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
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/NestedNameSpecifier.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
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
name|CXXCatchStmt
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Stmt
argument_list|(
name|CXXCatchStmtClass
argument_list|)
block|,
name|ExceptionDecl
argument_list|(
literal|0
argument_list|)
block|,
name|HandlerBlock
argument_list|(
literal|0
argument_list|)
block|{}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|CatchLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|HandlerBlock
operator|->
name|getLocEnd
argument_list|()
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
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|&
name|HandlerBlock
argument_list|,
operator|&
name|HandlerBlock
operator|+
literal|1
argument_list|)
return|;
block|}
name|friend
name|class
name|ASTStmtReader
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
name|unsigned
name|NumHandlers
block|;
name|CXXTryStmt
argument_list|(
argument|SourceLocation tryLoc
argument_list|,
argument|Stmt *tryBlock
argument_list|,
argument|ArrayRef<Stmt*> handlers
argument_list|)
block|;
name|CXXTryStmt
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|unsigned numHandlers
argument_list|)
operator|:
name|Stmt
argument_list|(
name|CXXTryStmtClass
argument_list|)
block|,
name|NumHandlers
argument_list|(
argument|numHandlers
argument_list|)
block|{ }
name|Stmt
specifier|const
operator|*
specifier|const
operator|*
name|getStmts
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|Stmt
specifier|const
operator|*
specifier|const
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|Stmt
operator|*
operator|*
name|getStmts
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|public
operator|:
specifier|static
name|CXXTryStmt
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation tryLoc
argument_list|,
argument|Stmt *tryBlock
argument_list|,
argument|ArrayRef<Stmt*> handlers
argument_list|)
block|;
specifier|static
name|CXXTryStmt
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|EmptyShell Empty
argument_list|,
argument|unsigned numHandlers
argument_list|)
block|;
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getTryLoc
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getEndLoc
argument_list|()
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
name|getStmts
argument_list|()
index|[
name|NumHandlers
index|]
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
name|cast
operator|<
name|CompoundStmt
operator|>
operator|(
name|getStmts
argument_list|()
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
name|cast
operator|<
name|CompoundStmt
operator|>
operator|(
name|getStmts
argument_list|()
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
name|NumHandlers
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
name|cast
operator|<
name|CXXCatchStmt
operator|>
operator|(
name|getStmts
argument_list|()
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
name|cast
operator|<
name|CXXCatchStmt
operator|>
operator|(
name|getStmts
argument_list|()
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
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|getStmts
argument_list|()
argument_list|,
name|getStmts
argument_list|()
operator|+
name|getNumHandlers
argument_list|()
operator|+
literal|1
argument_list|)
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|; }
decl_stmt|;
comment|/// CXXForRangeStmt - This represents C++0x [stmt.ranged]'s ranged for
comment|/// statement, represented as 'for (range-declarator : range-expression)'.
comment|///
comment|/// This is stored in a partially-desugared form to allow full semantic
comment|/// analysis of the constituent components. The original syntactic components
comment|/// can be extracted using getLoopVariable and getRangeInit.
name|class
name|CXXForRangeStmt
range|:
name|public
name|Stmt
block|{   enum
block|{
name|RANGE
block|,
name|BEGINEND
block|,
name|COND
block|,
name|INC
block|,
name|LOOPVAR
block|,
name|BODY
block|,
name|END
block|}
block|;
comment|// SubExprs[RANGE] is an expression or declstmt.
comment|// SubExprs[COND] and SubExprs[INC] are expressions.
name|Stmt
operator|*
name|SubExprs
index|[
name|END
index|]
block|;
name|SourceLocation
name|ForLoc
block|;
name|SourceLocation
name|ColonLoc
block|;
name|SourceLocation
name|RParenLoc
block|;
name|public
operator|:
name|CXXForRangeStmt
argument_list|(
argument|DeclStmt *Range
argument_list|,
argument|DeclStmt *BeginEnd
argument_list|,
argument|Expr *Cond
argument_list|,
argument|Expr *Inc
argument_list|,
argument|DeclStmt *LoopVar
argument_list|,
argument|Stmt *Body
argument_list|,
argument|SourceLocation FL
argument_list|,
argument|SourceLocation CL
argument_list|,
argument|SourceLocation RPL
argument_list|)
block|;
name|CXXForRangeStmt
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Stmt
argument_list|(
argument|CXXForRangeStmtClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|VarDecl
operator|*
name|getLoopVariable
argument_list|()
block|;
name|Expr
operator|*
name|getRangeInit
argument_list|()
block|;
specifier|const
name|VarDecl
operator|*
name|getLoopVariable
argument_list|()
specifier|const
block|;
specifier|const
name|Expr
operator|*
name|getRangeInit
argument_list|()
specifier|const
block|;
name|DeclStmt
operator|*
name|getRangeStmt
argument_list|()
block|{
return|return
name|cast
operator|<
name|DeclStmt
operator|>
operator|(
name|SubExprs
index|[
name|RANGE
index|]
operator|)
return|;
block|}
name|DeclStmt
operator|*
name|getBeginEndStmt
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|DeclStmt
operator|>
operator|(
name|SubExprs
index|[
name|BEGINEND
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getCond
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|COND
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getInc
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|INC
index|]
operator|)
return|;
block|}
name|DeclStmt
operator|*
name|getLoopVarStmt
argument_list|()
block|{
return|return
name|cast
operator|<
name|DeclStmt
operator|>
operator|(
name|SubExprs
index|[
name|LOOPVAR
index|]
operator|)
return|;
block|}
name|Stmt
operator|*
name|getBody
argument_list|()
block|{
return|return
name|SubExprs
index|[
name|BODY
index|]
return|;
block|}
specifier|const
name|DeclStmt
operator|*
name|getRangeStmt
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|DeclStmt
operator|>
operator|(
name|SubExprs
index|[
name|RANGE
index|]
operator|)
return|;
block|}
specifier|const
name|DeclStmt
operator|*
name|getBeginEndStmt
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|DeclStmt
operator|>
operator|(
name|SubExprs
index|[
name|BEGINEND
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getCond
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|COND
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getInc
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|INC
index|]
operator|)
return|;
block|}
specifier|const
name|DeclStmt
operator|*
name|getLoopVarStmt
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|DeclStmt
operator|>
operator|(
name|SubExprs
index|[
name|LOOPVAR
index|]
operator|)
return|;
block|}
specifier|const
name|Stmt
operator|*
name|getBody
argument_list|()
specifier|const
block|{
return|return
name|SubExprs
index|[
name|BODY
index|]
return|;
block|}
name|void
name|setRangeInit
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|RANGE
index|]
operator|=
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
name|E
operator|)
block|; }
name|void
name|setRangeStmt
argument_list|(
argument|Stmt *S
argument_list|)
block|{
name|SubExprs
index|[
name|RANGE
index|]
operator|=
name|S
block|; }
name|void
name|setBeginEndStmt
argument_list|(
argument|Stmt *S
argument_list|)
block|{
name|SubExprs
index|[
name|BEGINEND
index|]
operator|=
name|S
block|; }
name|void
name|setCond
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|COND
index|]
operator|=
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
name|E
operator|)
block|; }
name|void
name|setInc
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|INC
index|]
operator|=
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
name|E
operator|)
block|; }
name|void
name|setLoopVarStmt
argument_list|(
argument|Stmt *S
argument_list|)
block|{
name|SubExprs
index|[
name|LOOPVAR
index|]
operator|=
name|S
block|; }
name|void
name|setBody
argument_list|(
argument|Stmt *S
argument_list|)
block|{
name|SubExprs
index|[
name|BODY
index|]
operator|=
name|S
block|; }
name|SourceLocation
name|getForLoc
argument_list|()
specifier|const
block|{
return|return
name|ForLoc
return|;
block|}
name|void
name|setForLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|ForLoc
operator|=
name|Loc
block|; }
name|SourceLocation
name|getColonLoc
argument_list|()
specifier|const
block|{
return|return
name|ColonLoc
return|;
block|}
name|void
name|setColonLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|ColonLoc
operator|=
name|Loc
block|; }
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
name|void
name|setRParenLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|RParenLoc
operator|=
name|Loc
block|; }
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|ForLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SubExprs
index|[
name|BODY
index|]
operator|->
name|getLocEnd
argument_list|()
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
name|CXXForRangeStmtClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|&
name|SubExprs
index|[
literal|0
index|]
argument_list|,
operator|&
name|SubExprs
index|[
name|END
index|]
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief Representation of a Microsoft __if_exists or __if_not_exists
comment|/// statement with a dependent name.
comment|///
comment|/// The __if_exists statement can be used to include a sequence of statements
comment|/// in the program only when a particular dependent name does not exist. For
comment|/// example:
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// void call_foo(T&t) {
comment|///   __if_exists (T::foo) {
comment|///     t.foo(); // okay: only called when T::foo exists.
comment|///   }
comment|/// }
comment|/// \endcode
comment|///
comment|/// Similarly, the __if_not_exists statement can be used to include the
comment|/// statements when a particular name does not exist.
comment|///
comment|/// Note that this statement only captures __if_exists and __if_not_exists
comment|/// statements whose name is dependent. All non-dependent cases are handled
comment|/// directly in the parser, so that they don't introduce a new scope. Clang
comment|/// introduces scopes in the dependent case to keep names inside the compound
comment|/// statement from leaking out into the surround statements, which would
comment|/// compromise the template instantiation model. This behavior differs from
comment|/// Visual C++ (which never introduces a scope), but is a fairly reasonable
comment|/// approximation of the VC++ behavior.
name|class
name|MSDependentExistsStmt
operator|:
name|public
name|Stmt
block|{
name|SourceLocation
name|KeywordLoc
block|;
name|bool
name|IsIfExists
block|;
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
name|DeclarationNameInfo
name|NameInfo
block|;
name|Stmt
operator|*
name|SubStmt
block|;
name|friend
name|class
name|ASTReader
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
name|MSDependentExistsStmt
argument_list|(
argument|SourceLocation KeywordLoc
argument_list|,
argument|bool IsIfExists
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|DeclarationNameInfo NameInfo
argument_list|,
argument|CompoundStmt *SubStmt
argument_list|)
operator|:
name|Stmt
argument_list|(
name|MSDependentExistsStmtClass
argument_list|)
block|,
name|KeywordLoc
argument_list|(
name|KeywordLoc
argument_list|)
block|,
name|IsIfExists
argument_list|(
name|IsIfExists
argument_list|)
block|,
name|QualifierLoc
argument_list|(
name|QualifierLoc
argument_list|)
block|,
name|NameInfo
argument_list|(
name|NameInfo
argument_list|)
block|,
name|SubStmt
argument_list|(
argument|reinterpret_cast<Stmt *>(SubStmt)
argument_list|)
block|{ }
comment|/// \brief Retrieve the location of the __if_exists or __if_not_exists
comment|/// keyword.
name|SourceLocation
name|getKeywordLoc
argument_list|()
specifier|const
block|{
return|return
name|KeywordLoc
return|;
block|}
comment|/// \brief Determine whether this is an __if_exists statement.
name|bool
name|isIfExists
argument_list|()
specifier|const
block|{
return|return
name|IsIfExists
return|;
block|}
comment|/// \brief Determine whether this is an __if_exists statement.
name|bool
name|isIfNotExists
argument_list|()
specifier|const
block|{
return|return
operator|!
name|IsIfExists
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies this name, if
comment|/// any.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief Retrieve the name of the entity we're testing for, along with
comment|/// location information
name|DeclarationNameInfo
name|getNameInfo
argument_list|()
specifier|const
block|{
return|return
name|NameInfo
return|;
block|}
comment|/// \brief Retrieve the compound statement that will be included in the
comment|/// program only if the existence of the symbol matches the initial keyword.
name|CompoundStmt
operator|*
name|getSubStmt
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|CompoundStmt
operator|*
operator|>
operator|(
name|SubStmt
operator|)
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|KeywordLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SubStmt
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|&
name|SubStmt
argument_list|,
operator|&
name|SubStmt
operator|+
literal|1
argument_list|)
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
name|MSDependentExistsStmtClass
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

