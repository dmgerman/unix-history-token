begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: mf_common.h,v 0.22 2005/11/26 15:26:52 tom Exp $ */
end_comment

begin_comment
comment|/* Common internal header for menu and form library */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MF_COMMON_H_incl
end_ifndef

begin_define
define|#
directive|define
name|MF_COMMON_H_incl
value|1
end_define

begin_include
include|#
directive|include
file|<ncurses_cfg.h>
end_include

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|DECL_ERRNO
end_if

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* in case of debug version we ignore the suppression of assertions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_undef
undef|#
directive|undef
name|NDEBUG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<nc_alloc.h>
end_include

begin_if
if|#
directive|if
name|USE_RCS_IDS
end_if

begin_define
define|#
directive|define
name|MODULE_ID
parameter_list|(
name|id
parameter_list|)
value|static const char Ident[] = id;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MODULE_ID
parameter_list|(
name|id
parameter_list|)
end_define

begin_comment
comment|/*nothing*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Maximum regular 8-bit character code */
end_comment

begin_define
define|#
directive|define
name|MAX_REGULAR_CHARACTER
value|(0xff)
end_define

begin_define
define|#
directive|define
name|SET_ERROR
parameter_list|(
name|code
parameter_list|)
value|(errno=(code))
end_define

begin_define
define|#
directive|define
name|GET_ERROR
parameter_list|()
value|(errno)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_define
define|#
directive|define
name|RETURN
parameter_list|(
name|code
parameter_list|)
value|returnCode( SET_ERROR(code) )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RETURN
parameter_list|(
name|code
parameter_list|)
value|return( SET_ERROR(code) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The few common values in the status fields for menus and forms */
end_comment

begin_define
define|#
directive|define
name|_POSTED
value|(0x01U)
end_define

begin_comment
comment|/* menu or form is posted                  */
end_comment

begin_define
define|#
directive|define
name|_IN_DRIVER
value|(0x02U)
end_define

begin_comment
comment|/* menu or form is processing hook routine */
end_comment

begin_comment
comment|/* Call object hook */
end_comment

begin_define
define|#
directive|define
name|Call_Hook
parameter_list|(
name|object
parameter_list|,
name|handler
parameter_list|)
define|\
value|if ( (object) != 0&& ((object)->handler) != (void *) 0 )\    {\ 	(object)->status |= _IN_DRIVER;\ 	(object)->handler(object);\ 	(object)->status&= ~_IN_DRIVER;\    }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MF_COMMON_H_incl */
end_comment

end_unit

