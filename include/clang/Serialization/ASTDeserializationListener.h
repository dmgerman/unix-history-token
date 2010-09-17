begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ASTDeserializationListener.h - Decl/Type PCH Read Events -*- C++ -*-===//
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
comment|//  This file defines the ASTDeserializationListener class, which is notified
end_comment

begin_comment
comment|//  by the ASTReader whenever a type or declaration is deserialized.
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
name|LLVM_CLANG_FRONTEND_AST_DESERIALIZATION_LISTENER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_AST_DESERIALIZATION_LISTENER_H
end_define

begin_include
include|#
directive|include
file|"clang/Serialization/ASTBitCodes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|ASTReader
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|ASTDeserializationListener
block|{
name|protected
label|:
name|virtual
operator|~
name|ASTDeserializationListener
argument_list|()
block|{}
name|public
operator|:
comment|/// \brief Tell the listener about the reader.
name|virtual
name|void
name|SetReader
argument_list|(
name|ASTReader
operator|*
name|Reader
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// \brief An identifier was deserialized from the AST file.
name|virtual
name|void
name|IdentifierRead
argument_list|(
name|serialization
operator|::
name|IdentID
name|ID
argument_list|,
name|IdentifierInfo
operator|*
name|II
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// \brief A type was deserialized from the AST file. The ID here has the
comment|///        qualifier bits already removed, and T is guaranteed to be locally
comment|///        unqualified.
name|virtual
name|void
name|TypeRead
argument_list|(
name|serialization
operator|::
name|TypeIdx
name|Idx
argument_list|,
name|QualType
name|T
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// \brief A decl was deserialized from the AST file.
name|virtual
name|void
name|DeclRead
argument_list|(
name|serialization
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
comment|/// \brief A selector was read from the AST file.
name|virtual
name|void
name|SelectorRead
argument_list|(
name|serialization
operator|::
name|SelectorID
name|iD
argument_list|,
name|Selector
name|Sel
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

