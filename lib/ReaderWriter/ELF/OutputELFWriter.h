begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/OutputELFWriter.h ----------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_ELF_OUTPUT_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_OUTPUT_WRITER_H
end_define

begin_include
include|#
directive|include
file|"ELFFile.h"
end_include

begin_include
include|#
directive|include
file|"TargetLayout.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Writer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|ELFLinkingContext
decl_stmt|;
name|namespace
name|elf
block|{
name|using
name|namespace
name|llvm
decl_stmt|;
name|using
name|namespace
name|llvm
operator|::
name|object
expr_stmt|;
comment|//  OutputELFWriter Class
comment|//
comment|/// \brief This acts as the base class for all the ELF writers that are output
comment|/// for emitting an ELF output file. This class also acts as a common class for
comment|/// creating static and dynamic executables. All the function in this class
comment|/// can be overridden and an appropriate writer be created
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|OutputELFWriter
operator|:
name|public
name|ELFWriter
block|{
name|public
operator|:
typedef|typedef
name|Elf_Shdr_Impl
operator|<
name|ELFT
operator|>
name|Elf_Shdr
expr_stmt|;
typedef|typedef
name|Elf_Sym_Impl
operator|<
name|ELFT
operator|>
name|Elf_Sym
expr_stmt|;
typedef|typedef
name|Elf_Dyn_Impl
operator|<
name|ELFT
operator|>
name|Elf_Dyn
expr_stmt|;
name|OutputELFWriter
argument_list|(
name|ELFLinkingContext
operator|&
name|ctx
argument_list|,
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|layout
argument_list|)
expr_stmt|;
name|protected
label|:
comment|// build the sections that need to be created
name|virtual
name|void
name|createDefaultSections
parameter_list|()
function_decl|;
comment|// Build all the output sections
name|void
name|buildChunks
argument_list|(
specifier|const
name|File
operator|&
name|file
argument_list|)
name|override
decl_stmt|;
comment|// Build the output file
name|virtual
name|std
operator|::
name|error_code
name|buildOutput
argument_list|(
specifier|const
name|File
operator|&
name|file
argument_list|)
expr_stmt|;
comment|// Setup the ELF header.
name|virtual
name|std
operator|::
name|error_code
name|setELFHeader
argument_list|()
expr_stmt|;
comment|// Write the file to the path specified
name|std
operator|::
name|error_code
name|writeFile
argument_list|(
argument|const File&File
argument_list|,
argument|StringRef path
argument_list|)
name|override
expr_stmt|;
comment|// Write to the output file.
name|virtual
name|std
operator|::
name|error_code
name|writeOutput
argument_list|(
argument|const File&file
argument_list|,
argument|StringRef path
argument_list|)
expr_stmt|;
comment|// Get the size of the output file that the linker would emit.
name|virtual
name|uint64_t
name|outputFileSize
argument_list|()
specifier|const
expr_stmt|;
comment|// Build the atom to address map, this has to be called
comment|// before applying relocations
name|virtual
name|void
name|buildAtomToAddressMap
parameter_list|(
specifier|const
name|File
modifier|&
name|file
parameter_list|)
function_decl|;
comment|// Build the symbol table for static linking
name|virtual
name|void
name|buildStaticSymbolTable
parameter_list|(
specifier|const
name|File
modifier|&
name|file
parameter_list|)
function_decl|;
comment|// Build the dynamic symbol table for dynamic linking
name|virtual
name|void
name|buildDynamicSymbolTable
parameter_list|(
specifier|const
name|File
modifier|&
name|file
parameter_list|)
function_decl|;
comment|// Build the section header table
name|virtual
name|void
name|buildSectionHeaderTable
parameter_list|()
function_decl|;
comment|// Assign sections that have no segments such as the symbol table,
comment|// section header table, string table etc
name|virtual
name|void
name|assignSectionsWithNoSegments
parameter_list|()
function_decl|;
comment|// Add any runtime files and their atoms to the output
name|void
name|createImplicitFiles
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
operator|&
argument_list|)
name|override
decl_stmt|;
comment|// Finalize the default atom values
name|virtual
name|void
name|finalizeDefaultAtomValues
parameter_list|()
function_decl|;
comment|// This is called by the write section to apply relocations
name|uint64_t
name|addressOfAtom
parameter_list|(
specifier|const
name|Atom
modifier|*
name|atom
parameter_list|)
function|override
block|{
name|auto
name|addr
init|=
name|_atomToAddressMap
operator|.
name|find
argument_list|(
name|atom
argument_list|)
decl_stmt|;
return|return
name|addr
operator|==
name|_atomToAddressMap
operator|.
name|end
argument_list|()
condition|?
literal|0
else|:
name|addr
operator|->
name|second
return|;
block|}
comment|// This is a hook for creating default dynamic entries
name|virtual
name|void
name|createDefaultDynamicEntries
parameter_list|()
block|{}
comment|/// \brief Create symbol table.
name|virtual
name|unique_bump_ptr
operator|<
name|SymbolTable
operator|<
name|ELFT
operator|>>
name|createSymbolTable
argument_list|()
expr_stmt|;
comment|/// \brief create dynamic table.
name|virtual
name|unique_bump_ptr
operator|<
name|DynamicTable
operator|<
name|ELFT
operator|>>
name|createDynamicTable
argument_list|()
expr_stmt|;
comment|/// \brief create dynamic symbol table.
name|virtual
name|unique_bump_ptr
operator|<
name|DynamicSymbolTable
operator|<
name|ELFT
operator|>>
name|createDynamicSymbolTable
argument_list|()
expr_stmt|;
comment|/// \brief Create entry in the dynamic symbols table for this atom.
name|virtual
name|bool
name|isDynSymEntryRequired
argument_list|(
specifier|const
name|SharedLibraryAtom
operator|*
name|sla
argument_list|)
decl|const
block|{
return|return
name|_layout
operator|.
name|isReferencedByDefinedAtom
argument_list|(
name|sla
argument_list|)
return|;
block|}
comment|/// \brief Create DT_NEEDED dynamic tage for the shared library.
name|virtual
name|bool
name|isNeededTagRequired
argument_list|(
specifier|const
name|SharedLibraryAtom
operator|*
name|sla
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Process undefined symbols that left after resolution step.
name|virtual
name|void
name|processUndefinedSymbol
argument_list|(
name|StringRef
name|symName
argument_list|,
name|RuntimeFile
operator|<
name|ELFT
operator|>
operator|&
name|file
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Assign addresses to atoms marking section's start and end.
name|void
name|updateScopeAtomValues
parameter_list|(
name|StringRef
name|sym
parameter_list|,
name|StringRef
name|sec
parameter_list|)
function_decl|;
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
expr_stmt|;
name|ELFLinkingContext
modifier|&
name|_ctx
decl_stmt|;
name|TargetHandler
modifier|&
name|_targetHandler
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Atom
operator|*
operator|,
name|uint64_t
operator|>
name|AtomToAddress
expr_stmt|;
name|AtomToAddress
name|_atomToAddressMap
decl_stmt|;
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|_layout
expr_stmt|;
name|unique_bump_ptr
operator|<
name|ELFHeader
operator|<
name|ELFT
operator|>>
name|_elfHeader
expr_stmt|;
name|unique_bump_ptr
operator|<
name|ProgramHeader
operator|<
name|ELFT
operator|>>
name|_programHeader
expr_stmt|;
name|unique_bump_ptr
operator|<
name|SymbolTable
operator|<
name|ELFT
operator|>>
name|_symtab
expr_stmt|;
name|unique_bump_ptr
operator|<
name|StringTable
operator|<
name|ELFT
operator|>>
name|_strtab
expr_stmt|;
name|unique_bump_ptr
operator|<
name|StringTable
operator|<
name|ELFT
operator|>>
name|_shstrtab
expr_stmt|;
name|unique_bump_ptr
operator|<
name|SectionHeader
operator|<
name|ELFT
operator|>>
name|_shdrtab
expr_stmt|;
name|unique_bump_ptr
operator|<
name|EHFrameHeader
operator|<
name|ELFT
operator|>>
name|_ehFrameHeader
expr_stmt|;
comment|/// \name Dynamic sections.
comment|/// @{
name|unique_bump_ptr
operator|<
name|DynamicTable
operator|<
name|ELFT
operator|>>
name|_dynamicTable
expr_stmt|;
name|unique_bump_ptr
operator|<
name|DynamicSymbolTable
operator|<
name|ELFT
operator|>>
name|_dynamicSymbolTable
expr_stmt|;
name|unique_bump_ptr
operator|<
name|StringTable
operator|<
name|ELFT
operator|>>
name|_dynamicStringTable
expr_stmt|;
name|unique_bump_ptr
operator|<
name|HashSection
operator|<
name|ELFT
operator|>>
name|_hashTable
expr_stmt|;
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|_soNeeded
expr_stmt|;
comment|/// @}
name|private
label|:
specifier|static
name|StringRef
name|maybeGetSOName
parameter_list|(
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|updateScopeAtomValues
parameter_list|(
name|StringRef
name|start
parameter_list|,
name|StringRef
name|end
parameter_list|,
name|StringRef
name|sec
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace elf
end_comment

begin_comment
unit|}
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_ELF_OUTPUT_WRITER_H
end_comment

end_unit

