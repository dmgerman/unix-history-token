begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// object.h -- support for an object file for linking in gold  -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_OBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_OBJECT_H
end_define

begin_include
include|#
directive|include
file|<string>
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
file|"elfcpp_file.h"
end_include

begin_include
include|#
directive|include
file|"fileread.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|General_options
decl_stmt|;
name|class
name|Layout
decl_stmt|;
name|class
name|Output_section
decl_stmt|;
name|class
name|Output_file
decl_stmt|;
name|class
name|Dynobj
decl_stmt|;
name|template
operator|<
name|typename
name|Stringpool_char
operator|>
name|class
name|Stringpool_template
expr_stmt|;
comment|// Data to pass from read_symbols() to add_symbols().
struct|struct
name|Read_symbols_data
block|{
comment|// Section headers.
name|File_view
modifier|*
name|section_headers
decl_stmt|;
comment|// Section names.
name|File_view
modifier|*
name|section_names
decl_stmt|;
comment|// Size of section name data in bytes.
name|off_t
name|section_names_size
decl_stmt|;
comment|// Symbol data.
name|File_view
modifier|*
name|symbols
decl_stmt|;
comment|// Size of symbol data in bytes.
name|off_t
name|symbols_size
decl_stmt|;
comment|// Symbol names.
name|File_view
modifier|*
name|symbol_names
decl_stmt|;
comment|// Size of symbol name data in bytes.
name|off_t
name|symbol_names_size
decl_stmt|;
comment|// Version information.  This is only used on dynamic objects.
comment|// Version symbol data (from SHT_GNU_versym section).
name|File_view
modifier|*
name|versym
decl_stmt|;
name|off_t
name|versym_size
decl_stmt|;
comment|// Version definition data (from SHT_GNU_verdef section).
name|File_view
modifier|*
name|verdef
decl_stmt|;
name|off_t
name|verdef_size
decl_stmt|;
name|unsigned
name|int
name|verdef_info
decl_stmt|;
comment|// Needed version data  (from SHT_GNU_verneed section).
name|File_view
modifier|*
name|verneed
decl_stmt|;
name|off_t
name|verneed_size
decl_stmt|;
name|unsigned
name|int
name|verneed_info
decl_stmt|;
block|}
struct|;
comment|// Data about a single relocation section.  This is read in
comment|// read_relocs and processed in scan_relocs.
struct|struct
name|Section_relocs
block|{
comment|// Index of reloc section.
name|unsigned
name|int
name|reloc_shndx
decl_stmt|;
comment|// Index of section that relocs apply to.
name|unsigned
name|int
name|data_shndx
decl_stmt|;
comment|// Contents of reloc section.
name|File_view
modifier|*
name|contents
decl_stmt|;
comment|// Reloc section type.
name|unsigned
name|int
name|sh_type
decl_stmt|;
comment|// Number of reloc entries.
name|size_t
name|reloc_count
decl_stmt|;
block|}
struct|;
comment|// Relocations in an object file.  This is read in read_relocs and
comment|// processed in scan_relocs.
struct|struct
name|Read_relocs_data
block|{
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Section_relocs
operator|>
name|Relocs_list
expr_stmt|;
comment|// The relocations.
name|Relocs_list
name|relocs
decl_stmt|;
comment|// The local symbols.
name|File_view
modifier|*
name|local_symbols
decl_stmt|;
block|}
struct|;
comment|// Object is an abstract base class which represents either a 32-bit
comment|// or a 64-bit input object.  This can be a regular object file
comment|// (ET_REL) or a shared object (ET_DYN).
name|class
name|Object
block|{
name|public
label|:
comment|// NAME is the name of the object as we would report it to the user
comment|// (e.g., libfoo.a(bar.o) if this is in an archive.  INPUT_FILE is
comment|// used to read the file.  OFFSET is the offset within the input
comment|// file--0 for a .o or .so file, something else for a .a file.
name|Object
argument_list|(
argument|const std::string& name
argument_list|,
argument|Input_file* input_file
argument_list|,
argument|bool is_dynamic
argument_list|,
argument|off_t offset =
literal|0
argument_list|)
block|:
name|name_
argument_list|(
name|name
argument_list|)
operator|,
name|input_file_
argument_list|(
name|input_file
argument_list|)
operator|,
name|offset_
argument_list|(
name|offset
argument_list|)
operator|,
name|shnum_
argument_list|(
operator|-
literal|1U
argument_list|)
operator|,
name|is_dynamic_
argument_list|(
name|is_dynamic
argument_list|)
operator|,
name|target_
argument_list|(
argument|NULL
argument_list|)
block|{ }
name|virtual
operator|~
name|Object
argument_list|()
block|{ }
comment|// Return the name of the object as we would report it to the tuser.
specifier|const
name|std
operator|::
name|string
operator|&
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
comment|// Return whether this is a dynamic object.
name|bool
name|is_dynamic
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|is_dynamic_
return|;
block|}
comment|// Return the target structure associated with this object.
name|Target
operator|*
name|target
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|target_
return|;
block|}
comment|// Lock the underlying file.
name|void
name|lock
parameter_list|()
block|{
name|this
operator|->
name|input_file_
operator|->
name|file
argument_list|()
operator|.
name|lock
argument_list|()
expr_stmt|;
block|}
comment|// Unlock the underlying file.
name|void
name|unlock
parameter_list|()
block|{
name|this
operator|->
name|input_file_
operator|->
name|file
argument_list|()
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
comment|// Return whether the underlying file is locked.
name|bool
name|is_locked
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|input_file_
operator|->
name|file
argument_list|()
operator|.
name|is_locked
argument_list|()
return|;
block|}
comment|// Return the sized target structure associated with this object.
comment|// This is like the target method but it returns a pointer of
comment|// appropriate checked type.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|Sized_target
operator|<
name|size
operator|,
name|big_endian
operator|>
operator|*
name|sized_target
argument_list|(
name|ACCEPT_SIZE_ENDIAN_ONLY
argument_list|)
expr_stmt|;
comment|// Get the number of sections.
name|unsigned
name|int
name|shnum
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|shnum_
return|;
block|}
comment|// Return a view of the contents of a section.  Set *PLEN to the
comment|// size.
specifier|const
name|unsigned
name|char
modifier|*
name|section_contents
parameter_list|(
name|unsigned
name|int
name|shndx
parameter_list|,
name|off_t
modifier|*
name|plen
parameter_list|)
function_decl|;
comment|// Return the name of a section given a section index.  This is only
comment|// used for error messages.
name|std
operator|::
name|string
name|section_name
argument_list|(
argument|unsigned int shndx
argument_list|)
block|{
return|return
name|this
operator|->
name|do_section_name
argument_list|(
name|shndx
argument_list|)
return|;
block|}
comment|// Return the section flags given a section index.
name|uint64_t
name|section_flags
parameter_list|(
name|unsigned
name|int
name|shndx
parameter_list|)
block|{
return|return
name|this
operator|->
name|do_section_flags
argument_list|(
name|shndx
argument_list|)
return|;
block|}
comment|// Read the symbol information.
name|void
name|read_symbols
parameter_list|(
name|Read_symbols_data
modifier|*
name|sd
parameter_list|)
block|{
return|return
name|this
operator|->
name|do_read_symbols
argument_list|(
name|sd
argument_list|)
return|;
block|}
comment|// Pass sections which should be included in the link to the Layout
comment|// object, and record where the sections go in the output file.
name|void
name|layout
parameter_list|(
specifier|const
name|General_options
modifier|&
name|options
parameter_list|,
name|Symbol_table
modifier|*
name|symtab
parameter_list|,
name|Layout
modifier|*
name|layout
parameter_list|,
name|Read_symbols_data
modifier|*
name|sd
parameter_list|)
block|{
name|this
operator|->
name|do_layout
argument_list|(
name|options
argument_list|,
name|symtab
argument_list|,
name|layout
argument_list|,
name|sd
argument_list|)
expr_stmt|;
block|}
comment|// Add symbol information to the global symbol table.
name|void
name|add_symbols
parameter_list|(
name|Symbol_table
modifier|*
name|symtab
parameter_list|,
name|Read_symbols_data
modifier|*
name|sd
parameter_list|)
block|{
name|this
operator|->
name|do_add_symbols
argument_list|(
name|symtab
argument_list|,
name|sd
argument_list|)
expr_stmt|;
block|}
comment|// Functions and types for the elfcpp::Elf_file interface.  This
comment|// permit us to use Object as the File template parameter for
comment|// elfcpp::Elf_file.
comment|// The View class is returned by view.  It must support a single
comment|// method, data().  This is trivial, because get_view does what we
comment|// need.
name|class
name|View
block|{
name|public
label|:
name|View
argument_list|(
argument|const unsigned char* p
argument_list|)
block|:
name|p_
argument_list|(
argument|p
argument_list|)
block|{ }
specifier|const
name|unsigned
name|char
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|p_
return|;
block|}
name|private
label|:
specifier|const
name|unsigned
name|char
modifier|*
name|p_
decl_stmt|;
block|}
empty_stmt|;
comment|// Return a View.
name|View
name|view
parameter_list|(
name|off_t
name|file_offset
parameter_list|,
name|off_t
name|data_size
parameter_list|)
block|{
return|return
name|View
argument_list|(
name|this
operator|->
name|get_view
argument_list|(
name|file_offset
argument_list|,
name|data_size
argument_list|)
argument_list|)
return|;
block|}
comment|// Report an error.
name|void
name|error
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_2
decl_stmt|;
comment|// A location in the file.
struct|struct
name|Location
block|{
name|off_t
name|file_offset
decl_stmt|;
name|off_t
name|data_size
decl_stmt|;
name|Location
argument_list|(
argument|off_t fo
argument_list|,
argument|off_t ds
argument_list|)
block|:
name|file_offset
argument_list|(
name|fo
argument_list|)
operator|,
name|data_size
argument_list|(
argument|ds
argument_list|)
block|{ }
block|}
struct|;
comment|// Get a View given a Location.
name|View
name|view
parameter_list|(
name|Location
name|loc
parameter_list|)
block|{
return|return
name|View
argument_list|(
name|this
operator|->
name|get_view
argument_list|(
name|loc
operator|.
name|file_offset
argument_list|,
name|loc
operator|.
name|data_size
argument_list|)
argument_list|)
return|;
block|}
name|protected
label|:
comment|// Read the symbols--implemented by child class.
name|virtual
name|void
name|do_read_symbols
parameter_list|(
name|Read_symbols_data
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Lay out sections--implemented by child class.
name|virtual
name|void
name|do_layout
parameter_list|(
specifier|const
name|General_options
modifier|&
parameter_list|,
name|Symbol_table
modifier|*
parameter_list|,
name|Layout
modifier|*
parameter_list|,
name|Read_symbols_data
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Add symbol information to the global symbol table--implemented by
comment|// child class.
name|virtual
name|void
name|do_add_symbols
parameter_list|(
name|Symbol_table
modifier|*
parameter_list|,
name|Read_symbols_data
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Return the location of the contents of a section.  Implemented by
comment|// child class.
name|virtual
name|Location
name|do_section_contents
parameter_list|(
name|unsigned
name|int
name|shndx
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Get the name of a section--implemented by child class.
name|virtual
name|std
operator|::
name|string
name|do_section_name
argument_list|(
argument|unsigned int shndx
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|// Get section flags--implemented by child class.
name|virtual
name|uint64_t
name|do_section_flags
parameter_list|(
name|unsigned
name|int
name|shndx
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Get the file.
name|Input_file
operator|*
name|input_file
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|input_file_
return|;
block|}
comment|// Get the offset into the file.
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
comment|// Get a view into the underlying file.
specifier|const
name|unsigned
name|char
modifier|*
name|get_view
parameter_list|(
name|off_t
name|start
parameter_list|,
name|off_t
name|size
parameter_list|)
block|{
return|return
name|this
operator|->
name|input_file_
operator|->
name|file
argument_list|()
operator|.
name|get_view
argument_list|(
name|start
operator|+
name|this
operator|->
name|offset_
argument_list|,
name|size
argument_list|)
return|;
block|}
comment|// Get a lasting view into the underlying file.
name|File_view
modifier|*
name|get_lasting_view
parameter_list|(
name|off_t
name|start
parameter_list|,
name|off_t
name|size
parameter_list|)
block|{
return|return
name|this
operator|->
name|input_file_
operator|->
name|file
argument_list|()
operator|.
name|get_lasting_view
argument_list|(
name|start
operator|+
name|this
operator|->
name|offset_
argument_list|,
name|size
argument_list|)
return|;
block|}
comment|// Read data from the underlying file.
name|void
name|read
parameter_list|(
name|off_t
name|start
parameter_list|,
name|off_t
name|size
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
block|{
name|this
operator|->
name|input_file_
operator|->
name|file
argument_list|()
operator|.
name|read
argument_list|(
name|start
operator|+
name|this
operator|->
name|offset_
argument_list|,
name|size
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
comment|// Set the target.
name|void
name|set_target
parameter_list|(
name|int
name|machine
parameter_list|,
name|int
name|size
parameter_list|,
name|bool
name|big_endian
parameter_list|,
name|int
name|osabi
parameter_list|,
name|int
name|abiversion
parameter_list|)
function_decl|;
comment|// Set the number of sections.
name|void
name|set_shnum
parameter_list|(
name|int
name|shnum
parameter_list|)
block|{
name|this
operator|->
name|shnum_
operator|=
name|shnum
expr_stmt|;
block|}
comment|// Functions used by both Sized_relobj and Sized_dynobj.
comment|// Read the section data into a Read_symbols_data object.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|read_section_data
argument_list|(
name|elfcpp
operator|::
name|Elf_file
operator|<
name|size
argument_list|,
name|big_endian
argument_list|,
name|Object
operator|>
operator|*
argument_list|,
name|Read_symbols_data
operator|*
argument_list|)
expr_stmt|;
comment|// If NAME is the name of a special .gnu.warning section, arrange
comment|// for the warning to be issued.  SHNDX is the section index.
comment|// Return whether it is a warning section.
name|bool
name|handle_gnu_warning_section
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|shndx
parameter_list|,
name|Symbol_table
modifier|*
parameter_list|)
function_decl|;
name|private
label|:
comment|// This class may not be copied.
name|Object
argument_list|(
specifier|const
name|Object
operator|&
argument_list|)
expr_stmt|;
name|Object
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Object
operator|&
operator|)
decl_stmt|;
comment|// Name of object as printed to user.
name|std
operator|::
name|string
name|name_
expr_stmt|;
comment|// For reading the file.
name|Input_file
modifier|*
name|input_file_
decl_stmt|;
comment|// Offset within the file--0 for an object file, non-0 for an
comment|// archive.
name|off_t
name|offset_
decl_stmt|;
comment|// Number of input sections.
name|unsigned
name|int
name|shnum_
decl_stmt|;
comment|// Whether this is a dynamic object.
name|bool
name|is_dynamic_
decl_stmt|;
comment|// Target functions--may be NULL if the target is not known.
name|Target
modifier|*
name|target_
decl_stmt|;
block|}
empty_stmt|;
comment|// Implement sized_target inline for efficiency.  This approach breaks
comment|// static type checking, but is made safe using asserts.
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
specifier|inline
name|Sized_target
operator|<
name|size
operator|,
name|big_endian
operator|>
operator|*
name|Object
operator|::
name|sized_target
argument_list|(
argument|ACCEPT_SIZE_ENDIAN_ONLY
argument_list|)
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|target_
operator|->
name|get_size
argument_list|()
operator|==
name|size
argument_list|)
block|;
name|gold_assert
argument_list|(
name|this
operator|->
name|target_
operator|->
name|is_big_endian
argument_list|()
condition|?
name|big_endian
else|:
operator|!
name|big_endian
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|Sized_target
operator|<
name|size
operator|,
name|big_endian
operator|>
operator|*
operator|>
operator|(
name|this
operator|->
name|target_
operator|)
return|;
block|}
comment|// A regular object (ET_REL).  This is an abstract base class itself.
comment|// The implementation is the template class Sized_relobj.
name|class
name|Relobj
range|:
name|public
name|Object
block|{
name|public
operator|:
name|Relobj
argument_list|(
argument|const std::string& name
argument_list|,
argument|Input_file* input_file
argument_list|,
argument|off_t offset =
literal|0
argument_list|)
operator|:
name|Object
argument_list|(
argument|name
argument_list|,
argument|input_file
argument_list|,
argument|false
argument_list|,
argument|offset
argument_list|)
block|{ }
comment|// Read the relocs.
name|void
name|read_relocs
argument_list|(
argument|Read_relocs_data* rd
argument_list|)
block|{
return|return
name|this
operator|->
name|do_read_relocs
argument_list|(
name|rd
argument_list|)
return|;
block|}
comment|// Scan the relocs and adjust the symbol table.
name|void
name|scan_relocs
argument_list|(
argument|const General_options& options
argument_list|,
argument|Symbol_table* symtab
argument_list|,
argument|Layout* layout
argument_list|,
argument|Read_relocs_data* rd
argument_list|)
block|{
return|return
name|this
operator|->
name|do_scan_relocs
argument_list|(
name|options
argument_list|,
name|symtab
argument_list|,
name|layout
argument_list|,
name|rd
argument_list|)
return|;
block|}
comment|// Initial local symbol processing: set the offset where local
comment|// symbol information will be stored; add local symbol names to
comment|// *POOL; return the new local symbol index.
name|unsigned
name|int
name|finalize_local_symbols
argument_list|(
argument|unsigned int index
argument_list|,
argument|off_t off
argument_list|,
argument|Stringpool_template<char>* pool
argument_list|)
block|{
return|return
name|this
operator|->
name|do_finalize_local_symbols
argument_list|(
name|index
argument_list|,
name|off
argument_list|,
name|pool
argument_list|)
return|;
block|}
comment|// Relocate the input sections and write out the local symbols.
name|void
name|relocate
argument_list|(
argument|const General_options& options
argument_list|,
argument|const Symbol_table* symtab
argument_list|,
argument|const Layout* layout
argument_list|,
argument|Output_file* of
argument_list|)
block|{
return|return
name|this
operator|->
name|do_relocate
argument_list|(
name|options
argument_list|,
name|symtab
argument_list|,
name|layout
argument_list|,
name|of
argument_list|)
return|;
block|}
comment|// Return whether an input section is being included in the link.
name|bool
name|is_section_included
argument_list|(
argument|unsigned int shndx
argument_list|)
specifier|const
block|{
name|gold_assert
argument_list|(
name|shndx
operator|<
name|this
operator|->
name|map_to_output_
operator|.
name|size
argument_list|()
argument_list|)
block|;
return|return
name|this
operator|->
name|map_to_output_
index|[
name|shndx
index|]
operator|.
name|output_section
operator|!=
name|NULL
return|;
block|}
comment|// Given a section index, return the corresponding Output_section
comment|// (which will be NULL if the section is not included in the link)
comment|// and set *POFF to the offset within that section.
specifier|inline
name|Output_section
operator|*
name|output_section
argument_list|(
argument|unsigned int shndx
argument_list|,
argument|off_t* poff
argument_list|)
specifier|const
block|;
comment|// Set the offset of an input section within its output section.
name|void
name|set_section_offset
argument_list|(
argument|unsigned int shndx
argument_list|,
argument|off_t off
argument_list|)
block|{
name|gold_assert
argument_list|(
name|shndx
operator|<
name|this
operator|->
name|map_to_output_
operator|.
name|size
argument_list|()
argument_list|)
block|;
name|this
operator|->
name|map_to_output_
index|[
name|shndx
index|]
operator|.
name|offset
operator|=
name|off
block|;   }
name|protected
operator|:
comment|// What we need to know to map an input section to an output
comment|// section.  We keep an array of these, one for each input section,
comment|// indexed by the input section number.
expr|struct
name|Map_to_output
block|{
comment|// The output section.  This is NULL if the input section is to be
comment|// discarded.
name|Output_section
operator|*
name|output_section
block|;
comment|// The offset within the output section.  This is -1 if the
comment|// section requires special handling.
name|off_t
name|offset
block|;   }
block|;
comment|// Read the relocs--implemented by child class.
name|virtual
name|void
name|do_read_relocs
argument_list|(
name|Read_relocs_data
operator|*
argument_list|)
operator|=
literal|0
block|;
comment|// Scan the relocs--implemented by child class.
name|virtual
name|void
name|do_scan_relocs
argument_list|(
specifier|const
name|General_options
operator|&
argument_list|,
name|Symbol_table
operator|*
argument_list|,
name|Layout
operator|*
argument_list|,
name|Read_relocs_data
operator|*
argument_list|)
operator|=
literal|0
block|;
comment|// Finalize local symbols--implemented by child class.
name|virtual
name|unsigned
name|int
name|do_finalize_local_symbols
argument_list|(
argument|unsigned int
argument_list|,
argument|off_t
argument_list|,
argument|Stringpool_template<char>*
argument_list|)
operator|=
literal|0
block|;
comment|// Relocate the input sections and write out the local
comment|// symbols--implemented by child class.
name|virtual
name|void
name|do_relocate
argument_list|(
specifier|const
name|General_options
operator|&
name|options
argument_list|,
specifier|const
name|Symbol_table
operator|*
name|symtab
argument_list|,
specifier|const
name|Layout
operator|*
argument_list|,
name|Output_file
operator|*
name|of
argument_list|)
operator|=
literal|0
block|;
comment|// Return the vector mapping input sections to output sections.
name|std
operator|::
name|vector
operator|<
name|Map_to_output
operator|>
operator|&
name|map_to_output
argument_list|()
block|{
return|return
name|this
operator|->
name|map_to_output_
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|Map_to_output
operator|>
operator|&
name|map_to_output
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|map_to_output_
return|;
block|}
name|private
operator|:
comment|// Mapping from input sections to output section.
name|std
operator|::
name|vector
operator|<
name|Map_to_output
operator|>
name|map_to_output_
block|; }
decl_stmt|;
comment|// Implement Object::output_section inline for efficiency.
specifier|inline
name|Output_section
operator|*
name|Relobj
operator|::
name|output_section
argument_list|(
argument|unsigned int shndx
argument_list|,
argument|off_t* poff
argument_list|)
specifier|const
block|{
name|gold_assert
argument_list|(
name|shndx
operator|<
name|this
operator|->
name|map_to_output_
operator|.
name|size
argument_list|()
argument_list|)
block|;
specifier|const
name|Map_to_output
operator|&
name|mo
argument_list|(
name|this
operator|->
name|map_to_output_
index|[
name|shndx
index|]
argument_list|)
block|;
operator|*
name|poff
operator|=
name|mo
operator|.
name|offset
block|;
return|return
name|mo
operator|.
name|output_section
return|;
block|}
comment|// This POD class is holds the value of a symbol.  This is used for
comment|// local symbols, and for all symbols during relocation processing.
comment|// In order to process relocs we need to be able to handle SHF_MERGE
comment|// sections correctly.
name|template
operator|<
name|int
name|size
operator|>
name|class
name|Symbol_value
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
name|Value
expr_stmt|;
name|Symbol_value
argument_list|()
operator|:
name|output_symtab_index_
argument_list|(
literal|0
argument_list|)
operator|,
name|input_shndx_
argument_list|(
literal|0
argument_list|)
operator|,
name|needs_output_address_
argument_list|(
name|false
argument_list|)
operator|,
name|value_
argument_list|(
literal|0
argument_list|)
block|{ }
comment|// Get the value of this symbol.  OBJECT is the object in which this
comment|// symbol is defined, and ADDEND is an addend to add to the value.
name|template
operator|<
name|bool
name|big_endian
operator|>
name|Value
name|value
argument_list|(
argument|const Sized_relobj<size
argument_list|,
argument|big_endian>* object
argument_list|,
argument|Value addend
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|this
operator|->
name|needs_output_address_
condition|)
return|return
name|this
operator|->
name|value_
operator|+
name|addend
return|;
return|return
name|object
operator|->
name|local_value
argument_list|(
name|this
operator|->
name|input_shndx_
argument_list|,
name|this
operator|->
name|value_
argument_list|,
name|addend
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Set the value of this symbol in the output symbol table.
end_comment

begin_function
name|void
name|set_output_value
parameter_list|(
name|Value
name|value
parameter_list|)
block|{
name|this
operator|->
name|value_
operator|=
name|value
expr_stmt|;
name|this
operator|->
name|needs_output_address_
operator|=
name|false
expr_stmt|;
block|}
end_function

begin_comment
comment|// If this symbol is mapped to an output section which requires
end_comment

begin_comment
comment|// special handling to determine the output value, we store the
end_comment

begin_comment
comment|// value of the symbol in the input file.  This is used for
end_comment

begin_comment
comment|// SHF_MERGE sections.
end_comment

begin_function
name|void
name|set_input_value
parameter_list|(
name|Value
name|value
parameter_list|)
block|{
name|this
operator|->
name|value_
operator|=
name|value
expr_stmt|;
name|this
operator|->
name|needs_output_address_
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|// Return whether this symbol should go into the output symbol
end_comment

begin_comment
comment|// table.
end_comment

begin_expr_stmt
name|bool
name|needs_output_symtab_entry
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|output_symtab_index_
operator|!=
literal|0
argument_list|)
block|;
return|return
name|this
operator|->
name|output_symtab_index_
operator|!=
operator|-
literal|1U
return|;
block|}
end_expr_stmt

begin_comment
comment|// Return the index in the output symbol table.
end_comment

begin_expr_stmt
name|unsigned
name|int
name|output_symtab_index
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|output_symtab_index_
operator|!=
literal|0
argument_list|)
block|;
return|return
name|this
operator|->
name|output_symtab_index_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Set the index in the output symbol table.
end_comment

begin_function
name|void
name|set_output_symtab_index
parameter_list|(
name|unsigned
name|int
name|i
parameter_list|)
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|output_symtab_index_
operator|==
literal|0
argument_list|)
expr_stmt|;
name|this
operator|->
name|output_symtab_index_
operator|=
name|i
expr_stmt|;
block|}
end_function

begin_comment
comment|// Record that this symbol should not go into the output symbol
end_comment

begin_comment
comment|// table.
end_comment

begin_function
name|void
name|set_no_output_symtab_entry
parameter_list|()
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|output_symtab_index_
operator|==
literal|0
argument_list|)
expr_stmt|;
name|this
operator|->
name|output_symtab_index_
operator|=
operator|-
literal|1U
expr_stmt|;
block|}
end_function

begin_comment
comment|// Set the index of the input section in the input file.
end_comment

begin_function
name|void
name|set_input_shndx
parameter_list|(
name|unsigned
name|int
name|i
parameter_list|)
block|{
name|this
operator|->
name|input_shndx_
operator|=
name|i
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|// The index of this local symbol in the output symbol table.  This
end_comment

begin_comment
comment|// will be -1 if the symbol should not go into the symbol table.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|output_symtab_index_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The section index in the input file in which this symbol is
end_comment

begin_comment
comment|// defined.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|input_shndx_
range|:
literal|31
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether getting the value of this symbol requires calling an
end_comment

begin_comment
comment|// Output_section method.  For example, this will be true of a
end_comment

begin_comment
comment|// STT_SECTION symbol in a SHF_MERGE section.
end_comment

begin_decl_stmt
name|bool
name|needs_output_address_
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The value of the symbol.  If !needs_output_address_, this is the
end_comment

begin_comment
comment|// value in the output file.  If needs_output_address_, this is the
end_comment

begin_comment
comment|// value in the input file.
end_comment

begin_decl_stmt
name|Value
name|value_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// A regular object file.  This is size and endian specific.
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
name|Sized_relobj
operator|:
name|public
name|Relobj
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
name|std
operator|::
name|vector
operator|<
name|Symbol_value
operator|<
name|size
operator|>
expr|>
name|Local_values
expr_stmt|;
end_typedef

begin_macro
name|Sized_relobj
argument_list|(
argument|const std::string& name
argument_list|,
argument|Input_file* input_file
argument_list|,
argument|off_t offset
argument_list|,
argument|const typename elfcpp::Ehdr<size
argument_list|,
argument|big_endian>&
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|~
name|Sized_relobj
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Set up the object file based on the ELF header.
end_comment

begin_decl_stmt
name|void
name|setup
argument_list|(
specifier|const
name|typename
name|elfcpp
operator|::
name|Ehdr
operator|<
name|size
argument_list|,
name|big_endian
operator|>
operator|&
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Return the index of local symbol SYM in the ordinary symbol
end_comment

begin_comment
comment|// table.  A value of -1U means that the symbol is not being output.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|symtab_index
argument_list|(
name|unsigned
name|int
name|sym
argument_list|)
decl|const
block|{
name|gold_assert
argument_list|(
name|sym
operator|<
name|this
operator|->
name|local_values_
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|this
operator|->
name|local_values_
index|[
name|sym
index|]
operator|.
name|output_symtab_index
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|// Read the symbols.
end_comment

begin_function_decl
name|void
name|do_read_symbols
parameter_list|(
name|Read_symbols_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Lay out the input sections.
end_comment

begin_function_decl
name|void
name|do_layout
parameter_list|(
specifier|const
name|General_options
modifier|&
parameter_list|,
name|Symbol_table
modifier|*
parameter_list|,
name|Layout
modifier|*
parameter_list|,
name|Read_symbols_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Add the symbols to the symbol table.
end_comment

begin_function_decl
name|void
name|do_add_symbols
parameter_list|(
name|Symbol_table
modifier|*
parameter_list|,
name|Read_symbols_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Read the relocs.
end_comment

begin_function_decl
name|void
name|do_read_relocs
parameter_list|(
name|Read_relocs_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Scan the relocs and adjust the symbol table.
end_comment

begin_function_decl
name|void
name|do_scan_relocs
parameter_list|(
specifier|const
name|General_options
modifier|&
parameter_list|,
name|Symbol_table
modifier|*
parameter_list|,
name|Layout
modifier|*
parameter_list|,
name|Read_relocs_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Finalize the local symbols.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|do_finalize_local_symbols
argument_list|(
name|unsigned
name|int
argument_list|,
name|off_t
argument_list|,
name|Stringpool_template
operator|<
name|char
operator|>
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Relocate the input sections and write out the local symbols.
end_comment

begin_function_decl
name|void
name|do_relocate
parameter_list|(
specifier|const
name|General_options
modifier|&
name|options
parameter_list|,
specifier|const
name|Symbol_table
modifier|*
name|symtab
parameter_list|,
specifier|const
name|Layout
modifier|*
parameter_list|,
name|Output_file
modifier|*
name|of
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Get the name of a section.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|do_section_name
argument_list|(
argument|unsigned int shndx
argument_list|)
block|{
return|return
name|this
operator|->
name|elf_file_
operator|.
name|section_name
argument_list|(
name|shndx
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Return the location of the contents of a section.
end_comment

begin_expr_stmt
name|Object
operator|::
name|Location
name|do_section_contents
argument_list|(
argument|unsigned int shndx
argument_list|)
block|{
return|return
name|this
operator|->
name|elf_file_
operator|.
name|section_contents
argument_list|(
name|shndx
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Return section flags.
end_comment

begin_function
name|uint64_t
name|do_section_flags
parameter_list|(
name|unsigned
name|int
name|shndx
parameter_list|)
block|{
return|return
name|this
operator|->
name|elf_file_
operator|.
name|section_flags
argument_list|(
name|shndx
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Return the appropriate Sized_target structure.
end_comment

begin_expr_stmt
name|Sized_target
operator|<
name|size
operator|,
name|big_endian
operator|>
operator|*
name|sized_target
argument_list|()
block|{
return|return
name|this
operator|->
name|Object
operator|::
name|sized_target
name|SELECT_SIZE_ENDIAN_NAME
argument_list|(
name|size
argument_list|,
name|big_endian
argument_list|)
argument_list|(
name|SELECT_SIZE_ENDIAN_ONLY
argument_list|(
name|size
argument_list|,
name|big_endian
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Return the value of a local symbol define in input section SHNDX,
end_comment

begin_comment
comment|// with value VALUE, adding addend ADDEND.  This handles SHF_MERGE
end_comment

begin_comment
comment|// sections.
end_comment

begin_decl_stmt
name|Address
name|local_value
argument_list|(
name|unsigned
name|int
name|shndx
argument_list|,
name|Address
name|value
argument_list|,
name|Address
name|addend
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// For convenience.
end_comment

begin_typedef
typedef|typedef
name|Sized_relobj
operator|<
name|size
operator|,
name|big_endian
operator|>
name|This
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|int
name|ehdr_size
init|=
name|elfcpp
operator|::
name|Elf_sizes
operator|<
name|size
operator|>
operator|::
name|ehdr_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|shdr_size
init|=
name|elfcpp
operator|::
name|Elf_sizes
operator|<
name|size
operator|>
operator|::
name|shdr_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|sym_size
init|=
name|elfcpp
operator|::
name|Elf_sizes
operator|<
name|size
operator|>
operator|::
name|sym_size
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|elfcpp
operator|::
name|Shdr
operator|<
name|size
operator|,
name|big_endian
operator|>
name|Shdr
expr_stmt|;
end_typedef

begin_comment
comment|// Find the SHT_SYMTAB section, given the section headers.
end_comment

begin_function_decl
name|void
name|find_symtab
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|pshdrs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Whether to include a section group in the link.
end_comment

begin_decl_stmt
name|bool
name|include_section_group
argument_list|(
name|Layout
operator|*
argument_list|,
name|unsigned
name|int
argument_list|,
specifier|const
name|elfcpp
operator|::
name|Shdr
operator|<
name|size
argument_list|,
name|big_endian
operator|>
operator|&
argument_list|,
name|std
operator|::
name|vector
operator|<
name|bool
operator|>
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether to include a linkonce section in the link.
end_comment

begin_decl_stmt
name|bool
name|include_linkonce_section
argument_list|(
name|Layout
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|elfcpp
operator|::
name|Shdr
operator|<
name|size
argument_list|,
name|big_endian
operator|>
operator|&
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Views and sizes when relocating.
end_comment

begin_struct
struct|struct
name|View_size
block|{
name|unsigned
name|char
modifier|*
name|view
decl_stmt|;
name|typename
name|elfcpp
operator|::
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_Addr
name|address
expr_stmt|;
name|off_t
name|offset
decl_stmt|;
name|off_t
name|view_size
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|View_size
operator|>
name|Views
expr_stmt|;
end_typedef

begin_comment
comment|// Write section data to the output file.  Record the views and
end_comment

begin_comment
comment|// sizes in VIEWS for use when relocating.
end_comment

begin_function_decl
name|void
name|write_sections
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|pshdrs
parameter_list|,
name|Output_file
modifier|*
parameter_list|,
name|Views
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Relocate the sections in the output file.
end_comment

begin_function_decl
name|void
name|relocate_sections
parameter_list|(
specifier|const
name|General_options
modifier|&
name|options
parameter_list|,
specifier|const
name|Symbol_table
modifier|*
parameter_list|,
specifier|const
name|Layout
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|pshdrs
parameter_list|,
name|Views
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Write out the local symbols.
end_comment

begin_decl_stmt
name|void
name|write_local_symbols
argument_list|(
name|Output_file
operator|*
argument_list|,
specifier|const
name|Stringpool_template
operator|<
name|char
operator|>
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// General access to the ELF file.
end_comment

begin_expr_stmt
name|elfcpp
operator|::
name|Elf_file
operator|<
name|size
operator|,
name|big_endian
operator|,
name|Object
operator|>
name|elf_file_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Index of SHT_SYMTAB section.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|symtab_shndx_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The number of local symbols.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|local_symbol_count_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The number of local symbols which go into the output file.
end_comment

begin_decl_stmt
name|unsigned
name|int
name|output_local_symbol_count_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The entries in the symbol table for the external symbols.
end_comment

begin_decl_stmt
name|Symbol
modifier|*
modifier|*
name|symbols_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// File offset for local symbols.
end_comment

begin_decl_stmt
name|off_t
name|local_symbol_offset_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Values of local symbols.
end_comment

begin_decl_stmt
name|Local_values
name|local_values_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// A class to manage the list of all objects.
end_comment

begin_decl_stmt
name|class
name|Input_objects
block|{
name|public
label|:
name|Input_objects
argument_list|()
operator|:
name|relobj_list_
argument_list|()
operator|,
name|dynobj_list_
argument_list|()
operator|,
name|target_
argument_list|(
name|NULL
argument_list|)
operator|,
name|sonames_
argument_list|()
block|{ }
comment|// The type of the list of input relocateable objects.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Relobj
operator|*
operator|>
name|Relobj_list
expr_stmt|;
typedef|typedef
name|Relobj_list
operator|::
name|const_iterator
name|Relobj_iterator
expr_stmt|;
comment|// The type of the list of input dynamic objects.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Dynobj
operator|*
operator|>
name|Dynobj_list
expr_stmt|;
typedef|typedef
name|Dynobj_list
operator|::
name|const_iterator
name|Dynobj_iterator
expr_stmt|;
comment|// Add an object to the list.  Return true if all is well, or false
comment|// if this object should be ignored.
name|bool
name|add_object
parameter_list|(
name|Object
modifier|*
parameter_list|)
function_decl|;
comment|// Get the target we should use for the output file.
name|Target
operator|*
name|target
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|target_
return|;
block|}
comment|// Iterate over all regular objects.
name|Relobj_iterator
name|relobj_begin
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|relobj_list_
operator|.
name|begin
argument_list|()
return|;
block|}
name|Relobj_iterator
name|relobj_end
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|relobj_list_
operator|.
name|end
argument_list|()
return|;
block|}
comment|// Iterate over all dynamic objects.
name|Dynobj_iterator
name|dynobj_begin
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|dynobj_list_
operator|.
name|begin
argument_list|()
return|;
block|}
name|Dynobj_iterator
name|dynobj_end
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|dynobj_list_
operator|.
name|end
argument_list|()
return|;
block|}
comment|// Return whether we have seen any dynamic objects.
name|bool
name|any_dynamic
argument_list|()
specifier|const
block|{
return|return
operator|!
name|this
operator|->
name|dynobj_list_
operator|.
name|empty
argument_list|()
return|;
block|}
name|private
label|:
name|Input_objects
argument_list|(
specifier|const
name|Input_objects
operator|&
argument_list|)
expr_stmt|;
name|Input_objects
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Input_objects
operator|&
operator|)
decl_stmt|;
comment|// The list of ordinary objects included in the link.
name|Relobj_list
name|relobj_list_
decl_stmt|;
comment|// The list of dynamic objects included in the link.
name|Dynobj_list
name|dynobj_list_
decl_stmt|;
comment|// The target.
name|Target
modifier|*
name|target_
decl_stmt|;
comment|// SONAMEs that we have seen.
name|Unordered_set
operator|<
name|std
operator|::
name|string
operator|>
name|sonames_
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Some of the information we pass to the relocation routines.  We
end_comment

begin_comment
comment|// group this together to avoid passing a dozen different arguments.
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
expr|struct
name|Relocate_info
block|{
comment|// Command line options.
specifier|const
name|General_options
operator|*
name|options
block|;
comment|// Symbol table.
specifier|const
name|Symbol_table
operator|*
name|symtab
block|;
comment|// Layout.
specifier|const
name|Layout
operator|*
name|layout
block|;
comment|// Object being relocated.
name|Sized_relobj
operator|<
name|size
block|,
name|big_endian
operator|>
operator|*
name|object
block|;
comment|// Number of local symbols.
name|unsigned
name|int
name|local_symbol_count
block|;
comment|// Values of local symbols.
specifier|const
name|typename
name|Sized_relobj
operator|<
name|size
block|,
name|big_endian
operator|>
operator|::
name|Local_values
operator|*
name|local_values
block|;
comment|// Global symbols.
specifier|const
name|Symbol
operator|*
specifier|const
operator|*
name|symbols
block|;
comment|// Section index of relocation section.
name|unsigned
name|int
name|reloc_shndx
block|;
comment|// Section index of section being relocated.
name|unsigned
name|int
name|data_shndx
block|;
comment|// Return a string showing the location of a relocation.  This is
comment|// only used for error messages.
name|std
operator|::
name|string
name|location
argument_list|(
argument|size_t relnum
argument_list|,
argument|off_t reloffset
argument_list|)
specifier|const
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Return an Object appropriate for the input file.  P is BYTES long,
end_comment

begin_comment
comment|// and holds the ELF header.
end_comment

begin_decl_stmt
specifier|extern
name|Object
modifier|*
name|make_elf_object
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|,
name|Input_file
operator|*
argument_list|,
name|off_t
name|offset
argument_list|,
specifier|const
name|unsigned
name|char
operator|*
name|p
argument_list|,
name|off_t
name|bytes
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace gold
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_OBJECT_H)
end_comment

end_unit

