begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2004,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey<dickey@clark.net> 1996,1997                   *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: nc_alloc.h,v 1.13 2005/01/16 00:27:35 tom Exp $ */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
if|#
directive|if
name|HAVE_LIBDMALLOC
include|#
directive|include
file|<dmalloc.h>
comment|/* Gray Watson's library */
else|#
directive|else
undef|#
directive|undef
name|HAVE_LIBDMALLOC
define|#
directive|define
name|HAVE_LIBDMALLOC
value|0
endif|#
directive|endif
if|#
directive|if
name|HAVE_LIBDBMALLOC
include|#
directive|include
file|<dbmalloc.h>
comment|/* Conor Cahill's library */
else|#
directive|else
undef|#
directive|undef
name|HAVE_LIBDBMALLOC
define|#
directive|define
name|HAVE_LIBDBMALLOC
value|0
endif|#
directive|endif
if|#
directive|if
name|HAVE_LIBMPATROL
include|#
directive|include
file|<mpatrol.h>
comment|/* Memory-Patrol library */
else|#
directive|else
undef|#
directive|undef
name|HAVE_LIBMPATROL
define|#
directive|define
name|HAVE_LIBMPATROL
value|0
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_LEAKS
define|#
directive|define
name|NO_LEAKS
value|0
endif|#
directive|endif
if|#
directive|if
name|HAVE_LIBDBMALLOC
operator|||
name|HAVE_LIBDMALLOC
operator|||
name|NO_LEAKS
define|#
directive|define
name|HAVE_NC_FREEALL
value|1
struct_decl|struct
name|termtype
struct_decl|;
extern|extern NCURSES_EXPORT(void
block|)
name|_nc_free_and_exit
argument_list|(
argument|int
argument_list|)
name|GCC_NORETURN
expr_stmt|;
end_extern

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_free_tparm
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_leaks_dump_entry
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

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
value|exit(code)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* doalloc.c */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(void *
end_extern

begin_expr_stmt
unit|)
name|_nc_doalloc
argument_list|(
name|void
operator|*
argument_list|,
name|size_t
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_extern
extern|extern NCURSES_EXPORT(char *
end_extern

begin_expr_stmt
unit|)
name|_nc_strdup
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NC_ALLOC_included */
end_comment

end_unit

