begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 The DragonFly Project.  All rights reserved.  *   * This code is derived from software contributed to The DragonFly Project  * by Matthew Dillon<dillon@backplane.com>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $DragonFly: src/sys/net/altq/altq_fairq.h,v 1.1 2008/04/06 18:58:15 dillon Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_FAIRQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_FAIRQ_H_
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
file|<altq/altq_codel.h>
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

begin_include
include|#
directive|include
file|<altq/altq_rmclass.h>
end_include

begin_define
define|#
directive|define
name|FAIRQ_MAX_BUCKETS
value|2048
end_define

begin_comment
comment|/* maximum number of sorting buckets */
end_comment

begin_define
define|#
directive|define
name|FAIRQ_MAXPRI
value|RM_MAXPRIO
end_define

begin_define
define|#
directive|define
name|FAIRQ_BITMAP_WIDTH
value|(sizeof(fairq_bitmap_t)*8)
end_define

begin_define
define|#
directive|define
name|FAIRQ_BITMAP_MASK
value|(FAIRQ_BITMAP_WIDTH - 1)
end_define

begin_comment
comment|/* fairq class flags */
end_comment

begin_define
define|#
directive|define
name|FARF_RED
value|0x0001
end_define

begin_comment
comment|/* use RED */
end_comment

begin_define
define|#
directive|define
name|FARF_ECN
value|0x0002
end_define

begin_comment
comment|/* use RED/ECN */
end_comment

begin_define
define|#
directive|define
name|FARF_RIO
value|0x0004
end_define

begin_comment
comment|/* use RIO */
end_comment

begin_define
define|#
directive|define
name|FARF_CODEL
value|0x0008
end_define

begin_comment
comment|/* use CoDel */
end_comment

begin_define
define|#
directive|define
name|FARF_CLEARDSCP
value|0x0010
end_define

begin_comment
comment|/* clear diffserv codepoint */
end_comment

begin_define
define|#
directive|define
name|FARF_DEFAULTCLASS
value|0x1000
end_define

begin_comment
comment|/* default class */
end_comment

begin_define
define|#
directive|define
name|FARF_HAS_PACKETS
value|0x2000
end_define

begin_comment
comment|/* might have queued packets */
end_comment

begin_define
define|#
directive|define
name|FARF_USERFLAGS
value|(FARF_RED|FARF_ECN|FARF_RIO|FARF_CLEARDSCP| \ 				 FARF_DEFAULTCLASS)
end_define

begin_comment
comment|/* special class handles */
end_comment

begin_define
define|#
directive|define
name|FAIRQ_NULLCLASS_HANDLE
value|0
end_define

begin_typedef
typedef|typedef
name|u_int
name|fairq_bitmap_t
typedef|;
end_typedef

begin_struct
struct|struct
name|fairq_classstats
block|{
name|uint32_t
name|class_handle
decl_stmt|;
name|u_int
name|qlength
decl_stmt|;
name|u_int
name|qlimit
decl_stmt|;
name|struct
name|pktcntr
name|xmit_cnt
decl_stmt|;
comment|/* transmitted packet counter */
name|struct
name|pktcntr
name|drop_cnt
decl_stmt|;
comment|/* dropped packet counter */
comment|/* codel, red and rio related info */
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
name|struct
name|codel_stats
name|codel
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|fairq_bucket
block|{
name|struct
name|fairq_bucket
modifier|*
name|next
decl_stmt|;
comment|/* circular list */
name|struct
name|fairq_bucket
modifier|*
name|prev
decl_stmt|;
comment|/* circular list */
name|class_queue_t
name|queue
decl_stmt|;
comment|/* the actual queue */
name|uint64_t
name|bw_bytes
decl_stmt|;
comment|/* statistics used to calculate bw */
name|uint64_t
name|bw_delta
decl_stmt|;
comment|/* statistics used to calculate bw */
name|uint64_t
name|last_time
decl_stmt|;
name|int
name|in_use
decl_stmt|;
block|}
name|fairq_bucket_t
typedef|;
end_typedef

begin_struct
struct|struct
name|fairq_class
block|{
name|uint32_t
name|cl_handle
decl_stmt|;
comment|/* class handle */
name|u_int
name|cl_nbuckets
decl_stmt|;
comment|/* (power of 2) */
name|u_int
name|cl_nbucket_mask
decl_stmt|;
comment|/* bucket mask */
name|fairq_bucket_t
modifier|*
name|cl_buckets
decl_stmt|;
name|fairq_bucket_t
modifier|*
name|cl_head
decl_stmt|;
comment|/* head of circular bucket list */
name|fairq_bucket_t
modifier|*
name|cl_polled
decl_stmt|;
union|union
block|{
name|struct
name|red
modifier|*
name|cl_red
decl_stmt|;
comment|/* RED state */
name|struct
name|codel
modifier|*
name|cl_codel
decl_stmt|;
comment|/* CoDel state */
block|}
name|cl_aqm
union|;
define|#
directive|define
name|cl_red
value|cl_aqm.cl_red
define|#
directive|define
name|cl_codel
value|cl_aqm.cl_codel
name|u_int
name|cl_hogs_m1
decl_stmt|;
name|u_int
name|cl_lssc_m1
decl_stmt|;
name|u_int
name|cl_bandwidth
decl_stmt|;
name|uint64_t
name|cl_bw_bytes
decl_stmt|;
name|uint64_t
name|cl_bw_delta
decl_stmt|;
name|uint64_t
name|cl_last_time
decl_stmt|;
name|int
name|cl_qtype
decl_stmt|;
comment|/* rollup */
name|int
name|cl_qlimit
decl_stmt|;
name|int
name|cl_pri
decl_stmt|;
comment|/* priority */
name|int
name|cl_flags
decl_stmt|;
comment|/* class flags */
name|struct
name|fairq_if
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
comment|/* round robin index */
comment|/* statistics */
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
end_struct

begin_comment
comment|/*  * fairq interface state  */
end_comment

begin_struct
struct|struct
name|fairq_if
block|{
name|struct
name|fairq_if
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
name|fairq_class
modifier|*
name|pif_poll_cache
decl_stmt|;
comment|/* cached poll */
name|struct
name|fairq_class
modifier|*
name|pif_default
decl_stmt|;
comment|/* default class */
name|struct
name|fairq_class
modifier|*
name|pif_classes
index|[
name|FAIRQ_MAXPRI
index|]
decl_stmt|;
comment|/* classes */
block|}
struct|;
end_struct

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
comment|/* _ALTQ_ALTQ_FAIRQ_H_ */
end_comment

end_unit

