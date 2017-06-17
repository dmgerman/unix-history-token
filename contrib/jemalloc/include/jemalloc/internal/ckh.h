begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_CKH_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_CKH_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/tsd.h"
end_include

begin_comment
comment|/* Cuckoo hashing implementation.  Skip to the end for the interface. */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* INTERNAL DEFINITIONS -- IGNORE */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* Maintain counters used to get an idea of performance. */
end_comment

begin_comment
comment|/* #define CKH_COUNT */
end_comment

begin_comment
comment|/* Print counter values in ckh_delete() (requires CKH_COUNT). */
end_comment

begin_comment
comment|/* #define CKH_VERBOSE */
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
comment|/* Hash table cell. */
end_comment

begin_typedef
typedef|typedef
struct|struct
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
name|ckhc_t
typedef|;
end_typedef

begin_comment
comment|/* The hash table itself. */
end_comment

begin_typedef
typedef|typedef
struct|struct
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
name|uint64_t
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
name|ckh_t
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* BEGIN PUBLIC API */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* Lifetime management.  Minitems is the initial capacity. */
end_comment

begin_function_decl
name|bool
name|ckh_new
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
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
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|ckh_t
modifier|*
name|ckh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the number of elements in the set. */
end_comment

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

begin_comment
comment|/*  * To iterate over the elements in the table, initialize *tabind to 0 and call  * this function until it returns true.  Each call that returns false will  * update *key and *data to the next element in the table, assuming the pointers  * are non-NULL.  */
end_comment

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

begin_comment
comment|/*  * Basic hash table operations -- insert, removal, lookup.  For ckh_remove and  * ckh_search, key or data can be NULL.  The hash-table only stores pointers to  * the key and value, and doesn't do any lifetime management.  */
end_comment

begin_function_decl
name|bool
name|ckh_insert
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
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
name|tsd_t
modifier|*
name|tsd
parameter_list|,
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

begin_comment
comment|/* Some useful hash and comparison functions for strings and pointers. */
end_comment

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
comment|/* JEMALLOC_INTERNAL_CKH_H */
end_comment

end_unit

