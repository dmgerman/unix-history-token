begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ioctl.h	8.6 (Berkeley) 3/28/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IOCTL_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
name|__GNUC__
end_if

begin_warning
warning|#
directive|warning
literal|"Don't #include ioctl.h in the kernel.  Include xxxio.h instead."
end_warning

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
file|<sys/ttycom.h>
end_include

begin_comment
comment|/*  * Pun for SunOS prior to 3.2.  SunOS 3.2 and later support TIOCGWINSZ  * and TIOCSWINSZ (yes, even 3.2-3.5, the fact that it wasn't documented  * notwithstanding).  */
end_comment

begin_struct
struct|struct
name|ttysize
block|{
name|unsigned
name|short
name|ts_lines
decl_stmt|;
name|unsigned
name|short
name|ts_cols
decl_stmt|;
name|unsigned
name|short
name|ts_xxx
decl_stmt|;
name|unsigned
name|short
name|ts_yyy
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TIOCGSIZE
value|TIOCGWINSZ
end_define

begin_define
define|#
directive|define
name|TIOCSSIZE
value|TIOCSWINSZ
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_IOCTL_H_ */
end_comment

begin_comment
comment|/*  * Keep outside _SYS_IOCTL_H_  * Compatibility with old terminal driver  *  * Source level -> #define USE_OLD_TTY  * Kernel level -> options COMPAT_43 or COMPAT_SUNOS  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_OLD_TTY
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_SUNOS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioctl_compat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

