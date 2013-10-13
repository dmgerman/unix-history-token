begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2010 Andreas Tobler  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PSERIES_PHYP_HVCALL_H_
end_ifndef

begin_define
define|#
directive|define
name|_PSERIES_PHYP_HVCALL_H_
end_define

begin_comment
comment|/* Information taken from: Power.org PAPR, Version 2.4 (December 7, 2009). */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Return codes. */
end_comment

begin_define
define|#
directive|define
name|H_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|H_BUSY
value|1
end_define

begin_comment
comment|/* Hardware Busy -- Retry Later. */
end_comment

begin_define
define|#
directive|define
name|H_CLOSED
value|2
end_define

begin_comment
comment|/* Virtual I/O connection is closed. */
end_comment

begin_define
define|#
directive|define
name|H_NOT_AVAILABLE
value|3
end_define

begin_define
define|#
directive|define
name|H_CONSTRAINED
value|4
end_define

begin_comment
comment|/* The request called for resources in excess of 			      the maximum allowed. The resultant allocation 			      was constrained to maximum allowed. */
end_comment

begin_define
define|#
directive|define
name|H_PARTIAL
value|5
end_define

begin_comment
comment|/* The request completed only partially successful. 			      Parameters were valid but some specific hcall 			      function condition prevented fully completing the 			      architected function, see the specific hcall 			      definition for possible reasons. */
end_comment

begin_define
define|#
directive|define
name|H_IN_PROGRESS
value|14
end_define

begin_define
define|#
directive|define
name|H_PAGE_REGISTERED
value|15
end_define

begin_define
define|#
directive|define
name|H_PARTIAL_STORE
value|16
end_define

begin_define
define|#
directive|define
name|H_PENDING
value|17
end_define

begin_define
define|#
directive|define
name|H_CONTINUE
value|18
end_define

begin_define
define|#
directive|define
name|H_LONG_BUSY_ORDER_1_MS
value|9900
end_define

begin_comment
comment|/* This return code is identical to 					  H_BUSY, but with the added bonus of a 					  hint to the partition OS. If the 					  partition OS can delay for 1 					  millisecond, the hcall will likely 					  succeed on a new hcall with no further 					  busy return codes. If the partition OS 					  cannot handle a delay, they are 					  certainly free to immediately turn 					  around and try again. */
end_comment

begin_define
define|#
directive|define
name|H_LONG_BUSY_ORDER_10_MS
value|9901
end_define

begin_comment
comment|/* Similar to H_LONG_BUSY_ORDER_1_MS, but 					  the hint is 10mSec wait this time. */
end_comment

begin_define
define|#
directive|define
name|H_LONG_BUSY_ORDER_100_MS
value|9902
end_define

begin_comment
comment|/* Similar to H_LONG_BUSY_ORDER_1_MS, but 					  the hint is 100mSec wait this time. */
end_comment

begin_define
define|#
directive|define
name|H_LONG_BUSY_ORDER_1_S
value|9903
end_define

begin_comment
comment|/* Similar to H_LONG_BUSY_ORDER_1_MS, but 					  the hint is 1Sec wait this time. */
end_comment

begin_define
define|#
directive|define
name|H_LONG_BUSY_ORDER_10_S
value|9904
end_define

begin_comment
comment|/* Similar to H_LONG_BUSY_ORDER_1_MS, but 					  the hint is 10Sec wait this time. */
end_comment

begin_define
define|#
directive|define
name|H_LONG_BUSY_ORDER_100_S
value|9905
end_define

begin_comment
comment|/* Similar to H_LONG_BUSY_ORDER_1_MS, but 					  the hint is 100Sec wait this time. */
end_comment

begin_define
define|#
directive|define
name|H_HARDWARE
value|-1
end_define

begin_comment
comment|/* Error. */
end_comment

begin_define
define|#
directive|define
name|H_FUNCTION
value|-2
end_define

begin_comment
comment|/* Not supported. */
end_comment

begin_define
define|#
directive|define
name|H_PRIVILEGE
value|-3
end_define

begin_comment
comment|/* Caller not in privileged mode. */
end_comment

begin_define
define|#
directive|define
name|H_PARAMETER
value|-4
end_define

begin_comment
comment|/* Outside valid range for partition or conflicting. */
end_comment

begin_define
define|#
directive|define
name|H_BAD_MODE
value|-5
end_define

begin_comment
comment|/* Illegal MSR value. */
end_comment

begin_define
define|#
directive|define
name|H_PTEG_FULL
value|-6
end_define

begin_comment
comment|/* The requested pteg was full. */
end_comment

begin_define
define|#
directive|define
name|H_NOT_FOUND
value|-7
end_define

begin_comment
comment|/* The requested entitiy was not found. */
end_comment

begin_define
define|#
directive|define
name|H_RESERVED_DABR
value|-8
end_define

begin_comment
comment|/* The requested address is reserved by the 			       hypervisor on this processor. */
end_comment

begin_define
define|#
directive|define
name|H_NOMEM
value|-9
end_define

begin_define
define|#
directive|define
name|H_AUTHORITY
value|-10
end_define

begin_comment
comment|/* The caller did not have authority to perform the 			    function. */
end_comment

begin_define
define|#
directive|define
name|H_PERMISSION
value|-11
end_define

begin_comment
comment|/* The mapping specified by the request does not 			     allow for the requested transfer. */
end_comment

begin_define
define|#
directive|define
name|H_DROPPED
value|-12
end_define

begin_comment
comment|/* One or more packets could not be delivered to 			    their requested destinations. */
end_comment

begin_define
define|#
directive|define
name|H_S_PARM
value|-13
end_define

begin_comment
comment|/* The source parameter is illegal. */
end_comment

begin_define
define|#
directive|define
name|H_D_PARM
value|-14
end_define

begin_comment
comment|/* The destination parameter is illegal. */
end_comment

begin_define
define|#
directive|define
name|H_R_PARM
value|-15
end_define

begin_comment
comment|/* The remote TCE mapping is illegal. */
end_comment

begin_define
define|#
directive|define
name|H_RESOURCE
value|-16
end_define

begin_comment
comment|/* One or more required resources are in use. */
end_comment

begin_define
define|#
directive|define
name|H_ADAPTER_PARM
value|-17
end_define

begin_comment
comment|/* Invalid adapter. */
end_comment

begin_define
define|#
directive|define
name|H_RH_PARM
value|-18
end_define

begin_comment
comment|/* Resource not valid or logical partition 			   conflicting. */
end_comment

begin_define
define|#
directive|define
name|H_RCQ_PARM
value|-19
end_define

begin_comment
comment|/* RCQ not valid or logical partition conflicting. */
end_comment

begin_define
define|#
directive|define
name|H_SCQ_PARM
value|-20
end_define

begin_comment
comment|/* SCQ not valid or logical partition conflicting. */
end_comment

begin_define
define|#
directive|define
name|H_EQ_PARM
value|-21
end_define

begin_comment
comment|/* EQ not valid or logical partition conflicting. */
end_comment

begin_define
define|#
directive|define
name|H_RT_PARM
value|-22
end_define

begin_comment
comment|/* Invalid resource type. */
end_comment

begin_define
define|#
directive|define
name|H_ST_PARM
value|-23
end_define

begin_comment
comment|/* Invalid service type. */
end_comment

begin_define
define|#
directive|define
name|H_SIGT_PARM
value|-24
end_define

begin_comment
comment|/* Invalid signalling type. */
end_comment

begin_define
define|#
directive|define
name|H_TOKEN_PARM
value|-25
end_define

begin_comment
comment|/* Invalid token. */
end_comment

begin_define
define|#
directive|define
name|H_MLENGTH_PARM
value|-27
end_define

begin_comment
comment|/* Invalid memory length. */
end_comment

begin_define
define|#
directive|define
name|H_MEM_PARM
value|-28
end_define

begin_comment
comment|/* Invalid memory I/O virtual address. */
end_comment

begin_define
define|#
directive|define
name|H_MEM_ACCESS_PARM
value|-29
end_define

begin_comment
comment|/* Invalid memory access control. */
end_comment

begin_define
define|#
directive|define
name|H_ATTR_PARM
value|-30
end_define

begin_comment
comment|/* Invalid attribute value. */
end_comment

begin_define
define|#
directive|define
name|H_PORT_PARM
value|-31
end_define

begin_comment
comment|/* Invalid port number. */
end_comment

begin_define
define|#
directive|define
name|H_MCG_PARM
value|-32
end_define

begin_comment
comment|/* Invalid multicast group. */
end_comment

begin_define
define|#
directive|define
name|H_VL_PARM
value|-33
end_define

begin_comment
comment|/* Invalid virtual lane. */
end_comment

begin_define
define|#
directive|define
name|H_TSIZE_PARM
value|-34
end_define

begin_comment
comment|/* Invalid trace size. */
end_comment

begin_define
define|#
directive|define
name|H_TRACE_PARM
value|-35
end_define

begin_comment
comment|/* Invalid trace buffer. */
end_comment

begin_define
define|#
directive|define
name|H_MASK_PARM
value|-37
end_define

begin_comment
comment|/* Invalid mask value. */
end_comment

begin_define
define|#
directive|define
name|H_MCG_FULL
value|-38
end_define

begin_comment
comment|/* Multicast attachments exceeded. */
end_comment

begin_define
define|#
directive|define
name|H_ALIAS_EXIST
value|-39
end_define

begin_comment
comment|/* Alias QP already defined. */
end_comment

begin_define
define|#
directive|define
name|H_P_COUNTER
value|-40
end_define

begin_comment
comment|/* Invalid counter specification. */
end_comment

begin_define
define|#
directive|define
name|H_TABLE_FULL
value|-41
end_define

begin_comment
comment|/* Resource page table full. */
end_comment

begin_define
define|#
directive|define
name|H_ALT_TABLE
value|-42
end_define

begin_comment
comment|/* Alternate table already exists / alternate page 			    table not available. */
end_comment

begin_define
define|#
directive|define
name|H_MR_CONDITION
value|-43
end_define

begin_comment
comment|/* Invalid memory region condition. */
end_comment

begin_define
define|#
directive|define
name|H_NOT_ENOUGH_RESOURCES
value|-44
end_define

begin_comment
comment|/* Insufficient resources. */
end_comment

begin_define
define|#
directive|define
name|H_R_STATE
value|-45
end_define

begin_comment
comment|/* Invalid resource state condition or sequencing 			  error. */
end_comment

begin_define
define|#
directive|define
name|H_RESCINDED
value|-46
end_define

begin_define
define|#
directive|define
name|H_ABORTED
value|-54
end_define

begin_define
define|#
directive|define
name|H_P2
value|-55
end_define

begin_define
define|#
directive|define
name|H_P3
value|-56
end_define

begin_define
define|#
directive|define
name|H_P4
value|-57
end_define

begin_define
define|#
directive|define
name|H_P5
value|-58
end_define

begin_define
define|#
directive|define
name|H_P6
value|-59
end_define

begin_define
define|#
directive|define
name|H_P7
value|-60
end_define

begin_define
define|#
directive|define
name|H_P8
value|-61
end_define

begin_define
define|#
directive|define
name|H_P9
value|-62
end_define

begin_define
define|#
directive|define
name|H_NOOP
value|-63
end_define

begin_define
define|#
directive|define
name|H_TOO_BIG
value|-64
end_define

begin_define
define|#
directive|define
name|H_UNSUPPORTED
value|-67
end_define

begin_comment
comment|/* Parameter value outside of the range supported 			      by this implementation. */
end_comment

begin_comment
comment|/* Flags. */
end_comment

begin_comment
comment|/* Table 168. Page Frame Table Access flags field definition. */
end_comment

begin_define
define|#
directive|define
name|H_EXACT
value|(1UL<<(63-24))
end_define

begin_define
define|#
directive|define
name|H_R_XLATE
value|(1UL<<(63-25))
end_define

begin_define
define|#
directive|define
name|H_READ_4
value|(1UL<<(63-26))
end_define

begin_comment
comment|/* Table 178. CMO Page Usage State flags Definition. */
end_comment

begin_define
define|#
directive|define
name|H_PAGE_STATE_CHANGE
value|(1UL<<(63-28))
end_define

begin_define
define|#
directive|define
name|H_PAGE_UNUSED
value|((1UL<<(63-29)) | (1UL<<(63-30)))
end_define

begin_define
define|#
directive|define
name|H_PAGE_SET_UNUSED
value|(H_PAGE_STATE_CHANGE | H_PAGE_UNUSED)
end_define

begin_define
define|#
directive|define
name|H_PAGE_SET_LOANED
value|(H_PAGE_SET_UNUSED | (1UL<<(63-31)))
end_define

begin_define
define|#
directive|define
name|H_PAGE_SET_ACTIVE
value|H_PAGE_STATE_CHANGE
end_define

begin_comment
comment|/* Table 168. Page Frame Table Access flags field definition. */
end_comment

begin_define
define|#
directive|define
name|H_AVPN
value|(1UL<<(63-32))
end_define

begin_define
define|#
directive|define
name|H_ANDCOND
value|(1UL<<(63-33))
end_define

begin_define
define|#
directive|define
name|H_ICACHE_INVALIDATE
value|(1UL<<(63-40))
end_define

begin_define
define|#
directive|define
name|H_ICACHE_SYNCHRONIZE
value|(1UL<<(63-41))
end_define

begin_define
define|#
directive|define
name|H_ZERO_PAGE
value|(1UL<<(63-48))
end_define

begin_define
define|#
directive|define
name|H_COPY_PAGE
value|(1UL<<(63-49))
end_define

begin_define
define|#
directive|define
name|H_N
value|(1UL<<(63-61))
end_define

begin_define
define|#
directive|define
name|H_PP1
value|(1UL<<(63-62))
end_define

begin_define
define|#
directive|define
name|H_PP2
value|(1UL<<(63-63))
end_define

begin_comment
comment|/* pSeries hypervisor opcodes. */
end_comment

begin_define
define|#
directive|define
name|H_REMOVE
value|0x04
end_define

begin_define
define|#
directive|define
name|H_ENTER
value|0x08
end_define

begin_define
define|#
directive|define
name|H_READ
value|0x0c
end_define

begin_define
define|#
directive|define
name|H_CLEAR_MOD
value|0x10
end_define

begin_define
define|#
directive|define
name|H_CLEAR_REF
value|0x14
end_define

begin_define
define|#
directive|define
name|H_PROTECT
value|0x18
end_define

begin_define
define|#
directive|define
name|H_GET_TCE
value|0x1c
end_define

begin_define
define|#
directive|define
name|H_PUT_TCE
value|0x20
end_define

begin_define
define|#
directive|define
name|H_SET_SPRG0
value|0x24
end_define

begin_define
define|#
directive|define
name|H_SET_DABR
value|0x28
end_define

begin_define
define|#
directive|define
name|H_PAGE_INIT
value|0x2c
end_define

begin_define
define|#
directive|define
name|H_SET_ASR
value|0x30
end_define

begin_define
define|#
directive|define
name|H_ASR_ON
value|0x34
end_define

begin_define
define|#
directive|define
name|H_ASR_OFF
value|0x38
end_define

begin_define
define|#
directive|define
name|H_LOGICAL_CI_LOAD
value|0x3c
end_define

begin_define
define|#
directive|define
name|H_LOGICAL_CI_STORE
value|0x40
end_define

begin_define
define|#
directive|define
name|H_LOGICAL_CACHE_LOAD
value|0x44
end_define

begin_define
define|#
directive|define
name|H_LOGICAL_CACHE_STORE
value|0x48
end_define

begin_define
define|#
directive|define
name|H_LOGICAL_ICBI
value|0x4c
end_define

begin_define
define|#
directive|define
name|H_LOGICAL_DCBF
value|0x50
end_define

begin_define
define|#
directive|define
name|H_GET_TERM_CHAR
value|0x54
end_define

begin_define
define|#
directive|define
name|H_PUT_TERM_CHAR
value|0x58
end_define

begin_define
define|#
directive|define
name|H_REAL_TO_LOGICAL
value|0x5c
end_define

begin_define
define|#
directive|define
name|H_HYPERVISOR_DATA
value|0x60
end_define

begin_define
define|#
directive|define
name|H_EOI
value|0x64
end_define

begin_define
define|#
directive|define
name|H_CPPR
value|0x68
end_define

begin_define
define|#
directive|define
name|H_IPI
value|0x6c
end_define

begin_define
define|#
directive|define
name|H_IPOLL
value|0x70
end_define

begin_define
define|#
directive|define
name|H_XIRR
value|0x74
end_define

begin_define
define|#
directive|define
name|H_MIGRATE_DMA
value|0x78
end_define

begin_define
define|#
directive|define
name|H_PERFMON
value|0x7c
end_define

begin_define
define|#
directive|define
name|H_REGISTER_VPA
value|0xdc
end_define

begin_define
define|#
directive|define
name|H_CEDE
value|0xe0
end_define

begin_define
define|#
directive|define
name|H_CONFER
value|0xe4
end_define

begin_define
define|#
directive|define
name|H_PROD
value|0xe8
end_define

begin_define
define|#
directive|define
name|H_GET_PPP
value|0xec
end_define

begin_define
define|#
directive|define
name|H_SET_PPP
value|0xf0
end_define

begin_define
define|#
directive|define
name|H_PURR
value|0xf4
end_define

begin_define
define|#
directive|define
name|H_PIC
value|0xf8
end_define

begin_define
define|#
directive|define
name|H_REG_CRQ
value|0xfc
end_define

begin_define
define|#
directive|define
name|H_FREE_CRQ
value|0x100
end_define

begin_define
define|#
directive|define
name|H_VIO_SIGNAL
value|0x104
end_define

begin_define
define|#
directive|define
name|H_SEND_CRQ
value|0x108
end_define

begin_define
define|#
directive|define
name|H_PUT_RTCE
value|0x10c
end_define

begin_define
define|#
directive|define
name|H_COPY_RDMA
value|0x110
end_define

begin_define
define|#
directive|define
name|H_REGISTER_LOGICAL_LAN
value|0x114
end_define

begin_define
define|#
directive|define
name|H_FREE_LOGICAL_LAN
value|0x118
end_define

begin_define
define|#
directive|define
name|H_ADD_LOGICAL_LAN_BUFFER
value|0x11c
end_define

begin_define
define|#
directive|define
name|H_SEND_LOGICAL_LAN
value|0x120
end_define

begin_define
define|#
directive|define
name|H_BULK_REMOVE
value|0x124
end_define

begin_define
define|#
directive|define
name|H_WRITE_RDMA
value|0x128
end_define

begin_define
define|#
directive|define
name|H_READ_RDMA
value|0x12c
end_define

begin_define
define|#
directive|define
name|H_MULTICAST_CTRL
value|0x130
end_define

begin_define
define|#
directive|define
name|H_SET_XDABR
value|0x134
end_define

begin_define
define|#
directive|define
name|H_STUFF_TCE
value|0x138
end_define

begin_define
define|#
directive|define
name|H_PUT_TCE_INDIRECT
value|0x13c
end_define

begin_define
define|#
directive|define
name|H_PUT_RTCE_INDIRECT
value|0x140
end_define

begin_define
define|#
directive|define
name|H_CHANGE_LOGICAL_LAN_MAC
value|0x14c
end_define

begin_define
define|#
directive|define
name|H_VTERM_PARTNER_INFO
value|0x150
end_define

begin_define
define|#
directive|define
name|H_REGISTER_VTERM
value|0x154
end_define

begin_define
define|#
directive|define
name|H_FREE_VTERM
value|0x158
end_define

begin_comment
comment|/* Reserved .... #define H_RESET_EVENTS          0x15c #define H_ALLOC_RESOURCE        0x160 #define H_FREE_RESOURCE         0x164 #define H_MODIFY_QP             0x168 #define H_QUERY_QP              0x16c #define H_REREGISTER_PMR        0x170 #define H_REGISTER_SMR          0x174 #define H_QUERY_MR              0x178 #define H_QUERY_MW              0x17c #define H_QUERY_HCA             0x180 #define H_QUERY_PORT            0x184 #define H_MODIFY_PORT           0x188 #define H_DEFINE_AQP1           0x18c #define H_GET_TRACE_BUFFER      0x190 #define H_DEFINE_AQP0           0x194 #define H_RESIZE_MR             0x198 #define H_ATTACH_MCQP           0x19c #define H_DETACH_MCQP           0x1a0 #define H_CREATE_RPT            0x1a4 #define H_REMOVE_RPT            0x1a8 #define H_REGISTER_RPAGES       0x1ac #define H_DISABLE_AND_GETC      0x1b0 #define H_ERROR_DATA            0x1b4 #define H_GET_HCA_INFO          0x1b8 #define H_GET_PERF_COUNT        0x1bc #define H_MANAGE_TRACE          0x1c0 .... */
end_comment

begin_define
define|#
directive|define
name|H_FREE_LOGICAL_LAN_BUFFER
value|0x1d4
end_define

begin_define
define|#
directive|define
name|H_POLL_PENDING
value|0x1d8
end_define

begin_comment
comment|/* Reserved .... #define H_QUERY_INT_STATE       0x1e4 .... */
end_comment

begin_define
define|#
directive|define
name|H_LIOBN_ATTRIBUTES
value|0x240
end_define

begin_define
define|#
directive|define
name|H_ILLAN_ATTRIBUTES
value|0x244
end_define

begin_define
define|#
directive|define
name|H_REMOVE_RTCE
value|0x24c
end_define

begin_comment
comment|/* Reserved ... #define H_MODIFY_HEA_QP		0x250 #define H_QUERY_HEA_QP		0x254 #define H_QUERY_HEA		0x258 #define H_QUERY_HEA_PORT	0x25c #define H_MODIFY_HEA_PORT	0x260 #define H_REG_BCMC		0x264 #define H_DEREG_BCMC		0x268 #define H_REGISTER_HEA_RPAGES	0x26c #define H_DISABLE_AND_GET_HEA	0x270 #define H_GET_HEA_INFO		0x274 #define H_ALLOC_HEA_RESOURCE	0x278 #define H_ADD_CONN		0x284 #define H_DEL_CONN		0x288 ... */
end_comment

begin_define
define|#
directive|define
name|H_JOIN
value|0x298
end_define

begin_define
define|#
directive|define
name|H_DONOR_OPERATION
value|0x29c
end_define

begin_define
define|#
directive|define
name|H_VASI_SIGNAL
value|0x2a0
end_define

begin_define
define|#
directive|define
name|H_VASI_STATE
value|0x2a4
end_define

begin_define
define|#
directive|define
name|H_VIOCTL
value|0x2a8
end_define

begin_define
define|#
directive|define
name|H_VRMASD
value|0x2ac
end_define

begin_define
define|#
directive|define
name|H_ENABLE_CRQ
value|0x2b0
end_define

begin_comment
comment|/* Reserved ... #define H_GET_EM_PARMS		0x2b8 ... */
end_comment

begin_define
define|#
directive|define
name|H_VPM_STAT
value|0x2bc
end_define

begin_define
define|#
directive|define
name|H_SET_MPP
value|0x2d0
end_define

begin_define
define|#
directive|define
name|H_GET_MPP
value|0x2d4
end_define

begin_define
define|#
directive|define
name|MAX_HCALL_OPCODE
value|H_GET_MPP
end_define

begin_function_decl
name|int64_t
name|phyp_hcall
parameter_list|(
name|uint64_t
name|opcode
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64_t
name|phyp_pft_hcall
parameter_list|(
name|uint64_t
name|opcode
parameter_list|,
name|uint64_t
name|flags
parameter_list|,
name|uint64_t
name|pteidx
parameter_list|,
name|uint64_t
name|pte_hi
parameter_list|,
name|uint64_t
name|pte_lo
parameter_list|,
name|uint64_t
modifier|*
name|pteidx_out
parameter_list|,
name|uint64_t
modifier|*
name|ptelo_out
parameter_list|,
name|uint64_t
modifier|*
name|r6
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PSERIES_PHYP_HVCALL_H_ */
end_comment

end_unit

