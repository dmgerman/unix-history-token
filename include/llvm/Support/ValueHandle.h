begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/ValueHandle.h - Value Smart Pointer classes -*- C++ -*-===//
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
comment|// This file declares the ValueHandle class and its sub-classes.
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
name|LLVM_SUPPORT_VALUEHANDLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_VALUEHANDLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Value.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ValueHandleBase
decl_stmt|;
comment|// ValueHandleBase** is only 4-byte aligned.
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|ValueHandleBase
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
argument|ValueHandleBase** P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
name|ValueHandleBase
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
name|ValueHandleBase
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
comment|/// ValueHandleBase - This is the common base class of value handles.
comment|/// ValueHandle's are smart pointers to Value's that have special behavior when
comment|/// the value is deleted or ReplaceAllUsesWith'd.  See the specific handles
comment|/// below for details.
comment|///
name|class
name|ValueHandleBase
block|{
name|friend
name|class
name|Value
decl_stmt|;
name|protected
label|:
comment|/// HandleBaseKind - This indicates what sub class the handle actually is.
comment|/// This is to avoid having a vtable for the light-weight handle pointers. The
comment|/// fully general Callback version does have a vtable.
enum|enum
name|HandleBaseKind
block|{
name|Assert
block|,
name|Weak
block|,
name|Callback
block|}
enum|;
name|private
label|:
name|PointerIntPair
operator|<
name|ValueHandleBase
operator|*
operator|*
operator|,
literal|2
operator|,
name|HandleBaseKind
operator|>
name|PrevPair
expr_stmt|;
name|ValueHandleBase
modifier|*
name|Next
decl_stmt|;
name|Value
modifier|*
name|VP
decl_stmt|;
name|public
label|:
name|explicit
name|ValueHandleBase
argument_list|(
argument|HandleBaseKind Kind
argument_list|)
block|:
name|PrevPair
argument_list|(
literal|0
argument_list|,
name|Kind
argument_list|)
operator|,
name|Next
argument_list|(
literal|0
argument_list|)
operator|,
name|VP
argument_list|(
literal|0
argument_list|)
block|{}
name|ValueHandleBase
argument_list|(
argument|HandleBaseKind Kind
argument_list|,
argument|Value *V
argument_list|)
operator|:
name|PrevPair
argument_list|(
literal|0
argument_list|,
name|Kind
argument_list|)
operator|,
name|Next
argument_list|(
literal|0
argument_list|)
operator|,
name|VP
argument_list|(
argument|V
argument_list|)
block|{
if|if
condition|(
name|V
condition|)
name|AddToUseList
argument_list|()
expr_stmt|;
block|}
name|ValueHandleBase
argument_list|(
argument|HandleBaseKind Kind
argument_list|,
argument|const ValueHandleBase&RHS
argument_list|)
block|:
name|PrevPair
argument_list|(
literal|0
argument_list|,
name|Kind
argument_list|)
operator|,
name|Next
argument_list|(
literal|0
argument_list|)
operator|,
name|VP
argument_list|(
argument|RHS.VP
argument_list|)
block|{
if|if
condition|(
name|VP
condition|)
name|AddToExistingUseList
argument_list|(
name|RHS
operator|.
name|getPrevPtr
argument_list|()
argument_list|)
expr_stmt|;
block|}
operator|~
name|ValueHandleBase
argument_list|()
block|{
if|if
condition|(
name|VP
condition|)
name|RemoveFromUseList
argument_list|()
expr_stmt|;
block|}
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
if|if
condition|(
name|VP
operator|==
name|RHS
condition|)
return|return
name|RHS
return|;
if|if
condition|(
name|VP
condition|)
name|RemoveFromUseList
argument_list|()
expr_stmt|;
name|VP
operator|=
name|RHS
expr_stmt|;
if|if
condition|(
name|VP
condition|)
name|AddToUseList
argument_list|()
expr_stmt|;
return|return
name|RHS
return|;
block|}
name|Value
modifier|*
name|operator
init|=
operator|(
specifier|const
name|ValueHandleBase
operator|&
name|RHS
operator|)
block|{
if|if
condition|(
name|VP
operator|==
name|RHS
operator|.
name|VP
condition|)
return|return
name|RHS
operator|.
name|VP
return|;
if|if
condition|(
name|VP
condition|)
name|RemoveFromUseList
argument_list|()
expr_stmt|;
name|VP
operator|=
name|RHS
operator|.
name|VP
expr_stmt|;
if|if
condition|(
name|VP
condition|)
name|AddToExistingUseList
argument_list|(
name|RHS
operator|.
name|getPrevPtr
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|VP
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|Value
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
name|getValPtr
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|Value
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|getValPtr
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|Value
operator|*
name|getValPtr
argument_list|()
specifier|const
block|{
return|return
name|VP
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Callbacks made from Value.
end_comment

begin_function_decl
specifier|static
name|void
name|ValueIsDeleted
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ValueIsRAUWd
parameter_list|(
name|Value
modifier|*
name|Old
parameter_list|,
name|Value
modifier|*
name|New
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Internal implementation details.
end_comment

begin_expr_stmt
name|ValueHandleBase
operator|*
operator|*
name|getPrevPtr
argument_list|()
specifier|const
block|{
return|return
name|PrevPair
operator|.
name|getPointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|HandleBaseKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|PrevPair
operator|.
name|getInt
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setPrevPtr
parameter_list|(
name|ValueHandleBase
modifier|*
modifier|*
name|Ptr
parameter_list|)
block|{
name|PrevPair
operator|.
name|setPointer
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// AddToUseList - Add this ValueHandle to the use list for VP, where List is
end_comment

begin_comment
comment|/// known to point into the existing use list.
end_comment

begin_function_decl
name|void
name|AddToExistingUseList
parameter_list|(
name|ValueHandleBase
modifier|*
modifier|*
name|List
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddToUseList - Add this ValueHandle to the use list for VP.
end_comment

begin_function_decl
name|void
name|AddToUseList
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// RemoveFromUseList - Remove this ValueHandle from its current use list.
end_comment

begin_function_decl
name|void
name|RemoveFromUseList
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// WeakVH - This is a value handle that tries hard to point to a Value, even
end_comment

begin_comment
comment|/// across RAUW operations, but will null itself out if the value is destroyed.
end_comment

begin_comment
comment|/// this is useful for advisory sorts of information, but should not be used as
end_comment

begin_comment
comment|/// the key of a map (since the map would have to rearrange itself when the
end_comment

begin_comment
comment|/// pointer changes).
end_comment

begin_decl_stmt
name|class
name|WeakVH
range|:
name|public
name|ValueHandleBase
block|{
name|public
operator|:
name|WeakVH
argument_list|()
operator|:
name|ValueHandleBase
argument_list|(
argument|Weak
argument_list|)
block|{}
name|WeakVH
argument_list|(
name|Value
operator|*
name|P
argument_list|)
operator|:
name|ValueHandleBase
argument_list|(
argument|Weak
argument_list|,
argument|P
argument_list|)
block|{}
name|WeakVH
argument_list|(
specifier|const
name|WeakVH
operator|&
name|RHS
argument_list|)
operator|:
name|ValueHandleBase
argument_list|(
argument|Weak
argument_list|,
argument|RHS
argument_list|)
block|{}
name|operator
name|Value
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|getValPtr
argument_list|()
return|;
block|}
expr|}
block|;
comment|// Specialize simplify_type to allow WeakVH to participate in
comment|// dyn_cast, isa, etc.
name|template
operator|<
name|typename
name|From
operator|>
expr|struct
name|simplify_type
block|;
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
name|WeakVH
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
argument|const WeakVH&WVH
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|WVH
operator|)
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|WeakVH
operator|>
operator|:
name|public
name|simplify_type
operator|<
specifier|const
name|WeakVH
operator|>
block|{}
block|;
comment|/// AssertingVH - This is a Value Handle that points to a value and asserts out
comment|/// if the value is destroyed while the handle is still live.  This is very
comment|/// useful for catching dangling pointer bugs and other things which can be
comment|/// non-obvious.  One particularly useful place to use this is as the Key of a
comment|/// map.  Dangling pointer bugs often lead to really subtle bugs that only occur
comment|/// if another object happens to get allocated to the same address as the old
comment|/// one.  Using an AssertingVH ensures that an assert is triggered as soon as
comment|/// the bad delete occurs.
comment|///
comment|/// Note that an AssertingVH handle does *not* follow values across RAUW
comment|/// operations.  This means that RAUW's need to explicitly update the
comment|/// AssertingVH's as it moves.  This is required because in non-assert mode this
comment|/// class turns into a trivial wrapper around a pointer.
name|template
operator|<
name|typename
name|ValueTy
operator|>
name|class
name|AssertingVH
ifndef|#
directive|ifndef
name|NDEBUG
operator|:
name|public
name|ValueHandleBase
endif|#
directive|endif
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|ValueTy
operator|*
name|getValPtr
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ValueTy
operator|*
operator|>
operator|(
name|ValueHandleBase
operator|::
name|getValPtr
argument_list|()
operator|)
return|;
block|}
name|void
name|setValPtr
argument_list|(
argument|ValueTy *P
argument_list|)
block|{
name|ValueHandleBase
operator|::
name|operator
operator|=
operator|(
name|P
operator|)
block|;   }
else|#
directive|else
name|ValueTy
operator|*
name|ThePtr
block|;
name|ValueTy
operator|*
name|getValPtr
argument_list|()
specifier|const
block|{
return|return
name|ThePtr
return|;
block|}
name|void
name|setValPtr
argument_list|(
argument|ValueTy *P
argument_list|)
block|{
name|ThePtr
operator|=
name|P
block|; }
endif|#
directive|endif
name|public
operator|:
ifndef|#
directive|ifndef
name|NDEBUG
name|AssertingVH
argument_list|()
operator|:
name|ValueHandleBase
argument_list|(
argument|Assert
argument_list|)
block|{}
name|AssertingVH
argument_list|(
name|ValueTy
operator|*
name|P
argument_list|)
operator|:
name|ValueHandleBase
argument_list|(
argument|Assert
argument_list|,
argument|P
argument_list|)
block|{}
name|AssertingVH
argument_list|(
specifier|const
name|AssertingVH
operator|&
name|RHS
argument_list|)
operator|:
name|ValueHandleBase
argument_list|(
argument|Assert
argument_list|,
argument|RHS
argument_list|)
block|{}
else|#
directive|else
name|AssertingVH
argument_list|()
operator|:
name|ThePtr
argument_list|(
literal|0
argument_list|)
block|{}
name|AssertingVH
argument_list|(
name|ValueTy
operator|*
name|P
argument_list|)
operator|:
name|ThePtr
argument_list|(
argument|P
argument_list|)
block|{}
endif|#
directive|endif
name|operator
name|ValueTy
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|getValPtr
argument_list|()
return|;
block|}
name|ValueTy
operator|*
name|operator
operator|=
operator|(
name|ValueTy
operator|*
name|RHS
operator|)
block|{
name|setValPtr
argument_list|(
name|RHS
argument_list|)
block|;
return|return
name|getValPtr
argument_list|()
return|;
block|}
name|ValueTy
operator|*
name|operator
operator|=
operator|(
name|AssertingVH
operator|<
name|ValueTy
operator|>
operator|&
name|RHS
operator|)
block|{
name|setValPtr
argument_list|(
name|RHS
operator|.
name|getValPtr
argument_list|()
argument_list|)
block|;
return|return
name|getValPtr
argument_list|()
return|;
block|}
name|ValueTy
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
name|getValPtr
argument_list|()
return|;
block|}
name|ValueTy
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|getValPtr
argument_list|()
return|;
block|}
expr|}
block|;
comment|// Specialize simplify_type to allow AssertingVH to participate in
comment|// dyn_cast, isa, etc.
name|template
operator|<
name|typename
name|From
operator|>
expr|struct
name|simplify_type
block|;
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
name|AssertingVH
operator|<
name|Value
operator|>
expr|>
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
argument|const AssertingVH<Value>&AVH
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|AVH
operator|)
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|AssertingVH
operator|<
name|Value
operator|>
expr|>
operator|:
name|public
name|simplify_type
operator|<
specifier|const
name|AssertingVH
operator|<
name|Value
operator|>
expr|>
block|{}
block|;
comment|/// CallbackVH - This is a value handle that allows subclasses to define
comment|/// callbacks that run when the underlying Value has RAUW called on it or is
comment|/// destroyed.  This class can be used as the key of a map, as long as the user
comment|/// takes it out of the map before calling setValPtr() (since the map has to
comment|/// rearrange itself when the pointer changes).  Unlike ValueHandleBase, this
comment|/// class has a vtable and a virtual destructor.
name|class
name|CallbackVH
operator|:
name|public
name|ValueHandleBase
block|{
name|protected
operator|:
name|CallbackVH
argument_list|(
specifier|const
name|CallbackVH
operator|&
name|RHS
argument_list|)
operator|:
name|ValueHandleBase
argument_list|(
argument|Callback
argument_list|,
argument|RHS
argument_list|)
block|{}
name|virtual
operator|~
name|CallbackVH
argument_list|()
block|;
name|void
name|setValPtr
argument_list|(
argument|Value *P
argument_list|)
block|{
name|ValueHandleBase
operator|::
name|operator
operator|=
operator|(
name|P
operator|)
block|;   }
name|public
operator|:
name|CallbackVH
argument_list|()
operator|:
name|ValueHandleBase
argument_list|(
argument|Callback
argument_list|)
block|{}
name|CallbackVH
argument_list|(
name|Value
operator|*
name|P
argument_list|)
operator|:
name|ValueHandleBase
argument_list|(
argument|Callback
argument_list|,
argument|P
argument_list|)
block|{}
name|operator
name|Value
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|getValPtr
argument_list|()
return|;
block|}
comment|/// Called when this->getValPtr() is destroyed, inside ~Value(), so you may
comment|/// call any non-virtual Value method on getValPtr(), but no subclass methods.
comment|/// If WeakVH were implemented as a CallbackVH, it would use this method to
comment|/// call setValPtr(NULL).  AssertingVH would use this method to cause an
comment|/// assertion failure.
comment|///
comment|/// All implementations must remove the reference from this object to the
comment|/// Value that's being destroyed.
name|virtual
name|void
name|deleted
argument_list|()
block|{
name|setValPtr
argument_list|(
name|NULL
argument_list|)
block|;   }
comment|/// Called when this->getValPtr()->replaceAllUsesWith(new_value) is called,
comment|/// _before_ any of the uses have actually been replaced.  If WeakVH were
comment|/// implemented as a CallbackVH, it would use this method to call
comment|/// setValPtr(new_value).  AssertingVH would do nothing in this method.
name|virtual
name|void
name|allUsesReplacedWith
argument_list|(
argument|Value *new_value
argument_list|)
block|{}
expr|}
block|;
comment|// Specialize simplify_type to allow CallbackVH to participate in
comment|// dyn_cast, isa, etc.
name|template
operator|<
name|typename
name|From
operator|>
expr|struct
name|simplify_type
block|;
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
name|CallbackVH
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
argument|const CallbackVH&CVH
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|CVH
operator|)
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|CallbackVH
operator|>
operator|:
name|public
name|simplify_type
operator|<
specifier|const
name|CallbackVH
operator|>
block|{}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

