begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Take file names apart into directory and base names.      Copyright (C) 1998, 2001, 2003-2006 Free Software Foundation, Inc.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 2, or (at your option)     any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; if not, write to the Free Software Foundation,     Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|<stdbool.h>
end_include

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
name|FILE_SYSTEM_PREFIX_LEN
end_ifndef

begin_if
if|#
directive|if
name|FILE_SYSTEM_ACCEPTS_DRIVE_LETTER_PREFIX
end_if

begin_comment
comment|/* This internal macro assumes ASCII, but all hosts that support drive        letters use ASCII.  */
end_comment

begin_define
define|#
directive|define
name|_IS_DRIVE_LETTER
parameter_list|(
name|c
parameter_list|)
value|(((unsigned int) (c) | ('a' - 'A')) - 'a' \<= 'z' - 'a')
end_define

begin_define
define|#
directive|define
name|FILE_SYSTEM_PREFIX_LEN
parameter_list|(
name|Filename
parameter_list|)
define|\
value|(_IS_DRIVE_LETTER ((Filename)[0])&& (Filename)[1] == ':' ? 2 : 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FILE_SYSTEM_PREFIX_LEN
parameter_list|(
name|Filename
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE
end_ifndef

begin_define
define|#
directive|define
name|FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DOUBLE_SLASH_IS_DISTINCT_ROOT
end_ifndef

begin_define
define|#
directive|define
name|DOUBLE_SLASH_IS_DISTINCT_ROOT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE
end_if

begin_define
define|#
directive|define
name|IS_ABSOLUTE_FILE_NAME
parameter_list|(
name|F
parameter_list|)
value|ISSLASH ((F)[FILE_SYSTEM_PREFIX_LEN (F)])
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_ABSOLUTE_FILE_NAME
parameter_list|(
name|F
parameter_list|)
define|\
value|(ISSLASH ((F)[0]) || 0< FILE_SYSTEM_PREFIX_LEN (F))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IS_RELATIVE_FILE_NAME
parameter_list|(
name|F
parameter_list|)
value|(! IS_ABSOLUTE_FILE_NAME (F))
end_define

begin_function_decl
name|char
modifier|*
name|base_name
parameter_list|(
name|char
specifier|const
modifier|*
name|file
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
name|file
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
name|file
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
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|last_component
parameter_list|(
name|char
specifier|const
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|strip_trailing_slashes
parameter_list|(
name|char
modifier|*
name|file
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

