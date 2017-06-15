begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_PROF_STRUCTS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_PROF_STRUCTS_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/ckh.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mutex.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prng.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/rb.h"
end_include

begin_struct
struct|struct
name|prof_bt_s
block|{
comment|/* Backtrace, stored as len program counters. */
name|void
modifier|*
modifier|*
name|vec
decl_stmt|;
name|unsigned
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_PROF_LIBGCC
end_ifdef

begin_comment
comment|/* Data structure passed to libgcc _Unwind_Backtrace() callback functions. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|prof_bt_t
modifier|*
name|bt
decl_stmt|;
name|unsigned
name|max
decl_stmt|;
block|}
name|prof_unwind_data_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|prof_accum_s
block|{
ifndef|#
directive|ifndef
name|JEMALLOC_ATOMIC_U64
name|malloc_mutex_t
name|mtx
decl_stmt|;
name|uint64_t
name|accumbytes
decl_stmt|;
else|#
directive|else
name|atomic_u64_t
name|accumbytes
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|prof_cnt_s
block|{
comment|/* Profiling counters. */
name|uint64_t
name|curobjs
decl_stmt|;
name|uint64_t
name|curbytes
decl_stmt|;
name|uint64_t
name|accumobjs
decl_stmt|;
name|uint64_t
name|accumbytes
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|prof_tctx_state_initializing
block|,
name|prof_tctx_state_nominal
block|,
name|prof_tctx_state_dumping
block|,
name|prof_tctx_state_purgatory
comment|/* Dumper must finish destroying. */
block|}
name|prof_tctx_state_t
typedef|;
end_typedef

begin_struct
struct|struct
name|prof_tctx_s
block|{
comment|/* Thread data for thread that performed the allocation. */
name|prof_tdata_t
modifier|*
name|tdata
decl_stmt|;
comment|/* 	 * Copy of tdata->thr_{uid,discrim}, necessary because tdata may be 	 * defunct during teardown. 	 */
name|uint64_t
name|thr_uid
decl_stmt|;
name|uint64_t
name|thr_discrim
decl_stmt|;
comment|/* Profiling counters, protected by tdata->lock. */
name|prof_cnt_t
name|cnts
decl_stmt|;
comment|/* Associated global context. */
name|prof_gctx_t
modifier|*
name|gctx
decl_stmt|;
comment|/* 	 * UID that distinguishes multiple tctx's created by the same thread, 	 * but coexisting in gctx->tctxs.  There are two ways that such 	 * coexistence can occur: 	 * - A dumper thread can cause a tctx to be retained in the purgatory 	 *   state. 	 * - Although a single "producer" thread must create all tctx's which 	 *   share the same thr_uid, multiple "consumers" can each concurrently 	 *   execute portions of prof_tctx_destroy().  prof_tctx_destroy() only 	 *   gets called once each time cnts.cur{objs,bytes} drop to 0, but this 	 *   threshold can be hit again before the first consumer finishes 	 *   executing prof_tctx_destroy(). 	 */
name|uint64_t
name|tctx_uid
decl_stmt|;
comment|/* Linkage into gctx's tctxs. */
name|rb_node
argument_list|(
argument|prof_tctx_t
argument_list|)
name|tctx_link
expr_stmt|;
comment|/* 	 * True during prof_alloc_prep()..prof_malloc_sample_object(), prevents 	 * sample vs destroy race. 	 */
name|bool
name|prepared
decl_stmt|;
comment|/* Current dump-related state, protected by gctx->lock. */
name|prof_tctx_state_t
name|state
decl_stmt|;
comment|/* 	 * Copy of cnts snapshotted during early dump phase, protected by 	 * dump_mtx. 	 */
name|prof_cnt_t
name|dump_cnts
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|rb_tree
argument_list|(
argument|prof_tctx_t
argument_list|)
name|prof_tctx_tree_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|prof_gctx_s
block|{
comment|/* Protects nlimbo, cnt_summed, and tctxs. */
name|malloc_mutex_t
modifier|*
name|lock
decl_stmt|;
comment|/* 	 * Number of threads that currently cause this gctx to be in a state of 	 * limbo due to one of: 	 *   - Initializing this gctx. 	 *   - Initializing per thread counters associated with this gctx. 	 *   - Preparing to destroy this gctx. 	 *   - Dumping a heap profile that includes this gctx. 	 * nlimbo must be 1 (single destroyer) in order to safely destroy the 	 * gctx. 	 */
name|unsigned
name|nlimbo
decl_stmt|;
comment|/* 	 * Tree of profile counters, one for each thread that has allocated in 	 * this context. 	 */
name|prof_tctx_tree_t
name|tctxs
decl_stmt|;
comment|/* Linkage for tree of contexts to be dumped. */
name|rb_node
argument_list|(
argument|prof_gctx_t
argument_list|)
name|dump_link
expr_stmt|;
comment|/* Temporary storage for summation during dump. */
name|prof_cnt_t
name|cnt_summed
decl_stmt|;
comment|/* Associated backtrace. */
name|prof_bt_t
name|bt
decl_stmt|;
comment|/* Backtrace vector, variable size, referred to by bt. */
name|void
modifier|*
name|vec
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|rb_tree
argument_list|(
argument|prof_gctx_t
argument_list|)
name|prof_gctx_tree_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|prof_tdata_s
block|{
name|malloc_mutex_t
modifier|*
name|lock
decl_stmt|;
comment|/* Monotonically increasing unique thread identifier. */
name|uint64_t
name|thr_uid
decl_stmt|;
comment|/* 	 * Monotonically increasing discriminator among tdata structures 	 * associated with the same thr_uid. 	 */
name|uint64_t
name|thr_discrim
decl_stmt|;
comment|/* Included in heap profile dumps if non-NULL. */
name|char
modifier|*
name|thread_name
decl_stmt|;
name|bool
name|attached
decl_stmt|;
name|bool
name|expired
decl_stmt|;
name|rb_node
argument_list|(
argument|prof_tdata_t
argument_list|)
name|tdata_link
expr_stmt|;
comment|/* 	 * Counter used to initialize prof_tctx_t's tctx_uid.  No locking is 	 * necessary when incrementing this field, because only one thread ever 	 * does so. 	 */
name|uint64_t
name|tctx_uid_next
decl_stmt|;
comment|/* 	 * Hash of (prof_bt_t *)-->(prof_tctx_t *).  Each thread tracks 	 * backtraces for which it has non-zero allocation/deallocation counters 	 * associated with thread-specific prof_tctx_t objects.  Other threads 	 * may write to prof_tctx_t contents when freeing associated objects. 	 */
name|ckh_t
name|bt2tctx
decl_stmt|;
comment|/* Sampling state. */
name|uint64_t
name|prng_state
decl_stmt|;
name|uint64_t
name|bytes_until_sample
decl_stmt|;
comment|/* State used to avoid dumping while operating on prof internals. */
name|bool
name|enq
decl_stmt|;
name|bool
name|enq_idump
decl_stmt|;
name|bool
name|enq_gdump
decl_stmt|;
comment|/* 	 * Set to true during an early dump phase for tdata's which are 	 * currently being dumped.  New threads' tdata's have this initialized 	 * to false so that they aren't accidentally included in later dump 	 * phases. 	 */
name|bool
name|dumping
decl_stmt|;
comment|/* 	 * True if profiling is active for this tdata's thread 	 * (thread.prof.active mallctl). 	 */
name|bool
name|active
decl_stmt|;
comment|/* Temporary storage for summation during dump. */
name|prof_cnt_t
name|cnt_summed
decl_stmt|;
comment|/* Backtrace vector, used for calls to prof_backtrace(). */
name|void
modifier|*
name|vec
index|[
name|PROF_BT_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|rb_tree
argument_list|(
argument|prof_tdata_t
argument_list|)
name|prof_tdata_tree_t
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_PROF_STRUCTS_H */
end_comment

end_unit

