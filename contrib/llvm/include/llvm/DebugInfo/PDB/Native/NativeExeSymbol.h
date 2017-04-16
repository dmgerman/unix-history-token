begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- NativeExeSymbol.h - native impl for PDBSymbolExe ---------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_NATIVE_NATIVEEXESYMBOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_NATIVE_NATIVEEXESYMBOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/NativeRawSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/NativeSession.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|NativeExeSymbol
range|:
name|public
name|NativeRawSymbol
block|{
name|public
operator|:
name|NativeExeSymbol
argument_list|(
name|NativeSession
operator|&
name|Session
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSymbols
operator|>
name|findChildren
argument_list|(
argument|PDB_SymType Type
argument_list|)
specifier|const
name|override
block|;
name|uint32_t
name|getAge
argument_list|()
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|getSymbolsFileName
argument_list|()
specifier|const
name|override
block|;
name|PDB_UniqueId
name|getGuid
argument_list|()
specifier|const
name|override
block|;
name|bool
name|hasCTypes
argument_list|()
specifier|const
name|override
block|;
name|bool
name|hasPrivateSymbols
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|PDBFile
operator|&
name|File
block|; }
decl_stmt|;
block|}
comment|// namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

