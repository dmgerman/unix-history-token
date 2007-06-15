begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Memory allocation on the stack.    Copyright (C) 1995, 1999, 2001-2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,    USA.  */
end_comment

begin_comment
comment|/* When this file is included, it may be preceded only by preprocessor    declarations.  Thanks to AIX.  Therefore we include it right after    "config.h", not later.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALLOCA_H
end_ifndef

begin_define
define|#
directive|define
name|_ALLOCA_H
end_define

begin_comment
comment|/* alloca(N) returns a pointer (void* or char*) to N bytes of memory    allocated on the stack, and which will last until the function returns.    Use of alloca should be avoided:      - inside arguments of function calls - undefined behaviour,      - in inline functions - the allocation may actually last until the        calling function returns,      - for huge N (say, N>= 65536) - you never know how large (or small)        the stack is, and when the stack cannot fulfill the memory allocation        request, the program just crashes.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_define
define|#
directive|define
name|alloca
value|_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_ALLOCA_H
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_comment
comment|/* This section must match that of bison generated files. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
name|void
modifier|*
name|alloca
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_extern

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __cplusplus */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __cplusplus */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __hpux */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|alloca
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

begin_comment
comment|/* __hpux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALLOCA_H */
end_comment

end_unit

