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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Printable.h"
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
name|VirtRegMap
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|LiveRegMatrix
decl_stmt|;
name|class
name|TargetRegisterClass
block|{
name|public
label|:
typedef|typedef
specifier|const
name|MCPhysReg
modifier|*
name|iterator
typedef|;
typedef|typedef
specifier|const
name|MCPhysReg
modifier|*
name|const_iterator
typedef|;
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
name|uint16_t
name|SpillSize
decl_stmt|,
name|SpillAlignment
decl_stmt|;
specifier|const
name|MVT
operator|::
name|SimpleValueType
operator|*
name|VTs
expr_stmt|;
specifier|const
name|uint32_t
modifier|*
name|SubClassMask
decl_stmt|;
specifier|const
name|uint16_t
modifier|*
name|SuperRegIndices
decl_stmt|;
specifier|const
name|LaneBitmask
name|LaneMask
decl_stmt|;
comment|/// Classes with a higher priority value are assigned first by register
comment|/// allocators using a greedy heuristic. The value is in the range [0,63].
specifier|const
name|uint8_t
name|AllocationPriority
decl_stmt|;
comment|/// Whether the class supports two (or more) disjunct subregister indices.
specifier|const
name|bool
name|HasDisjunctSubRegs
decl_stmt|;
comment|/// Whether a combination of subregisters can cover every register in the
comment|/// class. See also the CoveredBySubRegs description in Target.td.
specifier|const
name|bool
name|CoveredBySubRegs
decl_stmt|;
specifier|const
name|sc_iterator
name|SuperClasses
decl_stmt|;
name|ArrayRef
operator|<
name|MCPhysReg
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
comment|/// Return the register class ID number.
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
comment|/// Return the number of registers in this class.
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
name|iterator_range
operator|<
name|SmallVectorImpl
operator|<
name|MCPhysReg
operator|>
operator|::
name|const_iterator
operator|>
name|getRegisters
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|MC
operator|->
name|begin
argument_list|()
argument_list|,
name|MC
operator|->
name|end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return the specified register in the class.
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
comment|/// Return true if the specified register is included in this register class.
comment|/// This does not include virtual registers.
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
comment|/// Return true if both registers are in this class.
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
comment|/// Return the cost of copying a value between two registers in this class.
comment|/// A negative number means the register class is very expensive
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
comment|/// Return true if this register class may be used to create virtual
comment|/// registers.
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
comment|/// Return true if the specified TargetRegisterClass
comment|/// is a proper sub-class of this TargetRegisterClass.
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
comment|/// Returns true if RC is a sub-class of or equal to this class.
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
comment|/// Return true if the specified TargetRegisterClass is a
comment|/// proper super-class of this TargetRegisterClass.
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
comment|/// Returns true if RC is a super-class of or equal to this class.
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
comment|/// Returns a bit vector of subclasses, including this one.
comment|/// The vector is indexed by class IDs.
comment|///
comment|/// To use it, consider the returned array as a chunk of memory that
comment|/// contains an array of bits of size NumRegClasses. Each 32-bit chunk
comment|/// contains a bitset of the ID of the subclasses in big-endian style.
comment|/// I.e., the representation of the memory from left to right at the
comment|/// bit level looks like:
comment|/// [31 30 ... 1 0] [ 63 62 ... 33 32] ...
comment|///                     [ XXX NumRegClasses NumRegClasses - 1 ... ]
comment|/// Where the number represents the class ID and XXX bits that
comment|/// should be ignored.
comment|///
comment|/// See the implementation of hasSubClassEq for an example of how it
comment|/// can be used.
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
comment|/// Returns a 0-terminated list of sub-register indices that project some
comment|/// super-register class into this register class. The list has an entry for
comment|/// each Idx such that:
comment|///
comment|///   There exists SuperRC where:
comment|///     For all Reg in SuperRC:
comment|///       this->contains(Reg:Idx)
comment|///
specifier|const
name|uint16_t
operator|*
name|getSuperRegIndices
argument_list|()
specifier|const
block|{
return|return
name|SuperRegIndices
return|;
block|}
comment|/// Returns a NULL-terminated list of super-classes.  The
comment|/// classes are ordered by ID which is also a topological ordering from large
comment|/// to small classes.  The list does NOT include the current class.
name|sc_iterator
name|getSuperClasses
argument_list|()
specifier|const
block|{
return|return
name|SuperClasses
return|;
block|}
comment|/// Return true if this TargetRegisterClass is a subset
comment|/// class of at least one other TargetRegisterClass.
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
name|nullptr
return|;
block|}
comment|/// Returns the preferred order for allocating registers from this register
comment|/// class in MF. The raw order comes directly from the .td file and may
comment|/// include reserved registers that are not allocatable.
comment|/// Register allocators should also make sure to allocate
comment|/// callee-saved registers only after all the volatiles are used. The
comment|/// RegisterClassInfo class provides filtered allocation orders with
comment|/// callee-saved registers moved to the end.
comment|///
comment|/// The MachineFunction argument can be used to tune the allocatable
comment|/// registers based on the characteristics of the function, subtarget, or
comment|/// other criteria.
comment|///
comment|/// By default, this method returns all registers in the class.
comment|///
name|ArrayRef
operator|<
name|MCPhysReg
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
comment|/// Returns the combination of all lane masks of register in this class.
comment|/// The lane masks of the registers are the combination of all lane masks
comment|/// of their subregisters. Returns 1 if there are no subregisters.
name|LaneBitmask
name|getLaneMask
argument_list|()
specifier|const
block|{
return|return
name|LaneMask
return|;
block|}
block|}
empty_stmt|;
comment|/// Extra information, not in MCRegisterDesc, about registers.
comment|/// These are used by codegen, not by MC.
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
comment|/// Each TargetRegisterClass has a per register weight, and weight
comment|/// limit which must be less than the limits of its pressure sets.
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
comment|/// TargetRegisterInfo base class - We assume that the target defines a static
comment|/// array of TargetRegisterDesc objects that represent all of the machine
comment|/// registers that the target has.  As such, we simply have to track a pointer
comment|/// to this array so that we can turn register number into a register
comment|/// descriptor.
comment|///
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
typedef|typedef
specifier|const
name|MVT
operator|::
name|SimpleValueType
operator|*
name|vt_iterator
expr_stmt|;
name|private
label|:
specifier|const
name|TargetRegisterInfoDesc
modifier|*
name|InfoDesc
decl_stmt|;
comment|// Extra desc array for codegen
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|SubRegIndexNames
decl_stmt|;
comment|// Names of subreg indexes.
comment|// Pointer to array of lane masks, one per sub-reg index.
specifier|const
name|LaneBitmask
modifier|*
name|SubRegIndexLaneMasks
decl_stmt|;
name|regclass_iterator
name|RegClassBegin
decl_stmt|,
name|RegClassEnd
decl_stmt|;
comment|// List of regclasses
name|LaneBitmask
name|CoveringLanes
decl_stmt|;
name|protected
label|:
name|TargetRegisterInfo
argument_list|(
argument|const TargetRegisterInfoDesc *ID
argument_list|,
argument|regclass_iterator RegClassBegin
argument_list|,
argument|regclass_iterator RegClassEnd
argument_list|,
argument|const char *const *SRINames
argument_list|,
argument|const LaneBitmask *SRILaneMasks
argument_list|,
argument|LaneBitmask CoveringLanes
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|TargetRegisterInfo
argument_list|()
expr_stmt|;
name|public
label|:
comment|// Register numbers can represent physical registers, virtual registers, and
comment|// sometimes stack slots. The unsigned values are divided into these ranges:
comment|//
comment|//   0           Not a register, can be used as a sentinel.
comment|//   [1;2^30)    Physical registers assigned by TableGen.
comment|//   [2^30;2^31) Stack slots. (Rarely used.)
comment|//   [2^31;2^32) Virtual registers assigned by MachineRegisterInfo.
comment|//
comment|// Further sentinels can be allocated from the small negative integers.
comment|// DenseMapInfo<unsigned> uses -1u and -2u.
comment|/// isStackSlot - Sometimes it is useful the be able to store a non-negative
comment|/// frame index in a variable that normally holds a register. isStackSlot()
comment|/// returns true if Reg is in the range used for stack slots.
comment|///
comment|/// Note that isVirtualRegister() and isPhysicalRegister() cannot handle stack
comment|/// slots, so if a variable may contains a stack slot, always check
comment|/// isStackSlot() first.
comment|///
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
comment|/// Compute the frame index from a register value representing a stack slot.
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
comment|/// Convert a non-negative frame index to a stack slot register value.
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
comment|/// Return true if the specified register number is in
comment|/// the physical register namespace.
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
comment|/// Return true if the specified register number is in
comment|/// the virtual register namespace.
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
comment|/// Convert a virtual register number to a 0-based index.
comment|/// The first virtual register in a function will get the index 0.
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
comment|/// Convert a 0-based index to a virtual register number.
comment|/// This is the inverse operation of VirtReg2IndexFunctor below.
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
comment|/// Return the size in bits of a register from class RC.
name|unsigned
name|getRegSizeInBits
argument_list|(
specifier|const
name|TargetRegisterClass
operator|&
name|RC
argument_list|)
decl|const
block|{
return|return
name|RC
operator|.
name|SpillSize
operator|*
literal|8
return|;
block|}
comment|/// Return the size in bytes of the stack slot allocated to hold a spilled
comment|/// copy of a register from class RC.
name|unsigned
name|getSpillSize
argument_list|(
specifier|const
name|TargetRegisterClass
operator|&
name|RC
argument_list|)
decl|const
block|{
return|return
name|RC
operator|.
name|SpillSize
return|;
block|}
comment|/// Return the minimum required alignment for a spill slot for a register
comment|/// of this class.
name|unsigned
name|getSpillAlignment
argument_list|(
specifier|const
name|TargetRegisterClass
operator|&
name|RC
argument_list|)
decl|const
block|{
return|return
name|RC
operator|.
name|SpillAlignment
return|;
block|}
comment|/// Return true if the given TargetRegisterClass has the ValueType T.
name|bool
name|isTypeLegalForClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|&
name|RC
argument_list|,
name|MVT
name|T
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
name|RC
operator|.
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
name|MVT
argument_list|(
name|RC
operator|.
name|VTs
index|[
name|i
index|]
argument_list|)
operator|==
name|T
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|/// Loop over all of the value types that can be represented by values
comment|// in the given register class.
name|vt_iterator
name|legalclasstypes_begin
argument_list|(
specifier|const
name|TargetRegisterClass
operator|&
name|RC
argument_list|)
decl|const
block|{
return|return
name|RC
operator|.
name|VTs
return|;
block|}
name|vt_iterator
name|legalclasstypes_end
argument_list|(
specifier|const
name|TargetRegisterClass
operator|&
name|RC
argument_list|)
decl|const
block|{
name|vt_iterator
name|I
init|=
name|RC
operator|.
name|VTs
decl_stmt|;
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
comment|/// Returns the Register Class of a physical register of the given type,
comment|/// picking the most sub register class of the right type that contains this
comment|/// physreg.
specifier|const
name|TargetRegisterClass
modifier|*
name|getMinimalPhysRegClass
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|MVT
name|VT
operator|=
name|MVT
operator|::
name|Other
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the maximal subclass of the given register class that is
comment|/// allocatable or NULL.
specifier|const
name|TargetRegisterClass
modifier|*
name|getAllocatableClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns a bitset indexed by register number indicating if a register is
comment|/// allocatable or not. If a register class is specified, returns the subset
comment|/// for the class.
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
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the additional cost of using this register instead
comment|/// of other registers in its class.
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
comment|/// Return true if the register is in the allocation of any register class.
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
comment|/// Return the human-readable symbolic target-specific
comment|/// name for the specified SubRegIndex.
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
name|SubIdx
operator|<
name|getNumSubRegIndices
argument_list|()
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
comment|/// Return a bitmask representing the parts of a register that are covered by
comment|/// SubIdx \see LaneBitmask.
comment|///
comment|/// SubIdx == 0 is allowed, it has the lane mask ~0u.
name|LaneBitmask
name|getSubRegIndexLaneMask
argument_list|(
name|unsigned
name|SubIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|SubIdx
operator|<
name|getNumSubRegIndices
argument_list|()
operator|&&
literal|"This is not a subregister index"
argument_list|)
expr_stmt|;
return|return
name|SubRegIndexLaneMasks
index|[
name|SubIdx
index|]
return|;
block|}
comment|/// The lane masks returned by getSubRegIndexLaneMask() above can only be
comment|/// used to determine if sub-registers overlap - they can't be used to
comment|/// determine if a set of sub-registers completely cover another
comment|/// sub-register.
comment|///
comment|/// The X86 general purpose registers have two lanes corresponding to the
comment|/// sub_8bit and sub_8bit_hi sub-registers. Both sub_32bit and sub_16bit have
comment|/// lane masks '3', but the sub_16bit sub-register doesn't fully cover the
comment|/// sub_32bit sub-register.
comment|///
comment|/// On the other hand, the ARM NEON lanes fully cover their registers: The
comment|/// dsub_0 sub-register is completely covered by the ssub_0 and ssub_1 lanes.
comment|/// This is related to the CoveredBySubRegs property on register definitions.
comment|///
comment|/// This function returns a bit mask of lanes that completely cover their
comment|/// sub-registers. More precisely, given:
comment|///
comment|///   Covering = getCoveringLanes();
comment|///   MaskA = getSubRegIndexLaneMask(SubA);
comment|///   MaskB = getSubRegIndexLaneMask(SubB);
comment|///
comment|/// If (MaskA& ~(MaskB& Covering)) == 0, then SubA is completely covered by
comment|/// SubB.
name|LaneBitmask
name|getCoveringLanes
argument_list|()
specifier|const
block|{
return|return
name|CoveringLanes
return|;
block|}
comment|/// Returns true if the two registers are equal or alias each other.
comment|/// The registers may be virtual registers.
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
comment|// Regunits are numerically ordered. Find a common unit.
name|MCRegUnitIterator
name|RUA
parameter_list|(
name|regA
parameter_list|,
name|this
parameter_list|)
function_decl|;
name|MCRegUnitIterator
name|RUB
parameter_list|(
name|regB
parameter_list|,
name|this
parameter_list|)
function_decl|;
do|do
block|{
if|if
condition|(
operator|*
name|RUA
operator|==
operator|*
name|RUB
condition|)
return|return
name|true
return|;
if|if
condition|(
operator|*
name|RUA
operator|<
operator|*
name|RUB
condition|)
operator|++
name|RUA
expr_stmt|;
else|else
operator|++
name|RUB
expr_stmt|;
block|}
do|while
condition|(
name|RUA
operator|.
name|isValid
argument_list|()
operator|&&
name|RUB
operator|.
name|isValid
argument_list|()
condition|)
do|;
return|return
name|false
return|;
block|}
comment|/// Returns true if Reg contains RegUnit.
name|bool
name|hasRegUnit
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|unsigned
name|RegUnit
argument_list|)
decl|const
block|{
for|for
control|(
name|MCRegUnitIterator
name|Units
argument_list|(
name|Reg
argument_list|,
name|this
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
operator|*
name|Units
operator|==
name|RegUnit
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|/// Return a null-terminated list of all of the callee-saved registers on
comment|/// this target. The register should be in the order of desired callee-save
comment|/// stack frame offset. The first register is closest to the incoming stack
comment|/// pointer if stack grows down, and vice versa.
comment|/// Notice: This function does not take into account disabled CSRs.
comment|///         In most cases you will want to use instead the function
comment|///         getCalleeSavedRegs that is implemented in MachineRegisterInfo.
name|virtual
specifier|const
name|MCPhysReg
modifier|*
name|getCalleeSavedRegs
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Return a mask of call-preserved registers for the given calling convention
comment|/// on the current function. The mask should include all call-preserved
comment|/// aliases. This is used by the register allocator to determine which
comment|/// registers can be live across a call.
comment|///
comment|/// The mask is an array containing (TRI::getNumRegs()+31)/32 entries.
comment|/// A set bit indicates that all bits of the corresponding register are
comment|/// preserved across the function call.  The bit mask is expected to be
comment|/// sub-register complete, i.e. if A is preserved, so are all its
comment|/// sub-registers.
comment|///
comment|/// Bits are numbered from the LSB, so the bit for physical register Reg can
comment|/// be found as (Mask[Reg / 32]>> Reg % 32)& 1.
comment|///
comment|/// A NULL pointer means that no register mask will be used, and call
comment|/// instructions should use implicit-def operands to indicate call clobbered
comment|/// registers.
comment|///
name|virtual
specifier|const
name|uint32_t
modifier|*
name|getCallPreservedMask
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
name|CallingConv
operator|::
name|ID
argument_list|)
decl|const
block|{
comment|// The default mask clobbers everything.  All targets should override.
return|return
name|nullptr
return|;
block|}
comment|/// Return a register mask that clobbers everything.
name|virtual
specifier|const
name|uint32_t
operator|*
name|getNoPreservedMask
argument_list|()
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"target does not provide no preserved mask"
argument_list|)
block|;   }
comment|/// Return true if all bits that are set in mask \p mask0 are also set in
comment|/// \p mask1.
name|bool
name|regmaskSubsetEqual
argument_list|(
argument|const uint32_t *mask0
argument_list|,
argument|const uint32_t *mask1
argument_list|)
specifier|const
expr_stmt|;
comment|/// Return all the call-preserved register masks defined for this target.
name|virtual
name|ArrayRef
operator|<
specifier|const
name|uint32_t
operator|*
operator|>
name|getRegMasks
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|getRegMaskNames
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Returns a bitset indexed by physical register number indicating if a
comment|/// register is a special register that has particular uses and should be
comment|/// considered unavailable at all times, e.g. stack pointer, return address.
comment|/// A reserved register:
comment|/// - is not allocatable
comment|/// - is considered always live
comment|/// - is ignored by liveness tracking
comment|/// It is often necessary to reserve the super registers of a reserved
comment|/// register as well, to avoid them getting allocated indirectly. You may use
comment|/// markSuperRegs() and checkAllSuperRegsMarked() in this case.
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
comment|/// Returns true if PhysReg is unallocatable and constant throughout the
comment|/// function.  Used by MachineRegisterInfo::isConstantPhysReg().
name|virtual
name|bool
name|isConstantPhysReg
argument_list|(
name|unsigned
name|PhysReg
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Prior to adding the live-out mask to a stackmap or patchpoint
comment|/// instruction, provide the target the opportunity to adjust it (mainly to
comment|/// remove pseudo-registers that should be ignored).
name|virtual
name|void
name|adjustStackMapLiveOutMask
argument_list|(
name|uint32_t
operator|*
name|Mask
argument_list|)
decl|const
block|{ }
comment|/// Return a super-register of the specified register
comment|/// Reg so its sub-register of index SubIdx is Reg.
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
comment|/// Return a subclass of the specified register
comment|/// class A so that each register in it has a sub-register of the
comment|/// specified sub-register index which is in the specified register class B.
comment|///
comment|/// TableGen will synthesize missing A sub-classes.
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
decl_stmt|;
comment|// For a copy-like instruction that defines a register of class DefRC with
comment|// subreg index DefSubReg, reading from another source with class SrcRC and
comment|// subregister SrcSubReg return true if this is a preferable copy
comment|// instruction or an earlier use should be used.
name|virtual
name|bool
name|shouldRewriteCopySrc
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|DefRC
argument_list|,
name|unsigned
name|DefSubReg
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|SrcRC
argument_list|,
name|unsigned
name|SrcSubReg
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns the largest legal sub-class of RC that
comment|/// supports the sub-register index Idx.
comment|/// If no such sub-class exists, return NULL.
comment|/// If all registers in RC already have an Idx sub-register, return RC.
comment|///
comment|/// TableGen generates a version of this function that is good enough in most
comment|/// cases.  Targets can override if they have constraints that TableGen
comment|/// doesn't understand.  For example, the x86 sub_8bit sub-register index is
comment|/// supported by the full GR32 register class in 64-bit mode, but only by the
comment|/// GR32_ABCD regiister class in 32-bit mode.
comment|///
comment|/// TableGen will synthesize missing RC sub-classes.
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
block|{
name|assert
argument_list|(
name|Idx
operator|==
literal|0
operator|&&
literal|"Target has no sub-registers"
argument_list|)
expr_stmt|;
return|return
name|RC
return|;
block|}
comment|/// Return the subregister index you get from composing
comment|/// two subregister indices.
comment|///
comment|/// The special null sub-register index composes as the identity.
comment|///
comment|/// If R:a:b is the same register as R:c, then composeSubRegIndices(a, b)
comment|/// returns c. Note that composeSubRegIndices does not tell you about illegal
comment|/// compositions. If R does not have a subreg a, or R:a does not have a subreg
comment|/// b, composeSubRegIndices doesn't tell you.
comment|///
comment|/// The ARM register Q0 has two D subregs dsub_0:D0 and dsub_1:D1. It also has
comment|/// ssub_0:S0 - ssub_3:S3 subregs.
comment|/// If you compose subreg indices dsub_1, ssub_0 you get ssub_2.
comment|///
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
if|if
condition|(
operator|!
name|a
condition|)
return|return
name|b
return|;
if|if
condition|(
operator|!
name|b
condition|)
return|return
name|a
return|;
return|return
name|composeSubRegIndicesImpl
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
comment|/// Transforms a LaneMask computed for one subregister to the lanemask that
comment|/// would have been computed when composing the subsubregisters with IdxA
comment|/// first. @sa composeSubRegIndices()
name|LaneBitmask
name|composeSubRegIndexLaneMask
argument_list|(
name|unsigned
name|IdxA
argument_list|,
name|LaneBitmask
name|Mask
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|IdxA
condition|)
return|return
name|Mask
return|;
return|return
name|composeSubRegIndexLaneMaskImpl
argument_list|(
name|IdxA
argument_list|,
name|Mask
argument_list|)
return|;
block|}
comment|/// Transform a lanemask given for a virtual register to the corresponding
comment|/// lanemask before using subregister with index \p IdxA.
comment|/// This is the reverse of composeSubRegIndexLaneMask(), assuming Mask is a
comment|/// valie lane mask (no invalid bits set) the following holds:
comment|/// X0 = composeSubRegIndexLaneMask(Idx, Mask)
comment|/// X1 = reverseComposeSubRegIndexLaneMask(Idx, X0)
comment|/// => X1 == Mask
name|LaneBitmask
name|reverseComposeSubRegIndexLaneMask
argument_list|(
name|unsigned
name|IdxA
argument_list|,
name|LaneBitmask
name|LaneMask
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|IdxA
condition|)
return|return
name|LaneMask
return|;
return|return
name|reverseComposeSubRegIndexLaneMaskImpl
argument_list|(
name|IdxA
argument_list|,
name|LaneMask
argument_list|)
return|;
block|}
comment|/// Debugging helper: dump register in human readable form to dbgs() stream.
specifier|static
name|void
name|dumpReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|unsigned
name|SubRegIndex
init|=
literal|0
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
init|=
name|nullptr
parameter_list|)
function_decl|;
name|protected
label|:
comment|/// Overridden by TableGen in targets that have sub-registers.
name|virtual
name|unsigned
name|composeSubRegIndicesImpl
argument_list|(
name|unsigned
argument_list|,
name|unsigned
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Target has no sub-registers"
argument_list|)
expr_stmt|;
block|}
comment|/// Overridden by TableGen in targets that have sub-registers.
name|virtual
name|LaneBitmask
name|composeSubRegIndexLaneMaskImpl
argument_list|(
name|unsigned
argument_list|,
name|LaneBitmask
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Target has no sub-registers"
argument_list|)
expr_stmt|;
block|}
name|virtual
name|LaneBitmask
name|reverseComposeSubRegIndexLaneMaskImpl
argument_list|(
name|unsigned
argument_list|,
name|LaneBitmask
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Target has no sub-registers"
argument_list|)
expr_stmt|;
block|}
name|public
label|:
comment|/// Find a common super-register class if it exists.
comment|///
comment|/// Find a register class, SuperRC and two sub-register indices, PreA and
comment|/// PreB, such that:
comment|///
comment|///   1. PreA + SubA == PreB + SubB  (using composeSubRegIndices()), and
comment|///
comment|///   2. For all Reg in SuperRC: Reg:PreA in RCA and Reg:PreB in RCB, and
comment|///
comment|///   3. SuperRC->getSize()>= max(RCA->getSize(), RCB->getSize()).
comment|///
comment|/// SuperRC will be chosen such that no super-class of SuperRC satisfies the
comment|/// requirements, and there is no register class with a smaller spill size
comment|/// that satisfies the requirements.
comment|///
comment|/// SubA and SubB must not be 0. Use getMatchingSuperRegClass() instead.
comment|///
comment|/// Either of the PreA and PreB sub-register indices may be returned as 0. In
comment|/// that case, the returned register class will be a sub-class of the
comment|/// corresponding argument register class.
comment|///
comment|/// The function returns NULL if no register class can be found.
comment|///
specifier|const
name|TargetRegisterClass
modifier|*
name|getCommonSuperRegClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RCA
argument_list|,
name|unsigned
name|SubA
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|RCB
argument_list|,
name|unsigned
name|SubB
argument_list|,
name|unsigned
operator|&
name|PreA
argument_list|,
name|unsigned
operator|&
name|PreB
argument_list|)
decl|const
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Register Class Information
comment|//
comment|/// Register class iterators
comment|///
name|regclass_iterator
name|regclass_begin
argument_list|()
specifier|const
block|{
return|return
name|RegClassBegin
return|;
block|}
name|regclass_iterator
name|regclass_end
argument_list|()
specifier|const
block|{
return|return
name|RegClassEnd
return|;
block|}
name|iterator_range
operator|<
name|regclass_iterator
operator|>
name|regclasses
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|regclass_begin
argument_list|()
argument_list|,
name|regclass_end
argument_list|()
argument_list|)
return|;
block|}
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
comment|/// Returns the register class associated with the enumeration value.
comment|/// See class MCOperandInfo.
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
comment|/// Returns the name of the register class.
specifier|const
name|char
modifier|*
name|getRegClassName
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|Class
argument_list|)
decl|const
block|{
return|return
name|MCRegisterInfo
operator|::
name|getRegClassName
argument_list|(
name|Class
operator|->
name|MC
argument_list|)
return|;
block|}
comment|/// Find the largest common subclass of A and B.
comment|/// Return NULL if there is no common subclass.
comment|/// The common subclass should contain
comment|/// simple value type SVT if it is not the Any type.
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
argument_list|,
specifier|const
name|MVT
operator|::
name|SimpleValueType
name|SVT
operator|=
name|MVT
operator|::
name|SimpleValueType
operator|::
name|Any
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns a TargetRegisterClass used for pointer values.
comment|/// If a target supports multiple different pointer register classes,
comment|/// kind specifies which one is indicated.
name|virtual
specifier|const
name|TargetRegisterClass
modifier|*
name|getPointerRegClass
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
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
comment|/// Returns a legal register class to copy a register in the specified class
comment|/// to or from. If it is possible to copy the register directly without using
comment|/// a cross register class copy, return the specified RC. Returns NULL if it
comment|/// is not possible to copy between two registers of the specified class.
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
comment|/// Returns the largest super class of RC that is legal to use in the current
comment|/// sub-target and has the same spill size.
comment|/// The returned register class can be used to create virtual registers which
comment|/// means that all its registers can be copied and spilled.
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
argument_list|,
specifier|const
name|MachineFunction
operator|&
argument_list|)
decl|const
block|{
comment|/// The default implementation is very conservative and doesn't allow the
comment|/// register allocator to inflate register classes.
return|return
name|RC
return|;
block|}
comment|/// Return the register pressure "high water mark" for the specific register
comment|/// class. The scheduler is in high register pressure mode (for the specific
comment|/// register class) if it goes over the limit.
comment|///
comment|/// Note: this is the old register pressure model that relies on a manually
comment|/// specified representative register class per value type.
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
comment|/// Return a heuristic for the machine scheduler to compare the profitability
comment|/// of increasing one register pressure set versus another.  The scheduler
comment|/// will prefer increasing the register pressure of the set which returns
comment|/// the largest value for this function.
name|virtual
name|unsigned
name|getRegPressureSetScore
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
name|unsigned
name|PSetID
argument_list|)
decl|const
block|{
return|return
name|PSetID
return|;
block|}
comment|/// Get the weight in units of pressure for this register class.
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
comment|/// Get the weight in units of pressure for this register unit.
name|virtual
name|unsigned
name|getRegUnitWeight
argument_list|(
name|unsigned
name|RegUnit
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Get the number of dimensions of register pressure.
name|virtual
name|unsigned
name|getNumRegPressureSets
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Get the name of this register unit pressure set.
name|virtual
specifier|const
name|char
modifier|*
name|getRegPressureSetName
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Get the register unit pressure limit for this dimension.
comment|/// This limit must be adjusted dynamically for reserved registers.
name|virtual
name|unsigned
name|getRegPressureSetLimit
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
name|unsigned
name|Idx
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Get the dimensions of register pressure impacted by this register class.
comment|/// Returns a -1 terminated array of pressure set IDs.
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
comment|/// Get the dimensions of register pressure impacted by this register unit.
comment|/// Returns a -1 terminated array of pressure set IDs.
name|virtual
specifier|const
name|int
modifier|*
name|getRegUnitPressureSets
argument_list|(
name|unsigned
name|RegUnit
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Get a list of 'hint' registers that the register allocator should try
comment|/// first when allocating a physical register for the virtual register
comment|/// VirtReg. These registers are effectively moved to the front of the
comment|/// allocation order.
comment|///
comment|/// The Order argument is the allocation order for VirtReg's register class
comment|/// as returned from RegisterClassInfo::getOrder(). The hint registers must
comment|/// come from Order, and they must not be reserved.
comment|///
comment|/// The default implementation of this function can resolve
comment|/// target-independent hints provided to MRI::setRegAllocationHint with
comment|/// HintType == 0. Targets that override this function should defer to the
comment|/// default implementation if they have no reason to change the allocation
comment|/// order for VirtReg. There may be target-independent hints.
name|virtual
name|void
name|getRegAllocationHints
argument_list|(
name|unsigned
name|VirtReg
argument_list|,
name|ArrayRef
operator|<
name|MCPhysReg
operator|>
name|Order
argument_list|,
name|SmallVectorImpl
operator|<
name|MCPhysReg
operator|>
operator|&
name|Hints
argument_list|,
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
specifier|const
name|VirtRegMap
operator|*
name|VRM
operator|=
name|nullptr
argument_list|,
specifier|const
name|LiveRegMatrix
operator|*
name|Matrix
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// A callback to allow target a chance to update register allocation hints
comment|/// when a register is "changed" (e.g. coalesced) to another register.
comment|/// e.g. On ARM, some virtual registers should target register pairs,
comment|/// if one of pair is coalesced to another register, the allocation hint of
comment|/// the other half of the pair should be changed to point to the new register.
name|virtual
name|void
name|updateRegAllocHint
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
comment|/// Allow the target to reverse allocation order of local live ranges. This
comment|/// will generally allocate shorter local live ranges first. For targets with
comment|/// many registers, this could reduce regalloc compile time by a large
comment|/// factor. It is disabled by default for three reasons:
comment|/// (1) Top-down allocation is simpler and easier to debug for targets that
comment|/// don't benefit from reversing the order.
comment|/// (2) Bottom-up allocation could result in poor evicition decisions on some
comment|/// targets affecting the performance of compiled code.
comment|/// (3) Bottom-up allocation is no longer guaranteed to optimally color.
name|virtual
name|bool
name|reverseLocalAssignment
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Allow the target to override the cost of using a callee-saved register for
comment|/// the first time. Default value of 0 means we will use a callee-saved
comment|/// register if it is available.
name|virtual
name|unsigned
name|getCSRFirstUseCost
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// Returns true if the target requires (and can make use of) the register
comment|/// scavenger.
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
comment|/// Returns true if the target wants to use frame pointer based accesses to
comment|/// spill to the scavenger emergency spill slot.
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
comment|/// Returns true if the target requires post PEI scavenging of registers for
comment|/// materializing frame index constants.
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
comment|/// Returns true if the target requires using the RegScavenger directly for
comment|/// frame elimination despite using requiresFrameIndexScavenging.
name|virtual
name|bool
name|requiresFrameIndexReplacementScavenging
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
comment|/// Returns true if the target wants the LocalStackAllocation pass to be run
comment|/// and virtual base registers used for more efficient stack access.
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
comment|/// Return true if target has reserved a spill slot in the stack frame of
comment|/// the given function for the specified register. e.g. On x86, if the frame
comment|/// register is required, the first fixed stack object is reserved as its
comment|/// spill slot. This tells PEI not to create a new stack frame
comment|/// object for the given register. It should be called only after
comment|/// determineCalleeSaves().
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
comment|/// Returns true if the live-ins should be tracked after register allocation.
name|virtual
name|bool
name|trackLivenessAfterRegAlloc
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
comment|/// True if the stack can be realigned for the target.
name|virtual
name|bool
name|canRealignStack
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
comment|/// True if storage within the function requires the stack pointer to be
comment|/// aligned more than the normal calling convention calls for.
comment|/// This cannot be overriden by the target, but canRealignStack can be
comment|/// overridden.
name|bool
name|needsStackRealignment
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the offset from the referenced frame index in the instruction,
comment|/// if there is one.
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
comment|/// Returns true if the instruction's frame index reference would be better
comment|/// served by a base register other than FP or SP.
comment|/// Used by LocalStackFrameAllocation to determine which frame index
comment|/// references it should create new base registers for.
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
comment|/// Insert defining instruction(s) for BaseReg to be a pointer to FrameIdx
comment|/// before insertion point I.
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
comment|/// Resolve a frame index operand of an instruction
comment|/// to reference the indicated base register plus offset instead.
name|virtual
name|void
name|resolveFrameIndex
argument_list|(
name|MachineInstr
operator|&
name|MI
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
comment|/// Determine whether a given base register plus offset immediate is
comment|/// encodable to resolve a frame index.
name|virtual
name|bool
name|isFrameOffsetLegal
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
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
literal|"isFrameOffsetLegal does not exist on this target"
argument_list|)
expr_stmt|;
block|}
comment|/// Spill the register so it can be used by the register scavenger.
comment|/// Return true if the register was spilled, false otherwise.
comment|/// If this function does not spill the register, the scavenger
comment|/// will instead spill it to the emergency spill slot.
comment|///
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
comment|/// This method must be overriden to eliminate abstract frame indices from
comment|/// instructions which may use them. The instruction referenced by the
comment|/// iterator contains an MO_FrameIndex operand which must be eliminated by
comment|/// this method. This method may modify or replace the specified instruction,
comment|/// as long as it keeps the iterator pointing at the finished product.
comment|/// SPAdj is the SP adjustment due to call frame setup instruction.
comment|/// FIOperandNum is the FI operand number.
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
name|unsigned
name|FIOperandNum
argument_list|,
name|RegScavenger
operator|*
name|RS
operator|=
name|nullptr
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Return the assembly name for \p Reg.
name|virtual
name|StringRef
name|getRegAsmName
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
comment|// FIXME: We are assuming that the assembly name is equal to the TableGen
comment|// name converted to lower case
comment|//
comment|// The TableGen name is the name of the definition for this register in the
comment|// target's tablegen files.  For example, the TableGen name of
comment|// def EAX : Register<...>; is "EAX"
return|return
name|StringRef
argument_list|(
name|getName
argument_list|(
name|Reg
argument_list|)
argument_list|)
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|/// Subtarget Hooks
comment|/// \brief SrcRC and DstRC will be morphed into NewRC if this returns true.
name|virtual
name|bool
name|shouldCoalesce
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|SrcRC
argument_list|,
name|unsigned
name|SubReg
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|DstRC
argument_list|,
name|unsigned
name|DstSubReg
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|NewRC
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|/// Debug information queries.
comment|/// getFrameRegister - This method should return the register used as a base
comment|/// for values allocated in the current stack frame.
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
comment|/// Mark a register and all its aliases as reserved in the given set.
name|void
name|markSuperRegs
argument_list|(
name|BitVector
operator|&
name|RegisterSet
argument_list|,
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns true if for every register in the set all super registers are part
comment|/// of the set as well.
name|bool
name|checkAllSuperRegsMarked
argument_list|(
specifier|const
name|BitVector
operator|&
name|RegisterSet
argument_list|,
name|ArrayRef
operator|<
name|MCPhysReg
operator|>
name|Exceptions
operator|=
name|ArrayRef
operator|<
name|MCPhysReg
operator|>
operator|(
operator|)
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                           SuperRegClassIterator
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Iterate over the possible super-registers for a given register class. The
end_comment

begin_comment
comment|// iterator will visit a list of pairs (Idx, Mask) corresponding to the
end_comment

begin_comment
comment|// possible classes of super-registers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Each bit mask will have at least one set bit, and each set bit in Mask
end_comment

begin_comment
comment|// corresponds to a SuperRC such that:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   For all Reg in SuperRC: Reg:Idx is in RC.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The iterator can include (O, RC->getSubClassMask()) as the first entry which
end_comment

begin_comment
comment|// also satisfies the above requirement, assuming Reg:0 == Reg.
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|SuperRegClassIterator
block|{
specifier|const
name|unsigned
name|RCMaskWords
decl_stmt|;
name|unsigned
name|SubReg
decl_stmt|;
specifier|const
name|uint16_t
modifier|*
name|Idx
decl_stmt|;
specifier|const
name|uint32_t
modifier|*
name|Mask
decl_stmt|;
name|public
label|:
comment|/// Create a SuperRegClassIterator that visits all the super-register classes
comment|/// of RC. When IncludeSelf is set, also include the (0, sub-classes) entry.
name|SuperRegClassIterator
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|bool IncludeSelf = false
argument_list|)
block|:
name|RCMaskWords
argument_list|(
operator|(
name|TRI
operator|->
name|getNumRegClasses
argument_list|()
operator|+
literal|31
operator|)
operator|/
literal|32
argument_list|)
operator|,
name|SubReg
argument_list|(
literal|0
argument_list|)
operator|,
name|Idx
argument_list|(
name|RC
operator|->
name|getSuperRegIndices
argument_list|()
argument_list|)
operator|,
name|Mask
argument_list|(
argument|RC->getSubClassMask()
argument_list|)
block|{
if|if
condition|(
operator|!
name|IncludeSelf
condition|)
operator|++
operator|*
name|this
expr_stmt|;
block|}
comment|/// Returns true if this iterator is still pointing at a valid entry.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Idx
return|;
block|}
comment|/// Returns the current sub-register index.
name|unsigned
name|getSubReg
argument_list|()
specifier|const
block|{
return|return
name|SubReg
return|;
block|}
comment|/// Returns the bit mask of register classes that getSubReg() projects into
comment|/// RC.
comment|/// See TargetRegisterClass::getSubClassMask() for how to use it.
specifier|const
name|uint32_t
operator|*
name|getMask
argument_list|()
specifier|const
block|{
return|return
name|Mask
return|;
block|}
comment|/// Advance iterator to the next entry.
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
literal|"Cannot move iterator past end."
argument_list|)
block|;
name|Mask
operator|+=
name|RCMaskWords
block|;
name|SubReg
operator|=
operator|*
name|Idx
operator|++
block|;
if|if
condition|(
operator|!
name|SubReg
condition|)
name|Idx
operator|=
name|nullptr
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                           BitMaskClassIterator
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// This class encapuslates the logic to iterate over bitmask returned by
end_comment

begin_comment
comment|/// the various RegClass related APIs.
end_comment

begin_comment
comment|/// E.g., this class can be used to iterate over the subclasses provided by
end_comment

begin_comment
comment|/// TargetRegisterClass::getSubClassMask or SuperRegClassIterator::getMask.
end_comment

begin_decl_stmt
name|class
name|BitMaskClassIterator
block|{
comment|/// Total number of register classes.
specifier|const
name|unsigned
name|NumRegClasses
decl_stmt|;
comment|/// Base index of CurrentChunk.
comment|/// In other words, the number of bit we read to get at the
comment|/// beginning of that chunck.
name|unsigned
name|Base
decl_stmt|;
comment|/// Adjust base index of CurrentChunk.
comment|/// Base index + how many bit we read within CurrentChunk.
name|unsigned
name|Idx
decl_stmt|;
comment|/// Current register class ID.
name|unsigned
name|ID
decl_stmt|;
comment|/// Mask we are iterating over.
specifier|const
name|uint32_t
modifier|*
name|Mask
decl_stmt|;
comment|/// Current chunk of the Mask we are traversing.
name|uint32_t
name|CurrentChunk
decl_stmt|;
comment|/// Move ID to the next set bit.
name|void
name|moveToNextID
parameter_list|()
block|{
comment|// If the current chunk of memory is empty, move to the next one,
comment|// while making sure we do not go pass the number of register
comment|// classes.
while|while
condition|(
operator|!
name|CurrentChunk
condition|)
block|{
comment|// Move to the next chunk.
name|Base
operator|+=
literal|32
expr_stmt|;
if|if
condition|(
name|Base
operator|>=
name|NumRegClasses
condition|)
block|{
name|ID
operator|=
name|NumRegClasses
expr_stmt|;
return|return;
block|}
name|CurrentChunk
operator|=
operator|*
operator|++
name|Mask
expr_stmt|;
name|Idx
operator|=
name|Base
expr_stmt|;
block|}
comment|// Otherwise look for the first bit set from the right
comment|// (representation of the class ID is big endian).
comment|// See getSubClassMask for more details on the representation.
name|unsigned
name|Offset
init|=
name|countTrailingZeros
argument_list|(
name|CurrentChunk
argument_list|)
decl_stmt|;
comment|// Add the Offset to the adjusted base number of this chunk: Idx.
comment|// This is the ID of the register class.
name|ID
operator|=
name|Idx
operator|+
name|Offset
expr_stmt|;
comment|// Consume the zeros, if any, and the bit we just read
comment|// so that we are at the right spot for the next call.
comment|// Do not do Offset + 1 because Offset may be 31 and 32
comment|// will be UB for the shift, though in that case we could
comment|// have make the chunk being equal to 0, but that would
comment|// have introduced a if statement.
name|moveNBits
argument_list|(
name|Offset
argument_list|)
expr_stmt|;
name|moveNBits
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/// Move \p NumBits Bits forward in CurrentChunk.
name|void
name|moveNBits
parameter_list|(
name|unsigned
name|NumBits
parameter_list|)
block|{
name|assert
argument_list|(
name|NumBits
operator|<
literal|32
operator|&&
literal|"Undefined behavior spotted!"
argument_list|)
expr_stmt|;
comment|// Consume the bit we read for the next call.
name|CurrentChunk
operator|>>=
name|NumBits
expr_stmt|;
comment|// Adjust the base for the chunk.
name|Idx
operator|+=
name|NumBits
expr_stmt|;
block|}
name|public
label|:
comment|/// Create a BitMaskClassIterator that visits all the register classes
comment|/// represented by \p Mask.
comment|///
comment|/// \pre \p Mask != nullptr
name|BitMaskClassIterator
argument_list|(
specifier|const
name|uint32_t
operator|*
name|Mask
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|)
operator|:
name|NumRegClasses
argument_list|(
name|TRI
operator|.
name|getNumRegClasses
argument_list|()
argument_list|)
operator|,
name|Base
argument_list|(
literal|0
argument_list|)
operator|,
name|Idx
argument_list|(
literal|0
argument_list|)
operator|,
name|ID
argument_list|(
literal|0
argument_list|)
operator|,
name|Mask
argument_list|(
name|Mask
argument_list|)
operator|,
name|CurrentChunk
argument_list|(
argument|*Mask
argument_list|)
block|{
comment|// Move to the first ID.
name|moveToNextID
argument_list|()
block|;   }
comment|/// Returns true if this iterator is still pointing at a valid entry.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|getID
argument_list|()
operator|!=
name|NumRegClasses
return|;
block|}
comment|/// Returns the current register class ID.
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
comment|/// Advance iterator to the next entry.
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
literal|"Cannot move iterator past end."
argument_list|)
block|;
name|moveToNextID
argument_list|()
block|;   }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
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

begin_function_decl
name|Printable
name|PrintReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
init|=
name|nullptr
parameter_list|,
name|unsigned
name|SubRegIdx
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Create Printable object to print register units on a \ref raw_ostream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Register units are named after their root registers:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   AL      - Single root.
end_comment

begin_comment
comment|///   FP0~ST7 - Dual roots.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Usage: OS<< PrintRegUnit(Unit, TRI)<< '\n';
end_comment

begin_function_decl
name|Printable
name|PrintRegUnit
parameter_list|(
name|unsigned
name|Unit
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Create Printable object to print virtual registers and physical
end_comment

begin_comment
comment|/// registers on a \ref raw_ostream.
end_comment

begin_function_decl
name|Printable
name|PrintVRegOrUnit
parameter_list|(
name|unsigned
name|VRegOrUnit
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

