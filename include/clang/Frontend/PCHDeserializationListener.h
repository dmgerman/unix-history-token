begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PCHDeserializationListener.h - Decl/Type PCH Read Events -*- C++ -*-===//
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
comment|//  This file defines the PCHDeserializationListener class, which is notified
end_comment

begin_comment
comment|//  by the PCHReader whenever a type or declaration is deserialized.
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
name|LLVM_CLANG_FRONTEND_PCH_DESERIALIZATION_LISTENER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_PCH_DESERIALIZATION_LISTENER_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/PCHBitCodes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|PCHDeserializationListener
block|{
name|protected
label|:
operator|~
name|PCHDeserializationListener
argument_list|()
block|{}
name|public
operator|:
name|virtual
name|void
name|TypeRead
argument_list|(
argument|pch::TypeID ID
argument_list|,
argument|QualType T
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|DeclRead
argument_list|(
name|pch
operator|::
name|DeclID
name|ID
argument_list|,
specifier|const
name|Decl
operator|*
name|D
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

