begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: altq_priq.h,v 1.5 2003/07/10 12:07:48 kjc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000-2003  *	Sony Computer Science Laboratories Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY SONY CSL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL SONY CSL OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_PRIQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_PRIQ_H_
end_define

begin_include
include|#
directive|include
file|<altq/altq.h>
end_include

begin_include
include|#
directive|include
file|<altq/altq_classq.h>
end_include

begin_include
include|#
directive|include
file|<altq/altq_red.h>
end_include

begin_include
include|#
directive|include
file|<altq/altq_rio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
define|#
directive|define
name|PRIQ_MAXPRI
value|16
comment|/* upper limit of the number of priorities */
define|#
directive|define
name|PRIQ_MAXQID
value|256
comment|/* upper limit of queues */
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
struct|struct
name|priq_interface
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* interface name (e.g., fxp0) */
name|u_long
name|arg
decl_stmt|;
comment|/* request-specific argument */
block|}
struct|;
struct|struct
name|priq_add_class
block|{
name|struct
name|priq_interface
name|iface
decl_stmt|;
name|int
name|pri
decl_stmt|;
comment|/* priority (0 is the lowest) */
name|int
name|qlimit
decl_stmt|;
comment|/* queue size limit */
name|int
name|flags
decl_stmt|;
comment|/* misc flags (see below) */
name|u_int32_t
name|class_handle
decl_stmt|;
comment|/* return value */
block|}
struct|;
endif|#
directive|endif
comment|/* ALTQ3_COMPAT */
comment|/* priq class flags */
define|#
directive|define
name|PRCF_RED
value|0x0001
comment|/* use RED */
define|#
directive|define
name|PRCF_ECN
value|0x0002
comment|/* use RED/ECN */
define|#
directive|define
name|PRCF_RIO
value|0x0004
comment|/* use RIO */
define|#
directive|define
name|PRCF_CLEARDSCP
value|0x0010
comment|/* clear diffserv codepoint */
define|#
directive|define
name|PRCF_DEFAULTCLASS
value|0x1000
comment|/* default class */
comment|/* special class handles */
define|#
directive|define
name|PRIQ_NULLCLASS_HANDLE
value|0
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
struct|struct
name|priq_delete_class
block|{
name|struct
name|priq_interface
name|iface
decl_stmt|;
name|u_int32_t
name|class_handle
decl_stmt|;
block|}
struct|;
struct|struct
name|priq_modify_class
block|{
name|struct
name|priq_interface
name|iface
decl_stmt|;
name|u_int32_t
name|class_handle
decl_stmt|;
name|int
name|pri
decl_stmt|;
name|int
name|qlimit
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
struct|struct
name|priq_add_filter
block|{
name|struct
name|priq_interface
name|iface
decl_stmt|;
name|u_int32_t
name|class_handle
decl_stmt|;
name|struct
name|flow_filter
name|filter
decl_stmt|;
name|u_long
name|filter_handle
decl_stmt|;
comment|/* return value */
block|}
struct|;
struct|struct
name|priq_delete_filter
block|{
name|struct
name|priq_interface
name|iface
decl_stmt|;
name|u_long
name|filter_handle
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
comment|/* ALTQ3_COMPAT */
struct|struct
name|priq_classstats
block|{
name|u_int32_t
name|class_handle
decl_stmt|;
name|u_int
name|qlength
decl_stmt|;
name|u_int
name|qlimit
decl_stmt|;
name|u_int
name|period
decl_stmt|;
name|struct
name|pktcntr
name|xmitcnt
decl_stmt|;
comment|/* transmitted packet counter */
name|struct
name|pktcntr
name|dropcnt
decl_stmt|;
comment|/* dropped packet counter */
comment|/* red and rio related info */
name|int
name|qtype
decl_stmt|;
name|struct
name|redstats
name|red
index|[
literal|3
index|]
decl_stmt|;
comment|/* rio has 3 red stats */
block|}
struct|;
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
struct|struct
name|priq_class_stats
block|{
name|struct
name|priq_interface
name|iface
decl_stmt|;
name|int
name|maxpri
decl_stmt|;
comment|/* in/out */
name|struct
name|priq_classstats
modifier|*
name|stats
decl_stmt|;
comment|/* pointer to stats array */
block|}
struct|;
define|#
directive|define
name|PRIQ_IF_ATTACH
value|_IOW('Q', 1, struct priq_interface)
define|#
directive|define
name|PRIQ_IF_DETACH
value|_IOW('Q', 2, struct priq_interface)
define|#
directive|define
name|PRIQ_ENABLE
value|_IOW('Q', 3, struct priq_interface)
define|#
directive|define
name|PRIQ_DISABLE
value|_IOW('Q', 4, struct priq_interface)
define|#
directive|define
name|PRIQ_CLEAR
value|_IOW('Q', 5, struct priq_interface)
define|#
directive|define
name|PRIQ_ADD_CLASS
value|_IOWR('Q', 7, struct priq_add_class)
define|#
directive|define
name|PRIQ_DEL_CLASS
value|_IOW('Q', 8, struct priq_delete_class)
define|#
directive|define
name|PRIQ_MOD_CLASS
value|_IOW('Q', 9, struct priq_modify_class)
define|#
directive|define
name|PRIQ_ADD_FILTER
value|_IOWR('Q', 10, struct priq_add_filter)
define|#
directive|define
name|PRIQ_DEL_FILTER
value|_IOW('Q', 11, struct priq_delete_filter)
define|#
directive|define
name|PRIQ_GETSTATS
value|_IOWR('Q', 12, struct priq_class_stats)
endif|#
directive|endif
comment|/* ALTQ3_COMPAT */
ifdef|#
directive|ifdef
name|_KERNEL
struct|struct
name|priq_class
block|{
name|u_int32_t
name|cl_handle
decl_stmt|;
comment|/* class handle */
name|class_queue_t
modifier|*
name|cl_q
decl_stmt|;
comment|/* class queue structure */
name|struct
name|red
modifier|*
name|cl_red
decl_stmt|;
comment|/* RED state */
name|int
name|cl_pri
decl_stmt|;
comment|/* priority */
name|int
name|cl_flags
decl_stmt|;
comment|/* class flags */
name|struct
name|priq_if
modifier|*
name|cl_pif
decl_stmt|;
comment|/* back pointer to pif */
name|struct
name|altq_pktattr
modifier|*
name|cl_pktattr
decl_stmt|;
comment|/* saved header used by ECN */
comment|/* statistics */
name|u_int
name|cl_period
decl_stmt|;
comment|/* backlog period */
name|struct
name|pktcntr
name|cl_xmitcnt
decl_stmt|;
comment|/* transmitted packet counter */
name|struct
name|pktcntr
name|cl_dropcnt
decl_stmt|;
comment|/* dropped packet counter */
block|}
struct|;
comment|/*  * priq interface state  */
struct|struct
name|priq_if
block|{
name|struct
name|priq_if
modifier|*
name|pif_next
decl_stmt|;
comment|/* interface state list */
name|struct
name|ifaltq
modifier|*
name|pif_ifq
decl_stmt|;
comment|/* backpointer to ifaltq */
name|u_int
name|pif_bandwidth
decl_stmt|;
comment|/* link bandwidth in bps */
name|int
name|pif_maxpri
decl_stmt|;
comment|/* max priority in use */
name|struct
name|priq_class
modifier|*
name|pif_default
decl_stmt|;
comment|/* default class */
name|struct
name|priq_class
modifier|*
name|pif_classes
index|[
name|PRIQ_MAXPRI
index|]
decl_stmt|;
comment|/* classes */
ifdef|#
directive|ifdef
name|ALTQ3_CLFIER_COMPAT
name|struct
name|acc_classifier
name|pif_classifier
decl_stmt|;
comment|/* classifier */
endif|#
directive|endif
block|}
struct|;
endif|#
directive|endif
comment|/* _KERNEL */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALTQ_ALTQ_PRIQ_H_ */
end_comment

end_unit

