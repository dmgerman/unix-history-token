begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- NativeSession.h - Native implementation of IPDBSession ---*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
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
name|LLVM_DEBUGINFO_PDB_NATIVE_NATIVESESSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_NATIVE_NATIVESESSION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/IPDBRawSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/IPDBSession.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/DbiModuleDescriptor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/NativeBuiltinSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/NativeRawSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|PDBFile
decl_stmt|;
name|class
name|NativeSession
range|:
name|public
name|IPDBSession
block|{
name|public
operator|:
name|NativeSession
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|PDBFile
operator|>
name|PdbFile
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|BumpPtrAllocator
operator|>
name|Allocator
argument_list|)
block|;
operator|~
name|NativeSession
argument_list|()
name|override
block|;
specifier|static
name|Error
name|createFromPdb
argument_list|(
argument|StringRef Path
argument_list|,
argument|std::unique_ptr<IPDBSession>&Session
argument_list|)
block|;
specifier|static
name|Error
name|createFromExe
argument_list|(
argument|StringRef Path
argument_list|,
argument|std::unique_ptr<IPDBSession>&Session
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|PDBSymbolCompiland
operator|>
name|createCompilandSymbol
argument_list|(
argument|DbiModuleDescriptor MI
argument_list|)
block|;
name|SymIndexId
name|findSymbolByTypeIndex
argument_list|(
argument|codeview::TypeIndex TI
argument_list|)
block|;
name|uint64_t
name|getLoadAddress
argument_list|()
specifier|const
name|override
block|;
name|void
name|setLoadAddress
argument_list|(
argument|uint64_t Address
argument_list|)
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|PDBSymbolExe
operator|>
name|getGlobalScope
argument_list|()
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|PDBSymbol
operator|>
name|getSymbolById
argument_list|(
argument|uint32_t SymbolId
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|PDBSymbol
operator|>
name|findSymbolByAddress
argument_list|(
argument|uint64_t Address
argument_list|,
argument|PDB_SymType Type
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumLineNumbers
operator|>
name|findLineNumbers
argument_list|(
argument|const PDBSymbolCompiland&Compiland
argument_list|,
argument|const IPDBSourceFile&File
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumLineNumbers
operator|>
name|findLineNumbersByAddress
argument_list|(
argument|uint64_t Address
argument_list|,
argument|uint32_t Length
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSourceFiles
operator|>
name|findSourceFiles
argument_list|(
argument|const PDBSymbolCompiland *Compiland
argument_list|,
argument|llvm::StringRef Pattern
argument_list|,
argument|PDB_NameSearchFlags Flags
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBSourceFile
operator|>
name|findOneSourceFile
argument_list|(
argument|const PDBSymbolCompiland *Compiland
argument_list|,
argument|llvm::StringRef Pattern
argument_list|,
argument|PDB_NameSearchFlags Flags
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumChildren
operator|<
name|PDBSymbolCompiland
operator|>>
name|findCompilandsForSourceFile
argument_list|(
argument|llvm::StringRef Pattern
argument_list|,
argument|PDB_NameSearchFlags Flags
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|PDBSymbolCompiland
operator|>
name|findOneCompilandForSourceFile
argument_list|(
argument|llvm::StringRef Pattern
argument_list|,
argument|PDB_NameSearchFlags Flags
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSourceFiles
operator|>
name|getAllSourceFiles
argument_list|()
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSourceFiles
operator|>
name|getSourceFilesForCompiland
argument_list|(
argument|const PDBSymbolCompiland&Compiland
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBSourceFile
operator|>
name|getSourceFileById
argument_list|(
argument|uint32_t FileId
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumDataStreams
operator|>
name|getDebugStreams
argument_list|()
specifier|const
name|override
block|;
name|PDBFile
operator|&
name|getPDBFile
argument_list|()
block|{
return|return
operator|*
name|Pdb
return|;
block|}
specifier|const
name|PDBFile
operator|&
name|getPDBFile
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Pdb
return|;
block|}
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|PDBFile
operator|>
name|Pdb
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|BumpPtrAllocator
operator|>
name|Allocator
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|NativeRawSymbol
operator|>>
name|SymbolCache
block|;
name|DenseMap
operator|<
name|codeview
operator|::
name|TypeIndex
block|,
name|SymIndexId
operator|>
name|TypeIndexToSymbolId
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

