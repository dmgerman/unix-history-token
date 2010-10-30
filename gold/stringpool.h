begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// stringpool.h -- a string pool for gold    -*- C++ -*-
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_comment
comment|// Stringpool
end_comment

begin_comment
comment|//   Manage a pool of unique strings.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_STRINGPOOL_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_STRINGPOOL_H
end_define

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|Output_file
decl_stmt|;
name|template
operator|<
name|typename
name|Stringpool_char
operator|>
name|class
name|Stringpool_template
block|{
name|public
operator|:
comment|// The type of a key into the stringpool.  A key value will always
comment|// be the same during any run of the linker.  The string pointers
comment|// may change when using address space randomization.  We use key
comment|// values in order to get repeatable runs when the value is inserted
comment|// into an unordered hash table.  Zero is never a valid key.
typedef|typedef
name|size_t
name|Key
typedef|;
comment|// Create a Stringpool.  ZERO_NULL is true if we should reserve
comment|// offset 0 to hold the empty string.
name|Stringpool_template
argument_list|(
argument|bool zero_null = true
argument_list|)
expr_stmt|;
operator|~
name|Stringpool_template
argument_list|()
expr_stmt|;
comment|// Add a string to the pool.  This returns a canonical permanent
comment|// pointer to the string.  If PKEY is not NULL, this sets *PKEY to
comment|// the key for the string.
specifier|const
name|Stringpool_char
modifier|*
name|add
parameter_list|(
specifier|const
name|Stringpool_char
modifier|*
parameter_list|,
name|Key
modifier|*
name|pkey
parameter_list|)
function_decl|;
specifier|const
name|Stringpool_char
modifier|*
name|add
argument_list|(
specifier|const
name|std
operator|::
name|basic_string
operator|<
name|Stringpool_char
operator|>
operator|&
name|s
argument_list|,
name|Key
operator|*
name|pkey
argument_list|)
block|{
return|return
name|this
operator|->
name|add
argument_list|(
name|s
operator|.
name|c_str
argument_list|()
argument_list|,
name|pkey
argument_list|)
return|;
block|}
comment|// Add the prefix of a string to the pool.
specifier|const
name|Stringpool_char
modifier|*
name|add
parameter_list|(
specifier|const
name|Stringpool_char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|Key
modifier|*
name|pkey
parameter_list|)
function_decl|;
comment|// If a string is present, return the canonical string.  Otherwise,
comment|// return NULL.  If PKEY is not NULL, set *PKEY to the key.
specifier|const
name|Stringpool_char
modifier|*
name|find
argument_list|(
specifier|const
name|Stringpool_char
operator|*
argument_list|,
name|Key
operator|*
name|pkey
argument_list|)
decl|const
decl_stmt|;
comment|// Turn the stringpool into an ELF strtab: determine the offsets of
comment|// all the strings.
name|void
name|set_string_offsets
parameter_list|()
function_decl|;
comment|// Get the offset of a string in an ELF strtab.  This returns the
comment|// offset in bytes, not characters.
name|off_t
name|get_offset
argument_list|(
specifier|const
name|Stringpool_char
operator|*
argument_list|)
decl|const
decl_stmt|;
name|off_t
name|get_offset
argument_list|(
specifier|const
name|std
operator|::
name|basic_string
operator|<
name|Stringpool_char
operator|>
operator|&
name|s
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|get_offset
argument_list|(
name|s
operator|.
name|c_str
argument_list|()
argument_list|)
return|;
block|}
comment|// Get the size of the ELF strtab.  This returns the number of
comment|// bytes, not characters.
name|off_t
name|get_strtab_size
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|strtab_size_
operator|!=
literal|0
argument_list|)
block|;
return|return
name|this
operator|->
name|strtab_size_
return|;
block|}
comment|// Write the strtab into the output file at the specified offset.
name|void
name|write
parameter_list|(
name|Output_file
modifier|*
parameter_list|,
name|off_t
name|offset
parameter_list|)
function_decl|;
name|private
label|:
name|Stringpool_template
argument_list|(
specifier|const
name|Stringpool_template
operator|&
argument_list|)
expr_stmt|;
name|Stringpool_template
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Stringpool_template
operator|&
operator|)
decl_stmt|;
comment|// Return the length of a string.
specifier|static
name|size_t
name|string_length
parameter_list|(
specifier|const
name|Stringpool_char
modifier|*
parameter_list|)
function_decl|;
comment|// We store the actual data in a list of these buffers.
struct|struct
name|Stringdata
block|{
comment|// Length of data in buffer.
name|size_t
name|len
decl_stmt|;
comment|// Allocated size of buffer.
name|size_t
name|alc
decl_stmt|;
comment|// Buffer index.
name|unsigned
name|int
name|index
decl_stmt|;
comment|// Buffer.
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
comment|// Copy a string into the buffers, returning a canonical string.
specifier|const
name|Stringpool_char
modifier|*
name|add_string
parameter_list|(
specifier|const
name|Stringpool_char
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|)
function_decl|;
struct|struct
name|Stringpool_hash
block|{
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|Stringpool_char
operator|*
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
struct|struct
name|Stringpool_eq
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Stringpool_char
operator|*
name|p1
operator|,
specifier|const
name|Stringpool_char
operator|*
name|p2
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
comment|// Return whether s1 is a suffix of s2.
specifier|static
name|bool
name|is_suffix
parameter_list|(
specifier|const
name|Stringpool_char
modifier|*
name|s1
parameter_list|,
specifier|const
name|Stringpool_char
modifier|*
name|s2
parameter_list|)
function_decl|;
comment|// The hash table is a map from string names to a pair of Key and
comment|// ELF strtab offsets.  We only use the offsets if we turn this into
comment|// an ELF strtab section.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|Key
operator|,
name|off_t
operator|>
name|Val
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_TR1_UNORDERED_SET
typedef|typedef
name|Unordered_map
operator|<
specifier|const
name|Stringpool_char
operator|*
operator|,
name|Val
operator|,
name|Stringpool_hash
operator|,
name|Stringpool_eq
operator|,
name|std
operator|::
name|allocator
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|Stringpool_char
operator|*
specifier|const
operator|,
name|Val
operator|>
expr|>
operator|,
name|true
operator|>
name|String_set_type
expr_stmt|;
else|#
directive|else
typedef|typedef
name|Unordered_map
operator|<
specifier|const
name|Stringpool_char
operator|*
operator|,
name|Val
operator|,
name|Stringpool_hash
operator|,
name|Stringpool_eq
operator|>
name|String_set_type
expr_stmt|;
endif|#
directive|endif
comment|// Comparison routine used when sorting into an ELF strtab.
struct|struct
name|Stringpool_sort_comparison
block|{
name|bool
name|operator
argument_list|()
operator|(
name|typename
name|String_set_type
operator|::
name|iterator
operator|,
name|typename
name|String_set_type
operator|::
name|iterator
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
comment|// List of Stringdata structures.
typedef|typedef
name|std
operator|::
name|list
operator|<
name|Stringdata
operator|*
operator|>
name|Stringdata_list
expr_stmt|;
comment|// Mapping from const char* to namepool entry.
name|String_set_type
name|string_set_
decl_stmt|;
comment|// List of buffers.
name|Stringdata_list
name|strings_
decl_stmt|;
comment|// Size of ELF strtab.
name|off_t
name|strtab_size_
decl_stmt|;
comment|// Next Stringdata index.
name|unsigned
name|int
name|next_index_
decl_stmt|;
comment|// Whether to reserve offset 0 to hold the null string.
name|bool
name|zero_null_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// The most common type of Stringpool.
end_comment

begin_typedef
typedef|typedef
name|Stringpool_template
operator|<
name|char
operator|>
name|Stringpool
expr_stmt|;
end_typedef

begin_comment
unit|}
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_STRINGPOOL_H)
end_comment

end_unit

