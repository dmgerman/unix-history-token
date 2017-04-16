begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- BitTracker.h -------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_HEXAGON_BITTRACKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_BITTRACKER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineOperand.h"
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
file|<map>
end_include

begin_include
include|#
directive|include
file|<queue>
end_include

begin_include
include|#
directive|include
file|<set>
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
name|class
name|ConstantInt
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
struct|struct
name|BitTracker
block|{
struct_decl|struct
name|BitRef
struct_decl|;
struct_decl|struct
name|RegisterRef
struct_decl|;
struct_decl|struct
name|BitValue
struct_decl|;
struct_decl|struct
name|BitMask
struct_decl|;
struct_decl|struct
name|RegisterCell
struct_decl|;
struct_decl|struct
name|MachineEvaluator
struct_decl|;
typedef|typedef
name|SetVector
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|>
name|BranchTargetList
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|RegisterCell
operator|>
name|CellMapType
expr_stmt|;
name|BitTracker
argument_list|(
specifier|const
name|MachineEvaluator
operator|&
name|E
argument_list|,
name|MachineFunction
operator|&
name|F
argument_list|)
expr_stmt|;
operator|~
name|BitTracker
argument_list|()
expr_stmt|;
name|void
name|run
parameter_list|()
function_decl|;
name|void
name|trace
parameter_list|(
name|bool
name|On
init|=
name|false
parameter_list|)
block|{
name|Trace
operator|=
name|On
expr_stmt|;
block|}
name|bool
name|has
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|RegisterCell
modifier|&
name|lookup
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
name|RegisterCell
name|get
argument_list|(
name|RegisterRef
name|RR
argument_list|)
decl|const
decl_stmt|;
name|void
name|put
parameter_list|(
name|RegisterRef
name|RR
parameter_list|,
specifier|const
name|RegisterCell
modifier|&
name|RC
parameter_list|)
function_decl|;
name|void
name|subst
parameter_list|(
name|RegisterRef
name|OldRR
parameter_list|,
name|RegisterRef
name|NewRR
parameter_list|)
function_decl|;
name|bool
name|reached
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|B
argument_list|)
decl|const
decl_stmt|;
name|void
name|visit
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
name|void
name|print_cells
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|visitPHI
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|PI
parameter_list|)
function_decl|;
name|void
name|visitNonBranch
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
name|void
name|visitBranchesFrom
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|BI
parameter_list|)
function_decl|;
name|void
name|visitUsesOf
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
name|void
name|reset
parameter_list|()
function_decl|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|int
operator|>
name|CFGEdge
expr_stmt|;
typedef|typedef
name|std
operator|::
name|set
operator|<
name|CFGEdge
operator|>
name|EdgeSetType
expr_stmt|;
typedef|typedef
name|std
operator|::
name|set
operator|<
specifier|const
name|MachineInstr
operator|*
operator|>
name|InstrSetType
expr_stmt|;
typedef|typedef
name|std
operator|::
name|queue
operator|<
name|CFGEdge
operator|>
name|EdgeQueueType
expr_stmt|;
name|EdgeSetType
name|EdgeExec
decl_stmt|;
comment|// Executable flow graph edges.
name|InstrSetType
name|InstrExec
decl_stmt|;
comment|// Executable instructions.
name|EdgeQueueType
name|FlowQ
decl_stmt|;
comment|// Work queue of CFG edges.
name|bool
name|Trace
decl_stmt|;
comment|// Enable tracing for debugging.
specifier|const
name|MachineEvaluator
modifier|&
name|ME
decl_stmt|;
name|MachineFunction
modifier|&
name|MF
decl_stmt|;
name|MachineRegisterInfo
modifier|&
name|MRI
decl_stmt|;
name|CellMapType
modifier|&
name|Map
decl_stmt|;
block|}
struct|;
comment|// Abstraction of a reference to bit at position Pos from a register Reg.
block|struct
name|BitTracker
operator|::
name|BitRef
block|{
name|BitRef
argument_list|(
argument|unsigned R =
literal|0
argument_list|,
argument|uint16_t P =
literal|0
argument_list|)
operator|:
name|Reg
argument_list|(
name|R
argument_list|)
block|,
name|Pos
argument_list|(
argument|P
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|BitRef
operator|&
name|BR
operator|)
specifier|const
block|{
comment|// If Reg is 0, disregard Pos.
return|return
name|Reg
operator|==
name|BR
operator|.
name|Reg
operator|&&
operator|(
name|Reg
operator|==
literal|0
operator|||
name|Pos
operator|==
name|BR
operator|.
name|Pos
operator|)
return|;
block|}
name|unsigned
name|Reg
block|;
name|uint16_t
name|Pos
block|; }
expr_stmt|;
comment|// Abstraction of a register reference in MachineOperand.  It contains the
comment|// register number and the subregister index.
block|struct
name|BitTracker
operator|::
name|RegisterRef
block|{
name|RegisterRef
argument_list|(
argument|unsigned R =
literal|0
argument_list|,
argument|unsigned S =
literal|0
argument_list|)
operator|:
name|Reg
argument_list|(
name|R
argument_list|)
block|,
name|Sub
argument_list|(
argument|S
argument_list|)
block|{}
name|RegisterRef
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|)
operator|:
name|Reg
argument_list|(
name|MO
operator|.
name|getReg
argument_list|()
argument_list|)
block|,
name|Sub
argument_list|(
argument|MO.getSubReg()
argument_list|)
block|{}
name|unsigned
name|Reg
block|,
name|Sub
block|; }
expr_stmt|;
comment|// Value that a single bit can take.  This is outside of the context of
comment|// any register, it is more of an abstraction of the two-element set of
comment|// possible bit values.  One extension here is the "Ref" type, which
comment|// indicates that this bit takes the same value as the bit described by
comment|// RefInfo.
block|struct
name|BitTracker
operator|::
name|BitValue
block|{   enum
name|ValueType
block|{
name|Top
block|,
comment|// Bit not yet defined.
name|Zero
block|,
comment|// Bit = 0.
name|One
block|,
comment|// Bit = 1.
name|Ref
comment|// Bit value same as the one described in RefI.
comment|// Conceptually, there is no explicit "bottom" value: the lattice's
comment|// bottom will be expressed as a "ref to itself", which, in the context
comment|// of registers, could be read as "this value of this bit is defined by
comment|// this bit".
comment|// The ordering is:
comment|//   x<= Top,
comment|//   Self<= x, where "Self" is "ref to itself".
comment|// This makes the value lattice different for each virtual register
comment|// (even for each bit in the same virtual register), since the "bottom"
comment|// for one register will be a simple "ref" for another register.
comment|// Since we do not store the "Self" bit and register number, the meet
comment|// operation will need to take it as a parameter.
comment|//
comment|// In practice there is a special case for values that are not associa-
comment|// ted with any specific virtual register. An example would be a value
comment|// corresponding to a bit of a physical register, or an intermediate
comment|// value obtained in some computation (such as instruction evaluation).
comment|// Such cases are identical to the usual Ref type, but the register
comment|// number is 0. In such case the Pos field of the reference is ignored.
comment|//
comment|// What is worthy of notice is that in value V (that is a "ref"), as long
comment|// as the RefI.Reg is not 0, it may actually be the same register as the
comment|// one in which V will be contained.  If the RefI.Pos refers to the posi-
comment|// tion of V, then V is assumed to be "bottom" (as a "ref to itself"),
comment|// otherwise V is taken to be identical to the referenced bit of the
comment|// same register.
comment|// If RefI.Reg is 0, however, such a reference to the same register is
comment|// not possible.  Any value V that is a "ref", and whose RefI.Reg is 0
comment|// is treated as "bottom".
block|}
block|;
name|ValueType
name|Type
block|;
name|BitRef
name|RefI
block|;
name|BitValue
argument_list|(
argument|ValueType T = Top
argument_list|)
operator|:
name|Type
argument_list|(
argument|T
argument_list|)
block|{}
name|BitValue
argument_list|(
argument|bool B
argument_list|)
operator|:
name|Type
argument_list|(
argument|B ? One : Zero
argument_list|)
block|{}
name|BitValue
argument_list|(
argument|unsigned Reg
argument_list|,
argument|uint16_t Pos
argument_list|)
operator|:
name|Type
argument_list|(
name|Ref
argument_list|)
block|,
name|RefI
argument_list|(
argument|Reg
argument_list|,
argument|Pos
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|BitValue
operator|&
name|V
operator|)
specifier|const
block|{
if|if
condition|(
name|Type
operator|!=
name|V
operator|.
name|Type
condition|)
return|return
name|false
return|;
if|if
condition|(
name|Type
operator|==
name|Ref
operator|&&
operator|!
operator|(
name|RefI
operator|==
name|V
operator|.
name|RefI
operator|)
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|BitValue
operator|&
name|V
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|V
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|is
argument_list|(
name|unsigned
name|T
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|T
operator|==
literal|0
operator|||
name|T
operator|==
literal|1
argument_list|)
expr_stmt|;
return|return
name|T
operator|==
literal|0
condition|?
name|Type
operator|==
name|Zero
else|:
operator|(
name|T
operator|==
literal|1
condition|?
name|Type
operator|==
name|One
else|:
name|false
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// The "meet" operation is the "." operation in a semilattice (L, ., T, B):
end_comment

begin_comment
comment|// (1)  x.x = x
end_comment

begin_comment
comment|// (2)  x.y = y.x
end_comment

begin_comment
comment|// (3)  x.(y.z) = (x.y).z
end_comment

begin_comment
comment|// (4)  x.T = x  (i.e. T = "top")
end_comment

begin_comment
comment|// (5)  x.B = B  (i.e. B = "bottom")
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This "meet" function will update the value of the "*this" object with
end_comment

begin_comment
comment|// the newly calculated one, and return "true" if the value of *this has
end_comment

begin_comment
comment|// changed, and "false" otherwise.
end_comment

begin_comment
comment|// To prove that it satisfies the conditions (1)-(5), it is sufficient
end_comment

begin_comment
comment|// to show that a relation
end_comment

begin_comment
comment|//   x<= y<=>  x.y = x
end_comment

begin_comment
comment|// defines a partial order (i.e. that "meet" is same as "infimum").
end_comment

begin_function
name|bool
name|meet
parameter_list|(
specifier|const
name|BitValue
modifier|&
name|V
parameter_list|,
specifier|const
name|BitRef
modifier|&
name|Self
parameter_list|)
block|{
comment|// First, check the cases where there is nothing to be done.
if|if
condition|(
name|Type
operator|==
name|Ref
operator|&&
name|RefI
operator|==
name|Self
condition|)
comment|// Bottom.meet(V) = Bottom (i.e. This)
return|return
name|false
return|;
if|if
condition|(
name|V
operator|.
name|Type
operator|==
name|Top
condition|)
comment|// This.meet(Top) = This
return|return
name|false
return|;
if|if
condition|(
operator|*
name|this
operator|==
name|V
condition|)
comment|// This.meet(This) = This
return|return
name|false
return|;
comment|// At this point, we know that the value of "this" will change.
comment|// If it is Top, it will become the same as V, otherwise it will
comment|// become "bottom" (i.e. Self).
if|if
condition|(
name|Type
operator|==
name|Top
condition|)
block|{
name|Type
operator|=
name|V
operator|.
name|Type
expr_stmt|;
name|RefI
operator|=
name|V
operator|.
name|RefI
expr_stmt|;
comment|// This may be irrelevant, but copy anyway.
return|return
name|true
return|;
block|}
comment|// Become "bottom".
name|Type
operator|=
name|Ref
expr_stmt|;
name|RefI
operator|=
name|Self
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|// Create a reference to the bit value V.
end_comment

begin_function_decl
specifier|static
name|BitValue
name|ref
parameter_list|(
specifier|const
name|BitValue
modifier|&
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Create a "self".
end_comment

begin_function_decl
specifier|static
name|BitValue
name|self
parameter_list|(
specifier|const
name|BitRef
modifier|&
name|Self
init|=
name|BitRef
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|bool
name|num
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|==
name|Zero
operator|||
name|Type
operator|==
name|One
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|bool
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Type
operator|==
name|Zero
operator|||
name|Type
operator|==
name|One
argument_list|)
block|;
return|return
name|Type
operator|==
name|One
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
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
name|BitValue
operator|&
name|BV
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// This operation must be idempotent, i.e. ref(ref(V)) == ref(V).
end_comment

begin_expr_stmt
specifier|inline
name|BitTracker
operator|::
name|BitValue
name|BitTracker
operator|::
name|BitValue
operator|::
name|ref
argument_list|(
argument|const BitValue&V
argument_list|)
block|{
if|if
condition|(
name|V
operator|.
name|Type
operator|!=
name|Ref
condition|)
return|return
name|BitValue
argument_list|(
name|V
operator|.
name|Type
argument_list|)
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|V
operator|.
name|RefI
operator|.
name|Reg
operator|!=
literal|0
condition|)
return|return
name|BitValue
argument_list|(
name|V
operator|.
name|RefI
operator|.
name|Reg
argument_list|,
name|V
operator|.
name|RefI
operator|.
name|Pos
argument_list|)
return|;
end_if

begin_return
return|return
name|self
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}  inline
name|BitTracker
operator|::
name|BitValue
name|BitTracker
operator|::
name|BitValue
operator|::
name|self
argument_list|(
argument|const BitRef&Self
argument_list|)
block|{
return|return
name|BitValue
argument_list|(
name|Self
operator|.
name|Reg
argument_list|,
name|Self
operator|.
name|Pos
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// A sequence of bits starting from index B up to and including index E.
end_comment

begin_comment
comment|// If E< B, the mask represents two sections: [0..E] and [B..W) where
end_comment

begin_comment
comment|// W is the width of the register.
end_comment

begin_expr_stmt
unit|struct
name|BitTracker
operator|::
name|BitMask
block|{
name|BitMask
argument_list|()
operator|=
expr|default
block|;
name|BitMask
argument_list|(
argument|uint16_t b
argument_list|,
argument|uint16_t e
argument_list|)
operator|:
name|B
argument_list|(
name|b
argument_list|)
block|,
name|E
argument_list|(
argument|e
argument_list|)
block|{}
name|uint16_t
name|first
argument_list|()
specifier|const
block|{
return|return
name|B
return|;
block|}
name|uint16_t
name|last
argument_list|()
specifier|const
block|{
return|return
name|E
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|uint16_t
name|B
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint16_t
name|E
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Representation of a register: a list of BitValues.
end_comment

begin_expr_stmt
unit|struct
name|BitTracker
operator|::
name|RegisterCell
block|{
name|RegisterCell
argument_list|(
argument|uint16_t Width = DefaultBitN
argument_list|)
operator|:
name|Bits
argument_list|(
argument|Width
argument_list|)
block|{}
name|uint16_t
name|width
argument_list|()
specifier|const
block|{
return|return
name|Bits
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|BitValue
operator|&
name|operator
index|[]
operator|(
name|uint16_t
name|BitN
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|BitN
operator|<
name|Bits
operator|.
name|size
argument_list|()
argument_list|)
block|;
return|return
name|Bits
index|[
name|BitN
index|]
return|;
block|}
end_expr_stmt

begin_function
name|BitValue
modifier|&
name|operator
function|[]
parameter_list|(
name|uint16_t
name|BitN
parameter_list|)
block|{
name|assert
argument_list|(
name|BitN
operator|<
name|Bits
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|Bits
index|[
name|BitN
index|]
return|;
block|}
end_function

begin_function_decl
name|bool
name|meet
parameter_list|(
specifier|const
name|RegisterCell
modifier|&
name|RC
parameter_list|,
name|unsigned
name|SelfR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RegisterCell
modifier|&
name|insert
parameter_list|(
specifier|const
name|RegisterCell
modifier|&
name|RC
parameter_list|,
specifier|const
name|BitMask
modifier|&
name|M
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|RegisterCell
name|extract
argument_list|(
specifier|const
name|BitMask
operator|&
name|M
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Returns a new cell.
end_comment

begin_function_decl
name|RegisterCell
modifier|&
name|rol
parameter_list|(
name|uint16_t
name|Sh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Rotate left.
end_comment

begin_function_decl
name|RegisterCell
modifier|&
name|fill
parameter_list|(
name|uint16_t
name|B
parameter_list|,
name|uint16_t
name|E
parameter_list|,
specifier|const
name|BitValue
modifier|&
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RegisterCell
modifier|&
name|cat
parameter_list|(
specifier|const
name|RegisterCell
modifier|&
name|RC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Concatenate.
end_comment

begin_decl_stmt
name|uint16_t
name|cl
argument_list|(
name|bool
name|B
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint16_t
name|ct
argument_list|(
name|bool
name|B
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|RegisterCell
operator|&
name|RC
operator|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|RegisterCell
operator|&
name|RC
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|RC
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Replace the ref-to-reg-0 bit values with the given register.
end_comment

begin_function_decl
name|RegisterCell
modifier|&
name|regify
parameter_list|(
name|unsigned
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Generate a "ref" cell for the corresponding register. In the resulting
end_comment

begin_comment
comment|// cell each bit will be described as being the same as the corresponding
end_comment

begin_comment
comment|// bit in register Reg (i.e. the cell is "defined" by register Reg).
end_comment

begin_function_decl
specifier|static
name|RegisterCell
name|self
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|uint16_t
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Generate a "top" cell of given size.
end_comment

begin_function_decl
specifier|static
name|RegisterCell
name|top
parameter_list|(
name|uint16_t
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Generate a cell that is a "ref" to another cell.
end_comment

begin_function_decl
specifier|static
name|RegisterCell
name|ref
parameter_list|(
specifier|const
name|RegisterCell
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_comment
comment|// The DefaultBitN is here only to avoid frequent reallocation of the
end_comment

begin_comment
comment|// memory in the vector.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|DefaultBitN
init|=
literal|32
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|SmallVector
operator|<
name|BitValue
operator|,
name|DefaultBitN
operator|>
name|BitValueList
expr_stmt|;
end_typedef

begin_decl_stmt
name|BitValueList
name|Bits
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|friend
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
name|RegisterCell
operator|&
name|RC
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
specifier|inline
name|bool
name|BitTracker
operator|::
name|has
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|{
return|return
name|Map
operator|.
name|find
argument_list|(
name|Reg
argument_list|)
operator|!=
name|Map
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|BitTracker
operator|::
name|RegisterCell
operator|&
name|BitTracker
operator|::
name|lookup
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|{
name|CellMapType
operator|::
name|const_iterator
name|F
operator|=
name|Map
operator|.
name|find
argument_list|(
name|Reg
argument_list|)
block|;
name|assert
argument_list|(
name|F
operator|!=
name|Map
operator|.
name|end
argument_list|()
argument_list|)
block|;
return|return
name|F
operator|->
name|second
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|BitTracker
operator|::
name|RegisterCell
name|BitTracker
operator|::
name|RegisterCell
operator|::
name|self
argument_list|(
argument|unsigned Reg
argument_list|,
argument|uint16_t Width
argument_list|)
block|{
name|RegisterCell
name|RC
argument_list|(
name|Width
argument_list|)
block|;
for|for
control|(
name|uint16_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|Width
condition|;
operator|++
name|i
control|)
name|RC
operator|.
name|Bits
index|[
name|i
index|]
operator|=
name|BitValue
operator|::
name|self
argument_list|(
name|BitRef
argument_list|(
name|Reg
argument_list|,
name|i
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|RC
return|;
end_return

begin_expr_stmt
unit|}  inline
name|BitTracker
operator|::
name|RegisterCell
name|BitTracker
operator|::
name|RegisterCell
operator|::
name|top
argument_list|(
argument|uint16_t Width
argument_list|)
block|{
name|RegisterCell
name|RC
argument_list|(
name|Width
argument_list|)
block|;
for|for
control|(
name|uint16_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|Width
condition|;
operator|++
name|i
control|)
name|RC
operator|.
name|Bits
index|[
name|i
index|]
operator|=
name|BitValue
argument_list|(
name|BitValue
operator|::
name|Top
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|RC
return|;
end_return

begin_expr_stmt
unit|}  inline
name|BitTracker
operator|::
name|RegisterCell
name|BitTracker
operator|::
name|RegisterCell
operator|::
name|ref
argument_list|(
argument|const RegisterCell&C
argument_list|)
block|{
name|uint16_t
name|W
operator|=
name|C
operator|.
name|width
argument_list|()
block|;
name|RegisterCell
name|RC
argument_list|(
name|W
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|W
condition|;
operator|++
name|i
control|)
name|RC
index|[
name|i
index|]
operator|=
name|BitValue
operator|::
name|ref
argument_list|(
name|C
index|[
name|i
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|RC
return|;
end_return

begin_comment
unit|}
comment|// A class to evaluate target's instructions and update the cell maps.
end_comment

begin_comment
comment|// This is used internally by the bit tracker.  A target that wants to
end_comment

begin_comment
comment|// utilize this should implement the evaluation functions (noted below)
end_comment

begin_comment
comment|// in a subclass of this class.
end_comment

begin_expr_stmt
unit|struct
name|BitTracker
operator|::
name|MachineEvaluator
block|{
name|MachineEvaluator
argument_list|(
specifier|const
name|TargetRegisterInfo
operator|&
name|T
argument_list|,
name|MachineRegisterInfo
operator|&
name|M
argument_list|)
operator|:
name|TRI
argument_list|(
name|T
argument_list|)
block|,
name|MRI
argument_list|(
argument|M
argument_list|)
block|{}
name|virtual
operator|~
name|MachineEvaluator
argument_list|()
operator|=
expr|default
block|;
name|uint16_t
name|getRegBitWidth
argument_list|(
argument|const RegisterRef&RR
argument_list|)
specifier|const
block|;
name|RegisterCell
name|getCell
argument_list|(
argument|const RegisterRef&RR
argument_list|,
argument|const CellMapType&M
argument_list|)
specifier|const
block|;
name|void
name|putCell
argument_list|(
argument|const RegisterRef&RR
argument_list|,
argument|RegisterCell RC
argument_list|,
argument|CellMapType&M
argument_list|)
specifier|const
block|;
comment|// A result of any operation should use refs to the source cells, not
comment|// the cells directly. This function is a convenience wrapper to quickly
comment|// generate a ref for a cell corresponding to a register reference.
name|RegisterCell
name|getRef
argument_list|(
argument|const RegisterRef&RR
argument_list|,
argument|const CellMapType&M
argument_list|)
specifier|const
block|{
name|RegisterCell
name|RC
operator|=
name|getCell
argument_list|(
name|RR
argument_list|,
name|M
argument_list|)
block|;
return|return
name|RegisterCell
operator|::
name|ref
argument_list|(
name|RC
argument_list|)
return|;
block|}
comment|// Helper functions.
comment|// Check if a cell is an immediate value (i.e. all bits are either 0 or 1).
name|bool
name|isInt
argument_list|(
argument|const RegisterCell&A
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Convert cell to an immediate value.
end_comment

begin_decl_stmt
name|uint64_t
name|toInt
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Generate cell from an immediate value.
end_comment

begin_decl_stmt
name|RegisterCell
name|eIMM
argument_list|(
name|int64_t
name|V
argument_list|,
name|uint16_t
name|W
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eIMM
argument_list|(
specifier|const
name|ConstantInt
operator|*
name|CI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Arithmetic.
end_comment

begin_decl_stmt
name|RegisterCell
name|eADD
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
specifier|const
name|RegisterCell
operator|&
name|A2
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eSUB
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
specifier|const
name|RegisterCell
operator|&
name|A2
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eMLS
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
specifier|const
name|RegisterCell
operator|&
name|A2
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eMLU
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
specifier|const
name|RegisterCell
operator|&
name|A2
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Shifts.
end_comment

begin_decl_stmt
name|RegisterCell
name|eASL
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
name|uint16_t
name|Sh
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eLSR
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
name|uint16_t
name|Sh
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eASR
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
name|uint16_t
name|Sh
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Logical.
end_comment

begin_decl_stmt
name|RegisterCell
name|eAND
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
specifier|const
name|RegisterCell
operator|&
name|A2
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eORL
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
specifier|const
name|RegisterCell
operator|&
name|A2
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eXOR
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
specifier|const
name|RegisterCell
operator|&
name|A2
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eNOT
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Set bit, clear bit.
end_comment

begin_decl_stmt
name|RegisterCell
name|eSET
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
name|uint16_t
name|BitN
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eCLR
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
name|uint16_t
name|BitN
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Count leading/trailing bits (zeros/ones).
end_comment

begin_decl_stmt
name|RegisterCell
name|eCLB
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
name|bool
name|B
argument_list|,
name|uint16_t
name|W
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eCTB
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
name|bool
name|B
argument_list|,
name|uint16_t
name|W
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Sign/zero extension.
end_comment

begin_decl_stmt
name|RegisterCell
name|eSXT
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
name|uint16_t
name|FromN
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eZXT
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
name|uint16_t
name|FromN
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Extract/insert
end_comment

begin_comment
comment|// XTR R,b,e:  extract bits from A1 starting at bit b, ending at e-1.
end_comment

begin_comment
comment|// INS R,S,b:  take R and replace bits starting from b with S.
end_comment

begin_decl_stmt
name|RegisterCell
name|eXTR
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
name|uint16_t
name|B
argument_list|,
name|uint16_t
name|E
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RegisterCell
name|eINS
argument_list|(
specifier|const
name|RegisterCell
operator|&
name|A1
argument_list|,
specifier|const
name|RegisterCell
operator|&
name|A2
argument_list|,
name|uint16_t
name|AtN
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// User-provided functions for individual targets:
end_comment

begin_comment
comment|// Return a sub-register mask that indicates which bits in Reg belong
end_comment

begin_comment
comment|// to the subregister Sub. These bits are assumed to be contiguous in
end_comment

begin_comment
comment|// the super-register, and have the same ordering in the sub-register
end_comment

begin_comment
comment|// as in the super-register. It is valid to call this function with
end_comment

begin_comment
comment|// Sub == 0, in this case, the function should return a mask that spans
end_comment

begin_comment
comment|// the entire register Reg (which is what the default implementation
end_comment

begin_comment
comment|// does).
end_comment

begin_decl_stmt
name|virtual
name|BitMask
name|mask
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|unsigned
name|Sub
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Indicate whether a given register class should be tracked.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|track
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
end_decl_stmt

begin_comment
comment|// Evaluate a non-branching machine instruction, given the cell map with
end_comment

begin_comment
comment|// the input values. Place the results in the Outputs map. Return "true"
end_comment

begin_comment
comment|// if evaluation succeeded, "false" otherwise.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|evaluate
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|,
specifier|const
name|CellMapType
operator|&
name|Inputs
argument_list|,
name|CellMapType
operator|&
name|Outputs
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Evaluate a branch, given the cell map with the input values. Fill out
end_comment

begin_comment
comment|// a list of all possible branch targets and indicate (through a flag)
end_comment

begin_comment
comment|// whether the branch could fall-through. Return "true" if this information
end_comment

begin_comment
comment|// has been successfully computed, "false" otherwise.
end_comment

begin_decl_stmt
name|virtual
name|bool
name|evaluate
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|BI
argument_list|,
specifier|const
name|CellMapType
operator|&
name|Inputs
argument_list|,
name|BranchTargetList
operator|&
name|Targets
argument_list|,
name|bool
operator|&
name|FallsThru
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MachineRegisterInfo
modifier|&
name|MRI
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_HEXAGON_BITTRACKER_H
end_comment

end_unit

