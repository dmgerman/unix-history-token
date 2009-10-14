begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/AbstractTypeUser.h - AbstractTypeUser Interface ----*- C++ -*-===//
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
comment|// This file declares the AbstractTypeUser class.
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
name|LLVM_ABSTRACT_TYPE_USER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ABSTRACT_TYPE_USER_H
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LLVM_TYPE_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LLVM_VALUE_H
argument_list|)
end_if

begin_error
error|#
directive|error
error|Do not include this file directly.  Include Type.h instead.
end_error

begin_error
error|#
directive|error
error|Some versions of GCC (e.g. 3.4 and 4.1) can not handle the inlined method
end_error

begin_error
error|#
directive|error
error|PATypeHolder::dropRef() correctly otherwise.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// This is the "master" include for<cassert> Whether this file needs it or not,
end_comment

begin_comment
comment|// it must always include<cassert> for the files which include
end_comment

begin_comment
comment|// llvm/AbstractTypeUser.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// In this way, most every LLVM source file will have access to the assert()
end_comment

begin_comment
comment|// macro without having to #include<cassert> directly.
end_comment

begin_comment
comment|//
end_comment

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
name|Value
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|DerivedType
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|simplify_type
expr_stmt|;
comment|/// The AbstractTypeUser class is an interface to be implemented by classes who
comment|/// could possibly use an abstract type.  Abstract types are denoted by the
comment|/// isAbstract flag set to true in the Type class.  These are classes that
comment|/// contain an Opaque type in their structure somewhere.
comment|///
comment|/// Classes must implement this interface so that they may be notified when an
comment|/// abstract type is resolved.  Abstract types may be resolved into more
comment|/// concrete types through: linking, parsing, and bitcode reading.  When this
comment|/// happens, all of the users of the type must be updated to reference the new,
comment|/// more concrete type.  They are notified through the AbstractTypeUser
comment|/// interface.
comment|///
comment|/// In addition to this, AbstractTypeUsers must keep the use list of the
comment|/// potentially abstract type that they reference up-to-date.  To do this in a
comment|/// nice, transparent way, the PATypeHandle class is used to hold "Potentially
comment|/// Abstract Types", and keep the use list of the abstract types up-to-date.
comment|/// @brief LLVM Abstract Type User Representation
name|class
name|AbstractTypeUser
block|{
name|protected
label|:
name|virtual
operator|~
name|AbstractTypeUser
argument_list|()
expr_stmt|;
comment|// Derive from me
comment|/// setType - It's normally not possible to change a Value's type in place,
comment|/// but an AbstractTypeUser subclass that knows what its doing can be
comment|/// permitted to do so with care.
name|void
name|setType
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|Type
modifier|*
name|NewTy
parameter_list|)
function_decl|;
name|public
label|:
comment|/// refineAbstractType - The callback method invoked when an abstract type is
comment|/// resolved to another type.  An object must override this method to update
comment|/// its internal state to reference NewType instead of OldType.
comment|///
name|virtual
name|void
name|refineAbstractType
parameter_list|(
specifier|const
name|DerivedType
modifier|*
name|OldTy
parameter_list|,
specifier|const
name|Type
modifier|*
name|NewTy
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// The other case which AbstractTypeUsers must be aware of is when a type
comment|/// makes the transition from being abstract (where it has clients on its
comment|/// AbstractTypeUsers list) to concrete (where it does not).  This method
comment|/// notifies ATU's when this occurs for a type.
comment|///
name|virtual
name|void
name|typeBecameConcrete
parameter_list|(
specifier|const
name|DerivedType
modifier|*
name|AbsTy
parameter_list|)
init|=
literal|0
function_decl|;
comment|// for debugging...
name|virtual
name|void
name|dump
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// PATypeHandle - Handle to a Type subclass.  This class is used to keep the
comment|/// use list of abstract types up-to-date.
comment|///
name|class
name|PATypeHandle
block|{
specifier|const
name|Type
modifier|*
name|Ty
decl_stmt|;
name|AbstractTypeUser
modifier|*
specifier|const
name|User
decl_stmt|;
comment|// These functions are defined at the bottom of Type.h.  See the comment there
comment|// for justification.
name|void
name|addUser
parameter_list|()
function_decl|;
name|void
name|removeUser
parameter_list|()
function_decl|;
name|public
label|:
comment|// ctor - Add use to type if abstract.  Note that Ty must not be null
specifier|inline
name|PATypeHandle
argument_list|(
specifier|const
name|Type
operator|*
name|ty
argument_list|,
name|AbstractTypeUser
operator|*
name|user
argument_list|)
operator|:
name|Ty
argument_list|(
name|ty
argument_list|)
operator|,
name|User
argument_list|(
argument|user
argument_list|)
block|{
name|addUser
argument_list|()
block|;   }
comment|// ctor - Add use to type if abstract.
specifier|inline
name|PATypeHandle
argument_list|(
specifier|const
name|PATypeHandle
operator|&
name|T
argument_list|)
operator|:
name|Ty
argument_list|(
name|T
operator|.
name|Ty
argument_list|)
operator|,
name|User
argument_list|(
argument|T.User
argument_list|)
block|{
name|addUser
argument_list|()
block|;   }
comment|// dtor - Remove reference to type...
specifier|inline
operator|~
name|PATypeHandle
argument_list|()
block|{
name|removeUser
argument_list|()
block|; }
comment|// Automatic casting operator so that the handle may be used naturally
specifier|inline
name|operator
name|Type
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Type
operator|*
operator|>
operator|(
name|Ty
operator|)
return|;
block|}
specifier|inline
name|Type
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Type
operator|*
operator|>
operator|(
name|Ty
operator|)
return|;
block|}
comment|// operator= - Allow assignment to handle
specifier|inline
name|Type
modifier|*
name|operator
init|=
operator|(
specifier|const
name|Type
operator|*
name|ty
operator|)
block|{
if|if
condition|(
name|Ty
operator|!=
name|ty
condition|)
block|{
comment|// Ensure we don't accidentally drop last ref to Ty
name|removeUser
argument_list|()
expr_stmt|;
name|Ty
operator|=
name|ty
expr_stmt|;
name|addUser
argument_list|()
expr_stmt|;
block|}
return|return
name|get
argument_list|()
return|;
block|}
comment|// operator= - Allow assignment to handle
specifier|inline
specifier|const
name|Type
modifier|*
name|operator
init|=
operator|(
specifier|const
name|PATypeHandle
operator|&
name|T
operator|)
block|{
return|return
name|operator
operator|=
operator|(
name|T
operator|.
name|Ty
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Type
operator|*
name|ty
operator|)
block|{
return|return
name|Ty
operator|==
name|ty
return|;
block|}
comment|// operator-> - Allow user to dereference handle naturally...
specifier|inline
specifier|const
name|Type
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Ty
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// PATypeHolder - Holder class for a potentially abstract type.  This uses
end_comment

begin_comment
comment|/// efficient union-find techniques to handle dynamic type resolution.  Unless
end_comment

begin_comment
comment|/// you need to do custom processing when types are resolved, you should always
end_comment

begin_comment
comment|/// use PATypeHolders in preference to PATypeHandles.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|PATypeHolder
block|{
name|mutable
specifier|const
name|Type
modifier|*
name|Ty
decl_stmt|;
name|void
name|destroy
parameter_list|()
function_decl|;
name|public
label|:
name|PATypeHolder
argument_list|(
specifier|const
name|Type
operator|*
name|ty
argument_list|)
operator|:
name|Ty
argument_list|(
argument|ty
argument_list|)
block|{
name|addRef
argument_list|()
block|;   }
name|PATypeHolder
argument_list|(
specifier|const
name|PATypeHolder
operator|&
name|T
argument_list|)
operator|:
name|Ty
argument_list|(
argument|T.Ty
argument_list|)
block|{
name|addRef
argument_list|()
block|;   }
operator|~
name|PATypeHolder
argument_list|()
block|{
if|if
condition|(
name|Ty
condition|)
name|dropRef
argument_list|()
expr_stmt|;
block|}
name|operator
name|Type
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|get
argument_list|()
return|;
block|}
name|Type
operator|*
name|get
argument_list|()
specifier|const
expr_stmt|;
comment|// operator-> - Allow user to dereference handle naturally...
name|Type
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|get
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|// operator= - Allow assignment to handle
end_comment

begin_decl_stmt
name|Type
modifier|*
name|operator
init|=
operator|(
specifier|const
name|Type
operator|*
name|ty
operator|)
block|{
if|if
condition|(
name|Ty
operator|!=
name|ty
condition|)
block|{
comment|// Don't accidentally drop last ref to Ty.
name|dropRef
argument_list|()
expr_stmt|;
name|Ty
operator|=
name|ty
expr_stmt|;
name|addRef
argument_list|()
expr_stmt|;
block|}
return|return
name|get
argument_list|()
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|Type
modifier|*
name|operator
init|=
operator|(
specifier|const
name|PATypeHolder
operator|&
name|H
operator|)
block|{
return|return
name|operator
operator|=
operator|(
name|H
operator|.
name|Ty
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getRawType - This should only be used to implement the vmcore library.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
specifier|const
name|Type
operator|*
name|getRawType
argument_list|()
specifier|const
block|{
return|return
name|Ty
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|addRef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dropRef
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|friend
name|class
name|TypeMapBase
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
name|PATypeHolder
operator|>
block|{
typedef|typedef
specifier|const
name|Type
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const PATypeHolder&Val
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
name|PATypeHolder
operator|>
block|{
typedef|typedef
specifier|const
name|Type
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const PATypeHolder&Val
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

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

