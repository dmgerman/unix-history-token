begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey<dickey@clark.net> 1996,1997                   *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: nc_alloc.h,v 1.8 2000/04/08 23:42:57 tom Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NC_ALLOC_included
end_ifndef

begin_define
define|#
directive|define
name|NC_ALLOC_included
value|1
end_define

begin_if
if|#
directive|if
name|HAVE_LIBDMALLOC
end_if

begin_include
include|#
directive|include
file|<dmalloc.h>
end_include

begin_comment
comment|/* Gray Watson's library */
end_comment

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|HAVE_LIBDMALLOC
end_undef

begin_define
define|#
directive|define
name|HAVE_LIBDMALLOC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_LIBDBMALLOC
end_if

begin_include
include|#
directive|include
file|<dbmalloc.h>
end_include

begin_comment
comment|/* Conor Cahill's library */
end_comment

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|HAVE_LIBDBMALLOC
end_undef

begin_define
define|#
directive|define
name|HAVE_LIBDBMALLOC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_LEAKS
end_ifndef

begin_define
define|#
directive|define
name|NO_LEAKS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_LIBDBMALLOC
operator|||
name|HAVE_LIBDMALLOC
operator|||
name|NO_LEAKS
end_if

begin_define
define|#
directive|define
name|HAVE_NC_FREEALL
value|1
end_define

begin_struct_decl
struct_decl|struct
name|termtype
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|void
name|_nc_free_and_exit
argument_list|(
name|int
argument_list|)
name|GCC_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|_nc_free_tparm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_nc_leaks_dump_entry
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ExitProgram
parameter_list|(
name|code
parameter_list|)
value|_nc_free_and_exit(code)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_NC_FREEALL
end_ifndef

begin_define
define|#
directive|define
name|HAVE_NC_FREEALL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ExitProgram
end_ifndef

begin_define
define|#
directive|define
name|ExitProgram
parameter_list|(
name|code
parameter_list|)
value|return code
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* doalloc.c */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|_nc_doalloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|HAVE_STRDUP
end_if

begin_define
define|#
directive|define
name|strdup
value|_nc_strdup
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|_nc_strdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|typeMalloc
parameter_list|(
name|type
parameter_list|,
name|elts
parameter_list|)
value|(type *)malloc((elts)*sizeof(type))
end_define

begin_define
define|#
directive|define
name|typeCalloc
parameter_list|(
name|type
parameter_list|,
name|elts
parameter_list|)
value|(type *)calloc((elts),sizeof(type))
end_define

begin_define
define|#
directive|define
name|typeRealloc
parameter_list|(
name|type
parameter_list|,
name|elts
parameter_list|,
name|ptr
parameter_list|)
value|(type *)_nc_doalloc(ptr, (elts)*sizeof(type))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NC_ALLOC_included */
end_comment

end_unit

