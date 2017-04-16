begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IPDBSession.h - base interface for a PDB symbol context --*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_IPDBSESSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_IPDBSESSION_H
end_define

begin_include
include|#
directive|include
file|"PDBSymbol.h"
end_include

begin_include
include|#
directive|include
file|"PDBTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|PDBSymbolCompiland
decl_stmt|;
name|class
name|PDBSymbolExe
decl_stmt|;
comment|/// IPDBSession defines an interface used to provide a context for querying
comment|/// debug information from a debug data source (for example, a PDB).
name|class
name|IPDBSession
block|{
name|public
label|:
name|virtual
operator|~
name|IPDBSession
argument_list|()
expr_stmt|;
name|virtual
name|uint64_t
name|getLoadAddress
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setLoadAddress
parameter_list|(
name|uint64_t
name|Address
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|PDBSymbolExe
operator|>
name|getGlobalScope
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
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
operator|=
literal|0
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>
name|getConcreteSymbolById
argument_list|(
argument|uint32_t SymbolId
argument_list|)
specifier|const
block|{
return|return
name|unique_dyn_cast_or_null
operator|<
name|T
operator|>
operator|(
name|getSymbolById
argument_list|(
name|SymbolId
argument_list|)
operator|)
return|;
block|}
name|virtual
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
operator|=
literal|0
expr_stmt|;
name|virtual
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
operator|=
literal|0
expr_stmt|;
name|virtual
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
operator|=
literal|0
expr_stmt|;
name|virtual
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
operator|=
literal|0
expr_stmt|;
name|virtual
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
operator|=
literal|0
expr_stmt|;
name|virtual
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
operator|=
literal|0
expr_stmt|;
name|virtual
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
operator|=
literal|0
expr_stmt|;
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSourceFiles
operator|>
name|getAllSourceFiles
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
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
operator|=
literal|0
expr_stmt|;
name|virtual
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
operator|=
literal|0
expr_stmt|;
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumDataStreams
operator|>
name|getDebugStreams
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

