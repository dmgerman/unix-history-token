begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeGenRegisters.h - Register and RegisterClass Info -----*- C++ -*-===//
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
comment|// This file defines structures to encapsulate information gleaned from the
end_comment

begin_comment
comment|// target register and register class definitions.
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
name|LLVM_UTILS_TABLEGEN_CODEGENREGISTERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UTILS_TABLEGEN_CODEGENREGISTERS_H
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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SparseBitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/LaneBitmask.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/TableGen/Record.h"
end_include

begin_include
include|#
directive|include
file|"llvm/TableGen/SetTheory.h"
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
file|<deque>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
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
name|CodeGenRegBank
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Vector
operator|,
name|typename
name|Set
operator|>
name|class
name|SetVector
expr_stmt|;
comment|/// Used to encode a step in a register lane mask transformation.
comment|/// Mask the bits specified in Mask, then rotate them Rol bits to the left
comment|/// assuming a wraparound at 32bits.
struct|struct
name|MaskRolPair
block|{
name|LaneBitmask
name|Mask
decl_stmt|;
name|uint8_t
name|RotateLeft
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MaskRolPair
name|Other
operator|)
specifier|const
block|{
return|return
name|Mask
operator|==
name|Other
operator|.
name|Mask
operator|&&
name|RotateLeft
operator|==
name|Other
operator|.
name|RotateLeft
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|MaskRolPair
name|Other
operator|)
specifier|const
block|{
return|return
name|Mask
operator|!=
name|Other
operator|.
name|Mask
operator|||
name|RotateLeft
operator|!=
name|Other
operator|.
name|RotateLeft
return|;
block|}
block|}
struct|;
comment|/// CodeGenSubRegIndex - Represents a sub-register index.
name|class
name|CodeGenSubRegIndex
block|{
name|Record
modifier|*
specifier|const
name|TheDef
decl_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|std
operator|::
name|string
name|Namespace
expr_stmt|;
name|public
label|:
name|uint16_t
name|Size
decl_stmt|;
name|uint16_t
name|Offset
decl_stmt|;
specifier|const
name|unsigned
name|EnumValue
decl_stmt|;
name|mutable
name|LaneBitmask
name|LaneMask
decl_stmt|;
name|mutable
name|SmallVector
operator|<
name|MaskRolPair
operator|,
literal|1
operator|>
name|CompositionLaneMaskTransform
expr_stmt|;
comment|// Are all super-registers containing this SubRegIndex covered by their
comment|// sub-registers?
name|bool
name|AllSuperRegsCovered
decl_stmt|;
name|CodeGenSubRegIndex
argument_list|(
argument|Record *R
argument_list|,
argument|unsigned Enum
argument_list|)
empty_stmt|;
name|CodeGenSubRegIndex
argument_list|(
argument|StringRef N
argument_list|,
argument|StringRef Nspace
argument_list|,
argument|unsigned Enum
argument_list|)
empty_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getNamespace
argument_list|()
specifier|const
block|{
return|return
name|Namespace
return|;
block|}
name|std
operator|::
name|string
name|getQualifiedName
argument_list|()
specifier|const
expr_stmt|;
comment|// Map of composite subreg indices.
typedef|typedef
name|std
operator|::
name|map
operator|<
name|CodeGenSubRegIndex
operator|*
operator|,
name|CodeGenSubRegIndex
operator|*
operator|,
name|deref
operator|<
name|llvm
operator|::
name|less
operator|>>
name|CompMap
expr_stmt|;
comment|// Returns the subreg index that results from composing this with Idx.
comment|// Returns NULL if this and Idx don't compose.
name|CodeGenSubRegIndex
modifier|*
name|compose
argument_list|(
name|CodeGenSubRegIndex
operator|*
name|Idx
argument_list|)
decl|const
block|{
name|CompMap
operator|::
name|const_iterator
name|I
operator|=
name|Composed
operator|.
name|find
argument_list|(
name|Idx
argument_list|)
expr_stmt|;
return|return
name|I
operator|==
name|Composed
operator|.
name|end
argument_list|()
condition|?
name|nullptr
else|:
name|I
operator|->
name|second
return|;
block|}
comment|// Add a composite subreg index: this+A = B.
comment|// Return a conflicting composite, or NULL
name|CodeGenSubRegIndex
modifier|*
name|addComposite
parameter_list|(
name|CodeGenSubRegIndex
modifier|*
name|A
parameter_list|,
name|CodeGenSubRegIndex
modifier|*
name|B
parameter_list|)
block|{
name|assert
argument_list|(
name|A
operator|&&
name|B
argument_list|)
expr_stmt|;
name|std
operator|::
name|pair
operator|<
name|CompMap
operator|::
name|iterator
operator|,
name|bool
operator|>
name|Ins
operator|=
name|Composed
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
argument_list|)
expr_stmt|;
comment|// Synthetic subreg indices that aren't contiguous (for instance ARM
comment|// register tuples) don't have a bit range, so it's OK to let
comment|// B->Offset == -1. For the other cases, accumulate the offset and set
comment|// the size here. Only do so if there is no offset yet though.
if|if
condition|(
operator|(
name|Offset
operator|!=
operator|(
name|uint16_t
operator|)
operator|-
literal|1
operator|&&
name|A
operator|->
name|Offset
operator|!=
operator|(
name|uint16_t
operator|)
operator|-
literal|1
operator|)
operator|&&
operator|(
name|B
operator|->
name|Offset
operator|==
operator|(
name|uint16_t
operator|)
operator|-
literal|1
operator|)
condition|)
block|{
name|B
operator|->
name|Offset
operator|=
name|Offset
operator|+
name|A
operator|->
name|Offset
expr_stmt|;
name|B
operator|->
name|Size
operator|=
name|A
operator|->
name|Size
expr_stmt|;
block|}
return|return
operator|(
name|Ins
operator|.
name|second
operator|||
name|Ins
operator|.
name|first
operator|->
name|second
operator|==
name|B
operator|)
condition|?
name|nullptr
else|:
name|Ins
operator|.
name|first
operator|->
name|second
return|;
block|}
comment|// Update the composite maps of components specified in 'ComposedOf'.
name|void
name|updateComponents
parameter_list|(
name|CodeGenRegBank
modifier|&
parameter_list|)
function_decl|;
comment|// Return the map of composites.
specifier|const
name|CompMap
operator|&
name|getComposites
argument_list|()
specifier|const
block|{
return|return
name|Composed
return|;
block|}
comment|// Compute LaneMask from Composed. Return LaneMask.
name|LaneBitmask
name|computeLaneMask
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|CompMap
name|Composed
decl_stmt|;
block|}
empty_stmt|;
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|CodeGenSubRegIndex
operator|&
name|A
operator|,
specifier|const
name|CodeGenSubRegIndex
operator|&
name|B
operator|)
block|{
return|return
name|A
operator|.
name|EnumValue
operator|<
name|B
operator|.
name|EnumValue
return|;
block|}
comment|/// CodeGenRegister - Represents a register definition.
struct|struct
name|CodeGenRegister
block|{
name|Record
modifier|*
name|TheDef
decl_stmt|;
name|unsigned
name|EnumValue
decl_stmt|;
name|unsigned
name|CostPerUse
decl_stmt|;
name|bool
name|CoveredBySubRegs
decl_stmt|;
name|bool
name|HasDisjunctSubRegs
decl_stmt|;
comment|// Map SubRegIndex -> Register.
typedef|typedef
name|std
operator|::
name|map
operator|<
name|CodeGenSubRegIndex
operator|*
operator|,
name|CodeGenRegister
operator|*
operator|,
name|deref
operator|<
name|llvm
operator|::
name|less
operator|>>
name|SubRegMap
expr_stmt|;
name|CodeGenRegister
argument_list|(
argument|Record *R
argument_list|,
argument|unsigned Enum
argument_list|)
empty_stmt|;
specifier|const
name|StringRef
name|getName
argument_list|()
specifier|const
expr_stmt|;
comment|// Extract more information from TheDef. This is used to build an object
comment|// graph after all CodeGenRegister objects have been created.
name|void
name|buildObjectGraph
parameter_list|(
name|CodeGenRegBank
modifier|&
parameter_list|)
function_decl|;
comment|// Lazily compute a map of all sub-registers.
comment|// This includes unique entries for all sub-sub-registers.
specifier|const
name|SubRegMap
modifier|&
name|computeSubRegs
parameter_list|(
name|CodeGenRegBank
modifier|&
parameter_list|)
function_decl|;
comment|// Compute extra sub-registers by combining the existing sub-registers.
name|void
name|computeSecondarySubRegs
parameter_list|(
name|CodeGenRegBank
modifier|&
parameter_list|)
function_decl|;
comment|// Add this as a super-register to all sub-registers after the sub-register
comment|// graph has been built.
name|void
name|computeSuperRegs
parameter_list|(
name|CodeGenRegBank
modifier|&
parameter_list|)
function_decl|;
specifier|const
name|SubRegMap
operator|&
name|getSubRegs
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|SubRegsComplete
operator|&&
literal|"Must precompute sub-registers"
argument_list|)
block|;
return|return
name|SubRegs
return|;
block|}
comment|// Add sub-registers to OSet following a pre-order defined by the .td file.
name|void
name|addSubRegsPreOrder
argument_list|(
name|SetVector
operator|<
specifier|const
name|CodeGenRegister
operator|*
operator|>
operator|&
name|OSet
argument_list|,
name|CodeGenRegBank
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|// Return the sub-register index naming Reg as a sub-register of this
comment|// register. Returns NULL if Reg is not a sub-register.
name|CodeGenSubRegIndex
modifier|*
name|getSubRegIndex
argument_list|(
specifier|const
name|CodeGenRegister
operator|*
name|Reg
argument_list|)
decl|const
block|{
return|return
name|SubReg2Idx
operator|.
name|lookup
argument_list|(
name|Reg
argument_list|)
return|;
block|}
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|CodeGenRegister
operator|*
operator|>
name|SuperRegList
expr_stmt|;
comment|// Get the list of super-registers in topological order, small to large.
comment|// This is valid after computeSubRegs visits all registers during RegBank
comment|// construction.
specifier|const
name|SuperRegList
operator|&
name|getSuperRegs
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|SubRegsComplete
operator|&&
literal|"Must precompute sub-registers"
argument_list|)
block|;
return|return
name|SuperRegs
return|;
block|}
comment|// Get the list of ad hoc aliases. The graph is symmetric, so the list
comment|// contains all registers in 'Aliases', and all registers that mention this
comment|// register in 'Aliases'.
name|ArrayRef
operator|<
name|CodeGenRegister
operator|*
operator|>
name|getExplicitAliases
argument_list|()
specifier|const
block|{
return|return
name|ExplicitAliases
return|;
block|}
comment|// Get the topological signature of this register. This is a small integer
comment|// less than RegBank.getNumTopoSigs(). Registers with the same TopoSig have
comment|// identical sub-register structure. That is, they support the same set of
comment|// sub-register indices mapping to the same kind of sub-registers
comment|// (TopoSig-wise).
name|unsigned
name|getTopoSig
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|SuperRegsComplete
operator|&&
literal|"TopoSigs haven't been computed yet."
argument_list|)
block|;
return|return
name|TopoSig
return|;
block|}
comment|// List of register units in ascending order.
typedef|typedef
name|SparseBitVector
operator|<
operator|>
name|RegUnitList
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|LaneBitmask
operator|,
literal|16
operator|>
name|RegUnitLaneMaskList
expr_stmt|;
comment|// How many entries in RegUnitList are native?
name|RegUnitList
name|NativeRegUnits
decl_stmt|;
comment|// Get the list of register units.
comment|// This is only valid after computeSubRegs() completes.
specifier|const
name|RegUnitList
operator|&
name|getRegUnits
argument_list|()
specifier|const
block|{
return|return
name|RegUnits
return|;
block|}
name|ArrayRef
operator|<
name|LaneBitmask
operator|>
name|getRegUnitLaneMasks
argument_list|()
specifier|const
block|{
return|return
name|makeArrayRef
argument_list|(
name|RegUnitLaneMasks
argument_list|)
operator|.
name|slice
argument_list|(
literal|0
argument_list|,
name|NativeRegUnits
operator|.
name|count
argument_list|()
argument_list|)
return|;
block|}
comment|// Get the native register units. This is a prefix of getRegUnits().
name|RegUnitList
name|getNativeRegUnits
argument_list|()
specifier|const
block|{
return|return
name|NativeRegUnits
return|;
block|}
name|void
name|setRegUnitLaneMasks
parameter_list|(
specifier|const
name|RegUnitLaneMaskList
modifier|&
name|LaneMasks
parameter_list|)
block|{
name|RegUnitLaneMasks
operator|=
name|LaneMasks
expr_stmt|;
block|}
comment|// Inherit register units from subregisters.
comment|// Return true if the RegUnits changed.
name|bool
name|inheritRegUnits
parameter_list|(
name|CodeGenRegBank
modifier|&
name|RegBank
parameter_list|)
function_decl|;
comment|// Adopt a register unit for pressure tracking.
comment|// A unit is adopted iff its unit number is>= NativeRegUnits.count().
name|void
name|adoptRegUnit
parameter_list|(
name|unsigned
name|RUID
parameter_list|)
block|{
name|RegUnits
operator|.
name|set
argument_list|(
name|RUID
argument_list|)
expr_stmt|;
block|}
comment|// Get the sum of this register's register unit weights.
name|unsigned
name|getWeight
argument_list|(
specifier|const
name|CodeGenRegBank
operator|&
name|RegBank
argument_list|)
decl|const
decl_stmt|;
comment|// Canonically ordered set.
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|CodeGenRegister
operator|*
operator|>
name|Vec
expr_stmt|;
name|private
label|:
name|bool
name|SubRegsComplete
decl_stmt|;
name|bool
name|SuperRegsComplete
decl_stmt|;
name|unsigned
name|TopoSig
decl_stmt|;
comment|// The sub-registers explicit in the .td file form a tree.
name|SmallVector
operator|<
name|CodeGenSubRegIndex
operator|*
operator|,
literal|8
operator|>
name|ExplicitSubRegIndices
expr_stmt|;
name|SmallVector
operator|<
name|CodeGenRegister
operator|*
operator|,
literal|8
operator|>
name|ExplicitSubRegs
expr_stmt|;
comment|// Explicit ad hoc aliases, symmetrized to form an undirected graph.
name|SmallVector
operator|<
name|CodeGenRegister
operator|*
operator|,
literal|8
operator|>
name|ExplicitAliases
expr_stmt|;
comment|// Super-registers where this is the first explicit sub-register.
name|SuperRegList
name|LeadingSuperRegs
decl_stmt|;
name|SubRegMap
name|SubRegs
decl_stmt|;
name|SuperRegList
name|SuperRegs
decl_stmt|;
name|DenseMap
operator|<
specifier|const
name|CodeGenRegister
operator|*
operator|,
name|CodeGenSubRegIndex
operator|*
operator|>
name|SubReg2Idx
expr_stmt|;
name|RegUnitList
name|RegUnits
decl_stmt|;
name|RegUnitLaneMaskList
name|RegUnitLaneMasks
decl_stmt|;
block|}
struct|;
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|CodeGenRegister
operator|&
name|A
operator|,
specifier|const
name|CodeGenRegister
operator|&
name|B
operator|)
block|{
return|return
name|A
operator|.
name|EnumValue
operator|<
name|B
operator|.
name|EnumValue
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|CodeGenRegister
operator|&
name|A
operator|,
specifier|const
name|CodeGenRegister
operator|&
name|B
operator|)
block|{
return|return
name|A
operator|.
name|EnumValue
operator|==
name|B
operator|.
name|EnumValue
return|;
block|}
name|class
name|CodeGenRegisterClass
block|{
name|CodeGenRegister
operator|::
name|Vec
name|Members
expr_stmt|;
comment|// Allocation orders. Order[0] always contains all registers in Members.
name|std
operator|::
name|vector
operator|<
name|SmallVector
operator|<
name|Record
operator|*
operator|,
literal|16
operator|>>
name|Orders
expr_stmt|;
comment|// Bit mask of sub-classes including this, indexed by their EnumValue.
name|BitVector
name|SubClasses
decl_stmt|;
comment|// List of super-classes, topologocally ordered to have the larger classes
comment|// first.  This is the same as sorting by EnumValue.
name|SmallVector
operator|<
name|CodeGenRegisterClass
operator|*
operator|,
literal|4
operator|>
name|SuperClasses
expr_stmt|;
name|Record
modifier|*
name|TheDef
decl_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|// For a synthesized class, inherit missing properties from the nearest
comment|// super-class.
name|void
name|inheritProperties
parameter_list|(
name|CodeGenRegBank
modifier|&
parameter_list|)
function_decl|;
comment|// Map SubRegIndex -> sub-class.  This is the largest sub-class where all
comment|// registers have a SubRegIndex sub-register.
name|DenseMap
operator|<
specifier|const
name|CodeGenSubRegIndex
operator|*
operator|,
name|CodeGenRegisterClass
operator|*
operator|>
name|SubClassWithSubReg
expr_stmt|;
comment|// Map SubRegIndex -> set of super-reg classes.  This is all register
comment|// classes SuperRC such that:
comment|//
comment|//   R:SubRegIndex in this RC for all R in SuperRC.
comment|//
name|DenseMap
operator|<
specifier|const
name|CodeGenSubRegIndex
operator|*
operator|,
name|SmallPtrSet
operator|<
name|CodeGenRegisterClass
operator|*
operator|,
literal|8
operator|>>
name|SuperRegClasses
expr_stmt|;
comment|// Bit vector of TopoSigs for the registers in this class. This will be
comment|// very sparse on regular architectures.
name|BitVector
name|TopoSigs
decl_stmt|;
name|public
label|:
name|unsigned
name|EnumValue
decl_stmt|;
name|StringRef
name|Namespace
decl_stmt|;
name|SmallVector
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|,
literal|4
operator|>
name|VTs
expr_stmt|;
name|unsigned
name|SpillSize
decl_stmt|;
name|unsigned
name|SpillAlignment
decl_stmt|;
name|int
name|CopyCost
decl_stmt|;
name|bool
name|Allocatable
decl_stmt|;
name|StringRef
name|AltOrderSelect
decl_stmt|;
name|uint8_t
name|AllocationPriority
decl_stmt|;
comment|/// Contains the combination of the lane masks of all subregisters.
name|LaneBitmask
name|LaneMask
decl_stmt|;
comment|/// True if there are at least 2 subregisters which do not interfere.
name|bool
name|HasDisjunctSubRegs
decl_stmt|;
name|bool
name|CoveredBySubRegs
decl_stmt|;
comment|// Return the Record that defined this class, or NULL if the class was
comment|// created by TableGen.
name|Record
operator|*
name|getDef
argument_list|()
specifier|const
block|{
return|return
name|TheDef
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|std
operator|::
name|string
name|getQualifiedName
argument_list|()
specifier|const
expr_stmt|;
name|ArrayRef
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|>
name|getValueTypes
argument_list|()
specifier|const
block|{
return|return
name|VTs
return|;
block|}
name|bool
name|hasValueType
argument_list|(
name|MVT
operator|::
name|SimpleValueType
name|VT
argument_list|)
decl|const
block|{
return|return
name|std
operator|::
name|find
argument_list|(
name|VTs
operator|.
name|begin
argument_list|()
argument_list|,
name|VTs
operator|.
name|end
argument_list|()
argument_list|,
name|VT
argument_list|)
operator|!=
name|VTs
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|getNumValueTypes
argument_list|()
specifier|const
block|{
return|return
name|VTs
operator|.
name|size
argument_list|()
return|;
block|}
name|MVT
operator|::
name|SimpleValueType
name|getValueTypeNum
argument_list|(
argument|unsigned VTNum
argument_list|)
specifier|const
block|{
if|if
condition|(
name|VTNum
operator|<
name|VTs
operator|.
name|size
argument_list|()
condition|)
return|return
name|VTs
index|[
name|VTNum
index|]
return|;
name|llvm_unreachable
argument_list|(
literal|"VTNum greater than number of ValueTypes in RegClass!"
argument_list|)
expr_stmt|;
block|}
comment|// Return true if this this class contains the register.
name|bool
name|contains
argument_list|(
specifier|const
name|CodeGenRegister
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|// Returns true if RC is a subclass.
comment|// RC is a sub-class of this class if it is a valid replacement for any
comment|// instruction operand where a register of this classis required. It must
comment|// satisfy these conditions:
comment|//
comment|// 1. All RC registers are also in this.
comment|// 2. The RC spill size must not be smaller than our spill size.
comment|// 3. RC spill alignment must be compatible with ours.
comment|//
name|bool
name|hasSubClass
argument_list|(
specifier|const
name|CodeGenRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
return|return
name|SubClasses
operator|.
name|test
argument_list|(
name|RC
operator|->
name|EnumValue
argument_list|)
return|;
block|}
comment|// getSubClassWithSubReg - Returns the largest sub-class where all
comment|// registers have a SubIdx sub-register.
name|CodeGenRegisterClass
modifier|*
name|getSubClassWithSubReg
argument_list|(
specifier|const
name|CodeGenSubRegIndex
operator|*
name|SubIdx
argument_list|)
decl|const
block|{
return|return
name|SubClassWithSubReg
operator|.
name|lookup
argument_list|(
name|SubIdx
argument_list|)
return|;
block|}
comment|/// Find largest subclass where all registers have SubIdx subregisters in
comment|/// SubRegClass and the largest subregister class that contains those
comment|/// subregisters without (as far as possible) also containing additional registers.
comment|///
comment|/// This can be used to find a suitable pair of classes for subregister copies.
comment|/// \return std::pair<SubClass, SubRegClass> where SubClass is a SubClass is
comment|/// a class where every register has SubIdx and SubRegClass is a class where
comment|/// every register is covered by the SubIdx subregister of SubClass.
name|Optional
operator|<
name|std
operator|::
name|pair
operator|<
name|CodeGenRegisterClass
operator|*
operator|,
name|CodeGenRegisterClass
operator|*
operator|>>
name|getMatchingSubClassWithSubRegs
argument_list|(
argument|CodeGenRegBank&RegBank
argument_list|,
argument|const CodeGenSubRegIndex *SubIdx
argument_list|)
specifier|const
expr_stmt|;
name|void
name|setSubClassWithSubReg
parameter_list|(
specifier|const
name|CodeGenSubRegIndex
modifier|*
name|SubIdx
parameter_list|,
name|CodeGenRegisterClass
modifier|*
name|SubRC
parameter_list|)
block|{
name|SubClassWithSubReg
index|[
name|SubIdx
index|]
operator|=
name|SubRC
expr_stmt|;
block|}
comment|// getSuperRegClasses - Returns a bit vector of all register classes
comment|// containing only SubIdx super-registers of this class.
name|void
name|getSuperRegClasses
argument_list|(
specifier|const
name|CodeGenSubRegIndex
operator|*
name|SubIdx
argument_list|,
name|BitVector
operator|&
name|Out
argument_list|)
decl|const
decl_stmt|;
comment|// addSuperRegClass - Add a class containing only SubIdx super-registers.
name|void
name|addSuperRegClass
parameter_list|(
name|CodeGenSubRegIndex
modifier|*
name|SubIdx
parameter_list|,
name|CodeGenRegisterClass
modifier|*
name|SuperRC
parameter_list|)
block|{
name|SuperRegClasses
index|[
name|SubIdx
index|]
operator|.
name|insert
argument_list|(
name|SuperRC
argument_list|)
expr_stmt|;
block|}
comment|// getSubClasses - Returns a constant BitVector of subclasses indexed by
comment|// EnumValue.
comment|// The SubClasses vector includes an entry for this class.
specifier|const
name|BitVector
operator|&
name|getSubClasses
argument_list|()
specifier|const
block|{
return|return
name|SubClasses
return|;
block|}
comment|// getSuperClasses - Returns a list of super classes ordered by EnumValue.
comment|// The array does not include an entry for this class.
name|ArrayRef
operator|<
name|CodeGenRegisterClass
operator|*
operator|>
name|getSuperClasses
argument_list|()
specifier|const
block|{
return|return
name|SuperClasses
return|;
block|}
comment|// Returns an ordered list of class members.
comment|// The order of registers is the same as in the .td file.
comment|// No = 0 is the default allocation order, No = 1 is the first alternative.
name|ArrayRef
operator|<
name|Record
operator|*
operator|>
name|getOrder
argument_list|(
argument|unsigned No =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|Orders
index|[
name|No
index|]
return|;
block|}
comment|// Return the total number of allocation orders available.
name|unsigned
name|getNumOrders
argument_list|()
specifier|const
block|{
return|return
name|Orders
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Get the set of registers.  This set contains the same registers as
comment|// getOrder(0).
specifier|const
name|CodeGenRegister
operator|::
name|Vec
operator|&
name|getMembers
argument_list|()
specifier|const
block|{
return|return
name|Members
return|;
block|}
comment|// Get a bit vector of TopoSigs present in this register class.
specifier|const
name|BitVector
operator|&
name|getTopoSigs
argument_list|()
specifier|const
block|{
return|return
name|TopoSigs
return|;
block|}
comment|// Populate a unique sorted list of units from a register set.
name|void
name|buildRegUnitSet
argument_list|(
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|RegUnits
argument_list|)
decl|const
decl_stmt|;
name|CodeGenRegisterClass
argument_list|(
name|CodeGenRegBank
operator|&
argument_list|,
name|Record
operator|*
name|R
argument_list|)
expr_stmt|;
comment|// A key representing the parts of a register class used for forming
comment|// sub-classes.  Note the ordering provided by this key is not the same as
comment|// the topological order used for the EnumValues.
struct|struct
name|Key
block|{
specifier|const
name|CodeGenRegister
operator|::
name|Vec
operator|*
name|Members
expr_stmt|;
name|unsigned
name|SpillSize
decl_stmt|;
name|unsigned
name|SpillAlignment
decl_stmt|;
name|Key
argument_list|(
argument|const CodeGenRegister::Vec *M
argument_list|,
argument|unsigned S =
literal|0
argument_list|,
argument|unsigned A =
literal|0
argument_list|)
block|:
name|Members
argument_list|(
name|M
argument_list|)
operator|,
name|SpillSize
argument_list|(
name|S
argument_list|)
operator|,
name|SpillAlignment
argument_list|(
argument|A
argument_list|)
block|{}
name|Key
argument_list|(
specifier|const
name|CodeGenRegisterClass
operator|&
name|RC
argument_list|)
operator|:
name|Members
argument_list|(
operator|&
name|RC
operator|.
name|getMembers
argument_list|()
argument_list|)
operator|,
name|SpillSize
argument_list|(
name|RC
operator|.
name|SpillSize
argument_list|)
operator|,
name|SpillAlignment
argument_list|(
argument|RC.SpillAlignment
argument_list|)
block|{}
comment|// Lexicographical order of (Members, SpillSize, SpillAlignment).
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Key
operator|&
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
comment|// Create a non-user defined register class.
name|CodeGenRegisterClass
argument_list|(
argument|CodeGenRegBank&
argument_list|,
argument|StringRef Name
argument_list|,
argument|Key Props
argument_list|)
empty_stmt|;
comment|// Called by CodeGenRegBank::CodeGenRegBank().
specifier|static
name|void
name|computeSubClasses
parameter_list|(
name|CodeGenRegBank
modifier|&
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Register units are used to model interference and register pressure.
end_comment

begin_comment
comment|// Every register is assigned one or more register units such that two
end_comment

begin_comment
comment|// registers overlap if and only if they have a register unit in common.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Normally, one register unit is created per leaf register. Non-leaf
end_comment

begin_comment
comment|// registers inherit the units of their sub-registers.
end_comment

begin_struct
struct|struct
name|RegUnit
block|{
comment|// Weight assigned to this RegUnit for estimating register pressure.
comment|// This is useful when equalizing weights in register classes with mixed
comment|// register topologies.
name|unsigned
name|Weight
decl_stmt|;
comment|// Each native RegUnit corresponds to one or two root registers. The full
comment|// set of registers containing this unit can be computed as the union of
comment|// these two registers and their super-registers.
specifier|const
name|CodeGenRegister
modifier|*
name|Roots
index|[
literal|2
index|]
decl_stmt|;
comment|// Index into RegClassUnitSets where we can find the list of UnitSets that
comment|// contain this unit.
name|unsigned
name|RegClassUnitSetsIdx
decl_stmt|;
name|RegUnit
argument_list|()
operator|:
name|Weight
argument_list|(
literal|0
argument_list|)
operator|,
name|RegClassUnitSetsIdx
argument_list|(
literal|0
argument_list|)
block|{
name|Roots
index|[
literal|0
index|]
operator|=
name|Roots
index|[
literal|1
index|]
operator|=
name|nullptr
block|;     }
name|ArrayRef
operator|<
specifier|const
name|CodeGenRegister
operator|*
operator|>
name|getRoots
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
operator|(
name|Roots
index|[
literal|1
index|]
operator|&&
operator|!
name|Roots
index|[
literal|0
index|]
operator|)
operator|&&
literal|"Invalid roots array"
argument_list|)
block|;
return|return
name|makeArrayRef
argument_list|(
name|Roots
argument_list|,
operator|!
operator|!
name|Roots
index|[
literal|0
index|]
operator|+
operator|!
operator|!
name|Roots
index|[
literal|1
index|]
argument_list|)
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|// Each RegUnitSet is a sorted vector with a name.
end_comment

begin_struct
struct|struct
name|RegUnitSet
block|{
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|Units
expr_stmt|;
name|unsigned
name|Weight
init|=
literal|0
decl_stmt|;
comment|// Cache the sum of all unit weights.
name|unsigned
name|Order
init|=
literal|0
decl_stmt|;
comment|// Cache the sort key.
name|RegUnitSet
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Base vector for identifying TopoSigs. The contents uniquely identify a
end_comment

begin_comment
comment|// TopoSig, only computeSuperRegs needs to know how.
end_comment

begin_typedef
typedef|typedef
name|SmallVector
operator|<
name|unsigned
operator|,
literal|16
operator|>
name|TopoSigId
expr_stmt|;
end_typedef

begin_comment
comment|// CodeGenRegBank - Represent a target's registers and the relations between
end_comment

begin_comment
comment|// them.
end_comment

begin_decl_stmt
name|class
name|CodeGenRegBank
block|{
name|SetTheory
name|Sets
decl_stmt|;
name|std
operator|::
name|deque
operator|<
name|CodeGenSubRegIndex
operator|>
name|SubRegIndices
expr_stmt|;
name|DenseMap
operator|<
name|Record
operator|*
operator|,
name|CodeGenSubRegIndex
operator|*
operator|>
name|Def2SubRegIdx
expr_stmt|;
name|CodeGenSubRegIndex
modifier|*
name|createSubRegIndex
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|StringRef
name|NameSpace
parameter_list|)
function_decl|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|SmallVector
operator|<
name|CodeGenSubRegIndex
operator|*
operator|,
literal|8
operator|>
operator|,
name|CodeGenSubRegIndex
operator|*
operator|>
name|ConcatIdxMap
expr_stmt|;
name|ConcatIdxMap
name|ConcatIdx
decl_stmt|;
comment|// Registers.
name|std
operator|::
name|deque
operator|<
name|CodeGenRegister
operator|>
name|Registers
expr_stmt|;
name|StringMap
operator|<
name|CodeGenRegister
operator|*
operator|>
name|RegistersByName
expr_stmt|;
name|DenseMap
operator|<
name|Record
operator|*
operator|,
name|CodeGenRegister
operator|*
operator|>
name|Def2Reg
expr_stmt|;
name|unsigned
name|NumNativeRegUnits
decl_stmt|;
name|std
operator|::
name|map
operator|<
name|TopoSigId
operator|,
name|unsigned
operator|>
name|TopoSigs
expr_stmt|;
comment|// Includes native (0..NumNativeRegUnits-1) and adopted register units.
name|SmallVector
operator|<
name|RegUnit
operator|,
literal|8
operator|>
name|RegUnits
expr_stmt|;
comment|// Register classes.
name|std
operator|::
name|list
operator|<
name|CodeGenRegisterClass
operator|>
name|RegClasses
expr_stmt|;
name|DenseMap
operator|<
name|Record
operator|*
operator|,
name|CodeGenRegisterClass
operator|*
operator|>
name|Def2RC
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|CodeGenRegisterClass
operator|::
name|Key
operator|,
name|CodeGenRegisterClass
operator|*
operator|>
name|RCKeyMap
expr_stmt|;
name|RCKeyMap
name|Key2RC
decl_stmt|;
comment|// Remember each unique set of register units. Initially, this contains a
comment|// unique set for each register class. Simliar sets are coalesced with
comment|// pruneUnitSets and new supersets are inferred during computeRegUnitSets.
name|std
operator|::
name|vector
operator|<
name|RegUnitSet
operator|>
name|RegUnitSets
expr_stmt|;
comment|// Map RegisterClass index to the index of the RegUnitSet that contains the
comment|// class's units and any inferred RegUnit supersets.
comment|//
comment|// NOTE: This could grow beyond the number of register classes when we map
comment|// register units to lists of unit sets. If the list of unit sets does not
comment|// already exist for a register class, we create a new entry in this vector.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>>
name|RegClassUnitSets
expr_stmt|;
comment|// Give each register unit set an order based on sorting criteria.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|RegUnitSetOrder
expr_stmt|;
comment|// Add RC to *2RC maps.
name|void
name|addToMaps
parameter_list|(
name|CodeGenRegisterClass
modifier|*
parameter_list|)
function_decl|;
comment|// Create a synthetic sub-class if it is missing.
name|CodeGenRegisterClass
modifier|*
name|getOrCreateSubClass
argument_list|(
specifier|const
name|CodeGenRegisterClass
operator|*
name|RC
argument_list|,
specifier|const
name|CodeGenRegister
operator|::
name|Vec
operator|*
name|Membs
argument_list|,
name|StringRef
name|Name
argument_list|)
decl_stmt|;
comment|// Infer missing register classes.
name|void
name|computeInferredRegisterClasses
parameter_list|()
function_decl|;
name|void
name|inferCommonSubClass
parameter_list|(
name|CodeGenRegisterClass
modifier|*
name|RC
parameter_list|)
function_decl|;
name|void
name|inferSubClassWithSubReg
parameter_list|(
name|CodeGenRegisterClass
modifier|*
name|RC
parameter_list|)
function_decl|;
name|void
name|inferMatchingSuperRegClass
parameter_list|(
name|CodeGenRegisterClass
modifier|*
name|RC
parameter_list|)
block|{
name|inferMatchingSuperRegClass
argument_list|(
name|RC
argument_list|,
name|RegClasses
operator|.
name|begin
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|inferMatchingSuperRegClass
argument_list|(
name|CodeGenRegisterClass
operator|*
name|RC
argument_list|,
name|std
operator|::
name|list
operator|<
name|CodeGenRegisterClass
operator|>
operator|::
name|iterator
name|FirstSubRegRC
argument_list|)
decl_stmt|;
comment|// Iteratively prune unit sets.
name|void
name|pruneUnitSets
parameter_list|()
function_decl|;
comment|// Compute a weight for each register unit created during getSubRegs.
name|void
name|computeRegUnitWeights
parameter_list|()
function_decl|;
comment|// Create a RegUnitSet for each RegClass and infer superclasses.
name|void
name|computeRegUnitSets
parameter_list|()
function_decl|;
comment|// Populate the Composite map from sub-register relationships.
name|void
name|computeComposites
parameter_list|()
function_decl|;
comment|// Compute a lane mask for each sub-register index.
name|void
name|computeSubRegLaneMasks
parameter_list|()
function_decl|;
comment|/// Computes a lane mask for each register unit enumerated by a physical
comment|/// register.
name|void
name|computeRegUnitLaneMasks
parameter_list|()
function_decl|;
name|public
label|:
name|CodeGenRegBank
argument_list|(
name|RecordKeeper
operator|&
argument_list|)
expr_stmt|;
name|SetTheory
modifier|&
name|getSets
parameter_list|()
block|{
return|return
name|Sets
return|;
block|}
comment|// Sub-register indices. The first NumNamedIndices are defined by the user
comment|// in the .td files. The rest are synthesized such that all sub-registers
comment|// have a unique name.
specifier|const
name|std
operator|::
name|deque
operator|<
name|CodeGenSubRegIndex
operator|>
operator|&
name|getSubRegIndices
argument_list|()
specifier|const
block|{
return|return
name|SubRegIndices
return|;
block|}
comment|// Find a SubRegIndex form its Record def.
name|CodeGenSubRegIndex
modifier|*
name|getSubRegIdx
parameter_list|(
name|Record
modifier|*
parameter_list|)
function_decl|;
comment|// Find or create a sub-register index representing the A+B composition.
name|CodeGenSubRegIndex
modifier|*
name|getCompositeSubRegIndex
parameter_list|(
name|CodeGenSubRegIndex
modifier|*
name|A
parameter_list|,
name|CodeGenSubRegIndex
modifier|*
name|B
parameter_list|)
function_decl|;
comment|// Find or create a sub-register index representing the concatenation of
comment|// non-overlapping sibling indices.
name|CodeGenSubRegIndex
modifier|*
name|getConcatSubRegIndex
argument_list|(
specifier|const
name|SmallVector
operator|<
name|CodeGenSubRegIndex
operator|*
argument_list|,
literal|8
operator|>
operator|&
argument_list|)
decl_stmt|;
name|void
name|addConcatSubRegIndex
argument_list|(
specifier|const
name|SmallVector
operator|<
name|CodeGenSubRegIndex
operator|*
argument_list|,
literal|8
operator|>
operator|&
name|Parts
argument_list|,
name|CodeGenSubRegIndex
operator|*
name|Idx
argument_list|)
block|{
name|ConcatIdx
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Parts
argument_list|,
name|Idx
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|const
name|std
operator|::
name|deque
operator|<
name|CodeGenRegister
operator|>
operator|&
name|getRegisters
argument_list|()
block|{
return|return
name|Registers
return|;
block|}
specifier|const
name|StringMap
operator|<
name|CodeGenRegister
operator|*
operator|>
operator|&
name|getRegistersByName
argument_list|()
block|{
return|return
name|RegistersByName
return|;
block|}
comment|// Find a register from its Record def.
name|CodeGenRegister
modifier|*
name|getReg
parameter_list|(
name|Record
modifier|*
parameter_list|)
function_decl|;
comment|// Get a Register's index into the Registers array.
name|unsigned
name|getRegIndex
argument_list|(
specifier|const
name|CodeGenRegister
operator|*
name|Reg
argument_list|)
decl|const
block|{
return|return
name|Reg
operator|->
name|EnumValue
operator|-
literal|1
return|;
block|}
comment|// Return the number of allocated TopoSigs. The first TopoSig representing
comment|// leaf registers is allocated number 0.
name|unsigned
name|getNumTopoSigs
argument_list|()
specifier|const
block|{
return|return
name|TopoSigs
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Find or create a TopoSig for the given TopoSigId.
comment|// This function is only for use by CodeGenRegister::computeSuperRegs().
comment|// Others should simply use Reg->getTopoSig().
name|unsigned
name|getTopoSig
parameter_list|(
specifier|const
name|TopoSigId
modifier|&
name|Id
parameter_list|)
block|{
return|return
name|TopoSigs
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Id
argument_list|,
name|TopoSigs
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
operator|.
name|first
operator|->
name|second
return|;
block|}
comment|// Create a native register unit that is associated with one or two root
comment|// registers.
name|unsigned
name|newRegUnit
parameter_list|(
name|CodeGenRegister
modifier|*
name|R0
parameter_list|,
name|CodeGenRegister
modifier|*
name|R1
init|=
name|nullptr
parameter_list|)
block|{
name|RegUnits
operator|.
name|resize
argument_list|(
name|RegUnits
operator|.
name|size
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
name|RegUnits
operator|.
name|back
argument_list|()
operator|.
name|Roots
index|[
literal|0
index|]
operator|=
name|R0
expr_stmt|;
name|RegUnits
operator|.
name|back
argument_list|()
operator|.
name|Roots
index|[
literal|1
index|]
operator|=
name|R1
expr_stmt|;
return|return
name|RegUnits
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
comment|// Create a new non-native register unit that can be adopted by a register
comment|// to increase its pressure. Note that NumNativeRegUnits is not increased.
name|unsigned
name|newRegUnit
parameter_list|(
name|unsigned
name|Weight
parameter_list|)
block|{
name|RegUnits
operator|.
name|resize
argument_list|(
name|RegUnits
operator|.
name|size
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
name|RegUnits
operator|.
name|back
argument_list|()
operator|.
name|Weight
operator|=
name|Weight
expr_stmt|;
return|return
name|RegUnits
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
comment|// Native units are the singular unit of a leaf register. Register aliasing
comment|// is completely characterized by native units. Adopted units exist to give
comment|// register additional weight but don't affect aliasing.
name|bool
name|isNativeUnit
parameter_list|(
name|unsigned
name|RUID
parameter_list|)
block|{
return|return
name|RUID
operator|<
name|NumNativeRegUnits
return|;
block|}
name|unsigned
name|getNumNativeRegUnits
argument_list|()
specifier|const
block|{
return|return
name|NumNativeRegUnits
return|;
block|}
name|RegUnit
modifier|&
name|getRegUnit
parameter_list|(
name|unsigned
name|RUID
parameter_list|)
block|{
return|return
name|RegUnits
index|[
name|RUID
index|]
return|;
block|}
specifier|const
name|RegUnit
modifier|&
name|getRegUnit
argument_list|(
name|unsigned
name|RUID
argument_list|)
decl|const
block|{
return|return
name|RegUnits
index|[
name|RUID
index|]
return|;
block|}
name|std
operator|::
name|list
operator|<
name|CodeGenRegisterClass
operator|>
operator|&
name|getRegClasses
argument_list|()
block|{
return|return
name|RegClasses
return|;
block|}
specifier|const
name|std
operator|::
name|list
operator|<
name|CodeGenRegisterClass
operator|>
operator|&
name|getRegClasses
argument_list|()
specifier|const
block|{
return|return
name|RegClasses
return|;
block|}
comment|// Find a register class from its def.
name|CodeGenRegisterClass
modifier|*
name|getRegClass
parameter_list|(
name|Record
modifier|*
parameter_list|)
function_decl|;
comment|/// getRegisterClassForRegister - Find the register class that contains the
comment|/// specified physical register.  If the register is not in a register
comment|/// class, return null. If the register is in multiple classes, and the
comment|/// classes have a superset-subset relationship and the same set of types,
comment|/// return the superclass.  Otherwise return null.
specifier|const
name|CodeGenRegisterClass
modifier|*
name|getRegClassForRegister
parameter_list|(
name|Record
modifier|*
name|R
parameter_list|)
function_decl|;
comment|// Get the sum of unit weights.
name|unsigned
name|getRegUnitSetWeight
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|Units
argument_list|)
decl|const
block|{
name|unsigned
name|Weight
init|=
literal|0
decl_stmt|;
for|for
control|(
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|Units
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|Units
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|Weight
operator|+=
name|getRegUnit
argument_list|(
operator|*
name|I
argument_list|)
operator|.
name|Weight
expr_stmt|;
return|return
name|Weight
return|;
block|}
name|unsigned
name|getRegSetIDAt
argument_list|(
name|unsigned
name|Order
argument_list|)
decl|const
block|{
return|return
name|RegUnitSetOrder
index|[
name|Order
index|]
return|;
block|}
specifier|const
name|RegUnitSet
modifier|&
name|getRegSetAt
argument_list|(
name|unsigned
name|Order
argument_list|)
decl|const
block|{
return|return
name|RegUnitSets
index|[
name|RegUnitSetOrder
index|[
name|Order
index|]
index|]
return|;
block|}
comment|// Increase a RegUnitWeight.
name|void
name|increaseRegUnitWeight
parameter_list|(
name|unsigned
name|RUID
parameter_list|,
name|unsigned
name|Inc
parameter_list|)
block|{
name|getRegUnit
argument_list|(
name|RUID
argument_list|)
operator|.
name|Weight
operator|+=
name|Inc
expr_stmt|;
block|}
comment|// Get the number of register pressure dimensions.
name|unsigned
name|getNumRegPressureSets
argument_list|()
specifier|const
block|{
return|return
name|RegUnitSets
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Get a set of register unit IDs for a given dimension of pressure.
specifier|const
name|RegUnitSet
modifier|&
name|getRegPressureSet
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
return|return
name|RegUnitSets
index|[
name|Idx
index|]
return|;
block|}
comment|// The number of pressure set lists may be larget than the number of
comment|// register classes if some register units appeared in a list of sets that
comment|// did not correspond to an existing register class.
name|unsigned
name|getNumRegClassPressureSetLists
argument_list|()
specifier|const
block|{
return|return
name|RegClassUnitSets
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Get a list of pressure set IDs for a register class. Liveness of a
comment|// register in this class impacts each pressure set in this list by the
comment|// weight of the register. An exact solution requires all registers in a
comment|// class to have the same class, but it is not strictly guaranteed.
name|ArrayRef
operator|<
name|unsigned
operator|>
name|getRCPressureSetIDs
argument_list|(
argument|unsigned RCIdx
argument_list|)
specifier|const
block|{
return|return
name|RegClassUnitSets
index|[
name|RCIdx
index|]
return|;
block|}
comment|// Computed derived records such as missing sub-register indices.
name|void
name|computeDerivedInfo
parameter_list|()
function_decl|;
comment|// Compute the set of registers completely covered by the registers in Regs.
comment|// The returned BitVector will have a bit set for each register in Regs,
comment|// all sub-registers, and all super-registers that are covered by the
comment|// registers in Regs.
comment|//
comment|// This is used to compute the mask of call-preserved registers from a list
comment|// of callee-saves.
name|BitVector
name|computeCoveredRegisters
argument_list|(
name|ArrayRef
operator|<
name|Record
operator|*
operator|>
name|Regs
argument_list|)
decl_stmt|;
comment|// Bit mask of lanes that cover their registers. A sub-register index whose
comment|// LaneMask is contained in CoveringLanes will be completely covered by
comment|// another sub-register with the same or larger lane mask.
name|LaneBitmask
name|CoveringLanes
decl_stmt|;
comment|// Helper function for printing debug information. Handles artificial
comment|// (non-native) reg units.
name|void
name|printRegUnitName
argument_list|(
name|unsigned
name|Unit
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_UTILS_TABLEGEN_CODEGENREGISTERS_H
end_comment

end_unit

