begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Take file names apart into directory and base names.      Copyright (C) 1998, 2001, 2003 Free Software Foundation, Inc.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 2, or (at your option)     any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; if not, write to the Free Software Foundation,     Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIRNAME_H_
end_ifndef

begin_define
define|#
directive|define
name|DIRNAME_H_
value|1
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|DIRECTORY_SEPARATOR
end_ifndef

begin_define
define|#
directive|define
name|DIRECTORY_SEPARATOR
value|'/'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISSLASH
end_ifndef

begin_define
define|#
directive|define
name|ISSLASH
parameter_list|(
name|C
parameter_list|)
value|((C) == DIRECTORY_SEPARATOR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FILESYSTEM_PREFIX_LEN
end_ifndef

begin_define
define|#
directive|define
name|FILESYSTEM_PREFIX_LEN
parameter_list|(
name|Filename
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|base_name
parameter_list|(
name|char
specifier|const
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|dir_name
parameter_list|(
name|char
specifier|const
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|base_len
parameter_list|(
name|char
specifier|const
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|dir_len
parameter_list|(
name|char
specifier|const
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strip_trailing_slashes
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DIRNAME_H_ */
end_comment

end_unit

