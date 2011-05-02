begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ExprCXX.h - Classes for representing expressions -------*- C++ -*-===//
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
comment|//  This file defines the Expr interface and subclasses for C++ expressions.
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
name|LLVM_CLANG_AST_EXPRCXX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_EXPRCXX_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/TypeTraits.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ExpressionTraits.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/UnresolvedSet.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateBase.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXConstructorDecl
decl_stmt|;
name|class
name|CXXDestructorDecl
decl_stmt|;
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|CXXTemporary
decl_stmt|;
name|class
name|TemplateArgumentListInfo
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// C++ Expressions.
comment|//===--------------------------------------------------------------------===//
comment|/// \brief A call to an overloaded operator written using operator
comment|/// syntax.
comment|///
comment|/// Represents a call to an overloaded operator written using operator
comment|/// syntax, e.g., "x + y" or "*p". While semantically equivalent to a
comment|/// normal call, this AST node provides better information about the
comment|/// syntactic representation of the call.
comment|///
comment|/// In a C++ template, this expression node kind will be used whenever
comment|/// any of the arguments are type-dependent. In this case, the
comment|/// function itself will be a (possibly empty) set of functions and
comment|/// function templates that were found by name lookup at template
comment|/// definition time.
name|class
name|CXXOperatorCallExpr
range|:
name|public
name|CallExpr
block|{
comment|/// \brief The overloaded operator.
name|OverloadedOperatorKind
name|Operator
block|;
name|public
operator|:
name|CXXOperatorCallExpr
argument_list|(
argument|ASTContext& C
argument_list|,
argument|OverloadedOperatorKind Op
argument_list|,
argument|Expr *fn
argument_list|,
argument|Expr **args
argument_list|,
argument|unsigned numargs
argument_list|,
argument|QualType t
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation operatorloc
argument_list|)
operator|:
name|CallExpr
argument_list|(
name|C
argument_list|,
name|CXXOperatorCallExprClass
argument_list|,
name|fn
argument_list|,
literal|0
argument_list|,
name|args
argument_list|,
name|numargs
argument_list|,
name|t
argument_list|,
name|VK
argument_list|,
name|operatorloc
argument_list|)
block|,
name|Operator
argument_list|(
argument|Op
argument_list|)
block|{}
name|explicit
name|CXXOperatorCallExpr
argument_list|(
argument|ASTContext& C
argument_list|,
argument|EmptyShell Empty
argument_list|)
operator|:
name|CallExpr
argument_list|(
argument|C
argument_list|,
argument|CXXOperatorCallExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// getOperator - Returns the kind of overloaded operator that this
comment|/// expression refers to.
name|OverloadedOperatorKind
name|getOperator
argument_list|()
specifier|const
block|{
return|return
name|Operator
return|;
block|}
name|void
name|setOperator
argument_list|(
argument|OverloadedOperatorKind Kind
argument_list|)
block|{
name|Operator
operator|=
name|Kind
block|; }
comment|/// getOperatorLoc - Returns the location of the operator symbol in
comment|/// the expression. When @c getOperator()==OO_Call, this is the
comment|/// location of the right parentheses; when @c
comment|/// getOperator()==OO_Subscript, this is the location of the right
comment|/// bracket.
name|SourceLocation
name|getOperatorLoc
argument_list|()
specifier|const
block|{
return|return
name|getRParenLoc
argument_list|()
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|;
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
name|CXXOperatorCallExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXOperatorCallExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// CXXMemberCallExpr - Represents a call to a member function that
comment|/// may be written either with member call syntax (e.g., "obj.func()"
comment|/// or "objptr->func()") or with normal function-call syntax
comment|/// ("func()") within a member function that ends up calling a member
comment|/// function. The callee in either case is a MemberExpr that contains
comment|/// both the object argument and the member function, while the
comment|/// arguments are the arguments within the parentheses (not including
comment|/// the object argument).
name|class
name|CXXMemberCallExpr
operator|:
name|public
name|CallExpr
block|{
name|public
operator|:
name|CXXMemberCallExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr *fn
argument_list|,
argument|Expr **args
argument_list|,
argument|unsigned numargs
argument_list|,
argument|QualType t
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation RP
argument_list|)
operator|:
name|CallExpr
argument_list|(
argument|C
argument_list|,
argument|CXXMemberCallExprClass
argument_list|,
argument|fn
argument_list|,
literal|0
argument_list|,
argument|args
argument_list|,
argument|numargs
argument_list|,
argument|t
argument_list|,
argument|VK
argument_list|,
argument|RP
argument_list|)
block|{}
name|CXXMemberCallExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|EmptyShell Empty
argument_list|)
operator|:
name|CallExpr
argument_list|(
argument|C
argument_list|,
argument|CXXMemberCallExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// getImplicitObjectArgument - Retrieves the implicit object
comment|/// argument for the member call. For example, in "x.f(5)", this
comment|/// operation would return "x".
name|Expr
operator|*
name|getImplicitObjectArgument
argument_list|()
specifier|const
block|;
comment|/// Retrieves the declaration of the called method.
name|CXXMethodDecl
operator|*
name|getMethodDecl
argument_list|()
specifier|const
block|;
comment|/// getRecordDecl - Retrieves the CXXRecordDecl for the underlying type of
comment|/// the implicit object argument. Note that this is may not be the same
comment|/// declaration as that of the class context of the CXXMethodDecl which this
comment|/// function is calling.
comment|/// FIXME: Returns 0 for member pointer call exprs.
name|CXXRecordDecl
operator|*
name|getRecordDecl
argument_list|()
block|;
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
name|CXXMemberCallExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXMemberCallExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// CUDAKernelCallExpr - Represents a call to a CUDA kernel function.
name|class
name|CUDAKernelCallExpr
operator|:
name|public
name|CallExpr
block|{
name|private
operator|:
expr|enum
block|{
name|CONFIG
block|,
name|END_PREARG
block|}
block|;
name|public
operator|:
name|CUDAKernelCallExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr *fn
argument_list|,
argument|CallExpr *Config
argument_list|,
argument|Expr **args
argument_list|,
argument|unsigned numargs
argument_list|,
argument|QualType t
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation RP
argument_list|)
operator|:
name|CallExpr
argument_list|(
argument|C
argument_list|,
argument|CUDAKernelCallExprClass
argument_list|,
argument|fn
argument_list|,
argument|END_PREARG
argument_list|,
argument|args
argument_list|,
argument|numargs
argument_list|,
argument|t
argument_list|,
argument|VK
argument_list|,
argument|RP
argument_list|)
block|{
name|setConfig
argument_list|(
name|Config
argument_list|)
block|;   }
name|CUDAKernelCallExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|EmptyShell Empty
argument_list|)
operator|:
name|CallExpr
argument_list|(
argument|C
argument_list|,
argument|CUDAKernelCallExprClass
argument_list|,
argument|END_PREARG
argument_list|,
argument|Empty
argument_list|)
block|{ }
specifier|const
name|CallExpr
operator|*
name|getConfig
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|CallExpr
operator|>
operator|(
name|getPreArg
argument_list|(
name|CONFIG
argument_list|)
operator|)
return|;
block|}
name|CallExpr
operator|*
name|getConfig
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|CallExpr
operator|>
operator|(
name|getPreArg
argument_list|(
name|CONFIG
argument_list|)
operator|)
return|;
block|}
name|void
name|setConfig
argument_list|(
argument|CallExpr *E
argument_list|)
block|{
name|setPreArg
argument_list|(
name|CONFIG
argument_list|,
name|E
argument_list|)
block|; }
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
name|CUDAKernelCallExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CUDAKernelCallExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// CXXNamedCastExpr - Abstract class common to all of the C++ "named"
comment|/// casts, @c static_cast, @c dynamic_cast, @c reinterpret_cast, or @c
comment|/// const_cast.
comment|///
comment|/// This abstract class is inherited by all of the classes
comment|/// representing "named" casts, e.g., CXXStaticCastExpr,
comment|/// CXXDynamicCastExpr, CXXReinterpretCastExpr, and CXXConstCastExpr.
name|class
name|CXXNamedCastExpr
operator|:
name|public
name|ExplicitCastExpr
block|{
name|private
operator|:
name|SourceLocation
name|Loc
block|;
comment|// the location of the casting op
name|SourceLocation
name|RParenLoc
block|;
comment|// the location of the right parenthesis
name|protected
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|QualType ty
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|unsigned PathSize
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation l
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
name|SC
argument_list|,
name|ty
argument_list|,
name|VK
argument_list|,
name|kind
argument_list|,
name|op
argument_list|,
name|PathSize
argument_list|,
name|writtenTy
argument_list|)
block|,
name|Loc
argument_list|(
name|l
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|RParenLoc
argument_list|)
block|{}
name|explicit
name|CXXNamedCastExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|EmptyShell Shell
argument_list|,
argument|unsigned PathSize
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
argument|SC
argument_list|,
argument|Shell
argument_list|,
argument|PathSize
argument_list|)
block|{ }
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
specifier|const
name|char
operator|*
name|getCastName
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve the location of the cast operator keyword, e.g.,
comment|/// "static_cast".
name|SourceLocation
name|getOperatorLoc
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
comment|/// \brief Retrieve the location of the closing parenthesis.
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|,
name|RParenLoc
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
switch|switch
condition|(
name|T
operator|->
name|getStmtClass
argument_list|()
condition|)
block|{
case|case
name|CXXStaticCastExprClass
case|:
case|case
name|CXXDynamicCastExprClass
case|:
case|case
name|CXXReinterpretCastExprClass
case|:
case|case
name|CXXConstCastExprClass
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXNamedCastExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// CXXStaticCastExpr - A C++ @c static_cast expression (C++ [expr.static.cast]).
comment|///
comment|/// This expression node represents a C++ static cast, e.g.,
comment|/// @c static_cast<int>(1.0).
name|class
name|CXXStaticCastExpr
operator|:
name|public
name|CXXNamedCastExpr
block|{
name|CXXStaticCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|ExprValueKind vk
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|unsigned pathSize
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation l
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXStaticCastExprClass
argument_list|,
argument|ty
argument_list|,
argument|vk
argument_list|,
argument|kind
argument_list|,
argument|op
argument_list|,
argument|pathSize
argument_list|,
argument|writtenTy
argument_list|,
argument|l
argument_list|,
argument|RParenLoc
argument_list|)
block|{}
name|explicit
name|CXXStaticCastExpr
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|unsigned PathSize
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXStaticCastExprClass
argument_list|,
argument|Empty
argument_list|,
argument|PathSize
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|CXXStaticCastExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|CastKind K
argument_list|,
argument|Expr *Op
argument_list|,
argument|const CXXCastPath *Path
argument_list|,
argument|TypeSourceInfo *Written
argument_list|,
argument|SourceLocation L
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|;
specifier|static
name|CXXStaticCastExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|unsigned PathSize
argument_list|)
block|;
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
name|CXXStaticCastExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXStaticCastExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// CXXDynamicCastExpr - A C++ @c dynamic_cast expression
comment|/// (C++ [expr.dynamic.cast]), which may perform a run-time check to
comment|/// determine how to perform the type cast.
comment|///
comment|/// This expression node represents a dynamic cast, e.g.,
comment|/// @c dynamic_cast<Derived*>(BasePtr).
name|class
name|CXXDynamicCastExpr
operator|:
name|public
name|CXXNamedCastExpr
block|{
name|CXXDynamicCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|unsigned pathSize
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation l
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXDynamicCastExprClass
argument_list|,
argument|ty
argument_list|,
argument|VK
argument_list|,
argument|kind
argument_list|,
argument|op
argument_list|,
argument|pathSize
argument_list|,
argument|writtenTy
argument_list|,
argument|l
argument_list|,
argument|RParenLoc
argument_list|)
block|{}
name|explicit
name|CXXDynamicCastExpr
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|unsigned pathSize
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXDynamicCastExprClass
argument_list|,
argument|Empty
argument_list|,
argument|pathSize
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|CXXDynamicCastExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|CastKind Kind
argument_list|,
argument|Expr *Op
argument_list|,
argument|const CXXCastPath *Path
argument_list|,
argument|TypeSourceInfo *Written
argument_list|,
argument|SourceLocation L
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|;
specifier|static
name|CXXDynamicCastExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|unsigned pathSize
argument_list|)
block|;
name|bool
name|isAlwaysNull
argument_list|()
specifier|const
block|;
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
name|CXXDynamicCastExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXDynamicCastExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// CXXReinterpretCastExpr - A C++ @c reinterpret_cast expression (C++
comment|/// [expr.reinterpret.cast]), which provides a differently-typed view
comment|/// of a value but performs no actual work at run time.
comment|///
comment|/// This expression node represents a reinterpret cast, e.g.,
comment|/// @c reinterpret_cast<int>(VoidPtr).
name|class
name|CXXReinterpretCastExpr
operator|:
name|public
name|CXXNamedCastExpr
block|{
name|CXXReinterpretCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|ExprValueKind vk
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|unsigned pathSize
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation l
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXReinterpretCastExprClass
argument_list|,
argument|ty
argument_list|,
argument|vk
argument_list|,
argument|kind
argument_list|,
argument|op
argument_list|,
argument|pathSize
argument_list|,
argument|writtenTy
argument_list|,
argument|l
argument_list|,
argument|RParenLoc
argument_list|)
block|{}
name|CXXReinterpretCastExpr
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|unsigned pathSize
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXReinterpretCastExprClass
argument_list|,
argument|Empty
argument_list|,
argument|pathSize
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|CXXReinterpretCastExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|CastKind Kind
argument_list|,
argument|Expr *Op
argument_list|,
argument|const CXXCastPath *Path
argument_list|,
argument|TypeSourceInfo *WrittenTy
argument_list|,
argument|SourceLocation L
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|;
specifier|static
name|CXXReinterpretCastExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|unsigned pathSize
argument_list|)
block|;
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
name|CXXReinterpretCastExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXReinterpretCastExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// CXXConstCastExpr - A C++ @c const_cast expression (C++ [expr.const.cast]),
comment|/// which can remove type qualifiers but does not change the underlying value.
comment|///
comment|/// This expression node represents a const cast, e.g.,
comment|/// @c const_cast<char*>(PtrToConstChar).
name|class
name|CXXConstCastExpr
operator|:
name|public
name|CXXNamedCastExpr
block|{
name|CXXConstCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|Expr *op
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation l
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXConstCastExprClass
argument_list|,
argument|ty
argument_list|,
argument|VK
argument_list|,
argument|CK_NoOp
argument_list|,
argument|op
argument_list|,
literal|0
argument_list|,
argument|writtenTy
argument_list|,
argument|l
argument_list|,
argument|RParenLoc
argument_list|)
block|{}
name|explicit
name|CXXConstCastExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXConstCastExprClass
argument_list|,
argument|Empty
argument_list|,
literal|0
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|CXXConstCastExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|Expr *Op
argument_list|,
argument|TypeSourceInfo *WrittenTy
argument_list|,
argument|SourceLocation L
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|;
specifier|static
name|CXXConstCastExpr
operator|*
name|CreateEmpty
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
block|;
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
name|CXXConstCastExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXConstCastExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// CXXBoolLiteralExpr - [C++ 2.13.5] C++ Boolean Literal.
comment|///
name|class
name|CXXBoolLiteralExpr
operator|:
name|public
name|Expr
block|{
name|bool
name|Value
block|;
name|SourceLocation
name|Loc
block|;
name|public
operator|:
name|CXXBoolLiteralExpr
argument_list|(
argument|bool val
argument_list|,
argument|QualType Ty
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXBoolLiteralExprClass
argument_list|,
name|Ty
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Value
argument_list|(
name|val
argument_list|)
block|,
name|Loc
argument_list|(
argument|l
argument_list|)
block|{}
name|explicit
name|CXXBoolLiteralExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CXXBoolLiteralExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|bool
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
name|void
name|setValue
argument_list|(
argument|bool V
argument_list|)
block|{
name|Value
operator|=
name|V
block|; }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|)
return|;
block|}
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|void
name|setLocation
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|Loc
operator|=
name|L
block|; }
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
name|CXXBoolLiteralExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXBoolLiteralExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// CXXNullPtrLiteralExpr - [C++0x 2.14.7] C++ Pointer Literal
name|class
name|CXXNullPtrLiteralExpr
operator|:
name|public
name|Expr
block|{
name|SourceLocation
name|Loc
block|;
name|public
operator|:
name|CXXNullPtrLiteralExpr
argument_list|(
argument|QualType Ty
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXNullPtrLiteralExprClass
argument_list|,
name|Ty
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Loc
argument_list|(
argument|l
argument_list|)
block|{}
name|explicit
name|CXXNullPtrLiteralExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CXXNullPtrLiteralExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|)
return|;
block|}
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|void
name|setLocation
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|Loc
operator|=
name|L
block|; }
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
name|CXXNullPtrLiteralExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXNullPtrLiteralExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// CXXTypeidExpr - A C++ @c typeid expression (C++ [expr.typeid]), which gets
comment|/// the type_info that corresponds to the supplied type, or the (possibly
comment|/// dynamic) type of the supplied expression.
comment|///
comment|/// This represents code like @c typeid(int) or @c typeid(*objPtr)
name|class
name|CXXTypeidExpr
operator|:
name|public
name|Expr
block|{
name|private
operator|:
name|llvm
operator|::
name|PointerUnion
operator|<
name|Stmt
operator|*
block|,
name|TypeSourceInfo
operator|*
operator|>
name|Operand
block|;
name|SourceRange
name|Range
block|;
name|public
operator|:
name|CXXTypeidExpr
argument_list|(
argument|QualType Ty
argument_list|,
argument|TypeSourceInfo *Operand
argument_list|,
argument|SourceRange R
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXTypeidExprClass
argument_list|,
name|Ty
argument_list|,
name|VK_LValue
argument_list|,
name|OK_Ordinary
argument_list|,
comment|// typeid is never type-dependent (C++ [temp.dep.expr]p4)
name|false
argument_list|,
comment|// typeid is value-dependent if the type or expression are dependent
name|Operand
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|Operand
operator|->
name|getType
argument_list|()
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Operand
argument_list|(
name|Operand
argument_list|)
block|,
name|Range
argument_list|(
argument|R
argument_list|)
block|{ }
name|CXXTypeidExpr
argument_list|(
argument|QualType Ty
argument_list|,
argument|Expr *Operand
argument_list|,
argument|SourceRange R
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXTypeidExprClass
argument_list|,
name|Ty
argument_list|,
name|VK_LValue
argument_list|,
name|OK_Ordinary
argument_list|,
comment|// typeid is never type-dependent (C++ [temp.dep.expr]p4)
name|false
argument_list|,
comment|// typeid is value-dependent if the type or expression are dependent
name|Operand
operator|->
name|isTypeDependent
argument_list|()
operator|||
name|Operand
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|Operand
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Operand
argument_list|(
name|Operand
argument_list|)
block|,
name|Range
argument_list|(
argument|R
argument_list|)
block|{ }
name|CXXTypeidExpr
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|bool isExpr
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CXXTypeidExprClass
argument_list|,
argument|Empty
argument_list|)
block|{
if|if
condition|(
name|isExpr
condition|)
name|Operand
operator|=
operator|(
name|Expr
operator|*
operator|)
literal|0
expr_stmt|;
else|else
name|Operand
operator|=
operator|(
name|TypeSourceInfo
operator|*
operator|)
literal|0
expr_stmt|;
block|}
name|bool
name|isTypeOperand
argument_list|()
specifier|const
block|{
return|return
name|Operand
operator|.
name|is
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Retrieves the type operand of this typeid() expression after
comment|/// various required adjustments (removing reference types, cv-qualifiers).
name|QualType
name|getTypeOperand
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve source information for the type operand.
name|TypeSourceInfo
operator|*
name|getTypeOperandSourceInfo
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isTypeOperand
argument_list|()
operator|&&
literal|"Cannot call getTypeOperand for typeid(expr)"
argument_list|)
block|;
return|return
name|Operand
operator|.
name|get
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|void
name|setTypeOperandSourceInfo
argument_list|(
argument|TypeSourceInfo *TSI
argument_list|)
block|{
name|assert
argument_list|(
name|isTypeOperand
argument_list|()
operator|&&
literal|"Cannot call getTypeOperand for typeid(expr)"
argument_list|)
block|;
name|Operand
operator|=
name|TSI
block|;   }
name|Expr
operator|*
name|getExprOperand
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isTypeOperand
argument_list|()
operator|&&
literal|"Cannot call getExprOperand for typeid(type)"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|Operand
operator|.
name|get
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
operator|)
return|;
block|}
name|void
name|setExprOperand
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|isTypeOperand
argument_list|()
operator|&&
literal|"Cannot call getExprOperand for typeid(type)"
argument_list|)
block|;
name|Operand
operator|=
name|E
block|;   }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|Range
return|;
block|}
name|void
name|setSourceRange
argument_list|(
argument|SourceRange R
argument_list|)
block|{
name|Range
operator|=
name|R
block|; }
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
name|CXXTypeidExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXTypeidExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
if|if
condition|(
name|isTypeOperand
argument_list|()
condition|)
return|return
name|child_range
argument_list|()
return|;
name|Stmt
operator|*
operator|*
name|begin
operator|=
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
operator|&
name|Operand
operator|)
block|;
return|return
name|child_range
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// CXXUuidofExpr - A microsoft C++ @c __uuidof expression, which gets
comment|/// the _GUID that corresponds to the supplied type or expression.
comment|///
comment|/// This represents code like @c __uuidof(COMTYPE) or @c __uuidof(*comPtr)
name|class
name|CXXUuidofExpr
operator|:
name|public
name|Expr
block|{
name|private
operator|:
name|llvm
operator|::
name|PointerUnion
operator|<
name|Stmt
operator|*
block|,
name|TypeSourceInfo
operator|*
operator|>
name|Operand
block|;
name|SourceRange
name|Range
block|;
name|public
operator|:
name|CXXUuidofExpr
argument_list|(
argument|QualType Ty
argument_list|,
argument|TypeSourceInfo *Operand
argument_list|,
argument|SourceRange R
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXUuidofExprClass
argument_list|,
name|Ty
argument_list|,
name|VK_LValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|Operand
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|Operand
operator|->
name|getType
argument_list|()
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Operand
argument_list|(
name|Operand
argument_list|)
block|,
name|Range
argument_list|(
argument|R
argument_list|)
block|{ }
name|CXXUuidofExpr
argument_list|(
argument|QualType Ty
argument_list|,
argument|Expr *Operand
argument_list|,
argument|SourceRange R
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXUuidofExprClass
argument_list|,
name|Ty
argument_list|,
name|VK_LValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|Operand
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|Operand
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Operand
argument_list|(
name|Operand
argument_list|)
block|,
name|Range
argument_list|(
argument|R
argument_list|)
block|{ }
name|CXXUuidofExpr
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|bool isExpr
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CXXUuidofExprClass
argument_list|,
argument|Empty
argument_list|)
block|{
if|if
condition|(
name|isExpr
condition|)
name|Operand
operator|=
operator|(
name|Expr
operator|*
operator|)
literal|0
expr_stmt|;
else|else
name|Operand
operator|=
operator|(
name|TypeSourceInfo
operator|*
operator|)
literal|0
expr_stmt|;
block|}
name|bool
name|isTypeOperand
argument_list|()
specifier|const
block|{
return|return
name|Operand
operator|.
name|is
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Retrieves the type operand of this __uuidof() expression after
comment|/// various required adjustments (removing reference types, cv-qualifiers).
name|QualType
name|getTypeOperand
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve source information for the type operand.
name|TypeSourceInfo
operator|*
name|getTypeOperandSourceInfo
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isTypeOperand
argument_list|()
operator|&&
literal|"Cannot call getTypeOperand for __uuidof(expr)"
argument_list|)
block|;
return|return
name|Operand
operator|.
name|get
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|void
name|setTypeOperandSourceInfo
argument_list|(
argument|TypeSourceInfo *TSI
argument_list|)
block|{
name|assert
argument_list|(
name|isTypeOperand
argument_list|()
operator|&&
literal|"Cannot call getTypeOperand for __uuidof(expr)"
argument_list|)
block|;
name|Operand
operator|=
name|TSI
block|;   }
name|Expr
operator|*
name|getExprOperand
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isTypeOperand
argument_list|()
operator|&&
literal|"Cannot call getExprOperand for __uuidof(type)"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|Operand
operator|.
name|get
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
operator|)
return|;
block|}
name|void
name|setExprOperand
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|isTypeOperand
argument_list|()
operator|&&
literal|"Cannot call getExprOperand for __uuidof(type)"
argument_list|)
block|;
name|Operand
operator|=
name|E
block|;   }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|Range
return|;
block|}
name|void
name|setSourceRange
argument_list|(
argument|SourceRange R
argument_list|)
block|{
name|Range
operator|=
name|R
block|; }
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
name|CXXUuidofExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXUuidofExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
if|if
condition|(
name|isTypeOperand
argument_list|()
condition|)
return|return
name|child_range
argument_list|()
return|;
name|Stmt
operator|*
operator|*
name|begin
operator|=
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
operator|&
name|Operand
operator|)
block|;
return|return
name|child_range
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// CXXThisExpr - Represents the "this" expression in C++, which is a
comment|/// pointer to the object on which the current member function is
comment|/// executing (C++ [expr.prim]p3). Example:
comment|///
comment|/// @code
comment|/// class Foo {
comment|/// public:
comment|///   void bar();
comment|///   void test() { this->bar(); }
comment|/// };
comment|/// @endcode
name|class
name|CXXThisExpr
operator|:
name|public
name|Expr
block|{
name|SourceLocation
name|Loc
block|;
name|bool
name|Implicit
operator|:
literal|1
block|;
name|public
operator|:
name|CXXThisExpr
argument_list|(
argument|SourceLocation L
argument_list|,
argument|QualType Type
argument_list|,
argument|bool isImplicit
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXThisExprClass
argument_list|,
name|Type
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
comment|// 'this' is type-dependent if the class type of the enclosing
comment|// member function is dependent (C++ [temp.dep.expr]p2)
name|Type
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|Type
operator|->
name|isDependentType
argument_list|()
argument_list|,
comment|/*ContainsUnexpandedParameterPack=*/
name|false
argument_list|)
block|,
name|Loc
argument_list|(
name|L
argument_list|)
block|,
name|Implicit
argument_list|(
argument|isImplicit
argument_list|)
block|{ }
name|CXXThisExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CXXThisExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|void
name|setLocation
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|Loc
operator|=
name|L
block|; }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|)
return|;
block|}
name|bool
name|isImplicit
argument_list|()
specifier|const
block|{
return|return
name|Implicit
return|;
block|}
name|void
name|setImplicit
argument_list|(
argument|bool I
argument_list|)
block|{
name|Implicit
operator|=
name|I
block|; }
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
name|CXXThisExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXThisExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
expr|}
block|;
comment|///  CXXThrowExpr - [C++ 15] C++ Throw Expression.  This handles
comment|///  'throw' and 'throw' assignment-expression.  When
comment|///  assignment-expression isn't present, Op will be null.
comment|///
name|class
name|CXXThrowExpr
operator|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|Op
block|;
name|SourceLocation
name|ThrowLoc
block|;
name|public
operator|:
comment|// Ty is the void type which is used as the result type of the
comment|// exepression.  The l is the location of the throw keyword.  expr
comment|// can by null, if the optional expression to throw isn't present.
name|CXXThrowExpr
argument_list|(
argument|Expr *expr
argument_list|,
argument|QualType Ty
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXThrowExprClass
argument_list|,
name|Ty
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|expr
operator|&&
name|expr
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Op
argument_list|(
name|expr
argument_list|)
block|,
name|ThrowLoc
argument_list|(
argument|l
argument_list|)
block|{}
name|CXXThrowExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CXXThrowExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
specifier|const
name|Expr
operator|*
name|getSubExpr
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|Op
operator|)
return|;
block|}
name|Expr
operator|*
name|getSubExpr
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|Op
operator|)
return|;
block|}
name|void
name|setSubExpr
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Op
operator|=
name|E
block|; }
name|SourceLocation
name|getThrowLoc
argument_list|()
specifier|const
block|{
return|return
name|ThrowLoc
return|;
block|}
name|void
name|setThrowLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|ThrowLoc
operator|=
name|L
block|; }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getSubExpr
argument_list|()
operator|==
literal|0
condition|)
return|return
name|SourceRange
argument_list|(
name|ThrowLoc
argument_list|,
name|ThrowLoc
argument_list|)
return|;
return|return
name|SourceRange
argument_list|(
name|ThrowLoc
argument_list|,
name|getSubExpr
argument_list|()
operator|->
name|getSourceRange
argument_list|()
operator|.
name|getEnd
argument_list|()
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
name|CXXThrowExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXThrowExpr *
argument_list|)
block|{
return|return
name|true
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
name|Op
argument_list|,
name|Op
operator|?
operator|&
name|Op
operator|+
literal|1
operator|:
operator|&
name|Op
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// CXXDefaultArgExpr - C++ [dcl.fct.default]. This wraps up a
comment|/// function call argument that was created from the corresponding
comment|/// parameter's default argument, when the call did not explicitly
comment|/// supply arguments for all of the parameters.
name|class
name|CXXDefaultArgExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The parameter whose default is being used.
comment|///
comment|/// When the bit is set, the subexpression is stored after the
comment|/// CXXDefaultArgExpr itself. When the bit is clear, the parameter's
comment|/// actual default expression is the subexpression.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|ParmVarDecl
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|Param
block|;
comment|/// \brief The location where the default argument expression was used.
name|SourceLocation
name|Loc
block|;
name|CXXDefaultArgExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|ParmVarDecl *param
argument_list|)
operator|:
name|Expr
argument_list|(
name|SC
argument_list|,
name|param
operator|->
name|hasUnparsedDefaultArg
argument_list|()
condition|?
name|param
operator|->
name|getType
argument_list|()
operator|.
name|getNonReferenceType
argument_list|()
else|:
name|param
operator|->
name|getDefaultArg
argument_list|()
operator|->
name|getType
argument_list|()
argument_list|,
name|param
operator|->
name|getDefaultArg
argument_list|()
operator|->
name|getValueKind
argument_list|()
argument_list|,
name|param
operator|->
name|getDefaultArg
argument_list|()
operator|->
name|getObjectKind
argument_list|()
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Param
argument_list|(
name|param
argument_list|,
name|false
argument_list|)
block|,
name|Loc
argument_list|(
argument|Loc
argument_list|)
block|{ }
name|CXXDefaultArgExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|ParmVarDecl *param
argument_list|,
argument|Expr *SubExpr
argument_list|)
operator|:
name|Expr
argument_list|(
name|SC
argument_list|,
name|SubExpr
operator|->
name|getType
argument_list|()
argument_list|,
name|SubExpr
operator|->
name|getValueKind
argument_list|()
argument_list|,
name|SubExpr
operator|->
name|getObjectKind
argument_list|()
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Param
argument_list|(
name|param
argument_list|,
name|true
argument_list|)
block|,
name|Loc
argument_list|(
argument|Loc
argument_list|)
block|{
operator|*
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
operator|=
name|SubExpr
block|;   }
name|public
operator|:
name|CXXDefaultArgExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CXXDefaultArgExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
comment|// Param is the parameter whose default argument is used by this
comment|// expression.
specifier|static
name|CXXDefaultArgExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|ParmVarDecl *Param
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|C
argument_list|)
name|CXXDefaultArgExpr
argument_list|(
name|CXXDefaultArgExprClass
argument_list|,
name|Loc
argument_list|,
name|Param
argument_list|)
return|;
block|}
comment|// Param is the parameter whose default argument is used by this
comment|// expression, and SubExpr is the expression that will actually be used.
specifier|static
name|CXXDefaultArgExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|ParmVarDecl *Param
argument_list|,
argument|Expr *SubExpr
argument_list|)
block|;
comment|// Retrieve the parameter that the argument was created from.
specifier|const
name|ParmVarDecl
operator|*
name|getParam
argument_list|()
specifier|const
block|{
return|return
name|Param
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|ParmVarDecl
operator|*
name|getParam
argument_list|()
block|{
return|return
name|Param
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|// Retrieve the actual argument to the function call.
specifier|const
name|Expr
operator|*
name|getExpr
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Param
operator|.
name|getInt
argument_list|()
condition|)
return|return
operator|*
name|reinterpret_cast
operator|<
name|Expr
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
return|return
name|getParam
argument_list|()
operator|->
name|getDefaultArg
argument_list|()
return|;
block|}
name|Expr
operator|*
name|getExpr
argument_list|()
block|{
if|if
condition|(
name|Param
operator|.
name|getInt
argument_list|()
condition|)
return|return
operator|*
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
return|return
name|getParam
argument_list|()
operator|->
name|getDefaultArg
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the location where this default argument was actually
comment|/// used.
name|SourceLocation
name|getUsedLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
comment|// Default argument expressions have no representation in the
comment|// source, so they have an empty source range.
return|return
name|SourceRange
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
name|CXXDefaultArgExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXDefaultArgExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|; }
block|;
comment|/// CXXTemporary - Represents a C++ temporary.
name|class
name|CXXTemporary
block|{
comment|/// Destructor - The destructor that needs to be called.
specifier|const
name|CXXDestructorDecl
operator|*
name|Destructor
block|;
name|CXXTemporary
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|destructor
argument_list|)
operator|:
name|Destructor
argument_list|(
argument|destructor
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|CXXTemporary
operator|*
name|Create
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|,
specifier|const
name|CXXDestructorDecl
operator|*
name|Destructor
argument_list|)
block|;
specifier|const
name|CXXDestructorDecl
operator|*
name|getDestructor
argument_list|()
specifier|const
block|{
return|return
name|Destructor
return|;
block|}
expr|}
block|;
comment|/// \brief Represents binding an expression to a temporary.
comment|///
comment|/// This ensures the destructor is called for the temporary. It should only be
comment|/// needed for non-POD, non-trivially destructable class types. For example:
comment|///
comment|/// \code
comment|///   struct S {
comment|///     S() { }  // User defined constructor makes S non-POD.
comment|///     ~S() { } // User defined destructor makes it non-trivial.
comment|///   };
comment|///   void test() {
comment|///     const S&s_ref = S(); // Requires a CXXBindTemporaryExpr.
comment|///   }
comment|/// \endcode
name|class
name|CXXBindTemporaryExpr
operator|:
name|public
name|Expr
block|{
name|CXXTemporary
operator|*
name|Temp
block|;
name|Stmt
operator|*
name|SubExpr
block|;
name|CXXBindTemporaryExpr
argument_list|(
name|CXXTemporary
operator|*
name|temp
argument_list|,
name|Expr
operator|*
name|SubExpr
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXBindTemporaryExprClass
argument_list|,
name|SubExpr
operator|->
name|getType
argument_list|()
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|SubExpr
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|SubExpr
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|SubExpr
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Temp
argument_list|(
name|temp
argument_list|)
block|,
name|SubExpr
argument_list|(
argument|SubExpr
argument_list|)
block|{ }
name|public
operator|:
name|CXXBindTemporaryExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXBindTemporaryExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|Temp
argument_list|(
literal|0
argument_list|)
block|,
name|SubExpr
argument_list|(
literal|0
argument_list|)
block|{}
specifier|static
name|CXXBindTemporaryExpr
operator|*
name|Create
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|,
name|CXXTemporary
operator|*
name|Temp
argument_list|,
name|Expr
operator|*
name|SubExpr
argument_list|)
block|;
name|CXXTemporary
operator|*
name|getTemporary
argument_list|()
block|{
return|return
name|Temp
return|;
block|}
specifier|const
name|CXXTemporary
operator|*
name|getTemporary
argument_list|()
specifier|const
block|{
return|return
name|Temp
return|;
block|}
name|void
name|setTemporary
argument_list|(
argument|CXXTemporary *T
argument_list|)
block|{
name|Temp
operator|=
name|T
block|; }
specifier|const
name|Expr
operator|*
name|getSubExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExpr
operator|)
return|;
block|}
name|Expr
operator|*
name|getSubExpr
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExpr
operator|)
return|;
block|}
name|void
name|setSubExpr
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExpr
operator|=
name|E
block|; }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SubExpr
operator|->
name|getSourceRange
argument_list|()
return|;
block|}
comment|// Implement isa/cast/dyncast/etc.
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
name|CXXBindTemporaryExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXBindTemporaryExpr *
argument_list|)
block|{
return|return
name|true
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
name|SubExpr
argument_list|,
operator|&
name|SubExpr
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// CXXConstructExpr - Represents a call to a C++ constructor.
name|class
name|CXXConstructExpr
operator|:
name|public
name|Expr
block|{
name|public
operator|:
expr|enum
name|ConstructionKind
block|{
name|CK_Complete
block|,
name|CK_NonVirtualBase
block|,
name|CK_VirtualBase
block|,
name|CK_Delegating
block|}
block|;
name|private
operator|:
name|CXXConstructorDecl
operator|*
name|Constructor
block|;
name|SourceLocation
name|Loc
block|;
name|SourceRange
name|ParenRange
block|;
name|bool
name|Elidable
operator|:
literal|1
block|;
name|bool
name|ZeroInitialization
operator|:
literal|1
block|;
name|unsigned
name|ConstructKind
operator|:
literal|2
block|;
name|Stmt
operator|*
operator|*
name|Args
block|;
name|unsigned
name|NumArgs
block|;
name|protected
operator|:
name|CXXConstructExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|StmtClass SC
argument_list|,
argument|QualType T
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|CXXConstructorDecl *d
argument_list|,
argument|bool elidable
argument_list|,
argument|Expr **args
argument_list|,
argument|unsigned numargs
argument_list|,
argument|bool ZeroInitialization = false
argument_list|,
argument|ConstructionKind ConstructKind = CK_Complete
argument_list|,
argument|SourceRange ParenRange = SourceRange()
argument_list|)
block|;
comment|/// \brief Construct an empty C++ construction expression.
name|CXXConstructExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|SC
argument_list|,
name|Empty
argument_list|)
block|,
name|Constructor
argument_list|(
literal|0
argument_list|)
block|,
name|Elidable
argument_list|(
literal|0
argument_list|)
block|,
name|ZeroInitialization
argument_list|(
literal|0
argument_list|)
block|,
name|ConstructKind
argument_list|(
literal|0
argument_list|)
block|,
name|Args
argument_list|(
literal|0
argument_list|)
block|,
name|NumArgs
argument_list|(
literal|0
argument_list|)
block|{ }
name|public
operator|:
comment|/// \brief Construct an empty C++ construction expression.
name|explicit
name|CXXConstructExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXConstructExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|Constructor
argument_list|(
literal|0
argument_list|)
block|,
name|Elidable
argument_list|(
literal|0
argument_list|)
block|,
name|ZeroInitialization
argument_list|(
literal|0
argument_list|)
block|,
name|ConstructKind
argument_list|(
literal|0
argument_list|)
block|,
name|Args
argument_list|(
literal|0
argument_list|)
block|,
name|NumArgs
argument_list|(
literal|0
argument_list|)
block|{ }
specifier|static
name|CXXConstructExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|QualType T
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|CXXConstructorDecl *D
argument_list|,
argument|bool Elidable
argument_list|,
argument|Expr **Args
argument_list|,
argument|unsigned NumArgs
argument_list|,
argument|bool ZeroInitialization = false
argument_list|,
argument|ConstructionKind ConstructKind = CK_Complete
argument_list|,
argument|SourceRange ParenRange = SourceRange()
argument_list|)
block|;
name|CXXConstructorDecl
operator|*
name|getConstructor
argument_list|()
specifier|const
block|{
return|return
name|Constructor
return|;
block|}
name|void
name|setConstructor
argument_list|(
argument|CXXConstructorDecl *C
argument_list|)
block|{
name|Constructor
operator|=
name|C
block|; }
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|void
name|setLocation
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|this
operator|->
name|Loc
operator|=
name|Loc
block|; }
comment|/// \brief Whether this construction is elidable.
name|bool
name|isElidable
argument_list|()
specifier|const
block|{
return|return
name|Elidable
return|;
block|}
name|void
name|setElidable
argument_list|(
argument|bool E
argument_list|)
block|{
name|Elidable
operator|=
name|E
block|; }
comment|/// \brief Whether this construction first requires
comment|/// zero-initialization before the initializer is called.
name|bool
name|requiresZeroInitialization
argument_list|()
specifier|const
block|{
return|return
name|ZeroInitialization
return|;
block|}
name|void
name|setRequiresZeroInitialization
argument_list|(
argument|bool ZeroInit
argument_list|)
block|{
name|ZeroInitialization
operator|=
name|ZeroInit
block|;   }
comment|/// \brief Determines whether this constructor is actually constructing
comment|/// a base class (rather than a complete object).
name|ConstructionKind
name|getConstructionKind
argument_list|()
specifier|const
block|{
return|return
operator|(
name|ConstructionKind
operator|)
name|ConstructKind
return|;
block|}
name|void
name|setConstructionKind
argument_list|(
argument|ConstructionKind CK
argument_list|)
block|{
name|ConstructKind
operator|=
name|CK
block|;   }
typedef|typedef
name|ExprIterator
name|arg_iterator
typedef|;
typedef|typedef
name|ConstExprIterator
name|const_arg_iterator
typedef|;
name|arg_iterator
name|arg_begin
argument_list|()
block|{
return|return
name|Args
return|;
block|}
name|arg_iterator
name|arg_end
argument_list|()
block|{
return|return
name|Args
operator|+
name|NumArgs
return|;
block|}
name|const_arg_iterator
name|arg_begin
argument_list|()
specifier|const
block|{
return|return
name|Args
return|;
block|}
name|const_arg_iterator
name|arg_end
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|+
name|NumArgs
return|;
block|}
name|Expr
operator|*
operator|*
name|getArgs
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|Args
operator|)
return|;
block|}
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|NumArgs
return|;
block|}
comment|/// getArg - Return the specified argument.
name|Expr
operator|*
name|getArg
argument_list|(
argument|unsigned Arg
argument_list|)
block|{
name|assert
argument_list|(
name|Arg
operator|<
name|NumArgs
operator|&&
literal|"Arg access out of range!"
argument_list|)
block|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Args
index|[
name|Arg
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArg
argument_list|(
argument|unsigned Arg
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Arg
operator|<
name|NumArgs
operator|&&
literal|"Arg access out of range!"
argument_list|)
block|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Args
index|[
name|Arg
index|]
operator|)
return|;
block|}
comment|/// setArg - Set the specified argument.
name|void
name|setArg
argument_list|(
argument|unsigned Arg
argument_list|,
argument|Expr *ArgExpr
argument_list|)
block|{
name|assert
argument_list|(
name|Arg
operator|<
name|NumArgs
operator|&&
literal|"Arg access out of range!"
argument_list|)
block|;
name|Args
index|[
name|Arg
index|]
operator|=
name|ArgExpr
block|;   }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|;
name|SourceRange
name|getParenRange
argument_list|()
specifier|const
block|{
return|return
name|ParenRange
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
name|CXXConstructExprClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|CXXTemporaryObjectExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXConstructExpr *
argument_list|)
block|{
return|return
name|true
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
name|Args
index|[
literal|0
index|]
argument_list|,
operator|&
name|Args
index|[
literal|0
index|]
operator|+
name|NumArgs
argument_list|)
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// CXXFunctionalCastExpr - Represents an explicit C++ type conversion
comment|/// that uses "functional" notion (C++ [expr.type.conv]). Example: @c
comment|/// x = int(0.5);
name|class
name|CXXFunctionalCastExpr
operator|:
name|public
name|ExplicitCastExpr
block|{
name|SourceLocation
name|TyBeginLoc
block|;
name|SourceLocation
name|RParenLoc
block|;
name|CXXFunctionalCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation tyBeginLoc
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *castExpr
argument_list|,
argument|unsigned pathSize
argument_list|,
argument|SourceLocation rParenLoc
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
name|CXXFunctionalCastExprClass
argument_list|,
name|ty
argument_list|,
name|VK
argument_list|,
name|kind
argument_list|,
name|castExpr
argument_list|,
name|pathSize
argument_list|,
name|writtenTy
argument_list|)
block|,
name|TyBeginLoc
argument_list|(
name|tyBeginLoc
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|rParenLoc
argument_list|)
block|{}
name|explicit
name|CXXFunctionalCastExpr
argument_list|(
argument|EmptyShell Shell
argument_list|,
argument|unsigned PathSize
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
argument|CXXFunctionalCastExprClass
argument_list|,
argument|Shell
argument_list|,
argument|PathSize
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|CXXFunctionalCastExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|TypeSourceInfo *Written
argument_list|,
argument|SourceLocation TyBeginLoc
argument_list|,
argument|CastKind Kind
argument_list|,
argument|Expr *Op
argument_list|,
argument|const CXXCastPath *Path
argument_list|,
argument|SourceLocation RPLoc
argument_list|)
block|;
specifier|static
name|CXXFunctionalCastExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|unsigned PathSize
argument_list|)
block|;
name|SourceLocation
name|getTypeBeginLoc
argument_list|()
specifier|const
block|{
return|return
name|TyBeginLoc
return|;
block|}
name|void
name|setTypeBeginLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|TyBeginLoc
operator|=
name|L
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
argument|SourceLocation L
argument_list|)
block|{
name|RParenLoc
operator|=
name|L
block|; }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|TyBeginLoc
argument_list|,
name|RParenLoc
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
name|CXXFunctionalCastExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXFunctionalCastExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// @brief Represents a C++ functional cast expression that builds a
comment|/// temporary object.
comment|///
comment|/// This expression type represents a C++ "functional" cast
comment|/// (C++[expr.type.conv]) with N != 1 arguments that invokes a
comment|/// constructor to build a temporary object. With N == 1 arguments the
comment|/// functional cast expression will be represented by CXXFunctionalCastExpr.
comment|/// Example:
comment|/// @code
comment|/// struct X { X(int, float); }
comment|///
comment|/// X create_X() {
comment|///   return X(1, 3.14f); // creates a CXXTemporaryObjectExpr
comment|/// };
comment|/// @endcode
name|class
name|CXXTemporaryObjectExpr
operator|:
name|public
name|CXXConstructExpr
block|{
name|TypeSourceInfo
operator|*
name|Type
block|;
name|public
operator|:
name|CXXTemporaryObjectExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXConstructorDecl *Cons
argument_list|,
argument|TypeSourceInfo *Type
argument_list|,
argument|Expr **Args
argument_list|,
argument|unsigned NumArgs
argument_list|,
argument|SourceRange parenRange
argument_list|,
argument|bool ZeroInitialization = false
argument_list|)
block|;
name|explicit
name|CXXTemporaryObjectExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|CXXConstructExpr
argument_list|(
name|CXXTemporaryObjectExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|Type
argument_list|()
block|{ }
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|;
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
name|CXXTemporaryObjectExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXTemporaryObjectExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// CXXScalarValueInitExpr - [C++ 5.2.3p2]
comment|/// Expression "T()" which creates a value-initialized rvalue of type
comment|/// T, which is a non-class type.
comment|///
name|class
name|CXXScalarValueInitExpr
operator|:
name|public
name|Expr
block|{
name|SourceLocation
name|RParenLoc
block|;
name|TypeSourceInfo
operator|*
name|TypeInfo
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
comment|/// \brief Create an explicitly-written scalar-value initialization
comment|/// expression.
name|CXXScalarValueInitExpr
argument_list|(
argument|QualType Type
argument_list|,
argument|TypeSourceInfo *TypeInfo
argument_list|,
argument|SourceLocation rParenLoc
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXScalarValueInitExprClass
argument_list|,
name|Type
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|RParenLoc
argument_list|(
name|rParenLoc
argument_list|)
block|,
name|TypeInfo
argument_list|(
argument|TypeInfo
argument_list|)
block|{}
name|explicit
name|CXXScalarValueInitExpr
argument_list|(
argument|EmptyShell Shell
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CXXScalarValueInitExprClass
argument_list|,
argument|Shell
argument_list|)
block|{ }
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|TypeInfo
return|;
block|}
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|;
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
name|CXXScalarValueInitExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXScalarValueInitExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// CXXNewExpr - A new expression for memory allocation and constructor calls,
comment|/// e.g: "new CXXNewExpr(foo)".
name|class
name|CXXNewExpr
operator|:
name|public
name|Expr
block|{
comment|// Was the usage ::new, i.e. is the global new to be used?
name|bool
name|GlobalNew
operator|:
literal|1
block|;
comment|// Is there an initializer? If not, built-ins are uninitialized, else they're
comment|// value-initialized.
name|bool
name|Initializer
operator|:
literal|1
block|;
comment|// Do we allocate an array? If so, the first SubExpr is the size expression.
name|bool
name|Array
operator|:
literal|1
block|;
comment|// If this is an array allocation, does the usual deallocation
comment|// function for the allocated type want to know the allocated size?
name|bool
name|UsualArrayDeleteWantsSize
operator|:
literal|1
block|;
comment|// The number of placement new arguments.
name|unsigned
name|NumPlacementArgs
operator|:
literal|14
block|;
comment|// The number of constructor arguments. This may be 1 even for non-class
comment|// types; use the pseudo copy constructor.
name|unsigned
name|NumConstructorArgs
operator|:
literal|14
block|;
comment|// Contains an optional array size expression, any number of optional
comment|// placement arguments, and any number of optional constructor arguments,
comment|// in that order.
name|Stmt
operator|*
operator|*
name|SubExprs
block|;
comment|// Points to the allocation function used.
name|FunctionDecl
operator|*
name|OperatorNew
block|;
comment|// Points to the deallocation function used in case of error. May be null.
name|FunctionDecl
operator|*
name|OperatorDelete
block|;
comment|// Points to the constructor used. Cannot be null if AllocType is a record;
comment|// it would still point at the default constructor (even an implicit one).
comment|// Must be null for all other types.
name|CXXConstructorDecl
operator|*
name|Constructor
block|;
comment|/// \brief The allocated type-source information, as written in the source.
name|TypeSourceInfo
operator|*
name|AllocatedTypeInfo
block|;
comment|/// \brief If the allocated type was expressed as a parenthesized type-id,
comment|/// the source range covering the parenthesized type-id.
name|SourceRange
name|TypeIdParens
block|;
name|SourceLocation
name|StartLoc
block|;
name|SourceLocation
name|EndLoc
block|;
name|SourceLocation
name|ConstructorLParen
block|;
name|SourceLocation
name|ConstructorRParen
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
name|CXXNewExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|bool globalNew
argument_list|,
argument|FunctionDecl *operatorNew
argument_list|,
argument|Expr **placementArgs
argument_list|,
argument|unsigned numPlaceArgs
argument_list|,
argument|SourceRange TypeIdParens
argument_list|,
argument|Expr *arraySize
argument_list|,
argument|CXXConstructorDecl *constructor
argument_list|,
argument|bool initializer
argument_list|,
argument|Expr **constructorArgs
argument_list|,
argument|unsigned numConsArgs
argument_list|,
argument|FunctionDecl *operatorDelete
argument_list|,
argument|bool usualArrayDeleteWantsSize
argument_list|,
argument|QualType ty
argument_list|,
argument|TypeSourceInfo *AllocatedTypeInfo
argument_list|,
argument|SourceLocation startLoc
argument_list|,
argument|SourceLocation endLoc
argument_list|,
argument|SourceLocation constructorLParen
argument_list|,
argument|SourceLocation constructorRParen
argument_list|)
block|;
name|explicit
name|CXXNewExpr
argument_list|(
argument|EmptyShell Shell
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXNewExprClass
argument_list|,
name|Shell
argument_list|)
block|,
name|SubExprs
argument_list|(
literal|0
argument_list|)
block|{ }
name|void
name|AllocateArgsArray
argument_list|(
argument|ASTContext&C
argument_list|,
argument|bool isArray
argument_list|,
argument|unsigned numPlaceArgs
argument_list|,
argument|unsigned numConsArgs
argument_list|)
block|;
name|QualType
name|getAllocatedType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getType
argument_list|()
operator|->
name|isPointerType
argument_list|()
argument_list|)
block|;
return|return
name|getType
argument_list|()
operator|->
name|getAs
operator|<
name|PointerType
operator|>
operator|(
operator|)
operator|->
name|getPointeeType
argument_list|()
return|;
block|}
name|TypeSourceInfo
operator|*
name|getAllocatedTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|AllocatedTypeInfo
return|;
block|}
comment|/// \brief True if the allocation result needs to be null-checked.
comment|/// C++0x [expr.new]p13:
comment|///   If the allocation function returns null, initialization shall
comment|///   not be done, the deallocation function shall not be called,
comment|///   and the value of the new-expression shall be null.
comment|/// An allocation function is not allowed to return null unless it
comment|/// has a non-throwing exception-specification.  The '03 rule is
comment|/// identical except that the definition of a non-throwing
comment|/// exception specification is just "is it throw()?".
name|bool
name|shouldNullCheckAllocation
argument_list|(
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
name|FunctionDecl
operator|*
name|getOperatorNew
argument_list|()
specifier|const
block|{
return|return
name|OperatorNew
return|;
block|}
name|void
name|setOperatorNew
argument_list|(
argument|FunctionDecl *D
argument_list|)
block|{
name|OperatorNew
operator|=
name|D
block|; }
name|FunctionDecl
operator|*
name|getOperatorDelete
argument_list|()
specifier|const
block|{
return|return
name|OperatorDelete
return|;
block|}
name|void
name|setOperatorDelete
argument_list|(
argument|FunctionDecl *D
argument_list|)
block|{
name|OperatorDelete
operator|=
name|D
block|; }
name|CXXConstructorDecl
operator|*
name|getConstructor
argument_list|()
specifier|const
block|{
return|return
name|Constructor
return|;
block|}
name|void
name|setConstructor
argument_list|(
argument|CXXConstructorDecl *D
argument_list|)
block|{
name|Constructor
operator|=
name|D
block|; }
name|bool
name|isArray
argument_list|()
specifier|const
block|{
return|return
name|Array
return|;
block|}
name|Expr
operator|*
name|getArraySize
argument_list|()
block|{
return|return
name|Array
operator|?
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
literal|0
index|]
operator|)
operator|:
literal|0
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArraySize
argument_list|()
specifier|const
block|{
return|return
name|Array
condition|?
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
literal|0
index|]
operator|)
else|:
literal|0
return|;
block|}
name|unsigned
name|getNumPlacementArgs
argument_list|()
specifier|const
block|{
return|return
name|NumPlacementArgs
return|;
block|}
name|Expr
operator|*
operator|*
name|getPlacementArgs
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|SubExprs
operator|+
name|Array
operator|)
return|;
block|}
name|Expr
operator|*
name|getPlacementArg
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumPlacementArgs
operator|&&
literal|"Index out of range"
argument_list|)
block|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|Array
operator|+
name|i
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getPlacementArg
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumPlacementArgs
operator|&&
literal|"Index out of range"
argument_list|)
block|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|Array
operator|+
name|i
index|]
operator|)
return|;
block|}
name|bool
name|isParenTypeId
argument_list|()
specifier|const
block|{
return|return
name|TypeIdParens
operator|.
name|isValid
argument_list|()
return|;
block|}
name|SourceRange
name|getTypeIdParens
argument_list|()
specifier|const
block|{
return|return
name|TypeIdParens
return|;
block|}
name|bool
name|isGlobalNew
argument_list|()
specifier|const
block|{
return|return
name|GlobalNew
return|;
block|}
name|bool
name|hasInitializer
argument_list|()
specifier|const
block|{
return|return
name|Initializer
return|;
block|}
comment|/// Answers whether the usual array deallocation function for the
comment|/// allocated type expects the size of the allocation as a
comment|/// parameter.
name|bool
name|doesUsualArrayDeleteWantSize
argument_list|()
specifier|const
block|{
return|return
name|UsualArrayDeleteWantsSize
return|;
block|}
name|unsigned
name|getNumConstructorArgs
argument_list|()
specifier|const
block|{
return|return
name|NumConstructorArgs
return|;
block|}
name|Expr
operator|*
operator|*
name|getConstructorArgs
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|SubExprs
operator|+
name|Array
operator|+
name|NumPlacementArgs
operator|)
return|;
block|}
name|Expr
operator|*
name|getConstructorArg
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumConstructorArgs
operator|&&
literal|"Index out of range"
argument_list|)
block|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|Array
operator|+
name|NumPlacementArgs
operator|+
name|i
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getConstructorArg
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumConstructorArgs
operator|&&
literal|"Index out of range"
argument_list|)
block|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|Array
operator|+
name|NumPlacementArgs
operator|+
name|i
index|]
operator|)
return|;
block|}
typedef|typedef
name|ExprIterator
name|arg_iterator
typedef|;
typedef|typedef
name|ConstExprIterator
name|const_arg_iterator
typedef|;
name|arg_iterator
name|placement_arg_begin
argument_list|()
block|{
return|return
name|SubExprs
operator|+
name|Array
return|;
block|}
name|arg_iterator
name|placement_arg_end
argument_list|()
block|{
return|return
name|SubExprs
operator|+
name|Array
operator|+
name|getNumPlacementArgs
argument_list|()
return|;
block|}
name|const_arg_iterator
name|placement_arg_begin
argument_list|()
specifier|const
block|{
return|return
name|SubExprs
operator|+
name|Array
return|;
block|}
name|const_arg_iterator
name|placement_arg_end
argument_list|()
specifier|const
block|{
return|return
name|SubExprs
operator|+
name|Array
operator|+
name|getNumPlacementArgs
argument_list|()
return|;
block|}
name|arg_iterator
name|constructor_arg_begin
argument_list|()
block|{
return|return
name|SubExprs
operator|+
name|Array
operator|+
name|getNumPlacementArgs
argument_list|()
return|;
block|}
name|arg_iterator
name|constructor_arg_end
argument_list|()
block|{
return|return
name|SubExprs
operator|+
name|Array
operator|+
name|getNumPlacementArgs
argument_list|()
operator|+
name|getNumConstructorArgs
argument_list|()
return|;
block|}
name|const_arg_iterator
name|constructor_arg_begin
argument_list|()
specifier|const
block|{
return|return
name|SubExprs
operator|+
name|Array
operator|+
name|getNumPlacementArgs
argument_list|()
return|;
block|}
name|const_arg_iterator
name|constructor_arg_end
argument_list|()
specifier|const
block|{
return|return
name|SubExprs
operator|+
name|Array
operator|+
name|getNumPlacementArgs
argument_list|()
operator|+
name|getNumConstructorArgs
argument_list|()
return|;
block|}
typedef|typedef
name|Stmt
modifier|*
modifier|*
name|raw_arg_iterator
typedef|;
name|raw_arg_iterator
name|raw_arg_begin
argument_list|()
block|{
return|return
name|SubExprs
return|;
block|}
name|raw_arg_iterator
name|raw_arg_end
argument_list|()
block|{
return|return
name|SubExprs
operator|+
name|Array
operator|+
name|getNumPlacementArgs
argument_list|()
operator|+
name|getNumConstructorArgs
argument_list|()
return|;
block|}
name|const_arg_iterator
name|raw_arg_begin
argument_list|()
specifier|const
block|{
return|return
name|SubExprs
return|;
block|}
name|const_arg_iterator
name|raw_arg_end
argument_list|()
specifier|const
block|{
return|return
name|constructor_arg_end
argument_list|()
return|;
block|}
name|SourceLocation
name|getStartLoc
argument_list|()
specifier|const
block|{
return|return
name|StartLoc
return|;
block|}
name|SourceLocation
name|getEndLoc
argument_list|()
specifier|const
block|{
return|return
name|EndLoc
return|;
block|}
name|SourceLocation
name|getConstructorLParen
argument_list|()
specifier|const
block|{
return|return
name|ConstructorLParen
return|;
block|}
name|SourceLocation
name|getConstructorRParen
argument_list|()
specifier|const
block|{
return|return
name|ConstructorRParen
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|StartLoc
argument_list|,
name|EndLoc
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
name|CXXNewExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXNewExpr *
argument_list|)
block|{
return|return
name|true
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
literal|0
index|]
operator|+
name|Array
operator|+
name|getNumPlacementArgs
argument_list|()
operator|+
name|getNumConstructorArgs
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// CXXDeleteExpr - A delete expression for memory deallocation and destructor
comment|/// calls, e.g. "delete[] pArray".
name|class
name|CXXDeleteExpr
operator|:
name|public
name|Expr
block|{
comment|// Is this a forced global delete, i.e. "::delete"?
name|bool
name|GlobalDelete
operator|:
literal|1
block|;
comment|// Is this the array form of delete, i.e. "delete[]"?
name|bool
name|ArrayForm
operator|:
literal|1
block|;
comment|// ArrayFormAsWritten can be different from ArrayForm if 'delete' is applied
comment|// to pointer-to-array type (ArrayFormAsWritten will be false while ArrayForm
comment|// will be true).
name|bool
name|ArrayFormAsWritten
operator|:
literal|1
block|;
comment|// Does the usual deallocation function for the element type require
comment|// a size_t argument?
name|bool
name|UsualArrayDeleteWantsSize
operator|:
literal|1
block|;
comment|// Points to the operator delete overload that is used. Could be a member.
name|FunctionDecl
operator|*
name|OperatorDelete
block|;
comment|// The pointer expression to be deleted.
name|Stmt
operator|*
name|Argument
block|;
comment|// Location of the expression.
name|SourceLocation
name|Loc
block|;
name|public
operator|:
name|CXXDeleteExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|bool globalDelete
argument_list|,
argument|bool arrayForm
argument_list|,
argument|bool arrayFormAsWritten
argument_list|,
argument|bool usualArrayDeleteWantsSize
argument_list|,
argument|FunctionDecl *operatorDelete
argument_list|,
argument|Expr *arg
argument_list|,
argument|SourceLocation loc
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXDeleteExprClass
argument_list|,
name|ty
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|arg
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|GlobalDelete
argument_list|(
name|globalDelete
argument_list|)
block|,
name|ArrayForm
argument_list|(
name|arrayForm
argument_list|)
block|,
name|ArrayFormAsWritten
argument_list|(
name|arrayFormAsWritten
argument_list|)
block|,
name|UsualArrayDeleteWantsSize
argument_list|(
name|usualArrayDeleteWantsSize
argument_list|)
block|,
name|OperatorDelete
argument_list|(
name|operatorDelete
argument_list|)
block|,
name|Argument
argument_list|(
name|arg
argument_list|)
block|,
name|Loc
argument_list|(
argument|loc
argument_list|)
block|{ }
name|explicit
name|CXXDeleteExpr
argument_list|(
argument|EmptyShell Shell
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXDeleteExprClass
argument_list|,
name|Shell
argument_list|)
block|,
name|OperatorDelete
argument_list|(
literal|0
argument_list|)
block|,
name|Argument
argument_list|(
literal|0
argument_list|)
block|{ }
name|bool
name|isGlobalDelete
argument_list|()
specifier|const
block|{
return|return
name|GlobalDelete
return|;
block|}
name|bool
name|isArrayForm
argument_list|()
specifier|const
block|{
return|return
name|ArrayForm
return|;
block|}
name|bool
name|isArrayFormAsWritten
argument_list|()
specifier|const
block|{
return|return
name|ArrayFormAsWritten
return|;
block|}
comment|/// Answers whether the usual array deallocation function for the
comment|/// allocated type expects the size of the allocation as a
comment|/// parameter.  This can be true even if the actual deallocation
comment|/// function that we're using doesn't want a size.
name|bool
name|doesUsualArrayDeleteWantSize
argument_list|()
specifier|const
block|{
return|return
name|UsualArrayDeleteWantsSize
return|;
block|}
name|FunctionDecl
operator|*
name|getOperatorDelete
argument_list|()
specifier|const
block|{
return|return
name|OperatorDelete
return|;
block|}
name|Expr
operator|*
name|getArgument
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Argument
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArgument
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Argument
operator|)
return|;
block|}
comment|/// \brief Retrieve the type being destroyed.  If the type being
comment|/// destroyed is a dependent type which may or may not be a pointer,
comment|/// return an invalid type.
name|QualType
name|getDestroyedType
argument_list|()
specifier|const
block|;
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|,
name|Argument
operator|->
name|getLocEnd
argument_list|()
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
name|CXXDeleteExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXDeleteExpr *
argument_list|)
block|{
return|return
name|true
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
name|Argument
argument_list|,
operator|&
name|Argument
operator|+
literal|1
argument_list|)
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// \brief Structure used to store the type being destroyed by a
comment|/// pseudo-destructor expression.
name|class
name|PseudoDestructorTypeStorage
block|{
comment|/// \brief Either the type source information or the name of the type, if
comment|/// it couldn't be resolved due to type-dependence.
name|llvm
operator|::
name|PointerUnion
operator|<
name|TypeSourceInfo
operator|*
block|,
name|IdentifierInfo
operator|*
operator|>
name|Type
block|;
comment|/// \brief The starting source location of the pseudo-destructor type.
name|SourceLocation
name|Location
block|;
name|public
operator|:
name|PseudoDestructorTypeStorage
argument_list|()
block|{ }
name|PseudoDestructorTypeStorage
argument_list|(
argument|IdentifierInfo *II
argument_list|,
argument|SourceLocation Loc
argument_list|)
operator|:
name|Type
argument_list|(
name|II
argument_list|)
block|,
name|Location
argument_list|(
argument|Loc
argument_list|)
block|{ }
name|PseudoDestructorTypeStorage
argument_list|(
name|TypeSourceInfo
operator|*
name|Info
argument_list|)
block|;
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|.
name|dyn_cast
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|IdentifierInfo
operator|*
name|getIdentifier
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|.
name|dyn_cast
operator|<
name|IdentifierInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Location
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a C++ pseudo-destructor (C++ [expr.pseudo]).
comment|///
comment|/// A pseudo-destructor is an expression that looks like a member access to a
comment|/// destructor of a scalar type, except that scalar types don't have
comment|/// destructors. For example:
comment|///
comment|/// \code
comment|/// typedef int T;
comment|/// void f(int *p) {
comment|///   p->T::~T();
comment|/// }
comment|/// \endcode
comment|///
comment|/// Pseudo-destructors typically occur when instantiating templates such as:
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// void destroy(T* ptr) {
comment|///   ptr->T::~T();
comment|/// }
comment|/// \endcode
comment|///
comment|/// for scalar types. A pseudo-destructor expression has no run-time semantics
comment|/// beyond evaluating the base expression.
name|class
name|CXXPseudoDestructorExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The base expression (that is being destroyed).
name|Stmt
operator|*
name|Base
block|;
comment|/// \brief Whether the operator was an arrow ('->'); otherwise, it was a
comment|/// period ('.').
name|bool
name|IsArrow
operator|:
literal|1
block|;
comment|/// \brief The location of the '.' or '->' operator.
name|SourceLocation
name|OperatorLoc
block|;
comment|/// \brief The nested-name-specifier that follows the operator, if present.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
comment|/// \brief The type that precedes the '::' in a qualified pseudo-destructor
comment|/// expression.
name|TypeSourceInfo
operator|*
name|ScopeType
block|;
comment|/// \brief The location of the '::' in a qualified pseudo-destructor
comment|/// expression.
name|SourceLocation
name|ColonColonLoc
block|;
comment|/// \brief The location of the '~'.
name|SourceLocation
name|TildeLoc
block|;
comment|/// \brief The type being destroyed, or its name if we were unable to
comment|/// resolve the name.
name|PseudoDestructorTypeStorage
name|DestroyedType
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
name|CXXPseudoDestructorExpr
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|Expr *Base
argument_list|,
argument|bool isArrow
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|TypeSourceInfo *ScopeType
argument_list|,
argument|SourceLocation ColonColonLoc
argument_list|,
argument|SourceLocation TildeLoc
argument_list|,
argument|PseudoDestructorTypeStorage DestroyedType
argument_list|)
block|;
name|explicit
name|CXXPseudoDestructorExpr
argument_list|(
argument|EmptyShell Shell
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXPseudoDestructorExprClass
argument_list|,
name|Shell
argument_list|)
block|,
name|Base
argument_list|(
literal|0
argument_list|)
block|,
name|IsArrow
argument_list|(
name|false
argument_list|)
block|,
name|QualifierLoc
argument_list|()
block|,
name|ScopeType
argument_list|(
literal|0
argument_list|)
block|{ }
name|Expr
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
comment|/// \brief Determines whether this member expression actually had
comment|/// a C++ nested-name-specifier prior to the name of the member, e.g.,
comment|/// x->Base::foo.
name|bool
name|hasQualifier
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief Retrieves the nested-name-specifier that qualifies the type name,
comment|/// with source-location information.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief If the member name was qualified, retrieves the
comment|/// nested-name-specifier that precedes the member name. Otherwise, returns
comment|/// NULL.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
return|;
block|}
comment|/// \brief Determine whether this pseudo-destructor expression was written
comment|/// using an '->' (otherwise, it used a '.').
name|bool
name|isArrow
argument_list|()
specifier|const
block|{
return|return
name|IsArrow
return|;
block|}
comment|/// \brief Retrieve the location of the '.' or '->' operator.
name|SourceLocation
name|getOperatorLoc
argument_list|()
specifier|const
block|{
return|return
name|OperatorLoc
return|;
block|}
comment|/// \brief Retrieve the scope type in a qualified pseudo-destructor
comment|/// expression.
comment|///
comment|/// Pseudo-destructor expressions can have extra qualification within them
comment|/// that is not part of the nested-name-specifier, e.g., \c p->T::~T().
comment|/// Here, if the object type of the expression is (or may be) a scalar type,
comment|/// \p T may also be a scalar type and, therefore, cannot be part of a
comment|/// nested-name-specifier. It is stored as the "scope type" of the pseudo-
comment|/// destructor expression.
name|TypeSourceInfo
operator|*
name|getScopeTypeInfo
argument_list|()
specifier|const
block|{
return|return
name|ScopeType
return|;
block|}
comment|/// \brief Retrieve the location of the '::' in a qualified pseudo-destructor
comment|/// expression.
name|SourceLocation
name|getColonColonLoc
argument_list|()
specifier|const
block|{
return|return
name|ColonColonLoc
return|;
block|}
comment|/// \brief Retrieve the location of the '~'.
name|SourceLocation
name|getTildeLoc
argument_list|()
specifier|const
block|{
return|return
name|TildeLoc
return|;
block|}
comment|/// \brief Retrieve the source location information for the type
comment|/// being destroyed.
comment|///
comment|/// This type-source information is available for non-dependent
comment|/// pseudo-destructor expressions and some dependent pseudo-destructor
comment|/// expressions. Returns NULL if we only have the identifier for a
comment|/// dependent pseudo-destructor expression.
name|TypeSourceInfo
operator|*
name|getDestroyedTypeInfo
argument_list|()
specifier|const
block|{
return|return
name|DestroyedType
operator|.
name|getTypeSourceInfo
argument_list|()
return|;
block|}
comment|/// \brief In a dependent pseudo-destructor expression for which we do not
comment|/// have full type information on the destroyed type, provides the name
comment|/// of the destroyed type.
name|IdentifierInfo
operator|*
name|getDestroyedTypeIdentifier
argument_list|()
specifier|const
block|{
return|return
name|DestroyedType
operator|.
name|getIdentifier
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the type being destroyed.
name|QualType
name|getDestroyedType
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve the starting location of the type being destroyed.
name|SourceLocation
name|getDestroyedTypeLoc
argument_list|()
specifier|const
block|{
return|return
name|DestroyedType
operator|.
name|getLocation
argument_list|()
return|;
block|}
comment|/// \brief Set the name of destroyed type for a dependent pseudo-destructor
comment|/// expression.
name|void
name|setDestroyedType
argument_list|(
argument|IdentifierInfo *II
argument_list|,
argument|SourceLocation Loc
argument_list|)
block|{
name|DestroyedType
operator|=
name|PseudoDestructorTypeStorage
argument_list|(
name|II
argument_list|,
name|Loc
argument_list|)
block|;   }
comment|/// \brief Set the destroyed type.
name|void
name|setDestroyedType
argument_list|(
argument|TypeSourceInfo *Info
argument_list|)
block|{
name|DestroyedType
operator|=
name|PseudoDestructorTypeStorage
argument_list|(
name|Info
argument_list|)
block|;   }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|;
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
name|CXXPseudoDestructorExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXPseudoDestructorExpr *
argument_list|)
block|{
return|return
name|true
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
name|Base
argument_list|,
operator|&
name|Base
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// UnaryTypeTraitExpr - A GCC or MS unary type trait, as used in the
comment|/// implementation of TR1/C++0x type trait templates.
comment|/// Example:
comment|/// __is_pod(int) == true
comment|/// __is_enum(std::string) == false
name|class
name|UnaryTypeTraitExpr
operator|:
name|public
name|Expr
block|{
comment|/// UTT - The trait. A UnaryTypeTrait enum in MSVC compat unsigned.
name|unsigned
name|UTT
operator|:
literal|31
block|;
comment|/// The value of the type trait. Unspecified if dependent.
name|bool
name|Value
operator|:
literal|1
block|;
comment|/// Loc - The location of the type trait keyword.
name|SourceLocation
name|Loc
block|;
comment|/// RParen - The location of the closing paren.
name|SourceLocation
name|RParen
block|;
comment|/// The type being queried.
name|TypeSourceInfo
operator|*
name|QueriedType
block|;
name|public
operator|:
name|UnaryTypeTraitExpr
argument_list|(
argument|SourceLocation loc
argument_list|,
argument|UnaryTypeTrait utt
argument_list|,
argument|TypeSourceInfo *queried
argument_list|,
argument|bool value
argument_list|,
argument|SourceLocation rparen
argument_list|,
argument|QualType ty
argument_list|)
operator|:
name|Expr
argument_list|(
name|UnaryTypeTraitExprClass
argument_list|,
name|ty
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|queried
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|queried
operator|->
name|getType
argument_list|()
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|UTT
argument_list|(
name|utt
argument_list|)
block|,
name|Value
argument_list|(
name|value
argument_list|)
block|,
name|Loc
argument_list|(
name|loc
argument_list|)
block|,
name|RParen
argument_list|(
name|rparen
argument_list|)
block|,
name|QueriedType
argument_list|(
argument|queried
argument_list|)
block|{ }
name|explicit
name|UnaryTypeTraitExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|UnaryTypeTraitExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|UTT
argument_list|(
literal|0
argument_list|)
block|,
name|Value
argument_list|(
name|false
argument_list|)
block|,
name|QueriedType
argument_list|()
block|{ }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|,
name|RParen
argument_list|)
return|;
block|}
name|UnaryTypeTrait
name|getTrait
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|UnaryTypeTrait
operator|>
operator|(
name|UTT
operator|)
return|;
block|}
name|QualType
name|getQueriedType
argument_list|()
specifier|const
block|{
return|return
name|QueriedType
operator|->
name|getType
argument_list|()
return|;
block|}
name|TypeSourceInfo
operator|*
name|getQueriedTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|QueriedType
return|;
block|}
name|bool
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
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
name|UnaryTypeTraitExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const UnaryTypeTraitExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// BinaryTypeTraitExpr - A GCC or MS binary type trait, as used in the
comment|/// implementation of TR1/C++0x type trait templates.
comment|/// Example:
comment|/// __is_base_of(Base, Derived) == true
name|class
name|BinaryTypeTraitExpr
operator|:
name|public
name|Expr
block|{
comment|/// BTT - The trait. A BinaryTypeTrait enum in MSVC compat unsigned.
name|unsigned
name|BTT
operator|:
literal|8
block|;
comment|/// The value of the type trait. Unspecified if dependent.
name|bool
name|Value
operator|:
literal|1
block|;
comment|/// Loc - The location of the type trait keyword.
name|SourceLocation
name|Loc
block|;
comment|/// RParen - The location of the closing paren.
name|SourceLocation
name|RParen
block|;
comment|/// The lhs type being queried.
name|TypeSourceInfo
operator|*
name|LhsType
block|;
comment|/// The rhs type being queried.
name|TypeSourceInfo
operator|*
name|RhsType
block|;
name|public
operator|:
name|BinaryTypeTraitExpr
argument_list|(
argument|SourceLocation loc
argument_list|,
argument|BinaryTypeTrait btt
argument_list|,
argument|TypeSourceInfo *lhsType
argument_list|,
argument|TypeSourceInfo *rhsType
argument_list|,
argument|bool value
argument_list|,
argument|SourceLocation rparen
argument_list|,
argument|QualType ty
argument_list|)
operator|:
name|Expr
argument_list|(
name|BinaryTypeTraitExprClass
argument_list|,
name|ty
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|lhsType
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
operator|||
name|rhsType
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
argument_list|,
operator|(
name|lhsType
operator|->
name|getType
argument_list|()
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|rhsType
operator|->
name|getType
argument_list|()
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
argument_list|)
block|,
name|BTT
argument_list|(
name|btt
argument_list|)
block|,
name|Value
argument_list|(
name|value
argument_list|)
block|,
name|Loc
argument_list|(
name|loc
argument_list|)
block|,
name|RParen
argument_list|(
name|rparen
argument_list|)
block|,
name|LhsType
argument_list|(
name|lhsType
argument_list|)
block|,
name|RhsType
argument_list|(
argument|rhsType
argument_list|)
block|{ }
name|explicit
name|BinaryTypeTraitExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|BinaryTypeTraitExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|BTT
argument_list|(
literal|0
argument_list|)
block|,
name|Value
argument_list|(
name|false
argument_list|)
block|,
name|LhsType
argument_list|()
block|,
name|RhsType
argument_list|()
block|{ }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|,
name|RParen
argument_list|)
return|;
block|}
name|BinaryTypeTrait
name|getTrait
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|BinaryTypeTrait
operator|>
operator|(
name|BTT
operator|)
return|;
block|}
name|QualType
name|getLhsType
argument_list|()
specifier|const
block|{
return|return
name|LhsType
operator|->
name|getType
argument_list|()
return|;
block|}
name|QualType
name|getRhsType
argument_list|()
specifier|const
block|{
return|return
name|RhsType
operator|->
name|getType
argument_list|()
return|;
block|}
name|TypeSourceInfo
operator|*
name|getLhsTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|LhsType
return|;
block|}
name|TypeSourceInfo
operator|*
name|getRhsTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|RhsType
return|;
block|}
name|bool
name|getValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isTypeDependent
argument_list|()
argument_list|)
block|;
return|return
name|Value
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
name|BinaryTypeTraitExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const BinaryTypeTraitExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// ArrayTypeTraitExpr - An Embarcadero array type trait, as used in the
comment|/// implementation of __array_rank and __array_extent.
comment|/// Example:
comment|/// __array_rank(int[10][20]) == 2
comment|/// __array_extent(int, 1)    == 20
name|class
name|ArrayTypeTraitExpr
operator|:
name|public
name|Expr
block|{
comment|/// ATT - The trait. An ArrayTypeTrait enum in MSVC compat unsigned.
name|unsigned
name|ATT
operator|:
literal|2
block|;
comment|/// The value of the type trait. Unspecified if dependent.
name|uint64_t
name|Value
block|;
comment|/// The array dimension being queried, or -1 if not used
name|Expr
operator|*
name|Dimension
block|;
comment|/// Loc - The location of the type trait keyword.
name|SourceLocation
name|Loc
block|;
comment|/// RParen - The location of the closing paren.
name|SourceLocation
name|RParen
block|;
comment|/// The type being queried.
name|TypeSourceInfo
operator|*
name|QueriedType
block|;
name|public
operator|:
name|ArrayTypeTraitExpr
argument_list|(
argument|SourceLocation loc
argument_list|,
argument|ArrayTypeTrait att
argument_list|,
argument|TypeSourceInfo *queried
argument_list|,
argument|uint64_t value
argument_list|,
argument|Expr *dimension
argument_list|,
argument|SourceLocation rparen
argument_list|,
argument|QualType ty
argument_list|)
operator|:
name|Expr
argument_list|(
name|ArrayTypeTraitExprClass
argument_list|,
name|ty
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|queried
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|queried
operator|->
name|getType
argument_list|()
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|ATT
argument_list|(
name|att
argument_list|)
block|,
name|Value
argument_list|(
name|value
argument_list|)
block|,
name|Dimension
argument_list|(
name|dimension
argument_list|)
block|,
name|Loc
argument_list|(
name|loc
argument_list|)
block|,
name|RParen
argument_list|(
name|rparen
argument_list|)
block|,
name|QueriedType
argument_list|(
argument|queried
argument_list|)
block|{ }
name|explicit
name|ArrayTypeTraitExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|ArrayTypeTraitExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|ATT
argument_list|(
literal|0
argument_list|)
block|,
name|Value
argument_list|(
name|false
argument_list|)
block|,
name|QueriedType
argument_list|()
block|{ }
name|virtual
operator|~
name|ArrayTypeTraitExpr
argument_list|()
block|{ }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|,
name|RParen
argument_list|)
return|;
block|}
name|ArrayTypeTrait
name|getTrait
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ArrayTypeTrait
operator|>
operator|(
name|ATT
operator|)
return|;
block|}
name|QualType
name|getQueriedType
argument_list|()
specifier|const
block|{
return|return
name|QueriedType
operator|->
name|getType
argument_list|()
return|;
block|}
name|TypeSourceInfo
operator|*
name|getQueriedTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|QueriedType
return|;
block|}
name|uint64_t
name|getValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isTypeDependent
argument_list|()
argument_list|)
block|;
return|return
name|Value
return|;
block|}
name|Expr
operator|*
name|getDimensionExpression
argument_list|()
specifier|const
block|{
return|return
name|Dimension
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
name|ArrayTypeTraitExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ArrayTypeTraitExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// ExpressionTraitExpr - An expression trait intrinsic
comment|/// Example:
comment|/// __is_lvalue_expr(std::cout) == true
comment|/// __is_lvalue_expr(1) == false
name|class
name|ExpressionTraitExpr
operator|:
name|public
name|Expr
block|{
comment|/// ET - The trait. A ExpressionTrait enum in MSVC compat unsigned.
name|unsigned
name|ET
operator|:
literal|31
block|;
comment|/// The value of the type trait. Unspecified if dependent.
name|bool
name|Value
operator|:
literal|1
block|;
comment|/// Loc - The location of the type trait keyword.
name|SourceLocation
name|Loc
block|;
comment|/// RParen - The location of the closing paren.
name|SourceLocation
name|RParen
block|;
name|Expr
operator|*
name|QueriedExpression
block|;
name|public
operator|:
name|ExpressionTraitExpr
argument_list|(
argument|SourceLocation loc
argument_list|,
argument|ExpressionTrait et
argument_list|,
argument|Expr *queried
argument_list|,
argument|bool value
argument_list|,
argument|SourceLocation rparen
argument_list|,
argument|QualType resultType
argument_list|)
operator|:
name|Expr
argument_list|(
name|ExpressionTraitExprClass
argument_list|,
name|resultType
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
comment|// Not type-dependent
comment|// Value-dependent if the argument is type-dependent.
name|queried
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|queried
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|ET
argument_list|(
name|et
argument_list|)
block|,
name|Value
argument_list|(
name|value
argument_list|)
block|,
name|Loc
argument_list|(
name|loc
argument_list|)
block|,
name|RParen
argument_list|(
name|rparen
argument_list|)
block|,
name|QueriedExpression
argument_list|(
argument|queried
argument_list|)
block|{ }
name|explicit
name|ExpressionTraitExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|ExpressionTraitExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|ET
argument_list|(
literal|0
argument_list|)
block|,
name|Value
argument_list|(
name|false
argument_list|)
block|,
name|QueriedExpression
argument_list|()
block|{ }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|,
name|RParen
argument_list|)
return|;
block|}
name|ExpressionTrait
name|getTrait
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ExpressionTrait
operator|>
operator|(
name|ET
operator|)
return|;
block|}
name|Expr
operator|*
name|getQueriedExpression
argument_list|()
specifier|const
block|{
return|return
name|QueriedExpression
return|;
block|}
name|bool
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
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
name|ExpressionTraitExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ExpressionTraitExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// \brief A reference to an overloaded function set, either an
comment|/// \t UnresolvedLookupExpr or an \t UnresolvedMemberExpr.
name|class
name|OverloadExpr
operator|:
name|public
name|Expr
block|{
comment|/// The results.  These are undesugared, which is to say, they may
comment|/// include UsingShadowDecls.  Access is relative to the naming
comment|/// class.
comment|// FIXME: Allocate this data after the OverloadExpr subclass.
name|DeclAccessPair
operator|*
name|Results
block|;
name|unsigned
name|NumResults
block|;
comment|/// The common name of these declarations.
name|DeclarationNameInfo
name|NameInfo
block|;
comment|/// \brief The nested-name-specifier that qualifies the name, if any.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
name|protected
operator|:
comment|/// True if the name was a template-id.
name|bool
name|HasExplicitTemplateArgs
block|;
name|OverloadExpr
argument_list|(
argument|StmtClass K
argument_list|,
argument|ASTContext&C
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|,
argument|UnresolvedSetIterator Begin
argument_list|,
argument|UnresolvedSetIterator End
argument_list|,
argument|bool KnownDependent = false
argument_list|,
argument|bool KnownContainsUnexpandedParameterPack = false
argument_list|)
block|;
name|OverloadExpr
argument_list|(
argument|StmtClass K
argument_list|,
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|K
argument_list|,
name|Empty
argument_list|)
block|,
name|Results
argument_list|(
literal|0
argument_list|)
block|,
name|NumResults
argument_list|(
literal|0
argument_list|)
block|,
name|QualifierLoc
argument_list|()
block|,
name|HasExplicitTemplateArgs
argument_list|(
argument|false
argument_list|)
block|{ }
name|void
name|initializeResults
argument_list|(
argument|ASTContext&C
argument_list|,
argument|UnresolvedSetIterator Begin
argument_list|,
argument|UnresolvedSetIterator End
argument_list|)
block|;
name|public
operator|:
expr|struct
name|FindResult
block|{
name|OverloadExpr
operator|*
name|Expression
block|;
name|bool
name|IsAddressOfOperand
block|;
name|bool
name|HasFormOfMemberPointer
block|;   }
block|;
comment|/// Finds the overloaded expression in the given expression of
comment|/// OverloadTy.
comment|///
comment|/// \return the expression (which must be there) and true if it has
comment|/// the particular form of a member pointer expression
specifier|static
name|FindResult
name|find
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|assert
argument_list|(
name|E
operator|->
name|getType
argument_list|()
operator|->
name|isSpecificBuiltinType
argument_list|(
name|BuiltinType
operator|::
name|Overload
argument_list|)
argument_list|)
block|;
name|FindResult
name|Result
block|;
name|E
operator|=
name|E
operator|->
name|IgnoreParens
argument_list|()
block|;
if|if
condition|(
name|isa
operator|<
name|UnaryOperator
operator|>
operator|(
name|E
operator|)
condition|)
block|{
name|assert
argument_list|(
name|cast
operator|<
name|UnaryOperator
operator|>
operator|(
name|E
operator|)
operator|->
name|getOpcode
argument_list|()
operator|==
name|UO_AddrOf
argument_list|)
expr_stmt|;
name|E
operator|=
name|cast
operator|<
name|UnaryOperator
operator|>
operator|(
name|E
operator|)
operator|->
name|getSubExpr
argument_list|()
expr_stmt|;
name|OverloadExpr
modifier|*
name|Ovl
init|=
name|cast
operator|<
name|OverloadExpr
operator|>
operator|(
name|E
operator|->
name|IgnoreParens
argument_list|()
operator|)
decl_stmt|;
name|Result
operator|.
name|HasFormOfMemberPointer
operator|=
operator|(
name|E
operator|==
name|Ovl
operator|&&
name|Ovl
operator|->
name|getQualifier
argument_list|()
operator|)
expr_stmt|;
name|Result
operator|.
name|IsAddressOfOperand
operator|=
name|true
expr_stmt|;
name|Result
operator|.
name|Expression
operator|=
name|Ovl
expr_stmt|;
block|}
else|else
block|{
name|Result
operator|.
name|HasFormOfMemberPointer
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|IsAddressOfOperand
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|Expression
operator|=
name|cast
operator|<
name|OverloadExpr
operator|>
operator|(
name|E
operator|)
expr_stmt|;
block|}
return|return
name|Result
return|;
block|}
comment|/// Gets the naming class of this lookup, if any.
name|CXXRecordDecl
operator|*
name|getNamingClass
argument_list|()
specifier|const
block|;
typedef|typedef
name|UnresolvedSetImpl
operator|::
name|iterator
name|decls_iterator
expr_stmt|;
name|decls_iterator
name|decls_begin
argument_list|()
specifier|const
block|{
return|return
name|UnresolvedSetIterator
argument_list|(
name|Results
argument_list|)
return|;
block|}
name|decls_iterator
name|decls_end
argument_list|()
specifier|const
block|{
return|return
name|UnresolvedSetIterator
argument_list|(
name|Results
operator|+
name|NumResults
argument_list|)
return|;
block|}
comment|/// Gets the number of declarations in the unresolved set.
name|unsigned
name|getNumDecls
argument_list|()
specifier|const
block|{
return|return
name|NumResults
return|;
block|}
comment|/// Gets the full name info.
specifier|const
name|DeclarationNameInfo
operator|&
name|getNameInfo
argument_list|()
specifier|const
block|{
return|return
name|NameInfo
return|;
block|}
comment|/// Gets the name looked up.
name|DeclarationName
name|getName
argument_list|()
specifier|const
block|{
return|return
name|NameInfo
operator|.
name|getName
argument_list|()
return|;
block|}
comment|/// Gets the location of the name.
name|SourceLocation
name|getNameLoc
argument_list|()
specifier|const
block|{
return|return
name|NameInfo
operator|.
name|getLoc
argument_list|()
return|;
block|}
comment|/// Fetches the nested-name qualifier, if one was given.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
return|;
block|}
comment|/// Fetches the nested-name qualifier with source-location information, if
comment|/// one was given.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief Determines whether this expression had an explicit
comment|/// template argument list, e.g. f<int>.
name|bool
name|hasExplicitTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|HasExplicitTemplateArgs
return|;
block|}
name|ExplicitTemplateArgumentList
operator|&
name|getExplicitTemplateArgs
argument_list|()
block|;
comment|// defined far below
specifier|const
name|ExplicitTemplateArgumentList
operator|&
name|getExplicitTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|OverloadExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getExplicitTemplateArgs
argument_list|()
return|;
block|}
comment|/// \brief Retrieves the optional explicit template arguments.
comment|/// This points to the same data as getExplicitTemplateArgs(), but
comment|/// returns null if there are no explicit template arguments.
specifier|const
name|ExplicitTemplateArgumentList
operator|*
name|getOptionalExplicitTemplateArgs
argument_list|()
block|{
if|if
condition|(
operator|!
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
operator|&
name|getExplicitTemplateArgs
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
name|UnresolvedLookupExprClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|UnresolvedMemberExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OverloadExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|; }
block|;
comment|/// \brief A reference to a name which we were able to look up during
comment|/// parsing but could not resolve to a specific declaration.  This
comment|/// arises in several ways:
comment|///   * we might be waiting for argument-dependent lookup
comment|///   * the name might resolve to an overloaded function
comment|/// and eventually:
comment|///   * the lookup might have included a function template
comment|/// These never include UnresolvedUsingValueDecls, which are always
comment|/// class members and therefore appear only in
comment|/// UnresolvedMemberLookupExprs.
name|class
name|UnresolvedLookupExpr
operator|:
name|public
name|OverloadExpr
block|{
comment|/// True if these lookup results should be extended by
comment|/// argument-dependent lookup if this is the operand of a function
comment|/// call.
name|bool
name|RequiresADL
block|;
comment|/// True if namespace ::std should be considered an associated namespace
comment|/// for the purposes of argument-dependent lookup. See C++0x [stmt.ranged]p1.
name|bool
name|StdIsAssociatedNamespace
block|;
comment|/// True if these lookup results are overloaded.  This is pretty
comment|/// trivially rederivable if we urgently need to kill this field.
name|bool
name|Overloaded
block|;
comment|/// The naming class (C++ [class.access.base]p5) of the lookup, if
comment|/// any.  This can generally be recalculated from the context chain,
comment|/// but that can be fairly expensive for unqualified lookups.  If we
comment|/// want to improve memory use here, this could go in a union
comment|/// against the qualified-lookup bits.
name|CXXRecordDecl
operator|*
name|NamingClass
block|;
name|UnresolvedLookupExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXRecordDecl *NamingClass
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|bool RequiresADL
argument_list|,
argument|bool Overloaded
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|,
argument|UnresolvedSetIterator Begin
argument_list|,
argument|UnresolvedSetIterator End
argument_list|,
argument|bool StdIsAssociatedNamespace
argument_list|)
operator|:
name|OverloadExpr
argument_list|(
name|UnresolvedLookupExprClass
argument_list|,
name|C
argument_list|,
name|QualifierLoc
argument_list|,
name|NameInfo
argument_list|,
name|TemplateArgs
argument_list|,
name|Begin
argument_list|,
name|End
argument_list|)
block|,
name|RequiresADL
argument_list|(
name|RequiresADL
argument_list|)
block|,
name|StdIsAssociatedNamespace
argument_list|(
name|StdIsAssociatedNamespace
argument_list|)
block|,
name|Overloaded
argument_list|(
name|Overloaded
argument_list|)
block|,
name|NamingClass
argument_list|(
argument|NamingClass
argument_list|)
block|{}
name|UnresolvedLookupExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|OverloadExpr
argument_list|(
name|UnresolvedLookupExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|RequiresADL
argument_list|(
name|false
argument_list|)
block|,
name|StdIsAssociatedNamespace
argument_list|(
name|false
argument_list|)
block|,
name|Overloaded
argument_list|(
name|false
argument_list|)
block|,
name|NamingClass
argument_list|(
literal|0
argument_list|)
block|{}
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
specifier|static
name|UnresolvedLookupExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXRecordDecl *NamingClass
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|bool ADL
argument_list|,
argument|bool Overloaded
argument_list|,
argument|UnresolvedSetIterator Begin
argument_list|,
argument|UnresolvedSetIterator End
argument_list|,
argument|bool StdIsAssociatedNamespace = false
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|ADL
operator|||
operator|!
name|StdIsAssociatedNamespace
operator|)
operator|&&
literal|"std considered associated namespace when not performing ADL"
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|C
argument_list|)
name|UnresolvedLookupExpr
argument_list|(
name|C
argument_list|,
name|NamingClass
argument_list|,
name|QualifierLoc
argument_list|,
name|NameInfo
argument_list|,
name|ADL
argument_list|,
name|Overloaded
argument_list|,
literal|0
argument_list|,
name|Begin
argument_list|,
name|End
argument_list|,
name|StdIsAssociatedNamespace
argument_list|)
return|;
block|}
specifier|static
name|UnresolvedLookupExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXRecordDecl *NamingClass
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|bool ADL
argument_list|,
argument|const TemplateArgumentListInfo&Args
argument_list|,
argument|UnresolvedSetIterator Begin
argument_list|,
argument|UnresolvedSetIterator End
argument_list|)
block|;
specifier|static
name|UnresolvedLookupExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&C
argument_list|,
argument|bool HasExplicitTemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|)
block|;
comment|/// True if this declaration should be extended by
comment|/// argument-dependent lookup.
name|bool
name|requiresADL
argument_list|()
specifier|const
block|{
return|return
name|RequiresADL
return|;
block|}
comment|/// True if namespace ::std should be artificially added to the set of
comment|/// associated namespaecs for argument-dependent lookup purposes.
name|bool
name|isStdAssociatedNamespace
argument_list|()
specifier|const
block|{
return|return
name|StdIsAssociatedNamespace
return|;
block|}
comment|/// True if this lookup is overloaded.
name|bool
name|isOverloaded
argument_list|()
specifier|const
block|{
return|return
name|Overloaded
return|;
block|}
comment|/// Gets the 'naming class' (in the sense of C++0x
comment|/// [class.access.base]p5) of the lookup.  This is the scope
comment|/// that was looked in to find these results.
name|CXXRecordDecl
operator|*
name|getNamingClass
argument_list|()
specifier|const
block|{
return|return
name|NamingClass
return|;
block|}
comment|// Note that, inconsistently with the explicit-template-argument AST
comment|// nodes, users are *forbidden* from calling these methods on objects
comment|// without explicit template arguments.
name|ExplicitTemplateArgumentList
operator|&
name|getExplicitTemplateArgs
argument_list|()
block|{
name|assert
argument_list|(
name|hasExplicitTemplateArgs
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|reinterpret_cast
operator|<
name|ExplicitTemplateArgumentList
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// Gets a reference to the explicit template argument list.
specifier|const
name|ExplicitTemplateArgumentList
operator|&
name|getExplicitTemplateArgs
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasExplicitTemplateArgs
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|ExplicitTemplateArgumentList
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieves the optional explicit template arguments.
comment|/// This points to the same data as getExplicitTemplateArgs(), but
comment|/// returns null if there are no explicit template arguments.
specifier|const
name|ExplicitTemplateArgumentList
operator|*
name|getOptionalExplicitTemplateArgs
argument_list|()
block|{
if|if
condition|(
operator|!
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
operator|&
name|getExplicitTemplateArgs
argument_list|()
return|;
block|}
comment|/// \brief Copies the template arguments (if present) into the given
comment|/// structure.
name|void
name|copyTemplateArgumentsInto
argument_list|(
argument|TemplateArgumentListInfo&List
argument_list|)
specifier|const
block|{
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|copyInto
argument_list|(
name|List
argument_list|)
block|;   }
name|SourceLocation
name|getLAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|LAngleLoc
return|;
block|}
name|SourceLocation
name|getRAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|RAngleLoc
return|;
block|}
name|TemplateArgumentLoc
specifier|const
operator|*
name|getTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|getTemplateArgs
argument_list|()
return|;
block|}
name|unsigned
name|getNumTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|NumTemplateArgs
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
name|SourceRange
name|Range
argument_list|(
name|getNameInfo
argument_list|()
operator|.
name|getSourceRange
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|getQualifierLoc
argument_list|()
condition|)
name|Range
operator|.
name|setBegin
argument_list|(
name|getQualifierLoc
argument_list|()
operator|.
name|getBeginLoc
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasExplicitTemplateArgs
argument_list|()
condition|)
name|Range
operator|.
name|setEnd
argument_list|(
name|getRAngleLoc
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|Range
return|;
block|}
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
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
name|UnresolvedLookupExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const UnresolvedLookupExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// \brief A qualified reference to a name whose declaration cannot
comment|/// yet be resolved.
comment|///
comment|/// DependentScopeDeclRefExpr is similar to DeclRefExpr in that
comment|/// it expresses a reference to a declaration such as
comment|/// X<T>::value. The difference, however, is that an
comment|/// DependentScopeDeclRefExpr node is used only within C++ templates when
comment|/// the qualification (e.g., X<T>::) refers to a dependent type. In
comment|/// this case, X<T>::value cannot resolve to a declaration because the
comment|/// declaration will differ from on instantiation of X<T> to the
comment|/// next. Therefore, DependentScopeDeclRefExpr keeps track of the
comment|/// qualifier (X<T>::) and the name of the entity being referenced
comment|/// ("value"). Such expressions will instantiate to a DeclRefExpr once the
comment|/// declaration can be found.
name|class
name|DependentScopeDeclRefExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The nested-name-specifier that qualifies this unresolved
comment|/// declaration name.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
comment|/// The name of the entity we will be referencing.
name|DeclarationNameInfo
name|NameInfo
block|;
comment|/// \brief Whether the name includes explicit template arguments.
name|bool
name|HasExplicitTemplateArgs
block|;
name|DependentScopeDeclRefExpr
argument_list|(
argument|QualType T
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|const TemplateArgumentListInfo *Args
argument_list|)
block|;
name|public
operator|:
specifier|static
name|DependentScopeDeclRefExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs =
literal|0
argument_list|)
block|;
specifier|static
name|DependentScopeDeclRefExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&C
argument_list|,
argument|bool HasExplicitTemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|)
block|;
comment|/// \brief Retrieve the name that this expression refers to.
specifier|const
name|DeclarationNameInfo
operator|&
name|getNameInfo
argument_list|()
specifier|const
block|{
return|return
name|NameInfo
return|;
block|}
comment|/// \brief Retrieve the name that this expression refers to.
name|DeclarationName
name|getDeclName
argument_list|()
specifier|const
block|{
return|return
name|NameInfo
operator|.
name|getName
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the location of the name within the expression.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|NameInfo
operator|.
name|getLoc
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies the
comment|/// name, with source location information.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies this
comment|/// declaration.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
return|;
block|}
comment|/// Determines whether this lookup had explicit template arguments.
name|bool
name|hasExplicitTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|HasExplicitTemplateArgs
return|;
block|}
comment|// Note that, inconsistently with the explicit-template-argument AST
comment|// nodes, users are *forbidden* from calling these methods on objects
comment|// without explicit template arguments.
name|ExplicitTemplateArgumentList
operator|&
name|getExplicitTemplateArgs
argument_list|()
block|{
name|assert
argument_list|(
name|hasExplicitTemplateArgs
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|reinterpret_cast
operator|<
name|ExplicitTemplateArgumentList
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// Gets a reference to the explicit template argument list.
specifier|const
name|ExplicitTemplateArgumentList
operator|&
name|getExplicitTemplateArgs
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasExplicitTemplateArgs
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|ExplicitTemplateArgumentList
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieves the optional explicit template arguments.
comment|/// This points to the same data as getExplicitTemplateArgs(), but
comment|/// returns null if there are no explicit template arguments.
specifier|const
name|ExplicitTemplateArgumentList
operator|*
name|getOptionalExplicitTemplateArgs
argument_list|()
block|{
if|if
condition|(
operator|!
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
operator|&
name|getExplicitTemplateArgs
argument_list|()
return|;
block|}
comment|/// \brief Copies the template arguments (if present) into the given
comment|/// structure.
name|void
name|copyTemplateArgumentsInto
argument_list|(
argument|TemplateArgumentListInfo&List
argument_list|)
specifier|const
block|{
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|copyInto
argument_list|(
name|List
argument_list|)
block|;   }
name|SourceLocation
name|getLAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|LAngleLoc
return|;
block|}
name|SourceLocation
name|getRAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|RAngleLoc
return|;
block|}
name|TemplateArgumentLoc
specifier|const
operator|*
name|getTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|getTemplateArgs
argument_list|()
return|;
block|}
name|unsigned
name|getNumTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|NumTemplateArgs
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
name|SourceRange
name|Range
argument_list|(
name|QualifierLoc
operator|.
name|getBeginLoc
argument_list|()
argument_list|,
name|getLocation
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|hasExplicitTemplateArgs
argument_list|()
condition|)
name|Range
operator|.
name|setEnd
argument_list|(
name|getRAngleLoc
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|Range
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
name|DependentScopeDeclRefExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DependentScopeDeclRefExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|; }
block|;
comment|/// Represents an expression --- generally a full-expression --- which
comment|/// introduces cleanups to be run at the end of the sub-expression's
comment|/// evaluation.  The most common source of expression-introduced
comment|/// cleanups is temporary objects in C++, but several other C++
comment|/// expressions can create cleanups.
name|class
name|ExprWithCleanups
operator|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|SubExpr
block|;
name|CXXTemporary
operator|*
operator|*
name|Temps
block|;
name|unsigned
name|NumTemps
block|;
name|ExprWithCleanups
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr *SubExpr
argument_list|,
argument|CXXTemporary **Temps
argument_list|,
argument|unsigned NumTemps
argument_list|)
block|;
name|public
operator|:
name|ExprWithCleanups
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|ExprWithCleanupsClass
argument_list|,
name|Empty
argument_list|)
block|,
name|SubExpr
argument_list|(
literal|0
argument_list|)
block|,
name|Temps
argument_list|(
literal|0
argument_list|)
block|,
name|NumTemps
argument_list|(
literal|0
argument_list|)
block|{}
specifier|static
name|ExprWithCleanups
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr *SubExpr
argument_list|,
argument|CXXTemporary **Temps
argument_list|,
argument|unsigned NumTemps
argument_list|)
block|;
name|unsigned
name|getNumTemporaries
argument_list|()
specifier|const
block|{
return|return
name|NumTemps
return|;
block|}
name|void
name|setNumTemporaries
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned N
argument_list|)
block|;
name|CXXTemporary
operator|*
name|getTemporary
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumTemps
operator|&&
literal|"Index out of range"
argument_list|)
block|;
return|return
name|Temps
index|[
name|i
index|]
return|;
block|}
specifier|const
name|CXXTemporary
operator|*
name|getTemporary
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ExprWithCleanups
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getTemporary
argument_list|(
name|i
argument_list|)
return|;
block|}
name|void
name|setTemporary
argument_list|(
argument|unsigned i
argument_list|,
argument|CXXTemporary *T
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumTemps
operator|&&
literal|"Index out of range"
argument_list|)
block|;
name|Temps
index|[
name|i
index|]
operator|=
name|T
block|;   }
name|Expr
operator|*
name|getSubExpr
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExpr
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getSubExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExpr
operator|)
return|;
block|}
name|void
name|setSubExpr
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExpr
operator|=
name|E
block|; }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SubExpr
operator|->
name|getSourceRange
argument_list|()
return|;
block|}
comment|// Implement isa/cast/dyncast/etc.
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
name|ExprWithCleanupsClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ExprWithCleanups *
argument_list|)
block|{
return|return
name|true
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
name|SubExpr
argument_list|,
operator|&
name|SubExpr
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief Describes an explicit type conversion that uses functional
comment|/// notion but could not be resolved because one or more arguments are
comment|/// type-dependent.
comment|///
comment|/// The explicit type conversions expressed by
comment|/// CXXUnresolvedConstructExpr have the form \c T(a1, a2, ..., aN),
comment|/// where \c T is some type and \c a1, a2, ..., aN are values, and
comment|/// either \C T is a dependent type or one or more of the \c a's is
comment|/// type-dependent. For example, this would occur in a template such
comment|/// as:
comment|///
comment|/// \code
comment|///   template<typename T, typename A1>
comment|///   inline T make_a(const A1& a1) {
comment|///     return T(a1);
comment|///   }
comment|/// \endcode
comment|///
comment|/// When the returned expression is instantiated, it may resolve to a
comment|/// constructor call, conversion function call, or some kind of type
comment|/// conversion.
name|class
name|CXXUnresolvedConstructExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The type being constructed.
name|TypeSourceInfo
operator|*
name|Type
block|;
comment|/// \brief The location of the left parentheses ('(').
name|SourceLocation
name|LParenLoc
block|;
comment|/// \brief The location of the right parentheses (')').
name|SourceLocation
name|RParenLoc
block|;
comment|/// \brief The number of arguments used to construct the type.
name|unsigned
name|NumArgs
block|;
name|CXXUnresolvedConstructExpr
argument_list|(
argument|TypeSourceInfo *Type
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|Expr **Args
argument_list|,
argument|unsigned NumArgs
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|;
name|CXXUnresolvedConstructExpr
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|unsigned NumArgs
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXUnresolvedConstructExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|Type
argument_list|()
block|,
name|NumArgs
argument_list|(
argument|NumArgs
argument_list|)
block|{ }
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
specifier|static
name|CXXUnresolvedConstructExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|TypeSourceInfo *Type
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|Expr **Args
argument_list|,
argument|unsigned NumArgs
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|;
specifier|static
name|CXXUnresolvedConstructExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned NumArgs
argument_list|)
block|;
comment|/// \brief Retrieve the type that is being constructed, as specified
comment|/// in the source code.
name|QualType
name|getTypeAsWritten
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|->
name|getType
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the type source information for the type being
comment|/// constructed.
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
comment|/// \brief Retrieve the location of the left parentheses ('(') that
comment|/// precedes the argument list.
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
name|void
name|setLParenLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|LParenLoc
operator|=
name|L
block|; }
comment|/// \brief Retrieve the location of the right parentheses (')') that
comment|/// follows the argument list.
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
argument|SourceLocation L
argument_list|)
block|{
name|RParenLoc
operator|=
name|L
block|; }
comment|/// \brief Retrieve the number of arguments.
name|unsigned
name|arg_size
argument_list|()
specifier|const
block|{
return|return
name|NumArgs
return|;
block|}
typedef|typedef
name|Expr
modifier|*
modifier|*
name|arg_iterator
typedef|;
name|arg_iterator
name|arg_begin
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|Expr
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
name|arg_iterator
name|arg_end
argument_list|()
block|{
return|return
name|arg_begin
argument_list|()
operator|+
name|NumArgs
return|;
block|}
typedef|typedef
specifier|const
name|Expr
modifier|*
specifier|const
modifier|*
name|const_arg_iterator
typedef|;
name|const_arg_iterator
name|arg_begin
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|Expr
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
name|const_arg_iterator
name|arg_end
argument_list|()
specifier|const
block|{
return|return
name|arg_begin
argument_list|()
operator|+
name|NumArgs
return|;
block|}
name|Expr
operator|*
name|getArg
argument_list|(
argument|unsigned I
argument_list|)
block|{
name|assert
argument_list|(
name|I
operator|<
name|NumArgs
operator|&&
literal|"Argument index out-of-range"
argument_list|)
block|;
return|return
operator|*
operator|(
name|arg_begin
argument_list|()
operator|+
name|I
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArg
argument_list|(
argument|unsigned I
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|NumArgs
operator|&&
literal|"Argument index out-of-range"
argument_list|)
block|;
return|return
operator|*
operator|(
name|arg_begin
argument_list|()
operator|+
name|I
operator|)
return|;
block|}
name|void
name|setArg
argument_list|(
argument|unsigned I
argument_list|,
argument|Expr *E
argument_list|)
block|{
name|assert
argument_list|(
name|I
operator|<
name|NumArgs
operator|&&
literal|"Argument index out-of-range"
argument_list|)
block|;
operator|*
operator|(
name|arg_begin
argument_list|()
operator|+
name|I
operator|)
operator|=
name|E
block|;   }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|;
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
name|CXXUnresolvedConstructExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXUnresolvedConstructExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
name|Stmt
operator|*
operator|*
name|begin
operator|=
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
block|;
return|return
name|child_range
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
name|NumArgs
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a C++ member access expression where the actual
comment|/// member referenced could not be resolved because the base
comment|/// expression or the member name was dependent.
comment|///
comment|/// Like UnresolvedMemberExprs, these can be either implicit or
comment|/// explicit accesses.  It is only possible to get one of these with
comment|/// an implicit access if a qualifier is provided.
name|class
name|CXXDependentScopeMemberExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The expression for the base pointer or class reference,
comment|/// e.g., the \c x in x.f.  Can be null in implicit accesses.
name|Stmt
operator|*
name|Base
block|;
comment|/// \brief The type of the base expression.  Never null, even for
comment|/// implicit accesses.
name|QualType
name|BaseType
block|;
comment|/// \brief Whether this member expression used the '->' operator or
comment|/// the '.' operator.
name|bool
name|IsArrow
operator|:
literal|1
block|;
comment|/// \brief Whether this member expression has explicitly-specified template
comment|/// arguments.
name|bool
name|HasExplicitTemplateArgs
operator|:
literal|1
block|;
comment|/// \brief The location of the '->' or '.' operator.
name|SourceLocation
name|OperatorLoc
block|;
comment|/// \brief The nested-name-specifier that precedes the member name, if any.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
comment|/// \brief In a qualified member access expression such as t->Base::f, this
comment|/// member stores the resolves of name lookup in the context of the member
comment|/// access expression, to be used at instantiation time.
comment|///
comment|/// FIXME: This member, along with the QualifierLoc, could
comment|/// be stuck into a structure that is optionally allocated at the end of
comment|/// the CXXDependentScopeMemberExpr, to save space in the common case.
name|NamedDecl
operator|*
name|FirstQualifierFoundInScope
block|;
comment|/// \brief The member to which this member expression refers, which
comment|/// can be name, overloaded operator, or destructor.
comment|/// FIXME: could also be a template-id
name|DeclarationNameInfo
name|MemberNameInfo
block|;
name|CXXDependentScopeMemberExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr *Base
argument_list|,
argument|QualType BaseType
argument_list|,
argument|bool IsArrow
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|NamedDecl *FirstQualifierFoundInScope
argument_list|,
argument|DeclarationNameInfo MemberNameInfo
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|)
block|;
name|public
operator|:
name|CXXDependentScopeMemberExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr *Base
argument_list|,
argument|QualType BaseType
argument_list|,
argument|bool IsArrow
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|NamedDecl *FirstQualifierFoundInScope
argument_list|,
argument|DeclarationNameInfo MemberNameInfo
argument_list|)
block|;
specifier|static
name|CXXDependentScopeMemberExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr *Base
argument_list|,
argument|QualType BaseType
argument_list|,
argument|bool IsArrow
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|NamedDecl *FirstQualifierFoundInScope
argument_list|,
argument|DeclarationNameInfo MemberNameInfo
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|)
block|;
specifier|static
name|CXXDependentScopeMemberExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&C
argument_list|,
argument|bool HasExplicitTemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|)
block|;
comment|/// \brief True if this is an implicit access, i.e. one in which the
comment|/// member being accessed was not written in the source.  The source
comment|/// location of the operator is invalid in this case.
name|bool
name|isImplicitAccess
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve the base object of this member expressions,
comment|/// e.g., the \c x in \c x.m.
name|Expr
operator|*
name|getBase
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isImplicitAccess
argument_list|()
argument_list|)
block|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|QualType
name|getBaseType
argument_list|()
specifier|const
block|{
return|return
name|BaseType
return|;
block|}
comment|/// \brief Determine whether this member expression used the '->'
comment|/// operator; otherwise, it used the '.' operator.
name|bool
name|isArrow
argument_list|()
specifier|const
block|{
return|return
name|IsArrow
return|;
block|}
comment|/// \brief Retrieve the location of the '->' or '.' operator.
name|SourceLocation
name|getOperatorLoc
argument_list|()
specifier|const
block|{
return|return
name|OperatorLoc
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies the member
comment|/// name.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies the member
comment|/// name, with source location information.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief Retrieve the first part of the nested-name-specifier that was
comment|/// found in the scope of the member access expression when the member access
comment|/// was initially parsed.
comment|///
comment|/// This function only returns a useful result when member access expression
comment|/// uses a qualified member name, e.g., "x.Base::f". Here, the declaration
comment|/// returned by this function describes what was found by unqualified name
comment|/// lookup for the identifier "Base" within the scope of the member access
comment|/// expression itself. At template instantiation time, this information is
comment|/// combined with the results of name lookup into the type of the object
comment|/// expression itself (the class type of x).
name|NamedDecl
operator|*
name|getFirstQualifierFoundInScope
argument_list|()
specifier|const
block|{
return|return
name|FirstQualifierFoundInScope
return|;
block|}
comment|/// \brief Retrieve the name of the member that this expression
comment|/// refers to.
specifier|const
name|DeclarationNameInfo
operator|&
name|getMemberNameInfo
argument_list|()
specifier|const
block|{
return|return
name|MemberNameInfo
return|;
block|}
comment|/// \brief Retrieve the name of the member that this expression
comment|/// refers to.
name|DeclarationName
name|getMember
argument_list|()
specifier|const
block|{
return|return
name|MemberNameInfo
operator|.
name|getName
argument_list|()
return|;
block|}
comment|// \brief Retrieve the location of the name of the member that this
comment|// expression refers to.
name|SourceLocation
name|getMemberLoc
argument_list|()
specifier|const
block|{
return|return
name|MemberNameInfo
operator|.
name|getLoc
argument_list|()
return|;
block|}
comment|/// \brief Determines whether this member expression actually had a C++
comment|/// template argument list explicitly specified, e.g., x.f<int>.
name|bool
name|hasExplicitTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|HasExplicitTemplateArgs
return|;
block|}
comment|/// \brief Retrieve the explicit template argument list that followed the
comment|/// member template name, if any.
name|ExplicitTemplateArgumentList
operator|&
name|getExplicitTemplateArgs
argument_list|()
block|{
name|assert
argument_list|(
name|HasExplicitTemplateArgs
argument_list|)
block|;
return|return
operator|*
name|reinterpret_cast
operator|<
name|ExplicitTemplateArgumentList
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieve the explicit template argument list that followed the
comment|/// member template name, if any.
specifier|const
name|ExplicitTemplateArgumentList
operator|&
name|getExplicitTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|CXXDependentScopeMemberExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getExplicitTemplateArgs
argument_list|()
return|;
block|}
comment|/// \brief Retrieves the optional explicit template arguments.
comment|/// This points to the same data as getExplicitTemplateArgs(), but
comment|/// returns null if there are no explicit template arguments.
specifier|const
name|ExplicitTemplateArgumentList
operator|*
name|getOptionalExplicitTemplateArgs
argument_list|()
block|{
if|if
condition|(
operator|!
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
operator|&
name|getExplicitTemplateArgs
argument_list|()
return|;
block|}
comment|/// \brief Copies the template arguments (if present) into the given
comment|/// structure.
name|void
name|copyTemplateArgumentsInto
argument_list|(
argument|TemplateArgumentListInfo&List
argument_list|)
specifier|const
block|{
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|copyInto
argument_list|(
name|List
argument_list|)
block|;   }
comment|/// \brief Initializes the template arguments using the given structure.
name|void
name|initializeTemplateArgumentsFrom
argument_list|(
argument|const TemplateArgumentListInfo&List
argument_list|)
block|{
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|initializeFrom
argument_list|(
name|List
argument_list|)
block|;   }
comment|/// \brief Retrieve the location of the left angle bracket following the
comment|/// member name ('<'), if any.
name|SourceLocation
name|getLAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|LAngleLoc
return|;
block|}
comment|/// \brief Retrieve the template arguments provided as part of this
comment|/// template-id.
specifier|const
name|TemplateArgumentLoc
operator|*
name|getTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|getTemplateArgs
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the number of template arguments provided as part of this
comment|/// template-id.
name|unsigned
name|getNumTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|NumTemplateArgs
return|;
block|}
comment|/// \brief Retrieve the location of the right angle bracket following the
comment|/// template arguments ('>').
name|SourceLocation
name|getRAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|RAngleLoc
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
name|SourceRange
name|Range
block|;
if|if
condition|(
operator|!
name|isImplicitAccess
argument_list|()
condition|)
name|Range
operator|.
name|setBegin
argument_list|(
name|Base
operator|->
name|getSourceRange
argument_list|()
operator|.
name|getBegin
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|getQualifier
argument_list|()
condition|)
name|Range
operator|.
name|setBegin
argument_list|(
name|getQualifierLoc
argument_list|()
operator|.
name|getBeginLoc
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|Range
operator|.
name|setBegin
argument_list|(
name|MemberNameInfo
operator|.
name|getBeginLoc
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasExplicitTemplateArgs
argument_list|()
condition|)
name|Range
operator|.
name|setEnd
argument_list|(
name|getRAngleLoc
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|Range
operator|.
name|setEnd
argument_list|(
name|MemberNameInfo
operator|.
name|getEndLoc
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|Range
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
name|CXXDependentScopeMemberExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXDependentScopeMemberExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
if|if
condition|(
name|isImplicitAccess
argument_list|()
condition|)
return|return
name|child_range
argument_list|()
return|;
return|return
name|child_range
argument_list|(
operator|&
name|Base
argument_list|,
operator|&
name|Base
operator|+
literal|1
argument_list|)
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|; }
block|;
comment|/// \brief Represents a C++ member access expression for which lookup
comment|/// produced a set of overloaded functions.
comment|///
comment|/// The member access may be explicit or implicit:
comment|///    struct A {
comment|///      int a, b;
comment|///      int explicitAccess() { return this->a + this->A::b; }
comment|///      int implicitAccess() { return a + A::b; }
comment|///    };
comment|///
comment|/// In the final AST, an explicit access always becomes a MemberExpr.
comment|/// An implicit access may become either a MemberExpr or a
comment|/// DeclRefExpr, depending on whether the member is static.
name|class
name|UnresolvedMemberExpr
operator|:
name|public
name|OverloadExpr
block|{
comment|/// \brief Whether this member expression used the '->' operator or
comment|/// the '.' operator.
name|bool
name|IsArrow
operator|:
literal|1
block|;
comment|/// \brief Whether the lookup results contain an unresolved using
comment|/// declaration.
name|bool
name|HasUnresolvedUsing
operator|:
literal|1
block|;
comment|/// \brief The expression for the base pointer or class reference,
comment|/// e.g., the \c x in x.f.  This can be null if this is an 'unbased'
comment|/// member expression
name|Stmt
operator|*
name|Base
block|;
comment|/// \brief The type of the base expression;  never null.
name|QualType
name|BaseType
block|;
comment|/// \brief The location of the '->' or '.' operator.
name|SourceLocation
name|OperatorLoc
block|;
name|UnresolvedMemberExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|bool HasUnresolvedUsing
argument_list|,
argument|Expr *Base
argument_list|,
argument|QualType BaseType
argument_list|,
argument|bool IsArrow
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&MemberNameInfo
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|,
argument|UnresolvedSetIterator Begin
argument_list|,
argument|UnresolvedSetIterator End
argument_list|)
block|;
name|UnresolvedMemberExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|OverloadExpr
argument_list|(
name|UnresolvedMemberExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|IsArrow
argument_list|(
name|false
argument_list|)
block|,
name|HasUnresolvedUsing
argument_list|(
name|false
argument_list|)
block|,
name|Base
argument_list|(
literal|0
argument_list|)
block|{ }
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
specifier|static
name|UnresolvedMemberExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|bool HasUnresolvedUsing
argument_list|,
argument|Expr *Base
argument_list|,
argument|QualType BaseType
argument_list|,
argument|bool IsArrow
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&MemberNameInfo
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|,
argument|UnresolvedSetIterator Begin
argument_list|,
argument|UnresolvedSetIterator End
argument_list|)
block|;
specifier|static
name|UnresolvedMemberExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&C
argument_list|,
argument|bool HasExplicitTemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|)
block|;
comment|/// \brief True if this is an implicit access, i.e. one in which the
comment|/// member being accessed was not written in the source.  The source
comment|/// location of the operator is invalid in this case.
name|bool
name|isImplicitAccess
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve the base object of this member expressions,
comment|/// e.g., the \c x in \c x.m.
name|Expr
operator|*
name|getBase
argument_list|()
block|{
name|assert
argument_list|(
operator|!
name|isImplicitAccess
argument_list|()
argument_list|)
block|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getBase
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isImplicitAccess
argument_list|()
argument_list|)
block|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|QualType
name|getBaseType
argument_list|()
specifier|const
block|{
return|return
name|BaseType
return|;
block|}
comment|/// \brief Determine whether the lookup results contain an unresolved using
comment|/// declaration.
name|bool
name|hasUnresolvedUsing
argument_list|()
specifier|const
block|{
return|return
name|HasUnresolvedUsing
return|;
block|}
comment|/// \brief Determine whether this member expression used the '->'
comment|/// operator; otherwise, it used the '.' operator.
name|bool
name|isArrow
argument_list|()
specifier|const
block|{
return|return
name|IsArrow
return|;
block|}
comment|/// \brief Retrieve the location of the '->' or '.' operator.
name|SourceLocation
name|getOperatorLoc
argument_list|()
specifier|const
block|{
return|return
name|OperatorLoc
return|;
block|}
comment|/// \brief Retrieves the naming class of this lookup.
name|CXXRecordDecl
operator|*
name|getNamingClass
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve the full name info for the member that this expression
comment|/// refers to.
specifier|const
name|DeclarationNameInfo
operator|&
name|getMemberNameInfo
argument_list|()
specifier|const
block|{
return|return
name|getNameInfo
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the name of the member that this expression
comment|/// refers to.
name|DeclarationName
name|getMemberName
argument_list|()
specifier|const
block|{
return|return
name|getName
argument_list|()
return|;
block|}
comment|// \brief Retrieve the location of the name of the member that this
comment|// expression refers to.
name|SourceLocation
name|getMemberLoc
argument_list|()
specifier|const
block|{
return|return
name|getNameLoc
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the explicit template argument list that followed the
comment|/// member template name.
name|ExplicitTemplateArgumentList
operator|&
name|getExplicitTemplateArgs
argument_list|()
block|{
name|assert
argument_list|(
name|hasExplicitTemplateArgs
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|reinterpret_cast
operator|<
name|ExplicitTemplateArgumentList
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieve the explicit template argument list that followed the
comment|/// member template name, if any.
specifier|const
name|ExplicitTemplateArgumentList
operator|&
name|getExplicitTemplateArgs
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasExplicitTemplateArgs
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|ExplicitTemplateArgumentList
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieves the optional explicit template arguments.
comment|/// This points to the same data as getExplicitTemplateArgs(), but
comment|/// returns null if there are no explicit template arguments.
specifier|const
name|ExplicitTemplateArgumentList
operator|*
name|getOptionalExplicitTemplateArgs
argument_list|()
block|{
if|if
condition|(
operator|!
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
operator|&
name|getExplicitTemplateArgs
argument_list|()
return|;
block|}
comment|/// \brief Copies the template arguments into the given structure.
name|void
name|copyTemplateArgumentsInto
argument_list|(
argument|TemplateArgumentListInfo&List
argument_list|)
specifier|const
block|{
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|copyInto
argument_list|(
name|List
argument_list|)
block|;   }
comment|/// \brief Retrieve the location of the left angle bracket following
comment|/// the member name ('<').
name|SourceLocation
name|getLAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|LAngleLoc
return|;
block|}
comment|/// \brief Retrieve the template arguments provided as part of this
comment|/// template-id.
specifier|const
name|TemplateArgumentLoc
operator|*
name|getTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|getTemplateArgs
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the number of template arguments provided as
comment|/// part of this template-id.
name|unsigned
name|getNumTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|NumTemplateArgs
return|;
block|}
comment|/// \brief Retrieve the location of the right angle bracket
comment|/// following the template arguments ('>').
name|SourceLocation
name|getRAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|getExplicitTemplateArgs
argument_list|()
operator|.
name|RAngleLoc
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
name|SourceRange
name|Range
operator|=
name|getMemberNameInfo
argument_list|()
operator|.
name|getSourceRange
argument_list|()
block|;
if|if
condition|(
operator|!
name|isImplicitAccess
argument_list|()
condition|)
name|Range
operator|.
name|setBegin
argument_list|(
name|Base
operator|->
name|getSourceRange
argument_list|()
operator|.
name|getBegin
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|getQualifierLoc
argument_list|()
condition|)
name|Range
operator|.
name|setBegin
argument_list|(
name|getQualifierLoc
argument_list|()
operator|.
name|getBeginLoc
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasExplicitTemplateArgs
argument_list|()
condition|)
name|Range
operator|.
name|setEnd
argument_list|(
name|getRAngleLoc
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|Range
return|;
block|}
end_decl_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|T
parameter_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|UnresolvedMemberExprClass
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|UnresolvedMemberExpr
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|// Iterators
end_comment

begin_function
name|child_range
name|children
parameter_list|()
block|{
if|if
condition|(
name|isImplicitAccess
argument_list|()
condition|)
return|return
name|child_range
argument_list|()
return|;
return|return
name|child_range
argument_list|(
operator|&
name|Base
argument_list|,
operator|&
name|Base
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief Represents a C++0x noexcept expression (C++ [expr.unary.noexcept]).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The noexcept expression tests whether a given expression might throw. Its
end_comment

begin_comment
comment|/// result is a boolean constant.
end_comment

begin_decl_stmt
name|class
name|CXXNoexceptExpr
range|:
name|public
name|Expr
block|{
name|bool
name|Value
operator|:
literal|1
block|;
name|Stmt
operator|*
name|Operand
block|;
name|SourceRange
name|Range
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
name|CXXNoexceptExpr
argument_list|(
argument|QualType Ty
argument_list|,
argument|Expr *Operand
argument_list|,
argument|CanThrowResult Val
argument_list|,
argument|SourceLocation Keyword
argument_list|,
argument|SourceLocation RParen
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXNoexceptExprClass
argument_list|,
name|Ty
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
comment|/*TypeDependent*/
name|false
argument_list|,
comment|/*ValueDependent*/
name|Val
operator|==
name|CT_Dependent
argument_list|,
name|Operand
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Value
argument_list|(
name|Val
operator|==
name|CT_Cannot
argument_list|)
block|,
name|Operand
argument_list|(
name|Operand
argument_list|)
block|,
name|Range
argument_list|(
argument|Keyword
argument_list|,
argument|RParen
argument_list|)
block|{ }
name|CXXNoexceptExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CXXNoexceptExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|Expr
operator|*
name|getOperand
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|Operand
operator|)
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|Range
return|;
block|}
name|bool
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
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
name|CXXNoexceptExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXNoexceptExpr *
argument_list|)
block|{
return|return
name|true
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
name|Operand
argument_list|,
operator|&
name|Operand
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a C++0x pack expansion that produces a sequence of
comment|/// expressions.
comment|///
comment|/// A pack expansion expression contains a pattern (which itself is an
comment|/// expression) followed by an ellipsis. For example:
comment|///
comment|/// \code
comment|/// template<typename F, typename ...Types>
comment|/// void forward(F f, Types&&...args) {
comment|///   f(static_cast<Types&&>(args)...);
comment|/// }
comment|/// \endcode
comment|///
comment|/// Here, the argument to the function object \c f is a pack expansion whose
comment|/// pattern is \c static_cast<Types&&>(args). When the \c forward function
comment|/// template is instantiated, the pack expansion will instantiate to zero or
comment|/// or more function arguments to the function object \c f.
name|class
name|PackExpansionExpr
operator|:
name|public
name|Expr
block|{
name|SourceLocation
name|EllipsisLoc
block|;
comment|/// \brief The number of expansions that will be produced by this pack
comment|/// expansion expression, if known.
comment|///
comment|/// When zero, the number of expansions is not known. Otherwise, this value
comment|/// is the number of expansions + 1.
name|unsigned
name|NumExpansions
block|;
name|Stmt
operator|*
name|Pattern
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|;
name|public
operator|:
name|PackExpansionExpr
argument_list|(
argument|QualType T
argument_list|,
argument|Expr *Pattern
argument_list|,
argument|SourceLocation EllipsisLoc
argument_list|,
argument|llvm::Optional<unsigned> NumExpansions
argument_list|)
operator|:
name|Expr
argument_list|(
name|PackExpansionExprClass
argument_list|,
name|T
argument_list|,
name|Pattern
operator|->
name|getValueKind
argument_list|()
argument_list|,
name|Pattern
operator|->
name|getObjectKind
argument_list|()
argument_list|,
comment|/*TypeDependent=*/
name|true
argument_list|,
comment|/*ValueDependent=*/
name|true
argument_list|,
comment|/*ContainsUnexpandedParameterPack=*/
name|false
argument_list|)
block|,
name|EllipsisLoc
argument_list|(
name|EllipsisLoc
argument_list|)
block|,
name|NumExpansions
argument_list|(
name|NumExpansions
condition|?
operator|*
name|NumExpansions
operator|+
literal|1
else|:
literal|0
argument_list|)
block|,
name|Pattern
argument_list|(
argument|Pattern
argument_list|)
block|{ }
name|PackExpansionExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|PackExpansionExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// \brief Retrieve the pattern of the pack expansion.
name|Expr
operator|*
name|getPattern
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|Pattern
operator|)
return|;
block|}
comment|/// \brief Retrieve the pattern of the pack expansion.
specifier|const
name|Expr
operator|*
name|getPattern
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|Pattern
operator|)
return|;
block|}
comment|/// \brief Retrieve the location of the ellipsis that describes this pack
comment|/// expansion.
name|SourceLocation
name|getEllipsisLoc
argument_list|()
specifier|const
block|{
return|return
name|EllipsisLoc
return|;
block|}
comment|/// \brief Determine the number of expansions that will be produced when
comment|/// this pack expansion is instantiated, if already known.
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|getNumExpansions
argument_list|()
specifier|const
block|{
if|if
condition|(
name|NumExpansions
condition|)
return|return
name|NumExpansions
operator|-
literal|1
return|;
return|return
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
operator|(
operator|)
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Pattern
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|EllipsisLoc
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
name|PackExpansionExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const PackExpansionExpr *
argument_list|)
block|{
return|return
name|true
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
name|Pattern
argument_list|,
operator|&
name|Pattern
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
specifier|inline
name|ExplicitTemplateArgumentList
operator|&
name|OverloadExpr
operator|::
name|getExplicitTemplateArgs
argument_list|()
block|{
if|if
condition|(
name|isa
operator|<
name|UnresolvedLookupExpr
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|cast
operator|<
name|UnresolvedLookupExpr
operator|>
operator|(
name|this
operator|)
operator|->
name|getExplicitTemplateArgs
argument_list|()
return|;
else|else
return|return
name|cast
operator|<
name|UnresolvedMemberExpr
operator|>
operator|(
name|this
operator|)
operator|->
name|getExplicitTemplateArgs
argument_list|()
return|;
block|}
comment|/// \brief Represents an expression that computes the length of a parameter
comment|/// pack.
comment|///
comment|/// \code
comment|/// template<typename ...Types>
comment|/// struct count {
comment|///   static const unsigned value = sizeof...(Types);
comment|/// };
comment|/// \endcode
name|class
name|SizeOfPackExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The location of the 'sizeof' keyword.
name|SourceLocation
name|OperatorLoc
block|;
comment|/// \brief The location of the name of the parameter pack.
name|SourceLocation
name|PackLoc
block|;
comment|/// \brief The location of the closing parenthesis.
name|SourceLocation
name|RParenLoc
block|;
comment|/// \brief The length of the parameter pack, if known.
comment|///
comment|/// When this expression is value-dependent, the length of the parameter pack
comment|/// is unknown. When this expression is not value-dependent, the length is
comment|/// known.
name|unsigned
name|Length
block|;
comment|/// \brief The parameter pack itself.
name|NamedDecl
operator|*
name|Pack
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|;
name|public
operator|:
comment|/// \brief Creates a value-dependent expression that computes the length of
comment|/// the given parameter pack.
name|SizeOfPackExpr
argument_list|(
argument|QualType SizeType
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|NamedDecl *Pack
argument_list|,
argument|SourceLocation PackLoc
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
operator|:
name|Expr
argument_list|(
name|SizeOfPackExprClass
argument_list|,
name|SizeType
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
comment|/*TypeDependent=*/
name|false
argument_list|,
comment|/*ValueDependent=*/
name|true
argument_list|,
comment|/*ContainsUnexpandedParameterPack=*/
name|false
argument_list|)
block|,
name|OperatorLoc
argument_list|(
name|OperatorLoc
argument_list|)
block|,
name|PackLoc
argument_list|(
name|PackLoc
argument_list|)
block|,
name|RParenLoc
argument_list|(
name|RParenLoc
argument_list|)
block|,
name|Length
argument_list|(
literal|0
argument_list|)
block|,
name|Pack
argument_list|(
argument|Pack
argument_list|)
block|{ }
comment|/// \brief Creates an expression that computes the length of
comment|/// the given parameter pack, which is already known.
name|SizeOfPackExpr
argument_list|(
argument|QualType SizeType
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|NamedDecl *Pack
argument_list|,
argument|SourceLocation PackLoc
argument_list|,
argument|SourceLocation RParenLoc
argument_list|,
argument|unsigned Length
argument_list|)
operator|:
name|Expr
argument_list|(
name|SizeOfPackExprClass
argument_list|,
name|SizeType
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
comment|/*TypeDependent=*/
name|false
argument_list|,
comment|/*ValueDependent=*/
name|false
argument_list|,
comment|/*ContainsUnexpandedParameterPack=*/
name|false
argument_list|)
block|,
name|OperatorLoc
argument_list|(
name|OperatorLoc
argument_list|)
block|,
name|PackLoc
argument_list|(
name|PackLoc
argument_list|)
block|,
name|RParenLoc
argument_list|(
name|RParenLoc
argument_list|)
block|,
name|Length
argument_list|(
name|Length
argument_list|)
block|,
name|Pack
argument_list|(
argument|Pack
argument_list|)
block|{ }
comment|/// \brief Create an empty expression.
name|SizeOfPackExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|SizeOfPackExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// \brief Determine the location of the 'sizeof' keyword.
name|SourceLocation
name|getOperatorLoc
argument_list|()
specifier|const
block|{
return|return
name|OperatorLoc
return|;
block|}
comment|/// \brief Determine the location of the parameter pack.
name|SourceLocation
name|getPackLoc
argument_list|()
specifier|const
block|{
return|return
name|PackLoc
return|;
block|}
comment|/// \brief Determine the location of the right parenthesis.
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
comment|/// \brief Retrieve the parameter pack.
name|NamedDecl
operator|*
name|getPack
argument_list|()
specifier|const
block|{
return|return
name|Pack
return|;
block|}
comment|/// \brief Retrieve the length of the parameter pack.
comment|///
comment|/// This routine may only be invoked when the expression is not
comment|/// value-dependent.
name|unsigned
name|getPackLength
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isValueDependent
argument_list|()
operator|&&
literal|"Cannot get the length of a value-dependent pack size expression"
argument_list|)
block|;
return|return
name|Length
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|OperatorLoc
argument_list|,
name|RParenLoc
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
name|SizeOfPackExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SizeOfPackExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a reference to a non-type template parameter pack that
comment|/// has been substituted with a non-template argument pack.
comment|///
comment|/// When a pack expansion in the source code contains multiple parameter packs
comment|/// and those parameter packs correspond to different levels of template
comment|/// parameter lists, this node node is used to represent a non-type template
comment|/// parameter pack from an outer level, which has already had its argument pack
comment|/// substituted but that still lives within a pack expansion that itself
comment|/// could not be instantiated. When actually performing a substitution into
comment|/// that pack expansion (e.g., when all template parameters have corresponding
comment|/// arguments), this type will be replaced with the appropriate underlying
comment|/// expression at the current pack substitution index.
name|class
name|SubstNonTypeTemplateParmPackExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The non-type template parameter pack itself.
name|NonTypeTemplateParmDecl
operator|*
name|Param
block|;
comment|/// \brief A pointer to the set of template arguments that this
comment|/// parameter pack is instantiated with.
specifier|const
name|TemplateArgument
operator|*
name|Arguments
block|;
comment|/// \brief The number of template arguments in \c Arguments.
name|unsigned
name|NumArguments
block|;
comment|/// \brief The location of the non-type template parameter pack reference.
name|SourceLocation
name|NameLoc
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|;
name|public
operator|:
name|SubstNonTypeTemplateParmPackExpr
argument_list|(
argument|QualType T
argument_list|,
argument|NonTypeTemplateParmDecl *Param
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|const TemplateArgument&ArgPack
argument_list|)
block|;
name|SubstNonTypeTemplateParmPackExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|SubstNonTypeTemplateParmPackExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// \brief Retrieve the non-type template parameter pack being substituted.
name|NonTypeTemplateParmDecl
operator|*
name|getParameterPack
argument_list|()
specifier|const
block|{
return|return
name|Param
return|;
block|}
comment|/// \brief Retrieve the location of the parameter pack name.
name|SourceLocation
name|getParameterPackLocation
argument_list|()
specifier|const
block|{
return|return
name|NameLoc
return|;
block|}
comment|/// \brief Retrieve the template argument pack containing the substituted
comment|/// template arguments.
name|TemplateArgument
name|getArgumentPack
argument_list|()
specifier|const
block|;
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|NameLoc
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
name|SubstNonTypeTemplateParmPackExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SubstNonTypeTemplateParmPackExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
expr|}
block|;    }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

