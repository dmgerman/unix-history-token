begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2008 University of Zagreb  * Copyright (c) 2006-2008 FreeBSD Foundation  *  * This software was developed by the University of Zagreb and the  * FreeBSD Foundation under sponsorship by the Stichting NLnet and the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_VNET_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_VNET_H_
end_define

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_struct
struct|struct
name|vnet_net
block|{
name|int
name|_if_index
decl_stmt|;
name|struct
name|ifindex_entry
modifier|*
name|_ifindex_table
decl_stmt|;
name|struct
name|ifnethead
name|_ifnet
decl_stmt|;
name|struct
name|ifgrouphead
name|_ifg_head
decl_stmt|;
name|int
name|_if_indexlim
decl_stmt|;
name|struct
name|knlist
name|_ifklist
decl_stmt|;
name|struct
name|rtstat
name|_rtstat
decl_stmt|;
name|struct
name|radix_node_head
modifier|*
name|_rt_tables
index|[
name|RT_MAXFIBS
index|]
index|[
name|AF_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|_rttrash
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|_loif
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|lo_softc
argument_list|)
name|_lo_list
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|rawcb
argument_list|)
name|_rawcb_list
expr_stmt|;
name|int
name|_ether_ipfw
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Size guard. See sys/vimage.h. */
end_comment

begin_expr_stmt
name|VIMAGE_CTASSERT
argument_list|(
name|SIZEOF_vnet_net
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|vnet_net
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|VIMAGE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|VIMAGE_GLOBALS
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|vnet_net
name|vnet_net_0
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

begin_comment
comment|/*  * Symbol translation macros  */
end_comment

begin_define
define|#
directive|define
name|INIT_VNET_NET
parameter_list|(
name|vnet
parameter_list|)
define|\
value|INIT_FROM_VNET(vnet, VNET_MOD_NET, struct vnet_net, vnet_net)
end_define

begin_define
define|#
directive|define
name|VNET_NET
parameter_list|(
name|sym
parameter_list|)
value|VSYM(vnet_net, sym)
end_define

begin_define
define|#
directive|define
name|V_ether_ipfw
value|VNET_NET(ether_ipfw)
end_define

begin_define
define|#
directive|define
name|V_if_index
value|VNET_NET(if_index)
end_define

begin_define
define|#
directive|define
name|V_if_indexlim
value|VNET_NET(if_indexlim)
end_define

begin_define
define|#
directive|define
name|V_ifg_head
value|VNET_NET(ifg_head)
end_define

begin_define
define|#
directive|define
name|V_ifindex_table
value|VNET_NET(ifindex_table)
end_define

begin_define
define|#
directive|define
name|V_ifklist
value|VNET_NET(ifklist)
end_define

begin_define
define|#
directive|define
name|V_ifnet
value|VNET_NET(ifnet)
end_define

begin_define
define|#
directive|define
name|V_lo_list
value|VNET_NET(lo_list)
end_define

begin_define
define|#
directive|define
name|V_loif
value|VNET_NET(loif)
end_define

begin_define
define|#
directive|define
name|V_rawcb_list
value|VNET_NET(rawcb_list)
end_define

begin_define
define|#
directive|define
name|V_rt_tables
value|VNET_NET(rt_tables)
end_define

begin_define
define|#
directive|define
name|V_rtstat
value|VNET_NET(rtstat)
end_define

begin_define
define|#
directive|define
name|V_rttrash
value|VNET_NET(rttrash)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_VNET_H_ */
end_comment

end_unit

