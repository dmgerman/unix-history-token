begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hash.h -- the data structures used in hashing in Bash. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_HASH_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HASH_H_
end_define

begin_typedef
typedef|typedef
struct|struct
name|bucket_contents
block|{
name|struct
name|bucket_contents
modifier|*
name|next
decl_stmt|;
comment|/* Link to next hashed key in this bucket. */
name|char
modifier|*
name|key
decl_stmt|;
comment|/* What we look up. */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* What we really want. */
name|int
name|times_found
decl_stmt|;
comment|/* Number of times this item has been found. */
block|}
name|BUCKET_CONTENTS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hash_table
block|{
name|BUCKET_CONTENTS
modifier|*
modifier|*
name|bucket_array
decl_stmt|;
comment|/* Where the data is kept. */
name|int
name|nbuckets
decl_stmt|;
comment|/* How many buckets does this table have. */
name|int
name|nentries
decl_stmt|;
comment|/* How many entries does this table have. */
block|}
name|HASH_TABLE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|BUCKET_CONTENTS
modifier|*
name|find_hash_item
argument_list|()
decl_stmt|,
modifier|*
name|remove_hash_item
argument_list|()
decl_stmt|,
modifier|*
name|add_hash_item
argument_list|()
decl_stmt|,
modifier|*
name|get_hash_bucket
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|hash_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HASH_TABLE
modifier|*
name|make_hash_table
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Default number of buckets in the hash table. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_HASH_BUCKETS
value|107
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0x0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HASH_H */
end_comment

end_unit

