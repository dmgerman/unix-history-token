begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portable<string.h>    Copyright 1995 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDB_STRING_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|GDB_STRING_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strtok
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MEMORY_H
end_ifdef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
modifier|*
name|memset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|memcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|memmove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|memcmp
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

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(GDB_STRING_H) */
end_comment

end_unit

