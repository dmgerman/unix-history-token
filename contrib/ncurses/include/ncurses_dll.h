begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2004,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: ncurses_dll.h,v 1.5 2006/04/22 22:07:51 tom Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NCURSES_DLL_H_incl
end_ifndef

begin_define
define|#
directive|define
name|NCURSES_DLL_H_incl
value|1
end_define

begin_comment
comment|/* no longer needed on cygwin or mingw, thanks to auto-import       */
end_comment

begin_comment
comment|/* but this structure may be useful at some point for an MSVC build */
end_comment

begin_comment
comment|/* so, for now unconditionally define the important flags           */
end_comment

begin_comment
comment|/* "the right way" for proper static and dll+auto-import behavior   */
end_comment

begin_undef
undef|#
directive|undef
name|NCURSES_DLL
end_undef

begin_define
define|#
directive|define
name|NCURSES_STATIC
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NCURSES_DLL
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NCURSES_STATIC
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|NCURSES_STATIC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|NCURSES_IMPEXP
end_undef

begin_undef
undef|#
directive|undef
name|NCURSES_API
end_undef

begin_undef
undef|#
directive|undef
name|NCURSES_EXPORT
end_undef

begin_undef
undef|#
directive|undef
name|NCURSES_EXPORT_VAR
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NCURSES_DLL
argument_list|)
end_if

begin_comment
comment|/* building a DLL */
end_comment

begin_define
define|#
directive|define
name|NCURSES_IMPEXP
value|__declspec(dllexport)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|NCURSES_STATIC
argument_list|)
end_elif

begin_comment
comment|/* building or linking to a static library */
end_comment

begin_define
define|#
directive|define
name|NCURSES_IMPEXP
end_define

begin_comment
comment|/* nothing */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* linking to the DLL */
end_comment

begin_define
define|#
directive|define
name|NCURSES_IMPEXP
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NCURSES_API
value|__cdecl
end_define

begin_define
define|#
directive|define
name|NCURSES_EXPORT
parameter_list|(
name|type
parameter_list|)
value|NCURSES_IMPEXP type NCURSES_API
end_define

begin_define
define|#
directive|define
name|NCURSES_EXPORT_VAR
parameter_list|(
name|type
parameter_list|)
value|NCURSES_IMPEXP type
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Take care of non-cygwin platforms */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NCURSES_IMPEXP
argument_list|)
end_if

begin_define
define|#
directive|define
name|NCURSES_IMPEXP
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NCURSES_API
argument_list|)
end_if

begin_define
define|#
directive|define
name|NCURSES_API
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NCURSES_EXPORT
argument_list|)
end_if

begin_define
define|#
directive|define
name|NCURSES_EXPORT
parameter_list|(
name|type
parameter_list|)
value|NCURSES_IMPEXP type NCURSES_API
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NCURSES_EXPORT_VAR
argument_list|)
end_if

begin_define
define|#
directive|define
name|NCURSES_EXPORT_VAR
parameter_list|(
name|type
parameter_list|)
value|NCURSES_IMPEXP type
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCURSES_DLL_H_incl */
end_comment

end_unit

