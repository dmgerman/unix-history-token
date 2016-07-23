begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDBSymbolThunk.h - Support for querying PDB thunks ---------------*-===//
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
name|LLVM_DEBUGINFO_PDB_PDBSYMBOLTHUNK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_PDBSYMBOLTHUNK_H
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|pdb
block|{
name|class
name|PDBSymbolThunk
range|:
name|public
name|PDBSymbol
block|{
name|public
operator|:
name|PDBSymbolThunk
argument_list|(
specifier|const
name|IPDBSession
operator|&
name|PDBSession
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBRawSymbol
operator|>
name|ThunkSymbol
argument_list|)
block|;
name|DECLARE_PDB_SYMBOL_CONCRETE_TYPE
argument_list|(
argument|PDB_SymType::Thunk
argument_list|)
name|void
name|dump
argument_list|(
argument|PDBSymDumper&Dumper
argument_list|)
specifier|const
name|override
block|;
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getAccess
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getAddressOffset
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getAddressSection
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getClassParentId
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isConstType
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isIntroVirtualFunction
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isStatic
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getLength
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getLexicalParentId
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getName
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isPureVirtual
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getRelativeVirtualAddress
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getTargetOffset
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getTargetRelativeVirtualAddress
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getTargetVirtualAddress
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getTargetSection
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getThunkOrdinal
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getTypeId
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isUnalignedType
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isVirtual
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getVirtualAddress
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getVirtualBaseOffset
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isVolatileType
argument_list|)
block|}
decl_stmt|;
block|}
comment|// namespace llvm
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_PDBSYMBOLTHUNK_H
end_comment

end_unit

