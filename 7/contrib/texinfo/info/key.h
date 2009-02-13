begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* key.h -- Structure associating function names with numeric codes. */
end_comment

begin_comment
comment|/* This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Andrew Bettison<andrewb@zip.com.au> */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KEY_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|KEY_H
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|char
name|code
decl_stmt|;
block|}
name|FUNCTION_KEY
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FUNCTION_KEY
name|function_key_array
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KEY_H */
end_comment

end_unit

