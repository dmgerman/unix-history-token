begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: ipcp.h,v 1.25 1999/03/03 23:00:40 brian Exp $  *  *	TODO:  */
end_comment

begin_define
define|#
directive|define
name|IPCP_MAXCODE
value|CODE_CODEREJ
end_define

begin_define
define|#
directive|define
name|TY_IPADDRS
value|1
end_define

begin_define
define|#
directive|define
name|TY_COMPPROTO
value|2
end_define

begin_define
define|#
directive|define
name|TY_IPADDR
value|3
end_define

begin_comment
comment|/* Domain NameServer and NetBIOS NameServer options */
end_comment

begin_define
define|#
directive|define
name|TY_PRIMARY_DNS
value|129
end_define

begin_define
define|#
directive|define
name|TY_PRIMARY_NBNS
value|130
end_define

begin_define
define|#
directive|define
name|TY_SECONDARY_DNS
value|131
end_define

begin_define
define|#
directive|define
name|TY_SECONDARY_NBNS
value|132
end_define

begin_define
define|#
directive|define
name|TY_ADJUST_NS
value|119
end_define

begin_comment
comment|/* subtract from NS val for REJECT bit */
end_comment

begin_struct_decl
struct_decl|struct
name|sticky_route
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|in_range
block|{
name|struct
name|in_addr
name|ipaddr
decl_stmt|;
name|struct
name|in_addr
name|mask
decl_stmt|;
name|int
name|width
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipcp
block|{
name|struct
name|fsm
name|fsm
decl_stmt|;
comment|/* The finite state machine */
struct|struct
block|{
struct|struct
block|{
name|int
name|slots
decl_stmt|;
comment|/* Maximum VJ slots */
name|unsigned
name|slotcomp
range|:
literal|1
decl_stmt|;
comment|/* Slot compression */
name|unsigned
name|neg
range|:
literal|2
decl_stmt|;
comment|/* VJ negotiation */
block|}
name|vj
struct|;
name|struct
name|in_range
name|my_range
decl_stmt|;
comment|/* MYADDR spec */
name|struct
name|in_addr
name|netmask
decl_stmt|;
comment|/* Iface netmask (unused by most OSs) */
name|struct
name|in_range
name|peer_range
decl_stmt|;
comment|/* HISADDR spec */
name|struct
name|iplist
name|peer_list
decl_stmt|;
comment|/* Ranges of HISADDR values */
name|u_long
name|sendpipe
decl_stmt|;
comment|/* route sendpipe size */
name|u_long
name|recvpipe
decl_stmt|;
comment|/* route recvpipe size */
name|struct
name|in_addr
name|TriggerAddress
decl_stmt|;
comment|/* Address to suggest in REQ */
name|unsigned
name|HaveTriggerAddress
range|:
literal|1
decl_stmt|;
comment|/* Trigger address specified */
struct|struct
block|{
name|struct
name|in_addr
name|dns
index|[
literal|2
index|]
decl_stmt|;
comment|/* DNS addresses offered */
name|unsigned
name|dns_neg
range|:
literal|2
decl_stmt|;
comment|/* dns negotiation */
name|struct
name|in_addr
name|nbns
index|[
literal|2
index|]
decl_stmt|;
comment|/* NetBIOS NS addresses offered */
block|}
name|ns
struct|;
name|struct
name|fsm_retry
name|fsm
decl_stmt|;
comment|/* How often/frequently to resend requests */
block|}
name|cfg
struct|;
struct|struct
block|{
name|struct
name|slcompress
name|cslc
decl_stmt|;
comment|/* VJ state */
name|struct
name|slstat
name|slstat
decl_stmt|;
comment|/* VJ statistics */
block|}
name|vj
struct|;
name|struct
name|sticky_route
modifier|*
name|route
decl_stmt|;
comment|/* List of dynamic routes */
name|unsigned
name|heis1172
range|:
literal|1
decl_stmt|;
comment|/* True if he is speaking rfc1172 */
name|struct
name|in_addr
name|peer_ip
decl_stmt|;
comment|/* IP address he's willing to use */
name|u_int32_t
name|peer_compproto
decl_stmt|;
comment|/* VJ params he's willing to use */
name|struct
name|in_addr
name|ifmask
decl_stmt|;
comment|/* Interface netmask */
name|struct
name|in_addr
name|my_ip
decl_stmt|;
comment|/* IP address I'm willing to use */
name|u_int32_t
name|my_compproto
decl_stmt|;
comment|/* VJ params I'm willing to use */
name|u_int32_t
name|peer_reject
decl_stmt|;
comment|/* Request codes rejected by peer */
name|u_int32_t
name|my_reject
decl_stmt|;
comment|/* Request codes I have rejected */
name|struct
name|pppThroughput
name|throughput
decl_stmt|;
comment|/* throughput statistics */
name|struct
name|mqueue
name|Queue
index|[
name|PRI_FAST
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Output packet queues */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|fsm2ipcp
parameter_list|(
name|fp
parameter_list|)
value|(fp->proto == PROTO_IPCP ? (struct ipcp *)fp : NULL)
end_define

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|link
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_Init
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|,
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
specifier|const
name|struct
name|fsm_parent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_Setup
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_SetLink
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_Show
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|ipcp_Input
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_AddInOctets
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_AddOutOctets
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_UseHisIPaddr
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_UseHisaddr
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_vjset
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_CleanInterface
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_InterfaceUp
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|in_addr
name|addr2mask
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

end_unit

