begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDBSymbolTypeBaseClass.h - base class type information ---*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_PDBSYMBOLTYPEBASECLASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_PDBSYMBOLTYPEBASECLASS_H
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
name|class
name|PDBSymbolTypeBaseClass
range|:
name|public
name|PDBSymbol
block|{
name|public
operator|:
name|PDBSymbolTypeBaseClass
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
name|Symbol
argument_list|)
block|;
name|DECLARE_PDB_SYMBOL_CONCRETE_TYPE
argument_list|(
argument|PDB_SymType::BaseClass
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
argument|getClassParentId
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasConstructor
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isConstType
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasAssignmentOperator
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasCastOperator
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasNestedTypes
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isIndirectVirtualBaseClass
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
argument|isNested
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getOffset
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasOverloadedOperator
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isPacked
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isScoped
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getSymIndexId
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getTypeId
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getUdtKind
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isUnalignedType
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isVirtualBaseClass
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getVirtualBaseDispIndex
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getVirtualBasePointerOffset
argument_list|)
comment|// FORWARD_SYMBOL_METHOD(getVirtualBaseTableType)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getVirtualTableShapeId
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isVolatileType
argument_list|)
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_PDBSYMBOLTYPEBASECLASS_H
end_comment

end_unit

