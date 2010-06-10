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
comment|//
end_comment

begin_comment
comment|// This defines the Use class.  The Use class represents the operand of an
end_comment

begin_comment
comment|// instruction or some other User instance which refers to a Value.  The Use
end_comment

begin_comment
comment|// class keeps the "use list" of the referenced value up to date.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Pointer tagging is used to efficiently find the User corresponding
end_comment

begin_comment
comment|// to a Use without having to store a User pointer in every Use. A
end_comment

begin_comment
comment|// User is preceded in memory by all the Uses corresponding to its
end_comment

begin_comment
comment|// operands, and the low bits of one of the fields (Prev) of the Use
end_comment

begin_comment
comment|// class are used to encode offsets to be able to find that User given
end_comment

begin_comment
comment|// a pointer to any Use. For details, see:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   http://www.llvm.org/docs/ProgrammersManual.html#UserLayout
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
name|LLVM_USE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_USE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|<iterator>
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
comment|/// Tag - generic tag type for (at least 32 bit) pointers
enum|enum
name|Tag
block|{
name|noTag
block|,
name|tagOne
block|,
name|tagTwo
block|,
name|tagThree
block|}
enum|;
comment|// Use** is only 4-byte aligned.
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|Use
operator|*
operator|*
operator|>
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|Use** P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
name|Use
operator|*
operator|*
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|Use
operator|*
operator|*
operator|>
operator|(
name|P
operator|)
return|;
block|}
expr|enum
block|{
name|NumLowBitsAvailable
operator|=
literal|2
block|}
block|; }
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//                                  Use Class
comment|//===----------------------------------------------------------------------===//
comment|/// Use is here to make keeping the "use" list of a Value up-to-date really
comment|/// easy.
name|class
name|Use
block|{
name|public
label|:
comment|/// swap - provide a fast substitute to std::swap<Use>
comment|/// that also works with less standard-compliant compilers
name|void
name|swap
parameter_list|(
name|Use
modifier|&
name|RHS
parameter_list|)
function_decl|;
name|private
label|:
comment|/// Copy ctor - do not implement
name|Use
argument_list|(
specifier|const
name|Use
operator|&
name|U
argument_list|)
expr_stmt|;
comment|/// Destructor - Only for zap()
specifier|inline
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
comment|/// Default ctor - This leaves the Use completely uninitialized.  The only
comment|/// thing that is valid to do with this use is to call the "init" method.
specifier|inline
name|Use
argument_list|()
block|{}
expr|enum
name|PrevPtrTag
block|{
name|zeroDigitTag
operator|=
name|noTag
block|,
name|oneDigitTag
operator|=
name|tagOne
block|,
name|stopTag
operator|=
name|tagTwo
block|,
name|fullStopTag
operator|=
name|tagThree
block|}
expr_stmt|;
name|public
label|:
comment|/// Normally Use will just implicitly convert to a Value* that it holds.
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
comment|/// If implicit conversion to Value* doesn't work, the get() method returns
comment|/// the Value*.
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
comment|/// getUser - This returns the User that contains this Use.  For an
comment|/// instruction operand, for example, this will return the instruction.
name|User
operator|*
name|getUser
argument_list|()
specifier|const
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
name|Value
modifier|*
name|operator
init|=
operator|(
name|Value
operator|*
name|RHS
operator|)
block|{
name|set
argument_list|(
name|RHS
argument_list|)
block|;
return|return
name|RHS
return|;
block|}
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
block|{
name|set
argument_list|(
name|RHS
operator|.
name|Val
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
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
comment|/// zap - This is used to destroy Use operands when the number of operands of
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

begin_comment
comment|/// getPrefix - Return deletable pointer if appropriate
end_comment

begin_function_decl
name|Use
modifier|*
name|getPrefix
parameter_list|()
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
expr_stmt|;
end_expr_stmt

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
parameter_list|,
name|ptrdiff_t
name|Done
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

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

begin_decl_stmt
name|friend
name|class
name|User
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// simplify_type - Allow clients to treat uses just like values when using
end_comment

begin_comment
comment|// casting operators.
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
argument|const Use&Val
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|SimpleType
operator|>
operator|(
name|Val
operator|.
name|get
argument_list|()
operator|)
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
name|static_cast
operator|<
name|SimpleType
operator|>
operator|(
name|Val
operator|.
name|get
argument_list|()
operator|)
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
name|typename
name|UserTy
operator|>
comment|// UserTy == 'User' or 'const User'
name|class
name|value_use_iterator
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
name|UserTy
operator|*
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
name|UserTy
operator|*
operator|,
name|ptrdiff_t
operator|>
name|super
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|value_use_iterator
operator|<
name|UserTy
operator|>
name|_Self
expr_stmt|;
end_typedef

begin_decl_stmt
name|Use
modifier|*
name|U
decl_stmt|;
end_decl_stmt

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|value_use_iterator
argument_list|(
name|Use
operator|*
name|u
argument_list|)
operator|:
name|U
argument_list|(
argument|u
argument_list|)
block|{}
name|friend
name|class
name|Value
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|typename
name|super
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|super
operator|::
name|pointer
name|pointer
expr_stmt|;
end_typedef

begin_expr_stmt
name|value_use_iterator
argument_list|(
specifier|const
name|_Self
operator|&
name|I
argument_list|)
operator|:
name|U
argument_list|(
argument|I.U
argument_list|)
block|{}
name|value_use_iterator
argument_list|()
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|_Self
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|U
operator|==
name|x
operator|.
name|U
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|_Self
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

begin_comment
comment|/// atEnd - return true if this iterator is equal to use_end() on the value.
end_comment

begin_expr_stmt
name|bool
name|atEnd
argument_list|()
specifier|const
block|{
return|return
name|U
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|// Iterator traversal: forward iteration only
end_comment

begin_expr_stmt
name|_Self
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|assert
argument_list|(
name|U
operator|&&
literal|"Cannot increment end iterator!"
argument_list|)
block|;
name|U
operator|=
name|U
operator|->
name|getNext
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_Self
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|_Self
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
comment|// Retrieve a pointer to the current User.
end_comment

begin_expr_stmt
name|UserTy
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|U
operator|&&
literal|"Cannot dereference end iterator!"
argument_list|)
block|;
return|return
name|U
operator|->
name|getUser
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|UserTy
operator|*
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
name|Use
operator|&
name|getUse
argument_list|()
specifier|const
block|{
return|return
operator|*
name|U
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getOperandNo - Return the operand # of this use in its User.  Defined in
end_comment

begin_comment
comment|/// User.h
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|unsigned
name|getOperandNo
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|value_use_iterator
operator|<
name|User
operator|>
expr|>
block|{
typedef|typedef
name|User
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const value_use_iterator<User>&Val
argument_list|)
block|{
return|return
operator|*
name|Val
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
name|value_use_iterator
operator|<
name|User
operator|>
expr|>
operator|:
name|public
name|simplify_type
operator|<
name|value_use_iterator
operator|<
name|User
operator|>
expr|>
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|value_use_iterator
operator|<
specifier|const
name|User
operator|>
expr|>
block|{
typedef|typedef
specifier|const
name|User
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const                                         value_use_iterator<const User>&Val
argument_list|)
block|{
return|return
operator|*
name|Val
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
name|value_use_iterator
operator|<
specifier|const
name|User
operator|>
expr|>
operator|:
name|public
name|simplify_type
operator|<
name|value_use_iterator
operator|<
specifier|const
name|User
operator|>
expr|>
block|{}
expr_stmt|;
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

