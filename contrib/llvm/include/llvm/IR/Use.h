begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Use.h - Definition of the Use class ----------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This defines the Use class.  The Use class represents the operand of an
end_comment

begin_comment
comment|/// instruction or some other User instance which refers to a Value.  The Use
end_comment

begin_comment
comment|/// class keeps the "use list" of the referenced value up to date.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Pointer tagging is used to efficiently find the User corresponding to a Use
end_comment

begin_comment
comment|/// without having to store a User pointer in every Use. A User is preceded in
end_comment

begin_comment
comment|/// memory by all the Uses corresponding to its operands, and the low bits of
end_comment

begin_comment
comment|/// one of the fields (Prev) of the Use class are used to encode offsets to be
end_comment

begin_comment
comment|/// able to find that User given a pointer to any Use. For details, see:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   http://www.llvm.org/docs/ProgrammersManual.html#UserLayout
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_IR_USE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_USE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Types.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|User
decl_stmt|;
name|class
name|Use
decl_stmt|;
name|template
operator|<
name|typename
operator|>
expr|struct
name|simplify_type
expr_stmt|;
comment|/// \brief A Use represents the edge between a Value definition and its users.
comment|///
comment|/// This is notionally a two-dimensional linked list. It supports traversing
comment|/// all of the uses for a particular value definition. It also supports jumping
comment|/// directly to the used value when we arrive from the User's operands, and
comment|/// jumping directly to the User when we arrive from the Value's uses.
comment|///
comment|/// The pointer to the used Value is explicit, and the pointer to the User is
comment|/// implicit. The implicit pointer is found via a waymarking algorithm
comment|/// described in the programmer's manual:
comment|///
comment|///   http://www.llvm.org/docs/ProgrammersManual.html#the-waymarking-algorithm
comment|///
comment|/// This is essentially the single most memory intensive object in LLVM because
comment|/// of the number of uses in the system. At the same time, the constant time
comment|/// operations it allows are essential to many optimizations having reasonable
comment|/// time complexity.
name|class
name|Use
block|{
name|public
label|:
name|Use
argument_list|(
specifier|const
name|Use
operator|&
name|U
argument_list|)
operator|=
name|delete
expr_stmt|;
comment|/// \brief Provide a fast substitute to std::swap<Use>
comment|/// that also works with less standard-compliant compilers
name|void
name|swap
parameter_list|(
name|Use
modifier|&
name|RHS
parameter_list|)
function_decl|;
comment|// A type for the word following an array of hung-off Uses in memory, which is
comment|// a pointer back to their User with the bottom bit set.
typedef|typedef
name|PointerIntPair
operator|<
name|User
operator|*
operator|,
literal|1
operator|,
name|unsigned
operator|>
name|UserRef
expr_stmt|;
name|private
label|:
comment|/// Destructor - Only for zap()
operator|~
name|Use
argument_list|()
block|{
if|if
condition|(
name|Val
condition|)
name|removeFromList
argument_list|()
expr_stmt|;
block|}
enum|enum
name|PrevPtrTag
block|{
name|zeroDigitTag
block|,
name|oneDigitTag
block|,
name|stopTag
block|,
name|fullStopTag
block|}
enum|;
comment|/// Constructor
name|Use
argument_list|(
argument|PrevPtrTag tag
argument_list|)
block|:
name|Val
argument_list|(
argument|nullptr
argument_list|)
block|{
name|Prev
operator|.
name|setInt
argument_list|(
name|tag
argument_list|)
expr_stmt|;
block|}
name|public
label|:
name|operator
name|Value
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Val
return|;
block|}
name|Value
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
comment|/// \brief Returns the User that contains this Use.
comment|///
comment|/// For an instruction operand, for example, this will return the
comment|/// instruction.
name|User
operator|*
name|getUser
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
specifier|inline
name|void
name|set
parameter_list|(
name|Value
modifier|*
name|Val
parameter_list|)
function_decl|;
specifier|inline
name|Value
modifier|*
name|operator
init|=
operator|(
name|Value
operator|*
name|RHS
operator|)
decl_stmt|;
specifier|inline
specifier|const
name|Use
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Use
operator|&
name|RHS
operator|)
decl_stmt|;
name|Value
operator|*
name|operator
operator|->
expr|(
block|)
block|{
return|return
name|Val
return|;
block|}
specifier|const
name|Value
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Val
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|Use
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Next
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the operand # of this use in its User.
end_comment

begin_expr_stmt
name|unsigned
name|getOperandNo
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Initializes the waymarking tags on an array of Uses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This sets up the array of Uses such that getUser() can find the User from
end_comment

begin_comment
comment|/// any of those Uses.
end_comment

begin_function_decl
specifier|static
name|Use
modifier|*
name|initTags
parameter_list|(
name|Use
modifier|*
name|Start
parameter_list|,
name|Use
modifier|*
name|Stop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Destroys Use operands when the number of operands of
end_comment

begin_comment
comment|/// a User changes.
end_comment

begin_function_decl
specifier|static
name|void
name|zap
parameter_list|(
name|Use
modifier|*
name|Start
parameter_list|,
specifier|const
name|Use
modifier|*
name|Stop
parameter_list|,
name|bool
name|del
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|Use
operator|*
name|getImpliedUser
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Value
modifier|*
name|Val
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Use
modifier|*
name|Next
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|PointerIntPair
operator|<
name|Use
operator|*
operator|*
operator|,
literal|2
operator|,
name|PrevPtrTag
operator|>
name|Prev
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|setPrev
parameter_list|(
name|Use
modifier|*
modifier|*
name|NewPrev
parameter_list|)
block|{
name|Prev
operator|.
name|setPointer
argument_list|(
name|NewPrev
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|addToList
parameter_list|(
name|Use
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
name|setPrev
argument_list|(
operator|&
name|Next
argument_list|)
expr_stmt|;
name|setPrev
argument_list|(
name|List
argument_list|)
expr_stmt|;
operator|*
name|List
operator|=
name|this
expr_stmt|;
block|}
end_function

begin_function
name|void
name|removeFromList
parameter_list|()
block|{
name|Use
modifier|*
modifier|*
name|StrippedPrev
init|=
name|Prev
operator|.
name|getPointer
argument_list|()
decl_stmt|;
operator|*
name|StrippedPrev
operator|=
name|Next
expr_stmt|;
if|if
condition|(
name|Next
condition|)
name|Next
operator|->
name|setPrev
argument_list|(
name|StrippedPrev
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|Value
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Allow clients to treat uses just like values when using
end_comment

begin_comment
comment|/// casting operators.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|Use
operator|>
block|{
typedef|typedef
name|Value
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|Use&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|get
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
name|Use
operator|>
block|{
typedef|typedef
comment|/*const*/
name|Value
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const Use&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|get
argument_list|()
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
end_comment

begin_macro
name|DEFINE_SIMPLE_CONVERSION_FUNCTIONS
argument_list|(
argument|Use
argument_list|,
argument|LLVMUseRef
argument_list|)
end_macro

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_USE_H
end_comment

end_unit

