begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* footnote.h -- declarations for footnote.c.    $Id: footnote.h,v 1.2 1998/10/26 22:16:15 karl Exp $     Copyright (C) 1998 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FOOTNOTE_H
end_ifndef

begin_define
define|#
directive|define
name|FOOTNOTE_H
end_define

begin_decl_stmt
specifier|extern
name|int
name|footnote_style_preset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_footnote_number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|number_footnotes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|already_outputting_pending_notes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The Texinfo @commands.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cm_footnote
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cm_footnotestyle
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_footnote_style
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* called for -s option */
end_comment

begin_function_decl
specifier|extern
name|void
name|output_pending_notes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* called for output */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !FOOTNOTE_H */
end_comment

end_unit

