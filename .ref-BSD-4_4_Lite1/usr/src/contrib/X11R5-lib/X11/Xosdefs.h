begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * O/S-dependent (mis)feature macro definitions  *  * $XConsortium: Xosdefs.h,v 1.7 91/07/19 23:22:19 rws Exp $  *  * Copyright 1991 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XOSDEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_XOSDEFS_H_
end_define

begin_comment
comment|/*  * X_NOT_STDC_ENV means does not have ANSI C header files.  Lack of this  * symbol does NOT mean that the system has stdarg.h.  *  * X_NOT_POSIX means does not have POSIX header files.  Lack of this  * symbol does NOT mean that the POSIX environment is the default.  * You may still have to define _POSIX_SOURCE to get it.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOSTDHDRS
end_ifdef

begin_define
define|#
directive|define
name|X_NOT_POSIX
end_define

begin_define
define|#
directive|define
name|X_NOT_STDC_ENV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sony
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SYSTYPE_SYSV
end_ifndef

begin_define
define|#
directive|define
name|X_NOT_POSIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UTEK
end_ifdef

begin_define
define|#
directive|define
name|X_NOT_POSIX
end_define

begin_define
define|#
directive|define
name|X_NOT_STDC_ENV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_define
define|#
directive|define
name|X_NOT_POSIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ultrix
end_ifndef

begin_comment
comment|/* assume vanilla BSD */
end_comment

begin_define
define|#
directive|define
name|X_NOT_POSIX
end_define

begin_define
define|#
directive|define
name|X_NOT_STDC_ENV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|luna
end_ifdef

begin_define
define|#
directive|define
name|X_NOT_POSIX
end_define

begin_define
define|#
directive|define
name|X_NOT_STDC_ENV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|Mips
end_ifdef

begin_define
define|#
directive|define
name|X_NOT_POSIX
end_define

begin_define
define|#
directive|define
name|X_NOT_STDC_ENV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_comment
comment|/* (release 3.2) */
end_comment

begin_define
define|#
directive|define
name|X_NOT_POSIX
end_define

begin_define
define|#
directive|define
name|X_NOT_STDC_ENV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV386
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_define
define|#
directive|define
name|X_NOT_POSIX
end_define

begin_define
define|#
directive|define
name|X_NOT_STDC_ENV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MOTOROLA
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_define
define|#
directive|define
name|X_NOT_STDC_ENV
end_define

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
comment|/* _XOSDEFS_H_ */
end_comment

end_unit

