begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// target.h -- target support for gold   -*- C++ -*-
end_comment

begin_comment
comment|// The abstract class Target is the interface for target specific
end_comment

begin_comment
comment|// support.  It defines abstract methods which each target must
end_comment

begin_comment
comment|// implement.  Typically there will be one target per processor, but
end_comment

begin_comment
comment|// in some cases it may be necessary to have subclasses.
end_comment

begin_comment
comment|// For speed and consistency we want to use inline functions to handle
end_comment

begin_comment
comment|// relocation processing.  So besides implementations of the abstract
end_comment

begin_comment
comment|// methods, each target is expected to define a template
end_comment

begin_comment
comment|// specialization of the relocation functions.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_TARGET_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_TARGET_H
end_define

begin_include
include|#
directive|include
file|"elfcpp.h"
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
expr_stmt|;
name|class
name|Symbol
decl_stmt|;
name|template
operator|<
name|int
name|size
operator|>
name|class
name|Sized_symbol
expr_stmt|;
name|class
name|Symbol_table
decl_stmt|;
comment|// The abstract class for target specific handling.
name|class
name|Target
block|{
name|public
label|:
name|virtual
operator|~
name|Target
argument_list|()
block|{ }
comment|// Return the bit size that this target implements.  This should
comment|// return 32 or 64.
name|int
name|get_size
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|pti_
operator|->
name|size
return|;
block|}
comment|// Return whether this target is big-endian.
name|bool
name|is_big_endian
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|pti_
operator|->
name|is_big_endian
return|;
block|}
comment|// Machine code to store in e_machine field of ELF header.
name|elfcpp
operator|::
name|EM
name|machine_code
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|pti_
operator|->
name|machine_code
return|;
block|}
comment|// Whether this target has a specific make_symbol function.
name|bool
name|has_make_symbol
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|pti_
operator|->
name|has_make_symbol
return|;
block|}
comment|// Whether this target has a specific resolve function.
name|bool
name|has_resolve
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|pti_
operator|->
name|has_resolve
return|;
block|}
comment|// Return the default name of the dynamic linker.
specifier|const
name|char
operator|*
name|dynamic_linker
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|pti_
operator|->
name|dynamic_linker
return|;
block|}
comment|// Return the default address to use for the text segment.
name|uint64_t
name|text_segment_address
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|pti_
operator|->
name|text_segment_address
return|;
block|}
comment|// Return the ABI specified page size.
name|uint64_t
name|abi_pagesize
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|pti_
operator|->
name|abi_pagesize
return|;
block|}
comment|// Return the common page size used on actual systems.
name|uint64_t
name|common_pagesize
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|pti_
operator|->
name|common_pagesize
return|;
block|}
comment|// This is called to tell the target to complete any sections it is
comment|// handling.  After this all sections must have their final size.
name|void
name|finalize_sections
parameter_list|(
specifier|const
name|General_options
modifier|*
name|options
parameter_list|,
name|Layout
modifier|*
name|layout
parameter_list|)
block|{
return|return
name|this
operator|->
name|do_finalize_sections
argument_list|(
name|options
argument_list|,
name|layout
argument_list|)
return|;
block|}
name|protected
label|:
comment|// This struct holds the constant information for a child class.  We
comment|// use a struct to avoid the overhead of virtual function calls for
comment|// simple information.
struct|struct
name|Target_info
block|{
comment|// Address size (32 or 64).
name|int
name|size
decl_stmt|;
comment|// Whether the target is big endian.
name|bool
name|is_big_endian
decl_stmt|;
comment|// The code to store in the e_machine field of the ELF header.
name|elfcpp
operator|::
name|EM
name|machine_code
expr_stmt|;
comment|// Whether this target has a specific make_symbol function.
name|bool
name|has_make_symbol
decl_stmt|;
comment|// Whether this target has a specific resolve function.
name|bool
name|has_resolve
decl_stmt|;
comment|// The default dynamic linker name.
specifier|const
name|char
modifier|*
name|dynamic_linker
decl_stmt|;
comment|// The default text segment address.
name|uint64_t
name|text_segment_address
decl_stmt|;
comment|// The ABI specified page size.
name|uint64_t
name|abi_pagesize
decl_stmt|;
comment|// The common page size used by actual implementations.
name|uint64_t
name|common_pagesize
decl_stmt|;
block|}
struct|;
name|Target
argument_list|(
specifier|const
name|Target_info
operator|*
name|pti
argument_list|)
operator|:
name|pti_
argument_list|(
argument|pti
argument_list|)
block|{ }
comment|// Virtual function which may be implemented by the child class.
name|virtual
name|void
name|do_finalize_sections
argument_list|(
argument|const General_options*
argument_list|,
argument|Layout*
argument_list|)
block|{ }
name|private
operator|:
name|Target
argument_list|(
specifier|const
name|Target
operator|&
argument_list|)
expr_stmt|;
name|Target
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Target
operator|&
operator|)
decl_stmt|;
comment|// The target information.
specifier|const
name|Target_info
modifier|*
name|pti_
decl_stmt|;
block|}
empty_stmt|;
comment|// The abstract class for a specific size and endianness of target.
comment|// Each actual target implementation class should derive from an
comment|// instantiation of Sized_target.
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
operator|:
name|public
name|Target
block|{
name|public
operator|:
comment|// Make a new symbol table entry for the target.  This should be
comment|// overridden by a target which needs additional information in the
comment|// symbol table.  This will only be called if has_make_symbol()
comment|// returns true.
name|virtual
name|Sized_symbol
operator|<
name|size
operator|>
operator|*
name|make_symbol
argument_list|()
specifier|const
block|{
name|gold_unreachable
argument_list|()
block|; }
comment|// Resolve a symbol for the target.  This should be overridden by a
comment|// target which needs to take special action.  TO is the
comment|// pre-existing symbol.  SYM is the new symbol, seen in OBJECT.
comment|// VERSION is the version of SYM.  This will only be called if
comment|// has_resolve() returns true.
name|virtual
name|void
name|resolve
argument_list|(
argument|Symbol*
argument_list|,
argument|const elfcpp::Sym<size
argument_list|,
argument|big_endian>&
argument_list|,
argument|Object*
argument_list|,
argument|const char*
argument_list|)
block|{
name|gold_unreachable
argument_list|()
block|; }
comment|// Scan the relocs for a section, and record any information
comment|// required for the symbol.  OPTIONS is the command line options.
comment|// SYMTAB is the symbol table.  OBJECT is the object in which the
comment|// section appears.  DATA_SHNDX is the section index that these
comment|// relocs apply to.  SH_TYPE is the type of the relocation section,
comment|// SHT_REL or SHT_RELA.  PRELOCS points to the relocation data.
comment|// RELOC_COUNT is the number of relocs.  LOCAL_SYMBOL_COUNT is the
comment|// number of local symbols.  PLOCAL_SYMBOLS points to the local
comment|// symbol data from OBJECT.  GLOBAL_SYMBOLS is the array of pointers
comment|// to the global symbol table from OBJECT.
name|virtual
name|void
name|scan_relocs
argument_list|(
argument|const General_options& options
argument_list|,
argument|Symbol_table* symtab
argument_list|,
argument|Layout* layout
argument_list|,
argument|Sized_relobj<size
argument_list|,
argument|big_endian>* object
argument_list|,
argument|unsigned int data_shndx
argument_list|,
argument|unsigned int sh_type
argument_list|,
argument|const unsigned char* prelocs
argument_list|,
argument|size_t reloc_count
argument_list|,
argument|size_t local_symbol_count
argument_list|,
argument|const unsigned char* plocal_symbols
argument_list|,
argument|Symbol** global_symbols
argument_list|)
operator|=
literal|0
block|;
comment|// Relocate section data.  SH_TYPE is the type of the relocation
comment|// section, SHT_REL or SHT_RELA.  PRELOCS points to the relocation
comment|// information.  RELOC_COUNT is the number of relocs.  VIEW is a
comment|// view into the output file holding the section contents,
comment|// VIEW_ADDRESS is the virtual address of the view, and VIEW_SIZE is
comment|// the size of the view.
name|virtual
name|void
name|relocate_section
argument_list|(
argument|const Relocate_info<size
argument_list|,
argument|big_endian>*
argument_list|,
argument|unsigned int sh_type
argument_list|,
argument|const unsigned char* prelocs
argument_list|,
argument|size_t reloc_count
argument_list|,
argument|unsigned char* view
argument_list|,
argument|typename elfcpp::Elf_types<size>::Elf_Addr view_address
argument_list|,
argument|off_t view_size
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
name|Sized_target
argument_list|(
specifier|const
name|Target
operator|::
name|Target_info
operator|*
name|pti
argument_list|)
operator|:
name|Target
argument_list|(
argument|pti
argument_list|)
block|{
name|gold_assert
argument_list|(
name|pti
operator|->
name|size
operator|==
name|size
argument_list|)
block|;
name|gold_assert
argument_list|(
name|pti
operator|->
name|is_big_endian
condition|?
name|big_endian
else|:
operator|!
name|big_endian
argument_list|)
block|;   }
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_TARGET_H)
end_comment

end_unit

