begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)rwhod.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROTOCOLS_RWHOD_H_
end_ifndef

begin_define
define|#
directive|define
name|_PROTOCOLS_RWHOD_H_
end_define

begin_comment
comment|/*  * rwho protocol packet format.  */
end_comment

begin_struct
struct|struct
name|outmp
block|{
name|char
name|out_line
index|[
literal|8
index|]
decl_stmt|;
comment|/* tty name */
name|char
name|out_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* user id */
name|int32_t
name|out_time
decl_stmt|;
comment|/* time on */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|whod
block|{
name|char
name|wd_vers
decl_stmt|;
comment|/* protocol version # */
name|char
name|wd_type
decl_stmt|;
comment|/* packet type, see below */
name|char
name|wd_pad
index|[
literal|2
index|]
decl_stmt|;
name|int
name|wd_sendtime
decl_stmt|;
comment|/* time stamp by sender */
name|int
name|wd_recvtime
decl_stmt|;
comment|/* time stamp applied by receiver */
name|char
name|wd_hostname
index|[
literal|32
index|]
decl_stmt|;
comment|/* hosts's name */
name|int
name|wd_loadav
index|[
literal|3
index|]
decl_stmt|;
comment|/* load average as in uptime */
name|int
name|wd_boottime
decl_stmt|;
comment|/* time system booted */
struct|struct
name|whoent
block|{
name|struct
name|outmp
name|we_utmp
decl_stmt|;
comment|/* active tty info */
name|int
name|we_idle
decl_stmt|;
comment|/* tty idle time */
block|}
name|wd_we
index|[
literal|1024
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|whoent
argument_list|)
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WHODVERSION
value|1
end_define

begin_define
define|#
directive|define
name|WHODTYPE_STATUS
value|1
end_define

begin_comment
comment|/* host status */
end_comment

begin_define
define|#
directive|define
name|_PATH_RWHODIR
value|"/var/rwho"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RWHOD_H_ */
end_comment

end_unit

