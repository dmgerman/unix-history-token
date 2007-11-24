begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/* $OpenBSD: if_pflog.h,v 1.11 2004/05/19 17:50:51 dhartmei Exp $ */
end_comment

begin_comment
comment|/*  * Copyright 2001 Niels Provos<provos@citi.umich.edu>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_PFLOG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_PFLOG_H_
end_define

begin_struct
struct|struct
name|pflog_softc
block|{
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
comment|/* the interface */
name|LIST_ENTRY
argument_list|(
argument|pflog_softc
argument_list|)
name|sc_next
expr_stmt|;
else|#
directive|else
name|struct
name|ifnet
name|sc_if
decl_stmt|;
comment|/* the interface */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PFLOG_RULESET_NAME_SIZE
value|16
end_define

begin_struct
struct|struct
name|pfloghdr
block|{
name|u_int8_t
name|length
decl_stmt|;
name|sa_family_t
name|af
decl_stmt|;
name|u_int8_t
name|action
decl_stmt|;
name|u_int8_t
name|reason
decl_stmt|;
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|char
name|ruleset
index|[
name|PFLOG_RULESET_NAME_SIZE
index|]
decl_stmt|;
name|u_int32_t
name|rulenr
decl_stmt|;
name|u_int32_t
name|subrulenr
decl_stmt|;
name|u_int8_t
name|dir
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PFLOG_HDRLEN
value|sizeof(struct pfloghdr)
end_define

begin_comment
comment|/* minus pad, also used as a signature */
end_comment

begin_define
define|#
directive|define
name|PFLOG_REAL_HDRLEN
value|offsetof(struct pfloghdr, pad)
end_define

begin_comment
comment|/* XXX remove later when old format logs are no longer needed */
end_comment

begin_struct
struct|struct
name|old_pfloghdr
block|{
name|u_int32_t
name|af
decl_stmt|;
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|short
name|rnr
decl_stmt|;
name|u_short
name|reason
decl_stmt|;
name|u_short
name|action
decl_stmt|;
name|u_short
name|dir
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OLD_PFLOG_HDRLEN
value|sizeof(struct old_pfloghdr)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_struct_decl
struct_decl|struct
name|pf_rule
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pf_ruleset
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pfi_kif
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|pflog_packet_t
parameter_list|(
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|struct
name|pf_ruleset
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|pflog_packet_t
modifier|*
name|pflog_packet_ptr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PFLOG_PACKET
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
value|do {		\ 	if (pflog_packet_ptr != NULL)			\ 		pflog_packet_ptr(i,a,b,c,d,e,f,g);	\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|NPFLOG
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|PFLOG_PACKET
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
value|pflog_packet(i,a,b,c,d,e,f,g)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PFLOG_PACKET
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NPFLOG> 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

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
comment|/* _NET_IF_PFLOG_H_ */
end_comment

end_unit

