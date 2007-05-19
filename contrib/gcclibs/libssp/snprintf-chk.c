begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Checking snprintf.    Copyright (C) 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  In addition to the permissions in the GNU General Public License, the Free Software Foundation gives you unlimited permission to link the compiled version of this file into combinations with other programs, and to distribute those combinations without any restriction coming from the use of this file.  (The General Public License restrictions do apply in other respects; for example, they cover modification of the file, and distribution when not linked into a combine executable.)  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled with    GCC to produce an executable, this does not cause the resulting executable    to be covered by the GNU General Public License. This exception does not    however invalidate any other reasons why the executable file might be    covered by the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<ssp/ssp.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDIO_H
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|__chk_fail
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_USABLE_VSNPRINTF
end_ifdef

begin_decl_stmt
name|int
name|__snprintf_chk
argument_list|(
name|char
operator|*
name|s
argument_list|,
name|size_t
name|n
argument_list|,
name|int
name|flags
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|,
name|size_t
name|slen
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
block|{
name|va_list
name|arg
decl_stmt|;
name|int
name|done
decl_stmt|;
if|if
condition|(
name|n
operator|>
name|slen
condition|)
name|__chk_fail
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|arg
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|done
operator|=
name|vsnprintf
argument_list|(
name|s
argument_list|,
name|n
argument_list|,
name|format
argument_list|,
name|arg
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|arg
argument_list|)
expr_stmt|;
return|return
name|done
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

