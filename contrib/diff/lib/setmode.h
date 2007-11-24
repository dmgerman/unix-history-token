begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Set a file descriptor's mode to binary or to text.     Copyright (C) 2001, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert<eggert@twinsun.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|set_binary_mode
end_ifndef

begin_function_decl
name|bool
name|set_binary_mode
parameter_list|(
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|HAVE_SETMODE_DOS
end_if

begin_define
define|#
directive|define
name|set_binary_mode
parameter_list|(
name|fd
parameter_list|,
name|mode
parameter_list|)
value|true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

