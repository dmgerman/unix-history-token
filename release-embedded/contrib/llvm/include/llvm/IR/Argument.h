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
name|LLVM_IR_ARGUMENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_ARGUMENT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
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
comment|/// \brief LLVM Argument representation
comment|///
comment|/// This class represents an incoming formal argument to a Function. A formal
comment|/// argument, since it is ``formal'', does not contain an actual value but
comment|/// instead represents the type, argument number, and attributes of an argument
comment|/// for a specific function. When used in the body of said function, the
comment|/// argument of course represents the value of the actual argument that the
comment|/// function was called with.
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
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
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
comment|/// \brief Constructor.
comment|///
comment|/// If \p F is specified, the argument is inserted at the end of the argument
comment|/// list for \p F.
name|explicit
name|Argument
parameter_list|(
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
comment|/// \brief Return the index of this formal argument in its containing
comment|/// function.
comment|///
comment|/// For example in "void foo(int a, float b)" a is 0 and b is 1.
name|unsigned
name|getArgNo
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if this argument has the byval attribute on it in its
comment|/// containing function.
name|bool
name|hasByValAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief If this is a byval argument, return its alignment.
name|unsigned
name|getParamAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if this argument has the nest attribute on it in its
comment|/// containing function.
name|bool
name|hasNestAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if this argument has the noalias attribute on it in its
comment|/// containing function.
name|bool
name|hasNoAliasAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if this argument has the nocapture attribute on it in
comment|/// its containing function.
name|bool
name|hasNoCaptureAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if this argument has the sret attribute on it in its
comment|/// containing function.
name|bool
name|hasStructRetAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if this argument has the returned attribute on it in
comment|/// its containing function.
name|bool
name|hasReturnedAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if this argument has the readonly or readnone attribute
comment|/// on it in its containing function.
name|bool
name|onlyReadsMemory
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Add a Attribute to an argument.
name|void
name|addAttr
parameter_list|(
name|AttributeSet
name|AS
parameter_list|)
function_decl|;
comment|/// \brief Remove a Attribute from an argument.
name|void
name|removeAttr
parameter_list|(
name|AttributeSet
name|AS
parameter_list|)
function_decl|;
comment|/// \brief Method for support type inquiry through isa, cast, and
comment|/// dyn_cast.
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

