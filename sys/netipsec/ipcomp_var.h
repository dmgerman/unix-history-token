begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: ipcomp.h,v 1.8 2000/09/26 07:55:14 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1999 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPSEC_IPCOMP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPSEC_IPCOMP_VAR_H_
end_define

begin_comment
comment|/*  * These define the algorithm indices into the histogram.  They're  * presently based on the PF_KEY v2 protocol values which is bogus;  * they should be decoupled from the protocol at which time we can  * pack them and reduce the size of the array to a minimum.  */
end_comment

begin_define
define|#
directive|define
name|IPCOMP_ALG_MAX
value|8
end_define

begin_define
define|#
directive|define
name|IPCOMPSTAT_VERSION
value|1
end_define

begin_struct
struct|struct
name|ipcompstat
block|{
name|u_int32_t
name|ipcomps_hdrops
decl_stmt|;
comment|/* Packet shorter than header shows */
name|u_int32_t
name|ipcomps_nopf
decl_stmt|;
comment|/* Protocol family not supported */
name|u_int32_t
name|ipcomps_notdb
decl_stmt|;
name|u_int32_t
name|ipcomps_badkcr
decl_stmt|;
name|u_int32_t
name|ipcomps_qfull
decl_stmt|;
name|u_int32_t
name|ipcomps_noxform
decl_stmt|;
name|u_int32_t
name|ipcomps_wrap
decl_stmt|;
name|u_int32_t
name|ipcomps_input
decl_stmt|;
comment|/* Input IPcomp packets */
name|u_int32_t
name|ipcomps_output
decl_stmt|;
comment|/* Output IPcomp packets */
name|u_int32_t
name|ipcomps_invalid
decl_stmt|;
comment|/* Trying to use an invalid TDB */
name|u_int64_t
name|ipcomps_ibytes
decl_stmt|;
comment|/* Input bytes */
name|u_int64_t
name|ipcomps_obytes
decl_stmt|;
comment|/* Output bytes */
name|u_int32_t
name|ipcomps_toobig
decl_stmt|;
comment|/* Packet got> IP_MAXPACKET */
name|u_int32_t
name|ipcomps_pdrops
decl_stmt|;
comment|/* Packet blocked due to policy */
name|u_int32_t
name|ipcomps_crypto
decl_stmt|;
comment|/* "Crypto" processing failure */
name|u_int32_t
name|ipcomps_hist
index|[
name|IPCOMP_ALG_MAX
index|]
decl_stmt|;
comment|/* Per-algorithm op count */
name|u_int32_t
name|version
decl_stmt|;
comment|/* Version of this structure. */
name|u_int32_t
name|ipcomps_threshold
decl_stmt|;
comment|/* Packet< comp. algo. threshold. */
name|u_int32_t
name|ipcomps_uncompr
decl_stmt|;
comment|/* Compression was useles. */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ipcomp_enable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipcompstat
name|ipcompstat
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
comment|/*_NETIPSEC_IPCOMP_VAR_H_*/
end_comment

end_unit

