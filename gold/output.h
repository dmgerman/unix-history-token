begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// output.h -- manage the output file for gold   -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_OUTPUT_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_OUTPUT_H
end_define

begin_include
include|#
directive|include
file|<list>
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
file|"layout.h"
end_include

begin_include
include|#
directive|include
file|"reloc-types.h"
end_include

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|General_options
decl_stmt|;
name|class
name|Object
decl_stmt|;
name|class
name|Symbol
decl_stmt|;
name|class
name|Output_file
decl_stmt|;
name|class
name|Output_section
decl_stmt|;
name|class
name|Target
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
name|Sized_target
expr_stmt|;
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
comment|// An abtract class for data which has to go into the output file.
name|class
name|Output_data
block|{
name|public
label|:
name|explicit
name|Output_data
argument_list|(
argument|off_t data_size =
literal|0
argument_list|)
block|:
name|address_
argument_list|(
literal|0
argument_list|)
operator|,
name|data_size_
argument_list|(
name|data_size
argument_list|)
operator|,
name|offset_
argument_list|(
argument|-
literal|1
argument_list|)
block|{ }
name|virtual
operator|~
name|Output_data
argument_list|()
expr_stmt|;
comment|// Return the address.  This is only valid after Layout::finalize is
comment|// finished.
name|uint64_t
name|address
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|address_
return|;
block|}
comment|// Return the size of the data.  This must be valid after
comment|// Layout::finalize calls set_address, but need not be valid before
comment|// then.
name|off_t
name|data_size
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|data_size_
return|;
block|}
comment|// Return the file offset.  This is only valid after
comment|// Layout::finalize is finished.
name|off_t
name|offset
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|offset_
return|;
block|}
comment|// Return the required alignment.
name|uint64_t
name|addralign
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_addralign
argument_list|()
return|;
block|}
comment|// Return whether this is an Output_section.
name|bool
name|is_section
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_is_section
argument_list|()
return|;
block|}
comment|// Return whether this is an Output_section of the specified type.
name|bool
name|is_section_type
argument_list|(
name|elfcpp
operator|::
name|Elf_Word
name|stt
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_is_section_type
argument_list|(
name|stt
argument_list|)
return|;
block|}
comment|// Return whether this is an Output_section with the specified flag
comment|// set.
name|bool
name|is_section_flag_set
argument_list|(
name|elfcpp
operator|::
name|Elf_Xword
name|shf
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_is_section_flag_set
argument_list|(
name|shf
argument_list|)
return|;
block|}
comment|// Return the output section index, if there is an output section.
name|unsigned
name|int
name|out_shndx
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_out_shndx
argument_list|()
return|;
block|}
comment|// Set the output section index, if this is an output section.
name|void
name|set_out_shndx
parameter_list|(
name|unsigned
name|int
name|shndx
parameter_list|)
block|{
name|this
operator|->
name|do_set_out_shndx
argument_list|(
name|shndx
argument_list|)
expr_stmt|;
block|}
comment|// Set the address and file offset of this data.  This is called
comment|// during Layout::finalize.
name|void
name|set_address
parameter_list|(
name|uint64_t
name|addr
parameter_list|,
name|off_t
name|off
parameter_list|)
function_decl|;
comment|// Write the data to the output file.  This is called after
comment|// Layout::finalize is complete.
name|void
name|write
parameter_list|(
name|Output_file
modifier|*
name|file
parameter_list|)
block|{
name|this
operator|->
name|do_write
argument_list|(
name|file
argument_list|)
expr_stmt|;
block|}
comment|// This is called by Layout::finalize to note that all sizes must
comment|// now be fixed.
specifier|static
name|void
name|layout_complete
parameter_list|()
block|{
name|Output_data
operator|::
name|sizes_are_fixed
operator|=
name|true
expr_stmt|;
block|}
name|protected
label|:
comment|// Functions that child classes may or in some cases must implement.
comment|// Write the data to the output file.
name|virtual
name|void
name|do_write
parameter_list|(
name|Output_file
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Return the required alignment.
name|virtual
name|uint64_t
name|do_addralign
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Return whether this is an Output_section.
name|virtual
name|bool
name|do_is_section
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|// Return whether this is an Output_section of the specified type.
comment|// This only needs to be implement by Output_section.
name|virtual
name|bool
name|do_is_section_type
argument_list|(
name|elfcpp
operator|::
name|Elf_Word
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|// Return whether this is an Output_section with the specific flag
comment|// set.  This only needs to be implemented by Output_section.
name|virtual
name|bool
name|do_is_section_flag_set
argument_list|(
name|elfcpp
operator|::
name|Elf_Xword
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|// Return the output section index, if there is an output section.
name|virtual
name|unsigned
name|int
name|do_out_shndx
argument_list|()
specifier|const
block|{
name|gold_unreachable
argument_list|()
block|; }
comment|// Set the output section index, if this is an output section.
name|virtual
name|void
name|do_set_out_shndx
argument_list|(
argument|unsigned int
argument_list|)
block|{
name|gold_unreachable
argument_list|()
block|; }
comment|// Set the address and file offset of the data.  This only needs to
comment|// be implemented if the child needs to know.  The child class can
comment|// set its size in this call.
name|virtual
name|void
name|do_set_address
argument_list|(
argument|uint64_t
argument_list|,
argument|off_t
argument_list|)
block|{ }
comment|// Functions that child classes may call.
comment|// Set the size of the data.
name|void
name|set_data_size
argument_list|(
argument|off_t data_size
argument_list|)
block|{
name|gold_assert
argument_list|(
operator|!
name|Output_data
operator|::
name|sizes_are_fixed
argument_list|)
block|;
name|this
operator|->
name|data_size_
operator|=
name|data_size
block|;   }
comment|// Return default alignment for a size--32 or 64.
specifier|static
name|uint64_t
name|default_alignment
argument_list|(
argument|int size
argument_list|)
expr_stmt|;
name|private
label|:
name|Output_data
argument_list|(
specifier|const
name|Output_data
operator|&
argument_list|)
expr_stmt|;
name|Output_data
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Output_data
operator|&
operator|)
decl_stmt|;
comment|// This is used for verification, to make sure that we don't try to
comment|// change any sizes after we set the section addresses.
specifier|static
name|bool
name|sizes_are_fixed
decl_stmt|;
comment|// Memory address in file (not always meaningful).
name|uint64_t
name|address_
decl_stmt|;
comment|// Size of data in file.
name|off_t
name|data_size_
decl_stmt|;
comment|// Offset within file.
name|off_t
name|offset_
decl_stmt|;
block|}
empty_stmt|;
comment|// Output the section headers.
name|class
name|Output_section_headers
range|:
name|public
name|Output_data
block|{
name|public
operator|:
name|Output_section_headers
argument_list|(
argument|int size
argument_list|,
argument|bool big_endian
argument_list|,
argument|const Layout*
argument_list|,
argument|const Layout::Segment_list*
argument_list|,
argument|const Layout::Section_list*
argument_list|,
argument|const Stringpool*
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
comment|// Return the required alignment.
name|uint64_t
name|do_addralign
argument_list|()
specifier|const
block|{
return|return
name|Output_data
operator|::
name|default_alignment
argument_list|(
name|this
operator|->
name|size_
argument_list|)
return|;
block|}
name|private
operator|:
comment|// Write the data to the file with the right size and endianness.
name|template
operator|<
name|int
name|size
block|,
name|bool
name|big_endian
operator|>
name|void
name|do_sized_write
argument_list|(
name|Output_file
operator|*
argument_list|)
block|;
name|int
name|size_
block|;
name|bool
name|big_endian_
block|;
specifier|const
name|Layout
operator|*
name|layout_
block|;
specifier|const
name|Layout
operator|::
name|Segment_list
operator|*
name|segment_list_
block|;
specifier|const
name|Layout
operator|::
name|Section_list
operator|*
name|unattached_section_list_
block|;
specifier|const
name|Stringpool
operator|*
name|secnamepool_
block|; }
decl_stmt|;
comment|// Output the segment headers.
name|class
name|Output_segment_headers
range|:
name|public
name|Output_data
block|{
name|public
operator|:
name|Output_segment_headers
argument_list|(
argument|int size
argument_list|,
argument|bool big_endian
argument_list|,
argument|const Layout::Segment_list& segment_list
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
comment|// Return the required alignment.
name|uint64_t
name|do_addralign
argument_list|()
specifier|const
block|{
return|return
name|Output_data
operator|::
name|default_alignment
argument_list|(
name|this
operator|->
name|size_
argument_list|)
return|;
block|}
name|private
operator|:
comment|// Write the data to the file with the right size and endianness.
name|template
operator|<
name|int
name|size
block|,
name|bool
name|big_endian
operator|>
name|void
name|do_sized_write
argument_list|(
name|Output_file
operator|*
argument_list|)
block|;
name|int
name|size_
block|;
name|bool
name|big_endian_
block|;
specifier|const
name|Layout
operator|::
name|Segment_list
operator|&
name|segment_list_
block|; }
decl_stmt|;
comment|// Output the ELF file header.
name|class
name|Output_file_header
range|:
name|public
name|Output_data
block|{
name|public
operator|:
name|Output_file_header
argument_list|(
argument|int size
argument_list|,
argument|bool big_endian
argument_list|,
argument|const General_options&
argument_list|,
argument|const Target*
argument_list|,
argument|const Symbol_table*
argument_list|,
argument|const Output_segment_headers*
argument_list|)
block|;
comment|// Add information about the section headers.  We lay out the ELF
comment|// file header before we create the section headers.
name|void
name|set_section_info
argument_list|(
specifier|const
name|Output_section_headers
operator|*
argument_list|,
specifier|const
name|Output_section
operator|*
name|shstrtab
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
comment|// Return the required alignment.
name|uint64_t
name|do_addralign
argument_list|()
specifier|const
block|{
return|return
name|Output_data
operator|::
name|default_alignment
argument_list|(
name|this
operator|->
name|size_
argument_list|)
return|;
block|}
comment|// Set the address and offset--we only implement this for error
comment|// checking.
name|void
name|do_set_address
argument_list|(
argument|uint64_t
argument_list|,
argument|off_t off
argument_list|)
specifier|const
block|{
name|gold_assert
argument_list|(
name|off
operator|==
literal|0
argument_list|)
block|; }
name|private
operator|:
comment|// Write the data to the file with the right size and endianness.
name|template
operator|<
name|int
name|size
block|,
name|bool
name|big_endian
operator|>
name|void
name|do_sized_write
argument_list|(
name|Output_file
operator|*
argument_list|)
block|;
name|int
name|size_
block|;
name|bool
name|big_endian_
block|;
specifier|const
name|General_options
operator|&
name|options_
block|;
specifier|const
name|Target
operator|*
name|target_
block|;
specifier|const
name|Symbol_table
operator|*
name|symtab_
block|;
specifier|const
name|Output_segment_headers
operator|*
name|segment_header_
block|;
specifier|const
name|Output_section_headers
operator|*
name|section_header_
block|;
specifier|const
name|Output_section
operator|*
name|shstrtab_
block|; }
decl_stmt|;
comment|// Output sections are mainly comprised of input sections.  However,
comment|// there are cases where we have data to write out which is not in an
comment|// input section.  Output_section_data is used in such cases.  This is
comment|// an abstract base class.
name|class
name|Output_section_data
range|:
name|public
name|Output_data
block|{
name|public
operator|:
name|Output_section_data
argument_list|(
argument|off_t data_size
argument_list|,
argument|uint64_t addralign
argument_list|)
operator|:
name|Output_data
argument_list|(
name|data_size
argument_list|)
block|,
name|output_section_
argument_list|(
name|NULL
argument_list|)
block|,
name|addralign_
argument_list|(
argument|addralign
argument_list|)
block|{ }
name|Output_section_data
argument_list|(
argument|uint64_t addralign
argument_list|)
operator|:
name|Output_data
argument_list|(
literal|0
argument_list|)
block|,
name|output_section_
argument_list|(
name|NULL
argument_list|)
block|,
name|addralign_
argument_list|(
argument|addralign
argument_list|)
block|{ }
comment|// Return the output section.
specifier|const
name|Output_section
operator|*
name|output_section
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|output_section_
return|;
block|}
comment|// Record the output section.
name|void
name|set_output_section
argument_list|(
name|Output_section
operator|*
name|os
argument_list|)
block|;
comment|// Add an input section, for SHF_MERGE sections.  This returns true
comment|// if the section was handled.
name|bool
name|add_input_section
argument_list|(
argument|Relobj* object
argument_list|,
argument|unsigned int shndx
argument_list|)
block|{
return|return
name|this
operator|->
name|do_add_input_section
argument_list|(
name|object
argument_list|,
name|shndx
argument_list|)
return|;
block|}
comment|// Given an input OBJECT, an input section index SHNDX within that
comment|// object, and an OFFSET relative to the start of that input
comment|// section, return whether or not the output address is known.
comment|// OUTPUT_SECTION_ADDRESS is the address of the output section which
comment|// this is a part of.  If this function returns true, it sets
comment|// *POUTPUT to the output address.
name|virtual
name|bool
name|output_address
argument_list|(
argument|const Relobj* object
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|off_t offset
argument_list|,
argument|uint64_t output_section_address
argument_list|,
argument|uint64_t *poutput
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_output_address
argument_list|(
name|object
argument_list|,
name|shndx
argument_list|,
name|offset
argument_list|,
name|output_section_address
argument_list|,
name|poutput
argument_list|)
return|;
block|}
name|protected
operator|:
comment|// The child class must implement do_write.
comment|// The child class may implement specific adjustments to the output
comment|// section.
name|virtual
name|void
name|do_adjust_output_section
argument_list|(
argument|Output_section*
argument_list|)
block|{ }
comment|// May be implemented by child class.  Return true if the section
comment|// was handled.
name|virtual
name|bool
name|do_add_input_section
argument_list|(
argument|Relobj*
argument_list|,
argument|unsigned int
argument_list|)
block|{
name|gold_unreachable
argument_list|()
block|; }
comment|// The child class may implement output_address.
name|virtual
name|bool
name|do_output_address
argument_list|(
argument|const Relobj*
argument_list|,
argument|unsigned int
argument_list|,
argument|off_t
argument_list|,
argument|uint64_t
argument_list|,
argument|uint64_t*
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|// Return the required alignment.
name|uint64_t
name|do_addralign
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|addralign_
return|;
block|}
comment|// Return the section index of the output section.
name|unsigned
name|int
name|do_out_shndx
argument_list|()
specifier|const
block|;
comment|// Set the alignment.
name|void
name|set_addralign
argument_list|(
argument|uint64_t addralign
argument_list|)
block|{
name|this
operator|->
name|addralign_
operator|=
name|addralign
block|; }
name|private
operator|:
comment|// The output section for this section.
specifier|const
name|Output_section
operator|*
name|output_section_
block|;
comment|// The required alignment.
name|uint64_t
name|addralign_
block|; }
decl_stmt|;
comment|// A simple case of Output_data in which we have constant data to
comment|// output.
name|class
name|Output_data_const
range|:
name|public
name|Output_section_data
block|{
name|public
operator|:
name|Output_data_const
argument_list|(
argument|const std::string& data
argument_list|,
argument|uint64_t addralign
argument_list|)
operator|:
name|Output_section_data
argument_list|(
name|data
operator|.
name|size
argument_list|()
argument_list|,
name|addralign
argument_list|)
block|,
name|data_
argument_list|(
argument|data
argument_list|)
block|{ }
name|Output_data_const
argument_list|(
argument|const char* p
argument_list|,
argument|off_t len
argument_list|,
argument|uint64_t addralign
argument_list|)
operator|:
name|Output_section_data
argument_list|(
name|len
argument_list|,
name|addralign
argument_list|)
block|,
name|data_
argument_list|(
argument|p
argument_list|,
argument|len
argument_list|)
block|{ }
name|Output_data_const
argument_list|(
argument|const unsigned char* p
argument_list|,
argument|off_t len
argument_list|,
argument|uint64_t addralign
argument_list|)
operator|:
name|Output_section_data
argument_list|(
name|len
argument_list|,
name|addralign
argument_list|)
block|,
name|data_
argument_list|(
argument|reinterpret_cast<const char*>(p)
argument_list|,
argument|len
argument_list|)
block|{ }
comment|// Add more data.
name|void
name|add_data
argument_list|(
argument|const std::string& add
argument_list|)
block|{
name|this
operator|->
name|data_
operator|.
name|append
argument_list|(
name|add
argument_list|)
block|;
name|this
operator|->
name|set_data_size
argument_list|(
name|this
operator|->
name|data_
operator|.
name|size
argument_list|()
argument_list|)
block|;   }
comment|// Write the data to the output file.
name|void
name|do_write
argument_list|(
name|Output_file
operator|*
argument_list|)
block|;
name|private
operator|:
name|std
operator|::
name|string
name|data_
block|; }
decl_stmt|;
comment|// Another version of Output_data with constant data, in which the
comment|// buffer is allocated by the caller.
name|class
name|Output_data_const_buffer
range|:
name|public
name|Output_section_data
block|{
name|public
operator|:
name|Output_data_const_buffer
argument_list|(
argument|const unsigned char* p
argument_list|,
argument|off_t len
argument_list|,
argument|uint64_t addralign
argument_list|)
operator|:
name|Output_section_data
argument_list|(
name|len
argument_list|,
name|addralign
argument_list|)
block|,
name|p_
argument_list|(
argument|p
argument_list|)
block|{ }
comment|// Write the data the output file.
name|void
name|do_write
argument_list|(
name|Output_file
operator|*
argument_list|)
block|;
name|private
operator|:
specifier|const
name|unsigned
name|char
operator|*
name|p_
block|; }
decl_stmt|;
comment|// A place holder for data written out via some other mechanism.
name|class
name|Output_data_space
range|:
name|public
name|Output_section_data
block|{
name|public
operator|:
name|Output_data_space
argument_list|(
argument|off_t data_size
argument_list|,
argument|uint64_t addralign
argument_list|)
operator|:
name|Output_section_data
argument_list|(
argument|data_size
argument_list|,
argument|addralign
argument_list|)
block|{ }
name|explicit
name|Output_data_space
argument_list|(
argument|uint64_t addralign
argument_list|)
operator|:
name|Output_section_data
argument_list|(
argument|addralign
argument_list|)
block|{ }
comment|// Set the size.
name|void
name|set_space_size
argument_list|(
argument|off_t space_size
argument_list|)
block|{
name|this
operator|->
name|set_data_size
argument_list|(
name|space_size
argument_list|)
block|; }
comment|// Set the alignment.
name|void
name|set_space_alignment
argument_list|(
argument|uint64_t align
argument_list|)
block|{
name|this
operator|->
name|set_addralign
argument_list|(
name|align
argument_list|)
block|; }
comment|// Write out the data--this must be handled elsewhere.
name|void
name|do_write
argument_list|(
argument|Output_file*
argument_list|)
block|{ }
block|}
decl_stmt|;
comment|// A string table which goes into an output section.
name|class
name|Output_data_strtab
range|:
name|public
name|Output_section_data
block|{
name|public
operator|:
name|Output_data_strtab
argument_list|(
name|Stringpool
operator|*
name|strtab
argument_list|)
operator|:
name|Output_section_data
argument_list|(
literal|1
argument_list|)
block|,
name|strtab_
argument_list|(
argument|strtab
argument_list|)
block|{ }
comment|// This is called to set the address and file offset.  Here we make
comment|// sure that the Stringpool is finalized.
name|void
name|do_set_address
argument_list|(
name|uint64_t
argument_list|,
name|off_t
argument_list|)
block|;
comment|// Write out the data.
name|void
name|do_write
argument_list|(
name|Output_file
operator|*
argument_list|)
block|;
name|private
operator|:
name|Stringpool
operator|*
name|strtab_
block|; }
decl_stmt|;
comment|// This POD class is used to represent a single reloc in the output
comment|// file.  This could be a private class within Output_data_reloc, but
comment|// the templatization is complex enough that I broke it out into a
comment|// separate class.  The class is templatized on either elfcpp::SHT_REL
comment|// or elfcpp::SHT_RELA, and also on whether this is a dynamic
comment|// relocation or an ordinary relocation.
comment|// A relocation can be against a global symbol, a local symbol, an
comment|// output section, or the undefined symbol at index 0.  We represent
comment|// the latter by using a NULL global symbol.
name|template
operator|<
name|int
name|sh_type
operator|,
name|bool
name|dynamic
operator|,
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|class
name|Output_reloc
expr_stmt|;
name|template
operator|<
name|bool
name|dynamic
operator|,
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|class
name|Output_reloc
operator|<
name|elfcpp
operator|::
name|SHT_REL
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
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
name|Address
expr_stmt|;
comment|// An uninitialized entry.  We need this because we want to put
comment|// instances of this class into an STL container.
name|Output_reloc
argument_list|()
operator|:
name|local_sym_index_
argument_list|(
argument|INVALID_CODE
argument_list|)
block|{ }
comment|// A reloc against a global symbol.
name|Output_reloc
argument_list|(
argument|Symbol* gsym
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|)
operator|:
name|address_
argument_list|(
name|address
argument_list|)
operator|,
name|local_sym_index_
argument_list|(
name|GSYM_CODE
argument_list|)
operator|,
name|type_
argument_list|(
name|type
argument_list|)
operator|,
name|shndx_
argument_list|(
argument|INVALID_CODE
argument_list|)
block|{
name|this
operator|->
name|u1_
operator|.
name|gsym
operator|=
name|gsym
block|;
name|this
operator|->
name|u2_
operator|.
name|od
operator|=
name|od
block|;   }
name|Output_reloc
argument_list|(
argument|Symbol* gsym
argument_list|,
argument|unsigned int type
argument_list|,
argument|Relobj* relobj
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|)
operator|:
name|address_
argument_list|(
name|address
argument_list|)
operator|,
name|local_sym_index_
argument_list|(
name|GSYM_CODE
argument_list|)
operator|,
name|type_
argument_list|(
name|type
argument_list|)
operator|,
name|shndx_
argument_list|(
argument|shndx
argument_list|)
block|{
name|gold_assert
argument_list|(
name|shndx
operator|!=
name|INVALID_CODE
argument_list|)
block|;
name|this
operator|->
name|u1_
operator|.
name|gsym
operator|=
name|gsym
block|;
name|this
operator|->
name|u2_
operator|.
name|relobj
operator|=
name|relobj
block|;   }
comment|// A reloc against a local symbol.
name|Output_reloc
argument_list|(
argument|Sized_relobj<size
argument_list|,
argument|big_endian>* relobj
argument_list|,
argument|unsigned int local_sym_index
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|)
operator|:
name|address_
argument_list|(
name|address
argument_list|)
operator|,
name|local_sym_index_
argument_list|(
name|local_sym_index
argument_list|)
operator|,
name|type_
argument_list|(
name|type
argument_list|)
operator|,
name|shndx_
argument_list|(
argument|INVALID_CODE
argument_list|)
block|{
name|gold_assert
argument_list|(
name|local_sym_index
operator|!=
name|GSYM_CODE
operator|&&
name|local_sym_index
operator|!=
name|INVALID_CODE
argument_list|)
block|;
name|this
operator|->
name|u1_
operator|.
name|relobj
operator|=
name|relobj
block|;
name|this
operator|->
name|u2_
operator|.
name|od
operator|=
name|od
block|;   }
name|Output_reloc
argument_list|(
argument|Sized_relobj<size
argument_list|,
argument|big_endian>* relobj
argument_list|,
argument|unsigned int local_sym_index
argument_list|,
argument|unsigned int type
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|)
operator|:
name|address_
argument_list|(
name|address
argument_list|)
operator|,
name|local_sym_index_
argument_list|(
name|local_sym_index
argument_list|)
operator|,
name|type_
argument_list|(
name|type
argument_list|)
operator|,
name|shndx_
argument_list|(
argument|shndx
argument_list|)
block|{
name|gold_assert
argument_list|(
name|local_sym_index
operator|!=
name|GSYM_CODE
operator|&&
name|local_sym_index
operator|!=
name|INVALID_CODE
argument_list|)
block|;
name|gold_assert
argument_list|(
name|shndx
operator|!=
name|INVALID_CODE
argument_list|)
block|;
name|this
operator|->
name|u1_
operator|.
name|relobj
operator|=
name|relobj
block|;
name|this
operator|->
name|u2_
operator|.
name|relobj
operator|=
name|relobj
block|;   }
comment|// A reloc against the STT_SECTION symbol of an output section.
name|Output_reloc
argument_list|(
argument|Output_section* os
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|)
operator|:
name|address_
argument_list|(
name|address
argument_list|)
operator|,
name|local_sym_index_
argument_list|(
name|SECTION_CODE
argument_list|)
operator|,
name|type_
argument_list|(
name|type
argument_list|)
operator|,
name|shndx_
argument_list|(
argument|INVALID_CODE
argument_list|)
block|{
name|this
operator|->
name|u1_
operator|.
name|os
operator|=
name|os
block|;
name|this
operator|->
name|u2_
operator|.
name|od
operator|=
name|od
block|;   }
name|Output_reloc
argument_list|(
argument|Output_section* os
argument_list|,
argument|unsigned int type
argument_list|,
argument|Relobj* relobj
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|)
operator|:
name|address_
argument_list|(
name|address
argument_list|)
operator|,
name|local_sym_index_
argument_list|(
name|SECTION_CODE
argument_list|)
operator|,
name|type_
argument_list|(
name|type
argument_list|)
operator|,
name|shndx_
argument_list|(
argument|shndx
argument_list|)
block|{
name|gold_assert
argument_list|(
name|shndx
operator|!=
name|INVALID_CODE
argument_list|)
block|;
name|this
operator|->
name|u1_
operator|.
name|os
operator|=
name|os
block|;
name|this
operator|->
name|u2_
operator|.
name|relobj
operator|=
name|relobj
block|;   }
comment|// Write the reloc entry to an output view.
name|void
name|write
argument_list|(
argument|unsigned char* pov
argument_list|)
specifier|const
expr_stmt|;
comment|// Write the offset and info fields to Write_rel.
name|template
operator|<
name|typename
name|Write_rel
operator|>
name|void
name|write_rel
argument_list|(
argument|Write_rel*
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
comment|// Return the symbol index.  We can't do a double template
comment|// specialization, so we do a secondary template here.
name|unsigned
name|int
name|get_symbol_index
argument_list|()
specifier|const
expr_stmt|;
comment|// Codes for local_sym_index_.
enum|enum
block|{
comment|// Global symbol.
name|GSYM_CODE
init|=
operator|-
literal|1U
block|,
comment|// Output section.
name|SECTION_CODE
init|=
operator|-
literal|2U
block|,
comment|// Invalid uninitialized entry.
name|INVALID_CODE
init|=
operator|-
literal|3U
block|}
enum|;
union|union
block|{
comment|// For a local symbol, the object.  We will never generate a
comment|// relocation against a local symbol in a dynamic object; that
comment|// doesn't make sense.  And our callers will always be
comment|// templatized, so we use Sized_relobj here.
name|Sized_relobj
operator|<
name|size
operator|,
name|big_endian
operator|>
operator|*
name|relobj
expr_stmt|;
comment|// For a global symbol, the symbol.  If this is NULL, it indicates
comment|// a relocation against the undefined 0 symbol.
name|Symbol
modifier|*
name|gsym
decl_stmt|;
comment|// For a relocation against an output section, the output section.
name|Output_section
modifier|*
name|os
decl_stmt|;
block|}
name|u1_
union|;
union|union
block|{
comment|// If shndx_ is not INVALID CODE, the object which holds the input
comment|// section being used to specify the reloc address.
name|Relobj
modifier|*
name|relobj
decl_stmt|;
comment|// If shndx_ is INVALID_CODE, the output data being used to
comment|// specify the reloc address.  This may be NULL if the reloc
comment|// address is absolute.
name|Output_data
modifier|*
name|od
decl_stmt|;
block|}
name|u2_
union|;
comment|// The address offset within the input section or the Output_data.
name|Address
name|address_
decl_stmt|;
comment|// For a local symbol, the local symbol index.  This is GSYM_CODE
comment|// for a global symbol, or INVALID_CODE for an uninitialized value.
name|unsigned
name|int
name|local_sym_index_
decl_stmt|;
comment|// The reloc type--a processor specific code.
name|unsigned
name|int
name|type_
decl_stmt|;
comment|// If the reloc address is an input section in an object, the
comment|// section index.  This is INVALID_CODE if the reloc address is
comment|// specified in some other way.
name|unsigned
name|int
name|shndx_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// The SHT_RELA version of Output_reloc<>.  This is just derived from
end_comment

begin_comment
comment|// the SHT_REL version of Output_reloc, but it adds an addend.
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
name|dynamic
operator|,
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|class
name|Output_reloc
operator|<
name|elfcpp
operator|::
name|SHT_RELA
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
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
name|Address
expr_stmt|;
end_expr_stmt

begin_typedef
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
name|Addend
expr_stmt|;
end_typedef

begin_comment
comment|// An uninitialized entry.
end_comment

begin_expr_stmt
name|Output_reloc
argument_list|()
operator|:
name|rel_
argument_list|()
block|{ }
comment|// A reloc against a global symbol.
name|Output_reloc
argument_list|(
argument|Symbol* gsym
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
operator|:
name|rel_
argument_list|(
name|gsym
argument_list|,
name|type
argument_list|,
name|od
argument_list|,
name|address
argument_list|)
operator|,
name|addend_
argument_list|(
argument|addend
argument_list|)
block|{ }
name|Output_reloc
argument_list|(
argument|Symbol* gsym
argument_list|,
argument|unsigned int type
argument_list|,
argument|Relobj* relobj
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
operator|:
name|rel_
argument_list|(
name|gsym
argument_list|,
name|type
argument_list|,
name|relobj
argument_list|,
name|shndx
argument_list|,
name|address
argument_list|)
operator|,
name|addend_
argument_list|(
argument|addend
argument_list|)
block|{ }
comment|// A reloc against a local symbol.
name|Output_reloc
argument_list|(
argument|Sized_relobj<size
argument_list|,
argument|big_endian>* relobj
argument_list|,
argument|unsigned int local_sym_index
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
operator|:
name|rel_
argument_list|(
name|relobj
argument_list|,
name|local_sym_index
argument_list|,
name|type
argument_list|,
name|od
argument_list|,
name|address
argument_list|)
operator|,
name|addend_
argument_list|(
argument|addend
argument_list|)
block|{ }
name|Output_reloc
argument_list|(
argument|Sized_relobj<size
argument_list|,
argument|big_endian>* relobj
argument_list|,
argument|unsigned int local_sym_index
argument_list|,
argument|unsigned int type
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
operator|:
name|rel_
argument_list|(
name|relobj
argument_list|,
name|local_sym_index
argument_list|,
name|type
argument_list|,
name|shndx
argument_list|,
name|address
argument_list|)
operator|,
name|addend_
argument_list|(
argument|addend
argument_list|)
block|{ }
comment|// A reloc against the STT_SECTION symbol of an output section.
name|Output_reloc
argument_list|(
argument|Output_section* os
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
operator|:
name|rel_
argument_list|(
name|os
argument_list|,
name|type
argument_list|,
name|od
argument_list|,
name|address
argument_list|)
operator|,
name|addend_
argument_list|(
argument|addend
argument_list|)
block|{ }
name|Output_reloc
argument_list|(
argument|Output_section* os
argument_list|,
argument|unsigned int type
argument_list|,
argument|Relobj* relobj
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
operator|:
name|rel_
argument_list|(
name|os
argument_list|,
name|type
argument_list|,
name|relobj
argument_list|,
name|shndx
argument_list|,
name|address
argument_list|)
operator|,
name|addend_
argument_list|(
argument|addend
argument_list|)
block|{ }
comment|// Write the reloc entry to an output view.
name|void
name|write
argument_list|(
argument|unsigned char* pov
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// The basic reloc.
end_comment

begin_expr_stmt
name|Output_reloc
operator|<
name|elfcpp
operator|::
name|SHT_REL
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
name|rel_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The addend.
end_comment

begin_decl_stmt
name|Addend
name|addend_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Output_data_reloc is used to manage a section containing relocs.
end_comment

begin_comment
comment|// SH_TYPE is either elfcpp::SHT_REL or elfcpp::SHT_RELA.  DYNAMIC
end_comment

begin_comment
comment|// indicates whether this is a dynamic relocation or a normal
end_comment

begin_comment
comment|// relocation.  Output_data_reloc_base is a base class.
end_comment

begin_comment
comment|// Output_data_reloc is the real class, which we specialize based on
end_comment

begin_comment
comment|// the reloc type.
end_comment

begin_expr_stmt
name|template
operator|<
name|int
name|sh_type
operator|,
name|bool
name|dynamic
operator|,
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|class
name|Output_data_reloc_base
operator|:
name|public
name|Output_section_data
block|{
name|public
operator|:
typedef|typedef
name|Output_reloc
operator|<
name|sh_type
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
name|Output_reloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Output_reloc_type
operator|::
name|Address
name|Address
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|int
name|reloc_size
init|=
name|Reloc_types
operator|<
name|sh_type
decl_stmt|,
name|size
decl_stmt|,
name|big_endian
decl|>::
name|reloc_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Construct the section.
end_comment

begin_expr_stmt
name|Output_data_reloc_base
argument_list|()
operator|:
name|Output_section_data
argument_list|(
argument|Output_data::default_alignment(size)
argument_list|)
block|{ }
comment|// Write out the data.
name|void
name|do_write
argument_list|(
name|Output_file
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|// Set the entry size and the link.
end_comment

begin_function_decl
name|void
name|do_adjust_output_section
parameter_list|(
name|Output_section
modifier|*
name|os
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Add a relocation entry.
end_comment

begin_function
name|void
name|add
parameter_list|(
specifier|const
name|Output_reloc_type
modifier|&
name|reloc
parameter_list|)
block|{
name|this
operator|->
name|relocs_
operator|.
name|push_back
argument_list|(
name|reloc
argument_list|)
expr_stmt|;
name|this
operator|->
name|set_data_size
argument_list|(
name|this
operator|->
name|relocs_
operator|.
name|size
argument_list|()
operator|*
name|reloc_size
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Output_reloc_type
operator|>
name|Relocs
expr_stmt|;
end_typedef

begin_decl_stmt
name|Relocs
name|relocs_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// The class which callers actually create.
end_comment

begin_expr_stmt
name|template
operator|<
name|int
name|sh_type
operator|,
name|bool
name|dynamic
operator|,
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|class
name|Output_data_reloc
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The SHT_REL version of Output_data_reloc.
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
name|dynamic
operator|,
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|class
name|Output_data_reloc
operator|<
name|elfcpp
operator|::
name|SHT_REL
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
operator|:
name|public
name|Output_data_reloc_base
operator|<
name|elfcpp
operator|::
name|SHT_REL
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
block|{
name|private
operator|:
typedef|typedef
name|Output_data_reloc_base
operator|<
name|elfcpp
operator|::
name|SHT_REL
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
name|Base
expr_stmt|;
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Base
operator|::
name|Output_reloc_type
name|Output_reloc_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Output_reloc_type
operator|::
name|Address
name|Address
expr_stmt|;
end_typedef

begin_expr_stmt
name|Output_data_reloc
argument_list|()
operator|:
name|Output_data_reloc_base
operator|<
name|elfcpp
operator|::
name|SHT_REL
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
operator|(
operator|)
block|{ }
comment|// Add a reloc against a global symbol.
name|void
name|add_global
argument_list|(
argument|Symbol* gsym
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|gsym
argument_list|,
name|type
argument_list|,
name|od
argument_list|,
name|address
argument_list|)
argument_list|)
block|; }
name|void
name|add_global
argument_list|(
argument|Symbol* gsym
argument_list|,
argument|unsigned int type
argument_list|,
argument|Relobj* relobj
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|gsym
argument_list|,
name|type
argument_list|,
name|relobj
argument_list|,
name|shndx
argument_list|,
name|address
argument_list|)
argument_list|)
block|; }
comment|// Add a reloc against a local symbol.
name|void
name|add_local
argument_list|(
argument|Sized_relobj<size
argument_list|,
argument|big_endian>* relobj
argument_list|,
argument|unsigned int local_sym_index
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|relobj
argument_list|,
name|local_sym_index
argument_list|,
name|type
argument_list|,
name|od
argument_list|,
name|address
argument_list|)
argument_list|)
block|; }
name|void
name|add_local
argument_list|(
argument|Sized_relobj<size
argument_list|,
argument|big_endian>* relobj
argument_list|,
argument|unsigned int local_sym_index
argument_list|,
argument|unsigned int type
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|relobj
argument_list|,
name|local_sym_index
argument_list|,
name|type
argument_list|,
name|shndx
argument_list|,
name|address
argument_list|)
argument_list|)
block|; }
comment|// A reloc against the STT_SECTION symbol of an output section.
name|void
name|add_output_section
argument_list|(
argument|Output_section* os
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|os
argument_list|,
name|type
argument_list|,
name|od
argument_list|,
name|address
argument_list|)
argument_list|)
block|; }
name|void
name|add_output_section
argument_list|(
argument|Output_section* os
argument_list|,
argument|unsigned int type
argument_list|,
argument|Relobj* relobj
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|os
argument_list|,
name|type
argument_list|,
name|relobj
argument_list|,
name|shndx
argument_list|,
name|address
argument_list|)
argument_list|)
block|; }
end_expr_stmt

begin_comment
unit|};
comment|// The SHT_RELA version of Output_data_reloc.
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
name|dynamic
operator|,
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|class
name|Output_data_reloc
operator|<
name|elfcpp
operator|::
name|SHT_RELA
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
operator|:
name|public
name|Output_data_reloc_base
operator|<
name|elfcpp
operator|::
name|SHT_RELA
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
block|{
name|private
operator|:
typedef|typedef
name|Output_data_reloc_base
operator|<
name|elfcpp
operator|::
name|SHT_RELA
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
name|Base
expr_stmt|;
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Base
operator|::
name|Output_reloc_type
name|Output_reloc_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Output_reloc_type
operator|::
name|Address
name|Address
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Output_reloc_type
operator|::
name|Addend
name|Addend
expr_stmt|;
end_typedef

begin_expr_stmt
name|Output_data_reloc
argument_list|()
operator|:
name|Output_data_reloc_base
operator|<
name|elfcpp
operator|::
name|SHT_RELA
operator|,
name|dynamic
operator|,
name|size
operator|,
name|big_endian
operator|>
operator|(
operator|)
block|{ }
comment|// Add a reloc against a global symbol.
name|void
name|add_global
argument_list|(
argument|Symbol* gsym
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|gsym
argument_list|,
name|type
argument_list|,
name|od
argument_list|,
name|address
argument_list|,
name|addend
argument_list|)
argument_list|)
block|; }
name|void
name|add_global
argument_list|(
argument|Symbol* gsym
argument_list|,
argument|unsigned int type
argument_list|,
argument|Relobj* relobj
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|gsym
argument_list|,
name|type
argument_list|,
name|relobj
argument_list|,
name|shndx
argument_list|,
name|address
argument_list|,
name|addend
argument_list|)
argument_list|)
block|; }
comment|// Add a reloc against a local symbol.
name|void
name|add_local
argument_list|(
argument|Sized_relobj<size
argument_list|,
argument|big_endian>* relobj
argument_list|,
argument|unsigned int local_sym_index
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|relobj
argument_list|,
name|local_sym_index
argument_list|,
name|type
argument_list|,
name|od
argument_list|,
name|address
argument_list|,
name|addend
argument_list|)
argument_list|)
block|;   }
name|void
name|add_local
argument_list|(
argument|Sized_relobj<size
argument_list|,
argument|big_endian>* relobj
argument_list|,
argument|unsigned int local_sym_index
argument_list|,
argument|unsigned int type
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|relobj
argument_list|,
name|local_sym_index
argument_list|,
name|type
argument_list|,
name|shndx
argument_list|,
name|address
argument_list|,
name|addend
argument_list|)
argument_list|)
block|;   }
comment|// A reloc against the STT_SECTION symbol of an output section.
name|void
name|add_output_section
argument_list|(
argument|Output_section* os
argument_list|,
argument|unsigned int type
argument_list|,
argument|Output_data* od
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|os
argument_list|,
name|type
argument_list|,
name|od
argument_list|,
name|address
argument_list|,
name|addend
argument_list|)
argument_list|)
block|; }
name|void
name|add_output_section
argument_list|(
argument|Output_section* os
argument_list|,
argument|unsigned int type
argument_list|,
argument|Relobj* relobj
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|Address address
argument_list|,
argument|Addend addend
argument_list|)
block|{
name|this
operator|->
name|add
argument_list|(
name|Output_reloc_type
argument_list|(
name|os
argument_list|,
name|type
argument_list|,
name|relobj
argument_list|,
name|shndx
argument_list|,
name|address
argument_list|,
name|addend
argument_list|)
argument_list|)
block|; }
end_expr_stmt

begin_comment
unit|};
comment|// Output_data_got is used to manage a GOT.  Each entry in the GOT is
end_comment

begin_comment
comment|// for one symbol--either a global symbol or a local symbol in an
end_comment

begin_comment
comment|// object.  The target specific code adds entries to the GOT as
end_comment

begin_comment
comment|// needed.
end_comment

begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|class
name|Output_data_got
operator|:
name|public
name|Output_section_data
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
name|Valtype
expr_stmt|;
name|Output_data_got
argument_list|(
specifier|const
name|General_options
operator|*
name|options
argument_list|)
operator|:
name|Output_section_data
argument_list|(
name|Output_data
operator|::
name|default_alignment
argument_list|(
name|size
argument_list|)
argument_list|)
operator|,
name|options_
argument_list|(
name|options
argument_list|)
operator|,
name|entries_
argument_list|()
block|{ }
comment|// Add an entry for a global symbol to the GOT.  Return true if this
comment|// is a new GOT entry, false if the symbol was already in the GOT.
name|bool
name|add_global
argument_list|(
name|Symbol
operator|*
name|gsym
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Add an entry for a local symbol to the GOT.  This returns the
end_comment

begin_comment
comment|// offset of the new entry from the start of the GOT.
end_comment

begin_function
name|unsigned
name|int
name|add_local
parameter_list|(
name|Object
modifier|*
name|object
parameter_list|,
name|unsigned
name|int
name|sym_index
parameter_list|)
block|{
name|this
operator|->
name|entries_
operator|.
name|push_back
argument_list|(
name|Got_entry
argument_list|(
name|object
argument_list|,
name|sym_index
argument_list|)
argument_list|)
expr_stmt|;
name|this
operator|->
name|set_got_size
argument_list|()
expr_stmt|;
return|return
name|this
operator|->
name|last_got_offset
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Add a constant to the GOT.  This returns the offset of the new
end_comment

begin_comment
comment|// entry from the start of the GOT.
end_comment

begin_function
name|unsigned
name|int
name|add_constant
parameter_list|(
name|Valtype
name|constant
parameter_list|)
block|{
name|this
operator|->
name|entries_
operator|.
name|push_back
argument_list|(
name|Got_entry
argument_list|(
name|constant
argument_list|)
argument_list|)
expr_stmt|;
name|this
operator|->
name|set_got_size
argument_list|()
expr_stmt|;
return|return
name|this
operator|->
name|last_got_offset
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Write out the GOT table.
end_comment

begin_function_decl
name|void
name|do_write
parameter_list|(
name|Output_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_comment
comment|// This POD class holds a single GOT entry.
end_comment

begin_decl_stmt
name|class
name|Got_entry
block|{
name|public
label|:
comment|// Create a zero entry.
name|Got_entry
argument_list|()
operator|:
name|local_sym_index_
argument_list|(
argument|CONSTANT_CODE
argument_list|)
block|{
name|this
operator|->
name|u_
operator|.
name|constant
operator|=
literal|0
block|; }
comment|// Create a global symbol entry.
name|explicit
name|Got_entry
argument_list|(
name|Symbol
operator|*
name|gsym
argument_list|)
operator|:
name|local_sym_index_
argument_list|(
argument|GSYM_CODE
argument_list|)
block|{
name|this
operator|->
name|u_
operator|.
name|gsym
operator|=
name|gsym
block|; }
comment|// Create a local symbol entry.
name|Got_entry
argument_list|(
argument|Object* object
argument_list|,
argument|unsigned int local_sym_index
argument_list|)
operator|:
name|local_sym_index_
argument_list|(
argument|local_sym_index
argument_list|)
block|{
name|gold_assert
argument_list|(
name|local_sym_index
operator|!=
name|GSYM_CODE
operator|&&
name|local_sym_index
operator|!=
name|CONSTANT_CODE
argument_list|)
block|;
name|this
operator|->
name|u_
operator|.
name|object
operator|=
name|object
block|;     }
comment|// Create a constant entry.  The constant is a host value--it will
comment|// be swapped, if necessary, when it is written out.
name|explicit
name|Got_entry
argument_list|(
argument|Valtype constant
argument_list|)
operator|:
name|local_sym_index_
argument_list|(
argument|CONSTANT_CODE
argument_list|)
block|{
name|this
operator|->
name|u_
operator|.
name|constant
operator|=
name|constant
block|; }
comment|// Write the GOT entry to an output view.
name|void
name|write
argument_list|(
argument|const General_options*
argument_list|,
argument|unsigned char* pov
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
enum|enum
block|{
name|GSYM_CODE
init|=
operator|-
literal|1U
block|,
name|CONSTANT_CODE
init|=
operator|-
literal|2U
block|}
enum|;
union|union
block|{
comment|// For a local symbol, the object.
name|Object
modifier|*
name|object
decl_stmt|;
comment|// For a global symbol, the symbol.
name|Symbol
modifier|*
name|gsym
decl_stmt|;
comment|// For a constant, the constant.
name|Valtype
name|constant
decl_stmt|;
block|}
name|u_
union|;
comment|// For a local symbol, the local symbol index.  This is GSYM_CODE
comment|// for a global symbol, or CONSTANT_CODE for a constant.
name|unsigned
name|int
name|local_sym_index_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Got_entry
operator|>
name|Got_entries
expr_stmt|;
end_typedef

begin_comment
comment|// Return the offset into the GOT of GOT entry I.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|got_offset
argument_list|(
name|unsigned
name|int
name|i
argument_list|)
decl|const
block|{
return|return
name|i
operator|*
operator|(
name|size
operator|/
literal|8
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Return the offset into the GOT of the last entry added.
end_comment

begin_expr_stmt
name|unsigned
name|int
name|last_got_offset
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|got_offset
argument_list|(
name|this
operator|->
name|entries_
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Set the size of the section.
end_comment

begin_function
name|void
name|set_got_size
parameter_list|()
block|{
name|this
operator|->
name|set_data_size
argument_list|(
name|this
operator|->
name|got_offset
argument_list|(
name|this
operator|->
name|entries_
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Options.
end_comment

begin_decl_stmt
specifier|const
name|General_options
modifier|*
name|options_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The list of GOT entries.
end_comment

begin_decl_stmt
name|Got_entries
name|entries_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Output_data_dynamic is used to hold the data in SHT_DYNAMIC
end_comment

begin_comment
comment|// section.
end_comment

begin_decl_stmt
name|class
name|Output_data_dynamic
range|:
name|public
name|Output_section_data
block|{
name|public
operator|:
name|Output_data_dynamic
argument_list|(
specifier|const
name|Target
operator|*
name|target
argument_list|,
name|Stringpool
operator|*
name|pool
argument_list|)
operator|:
name|Output_section_data
argument_list|(
name|Output_data
operator|::
name|default_alignment
argument_list|(
name|target
operator|->
name|get_size
argument_list|()
argument_list|)
argument_list|)
block|,
name|target_
argument_list|(
name|target
argument_list|)
block|,
name|entries_
argument_list|()
block|,
name|pool_
argument_list|(
argument|pool
argument_list|)
block|{ }
comment|// Add a new dynamic entry with a fixed numeric value.
name|void
name|add_constant
argument_list|(
argument|elfcpp::DT tag
argument_list|,
argument|unsigned int val
argument_list|)
block|{
name|this
operator|->
name|add_entry
argument_list|(
name|Dynamic_entry
argument_list|(
name|tag
argument_list|,
name|val
argument_list|)
argument_list|)
block|; }
comment|// Add a new dynamic entry with the address of output data.
name|void
name|add_section_address
argument_list|(
argument|elfcpp::DT tag
argument_list|,
argument|const Output_data* od
argument_list|)
block|{
name|this
operator|->
name|add_entry
argument_list|(
name|Dynamic_entry
argument_list|(
name|tag
argument_list|,
name|od
argument_list|,
name|false
argument_list|)
argument_list|)
block|; }
comment|// Add a new dynamic entry with the size of output data.
name|void
name|add_section_size
argument_list|(
argument|elfcpp::DT tag
argument_list|,
argument|const Output_data* od
argument_list|)
block|{
name|this
operator|->
name|add_entry
argument_list|(
name|Dynamic_entry
argument_list|(
name|tag
argument_list|,
name|od
argument_list|,
name|true
argument_list|)
argument_list|)
block|; }
comment|// Add a new dynamic entry with the address of a symbol.
name|void
name|add_symbol
argument_list|(
argument|elfcpp::DT tag
argument_list|,
argument|const Symbol* sym
argument_list|)
block|{
name|this
operator|->
name|add_entry
argument_list|(
name|Dynamic_entry
argument_list|(
name|tag
argument_list|,
name|sym
argument_list|)
argument_list|)
block|; }
comment|// Add a new dynamic entry with a string.
name|void
name|add_string
argument_list|(
argument|elfcpp::DT tag
argument_list|,
argument|const char* str
argument_list|)
block|{
name|this
operator|->
name|add_entry
argument_list|(
name|Dynamic_entry
argument_list|(
name|tag
argument_list|,
name|this
operator|->
name|pool_
operator|->
name|add
argument_list|(
name|str
argument_list|,
name|NULL
argument_list|)
argument_list|)
argument_list|)
block|; }
comment|// Set the final data size.
name|void
name|do_set_address
argument_list|(
name|uint64_t
argument_list|,
name|off_t
argument_list|)
block|;
comment|// Write out the dynamic entries.
name|void
name|do_write
argument_list|(
name|Output_file
operator|*
argument_list|)
block|;
name|protected
operator|:
comment|// Adjust the output section to set the entry size.
name|void
name|do_adjust_output_section
argument_list|(
name|Output_section
operator|*
argument_list|)
block|;
name|private
operator|:
comment|// This POD class holds a single dynamic entry.
name|class
name|Dynamic_entry
block|{
name|public
operator|:
comment|// Create an entry with a fixed numeric value.
name|Dynamic_entry
argument_list|(
argument|elfcpp::DT tag
argument_list|,
argument|unsigned int val
argument_list|)
operator|:
name|tag_
argument_list|(
name|tag
argument_list|)
block|,
name|classification_
argument_list|(
argument|DYNAMIC_NUMBER
argument_list|)
block|{
name|this
operator|->
name|u_
operator|.
name|val
operator|=
name|val
block|; }
comment|// Create an entry with the size or address of a section.
name|Dynamic_entry
argument_list|(
argument|elfcpp::DT tag
argument_list|,
argument|const Output_data* od
argument_list|,
argument|bool section_size
argument_list|)
operator|:
name|tag_
argument_list|(
name|tag
argument_list|)
block|,
name|classification_
argument_list|(
argument|section_size 			? DYNAMIC_SECTION_SIZE 			: DYNAMIC_SECTION_ADDRESS
argument_list|)
block|{
name|this
operator|->
name|u_
operator|.
name|od
operator|=
name|od
block|; }
comment|// Create an entry with the address of a symbol.
name|Dynamic_entry
argument_list|(
argument|elfcpp::DT tag
argument_list|,
argument|const Symbol* sym
argument_list|)
operator|:
name|tag_
argument_list|(
name|tag
argument_list|)
block|,
name|classification_
argument_list|(
argument|DYNAMIC_SYMBOL
argument_list|)
block|{
name|this
operator|->
name|u_
operator|.
name|sym
operator|=
name|sym
block|; }
comment|// Create an entry with a string.
name|Dynamic_entry
argument_list|(
argument|elfcpp::DT tag
argument_list|,
argument|const char* str
argument_list|)
operator|:
name|tag_
argument_list|(
name|tag
argument_list|)
block|,
name|classification_
argument_list|(
argument|DYNAMIC_STRING
argument_list|)
block|{
name|this
operator|->
name|u_
operator|.
name|str
operator|=
name|str
block|; }
comment|// Write the dynamic entry to an output view.
name|template
operator|<
name|int
name|size
block|,
name|bool
name|big_endian
operator|>
name|void
name|write
argument_list|(
argument|unsigned char* pov
argument_list|,
argument|const Stringpool* ACCEPT_SIZE_ENDIAN
argument_list|)
specifier|const
block|;
name|private
operator|:
expr|enum
name|Classification
block|{
comment|// Number.
name|DYNAMIC_NUMBER
block|,
comment|// Section address.
name|DYNAMIC_SECTION_ADDRESS
block|,
comment|// Section size.
name|DYNAMIC_SECTION_SIZE
block|,
comment|// Symbol adress.
name|DYNAMIC_SYMBOL
block|,
comment|// String.
name|DYNAMIC_STRING
block|}
block|;
expr|union
block|{
comment|// For DYNAMIC_NUMBER.
name|unsigned
name|int
name|val
block|;
comment|// For DYNAMIC_SECTION_ADDRESS and DYNAMIC_SECTION_SIZE.
specifier|const
name|Output_data
operator|*
name|od
block|;
comment|// For DYNAMIC_SYMBOL.
specifier|const
name|Symbol
operator|*
name|sym
block|;
comment|// For DYNAMIC_STRING.
specifier|const
name|char
operator|*
name|str
block|;     }
name|u_
block|;
comment|// The dynamic tag.
name|elfcpp
operator|::
name|DT
name|tag_
block|;
comment|// The type of entry.
name|Classification
name|classification_
block|;   }
block|;
comment|// Add an entry to the list.
name|void
name|add_entry
argument_list|(
argument|const Dynamic_entry& entry
argument_list|)
block|{
name|this
operator|->
name|entries_
operator|.
name|push_back
argument_list|(
name|entry
argument_list|)
block|; }
comment|// Sized version of write function.
name|template
operator|<
name|int
name|size
block|,
name|bool
name|big_endian
operator|>
name|void
name|sized_write
argument_list|(
name|Output_file
operator|*
name|of
argument_list|)
block|;
comment|// The type of the list of entries.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Dynamic_entry
operator|>
name|Dynamic_entries
expr_stmt|;
comment|// The target.
specifier|const
name|Target
operator|*
name|target_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The entries.
end_comment

begin_decl_stmt
name|Dynamic_entries
name|entries_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The pool used for strings.
end_comment

begin_decl_stmt
name|Stringpool
modifier|*
name|pool_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// An output section.  We don't expect to have too many output
end_comment

begin_comment
comment|// sections, so we don't bother to do a template on the size.
end_comment

begin_decl_stmt
name|class
name|Output_section
range|:
name|public
name|Output_data
block|{
name|public
operator|:
comment|// Create an output section, giving the name, type, and flags.
name|Output_section
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|elfcpp
operator|::
name|Elf_Word
argument_list|,
name|elfcpp
operator|::
name|Elf_Xword
argument_list|)
block|;
name|virtual
operator|~
name|Output_section
argument_list|()
block|;
comment|// Add a new input section SHNDX, named NAME, with header SHDR, from
comment|// object OBJECT.  Return the offset within the output section.
name|template
operator|<
name|int
name|size
block|,
name|bool
name|big_endian
operator|>
name|off_t
name|add_input_section
argument_list|(
argument|Relobj* object
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|const char *name
argument_list|,
argument|const elfcpp::Shdr<size
argument_list|,
argument|big_endian>& shdr
argument_list|)
block|;
comment|// Add generated data POSD to this output section.
name|void
name|add_output_section_data
argument_list|(
name|Output_section_data
operator|*
name|posd
argument_list|)
block|;
comment|// Return the section name.
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
comment|// Return the section type.
name|elfcpp
operator|::
name|Elf_Word
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
comment|// Return the section flags.
name|elfcpp
operator|::
name|Elf_Xword
name|flags
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|flags_
return|;
block|}
comment|// Return the section index in the output file.
name|unsigned
name|int
name|do_out_shndx
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|out_shndx_
return|;
block|}
comment|// Set the output section index.
name|void
name|do_set_out_shndx
argument_list|(
argument|unsigned int shndx
argument_list|)
block|{
name|this
operator|->
name|out_shndx_
operator|=
name|shndx
block|; }
comment|// Return the entsize field.
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
comment|// Set the entsize field.
name|void
name|set_entsize
argument_list|(
argument|uint64_t v
argument_list|)
block|;
comment|// Set the link field to the output section index of a section.
name|void
name|set_link_section
argument_list|(
argument|const Output_data* od
argument_list|)
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|link_
operator|==
literal|0
operator|&&
operator|!
name|this
operator|->
name|should_link_to_symtab_
operator|&&
operator|!
name|this
operator|->
name|should_link_to_dynsym_
argument_list|)
block|;
name|this
operator|->
name|link_section_
operator|=
name|od
block|;   }
comment|// Set the link field to a constant.
name|void
name|set_link
argument_list|(
argument|unsigned int v
argument_list|)
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|link_section_
operator|==
name|NULL
operator|&&
operator|!
name|this
operator|->
name|should_link_to_symtab_
operator|&&
operator|!
name|this
operator|->
name|should_link_to_dynsym_
argument_list|)
block|;
name|this
operator|->
name|link_
operator|=
name|v
block|;   }
comment|// Record that this section should link to the normal symbol table.
name|void
name|set_should_link_to_symtab
argument_list|()
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|link_section_
operator|==
name|NULL
operator|&&
name|this
operator|->
name|link_
operator|==
literal|0
operator|&&
operator|!
name|this
operator|->
name|should_link_to_dynsym_
argument_list|)
block|;
name|this
operator|->
name|should_link_to_symtab_
operator|=
name|true
block|;   }
comment|// Record that this section should link to the dynamic symbol table.
name|void
name|set_should_link_to_dynsym
argument_list|()
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|link_section_
operator|==
name|NULL
operator|&&
name|this
operator|->
name|link_
operator|==
literal|0
operator|&&
operator|!
name|this
operator|->
name|should_link_to_symtab_
argument_list|)
block|;
name|this
operator|->
name|should_link_to_dynsym_
operator|=
name|true
block|;   }
comment|// Return the info field.
name|unsigned
name|int
name|info
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|info_section_
operator|==
name|NULL
argument_list|)
block|;
return|return
name|this
operator|->
name|info_
return|;
block|}
comment|// Set the info field to the output section index of a section.
name|void
name|set_info_section
argument_list|(
argument|const Output_data* od
argument_list|)
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|info_
operator|==
literal|0
argument_list|)
block|;
name|this
operator|->
name|info_section_
operator|=
name|od
block|;   }
comment|// Set the info field to a constant.
name|void
name|set_info
argument_list|(
argument|unsigned int v
argument_list|)
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|info_section_
operator|==
name|NULL
argument_list|)
block|;
name|this
operator|->
name|info_
operator|=
name|v
block|;   }
comment|// Set the addralign field.
name|void
name|set_addralign
argument_list|(
argument|uint64_t v
argument_list|)
block|{
name|this
operator|->
name|addralign_
operator|=
name|v
block|; }
comment|// Indicate that we need a symtab index.
name|void
name|set_needs_symtab_index
argument_list|()
block|{
name|this
operator|->
name|needs_symtab_index_
operator|=
name|true
block|; }
comment|// Return whether we need a symtab index.
name|bool
name|needs_symtab_index
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|needs_symtab_index_
return|;
block|}
comment|// Get the symtab index.
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
comment|// Set the symtab index.
name|void
name|set_symtab_index
argument_list|(
argument|unsigned int index
argument_list|)
block|{
name|gold_assert
argument_list|(
name|index
operator|!=
literal|0
argument_list|)
block|;
name|this
operator|->
name|symtab_index_
operator|=
name|index
block|;   }
comment|// Indicate that we need a dynsym index.
name|void
name|set_needs_dynsym_index
argument_list|()
block|{
name|this
operator|->
name|needs_dynsym_index_
operator|=
name|true
block|; }
comment|// Return whether we need a dynsym index.
name|bool
name|needs_dynsym_index
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|needs_dynsym_index_
return|;
block|}
comment|// Get the dynsym index.
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
comment|// Set the dynsym index.
name|void
name|set_dynsym_index
argument_list|(
argument|unsigned int index
argument_list|)
block|{
name|gold_assert
argument_list|(
name|index
operator|!=
literal|0
argument_list|)
block|;
name|this
operator|->
name|dynsym_index_
operator|=
name|index
block|;   }
comment|// Return the output virtual address of OFFSET relative to the start
comment|// of input section SHNDX in object OBJECT.
name|uint64_t
name|output_address
argument_list|(
argument|const Relobj* object
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|off_t offset
argument_list|)
specifier|const
block|;
comment|// Set the address of the Output_section.  For a typical
comment|// Output_section, there is nothing to do, but if there are any
comment|// Output_section_data objects we need to set the final addresses
comment|// here.
name|void
name|do_set_address
argument_list|(
name|uint64_t
argument_list|,
name|off_t
argument_list|)
block|;
comment|// Write the data to the file.  For a typical Output_section, this
comment|// does nothing: the data is written out by calling Object::Relocate
comment|// on each input object.  But if there are any Output_section_data
comment|// objects we do need to write them out here.
name|void
name|do_write
argument_list|(
name|Output_file
operator|*
argument_list|)
block|;
comment|// Return the address alignment--function required by parent class.
name|uint64_t
name|do_addralign
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|addralign_
return|;
block|}
comment|// Return whether this is an Output_section.
name|bool
name|do_is_section
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|// Return whether this is a section of the specified type.
name|bool
name|do_is_section_type
argument_list|(
argument|elfcpp::Elf_Word type
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|type_
operator|==
name|type
return|;
block|}
comment|// Return whether the specified section flag is set.
name|bool
name|do_is_section_flag_set
argument_list|(
argument|elfcpp::Elf_Xword flag
argument_list|)
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|flags_
operator|&
name|flag
operator|)
operator|!=
literal|0
return|;
block|}
comment|// Write the section header into *OPHDR.
name|template
operator|<
name|int
name|size
block|,
name|bool
name|big_endian
operator|>
name|void
name|write_header
argument_list|(
argument|const Layout*
argument_list|,
argument|const Stringpool*
argument_list|,
argument|elfcpp::Shdr_write<size
argument_list|,
argument|big_endian>*
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|// In some cases we need to keep a list of the input sections
comment|// associated with this output section.  We only need the list if we
comment|// might have to change the offsets of the input section within the
comment|// output section after we add the input section.  The ordinary
comment|// input sections will be written out when we process the object
comment|// file, and as such we don't need to track them here.  We do need
comment|// to track Output_section_data objects here.  We store instances of
comment|// this structure in a std::vector, so it must be a POD.  There can
comment|// be many instances of this structure, so we use a union to save
comment|// some space.
name|class
name|Input_section
block|{
name|public
operator|:
name|Input_section
argument_list|()
operator|:
name|shndx_
argument_list|(
literal|0
argument_list|)
block|,
name|p2align_
argument_list|(
literal|0
argument_list|)
block|{
name|this
operator|->
name|u1_
operator|.
name|data_size
operator|=
literal|0
block|;
name|this
operator|->
name|u2_
operator|.
name|object
operator|=
name|NULL
block|;     }
comment|// For an ordinary input section.
name|Input_section
argument_list|(
argument|Relobj* object
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|off_t data_size
argument_list|,
argument|uint64_t addralign
argument_list|)
operator|:
name|shndx_
argument_list|(
name|shndx
argument_list|)
block|,
name|p2align_
argument_list|(
argument|ffsll(static_cast<long long>(addralign))
argument_list|)
block|{
name|gold_assert
argument_list|(
name|shndx
operator|!=
name|OUTPUT_SECTION_CODE
operator|&&
name|shndx
operator|!=
name|MERGE_DATA_SECTION_CODE
operator|&&
name|shndx
operator|!=
name|MERGE_STRING_SECTION_CODE
argument_list|)
block|;
name|this
operator|->
name|u1_
operator|.
name|data_size
operator|=
name|data_size
block|;
name|this
operator|->
name|u2_
operator|.
name|object
operator|=
name|object
block|;     }
comment|// For a non-merge output section.
name|Input_section
argument_list|(
name|Output_section_data
operator|*
name|posd
argument_list|)
operator|:
name|shndx_
argument_list|(
name|OUTPUT_SECTION_CODE
argument_list|)
block|,
name|p2align_
argument_list|(
argument|ffsll(static_cast<long long>(posd->addralign()))
argument_list|)
block|{
name|this
operator|->
name|u1_
operator|.
name|data_size
operator|=
literal|0
block|;
name|this
operator|->
name|u2_
operator|.
name|posd
operator|=
name|posd
block|;     }
comment|// For a merge section.
name|Input_section
argument_list|(
argument|Output_section_data* posd
argument_list|,
argument|bool is_string
argument_list|,
argument|uint64_t entsize
argument_list|)
operator|:
name|shndx_
argument_list|(
name|is_string
condition|?
name|MERGE_STRING_SECTION_CODE
else|:
name|MERGE_DATA_SECTION_CODE
argument_list|)
block|,
name|p2align_
argument_list|(
argument|ffsll(static_cast<long long>(posd->addralign()))
argument_list|)
block|{
name|this
operator|->
name|u1_
operator|.
name|entsize
operator|=
name|entsize
block|;
name|this
operator|->
name|u2_
operator|.
name|posd
operator|=
name|posd
block|;     }
comment|// The required alignment.
name|uint64_t
name|addralign
argument_list|()
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|p2align_
operator|==
literal|0
condition|?
literal|0
else|:
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
literal|1
operator|)
operator|<<
operator|(
name|this
operator|->
name|p2align_
operator|-
literal|1
operator|)
operator|)
return|;
block|}
comment|// Return the required size.
name|off_t
name|data_size
argument_list|()
specifier|const
block|;
comment|// Return whether this is a merge section which matches the
comment|// parameters.
name|bool
name|is_merge_section
argument_list|(
argument|bool is_string
argument_list|,
argument|uint64_t entsize
argument_list|)
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|shndx_
operator|==
operator|(
name|is_string
condition|?
name|MERGE_STRING_SECTION_CODE
else|:
name|MERGE_DATA_SECTION_CODE
operator|)
operator|&&
name|this
operator|->
name|u1_
operator|.
name|entsize
operator|==
name|entsize
operator|)
return|;
block|}
comment|// Set the output section.
name|void
name|set_output_section
argument_list|(
argument|Output_section* os
argument_list|)
block|{
name|gold_assert
argument_list|(
operator|!
name|this
operator|->
name|is_input_section
argument_list|()
argument_list|)
block|;
name|this
operator|->
name|u2_
operator|.
name|posd
operator|->
name|set_output_section
argument_list|(
name|os
argument_list|)
block|;     }
comment|// Set the address and file offset.  This is called during
comment|// Layout::finalize.  SECOFF is the file offset of the enclosing
comment|// section.
name|void
name|set_address
argument_list|(
argument|uint64_t addr
argument_list|,
argument|off_t off
argument_list|,
argument|off_t secoff
argument_list|)
block|;
comment|// Add an input section, for SHF_MERGE sections.
name|bool
name|add_input_section
argument_list|(
argument|Relobj* object
argument_list|,
argument|unsigned int shndx
argument_list|)
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|shndx_
operator|==
name|MERGE_DATA_SECTION_CODE
operator|||
name|this
operator|->
name|shndx_
operator|==
name|MERGE_STRING_SECTION_CODE
argument_list|)
block|;
return|return
name|this
operator|->
name|u2_
operator|.
name|posd
operator|->
name|add_input_section
argument_list|(
name|object
argument_list|,
name|shndx
argument_list|)
return|;
block|}
comment|// Given an input OBJECT, an input section index SHNDX within that
comment|// object, and an OFFSET relative to the start of that input
comment|// section, return whether or not the output address is known.
comment|// OUTPUT_SECTION_ADDRESS is the address of the output section
comment|// which this is a part of.  If this function returns true, it
comment|// sets *POUTPUT to the output address.
name|bool
name|output_address
argument_list|(
argument|const Relobj* object
argument_list|,
argument|unsigned int shndx
argument_list|,
argument|off_t offset
argument_list|,
argument|uint64_t output_section_address
argument_list|,
argument|uint64_t *poutput
argument_list|)
specifier|const
block|;
comment|// Write out the data.  This does nothing for an input section.
name|void
name|write
argument_list|(
name|Output_file
operator|*
argument_list|)
block|;
name|private
operator|:
comment|// Code values which appear in shndx_.  If the value is not one of
comment|// these codes, it is the input section index in the object file.
expr|enum
block|{
comment|// An Output_section_data.
name|OUTPUT_SECTION_CODE
operator|=
operator|-
literal|1U
block|,
comment|// An Output_section_data for an SHF_MERGE section with
comment|// SHF_STRINGS not set.
name|MERGE_DATA_SECTION_CODE
operator|=
operator|-
literal|2U
block|,
comment|// An Output_section_data for an SHF_MERGE section with
comment|// SHF_STRINGS set.
name|MERGE_STRING_SECTION_CODE
operator|=
operator|-
literal|3U
block|}
block|;
comment|// Whether this is an input section.
name|bool
name|is_input_section
argument_list|()
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|shndx_
operator|!=
name|OUTPUT_SECTION_CODE
operator|&&
name|this
operator|->
name|shndx_
operator|!=
name|MERGE_DATA_SECTION_CODE
operator|&&
name|this
operator|->
name|shndx_
operator|!=
name|MERGE_STRING_SECTION_CODE
operator|)
return|;
block|}
comment|// For an ordinary input section, this is the section index in the
comment|// input file.  For an Output_section_data, this is
comment|// OUTPUT_SECTION_CODE or MERGE_DATA_SECTION_CODE or
comment|// MERGE_STRING_SECTION_CODE.
name|unsigned
name|int
name|shndx_
block|;
comment|// The required alignment, stored as a power of 2.
name|unsigned
name|int
name|p2align_
block|;
expr|union
block|{
comment|// For an ordinary input section, the section size.
name|off_t
name|data_size
block|;
comment|// For OUTPUT_SECTION_CODE, this is not used.  For
comment|// MERGE_DATA_SECTION_CODE or MERGE_STRING_SECTION_CODE, the
comment|// entity size.
name|uint64_t
name|entsize
block|;     }
name|u1_
block|;
expr|union
block|{
comment|// For an ordinary input section, the object which holds the
comment|// input section.
name|Relobj
operator|*
name|object
block|;
comment|// For OUTPUT_SECTION_CODE or MERGE_DATA_SECTION_CODE or
comment|// MERGE_STRING_SECTION_CODE, the data.
name|Output_section_data
operator|*
name|posd
block|;     }
name|u2_
block|;   }
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Input_section
operator|>
name|Input_section_list
expr_stmt|;
comment|// Add a new output section by Input_section.
name|void
name|add_output_section_data
argument_list|(
name|Input_section
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Add an SHF_MERGE input section.  Returns true if the section was
end_comment

begin_comment
comment|// handled.
end_comment

begin_function_decl
name|bool
name|add_merge_input_section
parameter_list|(
name|Relobj
modifier|*
name|object
parameter_list|,
name|unsigned
name|int
name|shndx
parameter_list|,
name|uint64_t
name|flags
parameter_list|,
name|uint64_t
name|entsize
parameter_list|,
name|uint64_t
name|addralign
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Add an output SHF_MERGE section POSD to this output section.
end_comment

begin_comment
comment|// IS_STRING indicates whether it is a SHF_STRINGS section, and
end_comment

begin_comment
comment|// ENTSIZE is the entity size.  This returns the entry added to
end_comment

begin_comment
comment|// input_sections_.
end_comment

begin_function_decl
name|void
name|add_output_merge_section
parameter_list|(
name|Output_section_data
modifier|*
name|posd
parameter_list|,
name|bool
name|is_string
parameter_list|,
name|uint64_t
name|entsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Most of these fields are only valid after layout.
end_comment

begin_comment
comment|// The name of the section.  This will point into a Stringpool.
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|name_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The section address is in the parent class.
end_comment

begin_comment
comment|// The section alignment.
end_comment

begin_decl_stmt
name|uint64_t
name|addralign_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The section entry size.
end_comment

begin_decl_stmt
name|uint64_t
name|entsize_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The file offset is in the parent class.
end_comment

begin_comment
comment|// Set the section link field to the index of this section.
end_comment

begin_decl_stmt
specifier|const
name|Output_data
modifier|*
name|link_section_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If link_section_ is NULL, this is the link field.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|link_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Set the section info field to the index of this section.
end_comment

begin_decl_stmt
specifier|const
name|Output_data
modifier|*
name|info_section_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If info_section_ is NULL, this is the section info field.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|info_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The section type.
end_comment

begin_expr_stmt
name|elfcpp
operator|::
name|Elf_Word
name|type_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The section flags.
end_comment

begin_expr_stmt
name|elfcpp
operator|::
name|Elf_Xword
name|flags_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The section index.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|out_shndx_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If there is a STT_SECTION for this output section in the normal
end_comment

begin_comment
comment|// symbol table, this is the symbol index.  This starts out as zero.
end_comment

begin_comment
comment|// It is initialized in Layout::finalize() to be the index, or -1U
end_comment

begin_comment
comment|// if there isn't one.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|symtab_index_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If there is a STT_SECTION for this output section in the dynamic
end_comment

begin_comment
comment|// symbol table, this is the symbol index.  This starts out as zero.
end_comment

begin_comment
comment|// It is initialized in Layout::finalize() to be the index, or -1U
end_comment

begin_comment
comment|// if there isn't one.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|dynsym_index_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The input sections.  This will be empty in cases where we don't
end_comment

begin_comment
comment|// need to keep track of them.
end_comment

begin_decl_stmt
name|Input_section_list
name|input_sections_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The offset of the first entry in input_sections_.
end_comment

begin_decl_stmt
name|off_t
name|first_input_offset_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether this output section needs a STT_SECTION symbol in the
end_comment

begin_comment
comment|// normal symbol table.  This will be true if there is a relocation
end_comment

begin_comment
comment|// which needs it.
end_comment

begin_decl_stmt
name|bool
name|needs_symtab_index_
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether this output section needs a STT_SECTION symbol in the
end_comment

begin_comment
comment|// dynamic symbol table.  This will be true if there is a dynamic
end_comment

begin_comment
comment|// relocation which needs it.
end_comment

begin_decl_stmt
name|bool
name|needs_dynsym_index_
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether the link field of this output section should point to the
end_comment

begin_comment
comment|// normal symbol table.
end_comment

begin_decl_stmt
name|bool
name|should_link_to_symtab_
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether the link field of this output section should point to the
end_comment

begin_comment
comment|// dynamic symbol table.
end_comment

begin_decl_stmt
name|bool
name|should_link_to_dynsym_
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// An output segment.  PT_LOAD segments are built from collections of
end_comment

begin_comment
comment|// output sections.  Other segments typically point within PT_LOAD
end_comment

begin_comment
comment|// segments, and are built directly as needed.
end_comment

begin_decl_stmt
name|class
name|Output_segment
block|{
name|public
label|:
comment|// Create an output segment, specifying the type and flags.
name|Output_segment
argument_list|(
name|elfcpp
operator|::
name|Elf_Word
argument_list|,
name|elfcpp
operator|::
name|Elf_Word
argument_list|)
expr_stmt|;
comment|// Return the virtual address.
name|uint64_t
name|vaddr
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|vaddr_
return|;
block|}
comment|// Return the physical address.
name|uint64_t
name|paddr
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|paddr_
return|;
block|}
comment|// Return the segment type.
name|elfcpp
operator|::
name|Elf_Word
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
comment|// Return the segment flags.
name|elfcpp
operator|::
name|Elf_Word
name|flags
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|flags_
return|;
block|}
comment|// Return the memory size.
name|uint64_t
name|memsz
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|memsz_
return|;
block|}
comment|// Return the file size.
name|off_t
name|filesz
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|filesz_
return|;
block|}
comment|// Return the maximum alignment of the Output_data.
name|uint64_t
name|addralign
parameter_list|()
function_decl|;
comment|// Add an Output_section to this segment.
name|void
name|add_output_section
argument_list|(
name|Output_section
operator|*
name|os
argument_list|,
name|elfcpp
operator|::
name|Elf_Word
name|seg_flags
argument_list|)
block|{
name|this
operator|->
name|add_output_section
argument_list|(
name|os
argument_list|,
name|seg_flags
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
comment|// Add an Output_section to the start of this segment.
name|void
name|add_initial_output_section
argument_list|(
name|Output_section
operator|*
name|os
argument_list|,
name|elfcpp
operator|::
name|Elf_Word
name|seg_flags
argument_list|)
block|{
name|this
operator|->
name|add_output_section
argument_list|(
name|os
argument_list|,
name|seg_flags
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
comment|// Add an Output_data (which is not an Output_section) to the start
comment|// of this segment.
name|void
name|add_initial_output_data
parameter_list|(
name|Output_data
modifier|*
parameter_list|)
function_decl|;
comment|// Set the address of the segment to ADDR and the offset to *POFF
comment|// (aligned if necessary), and set the addresses and offsets of all
comment|// contained output sections accordingly.  Set the section indexes
comment|// of all contained output sections starting with *PSHNDX.  Return
comment|// the address of the immediately following segment.  Update *POFF
comment|// and *PSHNDX.  This should only be called for a PT_LOAD segment.
name|uint64_t
name|set_section_addresses
parameter_list|(
name|uint64_t
name|addr
parameter_list|,
name|off_t
modifier|*
name|poff
parameter_list|,
name|unsigned
name|int
modifier|*
name|pshndx
parameter_list|)
function_decl|;
comment|// Set the offset of this segment based on the section.  This should
comment|// only be called for a non-PT_LOAD segment.
name|void
name|set_offset
parameter_list|()
function_decl|;
comment|// Return the number of output sections.
name|unsigned
name|int
name|output_section_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Write the segment header into *OPHDR.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|write_header
argument_list|(
name|elfcpp
operator|::
name|Phdr_write
operator|<
name|size
argument_list|,
name|big_endian
operator|>
operator|*
argument_list|)
expr_stmt|;
comment|// Write the section headers of associated sections into V.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|unsigned
name|char
operator|*
name|write_section_headers
argument_list|(
argument|const Layout*
argument_list|,
argument|const Stringpool*
argument_list|,
argument|unsigned char* v
argument_list|,
argument|unsigned int* pshndx ACCEPT_SIZE_ENDIAN
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
name|Output_segment
argument_list|(
specifier|const
name|Output_segment
operator|&
argument_list|)
expr_stmt|;
name|Output_segment
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Output_segment
operator|&
operator|)
decl_stmt|;
typedef|typedef
name|std
operator|::
name|list
operator|<
name|Output_data
operator|*
operator|>
name|Output_data_list
expr_stmt|;
comment|// Add an Output_section to this segment, specifying front or back.
name|void
name|add_output_section
argument_list|(
name|Output_section
operator|*
argument_list|,
name|elfcpp
operator|::
name|Elf_Word
name|seg_flags
argument_list|,
name|bool
name|front
argument_list|)
decl_stmt|;
comment|// Find the maximum alignment in an Output_data_list.
specifier|static
name|uint64_t
name|maximum_alignment
parameter_list|(
specifier|const
name|Output_data_list
modifier|*
parameter_list|)
function_decl|;
comment|// Set the section addresses in an Output_data_list.
name|uint64_t
name|set_section_list_addresses
parameter_list|(
name|Output_data_list
modifier|*
parameter_list|,
name|uint64_t
name|addr
parameter_list|,
name|off_t
modifier|*
name|poff
parameter_list|,
name|unsigned
name|int
modifier|*
name|pshndx
parameter_list|)
function_decl|;
comment|// Return the number of Output_sections in an Output_data_list.
name|unsigned
name|int
name|output_section_count_list
argument_list|(
specifier|const
name|Output_data_list
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|// Write the section headers in the list into V.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|unsigned
name|char
operator|*
name|write_section_headers_list
argument_list|(
argument|const Layout*
argument_list|,
argument|const Stringpool*
argument_list|,
argument|const Output_data_list*
argument_list|,
argument|unsigned char* v
argument_list|,
argument|unsigned int* pshdx ACCEPT_SIZE_ENDIAN
argument_list|)
specifier|const
expr_stmt|;
comment|// The list of output data with contents attached to this segment.
name|Output_data_list
name|output_data_
decl_stmt|;
comment|// The list of output data without contents attached to this segment.
name|Output_data_list
name|output_bss_
decl_stmt|;
comment|// The segment virtual address.
name|uint64_t
name|vaddr_
decl_stmt|;
comment|// The segment physical address.
name|uint64_t
name|paddr_
decl_stmt|;
comment|// The size of the segment in memory.
name|uint64_t
name|memsz_
decl_stmt|;
comment|// The segment alignment.
name|uint64_t
name|align_
decl_stmt|;
comment|// The offset of the segment data within the file.
name|off_t
name|offset_
decl_stmt|;
comment|// The size of the segment data in the file.
name|off_t
name|filesz_
decl_stmt|;
comment|// The segment type;
name|elfcpp
operator|::
name|Elf_Word
name|type_
expr_stmt|;
comment|// The segment flags.
name|elfcpp
operator|::
name|Elf_Word
name|flags_
expr_stmt|;
comment|// Whether we have set align_.
name|bool
name|is_align_known_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This class represents the output file.
end_comment

begin_decl_stmt
name|class
name|Output_file
block|{
name|public
label|:
name|Output_file
argument_list|(
specifier|const
name|General_options
operator|&
name|options
argument_list|)
expr_stmt|;
comment|// Open the output file.  FILE_SIZE is the final size of the file.
name|void
name|open
parameter_list|(
name|off_t
name|file_size
parameter_list|)
function_decl|;
comment|// Close the output file and make sure there are no error.
name|void
name|close
parameter_list|()
function_decl|;
comment|// We currently always use mmap which makes the view handling quite
comment|// simple.  In the future we may support other approaches.
comment|// Write data to the output file.
name|void
name|write
parameter_list|(
name|off_t
name|offset
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|off_t
name|len
parameter_list|)
block|{
name|memcpy
argument_list|(
name|this
operator|->
name|base_
operator|+
name|offset
argument_list|,
name|data
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
comment|// Get a buffer to use to write to the file, given the offset into
comment|// the file and the size.
name|unsigned
name|char
modifier|*
name|get_output_view
parameter_list|(
name|off_t
name|start
parameter_list|,
name|off_t
name|size
parameter_list|)
block|{
name|gold_assert
argument_list|(
name|start
operator|>=
literal|0
operator|&&
name|size
operator|>=
literal|0
operator|&&
name|start
operator|+
name|size
operator|<=
name|this
operator|->
name|file_size_
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|base_
operator|+
name|start
return|;
block|}
comment|// VIEW must have been returned by get_output_view.  Write the
comment|// buffer to the file, passing in the offset and the size.
name|void
name|write_output_view
parameter_list|(
name|off_t
parameter_list|,
name|off_t
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
block|{ }
name|private
label|:
comment|// General options.
specifier|const
name|General_options
modifier|&
name|options_
decl_stmt|;
comment|// File name.
specifier|const
name|char
modifier|*
name|name_
decl_stmt|;
comment|// File descriptor.
name|int
name|o_
decl_stmt|;
comment|// File size.
name|off_t
name|file_size_
decl_stmt|;
comment|// Base of file mapped into memory.
name|unsigned
name|char
modifier|*
name|base_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_OUTPUT_H)
end_comment

end_unit

