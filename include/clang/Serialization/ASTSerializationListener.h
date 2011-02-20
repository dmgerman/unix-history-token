begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ASTSerializationListener.h - Decl/Type PCH Write Events -*- C++ -*-===//
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
comment|//  This file defines the ASTSerializationListener class, which is notified
end_comment

begin_comment
comment|//  by the ASTWriter when an entity is serialized.
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
name|LLVM_CLANG_FRONTEND_AST_SERIALIZATION_LISTENER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_AST_SERIALIZATION_LISTENER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|PreprocessedEntity
decl_stmt|;
comment|/// \brief Listener object that receives callbacks when certain kinds of
comment|/// entities are serialized.
name|class
name|ASTSerializationListener
block|{
name|public
label|:
name|virtual
operator|~
name|ASTSerializationListener
argument_list|()
expr_stmt|;
comment|/// \brief Callback invoked whenever a preprocessed entity is serialized.
comment|///
comment|/// This callback will only occur when the translation unit was created with
comment|/// a detailed preprocessing record.
comment|///
comment|/// \param Entity The entity that has been serialized.
comment|///
comment|/// \param Offset The offset (in bits) of this entity in the resulting
comment|/// AST file.
name|virtual
name|void
name|SerializedPreprocessedEntity
parameter_list|(
name|PreprocessedEntity
modifier|*
name|Entity
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

