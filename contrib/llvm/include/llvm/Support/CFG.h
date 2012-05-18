begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/CFG.h - Process LLVM structures as graphs --*- C++ -*-===//
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
comment|// This file defines specializations of GraphTraits that allow Function and
end_comment

begin_comment
comment|// BasicBlock graphs to be treated as proper graphs for generic algorithms.
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
name|LLVM_SUPPORT_CFG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_CFG_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/InstrTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|// BasicBlock pred_iterator definition
comment|//===----------------------------------------------------------------------===//
name|template
operator|<
name|class
name|Ptr
operator|,
name|class
name|USE_iterator
operator|>
comment|// Predecessor Iterator
name|class
name|PredIterator
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
name|Ptr
operator|,
name|ptrdiff_t
operator|>
block|{
typedef|typedef
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|Ptr
operator|,
name|ptrdiff_t
operator|>
name|super
expr_stmt|;
typedef|typedef
name|PredIterator
operator|<
name|Ptr
operator|,
name|USE_iterator
operator|>
name|Self
expr_stmt|;
name|USE_iterator
name|It
decl_stmt|;
specifier|inline
name|void
name|advancePastNonTerminators
parameter_list|()
block|{
comment|// Loop to ignore non terminator uses (for example BlockAddresses).
while|while
condition|(
operator|!
name|It
operator|.
name|atEnd
argument_list|()
operator|&&
operator|!
name|isa
operator|<
name|TerminatorInst
operator|>
operator|(
operator|*
name|It
operator|)
condition|)
operator|++
name|It
expr_stmt|;
block|}
name|public
label|:
typedef|typedef
name|typename
name|super
operator|::
name|pointer
name|pointer
expr_stmt|;
name|PredIterator
argument_list|()
block|{}
name|explicit
specifier|inline
name|PredIterator
argument_list|(
name|Ptr
operator|*
name|bb
argument_list|)
operator|:
name|It
argument_list|(
argument|bb->use_begin()
argument_list|)
block|{
name|advancePastNonTerminators
argument_list|()
block|;   }
specifier|inline
name|PredIterator
argument_list|(
name|Ptr
operator|*
name|bb
argument_list|,
name|bool
argument_list|)
operator|:
name|It
argument_list|(
argument|bb->use_end()
argument_list|)
block|{}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|It
operator|==
name|x
operator|.
name|It
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Self
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
specifier|inline
name|pointer
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|It
operator|.
name|atEnd
argument_list|()
operator|&&
literal|"pred_iterator out of range!"
argument_list|)
block|;
return|return
name|cast
operator|<
name|TerminatorInst
operator|>
operator|(
operator|*
name|It
operator|)
operator|->
name|getParent
argument_list|()
return|;
block|}
specifier|inline
name|pointer
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|operator
operator|*
operator|(
operator|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|inline
name|Self
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|assert
argument_list|(
operator|!
name|It
operator|.
name|atEnd
argument_list|()
operator|&&
literal|"pred_iterator out of range!"
argument_list|)
block|;
operator|++
name|It
block|;
name|advancePastNonTerminators
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|Self
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|Self
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
end_expr_stmt

begin_comment
comment|/// getOperandNo - Return the operand number in the predecessor's
end_comment

begin_comment
comment|/// terminator of the successor.
end_comment

begin_expr_stmt
name|unsigned
name|getOperandNo
argument_list|()
specifier|const
block|{
return|return
name|It
operator|.
name|getOperandNo
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getUse - Return the operand Use in the predecessor's terminator
end_comment

begin_comment
comment|/// of the successor.
end_comment

begin_expr_stmt
name|Use
operator|&
name|getUse
argument_list|()
specifier|const
block|{
return|return
name|It
operator|.
name|getUse
argument_list|()
return|;
block|}
end_expr_stmt

begin_typedef
unit|};
typedef|typedef
name|PredIterator
operator|<
name|BasicBlock
operator|,
name|Value
operator|::
name|use_iterator
operator|>
name|pred_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|PredIterator
operator|<
specifier|const
name|BasicBlock
operator|,
name|Value
operator|::
name|const_use_iterator
operator|>
name|const_pred_iterator
expr_stmt|;
end_typedef

begin_function
specifier|inline
name|pred_iterator
name|pred_begin
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|pred_iterator
argument_list|(
name|BB
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|const_pred_iterator
name|pred_begin
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|const_pred_iterator
argument_list|(
name|BB
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|pred_iterator
name|pred_end
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|pred_iterator
argument_list|(
name|BB
argument_list|,
name|true
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|const_pred_iterator
name|pred_end
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|const_pred_iterator
argument_list|(
name|BB
argument_list|,
name|true
argument_list|)
return|;
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// BasicBlock succ_iterator definition
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Term_
operator|,
name|class
name|BB_
operator|>
comment|// Successor Iterator
name|class
name|SuccIterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|bidirectional_iterator_tag
operator|,
name|BB_
operator|,
name|ptrdiff_t
operator|>
block|{
specifier|const
name|Term_
name|Term
block|;
name|unsigned
name|idx
block|;
typedef|typedef
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|bidirectional_iterator_tag
operator|,
name|BB_
operator|,
name|ptrdiff_t
operator|>
name|super
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|SuccIterator
operator|<
name|Term_
operator|,
name|BB_
operator|>
name|Self
expr_stmt|;
end_typedef

begin_function
specifier|inline
name|bool
name|index_is_valid
parameter_list|(
name|int
name|idx
parameter_list|)
block|{
return|return
name|idx
operator|>=
literal|0
operator|&&
operator|(
name|unsigned
operator|)
name|idx
operator|<
name|Term
operator|->
name|getNumSuccessors
argument_list|()
return|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|typename
name|super
operator|::
name|pointer
name|pointer
expr_stmt|;
end_typedef

begin_comment
comment|// TODO: This can be random access iterator, only operator[] missing.
end_comment

begin_macro
name|explicit
end_macro

begin_expr_stmt
specifier|inline
name|SuccIterator
argument_list|(
argument|Term_ T
argument_list|)
operator|:
name|Term
argument_list|(
name|T
argument_list|)
operator|,
name|idx
argument_list|(
literal|0
argument_list|)
block|{
comment|// begin iterator
block|}
specifier|inline
name|SuccIterator
argument_list|(
argument|Term_ T
argument_list|,
argument|bool
argument_list|)
comment|// end iterator
operator|:
name|Term
argument_list|(
argument|T
argument_list|)
block|{
if|if
condition|(
name|Term
condition|)
name|idx
operator|=
name|Term
operator|->
name|getNumSuccessors
argument_list|()
expr_stmt|;
else|else
comment|// Term == NULL happens, if a basic block is not fully constructed and
comment|// consequently getTerminator() returns NULL. In this case we construct a
comment|// SuccIterator which describes a basic block that has zero successors.
comment|// Defining SuccIterator for incomplete and malformed CFGs is especially
comment|// useful for debugging.
name|idx
operator|=
literal|0
expr_stmt|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|inline
specifier|const
name|Self
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Self
operator|&
name|I
operator|)
block|{
name|assert
argument_list|(
name|Term
operator|==
name|I
operator|.
name|Term
operator|&&
literal|"Cannot assign iterators to two different blocks!"
argument_list|)
block|;
name|idx
operator|=
name|I
operator|.
name|idx
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getSuccessorIndex - This is used to interface between code that wants to
end_comment

begin_comment
comment|/// operate on terminator instructions directly.
end_comment

begin_expr_stmt
name|unsigned
name|getSuccessorIndex
argument_list|()
specifier|const
block|{
return|return
name|idx
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|idx
operator|==
name|x
operator|.
name|idx
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Self
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
end_expr_stmt

begin_expr_stmt
specifier|inline
name|pointer
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Term
operator|->
name|getSuccessor
argument_list|(
name|idx
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|operator
operator|*
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|Self
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|idx
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|// Preincrement
end_comment

begin_expr_stmt
specifier|inline
name|Self
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|Self
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
end_expr_stmt

begin_expr_stmt
specifier|inline
name|Self
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
operator|--
name|idx
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|// Predecrement
end_comment

begin_expr_stmt
specifier|inline
name|Self
name|operator
operator|--
operator|(
name|int
operator|)
block|{
comment|// Postdecrement
name|Self
name|tmp
operator|=
operator|*
name|this
block|;
operator|--
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Term
operator|==
name|x
operator|.
name|Term
operator|&&
literal|"Cannot compare iterators of different blocks!"
argument_list|)
block|;
return|return
name|idx
operator|<
name|x
operator|.
name|idx
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Term
operator|==
name|x
operator|.
name|Term
operator|&&
literal|"Cannot compare iterators of different blocks!"
argument_list|)
block|;
return|return
name|idx
operator|<=
name|x
operator|.
name|idx
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Term
operator|==
name|x
operator|.
name|Term
operator|&&
literal|"Cannot compare iterators of different blocks!"
argument_list|)
block|;
return|return
name|idx
operator|>=
name|x
operator|.
name|idx
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Term
operator|==
name|x
operator|.
name|Term
operator|&&
literal|"Cannot compare iterators of different blocks!"
argument_list|)
block|;
return|return
name|idx
operator|>
name|x
operator|.
name|idx
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|Self
operator|&
name|operator
operator|+=
operator|(
name|int
name|Right
operator|)
block|{
name|unsigned
name|new_idx
operator|=
name|idx
operator|+
name|Right
block|;
name|assert
argument_list|(
name|index_is_valid
argument_list|(
name|new_idx
argument_list|)
operator|&&
literal|"Iterator index out of bound"
argument_list|)
block|;
name|idx
operator|=
name|new_idx
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|Self
name|operator
operator|+
operator|(
name|int
name|Right
operator|)
block|{
name|Self
name|tmp
operator|=
operator|*
name|this
block|;
name|tmp
operator|+=
name|Right
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|Self
operator|&
name|operator
operator|-=
operator|(
name|int
name|Right
operator|)
block|{
return|return
name|operator
operator|+=
operator|(
operator|-
name|Right
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|Self
name|operator
operator|-
operator|(
name|int
name|Right
operator|)
block|{
return|return
name|operator
operator|+
operator|(
operator|-
name|Right
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|operator
operator|-
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
block|{
name|assert
argument_list|(
name|Term
operator|==
name|x
operator|.
name|Term
operator|&&
literal|"Cannot work on iterators of different blocks!"
argument_list|)
block|;
name|int
name|distance
operator|=
name|idx
operator|-
name|x
operator|.
name|idx
block|;
return|return
name|distance
return|;
block|}
end_expr_stmt

begin_comment
comment|// This works for read access, however write access is difficult as changes
end_comment

begin_comment
comment|// to Term are only possible with Term->setSuccessor(idx). Pointers that can
end_comment

begin_comment
comment|// be modified are not available.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// inline pointer operator[](int offset) {
end_comment

begin_comment
comment|//  Self tmp = *this;
end_comment

begin_comment
comment|//  tmp += offset;
end_comment

begin_comment
comment|//  return tmp.operator*();
end_comment

begin_comment
comment|// }
end_comment

begin_comment
comment|/// Get the source BB of this iterator.
end_comment

begin_function
specifier|inline
name|BB_
modifier|*
name|getSource
parameter_list|()
block|{
name|assert
argument_list|(
name|Term
operator|&&
literal|"Source not available, if basic block was malformed"
argument_list|)
expr_stmt|;
return|return
name|Term
operator|->
name|getParent
argument_list|()
return|;
block|}
end_function

begin_typedef
unit|};
typedef|typedef
name|SuccIterator
operator|<
name|TerminatorInst
operator|*
operator|,
name|BasicBlock
operator|>
name|succ_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|SuccIterator
operator|<
specifier|const
name|TerminatorInst
operator|*
operator|,
specifier|const
name|BasicBlock
operator|>
name|succ_const_iterator
expr_stmt|;
end_typedef

begin_function
specifier|inline
name|succ_iterator
name|succ_begin
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|succ_iterator
argument_list|(
name|BB
operator|->
name|getTerminator
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|succ_const_iterator
name|succ_begin
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|succ_const_iterator
argument_list|(
name|BB
operator|->
name|getTerminator
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|succ_iterator
name|succ_end
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|succ_iterator
argument_list|(
name|BB
operator|->
name|getTerminator
argument_list|()
argument_list|,
name|true
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|succ_const_iterator
name|succ_end
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|succ_const_iterator
argument_list|(
name|BB
operator|->
name|getTerminator
argument_list|()
argument_list|,
name|true
argument_list|)
return|;
block|}
end_function

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// GraphTraits specializations for basic block graphs (CFGs)
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Provide specializations of GraphTraits to be able to treat a function as a
end_comment

begin_comment
comment|// graph of basic blocks...
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|BasicBlock
operator|*
operator|>
block|{
typedef|typedef
name|BasicBlock
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|succ_iterator
name|ChildIteratorType
typedef|;
end_typedef

begin_function
specifier|static
name|NodeType
modifier|*
name|getEntryNode
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|BB
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|succ_begin
argument_list|(
name|N
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|succ_end
argument_list|(
name|N
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
block|{
typedef|typedef
specifier|const
name|BasicBlock
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|succ_const_iterator
name|ChildIteratorType
typedef|;
end_typedef

begin_function
specifier|static
name|NodeType
modifier|*
name|getEntryNode
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|BB
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|succ_begin
argument_list|(
name|N
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|succ_end
argument_list|(
name|N
argument_list|)
return|;
block|}
end_function

begin_comment
unit|};
comment|// Provide specializations of GraphTraits to be able to treat a function as a
end_comment

begin_comment
comment|// graph of basic blocks... and to walk it in inverse order.  Inverse order for
end_comment

begin_comment
comment|// a function is considered to be when traversing the predecessor edges of a BB
end_comment

begin_comment
comment|// instead of the successor edges.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Inverse
operator|<
name|BasicBlock
operator|*
operator|>
expr|>
block|{
typedef|typedef
name|BasicBlock
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|pred_iterator
name|ChildIteratorType
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|NodeType
modifier|*
name|getEntryNode
argument_list|(
name|Inverse
operator|<
name|BasicBlock
operator|*
operator|>
name|G
argument_list|)
block|{
return|return
name|G
operator|.
name|Graph
return|;
block|}
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|pred_begin
argument_list|(
name|N
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|pred_end
argument_list|(
name|N
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Inverse
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
expr|>
block|{
typedef|typedef
specifier|const
name|BasicBlock
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|const_pred_iterator
name|ChildIteratorType
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|NodeType
modifier|*
name|getEntryNode
argument_list|(
name|Inverse
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
name|G
argument_list|)
block|{
return|return
name|G
operator|.
name|Graph
return|;
block|}
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|pred_begin
argument_list|(
name|N
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|pred_end
argument_list|(
name|N
argument_list|)
return|;
block|}
end_function

begin_comment
unit|};
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// GraphTraits specializations for function basic block graphs (CFGs)
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Provide specializations of GraphTraits to be able to treat a function as a
end_comment

begin_comment
comment|// graph of basic blocks... these are the same as the basic block iterators,
end_comment

begin_comment
comment|// except that the root node is implicitly the first node of the function.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Function
operator|*
operator|>
operator|:
name|public
name|GraphTraits
operator|<
name|BasicBlock
operator|*
operator|>
block|{
specifier|static
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|Function *F
argument_list|)
block|{
return|return
operator|&
name|F
operator|->
name|getEntryBlock
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// nodes_iterator/begin/end - Allow iteration over all nodes in the graph
end_comment

begin_typedef
typedef|typedef
name|Function
operator|::
name|iterator
name|nodes_iterator
expr_stmt|;
end_typedef

begin_function
specifier|static
name|nodes_iterator
name|nodes_begin
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|nodes_iterator
name|nodes_end
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|end
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|size
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|size
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
specifier|const
name|Function
operator|*
operator|>
operator|:
name|public
name|GraphTraits
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
block|{
specifier|static
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|const Function *F
argument_list|)
block|{
return|return
operator|&
name|F
operator|->
name|getEntryBlock
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// nodes_iterator/begin/end - Allow iteration over all nodes in the graph
end_comment

begin_typedef
typedef|typedef
name|Function
operator|::
name|const_iterator
name|nodes_iterator
expr_stmt|;
end_typedef

begin_function
specifier|static
name|nodes_iterator
name|nodes_begin
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|nodes_iterator
name|nodes_end
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|end
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|size
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|size
argument_list|()
return|;
block|}
end_function

begin_comment
unit|};
comment|// Provide specializations of GraphTraits to be able to treat a function as a
end_comment

begin_comment
comment|// graph of basic blocks... and to walk it in inverse order.  Inverse order for
end_comment

begin_comment
comment|// a function is considered to be when traversing the predecessor edges of a BB
end_comment

begin_comment
comment|// instead of the successor edges.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Inverse
operator|<
name|Function
operator|*
operator|>
expr|>
operator|:
name|public
name|GraphTraits
operator|<
name|Inverse
operator|<
name|BasicBlock
operator|*
operator|>
expr|>
block|{
specifier|static
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|Inverse<Function*> G
argument_list|)
block|{
return|return
operator|&
name|G
operator|.
name|Graph
operator|->
name|getEntryBlock
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Inverse
operator|<
specifier|const
name|Function
operator|*
operator|>
expr|>
operator|:
name|public
name|GraphTraits
operator|<
name|Inverse
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
expr|>
block|{
specifier|static
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|Inverse<const Function *> G
argument_list|)
block|{
return|return
operator|&
name|G
operator|.
name|Graph
operator|->
name|getEntryBlock
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

