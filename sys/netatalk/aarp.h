begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990,1991 Regents of The University of Michigan.  * All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation, and that the name of The University  * of Michigan not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission. This software is supplied as is without expressed or  * implied warranties of any kind.  *  * This product includes software developed by the University of  * California, Berkeley and its contributors.  *  *	Research Systems Unix Group  *	The University of Michigan  *	c/o Wesley Craig  *	535 W. William Street  *	Ann Arbor, Michigan  *	+1-313-764-2278  *	netatalk@umich.edu  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATALK_AARP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETATALK_AARP_H_
end_define

begin_comment
comment|/*  * This structure is used for both phase 1 and 2. Under phase 1  * the net is not filled in. It is in phase 2. In both cases, the  * hardware address length is (for some unknown reason) 4. If  * anyone at Apple could program their way out of paper bag, it  * would be 1 and 3 respectively for phase 1 and 2.  */
end_comment

begin_union
union|union
name|aapa
block|{
name|u_char
name|ap_pa
index|[
literal|4
index|]
decl_stmt|;
struct|struct
name|ap_node
block|{
name|u_char
name|an_zero
decl_stmt|;
name|u_char
name|an_net
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|an_node
decl_stmt|;
block|}
name|ap_node
struct|;
block|}
union|;
end_union

begin_struct
struct|struct
name|ether_aarp
block|{
name|struct
name|arphdr
name|eaa_hdr
decl_stmt|;
name|u_char
name|aarp_sha
index|[
literal|6
index|]
decl_stmt|;
name|union
name|aapa
name|aarp_spu
decl_stmt|;
name|u_char
name|aarp_tha
index|[
literal|6
index|]
decl_stmt|;
name|union
name|aapa
name|aarp_tpu
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|aarp_hrd
value|eaa_hdr.ar_hrd
end_define

begin_define
define|#
directive|define
name|aarp_pro
value|eaa_hdr.ar_pro
end_define

begin_define
define|#
directive|define
name|aarp_hln
value|eaa_hdr.ar_hln
end_define

begin_define
define|#
directive|define
name|aarp_pln
value|eaa_hdr.ar_pln
end_define

begin_define
define|#
directive|define
name|aarp_op
value|eaa_hdr.ar_op
end_define

begin_define
define|#
directive|define
name|aarp_spa
value|aarp_spu.ap_node.an_node
end_define

begin_define
define|#
directive|define
name|aarp_tpa
value|aarp_tpu.ap_node.an_node
end_define

begin_define
define|#
directive|define
name|aarp_spnet
value|aarp_spu.ap_node.an_net
end_define

begin_define
define|#
directive|define
name|aarp_tpnet
value|aarp_tpu.ap_node.an_net
end_define

begin_define
define|#
directive|define
name|aarp_spnode
value|aarp_spu.ap_node.an_node
end_define

begin_define
define|#
directive|define
name|aarp_tpnode
value|aarp_tpu.ap_node.an_node
end_define

begin_struct
struct|struct
name|aarptab
block|{
name|struct
name|at_addr
name|aat_ataddr
decl_stmt|;
name|u_char
name|aat_enaddr
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|aat_timer
decl_stmt|;
name|u_char
name|aat_flags
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|aat_hold
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AARPHRD_ETHER
value|0x0001
end_define

begin_define
define|#
directive|define
name|AARPOP_REQUEST
value|0x01
end_define

begin_define
define|#
directive|define
name|AARPOP_RESPONSE
value|0x02
end_define

begin_define
define|#
directive|define
name|AARPOP_PROBE
value|0x03
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|struct
name|aarptab
modifier|*
name|aarptnew
parameter_list|(
name|struct
name|at_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETATALK_AARP_H_ */
end_comment

end_unit

