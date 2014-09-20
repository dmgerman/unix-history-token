begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: if_altq.h,v 1.12 2005/04/13 03:44:25 suz Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1997-2003  *	Sony Computer Science Laboratories Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY SONY CSL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL SONY CSL OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_IF_ALTQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_IF_ALTQ_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL_OPT
end_ifdef

begin_include
include|#
directive|include
file|<altq/altqconf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|altq_pktattr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tb_regulator
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|top_cdnr
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Structure defining a queue for a network interface.  */
end_comment

begin_struct
struct|struct
name|ifaltq
block|{
comment|/* fields compatible with struct ifqueue */
name|struct
name|mbuf
modifier|*
name|ifq_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ifq_tail
decl_stmt|;
name|int
name|ifq_len
decl_stmt|;
name|int
name|ifq_maxlen
decl_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|mtx
name|ifq_mtx
decl_stmt|;
endif|#
directive|endif
comment|/* driver owned queue (used for bulk dequeue and prepend) UNLOCKED */
name|struct
name|mbuf
modifier|*
name|ifq_drv_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ifq_drv_tail
decl_stmt|;
name|int
name|ifq_drv_len
decl_stmt|;
name|int
name|ifq_drv_maxlen
decl_stmt|;
comment|/* alternate queueing related fields */
name|int
name|altq_type
decl_stmt|;
comment|/* discipline type */
name|int
name|altq_flags
decl_stmt|;
comment|/* flags (e.g. ready, in-use) */
name|void
modifier|*
name|altq_disc
decl_stmt|;
comment|/* for discipline-specific use */
name|struct
name|ifnet
modifier|*
name|altq_ifp
decl_stmt|;
comment|/* back pointer to interface */
name|int
function_decl|(
modifier|*
name|altq_enqueue
function_decl|)
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|altq_pktattr
modifier|*
parameter_list|)
function_decl|;
name|struct
name|mbuf
modifier|*
function_decl|(
modifier|*
name|altq_dequeue
function_decl|)
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|altq_request
function_decl|)
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* classifier fields */
name|void
modifier|*
name|altq_clfier
decl_stmt|;
comment|/* classifier-specific use */
name|void
modifier|*
function_decl|(
modifier|*
name|altq_classify
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* token bucket regulator */
name|struct
name|tb_regulator
modifier|*
name|altq_tbr
decl_stmt|;
comment|/* input traffic conditioner (doesn't belong to the output queue...) */
name|struct
name|top_cdnr
modifier|*
name|altq_cdnr
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
comment|/*  * packet attributes used by queueing disciplines.  * pattr_class is a discipline-dependent scheduling class that is  * set by a classifier.  * pattr_hdr and pattr_af may be used by a discipline to access  * the header within a mbuf.  (e.g. ECN needs to update the CE bit)  * note that pattr_hdr could be stale after m_pullup, though link  * layer output routines usually don't use m_pullup.  link-level  * compression also invalidates these fields.  thus, pattr_hdr needs  * to be verified when a discipline touches the header.  */
end_comment

begin_struct
struct|struct
name|altq_pktattr
block|{
name|void
modifier|*
name|pattr_class
decl_stmt|;
comment|/* sched class set by classifier */
name|int
name|pattr_af
decl_stmt|;
comment|/* address family */
name|caddr_t
name|pattr_hdr
decl_stmt|;
comment|/* saved header position in mbuf */
block|}
struct|;
end_struct

begin_comment
comment|/*  * mbuf tag to carry a queue id (and hints for ECN).  */
end_comment

begin_struct
struct|struct
name|altq_tag
block|{
name|u_int32_t
name|qid
decl_stmt|;
comment|/* queue id */
comment|/* hints for ecn */
name|int
name|af
decl_stmt|;
comment|/* address family */
name|void
modifier|*
name|hdr
decl_stmt|;
comment|/* saved header position in mbuf */
block|}
struct|;
end_struct

begin_comment
comment|/*  * a token-bucket regulator limits the rate that a network driver can  * dequeue packets from the output queue.  * modern cards are able to buffer a large amount of packets and dequeue  * too many packets at a time.  this bursty dequeue behavior makes it  * impossible to schedule packets by queueing disciplines.  * a token-bucket is used to control the burst size in a device  * independent manner.  */
end_comment

begin_struct
struct|struct
name|tb_regulator
block|{
name|int64_t
name|tbr_rate
decl_stmt|;
comment|/* (scaled) token bucket rate */
name|int64_t
name|tbr_depth
decl_stmt|;
comment|/* (scaled) token bucket depth */
name|int64_t
name|tbr_token
decl_stmt|;
comment|/* (scaled) current token */
name|int64_t
name|tbr_filluptime
decl_stmt|;
comment|/* (scaled) time to fill up bucket */
name|u_int64_t
name|tbr_last
decl_stmt|;
comment|/* last time token was updated */
name|int
name|tbr_lastop
decl_stmt|;
comment|/* last dequeue operation type 					   needed for poll-and-dequeue */
block|}
struct|;
end_struct

begin_comment
comment|/* if_altqflags */
end_comment

begin_define
define|#
directive|define
name|ALTQF_READY
value|0x01
end_define

begin_comment
comment|/* driver supports alternate queueing */
end_comment

begin_define
define|#
directive|define
name|ALTQF_ENABLED
value|0x02
end_define

begin_comment
comment|/* altq is in use */
end_comment

begin_define
define|#
directive|define
name|ALTQF_CLASSIFY
value|0x04
end_define

begin_comment
comment|/* classify packets */
end_comment

begin_define
define|#
directive|define
name|ALTQF_CNDTNING
value|0x08
end_define

begin_comment
comment|/* altq traffic conditioning is enabled */
end_comment

begin_define
define|#
directive|define
name|ALTQF_DRIVER1
value|0x40
end_define

begin_comment
comment|/* driver specific */
end_comment

begin_comment
comment|/* if_altqflags set internally only: */
end_comment

begin_define
define|#
directive|define
name|ALTQF_CANTCHANGE
value|(ALTQF_READY)
end_define

begin_comment
comment|/* altq_dequeue 2nd arg */
end_comment

begin_define
define|#
directive|define
name|ALTDQ_REMOVE
value|1
end_define

begin_comment
comment|/* dequeue mbuf from the queue */
end_comment

begin_define
define|#
directive|define
name|ALTDQ_POLL
value|2
end_define

begin_comment
comment|/* don't dequeue mbuf from the queue */
end_comment

begin_comment
comment|/* altq request types (currently only purge is defined) */
end_comment

begin_define
define|#
directive|define
name|ALTRQ_PURGE
value|1
end_define

begin_comment
comment|/* purge all packets */
end_comment

begin_define
define|#
directive|define
name|ALTQ_IS_READY
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->altq_flags& ALTQF_READY)
end_define

begin_define
define|#
directive|define
name|ALTQ_IS_ENABLED
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->altq_flags& ALTQF_ENABLED)
end_define

begin_define
define|#
directive|define
name|ALTQ_NEEDS_CLASSIFY
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->altq_flags& ALTQF_CLASSIFY)
end_define

begin_define
define|#
directive|define
name|ALTQ_IS_CNDTNING
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->altq_flags& ALTQF_CNDTNING)
end_define

begin_define
define|#
directive|define
name|ALTQ_SET_CNDTNING
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->altq_flags |= ALTQF_CNDTNING)
end_define

begin_define
define|#
directive|define
name|ALTQ_CLEAR_CNDTNING
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->altq_flags&= ~ALTQF_CNDTNING)
end_define

begin_define
define|#
directive|define
name|ALTQ_IS_ATTACHED
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->altq_disc != NULL)
end_define

begin_define
define|#
directive|define
name|ALTQ_ENQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|,
name|pa
parameter_list|,
name|err
parameter_list|)
define|\
value|(err) = (*(ifq)->altq_enqueue)((ifq),(m),(pa))
end_define

begin_define
define|#
directive|define
name|ALTQ_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|(m) = (*(ifq)->altq_dequeue)((ifq), ALTDQ_REMOVE)
end_define

begin_define
define|#
directive|define
name|ALTQ_POLL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|(m) = (*(ifq)->altq_dequeue)((ifq), ALTDQ_POLL)
end_define

begin_define
define|#
directive|define
name|ALTQ_PURGE
parameter_list|(
name|ifq
parameter_list|)
define|\
value|(void)(*(ifq)->altq_request)((ifq), ALTRQ_PURGE, (void *)0)
end_define

begin_define
define|#
directive|define
name|ALTQ_IS_EMPTY
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len == 0)
end_define

begin_define
define|#
directive|define
name|TBR_IS_ENABLED
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->altq_tbr != NULL)
end_define

begin_decl_stmt
specifier|extern
name|int
name|altq_attach
argument_list|(
expr|struct
name|ifaltq
operator|*
argument_list|,
name|int
argument_list|,
name|void
operator|*
argument_list|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|ifaltq
operator|*
argument_list|,
expr|struct
name|mbuf
operator|*
argument_list|,
expr|struct
name|altq_pktattr
operator|*
argument_list|)
argument_list|,
expr|struct
name|mbuf
operator|*
call|(
modifier|*
call|)
argument_list|(
expr|struct
name|ifaltq
operator|*
argument_list|,
name|int
argument_list|)
argument_list|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|ifaltq
operator|*
argument_list|,
name|int
argument_list|,
name|void
operator|*
argument_list|)
argument_list|,
name|void
operator|*
argument_list|,
name|void
operator|*
call|(
modifier|*
call|)
argument_list|(
name|void
operator|*
argument_list|,
expr|struct
name|mbuf
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|altq_detach
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|altq_enable
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|altq_disable
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
function_decl|(
modifier|*
name|tbr_dequeue_ptr
function_decl|)
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|altq_input
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* ALTQ3_CLFIER_COMPAT */
end_comment

begin_endif
unit|void altq_etherclassify(struct ifaltq *, struct mbuf *, struct altq_pktattr *);
endif|#
directive|endif
end_endif

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
comment|/* _ALTQ_IF_ALTQ_H_ */
end_comment

end_unit

