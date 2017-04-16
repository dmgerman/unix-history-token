begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MC/MCRegisterInfo.h - Target Register Description --------*- C++ -*-===//
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
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/LaneBitmask.h"
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
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// An unsigned integer type large enough to represent all physical registers,
comment|/// but not necessarily virtual registers.
typedef|typedef
name|uint16_t
name|MCPhysReg
typedef|;
comment|/// MCRegisterClass - Base class of TargetRegisterClass.
name|class
name|MCRegisterClass
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
name|uint32_t
name|NameIdx
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
name|PhysRegSize
decl_stmt|;
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
comment|/// Return the size of the physical register in bytes.
name|unsigned
name|getPhysRegSize
argument_list|()
specifier|const
block|{
return|return
name|PhysRegSize
return|;
block|}
comment|/// Temporary function to allow out-of-tree targets to switch.
name|unsigned
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|getPhysRegSize
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
comment|/// MCRegisterDesc - This record contains information about a particular
comment|/// register.  The SubRegs field is a zero terminated array of registers that
comment|/// are sub-registers of the specific register, e.g. AL, AH are sub-registers
comment|/// of AX. The SuperRegs field is a zero terminated array of registers that are
comment|/// super-registers of the specific register, e.g. RAX, EAX, are
comment|/// super-registers of AX.
comment|///
struct|struct
name|MCRegisterDesc
block|{
name|uint32_t
name|Name
decl_stmt|;
comment|// Printable name for the reg (for debugging)
name|uint32_t
name|SubRegs
decl_stmt|;
comment|// Sub-register set, described above
name|uint32_t
name|SuperRegs
decl_stmt|;
comment|// Super-register set, described above
comment|// Offset into MCRI::SubRegIndices of a list of sub-register indices for each
comment|// sub-register in SubRegs.
name|uint32_t
name|SubRegIndices
decl_stmt|;
comment|// RegUnits - Points to the list of register units. The low 4 bits holds the
comment|// Scale, the high bits hold an offset into DiffLists. See MCRegUnitIterator.
name|uint32_t
name|RegUnits
decl_stmt|;
comment|/// Index into list with lane mask sequences. The sequence contains a lanemask
comment|/// for every register unit.
name|uint16_t
name|RegUnitLaneMasks
decl_stmt|;
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
comment|/// SubRegCoveredBits - Emitted by tablegen: bit range covered by a subreg
comment|/// index, -1 in any being invalid.
struct|struct
name|SubRegCoveredBits
block|{
name|uint16_t
name|Offset
decl_stmt|;
name|uint16_t
name|Size
decl_stmt|;
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
name|unsigned
name|PCReg
decl_stmt|;
comment|// Program counter register
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
name|unsigned
name|NumRegUnits
decl_stmt|;
comment|// Number of regunits.
specifier|const
name|MCPhysReg
argument_list|(
operator|*
name|RegUnitRoots
argument_list|)
index|[
literal|2
index|]
expr_stmt|;
comment|// Pointer to regunit root table.
specifier|const
name|MCPhysReg
modifier|*
name|DiffLists
decl_stmt|;
comment|// Pointer to the difflists array
specifier|const
name|LaneBitmask
modifier|*
name|RegUnitMaskSequences
decl_stmt|;
comment|// Pointer to lane mask sequences
comment|// for register units.
specifier|const
name|char
modifier|*
name|RegStrings
decl_stmt|;
comment|// Pointer to the string table.
specifier|const
name|char
modifier|*
name|RegClassStrings
decl_stmt|;
comment|// Pointer to the class strings.
specifier|const
name|uint16_t
modifier|*
name|SubRegIndices
decl_stmt|;
comment|// Pointer to the subreg lookup
comment|// array.
specifier|const
name|SubRegCoveredBits
modifier|*
name|SubRegIdxRanges
decl_stmt|;
comment|// Pointer to the subreg covered
comment|// bit ranges array.
name|unsigned
name|NumSubRegIndices
decl_stmt|;
comment|// Number of subreg indices.
specifier|const
name|uint16_t
modifier|*
name|RegEncodingTable
decl_stmt|;
comment|// Pointer to array of register
comment|// encodings.
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
name|DenseMap
operator|<
name|unsigned
operator|,
name|int
operator|>
name|L2CVRegs
expr_stmt|;
comment|// LLVM to CV regs mapping
name|public
label|:
comment|/// DiffListIterator - Base iterator class that can traverse the
comment|/// differentially encoded register and regunit lists in DiffLists.
comment|/// Don't use this class directly, use one of the specialized sub-classes
comment|/// defined below.
name|class
name|DiffListIterator
block|{
name|uint16_t
name|Val
init|=
literal|0
decl_stmt|;
specifier|const
name|MCPhysReg
modifier|*
name|List
init|=
name|nullptr
decl_stmt|;
name|protected
label|:
comment|/// Create an invalid iterator. Call init() to point to something useful.
name|DiffListIterator
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// init - Point the iterator to InitVal, decoding subsequent values from
comment|/// DiffList. The iterator will initially point to InitVal, sub-classes are
comment|/// responsible for skipping the seed value if it is not part of the list.
name|void
name|init
parameter_list|(
name|MCPhysReg
name|InitVal
parameter_list|,
specifier|const
name|MCPhysReg
modifier|*
name|DiffList
parameter_list|)
block|{
name|Val
operator|=
name|InitVal
expr_stmt|;
name|List
operator|=
name|DiffList
expr_stmt|;
block|}
comment|/// advance - Move to the next list position, return the applied
comment|/// differential. This function does not detect the end of the list, that
comment|/// is the caller's responsibility (by checking for a 0 return value).
name|unsigned
name|advance
parameter_list|()
block|{
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Cannot move off the end of the list."
argument_list|)
expr_stmt|;
name|MCPhysReg
name|D
init|=
operator|*
name|List
operator|++
decl_stmt|;
name|Val
operator|+=
name|D
expr_stmt|;
return|return
name|D
return|;
block|}
name|public
label|:
comment|/// isValid - returns true if this iterator is not yet at the end.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|List
return|;
block|}
comment|/// Dereference the iterator to get the value at the current position.
name|unsigned
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Val
return|;
block|}
comment|/// Pre-increment to move to the next position.
name|void
name|operator
operator|++
operator|(
operator|)
block|{
comment|// The end of the list is encoded as a 0 differential.
if|if
condition|(
operator|!
name|advance
argument_list|()
condition|)
name|List
operator|=
name|nullptr
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|// These iterators are allowed to sub-class DiffListIterator and access
comment|// internal list pointers.
name|friend
name|class
name|MCSubRegIterator
decl_stmt|;
name|friend
name|class
name|MCSubRegIndexIterator
decl_stmt|;
name|friend
name|class
name|MCSuperRegIterator
decl_stmt|;
name|friend
name|class
name|MCRegUnitIterator
decl_stmt|;
name|friend
name|class
name|MCRegUnitMaskIterator
decl_stmt|;
name|friend
name|class
name|MCRegUnitRootIterator
decl_stmt|;
comment|/// \brief Initialize MCRegisterInfo, called by TableGen
comment|/// auto-generated routines. *DO NOT USE*.
name|void
name|InitMCRegisterInfo
argument_list|(
specifier|const
name|MCRegisterDesc
operator|*
name|D
argument_list|,
name|unsigned
name|NR
argument_list|,
name|unsigned
name|RA
argument_list|,
name|unsigned
name|PC
argument_list|,
specifier|const
name|MCRegisterClass
operator|*
name|C
argument_list|,
name|unsigned
name|NC
argument_list|,
specifier|const
name|MCPhysReg
argument_list|(
operator|*
name|RURoots
argument_list|)
index|[
literal|2
index|]
argument_list|,
name|unsigned
name|NRU
argument_list|,
specifier|const
name|MCPhysReg
operator|*
name|DL
argument_list|,
specifier|const
name|LaneBitmask
operator|*
name|RUMS
argument_list|,
specifier|const
name|char
operator|*
name|Strings
argument_list|,
specifier|const
name|char
operator|*
name|ClassStrings
argument_list|,
specifier|const
name|uint16_t
operator|*
name|SubIndices
argument_list|,
name|unsigned
name|NumIndices
argument_list|,
specifier|const
name|SubRegCoveredBits
operator|*
name|SubIdxRanges
argument_list|,
specifier|const
name|uint16_t
operator|*
name|RET
argument_list|)
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
name|PCReg
operator|=
name|PC
expr_stmt|;
name|Classes
operator|=
name|C
expr_stmt|;
name|DiffLists
operator|=
name|DL
expr_stmt|;
name|RegUnitMaskSequences
operator|=
name|RUMS
expr_stmt|;
name|RegStrings
operator|=
name|Strings
expr_stmt|;
name|RegClassStrings
operator|=
name|ClassStrings
expr_stmt|;
name|NumClasses
operator|=
name|NC
expr_stmt|;
name|RegUnitRoots
operator|=
name|RURoots
expr_stmt|;
name|NumRegUnits
operator|=
name|NRU
expr_stmt|;
name|SubRegIndices
operator|=
name|SubIndices
expr_stmt|;
name|NumSubRegIndices
operator|=
name|NumIndices
expr_stmt|;
name|SubRegIdxRanges
operator|=
name|SubIdxRanges
expr_stmt|;
name|RegEncodingTable
operator|=
name|RET
expr_stmt|;
comment|// Initialize DWARF register mapping variables
name|EHL2DwarfRegs
operator|=
name|nullptr
expr_stmt|;
name|EHL2DwarfRegsSize
operator|=
literal|0
expr_stmt|;
name|L2DwarfRegs
operator|=
name|nullptr
expr_stmt|;
name|L2DwarfRegsSize
operator|=
literal|0
expr_stmt|;
name|EHDwarf2LRegs
operator|=
name|nullptr
expr_stmt|;
name|EHDwarf2LRegsSize
operator|=
literal|0
expr_stmt|;
name|Dwarf2LRegs
operator|=
name|nullptr
expr_stmt|;
name|Dwarf2LRegsSize
operator|=
literal|0
expr_stmt|;
block|}
comment|/// \brief Used to initialize LLVM register to Dwarf
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
comment|/// \brief Used to initialize Dwarf register to LLVM
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
name|void
name|mapLLVMRegToCVReg
parameter_list|(
name|unsigned
name|LLVMReg
parameter_list|,
name|int
name|CVReg
parameter_list|)
block|{
name|L2CVRegs
index|[
name|LLVMReg
index|]
operator|=
name|CVReg
expr_stmt|;
block|}
comment|/// \brief This method should return the register where the return
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
comment|/// Return the register which is the program counter.
name|unsigned
name|getProgramCounter
argument_list|()
specifier|const
block|{
return|return
name|PCReg
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
comment|/// \brief Provide a get method, equivalent to [], but more useful with a
comment|/// pointer to this object.
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
comment|/// \brief Returns the physical register number of sub-register "Index"
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
decl_stmt|;
comment|/// \brief Return a super-register of the specified register
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
decl_stmt|;
comment|/// \brief For a given register pair, return the sub-register index
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
decl_stmt|;
comment|/// \brief Get the size of the bit range covered by a sub-register index.
comment|/// If the index isn't continuous, return the sum of the sizes of its parts.
comment|/// If the index is used to access subregisters of different sizes, return -1.
name|unsigned
name|getSubRegIdxSize
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the offset of the bit range covered by a sub-register index.
comment|/// If an Offset doesn't make sense (the index isn't continuous, or is used to
comment|/// access sub-registers at different offsets), return -1.
name|unsigned
name|getSubRegIdxOffset
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the human-readable symbolic target-specific name for the
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
name|RegStrings
operator|+
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|Name
return|;
block|}
comment|/// \brief Return the number of registers this target has (useful for
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
comment|/// \brief Return the number of sub-register indices
comment|/// understood by the target. Index 0 is reserved for the no-op sub-register,
comment|/// while 1 to getNumSubRegIndices() - 1 represent real sub-registers.
name|unsigned
name|getNumSubRegIndices
argument_list|()
specifier|const
block|{
return|return
name|NumSubRegIndices
return|;
block|}
comment|/// \brief Return the number of (native) register units in the
comment|/// target. Register units are numbered from 0 to getNumRegUnits() - 1. They
comment|/// can be accessed through MCRegUnitIterator defined below.
name|unsigned
name|getNumRegUnits
argument_list|()
specifier|const
block|{
return|return
name|NumRegUnits
return|;
block|}
comment|/// \brief Map a target register to an equivalent dwarf register
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
decl_stmt|;
comment|/// \brief Map a dwarf register back to a target register.
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
decl_stmt|;
comment|/// \brief Map a target register to an equivalent SEH register
comment|/// number.  Returns LLVM register number if there is no equivalent value.
name|int
name|getSEHRegNum
argument_list|(
name|unsigned
name|RegNum
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Map a target register to an equivalent CodeView register
comment|/// number.
name|int
name|getCodeViewRegNum
argument_list|(
name|unsigned
name|RegNum
argument_list|)
decl|const
decl_stmt|;
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
comment|/// \brief Returns the register class associated with the enumeration
comment|/// value.  See class MCOperandInfo.
specifier|const
name|MCRegisterClass
modifier|&
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
specifier|const
name|char
modifier|*
name|getRegClassName
argument_list|(
specifier|const
name|MCRegisterClass
operator|*
name|Class
argument_list|)
decl|const
block|{
return|return
name|RegClassStrings
operator|+
name|Class
operator|->
name|NameIdx
return|;
block|}
comment|/// \brief Returns the encoding for RegNo
name|uint16_t
name|getEncodingValue
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
literal|"Attempting to get encoding for invalid register number!"
argument_list|)
expr_stmt|;
return|return
name|RegEncodingTable
index|[
name|RegNo
index|]
return|;
block|}
comment|/// \brief Returns true if RegB is a sub-register of RegA.
name|bool
name|isSubRegister
argument_list|(
name|unsigned
name|RegA
argument_list|,
name|unsigned
name|RegB
argument_list|)
decl|const
block|{
return|return
name|isSuperRegister
argument_list|(
name|RegB
argument_list|,
name|RegA
argument_list|)
return|;
block|}
comment|/// \brief Returns true if RegB is a super-register of RegA.
name|bool
name|isSuperRegister
argument_list|(
name|unsigned
name|RegA
argument_list|,
name|unsigned
name|RegB
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns true if RegB is a sub-register of RegA or if RegB == RegA.
name|bool
name|isSubRegisterEq
argument_list|(
name|unsigned
name|RegA
argument_list|,
name|unsigned
name|RegB
argument_list|)
decl|const
block|{
return|return
name|isSuperRegisterEq
argument_list|(
name|RegB
argument_list|,
name|RegA
argument_list|)
return|;
block|}
comment|/// \brief Returns true if RegB is a super-register of RegA or if
comment|/// RegB == RegA.
name|bool
name|isSuperRegisterEq
argument_list|(
name|unsigned
name|RegA
argument_list|,
name|unsigned
name|RegB
argument_list|)
decl|const
block|{
return|return
name|RegA
operator|==
name|RegB
operator|||
name|isSuperRegister
argument_list|(
name|RegA
argument_list|,
name|RegB
argument_list|)
return|;
block|}
comment|/// \brief Returns true if RegB is a super-register or sub-register of RegA
comment|/// or if RegB == RegA.
name|bool
name|isSuperOrSubRegisterEq
argument_list|(
name|unsigned
name|RegA
argument_list|,
name|unsigned
name|RegB
argument_list|)
decl|const
block|{
return|return
name|isSubRegisterEq
argument_list|(
name|RegA
argument_list|,
name|RegB
argument_list|)
operator|||
name|isSuperRegister
argument_list|(
name|RegA
argument_list|,
name|RegB
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//                          Register List Iterators
comment|//===----------------------------------------------------------------------===//
comment|// MCRegisterInfo provides lists of super-registers, sub-registers, and
comment|// aliasing registers. Use these iterator classes to traverse the lists.
comment|/// MCSubRegIterator enumerates all sub-registers of Reg.
comment|/// If IncludeSelf is set, Reg itself is included in the list.
name|class
name|MCSubRegIterator
range|:
name|public
name|MCRegisterInfo
operator|::
name|DiffListIterator
block|{
name|public
operator|:
name|MCSubRegIterator
argument_list|(
argument|unsigned Reg
argument_list|,
argument|const MCRegisterInfo *MCRI
argument_list|,
argument|bool IncludeSelf = false
argument_list|)
block|{
name|init
argument_list|(
name|Reg
argument_list|,
name|MCRI
operator|->
name|DiffLists
operator|+
name|MCRI
operator|->
name|get
argument_list|(
name|Reg
argument_list|)
operator|.
name|SubRegs
argument_list|)
block|;
comment|// Initially, the iterator points to Reg itself.
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
expr|}
block|;
comment|/// Iterator that enumerates the sub-registers of a Reg and the associated
comment|/// sub-register indices.
name|class
name|MCSubRegIndexIterator
block|{
name|MCSubRegIterator
name|SRIter
block|;
specifier|const
name|uint16_t
operator|*
name|SRIndex
block|;
name|public
operator|:
comment|/// Constructs an iterator that traverses subregisters and their
comment|/// associated subregister indices.
name|MCSubRegIndexIterator
argument_list|(
argument|unsigned Reg
argument_list|,
argument|const MCRegisterInfo *MCRI
argument_list|)
operator|:
name|SRIter
argument_list|(
argument|Reg
argument_list|,
argument|MCRI
argument_list|)
block|{
name|SRIndex
operator|=
name|MCRI
operator|->
name|SubRegIndices
operator|+
name|MCRI
operator|->
name|get
argument_list|(
name|Reg
argument_list|)
operator|.
name|SubRegIndices
block|;   }
comment|/// Returns current sub-register.
name|unsigned
name|getSubReg
argument_list|()
specifier|const
block|{
return|return
operator|*
name|SRIter
return|;
block|}
comment|/// Returns sub-register index of the current sub-register.
name|unsigned
name|getSubRegIndex
argument_list|()
specifier|const
block|{
return|return
operator|*
name|SRIndex
return|;
block|}
comment|/// Returns true if this iterator is not yet at the end.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|SRIter
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// Moves to the next position.
name|void
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|SRIter
block|;
operator|++
name|SRIndex
block|;   }
expr|}
block|;
comment|/// MCSuperRegIterator enumerates all super-registers of Reg.
comment|/// If IncludeSelf is set, Reg itself is included in the list.
name|class
name|MCSuperRegIterator
operator|:
name|public
name|MCRegisterInfo
operator|::
name|DiffListIterator
block|{
name|public
operator|:
name|MCSuperRegIterator
argument_list|()
operator|=
expr|default
block|;
name|MCSuperRegIterator
argument_list|(
argument|unsigned Reg
argument_list|,
argument|const MCRegisterInfo *MCRI
argument_list|,
argument|bool IncludeSelf = false
argument_list|)
block|{
name|init
argument_list|(
name|Reg
argument_list|,
name|MCRI
operator|->
name|DiffLists
operator|+
name|MCRI
operator|->
name|get
argument_list|(
name|Reg
argument_list|)
operator|.
name|SuperRegs
argument_list|)
block|;
comment|// Initially, the iterator points to Reg itself.
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
expr|}
block|;
comment|// Definition for isSuperRegister. Put it down here since it needs the
comment|// iterator defined above in addition to the MCRegisterInfo class itself.
specifier|inline
name|bool
name|MCRegisterInfo
operator|::
name|isSuperRegister
argument_list|(
argument|unsigned RegA
argument_list|,
argument|unsigned RegB
argument_list|)
specifier|const
block|{
for|for
control|(
name|MCSuperRegIterator
name|I
argument_list|(
name|RegA
argument_list|,
name|this
argument_list|)
init|;
name|I
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|I
control|)
if|if
condition|(
operator|*
name|I
operator|==
name|RegB
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|//===----------------------------------------------------------------------===//
comment|//                               Register Units
comment|//===----------------------------------------------------------------------===//
comment|// Register units are used to compute register aliasing. Every register has at
comment|// least one register unit, but it can have more. Two registers overlap if and
comment|// only if they have a common register unit.
comment|//
comment|// A target with a complicated sub-register structure will typically have many
comment|// fewer register units than actual registers. MCRI::getNumRegUnits() returns
comment|// the number of register units in the target.
comment|// MCRegUnitIterator enumerates a list of register units for Reg. The list is
comment|// in ascending numerical order.
name|class
name|MCRegUnitIterator
operator|:
name|public
name|MCRegisterInfo
operator|::
name|DiffListIterator
block|{
name|public
operator|:
comment|/// MCRegUnitIterator - Create an iterator that traverses the register units
comment|/// in Reg.
name|MCRegUnitIterator
argument_list|()
operator|=
expr|default
block|;
name|MCRegUnitIterator
argument_list|(
argument|unsigned Reg
argument_list|,
argument|const MCRegisterInfo *MCRI
argument_list|)
block|{
name|assert
argument_list|(
name|Reg
operator|&&
literal|"Null register has no regunits"
argument_list|)
block|;
comment|// Decode the RegUnits MCRegisterDesc field.
name|unsigned
name|RU
operator|=
name|MCRI
operator|->
name|get
argument_list|(
name|Reg
argument_list|)
operator|.
name|RegUnits
block|;
name|unsigned
name|Scale
operator|=
name|RU
operator|&
literal|15
block|;
name|unsigned
name|Offset
operator|=
name|RU
operator|>>
literal|4
block|;
comment|// Initialize the iterator to Reg * Scale, and the List pointer to
comment|// DiffLists + Offset.
name|init
argument_list|(
name|Reg
operator|*
name|Scale
argument_list|,
name|MCRI
operator|->
name|DiffLists
operator|+
name|Offset
argument_list|)
block|;
comment|// That may not be a valid unit, we need to advance by one to get the real
comment|// unit number. The first differential can be 0 which would normally
comment|// terminate the list, but since we know every register has at least one
comment|// unit, we can allow a 0 differential here.
name|advance
argument_list|()
block|;   }
block|}
block|;
comment|/// MCRegUnitMaskIterator enumerates a list of register units and their
comment|/// associated lane masks for Reg. The register units are in ascending
comment|/// numerical order.
name|class
name|MCRegUnitMaskIterator
block|{
name|MCRegUnitIterator
name|RUIter
block|;
specifier|const
name|LaneBitmask
operator|*
name|MaskListIter
block|;
name|public
operator|:
name|MCRegUnitMaskIterator
argument_list|()
operator|=
expr|default
block|;
comment|/// Constructs an iterator that traverses the register units and their
comment|/// associated LaneMasks in Reg.
name|MCRegUnitMaskIterator
argument_list|(
argument|unsigned Reg
argument_list|,
argument|const MCRegisterInfo *MCRI
argument_list|)
operator|:
name|RUIter
argument_list|(
argument|Reg
argument_list|,
argument|MCRI
argument_list|)
block|{
name|uint16_t
name|Idx
operator|=
name|MCRI
operator|->
name|get
argument_list|(
name|Reg
argument_list|)
operator|.
name|RegUnitLaneMasks
block|;
name|MaskListIter
operator|=
operator|&
name|MCRI
operator|->
name|RegUnitMaskSequences
index|[
name|Idx
index|]
block|;   }
comment|/// Returns a (RegUnit, LaneMask) pair.
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|LaneBitmask
operator|>
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
operator|*
name|RUIter
argument_list|,
operator|*
name|MaskListIter
argument_list|)
return|;
block|}
comment|/// Returns true if this iterator is not yet at the end.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|RUIter
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// Moves to the next position.
name|void
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|MaskListIter
block|;
operator|++
name|RUIter
block|;   }
expr|}
block|;
comment|// Each register unit has one or two root registers. The complete set of
comment|// registers containing a register unit is the union of the roots and their
comment|// super-registers. All registers aliasing Unit can be visited like this:
comment|//
comment|//   for (MCRegUnitRootIterator RI(Unit, MCRI); RI.isValid(); ++RI) {
comment|//     for (MCSuperRegIterator SI(*RI, MCRI, true); SI.isValid(); ++SI)
comment|//       visit(*SI);
comment|//    }
comment|/// MCRegUnitRootIterator enumerates the root registers of a register unit.
name|class
name|MCRegUnitRootIterator
block|{
name|uint16_t
name|Reg0
operator|=
literal|0
block|;
name|uint16_t
name|Reg1
operator|=
literal|0
block|;
name|public
operator|:
name|MCRegUnitRootIterator
argument_list|()
operator|=
expr|default
block|;
name|MCRegUnitRootIterator
argument_list|(
argument|unsigned RegUnit
argument_list|,
argument|const MCRegisterInfo *MCRI
argument_list|)
block|{
name|assert
argument_list|(
name|RegUnit
operator|<
name|MCRI
operator|->
name|getNumRegUnits
argument_list|()
operator|&&
literal|"Invalid register unit"
argument_list|)
block|;
name|Reg0
operator|=
name|MCRI
operator|->
name|RegUnitRoots
index|[
name|RegUnit
index|]
index|[
literal|0
index|]
block|;
name|Reg1
operator|=
name|MCRI
operator|->
name|RegUnitRoots
index|[
name|RegUnit
index|]
index|[
literal|1
index|]
block|;   }
comment|/// \brief Dereference to get the current root register.
name|unsigned
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Reg0
return|;
block|}
comment|/// \brief Check if the iterator is at the end of the list.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Reg0
return|;
block|}
comment|/// \brief Preincrement to move to the next root register.
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
literal|"Cannot move off the end of the list."
argument_list|)
block|;
name|Reg0
operator|=
name|Reg1
block|;
name|Reg1
operator|=
literal|0
block|;   }
expr|}
block|;
comment|/// MCRegAliasIterator enumerates all registers aliasing Reg.  If IncludeSelf is
comment|/// set, Reg itself is included in the list.  This iterator does not guarantee
comment|/// any ordering or that entries are unique.
name|class
name|MCRegAliasIterator
block|{
name|private
operator|:
name|unsigned
name|Reg
block|;
specifier|const
name|MCRegisterInfo
operator|*
name|MCRI
block|;
name|bool
name|IncludeSelf
block|;
name|MCRegUnitIterator
name|RI
block|;
name|MCRegUnitRootIterator
name|RRI
block|;
name|MCSuperRegIterator
name|SI
block|;
name|public
operator|:
name|MCRegAliasIterator
argument_list|(
argument|unsigned Reg
argument_list|,
argument|const MCRegisterInfo *MCRI
argument_list|,
argument|bool IncludeSelf
argument_list|)
operator|:
name|Reg
argument_list|(
name|Reg
argument_list|)
block|,
name|MCRI
argument_list|(
name|MCRI
argument_list|)
block|,
name|IncludeSelf
argument_list|(
argument|IncludeSelf
argument_list|)
block|{
comment|// Initialize the iterators.
for|for
control|(
name|RI
operator|=
name|MCRegUnitIterator
argument_list|(
name|Reg
argument_list|,
name|MCRI
argument_list|)
init|;
name|RI
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|RI
control|)
block|{
for|for
control|(
name|RRI
operator|=
name|MCRegUnitRootIterator
argument_list|(
operator|*
name|RI
argument_list|,
name|MCRI
argument_list|)
init|;
name|RRI
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|RRI
control|)
block|{
for|for
control|(
name|SI
operator|=
name|MCSuperRegIterator
argument_list|(
operator|*
name|RRI
argument_list|,
name|MCRI
argument_list|,
name|true
argument_list|)
init|;
name|SI
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|SI
control|)
block|{
if|if
condition|(
operator|!
operator|(
operator|!
name|IncludeSelf
operator|&&
name|Reg
operator|==
operator|*
name|SI
operator|)
condition|)
return|return;
block|}
block|}
block|}
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|RI
operator|.
name|isValid
argument_list|()
return|;
block|}
name|unsigned
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|SI
operator|.
name|isValid
argument_list|()
operator|&&
literal|"Cannot dereference an invalid iterator."
argument_list|)
block|;
return|return
operator|*
name|SI
return|;
block|}
name|void
name|advance
argument_list|()
block|{
comment|// Assuming SI is valid.
operator|++
name|SI
block|;
if|if
condition|(
name|SI
operator|.
name|isValid
argument_list|()
condition|)
return|return;
operator|++
name|RRI
block|;
if|if
condition|(
name|RRI
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|SI
operator|=
name|MCSuperRegIterator
argument_list|(
operator|*
name|RRI
argument_list|,
name|MCRI
argument_list|,
name|true
argument_list|)
expr_stmt|;
return|return;
block|}
operator|++
name|RI
expr_stmt|;
if|if
condition|(
name|RI
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|RRI
operator|=
name|MCRegUnitRootIterator
argument_list|(
operator|*
name|RI
argument_list|,
name|MCRI
argument_list|)
expr_stmt|;
name|SI
operator|=
name|MCSuperRegIterator
argument_list|(
operator|*
name|RRI
argument_list|,
name|MCRI
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
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
literal|"Cannot move off the end of the list."
argument_list|)
block|;
do|do
name|advance
argument_list|()
expr_stmt|;
do|while
condition|(
operator|!
name|IncludeSelf
operator|&&
name|isValid
argument_list|()
operator|&&
operator|*
name|SI
operator|==
name|Reg
condition|)
do|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCREGISTERINFO_H
end_comment

end_unit

