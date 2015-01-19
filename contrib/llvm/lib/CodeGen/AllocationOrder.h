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

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

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
name|SmallVector
operator|<
name|MCPhysReg
operator|,
literal|16
operator|>
name|Hints
expr_stmt|;
name|ArrayRef
operator|<
name|MCPhysReg
operator|>
name|Order
expr_stmt|;
name|int
name|Pos
decl_stmt|;
name|public
label|:
comment|/// Create a new AllocationOrder for VirtReg.
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
comment|/// Get the allocation order without reordered hints.
name|ArrayRef
operator|<
name|MCPhysReg
operator|>
name|getOrder
argument_list|()
specifier|const
block|{
return|return
name|Order
return|;
block|}
comment|/// Return the next physical register in the allocation order, or 0.
comment|/// It is safe to call next() again after it returned 0, it will keep
comment|/// returning 0 until rewind() is called.
name|unsigned
name|next
parameter_list|(
name|unsigned
name|Limit
init|=
literal|0
parameter_list|)
block|{
if|if
condition|(
name|Pos
operator|<
literal|0
condition|)
return|return
name|Hints
operator|.
name|end
argument_list|()
index|[
name|Pos
operator|++
index|]
return|;
if|if
condition|(
operator|!
name|Limit
condition|)
name|Limit
operator|=
name|Order
operator|.
name|size
argument_list|()
expr_stmt|;
while|while
condition|(
name|Pos
operator|<
name|int
argument_list|(
name|Limit
argument_list|)
condition|)
block|{
name|unsigned
name|Reg
init|=
name|Order
index|[
name|Pos
operator|++
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|isHint
argument_list|(
name|Reg
argument_list|)
condition|)
return|return
name|Reg
return|;
block|}
return|return
literal|0
return|;
block|}
comment|/// As next(), but allow duplicates to be returned, and stop before the
comment|/// Limit'th register in the RegisterClassInfo allocation order.
comment|///
comment|/// This can produce more than Limit registers if there are hints.
name|unsigned
name|nextWithDups
parameter_list|(
name|unsigned
name|Limit
parameter_list|)
block|{
if|if
condition|(
name|Pos
operator|<
literal|0
condition|)
return|return
name|Hints
operator|.
name|end
argument_list|()
index|[
name|Pos
operator|++
index|]
return|;
if|if
condition|(
name|Pos
operator|<
name|int
argument_list|(
name|Limit
argument_list|)
condition|)
return|return
name|Order
index|[
name|Pos
operator|++
index|]
return|;
return|return
literal|0
return|;
block|}
comment|/// Start over from the beginning.
name|void
name|rewind
parameter_list|()
block|{
name|Pos
operator|=
operator|-
name|int
argument_list|(
name|Hints
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// Return true if the last register returned from next() was a preferred register.
name|bool
name|isHint
argument_list|()
specifier|const
block|{
return|return
name|Pos
operator|<=
literal|0
return|;
block|}
comment|/// Return true if PhysReg is a preferred register.
name|bool
name|isHint
argument_list|(
name|unsigned
name|PhysReg
argument_list|)
decl|const
block|{
return|return
name|std
operator|::
name|find
argument_list|(
name|Hints
operator|.
name|begin
argument_list|()
argument_list|,
name|Hints
operator|.
name|end
argument_list|()
argument_list|,
name|PhysReg
argument_list|)
operator|!=
name|Hints
operator|.
name|end
argument_list|()
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

