begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)stty.h	8.1 (Berkeley) 5/31/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_struct
struct|struct
name|info
block|{
name|int
name|fd
decl_stmt|;
comment|/* file descriptor */
name|int
name|ldisc
decl_stmt|;
comment|/* line discipline */
name|int
name|off
decl_stmt|;
comment|/* turn off */
name|int
name|set
decl_stmt|;
comment|/* need set */
name|int
name|wset
decl_stmt|;
comment|/* need window set */
specifier|const
name|char
modifier|*
name|arg
decl_stmt|;
comment|/* argument */
name|struct
name|termios
name|t
decl_stmt|;
comment|/* terminal info */
name|struct
name|winsize
name|win
decl_stmt|;
comment|/* window info */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cchar
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|sub
decl_stmt|;
name|u_char
name|def
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|FMT
block|{
name|NOTSET
block|,
name|GFLAG
block|,
name|BSD
block|,
name|POSIX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|LINELENGTH
value|72
end_define

end_unit

