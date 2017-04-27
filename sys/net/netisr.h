begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2009 Robert N. M. Watson  * Copyright (c) 2010-2011 Juniper Networks, Inc.  * All rights reserved.  *  * This software was developed by Robert N. M. Watson under contract  * to Juniper Networks, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_NETISR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_NETISR_H_
end_define

begin_comment
comment|/*  * The netisr (network interrupt service routine) provides a deferred  * execution evironment in which (generally inbound) network processing can  * take place.  Protocols register handlers which will be executed directly,  * or via deferred dispatch, depending on the circumstances.  *  * Historically, this was implemented by the BSD software ISR facility; it is  * now implemented via a software ithread (SWI).  */
end_comment

begin_comment
comment|/*  * Protocol numbers, which are encoded in monitoring applications and kernel  * modules.  Internally, these are used in bit shift operations so must have  * a value 0< proto< 32; we currently further limit at compile-time to 16  * for array-sizing purposes.  */
end_comment

begin_define
define|#
directive|define
name|NETISR_IP
value|1
end_define

begin_define
define|#
directive|define
name|NETISR_IGMP
value|2
end_define

begin_comment
comment|/* IGMPv3 output queue */
end_comment

begin_define
define|#
directive|define
name|NETISR_ROUTE
value|3
end_define

begin_comment
comment|/* routing socket */
end_comment

begin_define
define|#
directive|define
name|NETISR_ARP
value|4
end_define

begin_comment
comment|/* same as AF_LINK */
end_comment

begin_define
define|#
directive|define
name|NETISR_ETHER
value|5
end_define

begin_comment
comment|/* ethernet input */
end_comment

begin_define
define|#
directive|define
name|NETISR_IPV6
value|6
end_define

begin_define
define|#
directive|define
name|NETISR_EPAIR
value|8
end_define

begin_comment
comment|/* if_epair(4) */
end_comment

begin_define
define|#
directive|define
name|NETISR_IP_DIRECT
value|9
end_define

begin_comment
comment|/* direct-dispatch IPv4 */
end_comment

begin_define
define|#
directive|define
name|NETISR_IPV6_DIRECT
value|10
end_define

begin_comment
comment|/* direct-dispatch IPv6 */
end_comment

begin_comment
comment|/*  * Protocol ordering and affinity policy constants.  See the detailed  * discussion of policies later in the file.  */
end_comment

begin_define
define|#
directive|define
name|NETISR_POLICY_SOURCE
value|1
end_define

begin_comment
comment|/* Maintain source ordering. */
end_comment

begin_define
define|#
directive|define
name|NETISR_POLICY_FLOW
value|2
end_define

begin_comment
comment|/* Maintain flow ordering. */
end_comment

begin_define
define|#
directive|define
name|NETISR_POLICY_CPU
value|3
end_define

begin_comment
comment|/* Protocol determines CPU placement. */
end_comment

begin_comment
comment|/*  * Protocol dispatch policy constants; selects whether and when direct  * dispatch is permitted.  */
end_comment

begin_define
define|#
directive|define
name|NETISR_DISPATCH_DEFAULT
value|0
end_define

begin_comment
comment|/* Use global default. */
end_comment

begin_define
define|#
directive|define
name|NETISR_DISPATCH_DEFERRED
value|1
end_define

begin_comment
comment|/* Always defer dispatch. */
end_comment

begin_define
define|#
directive|define
name|NETISR_DISPATCH_HYBRID
value|2
end_define

begin_comment
comment|/* Allow hybrid dispatch. */
end_comment

begin_define
define|#
directive|define
name|NETISR_DISPATCH_DIRECT
value|3
end_define

begin_comment
comment|/* Always direct dispatch. */
end_comment

begin_comment
comment|/*  * Monitoring data structures, exported by sysctl(2).  *  * Three sysctls are defined.  First, a per-protocol structure exported by  * net.isr.proto.  */
end_comment

begin_define
define|#
directive|define
name|NETISR_NAMEMAXLEN
value|32
end_define

begin_struct
struct|struct
name|sysctl_netisr_proto
block|{
name|u_int
name|snp_version
decl_stmt|;
comment|/* Length of struct. */
name|char
name|snp_name
index|[
name|NETISR_NAMEMAXLEN
index|]
decl_stmt|;
comment|/* nh_name */
name|u_int
name|snp_proto
decl_stmt|;
comment|/* nh_proto */
name|u_int
name|snp_qlimit
decl_stmt|;
comment|/* nh_qlimit */
name|u_int
name|snp_policy
decl_stmt|;
comment|/* nh_policy */
name|u_int
name|snp_flags
decl_stmt|;
comment|/* Various flags. */
name|u_int
name|snp_dispatch
decl_stmt|;
comment|/* Dispatch policy. */
name|u_int
name|_snp_ispare
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for sysctl_netisr_proto.snp_flags.  */
end_comment

begin_define
define|#
directive|define
name|NETISR_SNP_FLAGS_M2FLOW
value|0x00000001
end_define

begin_comment
comment|/* nh_m2flow */
end_comment

begin_define
define|#
directive|define
name|NETISR_SNP_FLAGS_M2CPUID
value|0x00000002
end_define

begin_comment
comment|/* nh_m2cpuid */
end_comment

begin_define
define|#
directive|define
name|NETISR_SNP_FLAGS_DRAINEDCPU
value|0x00000004
end_define

begin_comment
comment|/* nh_drainedcpu */
end_comment

begin_comment
comment|/*  * Next, a structure per-workstream, with per-protocol data, exported as  * net.isr.workstream.  */
end_comment

begin_struct
struct|struct
name|sysctl_netisr_workstream
block|{
name|u_int
name|snws_version
decl_stmt|;
comment|/* Length of struct. */
name|u_int
name|snws_flags
decl_stmt|;
comment|/* Various flags. */
name|u_int
name|snws_wsid
decl_stmt|;
comment|/* Workstream ID. */
name|u_int
name|snws_cpu
decl_stmt|;
comment|/* nws_cpu */
name|u_int
name|_snws_ispare
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for sysctl_netisr_workstream.snws_flags  */
end_comment

begin_define
define|#
directive|define
name|NETISR_SNWS_FLAGS_INTR
value|0x00000001
end_define

begin_comment
comment|/* nws_intr_event */
end_comment

begin_comment
comment|/*  * Finally, a per-workstream-per-protocol structure, exported as  * net.isr.work.  */
end_comment

begin_struct
struct|struct
name|sysctl_netisr_work
block|{
name|u_int
name|snw_version
decl_stmt|;
comment|/* Length of struct. */
name|u_int
name|snw_wsid
decl_stmt|;
comment|/* Workstream ID. */
name|u_int
name|snw_proto
decl_stmt|;
comment|/* Protocol number. */
name|u_int
name|snw_len
decl_stmt|;
comment|/* nw_len */
name|u_int
name|snw_watermark
decl_stmt|;
comment|/* nw_watermark */
name|u_int
name|_snw_ispare
index|[
literal|3
index|]
decl_stmt|;
name|uint64_t
name|snw_dispatched
decl_stmt|;
comment|/* nw_dispatched */
name|uint64_t
name|snw_hybrid_dispatched
decl_stmt|;
comment|/* nw_hybrid_dispatched */
name|uint64_t
name|snw_qdrops
decl_stmt|;
comment|/* nw_qdrops */
name|uint64_t
name|snw_queued
decl_stmt|;
comment|/* nw_queued */
name|uint64_t
name|snw_handled
decl_stmt|;
comment|/* nw_handled */
name|uint64_t
name|_snw_llspare
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*-  * Protocols express ordering constraints and affinity preferences by  * implementing one or neither of nh_m2flow and nh_m2cpuid, which are used by  * netisr to determine which per-CPU workstream to assign mbufs to.  *  * The following policies may be used by protocols:  *  * NETISR_POLICY_SOURCE - netisr should maintain source ordering without  *                        advice from the protocol.  netisr will ignore any  *                        flow IDs present on the mbuf for the purposes of  *                        work placement.  *  * NETISR_POLICY_FLOW - netisr should maintain flow ordering as defined by  *                      the mbuf header flow ID field.  If the protocol  *                      implements nh_m2flow, then netisr will query the  *                      protocol in the event that the mbuf doesn't have a  *                      flow ID, falling back on source ordering.  *  * NETISR_POLICY_CPU - netisr will delegate all work placement decisions to  *                     the protocol, querying nh_m2cpuid for each packet.  *  * Protocols might make decisions about work placement based on an existing  * calculated flow ID on the mbuf, such as one provided in hardware, the  * receive interface pointed to by the mbuf (if any), the optional source  * identifier passed at some dispatch points, or even parse packet headers to  * calculate a flow.  Both protocol handlers may return a new mbuf pointer  * for the chain, or NULL if the packet proves invalid or m_pullup() fails.  *  * XXXRW: If we eventually support dynamic reconfiguration, there should be  * protocol handlers to notify them of CPU configuration changes so that they  * can rebalance work.  */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|netisr_handler_t
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mbuf
modifier|*
name|netisr_m2cpuid_t
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uintptr_t
name|source
parameter_list|,
name|u_int
modifier|*
name|cpuid
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mbuf
modifier|*
name|netisr_m2flow_t
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uintptr_t
name|source
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|netisr_drainedcpu_t
parameter_list|(
name|u_int
name|cpuid
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|NETISR_CPUID_NONE
value|((u_int)-1)
end_define

begin_comment
comment|/* No affinity returned. */
end_comment

begin_comment
comment|/*  * Data structure describing a protocol handler.  */
end_comment

begin_struct
struct|struct
name|netisr_handler
block|{
specifier|const
name|char
modifier|*
name|nh_name
decl_stmt|;
comment|/* Character string protocol name. */
name|netisr_handler_t
modifier|*
name|nh_handler
decl_stmt|;
comment|/* Protocol handler. */
name|netisr_m2flow_t
modifier|*
name|nh_m2flow
decl_stmt|;
comment|/* Query flow for untagged packet. */
name|netisr_m2cpuid_t
modifier|*
name|nh_m2cpuid
decl_stmt|;
comment|/* Query CPU to process mbuf on. */
name|netisr_drainedcpu_t
modifier|*
name|nh_drainedcpu
decl_stmt|;
comment|/* Callback when drained a queue. */
name|u_int
name|nh_proto
decl_stmt|;
comment|/* Integer protocol ID. */
name|u_int
name|nh_qlimit
decl_stmt|;
comment|/* Maximum per-CPU queue depth. */
name|u_int
name|nh_policy
decl_stmt|;
comment|/* Work placement policy. */
name|u_int
name|nh_dispatch
decl_stmt|;
comment|/* Dispatch policy. */
name|u_int
name|nh_ispare
index|[
literal|4
index|]
decl_stmt|;
comment|/* For future use. */
name|void
modifier|*
name|nh_pspare
index|[
literal|4
index|]
decl_stmt|;
comment|/* For future use. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Register, unregister, and other netisr handler management functions.  */
end_comment

begin_function_decl
name|void
name|netisr_clearqdrops
parameter_list|(
specifier|const
name|struct
name|netisr_handler
modifier|*
name|nhp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netisr_getqdrops
parameter_list|(
specifier|const
name|struct
name|netisr_handler
modifier|*
name|nhp
parameter_list|,
name|u_int64_t
modifier|*
name|qdropsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netisr_getqlimit
parameter_list|(
specifier|const
name|struct
name|netisr_handler
modifier|*
name|nhp
parameter_list|,
name|u_int
modifier|*
name|qlimitp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netisr_register
parameter_list|(
specifier|const
name|struct
name|netisr_handler
modifier|*
name|nhp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netisr_setqlimit
parameter_list|(
specifier|const
name|struct
name|netisr_handler
modifier|*
name|nhp
parameter_list|,
name|u_int
name|qlimit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netisr_unregister
parameter_list|(
specifier|const
name|struct
name|netisr_handler
modifier|*
name|nhp
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_function_decl
name|void
name|netisr_register_vnet
parameter_list|(
specifier|const
name|struct
name|netisr_handler
modifier|*
name|nhp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netisr_unregister_vnet
parameter_list|(
specifier|const
name|struct
name|netisr_handler
modifier|*
name|nhp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Process a packet destined for a protocol, and attempt direct dispatch.  * Supplemental source ordering information can be passed using the _src  * variant.  */
end_comment

begin_function_decl
name|int
name|netisr_dispatch
parameter_list|(
name|u_int
name|proto
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netisr_dispatch_src
parameter_list|(
name|u_int
name|proto
parameter_list|,
name|uintptr_t
name|source
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netisr_queue
parameter_list|(
name|u_int
name|proto
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netisr_queue_src
parameter_list|(
name|u_int
name|proto
parameter_list|,
name|uintptr_t
name|source
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Provide a default implementation of "map an ID to a CPU ID".  */
end_comment

begin_function_decl
name|u_int
name|netisr_default_flow2cpu
parameter_list|(
name|u_int
name|flowid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Utility routines to return the number of CPUs participting in netisr, and  * to return a mapping from a number to a CPU ID that can be used with the  * scheduler.  */
end_comment

begin_function_decl
name|u_int
name|netisr_get_cpucount
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|netisr_get_cpuid
parameter_list|(
name|u_int
name|cpunumber
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Interfaces between DEVICE_POLLING and netisr.  */
end_comment

begin_function_decl
name|void
name|netisr_sched_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netisr_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netisr_pollmore
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_NETISR_H_ */
end_comment

end_unit

