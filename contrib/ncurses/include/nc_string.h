begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2012,2013 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey                        2012                    *  ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STRING_HACKS_H
end_ifndef

begin_define
define|#
directive|define
name|STRING_HACKS_H
value|1
end_define

begin_include
include|#
directive|include
file|<ncurses_cfg.h>
end_include

begin_comment
comment|/*  * $Id: nc_string.h,v 1.4 2013/12/15 01:09:19 tom Exp $  *  * String-hacks.  Use these macros to stifle warnings on (presumably) correct  * uses of strcat, strcpy and sprintf.  *  * By the way -  * A fundamental limitation of the interfaces (and frequent issue in bug  * reports using these functions) is that sizes are passed as unsigned values  * (with associated sign-extension problems), limiting their effectiveness  * when checking for buffer overflow.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|NCURSES_VOID
end_define

begin_comment
comment|/* nothing */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCURSES_VOID
value|(void)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|USE_STRING_HACKS
operator|&&
name|HAVE_STRLCAT
end_if

begin_define
define|#
directive|define
name|_nc_STRCAT
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|NCURSES_VOID strlcat((d),(s),NCURSES_CAST(size_t,n))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_nc_STRCAT
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|NCURSES_VOID strcat((d),(s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|USE_STRING_HACKS
operator|&&
name|HAVE_STRLCPY
end_if

begin_define
define|#
directive|define
name|_nc_STRCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|NCURSES_VOID strlcpy((d),(s),NCURSES_CAST(size_t,n))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_nc_STRCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|NCURSES_VOID strcpy((d),(s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|USE_STRING_HACKS
operator|&&
name|HAVE_SNPRINTF
end_if

begin_define
define|#
directive|define
name|_nc_SPRINTF
value|NCURSES_VOID snprintf
end_define

begin_define
define|#
directive|define
name|_nc_SLIMIT
parameter_list|(
name|n
parameter_list|)
value|NCURSES_CAST(size_t,n),
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_nc_SPRINTF
value|NCURSES_VOID sprintf
end_define

begin_define
define|#
directive|define
name|_nc_SLIMIT
parameter_list|(
name|n
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STRING_HACKS_H */
end_comment

end_unit

