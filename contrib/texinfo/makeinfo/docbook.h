begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* docbook.h -- docbook declarations.    $Id: docbook.h,v 1.2 2001/12/31 16:51:32 karl Exp $     Copyright (C) 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOCBOOK_H
end_ifndef

begin_define
define|#
directive|define
name|DOCBOOK_H
end_define

begin_define
define|#
directive|define
name|DB_B
value|"emphasis role=\"bold\""
end_define

begin_define
define|#
directive|define
name|DB_CITE
value|"citetitle"
end_define

begin_define
define|#
directive|define
name|DB_CODE
value|"literal"
end_define

begin_define
define|#
directive|define
name|DB_COMMAND
value|"command"
end_define

begin_define
define|#
directive|define
name|DB_DFN
value|"firstterm"
end_define

begin_define
define|#
directive|define
name|DB_EMPH
value|"emphasis"
end_define

begin_define
define|#
directive|define
name|DB_ENV
value|"envar"
end_define

begin_define
define|#
directive|define
name|DB_FILE
value|"filename"
end_define

begin_define
define|#
directive|define
name|DB_FUNCTION
value|"function"
end_define

begin_define
define|#
directive|define
name|DB_I
value|"emphasis"
end_define

begin_define
define|#
directive|define
name|DB_KBD
value|"userinput"
end_define

begin_define
define|#
directive|define
name|DB_KEY
value|"keycap"
end_define

begin_define
define|#
directive|define
name|DB_OPTION
value|"option"
end_define

begin_define
define|#
directive|define
name|DB_STRONG
value|"emphasis role=\"bold\""
end_define

begin_define
define|#
directive|define
name|DB_TT
value|"literal"
end_define

begin_define
define|#
directive|define
name|DB_URL
value|"systemitem role=\"sitename\""
end_define

begin_define
define|#
directive|define
name|DB_VAR
value|"replaceable"
end_define

begin_decl_stmt
specifier|extern
name|int
name|docbook_version_inserted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|docbook_begin_book_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|docbook_first_chapter_found
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|docbook_must_insert_node_anchor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|docbook_no_new_paragraph
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|docbook_begin_section
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_begin_paragraph
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_begin_book
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_end_book
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_insert_tag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_xref1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_xref2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|docbook_quote
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|docbook_is_punctuation
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_punctuation
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_begin_itemize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_end_itemize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_begin_enumerate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_end_enumerate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_begin_table
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_end_table
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_add_item
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_add_table_item
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_close_table_item
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_add_anchor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_footnote
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_begin_index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_begin_example
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|docbook_end_example
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOCBOOK_H */
end_comment

end_unit

