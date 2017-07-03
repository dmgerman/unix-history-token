begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_TSD_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_TSD_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/arena_types.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/assert.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/jemalloc_internal_externs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/prof_types.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ql.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/rtree_tsd.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tcache_types.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tcache_structs.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/util.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/witness.h"
end_include

begin_comment
comment|/*  * Thread-Specific-Data layout  * --- data accessed on tcache fast path: state, rtree_ctx, stats, prof ---  * s: state  * e: tcache_enabled  * m: thread_allocated (config_stats)  * f: thread_deallocated (config_stats)  * p: prof_tdata (config_prof)  * c: rtree_ctx (rtree cache accessed on deallocation)  * t: tcache  * --- data not accessed on tcache fast path: arena-related fields ---  * d: arenas_tdata_bypass  * r: reentrancy_level  * x: narenas_tdata  * i: iarena  * a: arena  * o: arenas_tdata  * Loading TSD data is on the critical path of basically all malloc operations.  * In particular, tcache and rtree_ctx rely on hot CPU cache to be effective.  * Use a compact layout to reduce cache footprint.  * +--- 64-bit and 64B cacheline; 1B each letter; First byte on the left. ---+  * |----------------------------  1st cacheline  ----------------------------|  * | sedrxxxx mmmmmmmm ffffffff pppppppp [c * 32  ........ ........ .......] |  * |----------------------------  2nd cacheline  ----------------------------|  * | [c * 64  ........ ........ ........ ........ ........ ........ .......] |  * |----------------------------  3nd cacheline  ----------------------------|  * | [c * 32  ........ ........ .......] iiiiiiii aaaaaaaa oooooooo [t...... |  * +-------------------------------------------------------------------------+  * Note: the entire tcache is embedded into TSD and spans multiple cachelines.  *  * The last 3 members (i, a and o) before tcache isn't really needed on tcache  * fast path.  However we have a number of unused tcache bins and witnesses  * (never touched unless config_debug) at the end of tcache, so we place them  * there to avoid breaking the cachelines and possibly paging in an extra page.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|test_callback_t
function_decl|)
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|MALLOC_TSD_TEST_DATA_INIT
value|0x72b65c10
end_define

begin_define
define|#
directive|define
name|MALLOC_TEST_TSD
define|\
value|O(test_data,		int,			int)		\     O(test_callback,		test_callback_t,	int)
end_define

begin_define
define|#
directive|define
name|MALLOC_TEST_TSD_INITIALIZER
value|, MALLOC_TSD_TEST_DATA_INIT, NULL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MALLOC_TEST_TSD
end_define

begin_define
define|#
directive|define
name|MALLOC_TEST_TSD_INITIALIZER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  O(name,			type,			nullable type */
end_comment

begin_define
define|#
directive|define
name|MALLOC_TSD
define|\
value|O(tcache_enabled,		bool,			bool)		\     O(arenas_tdata_bypass,	bool,			bool)		\     O(reentrancy_level,		int8_t,			int8_t)		\     O(narenas_tdata,		uint32_t,		uint32_t)	\     O(thread_allocated,		uint64_t,		uint64_t)	\     O(thread_deallocated,	uint64_t,		uint64_t)	\     O(prof_tdata,		prof_tdata_t *,		prof_tdata_t *)	\     O(rtree_ctx,		rtree_ctx_t,		rtree_ctx_t)	\     O(iarena,			arena_t *,		arena_t *)	\     O(arena,			arena_t *,		arena_t *)	\     O(arenas_tdata,		arena_tdata_t *,	arena_tdata_t *)\     O(tcache,			tcache_t,		tcache_t)	\     O(witness_tsd,              witness_tsd_t,		witness_tsdn_t)	\     MALLOC_TEST_TSD
end_define

begin_define
define|#
directive|define
name|TSD_INITIALIZER
value|{						\     tsd_state_uninitialized,						\     TCACHE_ENABLED_ZERO_INITIALIZER,					\     false,								\     0,									\     0,									\     0,									\     0,									\     NULL,								\     RTREE_CTX_ZERO_INITIALIZER,						\     NULL,								\     NULL,								\     NULL,								\     TCACHE_ZERO_INITIALIZER,						\     WITNESS_TSD_INITIALIZER						\     MALLOC_TEST_TSD_INITIALIZER						\ }
end_define

begin_enum
enum|enum
block|{
name|tsd_state_nominal
init|=
literal|0
block|,
comment|/* Common case --> jnz. */
name|tsd_state_nominal_slow
init|=
literal|1
block|,
comment|/* Initialized but on slow path. */
comment|/* the above 2 nominal states should be lower values. */
name|tsd_state_nominal_max
init|=
literal|1
block|,
comment|/* used for comparison only. */
name|tsd_state_minimal_initialized
init|=
literal|2
block|,
name|tsd_state_purgatory
init|=
literal|3
block|,
name|tsd_state_reincarnated
init|=
literal|4
block|,
name|tsd_state_uninitialized
init|=
literal|5
block|}
enum|;
end_enum

begin_comment
comment|/* Manually limit tsd_state_t to a single byte. */
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|tsd_state_t
typedef|;
end_typedef

begin_comment
comment|/* The actual tsd. */
end_comment

begin_struct
struct|struct
name|tsd_s
block|{
comment|/* 	 * The contents should be treated as totally opaque outside the tsd 	 * module.  Access any thread-local state through the getters and 	 * setters below. 	 */
name|tsd_state_t
name|state
decl_stmt|;
define|#
directive|define
name|O
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|,
name|nt
parameter_list|)
define|\
value|t use_a_getter_or_setter_instead_##n;
name|MALLOC_TSD
undef|#
directive|undef
name|O
block|}
struct|;
end_struct

begin_comment
comment|/*  * Wrapper around tsd_t that makes it possible to avoid implicit conversion  * between tsd_t and tsdn_t, where tsdn_t is "nullable" and has to be  * explicitly converted to tsd_t, which is non-nullable.  */
end_comment

begin_struct
struct|struct
name|tsdn_s
block|{
name|tsd_t
name|tsd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TSDN_NULL
value|((tsdn_t *)0)
end_define

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|tsdn_t
modifier|*
name|tsd_tsdn
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
block|{
return|return
operator|(
name|tsdn_t
operator|*
operator|)
name|tsd
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|bool
name|tsdn_null
parameter_list|(
specifier|const
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
block|{
return|return
name|tsdn
operator|==
name|NULL
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|tsd_t
modifier|*
name|tsdn_tsd
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|tsdn_null
argument_list|(
name|tsdn
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|&
name|tsdn
operator|->
name|tsd
return|;
block|}
end_function

begin_function_decl
name|void
modifier|*
name|malloc_tsd_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_tsd_dalloc
parameter_list|(
name|void
modifier|*
name|wrapper
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_tsd_cleanup_register
parameter_list|(
name|bool
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tsd_t
modifier|*
name|malloc_tsd_boot0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_tsd_boot1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsd_cleanup
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tsd_t
modifier|*
name|tsd_fetch_slow
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|bool
name|internal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsd_slow_update
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * We put the platform-specific data declarations and inlines into their own  * header files to avoid cluttering this file.  They define tsd_boot0,  * tsd_boot1, tsd_boot, tsd_booted_get, tsd_get_allocates, tsd_get, and tsd_set.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_MALLOC_THREAD_CLEANUP
end_ifdef

begin_include
include|#
directive|include
file|"jemalloc/internal/tsd_malloc_thread_cleanup.h"
end_include

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_TLS
argument_list|)
operator|)
end_elif

begin_include
include|#
directive|include
file|"jemalloc/internal/tsd_tls.h"
end_include

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|)
end_elif

begin_include
include|#
directive|include
file|"jemalloc/internal/tsd_win.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"jemalloc/internal/tsd_generic.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * tsd_foop_get_unsafe(tsd) returns a pointer to the thread-local instance of  * foo.  This omits some safety checks, and so can be used during tsd  * initialization and cleanup.  */
end_comment

begin_define
define|#
directive|define
name|O
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|,
name|nt
parameter_list|)
define|\
value|JEMALLOC_ALWAYS_INLINE t *						\ tsd_##n##p_get_unsafe(tsd_t *tsd) {					\ 	return&tsd->use_a_getter_or_setter_instead_##n;		\ }
end_define

begin_function
name|MALLOC_TSD
undef|#
directive|undef
name|O
comment|/* tsd_foop_get(tsd) returns a pointer to the thread-local instance of foo. */
define|#
directive|define
name|O
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|,
name|nt
parameter_list|)
define|\
value|JEMALLOC_ALWAYS_INLINE t *						\ tsd_##n##p_get(tsd_t *tsd) {						\ 	assert(tsd->state == tsd_state_nominal ||			\ 	    tsd->state == tsd_state_nominal_slow ||			\ 	    tsd->state == tsd_state_reincarnated ||			\ 	    tsd->state == tsd_state_minimal_initialized);		\ 	return tsd_##n##p_get_unsafe(tsd);				\ }
name|MALLOC_TSD
undef|#
directive|undef
name|O
comment|/*  * tsdn_foop_get(tsdn) returns either the thread-local instance of foo (if tsdn  * isn't NULL), or NULL (if tsdn is NULL), cast to the nullable pointer type.  */
define|#
directive|define
name|O
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|,
name|nt
parameter_list|)
define|\
value|JEMALLOC_ALWAYS_INLINE nt *						\ tsdn_##n##p_get(tsdn_t *tsdn) {						\ 	if (tsdn_null(tsdn)) {						\ 		return NULL;						\ 	}								\ 	tsd_t *tsd = tsdn_tsd(tsdn);					\ 	return (nt *)tsd_##n##p_get(tsd);				\ }
name|MALLOC_TSD
undef|#
directive|undef
name|O
comment|/* tsd_foo_get(tsd) returns the value of the thread-local instance of foo. */
define|#
directive|define
name|O
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|,
name|nt
parameter_list|)
define|\
value|JEMALLOC_ALWAYS_INLINE t						\ tsd_##n##_get(tsd_t *tsd) {						\ 	return *tsd_##n##p_get(tsd);					\ }
name|MALLOC_TSD
undef|#
directive|undef
name|O
comment|/* tsd_foo_set(tsd, val) updates the thread-local instance of foo to be val. */
define|#
directive|define
name|O
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|,
name|nt
parameter_list|)
define|\
value|JEMALLOC_ALWAYS_INLINE void						\ tsd_##n##_set(tsd_t *tsd, t val) {					\ 	assert(tsd->state != tsd_state_reincarnated&&			\ 	    tsd->state != tsd_state_minimal_initialized);		\ 	*tsd_##n##p_get(tsd) = val;					\ }
name|MALLOC_TSD
undef|#
directive|undef
name|O
name|JEMALLOC_ALWAYS_INLINE
name|void
name|tsd_assert_fast
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|malloc_slow
operator|&&
name|tsd_tcache_enabled_get
argument_list|(
name|tsd
argument_list|)
operator|&&
name|tsd_reentrancy_level_get
argument_list|(
name|tsd
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|bool
name|tsd_fast
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
block|{
name|bool
name|fast
init|=
operator|(
name|tsd
operator|->
name|state
operator|==
name|tsd_state_nominal
operator|)
decl_stmt|;
if|if
condition|(
name|fast
condition|)
block|{
name|tsd_assert_fast
argument_list|(
name|tsd
argument_list|)
expr_stmt|;
block|}
return|return
name|fast
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|tsd_t
modifier|*
name|tsd_fetch_impl
parameter_list|(
name|bool
name|init
parameter_list|,
name|bool
name|minimal
parameter_list|)
block|{
name|tsd_t
modifier|*
name|tsd
init|=
name|tsd_get
argument_list|(
name|init
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|init
operator|&&
name|tsd_get_allocates
argument_list|()
operator|&&
name|tsd
operator|==
name|NULL
condition|)
block|{
return|return
name|NULL
return|;
block|}
name|assert
argument_list|(
name|tsd
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|unlikely
argument_list|(
name|tsd
operator|->
name|state
operator|!=
name|tsd_state_nominal
argument_list|)
condition|)
block|{
return|return
name|tsd_fetch_slow
argument_list|(
name|tsd
argument_list|,
name|minimal
argument_list|)
return|;
block|}
name|assert
argument_list|(
name|tsd_fast
argument_list|(
name|tsd
argument_list|)
argument_list|)
expr_stmt|;
name|tsd_assert_fast
argument_list|(
name|tsd
argument_list|)
expr_stmt|;
return|return
name|tsd
return|;
block|}
end_function

begin_comment
comment|/* Get a minimal TSD that requires no cleanup.  See comments in free(). */
end_comment

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|tsd_t
modifier|*
name|tsd_fetch_min
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|tsd_fetch_impl
argument_list|(
name|true
argument_list|,
name|true
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* For internal background threads use only. */
end_comment

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|tsd_t
modifier|*
name|tsd_internal_fetch
parameter_list|(
name|void
parameter_list|)
block|{
name|tsd_t
modifier|*
name|tsd
init|=
name|tsd_fetch_min
argument_list|()
decl_stmt|;
comment|/* Use reincarnated state to prevent full initialization. */
name|tsd
operator|->
name|state
operator|=
name|tsd_state_reincarnated
expr_stmt|;
return|return
name|tsd
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|tsd_t
modifier|*
name|tsd_fetch
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|tsd_fetch_impl
argument_list|(
name|true
argument_list|,
name|false
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|bool
name|tsd_nominal
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
block|{
return|return
operator|(
name|tsd
operator|->
name|state
operator|<=
name|tsd_state_nominal_max
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|tsdn_t
modifier|*
name|tsdn_fetch
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|tsd_booted_get
argument_list|()
condition|)
block|{
return|return
name|NULL
return|;
block|}
return|return
name|tsd_tsdn
argument_list|(
name|tsd_fetch_impl
argument_list|(
name|false
argument_list|,
name|false
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|rtree_ctx_t
modifier|*
name|tsd_rtree_ctx
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
block|{
return|return
name|tsd_rtree_ctxp_get
argument_list|(
name|tsd
argument_list|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|rtree_ctx_t
modifier|*
name|tsdn_rtree_ctx
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|rtree_ctx_t
modifier|*
name|fallback
parameter_list|)
block|{
comment|/* 	 * If tsd cannot be accessed, initialize the fallback rtree_ctx and 	 * return a pointer to it. 	 */
if|if
condition|(
name|unlikely
argument_list|(
name|tsdn_null
argument_list|(
name|tsdn
argument_list|)
argument_list|)
condition|)
block|{
name|rtree_ctx_data_init
argument_list|(
name|fallback
argument_list|)
expr_stmt|;
return|return
name|fallback
return|;
block|}
return|return
name|tsd_rtree_ctx
argument_list|(
name|tsdn_tsd
argument_list|(
name|tsdn
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_TSD_H */
end_comment

end_unit

