begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ttydefaults.h	8.4 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * System wide defaults for terminal state.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TTYDEFAULTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TTYDEFAULTS_H_
end_define

begin_comment
comment|/*  * Defaults on "first" open.  */
end_comment

begin_define
define|#
directive|define
name|TTYDEF_IFLAG
value|(BRKINT	| ICRNL	| IMAXBEL | IXON | IXANY)
end_define

begin_define
define|#
directive|define
name|TTYDEF_OFLAG
value|(OPOST | ONLCR)
end_define

begin_define
define|#
directive|define
name|TTYDEF_LFLAG_NOECHO
value|(ICANON | ISIG | IEXTEN)
end_define

begin_define
define|#
directive|define
name|TTYDEF_LFLAG_ECHO
value|(TTYDEF_LFLAG_NOECHO \ 	| ECHO | ECHOE | ECHOKE | ECHOCTL)
end_define

begin_define
define|#
directive|define
name|TTYDEF_LFLAG
value|TTYDEF_LFLAG_ECHO
end_define

begin_define
define|#
directive|define
name|TTYDEF_CFLAG
value|(CREAD | CS8 | HUPCL)
end_define

begin_define
define|#
directive|define
name|TTYDEF_SPEED
value|(B9600)
end_define

begin_comment
comment|/*  * Control Character Defaults  */
end_comment

begin_comment
comment|/*  * XXX: A lot of code uses lowercase characters, but control-character  * conversion is actually only valid when applied to uppercase  * characters. We just treat lowercase characters as if they were  * inserted as uppercase.  */
end_comment

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|x
parameter_list|)
value|((x)>= 'a'&& (x)<= 'z' ? \ 	((x) - 'a' + 1) : (((x) - 'A' + 1)& 0x7f))
end_define

begin_define
define|#
directive|define
name|CEOF
value|CTRL('D')
end_define

begin_define
define|#
directive|define
name|CEOL
value|0xff
end_define

begin_comment
comment|/* XXX avoid _POSIX_VDISABLE */
end_comment

begin_define
define|#
directive|define
name|CERASE
value|CTRL('?')
end_define

begin_define
define|#
directive|define
name|CERASE2
value|CTRL('H')
end_define

begin_define
define|#
directive|define
name|CINTR
value|CTRL('C')
end_define

begin_define
define|#
directive|define
name|CSTATUS
value|CTRL('T')
end_define

begin_define
define|#
directive|define
name|CKILL
value|CTRL('U')
end_define

begin_define
define|#
directive|define
name|CMIN
value|1
end_define

begin_define
define|#
directive|define
name|CQUIT
value|CTRL('\\')
end_define

begin_define
define|#
directive|define
name|CSUSP
value|CTRL('Z')
end_define

begin_define
define|#
directive|define
name|CTIME
value|0
end_define

begin_define
define|#
directive|define
name|CDSUSP
value|CTRL('Y')
end_define

begin_define
define|#
directive|define
name|CSTART
value|CTRL('Q')
end_define

begin_define
define|#
directive|define
name|CSTOP
value|CTRL('S')
end_define

begin_define
define|#
directive|define
name|CLNEXT
value|CTRL('V')
end_define

begin_define
define|#
directive|define
name|CDISCARD
value|CTRL('O')
end_define

begin_define
define|#
directive|define
name|CWERASE
value|CTRL('W')
end_define

begin_define
define|#
directive|define
name|CREPRINT
value|CTRL('R')
end_define

begin_define
define|#
directive|define
name|CEOT
value|CEOF
end_define

begin_comment
comment|/* compat */
end_comment

begin_define
define|#
directive|define
name|CBRK
value|CEOL
end_define

begin_define
define|#
directive|define
name|CRPRNT
value|CREPRINT
end_define

begin_define
define|#
directive|define
name|CFLUSH
value|CDISCARD
end_define

begin_comment
comment|/* PROTECTED INCLUSION ENDS HERE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TTYDEFAULTS_H_ */
end_comment

begin_comment
comment|/*  * #define TTYDEFCHARS to include an array of default control characters.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TTYDEFCHARS
end_ifdef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_termios.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|cc_t
name|ttydefchars
index|[]
init|=
block|{
name|CEOF
block|,
name|CEOL
block|,
name|CEOL
block|,
name|CERASE
block|,
name|CWERASE
block|,
name|CKILL
block|,
name|CREPRINT
block|,
name|CERASE2
block|,
name|CINTR
block|,
name|CQUIT
block|,
name|CSUSP
block|,
name|CDSUSP
block|,
name|CSTART
block|,
name|CSTOP
block|,
name|CLNEXT
block|,
name|CDISCARD
block|,
name|CMIN
block|,
name|CTIME
block|,
name|CSTATUS
block|,
name|_POSIX_VDISABLE
block|}
decl_stmt|;
end_decl_stmt

begin_assert
assert|_Static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|ttydefchars
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|cc_t
argument_list|)
operator|==
name|NCCS
argument_list|,
literal|"Size of ttydefchars does not match NCCS"
argument_list|)
assert|;
end_assert

begin_undef
undef|#
directive|undef
name|TTYDEFCHARS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TTYDEFCHARS */
end_comment

end_unit

