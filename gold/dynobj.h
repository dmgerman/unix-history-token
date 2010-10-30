begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// dynobj.h -- dynamic object support for gold   -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_DYNOBJ_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_DYNOBJ_H
end_define

begin_include
include|#
directive|include
file|<vector>
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

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|General_options
decl_stmt|;
comment|// A dynamic object (ET_DYN).  This is an abstract base class itself.
comment|// The implementations is the template class Sized_dynobj.
name|class
name|Dynobj
range|:
name|public
name|Object
block|{
name|public
operator|:
name|Dynobj
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
name|name
argument_list|,
name|input_file
argument_list|,
name|true
argument_list|,
name|offset
argument_list|)
block|,
name|soname_
argument_list|()
block|{ }
comment|// Return the name to use in a DT_NEEDED entry for this object.
specifier|const
name|char
operator|*
name|soname
argument_list|()
specifier|const
block|;
comment|// Compute the ELF hash code for a string.
specifier|static
name|uint32_t
name|elf_hash
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
block|;
comment|// Create a standard ELF hash table, setting *PPHASH and *PHASHLEN.
comment|// DYNSYMS is the global dynamic symbols.  LOCAL_DYNSYM_COUNT is the
comment|// number of local dynamic symbols, which is the index of the first
comment|// dynamic gobal symbol.
specifier|static
name|void
name|create_elf_hash_table
argument_list|(
argument|const Target*
argument_list|,
argument|const std::vector<Symbol*>& dynsyms
argument_list|,
argument|unsigned int local_dynsym_count
argument_list|,
argument|unsigned char** pphash
argument_list|,
argument|unsigned int* phashlen
argument_list|)
block|;
comment|// Create a GNU hash table, setting *PPHASH and *PHASHLEN.  DYNSYMS
comment|// is the global dynamic symbols.  LOCAL_DYNSYM_COUNT is the number
comment|// of local dynamic symbols, which is the index of the first dynamic
comment|// gobal symbol.
specifier|static
name|void
name|create_gnu_hash_table
argument_list|(
argument|const Target*
argument_list|,
argument|const std::vector<Symbol*>& dynsyms
argument_list|,
argument|unsigned int local_dynsym_count
argument_list|,
argument|unsigned char** pphash
argument_list|,
argument|unsigned int* phashlen
argument_list|)
block|;
name|protected
operator|:
comment|// Set the DT_SONAME string.
name|void
name|set_soname_string
argument_list|(
argument|const char* s
argument_list|)
block|{
name|this
operator|->
name|soname_
operator|.
name|assign
argument_list|(
name|s
argument_list|)
block|; }
name|private
operator|:
comment|// Compute the GNU hash code for a string.
specifier|static
name|uint32_t
name|gnu_hash
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
block|;
comment|// Compute the number of hash buckets to use.
specifier|static
name|unsigned
name|int
name|compute_bucket_count
argument_list|(
argument|const std::vector<uint32_t>& hashcodes
argument_list|,
argument|bool for_gnu_hash_table
argument_list|)
block|;
comment|// Sized version of create_elf_hash_table.
name|template
operator|<
name|bool
name|big_endian
operator|>
specifier|static
name|void
name|sized_create_elf_hash_table
argument_list|(
argument|const std::vector<uint32_t>& bucket
argument_list|,
argument|const std::vector<uint32_t>& chain
argument_list|,
argument|unsigned char* phash
argument_list|,
argument|unsigned int hashlen
argument_list|)
block|;
comment|// Sized version of create_gnu_hash_table.
name|template
operator|<
name|int
name|size
block|,
name|bool
name|big_endian
operator|>
specifier|static
name|void
name|sized_create_gnu_hash_table
argument_list|(
argument|const std::vector<Symbol*>& hashed_dynsyms
argument_list|,
argument|const std::vector<uint32_t>& dynsym_hashvals
argument_list|,
argument|unsigned int unhashed_dynsym_count
argument_list|,
argument|unsigned char** pphash
argument_list|,
argument|unsigned int* phashlen
argument_list|)
block|;
comment|// The DT_SONAME name, if any.
name|std
operator|::
name|string
name|soname_
block|; }
decl_stmt|;
comment|// A dynamic object, size and endian specific version.
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
operator|:
name|public
name|Dynobj
block|{
name|public
operator|:
name|Sized_dynobj
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
block|;
comment|// Set up the object file based on the ELF header.
name|void
name|setup
argument_list|(
argument|const typename elfcpp::Ehdr<size
argument_list|,
argument|big_endian>&
argument_list|)
block|;
comment|// Read the symbols.
name|void
name|do_read_symbols
argument_list|(
name|Read_symbols_data
operator|*
argument_list|)
block|;
comment|// Lay out the input sections.
name|void
name|do_layout
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
name|Read_symbols_data
operator|*
argument_list|)
block|;
comment|// Add the symbols to the symbol table.
name|void
name|do_add_symbols
argument_list|(
name|Symbol_table
operator|*
argument_list|,
name|Read_symbols_data
operator|*
argument_list|)
block|;
comment|// Get the name of a section.
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
comment|// Return a view of the contents of a section.  Set *PLEN to the
comment|// size.
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
comment|// Return section flags.
name|uint64_t
name|do_section_flags
argument_list|(
argument|unsigned int shndx
argument_list|)
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
name|private
operator|:
comment|// For convenience.
typedef|typedef
name|Sized_dynobj
operator|<
name|size
operator|,
name|big_endian
operator|>
name|This
expr_stmt|;
specifier|static
specifier|const
name|int
name|shdr_size
operator|=
name|elfcpp
operator|::
name|Elf_sizes
operator|<
name|size
operator|>
operator|::
name|shdr_size
expr_stmt|;
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
specifier|static
specifier|const
name|int
name|dyn_size
init|=
name|elfcpp
operator|::
name|Elf_sizes
operator|<
name|size
operator|>
operator|::
name|dyn_size
decl_stmt|;
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
typedef|typedef
name|elfcpp
operator|::
name|Dyn
operator|<
name|size
operator|,
name|big_endian
operator|>
name|Dyn
expr_stmt|;
comment|// Find the dynamic symbol table and the version sections, given the
comment|// section headers.
name|void
name|find_dynsym_sections
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|pshdrs
parameter_list|,
name|unsigned
name|int
modifier|*
name|pdynshm_shndx
parameter_list|,
name|unsigned
name|int
modifier|*
name|pversym_shndx
parameter_list|,
name|unsigned
name|int
modifier|*
name|pverdef_shndx
parameter_list|,
name|unsigned
name|int
modifier|*
name|pverneed_shndx
parameter_list|,
name|unsigned
name|int
modifier|*
name|pdynamic_shndx
parameter_list|)
function_decl|;
comment|// Read the dynamic symbol section SHNDX.
name|void
name|read_dynsym_section
argument_list|(
specifier|const
name|unsigned
name|char
operator|*
name|pshdrs
argument_list|,
name|unsigned
name|int
name|shndx
argument_list|,
name|elfcpp
operator|::
name|SHT
name|type
argument_list|,
name|unsigned
name|int
name|link
argument_list|,
name|File_view
operator|*
operator|*
name|view
argument_list|,
name|off_t
operator|*
name|view_size
argument_list|,
name|unsigned
name|int
operator|*
name|view_info
argument_list|)
decl_stmt|;
comment|// Set the SONAME from the SHT_DYNAMIC section at DYNAMIC_SHNDX.
comment|// The STRTAB parameters may have the relevant string table.
name|void
name|set_soname
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|pshdrs
parameter_list|,
name|unsigned
name|int
name|dynamic_shndx
parameter_list|,
name|unsigned
name|int
name|strtab_shndx
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|strtabu
parameter_list|,
name|off_t
name|strtab_size
parameter_list|)
function_decl|;
comment|// Mapping from version number to version name.
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
operator|>
name|Version_map
expr_stmt|;
comment|// Create the version map.
name|void
name|make_version_map
argument_list|(
name|Read_symbols_data
operator|*
name|sd
argument_list|,
name|Version_map
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|// Add version definitions to the version map.
name|void
name|make_verdef_map
argument_list|(
name|Read_symbols_data
operator|*
name|sd
argument_list|,
name|Version_map
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|// Add version references to the version map.
name|void
name|make_verneed_map
argument_list|(
name|Read_symbols_data
operator|*
name|sd
argument_list|,
name|Version_map
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|// Add an entry to the version map.
name|void
name|set_version_map
argument_list|(
name|Version_map
operator|*
argument_list|,
name|unsigned
name|int
name|ndx
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
decl|const
decl_stmt|;
comment|// General access to the ELF file.
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// A base class for Verdef and Verneed_version which just handles the
end_comment

begin_comment
comment|// version index which will be stored in the SHT_GNU_versym section.
end_comment

begin_decl_stmt
name|class
name|Version_base
block|{
name|public
label|:
name|Version_base
argument_list|()
operator|:
name|index_
argument_list|(
argument|-
literal|1U
argument_list|)
block|{ }
name|virtual
operator|~
name|Version_base
argument_list|()
block|{ }
comment|// Return the version index.
name|unsigned
name|int
name|index
argument_list|()
specifier|const
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|index_
operator|!=
operator|-
literal|1U
argument_list|)
block|;
return|return
name|this
operator|->
name|index_
return|;
block|}
comment|// Set the version index.
name|void
name|set_index
parameter_list|(
name|unsigned
name|int
name|index
parameter_list|)
block|{
name|gold_assert
argument_list|(
name|this
operator|->
name|index_
operator|==
operator|-
literal|1U
argument_list|)
expr_stmt|;
name|this
operator|->
name|index_
operator|=
name|index
expr_stmt|;
block|}
comment|// Clear the weak flag in a version definition.
name|virtual
name|void
name|clear_weak
parameter_list|()
init|=
literal|0
function_decl|;
name|private
label|:
name|Version_base
argument_list|(
specifier|const
name|Version_base
operator|&
argument_list|)
expr_stmt|;
name|Version_base
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Version_base
operator|&
operator|)
decl_stmt|;
comment|// The index of the version definition or reference.
name|unsigned
name|int
name|index_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This class handles a version being defined in the file we are
end_comment

begin_comment
comment|// generating.
end_comment

begin_decl_stmt
name|class
name|Verdef
range|:
name|public
name|Version_base
block|{
name|public
operator|:
name|Verdef
argument_list|(
argument|const char* name
argument_list|,
argument|bool is_base
argument_list|,
argument|bool is_weak
argument_list|,
argument|bool is_symbol_created
argument_list|)
operator|:
name|name_
argument_list|(
name|name
argument_list|)
block|,
name|deps_
argument_list|()
block|,
name|is_base_
argument_list|(
name|is_base
argument_list|)
block|,
name|is_weak_
argument_list|(
name|is_weak
argument_list|)
block|,
name|is_symbol_created_
argument_list|(
argument|is_symbol_created
argument_list|)
block|{ }
comment|// Return the version name.
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
comment|// Return the number of dependencies.
name|unsigned
name|int
name|count_dependencies
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|deps_
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Add a dependency to this version.  The NAME should be
comment|// canonicalized in the dynamic Stringpool.
name|void
name|add_dependency
argument_list|(
argument|const char* name
argument_list|)
block|{
name|this
operator|->
name|deps_
operator|.
name|push_back
argument_list|(
name|name
argument_list|)
block|; }
comment|// Return whether this definition is weak.
name|bool
name|is_weak
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|is_weak_
return|;
block|}
comment|// Clear the weak flag.
name|void
name|clear_weak
argument_list|()
block|{
name|this
operator|->
name|is_weak_
operator|=
name|false
block|; }
comment|// Return whether a version symbol has been created for this
comment|// definition.
name|bool
name|is_symbol_created
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|is_symbol_created_
return|;
block|}
comment|// Write contents to buffer.
name|template
operator|<
name|int
name|size
block|,
name|bool
name|big_endian
operator|>
name|unsigned
name|char
operator|*
name|write
argument_list|(
argument|const Stringpool*
argument_list|,
argument|bool is_last
argument_list|,
argument|unsigned char*         ACCEPT_SIZE_ENDIAN
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Verdef
argument_list|(
specifier|const
name|Verdef
operator|&
argument_list|)
block|;
name|Verdef
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Verdef
operator|&
operator|)
block|;
comment|// The type of the list of version dependencies.  Each dependency
comment|// should be canonicalized in the dynamic Stringpool.
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
operator|>
name|Deps
expr_stmt|;
comment|// The name of this version.  This should be canonicalized in the
comment|// dynamic Stringpool.
specifier|const
name|char
operator|*
name|name_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// A list of other versions which this version depends upon.
end_comment

begin_decl_stmt
name|Deps
name|deps_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether this is the base version.
end_comment

begin_decl_stmt
name|bool
name|is_base_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether this version is weak.
end_comment

begin_decl_stmt
name|bool
name|is_weak_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether a version symbol has been created.
end_comment

begin_decl_stmt
name|bool
name|is_symbol_created_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// A referened version.  This will be associated with a filename by
end_comment

begin_comment
comment|// Verneed.
end_comment

begin_decl_stmt
name|class
name|Verneed_version
range|:
name|public
name|Version_base
block|{
name|public
operator|:
name|Verneed_version
argument_list|(
specifier|const
name|char
operator|*
name|version
argument_list|)
operator|:
name|version_
argument_list|(
argument|version
argument_list|)
block|{ }
comment|// Return the version name.
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
comment|// Clear the weak flag.  This is invalid for a reference.
name|void
name|clear_weak
argument_list|()
block|{
name|gold_unreachable
argument_list|()
block|; }
name|private
operator|:
name|Verneed_version
argument_list|(
specifier|const
name|Verneed_version
operator|&
argument_list|)
block|;
name|Verneed_version
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Verneed_version
operator|&
operator|)
block|;
specifier|const
name|char
operator|*
name|version_
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Version references in a single dynamic object.
end_comment

begin_decl_stmt
name|class
name|Verneed
block|{
name|public
label|:
name|Verneed
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|)
operator|:
name|filename_
argument_list|(
name|filename
argument_list|)
operator|,
name|need_versions_
argument_list|()
block|{ }
operator|~
name|Verneed
argument_list|()
expr_stmt|;
comment|// Return the file name.
specifier|const
name|char
operator|*
name|filename
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|filename_
return|;
block|}
comment|// Return the number of versions.
name|unsigned
name|int
name|count_versions
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|need_versions_
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Add a version name.  The name should be canonicalized in the
comment|// dynamic Stringpool.  If the name is already present, this does
comment|// nothing.
name|Verneed_version
modifier|*
name|add_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|// Set the version indexes, starting at INDEX.  Return the updated
comment|// INDEX.
name|unsigned
name|int
name|finalize
parameter_list|(
name|unsigned
name|int
name|index
parameter_list|)
function_decl|;
comment|// Write contents to buffer.
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
name|write
argument_list|(
argument|const Stringpool*
argument_list|,
argument|bool is_last
argument_list|,
argument|unsigned char*         ACCEPT_SIZE_ENDIAN
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
name|Verneed
argument_list|(
specifier|const
name|Verneed
operator|&
argument_list|)
expr_stmt|;
name|Verneed
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Verneed
operator|&
operator|)
decl_stmt|;
comment|// The type of the list of version names.  Each name should be
comment|// canonicalized in the dynamic Stringpool.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Verneed_version
operator|*
operator|>
name|Need_versions
expr_stmt|;
comment|// The filename of the dynamic object.  This should be
comment|// canonicalized in the dynamic Stringpool.
specifier|const
name|char
modifier|*
name|filename_
decl_stmt|;
comment|// The list of version names.
name|Need_versions
name|need_versions_
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This class handles version definitions and references which go into
end_comment

begin_comment
comment|// the output file.
end_comment

begin_decl_stmt
name|class
name|Versions
block|{
name|public
label|:
name|Versions
argument_list|()
operator|:
name|defs_
argument_list|()
operator|,
name|needs_
argument_list|()
operator|,
name|version_table_
argument_list|()
operator|,
name|is_finalized_
argument_list|(
argument|false
argument_list|)
block|{ }
operator|~
name|Versions
argument_list|()
expr_stmt|;
comment|// SYM is going into the dynamic symbol table and has a version.
comment|// Record the appropriate version information.
name|void
name|record_version
parameter_list|(
specifier|const
name|General_options
modifier|*
parameter_list|,
name|Stringpool
modifier|*
parameter_list|,
specifier|const
name|Symbol
modifier|*
name|sym
parameter_list|)
function_decl|;
comment|// Set the version indexes.  DYNSYM_INDEX is the index we should use
comment|// for the next dynamic symbol.  We add new dynamic symbols to SYMS
comment|// and return an updated DYNSYM_INDEX.
name|unsigned
name|int
name|finalize
argument_list|(
specifier|const
name|Target
operator|*
argument_list|,
name|Symbol_table
operator|*
name|symtab
argument_list|,
name|unsigned
name|int
name|dynsym_index
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Symbol
operator|*
operator|>
operator|*
name|syms
argument_list|)
decl_stmt|;
comment|// Return whether there are any version definitions.
name|bool
name|any_defs
argument_list|()
specifier|const
block|{
return|return
operator|!
name|this
operator|->
name|defs_
operator|.
name|empty
argument_list|()
return|;
block|}
comment|// Return whether there are any version references.
name|bool
name|any_needs
argument_list|()
specifier|const
block|{
return|return
operator|!
name|this
operator|->
name|needs_
operator|.
name|empty
argument_list|()
return|;
block|}
comment|// Build an allocated buffer holding the contents of the symbol
comment|// version section (.gnu.version).
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|symbol_section_contents
argument_list|(
argument|const Stringpool*
argument_list|,
argument|unsigned int local_symcount
argument_list|,
argument|const std::vector<Symbol*>& syms
argument_list|,
argument|unsigned char**
argument_list|,
argument|unsigned int*                           ACCEPT_SIZE_ENDIAN
argument_list|)
specifier|const
expr_stmt|;
comment|// Build an allocated buffer holding the contents of the version
comment|// definition section (.gnu.version_d).
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|def_section_contents
argument_list|(
argument|const Stringpool*
argument_list|,
argument|unsigned char**
argument_list|,
argument|unsigned int* psize
argument_list|,
argument|unsigned int* pentries                        ACCEPT_SIZE_ENDIAN
argument_list|)
specifier|const
expr_stmt|;
comment|// Build an allocated buffer holding the contents of the version
comment|// reference section (.gnu.version_r).
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
name|void
name|need_section_contents
argument_list|(
argument|const Stringpool*
argument_list|,
argument|unsigned char**
argument_list|,
argument|unsigned int* psize
argument_list|,
argument|unsigned int* pentries                         ACCEPT_SIZE_ENDIAN
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
comment|// The type of the list of version definitions.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Verdef
operator|*
operator|>
name|Defs
expr_stmt|;
comment|// The type of the list of version references.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Verneed
operator|*
operator|>
name|Needs
expr_stmt|;
comment|// Handle a symbol SYM defined with version VERSION.
name|void
name|add_def
argument_list|(
specifier|const
name|General_options
operator|*
argument_list|,
specifier|const
name|Symbol
operator|*
name|sym
argument_list|,
specifier|const
name|char
operator|*
name|version
argument_list|,
name|Stringpool
operator|::
name|Key
argument_list|)
decl_stmt|;
comment|// Add a reference to version NAME in file FILENAME.
name|void
name|add_need
argument_list|(
name|Stringpool
operator|*
argument_list|,
specifier|const
name|char
operator|*
name|filename
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
name|Stringpool
operator|::
name|Key
argument_list|)
decl_stmt|;
comment|// Return the version index to use for SYM.
name|unsigned
name|int
name|version_index
argument_list|(
specifier|const
name|Stringpool
operator|*
argument_list|,
specifier|const
name|Symbol
operator|*
name|sym
argument_list|)
decl|const
decl_stmt|;
comment|// We keep a hash table mapping canonicalized name/version pairs to
comment|// a version base.
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
name|Key
expr_stmt|;
struct|struct
name|Version_table_hash
block|{
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|Key
operator|&
name|k
operator|)
specifier|const
block|{
return|return
name|k
operator|.
name|first
operator|+
name|k
operator|.
name|second
return|;
block|}
block|}
struct|;
struct|struct
name|Version_table_eq
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Key
operator|&
name|k1
operator|,
specifier|const
name|Key
operator|&
name|k2
operator|)
specifier|const
block|{
return|return
name|k1
operator|.
name|first
operator|==
name|k2
operator|.
name|first
operator|&&
name|k1
operator|.
name|second
operator|==
name|k2
operator|.
name|second
return|;
block|}
block|}
struct|;
typedef|typedef
name|Unordered_map
operator|<
name|Key
operator|,
name|Version_base
operator|*
operator|,
name|Version_table_hash
operator|,
name|Version_table_eq
operator|>
name|Version_table
expr_stmt|;
comment|// The version definitions.
name|Defs
name|defs_
decl_stmt|;
comment|// The version references.
name|Needs
name|needs_
decl_stmt|;
comment|// The mapping from a canonicalized version/filename pair to a
comment|// version index.  The filename may be NULL.
name|Version_table
name|version_table_
decl_stmt|;
comment|// Whether the version indexes have been set.
name|bool
name|is_finalized_
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
comment|// !defined(GOLD_DYNOBJ_H)
end_comment

end_unit

