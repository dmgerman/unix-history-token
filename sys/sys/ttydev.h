begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ttydev.h	8.2 (Berkeley) 1/4/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/* COMPATIBILITY HEADER FILE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TTYDEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TTYDEV_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OLD_TTY
end_ifdef

begin_define
define|#
directive|define
name|B0
value|0
end_define

begin_define
define|#
directive|define
name|B50
value|1
end_define

begin_define
define|#
directive|define
name|B75
value|2
end_define

begin_define
define|#
directive|define
name|B110
value|3
end_define

begin_define
define|#
directive|define
name|B134
value|4
end_define

begin_define
define|#
directive|define
name|B150
value|5
end_define

begin_define
define|#
directive|define
name|B200
value|6
end_define

begin_define
define|#
directive|define
name|B300
value|7
end_define

begin_define
define|#
directive|define
name|B600
value|8
end_define

begin_define
define|#
directive|define
name|B1200
value|9
end_define

begin_define
define|#
directive|define
name|B1800
value|10
end_define

begin_define
define|#
directive|define
name|B2400
value|11
end_define

begin_define
define|#
directive|define
name|B4800
value|12
end_define

begin_define
define|#
directive|define
name|B9600
value|13
end_define

begin_define
define|#
directive|define
name|EXTA
value|14
end_define

begin_define
define|#
directive|define
name|EXTB
value|15
end_define

begin_define
define|#
directive|define
name|B57600
value|16
end_define

begin_define
define|#
directive|define
name|B115200
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_OLD_TTY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TTYDEV_H_ */
end_comment

end_unit

