begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1995 Matt Thomas (thomas@lkg.dec.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_fddi.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IF_FDDI_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IF_FDDI_H_
end_define

begin_comment
comment|/*  * Structure of an 100Mb/s FDDI header.  */
end_comment

begin_struct
struct|struct
name|fddi_header
block|{
name|u_char
name|fddi_fc
decl_stmt|;
name|u_char
name|fddi_dhost
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|fddi_shost
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FDDIIPMTU
value|4352
end_define

begin_define
define|#
directive|define
name|FDDIMTU
value|4470
end_define

begin_define
define|#
directive|define
name|FDDIMIN
value|3
end_define

begin_define
define|#
directive|define
name|FDDIFC_C
value|0x80
end_define

begin_comment
comment|/* 0b10000000 */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_L
value|0x40
end_define

begin_comment
comment|/* 0b01000000 */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_F
value|0x30
end_define

begin_comment
comment|/* 0b00110000 */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_Z
value|0x0F
end_define

begin_comment
comment|/* 0b00001111 */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_LLC_ASYNC
value|0x50
end_define

begin_define
define|#
directive|define
name|FDDIFC_LLC_PRIO0
value|0
end_define

begin_define
define|#
directive|define
name|FDDIFC_LLC_PRIO1
value|1
end_define

begin_define
define|#
directive|define
name|FDDIFC_LLC_PRIO2
value|2
end_define

begin_define
define|#
directive|define
name|FDDIFC_LLC_PRIO3
value|3
end_define

begin_define
define|#
directive|define
name|FDDIFC_LLC_PRIO4
value|4
end_define

begin_define
define|#
directive|define
name|FDDIFC_LLC_PRIO5
value|5
end_define

begin_define
define|#
directive|define
name|FDDIFC_LLC_PRIO6
value|6
end_define

begin_define
define|#
directive|define
name|FDDIFC_LLC_PRIO7
value|7
end_define

begin_define
define|#
directive|define
name|FDDIFC_LLC_SYNC
value|0xd0
end_define

begin_define
define|#
directive|define
name|FDDIFC_SMT
value|0x40
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|fddibroadcastaddr
value|etherbroadcastaddr
end_define

begin_define
define|#
directive|define
name|fddi_ipmulticast_min
value|ether_ipmulticast_min
end_define

begin_define
define|#
directive|define
name|fddi_ipmulticast_max
value|ether_ipmulticast_max
end_define

begin_define
define|#
directive|define
name|fddi_addmulti
value|ether_addmulti
end_define

begin_define
define|#
directive|define
name|fddi_delmulti
value|ether_delmulti
end_define

begin_define
define|#
directive|define
name|fddi_sprintf
value|ether_sprintf
end_define

begin_decl_stmt
name|void
name|fddi_ifattach
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fddi_input
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|fddi_header
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fddi_output
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

