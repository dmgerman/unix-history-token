begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETSMB_NETBIOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETSMB_NETBIOS_H_
end_define

begin_comment
comment|/*  * make this file dirty...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_H_
end_ifndef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_IPX_H_
end_ifndef

begin_include
include|#
directive|include
file|<netipx/ipx.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AF_NETBIOS
value|AF_NS
end_define

begin_comment
comment|/* XXX: should go to socket.h */
end_comment

begin_define
define|#
directive|define
name|PF_NETBIOS
value|AF_NETBIOS
end_define

begin_define
define|#
directive|define
name|NBPROTO_TCPSSN
value|1
end_define

begin_comment
comment|/* NETBIOS session over TCP */
end_comment

begin_define
define|#
directive|define
name|NBPROTO_IPXSSN
value|11
end_define

begin_comment
comment|/* NETBIOS over IPX */
end_comment

begin_define
define|#
directive|define
name|NB_NAMELEN
value|16
end_define

begin_define
define|#
directive|define
name|NB_ENCNAMELEN
value|NB_NAMELEN * 2
end_define

begin_define
define|#
directive|define
name|NB_MAXLABLEN
value|63
end_define

begin_define
define|#
directive|define
name|NB_MINSALEN
value|(sizeof(struct sockaddr_nb))
end_define

begin_comment
comment|/*  * name types  */
end_comment

begin_define
define|#
directive|define
name|NBT_WKSTA
value|0x00
end_define

begin_define
define|#
directive|define
name|NBT_SERVER
value|0x20
end_define

begin_comment
comment|/*  * Session packet types  */
end_comment

begin_define
define|#
directive|define
name|NB_SSN_MESSAGE
value|0x0
end_define

begin_define
define|#
directive|define
name|NB_SSN_REQUEST
value|0x81
end_define

begin_define
define|#
directive|define
name|NB_SSN_POSRESP
value|0x82
end_define

begin_define
define|#
directive|define
name|NB_SSN_NEGRESP
value|0x83
end_define

begin_define
define|#
directive|define
name|NB_SSN_RTGRESP
value|0x84
end_define

begin_define
define|#
directive|define
name|NB_SSN_KEEPALIVE
value|0x85
end_define

begin_comment
comment|/*  * resolver: Opcodes  */
end_comment

begin_define
define|#
directive|define
name|NBNS_OPCODE_QUERY
value|0x00
end_define

begin_define
define|#
directive|define
name|NBNS_OPCODE_REGISTER
value|0x05
end_define

begin_define
define|#
directive|define
name|NBNS_OPCODE_RELEASE
value|0x06
end_define

begin_define
define|#
directive|define
name|NBNS_OPCODE_WACK
value|0x07
end_define

begin_define
define|#
directive|define
name|NBNS_OPCODE_REFRESH
value|0x08
end_define

begin_define
define|#
directive|define
name|NBNS_OPCODE_RESPONSE
value|0x10
end_define

begin_comment
comment|/* or'ed with other opcodes */
end_comment

begin_comment
comment|/*  * resolver: NM_FLAGS  */
end_comment

begin_define
define|#
directive|define
name|NBNS_NMFLAG_BCAST
value|0x01
end_define

begin_define
define|#
directive|define
name|NBNS_NMFLAG_RA
value|0x08
end_define

begin_comment
comment|/* recursion available */
end_comment

begin_define
define|#
directive|define
name|NBNS_NMFLAG_RD
value|0x10
end_define

begin_comment
comment|/* recursion desired */
end_comment

begin_define
define|#
directive|define
name|NBNS_NMFLAG_TC
value|0x20
end_define

begin_comment
comment|/* truncation occured */
end_comment

begin_define
define|#
directive|define
name|NBNS_NMFLAG_AA
value|0x40
end_define

begin_comment
comment|/* authoritative answer */
end_comment

begin_comment
comment|/*   * resolver: Question types  */
end_comment

begin_define
define|#
directive|define
name|NBNS_QUESTION_TYPE_NB
value|0x0020
end_define

begin_define
define|#
directive|define
name|NBNS_QUESTION_TYPE_NBSTAT
value|0x0021
end_define

begin_comment
comment|/*   * resolver: Question class   */
end_comment

begin_define
define|#
directive|define
name|NBNS_QUESTION_CLASS_IN
value|0x0001
end_define

begin_comment
comment|/*  * resolver: Limits  */
end_comment

begin_define
define|#
directive|define
name|NBNS_MAXREDIRECTS
value|3
end_define

begin_comment
comment|/* maximum number of accepted redirects */
end_comment

begin_define
define|#
directive|define
name|NBDG_MAXSIZE
value|576
end_define

begin_comment
comment|/* maximum nbns datagram size */
end_comment

begin_comment
comment|/*  * NETBIOS addressing  */
end_comment

begin_union
union|union
name|nb_tran
block|{
name|struct
name|sockaddr_in
name|x_in
decl_stmt|;
name|struct
name|sockaddr_ipx
name|x_ipx
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|nb_name
block|{
name|u_int
name|nn_type
decl_stmt|;
name|u_char
name|nn_name
index|[
name|NB_NAMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|u_char
modifier|*
name|nn_scope
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Socket address  */
end_comment

begin_struct
struct|struct
name|sockaddr_nb
block|{
name|u_char
name|snb_len
decl_stmt|;
name|u_char
name|snb_family
decl_stmt|;
name|union
name|nb_tran
name|snb_tran
decl_stmt|;
comment|/* transport */
name|u_char
name|snb_name
index|[
literal|1
operator|+
name|NB_ENCNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* encoded */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|snb_addrin
value|snb_tran.x_in
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETSMB_NETBIOS_H_ */
end_comment

end_unit

