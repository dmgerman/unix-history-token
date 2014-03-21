begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachineRegisterInfo.h ----------------------*- C++ -*-===//
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
comment|// This file defines the MachineRegisterInfo class.
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
name|LLVM_CODEGEN_MACHINEREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IndexedMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstrBundle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PSetIterator
decl_stmt|;
comment|/// MachineRegisterInfo - Keep track of information for virtual and physical
comment|/// registers, including vreg register classes, use/def chains for registers,
comment|/// etc.
name|class
name|MachineRegisterInfo
block|{
name|public
label|:
name|class
name|Delegate
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|virtual
name|void
name|MRI_NoteNewVirtualRegister
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
operator|~
name|Delegate
argument_list|()
block|{}
block|}
empty_stmt|;
name|private
label|:
specifier|const
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
name|Delegate
modifier|*
name|TheDelegate
decl_stmt|;
comment|/// IsSSA - True when the machine function is in SSA form and virtual
comment|/// registers have a single def.
name|bool
name|IsSSA
decl_stmt|;
comment|/// TracksLiveness - True while register liveness is being tracked accurately.
comment|/// Basic block live-in lists, kill flags, and implicit defs may not be
comment|/// accurate when after this flag is cleared.
name|bool
name|TracksLiveness
decl_stmt|;
comment|/// VRegInfo - Information we keep for each virtual register.
comment|///
comment|/// Each element in this list contains the register class of the vreg and the
comment|/// start of the use/def list for the register.
name|IndexedMap
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|TargetRegisterClass
operator|*
operator|,
name|MachineOperand
operator|*
operator|>
operator|,
name|VirtReg2IndexFunctor
operator|>
name|VRegInfo
expr_stmt|;
comment|/// RegAllocHints - This vector records register allocation hints for virtual
comment|/// registers. For each virtual register, it keeps a register and hint type
comment|/// pair making up the allocation hint. Hint type is target specific except
comment|/// for the value 0 which means the second value of the pair is the preferred
comment|/// register for allocation. For example, if the hint is<0, 1024>, it means
comment|/// the allocator should prefer the physical register allocated to the virtual
comment|/// register of the hint.
name|IndexedMap
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
operator|,
name|VirtReg2IndexFunctor
operator|>
name|RegAllocHints
expr_stmt|;
comment|/// PhysRegUseDefLists - This is an array of the head of the use/def list for
comment|/// physical registers.
name|MachineOperand
modifier|*
modifier|*
name|PhysRegUseDefLists
decl_stmt|;
comment|/// getRegUseDefListHead - Return the head pointer for the register use/def
comment|/// list for the specified virtual or physical register.
name|MachineOperand
modifier|*
modifier|&
name|getRegUseDefListHead
parameter_list|(
name|unsigned
name|RegNo
parameter_list|)
block|{
if|if
condition|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|RegNo
argument_list|)
condition|)
return|return
name|VRegInfo
index|[
name|RegNo
index|]
operator|.
name|second
return|;
return|return
name|PhysRegUseDefLists
index|[
name|RegNo
index|]
return|;
block|}
name|MachineOperand
modifier|*
name|getRegUseDefListHead
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
if|if
condition|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|RegNo
argument_list|)
condition|)
return|return
name|VRegInfo
index|[
name|RegNo
index|]
operator|.
name|second
return|;
return|return
name|PhysRegUseDefLists
index|[
name|RegNo
index|]
return|;
block|}
comment|/// Get the next element in the use-def chain.
specifier|static
name|MachineOperand
modifier|*
name|getNextOperandForReg
parameter_list|(
specifier|const
name|MachineOperand
modifier|*
name|MO
parameter_list|)
block|{
name|assert
argument_list|(
name|MO
operator|&&
name|MO
operator|->
name|isReg
argument_list|()
operator|&&
literal|"This is not a register operand!"
argument_list|)
expr_stmt|;
return|return
name|MO
operator|->
name|Contents
operator|.
name|Reg
operator|.
name|Next
return|;
block|}
comment|/// UsedRegUnits - This is a bit vector that is computed and set by the
comment|/// register allocator, and must be kept up to date by passes that run after
comment|/// register allocation (though most don't modify this).  This is used
comment|/// so that the code generator knows which callee save registers to save and
comment|/// for other target specific uses.
comment|/// This vector has bits set for register units that are modified in the
comment|/// current function. It doesn't include registers clobbered by function
comment|/// calls with register mask operands.
name|BitVector
name|UsedRegUnits
decl_stmt|;
comment|/// UsedPhysRegMask - Additional used physregs including aliases.
comment|/// This bit vector represents all the registers clobbered by function calls.
comment|/// It can model things that UsedRegUnits can't, such as function calls that
comment|/// clobber ymm7 but preserve the low half in xmm7.
name|BitVector
name|UsedPhysRegMask
decl_stmt|;
comment|/// ReservedRegs - This is a bit vector of reserved registers.  The target
comment|/// may change its mind about which registers should be reserved.  This
comment|/// vector is the frozen set of reserved registers when register allocation
comment|/// started.
name|BitVector
name|ReservedRegs
decl_stmt|;
comment|/// Keep track of the physical registers that are live in to the function.
comment|/// Live in values are typically arguments in registers.  LiveIn values are
comment|/// allowed to have virtual registers associated with them, stored in the
comment|/// second element.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
expr|>
name|LiveIns
expr_stmt|;
name|MachineRegisterInfo
argument_list|(
argument|const MachineRegisterInfo&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MachineRegisterInfo
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
name|explicit
name|MachineRegisterInfo
parameter_list|(
specifier|const
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
operator|~
name|MachineRegisterInfo
argument_list|()
expr_stmt|;
specifier|const
name|TargetRegisterInfo
operator|*
name|getTargetRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|TM
operator|.
name|getRegisterInfo
argument_list|()
return|;
block|}
name|void
name|resetDelegate
parameter_list|(
name|Delegate
modifier|*
name|delegate
parameter_list|)
block|{
comment|// Ensure another delegate does not take over unless the current
comment|// delegate first unattaches itself. If we ever need to multicast
comment|// notifications, we will need to change to using a list.
name|assert
argument_list|(
name|TheDelegate
operator|==
name|delegate
operator|&&
literal|"Only the current delegate can perform reset!"
argument_list|)
expr_stmt|;
name|TheDelegate
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|setDelegate
parameter_list|(
name|Delegate
modifier|*
name|delegate
parameter_list|)
block|{
name|assert
argument_list|(
name|delegate
operator|&&
operator|!
name|TheDelegate
operator|&&
literal|"Attempted to set delegate to null, or to change it without "
literal|"first resetting it!"
argument_list|)
expr_stmt|;
name|TheDelegate
operator|=
name|delegate
expr_stmt|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Function State
comment|//===--------------------------------------------------------------------===//
comment|// isSSA - Returns true when the machine function is in SSA form. Early
comment|// passes require the machine function to be in SSA form where every virtual
comment|// register has a single defining instruction.
comment|//
comment|// The TwoAddressInstructionPass and PHIElimination passes take the machine
comment|// function out of SSA form when they introduce multiple defs per virtual
comment|// register.
name|bool
name|isSSA
argument_list|()
specifier|const
block|{
return|return
name|IsSSA
return|;
block|}
comment|// leaveSSA - Indicates that the machine function is no longer in SSA form.
name|void
name|leaveSSA
parameter_list|()
block|{
name|IsSSA
operator|=
name|false
expr_stmt|;
block|}
comment|/// tracksLiveness - Returns true when tracking register liveness accurately.
comment|///
comment|/// While this flag is true, register liveness information in basic block
comment|/// live-in lists and machine instruction operands is accurate. This means it
comment|/// can be used to change the code in ways that affect the values in
comment|/// registers, for example by the register scavenger.
comment|///
comment|/// When this flag is false, liveness is no longer reliable.
name|bool
name|tracksLiveness
argument_list|()
specifier|const
block|{
return|return
name|TracksLiveness
return|;
block|}
comment|/// invalidateLiveness - Indicates that register liveness is no longer being
comment|/// tracked accurately.
comment|///
comment|/// This should be called by late passes that invalidate the liveness
comment|/// information.
name|void
name|invalidateLiveness
parameter_list|()
block|{
name|TracksLiveness
operator|=
name|false
expr_stmt|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Register Info
comment|//===--------------------------------------------------------------------===//
comment|// Strictly for use by MachineInstr.cpp.
name|void
name|addRegOperandToUseList
parameter_list|(
name|MachineOperand
modifier|*
name|MO
parameter_list|)
function_decl|;
comment|// Strictly for use by MachineInstr.cpp.
name|void
name|removeRegOperandFromUseList
parameter_list|(
name|MachineOperand
modifier|*
name|MO
parameter_list|)
function_decl|;
comment|// Strictly for use by MachineInstr.cpp.
name|void
name|moveOperands
parameter_list|(
name|MachineOperand
modifier|*
name|Dst
parameter_list|,
name|MachineOperand
modifier|*
name|Src
parameter_list|,
name|unsigned
name|NumOps
parameter_list|)
function_decl|;
comment|/// Verify the sanity of the use list for Reg.
name|void
name|verifyUseList
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
comment|/// Verify the use list of all registers.
name|void
name|verifyUseLists
argument_list|()
specifier|const
expr_stmt|;
comment|/// reg_begin/reg_end - Provide iteration support to walk over all definitions
comment|/// and uses of a register within the MachineFunction that corresponds to this
comment|/// MachineRegisterInfo object.
name|template
operator|<
name|bool
name|Uses
operator|,
name|bool
name|Defs
operator|,
name|bool
name|SkipDebug
operator|>
name|class
name|defusechain_iterator
expr_stmt|;
comment|// Make it a friend so it can access getNextOperandForReg().
name|template
operator|<
name|bool
operator|,
name|bool
operator|,
name|bool
operator|>
name|friend
name|class
name|defusechain_iterator
expr_stmt|;
comment|/// reg_iterator/reg_begin/reg_end - Walk all defs and uses of the specified
comment|/// register.
typedef|typedef
name|defusechain_iterator
operator|<
name|true
operator|,
name|true
operator|,
name|false
operator|>
name|reg_iterator
expr_stmt|;
name|reg_iterator
name|reg_begin
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|reg_iterator
argument_list|(
name|getRegUseDefListHead
argument_list|(
name|RegNo
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|reg_iterator
name|reg_end
parameter_list|()
block|{
return|return
name|reg_iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// reg_empty - Return true if there are no instructions using or defining the
comment|/// specified register (it may be live-in).
name|bool
name|reg_empty
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|reg_begin
argument_list|(
name|RegNo
argument_list|)
operator|==
name|reg_end
argument_list|()
return|;
block|}
comment|/// reg_nodbg_iterator/reg_nodbg_begin/reg_nodbg_end - Walk all defs and uses
comment|/// of the specified register, skipping those marked as Debug.
typedef|typedef
name|defusechain_iterator
operator|<
name|true
operator|,
name|true
operator|,
name|true
operator|>
name|reg_nodbg_iterator
expr_stmt|;
name|reg_nodbg_iterator
name|reg_nodbg_begin
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|reg_nodbg_iterator
argument_list|(
name|getRegUseDefListHead
argument_list|(
name|RegNo
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|reg_nodbg_iterator
name|reg_nodbg_end
parameter_list|()
block|{
return|return
name|reg_nodbg_iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// reg_nodbg_empty - Return true if the only instructions using or defining
comment|/// Reg are Debug instructions.
name|bool
name|reg_nodbg_empty
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|reg_nodbg_begin
argument_list|(
name|RegNo
argument_list|)
operator|==
name|reg_nodbg_end
argument_list|()
return|;
block|}
comment|/// def_iterator/def_begin/def_end - Walk all defs of the specified register.
typedef|typedef
name|defusechain_iterator
operator|<
name|false
operator|,
name|true
operator|,
name|false
operator|>
name|def_iterator
expr_stmt|;
name|def_iterator
name|def_begin
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|def_iterator
argument_list|(
name|getRegUseDefListHead
argument_list|(
name|RegNo
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|def_iterator
name|def_end
parameter_list|()
block|{
return|return
name|def_iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// def_empty - Return true if there are no instructions defining the
comment|/// specified register (it may be live-in).
name|bool
name|def_empty
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|def_begin
argument_list|(
name|RegNo
argument_list|)
operator|==
name|def_end
argument_list|()
return|;
block|}
comment|/// hasOneDef - Return true if there is exactly one instruction defining the
comment|/// specified register.
name|bool
name|hasOneDef
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
name|def_iterator
name|DI
init|=
name|def_begin
argument_list|(
name|RegNo
argument_list|)
decl_stmt|;
if|if
condition|(
name|DI
operator|==
name|def_end
argument_list|()
condition|)
return|return
name|false
return|;
return|return
operator|++
name|DI
operator|==
name|def_end
argument_list|()
return|;
block|}
comment|/// use_iterator/use_begin/use_end - Walk all uses of the specified register.
typedef|typedef
name|defusechain_iterator
operator|<
name|true
operator|,
name|false
operator|,
name|false
operator|>
name|use_iterator
expr_stmt|;
name|use_iterator
name|use_begin
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|use_iterator
argument_list|(
name|getRegUseDefListHead
argument_list|(
name|RegNo
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|use_iterator
name|use_end
parameter_list|()
block|{
return|return
name|use_iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// use_empty - Return true if there are no instructions using the specified
comment|/// register.
name|bool
name|use_empty
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|use_begin
argument_list|(
name|RegNo
argument_list|)
operator|==
name|use_end
argument_list|()
return|;
block|}
comment|/// hasOneUse - Return true if there is exactly one instruction using the
comment|/// specified register.
name|bool
name|hasOneUse
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
name|use_iterator
name|UI
init|=
name|use_begin
argument_list|(
name|RegNo
argument_list|)
decl_stmt|;
if|if
condition|(
name|UI
operator|==
name|use_end
argument_list|()
condition|)
return|return
name|false
return|;
return|return
operator|++
name|UI
operator|==
name|use_end
argument_list|()
return|;
block|}
comment|/// use_nodbg_iterator/use_nodbg_begin/use_nodbg_end - Walk all uses of the
comment|/// specified register, skipping those marked as Debug.
typedef|typedef
name|defusechain_iterator
operator|<
name|true
operator|,
name|false
operator|,
name|true
operator|>
name|use_nodbg_iterator
expr_stmt|;
name|use_nodbg_iterator
name|use_nodbg_begin
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|use_nodbg_iterator
argument_list|(
name|getRegUseDefListHead
argument_list|(
name|RegNo
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|use_nodbg_iterator
name|use_nodbg_end
parameter_list|()
block|{
return|return
name|use_nodbg_iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// use_nodbg_empty - Return true if there are no non-Debug instructions
comment|/// using the specified register.
name|bool
name|use_nodbg_empty
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|use_nodbg_begin
argument_list|(
name|RegNo
argument_list|)
operator|==
name|use_nodbg_end
argument_list|()
return|;
block|}
comment|/// hasOneNonDBGUse - Return true if there is exactly one non-Debug
comment|/// instruction using the specified register.
name|bool
name|hasOneNonDBGUse
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
decl_stmt|;
comment|/// replaceRegWith - Replace all instances of FromReg with ToReg in the
comment|/// machine function.  This is like llvm-level X->replaceAllUsesWith(Y),
comment|/// except that it also changes any definitions of the register as well.
comment|///
comment|/// Note that it is usually necessary to first constrain ToReg's register
comment|/// class to match the FromReg constraints using:
comment|///
comment|///   constrainRegClass(ToReg, getRegClass(FromReg))
comment|///
comment|/// That function will return NULL if the virtual registers have incompatible
comment|/// constraints.
name|void
name|replaceRegWith
parameter_list|(
name|unsigned
name|FromReg
parameter_list|,
name|unsigned
name|ToReg
parameter_list|)
function_decl|;
comment|/// getVRegDef - Return the machine instr that defines the specified virtual
comment|/// register or null if none is found.  This assumes that the code is in SSA
comment|/// form, so there should only be one definition.
name|MachineInstr
modifier|*
name|getVRegDef
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
comment|/// getUniqueVRegDef - Return the unique machine instr that defines the
comment|/// specified virtual register or null if none is found.  If there are
comment|/// multiple definitions or no definition, return null.
name|MachineInstr
modifier|*
name|getUniqueVRegDef
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
comment|/// clearKillFlags - Iterate over all the uses of the given register and
comment|/// clear the kill flag from the MachineOperand. This function is used by
comment|/// optimization passes which extend register lifetimes and need only
comment|/// preserve conservative kill flag information.
name|void
name|clearKillFlags
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|dumpUses
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
comment|/// isConstantPhysReg - Returns true if PhysReg is unallocatable and constant
comment|/// throughout the function.  It is safe to move instructions that read such
comment|/// a physreg.
name|bool
name|isConstantPhysReg
argument_list|(
name|unsigned
name|PhysReg
argument_list|,
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
comment|/// Get an iterator over the pressure sets affected by the given physical or
comment|/// virtual register. If RegUnit is physical, it must be a register unit (from
comment|/// MCRegUnitIterator).
name|PSetIterator
name|getPressureSets
argument_list|(
name|unsigned
name|RegUnit
argument_list|)
decl|const
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Virtual Register Info
comment|//===--------------------------------------------------------------------===//
comment|/// getRegClass - Return the register class of the specified virtual register.
comment|///
specifier|const
name|TargetRegisterClass
modifier|*
name|getRegClass
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
return|return
name|VRegInfo
index|[
name|Reg
index|]
operator|.
name|first
return|;
block|}
comment|/// setRegClass - Set the register class of the specified virtual register.
comment|///
name|void
name|setRegClass
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|)
function_decl|;
comment|/// constrainRegClass - Constrain the register class of the specified virtual
comment|/// register to be a common subclass of RC and the current register class,
comment|/// but only if the new class has at least MinNumRegs registers.  Return the
comment|/// new register class, or NULL if no such class exists.
comment|/// This should only be used when the constraint is known to be trivial, like
comment|/// GR32 -> GR32_NOSP. Beware of increasing register pressure.
comment|///
specifier|const
name|TargetRegisterClass
modifier|*
name|constrainRegClass
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|,
name|unsigned
name|MinNumRegs
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// recomputeRegClass - Try to find a legal super-class of Reg's register
comment|/// class that still satisfies the constraints from the instructions using
comment|/// Reg.  Returns true if Reg was upgraded.
comment|///
comment|/// This method can be used after constraints have been removed from a
comment|/// virtual register, for example after removing instructions or splitting
comment|/// the live range.
comment|///
name|bool
name|recomputeRegClass
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|TargetMachine
modifier|&
parameter_list|)
function_decl|;
comment|/// createVirtualRegister - Create and return a new virtual register in the
comment|/// function with the specified register class.
comment|///
name|unsigned
name|createVirtualRegister
parameter_list|(
specifier|const
name|TargetRegisterClass
modifier|*
name|RegClass
parameter_list|)
function_decl|;
comment|/// getNumVirtRegs - Return the number of virtual registers created.
comment|///
name|unsigned
name|getNumVirtRegs
argument_list|()
specifier|const
block|{
return|return
name|VRegInfo
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// clearVirtRegs - Remove all virtual registers (after physreg assignment).
name|void
name|clearVirtRegs
parameter_list|()
function_decl|;
comment|/// setRegAllocationHint - Specify a register allocation hint for the
comment|/// specified virtual register.
name|void
name|setRegAllocationHint
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|PrefReg
parameter_list|)
block|{
name|RegAllocHints
index|[
name|Reg
index|]
operator|.
name|first
operator|=
name|Type
expr_stmt|;
name|RegAllocHints
index|[
name|Reg
index|]
operator|.
name|second
operator|=
name|PrefReg
expr_stmt|;
block|}
comment|/// getRegAllocationHint - Return the register allocation hint for the
comment|/// specified virtual register.
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|getRegAllocationHint
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|{
return|return
name|RegAllocHints
index|[
name|Reg
index|]
return|;
block|}
comment|/// getSimpleHint - Return the preferred register allocation hint, or 0 if a
comment|/// standard simple hint (Type == 0) is not set.
name|unsigned
name|getSimpleHint
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|Hint
operator|=
name|getRegAllocationHint
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
return|return
name|Hint
operator|.
name|first
condition|?
literal|0
else|:
name|Hint
operator|.
name|second
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Physical Register Use Info
comment|//===--------------------------------------------------------------------===//
comment|/// isPhysRegUsed - Return true if the specified register is used in this
comment|/// function. Also check for clobbered aliases and registers clobbered by
comment|/// function calls with register mask operands.
comment|///
comment|/// This only works after register allocation. It is primarily used by
comment|/// PrologEpilogInserter to determine which callee-saved registers need
comment|/// spilling.
name|bool
name|isPhysRegUsed
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
if|if
condition|(
name|UsedPhysRegMask
operator|.
name|test
argument_list|(
name|Reg
argument_list|)
condition|)
return|return
name|true
return|;
for|for
control|(
name|MCRegUnitIterator
name|Units
argument_list|(
name|Reg
argument_list|,
name|getTargetRegisterInfo
argument_list|()
argument_list|)
init|;
name|Units
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|Units
control|)
if|if
condition|(
name|UsedRegUnits
operator|.
name|test
argument_list|(
operator|*
name|Units
argument_list|)
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|/// Mark the specified register unit as used in this function.
comment|/// This should only be called during and after register allocation.
name|void
name|setRegUnitUsed
parameter_list|(
name|unsigned
name|RegUnit
parameter_list|)
block|{
name|UsedRegUnits
operator|.
name|set
argument_list|(
name|RegUnit
argument_list|)
expr_stmt|;
block|}
comment|/// setPhysRegUsed - Mark the specified register used in this function.
comment|/// This should only be called during and after register allocation.
name|void
name|setPhysRegUsed
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
for|for
control|(
name|MCRegUnitIterator
name|Units
argument_list|(
name|Reg
argument_list|,
name|getTargetRegisterInfo
argument_list|()
argument_list|)
init|;
name|Units
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|Units
control|)
name|UsedRegUnits
operator|.
name|set
argument_list|(
operator|*
name|Units
argument_list|)
expr_stmt|;
block|}
comment|/// addPhysRegsUsedFromRegMask - Mark any registers not in RegMask as used.
comment|/// This corresponds to the bit mask attached to register mask operands.
name|void
name|addPhysRegsUsedFromRegMask
parameter_list|(
specifier|const
name|uint32_t
modifier|*
name|RegMask
parameter_list|)
block|{
name|UsedPhysRegMask
operator|.
name|setBitsNotInMask
argument_list|(
name|RegMask
argument_list|)
expr_stmt|;
block|}
comment|/// setPhysRegUnused - Mark the specified register unused in this function.
comment|/// This should only be called during and after register allocation.
name|void
name|setPhysRegUnused
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|UsedPhysRegMask
operator|.
name|reset
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
for|for
control|(
name|MCRegUnitIterator
name|Units
argument_list|(
name|Reg
argument_list|,
name|getTargetRegisterInfo
argument_list|()
argument_list|)
init|;
name|Units
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|Units
control|)
name|UsedRegUnits
operator|.
name|reset
argument_list|(
operator|*
name|Units
argument_list|)
expr_stmt|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Reserved Register Info
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// The set of reserved registers must be invariant during register
comment|// allocation.  For example, the target cannot suddenly decide it needs a
comment|// frame pointer when the register allocator has already used the frame
comment|// pointer register for something else.
comment|//
comment|// These methods can be used by target hooks like hasFP() to avoid changing
comment|// the reserved register set during register allocation.
comment|/// freezeReservedRegs - Called by the register allocator to freeze the set
comment|/// of reserved registers before allocation begins.
name|void
name|freezeReservedRegs
parameter_list|(
specifier|const
name|MachineFunction
modifier|&
parameter_list|)
function_decl|;
comment|/// reservedRegsFrozen - Returns true after freezeReservedRegs() was called
comment|/// to ensure the set of reserved registers stays constant.
name|bool
name|reservedRegsFrozen
argument_list|()
specifier|const
block|{
return|return
operator|!
name|ReservedRegs
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// canReserveReg - Returns true if PhysReg can be used as a reserved
comment|/// register.  Any register can be reserved before freezeReservedRegs() is
comment|/// called.
name|bool
name|canReserveReg
argument_list|(
name|unsigned
name|PhysReg
argument_list|)
decl|const
block|{
return|return
operator|!
name|reservedRegsFrozen
argument_list|()
operator|||
name|ReservedRegs
operator|.
name|test
argument_list|(
name|PhysReg
argument_list|)
return|;
block|}
comment|/// getReservedRegs - Returns a reference to the frozen set of reserved
comment|/// registers. This method should always be preferred to calling
comment|/// TRI::getReservedRegs() when possible.
specifier|const
name|BitVector
operator|&
name|getReservedRegs
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|reservedRegsFrozen
argument_list|()
operator|&&
literal|"Reserved registers haven't been frozen yet. "
literal|"Use TRI::getReservedRegs()."
argument_list|)
block|;
return|return
name|ReservedRegs
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
name|getReservedRegs
argument_list|()
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
name|getTargetRegisterInfo
argument_list|()
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
comment|//===--------------------------------------------------------------------===//
comment|// LiveIn Management
comment|//===--------------------------------------------------------------------===//
comment|/// addLiveIn - Add the specified register as a live-in.  Note that it
comment|/// is an error to add the same register to the same set more than once.
name|void
name|addLiveIn
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|unsigned
name|vreg
init|=
literal|0
parameter_list|)
block|{
name|LiveIns
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Reg
argument_list|,
name|vreg
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Iteration support for the live-ins set.  It's kept in sorted order
comment|// by register number.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
expr|>
operator|::
name|const_iterator
name|livein_iterator
expr_stmt|;
name|livein_iterator
name|livein_begin
argument_list|()
specifier|const
block|{
return|return
name|LiveIns
operator|.
name|begin
argument_list|()
return|;
block|}
name|livein_iterator
name|livein_end
argument_list|()
specifier|const
block|{
return|return
name|LiveIns
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|livein_empty
argument_list|()
specifier|const
block|{
return|return
name|LiveIns
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|isLiveIn
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
comment|/// getLiveInPhysReg - If VReg is a live-in virtual register, return the
comment|/// corresponding live-in physical register.
name|unsigned
name|getLiveInPhysReg
argument_list|(
name|unsigned
name|VReg
argument_list|)
decl|const
decl_stmt|;
comment|/// getLiveInVirtReg - If PReg is a live-in physical register, return the
comment|/// corresponding live-in physical register.
name|unsigned
name|getLiveInVirtReg
argument_list|(
name|unsigned
name|PReg
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitLiveInCopies - Emit copies to initialize livein virtual registers
comment|/// into the given entry block.
name|void
name|EmitLiveInCopies
parameter_list|(
name|MachineBasicBlock
modifier|*
name|EntryMBB
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
parameter_list|,
specifier|const
name|TargetInstrInfo
modifier|&
name|TII
parameter_list|)
function_decl|;
comment|/// defusechain_iterator - This class provides iterator support for machine
comment|/// operands in the function that use or define a specific register.  If
comment|/// ReturnUses is true it returns uses of registers, if ReturnDefs is true it
comment|/// returns defs.  If neither are true then you are silly and it always
comment|/// returns end().  If SkipDebug is true it skips uses marked Debug
comment|/// when incrementing.
name|template
operator|<
name|bool
name|ReturnUses
operator|,
name|bool
name|ReturnDefs
operator|,
name|bool
name|SkipDebug
operator|>
name|class
name|defusechain_iterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|MachineInstr
operator|,
name|ptrdiff_t
operator|>
block|{
name|MachineOperand
operator|*
name|Op
block|;
name|explicit
name|defusechain_iterator
argument_list|(
name|MachineOperand
operator|*
name|op
argument_list|)
operator|:
name|Op
argument_list|(
argument|op
argument_list|)
block|{
comment|// If the first node isn't one we're interested in, advance to one that
comment|// we are interested in.
if|if
condition|(
name|op
condition|)
block|{
if|if
condition|(
operator|(
operator|!
name|ReturnUses
operator|&&
name|op
operator|->
name|isUse
argument_list|()
operator|)
operator|||
operator|(
operator|!
name|ReturnDefs
operator|&&
name|op
operator|->
name|isDef
argument_list|()
operator|)
operator|||
operator|(
name|SkipDebug
operator|&&
name|op
operator|->
name|isDebug
argument_list|()
operator|)
condition|)
operator|++
operator|*
name|this
expr_stmt|;
block|}
block|}
name|friend
name|class
name|MachineRegisterInfo
block|;
name|public
operator|:
typedef|typedef
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|MachineInstr
operator|,
name|ptrdiff_t
operator|>
operator|::
name|reference
name|reference
expr_stmt|;
typedef|typedef
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|MachineInstr
operator|,
name|ptrdiff_t
operator|>
operator|::
name|pointer
name|pointer
expr_stmt|;
name|defusechain_iterator
argument_list|(
specifier|const
name|defusechain_iterator
operator|&
name|I
argument_list|)
operator|:
name|Op
argument_list|(
argument|I.Op
argument_list|)
block|{}
name|defusechain_iterator
argument_list|()
operator|:
name|Op
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|defusechain_iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|Op
operator|==
name|x
operator|.
name|Op
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|defusechain_iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
comment|/// atEnd - return true if this iterator is equal to reg_end() on the value.
name|bool
name|atEnd
argument_list|()
specifier|const
block|{
return|return
name|Op
operator|==
literal|0
return|;
block|}
comment|// Iterator traversal: forward iteration only
name|defusechain_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|assert
argument_list|(
name|Op
operator|&&
literal|"Cannot increment end iterator!"
argument_list|)
block|;
name|Op
operator|=
name|getNextOperandForReg
argument_list|(
name|Op
argument_list|)
block|;
comment|// All defs come before the uses, so stop def_iterator early.
if|if
condition|(
operator|!
name|ReturnUses
condition|)
block|{
if|if
condition|(
name|Op
condition|)
block|{
if|if
condition|(
name|Op
operator|->
name|isUse
argument_list|()
condition|)
name|Op
operator|=
literal|0
expr_stmt|;
else|else
name|assert
argument_list|(
operator|!
name|Op
operator|->
name|isDebug
argument_list|()
operator|&&
literal|"Can't have debug defs"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// If this is an operand we don't care about, skip it.
while|while
condition|(
name|Op
operator|&&
operator|(
operator|(
operator|!
name|ReturnDefs
operator|&&
name|Op
operator|->
name|isDef
argument_list|()
operator|)
operator|||
operator|(
name|SkipDebug
operator|&&
name|Op
operator|->
name|isDebug
argument_list|()
operator|)
operator|)
condition|)
name|Op
operator|=
name|getNextOperandForReg
argument_list|(
name|Op
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
name|defusechain_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|defusechain_iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
comment|/// skipInstruction - move forward until reaching a different instruction.
comment|/// Return the skipped instruction that is no longer pointed to, or NULL if
comment|/// already pointing to end().
name|MachineInstr
modifier|*
name|skipInstruction
parameter_list|()
block|{
if|if
condition|(
operator|!
name|Op
condition|)
return|return
literal|0
return|;
name|MachineInstr
modifier|*
name|MI
init|=
name|Op
operator|->
name|getParent
argument_list|()
decl_stmt|;
do|do
operator|++
operator|*
name|this
expr_stmt|;
do|while
condition|(
name|Op
operator|&&
name|Op
operator|->
name|getParent
argument_list|()
operator|==
name|MI
condition|)
do|;
return|return
name|MI
return|;
block|}
name|MachineInstr
modifier|*
name|skipBundle
parameter_list|()
block|{
if|if
condition|(
operator|!
name|Op
condition|)
return|return
literal|0
return|;
name|MachineInstr
modifier|*
name|MI
init|=
name|getBundleStart
argument_list|(
name|Op
operator|->
name|getParent
argument_list|()
argument_list|)
decl_stmt|;
do|do
operator|++
operator|*
name|this
expr_stmt|;
do|while
condition|(
name|Op
operator|&&
name|getBundleStart
argument_list|(
name|Op
operator|->
name|getParent
argument_list|()
argument_list|)
operator|==
name|MI
condition|)
do|;
return|return
name|MI
return|;
block|}
name|MachineOperand
operator|&
name|getOperand
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Op
operator|&&
literal|"Cannot dereference end iterator!"
argument_list|)
block|;
return|return
operator|*
name|Op
return|;
block|}
comment|/// getOperandNo - Return the operand # of this MachineOperand in its
comment|/// MachineInstr.
name|unsigned
name|getOperandNo
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Op
operator|&&
literal|"Cannot dereference end iterator!"
argument_list|)
block|;
return|return
name|Op
operator|-
operator|&
name|Op
operator|->
name|getParent
argument_list|()
operator|->
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|// Retrieve a reference to the current operand.
name|MachineInstr
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Op
operator|&&
literal|"Cannot dereference end iterator!"
argument_list|)
block|;
return|return
operator|*
name|Op
operator|->
name|getParent
argument_list|()
return|;
block|}
name|MachineInstr
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
name|assert
argument_list|(
name|Op
operator|&&
literal|"Cannot dereference end iterator!"
argument_list|)
expr_stmt|;
return|return
name|Op
operator|->
name|getParent
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|};
comment|/// Iterate over the pressure sets affected by the given physical or virtual
end_comment

begin_comment
comment|/// register. If Reg is physical, it must be a register unit (from
end_comment

begin_comment
comment|/// MCRegUnitIterator).
end_comment

begin_decl_stmt
name|class
name|PSetIterator
block|{
specifier|const
name|int
modifier|*
name|PSet
decl_stmt|;
name|unsigned
name|Weight
decl_stmt|;
name|public
label|:
name|PSetIterator
argument_list|()
operator|:
name|PSet
argument_list|(
literal|0
argument_list|)
operator|,
name|Weight
argument_list|(
literal|0
argument_list|)
block|{}
name|PSetIterator
argument_list|(
argument|unsigned RegUnit
argument_list|,
argument|const MachineRegisterInfo *MRI
argument_list|)
block|{
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|MRI
operator|->
name|getTargetRegisterInfo
argument_list|()
block|;
if|if
condition|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|RegUnit
argument_list|)
condition|)
block|{
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
init|=
name|MRI
operator|->
name|getRegClass
argument_list|(
name|RegUnit
argument_list|)
decl_stmt|;
name|PSet
operator|=
name|TRI
operator|->
name|getRegClassPressureSets
argument_list|(
name|RC
argument_list|)
expr_stmt|;
name|Weight
operator|=
name|TRI
operator|->
name|getRegClassWeight
argument_list|(
name|RC
argument_list|)
operator|.
name|RegWeight
expr_stmt|;
block|}
else|else
block|{
name|PSet
operator|=
name|TRI
operator|->
name|getRegUnitPressureSets
argument_list|(
name|RegUnit
argument_list|)
expr_stmt|;
name|Weight
operator|=
name|TRI
operator|->
name|getRegUnitWeight
argument_list|(
name|RegUnit
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|PSet
operator|==
operator|-
literal|1
condition|)
name|PSet
operator|=
literal|0
expr_stmt|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|PSet
return|;
block|}
name|unsigned
name|getWeight
argument_list|()
specifier|const
block|{
return|return
name|Weight
return|;
block|}
name|unsigned
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|PSet
return|;
block|}
name|void
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Invalid PSetIterator."
argument_list|)
block|;
operator|++
name|PSet
block|;
if|if
condition|(
operator|*
name|PSet
operator|==
operator|-
literal|1
condition|)
name|PSet
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|PSetIterator
name|MachineRegisterInfo
operator|::
name|getPressureSets
argument_list|(
argument|unsigned RegUnit
argument_list|)
specifier|const
block|{
return|return
name|PSetIterator
argument_list|(
name|RegUnit
argument_list|,
name|this
argument_list|)
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

