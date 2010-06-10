begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- EntityImpl.h - Internal Entity implementation---------*- C++ -*-=====//
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
comment|//  Internal implementation for the Entity class
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
name|LLVM_CLANG_INDEX_ENTITYIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_ENTITYIMPL_H
end_define

begin_include
include|#
directive|include
file|"clang/Index/Entity.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|idx
block|{
name|class
name|ProgramImpl
decl_stmt|;
name|class
name|EntityImpl
range|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|Entity
name|Parent
block|;
name|DeclarationName
name|Name
block|;
comment|/// \brief Identifier namespace.
name|unsigned
name|IdNS
block|;
comment|/// \brief If Name is a selector, this keeps track whether it's for an
comment|/// instance method.
name|bool
name|IsObjCInstanceMethod
block|;
name|public
operator|:
name|EntityImpl
argument_list|(
argument|Entity parent
argument_list|,
argument|DeclarationName name
argument_list|,
argument|unsigned idNS
argument_list|,
argument|bool isObjCInstanceMethod
argument_list|)
operator|:
name|Parent
argument_list|(
name|parent
argument_list|)
block|,
name|Name
argument_list|(
name|name
argument_list|)
block|,
name|IdNS
argument_list|(
name|idNS
argument_list|)
block|,
name|IsObjCInstanceMethod
argument_list|(
argument|isObjCInstanceMethod
argument_list|)
block|{ }
comment|/// \brief Find the Decl that can be referred to by this entity.
name|Decl
operator|*
name|getDecl
argument_list|(
name|ASTContext
operator|&
name|AST
argument_list|)
block|;
comment|/// \brief Get an Entity associated with the given Decl.
comment|/// \returns Null if an Entity cannot refer to this Decl.
specifier|static
name|Entity
name|get
argument_list|(
name|Decl
operator|*
name|D
argument_list|,
name|Program
operator|&
name|Prog
argument_list|,
name|ProgramImpl
operator|&
name|ProgImpl
argument_list|)
block|;
name|std
operator|::
name|string
name|getPrintableName
argument_list|()
block|;
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|Parent
argument_list|,
name|Name
argument_list|,
name|IdNS
argument_list|,
name|IsObjCInstanceMethod
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|Entity Parent
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|unsigned IdNS
argument_list|,
argument|bool isObjCInstanceMethod
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Parent
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|Name
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|IdNS
argument_list|)
block|;
name|ID
operator|.
name|AddBoolean
argument_list|(
name|isObjCInstanceMethod
argument_list|)
block|;   }
block|}
decl_stmt|;
block|}
comment|// namespace idx
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

