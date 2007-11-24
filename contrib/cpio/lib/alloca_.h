begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Memory allocation on the stack.     Copyright (C) 1995, 1999, 2001, 2002, 2003, 2004 Free Software    Foundation, Inc.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,    USA.  */
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
comment|/* alloca (N) returns a pointer to N bytes of memory    allocated on the stack, which will last until the function returns.    Use of alloca should be avoided:      - inside arguments of function calls - undefined behaviour,      - in inline functions - the allocation may actually last until the        calling function returns,      - for huge N (say, N>= 65536) - you never know how large (or small)        the stack is, and when the stack cannot fulfill the memory allocation        request, the program just crashes.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_elif
elif|#
directive|elif
name|defined
name|_AIX
end_elif

begin_define
define|#
directive|define
name|alloca
value|__alloca
end_define

begin_elif
elif|#
directive|elif
name|defined
name|_MSC_VER
end_elif

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

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
endif|#
directive|endif
name|void
modifier|*
name|alloca
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_extern

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

