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
file|"PDBTypes.h"
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
name|auto
name|Symbol
argument_list|(
name|getSymbolById
argument_list|(
name|SymbolId
argument_list|)
argument_list|)
block|;
if|if
condition|(
operator|!
name|Symbol
condition|)
return|return
name|nullptr
return|;
name|T
operator|*
name|ConcreteSymbol
operator|=
name|dyn_cast
operator|<
name|T
operator|>
operator|(
name|Symbol
operator|.
name|get
argument_list|()
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|ConcreteSymbol
condition|)
return|return
name|nullptr
return|;
name|Symbol
operator|.
name|release
argument_list|()
expr_stmt|;
return|return
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>
operator|(
name|ConcreteSymbol
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

