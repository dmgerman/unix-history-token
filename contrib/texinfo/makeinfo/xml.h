begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xml.h -- xml output declarations.    $Id: xml.h,v 1.3 2001/05/01 16:29:29 karl Exp $     Copyright (C) 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Philippe Martin<feloy@free.fr>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XML_H
end_ifndef

begin_define
define|#
directive|define
name|XML_H
end_define

begin_comment
comment|/* Options. */
end_comment

begin_comment
comment|/* Separate index entries into divisions for each letters. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xml_index_divisions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xml_sort_index
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xml_node_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xml_no_para
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xml_node_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xml_last_section_output_position
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|xml_element
block|{
name|TEXINFO
init|=
literal|0
block|,
name|SETFILENAME
block|,
name|TITLEFONT
block|,
name|SETTITLE
block|,
comment|/* Node */
name|NODE
comment|/* 4 */
block|,
name|NODENEXT
block|,
name|NODEPREV
block|,
name|NODEUP
block|,
comment|/* Structuring */
name|CHAPTER
comment|/* 8 */
block|,
name|SECTION
block|,
name|SUBSECTION
block|,
name|SUBSUBSECTION
block|,
name|TOP
comment|/* 12 */
block|,
name|UNNUMBERED
block|,
name|UNNUMBEREDSEC
block|,
name|UNNUMBEREDSUBSEC
block|,
name|UNNUMBEREDSUBSUBSEC
block|,
name|APPENDIX
comment|/* 17 */
block|,
name|APPENDIXSEC
block|,
name|APPENDIXSUBSEC
block|,
name|APPENDIXSUBSUBSEC
block|,
name|MAJORHEADING
comment|/* 21 */
block|,
name|CHAPHEADING
block|,
name|HEADING
block|,
name|SUBHEADING
block|,
name|SUBSUBHEADING
block|,
comment|/* Menu */
name|MENU
comment|/* 26 */
block|,
name|MENUENTRY
block|,
name|MENUTITLE
block|,
name|MENUCOMMENT
block|,
name|MENUNODE
block|,
name|NODENAME
block|,
comment|/* -- */
name|ACRONYM
comment|/* 32 */
block|,
name|TT
block|,
name|CODE
block|,
name|KBD
block|,
name|URL
block|,
name|KEY
block|,
name|VAR
block|,
name|SC
block|,
name|DFN
block|,
name|EMPH
block|,
name|STRONG
block|,
name|CITE
block|,
name|NOTFIXEDWIDTH
block|,
name|I
block|,
name|B
block|,
name|R
block|,
name|TITLE
block|,
name|IFINFO
block|,
name|SP
block|,
name|CENTER
block|,
name|DIRCATEGORY
block|,
name|QUOTATION
block|,
name|EXAMPLE
block|,
name|SMALLEXAMPLE
block|,
name|LISP
block|,
name|SMALLLISP
block|,
name|CARTOUCHE
block|,
name|FORMAT
block|,
name|SMALLFORMAT
block|,
name|DISPLAY
block|,
name|SMALLDISPLAY
block|,
name|FOOTNOTE
block|,
name|ITEMIZE
block|,
name|ITEMFUNCTION
block|,
name|ITEM
block|,
name|ENUMERATE
block|,
name|TABLE
block|,
name|TABLEITEM
block|,
name|TABLETERM
block|,
name|INDEXTERM
block|,
name|XREF
block|,
name|XREFNODENAME
block|,
name|XREFINFONAME
block|,
name|XREFPRINTEDDESC
block|,
name|XREFINFOFILE
block|,
name|XREFPRINTEDNAME
block|,
name|INFOREF
block|,
name|INFOREFNODENAME
block|,
name|INFOREFREFNAME
block|,
name|INFOREFINFONAME
block|,
name|UREF
block|,
name|UREFURL
block|,
name|UREFDESC
block|,
name|UREFREPLACEMENT
block|,
name|EMAIL
block|,
name|EMAILADDRESS
block|,
name|EMAILNAME
block|,
name|GROUP
block|,
name|PRINTINDEX
block|,
name|ANCHOR
block|,
name|IMAGE
block|,
name|PRIMARY
block|,
name|SECONDARY
block|,
name|INFORMALFIGURE
block|,
name|MEDIAOBJECT
block|,
name|IMAGEOBJECT
block|,
name|IMAGEDATA
block|,
name|TEXTOBJECT
block|,
name|INDEXENTRY
block|,
name|PRIMARYIE
block|,
name|SECONDARYIE
block|,
name|INDEXDIV
block|,
name|MULTITABLE
block|,
name|TGROUP
block|,
name|COLSPEC
block|,
name|TBODY
block|,
name|ENTRY
block|,
name|ROW
block|,
name|BOOKINFO
block|,
name|ABSTRACT
block|,
name|REPLACEABLE
block|,
name|PARA
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|void
name|xml_insert_element
parameter_list|(
comment|/* int name, int arg */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|xml_id
parameter_list|(
comment|/* char *id */
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XML_H */
end_comment

end_unit

