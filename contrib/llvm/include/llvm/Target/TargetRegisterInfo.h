begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== Target/TargetRegisterInfo.h - Target Register Information -*- C++ -*-===//
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
comment|// This file describes an abstract interface used to get information about a
end_comment

begin_comment
comment|// target machines register file.  This information is used for a variety of
end_comment

begin_comment
comment|// purposed, especially register allocation.
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
name|LLVM_TARGET_TARGETREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BitVector
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|RegScavenger
decl_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|TargetRegisterClass
block|{
name|public
label|:
typedef|typedef
specifier|const
name|uint16_t
modifier|*
name|iterator
typedef|;
typedef|typedef
specifier|const
name|uint16_t
modifier|*
name|const_iterator
typedef|;
typedef|typedef
specifier|const
name|MVT
operator|::
name|SimpleValueType
operator|*
name|vt_iterator
expr_stmt|;
typedef|typedef
specifier|const
name|TargetRegisterClass
modifier|*
specifier|const
modifier|*
name|sc_iterator
typedef|;
comment|// Instance variables filled by tablegen, do not use!
specifier|const
name|MCRegisterClass
modifier|*
name|MC
decl_stmt|;
specifier|const
name|vt_iterator
name|VTs
decl_stmt|;
specifier|const
name|unsigned
modifier|*
name|SubClassMask
decl_stmt|;
specifier|const
name|sc_iterator
name|SuperClasses
decl_stmt|;
specifier|const
name|sc_iterator
name|SuperRegClasses
decl_stmt|;
name|ArrayRef
operator|<
name|uint16_t
operator|>
call|(
modifier|*
name|OrderFunc
call|)
argument_list|(
specifier|const
name|MachineFunction
operator|&
argument_list|)
expr_stmt|;
comment|/// getID() - Return the register class ID number.
comment|///
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|MC
operator|->
name|getID
argument_list|()
return|;
block|}
comment|/// getName() - Return the register class name for debugging.
comment|///
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|MC
operator|->
name|getName
argument_list|()
return|;
block|}
comment|/// begin/end - Return all of the registers in this class.
comment|///
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|MC
operator|->
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|MC
operator|->
name|end
argument_list|()
return|;
block|}
comment|/// getNumRegs - Return the number of registers in this class.
comment|///
name|unsigned
name|getNumRegs
argument_list|()
specifier|const
block|{
return|return
name|MC
operator|->
name|getNumRegs
argument_list|()
return|;
block|}
comment|/// getRegister - Return the specified register in the class.
comment|///
name|unsigned
name|getRegister
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
return|return
name|MC
operator|->
name|getRegister
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// contains - Return true if the specified register is included in this
comment|/// register class.  This does not include virtual registers.
name|bool
name|contains
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
return|return
name|MC
operator|->
name|contains
argument_list|(
name|Reg
argument_list|)
return|;
block|}
comment|/// contains - Return true if both registers are in this class.
name|bool
name|contains
argument_list|(
name|unsigned
name|Reg1
argument_list|,
name|unsigned
name|Reg2
argument_list|)
decl|const
block|{
return|return
name|MC
operator|->
name|contains
argument_list|(
name|Reg1
argument_list|,
name|Reg2
argument_list|)
return|;
block|}
comment|/// getSize - Return the size of the register in bytes, which is also the size
comment|/// of a stack slot allocated to hold a spilled copy of this register.
name|unsigned
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|MC
operator|->
name|getSize
argument_list|()
return|;
block|}
comment|/// getAlignment - Return the minimum required alignment for a register of
comment|/// this class.
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|MC
operator|->
name|getAlignment
argument_list|()
return|;
block|}
comment|/// getCopyCost - Return the cost of copying a value between two registers in
comment|/// this class. A negative number means the register class is very expensive
comment|/// to copy e.g. status flag register classes.
name|int
name|getCopyCost
argument_list|()
specifier|const
block|{
return|return
name|MC
operator|->
name|getCopyCost
argument_list|()
return|;
block|}
comment|/// isAllocatable - Return true if this register class may be used to create
comment|/// virtual registers.
name|bool
name|isAllocatable
argument_list|()
specifier|const
block|{
return|return
name|MC
operator|->
name|isAllocatable
argument_list|()
return|;
block|}
comment|/// hasType - return true if this TargetRegisterClass has the ValueType vt.
comment|///
name|bool
name|hasType
argument_list|(
name|EVT
name|vt
argument_list|)
decl|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|VTs
index|[
name|i
index|]
operator|!=
name|MVT
operator|::
name|Other
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|EVT
argument_list|(
name|VTs
index|[
name|i
index|]
argument_list|)
operator|==
name|vt
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|/// vt_begin / vt_end - Loop over all of the value types that can be
comment|/// represented by values in this register class.
name|vt_iterator
name|vt_begin
argument_list|()
specifier|const
block|{
return|return
name|VTs
return|;
block|}
name|vt_iterator
name|vt_end
argument_list|()
specifier|const
block|{
name|vt_iterator
name|I
operator|=
name|VTs
block|;
while|while
condition|(
operator|*
name|I
operator|!=
name|MVT
operator|::
name|Other
condition|)
operator|++
name|I
expr_stmt|;
return|return
name|I
return|;
block|}
comment|/// superregclasses_begin / superregclasses_end - Loop over all of
comment|/// the superreg register classes of this register class.
name|sc_iterator
name|superregclasses_begin
argument_list|()
specifier|const
block|{
return|return
name|SuperRegClasses
return|;
block|}
name|sc_iterator
name|superregclasses_end
argument_list|()
specifier|const
block|{
name|sc_iterator
name|I
operator|=
name|SuperRegClasses
block|;
while|while
condition|(
operator|*
name|I
operator|!=
name|NULL
condition|)
operator|++
name|I
expr_stmt|;
return|return
name|I
return|;
block|}
end_decl_stmt

begin_comment
comment|/// hasSubClass - return true if the specified TargetRegisterClass
end_comment

begin_comment
comment|/// is a proper sub-class of this TargetRegisterClass.
end_comment

begin_decl_stmt
name|bool
name|hasSubClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
return|return
name|RC
operator|!=
name|this
operator|&&
name|hasSubClassEq
argument_list|(
name|RC
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// hasSubClassEq - Returns true if RC is a sub-class of or equal to this
end_comment

begin_comment
comment|/// class.
end_comment

begin_decl_stmt
name|bool
name|hasSubClassEq
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
name|unsigned
name|ID
init|=
name|RC
operator|->
name|getID
argument_list|()
decl_stmt|;
return|return
operator|(
name|SubClassMask
index|[
name|ID
operator|/
literal|32
index|]
operator|>>
operator|(
name|ID
operator|%
literal|32
operator|)
operator|)
operator|&
literal|1
return|;
block|}
end_decl_stmt

begin_comment
comment|/// hasSuperClass - return true if the specified TargetRegisterClass is a
end_comment

begin_comment
comment|/// proper super-class of this TargetRegisterClass.
end_comment

begin_decl_stmt
name|bool
name|hasSuperClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
return|return
name|RC
operator|->
name|hasSubClass
argument_list|(
name|this
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// hasSuperClassEq - Returns true if RC is a super-class of or equal to this
end_comment

begin_comment
comment|/// class.
end_comment

begin_decl_stmt
name|bool
name|hasSuperClassEq
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
return|return
name|RC
operator|->
name|hasSubClassEq
argument_list|(
name|this
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getSubClassMask - Returns a bit vector of subclasses, including this one.
end_comment

begin_comment
comment|/// The vector is indexed by class IDs, see hasSubClassEq() above for how to
end_comment

begin_comment
comment|/// use it.
end_comment

begin_expr_stmt
specifier|const
name|uint32_t
operator|*
name|getSubClassMask
argument_list|()
specifier|const
block|{
return|return
name|SubClassMask
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getSuperClasses - Returns a NULL terminated list of super-classes.  The
end_comment

begin_comment
comment|/// classes are ordered by ID which is also a topological ordering from large
end_comment

begin_comment
comment|/// to small classes.  The list does NOT include the current class.
end_comment

begin_expr_stmt
name|sc_iterator
name|getSuperClasses
argument_list|()
specifier|const
block|{
return|return
name|SuperClasses
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isASubClass - return true if this TargetRegisterClass is a subset
end_comment

begin_comment
comment|/// class of at least one other TargetRegisterClass.
end_comment

begin_expr_stmt
name|bool
name|isASubClass
argument_list|()
specifier|const
block|{
return|return
name|SuperClasses
index|[
literal|0
index|]
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getRawAllocationOrder - Returns the preferred order for allocating
end_comment

begin_comment
comment|/// registers from this register class in MF. The raw order comes directly
end_comment

begin_comment
comment|/// from the .td file and may include reserved registers that are not
end_comment

begin_comment
comment|/// allocatable. Register allocators should also make sure to allocate
end_comment

begin_comment
comment|/// callee-saved registers only after all the volatiles are used. The
end_comment

begin_comment
comment|/// RegisterClassInfo class provides filtered allocation orders with
end_comment

begin_comment
comment|/// callee-saved registers moved to the end.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The MachineFunction argument can be used to tune the allocatable
end_comment

begin_comment
comment|/// registers based on the characteristics of the function, subtarget, or
end_comment

begin_comment
comment|/// other criteria.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// By default, this method returns all registers in the class.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|ArrayRef
operator|<
name|uint16_t
operator|>
name|getRawAllocationOrder
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|{
return|return
name|OrderFunc
operator|?
name|OrderFunc
argument_list|(
name|MF
argument_list|)
operator|:
name|makeArrayRef
argument_list|(
name|begin
argument_list|()
argument_list|,
name|getNumRegs
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// TargetRegisterInfoDesc - Extra information, not in MCRegisterDesc, about
end_comment

begin_comment
comment|/// registers. These are used by codegen, not by MC.
end_comment

begin_struct
struct|struct
name|TargetRegisterInfoDesc
block|{
name|unsigned
name|CostPerUse
decl_stmt|;
comment|// Extra cost of instructions using register.
name|bool
name|inAllocatableClass
decl_stmt|;
comment|// Register belongs to an allocatable regclass.
block|}
struct|;
end_struct

begin_comment
comment|/// Each TargetRegisterClass has a per register weight, and weight
end_comment

begin_comment
comment|/// limit which must be less than the limits of its pressure sets.
end_comment

begin_struct
struct|struct
name|RegClassWeight
block|{
name|unsigned
name|RegWeight
decl_stmt|;
name|unsigned
name|WeightLimit
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// TargetRegisterInfo base class - We assume that the target defines a static
end_comment

begin_comment
comment|/// array of TargetRegisterDesc objects that represent all of the machine
end_comment

begin_comment
comment|/// registers that the target has.  As such, we simply have to track a pointer
end_comment

begin_comment
comment|/// to this array so that we can turn register number into a register
end_comment

begin_comment
comment|/// descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|TargetRegisterInfo
range|:
name|public
name|MCRegisterInfo
block|{
name|public
operator|:
typedef|typedef
specifier|const
name|TargetRegisterClass
modifier|*
specifier|const
modifier|*
name|regclass_iterator
typedef|;
name|private
operator|:
specifier|const
name|TargetRegisterInfoDesc
operator|*
name|InfoDesc
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Extra desc array for codegen
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|SubRegIndexNames
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Names of subreg indexes.
end_comment

begin_decl_stmt
name|regclass_iterator
name|RegClassBegin
decl_stmt|,
name|RegClassEnd
decl_stmt|;
end_decl_stmt

begin_comment
comment|// List of regclasses
end_comment

begin_label
name|protected
label|:
end_label

begin_macro
name|TargetRegisterInfo
argument_list|(
argument|const TargetRegisterInfoDesc *ID
argument_list|,
argument|regclass_iterator RegClassBegin
argument_list|,
argument|regclass_iterator RegClassEnd
argument_list|,
argument|const char *const *subregindexnames
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|virtual
operator|~
name|TargetRegisterInfo
argument_list|()
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// Register numbers can represent physical registers, virtual registers, and
end_comment

begin_comment
comment|// sometimes stack slots. The unsigned values are divided into these ranges:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   0           Not a register, can be used as a sentinel.
end_comment

begin_comment
comment|//   [1;2^30)    Physical registers assigned by TableGen.
end_comment

begin_comment
comment|//   [2^30;2^31) Stack slots. (Rarely used.)
end_comment

begin_comment
comment|//   [2^31;2^32) Virtual registers assigned by MachineRegisterInfo.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Further sentinels can be allocated from the small negative integers.
end_comment

begin_comment
comment|// DenseMapInfo<unsigned> uses -1u and -2u.
end_comment

begin_comment
comment|/// isStackSlot - Sometimes it is useful the be able to store a non-negative
end_comment

begin_comment
comment|/// frame index in a variable that normally holds a register. isStackSlot()
end_comment

begin_comment
comment|/// returns true if Reg is in the range used for stack slots.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that isVirtualRegister() and isPhysicalRegister() cannot handle stack
end_comment

begin_comment
comment|/// slots, so if a variable may contains a stack slot, always check
end_comment

begin_comment
comment|/// isStackSlot() first.
end_comment

begin_comment
comment|///
end_comment

begin_function
specifier|static
name|bool
name|isStackSlot
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
return|return
name|int
argument_list|(
name|Reg
argument_list|)
operator|>=
operator|(
literal|1
operator|<<
literal|30
operator|)
return|;
block|}
end_function

begin_comment
comment|/// stackSlot2Index - Compute the frame index from a register value
end_comment

begin_comment
comment|/// representing a stack slot.
end_comment

begin_function
specifier|static
name|int
name|stackSlot2Index
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|assert
argument_list|(
name|isStackSlot
argument_list|(
name|Reg
argument_list|)
operator|&&
literal|"Not a stack slot"
argument_list|)
expr_stmt|;
return|return
name|int
argument_list|(
name|Reg
operator|-
operator|(
literal|1u
operator|<<
literal|30
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// index2StackSlot - Convert a non-negative frame index to a stack slot
end_comment

begin_comment
comment|/// register value.
end_comment

begin_function
specifier|static
name|unsigned
name|index2StackSlot
parameter_list|(
name|int
name|FI
parameter_list|)
block|{
name|assert
argument_list|(
name|FI
operator|>=
literal|0
operator|&&
literal|"Cannot hold a negative frame index."
argument_list|)
expr_stmt|;
return|return
name|FI
operator|+
operator|(
literal|1u
operator|<<
literal|30
operator|)
return|;
block|}
end_function

begin_comment
comment|/// isPhysicalRegister - Return true if the specified register number is in
end_comment

begin_comment
comment|/// the physical register namespace.
end_comment

begin_function
specifier|static
name|bool
name|isPhysicalRegister
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isStackSlot
argument_list|(
name|Reg
argument_list|)
operator|&&
literal|"Not a register! Check isStackSlot() first."
argument_list|)
expr_stmt|;
return|return
name|int
argument_list|(
name|Reg
argument_list|)
operator|>
literal|0
return|;
block|}
end_function

begin_comment
comment|/// isVirtualRegister - Return true if the specified register number is in
end_comment

begin_comment
comment|/// the virtual register namespace.
end_comment

begin_function
specifier|static
name|bool
name|isVirtualRegister
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isStackSlot
argument_list|(
name|Reg
argument_list|)
operator|&&
literal|"Not a register! Check isStackSlot() first."
argument_list|)
expr_stmt|;
return|return
name|int
argument_list|(
name|Reg
argument_list|)
operator|<
literal|0
return|;
block|}
end_function

begin_comment
comment|/// virtReg2Index - Convert a virtual register number to a 0-based index.
end_comment

begin_comment
comment|/// The first virtual register in a function will get the index 0.
end_comment

begin_function
specifier|static
name|unsigned
name|virtReg2Index
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|assert
argument_list|(
name|isVirtualRegister
argument_list|(
name|Reg
argument_list|)
operator|&&
literal|"Not a virtual register"
argument_list|)
expr_stmt|;
return|return
name|Reg
operator|&
operator|~
operator|(
literal|1u
operator|<<
literal|31
operator|)
return|;
block|}
end_function

begin_comment
comment|/// index2VirtReg - Convert a 0-based index to a virtual register number.
end_comment

begin_comment
comment|/// This is the inverse operation of VirtReg2IndexFunctor below.
end_comment

begin_function
specifier|static
name|unsigned
name|index2VirtReg
parameter_list|(
name|unsigned
name|Index
parameter_list|)
block|{
return|return
name|Index
operator||
operator|(
literal|1u
operator|<<
literal|31
operator|)
return|;
block|}
end_function

begin_comment
comment|/// getMinimalPhysRegClass - Returns the Register Class of a physical
end_comment

begin_comment
comment|/// register of the given type, picking the most sub register class of
end_comment

begin_comment
comment|/// the right type that contains this physreg.
end_comment

begin_decl_stmt
specifier|const
name|TargetRegisterClass
modifier|*
name|getMinimalPhysRegClass
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|EVT
name|VT
operator|=
name|MVT
operator|::
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getAllocatableSet - Returns a bitset indexed by register number
end_comment

begin_comment
comment|/// indicating if a register is allocatable or not. If a register class is
end_comment

begin_comment
comment|/// specified, returns the subset for the class.
end_comment

begin_decl_stmt
name|BitVector
name|getAllocatableSet
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|RC
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getCostPerUse - Return the additional cost of using this register instead
end_comment

begin_comment
comment|/// of other registers in its class.
end_comment

begin_decl_stmt
name|unsigned
name|getCostPerUse
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|InfoDesc
index|[
name|RegNo
index|]
operator|.
name|CostPerUse
return|;
block|}
end_decl_stmt

begin_comment
comment|/// isInAllocatableClass - Return true if the register is in the allocation
end_comment

begin_comment
comment|/// of any register class.
end_comment

begin_decl_stmt
name|bool
name|isInAllocatableClass
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|InfoDesc
index|[
name|RegNo
index|]
operator|.
name|inAllocatableClass
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getSubRegIndexName - Return the human-readable symbolic target-specific
end_comment

begin_comment
comment|/// name for the specified SubRegIndex.
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|getSubRegIndexName
argument_list|(
name|unsigned
name|SubIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|SubIdx
operator|&&
literal|"This is not a subregister index"
argument_list|)
expr_stmt|;
return|return
name|SubRegIndexNames
index|[
name|SubIdx
operator|-
literal|1
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|/// regsOverlap - Returns true if the two registers are equal or alias each
end_comment

begin_comment
comment|/// other. The registers may be virtual register.
end_comment

begin_decl_stmt
name|bool
name|regsOverlap
argument_list|(
name|unsigned
name|regA
argument_list|,
name|unsigned
name|regB
argument_list|)
decl|const
block|{
if|if
condition|(
name|regA
operator|==
name|regB
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isVirtualRegister
argument_list|(
name|regA
argument_list|)
operator|||
name|isVirtualRegister
argument_list|(
name|regB
argument_list|)
condition|)
return|return
name|false
return|;
for|for
control|(
specifier|const
name|uint16_t
modifier|*
name|regList
init|=
name|getOverlaps
argument_list|(
name|regA
argument_list|)
operator|+
literal|1
init|;
operator|*
name|regList
condition|;
operator|++
name|regList
control|)
block|{
if|if
condition|(
operator|*
name|regList
operator|==
name|regB
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// isSubRegister - Returns true if regB is a sub-register of regA.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|bool
name|isSubRegister
argument_list|(
name|unsigned
name|regA
argument_list|,
name|unsigned
name|regB
argument_list|)
decl|const
block|{
return|return
name|isSuperRegister
argument_list|(
name|regB
argument_list|,
name|regA
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// isSuperRegister - Returns true if regB is a super-register of regA.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|bool
name|isSuperRegister
argument_list|(
name|unsigned
name|regA
argument_list|,
name|unsigned
name|regB
argument_list|)
decl|const
block|{
for|for
control|(
specifier|const
name|uint16_t
modifier|*
name|regList
init|=
name|getSuperRegisters
argument_list|(
name|regA
argument_list|)
init|;
operator|*
name|regList
condition|;
operator|++
name|regList
control|)
block|{
if|if
condition|(
operator|*
name|regList
operator|==
name|regB
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getCalleeSavedRegs - Return a null-terminated list of all of the
end_comment

begin_comment
comment|/// callee saved registers on this target. The register should be in the
end_comment

begin_comment
comment|/// order of desired callee-save stack frame offset. The first register is
end_comment

begin_comment
comment|/// closest to the incoming stack pointer if stack grows down, and vice versa.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|uint16_t
modifier|*
name|getCalleeSavedRegs
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
operator|=
literal|0
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getCallPreservedMask - Return a mask of call-preserved registers for the
end_comment

begin_comment
comment|/// given calling convention on the current sub-target.  The mask should
end_comment

begin_comment
comment|/// include all call-preserved aliases.  This is used by the register
end_comment

begin_comment
comment|/// allocator to determine which registers can be live across a call.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The mask is an array containing (TRI::getNumRegs()+31)/32 entries.
end_comment

begin_comment
comment|/// A set bit indicates that all bits of the corresponding register are
end_comment

begin_comment
comment|/// preserved across the function call.  The bit mask is expected to be
end_comment

begin_comment
comment|/// sub-register complete, i.e. if A is preserved, so are all its
end_comment

begin_comment
comment|/// sub-registers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Bits are numbered from the LSB, so the bit for physical register Reg can
end_comment

begin_comment
comment|/// be found as (Mask[Reg / 32]>> Reg % 32)& 1.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A NULL pointer means that no register mask will be used, and call
end_comment

begin_comment
comment|/// instructions should use implicit-def operands to indicate call clobbered
end_comment

begin_comment
comment|/// registers.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|uint32_t
modifier|*
name|getCallPreservedMask
argument_list|(
name|CallingConv
operator|::
name|ID
argument_list|)
decl|const
block|{
comment|// The default mask clobbers everything.  All targets should override.
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getReservedRegs - Returns a bitset indexed by physical register number
end_comment

begin_comment
comment|/// indicating if a register is a special register that has particular uses
end_comment

begin_comment
comment|/// and should be considered unavailable at all times, e.g. SP, RA. This is
end_comment

begin_comment
comment|/// used by register scavenger to determine what registers are free.
end_comment

begin_decl_stmt
name|virtual
name|BitVector
name|getReservedRegs
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getMatchingSuperReg - Return a super-register of the specified register
end_comment

begin_comment
comment|/// Reg so its sub-register of index SubIdx is Reg.
end_comment

begin_decl_stmt
name|unsigned
name|getMatchingSuperReg
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|unsigned
name|SubIdx
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
return|return
name|MCRegisterInfo
operator|::
name|getMatchingSuperReg
argument_list|(
name|Reg
argument_list|,
name|SubIdx
argument_list|,
name|RC
operator|->
name|MC
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// canCombineSubRegIndices - Given a register class and a list of
end_comment

begin_comment
comment|/// subregister indices, return true if it's possible to combine the
end_comment

begin_comment
comment|/// subregister indices into one that corresponds to a larger
end_comment

begin_comment
comment|/// subregister. Return the new subregister index by reference. Note the
end_comment

begin_comment
comment|/// new index may be zero if the given subregisters can be combined to
end_comment

begin_comment
comment|/// form the whole register.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|canCombineSubRegIndices
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|SubIndices
argument_list|,
name|unsigned
operator|&
name|NewSubIdx
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getMatchingSuperRegClass - Return a subclass of the specified register
end_comment

begin_comment
comment|/// class A so that each register in it has a sub-register of the
end_comment

begin_comment
comment|/// specified sub-register index which is in the specified register class B.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// TableGen will synthesize missing A sub-classes.
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|TargetRegisterClass
modifier|*
name|getMatchingSuperRegClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|A
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|B
argument_list|,
name|unsigned
name|Idx
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getSubClassWithSubReg - Returns the largest legal sub-class of RC that
end_comment

begin_comment
comment|/// supports the sub-register index Idx.
end_comment

begin_comment
comment|/// If no such sub-class exists, return NULL.
end_comment

begin_comment
comment|/// If all registers in RC already have an Idx sub-register, return RC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// TableGen generates a version of this function that is good enough in most
end_comment

begin_comment
comment|/// cases.  Targets can override if they have constraints that TableGen
end_comment

begin_comment
comment|/// doesn't understand.  For example, the x86 sub_8bit sub-register index is
end_comment

begin_comment
comment|/// supported by the full GR32 register class in 64-bit mode, but only by the
end_comment

begin_comment
comment|/// GR32_ABCD regiister class in 32-bit mode.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// TableGen will synthesize missing RC sub-classes.
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|TargetRegisterClass
modifier|*
name|getSubClassWithSubReg
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|,
name|unsigned
name|Idx
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// composeSubRegIndices - Return the subregister index you get from composing
end_comment

begin_comment
comment|/// two subregister indices.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If R:a:b is the same register as R:c, then composeSubRegIndices(a, b)
end_comment

begin_comment
comment|/// returns c. Note that composeSubRegIndices does not tell you about illegal
end_comment

begin_comment
comment|/// compositions. If R does not have a subreg a, or R:a does not have a subreg
end_comment

begin_comment
comment|/// b, composeSubRegIndices doesn't tell you.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The ARM register Q0 has two D subregs dsub_0:D0 and dsub_1:D1. It also has
end_comment

begin_comment
comment|/// ssub_0:S0 - ssub_3:S3 subregs.
end_comment

begin_comment
comment|/// If you compose subreg indices dsub_1, ssub_0 you get ssub_2.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
name|unsigned
name|composeSubRegIndices
argument_list|(
name|unsigned
name|a
argument_list|,
name|unsigned
name|b
argument_list|)
decl|const
block|{
comment|// This default implementation is correct for most targets.
return|return
name|b
return|;
block|}
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Register Class Information
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// Register class iterators
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|regclass_iterator
name|regclass_begin
argument_list|()
specifier|const
block|{
return|return
name|RegClassBegin
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|regclass_iterator
name|regclass_end
argument_list|()
specifier|const
block|{
return|return
name|RegClassEnd
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getNumRegClasses
argument_list|()
specifier|const
block|{
return|return
call|(
name|unsigned
call|)
argument_list|(
name|regclass_end
argument_list|()
operator|-
name|regclass_begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getRegClass - Returns the register class associated with the enumeration
end_comment

begin_comment
comment|/// value.  See class MCOperandInfo.
end_comment

begin_decl_stmt
specifier|const
name|TargetRegisterClass
modifier|*
name|getRegClass
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumRegClasses
argument_list|()
operator|&&
literal|"Register Class ID out of range"
argument_list|)
expr_stmt|;
return|return
name|RegClassBegin
index|[
name|i
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getCommonSubClass - find the largest common subclass of A and B. Return
end_comment

begin_comment
comment|/// NULL if there is no common subclass.
end_comment

begin_decl_stmt
specifier|const
name|TargetRegisterClass
modifier|*
name|getCommonSubClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|A
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|B
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getPointerRegClass - Returns a TargetRegisterClass used for pointer
end_comment

begin_comment
comment|/// values.  If a target supports multiple different pointer register classes,
end_comment

begin_comment
comment|/// kind specifies which one is indicated.
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|TargetRegisterClass
modifier|*
name|getPointerRegClass
argument_list|(
name|unsigned
name|Kind
operator|=
literal|0
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Target didn't implement getPointerRegClass!"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// getCrossCopyRegClass - Returns a legal register class to copy a register
end_comment

begin_comment
comment|/// in the specified class to or from. If it is possible to copy the register
end_comment

begin_comment
comment|/// directly without using a cross register class copy, return the specified
end_comment

begin_comment
comment|/// RC. Returns NULL if it is not possible to copy between a two registers of
end_comment

begin_comment
comment|/// the specified class.
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|TargetRegisterClass
modifier|*
name|getCrossCopyRegClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
return|return
name|RC
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getLargestLegalSuperClass - Returns the largest super class of RC that is
end_comment

begin_comment
comment|/// legal to use in the current sub-target and has the same spill size.
end_comment

begin_comment
comment|/// The returned register class can be used to create virtual registers which
end_comment

begin_comment
comment|/// means that all its registers can be copied and spilled.
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|TargetRegisterClass
modifier|*
name|getLargestLegalSuperClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
comment|/// The default implementation is very conservative and doesn't allow the
comment|/// register allocator to inflate register classes.
return|return
name|RC
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getRegPressureLimit - Return the register pressure "high water mark" for
end_comment

begin_comment
comment|/// the specific register class. The scheduler is in high register pressure
end_comment

begin_comment
comment|/// mode (for the specific register class) if it goes over the limit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note: this is the old register pressure model that relies on a manually
end_comment

begin_comment
comment|/// specified representative register class per value type.
end_comment

begin_decl_stmt
name|virtual
name|unsigned
name|getRegPressureLimit
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Get the weight in units of pressure for this register class.
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|RegClassWeight
modifier|&
name|getRegClassWeight
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Get the number of dimensions of register pressure.
end_comment

begin_expr_stmt
name|virtual
name|unsigned
name|getNumRegPressureSets
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Get the register unit pressure limit for this dimension.
end_comment

begin_comment
comment|/// This limit must be adjusted dynamically for reserved registers.
end_comment

begin_decl_stmt
name|virtual
name|unsigned
name|getRegPressureSetLimit
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Get the dimensions of register pressure impacted by this register class.
end_comment

begin_comment
comment|/// Returns a -1 terminated array of pressure set IDs.
end_comment

begin_decl_stmt
name|virtual
specifier|const
name|int
modifier|*
name|getRegClassPressureSets
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getRawAllocationOrder - Returns the register allocation order for a
end_comment

begin_comment
comment|/// specified register class with a target-dependent hint. The returned list
end_comment

begin_comment
comment|/// may contain reserved registers that cannot be allocated.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Register allocators need only call this function to resolve
end_comment

begin_comment
comment|/// target-dependent hints, but it should work without hinting as well.
end_comment

begin_expr_stmt
name|virtual
name|ArrayRef
operator|<
name|uint16_t
operator|>
name|getRawAllocationOrder
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|unsigned HintType
argument_list|,
argument|unsigned HintReg
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|{
return|return
name|RC
operator|->
name|getRawAllocationOrder
argument_list|(
name|MF
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// ResolveRegAllocHint - Resolves the specified register allocation hint
end_comment

begin_comment
comment|/// to a physical register. Returns the physical register if it is successful.
end_comment

begin_decl_stmt
name|virtual
name|unsigned
name|ResolveRegAllocHint
argument_list|(
name|unsigned
name|Type
argument_list|,
name|unsigned
name|Reg
argument_list|,
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
if|if
condition|(
name|Type
operator|==
literal|0
operator|&&
name|Reg
operator|&&
name|isPhysicalRegister
argument_list|(
name|Reg
argument_list|)
condition|)
return|return
name|Reg
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// avoidWriteAfterWrite - Return true if the register allocator should avoid
end_comment

begin_comment
comment|/// writing a register from RC in two consecutive instructions.
end_comment

begin_comment
comment|/// This can avoid pipeline stalls on certain architectures.
end_comment

begin_comment
comment|/// It does cause increased register pressure, though.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|avoidWriteAfterWrite
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// UpdateRegAllocHint - A callback to allow target a chance to update
end_comment

begin_comment
comment|/// register allocation hints when a register is "changed" (e.g. coalesced)
end_comment

begin_comment
comment|/// to another register. e.g. On ARM, some virtual registers should target
end_comment

begin_comment
comment|/// register pairs, if one of pair is coalesced to another register, the
end_comment

begin_comment
comment|/// allocation hint of the other half of the pair should be changed to point
end_comment

begin_comment
comment|/// to the new register.
end_comment

begin_decl_stmt
name|virtual
name|void
name|UpdateRegAllocHint
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|unsigned
name|NewReg
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
comment|// Do nothing.
block|}
end_decl_stmt

begin_comment
comment|/// requiresRegisterScavenging - returns true if the target requires (and can
end_comment

begin_comment
comment|/// make use of) the register scavenger.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|requiresRegisterScavenging
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// useFPForScavengingIndex - returns true if the target wants to use
end_comment

begin_comment
comment|/// frame pointer based accesses to spill to the scavenger emergency spill
end_comment

begin_comment
comment|/// slot.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|useFPForScavengingIndex
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
end_decl_stmt

begin_comment
comment|/// requiresFrameIndexScavenging - returns true if the target requires post
end_comment

begin_comment
comment|/// PEI scavenging of registers for materializing frame index constants.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|requiresFrameIndexScavenging
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// requiresVirtualBaseRegisters - Returns true if the target wants the
end_comment

begin_comment
comment|/// LocalStackAllocation pass to be run and virtual base registers
end_comment

begin_comment
comment|/// used for more efficient stack access.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|requiresVirtualBaseRegisters
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// hasReservedSpillSlot - Return true if target has reserved a spill slot in
end_comment

begin_comment
comment|/// the stack frame of the given function for the specified register. e.g. On
end_comment

begin_comment
comment|/// x86, if the frame register is required, the first fixed stack object is
end_comment

begin_comment
comment|/// reserved as its spill slot. This tells PEI not to create a new stack frame
end_comment

begin_comment
comment|/// object for the given register. It should be called only after
end_comment

begin_comment
comment|/// processFunctionBeforeCalleeSavedScan().
end_comment

begin_decl_stmt
name|virtual
name|bool
name|hasReservedSpillSlot
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
name|unsigned
name|Reg
argument_list|,
name|int
operator|&
name|FrameIdx
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// needsStackRealignment - true if storage within the function requires the
end_comment

begin_comment
comment|/// stack pointer to be aligned more than the normal calling convention calls
end_comment

begin_comment
comment|/// for.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|needsStackRealignment
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getFrameIndexInstrOffset - Get the offset from the referenced frame
end_comment

begin_comment
comment|/// index in the instruction, if there is one.
end_comment

begin_decl_stmt
name|virtual
name|int64_t
name|getFrameIndexInstrOffset
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|int
name|Idx
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// needsFrameBaseReg - Returns true if the instruction's frame index
end_comment

begin_comment
comment|/// reference would be better served by a base register other than FP
end_comment

begin_comment
comment|/// or SP. Used by LocalStackFrameAllocation to determine which frame index
end_comment

begin_comment
comment|/// references it should create new base registers for.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|needsFrameBaseReg
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|int64_t
name|Offset
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// materializeFrameBaseRegister - Insert defining instruction(s) for
end_comment

begin_comment
comment|/// BaseReg to be a pointer to FrameIdx before insertion point I.
end_comment

begin_decl_stmt
name|virtual
name|void
name|materializeFrameBaseRegister
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|unsigned
name|BaseReg
argument_list|,
name|int
name|FrameIdx
argument_list|,
name|int64_t
name|Offset
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"materializeFrameBaseRegister does not exist on this "
literal|"target"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// resolveFrameIndex - Resolve a frame index operand of an instruction
end_comment

begin_comment
comment|/// to reference the indicated base register plus offset instead.
end_comment

begin_decl_stmt
name|virtual
name|void
name|resolveFrameIndex
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|I
argument_list|,
name|unsigned
name|BaseReg
argument_list|,
name|int64_t
name|Offset
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"resolveFrameIndex does not exist on this target"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// isFrameOffsetLegal - Determine whether a given offset immediate is
end_comment

begin_comment
comment|/// encodable to resolve a frame index.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|isFrameOffsetLegal
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|int64_t
name|Offset
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"isFrameOffsetLegal does not exist on this target"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// eliminateCallFramePseudoInstr - This method is called during prolog/epilog
end_comment

begin_comment
comment|/// code insertion to eliminate call frame setup and destroy pseudo
end_comment

begin_comment
comment|/// instructions (but only if the Target is using them).  It is responsible
end_comment

begin_comment
comment|/// for eliminating these instructions, replacing them with concrete
end_comment

begin_comment
comment|/// instructions.  This method need only be implemented if using call frame
end_comment

begin_comment
comment|/// setup/destroy pseudo instructions.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
name|void
name|eliminateCallFramePseudoInstr
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Call Frame Pseudo Instructions do not exist on this "
literal|"target!"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// saveScavengerRegister - Spill the register so it can be used by the
end_comment

begin_comment
comment|/// register scavenger. Return true if the register was spilled, false
end_comment

begin_comment
comment|/// otherwise. If this function does not spill the register, the scavenger
end_comment

begin_comment
comment|/// will instead spill it to the emergency spill slot.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
name|bool
name|saveScavengerRegister
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|I
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
operator|&
name|UseMI
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|,
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// eliminateFrameIndex - This method must be overriden to eliminate abstract
end_comment

begin_comment
comment|/// frame indices from instructions which may use them.  The instruction
end_comment

begin_comment
comment|/// referenced by the iterator contains an MO_FrameIndex operand which must be
end_comment

begin_comment
comment|/// eliminated by this method.  This method may modify or replace the
end_comment

begin_comment
comment|/// specified instruction, as long as it keeps the iterator pointing at the
end_comment

begin_comment
comment|/// finished product. SPAdj is the SP adjustment due to call frame setup
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_decl_stmt
name|virtual
name|void
name|eliminateFrameIndex
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|int
name|SPAdj
argument_list|,
name|RegScavenger
operator|*
name|RS
operator|=
name|NULL
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// Debug information queries.
end_comment

begin_comment
comment|/// getFrameRegister - This method should return the register used as a base
end_comment

begin_comment
comment|/// for values allocated in the current stack frame.
end_comment

begin_decl_stmt
name|virtual
name|unsigned
name|getFrameRegister
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getCompactUnwindRegNum - This function maps the register to the number for
end_comment

begin_comment
comment|/// compact unwind encoding. Return -1 if the register isn't valid.
end_comment

begin_decl_stmt
name|virtual
name|int
name|getCompactUnwindRegNum
argument_list|(
name|unsigned
argument_list|,
name|bool
argument_list|)
decl|const
block|{
return|return
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|// This is useful when building IndexedMaps keyed on virtual registers
end_comment

begin_decl_stmt
name|struct
name|VirtReg2IndexFunctor
range|:
name|public
name|std
operator|::
name|unary_function
operator|<
name|unsigned
decl_stmt|,
name|unsigned
decl|>
block|{
name|unsigned
name|operator
argument_list|()
operator|(
name|unsigned
name|Reg
operator|)
specifier|const
block|{
return|return
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|Reg
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// PrintReg - Helper class for printing registers on a raw_ostream.
end_comment

begin_comment
comment|/// Prints virtual and physical registers with or without a TRI instance.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The format is:
end_comment

begin_comment
comment|///   %noreg          - NoRegister
end_comment

begin_comment
comment|///   %vreg5          - a virtual register.
end_comment

begin_comment
comment|///   %vreg5:sub_8bit - a virtual register with sub-register index (with TRI).
end_comment

begin_comment
comment|///   %EAX            - a physical register
end_comment

begin_comment
comment|///   %physreg17      - a physical register when no TRI instance given.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Usage: OS<< PrintReg(Reg, TRI)<< '\n';
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|PrintReg
block|{
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
name|unsigned
name|Reg
decl_stmt|;
name|unsigned
name|SubIdx
decl_stmt|;
name|public
label|:
name|PrintReg
argument_list|(
argument|unsigned reg
argument_list|,
argument|const TargetRegisterInfo *tri =
literal|0
argument_list|,
argument|unsigned subidx =
literal|0
argument_list|)
block|:
name|TRI
argument_list|(
name|tri
argument_list|)
operator|,
name|Reg
argument_list|(
name|reg
argument_list|)
operator|,
name|SubIdx
argument_list|(
argument|subidx
argument_list|)
block|{}
name|void
name|print
argument_list|(
argument|raw_ostream&
argument_list|)
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|static
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
name|PrintReg
operator|&
name|PR
operator|)
block|{
name|PR
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

