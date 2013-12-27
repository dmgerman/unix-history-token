begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Luigi Rizzo, Riccardo Panicucci, Universita` di Pisa  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * internal dummynet APIs.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_DN_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|_IP_DN_PRIVATE_H
end_define

begin_comment
comment|/* debugging support  * use ND() to remove debugging, D() to print a line,  * DX(level, ...) to print above a certain level  * If you redefine D() you are expected to redefine all.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|D
end_ifndef

begin_define
define|#
directive|define
name|ND
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|D1
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|D
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|printf("%-10s " fmt "\n",      \         __FUNCTION__, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DX
parameter_list|(
name|lev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {              \         if (dn_cfg.debug> lev) D(fmt, ## __VA_ARGS__); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_DUMMYNET
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__linux__
end_ifndef

begin_define
define|#
directive|define
name|div64
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int64_t)(a) / (int64_t)(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DN_LOCK_INIT
parameter_list|()
value|do {				\ 	mtx_init(&dn_cfg.uh_mtx, "dn_uh", NULL, MTX_DEF);	\ 	mtx_init(&dn_cfg.bh_mtx, "dn_bh", NULL, MTX_DEF);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|DN_LOCK_DESTROY
parameter_list|()
value|do {				\ 	mtx_destroy(&dn_cfg.uh_mtx);			\ 	mtx_destroy(&dn_cfg.bh_mtx);			\ 	} while (0)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* not used yet */
end_comment

begin_define
define|#
directive|define
name|DN_UH_RLOCK
parameter_list|()
value|mtx_lock(&dn_cfg.uh_mtx)
end_define

begin_define
define|#
directive|define
name|DN_UH_RUNLOCK
parameter_list|()
value|mtx_unlock(&dn_cfg.uh_mtx)
end_define

begin_define
define|#
directive|define
name|DN_UH_WLOCK
parameter_list|()
value|mtx_lock(&dn_cfg.uh_mtx)
end_define

begin_define
define|#
directive|define
name|DN_UH_WUNLOCK
parameter_list|()
value|mtx_unlock(&dn_cfg.uh_mtx)
end_define

begin_define
define|#
directive|define
name|DN_UH_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&dn_cfg.uh_mtx, MA_OWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DN_BH_RLOCK
parameter_list|()
value|mtx_lock(&dn_cfg.uh_mtx)
end_define

begin_define
define|#
directive|define
name|DN_BH_RUNLOCK
parameter_list|()
value|mtx_unlock(&dn_cfg.uh_mtx)
end_define

begin_define
define|#
directive|define
name|DN_BH_WLOCK
parameter_list|()
value|mtx_lock(&dn_cfg.uh_mtx)
end_define

begin_define
define|#
directive|define
name|DN_BH_WUNLOCK
parameter_list|()
value|mtx_unlock(&dn_cfg.uh_mtx)
end_define

begin_define
define|#
directive|define
name|DN_BH_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&dn_cfg.uh_mtx, MA_OWNED)
end_define

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|dn_schk_head
argument_list|,
name|dn_schk
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|dn_sch_inst_head
argument_list|,
name|dn_sch_inst
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|dn_fsk_head
argument_list|,
name|dn_fsk
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|dn_queue_head
argument_list|,
name|dn_queue
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|dn_alg_head
argument_list|,
name|dn_alg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|mq
block|{
comment|/* a basic queue of packets*/
name|struct
name|mbuf
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|void
name|set_oid
parameter_list|(
name|struct
name|dn_id
modifier|*
name|o
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|len
parameter_list|)
block|{
name|o
operator|->
name|type
operator|=
name|type
expr_stmt|;
name|o
operator|->
name|len
operator|=
name|len
expr_stmt|;
name|o
operator|->
name|subtype
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * configuration and global data for a dummynet instance  *  * When a configuration is modified from userland, 'id' is incremented  * so we can use the value to check for stale pointers.  */
end_comment

begin_struct
struct|struct
name|dn_parms
block|{
name|uint32_t
name|id
decl_stmt|;
comment|/* configuration version */
comment|/* defaults (sysctl-accessible) */
name|int
name|red_lookup_depth
decl_stmt|;
name|int
name|red_avg_pkt_size
decl_stmt|;
name|int
name|red_max_pkt_size
decl_stmt|;
name|int
name|hash_size
decl_stmt|;
name|int
name|max_hash_size
decl_stmt|;
name|long
name|byte_limit
decl_stmt|;
comment|/* max queue sizes */
name|long
name|slot_limit
decl_stmt|;
name|int
name|io_fast
decl_stmt|;
name|int
name|debug
decl_stmt|;
comment|/* timekeeping */
name|struct
name|timeval
name|prev_t
decl_stmt|;
comment|/* last time dummynet_tick ran */
name|struct
name|dn_heap
name|evheap
decl_stmt|;
comment|/* scheduled events */
comment|/* counters of objects -- used for reporting space */
name|int
name|schk_count
decl_stmt|;
name|int
name|si_count
decl_stmt|;
name|int
name|fsk_count
decl_stmt|;
name|int
name|queue_count
decl_stmt|;
comment|/* ticks and other stuff */
name|uint64_t
name|curr_time
decl_stmt|;
comment|/* flowsets and schedulers are in hash tables, with 'hash_size' 	 * buckets. fshash is looked up at every packet arrival 	 * so better be generous if we expect many entries. 	 */
name|struct
name|dn_ht
modifier|*
name|fshash
decl_stmt|;
name|struct
name|dn_ht
modifier|*
name|schedhash
decl_stmt|;
comment|/* list of flowsets without a scheduler -- use sch_chain */
name|struct
name|dn_fsk_head
name|fsu
decl_stmt|;
comment|/* list of unlinked flowsets */
name|struct
name|dn_alg_head
name|schedlist
decl_stmt|;
comment|/* list of algorithms */
comment|/* Store the fs/sch to scan when draining. The value is the 	 * bucket number of the hash table. Expire can be disabled 	 * with net.inet.ip.dummynet.expire=0, or it happens every 	 * expire ticks. 	 **/
name|int
name|drain_fs
decl_stmt|;
name|int
name|drain_sch
decl_stmt|;
name|uint32_t
name|expire
decl_stmt|;
name|uint32_t
name|expire_cycle
decl_stmt|;
comment|/* tick count */
name|int
name|init_done
decl_stmt|;
comment|/* if the upper half is busy doing something long, 	 * can set the busy flag and we will enqueue packets in 	 * a queue for later processing. 	 */
name|int
name|busy
decl_stmt|;
name|struct
name|mq
name|pending
decl_stmt|;
ifdef|#
directive|ifdef
name|_KERNEL
comment|/* 	 * This file is normally used in the kernel, unless we do 	 * some userland tests, in which case we do not need a mtx. 	 * uh_mtx arbitrates between system calls and also 	 * protects fshash, schedhash and fsunlinked. 	 * These structures are readonly for the lower half. 	 * bh_mtx protects all other structures which may be 	 * modified upon packet arrivals 	 */
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
name|spinlock_t
name|uh_mtx
decl_stmt|;
name|spinlock_t
name|bh_mtx
decl_stmt|;
else|#
directive|else
name|struct
name|mtx
name|uh_mtx
decl_stmt|;
name|struct
name|mtx
name|bh_mtx
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* _KERNEL */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Delay line, contains all packets on output from a link.  * Every scheduler instance has one.  */
end_comment

begin_struct
struct|struct
name|delay_line
block|{
name|struct
name|dn_id
name|oid
decl_stmt|;
name|struct
name|dn_sch_inst
modifier|*
name|si
decl_stmt|;
name|struct
name|mq
name|mq
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The kernel side of a flowset. It is linked in a hash table  * of flowsets, and in a list of children of their parent scheduler.  * qht is either the queue or (if HAVE_MASK) a hash table queues.  * Note that the mask to use is the (flow_mask|sched_mask), which  * changes as we attach/detach schedulers. So we store it here.  *  * XXX If we want to add scheduler-specific parameters, we need to  * put them in external storage because the scheduler may not be  * available when the fsk is created.  */
end_comment

begin_struct
struct|struct
name|dn_fsk
block|{
comment|/* kernel side of a flowset */
name|struct
name|dn_fs
name|fs
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|dn_fsk
argument_list|)
name|fsk_next
expr_stmt|;
comment|/* hash chain for fshash */
name|struct
name|ipfw_flow_id
name|fsk_mask
decl_stmt|;
comment|/* qht is a hash table of queues, or just a single queue 	 * a bit in fs.flags tells us which one 	 */
name|struct
name|dn_ht
modifier|*
name|qht
decl_stmt|;
name|struct
name|dn_schk
modifier|*
name|sched
decl_stmt|;
comment|/* Sched we are linked to */
name|SLIST_ENTRY
argument_list|(
argument|dn_fsk
argument_list|)
name|sch_chain
expr_stmt|;
comment|/* list of fsk attached to sched */
comment|/* bucket index used by drain routine to drain queues for this 	 * flowset 	 */
name|int
name|drain_bucket
decl_stmt|;
comment|/* Parameter realted to RED / GRED */
comment|/* original values are in dn_fs*/
name|int
name|w_q
decl_stmt|;
comment|/* queue weight (scaled) */
name|int
name|max_th
decl_stmt|;
comment|/* maximum threshold for queue (scaled) */
name|int
name|min_th
decl_stmt|;
comment|/* minimum threshold for queue (scaled) */
name|int
name|max_p
decl_stmt|;
comment|/* maximum value for p_b (scaled) */
name|u_int
name|c_1
decl_stmt|;
comment|/* max_p/(max_th-min_th) (scaled) */
name|u_int
name|c_2
decl_stmt|;
comment|/* max_p*min_th/(max_th-min_th) (scaled) */
name|u_int
name|c_3
decl_stmt|;
comment|/* for GRED, (1-max_p)/max_th (scaled) */
name|u_int
name|c_4
decl_stmt|;
comment|/* for GRED, 1 - 2*max_p (scaled) */
name|u_int
modifier|*
name|w_q_lookup
decl_stmt|;
comment|/* lookup table for computing (1-w_q)^t */
name|u_int
name|lookup_depth
decl_stmt|;
comment|/* depth of lookup table */
name|int
name|lookup_step
decl_stmt|;
comment|/* granularity inside the lookup table */
name|int
name|lookup_weight
decl_stmt|;
comment|/* equal to (1-w_q)^t / (1-w_q)^(t+1) */
name|int
name|avg_pkt_size
decl_stmt|;
comment|/* medium packet size */
name|int
name|max_pkt_size
decl_stmt|;
comment|/* max packet size */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A queue is created as a child of a flowset unless it belongs to  * a !MULTIQUEUE scheduler. It is normally in a hash table in the  * flowset. fs always points to the parent flowset.  * si normally points to the sch_inst, unless the flowset has been  * detached from the scheduler -- in this case si == NULL and we  * should not enqueue.  */
end_comment

begin_struct
struct|struct
name|dn_queue
block|{
name|struct
name|dn_flow
name|ni
decl_stmt|;
comment|/* oid, flow_id, stats */
name|struct
name|mq
name|mq
decl_stmt|;
comment|/* packets queue */
name|struct
name|dn_sch_inst
modifier|*
name|_si
decl_stmt|;
comment|/* owner scheduler instance */
name|SLIST_ENTRY
argument_list|(
argument|dn_queue
argument_list|)
name|q_next
expr_stmt|;
comment|/* hash chain list for qht */
name|struct
name|dn_fsk
modifier|*
name|fs
decl_stmt|;
comment|/* parent flowset. */
comment|/* RED parameters */
name|int
name|avg
decl_stmt|;
comment|/* average queue length est. (scaled) */
name|int
name|count
decl_stmt|;
comment|/* arrivals since last RED drop */
name|int
name|random
decl_stmt|;
comment|/* random value (scaled) */
name|uint64_t
name|q_time
decl_stmt|;
comment|/* start of queue idle time */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The kernel side of a scheduler. Contains the userland config,  * a link, pointer to extra config arguments from command line,  * kernel flags, and a pointer to the scheduler methods.  * It is stored in a hash table, and holds a list of all  * flowsets and scheduler instances.  * XXX sch must be at the beginning, see schk_hash().  */
end_comment

begin_struct
struct|struct
name|dn_schk
block|{
name|struct
name|dn_sch
name|sch
decl_stmt|;
name|struct
name|dn_alg
modifier|*
name|fp
decl_stmt|;
comment|/* Pointer to scheduler functions */
name|struct
name|dn_link
name|link
decl_stmt|;
comment|/* The link, embedded */
name|struct
name|dn_profile
modifier|*
name|profile
decl_stmt|;
comment|/* delay profile, if any */
name|struct
name|dn_id
modifier|*
name|cfg
decl_stmt|;
comment|/* extra config arguments */
name|SLIST_ENTRY
argument_list|(
argument|dn_schk
argument_list|)
name|schk_next
expr_stmt|;
comment|/* hash chain for schedhash */
name|struct
name|dn_fsk_head
name|fsk_list
decl_stmt|;
comment|/* all fsk linked to me */
name|struct
name|dn_fsk
modifier|*
name|fs
decl_stmt|;
comment|/* Flowset for !MULTIQUEUE */
comment|/* bucket index used by the drain routine to drain the scheduler 	 * instance for this flowset. 	 */
name|int
name|drain_bucket
decl_stmt|;
comment|/* Hash table of all instances (through sch.sched_mask) 	 * or single instance if no mask. Always valid. 	 */
name|struct
name|dn_ht
modifier|*
name|siht
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scheduler instance.  * Contains variables and all queues relative to a this instance.  * This struct is created a runtime.  */
end_comment

begin_struct
struct|struct
name|dn_sch_inst
block|{
name|struct
name|dn_flow
name|ni
decl_stmt|;
comment|/* oid, flowid and stats */
name|SLIST_ENTRY
argument_list|(
argument|dn_sch_inst
argument_list|)
name|si_next
expr_stmt|;
comment|/* hash chain for siht */
name|struct
name|delay_line
name|dline
decl_stmt|;
name|struct
name|dn_schk
modifier|*
name|sched
decl_stmt|;
comment|/* the template */
name|int
name|kflags
decl_stmt|;
comment|/* DN_ACTIVE */
name|int64_t
name|credit
decl_stmt|;
comment|/* bits I can transmit (more or less). */
name|uint64_t
name|sched_time
decl_stmt|;
comment|/* time link was scheduled in ready_heap */
name|uint64_t
name|idle_time
decl_stmt|;
comment|/* start of scheduler instance idle time */
comment|/* q_count is the number of queues that this instance is using. 	 * The counter is incremented or decremented when 	 * a reference from the queue is created or deleted. 	 * It is used to make sure that a scheduler instance can be safely 	 * deleted by the drain routine. See notes below. 	 */
name|int
name|q_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NOTE about object drain.  * The system will automatically (XXX check when) drain queues and  * scheduler instances when they are idle.  * A queue is idle when it has no packets; an instance is idle when  * it is not in the evheap heap, and the corresponding delay line is empty.  * A queue can be safely deleted when it is idle because of the scheduler  * function xxx_free_queue() will remove any references to it.  * An instance can be only deleted when no queues reference it. To be sure  * of that, a counter (q_count) stores the number of queues that are pointing  * to the instance.  *  * XXX  * Order of scan:  * - take all flowset in a bucket for the flowset hash table  * - take all queues in a bucket for the flowset  * - increment the queue bucket  * - scan next flowset bucket  * Nothing is done if a bucket contains no entries.  *  * The same schema is used for sceduler instances  */
end_comment

begin_comment
comment|/* kernel-side flags. Linux has DN_DELETE in fcntl.h  */
end_comment

begin_enum
enum|enum
block|{
comment|/* 1 and 2 are reserved for the SCAN flags */
name|DN_DESTROY
init|=
literal|0x0004
block|,
comment|/* destroy */
name|DN_DELETE_FS
init|=
literal|0x0008
block|,
comment|/* destroy flowset */
name|DN_DETACH
init|=
literal|0x0010
block|,
name|DN_ACTIVE
init|=
literal|0x0020
block|,
comment|/* object is in evheap */
name|DN_F_DLINE
init|=
literal|0x0040
block|,
comment|/* object is a delay line */
name|DN_DEL_SAFE
init|=
literal|0x0080
block|,
comment|/* delete a queue only if no longer needed 				   * by scheduler */
name|DN_QHT_IS_Q
init|=
literal|0x0100
block|,
comment|/* in flowset, qht is a single queue */
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|struct
name|dn_parms
name|dn_cfg
decl_stmt|;
end_decl_stmt

begin_comment
comment|//VNET_DECLARE(struct dn_parms, _base_dn_cfg);
end_comment

begin_comment
comment|//#define dn_cfg	VNET(_base_dn_cfg)
end_comment

begin_function_decl
name|int
name|dummynet_io
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ip_fw_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dummynet_task
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|int
name|pending
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dn_reschedule
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dn_queue
modifier|*
name|ipdn_q_find
parameter_list|(
name|struct
name|dn_fsk
modifier|*
parameter_list|,
name|struct
name|dn_sch_inst
modifier|*
parameter_list|,
name|struct
name|ipfw_flow_id
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dn_sch_inst
modifier|*
name|ipdn_si_find
parameter_list|(
name|struct
name|dn_schk
modifier|*
parameter_list|,
name|struct
name|ipfw_flow_id
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * copy_range is a template for requests for ranges of pipes/queues/scheds.  * The number of ranges is variable and can be derived by o.len.  * As a default, we use a small number of entries so that the struct  * fits easily on the stack and is sufficient for most common requests.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_RANGES
value|5
end_define

begin_struct
struct|struct
name|copy_range
block|{
name|struct
name|dn_id
name|o
decl_stmt|;
name|uint32_t
name|r
index|[
literal|2
operator|*
name|DEFAULT_RANGES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|copy_args
block|{
name|char
modifier|*
modifier|*
name|start
decl_stmt|;
name|char
modifier|*
name|end
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|type
decl_stmt|;
name|struct
name|copy_range
modifier|*
name|extra
decl_stmt|;
comment|/* extra filtering */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ip_dummynet_compat
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dummynet_get
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|void
modifier|*
modifier|*
name|compat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_c_copy_q
parameter_list|(
name|void
modifier|*
name|_ni
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_c_copy_pipe
parameter_list|(
name|struct
name|dn_schk
modifier|*
name|s
parameter_list|,
name|struct
name|copy_args
modifier|*
name|a
parameter_list|,
name|int
name|nq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_c_copy_fs
parameter_list|(
name|struct
name|dn_fsk
modifier|*
name|f
parameter_list|,
name|struct
name|copy_args
modifier|*
name|a
parameter_list|,
name|int
name|nq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_compat_copy_queue
parameter_list|(
name|struct
name|copy_args
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|_o
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_compat_copy_pipe
parameter_list|(
name|struct
name|copy_args
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|_o
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copy_data_helper_compat
parameter_list|(
name|void
modifier|*
name|_o
parameter_list|,
name|void
modifier|*
name|_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_compat_calc_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_config
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|int
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* function to drain idle object */
end_comment

begin_function_decl
name|void
name|dn_drain_scheduler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dn_drain_queue
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
comment|/* _IP_DN_PRIVATE_H */
end_comment

end_unit

