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
file|"llvm/ADT/DenseSet.h"
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
name|MachineMove
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
comment|/// TargetRegisterDesc - This record contains all of the information known about
comment|/// a particular register.  The Overlaps field contains a pointer to a zero
comment|/// terminated array of registers that this register aliases, starting with
comment|/// itself. This is needed for architectures like X86 which have AL alias AX
comment|/// alias EAX. The SubRegs field is a zero terminated array of registers that
comment|/// are sub-registers of the specific register, e.g. AL, AH are sub-registers of
comment|/// AX. The SuperRegs field is a zero terminated array of registers that are
comment|/// super-registers of the specific register, e.g. RAX, EAX, are super-registers
comment|/// of AX.
comment|///
struct|struct
name|TargetRegisterDesc
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|// Printable name for the reg (for debugging)
specifier|const
name|unsigned
modifier|*
name|Overlaps
decl_stmt|;
comment|// Overlapping registers, described above
specifier|const
name|unsigned
modifier|*
name|SubRegs
decl_stmt|;
comment|// Sub-register set, described above
specifier|const
name|unsigned
modifier|*
name|SuperRegs
decl_stmt|;
comment|// Super-register set, described above
block|}
struct|;
name|class
name|TargetRegisterClass
block|{
name|public
label|:
typedef|typedef
specifier|const
name|unsigned
modifier|*
name|iterator
typedef|;
typedef|typedef
specifier|const
name|unsigned
modifier|*
name|const_iterator
typedef|;
typedef|typedef
specifier|const
name|EVT
modifier|*
name|vt_iterator
typedef|;
typedef|typedef
specifier|const
name|TargetRegisterClass
modifier|*
specifier|const
modifier|*
name|sc_iterator
typedef|;
name|private
label|:
name|unsigned
name|ID
decl_stmt|;
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
specifier|const
name|vt_iterator
name|VTs
decl_stmt|;
specifier|const
name|sc_iterator
name|SubClasses
decl_stmt|;
specifier|const
name|sc_iterator
name|SuperClasses
decl_stmt|;
specifier|const
name|sc_iterator
name|SubRegClasses
decl_stmt|;
specifier|const
name|sc_iterator
name|SuperRegClasses
decl_stmt|;
specifier|const
name|unsigned
name|RegSize
decl_stmt|,
name|Alignment
decl_stmt|;
comment|// Size& Alignment of register in bytes
specifier|const
name|int
name|CopyCost
decl_stmt|;
specifier|const
name|iterator
name|RegsBegin
decl_stmt|,
name|RegsEnd
decl_stmt|;
name|DenseSet
operator|<
name|unsigned
operator|>
name|RegSet
expr_stmt|;
name|public
label|:
name|TargetRegisterClass
argument_list|(
argument|unsigned id
argument_list|,
argument|const char *name
argument_list|,
argument|const EVT *vts
argument_list|,
argument|const TargetRegisterClass * const *subcs
argument_list|,
argument|const TargetRegisterClass * const *supcs
argument_list|,
argument|const TargetRegisterClass * const *subregcs
argument_list|,
argument|const TargetRegisterClass * const *superregcs
argument_list|,
argument|unsigned RS
argument_list|,
argument|unsigned Al
argument_list|,
argument|int CC
argument_list|,
argument|iterator RB
argument_list|,
argument|iterator RE
argument_list|)
block|:
name|ID
argument_list|(
name|id
argument_list|)
operator|,
name|Name
argument_list|(
name|name
argument_list|)
operator|,
name|VTs
argument_list|(
name|vts
argument_list|)
operator|,
name|SubClasses
argument_list|(
name|subcs
argument_list|)
operator|,
name|SuperClasses
argument_list|(
name|supcs
argument_list|)
operator|,
name|SubRegClasses
argument_list|(
name|subregcs
argument_list|)
operator|,
name|SuperRegClasses
argument_list|(
name|superregcs
argument_list|)
operator|,
name|RegSize
argument_list|(
name|RS
argument_list|)
operator|,
name|Alignment
argument_list|(
name|Al
argument_list|)
operator|,
name|CopyCost
argument_list|(
name|CC
argument_list|)
operator|,
name|RegsBegin
argument_list|(
name|RB
argument_list|)
operator|,
name|RegsEnd
argument_list|(
argument|RE
argument_list|)
block|{
for|for
control|(
name|iterator
name|I
init|=
name|RegsBegin
init|,
name|E
init|=
name|RegsEnd
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|RegSet
operator|.
name|insert
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
name|virtual
operator|~
name|TargetRegisterClass
argument_list|()
block|{}
comment|// Allow subclasses
comment|/// getID() - Return the register class ID number.
comment|///
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
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
name|Name
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
name|RegsBegin
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|RegsEnd
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
call|(
name|unsigned
call|)
argument_list|(
name|RegsEnd
operator|-
name|RegsBegin
argument_list|)
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
name|assert
argument_list|(
name|i
operator|<
name|getNumRegs
argument_list|()
operator|&&
literal|"Register number out of range!"
argument_list|)
expr_stmt|;
return|return
name|RegsBegin
index|[
name|i
index|]
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
name|RegSet
operator|.
name|count
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
name|contains
argument_list|(
name|Reg1
argument_list|)
operator|&&
name|contains
argument_list|(
name|Reg2
argument_list|)
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
name|VTs
index|[
name|i
index|]
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
comment|/// subregclasses_begin / subregclasses_end - Loop over all of
comment|/// the subreg register classes of this register class.
name|sc_iterator
name|subregclasses_begin
argument_list|()
specifier|const
block|{
return|return
name|SubRegClasses
return|;
block|}
name|sc_iterator
name|subregclasses_end
argument_list|()
specifier|const
block|{
name|sc_iterator
name|I
operator|=
name|SubRegClasses
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
comment|/// getSubRegisterRegClass - Return the register class of subregisters with
end_comment

begin_comment
comment|/// index SubIdx, or NULL if no such class exists.
end_comment

begin_decl_stmt
specifier|const
name|TargetRegisterClass
modifier|*
name|getSubRegisterRegClass
argument_list|(
name|unsigned
name|SubIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|SubIdx
operator|>
literal|0
operator|&&
literal|"Invalid subregister index"
argument_list|)
expr_stmt|;
return|return
name|SubRegClasses
index|[
name|SubIdx
operator|-
literal|1
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|/// superregclasses_begin / superregclasses_end - Loop over all of
end_comment

begin_comment
comment|/// the superreg register classes of this register class.
end_comment

begin_expr_stmt
name|sc_iterator
name|superregclasses_begin
argument_list|()
specifier|const
block|{
return|return
name|SuperRegClasses
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_return
return|return
name|I
return|;
end_return

begin_comment
unit|}
comment|/// hasSubClass - return true if the specified TargetRegisterClass
end_comment

begin_comment
comment|/// is a proper subset of this TargetRegisterClass.
end_comment

begin_macro
unit|bool
name|hasSubClass
argument_list|(
argument|const TargetRegisterClass *cs
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|SubClasses
index|[
name|i
index|]
operator|!=
name|NULL
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|SubClasses
index|[
name|i
index|]
operator|==
name|cs
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// subclasses_begin / subclasses_end - Loop over all of the classes
end_comment

begin_comment
comment|/// that are proper subsets of this register class.
end_comment

begin_macro
unit|sc_iterator
name|subclasses_begin
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|SubClasses
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|sc_iterator
name|subclasses_end
argument_list|()
specifier|const
block|{
name|sc_iterator
name|I
operator|=
name|SubClasses
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
end_expr_stmt

begin_return
return|return
name|I
return|;
end_return

begin_comment
unit|}
comment|/// hasSuperClass - return true if the specified TargetRegisterClass is a
end_comment

begin_comment
comment|/// proper superset of this TargetRegisterClass.
end_comment

begin_macro
unit|bool
name|hasSuperClass
argument_list|(
argument|const TargetRegisterClass *cs
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|SuperClasses
index|[
name|i
index|]
operator|!=
name|NULL
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|SuperClasses
index|[
name|i
index|]
operator|==
name|cs
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// superclasses_begin / superclasses_end - Loop over all of the classes
end_comment

begin_comment
comment|/// that are proper supersets of this register class.
end_comment

begin_macro
unit|sc_iterator
name|superclasses_begin
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|SuperClasses
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|sc_iterator
name|superclasses_end
argument_list|()
specifier|const
block|{
name|sc_iterator
name|I
operator|=
name|SuperClasses
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
end_expr_stmt

begin_return
return|return
name|I
return|;
end_return

begin_comment
unit|}
comment|/// isASubClass - return true if this TargetRegisterClass is a subset
end_comment

begin_comment
comment|/// class of at least one other TargetRegisterClass.
end_comment

begin_macro
unit|bool
name|isASubClass
argument_list|()
end_macro

begin_expr_stmt
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
comment|/// allocation_order_begin/end - These methods define a range of registers
end_comment

begin_comment
comment|/// which specify the registers in this class that are valid to register
end_comment

begin_comment
comment|/// allocate, and the preferred order to allocate them in.  For example,
end_comment

begin_comment
comment|/// callee saved registers should be at the end of the list, because it is
end_comment

begin_comment
comment|/// cheaper to allocate caller saved registers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These methods take a MachineFunction argument, which can be used to tune
end_comment

begin_comment
comment|/// the allocatable registers based on the characteristics of the function,
end_comment

begin_comment
comment|/// subtarget, or other criteria.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Register allocators should account for the fact that an allocation
end_comment

begin_comment
comment|/// order iterator may return a reserved register and always check
end_comment

begin_comment
comment|/// if the register is allocatable (getAllocatableSet()) before using it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// By default, these methods return all registers in the class.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
name|iterator
name|allocation_order_begin
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|begin
argument_list|()
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|virtual
name|iterator
name|allocation_order_end
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|end
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getSize - Return the size of the register in bytes, which is also the size
end_comment

begin_comment
comment|/// of a stack slot allocated to hold a spilled copy of this register.
end_comment

begin_expr_stmt
name|unsigned
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|RegSize
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getAlignment - Return the minimum required alignment for a register of
end_comment

begin_comment
comment|/// this class.
end_comment

begin_expr_stmt
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getCopyCost - Return the cost of copying a value between two registers in
end_comment

begin_comment
comment|/// this class. A negative number means the register class is very expensive
end_comment

begin_comment
comment|/// to copy e.g. status flag register classes.
end_comment

begin_expr_stmt
name|int
name|getCopyCost
argument_list|()
specifier|const
block|{
return|return
name|CopyCost
return|;
block|}
end_expr_stmt

begin_comment
unit|};
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
block|{
name|protected
label|:
specifier|const
name|unsigned
modifier|*
name|SubregHash
decl_stmt|;
specifier|const
name|unsigned
name|SubregHashSize
decl_stmt|;
specifier|const
name|unsigned
modifier|*
name|AliasesHash
decl_stmt|;
specifier|const
name|unsigned
name|AliasesHashSize
decl_stmt|;
name|public
label|:
typedef|typedef
specifier|const
name|TargetRegisterClass
modifier|*
specifier|const
modifier|*
name|regclass_iterator
typedef|;
name|private
label|:
specifier|const
name|TargetRegisterDesc
modifier|*
name|Desc
decl_stmt|;
comment|// Pointer to the descriptor array
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|SubRegIndexNames
decl_stmt|;
comment|// Names of subreg indexes.
name|unsigned
name|NumRegs
decl_stmt|;
comment|// Number of entries in the array
name|regclass_iterator
name|RegClassBegin
decl_stmt|,
name|RegClassEnd
decl_stmt|;
comment|// List of regclasses
name|int
name|CallFrameSetupOpcode
decl_stmt|,
name|CallFrameDestroyOpcode
decl_stmt|;
name|protected
label|:
name|TargetRegisterInfo
argument_list|(
argument|const TargetRegisterDesc *D
argument_list|,
argument|unsigned NR
argument_list|,
argument|regclass_iterator RegClassBegin
argument_list|,
argument|regclass_iterator RegClassEnd
argument_list|,
argument|const char *const *subregindexnames
argument_list|,
argument|int CallFrameSetupOpcode = -
literal|1
argument_list|,
argument|int CallFrameDestroyOpcode = -
literal|1
argument_list|,
argument|const unsigned* subregs =
literal|0
argument_list|,
argument|const unsigned subregsize =
literal|0
argument_list|,
argument|const unsigned* aliases =
literal|0
argument_list|,
argument|const unsigned aliasessize =
literal|0
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
comment|/// stackSlot2Index - Compute the frame index from a register value
comment|/// representing a stack slot.
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
comment|/// index2StackSlot - Convert a non-negative frame index to a stack slot
comment|/// register value.
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
comment|/// isPhysicalRegister - Return true if the specified register number is in
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
comment|/// isVirtualRegister - Return true if the specified register number is in
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
comment|/// virtReg2Index - Convert a virtual register number to a 0-based index.
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
operator|-
operator|(
literal|1u
operator|<<
literal|31
operator|)
return|;
block|}
comment|/// index2VirtReg - Convert a 0-based index to a virtual register number.
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
operator|+
operator|(
literal|1u
operator|<<
literal|31
operator|)
return|;
block|}
comment|/// getMinimalPhysRegClass - Returns the Register Class of a physical
comment|/// register of the given type, picking the most sub register class of
comment|/// the right type that contains this physreg.
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
comment|/// getAllocatableSet - Returns a bitset indexed by register number
comment|/// indicating if a register is allocatable or not. If a register class is
comment|/// specified, returns the subset for the class.
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
specifier|const
name|TargetRegisterDesc
modifier|&
name|operator
index|[]
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|RegNo
operator|<
name|NumRegs
operator|&&
literal|"Attempting to access record for invalid register number!"
argument_list|)
expr_stmt|;
return|return
name|Desc
index|[
name|RegNo
index|]
return|;
block|}
comment|/// Provide a get method, equivalent to [], but more useful if we have a
comment|/// pointer to this object.
comment|///
specifier|const
name|TargetRegisterDesc
modifier|&
name|get
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|operator
index|[]
operator|(
name|RegNo
operator|)
return|;
block|}
comment|/// getAliasSet - Return the set of registers aliased by the specified
comment|/// register, or a null list of there are none.  The list returned is zero
comment|/// terminated.
comment|///
specifier|const
name|unsigned
modifier|*
name|getAliasSet
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
comment|// The Overlaps set always begins with Reg itself.
return|return
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|Overlaps
operator|+
literal|1
return|;
block|}
comment|/// getOverlaps - Return a list of registers that overlap Reg, including
comment|/// itself. This is the same as the alias set except Reg is included in the
comment|/// list.
comment|/// These are exactly the registers in { x | regsOverlap(x, Reg) }.
comment|///
specifier|const
name|unsigned
modifier|*
name|getOverlaps
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|Overlaps
return|;
block|}
comment|/// getSubRegisters - Return the list of registers that are sub-registers of
comment|/// the specified register, or a null list of there are none. The list
comment|/// returned is zero terminated and sorted according to super-sub register
comment|/// relations. e.g. X86::RAX's sub-register list is EAX, AX, AL, AH.
comment|///
specifier|const
name|unsigned
modifier|*
name|getSubRegisters
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|SubRegs
return|;
block|}
comment|/// getSuperRegisters - Return the list of registers that are super-registers
comment|/// of the specified register, or a null list of there are none. The list
comment|/// returned is zero terminated and sorted according to super-sub register
comment|/// relations. e.g. X86::AL's super-register list is RAX, EAX, AX.
comment|///
specifier|const
name|unsigned
modifier|*
name|getSuperRegisters
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|SuperRegs
return|;
block|}
comment|/// getName - Return the human-readable symbolic target-specific name for the
comment|/// specified physical register.
specifier|const
name|char
modifier|*
name|getName
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|Name
return|;
block|}
comment|/// getNumRegs - Return the number of registers this target has (useful for
comment|/// sizing arrays holding per register information)
name|unsigned
name|getNumRegs
argument_list|()
specifier|const
block|{
return|return
name|NumRegs
return|;
block|}
comment|/// getSubRegIndexName - Return the human-readable symbolic target-specific
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
comment|/// regsOverlap - Returns true if the two registers are equal or alias each
comment|/// other. The registers may be virtual register.
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
comment|// regA and regB are distinct physical registers. Do they alias?
name|size_t
name|index
init|=
operator|(
name|regA
operator|+
name|regB
operator|*
literal|37
operator|)
operator|&
operator|(
name|AliasesHashSize
operator|-
literal|1
operator|)
decl_stmt|;
name|unsigned
name|ProbeAmt
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|AliasesHash
index|[
name|index
operator|*
literal|2
index|]
operator|!=
literal|0
operator|&&
name|AliasesHash
index|[
name|index
operator|*
literal|2
operator|+
literal|1
index|]
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|AliasesHash
index|[
name|index
operator|*
literal|2
index|]
operator|==
name|regA
operator|&&
name|AliasesHash
index|[
name|index
operator|*
literal|2
operator|+
literal|1
index|]
operator|==
name|regB
condition|)
return|return
name|true
return|;
name|index
operator|=
operator|(
name|index
operator|+
name|ProbeAmt
operator|)
operator|&
operator|(
name|AliasesHashSize
operator|-
literal|1
operator|)
expr_stmt|;
name|ProbeAmt
operator|+=
literal|2
expr_stmt|;
block|}
return|return
name|false
return|;
block|}
comment|/// isSubRegister - Returns true if regB is a sub-register of regA.
comment|///
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
comment|// SubregHash is a simple quadratically probed hash table.
name|size_t
name|index
init|=
operator|(
name|regA
operator|+
name|regB
operator|*
literal|37
operator|)
operator|&
operator|(
name|SubregHashSize
operator|-
literal|1
operator|)
decl_stmt|;
name|unsigned
name|ProbeAmt
init|=
literal|2
decl_stmt|;
while|while
condition|(
name|SubregHash
index|[
name|index
operator|*
literal|2
index|]
operator|!=
literal|0
operator|&&
name|SubregHash
index|[
name|index
operator|*
literal|2
operator|+
literal|1
index|]
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|SubregHash
index|[
name|index
operator|*
literal|2
index|]
operator|==
name|regA
operator|&&
name|SubregHash
index|[
name|index
operator|*
literal|2
operator|+
literal|1
index|]
operator|==
name|regB
condition|)
return|return
name|true
return|;
name|index
operator|=
operator|(
name|index
operator|+
name|ProbeAmt
operator|)
operator|&
operator|(
name|SubregHashSize
operator|-
literal|1
operator|)
expr_stmt|;
name|ProbeAmt
operator|+=
literal|2
expr_stmt|;
block|}
return|return
name|false
return|;
block|}
comment|/// isSuperRegister - Returns true if regB is a super-register of regA.
comment|///
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
return|return
name|isSubRegister
argument_list|(
name|regB
argument_list|,
name|regA
argument_list|)
return|;
block|}
comment|/// getCalleeSavedRegs - Return a null-terminated list of all of the
comment|/// callee saved registers on this target. The register should be in the
comment|/// order of desired callee-save stack frame offset. The first register is
comment|/// closed to the incoming stack pointer if stack grows down, and vice versa.
name|virtual
specifier|const
name|unsigned
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
comment|/// getReservedRegs - Returns a bitset indexed by physical register number
comment|/// indicating if a register is a special register that has particular uses
comment|/// and should be considered unavailable at all times, e.g. SP, RA. This is
comment|/// used by register scavenger to determine what registers are free.
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
comment|/// getSubReg - Returns the physical register number of sub-register "Index"
comment|/// for physical register RegNo. Return zero if the sub-register does not
comment|/// exist.
name|virtual
name|unsigned
name|getSubReg
argument_list|(
name|unsigned
name|RegNo
argument_list|,
name|unsigned
name|Index
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// getSubRegIndex - For a given register pair, return the sub-register index
comment|/// if the second register is a sub-register of the first. Return zero
comment|/// otherwise.
name|virtual
name|unsigned
name|getSubRegIndex
argument_list|(
name|unsigned
name|RegNo
argument_list|,
name|unsigned
name|SubRegNo
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// getMatchingSuperReg - Return a super-register of the specified register
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
for|for
control|(
specifier|const
name|unsigned
modifier|*
name|SRs
init|=
name|getSuperRegisters
argument_list|(
name|Reg
argument_list|)
init|;
name|unsigned
name|SR
operator|=
operator|*
name|SRs
condition|;
operator|++
name|SRs
control|)
if|if
condition|(
name|Reg
operator|==
name|getSubReg
argument_list|(
name|SR
argument_list|,
name|SubIdx
argument_list|)
operator|&&
name|RC
operator|->
name|contains
argument_list|(
name|SR
argument_list|)
condition|)
return|return
name|SR
return|;
return|return
literal|0
return|;
block|}
comment|/// canCombineSubRegIndices - Given a register class and a list of
comment|/// subregister indices, return true if it's possible to combine the
comment|/// subregister indices into one that corresponds to a larger
comment|/// subregister. Return the new subregister index by reference. Note the
comment|/// new index may be zero if the given subregisters can be combined to
comment|/// form the whole register.
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
comment|/// getMatchingSuperRegClass - Return a subclass of the specified register
comment|/// class A so that each register in it has a sub-register of the
comment|/// specified sub-register index which is in the specified register class B.
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
block|{
return|return
literal|0
return|;
block|}
comment|/// composeSubRegIndices - Return the subregister index you get from composing
comment|/// two subregister indices.
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
comment|/// getRegClass - Returns the register class associated with the enumeration
comment|/// value.  See class TargetOperandInfo.
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
comment|/// getPointerRegClass - Returns a TargetRegisterClass used for pointer
comment|/// values.  If a target supports multiple different pointer register classes,
comment|/// kind specifies which one is indicated.
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
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement getPointerRegClass!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|// Must return a value in order to compile with VS 2005
block|}
comment|/// getCrossCopyRegClass - Returns a legal register class to copy a register
comment|/// in the specified class to or from. Returns NULL if it is possible to copy
comment|/// between a two registers of the specified class.
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
name|NULL
return|;
block|}
comment|/// getAllocationOrder - Returns the register allocation order for a specified
comment|/// register class in the form of a pair of TargetRegisterClass iterators.
name|virtual
name|std
operator|::
name|pair
operator|<
name|TargetRegisterClass
operator|::
name|iterator
operator|,
name|TargetRegisterClass
operator|::
name|iterator
operator|>
name|getAllocationOrder
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
name|std
operator|::
name|make_pair
argument_list|(
name|RC
operator|->
name|allocation_order_begin
argument_list|(
name|MF
argument_list|)
argument_list|,
name|RC
operator|->
name|allocation_order_end
argument_list|(
name|MF
argument_list|)
argument_list|)
return|;
block|}
comment|/// ResolveRegAllocHint - Resolves the specified register allocation hint
comment|/// to a physical register. Returns the physical register if it is successful.
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
comment|/// UpdateRegAllocHint - A callback to allow target a chance to update
comment|/// register allocation hints when a register is "changed" (e.g. coalesced)
comment|/// to another register. e.g. On ARM, some virtual registers should target
comment|/// register pairs, if one of pair is coalesced to another register, the
comment|/// allocation hint of the other half of the pair should be changed to point
comment|/// to the new register.
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
comment|/// requiresRegisterScavenging - returns true if the target requires (and can
comment|/// make use of) the register scavenger.
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
comment|/// requiresFrameIndexScavenging - returns true if the target requires post
comment|/// PEI scavenging of registers for materializing frame index constants.
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
comment|/// requiresVirtualBaseRegisters - Returns true if the target wants the
comment|/// LocalStackAllocation pass to be run and virtual base registers
comment|/// used for more efficient stack access.
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
comment|/// hasReservedSpillSlot - Return true if target has reserved a spill slot in
comment|/// the stack frame of the given function for the specified register. e.g. On
comment|/// x86, if the frame register is required, the first fixed stack object is
comment|/// reserved as its spill slot. This tells PEI not to create a new stack frame
comment|/// object for the given register. It should be called only after
comment|/// processFunctionBeforeCalleeSavedScan().
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
comment|/// needsStackRealignment - true if storage within the function requires the
comment|/// stack pointer to be aligned more than the normal calling convention calls
comment|/// for.
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
comment|/// getFrameIndexInstrOffset - Get the offset from the referenced frame
comment|/// index in the instruction, if there is one.
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
comment|/// needsFrameBaseReg - Returns true if the instruction's frame index
comment|/// reference would be better served by a base register other than FP
comment|/// or SP. Used by LocalStackFrameAllocation to determine which frame index
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
comment|/// materializeFrameBaseRegister - Insert defining instruction(s) for
comment|/// BaseReg to be a pointer to FrameIdx before insertion point I.
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
name|assert
argument_list|(
literal|0
operator|&&
literal|"materializeFrameBaseRegister does not exist on this target"
argument_list|)
expr_stmt|;
block|}
comment|/// resolveFrameIndex - Resolve a frame index operand of an instruction
comment|/// to reference the indicated base register plus offset instead.
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
name|assert
argument_list|(
literal|0
operator|&&
literal|"resolveFrameIndex does not exist on this target"
argument_list|)
expr_stmt|;
block|}
comment|/// isFrameOffsetLegal - Determine whether a given offset immediate is
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
name|int64_t
name|Offset
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"isFrameOffsetLegal does not exist on this target"
argument_list|)
expr_stmt|;
return|return
name|false
return|;
comment|// Must return a value in order to compile with VS 2005
block|}
comment|/// getCallFrameSetup/DestroyOpcode - These methods return the opcode of the
comment|/// frame setup/destroy instructions if they exist (-1 otherwise).  Some
comment|/// targets use pseudo instructions in order to abstract away the difference
comment|/// between operating with a frame pointer and operating without, through the
comment|/// use of these two instructions.
comment|///
name|int
name|getCallFrameSetupOpcode
argument_list|()
specifier|const
block|{
return|return
name|CallFrameSetupOpcode
return|;
block|}
name|int
name|getCallFrameDestroyOpcode
argument_list|()
specifier|const
block|{
return|return
name|CallFrameDestroyOpcode
return|;
block|}
comment|/// eliminateCallFramePseudoInstr - This method is called during prolog/epilog
comment|/// code insertion to eliminate call frame setup and destroy pseudo
comment|/// instructions (but only if the Target is using them).  It is responsible
comment|/// for eliminating these instructions, replacing them with concrete
comment|/// instructions.  This method need only be implemented if using call frame
comment|/// setup/destroy pseudo instructions.
comment|///
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
name|assert
argument_list|(
name|getCallFrameSetupOpcode
argument_list|()
operator|==
operator|-
literal|1
operator|&&
name|getCallFrameDestroyOpcode
argument_list|()
operator|==
operator|-
literal|1
operator|&&
literal|"eliminateCallFramePseudoInstr must be implemented if using"
literal|" call frame setup/destroy pseudo instructions!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|&&
literal|"Call Frame Pseudo Instructions do not exist on this target!"
argument_list|)
expr_stmt|;
block|}
comment|/// saveScavengerRegister - Spill the register so it can be used by the
comment|/// register scavenger. Return true if the register was spilled, false
comment|/// otherwise. If this function does not spill the register, the scavenger
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
comment|/// eliminateFrameIndex - This method must be overriden to eliminate abstract
comment|/// frame indices from instructions which may use them.  The instruction
comment|/// referenced by the iterator contains an MO_FrameIndex operand which must be
comment|/// eliminated by this method.  This method may modify or replace the
comment|/// specified instruction, as long as it keeps the iterator pointing at the
comment|/// finished product. SPAdj is the SP adjustment due to call frame setup
comment|/// instruction.
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
comment|//===--------------------------------------------------------------------===//
comment|/// Debug information queries.
comment|/// getDwarfRegNum - Map a target register to an equivalent dwarf register
comment|/// number.  Returns -1 if there is no equivalent value.  The second
comment|/// parameter allows targets to use different numberings for EH info and
comment|/// debugging info.
name|virtual
name|int
name|getDwarfRegNum
argument_list|(
name|unsigned
name|RegNum
argument_list|,
name|bool
name|isEH
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
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
comment|/// getRARegister - This method should return the register where the return
comment|/// address can be found.
name|virtual
name|unsigned
name|getRARegister
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
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
comment|/// getCommonSubClass - find the largest common subclass of A and B. Return NULL
end_comment

begin_comment
comment|/// if there is no common subclass.
end_comment

begin_function_decl
specifier|const
name|TargetRegisterClass
modifier|*
name|getCommonSubClass
parameter_list|(
specifier|const
name|TargetRegisterClass
modifier|*
name|A
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|B
parameter_list|)
function_decl|;
end_function_decl

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

