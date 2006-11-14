begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: altq_cbq.h,v 1.10 2003/08/20 23:30:23 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) Sun Microsystems, Inc. 1993-1998 All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the SMCC Technology  *      Development Group at Sun Microsystems, Inc.  *  * 4. The name of the Sun Microsystems, Inc nor may not be used to endorse or  *      promote products derived from this software without specific prior  *      written permission.  *  * SUN MICROSYSTEMS DOES NOT CLAIM MERCHANTABILITY OF THIS SOFTWARE OR THE  * SUITABILITY OF THIS SOFTWARE FOR ANY PARTICULAR PURPOSE.  The software is  * provided "as is" without express or implied warranty of any kind.  *  * These notices must be retained in any copies of any part of this software.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_CBQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_CBQ_H_
end_define

begin_include
include|#
directive|include
file|<altq/altq.h>
end_include

begin_include
include|#
directive|include
file|<altq/altq_rmclass.h>
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

begin_comment
comment|/* #pragma ident "@(#)cbq.h  1.18     98/05/13 SMI" */
end_comment

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
comment|/*  * Define a well known class handles  */
define|#
directive|define
name|NULL_CLASS_HANDLE
value|0xffffffff
define|#
directive|define
name|ROOT_CLASS_HANDLE
value|0xfffffffe
define|#
directive|define
name|DEFAULT_CLASS_HANDLE
value|0xfffffffd
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
define|#
directive|define
name|CTL_CLASS_HANDLE
value|0xfffffffc
endif|#
directive|endif
comment|/* class flags shoud be same as class flags in rm_class.h */
define|#
directive|define
name|CBQCLF_RED
value|0x0001
comment|/* use RED */
define|#
directive|define
name|CBQCLF_ECN
value|0x0002
comment|/* use RED/ECN */
define|#
directive|define
name|CBQCLF_RIO
value|0x0004
comment|/* use RIO */
define|#
directive|define
name|CBQCLF_FLOWVALVE
value|0x0008
comment|/* use flowvalve (aka penalty-box) */
define|#
directive|define
name|CBQCLF_CLEARDSCP
value|0x0010
comment|/* clear diffserv codepoint */
define|#
directive|define
name|CBQCLF_BORROW
value|0x0020
comment|/* borrow from parent */
comment|/* class flags only for root class */
define|#
directive|define
name|CBQCLF_WRR
value|0x0100
comment|/* weighted-round robin */
define|#
directive|define
name|CBQCLF_EFFICIENT
value|0x0200
comment|/* work-conserving */
comment|/* class flags for special classes */
define|#
directive|define
name|CBQCLF_ROOTCLASS
value|0x1000
comment|/* root class */
define|#
directive|define
name|CBQCLF_DEFCLASS
value|0x2000
comment|/* default class */
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
define|#
directive|define
name|CBQCLF_CTLCLASS
value|0x4000
comment|/* control class */
endif|#
directive|endif
define|#
directive|define
name|CBQCLF_CLASSMASK
value|0xf000
comment|/* class mask */
define|#
directive|define
name|CBQ_MAXQSIZE
value|200
define|#
directive|define
name|CBQ_MAXPRI
value|RM_MAXPRIO
typedef|typedef
struct|struct
name|_cbq_class_stats_
block|{
name|u_int32_t
name|handle
decl_stmt|;
name|u_int
name|depth
decl_stmt|;
name|struct
name|pktcntr
name|xmit_cnt
decl_stmt|;
comment|/* packets sent in this class */
name|struct
name|pktcntr
name|drop_cnt
decl_stmt|;
comment|/* dropped packets */
name|u_int
name|over
decl_stmt|;
comment|/* # times went over limit */
name|u_int
name|borrows
decl_stmt|;
comment|/* # times tried to borrow */
name|u_int
name|overactions
decl_stmt|;
comment|/* # times invoked overlimit action */
name|u_int
name|delays
decl_stmt|;
comment|/* # times invoked delay actions */
comment|/* other static class parameters useful for debugging */
name|int
name|priority
decl_stmt|;
name|int
name|maxidle
decl_stmt|;
name|int
name|minidle
decl_stmt|;
name|int
name|offtime
decl_stmt|;
name|int
name|qmax
decl_stmt|;
name|int
name|ns_per_byte
decl_stmt|;
name|int
name|wrr_allot
decl_stmt|;
name|int
name|qcnt
decl_stmt|;
comment|/* # packets in queue */
name|int
name|avgidle
decl_stmt|;
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
block|}
name|class_stats_t
typedef|;
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
comment|/*  * Define structures associated with IOCTLS for cbq.  */
comment|/*  * Define the CBQ interface structure.  This must be included in all  * IOCTL's such that the CBQ driver may find the appropriate CBQ module  * associated with the network interface to be affected.  */
struct|struct
name|cbq_interface
block|{
name|char
name|cbq_ifacename
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
typedef|typedef
struct|struct
name|cbq_class_spec
block|{
name|u_int
name|priority
decl_stmt|;
name|u_int
name|nano_sec_per_byte
decl_stmt|;
name|u_int
name|maxq
decl_stmt|;
name|u_int
name|maxidle
decl_stmt|;
name|int
name|minidle
decl_stmt|;
name|u_int
name|offtime
decl_stmt|;
name|u_int32_t
name|parent_class_handle
decl_stmt|;
name|u_int32_t
name|borrow_class_handle
decl_stmt|;
name|u_int
name|pktsize
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
name|cbq_class_spec_t
typedef|;
struct|struct
name|cbq_add_class
block|{
name|struct
name|cbq_interface
name|cbq_iface
decl_stmt|;
name|cbq_class_spec_t
name|cbq_class
decl_stmt|;
name|u_int32_t
name|cbq_class_handle
decl_stmt|;
block|}
struct|;
struct|struct
name|cbq_delete_class
block|{
name|struct
name|cbq_interface
name|cbq_iface
decl_stmt|;
name|u_int32_t
name|cbq_class_handle
decl_stmt|;
block|}
struct|;
struct|struct
name|cbq_modify_class
block|{
name|struct
name|cbq_interface
name|cbq_iface
decl_stmt|;
name|cbq_class_spec_t
name|cbq_class
decl_stmt|;
name|u_int32_t
name|cbq_class_handle
decl_stmt|;
block|}
struct|;
struct|struct
name|cbq_add_filter
block|{
name|struct
name|cbq_interface
name|cbq_iface
decl_stmt|;
name|u_int32_t
name|cbq_class_handle
decl_stmt|;
name|struct
name|flow_filter
name|cbq_filter
decl_stmt|;
name|u_long
name|cbq_filter_handle
decl_stmt|;
block|}
struct|;
struct|struct
name|cbq_delete_filter
block|{
name|struct
name|cbq_interface
name|cbq_iface
decl_stmt|;
name|u_long
name|cbq_filter_handle
decl_stmt|;
block|}
struct|;
comment|/* number of classes are returned in nclasses field */
struct|struct
name|cbq_getstats
block|{
name|struct
name|cbq_interface
name|iface
decl_stmt|;
name|int
name|nclasses
decl_stmt|;
name|class_stats_t
modifier|*
name|stats
decl_stmt|;
block|}
struct|;
comment|/*  * Define IOCTLs for CBQ.  */
define|#
directive|define
name|CBQ_IF_ATTACH
value|_IOW('Q', 1, struct cbq_interface)
define|#
directive|define
name|CBQ_IF_DETACH
value|_IOW('Q', 2, struct cbq_interface)
define|#
directive|define
name|CBQ_ENABLE
value|_IOW('Q', 3, struct cbq_interface)
define|#
directive|define
name|CBQ_DISABLE
value|_IOW('Q', 4, struct cbq_interface)
define|#
directive|define
name|CBQ_CLEAR_HIERARCHY
value|_IOW('Q', 5, struct cbq_interface)
define|#
directive|define
name|CBQ_ADD_CLASS
value|_IOWR('Q', 7, struct cbq_add_class)
define|#
directive|define
name|CBQ_DEL_CLASS
value|_IOW('Q', 8, struct cbq_delete_class)
define|#
directive|define
name|CBQ_MODIFY_CLASS
value|_IOWR('Q', 9, struct cbq_modify_class)
define|#
directive|define
name|CBQ_ADD_FILTER
value|_IOWR('Q', 10, struct cbq_add_filter)
define|#
directive|define
name|CBQ_DEL_FILTER
value|_IOW('Q', 11, struct cbq_delete_filter)
define|#
directive|define
name|CBQ_GETSTATS
value|_IOWR('Q', 12, struct cbq_getstats)
endif|#
directive|endif
comment|/* ALTQ3_COMPAT */
ifdef|#
directive|ifdef
name|_KERNEL
comment|/*  * Define macros only good for kernel drivers and modules.  */
define|#
directive|define
name|CBQ_WATCHDOG
value|(hz / 20)
define|#
directive|define
name|CBQ_TIMEOUT
value|10
define|#
directive|define
name|CBQ_LS_TIMEOUT
value|(20 * hz / 1000)
define|#
directive|define
name|CBQ_MAX_CLASSES
value|256
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
define|#
directive|define
name|CBQ_MAX_FILTERS
value|256
define|#
directive|define
name|DISABLE
value|0x00
define|#
directive|define
name|ENABLE
value|0x01
endif|#
directive|endif
comment|/* ALTQ3_COMPAT */
comment|/*  * Define State structures.  */
typedef|typedef
struct|struct
name|cbqstate
block|{
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
name|struct
name|cbqstate
modifier|*
name|cbq_next
decl_stmt|;
endif|#
directive|endif
name|int
name|cbq_qlen
decl_stmt|;
comment|/* # of packets in cbq */
name|struct
name|rm_class
modifier|*
name|cbq_class_tbl
index|[
name|CBQ_MAX_CLASSES
index|]
decl_stmt|;
name|struct
name|rm_ifdat
name|ifnp
decl_stmt|;
name|struct
name|callout
name|cbq_callout
decl_stmt|;
comment|/* for timeouts */
ifdef|#
directive|ifdef
name|ALTQ3_CLFIER_COMPAT
name|struct
name|acc_classifier
name|cbq_classifier
decl_stmt|;
endif|#
directive|endif
block|}
name|cbq_state_t
typedef|;
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
comment|/* !_ALTQ_ALTQ_CBQ_H_ */
end_comment

end_unit

