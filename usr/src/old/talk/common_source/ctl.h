begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1985  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ctl.h	5.1 (Berkeley) 6/6/85  */
end_comment

begin_comment
comment|/*  * ctl.h describes the structure that  * talk and talkd pass back and forth.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_define
define|#
directive|define
name|NAME_SIZE
value|9
end_define

begin_define
define|#
directive|define
name|TTY_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|HOST_NAME_LENGTH
value|256
end_define

begin_define
define|#
directive|define
name|MAX_LIFE
value|60
end_define

begin_comment
comment|/* max time daemon saves invitations */
end_comment

begin_comment
comment|/* RING_WAIT should be 10's of seconds less than MAX_LIFE */
end_comment

begin_define
define|#
directive|define
name|RING_WAIT
value|30
end_define

begin_comment
comment|/* time to wait before refreshing invitation */
end_comment

begin_comment
comment|/* type values */
end_comment

begin_define
define|#
directive|define
name|LEAVE_INVITE
value|0
end_define

begin_define
define|#
directive|define
name|LOOK_UP
value|1
end_define

begin_define
define|#
directive|define
name|DELETE
value|2
end_define

begin_define
define|#
directive|define
name|ANNOUNCE
value|3
end_define

begin_comment
comment|/* answer values */
end_comment

begin_define
define|#
directive|define
name|SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|NOT_HERE
value|1
end_define

begin_define
define|#
directive|define
name|FAILED
value|2
end_define

begin_define
define|#
directive|define
name|MACHINE_UNKNOWN
value|3
end_define

begin_define
define|#
directive|define
name|PERMISSION_DENIED
value|4
end_define

begin_define
define|#
directive|define
name|UNKNOWN_REQUEST
value|5
end_define

begin_typedef
typedef|typedef
struct|struct
name|ctl_response
block|{
name|char
name|type
decl_stmt|;
name|char
name|answer
decl_stmt|;
name|int
name|id_num
decl_stmt|;
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
block|}
name|CTL_RESPONSE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ctl_msg
block|{
name|char
name|type
decl_stmt|;
name|char
name|l_name
index|[
name|NAME_SIZE
index|]
decl_stmt|;
name|char
name|r_name
index|[
name|NAME_SIZE
index|]
decl_stmt|;
name|int
name|id_num
decl_stmt|;
name|int
name|pid
decl_stmt|;
name|char
name|r_tty
index|[
name|TTY_SIZE
index|]
decl_stmt|;
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
name|struct
name|sockaddr_in
name|ctl_addr
decl_stmt|;
block|}
name|CTL_MSG
typedef|;
end_typedef

end_unit

