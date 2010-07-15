begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Expr.h - Classes for representing expressions ----------*- C++ -*-===//
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
comment|//  This file defines the Expr interface and subclasses.
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
name|LLVM_CLANG_AST_EXPR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_EXPR_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/APValue.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclAccessPair.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ASTVector.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/UsuallyTinyPtrVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APSInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APFloat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|APValue
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|ParmVarDecl
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|ValueDecl
decl_stmt|;
name|class
name|BlockDecl
decl_stmt|;
name|class
name|CXXBaseSpecifier
decl_stmt|;
name|class
name|CXXOperatorCallExpr
decl_stmt|;
name|class
name|CXXMemberCallExpr
decl_stmt|;
name|class
name|TemplateArgumentLoc
decl_stmt|;
name|class
name|TemplateArgumentListInfo
decl_stmt|;
comment|/// \brief A simple array of base specifiers.
typedef|typedef
name|UsuallyTinyPtrVector
operator|<
specifier|const
name|CXXBaseSpecifier
operator|>
name|CXXBaseSpecifierArray
expr_stmt|;
comment|/// Expr - This represents one expression.  Note that Expr's are subclasses of
comment|/// Stmt.  This allows an expression to be transparently used any place a Stmt
comment|/// is required.
comment|///
name|class
name|Expr
range|:
name|public
name|Stmt
block|{
name|QualType
name|TR
block|;
name|virtual
name|void
name|ANCHOR
argument_list|()
block|;
comment|// key function.
name|protected
operator|:
comment|/// TypeDependent - Whether this expression is type-dependent
comment|/// (C++ [temp.dep.expr]).
name|bool
name|TypeDependent
operator|:
literal|1
block|;
comment|/// ValueDependent - Whether this expression is value-dependent
comment|/// (C++ [temp.dep.constexpr]).
name|bool
name|ValueDependent
operator|:
literal|1
block|;
name|Expr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|QualType T
argument_list|,
argument|bool TD
argument_list|,
argument|bool VD
argument_list|)
operator|:
name|Stmt
argument_list|(
name|SC
argument_list|)
block|,
name|TypeDependent
argument_list|(
name|TD
argument_list|)
block|,
name|ValueDependent
argument_list|(
argument|VD
argument_list|)
block|{
name|setType
argument_list|(
name|T
argument_list|)
block|;   }
comment|/// \brief Construct an empty expression.
name|explicit
name|Expr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|EmptyShell
argument_list|)
operator|:
name|Stmt
argument_list|(
argument|SC
argument_list|)
block|{ }
name|public
operator|:
comment|/// \brief Increases the reference count for this expression.
comment|///
comment|/// Invoke the Retain() operation when this expression
comment|/// is being shared by another owner.
name|Expr
operator|*
name|Retain
argument_list|()
block|{
name|Stmt
operator|::
name|Retain
argument_list|()
block|;
return|return
name|this
return|;
block|}
name|QualType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|TR
return|;
block|}
name|void
name|setType
argument_list|(
argument|QualType t
argument_list|)
block|{
comment|// In C++, the type of an expression is always adjusted so that it
comment|// will not have reference type an expression will never have
comment|// reference type (C++ [expr]p6). Use
comment|// QualType::getNonReferenceType() to retrieve the non-reference
comment|// type. Additionally, inspect Expr::isLvalue to determine whether
comment|// an expression that is adjusted in this manner should be
comment|// considered an lvalue.
name|assert
argument_list|(
operator|(
name|t
operator|.
name|isNull
argument_list|()
operator|||
operator|!
name|t
operator|->
name|isReferenceType
argument_list|()
operator|)
operator|&&
literal|"Expressions can't have reference type"
argument_list|)
block|;
name|TR
operator|=
name|t
block|;   }
comment|/// isValueDependent - Determines whether this expression is
comment|/// value-dependent (C++ [temp.dep.constexpr]). For example, the
comment|/// array bound of "Chars" in the following example is
comment|/// value-dependent.
comment|/// @code
comment|/// template<int Size, char (&Chars)[Size]> struct meta_string;
comment|/// @endcode
name|bool
name|isValueDependent
argument_list|()
specifier|const
block|{
return|return
name|ValueDependent
return|;
block|}
comment|/// \brief Set whether this expression is value-dependent or not.
name|void
name|setValueDependent
argument_list|(
argument|bool VD
argument_list|)
block|{
name|ValueDependent
operator|=
name|VD
block|; }
comment|/// isTypeDependent - Determines whether this expression is
comment|/// type-dependent (C++ [temp.dep.expr]), which means that its type
comment|/// could change from one template instantiation to the next. For
comment|/// example, the expressions "x" and "x + y" are type-dependent in
comment|/// the following code, but "y" is not type-dependent:
comment|/// @code
comment|/// template<typename T>
comment|/// void add(T x, int y) {
comment|///   x + y;
comment|/// }
comment|/// @endcode
name|bool
name|isTypeDependent
argument_list|()
specifier|const
block|{
return|return
name|TypeDependent
return|;
block|}
comment|/// \brief Set whether this expression is type-dependent or not.
name|void
name|setTypeDependent
argument_list|(
argument|bool TD
argument_list|)
block|{
name|TypeDependent
operator|=
name|TD
block|; }
comment|/// SourceLocation tokens are not useful in isolation - they are low level
comment|/// value objects created/interpreted by SourceManager. We assume AST
comment|/// clients will have a pointer to the respective SourceManager.
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// getExprLoc - Return the preferred location for the arrow when diagnosing
comment|/// a problem with a generic expression.
name|virtual
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
block|{
return|return
name|getLocStart
argument_list|()
return|;
block|}
comment|/// isUnusedResultAWarning - Return true if this immediate expression should
comment|/// be warned about if the result is unused.  If so, fill in Loc and Ranges
comment|/// with location to warn on and the source range[s] to report with the
comment|/// warning.
name|bool
name|isUnusedResultAWarning
argument_list|(
argument|SourceLocation&Loc
argument_list|,
argument|SourceRange&R1
argument_list|,
argument|SourceRange&R2
argument_list|,
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// isLvalue - C99 6.3.2.1: an lvalue is an expression with an object type or
comment|/// incomplete type other than void. Nonarray expressions that can be lvalues:
comment|///  - name, where name must be a variable
comment|///  - e[i]
comment|///  - (e), where e must be an lvalue
comment|///  - e.name, where e must be an lvalue
comment|///  - e->name
comment|///  - *e, the type of e cannot be a function type
comment|///  - string-constant
comment|///  - reference type [C++ [expr]]
comment|///  - b ? x : y, where x and y are lvalues of suitable types [C++]
comment|///
block|enum
name|isLvalueResult
block|{
name|LV_Valid
block|,
name|LV_NotObjectType
block|,
name|LV_IncompleteVoidType
block|,
name|LV_DuplicateVectorComponents
block|,
name|LV_InvalidExpression
block|,
name|LV_MemberFunction
block|,
name|LV_SubObjCPropertySetting
block|,
name|LV_ClassTemporary
block|}
block|;
name|isLvalueResult
name|isLvalue
argument_list|(
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// isModifiableLvalue - C99 6.3.2.1: an lvalue that does not have array type,
comment|/// does not have an incomplete type, does not have a const-qualified type,
comment|/// and if it is a structure or union, does not have any member (including,
comment|/// recursively, any member or element of all contained aggregates or unions)
comment|/// with a const-qualified type.
comment|///
comment|/// \param Loc [in] [out] - A source location which *may* be filled
comment|/// in with the location of the expression making this a
comment|/// non-modifiable lvalue, if specified.
block|enum
name|isModifiableLvalueResult
block|{
name|MLV_Valid
block|,
name|MLV_NotObjectType
block|,
name|MLV_IncompleteVoidType
block|,
name|MLV_DuplicateVectorComponents
block|,
name|MLV_InvalidExpression
block|,
name|MLV_LValueCast
block|,
comment|// Specialized form of MLV_InvalidExpression.
name|MLV_IncompleteType
block|,
name|MLV_ConstQualified
block|,
name|MLV_ArrayType
block|,
name|MLV_NotBlockQualified
block|,
name|MLV_ReadonlyProperty
block|,
name|MLV_NoSetterProperty
block|,
name|MLV_MemberFunction
block|,
name|MLV_SubObjCPropertySetting
block|,
name|MLV_ClassTemporary
block|}
block|;
name|isModifiableLvalueResult
name|isModifiableLvalue
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|SourceLocation *Loc =
literal|0
argument_list|)
specifier|const
block|;
comment|/// \brief The return type of classify(). Represents the C++0x expression
comment|///        taxonomy.
name|class
name|Classification
block|{
name|public
operator|:
comment|/// \brief The various classification results. Most of these mean prvalue.
expr|enum
name|Kinds
block|{
name|CL_LValue
block|,
name|CL_XValue
block|,
name|CL_Function
block|,
comment|// Functions cannot be lvalues in C.
name|CL_Void
block|,
comment|// Void cannot be an lvalue in C.
name|CL_DuplicateVectorComponents
block|,
comment|// A vector shuffle with dupes.
name|CL_MemberFunction
block|,
comment|// An expression referring to a member function
name|CL_SubObjCPropertySetting
block|,
name|CL_ClassTemporary
block|,
comment|// A prvalue of class type
name|CL_PRValue
comment|// A prvalue for any other reason, of any other type
block|}
block|;
comment|/// \brief The results of modification testing.
block|enum
name|ModifiableType
block|{
name|CM_Untested
block|,
comment|// testModifiable was false.
name|CM_Modifiable
block|,
name|CM_RValue
block|,
comment|// Not modifiable because it's an rvalue
name|CM_Function
block|,
comment|// Not modifiable because it's a function; C++ only
name|CM_LValueCast
block|,
comment|// Same as CM_RValue, but indicates GCC cast-as-lvalue ext
name|CM_NotBlockQualified
block|,
comment|// Not captured in the closure
name|CM_NoSetterProperty
block|,
comment|// Implicit assignment to ObjC property without setter
name|CM_ConstQualified
block|,
name|CM_ArrayType
block|,
name|CM_IncompleteType
block|}
block|;
name|private
operator|:
name|friend
name|class
name|Expr
block|;
name|unsigned
name|short
name|Kind
block|;
name|unsigned
name|short
name|Modifiable
block|;
name|explicit
name|Classification
argument_list|(
argument|Kinds k
argument_list|,
argument|ModifiableType m
argument_list|)
operator|:
name|Kind
argument_list|(
name|k
argument_list|)
block|,
name|Modifiable
argument_list|(
argument|m
argument_list|)
block|{}
name|public
operator|:
name|Classification
argument_list|()
block|{}
name|Kinds
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Kinds
operator|>
operator|(
name|Kind
operator|)
return|;
block|}
name|ModifiableType
name|getModifiable
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Modifiable
operator|!=
name|CM_Untested
operator|&&
literal|"Did not test for modifiability."
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|ModifiableType
operator|>
operator|(
name|Modifiable
operator|)
return|;
block|}
name|bool
name|isLValue
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|CL_LValue
return|;
block|}
name|bool
name|isXValue
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|CL_XValue
return|;
block|}
name|bool
name|isGLValue
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|<=
name|CL_XValue
return|;
block|}
name|bool
name|isPRValue
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|>=
name|CL_Function
return|;
block|}
name|bool
name|isRValue
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|>=
name|CL_XValue
return|;
block|}
name|bool
name|isModifiable
argument_list|()
specifier|const
block|{
return|return
name|getModifiable
argument_list|()
operator|==
name|CM_Modifiable
return|;
block|}
expr|}
block|;
comment|/// \brief classify - Classify this expression according to the C++0x
comment|///        expression taxonomy.
comment|///
comment|/// C++0x defines ([basic.lval]) a new taxonomy of expressions to replace the
comment|/// old lvalue vs rvalue. This function determines the type of expression this
comment|/// is. There are three expression types:
comment|/// - lvalues are classical lvalues as in C++03.
comment|/// - prvalues are equivalent to rvalues in C++03.
comment|/// - xvalues are expressions yielding unnamed rvalue references, e.g. a
comment|///   function returning an rvalue reference.
comment|/// lvalues and xvalues are collectively referred to as glvalues, while
comment|/// prvalues and xvalues together form rvalues.
comment|/// If a
name|Classification
name|Classify
argument_list|(
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|{
return|return
name|ClassifyImpl
argument_list|(
name|Ctx
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// \brief classifyModifiable - Classify this expression according to the
comment|///        C++0x expression taxonomy, and see if it is valid on the left side
comment|///        of an assignment.
comment|///
comment|/// This function extends classify in that it also tests whether the
comment|/// expression is modifiable (C99 6.3.2.1p1).
comment|/// \param Loc A source location that might be filled with a relevant location
comment|///            if the expression is not modifiable.
name|Classification
name|ClassifyModifiable
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|SourceLocation&Loc
argument_list|)
specifier|const
block|{
return|return
name|ClassifyImpl
argument_list|(
name|Ctx
argument_list|,
operator|&
name|Loc
argument_list|)
return|;
block|}
name|private
operator|:
name|Classification
name|ClassifyImpl
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|SourceLocation *Loc
argument_list|)
specifier|const
block|;
name|public
operator|:
comment|/// \brief If this expression refers to a bit-field, retrieve the
comment|/// declaration of that bit-field.
name|FieldDecl
operator|*
name|getBitField
argument_list|()
block|;
specifier|const
name|FieldDecl
operator|*
name|getBitField
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getBitField
argument_list|()
return|;
block|}
comment|/// \brief Returns whether this expression refers to a vector element.
name|bool
name|refersToVectorElement
argument_list|()
specifier|const
block|;
comment|/// isKnownToHaveBooleanValue - Return true if this is an integer expression
comment|/// that is known to return 0 or 1.  This happens for _Bool/bool expressions
comment|/// but also int expressions which are produced by things like comparisons in
comment|/// C.
name|bool
name|isKnownToHaveBooleanValue
argument_list|()
specifier|const
block|;
comment|/// isIntegerConstantExpr - Return true if this expression is a valid integer
comment|/// constant expression, and, if so, return its value in Result.  If not a
comment|/// valid i-c-e, return false and fill in Loc (if specified) with the location
comment|/// of the invalid expression.
name|bool
name|isIntegerConstantExpr
argument_list|(
argument|llvm::APSInt&Result
argument_list|,
argument|ASTContext&Ctx
argument_list|,
argument|SourceLocation *Loc =
literal|0
argument_list|,
argument|bool isEvaluated = true
argument_list|)
specifier|const
block|;
name|bool
name|isIntegerConstantExpr
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|SourceLocation *Loc =
literal|0
argument_list|)
specifier|const
block|{
name|llvm
operator|::
name|APSInt
name|X
block|;
return|return
name|isIntegerConstantExpr
argument_list|(
name|X
argument_list|,
name|Ctx
argument_list|,
name|Loc
argument_list|)
return|;
block|}
comment|/// isConstantInitializer - Returns true if this expression is a constant
comment|/// initializer, which can be emitted at compile-time.
name|bool
name|isConstantInitializer
argument_list|(
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// EvalResult is a struct with detailed info about an evaluated expression.
block|struct
name|EvalResult
block|{
comment|/// Val - This is the value the expression can be folded to.
name|APValue
name|Val
block|;
comment|/// HasSideEffects - Whether the evaluated expression has side effects.
comment|/// For example, (f()&& 0) can be folded, but it still has side effects.
name|bool
name|HasSideEffects
block|;
comment|/// Diag - If the expression is unfoldable, then Diag contains a note
comment|/// diagnostic indicating why it's not foldable. DiagLoc indicates a caret
comment|/// position for the error, and DiagExpr is the expression that caused
comment|/// the error.
comment|/// If the expression is foldable, but not an integer constant expression,
comment|/// Diag contains a note diagnostic that describes why it isn't an integer
comment|/// constant expression. If the expression *is* an integer constant
comment|/// expression, then Diag will be zero.
name|unsigned
name|Diag
block|;
specifier|const
name|Expr
operator|*
name|DiagExpr
block|;
name|SourceLocation
name|DiagLoc
block|;
name|EvalResult
argument_list|()
operator|:
name|HasSideEffects
argument_list|(
name|false
argument_list|)
block|,
name|Diag
argument_list|(
literal|0
argument_list|)
block|,
name|DiagExpr
argument_list|(
literal|0
argument_list|)
block|{}
comment|// isGlobalLValue - Return true if the evaluated lvalue expression
comment|// is global.
name|bool
name|isGlobalLValue
argument_list|()
specifier|const
block|;
comment|// hasSideEffects - Return true if the evaluated expression has
comment|// side effects.
name|bool
name|hasSideEffects
argument_list|()
specifier|const
block|{
return|return
name|HasSideEffects
return|;
block|}
expr|}
block|;
comment|/// Evaluate - Return true if this is a constant which we can fold using
comment|/// any crazy technique (that has nothing to do with language standards) that
comment|/// we want to.  If this function returns true, it returns the folded constant
comment|/// in Result.
name|bool
name|Evaluate
argument_list|(
argument|EvalResult&Result
argument_list|,
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// EvaluateAsBooleanCondition - Return true if this is a constant
comment|/// which we we can fold and convert to a boolean condition using
comment|/// any crazy technique that we want to.
name|bool
name|EvaluateAsBooleanCondition
argument_list|(
argument|bool&Result
argument_list|,
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// isEvaluatable - Call Evaluate to see if this expression can be constant
comment|/// folded, but discard the result.
name|bool
name|isEvaluatable
argument_list|(
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// HasSideEffects - This routine returns true for all those expressions
comment|/// which must be evaluated each time and must not be optimization away
comment|/// or evaluated at compile time. Example is a function call, volatile
comment|/// variable read.
name|bool
name|HasSideEffects
argument_list|(
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// EvaluateAsInt - Call Evaluate and return the folded integer. This
comment|/// must be called on an expression that constant folds to an integer.
name|llvm
operator|::
name|APSInt
name|EvaluateAsInt
argument_list|(
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// EvaluateAsLValue - Evaluate an expression to see if it's a lvalue
comment|/// with link time known address.
name|bool
name|EvaluateAsLValue
argument_list|(
argument|EvalResult&Result
argument_list|,
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// EvaluateAsLValue - Evaluate an expression to see if it's a lvalue.
name|bool
name|EvaluateAsAnyLValue
argument_list|(
argument|EvalResult&Result
argument_list|,
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// \brief Enumeration used to describe how \c isNullPointerConstant()
comment|/// should cope with value-dependent expressions.
block|enum
name|NullPointerConstantValueDependence
block|{
comment|/// \brief Specifies that the expression should never be value-dependent.
name|NPC_NeverValueDependent
operator|=
literal|0
block|,
comment|/// \brief Specifies that a value-dependent expression of integral or
comment|/// dependent type should be considered a null pointer constant.
name|NPC_ValueDependentIsNull
block|,
comment|/// \brief Specifies that a value-dependent expression should be considered
comment|/// to never be a null pointer constant.
name|NPC_ValueDependentIsNotNull
block|}
block|;
comment|/// isNullPointerConstant - C99 6.3.2.3p3 -  Return true if this is either an
comment|/// integer constant expression with the value zero, or if this is one that is
comment|/// cast to void*.
name|bool
name|isNullPointerConstant
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|NullPointerConstantValueDependence NPC
argument_list|)
specifier|const
block|;
comment|/// isOBJCGCCandidate - Return true if this expression may be used in a read/
comment|/// write barrier.
name|bool
name|isOBJCGCCandidate
argument_list|(
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// IgnoreParens - Ignore parentheses.  If this Expr is a ParenExpr, return
comment|///  its subexpression.  If that subexpression is also a ParenExpr,
comment|///  then this method recursively returns its subexpression, and so forth.
comment|///  Otherwise, the method returns the current Expr.
name|Expr
operator|*
name|IgnoreParens
argument_list|()
block|;
comment|/// IgnoreParenCasts - Ignore parentheses and casts.  Strip off any ParenExpr
comment|/// or CastExprs, returning their operand.
name|Expr
operator|*
name|IgnoreParenCasts
argument_list|()
block|;
comment|/// IgnoreParenImpCasts - Ignore parentheses and implicit casts.  Strip off any
comment|/// ParenExpr or ImplicitCastExprs, returning their operand.
name|Expr
operator|*
name|IgnoreParenImpCasts
argument_list|()
block|;
comment|/// IgnoreParenNoopCasts - Ignore parentheses and casts that do not change the
comment|/// value (including ptr->int casts of the same size).  Strip off any
comment|/// ParenExpr or CastExprs, returning their operand.
name|Expr
operator|*
name|IgnoreParenNoopCasts
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
block|;
comment|/// \brief Determine whether this expression is a default function argument.
comment|///
comment|/// Default arguments are implicitly generated in the abstract syntax tree
comment|/// by semantic analysis for function calls, object constructions, etc. in
comment|/// C++. Default arguments are represented by \c CXXDefaultArgExpr nodes;
comment|/// this routine also looks through any implicit casts to determine whether
comment|/// the expression is a default argument.
name|bool
name|isDefaultArgument
argument_list|()
specifier|const
block|;
comment|/// \brief Determine whether this expression directly creates a
comment|/// temporary object (of class type).
name|bool
name|isTemporaryObject
argument_list|()
specifier|const
block|{
return|return
name|getTemporaryObject
argument_list|()
operator|!=
literal|0
return|;
block|}
comment|/// \brief If this expression directly creates a temporary object of
comment|/// class type, return the expression that actually constructs that
comment|/// temporary object.
specifier|const
name|Expr
operator|*
name|getTemporaryObject
argument_list|()
specifier|const
block|;
specifier|const
name|Expr
operator|*
name|IgnoreParens
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|IgnoreParens
argument_list|()
return|;
block|}
specifier|const
name|Expr
operator|*
name|IgnoreParenCasts
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|IgnoreParenCasts
argument_list|()
return|;
block|}
specifier|const
name|Expr
operator|*
name|IgnoreParenNoopCasts
argument_list|(
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|IgnoreParenNoopCasts
argument_list|(
name|Ctx
argument_list|)
return|;
block|}
specifier|static
name|bool
name|hasAnyTypeDependentArguments
argument_list|(
argument|Expr** Exprs
argument_list|,
argument|unsigned NumExprs
argument_list|)
block|;
specifier|static
name|bool
name|hasAnyValueDependentArguments
argument_list|(
argument|Expr** Exprs
argument_list|,
argument|unsigned NumExprs
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
operator|>=
name|firstExprConstant
operator|&&
name|T
operator|->
name|getStmtClass
argument_list|()
operator|<=
name|lastExprConstant
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Expr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|// Primary Expressions.
comment|//===----------------------------------------------------------------------===//
comment|/// \brief Represents the qualifier that may precede a C++ name, e.g., the
comment|/// "std::" in "std::sort".
block|struct
name|NameQualifier
block|{
comment|/// \brief The nested name specifier.
name|NestedNameSpecifier
operator|*
name|NNS
block|;
comment|/// \brief The source range covered by the nested name specifier.
name|SourceRange
name|Range
block|; }
block|;
comment|/// \brief Represents an explicit template argument list in C++, e.g.,
comment|/// the "<int>" in "sort<int>".
block|struct
name|ExplicitTemplateArgumentList
block|{
comment|/// \brief The source location of the left angle bracket ('<');
name|SourceLocation
name|LAngleLoc
block|;
comment|/// \brief The source location of the right angle bracket ('>');
name|SourceLocation
name|RAngleLoc
block|;
comment|/// \brief The number of template arguments in TemplateArgs.
comment|/// The actual template arguments (if any) are stored after the
comment|/// ExplicitTemplateArgumentList structure.
name|unsigned
name|NumTemplateArgs
block|;
comment|/// \brief Retrieve the template arguments
name|TemplateArgumentLoc
operator|*
name|getTemplateArgs
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|TemplateArgumentLoc
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieve the template arguments
specifier|const
name|TemplateArgumentLoc
operator|*
name|getTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|TemplateArgumentLoc
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|void
name|initializeFrom
argument_list|(
specifier|const
name|TemplateArgumentListInfo
operator|&
name|List
argument_list|)
block|;
name|void
name|copyInto
argument_list|(
argument|TemplateArgumentListInfo&List
argument_list|)
specifier|const
block|;
specifier|static
name|std
operator|::
name|size_t
name|sizeFor
argument_list|(
argument|unsigned NumTemplateArgs
argument_list|)
block|;
specifier|static
name|std
operator|::
name|size_t
name|sizeFor
argument_list|(
specifier|const
name|TemplateArgumentListInfo
operator|&
name|List
argument_list|)
block|; }
block|;
comment|/// DeclRefExpr - [C99 6.5.1p2] - A reference to a declared variable, function,
comment|/// enum, etc.
name|class
name|DeclRefExpr
operator|:
name|public
name|Expr
block|{   enum
block|{
comment|// Flag on DecoratedD that specifies when this declaration reference
comment|// expression has a C++ nested-name-specifier.
name|HasQualifierFlag
operator|=
literal|0x01
block|,
comment|// Flag on DecoratedD that specifies when this declaration reference
comment|// expression has an explicit C++ template argument list.
name|HasExplicitTemplateArgumentListFlag
operator|=
literal|0x02
block|}
block|;
comment|// DecoratedD - The declaration that we are referencing, plus two bits to
comment|// indicate whether (1) the declaration's name was explicitly qualified and
comment|// (2) the declaration's name was followed by an explicit template
comment|// argument list.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|ValueDecl
operator|*
block|,
literal|2
operator|>
name|DecoratedD
block|;
comment|// Loc - The location of the declaration name itself.
name|SourceLocation
name|Loc
block|;
comment|/// \brief Retrieve the qualifier that preceded the declaration name, if any.
name|NameQualifier
operator|*
name|getNameQualifier
argument_list|()
block|{
if|if
condition|(
operator|(
name|DecoratedD
operator|.
name|getInt
argument_list|()
operator|&
name|HasQualifierFlag
operator|)
operator|==
literal|0
condition|)
return|return
literal|0
return|;
return|return
name|reinterpret_cast
operator|<
name|NameQualifier
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieve the qualifier that preceded the member name, if any.
specifier|const
name|NameQualifier
operator|*
name|getNameQualifier
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|DeclRefExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getNameQualifier
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the explicit template argument list that followed the
comment|/// member template name, if any.
name|ExplicitTemplateArgumentList
operator|*
name|getExplicitTemplateArgumentList
argument_list|()
block|{
if|if
condition|(
operator|(
name|DecoratedD
operator|.
name|getInt
argument_list|()
operator|&
name|HasExplicitTemplateArgumentListFlag
operator|)
operator|==
literal|0
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|(
name|DecoratedD
operator|.
name|getInt
argument_list|()
operator|&
name|HasQualifierFlag
operator|)
operator|==
literal|0
condition|)
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
return|return
name|reinterpret_cast
operator|<
name|ExplicitTemplateArgumentList
operator|*
operator|>
operator|(
name|getNameQualifier
argument_list|()
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
name|DeclRefExpr
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
name|DeclRefExpr
argument_list|(
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|ValueDecl *D
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|,
argument|QualType T
argument_list|)
block|;
comment|/// \brief Construct an empty declaration reference expression.
name|explicit
name|DeclRefExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|DeclRefExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// \brief Computes the type- and value-dependence flags for this
comment|/// declaration reference expression.
name|void
name|computeDependence
argument_list|()
block|;
name|public
operator|:
name|DeclRefExpr
argument_list|(
argument|ValueDecl *d
argument_list|,
argument|QualType t
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|Expr
argument_list|(
name|DeclRefExprClass
argument_list|,
name|t
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|DecoratedD
argument_list|(
name|d
argument_list|,
literal|0
argument_list|)
block|,
name|Loc
argument_list|(
argument|l
argument_list|)
block|{
name|computeDependence
argument_list|()
block|;   }
specifier|static
name|DeclRefExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|ValueDecl *D
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|QualType T
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs =
literal|0
argument_list|)
block|;
comment|/// \brief Construct an empty declaration reference expression.
specifier|static
name|DeclRefExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|bool HasQualifier
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|)
block|;
name|ValueDecl
operator|*
name|getDecl
argument_list|()
block|{
return|return
name|DecoratedD
operator|.
name|getPointer
argument_list|()
return|;
block|}
specifier|const
name|ValueDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|DecoratedD
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|void
name|setDecl
argument_list|(
argument|ValueDecl *NewD
argument_list|)
block|{
name|DecoratedD
operator|.
name|setPointer
argument_list|(
name|NewD
argument_list|)
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
block|;
comment|/// \brief Determine whether this declaration reference was preceded by a
comment|/// C++ nested-name-specifier, e.g., \c N::foo.
name|bool
name|hasQualifier
argument_list|()
specifier|const
block|{
return|return
name|DecoratedD
operator|.
name|getInt
argument_list|()
operator|&
name|HasQualifierFlag
return|;
block|}
comment|/// \brief If the name was qualified, retrieves the source range of
comment|/// the nested-name-specifier that precedes the name. Otherwise,
comment|/// returns an empty source range.
name|SourceRange
name|getQualifierRange
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hasQualifier
argument_list|()
condition|)
return|return
name|SourceRange
argument_list|()
return|;
return|return
name|getNameQualifier
argument_list|()
operator|->
name|Range
return|;
block|}
comment|/// \brief If the name was qualified, retrieves the nested-name-specifier
comment|/// that precedes the name. Otherwise, returns NULL.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hasQualifier
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|getNameQualifier
argument_list|()
operator|->
name|NNS
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determines whether this member expression actually had a C++
end_comment

begin_comment
comment|/// template argument list explicitly specified, e.g., x.f<int>.
end_comment

begin_expr_stmt
name|bool
name|hasExplicitTemplateArgumentList
argument_list|()
specifier|const
block|{
return|return
name|DecoratedD
operator|.
name|getInt
argument_list|()
operator|&
name|HasExplicitTemplateArgumentListFlag
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Copies the template arguments (if present) into the given
end_comment

begin_comment
comment|/// structure.
end_comment

begin_decl_stmt
name|void
name|copyTemplateArgumentsInto
argument_list|(
name|TemplateArgumentListInfo
operator|&
name|List
argument_list|)
decl|const
block|{
if|if
condition|(
name|hasExplicitTemplateArgumentList
argument_list|()
condition|)
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|copyInto
argument_list|(
name|List
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the location of the left angle bracket following the
end_comment

begin_comment
comment|/// member name ('<'), if any.
end_comment

begin_expr_stmt
name|SourceLocation
name|getLAngleLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hasExplicitTemplateArgumentList
argument_list|()
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|LAngleLoc
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the template arguments provided as part of this
end_comment

begin_comment
comment|/// template-id.
end_comment

begin_expr_stmt
unit|const
name|TemplateArgumentLoc
operator|*
name|getTemplateArgs
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hasExplicitTemplateArgumentList
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|getTemplateArgs
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the number of template arguments provided as part of this
end_comment

begin_comment
comment|/// template-id.
end_comment

begin_macro
unit|unsigned
name|getNumTemplateArgs
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
operator|!
name|hasExplicitTemplateArgumentList
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|NumTemplateArgs
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the location of the right angle bracket following the
end_comment

begin_comment
comment|/// template arguments ('>').
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
name|hasExplicitTemplateArgumentList
argument_list|()
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|RAngleLoc
return|;
end_return

begin_function
unit|}      static
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
name|DeclRefExprClass
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|DeclRefExpr
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

begin_decl_stmt
name|friend
name|class
name|PCHStmtReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|PCHStmtWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// PredefinedExpr - [C99 6.4.2.2] - A predefined identifier such as __func__.
end_comment

begin_decl_stmt
name|class
name|PredefinedExpr
range|:
name|public
name|Expr
block|{
name|public
operator|:
expr|enum
name|IdentType
block|{
name|Func
block|,
name|Function
block|,
name|PrettyFunction
block|,
comment|/// PrettyFunctionNoVirtual - The same as PrettyFunction, except that the
comment|/// 'virtual' keyword is omitted for virtual member functions.
name|PrettyFunctionNoVirtual
block|}
block|;
name|private
operator|:
name|SourceLocation
name|Loc
block|;
name|IdentType
name|Type
block|;
name|public
operator|:
name|PredefinedExpr
argument_list|(
argument|SourceLocation l
argument_list|,
argument|QualType type
argument_list|,
argument|IdentType IT
argument_list|)
operator|:
name|Expr
argument_list|(
name|PredefinedExprClass
argument_list|,
name|type
argument_list|,
name|type
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|type
operator|->
name|isDependentType
argument_list|()
argument_list|)
block|,
name|Loc
argument_list|(
name|l
argument_list|)
block|,
name|Type
argument_list|(
argument|IT
argument_list|)
block|{}
comment|/// \brief Construct an empty predefined expression.
name|explicit
name|PredefinedExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|PredefinedExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|IdentType
name|getIdentType
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
name|void
name|setIdentType
argument_list|(
argument|IdentType IT
argument_list|)
block|{
name|Type
operator|=
name|IT
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
argument|SourceLocation L
argument_list|)
block|{
name|Loc
operator|=
name|L
block|; }
specifier|static
name|std
operator|::
name|string
name|ComputeName
argument_list|(
argument|IdentType IT
argument_list|,
argument|const Decl *CurrentDecl
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
name|PredefinedExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const PredefinedExpr *
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
end_decl_stmt

begin_decl_stmt
name|class
name|IntegerLiteral
range|:
name|public
name|Expr
block|{
name|llvm
operator|::
name|APInt
name|Value
block|;
name|SourceLocation
name|Loc
block|;
name|public
operator|:
comment|// type should be IntTy, LongTy, LongLongTy, UnsignedIntTy, UnsignedLongTy,
comment|// or UnsignedLongLongTy
name|IntegerLiteral
argument_list|(
argument|const llvm::APInt&V
argument_list|,
argument|QualType type
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|Expr
argument_list|(
name|IntegerLiteralClass
argument_list|,
name|type
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Value
argument_list|(
name|V
argument_list|)
block|,
name|Loc
argument_list|(
argument|l
argument_list|)
block|{
name|assert
argument_list|(
name|type
operator|->
name|isIntegerType
argument_list|()
operator|&&
literal|"Illegal type in IntegerLiteral"
argument_list|)
block|;   }
comment|/// \brief Construct an empty integer literal.
name|explicit
name|IntegerLiteral
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|IntegerLiteralClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
specifier|const
name|llvm
operator|::
name|APInt
operator|&
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
comment|/// \brief Retrieve the location of the literal.
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
name|setValue
argument_list|(
argument|const llvm::APInt&Val
argument_list|)
block|{
name|Value
operator|=
name|Val
block|; }
name|void
name|setLocation
argument_list|(
argument|SourceLocation Location
argument_list|)
block|{
name|Loc
operator|=
name|Location
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
name|IntegerLiteralClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const IntegerLiteral *
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
end_decl_stmt

begin_decl_stmt
name|class
name|CharacterLiteral
range|:
name|public
name|Expr
block|{
name|unsigned
name|Value
block|;
name|SourceLocation
name|Loc
block|;
name|bool
name|IsWide
block|;
name|public
operator|:
comment|// type should be IntTy
name|CharacterLiteral
argument_list|(
argument|unsigned value
argument_list|,
argument|bool iswide
argument_list|,
argument|QualType type
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|Expr
argument_list|(
name|CharacterLiteralClass
argument_list|,
name|type
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Value
argument_list|(
name|value
argument_list|)
block|,
name|Loc
argument_list|(
name|l
argument_list|)
block|,
name|IsWide
argument_list|(
argument|iswide
argument_list|)
block|{   }
comment|/// \brief Construct an empty character literal.
name|CharacterLiteral
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CharacterLiteralClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|bool
name|isWide
argument_list|()
specifier|const
block|{
return|return
name|IsWide
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
name|unsigned
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
name|void
name|setLocation
argument_list|(
argument|SourceLocation Location
argument_list|)
block|{
name|Loc
operator|=
name|Location
block|; }
name|void
name|setWide
argument_list|(
argument|bool W
argument_list|)
block|{
name|IsWide
operator|=
name|W
block|; }
name|void
name|setValue
argument_list|(
argument|unsigned Val
argument_list|)
block|{
name|Value
operator|=
name|Val
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
name|CharacterLiteralClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CharacterLiteral *
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
end_decl_stmt

begin_decl_stmt
name|class
name|FloatingLiteral
range|:
name|public
name|Expr
block|{
name|llvm
operator|::
name|APFloat
name|Value
block|;
name|bool
name|IsExact
operator|:
literal|1
block|;
name|SourceLocation
name|Loc
block|;
name|public
operator|:
name|FloatingLiteral
argument_list|(
argument|const llvm::APFloat&V
argument_list|,
argument|bool isexact
argument_list|,
argument|QualType Type
argument_list|,
argument|SourceLocation L
argument_list|)
operator|:
name|Expr
argument_list|(
name|FloatingLiteralClass
argument_list|,
name|Type
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Value
argument_list|(
name|V
argument_list|)
block|,
name|IsExact
argument_list|(
name|isexact
argument_list|)
block|,
name|Loc
argument_list|(
argument|L
argument_list|)
block|{}
comment|/// \brief Construct an empty floating-point literal.
name|explicit
name|FloatingLiteral
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|FloatingLiteralClass
argument_list|,
name|Empty
argument_list|)
block|,
name|Value
argument_list|(
literal|0.0
argument_list|)
block|{ }
specifier|const
name|llvm
operator|::
name|APFloat
operator|&
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
argument|const llvm::APFloat&Val
argument_list|)
block|{
name|Value
operator|=
name|Val
block|; }
name|bool
name|isExact
argument_list|()
specifier|const
block|{
return|return
name|IsExact
return|;
block|}
name|void
name|setExact
argument_list|(
argument|bool E
argument_list|)
block|{
name|IsExact
operator|=
name|E
block|; }
comment|/// getValueAsApproximateDouble - This returns the value as an inaccurate
comment|/// double.  Note that this may cause loss of precision, but is useful for
comment|/// debugging dumps, etc.
name|double
name|getValueAsApproximateDouble
argument_list|()
specifier|const
block|;
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
name|FloatingLiteralClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const FloatingLiteral *
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
end_decl_stmt

begin_comment
comment|/// ImaginaryLiteral - We support imaginary integer and floating point literals,
end_comment

begin_comment
comment|/// like "1.0i".  We represent these as a wrapper around FloatingLiteral and
end_comment

begin_comment
comment|/// IntegerLiteral classes.  Instances of this class always have a Complex type
end_comment

begin_comment
comment|/// whose element type matches the subexpression.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ImaginaryLiteral
range|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|Val
block|;
name|public
operator|:
name|ImaginaryLiteral
argument_list|(
argument|Expr *val
argument_list|,
argument|QualType Ty
argument_list|)
operator|:
name|Expr
argument_list|(
name|ImaginaryLiteralClass
argument_list|,
name|Ty
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Val
argument_list|(
argument|val
argument_list|)
block|{}
comment|/// \brief Build an empty imaginary literal.
name|explicit
name|ImaginaryLiteral
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ImaginaryLiteralClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
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
name|Val
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
name|Val
operator|)
return|;
block|}
name|void
name|setSubExpr
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Val
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
name|Val
operator|->
name|getSourceRange
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
name|ImaginaryLiteralClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ImaginaryLiteral *
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
end_decl_stmt

begin_comment
comment|/// StringLiteral - This represents a string literal expression, e.g. "foo"
end_comment

begin_comment
comment|/// or L"bar" (wide strings).  The actual string is returned by getStrData()
end_comment

begin_comment
comment|/// is NOT null-terminated, and the length of the string is determined by
end_comment

begin_comment
comment|/// calling getByteLength().  The C type for a string is always a
end_comment

begin_comment
comment|/// ConstantArrayType.  In C++, the char type is const qualified, in C it is
end_comment

begin_comment
comment|/// not.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that strings in C can be formed by concatenation of multiple string
end_comment

begin_comment
comment|/// literal pptokens in translation phase #6.  This keeps track of the locations
end_comment

begin_comment
comment|/// of each of these pieces.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Strings in C can also be truncated and extended by assigning into arrays,
end_comment

begin_comment
comment|/// e.g. with constructs like:
end_comment

begin_comment
comment|///   char X[2] = "foobar";
end_comment

begin_comment
comment|/// In this case, getByteLength() will return 6, but the string literal will
end_comment

begin_comment
comment|/// have type "char[2]".
end_comment

begin_decl_stmt
name|class
name|StringLiteral
range|:
name|public
name|Expr
block|{
specifier|const
name|char
operator|*
name|StrData
block|;
name|unsigned
name|ByteLength
block|;
name|bool
name|IsWide
block|;
name|unsigned
name|NumConcatenated
block|;
name|SourceLocation
name|TokLocs
index|[
literal|1
index|]
block|;
name|StringLiteral
argument_list|(
argument|QualType Ty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|StringLiteralClass
argument_list|,
argument|Ty
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|)
block|{}
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
comment|/// This is the "fully general" constructor that allows representation of
comment|/// strings formed from multiple concatenated tokens.
specifier|static
name|StringLiteral
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|const char *StrData
argument_list|,
argument|unsigned ByteLength
argument_list|,
argument|bool Wide
argument_list|,
argument|QualType Ty
argument_list|,
argument|const SourceLocation *Loc
argument_list|,
argument|unsigned NumStrs
argument_list|)
block|;
comment|/// Simple constructor for string literals made from one token.
specifier|static
name|StringLiteral
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|const char *StrData
argument_list|,
argument|unsigned ByteLength
argument_list|,
argument|bool Wide
argument_list|,
argument|QualType Ty
argument_list|,
argument|SourceLocation Loc
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|C
argument_list|,
name|StrData
argument_list|,
name|ByteLength
argument_list|,
name|Wide
argument_list|,
name|Ty
argument_list|,
operator|&
name|Loc
argument_list|,
literal|1
argument_list|)
return|;
block|}
comment|/// \brief Construct an empty string literal.
specifier|static
name|StringLiteral
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned NumStrs
argument_list|)
block|;
name|llvm
operator|::
name|StringRef
name|getString
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|StringRef
argument_list|(
name|StrData
argument_list|,
name|ByteLength
argument_list|)
return|;
block|}
comment|// FIXME: These are deprecated, replace with StringRef.
specifier|const
name|char
operator|*
name|getStrData
argument_list|()
specifier|const
block|{
return|return
name|StrData
return|;
block|}
name|unsigned
name|getByteLength
argument_list|()
specifier|const
block|{
return|return
name|ByteLength
return|;
block|}
comment|/// \brief Sets the string data to the given string data.
name|void
name|setString
argument_list|(
argument|ASTContext&C
argument_list|,
argument|llvm::StringRef Str
argument_list|)
block|;
name|bool
name|isWide
argument_list|()
specifier|const
block|{
return|return
name|IsWide
return|;
block|}
name|void
name|setWide
argument_list|(
argument|bool W
argument_list|)
block|{
name|IsWide
operator|=
name|W
block|; }
name|bool
name|containsNonAsciiOrNull
argument_list|()
specifier|const
block|{
name|llvm
operator|::
name|StringRef
name|Str
operator|=
name|getString
argument_list|()
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|Str
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
operator|!
name|isascii
argument_list|(
name|Str
index|[
name|i
index|]
argument_list|)
operator|||
operator|!
name|Str
index|[
name|i
index|]
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getNumConcatenated - Get the number of string literal tokens that were
end_comment

begin_comment
comment|/// concatenated in translation phase #6 to form this string literal.
end_comment

begin_expr_stmt
name|unsigned
name|getNumConcatenated
argument_list|()
specifier|const
block|{
return|return
name|NumConcatenated
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|SourceLocation
name|getStrTokenLoc
argument_list|(
name|unsigned
name|TokNum
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|TokNum
operator|<
name|NumConcatenated
operator|&&
literal|"Invalid tok number"
argument_list|)
expr_stmt|;
return|return
name|TokLocs
index|[
name|TokNum
index|]
return|;
block|}
end_decl_stmt

begin_function
name|void
name|setStrTokenLoc
parameter_list|(
name|unsigned
name|TokNum
parameter_list|,
name|SourceLocation
name|L
parameter_list|)
block|{
name|assert
argument_list|(
name|TokNum
operator|<
name|NumConcatenated
operator|&&
literal|"Invalid tok number"
argument_list|)
expr_stmt|;
name|TokLocs
index|[
name|TokNum
index|]
operator|=
name|L
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
specifier|const
name|SourceLocation
modifier|*
name|tokloc_iterator
typedef|;
end_typedef

begin_expr_stmt
name|tokloc_iterator
name|tokloc_begin
argument_list|()
specifier|const
block|{
return|return
name|TokLocs
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|tokloc_iterator
name|tokloc_end
argument_list|()
specifier|const
block|{
return|return
name|TokLocs
operator|+
name|NumConcatenated
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|TokLocs
index|[
literal|0
index|]
argument_list|,
name|TokLocs
index|[
name|NumConcatenated
operator|-
literal|1
index|]
argument_list|)
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
name|StringLiteralClass
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|StringLiteral
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
comment|/// ParenExpr - This represents a parethesized expression, e.g. "(1)".  This
end_comment

begin_comment
comment|/// AST node is only formed if full location information is requested.
end_comment

begin_decl_stmt
name|class
name|ParenExpr
range|:
name|public
name|Expr
block|{
name|SourceLocation
name|L
block|,
name|R
block|;
name|Stmt
operator|*
name|Val
block|;
name|public
operator|:
name|ParenExpr
argument_list|(
argument|SourceLocation l
argument_list|,
argument|SourceLocation r
argument_list|,
argument|Expr *val
argument_list|)
operator|:
name|Expr
argument_list|(
name|ParenExprClass
argument_list|,
name|val
operator|->
name|getType
argument_list|()
argument_list|,
name|val
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|val
operator|->
name|isValueDependent
argument_list|()
argument_list|)
block|,
name|L
argument_list|(
name|l
argument_list|)
block|,
name|R
argument_list|(
name|r
argument_list|)
block|,
name|Val
argument_list|(
argument|val
argument_list|)
block|{}
comment|/// \brief Construct an empty parenthesized expression.
name|explicit
name|ParenExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ParenExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
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
name|Val
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
name|Val
operator|)
return|;
block|}
name|void
name|setSubExpr
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Val
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
argument_list|(
name|L
argument_list|,
name|R
argument_list|)
return|;
block|}
comment|/// \brief Get the location of the left parentheses '('.
name|SourceLocation
name|getLParen
argument_list|()
specifier|const
block|{
return|return
name|L
return|;
block|}
name|void
name|setLParen
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|L
operator|=
name|Loc
block|; }
comment|/// \brief Get the location of the right parentheses ')'.
name|SourceLocation
name|getRParen
argument_list|()
specifier|const
block|{
return|return
name|R
return|;
block|}
name|void
name|setRParen
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|R
operator|=
name|Loc
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
name|ParenExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ParenExpr *
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
end_decl_stmt

begin_comment
comment|/// UnaryOperator - This represents the unary-expression's (except sizeof and
end_comment

begin_comment
comment|/// alignof), the postinc/postdec operators from postfix-expression, and various
end_comment

begin_comment
comment|/// extensions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Notes on various nodes:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Real/Imag - These return the real/imag part of a complex operand.  If
end_comment

begin_comment
comment|///   applied to a non-complex value, the former returns its operand and the
end_comment

begin_comment
comment|///   later returns zero in the type of the operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// __builtin_offsetof(type, a.b[10]) is represented as a unary operator whose
end_comment

begin_comment
comment|///   subexpression is a compound literal with the various MemberExpr and
end_comment

begin_comment
comment|///   ArraySubscriptExpr's applied to it. (This is only used in C)
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|UnaryOperator
range|:
name|public
name|Expr
block|{
name|public
operator|:
comment|// Note that additions to this should also update the StmtVisitor class.
expr|enum
name|Opcode
block|{
name|PostInc
block|,
name|PostDec
block|,
comment|// [C99 6.5.2.4] Postfix increment and decrement operators
name|PreInc
block|,
name|PreDec
block|,
comment|// [C99 6.5.3.1] Prefix increment and decrement operators.
name|AddrOf
block|,
name|Deref
block|,
comment|// [C99 6.5.3.2] Address and indirection operators.
name|Plus
block|,
name|Minus
block|,
comment|// [C99 6.5.3.3] Unary arithmetic operators.
name|Not
block|,
name|LNot
block|,
comment|// [C99 6.5.3.3] Unary arithmetic operators.
name|Real
block|,
name|Imag
block|,
comment|// "__real expr"/"__imag expr" Extension.
name|Extension
block|,
comment|// __extension__ marker.
name|OffsetOf
comment|// __builtin_offsetof
block|}
block|;
name|private
operator|:
name|Stmt
operator|*
name|Val
block|;
name|Opcode
name|Opc
block|;
name|SourceLocation
name|Loc
block|;
name|public
operator|:
name|UnaryOperator
argument_list|(
argument|Expr *input
argument_list|,
argument|Opcode opc
argument_list|,
argument|QualType type
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|Expr
argument_list|(
name|UnaryOperatorClass
argument_list|,
name|type
argument_list|,
name|input
operator|->
name|isTypeDependent
argument_list|()
operator|&&
name|opc
operator|!=
name|OffsetOf
argument_list|,
name|input
operator|->
name|isValueDependent
argument_list|()
argument_list|)
block|,
name|Val
argument_list|(
name|input
argument_list|)
block|,
name|Opc
argument_list|(
name|opc
argument_list|)
block|,
name|Loc
argument_list|(
argument|l
argument_list|)
block|{}
comment|/// \brief Build an empty unary operator.
name|explicit
name|UnaryOperator
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|UnaryOperatorClass
argument_list|,
name|Empty
argument_list|)
block|,
name|Opc
argument_list|(
argument|AddrOf
argument_list|)
block|{ }
name|Opcode
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Opc
return|;
block|}
name|void
name|setOpcode
argument_list|(
argument|Opcode O
argument_list|)
block|{
name|Opc
operator|=
name|O
block|; }
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
name|Val
operator|)
return|;
block|}
name|void
name|setSubExpr
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Val
operator|=
name|E
block|; }
comment|/// getOperatorLoc - Return the location of the operator.
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
comment|/// isPostfix - Return true if this is a postfix operation, like x++.
specifier|static
name|bool
name|isPostfix
argument_list|(
argument|Opcode Op
argument_list|)
block|{
return|return
name|Op
operator|==
name|PostInc
operator|||
name|Op
operator|==
name|PostDec
return|;
block|}
comment|/// isPostfix - Return true if this is a prefix operation, like --x.
specifier|static
name|bool
name|isPrefix
argument_list|(
argument|Opcode Op
argument_list|)
block|{
return|return
name|Op
operator|==
name|PreInc
operator|||
name|Op
operator|==
name|PreDec
return|;
block|}
name|bool
name|isPrefix
argument_list|()
specifier|const
block|{
return|return
name|isPrefix
argument_list|(
name|Opc
argument_list|)
return|;
block|}
name|bool
name|isPostfix
argument_list|()
specifier|const
block|{
return|return
name|isPostfix
argument_list|(
name|Opc
argument_list|)
return|;
block|}
name|bool
name|isIncrementOp
argument_list|()
specifier|const
block|{
return|return
name|Opc
operator|==
name|PreInc
operator|||
name|Opc
operator|==
name|PostInc
return|;
block|}
name|bool
name|isIncrementDecrementOp
argument_list|()
specifier|const
block|{
return|return
name|Opc
operator|>=
name|PostInc
operator|&&
name|Opc
operator|<=
name|PreDec
return|;
block|}
name|bool
name|isOffsetOfOp
argument_list|()
specifier|const
block|{
return|return
name|Opc
operator|==
name|OffsetOf
return|;
block|}
specifier|static
name|bool
name|isArithmeticOp
argument_list|(
argument|Opcode Op
argument_list|)
block|{
return|return
name|Op
operator|>=
name|Plus
operator|&&
name|Op
operator|<=
name|LNot
return|;
block|}
name|bool
name|isArithmeticOp
argument_list|()
specifier|const
block|{
return|return
name|isArithmeticOp
argument_list|(
name|Opc
argument_list|)
return|;
block|}
comment|/// getOpcodeStr - Turn an Opcode enum value into the punctuation char it
comment|/// corresponds to, e.g. "sizeof" or "[pre]++"
specifier|static
specifier|const
name|char
operator|*
name|getOpcodeStr
argument_list|(
argument|Opcode Op
argument_list|)
block|;
comment|/// \brief Retrieve the unary opcode that corresponds to the given
comment|/// overloaded operator.
specifier|static
name|Opcode
name|getOverloadedOpcode
argument_list|(
argument|OverloadedOperatorKind OO
argument_list|,
argument|bool Postfix
argument_list|)
block|;
comment|/// \brief Retrieve the overloaded operator kind that corresponds to
comment|/// the given unary opcode.
specifier|static
name|OverloadedOperatorKind
name|getOverloadedOperator
argument_list|(
argument|Opcode Opc
argument_list|)
block|;
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isPostfix
argument_list|()
condition|)
return|return
name|SourceRange
argument_list|(
name|Val
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|Loc
argument_list|)
return|;
else|else
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|,
name|Val
operator|->
name|getLocEnd
argument_list|()
argument_list|)
return|;
block|}
name|virtual
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
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
name|UnaryOperatorClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const UnaryOperator *
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
end_decl_stmt

begin_comment
comment|/// OffsetOfExpr - [C99 7.17] - This represents an expression of the form
end_comment

begin_comment
comment|/// offsetof(record-type, member-designator). For example, given:
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// struct S {
end_comment

begin_comment
comment|///   float f;
end_comment

begin_comment
comment|///   double d;
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// struct T {
end_comment

begin_comment
comment|///   int i;
end_comment

begin_comment
comment|///   struct S s[10];
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|/// we can represent and evaluate the expression @c offsetof(struct T, s[2].d).
end_comment

begin_decl_stmt
name|class
name|OffsetOfExpr
range|:
name|public
name|Expr
block|{
name|public
operator|:
comment|// __builtin_offsetof(type, identifier(.identifier|[expr])*)
name|class
name|OffsetOfNode
block|{
name|public
operator|:
comment|/// \brief The kind of offsetof node we have.
expr|enum
name|Kind
block|{
comment|/// \brief An index into an array.
name|Array
operator|=
literal|0x00
block|,
comment|/// \brief A field.
name|Field
operator|=
literal|0x01
block|,
comment|/// \brief A field in a dependent type, known only by its name.
name|Identifier
operator|=
literal|0x02
block|,
comment|/// \brief An implicit indirection through a C++ base class, when the
comment|/// field found is in a base class.
name|Base
operator|=
literal|0x03
block|}
block|;
name|private
operator|:
expr|enum
block|{
name|MaskBits
operator|=
literal|2
block|,
name|Mask
operator|=
literal|0x03
block|}
block|;
comment|/// \brief The source range that covers this part of the designator.
name|SourceRange
name|Range
block|;
comment|/// \brief The data describing the designator, which comes in three
comment|/// different forms, depending on the lower two bits.
comment|///   - An unsigned index into the array of Expr*'s stored after this node
comment|///     in memory, for [constant-expression] designators.
comment|///   - A FieldDecl*, for references to a known field.
comment|///   - An IdentifierInfo*, for references to a field with a given name
comment|///     when the class type is dependent.
comment|///   - A CXXBaseSpecifier*, for references that look at a field in a
comment|///     base class.
name|uintptr_t
name|Data
block|;
name|public
operator|:
comment|/// \brief Create an offsetof node that refers to an array element.
name|OffsetOfNode
argument_list|(
argument|SourceLocation LBracketLoc
argument_list|,
argument|unsigned Index
argument_list|,
argument|SourceLocation RBracketLoc
argument_list|)
operator|:
name|Range
argument_list|(
name|LBracketLoc
argument_list|,
name|RBracketLoc
argument_list|)
block|,
name|Data
argument_list|(
argument|(Index<<
literal|2
argument|) | Array
argument_list|)
block|{ }
comment|/// \brief Create an offsetof node that refers to a field.
name|OffsetOfNode
argument_list|(
argument|SourceLocation DotLoc
argument_list|,
argument|FieldDecl *Field
argument_list|,
argument|SourceLocation NameLoc
argument_list|)
operator|:
name|Range
argument_list|(
name|DotLoc
operator|.
name|isValid
argument_list|()
operator|?
name|DotLoc
operator|:
name|NameLoc
argument_list|,
name|NameLoc
argument_list|)
block|,
name|Data
argument_list|(
argument|reinterpret_cast<uintptr_t>(Field) | OffsetOfNode::Field
argument_list|)
block|{ }
comment|/// \brief Create an offsetof node that refers to an identifier.
name|OffsetOfNode
argument_list|(
argument|SourceLocation DotLoc
argument_list|,
argument|IdentifierInfo *Name
argument_list|,
argument|SourceLocation NameLoc
argument_list|)
operator|:
name|Range
argument_list|(
name|DotLoc
operator|.
name|isValid
argument_list|()
operator|?
name|DotLoc
operator|:
name|NameLoc
argument_list|,
name|NameLoc
argument_list|)
block|,
name|Data
argument_list|(
argument|reinterpret_cast<uintptr_t>(Name) | Identifier
argument_list|)
block|{ }
comment|/// \brief Create an offsetof node that refers into a C++ base class.
name|explicit
name|OffsetOfNode
argument_list|(
specifier|const
name|CXXBaseSpecifier
operator|*
name|Base
argument_list|)
operator|:
name|Range
argument_list|()
block|,
name|Data
argument_list|(
argument|reinterpret_cast<uintptr_t>(Base) | OffsetOfNode::Base
argument_list|)
block|{}
comment|/// \brief Determine what kind of offsetof node this is.
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Kind
operator|>
operator|(
name|Data
operator|&
name|Mask
operator|)
return|;
block|}
comment|/// \brief For an array element node, returns the index into the array
comment|/// of expressions.
name|unsigned
name|getArrayExprIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Array
argument_list|)
block|;
return|return
name|Data
operator|>>
literal|2
return|;
block|}
comment|/// \brief For a field offsetof node, returns the field.
name|FieldDecl
operator|*
name|getField
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Field
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|FieldDecl
operator|*
operator|>
operator|(
name|Data
operator|&
operator|~
operator|(
name|uintptr_t
operator|)
name|Mask
operator|)
return|;
block|}
comment|/// \brief For a field or identifier offsetof node, returns the name of
comment|/// the field.
name|IdentifierInfo
operator|*
name|getFieldName
argument_list|()
specifier|const
block|;
comment|/// \brief For a base class node, returns the base specifier.
name|CXXBaseSpecifier
operator|*
name|getBase
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Base
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|CXXBaseSpecifier
operator|*
operator|>
operator|(
name|Data
operator|&
operator|~
operator|(
name|uintptr_t
operator|)
name|Mask
operator|)
return|;
block|}
comment|/// \brief Retrieve the source range that covers this offsetof node.
comment|///
comment|/// For an array element node, the source range contains the locations of
comment|/// the square brackets. For a field or identifier node, the source range
comment|/// contains the location of the period (if there is one) and the
comment|/// identifier.
name|SourceRange
name|getRange
argument_list|()
specifier|const
block|{
return|return
name|Range
return|;
block|}
expr|}
block|;
name|private
operator|:
name|SourceLocation
name|OperatorLoc
block|,
name|RParenLoc
block|;
comment|// Base type;
name|TypeSourceInfo
operator|*
name|TSInfo
block|;
comment|// Number of sub-components (i.e. instances of OffsetOfNode).
name|unsigned
name|NumComps
block|;
comment|// Number of sub-expressions (i.e. array subscript expressions).
name|unsigned
name|NumExprs
block|;
name|OffsetOfExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|QualType type
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|TypeSourceInfo *tsi
argument_list|,
argument|OffsetOfNode* compsPtr
argument_list|,
argument|unsigned numComps
argument_list|,
argument|Expr** exprsPtr
argument_list|,
argument|unsigned numExprs
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|;
name|explicit
name|OffsetOfExpr
argument_list|(
argument|unsigned numComps
argument_list|,
argument|unsigned numExprs
argument_list|)
operator|:
name|Expr
argument_list|(
name|OffsetOfExprClass
argument_list|,
name|EmptyShell
argument_list|()
argument_list|)
block|,
name|TSInfo
argument_list|(
literal|0
argument_list|)
block|,
name|NumComps
argument_list|(
name|numComps
argument_list|)
block|,
name|NumExprs
argument_list|(
argument|numExprs
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|OffsetOfExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|QualType type
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|TypeSourceInfo *tsi
argument_list|,
argument|OffsetOfNode* compsPtr
argument_list|,
argument|unsigned numComps
argument_list|,
argument|Expr** exprsPtr
argument_list|,
argument|unsigned numExprs
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|;
specifier|static
name|OffsetOfExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned NumComps
argument_list|,
argument|unsigned NumExprs
argument_list|)
block|;
comment|/// getOperatorLoc - Return the location of the operator.
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
comment|/// \brief Return the location of the right parentheses.
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
argument|SourceLocation R
argument_list|)
block|{
name|RParenLoc
operator|=
name|R
block|; }
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|TSInfo
return|;
block|}
name|void
name|setTypeSourceInfo
argument_list|(
argument|TypeSourceInfo *tsi
argument_list|)
block|{
name|TSInfo
operator|=
name|tsi
block|;   }
specifier|const
name|OffsetOfNode
operator|&
name|getComponent
argument_list|(
argument|unsigned Idx
argument_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|NumComps
operator|&&
literal|"Subscript out of range"
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|OffsetOfNode
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
index|[
name|Idx
index|]
return|;
block|}
name|void
name|setComponent
argument_list|(
argument|unsigned Idx
argument_list|,
argument|OffsetOfNode ON
argument_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|NumComps
operator|&&
literal|"Subscript out of range"
argument_list|)
block|;
name|reinterpret_cast
operator|<
name|OffsetOfNode
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
index|[
name|Idx
index|]
operator|=
name|ON
block|;   }
name|unsigned
name|getNumComponents
argument_list|()
specifier|const
block|{
return|return
name|NumComps
return|;
block|}
name|Expr
operator|*
name|getIndexExpr
argument_list|(
argument|unsigned Idx
argument_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|NumExprs
operator|&&
literal|"Subscript out of range"
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|OffsetOfNode
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
operator|+
name|NumComps
operator|)
index|[
name|Idx
index|]
return|;
block|}
name|void
name|setIndexExpr
argument_list|(
argument|unsigned Idx
argument_list|,
argument|Expr* E
argument_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|NumComps
operator|&&
literal|"Subscript out of range"
argument_list|)
block|;
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|OffsetOfNode
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
operator|+
name|NumComps
operator|)
index|[
name|Idx
index|]
operator|=
name|E
block|;   }
name|unsigned
name|getNumExpressions
argument_list|()
specifier|const
block|{
return|return
name|NumExprs
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
name|OffsetOfExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OffsetOfExpr *
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
comment|/// SizeOfAlignOfExpr - [C99 6.5.3.4] - This is for sizeof/alignof, both of
comment|/// types and expressions.
name|class
name|SizeOfAlignOfExpr
operator|:
name|public
name|Expr
block|{
name|bool
name|isSizeof
operator|:
literal|1
block|;
comment|// true if sizeof, false if alignof.
name|bool
name|isType
operator|:
literal|1
block|;
comment|// true if operand is a type, false if an expression
expr|union
block|{
name|TypeSourceInfo
operator|*
name|Ty
block|;
name|Stmt
operator|*
name|Ex
block|;   }
name|Argument
block|;
name|SourceLocation
name|OpLoc
block|,
name|RParenLoc
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
name|SizeOfAlignOfExpr
argument_list|(
argument|bool issizeof
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|QualType resultType
argument_list|,
argument|SourceLocation op
argument_list|,
argument|SourceLocation rp
argument_list|)
operator|:
name|Expr
argument_list|(
name|SizeOfAlignOfExprClass
argument_list|,
name|resultType
argument_list|,
name|false
argument_list|,
comment|// Never type-dependent (C++ [temp.dep.expr]p3).
comment|// Value-dependent if the argument is type-dependent.
name|TInfo
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
argument_list|)
block|,
name|isSizeof
argument_list|(
name|issizeof
argument_list|)
block|,
name|isType
argument_list|(
name|true
argument_list|)
block|,
name|OpLoc
argument_list|(
name|op
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|rp
argument_list|)
block|{
name|Argument
operator|.
name|Ty
operator|=
name|TInfo
block|;   }
name|SizeOfAlignOfExpr
argument_list|(
argument|bool issizeof
argument_list|,
argument|Expr *E
argument_list|,
argument|QualType resultType
argument_list|,
argument|SourceLocation op
argument_list|,
argument|SourceLocation rp
argument_list|)
operator|:
name|Expr
argument_list|(
name|SizeOfAlignOfExprClass
argument_list|,
name|resultType
argument_list|,
name|false
argument_list|,
comment|// Never type-dependent (C++ [temp.dep.expr]p3).
comment|// Value-dependent if the argument is type-dependent.
name|E
operator|->
name|isTypeDependent
argument_list|()
argument_list|)
block|,
name|isSizeof
argument_list|(
name|issizeof
argument_list|)
block|,
name|isType
argument_list|(
name|false
argument_list|)
block|,
name|OpLoc
argument_list|(
name|op
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|rp
argument_list|)
block|{
name|Argument
operator|.
name|Ex
operator|=
name|E
block|;   }
comment|/// \brief Construct an empty sizeof/alignof expression.
name|explicit
name|SizeOfAlignOfExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|SizeOfAlignOfExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|bool
name|isSizeOf
argument_list|()
specifier|const
block|{
return|return
name|isSizeof
return|;
block|}
name|void
name|setSizeof
argument_list|(
argument|bool S
argument_list|)
block|{
name|isSizeof
operator|=
name|S
block|; }
name|bool
name|isArgumentType
argument_list|()
specifier|const
block|{
return|return
name|isType
return|;
block|}
name|QualType
name|getArgumentType
argument_list|()
specifier|const
block|{
return|return
name|getArgumentTypeInfo
argument_list|()
operator|->
name|getType
argument_list|()
return|;
block|}
name|TypeSourceInfo
operator|*
name|getArgumentTypeInfo
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isArgumentType
argument_list|()
operator|&&
literal|"calling getArgumentType() when arg is expr"
argument_list|)
block|;
return|return
name|Argument
operator|.
name|Ty
return|;
block|}
name|Expr
operator|*
name|getArgumentExpr
argument_list|()
block|{
name|assert
argument_list|(
operator|!
name|isArgumentType
argument_list|()
operator|&&
literal|"calling getArgumentExpr() when arg is type"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|Argument
operator|.
name|Ex
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArgumentExpr
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|SizeOfAlignOfExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getArgumentExpr
argument_list|()
return|;
block|}
name|void
name|setArgument
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Argument
operator|.
name|Ex
operator|=
name|E
block|;
name|isType
operator|=
name|false
block|; }
name|void
name|setArgument
argument_list|(
argument|TypeSourceInfo *TInfo
argument_list|)
block|{
name|Argument
operator|.
name|Ty
operator|=
name|TInfo
block|;
name|isType
operator|=
name|true
block|;   }
comment|/// Gets the argument type, or the type of the argument expression, whichever
comment|/// is appropriate.
name|QualType
name|getTypeOfArgument
argument_list|()
specifier|const
block|{
return|return
name|isArgumentType
argument_list|()
condition|?
name|getArgumentType
argument_list|()
else|:
name|getArgumentExpr
argument_list|()
operator|->
name|getType
argument_list|()
return|;
block|}
name|SourceLocation
name|getOperatorLoc
argument_list|()
specifier|const
block|{
return|return
name|OpLoc
return|;
block|}
name|void
name|setOperatorLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|OpLoc
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
name|OpLoc
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
name|SizeOfAlignOfExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SizeOfAlignOfExpr *
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
comment|//===----------------------------------------------------------------------===//
comment|// Postfix Operators.
comment|//===----------------------------------------------------------------------===//
comment|/// ArraySubscriptExpr - [C99 6.5.2.1] Array Subscripting.
name|class
name|ArraySubscriptExpr
operator|:
name|public
name|Expr
block|{   enum
block|{
name|LHS
block|,
name|RHS
block|,
name|END_EXPR
operator|=
literal|2
block|}
block|;
name|Stmt
operator|*
name|SubExprs
index|[
name|END_EXPR
index|]
block|;
name|SourceLocation
name|RBracketLoc
block|;
name|public
operator|:
name|ArraySubscriptExpr
argument_list|(
argument|Expr *lhs
argument_list|,
argument|Expr *rhs
argument_list|,
argument|QualType t
argument_list|,
argument|SourceLocation rbracketloc
argument_list|)
operator|:
name|Expr
argument_list|(
name|ArraySubscriptExprClass
argument_list|,
name|t
argument_list|,
name|lhs
operator|->
name|isTypeDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|lhs
operator|->
name|isValueDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isValueDependent
argument_list|()
argument_list|)
block|,
name|RBracketLoc
argument_list|(
argument|rbracketloc
argument_list|)
block|{
name|SubExprs
index|[
name|LHS
index|]
operator|=
name|lhs
block|;
name|SubExprs
index|[
name|RHS
index|]
operator|=
name|rhs
block|;   }
comment|/// \brief Create an empty array subscript expression.
name|explicit
name|ArraySubscriptExpr
argument_list|(
argument|EmptyShell Shell
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ArraySubscriptExprClass
argument_list|,
argument|Shell
argument_list|)
block|{ }
comment|/// An array access can be written A[4] or 4[A] (both are equivalent).
comment|/// - getBase() and getIdx() always present the normalized view: A[4].
comment|///    In this case getBase() returns "A" and getIdx() returns "4".
comment|/// - getLHS() and getRHS() present the syntactic view. e.g. for
comment|///    4[A] getLHS() returns "4".
comment|/// Note: Because vector element access is also written A[4] we must
comment|/// predicate the format conversion in getBase and getIdx only on the
comment|/// the type of the RHS, as it is possible for the LHS to be a vector of
comment|/// integer type
name|Expr
operator|*
name|getLHS
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|LHS
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getLHS
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|LHS
index|]
operator|)
return|;
block|}
name|void
name|setLHS
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|LHS
index|]
operator|=
name|E
block|; }
name|Expr
operator|*
name|getRHS
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|RHS
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getRHS
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|RHS
index|]
operator|)
return|;
block|}
name|void
name|setRHS
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|RHS
index|]
operator|=
name|E
block|; }
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
name|getRHS
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|isIntegerType
argument_list|()
condition|?
name|getLHS
argument_list|()
else|:
name|getRHS
argument_list|()
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
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|getRHS
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|isIntegerType
argument_list|()
condition|?
name|getLHS
argument_list|()
else|:
name|getRHS
argument_list|()
operator|)
return|;
block|}
name|Expr
operator|*
name|getIdx
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|getRHS
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|isIntegerType
argument_list|()
condition|?
name|getRHS
argument_list|()
else|:
name|getLHS
argument_list|()
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getIdx
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|getRHS
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|isIntegerType
argument_list|()
condition|?
name|getRHS
argument_list|()
else|:
name|getLHS
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
name|getLHS
argument_list|()
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|RBracketLoc
argument_list|)
return|;
block|}
name|SourceLocation
name|getRBracketLoc
argument_list|()
specifier|const
block|{
return|return
name|RBracketLoc
return|;
block|}
name|void
name|setRBracketLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|RBracketLoc
operator|=
name|L
block|; }
name|virtual
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
block|{
return|return
name|getBase
argument_list|()
operator|->
name|getExprLoc
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
name|ArraySubscriptExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ArraySubscriptExpr *
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
comment|/// CallExpr - Represents a function call (C99 6.5.2.2, C++ [expr.call]).
comment|/// CallExpr itself represents a normal function call, e.g., "f(x, 2)",
comment|/// while its subclasses may represent alternative syntax that (semantically)
comment|/// results in a function call. For example, CXXOperatorCallExpr is
comment|/// a subclass for overloaded operator calls that use operator syntax, e.g.,
comment|/// "str1 + str2" to resolve to a function call.
name|class
name|CallExpr
operator|:
name|public
name|Expr
block|{   enum
block|{
name|FN
operator|=
literal|0
block|,
name|ARGS_START
operator|=
literal|1
block|}
block|;
name|Stmt
operator|*
operator|*
name|SubExprs
block|;
name|unsigned
name|NumArgs
block|;
name|SourceLocation
name|RParenLoc
block|;
name|protected
operator|:
comment|// This version of the constructor is for derived classes.
name|CallExpr
argument_list|(
argument|ASTContext& C
argument_list|,
argument|StmtClass SC
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
name|public
operator|:
name|CallExpr
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
block|;
comment|/// \brief Build an empty call expression.
name|CallExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|StmtClass SC
argument_list|,
argument|EmptyShell Empty
argument_list|)
block|;
operator|~
name|CallExpr
argument_list|()
block|{}
specifier|const
name|Expr
operator|*
name|getCallee
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|FN
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getCallee
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|FN
index|]
operator|)
return|;
block|}
name|void
name|setCallee
argument_list|(
argument|Expr *F
argument_list|)
block|{
name|SubExprs
index|[
name|FN
index|]
operator|=
name|F
block|; }
name|Decl
operator|*
name|getCalleeDecl
argument_list|()
block|;
specifier|const
name|Decl
operator|*
name|getCalleeDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|CallExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getCalleeDecl
argument_list|()
return|;
block|}
comment|/// \brief If the callee is a FunctionDecl, return it. Otherwise return 0.
name|FunctionDecl
operator|*
name|getDirectCallee
argument_list|()
block|;
specifier|const
name|FunctionDecl
operator|*
name|getDirectCallee
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|CallExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getDirectCallee
argument_list|()
return|;
block|}
comment|/// getNumArgs - Return the number of actual arguments to this call.
comment|///
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
name|SubExprs
index|[
name|Arg
operator|+
name|ARGS_START
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
name|SubExprs
index|[
name|Arg
operator|+
name|ARGS_START
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
name|SubExprs
index|[
name|Arg
operator|+
name|ARGS_START
index|]
operator|=
name|ArgExpr
block|;   }
comment|/// setNumArgs - This changes the number of arguments present in this call.
comment|/// Any orphaned expressions are deleted by this, and any new operands are set
comment|/// to null.
name|void
name|setNumArgs
argument_list|(
argument|ASTContext& C
argument_list|,
argument|unsigned NumArgs
argument_list|)
block|;
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
name|SubExprs
operator|+
name|ARGS_START
return|;
block|}
name|arg_iterator
name|arg_end
argument_list|()
block|{
return|return
name|SubExprs
operator|+
name|ARGS_START
operator|+
name|getNumArgs
argument_list|()
return|;
block|}
name|const_arg_iterator
name|arg_begin
argument_list|()
specifier|const
block|{
return|return
name|SubExprs
operator|+
name|ARGS_START
return|;
block|}
name|const_arg_iterator
name|arg_end
argument_list|()
specifier|const
block|{
return|return
name|SubExprs
operator|+
name|ARGS_START
operator|+
name|getNumArgs
argument_list|()
return|;
block|}
comment|/// getNumCommas - Return the number of commas that must have been present in
comment|/// this function call.
name|unsigned
name|getNumCommas
argument_list|()
specifier|const
block|{
return|return
name|NumArgs
operator|?
name|NumArgs
operator|-
literal|1
operator|:
literal|0
return|;
block|}
comment|/// isBuiltinCall - If this is a call to a builtin, return the builtin ID.  If
comment|/// not, return 0.
name|unsigned
name|isBuiltinCall
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getCallReturnType - Get the return type of the call expr. This is not
end_comment

begin_comment
comment|/// always the type of the expr itself, if the return type is a reference
end_comment

begin_comment
comment|/// type.
end_comment

begin_expr_stmt
name|QualType
name|getCallReturnType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setRParenLoc
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|RParenLoc
operator|=
name|L
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|getCallee
argument_list|()
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|RParenLoc
argument_list|)
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
operator|>=
name|firstCallExprConstant
operator|&&
name|T
operator|->
name|getStmtClass
argument_list|()
operator|<=
name|lastCallExprConstant
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|CallExpr
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
comment|/// MemberExpr - [C99 6.5.2.3] Structure and Union Members.  X->F and X.F.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|MemberExpr
range|:
name|public
name|Expr
block|{
comment|/// Extra data stored in some member expressions.
block|struct
name|MemberNameQualifier
operator|:
name|public
name|NameQualifier
block|{
name|DeclAccessPair
name|FoundDecl
block|;   }
block|;
comment|/// Base - the expression for the base pointer or structure references.  In
comment|/// X.F, this is "X".
name|Stmt
operator|*
name|Base
block|;
comment|/// MemberDecl - This is the decl being referenced by the field/member name.
comment|/// In X.F, this is the decl referenced by F.
name|ValueDecl
operator|*
name|MemberDecl
block|;
comment|/// MemberLoc - This is the location of the member name.
name|SourceLocation
name|MemberLoc
block|;
comment|/// IsArrow - True if this is "X->F", false if this is "X.F".
name|bool
name|IsArrow
operator|:
literal|1
block|;
comment|/// \brief True if this member expression used a nested-name-specifier to
comment|/// refer to the member, e.g., "x->Base::f", or found its member via a using
comment|/// declaration.  When true, a MemberNameQualifier
comment|/// structure is allocated immediately after the MemberExpr.
name|bool
name|HasQualifierOrFoundDecl
operator|:
literal|1
block|;
comment|/// \brief True if this member expression specified a template argument list
comment|/// explicitly, e.g., x->f<int>. When true, an ExplicitTemplateArgumentList
comment|/// structure (and its TemplateArguments) are allocated immediately after
comment|/// the MemberExpr or, if the member expression also has a qualifier, after
comment|/// the MemberNameQualifier structure.
name|bool
name|HasExplicitTemplateArgumentList
operator|:
literal|1
block|;
comment|/// \brief Retrieve the qualifier that preceded the member name, if any.
name|MemberNameQualifier
operator|*
name|getMemberQualifier
argument_list|()
block|{
name|assert
argument_list|(
name|HasQualifierOrFoundDecl
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|MemberNameQualifier
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieve the qualifier that preceded the member name, if any.
specifier|const
name|MemberNameQualifier
operator|*
name|getMemberQualifier
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|MemberExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMemberQualifier
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the explicit template argument list that followed the
comment|/// member template name, if any.
name|ExplicitTemplateArgumentList
operator|*
name|getExplicitTemplateArgumentList
argument_list|()
block|{
if|if
condition|(
operator|!
name|HasExplicitTemplateArgumentList
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|HasQualifierOrFoundDecl
condition|)
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
end_decl_stmt

begin_return
return|return
name|reinterpret_cast
operator|<
name|ExplicitTemplateArgumentList
operator|*
operator|>
operator|(
name|getMemberQualifier
argument_list|()
operator|+
literal|1
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the explicit template argument list that followed the
end_comment

begin_comment
comment|/// member template name, if any.
end_comment

begin_expr_stmt
unit|const
name|ExplicitTemplateArgumentList
operator|*
name|getExplicitTemplateArgumentList
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|MemberExpr
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
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|MemberExpr
argument_list|(
argument|Expr *base
argument_list|,
argument|bool isarrow
argument_list|,
argument|ValueDecl *memberdecl
argument_list|,
argument|SourceLocation l
argument_list|,
argument|QualType ty
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|Expr
argument_list|(
name|MemberExprClass
argument_list|,
name|ty
argument_list|,
name|base
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|base
operator|->
name|isValueDependent
argument_list|()
argument_list|)
operator|,
name|Base
argument_list|(
name|base
argument_list|)
operator|,
name|MemberDecl
argument_list|(
name|memberdecl
argument_list|)
operator|,
name|MemberLoc
argument_list|(
name|l
argument_list|)
operator|,
name|IsArrow
argument_list|(
name|isarrow
argument_list|)
operator|,
name|HasQualifierOrFoundDecl
argument_list|(
name|false
argument_list|)
operator|,
name|HasExplicitTemplateArgumentList
argument_list|(
argument|false
argument_list|)
block|{}
specifier|static
name|MemberExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr *base
argument_list|,
argument|bool isarrow
argument_list|,
argument|NestedNameSpecifier *qual
argument_list|,
argument|SourceRange qualrange
argument_list|,
argument|ValueDecl *memberdecl
argument_list|,
argument|DeclAccessPair founddecl
argument_list|,
argument|SourceLocation l
argument_list|,
argument|const TemplateArgumentListInfo *targs
argument_list|,
argument|QualType ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|setBase
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
name|Base
operator|=
name|E
expr_stmt|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the member declaration to which this expression refers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The returned declaration will either be a FieldDecl or (in C++)
end_comment

begin_comment
comment|/// a CXXMethodDecl.
end_comment

begin_expr_stmt
name|ValueDecl
operator|*
name|getMemberDecl
argument_list|()
specifier|const
block|{
return|return
name|MemberDecl
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setMemberDecl
parameter_list|(
name|ValueDecl
modifier|*
name|D
parameter_list|)
block|{
name|MemberDecl
operator|=
name|D
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Retrieves the declaration found by lookup.
end_comment

begin_expr_stmt
name|DeclAccessPair
name|getFoundDecl
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasQualifierOrFoundDecl
condition|)
return|return
name|DeclAccessPair
operator|::
name|make
argument_list|(
name|getMemberDecl
argument_list|()
argument_list|,
name|getMemberDecl
argument_list|()
operator|->
name|getAccess
argument_list|()
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|getMemberQualifier
argument_list|()
operator|->
name|FoundDecl
return|;
end_return

begin_comment
unit|}
comment|/// \brief Determines whether this member expression actually had
end_comment

begin_comment
comment|/// a C++ nested-name-specifier prior to the name of the member, e.g.,
end_comment

begin_comment
comment|/// x->Base::foo.
end_comment

begin_macro
unit|bool
name|hasQualifier
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|getQualifier
argument_list|()
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief If the member name was qualified, retrieves the source range of
end_comment

begin_comment
comment|/// the nested-name-specifier that precedes the member name. Otherwise,
end_comment

begin_comment
comment|/// returns an empty source range.
end_comment

begin_expr_stmt
name|SourceRange
name|getQualifierRange
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasQualifierOrFoundDecl
condition|)
return|return
name|SourceRange
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getMemberQualifier
argument_list|()
operator|->
name|Range
return|;
end_return

begin_comment
unit|}
comment|/// \brief If the member name was qualified, retrieves the
end_comment

begin_comment
comment|/// nested-name-specifier that precedes the member name. Otherwise, returns
end_comment

begin_comment
comment|/// NULL.
end_comment

begin_expr_stmt
unit|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasQualifierOrFoundDecl
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|getMemberQualifier
argument_list|()
operator|->
name|NNS
return|;
end_return

begin_comment
unit|}
comment|/// \brief Determines whether this member expression actually had a C++
end_comment

begin_comment
comment|/// template argument list explicitly specified, e.g., x.f<int>.
end_comment

begin_macro
unit|bool
name|hasExplicitTemplateArgumentList
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|HasExplicitTemplateArgumentList
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Copies the template arguments (if present) into the given
end_comment

begin_comment
comment|/// structure.
end_comment

begin_decl_stmt
name|void
name|copyTemplateArgumentsInto
argument_list|(
name|TemplateArgumentListInfo
operator|&
name|List
argument_list|)
decl|const
block|{
if|if
condition|(
name|hasExplicitTemplateArgumentList
argument_list|()
condition|)
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|copyInto
argument_list|(
name|List
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the location of the left angle bracket following the
end_comment

begin_comment
comment|/// member name ('<'), if any.
end_comment

begin_expr_stmt
name|SourceLocation
name|getLAngleLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasExplicitTemplateArgumentList
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|LAngleLoc
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the template arguments provided as part of this
end_comment

begin_comment
comment|/// template-id.
end_comment

begin_expr_stmt
unit|const
name|TemplateArgumentLoc
operator|*
name|getTemplateArgs
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasExplicitTemplateArgumentList
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|getTemplateArgs
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the number of template arguments provided as part of this
end_comment

begin_comment
comment|/// template-id.
end_comment

begin_macro
unit|unsigned
name|getNumTemplateArgs
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
operator|!
name|HasExplicitTemplateArgumentList
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|NumTemplateArgs
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the location of the right angle bracket following the
end_comment

begin_comment
comment|/// template arguments ('>').
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
name|HasExplicitTemplateArgumentList
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getExplicitTemplateArgumentList
argument_list|()
operator|->
name|RAngleLoc
return|;
end_return

begin_macro
unit|}    bool
name|isArrow
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|IsArrow
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setArrow
parameter_list|(
name|bool
name|A
parameter_list|)
block|{
name|IsArrow
operator|=
name|A
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getMemberLoc - Return the location of the "member", in X->F, it is the
end_comment

begin_comment
comment|/// location of 'F'.
end_comment

begin_expr_stmt
name|SourceLocation
name|getMemberLoc
argument_list|()
specifier|const
block|{
return|return
name|MemberLoc
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setMemberLoc
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|MemberLoc
operator|=
name|L
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
comment|// If we have an implicit base (like a C++ implicit this),
comment|// make sure not to return its location
name|SourceLocation
name|EndLoc
operator|=
name|MemberLoc
block|;
if|if
condition|(
name|HasExplicitTemplateArgumentList
condition|)
name|EndLoc
operator|=
name|getRAngleLoc
argument_list|()
expr_stmt|;
name|SourceLocation
name|BaseLoc
operator|=
name|getBase
argument_list|()
operator|->
name|getLocStart
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|BaseLoc
operator|.
name|isInvalid
argument_list|()
condition|)
return|return
name|SourceRange
argument_list|(
name|MemberLoc
argument_list|,
name|EndLoc
argument_list|)
return|;
end_if

begin_return
return|return
name|SourceRange
argument_list|(
name|BaseLoc
argument_list|,
name|EndLoc
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    virtual
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
block|{
return|return
name|MemberLoc
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
name|MemberExprClass
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|MemberExpr
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
comment|/// CompoundLiteralExpr - [C99 6.5.2.5]
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|CompoundLiteralExpr
range|:
name|public
name|Expr
block|{
comment|/// LParenLoc - If non-null, this is the location of the left paren in a
comment|/// compound literal like "(int){4}".  This can be null if this is a
comment|/// synthesized compound expression.
name|SourceLocation
name|LParenLoc
block|;
comment|/// The type as written.  This can be an incomplete array type, in
comment|/// which case the actual expression type will be different.
name|TypeSourceInfo
operator|*
name|TInfo
block|;
name|Stmt
operator|*
name|Init
block|;
name|bool
name|FileScope
block|;
name|public
operator|:
comment|// FIXME: Can compound literals be value-dependent?
name|CompoundLiteralExpr
argument_list|(
argument|SourceLocation lparenloc
argument_list|,
argument|TypeSourceInfo *tinfo
argument_list|,
argument|QualType T
argument_list|,
argument|Expr *init
argument_list|,
argument|bool fileScope
argument_list|)
operator|:
name|Expr
argument_list|(
name|CompoundLiteralExprClass
argument_list|,
name|T
argument_list|,
name|tinfo
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|false
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|lparenloc
argument_list|)
block|,
name|TInfo
argument_list|(
name|tinfo
argument_list|)
block|,
name|Init
argument_list|(
name|init
argument_list|)
block|,
name|FileScope
argument_list|(
argument|fileScope
argument_list|)
block|{}
comment|/// \brief Construct an empty compound literal.
name|explicit
name|CompoundLiteralExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|CompoundLiteralExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
specifier|const
name|Expr
operator|*
name|getInitializer
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Init
operator|)
return|;
block|}
name|Expr
operator|*
name|getInitializer
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Init
operator|)
return|;
block|}
name|void
name|setInitializer
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Init
operator|=
name|E
block|; }
name|bool
name|isFileScope
argument_list|()
specifier|const
block|{
return|return
name|FileScope
return|;
block|}
name|void
name|setFileScope
argument_list|(
argument|bool FS
argument_list|)
block|{
name|FileScope
operator|=
name|FS
block|; }
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
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|TInfo
return|;
block|}
name|void
name|setTypeSourceInfo
argument_list|(
argument|TypeSourceInfo* tinfo
argument_list|)
block|{
name|TInfo
operator|=
name|tinfo
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
comment|// FIXME: Init should never be null.
if|if
condition|(
operator|!
name|Init
condition|)
return|return
name|SourceRange
argument_list|()
return|;
if|if
condition|(
name|LParenLoc
operator|.
name|isInvalid
argument_list|()
condition|)
return|return
name|Init
operator|->
name|getSourceRange
argument_list|()
return|;
end_decl_stmt

begin_return
return|return
name|SourceRange
argument_list|(
name|LParenLoc
argument_list|,
name|Init
operator|->
name|getLocEnd
argument_list|()
argument_list|)
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
name|CompoundLiteralExprClass
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|CompoundLiteralExpr
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
comment|/// CastExpr - Base class for type casts, including both implicit
end_comment

begin_comment
comment|/// casts (ImplicitCastExpr) and explicit casts that have some
end_comment

begin_comment
comment|/// representation in the source code (ExplicitCastExpr's derived
end_comment

begin_comment
comment|/// classes).
end_comment

begin_decl_stmt
name|class
name|CastExpr
range|:
name|public
name|Expr
block|{
name|public
operator|:
comment|/// CastKind - the kind of cast this represents.
expr|enum
name|CastKind
block|{
comment|/// CK_Unknown - Unknown cast kind.
comment|/// FIXME: The goal is to get rid of this and make all casts have a
comment|/// kind so that the AST client doesn't have to try to figure out what's
comment|/// going on.
name|CK_Unknown
block|,
comment|/// CK_BitCast - Used for reinterpret_cast.
name|CK_BitCast
block|,
comment|/// CK_LValueBitCast - Used for reinterpret_cast of expressions to
comment|/// a reference type.
name|CK_LValueBitCast
block|,
comment|/// CK_NoOp - Used for const_cast.
name|CK_NoOp
block|,
comment|/// CK_BaseToDerived - Base to derived class casts.
name|CK_BaseToDerived
block|,
comment|/// CK_DerivedToBase - Derived to base class casts.
name|CK_DerivedToBase
block|,
comment|/// CK_UncheckedDerivedToBase - Derived to base class casts that
comment|/// assume that the derived pointer is not null.
name|CK_UncheckedDerivedToBase
block|,
comment|/// CK_Dynamic - Dynamic cast.
name|CK_Dynamic
block|,
comment|/// CK_ToUnion - Cast to union (GCC extension).
name|CK_ToUnion
block|,
comment|/// CK_ArrayToPointerDecay - Array to pointer decay.
name|CK_ArrayToPointerDecay
block|,
comment|// CK_FunctionToPointerDecay - Function to pointer decay.
name|CK_FunctionToPointerDecay
block|,
comment|/// CK_NullToMemberPointer - Null pointer to member pointer.
name|CK_NullToMemberPointer
block|,
comment|/// CK_BaseToDerivedMemberPointer - Member pointer in base class to
comment|/// member pointer in derived class.
name|CK_BaseToDerivedMemberPointer
block|,
comment|/// CK_DerivedToBaseMemberPointer - Member pointer in derived class to
comment|/// member pointer in base class.
name|CK_DerivedToBaseMemberPointer
block|,
comment|/// CK_UserDefinedConversion - Conversion using a user defined type
comment|/// conversion function.
name|CK_UserDefinedConversion
block|,
comment|/// CK_ConstructorConversion - Conversion by constructor
name|CK_ConstructorConversion
block|,
comment|/// CK_IntegralToPointer - Integral to pointer
name|CK_IntegralToPointer
block|,
comment|/// CK_PointerToIntegral - Pointer to integral
name|CK_PointerToIntegral
block|,
comment|/// CK_ToVoid - Cast to void.
name|CK_ToVoid
block|,
comment|/// CK_VectorSplat - Casting from an integer/floating type to an extended
comment|/// vector type with the same element type as the src type. Splats the
comment|/// src expression into the destination expression.
name|CK_VectorSplat
block|,
comment|/// CK_IntegralCast - Casting between integral types of different size.
name|CK_IntegralCast
block|,
comment|/// CK_IntegralToFloating - Integral to floating point.
name|CK_IntegralToFloating
block|,
comment|/// CK_FloatingToIntegral - Floating point to integral.
name|CK_FloatingToIntegral
block|,
comment|/// CK_FloatingCast - Casting between floating types of different size.
name|CK_FloatingCast
block|,
comment|/// CK_MemberPointerToBoolean - Member pointer to boolean
name|CK_MemberPointerToBoolean
block|,
comment|/// CK_AnyPointerToObjCPointerCast - Casting any pointer to objective-c
comment|/// pointer
name|CK_AnyPointerToObjCPointerCast
block|,
comment|/// CK_AnyPointerToBlockPointerCast - Casting any pointer to block
comment|/// pointer
name|CK_AnyPointerToBlockPointerCast
block|}
block|;
name|private
operator|:
name|CastKind
name|Kind
block|;
name|Stmt
operator|*
name|Op
block|;
comment|/// BasePath - For derived-to-base and base-to-derived casts, the base array
comment|/// contains the inheritance path.
name|CXXBaseSpecifierArray
name|BasePath
block|;
name|void
name|CheckBasePath
argument_list|()
specifier|const
block|{
ifndef|#
directive|ifndef
name|NDEBUG
switch|switch
condition|(
name|getCastKind
argument_list|()
condition|)
block|{
case|case
name|CK_DerivedToBase
case|:
case|case
name|CK_UncheckedDerivedToBase
case|:
case|case
name|CK_DerivedToBaseMemberPointer
case|:
case|case
name|CK_BaseToDerived
case|:
case|case
name|CK_BaseToDerivedMemberPointer
case|:
name|assert
argument_list|(
operator|!
name|BasePath
operator|.
name|empty
argument_list|()
operator|&&
literal|"Cast kind should have a base path!"
argument_list|)
expr_stmt|;
break|break;
comment|// These should not have an inheritance path.
case|case
name|CK_Unknown
case|:
case|case
name|CK_BitCast
case|:
case|case
name|CK_LValueBitCast
case|:
case|case
name|CK_NoOp
case|:
case|case
name|CK_Dynamic
case|:
case|case
name|CK_ToUnion
case|:
case|case
name|CK_ArrayToPointerDecay
case|:
case|case
name|CK_FunctionToPointerDecay
case|:
case|case
name|CK_NullToMemberPointer
case|:
case|case
name|CK_UserDefinedConversion
case|:
case|case
name|CK_ConstructorConversion
case|:
case|case
name|CK_IntegralToPointer
case|:
case|case
name|CK_PointerToIntegral
case|:
case|case
name|CK_ToVoid
case|:
case|case
name|CK_VectorSplat
case|:
case|case
name|CK_IntegralCast
case|:
case|case
name|CK_IntegralToFloating
case|:
case|case
name|CK_FloatingToIntegral
case|:
case|case
name|CK_FloatingCast
case|:
case|case
name|CK_MemberPointerToBoolean
case|:
case|case
name|CK_AnyPointerToObjCPointerCast
case|:
case|case
name|CK_AnyPointerToBlockPointerCast
case|:
name|assert
argument_list|(
name|BasePath
operator|.
name|empty
argument_list|()
operator|&&
literal|"Cast kind should not have a base path!"
argument_list|)
expr_stmt|;
break|break;
block|}
endif|#
directive|endif
block|}
name|protected
operator|:
name|CastExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|QualType ty
argument_list|,
argument|const CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|CXXBaseSpecifierArray BasePath
argument_list|)
operator|:
name|Expr
argument_list|(
name|SC
argument_list|,
name|ty
argument_list|,
comment|// Cast expressions are type-dependent if the type is
comment|// dependent (C++ [temp.dep.expr]p3).
name|ty
operator|->
name|isDependentType
argument_list|()
argument_list|,
comment|// Cast expressions are value-dependent if the type is
comment|// dependent or if the subexpression is value-dependent.
name|ty
operator|->
name|isDependentType
argument_list|()
operator|||
operator|(
name|op
operator|&&
name|op
operator|->
name|isValueDependent
argument_list|()
operator|)
argument_list|)
block|,
name|Kind
argument_list|(
name|kind
argument_list|)
block|,
name|Op
argument_list|(
name|op
argument_list|)
block|,
name|BasePath
argument_list|(
argument|BasePath
argument_list|)
block|{
name|CheckBasePath
argument_list|()
block|;     }
comment|/// \brief Construct an empty cast.
name|CastExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|SC
argument_list|,
argument|Empty
argument_list|)
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
name|CastKind
name|getCastKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|void
name|setCastKind
argument_list|(
argument|CastKind K
argument_list|)
block|{
name|Kind
operator|=
name|K
block|; }
specifier|const
name|char
operator|*
name|getCastKindName
argument_list|()
specifier|const
block|;
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
name|Op
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
comment|/// \brief Retrieve the cast subexpression as it was written in the source
comment|/// code, looking through any implicit casts or other intermediate nodes
comment|/// introduced by semantic analysis.
name|Expr
operator|*
name|getSubExprAsWritten
argument_list|()
block|;
specifier|const
name|Expr
operator|*
name|getSubExprAsWritten
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|CastExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getSubExprAsWritten
argument_list|()
return|;
block|}
specifier|const
name|CXXBaseSpecifierArray
operator|&
name|getBasePath
argument_list|()
specifier|const
block|{
return|return
name|BasePath
return|;
block|}
name|CXXBaseSpecifierArray
operator|&
name|getBasePath
argument_list|()
block|{
return|return
name|BasePath
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
operator|>=
name|firstCastExprConstant
operator|&&
name|T
operator|->
name|getStmtClass
argument_list|()
operator|<=
name|lastCastExprConstant
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CastExpr *
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
end_decl_stmt

begin_comment
comment|/// ImplicitCastExpr - Allows us to explicitly represent implicit type
end_comment

begin_comment
comment|/// conversions, which have no direct representation in the original
end_comment

begin_comment
comment|/// source code. For example: converting T[]->T*, void f()->void
end_comment

begin_comment
comment|/// (*f)(), float->double, short->int, etc.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In C, implicit casts always produce rvalues. However, in C++, an
end_comment

begin_comment
comment|/// implicit cast whose result is being bound to a reference will be
end_comment

begin_comment
comment|/// an lvalue. For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// class Base { };
end_comment

begin_comment
comment|/// class Derived : public Base { };
end_comment

begin_comment
comment|/// void f(Derived d) {
end_comment

begin_comment
comment|///   Base& b = d; // initializer is an ImplicitCastExpr to an lvalue of type Base
end_comment

begin_comment
comment|/// }
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_decl_stmt
name|class
name|ImplicitCastExpr
range|:
name|public
name|CastExpr
block|{
comment|/// LvalueCast - Whether this cast produces an lvalue.
name|bool
name|LvalueCast
block|;
name|public
operator|:
name|ImplicitCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|CXXBaseSpecifierArray BasePath
argument_list|,
argument|bool Lvalue
argument_list|)
operator|:
name|CastExpr
argument_list|(
name|ImplicitCastExprClass
argument_list|,
name|ty
argument_list|,
name|kind
argument_list|,
name|op
argument_list|,
name|BasePath
argument_list|)
block|,
name|LvalueCast
argument_list|(
argument|Lvalue
argument_list|)
block|{ }
comment|/// \brief Construct an empty implicit cast.
name|explicit
name|ImplicitCastExpr
argument_list|(
argument|EmptyShell Shell
argument_list|)
operator|:
name|CastExpr
argument_list|(
argument|ImplicitCastExprClass
argument_list|,
argument|Shell
argument_list|)
block|{ }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|getSubExpr
argument_list|()
operator|->
name|getSourceRange
argument_list|()
return|;
block|}
comment|/// isLvalueCast - Whether this cast produces an lvalue.
name|bool
name|isLvalueCast
argument_list|()
specifier|const
block|{
return|return
name|LvalueCast
return|;
block|}
comment|/// setLvalueCast - Set whether this cast produces an lvalue.
name|void
name|setLvalueCast
argument_list|(
argument|bool Lvalue
argument_list|)
block|{
name|LvalueCast
operator|=
name|Lvalue
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
name|ImplicitCastExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ImplicitCastExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// ExplicitCastExpr - An explicit cast written in the source
comment|/// code.
comment|///
comment|/// This class is effectively an abstract class, because it provides
comment|/// the basic representation of an explicitly-written cast without
comment|/// specifying which kind of cast (C cast, functional cast, static
comment|/// cast, etc.) was written; specific derived classes represent the
comment|/// particular style of cast and its location information.
comment|///
comment|/// Unlike implicit casts, explicit cast nodes have two different
comment|/// types: the type that was written into the source code, and the
comment|/// actual type of the expression as determined by semantic
comment|/// analysis. These types may differ slightly. For example, in C++ one
comment|/// can cast to a reference type, which indicates that the resulting
comment|/// expression will be an lvalue. The reference type, however, will
comment|/// not be used as the type of the expression.
name|class
name|ExplicitCastExpr
operator|:
name|public
name|CastExpr
block|{
comment|/// TInfo - Source type info for the (written) type
comment|/// this expression is casting to.
name|TypeSourceInfo
operator|*
name|TInfo
block|;
name|protected
operator|:
name|ExplicitCastExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|QualType exprTy
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|CXXBaseSpecifierArray BasePath
argument_list|,
argument|TypeSourceInfo *writtenTy
argument_list|)
operator|:
name|CastExpr
argument_list|(
name|SC
argument_list|,
name|exprTy
argument_list|,
name|kind
argument_list|,
name|op
argument_list|,
name|BasePath
argument_list|)
block|,
name|TInfo
argument_list|(
argument|writtenTy
argument_list|)
block|{}
comment|/// \brief Construct an empty explicit cast.
name|ExplicitCastExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|EmptyShell Shell
argument_list|)
operator|:
name|CastExpr
argument_list|(
argument|SC
argument_list|,
argument|Shell
argument_list|)
block|{ }
name|public
operator|:
comment|/// getTypeInfoAsWritten - Returns the type source info for the type
comment|/// that this expression is casting to.
name|TypeSourceInfo
operator|*
name|getTypeInfoAsWritten
argument_list|()
specifier|const
block|{
return|return
name|TInfo
return|;
block|}
name|void
name|setTypeInfoAsWritten
argument_list|(
argument|TypeSourceInfo *writtenTy
argument_list|)
block|{
name|TInfo
operator|=
name|writtenTy
block|; }
comment|/// getTypeAsWritten - Returns the type that this expression is
comment|/// casting to, as written in the source code.
name|QualType
name|getTypeAsWritten
argument_list|()
specifier|const
block|{
return|return
name|TInfo
operator|->
name|getType
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
operator|>=
name|firstExplicitCastExprConstant
operator|&&
name|T
operator|->
name|getStmtClass
argument_list|()
operator|<=
name|lastExplicitCastExprConstant
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ExplicitCastExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// CStyleCastExpr - An explicit cast in C (C99 6.5.4) or a C-style
comment|/// cast in C++ (C++ [expr.cast]), which uses the syntax
comment|/// (Type)expr. For example: @c (int)f.
name|class
name|CStyleCastExpr
operator|:
name|public
name|ExplicitCastExpr
block|{
name|SourceLocation
name|LPLoc
block|;
comment|// the location of the left paren
name|SourceLocation
name|RPLoc
block|;
comment|// the location of the right paren
name|public
operator|:
name|CStyleCastExpr
argument_list|(
argument|QualType exprTy
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
argument_list|,
argument|SourceLocation r
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
name|CStyleCastExprClass
argument_list|,
name|exprTy
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
name|LPLoc
argument_list|(
name|l
argument_list|)
block|,
name|RPLoc
argument_list|(
argument|r
argument_list|)
block|{}
comment|/// \brief Construct an empty C-style explicit cast.
name|explicit
name|CStyleCastExpr
argument_list|(
argument|EmptyShell Shell
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
argument|CStyleCastExprClass
argument_list|,
argument|Shell
argument_list|)
block|{ }
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LPLoc
return|;
block|}
name|void
name|setLParenLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|LPLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RPLoc
return|;
block|}
name|void
name|setRParenLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|RPLoc
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
name|LPLoc
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
name|CStyleCastExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CStyleCastExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// \brief A builtin binary operation expression such as "x + y" or "x<= y".
comment|///
comment|/// This expression node kind describes a builtin binary operation,
comment|/// such as "x + y" for integer values "x" and "y". The operands will
comment|/// already have been converted to appropriate types (e.g., by
comment|/// performing promotions or conversions).
comment|///
comment|/// In C++, where operators may be overloaded, a different kind of
comment|/// expression node (CXXOperatorCallExpr) is used to express the
comment|/// invocation of an overloaded operator with operator syntax. Within
comment|/// a C++ template, whether BinaryOperator or CXXOperatorCallExpr is
comment|/// used to store an expression "x + y" depends on the subexpressions
comment|/// for x and y. If neither x or y is type-dependent, and the "+"
comment|/// operator resolves to a built-in operation, BinaryOperator will be
comment|/// used to express the computation (x and y may still be
comment|/// value-dependent). If either x or y is type-dependent, or if the
comment|/// "+" resolves to an overloaded operator, CXXOperatorCallExpr will
comment|/// be used to express the computation.
name|class
name|BinaryOperator
operator|:
name|public
name|Expr
block|{
name|public
operator|:
expr|enum
name|Opcode
block|{
comment|// Operators listed in order of precedence.
comment|// Note that additions to this should also update the StmtVisitor class.
name|PtrMemD
block|,
name|PtrMemI
block|,
comment|// [C++ 5.5] Pointer-to-member operators.
name|Mul
block|,
name|Div
block|,
name|Rem
block|,
comment|// [C99 6.5.5] Multiplicative operators.
name|Add
block|,
name|Sub
block|,
comment|// [C99 6.5.6] Additive operators.
name|Shl
block|,
name|Shr
block|,
comment|// [C99 6.5.7] Bitwise shift operators.
name|LT
block|,
name|GT
block|,
name|LE
block|,
name|GE
block|,
comment|// [C99 6.5.8] Relational operators.
name|EQ
block|,
name|NE
block|,
comment|// [C99 6.5.9] Equality operators.
name|And
block|,
comment|// [C99 6.5.10] Bitwise AND operator.
name|Xor
block|,
comment|// [C99 6.5.11] Bitwise XOR operator.
name|Or
block|,
comment|// [C99 6.5.12] Bitwise OR operator.
name|LAnd
block|,
comment|// [C99 6.5.13] Logical AND operator.
name|LOr
block|,
comment|// [C99 6.5.14] Logical OR operator.
name|Assign
block|,
name|MulAssign
block|,
comment|// [C99 6.5.16] Assignment operators.
name|DivAssign
block|,
name|RemAssign
block|,
name|AddAssign
block|,
name|SubAssign
block|,
name|ShlAssign
block|,
name|ShrAssign
block|,
name|AndAssign
block|,
name|XorAssign
block|,
name|OrAssign
block|,
name|Comma
comment|// [C99 6.5.17] Comma operator.
block|}
block|;
name|private
operator|:
expr|enum
block|{
name|LHS
block|,
name|RHS
block|,
name|END_EXPR
block|}
block|;
name|Stmt
operator|*
name|SubExprs
index|[
name|END_EXPR
index|]
block|;
name|Opcode
name|Opc
block|;
name|SourceLocation
name|OpLoc
block|;
name|public
operator|:
name|BinaryOperator
argument_list|(
argument|Expr *lhs
argument_list|,
argument|Expr *rhs
argument_list|,
argument|Opcode opc
argument_list|,
argument|QualType ResTy
argument_list|,
argument|SourceLocation opLoc
argument_list|)
operator|:
name|Expr
argument_list|(
name|BinaryOperatorClass
argument_list|,
name|ResTy
argument_list|,
name|lhs
operator|->
name|isTypeDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|lhs
operator|->
name|isValueDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isValueDependent
argument_list|()
argument_list|)
block|,
name|Opc
argument_list|(
name|opc
argument_list|)
block|,
name|OpLoc
argument_list|(
argument|opLoc
argument_list|)
block|{
name|SubExprs
index|[
name|LHS
index|]
operator|=
name|lhs
block|;
name|SubExprs
index|[
name|RHS
index|]
operator|=
name|rhs
block|;
name|assert
argument_list|(
operator|!
name|isCompoundAssignmentOp
argument_list|()
operator|&&
literal|"Use ArithAssignBinaryOperator for compound assignments"
argument_list|)
block|;   }
comment|/// \brief Construct an empty binary operator.
name|explicit
name|BinaryOperator
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|BinaryOperatorClass
argument_list|,
name|Empty
argument_list|)
block|,
name|Opc
argument_list|(
argument|Comma
argument_list|)
block|{ }
name|SourceLocation
name|getOperatorLoc
argument_list|()
specifier|const
block|{
return|return
name|OpLoc
return|;
block|}
name|void
name|setOperatorLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|OpLoc
operator|=
name|L
block|; }
name|Opcode
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Opc
return|;
block|}
name|void
name|setOpcode
argument_list|(
argument|Opcode O
argument_list|)
block|{
name|Opc
operator|=
name|O
block|; }
name|Expr
operator|*
name|getLHS
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|LHS
index|]
operator|)
return|;
block|}
name|void
name|setLHS
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|LHS
index|]
operator|=
name|E
block|; }
name|Expr
operator|*
name|getRHS
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|RHS
index|]
operator|)
return|;
block|}
name|void
name|setRHS
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|RHS
index|]
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
argument_list|(
name|getLHS
argument_list|()
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|getRHS
argument_list|()
operator|->
name|getLocEnd
argument_list|()
argument_list|)
return|;
block|}
comment|/// getOpcodeStr - Turn an Opcode enum value into the punctuation char it
comment|/// corresponds to, e.g. "<<=".
specifier|static
specifier|const
name|char
operator|*
name|getOpcodeStr
argument_list|(
argument|Opcode Op
argument_list|)
block|;
comment|/// \brief Retrieve the binary opcode that corresponds to the given
comment|/// overloaded operator.
specifier|static
name|Opcode
name|getOverloadedOpcode
argument_list|(
argument|OverloadedOperatorKind OO
argument_list|)
block|;
comment|/// \brief Retrieve the overloaded operator kind that corresponds to
comment|/// the given binary opcode.
specifier|static
name|OverloadedOperatorKind
name|getOverloadedOperator
argument_list|(
argument|Opcode Opc
argument_list|)
block|;
comment|/// predicates to categorize the respective opcodes.
name|bool
name|isMultiplicativeOp
argument_list|()
specifier|const
block|{
return|return
name|Opc
operator|>=
name|Mul
operator|&&
name|Opc
operator|<=
name|Rem
return|;
block|}
specifier|static
name|bool
name|isAdditiveOp
argument_list|(
argument|Opcode Opc
argument_list|)
block|{
return|return
name|Opc
operator|==
name|Add
operator|||
name|Opc
operator|==
name|Sub
return|;
block|}
name|bool
name|isAdditiveOp
argument_list|()
specifier|const
block|{
return|return
name|isAdditiveOp
argument_list|(
name|Opc
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isShiftOp
argument_list|(
argument|Opcode Opc
argument_list|)
block|{
return|return
name|Opc
operator|==
name|Shl
operator|||
name|Opc
operator|==
name|Shr
return|;
block|}
name|bool
name|isShiftOp
argument_list|()
specifier|const
block|{
return|return
name|isShiftOp
argument_list|(
name|Opc
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isBitwiseOp
argument_list|(
argument|Opcode Opc
argument_list|)
block|{
return|return
name|Opc
operator|>=
name|And
operator|&&
name|Opc
operator|<=
name|Or
return|;
block|}
name|bool
name|isBitwiseOp
argument_list|()
specifier|const
block|{
return|return
name|isBitwiseOp
argument_list|(
name|Opc
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isRelationalOp
argument_list|(
argument|Opcode Opc
argument_list|)
block|{
return|return
name|Opc
operator|>=
name|LT
operator|&&
name|Opc
operator|<=
name|GE
return|;
block|}
name|bool
name|isRelationalOp
argument_list|()
specifier|const
block|{
return|return
name|isRelationalOp
argument_list|(
name|Opc
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqualityOp
argument_list|(
argument|Opcode Opc
argument_list|)
block|{
return|return
name|Opc
operator|==
name|EQ
operator|||
name|Opc
operator|==
name|NE
return|;
block|}
name|bool
name|isEqualityOp
argument_list|()
specifier|const
block|{
return|return
name|isEqualityOp
argument_list|(
name|Opc
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isComparisonOp
argument_list|(
argument|Opcode Opc
argument_list|)
block|{
return|return
name|Opc
operator|>=
name|LT
operator|&&
name|Opc
operator|<=
name|NE
return|;
block|}
name|bool
name|isComparisonOp
argument_list|()
specifier|const
block|{
return|return
name|isComparisonOp
argument_list|(
name|Opc
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isLogicalOp
argument_list|(
argument|Opcode Opc
argument_list|)
block|{
return|return
name|Opc
operator|==
name|LAnd
operator|||
name|Opc
operator|==
name|LOr
return|;
block|}
name|bool
name|isLogicalOp
argument_list|()
specifier|const
block|{
return|return
name|isLogicalOp
argument_list|(
name|Opc
argument_list|)
return|;
block|}
name|bool
name|isAssignmentOp
argument_list|()
specifier|const
block|{
return|return
name|Opc
operator|>=
name|Assign
operator|&&
name|Opc
operator|<=
name|OrAssign
return|;
block|}
name|bool
name|isCompoundAssignmentOp
argument_list|()
specifier|const
block|{
return|return
name|Opc
operator|>
name|Assign
operator|&&
name|Opc
operator|<=
name|OrAssign
return|;
block|}
name|bool
name|isShiftAssignOp
argument_list|()
specifier|const
block|{
return|return
name|Opc
operator|==
name|ShlAssign
operator|||
name|Opc
operator|==
name|ShrAssign
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
operator|>=
name|firstBinaryOperatorConstant
operator|&&
name|S
operator|->
name|getStmtClass
argument_list|()
operator|<=
name|lastBinaryOperatorConstant
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const BinaryOperator *
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
block|;
name|protected
operator|:
name|BinaryOperator
argument_list|(
argument|Expr *lhs
argument_list|,
argument|Expr *rhs
argument_list|,
argument|Opcode opc
argument_list|,
argument|QualType ResTy
argument_list|,
argument|SourceLocation opLoc
argument_list|,
argument|bool dead
argument_list|)
operator|:
name|Expr
argument_list|(
name|CompoundAssignOperatorClass
argument_list|,
name|ResTy
argument_list|,
name|lhs
operator|->
name|isTypeDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|lhs
operator|->
name|isValueDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isValueDependent
argument_list|()
argument_list|)
block|,
name|Opc
argument_list|(
name|opc
argument_list|)
block|,
name|OpLoc
argument_list|(
argument|opLoc
argument_list|)
block|{
name|SubExprs
index|[
name|LHS
index|]
operator|=
name|lhs
block|;
name|SubExprs
index|[
name|RHS
index|]
operator|=
name|rhs
block|;   }
name|BinaryOperator
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
name|Opc
argument_list|(
argument|MulAssign
argument_list|)
block|{ }
block|}
block|;
comment|/// CompoundAssignOperator - For compound assignments (e.g. +=), we keep
comment|/// track of the type the operation is performed in.  Due to the semantics of
comment|/// these operators, the operands are promoted, the aritmetic performed, an
comment|/// implicit conversion back to the result type done, then the assignment takes
comment|/// place.  This captures the intermediate type which the computation is done
comment|/// in.
name|class
name|CompoundAssignOperator
operator|:
name|public
name|BinaryOperator
block|{
name|QualType
name|ComputationLHSType
block|;
name|QualType
name|ComputationResultType
block|;
name|public
operator|:
name|CompoundAssignOperator
argument_list|(
argument|Expr *lhs
argument_list|,
argument|Expr *rhs
argument_list|,
argument|Opcode opc
argument_list|,
argument|QualType ResType
argument_list|,
argument|QualType CompLHSType
argument_list|,
argument|QualType CompResultType
argument_list|,
argument|SourceLocation OpLoc
argument_list|)
operator|:
name|BinaryOperator
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|,
name|opc
argument_list|,
name|ResType
argument_list|,
name|OpLoc
argument_list|,
name|true
argument_list|)
block|,
name|ComputationLHSType
argument_list|(
name|CompLHSType
argument_list|)
block|,
name|ComputationResultType
argument_list|(
argument|CompResultType
argument_list|)
block|{
name|assert
argument_list|(
name|isCompoundAssignmentOp
argument_list|()
operator|&&
literal|"Only should be used for compound assignments"
argument_list|)
block|;   }
comment|/// \brief Build an empty compound assignment operator expression.
name|explicit
name|CompoundAssignOperator
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|BinaryOperator
argument_list|(
argument|CompoundAssignOperatorClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|// The two computation types are the type the LHS is converted
comment|// to for the computation and the type of the result; the two are
comment|// distinct in a few cases (specifically, int+=ptr and ptr-=ptr).
name|QualType
name|getComputationLHSType
argument_list|()
specifier|const
block|{
return|return
name|ComputationLHSType
return|;
block|}
name|void
name|setComputationLHSType
argument_list|(
argument|QualType T
argument_list|)
block|{
name|ComputationLHSType
operator|=
name|T
block|; }
name|QualType
name|getComputationResultType
argument_list|()
specifier|const
block|{
return|return
name|ComputationResultType
return|;
block|}
name|void
name|setComputationResultType
argument_list|(
argument|QualType T
argument_list|)
block|{
name|ComputationResultType
operator|=
name|T
block|; }
specifier|static
name|bool
name|classof
argument_list|(
argument|const CompoundAssignOperator *
argument_list|)
block|{
return|return
name|true
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
name|CompoundAssignOperatorClass
return|;
block|}
expr|}
block|;
comment|/// ConditionalOperator - The ?: operator.  Note that LHS may be null when the
comment|/// GNU "missing LHS" extension is in use.
comment|///
name|class
name|ConditionalOperator
operator|:
name|public
name|Expr
block|{   enum
block|{
name|COND
block|,
name|LHS
block|,
name|RHS
block|,
name|END_EXPR
block|}
block|;
name|Stmt
operator|*
name|SubExprs
index|[
name|END_EXPR
index|]
block|;
comment|// Left/Middle/Right hand sides.
name|SourceLocation
name|QuestionLoc
block|,
name|ColonLoc
block|;
name|public
operator|:
name|ConditionalOperator
argument_list|(
argument|Expr *cond
argument_list|,
argument|SourceLocation QLoc
argument_list|,
argument|Expr *lhs
argument_list|,
argument|SourceLocation CLoc
argument_list|,
argument|Expr *rhs
argument_list|,
argument|QualType t
argument_list|)
operator|:
name|Expr
argument_list|(
name|ConditionalOperatorClass
argument_list|,
name|t
argument_list|,
comment|// FIXME: the type of the conditional operator doesn't
comment|// depend on the type of the conditional, but the standard
comment|// seems to imply that it could. File a bug!
operator|(
operator|(
name|lhs
operator|&&
name|lhs
operator|->
name|isTypeDependent
argument_list|()
operator|)
operator|||
operator|(
name|rhs
operator|&&
name|rhs
operator|->
name|isTypeDependent
argument_list|()
operator|)
operator|)
argument_list|,
operator|(
name|cond
operator|->
name|isValueDependent
argument_list|()
operator|||
operator|(
name|lhs
operator|&&
name|lhs
operator|->
name|isValueDependent
argument_list|()
operator|)
operator|||
operator|(
name|rhs
operator|&&
name|rhs
operator|->
name|isValueDependent
argument_list|()
operator|)
operator|)
argument_list|)
block|,
name|QuestionLoc
argument_list|(
name|QLoc
argument_list|)
block|,
name|ColonLoc
argument_list|(
argument|CLoc
argument_list|)
block|{
name|SubExprs
index|[
name|COND
index|]
operator|=
name|cond
block|;
name|SubExprs
index|[
name|LHS
index|]
operator|=
name|lhs
block|;
name|SubExprs
index|[
name|RHS
index|]
operator|=
name|rhs
block|;   }
comment|/// \brief Build an empty conditional operator.
name|explicit
name|ConditionalOperator
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ConditionalOperatorClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|// getCond - Return the expression representing the condition for
comment|//  the ?: operator.
name|Expr
operator|*
name|getCond
argument_list|()
specifier|const
block|{
return|return
name|cast
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
name|E
block|; }
comment|// getTrueExpr - Return the subexpression representing the value of the ?:
comment|//  expression if the condition evaluates to true.  In most cases this value
comment|//  will be the same as getLHS() except a GCC extension allows the left
comment|//  subexpression to be omitted, and instead of the condition be returned.
comment|//  e.g: x ?: y is shorthand for x ? x : y, except that the expression "x"
comment|//  is only evaluated once.
name|Expr
operator|*
name|getTrueExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|LHS
index|]
operator|?
name|SubExprs
index|[
name|LHS
index|]
operator|:
name|SubExprs
index|[
name|COND
index|]
operator|)
return|;
block|}
comment|// getTrueExpr - Return the subexpression representing the value of the ?:
comment|// expression if the condition evaluates to false. This is the same as getRHS.
name|Expr
operator|*
name|getFalseExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|RHS
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getLHS
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
name|LHS
index|]
operator|)
return|;
block|}
name|void
name|setLHS
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|LHS
index|]
operator|=
name|E
block|; }
name|Expr
operator|*
name|getRHS
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|RHS
index|]
operator|)
return|;
block|}
name|void
name|setRHS
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|RHS
index|]
operator|=
name|E
block|; }
name|SourceLocation
name|getQuestionLoc
argument_list|()
specifier|const
block|{
return|return
name|QuestionLoc
return|;
block|}
name|void
name|setQuestionLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|QuestionLoc
operator|=
name|L
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
argument|SourceLocation L
argument_list|)
block|{
name|ColonLoc
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
name|getCond
argument_list|()
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|getRHS
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
name|ConditionalOperatorClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ConditionalOperator *
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
comment|/// AddrLabelExpr - The GNU address of label extension, representing&&label.
name|class
name|AddrLabelExpr
operator|:
name|public
name|Expr
block|{
name|SourceLocation
name|AmpAmpLoc
block|,
name|LabelLoc
block|;
name|LabelStmt
operator|*
name|Label
block|;
name|public
operator|:
name|AddrLabelExpr
argument_list|(
argument|SourceLocation AALoc
argument_list|,
argument|SourceLocation LLoc
argument_list|,
argument|LabelStmt *L
argument_list|,
argument|QualType t
argument_list|)
operator|:
name|Expr
argument_list|(
name|AddrLabelExprClass
argument_list|,
name|t
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|AmpAmpLoc
argument_list|(
name|AALoc
argument_list|)
block|,
name|LabelLoc
argument_list|(
name|LLoc
argument_list|)
block|,
name|Label
argument_list|(
argument|L
argument_list|)
block|{}
comment|/// \brief Build an empty address of a label expression.
name|explicit
name|AddrLabelExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|AddrLabelExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|SourceLocation
name|getAmpAmpLoc
argument_list|()
specifier|const
block|{
return|return
name|AmpAmpLoc
return|;
block|}
name|void
name|setAmpAmpLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|AmpAmpLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getLabelLoc
argument_list|()
specifier|const
block|{
return|return
name|LabelLoc
return|;
block|}
name|void
name|setLabelLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|LabelLoc
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
name|AmpAmpLoc
argument_list|,
name|LabelLoc
argument_list|)
return|;
block|}
name|LabelStmt
operator|*
name|getLabel
argument_list|()
specifier|const
block|{
return|return
name|Label
return|;
block|}
name|void
name|setLabel
argument_list|(
argument|LabelStmt *S
argument_list|)
block|{
name|Label
operator|=
name|S
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
name|AddrLabelExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const AddrLabelExpr *
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
comment|/// StmtExpr - This is the GNU Statement Expression extension: ({int X=4; X;}).
comment|/// The StmtExpr contains a single CompoundStmt node, which it evaluates and
comment|/// takes the value of the last subexpression.
name|class
name|StmtExpr
operator|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|SubStmt
block|;
name|SourceLocation
name|LParenLoc
block|,
name|RParenLoc
block|;
name|public
operator|:
comment|// FIXME: Does type-dependence need to be computed differently?
name|StmtExpr
argument_list|(
argument|CompoundStmt *substmt
argument_list|,
argument|QualType T
argument_list|,
argument|SourceLocation lp
argument_list|,
argument|SourceLocation rp
argument_list|)
operator|:
name|Expr
argument_list|(
name|StmtExprClass
argument_list|,
name|T
argument_list|,
name|T
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|false
argument_list|)
block|,
name|SubStmt
argument_list|(
name|substmt
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|lp
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|rp
argument_list|)
block|{ }
comment|/// \brief Build an empty statement expression.
name|explicit
name|StmtExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|StmtExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|CompoundStmt
operator|*
name|getSubStmt
argument_list|()
block|{
return|return
name|cast
operator|<
name|CompoundStmt
operator|>
operator|(
name|SubStmt
operator|)
return|;
block|}
specifier|const
name|CompoundStmt
operator|*
name|getSubStmt
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CompoundStmt
operator|>
operator|(
name|SubStmt
operator|)
return|;
block|}
name|void
name|setSubStmt
argument_list|(
argument|CompoundStmt *S
argument_list|)
block|{
name|SubStmt
operator|=
name|S
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
name|LParenLoc
argument_list|,
name|RParenLoc
argument_list|)
return|;
block|}
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
name|StmtExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const StmtExpr *
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
comment|/// TypesCompatibleExpr - GNU builtin-in function __builtin_types_compatible_p.
comment|/// This AST node represents a function that returns 1 if two *types* (not
comment|/// expressions) are compatible. The result of this built-in function can be
comment|/// used in integer constant expressions.
name|class
name|TypesCompatibleExpr
operator|:
name|public
name|Expr
block|{
name|QualType
name|Type1
block|;
name|QualType
name|Type2
block|;
name|SourceLocation
name|BuiltinLoc
block|,
name|RParenLoc
block|;
name|public
operator|:
name|TypesCompatibleExpr
argument_list|(
argument|QualType ReturnType
argument_list|,
argument|SourceLocation BLoc
argument_list|,
argument|QualType t1
argument_list|,
argument|QualType t2
argument_list|,
argument|SourceLocation RP
argument_list|)
operator|:
name|Expr
argument_list|(
name|TypesCompatibleExprClass
argument_list|,
name|ReturnType
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Type1
argument_list|(
name|t1
argument_list|)
block|,
name|Type2
argument_list|(
name|t2
argument_list|)
block|,
name|BuiltinLoc
argument_list|(
name|BLoc
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|RP
argument_list|)
block|{}
comment|/// \brief Build an empty __builtin_type_compatible_p expression.
name|explicit
name|TypesCompatibleExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|TypesCompatibleExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|QualType
name|getArgType1
argument_list|()
specifier|const
block|{
return|return
name|Type1
return|;
block|}
name|void
name|setArgType1
argument_list|(
argument|QualType T
argument_list|)
block|{
name|Type1
operator|=
name|T
block|; }
name|QualType
name|getArgType2
argument_list|()
specifier|const
block|{
return|return
name|Type2
return|;
block|}
name|void
name|setArgType2
argument_list|(
argument|QualType T
argument_list|)
block|{
name|Type2
operator|=
name|T
block|; }
name|SourceLocation
name|getBuiltinLoc
argument_list|()
specifier|const
block|{
return|return
name|BuiltinLoc
return|;
block|}
name|void
name|setBuiltinLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|BuiltinLoc
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
name|BuiltinLoc
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
name|TypesCompatibleExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const TypesCompatibleExpr *
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
comment|/// ShuffleVectorExpr - clang-specific builtin-in function
comment|/// __builtin_shufflevector.
comment|/// This AST node represents a operator that does a constant
comment|/// shuffle, similar to LLVM's shufflevector instruction. It takes
comment|/// two vectors and a variable number of constant indices,
comment|/// and returns the appropriately shuffled vector.
name|class
name|ShuffleVectorExpr
operator|:
name|public
name|Expr
block|{
name|SourceLocation
name|BuiltinLoc
block|,
name|RParenLoc
block|;
comment|// SubExprs - the list of values passed to the __builtin_shufflevector
comment|// function. The first two are vectors, and the rest are constant
comment|// indices.  The number of values in this list is always
comment|// 2+the number of indices in the vector type.
name|Stmt
operator|*
operator|*
name|SubExprs
block|;
name|unsigned
name|NumExprs
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
comment|// FIXME: Can a shufflevector be value-dependent?  Does type-dependence need
comment|// to be computed differently?
name|ShuffleVectorExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr **args
argument_list|,
argument|unsigned nexpr
argument_list|,
argument|QualType Type
argument_list|,
argument|SourceLocation BLoc
argument_list|,
argument|SourceLocation RP
argument_list|)
operator|:
name|Expr
argument_list|(
name|ShuffleVectorExprClass
argument_list|,
name|Type
argument_list|,
name|Type
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|false
argument_list|)
block|,
name|BuiltinLoc
argument_list|(
name|BLoc
argument_list|)
block|,
name|RParenLoc
argument_list|(
name|RP
argument_list|)
block|,
name|NumExprs
argument_list|(
argument|nexpr
argument_list|)
block|{
name|SubExprs
operator|=
name|new
argument_list|(
argument|C
argument_list|)
name|Stmt
operator|*
index|[
name|nexpr
index|]
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|nexpr
condition|;
name|i
operator|++
control|)
name|SubExprs
index|[
name|i
index|]
operator|=
name|args
index|[
name|i
index|]
expr_stmt|;
block|}
comment|/// \brief Build an empty vector-shuffle expression.
name|explicit
name|ShuffleVectorExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|ShuffleVectorExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|SubExprs
argument_list|(
literal|0
argument_list|)
block|{ }
name|SourceLocation
name|getBuiltinLoc
argument_list|()
specifier|const
block|{
return|return
name|BuiltinLoc
return|;
block|}
name|void
name|setBuiltinLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|BuiltinLoc
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
name|BuiltinLoc
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
name|ShuffleVectorExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ShuffleVectorExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
operator|~
name|ShuffleVectorExpr
argument_list|()
block|{}
comment|/// getNumSubExprs - Return the size of the SubExprs array.  This includes the
comment|/// constant expression, the actual arguments passed in, and the function
comment|/// pointers.
name|unsigned
name|getNumSubExprs
argument_list|()
specifier|const
block|{
return|return
name|NumExprs
return|;
block|}
comment|/// getExpr - Return the Expr at the specified index.
name|Expr
operator|*
name|getExpr
argument_list|(
argument|unsigned Index
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Index
operator|<
name|NumExprs
operator|)
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
name|SubExprs
index|[
name|Index
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getExpr
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Index
operator|<
name|NumExprs
operator|)
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
name|SubExprs
index|[
name|Index
index|]
operator|)
return|;
block|}
name|void
name|setExprs
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Expr ** Exprs
argument_list|,
argument|unsigned NumExprs
argument_list|)
block|;
name|unsigned
name|getShuffleMaskIdx
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|unsigned N
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|N
operator|<
name|NumExprs
operator|-
literal|2
operator|)
operator|&&
literal|"Shuffle idx out of range!"
argument_list|)
block|;
return|return
name|getExpr
argument_list|(
name|N
operator|+
literal|2
argument_list|)
operator|->
name|EvaluateAsInt
argument_list|(
name|Ctx
argument_list|)
operator|.
name|getZExtValue
argument_list|()
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
comment|/// ChooseExpr - GNU builtin-in function __builtin_choose_expr.
comment|/// This AST node is similar to the conditional operator (?:) in C, with
comment|/// the following exceptions:
comment|/// - the test expression must be a integer constant expression.
comment|/// - the expression returned acts like the chosen subexpression in every
comment|///   visible way: the type is the same as that of the chosen subexpression,
comment|///   and all predicates (whether it's an l-value, whether it's an integer
comment|///   constant expression, etc.) return the same result as for the chosen
comment|///   sub-expression.
name|class
name|ChooseExpr
operator|:
name|public
name|Expr
block|{   enum
block|{
name|COND
block|,
name|LHS
block|,
name|RHS
block|,
name|END_EXPR
block|}
block|;
name|Stmt
operator|*
name|SubExprs
index|[
name|END_EXPR
index|]
block|;
comment|// Left/Middle/Right hand sides.
name|SourceLocation
name|BuiltinLoc
block|,
name|RParenLoc
block|;
name|public
operator|:
name|ChooseExpr
argument_list|(
argument|SourceLocation BLoc
argument_list|,
argument|Expr *cond
argument_list|,
argument|Expr *lhs
argument_list|,
argument|Expr *rhs
argument_list|,
argument|QualType t
argument_list|,
argument|SourceLocation RP
argument_list|,
argument|bool TypeDependent
argument_list|,
argument|bool ValueDependent
argument_list|)
operator|:
name|Expr
argument_list|(
name|ChooseExprClass
argument_list|,
name|t
argument_list|,
name|TypeDependent
argument_list|,
name|ValueDependent
argument_list|)
block|,
name|BuiltinLoc
argument_list|(
name|BLoc
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|RP
argument_list|)
block|{
name|SubExprs
index|[
name|COND
index|]
operator|=
name|cond
block|;
name|SubExprs
index|[
name|LHS
index|]
operator|=
name|lhs
block|;
name|SubExprs
index|[
name|RHS
index|]
operator|=
name|rhs
block|;     }
comment|/// \brief Build an empty __builtin_choose_expr.
name|explicit
name|ChooseExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ChooseExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// isConditionTrue - Return whether the condition is true (i.e. not
comment|/// equal to zero).
name|bool
name|isConditionTrue
argument_list|(
argument|ASTContext&C
argument_list|)
specifier|const
block|;
comment|/// getChosenSubExpr - Return the subexpression chosen according to the
comment|/// condition.
name|Expr
operator|*
name|getChosenSubExpr
argument_list|(
argument|ASTContext&C
argument_list|)
specifier|const
block|{
return|return
name|isConditionTrue
argument_list|(
name|C
argument_list|)
operator|?
name|getLHS
argument_list|()
operator|:
name|getRHS
argument_list|()
return|;
block|}
name|Expr
operator|*
name|getCond
argument_list|()
specifier|const
block|{
return|return
name|cast
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
name|E
block|; }
name|Expr
operator|*
name|getLHS
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|LHS
index|]
operator|)
return|;
block|}
name|void
name|setLHS
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|LHS
index|]
operator|=
name|E
block|; }
name|Expr
operator|*
name|getRHS
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|RHS
index|]
operator|)
return|;
block|}
name|void
name|setRHS
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|SubExprs
index|[
name|RHS
index|]
operator|=
name|E
block|; }
name|SourceLocation
name|getBuiltinLoc
argument_list|()
specifier|const
block|{
return|return
name|BuiltinLoc
return|;
block|}
name|void
name|setBuiltinLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|BuiltinLoc
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
name|BuiltinLoc
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
name|ChooseExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ChooseExpr *
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
comment|/// GNUNullExpr - Implements the GNU __null extension, which is a name
comment|/// for a null pointer constant that has integral type (e.g., int or
comment|/// long) and is the same size and alignment as a pointer. The __null
comment|/// extension is typically only used by system headers, which define
comment|/// NULL as __null in C++ rather than using 0 (which is an integer
comment|/// that may not match the size of a pointer).
name|class
name|GNUNullExpr
operator|:
name|public
name|Expr
block|{
comment|/// TokenLoc - The location of the __null keyword.
name|SourceLocation
name|TokenLoc
block|;
name|public
operator|:
name|GNUNullExpr
argument_list|(
argument|QualType Ty
argument_list|,
argument|SourceLocation Loc
argument_list|)
operator|:
name|Expr
argument_list|(
name|GNUNullExprClass
argument_list|,
name|Ty
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|TokenLoc
argument_list|(
argument|Loc
argument_list|)
block|{ }
comment|/// \brief Build an empty GNU __null expression.
name|explicit
name|GNUNullExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|GNUNullExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// getTokenLocation - The location of the __null token.
name|SourceLocation
name|getTokenLocation
argument_list|()
specifier|const
block|{
return|return
name|TokenLoc
return|;
block|}
name|void
name|setTokenLocation
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|TokenLoc
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
name|TokenLoc
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
name|GNUNullExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const GNUNullExpr *
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
comment|/// VAArgExpr, used for the builtin function __builtin_va_arg.
name|class
name|VAArgExpr
operator|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|Val
block|;
name|SourceLocation
name|BuiltinLoc
block|,
name|RParenLoc
block|;
name|public
operator|:
name|VAArgExpr
argument_list|(
argument|SourceLocation BLoc
argument_list|,
argument|Expr* e
argument_list|,
argument|QualType t
argument_list|,
argument|SourceLocation RPLoc
argument_list|)
operator|:
name|Expr
argument_list|(
name|VAArgExprClass
argument_list|,
name|t
argument_list|,
name|t
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|false
argument_list|)
block|,
name|Val
argument_list|(
name|e
argument_list|)
block|,
name|BuiltinLoc
argument_list|(
name|BLoc
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|RPLoc
argument_list|)
block|{ }
comment|/// \brief Create an empty __builtin_va_arg expression.
name|explicit
name|VAArgExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|VAArgExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
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
name|Val
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
name|Val
operator|)
return|;
block|}
name|void
name|setSubExpr
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Val
operator|=
name|E
block|; }
name|SourceLocation
name|getBuiltinLoc
argument_list|()
specifier|const
block|{
return|return
name|BuiltinLoc
return|;
block|}
name|void
name|setBuiltinLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|BuiltinLoc
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
name|BuiltinLoc
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
name|VAArgExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const VAArgExpr *
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
comment|/// @brief Describes an C or C++ initializer list.
comment|///
comment|/// InitListExpr describes an initializer list, which can be used to
comment|/// initialize objects of different types, including
comment|/// struct/class/union types, arrays, and vectors. For example:
comment|///
comment|/// @code
comment|/// struct foo x = { 1, { 2, 3 } };
comment|/// @endcode
comment|///
comment|/// Prior to semantic analysis, an initializer list will represent the
comment|/// initializer list as written by the user, but will have the
comment|/// placeholder type "void". This initializer list is called the
comment|/// syntactic form of the initializer, and may contain C99 designated
comment|/// initializers (represented as DesignatedInitExprs), initializations
comment|/// of subobject members without explicit braces, and so on. Clients
comment|/// interested in the original syntax of the initializer list should
comment|/// use the syntactic form of the initializer list.
comment|///
comment|/// After semantic analysis, the initializer list will represent the
comment|/// semantic form of the initializer, where the initializations of all
comment|/// subobjects are made explicit with nested InitListExpr nodes and
comment|/// C99 designators have been eliminated by placing the designated
comment|/// initializations into the subobject they initialize. Additionally,
comment|/// any "holes" in the initialization, where no initializer has been
comment|/// specified for a particular subobject, will be replaced with
comment|/// implicitly-generated ImplicitValueInitExpr expressions that
comment|/// value-initialize the subobjects. Note, however, that the
comment|/// initializer lists may still have fewer initializers than there are
comment|/// elements to initialize within the object.
comment|///
comment|/// Given the semantic form of the initializer list, one can retrieve
comment|/// the original syntactic form of that initializer list (if it
comment|/// exists) using getSyntacticForm(). Since many initializer lists
comment|/// have the same syntactic and semantic forms, getSyntacticForm() may
comment|/// return NULL, indicating that the current initializer list also
comment|/// serves as its syntactic form.
name|class
name|InitListExpr
operator|:
name|public
name|Expr
block|{
comment|// FIXME: Eliminate this vector in favor of ASTContext allocation
typedef|typedef
name|ASTVector
operator|<
name|Stmt
operator|*
operator|>
name|InitExprsTy
expr_stmt|;
name|InitExprsTy
name|InitExprs
block|;
name|SourceLocation
name|LBraceLoc
block|,
name|RBraceLoc
block|;
comment|/// Contains the initializer list that describes the syntactic form
comment|/// written in the source code.
name|InitListExpr
operator|*
name|SyntacticForm
block|;
comment|/// If this initializer list initializes a union, specifies which
comment|/// field within the union will be initialized.
name|FieldDecl
operator|*
name|UnionFieldInit
block|;
comment|/// Whether this initializer list originally had a GNU array-range
comment|/// designator in it. This is a temporary marker used by CodeGen.
name|bool
name|HadArrayRangeDesignator
block|;
name|public
operator|:
name|InitListExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|SourceLocation lbraceloc
argument_list|,
argument|Expr **initexprs
argument_list|,
argument|unsigned numinits
argument_list|,
argument|SourceLocation rbraceloc
argument_list|)
block|;
comment|/// \brief Build an empty initializer list.
name|explicit
name|InitListExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|InitListExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|InitExprs
argument_list|(
argument|C
argument_list|)
block|{ }
name|unsigned
name|getNumInits
argument_list|()
specifier|const
block|{
return|return
name|InitExprs
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|Expr
operator|*
name|getInit
argument_list|(
argument|unsigned Init
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Init
operator|<
name|getNumInits
argument_list|()
operator|&&
literal|"Initializer access out of range!"
argument_list|)
block|;
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|InitExprs
index|[
name|Init
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getInit
argument_list|(
argument|unsigned Init
argument_list|)
block|{
name|assert
argument_list|(
name|Init
operator|<
name|getNumInits
argument_list|()
operator|&&
literal|"Initializer access out of range!"
argument_list|)
block|;
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|InitExprs
index|[
name|Init
index|]
operator|)
return|;
block|}
name|void
name|setInit
argument_list|(
argument|unsigned Init
argument_list|,
argument|Expr *expr
argument_list|)
block|{
name|assert
argument_list|(
name|Init
operator|<
name|getNumInits
argument_list|()
operator|&&
literal|"Initializer access out of range!"
argument_list|)
block|;
name|InitExprs
index|[
name|Init
index|]
operator|=
name|expr
block|;   }
comment|/// \brief Reserve space for some number of initializers.
name|void
name|reserveInits
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned NumInits
argument_list|)
block|;
comment|/// @brief Specify the number of initializers
comment|///
comment|/// If there are more than @p NumInits initializers, the remaining
comment|/// initializers will be destroyed. If there are fewer than @p
comment|/// NumInits initializers, NULL expressions will be added for the
comment|/// unknown initializers.
name|void
name|resizeInits
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|unsigned NumInits
argument_list|)
block|;
comment|/// @brief Updates the initializer at index @p Init with the new
comment|/// expression @p expr, and returns the old expression at that
comment|/// location.
comment|///
comment|/// When @p Init is out of range for this initializer list, the
comment|/// initializer list will be extended with NULL expressions to
comment|/// accomodate the new entry.
name|Expr
operator|*
name|updateInit
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned Init
argument_list|,
argument|Expr *expr
argument_list|)
block|;
comment|/// \brief If this initializes a union, specifies which field in the
comment|/// union to initialize.
comment|///
comment|/// Typically, this field is the first named field within the
comment|/// union. However, a designated initializer can specify the
comment|/// initialization of a different field within the union.
name|FieldDecl
operator|*
name|getInitializedFieldInUnion
argument_list|()
block|{
return|return
name|UnionFieldInit
return|;
block|}
name|void
name|setInitializedFieldInUnion
argument_list|(
argument|FieldDecl *FD
argument_list|)
block|{
name|UnionFieldInit
operator|=
name|FD
block|; }
comment|// Explicit InitListExpr's originate from source code (and have valid source
comment|// locations). Implicit InitListExpr's are created by the semantic analyzer.
name|bool
name|isExplicit
argument_list|()
block|{
return|return
name|LBraceLoc
operator|.
name|isValid
argument_list|()
operator|&&
name|RBraceLoc
operator|.
name|isValid
argument_list|()
return|;
block|}
name|SourceLocation
name|getLBraceLoc
argument_list|()
specifier|const
block|{
return|return
name|LBraceLoc
return|;
block|}
name|void
name|setLBraceLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|LBraceLoc
operator|=
name|Loc
block|; }
name|SourceLocation
name|getRBraceLoc
argument_list|()
specifier|const
block|{
return|return
name|RBraceLoc
return|;
block|}
name|void
name|setRBraceLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|RBraceLoc
operator|=
name|Loc
block|; }
comment|/// @brief Retrieve the initializer list that describes the
comment|/// syntactic form of the initializer.
comment|///
comment|///
name|InitListExpr
operator|*
name|getSyntacticForm
argument_list|()
specifier|const
block|{
return|return
name|SyntacticForm
return|;
block|}
name|void
name|setSyntacticForm
argument_list|(
argument|InitListExpr *Init
argument_list|)
block|{
name|SyntacticForm
operator|=
name|Init
block|; }
name|bool
name|hadArrayRangeDesignator
argument_list|()
specifier|const
block|{
return|return
name|HadArrayRangeDesignator
return|;
block|}
name|void
name|sawArrayRangeDesignator
argument_list|(
argument|bool ARD = true
argument_list|)
block|{
name|HadArrayRangeDesignator
operator|=
name|ARD
block|;   }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|LBraceLoc
argument_list|,
name|RBraceLoc
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
name|InitListExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const InitListExpr *
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
block|;
typedef|typedef
name|InitExprsTy
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|InitExprsTy
operator|::
name|reverse_iterator
name|reverse_iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
block|{
return|return
name|InitExprs
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|InitExprs
operator|.
name|end
argument_list|()
return|;
block|}
name|reverse_iterator
name|rbegin
argument_list|()
block|{
return|return
name|InitExprs
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|reverse_iterator
name|rend
argument_list|()
block|{
return|return
name|InitExprs
operator|.
name|rend
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// @brief Represents a C99 designated initializer expression.
comment|///
comment|/// A designated initializer expression (C99 6.7.8) contains one or
comment|/// more designators (which can be field designators, array
comment|/// designators, or GNU array-range designators) followed by an
comment|/// expression that initializes the field or element(s) that the
comment|/// designators refer to. For example, given:
comment|///
comment|/// @code
comment|/// struct point {
comment|///   double x;
comment|///   double y;
comment|/// };
comment|/// struct point ptarray[10] = { [2].y = 1.0, [2].x = 2.0, [0].x = 1.0 };
comment|/// @endcode
comment|///
comment|/// The InitListExpr contains three DesignatedInitExprs, the first of
comment|/// which covers @c [2].y=1.0. This DesignatedInitExpr will have two
comment|/// designators, one array designator for @c [2] followed by one field
comment|/// designator for @c .y. The initalization expression will be 1.0.
name|class
name|DesignatedInitExpr
operator|:
name|public
name|Expr
block|{
name|public
operator|:
comment|/// \brief Forward declaration of the Designator class.
name|class
name|Designator
block|;
name|private
operator|:
comment|/// The location of the '=' or ':' prior to the actual initializer
comment|/// expression.
name|SourceLocation
name|EqualOrColonLoc
block|;
comment|/// Whether this designated initializer used the GNU deprecated
comment|/// syntax rather than the C99 '=' syntax.
name|bool
name|GNUSyntax
operator|:
literal|1
block|;
comment|/// The number of designators in this initializer expression.
name|unsigned
name|NumDesignators
operator|:
literal|15
block|;
comment|/// \brief The designators in this designated initialization
comment|/// expression.
name|Designator
operator|*
name|Designators
block|;
comment|/// The number of subexpressions of this initializer expression,
comment|/// which contains both the initializer and any additional
comment|/// expressions used by array and array-range designators.
name|unsigned
name|NumSubExprs
operator|:
literal|16
block|;
name|DesignatedInitExpr
argument_list|(
argument|ASTContext&C
argument_list|,
argument|QualType Ty
argument_list|,
argument|unsigned NumDesignators
argument_list|,
argument|const Designator *Designators
argument_list|,
argument|SourceLocation EqualOrColonLoc
argument_list|,
argument|bool GNUSyntax
argument_list|,
argument|Expr **IndexExprs
argument_list|,
argument|unsigned NumIndexExprs
argument_list|,
argument|Expr *Init
argument_list|)
block|;
name|explicit
name|DesignatedInitExpr
argument_list|(
argument|unsigned NumSubExprs
argument_list|)
operator|:
name|Expr
argument_list|(
name|DesignatedInitExprClass
argument_list|,
name|EmptyShell
argument_list|()
argument_list|)
block|,
name|NumDesignators
argument_list|(
literal|0
argument_list|)
block|,
name|Designators
argument_list|(
literal|0
argument_list|)
block|,
name|NumSubExprs
argument_list|(
argument|NumSubExprs
argument_list|)
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
name|void
name|DestroyDesignators
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|public
operator|:
comment|/// A field designator, e.g., ".x".
expr|struct
name|FieldDesignator
block|{
comment|/// Refers to the field that is being initialized. The low bit
comment|/// of this field determines whether this is actually a pointer
comment|/// to an IdentifierInfo (if 1) or a FieldDecl (if 0). When
comment|/// initially constructed, a field designator will store an
comment|/// IdentifierInfo*. After semantic analysis has resolved that
comment|/// name, the field designator will instead store a FieldDecl*.
name|uintptr_t
name|NameOrField
block|;
comment|/// The location of the '.' in the designated initializer.
name|unsigned
name|DotLoc
block|;
comment|/// The location of the field name in the designated initializer.
name|unsigned
name|FieldLoc
block|;   }
block|;
comment|/// An array or GNU array-range designator, e.g., "[9]" or "[10..15]".
block|struct
name|ArrayOrRangeDesignator
block|{
comment|/// Location of the first index expression within the designated
comment|/// initializer expression's list of subexpressions.
name|unsigned
name|Index
block|;
comment|/// The location of the '[' starting the array range designator.
name|unsigned
name|LBracketLoc
block|;
comment|/// The location of the ellipsis separating the start and end
comment|/// indices. Only valid for GNU array-range designators.
name|unsigned
name|EllipsisLoc
block|;
comment|/// The location of the ']' terminating the array range designator.
name|unsigned
name|RBracketLoc
block|;   }
block|;
comment|/// @brief Represents a single C99 designator.
comment|///
comment|/// @todo This class is infuriatingly similar to clang::Designator,
comment|/// but minor differences (storing indices vs. storing pointers)
comment|/// keep us from reusing it. Try harder, later, to rectify these
comment|/// differences.
name|class
name|Designator
block|{
comment|/// @brief The kind of designator this describes.
block|enum
block|{
name|FieldDesignator
block|,
name|ArrayDesignator
block|,
name|ArrayRangeDesignator
block|}
name|Kind
block|;
expr|union
block|{
comment|/// A field designator, e.g., ".x".
block|struct
name|FieldDesignator
name|Field
block|;
comment|/// An array or GNU array-range designator, e.g., "[9]" or "[10..15]".
block|struct
name|ArrayOrRangeDesignator
name|ArrayOrRange
block|;     }
block|;
name|friend
name|class
name|DesignatedInitExpr
block|;
name|public
operator|:
name|Designator
argument_list|()
block|{}
comment|/// @brief Initializes a field designator.
name|Designator
argument_list|(
argument|const IdentifierInfo *FieldName
argument_list|,
argument|SourceLocation DotLoc
argument_list|,
argument|SourceLocation FieldLoc
argument_list|)
operator|:
name|Kind
argument_list|(
argument|FieldDesignator
argument_list|)
block|{
name|Field
operator|.
name|NameOrField
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|FieldName
operator|)
operator||
literal|0x01
block|;
name|Field
operator|.
name|DotLoc
operator|=
name|DotLoc
operator|.
name|getRawEncoding
argument_list|()
block|;
name|Field
operator|.
name|FieldLoc
operator|=
name|FieldLoc
operator|.
name|getRawEncoding
argument_list|()
block|;     }
comment|/// @brief Initializes an array designator.
name|Designator
argument_list|(
argument|unsigned Index
argument_list|,
argument|SourceLocation LBracketLoc
argument_list|,
argument|SourceLocation RBracketLoc
argument_list|)
operator|:
name|Kind
argument_list|(
argument|ArrayDesignator
argument_list|)
block|{
name|ArrayOrRange
operator|.
name|Index
operator|=
name|Index
block|;
name|ArrayOrRange
operator|.
name|LBracketLoc
operator|=
name|LBracketLoc
operator|.
name|getRawEncoding
argument_list|()
block|;
name|ArrayOrRange
operator|.
name|EllipsisLoc
operator|=
name|SourceLocation
argument_list|()
operator|.
name|getRawEncoding
argument_list|()
block|;
name|ArrayOrRange
operator|.
name|RBracketLoc
operator|=
name|RBracketLoc
operator|.
name|getRawEncoding
argument_list|()
block|;     }
comment|/// @brief Initializes a GNU array-range designator.
name|Designator
argument_list|(
argument|unsigned Index
argument_list|,
argument|SourceLocation LBracketLoc
argument_list|,
argument|SourceLocation EllipsisLoc
argument_list|,
argument|SourceLocation RBracketLoc
argument_list|)
operator|:
name|Kind
argument_list|(
argument|ArrayRangeDesignator
argument_list|)
block|{
name|ArrayOrRange
operator|.
name|Index
operator|=
name|Index
block|;
name|ArrayOrRange
operator|.
name|LBracketLoc
operator|=
name|LBracketLoc
operator|.
name|getRawEncoding
argument_list|()
block|;
name|ArrayOrRange
operator|.
name|EllipsisLoc
operator|=
name|EllipsisLoc
operator|.
name|getRawEncoding
argument_list|()
block|;
name|ArrayOrRange
operator|.
name|RBracketLoc
operator|=
name|RBracketLoc
operator|.
name|getRawEncoding
argument_list|()
block|;     }
name|bool
name|isFieldDesignator
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|FieldDesignator
return|;
block|}
name|bool
name|isArrayDesignator
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|ArrayDesignator
return|;
block|}
name|bool
name|isArrayRangeDesignator
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|ArrayRangeDesignator
return|;
block|}
name|IdentifierInfo
operator|*
name|getFieldName
argument_list|()
block|;
name|FieldDecl
operator|*
name|getField
argument_list|()
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|FieldDesignator
operator|&&
literal|"Only valid on a field designator"
argument_list|)
block|;
if|if
condition|(
name|Field
operator|.
name|NameOrField
operator|&
literal|0x01
condition|)
return|return
literal|0
return|;
else|else
return|return
name|reinterpret_cast
operator|<
name|FieldDecl
operator|*
operator|>
operator|(
name|Field
operator|.
name|NameOrField
operator|)
return|;
block|}
name|void
name|setField
argument_list|(
argument|FieldDecl *FD
argument_list|)
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|FieldDesignator
operator|&&
literal|"Only valid on a field designator"
argument_list|)
block|;
name|Field
operator|.
name|NameOrField
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|FD
operator|)
block|;     }
name|SourceLocation
name|getDotLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|FieldDesignator
operator|&&
literal|"Only valid on a field designator"
argument_list|)
block|;
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Field
operator|.
name|DotLoc
argument_list|)
return|;
block|}
name|SourceLocation
name|getFieldLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|FieldDesignator
operator|&&
literal|"Only valid on a field designator"
argument_list|)
block|;
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Field
operator|.
name|FieldLoc
argument_list|)
return|;
block|}
name|SourceLocation
name|getLBracketLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Kind
operator|==
name|ArrayDesignator
operator|||
name|Kind
operator|==
name|ArrayRangeDesignator
operator|)
operator|&&
literal|"Only valid on an array or array-range designator"
argument_list|)
block|;
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|ArrayOrRange
operator|.
name|LBracketLoc
argument_list|)
return|;
block|}
name|SourceLocation
name|getRBracketLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Kind
operator|==
name|ArrayDesignator
operator|||
name|Kind
operator|==
name|ArrayRangeDesignator
operator|)
operator|&&
literal|"Only valid on an array or array-range designator"
argument_list|)
block|;
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|ArrayOrRange
operator|.
name|RBracketLoc
argument_list|)
return|;
block|}
name|SourceLocation
name|getEllipsisLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|ArrayRangeDesignator
operator|&&
literal|"Only valid on an array-range designator"
argument_list|)
block|;
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|ArrayOrRange
operator|.
name|EllipsisLoc
argument_list|)
return|;
block|}
name|unsigned
name|getFirstExprIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Kind
operator|==
name|ArrayDesignator
operator|||
name|Kind
operator|==
name|ArrayRangeDesignator
operator|)
operator|&&
literal|"Only valid on an array or array-range designator"
argument_list|)
block|;
return|return
name|ArrayOrRange
operator|.
name|Index
return|;
block|}
name|SourceLocation
name|getStartLocation
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Kind
operator|==
name|FieldDesignator
condition|)
return|return
name|getDotLoc
argument_list|()
operator|.
name|isInvalid
argument_list|()
operator|?
name|getFieldLoc
argument_list|()
operator|:
name|getDotLoc
argument_list|()
return|;
else|else
return|return
name|getLBracketLoc
argument_list|()
return|;
block|}
expr|}
block|;
specifier|static
name|DesignatedInitExpr
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Designator *Designators
argument_list|,
argument|unsigned NumDesignators
argument_list|,
argument|Expr **IndexExprs
argument_list|,
argument|unsigned NumIndexExprs
argument_list|,
argument|SourceLocation EqualOrColonLoc
argument_list|,
argument|bool GNUSyntax
argument_list|,
argument|Expr *Init
argument_list|)
block|;
specifier|static
name|DesignatedInitExpr
operator|*
name|CreateEmpty
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned NumIndexExprs
argument_list|)
block|;
comment|/// @brief Returns the number of designators in this initializer.
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|NumDesignators
return|;
block|}
comment|// Iterator access to the designators.
typedef|typedef
name|Designator
modifier|*
name|designators_iterator
typedef|;
name|designators_iterator
name|designators_begin
argument_list|()
block|{
return|return
name|Designators
return|;
block|}
name|designators_iterator
name|designators_end
argument_list|()
block|{
return|return
name|Designators
operator|+
name|NumDesignators
return|;
block|}
name|Designator
operator|*
name|getDesignator
argument_list|(
argument|unsigned Idx
argument_list|)
block|{
return|return
operator|&
name|designators_begin
argument_list|()
index|[
name|Idx
index|]
return|;
block|}
name|void
name|setDesignators
argument_list|(
argument|ASTContext&C
argument_list|,
argument|const Designator *Desigs
argument_list|,
argument|unsigned NumDesigs
argument_list|)
block|;
name|Expr
operator|*
name|getArrayIndex
argument_list|(
specifier|const
name|Designator
operator|&
name|D
argument_list|)
block|;
name|Expr
operator|*
name|getArrayRangeStart
argument_list|(
specifier|const
name|Designator
operator|&
name|D
argument_list|)
block|;
name|Expr
operator|*
name|getArrayRangeEnd
argument_list|(
specifier|const
name|Designator
operator|&
name|D
argument_list|)
block|;
comment|/// @brief Retrieve the location of the '=' that precedes the
comment|/// initializer value itself, if present.
name|SourceLocation
name|getEqualOrColonLoc
argument_list|()
specifier|const
block|{
return|return
name|EqualOrColonLoc
return|;
block|}
name|void
name|setEqualOrColonLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|EqualOrColonLoc
operator|=
name|L
block|; }
comment|/// @brief Determines whether this designated initializer used the
comment|/// deprecated GNU syntax for designated initializers.
name|bool
name|usesGNUSyntax
argument_list|()
specifier|const
block|{
return|return
name|GNUSyntax
return|;
block|}
name|void
name|setGNUSyntax
argument_list|(
argument|bool GNU
argument_list|)
block|{
name|GNUSyntax
operator|=
name|GNU
block|; }
comment|/// @brief Retrieve the initializer value.
name|Expr
operator|*
name|getInit
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
operator|*
name|const_cast
operator|<
name|DesignatedInitExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|child_begin
argument_list|()
operator|)
return|;
block|}
name|void
name|setInit
argument_list|(
argument|Expr *init
argument_list|)
block|{
operator|*
name|child_begin
argument_list|()
operator|=
name|init
block|;   }
comment|/// \brief Retrieve the total number of subexpressions in this
comment|/// designated initializer expression, including the actual
comment|/// initialized value and any expressions that occur within array
comment|/// and array-range designators.
name|unsigned
name|getNumSubExprs
argument_list|()
specifier|const
block|{
return|return
name|NumSubExprs
return|;
block|}
name|Expr
operator|*
name|getSubExpr
argument_list|(
argument|unsigned Idx
argument_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|NumSubExprs
operator|&&
literal|"Subscript out of range"
argument_list|)
block|;
name|char
operator|*
name|Ptr
operator|=
name|static_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|this
operator|)
operator|)
block|;
name|Ptr
operator|+=
sizeof|sizeof
argument_list|(
name|DesignatedInitExpr
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|void
operator|*
operator|*
operator|>
operator|(
name|Ptr
operator|)
operator|)
index|[
name|Idx
index|]
return|;
block|}
name|void
name|setSubExpr
argument_list|(
argument|unsigned Idx
argument_list|,
argument|Expr *E
argument_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|NumSubExprs
operator|&&
literal|"Subscript out of range"
argument_list|)
block|;
name|char
operator|*
name|Ptr
operator|=
name|static_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|this
operator|)
operator|)
block|;
name|Ptr
operator|+=
sizeof|sizeof
argument_list|(
name|DesignatedInitExpr
argument_list|)
block|;
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|void
operator|*
operator|*
operator|>
operator|(
name|Ptr
operator|)
operator|)
index|[
name|Idx
index|]
operator|=
name|E
block|;   }
comment|/// \brief Replaces the designator at index @p Idx with the series
comment|/// of designators in [First, Last).
name|void
name|ExpandDesignator
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned Idx
argument_list|,
argument|const Designator *First
argument_list|,
argument|const Designator *Last
argument_list|)
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
name|DesignatedInitExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DesignatedInitExpr *
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
comment|/// \brief Represents an implicitly-generated value initialization of
comment|/// an object of a given type.
comment|///
comment|/// Implicit value initializations occur within semantic initializer
comment|/// list expressions (InitListExpr) as placeholders for subobject
comment|/// initializations not explicitly specified by the user.
comment|///
comment|/// \see InitListExpr
name|class
name|ImplicitValueInitExpr
operator|:
name|public
name|Expr
block|{
name|public
operator|:
name|explicit
name|ImplicitValueInitExpr
argument_list|(
argument|QualType ty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ImplicitValueInitExprClass
argument_list|,
argument|ty
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|)
block|{ }
comment|/// \brief Construct an empty implicit value initialization.
name|explicit
name|ImplicitValueInitExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ImplicitValueInitExprClass
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
name|ImplicitValueInitExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ImplicitValueInitExpr *
argument_list|)
block|{
return|return
name|true
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
name|class
name|ParenListExpr
operator|:
name|public
name|Expr
block|{
name|Stmt
operator|*
operator|*
name|Exprs
block|;
name|unsigned
name|NumExprs
block|;
name|SourceLocation
name|LParenLoc
block|,
name|RParenLoc
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
name|ParenListExpr
argument_list|(
argument|ASTContext& C
argument_list|,
argument|SourceLocation lparenloc
argument_list|,
argument|Expr **exprs
argument_list|,
argument|unsigned numexprs
argument_list|,
argument|SourceLocation rparenloc
argument_list|)
block|;
operator|~
name|ParenListExpr
argument_list|()
block|{}
comment|/// \brief Build an empty paren list.
name|explicit
name|ParenListExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ParenListExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|unsigned
name|getNumExprs
argument_list|()
specifier|const
block|{
return|return
name|NumExprs
return|;
block|}
specifier|const
name|Expr
operator|*
name|getExpr
argument_list|(
argument|unsigned Init
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Init
operator|<
name|getNumExprs
argument_list|()
operator|&&
literal|"Initializer access out of range!"
argument_list|)
block|;
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|Exprs
index|[
name|Init
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getExpr
argument_list|(
argument|unsigned Init
argument_list|)
block|{
name|assert
argument_list|(
name|Init
operator|<
name|getNumExprs
argument_list|()
operator|&&
literal|"Initializer access out of range!"
argument_list|)
block|;
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|Exprs
index|[
name|Init
index|]
operator|)
return|;
block|}
name|Expr
operator|*
operator|*
name|getExprs
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
name|Exprs
operator|)
return|;
block|}
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
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
name|LParenLoc
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
name|ParenListExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ParenListExpr *
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
block|;
name|friend
name|class
name|PCHStmtReader
block|;
name|friend
name|class
name|PCHStmtWriter
block|; }
block|;
comment|//===----------------------------------------------------------------------===//
comment|// Clang Extensions
comment|//===----------------------------------------------------------------------===//
comment|/// ExtVectorElementExpr - This represents access to specific elements of a
comment|/// vector, and may occur on the left hand side or right hand side.  For example
comment|/// the following is legal:  "V.xy = V.zw" if V is a 4 element extended vector.
comment|///
comment|/// Note that the base may have either vector or pointer to vector type, just
comment|/// like a struct field reference.
comment|///
name|class
name|ExtVectorElementExpr
operator|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|Base
block|;
name|IdentifierInfo
operator|*
name|Accessor
block|;
name|SourceLocation
name|AccessorLoc
block|;
name|public
operator|:
name|ExtVectorElementExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|Expr *base
argument_list|,
argument|IdentifierInfo&accessor
argument_list|,
argument|SourceLocation loc
argument_list|)
operator|:
name|Expr
argument_list|(
name|ExtVectorElementExprClass
argument_list|,
name|ty
argument_list|,
name|base
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|base
operator|->
name|isValueDependent
argument_list|()
argument_list|)
block|,
name|Base
argument_list|(
name|base
argument_list|)
block|,
name|Accessor
argument_list|(
operator|&
name|accessor
argument_list|)
block|,
name|AccessorLoc
argument_list|(
argument|loc
argument_list|)
block|{}
comment|/// \brief Build an empty vector element expression.
name|explicit
name|ExtVectorElementExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ExtVectorElementExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
specifier|const
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
name|IdentifierInfo
operator|&
name|getAccessor
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Accessor
return|;
block|}
name|void
name|setAccessor
argument_list|(
argument|IdentifierInfo *II
argument_list|)
block|{
name|Accessor
operator|=
name|II
block|; }
name|SourceLocation
name|getAccessorLoc
argument_list|()
specifier|const
block|{
return|return
name|AccessorLoc
return|;
block|}
name|void
name|setAccessorLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|AccessorLoc
operator|=
name|L
block|; }
comment|/// getNumElements - Get the number of components being selected.
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|;
comment|/// containsDuplicateElements - Return true if any element access is
comment|/// repeated.
name|bool
name|containsDuplicateElements
argument_list|()
specifier|const
block|;
comment|/// getEncodedElementAccess - Encode the elements accessed into an llvm
comment|/// aggregate Constant of ConstantInt(s).
name|void
name|getEncodedElementAccess
argument_list|(
argument|llvm::SmallVectorImpl<unsigned>&Elts
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
name|getBase
argument_list|()
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|AccessorLoc
argument_list|)
return|;
block|}
comment|/// isArrow - Return true if the base expression is a pointer to vector,
comment|/// return false if the base expression is a vector.
name|bool
name|isArrow
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
name|ExtVectorElementExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ExtVectorElementExpr *
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
comment|/// BlockExpr - Adaptor class for mixing a BlockDecl with expressions.
comment|/// ^{ statement-body }   or   ^(int arg1, float arg2){ statement-body }
name|class
name|BlockExpr
operator|:
name|public
name|Expr
block|{
name|protected
operator|:
name|BlockDecl
operator|*
name|TheBlock
block|;
name|bool
name|HasBlockDeclRefExprs
block|;
name|public
operator|:
name|BlockExpr
argument_list|(
argument|BlockDecl *BD
argument_list|,
argument|QualType ty
argument_list|,
argument|bool hasBlockDeclRefExprs
argument_list|)
operator|:
name|Expr
argument_list|(
name|BlockExprClass
argument_list|,
name|ty
argument_list|,
name|ty
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|false
argument_list|)
block|,
name|TheBlock
argument_list|(
name|BD
argument_list|)
block|,
name|HasBlockDeclRefExprs
argument_list|(
argument|hasBlockDeclRefExprs
argument_list|)
block|{}
comment|/// \brief Build an empty block expression.
name|explicit
name|BlockExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|BlockExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
specifier|const
name|BlockDecl
operator|*
name|getBlockDecl
argument_list|()
specifier|const
block|{
return|return
name|TheBlock
return|;
block|}
name|BlockDecl
operator|*
name|getBlockDecl
argument_list|()
block|{
return|return
name|TheBlock
return|;
block|}
name|void
name|setBlockDecl
argument_list|(
argument|BlockDecl *BD
argument_list|)
block|{
name|TheBlock
operator|=
name|BD
block|; }
comment|// Convenience functions for probing the underlying BlockDecl.
name|SourceLocation
name|getCaretLocation
argument_list|()
specifier|const
block|;
specifier|const
name|Stmt
operator|*
name|getBody
argument_list|()
specifier|const
block|;
name|Stmt
operator|*
name|getBody
argument_list|()
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
name|getCaretLocation
argument_list|()
argument_list|,
name|getBody
argument_list|()
operator|->
name|getLocEnd
argument_list|()
argument_list|)
return|;
block|}
comment|/// getFunctionType - Return the underlying function type for this block.
specifier|const
name|FunctionType
operator|*
name|getFunctionType
argument_list|()
specifier|const
block|;
comment|/// hasBlockDeclRefExprs - Return true iff the block has BlockDeclRefExpr
comment|/// inside of the block that reference values outside the block.
name|bool
name|hasBlockDeclRefExprs
argument_list|()
specifier|const
block|{
return|return
name|HasBlockDeclRefExprs
return|;
block|}
name|void
name|setHasBlockDeclRefExprs
argument_list|(
argument|bool BDRE
argument_list|)
block|{
name|HasBlockDeclRefExprs
operator|=
name|BDRE
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
name|BlockExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const BlockExpr *
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
comment|/// BlockDeclRefExpr - A reference to a declared variable, function,
comment|/// enum, etc.
name|class
name|BlockDeclRefExpr
operator|:
name|public
name|Expr
block|{
name|ValueDecl
operator|*
name|D
block|;
name|SourceLocation
name|Loc
block|;
name|bool
name|IsByRef
operator|:
literal|1
block|;
name|bool
name|ConstQualAdded
operator|:
literal|1
block|;
name|Stmt
operator|*
name|CopyConstructorVal
block|;
name|public
operator|:
comment|// FIXME: Fix type/value dependence!
name|BlockDeclRefExpr
argument_list|(
argument|ValueDecl *d
argument_list|,
argument|QualType t
argument_list|,
argument|SourceLocation l
argument_list|,
argument|bool ByRef
argument_list|,
argument|bool constAdded = false
argument_list|,
argument|Stmt *copyConstructorVal =
literal|0
argument_list|)
operator|:
name|Expr
argument_list|(
name|BlockDeclRefExprClass
argument_list|,
name|t
argument_list|,
operator|(
operator|!
name|t
operator|.
name|isNull
argument_list|()
operator|&&
name|t
operator|->
name|isDependentType
argument_list|()
operator|)
argument_list|,
name|false
argument_list|)
block|,
name|D
argument_list|(
name|d
argument_list|)
block|,
name|Loc
argument_list|(
name|l
argument_list|)
block|,
name|IsByRef
argument_list|(
name|ByRef
argument_list|)
block|,
name|ConstQualAdded
argument_list|(
name|constAdded
argument_list|)
block|,
name|CopyConstructorVal
argument_list|(
argument|copyConstructorVal
argument_list|)
block|{}
comment|// \brief Build an empty reference to a declared variable in a
comment|// block.
name|explicit
name|BlockDeclRefExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|BlockDeclRefExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|ValueDecl
operator|*
name|getDecl
argument_list|()
block|{
return|return
name|D
return|;
block|}
specifier|const
name|ValueDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|D
return|;
block|}
name|void
name|setDecl
argument_list|(
argument|ValueDecl *VD
argument_list|)
block|{
name|D
operator|=
name|VD
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
argument_list|)
return|;
block|}
name|bool
name|isByRef
argument_list|()
specifier|const
block|{
return|return
name|IsByRef
return|;
block|}
name|void
name|setByRef
argument_list|(
argument|bool BR
argument_list|)
block|{
name|IsByRef
operator|=
name|BR
block|; }
name|bool
name|isConstQualAdded
argument_list|()
specifier|const
block|{
return|return
name|ConstQualAdded
return|;
block|}
name|void
name|setConstQualAdded
argument_list|(
argument|bool C
argument_list|)
block|{
name|ConstQualAdded
operator|=
name|C
block|; }
specifier|const
name|Expr
operator|*
name|getCopyConstructorExpr
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|CopyConstructorVal
operator|)
return|;
block|}
name|Expr
operator|*
name|getCopyConstructorExpr
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|CopyConstructorVal
operator|)
return|;
block|}
name|void
name|setCopyConstructorExpr
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|CopyConstructorVal
operator|=
name|E
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
name|BlockDeclRefExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const BlockDeclRefExpr *
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

