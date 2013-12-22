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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::Expr interface and subclasses for C++ expressions.
end_comment

begin_comment
comment|///
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
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateBase.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/UnresolvedSet.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ExpressionTraits.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Lambda.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TypeTraits.h"
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
name|MSPropertyDecl
decl_stmt|;
name|class
name|TemplateArgumentListInfo
decl_stmt|;
name|class
name|UuidAttr
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
name|SourceRange
name|Range
block|;
comment|// Record the FP_CONTRACT state that applies to this operator call. Only
comment|// meaningful for floating point types. For other types this value can be
comment|// set to false.
name|unsigned
name|FPContractable
operator|:
literal|1
block|;
name|SourceRange
name|getSourceRangeImpl
argument_list|()
specifier|const
name|LLVM_READONLY
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
argument|ArrayRef<Expr*> args
argument_list|,
argument|QualType t
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation operatorloc
argument_list|,
argument|bool fpContractable
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
name|t
argument_list|,
name|VK
argument_list|,
name|operatorloc
argument_list|)
block|,
name|Operator
argument_list|(
name|Op
argument_list|)
block|,
name|FPContractable
argument_list|(
argument|fpContractable
argument_list|)
block|{
name|Range
operator|=
name|getSourceRangeImpl
argument_list|()
block|;   }
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
comment|/// \brief Returns the kind of overloaded operator that this
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
comment|/// \brief Returns the location of the operator symbol in the expression.
comment|///
comment|/// When \c getOperator()==OO_Call, this is the location of the right
comment|/// parentheses; when \c getOperator()==OO_Subscript, this is the location
comment|/// of the right bracket.
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getBegin
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
name|Range
operator|.
name|getEnd
argument_list|()
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
comment|// Set the FP contractability status of this operator. Only meaningful for
comment|// operations on floating point types.
name|void
name|setFPContractable
argument_list|(
argument|bool FPC
argument_list|)
block|{
name|FPContractable
operator|=
name|FPC
block|; }
comment|// Get the FP contractability status of this operator. Only meaningful for
comment|// operations on floating point types.
name|bool
name|isFPContractable
argument_list|()
specifier|const
block|{
return|return
name|FPContractable
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
decl_stmt|;
comment|/// Represents a call to a member function that
comment|/// may be written either with member call syntax (e.g., "obj.func()"
comment|/// or "objptr->func()") or with normal function-call syntax
comment|/// ("func()") within a member function that ends up calling a member
comment|/// function. The callee in either case is a MemberExpr that contains
comment|/// both the object argument and the member function, while the
comment|/// arguments are the arguments within the parentheses (not including
comment|/// the object argument).
name|class
name|CXXMemberCallExpr
range|:
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
argument|ArrayRef<Expr*> args
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
comment|/// \brief Retrieves the implicit object argument for the member call.
comment|///
comment|/// For example, in "x.f(5)", this returns the sub-expression "x".
name|Expr
operator|*
name|getImplicitObjectArgument
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieves the declaration of the called method.
name|CXXMethodDecl
operator|*
name|getMethodDecl
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieves the CXXRecordDecl for the underlying type of
comment|/// the implicit object argument.
comment|///
comment|/// Note that this is may not be the same declaration as that of the class
comment|/// context of the CXXMethodDecl which this function is calling.
comment|/// FIXME: Returns 0 for member pointer call exprs.
name|CXXRecordDecl
operator|*
name|getRecordDecl
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
name|CXXMemberCallExprClass
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a call to a CUDA kernel function.
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
argument|ArrayRef<Expr*> args
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
expr|}
block|;
comment|/// \brief Abstract class common to all of the C++ "named"/"keyword" casts.
comment|///
comment|/// This abstract class is inherited by all of the classes
comment|/// representing "named" casts: CXXStaticCastExpr for \c static_cast,
comment|/// CXXDynamicCastExpr for \c dynamic_cast, CXXReinterpretCastExpr for
comment|/// reinterpret_cast, and CXXConstCastExpr for \c const_cast.
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
name|SourceRange
name|AngleBrackets
block|;
comment|// range for '<' '>'
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
argument_list|,
argument|SourceRange AngleBrackets
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
name|RParenLoc
argument_list|)
block|,
name|AngleBrackets
argument_list|(
argument|AngleBrackets
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
comment|/// \c static_cast.
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RParenLoc
return|;
block|}
name|SourceRange
name|getAngleBrackets
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|AngleBrackets
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
expr|}
block|;
comment|/// \brief A C++ \c static_cast expression (C++ [expr.static.cast]).
comment|///
comment|/// This expression node represents a C++ static cast, e.g.,
comment|/// \c static_cast<int>(1.0).
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
argument_list|,
argument|SourceRange AngleBrackets
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
argument_list|,
argument|AngleBrackets
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
argument|const ASTContext&Context
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
argument_list|,
argument|SourceRange AngleBrackets
argument_list|)
block|;
specifier|static
name|CXXStaticCastExpr
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&Context
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
expr|}
block|;
comment|/// \brief A C++ @c dynamic_cast expression (C++ [expr.dynamic.cast]).
comment|///
comment|/// This expression node represents a dynamic cast, e.g.,
comment|/// \c dynamic_cast<Derived*>(BasePtr). Such a cast may perform a run-time
comment|/// check to determine how to perform the type conversion.
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
argument_list|,
argument|SourceRange AngleBrackets
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
argument_list|,
argument|AngleBrackets
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
argument|const ASTContext&Context
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
argument_list|,
argument|SourceRange AngleBrackets
argument_list|)
block|;
specifier|static
name|CXXDynamicCastExpr
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&Context
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
expr|}
block|;
comment|/// \brief A C++ @c reinterpret_cast expression (C++ [expr.reinterpret.cast]).
comment|///
comment|/// This expression node represents a reinterpret cast, e.g.,
comment|/// @c reinterpret_cast<int>(VoidPtr).
comment|///
comment|/// A reinterpret_cast provides a differently-typed view of a value but
comment|/// (in Clang, as in most C++ implementations) performs no actual work at
comment|/// run time.
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
argument_list|,
argument|SourceRange AngleBrackets
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
argument_list|,
argument|AngleBrackets
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
argument|const ASTContext&Context
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
argument_list|,
argument|SourceRange AngleBrackets
argument_list|)
block|;
specifier|static
name|CXXReinterpretCastExpr
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&Context
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
expr|}
block|;
comment|/// \brief A C++ \c const_cast expression (C++ [expr.const.cast]).
comment|///
comment|/// This expression node represents a const cast, e.g.,
comment|/// \c const_cast<char*>(PtrToConstChar).
comment|///
comment|/// A const_cast can remove type qualifiers but does not change the underlying
comment|/// value.
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
argument_list|,
argument|SourceRange AngleBrackets
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
argument_list|,
argument|AngleBrackets
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
argument|const ASTContext&Context
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
argument_list|,
argument|SourceRange AngleBrackets
argument_list|)
block|;
specifier|static
name|CXXConstCastExpr
operator|*
name|CreateEmpty
argument_list|(
specifier|const
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
expr|}
block|;
comment|/// \brief A call to a literal operator (C++11 [over.literal])
comment|/// written as a user-defined literal (C++11 [lit.ext]).
comment|///
comment|/// Represents a user-defined literal, e.g. "foo"_bar or 1.23_xyz. While this
comment|/// is semantically equivalent to a normal call, this AST node provides better
comment|/// information about the syntactic representation of the literal.
comment|///
comment|/// Since literal operators are never found by ADL and can only be declared at
comment|/// namespace scope, a user-defined literal is never dependent.
name|class
name|UserDefinedLiteral
operator|:
name|public
name|CallExpr
block|{
comment|/// \brief The location of a ud-suffix within the literal.
name|SourceLocation
name|UDSuffixLoc
block|;
name|public
operator|:
name|UserDefinedLiteral
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|Expr *Fn
argument_list|,
argument|ArrayRef<Expr*> Args
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation LitEndLoc
argument_list|,
argument|SourceLocation SuffixLoc
argument_list|)
operator|:
name|CallExpr
argument_list|(
name|C
argument_list|,
name|UserDefinedLiteralClass
argument_list|,
name|Fn
argument_list|,
literal|0
argument_list|,
name|Args
argument_list|,
name|T
argument_list|,
name|VK
argument_list|,
name|LitEndLoc
argument_list|)
block|,
name|UDSuffixLoc
argument_list|(
argument|SuffixLoc
argument_list|)
block|{}
name|explicit
name|UserDefinedLiteral
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|EmptyShell Empty
argument_list|)
operator|:
name|CallExpr
argument_list|(
argument|C
argument_list|,
argument|UserDefinedLiteralClass
argument_list|,
argument|Empty
argument_list|)
block|{}
comment|/// The kind of literal operator which is invoked.
expr|enum
name|LiteralOperatorKind
block|{
name|LOK_Raw
block|,
comment|///< Raw form: operator "" X (const char *)
name|LOK_Template
block|,
comment|///< Raw form: operator "" X<cs...> ()
name|LOK_Integer
block|,
comment|///< operator "" X (unsigned long long)
name|LOK_Floating
block|,
comment|///< operator "" X (long double)
name|LOK_String
block|,
comment|///< operator "" X (const CharT *, size_t)
name|LOK_Character
comment|///< operator "" X (CharT)
block|}
block|;
comment|/// \brief Returns the kind of literal operator invocation
comment|/// which this expression represents.
name|LiteralOperatorKind
name|getLiteralOperatorKind
argument_list|()
specifier|const
block|;
comment|/// \brief If this is not a raw user-defined literal, get the
comment|/// underlying cooked literal (representing the literal with the suffix
comment|/// removed).
name|Expr
operator|*
name|getCookedLiteral
argument_list|()
block|;
specifier|const
name|Expr
operator|*
name|getCookedLiteral
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|UserDefinedLiteral
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getCookedLiteral
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getLiteralOperatorKind
argument_list|()
operator|==
name|LOK_Template
condition|)
return|return
name|getRParenLoc
argument_list|()
return|;
return|return
name|getArg
argument_list|(
literal|0
argument_list|)
operator|->
name|getLocStart
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
block|{
return|return
name|getRParenLoc
argument_list|()
return|;
block|}
comment|/// \brief Returns the location of a ud-suffix in the expression.
comment|///
comment|/// For a string literal, there may be multiple identical suffixes. This
comment|/// returns the first.
name|SourceLocation
name|getUDSuffixLoc
argument_list|()
specifier|const
block|{
return|return
name|UDSuffixLoc
return|;
block|}
comment|/// \brief Returns the ud-suffix specified for this literal.
specifier|const
name|IdentifierInfo
operator|*
name|getUDSuffix
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *S
argument_list|)
block|{
return|return
name|S
operator|->
name|getStmtClass
argument_list|()
operator|==
name|UserDefinedLiteralClass
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
comment|/// \brief A boolean literal, per ([C++ lex.bool] Boolean literals).
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
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
comment|/// \brief The null pointer literal (C++11 [lex.nullptr])
comment|///
comment|/// Introduced in C++11, the only literal of type \c nullptr_t is \c nullptr.
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
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
comment|/// \brief Implicit construction of a std::initializer_list<T> object from an
comment|/// array temporary within list-initialization (C++11 [dcl.init.list]p5).
name|class
name|CXXStdInitializerListExpr
operator|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|SubExpr
block|;
name|CXXStdInitializerListExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXStdInitializerListExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|SubExpr
argument_list|(
literal|0
argument_list|)
block|{}
name|public
operator|:
name|CXXStdInitializerListExpr
argument_list|(
argument|QualType Ty
argument_list|,
argument|Expr *SubExpr
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXStdInitializerListExprClass
argument_list|,
name|Ty
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|Ty
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|SubExpr
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|SubExpr
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|SubExpr
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|SubExpr
argument_list|(
argument|SubExpr
argument_list|)
block|{}
name|Expr
operator|*
name|getSubExpr
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|Expr
operator|*
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
name|static_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
name|SubExpr
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
name|SubExpr
operator|->
name|getLocStart
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
name|SubExpr
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SubExpr
operator|->
name|getSourceRange
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *S
argument_list|)
block|{
return|return
name|S
operator|->
name|getStmtClass
argument_list|()
operator|==
name|CXXStdInitializerListExprClass
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
name|SubExpr
argument_list|,
operator|&
name|SubExpr
operator|+
literal|1
argument_list|)
return|;
block|}
name|friend
name|class
name|ASTReader
block|;
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// A C++ \c typeid expression (C++ [expr.typeid]), which gets
comment|/// the \c type_info that corresponds to the supplied type, or the (possibly
comment|/// dynamic) type of the supplied expression.
comment|///
comment|/// This represents code like \c typeid(int) or \c typeid(*objPtr)
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
name|isInstantiationDependentType
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
name|isInstantiationDependent
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
comment|/// Determine whether this typeid has a type operand which is potentially
comment|/// evaluated, per C++11 [expr.typeid]p3.
name|bool
name|isPotentiallyEvaluated
argument_list|()
specifier|const
block|;
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
argument_list|(
argument|ASTContext&Context
argument_list|)
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getBegin
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
name|Range
operator|.
name|getEnd
argument_list|()
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
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
comment|/// \brief A member reference to an MSPropertyDecl.
comment|///
comment|/// This expression always has pseudo-object type, and therefore it is
comment|/// typically not encountered in a fully-typechecked expression except
comment|/// within the syntactic form of a PseudoObjectExpr.
name|class
name|MSPropertyRefExpr
operator|:
name|public
name|Expr
block|{
name|Expr
operator|*
name|BaseExpr
block|;
name|MSPropertyDecl
operator|*
name|TheDecl
block|;
name|SourceLocation
name|MemberLoc
block|;
name|bool
name|IsArrow
block|;
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
name|public
operator|:
name|MSPropertyRefExpr
argument_list|(
argument|Expr *baseExpr
argument_list|,
argument|MSPropertyDecl *decl
argument_list|,
argument|bool isArrow
argument_list|,
argument|QualType ty
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|NestedNameSpecifierLoc qualifierLoc
argument_list|,
argument|SourceLocation nameLoc
argument_list|)
operator|:
name|Expr
argument_list|(
name|MSPropertyRefExprClass
argument_list|,
name|ty
argument_list|,
name|VK
argument_list|,
name|OK_Ordinary
argument_list|,
comment|/*type-dependent*/
name|false
argument_list|,
name|baseExpr
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|baseExpr
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|baseExpr
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|BaseExpr
argument_list|(
name|baseExpr
argument_list|)
block|,
name|TheDecl
argument_list|(
name|decl
argument_list|)
block|,
name|MemberLoc
argument_list|(
name|nameLoc
argument_list|)
block|,
name|IsArrow
argument_list|(
name|isArrow
argument_list|)
block|,
name|QualifierLoc
argument_list|(
argument|qualifierLoc
argument_list|)
block|{}
name|MSPropertyRefExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|MSPropertyRefExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|getLocStart
argument_list|()
argument_list|,
name|getLocEnd
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isImplicitAccess
argument_list|()
specifier|const
block|{
return|return
name|getBaseExpr
argument_list|()
operator|&&
name|getBaseExpr
argument_list|()
operator|->
name|isImplicitCXXThis
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isImplicitAccess
argument_list|()
condition|)
return|return
name|BaseExpr
operator|->
name|getLocStart
argument_list|()
return|;
elseif|else
if|if
condition|(
name|QualifierLoc
condition|)
return|return
name|QualifierLoc
operator|.
name|getBeginLoc
argument_list|()
return|;
else|else
return|return
name|MemberLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
block|{
return|return
name|getMemberLoc
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
operator|(
name|Stmt
operator|*
operator|*
operator|)
operator|&
name|BaseExpr
argument_list|,
operator|(
name|Stmt
operator|*
operator|*
operator|)
operator|&
name|BaseExpr
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
name|MSPropertyRefExprClass
return|;
block|}
name|Expr
operator|*
name|getBaseExpr
argument_list|()
specifier|const
block|{
return|return
name|BaseExpr
return|;
block|}
name|MSPropertyDecl
operator|*
name|getPropertyDecl
argument_list|()
specifier|const
block|{
return|return
name|TheDecl
return|;
block|}
name|bool
name|isArrow
argument_list|()
specifier|const
block|{
return|return
name|IsArrow
return|;
block|}
name|SourceLocation
name|getMemberLoc
argument_list|()
specifier|const
block|{
return|return
name|MemberLoc
return|;
block|}
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// A Microsoft C++ @c __uuidof expression, which gets
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
name|isInstantiationDependentType
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
name|isInstantiationDependent
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
argument_list|(
argument|ASTContext&Context
argument_list|)
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
name|StringRef
name|getUuidAsStringRef
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
block|;
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getBegin
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
name|Range
operator|.
name|getEnd
argument_list|()
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
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
comment|/// Grabs __declspec(uuid()) off a type, or returns 0 if we cannot resolve to
comment|/// a single GUID.
specifier|static
name|UuidAttr
operator|*
name|GetUuidAttrOfType
argument_list|(
argument|QualType QT
argument_list|,
argument|bool *HasMultipleGUIDsPtr =
literal|0
argument_list|)
block|;
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
comment|/// \brief Represents the \c this expression in C++.
comment|///
comment|/// This is a pointer to the object on which the current member function is
comment|/// executing (C++ [expr.prim]p3). Example:
comment|///
comment|/// \code
comment|/// class Foo {
comment|/// public:
comment|///   void bar();
comment|///   void test() { this->bar(); }
comment|/// };
comment|/// \endcode
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
name|Type
operator|->
name|isInstantiationDependentType
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
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
comment|/// \brief A C++ throw-expression (C++ [except.throw]).
comment|///
comment|/// This handles 'throw' (for re-throwing the current exception) and
comment|/// 'throw' assignment-expression.  When assignment-expression isn't
comment|/// present, Op will be null.
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
comment|/// \brief Whether the thrown variable (if any) is in scope.
name|unsigned
name|IsThrownVariableInScope
operator|:
literal|1
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
comment|// \p Ty is the void type which is used as the result type of the
comment|// expression.  The \p l is the location of the throw keyword.  \p expr
comment|// can by null, if the optional expression to throw isn't present.
name|CXXThrowExpr
argument_list|(
argument|Expr *expr
argument_list|,
argument|QualType Ty
argument_list|,
argument|SourceLocation l
argument_list|,
argument|bool IsThrownVariableInScope
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
name|isInstantiationDependent
argument_list|()
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
name|l
argument_list|)
block|,
name|IsThrownVariableInScope
argument_list|(
argument|IsThrownVariableInScope
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
name|SourceLocation
name|getThrowLoc
argument_list|()
specifier|const
block|{
return|return
name|ThrowLoc
return|;
block|}
comment|/// \brief Determines whether the variable thrown by this expression (if any!)
comment|/// is within the innermost try block.
comment|///
comment|/// This information is required to determine whether the NRVO can apply to
comment|/// this variable.
name|bool
name|isThrownVariableInScope
argument_list|()
specifier|const
block|{
return|return
name|IsThrownVariableInScope
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|ThrowLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|getSubExpr
argument_list|()
operator|==
literal|0
condition|)
return|return
name|ThrowLoc
return|;
return|return
name|getSubExpr
argument_list|()
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
name|CXXThrowExprClass
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
comment|/// \brief A default argument (C++ [dcl.fct.default]).
comment|///
comment|/// This wraps up a function call argument that was created from the
comment|/// corresponding parameter's default argument, when the call did not
comment|/// explicitly supply arguments for all of the parameters.
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
comment|// \p Param is the parameter whose default argument is used by this
comment|// expression.
specifier|static
name|CXXDefaultArgExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
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
comment|// \p Param is the parameter whose default argument is used by this
comment|// expression, and \p SubExpr is the expression that will actually be used.
specifier|static
name|CXXDefaultArgExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
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
comment|/// Default argument expressions have no representation in the
comment|/// source, so they have an empty source range.
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceLocation
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
name|SourceLocation
argument_list|()
return|;
block|}
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
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
comment|/// \brief A use of a default initializer in a constructor or in aggregate
comment|/// initialization.
comment|///
comment|/// This wraps a use of a C++ default initializer (technically,
comment|/// a brace-or-equal-initializer for a non-static data member) when it
comment|/// is implicitly used in a mem-initializer-list in a constructor
comment|/// (C++11 [class.base.init]p8) or in aggregate initialization
comment|/// (C++1y [dcl.init.aggr]p7).
name|class
name|CXXDefaultInitExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The field whose default is being used.
name|FieldDecl
operator|*
name|Field
block|;
comment|/// \brief The location where the default initializer expression was used.
name|SourceLocation
name|Loc
block|;
name|CXXDefaultInitExpr
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|FieldDecl *Field
argument_list|,
argument|QualType T
argument_list|)
block|;
name|CXXDefaultInitExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CXXDefaultInitExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|public
operator|:
comment|/// \p Field is the non-static data member whose default initializer is used
comment|/// by this expression.
specifier|static
name|CXXDefaultInitExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|FieldDecl *Field
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|C
argument_list|)
name|CXXDefaultInitExpr
argument_list|(
name|C
argument_list|,
name|Loc
argument_list|,
name|Field
argument_list|,
name|Field
operator|->
name|getType
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Get the field whose initializer will be used.
name|FieldDecl
operator|*
name|getField
argument_list|()
block|{
return|return
name|Field
return|;
block|}
specifier|const
name|FieldDecl
operator|*
name|getField
argument_list|()
specifier|const
block|{
return|return
name|Field
return|;
block|}
comment|/// \brief Get the initialization expression that will be used.
specifier|const
name|Expr
operator|*
name|getExpr
argument_list|()
specifier|const
block|{
return|return
name|Field
operator|->
name|getInClassInitializer
argument_list|()
return|;
block|}
name|Expr
operator|*
name|getExpr
argument_list|()
block|{
return|return
name|Field
operator|->
name|getInClassInitializer
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
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
name|CXXDefaultInitExprClass
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
name|ASTReader
block|;
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// \brief Represents a C++ temporary.
name|class
name|CXXTemporary
block|{
comment|/// \brief The destructor that needs to be called.
specifier|const
name|CXXDestructorDecl
operator|*
name|Destructor
block|;
name|explicit
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
specifier|const
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
name|void
name|setDestructor
argument_list|(
argument|const CXXDestructorDecl *Dtor
argument_list|)
block|{
name|Destructor
operator|=
name|Dtor
block|;   }
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
name|isInstantiationDependent
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
specifier|const
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SubExpr
operator|->
name|getLocStart
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
name|SubExpr
operator|->
name|getLocEnd
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
comment|/// \brief Represents a call to a C++ constructor.
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
name|ParenOrBraceRange
block|;
name|unsigned
name|NumArgs
operator|:
literal|16
block|;
name|bool
name|Elidable
operator|:
literal|1
block|;
name|bool
name|HadMultipleCandidates
operator|:
literal|1
block|;
name|bool
name|ListInitialization
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
name|protected
operator|:
name|CXXConstructExpr
argument_list|(
argument|const ASTContext&C
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
argument|ArrayRef<Expr *> Args
argument_list|,
argument|bool HadMultipleCandidates
argument_list|,
argument|bool ListInitialization
argument_list|,
argument|bool ZeroInitialization
argument_list|,
argument|ConstructionKind ConstructKind
argument_list|,
argument|SourceRange ParenOrBraceRange
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
name|NumArgs
argument_list|(
literal|0
argument_list|)
block|,
name|Elidable
argument_list|(
name|false
argument_list|)
block|,
name|HadMultipleCandidates
argument_list|(
name|false
argument_list|)
block|,
name|ListInitialization
argument_list|(
name|false
argument_list|)
block|,
name|ZeroInitialization
argument_list|(
name|false
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
name|NumArgs
argument_list|(
literal|0
argument_list|)
block|,
name|Elidable
argument_list|(
name|false
argument_list|)
block|,
name|HadMultipleCandidates
argument_list|(
name|false
argument_list|)
block|,
name|ListInitialization
argument_list|(
name|false
argument_list|)
block|,
name|ZeroInitialization
argument_list|(
name|false
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
block|{ }
specifier|static
name|CXXConstructExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|QualType T
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|CXXConstructorDecl *D
argument_list|,
argument|bool Elidable
argument_list|,
argument|ArrayRef<Expr *> Args
argument_list|,
argument|bool HadMultipleCandidates
argument_list|,
argument|bool ListInitialization
argument_list|,
argument|bool ZeroInitialization
argument_list|,
argument|ConstructionKind ConstructKind
argument_list|,
argument|SourceRange ParenOrBraceRange
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
comment|/// \brief Whether the referred constructor was resolved from
comment|/// an overloaded set having size greater than 1.
name|bool
name|hadMultipleCandidates
argument_list|()
specifier|const
block|{
return|return
name|HadMultipleCandidates
return|;
block|}
name|void
name|setHadMultipleCandidates
argument_list|(
argument|bool V
argument_list|)
block|{
name|HadMultipleCandidates
operator|=
name|V
block|; }
comment|/// \brief Whether this constructor call was written as list-initialization.
name|bool
name|isListInitialization
argument_list|()
specifier|const
block|{
return|return
name|ListInitialization
return|;
block|}
name|void
name|setListInitialization
argument_list|(
argument|bool V
argument_list|)
block|{
name|ListInitialization
operator|=
name|V
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
comment|/// \brief Determine whether this constructor is actually constructing
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
comment|/// \brief Return the specified argument.
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
comment|/// \brief Set the specified argument.
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|;
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|;
name|SourceRange
name|getParenOrBraceRange
argument_list|()
specifier|const
block|{
return|return
name|ParenOrBraceRange
return|;
block|}
name|void
name|setParenOrBraceRange
argument_list|(
argument|SourceRange Range
argument_list|)
block|{
name|ParenOrBraceRange
operator|=
name|Range
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
comment|/// \brief Represents an explicit C++ type conversion that uses "functional"
comment|/// notation (C++ [expr.type.conv]).
comment|///
comment|/// Example:
comment|/// \code
comment|///   x = int(0.5);
comment|/// \endcode
name|class
name|CXXFunctionalCastExpr
operator|:
name|public
name|ExplicitCastExpr
block|{
name|SourceLocation
name|LParenLoc
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
argument|CastKind kind
argument_list|,
argument|Expr *castExpr
argument_list|,
argument|unsigned pathSize
argument_list|,
argument|SourceLocation lParenLoc
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
name|LParenLoc
argument_list|(
name|lParenLoc
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
argument|const ASTContext&Context
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|TypeSourceInfo *Written
argument_list|,
argument|CastKind Kind
argument_list|,
argument|Expr *Op
argument_list|,
argument|const CXXCastPath *Path
argument_list|,
argument|SourceLocation LPLoc
argument_list|,
argument|SourceLocation RPLoc
argument_list|)
block|;
specifier|static
name|CXXFunctionalCastExpr
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|unsigned PathSize
argument_list|)
block|;
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|;
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|CXXFunctionalCastExprClass
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
comment|/// \code
comment|/// struct X { X(int, float); }
comment|///
comment|/// X create_X() {
comment|///   return X(1, 3.14f); // creates a CXXTemporaryObjectExpr
comment|/// };
comment|/// \endcode
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
argument|const ASTContext&C
argument_list|,
argument|CXXConstructorDecl *Cons
argument_list|,
argument|TypeSourceInfo *Type
argument_list|,
argument|ArrayRef<Expr *> Args
argument_list|,
argument|SourceRange ParenOrBraceRange
argument_list|,
argument|bool HadMultipleCandidates
argument_list|,
argument|bool ListInitialization
argument_list|,
argument|bool ZeroInitialization
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|;
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// \brief A C++ lambda expression, which produces a function object
comment|/// (of unspecified type) that can be invoked later.
comment|///
comment|/// Example:
comment|/// \code
comment|/// void low_pass_filter(std::vector<double>&values, double cutoff) {
comment|///   values.erase(std::remove_if(values.begin(), values.end(),
comment|///                               [=](double value) { return value> cutoff; });
comment|/// }
comment|/// \endcode
comment|///
comment|/// C++11 lambda expressions can capture local variables, either by copying
comment|/// the values of those local variables at the time the function
comment|/// object is constructed (not when it is called!) or by holding a
comment|/// reference to the local variable. These captures can occur either
comment|/// implicitly or can be written explicitly between the square
comment|/// brackets ([...]) that start the lambda expression.
comment|///
comment|/// C++1y introduces a new form of "capture" called an init-capture that
comment|/// includes an initializing expression (rather than capturing a variable),
comment|/// and which can never occur implicitly.
name|class
name|LambdaExpr
operator|:
name|public
name|Expr
block|{   enum
block|{
comment|/// \brief Flag used by the Capture class to indicate that the given
comment|/// capture was implicit.
name|Capture_Implicit
operator|=
literal|0x01
block|,
comment|/// \brief Flag used by the Capture class to indicate that the
comment|/// given capture was by-copy.
comment|///
comment|/// This includes the case of a non-reference init-capture.
name|Capture_ByCopy
operator|=
literal|0x02
block|}
block|;
comment|/// \brief The source range that covers the lambda introducer ([...]).
name|SourceRange
name|IntroducerRange
block|;
comment|/// \brief The source location of this lambda's capture-default ('=' or '&').
name|SourceLocation
name|CaptureDefaultLoc
block|;
comment|/// \brief The number of captures.
name|unsigned
name|NumCaptures
operator|:
literal|16
block|;
comment|/// \brief The default capture kind, which is a value of type
comment|/// LambdaCaptureDefault.
name|unsigned
name|CaptureDefault
operator|:
literal|2
block|;
comment|/// \brief Whether this lambda had an explicit parameter list vs. an
comment|/// implicit (and empty) parameter list.
name|unsigned
name|ExplicitParams
operator|:
literal|1
block|;
comment|/// \brief Whether this lambda had the result type explicitly specified.
name|unsigned
name|ExplicitResultType
operator|:
literal|1
block|;
comment|/// \brief Whether there are any array index variables stored at the end of
comment|/// this lambda expression.
name|unsigned
name|HasArrayIndexVars
operator|:
literal|1
block|;
comment|/// \brief The location of the closing brace ('}') that completes
comment|/// the lambda.
comment|///
comment|/// The location of the brace is also available by looking up the
comment|/// function call operator in the lambda class. However, it is
comment|/// stored here to improve the performance of getSourceRange(), and
comment|/// to avoid having to deserialize the function call operator from a
comment|/// module file just to determine the source range.
name|SourceLocation
name|ClosingBrace
block|;
comment|// Note: The capture initializers are stored directly after the lambda
comment|// expression, along with the index variables used to initialize by-copy
comment|// array captures.
name|public
operator|:
comment|/// \brief Describes the capture of a variable or of \c this, or of a
comment|/// C++1y init-capture.
name|class
name|Capture
block|{
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Decl
operator|*
block|,
literal|2
operator|>
name|DeclAndBits
block|;
name|SourceLocation
name|Loc
block|;
name|SourceLocation
name|EllipsisLoc
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
comment|/// \brief Create a new capture of a variable or of \c this.
comment|///
comment|/// \param Loc The source location associated with this capture.
comment|///
comment|/// \param Kind The kind of capture (this, byref, bycopy), which must
comment|/// not be init-capture.
comment|///
comment|/// \param Implicit Whether the capture was implicit or explicit.
comment|///
comment|/// \param Var The local variable being captured, or null if capturing
comment|/// \c this.
comment|///
comment|/// \param EllipsisLoc The location of the ellipsis (...) for a
comment|/// capture that is a pack expansion, or an invalid source
comment|/// location to indicate that this is not a pack expansion.
name|Capture
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|bool Implicit
argument_list|,
argument|LambdaCaptureKind Kind
argument_list|,
argument|VarDecl *Var =
literal|0
argument_list|,
argument|SourceLocation EllipsisLoc = SourceLocation()
argument_list|)
block|;
comment|/// \brief Determine the kind of capture.
name|LambdaCaptureKind
name|getCaptureKind
argument_list|()
specifier|const
block|;
comment|/// \brief Determine whether this capture handles the C++ \c this
comment|/// pointer.
name|bool
name|capturesThis
argument_list|()
specifier|const
block|{
return|return
name|DeclAndBits
operator|.
name|getPointer
argument_list|()
operator|==
literal|0
return|;
block|}
comment|/// \brief Determine whether this capture handles a variable.
name|bool
name|capturesVariable
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|VarDecl
operator|>
operator|(
name|DeclAndBits
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Determine whether this is an init-capture.
name|bool
name|isInitCapture
argument_list|()
specifier|const
block|{
return|return
name|capturesVariable
argument_list|()
operator|&&
name|getCapturedVar
argument_list|()
operator|->
name|isInitCapture
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the declaration of the local variable being
comment|/// captured.
comment|///
comment|/// This operation is only valid if this capture is a variable capture
comment|/// (other than a capture of \c this).
name|VarDecl
operator|*
name|getCapturedVar
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|capturesVariable
argument_list|()
operator|&&
literal|"No variable available for 'this' capture"
argument_list|)
block|;
return|return
name|cast
operator|<
name|VarDecl
operator|>
operator|(
name|DeclAndBits
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Determine whether this was an implicit capture (not
comment|/// written between the square brackets introducing the lambda).
name|bool
name|isImplicit
argument_list|()
specifier|const
block|{
return|return
name|DeclAndBits
operator|.
name|getInt
argument_list|()
operator|&
name|Capture_Implicit
return|;
block|}
comment|/// \brief Determine whether this was an explicit capture (written
comment|/// between the square brackets introducing the lambda).
name|bool
name|isExplicit
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isImplicit
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the source location of the capture.
comment|///
comment|/// For an explicit capture, this returns the location of the
comment|/// explicit capture in the source. For an implicit capture, this
comment|/// returns the location at which the variable or \c this was first
comment|/// used.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
comment|/// \brief Determine whether this capture is a pack expansion,
comment|/// which captures a function parameter pack.
name|bool
name|isPackExpansion
argument_list|()
specifier|const
block|{
return|return
name|EllipsisLoc
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the location of the ellipsis for a capture
comment|/// that is a pack expansion.
name|SourceLocation
name|getEllipsisLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isPackExpansion
argument_list|()
operator|&&
literal|"No ellipsis location for a non-expansion"
argument_list|)
block|;
return|return
name|EllipsisLoc
return|;
block|}
expr|}
block|;
name|private
operator|:
comment|/// \brief Construct a lambda expression.
name|LambdaExpr
argument_list|(
argument|QualType T
argument_list|,
argument|SourceRange IntroducerRange
argument_list|,
argument|LambdaCaptureDefault CaptureDefault
argument_list|,
argument|SourceLocation CaptureDefaultLoc
argument_list|,
argument|ArrayRef<Capture> Captures
argument_list|,
argument|bool ExplicitParams
argument_list|,
argument|bool ExplicitResultType
argument_list|,
argument|ArrayRef<Expr *> CaptureInits
argument_list|,
argument|ArrayRef<VarDecl *> ArrayIndexVars
argument_list|,
argument|ArrayRef<unsigned> ArrayIndexStarts
argument_list|,
argument|SourceLocation ClosingBrace
argument_list|,
argument|bool ContainsUnexpandedParameterPack
argument_list|)
block|;
comment|/// \brief Construct an empty lambda expression.
name|LambdaExpr
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|unsigned NumCaptures
argument_list|,
argument|bool HasArrayIndexVars
argument_list|)
operator|:
name|Expr
argument_list|(
name|LambdaExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|NumCaptures
argument_list|(
name|NumCaptures
argument_list|)
block|,
name|CaptureDefault
argument_list|(
name|LCD_None
argument_list|)
block|,
name|ExplicitParams
argument_list|(
name|false
argument_list|)
block|,
name|ExplicitResultType
argument_list|(
name|false
argument_list|)
block|,
name|HasArrayIndexVars
argument_list|(
argument|true
argument_list|)
block|{
name|getStoredStmts
argument_list|()
index|[
name|NumCaptures
index|]
operator|=
literal|0
block|;   }
name|Stmt
operator|*
operator|*
name|getStoredStmts
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|LambdaExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieve the mapping from captures to the first array index
comment|/// variable.
name|unsigned
operator|*
name|getArrayIndexStarts
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|unsigned
operator|*
operator|>
operator|(
name|getStoredStmts
argument_list|()
operator|+
name|NumCaptures
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieve the complete set of array-index variables.
name|VarDecl
operator|*
operator|*
name|getArrayIndexVars
argument_list|()
specifier|const
block|{
name|unsigned
name|ArrayIndexSize
operator|=
name|llvm
operator|::
name|RoundUpToAlignment
argument_list|(
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
operator|(
name|NumCaptures
operator|+
literal|1
operator|)
argument_list|,
name|llvm
operator|::
name|alignOf
operator|<
name|VarDecl
operator|*
operator|>
operator|(
operator|)
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|VarDecl
operator|*
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|getArrayIndexStarts
argument_list|()
operator|)
operator|+
name|ArrayIndexSize
operator|)
return|;
block|}
name|public
operator|:
comment|/// \brief Construct a new lambda expression.
specifier|static
name|LambdaExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|CXXRecordDecl *Class
argument_list|,
argument|SourceRange IntroducerRange
argument_list|,
argument|LambdaCaptureDefault CaptureDefault
argument_list|,
argument|SourceLocation CaptureDefaultLoc
argument_list|,
argument|ArrayRef<Capture> Captures
argument_list|,
argument|bool ExplicitParams
argument_list|,
argument|bool ExplicitResultType
argument_list|,
argument|ArrayRef<Expr *> CaptureInits
argument_list|,
argument|ArrayRef<VarDecl *> ArrayIndexVars
argument_list|,
argument|ArrayRef<unsigned> ArrayIndexStarts
argument_list|,
argument|SourceLocation ClosingBrace
argument_list|,
argument|bool ContainsUnexpandedParameterPack
argument_list|)
block|;
comment|/// \brief Construct a new lambda expression that will be deserialized from
comment|/// an external source.
specifier|static
name|LambdaExpr
operator|*
name|CreateDeserialized
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumCaptures
argument_list|,
argument|unsigned NumArrayIndexVars
argument_list|)
block|;
comment|/// \brief Determine the default capture kind for this lambda.
name|LambdaCaptureDefault
name|getCaptureDefault
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|LambdaCaptureDefault
operator|>
operator|(
name|CaptureDefault
operator|)
return|;
block|}
comment|/// \brief Retrieve the location of this lambda's capture-default, if any.
name|SourceLocation
name|getCaptureDefaultLoc
argument_list|()
specifier|const
block|{
return|return
name|CaptureDefaultLoc
return|;
block|}
comment|/// \brief An iterator that walks over the captures of the lambda,
comment|/// both implicit and explicit.
typedef|typedef
specifier|const
name|Capture
modifier|*
name|capture_iterator
typedef|;
comment|/// \brief Retrieve an iterator pointing to the first lambda capture.
name|capture_iterator
name|capture_begin
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve an iterator pointing past the end of the
comment|/// sequence of lambda captures.
name|capture_iterator
name|capture_end
argument_list|()
specifier|const
block|;
comment|/// \brief Determine the number of captures in this lambda.
name|unsigned
name|capture_size
argument_list|()
specifier|const
block|{
return|return
name|NumCaptures
return|;
block|}
comment|/// \brief Retrieve an iterator pointing to the first explicit
comment|/// lambda capture.
name|capture_iterator
name|explicit_capture_begin
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve an iterator pointing past the end of the sequence of
comment|/// explicit lambda captures.
name|capture_iterator
name|explicit_capture_end
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve an iterator pointing to the first implicit
comment|/// lambda capture.
name|capture_iterator
name|implicit_capture_begin
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve an iterator pointing past the end of the sequence of
comment|/// implicit lambda captures.
name|capture_iterator
name|implicit_capture_end
argument_list|()
specifier|const
block|;
comment|/// \brief Iterator that walks over the capture initialization
comment|/// arguments.
typedef|typedef
name|Expr
modifier|*
modifier|*
name|capture_init_iterator
typedef|;
comment|/// \brief Retrieve the first initialization argument for this
comment|/// lambda expression (which initializes the first capture field).
name|capture_init_iterator
name|capture_init_begin
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
name|getStoredStmts
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Retrieve the iterator pointing one past the last
comment|/// initialization argument for this lambda expression.
name|capture_init_iterator
name|capture_init_end
argument_list|()
specifier|const
block|{
return|return
name|capture_init_begin
argument_list|()
operator|+
name|NumCaptures
return|;
block|}
comment|/// \brief Retrieve the set of index variables used in the capture
comment|/// initializer of an array captured by copy.
comment|///
comment|/// \param Iter The iterator that points at the capture initializer for
comment|/// which we are extracting the corresponding index variables.
name|ArrayRef
operator|<
name|VarDecl
operator|*
operator|>
name|getCaptureInitIndexVars
argument_list|(
argument|capture_init_iterator Iter
argument_list|)
specifier|const
block|;
comment|/// \brief Retrieve the source range covering the lambda introducer,
comment|/// which contains the explicit capture list surrounded by square
comment|/// brackets ([...]).
name|SourceRange
name|getIntroducerRange
argument_list|()
specifier|const
block|{
return|return
name|IntroducerRange
return|;
block|}
comment|/// \brief Retrieve the class that corresponds to the lambda.
comment|///
comment|/// This is the "closure type" (C++1y [expr.prim.lambda]), and stores the
comment|/// captures in its fields and provides the various operations permitted
comment|/// on a lambda (copying, calling).
name|CXXRecordDecl
operator|*
name|getLambdaClass
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve the function call operator associated with this
comment|/// lambda expression.
name|CXXMethodDecl
operator|*
name|getCallOperator
argument_list|()
specifier|const
block|;
comment|/// \brief If this is a generic lambda expression, retrieve the template
comment|/// parameter list associated with it, or else return null.
name|TemplateParameterList
operator|*
name|getTemplateParameterList
argument_list|()
specifier|const
block|;
comment|/// \brief Whether this is a generic lambda.
name|bool
name|isGenericLambda
argument_list|()
specifier|const
block|{
return|return
name|getTemplateParameterList
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the body of the lambda.
name|CompoundStmt
operator|*
name|getBody
argument_list|()
specifier|const
block|;
comment|/// \brief Determine whether the lambda is mutable, meaning that any
comment|/// captures values can be modified.
name|bool
name|isMutable
argument_list|()
specifier|const
block|;
comment|/// \brief Determine whether this lambda has an explicit parameter
comment|/// list vs. an implicit (empty) parameter list.
name|bool
name|hasExplicitParameters
argument_list|()
specifier|const
block|{
return|return
name|ExplicitParams
return|;
block|}
comment|/// \brief Whether this lambda had its result type explicitly specified.
name|bool
name|hasExplicitResultType
argument_list|()
specifier|const
block|{
return|return
name|ExplicitResultType
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
name|LambdaExprClass
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|IntroducerRange
operator|.
name|getBegin
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
name|ClosingBrace
return|;
block|}
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|getStoredStmts
argument_list|()
argument_list|,
name|getStoredStmts
argument_list|()
operator|+
name|NumCaptures
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
comment|/// An expression "T()" which creates a value-initialized rvalue of type
comment|/// T, which is a non-class type.  See (C++98 [5.2.3p2]).
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
name|Type
operator|->
name|isInstantiationDependentType
argument_list|()
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|;
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RParenLoc
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
name|CXXScalarValueInitExprClass
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
comment|/// \brief Represents a new-expression for memory allocation and constructor
comment|/// calls, e.g: "new CXXNewExpr(foo)".
name|class
name|CXXNewExpr
operator|:
name|public
name|Expr
block|{
comment|/// Contains an optional array size expression, an optional initialization
comment|/// expression, and any number of optional placement arguments, in that order.
name|Stmt
operator|*
operator|*
name|SubExprs
block|;
comment|/// \brief Points to the allocation function used.
name|FunctionDecl
operator|*
name|OperatorNew
block|;
comment|/// \brief Points to the deallocation function used in case of error. May be
comment|/// null.
name|FunctionDecl
operator|*
name|OperatorDelete
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
comment|/// \brief Range of the entire new expression.
name|SourceRange
name|Range
block|;
comment|/// \brief Source-range of a paren-delimited initializer.
name|SourceRange
name|DirectInitRange
block|;
comment|/// Was the usage ::new, i.e. is the global new to be used?
name|bool
name|GlobalNew
operator|:
literal|1
block|;
comment|/// Do we allocate an array? If so, the first SubExpr is the size expression.
name|bool
name|Array
operator|:
literal|1
block|;
comment|/// If this is an array allocation, does the usual deallocation
comment|/// function for the allocated type want to know the allocated size?
name|bool
name|UsualArrayDeleteWantsSize
operator|:
literal|1
block|;
comment|/// The number of placement new arguments.
name|unsigned
name|NumPlacementArgs
operator|:
literal|13
block|;
comment|/// What kind of initializer do we have? Could be none, parens, or braces.
comment|/// In storage, we distinguish between "none, and no initializer expr", and
comment|/// "none, but an implicit initializer expr".
name|unsigned
name|StoredInitializationStyle
operator|:
literal|2
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
expr|enum
name|InitializationStyle
block|{
name|NoInit
block|,
comment|///< New-expression has no initializer as written.
name|CallInit
block|,
comment|///< New-expression has a C++98 paren-delimited initializer.
name|ListInit
comment|///< New-expression has a C++11 list-initializer.
block|}
block|;
name|CXXNewExpr
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|bool globalNew
argument_list|,
argument|FunctionDecl *operatorNew
argument_list|,
argument|FunctionDecl *operatorDelete
argument_list|,
argument|bool usualArrayDeleteWantsSize
argument_list|,
argument|ArrayRef<Expr*> placementArgs
argument_list|,
argument|SourceRange typeIdParens
argument_list|,
argument|Expr *arraySize
argument_list|,
argument|InitializationStyle initializationStyle
argument_list|,
argument|Expr *initializer
argument_list|,
argument|QualType ty
argument_list|,
argument|TypeSourceInfo *AllocatedTypeInfo
argument_list|,
argument|SourceRange Range
argument_list|,
argument|SourceRange directInitRange
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
argument|const ASTContext&C
argument_list|,
argument|bool isArray
argument_list|,
argument|unsigned numPlaceArgs
argument_list|,
argument|bool hasInitializer
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
comment|///
comment|/// C++11 [expr.new]p13:
comment|///   If the allocation function returns null, initialization shall
comment|///   not be done, the deallocation function shall not be called,
comment|///   and the value of the new-expression shall be null.
comment|///
comment|/// An allocation function is not allowed to return null unless it
comment|/// has a non-throwing exception-specification.  The '03 rule is
comment|/// identical except that the definition of a non-throwing
comment|/// exception specification is just "is it throw()?".
name|bool
name|shouldNullCheckAllocation
argument_list|(
argument|const ASTContext&Ctx
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
operator|+
name|hasInitializer
argument_list|()
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
name|getPlacementArgs
argument_list|()
index|[
name|i
index|]
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
name|const_cast
operator|<
name|CXXNewExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPlacementArg
argument_list|(
name|i
argument_list|)
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
comment|/// \brief Whether this new-expression has any initializer at all.
name|bool
name|hasInitializer
argument_list|()
specifier|const
block|{
return|return
name|StoredInitializationStyle
operator|>
literal|0
return|;
block|}
comment|/// \brief The kind of initializer this new-expression has.
name|InitializationStyle
name|getInitializationStyle
argument_list|()
specifier|const
block|{
if|if
condition|(
name|StoredInitializationStyle
operator|==
literal|0
condition|)
return|return
name|NoInit
return|;
return|return
name|static_cast
operator|<
name|InitializationStyle
operator|>
operator|(
name|StoredInitializationStyle
operator|-
literal|1
operator|)
return|;
block|}
comment|/// \brief The initializer of this new-expression.
name|Expr
operator|*
name|getInitializer
argument_list|()
block|{
return|return
name|hasInitializer
argument_list|()
operator|?
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|Array
index|]
operator|)
operator|:
literal|0
return|;
block|}
specifier|const
name|Expr
operator|*
name|getInitializer
argument_list|()
specifier|const
block|{
return|return
name|hasInitializer
argument_list|()
condition|?
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|Array
index|]
operator|)
else|:
literal|0
return|;
block|}
comment|/// \brief Returns the CXXConstructExpr from this new-expression, or null.
specifier|const
name|CXXConstructExpr
operator|*
name|getConstructExpr
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|CXXConstructExpr
operator|>
operator|(
name|getInitializer
argument_list|()
operator|)
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
operator|+
name|hasInitializer
argument_list|()
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
name|hasInitializer
argument_list|()
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
operator|+
name|hasInitializer
argument_list|()
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
name|hasInitializer
argument_list|()
operator|+
name|getNumPlacementArgs
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
name|hasInitializer
argument_list|()
operator|+
name|getNumPlacementArgs
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
name|SubExprs
operator|+
name|Array
operator|+
name|hasInitializer
argument_list|()
operator|+
name|getNumPlacementArgs
argument_list|()
return|;
block|}
name|SourceLocation
name|getStartLoc
argument_list|()
specifier|const
block|{
return|return
name|Range
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceLocation
name|getEndLoc
argument_list|()
specifier|const
block|{
return|return
name|Range
operator|.
name|getEnd
argument_list|()
return|;
block|}
name|SourceRange
name|getDirectInitRange
argument_list|()
specifier|const
block|{
return|return
name|DirectInitRange
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getStartLoc
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
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|raw_arg_begin
argument_list|()
argument_list|,
name|raw_arg_end
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a \c delete expression for memory deallocation and
comment|/// destructor calls, e.g. "delete[] pArray".
name|class
name|CXXDeleteExpr
operator|:
name|public
name|Expr
block|{
comment|/// Points to the operator delete overload that is used. Could be a member.
name|FunctionDecl
operator|*
name|OperatorDelete
block|;
comment|/// The pointer expression to be deleted.
name|Stmt
operator|*
name|Argument
block|;
comment|/// Location of the expression.
name|SourceLocation
name|Loc
block|;
comment|/// Is this a forced global delete, i.e. "::delete"?
name|bool
name|GlobalDelete
operator|:
literal|1
block|;
comment|/// Is this the array form of delete, i.e. "delete[]"?
name|bool
name|ArrayForm
operator|:
literal|1
block|;
comment|/// ArrayFormAsWritten can be different from ArrayForm if 'delete' is applied
comment|/// to pointer-to-array type (ArrayFormAsWritten will be false while ArrayForm
comment|/// will be true).
name|bool
name|ArrayFormAsWritten
operator|:
literal|1
block|;
comment|/// Does the usual deallocation function for the element type require
comment|/// a size_t argument?
name|bool
name|UsualArrayDeleteWantsSize
operator|:
literal|1
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
name|isInstantiationDependent
argument_list|()
argument_list|,
name|arg
operator|->
name|containsUnexpandedParameterPack
argument_list|()
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
name|loc
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
argument|usualArrayDeleteWantsSize
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
comment|/// \brief Retrieve the type being destroyed.
comment|///
comment|/// If the type being destroyed is a dependent type which may or may not
comment|/// be a pointer, return an invalid type.
name|QualType
name|getDestroyedType
argument_list|()
specifier|const
block|;
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Argument
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
name|CXXDeleteExprClass
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
comment|/// \brief Stores the type being destroyed by a pseudo-destructor expression.
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
argument|const ASTContext&Context
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
operator|.
name|hasQualifier
argument_list|()
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
comment|/// null.
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
comment|/// expressions. Returns null if we only have the identifier for a
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Base
operator|->
name|getLocStart
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
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
comment|/// \brief Represents a GCC or MS unary type trait, as used in the
comment|/// implementation of TR1/C++11 type trait templates.
comment|///
comment|/// Example:
comment|/// \code
comment|///   __is_pod(int) == true
comment|///   __is_enum(std::string) == false
comment|/// \endcode
name|class
name|UnaryTypeTraitExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The trait. A UnaryTypeTrait enum in MSVC compatible unsigned.
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
comment|/// \brief The location of the type trait keyword.
name|SourceLocation
name|Loc
block|;
comment|/// \brief The location of the closing paren.
name|SourceLocation
name|RParen
block|;
comment|/// \brief The type being queried.
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
name|isInstantiationDependentType
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RParen
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
comment|/// \brief Represents a GCC or MS binary type trait, as used in the
comment|/// implementation of TR1/C++11 type trait templates.
comment|///
comment|/// Example:
comment|/// \code
comment|///   __is_base_of(Base, Derived) == true
comment|/// \endcode
name|class
name|BinaryTypeTraitExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The trait. A BinaryTypeTrait enum in MSVC compatible unsigned.
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
comment|/// \brief The location of the type trait keyword.
name|SourceLocation
name|Loc
block|;
comment|/// \brief The location of the closing paren.
name|SourceLocation
name|RParen
block|;
comment|/// \brief The lhs type being queried.
name|TypeSourceInfo
operator|*
name|LhsType
block|;
comment|/// \brief The rhs type being queried.
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
name|isInstantiationDependentType
argument_list|()
operator|||
name|rhsType
operator|->
name|getType
argument_list|()
operator|->
name|isInstantiationDependentType
argument_list|()
operator|)
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RParen
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
comment|/// \brief A type trait used in the implementation of various C++11 and
comment|/// Library TR1 trait templates.
comment|///
comment|/// \code
comment|///   __is_trivially_constructible(vector<int>, int*, int*)
comment|/// \endcode
name|class
name|TypeTraitExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The location of the type trait keyword.
name|SourceLocation
name|Loc
block|;
comment|/// \brief  The location of the closing parenthesis.
name|SourceLocation
name|RParenLoc
block|;
comment|// Note: The TypeSourceInfos for the arguments are allocated after the
comment|// TypeTraitExpr.
name|TypeTraitExpr
argument_list|(
argument|QualType T
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|TypeTrait Kind
argument_list|,
argument|ArrayRef<TypeSourceInfo *> Args
argument_list|,
argument|SourceLocation RParenLoc
argument_list|,
argument|bool Value
argument_list|)
block|;
name|TypeTraitExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|TypeTraitExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// \brief Retrieve the argument types.
name|TypeSourceInfo
operator|*
operator|*
name|getTypeSourceInfos
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|TypeSourceInfo
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
comment|/// \brief Retrieve the argument types.
name|TypeSourceInfo
operator|*
specifier|const
operator|*
name|getTypeSourceInfos
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|TypeSourceInfo
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
name|public
operator|:
comment|/// \brief Create a new type trait expression.
specifier|static
name|TypeTraitExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|QualType T
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|TypeTrait Kind
argument_list|,
argument|ArrayRef<TypeSourceInfo *> Args
argument_list|,
argument|SourceLocation RParenLoc
argument_list|,
argument|bool Value
argument_list|)
block|;
specifier|static
name|TypeTraitExpr
operator|*
name|CreateDeserialized
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumArgs
argument_list|)
block|;
comment|/// \brief Determine which type trait this expression uses.
name|TypeTrait
name|getTrait
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|TypeTrait
operator|>
operator|(
name|TypeTraitExprBits
operator|.
name|Kind
operator|)
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
name|isValueDependent
argument_list|()
argument_list|)
block|;
return|return
name|TypeTraitExprBits
operator|.
name|Value
return|;
block|}
comment|/// \brief Determine the number of arguments to this type trait.
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|TypeTraitExprBits
operator|.
name|NumArgs
return|;
block|}
comment|/// \brief Retrieve the Ith argument.
name|TypeSourceInfo
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
name|getNumArgs
argument_list|()
operator|&&
literal|"Argument out-of-range"
argument_list|)
block|;
return|return
name|getArgs
argument_list|()
index|[
name|I
index|]
return|;
block|}
comment|/// \brief Retrieve the argument types.
name|ArrayRef
operator|<
name|TypeSourceInfo
operator|*
operator|>
name|getArgs
argument_list|()
specifier|const
block|{
return|return
name|ArrayRef
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
name|getTypeSourceInfos
argument_list|()
expr|,
name|getNumArgs
argument_list|()
operator|)
return|;
block|}
typedef|typedef
name|TypeSourceInfo
modifier|*
modifier|*
name|arg_iterator
typedef|;
name|arg_iterator
name|arg_begin
argument_list|()
block|{
return|return
name|getTypeSourceInfos
argument_list|()
return|;
block|}
name|arg_iterator
name|arg_end
argument_list|()
block|{
return|return
name|getTypeSourceInfos
argument_list|()
operator|+
name|getNumArgs
argument_list|()
return|;
block|}
typedef|typedef
name|TypeSourceInfo
specifier|const
modifier|*
specifier|const
modifier|*
name|arg_const_iterator
typedef|;
name|arg_const_iterator
name|arg_begin
argument_list|()
specifier|const
block|{
return|return
name|getTypeSourceInfos
argument_list|()
return|;
block|}
name|arg_const_iterator
name|arg_end
argument_list|()
specifier|const
block|{
return|return
name|getTypeSourceInfos
argument_list|()
operator|+
name|getNumArgs
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RParenLoc
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
name|TypeTraitExprClass
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
block|;  }
block|;
comment|/// \brief An Embarcadero array type trait, as used in the implementation of
comment|/// __array_rank and __array_extent.
comment|///
comment|/// Example:
comment|/// \code
comment|///   __array_rank(int[10][20]) == 2
comment|///   __array_extent(int, 1)    == 20
comment|/// \endcode
name|class
name|ArrayTypeTraitExpr
operator|:
name|public
name|Expr
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// \brief The trait. An ArrayTypeTrait enum in MSVC compat unsigned.
name|unsigned
name|ATT
operator|:
literal|2
block|;
comment|/// \brief The value of the type trait. Unspecified if dependent.
name|uint64_t
name|Value
block|;
comment|/// \brief The array dimension being queried, or -1 if not used.
name|Expr
operator|*
name|Dimension
block|;
comment|/// \brief The location of the type trait keyword.
name|SourceLocation
name|Loc
block|;
comment|/// \brief The location of the closing paren.
name|SourceLocation
name|RParen
block|;
comment|/// \brief The type being queried.
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
operator|(
name|queried
operator|->
name|getType
argument_list|()
operator|->
name|isInstantiationDependentType
argument_list|()
operator|||
operator|(
name|dimension
operator|&&
name|dimension
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
operator|)
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RParen
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
comment|/// \brief An expression trait intrinsic.
comment|///
comment|/// Example:
comment|/// \code
comment|///   __is_lvalue_expr(std::cout) == true
comment|///   __is_lvalue_expr(1) == false
comment|/// \endcode
name|class
name|ExpressionTraitExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The trait. A ExpressionTrait enum in MSVC compatible unsigned.
name|unsigned
name|ET
operator|:
literal|31
block|;
comment|/// \brief The value of the type trait. Unspecified if dependent.
name|bool
name|Value
operator|:
literal|1
block|;
comment|/// \brief The location of the type trait keyword.
name|SourceLocation
name|Loc
block|;
comment|/// \brief The location of the closing paren.
name|SourceLocation
name|RParen
block|;
comment|/// \brief The expression being queried.
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
name|isInstantiationDependent
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RParen
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
comment|/// \c UnresolvedLookupExpr or an \c UnresolvedMemberExpr.
name|class
name|OverloadExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The common name of these declarations.
name|DeclarationNameInfo
name|NameInfo
block|;
comment|/// \brief The nested-name-specifier that qualifies the name, if any.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
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
name|protected
operator|:
comment|/// \brief Whether the name includes info for explicit template
comment|/// keyword and arguments.
name|bool
name|HasTemplateKWAndArgsInfo
block|;
comment|/// \brief Return the optional template keyword and arguments info.
name|ASTTemplateKWAndArgsInfo
operator|*
name|getTemplateKWAndArgsInfo
argument_list|()
block|;
comment|// defined far below.
comment|/// \brief Return the optional template keyword and arguments info.
specifier|const
name|ASTTemplateKWAndArgsInfo
operator|*
name|getTemplateKWAndArgsInfo
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
name|getTemplateKWAndArgsInfo
argument_list|()
return|;
block|}
name|OverloadExpr
argument_list|(
argument|StmtClass K
argument_list|,
argument|const ASTContext&C
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation TemplateKWLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|,
argument|UnresolvedSetIterator Begin
argument_list|,
argument|UnresolvedSetIterator End
argument_list|,
argument|bool KnownDependent
argument_list|,
argument|bool KnownInstantiationDependent
argument_list|,
argument|bool KnownContainsUnexpandedParameterPack
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
name|QualifierLoc
argument_list|()
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
name|HasTemplateKWAndArgsInfo
argument_list|(
argument|false
argument_list|)
block|{ }
name|void
name|initializeResults
argument_list|(
argument|const ASTContext&C
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
comment|/// \brief Finds the overloaded expression in the given expression \p E of
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
comment|/// \brief Gets the naming class of this lookup, if any.
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
comment|/// \brief Gets the number of declarations in the unresolved set.
name|unsigned
name|getNumDecls
argument_list|()
specifier|const
block|{
return|return
name|NumResults
return|;
block|}
comment|/// \brief Gets the full name info.
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
comment|/// \brief Gets the name looked up.
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
comment|/// \brief Gets the location of the name.
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
comment|/// \brief Fetches the nested-name qualifier, if one was given.
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
comment|/// \brief Fetches the nested-name qualifier with source-location
comment|/// information, if one was given.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief Retrieve the location of the template keyword preceding
comment|/// this name, if any.
name|SourceLocation
name|getTemplateKeywordLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
return|return
name|getTemplateKWAndArgsInfo
argument_list|()
operator|->
name|getTemplateKeywordLoc
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the location of the left angle bracket starting the
comment|/// explicit template argument list following the name, if any.
name|SourceLocation
name|getLAngleLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
return|return
name|getTemplateKWAndArgsInfo
argument_list|()
operator|->
name|LAngleLoc
return|;
block|}
comment|/// \brief Retrieve the location of the right angle bracket ending the
comment|/// explicit template argument list following the name, if any.
name|SourceLocation
name|getRAngleLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
return|return
name|getTemplateKWAndArgsInfo
argument_list|()
operator|->
name|RAngleLoc
return|;
block|}
comment|/// \brief Determines whether the name was preceded by the template keyword.
name|bool
name|hasTemplateKeyword
argument_list|()
specifier|const
block|{
return|return
name|getTemplateKeywordLoc
argument_list|()
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// \brief Determines whether this expression had explicit template arguments.
name|bool
name|hasExplicitTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getLAngleLoc
argument_list|()
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|// Note that, inconsistently with the explicit-template-argument AST
comment|// nodes, users are *forbidden* from calling these methods on objects
comment|// without explicit template arguments.
name|ASTTemplateArgumentListInfo
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
name|getTemplateKWAndArgsInfo
argument_list|()
return|;
block|}
specifier|const
name|ASTTemplateArgumentListInfo
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
comment|/// \brief Retrieves the optional explicit template arguments.
comment|///
comment|/// This points to the same data as getExplicitTemplateArgs(), but
comment|/// returns null if there are no explicit template arguments.
specifier|const
name|ASTTemplateArgumentListInfo
operator|*
name|getOptionalExplicitTemplateArgs
argument_list|()
specifier|const
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
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|; }
decl_stmt|;
comment|/// \brief A reference to a name which we were able to look up during
comment|/// parsing but could not resolve to a specific declaration.
comment|///
comment|/// This arises in several ways:
comment|///   * we might be waiting for argument-dependent lookup;
comment|///   * the name might resolve to an overloaded function;
comment|/// and eventually:
comment|///   * the lookup might have included a function template.
comment|///
comment|/// These never include UnresolvedUsingValueDecls, which are always class
comment|/// members and therefore appear only in UnresolvedMemberLookupExprs.
name|class
name|UnresolvedLookupExpr
range|:
name|public
name|OverloadExpr
block|{
comment|/// True if these lookup results should be extended by
comment|/// argument-dependent lookup if this is the operand of a function
comment|/// call.
name|bool
name|RequiresADL
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
argument|const ASTContext&C
argument_list|,
argument|CXXRecordDecl *NamingClass
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation TemplateKWLoc
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
name|TemplateKWLoc
argument_list|,
name|NameInfo
argument_list|,
name|TemplateArgs
argument_list|,
name|Begin
argument_list|,
name|End
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|RequiresADL
argument_list|(
name|RequiresADL
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
argument|const ASTContext&C
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
argument_list|)
block|{
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
name|SourceLocation
argument_list|()
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
argument_list|)
return|;
block|}
specifier|static
name|UnresolvedLookupExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|CXXRecordDecl *NamingClass
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation TemplateKWLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|bool ADL
argument_list|,
argument|const TemplateArgumentListInfo *Args
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
argument|const ASTContext&C
argument_list|,
argument|bool HasTemplateKWAndArgsInfo
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|NestedNameSpecifierLoc
name|l
init|=
name|getQualifierLoc
argument_list|()
condition|)
return|return
name|l
operator|.
name|getBeginLoc
argument_list|()
return|;
return|return
name|getNameInfo
argument_list|()
operator|.
name|getLocStart
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
name|getRAngleLoc
argument_list|()
return|;
return|return
name|getNameInfo
argument_list|()
operator|.
name|getLocEnd
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|child_range
name|children
parameter_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
end_function

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
name|UnresolvedLookupExprClass
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief A qualified reference to a name whose declaration cannot
end_comment

begin_comment
comment|/// yet be resolved.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// DependentScopeDeclRefExpr is similar to DeclRefExpr in that
end_comment

begin_comment
comment|/// it expresses a reference to a declaration such as
end_comment

begin_comment
comment|/// X<T>::value. The difference, however, is that an
end_comment

begin_comment
comment|/// DependentScopeDeclRefExpr node is used only within C++ templates when
end_comment

begin_comment
comment|/// the qualification (e.g., X<T>::) refers to a dependent type. In
end_comment

begin_comment
comment|/// this case, X<T>::value cannot resolve to a declaration because the
end_comment

begin_comment
comment|/// declaration will differ from one instantiation of X<T> to the
end_comment

begin_comment
comment|/// next. Therefore, DependentScopeDeclRefExpr keeps track of the
end_comment

begin_comment
comment|/// qualifier (X<T>::) and the name of the entity being referenced
end_comment

begin_comment
comment|/// ("value"). Such expressions will instantiate to a DeclRefExpr once the
end_comment

begin_comment
comment|/// declaration can be found.
end_comment

begin_decl_stmt
name|class
name|DependentScopeDeclRefExpr
range|:
name|public
name|Expr
block|{
comment|/// \brief The nested-name-specifier that qualifies this unresolved
comment|/// declaration name.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
comment|/// \brief The name of the entity we will be referencing.
name|DeclarationNameInfo
name|NameInfo
block|;
comment|/// \brief Whether the name includes info for explicit template
comment|/// keyword and arguments.
name|bool
name|HasTemplateKWAndArgsInfo
block|;
comment|/// \brief Return the optional template keyword and arguments info.
name|ASTTemplateKWAndArgsInfo
operator|*
name|getTemplateKWAndArgsInfo
argument_list|()
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
literal|0
return|;
return|return
name|reinterpret_cast
operator|<
name|ASTTemplateKWAndArgsInfo
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return the optional template keyword and arguments info.
end_comment

begin_expr_stmt
specifier|const
name|ASTTemplateKWAndArgsInfo
operator|*
name|getTemplateKWAndArgsInfo
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|DependentScopeDeclRefExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getTemplateKWAndArgsInfo
argument_list|()
return|;
block|}
end_expr_stmt

begin_macro
name|DependentScopeDeclRefExpr
argument_list|(
argument|QualType T
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation TemplateKWLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|const TemplateArgumentListInfo *Args
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|public
label|:
end_label

begin_function_decl
specifier|static
name|DependentScopeDeclRefExpr
modifier|*
name|Create
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|NestedNameSpecifierLoc
name|QualifierLoc
parameter_list|,
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|DependentScopeDeclRefExpr
modifier|*
name|CreateEmpty
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|bool
name|HasTemplateKWAndArgsInfo
parameter_list|,
name|unsigned
name|NumTemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the name that this expression refers to.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the name that this expression refers to.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the location of the name within the expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example, in "X<T>::value" this is the location of "value".
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the nested-name-specifier that qualifies the
end_comment

begin_comment
comment|/// name, with source location information.
end_comment

begin_expr_stmt
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the nested-name-specifier that qualifies this
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the location of the template keyword preceding
end_comment

begin_comment
comment|/// this name, if any.
end_comment

begin_expr_stmt
name|SourceLocation
name|getTemplateKeywordLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getTemplateKWAndArgsInfo
argument_list|()
operator|->
name|getTemplateKeywordLoc
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the location of the left angle bracket starting the
end_comment

begin_comment
comment|/// explicit template argument list following the name, if any.
end_comment

begin_macro
unit|SourceLocation
name|getLAngleLoc
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getTemplateKWAndArgsInfo
argument_list|()
operator|->
name|LAngleLoc
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the location of the right angle bracket ending the
end_comment

begin_comment
comment|/// explicit template argument list following the name, if any.
end_comment

begin_macro
unit|SourceLocation
name|getRAngleLoc
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getTemplateKWAndArgsInfo
argument_list|()
operator|->
name|RAngleLoc
return|;
end_return

begin_comment
unit|}
comment|/// Determines whether the name was preceded by the template keyword.
end_comment

begin_macro
unit|bool
name|hasTemplateKeyword
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|getTemplateKeywordLoc
argument_list|()
operator|.
name|isValid
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Determines whether this lookup had explicit template arguments.
end_comment

begin_expr_stmt
name|bool
name|hasExplicitTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getLAngleLoc
argument_list|()
operator|.
name|isValid
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Note that, inconsistently with the explicit-template-argument AST
end_comment

begin_comment
comment|// nodes, users are *forbidden* from calling these methods on objects
end_comment

begin_comment
comment|// without explicit template arguments.
end_comment

begin_function
name|ASTTemplateArgumentListInfo
modifier|&
name|getExplicitTemplateArgs
parameter_list|()
block|{
name|assert
argument_list|(
name|hasExplicitTemplateArgs
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
name|reinterpret_cast
operator|<
name|ASTTemplateArgumentListInfo
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Gets a reference to the explicit template argument list.
end_comment

begin_expr_stmt
specifier|const
name|ASTTemplateArgumentListInfo
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
name|ASTTemplateArgumentListInfo
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieves the optional explicit template arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This points to the same data as getExplicitTemplateArgs(), but
end_comment

begin_comment
comment|/// returns null if there are no explicit template arguments.
end_comment

begin_expr_stmt
specifier|const
name|ASTTemplateArgumentListInfo
operator|*
name|getOptionalExplicitTemplateArgs
argument_list|()
specifier|const
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
end_expr_stmt

begin_return
return|return
operator|&
name|getExplicitTemplateArgs
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Copies the template arguments (if present) into the given
end_comment

begin_comment
comment|/// structure.
end_comment

begin_macro
unit|void
name|copyTemplateArgumentsInto
argument_list|(
argument|TemplateArgumentListInfo&List
argument_list|)
end_macro

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// Note: getLocStart() is the start of the whole DependentScopeDeclRefExpr,
end_comment

begin_comment
comment|/// and differs from getLocation().getStart().
end_comment

begin_expr_stmt
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|QualifierLoc
operator|.
name|getBeginLoc
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
name|getRAngleLoc
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getLocation
argument_list|()
return|;
end_return

begin_function
unit|}    static
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
name|DependentScopeDeclRefExprClass
return|;
block|}
end_function

begin_function
name|child_range
name|children
parameter_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTStmtReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTStmtWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// Represents an expression -- generally a full-expression -- that
end_comment

begin_comment
comment|/// introduces cleanups to be run at the end of the sub-expression's
end_comment

begin_comment
comment|/// evaluation.  The most common source of expression-introduced
end_comment

begin_comment
comment|/// cleanups is temporary objects in C++, but several other kinds of
end_comment

begin_comment
comment|/// expressions can create cleanups, including basically every
end_comment

begin_comment
comment|/// call in ARC that returns an Objective-C pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This expression also tracks whether the sub-expression contains a
end_comment

begin_comment
comment|/// potentially-evaluated block literal.  The lifetime of a block
end_comment

begin_comment
comment|/// literal is the extent of the enclosing scope.
end_comment

begin_decl_stmt
name|class
name|ExprWithCleanups
range|:
name|public
name|Expr
block|{
name|public
operator|:
comment|/// The type of objects that are kept in the cleanup.
comment|/// It's useful to remember the set of blocks;  we could also
comment|/// remember the set of temporaries, but there's currently
comment|/// no need.
typedef|typedef
name|BlockDecl
modifier|*
name|CleanupObject
typedef|;
name|private
operator|:
name|Stmt
operator|*
name|SubExpr
decl_stmt|;
end_decl_stmt

begin_macro
name|ExprWithCleanups
argument_list|(
argument|EmptyShell
argument_list|,
argument|unsigned NumObjects
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|ExprWithCleanups
argument_list|(
name|Expr
operator|*
name|SubExpr
argument_list|,
name|ArrayRef
operator|<
name|CleanupObject
operator|>
name|Objects
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|CleanupObject
modifier|*
name|getObjectsBuffer
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|CleanupObject
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|CleanupObject
operator|*
name|getObjectsBuffer
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|CleanupObject
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|friend
name|class
name|ASTStmtReader
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_function_decl
specifier|static
name|ExprWithCleanups
modifier|*
name|Create
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|EmptyShell
name|empty
parameter_list|,
name|unsigned
name|numObjects
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|ExprWithCleanups
modifier|*
name|Create
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|Expr
operator|*
name|subexpr
argument_list|,
name|ArrayRef
operator|<
name|CleanupObject
operator|>
name|objects
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|ArrayRef
operator|<
name|CleanupObject
operator|>
name|getObjects
argument_list|()
specifier|const
block|{
return|return
name|ArrayRef
operator|<
name|CleanupObject
operator|>
operator|(
name|getObjectsBuffer
argument_list|()
operator|,
name|getNumObjects
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getNumObjects
argument_list|()
specifier|const
block|{
return|return
name|ExprWithCleanupsBits
operator|.
name|NumObjects
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|CleanupObject
name|getObject
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumObjects
argument_list|()
operator|&&
literal|"Index out of range"
argument_list|)
expr_stmt|;
return|return
name|getObjects
argument_list|()
index|[
name|i
index|]
return|;
block|}
end_decl_stmt

begin_function
name|Expr
modifier|*
name|getSubExpr
parameter_list|()
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// As with any mutator of the AST, be very careful
end_comment

begin_comment
comment|/// when modifying an existing AST to preserve its invariants.
end_comment

begin_function
name|void
name|setSubExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
name|SubExpr
operator|=
name|E
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SubExpr
operator|->
name|getLocStart
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SubExpr
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Implement isa/cast/dyncast/etc.
end_comment

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
name|ExprWithCleanupsClass
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
end_function

begin_comment
unit|};
comment|/// \brief Describes an explicit type conversion that uses functional
end_comment

begin_comment
comment|/// notion but could not be resolved because one or more arguments are
end_comment

begin_comment
comment|/// type-dependent.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The explicit type conversions expressed by
end_comment

begin_comment
comment|/// CXXUnresolvedConstructExpr have the form<tt>T(a1, a2, ..., aN)</tt>,
end_comment

begin_comment
comment|/// where \c T is some type and \c a1, \c a2, ..., \c aN are values, and
end_comment

begin_comment
comment|/// either \c T is a dependent type or one or more of the<tt>a</tt>'s is
end_comment

begin_comment
comment|/// type-dependent. For example, this would occur in a template such
end_comment

begin_comment
comment|/// as:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///   template<typename T, typename A1>
end_comment

begin_comment
comment|///   inline T make_a(const A1& a1) {
end_comment

begin_comment
comment|///     return T(a1);
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When the returned expression is instantiated, it may resolve to a
end_comment

begin_comment
comment|/// constructor call, conversion function call, or some kind of type
end_comment

begin_comment
comment|/// conversion.
end_comment

begin_decl_stmt
name|class
name|CXXUnresolvedConstructExpr
range|:
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
argument|ArrayRef<Expr*> Args
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
argument|const ASTContext&C
argument_list|,
argument|TypeSourceInfo *Type
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|ArrayRef<Expr*> Args
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|;
specifier|static
name|CXXUnresolvedConstructExpr
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
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
end_decl_stmt

begin_typedef
typedef|typedef
specifier|const
name|Expr
modifier|*
specifier|const
modifier|*
name|const_arg_iterator
typedef|;
end_typedef

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
name|Expr
modifier|*
name|getArg
parameter_list|(
name|unsigned
name|I
parameter_list|)
block|{
name|assert
argument_list|(
name|I
operator|<
name|NumArgs
operator|&&
literal|"Argument index out-of-range"
argument_list|)
expr_stmt|;
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
end_function

begin_decl_stmt
specifier|const
name|Expr
modifier|*
name|getArg
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|NumArgs
operator|&&
literal|"Argument index out-of-range"
argument_list|)
expr_stmt|;
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
end_decl_stmt

begin_function
name|void
name|setArg
parameter_list|(
name|unsigned
name|I
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|)
block|{
name|assert
argument_list|(
name|I
operator|<
name|NumArgs
operator|&&
literal|"Argument index out-of-range"
argument_list|)
expr_stmt|;
operator|*
operator|(
name|arg_begin
argument_list|()
operator|+
name|I
operator|)
operator|=
name|E
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
name|assert
argument_list|(
name|RParenLoc
operator|.
name|isValid
argument_list|()
operator|||
name|NumArgs
operator|==
literal|1
argument_list|)
block|;
return|return
name|RParenLoc
operator|.
name|isValid
argument_list|()
condition|?
name|RParenLoc
else|:
name|getArg
argument_list|(
literal|0
argument_list|)
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
end_expr_stmt

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
name|CXXUnresolvedConstructExprClass
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
name|Stmt
modifier|*
modifier|*
name|begin
init|=
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
decl_stmt|;
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
end_function

begin_comment
unit|};
comment|/// \brief Represents a C++ member access expression where the actual
end_comment

begin_comment
comment|/// member referenced could not be resolved because the base
end_comment

begin_comment
comment|/// expression or the member name was dependent.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Like UnresolvedMemberExprs, these can be either implicit or
end_comment

begin_comment
comment|/// explicit accesses.  It is only possible to get one of these with
end_comment

begin_comment
comment|/// an implicit access if a qualifier is provided.
end_comment

begin_decl_stmt
name|class
name|CXXDependentScopeMemberExpr
range|:
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
comment|/// \brief Whether this member expression has info for explicit template
comment|/// keyword and arguments.
name|bool
name|HasTemplateKWAndArgsInfo
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
comment|///
comment|/// FIXME: could also be a template-id
name|DeclarationNameInfo
name|MemberNameInfo
block|;
comment|/// \brief Return the optional template keyword and arguments info.
name|ASTTemplateKWAndArgsInfo
operator|*
name|getTemplateKWAndArgsInfo
argument_list|()
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
literal|0
return|;
return|return
name|reinterpret_cast
operator|<
name|ASTTemplateKWAndArgsInfo
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return the optional template keyword and arguments info.
end_comment

begin_expr_stmt
specifier|const
name|ASTTemplateKWAndArgsInfo
operator|*
name|getTemplateKWAndArgsInfo
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
name|getTemplateKWAndArgsInfo
argument_list|()
return|;
block|}
end_expr_stmt

begin_macro
name|CXXDependentScopeMemberExpr
argument_list|(
argument|const ASTContext&C
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
argument|SourceLocation TemplateKWLoc
argument_list|,
argument|NamedDecl *FirstQualifierFoundInScope
argument_list|,
argument|DeclarationNameInfo MemberNameInfo
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|CXXDependentScopeMemberExpr
argument_list|(
argument|const ASTContext&C
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
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|static
name|CXXDependentScopeMemberExpr
modifier|*
name|Create
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|Expr
modifier|*
name|Base
parameter_list|,
name|QualType
name|BaseType
parameter_list|,
name|bool
name|IsArrow
parameter_list|,
name|SourceLocation
name|OperatorLoc
parameter_list|,
name|NestedNameSpecifierLoc
name|QualifierLoc
parameter_list|,
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
name|NamedDecl
modifier|*
name|FirstQualifierFoundInScope
parameter_list|,
name|DeclarationNameInfo
name|MemberNameInfo
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|CXXDependentScopeMemberExpr
modifier|*
name|CreateEmpty
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|bool
name|HasTemplateKWAndArgsInfo
parameter_list|,
name|unsigned
name|NumTemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief True if this is an implicit access, i.e. one in which the
end_comment

begin_comment
comment|/// member being accessed was not written in the source.  The source
end_comment

begin_comment
comment|/// location of the operator is invalid in this case.
end_comment

begin_expr_stmt
name|bool
name|isImplicitAccess
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the base object of this member expressions,
end_comment

begin_comment
comment|/// e.g., the \c x in \c x.m.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|QualType
name|getBaseType
argument_list|()
specifier|const
block|{
return|return
name|BaseType
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this member expression used the '->'
end_comment

begin_comment
comment|/// operator; otherwise, it used the '.' operator.
end_comment

begin_expr_stmt
name|bool
name|isArrow
argument_list|()
specifier|const
block|{
return|return
name|IsArrow
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the location of the '->' or '.' operator.
end_comment

begin_expr_stmt
name|SourceLocation
name|getOperatorLoc
argument_list|()
specifier|const
block|{
return|return
name|OperatorLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the nested-name-specifier that qualifies the member
end_comment

begin_comment
comment|/// name.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the nested-name-specifier that qualifies the member
end_comment

begin_comment
comment|/// name, with source location information.
end_comment

begin_expr_stmt
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the first part of the nested-name-specifier that was
end_comment

begin_comment
comment|/// found in the scope of the member access expression when the member access
end_comment

begin_comment
comment|/// was initially parsed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function only returns a useful result when member access expression
end_comment

begin_comment
comment|/// uses a qualified member name, e.g., "x.Base::f". Here, the declaration
end_comment

begin_comment
comment|/// returned by this function describes what was found by unqualified name
end_comment

begin_comment
comment|/// lookup for the identifier "Base" within the scope of the member access
end_comment

begin_comment
comment|/// expression itself. At template instantiation time, this information is
end_comment

begin_comment
comment|/// combined with the results of name lookup into the type of the object
end_comment

begin_comment
comment|/// expression itself (the class type of x).
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the name of the member that this expression
end_comment

begin_comment
comment|/// refers to.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the name of the member that this expression
end_comment

begin_comment
comment|/// refers to.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|// \brief Retrieve the location of the name of the member that this
end_comment

begin_comment
comment|// expression refers to.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the location of the template keyword preceding the
end_comment

begin_comment
comment|/// member name, if any.
end_comment

begin_expr_stmt
name|SourceLocation
name|getTemplateKeywordLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getTemplateKWAndArgsInfo
argument_list|()
operator|->
name|getTemplateKeywordLoc
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the location of the left angle bracket starting the
end_comment

begin_comment
comment|/// explicit template argument list following the member name, if any.
end_comment

begin_macro
unit|SourceLocation
name|getLAngleLoc
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getTemplateKWAndArgsInfo
argument_list|()
operator|->
name|LAngleLoc
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the location of the right angle bracket ending the
end_comment

begin_comment
comment|/// explicit template argument list following the member name, if any.
end_comment

begin_macro
unit|SourceLocation
name|getRAngleLoc
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getTemplateKWAndArgsInfo
argument_list|()
operator|->
name|RAngleLoc
return|;
end_return

begin_comment
unit|}
comment|/// Determines whether the member name was preceded by the template keyword.
end_comment

begin_macro
unit|bool
name|hasTemplateKeyword
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|getTemplateKeywordLoc
argument_list|()
operator|.
name|isValid
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determines whether this member expression actually had a C++
end_comment

begin_comment
comment|/// template argument list explicitly specified, e.g., x.f<int>.
end_comment

begin_expr_stmt
name|bool
name|hasExplicitTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getLAngleLoc
argument_list|()
operator|.
name|isValid
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the explicit template argument list that followed the
end_comment

begin_comment
comment|/// member template name, if any.
end_comment

begin_function
name|ASTTemplateArgumentListInfo
modifier|&
name|getExplicitTemplateArgs
parameter_list|()
block|{
name|assert
argument_list|(
name|hasExplicitTemplateArgs
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
name|reinterpret_cast
operator|<
name|ASTTemplateArgumentListInfo
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the explicit template argument list that followed the
end_comment

begin_comment
comment|/// member template name, if any.
end_comment

begin_expr_stmt
specifier|const
name|ASTTemplateArgumentListInfo
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieves the optional explicit template arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This points to the same data as getExplicitTemplateArgs(), but
end_comment

begin_comment
comment|/// returns null if there are no explicit template arguments.
end_comment

begin_expr_stmt
specifier|const
name|ASTTemplateArgumentListInfo
operator|*
name|getOptionalExplicitTemplateArgs
argument_list|()
specifier|const
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
end_expr_stmt

begin_return
return|return
operator|&
name|getExplicitTemplateArgs
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Copies the template arguments (if present) into the given
end_comment

begin_comment
comment|/// structure.
end_comment

begin_macro
unit|void
name|copyTemplateArgumentsInto
argument_list|(
argument|TemplateArgumentListInfo&List
argument_list|)
end_macro

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the number of template arguments provided as part of this
end_comment

begin_comment
comment|/// template-id.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
operator|!
name|isImplicitAccess
argument_list|()
condition|)
return|return
name|Base
operator|->
name|getLocStart
argument_list|()
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|getQualifier
argument_list|()
condition|)
return|return
name|getQualifierLoc
argument_list|()
operator|.
name|getBeginLoc
argument_list|()
return|;
end_if

begin_return
return|return
name|MemberNameInfo
operator|.
name|getBeginLoc
argument_list|()
return|;
end_return

begin_macro
unit|}   SourceLocation
name|getLocEnd
argument_list|()
end_macro

begin_expr_stmt
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
name|getRAngleLoc
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|MemberNameInfo
operator|.
name|getEndLoc
argument_list|()
return|;
end_return

begin_function
unit|}    static
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
name|CXXDependentScopeMemberExprClass
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

begin_decl_stmt
name|friend
name|class
name|ASTStmtReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTStmtWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Represents a C++ member access expression for which lookup
end_comment

begin_comment
comment|/// produced a set of overloaded functions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The member access may be explicit or implicit:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///    struct A {
end_comment

begin_comment
comment|///      int a, b;
end_comment

begin_comment
comment|///      int explicitAccess() { return this->a + this->A::b; }
end_comment

begin_comment
comment|///      int implicitAccess() { return a + A::b; }
end_comment

begin_comment
comment|///    };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In the final AST, an explicit access always becomes a MemberExpr.
end_comment

begin_comment
comment|/// An implicit access may become either a MemberExpr or a
end_comment

begin_comment
comment|/// DeclRefExpr, depending on whether the member is static.
end_comment

begin_decl_stmt
name|class
name|UnresolvedMemberExpr
range|:
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
comment|/// e.g., the \c x in x.f.
comment|///
comment|/// This can be null if this is an 'unbased' member expression.
name|Stmt
operator|*
name|Base
block|;
comment|/// \brief The type of the base expression; never null.
name|QualType
name|BaseType
block|;
comment|/// \brief The location of the '->' or '.' operator.
name|SourceLocation
name|OperatorLoc
block|;
name|UnresolvedMemberExpr
argument_list|(
argument|const ASTContext&C
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
argument|SourceLocation TemplateKWLoc
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
argument|const ASTContext&C
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
argument|SourceLocation TemplateKWLoc
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
argument|const ASTContext&C
argument_list|,
argument|bool HasTemplateKWAndArgsInfo
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|)
block|;
comment|/// \brief True if this is an implicit access, i.e., one in which the
comment|/// member being accessed was not written in the source.
comment|///
comment|/// The source location of the operator is invalid in this case.
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
comment|/// \brief Retrieve the naming class of this lookup.
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
comment|// \brief Return the preferred location (the member name) for the arrow when
comment|// diagnosing a problem with this expression.
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getMemberLoc
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
operator|!
name|isImplicitAccess
argument_list|()
condition|)
return|return
name|Base
operator|->
name|getLocStart
argument_list|()
return|;
if|if
condition|(
name|NestedNameSpecifierLoc
name|l
init|=
name|getQualifierLoc
argument_list|()
condition|)
return|return
name|l
operator|.
name|getBeginLoc
argument_list|()
return|;
end_decl_stmt

begin_return
return|return
name|getMemberNameInfo
argument_list|()
operator|.
name|getLocStart
argument_list|()
return|;
end_return

begin_macro
unit|}   SourceLocation
name|getLocEnd
argument_list|()
end_macro

begin_expr_stmt
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
name|getRAngleLoc
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getMemberNameInfo
argument_list|()
operator|.
name|getLocEnd
argument_list|()
return|;
end_return

begin_function
unit|}    static
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
comment|/// \brief Represents a C++11 noexcept expression (C++ [expr.unary.noexcept]).
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
name|Val
operator|==
name|CT_Dependent
operator|||
name|Operand
operator|->
name|isInstantiationDependent
argument_list|()
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getBegin
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
name|Range
operator|.
name|getEnd
argument_list|()
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
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
comment|/// \brief Represents a C++11 pack expansion that produces a sequence of
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
argument|Optional<unsigned> NumExpansions
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
comment|/*InstantiationDependent=*/
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
name|None
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Pattern
operator|->
name|getLocStart
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
name|EllipsisLoc
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
name|ASTTemplateKWAndArgsInfo
operator|*
name|OverloadExpr
operator|::
name|getTemplateKWAndArgsInfo
argument_list|()
block|{
if|if
condition|(
operator|!
name|HasTemplateKWAndArgsInfo
condition|)
return|return
literal|0
return|;
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
name|reinterpret_cast
operator|<
name|ASTTemplateKWAndArgsInfo
operator|*
operator|>
operator|(
name|cast
operator|<
name|UnresolvedLookupExpr
operator|>
operator|(
name|this
operator|)
operator|+
literal|1
operator|)
return|;
else|else
return|return
name|reinterpret_cast
operator|<
name|ASTTemplateKWAndArgsInfo
operator|*
operator|>
operator|(
name|cast
operator|<
name|UnresolvedMemberExpr
operator|>
operator|(
name|this
operator|)
operator|+
literal|1
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Represents an expression that computes the length of a parameter
end_comment

begin_comment
comment|/// pack.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template<typename ...Types>
end_comment

begin_comment
comment|/// struct count {
end_comment

begin_comment
comment|///   static const unsigned value = sizeof...(Types);
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|SizeOfPackExpr
range|:
name|public
name|Expr
block|{
comment|/// \brief The location of the \c sizeof keyword.
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
comment|/// \brief Create a value-dependent expression that computes the length of
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
comment|/*InstantiationDependent=*/
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
comment|/// \brief Create an expression that computes the length of
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
comment|/*InstantiationDependent=*/
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|OperatorLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RParenLoc
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
comment|/// \brief Represents a reference to a non-type template parameter
comment|/// that has been substituted with a template argument.
name|class
name|SubstNonTypeTemplateParmExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The replaced parameter.
name|NonTypeTemplateParmDecl
operator|*
name|Param
block|;
comment|/// \brief The replacement expression.
name|Stmt
operator|*
name|Replacement
block|;
comment|/// \brief The location of the non-type template parameter reference.
name|SourceLocation
name|NameLoc
block|;
name|friend
name|class
name|ASTReader
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|explicit
name|SubstNonTypeTemplateParmExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|SubstNonTypeTemplateParmExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|public
operator|:
name|SubstNonTypeTemplateParmExpr
argument_list|(
argument|QualType type
argument_list|,
argument|ExprValueKind valueKind
argument_list|,
argument|SourceLocation loc
argument_list|,
argument|NonTypeTemplateParmDecl *param
argument_list|,
argument|Expr *replacement
argument_list|)
operator|:
name|Expr
argument_list|(
name|SubstNonTypeTemplateParmExprClass
argument_list|,
name|type
argument_list|,
name|valueKind
argument_list|,
name|OK_Ordinary
argument_list|,
name|replacement
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|replacement
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|replacement
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|replacement
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Param
argument_list|(
name|param
argument_list|)
block|,
name|Replacement
argument_list|(
name|replacement
argument_list|)
block|,
name|NameLoc
argument_list|(
argument|loc
argument_list|)
block|{}
name|SourceLocation
name|getNameLoc
argument_list|()
specifier|const
block|{
return|return
name|NameLoc
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|NameLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|NameLoc
return|;
block|}
name|Expr
operator|*
name|getReplacement
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Replacement
operator|)
return|;
block|}
name|NonTypeTemplateParmDecl
operator|*
name|getParameter
argument_list|()
specifier|const
block|{
return|return
name|Param
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *s
argument_list|)
block|{
return|return
name|s
operator|->
name|getStmtClass
argument_list|()
operator|==
name|SubstNonTypeTemplateParmExprClass
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
name|Replacement
argument_list|,
operator|&
name|Replacement
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a reference to a non-type template parameter pack that
comment|/// has been substituted with a non-template argument pack.
comment|///
comment|/// When a pack expansion in the source code contains multiple parameter packs
comment|/// and those parameter packs correspond to different levels of template
comment|/// parameter lists, this node is used to represent a non-type template
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
name|ASTReader
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|explicit
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|NameLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
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
comment|/// \brief Represents a reference to a function parameter pack that has been
comment|/// substituted but not yet expanded.
comment|///
comment|/// When a pack expansion contains multiple parameter packs at different levels,
comment|/// this node is used to represent a function parameter pack at an outer level
comment|/// which we have already substituted to refer to expanded parameters, but where
comment|/// the containing pack expansion cannot yet be expanded.
comment|///
comment|/// \code
comment|/// template<typename...Ts> struct S {
comment|///   template<typename...Us> auto f(Ts ...ts) -> decltype(g(Us(ts)...));
comment|/// };
comment|/// template struct S<int, int>;
comment|/// \endcode
name|class
name|FunctionParmPackExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The function parameter pack which was referenced.
name|ParmVarDecl
operator|*
name|ParamPack
block|;
comment|/// \brief The location of the function parameter pack reference.
name|SourceLocation
name|NameLoc
block|;
comment|/// \brief The number of expansions of this pack.
name|unsigned
name|NumParameters
block|;
name|FunctionParmPackExpr
argument_list|(
argument|QualType T
argument_list|,
argument|ParmVarDecl *ParamPack
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|unsigned NumParams
argument_list|,
argument|Decl * const *Params
argument_list|)
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
specifier|static
name|FunctionParmPackExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|QualType T
argument_list|,
argument|ParmVarDecl *ParamPack
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|ArrayRef<Decl *> Params
argument_list|)
block|;
specifier|static
name|FunctionParmPackExpr
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|unsigned NumParams
argument_list|)
block|;
comment|/// \brief Get the parameter pack which this expression refers to.
name|ParmVarDecl
operator|*
name|getParameterPack
argument_list|()
specifier|const
block|{
return|return
name|ParamPack
return|;
block|}
comment|/// \brief Get the location of the parameter pack.
name|SourceLocation
name|getParameterPackLocation
argument_list|()
specifier|const
block|{
return|return
name|NameLoc
return|;
block|}
comment|/// \brief Iterators over the parameters which the parameter pack expanded
comment|/// into.
typedef|typedef
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|iterator
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|begin
argument_list|()
operator|+
name|NumParameters
return|;
block|}
comment|/// \brief Get the number of parameters in this parameter pack.
name|unsigned
name|getNumExpansions
argument_list|()
specifier|const
block|{
return|return
name|NumParameters
return|;
block|}
comment|/// \brief Get an expansion of the parameter pack by index.
name|ParmVarDecl
operator|*
name|getExpansion
argument_list|(
argument|unsigned I
argument_list|)
specifier|const
block|{
return|return
name|begin
argument_list|()
index|[
name|I
index|]
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|NameLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|FunctionParmPackExprClass
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
comment|/// \brief Represents a prvalue temporary that is written into memory so that
comment|/// a reference can bind to it.
comment|///
comment|/// Prvalue expressions are materialized when they need to have an address
comment|/// in memory for a reference to bind to. This happens when binding a
comment|/// reference to the result of a conversion, e.g.,
comment|///
comment|/// \code
comment|/// const int&r = 1.0;
comment|/// \endcode
comment|///
comment|/// Here, 1.0 is implicitly converted to an \c int. That resulting \c int is
comment|/// then materialized via a \c MaterializeTemporaryExpr, and the reference
comment|/// binds to the temporary. \c MaterializeTemporaryExprs are always glvalues
comment|/// (either an lvalue or an xvalue, depending on the kind of reference binding
comment|/// to it), maintaining the invariant that references always bind to glvalues.
comment|///
comment|/// Reference binding and copy-elision can both extend the lifetime of a
comment|/// temporary. When either happens, the expression will also track the
comment|/// declaration which is responsible for the lifetime extension.
name|class
name|MaterializeTemporaryExpr
operator|:
name|public
name|Expr
block|{
name|public
operator|:
comment|/// \brief The temporary-generating expression whose value will be
comment|/// materialized.
name|Stmt
operator|*
name|Temporary
block|;
comment|/// \brief The declaration which lifetime-extended this reference, if any.
comment|/// Either a VarDecl, or (for a ctor-initializer) a FieldDecl.
specifier|const
name|ValueDecl
operator|*
name|ExtendingDecl
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
name|MaterializeTemporaryExpr
argument_list|(
argument|QualType T
argument_list|,
argument|Expr *Temporary
argument_list|,
argument|bool BoundToLvalueReference
argument_list|,
argument|const ValueDecl *ExtendedBy
argument_list|)
operator|:
name|Expr
argument_list|(
name|MaterializeTemporaryExprClass
argument_list|,
name|T
argument_list|,
name|BoundToLvalueReference
condition|?
name|VK_LValue
else|:
name|VK_XValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|Temporary
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|Temporary
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|Temporary
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|Temporary
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Temporary
argument_list|(
name|Temporary
argument_list|)
block|,
name|ExtendingDecl
argument_list|(
argument|ExtendedBy
argument_list|)
block|{   }
name|MaterializeTemporaryExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|MaterializeTemporaryExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// \brief Retrieve the temporary-generating subexpression whose value will
comment|/// be materialized into a glvalue.
name|Expr
operator|*
name|GetTemporaryExpr
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
name|Temporary
operator|)
return|;
block|}
comment|/// \brief Retrieve the storage duration for the materialized temporary.
name|StorageDuration
name|getStorageDuration
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|ExtendingDecl
condition|)
return|return
name|SD_FullExpression
return|;
comment|// FIXME: This is not necessarily correct for a temporary materialized
comment|// within a default initializer.
if|if
condition|(
name|isa
operator|<
name|FieldDecl
operator|>
operator|(
name|ExtendingDecl
operator|)
condition|)
return|return
name|SD_Automatic
return|;
return|return
name|cast
operator|<
name|VarDecl
operator|>
operator|(
name|ExtendingDecl
operator|)
operator|->
name|getStorageDuration
argument_list|()
return|;
block|}
comment|/// \brief Get the declaration which triggered the lifetime-extension of this
comment|/// temporary, if any.
specifier|const
name|ValueDecl
operator|*
name|getExtendingDecl
argument_list|()
specifier|const
block|{
return|return
name|ExtendingDecl
return|;
block|}
name|void
name|setExtendingDecl
argument_list|(
argument|const ValueDecl *ExtendedBy
argument_list|)
block|{
name|ExtendingDecl
operator|=
name|ExtendedBy
block|;   }
comment|/// \brief Determine whether this materialized temporary is bound to an
comment|/// lvalue reference; otherwise, it's bound to an rvalue reference.
name|bool
name|isBoundToLvalueReference
argument_list|()
specifier|const
block|{
return|return
name|getValueKind
argument_list|()
operator|==
name|VK_LValue
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Temporary
operator|->
name|getLocStart
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
name|Temporary
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
name|MaterializeTemporaryExprClass
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
name|Temporary
argument_list|,
operator|&
name|Temporary
operator|+
literal|1
argument_list|)
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

