begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTMutationListener.h - AST Mutation Interface --------*- C++ -*-===//
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
comment|//  This file defines the ASTMutationListener interface.
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
name|LLVM_CLANG_AST_ASTMUTATIONLISTENER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_ASTMUTATIONLISTENER_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|TagDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|ClassTemplateDecl
decl_stmt|;
name|class
name|ClassTemplateSpecializationDecl
decl_stmt|;
comment|/// \brief An abstract interface that should be implemented by listeners
comment|/// that want to be notified when an AST entity gets modified after its
comment|/// initial creation.
name|class
name|ASTMutationListener
block|{
name|public
label|:
name|virtual
operator|~
name|ASTMutationListener
argument_list|()
expr_stmt|;
comment|/// \brief A new TagDecl definition was completed.
name|virtual
name|void
name|CompletedTagDefinition
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|D
parameter_list|)
block|{ }
comment|/// \brief A new declaration with name has been added to a DeclContext.
name|virtual
name|void
name|AddedVisibleDecl
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|,
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief An implicit member was added after the definition was completed.
name|virtual
name|void
name|AddedCXXImplicitMember
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief A template specialization (or partial one) was added to the
comment|/// template declaration.
name|virtual
name|void
name|AddedCXXTemplateSpecialization
parameter_list|(
specifier|const
name|ClassTemplateDecl
modifier|*
name|TD
parameter_list|,
specifier|const
name|ClassTemplateSpecializationDecl
modifier|*
name|D
parameter_list|)
block|{}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

