begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- NativeBuiltinSymbol.h -------------------------------------- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_NATIVE_NATIVEBUILTINSYMBOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_NATIVE_NATIVEBUILTINSYMBOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/NativeRawSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/PDBTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|NativeSession
decl_stmt|;
name|class
name|NativeBuiltinSymbol
range|:
name|public
name|NativeRawSymbol
block|{
name|public
operator|:
name|NativeBuiltinSymbol
argument_list|(
argument|NativeSession&PDBSession
argument_list|,
argument|SymIndexId Id
argument_list|,
argument|PDB_BuiltinType T
argument_list|,
argument|uint64_t L
argument_list|)
block|;
operator|~
name|NativeBuiltinSymbol
argument_list|()
name|override
block|;
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|NativeRawSymbol
operator|>
name|clone
argument_list|()
specifier|const
name|override
block|;
name|void
name|dump
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|int Indent
argument_list|)
specifier|const
name|override
block|;
name|PDB_SymType
name|getSymTag
argument_list|()
specifier|const
name|override
block|;
name|PDB_BuiltinType
name|getBuiltinType
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isConstType
argument_list|()
specifier|const
name|override
block|;
name|uint64_t
name|getLength
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isUnalignedType
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isVolatileType
argument_list|()
specifier|const
name|override
block|;
name|protected
operator|:
name|NativeSession
operator|&
name|Session
block|;
name|PDB_BuiltinType
name|Type
block|;
name|uint64_t
name|Length
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

