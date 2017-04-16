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
file|"clang/AST/ASTVector.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclAccessPair.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/OperationKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateBase.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/CharInfo.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TypeTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APFloat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APSInt.h"
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
file|"llvm/Support/AtomicOrdering.h"
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
name|APValue
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|BlockDecl
decl_stmt|;
name|class
name|CXXBaseSpecifier
decl_stmt|;
name|class
name|CXXMemberCallExpr
decl_stmt|;
name|class
name|CXXOperatorCallExpr
decl_stmt|;
name|class
name|CastExpr
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|MaterializeTemporaryExpr
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|ObjCPropertyRefExpr
decl_stmt|;
name|class
name|OpaqueValueExpr
decl_stmt|;
name|class
name|ParmVarDecl
decl_stmt|;
name|class
name|StringLiteral
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|ValueDecl
decl_stmt|;
comment|/// \brief A simple array of base specifiers.
typedef|typedef
name|SmallVector
operator|<
name|CXXBaseSpecifier
operator|*
operator|,
literal|4
operator|>
name|CXXCastPath
expr_stmt|;
comment|/// \brief An adjustment to be made to the temporary created when emitting a
comment|/// reference binding, which accesses a particular subobject of that temporary.
struct|struct
name|SubobjectAdjustment
block|{
enum|enum
block|{
name|DerivedToBaseAdjustment
block|,
name|FieldAdjustment
block|,
name|MemberPointerAdjustment
block|}
name|Kind
enum|;
struct|struct
name|DTB
block|{
specifier|const
name|CastExpr
modifier|*
name|BasePath
decl_stmt|;
specifier|const
name|CXXRecordDecl
modifier|*
name|DerivedClass
decl_stmt|;
block|}
struct|;
struct|struct
name|P
block|{
specifier|const
name|MemberPointerType
modifier|*
name|MPT
decl_stmt|;
name|Expr
modifier|*
name|RHS
decl_stmt|;
block|}
struct|;
union|union
block|{
name|struct
name|DTB
name|DerivedToBase
decl_stmt|;
name|FieldDecl
modifier|*
name|Field
decl_stmt|;
name|struct
name|P
name|Ptr
decl_stmt|;
block|}
union|;
name|SubobjectAdjustment
argument_list|(
specifier|const
name|CastExpr
operator|*
name|BasePath
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|DerivedClass
argument_list|)
operator|:
name|Kind
argument_list|(
argument|DerivedToBaseAdjustment
argument_list|)
block|{
name|DerivedToBase
operator|.
name|BasePath
operator|=
name|BasePath
block|;
name|DerivedToBase
operator|.
name|DerivedClass
operator|=
name|DerivedClass
block|;   }
name|SubobjectAdjustment
argument_list|(
name|FieldDecl
operator|*
name|Field
argument_list|)
operator|:
name|Kind
argument_list|(
argument|FieldAdjustment
argument_list|)
block|{
name|this
operator|->
name|Field
operator|=
name|Field
block|;   }
name|SubobjectAdjustment
argument_list|(
specifier|const
name|MemberPointerType
operator|*
name|MPT
argument_list|,
name|Expr
operator|*
name|RHS
argument_list|)
operator|:
name|Kind
argument_list|(
argument|MemberPointerAdjustment
argument_list|)
block|{
name|this
operator|->
name|Ptr
operator|.
name|MPT
operator|=
name|MPT
block|;
name|this
operator|->
name|Ptr
operator|.
name|RHS
operator|=
name|RHS
block|;   }
block|}
struct|;
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
name|protected
operator|:
name|Expr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|bool TD
argument_list|,
argument|bool VD
argument_list|,
argument|bool ID
argument_list|,
argument|bool ContainsUnexpandedParameterPack
argument_list|)
operator|:
name|Stmt
argument_list|(
argument|SC
argument_list|)
block|{
name|ExprBits
operator|.
name|TypeDependent
operator|=
name|TD
block|;
name|ExprBits
operator|.
name|ValueDependent
operator|=
name|VD
block|;
name|ExprBits
operator|.
name|InstantiationDependent
operator|=
name|ID
block|;
name|ExprBits
operator|.
name|ValueKind
operator|=
name|VK
block|;
name|ExprBits
operator|.
name|ObjectKind
operator|=
name|OK
block|;
name|assert
argument_list|(
name|ExprBits
operator|.
name|ObjectKind
operator|==
name|OK
operator|&&
literal|"truncated kind"
argument_list|)
block|;
name|ExprBits
operator|.
name|ContainsUnexpandedParameterPack
operator|=
name|ContainsUnexpandedParameterPack
block|;
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
comment|// will not have reference type (C++ [expr]p6). Use
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
name|ExprBits
operator|.
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
name|ExprBits
operator|.
name|ValueDependent
operator|=
name|VD
block|;   }
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
name|ExprBits
operator|.
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
name|ExprBits
operator|.
name|TypeDependent
operator|=
name|TD
block|;   }
comment|/// \brief Whether this expression is instantiation-dependent, meaning that
comment|/// it depends in some way on a template parameter, even if neither its type
comment|/// nor (constant) value can change due to the template instantiation.
comment|///
comment|/// In the following example, the expression \c sizeof(sizeof(T() + T())) is
comment|/// instantiation-dependent (since it involves a template parameter \c T), but
comment|/// is neither type- nor value-dependent, since the type of the inner
comment|/// \c sizeof is known (\c std::size_t) and therefore the size of the outer
comment|/// \c sizeof is known.
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// void f(T x, T y) {
comment|///   sizeof(sizeof(T() + T());
comment|/// }
comment|/// \endcode
comment|///
name|bool
name|isInstantiationDependent
argument_list|()
specifier|const
block|{
return|return
name|ExprBits
operator|.
name|InstantiationDependent
return|;
block|}
comment|/// \brief Set whether this expression is instantiation-dependent or not.
name|void
name|setInstantiationDependent
argument_list|(
argument|bool ID
argument_list|)
block|{
name|ExprBits
operator|.
name|InstantiationDependent
operator|=
name|ID
block|;   }
comment|/// \brief Whether this expression contains an unexpanded parameter
comment|/// pack (for C++11 variadic templates).
comment|///
comment|/// Given the following function template:
comment|///
comment|/// \code
comment|/// template<typename F, typename ...Types>
comment|/// void forward(const F&f, Types&&...args) {
comment|///   f(static_cast<Types&&>(args)...);
comment|/// }
comment|/// \endcode
comment|///
comment|/// The expressions \c args and \c static_cast<Types&&>(args) both
comment|/// contain parameter packs.
name|bool
name|containsUnexpandedParameterPack
argument_list|()
specifier|const
block|{
return|return
name|ExprBits
operator|.
name|ContainsUnexpandedParameterPack
return|;
block|}
comment|/// \brief Set the bit that describes whether this expression
comment|/// contains an unexpanded parameter pack.
name|void
name|setContainsUnexpandedParameterPack
argument_list|(
argument|bool PP = true
argument_list|)
block|{
name|ExprBits
operator|.
name|ContainsUnexpandedParameterPack
operator|=
name|PP
block|;   }
comment|/// getExprLoc - Return the preferred location for the arrow when diagnosing
comment|/// a problem with a generic expression.
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
name|LLVM_READONLY
block|;
comment|/// isUnusedResultAWarning - Return true if this immediate expression should
comment|/// be warned about if the result is unused.  If so, fill in expr, location,
comment|/// and ranges with expr to warn on and source locations/ranges appropriate
comment|/// for a warning.
name|bool
name|isUnusedResultAWarning
argument_list|(
argument|const Expr *&WarnExpr
argument_list|,
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
comment|/// isLValue - True if this expression is an "l-value" according to
comment|/// the rules of the current language.  C and C++ give somewhat
comment|/// different rules for this concept, but in general, the result of
comment|/// an l-value expression identifies a specific object whereas the
comment|/// result of an r-value expression is a value detached from any
comment|/// specific storage.
comment|///
comment|/// C++11 divides the concept of "r-value" into pure r-values
comment|/// ("pr-values") and so-called expiring values ("x-values"), which
comment|/// identify specific objects that can be safely cannibalized for
comment|/// their resources.  This is an unfortunate abuse of terminology on
comment|/// the part of the C++ committee.  In Clang, when we say "r-value",
comment|/// we generally mean a pr-value.
name|bool
name|isLValue
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
name|bool
name|isRValue
argument_list|()
specifier|const
block|{
return|return
name|getValueKind
argument_list|()
operator|==
name|VK_RValue
return|;
block|}
name|bool
name|isXValue
argument_list|()
specifier|const
block|{
return|return
name|getValueKind
argument_list|()
operator|==
name|VK_XValue
return|;
block|}
name|bool
name|isGLValue
argument_list|()
specifier|const
block|{
return|return
name|getValueKind
argument_list|()
operator|!=
name|VK_RValue
return|;
block|}
expr|enum
name|LValueClassification
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
name|LV_InvalidMessageExpression
block|,
name|LV_MemberFunction
block|,
name|LV_SubObjCPropertySetting
block|,
name|LV_ClassTemporary
block|,
name|LV_ArrayTemporary
block|}
block|;
comment|/// Reasons why an expression might not be an l-value.
name|LValueClassification
name|ClassifyLValue
argument_list|(
argument|ASTContext&Ctx
argument_list|)
specifier|const
block|;    enum
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
name|MLV_ConstAddrSpace
block|,
name|MLV_ArrayType
block|,
name|MLV_NoSetterProperty
block|,
name|MLV_MemberFunction
block|,
name|MLV_SubObjCPropertySetting
block|,
name|MLV_InvalidMessageExpression
block|,
name|MLV_ClassTemporary
block|,
name|MLV_ArrayTemporary
block|}
block|;
comment|/// isModifiableLvalue - C99 6.3.2.1: an lvalue that does not have array type,
comment|/// does not have an incomplete type, does not have a const-qualified type,
comment|/// and if it is a structure or union, does not have any member (including,
comment|/// recursively, any member or element of all contained aggregates or unions)
comment|/// with a const-qualified type.
comment|///
comment|/// \param Loc [in,out] - A source location which *may* be filled
comment|/// in with the location of the expression making this a
comment|/// non-modifiable lvalue, if specified.
name|isModifiableLvalueResult
name|isModifiableLvalue
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|SourceLocation *Loc = nullptr
argument_list|)
specifier|const
block|;
comment|/// \brief The return type of classify(). Represents the C++11 expression
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
name|CL_AddressableVoid
block|,
comment|// Void expression whose address can be taken in C.
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
comment|// A temporary of class type, or subobject thereof.
name|CL_ArrayTemporary
block|,
comment|// A temporary of array type.
name|CL_ObjCMessageRValue
block|,
comment|// ObjC message is an rvalue
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
name|CM_NoSetterProperty
block|,
comment|// Implicit assignment to ObjC property without setter
name|CM_ConstQualified
block|,
name|CM_ConstAddrSpace
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
comment|/// \brief Create a simple, modifiably lvalue
specifier|static
name|Classification
name|makeSimpleLValue
argument_list|()
block|{
return|return
name|Classification
argument_list|(
name|CL_LValue
argument_list|,
name|CM_Modifiable
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief Classify - Classify this expression according to the C++11
comment|///        expression taxonomy.
comment|///
comment|/// C++11 defines ([basic.lval]) a new taxonomy of expressions to replace the
comment|/// old lvalue vs rvalue. This function determines the type of expression this
comment|/// is. There are three expression types:
comment|/// - lvalues are classical lvalues as in C++03.
comment|/// - prvalues are equivalent to rvalues in C++03.
comment|/// - xvalues are expressions yielding unnamed rvalue references, e.g. a
comment|///   function returning an rvalue reference.
comment|/// lvalues and xvalues are collectively referred to as glvalues, while
comment|/// prvalues and xvalues together form rvalues.
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
name|nullptr
argument_list|)
return|;
block|}
comment|/// \brief ClassifyModifiable - Classify this expression according to the
comment|///        C++11 expression taxonomy, and see if it is valid on the left side
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
comment|/// getValueKindForType - Given a formal return or parameter type,
comment|/// give its value kind.
specifier|static
name|ExprValueKind
name|getValueKindForType
argument_list|(
argument|QualType T
argument_list|)
block|{
if|if
condition|(
specifier|const
name|ReferenceType
modifier|*
name|RT
init|=
name|T
operator|->
name|getAs
operator|<
name|ReferenceType
operator|>
operator|(
operator|)
condition|)
return|return
operator|(
name|isa
operator|<
name|LValueReferenceType
operator|>
operator|(
name|RT
operator|)
operator|?
name|VK_LValue
operator|:
operator|(
name|RT
operator|->
name|getPointeeType
argument_list|()
operator|->
name|isFunctionType
argument_list|()
operator|?
name|VK_LValue
operator|:
name|VK_XValue
operator|)
operator|)
return|;
return|return
name|VK_RValue
return|;
block|}
comment|/// getValueKind - The value kind that this expression produces.
name|ExprValueKind
name|getValueKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ExprValueKind
operator|>
operator|(
name|ExprBits
operator|.
name|ValueKind
operator|)
return|;
block|}
comment|/// getObjectKind - The object kind that this expression produces.
comment|/// Object kinds are meaningful only for expressions that yield an
comment|/// l-value or x-value.
name|ExprObjectKind
name|getObjectKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ExprObjectKind
operator|>
operator|(
name|ExprBits
operator|.
name|ObjectKind
operator|)
return|;
block|}
name|bool
name|isOrdinaryOrBitFieldObject
argument_list|()
specifier|const
block|{
name|ExprObjectKind
name|OK
operator|=
name|getObjectKind
argument_list|()
block|;
return|return
operator|(
name|OK
operator|==
name|OK_Ordinary
operator|||
name|OK
operator|==
name|OK_BitField
operator|)
return|;
block|}
comment|/// setValueKind - Set the value kind produced by this expression.
name|void
name|setValueKind
argument_list|(
argument|ExprValueKind Cat
argument_list|)
block|{
name|ExprBits
operator|.
name|ValueKind
operator|=
name|Cat
block|; }
comment|/// setObjectKind - Set the object kind produced by this expression.
name|void
name|setObjectKind
argument_list|(
argument|ExprObjectKind Cat
argument_list|)
block|{
name|ExprBits
operator|.
name|ObjectKind
operator|=
name|Cat
block|; }
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
comment|/// \brief Returns true if this expression is a gl-value that
comment|/// potentially refers to a bit-field.
comment|///
comment|/// In C++, whether a gl-value refers to a bitfield is essentially
comment|/// an aspect of the value-kind type system.
name|bool
name|refersToBitField
argument_list|()
specifier|const
block|{
return|return
name|getObjectKind
argument_list|()
operator|==
name|OK_BitField
return|;
block|}
comment|/// \brief If this expression refers to a bit-field, retrieve the
comment|/// declaration of that bit-field.
comment|///
comment|/// Note that this returns a non-null pointer in subtly different
comment|/// places than refersToBitField returns true.  In particular, this can
comment|/// return a non-null pointer even for r-values loaded from
comment|/// bit-fields, but it will return null for a conditional bit-field.
name|FieldDecl
operator|*
name|getSourceBitField
argument_list|()
block|;
specifier|const
name|FieldDecl
operator|*
name|getSourceBitField
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
name|getSourceBitField
argument_list|()
return|;
block|}
name|Decl
operator|*
name|getReferencedDeclOfCallee
argument_list|()
block|;
specifier|const
name|Decl
operator|*
name|getReferencedDeclOfCallee
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
name|getReferencedDeclOfCallee
argument_list|()
return|;
block|}
comment|/// \brief If this expression is an l-value for an Objective C
comment|/// property, find the underlying property reference expression.
specifier|const
name|ObjCPropertyRefExpr
operator|*
name|getObjCProperty
argument_list|()
specifier|const
block|;
comment|/// \brief Check if this expression is the ObjC 'self' implicit parameter.
name|bool
name|isObjCSelfExpr
argument_list|()
specifier|const
block|;
comment|/// \brief Returns whether this expression refers to a vector element.
name|bool
name|refersToVectorElement
argument_list|()
specifier|const
block|;
comment|/// \brief Returns whether this expression refers to a global register
comment|/// variable.
name|bool
name|refersToGlobalRegisterVar
argument_list|()
specifier|const
block|;
comment|/// \brief Returns whether this expression has a placeholder type.
name|bool
name|hasPlaceholderType
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|->
name|isPlaceholderType
argument_list|()
return|;
block|}
comment|/// \brief Returns whether this expression has a specific placeholder type.
name|bool
name|hasPlaceholderType
argument_list|(
argument|BuiltinType::Kind K
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|BuiltinType
operator|::
name|isPlaceholderTypeKind
argument_list|(
name|K
argument_list|)
argument_list|)
block|;
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|getType
argument_list|()
operator|)
condition|)
return|return
name|BT
operator|->
name|getKind
argument_list|()
operator|==
name|K
return|;
return|return
name|false
return|;
block|}
comment|/// isKnownToHaveBooleanValue - Return true if this is an integer expression
comment|/// that is known to return 0 or 1.  This happens for _Bool/bool expressions
comment|/// but also int expressions which are produced by things like comparisons in
comment|/// C.
name|bool
name|isKnownToHaveBooleanValue
argument_list|()
specifier|const
expr_stmt|;
comment|/// isIntegerConstantExpr - Return true if this expression is a valid integer
comment|/// constant expression, and, if so, return its value in Result.  If not a
comment|/// valid i-c-e, return false and fill in Loc (if specified) with the location
comment|/// of the invalid expression.
comment|///
comment|/// Note: This does not perform the implicit conversions required by C++11
comment|/// [expr.const]p5.
name|bool
name|isIntegerConstantExpr
argument_list|(
name|llvm
operator|::
name|APSInt
operator|&
name|Result
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|SourceLocation
operator|*
name|Loc
operator|=
name|nullptr
argument_list|,
name|bool
name|isEvaluated
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isIntegerConstantExpr
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|SourceLocation
operator|*
name|Loc
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// isCXX98IntegralConstantExpr - Return true if this expression is an
comment|/// integral constant expression in C++98. Can only be used in C++.
name|bool
name|isCXX98IntegralConstantExpr
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// isCXX11ConstantExpr - Return true if this expression is a constant
comment|/// expression in C++11. Can only be used in C++.
comment|///
comment|/// Note: This does not perform the implicit conversions required by C++11
comment|/// [expr.const]p5.
name|bool
name|isCXX11ConstantExpr
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|APValue
operator|*
name|Result
operator|=
name|nullptr
argument_list|,
name|SourceLocation
operator|*
name|Loc
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// isPotentialConstantExpr - Return true if this function's definition
comment|/// might be usable in a constant expression in C++11, if it were marked
comment|/// constexpr. Return false if the function can never produce a constant
comment|/// expression, along with diagnostics describing why not.
specifier|static
name|bool
name|isPotentialConstantExpr
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|,
name|SmallVectorImpl
operator|<
name|PartialDiagnosticAt
operator|>
operator|&
name|Diags
argument_list|)
decl_stmt|;
comment|/// isPotentialConstantExprUnevaluted - Return true if this expression might
comment|/// be usable in a constant expression in C++11 in an unevaluated context, if
comment|/// it were in function FD marked constexpr. Return false if the function can
comment|/// never produce a constant expression, along with diagnostics describing
comment|/// why not.
specifier|static
name|bool
name|isPotentialConstantExprUnevaluated
argument_list|(
name|Expr
operator|*
name|E
argument_list|,
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|,
name|SmallVectorImpl
operator|<
name|PartialDiagnosticAt
operator|>
operator|&
name|Diags
argument_list|)
decl_stmt|;
comment|/// isConstantInitializer - Returns true if this expression can be emitted to
comment|/// IR as a constant, and thus can be used as a constant initializer in C.
comment|/// If this expression is not constant and Culprit is non-null,
comment|/// it is used to store the address of first non constant expr.
name|bool
name|isConstantInitializer
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|bool
name|ForRef
argument_list|,
specifier|const
name|Expr
operator|*
operator|*
name|Culprit
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// EvalStatus is a struct with detailed info about an evaluation in progress.
struct|struct
name|EvalStatus
block|{
comment|/// \brief Whether the evaluated expression has side effects.
comment|/// For example, (f()&& 0) can be folded, but it still has side effects.
name|bool
name|HasSideEffects
decl_stmt|;
comment|/// \brief Whether the evaluation hit undefined behavior.
comment|/// For example, 1.0 / 0.0 can be folded to Inf, but has undefined behavior.
comment|/// Likewise, INT_MAX + 1 can be folded to INT_MIN, but has UB.
name|bool
name|HasUndefinedBehavior
decl_stmt|;
comment|/// Diag - If this is non-null, it will be filled in with a stack of notes
comment|/// indicating why evaluation failed (or why it failed to produce a constant
comment|/// expression).
comment|/// If the expression is unfoldable, the notes will indicate why it's not
comment|/// foldable. If the expression is foldable, but not a constant expression,
comment|/// the notes will describes why it isn't a constant expression. If the
comment|/// expression *is* a constant expression, no notes will be produced.
name|SmallVectorImpl
operator|<
name|PartialDiagnosticAt
operator|>
operator|*
name|Diag
expr_stmt|;
name|EvalStatus
argument_list|()
operator|:
name|HasSideEffects
argument_list|(
name|false
argument_list|)
operator|,
name|HasUndefinedBehavior
argument_list|(
name|false
argument_list|)
operator|,
name|Diag
argument_list|(
argument|nullptr
argument_list|)
block|{}
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
block|}
struct|;
comment|/// EvalResult is a struct with detailed info about an evaluated expression.
name|struct
name|EvalResult
range|:
name|EvalStatus
block|{
comment|/// Val - This is the value the expression can be folded to.
name|APValue
name|Val
block|;
comment|// isGlobalLValue - Return true if the evaluated lvalue expression
comment|// is global.
name|bool
name|isGlobalLValue
argument_list|()
specifier|const
block|;   }
decl_stmt|;
comment|/// EvaluateAsRValue - Return true if this is a constant which we can fold to
comment|/// an rvalue using any crazy technique (that has nothing to do with language
comment|/// standards) that we want to, even if the expression has side-effects. If
comment|/// this function returns true, it returns the folded constant in Result. If
comment|/// the expression is a glvalue, an lvalue-to-rvalue conversion will be
comment|/// applied.
name|bool
name|EvaluateAsRValue
argument_list|(
name|EvalResult
operator|&
name|Result
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// EvaluateAsBooleanCondition - Return true if this is a constant
comment|/// which we we can fold and convert to a boolean condition using
comment|/// any crazy technique that we want to, even if the expression has
comment|/// side-effects.
name|bool
name|EvaluateAsBooleanCondition
argument_list|(
name|bool
operator|&
name|Result
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
enum|enum
name|SideEffectsKind
block|{
name|SE_NoSideEffects
block|,
comment|///< Strictly evaluate the expression.
name|SE_AllowUndefinedBehavior
block|,
comment|///< Allow UB that we can give a value, but not
comment|///< arbitrary unmodeled side effects.
name|SE_AllowSideEffects
comment|///< Allow any unmodeled side effect.
block|}
enum|;
comment|/// EvaluateAsInt - Return true if this is a constant which we can fold and
comment|/// convert to an integer, using any crazy technique that we want to.
name|bool
name|EvaluateAsInt
argument_list|(
name|llvm
operator|::
name|APSInt
operator|&
name|Result
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|SideEffectsKind
name|AllowSideEffects
operator|=
name|SE_NoSideEffects
argument_list|)
decl|const
decl_stmt|;
comment|/// EvaluateAsFloat - Return true if this is a constant which we can fold and
comment|/// convert to a floating point value, using any crazy technique that we
comment|/// want to.
name|bool
name|EvaluateAsFloat
argument_list|(
name|llvm
operator|::
name|APFloat
operator|&
name|Result
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|SideEffectsKind
name|AllowSideEffects
operator|=
name|SE_NoSideEffects
argument_list|)
decl|const
decl_stmt|;
comment|/// isEvaluatable - Call EvaluateAsRValue to see if this expression can be
comment|/// constant folded without side-effects, but discard the result.
name|bool
name|isEvaluatable
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|SideEffectsKind
name|AllowSideEffects
operator|=
name|SE_NoSideEffects
argument_list|)
decl|const
decl_stmt|;
comment|/// HasSideEffects - This routine returns true for all those expressions
comment|/// which have any effect other than producing a value. Example is a function
comment|/// call, volatile variable read, or throwing an exception. If
comment|/// IncludePossibleEffects is false, this call treats certain expressions with
comment|/// potential side effects (such as function call-like expressions,
comment|/// instantiation-dependent expressions, or invocations from a macro) as not
comment|/// having side effects.
name|bool
name|HasSideEffects
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|bool
name|IncludePossibleEffects
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Determine whether this expression involves a call to any function
comment|/// that is not trivial.
name|bool
name|hasNonTrivialCall
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// EvaluateKnownConstInt - Call EvaluateAsRValue and return the folded
comment|/// integer. This must be called on an expression that constant folds to an
comment|/// integer.
name|llvm
operator|::
name|APSInt
name|EvaluateKnownConstInt
argument_list|(
argument|const ASTContext&Ctx
argument_list|,
argument|SmallVectorImpl<PartialDiagnosticAt> *Diag = nullptr
argument_list|)
specifier|const
expr_stmt|;
name|void
name|EvaluateForOverflow
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// EvaluateAsLValue - Evaluate an expression to see if we can fold it to an
comment|/// lvalue with link time known address, with no side-effects.
name|bool
name|EvaluateAsLValue
argument_list|(
name|EvalResult
operator|&
name|Result
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// EvaluateAsInitializer - Evaluate an expression as if it were the
comment|/// initializer of the given declaration. Returns true if the initializer
comment|/// can be folded to a constant, and produces any relevant notes. In C++11,
comment|/// notes will be produced if the expression is not a constant expression.
name|bool
name|EvaluateAsInitializer
argument_list|(
name|APValue
operator|&
name|Result
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|,
name|SmallVectorImpl
operator|<
name|PartialDiagnosticAt
operator|>
operator|&
name|Notes
argument_list|)
decl|const
decl_stmt|;
comment|/// EvaluateWithSubstitution - Evaluate an expression as if from the context
comment|/// of a call to the given function with the given arguments, inside an
comment|/// unevaluated context. Returns true if the expression could be folded to a
comment|/// constant.
name|bool
name|EvaluateWithSubstitution
argument_list|(
name|APValue
operator|&
name|Value
argument_list|,
name|ASTContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|FunctionDecl
operator|*
name|Callee
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|Args
argument_list|,
specifier|const
name|Expr
operator|*
name|This
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief If the current Expr is a pointer, this will try to statically
comment|/// determine the number of bytes available where the pointer is pointing.
comment|/// Returns true if all of the above holds and we were able to figure out the
comment|/// size, false otherwise.
comment|///
comment|/// \param Type - How to evaluate the size of the Expr, as defined by the
comment|/// "type" parameter of __builtin_object_size
name|bool
name|tryEvaluateObjectSize
argument_list|(
name|uint64_t
operator|&
name|Result
argument_list|,
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|unsigned
name|Type
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Enumeration used to describe the kind of Null pointer constant
comment|/// returned from \c isNullPointerConstant().
enum|enum
name|NullPointerConstantKind
block|{
comment|/// \brief Expression is not a Null pointer constant.
name|NPCK_NotNull
init|=
literal|0
block|,
comment|/// \brief Expression is a Null pointer constant built from a zero integer
comment|/// expression that is not a simple, possibly parenthesized, zero literal.
comment|/// C++ Core Issue 903 will classify these expressions as "not pointers"
comment|/// once it is adopted.
comment|/// http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_active.html#903
name|NPCK_ZeroExpression
block|,
comment|/// \brief Expression is a Null pointer constant built from a literal zero.
name|NPCK_ZeroLiteral
block|,
comment|/// \brief Expression is a C++11 nullptr.
name|NPCK_CXX11_nullptr
block|,
comment|/// \brief Expression is a GNU-style __null constant.
name|NPCK_GNUNull
block|}
enum|;
comment|/// \brief Enumeration used to describe how \c isNullPointerConstant()
comment|/// should cope with value-dependent expressions.
enum|enum
name|NullPointerConstantValueDependence
block|{
comment|/// \brief Specifies that the expression should never be value-dependent.
name|NPC_NeverValueDependent
init|=
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
enum|;
comment|/// isNullPointerConstant - C99 6.3.2.3p3 - Test if this reduces down to
comment|/// a Null pointer constant. The return value can further distinguish the
comment|/// kind of NULL pointer constant that was detected.
name|NullPointerConstantKind
name|isNullPointerConstant
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|NullPointerConstantValueDependence
name|NPC
argument_list|)
decl|const
decl_stmt|;
comment|/// isOBJCGCCandidate - Return true if this expression may be used in a read/
comment|/// write barrier.
name|bool
name|isOBJCGCCandidate
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns true if this expression is a bound member function.
name|bool
name|isBoundMemberFunction
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Given an expression of bound-member type, find the type
comment|/// of the member.  Returns null if this is an *overloaded* bound
comment|/// member expression.
specifier|static
name|QualType
name|findBoundMemberType
parameter_list|(
specifier|const
name|Expr
modifier|*
name|expr
parameter_list|)
function_decl|;
comment|/// IgnoreImpCasts - Skip past any implicit casts which might
comment|/// surround this expression.  Only skips ImplicitCastExprs.
name|Expr
operator|*
name|IgnoreImpCasts
argument_list|()
name|LLVM_READONLY
expr_stmt|;
comment|/// IgnoreImplicit - Skip past any implicit AST nodes which might
comment|/// surround this expression.
name|Expr
modifier|*
name|IgnoreImplicit
parameter_list|()
function|LLVM_READONLY
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Stmt
operator|::
name|IgnoreImplicit
argument_list|()
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|IgnoreImplicit
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|IgnoreImplicit
argument_list|()
return|;
block|}
comment|/// IgnoreParens - Ignore parentheses.  If this Expr is a ParenExpr, return
comment|///  its subexpression.  If that subexpression is also a ParenExpr,
comment|///  then this method recursively returns its subexpression, and so forth.
comment|///  Otherwise, the method returns the current Expr.
name|Expr
operator|*
name|IgnoreParens
argument_list|()
name|LLVM_READONLY
expr_stmt|;
comment|/// IgnoreParenCasts - Ignore parentheses and casts.  Strip off any ParenExpr
comment|/// or CastExprs, returning their operand.
name|Expr
operator|*
name|IgnoreParenCasts
argument_list|()
name|LLVM_READONLY
expr_stmt|;
comment|/// Ignore casts.  Strip off any CastExprs, returning their operand.
name|Expr
operator|*
name|IgnoreCasts
argument_list|()
name|LLVM_READONLY
expr_stmt|;
comment|/// IgnoreParenImpCasts - Ignore parentheses and implicit casts.  Strip off
comment|/// any ParenExpr or ImplicitCastExprs, returning their operand.
name|Expr
operator|*
name|IgnoreParenImpCasts
argument_list|()
name|LLVM_READONLY
expr_stmt|;
comment|/// IgnoreConversionOperator - Ignore conversion operator. If this Expr is a
comment|/// call to a conversion operator, return the argument.
name|Expr
operator|*
name|IgnoreConversionOperator
argument_list|()
name|LLVM_READONLY
expr_stmt|;
specifier|const
name|Expr
operator|*
name|IgnoreConversionOperator
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|IgnoreConversionOperator
argument_list|()
return|;
block|}
specifier|const
name|Expr
operator|*
name|IgnoreParenImpCasts
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|IgnoreParenImpCasts
argument_list|()
return|;
block|}
comment|/// Ignore parentheses and lvalue casts.  Strip off any ParenExpr and
comment|/// CastExprs that represent lvalue casts, returning their operand.
name|Expr
operator|*
name|IgnoreParenLValueCasts
argument_list|()
name|LLVM_READONLY
expr_stmt|;
specifier|const
name|Expr
operator|*
name|IgnoreParenLValueCasts
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|IgnoreParenLValueCasts
argument_list|()
return|;
block|}
comment|/// IgnoreParenNoopCasts - Ignore parentheses and casts that do not change the
comment|/// value (including ptr->int casts of the same size).  Strip off any
comment|/// ParenExpr or CastExprs, returning their operand.
name|Expr
modifier|*
name|IgnoreParenNoopCasts
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
name|LLVM_READONLY
decl_stmt|;
comment|/// Ignore parentheses and derived-to-base casts.
name|Expr
operator|*
name|ignoreParenBaseCasts
argument_list|()
name|LLVM_READONLY
expr_stmt|;
specifier|const
name|Expr
operator|*
name|ignoreParenBaseCasts
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|ignoreParenBaseCasts
argument_list|()
return|;
block|}
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
expr_stmt|;
comment|/// \brief Determine whether the result of this expression is a
comment|/// temporary object of the given class type.
name|bool
name|isTemporaryObject
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|TempTy
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Whether this expression is an implicit reference to 'this' in C++.
name|bool
name|isImplicitCXXThis
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|Expr
operator|*
name|IgnoreImpCasts
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|IgnoreImpCasts
argument_list|()
return|;
block|}
specifier|const
name|Expr
operator|*
name|IgnoreParens
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|LLVM_READONLY
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
comment|/// Strip off casts, but keep parentheses.
specifier|const
name|Expr
operator|*
name|IgnoreCasts
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|IgnoreCasts
argument_list|()
return|;
block|}
specifier|const
name|Expr
modifier|*
name|IgnoreParenNoopCasts
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
name|LLVM_READONLY
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
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Exprs
argument_list|)
decl_stmt|;
comment|/// \brief For an expression of class type or pointer to class type,
comment|/// return the most derived class decl the expression is known to refer to.
comment|///
comment|/// If this expression is a cast, this method looks through it to find the
comment|/// most derived decl that can be inferred from the expression.
comment|/// This is valid because derived-to-base conversions have undefined
comment|/// behavior if the object isn't dynamically of the derived type.
specifier|const
name|CXXRecordDecl
operator|*
name|getBestDynamicClassType
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Get the inner expression that determines the best dynamic class.
comment|/// If this is a prvalue, we guarantee that it is of the most-derived type
comment|/// for the object itself.
specifier|const
name|Expr
operator|*
name|getBestDynamicClassTypeExpr
argument_list|()
specifier|const
expr_stmt|;
comment|/// Walk outwards from an expression we want to bind a reference to and
comment|/// find the expression whose lifetime needs to be extended. Record
comment|/// the LHSs of comma expressions and adjustments needed along the path.
specifier|const
name|Expr
modifier|*
name|skipRValueSubobjectAdjustments
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|&
name|CommaLHS
argument_list|,
name|SmallVectorImpl
operator|<
name|SubobjectAdjustment
operator|>
operator|&
name|Adjustments
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|Expr
operator|*
name|skipRValueSubobjectAdjustments
argument_list|()
specifier|const
block|{
name|SmallVector
operator|<
specifier|const
name|Expr
operator|*
block|,
literal|8
operator|>
name|CommaLHSs
block|;
name|SmallVector
operator|<
name|SubobjectAdjustment
block|,
literal|8
operator|>
name|Adjustments
block|;
return|return
name|skipRValueSubobjectAdjustments
argument_list|(
name|CommaLHSs
argument_list|,
name|Adjustments
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Primary Expressions.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// OpaqueValueExpr - An expression referring to an opaque object of a
end_comment

begin_comment
comment|/// fixed type and value class.  These don't correspond to concrete
end_comment

begin_comment
comment|/// syntax; instead they're used to express operations (usually copy
end_comment

begin_comment
comment|/// operations) on values whose source is generally obvious from
end_comment

begin_comment
comment|/// context.
end_comment

begin_decl_stmt
name|class
name|OpaqueValueExpr
range|:
name|public
name|Expr
block|{
name|friend
name|class
name|ASTStmtReader
block|;
name|Expr
operator|*
name|SourceExpr
block|;
name|SourceLocation
name|Loc
block|;
name|public
operator|:
name|OpaqueValueExpr
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK = OK_Ordinary
argument_list|,
argument|Expr *SourceExpr = nullptr
argument_list|)
operator|:
name|Expr
argument_list|(
name|OpaqueValueExprClass
argument_list|,
name|T
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
name|T
operator|->
name|isDependentType
argument_list|()
operator|||
operator|(
name|SourceExpr
operator|&&
name|SourceExpr
operator|->
name|isTypeDependent
argument_list|()
operator|)
argument_list|,
name|T
operator|->
name|isDependentType
argument_list|()
operator|||
operator|(
name|SourceExpr
operator|&&
name|SourceExpr
operator|->
name|isValueDependent
argument_list|()
operator|)
argument_list|,
name|T
operator|->
name|isInstantiationDependentType
argument_list|()
operator|||
operator|(
name|SourceExpr
operator|&&
name|SourceExpr
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
argument_list|,
name|false
argument_list|)
block|,
name|SourceExpr
argument_list|(
name|SourceExpr
argument_list|)
block|,
name|Loc
argument_list|(
argument|Loc
argument_list|)
block|{   }
comment|/// Given an expression which invokes a copy constructor --- i.e.  a
comment|/// CXXConstructExpr, possibly wrapped in an ExprWithCleanups ---
comment|/// find the OpaqueValueExpr that's the source of the construction.
specifier|static
specifier|const
name|OpaqueValueExpr
operator|*
name|findInCopyConstruct
argument_list|(
specifier|const
name|Expr
operator|*
name|expr
argument_list|)
block|;
name|explicit
name|OpaqueValueExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|OpaqueValueExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// \brief Retrieve the location of this expression.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceExpr
operator|?
name|SourceExpr
operator|->
name|getLocStart
argument_list|()
operator|:
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
name|SourceExpr
condition|?
name|SourceExpr
operator|->
name|getLocEnd
argument_list|()
else|:
name|Loc
return|;
block|}
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|SourceExpr
condition|)
return|return
name|SourceExpr
operator|->
name|getExprLoc
argument_list|()
return|;
return|return
name|Loc
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
argument_list|(
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// The source expression of an opaque value expression is the
end_comment

begin_comment
comment|/// expression which originally generated the value.  This is
end_comment

begin_comment
comment|/// provided as a convenience for analyses that don't wish to
end_comment

begin_comment
comment|/// precisely model the execution behavior of the program.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The source expression is typically set when building the
end_comment

begin_comment
comment|/// expression which binds the opaque value expression in the first
end_comment

begin_comment
comment|/// place.
end_comment

begin_expr_stmt
name|Expr
operator|*
name|getSourceExpr
argument_list|()
specifier|const
block|{
return|return
name|SourceExpr
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
name|OpaqueValueExprClass
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief A reference to a declared variable, function, enum, etc.
end_comment

begin_comment
comment|/// [C99 6.5.1p2]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This encodes all the information about how a declaration is referenced
end_comment

begin_comment
comment|/// within an expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There are several optional constructs attached to DeclRefExprs only when
end_comment

begin_comment
comment|/// they apply in order to conserve memory. These are laid out past the end of
end_comment

begin_comment
comment|/// the object, and flags in the DeclRefExprBitfield track whether they exist:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   DeclRefExprBits.HasQualifier:
end_comment

begin_comment
comment|///       Specifies when this declaration reference expression has a C++
end_comment

begin_comment
comment|///       nested-name-specifier.
end_comment

begin_comment
comment|///   DeclRefExprBits.HasFoundDecl:
end_comment

begin_comment
comment|///       Specifies when this declaration reference expression has a record of
end_comment

begin_comment
comment|///       a NamedDecl (different from the referenced ValueDecl) which was found
end_comment

begin_comment
comment|///       during name lookup and/or overload resolution.
end_comment

begin_comment
comment|///   DeclRefExprBits.HasTemplateKWAndArgsInfo:
end_comment

begin_comment
comment|///       Specifies when this declaration reference expression has an explicit
end_comment

begin_comment
comment|///       C++ template keyword and/or template argument list.
end_comment

begin_comment
comment|///   DeclRefExprBits.RefersToEnclosingVariableOrCapture
end_comment

begin_comment
comment|///       Specifies when this declaration reference expression (validly)
end_comment

begin_comment
comment|///       refers to an enclosed local or a captured variable.
end_comment

begin_decl_stmt
name|class
name|DeclRefExpr
name|final
range|:
name|public
name|Expr
decl_stmt|,
name|private
name|llvm
decl|::
name|TrailingObjects
decl|<
name|DeclRefExpr
decl_stmt|,
name|NestedNameSpecifierLoc
decl_stmt|,
name|NamedDecl
modifier|*
decl_stmt|,
name|ASTTemplateKWAndArgsInfo
decl_stmt|,
name|TemplateArgumentLoc
decl|>
block|{
comment|/// \brief The declaration that we are referencing.
name|ValueDecl
modifier|*
name|D
decl_stmt|;
comment|/// \brief The location of the declaration name itself.
name|SourceLocation
name|Loc
decl_stmt|;
comment|/// \brief Provides source/type location info for the declaration name
comment|/// embedded in D.
name|DeclarationNameLoc
name|DNLoc
decl_stmt|;
name|size_t
name|numTrailingObjects
argument_list|(
name|OverloadToken
operator|<
name|NestedNameSpecifierLoc
operator|>
argument_list|)
decl|const
block|{
return|return
name|hasQualifier
argument_list|()
condition|?
literal|1
else|:
literal|0
return|;
block|}
name|size_t
name|numTrailingObjects
argument_list|(
name|OverloadToken
operator|<
name|NamedDecl
operator|*
operator|>
argument_list|)
decl|const
block|{
return|return
name|hasFoundDecl
argument_list|()
condition|?
literal|1
else|:
literal|0
return|;
block|}
name|size_t
name|numTrailingObjects
argument_list|(
name|OverloadToken
operator|<
name|ASTTemplateKWAndArgsInfo
operator|>
argument_list|)
decl|const
block|{
return|return
name|hasTemplateKWAndArgsInfo
argument_list|()
condition|?
literal|1
else|:
literal|0
return|;
block|}
comment|/// \brief Test whether there is a distinct FoundDecl attached to the end of
comment|/// this DRE.
name|bool
name|hasFoundDecl
argument_list|()
specifier|const
block|{
return|return
name|DeclRefExprBits
operator|.
name|HasFoundDecl
return|;
block|}
name|DeclRefExpr
argument_list|(
argument|const ASTContext&Ctx
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation TemplateKWLoc
argument_list|,
argument|ValueDecl *D
argument_list|,
argument|bool RefersToEnlosingVariableOrCapture
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|NamedDecl *FoundD
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|)
empty_stmt|;
comment|/// \brief Construct an empty declaration reference expression.
name|explicit
name|DeclRefExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
block|:
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
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|)
function_decl|;
name|public
label|:
name|DeclRefExpr
argument_list|(
argument|ValueDecl *D
argument_list|,
argument|bool RefersToEnclosingVariableOrCapture
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation L
argument_list|,
argument|const DeclarationNameLoc&LocInfo = DeclarationNameLoc()
argument_list|)
block|:
name|Expr
argument_list|(
name|DeclRefExprClass
argument_list|,
name|T
argument_list|,
name|VK
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
operator|,
name|D
argument_list|(
name|D
argument_list|)
operator|,
name|Loc
argument_list|(
name|L
argument_list|)
operator|,
name|DNLoc
argument_list|(
argument|LocInfo
argument_list|)
block|{
name|DeclRefExprBits
operator|.
name|HasQualifier
operator|=
literal|0
block|;
name|DeclRefExprBits
operator|.
name|HasTemplateKWAndArgsInfo
operator|=
literal|0
block|;
name|DeclRefExprBits
operator|.
name|HasFoundDecl
operator|=
literal|0
block|;
name|DeclRefExprBits
operator|.
name|HadMultipleCandidates
operator|=
literal|0
block|;
name|DeclRefExprBits
operator|.
name|RefersToEnclosingVariableOrCapture
operator|=
name|RefersToEnclosingVariableOrCapture
block|;
name|computeDependence
argument_list|(
name|D
operator|->
name|getASTContext
argument_list|()
argument_list|)
block|;   }
specifier|static
name|DeclRefExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation TemplateKWLoc
argument_list|,
argument|ValueDecl *D
argument_list|,
argument|bool RefersToEnclosingVariableOrCapture
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|NamedDecl *FoundD = nullptr
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgs = nullptr
argument_list|)
expr_stmt|;
specifier|static
name|DeclRefExpr
modifier|*
name|Create
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|NestedNameSpecifierLoc
name|QualifierLoc
parameter_list|,
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
name|ValueDecl
modifier|*
name|D
parameter_list|,
name|bool
name|RefersToEnclosingVariableOrCapture
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
name|QualType
name|T
parameter_list|,
name|ExprValueKind
name|VK
parameter_list|,
name|NamedDecl
modifier|*
name|FoundD
init|=
name|nullptr
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Construct an empty declaration reference expression.
specifier|static
name|DeclRefExpr
modifier|*
name|CreateEmpty
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|bool
name|HasQualifier
parameter_list|,
name|bool
name|HasFoundDecl
parameter_list|,
name|bool
name|HasTemplateKWAndArgsInfo
parameter_list|,
name|unsigned
name|NumTemplateArgs
parameter_list|)
function_decl|;
name|ValueDecl
modifier|*
name|getDecl
parameter_list|()
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
parameter_list|(
name|ValueDecl
modifier|*
name|NewD
parameter_list|)
block|{
name|D
operator|=
name|NewD
expr_stmt|;
block|}
name|DeclarationNameInfo
name|getNameInfo
argument_list|()
specifier|const
block|{
return|return
name|DeclarationNameInfo
argument_list|(
name|getDecl
argument_list|()
operator|->
name|getDeclName
argument_list|()
argument_list|,
name|Loc
argument_list|,
name|DNLoc
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
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|Loc
operator|=
name|L
expr_stmt|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
comment|/// \brief Determine whether this declaration reference was preceded by a
comment|/// C++ nested-name-specifier, e.g., \c N::foo.
name|bool
name|hasQualifier
argument_list|()
specifier|const
block|{
return|return
name|DeclRefExprBits
operator|.
name|HasQualifier
return|;
block|}
comment|/// \brief If the name was qualified, retrieves the nested-name-specifier
comment|/// that precedes the name, with source-location information.
name|NestedNameSpecifierLoc
name|getQualifierLoc
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
name|NestedNameSpecifierLoc
argument_list|()
return|;
return|return
operator|*
name|getTrailingObjects
operator|<
name|NestedNameSpecifierLoc
operator|>
operator|(
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief If the name was qualified, retrieves the nested-name-specifier
end_comment

begin_comment
comment|/// that precedes the name. Otherwise, returns NULL.
end_comment

begin_expr_stmt
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|getQualifierLoc
argument_list|()
operator|.
name|getNestedNameSpecifier
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get the NamedDecl through which this reference occurred.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This Decl may be different from the ValueDecl actually referred to in the
end_comment

begin_comment
comment|/// presence of using declarations, etc. It always returns non-NULL, and may
end_comment

begin_comment
comment|/// simple return the ValueDecl when appropriate.
end_comment

begin_function
name|NamedDecl
modifier|*
name|getFoundDecl
parameter_list|()
block|{
return|return
name|hasFoundDecl
argument_list|()
condition|?
operator|*
name|getTrailingObjects
operator|<
name|NamedDecl
operator|*
operator|>
operator|(
operator|)
else|:
name|D
return|;
block|}
end_function

begin_comment
comment|/// \brief Get the NamedDecl through which this reference occurred.
end_comment

begin_comment
comment|/// See non-const variant.
end_comment

begin_expr_stmt
specifier|const
name|NamedDecl
operator|*
name|getFoundDecl
argument_list|()
specifier|const
block|{
return|return
name|hasFoundDecl
argument_list|()
operator|?
operator|*
name|getTrailingObjects
operator|<
name|NamedDecl
operator|*
operator|>
operator|(
operator|)
operator|:
name|D
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasTemplateKWAndArgsInfo
argument_list|()
specifier|const
block|{
return|return
name|DeclRefExprBits
operator|.
name|HasTemplateKWAndArgsInfo
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
name|hasTemplateKWAndArgsInfo
argument_list|()
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getTrailingObjects
operator|<
name|ASTTemplateKWAndArgsInfo
operator|>
operator|(
operator|)
operator|->
name|TemplateKWLoc
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
name|hasTemplateKWAndArgsInfo
argument_list|()
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getTrailingObjects
operator|<
name|ASTTemplateKWAndArgsInfo
operator|>
operator|(
operator|)
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
name|hasTemplateKWAndArgsInfo
argument_list|()
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getTrailingObjects
operator|<
name|ASTTemplateKWAndArgsInfo
operator|>
operator|(
operator|)
operator|->
name|RAngleLoc
return|;
end_return

begin_comment
unit|}
comment|/// \brief Determines whether the name in this declaration reference
end_comment

begin_comment
comment|/// was preceded by the template keyword.
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
comment|/// \brief Determines whether this declaration reference was followed by an
end_comment

begin_comment
comment|/// explicit template argument list.
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
name|hasExplicitTemplateArgs
argument_list|()
condition|)
name|getTrailingObjects
operator|<
name|ASTTemplateKWAndArgsInfo
operator|>
operator|(
operator|)
operator|->
name|copyInto
argument_list|(
name|getTrailingObjects
operator|<
name|TemplateArgumentLoc
operator|>
operator|(
operator|)
argument_list|,
name|List
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the template arguments provided as part of this
end_comment

begin_comment
comment|/// template-id.
end_comment

begin_expr_stmt
specifier|const
name|TemplateArgumentLoc
operator|*
name|getTemplateArgs
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
name|nullptr
return|;
end_expr_stmt

begin_return
return|return
name|getTrailingObjects
operator|<
name|TemplateArgumentLoc
operator|>
operator|(
operator|)
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
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|getTrailingObjects
operator|<
name|ASTTemplateKWAndArgsInfo
operator|>
operator|(
operator|)
operator|->
name|NumTemplateArgs
return|;
end_return

begin_expr_stmt
unit|}    ArrayRef
operator|<
name|TemplateArgumentLoc
operator|>
name|template_arguments
argument_list|()
specifier|const
block|{
return|return
block|{
name|getTemplateArgs
argument_list|()
block|,
name|getNumTemplateArgs
argument_list|()
block|}
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if this expression refers to a function that
end_comment

begin_comment
comment|/// was resolved from an overloaded set having size greater than 1.
end_comment

begin_expr_stmt
name|bool
name|hadMultipleCandidates
argument_list|()
specifier|const
block|{
return|return
name|DeclRefExprBits
operator|.
name|HadMultipleCandidates
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Sets the flag telling whether this expression refers to
end_comment

begin_comment
comment|/// a function that was resolved from an overloaded set having size
end_comment

begin_comment
comment|/// greater than 1.
end_comment

begin_function
name|void
name|setHadMultipleCandidates
parameter_list|(
name|bool
name|V
init|=
name|true
parameter_list|)
block|{
name|DeclRefExprBits
operator|.
name|HadMultipleCandidates
operator|=
name|V
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Does this DeclRefExpr refer to an enclosing local or a captured
end_comment

begin_comment
comment|/// variable?
end_comment

begin_expr_stmt
name|bool
name|refersToEnclosingVariableOrCapture
argument_list|()
specifier|const
block|{
return|return
name|DeclRefExprBits
operator|.
name|RefersToEnclosingVariableOrCapture
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
name|DeclRefExprClass
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
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|friend
name|TrailingObjects
decl_stmt|;
end_decl_stmt

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
comment|/// \brief [C99 6.4.2.2] - A predefined identifier such as __func__.
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
name|LFunction
block|,
comment|// Same as Function, but as wide string.
name|FuncDName
block|,
name|FuncSig
block|,
name|PrettyFunction
block|,
comment|/// \brief The same as PrettyFunction, except that the
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
name|Stmt
operator|*
name|FnName
block|;
name|public
operator|:
name|PredefinedExpr
argument_list|(
argument|SourceLocation L
argument_list|,
argument|QualType FNTy
argument_list|,
argument|IdentType IT
argument_list|,
argument|StringLiteral *SL
argument_list|)
block|;
comment|/// \brief Construct an empty predefined expression.
name|explicit
name|PredefinedExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|PredefinedExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|Loc
argument_list|()
block|,
name|Type
argument_list|(
name|Func
argument_list|)
block|,
name|FnName
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|IdentType
name|getIdentType
argument_list|()
specifier|const
block|{
return|return
name|Type
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
name|StringLiteral
operator|*
name|getFunctionName
argument_list|()
block|;
specifier|const
name|StringLiteral
operator|*
name|getFunctionName
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|PredefinedExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getFunctionName
argument_list|()
return|;
block|}
specifier|static
name|StringRef
name|getIdentTypeName
argument_list|(
argument|IdentType IT
argument_list|)
block|;
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
name|PredefinedExprClass
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
name|FnName
argument_list|,
operator|&
name|FnName
operator|+
literal|1
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
operator|&
name|FnName
argument_list|,
operator|&
name|FnName
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
end_decl_stmt

begin_comment
comment|/// \brief Used by IntegerLiteral/FloatingLiteral to store the numeric without
end_comment

begin_comment
comment|/// leaking memory.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For large floats/integers, APFloat/APInt will allocate memory from the heap
end_comment

begin_comment
comment|/// to represent these numbers.  Unfortunately, when we use a BumpPtrAllocator
end_comment

begin_comment
comment|/// to allocate IntegerLiteral/FloatingLiteral nodes the memory associated with
end_comment

begin_comment
comment|/// the APFloat/APInt values will never get freed. APNumericStorage uses
end_comment

begin_comment
comment|/// ASTContext's allocator for memory allocation.
end_comment

begin_decl_stmt
name|class
name|APNumericStorage
block|{
union|union
block|{
name|uint64_t
name|VAL
decl_stmt|;
comment|///< Used to store the<= 64 bits integer value.
name|uint64_t
modifier|*
name|pVal
decl_stmt|;
comment|///< Used to store the>64 bits integer value.
block|}
union|;
name|unsigned
name|BitWidth
decl_stmt|;
name|bool
name|hasAllocation
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|APInt
operator|::
name|getNumWords
argument_list|(
name|BitWidth
argument_list|)
operator|>
literal|1
return|;
block|}
name|APNumericStorage
argument_list|(
specifier|const
name|APNumericStorage
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|APNumericStorage
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|protected
label|:
name|APNumericStorage
argument_list|()
operator|:
name|VAL
argument_list|(
literal|0
argument_list|)
operator|,
name|BitWidth
argument_list|(
literal|0
argument_list|)
block|{ }
name|llvm
operator|::
name|APInt
name|getIntValue
argument_list|()
specifier|const
block|{
name|unsigned
name|NumWords
operator|=
name|llvm
operator|::
name|APInt
operator|::
name|getNumWords
argument_list|(
name|BitWidth
argument_list|)
block|;
if|if
condition|(
name|NumWords
operator|>
literal|1
condition|)
return|return
name|llvm
operator|::
name|APInt
argument_list|(
name|BitWidth
argument_list|,
name|NumWords
argument_list|,
name|pVal
argument_list|)
return|;
else|else
return|return
name|llvm
operator|::
name|APInt
argument_list|(
name|BitWidth
argument_list|,
name|VAL
argument_list|)
return|;
block|}
name|void
name|setIntValue
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
specifier|const
name|llvm
operator|::
name|APInt
operator|&
name|Val
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|APIntStorage
range|:
name|private
name|APNumericStorage
block|{
name|public
operator|:
name|llvm
operator|::
name|APInt
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|getIntValue
argument_list|()
return|;
block|}
name|void
name|setValue
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|const llvm::APInt&Val
argument_list|)
block|{
name|setIntValue
argument_list|(
name|C
argument_list|,
name|Val
argument_list|)
block|;   }
expr|}
block|;
name|class
name|APFloatStorage
operator|:
name|private
name|APNumericStorage
block|{
name|public
operator|:
name|llvm
operator|::
name|APFloat
name|getValue
argument_list|(
argument|const llvm::fltSemantics&Semantics
argument_list|)
specifier|const
block|{
return|return
name|llvm
operator|::
name|APFloat
argument_list|(
name|Semantics
argument_list|,
name|getIntValue
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setValue
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|const llvm::APFloat&Val
argument_list|)
block|{
name|setIntValue
argument_list|(
name|C
argument_list|,
name|Val
operator|.
name|bitcastToAPInt
argument_list|()
argument_list|)
block|;   }
expr|}
block|;
name|class
name|IntegerLiteral
operator|:
name|public
name|Expr
block|,
name|public
name|APIntStorage
block|{
name|SourceLocation
name|Loc
block|;
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
name|public
operator|:
comment|// type should be IntTy, LongTy, LongLongTy, UnsignedIntTy, UnsignedLongTy,
comment|// or UnsignedLongLongTy
name|IntegerLiteral
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|const llvm::APInt&V
argument_list|,
argument|QualType type
argument_list|,
argument|SourceLocation l
argument_list|)
block|;
comment|/// \brief Returns a new integer literal with value 'V' and type 'type'.
comment|/// \param type - either IntTy, LongTy, LongLongTy, UnsignedIntTy,
comment|/// UnsignedLongTy, or UnsignedLongLongTy which should match the size of V
comment|/// \param V - the value that the returned integer literal contains.
specifier|static
name|IntegerLiteral
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|const llvm::APInt&V
argument_list|,
argument|QualType type
argument_list|,
argument|SourceLocation l
argument_list|)
block|;
comment|/// \brief Returns a new empty integer literal.
specifier|static
name|IntegerLiteral
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|EmptyShell Empty
argument_list|)
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
name|Loc
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
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
name|class
name|CharacterLiteral
operator|:
name|public
name|Expr
block|{
name|public
operator|:
expr|enum
name|CharacterKind
block|{
name|Ascii
block|,
name|Wide
block|,
name|UTF8
block|,
name|UTF16
block|,
name|UTF32
block|}
block|;
name|private
operator|:
name|unsigned
name|Value
block|;
name|SourceLocation
name|Loc
block|;
name|public
operator|:
comment|// type should be IntTy
name|CharacterLiteral
argument_list|(
argument|unsigned value
argument_list|,
argument|CharacterKind kind
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
name|value
argument_list|)
block|,
name|Loc
argument_list|(
argument|l
argument_list|)
block|{
name|CharacterLiteralBits
operator|.
name|Kind
operator|=
name|kind
block|;   }
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
name|CharacterKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|CharacterKind
operator|>
operator|(
name|CharacterLiteralBits
operator|.
name|Kind
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
name|setKind
argument_list|(
argument|CharacterKind kind
argument_list|)
block|{
name|CharacterLiteralBits
operator|.
name|Kind
operator|=
name|kind
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
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
name|class
name|FloatingLiteral
operator|:
name|public
name|Expr
block|,
name|private
name|APFloatStorage
block|{
name|SourceLocation
name|Loc
block|;
name|FloatingLiteral
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|const llvm::APFloat&V
argument_list|,
argument|bool isexact
argument_list|,
argument|QualType Type
argument_list|,
argument|SourceLocation L
argument_list|)
block|;
comment|/// \brief Construct an empty floating-point literal.
name|explicit
name|FloatingLiteral
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|EmptyShell Empty
argument_list|)
block|;
name|public
operator|:
specifier|static
name|FloatingLiteral
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|const llvm::APFloat&V
argument_list|,
argument|bool isexact
argument_list|,
argument|QualType Type
argument_list|,
argument|SourceLocation L
argument_list|)
block|;
specifier|static
name|FloatingLiteral
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|EmptyShell Empty
argument_list|)
block|;
name|llvm
operator|::
name|APFloat
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|APFloatStorage
operator|::
name|getValue
argument_list|(
name|getSemantics
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setValue
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|const llvm::APFloat&Val
argument_list|)
block|{
name|assert
argument_list|(
operator|&
name|getSemantics
argument_list|()
operator|==
operator|&
name|Val
operator|.
name|getSemantics
argument_list|()
operator|&&
literal|"Inconsistent semantics"
argument_list|)
block|;
name|APFloatStorage
operator|::
name|setValue
argument_list|(
name|C
argument_list|,
name|Val
argument_list|)
block|;   }
comment|/// Get a raw enumeration value representing the floating-point semantics of
comment|/// this literal (32-bit IEEE, x87, ...), suitable for serialisation.
name|APFloatSemantics
name|getRawSemantics
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|APFloatSemantics
operator|>
operator|(
name|FloatingLiteralBits
operator|.
name|Semantics
operator|)
return|;
block|}
comment|/// Set the raw enumeration value representing the floating-point semantics of
comment|/// this literal (32-bit IEEE, x87, ...), suitable for serialisation.
name|void
name|setRawSemantics
argument_list|(
argument|APFloatSemantics Sem
argument_list|)
block|{
name|FloatingLiteralBits
operator|.
name|Semantics
operator|=
name|Sem
block|;   }
comment|/// Return the APFloat semantics this literal uses.
specifier|const
name|llvm
operator|::
name|fltSemantics
operator|&
name|getSemantics
argument_list|()
specifier|const
block|;
comment|/// Set the APFloat semantics this literal uses.
name|void
name|setSemantics
argument_list|(
specifier|const
name|llvm
operator|::
name|fltSemantics
operator|&
name|Sem
argument_list|)
block|;
name|bool
name|isExact
argument_list|()
specifier|const
block|{
return|return
name|FloatingLiteralBits
operator|.
name|IsExact
return|;
block|}
name|void
name|setExact
argument_list|(
argument|bool E
argument_list|)
block|{
name|FloatingLiteralBits
operator|.
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
name|FloatingLiteralClass
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
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// ImaginaryLiteral - We support imaginary integer and floating point literals,
comment|/// like "1.0i".  We represent these as a wrapper around FloatingLiteral and
comment|/// IntegerLiteral classes.  Instances of this class always have a Complex type
comment|/// whose element type matches the subexpression.
comment|///
name|class
name|ImaginaryLiteral
operator|:
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Val
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
name|Val
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
name|ImaginaryLiteralClass
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
name|Val
argument_list|,
operator|&
name|Val
operator|+
literal|1
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
operator|&
name|Val
argument_list|,
operator|&
name|Val
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// StringLiteral - This represents a string literal expression, e.g. "foo"
comment|/// or L"bar" (wide strings).  The actual string is returned by getBytes()
comment|/// is NOT null-terminated, and the length of the string is determined by
comment|/// calling getByteLength().  The C type for a string is always a
comment|/// ConstantArrayType.  In C++, the char type is const qualified, in C it is
comment|/// not.
comment|///
comment|/// Note that strings in C can be formed by concatenation of multiple string
comment|/// literal pptokens in translation phase #6.  This keeps track of the locations
comment|/// of each of these pieces.
comment|///
comment|/// Strings in C can also be truncated and extended by assigning into arrays,
comment|/// e.g. with constructs like:
comment|///   char X[2] = "foobar";
comment|/// In this case, getByteLength() will return 6, but the string literal will
comment|/// have type "char[2]".
name|class
name|StringLiteral
operator|:
name|public
name|Expr
block|{
name|public
operator|:
expr|enum
name|StringKind
block|{
name|Ascii
block|,
name|Wide
block|,
name|UTF8
block|,
name|UTF16
block|,
name|UTF32
block|}
block|;
name|private
operator|:
name|friend
name|class
name|ASTStmtReader
block|;
expr|union
block|{
specifier|const
name|char
operator|*
name|asChar
block|;
specifier|const
name|uint16_t
operator|*
name|asUInt16
block|;
specifier|const
name|uint32_t
operator|*
name|asUInt32
block|;   }
name|StrData
block|;
name|unsigned
name|Length
block|;
name|unsigned
name|CharByteWidth
operator|:
literal|4
block|;
name|unsigned
name|Kind
operator|:
literal|3
block|;
name|unsigned
name|IsPascal
operator|:
literal|1
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
argument|VK_LValue
argument_list|,
argument|OK_Ordinary
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|)
block|{}
specifier|static
name|int
name|mapCharByteWidth
argument_list|(
argument|TargetInfo const&target
argument_list|,
argument|StringKind k
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
argument|const ASTContext&C
argument_list|,
argument|StringRef Str
argument_list|,
argument|StringKind Kind
argument_list|,
argument|bool Pascal
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
argument|const ASTContext&C
argument_list|,
argument|StringRef Str
argument_list|,
argument|StringKind Kind
argument_list|,
argument|bool Pascal
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
name|Str
argument_list|,
name|Kind
argument_list|,
name|Pascal
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
argument|const ASTContext&C
argument_list|,
argument|unsigned NumStrs
argument_list|)
block|;
name|StringRef
name|getString
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CharByteWidth
operator|==
literal|1
operator|&&
literal|"This function is used in places that assume strings use char"
argument_list|)
block|;
return|return
name|StringRef
argument_list|(
name|StrData
operator|.
name|asChar
argument_list|,
name|getByteLength
argument_list|()
argument_list|)
return|;
block|}
comment|/// Allow access to clients that need the byte representation, such as
comment|/// ASTWriterStmt::VisitStringLiteral().
name|StringRef
name|getBytes
argument_list|()
specifier|const
block|{
comment|// FIXME: StringRef may not be the right type to use as a result for this.
if|if
condition|(
name|CharByteWidth
operator|==
literal|1
condition|)
return|return
name|StringRef
argument_list|(
name|StrData
operator|.
name|asChar
argument_list|,
name|getByteLength
argument_list|()
argument_list|)
return|;
if|if
condition|(
name|CharByteWidth
operator|==
literal|4
condition|)
return|return
name|StringRef
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|StrData
operator|.
name|asUInt32
operator|)
argument_list|,
name|getByteLength
argument_list|()
argument_list|)
return|;
name|assert
argument_list|(
name|CharByteWidth
operator|==
literal|2
operator|&&
literal|"unsupported CharByteWidth"
argument_list|)
block|;
return|return
name|StringRef
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|StrData
operator|.
name|asUInt16
operator|)
argument_list|,
name|getByteLength
argument_list|()
argument_list|)
return|;
block|}
name|void
name|outputString
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|uint32_t
name|getCodeUnit
argument_list|(
argument|size_t i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|Length
operator|&&
literal|"out of bounds access"
argument_list|)
block|;
if|if
condition|(
name|CharByteWidth
operator|==
literal|1
condition|)
return|return
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|StrData
operator|.
name|asChar
index|[
name|i
index|]
operator|)
return|;
if|if
condition|(
name|CharByteWidth
operator|==
literal|4
condition|)
return|return
name|StrData
operator|.
name|asUInt32
index|[
name|i
index|]
return|;
name|assert
argument_list|(
name|CharByteWidth
operator|==
literal|2
operator|&&
literal|"unsupported CharByteWidth"
argument_list|)
block|;
return|return
name|StrData
operator|.
name|asUInt16
index|[
name|i
index|]
return|;
block|}
name|unsigned
name|getByteLength
argument_list|()
specifier|const
block|{
return|return
name|CharByteWidth
operator|*
name|Length
return|;
block|}
name|unsigned
name|getLength
argument_list|()
specifier|const
block|{
return|return
name|Length
return|;
block|}
name|unsigned
name|getCharByteWidth
argument_list|()
specifier|const
block|{
return|return
name|CharByteWidth
return|;
block|}
comment|/// \brief Sets the string data to the given string data.
name|void
name|setString
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|StringRef Str
argument_list|,
argument|StringKind Kind
argument_list|,
argument|bool IsPascal
argument_list|)
block|;
name|StringKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|StringKind
operator|>
operator|(
name|Kind
operator|)
return|;
block|}
name|bool
name|isAscii
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Ascii
return|;
block|}
name|bool
name|isWide
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Wide
return|;
block|}
name|bool
name|isUTF8
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|UTF8
return|;
block|}
name|bool
name|isUTF16
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|UTF16
return|;
block|}
name|bool
name|isUTF32
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|UTF32
return|;
block|}
name|bool
name|isPascal
argument_list|()
specifier|const
block|{
return|return
name|IsPascal
return|;
block|}
name|bool
name|containsNonAsciiOrNull
argument_list|()
specifier|const
block|{
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
name|isASCII
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
comment|/// getNumConcatenated - Get the number of string literal tokens that were
comment|/// concatenated in translation phase #6 to form this string literal.
name|unsigned
name|getNumConcatenated
argument_list|()
specifier|const
block|{
return|return
name|NumConcatenated
return|;
block|}
name|SourceLocation
name|getStrTokenLoc
argument_list|(
argument|unsigned TokNum
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|TokNum
operator|<
name|NumConcatenated
operator|&&
literal|"Invalid tok number"
argument_list|)
block|;
return|return
name|TokLocs
index|[
name|TokNum
index|]
return|;
block|}
name|void
name|setStrTokenLoc
argument_list|(
argument|unsigned TokNum
argument_list|,
argument|SourceLocation L
argument_list|)
block|{
name|assert
argument_list|(
name|TokNum
operator|<
name|NumConcatenated
operator|&&
literal|"Invalid tok number"
argument_list|)
block|;
name|TokLocs
index|[
name|TokNum
index|]
operator|=
name|L
block|;   }
comment|/// getLocationOfByte - Return a source location that points to the specified
comment|/// byte of this string literal.
comment|///
comment|/// Strings are amazingly complex.  They can be formed from multiple tokens
comment|/// and can have escape sequences in them in addition to the usual trigraph
comment|/// and escaped newline business.  This routine handles this complexity.
comment|///
name|SourceLocation
name|getLocationOfByte
argument_list|(
argument|unsigned ByteNo
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&Features
argument_list|,
argument|const TargetInfo&Target
argument_list|,
argument|unsigned *StartToken = nullptr
argument_list|,
argument|unsigned *StartTokenByteOffset = nullptr
argument_list|)
specifier|const
block|;
typedef|typedef
specifier|const
name|SourceLocation
modifier|*
name|tokloc_iterator
typedef|;
name|tokloc_iterator
name|tokloc_begin
argument_list|()
specifier|const
block|{
return|return
name|TokLocs
return|;
block|}
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|TokLocs
index|[
literal|0
index|]
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|TokLocs
index|[
name|NumConcatenated
operator|-
literal|1
index|]
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
name|StringLiteralClass
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
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// ParenExpr - This represents a parethesized expression, e.g. "(1)".  This
comment|/// AST node is only formed if full location information is requested.
name|class
name|ParenExpr
operator|:
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
name|getValueKind
argument_list|()
argument_list|,
name|val
operator|->
name|getObjectKind
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
argument_list|,
name|val
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|val
operator|->
name|containsUnexpandedParameterPack
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|L
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|R
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
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|&
name|Val
argument_list|,
operator|&
name|Val
operator|+
literal|1
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
operator|&
name|Val
argument_list|,
operator|&
name|Val
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// UnaryOperator - This represents the unary-expression's (except sizeof and
comment|/// alignof), the postinc/postdec operators from postfix-expression, and various
comment|/// extensions.
comment|///
comment|/// Notes on various nodes:
comment|///
comment|/// Real/Imag - These return the real/imag part of a complex operand.  If
comment|///   applied to a non-complex value, the former returns its operand and the
comment|///   later returns zero in the type of the operand.
comment|///
name|class
name|UnaryOperator
operator|:
name|public
name|Expr
block|{
name|public
operator|:
typedef|typedef
name|UnaryOperatorKind
name|Opcode
typedef|;
name|private
operator|:
name|unsigned
name|Opc
operator|:
literal|5
block|;
name|SourceLocation
name|Loc
block|;
name|Stmt
operator|*
name|Val
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
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
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
name|VK
argument_list|,
name|OK
argument_list|,
name|input
operator|->
name|isTypeDependent
argument_list|()
operator|||
name|type
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|input
operator|->
name|isValueDependent
argument_list|()
argument_list|,
operator|(
name|input
operator|->
name|isInstantiationDependent
argument_list|()
operator|||
name|type
operator|->
name|isInstantiationDependentType
argument_list|()
operator|)
argument_list|,
name|input
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Opc
argument_list|(
name|opc
argument_list|)
block|,
name|Loc
argument_list|(
name|l
argument_list|)
block|,
name|Val
argument_list|(
argument|input
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
argument|UO_AddrOf
argument_list|)
block|{ }
name|Opcode
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Opcode
operator|>
operator|(
name|Opc
operator|)
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
name|UO_PostInc
operator|||
name|Op
operator|==
name|UO_PostDec
return|;
block|}
comment|/// isPrefix - Return true if this is a prefix operation, like --x.
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
name|UO_PreInc
operator|||
name|Op
operator|==
name|UO_PreDec
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
name|getOpcode
argument_list|()
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
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isIncrementOp
argument_list|(
argument|Opcode Op
argument_list|)
block|{
return|return
name|Op
operator|==
name|UO_PreInc
operator|||
name|Op
operator|==
name|UO_PostInc
return|;
block|}
name|bool
name|isIncrementOp
argument_list|()
specifier|const
block|{
return|return
name|isIncrementOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isDecrementOp
argument_list|(
argument|Opcode Op
argument_list|)
block|{
return|return
name|Op
operator|==
name|UO_PreDec
operator|||
name|Op
operator|==
name|UO_PostDec
return|;
block|}
name|bool
name|isDecrementOp
argument_list|()
specifier|const
block|{
return|return
name|isDecrementOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isIncrementDecrementOp
argument_list|(
argument|Opcode Op
argument_list|)
block|{
return|return
name|Op
operator|<=
name|UO_PreDec
return|;
block|}
name|bool
name|isIncrementDecrementOp
argument_list|()
specifier|const
block|{
return|return
name|isIncrementDecrementOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
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
name|UO_Plus
operator|&&
name|Op
operator|<=
name|UO_LNot
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
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
comment|/// getOpcodeStr - Turn an Opcode enum value into the punctuation char it
comment|/// corresponds to, e.g. "sizeof" or "[pre]++"
specifier|static
name|StringRef
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|isPostfix
argument_list|()
operator|?
name|Val
operator|->
name|getLocStart
argument_list|()
operator|:
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
name|isPostfix
argument_list|()
condition|?
name|Loc
else|:
name|Val
operator|->
name|getLocEnd
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
name|UnaryOperatorClass
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
name|Val
argument_list|,
operator|&
name|Val
operator|+
literal|1
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
operator|&
name|Val
argument_list|,
operator|&
name|Val
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// Helper class for OffsetOfExpr.
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
block|{}
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
condition|?
name|DotLoc
else|:
name|NameLoc
argument_list|,
name|NameLoc
argument_list|)
block|,
name|Data
argument_list|(
argument|reinterpret_cast<uintptr_t>(Field) | OffsetOfNode::Field
argument_list|)
block|{}
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
condition|?
name|DotLoc
else|:
name|NameLoc
argument_list|,
name|NameLoc
argument_list|)
block|,
name|Data
argument_list|(
argument|reinterpret_cast<uintptr_t>(Name) | Identifier
argument_list|)
block|{}
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
expr|}
block|;
comment|/// OffsetOfExpr - [C99 7.17] - This represents an expression of the form
comment|/// offsetof(record-type, member-designator). For example, given:
comment|/// @code
comment|/// struct S {
comment|///   float f;
comment|///   double d;
comment|/// };
comment|/// struct T {
comment|///   int i;
comment|///   struct S s[10];
comment|/// };
comment|/// @endcode
comment|/// we can represent and evaluate the expression @c offsetof(struct T, s[2].d).
name|class
name|OffsetOfExpr
name|final
operator|:
name|public
name|Expr
block|,
name|private
name|llvm
operator|::
name|TrailingObjects
operator|<
name|OffsetOfExpr
block|,
name|OffsetOfNode
block|,
name|Expr
operator|*
operator|>
block|{
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
name|size_t
name|numTrailingObjects
argument_list|(
argument|OverloadToken<OffsetOfNode>
argument_list|)
specifier|const
block|{
return|return
name|NumComps
return|;
block|}
name|OffsetOfExpr
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|QualType type
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|TypeSourceInfo *tsi
argument_list|,
argument|ArrayRef<OffsetOfNode> comps
argument_list|,
argument|ArrayRef<Expr*> exprs
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
name|nullptr
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
argument|const ASTContext&C
argument_list|,
argument|QualType type
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|TypeSourceInfo *tsi
argument_list|,
argument|ArrayRef<OffsetOfNode> comps
argument_list|,
argument|ArrayRef<Expr*> exprs
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|;
specifier|static
name|OffsetOfExpr
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
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
specifier|const
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
name|getTrailingObjects
operator|<
name|OffsetOfNode
operator|>
operator|(
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
name|getTrailingObjects
operator|<
name|OffsetOfNode
operator|>
operator|(
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
name|getTrailingObjects
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
index|[
name|Idx
index|]
return|;
block|}
specifier|const
name|Expr
operator|*
name|getIndexExpr
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
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
name|getTrailingObjects
operator|<
name|Expr
operator|*
operator|>
operator|(
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
name|getTrailingObjects
operator|<
name|Expr
operator|*
operator|>
operator|(
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
name|OffsetOfExprClass
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
name|getTrailingObjects
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
operator|)
block|;
return|return
name|child_range
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
name|NumExprs
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
name|Stmt
operator|*
specifier|const
operator|*
name|begin
operator|=
name|reinterpret_cast
operator|<
name|Stmt
operator|*
specifier|const
operator|*
operator|>
operator|(
name|getTrailingObjects
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
operator|)
block|;
return|return
name|const_child_range
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
name|NumExprs
argument_list|)
return|;
block|}
name|friend
name|TrailingObjects
block|; }
block|;
comment|/// UnaryExprOrTypeTraitExpr - expression with either a type or (unevaluated)
comment|/// expression operand.  Used for sizeof/alignof (C99 6.5.3.4) and
comment|/// vec_step (OpenCL 1.1 6.11.12).
name|class
name|UnaryExprOrTypeTraitExpr
operator|:
name|public
name|Expr
block|{
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
name|public
operator|:
name|UnaryExprOrTypeTraitExpr
argument_list|(
argument|UnaryExprOrTypeTrait ExprKind
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
name|UnaryExprOrTypeTraitExprClass
argument_list|,
name|resultType
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
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
argument_list|,
name|TInfo
operator|->
name|getType
argument_list|()
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|TInfo
operator|->
name|getType
argument_list|()
operator|->
name|containsUnexpandedParameterPack
argument_list|()
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
name|UnaryExprOrTypeTraitExprBits
operator|.
name|Kind
operator|=
name|ExprKind
block|;
name|UnaryExprOrTypeTraitExprBits
operator|.
name|IsType
operator|=
name|true
block|;
name|Argument
operator|.
name|Ty
operator|=
name|TInfo
block|;   }
name|UnaryExprOrTypeTraitExpr
argument_list|(
argument|UnaryExprOrTypeTrait ExprKind
argument_list|,
argument|Expr *E
argument_list|,
argument|QualType resultType
argument_list|,
argument|SourceLocation op
argument_list|,
argument|SourceLocation rp
argument_list|)
block|;
comment|/// \brief Construct an empty sizeof/alignof expression.
name|explicit
name|UnaryExprOrTypeTraitExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|UnaryExprOrTypeTraitExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|UnaryExprOrTypeTrait
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|UnaryExprOrTypeTrait
operator|>
operator|(
name|UnaryExprOrTypeTraitExprBits
operator|.
name|Kind
operator|)
return|;
block|}
name|void
name|setKind
argument_list|(
argument|UnaryExprOrTypeTrait K
argument_list|)
block|{
name|UnaryExprOrTypeTraitExprBits
operator|.
name|Kind
operator|=
name|K
block|;}
name|bool
name|isArgumentType
argument_list|()
specifier|const
block|{
return|return
name|UnaryExprOrTypeTraitExprBits
operator|.
name|IsType
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
name|UnaryExprOrTypeTraitExpr
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
name|UnaryExprOrTypeTraitExprBits
operator|.
name|IsType
operator|=
name|false
block|;   }
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
name|UnaryExprOrTypeTraitExprBits
operator|.
name|IsType
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|OpLoc
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
name|UnaryExprOrTypeTraitExprClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|;
name|const_child_range
name|children
argument_list|()
specifier|const
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
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
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
name|VK
argument_list|,
name|OK
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
argument_list|,
operator|(
name|lhs
operator|->
name|isInstantiationDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
argument_list|,
operator|(
name|lhs
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|rhs
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getLHS
argument_list|()
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
name|RBracketLoc
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
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|END_EXPR
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
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
name|END_EXPR
argument_list|)
return|;
block|}
expr|}
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
name|PREARGS_START
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
name|void
name|updateDependenciesFromArg
argument_list|(
name|Expr
operator|*
name|Arg
argument_list|)
block|;
name|protected
operator|:
comment|// These versions of the constructor are for derived classes.
name|CallExpr
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|StmtClass SC
argument_list|,
argument|Expr *fn
argument_list|,
argument|ArrayRef<Expr *> preargs
argument_list|,
argument|ArrayRef<Expr *> args
argument_list|,
argument|QualType t
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation rparenloc
argument_list|)
block|;
name|CallExpr
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|StmtClass SC
argument_list|,
argument|Expr *fn
argument_list|,
argument|ArrayRef<Expr *> args
argument_list|,
argument|QualType t
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation rparenloc
argument_list|)
block|;
name|CallExpr
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|StmtClass SC
argument_list|,
argument|unsigned NumPreArgs
argument_list|,
argument|EmptyShell Empty
argument_list|)
block|;
name|Stmt
operator|*
name|getPreArg
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumPreArgs
argument_list|()
operator|&&
literal|"Prearg access out of range!"
argument_list|)
block|;
return|return
name|SubExprs
index|[
name|PREARGS_START
operator|+
name|i
index|]
return|;
block|}
specifier|const
name|Stmt
operator|*
name|getPreArg
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumPreArgs
argument_list|()
operator|&&
literal|"Prearg access out of range!"
argument_list|)
block|;
return|return
name|SubExprs
index|[
name|PREARGS_START
operator|+
name|i
index|]
return|;
block|}
name|void
name|setPreArg
argument_list|(
argument|unsigned i
argument_list|,
argument|Stmt *PreArg
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumPreArgs
argument_list|()
operator|&&
literal|"Prearg access out of range!"
argument_list|)
block|;
name|SubExprs
index|[
name|PREARGS_START
operator|+
name|i
index|]
operator|=
name|PreArg
block|;   }
name|unsigned
name|getNumPreArgs
argument_list|()
specifier|const
block|{
return|return
name|CallExprBits
operator|.
name|NumPreArgs
return|;
block|}
name|public
operator|:
name|CallExpr
argument_list|(
argument|const ASTContext& C
argument_list|,
argument|Expr *fn
argument_list|,
argument|ArrayRef<Expr*> args
argument_list|,
argument|QualType t
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation rparenloc
argument_list|)
block|;
comment|/// \brief Build an empty call expression.
name|CallExpr
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|StmtClass SC
argument_list|,
argument|EmptyShell Empty
argument_list|)
block|;
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
comment|/// \brief Retrieve the call arguments.
name|Expr
operator|*
operator|*
name|getArgs
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
name|getNumPreArgs
argument_list|()
operator|+
name|PREARGS_START
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
specifier|const
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
name|SubExprs
operator|+
name|getNumPreArgs
argument_list|()
operator|+
name|PREARGS_START
operator|)
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
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|Arg
operator|+
name|getNumPreArgs
argument_list|()
operator|+
name|PREARGS_START
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
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|Arg
operator|+
name|getNumPreArgs
argument_list|()
operator|+
name|PREARGS_START
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
name|getNumPreArgs
argument_list|()
operator|+
name|PREARGS_START
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
argument|const ASTContext& C
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
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|arg_iterator
operator|>
name|arg_range
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|const_arg_iterator
operator|>
name|arg_const_range
expr_stmt|;
name|arg_range
name|arguments
argument_list|()
block|{
return|return
name|arg_range
argument_list|(
name|arg_begin
argument_list|()
argument_list|,
name|arg_end
argument_list|()
argument_list|)
return|;
block|}
name|arg_const_range
name|arguments
argument_list|()
specifier|const
block|{
return|return
name|arg_const_range
argument_list|(
name|arg_begin
argument_list|()
argument_list|,
name|arg_end
argument_list|()
argument_list|)
return|;
block|}
name|arg_iterator
name|arg_begin
argument_list|()
block|{
return|return
name|SubExprs
operator|+
name|PREARGS_START
operator|+
name|getNumPreArgs
argument_list|()
return|;
block|}
name|arg_iterator
name|arg_end
argument_list|()
block|{
return|return
name|SubExprs
operator|+
name|PREARGS_START
operator|+
name|getNumPreArgs
argument_list|()
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
name|PREARGS_START
operator|+
name|getNumPreArgs
argument_list|()
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
name|PREARGS_START
operator|+
name|getNumPreArgs
argument_list|()
operator|+
name|getNumArgs
argument_list|()
return|;
block|}
comment|/// This method provides fast access to all the subexpressions of
comment|/// a CallExpr without going through the slower virtual child_iterator
comment|/// interface.  This provides efficient reverse iteration of the
comment|/// subexpressions.  This is currently used for CFG construction.
name|ArrayRef
operator|<
name|Stmt
operator|*
operator|>
name|getRawSubExprs
argument_list|()
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|SubExprs
argument_list|,
name|getNumPreArgs
argument_list|()
operator|+
name|PREARGS_START
operator|+
name|getNumArgs
argument_list|()
argument_list|)
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
comment|/// getBuiltinCallee - If this is a call to a builtin, return the builtin ID
comment|/// of the callee. If not, return 0.
name|unsigned
name|getBuiltinCallee
argument_list|()
specifier|const
block|;
comment|/// \brief Returns \c true if this is a call to a builtin which does not
comment|/// evaluate side-effects within its arguments.
name|bool
name|isUnevaluatedBuiltinCall
argument_list|(
argument|const ASTContext&Ctx
argument_list|)
specifier|const
block|;
comment|/// getCallReturnType - Get the return type of the call expr. This is not
comment|/// always the type of the expr itself, if the return type is a reference
comment|/// type.
name|QualType
name|getCallReturnType
argument_list|(
argument|const ASTContext&Ctx
argument_list|)
specifier|const
block|;
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
name|NumArgs
operator|+
name|getNumPreArgs
argument_list|()
operator|+
name|PREARGS_START
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
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
name|NumArgs
operator|+
name|getNumPreArgs
argument_list|()
operator|+
name|PREARGS_START
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// Extra data stored in some MemberExpr objects.
block|struct
name|MemberExprNameQualifier
block|{
comment|/// \brief The nested-name-specifier that qualifies the name, including
comment|/// source-location information.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
comment|/// \brief The DeclAccessPair through which the MemberDecl was found due to
comment|/// name qualifiers.
name|DeclAccessPair
name|FoundDecl
block|; }
block|;
comment|/// MemberExpr - [C99 6.5.2.3] Structure and Union Members.  X->F and X.F.
comment|///
name|class
name|MemberExpr
name|final
operator|:
name|public
name|Expr
block|,
name|private
name|llvm
operator|::
name|TrailingObjects
operator|<
name|MemberExpr
block|,
name|MemberExprNameQualifier
block|,
name|ASTTemplateKWAndArgsInfo
block|,
name|TemplateArgumentLoc
operator|>
block|{
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
comment|/// MemberDNLoc - Provides source/type location info for the
comment|/// declaration name embedded in MemberDecl.
name|DeclarationNameLoc
name|MemberDNLoc
block|;
comment|/// MemberLoc - This is the location of the member name.
name|SourceLocation
name|MemberLoc
block|;
comment|/// This is the location of the -> or . in the expression.
name|SourceLocation
name|OperatorLoc
block|;
comment|/// IsArrow - True if this is "X->F", false if this is "X.F".
name|bool
name|IsArrow
operator|:
literal|1
block|;
comment|/// \brief True if this member expression used a nested-name-specifier to
comment|/// refer to the member, e.g., "x->Base::f", or found its member via a using
comment|/// declaration.  When true, a MemberExprNameQualifier
comment|/// structure is allocated immediately after the MemberExpr.
name|bool
name|HasQualifierOrFoundDecl
operator|:
literal|1
block|;
comment|/// \brief True if this member expression specified a template keyword
comment|/// and/or a template argument list explicitly, e.g., x->f<int>,
comment|/// x->template f, x->template f<int>.
comment|/// When true, an ASTTemplateKWAndArgsInfo structure and its
comment|/// TemplateArguments (if any) are present.
name|bool
name|HasTemplateKWAndArgsInfo
operator|:
literal|1
block|;
comment|/// \brief True if this member expression refers to a method that
comment|/// was resolved from an overloaded set having size greater than 1.
name|bool
name|HadMultipleCandidates
operator|:
literal|1
block|;
name|size_t
name|numTrailingObjects
argument_list|(
argument|OverloadToken<MemberExprNameQualifier>
argument_list|)
specifier|const
block|{
return|return
name|HasQualifierOrFoundDecl
condition|?
literal|1
else|:
literal|0
return|;
block|}
name|size_t
name|numTrailingObjects
argument_list|(
argument|OverloadToken<ASTTemplateKWAndArgsInfo>
argument_list|)
specifier|const
block|{
return|return
name|HasTemplateKWAndArgsInfo
condition|?
literal|1
else|:
literal|0
return|;
block|}
name|public
operator|:
name|MemberExpr
argument_list|(
argument|Expr *base
argument_list|,
argument|bool isarrow
argument_list|,
argument|SourceLocation operatorloc
argument_list|,
argument|ValueDecl *memberdecl
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType ty
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|)
operator|:
name|Expr
argument_list|(
name|MemberExprClass
argument_list|,
name|ty
argument_list|,
name|VK
argument_list|,
name|OK
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
argument_list|,
name|base
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|base
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Base
argument_list|(
name|base
argument_list|)
block|,
name|MemberDecl
argument_list|(
name|memberdecl
argument_list|)
block|,
name|MemberDNLoc
argument_list|(
name|NameInfo
operator|.
name|getInfo
argument_list|()
argument_list|)
block|,
name|MemberLoc
argument_list|(
name|NameInfo
operator|.
name|getLoc
argument_list|()
argument_list|)
block|,
name|OperatorLoc
argument_list|(
name|operatorloc
argument_list|)
block|,
name|IsArrow
argument_list|(
name|isarrow
argument_list|)
block|,
name|HasQualifierOrFoundDecl
argument_list|(
name|false
argument_list|)
block|,
name|HasTemplateKWAndArgsInfo
argument_list|(
name|false
argument_list|)
block|,
name|HadMultipleCandidates
argument_list|(
argument|false
argument_list|)
block|{
name|assert
argument_list|(
name|memberdecl
operator|->
name|getDeclName
argument_list|()
operator|==
name|NameInfo
operator|.
name|getName
argument_list|()
argument_list|)
block|;   }
comment|// NOTE: this constructor should be used only when it is known that
comment|// the member name can not provide additional syntactic info
comment|// (i.e., source locations for C++ operator names or type source info
comment|// for constructors, destructors and conversion operators).
name|MemberExpr
argument_list|(
argument|Expr *base
argument_list|,
argument|bool isarrow
argument_list|,
argument|SourceLocation operatorloc
argument_list|,
argument|ValueDecl *memberdecl
argument_list|,
argument|SourceLocation l
argument_list|,
argument|QualType ty
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|)
operator|:
name|Expr
argument_list|(
name|MemberExprClass
argument_list|,
name|ty
argument_list|,
name|VK
argument_list|,
name|OK
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
argument_list|,
name|base
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|base
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Base
argument_list|(
name|base
argument_list|)
block|,
name|MemberDecl
argument_list|(
name|memberdecl
argument_list|)
block|,
name|MemberDNLoc
argument_list|()
block|,
name|MemberLoc
argument_list|(
name|l
argument_list|)
block|,
name|OperatorLoc
argument_list|(
name|operatorloc
argument_list|)
block|,
name|IsArrow
argument_list|(
name|isarrow
argument_list|)
block|,
name|HasQualifierOrFoundDecl
argument_list|(
name|false
argument_list|)
block|,
name|HasTemplateKWAndArgsInfo
argument_list|(
name|false
argument_list|)
block|,
name|HadMultipleCandidates
argument_list|(
argument|false
argument_list|)
block|{}
specifier|static
name|MemberExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|Expr *base
argument_list|,
argument|bool isarrow
argument_list|,
argument|SourceLocation OperatorLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation TemplateKWLoc
argument_list|,
argument|ValueDecl *memberdecl
argument_list|,
argument|DeclAccessPair founddecl
argument_list|,
argument|DeclarationNameInfo MemberNameInfo
argument_list|,
argument|const TemplateArgumentListInfo *targs
argument_list|,
argument|QualType ty
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|)
block|;
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
comment|/// \brief Retrieve the member declaration to which this expression refers.
comment|///
comment|/// The returned declaration will be a FieldDecl or (in C++) a VarDecl (for
comment|/// static data members), a CXXMethodDecl, or an EnumConstantDecl.
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
name|void
name|setMemberDecl
argument_list|(
argument|ValueDecl *D
argument_list|)
block|{
name|MemberDecl
operator|=
name|D
block|; }
comment|/// \brief Retrieves the declaration found by lookup.
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
return|return
name|getTrailingObjects
operator|<
name|MemberExprNameQualifier
operator|>
operator|(
operator|)
operator|->
name|FoundDecl
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
name|getQualifier
argument_list|()
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief If the member name was qualified, retrieves the
comment|/// nested-name-specifier that precedes the member name, with source-location
comment|/// information.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasQualifierOrFoundDecl
condition|)
return|return
name|NestedNameSpecifierLoc
argument_list|()
return|;
return|return
name|getTrailingObjects
operator|<
name|MemberExprNameQualifier
operator|>
operator|(
operator|)
operator|->
name|QualifierLoc
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief If the member name was qualified, retrieves the
end_comment

begin_comment
comment|/// nested-name-specifier that precedes the member name. Otherwise, returns
end_comment

begin_comment
comment|/// NULL.
end_comment

begin_expr_stmt
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|getQualifierLoc
argument_list|()
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
comment|/// the member name, if any.
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
name|getTrailingObjects
operator|<
name|ASTTemplateKWAndArgsInfo
operator|>
operator|(
operator|)
operator|->
name|TemplateKWLoc
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
name|getTrailingObjects
operator|<
name|ASTTemplateKWAndArgsInfo
operator|>
operator|(
operator|)
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
name|getTrailingObjects
operator|<
name|ASTTemplateKWAndArgsInfo
operator|>
operator|(
operator|)
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
comment|/// \brief Determines whether the member name was followed by an
end_comment

begin_comment
comment|/// explicit template argument list.
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
name|hasExplicitTemplateArgs
argument_list|()
condition|)
name|getTrailingObjects
operator|<
name|ASTTemplateKWAndArgsInfo
operator|>
operator|(
operator|)
operator|->
name|copyInto
argument_list|(
name|getTrailingObjects
operator|<
name|TemplateArgumentLoc
operator|>
operator|(
operator|)
argument_list|,
name|List
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the template arguments provided as part of this
end_comment

begin_comment
comment|/// template-id.
end_comment

begin_expr_stmt
specifier|const
name|TemplateArgumentLoc
operator|*
name|getTemplateArgs
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
name|nullptr
return|;
end_expr_stmt

begin_return
return|return
name|getTrailingObjects
operator|<
name|TemplateArgumentLoc
operator|>
operator|(
operator|)
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
name|hasExplicitTemplateArgs
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|getTrailingObjects
operator|<
name|ASTTemplateKWAndArgsInfo
operator|>
operator|(
operator|)
operator|->
name|NumTemplateArgs
return|;
end_return

begin_expr_stmt
unit|}    ArrayRef
operator|<
name|TemplateArgumentLoc
operator|>
name|template_arguments
argument_list|()
specifier|const
block|{
return|return
block|{
name|getTemplateArgs
argument_list|()
block|,
name|getNumTemplateArgs
argument_list|()
block|}
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the member declaration name info.
end_comment

begin_expr_stmt
name|DeclarationNameInfo
name|getMemberNameInfo
argument_list|()
specifier|const
block|{
return|return
name|DeclarationNameInfo
argument_list|(
name|MemberDecl
operator|->
name|getDeclName
argument_list|()
argument_list|,
name|MemberLoc
argument_list|,
name|MemberDNLoc
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getOperatorLoc
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|OperatorLoc
return|;
block|}
end_expr_stmt

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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|MemberLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether the base of this explicit is implicit.
end_comment

begin_expr_stmt
name|bool
name|isImplicitAccess
argument_list|()
specifier|const
block|{
return|return
name|getBase
argument_list|()
operator|&&
name|getBase
argument_list|()
operator|->
name|isImplicitCXXThis
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if this member expression refers to a method that
end_comment

begin_comment
comment|/// was resolved from an overloaded set having size greater than 1.
end_comment

begin_expr_stmt
name|bool
name|hadMultipleCandidates
argument_list|()
specifier|const
block|{
return|return
name|HadMultipleCandidates
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Sets the flag telling whether this expression refers to
end_comment

begin_comment
comment|/// a method that was resolved from an overloaded set having size
end_comment

begin_comment
comment|/// greater than 1.
end_comment

begin_function
name|void
name|setHadMultipleCandidates
parameter_list|(
name|bool
name|V
init|=
name|true
parameter_list|)
block|{
name|HadMultipleCandidates
operator|=
name|V
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Returns true if virtual dispatch is performed.
end_comment

begin_comment
comment|/// If the member access is fully qualified, (i.e. X::f()), virtual
end_comment

begin_comment
comment|/// dispatching is not performed. In -fapple-kext mode qualified
end_comment

begin_comment
comment|/// calls to virtual method will still go through the vtable.
end_comment

begin_decl_stmt
name|bool
name|performsVirtualDispatch
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LO
argument_list|)
decl|const
block|{
return|return
name|LO
operator|.
name|AppleKext
operator|||
operator|!
name|hasQualifier
argument_list|()
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
name|MemberExprClass
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

begin_expr_stmt
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
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
end_expr_stmt

begin_decl_stmt
name|friend
name|TrailingObjects
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTReader
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
comment|/// The int part of the pair stores whether this expr is file scope.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|TypeSourceInfo
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|TInfoAndScope
block|;
name|Stmt
operator|*
name|Init
block|;
name|public
operator|:
name|CompoundLiteralExpr
argument_list|(
argument|SourceLocation lparenloc
argument_list|,
argument|TypeSourceInfo *tinfo
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
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
name|VK
argument_list|,
name|OK_Ordinary
argument_list|,
name|tinfo
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|init
operator|->
name|isValueDependent
argument_list|()
argument_list|,
operator|(
name|init
operator|->
name|isInstantiationDependent
argument_list|()
operator|||
name|tinfo
operator|->
name|getType
argument_list|()
operator|->
name|isInstantiationDependentType
argument_list|()
operator|)
argument_list|,
name|init
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|lparenloc
argument_list|)
block|,
name|TInfoAndScope
argument_list|(
name|tinfo
argument_list|,
name|fileScope
argument_list|)
block|,
name|Init
argument_list|(
argument|init
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
name|TInfoAndScope
operator|.
name|getInt
argument_list|()
return|;
block|}
name|void
name|setFileScope
argument_list|(
argument|bool FS
argument_list|)
block|{
name|TInfoAndScope
operator|.
name|setInt
argument_list|(
name|FS
argument_list|)
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
name|TInfoAndScope
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|void
name|setTypeSourceInfo
argument_list|(
argument|TypeSourceInfo *tinfo
argument_list|)
block|{
name|TInfoAndScope
operator|.
name|setPointer
argument_list|(
name|tinfo
argument_list|)
block|;   }
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
comment|// FIXME: Init should never be null.
if|if
condition|(
operator|!
name|Init
condition|)
return|return
name|SourceLocation
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
name|getLocStart
argument_list|()
return|;
end_decl_stmt

begin_return
return|return
name|LParenLoc
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
comment|// FIXME: Init should never be null.
if|if
condition|(
operator|!
name|Init
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|Init
operator|->
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
name|CompoundLiteralExprClass
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
name|Init
argument_list|,
operator|&
name|Init
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
operator|&
name|Init
argument_list|,
operator|&
name|Init
operator|+
literal|1
argument_list|)
return|;
block|}
end_expr_stmt

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
name|private
operator|:
name|Stmt
operator|*
name|Op
block|;
name|bool
name|CastConsistency
argument_list|()
specifier|const
block|;
specifier|const
name|CXXBaseSpecifier
operator|*
specifier|const
operator|*
name|path_buffer
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
name|path_buffer
argument_list|()
return|;
block|}
name|CXXBaseSpecifier
operator|*
operator|*
name|path_buffer
argument_list|()
block|;
name|void
name|setBasePathSize
argument_list|(
argument|unsigned basePathSize
argument_list|)
block|{
name|CastExprBits
operator|.
name|BasePathSize
operator|=
name|basePathSize
block|;
name|assert
argument_list|(
name|CastExprBits
operator|.
name|BasePathSize
operator|==
name|basePathSize
operator|&&
literal|"basePathSize doesn't fit in bits of CastExprBits.BasePathSize!"
argument_list|)
block|;   }
name|protected
operator|:
name|CastExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|QualType ty
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|const CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|unsigned BasePathSize
argument_list|)
operator|:
name|Expr
argument_list|(
name|SC
argument_list|,
name|ty
argument_list|,
name|VK
argument_list|,
name|OK_Ordinary
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
argument_list|,
operator|(
name|ty
operator|->
name|isInstantiationDependentType
argument_list|()
operator|||
operator|(
name|op
operator|&&
name|op
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
operator|)
argument_list|,
comment|// An implicit cast expression doesn't (lexically) contain an
comment|// unexpanded pack, even if its target type does.
operator|(
operator|(
name|SC
operator|!=
name|ImplicitCastExprClass
operator|&&
name|ty
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
operator|||
operator|(
name|op
operator|&&
name|op
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
operator|)
argument_list|)
block|,
name|Op
argument_list|(
argument|op
argument_list|)
block|{
name|assert
argument_list|(
name|kind
operator|!=
name|CK_Invalid
operator|&&
literal|"creating cast with invalid cast kind"
argument_list|)
block|;
name|CastExprBits
operator|.
name|Kind
operator|=
name|kind
block|;
name|setBasePathSize
argument_list|(
name|BasePathSize
argument_list|)
block|;
name|assert
argument_list|(
name|CastConsistency
argument_list|()
argument_list|)
block|;   }
comment|/// \brief Construct an empty cast.
name|CastExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|EmptyShell Empty
argument_list|,
argument|unsigned BasePathSize
argument_list|)
operator|:
name|Expr
argument_list|(
argument|SC
argument_list|,
argument|Empty
argument_list|)
block|{
name|setBasePathSize
argument_list|(
name|BasePathSize
argument_list|)
block|;   }
name|public
operator|:
name|CastKind
name|getCastKind
argument_list|()
specifier|const
block|{
return|return
operator|(
name|CastKind
operator|)
name|CastExprBits
operator|.
name|Kind
return|;
block|}
name|void
name|setCastKind
argument_list|(
argument|CastKind K
argument_list|)
block|{
name|CastExprBits
operator|.
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
typedef|typedef
name|CXXBaseSpecifier
modifier|*
modifier|*
name|path_iterator
typedef|;
end_decl_stmt

begin_typedef
typedef|typedef
specifier|const
name|CXXBaseSpecifier
modifier|*
specifier|const
modifier|*
name|path_const_iterator
typedef|;
end_typedef

begin_expr_stmt
name|bool
name|path_empty
argument_list|()
specifier|const
block|{
return|return
name|CastExprBits
operator|.
name|BasePathSize
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|path_size
argument_list|()
specifier|const
block|{
return|return
name|CastExprBits
operator|.
name|BasePathSize
return|;
block|}
end_expr_stmt

begin_function
name|path_iterator
name|path_begin
parameter_list|()
block|{
return|return
name|path_buffer
argument_list|()
return|;
block|}
end_function

begin_function
name|path_iterator
name|path_end
parameter_list|()
block|{
return|return
name|path_buffer
argument_list|()
operator|+
name|path_size
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|path_const_iterator
name|path_begin
argument_list|()
specifier|const
block|{
return|return
name|path_buffer
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|path_const_iterator
name|path_end
argument_list|()
specifier|const
block|{
return|return
name|path_buffer
argument_list|()
operator|+
name|path_size
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
name|Op
argument_list|,
operator|&
name|Op
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
operator|&
name|Op
argument_list|,
operator|&
name|Op
operator|+
literal|1
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
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
comment|/// an lvalue or xvalue. For example:
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
comment|/// Derived&&ref();
end_comment

begin_comment
comment|/// void f(Derived d) {
end_comment

begin_comment
comment|///   Base& b = d; // initializer is an ImplicitCastExpr
end_comment

begin_comment
comment|///                // to an lvalue of type Base
end_comment

begin_comment
comment|///   Base&& r = ref(); // initializer is an ImplicitCastExpr
end_comment

begin_comment
comment|///                     // to an xvalue of type Base
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
name|final
range|:
name|public
name|CastExpr
decl_stmt|,
name|private
name|llvm
decl|::
name|TrailingObjects
decl|<
name|ImplicitCastExpr
decl_stmt|,
name|CXXBaseSpecifier
modifier|*
decl|>
block|{
name|private
label|:
name|ImplicitCastExpr
argument_list|(
argument|QualType ty
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|unsigned BasePathLength
argument_list|,
argument|ExprValueKind VK
argument_list|)
block|:
name|CastExpr
argument_list|(
argument|ImplicitCastExprClass
argument_list|,
argument|ty
argument_list|,
argument|VK
argument_list|,
argument|kind
argument_list|,
argument|op
argument_list|,
argument|BasePathLength
argument_list|)
block|{   }
comment|/// \brief Construct an empty implicit cast.
name|explicit
name|ImplicitCastExpr
argument_list|(
argument|EmptyShell Shell
argument_list|,
argument|unsigned PathSize
argument_list|)
block|:
name|CastExpr
argument_list|(
argument|ImplicitCastExprClass
argument_list|,
argument|Shell
argument_list|,
argument|PathSize
argument_list|)
block|{ }
name|public
label|:
enum|enum
name|OnStack_t
block|{
name|OnStack
block|}
enum|;
name|ImplicitCastExpr
argument_list|(
argument|OnStack_t _
argument_list|,
argument|QualType ty
argument_list|,
argument|CastKind kind
argument_list|,
argument|Expr *op
argument_list|,
argument|ExprValueKind VK
argument_list|)
block|:
name|CastExpr
argument_list|(
argument|ImplicitCastExprClass
argument_list|,
argument|ty
argument_list|,
argument|VK
argument_list|,
argument|kind
argument_list|,
argument|op
argument_list|,
literal|0
argument_list|)
block|{   }
specifier|static
name|ImplicitCastExpr
modifier|*
name|Create
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|QualType
name|T
parameter_list|,
name|CastKind
name|Kind
parameter_list|,
name|Expr
modifier|*
name|Operand
parameter_list|,
specifier|const
name|CXXCastPath
modifier|*
name|BasePath
parameter_list|,
name|ExprValueKind
name|Cat
parameter_list|)
function_decl|;
specifier|static
name|ImplicitCastExpr
modifier|*
name|CreateEmpty
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|unsigned
name|PathSize
parameter_list|)
function_decl|;
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getSubExpr
argument_list|()
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
name|ImplicitCastExprClass
return|;
block|}
name|friend
name|TrailingObjects
decl_stmt|;
name|friend
name|class
name|CastExpr
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|Expr
operator|*
name|Expr
operator|::
name|IgnoreImpCasts
argument_list|()
block|{
name|Expr
operator|*
name|e
operator|=
name|this
block|;
while|while
condition|(
name|ImplicitCastExpr
modifier|*
name|ice
init|=
name|dyn_cast
operator|<
name|ImplicitCastExpr
operator|>
operator|(
name|e
operator|)
condition|)
name|e
operator|=
name|ice
operator|->
name|getSubExpr
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|e
return|;
end_return

begin_comment
unit|}
comment|/// ExplicitCastExpr - An explicit cast written in the source
end_comment

begin_comment
comment|/// code.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class is effectively an abstract class, because it provides
end_comment

begin_comment
comment|/// the basic representation of an explicitly-written cast without
end_comment

begin_comment
comment|/// specifying which kind of cast (C cast, functional cast, static
end_comment

begin_comment
comment|/// cast, etc.) was written; specific derived classes represent the
end_comment

begin_comment
comment|/// particular style of cast and its location information.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Unlike implicit casts, explicit cast nodes have two different
end_comment

begin_comment
comment|/// types: the type that was written into the source code, and the
end_comment

begin_comment
comment|/// actual type of the expression as determined by semantic
end_comment

begin_comment
comment|/// analysis. These types may differ slightly. For example, in C++ one
end_comment

begin_comment
comment|/// can cast to a reference type, which indicates that the resulting
end_comment

begin_comment
comment|/// expression will be an lvalue or xvalue. The reference type, however,
end_comment

begin_comment
comment|/// will not be used as the type of the expression.
end_comment

begin_label
unit|class
name|ExplicitCastExpr
label|:
end_label

begin_decl_stmt
name|public
name|CastExpr
block|{
comment|/// TInfo - Source type info for the (written) type
comment|/// this expression is casting to.
name|TypeSourceInfo
modifier|*
name|TInfo
decl_stmt|;
name|protected
label|:
name|ExplicitCastExpr
argument_list|(
argument|StmtClass SC
argument_list|,
argument|QualType exprTy
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
argument_list|)
block|:
name|CastExpr
argument_list|(
name|SC
argument_list|,
name|exprTy
argument_list|,
name|VK
argument_list|,
name|kind
argument_list|,
name|op
argument_list|,
name|PathSize
argument_list|)
operator|,
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
argument_list|,
argument|unsigned PathSize
argument_list|)
operator|:
name|CastExpr
argument_list|(
argument|SC
argument_list|,
argument|Shell
argument_list|,
argument|PathSize
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
parameter_list|(
name|TypeSourceInfo
modifier|*
name|writtenTy
parameter_list|)
block|{
name|TInfo
operator|=
name|writtenTy
expr_stmt|;
block|}
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// CStyleCastExpr - An explicit cast in C (C99 6.5.4) or a C-style
end_comment

begin_comment
comment|/// cast in C++ (C++ [expr.cast]), which uses the syntax
end_comment

begin_comment
comment|/// (Type)expr. For example: @c (int)f.
end_comment

begin_decl_stmt
name|class
name|CStyleCastExpr
name|final
range|:
name|public
name|ExplicitCastExpr
decl_stmt|,
name|private
name|llvm
decl|::
name|TrailingObjects
decl|<
name|CStyleCastExpr
decl_stmt|,
name|CXXBaseSpecifier
modifier|*
decl|>
block|{
name|SourceLocation
name|LPLoc
decl_stmt|;
comment|// the location of the left paren
name|SourceLocation
name|RPLoc
decl_stmt|;
comment|// the location of the right paren
name|CStyleCastExpr
argument_list|(
argument|QualType exprTy
argument_list|,
argument|ExprValueKind vk
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
argument|SourceLocation r
argument_list|)
block|:
name|ExplicitCastExpr
argument_list|(
name|CStyleCastExprClass
argument_list|,
name|exprTy
argument_list|,
name|vk
argument_list|,
name|kind
argument_list|,
name|op
argument_list|,
name|PathSize
argument_list|,
name|writtenTy
argument_list|)
operator|,
name|LPLoc
argument_list|(
name|l
argument_list|)
operator|,
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
argument_list|,
argument|unsigned PathSize
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
argument|CStyleCastExprClass
argument_list|,
argument|Shell
argument_list|,
argument|PathSize
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|CStyleCastExpr
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
argument|const CXXCastPath *BasePath
argument_list|,
argument|TypeSourceInfo *WrittenTy
argument_list|,
argument|SourceLocation L
argument_list|,
argument|SourceLocation R
argument_list|)
expr_stmt|;
specifier|static
name|CStyleCastExpr
modifier|*
name|CreateEmpty
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|unsigned
name|PathSize
parameter_list|)
function_decl|;
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
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|LPLoc
operator|=
name|L
expr_stmt|;
block|}
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
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|RPLoc
operator|=
name|L
expr_stmt|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|LPLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
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
name|CStyleCastExprClass
return|;
block|}
name|friend
name|TrailingObjects
decl_stmt|;
name|friend
name|class
name|CastExpr
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A builtin binary operation expression such as "x + y" or "x<= y".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This expression node kind describes a builtin binary operation,
end_comment

begin_comment
comment|/// such as "x + y" for integer values "x" and "y". The operands will
end_comment

begin_comment
comment|/// already have been converted to appropriate types (e.g., by
end_comment

begin_comment
comment|/// performing promotions or conversions).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In C++, where operators may be overloaded, a different kind of
end_comment

begin_comment
comment|/// expression node (CXXOperatorCallExpr) is used to express the
end_comment

begin_comment
comment|/// invocation of an overloaded operator with operator syntax. Within
end_comment

begin_comment
comment|/// a C++ template, whether BinaryOperator or CXXOperatorCallExpr is
end_comment

begin_comment
comment|/// used to store an expression "x + y" depends on the subexpressions
end_comment

begin_comment
comment|/// for x and y. If neither x or y is type-dependent, and the "+"
end_comment

begin_comment
comment|/// operator resolves to a built-in operation, BinaryOperator will be
end_comment

begin_comment
comment|/// used to express the computation (x and y may still be
end_comment

begin_comment
comment|/// value-dependent). If either x or y is type-dependent, or if the
end_comment

begin_comment
comment|/// "+" resolves to an overloaded operator, CXXOperatorCallExpr will
end_comment

begin_comment
comment|/// be used to express the computation.
end_comment

begin_decl_stmt
name|class
name|BinaryOperator
range|:
name|public
name|Expr
block|{
name|public
operator|:
typedef|typedef
name|BinaryOperatorKind
name|Opcode
typedef|;
name|private
operator|:
name|unsigned
name|Opc
operator|:
literal|6
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This is only meaningful for operations on floating point types and 0
end_comment

begin_comment
comment|// otherwise.
end_comment

begin_decl_stmt
name|unsigned
name|FPFeatures
range|:
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SourceLocation
name|OpLoc
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
block|{
name|LHS
block|,
name|RHS
block|,
name|END_EXPR
block|}
enum|;
end_enum

begin_decl_stmt
name|Stmt
modifier|*
name|SubExprs
index|[
name|END_EXPR
index|]
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_macro
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
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|SourceLocation opLoc
argument_list|,
argument|FPOptions FPFeatures
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|Expr
argument_list|(
name|BinaryOperatorClass
argument_list|,
name|ResTy
argument_list|,
name|VK
argument_list|,
name|OK
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
argument_list|,
operator|(
name|lhs
operator|->
name|isInstantiationDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
argument_list|,
operator|(
name|lhs
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|rhs
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
argument_list|)
operator|,
name|Opc
argument_list|(
name|opc
argument_list|)
operator|,
name|FPFeatures
argument_list|(
name|FPFeatures
operator|.
name|getInt
argument_list|()
argument_list|)
operator|,
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
literal|"Use CompoundAssignOperator for compound assignments"
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
operator|,
name|Opc
argument_list|(
argument|BO_Comma
argument_list|)
block|{ }
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|OpLoc
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getOperatorLoc
argument_list|()
specifier|const
block|{
return|return
name|OpLoc
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setOperatorLoc
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|OpLoc
operator|=
name|L
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|Opcode
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Opcode
operator|>
operator|(
name|Opc
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setOpcode
parameter_list|(
name|Opcode
name|O
parameter_list|)
block|{
name|Opc
operator|=
name|O
expr_stmt|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
name|void
name|setLHS
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
name|SubExprs
index|[
name|LHS
index|]
operator|=
name|E
expr_stmt|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
name|void
name|setRHS
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
name|SubExprs
index|[
name|RHS
index|]
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
name|getLHS
argument_list|()
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
name|getRHS
argument_list|()
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getOpcodeStr - Turn an Opcode enum value into the punctuation char it
end_comment

begin_comment
comment|/// corresponds to, e.g. "<<=".
end_comment

begin_function_decl
specifier|static
name|StringRef
name|getOpcodeStr
parameter_list|(
name|Opcode
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|StringRef
name|getOpcodeStr
argument_list|()
specifier|const
block|{
return|return
name|getOpcodeStr
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the binary opcode that corresponds to the given
end_comment

begin_comment
comment|/// overloaded operator.
end_comment

begin_function_decl
specifier|static
name|Opcode
name|getOverloadedOpcode
parameter_list|(
name|OverloadedOperatorKind
name|OO
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the overloaded operator kind that corresponds to
end_comment

begin_comment
comment|/// the given binary opcode.
end_comment

begin_function_decl
specifier|static
name|OverloadedOperatorKind
name|getOverloadedOperator
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// predicates to categorize the respective opcodes.
end_comment

begin_expr_stmt
name|bool
name|isPtrMemOp
argument_list|()
specifier|const
block|{
return|return
name|Opc
operator|==
name|BO_PtrMemD
operator|||
name|Opc
operator|==
name|BO_PtrMemI
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|isMultiplicativeOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|>=
name|BO_Mul
operator|&&
name|Opc
operator|<=
name|BO_Rem
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|isMultiplicativeOp
argument_list|()
specifier|const
block|{
return|return
name|isMultiplicativeOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|isAdditiveOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|==
name|BO_Add
operator|||
name|Opc
operator|==
name|BO_Sub
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|isAdditiveOp
argument_list|()
specifier|const
block|{
return|return
name|isAdditiveOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|isShiftOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|==
name|BO_Shl
operator|||
name|Opc
operator|==
name|BO_Shr
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|isShiftOp
argument_list|()
specifier|const
block|{
return|return
name|isShiftOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|isBitwiseOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|>=
name|BO_And
operator|&&
name|Opc
operator|<=
name|BO_Or
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|isBitwiseOp
argument_list|()
specifier|const
block|{
return|return
name|isBitwiseOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|isRelationalOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|>=
name|BO_LT
operator|&&
name|Opc
operator|<=
name|BO_GE
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|isRelationalOp
argument_list|()
specifier|const
block|{
return|return
name|isRelationalOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|isEqualityOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|==
name|BO_EQ
operator|||
name|Opc
operator|==
name|BO_NE
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|isEqualityOp
argument_list|()
specifier|const
block|{
return|return
name|isEqualityOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|isComparisonOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|>=
name|BO_LT
operator|&&
name|Opc
operator|<=
name|BO_NE
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|isComparisonOp
argument_list|()
specifier|const
block|{
return|return
name|isComparisonOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|Opcode
name|negateComparisonOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
switch|switch
condition|(
name|Opc
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Not a comparsion operator."
argument_list|)
expr_stmt|;
case|case
name|BO_LT
case|:
return|return
name|BO_GE
return|;
case|case
name|BO_GT
case|:
return|return
name|BO_LE
return|;
case|case
name|BO_LE
case|:
return|return
name|BO_GT
return|;
case|case
name|BO_GE
case|:
return|return
name|BO_LT
return|;
case|case
name|BO_EQ
case|:
return|return
name|BO_NE
return|;
case|case
name|BO_NE
case|:
return|return
name|BO_EQ
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|Opcode
name|reverseComparisonOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
switch|switch
condition|(
name|Opc
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Not a comparsion operator."
argument_list|)
expr_stmt|;
case|case
name|BO_LT
case|:
return|return
name|BO_GT
return|;
case|case
name|BO_GT
case|:
return|return
name|BO_LT
return|;
case|case
name|BO_LE
case|:
return|return
name|BO_GE
return|;
case|case
name|BO_GE
case|:
return|return
name|BO_LE
return|;
case|case
name|BO_EQ
case|:
case|case
name|BO_NE
case|:
return|return
name|Opc
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|bool
name|isLogicalOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|==
name|BO_LAnd
operator|||
name|Opc
operator|==
name|BO_LOr
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|isLogicalOp
argument_list|()
specifier|const
block|{
return|return
name|isLogicalOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|isAssignmentOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|>=
name|BO_Assign
operator|&&
name|Opc
operator|<=
name|BO_OrAssign
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|isAssignmentOp
argument_list|()
specifier|const
block|{
return|return
name|isAssignmentOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|isCompoundAssignmentOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|>
name|BO_Assign
operator|&&
name|Opc
operator|<=
name|BO_OrAssign
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|isCompoundAssignmentOp
argument_list|()
specifier|const
block|{
return|return
name|isCompoundAssignmentOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|Opcode
name|getOpForCompoundAssignment
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
name|assert
argument_list|(
name|isCompoundAssignmentOp
argument_list|(
name|Opc
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|Opc
operator|>=
name|BO_AndAssign
condition|)
return|return
name|Opcode
argument_list|(
name|unsigned
argument_list|(
name|Opc
argument_list|)
operator|-
name|BO_AndAssign
operator|+
name|BO_And
argument_list|)
return|;
else|else
return|return
name|Opcode
argument_list|(
name|unsigned
argument_list|(
name|Opc
argument_list|)
operator|-
name|BO_MulAssign
operator|+
name|BO_Mul
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isShiftAssignOp
parameter_list|(
name|Opcode
name|Opc
parameter_list|)
block|{
return|return
name|Opc
operator|==
name|BO_ShlAssign
operator|||
name|Opc
operator|==
name|BO_ShrAssign
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|isShiftAssignOp
argument_list|()
specifier|const
block|{
return|return
name|isShiftAssignOp
argument_list|(
name|getOpcode
argument_list|()
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
name|S
parameter_list|)
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
name|END_EXPR
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
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
name|END_EXPR
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Set the FP contractability status of this operator. Only meaningful for
end_comment

begin_comment
comment|// operations on floating point types.
end_comment

begin_function
name|void
name|setFPFeatures
parameter_list|(
name|FPOptions
name|F
parameter_list|)
block|{
name|FPFeatures
operator|=
name|F
operator|.
name|getInt
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|FPOptions
name|getFPFeatures
argument_list|()
specifier|const
block|{
return|return
name|FPOptions
argument_list|(
name|FPFeatures
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Get the FP contractability status of this operator. Only meaningful for
end_comment

begin_comment
comment|// operations on floating point types.
end_comment

begin_expr_stmt
name|bool
name|isFPContractableWithinStatement
argument_list|()
specifier|const
block|{
return|return
name|FPOptions
argument_list|(
name|FPFeatures
argument_list|)
operator|.
name|allowFPContractWithinStatement
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_macro
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
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|SourceLocation opLoc
argument_list|,
argument|FPOptions FPFeatures
argument_list|,
argument|bool dead2
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|Expr
argument_list|(
name|CompoundAssignOperatorClass
argument_list|,
name|ResTy
argument_list|,
name|VK
argument_list|,
name|OK
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
argument_list|,
operator|(
name|lhs
operator|->
name|isInstantiationDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
argument_list|,
operator|(
name|lhs
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|rhs
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
argument_list|)
operator|,
name|Opc
argument_list|(
name|opc
argument_list|)
operator|,
name|FPFeatures
argument_list|(
name|FPFeatures
operator|.
name|getInt
argument_list|()
argument_list|)
operator|,
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
operator|,
name|Opc
argument_list|(
argument|BO_MulAssign
argument_list|)
block|{ }
end_expr_stmt

begin_comment
unit|};
comment|/// CompoundAssignOperator - For compound assignments (e.g. +=), we keep
end_comment

begin_comment
comment|/// track of the type the operation is performed in.  Due to the semantics of
end_comment

begin_comment
comment|/// these operators, the operands are promoted, the arithmetic performed, an
end_comment

begin_comment
comment|/// implicit conversion back to the result type done, then the assignment takes
end_comment

begin_comment
comment|/// place.  This captures the intermediate type which the computation is done
end_comment

begin_comment
comment|/// in.
end_comment

begin_decl_stmt
name|class
name|CompoundAssignOperator
range|:
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
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|QualType CompLHSType
argument_list|,
argument|QualType CompResultType
argument_list|,
argument|SourceLocation OpLoc
argument_list|,
argument|FPOptions FPFeatures
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
name|VK
argument_list|,
name|OK
argument_list|,
name|OpLoc
argument_list|,
name|FPFeatures
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
comment|/// AbstractConditionalOperator - An abstract base class for
comment|/// ConditionalOperator and BinaryConditionalOperator.
name|class
name|AbstractConditionalOperator
operator|:
name|public
name|Expr
block|{
name|SourceLocation
name|QuestionLoc
block|,
name|ColonLoc
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|protected
operator|:
name|AbstractConditionalOperator
argument_list|(
argument|StmtClass SC
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|bool TD
argument_list|,
argument|bool VD
argument_list|,
argument|bool ID
argument_list|,
argument|bool ContainsUnexpandedParameterPack
argument_list|,
argument|SourceLocation qloc
argument_list|,
argument|SourceLocation cloc
argument_list|)
operator|:
name|Expr
argument_list|(
name|SC
argument_list|,
name|T
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
name|TD
argument_list|,
name|VD
argument_list|,
name|ID
argument_list|,
name|ContainsUnexpandedParameterPack
argument_list|)
block|,
name|QuestionLoc
argument_list|(
name|qloc
argument_list|)
block|,
name|ColonLoc
argument_list|(
argument|cloc
argument_list|)
block|{}
name|AbstractConditionalOperator
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
name|public
operator|:
comment|// getCond - Return the expression representing the condition for
comment|//   the ?: operator.
name|Expr
operator|*
name|getCond
argument_list|()
specifier|const
block|;
comment|// getTrueExpr - Return the subexpression representing the value of
comment|//   the expression if the condition evaluates to true.
name|Expr
operator|*
name|getTrueExpr
argument_list|()
specifier|const
block|;
comment|// getFalseExpr - Return the subexpression representing the value of
comment|//   the expression if the condition evaluates to false.  This is
comment|//   the same as getRHS.
name|Expr
operator|*
name|getFalseExpr
argument_list|()
specifier|const
block|;
name|SourceLocation
name|getQuestionLoc
argument_list|()
specifier|const
block|{
return|return
name|QuestionLoc
return|;
block|}
name|SourceLocation
name|getColonLoc
argument_list|()
specifier|const
block|{
return|return
name|ColonLoc
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
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|BinaryConditionalOperatorClass
return|;
block|}
expr|}
block|;
comment|/// ConditionalOperator - The ?: ternary operator.  The GNU "missing
comment|/// middle" extension is a BinaryConditionalOperator.
name|class
name|ConditionalOperator
operator|:
name|public
name|AbstractConditionalOperator
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
name|friend
name|class
name|ASTStmtReader
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
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|)
operator|:
name|AbstractConditionalOperator
argument_list|(
argument|ConditionalOperatorClass
argument_list|,
argument|t
argument_list|,
argument|VK
argument_list|,
argument|OK
argument_list|,
comment|// FIXME: the type of the conditional operator doesn't
comment|// depend on the type of the conditional, but the standard
comment|// seems to imply that it could. File a bug!
argument|(lhs->isTypeDependent() || rhs->isTypeDependent())
argument_list|,
argument|(cond->isValueDependent() || lhs->isValueDependent() ||             rhs->isValueDependent())
argument_list|,
argument|(cond->isInstantiationDependent() ||             lhs->isInstantiationDependent() ||             rhs->isInstantiationDependent())
argument_list|,
argument|(cond->containsUnexpandedParameterPack() ||             lhs->containsUnexpandedParameterPack() ||             rhs->containsUnexpandedParameterPack())
argument_list|,
argument|QLoc
argument_list|,
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
name|AbstractConditionalOperator
argument_list|(
argument|ConditionalOperatorClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|// getCond - Return the expression representing the condition for
comment|//   the ?: operator.
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
comment|// getTrueExpr - Return the subexpression representing the value of
comment|//   the expression if the condition evaluates to true.
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
operator|)
return|;
block|}
comment|// getFalseExpr - Return the subexpression representing the value of
comment|//   the expression if the condition evaluates to false.  This is
comment|//   the same as getRHS.
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getCond
argument_list|()
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
name|getRHS
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
name|ConditionalOperatorClass
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
name|END_EXPR
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
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
name|END_EXPR
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// BinaryConditionalOperator - The GNU extension to the conditional
comment|/// operator which allows the middle operand to be omitted.
comment|///
comment|/// This is a different expression kind on the assumption that almost
comment|/// every client ends up needing to know that these are different.
name|class
name|BinaryConditionalOperator
operator|:
name|public
name|AbstractConditionalOperator
block|{   enum
block|{
name|COMMON
block|,
name|COND
block|,
name|LHS
block|,
name|RHS
block|,
name|NUM_SUBEXPRS
block|}
block|;
comment|/// - the common condition/left-hand-side expression, which will be
comment|///   evaluated as the opaque value
comment|/// - the condition, expressed in terms of the opaque value
comment|/// - the left-hand-side, expressed in terms of the opaque value
comment|/// - the right-hand-side
name|Stmt
operator|*
name|SubExprs
index|[
name|NUM_SUBEXPRS
index|]
block|;
name|OpaqueValueExpr
operator|*
name|OpaqueValue
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
name|BinaryConditionalOperator
argument_list|(
argument|Expr *common
argument_list|,
argument|OpaqueValueExpr *opaqueValue
argument_list|,
argument|Expr *cond
argument_list|,
argument|Expr *lhs
argument_list|,
argument|Expr *rhs
argument_list|,
argument|SourceLocation qloc
argument_list|,
argument|SourceLocation cloc
argument_list|,
argument|QualType t
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|)
operator|:
name|AbstractConditionalOperator
argument_list|(
name|BinaryConditionalOperatorClass
argument_list|,
name|t
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
operator|(
name|common
operator|->
name|isTypeDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isTypeDependent
argument_list|()
operator|)
argument_list|,
operator|(
name|common
operator|->
name|isValueDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isValueDependent
argument_list|()
operator|)
argument_list|,
operator|(
name|common
operator|->
name|isInstantiationDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
argument_list|,
operator|(
name|common
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|rhs
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
argument_list|,
name|qloc
argument_list|,
name|cloc
argument_list|)
block|,
name|OpaqueValue
argument_list|(
argument|opaqueValue
argument_list|)
block|{
name|SubExprs
index|[
name|COMMON
index|]
operator|=
name|common
block|;
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
block|;
name|assert
argument_list|(
name|OpaqueValue
operator|->
name|getSourceExpr
argument_list|()
operator|==
name|common
operator|&&
literal|"Wrong opaque value"
argument_list|)
block|;   }
comment|/// \brief Build an empty conditional operator.
name|explicit
name|BinaryConditionalOperator
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|AbstractConditionalOperator
argument_list|(
argument|BinaryConditionalOperatorClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
comment|/// \brief getCommon - Return the common expression, written to the
comment|///   left of the condition.  The opaque value will be bound to the
comment|///   result of this expression.
name|Expr
operator|*
name|getCommon
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
name|COMMON
index|]
operator|)
return|;
block|}
comment|/// \brief getOpaqueValue - Return the opaque value placeholder.
name|OpaqueValueExpr
operator|*
name|getOpaqueValue
argument_list|()
specifier|const
block|{
return|return
name|OpaqueValue
return|;
block|}
comment|/// \brief getCond - Return the condition expression; this is defined
comment|///   in terms of the opaque value.
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
comment|/// \brief getTrueExpr - Return the subexpression which will be
comment|///   evaluated if the condition evaluates to true;  this is defined
comment|///   in terms of the opaque value.
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
operator|)
return|;
block|}
comment|/// \brief getFalseExpr - Return the subexpression which will be
comment|///   evaluated if the condnition evaluates to false; this is
comment|///   defined in terms of the opaque value.
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getCommon
argument_list|()
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
name|getFalseExpr
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
name|BinaryConditionalOperatorClass
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
name|SubExprs
argument_list|,
name|SubExprs
operator|+
name|NUM_SUBEXPRS
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|SubExprs
argument_list|,
name|SubExprs
operator|+
name|NUM_SUBEXPRS
argument_list|)
return|;
block|}
expr|}
block|;
specifier|inline
name|Expr
operator|*
name|AbstractConditionalOperator
operator|::
name|getCond
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|ConditionalOperator
modifier|*
name|co
init|=
name|dyn_cast
operator|<
name|ConditionalOperator
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|co
operator|->
name|getCond
argument_list|()
return|;
return|return
name|cast
operator|<
name|BinaryConditionalOperator
operator|>
operator|(
name|this
operator|)
operator|->
name|getCond
argument_list|()
return|;
block|}
specifier|inline
name|Expr
operator|*
name|AbstractConditionalOperator
operator|::
name|getTrueExpr
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|ConditionalOperator
modifier|*
name|co
init|=
name|dyn_cast
operator|<
name|ConditionalOperator
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|co
operator|->
name|getTrueExpr
argument_list|()
return|;
return|return
name|cast
operator|<
name|BinaryConditionalOperator
operator|>
operator|(
name|this
operator|)
operator|->
name|getTrueExpr
argument_list|()
return|;
block|}
specifier|inline
name|Expr
operator|*
name|AbstractConditionalOperator
operator|::
name|getFalseExpr
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|ConditionalOperator
modifier|*
name|co
init|=
name|dyn_cast
operator|<
name|ConditionalOperator
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|co
operator|->
name|getFalseExpr
argument_list|()
return|;
return|return
name|cast
operator|<
name|BinaryConditionalOperator
operator|>
operator|(
name|this
operator|)
operator|->
name|getFalseExpr
argument_list|()
return|;
block|}
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
name|LabelDecl
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
argument|LabelDecl *L
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|AmpAmpLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|LabelLoc
return|;
block|}
name|LabelDecl
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
argument|LabelDecl *L
argument_list|)
block|{
name|Label
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
name|AddrLabelExprClass
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
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// StmtExpr - This is the GNU Statement Expression extension: ({int X=4; X;}).
comment|/// The StmtExpr contains a single CompoundStmt node, which it evaluates and
comment|/// takes the value of the last subexpression.
comment|///
comment|/// A StmtExpr is always an r-value; values "returned" out of a
comment|/// StmtExpr will be copied.
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
comment|// FIXME: Do we need to compute instantiation instantiation-dependence for
comment|// statements? (ugh!)
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
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|T
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|false
argument_list|,
name|false
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|LParenLoc
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
comment|// Iterators
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
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
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
expr|}
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
name|public
operator|:
name|ShuffleVectorExpr
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|ArrayRef<Expr*> args
argument_list|,
argument|QualType Type
argument_list|,
argument|SourceLocation BLoc
argument_list|,
argument|SourceLocation RP
argument_list|)
block|;
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
argument|nullptr
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|BuiltinLoc
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
name|ShuffleVectorExprClass
return|;
block|}
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
comment|/// \brief Retrieve the array of expressions.
name|Expr
operator|*
operator|*
name|getSubExprs
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
operator|)
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
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Exprs
argument_list|)
block|;
name|llvm
operator|::
name|APSInt
name|getShuffleMaskIdx
argument_list|(
argument|const ASTContext&Ctx
argument_list|,
argument|unsigned N
argument_list|)
specifier|const
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
name|EvaluateKnownConstInt
argument_list|(
name|Ctx
argument_list|)
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
name|NumExprs
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
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
name|NumExprs
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// ConvertVectorExpr - Clang builtin function __builtin_convertvector
comment|/// This AST node provides support for converting a vector type to another
comment|/// vector type of the same arity.
name|class
name|ConvertVectorExpr
operator|:
name|public
name|Expr
block|{
name|private
operator|:
name|Stmt
operator|*
name|SrcExpr
block|;
name|TypeSourceInfo
operator|*
name|TInfo
block|;
name|SourceLocation
name|BuiltinLoc
block|,
name|RParenLoc
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
name|ConvertVectorExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ConvertVectorExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|public
operator|:
name|ConvertVectorExpr
argument_list|(
argument|Expr* SrcExpr
argument_list|,
argument|TypeSourceInfo *TI
argument_list|,
argument|QualType DstType
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|SourceLocation BuiltinLoc
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
operator|:
name|Expr
argument_list|(
name|ConvertVectorExprClass
argument_list|,
name|DstType
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
name|DstType
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|DstType
operator|->
name|isDependentType
argument_list|()
operator|||
name|SrcExpr
operator|->
name|isValueDependent
argument_list|()
argument_list|,
operator|(
name|DstType
operator|->
name|isInstantiationDependentType
argument_list|()
operator|||
name|SrcExpr
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
argument_list|,
operator|(
name|DstType
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|SrcExpr
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
argument_list|)
block|,
name|SrcExpr
argument_list|(
name|SrcExpr
argument_list|)
block|,
name|TInfo
argument_list|(
name|TI
argument_list|)
block|,
name|BuiltinLoc
argument_list|(
name|BuiltinLoc
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|RParenLoc
argument_list|)
block|{}
comment|/// getSrcExpr - Return the Expr to be converted.
name|Expr
operator|*
name|getSrcExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SrcExpr
operator|)
return|;
block|}
comment|/// getTypeSourceInfo - Return the destination type.
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
argument|TypeSourceInfo *ti
argument_list|)
block|{
name|TInfo
operator|=
name|ti
block|;   }
comment|/// getBuiltinLoc - Return the location of the __builtin_convertvector token.
name|SourceLocation
name|getBuiltinLoc
argument_list|()
specifier|const
block|{
return|return
name|BuiltinLoc
return|;
block|}
comment|/// getRParenLoc - Return the location of final right parenthesis.
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
name|BuiltinLoc
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
name|ConvertVectorExprClass
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
name|SrcExpr
argument_list|,
operator|&
name|SrcExpr
operator|+
literal|1
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
operator|&
name|SrcExpr
argument_list|,
operator|&
name|SrcExpr
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
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
name|bool
name|CondIsTrue
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
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|SourceLocation RP
argument_list|,
argument|bool condIsTrue
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
name|VK
argument_list|,
name|OK
argument_list|,
name|TypeDependent
argument_list|,
name|ValueDependent
argument_list|,
operator|(
name|cond
operator|->
name|isInstantiationDependent
argument_list|()
operator|||
name|lhs
operator|->
name|isInstantiationDependent
argument_list|()
operator|||
name|rhs
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
argument_list|,
operator|(
name|cond
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|lhs
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|rhs
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
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
name|CondIsTrue
argument_list|(
argument|condIsTrue
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
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isConditionDependent
argument_list|()
operator|&&
literal|"Dependent condition isn't true or false"
argument_list|)
block|;
return|return
name|CondIsTrue
return|;
block|}
name|void
name|setIsConditionTrue
argument_list|(
argument|bool isTrue
argument_list|)
block|{
name|CondIsTrue
operator|=
name|isTrue
block|; }
name|bool
name|isConditionDependent
argument_list|()
specifier|const
block|{
return|return
name|getCond
argument_list|()
operator|->
name|isTypeDependent
argument_list|()
operator|||
name|getCond
argument_list|()
operator|->
name|isValueDependent
argument_list|()
return|;
block|}
comment|/// getChosenSubExpr - Return the subexpression chosen according to the
comment|/// condition.
name|Expr
operator|*
name|getChosenSubExpr
argument_list|()
specifier|const
block|{
return|return
name|isConditionTrue
argument_list|()
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|BuiltinLoc
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
name|ChooseExprClass
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
name|END_EXPR
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
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
name|END_EXPR
argument_list|)
return|;
block|}
expr|}
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|TokenLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|TokenLoc
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
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// Represents a call to the builtin function \c __builtin_va_arg.
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
name|llvm
operator|::
name|PointerIntPair
operator|<
name|TypeSourceInfo
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|TInfo
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
argument|Expr *e
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|SourceLocation RPLoc
argument_list|,
argument|QualType t
argument_list|,
argument|bool IsMS
argument_list|)
operator|:
name|Expr
argument_list|(
name|VAArgExprClass
argument_list|,
name|t
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|t
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|false
argument_list|,
operator|(
name|TInfo
operator|->
name|getType
argument_list|()
operator|->
name|isInstantiationDependentType
argument_list|()
operator|||
name|e
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
argument_list|,
operator|(
name|TInfo
operator|->
name|getType
argument_list|()
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|e
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
argument_list|)
block|,
name|Val
argument_list|(
name|e
argument_list|)
block|,
name|TInfo
argument_list|(
name|TInfo
argument_list|,
name|IsMS
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
block|{}
comment|/// Create an empty __builtin_va_arg expression.
name|explicit
name|VAArgExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|VAArgExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|Val
argument_list|(
name|nullptr
argument_list|)
block|,
name|TInfo
argument_list|(
argument|nullptr
argument_list|,
argument|false
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
comment|/// Returns whether this is really a Win64 ABI va_arg expression.
name|bool
name|isMicrosoftABI
argument_list|()
specifier|const
block|{
return|return
name|TInfo
operator|.
name|getInt
argument_list|()
return|;
block|}
name|void
name|setIsMicrosoftABI
argument_list|(
argument|bool IsMS
argument_list|)
block|{
name|TInfo
operator|.
name|setInt
argument_list|(
name|IsMS
argument_list|)
block|; }
name|TypeSourceInfo
operator|*
name|getWrittenTypeInfo
argument_list|()
specifier|const
block|{
return|return
name|TInfo
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|void
name|setWrittenTypeInfo
argument_list|(
argument|TypeSourceInfo *TI
argument_list|)
block|{
name|TInfo
operator|.
name|setPointer
argument_list|(
name|TI
argument_list|)
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|BuiltinLoc
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
name|VAArgExprClass
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
name|Val
argument_list|,
operator|&
name|Val
operator|+
literal|1
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
operator|&
name|Val
argument_list|,
operator|&
name|Val
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
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
comment|/// After semantic analysis has completed, given an initializer list,
comment|/// method isSemanticForm() returns true if and only if this is the
comment|/// semantic form of the initializer list (note: the same AST node
comment|/// may at the same time be the syntactic form).
comment|/// Given the semantic form of the initializer list, one can retrieve
comment|/// the syntactic form of that initializer list (when different)
comment|/// using method getSyntacticForm(); the method returns null if applied
comment|/// to a initializer list which is already in syntactic form.
comment|/// Similarly, given the syntactic form (i.e., an initializer list such
comment|/// that isSemanticForm() returns false), one can retrieve the semantic
comment|/// form using method getSemanticForm().
comment|/// Since many initializer lists have the same syntactic and semantic forms,
comment|/// getSyntacticForm() may return NULL, indicating that the current
comment|/// semantic initializer list also serves as its syntactic form.
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
comment|/// The alternative form of the initializer list (if it exists).
comment|/// The int part of the pair stores whether this initializer list is
comment|/// in semantic form. If not null, the pointer points to:
comment|///   - the syntactic form, if this is in semantic form;
comment|///   - the semantic form, if this is in syntactic form.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|InitListExpr
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|AltForm
block|;
comment|/// \brief Either:
comment|///  If this initializer list initializes an array with more elements than
comment|///  there are initializers in the list, specifies an expression to be used
comment|///  for value initialization of the rest of the elements.
comment|/// Or
comment|///  If this initializer list initializes a union, specifies which
comment|///  field within the union will be initialized.
name|llvm
operator|::
name|PointerUnion
operator|<
name|Expr
operator|*
block|,
name|FieldDecl
operator|*
operator|>
name|ArrayFillerOrUnionFieldInit
block|;
name|public
operator|:
name|InitListExpr
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation lbraceloc
argument_list|,
argument|ArrayRef<Expr*> initExprs
argument_list|,
argument|SourceLocation rbraceloc
argument_list|)
block|;
comment|/// \brief Build an empty initializer list.
name|explicit
name|InitListExpr
argument_list|(
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
name|AltForm
argument_list|(
argument|nullptr
argument_list|,
argument|true
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
comment|/// \brief Retrieve the set of initializers.
name|Expr
operator|*
operator|*
name|getInits
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
name|InitExprs
operator|.
name|data
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Retrieve the set of initializers.
name|Expr
operator|*
specifier|const
operator|*
name|getInits
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
specifier|const
operator|*
operator|>
operator|(
name|InitExprs
operator|.
name|data
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|inits
argument_list|()
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getInits
argument_list|()
argument_list|,
name|getNumInits
argument_list|()
argument_list|)
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|inits
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getInits
argument_list|()
argument_list|,
name|getNumInits
argument_list|()
argument_list|)
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
block|;
if|if
condition|(
name|expr
condition|)
block|{
name|ExprBits
operator|.
name|TypeDependent
operator||=
name|expr
operator|->
name|isTypeDependent
argument_list|()
expr_stmt|;
name|ExprBits
operator|.
name|ValueDependent
operator||=
name|expr
operator|->
name|isValueDependent
argument_list|()
expr_stmt|;
name|ExprBits
operator|.
name|InstantiationDependent
operator||=
name|expr
operator|->
name|isInstantiationDependent
argument_list|()
expr_stmt|;
name|ExprBits
operator|.
name|ContainsUnexpandedParameterPack
operator||=
name|expr
operator|->
name|containsUnexpandedParameterPack
argument_list|()
expr_stmt|;
block|}
block|}
comment|/// \brief Reserve space for some number of initializers.
name|void
name|reserveInits
argument_list|(
argument|const ASTContext&C
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
argument|const ASTContext&Context
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
comment|/// accommodate the new entry.
name|Expr
operator|*
name|updateInit
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned Init
argument_list|,
argument|Expr *expr
argument_list|)
block|;
comment|/// \brief If this initializer list initializes an array with more elements
comment|/// than there are initializers in the list, specifies an expression to be
comment|/// used for value initialization of the rest of the elements.
name|Expr
operator|*
name|getArrayFiller
argument_list|()
block|{
return|return
name|ArrayFillerOrUnionFieldInit
operator|.
name|dyn_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArrayFiller
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|InitListExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getArrayFiller
argument_list|()
return|;
block|}
name|void
name|setArrayFiller
argument_list|(
name|Expr
operator|*
name|filler
argument_list|)
block|;
comment|/// \brief Return true if this is an array initializer and its array "filler"
comment|/// has been set.
name|bool
name|hasArrayFiller
argument_list|()
specifier|const
block|{
return|return
name|getArrayFiller
argument_list|()
return|;
block|}
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
name|ArrayFillerOrUnionFieldInit
operator|.
name|dyn_cast
operator|<
name|FieldDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|FieldDecl
operator|*
name|getInitializedFieldInUnion
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|InitListExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getInitializedFieldInUnion
argument_list|()
return|;
block|}
name|void
name|setInitializedFieldInUnion
argument_list|(
argument|FieldDecl *FD
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|FD
operator|==
name|nullptr
operator|||
name|getInitializedFieldInUnion
argument_list|()
operator|==
name|nullptr
operator|||
name|getInitializedFieldInUnion
argument_list|()
operator|==
name|FD
operator|)
operator|&&
literal|"Only one field of a union may be initialized at a time!"
argument_list|)
block|;
name|ArrayFillerOrUnionFieldInit
operator|=
name|FD
block|;   }
comment|// Explicit InitListExpr's originate from source code (and have valid source
comment|// locations). Implicit InitListExpr's are created by the semantic analyzer.
name|bool
name|isExplicit
argument_list|()
specifier|const
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
comment|// Is this an initializer for an array of characters, initialized by a string
comment|// literal or an @encode?
name|bool
name|isStringLiteralInit
argument_list|()
specifier|const
block|;
comment|/// Is this a transparent initializer list (that is, an InitListExpr that is
comment|/// purely syntactic, and whose semantics are that of the sole contained
comment|/// initializer)?
name|bool
name|isTransparent
argument_list|()
specifier|const
block|;
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
name|bool
name|isSemanticForm
argument_list|()
specifier|const
block|{
return|return
name|AltForm
operator|.
name|getInt
argument_list|()
return|;
block|}
name|InitListExpr
operator|*
name|getSemanticForm
argument_list|()
specifier|const
block|{
return|return
name|isSemanticForm
argument_list|()
operator|?
name|nullptr
operator|:
name|AltForm
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|InitListExpr
operator|*
name|getSyntacticForm
argument_list|()
specifier|const
block|{
return|return
name|isSemanticForm
argument_list|()
condition|?
name|AltForm
operator|.
name|getPointer
argument_list|()
else|:
name|nullptr
return|;
block|}
name|void
name|setSyntacticForm
argument_list|(
argument|InitListExpr *Init
argument_list|)
block|{
name|AltForm
operator|.
name|setPointer
argument_list|(
name|Init
argument_list|)
block|;
name|AltForm
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
block|;
name|Init
operator|->
name|AltForm
operator|.
name|setPointer
argument_list|(
name|this
argument_list|)
block|;
name|Init
operator|->
name|AltForm
operator|.
name|setInt
argument_list|(
name|false
argument_list|)
block|;   }
name|bool
name|hadArrayRangeDesignator
argument_list|()
specifier|const
block|{
return|return
name|InitListExprBits
operator|.
name|HadArrayRangeDesignator
operator|!=
literal|0
return|;
block|}
name|void
name|sawArrayRangeDesignator
argument_list|(
argument|bool ARD = true
argument_list|)
block|{
name|InitListExprBits
operator|.
name|HadArrayRangeDesignator
operator|=
name|ARD
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
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
name|const_child_range
name|CCR
operator|=
name|const_cast
operator|<
specifier|const
name|InitListExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|children
argument_list|()
block|;
return|return
name|child_range
argument_list|(
name|cast_away_const
argument_list|(
name|CCR
operator|.
name|begin
argument_list|()
argument_list|)
argument_list|,
name|cast_away_const
argument_list|(
name|CCR
operator|.
name|end
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
comment|// FIXME: This does not include the array filler expression.
if|if
condition|(
name|InitExprs
operator|.
name|empty
argument_list|()
condition|)
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
return|return
name|const_child_range
argument_list|(
operator|&
name|InitExprs
index|[
literal|0
index|]
argument_list|,
operator|&
name|InitExprs
index|[
literal|0
index|]
operator|+
name|InitExprs
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
typedef|typedef
name|InitExprsTy
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|InitExprsTy
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|InitExprsTy
operator|::
name|reverse_iterator
name|reverse_iterator
expr_stmt|;
typedef|typedef
name|InitExprsTy
operator|::
name|const_reverse_iterator
name|const_reverse_iterator
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
name|const_iterator
name|begin
argument_list|()
specifier|const
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
name|const_iterator
name|end
argument_list|()
specifier|const
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
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
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
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|InitExprs
operator|.
name|rend
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
comment|/// designator for @c .y. The initialization expression will be 1.0.
name|class
name|DesignatedInitExpr
name|final
operator|:
name|public
name|Expr
block|,
name|private
name|llvm
operator|::
name|TrailingObjects
operator|<
name|DesignatedInitExpr
block|,
name|Stmt
operator|*
operator|>
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
name|unsigned
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
comment|/// The number of subexpressions of this initializer expression,
comment|/// which contains both the initializer and any additional
comment|/// expressions used by array and array-range designators.
name|unsigned
name|NumSubExprs
operator|:
literal|16
block|;
comment|/// \brief The designators in this designated initialization
comment|/// expression.
name|Designator
operator|*
name|Designators
block|;
name|DesignatedInitExpr
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|QualType Ty
argument_list|,
argument|llvm::ArrayRef<Designator> Designators
argument_list|,
argument|SourceLocation EqualOrColonLoc
argument_list|,
argument|bool GNUSyntax
argument_list|,
argument|ArrayRef<Expr *> IndexExprs
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
name|NumSubExprs
argument_list|(
name|NumSubExprs
argument_list|)
block|,
name|Designators
argument_list|(
argument|nullptr
argument_list|)
block|{ }
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
specifier|const
block|;
name|FieldDecl
operator|*
name|getField
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
if|if
condition|(
name|Field
operator|.
name|NameOrField
operator|&
literal|0x01
condition|)
return|return
name|nullptr
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
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Kind
operator|==
name|FieldDesignator
condition|?
name|getFieldLoc
argument_list|()
else|:
name|getRBracketLoc
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
expr|}
block|;
specifier|static
name|DesignatedInitExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|llvm::ArrayRef<Designator> Designators
argument_list|,
argument|ArrayRef<Expr*> IndexExprs
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
argument|const ASTContext&C
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
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|Designator
operator|>
name|designators
argument_list|()
block|{
return|return
block|{
name|Designators
block|,
name|NumDesignators
block|}
return|;
block|}
name|llvm
operator|::
name|ArrayRef
operator|<
name|Designator
operator|>
name|designators
argument_list|()
specifier|const
block|{
return|return
block|{
name|Designators
block|,
name|NumDesignators
block|}
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
name|designators
argument_list|()
index|[
name|Idx
index|]
return|;
block|}
name|void
name|setDesignators
argument_list|(
argument|const ASTContext&C
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
argument|const Designator&D
argument_list|)
specifier|const
block|;
name|Expr
operator|*
name|getArrayRangeStart
argument_list|(
argument|const Designator&D
argument_list|)
specifier|const
block|;
name|Expr
operator|*
name|getArrayRangeEnd
argument_list|(
argument|const Designator&D
argument_list|)
specifier|const
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
specifier|const
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
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|getTrailingObjects
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
index|[
name|Idx
index|]
operator|)
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
name|getTrailingObjects
operator|<
name|Stmt
operator|*
operator|>
operator|(
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
argument|const ASTContext&C
argument_list|,
argument|unsigned Idx
argument_list|,
argument|const Designator *First
argument_list|,
argument|const Designator *Last
argument_list|)
block|;
name|SourceRange
name|getDesignatorsSourceRange
argument_list|()
specifier|const
block|;
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
name|DesignatedInitExprClass
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
name|getTrailingObjects
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
block|;
return|return
name|child_range
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
name|NumSubExprs
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
name|Stmt
operator|*
specifier|const
operator|*
name|begin
operator|=
name|getTrailingObjects
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
block|;
return|return
name|const_child_range
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
name|NumSubExprs
argument_list|)
return|;
block|}
name|friend
name|TrailingObjects
block|; }
block|;
comment|/// \brief Represents a place-holder for an object not to be initialized by
comment|/// anything.
comment|///
comment|/// This only makes sense when it appears as part of an updater of a
comment|/// DesignatedInitUpdateExpr (see below). The base expression of a DIUE
comment|/// initializes a big object, and the NoInitExpr's mark the spots within the
comment|/// big object not to be overwritten by the updater.
comment|///
comment|/// \see DesignatedInitUpdateExpr
name|class
name|NoInitExpr
operator|:
name|public
name|Expr
block|{
name|public
operator|:
name|explicit
name|NoInitExpr
argument_list|(
argument|QualType ty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|NoInitExprClass
argument_list|,
argument|ty
argument_list|,
argument|VK_RValue
argument_list|,
argument|OK_Ordinary
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|,
argument|ty->isInstantiationDependentType()
argument_list|,
argument|false
argument_list|)
block|{ }
name|explicit
name|NoInitExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|NoInitExprClass
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
name|NoInitExprClass
return|;
block|}
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
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|// In cases like:
comment|//   struct Q { int a, b, c; };
comment|//   Q *getQ();
comment|//   void foo() {
comment|//     struct A { Q q; } a = { *getQ(), .q.b = 3 };
comment|//   }
comment|//
comment|// We will have an InitListExpr for a, with type A, and then a
comment|// DesignatedInitUpdateExpr for "a.q" with type Q. The "base" for this DIUE
comment|// is the call expression *getQ(); the "updater" for the DIUE is ".q.b = 3"
comment|//
name|class
name|DesignatedInitUpdateExpr
operator|:
name|public
name|Expr
block|{
comment|// BaseAndUpdaterExprs[0] is the base expression;
comment|// BaseAndUpdaterExprs[1] is an InitListExpr overwriting part of the base.
name|Stmt
operator|*
name|BaseAndUpdaterExprs
index|[
literal|2
index|]
block|;
name|public
operator|:
name|DesignatedInitUpdateExpr
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation lBraceLoc
argument_list|,
argument|Expr *baseExprs
argument_list|,
argument|SourceLocation rBraceLoc
argument_list|)
block|;
name|explicit
name|DesignatedInitUpdateExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|DesignatedInitUpdateExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
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
name|DesignatedInitUpdateExprClass
return|;
block|}
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
name|BaseAndUpdaterExprs
index|[
literal|0
index|]
operator|)
return|;
block|}
name|void
name|setBase
argument_list|(
argument|Expr *Base
argument_list|)
block|{
name|BaseAndUpdaterExprs
index|[
literal|0
index|]
operator|=
name|Base
block|; }
name|InitListExpr
operator|*
name|getUpdater
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|InitListExpr
operator|>
operator|(
name|BaseAndUpdaterExprs
index|[
literal|1
index|]
operator|)
return|;
block|}
name|void
name|setUpdater
argument_list|(
argument|Expr *Updater
argument_list|)
block|{
name|BaseAndUpdaterExprs
index|[
literal|1
index|]
operator|=
name|Updater
block|; }
comment|// Iterators
comment|// children = the base and the updater
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|&
name|BaseAndUpdaterExprs
index|[
literal|0
index|]
argument_list|,
operator|&
name|BaseAndUpdaterExprs
index|[
literal|0
index|]
operator|+
literal|2
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
operator|&
name|BaseAndUpdaterExprs
index|[
literal|0
index|]
argument_list|,
operator|&
name|BaseAndUpdaterExprs
index|[
literal|0
index|]
operator|+
literal|2
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a loop initializing the elements of an array.
comment|///
comment|/// The need to initialize the elements of an array occurs in a number of
comment|/// contexts:
comment|///
comment|///  * in the implicit copy/move constructor for a class with an array member
comment|///  * when a lambda-expression captures an array by value
comment|///  * when a decomposition declaration decomposes an array
comment|///
comment|/// There are two subexpressions: a common expression (the source array)
comment|/// that is evaluated once up-front, and a per-element initializer that
comment|/// runs once for each array element.
comment|///
comment|/// Within the per-element initializer, the common expression may be referenced
comment|/// via an OpaqueValueExpr, and the current index may be obtained via an
comment|/// ArrayInitIndexExpr.
name|class
name|ArrayInitLoopExpr
operator|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|SubExprs
index|[
literal|2
index|]
block|;
name|explicit
name|ArrayInitLoopExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|ArrayInitLoopExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|SubExprs
block|{}
block|{}
name|public
operator|:
name|explicit
name|ArrayInitLoopExpr
argument_list|(
argument|QualType T
argument_list|,
argument|Expr *CommonInit
argument_list|,
argument|Expr *ElementInit
argument_list|)
operator|:
name|Expr
argument_list|(
name|ArrayInitLoopExprClass
argument_list|,
name|T
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|CommonInit
operator|->
name|isValueDependent
argument_list|()
operator|||
name|ElementInit
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|T
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|CommonInit
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|ElementInit
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|SubExprs
block|{
name|CommonInit
block|,
name|ElementInit
block|}
block|{}
comment|/// Get the common subexpression shared by all initializations (the source
comment|/// array).
name|OpaqueValueExpr
operator|*
name|getCommonExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|OpaqueValueExpr
operator|>
operator|(
name|SubExprs
index|[
literal|0
index|]
operator|)
return|;
block|}
comment|/// Get the initializer to use for each array element.
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
name|SubExprs
index|[
literal|1
index|]
operator|)
return|;
block|}
name|llvm
operator|::
name|APInt
name|getArraySize
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|ConstantArrayType
operator|>
operator|(
name|getType
argument_list|()
operator|->
name|castAsArrayTypeUnsafe
argument_list|()
operator|)
operator|->
name|getSize
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
name|ArrayInitLoopExprClass
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getCommonExpr
argument_list|()
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
name|getCommonExpr
argument_list|()
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
name|SubExprs
argument_list|,
name|SubExprs
operator|+
literal|2
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|SubExprs
argument_list|,
name|SubExprs
operator|+
literal|2
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
block|;
name|friend
name|class
name|ASTStmtWriter
block|; }
block|;
comment|/// \brief Represents the index of the current element of an array being
comment|/// initialized by an ArrayInitLoopExpr. This can only appear within the
comment|/// subexpression of an ArrayInitLoopExpr.
name|class
name|ArrayInitIndexExpr
operator|:
name|public
name|Expr
block|{
name|explicit
name|ArrayInitIndexExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ArrayInitIndexExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|public
operator|:
name|explicit
name|ArrayInitIndexExpr
argument_list|(
argument|QualType T
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ArrayInitIndexExprClass
argument_list|,
argument|T
argument_list|,
argument|VK_RValue
argument_list|,
argument|OK_Ordinary
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|)
block|{}
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
name|ArrayInitIndexExprClass
return|;
block|}
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
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
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
argument|VK_RValue
argument_list|,
argument|OK_Ordinary
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|,
argument|ty->isInstantiationDependentType()
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
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
expr|}
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
name|public
operator|:
name|ParenListExpr
argument_list|(
argument|const ASTContext& C
argument_list|,
argument|SourceLocation lparenloc
argument_list|,
argument|ArrayRef<Expr*> exprs
argument_list|,
argument|SourceLocation rparenloc
argument_list|)
block|;
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
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|exprs
argument_list|()
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getExprs
argument_list|()
argument_list|,
name|getNumExprs
argument_list|()
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
name|LParenLoc
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
name|ParenListExprClass
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
name|Exprs
index|[
literal|0
index|]
argument_list|,
operator|&
name|Exprs
index|[
literal|0
index|]
operator|+
name|NumExprs
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
operator|&
name|Exprs
index|[
literal|0
index|]
argument_list|,
operator|&
name|Exprs
index|[
literal|0
index|]
operator|+
name|NumExprs
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
comment|/// \brief Represents a C11 generic selection.
comment|///
comment|/// A generic selection (C11 6.5.1.1) contains an unevaluated controlling
comment|/// expression, followed by one or more generic associations.  Each generic
comment|/// association specifies a type name and an expression, or "default" and an
comment|/// expression (in which case it is known as a default generic association).
comment|/// The type and value of the generic selection are identical to those of its
comment|/// result expression, which is defined as the expression in the generic
comment|/// association with a type name that is compatible with the type of the
comment|/// controlling expression, or the expression in the default generic association
comment|/// if no types are compatible.  For example:
comment|///
comment|/// @code
comment|/// _Generic(X, double: 1, float: 2, default: 3)
comment|/// @endcode
comment|///
comment|/// The above expression evaluates to 1 if 1.0 is substituted for X, 2 if 1.0f
comment|/// or 3 if "hello".
comment|///
comment|/// As an extension, generic selections are allowed in C++, where the following
comment|/// additional semantics apply:
comment|///
comment|/// Any generic selection whose controlling expression is type-dependent or
comment|/// which names a dependent type in its association list is result-dependent,
comment|/// which means that the choice of result expression is dependent.
comment|/// Result-dependent generic associations are both type- and value-dependent.
name|class
name|GenericSelectionExpr
operator|:
name|public
name|Expr
block|{   enum
block|{
name|CONTROLLING
block|,
name|END_EXPR
block|}
block|;
name|TypeSourceInfo
operator|*
operator|*
name|AssocTypes
block|;
name|Stmt
operator|*
operator|*
name|SubExprs
block|;
name|unsigned
name|NumAssocs
block|,
name|ResultIndex
block|;
name|SourceLocation
name|GenericLoc
block|,
name|DefaultLoc
block|,
name|RParenLoc
block|;
name|public
operator|:
name|GenericSelectionExpr
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|SourceLocation GenericLoc
argument_list|,
argument|Expr *ControllingExpr
argument_list|,
argument|ArrayRef<TypeSourceInfo*> AssocTypes
argument_list|,
argument|ArrayRef<Expr*> AssocExprs
argument_list|,
argument|SourceLocation DefaultLoc
argument_list|,
argument|SourceLocation RParenLoc
argument_list|,
argument|bool ContainsUnexpandedParameterPack
argument_list|,
argument|unsigned ResultIndex
argument_list|)
block|;
comment|/// This constructor is used in the result-dependent case.
name|GenericSelectionExpr
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|SourceLocation GenericLoc
argument_list|,
argument|Expr *ControllingExpr
argument_list|,
argument|ArrayRef<TypeSourceInfo*> AssocTypes
argument_list|,
argument|ArrayRef<Expr*> AssocExprs
argument_list|,
argument|SourceLocation DefaultLoc
argument_list|,
argument|SourceLocation RParenLoc
argument_list|,
argument|bool ContainsUnexpandedParameterPack
argument_list|)
block|;
name|explicit
name|GenericSelectionExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|GenericSelectionExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|unsigned
name|getNumAssocs
argument_list|()
specifier|const
block|{
return|return
name|NumAssocs
return|;
block|}
name|SourceLocation
name|getGenericLoc
argument_list|()
specifier|const
block|{
return|return
name|GenericLoc
return|;
block|}
name|SourceLocation
name|getDefaultLoc
argument_list|()
specifier|const
block|{
return|return
name|DefaultLoc
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
specifier|const
name|Expr
operator|*
name|getAssocExpr
argument_list|(
argument|unsigned i
argument_list|)
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
name|END_EXPR
operator|+
name|i
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getAssocExpr
argument_list|(
argument|unsigned i
argument_list|)
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|END_EXPR
operator|+
name|i
index|]
operator|)
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getAssocExprs
argument_list|()
specifier|const
block|{
return|return
name|NumAssocs
condition|?
name|llvm
operator|::
name|makeArrayRef
argument_list|(
operator|&
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|SubExprs
operator|)
index|[
name|END_EXPR
index|]
argument_list|,
name|NumAssocs
argument_list|)
else|:
name|None
return|;
block|}
specifier|const
name|TypeSourceInfo
operator|*
name|getAssocTypeSourceInfo
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|AssocTypes
index|[
name|i
index|]
return|;
block|}
name|TypeSourceInfo
operator|*
name|getAssocTypeSourceInfo
argument_list|(
argument|unsigned i
argument_list|)
block|{
return|return
name|AssocTypes
index|[
name|i
index|]
return|;
block|}
name|ArrayRef
operator|<
name|TypeSourceInfo
operator|*
operator|>
name|getAssocTypeSourceInfos
argument_list|()
specifier|const
block|{
return|return
name|NumAssocs
condition|?
name|llvm
operator|::
name|makeArrayRef
argument_list|(
operator|&
name|AssocTypes
index|[
literal|0
index|]
argument_list|,
name|NumAssocs
argument_list|)
else|:
name|None
return|;
block|}
name|QualType
name|getAssocType
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
if|if
condition|(
specifier|const
name|TypeSourceInfo
modifier|*
name|TS
init|=
name|getAssocTypeSourceInfo
argument_list|(
name|i
argument_list|)
condition|)
return|return
name|TS
operator|->
name|getType
argument_list|()
return|;
else|else
return|return
name|QualType
argument_list|()
return|;
block|}
specifier|const
name|Expr
operator|*
name|getControllingExpr
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
name|CONTROLLING
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getControllingExpr
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
name|CONTROLLING
index|]
operator|)
return|;
block|}
comment|/// Whether this generic selection is result-dependent.
name|bool
name|isResultDependent
argument_list|()
specifier|const
block|{
return|return
name|ResultIndex
operator|==
operator|-
literal|1U
return|;
block|}
comment|/// The zero-based index of the result expression's generic association in
comment|/// the generic selection's association list.  Defined only if the
comment|/// generic selection is not result-dependent.
name|unsigned
name|getResultIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isResultDependent
argument_list|()
operator|&&
literal|"Generic selection is result-dependent"
argument_list|)
block|;
return|return
name|ResultIndex
return|;
block|}
comment|/// The generic selection's result expression.  Defined only if the
comment|/// generic selection is not result-dependent.
specifier|const
name|Expr
operator|*
name|getResultExpr
argument_list|()
specifier|const
block|{
return|return
name|getAssocExpr
argument_list|(
name|getResultIndex
argument_list|()
argument_list|)
return|;
block|}
name|Expr
operator|*
name|getResultExpr
argument_list|()
block|{
return|return
name|getAssocExpr
argument_list|(
name|getResultIndex
argument_list|()
argument_list|)
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|GenericLoc
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
name|GenericSelectionExprClass
return|;
block|}
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|SubExprs
argument_list|,
name|SubExprs
operator|+
name|END_EXPR
operator|+
name|NumAssocs
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|SubExprs
argument_list|,
name|SubExprs
operator|+
name|END_EXPR
operator|+
name|NumAssocs
argument_list|)
return|;
block|}
name|friend
name|class
name|ASTStmtReader
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
argument|ExprValueKind VK
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
name|VK
argument_list|,
operator|(
name|VK
operator|==
name|VK_RValue
condition|?
name|OK_Ordinary
else|:
name|OK_VectorComponent
operator|)
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
argument_list|,
name|base
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|base
operator|->
name|containsUnexpandedParameterPack
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
argument|SmallVectorImpl<uint32_t>&Elts
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
name|getBase
argument_list|()
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
name|AccessorLoc
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
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
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
name|public
operator|:
name|BlockExpr
argument_list|(
argument|BlockDecl *BD
argument_list|,
argument|QualType ty
argument_list|)
operator|:
name|Expr
argument_list|(
name|BlockExprClass
argument_list|,
name|ty
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|ty
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|ty
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|ty
operator|->
name|isInstantiationDependentType
argument_list|()
operator|||
name|BD
operator|->
name|isDependentContext
argument_list|()
argument_list|,
name|false
argument_list|)
block|,
name|TheBlock
argument_list|(
argument|BD
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getCaretLocation
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
name|getBody
argument_list|()
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
comment|/// getFunctionType - Return the underlying function type for this block.
specifier|const
name|FunctionProtoType
operator|*
name|getFunctionType
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
name|BlockExprClass
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
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// AsTypeExpr - Clang builtin function __builtin_astype [OpenCL 6.2.4.2]
comment|/// This AST node provides support for reinterpreting a type to another
comment|/// type of the same size.
name|class
name|AsTypeExpr
operator|:
name|public
name|Expr
block|{
name|private
operator|:
name|Stmt
operator|*
name|SrcExpr
block|;
name|SourceLocation
name|BuiltinLoc
block|,
name|RParenLoc
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
name|AsTypeExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|AsTypeExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|public
operator|:
name|AsTypeExpr
argument_list|(
argument|Expr* SrcExpr
argument_list|,
argument|QualType DstType
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|SourceLocation BuiltinLoc
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
operator|:
name|Expr
argument_list|(
name|AsTypeExprClass
argument_list|,
name|DstType
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
name|DstType
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|DstType
operator|->
name|isDependentType
argument_list|()
operator|||
name|SrcExpr
operator|->
name|isValueDependent
argument_list|()
argument_list|,
operator|(
name|DstType
operator|->
name|isInstantiationDependentType
argument_list|()
operator|||
name|SrcExpr
operator|->
name|isInstantiationDependent
argument_list|()
operator|)
argument_list|,
operator|(
name|DstType
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|SrcExpr
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
argument_list|)
block|,
name|SrcExpr
argument_list|(
name|SrcExpr
argument_list|)
block|,
name|BuiltinLoc
argument_list|(
name|BuiltinLoc
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|RParenLoc
argument_list|)
block|{}
comment|/// getSrcExpr - Return the Expr to be converted.
name|Expr
operator|*
name|getSrcExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SrcExpr
operator|)
return|;
block|}
comment|/// getBuiltinLoc - Return the location of the __builtin_astype token.
name|SourceLocation
name|getBuiltinLoc
argument_list|()
specifier|const
block|{
return|return
name|BuiltinLoc
return|;
block|}
comment|/// getRParenLoc - Return the location of final right parenthesis.
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
name|BuiltinLoc
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
name|AsTypeExprClass
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
name|SrcExpr
argument_list|,
operator|&
name|SrcExpr
operator|+
literal|1
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
operator|&
name|SrcExpr
argument_list|,
operator|&
name|SrcExpr
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// PseudoObjectExpr - An expression which accesses a pseudo-object
comment|/// l-value.  A pseudo-object is an abstract object, accesses to which
comment|/// are translated to calls.  The pseudo-object expression has a
comment|/// syntactic form, which shows how the expression was actually
comment|/// written in the source code, and a semantic form, which is a series
comment|/// of expressions to be executed in order which detail how the
comment|/// operation is actually evaluated.  Optionally, one of the semantic
comment|/// forms may also provide a result value for the expression.
comment|///
comment|/// If any of the semantic-form expressions is an OpaqueValueExpr,
comment|/// that OVE is required to have a source expression, and it is bound
comment|/// to the result of that source expression.  Such OVEs may appear
comment|/// only in subsequent semantic-form expressions and as
comment|/// sub-expressions of the syntactic form.
comment|///
comment|/// PseudoObjectExpr should be used only when an operation can be
comment|/// usefully described in terms of fairly simple rewrite rules on
comment|/// objects and functions that are meant to be used by end-developers.
comment|/// For example, under the Itanium ABI, dynamic casts are implemented
comment|/// as a call to a runtime function called __dynamic_cast; using this
comment|/// class to describe that would be inappropriate because that call is
comment|/// not really part of the user-visible semantics, and instead the
comment|/// cast is properly reflected in the AST and IR-generation has been
comment|/// taught to generate the call as necessary.  In contrast, an
comment|/// Objective-C property access is semantically defined to be
comment|/// equivalent to a particular message send, and this is very much
comment|/// part of the user model.  The name of this class encourages this
comment|/// modelling design.
name|class
name|PseudoObjectExpr
name|final
operator|:
name|public
name|Expr
block|,
name|private
name|llvm
operator|::
name|TrailingObjects
operator|<
name|PseudoObjectExpr
block|,
name|Expr
operator|*
operator|>
block|{
comment|// PseudoObjectExprBits.NumSubExprs - The number of sub-expressions.
comment|// Always at least two, because the first sub-expression is the
comment|// syntactic form.
comment|// PseudoObjectExprBits.ResultIndex - The index of the
comment|// sub-expression holding the result.  0 means the result is void,
comment|// which is unambiguous because it's the index of the syntactic
comment|// form.  Note that this is therefore 1 higher than the value passed
comment|// in to Create, which is an index within the semantic forms.
comment|// Note also that ASTStmtWriter assumes this encoding.
name|Expr
operator|*
operator|*
name|getSubExprsBuffer
argument_list|()
block|{
return|return
name|getTrailingObjects
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
specifier|const
operator|*
name|getSubExprsBuffer
argument_list|()
specifier|const
block|{
return|return
name|getTrailingObjects
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|PseudoObjectExpr
argument_list|(
argument|QualType type
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|Expr *syntactic
argument_list|,
argument|ArrayRef<Expr*> semantic
argument_list|,
argument|unsigned resultIndex
argument_list|)
block|;
name|PseudoObjectExpr
argument_list|(
argument|EmptyShell shell
argument_list|,
argument|unsigned numSemanticExprs
argument_list|)
block|;
name|unsigned
name|getNumSubExprs
argument_list|()
specifier|const
block|{
return|return
name|PseudoObjectExprBits
operator|.
name|NumSubExprs
return|;
block|}
name|public
operator|:
comment|/// NoResult - A value for the result index indicating that there is
comment|/// no semantic result.
expr|enum
operator|:
name|unsigned
block|{
name|NoResult
operator|=
operator|~
literal|0U
block|}
block|;
specifier|static
name|PseudoObjectExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|Expr *syntactic
argument_list|,
argument|ArrayRef<Expr*> semantic
argument_list|,
argument|unsigned resultIndex
argument_list|)
block|;
specifier|static
name|PseudoObjectExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|EmptyShell shell
argument_list|,
argument|unsigned numSemanticExprs
argument_list|)
block|;
comment|/// Return the syntactic form of this expression, i.e. the
comment|/// expression it actually looks like.  Likely to be expressed in
comment|/// terms of OpaqueValueExprs bound in the semantic form.
name|Expr
operator|*
name|getSyntacticForm
argument_list|()
block|{
return|return
name|getSubExprsBuffer
argument_list|()
index|[
literal|0
index|]
return|;
block|}
specifier|const
name|Expr
operator|*
name|getSyntacticForm
argument_list|()
specifier|const
block|{
return|return
name|getSubExprsBuffer
argument_list|()
index|[
literal|0
index|]
return|;
block|}
comment|/// Return the index of the result-bearing expression into the semantics
comment|/// expressions, or PseudoObjectExpr::NoResult if there is none.
name|unsigned
name|getResultExprIndex
argument_list|()
specifier|const
block|{
if|if
condition|(
name|PseudoObjectExprBits
operator|.
name|ResultIndex
operator|==
literal|0
condition|)
return|return
name|NoResult
return|;
return|return
name|PseudoObjectExprBits
operator|.
name|ResultIndex
operator|-
literal|1
return|;
block|}
comment|/// Return the result-bearing expression, or null if there is none.
name|Expr
operator|*
name|getResultExpr
argument_list|()
block|{
if|if
condition|(
name|PseudoObjectExprBits
operator|.
name|ResultIndex
operator|==
literal|0
condition|)
return|return
name|nullptr
return|;
return|return
name|getSubExprsBuffer
argument_list|()
index|[
name|PseudoObjectExprBits
operator|.
name|ResultIndex
index|]
return|;
block|}
specifier|const
name|Expr
operator|*
name|getResultExpr
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|PseudoObjectExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getResultExpr
argument_list|()
return|;
block|}
name|unsigned
name|getNumSemanticExprs
argument_list|()
specifier|const
block|{
return|return
name|getNumSubExprs
argument_list|()
operator|-
literal|1
return|;
block|}
typedef|typedef
name|Expr
modifier|*
specifier|const
modifier|*
name|semantics_iterator
typedef|;
typedef|typedef
specifier|const
name|Expr
modifier|*
specifier|const
modifier|*
name|const_semantics_iterator
typedef|;
name|semantics_iterator
name|semantics_begin
argument_list|()
block|{
return|return
name|getSubExprsBuffer
argument_list|()
operator|+
literal|1
return|;
block|}
name|const_semantics_iterator
name|semantics_begin
argument_list|()
specifier|const
block|{
return|return
name|getSubExprsBuffer
argument_list|()
operator|+
literal|1
return|;
block|}
name|semantics_iterator
name|semantics_end
argument_list|()
block|{
return|return
name|getSubExprsBuffer
argument_list|()
operator|+
name|getNumSubExprs
argument_list|()
return|;
block|}
name|const_semantics_iterator
name|semantics_end
argument_list|()
specifier|const
block|{
return|return
name|getSubExprsBuffer
argument_list|()
operator|+
name|getNumSubExprs
argument_list|()
return|;
block|}
name|llvm
operator|::
name|iterator_range
operator|<
name|semantics_iterator
operator|>
name|semantics
argument_list|()
block|{
return|return
name|llvm
operator|::
name|make_range
argument_list|(
name|semantics_begin
argument_list|()
argument_list|,
name|semantics_end
argument_list|()
argument_list|)
return|;
block|}
name|llvm
operator|::
name|iterator_range
operator|<
name|const_semantics_iterator
operator|>
name|semantics
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|make_range
argument_list|(
name|semantics_begin
argument_list|()
argument_list|,
name|semantics_end
argument_list|()
argument_list|)
return|;
block|}
name|Expr
operator|*
name|getSemanticExpr
argument_list|(
argument|unsigned index
argument_list|)
block|{
name|assert
argument_list|(
name|index
operator|+
literal|1
operator|<
name|getNumSubExprs
argument_list|()
argument_list|)
block|;
return|return
name|getSubExprsBuffer
argument_list|()
index|[
name|index
operator|+
literal|1
index|]
return|;
block|}
specifier|const
name|Expr
operator|*
name|getSemanticExpr
argument_list|(
argument|unsigned index
argument_list|)
specifier|const
block|{
return|return
name|const_cast
operator|<
name|PseudoObjectExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getSemanticExpr
argument_list|(
name|index
argument_list|)
return|;
block|}
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getSyntacticForm
argument_list|()
operator|->
name|getExprLoc
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
name|getSyntacticForm
argument_list|()
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
name|getSyntacticForm
argument_list|()
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
name|child_range
name|children
argument_list|()
block|{
name|const_child_range
name|CCR
operator|=
name|const_cast
operator|<
specifier|const
name|PseudoObjectExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|children
argument_list|()
block|;
return|return
name|child_range
argument_list|(
name|cast_away_const
argument_list|(
name|CCR
operator|.
name|begin
argument_list|()
argument_list|)
argument_list|,
name|cast_away_const
argument_list|(
name|CCR
operator|.
name|end
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
name|Stmt
operator|*
specifier|const
operator|*
name|cs
operator|=
name|const_cast
operator|<
name|Stmt
operator|*
specifier|const
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Stmt
operator|*
specifier|const
operator|*
operator|>
operator|(
name|getSubExprsBuffer
argument_list|()
operator|)
operator|)
block|;
return|return
name|const_child_range
argument_list|(
name|cs
argument_list|,
name|cs
operator|+
name|getNumSubExprs
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
name|PseudoObjectExprClass
return|;
block|}
name|friend
name|TrailingObjects
block|;
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// AtomicExpr - Variadic atomic builtins: __atomic_exchange, __atomic_fetch_*,
comment|/// __atomic_load, __atomic_store, and __atomic_compare_exchange_*, for the
comment|/// similarly-named C++11 instructions, and __c11 variants for<stdatomic.h>.
comment|/// All of these instructions take one primary pointer and at least one memory
comment|/// order.
name|class
name|AtomicExpr
operator|:
name|public
name|Expr
block|{
name|public
operator|:
expr|enum
name|AtomicOp
block|{
define|#
directive|define
name|BUILTIN
parameter_list|(
name|ID
parameter_list|,
name|TYPE
parameter_list|,
name|ATTRS
parameter_list|)
define|#
directive|define
name|ATOMIC_BUILTIN
parameter_list|(
name|ID
parameter_list|,
name|TYPE
parameter_list|,
name|ATTRS
parameter_list|)
value|AO ## ID,
include|#
directive|include
file|"clang/Basic/Builtins.def"
comment|// Avoid trailing comma
name|BI_First
operator|=
literal|0
block|}
block|;
name|private
operator|:
expr|enum
block|{
name|PTR
block|,
name|ORDER
block|,
name|VAL1
block|,
name|ORDER_FAIL
block|,
name|VAL2
block|,
name|WEAK
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
name|unsigned
name|NumSubExprs
block|;
name|SourceLocation
name|BuiltinLoc
block|,
name|RParenLoc
block|;
name|AtomicOp
name|Op
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|public
operator|:
name|AtomicExpr
argument_list|(
argument|SourceLocation BLoc
argument_list|,
argument|ArrayRef<Expr*> args
argument_list|,
argument|QualType t
argument_list|,
argument|AtomicOp op
argument_list|,
argument|SourceLocation RP
argument_list|)
block|;
comment|/// \brief Determine the number of arguments the specified atomic builtin
comment|/// should have.
specifier|static
name|unsigned
name|getNumSubExprs
argument_list|(
argument|AtomicOp Op
argument_list|)
block|;
comment|/// \brief Build an empty AtomicExpr.
name|explicit
name|AtomicExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|AtomicExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|Expr
operator|*
name|getPtr
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
name|PTR
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getOrder
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
name|ORDER
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getVal1
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Op
operator|==
name|AO__c11_atomic_init
condition|)
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|ORDER
index|]
operator|)
return|;
name|assert
argument_list|(
name|NumSubExprs
operator|>
name|VAL1
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
name|VAL1
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getOrderFail
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|NumSubExprs
operator|>
name|ORDER_FAIL
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
name|ORDER_FAIL
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getVal2
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Op
operator|==
name|AO__atomic_exchange
condition|)
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|ORDER_FAIL
index|]
operator|)
return|;
name|assert
argument_list|(
name|NumSubExprs
operator|>
name|VAL2
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
name|VAL2
index|]
operator|)
return|;
block|}
name|Expr
operator|*
name|getWeak
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|NumSubExprs
operator|>
name|WEAK
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
name|WEAK
index|]
operator|)
return|;
block|}
name|AtomicOp
name|getOp
argument_list|()
specifier|const
block|{
return|return
name|Op
return|;
block|}
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
operator|*
name|getSubExprs
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
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
specifier|const
operator|*
name|getSubExprs
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
specifier|const
operator|*
operator|>
operator|(
name|SubExprs
operator|)
return|;
block|}
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|getPtr
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|getPointeeType
argument_list|()
operator|.
name|isVolatileQualified
argument_list|()
return|;
block|}
name|bool
name|isCmpXChg
argument_list|()
specifier|const
block|{
return|return
name|getOp
argument_list|()
operator|==
name|AO__c11_atomic_compare_exchange_strong
operator|||
name|getOp
argument_list|()
operator|==
name|AO__c11_atomic_compare_exchange_weak
operator|||
name|getOp
argument_list|()
operator|==
name|AO__atomic_compare_exchange
operator|||
name|getOp
argument_list|()
operator|==
name|AO__atomic_compare_exchange_n
return|;
block|}
name|SourceLocation
name|getBuiltinLoc
argument_list|()
specifier|const
block|{
return|return
name|BuiltinLoc
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
block|{
return|return
name|BuiltinLoc
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
name|AtomicExprClass
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
name|SubExprs
argument_list|,
name|SubExprs
operator|+
name|NumSubExprs
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|SubExprs
argument_list|,
name|SubExprs
operator|+
name|NumSubExprs
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// TypoExpr - Internal placeholder for expressions where typo correction
comment|/// still needs to be performed and/or an error diagnostic emitted.
name|class
name|TypoExpr
operator|:
name|public
name|Expr
block|{
name|public
operator|:
name|TypoExpr
argument_list|(
argument|QualType T
argument_list|)
operator|:
name|Expr
argument_list|(
argument|TypoExprClass
argument_list|,
argument|T
argument_list|,
argument|VK_LValue
argument_list|,
argument|OK_Ordinary
argument_list|,
comment|/*isTypeDependent*/
argument|true
argument_list|,
comment|/*isValueDependent*/
argument|true
argument_list|,
comment|/*isInstantiationDependent*/
argument|true
argument_list|,
comment|/*containsUnexpandedParameterPack*/
argument|false
argument_list|)
block|{
name|assert
argument_list|(
name|T
operator|->
name|isDependentType
argument_list|()
operator|&&
literal|"TypoExpr given a non-dependent type"
argument_list|)
block|;   }
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
block|}
name|const_child_range
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_child_range
argument_list|(
name|const_child_iterator
argument_list|()
argument_list|,
name|const_child_iterator
argument_list|()
argument_list|)
return|;
block|}
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
name|TypoExprClass
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_EXPR_H
end_comment

end_unit

