begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTConsumer.h - Abstract interface for reading ASTs ----*- C++ -*-===//
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
comment|//  This file defines the ASTConsumer class.
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
name|LLVM_CLANG_AST_ASTCONSUMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_ASTCONSUMER_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|DeclGroupRef
decl_stmt|;
name|class
name|TagDecl
decl_stmt|;
name|class
name|HandleTagDeclDefinition
decl_stmt|;
name|class
name|SemaConsumer
decl_stmt|;
comment|// layering violation required for safe SemaConsumer
name|class
name|VarDecl
decl_stmt|;
comment|/// ASTConsumer - This is an abstract interface that should be implemented by
comment|/// clients that read ASTs.  This abstraction layer allows the client to be
comment|/// independent of the AST producer (e.g. parser vs AST dump file reader, etc).
name|class
name|ASTConsumer
block|{
comment|/// \brief Whether this AST consumer also requires information about
comment|/// semantic analysis.
name|bool
name|SemaConsumer
decl_stmt|;
name|friend
name|class
name|SemaConsumer
decl_stmt|;
name|public
label|:
name|ASTConsumer
argument_list|()
operator|:
name|SemaConsumer
argument_list|(
argument|false
argument_list|)
block|{ }
name|virtual
operator|~
name|ASTConsumer
argument_list|()
block|{}
comment|/// Initialize - This is called to initialize the consumer, providing the
comment|/// ASTContext.
name|virtual
name|void
name|Initialize
argument_list|(
argument|ASTContext&Context
argument_list|)
block|{}
comment|/// HandleTopLevelDecl - Handle the specified top-level declaration.  This is
comment|/// called by the parser to process every top-level Decl*. Note that D can be
comment|/// the head of a chain of Decls (e.g. for `int a, b` the chain will have two
comment|/// elements). Use Decl::getNextDeclarator() to walk the chain.
name|virtual
name|void
name|HandleTopLevelDecl
argument_list|(
argument|DeclGroupRef D
argument_list|)
expr_stmt|;
comment|/// HandleTranslationUnit - This method is called when the ASTs for entire
comment|/// translation unit have been parsed.
name|virtual
name|void
name|HandleTranslationUnit
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
block|{}
comment|/// HandleTagDeclDefinition - This callback is invoked each time a TagDecl
comment|/// (e.g. struct, union, enum, class) is completed.  This allows the client to
comment|/// hack on the type, which can occur at any point in the file (because these
comment|/// can be defined in declspecs).
name|virtual
name|void
name|HandleTagDeclDefinition
parameter_list|(
name|TagDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// CompleteTentativeDefinition - Callback invoked at the end of a translation
comment|/// unit to notify the consumer that the given tentative definition should be
comment|/// completed.
comment|///
comment|/// The variable declaration itself will be a tentative
comment|/// definition. If it had an incomplete array type, its type will
comment|/// have already been changed to an array of size 1. However, the
comment|/// declaration remains a tentative definition and has not been
comment|/// modified by the introduction of an implicit zero initializer.
name|virtual
name|void
name|CompleteTentativeDefinition
parameter_list|(
name|VarDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// PrintStats - If desired, print any statistics.
name|virtual
name|void
name|PrintStats
parameter_list|()
block|{}
comment|// Support isa/cast/dyn_cast
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|ASTConsumer
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

