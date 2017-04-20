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
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|Function
operator|*
name|Parent
block|;
name|unsigned
name|ArgNo
block|;
name|friend
name|class
name|Function
block|;
name|void
name|setParent
argument_list|(
name|Function
operator|*
name|parent
argument_list|)
block|;
name|public
operator|:
comment|/// Argument constructor.
name|explicit
name|Argument
argument_list|(
argument|Type *Ty
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|Function *F = nullptr
argument_list|,
argument|unsigned ArgNo =
literal|0
argument_list|)
block|;
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
operator|*
name|getParent
argument_list|()
block|{
return|return
name|Parent
return|;
block|}
comment|/// Return the index of this formal argument in its containing function.
comment|///
comment|/// For example in "void foo(int a, float b)" a is 0 and b is 1.
name|unsigned
name|getArgNo
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Parent
operator|&&
literal|"can't get number of unparented arg"
argument_list|)
block|;
return|return
name|ArgNo
return|;
block|}
comment|/// Return true if this argument has the nonnull attribute. Also returns true
comment|/// if at least one byte is known to be dereferenceable and the pointer is in
comment|/// addrspace(0).
name|bool
name|hasNonNullAttr
argument_list|()
specifier|const
block|;
comment|/// If this argument has the dereferenceable attribute, return the number of
comment|/// bytes known to be dereferenceable. Otherwise, zero is returned.
name|uint64_t
name|getDereferenceableBytes
argument_list|()
specifier|const
block|;
comment|/// If this argument has the dereferenceable_or_null attribute, return the
comment|/// number of bytes known to be dereferenceable. Otherwise, zero is returned.
name|uint64_t
name|getDereferenceableOrNullBytes
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the byval attribute.
name|bool
name|hasByValAttr
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the swiftself attribute.
name|bool
name|hasSwiftSelfAttr
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the swifterror attribute.
name|bool
name|hasSwiftErrorAttr
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the byval attribute or inalloca
comment|/// attribute. These attributes represent arguments being passed by value.
name|bool
name|hasByValOrInAllocaAttr
argument_list|()
specifier|const
block|;
comment|/// If this is a byval or inalloca argument, return its alignment.
name|unsigned
name|getParamAlignment
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the nest attribute.
name|bool
name|hasNestAttr
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the noalias attribute.
name|bool
name|hasNoAliasAttr
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the nocapture attribute.
name|bool
name|hasNoCaptureAttr
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the sret attribute.
name|bool
name|hasStructRetAttr
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the returned attribute.
name|bool
name|hasReturnedAttr
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the readonly or readnone attribute.
name|bool
name|onlyReadsMemory
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the inalloca attribute.
name|bool
name|hasInAllocaAttr
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the zext attribute.
name|bool
name|hasZExtAttr
argument_list|()
specifier|const
block|;
comment|/// Return true if this argument has the sext attribute.
name|bool
name|hasSExtAttr
argument_list|()
specifier|const
block|;
comment|/// Add attributes to an argument.
name|void
name|addAttrs
argument_list|(
name|AttrBuilder
operator|&
name|B
argument_list|)
block|;
name|void
name|addAttr
argument_list|(
argument|Attribute::AttrKind Kind
argument_list|)
block|;
name|void
name|addAttr
argument_list|(
argument|Attribute Attr
argument_list|)
block|;
comment|/// Remove attributes from an argument.
name|void
name|removeAttr
argument_list|(
argument|AttributeList AS
argument_list|)
block|;
name|void
name|removeAttr
argument_list|(
argument|Attribute::AttrKind Kind
argument_list|)
block|;
comment|/// Check if an argument has a given attribute.
name|bool
name|hasAttribute
argument_list|(
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// Method for support type inquiry through isa, cast, and dyn_cast.
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
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
expr|}
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

