begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RegisterClassInfo.h - Dynamic Register Class Info --------*- C++ -*-===//
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
comment|// This file implements the RegisterClassInfo class which provides dynamic
end_comment

begin_comment
comment|// information about target register classes. Callee saved and reserved
end_comment

begin_comment
comment|// registers depends on calling conventions and other dynamic information, so
end_comment

begin_comment
comment|// some things cannot be determined statically.
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
name|LLVM_CODEGEN_REGISTERCLASSINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_REGISTERCLASSINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
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
name|class
name|RegisterClassInfo
block|{
struct|struct
name|RCInfo
block|{
name|unsigned
name|Tag
init|=
literal|0
decl_stmt|;
name|unsigned
name|NumRegs
init|=
literal|0
decl_stmt|;
name|bool
name|ProperSubClass
init|=
name|false
decl_stmt|;
name|uint8_t
name|MinCost
init|=
literal|0
decl_stmt|;
name|uint16_t
name|LastCostChange
init|=
literal|0
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MCPhysReg
index|[]
operator|>
name|Order
expr_stmt|;
name|RCInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
name|operator
name|ArrayRef
operator|<
name|MCPhysReg
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|makeArrayRef
argument_list|(
name|Order
operator|.
name|get
argument_list|()
argument_list|,
name|NumRegs
argument_list|)
return|;
block|}
block|}
struct|;
comment|// Brief cached information for each register class.
name|std
operator|::
name|unique_ptr
operator|<
name|RCInfo
index|[]
operator|>
name|RegClass
expr_stmt|;
comment|// Tag changes whenever cached information needs to be recomputed. An RCInfo
comment|// entry is valid when its tag matches.
name|unsigned
name|Tag
init|=
literal|0
decl_stmt|;
specifier|const
name|MachineFunction
modifier|*
name|MF
init|=
name|nullptr
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
init|=
name|nullptr
decl_stmt|;
comment|// Callee saved registers of last MF. Assumed to be valid until the next
comment|// runOnFunction() call.
comment|// Used only to determine if an update was made to CalleeSavedAliases.
specifier|const
name|MCPhysReg
modifier|*
name|CalleeSavedRegs
init|=
name|nullptr
decl_stmt|;
comment|// Map register alias to the callee saved Register.
name|SmallVector
operator|<
name|MCPhysReg
operator|,
literal|4
operator|>
name|CalleeSavedAliases
expr_stmt|;
comment|// Reserved registers in the current MF.
name|BitVector
name|Reserved
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|unsigned
index|[]
operator|>
name|PSetLimits
expr_stmt|;
comment|// Compute all information about RC.
name|void
name|compute
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
decl_stmt|;
comment|// Return an up-to-date RCInfo for RC.
specifier|const
name|RCInfo
modifier|&
name|get
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
specifier|const
name|RCInfo
modifier|&
name|RCI
init|=
name|RegClass
index|[
name|RC
operator|->
name|getID
argument_list|()
index|]
decl_stmt|;
if|if
condition|(
name|Tag
operator|!=
name|RCI
operator|.
name|Tag
condition|)
name|compute
argument_list|(
name|RC
argument_list|)
expr_stmt|;
return|return
name|RCI
return|;
block|}
name|public
label|:
name|RegisterClassInfo
argument_list|()
expr_stmt|;
comment|/// runOnFunction - Prepare to answer questions about MF. This must be called
comment|/// before any other methods are used.
name|void
name|runOnMachineFunction
parameter_list|(
specifier|const
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// getNumAllocatableRegs - Returns the number of actually allocatable
comment|/// registers in RC in the current function.
name|unsigned
name|getNumAllocatableRegs
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
return|return
name|get
argument_list|(
name|RC
argument_list|)
operator|.
name|NumRegs
return|;
block|}
comment|/// getOrder - Returns the preferred allocation order for RC. The order
comment|/// contains no reserved registers, and registers that alias callee saved
comment|/// registers come last.
name|ArrayRef
operator|<
name|MCPhysReg
operator|>
name|getOrder
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|{
return|return
name|get
argument_list|(
name|RC
argument_list|)
return|;
block|}
comment|/// isProperSubClass - Returns true if RC has a legal super-class with more
comment|/// allocatable registers.
comment|///
comment|/// Register classes like GR32_NOSP are not proper sub-classes because %esp
comment|/// is not allocatable.  Similarly, tGPR is not a proper sub-class in Thumb
comment|/// mode because the GPR super-class is not legal.
name|bool
name|isProperSubClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
return|return
name|get
argument_list|(
name|RC
argument_list|)
operator|.
name|ProperSubClass
return|;
block|}
comment|/// getLastCalleeSavedAlias - Returns the last callee saved register that
comment|/// overlaps PhysReg, or 0 if Reg doesn't overlap a CalleeSavedAliases.
name|unsigned
name|getLastCalleeSavedAlias
argument_list|(
name|unsigned
name|PhysReg
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|TargetRegisterInfo
operator|::
name|isPhysicalRegister
argument_list|(
name|PhysReg
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|PhysReg
operator|<
name|CalleeSavedAliases
operator|.
name|size
argument_list|()
condition|)
return|return
name|CalleeSavedAliases
index|[
name|PhysReg
index|]
return|;
return|return
literal|0
return|;
block|}
comment|/// Get the minimum register cost in RC's allocation order.
comment|/// This is the smallest value returned by TRI->getCostPerUse(Reg) for all
comment|/// the registers in getOrder(RC).
name|unsigned
name|getMinCost
parameter_list|(
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|)
block|{
return|return
name|get
argument_list|(
name|RC
argument_list|)
operator|.
name|MinCost
return|;
block|}
comment|/// Get the position of the last cost change in getOrder(RC).
comment|///
comment|/// All registers in getOrder(RC).slice(getLastCostChange(RC)) will have the
comment|/// same cost according to TRI->getCostPerUse().
name|unsigned
name|getLastCostChange
parameter_list|(
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|)
block|{
return|return
name|get
argument_list|(
name|RC
argument_list|)
operator|.
name|LastCostChange
return|;
block|}
comment|/// Get the register unit limit for the given pressure set index.
comment|///
comment|/// RegisterClassInfo adjusts this limit for reserved registers.
name|unsigned
name|getRegPressureSetLimit
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|PSetLimits
index|[
name|Idx
index|]
condition|)
name|PSetLimits
index|[
name|Idx
index|]
operator|=
name|computePSetLimit
argument_list|(
name|Idx
argument_list|)
expr_stmt|;
return|return
name|PSetLimits
index|[
name|Idx
index|]
return|;
block|}
name|protected
label|:
name|unsigned
name|computePSetLimit
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
decl_stmt|;
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

begin_comment
comment|// LLVM_CODEGEN_REGISTERCLASSINFO_H
end_comment

end_unit

