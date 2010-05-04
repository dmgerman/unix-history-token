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
name|args
argument_list|,
name|numargs
argument_list|,
name|t
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
name|virtual
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
argument|ASTContext& C
argument_list|,
argument|Expr *fn
argument_list|,
argument|Expr **args
argument_list|,
argument|unsigned numargs
argument_list|,
argument|QualType t
argument_list|,
argument|SourceLocation rparenloc
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
argument|args
argument_list|,
argument|numargs
argument_list|,
argument|t
argument_list|,
argument|rparenloc
argument_list|)
block|{}
comment|/// getImplicitObjectArgument - Retrieves the implicit object
comment|/// argument for the member call. For example, in "x.f(5)", this
comment|/// operation would return "x".
name|Expr
operator|*
name|getImplicitObjectArgument
argument_list|()
block|;
name|virtual
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
name|protected
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|QualType ty
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|CXXBaseSpecifierArray BasePath
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
name|SC
argument_list|,
name|ty
argument_list|,
name|kind
argument_list|,
name|op
argument_list|,
name|BasePath
argument_list|,
name|writtenTy
argument_list|)
block|,
name|Loc
argument_list|(
argument|l
argument_list|)
block|{}
name|explicit
name|CXXNamedCastExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|EmptyShell Shell
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
argument|SC
argument_list|,
argument|Shell
argument_list|)
block|{ }
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
name|void
name|setOperatorLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|Loc
operator|=
name|L
block|; }
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
name|public
operator|:
name|CXXStaticCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|CXXBaseSpecifierArray BasePath
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXStaticCastExprClass
argument_list|,
argument|ty
argument_list|,
argument|kind
argument_list|,
argument|op
argument_list|,
argument|BasePath
argument_list|,
argument|writtenTy
argument_list|,
argument|l
argument_list|)
block|{}
name|explicit
name|CXXStaticCastExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXStaticCastExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
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
name|public
operator|:
name|CXXDynamicCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|CXXBaseSpecifierArray BasePath
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXDynamicCastExprClass
argument_list|,
argument|ty
argument_list|,
argument|kind
argument_list|,
argument|op
argument_list|,
argument|BasePath
argument_list|,
argument|writtenTy
argument_list|,
argument|l
argument_list|)
block|{}
name|explicit
name|CXXDynamicCastExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXDynamicCastExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
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
name|public
operator|:
name|CXXReinterpretCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|CXXBaseSpecifierArray BasePath
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXReinterpretCastExprClass
argument_list|,
argument|ty
argument_list|,
argument|kind
argument_list|,
argument|op
argument_list|,
argument|BasePath
argument_list|,
argument|writtenTy
argument_list|,
argument|l
argument_list|)
block|{}
name|explicit
name|CXXReinterpretCastExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXReinterpretCastExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
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
name|public
operator|:
name|CXXConstCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|Expr *op
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|CXXNamedCastExpr
argument_list|(
argument|CXXConstCastExprClass
argument_list|,
argument|ty
argument_list|,
argument|CK_NoOp
argument_list|,
argument|op
argument_list|,
argument|CXXBaseSpecifierArray()
argument_list|,
argument|writtenTy
argument_list|,
argument|l
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
argument_list|)
block|{ }
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
name|virtual
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
name|false
argument_list|,
name|false
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
name|virtual
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
name|protected
operator|:
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
name|protected
operator|:
name|virtual
name|void
name|DoDestroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|public
operator|:
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
name|virtual
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
operator|~
name|CXXTemporary
argument_list|()
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
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|Ctx
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
comment|/// CXXBindTemporaryExpr - Represents binding an expression to a temporary,
comment|/// so its destructor can be called later.
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
name|subexpr
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXBindTemporaryExprClass
argument_list|,
name|subexpr
operator|->
name|getType
argument_list|()
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Temp
argument_list|(
name|temp
argument_list|)
block|,
name|SubExpr
argument_list|(
argument|subexpr
argument_list|)
block|{ }
operator|~
name|CXXBindTemporaryExpr
argument_list|()
block|{ }
name|protected
operator|:
name|virtual
name|void
name|DoDestroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|public
operator|:
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
name|virtual
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
block|;
comment|/// CXXBindReferenceExpr - Represents binding an expression to a reference.
comment|/// In the example:
comment|///
comment|/// const int&i = 10;
comment|///
comment|/// a bind reference expression is inserted to indicate that 10 is bound to
comment|/// a reference. (Ans also that a temporary needs to be created to hold the
comment|/// value).
name|class
name|CXXBindReferenceExpr
operator|:
name|public
name|Expr
block|{
comment|// SubExpr - The expression being bound.
name|Stmt
operator|*
name|SubExpr
block|;
comment|// ExtendsLifetime - Whether binding this reference extends the lifetime of
comment|// the expression being bound. FIXME: Add C++ reference.
name|bool
name|ExtendsLifetime
block|;
comment|/// RequiresTemporaryCopy - Whether binding the subexpression requires a
comment|/// temporary copy.
name|bool
name|RequiresTemporaryCopy
block|;
name|CXXBindReferenceExpr
argument_list|(
argument|Expr *subexpr
argument_list|,
argument|bool ExtendsLifetime
argument_list|,
argument|bool RequiresTemporaryCopy
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXBindReferenceExprClass
argument_list|,
name|subexpr
operator|->
name|getType
argument_list|()
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|SubExpr
argument_list|(
name|subexpr
argument_list|)
block|,
name|ExtendsLifetime
argument_list|(
name|ExtendsLifetime
argument_list|)
block|,
name|RequiresTemporaryCopy
argument_list|(
argument|RequiresTemporaryCopy
argument_list|)
block|{ }
operator|~
name|CXXBindReferenceExpr
argument_list|()
block|{ }
name|protected
operator|:
name|virtual
name|void
name|DoDestroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|public
operator|:
specifier|static
name|CXXBindReferenceExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr *SubExpr
argument_list|,
argument|bool ExtendsLifetime
argument_list|,
argument|bool RequiresTemporaryCopy
argument_list|)
block|;
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
name|virtual
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
comment|/// requiresTemporaryCopy - Whether binding the subexpression requires a
comment|/// temporary copy.
name|bool
name|requiresTemporaryCopy
argument_list|()
specifier|const
block|{
return|return
name|RequiresTemporaryCopy
return|;
block|}
comment|// extendsLifetime - Whether binding this reference extends the lifetime of
comment|// the expression being bound. FIXME: Add C++ reference.
name|bool
name|extendsLifetime
argument_list|()
block|{
return|return
name|ExtendsLifetime
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
name|CXXBindReferenceExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXBindReferenceExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
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
argument_list|)
block|;
operator|~
name|CXXConstructExpr
argument_list|()
block|{ }
name|virtual
name|void
name|DoDestroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|public
operator|:
comment|/// \brief Construct an empty C++ construction expression that will store
comment|/// \p numargs arguments.
name|CXXConstructExpr
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|ASTContext&C
argument_list|,
argument|unsigned numargs
argument_list|)
block|;
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
name|virtual
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
name|public
operator|:
name|CXXFunctionalCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|,
argument|SourceLocation tyBeginLoc
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *castExpr
argument_list|,
argument|CXXBaseSpecifierArray BasePath
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
name|kind
argument_list|,
name|castExpr
argument_list|,
name|BasePath
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
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
argument|CXXFunctionalCastExprClass
argument_list|,
argument|Shell
argument_list|)
block|{ }
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
name|virtual
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
comment|/// constructor to build a temporary object. If N == 0 but no
comment|/// constructor will be called (because the functional cast is
comment|/// performing a value-initialized an object whose class type has no
comment|/// user-declared constructors), CXXZeroInitValueExpr will represent
comment|/// the functional cast. Finally, with N == 1 arguments the functional
comment|/// cast expression will be represented by CXXFunctionalCastExpr.
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
name|SourceLocation
name|TyBeginLoc
block|;
name|SourceLocation
name|RParenLoc
block|;
name|public
operator|:
name|CXXTemporaryObjectExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXConstructorDecl *Cons
argument_list|,
argument|QualType writtenTy
argument_list|,
argument|SourceLocation tyBeginLoc
argument_list|,
argument|Expr **Args
argument_list|,
argument|unsigned NumArgs
argument_list|,
argument|SourceLocation rParenLoc
argument_list|,
argument|bool ZeroInitialization = false
argument_list|)
block|;
operator|~
name|CXXTemporaryObjectExpr
argument_list|()
block|{ }
name|SourceLocation
name|getTypeBeginLoc
argument_list|()
specifier|const
block|{
return|return
name|TyBeginLoc
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
name|virtual
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
expr|}
block|;
comment|/// CXXZeroInitValueExpr - [C++ 5.2.3p2]
comment|/// Expression "T()" which creates a value-initialized rvalue of type
comment|/// T, which is either a non-class type or a class type without any
comment|/// user-defined constructors.
comment|///
name|class
name|CXXZeroInitValueExpr
operator|:
name|public
name|Expr
block|{
name|SourceLocation
name|TyBeginLoc
block|;
name|SourceLocation
name|RParenLoc
block|;
name|public
operator|:
name|CXXZeroInitValueExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|SourceLocation tyBeginLoc
argument_list|,
argument|SourceLocation rParenLoc
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXZeroInitValueExprClass
argument_list|,
name|ty
argument_list|,
name|false
argument_list|,
name|false
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
name|SourceLocation
name|getTypeBeginLoc
argument_list|()
specifier|const
block|{
return|return
name|TyBeginLoc
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
comment|/// @brief Whether this initialization expression was
comment|/// implicitly-generated.
name|bool
name|isImplicit
argument_list|()
specifier|const
block|{
return|return
name|TyBeginLoc
operator|.
name|isInvalid
argument_list|()
operator|&&
name|RParenLoc
operator|.
name|isInvalid
argument_list|()
return|;
block|}
name|virtual
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
name|CXXZeroInitValueExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXZeroInitValueExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
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
comment|// Was the form (type-id) used? Otherwise, it was new-type-id.
name|bool
name|ParenTypeId
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
name|SourceLocation
name|StartLoc
block|;
name|SourceLocation
name|EndLoc
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
argument|bool ParenTypeId
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
argument|QualType ty
argument_list|,
argument|SourceLocation startLoc
argument_list|,
argument|SourceLocation endLoc
argument_list|)
block|;
name|virtual
name|void
name|DoDestroy
argument_list|(
name|ASTContext
operator|&
name|C
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
name|isGlobalNew
argument_list|()
specifier|const
block|{
return|return
name|GlobalNew
return|;
block|}
name|bool
name|isParenTypeId
argument_list|()
specifier|const
block|{
return|return
name|ParenTypeId
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
name|virtual
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
name|false
argument_list|,
name|false
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
name|NestedNameSpecifier
operator|*
name|Qualifier
block|;
comment|/// \brief The source range that covers the nested-name-specifier, if
comment|/// present.
name|SourceRange
name|QualifierRange
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
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|TypeSourceInfo *ScopeType
argument_list|,
argument|SourceLocation ColonColonLoc
argument_list|,
argument|SourceLocation TildeLoc
argument_list|,
argument|PseudoDestructorTypeStorage DestroyedType
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXPseudoDestructorExprClass
argument_list|,
name|Context
operator|.
name|getPointerType
argument_list|(
name|Context
operator|.
name|getFunctionType
argument_list|(
name|Context
operator|.
name|VoidTy
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|false
argument_list|,
literal|0
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|FunctionType
operator|::
name|ExtInfo
argument_list|()
argument_list|)
argument_list|)
argument_list|,
comment|/*isTypeDependent=*/
operator|(
name|Base
operator|->
name|isTypeDependent
argument_list|()
operator|||
operator|(
name|DestroyedType
operator|.
name|getTypeSourceInfo
argument_list|()
operator|&&
name|DestroyedType
operator|.
name|getTypeSourceInfo
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
operator|)
operator|)
argument_list|,
comment|/*isValueDependent=*/
name|Base
operator|->
name|isValueDependent
argument_list|()
argument_list|)
block|,
name|Base
argument_list|(
name|static_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
name|Base
operator|)
argument_list|)
block|,
name|IsArrow
argument_list|(
name|isArrow
argument_list|)
block|,
name|OperatorLoc
argument_list|(
name|OperatorLoc
argument_list|)
block|,
name|Qualifier
argument_list|(
name|Qualifier
argument_list|)
block|,
name|QualifierRange
argument_list|(
name|QualifierRange
argument_list|)
block|,
name|ScopeType
argument_list|(
name|ScopeType
argument_list|)
block|,
name|ColonColonLoc
argument_list|(
name|ColonColonLoc
argument_list|)
block|,
name|TildeLoc
argument_list|(
name|TildeLoc
argument_list|)
block|,
name|DestroyedType
argument_list|(
argument|DestroyedType
argument_list|)
block|{ }
name|void
name|setBase
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Base
operator|=
name|E
block|; }
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
name|Qualifier
operator|!=
literal|0
return|;
block|}
comment|/// \brief If the member name was qualified, retrieves the source range of
comment|/// the nested-name-specifier that precedes the member name. Otherwise,
comment|/// returns an empty source range.
name|SourceRange
name|getQualifierRange
argument_list|()
specifier|const
block|{
return|return
name|QualifierRange
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
name|Qualifier
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
name|void
name|setArrow
argument_list|(
argument|bool A
argument_list|)
block|{
name|IsArrow
operator|=
name|A
block|; }
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
name|virtual
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
comment|/// UTT - The trait.
name|UnaryTypeTrait
name|UTT
block|;
comment|/// Loc - The location of the type trait keyword.
name|SourceLocation
name|Loc
block|;
comment|/// RParen - The location of the closing paren.
name|SourceLocation
name|RParen
block|;
comment|/// QueriedType - The type we're testing.
name|QualType
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
argument|QualType queried
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
name|false
argument_list|,
name|queried
operator|->
name|isDependentType
argument_list|()
argument_list|)
block|,
name|UTT
argument_list|(
name|utt
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
name|UnaryTypeTrait
name|getTrait
argument_list|()
specifier|const
block|{
return|return
name|UTT
return|;
block|}
name|QualType
name|getQueriedType
argument_list|()
specifier|const
block|{
return|return
name|QueriedType
return|;
block|}
name|bool
name|EvaluateTrait
argument_list|(
argument|ASTContext&
argument_list|)
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
name|UnresolvedSet
operator|<
literal|4
operator|>
name|Results
block|;
comment|/// The common name of these declarations.
name|DeclarationName
name|Name
block|;
comment|/// The scope specifier, if any.
name|NestedNameSpecifier
operator|*
name|Qualifier
block|;
comment|/// The source range of the scope specifier.
name|SourceRange
name|QualifierRange
block|;
comment|/// The location of the name.
name|SourceLocation
name|NameLoc
block|;
comment|/// True if the name was a template-id.
name|bool
name|HasExplicitTemplateArgs
block|;
name|protected
operator|:
name|OverloadExpr
argument_list|(
argument|StmtClass K
argument_list|,
argument|QualType T
argument_list|,
argument|bool Dependent
argument_list|,
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QRange
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|bool HasTemplateArgs
argument_list|)
operator|:
name|Expr
argument_list|(
name|K
argument_list|,
name|T
argument_list|,
name|Dependent
argument_list|,
name|Dependent
argument_list|)
block|,
name|Name
argument_list|(
name|Name
argument_list|)
block|,
name|Qualifier
argument_list|(
name|Qualifier
argument_list|)
block|,
name|QualifierRange
argument_list|(
name|QRange
argument_list|)
block|,
name|NameLoc
argument_list|(
name|NameLoc
argument_list|)
block|,
name|HasExplicitTemplateArgs
argument_list|(
argument|HasTemplateArgs
argument_list|)
block|{}
name|public
operator|:
comment|/// Computes whether an unresolved lookup on the given declarations
comment|/// and optional template arguments is type- and value-dependent.
specifier|static
name|bool
name|ComputeDependence
argument_list|(
argument|UnresolvedSetIterator Begin
argument_list|,
argument|UnresolvedSetIterator End
argument_list|,
argument|const TemplateArgumentListInfo *Args
argument_list|)
block|;
comment|/// Finds the overloaded expression in the given expression of
comment|/// OverloadTy.
comment|///
comment|/// \return the expression (which must be there) and true if it is
comment|/// within an address-of operator.
specifier|static
name|llvm
operator|::
name|PointerIntPair
operator|<
name|OverloadExpr
operator|*
block|,
literal|1
operator|>
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
name|bool
name|op
operator|=
name|false
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
name|op
operator|=
name|true
operator|,
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
operator|->
name|IgnoreParens
argument_list|()
expr_stmt|;
return|return
name|llvm
operator|::
name|PointerIntPair
operator|<
name|OverloadExpr
operator|*
operator|,
literal|1
operator|>
operator|(
name|cast
operator|<
name|OverloadExpr
operator|>
operator|(
name|E
operator|)
expr|,
name|op
operator|)
return|;
block|}
name|void
name|addDecls
argument_list|(
argument|UnresolvedSetIterator Begin
argument_list|,
argument|UnresolvedSetIterator End
argument_list|)
block|{
name|Results
operator|.
name|append
argument_list|(
name|Begin
argument_list|,
name|End
argument_list|)
block|;   }
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
name|Results
operator|.
name|begin
argument_list|()
return|;
block|}
name|decls_iterator
name|decls_end
argument_list|()
specifier|const
block|{
return|return
name|Results
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Gets the decls as an unresolved set.
specifier|const
name|UnresolvedSetImpl
operator|&
name|getDecls
argument_list|()
block|{
return|return
name|Results
return|;
block|}
comment|/// Gets the number of declarations in the unresolved set.
name|unsigned
name|getNumDecls
argument_list|()
specifier|const
block|{
return|return
name|Results
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Gets the name looked up.
name|DeclarationName
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|void
name|setName
argument_list|(
argument|DeclarationName N
argument_list|)
block|{
name|Name
operator|=
name|N
block|; }
comment|/// Gets the location of the name.
name|SourceLocation
name|getNameLoc
argument_list|()
specifier|const
block|{
return|return
name|NameLoc
return|;
block|}
name|void
name|setNameLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|NameLoc
operator|=
name|Loc
block|; }
comment|/// Fetches the nested-name qualifier, if one was given.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|Qualifier
return|;
block|}
comment|/// Fetches the range of the nested-name qualifier.
name|SourceRange
name|getQualifierRange
argument_list|()
specifier|const
block|{
return|return
name|QualifierRange
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
name|ExplicitTemplateArgumentList
operator|*
name|getOptionalExplicitTemplateArgs
argument_list|()
block|{
if|if
condition|(
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
operator|&
name|getExplicitTemplateArgs
argument_list|()
return|;
return|return
literal|0
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
expr|}
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
argument|QualType T
argument_list|,
argument|bool Dependent
argument_list|,
argument|CXXRecordDecl *NamingClass
argument_list|,
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QRange
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|bool RequiresADL
argument_list|,
argument|bool Overloaded
argument_list|,
argument|bool HasTemplateArgs
argument_list|)
operator|:
name|OverloadExpr
argument_list|(
name|UnresolvedLookupExprClass
argument_list|,
name|T
argument_list|,
name|Dependent
argument_list|,
name|Qualifier
argument_list|,
name|QRange
argument_list|,
name|Name
argument_list|,
name|NameLoc
argument_list|,
name|HasTemplateArgs
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
name|public
operator|:
specifier|static
name|UnresolvedLookupExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|bool Dependent
argument_list|,
argument|CXXRecordDecl *NamingClass
argument_list|,
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|bool ADL
argument_list|,
argument|bool Overloaded
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|C
argument_list|)
name|UnresolvedLookupExpr
argument_list|(
name|Dependent
operator|?
name|C
operator|.
name|DependentTy
operator|:
name|C
operator|.
name|OverloadTy
argument_list|,
name|Dependent
argument_list|,
name|NamingClass
argument_list|,
name|Qualifier
argument_list|,
name|QualifierRange
argument_list|,
name|Name
argument_list|,
name|NameLoc
argument_list|,
name|ADL
argument_list|,
name|Overloaded
argument_list|,
name|false
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
argument|bool Dependent
argument_list|,
argument|CXXRecordDecl *NamingClass
argument_list|,
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|bool ADL
argument_list|,
argument|const TemplateArgumentListInfo&Args
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
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
name|SourceRange
name|Range
argument_list|(
name|getNameLoc
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|getQualifier
argument_list|()
condition|)
name|Range
operator|.
name|setBegin
argument_list|(
name|getQualifierRange
argument_list|()
operator|.
name|getBegin
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
name|virtual
name|StmtIterator
name|child_begin
argument_list|()
block|;
name|virtual
name|StmtIterator
name|child_end
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
comment|/// The name of the entity we will be referencing.
name|DeclarationName
name|Name
block|;
comment|/// Location of the name of the declaration we're referencing.
name|SourceLocation
name|Loc
block|;
comment|/// QualifierRange - The source range that covers the
comment|/// nested-name-specifier.
name|SourceRange
name|QualifierRange
block|;
comment|/// \brief The nested-name-specifier that qualifies this unresolved
comment|/// declaration name.
name|NestedNameSpecifier
operator|*
name|Qualifier
block|;
comment|/// \brief Whether the name includes explicit template arguments.
name|bool
name|HasExplicitTemplateArgs
block|;
name|DependentScopeDeclRefExpr
argument_list|(
argument|QualType T
argument_list|,
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|bool HasExplicitTemplateArgs
argument_list|)
operator|:
name|Expr
argument_list|(
name|DependentScopeDeclRefExprClass
argument_list|,
name|T
argument_list|,
name|true
argument_list|,
name|true
argument_list|)
block|,
name|Name
argument_list|(
name|Name
argument_list|)
block|,
name|Loc
argument_list|(
name|NameLoc
argument_list|)
block|,
name|QualifierRange
argument_list|(
name|QualifierRange
argument_list|)
block|,
name|Qualifier
argument_list|(
name|Qualifier
argument_list|)
block|,
name|HasExplicitTemplateArgs
argument_list|(
argument|HasExplicitTemplateArgs
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|DependentScopeDeclRefExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs =
literal|0
argument_list|)
block|;
comment|/// \brief Retrieve the name that this expression refers to.
name|DeclarationName
name|getDeclName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// \brief Retrieve the location of the name within the expression.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
comment|/// \brief Retrieve the source range of the nested-name-specifier.
name|SourceRange
name|getQualifierRange
argument_list|()
specifier|const
block|{
return|return
name|QualifierRange
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
name|Qualifier
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
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
name|SourceRange
name|Range
argument_list|(
name|QualifierRange
operator|.
name|getBegin
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
name|virtual
name|StmtIterator
name|child_begin
argument_list|()
block|;
name|virtual
name|StmtIterator
name|child_end
argument_list|()
block|; }
decl_stmt|;
name|class
name|CXXExprWithTemporaries
range|:
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
name|CXXExprWithTemporaries
argument_list|(
argument|Expr *SubExpr
argument_list|,
argument|CXXTemporary **Temps
argument_list|,
argument|unsigned NumTemps
argument_list|)
block|;
operator|~
name|CXXExprWithTemporaries
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|void
name|DoDestroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|public
operator|:
specifier|static
name|CXXExprWithTemporaries
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
name|CXXExprWithTemporaries
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
name|virtual
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
name|CXXExprWithTemporariesClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXExprWithTemporaries *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
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
range|:
name|public
name|Expr
block|{
comment|/// \brief The starting location of the type
name|SourceLocation
name|TyBeginLoc
block|;
comment|/// \brief The type being constructed.
name|QualType
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
argument|SourceLocation TyBegin
argument_list|,
argument|QualType T
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
name|public
operator|:
specifier|static
name|CXXUnresolvedConstructExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|SourceLocation TyBegin
argument_list|,
argument|QualType T
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
comment|/// \brief Retrieve the source location where the type begins.
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
comment|/// \brief Retrieve the type that is being constructed, as specified
comment|/// in the source code.
name|QualType
name|getTypeAsWritten
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
name|void
name|setTypeAsWritten
argument_list|(
argument|QualType T
argument_list|)
block|{
name|Type
operator|=
name|T
block|; }
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
name|virtual
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
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|CXXUnresolvedConstructExpr
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|virtual
name|child_iterator
name|child_begin
parameter_list|()
function_decl|;
name|virtual
name|child_iterator
name|child_end
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
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
name|NestedNameSpecifier
operator|*
name|Qualifier
block|;
comment|/// \brief The source range covering the nested name specifier.
name|SourceRange
name|QualifierRange
block|;
comment|/// \brief In a qualified member access expression such as t->Base::f, this
comment|/// member stores the resolves of name lookup in the context of the member
comment|/// access expression, to be used at instantiation time.
comment|///
comment|/// FIXME: This member, along with the Qualifier and QualifierRange, could
comment|/// be stuck into a structure that is optionally allocated at the end of
comment|/// the CXXDependentScopeMemberExpr, to save space in the common case.
name|NamedDecl
operator|*
name|FirstQualifierFoundInScope
block|;
comment|/// \brief The member to which this member expression refers, which
comment|/// can be name, overloaded operator, or destructor.
comment|/// FIXME: could also be a template-id
name|DeclarationName
name|Member
block|;
comment|/// \brief The location of the member name.
name|SourceLocation
name|MemberLoc
block|;
comment|/// \brief Retrieve the explicit template argument list that followed the
comment|/// member template name, if any.
name|ExplicitTemplateArgumentList
operator|*
name|getExplicitTemplateArgumentList
argument_list|()
block|{
name|assert
argument_list|(
name|HasExplicitTemplateArgs
argument_list|)
block|;
return|return
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
operator|*
name|getExplicitTemplateArgumentList
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
name|getExplicitTemplateArgumentList
argument_list|()
return|;
block|}
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
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|NamedDecl *FirstQualifierFoundInScope
argument_list|,
argument|DeclarationName Member
argument_list|,
argument|SourceLocation MemberLoc
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
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|NamedDecl *FirstQualifierFoundInScope
argument_list|,
argument|DeclarationName Member
argument_list|,
argument|SourceLocation MemberLoc
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXDependentScopeMemberExprClass
argument_list|,
name|C
operator|.
name|DependentTy
argument_list|,
name|true
argument_list|,
name|true
argument_list|)
block|,
name|Base
argument_list|(
name|Base
argument_list|)
block|,
name|BaseType
argument_list|(
name|BaseType
argument_list|)
block|,
name|IsArrow
argument_list|(
name|IsArrow
argument_list|)
block|,
name|HasExplicitTemplateArgs
argument_list|(
name|false
argument_list|)
block|,
name|OperatorLoc
argument_list|(
name|OperatorLoc
argument_list|)
block|,
name|Qualifier
argument_list|(
name|Qualifier
argument_list|)
block|,
name|QualifierRange
argument_list|(
name|QualifierRange
argument_list|)
block|,
name|FirstQualifierFoundInScope
argument_list|(
name|FirstQualifierFoundInScope
argument_list|)
block|,
name|Member
argument_list|(
name|Member
argument_list|)
block|,
name|MemberLoc
argument_list|(
argument|MemberLoc
argument_list|)
block|{ }
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
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|NamedDecl *FirstQualifierFoundInScope
argument_list|,
argument|DeclarationName Member
argument_list|,
argument|SourceLocation MemberLoc
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|)
block|;
comment|/// \brief True if this is an implicit access, i.e. one in which the
comment|/// member being accessed was not written in the source.  The source
comment|/// location of the operator is invalid in this case.
name|bool
name|isImplicitAccess
argument_list|()
specifier|const
block|{
return|return
name|Base
operator|==
literal|0
return|;
block|}
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
name|void
name|setBase
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Base
operator|=
name|E
block|; }
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
name|void
name|setArrow
argument_list|(
argument|bool A
argument_list|)
block|{
name|IsArrow
operator|=
name|A
block|; }
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
name|void
name|setOperatorLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|OperatorLoc
operator|=
name|L
block|; }
comment|/// \brief Retrieve the nested-name-specifier that qualifies the member
comment|/// name.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|Qualifier
return|;
block|}
comment|/// \brief Retrieve the source range covering the nested-name-specifier
comment|/// that qualifies the member name.
name|SourceRange
name|getQualifierRange
argument_list|()
specifier|const
block|{
return|return
name|QualifierRange
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
name|DeclarationName
name|getMember
argument_list|()
specifier|const
block|{
return|return
name|Member
return|;
block|}
name|void
name|setMember
argument_list|(
argument|DeclarationName N
argument_list|)
block|{
name|Member
operator|=
name|N
block|; }
comment|// \brief Retrieve the location of the name of the member that this
comment|// expression refers to.
name|SourceLocation
name|getMemberLoc
argument_list|()
specifier|const
block|{
return|return
name|MemberLoc
return|;
block|}
name|void
name|setMemberLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|MemberLoc
operator|=
name|L
block|; }
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
comment|/// \brief Copies the template arguments (if present) into the given
comment|/// structure.
name|void
name|copyTemplateArgumentsInto
argument_list|(
argument|TemplateArgumentListInfo&List
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|HasExplicitTemplateArgs
argument_list|)
block|;
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|copyInto
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
name|assert
argument_list|(
name|HasExplicitTemplateArgs
argument_list|)
block|;
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
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
name|assert
argument_list|(
name|HasExplicitTemplateArgs
argument_list|)
block|;
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
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
name|assert
argument_list|(
name|HasExplicitTemplateArgs
argument_list|)
block|;
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
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
name|assert
argument_list|(
name|HasExplicitTemplateArgs
argument_list|)
block|;
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|RAngleLoc
return|;
block|}
name|virtual
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
name|getQualifierRange
argument_list|()
operator|.
name|getBegin
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|Range
operator|.
name|setBegin
argument_list|(
name|MemberLoc
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
name|MemberLoc
argument_list|)
expr_stmt|;
end_decl_stmt

begin_return
return|return
name|Range
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

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|CXXDependentScopeMemberExpr
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

begin_function_decl
name|virtual
name|child_iterator
name|child_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|child_iterator
name|child_end
parameter_list|()
function_decl|;
end_function_decl

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
argument|QualType T
argument_list|,
argument|bool Dependent
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
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|DeclarationName Member
argument_list|,
argument|SourceLocation MemberLoc
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|)
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
argument|bool Dependent
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
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|DeclarationName Member
argument_list|,
argument|SourceLocation MemberLoc
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|)
block|;
comment|/// \brief True if this is an implicit access, i.e. one in which the
comment|/// member being accessed was not written in the source.  The source
comment|/// location of the operator is invalid in this case.
name|bool
name|isImplicitAccess
argument_list|()
specifier|const
block|{
return|return
name|Base
operator|==
literal|0
return|;
block|}
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
name|void
name|setBase
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Base
operator|=
name|E
block|; }
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
name|void
name|setArrow
argument_list|(
argument|bool A
argument_list|)
block|{
name|IsArrow
operator|=
name|A
block|; }
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
name|void
name|setOperatorLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|OperatorLoc
operator|=
name|L
block|; }
comment|/// \brief Retrieves the naming class of this lookup.
name|CXXRecordDecl
operator|*
name|getNamingClass
argument_list|()
specifier|const
block|;
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
name|void
name|setMemberName
argument_list|(
argument|DeclarationName N
argument_list|)
block|{
name|setName
argument_list|(
name|N
argument_list|)
block|; }
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
name|void
name|setMemberLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|setNameLoc
argument_list|(
name|L
argument_list|)
block|; }
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
name|virtual
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
name|getQualifierRange
argument_list|()
operator|.
name|getBegin
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|Range
operator|.
name|setBegin
argument_list|(
name|getMemberLoc
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
name|getMemberLoc
argument_list|()
argument_list|)
expr_stmt|;
end_decl_stmt

begin_return
return|return
name|Range
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

begin_function_decl
name|virtual
name|child_iterator
name|child_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|child_iterator
name|child_end
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
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
end_expr_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

