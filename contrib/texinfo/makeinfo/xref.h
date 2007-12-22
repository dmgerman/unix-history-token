begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xref.h -- declarations for the cross references.    $Id: xref.h,v 1.1 2004/04/11 17:56:47 karl Exp $     Copyright (C) 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XREF_H
end_ifndef

begin_define
define|#
directive|define
name|XREF_H
end_define

begin_enum
enum|enum
name|reftype
block|{
name|menu_reference
block|,
name|followed_reference
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_xref_token
parameter_list|(
name|int
name|expand
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not XREF_H */
end_comment

end_unit

