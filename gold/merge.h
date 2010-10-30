begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// merge.h -- handle section merging for gold  -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_MERGE_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_MERGE_H
end_define

begin_include
include|#
directive|include
file|<climits>
end_include

begin_include
include|#
directive|include
file|"stringpool.h"
end_include

begin_include
include|#
directive|include
file|"output.h"
end_include

begin_decl_stmt
name|namespace
name|gold
block|{
comment|// A general class for SHF_MERGE data, to hold functions shared by
comment|// fixed-size constant data and string data.
name|class
name|Output_merge_base
range|:
name|public
name|Output_section_data
block|{
name|public
operator|:
name|Output_merge_base
argument_list|(
argument|uint64_t entsize
argument_list|)
operator|:
name|Output_section_data
argument_list|(
literal|1
argument_list|)
block|,
name|merge_map_
argument_list|()
block|,
name|entsize_
argument_list|(
argument|entsize
argument_list|)
block|{ }
comment|// Return the output address for an input address.
name|bool
name|do_output_address
argument_list|(
argument|const Relobj* object
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|off_t offset
argument_list|,
argument|uint64_t output_section_address
argument_list|,
argument|uint64_t* poutput
argument_list|)
specifier|const
block|;
name|protected
operator|:
comment|// Return the entry size.
name|uint64_t
name|entsize
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|entsize_
return|;
block|}
comment|// Add a mapping from an OFFSET in input section SHNDX in object
comment|// OBJECT to an OUTPUT_OFFSET in the output section.
name|void
name|add_mapping
argument_list|(
argument|Relobj* object
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|off_t offset
argument_list|,
argument|off_t output_offset
argument_list|)
block|;
name|private
operator|:
comment|// We build a mapping from OBJECT/SHNDX/OFFSET to an offset in the
comment|// output section.
expr|struct
name|Merge_key
block|{
specifier|const
name|Relobj
operator|*
name|object
block|;
name|unsigned
name|int
name|shndx
block|;
name|off_t
name|offset
block|;   }
block|;    struct
name|Merge_key_less
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Merge_key
operator|&
expr|,
specifier|const
name|Merge_key
operator|&
operator|)
specifier|const
block|;   }
block|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|Merge_key
operator|,
name|off_t
operator|,
name|Merge_key_less
operator|>
name|Merge_map
expr_stmt|;
comment|// A mapping from input object/section/offset to offset in output
comment|// section.
name|Merge_map
name|merge_map_
decl_stmt|;
comment|// The entry size.  For fixed-size constants, this is the size of
comment|// the constants.  For strings, this is the size of a character.
name|uint64_t
name|entsize_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Handle SHF_MERGE sections with fixed-size constant data.
end_comment

begin_decl_stmt
name|class
name|Output_merge_data
range|:
name|public
name|Output_merge_base
block|{
name|public
operator|:
name|Output_merge_data
argument_list|(
argument|uint64_t entsize
argument_list|)
operator|:
name|Output_merge_base
argument_list|(
name|entsize
argument_list|)
block|,
name|p_
argument_list|(
name|NULL
argument_list|)
block|,
name|len_
argument_list|(
literal|0
argument_list|)
block|,
name|alc_
argument_list|(
literal|0
argument_list|)
block|,
name|hashtable_
argument_list|(
literal|128
argument_list|,
argument|Merge_data_hash(this)
argument_list|,
argument|Merge_data_eq(this)
argument_list|)
block|{ }
comment|// Add an input section.
name|bool
name|do_add_input_section
argument_list|(
argument|Relobj* object
argument_list|,
argument|unsigned int shndx
argument_list|)
block|;
comment|// Set the final data size.
name|void
name|do_set_address
argument_list|(
name|uint64_t
argument_list|,
name|off_t
argument_list|)
block|;
comment|// Write the data to the file.
name|void
name|do_write
argument_list|(
name|Output_file
operator|*
argument_list|)
block|;
name|private
operator|:
comment|// We build a hash table of the fixed-size constants.  Each constant
comment|// is stored as a pointer into the section data we are accumulating.
comment|// A key in the hash table.  This is an offset in the section
comment|// contents we are building.
typedef|typedef
name|off_t
name|Merge_data_key
typedef|;
comment|// Compute the hash code.  To do this we need a pointer back to the
comment|// object holding the data.
name|class
name|Merge_data_hash
block|{
name|public
operator|:
name|Merge_data_hash
argument_list|(
specifier|const
name|Output_merge_data
operator|*
name|pomd
argument_list|)
operator|:
name|pomd_
argument_list|(
argument|pomd
argument_list|)
block|{ }
name|size_t
name|operator
argument_list|()
operator|(
name|Merge_data_key
operator|)
specifier|const
block|;
name|private
operator|:
specifier|const
name|Output_merge_data
operator|*
name|pomd_
block|;   }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|Merge_data_hash
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Compare two entries in the hash table for equality.  To do this
end_comment

begin_comment
comment|// we need a pointer back to the object holding the data.  Note that
end_comment

begin_comment
comment|// we now have a pointer to the object stored in two places in the
end_comment

begin_comment
comment|// hash table.  Fixing this would require specializing the hash
end_comment

begin_comment
comment|// table, which would be hard to do portably.
end_comment

begin_decl_stmt
name|class
name|Merge_data_eq
block|{
name|public
label|:
name|Merge_data_eq
argument_list|(
specifier|const
name|Output_merge_data
operator|*
name|pomd
argument_list|)
operator|:
name|pomd_
argument_list|(
argument|pomd
argument_list|)
block|{ }
name|bool
name|operator
argument_list|()
operator|(
name|Merge_data_key
name|k1
operator|,
name|Merge_data_key
name|k2
operator|)
specifier|const
expr_stmt|;
name|private
label|:
specifier|const
name|Output_merge_data
modifier|*
name|pomd_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|friend
name|class
name|Merge_data_eq
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The type of the hash table.
end_comment

begin_typedef
typedef|typedef
name|Unordered_set
operator|<
name|Merge_data_key
operator|,
name|Merge_data_hash
operator|,
name|Merge_data_eq
operator|>
name|Merge_data_hashtable
expr_stmt|;
end_typedef

begin_comment
comment|// Given a hash table key, which is just an offset into the section
end_comment

begin_comment
comment|// data, return a pointer to the corresponding constant.
end_comment

begin_decl_stmt
specifier|const
name|unsigned
name|char
modifier|*
name|constant
argument_list|(
name|Merge_data_key
name|k
argument_list|)
decl|const
block|{
name|gold_assert
argument_list|(
name|k
operator|>=
literal|0
operator|&&
name|k
operator|<
name|this
operator|->
name|len_
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|p_
operator|+
name|k
return|;
block|}
end_decl_stmt

begin_comment
comment|// Add a constant to the output.
end_comment

begin_function_decl
name|void
name|add_constant
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// The accumulated data.
end_comment

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|p_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The length of the accumulated data.
end_comment

begin_decl_stmt
name|off_t
name|len_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The size of the allocated buffer.
end_comment

begin_decl_stmt
name|size_t
name|alc_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The hash table.
end_comment

begin_decl_stmt
name|Merge_data_hashtable
name|hashtable_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Handle SHF_MERGE sections with string data.  This is a template
end_comment

begin_comment
comment|// based on the type of the characters in the string.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Char_type
operator|>
name|class
name|Output_merge_string
operator|:
name|public
name|Output_merge_base
block|{
name|public
operator|:
name|Output_merge_string
argument_list|()
operator|:
name|Output_merge_base
argument_list|(
sizeof|sizeof
argument_list|(
name|Char_type
argument_list|)
argument_list|)
block|,
name|stringpool_
argument_list|(
name|false
argument_list|)
block|,
name|hashtable_
argument_list|()
block|{ }
comment|// Add an input section.
name|bool
name|do_add_input_section
argument_list|(
argument|Relobj* object
argument_list|,
argument|unsigned int shndx
argument_list|)
block|;
comment|// Set the final data size.
name|void
name|do_set_address
argument_list|(
name|uint64_t
argument_list|,
name|off_t
argument_list|)
block|;
comment|// Write the data to the file.
name|void
name|do_write
argument_list|(
name|Output_file
operator|*
argument_list|)
block|;
name|private
operator|:
comment|// As we see input sections, we build a mapping from object, section
comment|// index and offset to strings.
expr|struct
name|Merge_string_key
block|{
name|Relobj
operator|*
name|object
block|;
name|unsigned
name|int
name|shndx
block|;
name|off_t
name|offset
block|;
name|Merge_string_key
argument_list|(
argument|Relobj *objecta
argument_list|,
argument|unsigned int shndxa
argument_list|,
argument|off_t offseta
argument_list|)
operator|:
name|object
argument_list|(
name|objecta
argument_list|)
block|,
name|shndx
argument_list|(
name|shndxa
argument_list|)
block|,
name|offset
argument_list|(
argument|offseta
argument_list|)
block|{ }
block|}
block|;    struct
name|Merge_string_key_hash
block|{
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|Merge_string_key
operator|&
operator|)
specifier|const
block|;   }
block|;    struct
name|Merge_string_key_eq
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Merge_string_key
operator|&
operator|,
specifier|const
name|Merge_string_key
operator|&
operator|)
specifier|const
block|;   }
block|;
typedef|typedef
name|Unordered_map
operator|<
name|Merge_string_key
operator|,
specifier|const
name|Char_type
operator|*
operator|,
name|Merge_string_key_hash
operator|,
name|Merge_string_key_eq
operator|>
name|Merge_string_hashtable
expr_stmt|;
comment|// As we see the strings, we add them to a Stringpool.
name|Stringpool_template
operator|<
name|Char_type
operator|>
name|stringpool_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Map from a location in an input object to an entry in the
end_comment

begin_comment
comment|// Stringpool.
end_comment

begin_decl_stmt
name|Merge_string_hashtable
name|hashtable_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_MERGE_H)
end_comment

end_unit

