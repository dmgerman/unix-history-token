begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Argument.h - Definition of the Argument class ------*- C++ -*-===//
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
comment|// This file declares the Argument class.
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
name|LLVM_ARGUMENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ARGUMENT_H
end_define

begin_include
include|#
directive|include
file|"llvm/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|ValueSubClass
operator|,
name|typename
name|ItemParentClass
operator|>
name|class
name|SymbolTableListTraits
expr_stmt|;
comment|/// A class to represent an incoming formal argument to a Function. An argument
comment|/// is a very simple Value. It is essentially a named (optional) type. When used
comment|/// in the body of a function, it represents the value of the actual argument
comment|/// the function was called with.
comment|/// @brief LLVM Argument representation
name|class
name|Argument
range|:
name|public
name|Value
decl_stmt|,
name|public
name|ilist_node
decl|<
name|Argument
decl|>
block|{
name|Function
modifier|*
name|Parent
decl_stmt|;
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|Argument
operator|,
name|Function
operator|>
expr_stmt|;
name|void
name|setParent
parameter_list|(
name|Function
modifier|*
name|parent
parameter_list|)
function_decl|;
name|public
label|:
comment|/// Argument ctor - If Function argument is specified, this argument is
comment|/// inserted at the end of the argument list for the function.
comment|///
name|explicit
name|Argument
parameter_list|(
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Name
init|=
literal|""
parameter_list|,
name|Function
modifier|*
name|F
init|=
literal|0
parameter_list|)
function_decl|;
specifier|inline
specifier|const
name|Function
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
specifier|inline
name|Function
modifier|*
name|getParent
parameter_list|()
block|{
return|return
name|Parent
return|;
block|}
comment|/// getArgNo - Return the index of this formal argument in its containing
comment|/// function.  For example in "void foo(int a, float b)" a is 0 and b is 1.
name|unsigned
name|getArgNo
argument_list|()
specifier|const
expr_stmt|;
comment|/// hasByValAttr - Return true if this argument has the byval attribute on it
comment|/// in its containing function.
name|bool
name|hasByValAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// hasNestAttr - Return true if this argument has the nest attribute on
comment|/// it in its containing function.
name|bool
name|hasNestAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// hasNoAliasAttr - Return true if this argument has the noalias attribute on
comment|/// it in its containing function.
name|bool
name|hasNoAliasAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// hasNoCaptureAttr - Return true if this argument has the nocapture
comment|/// attribute on it in its containing function.
name|bool
name|hasNoCaptureAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// hasSRetAttr - Return true if this argument has the sret attribute on it in
comment|/// its containing function.
name|bool
name|hasStructRetAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// addAttr - Add a Attribute to an argument
name|void
name|addAttr
parameter_list|(
name|Attributes
parameter_list|)
function_decl|;
comment|/// removeAttr - Remove a Attribute from an argument
name|void
name|removeAttr
parameter_list|(
name|Attributes
parameter_list|)
function_decl|;
comment|/// classof - Methods for support type inquiry through isa, cast, and
comment|/// dyn_cast:
comment|///
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|Argument
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ArgumentVal
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

