begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)pathnames.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_comment
comment|/* 	Specify path to ACU (modem) log */
end_comment

begin_define
define|#
directive|define
name|_PATH_ACULOG
value|"/var/log/aculog"
end_define

begin_comment
comment|/* 	Specify path and format of lock files */
end_comment

begin_comment
comment|/* #define _PATH_LOCKDIRNAME "/usr/spool/uucp/LCK..%s" */
end_comment

begin_comment
comment|/* #define _PATH_LOCKDIRNAME "/etc/locks/LCK..%s" */
end_comment

begin_comment
comment|/* #define _PATH_LOCKDIRNAME "/usr/spool/locks/LCK..%s" */
end_comment

begin_comment
comment|/* #define _PATH_LOCKDIRNAME "/usr/spool/uucp/LCK/LCK..%s" */
end_comment

begin_define
define|#
directive|define
name|_PATH_LOCKDIRNAME
value|_PATH_UUCPLOCK "LCK..%s"
end_define

begin_comment
comment|/* 	Specify location for system wide databases */
end_comment

begin_define
define|#
directive|define
name|_PATH_MODEMS
value|"/etc/modems"
end_define

begin_define
define|#
directive|define
name|_PATH_PHONES
value|"/etc/phones"
end_define

begin_define
define|#
directive|define
name|_PATH_REMOTE
value|"/etc/remote"
end_define

end_unit

