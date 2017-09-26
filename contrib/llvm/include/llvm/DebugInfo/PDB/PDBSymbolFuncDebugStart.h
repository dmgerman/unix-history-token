begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDBSymbolFuncDebugStart.h - function start bounds info ---*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_PDBSYMBOLFUNCDEBUGSTART_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_PDBSYMBOLFUNCDEBUGSTART_H
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
name|PDBSymbolFuncDebugStart
range|:
name|public
name|PDBSymbol
block|{
name|public
operator|:
name|PDBSymbolFuncDebugStart
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
name|FuncDebugStartSymbol
argument_list|)
block|;
name|DECLARE_PDB_SYMBOL_CONCRETE_TYPE
argument_list|(
argument|PDB_SymType::FuncDebugStart
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
argument|getAddressOffset
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getAddressSection
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasCustomCallingConvention
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasFarReturn
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasInterruptReturn
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isStatic
argument_list|)
name|FORWARD_SYMBOL_ID_METHOD
argument_list|(
argument|getLexicalParent
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getLocationType
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasNoInlineAttribute
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasNoReturnAttribute
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isUnreached
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getOffset
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasOptimizedCodeDebugInfo
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getRelativeVirtualAddress
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getVirtualAddress
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
comment|// LLVM_DEBUGINFO_PDB_PDBSYMBOLFUNCDEBUGSTART_H
end_comment

end_unit

