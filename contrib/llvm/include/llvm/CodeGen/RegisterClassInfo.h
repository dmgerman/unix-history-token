begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterClassInfo.h - Dynamic Register Class Info -*- C++ -*-------===//
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
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
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
decl_stmt|;
name|unsigned
name|NumRegs
decl_stmt|;
name|bool
name|ProperSubClass
decl_stmt|;
name|OwningArrayPtr
operator|<
name|unsigned
operator|>
name|Order
expr_stmt|;
name|RCInfo
argument_list|()
operator|:
name|Tag
argument_list|(
literal|0
argument_list|)
operator|,
name|NumRegs
argument_list|(
literal|0
argument_list|)
operator|,
name|ProperSubClass
argument_list|(
argument|false
argument_list|)
block|{}
name|operator
name|ArrayRef
operator|<
name|unsigned
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
name|OwningArrayPtr
operator|<
name|RCInfo
operator|>
name|RegClass
expr_stmt|;
comment|// Tag changes whenever cached information needs to be recomputed. An RCInfo
comment|// entry is valid when its tag matches.
name|unsigned
name|Tag
decl_stmt|;
specifier|const
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
comment|// Callee saved registers of last MF. Assumed to be valid until the next
comment|// runOnFunction() call.
specifier|const
name|uint16_t
modifier|*
name|CalleeSaved
decl_stmt|;
comment|// Map register number to CalleeSaved index + 1;
name|SmallVector
operator|<
name|uint8_t
operator|,
literal|4
operator|>
name|CSRNum
expr_stmt|;
comment|// Reserved registers in the current MF.
name|BitVector
name|Reserved
decl_stmt|;
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
name|unsigned
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
comment|/// overlaps PhysReg, or 0 if Reg doesn't overlap a CSR.
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
name|unsigned
name|N
init|=
name|CSRNum
index|[
name|PhysReg
index|]
condition|)
return|return
name|CalleeSaved
index|[
name|N
operator|-
literal|1
index|]
return|;
return|return
literal|0
return|;
block|}
comment|/// isReserved - Returns true when PhysReg is a reserved register.
comment|///
comment|/// Reserved registers may belong to an allocatable register class, but the
comment|/// target has explicitly requested that they are not used.
comment|///
name|bool
name|isReserved
argument_list|(
name|unsigned
name|PhysReg
argument_list|)
decl|const
block|{
return|return
name|Reserved
operator|.
name|test
argument_list|(
name|PhysReg
argument_list|)
return|;
block|}
comment|/// isAllocatable - Returns true when PhysReg belongs to an allocatable
comment|/// register class and it hasn't been reserved.
comment|///
comment|/// Allocatable registers may show up in the allocation order of some virtual
comment|/// register, so a register allocator needs to track its liveness and
comment|/// availability.
name|bool
name|isAllocatable
argument_list|(
name|unsigned
name|PhysReg
argument_list|)
decl|const
block|{
return|return
name|TRI
operator|->
name|isInAllocatableClass
argument_list|(
name|PhysReg
argument_list|)
operator|&&
operator|!
name|isReserved
argument_list|(
name|PhysReg
argument_list|)
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

