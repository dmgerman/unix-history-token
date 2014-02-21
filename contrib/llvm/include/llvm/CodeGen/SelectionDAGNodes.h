begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/SelectionDAGNodes.h - SelectionDAG Nodes ---*- C++ -*-===//
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
comment|// This file declares the SDNode class and derived classes, which are used to
end_comment

begin_comment
comment|// represent the nodes and operations present in a SelectionDAG.  These nodes
end_comment

begin_comment
comment|// and operations are machine code level operations, with some similarities to
end_comment

begin_comment
comment|// the GCC RTL representation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Clients should include the SelectionDAG.h file instead of this file directly.
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
name|LLVM_CODEGEN_SELECTIONDAGNODES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SELECTIONDAGNODES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
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
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ISDOpcodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineMemOperand.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Constants.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
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
name|class
name|SelectionDAG
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineConstantPoolValue
decl_stmt|;
name|class
name|SDNode
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|DenseMapInfo
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|simplify_type
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|ilist_traits
expr_stmt|;
name|void
name|checkForCycles
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// SDVTList - This represents a list of ValueType's that has been intern'd by
comment|/// a SelectionDAG.  Instances of this simple value class are returned by
comment|/// SelectionDAG::getVTList(...).
comment|///
struct|struct
name|SDVTList
block|{
specifier|const
name|EVT
modifier|*
name|VTs
decl_stmt|;
name|unsigned
name|int
name|NumVTs
decl_stmt|;
block|}
struct|;
name|namespace
name|ISD
block|{
comment|/// Node predicates
comment|/// isBuildVectorAllOnes - Return true if the specified node is a
comment|/// BUILD_VECTOR where all of the elements are ~0 or undef.
name|bool
name|isBuildVectorAllOnes
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isBuildVectorAllZeros - Return true if the specified node is a
comment|/// BUILD_VECTOR where all of the elements are 0 or undef.
name|bool
name|isBuildVectorAllZeros
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isScalarToVector - Return true if the specified node is a
comment|/// ISD::SCALAR_TO_VECTOR node or a BUILD_VECTOR node where only the low
comment|/// element is not an undef.
name|bool
name|isScalarToVector
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// allOperandsUndef - Return true if the node has at least one operand
comment|/// and all operands of the specified node are ISD::UNDEF.
name|bool
name|allOperandsUndef
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
block|}
comment|// end llvm:ISD namespace
comment|//===----------------------------------------------------------------------===//
comment|/// SDValue - Unlike LLVM values, Selection DAG nodes may return multiple
comment|/// values as the result of a computation.  Many nodes return multiple values,
comment|/// from loads (which define a token and a return value) to ADDC (which returns
comment|/// a result and a carry value), to calls (which may return an arbitrary number
comment|/// of values).
comment|///
comment|/// As such, each use of a SelectionDAG computation must indicate the node that
comment|/// computes it as well as which return value to use from that node.  This pair
comment|/// of information is represented with the SDValue value type.
comment|///
name|class
name|SDValue
block|{
name|SDNode
modifier|*
name|Node
decl_stmt|;
comment|// The node defining the value we are using.
name|unsigned
name|ResNo
decl_stmt|;
comment|// Which return value of the node we are using.
name|public
label|:
name|SDValue
argument_list|()
operator|:
name|Node
argument_list|(
literal|0
argument_list|)
operator|,
name|ResNo
argument_list|(
literal|0
argument_list|)
block|{}
name|SDValue
argument_list|(
argument|SDNode *node
argument_list|,
argument|unsigned resno
argument_list|)
operator|:
name|Node
argument_list|(
name|node
argument_list|)
operator|,
name|ResNo
argument_list|(
argument|resno
argument_list|)
block|{}
comment|/// get the index which selects a specific result in the SDNode
name|unsigned
name|getResNo
argument_list|()
specifier|const
block|{
return|return
name|ResNo
return|;
block|}
comment|/// get the SDNode which holds the desired result
name|SDNode
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|Node
return|;
block|}
comment|/// set the SDNode
name|void
name|setNode
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
block|{
name|Node
operator|=
name|N
expr_stmt|;
block|}
specifier|inline
name|SDNode
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Node
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SDValue
operator|&
name|O
operator|)
specifier|const
block|{
return|return
name|Node
operator|==
name|O
operator|.
name|Node
operator|&&
name|ResNo
operator|==
name|O
operator|.
name|ResNo
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SDValue
operator|&
name|O
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|O
operator|)
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|SDValue
operator|&
name|O
operator|)
specifier|const
block|{
return|return
name|Node
operator|<
name|O
operator|.
name|Node
operator|||
operator|(
name|Node
operator|==
name|O
operator|.
name|Node
operator|&&
name|ResNo
operator|<
name|O
operator|.
name|ResNo
operator|)
return|;
block|}
name|SDValue
name|getValue
argument_list|(
name|unsigned
name|R
argument_list|)
decl|const
block|{
return|return
name|SDValue
argument_list|(
name|Node
argument_list|,
name|R
argument_list|)
return|;
block|}
comment|// isOperandOf - Return true if this node is an operand of N.
name|bool
name|isOperandOf
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
decl|const
decl_stmt|;
comment|/// getValueType - Return the ValueType of the referenced return value.
comment|///
specifier|inline
name|EVT
name|getValueType
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return the simple ValueType of the referenced return value.
name|MVT
name|getSimpleValueType
argument_list|()
specifier|const
block|{
return|return
name|getValueType
argument_list|()
operator|.
name|getSimpleVT
argument_list|()
return|;
block|}
comment|/// getValueSizeInBits - Returns the size of the value in bits.
comment|///
name|unsigned
name|getValueSizeInBits
argument_list|()
specifier|const
block|{
return|return
name|getValueType
argument_list|()
operator|.
name|getSizeInBits
argument_list|()
return|;
block|}
comment|// Forwarding methods - These forward to the corresponding methods in SDNode.
specifier|inline
name|unsigned
name|getOpcode
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
specifier|const
name|SDValue
modifier|&
name|getOperand
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|uint64_t
name|getConstantOperandVal
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|bool
name|isTargetMemoryOpcode
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isTargetOpcode
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isMachineOpcode
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|unsigned
name|getMachineOpcode
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
specifier|const
name|DebugLoc
name|getDebugLoc
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|void
name|dumpr
argument_list|()
specifier|const
expr_stmt|;
comment|/// reachesChainWithoutSideEffects - Return true if this operand (which must
comment|/// be a chain) reaches the specified operand without crossing any
comment|/// side-effecting instructions.  In practice, this looks through token
comment|/// factors and non-volatile loads.  In order to remain efficient, this only
comment|/// looks a couple of nodes in, it does not do an exhaustive search.
name|bool
name|reachesChainWithoutSideEffects
argument_list|(
name|SDValue
name|Dest
argument_list|,
name|unsigned
name|Depth
operator|=
literal|2
argument_list|)
decl|const
decl_stmt|;
comment|/// use_empty - Return true if there are no nodes using value ResNo
comment|/// of Node.
comment|///
specifier|inline
name|bool
name|use_empty
argument_list|()
specifier|const
expr_stmt|;
comment|/// hasOneUse - Return true if there is exactly one node using value
comment|/// ResNo of Node.
comment|///
specifier|inline
name|bool
name|hasOneUse
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|SDValue
operator|>
block|{
specifier|static
specifier|inline
name|SDValue
name|getEmptyKey
argument_list|()
block|{
return|return
name|SDValue
argument_list|(
operator|(
name|SDNode
operator|*
operator|)
operator|-
literal|1
argument_list|,
operator|-
literal|1U
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|SDValue
name|getTombstoneKey
argument_list|()
block|{
return|return
name|SDValue
argument_list|(
operator|(
name|SDNode
operator|*
operator|)
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|SDValue
modifier|&
name|Val
parameter_list|)
block|{
return|return
operator|(
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|uintptr_t
operator|)
name|Val
operator|.
name|getNode
argument_list|()
operator|>>
literal|4
argument_list|)
operator|^
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|uintptr_t
operator|)
name|Val
operator|.
name|getNode
argument_list|()
operator|>>
literal|9
argument_list|)
operator|)
operator|+
name|Val
operator|.
name|getResNo
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isEqual
parameter_list|(
specifier|const
name|SDValue
modifier|&
name|LHS
parameter_list|,
specifier|const
name|SDValue
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|SDValue
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// simplify_type specializations - Allow casting operators to work directly on
end_comment

begin_comment
comment|/// SDValues as if they were SDNode*'s.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|SDValue
operator|>
block|{
typedef|typedef
name|SDNode
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|SDValue&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getNode
argument_list|()
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
name|SDValue
operator|>
block|{
typedef|typedef
comment|/*const*/
name|SDNode
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const SDValue&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getNode
argument_list|()
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// SDUse - Represents a use of a SDNode. This class holds an SDValue,
end_comment

begin_comment
comment|/// which records the SDNode being used and the result number, a
end_comment

begin_comment
comment|/// pointer to the SDNode using the value, and Next and Prev pointers,
end_comment

begin_comment
comment|/// which link together all the uses of an SDNode.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|SDUse
block|{
comment|/// Val - The value being used.
name|SDValue
name|Val
decl_stmt|;
comment|/// User - The user of this value.
name|SDNode
modifier|*
name|User
decl_stmt|;
comment|/// Prev, Next - Pointers to the uses list of the SDNode referred by
comment|/// this operand.
name|SDUse
modifier|*
modifier|*
name|Prev
decl_stmt|,
modifier|*
name|Next
decl_stmt|;
name|SDUse
argument_list|(
argument|const SDUse&U
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|SDUse
operator|&
name|U
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
name|SDUse
argument_list|()
operator|:
name|Val
argument_list|()
operator|,
name|User
argument_list|(
name|NULL
argument_list|)
operator|,
name|Prev
argument_list|(
name|NULL
argument_list|)
operator|,
name|Next
argument_list|(
argument|NULL
argument_list|)
block|{}
comment|/// Normally SDUse will just implicitly convert to an SDValue that it holds.
name|operator
specifier|const
name|SDValue
operator|&
operator|(
operator|)
specifier|const
block|{
return|return
name|Val
return|;
block|}
comment|/// If implicit conversion to SDValue doesn't work, the get() method returns
comment|/// the SDValue.
specifier|const
name|SDValue
operator|&
name|get
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
comment|/// getUser - This returns the SDNode that contains this Use.
name|SDNode
modifier|*
name|getUser
parameter_list|()
block|{
return|return
name|User
return|;
block|}
comment|/// getNext - Get the next SDUse in the use list.
name|SDUse
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Next
return|;
block|}
comment|/// getNode - Convenience function for get().getNode().
name|SDNode
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getNode
argument_list|()
return|;
block|}
comment|/// getResNo - Convenience function for get().getResNo().
name|unsigned
name|getResNo
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getResNo
argument_list|()
return|;
block|}
comment|/// getValueType - Convenience function for get().getValueType().
name|EVT
name|getValueType
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getValueType
argument_list|()
return|;
block|}
comment|/// operator== - Convenience function for get().operator==
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SDValue
operator|&
name|V
operator|)
specifier|const
block|{
return|return
name|Val
operator|==
name|V
return|;
block|}
comment|/// operator!= - Convenience function for get().operator!=
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SDValue
operator|&
name|V
operator|)
specifier|const
block|{
return|return
name|Val
operator|!=
name|V
return|;
block|}
comment|/// operator< - Convenience function for get().operator<
name|bool
name|operator
operator|<
operator|(
specifier|const
name|SDValue
operator|&
name|V
operator|)
specifier|const
block|{
return|return
name|Val
operator|<
name|V
return|;
block|}
name|private
label|:
name|friend
name|class
name|SelectionDAG
decl_stmt|;
name|friend
name|class
name|SDNode
decl_stmt|;
name|void
name|setUser
parameter_list|(
name|SDNode
modifier|*
name|p
parameter_list|)
block|{
name|User
operator|=
name|p
expr_stmt|;
block|}
comment|/// set - Remove this use from its existing use list, assign it the
comment|/// given value, and add it to the new value's node's use list.
specifier|inline
name|void
name|set
parameter_list|(
specifier|const
name|SDValue
modifier|&
name|V
parameter_list|)
function_decl|;
comment|/// setInitial - like set, but only supports initializing a newly-allocated
comment|/// SDUse with a non-null value.
specifier|inline
name|void
name|setInitial
parameter_list|(
specifier|const
name|SDValue
modifier|&
name|V
parameter_list|)
function_decl|;
comment|/// setNode - like set, but only sets the Node portion of the value,
comment|/// leaving the ResNo portion unmodified.
specifier|inline
name|void
name|setNode
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
name|void
name|addToList
parameter_list|(
name|SDUse
modifier|*
modifier|*
name|List
parameter_list|)
block|{
name|Next
operator|=
operator|*
name|List
expr_stmt|;
if|if
condition|(
name|Next
condition|)
name|Next
operator|->
name|Prev
operator|=
operator|&
name|Next
expr_stmt|;
name|Prev
operator|=
name|List
expr_stmt|;
operator|*
name|List
operator|=
name|this
expr_stmt|;
block|}
name|void
name|removeFromList
parameter_list|()
block|{
operator|*
name|Prev
operator|=
name|Next
expr_stmt|;
if|if
condition|(
name|Next
condition|)
name|Next
operator|->
name|Prev
operator|=
name|Prev
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// simplify_type specializations - Allow casting operators to work directly on
end_comment

begin_comment
comment|/// SDValues as if they were SDNode*'s.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|SDUse
operator|>
block|{
typedef|typedef
name|SDNode
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|SDUse&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getNode
argument_list|()
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// SDNode - Represents one node in the SelectionDAG.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|SDNode
range|:
name|public
name|FoldingSetNode
decl_stmt|,
name|public
name|ilist_node
decl|<
name|SDNode
decl|>
block|{
name|private
label|:
comment|/// NodeType - The operation that this node performs.
comment|///
name|int16_t
name|NodeType
decl_stmt|;
comment|/// OperandsNeedDelete - This is true if OperandList was new[]'d.  If true,
comment|/// then they will be delete[]'d when the node is destroyed.
name|uint16_t
name|OperandsNeedDelete
range|:
literal|1
decl_stmt|;
comment|/// HasDebugValue - This tracks whether this node has one or more dbg_value
comment|/// nodes corresponding to it.
name|uint16_t
name|HasDebugValue
range|:
literal|1
decl_stmt|;
name|protected
label|:
comment|/// SubclassData - This member is defined by this class, but is not used for
comment|/// anything.  Subclasses can use it to hold whatever state they find useful.
comment|/// This field is initialized to zero by the ctor.
name|uint16_t
name|SubclassData
range|:
literal|14
decl_stmt|;
name|private
label|:
comment|/// NodeId - Unique id per SDNode in the DAG.
name|int
name|NodeId
decl_stmt|;
comment|/// OperandList - The values that are used by this operation.
comment|///
name|SDUse
modifier|*
name|OperandList
decl_stmt|;
comment|/// ValueList - The types of the values this node defines.  SDNode's may
comment|/// define multiple values simultaneously.
specifier|const
name|EVT
modifier|*
name|ValueList
decl_stmt|;
comment|/// UseList - List of uses for this SDNode.
name|SDUse
modifier|*
name|UseList
decl_stmt|;
comment|/// NumOperands/NumValues - The number of entries in the Operand/Value list.
name|unsigned
name|short
name|NumOperands
decl_stmt|,
name|NumValues
decl_stmt|;
comment|/// debugLoc - source line information.
name|DebugLoc
name|debugLoc
decl_stmt|;
comment|// The ordering of the SDNodes. It roughly corresponds to the ordering of the
comment|// original LLVM instructions.
comment|// This is used for turning off scheduling, because we'll forgo
comment|// the normal scheduling algorithms and output the instructions according to
comment|// this ordering.
name|unsigned
name|IROrder
decl_stmt|;
comment|/// getValueTypeList - Return a pointer to the specified value type.
specifier|static
specifier|const
name|EVT
modifier|*
name|getValueTypeList
parameter_list|(
name|EVT
name|VT
parameter_list|)
function_decl|;
name|friend
name|class
name|SelectionDAG
decl_stmt|;
name|friend
block|struct
name|ilist_traits
operator|<
name|SDNode
operator|>
expr_stmt|;
name|public
label|:
comment|//===--------------------------------------------------------------------===//
comment|//  Accessors
comment|//
comment|/// getOpcode - Return the SelectionDAG opcode value for this node. For
comment|/// pre-isel nodes (those for which isMachineOpcode returns false), these
comment|/// are the opcode values in the ISD and<target>ISD namespaces. For
comment|/// post-isel opcodes, see getMachineOpcode.
name|unsigned
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
name|short
operator|)
name|NodeType
return|;
block|}
comment|/// isTargetOpcode - Test if this node has a target-specific opcode (in the
comment|/// \<target\>ISD namespace).
name|bool
name|isTargetOpcode
argument_list|()
specifier|const
block|{
return|return
name|NodeType
operator|>=
name|ISD
operator|::
name|BUILTIN_OP_END
return|;
block|}
comment|/// isTargetMemoryOpcode - Test if this node has a target-specific
comment|/// memory-referencing opcode (in the \<target\>ISD namespace and
comment|/// greater than FIRST_TARGET_MEMORY_OPCODE).
name|bool
name|isTargetMemoryOpcode
argument_list|()
specifier|const
block|{
return|return
name|NodeType
operator|>=
name|ISD
operator|::
name|FIRST_TARGET_MEMORY_OPCODE
return|;
block|}
comment|/// isMachineOpcode - Test if this node has a post-isel opcode, directly
comment|/// corresponding to a MachineInstr opcode.
name|bool
name|isMachineOpcode
argument_list|()
specifier|const
block|{
return|return
name|NodeType
operator|<
literal|0
return|;
block|}
comment|/// getMachineOpcode - This may only be called if isMachineOpcode returns
comment|/// true. It returns the MachineInstr opcode value that the node's opcode
comment|/// corresponds to.
name|unsigned
name|getMachineOpcode
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isMachineOpcode
argument_list|()
operator|&&
literal|"Not a MachineInstr opcode!"
argument_list|)
block|;
return|return
operator|~
name|NodeType
return|;
block|}
comment|/// getHasDebugValue - get this bit.
name|bool
name|getHasDebugValue
argument_list|()
specifier|const
block|{
return|return
name|HasDebugValue
return|;
block|}
comment|/// setHasDebugValue - set this bit.
name|void
name|setHasDebugValue
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|HasDebugValue
operator|=
name|b
expr_stmt|;
block|}
comment|/// use_empty - Return true if there are no uses of this node.
comment|///
name|bool
name|use_empty
argument_list|()
specifier|const
block|{
return|return
name|UseList
operator|==
name|NULL
return|;
block|}
comment|/// hasOneUse - Return true if there is exactly one use of this node.
comment|///
name|bool
name|hasOneUse
argument_list|()
specifier|const
block|{
return|return
operator|!
name|use_empty
argument_list|()
operator|&&
name|llvm
operator|::
name|next
argument_list|(
name|use_begin
argument_list|()
argument_list|)
operator|==
name|use_end
argument_list|()
return|;
block|}
comment|/// use_size - Return the number of uses of this node. This method takes
comment|/// time proportional to the number of uses.
comment|///
name|size_t
name|use_size
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|distance
argument_list|(
name|use_begin
argument_list|()
argument_list|,
name|use_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// getNodeId - Return the unique node id.
comment|///
name|int
name|getNodeId
argument_list|()
specifier|const
block|{
return|return
name|NodeId
return|;
block|}
comment|/// setNodeId - Set unique node id.
name|void
name|setNodeId
parameter_list|(
name|int
name|Id
parameter_list|)
block|{
name|NodeId
operator|=
name|Id
expr_stmt|;
block|}
comment|/// getIROrder - Return the node ordering.
comment|///
name|unsigned
name|getIROrder
argument_list|()
specifier|const
block|{
return|return
name|IROrder
return|;
block|}
comment|/// setIROrder - Set the node ordering.
comment|///
name|void
name|setIROrder
parameter_list|(
name|unsigned
name|Order
parameter_list|)
block|{
name|IROrder
operator|=
name|Order
expr_stmt|;
block|}
comment|/// getDebugLoc - Return the source location info.
specifier|const
name|DebugLoc
name|getDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|debugLoc
return|;
block|}
comment|/// setDebugLoc - Set source location info.  Try to avoid this, putting
comment|/// it in the constructor is preferable.
name|void
name|setDebugLoc
parameter_list|(
specifier|const
name|DebugLoc
name|dl
parameter_list|)
block|{
name|debugLoc
operator|=
name|dl
expr_stmt|;
block|}
comment|/// use_iterator - This class provides iterator support for SDUse
comment|/// operands that use a specific SDNode.
name|class
name|use_iterator
range|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
decl_stmt|,
name|SDUse
decl_stmt|,
name|ptrdiff_t
decl|>
block|{
name|SDUse
modifier|*
name|Op
decl_stmt|;
name|explicit
name|use_iterator
argument_list|(
name|SDUse
operator|*
name|op
argument_list|)
operator|:
name|Op
argument_list|(
argument|op
argument_list|)
block|{     }
name|friend
name|class
name|SDNode
expr_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|SDUse
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
name|SDUse
operator|,
name|ptrdiff_t
operator|>
operator|::
name|pointer
name|pointer
expr_stmt|;
name|use_iterator
argument_list|(
specifier|const
name|use_iterator
operator|&
name|I
argument_list|)
operator|:
name|Op
argument_list|(
argument|I.Op
argument_list|)
block|{}
name|use_iterator
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
name|use_iterator
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
name|use_iterator
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
comment|/// atEnd - return true if this iterator is at the end of uses list.
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
comment|// Iterator traversal: forward iteration only.
name|use_iterator
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
name|Op
operator|->
name|getNext
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|use_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|use_iterator
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
comment|/// Retrieve a pointer to the current user node.
name|SDNode
operator|*
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
name|Op
operator|->
name|getUser
argument_list|()
return|;
block|}
name|SDNode
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|operator
operator|*
operator|(
operator|)
return|;
block|}
name|SDUse
operator|&
name|getUse
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Op
return|;
block|}
comment|/// getOperandNo - Retrieve the operand # of this use in its user.
comment|///
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
call|(
name|unsigned
call|)
argument_list|(
name|Op
operator|-
name|Op
operator|->
name|getUser
argument_list|()
operator|->
name|OperandList
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// use_begin/use_end - Provide iteration support to walk over all uses
end_comment

begin_comment
comment|/// of an SDNode.
end_comment

begin_expr_stmt
name|use_iterator
name|use_begin
argument_list|()
specifier|const
block|{
return|return
name|use_iterator
argument_list|(
name|UseList
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_comment
comment|/// hasNUsesOfValue - Return true if there are exactly NUSES uses of the
end_comment

begin_comment
comment|/// indicated value.  This method ignores uses of other values defined by this
end_comment

begin_comment
comment|/// operation.
end_comment

begin_decl_stmt
name|bool
name|hasNUsesOfValue
argument_list|(
name|unsigned
name|NUses
argument_list|,
name|unsigned
name|Value
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// hasAnyUseOfValue - Return true if there are any use of the indicated
end_comment

begin_comment
comment|/// value. This method ignores uses of other values defined by this operation.
end_comment

begin_decl_stmt
name|bool
name|hasAnyUseOfValue
argument_list|(
name|unsigned
name|Value
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isOnlyUserOf - Return true if this node is the only use of N.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|bool
name|isOnlyUserOf
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isOperandOf - Return true if this node is an operand of N.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|bool
name|isOperandOf
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isPredecessorOf - Return true if this node is a predecessor of N.
end_comment

begin_comment
comment|/// NOTE: Implemented on top of hasPredecessor and every bit as
end_comment

begin_comment
comment|/// expensive. Use carefully.
end_comment

begin_decl_stmt
name|bool
name|isPredecessorOf
argument_list|(
specifier|const
name|SDNode
operator|*
name|N
argument_list|)
decl|const
block|{
return|return
name|N
operator|->
name|hasPredecessor
argument_list|(
name|this
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// hasPredecessor - Return true if N is a predecessor of this node.
end_comment

begin_comment
comment|/// N is either an operand of this node, or can be reached by recursively
end_comment

begin_comment
comment|/// traversing up the operands.
end_comment

begin_comment
comment|/// NOTE: This is an expensive method. Use it carefully.
end_comment

begin_decl_stmt
name|bool
name|hasPredecessor
argument_list|(
specifier|const
name|SDNode
operator|*
name|N
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// hasPredecesorHelper - Return true if N is a predecessor of this node.
end_comment

begin_comment
comment|/// N is either an operand of this node, or can be reached by recursively
end_comment

begin_comment
comment|/// traversing up the operands.
end_comment

begin_comment
comment|/// In this helper the Visited and worklist sets are held externally to
end_comment

begin_comment
comment|/// cache predecessors over multiple invocations. If you want to test for
end_comment

begin_comment
comment|/// multiple predecessors this method is preferable to multiple calls to
end_comment

begin_comment
comment|/// hasPredecessor. Be sure to clear Visited and Worklist if the DAG
end_comment

begin_comment
comment|/// changes.
end_comment

begin_comment
comment|/// NOTE: This is still very expensive. Use carefully.
end_comment

begin_decl_stmt
name|bool
name|hasPredecessorHelper
argument_list|(
specifier|const
name|SDNode
operator|*
name|N
argument_list|,
name|SmallPtrSet
operator|<
specifier|const
name|SDNode
operator|*
argument_list|,
literal|32
operator|>
operator|&
name|Visited
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|SDNode
operator|*
operator|>
operator|&
name|Worklist
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getNumOperands - Return the number of values used by this operation.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
block|{
return|return
name|NumOperands
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getConstantOperandVal - Helper method returns the integer value of a
end_comment

begin_comment
comment|/// ConstantSDNode operand.
end_comment

begin_decl_stmt
name|uint64_t
name|getConstantOperandVal
argument_list|(
name|unsigned
name|Num
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|SDValue
modifier|&
name|getOperand
argument_list|(
name|unsigned
name|Num
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Num
operator|<
name|NumOperands
operator|&&
literal|"Invalid child # of SDNode!"
argument_list|)
expr_stmt|;
return|return
name|OperandList
index|[
name|Num
index|]
return|;
block|}
end_decl_stmt

begin_typedef
typedef|typedef
name|SDUse
modifier|*
name|op_iterator
typedef|;
end_typedef

begin_expr_stmt
name|op_iterator
name|op_begin
argument_list|()
specifier|const
block|{
return|return
name|OperandList
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|op_iterator
name|op_end
argument_list|()
specifier|const
block|{
return|return
name|OperandList
operator|+
name|NumOperands
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SDVTList
name|getVTList
argument_list|()
specifier|const
block|{
name|SDVTList
name|X
operator|=
block|{
name|ValueList
block|,
name|NumValues
block|}
block|;
return|return
name|X
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getGluedNode - If this node has a glue operand, return the node
end_comment

begin_comment
comment|/// to which the glue operand points. Otherwise return NULL.
end_comment

begin_expr_stmt
name|SDNode
operator|*
name|getGluedNode
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getNumOperands
argument_list|()
operator|!=
literal|0
operator|&&
name|getOperand
argument_list|(
name|getNumOperands
argument_list|()
operator|-
literal|1
argument_list|)
operator|.
name|getValueType
argument_list|()
operator|==
name|MVT
operator|::
name|Glue
condition|)
return|return
name|getOperand
argument_list|(
name|getNumOperands
argument_list|()
operator|-
literal|1
argument_list|)
operator|.
name|getNode
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_comment
unit|}
comment|// If this is a pseudo op, like copyfromreg, look to see if there is a
end_comment

begin_comment
comment|// real target node glued to it.  If so, return the target node.
end_comment

begin_expr_stmt
unit|const
name|SDNode
operator|*
name|getGluedMachineNode
argument_list|()
specifier|const
block|{
specifier|const
name|SDNode
operator|*
name|FoundNode
operator|=
name|this
block|;
comment|// Climb up glue edges until a machine-opcode node is found, or the
comment|// end of the chain is reached.
while|while
condition|(
operator|!
name|FoundNode
operator|->
name|isMachineOpcode
argument_list|()
condition|)
block|{
specifier|const
name|SDNode
modifier|*
name|N
init|=
name|FoundNode
operator|->
name|getGluedNode
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|N
condition|)
break|break;
name|FoundNode
operator|=
name|N
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|FoundNode
return|;
end_return

begin_comment
unit|}
comment|/// getGluedUser - If this node has a glue value with a user, return
end_comment

begin_comment
comment|/// the user (there is at most one). Otherwise return NULL.
end_comment

begin_expr_stmt
unit|SDNode
operator|*
name|getGluedUser
argument_list|()
specifier|const
block|{
for|for
control|(
name|use_iterator
name|UI
init|=
name|use_begin
argument_list|()
init|,
name|UE
init|=
name|use_end
argument_list|()
init|;
name|UI
operator|!=
name|UE
condition|;
operator|++
name|UI
control|)
if|if
condition|(
name|UI
operator|.
name|getUse
argument_list|()
operator|.
name|get
argument_list|()
operator|.
name|getValueType
argument_list|()
operator|==
name|MVT
operator|::
name|Glue
condition|)
return|return
operator|*
name|UI
return|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_comment
unit|}
comment|/// getNumValues - Return the number of values defined/returned by this
end_comment

begin_comment
comment|/// operator.
end_comment

begin_comment
comment|///
end_comment

begin_macro
unit|unsigned
name|getNumValues
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|NumValues
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getValueType - Return the type of a specified result.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|EVT
name|getValueType
argument_list|(
name|unsigned
name|ResNo
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|ResNo
operator|<
name|NumValues
operator|&&
literal|"Illegal result number!"
argument_list|)
expr_stmt|;
return|return
name|ValueList
index|[
name|ResNo
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return the type of a specified result as a simple type.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|MVT
name|getSimpleValueType
argument_list|(
name|unsigned
name|ResNo
argument_list|)
decl|const
block|{
return|return
name|getValueType
argument_list|(
name|ResNo
argument_list|)
operator|.
name|getSimpleVT
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getValueSizeInBits - Returns MVT::getSizeInBits(getValueType(ResNo)).
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|unsigned
name|getValueSizeInBits
argument_list|(
name|unsigned
name|ResNo
argument_list|)
decl|const
block|{
return|return
name|getValueType
argument_list|(
name|ResNo
argument_list|)
operator|.
name|getSizeInBits
argument_list|()
return|;
block|}
end_decl_stmt

begin_typedef
typedef|typedef
specifier|const
name|EVT
modifier|*
name|value_iterator
typedef|;
end_typedef

begin_expr_stmt
name|value_iterator
name|value_begin
argument_list|()
specifier|const
block|{
return|return
name|ValueList
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|value_iterator
name|value_end
argument_list|()
specifier|const
block|{
return|return
name|ValueList
operator|+
name|NumValues
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getOperationName - Return the opcode of this operation for printing.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getOperationName
argument_list|(
argument|const SelectionDAG *G =
literal|0
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|getIndexedModeName
argument_list|(
name|ISD
operator|::
name|MemIndexedMode
name|AM
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_types
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|SelectionDAG
operator|*
name|G
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_details
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|SelectionDAG
operator|*
name|G
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|SelectionDAG
operator|*
name|G
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|printr
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|SelectionDAG
operator|*
name|G
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// printrFull - Print a SelectionDAG node and all children down to
end_comment

begin_comment
comment|/// the leaves.  The given SelectionDAG allows target-specific nodes
end_comment

begin_comment
comment|/// to be printed in human-readable form.  Unlike printr, this will
end_comment

begin_comment
comment|/// print the whole DAG, including children that appear multiple
end_comment

begin_comment
comment|/// times.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|printrFull
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
specifier|const
name|SelectionDAG
operator|*
name|G
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// printrWithDepth - Print a SelectionDAG node and children up to
end_comment

begin_comment
comment|/// depth "depth."  The given SelectionDAG allows target-specific
end_comment

begin_comment
comment|/// nodes to be printed in human-readable form.  Unlike printr, this
end_comment

begin_comment
comment|/// will print children that appear multiple times wherever they are
end_comment

begin_comment
comment|/// used.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|printrWithDepth
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
specifier|const
name|SelectionDAG
operator|*
name|G
operator|=
literal|0
argument_list|,
name|unsigned
name|depth
operator|=
literal|100
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// dump - Dump this node, for debugging.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// dumpr - Dump (recursively) this node and its use-def subgraph.
end_comment

begin_expr_stmt
name|void
name|dumpr
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// dump - Dump this node, for debugging.
end_comment

begin_comment
comment|/// The given SelectionDAG allows target-specific nodes to be printed
end_comment

begin_comment
comment|/// in human-readable form.
end_comment

begin_decl_stmt
name|void
name|dump
argument_list|(
specifier|const
name|SelectionDAG
operator|*
name|G
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// dumpr - Dump (recursively) this node and its use-def subgraph.
end_comment

begin_comment
comment|/// The given SelectionDAG allows target-specific nodes to be printed
end_comment

begin_comment
comment|/// in human-readable form.
end_comment

begin_decl_stmt
name|void
name|dumpr
argument_list|(
specifier|const
name|SelectionDAG
operator|*
name|G
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// dumprFull - printrFull to dbgs().  The given SelectionDAG allows
end_comment

begin_comment
comment|/// target-specific nodes to be printed in human-readable form.
end_comment

begin_comment
comment|/// Unlike dumpr, this will print the whole DAG, including children
end_comment

begin_comment
comment|/// that appear multiple times.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|dumprFull
argument_list|(
specifier|const
name|SelectionDAG
operator|*
name|G
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// dumprWithDepth - printrWithDepth to dbgs().  The given
end_comment

begin_comment
comment|/// SelectionDAG allows target-specific nodes to be printed in
end_comment

begin_comment
comment|/// human-readable form.  Unlike dumpr, this will print children
end_comment

begin_comment
comment|/// that appear multiple times wherever they are used.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|dumprWithDepth
argument_list|(
specifier|const
name|SelectionDAG
operator|*
name|G
operator|=
literal|0
argument_list|,
name|unsigned
name|depth
operator|=
literal|100
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Profile - Gather unique data for the node.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|Profile
argument_list|(
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addUse - This method should only be used by the SDUse class.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|void
name|addUse
parameter_list|(
name|SDUse
modifier|&
name|U
parameter_list|)
block|{
name|U
operator|.
name|addToList
argument_list|(
operator|&
name|UseList
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|protected
label|:
end_label

begin_function
specifier|static
name|SDVTList
name|getSDVTList
parameter_list|(
name|EVT
name|VT
parameter_list|)
block|{
name|SDVTList
name|Ret
init|=
block|{
name|getValueTypeList
argument_list|(
name|VT
argument_list|)
block|,
literal|1
block|}
decl_stmt|;
return|return
name|Ret
return|;
block|}
end_function

begin_macro
name|SDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|const DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|const SDValue *Ops
argument_list|,
argument|unsigned NumOps
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|NodeType
argument_list|(
name|Opc
argument_list|)
operator|,
name|OperandsNeedDelete
argument_list|(
name|true
argument_list|)
operator|,
name|HasDebugValue
argument_list|(
name|false
argument_list|)
operator|,
name|SubclassData
argument_list|(
literal|0
argument_list|)
operator|,
name|NodeId
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|OperandList
argument_list|(
argument|NumOps ? new SDUse[NumOps] :
literal|0
argument_list|)
operator|,
name|ValueList
argument_list|(
name|VTs
operator|.
name|VTs
argument_list|)
operator|,
name|UseList
argument_list|(
name|NULL
argument_list|)
operator|,
name|NumOperands
argument_list|(
name|NumOps
argument_list|)
operator|,
name|NumValues
argument_list|(
name|VTs
operator|.
name|NumVTs
argument_list|)
operator|,
name|debugLoc
argument_list|(
name|dl
argument_list|)
operator|,
name|IROrder
argument_list|(
argument|Order
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|NumOps
condition|;
operator|++
name|i
control|)
block|{
name|OperandList
index|[
name|i
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|OperandList
index|[
name|i
index|]
operator|.
name|setInitial
argument_list|(
name|Ops
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|checkForCycles
argument_list|(
name|this
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// This constructor adds no operands itself; operands can be
end_comment

begin_comment
comment|/// set later with InitOperands.
end_comment

begin_expr_stmt
unit|SDNode
operator|(
name|unsigned
name|Opc
operator|,
name|unsigned
name|Order
operator|,
specifier|const
name|DebugLoc
name|dl
operator|,
name|SDVTList
name|VTs
operator|)
operator|:
name|NodeType
argument_list|(
name|Opc
argument_list|)
operator|,
name|OperandsNeedDelete
argument_list|(
name|false
argument_list|)
operator|,
name|HasDebugValue
argument_list|(
name|false
argument_list|)
operator|,
name|SubclassData
argument_list|(
literal|0
argument_list|)
operator|,
name|NodeId
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|OperandList
argument_list|(
literal|0
argument_list|)
operator|,
name|ValueList
argument_list|(
name|VTs
operator|.
name|VTs
argument_list|)
operator|,
name|UseList
argument_list|(
name|NULL
argument_list|)
operator|,
name|NumOperands
argument_list|(
literal|0
argument_list|)
operator|,
name|NumValues
argument_list|(
name|VTs
operator|.
name|NumVTs
argument_list|)
operator|,
name|debugLoc
argument_list|(
name|dl
argument_list|)
operator|,
name|IROrder
argument_list|(
argument|Order
argument_list|)
block|{}
comment|/// InitOperands - Initialize the operands list of this with 1 operand.
name|void
name|InitOperands
argument_list|(
argument|SDUse *Ops
argument_list|,
argument|const SDValue&Op0
argument_list|)
block|{
name|Ops
index|[
literal|0
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|0
index|]
operator|.
name|setInitial
argument_list|(
name|Op0
argument_list|)
block|;
name|NumOperands
operator|=
literal|1
block|;
name|OperandList
operator|=
name|Ops
block|;
name|checkForCycles
argument_list|(
name|this
argument_list|)
block|;   }
comment|/// InitOperands - Initialize the operands list of this with 2 operands.
name|void
name|InitOperands
argument_list|(
argument|SDUse *Ops
argument_list|,
argument|const SDValue&Op0
argument_list|,
argument|const SDValue&Op1
argument_list|)
block|{
name|Ops
index|[
literal|0
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|0
index|]
operator|.
name|setInitial
argument_list|(
name|Op0
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setInitial
argument_list|(
name|Op1
argument_list|)
block|;
name|NumOperands
operator|=
literal|2
block|;
name|OperandList
operator|=
name|Ops
block|;
name|checkForCycles
argument_list|(
name|this
argument_list|)
block|;   }
comment|/// InitOperands - Initialize the operands list of this with 3 operands.
name|void
name|InitOperands
argument_list|(
argument|SDUse *Ops
argument_list|,
argument|const SDValue&Op0
argument_list|,
argument|const SDValue&Op1
argument_list|,
argument|const SDValue&Op2
argument_list|)
block|{
name|Ops
index|[
literal|0
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|0
index|]
operator|.
name|setInitial
argument_list|(
name|Op0
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setInitial
argument_list|(
name|Op1
argument_list|)
block|;
name|Ops
index|[
literal|2
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|2
index|]
operator|.
name|setInitial
argument_list|(
name|Op2
argument_list|)
block|;
name|NumOperands
operator|=
literal|3
block|;
name|OperandList
operator|=
name|Ops
block|;
name|checkForCycles
argument_list|(
name|this
argument_list|)
block|;   }
comment|/// InitOperands - Initialize the operands list of this with 4 operands.
name|void
name|InitOperands
argument_list|(
argument|SDUse *Ops
argument_list|,
argument|const SDValue&Op0
argument_list|,
argument|const SDValue&Op1
argument_list|,
argument|const SDValue&Op2
argument_list|,
argument|const SDValue&Op3
argument_list|)
block|{
name|Ops
index|[
literal|0
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|0
index|]
operator|.
name|setInitial
argument_list|(
name|Op0
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setInitial
argument_list|(
name|Op1
argument_list|)
block|;
name|Ops
index|[
literal|2
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|2
index|]
operator|.
name|setInitial
argument_list|(
name|Op2
argument_list|)
block|;
name|Ops
index|[
literal|3
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|3
index|]
operator|.
name|setInitial
argument_list|(
name|Op3
argument_list|)
block|;
name|NumOperands
operator|=
literal|4
block|;
name|OperandList
operator|=
name|Ops
block|;
name|checkForCycles
argument_list|(
name|this
argument_list|)
block|;   }
comment|/// InitOperands - Initialize the operands list of this with N operands.
name|void
name|InitOperands
argument_list|(
argument|SDUse *Ops
argument_list|,
argument|const SDValue *Vals
argument_list|,
argument|unsigned N
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
block|{
name|Ops
index|[
name|i
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|Ops
index|[
name|i
index|]
operator|.
name|setInitial
argument_list|(
name|Vals
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|NumOperands
operator|=
name|N
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OperandList
operator|=
name|Ops
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|checkForCycles
argument_list|(
name|this
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// DropOperands - Release the operands and set this node to have
end_comment

begin_comment
comment|/// zero operands.
end_comment

begin_expr_stmt
unit|void
name|DropOperands
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// Wrapper class for IR location info (IR ordering and DebugLoc) to be passed
end_comment

begin_comment
comment|/// into SDNode creation functions.
end_comment

begin_comment
comment|/// When an SDNode is created from the DAGBuilder, the DebugLoc is extracted
end_comment

begin_comment
comment|/// from the original Instruction, and IROrder is the ordinal position of
end_comment

begin_comment
comment|/// the instruction.
end_comment

begin_comment
comment|/// When an SDNode is created after the DAG is being built, both DebugLoc and
end_comment

begin_comment
comment|/// the IROrder are propagated from the original SDNode.
end_comment

begin_comment
comment|/// So SDLoc class provides two constructors besides the default one, one to
end_comment

begin_comment
comment|/// be used by the DAGBuilder, the other to be used by others.
end_comment

begin_decl_stmt
name|class
name|SDLoc
block|{
name|private
label|:
comment|// Ptr could be used for either Instruction* or SDNode*. It is used for
comment|// Instruction* if IROrder is not -1.
specifier|const
name|void
modifier|*
name|Ptr
decl_stmt|;
name|int
name|IROrder
decl_stmt|;
name|public
label|:
name|SDLoc
argument_list|()
operator|:
name|Ptr
argument_list|(
name|NULL
argument_list|)
operator|,
name|IROrder
argument_list|(
literal|0
argument_list|)
block|{}
name|SDLoc
argument_list|(
specifier|const
name|SDNode
operator|*
name|N
argument_list|)
operator|:
name|Ptr
argument_list|(
name|N
argument_list|)
operator|,
name|IROrder
argument_list|(
argument|-
literal|1
argument_list|)
block|{
name|assert
argument_list|(
name|N
operator|&&
literal|"null SDNode"
argument_list|)
block|;   }
name|SDLoc
argument_list|(
argument|const SDValue V
argument_list|)
operator|:
name|Ptr
argument_list|(
name|V
operator|.
name|getNode
argument_list|()
argument_list|)
operator|,
name|IROrder
argument_list|(
argument|-
literal|1
argument_list|)
block|{
name|assert
argument_list|(
name|Ptr
operator|&&
literal|"null SDNode"
argument_list|)
block|;   }
name|SDLoc
argument_list|(
argument|const Instruction *I
argument_list|,
argument|int Order
argument_list|)
operator|:
name|Ptr
argument_list|(
name|I
argument_list|)
operator|,
name|IROrder
argument_list|(
argument|Order
argument_list|)
block|{
name|assert
argument_list|(
name|Order
operator|>=
literal|0
operator|&&
literal|"bad IROrder"
argument_list|)
block|;   }
name|unsigned
name|getIROrder
argument_list|()
block|{
if|if
condition|(
name|IROrder
operator|>=
literal|0
operator|||
name|Ptr
operator|==
name|NULL
condition|)
block|{
return|return
operator|(
name|unsigned
operator|)
name|IROrder
return|;
block|}
specifier|const
name|SDNode
modifier|*
name|N
init|=
operator|(
specifier|const
name|SDNode
operator|*
operator|)
operator|(
name|Ptr
operator|)
decl_stmt|;
return|return
name|N
operator|->
name|getIROrder
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|DebugLoc
name|getDebugLoc
parameter_list|()
block|{
if|if
condition|(
name|Ptr
operator|==
name|NULL
condition|)
block|{
return|return
name|DebugLoc
argument_list|()
return|;
block|}
if|if
condition|(
name|IROrder
operator|>=
literal|0
condition|)
block|{
specifier|const
name|Instruction
modifier|*
name|I
init|=
operator|(
specifier|const
name|Instruction
operator|*
operator|)
operator|(
name|Ptr
operator|)
decl_stmt|;
return|return
name|I
operator|->
name|getDebugLoc
argument_list|()
return|;
block|}
specifier|const
name|SDNode
modifier|*
name|N
init|=
operator|(
specifier|const
name|SDNode
operator|*
operator|)
operator|(
name|Ptr
operator|)
decl_stmt|;
return|return
name|N
operator|->
name|getDebugLoc
argument_list|()
return|;
block|}
end_function

begin_comment
unit|};
comment|// Define inline functions from the SDValue class.
end_comment

begin_expr_stmt
specifier|inline
name|unsigned
name|SDValue
operator|::
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|getOpcode
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|EVT
name|SDValue
operator|::
name|getValueType
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|getValueType
argument_list|(
name|ResNo
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|unsigned
name|SDValue
operator|::
name|getNumOperands
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|getNumOperands
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|SDValue
operator|&
name|SDValue
operator|::
name|getOperand
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|Node
operator|->
name|getOperand
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|uint64_t
name|SDValue
operator|::
name|getConstantOperandVal
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|Node
operator|->
name|getConstantOperandVal
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|SDValue
operator|::
name|isTargetOpcode
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|isTargetOpcode
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|SDValue
operator|::
name|isTargetMemoryOpcode
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|isTargetMemoryOpcode
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|SDValue
operator|::
name|isMachineOpcode
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|isMachineOpcode
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|unsigned
name|SDValue
operator|::
name|getMachineOpcode
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|getMachineOpcode
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|SDValue
operator|::
name|use_empty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Node
operator|->
name|hasAnyUseOfValue
argument_list|(
name|ResNo
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|SDValue
operator|::
name|hasOneUse
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|hasNUsesOfValue
argument_list|(
literal|1
argument_list|,
name|ResNo
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DebugLoc
name|SDValue
operator|::
name|getDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|getDebugLoc
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|SDValue
operator|::
name|dump
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|dump
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|SDValue
operator|::
name|dumpr
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|dumpr
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Define inline functions from the SDUse class.
end_comment

begin_expr_stmt
specifier|inline
name|void
name|SDUse
operator|::
name|set
argument_list|(
argument|const SDValue&V
argument_list|)
block|{
if|if
condition|(
name|Val
operator|.
name|getNode
argument_list|()
condition|)
name|removeFromList
argument_list|()
expr_stmt|;
name|Val
operator|=
name|V
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|V
operator|.
name|getNode
argument_list|()
condition|)
name|V
operator|.
name|getNode
argument_list|()
operator|->
name|addUse
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
unit|}  inline
name|void
name|SDUse
operator|::
name|setInitial
argument_list|(
argument|const SDValue&V
argument_list|)
block|{
name|Val
operator|=
name|V
block|;
name|V
operator|.
name|getNode
argument_list|()
operator|->
name|addUse
argument_list|(
operator|*
name|this
argument_list|)
block|; }
specifier|inline
name|void
name|SDUse
operator|::
name|setNode
argument_list|(
argument|SDNode *N
argument_list|)
block|{
if|if
condition|(
name|Val
operator|.
name|getNode
argument_list|()
condition|)
name|removeFromList
argument_list|()
expr_stmt|;
name|Val
operator|.
name|setNode
argument_list|(
name|N
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|N
condition|)
name|N
operator|->
name|addUse
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
end_if

begin_comment
unit|}
comment|/// UnarySDNode - This class is used for single-operand SDNodes.  This is solely
end_comment

begin_comment
comment|/// to allow co-allocation of node operands with the node itself.
end_comment

begin_label
unit|class
name|UnarySDNode
label|:
end_label

begin_decl_stmt
name|public
name|SDNode
block|{
name|SDUse
name|Op
decl_stmt|;
name|public
label|:
name|UnarySDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|SDValue X
argument_list|)
block|:
name|SDNode
argument_list|(
argument|Opc
argument_list|,
argument|Order
argument_list|,
argument|dl
argument_list|,
argument|VTs
argument_list|)
block|{
name|InitOperands
argument_list|(
operator|&
name|Op
argument_list|,
name|X
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// BinarySDNode - This class is used for two-operand SDNodes.  This is solely
end_comment

begin_comment
comment|/// to allow co-allocation of node operands with the node itself.
end_comment

begin_decl_stmt
name|class
name|BinarySDNode
range|:
name|public
name|SDNode
block|{
name|SDUse
name|Ops
index|[
literal|2
index|]
block|;
name|public
operator|:
name|BinarySDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|SDValue X
argument_list|,
argument|SDValue Y
argument_list|)
operator|:
name|SDNode
argument_list|(
argument|Opc
argument_list|,
argument|Order
argument_list|,
argument|dl
argument_list|,
argument|VTs
argument_list|)
block|{
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|X
argument_list|,
name|Y
argument_list|)
block|;   }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// TernarySDNode - This class is used for three-operand SDNodes. This is solely
end_comment

begin_comment
comment|/// to allow co-allocation of node operands with the node itself.
end_comment

begin_decl_stmt
name|class
name|TernarySDNode
range|:
name|public
name|SDNode
block|{
name|SDUse
name|Ops
index|[
literal|3
index|]
block|;
name|public
operator|:
name|TernarySDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|SDValue X
argument_list|,
argument|SDValue Y
argument_list|,
argument|SDValue Z
argument_list|)
operator|:
name|SDNode
argument_list|(
argument|Opc
argument_list|,
argument|Order
argument_list|,
argument|dl
argument_list|,
argument|VTs
argument_list|)
block|{
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|X
argument_list|,
name|Y
argument_list|,
name|Z
argument_list|)
block|;   }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// HandleSDNode - This class is used to form a handle around another node that
end_comment

begin_comment
comment|/// is persistent and is updated across invocations of replaceAllUsesWith on its
end_comment

begin_comment
comment|/// operand.  This node should be directly created by end-users and not added to
end_comment

begin_comment
comment|/// the AllNodes list.
end_comment

begin_decl_stmt
name|class
name|HandleSDNode
range|:
name|public
name|SDNode
block|{
name|SDUse
name|Op
block|;
name|public
operator|:
name|explicit
name|HandleSDNode
argument_list|(
argument|SDValue X
argument_list|)
operator|:
name|SDNode
argument_list|(
argument|ISD::HANDLENODE
argument_list|,
literal|0
argument_list|,
argument|DebugLoc()
argument_list|,
argument|getSDVTList(MVT::Other)
argument_list|)
block|{
name|InitOperands
argument_list|(
operator|&
name|Op
argument_list|,
name|X
argument_list|)
block|;   }
operator|~
name|HandleSDNode
argument_list|()
block|;
specifier|const
name|SDValue
operator|&
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Op
return|;
block|}
expr|}
block|;
name|class
name|AddrSpaceCastSDNode
operator|:
name|public
name|UnarySDNode
block|{
name|private
operator|:
name|unsigned
name|SrcAddrSpace
block|;
name|unsigned
name|DestAddrSpace
block|;
name|public
operator|:
name|AddrSpaceCastSDNode
argument_list|(
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|EVT VT
argument_list|,
argument|SDValue X
argument_list|,
argument|unsigned SrcAS
argument_list|,
argument|unsigned DestAS
argument_list|)
block|;
name|unsigned
name|getSrcAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|SrcAddrSpace
return|;
block|}
name|unsigned
name|getDestAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|DestAddrSpace
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ADDRSPACECAST
return|;
block|}
expr|}
block|;
comment|/// Abstact virtual class for operations for memory operations
name|class
name|MemSDNode
operator|:
name|public
name|SDNode
block|{
name|private
operator|:
comment|// MemoryVT - VT of in-memory value.
name|EVT
name|MemoryVT
block|;
name|protected
operator|:
comment|/// MMO - Memory reference information.
name|MachineMemOperand
operator|*
name|MMO
block|;
name|public
operator|:
name|MemSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|EVT MemoryVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
block|;
name|MemSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|const SDValue *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|EVT MemoryVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
block|;
name|bool
name|readMem
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|isLoad
argument_list|()
return|;
block|}
name|bool
name|writeMem
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|isStore
argument_list|()
return|;
block|}
comment|/// Returns alignment and volatility of the memory access
name|unsigned
name|getOriginalAlignment
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|getBaseAlignment
argument_list|()
return|;
block|}
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|getAlignment
argument_list|()
return|;
block|}
comment|/// getRawSubclassData - Return the SubclassData value, which contains an
comment|/// encoding of the volatile flag, as well as bits used by subclasses. This
comment|/// function should only be used to compute a FoldingSetNodeID value.
name|unsigned
name|getRawSubclassData
argument_list|()
specifier|const
block|{
return|return
name|SubclassData
return|;
block|}
comment|// We access subclass data here so that we can check consistency
comment|// with MachineMemOperand information.
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
operator|(
name|SubclassData
operator|>>
literal|5
operator|)
operator|&
literal|1
return|;
block|}
name|bool
name|isNonTemporal
argument_list|()
specifier|const
block|{
return|return
operator|(
name|SubclassData
operator|>>
literal|6
operator|)
operator|&
literal|1
return|;
block|}
name|bool
name|isInvariant
argument_list|()
specifier|const
block|{
return|return
operator|(
name|SubclassData
operator|>>
literal|7
operator|)
operator|&
literal|1
return|;
block|}
name|AtomicOrdering
name|getOrdering
argument_list|()
specifier|const
block|{
return|return
name|AtomicOrdering
argument_list|(
operator|(
name|SubclassData
operator|>>
literal|8
operator|)
operator|&
literal|15
argument_list|)
return|;
block|}
name|SynchronizationScope
name|getSynchScope
argument_list|()
specifier|const
block|{
return|return
name|SynchronizationScope
argument_list|(
operator|(
name|SubclassData
operator|>>
literal|12
operator|)
operator|&
literal|1
argument_list|)
return|;
block|}
comment|/// Returns the SrcValue and offset that describes the location of the access
specifier|const
name|Value
operator|*
name|getSrcValue
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|getValue
argument_list|()
return|;
block|}
name|int64_t
name|getSrcValueOffset
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|getOffset
argument_list|()
return|;
block|}
comment|/// Returns the TBAAInfo that describes the dereference.
specifier|const
name|MDNode
operator|*
name|getTBAAInfo
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|getTBAAInfo
argument_list|()
return|;
block|}
comment|/// Returns the Ranges that describes the dereference.
specifier|const
name|MDNode
operator|*
name|getRanges
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|getRanges
argument_list|()
return|;
block|}
comment|/// getMemoryVT - Return the type of the in-memory value.
name|EVT
name|getMemoryVT
argument_list|()
specifier|const
block|{
return|return
name|MemoryVT
return|;
block|}
comment|/// getMemOperand - Return a MachineMemOperand object describing the memory
comment|/// reference performed by operation.
name|MachineMemOperand
operator|*
name|getMemOperand
argument_list|()
specifier|const
block|{
return|return
name|MMO
return|;
block|}
specifier|const
name|MachinePointerInfo
operator|&
name|getPointerInfo
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|getPointerInfo
argument_list|()
return|;
block|}
comment|/// getAddressSpace - Return the address space for the associated pointer
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getPointerInfo
argument_list|()
operator|.
name|getAddrSpace
argument_list|()
return|;
block|}
comment|/// refineAlignment - Update this MemSDNode's MachineMemOperand information
comment|/// to reflect the alignment of NewMMO, if it has a greater alignment.
comment|/// This must only be used when the new alignment applies to all users of
comment|/// this MachineMemOperand.
name|void
name|refineAlignment
argument_list|(
argument|const MachineMemOperand *NewMMO
argument_list|)
block|{
name|MMO
operator|->
name|refineAlignment
argument_list|(
name|NewMMO
argument_list|)
block|;   }
specifier|const
name|SDValue
operator|&
name|getChain
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getBasePtr
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|STORE
operator|?
literal|2
operator|:
literal|1
argument_list|)
return|;
block|}
comment|// Methods to support isa and dyn_cast
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
comment|// For some targets, we lower some target intrinsics to a MemIntrinsicNode
comment|// with either an intrinsic or a target opcode.
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|LOAD
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|STORE
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|PREFETCH
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_CMP_SWAP
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_SWAP
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_ADD
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_SUB
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_AND
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_OR
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_XOR
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_NAND
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_MIN
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_MAX
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_UMIN
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_UMAX
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_STORE
operator|||
name|N
operator|->
name|isTargetMemoryOpcode
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// AtomicSDNode - A SDNode reprenting atomic operations.
comment|///
name|class
name|AtomicSDNode
operator|:
name|public
name|MemSDNode
block|{
name|SDUse
name|Ops
index|[
literal|4
index|]
block|;
name|void
name|InitAtomic
argument_list|(
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|)
block|{
comment|// This must match encodeMemSDNodeFlags() in SelectionDAG.cpp.
name|assert
argument_list|(
operator|(
name|Ordering
operator|&
literal|15
operator|)
operator|==
name|Ordering
operator|&&
literal|"Ordering may not require more than 4 bits!"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|SynchScope
operator|&
literal|1
operator|)
operator|==
name|SynchScope
operator|&&
literal|"SynchScope may not require more than 1 bit!"
argument_list|)
block|;
name|SubclassData
operator||=
name|Ordering
operator|<<
literal|8
block|;
name|SubclassData
operator||=
name|SynchScope
operator|<<
literal|12
block|;
name|assert
argument_list|(
name|getOrdering
argument_list|()
operator|==
name|Ordering
operator|&&
literal|"Ordering encoding error!"
argument_list|)
block|;
name|assert
argument_list|(
name|getSynchScope
argument_list|()
operator|==
name|SynchScope
operator|&&
literal|"Synch-scope encoding error!"
argument_list|)
block|;   }
name|public
operator|:
comment|// Opc:   opcode for atomic
comment|// VTL:    value type list
comment|// Chain:  memory chain for operaand
comment|// Ptr:    address to update as a SDValue
comment|// Cmp:    compare value
comment|// Swp:    swap value
comment|// SrcVal: address to update as a Value (used for MemOperand)
comment|// Align:  alignment of memory
name|AtomicSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTL
argument_list|,
argument|EVT MemVT
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Ptr
argument_list|,
argument|SDValue Cmp
argument_list|,
argument|SDValue Swp
argument_list|,
argument|MachineMemOperand *MMO
argument_list|,
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|)
operator|:
name|MemSDNode
argument_list|(
argument|Opc
argument_list|,
argument|Order
argument_list|,
argument|dl
argument_list|,
argument|VTL
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|InitAtomic
argument_list|(
name|Ordering
argument_list|,
name|SynchScope
argument_list|)
block|;
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|Chain
argument_list|,
name|Ptr
argument_list|,
name|Cmp
argument_list|,
name|Swp
argument_list|)
block|;   }
name|AtomicSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTL
argument_list|,
argument|EVT MemVT
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Ptr
argument_list|,
argument|SDValue Val
argument_list|,
argument|MachineMemOperand *MMO
argument_list|,
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|)
operator|:
name|MemSDNode
argument_list|(
argument|Opc
argument_list|,
argument|Order
argument_list|,
argument|dl
argument_list|,
argument|VTL
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|InitAtomic
argument_list|(
name|Ordering
argument_list|,
name|SynchScope
argument_list|)
block|;
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|Chain
argument_list|,
name|Ptr
argument_list|,
name|Val
argument_list|)
block|;   }
name|AtomicSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTL
argument_list|,
argument|EVT MemVT
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Ptr
argument_list|,
argument|MachineMemOperand *MMO
argument_list|,
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|)
operator|:
name|MemSDNode
argument_list|(
argument|Opc
argument_list|,
argument|Order
argument_list|,
argument|dl
argument_list|,
argument|VTL
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|InitAtomic
argument_list|(
name|Ordering
argument_list|,
name|SynchScope
argument_list|)
block|;
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|Chain
argument_list|,
name|Ptr
argument_list|)
block|;   }
name|AtomicSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTL
argument_list|,
argument|EVT MemVT
argument_list|,
argument|SDValue* AllOps
argument_list|,
argument|SDUse *DynOps
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|MachineMemOperand *MMO
argument_list|,
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|)
operator|:
name|MemSDNode
argument_list|(
argument|Opc
argument_list|,
argument|Order
argument_list|,
argument|dl
argument_list|,
argument|VTL
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|InitAtomic
argument_list|(
name|Ordering
argument_list|,
name|SynchScope
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|DynOps
operator|||
name|NumOps
operator|<=
name|array_lengthof
argument_list|(
name|Ops
argument_list|)
operator|)
operator|&&
literal|"Too many ops for internal storage!"
argument_list|)
block|;
name|InitOperands
argument_list|(
name|DynOps
condition|?
name|DynOps
else|:
name|Ops
argument_list|,
name|AllOps
argument_list|,
name|NumOps
argument_list|)
block|;   }
specifier|const
name|SDValue
operator|&
name|getBasePtr
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getVal
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|2
argument_list|)
return|;
block|}
name|bool
name|isCompareAndSwap
argument_list|()
specifier|const
block|{
name|unsigned
name|Op
operator|=
name|getOpcode
argument_list|()
block|;
return|return
name|Op
operator|==
name|ISD
operator|::
name|ATOMIC_CMP_SWAP
return|;
block|}
comment|// Methods to support isa and dyn_cast
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_CMP_SWAP
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_SWAP
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_ADD
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_SUB
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_AND
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_OR
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_XOR
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_NAND
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_MIN
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_MAX
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_UMIN
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_UMAX
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_STORE
return|;
block|}
expr|}
block|;
comment|/// MemIntrinsicSDNode - This SDNode is used for target intrinsics that touch
comment|/// memory and need an associated MachineMemOperand. Its opcode may be
comment|/// INTRINSIC_VOID, INTRINSIC_W_CHAIN, PREFETCH, or a target-specific opcode
comment|/// with a value not less than FIRST_TARGET_MEMORY_OPCODE.
name|class
name|MemIntrinsicSDNode
operator|:
name|public
name|MemSDNode
block|{
name|public
operator|:
name|MemIntrinsicSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|const SDValue *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|EVT MemoryVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
operator|:
name|MemSDNode
argument_list|(
argument|Opc
argument_list|,
argument|Order
argument_list|,
argument|dl
argument_list|,
argument|VTs
argument_list|,
argument|Ops
argument_list|,
argument|NumOps
argument_list|,
argument|MemoryVT
argument_list|,
argument|MMO
argument_list|)
block|{   }
comment|// Methods to support isa and dyn_cast
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
comment|// We lower some target intrinsics to their target opcode
comment|// early a node with a target opcode can be of this class
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|INTRINSIC_W_CHAIN
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|INTRINSIC_VOID
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|PREFETCH
operator|||
name|N
operator|->
name|isTargetMemoryOpcode
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// ShuffleVectorSDNode - This SDNode is used to implement the code generator
comment|/// support for the llvm IR shufflevector instruction.  It combines elements
comment|/// from two input vectors into a new input vector, with the selection and
comment|/// ordering of elements determined by an array of integers, referred to as
comment|/// the shuffle mask.  For input vectors of width N, mask indices of 0..N-1
comment|/// refer to elements from the LHS input, and indices from N to 2N-1 the RHS.
comment|/// An index of -1 is treated as undef, such that the code generator may put
comment|/// any value in the corresponding element of the result.
name|class
name|ShuffleVectorSDNode
operator|:
name|public
name|SDNode
block|{
name|SDUse
name|Ops
index|[
literal|2
index|]
block|;
comment|// The memory for Mask is owned by the SelectionDAG's OperandAllocator, and
comment|// is freed when the SelectionDAG object is destroyed.
specifier|const
name|int
operator|*
name|Mask
block|;
name|protected
operator|:
name|friend
name|class
name|SelectionDAG
block|;
name|ShuffleVectorSDNode
argument_list|(
argument|EVT VT
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDValue N1
argument_list|,
argument|SDValue N2
argument_list|,
argument|const int *M
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|VECTOR_SHUFFLE
argument_list|,
name|Order
argument_list|,
name|dl
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Mask
argument_list|(
argument|M
argument_list|)
block|{
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|N1
argument_list|,
name|N2
argument_list|)
block|;   }
name|public
operator|:
name|ArrayRef
operator|<
name|int
operator|>
name|getMask
argument_list|()
specifier|const
block|{
name|EVT
name|VT
operator|=
name|getValueType
argument_list|(
literal|0
argument_list|)
block|;
return|return
name|makeArrayRef
argument_list|(
name|Mask
argument_list|,
name|VT
operator|.
name|getVectorNumElements
argument_list|()
argument_list|)
return|;
block|}
name|int
name|getMaskElt
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|getValueType
argument_list|(
literal|0
argument_list|)
operator|.
name|getVectorNumElements
argument_list|()
operator|&&
literal|"Idx out of range!"
argument_list|)
block|;
return|return
name|Mask
index|[
name|Idx
index|]
return|;
block|}
name|bool
name|isSplat
argument_list|()
specifier|const
block|{
return|return
name|isSplatMask
argument_list|(
name|Mask
argument_list|,
name|getValueType
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
block|}
name|int
name|getSplatIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isSplat
argument_list|()
operator|&&
literal|"Cannot get splat index for non-splat!"
argument_list|)
block|;
name|EVT
name|VT
operator|=
name|getValueType
argument_list|(
literal|0
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|VT
operator|.
name|getVectorNumElements
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|Mask
index|[
name|i
index|]
operator|>=
literal|0
condition|)
return|return
name|Mask
index|[
name|i
index|]
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Splat with all undef indices?"
argument_list|)
expr_stmt|;
block|}
specifier|static
name|bool
name|isSplatMask
argument_list|(
argument|const int *Mask
argument_list|,
argument|EVT VT
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|VECTOR_SHUFFLE
return|;
block|}
expr|}
block|;
name|class
name|ConstantSDNode
operator|:
name|public
name|SDNode
block|{
specifier|const
name|ConstantInt
operator|*
name|Value
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|ConstantSDNode
argument_list|(
argument|bool isTarget
argument_list|,
argument|const ConstantInt *val
argument_list|,
argument|EVT VT
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarget
condition|?
name|ISD
operator|::
name|TargetConstant
else|:
name|ISD
operator|::
name|Constant
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Value
argument_list|(
argument|val
argument_list|)
block|{   }
name|public
operator|:
specifier|const
name|ConstantInt
operator|*
name|getConstantIntValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
specifier|const
name|APInt
operator|&
name|getAPIntValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|getValue
argument_list|()
return|;
block|}
name|uint64_t
name|getZExtValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|getZExtValue
argument_list|()
return|;
block|}
name|int64_t
name|getSExtValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|getSExtValue
argument_list|()
return|;
block|}
name|bool
name|isOne
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|isOne
argument_list|()
return|;
block|}
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|isNullValue
argument_list|()
return|;
block|}
name|bool
name|isAllOnesValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|isAllOnesValue
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|Constant
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetConstant
return|;
block|}
expr|}
block|;
name|class
name|ConstantFPSDNode
operator|:
name|public
name|SDNode
block|{
specifier|const
name|ConstantFP
operator|*
name|Value
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|ConstantFPSDNode
argument_list|(
argument|bool isTarget
argument_list|,
argument|const ConstantFP *val
argument_list|,
argument|EVT VT
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarget
condition|?
name|ISD
operator|::
name|TargetConstantFP
else|:
name|ISD
operator|::
name|ConstantFP
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Value
argument_list|(
argument|val
argument_list|)
block|{   }
name|public
operator|:
specifier|const
name|APFloat
operator|&
name|getValueAPF
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|getValueAPF
argument_list|()
return|;
block|}
specifier|const
name|ConstantFP
operator|*
name|getConstantFPValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
comment|/// isZero - Return true if the value is positive or negative zero.
name|bool
name|isZero
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|isZero
argument_list|()
return|;
block|}
comment|/// isNaN - Return true if the value is a NaN.
name|bool
name|isNaN
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|isNaN
argument_list|()
return|;
block|}
comment|/// isExactlyValue - We don't rely on operator== working on double values, as
comment|/// it returns true for things that are clearly not equal, like -0.0 and 0.0.
comment|/// As such, this method can be used to do an exact bit-for-bit comparison of
comment|/// two floating point values.
comment|/// We leave the version with the double argument here because it's just so
comment|/// convenient to write "2.0" and the like.  Without this function we'd
comment|/// have to duplicate its logic everywhere it's called.
name|bool
name|isExactlyValue
argument_list|(
argument|double V
argument_list|)
specifier|const
block|{
name|bool
name|ignored
block|;
name|APFloat
name|Tmp
argument_list|(
name|V
argument_list|)
block|;
name|Tmp
operator|.
name|convert
argument_list|(
name|Value
operator|->
name|getValueAPF
argument_list|()
operator|.
name|getSemantics
argument_list|()
argument_list|,
name|APFloat
operator|::
name|rmNearestTiesToEven
argument_list|,
operator|&
name|ignored
argument_list|)
block|;
return|return
name|isExactlyValue
argument_list|(
name|Tmp
argument_list|)
return|;
block|}
name|bool
name|isExactlyValue
argument_list|(
argument|const APFloat& V
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|isValueValidForType
argument_list|(
argument|EVT VT
argument_list|,
argument|const APFloat& Val
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ConstantFP
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetConstantFP
return|;
block|}
expr|}
block|;
name|class
name|GlobalAddressSDNode
operator|:
name|public
name|SDNode
block|{
specifier|const
name|GlobalValue
operator|*
name|TheGlobal
block|;
name|int64_t
name|Offset
block|;
name|unsigned
name|char
name|TargetFlags
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|GlobalAddressSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|const GlobalValue *GA
argument_list|,
argument|EVT VT
argument_list|,
argument|int64_t o
argument_list|,
argument|unsigned char TargetFlags
argument_list|)
block|;
name|public
operator|:
specifier|const
name|GlobalValue
operator|*
name|getGlobal
argument_list|()
specifier|const
block|{
return|return
name|TheGlobal
return|;
block|}
name|int64_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|unsigned
name|char
name|getTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|TargetFlags
return|;
block|}
comment|// Return the address space this GlobalAddress belongs to.
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|GlobalAddress
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetGlobalAddress
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|GlobalTLSAddress
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetGlobalTLSAddress
return|;
block|}
expr|}
block|;
name|class
name|FrameIndexSDNode
operator|:
name|public
name|SDNode
block|{
name|int
name|FI
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|FrameIndexSDNode
argument_list|(
argument|int fi
argument_list|,
argument|EVT VT
argument_list|,
argument|bool isTarg
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarg
condition|?
name|ISD
operator|::
name|TargetFrameIndex
else|:
name|ISD
operator|::
name|FrameIndex
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|FI
argument_list|(
argument|fi
argument_list|)
block|{   }
name|public
operator|:
name|int
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|FI
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|FrameIndex
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetFrameIndex
return|;
block|}
expr|}
block|;
name|class
name|JumpTableSDNode
operator|:
name|public
name|SDNode
block|{
name|int
name|JTI
block|;
name|unsigned
name|char
name|TargetFlags
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|JumpTableSDNode
argument_list|(
argument|int jti
argument_list|,
argument|EVT VT
argument_list|,
argument|bool isTarg
argument_list|,
argument|unsigned char TF
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarg
condition|?
name|ISD
operator|::
name|TargetJumpTable
else|:
name|ISD
operator|::
name|JumpTable
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|JTI
argument_list|(
name|jti
argument_list|)
block|,
name|TargetFlags
argument_list|(
argument|TF
argument_list|)
block|{   }
name|public
operator|:
name|int
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|JTI
return|;
block|}
name|unsigned
name|char
name|getTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|TargetFlags
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|JumpTable
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetJumpTable
return|;
block|}
expr|}
block|;
name|class
name|ConstantPoolSDNode
operator|:
name|public
name|SDNode
block|{
expr|union
block|{
specifier|const
name|Constant
operator|*
name|ConstVal
block|;
name|MachineConstantPoolValue
operator|*
name|MachineCPVal
block|;   }
name|Val
block|;
name|int
name|Offset
block|;
comment|// It's a MachineConstantPoolValue if top bit is set.
name|unsigned
name|Alignment
block|;
comment|// Minimum alignment requirement of CP (not log2 value).
name|unsigned
name|char
name|TargetFlags
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|ConstantPoolSDNode
argument_list|(
argument|bool isTarget
argument_list|,
argument|const Constant *c
argument_list|,
argument|EVT VT
argument_list|,
argument|int o
argument_list|,
argument|unsigned Align
argument_list|,
argument|unsigned char TF
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarget
condition|?
name|ISD
operator|::
name|TargetConstantPool
else|:
name|ISD
operator|::
name|ConstantPool
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Offset
argument_list|(
name|o
argument_list|)
block|,
name|Alignment
argument_list|(
name|Align
argument_list|)
block|,
name|TargetFlags
argument_list|(
argument|TF
argument_list|)
block|{
name|assert
argument_list|(
name|Offset
operator|>=
literal|0
operator|&&
literal|"Offset is too large"
argument_list|)
block|;
name|Val
operator|.
name|ConstVal
operator|=
name|c
block|;   }
name|ConstantPoolSDNode
argument_list|(
argument|bool isTarget
argument_list|,
argument|MachineConstantPoolValue *v
argument_list|,
argument|EVT VT
argument_list|,
argument|int o
argument_list|,
argument|unsigned Align
argument_list|,
argument|unsigned char TF
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarget
condition|?
name|ISD
operator|::
name|TargetConstantPool
else|:
name|ISD
operator|::
name|ConstantPool
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Offset
argument_list|(
name|o
argument_list|)
block|,
name|Alignment
argument_list|(
name|Align
argument_list|)
block|,
name|TargetFlags
argument_list|(
argument|TF
argument_list|)
block|{
name|assert
argument_list|(
name|Offset
operator|>=
literal|0
operator|&&
literal|"Offset is too large"
argument_list|)
block|;
name|Val
operator|.
name|MachineCPVal
operator|=
name|v
block|;
name|Offset
operator||=
literal|1
operator|<<
operator|(
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
name|CHAR_BIT
operator|-
literal|1
operator|)
block|;   }
name|public
operator|:
name|bool
name|isMachineConstantPoolEntry
argument_list|()
specifier|const
block|{
return|return
name|Offset
operator|<
literal|0
return|;
block|}
specifier|const
name|Constant
operator|*
name|getConstVal
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isMachineConstantPoolEntry
argument_list|()
operator|&&
literal|"Wrong constantpool type"
argument_list|)
block|;
return|return
name|Val
operator|.
name|ConstVal
return|;
block|}
name|MachineConstantPoolValue
operator|*
name|getMachineCPVal
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isMachineConstantPoolEntry
argument_list|()
operator|&&
literal|"Wrong constantpool type"
argument_list|)
block|;
return|return
name|Val
operator|.
name|MachineCPVal
return|;
block|}
name|int
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
operator|&
operator|~
operator|(
literal|1
operator|<<
operator|(
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
name|CHAR_BIT
operator|-
literal|1
operator|)
operator|)
return|;
block|}
comment|// Return the alignment of this constant pool object, which is either 0 (for
comment|// default alignment) or the desired value.
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
name|unsigned
name|char
name|getTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|TargetFlags
return|;
block|}
name|Type
operator|*
name|getType
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ConstantPool
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetConstantPool
return|;
block|}
expr|}
block|;
comment|/// Completely target-dependent object reference.
name|class
name|TargetIndexSDNode
operator|:
name|public
name|SDNode
block|{
name|unsigned
name|char
name|TargetFlags
block|;
name|int
name|Index
block|;
name|int64_t
name|Offset
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|public
operator|:
name|TargetIndexSDNode
argument_list|(
argument|int Idx
argument_list|,
argument|EVT VT
argument_list|,
argument|int64_t Ofs
argument_list|,
argument|unsigned char TF
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|TargetIndex
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|TargetFlags
argument_list|(
name|TF
argument_list|)
block|,
name|Index
argument_list|(
name|Idx
argument_list|)
block|,
name|Offset
argument_list|(
argument|Ofs
argument_list|)
block|{}
name|public
operator|:
name|unsigned
name|char
name|getTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|TargetFlags
return|;
block|}
name|int
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|Index
return|;
block|}
name|int64_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetIndex
return|;
block|}
expr|}
block|;
name|class
name|BasicBlockSDNode
operator|:
name|public
name|SDNode
block|{
name|MachineBasicBlock
operator|*
name|MBB
block|;
name|friend
name|class
name|SelectionDAG
block|;
comment|/// Debug info is meaningful and potentially useful here, but we create
comment|/// blocks out of order when they're jumped to, which makes it a bit
comment|/// harder.  Let's see if we need it first.
name|explicit
name|BasicBlockSDNode
argument_list|(
name|MachineBasicBlock
operator|*
name|mbb
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|BasicBlock
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|MBB
argument_list|(
argument|mbb
argument_list|)
block|{}
name|public
operator|:
name|MachineBasicBlock
operator|*
name|getBasicBlock
argument_list|()
specifier|const
block|{
return|return
name|MBB
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|BasicBlock
return|;
block|}
expr|}
block|;
comment|/// BuildVectorSDNode - A "pseudo-class" with methods for operating on
comment|/// BUILD_VECTORs.
name|class
name|BuildVectorSDNode
operator|:
name|public
name|SDNode
block|{
comment|// These are constructed as SDNodes and then cast to BuildVectorSDNodes.
name|explicit
name|BuildVectorSDNode
argument_list|()
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
comment|/// isConstantSplat - Check if this is a constant splat, and if so, find the
comment|/// smallest element size that splats the vector.  If MinSplatBits is
comment|/// nonzero, the element size must be at least that large.  Note that the
comment|/// splat element may be the entire vector (i.e., a one element vector).
comment|/// Returns the splat element value in SplatValue.  Any undefined bits in
comment|/// that value are zero, and the corresponding bits in the SplatUndef mask
comment|/// are set.  The SplatBitSize value is set to the splat element size in
comment|/// bits.  HasAnyUndefs is set to true if any bits in the vector are
comment|/// undefined.  isBigEndian describes the endianness of the target.
name|bool
name|isConstantSplat
argument_list|(
argument|APInt&SplatValue
argument_list|,
argument|APInt&SplatUndef
argument_list|,
argument|unsigned&SplatBitSize
argument_list|,
argument|bool&HasAnyUndefs
argument_list|,
argument|unsigned MinSplatBits =
literal|0
argument_list|,
argument|bool isBigEndian = false
argument_list|)
block|;
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|BUILD_VECTOR
return|;
block|}
expr|}
block|;
comment|/// SrcValueSDNode - An SDNode that holds an arbitrary LLVM IR Value. This is
comment|/// used when the SelectionDAG needs to make a simple reference to something
comment|/// in the LLVM IR representation.
comment|///
name|class
name|SrcValueSDNode
operator|:
name|public
name|SDNode
block|{
specifier|const
name|Value
operator|*
name|V
block|;
name|friend
name|class
name|SelectionDAG
block|;
comment|/// Create a SrcValue for a general value.
name|explicit
name|SrcValueSDNode
argument_list|(
specifier|const
name|Value
operator|*
name|v
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|SRCVALUE
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|V
argument_list|(
argument|v
argument_list|)
block|{}
name|public
operator|:
comment|/// getValue - return the contained Value.
specifier|const
name|Value
operator|*
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|V
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|SRCVALUE
return|;
block|}
expr|}
block|;
name|class
name|MDNodeSDNode
operator|:
name|public
name|SDNode
block|{
specifier|const
name|MDNode
operator|*
name|MD
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|explicit
name|MDNodeSDNode
argument_list|(
specifier|const
name|MDNode
operator|*
name|md
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|MDNODE_SDNODE
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|MD
argument_list|(
argument|md
argument_list|)
block|{}
name|public
operator|:
specifier|const
name|MDNode
operator|*
name|getMD
argument_list|()
specifier|const
block|{
return|return
name|MD
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|MDNODE_SDNODE
return|;
block|}
expr|}
block|;
name|class
name|RegisterSDNode
operator|:
name|public
name|SDNode
block|{
name|unsigned
name|Reg
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|RegisterSDNode
argument_list|(
argument|unsigned reg
argument_list|,
argument|EVT VT
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|Register
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Reg
argument_list|(
argument|reg
argument_list|)
block|{   }
name|public
operator|:
name|unsigned
name|getReg
argument_list|()
specifier|const
block|{
return|return
name|Reg
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|Register
return|;
block|}
expr|}
block|;
name|class
name|RegisterMaskSDNode
operator|:
name|public
name|SDNode
block|{
comment|// The memory for RegMask is not owned by the node.
specifier|const
name|uint32_t
operator|*
name|RegMask
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|RegisterMaskSDNode
argument_list|(
specifier|const
name|uint32_t
operator|*
name|mask
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|RegisterMask
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Untyped
argument_list|)
argument_list|)
block|,
name|RegMask
argument_list|(
argument|mask
argument_list|)
block|{}
name|public
operator|:
specifier|const
name|uint32_t
operator|*
name|getRegMask
argument_list|()
specifier|const
block|{
return|return
name|RegMask
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|RegisterMask
return|;
block|}
expr|}
block|;
name|class
name|BlockAddressSDNode
operator|:
name|public
name|SDNode
block|{
specifier|const
name|BlockAddress
operator|*
name|BA
block|;
name|int64_t
name|Offset
block|;
name|unsigned
name|char
name|TargetFlags
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|BlockAddressSDNode
argument_list|(
argument|unsigned NodeTy
argument_list|,
argument|EVT VT
argument_list|,
argument|const BlockAddress *ba
argument_list|,
argument|int64_t o
argument_list|,
argument|unsigned char Flags
argument_list|)
operator|:
name|SDNode
argument_list|(
name|NodeTy
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|BA
argument_list|(
name|ba
argument_list|)
block|,
name|Offset
argument_list|(
name|o
argument_list|)
block|,
name|TargetFlags
argument_list|(
argument|Flags
argument_list|)
block|{   }
name|public
operator|:
specifier|const
name|BlockAddress
operator|*
name|getBlockAddress
argument_list|()
specifier|const
block|{
return|return
name|BA
return|;
block|}
name|int64_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|unsigned
name|char
name|getTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|TargetFlags
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|BlockAddress
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetBlockAddress
return|;
block|}
expr|}
block|;
name|class
name|EHLabelSDNode
operator|:
name|public
name|SDNode
block|{
name|SDUse
name|Chain
block|;
name|MCSymbol
operator|*
name|Label
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|EHLabelSDNode
argument_list|(
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDValue ch
argument_list|,
argument|MCSymbol *L
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|EH_LABEL
argument_list|,
name|Order
argument_list|,
name|dl
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|Label
argument_list|(
argument|L
argument_list|)
block|{
name|InitOperands
argument_list|(
operator|&
name|Chain
argument_list|,
name|ch
argument_list|)
block|;   }
name|public
operator|:
name|MCSymbol
operator|*
name|getLabel
argument_list|()
specifier|const
block|{
return|return
name|Label
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|EH_LABEL
return|;
block|}
expr|}
block|;
name|class
name|ExternalSymbolSDNode
operator|:
name|public
name|SDNode
block|{
specifier|const
name|char
operator|*
name|Symbol
block|;
name|unsigned
name|char
name|TargetFlags
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|ExternalSymbolSDNode
argument_list|(
argument|bool isTarget
argument_list|,
argument|const char *Sym
argument_list|,
argument|unsigned char TF
argument_list|,
argument|EVT VT
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarget
condition|?
name|ISD
operator|::
name|TargetExternalSymbol
else|:
name|ISD
operator|::
name|ExternalSymbol
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Symbol
argument_list|(
name|Sym
argument_list|)
block|,
name|TargetFlags
argument_list|(
argument|TF
argument_list|)
block|{   }
name|public
operator|:
specifier|const
name|char
operator|*
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
name|Symbol
return|;
block|}
name|unsigned
name|char
name|getTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|TargetFlags
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ExternalSymbol
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetExternalSymbol
return|;
block|}
expr|}
block|;
name|class
name|CondCodeSDNode
operator|:
name|public
name|SDNode
block|{
name|ISD
operator|::
name|CondCode
name|Condition
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|explicit
name|CondCodeSDNode
argument_list|(
argument|ISD::CondCode Cond
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|CONDCODE
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|Condition
argument_list|(
argument|Cond
argument_list|)
block|{   }
name|public
operator|:
name|ISD
operator|::
name|CondCode
name|get
argument_list|()
specifier|const
block|{
return|return
name|Condition
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|CONDCODE
return|;
block|}
expr|}
block|;
comment|/// CvtRndSatSDNode - NOTE: avoid using this node as this may disappear in the
comment|/// future and most targets don't support it.
name|class
name|CvtRndSatSDNode
operator|:
name|public
name|SDNode
block|{
name|ISD
operator|::
name|CvtCode
name|CvtCode
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|explicit
name|CvtRndSatSDNode
argument_list|(
argument|EVT VT
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|const SDValue *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|ISD::CvtCode Code
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|CONVERT_RNDSAT
argument_list|,
name|Order
argument_list|,
name|dl
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|,
name|Ops
argument_list|,
name|NumOps
argument_list|)
block|,
name|CvtCode
argument_list|(
argument|Code
argument_list|)
block|{
name|assert
argument_list|(
name|NumOps
operator|==
literal|5
operator|&&
literal|"wrong number of operations"
argument_list|)
block|;   }
name|public
operator|:
name|ISD
operator|::
name|CvtCode
name|getCvtCode
argument_list|()
specifier|const
block|{
return|return
name|CvtCode
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|CONVERT_RNDSAT
return|;
block|}
expr|}
block|;
comment|/// VTSDNode - This class is used to represent EVT's, which are used
comment|/// to parameterize some operations.
name|class
name|VTSDNode
operator|:
name|public
name|SDNode
block|{
name|EVT
name|ValueType
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|explicit
name|VTSDNode
argument_list|(
argument|EVT VT
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|VALUETYPE
argument_list|,
literal|0
argument_list|,
name|DebugLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|ValueType
argument_list|(
argument|VT
argument_list|)
block|{   }
name|public
operator|:
name|EVT
name|getVT
argument_list|()
specifier|const
block|{
return|return
name|ValueType
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|VALUETYPE
return|;
block|}
expr|}
block|;
comment|/// LSBaseSDNode - Base class for LoadSDNode and StoreSDNode
comment|///
name|class
name|LSBaseSDNode
operator|:
name|public
name|MemSDNode
block|{
comment|//! Operand array for load and store
comment|/*!     \note Moving this array to the base class captures more     common functionality shared between LoadSDNode and     StoreSDNode    */
name|SDUse
name|Ops
index|[
literal|4
index|]
block|;
name|public
operator|:
name|LSBaseSDNode
argument_list|(
argument|ISD::NodeType NodeTy
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDValue *Operands
argument_list|,
argument|unsigned numOperands
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|ISD::MemIndexedMode AM
argument_list|,
argument|EVT MemVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
operator|:
name|MemSDNode
argument_list|(
argument|NodeTy
argument_list|,
argument|Order
argument_list|,
argument|dl
argument_list|,
argument|VTs
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|SubclassData
operator||=
name|AM
operator|<<
literal|2
block|;
name|assert
argument_list|(
name|getAddressingMode
argument_list|()
operator|==
name|AM
operator|&&
literal|"MemIndexedMode encoding error!"
argument_list|)
block|;
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|Operands
argument_list|,
name|numOperands
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|getOffset
argument_list|()
operator|.
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|UNDEF
operator|||
name|isIndexed
argument_list|()
operator|)
operator|&&
literal|"Only indexed loads and stores have a non-undef offset operand"
argument_list|)
block|;   }
specifier|const
name|SDValue
operator|&
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|LOAD
condition|?
literal|2
else|:
literal|3
argument_list|)
return|;
block|}
comment|/// getAddressingMode - Return the addressing mode for this load or store:
comment|/// unindexed, pre-inc, pre-dec, post-inc, or post-dec.
name|ISD
operator|::
name|MemIndexedMode
name|getAddressingMode
argument_list|()
specifier|const
block|{
return|return
name|ISD
operator|::
name|MemIndexedMode
argument_list|(
operator|(
name|SubclassData
operator|>>
literal|2
operator|)
operator|&
literal|7
argument_list|)
return|;
block|}
comment|/// isIndexed - Return true if this is a pre/post inc/dec load/store.
name|bool
name|isIndexed
argument_list|()
specifier|const
block|{
return|return
name|getAddressingMode
argument_list|()
operator|!=
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
comment|/// isUnindexed - Return true if this is NOT a pre/post inc/dec load/store.
name|bool
name|isUnindexed
argument_list|()
specifier|const
block|{
return|return
name|getAddressingMode
argument_list|()
operator|==
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|LOAD
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|STORE
return|;
block|}
expr|}
block|;
comment|/// LoadSDNode - This class is used to represent ISD::LOAD nodes.
comment|///
name|class
name|LoadSDNode
operator|:
name|public
name|LSBaseSDNode
block|{
name|friend
name|class
name|SelectionDAG
block|;
name|LoadSDNode
argument_list|(
argument|SDValue *ChainPtrOff
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|ISD::MemIndexedMode AM
argument_list|,
argument|ISD::LoadExtType ETy
argument_list|,
argument|EVT MemVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
operator|:
name|LSBaseSDNode
argument_list|(
argument|ISD::LOAD
argument_list|,
argument|Order
argument_list|,
argument|dl
argument_list|,
argument|ChainPtrOff
argument_list|,
literal|3
argument_list|,
argument|VTs
argument_list|,
argument|AM
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|SubclassData
operator||=
operator|(
name|unsigned
name|short
operator|)
name|ETy
block|;
name|assert
argument_list|(
name|getExtensionType
argument_list|()
operator|==
name|ETy
operator|&&
literal|"LoadExtType encoding error!"
argument_list|)
block|;
name|assert
argument_list|(
name|readMem
argument_list|()
operator|&&
literal|"Load MachineMemOperand is not a load!"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|writeMem
argument_list|()
operator|&&
literal|"Load MachineMemOperand is a store!"
argument_list|)
block|;   }
name|public
operator|:
comment|/// getExtensionType - Return whether this is a plain node,
comment|/// or one of the varieties of value-extending loads.
name|ISD
operator|::
name|LoadExtType
name|getExtensionType
argument_list|()
specifier|const
block|{
return|return
name|ISD
operator|::
name|LoadExtType
argument_list|(
name|SubclassData
operator|&
literal|3
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getBasePtr
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|2
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|LOAD
return|;
block|}
expr|}
block|;
comment|/// StoreSDNode - This class is used to represent ISD::STORE nodes.
comment|///
name|class
name|StoreSDNode
operator|:
name|public
name|LSBaseSDNode
block|{
name|friend
name|class
name|SelectionDAG
block|;
name|StoreSDNode
argument_list|(
argument|SDValue *ChainValuePtrOff
argument_list|,
argument|unsigned Order
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|ISD::MemIndexedMode AM
argument_list|,
argument|bool isTrunc
argument_list|,
argument|EVT MemVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
operator|:
name|LSBaseSDNode
argument_list|(
argument|ISD::STORE
argument_list|,
argument|Order
argument_list|,
argument|dl
argument_list|,
argument|ChainValuePtrOff
argument_list|,
literal|4
argument_list|,
argument|VTs
argument_list|,
argument|AM
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|SubclassData
operator||=
operator|(
name|unsigned
name|short
operator|)
name|isTrunc
block|;
name|assert
argument_list|(
name|isTruncatingStore
argument_list|()
operator|==
name|isTrunc
operator|&&
literal|"isTrunc encoding error!"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|readMem
argument_list|()
operator|&&
literal|"Store MachineMemOperand is a load!"
argument_list|)
block|;
name|assert
argument_list|(
name|writeMem
argument_list|()
operator|&&
literal|"Store MachineMemOperand is not a store!"
argument_list|)
block|;   }
name|public
operator|:
comment|/// isTruncatingStore - Return true if the op does a truncation before store.
comment|/// For integers this is the same as doing a TRUNCATE and storing the result.
comment|/// For floats, it is the same as doing an FP_ROUND and storing the result.
name|bool
name|isTruncatingStore
argument_list|()
specifier|const
block|{
return|return
name|SubclassData
operator|&
literal|1
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getBasePtr
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|2
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|3
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|STORE
return|;
block|}
expr|}
block|;
comment|/// MachineSDNode - An SDNode that represents everything that will be needed
comment|/// to construct a MachineInstr. These nodes are created during the
comment|/// instruction selection proper phase.
comment|///
name|class
name|MachineSDNode
operator|:
name|public
name|SDNode
block|{
name|public
operator|:
typedef|typedef
name|MachineMemOperand
modifier|*
modifier|*
name|mmo_iterator
typedef|;
name|private
operator|:
name|friend
name|class
name|SelectionDAG
block|;
name|MachineSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Order
argument_list|,
argument|const DebugLoc DL
argument_list|,
argument|SDVTList VTs
argument_list|)
operator|:
name|SDNode
argument_list|(
name|Opc
argument_list|,
name|Order
argument_list|,
name|DL
argument_list|,
name|VTs
argument_list|)
block|,
name|MemRefs
argument_list|(
literal|0
argument_list|)
block|,
name|MemRefsEnd
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// LocalOperands - Operands for this instruction, if they fit here. If
comment|/// they don't, this field is unused.
name|SDUse
name|LocalOperands
index|[
literal|4
index|]
block|;
comment|/// MemRefs - Memory reference descriptions for this instruction.
name|mmo_iterator
name|MemRefs
block|;
name|mmo_iterator
name|MemRefsEnd
block|;
name|public
operator|:
name|mmo_iterator
name|memoperands_begin
argument_list|()
specifier|const
block|{
return|return
name|MemRefs
return|;
block|}
name|mmo_iterator
name|memoperands_end
argument_list|()
specifier|const
block|{
return|return
name|MemRefsEnd
return|;
block|}
name|bool
name|memoperands_empty
argument_list|()
specifier|const
block|{
return|return
name|MemRefsEnd
operator|==
name|MemRefs
return|;
block|}
comment|/// setMemRefs - Assign this MachineSDNodes's memory reference descriptor
comment|/// list. This does not transfer ownership.
name|void
name|setMemRefs
argument_list|(
argument|mmo_iterator NewMemRefs
argument_list|,
argument|mmo_iterator NewMemRefsEnd
argument_list|)
block|{
for|for
control|(
name|mmo_iterator
name|MMI
init|=
name|NewMemRefs
init|,
name|MME
init|=
name|NewMemRefsEnd
init|;
name|MMI
operator|!=
name|MME
condition|;
operator|++
name|MMI
control|)
name|assert
argument_list|(
operator|*
name|MMI
operator|&&
literal|"Null mem ref detected!"
argument_list|)
expr_stmt|;
name|MemRefs
operator|=
name|NewMemRefs
block|;
name|MemRefsEnd
operator|=
name|NewMemRefsEnd
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|isMachineOpcode
argument_list|()
return|;
block|}
expr|}
block|;
name|class
name|SDNodeIterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
block|,
name|SDNode
block|,
name|ptrdiff_t
operator|>
block|{
specifier|const
name|SDNode
operator|*
name|Node
block|;
name|unsigned
name|Operand
block|;
name|SDNodeIterator
argument_list|(
argument|const SDNode *N
argument_list|,
argument|unsigned Op
argument_list|)
operator|:
name|Node
argument_list|(
name|N
argument_list|)
block|,
name|Operand
argument_list|(
argument|Op
argument_list|)
block|{}
name|public
operator|:
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SDNodeIterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|Operand
operator|==
name|x
operator|.
name|Operand
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SDNodeIterator
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
specifier|const
name|SDNodeIterator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SDNodeIterator
operator|&
name|I
operator|)
block|{
name|assert
argument_list|(
name|I
operator|.
name|Node
operator|==
name|Node
operator|&&
literal|"Cannot assign iterators to two different nodes!"
argument_list|)
block|;
name|Operand
operator|=
name|I
operator|.
name|Operand
block|;
return|return
operator|*
name|this
return|;
block|}
name|pointer
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Node
operator|->
name|getOperand
argument_list|(
name|Operand
argument_list|)
operator|.
name|getNode
argument_list|()
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
name|operator
operator|*
operator|(
operator|)
return|;
block|}
name|SDNodeIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
operator|++
name|Operand
block|;
return|return
operator|*
name|this
return|;
block|}
name|SDNodeIterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|SDNodeIterator
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
name|size_t
name|operator
operator|-
operator|(
name|SDNodeIterator
name|Other
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Node
operator|==
name|Other
operator|.
name|Node
operator|&&
literal|"Cannot compare iterators of two different nodes!"
argument_list|)
block|;
return|return
name|Operand
operator|-
name|Other
operator|.
name|Operand
return|;
block|}
specifier|static
name|SDNodeIterator
name|begin
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|SDNodeIterator
argument_list|(
name|N
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|SDNodeIterator
name|end
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|SDNodeIterator
argument_list|(
name|N
argument_list|,
name|N
operator|->
name|getNumOperands
argument_list|()
argument_list|)
return|;
block|}
name|unsigned
name|getOperand
argument_list|()
specifier|const
block|{
return|return
name|Operand
return|;
block|}
specifier|const
name|SDNode
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|Node
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|SDNode
operator|*
operator|>
block|{
typedef|typedef
name|SDNode
name|NodeType
typedef|;
typedef|typedef
name|SDNodeIterator
name|ChildIteratorType
typedef|;
specifier|static
specifier|inline
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|SDNode *N
argument_list|)
block|{
return|return
name|N
return|;
block|}
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
argument_list|(
argument|NodeType *N
argument_list|)
block|{
return|return
name|SDNodeIterator
operator|::
name|begin
argument_list|(
name|N
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
argument_list|(
argument|NodeType *N
argument_list|)
block|{
return|return
name|SDNodeIterator
operator|::
name|end
argument_list|(
name|N
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// LargestSDNode - The largest SDNode class.
comment|///
typedef|typedef
name|AtomicSDNode
name|LargestSDNode
typedef|;
comment|/// MostAlignedSDNode - The SDNode class with the greatest alignment
comment|/// requirement.
comment|///
typedef|typedef
name|GlobalAddressSDNode
name|MostAlignedSDNode
typedef|;
name|namespace
name|ISD
block|{
comment|/// isNormalLoad - Returns true if the specified node is a non-extending
comment|/// and unindexed load.
specifier|inline
name|bool
name|isNormalLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
specifier|const
name|LoadSDNode
operator|*
name|Ld
operator|=
name|dyn_cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
block|;
return|return
name|Ld
operator|&&
name|Ld
operator|->
name|getExtensionType
argument_list|()
operator|==
name|ISD
operator|::
name|NON_EXTLOAD
operator|&&
name|Ld
operator|->
name|getAddressingMode
argument_list|()
operator|==
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
comment|/// isNON_EXTLoad - Returns true if the specified node is a non-extending
comment|/// load.
specifier|inline
name|bool
name|isNON_EXTLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getExtensionType
argument_list|()
operator|==
name|ISD
operator|::
name|NON_EXTLOAD
return|;
block|}
comment|/// isEXTLoad - Returns true if the specified node is a EXTLOAD.
comment|///
specifier|inline
name|bool
name|isEXTLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getExtensionType
argument_list|()
operator|==
name|ISD
operator|::
name|EXTLOAD
return|;
block|}
comment|/// isSEXTLoad - Returns true if the specified node is a SEXTLOAD.
comment|///
specifier|inline
name|bool
name|isSEXTLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getExtensionType
argument_list|()
operator|==
name|ISD
operator|::
name|SEXTLOAD
return|;
block|}
comment|/// isZEXTLoad - Returns true if the specified node is a ZEXTLOAD.
comment|///
specifier|inline
name|bool
name|isZEXTLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getExtensionType
argument_list|()
operator|==
name|ISD
operator|::
name|ZEXTLOAD
return|;
block|}
comment|/// isUNINDEXEDLoad - Returns true if the specified node is an unindexed load.
comment|///
specifier|inline
name|bool
name|isUNINDEXEDLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getAddressingMode
argument_list|()
operator|==
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
comment|/// isNormalStore - Returns true if the specified node is a non-truncating
comment|/// and unindexed store.
specifier|inline
name|bool
name|isNormalStore
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
specifier|const
name|StoreSDNode
operator|*
name|St
operator|=
name|dyn_cast
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
block|;
return|return
name|St
operator|&&
operator|!
name|St
operator|->
name|isTruncatingStore
argument_list|()
operator|&&
name|St
operator|->
name|getAddressingMode
argument_list|()
operator|==
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
comment|/// isNON_TRUNCStore - Returns true if the specified node is a non-truncating
comment|/// store.
specifier|inline
name|bool
name|isNON_TRUNCStore
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
operator|!
name|cast
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|isTruncatingStore
argument_list|()
return|;
block|}
comment|/// isTRUNCStore - Returns true if the specified node is a truncating
comment|/// store.
specifier|inline
name|bool
name|isTRUNCStore
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|isTruncatingStore
argument_list|()
return|;
block|}
comment|/// isUNINDEXEDStore - Returns true if the specified node is an
comment|/// unindexed store.
specifier|inline
name|bool
name|isUNINDEXEDStore
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getAddressingMode
argument_list|()
operator|==
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
expr|}  }
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

