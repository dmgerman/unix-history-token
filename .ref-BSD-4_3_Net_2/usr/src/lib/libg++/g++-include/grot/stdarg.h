begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_stdarg_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_stdarg_h
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|mips
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUG__
end_ifndef

begin_extern
extern|extern
literal|"C"
name|__builtin_saveregs
argument_list|()
expr_stmt|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_comment
comment|/* Amount of space required in an argument list for an arg of type TYPE.    TYPE may alternatively be an expression whose type is used.  */
end_comment

begin_define
define|#
directive|define
name|__va_rounded_size
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(((sizeof (TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
end_if

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|,
name|LASTARG
parameter_list|)
define|\
value|(__builtin_saveregs (), AP = ((char *)&(LASTARG) + __va_rounded_size (LASTARG)))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|mips
argument_list|)
end_elif

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|,
name|LASTARG
parameter_list|)
value|{\        static char __vd_alist[16] = "__%%VARARGS";
comment|/* Identify to codegen */
value|\ 	__builtin_saveregs();\ 	(AP = ((char *)&(LASTARG) + __va_rounded_size (LASTARG)));}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|,
name|LASTARG
parameter_list|)
define|\
value|(AP = ((char *)&(LASTARG) + __va_rounded_size (LASTARG)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|va_end
parameter_list|(
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in gnulib */
end_comment

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|AP
parameter_list|)
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(AP += __va_rounded_size (TYPE),					\   *((TYPE *) (AP - __va_rounded_size (TYPE))))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

