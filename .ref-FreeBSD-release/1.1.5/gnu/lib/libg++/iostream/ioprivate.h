begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//    This is part of the iostream library, providing -*- C++ -*- input/output.
end_comment

begin_comment
comment|//    Copyright (C) 1991 Per Bothner.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    This library is free software; you can redistribute it and/or
end_comment

begin_comment
comment|//    modify it under the terms of the GNU Library General Public
end_comment

begin_comment
comment|//    License as published by the Free Software Foundation; either
end_comment

begin_comment
comment|//    version 2 of the License, or (at your option) any later version.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|//    but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
end_comment

begin_comment
comment|//    Library General Public License for more details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    You should have received a copy of the GNU Library General Public
end_comment

begin_comment
comment|//    License along with this library; if not, write to the Free
end_comment

begin_comment
comment|//    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"streambuf.h"
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|_fstat
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|fstat(x,y)
end_define

begin_define
define|#
directive|define
name|_isatty
parameter_list|(
name|fd
parameter_list|)
value|isatty(fd)
end_define

begin_function_decl
specifier|extern
name|int
name|__cvt_double
parameter_list|(
name|double
name|number
parameter_list|,
specifier|register
name|int
name|prec
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
modifier|*
name|signp
parameter_list|,
name|int
name|fmtch
parameter_list|,
name|char
modifier|*
name|startp
parameter_list|,
name|char
modifier|*
name|endp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*#define USE_MALLOC_BUF*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_MALLOC_BUF
end_ifndef

begin_define
define|#
directive|define
name|ALLOC_BUF
parameter_list|(
name|size
parameter_list|)
value|new char[size]
end_define

begin_define
define|#
directive|define
name|FREE_BUF
parameter_list|(
name|ptr
parameter_list|)
value|delete [] (ptr)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ALLOC_BUF
parameter_list|(
name|size
parameter_list|)
value|(char*)malloc(size)
end_define

begin_define
define|#
directive|define
name|FREE_BUF
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USE_DTOA
end_define

begin_comment
comment|// Advantages:
end_comment

begin_comment
comment|// - Input gets closest value
end_comment

begin_comment
comment|// - Output emits string that when read yields identical value.
end_comment

begin_comment
comment|// - Handles Infinity and NaNs (but not re-readable).
end_comment

begin_comment
comment|// Disadvantages of dtoa:
end_comment

begin_comment
comment|// - May not work for all double formats.
end_comment

begin_comment
comment|// - Big chunck of code.
end_comment

begin_comment
comment|// - Not reentrant - uses atatic variables freelist,
end_comment

begin_comment
comment|//   result, result_k in dtoa
end_comment

begin_comment
comment|//   (plus initializes p5s, HOWORD, and LOWORD).
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_DTOA
end_ifdef

begin_extern
extern|extern
literal|"C"
name|double
name|_Xstrtod
parameter_list|(
specifier|const
name|char
modifier|*
name|s00
parameter_list|,
name|char
modifier|*
modifier|*
name|se
parameter_list|)
function_decl|;
end_extern

begin_define
define|#
directive|define
name|strtod
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
value|_Xstrtod(s, e)
end_define

begin_extern
extern|extern
literal|"C"
name|char
modifier|*
name|dtoa
parameter_list|(
name|double
name|d
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|ndigits
parameter_list|,
name|int
modifier|*
name|decpt
parameter_list|,
name|int
modifier|*
name|sign
parameter_list|,
name|char
modifier|*
modifier|*
name|rve
parameter_list|)
function_decl|;
end_extern

begin_function_decl
specifier|extern
name|int
name|__outfloat
parameter_list|(
name|double
name|value
parameter_list|,
name|streambuf
modifier|*
name|sb
parameter_list|,
name|char
name|mode
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|precision
parameter_list|,
name|__fmtflags
name|flags
parameter_list|,
name|char
name|sign_mode
parameter_list|,
name|char
name|fill
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

