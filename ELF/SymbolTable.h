begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SymbolTable.h --------------------------------------------*- C++ -*-===//
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
name|LLD_ELF_SYMBOL_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_SYMBOL_TABLE_H
end_define

begin_include
include|#
directive|include
file|"InputFiles.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf2
block|{
name|class
name|Lazy
decl_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|OutputSectionBase
expr_stmt|;
struct_decl|struct
name|Symbol
struct_decl|;
name|class
name|Undefined
decl_stmt|;
comment|// SymbolTable is a bucket of all known symbols, including defined,
comment|// undefined, or lazy symbols (the last one is symbols in archive
comment|// files whose archive members are not yet loaded).
comment|//
comment|// We put all symbols of all files to a SymbolTable, and the
comment|// SymbolTable selects the "best" symbols if there are name
comment|// conflicts. For example, obviously, a defined symbol is better than
comment|// an undefined symbol. Or, if there's a conflict between a lazy and a
comment|// undefined, it'll read an archive member to read a real definition
comment|// to replace the lazy symbol. The logic is implemented in resolve().
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|SymbolTable
block|{
name|public
operator|:
name|SymbolTable
argument_list|()
block|;
name|void
name|addFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>
name|File
argument_list|)
block|;
specifier|const
name|llvm
operator|::
name|MapVector
operator|<
name|StringRef
block|,
name|Symbol
operator|*
operator|>
operator|&
name|getSymbols
argument_list|()
specifier|const
block|{
return|return
name|Symtab
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ObjectFile
operator|<
name|ELFT
operator|>>>
operator|&
name|getObjectFiles
argument_list|()
specifier|const
block|{
return|return
name|ObjectFiles
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SharedFile
operator|<
name|ELFT
operator|>>>
operator|&
name|getSharedFiles
argument_list|()
specifier|const
block|{
return|return
name|SharedFiles
return|;
block|}
name|SymbolBody
operator|*
name|addUndefined
argument_list|(
argument|StringRef Name
argument_list|)
block|;
name|SymbolBody
operator|*
name|addUndefinedOpt
argument_list|(
argument|StringRef Name
argument_list|)
block|;
name|void
name|addAbsolute
argument_list|(
argument|StringRef Name
argument_list|,
argument|typename llvm::object::ELFFile<ELFT>::Elf_Sym&ESym
argument_list|)
block|;
name|void
name|addSynthetic
argument_list|(
argument|StringRef Name
argument_list|,
argument|OutputSectionBase<ELFT>&Section
argument_list|,
argument|typename llvm::object::ELFFile<ELFT>::uintX_t Value
argument_list|)
block|;
name|SymbolBody
operator|*
name|addIgnored
argument_list|(
argument|StringRef Name
argument_list|)
block|;
name|void
name|scanShlibUndefined
argument_list|()
block|;
name|SymbolBody
operator|*
name|find
argument_list|(
argument|StringRef Name
argument_list|)
block|;
name|ELFFileBase
operator|<
name|ELFT
operator|>
operator|*
name|findFile
argument_list|(
name|SymbolBody
operator|*
name|B
argument_list|)
block|;
name|private
operator|:
name|Symbol
operator|*
name|insert
argument_list|(
name|SymbolBody
operator|*
name|New
argument_list|)
block|;
name|void
name|addLazy
argument_list|(
name|Lazy
operator|*
name|New
argument_list|)
block|;
name|void
name|addMemberFile
argument_list|(
name|Undefined
operator|*
name|Undef
argument_list|,
name|Lazy
operator|*
name|L
argument_list|)
block|;
name|void
name|resolve
argument_list|(
name|SymbolBody
operator|*
name|Body
argument_list|)
block|;
name|std
operator|::
name|string
name|conflictMsg
argument_list|(
name|SymbolBody
operator|*
name|Old
argument_list|,
name|SymbolBody
operator|*
name|New
argument_list|)
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ArchiveFile
operator|>>
name|ArchiveFiles
block|;
comment|// The order the global symbols are in is not defined. We can use an arbitrary
comment|// order, but it has to be reproducible. That is true even when cross linking.
comment|// The default hashing of StringRef produces different results on 32 and 64
comment|// bit systems so we use a MapVector. That is arbitrary, deterministic but
comment|// a bit inefficient.
comment|// FIXME: Experiment with passing in a custom hashing or sorting the symbols
comment|// once symbol resolution is finished.
name|llvm
operator|::
name|MapVector
operator|<
name|StringRef
block|,
name|Symbol
operator|*
operator|>
name|Symtab
block|;
name|llvm
operator|::
name|BumpPtrAllocator
name|Alloc
block|;
name|llvm
operator|::
name|DenseSet
operator|<
name|StringRef
operator|>
name|ComdatGroups
block|;
comment|// The writer needs to infer the machine type from the object files.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ObjectFile
operator|<
name|ELFT
operator|>>>
name|ObjectFiles
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SharedFile
operator|<
name|ELFT
operator|>>>
name|SharedFiles
block|;
name|llvm
operator|::
name|DenseSet
operator|<
name|StringRef
operator|>
name|IncludedSoNames
block|; }
expr_stmt|;
block|}
comment|// namespace elf2
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

