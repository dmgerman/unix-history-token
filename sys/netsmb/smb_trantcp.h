begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETSMB_SMB_TRANTCP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETSMB_SMB_TRANTCP_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NB_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|NBDEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf("%s(%d): "format,	\ 					    __FUNCTION__ , __LINE__ ,## args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NBDEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|nbstate
block|{
name|NBST_CLOSED
block|,
name|NBST_RQSENT
block|,
name|NBST_SESSION
block|,
name|NBST_RETARGET
block|,
name|NBST_REFUSED
block|}
enum|;
end_enum

begin_comment
comment|/*  * socket specific data  */
end_comment

begin_struct
struct|struct
name|nbpcb
block|{
name|struct
name|smb_vc
modifier|*
name|nbp_vc
decl_stmt|;
name|struct
name|socket
modifier|*
name|nbp_tso
decl_stmt|;
comment|/* transport socket */
name|struct
name|sockaddr_nb
modifier|*
name|nbp_laddr
decl_stmt|;
comment|/* local address */
name|struct
name|sockaddr_nb
modifier|*
name|nbp_paddr
decl_stmt|;
comment|/* peer address */
name|int
name|nbp_flags
decl_stmt|;
define|#
directive|define
name|NBF_LOCADDR
value|0x0001
comment|/* has local addr */
define|#
directive|define
name|NBF_CONNECTED
value|0x0002
define|#
directive|define
name|NBF_RECVLOCK
value|0x0004
name|enum
name|nbstate
name|nbp_state
decl_stmt|;
name|struct
name|timespec
name|nbp_timo
decl_stmt|;
name|int
name|nbp_sndbuf
decl_stmt|;
name|int
name|nbp_rcvbuf
decl_stmt|;
name|void
modifier|*
name|nbp_selectid
decl_stmt|;
comment|/*	LIST_ENTRY(nbpcb) nbp_link;*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Nominal space allocated per a NETBIOS socket.  */
end_comment

begin_define
define|#
directive|define
name|NB_SNDQ
value|(10 * 1024)
end_define

begin_define
define|#
directive|define
name|NB_RCVQ
value|(20 * 1024)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|smb_tran_desc
name|smb_tran_nbtcp_desc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETSMB_SMB_TRANTCP_H_ */
end_comment

end_unit

