package org.coolreader.crengine;

import java.util.ArrayList;

import android.util.Log;

public class BookInfo {
	private FileInfo fileInfo;
	private Bookmark lastPosition;
	private ArrayList<Bookmark> bookmarks = new ArrayList<Bookmark>();

	synchronized public void setShortcutBookmark(int shortcut, Bookmark bookmark)
	{
		bookmark.setShortcut(shortcut);
		bookmark.setModified(true);
		for ( int i=0; i<bookmarks.size(); i++ ) {
			Bookmark bm = bookmarks.get(i);
			if ( bm.getType()==Bookmark.TYPE_POSITION && bm.getShortcut()==shortcut ) {
				bookmark.setId(bm.getId());
				bookmarks.set(i, bookmark);
				return;
			}
		}
		bookmarks.add(bookmark);
	}
	
	synchronized public Bookmark findShortcutBookmark( int shortcut )
	{
		for ( Bookmark bm : bookmarks )
			if ( bm.getType()==Bookmark.TYPE_POSITION && bm.getShortcut()==shortcut )
				return bm;
		return null;
	}
	
	public void updateAccess()
	{
		// TODO:
	}
	
	public BookInfo( FileInfo fileInfo )
	{
		this.fileInfo = fileInfo; //new FileInfo(fileInfo);
	}
	
	public Bookmark getLastPosition()
	{
		return lastPosition;
	}
	
	synchronized public void setLastPosition( Bookmark position )
	{
		if ( lastPosition!=null )
			position.setId(lastPosition.getId());
		lastPosition = position;
		lastPosition.setModified(true);
		fileInfo.lastAccessTime = lastPosition.getTimeStamp();
		fileInfo.setModified(true);
	}
	
	public FileInfo getFileInfo()
	{
		return fileInfo;
	}
	
	synchronized public void addBookmark( Bookmark bm )
	{
		bookmarks.add(bm);
	}

	synchronized public int getBookmarkCount()
	{
		return bookmarks.size();
	}

	synchronized public Bookmark getBookmark( int index )
	{
		return bookmarks.get(index);
	}

	synchronized public Bookmark removeBookmark( Bookmark bm )
	{
		if ( bm==null )
			return null;
		int index = -1;
		for ( int i=0; i<bookmarks.size(); i++ ) {
			if ( bm.getShortcut()>0 && bookmarks.get(0).getShortcut()==bm.getShortcut() ) {
				index = i;
				break;
			}
			if ( bm.getStartPos()!=null && bm.getStartPos().equals(bookmarks.get(i).getStartPos())) {
				index = i;
				break;
			}
		}
		if ( index<0 ) {
			Log.e("cr3", "cannot find bookmark " + bm);
			return null;
		}
		return bookmarks.remove(index);
	}
	
	synchronized public Bookmark removeBookmark( int index )
	{
		return bookmarks.remove(index);
	}
	
	synchronized void setBookmarks(ArrayList<Bookmark> list)
	{
		if ( list.size()>0 ) {
			if ( list.get(0).getType()==0 ) {
				lastPosition = list.remove(0); 
			}
		}
		if ( list.size()>0 ) {
			bookmarks = list;
		}
	}

	@Override
	public String toString() {
		return "BookInfo [fileInfo=" + fileInfo + ", lastPosition="
				+ lastPosition + "]";
	}

	
	
}
