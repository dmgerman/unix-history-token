begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* html.h -- declarations for html-related utilities.    $Id: html.h,v 1.6 2004/11/30 02:03:23 karl Exp $     Copyright (C) 1999, 2000, 2002, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HTML_H
end_ifndef

begin_define
define|#
directive|define
name|HTML_H
end_define

begin_comment
comment|/* A stack of font tags.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hstack
block|{
name|struct
name|hstack
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|tag
decl_stmt|;
name|char
modifier|*
name|attribs
decl_stmt|;
block|}
name|HSTACK
typedef|;
end_typedef

begin_comment
comment|/* Nonzero if we have output the<head>.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|html_output_head_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we have output a title, from @titlefont or @settitle.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|html_title_written
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Perform the<head> output.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|html_output_head
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Escape&<>.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|escape_string
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Open or close TAG according to START_OR_END.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|insert_html_tag
parameter_list|(
name|int
name|start_or_end
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output HTML<link> to NODE, plus extra ATTRIBUTES.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|add_link
parameter_list|(
name|char
modifier|*
name|nodename
parameter_list|,
name|char
modifier|*
name|attributes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Escape URL-special characters.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|add_escaped_anchor_name
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|old
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* See html.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|add_anchor_name
parameter_list|(
name|char
modifier|*
name|nodename
parameter_list|,
name|int
name|href
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_url_name
parameter_list|(
name|char
modifier|*
name|nodename
parameter_list|,
name|int
name|href
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_nodename_to_filename
parameter_list|(
name|char
modifier|*
name|nodename
parameter_list|,
name|int
name|href
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|nodename_to_filename
parameter_list|(
name|char
modifier|*
name|nodename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rollback_empty_tag
parameter_list|(
name|char
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VA_FPRINTF
argument_list|)
operator|&&
name|__STDC__
end_if

begin_function_decl
specifier|extern
name|void
name|insert_html_tag_with_attribute
parameter_list|(
name|int
name|start_or_end
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|,
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|insert_html_tag_with_attribute
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HTML_H */
end_comment

end_unit

