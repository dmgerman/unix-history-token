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
file|"clang/AST/Decl.h"
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
name|CXXTemporary
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
argument|Expr *op
argument_list|,
argument|QualType writtenTy
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
name|op
argument_list|,
name|writtenTy
argument_list|)
block|,
name|Loc
argument_list|(
argument|l
argument_list|)
block|{}
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
name|CXXNamedCastExprClass
case|:
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
argument|Expr *op
argument_list|,
argument|QualType writtenTy
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
argument|op
argument_list|,
argument|writtenTy
argument_list|,
argument|l
argument_list|)
block|{}
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
argument|Expr *op
argument_list|,
argument|QualType writtenTy
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
argument|op
argument_list|,
argument|writtenTy
argument_list|,
argument|l
argument_list|)
block|{}
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
argument|Expr *op
argument_list|,
argument|QualType writtenTy
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
argument|op
argument_list|,
argument|writtenTy
argument_list|,
argument|l
argument_list|)
block|{}
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
argument|QualType writtenTy
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
argument|op
argument_list|,
argument|writtenTy
argument_list|,
argument|l
argument_list|)
block|{}
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
name|CXXBoolLiteralExpr
operator|*
name|Clone
argument_list|(
argument|ASTContext&C
argument_list|)
specifier|const
block|;
name|bool
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
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
argument_list|)
block|,
name|Loc
argument_list|(
argument|l
argument_list|)
block|{}
name|CXXNullPtrLiteralExpr
operator|*
name|Clone
argument_list|(
argument|ASTContext&C
argument_list|)
specifier|const
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
name|Loc
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
name|bool
name|isTypeOp
operator|:
literal|1
block|;
expr|union
block|{
name|void
operator|*
name|Ty
block|;
name|Stmt
operator|*
name|Ex
block|;   }
name|Operand
block|;
name|SourceRange
name|Range
block|;
name|public
operator|:
name|CXXTypeidExpr
argument_list|(
argument|bool isTypeOp
argument_list|,
argument|void *op
argument_list|,
argument|QualType Ty
argument_list|,
argument|const SourceRange r
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
operator|(
name|isTypeOp
condition|?
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|op
argument_list|)
operator|->
name|isDependentType
argument_list|()
else|:
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|op
operator|)
operator|->
name|isValueDependent
argument_list|()
operator|)
argument_list|)
block|,
name|isTypeOp
argument_list|(
name|isTypeOp
argument_list|)
block|,
name|Range
argument_list|(
argument|r
argument_list|)
block|{
if|if
condition|(
name|isTypeOp
condition|)
name|Operand
operator|.
name|Ty
operator|=
name|op
expr_stmt|;
else|else
comment|// op was an Expr*, so cast it back to that to be safe
name|Operand
operator|.
name|Ex
operator|=
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|op
operator|)
expr_stmt|;
block|}
name|bool
name|isTypeOperand
argument_list|()
specifier|const
block|{
return|return
name|isTypeOp
return|;
block|}
name|QualType
name|getTypeOperand
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
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|Operand
operator|.
name|Ty
argument_list|)
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
name|Ex
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
name|public
operator|:
name|CXXThisExpr
argument_list|(
argument|SourceLocation L
argument_list|,
argument|QualType Type
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
argument|L
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
name|ParmVarDecl
operator|*
name|Param
block|;
name|public
operator|:
comment|// Param is the parameter whose default argument is used by this
comment|// expression.
name|explicit
name|CXXDefaultArgExpr
argument_list|(
name|ParmVarDecl
operator|*
name|param
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXDefaultArgExprClass
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
argument_list|)
block|,
name|Param
argument_list|(
argument|param
argument_list|)
block|{ }
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
return|;
block|}
name|ParmVarDecl
operator|*
name|getParam
argument_list|()
block|{
return|return
name|Param
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
return|return
name|Param
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
return|return
name|Param
operator|->
name|getDefaultArg
argument_list|()
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
name|C
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
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
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
name|SourceRange
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
comment|/// CXXConstructExpr - Represents a call to a C++ constructor.
name|class
name|CXXConstructExpr
operator|:
name|public
name|Expr
block|{
name|CXXConstructorDecl
operator|*
name|Constructor
block|;
name|bool
name|Elidable
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
argument|CXXConstructorDecl *d
argument_list|,
argument|bool elidable
argument_list|,
argument|Expr **args
argument_list|,
argument|unsigned numargs
argument_list|)
block|;
operator|~
name|CXXConstructExpr
argument_list|()
block|{ }
name|public
operator|:
specifier|static
name|CXXConstructExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|QualType T
argument_list|,
argument|CXXConstructorDecl *D
argument_list|,
argument|bool Elidable
argument_list|,
argument|Expr **Args
argument_list|,
argument|unsigned NumArgs
argument_list|)
block|;
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
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
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|NumArgs
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
argument|QualType writtenTy
argument_list|,
argument|SourceLocation tyBeginLoc
argument_list|,
argument|Expr *castExpr
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
name|castExpr
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
name|CXXZeroInitValueExpr
operator|*
name|Clone
argument_list|(
argument|ASTContext&C
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
comment|/// CXXConditionDeclExpr - Condition declaration of a if/switch/while/for
comment|/// statement, e.g: "if (int x = f()) {...}".
comment|/// The main difference with DeclRefExpr is that CXXConditionDeclExpr owns the
comment|/// decl that it references.
comment|///
name|class
name|CXXConditionDeclExpr
operator|:
name|public
name|DeclRefExpr
block|{
name|public
operator|:
name|CXXConditionDeclExpr
argument_list|(
argument|SourceLocation startLoc
argument_list|,
argument|SourceLocation eqLoc
argument_list|,
argument|VarDecl *var
argument_list|)
operator|:
name|DeclRefExpr
argument_list|(
argument|CXXConditionDeclExprClass
argument_list|,
argument|var
argument_list|,
argument|var->getType().getNonReferenceType()
argument_list|,
argument|startLoc
argument_list|,
argument|var->getType()->isDependentType()
argument_list|,
comment|/*FIXME:integral constant?*/
argument|var->getType()->isDependentType()
argument_list|)
block|{}
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
block|;
name|SourceLocation
name|getStartLoc
argument_list|()
specifier|const
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
name|VarDecl
operator|*
name|getVarDecl
argument_list|()
block|{
return|return
name|cast
operator|<
name|VarDecl
operator|>
operator|(
name|getDecl
argument_list|()
operator|)
return|;
block|}
specifier|const
name|VarDecl
operator|*
name|getVarDecl
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|VarDecl
operator|>
operator|(
name|getDecl
argument_list|()
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
name|getStartLoc
argument_list|()
argument_list|,
name|getVarDecl
argument_list|()
operator|->
name|getInit
argument_list|()
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
name|CXXConditionDeclExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXConditionDeclExpr *
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
operator|~
name|CXXNewExpr
argument_list|()
block|{
name|delete
index|[]
name|SubExprs
block|;   }
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
name|getAsPointerType
argument_list|()
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
comment|/// \brief Represents the name of a function that has not been
comment|/// resolved to any declaration.
comment|///
comment|/// Unresolved function names occur when a function name is
comment|/// encountered prior to an open parentheses ('(') in a C++ function
comment|/// call, and the function name itself did not resolve to a
comment|/// declaration. These function names can only be resolved when they
comment|/// form the postfix-expression of a function call, so that
comment|/// argument-dependent lookup finds declarations corresponding to
comment|/// these functions.
comment|/// @code
comment|/// template<typename T> void f(T x) {
comment|///   g(x); // g is an unresolved function name (that is also a dependent name)
comment|/// }
comment|/// @endcode
name|class
name|UnresolvedFunctionNameExpr
operator|:
name|public
name|Expr
block|{
comment|/// The name that was present in the source
name|DeclarationName
name|Name
block|;
comment|/// The location of this name in the source code
name|SourceLocation
name|Loc
block|;
name|public
operator|:
name|UnresolvedFunctionNameExpr
argument_list|(
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|,
argument|SourceLocation L
argument_list|)
operator|:
name|Expr
argument_list|(
name|UnresolvedFunctionNameExprClass
argument_list|,
name|T
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Name
argument_list|(
name|N
argument_list|)
block|,
name|Loc
argument_list|(
argument|L
argument_list|)
block|{ }
comment|/// \brief Retrieves the name that occurred in the source code.
name|DeclarationName
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// getLocation - Retrieves the location in the source code where
comment|/// the name occurred.
name|SourceLocation
name|getLocation
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
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|)
return|;
block|}
name|UnresolvedFunctionNameExpr
operator|*
name|Clone
argument_list|(
argument|ASTContext&C
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
name|UnresolvedFunctionNameExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const UnresolvedFunctionNameExpr *
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
comment|/// QualifiedDeclRefExpr - A reference to a declared variable,
comment|/// function, enum, etc., that includes a qualification, e.g.,
comment|/// "N::foo".
name|class
name|QualifiedDeclRefExpr
operator|:
name|public
name|DeclRefExpr
block|{
comment|/// QualifierRange - The source range that covers the
comment|/// nested-name-specifier.
name|SourceRange
name|QualifierRange
block|;
comment|/// \brief The nested-name-specifier that qualifies this declaration
comment|/// name.
name|NestedNameSpecifier
operator|*
name|NNS
block|;
name|public
operator|:
name|QualifiedDeclRefExpr
argument_list|(
argument|NamedDecl *d
argument_list|,
argument|QualType t
argument_list|,
argument|SourceLocation l
argument_list|,
argument|bool TD
argument_list|,
argument|bool VD
argument_list|,
argument|SourceRange R
argument_list|,
argument|NestedNameSpecifier *NNS
argument_list|)
operator|:
name|DeclRefExpr
argument_list|(
name|QualifiedDeclRefExprClass
argument_list|,
name|d
argument_list|,
name|t
argument_list|,
name|l
argument_list|,
name|TD
argument_list|,
name|VD
argument_list|)
block|,
name|QualifierRange
argument_list|(
name|R
argument_list|)
block|,
name|NNS
argument_list|(
argument|NNS
argument_list|)
block|{ }
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
name|NNS
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
name|QualifierRange
operator|.
name|getBegin
argument_list|()
argument_list|,
name|getLocation
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
name|QualifiedDeclRefExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const QualifiedDeclRefExpr *
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
comment|/// UnresolvedDeclRefExpr is similar to QualifiedDeclRefExpr in that
comment|/// it expresses a qualified reference to a declaration such as
comment|/// X<T>::value. The difference, however, is that an
comment|/// UnresolvedDeclRefExpr node is used only within C++ templates when
comment|/// the qualification (e.g., X<T>::) refers to a dependent type. In
comment|/// this case, X<T>::value cannot resolve to a declaration because the
comment|/// declaration will differ from on instantiation of X<T> to the
comment|/// next. Therefore, UnresolvedDeclRefExpr keeps track of the
comment|/// qualifier (X<T>::) and the name of the entity being referenced
comment|/// ("value"). Such expressions will instantiate to
comment|/// QualifiedDeclRefExprs.
name|class
name|UnresolvedDeclRefExpr
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
name|NNS
block|;
name|public
operator|:
name|UnresolvedDeclRefExpr
argument_list|(
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|,
argument|SourceLocation L
argument_list|,
argument|SourceRange R
argument_list|,
argument|NestedNameSpecifier *NNS
argument_list|)
operator|:
name|Expr
argument_list|(
name|UnresolvedDeclRefExprClass
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
name|N
argument_list|)
block|,
name|Loc
argument_list|(
name|L
argument_list|)
block|,
name|QualifierRange
argument_list|(
name|R
argument_list|)
block|,
name|NNS
argument_list|(
argument|NNS
argument_list|)
block|{ }
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
name|NNS
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
name|QualifierRange
operator|.
name|getBegin
argument_list|()
argument_list|,
name|getLocation
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
name|UnresolvedDeclRefExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const UnresolvedDeclRefExpr *
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
block|;
name|class
name|CXXExprWithTemporaries
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
name|bool
name|DestroyTemps
block|;
name|CXXExprWithTemporaries
argument_list|(
argument|Expr *SubExpr
argument_list|,
argument|CXXTemporary **Temps
argument_list|,
argument|unsigned NumTemps
argument_list|,
argument|bool DestroyTemps
argument_list|)
block|;
operator|~
name|CXXExprWithTemporaries
argument_list|()
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
argument_list|,
argument|bool DestroyTems
argument_list|)
block|;
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
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
name|void
name|removeLastTemporary
argument_list|()
block|{
name|NumTemps
operator|--
block|; }
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
name|SourceRange
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
comment|/// \brief
name|class
name|CXXUnresolvedMemberExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief The expression for the base pointer or class reference,
comment|/// e.g., the \c x in x.f.
name|Stmt
operator|*
name|Base
block|;
comment|/// \brief Whether this member expression used the '->' operator or
comment|/// the '.' operator.
name|bool
name|IsArrow
block|;
comment|/// \brief The location of the '->' or '.' operator.
name|SourceLocation
name|OperatorLoc
block|;
comment|/// \brief The member to which this member expression refers, which
comment|/// can be name, overloaded operator, or destructor.
comment|/// FIXME: could also be a template-id, and we might have a
comment|/// nested-name-specifier as well.
name|DeclarationName
name|Member
block|;
comment|/// \brief The location of the member name.
name|SourceLocation
name|MemberLoc
block|;
name|public
operator|:
name|CXXUnresolvedMemberExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr *Base
argument_list|,
argument|bool IsArrow
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|DeclarationName Member
argument_list|,
argument|SourceLocation MemberLoc
argument_list|)
operator|:
name|Expr
argument_list|(
name|CXXUnresolvedMemberExprClass
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
name|IsArrow
argument_list|(
name|IsArrow
argument_list|)
block|,
name|OperatorLoc
argument_list|(
name|OperatorLoc
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
comment|/// \brief Retrieve the base object of this member expressions,
comment|/// e.g., the \c x in \c x.m.
name|Expr
operator|*
name|getBase
argument_list|()
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
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Base
operator|->
name|getSourceRange
argument_list|()
operator|.
name|getBegin
argument_list|()
argument_list|,
name|MemberLoc
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
name|CXXUnresolvedMemberExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXUnresolvedMemberExpr *
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

