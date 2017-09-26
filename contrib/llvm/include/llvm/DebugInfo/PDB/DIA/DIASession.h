begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DIASession.h - DIA implementation of IPDBSession ---------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_DIA_DIASESSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_DIA_DIASESSION_H
end_define

begin_include
include|#
directive|include
file|"DIASupport.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/IPDBSession.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|namespace
name|pdb
block|{
name|class
name|DIASession
range|:
name|public
name|IPDBSession
block|{
name|public
operator|:
name|explicit
name|DIASession
argument_list|(
name|CComPtr
operator|<
name|IDiaSession
operator|>
name|DiaSession
argument_list|)
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
name|private
operator|:
name|CComPtr
operator|<
name|IDiaSession
operator|>
name|Session
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

