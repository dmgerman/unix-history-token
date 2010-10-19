begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* search-list.h     Copyright 2000, 2001, 2004 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|search_list_h
end_ifndef

begin_define
define|#
directive|define
name|search_list_h
end_define

begin_comment
comment|/* Non-Posix systems use semi-colon as directory separator in lists,    since colon is part of drive letter spec.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|PATH_SEP_CHAR
value|';'
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PATH_SEP_CHAR
value|':'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|search_list_elem
block|{
name|struct
name|search_list_elem
modifier|*
name|next
decl_stmt|;
name|char
name|path
index|[
literal|1
index|]
decl_stmt|;
block|}
name|Search_List_Elem
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|search_list_elem
modifier|*
name|head
decl_stmt|;
name|struct
name|search_list_elem
modifier|*
name|tail
decl_stmt|;
block|}
name|Search_List
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|search_list_append
parameter_list|(
name|Search_List
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* search_list_h */
end_comment

end_unit

