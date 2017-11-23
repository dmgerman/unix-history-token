begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2008 Apple Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.   *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSM_AUDIT_DOMAIN_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSM_AUDIT_DOMAIN_H_
end_define

begin_comment
comment|/*  * BSM protocol domain constants - protocol domains defined in Solaris.  */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|BSM_PF_LOCAL
value|1
end_define

begin_define
define|#
directive|define
name|BSM_PF_INET
value|2
end_define

begin_define
define|#
directive|define
name|BSM_PF_IMPLINK
value|3
end_define

begin_define
define|#
directive|define
name|BSM_PF_PUP
value|4
end_define

begin_define
define|#
directive|define
name|BSM_PF_CHAOS
value|5
end_define

begin_define
define|#
directive|define
name|BSM_PF_NS
value|6
end_define

begin_define
define|#
directive|define
name|BSM_PF_NBS
value|7
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_ECMA
value|8
end_define

begin_define
define|#
directive|define
name|BSM_PF_DATAKIT
value|9
end_define

begin_define
define|#
directive|define
name|BSM_PF_CCITT
value|10
end_define

begin_define
define|#
directive|define
name|BSM_PF_SNA
value|11
end_define

begin_define
define|#
directive|define
name|BSM_PF_DECnet
value|12
end_define

begin_define
define|#
directive|define
name|BSM_PF_DLI
value|13
end_define

begin_define
define|#
directive|define
name|BSM_PF_LAT
value|14
end_define

begin_define
define|#
directive|define
name|BSM_PF_HYLINK
value|15
end_define

begin_define
define|#
directive|define
name|BSM_PF_APPLETALK
value|16
end_define

begin_define
define|#
directive|define
name|BSM_PF_NIT
value|17
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_802
value|18
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_OSI
value|19
end_define

begin_define
define|#
directive|define
name|BSM_PF_X25
value|20
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_OSINET
value|21
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_GOSIP
value|22
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_IPX
value|23
end_define

begin_define
define|#
directive|define
name|BSM_PF_ROUTE
value|24
end_define

begin_define
define|#
directive|define
name|BSM_PF_LINK
value|25
end_define

begin_define
define|#
directive|define
name|BSM_PF_INET6
value|26
end_define

begin_define
define|#
directive|define
name|BSM_PF_KEY
value|27
end_define

begin_define
define|#
directive|define
name|BSM_PF_NCA
value|28
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_POLICY
value|29
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_INET_OFFLOAD
value|30
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_comment
comment|/*  * BSM protocol domain constants - protocol domains not defined in Solaris.  */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_NETBIOS
value|500
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_ISO
value|501
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_XTP
value|502
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_COIP
value|503
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_CNT
value|504
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_RTIP
value|505
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_SIP
value|506
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_PIP
value|507
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_ISDN
value|508
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_E164
value|509
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_NATM
value|510
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_ATM
value|511
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_NETGRAPH
value|512
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_SLOW
value|513
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_SCLUSTER
value|514
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_ARP
value|515
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_BLUETOOTH
value|516
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_comment
comment|/* 517: unallocated. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_AX25
value|518
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_ROSE
value|519
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_NETBEUI
value|520
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_SECURITY
value|521
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_PACKET
value|522
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_ASH
value|523
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_ECONET
value|524
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_ATMSVC
value|525
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_IRDA
value|526
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_PPPOX
value|527
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_WANPIPE
value|528
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_LLC
value|529
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_CAN
value|530
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_TIPC
value|531
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_IUCV
value|532
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_RXRPC
value|533
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_PHONET
value|534
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_comment
comment|/*  * Used when there is no mapping from a local to BSM protocol domain.  */
end_comment

begin_define
define|#
directive|define
name|BSM_PF_UNKNOWN
value|700
end_define

begin_comment
comment|/* OpenBSM-specific. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BSM_AUDIT_DOMAIN_H_ */
end_comment

end_unit

