begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Copyright (c) 2012 by Delphix. All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2011, Joyent, Inc. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DTRACE_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DTRACE_IMPL_H
end_define

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
comment|/*  * DTrace Dynamic Tracing Software: Kernel Implementation Interfaces  *  * Note: The contents of this file are private to the implementation of the  * Solaris system and DTrace subsystem and are subject to change at any time  * without notice.  Applications and drivers using these interfaces will fail  * to run on future releases.  These interfaces should not be used for any  * purpose except those expressly outlined in dtrace(7D) and libdtrace(3LIB).  * Please refer to the "Solaris Dynamic Tracing Guide" for more information.  */
include|#
directive|include
file|<sys/dtrace.h>
if|#
directive|if
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
ifdef|#
directive|ifdef
name|__sparcv9
typedef|typedef
name|uint32_t
name|pc_t
typedef|;
else|#
directive|else
typedef|typedef
name|uintptr_t
name|pc_t
typedef|;
endif|#
directive|endif
typedef|typedef
name|u_long
name|greg_t
typedef|;
endif|#
directive|endif
comment|/*  * DTrace Implementation Constants and Typedefs  */
define|#
directive|define
name|DTRACE_MAXPROPLEN
value|128
define|#
directive|define
name|DTRACE_DYNVAR_CHUNKSIZE
value|256
struct_decl|struct
name|dtrace_probe
struct_decl|;
struct_decl|struct
name|dtrace_ecb
struct_decl|;
struct_decl|struct
name|dtrace_predicate
struct_decl|;
struct_decl|struct
name|dtrace_action
struct_decl|;
struct_decl|struct
name|dtrace_provider
struct_decl|;
struct_decl|struct
name|dtrace_state
struct_decl|;
typedef|typedef
name|struct
name|dtrace_probe
name|dtrace_probe_t
typedef|;
typedef|typedef
name|struct
name|dtrace_ecb
name|dtrace_ecb_t
typedef|;
typedef|typedef
name|struct
name|dtrace_predicate
name|dtrace_predicate_t
typedef|;
typedef|typedef
name|struct
name|dtrace_action
name|dtrace_action_t
typedef|;
typedef|typedef
name|struct
name|dtrace_provider
name|dtrace_provider_t
typedef|;
typedef|typedef
name|struct
name|dtrace_meta
name|dtrace_meta_t
typedef|;
typedef|typedef
name|struct
name|dtrace_state
name|dtrace_state_t
typedef|;
typedef|typedef
name|uint32_t
name|dtrace_optid_t
typedef|;
typedef|typedef
name|uint32_t
name|dtrace_specid_t
typedef|;
typedef|typedef
name|uint64_t
name|dtrace_genid_t
typedef|;
comment|/*  * DTrace Probes  *  * The probe is the fundamental unit of the DTrace architecture.  Probes are  * created by DTrace providers, and managed by the DTrace framework.  A probe  * is identified by a unique<provider, module, function, name> tuple, and has  * a unique probe identifier assigned to it.  (Some probes are not associated  * with a specific point in text; these are called _unanchored probes_ and have  * no module or function associated with them.)  Probes are represented as a  * dtrace_probe structure.  To allow quick lookups based on each element of the  * probe tuple, probes are hashed by each of provider, module, function and  * name.  (If a lookup is performed based on a regular expression, a  * dtrace_probekey is prepared, and a linear search is performed.) Each probe  * is additionally pointed to by a linear array indexed by its identifier.  The  * identifier is the provider's mechanism for indicating to the DTrace  * framework that a probe has fired:  the identifier is passed as the first  * argument to dtrace_probe(), where it is then mapped into the corresponding  * dtrace_probe structure.  From the dtrace_probe structure, dtrace_probe() can  * iterate over the probe's list of enabling control blocks; see "DTrace  * Enabling Control Blocks", below.)  */
struct|struct
name|dtrace_probe
block|{
name|dtrace_id_t
name|dtpr_id
decl_stmt|;
comment|/* probe identifier */
name|dtrace_ecb_t
modifier|*
name|dtpr_ecb
decl_stmt|;
comment|/* ECB list; see below */
name|dtrace_ecb_t
modifier|*
name|dtpr_ecb_last
decl_stmt|;
comment|/* last ECB in list */
name|void
modifier|*
name|dtpr_arg
decl_stmt|;
comment|/* provider argument */
name|dtrace_cacheid_t
name|dtpr_predcache
decl_stmt|;
comment|/* predicate cache ID */
name|int
name|dtpr_aframes
decl_stmt|;
comment|/* artificial frames */
name|dtrace_provider_t
modifier|*
name|dtpr_provider
decl_stmt|;
comment|/* pointer to provider */
name|char
modifier|*
name|dtpr_mod
decl_stmt|;
comment|/* probe's module name */
name|char
modifier|*
name|dtpr_func
decl_stmt|;
comment|/* probe's function name */
name|char
modifier|*
name|dtpr_name
decl_stmt|;
comment|/* probe's name */
name|dtrace_probe_t
modifier|*
name|dtpr_nextmod
decl_stmt|;
comment|/* next in module hash */
name|dtrace_probe_t
modifier|*
name|dtpr_prevmod
decl_stmt|;
comment|/* previous in module hash */
name|dtrace_probe_t
modifier|*
name|dtpr_nextfunc
decl_stmt|;
comment|/* next in function hash */
name|dtrace_probe_t
modifier|*
name|dtpr_prevfunc
decl_stmt|;
comment|/* previous in function hash */
name|dtrace_probe_t
modifier|*
name|dtpr_nextname
decl_stmt|;
comment|/* next in name hash */
name|dtrace_probe_t
modifier|*
name|dtpr_prevname
decl_stmt|;
comment|/* previous in name hash */
name|dtrace_genid_t
name|dtpr_gen
decl_stmt|;
comment|/* probe generation ID */
block|}
struct|;
typedef|typedef
name|int
name|dtrace_probekey_f
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
typedef|typedef
struct|struct
name|dtrace_probekey
block|{
name|char
modifier|*
name|dtpk_prov
decl_stmt|;
comment|/* provider name to match */
name|dtrace_probekey_f
modifier|*
name|dtpk_pmatch
decl_stmt|;
comment|/* provider matching function */
name|char
modifier|*
name|dtpk_mod
decl_stmt|;
comment|/* module name to match */
name|dtrace_probekey_f
modifier|*
name|dtpk_mmatch
decl_stmt|;
comment|/* module matching function */
name|char
modifier|*
name|dtpk_func
decl_stmt|;
comment|/* func name to match */
name|dtrace_probekey_f
modifier|*
name|dtpk_fmatch
decl_stmt|;
comment|/* func matching function */
name|char
modifier|*
name|dtpk_name
decl_stmt|;
comment|/* name to match */
name|dtrace_probekey_f
modifier|*
name|dtpk_nmatch
decl_stmt|;
comment|/* name matching function */
name|dtrace_id_t
name|dtpk_id
decl_stmt|;
comment|/* identifier to match */
block|}
name|dtrace_probekey_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_hashbucket
block|{
name|struct
name|dtrace_hashbucket
modifier|*
name|dthb_next
decl_stmt|;
comment|/* next on hash chain */
name|dtrace_probe_t
modifier|*
name|dthb_chain
decl_stmt|;
comment|/* chain of probes */
name|int
name|dthb_len
decl_stmt|;
comment|/* number of probes here */
block|}
name|dtrace_hashbucket_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_hash
block|{
name|dtrace_hashbucket_t
modifier|*
modifier|*
name|dth_tab
decl_stmt|;
comment|/* hash table */
name|int
name|dth_size
decl_stmt|;
comment|/* size of hash table */
name|int
name|dth_mask
decl_stmt|;
comment|/* mask to index into table */
name|int
name|dth_nbuckets
decl_stmt|;
comment|/* total number of buckets */
name|uintptr_t
name|dth_nextoffs
decl_stmt|;
comment|/* offset of next in probe */
name|uintptr_t
name|dth_prevoffs
decl_stmt|;
comment|/* offset of prev in probe */
name|uintptr_t
name|dth_stroffs
decl_stmt|;
comment|/* offset of str in probe */
block|}
name|dtrace_hash_t
typedef|;
comment|/*  * DTrace Enabling Control Blocks  *  * When a provider wishes to fire a probe, it calls into dtrace_probe(),  * passing the probe identifier as the first argument.  As described above,  * dtrace_probe() maps the identifier into a pointer to a dtrace_probe_t  * structure.  This structure contains information about the probe, and a  * pointer to the list of Enabling Control Blocks (ECBs).  Each ECB points to  * DTrace consumer state, and contains an optional predicate, and a list of  * actions.  (Shown schematically below.)  The ECB abstraction allows a single  * probe to be multiplexed across disjoint consumers, or across disjoint  * enablings of a single probe within one consumer.  *  *   Enabling Control Block  *        dtrace_ecb_t  * +------------------------+  * | dtrace_epid_t ---------+--------------> Enabled Probe ID (EPID)  * | dtrace_state_t * ------+--------------> State associated with this ECB  * | dtrace_predicate_t * --+---------+  * | dtrace_action_t * -----+----+    |  * | dtrace_ecb_t * ---+    |    |    |       Predicate (if any)  * +-------------------+----+    |    |       dtrace_predicate_t  *                     |         |    +---> +--------------------+  *                     |         |          | dtrace_difo_t * ---+----> DIFO  *                     |         |          +--------------------+  *                     |         |  *            Next ECB |         |           Action  *            (if any) |         |       dtrace_action_t  *                     :         +--> +-------------------+  *                     :              | dtrace_actkind_t -+------> kind  *                     v              | dtrace_difo_t * --+------> DIFO (if any)  *                                    | dtrace_recdesc_t -+------> record descr.  *                                    | dtrace_action_t * +------+  *                                    +-------------------+      |  *                                                               | Next action  *                               +-------------------------------+  (if any)  *                               |  *                               |           Action  *                               |       dtrace_action_t  *                               +--> +-------------------+  *                                    | dtrace_actkind_t -+------> kind  *                                    | dtrace_difo_t * --+------> DIFO (if any)  *                                    | dtrace_action_t * +------+  *                                    +-------------------+      |  *                                                               | Next action  *                               +-------------------------------+  (if any)  *                               |  *                               :  *                               v  *  *  * dtrace_probe() iterates over the ECB list.  If the ECB needs less space  * than is available in the principal buffer, the ECB is processed:  if the  * predicate is non-NULL, the DIF object is executed.  If the result is  * non-zero, the action list is processed, with each action being executed  * accordingly.  When the action list has been completely executed, processing  * advances to the next ECB. The ECB abstraction allows disjoint consumers  * to multiplex on single probes.  *  * Execution of the ECB results in consuming dte_size bytes in the buffer  * to record data.  During execution, dte_needed bytes must be available in  * the buffer.  This space is used for both recorded data and tuple data.  */
struct|struct
name|dtrace_ecb
block|{
name|dtrace_epid_t
name|dte_epid
decl_stmt|;
comment|/* enabled probe ID */
name|uint32_t
name|dte_alignment
decl_stmt|;
comment|/* required alignment */
name|size_t
name|dte_needed
decl_stmt|;
comment|/* space needed for execution */
name|size_t
name|dte_size
decl_stmt|;
comment|/* size of recorded payload */
name|dtrace_predicate_t
modifier|*
name|dte_predicate
decl_stmt|;
comment|/* predicate, if any */
name|dtrace_action_t
modifier|*
name|dte_action
decl_stmt|;
comment|/* actions, if any */
name|dtrace_ecb_t
modifier|*
name|dte_next
decl_stmt|;
comment|/* next ECB on probe */
name|dtrace_state_t
modifier|*
name|dte_state
decl_stmt|;
comment|/* pointer to state */
name|uint32_t
name|dte_cond
decl_stmt|;
comment|/* security condition */
name|dtrace_probe_t
modifier|*
name|dte_probe
decl_stmt|;
comment|/* pointer to probe */
name|dtrace_action_t
modifier|*
name|dte_action_last
decl_stmt|;
comment|/* last action on ECB */
name|uint64_t
name|dte_uarg
decl_stmt|;
comment|/* library argument */
block|}
struct|;
struct|struct
name|dtrace_predicate
block|{
name|dtrace_difo_t
modifier|*
name|dtp_difo
decl_stmt|;
comment|/* DIF object */
name|dtrace_cacheid_t
name|dtp_cacheid
decl_stmt|;
comment|/* cache identifier */
name|int
name|dtp_refcnt
decl_stmt|;
comment|/* reference count */
block|}
struct|;
struct|struct
name|dtrace_action
block|{
name|dtrace_actkind_t
name|dta_kind
decl_stmt|;
comment|/* kind of action */
name|uint16_t
name|dta_intuple
decl_stmt|;
comment|/* boolean:  in aggregation */
name|uint32_t
name|dta_refcnt
decl_stmt|;
comment|/* reference count */
name|dtrace_difo_t
modifier|*
name|dta_difo
decl_stmt|;
comment|/* pointer to DIFO */
name|dtrace_recdesc_t
name|dta_rec
decl_stmt|;
comment|/* record description */
name|dtrace_action_t
modifier|*
name|dta_prev
decl_stmt|;
comment|/* previous action */
name|dtrace_action_t
modifier|*
name|dta_next
decl_stmt|;
comment|/* next action */
block|}
struct|;
typedef|typedef
struct|struct
name|dtrace_aggregation
block|{
name|dtrace_action_t
name|dtag_action
decl_stmt|;
comment|/* action; must be first */
name|dtrace_aggid_t
name|dtag_id
decl_stmt|;
comment|/* identifier */
name|dtrace_ecb_t
modifier|*
name|dtag_ecb
decl_stmt|;
comment|/* corresponding ECB */
name|dtrace_action_t
modifier|*
name|dtag_first
decl_stmt|;
comment|/* first action in tuple */
name|uint32_t
name|dtag_base
decl_stmt|;
comment|/* base of aggregation */
name|uint8_t
name|dtag_hasarg
decl_stmt|;
comment|/* boolean:  has argument */
name|uint64_t
name|dtag_initial
decl_stmt|;
comment|/* initial value */
name|void
function_decl|(
modifier|*
name|dtag_aggregate
function_decl|)
parameter_list|(
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
block|}
name|dtrace_aggregation_t
typedef|;
comment|/*  * DTrace Buffers  *  * Principal buffers, aggregation buffers, and speculative buffers are all  * managed with the dtrace_buffer structure.  By default, this structure  * includes twin data buffers -- dtb_tomax and dtb_xamot -- that serve as the  * active and passive buffers, respectively.  For speculative buffers,  * dtb_xamot will be NULL; for "ring" and "fill" buffers, dtb_xamot will point  * to a scratch buffer.  For all buffer types, the dtrace_buffer structure is  * always allocated on a per-CPU basis; a single dtrace_buffer structure is  * never shared among CPUs.  (That is, there is never true sharing of the  * dtrace_buffer structure; to prevent false sharing of the structure, it must  * always be aligned to the coherence granularity -- generally 64 bytes.)  *  * One of the critical design decisions of DTrace is that a given ECB always  * stores the same quantity and type of data.  This is done to assure that the  * only metadata required for an ECB's traced data is the EPID.  That is, from  * the EPID, the consumer can determine the data layout.  (The data buffer  * layout is shown schematically below.)  By assuring that one can determine  * data layout from the EPID, the metadata stream can be separated from the  * data stream -- simplifying the data stream enormously.  The ECB always  * proceeds the recorded data as part of the dtrace_rechdr_t structure that  * includes the EPID and a high-resolution timestamp used for output ordering  * consistency.  *  *      base of data buffer --->  +--------+--------------------+--------+  *                                | rechdr | data               | rechdr |  *                                +--------+------+--------+----+--------+  *                                | data          | rechdr | data        |  *                                +---------------+--------+-------------+  *                                | data, cont.                          |  *                                +--------+--------------------+--------+  *                                | rechdr | data               |        |  *                                +--------+--------------------+        |  *                                |                ||                    |  *                                |                ||                    |  *                                |                \/                    |  *                                :                                      :  *                                .                                      .  *                                .                                      .  *                                .                                      .  *                                :                                      :  *                                |                                      |  *     limit of data buffer --->  +--------------------------------------+  *  * When evaluating an ECB, dtrace_probe() determines if the ECB's needs of the  * principal buffer (both scratch and payload) exceed the available space.  If  * the ECB's needs exceed available space (and if the principal buffer policy  * is the default "switch" policy), the ECB is dropped, the buffer's drop count  * is incremented, and processing advances to the next ECB.  If the ECB's needs  * can be met with the available space, the ECB is processed, but the offset in  * the principal buffer is only advanced if the ECB completes processing  * without error.  *  * When a buffer is to be switched (either because the buffer is the principal  * buffer with a "switch" policy or because it is an aggregation buffer), a  * cross call is issued to the CPU associated with the buffer.  In the cross  * call context, interrupts are disabled, and the active and the inactive  * buffers are atomically switched.  This involves switching the data pointers,  * copying the various state fields (offset, drops, errors, etc.) into their  * inactive equivalents, and clearing the state fields.  Because interrupts are  * disabled during this procedure, the switch is guaranteed to appear atomic to  * dtrace_probe().  *  * DTrace Ring Buffering  *  * To process a ring buffer correctly, one must know the oldest valid record.  * Processing starts at the oldest record in the buffer and continues until  * the end of the buffer is reached.  Processing then resumes starting with  * the record stored at offset 0 in the buffer, and continues until the  * youngest record is processed.  If trace records are of a fixed-length,  * determining the oldest record is trivial:  *  *   - If the ring buffer has not wrapped, the oldest record is the record  *     stored at offset 0.  *  *   - If the ring buffer has wrapped, the oldest record is the record stored  *     at the current offset.  *  * With variable length records, however, just knowing the current offset  * doesn't suffice for determining the oldest valid record:  assuming that one  * allows for arbitrary data, one has no way of searching forward from the  * current offset to find the oldest valid record.  (That is, one has no way  * of separating data from metadata.) It would be possible to simply refuse to  * process any data in the ring buffer between the current offset and the  * limit, but this leaves (potentially) an enormous amount of otherwise valid  * data unprocessed.  *  * To effect ring buffering, we track two offsets in the buffer:  the current  * offset and the _wrapped_ offset.  If a request is made to reserve some  * amount of data, and the buffer has wrapped, the wrapped offset is  * incremented until the wrapped offset minus the current offset is greater  * than or equal to the reserve request.  This is done by repeatedly looking  * up the ECB corresponding to the EPID at the current wrapped offset, and  * incrementing the wrapped offset by the size of the data payload  * corresponding to that ECB.  If this offset is greater than or equal to the  * limit of the data buffer, the wrapped offset is set to 0.  Thus, the  * current offset effectively "chases" the wrapped offset around the buffer.  * Schematically:  *  *      base of data buffer --->  +------+--------------------+------+  *                                | EPID | data               | EPID |  *                                +------+--------+------+----+------+  *                                | data          | EPID | data      |  *                                +---------------+------+-----------+  *                                | data, cont.                      |  *                                +------+---------------------------+  *                                | EPID | data                      |  *           current offset --->  +------+---------------------------+  *                                | invalid data                     |  *           wrapped offset --->  +------+--------------------+------+  *                                | EPID | data               | EPID |  *                                +------+--------+------+----+------+  *                                | data          | EPID | data      |  *                                +---------------+------+-----------+  *                                :                                  :  *                                .                                  .  *                                .        ... valid data ...        .  *                                .                                  .  *                                :                                  :  *                                +------+-------------+------+------+  *                                | EPID | data        | EPID | data |  *                                +------+------------++------+------+  *                                | data, cont.       | leftover     |  *     limit of data buffer --->  +-------------------+--------------+  *  * If the amount of requested buffer space exceeds the amount of space  * available between the current offset and the end of the buffer:  *  *  (1)  all words in the data buffer between the current offset and the limit  *       of the data buffer (marked "leftover", above) are set to  *       DTRACE_EPIDNONE  *  *  (2)  the wrapped offset is set to zero  *  *  (3)  the iteration process described above occurs until the wrapped offset  *       is greater than the amount of desired space.  *  * The wrapped offset is implemented by (re-)using the inactive offset.  * In a "switch" buffer policy, the inactive offset stores the offset in  * the inactive buffer; in a "ring" buffer policy, it stores the wrapped  * offset.  *  * DTrace Scratch Buffering  *  * Some ECBs may wish to allocate dynamically-sized temporary scratch memory.  * To accommodate such requests easily, scratch memory may be allocated in  * the buffer beyond the current offset plus the needed memory of the current  * ECB.  If there isn't sufficient room in the buffer for the requested amount  * of scratch space, the allocation fails and an error is generated.  Scratch  * memory is tracked in the dtrace_mstate_t and is automatically freed when  * the ECB ceases processing.  Note that ring buffers cannot allocate their  * scratch from the principal buffer -- lest they needlessly overwrite older,  * valid data.  Ring buffers therefore have their own dedicated scratch buffer  * from which scratch is allocated.  */
define|#
directive|define
name|DTRACEBUF_RING
value|0x0001
comment|/* bufpolicy set to "ring" */
define|#
directive|define
name|DTRACEBUF_FILL
value|0x0002
comment|/* bufpolicy set to "fill" */
define|#
directive|define
name|DTRACEBUF_NOSWITCH
value|0x0004
comment|/* do not switch buffer */
define|#
directive|define
name|DTRACEBUF_WRAPPED
value|0x0008
comment|/* ring buffer has wrapped */
define|#
directive|define
name|DTRACEBUF_DROPPED
value|0x0010
comment|/* drops occurred */
define|#
directive|define
name|DTRACEBUF_ERROR
value|0x0020
comment|/* errors occurred */
define|#
directive|define
name|DTRACEBUF_FULL
value|0x0040
comment|/* "fill" buffer is full */
define|#
directive|define
name|DTRACEBUF_CONSUMED
value|0x0080
comment|/* buffer has been consumed */
define|#
directive|define
name|DTRACEBUF_INACTIVE
value|0x0100
comment|/* buffer is not yet active */
typedef|typedef
struct|struct
name|dtrace_buffer
block|{
name|uint64_t
name|dtb_offset
decl_stmt|;
comment|/* current offset in buffer */
name|uint64_t
name|dtb_size
decl_stmt|;
comment|/* size of buffer */
name|uint32_t
name|dtb_flags
decl_stmt|;
comment|/* flags */
name|uint32_t
name|dtb_drops
decl_stmt|;
comment|/* number of drops */
name|caddr_t
name|dtb_tomax
decl_stmt|;
comment|/* active buffer */
name|caddr_t
name|dtb_xamot
decl_stmt|;
comment|/* inactive buffer */
name|uint32_t
name|dtb_xamot_flags
decl_stmt|;
comment|/* inactive flags */
name|uint32_t
name|dtb_xamot_drops
decl_stmt|;
comment|/* drops in inactive buffer */
name|uint64_t
name|dtb_xamot_offset
decl_stmt|;
comment|/* offset in inactive buffer */
name|uint32_t
name|dtb_errors
decl_stmt|;
comment|/* number of errors */
name|uint32_t
name|dtb_xamot_errors
decl_stmt|;
comment|/* errors in inactive buffer */
ifndef|#
directive|ifndef
name|_LP64
name|uint64_t
name|dtb_pad1
decl_stmt|;
comment|/* pad out to 64 bytes */
endif|#
directive|endif
name|uint64_t
name|dtb_switched
decl_stmt|;
comment|/* time of last switch */
name|uint64_t
name|dtb_interval
decl_stmt|;
comment|/* observed switch interval */
name|uint64_t
name|dtb_pad2
index|[
literal|6
index|]
decl_stmt|;
comment|/* pad to avoid false sharing */
block|}
name|dtrace_buffer_t
typedef|;
comment|/*  * DTrace Aggregation Buffers  *  * Aggregation buffers use much of the same mechanism as described above  * ("DTrace Buffers").  However, because an aggregation is fundamentally a  * hash, there exists dynamic metadata associated with an aggregation buffer  * that is not associated with other kinds of buffers.  This aggregation  * metadata is _only_ relevant for the in-kernel implementation of  * aggregations; it is not actually relevant to user-level consumers.  To do  * this, we allocate dynamic aggregation data (hash keys and hash buckets)  * starting below the _limit_ of the buffer, and we allocate data from the  * _base_ of the buffer.  When the aggregation buffer is copied out, _only_ the  * data is copied out; the metadata is simply discarded.  Schematically,  * aggregation buffers look like:  *  *      base of data buffer --->  +-------+------+-----------+-------+  *                                | aggid | key  | value     | aggid |  *                                +-------+------+-----------+-------+  *                                | key                              |  *                                +-------+-------+-----+------------+  *                                | value | aggid | key | value      |  *                                +-------+------++-----+------+-----+  *                                | aggid | key  | value       |     |  *                                +-------+------+-------------+     |  *                                |                ||                |  *                                |                ||                |  *                                |                \/                |  *                                :                                  :  *                                .                                  .  *                                .                                  .  *                                .                                  .  *                                :                                  :  *                                |                /\                |  *                                |                ||   +------------+  *                                |                ||   |            |  *                                +---------------------+            |  *                                | hash keys                        |  *                                | (dtrace_aggkey structures)       |  *                                |                                  |  *                                +----------------------------------+  *                                | hash buckets                     |  *                                | (dtrace_aggbuffer structure)     |  *                                |                                  |  *     limit of data buffer --->  +----------------------------------+  *  *  * As implied above, just as we assure that ECBs always store a constant  * amount of data, we assure that a given aggregation -- identified by its  * aggregation ID -- always stores data of a constant quantity and type.  * As with EPIDs, this allows the aggregation ID to serve as the metadata for a  * given record.  *  * Note that the size of the dtrace_aggkey structure must be sizeof (uintptr_t)  * aligned.  (If this the structure changes such that this becomes false, an  * assertion will fail in dtrace_aggregate().)  */
typedef|typedef
struct|struct
name|dtrace_aggkey
block|{
name|uint32_t
name|dtak_hashval
decl_stmt|;
comment|/* hash value */
name|uint32_t
name|dtak_action
range|:
literal|4
decl_stmt|;
comment|/* action -- 4 bits */
name|uint32_t
name|dtak_size
range|:
literal|28
decl_stmt|;
comment|/* size -- 28 bits */
name|caddr_t
name|dtak_data
decl_stmt|;
comment|/* data pointer */
name|struct
name|dtrace_aggkey
modifier|*
name|dtak_next
decl_stmt|;
comment|/* next in hash chain */
block|}
name|dtrace_aggkey_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_aggbuffer
block|{
name|uintptr_t
name|dtagb_hashsize
decl_stmt|;
comment|/* number of buckets */
name|uintptr_t
name|dtagb_free
decl_stmt|;
comment|/* free list of keys */
name|dtrace_aggkey_t
modifier|*
modifier|*
name|dtagb_hash
decl_stmt|;
comment|/* hash table */
block|}
name|dtrace_aggbuffer_t
typedef|;
comment|/*  * DTrace Speculations  *  * Speculations have a per-CPU buffer and a global state.  Once a speculation  * buffer has been comitted or discarded, it cannot be reused until all CPUs  * have taken the same action (commit or discard) on their respective  * speculative buffer.  However, because DTrace probes may execute in arbitrary  * context, other CPUs cannot simply be cross-called at probe firing time to  * perform the necessary commit or discard.  The speculation states thus  * optimize for the case that a speculative buffer is only active on one CPU at  * the time of a commit() or discard() -- for if this is the case, other CPUs  * need not take action, and the speculation is immediately available for  * reuse.  If the speculation is active on multiple CPUs, it must be  * asynchronously cleaned -- potentially leading to a higher rate of dirty  * speculative drops.  The speculation states are as follows:  *  *  DTRACESPEC_INACTIVE<= Initial state; inactive speculation  *  DTRACESPEC_ACTIVE<= Allocated, but not yet speculatively traced to  *  DTRACESPEC_ACTIVEONE<= Speculatively traced to on one CPU  *  DTRACESPEC_ACTIVEMANY<= Speculatively traced to on more than one CPU  *  DTRACESPEC_COMMITTING<= Currently being commited on one CPU  *  DTRACESPEC_COMMITTINGMANY<= Currently being commited on many CPUs  *  DTRACESPEC_DISCARDING<= Currently being discarded on many CPUs  *  * The state transition diagram is as follows:  *  *     +----------------------------------------------------------+  *     |                                                          |  *     |                      +------------+                      |  *     |  +-------------------| COMMITTING |<-----------------+   |  *     |  |                   +------------+                  |   |  *     |  | copied spec.            ^             commit() on |   | discard() on  *     |  | into principal          |              active CPU |   | active CPU  *     |  |                         | commit()                |   |  *     V  V                         |                         |   |  * +----------+                 +--------+                +-----------+  * | INACTIVE |---------------->| ACTIVE |--------------->| ACTIVEONE |  * +----------+  speculation()  +--------+  speculate()   +-----------+  *     ^  ^                         |                         |   |  *     |  |                         | discard()               |   |  *     |  | asynchronously          |            discard() on |   | speculate()  *     |  | cleaned                 V            inactive CPU |   | on inactive  *     |  |                   +------------+                  |   | CPU  *     |  +-------------------| DISCARDING |<-----------------+   |  *     |                      +------------+                      |  *     | asynchronously             ^                             |  *     | copied spec.               |       discard()             |  *     | into principal             +------------------------+    |  *     |                                                     |    V  *  +----------------+             commit()              +------------+  *  | COMMITTINGMANY |<----------------------------------| ACTIVEMANY |  *  +----------------+                                   +------------+  */
typedef|typedef
enum|enum
name|dtrace_speculation_state
block|{
name|DTRACESPEC_INACTIVE
init|=
literal|0
block|,
name|DTRACESPEC_ACTIVE
block|,
name|DTRACESPEC_ACTIVEONE
block|,
name|DTRACESPEC_ACTIVEMANY
block|,
name|DTRACESPEC_COMMITTING
block|,
name|DTRACESPEC_COMMITTINGMANY
block|,
name|DTRACESPEC_DISCARDING
block|}
name|dtrace_speculation_state_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_speculation
block|{
name|dtrace_speculation_state_t
name|dtsp_state
decl_stmt|;
comment|/* current speculation state */
name|int
name|dtsp_cleaning
decl_stmt|;
comment|/* non-zero if being cleaned */
name|dtrace_buffer_t
modifier|*
name|dtsp_buffer
decl_stmt|;
comment|/* speculative buffer */
block|}
name|dtrace_speculation_t
typedef|;
comment|/*  * DTrace Dynamic Variables  *  * The dynamic variable problem is obviously decomposed into two subproblems:  * allocating new dynamic storage, and freeing old dynamic storage.  The  * presence of the second problem makes the first much more complicated -- or  * rather, the absence of the second renders the first trivial.  This is the  * case with aggregations, for which there is effectively no deallocation of  * dynamic storage.  (Or more accurately, all dynamic storage is deallocated  * when a snapshot is taken of the aggregation.)  As DTrace dynamic variables  * allow for both dynamic allocation and dynamic deallocation, the  * implementation of dynamic variables is quite a bit more complicated than  * that of their aggregation kin.  *  * We observe that allocating new dynamic storage is tricky only because the  * size can vary -- the allocation problem is much easier if allocation sizes  * are uniform.  We further observe that in D, the size of dynamic variables is  * actually _not_ dynamic -- dynamic variable sizes may be determined by static  * analysis of DIF text.  (This is true even of putatively dynamically-sized  * objects like strings and stacks, the sizes of which are dictated by the  * "stringsize" and "stackframes" variables, respectively.)  We exploit this by  * performing this analysis on all DIF before enabling any probes.  For each  * dynamic load or store, we calculate the dynamically-allocated size plus the  * size of the dtrace_dynvar structure plus the storage required to key the  * data.  For all DIF, we take the largest value and dub it the _chunksize_.  * We then divide dynamic memory into two parts:  a hash table that is wide  * enough to have every chunk in its own bucket, and a larger region of equal  * chunksize units.  Whenever we wish to dynamically allocate a variable, we  * always allocate a single chunk of memory.  Depending on the uniformity of  * allocation, this will waste some amount of memory -- but it eliminates the  * non-determinism inherent in traditional heap fragmentation.  *  * Dynamic objects are allocated by storing a non-zero value to them; they are  * deallocated by storing a zero value to them.  Dynamic variables are  * complicated enormously by being shared between CPUs.  In particular,  * consider the following scenario:  *  *                 CPU A                                 CPU B  *  +---------------------------------+   +---------------------------------+  *  |                                 |   |                                 |  *  | allocates dynamic object a[123] |   |                                 |  *  | by storing the value 345 to it  |   |                                 |  *  |                               --------->                              |  *  |                                 |   | wishing to load from object     |  *  |                                 |   | a[123], performs lookup in      |  *  |                                 |   | dynamic variable space          |  *  |<---------                              |  *  | deallocates object a[123] by    |   |                                 |  *  | storing 0 to it                 |   |                                 |  *  |                                 |   |                                 |  *  | allocates dynamic object b[567] |   | performs load from a[123]       |  *  | by storing the value 789 to it  |   |                                 |  *  :                                 :   :                                 :  *  .                                 .   .                                 .  *  * This is obviously a race in the D program, but there are nonetheless only  * two valid values for CPU B's load from a[123]:  345 or 0.  Most importantly,  * CPU B may _not_ see the value 789 for a[123].  *  * There are essentially two ways to deal with this:  *  *  (1)  Explicitly spin-lock variables.  That is, if CPU B wishes to load  *       from a[123], it needs to lock a[123] and hold the lock for the  *       duration that it wishes to manipulate it.  *  *  (2)  Avoid reusing freed chunks until it is known that no CPU is referring  *       to them.  *  * The implementation of (1) is rife with complexity, because it requires the  * user of a dynamic variable to explicitly decree when they are done using it.  * Were all variables by value, this perhaps wouldn't be debilitating -- but  * dynamic variables of non-scalar types are tracked by reference.  That is, if  * a dynamic variable is, say, a string, and that variable is to be traced to,  * say, the principal buffer, the DIF emulation code returns to the main  * dtrace_probe() loop a pointer to the underlying storage, not the contents of  * the storage.  Further, code calling on DIF emulation would have to be aware  * that the DIF emulation has returned a reference to a dynamic variable that  * has been potentially locked.  The variable would have to be unlocked after  * the main dtrace_probe() loop is finished with the variable, and the main  * dtrace_probe() loop would have to be careful to not call any further DIF  * emulation while the variable is locked to avoid deadlock.  More generally,  * if one were to implement (1), DIF emulation code dealing with dynamic  * variables could only deal with one dynamic variable at a time (lest deadlock  * result).  To sum, (1) exports too much subtlety to the users of dynamic  * variables -- increasing maintenance burden and imposing serious constraints  * on future DTrace development.  *  * The implementation of (2) is also complex, but the complexity is more  * manageable.  We need to be sure that when a variable is deallocated, it is  * not placed on a traditional free list, but rather on a _dirty_ list.  Once a  * variable is on a dirty list, it cannot be found by CPUs performing a  * subsequent lookup of the variable -- but it may still be in use by other  * CPUs.  To assure that all CPUs that may be seeing the old variable have  * cleared out of probe context, a dtrace_sync() can be issued.  Once the  * dtrace_sync() has completed, it can be known that all CPUs are done  * manipulating the dynamic variable -- the dirty list can be atomically  * appended to the free list.  Unfortunately, there's a slight hiccup in this  * mechanism:  dtrace_sync() may not be issued from probe context.  The  * dtrace_sync() must be therefore issued asynchronously from non-probe  * context.  For this we rely on the DTrace cleaner, a cyclic that runs at the  * "cleanrate" frequency.  To ease this implementation, we define several chunk  * lists:  *  *   - Dirty.  Deallocated chunks, not yet cleaned.  Not available.  *  *   - Rinsing.  Formerly dirty chunks that are currently being asynchronously  *     cleaned.  Not available, but will be shortly.  Dynamic variable  *     allocation may not spin or block for availability, however.  *  *   - Clean.  Clean chunks, ready for allocation -- but not on the free list.  *  *   - Free.  Available for allocation.  *  * Moreover, to avoid absurd contention, _each_ of these lists is implemented  * on a per-CPU basis.  This is only for performance, not correctness; chunks  * may be allocated from another CPU's free list.  The algorithm for allocation  * then is this:  *  *   (1)  Attempt to atomically allocate from current CPU's free list.  If list  *        is non-empty and allocation is successful, allocation is complete.  *  *   (2)  If the clean list is non-empty, atomically move it to the free list,  *        and reattempt (1).  *  *   (3)  If the dynamic variable space is in the CLEAN state, look for free  *        and clean lists on other CPUs by setting the current CPU to the next  *        CPU, and reattempting (1).  If the next CPU is the current CPU (that  *        is, if all CPUs have been checked), atomically switch the state of  *        the dynamic variable space based on the following:  *  *        - If no free chunks were found and no dirty chunks were found,  *          atomically set the state to EMPTY.  *  *        - If dirty chunks were found, atomically set the state to DIRTY.  *  *        - If rinsing chunks were found, atomically set the state to RINSING.  *  *   (4)  Based on state of dynamic variable space state, increment appropriate  *        counter to indicate dynamic drops (if in EMPTY state) vs. dynamic  *        dirty drops (if in DIRTY state) vs. dynamic rinsing drops (if in  *        RINSING state).  Fail the allocation.  *  * The cleaning cyclic operates with the following algorithm:  for all CPUs  * with a non-empty dirty list, atomically move the dirty list to the rinsing  * list.  Perform a dtrace_sync().  For all CPUs with a non-empty rinsing list,  * atomically move the rinsing list to the clean list.  Perform another  * dtrace_sync().  By this point, all CPUs have seen the new clean list; the  * state of the dynamic variable space can be restored to CLEAN.  *  * There exist two final races that merit explanation.  The first is a simple  * allocation race:  *  *                 CPU A                                 CPU B  *  +---------------------------------+   +---------------------------------+  *  |                                 |   |                                 |  *  | allocates dynamic object a[123] |   | allocates dynamic object a[123] |  *  | by storing the value 345 to it  |   | by storing the value 567 to it  |  *  |                                 |   |                                 |  *  :                                 :   :                                 :  *  .                                 .   .                                 .  *  * Again, this is a race in the D program.  It can be resolved by having a[123]  * hold the value 345 or a[123] hold the value 567 -- but it must be true that  * a[123] have only _one_ of these values.  (That is, the racing CPUs may not  * put the same element twice on the same hash chain.)  This is resolved  * simply:  before the allocation is undertaken, the start of the new chunk's  * hash chain is noted.  Later, after the allocation is complete, the hash  * chain is atomically switched to point to the new element.  If this fails  * (because of either concurrent allocations or an allocation concurrent with a  * deletion), the newly allocated chunk is deallocated to the dirty list, and  * the whole process of looking up (and potentially allocating) the dynamic  * variable is reattempted.  *  * The final race is a simple deallocation race:  *  *                 CPU A                                 CPU B  *  +---------------------------------+   +---------------------------------+  *  |                                 |   |                                 |  *  | deallocates dynamic object      |   | deallocates dynamic object      |  *  | a[123] by storing the value 0   |   | a[123] by storing the value 0   |  *  | to it                           |   | to it                           |  *  |                                 |   |                                 |  *  :                                 :   :                                 :  *  .                                 .   .                                 .  *  * Once again, this is a race in the D program, but it is one that we must  * handle without corrupting the underlying data structures.  Because  * deallocations require the deletion of a chunk from the middle of a hash  * chain, we cannot use a single-word atomic operation to remove it.  For this,  * we add a spin lock to the hash buckets that is _only_ used for deallocations  * (allocation races are handled as above).  Further, this spin lock is _only_  * held for the duration of the delete; before control is returned to the DIF  * emulation code, the hash bucket is unlocked.  */
typedef|typedef
struct|struct
name|dtrace_key
block|{
name|uint64_t
name|dttk_value
decl_stmt|;
comment|/* data value or data pointer */
name|uint64_t
name|dttk_size
decl_stmt|;
comment|/* 0 if by-val,>0 if by-ref */
block|}
name|dtrace_key_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_tuple
block|{
name|uint32_t
name|dtt_nkeys
decl_stmt|;
comment|/* number of keys in tuple */
name|uint32_t
name|dtt_pad
decl_stmt|;
comment|/* padding */
name|dtrace_key_t
name|dtt_key
index|[
literal|1
index|]
decl_stmt|;
comment|/* array of tuple keys */
block|}
name|dtrace_tuple_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_dynvar
block|{
name|uint64_t
name|dtdv_hashval
decl_stmt|;
comment|/* hash value -- 0 if free */
name|struct
name|dtrace_dynvar
modifier|*
name|dtdv_next
decl_stmt|;
comment|/* next on list or hash chain */
name|void
modifier|*
name|dtdv_data
decl_stmt|;
comment|/* pointer to data */
name|dtrace_tuple_t
name|dtdv_tuple
decl_stmt|;
comment|/* tuple key */
block|}
name|dtrace_dynvar_t
typedef|;
typedef|typedef
enum|enum
name|dtrace_dynvar_op
block|{
name|DTRACE_DYNVAR_ALLOC
block|,
name|DTRACE_DYNVAR_NOALLOC
block|,
name|DTRACE_DYNVAR_DEALLOC
block|}
name|dtrace_dynvar_op_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_dynhash
block|{
name|dtrace_dynvar_t
modifier|*
name|dtdh_chain
decl_stmt|;
comment|/* hash chain for this bucket */
name|uintptr_t
name|dtdh_lock
decl_stmt|;
comment|/* deallocation lock */
ifdef|#
directive|ifdef
name|_LP64
name|uintptr_t
name|dtdh_pad
index|[
literal|6
index|]
decl_stmt|;
comment|/* pad to avoid false sharing */
else|#
directive|else
name|uintptr_t
name|dtdh_pad
index|[
literal|14
index|]
decl_stmt|;
comment|/* pad to avoid false sharing */
endif|#
directive|endif
block|}
name|dtrace_dynhash_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_dstate_percpu
block|{
name|dtrace_dynvar_t
modifier|*
name|dtdsc_free
decl_stmt|;
comment|/* free list for this CPU */
name|dtrace_dynvar_t
modifier|*
name|dtdsc_dirty
decl_stmt|;
comment|/* dirty list for this CPU */
name|dtrace_dynvar_t
modifier|*
name|dtdsc_rinsing
decl_stmt|;
comment|/* rinsing list for this CPU */
name|dtrace_dynvar_t
modifier|*
name|dtdsc_clean
decl_stmt|;
comment|/* clean list for this CPU */
name|uint64_t
name|dtdsc_drops
decl_stmt|;
comment|/* number of capacity drops */
name|uint64_t
name|dtdsc_dirty_drops
decl_stmt|;
comment|/* number of dirty drops */
name|uint64_t
name|dtdsc_rinsing_drops
decl_stmt|;
comment|/* number of rinsing drops */
ifdef|#
directive|ifdef
name|_LP64
name|uint64_t
name|dtdsc_pad
decl_stmt|;
comment|/* pad to avoid false sharing */
else|#
directive|else
name|uint64_t
name|dtdsc_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* pad to avoid false sharing */
endif|#
directive|endif
block|}
name|dtrace_dstate_percpu_t
typedef|;
typedef|typedef
enum|enum
name|dtrace_dstate_state
block|{
name|DTRACE_DSTATE_CLEAN
init|=
literal|0
block|,
name|DTRACE_DSTATE_EMPTY
block|,
name|DTRACE_DSTATE_DIRTY
block|,
name|DTRACE_DSTATE_RINSING
block|}
name|dtrace_dstate_state_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_dstate
block|{
name|void
modifier|*
name|dtds_base
decl_stmt|;
comment|/* base of dynamic var. space */
name|size_t
name|dtds_size
decl_stmt|;
comment|/* size of dynamic var. space */
name|size_t
name|dtds_hashsize
decl_stmt|;
comment|/* number of buckets in hash */
name|size_t
name|dtds_chunksize
decl_stmt|;
comment|/* size of each chunk */
name|dtrace_dynhash_t
modifier|*
name|dtds_hash
decl_stmt|;
comment|/* pointer to hash table */
name|dtrace_dstate_state_t
name|dtds_state
decl_stmt|;
comment|/* current dynamic var. state */
name|dtrace_dstate_percpu_t
modifier|*
name|dtds_percpu
decl_stmt|;
comment|/* per-CPU dyn. var. state */
block|}
name|dtrace_dstate_t
typedef|;
comment|/*  * DTrace Variable State  *  * The DTrace variable state tracks user-defined variables in its dtrace_vstate  * structure.  Each DTrace consumer has exactly one dtrace_vstate structure,  * but some dtrace_vstate structures may exist without a corresponding DTrace  * consumer (see "DTrace Helpers", below).  As described in<sys/dtrace.h>,  * user-defined variables can have one of three scopes:  *  *  DIFV_SCOPE_GLOBAL  =>  global scope  *  DIFV_SCOPE_THREAD  =>  thread-local scope (i.e. "self->" variables)  *  DIFV_SCOPE_LOCAL   =>  clause-local scope (i.e. "this->" variables)  *  * The variable state tracks variables by both their scope and their allocation  * type:  *  *  - The dtvs_globals and dtvs_locals members each point to an array of  *    dtrace_statvar structures.  These structures contain both the variable  *    metadata (dtrace_difv structures) and the underlying storage for all  *    statically allocated variables, including statically allocated  *    DIFV_SCOPE_GLOBAL variables and all DIFV_SCOPE_LOCAL variables.  *  *  - The dtvs_tlocals member points to an array of dtrace_difv structures for  *    DIFV_SCOPE_THREAD variables.  As such, this array tracks _only_ the  *    variable metadata for DIFV_SCOPE_THREAD variables; the underlying storage  *    is allocated out of the dynamic variable space.  *  *  - The dtvs_dynvars member is the dynamic variable state associated with the  *    variable state.  The dynamic variable state (described in "DTrace Dynamic  *    Variables", above) tracks all DIFV_SCOPE_THREAD variables and all  *    dynamically-allocated DIFV_SCOPE_GLOBAL variables.  */
typedef|typedef
struct|struct
name|dtrace_statvar
block|{
name|uint64_t
name|dtsv_data
decl_stmt|;
comment|/* data or pointer to it */
name|size_t
name|dtsv_size
decl_stmt|;
comment|/* size of pointed-to data */
name|int
name|dtsv_refcnt
decl_stmt|;
comment|/* reference count */
name|dtrace_difv_t
name|dtsv_var
decl_stmt|;
comment|/* variable metadata */
block|}
name|dtrace_statvar_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_vstate
block|{
name|dtrace_state_t
modifier|*
name|dtvs_state
decl_stmt|;
comment|/* back pointer to state */
name|dtrace_statvar_t
modifier|*
modifier|*
name|dtvs_globals
decl_stmt|;
comment|/* statically-allocated glbls */
name|int
name|dtvs_nglobals
decl_stmt|;
comment|/* number of globals */
name|dtrace_difv_t
modifier|*
name|dtvs_tlocals
decl_stmt|;
comment|/* thread-local metadata */
name|int
name|dtvs_ntlocals
decl_stmt|;
comment|/* number of thread-locals */
name|dtrace_statvar_t
modifier|*
modifier|*
name|dtvs_locals
decl_stmt|;
comment|/* clause-local data */
name|int
name|dtvs_nlocals
decl_stmt|;
comment|/* number of clause-locals */
name|dtrace_dstate_t
name|dtvs_dynvars
decl_stmt|;
comment|/* dynamic variable state */
block|}
name|dtrace_vstate_t
typedef|;
comment|/*  * DTrace Machine State  *  * In the process of processing a fired probe, DTrace needs to track and/or  * cache some per-CPU state associated with that particular firing.  This is  * state that is always discarded after the probe firing has completed, and  * much of it is not specific to any DTrace consumer, remaining valid across  * all ECBs.  This state is tracked in the dtrace_mstate structure.  */
define|#
directive|define
name|DTRACE_MSTATE_ARGS
value|0x00000001
define|#
directive|define
name|DTRACE_MSTATE_PROBE
value|0x00000002
define|#
directive|define
name|DTRACE_MSTATE_EPID
value|0x00000004
define|#
directive|define
name|DTRACE_MSTATE_TIMESTAMP
value|0x00000008
define|#
directive|define
name|DTRACE_MSTATE_STACKDEPTH
value|0x00000010
define|#
directive|define
name|DTRACE_MSTATE_CALLER
value|0x00000020
define|#
directive|define
name|DTRACE_MSTATE_IPL
value|0x00000040
define|#
directive|define
name|DTRACE_MSTATE_FLTOFFS
value|0x00000080
define|#
directive|define
name|DTRACE_MSTATE_WALLTIMESTAMP
value|0x00000100
define|#
directive|define
name|DTRACE_MSTATE_USTACKDEPTH
value|0x00000200
define|#
directive|define
name|DTRACE_MSTATE_UCALLER
value|0x00000400
typedef|typedef
struct|struct
name|dtrace_mstate
block|{
name|uintptr_t
name|dtms_scratch_base
decl_stmt|;
comment|/* base of scratch space */
name|uintptr_t
name|dtms_scratch_ptr
decl_stmt|;
comment|/* current scratch pointer */
name|size_t
name|dtms_scratch_size
decl_stmt|;
comment|/* scratch size */
name|uint32_t
name|dtms_present
decl_stmt|;
comment|/* variables that are present */
name|uint64_t
name|dtms_arg
index|[
literal|5
index|]
decl_stmt|;
comment|/* cached arguments */
name|dtrace_epid_t
name|dtms_epid
decl_stmt|;
comment|/* current EPID */
name|uint64_t
name|dtms_timestamp
decl_stmt|;
comment|/* cached timestamp */
name|hrtime_t
name|dtms_walltimestamp
decl_stmt|;
comment|/* cached wall timestamp */
name|int
name|dtms_stackdepth
decl_stmt|;
comment|/* cached stackdepth */
name|int
name|dtms_ustackdepth
decl_stmt|;
comment|/* cached ustackdepth */
name|struct
name|dtrace_probe
modifier|*
name|dtms_probe
decl_stmt|;
comment|/* current probe */
name|uintptr_t
name|dtms_caller
decl_stmt|;
comment|/* cached caller */
name|uint64_t
name|dtms_ucaller
decl_stmt|;
comment|/* cached user-level caller */
name|int
name|dtms_ipl
decl_stmt|;
comment|/* cached interrupt pri lev */
name|int
name|dtms_fltoffs
decl_stmt|;
comment|/* faulting DIFO offset */
name|uintptr_t
name|dtms_strtok
decl_stmt|;
comment|/* saved strtok() pointer */
name|uint32_t
name|dtms_access
decl_stmt|;
comment|/* memory access rights */
name|dtrace_difo_t
modifier|*
name|dtms_difo
decl_stmt|;
comment|/* current dif object */
name|file_t
modifier|*
name|dtms_getf
decl_stmt|;
comment|/* cached rval of getf() */
block|}
name|dtrace_mstate_t
typedef|;
define|#
directive|define
name|DTRACE_COND_OWNER
value|0x1
define|#
directive|define
name|DTRACE_COND_USERMODE
value|0x2
define|#
directive|define
name|DTRACE_COND_ZONEOWNER
value|0x4
define|#
directive|define
name|DTRACE_PROBEKEY_MAXDEPTH
value|8
comment|/* max glob recursion depth */
comment|/*  * Access flag used by dtrace_mstate.dtms_access.  */
define|#
directive|define
name|DTRACE_ACCESS_KERNEL
value|0x1
comment|/* the priv to read kmem */
comment|/*  * DTrace Activity  *  * Each DTrace consumer is in one of several states, which (for purposes of  * avoiding yet-another overloading of the noun "state") we call the current  * _activity_.  The activity transitions on dtrace_go() (from DTRACIOCGO), on  * dtrace_stop() (from DTRACIOCSTOP) and on the exit() action.  Activities may  * only transition in one direction; the activity transition diagram is a  * directed acyclic graph.  The activity transition diagram is as follows:  *  *  * +----------+                   +--------+                   +--------+  * | INACTIVE |------------------>| WARMUP |------------------>| ACTIVE |  * +----------+   dtrace_go(),    +--------+   dtrace_go(),    +--------+  *                before BEGIN        |        after BEGIN       |  |  |  *                                    |                          |  |  |  *                      exit() action |                          |  |  |  *                     from BEGIN ECB |                          |  |  |  *                                    |                          |  |  |  *                                    v                          |  |  |  *                               +----------+     exit() action  |  |  |  * +-----------------------------| DRAINING |<-------------------+  |  |  * |                             +----------+                       |  |  * |                                  |                             |  |  * |                   dtrace_stop(), |                             |  |  * |                     before END   |                             |  |  * |                                  |                             |  |  * |                                  v                             |  |  * | +---------+                 +----------+                       |  |  * | | STOPPED |<----------------| COOLDOWN |<----------------------+  |  * | +---------+  dtrace_stop(), +----------+     dtrace_stop(),       |  * |                after END                       before END         |  * |                                                                   |  * |                              +--------+                           |  * +----------------------------->| KILLED |<--------------------------+  *       deadman timeout or       +--------+     deadman timeout or  *        killed consumer                         killed consumer  *  * Note that once a DTrace consumer has stopped tracing, there is no way to  * restart it; if a DTrace consumer wishes to restart tracing, it must reopen  * the DTrace pseudodevice.  */
typedef|typedef
enum|enum
name|dtrace_activity
block|{
name|DTRACE_ACTIVITY_INACTIVE
init|=
literal|0
block|,
comment|/* not yet running */
name|DTRACE_ACTIVITY_WARMUP
block|,
comment|/* while starting */
name|DTRACE_ACTIVITY_ACTIVE
block|,
comment|/* running */
name|DTRACE_ACTIVITY_DRAINING
block|,
comment|/* before stopping */
name|DTRACE_ACTIVITY_COOLDOWN
block|,
comment|/* while stopping */
name|DTRACE_ACTIVITY_STOPPED
block|,
comment|/* after stopping */
name|DTRACE_ACTIVITY_KILLED
comment|/* killed */
block|}
name|dtrace_activity_t
typedef|;
comment|/*  * DTrace Helper Implementation  *  * A description of the helper architecture may be found in<sys/dtrace.h>.  * Each process contains a pointer to its helpers in its p_dtrace_helpers  * member.  This is a pointer to a dtrace_helpers structure, which contains an  * array of pointers to dtrace_helper structures, helper variable state (shared  * among a process's helpers) and a generation count.  (The generation count is  * used to provide an identifier when a helper is added so that it may be  * subsequently removed.)  The dtrace_helper structure is self-explanatory,  * containing pointers to the objects needed to execute the helper.  Note that  * helpers are _duplicated_ across fork(2), and destroyed on exec(2).  No more  * than dtrace_helpers_max are allowed per-process.  */
define|#
directive|define
name|DTRACE_HELPER_ACTION_USTACK
value|0
define|#
directive|define
name|DTRACE_NHELPER_ACTIONS
value|1
typedef|typedef
struct|struct
name|dtrace_helper_action
block|{
name|int
name|dtha_generation
decl_stmt|;
comment|/* helper action generation */
name|int
name|dtha_nactions
decl_stmt|;
comment|/* number of actions */
name|dtrace_difo_t
modifier|*
name|dtha_predicate
decl_stmt|;
comment|/* helper action predicate */
name|dtrace_difo_t
modifier|*
modifier|*
name|dtha_actions
decl_stmt|;
comment|/* array of actions */
name|struct
name|dtrace_helper_action
modifier|*
name|dtha_next
decl_stmt|;
comment|/* next helper action */
block|}
name|dtrace_helper_action_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_helper_provider
block|{
name|int
name|dthp_generation
decl_stmt|;
comment|/* helper provider generation */
name|uint32_t
name|dthp_ref
decl_stmt|;
comment|/* reference count */
name|dof_helper_t
name|dthp_prov
decl_stmt|;
comment|/* DOF w/ provider and probes */
block|}
name|dtrace_helper_provider_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_helpers
block|{
name|dtrace_helper_action_t
modifier|*
modifier|*
name|dthps_actions
decl_stmt|;
comment|/* array of helper actions */
name|dtrace_vstate_t
name|dthps_vstate
decl_stmt|;
comment|/* helper action var. state */
name|dtrace_helper_provider_t
modifier|*
modifier|*
name|dthps_provs
decl_stmt|;
comment|/* array of providers */
name|uint_t
name|dthps_nprovs
decl_stmt|;
comment|/* count of providers */
name|uint_t
name|dthps_maxprovs
decl_stmt|;
comment|/* provider array size */
name|int
name|dthps_generation
decl_stmt|;
comment|/* current generation */
name|pid_t
name|dthps_pid
decl_stmt|;
comment|/* pid of associated proc */
name|int
name|dthps_deferred
decl_stmt|;
comment|/* helper in deferred list */
name|struct
name|dtrace_helpers
modifier|*
name|dthps_next
decl_stmt|;
comment|/* next pointer */
name|struct
name|dtrace_helpers
modifier|*
name|dthps_prev
decl_stmt|;
comment|/* prev pointer */
block|}
name|dtrace_helpers_t
typedef|;
comment|/*  * DTrace Helper Action Tracing  *  * Debugging helper actions can be arduous.  To ease the development and  * debugging of helpers, DTrace contains a tracing-framework-within-a-tracing-  * framework: helper tracing.  If dtrace_helptrace_enabled is non-zero (which  * it is by default on DEBUG kernels), all helper activity will be traced to a  * global, in-kernel ring buffer.  Each entry includes a pointer to the specific  * helper, the location within the helper, and a trace of all local variables.  * The ring buffer may be displayed in a human-readable format with the  * ::dtrace_helptrace mdb(1) dcmd.  */
define|#
directive|define
name|DTRACE_HELPTRACE_NEXT
value|(-1)
define|#
directive|define
name|DTRACE_HELPTRACE_DONE
value|(-2)
define|#
directive|define
name|DTRACE_HELPTRACE_ERR
value|(-3)
typedef|typedef
struct|struct
name|dtrace_helptrace
block|{
name|dtrace_helper_action_t
modifier|*
name|dtht_helper
decl_stmt|;
comment|/* helper action */
name|int
name|dtht_where
decl_stmt|;
comment|/* where in helper action */
name|int
name|dtht_nlocals
decl_stmt|;
comment|/* number of locals */
name|int
name|dtht_fault
decl_stmt|;
comment|/* type of fault (if any) */
name|int
name|dtht_fltoffs
decl_stmt|;
comment|/* DIF offset */
name|uint64_t
name|dtht_illval
decl_stmt|;
comment|/* faulting value */
name|uint64_t
name|dtht_locals
index|[
literal|1
index|]
decl_stmt|;
comment|/* local variables */
block|}
name|dtrace_helptrace_t
typedef|;
comment|/*  * DTrace Credentials  *  * In probe context, we have limited flexibility to examine the credentials  * of the DTrace consumer that created a particular enabling.  We use  * the Least Privilege interfaces to cache the consumer's cred pointer and  * some facts about that credential in a dtrace_cred_t structure. These  * can limit the consumer's breadth of visibility and what actions the  * consumer may take.  */
define|#
directive|define
name|DTRACE_CRV_ALLPROC
value|0x01
define|#
directive|define
name|DTRACE_CRV_KERNEL
value|0x02
define|#
directive|define
name|DTRACE_CRV_ALLZONE
value|0x04
define|#
directive|define
name|DTRACE_CRV_ALL
value|(DTRACE_CRV_ALLPROC | DTRACE_CRV_KERNEL | \ 	DTRACE_CRV_ALLZONE)
define|#
directive|define
name|DTRACE_CRA_PROC
value|0x0001
define|#
directive|define
name|DTRACE_CRA_PROC_CONTROL
value|0x0002
define|#
directive|define
name|DTRACE_CRA_PROC_DESTRUCTIVE_ALLUSER
value|0x0004
define|#
directive|define
name|DTRACE_CRA_PROC_DESTRUCTIVE_ALLZONE
value|0x0008
define|#
directive|define
name|DTRACE_CRA_PROC_DESTRUCTIVE_CREDCHG
value|0x0010
define|#
directive|define
name|DTRACE_CRA_KERNEL
value|0x0020
define|#
directive|define
name|DTRACE_CRA_KERNEL_DESTRUCTIVE
value|0x0040
define|#
directive|define
name|DTRACE_CRA_ALL
value|(DTRACE_CRA_PROC | \ 	DTRACE_CRA_PROC_CONTROL | \ 	DTRACE_CRA_PROC_DESTRUCTIVE_ALLUSER | \ 	DTRACE_CRA_PROC_DESTRUCTIVE_ALLZONE | \ 	DTRACE_CRA_PROC_DESTRUCTIVE_CREDCHG | \ 	DTRACE_CRA_KERNEL | \ 	DTRACE_CRA_KERNEL_DESTRUCTIVE)
typedef|typedef
struct|struct
name|dtrace_cred
block|{
name|cred_t
modifier|*
name|dcr_cred
decl_stmt|;
name|uint8_t
name|dcr_destructive
decl_stmt|;
name|uint8_t
name|dcr_visible
decl_stmt|;
name|uint16_t
name|dcr_action
decl_stmt|;
block|}
name|dtrace_cred_t
typedef|;
comment|/*  * DTrace Consumer State  *  * Each DTrace consumer has an associated dtrace_state structure that contains  * its in-kernel DTrace state -- including options, credentials, statistics and  * pointers to ECBs, buffers, speculations and formats.  A dtrace_state  * structure is also allocated for anonymous enablings.  When anonymous state  * is grabbed, the grabbing consumers dts_anon pointer is set to the grabbed  * dtrace_state structure.  */
struct|struct
name|dtrace_state
block|{
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
name|dev_t
name|dts_dev
decl_stmt|;
comment|/* device */
else|#
directive|else
name|struct
name|cdev
modifier|*
name|dts_dev
decl_stmt|;
comment|/* device */
endif|#
directive|endif
name|int
name|dts_necbs
decl_stmt|;
comment|/* total number of ECBs */
name|dtrace_ecb_t
modifier|*
modifier|*
name|dts_ecbs
decl_stmt|;
comment|/* array of ECBs */
name|dtrace_epid_t
name|dts_epid
decl_stmt|;
comment|/* next EPID to allocate */
name|size_t
name|dts_needed
decl_stmt|;
comment|/* greatest needed space */
name|struct
name|dtrace_state
modifier|*
name|dts_anon
decl_stmt|;
comment|/* anon. state, if grabbed */
name|dtrace_activity_t
name|dts_activity
decl_stmt|;
comment|/* current activity */
name|dtrace_vstate_t
name|dts_vstate
decl_stmt|;
comment|/* variable state */
name|dtrace_buffer_t
modifier|*
name|dts_buffer
decl_stmt|;
comment|/* principal buffer */
name|dtrace_buffer_t
modifier|*
name|dts_aggbuffer
decl_stmt|;
comment|/* aggregation buffer */
name|dtrace_speculation_t
modifier|*
name|dts_speculations
decl_stmt|;
comment|/* speculation array */
name|int
name|dts_nspeculations
decl_stmt|;
comment|/* number of speculations */
name|int
name|dts_naggregations
decl_stmt|;
comment|/* number of aggregations */
name|dtrace_aggregation_t
modifier|*
modifier|*
name|dts_aggregations
decl_stmt|;
comment|/* aggregation array */
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
name|vmem_t
modifier|*
name|dts_aggid_arena
decl_stmt|;
comment|/* arena for aggregation IDs */
else|#
directive|else
name|struct
name|unrhdr
modifier|*
name|dts_aggid_arena
decl_stmt|;
comment|/* arena for aggregation IDs */
endif|#
directive|endif
name|uint64_t
name|dts_errors
decl_stmt|;
comment|/* total number of errors */
name|uint32_t
name|dts_speculations_busy
decl_stmt|;
comment|/* number of spec. busy */
name|uint32_t
name|dts_speculations_unavail
decl_stmt|;
comment|/* number of spec unavail */
name|uint32_t
name|dts_stkstroverflows
decl_stmt|;
comment|/* stack string tab overflows */
name|uint32_t
name|dts_dblerrors
decl_stmt|;
comment|/* errors in ERROR probes */
name|uint32_t
name|dts_reserve
decl_stmt|;
comment|/* space reserved for END */
name|hrtime_t
name|dts_laststatus
decl_stmt|;
comment|/* time of last status */
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
name|cyclic_id_t
name|dts_cleaner
decl_stmt|;
comment|/* cleaning cyclic */
name|cyclic_id_t
name|dts_deadman
decl_stmt|;
comment|/* deadman cyclic */
else|#
directive|else
name|struct
name|callout
name|dts_cleaner
decl_stmt|;
comment|/* Cleaning callout. */
name|struct
name|callout
name|dts_deadman
decl_stmt|;
comment|/* Deadman callout. */
endif|#
directive|endif
name|hrtime_t
name|dts_alive
decl_stmt|;
comment|/* time last alive */
name|char
name|dts_speculates
decl_stmt|;
comment|/* boolean: has speculations */
name|char
name|dts_destructive
decl_stmt|;
comment|/* boolean: has dest. actions */
name|int
name|dts_nformats
decl_stmt|;
comment|/* number of formats */
name|char
modifier|*
modifier|*
name|dts_formats
decl_stmt|;
comment|/* format string array */
name|dtrace_optval_t
name|dts_options
index|[
name|DTRACEOPT_MAX
index|]
decl_stmt|;
comment|/* options */
name|dtrace_cred_t
name|dts_cred
decl_stmt|;
comment|/* credentials */
name|size_t
name|dts_nretained
decl_stmt|;
comment|/* number of retained enabs */
name|int
name|dts_getf
decl_stmt|;
comment|/* number of getf() calls */
block|}
struct|;
struct|struct
name|dtrace_provider
block|{
name|dtrace_pattr_t
name|dtpv_attr
decl_stmt|;
comment|/* provider attributes */
name|dtrace_ppriv_t
name|dtpv_priv
decl_stmt|;
comment|/* provider privileges */
name|dtrace_pops_t
name|dtpv_pops
decl_stmt|;
comment|/* provider operations */
name|char
modifier|*
name|dtpv_name
decl_stmt|;
comment|/* provider name */
name|void
modifier|*
name|dtpv_arg
decl_stmt|;
comment|/* provider argument */
name|hrtime_t
name|dtpv_defunct
decl_stmt|;
comment|/* when made defunct */
name|struct
name|dtrace_provider
modifier|*
name|dtpv_next
decl_stmt|;
comment|/* next provider */
block|}
struct|;
struct|struct
name|dtrace_meta
block|{
name|dtrace_mops_t
name|dtm_mops
decl_stmt|;
comment|/* meta provider operations */
name|char
modifier|*
name|dtm_name
decl_stmt|;
comment|/* meta provider name */
name|void
modifier|*
name|dtm_arg
decl_stmt|;
comment|/* meta provider user arg */
name|uint64_t
name|dtm_count
decl_stmt|;
comment|/* no. of associated provs. */
block|}
struct|;
comment|/*  * DTrace Enablings  *  * A dtrace_enabling structure is used to track a collection of ECB  * descriptions -- before they have been turned into actual ECBs.  This is  * created as a result of DOF processing, and is generally used to generate  * ECBs immediately thereafter.  However, enablings are also generally  * retained should the probes they describe be created at a later time; as  * each new module or provider registers with the framework, the retained  * enablings are reevaluated, with any new match resulting in new ECBs.  To  * prevent probes from being matched more than once, the enabling tracks the  * last probe generation matched, and only matches probes from subsequent  * generations.  */
typedef|typedef
struct|struct
name|dtrace_enabling
block|{
name|dtrace_ecbdesc_t
modifier|*
modifier|*
name|dten_desc
decl_stmt|;
comment|/* all ECB descriptions */
name|int
name|dten_ndesc
decl_stmt|;
comment|/* number of ECB descriptions */
name|int
name|dten_maxdesc
decl_stmt|;
comment|/* size of ECB array */
name|dtrace_vstate_t
modifier|*
name|dten_vstate
decl_stmt|;
comment|/* associated variable state */
name|dtrace_genid_t
name|dten_probegen
decl_stmt|;
comment|/* matched probe generation */
name|dtrace_ecbdesc_t
modifier|*
name|dten_current
decl_stmt|;
comment|/* current ECB description */
name|int
name|dten_error
decl_stmt|;
comment|/* current error value */
name|int
name|dten_primed
decl_stmt|;
comment|/* boolean: set if primed */
name|struct
name|dtrace_enabling
modifier|*
name|dten_prev
decl_stmt|;
comment|/* previous enabling */
name|struct
name|dtrace_enabling
modifier|*
name|dten_next
decl_stmt|;
comment|/* next enabling */
block|}
name|dtrace_enabling_t
typedef|;
comment|/*  * DTrace Anonymous Enablings  *  * Anonymous enablings are DTrace enablings that are not associated with a  * controlling process, but rather derive their enabling from DOF stored as  * properties in the dtrace.conf file.  If there is an anonymous enabling, a  * DTrace consumer state and enabling are created on attach.  The state may be  * subsequently grabbed by the first consumer specifying the "grabanon"  * option.  As long as an anonymous DTrace enabling exists, dtrace(7D) will  * refuse to unload.  */
typedef|typedef
struct|struct
name|dtrace_anon
block|{
name|dtrace_state_t
modifier|*
name|dta_state
decl_stmt|;
comment|/* DTrace consumer state */
name|dtrace_enabling_t
modifier|*
name|dta_enabling
decl_stmt|;
comment|/* pointer to enabling */
name|processorid_t
name|dta_beganon
decl_stmt|;
comment|/* which CPU BEGIN ran on */
block|}
name|dtrace_anon_t
typedef|;
comment|/*  * DTrace Error Debugging  */
ifdef|#
directive|ifdef
name|DEBUG
define|#
directive|define
name|DTRACE_ERRDEBUG
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DTRACE_ERRDEBUG
typedef|typedef
struct|struct
name|dtrace_errhash
block|{
specifier|const
name|char
modifier|*
name|dter_msg
decl_stmt|;
comment|/* error message */
name|int
name|dter_count
decl_stmt|;
comment|/* number of times seen */
block|}
name|dtrace_errhash_t
typedef|;
define|#
directive|define
name|DTRACE_ERRHASHSZ
value|256
comment|/* must be> number of err msgs */
endif|#
directive|endif
comment|/* DTRACE_ERRDEBUG */
comment|/*  * DTrace Toxic Ranges  *  * DTrace supports safe loads from probe context; if the address turns out to  * be invalid, a bit will be set by the kernel indicating that DTrace  * encountered a memory error, and DTrace will propagate the error to the user  * accordingly.  However, there may exist some regions of memory in which an  * arbitrary load can change system state, and from which it is impossible to  * recover from such a load after it has been attempted.  Examples of this may  * include memory in which programmable I/O registers are mapped (for which a  * read may have some implications for the device) or (in the specific case of  * UltraSPARC-I and -II) the virtual address hole.  The platform is required  * to make DTrace aware of these toxic ranges; DTrace will then check that  * target addresses are not in a toxic range before attempting to issue a  * safe load.  */
typedef|typedef
struct|struct
name|dtrace_toxrange
block|{
name|uintptr_t
name|dtt_base
decl_stmt|;
comment|/* base of toxic range */
name|uintptr_t
name|dtt_limit
decl_stmt|;
comment|/* limit of toxic range */
block|}
name|dtrace_toxrange_t
typedef|;
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
specifier|extern
name|uint64_t
name|dtrace_getarg
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
else|#
directive|else
specifier|extern
name|uint64_t
name|__noinline
name|dtrace_getarg
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|extern
name|greg_t
name|dtrace_getfp
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dtrace_getipl
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|uintptr_t
name|dtrace_caller
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|uint32_t
name|dtrace_cas32
parameter_list|(
name|uint32_t
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|dtrace_casptr
parameter_list|(
specifier|volatile
name|void
modifier|*
parameter_list|,
specifier|volatile
name|void
modifier|*
parameter_list|,
specifier|volatile
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_copyin
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|size_t
parameter_list|,
specifier|volatile
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_copyinstr
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|size_t
parameter_list|,
specifier|volatile
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_copyout
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|size_t
parameter_list|,
specifier|volatile
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_copyoutstr
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|size_t
parameter_list|,
specifier|volatile
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_getpcstack
parameter_list|(
name|pc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|ulong_t
name|dtrace_getreg
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dtrace_getstackdepth
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_getupcstack
parameter_list|(
name|uint64_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_getufpstack
parameter_list|(
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dtrace_getustackdepth
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|uintptr_t
name|dtrace_fulword
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|uint8_t
name|dtrace_fuword8
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|uint16_t
name|dtrace_fuword16
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|uint32_t
name|dtrace_fuword32
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|uint64_t
name|dtrace_fuword64
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_probe_error
parameter_list|(
name|dtrace_state_t
modifier|*
parameter_list|,
name|dtrace_epid_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dtrace_assfail
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dtrace_attached
parameter_list|(
name|void
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
specifier|extern
name|hrtime_t
name|dtrace_gethrestime
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__sparc
specifier|extern
name|void
name|dtrace_flush_windows
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_flush_user_windows
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|uint_t
name|dtrace_getotherwin
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|uint_t
name|dtrace_getfprs
parameter_list|(
name|void
parameter_list|)
function_decl|;
else|#
directive|else
specifier|extern
name|void
name|dtrace_copy
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_copystr
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|size_t
parameter_list|,
specifier|volatile
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/*  * DTrace Assertions  *  * DTrace calls ASSERT from probe context.  To assure that a failed ASSERT  * does not induce a markedly more catastrophic failure (e.g., one from which  * a dump cannot be gleaned), DTrace must define its own ASSERT to be one that  * may safely be called from probe context.  This header file must thus be  * included by any DTrace component that calls ASSERT from probe context, and  * _only_ by those components.  (The only exception to this is kernel  * debugging infrastructure at user-level that doesn't depend on calling  * ASSERT.)  */
undef|#
directive|undef
name|ASSERT
ifdef|#
directive|ifdef
name|DEBUG
define|#
directive|define
name|ASSERT
parameter_list|(
name|EX
parameter_list|)
value|((void)((EX) || \ 			dtrace_assfail(#EX, __FILE__, __LINE__)))
else|#
directive|else
define|#
directive|define
name|ASSERT
parameter_list|(
name|X
parameter_list|)
value|((void)0)
endif|#
directive|endif
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
comment|/* _SYS_DTRACE_IMPL_H */
end_comment

end_unit

