begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== MC/MCRegisterInfo.h - Target Register Description ---------*- C++ -*-===//
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
name|LLVM_MC_MCREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MCRegisterClass - Base class of TargetRegisterClass.
name|class
name|MCRegisterClass
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
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
specifier|const
name|iterator
name|RegsBegin
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
specifier|const
name|RegSet
decl_stmt|;
specifier|const
name|uint16_t
name|RegsSize
decl_stmt|;
specifier|const
name|uint16_t
name|RegSetSize
decl_stmt|;
specifier|const
name|uint16_t
name|ID
decl_stmt|;
specifier|const
name|uint16_t
name|RegSize
decl_stmt|,
name|Alignment
decl_stmt|;
comment|// Size& Alignment of register in bytes
specifier|const
name|int8_t
name|CopyCost
decl_stmt|;
specifier|const
name|bool
name|Allocatable
decl_stmt|;
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
name|RegsBegin
operator|+
name|RegsSize
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
name|RegsSize
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
name|unsigned
name|InByte
init|=
name|Reg
operator|%
literal|8
decl_stmt|;
name|unsigned
name|Byte
init|=
name|Reg
operator|/
literal|8
decl_stmt|;
if|if
condition|(
name|Byte
operator|>=
name|RegSetSize
condition|)
return|return
name|false
return|;
return|return
operator|(
name|RegSet
index|[
name|Byte
index|]
operator|&
operator|(
literal|1
operator|<<
name|InByte
operator|)
operator|)
operator|!=
literal|0
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
comment|/// getSize - Return the size of the register in bytes, which is also the size
comment|/// of a stack slot allocated to hold a spilled copy of this register.
name|unsigned
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|RegSize
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
name|Alignment
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
name|CopyCost
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
name|Allocatable
return|;
block|}
block|}
empty_stmt|;
comment|/// MCRegisterDesc - This record contains all of the information known about
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
name|MCRegisterDesc
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|// Printable name for the reg (for debugging)
name|uint32_t
name|Overlaps
decl_stmt|;
comment|// Overlapping registers, described above
name|uint32_t
name|SubRegs
decl_stmt|;
comment|// Sub-register set, described above
name|uint32_t
name|SuperRegs
decl_stmt|;
comment|// Super-register set, described above
block|}
struct|;
comment|/// MCRegisterInfo base class - We assume that the target defines a static
comment|/// array of MCRegisterDesc objects that represent all of the machine
comment|/// registers that the target has.  As such, we simply have to track a pointer
comment|/// to this array so that we can turn register number into a register
comment|/// descriptor.
comment|///
comment|/// Note this class is designed to be a base class of TargetRegisterInfo, which
comment|/// is the interface used by codegen. However, specific targets *should never*
comment|/// specialize this class. MCRegisterInfo should only contain getters to access
comment|/// TableGen generated physical register data. It must not be extended with
comment|/// virtual methods.
comment|///
name|class
name|MCRegisterInfo
block|{
name|public
label|:
typedef|typedef
specifier|const
name|MCRegisterClass
modifier|*
name|regclass_iterator
typedef|;
comment|/// DwarfLLVMRegPair - Emitted by tablegen so Dwarf<->LLVM reg mappings can be
comment|/// performed with a binary search.
struct|struct
name|DwarfLLVMRegPair
block|{
name|unsigned
name|FromReg
decl_stmt|;
name|unsigned
name|ToReg
decl_stmt|;
name|bool
name|operator
operator|<
operator|(
name|DwarfLLVMRegPair
name|RHS
operator|)
specifier|const
block|{
return|return
name|FromReg
operator|<
name|RHS
operator|.
name|FromReg
return|;
block|}
block|}
struct|;
name|private
label|:
specifier|const
name|MCRegisterDesc
modifier|*
name|Desc
decl_stmt|;
comment|// Pointer to the descriptor array
name|unsigned
name|NumRegs
decl_stmt|;
comment|// Number of entries in the array
name|unsigned
name|RAReg
decl_stmt|;
comment|// Return address register
specifier|const
name|MCRegisterClass
modifier|*
name|Classes
decl_stmt|;
comment|// Pointer to the regclass array
name|unsigned
name|NumClasses
decl_stmt|;
comment|// Number of entries in the array
specifier|const
name|uint16_t
modifier|*
name|RegLists
decl_stmt|;
comment|// Pointer to the reglists array
specifier|const
name|uint16_t
modifier|*
name|SubRegIndices
decl_stmt|;
comment|// Pointer to the subreg lookup
comment|// array.
name|unsigned
name|NumSubRegIndices
decl_stmt|;
comment|// Number of subreg indices.
name|unsigned
name|L2DwarfRegsSize
decl_stmt|;
name|unsigned
name|EHL2DwarfRegsSize
decl_stmt|;
name|unsigned
name|Dwarf2LRegsSize
decl_stmt|;
name|unsigned
name|EHDwarf2LRegsSize
decl_stmt|;
specifier|const
name|DwarfLLVMRegPair
modifier|*
name|L2DwarfRegs
decl_stmt|;
comment|// LLVM to Dwarf regs mapping
specifier|const
name|DwarfLLVMRegPair
modifier|*
name|EHL2DwarfRegs
decl_stmt|;
comment|// LLVM to Dwarf regs mapping EH
specifier|const
name|DwarfLLVMRegPair
modifier|*
name|Dwarf2LRegs
decl_stmt|;
comment|// Dwarf to LLVM regs mapping
specifier|const
name|DwarfLLVMRegPair
modifier|*
name|EHDwarf2LRegs
decl_stmt|;
comment|// Dwarf to LLVM regs mapping EH
name|DenseMap
operator|<
name|unsigned
operator|,
name|int
operator|>
name|L2SEHRegs
expr_stmt|;
comment|// LLVM to SEH regs mapping
name|public
label|:
comment|/// InitMCRegisterInfo - Initialize MCRegisterInfo, called by TableGen
comment|/// auto-generated routines. *DO NOT USE*.
name|void
name|InitMCRegisterInfo
parameter_list|(
specifier|const
name|MCRegisterDesc
modifier|*
name|D
parameter_list|,
name|unsigned
name|NR
parameter_list|,
name|unsigned
name|RA
parameter_list|,
specifier|const
name|MCRegisterClass
modifier|*
name|C
parameter_list|,
name|unsigned
name|NC
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|RL
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|SubIndices
parameter_list|,
name|unsigned
name|NumIndices
parameter_list|)
block|{
name|Desc
operator|=
name|D
expr_stmt|;
name|NumRegs
operator|=
name|NR
expr_stmt|;
name|RAReg
operator|=
name|RA
expr_stmt|;
name|Classes
operator|=
name|C
expr_stmt|;
name|RegLists
operator|=
name|RL
expr_stmt|;
name|NumClasses
operator|=
name|NC
expr_stmt|;
name|SubRegIndices
operator|=
name|SubIndices
expr_stmt|;
name|NumSubRegIndices
operator|=
name|NumIndices
expr_stmt|;
block|}
comment|/// mapLLVMRegsToDwarfRegs - Used to initialize LLVM register to Dwarf
comment|/// register number mapping. Called by TableGen auto-generated routines.
comment|/// *DO NOT USE*.
name|void
name|mapLLVMRegsToDwarfRegs
parameter_list|(
specifier|const
name|DwarfLLVMRegPair
modifier|*
name|Map
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|bool
name|isEH
parameter_list|)
block|{
if|if
condition|(
name|isEH
condition|)
block|{
name|EHL2DwarfRegs
operator|=
name|Map
expr_stmt|;
name|EHL2DwarfRegsSize
operator|=
name|Size
expr_stmt|;
block|}
else|else
block|{
name|L2DwarfRegs
operator|=
name|Map
expr_stmt|;
name|L2DwarfRegsSize
operator|=
name|Size
expr_stmt|;
block|}
block|}
comment|/// mapDwarfRegsToLLVMRegs - Used to initialize Dwarf register to LLVM
comment|/// register number mapping. Called by TableGen auto-generated routines.
comment|/// *DO NOT USE*.
name|void
name|mapDwarfRegsToLLVMRegs
parameter_list|(
specifier|const
name|DwarfLLVMRegPair
modifier|*
name|Map
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|bool
name|isEH
parameter_list|)
block|{
if|if
condition|(
name|isEH
condition|)
block|{
name|EHDwarf2LRegs
operator|=
name|Map
expr_stmt|;
name|EHDwarf2LRegsSize
operator|=
name|Size
expr_stmt|;
block|}
else|else
block|{
name|Dwarf2LRegs
operator|=
name|Map
expr_stmt|;
name|Dwarf2LRegsSize
operator|=
name|Size
expr_stmt|;
block|}
block|}
comment|/// mapLLVMRegToSEHReg - Used to initialize LLVM register to SEH register
comment|/// number mapping. By default the SEH register number is just the same
comment|/// as the LLVM register number.
comment|/// FIXME: TableGen these numbers. Currently this requires target specific
comment|/// initialization code.
name|void
name|mapLLVMRegToSEHReg
parameter_list|(
name|unsigned
name|LLVMReg
parameter_list|,
name|int
name|SEHReg
parameter_list|)
block|{
name|L2SEHRegs
index|[
name|LLVMReg
index|]
operator|=
name|SEHReg
expr_stmt|;
block|}
comment|/// getRARegister - This method should return the register where the return
comment|/// address can be found.
name|unsigned
name|getRARegister
argument_list|()
specifier|const
block|{
return|return
name|RAReg
return|;
block|}
specifier|const
name|MCRegisterDesc
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
name|MCRegisterDesc
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
name|uint16_t
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
name|RegLists
operator|+
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
name|uint16_t
modifier|*
name|getOverlaps
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|RegLists
operator|+
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
name|uint16_t
modifier|*
name|getSubRegisters
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|RegLists
operator|+
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|SubRegs
return|;
block|}
comment|/// getSubReg - Returns the physical register number of sub-register "Index"
comment|/// for physical register RegNo. Return zero if the sub-register does not
comment|/// exist.
name|unsigned
name|getSubReg
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
return|return
operator|*
operator|(
name|SubRegIndices
operator|+
operator|(
name|Reg
operator|-
literal|1
operator|)
operator|*
name|NumSubRegIndices
operator|+
name|Idx
operator|-
literal|1
operator|)
return|;
block|}
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
name|MCRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
for|for
control|(
specifier|const
name|uint16_t
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
comment|/// getSubRegIndex - For a given register pair, return the sub-register index
comment|/// if the second register is a sub-register of the first. Return zero
comment|/// otherwise.
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
block|{
for|for
control|(
name|unsigned
name|I
init|=
literal|1
init|;
name|I
operator|<=
name|NumSubRegIndices
condition|;
operator|++
name|I
control|)
if|if
condition|(
name|getSubReg
argument_list|(
name|RegNo
argument_list|,
name|I
argument_list|)
operator|==
name|SubRegNo
condition|)
return|return
name|I
return|;
return|return
literal|0
return|;
block|}
comment|/// getSuperRegisters - Return the list of registers that are super-registers
comment|/// of the specified register, or a null list of there are none. The list
comment|/// returned is zero terminated and sorted according to super-sub register
comment|/// relations. e.g. X86::AL's super-register list is AX, EAX, RAX.
comment|///
specifier|const
name|uint16_t
modifier|*
name|getSuperRegisters
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|RegLists
operator|+
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
comment|/// getDwarfRegNum - Map a target register to an equivalent dwarf register
comment|/// number.  Returns -1 if there is no equivalent value.  The second
comment|/// parameter allows targets to use different numberings for EH info and
comment|/// debugging info.
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
block|{
specifier|const
name|DwarfLLVMRegPair
modifier|*
name|M
init|=
name|isEH
condition|?
name|EHL2DwarfRegs
else|:
name|L2DwarfRegs
decl_stmt|;
name|unsigned
name|Size
init|=
name|isEH
condition|?
name|EHL2DwarfRegsSize
else|:
name|L2DwarfRegsSize
decl_stmt|;
name|DwarfLLVMRegPair
name|Key
init|=
block|{
name|RegNum
block|,
literal|0
block|}
decl_stmt|;
specifier|const
name|DwarfLLVMRegPair
modifier|*
name|I
init|=
name|std
operator|::
name|lower_bound
argument_list|(
name|M
argument_list|,
name|M
operator|+
name|Size
argument_list|,
name|Key
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|M
operator|+
name|Size
operator|||
name|I
operator|->
name|FromReg
operator|!=
name|RegNum
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|I
operator|->
name|ToReg
return|;
block|}
comment|/// getLLVMRegNum - Map a dwarf register back to a target register.
comment|///
name|int
name|getLLVMRegNum
argument_list|(
name|unsigned
name|RegNum
argument_list|,
name|bool
name|isEH
argument_list|)
decl|const
block|{
specifier|const
name|DwarfLLVMRegPair
modifier|*
name|M
init|=
name|isEH
condition|?
name|EHDwarf2LRegs
else|:
name|Dwarf2LRegs
decl_stmt|;
name|unsigned
name|Size
init|=
name|isEH
condition|?
name|EHDwarf2LRegsSize
else|:
name|Dwarf2LRegsSize
decl_stmt|;
name|DwarfLLVMRegPair
name|Key
init|=
block|{
name|RegNum
block|,
literal|0
block|}
decl_stmt|;
specifier|const
name|DwarfLLVMRegPair
modifier|*
name|I
init|=
name|std
operator|::
name|lower_bound
argument_list|(
name|M
argument_list|,
name|M
operator|+
name|Size
argument_list|,
name|Key
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|M
operator|+
name|Size
operator|&&
name|I
operator|->
name|FromReg
operator|==
name|RegNum
operator|&&
literal|"Invalid RegNum"
argument_list|)
expr_stmt|;
return|return
name|I
operator|->
name|ToReg
return|;
block|}
comment|/// getSEHRegNum - Map a target register to an equivalent SEH register
comment|/// number.  Returns LLVM register number if there is no equivalent value.
name|int
name|getSEHRegNum
argument_list|(
name|unsigned
name|RegNum
argument_list|)
decl|const
block|{
specifier|const
name|DenseMap
operator|<
name|unsigned
operator|,
name|int
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|L2SEHRegs
operator|.
name|find
argument_list|(
name|RegNum
argument_list|)
expr_stmt|;
if|if
condition|(
name|I
operator|==
name|L2SEHRegs
operator|.
name|end
argument_list|()
condition|)
return|return
operator|(
name|int
operator|)
name|RegNum
return|;
return|return
name|I
operator|->
name|second
return|;
block|}
name|regclass_iterator
name|regclass_begin
argument_list|()
specifier|const
block|{
return|return
name|Classes
return|;
block|}
name|regclass_iterator
name|regclass_end
argument_list|()
specifier|const
block|{
return|return
name|Classes
operator|+
name|NumClasses
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
comment|/// value.  See class MCOperandInfo.
specifier|const
name|MCRegisterClass
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
name|Classes
index|[
name|i
index|]
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

