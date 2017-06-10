begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/VirtRegMap.h - Virtual Register Map -*- C++ -*--------===//
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
comment|// This file implements a virtual register map. This maps virtual registers to
end_comment

begin_comment
comment|// physical registers and virtual registers to stack slots. It is created and
end_comment

begin_comment
comment|// updated by a register allocator and then used by a machine code rewriter that
end_comment

begin_comment
comment|// adds spill code and rewrites virtual into physical register references.
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
name|LLVM_CODEGEN_VIRTREGMAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_VIRTREGMAP_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/IndexedMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
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
name|MachineInstr
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|SlotIndexes
decl_stmt|;
name|class
name|VirtRegMap
range|:
name|public
name|MachineFunctionPass
block|{
name|public
operator|:
expr|enum
block|{
name|NO_PHYS_REG
operator|=
literal|0
block|,
name|NO_STACK_SLOT
operator|=
operator|(
literal|1L
operator|<<
literal|30
operator|)
operator|-
literal|1
block|,
name|MAX_STACK_SLOT
operator|=
operator|(
literal|1L
operator|<<
literal|18
operator|)
operator|-
literal|1
block|}
block|;
name|private
operator|:
name|MachineRegisterInfo
operator|*
name|MRI
block|;
specifier|const
name|TargetInstrInfo
operator|*
name|TII
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
name|MachineFunction
operator|*
name|MF
block|;
comment|/// Virt2PhysMap - This is a virtual to physical register
comment|/// mapping. Each virtual register is required to have an entry in
comment|/// it; even spilled virtual registers (the register mapped to a
comment|/// spilled register is the temporary used to load it from the
comment|/// stack).
name|IndexedMap
operator|<
name|unsigned
block|,
name|VirtReg2IndexFunctor
operator|>
name|Virt2PhysMap
block|;
comment|/// Virt2StackSlotMap - This is virtual register to stack slot
comment|/// mapping. Each spilled virtual register has an entry in it
comment|/// which corresponds to the stack slot this register is spilled
comment|/// at.
name|IndexedMap
operator|<
name|int
block|,
name|VirtReg2IndexFunctor
operator|>
name|Virt2StackSlotMap
block|;
comment|/// Virt2SplitMap - This is virtual register to splitted virtual register
comment|/// mapping.
name|IndexedMap
operator|<
name|unsigned
block|,
name|VirtReg2IndexFunctor
operator|>
name|Virt2SplitMap
block|;
comment|/// createSpillSlot - Allocate a spill slot for RC from MFI.
name|unsigned
name|createSpillSlot
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
block|;
name|VirtRegMap
argument_list|(
specifier|const
name|VirtRegMap
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|VirtRegMap
operator|&
operator|)
operator|=
name|delete
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|VirtRegMap
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
name|ID
argument_list|)
block|,
name|Virt2PhysMap
argument_list|(
name|NO_PHYS_REG
argument_list|)
block|,
name|Virt2StackSlotMap
argument_list|(
name|NO_STACK_SLOT
argument_list|)
block|,
name|Virt2SplitMap
argument_list|(
literal|0
argument_list|)
block|{ }
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|{
name|AU
operator|.
name|setPreservesAll
argument_list|()
block|;
name|MachineFunctionPass
operator|::
name|getAnalysisUsage
argument_list|(
name|AU
argument_list|)
block|;     }
name|MachineFunction
operator|&
name|getMachineFunction
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|MF
operator|&&
literal|"getMachineFunction called before runOnMachineFunction"
argument_list|)
block|;
return|return
operator|*
name|MF
return|;
block|}
name|MachineRegisterInfo
operator|&
name|getRegInfo
argument_list|()
specifier|const
block|{
return|return
operator|*
name|MRI
return|;
block|}
specifier|const
name|TargetRegisterInfo
operator|&
name|getTargetRegInfo
argument_list|()
specifier|const
block|{
return|return
operator|*
name|TRI
return|;
block|}
name|void
name|grow
argument_list|()
block|;
comment|/// @brief returns true if the specified virtual register is
comment|/// mapped to a physical register
name|bool
name|hasPhys
argument_list|(
argument|unsigned virtReg
argument_list|)
specifier|const
block|{
return|return
name|getPhys
argument_list|(
name|virtReg
argument_list|)
operator|!=
name|NO_PHYS_REG
return|;
block|}
comment|/// @brief returns the physical register mapped to the specified
comment|/// virtual register
name|unsigned
name|getPhys
argument_list|(
argument|unsigned virtReg
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|virtReg
argument_list|)
argument_list|)
block|;
return|return
name|Virt2PhysMap
index|[
name|virtReg
index|]
return|;
block|}
comment|/// @brief creates a mapping for the specified virtual register to
comment|/// the specified physical register
name|void
name|assignVirt2Phys
argument_list|(
argument|unsigned virtReg
argument_list|,
argument|MCPhysReg physReg
argument_list|)
block|;
comment|/// @brief clears the specified virtual register's, physical
comment|/// register mapping
name|void
name|clearVirt
argument_list|(
argument|unsigned virtReg
argument_list|)
block|{
name|assert
argument_list|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|virtReg
argument_list|)
argument_list|)
block|;
name|assert
argument_list|(
name|Virt2PhysMap
index|[
name|virtReg
index|]
operator|!=
name|NO_PHYS_REG
operator|&&
literal|"attempt to clear a not assigned virtual register"
argument_list|)
block|;
name|Virt2PhysMap
index|[
name|virtReg
index|]
operator|=
name|NO_PHYS_REG
block|;     }
comment|/// @brief clears all virtual to physical register mappings
name|void
name|clearAllVirt
argument_list|()
block|{
name|Virt2PhysMap
operator|.
name|clear
argument_list|()
block|;
name|grow
argument_list|()
block|;     }
comment|/// @brief returns true if VirtReg is assigned to its preferred physreg.
name|bool
name|hasPreferredPhys
argument_list|(
argument|unsigned VirtReg
argument_list|)
block|;
comment|/// @brief returns true if VirtReg has a known preferred register.
comment|/// This returns false if VirtReg has a preference that is a virtual
comment|/// register that hasn't been assigned yet.
name|bool
name|hasKnownPreference
argument_list|(
argument|unsigned VirtReg
argument_list|)
block|;
comment|/// @brief records virtReg is a split live interval from SReg.
name|void
name|setIsSplitFromReg
argument_list|(
argument|unsigned virtReg
argument_list|,
argument|unsigned SReg
argument_list|)
block|{
name|Virt2SplitMap
index|[
name|virtReg
index|]
operator|=
name|SReg
block|;     }
comment|/// @brief returns the live interval virtReg is split from.
name|unsigned
name|getPreSplitReg
argument_list|(
argument|unsigned virtReg
argument_list|)
specifier|const
block|{
return|return
name|Virt2SplitMap
index|[
name|virtReg
index|]
return|;
block|}
comment|/// getOriginal - Return the original virtual register that VirtReg descends
comment|/// from through splitting.
comment|/// A register that was not created by splitting is its own original.
comment|/// This operation is idempotent.
name|unsigned
name|getOriginal
argument_list|(
argument|unsigned VirtReg
argument_list|)
specifier|const
block|{
name|unsigned
name|Orig
operator|=
name|getPreSplitReg
argument_list|(
name|VirtReg
argument_list|)
block|;
return|return
name|Orig
condition|?
name|Orig
else|:
name|VirtReg
return|;
block|}
comment|/// @brief returns true if the specified virtual register is not
comment|/// mapped to a stack slot or rematerialized.
name|bool
name|isAssignedReg
argument_list|(
argument|unsigned virtReg
argument_list|)
specifier|const
block|{
if|if
condition|(
name|getStackSlot
argument_list|(
name|virtReg
argument_list|)
operator|==
name|NO_STACK_SLOT
condition|)
return|return
name|true
return|;
comment|// Split register can be assigned a physical register as well as a
comment|// stack slot or remat id.
return|return
operator|(
name|Virt2SplitMap
index|[
name|virtReg
index|]
operator|&&
name|Virt2PhysMap
index|[
name|virtReg
index|]
operator|!=
name|NO_PHYS_REG
operator|)
return|;
block|}
comment|/// @brief returns the stack slot mapped to the specified virtual
comment|/// register
name|int
name|getStackSlot
argument_list|(
name|unsigned
name|virtReg
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|virtReg
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Virt2StackSlotMap
index|[
name|virtReg
index|]
return|;
block|}
comment|/// @brief create a mapping for the specifed virtual register to
comment|/// the next available stack slot
name|int
name|assignVirt2StackSlot
parameter_list|(
name|unsigned
name|virtReg
parameter_list|)
function_decl|;
comment|/// @brief create a mapping for the specified virtual register to
comment|/// the specified stack slot
name|void
name|assignVirt2StackSlot
parameter_list|(
name|unsigned
name|virtReg
parameter_list|,
name|int
name|frameIndex
parameter_list|)
function_decl|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|Module
operator|*
name|M
operator|=
name|nullptr
argument_list|)
decl|const
name|override
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|VirtRegMap
operator|&
name|VRM
operator|)
block|{
name|VRM
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

