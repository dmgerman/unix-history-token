begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNCP_NCP_USER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNCP_NCP_USER_H_
end_define

begin_comment
comment|/*   * "ncp" interface to kernel, this can be done via syscalls but may eat  * a lot of them, so we select internal code, define req's and replays  * as necessary. Structure for call is simple:  * byte=NCP_CONN  * byte=NCP_CONN_SUBFN  * ....=data  */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN
value|0xF5
end_define

begin_comment
comment|/* change if that will occupied */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_READ
value|0x01
end_define

begin_comment
comment|/* read from file handle */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_WRITE
value|0x02
end_define

begin_comment
comment|/* write to file handle */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_SETFLAGS
value|0x03
end_define

begin_comment
comment|/* word mask, word flags */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_LOGIN
value|0x04
end_define

begin_comment
comment|/* bind login on handle */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_GETINFO
value|0x05
end_define

begin_comment
comment|/* get information about connection */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_GETUSER
value|0x06
end_define

begin_comment
comment|/* get user name for connection */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_CONN2REF
value|0x07
end_define

begin_comment
comment|/* convert handle to reference */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_CONNCLOSE
value|0x08
end_define

begin_comment
comment|/* release connection handle */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_FRAG
value|0x09
end_define

begin_comment
comment|/* ncp fragmented request */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_DUP
value|0x0A
end_define

begin_comment
comment|/* get an additional handle */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_GETDATA
value|0x0B
end_define

begin_comment
comment|/* retrieve NCP_CD_* vals */
end_comment

begin_define
define|#
directive|define
name|NCP_CONN_SETDATA
value|0x0C
end_define

begin_comment
comment|/* store NCP_CD_* vals */
end_comment

begin_comment
comment|/*  * Internal connection data can be set by owner or superuser and retrieved  * only by superuser  */
end_comment

begin_define
define|#
directive|define
name|NCP_CD_NDSLOGINKEY
value|0x01
end_define

begin_define
define|#
directive|define
name|NCP_CD_NDSPRIVATEKEY
value|0x02
end_define

begin_define
define|#
directive|define
name|NCP_CD_NDSUFLAGS
value|0x03
end_define

begin_comment
comment|/* user side structures to issue fragmented ncp calls */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|fragAddress
decl_stmt|;
name|u_int32_t
name|fragSize
decl_stmt|;
block|}
name|NW_FRAGMENT
typedef|;
end_typedef

begin_struct
struct|struct
name|ncp_rw
block|{
name|ncp_fh
name|nrw_fh
decl_stmt|;
name|char
modifier|*
name|nrw_base
decl_stmt|;
name|off_t
name|nrw_offset
decl_stmt|;
name|int
name|nrw_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ncp_conn_login
block|{
name|char
modifier|*
name|username
decl_stmt|;
name|int
name|objtype
decl_stmt|;
name|char
modifier|*
name|password
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ncp_conn_frag
block|{
name|int
name|cc
decl_stmt|;
comment|/* completion code */
name|int
name|cs
decl_stmt|;
comment|/* connection state */
name|int
name|fn
decl_stmt|;
name|int
name|rqfcnt
decl_stmt|;
name|NW_FRAGMENT
modifier|*
name|rqf
decl_stmt|;
name|int
name|rpfcnt
decl_stmt|;
name|NW_FRAGMENT
modifier|*
name|rpf
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

