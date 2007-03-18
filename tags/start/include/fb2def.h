/** \file fb2def.h
    \brief FictionBook2 format defitions

    When included w/o XS_IMPLEMENT_SCHEME defined,
    declares enums for element, attribute and namespace names.

    When included with XS_IMPLEMENT_SCHEME defined,
    defines fb2_elem_table, fb2_attr_table and fb2_ns_table tables
    which can be passed to document to define schema.
    Please include it with XS_IMPLEMENT_SCHEME only into once in project.

    CoolReader Engine

    (c) Vadim Lopatin, 2000-2006
    This source code is distributed under the terms of
    GNU General Public License.

    See LICENSE file for details.

*/

#if !defined(__FB2_DEF_H_INCLUDED__) || defined(XS_IMPLEMENT_SCHEME)
#define __FB2_DEF_H_INCLUDED__

#include "dtddef.h"

//=====================================================
// el_ definitions
//=====================================================
XS_BEGIN_TAGS

XS_TAG2( xml, "?xml" )
XS_TAG2( xml_stylesheet, "?xml-stylesheet" )
XS_TAG1( FictionBook )
XS_TAG1D( genre, true, css_d_none, css_ws_normal )
XS_TAG1( annotation )
XS_TAG1T( id )
XS_TAG1T( version )
XS_TAG1( output )
XS_TAG1( part )
XS_TAG1( body )
XS_TAG1T( p )
XS_TAG1( coverpage )
XS_TAG1OBJ( image )
XS_TAG1T( lang )
XS_TAG1( title )
XS_TAG1( section )
XS_TAG1D( binary, true, css_d_none, css_ws_normal )
XS_TAG2T( text_author, "text-author" )

// type="styleType"
XS_TAG1I( strikethrough )
XS_TAG1I( sub )
XS_TAG1I( sup )
XS_TAG1I( style )
XS_TAG1I( strong )
XS_TAG1I( emphasis )
XS_TAG1I( code )
XS_TAG1I( a )

// table
XS_TAG1( table )
XS_TAG1( tr )
XS_TAG1T( th )
XS_TAG1T( td )

XS_TAG1( cite )
XS_TAG1T( v )
XS_TAG1( stanza )
XS_TAG1( epigraph )
XS_TAG1T( subtitle )
XS_TAG1( poem )
XS_TAG2( empty_line, "empty-line" )

XS_TAG1T( history )
XS_TAG1( author )
XS_TAG1T( date )
XS_TAG1T( year )
XS_TAG1T( sequence )

XS_TAG1D( stylesheet, false, css_d_none, css_ws_normal )
XS_TAG1D( description, false, css_d_none, css_ws_normal )
XS_TAG2( title_info, "title-info" )
XS_TAG2( src_title_info, "src-title-info" )
XS_TAG2( document_info, "document-info" )
XS_TAG2( publish_info, "publish-info" )
XS_TAG2( custom_info, "custom-info" )

// type="xs:string"
XS_TAG2T( home_page, "home-page" )
XS_TAG2T( src_url, "src-url" )
XS_TAG1T( email )

// type="textFieldType"
XS_TAG2T( book_title, "book-title" )
XS_TAG2T( program_used, "program-used" )
XS_TAG2I( first_name, "first-name" )
XS_TAG2I( middle_name, "middle-name" )
XS_TAG2I( last_name, "last-name" )
XS_TAG2T( src_ocr, "src-ocr" )
XS_TAG2T( book_name, "book-name" )
XS_TAG1T( publisher )
XS_TAG1T( city )
XS_TAG1T( isbn )
XS_TAG1T( nickname )
XS_TAG1T( keywords )


XS_END_TAGS


//=====================================================
// attr_ definitions
//=====================================================
XS_BEGIN_ATTRS

XS_ATTR( id )
XS_ATTR( value )
XS_ATTR( name )
XS_ATTR( number )
XS_ATTR( href )
XS_ATTR( type )
XS_ATTR( mode )
XS_ATTR( price )
XS_ATTR( currency )
XS_ATTR( version )
XS_ATTR( encoding )
XS_ATTR( l )
XS_ATTR( xmlns )
XS_ATTR( genre )
XS_ATTR( xlink )
XS_ATTR( xsi )
XS_ATTR( schemaLocation )
XS_ATTR( include )
XS_ATTR2( include_all, "include-all" )
XS_ATTR2( content_type, "content-type" )

XS_END_ATTRS


//=====================================================
// ns_ definitions
//=====================================================
XS_BEGIN_NS

XS_NS( l )
XS_NS( xsi )
XS_NS( xmlns )
XS_NS( xlink )
XS_NS( xs )

XS_END_NS


#endif // __FB2_DEF_H_INCLUDED__
