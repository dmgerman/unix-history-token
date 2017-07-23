begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ConcreteSymbolEnumerator.h -------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_CONCRETESYMBOLENUMERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_CONCRETESYMBOLENUMERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/IPDBEnumChildren.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/PDBTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
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
name|template
operator|<
name|typename
name|ChildType
operator|>
name|class
name|ConcreteSymbolEnumerator
operator|:
name|public
name|IPDBEnumChildren
operator|<
name|ChildType
operator|>
block|{
name|public
operator|:
name|ConcreteSymbolEnumerator
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSymbols
operator|>
name|SymbolEnumerator
argument_list|)
operator|:
name|Enumerator
argument_list|(
argument|std::move(SymbolEnumerator)
argument_list|)
block|{}
operator|~
name|ConcreteSymbolEnumerator
argument_list|()
name|override
operator|=
expr|default
block|;
name|uint32_t
name|getChildCount
argument_list|()
specifier|const
name|override
block|{
return|return
name|Enumerator
operator|->
name|getChildCount
argument_list|()
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|ChildType
operator|>
name|getChildAtIndex
argument_list|(
argument|uint32_t Index
argument_list|)
specifier|const
name|override
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|PDBSymbol
operator|>
name|Child
operator|=
name|Enumerator
operator|->
name|getChildAtIndex
argument_list|(
name|Index
argument_list|)
block|;
return|return
name|unique_dyn_cast_or_null
operator|<
name|ChildType
operator|>
operator|(
name|Child
operator|)
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|ChildType
operator|>
name|getNext
argument_list|()
name|override
block|{
return|return
name|unique_dyn_cast_or_null
operator|<
name|ChildType
operator|>
operator|(
name|Enumerator
operator|->
name|getNext
argument_list|()
operator|)
return|;
block|}
name|void
name|reset
argument_list|()
name|override
block|{
name|Enumerator
operator|->
name|reset
argument_list|()
block|; }
name|ConcreteSymbolEnumerator
operator|<
name|ChildType
operator|>
operator|*
name|clone
argument_list|()
specifier|const
name|override
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSymbols
operator|>
name|WrappedClone
argument_list|(
name|Enumerator
operator|->
name|clone
argument_list|()
argument_list|)
block|;
return|return
name|new
name|ConcreteSymbolEnumerator
operator|<
name|ChildType
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|WrappedClone
argument_list|)
operator|)
return|;
block|}
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumSymbols
operator|>
name|Enumerator
block|; }
expr_stmt|;
block|}
comment|// end namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_CONCRETESYMBOLENUMERATOR_H
end_comment

end_unit

