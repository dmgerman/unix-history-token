begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* toc.h -- table of contents handling.    $Id: toc.h,v 1.5 2002/02/09 00:54:51 karl Exp $     Copyright (C) 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Karl Heinz Marbaise<kama@hippo.fido.de>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TOC_H
end_ifndef

begin_define
define|#
directive|define
name|TOC_H
end_define

begin_comment
comment|/* the file where we found the @contents directive */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|contents_filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the file where we found the @shortcontents directive */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|shortcontents_filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Structure to hold one entry for the toc. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|toc_entry_elt
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|containing_node
decl_stmt|;
comment|/* Name of node containing this section.  */
name|char
modifier|*
name|html_file
decl_stmt|;
comment|/* Name of HTML node-file in split-HTML mode */
name|int
name|number
decl_stmt|;
comment|/* counting number from 0...n independent from                             chapter/section can be used for anchors or                             references to it.  */
name|int
name|level
decl_stmt|;
comment|/* level: chapter, section, subsection... */
block|}
name|TOC_ENTRY_ELT
typedef|;
end_typedef

begin_comment
comment|/* all routines which have relationship with TOC should start with    toc_ (this is a kind of name-space) */
end_comment

begin_function_decl
specifier|extern
name|int
name|toc_add_entry
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return the number for the toc-entry */
end_comment

begin_function_decl
specifier|extern
name|void
name|toc_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|toc_find_section_of_node
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|cm_contents
argument_list|()
decl_stmt|,
name|cm_shortcontents
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not TOC_H */
end_comment

end_unit

