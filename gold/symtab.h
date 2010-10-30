begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// symtab.h -- the gold symbol table   -*- C++ -*-
end_comment

begin_comment
comment|// Symbol_table
end_comment

begin_comment
comment|//   The symbol table.
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"elfcpp.h"
end_include

begin_include
include|#
directive|include
file|"stringpool.h"
end_include

begin_include
include|#
directive|include
file|"object.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_SYMTAB_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_SYMTAB_H
end_define

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|Object
decl_stmt|;
name|class
name|Relobj
decl_stmt|;
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|class
name|Sized_relobj
expr_stmt|;
name|class
name|Dynobj
decl_stmt|;
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|class
name|Sized_dynobj
expr_stmt|;
name|class
name|Versions
decl_stmt|;
name|class
name|Output_data
decl_stmt|;
name|class
name|Output_section
decl_stmt|;
name|class
name|Output_segment
decl_stmt|;
name|class
name|Output_file
decl_stmt|;
name|class
name|Target
decl_stmt|;
comment|// The base class of an entry in the symbol table.  The symbol table
comment|// can have a lot of entries, so we don't want this class to big.
comment|// Size dependent fields can be found in the template class
comment|// Sized_symbol.  Targets may support their own derived classes.
name|class
name|Symbol
block|{
name|public
label|:
comment|// Because we want the class to be small, we don't use any virtual
comment|// functions.  But because symbols can be defined in different
comment|// places, we need to classify them.  This enum is the different
comment|// sources of symbols we support.
enum|enum
name|Source
block|{
comment|// Symbol defined in a relocatable or dynamic input file--this is
comment|// the most common case.
name|FROM_OBJECT
block|,
comment|// Symbol defined in an Output_data, a special section created by
comment|// the target.
name|IN_OUTPUT_DATA
block|,
comment|// Symbol defined in an Output_segment, with no associated
comment|// section.
name|IN_OUTPUT_SEGMENT
block|,
comment|// Symbol value is constant.
name|CONSTANT
block|}
enum|;
comment|// When the source is IN_OUTPUT_SEGMENT, we need to describe what
comment|// the offset means.
enum|enum
name|Segment_offset_base
block|{
comment|// From the start of the segment.
name|SEGMENT_START
block|,
comment|// From the end of the segment.
name|SEGMENT_END
block|,
comment|// From the filesz of the segment--i.e., after the loaded bytes
comment|// but before the bytes which are allocated but zeroed.
name|SEGMENT_BSS
block|}
enum|;
comment|// Return the symbol name.
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|name_
return|;
block|}
comment|// Return the symbol version.  This will return NULL for an
comment|// unversioned symbol.
specifier|const
name|char
operator|*
name|version
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|version_
return|;
block|}
comment|// Return the symbol source.
name|Source
name|source
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|source_
return|;
block|}
comment|// Return the object with which this symbol is associated.
name|Object
operator|*
name|object
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|source_
operator|==
name|FROM_OBJECT
argument_list|)
block|;
return|return
name|this
operator|->
name|u_
operator|.
name|from_object
operator|.
name|object
return|;
block|}
comment|// Return the index of the section in the input relocatable or
comment|// dynamic object file.
name|unsigned
name|int
name|shndx
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|source_
operator|==
name|FROM_OBJECT
argument_list|)
block|;
return|return
name|this
operator|->
name|u_
operator|.
name|from_object
operator|.
name|shndx
return|;
block|}
comment|// Return the output data section with which this symbol is
comment|// associated, if the symbol was specially defined with respect to
comment|// an output data section.
name|Output_data
operator|*
name|output_data
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|source_
operator|==
name|IN_OUTPUT_DATA
argument_list|)
block|;
return|return
name|this
operator|->
name|u_
operator|.
name|in_output_data
operator|.
name|output_data
return|;
block|}
comment|// If this symbol was defined with respect to an output data
comment|// section, return whether the value is an offset from end.
name|bool
name|offset_is_from_end
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|source_
operator|==
name|IN_OUTPUT_DATA
argument_list|)
block|;
return|return
name|this
operator|->
name|u_
operator|.
name|in_output_data
operator|.
name|offset_is_from_end
return|;
block|}
comment|// Return the output segment with which this symbol is associated,
comment|// if the symbol was specially defined with respect to an output
comment|// segment.
name|Output_segment
operator|*
name|output_segment
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|source_
operator|==
name|IN_OUTPUT_SEGMENT
argument_list|)
block|;
return|return
name|this
operator|->
name|u_
operator|.
name|in_output_segment
operator|.
name|output_segment
return|;
block|}
comment|// If this symbol was defined with respect to an output segment,
comment|// return the offset base.
name|Segment_offset_base
name|offset_base
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|source_
operator|==
name|IN_OUTPUT_SEGMENT
argument_list|)
block|;
return|return
name|this
operator|->
name|u_
operator|.
name|in_output_segment
operator|.
name|offset_base
return|;
block|}
comment|// Return the symbol binding.
name|elfcpp
operator|::
name|STB
name|binding
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|binding_
return|;
block|}
comment|// Return the symbol type.
name|elfcpp
operator|::
name|STT
name|type
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|type_
return|;
block|}
comment|// Return the symbol visibility.
name|elfcpp
operator|::
name|STV
name|visibility
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|visibility_
return|;
block|}
comment|// Return the non-visibility part of the st_other field.
name|unsigned
name|char
name|nonvis
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|nonvis_
return|;
block|}
comment|// Return whether this symbol is a forwarder.  This will never be
comment|// true of a symbol found in the hash table, but may be true of
comment|// symbol pointers attached to object files.
name|bool
name|is_forwarder
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|is_forwarder_
return|;
block|}
comment|// Mark this symbol as a forwarder.
name|void
name|set_forwarder
parameter_list|()
block|{
name|this
operator|->
name|is_forwarder_
operator|=
name|true
expr_stmt|;
block|}
comment|// Return whether this symbol needs an entry in the dynamic symbol
comment|// table.
name|bool
name|needs_dynsym_entry
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|needs_dynsym_entry_
return|;
block|}
comment|// Mark this symbol as needing an entry in the dynamic symbol table.
name|void
name|set_needs_dynsym_entry
parameter_list|()
block|{
name|this
operator|->
name|needs_dynsym_entry_
operator|=
name|true
expr_stmt|;
block|}
comment|// Return whether this symbol has been seen in a regular object.
name|bool
name|in_reg
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|in_reg_
return|;
block|}
comment|// Mark this symbol as having been seen in a regular object.
name|void
name|set_in_reg
parameter_list|()
block|{
name|this
operator|->
name|in_reg_
operator|=
name|true
expr_stmt|;
block|}
comment|// Mark this symbol as having been seen in a dynamic object.
name|void
name|set_in_dyn
parameter_list|()
block|{
name|this
operator|->
name|in_dyn_
operator|=
name|true
expr_stmt|;
block|}
comment|// Return the index of this symbol in the output file symbol table.
comment|// A value of -1U means that this symbol is not going into the
comment|// output file.  This starts out as zero, and is set to a non-zero
comment|// value by Symbol_table::finalize.  It is an error to ask for the
comment|// symbol table index before it has been set.
name|unsigned
name|int
name|symtab_index
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|symtab_index_
operator|!=
literal|0
argument_list|)
block|;
return|return
name|this
operator|->
name|symtab_index_
return|;
block|}
comment|// Set the index of the symbol in the output file symbol table.
name|void
name|set_symtab_index
parameter_list|(
name|unsigned
name|int
name|index
parameter_list|)
block|{
name|gold_assert
argument_list|(
name|index
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|this
operator|->
name|symtab_index_
operator|=
name|index
expr_stmt|;
block|}
comment|// Return whether this symbol already has an index in the output
comment|// file symbol table.
name|bool
name|has_symtab_index
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|symtab_index_
operator|!=
literal|0
return|;
block|}
comment|// Return the index of this symbol in the dynamic symbol table.  A
comment|// value of -1U means that this symbol is not going into the dynamic
comment|// symbol table.  This starts out as zero, and is set to a non-zero
comment|// during Layout::finalize.  It is an error to ask for the dynamic
comment|// symbol table index before it has been set.
name|unsigned
name|int
name|dynsym_index
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|dynsym_index_
operator|!=
literal|0
argument_list|)
block|;
return|return
name|this
operator|->
name|dynsym_index_
return|;
block|}
comment|// Set the index of the symbol in the dynamic symbol table.
name|void
name|set_dynsym_index
parameter_list|(
name|unsigned
name|int
name|index
parameter_list|)
block|{
name|gold_assert
argument_list|(
name|index
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|this
operator|->
name|dynsym_index_
operator|=
name|index
expr_stmt|;
block|}
comment|// Return whether this symbol already has an index in the dynamic
comment|// symbol table.
name|bool
name|has_dynsym_index
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|dynsym_index_
operator|!=
literal|0
return|;
block|}
comment|// Return whether this symbol has an entry in the GOT section.
name|bool
name|has_got_offset
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|has_got_offset_
return|;
block|}
comment|// Return the offset into the GOT section of this symbol.
name|unsigned
name|int
name|got_offset
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|has_got_offset
argument_list|()
argument_list|)
block|;
return|return
name|this
operator|->
name|got_offset_
return|;
block|}
comment|// Set the GOT offset of this symbol.
name|void
name|set_got_offset
parameter_list|(
name|unsigned
name|int
name|got_offset
parameter_list|)
block|{
name|this
operator|->
name|has_got_offset_
operator|=
name|true
expr_stmt|;
name|this
operator|->
name|got_offset_
operator|=
name|got_offset
expr_stmt|;
block|}
comment|// Return whether this symbol has an entry in the PLT section.
name|bool
name|has_plt_offset
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|has_plt_offset_
return|;
block|}
comment|// Return the offset into the PLT section of this symbol.
name|unsigned
name|int
name|plt_offset
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|has_plt_offset
argument_list|()
argument_list|)
block|;
return|return
name|this
operator|->
name|plt_offset_
return|;
block|}
comment|// Set the PLT offset of this symbol.
name|void
name|set_plt_offset
parameter_list|(
name|unsigned
name|int
name|plt_offset
parameter_list|)
block|{
name|this
operator|->
name|has_plt_offset_
operator|=
name|true
expr_stmt|;
name|this
operator|->
name|plt_offset_
operator|=
name|plt_offset
expr_stmt|;
block|}
comment|// Return true if the final value of this symbol is known at link
comment|// time.
name|bool
name|final_value_is_known
argument_list|(
specifier|const
name|General_options
operator|*
name|options
argument_list|)
decl|const
block|{
if|if
condition|(
name|options
operator|->
name|is_shared
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|this
operator|->
name|source_
operator|!=
name|FROM_OBJECT
operator|||
operator|!
name|this
operator|->
name|object
argument_list|()
operator|->
name|is_dynamic
argument_list|()
return|;
block|}
comment|// Return whether this is a defined symbol (not undefined or
comment|// common).
name|bool
name|is_defined
argument_list|()
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|source_
operator|!=
name|FROM_OBJECT
operator|||
operator|(
name|this
operator|->
name|shndx
argument_list|()
operator|!=
name|elfcpp
operator|::
name|SHN_UNDEF
operator|&&
name|this
operator|->
name|shndx
argument_list|()
operator|!=
name|elfcpp
operator|::
name|SHN_COMMON
operator|)
operator|)
return|;
block|}
comment|// Return true if this symbol is from a dynamic object.
name|bool
name|is_from_dynobj
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|source_
operator|==
name|FROM_OBJECT
operator|&&
name|this
operator|->
name|object
argument_list|()
operator|->
name|is_dynamic
argument_list|()
return|;
block|}
comment|// Return whether this is an undefined symbol.
name|bool
name|is_undefined
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|source_
operator|==
name|FROM_OBJECT
operator|&&
name|this
operator|->
name|shndx
argument_list|()
operator|==
name|elfcpp
operator|::
name|SHN_UNDEF
return|;
block|}
comment|// Return whether this is a common symbol.
name|bool
name|is_common
argument_list|()
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|source_
operator|==
name|FROM_OBJECT
operator|&&
operator|(
name|this
operator|->
name|shndx
argument_list|()
operator|==
name|elfcpp
operator|::
name|SHN_COMMON
operator|||
name|this
operator|->
name|type_
operator|==
name|elfcpp
operator|::
name|STT_COMMON
operator|)
operator|)
return|;
block|}
comment|// Return whether there should be a warning for references to this
comment|// symbol.
name|bool
name|has_warning
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|has_warning_
return|;
block|}
comment|// Mark this symbol as having a warning.
name|void
name|set_has_warning
parameter_list|()
block|{
name|this
operator|->
name|has_warning_
operator|=
name|true
expr_stmt|;
block|}
name|protected
label|:
comment|// Instances of this class should always be created at a specific
comment|// size.
name|Symbol
argument_list|()
block|{
name|memset
argument_list|(
name|this
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
expr|*
name|this
argument_list|)
expr_stmt|;
block|}
comment|// Initialize the general fields.
name|void
name|init_fields
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|version
argument_list|,
name|elfcpp
operator|::
name|STT
name|type
argument_list|,
name|elfcpp
operator|::
name|STB
name|binding
argument_list|,
name|elfcpp
operator|::
name|STV
name|visibility
argument_list|,
name|unsigned
name|char
name|nonvis
argument_list|)
decl_stmt|;
comment|// Initialize fields from an ELF symbol in OBJECT.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|init_base
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|version
argument_list|,
name|Object
operator|*
name|object
argument_list|,
specifier|const
name|elfcpp
operator|::
name|Sym
operator|<
name|size
argument_list|,
name|big_endian
operator|>
operator|&
argument_list|)
expr_stmt|;
comment|// Initialize fields for an Output_data.
name|void
name|init_base
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|Output_data
operator|*
argument_list|,
name|elfcpp
operator|::
name|STT
argument_list|,
name|elfcpp
operator|::
name|STB
argument_list|,
name|elfcpp
operator|::
name|STV
argument_list|,
name|unsigned
name|char
name|nonvis
argument_list|,
name|bool
name|offset_is_from_end
argument_list|)
decl_stmt|;
comment|// Initialize fields for an Output_segment.
name|void
name|init_base
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|Output_segment
operator|*
name|os
argument_list|,
name|elfcpp
operator|::
name|STT
name|type
argument_list|,
name|elfcpp
operator|::
name|STB
name|binding
argument_list|,
name|elfcpp
operator|::
name|STV
name|visibility
argument_list|,
name|unsigned
name|char
name|nonvis
argument_list|,
name|Segment_offset_base
name|offset_base
argument_list|)
decl_stmt|;
comment|// Initialize fields for a constant.
name|void
name|init_base
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|elfcpp
operator|::
name|STT
name|type
argument_list|,
name|elfcpp
operator|::
name|STB
name|binding
argument_list|,
name|elfcpp
operator|::
name|STV
name|visibility
argument_list|,
name|unsigned
name|char
name|nonvis
argument_list|)
decl_stmt|;
comment|// Override existing symbol.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|override_base
argument_list|(
specifier|const
name|elfcpp
operator|::
name|Sym
operator|<
name|size
argument_list|,
name|big_endian
operator|>
operator|&
argument_list|,
name|Object
operator|*
name|object
argument_list|,
specifier|const
name|char
operator|*
name|version
argument_list|)
expr_stmt|;
name|private
label|:
name|Symbol
argument_list|(
specifier|const
name|Symbol
operator|&
argument_list|)
expr_stmt|;
name|Symbol
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Symbol
operator|&
operator|)
decl_stmt|;
comment|// Symbol name (expected to point into a Stringpool).
specifier|const
name|char
modifier|*
name|name_
decl_stmt|;
comment|// Symbol version (expected to point into a Stringpool).  This may
comment|// be NULL.
specifier|const
name|char
modifier|*
name|version_
decl_stmt|;
union|union
block|{
comment|// This struct is used if SOURCE_ == FROM_OBJECT.
struct|struct
block|{
comment|// Object in which symbol is defined, or in which it was first
comment|// seen.
name|Object
modifier|*
name|object
decl_stmt|;
comment|// Section number in object_ in which symbol is defined.
name|unsigned
name|int
name|shndx
decl_stmt|;
block|}
name|from_object
struct|;
comment|// This struct is used if SOURCE_ == IN_OUTPUT_DATA.
struct|struct
block|{
comment|// Output_data in which symbol is defined.  Before
comment|// Layout::finalize the symbol's value is an offset within the
comment|// Output_data.
name|Output_data
modifier|*
name|output_data
decl_stmt|;
comment|// True if the offset is from the end, false if the offset is
comment|// from the beginning.
name|bool
name|offset_is_from_end
decl_stmt|;
block|}
name|in_output_data
struct|;
comment|// This struct is used if SOURCE_ == IN_OUTPUT_SEGMENT.
struct|struct
block|{
comment|// Output_segment in which the symbol is defined.  Before
comment|// Layout::finalize the symbol's value is an offset.
name|Output_segment
modifier|*
name|output_segment
decl_stmt|;
comment|// The base to use for the offset before Layout::finalize.
name|Segment_offset_base
name|offset_base
decl_stmt|;
block|}
name|in_output_segment
struct|;
block|}
name|u_
union|;
comment|// The index of this symbol in the output file.  If the symbol is
comment|// not going into the output file, this value is -1U.  This field
comment|// starts as always holding zero.  It is set to a non-zero value by
comment|// Symbol_table::finalize.
name|unsigned
name|int
name|symtab_index_
decl_stmt|;
comment|// The index of this symbol in the dynamic symbol table.  If the
comment|// symbol is not going into the dynamic symbol table, this value is
comment|// -1U.  This field starts as always holding zero.  It is set to a
comment|// non-zero value during Layout::finalize.
name|unsigned
name|int
name|dynsym_index_
decl_stmt|;
comment|// If this symbol has an entry in the GOT section (has_got_offset_
comment|// is true), this is the offset from the start of the GOT section.
name|unsigned
name|int
name|got_offset_
decl_stmt|;
comment|// If this symbol has an entry in the PLT section (has_plt_offset_
comment|// is true), then this is the offset from the start of the PLT
comment|// section.
name|unsigned
name|int
name|plt_offset_
decl_stmt|;
comment|// Symbol type.
name|elfcpp
operator|::
name|STT
name|type_
operator|:
literal|4
expr_stmt|;
comment|// Symbol binding.
name|elfcpp
operator|::
name|STB
name|binding_
operator|:
literal|4
expr_stmt|;
comment|// Symbol visibility.
name|elfcpp
operator|::
name|STV
name|visibility_
operator|:
literal|2
expr_stmt|;
comment|// Rest of symbol st_other field.
name|unsigned
name|int
name|nonvis_
range|:
literal|6
decl_stmt|;
comment|// The type of symbol.
name|Source
name|source_
range|:
literal|3
decl_stmt|;
comment|// True if this symbol always requires special target-specific
comment|// handling.
name|bool
name|is_target_special_
range|:
literal|1
decl_stmt|;
comment|// True if this is the default version of the symbol.
name|bool
name|is_def_
range|:
literal|1
decl_stmt|;
comment|// True if this symbol really forwards to another symbol.  This is
comment|// used when we discover after the fact that two different entries
comment|// in the hash table really refer to the same symbol.  This will
comment|// never be set for a symbol found in the hash table, but may be set
comment|// for a symbol found in the list of symbols attached to an Object.
comment|// It forwards to the symbol found in the forwarders_ map of
comment|// Symbol_table.
name|bool
name|is_forwarder_
range|:
literal|1
decl_stmt|;
comment|// True if this symbol needs to be in the dynamic symbol table.
name|bool
name|needs_dynsym_entry_
range|:
literal|1
decl_stmt|;
comment|// True if we've seen this symbol in a regular object.
name|bool
name|in_reg_
range|:
literal|1
decl_stmt|;
comment|// True if we've seen this symbol in a dynamic object.
name|bool
name|in_dyn_
range|:
literal|1
decl_stmt|;
comment|// True if the symbol has an entry in the GOT section.
name|bool
name|has_got_offset_
range|:
literal|1
decl_stmt|;
comment|// True if the symbol has an entry in the PLT section.
name|bool
name|has_plt_offset_
range|:
literal|1
decl_stmt|;
comment|// True if there is a warning for this symbol.
name|bool
name|has_warning_
range|:
literal|1
decl_stmt|;
block|}
empty_stmt|;
comment|// The parts of a symbol which are size specific.  Using a template
comment|// derived class like this helps us use less space on a 32-bit system.
name|template
operator|<
name|int
name|size
operator|>
name|class
name|Sized_symbol
operator|:
name|public
name|Symbol
block|{
name|public
operator|:
typedef|typedef
name|typename
name|elfcpp
operator|::
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_Addr
name|Value_type
expr_stmt|;
typedef|typedef
name|typename
name|elfcpp
operator|::
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_WXword
name|Size_type
expr_stmt|;
name|Sized_symbol
argument_list|()
block|{ }
comment|// Initialize fields from an ELF symbol in OBJECT.
name|template
operator|<
name|bool
name|big_endian
operator|>
name|void
name|init
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|version
argument_list|,
name|Object
operator|*
name|object
argument_list|,
specifier|const
name|elfcpp
operator|::
name|Sym
operator|<
name|size
argument_list|,
name|big_endian
operator|>
operator|&
argument_list|)
expr_stmt|;
comment|// Initialize fields for an Output_data.
name|void
name|init
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|Output_data
operator|*
argument_list|,
name|Value_type
name|value
argument_list|,
name|Size_type
name|symsize
argument_list|,
name|elfcpp
operator|::
name|STT
argument_list|,
name|elfcpp
operator|::
name|STB
argument_list|,
name|elfcpp
operator|::
name|STV
argument_list|,
name|unsigned
name|char
name|nonvis
argument_list|,
name|bool
name|offset_is_from_end
argument_list|)
decl_stmt|;
comment|// Initialize fields for an Output_segment.
name|void
name|init
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|Output_segment
operator|*
argument_list|,
name|Value_type
name|value
argument_list|,
name|Size_type
name|symsize
argument_list|,
name|elfcpp
operator|::
name|STT
argument_list|,
name|elfcpp
operator|::
name|STB
argument_list|,
name|elfcpp
operator|::
name|STV
argument_list|,
name|unsigned
name|char
name|nonvis
argument_list|,
name|Segment_offset_base
name|offset_base
argument_list|)
decl_stmt|;
comment|// Initialize fields for a constant.
name|void
name|init
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|Value_type
name|value
argument_list|,
name|Size_type
name|symsize
argument_list|,
name|elfcpp
operator|::
name|STT
argument_list|,
name|elfcpp
operator|::
name|STB
argument_list|,
name|elfcpp
operator|::
name|STV
argument_list|,
name|unsigned
name|char
name|nonvis
argument_list|)
decl_stmt|;
comment|// Override existing symbol.
name|template
operator|<
name|bool
name|big_endian
operator|>
name|void
name|override
argument_list|(
specifier|const
name|elfcpp
operator|::
name|Sym
operator|<
name|size
argument_list|,
name|big_endian
operator|>
operator|&
argument_list|,
name|Object
operator|*
name|object
argument_list|,
specifier|const
name|char
operator|*
name|version
argument_list|)
expr_stmt|;
comment|// Return the symbol's value.
name|Value_type
name|value
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|value_
return|;
block|}
comment|// Return the symbol's size (we can't call this 'size' because that
comment|// is a template parameter).
name|Size_type
name|symsize
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|symsize_
return|;
block|}
comment|// Set the symbol size.  This is used when resolving common symbols.
name|void
name|set_symsize
parameter_list|(
name|Size_type
name|symsize
parameter_list|)
block|{
name|this
operator|->
name|symsize_
operator|=
name|symsize
expr_stmt|;
block|}
comment|// Set the symbol value.  This is called when we store the final
comment|// values of the symbols into the symbol table.
name|void
name|set_value
parameter_list|(
name|Value_type
name|value
parameter_list|)
block|{
name|this
operator|->
name|value_
operator|=
name|value
expr_stmt|;
block|}
name|private
label|:
name|Sized_symbol
argument_list|(
specifier|const
name|Sized_symbol
operator|&
argument_list|)
expr_stmt|;
name|Sized_symbol
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Sized_symbol
operator|&
operator|)
decl_stmt|;
comment|// Symbol value.  Before Layout::finalize this is the offset in the
comment|// input section.  This is set to the final value during
comment|// Layout::finalize.
name|Value_type
name|value_
decl_stmt|;
comment|// Symbol size.
name|Size_type
name|symsize_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// A struct describing a symbol defined by the linker, where the value
end_comment

begin_comment
comment|// of the symbol is defined based on an output section.  This is used
end_comment

begin_comment
comment|// for symbols defined by the linker, like "_init_array_start".
end_comment

begin_struct
struct|struct
name|Define_symbol_in_section
block|{
comment|// The symbol name.
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|// The name of the output section with which this symbol should be
comment|// associated.  If there is no output section with that name, the
comment|// symbol will be defined as zero.
specifier|const
name|char
modifier|*
name|output_section
decl_stmt|;
comment|// The offset of the symbol within the output section.  This is an
comment|// offset from the start of the output section, unless start_at_end
comment|// is true, in which case this is an offset from the end of the
comment|// output section.
name|uint64_t
name|value
decl_stmt|;
comment|// The size of the symbol.
name|uint64_t
name|size
decl_stmt|;
comment|// The symbol type.
name|elfcpp
operator|::
name|STT
name|type
expr_stmt|;
comment|// The symbol binding.
name|elfcpp
operator|::
name|STB
name|binding
expr_stmt|;
comment|// The symbol visibility.
name|elfcpp
operator|::
name|STV
name|visibility
expr_stmt|;
comment|// The rest of the st_other field.
name|unsigned
name|char
name|nonvis
decl_stmt|;
comment|// If true, the value field is an offset from the end of the output
comment|// section.
name|bool
name|offset_is_from_end
decl_stmt|;
comment|// If true, this symbol is defined only if we see a reference to it.
name|bool
name|only_if_ref
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// A struct describing a symbol defined by the linker, where the value
end_comment

begin_comment
comment|// of the symbol is defined based on a segment.  This is used for
end_comment

begin_comment
comment|// symbols defined by the linker, like "_end".  We describe the
end_comment

begin_comment
comment|// segment with which the symbol should be associated by its
end_comment

begin_comment
comment|// characteristics.  If no segment meets these characteristics, the
end_comment

begin_comment
comment|// symbol will be defined as zero.  If there is more than one segment
end_comment

begin_comment
comment|// which meets these characteristics, we will use the first one.
end_comment

begin_struct
struct|struct
name|Define_symbol_in_segment
block|{
comment|// The symbol name.
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|// The segment type where the symbol should be defined, typically
comment|// PT_LOAD.
name|elfcpp
operator|::
name|PT
name|segment_type
expr_stmt|;
comment|// Bitmask of segment flags which must be set.
name|elfcpp
operator|::
name|PF
name|segment_flags_set
expr_stmt|;
comment|// Bitmask of segment flags which must be clear.
name|elfcpp
operator|::
name|PF
name|segment_flags_clear
expr_stmt|;
comment|// The offset of the symbol within the segment.  The offset is
comment|// calculated from the position set by offset_base.
name|uint64_t
name|value
decl_stmt|;
comment|// The size of the symbol.
name|uint64_t
name|size
decl_stmt|;
comment|// The symbol type.
name|elfcpp
operator|::
name|STT
name|type
expr_stmt|;
comment|// The symbol binding.
name|elfcpp
operator|::
name|STB
name|binding
expr_stmt|;
comment|// The symbol visibility.
name|elfcpp
operator|::
name|STV
name|visibility
expr_stmt|;
comment|// The rest of the st_other field.
name|unsigned
name|char
name|nonvis
decl_stmt|;
comment|// The base from which we compute the offset.
name|Symbol
operator|::
name|Segment_offset_base
name|offset_base
expr_stmt|;
comment|// If true, this symbol is defined only if we see a reference to it.
name|bool
name|only_if_ref
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// This class manages warnings.  Warnings are a GNU extension.  When
end_comment

begin_comment
comment|// we see a section named .gnu.warning.SYM in an object file, and if
end_comment

begin_comment
comment|// we wind using the definition of SYM from that object file, then we
end_comment

begin_comment
comment|// will issue a warning for any relocation against SYM from a
end_comment

begin_comment
comment|// different object file.  The text of the warning is the contents of
end_comment

begin_comment
comment|// the section.  This is not precisely the definition used by the old
end_comment

begin_comment
comment|// GNU linker; the old GNU linker treated an occurrence of
end_comment

begin_comment
comment|// .gnu.warning.SYM as defining a warning symbol.  A warning symbol
end_comment

begin_comment
comment|// would trigger a warning on any reference.  However, it was
end_comment

begin_comment
comment|// inconsistent in that a warning in a dynamic object only triggered
end_comment

begin_comment
comment|// if there was no definition in a regular object.  This linker is
end_comment

begin_comment
comment|// different in that we only issue a warning if we use the symbol
end_comment

begin_comment
comment|// definition from the same object file as the warning section.
end_comment

begin_decl_stmt
name|class
name|Warnings
block|{
name|public
label|:
name|Warnings
argument_list|()
operator|:
name|warnings_
argument_list|()
block|{ }
comment|// Add a warning for symbol NAME in section SHNDX in object OBJ.
name|void
name|add_warning
argument_list|(
argument|Symbol_table* symtab
argument_list|,
argument|const char* name
argument_list|,
argument|Object* obj
argument_list|,
argument|unsigned int shndx
argument_list|)
expr_stmt|;
comment|// For each symbol for which we should give a warning, make a note
comment|// on the symbol.
name|void
name|note_warnings
parameter_list|(
name|Symbol_table
modifier|*
name|symtab
parameter_list|)
function_decl|;
comment|// Issue a warning for a reference to SYM at LOCATION.
name|void
name|issue_warning
argument_list|(
specifier|const
name|Symbol
operator|*
name|sym
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|location
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|Warnings
argument_list|(
specifier|const
name|Warnings
operator|&
argument_list|)
expr_stmt|;
name|Warnings
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Warnings
operator|&
operator|)
decl_stmt|;
comment|// What we need to know to get the warning text.
struct|struct
name|Warning_location
block|{
comment|// The object the warning is in.
name|Object
modifier|*
name|object
decl_stmt|;
comment|// The index of the warning section.
name|unsigned
name|int
name|shndx
decl_stmt|;
comment|// The warning text if we have already loaded it.
name|std
operator|::
name|string
name|text
expr_stmt|;
name|Warning_location
argument_list|()
operator|:
name|object
argument_list|(
name|NULL
argument_list|)
operator|,
name|shndx
argument_list|(
literal|0
argument_list|)
operator|,
name|text
argument_list|()
block|{ }
name|void
name|set
argument_list|(
argument|Object* o
argument_list|,
argument|unsigned int s
argument_list|)
block|{
name|this
operator|->
name|object
operator|=
name|o
block|;
name|this
operator|->
name|shndx
operator|=
name|s
block|;     }
name|void
name|set_text
argument_list|(
argument|const char* t
argument_list|,
argument|off_t l
argument_list|)
block|{
name|this
operator|->
name|text
operator|.
name|assign
argument_list|(
name|t
argument_list|,
name|l
argument_list|)
block|; }
block|}
struct|;
comment|// A mapping from warning symbol names (canonicalized in
comment|// Symbol_table's namepool_ field) to
typedef|typedef
name|Unordered_map
operator|<
specifier|const
name|char
operator|*
operator|,
name|Warning_location
operator|>
name|Warning_table
expr_stmt|;
name|Warning_table
name|warnings_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// The main linker symbol table.
end_comment

begin_decl_stmt
name|class
name|Symbol_table
block|{
name|public
label|:
name|Symbol_table
argument_list|()
expr_stmt|;
operator|~
name|Symbol_table
argument_list|()
expr_stmt|;
comment|// Add COUNT external symbols from the relocatable object RELOBJ to
comment|// the symbol table.  SYMS is the symbols, SYM_NAMES is their names,
comment|// SYM_NAME_SIZE is the size of SYM_NAMES.  This sets SYMPOINTERS to
comment|// point to the symbols in the symbol table.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|add_from_relobj
argument_list|(
argument|Sized_relobj<size
argument_list|,
argument|big_endian>* relobj
argument_list|,
argument|const unsigned char* syms
argument_list|,
argument|size_t count
argument_list|,
argument|const char* sym_names
argument_list|,
argument|size_t sym_name_size
argument_list|,
argument|Symbol** sympointers
argument_list|)
expr_stmt|;
comment|// Add COUNT dynamic symbols from the dynamic object DYNOBJ to the
comment|// symbol table.  SYMS is the symbols.  SYM_NAMES is their names.
comment|// SYM_NAME_SIZE is the size of SYM_NAMES.  The other parameters are
comment|// symbol version data.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|add_from_dynobj
argument_list|(
argument|Sized_dynobj<size
argument_list|,
argument|big_endian>* dynobj
argument_list|,
argument|const unsigned char* syms
argument_list|,
argument|size_t count
argument_list|,
argument|const char* sym_names
argument_list|,
argument|size_t sym_name_size
argument_list|,
argument|const unsigned char* versym
argument_list|,
argument|size_t versym_size
argument_list|,
argument|const std::vector<const char*>*
argument_list|)
expr_stmt|;
comment|// Define a special symbol based on an Output_data.  It is a
comment|// multiple definition error if this symbol is already defined.
name|Symbol
modifier|*
name|define_in_output_data
argument_list|(
specifier|const
name|Target
operator|*
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|version
argument_list|,
name|Output_data
operator|*
argument_list|,
name|uint64_t
name|value
argument_list|,
name|uint64_t
name|symsize
argument_list|,
name|elfcpp
operator|::
name|STT
name|type
argument_list|,
name|elfcpp
operator|::
name|STB
name|binding
argument_list|,
name|elfcpp
operator|::
name|STV
name|visibility
argument_list|,
name|unsigned
name|char
name|nonvis
argument_list|,
name|bool
name|offset_is_from_end
argument_list|,
name|bool
name|only_if_ref
argument_list|)
decl_stmt|;
comment|// Define a special symbol based on an Output_segment.  It is a
comment|// multiple definition error if this symbol is already defined.
name|Symbol
modifier|*
name|define_in_output_segment
argument_list|(
specifier|const
name|Target
operator|*
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|version
argument_list|,
name|Output_segment
operator|*
argument_list|,
name|uint64_t
name|value
argument_list|,
name|uint64_t
name|symsize
argument_list|,
name|elfcpp
operator|::
name|STT
name|type
argument_list|,
name|elfcpp
operator|::
name|STB
name|binding
argument_list|,
name|elfcpp
operator|::
name|STV
name|visibility
argument_list|,
name|unsigned
name|char
name|nonvis
argument_list|,
name|Symbol
operator|::
name|Segment_offset_base
argument_list|,
name|bool
name|only_if_ref
argument_list|)
decl_stmt|;
comment|// Define a special symbol with a constant value.  It is a multiple
comment|// definition error if this symbol is already defined.
name|Symbol
modifier|*
name|define_as_constant
argument_list|(
specifier|const
name|Target
operator|*
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|version
argument_list|,
name|uint64_t
name|value
argument_list|,
name|uint64_t
name|symsize
argument_list|,
name|elfcpp
operator|::
name|STT
name|type
argument_list|,
name|elfcpp
operator|::
name|STB
name|binding
argument_list|,
name|elfcpp
operator|::
name|STV
name|visibility
argument_list|,
name|unsigned
name|char
name|nonvis
argument_list|,
name|bool
name|only_if_ref
argument_list|)
decl_stmt|;
comment|// Define a set of symbols in output sections.
name|void
name|define_symbols
parameter_list|(
specifier|const
name|Layout
modifier|*
parameter_list|,
specifier|const
name|Target
modifier|*
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|Define_symbol_in_section
modifier|*
parameter_list|)
function_decl|;
comment|// Define a set of symbols in output segments.
name|void
name|define_symbols
parameter_list|(
specifier|const
name|Layout
modifier|*
parameter_list|,
specifier|const
name|Target
modifier|*
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|Define_symbol_in_segment
modifier|*
parameter_list|)
function_decl|;
comment|// Look up a symbol.
name|Symbol
modifier|*
name|lookup
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
name|version
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
comment|// Return the real symbol associated with the forwarder symbol FROM.
name|Symbol
modifier|*
name|resolve_forwards
argument_list|(
specifier|const
name|Symbol
operator|*
name|from
argument_list|)
decl|const
decl_stmt|;
comment|// Return the bitsize (32 or 64) of the symbols in the table.
name|int
name|get_size
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|size_
return|;
block|}
comment|// Return the sized version of a symbol in this table.
name|template
operator|<
name|int
name|size
operator|>
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
name|get_sized_symbol
argument_list|(
argument|Symbol* ACCEPT_SIZE
argument_list|)
specifier|const
expr_stmt|;
name|template
operator|<
name|int
name|size
operator|>
specifier|const
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
name|get_sized_symbol
argument_list|(
argument|const Symbol* ACCEPT_SIZE
argument_list|)
specifier|const
expr_stmt|;
comment|// Return the count of undefined symbols seen.
name|int
name|saw_undefined
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|saw_undefined_
return|;
block|}
comment|// Allocate the common symbols
name|void
name|allocate_commons
parameter_list|(
specifier|const
name|General_options
modifier|&
parameter_list|,
name|Layout
modifier|*
parameter_list|)
function_decl|;
comment|// Add a warning for symbol NAME in section SHNDX in object OBJ.
name|void
name|add_warning
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|Object
modifier|*
name|obj
parameter_list|,
name|unsigned
name|int
name|shndx
parameter_list|)
block|{
name|this
operator|->
name|warnings_
operator|.
name|add_warning
argument_list|(
name|this
argument_list|,
name|name
argument_list|,
name|obj
argument_list|,
name|shndx
argument_list|)
expr_stmt|;
block|}
comment|// Canonicalize a symbol name for use in the hash table.
specifier|const
name|char
modifier|*
name|canonicalize_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
name|this
operator|->
name|namepool_
operator|.
name|add
argument_list|(
name|name
argument_list|,
name|NULL
argument_list|)
return|;
block|}
comment|// Possibly issue a warning for a reference to SYM at LOCATION which
comment|// is in OBJ.
name|void
name|issue_warning
argument_list|(
specifier|const
name|Symbol
operator|*
name|sym
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|location
argument_list|)
decl|const
block|{
name|this
operator|->
name|warnings_
operator|.
name|issue_warning
argument_list|(
name|sym
argument_list|,
name|location
argument_list|)
expr_stmt|;
block|}
comment|// Set the dynamic symbol indexes.  INDEX is the index of the first
comment|// global dynamic symbol.  Pointers to the symbols are stored into
comment|// the vector.  The names are stored into the Stringpool.  This
comment|// returns an updated dynamic symbol index.
name|unsigned
name|int
name|set_dynsym_indexes
argument_list|(
specifier|const
name|General_options
operator|*
argument_list|,
specifier|const
name|Target
operator|*
argument_list|,
name|unsigned
name|int
name|index
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Symbol
operator|*
operator|>
operator|*
argument_list|,
name|Stringpool
operator|*
argument_list|,
name|Versions
operator|*
argument_list|)
decl_stmt|;
comment|// Finalize the symbol table after we have set the final addresses
comment|// of all the input sections.  This sets the final symbol indexes,
comment|// values and adds the names to *POOL.  INDEX is the index of the
comment|// first global symbol.  OFF is the file offset of the global symbol
comment|// table, DYNOFF is the offset of the globals in the dynamic symbol
comment|// table, DYN_GLOBAL_INDEX is the index of the first global dynamic
comment|// symbol, and DYNCOUNT is the number of global dynamic symbols.
comment|// This records the parameters, and returns the new file offset.
name|off_t
name|finalize
parameter_list|(
name|unsigned
name|int
name|index
parameter_list|,
name|off_t
name|off
parameter_list|,
name|off_t
name|dynoff
parameter_list|,
name|size_t
name|dyn_global_index
parameter_list|,
name|size_t
name|dyncount
parameter_list|,
name|Stringpool
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|// Write out the global symbols.
name|void
name|write_globals
argument_list|(
specifier|const
name|Target
operator|*
argument_list|,
specifier|const
name|Stringpool
operator|*
argument_list|,
specifier|const
name|Stringpool
operator|*
argument_list|,
name|Output_file
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|// Write out a section symbol.  Return the updated offset.
name|void
name|write_section_symbol
argument_list|(
specifier|const
name|Target
operator|*
argument_list|,
specifier|const
name|Output_section
operator|*
argument_list|,
name|Output_file
operator|*
argument_list|,
name|off_t
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|Symbol_table
argument_list|(
specifier|const
name|Symbol_table
operator|&
argument_list|)
expr_stmt|;
name|Symbol_table
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Symbol_table
operator|&
operator|)
decl_stmt|;
comment|// Set the size (32 or 64) of the symbols in the table.
name|void
name|set_size
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|this
operator|->
name|size_
operator|=
name|size
expr_stmt|;
block|}
comment|// Make FROM a forwarder symbol to TO.
name|void
name|make_forwarder
parameter_list|(
name|Symbol
modifier|*
name|from
parameter_list|,
name|Symbol
modifier|*
name|to
parameter_list|)
function_decl|;
comment|// Add a symbol.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|Symbol
operator|*
name|add_from_object
argument_list|(
argument|Object*
argument_list|,
argument|const char *name
argument_list|,
argument|Stringpool::Key name_key
argument_list|,
argument|const char *version
argument_list|,
argument|Stringpool::Key version_key
argument_list|,
argument|bool def
argument_list|,
argument|const elfcpp::Sym<size
argument_list|,
argument|big_endian>& sym
argument_list|)
expr_stmt|;
comment|// Resolve symbols.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
specifier|static
name|void
name|resolve
argument_list|(
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
name|to
argument_list|,
specifier|const
name|elfcpp
operator|::
name|Sym
operator|<
name|size
argument_list|,
name|big_endian
operator|>
operator|&
name|sym
argument_list|,
name|Object
operator|*
argument_list|,
specifier|const
name|char
operator|*
name|version
argument_list|)
expr_stmt|;
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
specifier|static
name|void
name|resolve
argument_list|(
argument|Sized_symbol<size>* to
argument_list|,
argument|const Sized_symbol<size>* from
argument_list|,
argument|const char* version ACCEPT_SIZE_ENDIAN
argument_list|)
expr_stmt|;
comment|// Define a special symbol.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
name|define_special_symbol
argument_list|(
argument|const Target* target
argument_list|,
argument|const char* name
argument_list|,
argument|const char* version
argument_list|,
argument|bool only_if_ref 			ACCEPT_SIZE_ENDIAN
argument_list|)
expr_stmt|;
comment|// Define a symbol in an Output_data, sized version.
name|template
operator|<
name|int
name|size
operator|>
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
name|do_define_in_output_data
argument_list|(
argument|const Target*
argument_list|,
argument|const char* name
argument_list|,
argument|const char* version
argument_list|,
argument|Output_data*
argument_list|,
argument|typename elfcpp::Elf_types<size>::Elf_Addr value
argument_list|,
argument|typename elfcpp::Elf_types<size>::Elf_WXword ssize
argument_list|,
argument|elfcpp::STT type
argument_list|,
argument|elfcpp::STB binding
argument_list|,
argument|elfcpp::STV visibility
argument_list|,
argument|unsigned char nonvis
argument_list|,
argument|bool offset_is_from_end
argument_list|,
argument|bool only_if_ref
argument_list|)
expr_stmt|;
comment|// Define a symbol in an Output_segment, sized version.
name|template
operator|<
name|int
name|size
operator|>
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
name|do_define_in_output_segment
argument_list|(
argument|const Target*
argument_list|,
argument|const char* name
argument_list|,
argument|const char* version
argument_list|,
argument|Output_segment* os
argument_list|,
argument|typename elfcpp::Elf_types<size>::Elf_Addr value
argument_list|,
argument|typename elfcpp::Elf_types<size>::Elf_WXword ssize
argument_list|,
argument|elfcpp::STT type
argument_list|,
argument|elfcpp::STB binding
argument_list|,
argument|elfcpp::STV visibility
argument_list|,
argument|unsigned char nonvis
argument_list|,
argument|Symbol::Segment_offset_base offset_base
argument_list|,
argument|bool only_if_ref
argument_list|)
expr_stmt|;
comment|// Define a symbol as a constant, sized version.
name|template
operator|<
name|int
name|size
operator|>
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
name|do_define_as_constant
argument_list|(
argument|const Target*
argument_list|,
argument|const char* name
argument_list|,
argument|const char* version
argument_list|,
argument|typename elfcpp::Elf_types<size>::Elf_Addr value
argument_list|,
argument|typename elfcpp::Elf_types<size>::Elf_WXword ssize
argument_list|,
argument|elfcpp::STT type
argument_list|,
argument|elfcpp::STB binding
argument_list|,
argument|elfcpp::STV visibility
argument_list|,
argument|unsigned char nonvis
argument_list|,
argument|bool only_if_ref
argument_list|)
expr_stmt|;
comment|// Allocate the common symbols, sized version.
name|template
operator|<
name|int
name|size
operator|>
name|void
name|do_allocate_commons
argument_list|(
specifier|const
name|General_options
operator|&
argument_list|,
name|Layout
operator|*
argument_list|)
expr_stmt|;
comment|// Finalize symbols specialized for size.
name|template
operator|<
name|int
name|size
operator|>
name|off_t
name|sized_finalize
argument_list|(
argument|unsigned int
argument_list|,
argument|off_t
argument_list|,
argument|Stringpool*
argument_list|)
expr_stmt|;
comment|// Write globals specialized for size and endianness.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|sized_write_globals
argument_list|(
argument|const Target*
argument_list|,
argument|const Stringpool*
argument_list|,
argument|const Stringpool*
argument_list|,
argument|Output_file*
argument_list|)
specifier|const
expr_stmt|;
comment|// Write out a symbol to P.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|sized_write_symbol
argument_list|(
argument|Sized_symbol<size>*
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|const Stringpool*
argument_list|,
argument|unsigned char* p                      ACCEPT_SIZE_ENDIAN
argument_list|)
specifier|const
expr_stmt|;
comment|// Write out a section symbol, specialized for size and endianness.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|sized_write_section_symbol
argument_list|(
argument|const Output_section*
argument_list|,
argument|Output_file*
argument_list|,
argument|off_t
argument_list|)
specifier|const
expr_stmt|;
comment|// The type of the symbol hash table.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|Stringpool
operator|::
name|Key
operator|,
name|Stringpool
operator|::
name|Key
operator|>
name|Symbol_table_key
expr_stmt|;
struct|struct
name|Symbol_table_hash
block|{
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|Symbol_table_key
operator|&
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
struct|struct
name|Symbol_table_eq
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Symbol_table_key
operator|&
operator|,
specifier|const
name|Symbol_table_key
operator|&
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
typedef|typedef
name|Unordered_map
operator|<
name|Symbol_table_key
operator|,
name|Symbol
operator|*
operator|,
name|Symbol_table_hash
operator|,
name|Symbol_table_eq
operator|>
name|Symbol_table_type
expr_stmt|;
comment|// The type of the list of common symbols.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Symbol
operator|*
operator|>
name|Commons_type
expr_stmt|;
comment|// The size of the symbols in the symbol table (32 or 64).
name|int
name|size_
decl_stmt|;
comment|// We increment this every time we see a new undefined symbol, for
comment|// use in archive groups.
name|int
name|saw_undefined_
decl_stmt|;
comment|// The index of the first global symbol in the output file.
name|unsigned
name|int
name|first_global_index_
decl_stmt|;
comment|// The file offset within the output symtab section where we should
comment|// write the table.
name|off_t
name|offset_
decl_stmt|;
comment|// The number of global symbols we want to write out.
name|size_t
name|output_count_
decl_stmt|;
comment|// The file offset of the global dynamic symbols, or 0 if none.
name|off_t
name|dynamic_offset_
decl_stmt|;
comment|// The index of the first global dynamic symbol.
name|unsigned
name|int
name|first_dynamic_global_index_
decl_stmt|;
comment|// The number of global dynamic symbols, or 0 if none.
name|off_t
name|dynamic_count_
decl_stmt|;
comment|// The symbol hash table.
name|Symbol_table_type
name|table_
decl_stmt|;
comment|// A pool of symbol names.  This is used for all global symbols.
comment|// Entries in the hash table point into this pool.
name|Stringpool
name|namepool_
decl_stmt|;
comment|// Forwarding symbols.
name|Unordered_map
operator|<
specifier|const
name|Symbol
operator|*
operator|,
name|Symbol
operator|*
operator|>
name|forwarders_
expr_stmt|;
comment|// We don't expect there to be very many common symbols, so we keep
comment|// a list of them.  When we find a common symbol we add it to this
comment|// list.  It is possible that by the time we process the list the
comment|// symbol is no longer a common symbol.  It may also have become a
comment|// forwarder.
name|Commons_type
name|commons_
decl_stmt|;
comment|// Manage symbol warnings.
name|Warnings
name|warnings_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// We inline get_sized_symbol for efficiency.
end_comment

begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|>
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
name|Symbol_table
operator|::
name|get_sized_symbol
argument_list|(
argument|Symbol* sym ACCEPT_SIZE
argument_list|)
specifier|const
block|{
name|gold_assert
argument_list|(
name|size
operator|==
name|this
operator|->
name|get_size
argument_list|()
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
operator|>
operator|(
name|sym
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|>
specifier|const
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
name|Symbol_table
operator|::
name|get_sized_symbol
argument_list|(
argument|const Symbol* sym ACCEPT_SIZE
argument_list|)
specifier|const
block|{
name|gold_assert
argument_list|(
name|size
operator|==
name|this
operator|->
name|get_size
argument_list|()
argument_list|)
block|;
return|return
name|static_cast
operator|<
specifier|const
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
operator|>
operator|(
name|sym
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_SYMTAB_H)
end_comment

end_unit

