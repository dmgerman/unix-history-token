begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tipconf.h	8.1 (Berkeley) 3/25/95  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tipconf_h_included
end_ifndef

begin_define
define|#
directive|define
name|tipconf_h_included
end_define

begin_comment
comment|/* 	Define constness */
end_comment

begin_define
define|#
directive|define
name|CONST
value|const
end_define

begin_comment
comment|/* 	Specify default bit rate for connections */
end_comment

begin_define
define|#
directive|define
name|DEFBR
value|1200
end_define

begin_comment
comment|/* 	Default frame size for file transfer buffering of writes 	on local side */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUFSIZ
end_ifndef

begin_define
define|#
directive|define
name|DEFFS
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFFS
value|BUFSIZ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	Enable logging of ACU use */
end_comment

begin_define
define|#
directive|define
name|ACULOG
value|1
end_define

begin_comment
comment|/* 	Strip phone #s from ACU log file */
end_comment

begin_define
define|#
directive|define
name|PRISTINE
value|1
end_define

begin_comment
comment|/* 	Enable command to "connect" remote with local process */
end_comment

begin_define
define|#
directive|define
name|CONNECT
value|1
end_define

begin_comment
comment|/* 	Specify style of UUCP lock files */
end_comment

begin_define
define|#
directive|define
name|HAVE_V2_LOCKFILES
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_HDB_LOCKFILES
value|1
end_define

begin_comment
comment|/* 	System has a millisecond based sleep function */
end_comment

begin_define
define|#
directive|define
name|HAVE_USLEEP
value|0
end_define

begin_comment
comment|/* 	System has select */
end_comment

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_comment
comment|/* 	System has termios tty interface */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS
value|1
end_define

begin_comment
comment|/* 	Include configurable modem driver */
end_comment

begin_define
define|#
directive|define
name|UNIDIALER
value|1
end_define

begin_comment
comment|/* 	Specify builtin modem drivers to include */
end_comment

begin_define
define|#
directive|define
name|BIZ1031
value|0
end_define

begin_define
define|#
directive|define
name|BIZ1022
value|0
end_define

begin_define
define|#
directive|define
name|COURIER
value|0
end_define

begin_define
define|#
directive|define
name|DF02
value|0
end_define

begin_define
define|#
directive|define
name|DF03
value|0
end_define

begin_define
define|#
directive|define
name|DN11
value|0
end_define

begin_define
define|#
directive|define
name|HAYES
value|0
end_define

begin_define
define|#
directive|define
name|MULTITECH
value|0
end_define

begin_define
define|#
directive|define
name|T3000
value|0
end_define

begin_define
define|#
directive|define
name|V3451
value|0
end_define

begin_define
define|#
directive|define
name|V831
value|0
end_define

begin_define
define|#
directive|define
name|VENTEL
value|0
end_define

begin_comment
comment|/* 	Include cu interface so that, when tip is linked to cu and then 	invoked as cu, it behaves like cu. */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_CU_INTERFACE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of tipconf.h */
end_comment

end_unit

