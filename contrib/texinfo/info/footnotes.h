begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* footnotes.h -- Some functions for manipulating footnotes.    $Id: footnotes.h,v 1.4 1998/11/29 21:44:49 karl Exp $     Copyright (C) 1993, 97, 98 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_FOOTNOTES_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_FOOTNOTES_H
end_define

begin_comment
comment|/* Magic string which indicates following text is footnotes. */
end_comment

begin_define
define|#
directive|define
name|FOOTNOTE_LABEL
value|N_("---------- Footnotes ----------")
end_define

begin_define
define|#
directive|define
name|FN_FOUND
value|0
end_define

begin_define
define|#
directive|define
name|FN_UNFOUND
value|1
end_define

begin_define
define|#
directive|define
name|FN_UNABLE
value|2
end_define

begin_comment
comment|/* Create or delete the footnotes window depending on whether footnotes    exist in WINDOW's node or not.  Returns FN_FOUND if footnotes were found    and displayed.  Returns FN_UNFOUND if there were no footnotes found    in WINDOW's node.  Returns FN_UNABLE if there were footnotes, but the    window to show them couldn't be made. */
end_comment

begin_function_decl
specifier|extern
name|int
name|info_get_or_remove_footnotes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Non-zero means attempt to show footnotes when displaying a new window. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|auto_footnotes_p
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INFO_FOOTNOTES_H */
end_comment

end_unit

