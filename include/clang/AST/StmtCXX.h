begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- StmtCXX.h - Classes for representing C++ statements ----*- C++ -*-===//
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
comment|// This file defines the C++ statement AST node classes.
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
name|LLVM_CLANG_AST_STMTCXX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_STMTCXX_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|VarDecl
decl_stmt|;
comment|/// CXXCatchStmt - This represents a C++ catch block.
comment|///
name|class
name|CXXCatchStmt
range|:
name|public
name|Stmt
block|{
name|SourceLocation
name|CatchLoc
block|;
comment|/// The exception-declaration of the type.
name|VarDecl
operator|*
name|ExceptionDecl
block|;
comment|/// The handler block.
name|Stmt
operator|*
name|HandlerBlock
block|;
name|protected
operator|:
name|virtual
name|void
name|DoDestroy
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
block|;
name|public
operator|:
name|CXXCatchStmt
argument_list|(
argument|SourceLocation catchLoc
argument_list|,
argument|VarDecl *exDecl
argument_list|,
argument|Stmt *handlerBlock
argument_list|)
operator|:
name|Stmt
argument_list|(
name|CXXCatchStmtClass
argument_list|)
block|,
name|CatchLoc
argument_list|(
name|catchLoc
argument_list|)
block|,
name|ExceptionDecl
argument_list|(
name|exDecl
argument_list|)
block|,
name|HandlerBlock
argument_list|(
argument|handlerBlock
argument_list|)
block|{}
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|CatchLoc
argument_list|,
name|HandlerBlock
operator|->
name|getLocEnd
argument_list|()
argument_list|)
return|;
block|}
name|SourceLocation
name|getCatchLoc
argument_list|()
specifier|const
block|{
return|return
name|CatchLoc
return|;
block|}
name|VarDecl
operator|*
name|getExceptionDecl
argument_list|()
specifier|const
block|{
return|return
name|ExceptionDecl
return|;
block|}
name|QualType
name|getCaughtType
argument_list|()
specifier|const
block|;
name|Stmt
operator|*
name|getHandlerBlock
argument_list|()
specifier|const
block|{
return|return
name|HandlerBlock
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|CXXCatchStmtClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXCatchStmt *
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|virtual
name|child_iterator
name|child_begin
argument_list|()
block|;
name|virtual
name|child_iterator
name|child_end
argument_list|()
block|; }
decl_stmt|;
comment|/// CXXTryStmt - A C++ try block, including all handlers.
comment|///
name|class
name|CXXTryStmt
range|:
name|public
name|Stmt
block|{
name|SourceLocation
name|TryLoc
block|;
comment|// First place is the guarded CompoundStatement. Subsequent are the handlers.
comment|// More than three handlers should be rare.
name|llvm
operator|::
name|SmallVector
operator|<
name|Stmt
operator|*
block|,
literal|4
operator|>
name|Stmts
block|;
name|public
operator|:
name|CXXTryStmt
argument_list|(
argument|SourceLocation tryLoc
argument_list|,
argument|Stmt *tryBlock
argument_list|,
argument|Stmt **handlers
argument_list|,
argument|unsigned numHandlers
argument_list|)
block|;
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|getTryLoc
argument_list|()
argument_list|,
name|getEndLoc
argument_list|()
argument_list|)
return|;
block|}
name|SourceLocation
name|getTryLoc
argument_list|()
specifier|const
block|{
return|return
name|TryLoc
return|;
block|}
name|SourceLocation
name|getEndLoc
argument_list|()
specifier|const
block|{
return|return
name|Stmts
operator|.
name|back
argument_list|()
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
name|CompoundStmt
operator|*
name|getTryBlock
argument_list|()
block|{
return|return
name|llvm
operator|::
name|cast
operator|<
name|CompoundStmt
operator|>
operator|(
name|Stmts
index|[
literal|0
index|]
operator|)
return|;
block|}
specifier|const
name|CompoundStmt
operator|*
name|getTryBlock
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|cast
operator|<
name|CompoundStmt
operator|>
operator|(
name|Stmts
index|[
literal|0
index|]
operator|)
return|;
block|}
name|unsigned
name|getNumHandlers
argument_list|()
specifier|const
block|{
return|return
name|Stmts
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
name|CXXCatchStmt
operator|*
name|getHandler
argument_list|(
argument|unsigned i
argument_list|)
block|{
return|return
name|llvm
operator|::
name|cast
operator|<
name|CXXCatchStmt
operator|>
operator|(
name|Stmts
index|[
name|i
operator|+
literal|1
index|]
operator|)
return|;
block|}
specifier|const
name|CXXCatchStmt
operator|*
name|getHandler
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|llvm
operator|::
name|cast
operator|<
name|CXXCatchStmt
operator|>
operator|(
name|Stmts
index|[
name|i
operator|+
literal|1
index|]
operator|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|CXXTryStmtClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXTryStmt *
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|virtual
name|child_iterator
name|child_begin
argument_list|()
block|;
name|virtual
name|child_iterator
name|child_end
argument_list|()
block|; }
decl_stmt|;
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

