begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010 Riccardo Panicucci, Luigi Rizzo, Universita` di Pisa  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * The API to write a packet scheduling algorithm for dummynet.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DN_SCHED_H
end_ifndef

begin_define
define|#
directive|define
name|_DN_SCHED_H
end_define

begin_define
define|#
directive|define
name|DN_MULTIQUEUE
value|0x01
end_define

begin_comment
comment|/*  * Descriptor for a scheduling algorithm.  * Contains all function pointers for a given scheduler  * This is typically created when a module is loaded, and stored  * in a global list of schedulers.  */
end_comment

begin_struct
struct|struct
name|dn_alg
block|{
name|uint32_t
name|type
decl_stmt|;
comment|/* the scheduler type */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* scheduler name */
name|uint32_t
name|flags
decl_stmt|;
comment|/* DN_MULTIQUEUE if supports multiple queues */
comment|/* 	 * The following define the size of 3 optional data structures 	 * that may need to be allocated at runtime, and are appended 	 * to each of the base data structures: scheduler, sched.inst, 	 * and queue. We don't have a per-flowset structure. 	 */
comment|/*    + parameters attached to the template, e.g. 	 *	default queue sizes, weights, quantum size, and so on; 	 */
name|size_t
name|schk_datalen
decl_stmt|;
comment|/*    + per-instance parameters, such as timestamps, 	 *	containers for queues, etc; 	 */
name|size_t
name|si_datalen
decl_stmt|;
name|size_t
name|q_datalen
decl_stmt|;
comment|/* per-queue parameters (e.g. S,F) */
comment|/* 	 * Methods implemented by the scheduler: 	 * enqueue	enqueue packet 'm' on scheduler 's', queue 'q'. 	 *	q is NULL for !MULTIQUEUE. 	 *	Return 0 on success, 1 on drop (packet consumed anyways). 	 *	Note that q should be interpreted only as a hint 	 *	on the flow that the mbuf belongs to: while a 	 *	scheduler will normally enqueue m into q, it is ok 	 *	to leave q alone and put the mbuf elsewhere. 	 *	This function is called in two cases: 	 *	 - when a new packet arrives to the scheduler; 	 *	 - when a scheduler is reconfigured. In this case the 	 *	   call is issued by the new_queue callback, with a  	 *	   non empty queue (q) and m pointing to the first 	 *	   mbuf in the queue. For this reason, the function 	 *	   should internally check for (m != q->mq.head) 	 *	   before calling dn_enqueue(). 	 * 	 * dequeue	Called when scheduler instance 's' can 	 *	dequeue a packet. Return NULL if none are available. 	 *	XXX what about non work-conserving ? 	 * 	 * config	called on 'sched X config ...', normally writes 	 *	in the area of size sch_arg 	 * 	 * destroy	called on 'sched delete', frees everything 	 *	in sch_arg (other parts are handled by more specific 	 *	functions) 	 * 	 * new_sched    called when a new instance is created, e.g. 	 *	to create the local queue for !MULTIQUEUE, set V or 	 *	copy parameters for WFQ, and so on. 	 * 	 * free_sched	called when deleting an instance, cleans 	 *	extra data in the per-instance area. 	 * 	 * new_fsk	called when a flowset is linked to a scheduler, 	 *	e.g. to validate parameters such as weights etc. 	 * free_fsk	when a flowset is unlinked from a scheduler. 	 *	(probably unnecessary) 	 * 	 * new_queue	called to set the per-queue parameters, 	 *	e.g. S and F, adjust sum of weights in the parent, etc. 	 * 	 *	The new_queue callback is normally called from when 	 *	creating a new queue. In some cases (such as a 	 *	scheduler change or reconfiguration) it can be called 	 *	with a non empty queue. In this case, the queue 	 *	In case of non empty queue, the new_queue callback could 	 *	need to call the enqueue function. In this case, 	 *	the callback should eventually call enqueue() passing 	 *	as m the first element in the queue. 	 * 	 * free_queue	actions related to a queue removal, e.g. undo 	 *	all the above. If the queue has data in it, also remove 	 *	from the scheduler. This can e.g. happen during a reconfigure. 	 */
name|int
function_decl|(
modifier|*
name|enqueue
function_decl|)
parameter_list|(
name|struct
name|dn_sch_inst
modifier|*
parameter_list|,
name|struct
name|dn_queue
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
name|struct
name|mbuf
modifier|*
function_decl|(
modifier|*
name|dequeue
function_decl|)
parameter_list|(
name|struct
name|dn_sch_inst
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|config
function_decl|)
parameter_list|(
name|struct
name|dn_schk
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|struct
name|dn_schk
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|new_sched
function_decl|)
parameter_list|(
name|struct
name|dn_sch_inst
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|free_sched
function_decl|)
parameter_list|(
name|struct
name|dn_sch_inst
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|new_fsk
function_decl|)
parameter_list|(
name|struct
name|dn_fsk
modifier|*
name|f
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|free_fsk
function_decl|)
parameter_list|(
name|struct
name|dn_fsk
modifier|*
name|f
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|new_queue
function_decl|)
parameter_list|(
name|struct
name|dn_queue
modifier|*
name|q
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|free_queue
function_decl|)
parameter_list|(
name|struct
name|dn_queue
modifier|*
name|q
parameter_list|)
function_decl|;
comment|/* run-time fields */
name|int
name|ref_count
decl_stmt|;
comment|/* XXX number of instances in the system */
name|SLIST_ENTRY
argument_list|(
argument|dn_alg
argument_list|)
name|next
expr_stmt|;
comment|/* Next scheduler in the list */
block|}
struct|;
end_struct

begin_comment
comment|/* MSVC does not support initializers so we need this ugly macro */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|_SI
parameter_list|(
name|fld
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_SI
parameter_list|(
name|fld
parameter_list|)
value|fld
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Additionally, dummynet exports some functions and macros  * to be used by schedulers:  */
end_comment

begin_function_decl
name|void
name|dn_free_pkts
parameter_list|(
name|struct
name|mbuf
modifier|*
name|mnext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_enqueue
parameter_list|(
name|struct
name|dn_queue
modifier|*
name|q
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|drop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* bound a variable between min and max */
end_comment

begin_function_decl
name|int
name|ipdn_bound_var
parameter_list|(
name|int
modifier|*
name|v
parameter_list|,
name|int
name|dflt
parameter_list|,
name|int
name|lo
parameter_list|,
name|int
name|hi
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Extract the head of a queue, update stats. Must be the very last  * thing done on a dequeue as the queue itself may go away.  */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|dn_dequeue
argument_list|(
argument|struct dn_queue *q
argument_list|)
block|{ 	struct
name|mbuf
operator|*
name|m
operator|=
name|q
operator|->
name|mq
operator|.
name|head
block|;
if|if
condition|(
name|m
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|q
operator|->
name|mq
operator|.
name|head
operator|=
name|m
operator|->
name|m_nextpkt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|q
operator|->
name|mq
operator|.
name|count
operator|--
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Update stats for the queue */
end_comment

begin_expr_stmt
name|q
operator|->
name|ni
operator|.
name|length
operator|--
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|q
operator|->
name|ni
operator|.
name|len_bytes
operator|-=
name|m
operator|->
name|m_pkthdr
operator|.
name|len
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|q
operator|->
name|_si
condition|)
block|{
name|q
operator|->
name|_si
operator|->
name|ni
operator|.
name|length
operator|--
expr_stmt|;
name|q
operator|->
name|_si
operator|->
name|ni
operator|.
name|len_bytes
operator|-=
name|m
operator|->
name|m_pkthdr
operator|.
name|len
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|q
operator|->
name|ni
operator|.
name|length
operator|==
literal|0
condition|)
comment|/* queue is now idle */
name|q
operator|->
name|q_time
operator|=
name|dn_cfg
operator|.
name|curr_time
expr_stmt|;
end_if

begin_return
return|return
name|m
return|;
end_return

begin_macro
unit|}  int
name|dn_sched_modevent
argument_list|(
argument|module_t mod
argument_list|,
argument|int cmd
argument_list|,
argument|void *arg
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|DECLARE_DNSCHED_MODULE
parameter_list|(
name|name
parameter_list|,
name|dnsched
parameter_list|)
define|\
value|static moduledata_t name##_mod = {			\ 		#name, dn_sched_modevent, dnsched		\ 	};							\ 	DECLARE_MODULE(name, name##_mod, 			\ 		SI_SUB_PROTO_IFATTACHDOMAIN, SI_ORDER_ANY); 	\         MODULE_DEPEND(name, dummynet, 3, 3, 3);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DN_SCHED_H */
end_comment

end_unit

