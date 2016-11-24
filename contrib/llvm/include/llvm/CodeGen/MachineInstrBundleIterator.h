begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/MachineInstrBundleIterator.h ----------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// Defines an iterator class that bundles MachineInstr.
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
name|LLVM_CODEGEN_MACHINEINSTRBUNDLEITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEINSTRBUNDLEITERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MachineBasicBlock iterator that automatically skips over MIs that are
comment|/// inside bundles (i.e. walk top level MIs only).
name|template
operator|<
name|typename
name|Ty
operator|>
name|class
name|MachineInstrBundleIterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|bidirectional_iterator_tag
operator|,
name|Ty
operator|,
name|ptrdiff_t
operator|>
block|{
typedef|typedef
name|ilist_iterator
operator|<
name|Ty
operator|>
name|instr_iterator
expr_stmt|;
name|instr_iterator
name|MII
expr_stmt|;
name|public
label|:
name|MachineInstrBundleIterator
argument_list|(
argument|instr_iterator MI
argument_list|)
block|:
name|MII
argument_list|(
argument|MI
argument_list|)
block|{}
name|MachineInstrBundleIterator
argument_list|(
name|Ty
operator|&
name|MI
argument_list|)
operator|:
name|MII
argument_list|(
argument|MI
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|MI
operator|.
name|isBundledWithPred
argument_list|()
operator|&&
literal|"It's not legal to initialize "
literal|"MachineInstrBundleIterator with a "
literal|"bundled MI"
argument_list|)
block|;   }
name|MachineInstrBundleIterator
argument_list|(
name|Ty
operator|*
name|MI
argument_list|)
operator|:
name|MII
argument_list|(
argument|MI
argument_list|)
block|{
comment|// FIXME: This conversion should be explicit.
name|assert
argument_list|(
operator|(
operator|!
name|MI
operator|||
operator|!
name|MI
operator|->
name|isBundledWithPred
argument_list|()
operator|)
operator|&&
literal|"It's not legal to initialize "
literal|"MachineInstrBundleIterator "
literal|"with a bundled MI"
argument_list|)
block|;   }
comment|// Template allows conversion from const to nonconst.
name|template
operator|<
name|class
name|OtherTy
operator|>
name|MachineInstrBundleIterator
argument_list|(
specifier|const
name|MachineInstrBundleIterator
operator|<
name|OtherTy
operator|>
operator|&
name|I
argument_list|)
operator|:
name|MII
argument_list|(
argument|I.getInstrIterator()
argument_list|)
block|{}
name|MachineInstrBundleIterator
argument_list|()
operator|:
name|MII
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|Ty
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|MII
return|;
block|}
name|Ty
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|operator
operator|*
operator|(
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// FIXME: This conversion should be explicit.
end_comment

begin_expr_stmt
name|operator
name|Ty
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|MII
operator|.
name|getNodePtrUnchecked
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MachineInstrBundleIterator
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|MII
operator|==
name|X
operator|.
name|MII
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|MachineInstrBundleIterator
operator|&
name|X
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|X
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Increment and decrement operators...
end_comment

begin_expr_stmt
name|MachineInstrBundleIterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
do|do
operator|--
name|MII
expr_stmt|;
do|while
condition|(
name|MII
operator|->
name|isBundledWithPred
argument_list|()
condition|)
do|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}   MachineInstrBundleIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
while|while
condition|(
name|MII
operator|->
name|isBundledWithSucc
argument_list|()
condition|)
operator|++
name|MII
expr_stmt|;
operator|++
name|MII
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}   MachineInstrBundleIterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|MachineInstrBundleIterator
name|Temp
operator|=
operator|*
name|this
block|;
operator|--
operator|*
name|this
block|;
return|return
name|Temp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|MachineInstrBundleIterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|MachineInstrBundleIterator
name|Temp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|Temp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|instr_iterator
name|getInstrIterator
argument_list|()
specifier|const
block|{
return|return
name|MII
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

