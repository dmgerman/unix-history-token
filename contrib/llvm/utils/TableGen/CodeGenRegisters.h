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
name|CODEGEN_REGISTERS_H
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_REGISTERS_H
end_define

begin_include
include|#
directive|include
file|"Record.h"
end_include

begin_include
include|#
directive|include
file|"SetTheory.h"
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
file|<cstdlib>
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
file|<set>
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
comment|// Map SubRegIndex -> Register.
typedef|typedef
name|std
operator|::
name|map
operator|<
name|Record
operator|*
operator|,
name|CodeGenRegister
operator|*
operator|,
name|LessRecord
operator|>
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
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
expr_stmt|;
comment|// Get a map of sub-registers computed lazily.
comment|// This includes unique entries for all sub-sub-registers.
specifier|const
name|SubRegMap
modifier|&
name|getSubRegs
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
name|CodeGenRegister
operator|*
operator|>
operator|&
name|OSet
argument_list|)
decl|const
decl_stmt|;
comment|// List of super-registers in topological order, small to large.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CodeGenRegister
operator|*
operator|>
name|SuperRegList
expr_stmt|;
comment|// Get the list of super-registers.
comment|// This is only valid after computeDerivedInfo has visited all registers.
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
comment|// Order CodeGenRegister pointers by EnumValue.
struct|struct
name|Less
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|CodeGenRegister
operator|*
name|A
operator|,
specifier|const
name|CodeGenRegister
operator|*
name|B
operator|)
specifier|const
block|{
return|return
name|A
operator|->
name|EnumValue
operator|<
name|B
operator|->
name|EnumValue
return|;
block|}
block|}
struct|;
comment|// Canonically ordered set.
typedef|typedef
name|std
operator|::
name|set
operator|<
specifier|const
name|CodeGenRegister
operator|*
operator|,
name|Less
operator|>
name|Set
expr_stmt|;
name|private
label|:
name|bool
name|SubRegsComplete
decl_stmt|;
name|SubRegMap
name|SubRegs
decl_stmt|;
name|SuperRegList
name|SuperRegs
decl_stmt|;
block|}
struct|;
name|class
name|CodeGenRegisterClass
block|{
name|CodeGenRegister
operator|::
name|Set
name|Members
expr_stmt|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
operator|*
name|Elements
expr_stmt|;
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
operator|>
expr|>
name|AltOrders
expr_stmt|;
name|public
label|:
name|Record
modifier|*
name|TheDef
decl_stmt|;
name|std
operator|::
name|string
name|Namespace
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|MVT
operator|::
name|SimpleValueType
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
comment|// Map SubRegIndex -> RegisterClass
name|DenseMap
operator|<
name|Record
operator|*
operator|,
name|Record
operator|*
operator|>
name|SubRegClasses
expr_stmt|;
name|std
operator|::
name|string
name|AltOrderSelect
expr_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|>
operator|&
name|getValueTypes
argument_list|()
specifier|const
block|{
return|return
name|VTs
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
name|assert
argument_list|(
literal|0
operator|&&
literal|"VTNum greater than number of ValueTypes in RegClass!"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
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
decl_stmt|;
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
if|if
condition|(
name|No
operator|==
literal|0
condition|)
return|return
operator|*
name|Elements
return|;
else|else
return|return
name|AltOrders
index|[
name|No
operator|-
literal|1
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
literal|1
operator|+
name|AltOrders
operator|.
name|size
argument_list|()
return|;
block|}
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|RecordKeeper
modifier|&
name|Records
decl_stmt|;
name|SetTheory
name|Sets
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
name|SubRegIndices
expr_stmt|;
name|unsigned
name|NumNamedIndices
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|CodeGenRegister
operator|*
operator|>
name|Registers
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
name|std
operator|::
name|vector
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
comment|// Composite SubRegIndex instances.
comment|// Map (SubRegIndex, SubRegIndex) -> SubRegIndex.
typedef|typedef
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
name|Record
operator|*
operator|,
name|Record
operator|*
operator|>
operator|,
name|Record
operator|*
operator|>
name|CompositeMap
expr_stmt|;
name|CompositeMap
name|Composite
decl_stmt|;
comment|// Populate the Composite map from sub-register relationships.
name|void
name|computeComposites
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
name|vector
operator|<
name|Record
operator|*
operator|>
operator|&
name|getSubRegIndices
argument_list|()
block|{
return|return
name|SubRegIndices
return|;
block|}
name|unsigned
name|getNumNamedIndices
parameter_list|()
block|{
return|return
name|NumNamedIndices
return|;
block|}
comment|// Map a SubRegIndex Record to its enum value.
name|unsigned
name|getSubRegIndexNo
parameter_list|(
name|Record
modifier|*
name|idx
parameter_list|)
function_decl|;
comment|// Find or create a sub-register index representing the A+B composition.
name|Record
modifier|*
name|getCompositeSubRegIndex
parameter_list|(
name|Record
modifier|*
name|A
parameter_list|,
name|Record
modifier|*
name|B
parameter_list|,
name|bool
name|create
init|=
name|false
parameter_list|)
function_decl|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|CodeGenRegister
operator|*
operator|>
operator|&
name|getRegisters
argument_list|()
block|{
return|return
name|Registers
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
specifier|const
name|std
operator|::
name|vector
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
comment|// Computed derived records such as missing sub-register indices.
name|void
name|computeDerivedInfo
parameter_list|()
function_decl|;
comment|// Compute full overlap sets for every register. These sets include the
comment|// rarely used aliases that are neither sub nor super-registers.
comment|//
comment|// Map[R1].count(R2) is reflexive and symmetric, but not transitive.
comment|//
comment|// If R1 is a sub-register of R2, Map[R1] is a subset of Map[R2].
name|void
name|computeOverlaps
argument_list|(
name|std
operator|::
name|map
operator|<
specifier|const
name|CodeGenRegister
operator|*
argument_list|,
name|CodeGenRegister
operator|::
name|Set
operator|>
operator|&
name|Map
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

