begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: altq_wfq.h,v 1.8 2003/07/10 12:07:49 kjc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1997-2002  *	Sony Computer Science Laboratories Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY SONY CSL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL SONY CSL OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  *  March 27, 1997.  Written by Hiroshi Kyusojin of Keio University  *  (kyu@mt.cs.keio.ac.jp).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_WFQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_WFQ_H_
end_define

begin_include
include|#
directive|include
file|<altq/altq.h>
end_include

begin_define
define|#
directive|define
name|DEFAULT_QSIZE
value|256
end_define

begin_define
define|#
directive|define
name|MAX_QSIZE
value|2048
end_define

begin_struct
struct|struct
name|wfq_interface
block|{
name|char
name|wfq_ifacename
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wfq_getqid
block|{
name|struct
name|wfq_interface
name|iface
decl_stmt|;
ifdef|#
directive|ifdef
name|ALTQ3_CLFIER_COMPAT
name|struct
name|flowinfo
name|flow
decl_stmt|;
endif|#
directive|endif
name|u_long
name|qid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wfq_setweight
block|{
name|struct
name|wfq_interface
name|iface
decl_stmt|;
name|int
name|qid
decl_stmt|;
name|int
name|weight
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|each_queue_stats
block|{
name|int
name|bytes
decl_stmt|;
comment|/* bytes in this queue */
name|int
name|weight
decl_stmt|;
comment|/* weight in percent */
name|struct
name|pktcntr
name|xmit_cnt
decl_stmt|;
name|struct
name|pktcntr
name|drop_cnt
decl_stmt|;
block|}
name|queue_stats
typedef|;
end_typedef

begin_struct
struct|struct
name|wfq_getstats
block|{
name|struct
name|wfq_interface
name|iface
decl_stmt|;
name|int
name|qid
decl_stmt|;
name|queue_stats
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wfq_conf
block|{
name|struct
name|wfq_interface
name|iface
decl_stmt|;
name|int
name|hash_policy
decl_stmt|;
comment|/* hash policy */
name|int
name|nqueues
decl_stmt|;
comment|/* number of queues */
name|int
name|qlimit
decl_stmt|;
comment|/* queue size in bytes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WFQ_HASH_DSTADDR
value|0
end_define

begin_comment
comment|/* hash by dst address */
end_comment

begin_define
define|#
directive|define
name|WFQ_HASH_SRCPORT
value|1
end_define

begin_comment
comment|/* hash by src port */
end_comment

begin_define
define|#
directive|define
name|WFQ_HASH_FULL
value|2
end_define

begin_comment
comment|/* hash by all fields */
end_comment

begin_define
define|#
directive|define
name|WFQ_IF_ATTACH
value|_IOW('Q', 1, struct wfq_interface)
end_define

begin_define
define|#
directive|define
name|WFQ_IF_DETACH
value|_IOW('Q', 2, struct wfq_interface)
end_define

begin_define
define|#
directive|define
name|WFQ_ENABLE
value|_IOW('Q', 3, struct wfq_interface)
end_define

begin_define
define|#
directive|define
name|WFQ_DISABLE
value|_IOW('Q', 4, struct wfq_interface)
end_define

begin_define
define|#
directive|define
name|WFQ_CONFIG
value|_IOWR('Q', 6, struct wfq_conf)
end_define

begin_define
define|#
directive|define
name|WFQ_GET_STATS
value|_IOWR('Q', 12, struct wfq_getstats)
end_define

begin_define
define|#
directive|define
name|WFQ_GET_QID
value|_IOWR('Q', 30, struct wfq_getqid)
end_define

begin_define
define|#
directive|define
name|WFQ_SET_WEIGHT
value|_IOWR('Q', 31, struct wfq_setweight)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|HWM
value|(64 * 1024)
end_define

begin_define
define|#
directive|define
name|WFQ_QUOTA
value|512
end_define

begin_comment
comment|/* quota bytes to send at a time */
end_comment

begin_define
define|#
directive|define
name|WFQ_ADDQUOTA
parameter_list|(
name|q
parameter_list|)
value|((q)->quota += WFQ_QUOTA * (q)->weight / 100)
end_define

begin_define
define|#
directive|define
name|ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|DISABLE
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|weighted_fair_queue
block|{
name|struct
name|weighted_fair_queue
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
name|int
name|bytes
decl_stmt|;
comment|/* bytes in this queue */
name|int
name|quota
decl_stmt|;
comment|/* bytes sent in this round */
name|int
name|weight
decl_stmt|;
comment|/* weight in percent */
name|struct
name|pktcntr
name|xmit_cnt
decl_stmt|;
name|struct
name|pktcntr
name|drop_cnt
decl_stmt|;
block|}
name|wfq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|wfqstate
block|{
name|struct
name|wfqstate
modifier|*
name|next
decl_stmt|;
comment|/* for wfqstate list */
name|struct
name|ifaltq
modifier|*
name|ifq
decl_stmt|;
name|int
name|nums
decl_stmt|;
comment|/* number of queues */
name|int
name|hwm
decl_stmt|;
comment|/* high water mark */
name|int
name|bytes
decl_stmt|;
comment|/* total bytes in all the queues */
name|wfq
modifier|*
name|rrp
decl_stmt|;
comment|/* round robin pointer */
name|wfq
modifier|*
name|queue
decl_stmt|;
comment|/* pointer to queue list */
ifdef|#
directive|ifdef
name|ALTQ3_CLFIER_COMPAT
name|u_long
function_decl|(
modifier|*
name|hash_func
function_decl|)
parameter_list|(
name|struct
name|flowinfo
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
name|u_int32_t
name|fbmask
decl_stmt|;
comment|/* filter bitmask */
block|}
name|wfq_state_t
typedef|;
end_typedef

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
comment|/* _ALTQ_ALTQ_WFQ_H */
end_comment

end_unit

