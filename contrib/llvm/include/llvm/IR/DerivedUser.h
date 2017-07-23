begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DerivedUser.h - Base for non-IR Users --------------------*- C++ -*-===//
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
name|LLVM_IR_DERIVEDUSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_DERIVEDUSER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/User.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Type
decl_stmt|;
name|class
name|Use
decl_stmt|;
comment|/// Extension point for the Value hierarchy. All classes outside of lib/IR
comment|/// that wish to inherit from User should instead inherit from DerivedUser
comment|/// instead. Inheriting from this class is discouraged.
comment|///
comment|/// Generally speaking, Value is the base of a closed class hierarchy
comment|/// that can't be extended by code outside of lib/IR. This class creates a
comment|/// loophole that allows classes outside of lib/IR to extend User to leverage
comment|/// its use/def list machinery.
name|class
name|DerivedUser
range|:
name|public
name|User
block|{
name|protected
operator|:
name|using
name|DeleteValueTy
operator|=
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|DerivedUser
operator|*
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|Value
block|;
name|DeleteValueTy
name|DeleteValue
block|;
name|public
operator|:
name|DerivedUser
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned VK
argument_list|,
argument|Use *U
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|DeleteValueTy DeleteValue
argument_list|)
operator|:
name|User
argument_list|(
name|Ty
argument_list|,
name|VK
argument_list|,
name|U
argument_list|,
name|NumOps
argument_list|)
block|,
name|DeleteValue
argument_list|(
argument|DeleteValue
argument_list|)
block|{}
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_DERIVEDUSER_H
end_comment

end_unit

