begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|ckh_s
name|ckh_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ckhc_s
name|ckhc_t
typedef|;
end_typedef

begin_comment
comment|/* Typedefs to allow easy function pointer passing. */
end_comment

begin_typedef
typedef|typedef
name|void
name|ckh_hash_t
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|bool
name|ckh_keycomp_t
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Maintain counters used to get an idea of performance. */
end_comment

begin_comment
comment|/* #define	CKH_COUNT */
end_comment

begin_comment
comment|/* Print counter values in ckh_delete() (requires CKH_COUNT). */
end_comment

begin_comment
comment|/* #define	CKH_VERBOSE */
end_comment

begin_comment
comment|/*  * There are 2^LG_CKH_BUCKET_CELLS cells in each hash table bucket.  Try to fit  * one bucket per L1 cache line.  */
end_comment

begin_define
define|#
directive|define
name|LG_CKH_BUCKET_CELLS
value|(LG_CACHELINE - LG_SIZEOF_PTR - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_TYPES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_STRUCTS
end_ifdef

begin_comment
comment|/* Hash table cell. */
end_comment

begin_struct
struct|struct
name|ckhc_s
block|{
specifier|const
name|void
modifier|*
name|key
decl_stmt|;
specifier|const
name|void
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ckh_s
block|{
ifdef|#
directive|ifdef
name|CKH_COUNT
comment|/* Counters used to get an idea of performance. */
name|uint64_t
name|ngrows
decl_stmt|;
name|uint64_t
name|nshrinks
decl_stmt|;
name|uint64_t
name|nshrinkfails
decl_stmt|;
name|uint64_t
name|ninserts
decl_stmt|;
name|uint64_t
name|nrelocs
decl_stmt|;
endif|#
directive|endif
comment|/* Used for pseudo-random number generation. */
define|#
directive|define
name|CKH_A
value|1103515241
define|#
directive|define
name|CKH_C
value|12347
name|uint32_t
name|prng_state
decl_stmt|;
comment|/* Total number of items. */
name|size_t
name|count
decl_stmt|;
comment|/* 	 * Minimum and current number of hash table buckets.  There are 	 * 2^LG_CKH_BUCKET_CELLS cells per bucket. 	 */
name|unsigned
name|lg_minbuckets
decl_stmt|;
name|unsigned
name|lg_curbuckets
decl_stmt|;
comment|/* Hash and comparison functions. */
name|ckh_hash_t
modifier|*
name|hash
decl_stmt|;
name|ckh_keycomp_t
modifier|*
name|keycomp
decl_stmt|;
comment|/* Hash table with 2^lg_curbuckets buckets. */
name|ckhc_t
modifier|*
name|tab
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_STRUCTS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_EXTERNS
end_ifdef

begin_function_decl
name|bool
name|ckh_new
parameter_list|(
name|ckh_t
modifier|*
name|ckh
parameter_list|,
name|size_t
name|minitems
parameter_list|,
name|ckh_hash_t
modifier|*
name|hash
parameter_list|,
name|ckh_keycomp_t
modifier|*
name|keycomp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ckh_delete
parameter_list|(
name|ckh_t
modifier|*
name|ckh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|ckh_count
parameter_list|(
name|ckh_t
modifier|*
name|ckh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ckh_iter
parameter_list|(
name|ckh_t
modifier|*
name|ckh
parameter_list|,
name|size_t
modifier|*
name|tabind
parameter_list|,
name|void
modifier|*
modifier|*
name|key
parameter_list|,
name|void
modifier|*
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ckh_insert
parameter_list|(
name|ckh_t
modifier|*
name|ckh
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ckh_remove
parameter_list|(
name|ckh_t
modifier|*
name|ckh
parameter_list|,
specifier|const
name|void
modifier|*
name|searchkey
parameter_list|,
name|void
modifier|*
modifier|*
name|key
parameter_list|,
name|void
modifier|*
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ckh_search
parameter_list|(
name|ckh_t
modifier|*
name|ckh
parameter_list|,
specifier|const
name|void
modifier|*
name|seachkey
parameter_list|,
name|void
modifier|*
modifier|*
name|key
parameter_list|,
name|void
modifier|*
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ckh_string_hash
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|size_t
name|r_hash
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ckh_string_keycomp
parameter_list|(
specifier|const
name|void
modifier|*
name|k1
parameter_list|,
specifier|const
name|void
modifier|*
name|k2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ckh_pointer_hash
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|size_t
name|r_hash
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ckh_pointer_keycomp
parameter_list|(
specifier|const
name|void
modifier|*
name|k1
parameter_list|,
specifier|const
name|void
modifier|*
name|k2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_EXTERNS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_INLINES
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_INLINES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

end_unit

