begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/AllocationOrder.h - Allocation Order -*- C++ -*-------===//
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
comment|// This file implements an allocation order for virtual registers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The preferred allocation order for a virtual register depends on allocation
end_comment

begin_comment
comment|// hints and target hooks. The AllocationOrder class encapsulates all of that.
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
name|LLVM_CODEGEN_ALLOCATIONORDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_ALLOCATIONORDER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|RegisterClassInfo
decl_stmt|;
name|class
name|VirtRegMap
decl_stmt|;
name|class
name|AllocationOrder
block|{
specifier|const
name|unsigned
modifier|*
name|Begin
decl_stmt|;
specifier|const
name|unsigned
modifier|*
name|End
decl_stmt|;
specifier|const
name|unsigned
modifier|*
name|Pos
decl_stmt|;
specifier|const
name|RegisterClassInfo
modifier|&
name|RCI
decl_stmt|;
name|unsigned
name|Hint
decl_stmt|;
name|bool
name|OwnedBegin
decl_stmt|;
name|public
label|:
comment|/// AllocationOrder - Create a new AllocationOrder for VirtReg.
comment|/// @param VirtReg      Virtual register to allocate for.
comment|/// @param VRM          Virtual register map for function.
comment|/// @param RegClassInfo Information about reserved and allocatable registers.
name|AllocationOrder
argument_list|(
argument|unsigned VirtReg
argument_list|,
argument|const VirtRegMap&VRM
argument_list|,
argument|const RegisterClassInfo&RegClassInfo
argument_list|)
empty_stmt|;
operator|~
name|AllocationOrder
argument_list|()
expr_stmt|;
comment|/// next - Return the next physical register in the allocation order, or 0.
comment|/// It is safe to call next again after it returned 0.
comment|/// It will keep returning 0 until rewind() is called.
name|unsigned
name|next
parameter_list|()
block|{
comment|// First take the hint.
if|if
condition|(
operator|!
name|Pos
condition|)
block|{
name|Pos
operator|=
name|Begin
expr_stmt|;
if|if
condition|(
name|Hint
condition|)
return|return
name|Hint
return|;
block|}
comment|// Then look at the order from TRI.
while|while
condition|(
name|Pos
operator|!=
name|End
condition|)
block|{
name|unsigned
name|Reg
init|=
operator|*
name|Pos
operator|++
decl_stmt|;
if|if
condition|(
name|Reg
operator|!=
name|Hint
condition|)
return|return
name|Reg
return|;
block|}
return|return
literal|0
return|;
block|}
comment|/// rewind - Start over from the beginning.
name|void
name|rewind
parameter_list|()
block|{
name|Pos
operator|=
literal|0
expr_stmt|;
block|}
comment|/// isHint - Return true if PhysReg is a preferred register.
name|bool
name|isHint
argument_list|(
name|unsigned
name|PhysReg
argument_list|)
decl|const
block|{
return|return
name|PhysReg
operator|==
name|Hint
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

