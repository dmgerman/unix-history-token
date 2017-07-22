begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Overload.h - C++ Overloading ---------------------------*- C++ -*-===//
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
comment|// This file defines the data structures and types used in C++
end_comment

begin_comment
comment|// overload resolution.
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
name|LLVM_CLANG_SEMA_OVERLOAD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_OVERLOAD_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclTemplate.h"
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
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/UnresolvedSet.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/SemaFixItUtils.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/TemplateDeduction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|CXXConstructorDecl
decl_stmt|;
name|class
name|CXXConversionDecl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|Sema
decl_stmt|;
comment|/// OverloadingResult - Capture the result of performing overload
comment|/// resolution.
enum|enum
name|OverloadingResult
block|{
name|OR_Success
block|,
comment|///< Overload resolution succeeded.
name|OR_No_Viable_Function
block|,
comment|///< No viable function found.
name|OR_Ambiguous
block|,
comment|///< Ambiguous candidates found.
name|OR_Deleted
comment|///< Succeeded, but refers to a deleted function.
block|}
enum|;
enum|enum
name|OverloadCandidateDisplayKind
block|{
comment|/// Requests that all candidates be shown.  Viable candidates will
comment|/// be printed first.
name|OCD_AllCandidates
block|,
comment|/// Requests that only viable candidates be shown.
name|OCD_ViableCandidates
block|}
enum|;
comment|/// ImplicitConversionKind - The kind of implicit conversion used to
comment|/// convert an argument to a parameter's type. The enumerator values
comment|/// match with Table 9 of (C++ 13.3.3.1.1) and are listed such that
comment|/// better conversion kinds have smaller values.
enum|enum
name|ImplicitConversionKind
block|{
name|ICK_Identity
init|=
literal|0
block|,
comment|///< Identity conversion (no conversion)
name|ICK_Lvalue_To_Rvalue
block|,
comment|///< Lvalue-to-rvalue conversion (C++ 4.1)
name|ICK_Array_To_Pointer
block|,
comment|///< Array-to-pointer conversion (C++ 4.2)
name|ICK_Function_To_Pointer
block|,
comment|///< Function-to-pointer (C++ 4.3)
name|ICK_Function_Conversion
block|,
comment|///< Function pointer conversion (C++17 4.13)
name|ICK_Qualification
block|,
comment|///< Qualification conversions (C++ 4.4)
name|ICK_Integral_Promotion
block|,
comment|///< Integral promotions (C++ 4.5)
name|ICK_Floating_Promotion
block|,
comment|///< Floating point promotions (C++ 4.6)
name|ICK_Complex_Promotion
block|,
comment|///< Complex promotions (Clang extension)
name|ICK_Integral_Conversion
block|,
comment|///< Integral conversions (C++ 4.7)
name|ICK_Floating_Conversion
block|,
comment|///< Floating point conversions (C++ 4.8)
name|ICK_Complex_Conversion
block|,
comment|///< Complex conversions (C99 6.3.1.6)
name|ICK_Floating_Integral
block|,
comment|///< Floating-integral conversions (C++ 4.9)
name|ICK_Pointer_Conversion
block|,
comment|///< Pointer conversions (C++ 4.10)
name|ICK_Pointer_Member
block|,
comment|///< Pointer-to-member conversions (C++ 4.11)
name|ICK_Boolean_Conversion
block|,
comment|///< Boolean conversions (C++ 4.12)
name|ICK_Compatible_Conversion
block|,
comment|///< Conversions between compatible types in C99
name|ICK_Derived_To_Base
block|,
comment|///< Derived-to-base (C++ [over.best.ics])
name|ICK_Vector_Conversion
block|,
comment|///< Vector conversions
name|ICK_Vector_Splat
block|,
comment|///< A vector splat from an arithmetic type
name|ICK_Complex_Real
block|,
comment|///< Complex-real conversions (C99 6.3.1.7)
name|ICK_Block_Pointer_Conversion
block|,
comment|///< Block Pointer conversions
name|ICK_TransparentUnionConversion
block|,
comment|///< Transparent Union Conversions
name|ICK_Writeback_Conversion
block|,
comment|///< Objective-C ARC writeback conversion
name|ICK_Zero_Event_Conversion
block|,
comment|///< Zero constant to event (OpenCL1.2 6.12.10)
name|ICK_Zero_Queue_Conversion
block|,
comment|///< Zero constant to queue
name|ICK_C_Only_Conversion
block|,
comment|///< Conversions allowed in C, but not C++
name|ICK_Incompatible_Pointer_Conversion
block|,
comment|///< C-only conversion between pointers
comment|///  with incompatible types
name|ICK_Num_Conversion_Kinds
block|,
comment|///< The number of conversion kinds
block|}
enum|;
comment|/// ImplicitConversionRank - The rank of an implicit conversion
comment|/// kind. The enumerator values match with Table 9 of (C++
comment|/// 13.3.3.1.1) and are listed such that better conversion ranks
comment|/// have smaller values.
enum|enum
name|ImplicitConversionRank
block|{
name|ICR_Exact_Match
init|=
literal|0
block|,
comment|///< Exact Match
name|ICR_Promotion
block|,
comment|///< Promotion
name|ICR_Conversion
block|,
comment|///< Conversion
name|ICR_OCL_Scalar_Widening
block|,
comment|///< OpenCL Scalar Widening
name|ICR_Complex_Real_Conversion
block|,
comment|///< Complex<-> Real conversion
name|ICR_Writeback_Conversion
block|,
comment|///< ObjC ARC writeback conversion
name|ICR_C_Conversion
block|,
comment|///< Conversion only allowed in the C standard.
comment|///  (e.g. void* to char*)
name|ICR_C_Conversion_Extension
comment|///< Conversion not allowed by the C standard,
comment|///  but that we accept as an extension anyway.
block|}
enum|;
name|ImplicitConversionRank
name|GetConversionRank
parameter_list|(
name|ImplicitConversionKind
name|Kind
parameter_list|)
function_decl|;
comment|/// NarrowingKind - The kind of narrowing conversion being performed by a
comment|/// standard conversion sequence according to C++11 [dcl.init.list]p7.
enum|enum
name|NarrowingKind
block|{
comment|/// Not a narrowing conversion.
name|NK_Not_Narrowing
block|,
comment|/// A narrowing conversion by virtue of the source and destination types.
name|NK_Type_Narrowing
block|,
comment|/// A narrowing conversion, because a constant expression got narrowed.
name|NK_Constant_Narrowing
block|,
comment|/// A narrowing conversion, because a non-constant-expression variable might
comment|/// have got narrowed.
name|NK_Variable_Narrowing
block|,
comment|/// Cannot tell whether this is a narrowing conversion because the
comment|/// expression is value-dependent.
name|NK_Dependent_Narrowing
block|,   }
enum|;
comment|/// StandardConversionSequence - represents a standard conversion
comment|/// sequence (C++ 13.3.3.1.1). A standard conversion sequence
comment|/// contains between zero and three conversions. If a particular
comment|/// conversion is not needed, it will be set to the identity conversion
comment|/// (ICK_Identity). Note that the three conversions are
comment|/// specified as separate members (rather than in an array) so that
comment|/// we can keep the size of a standard conversion sequence to a
comment|/// single word.
name|class
name|StandardConversionSequence
block|{
name|public
label|:
comment|/// First -- The first conversion can be an lvalue-to-rvalue
comment|/// conversion, array-to-pointer conversion, or
comment|/// function-to-pointer conversion.
name|ImplicitConversionKind
name|First
range|:
literal|8
decl_stmt|;
comment|/// Second - The second conversion can be an integral promotion,
comment|/// floating point promotion, integral conversion, floating point
comment|/// conversion, floating-integral conversion, pointer conversion,
comment|/// pointer-to-member conversion, or boolean conversion.
name|ImplicitConversionKind
name|Second
range|:
literal|8
decl_stmt|;
comment|/// Third - The third conversion can be a qualification conversion
comment|/// or a function conversion.
name|ImplicitConversionKind
name|Third
range|:
literal|8
decl_stmt|;
comment|/// \brief Whether this is the deprecated conversion of a
comment|/// string literal to a pointer to non-const character data
comment|/// (C++ 4.2p2).
name|unsigned
name|DeprecatedStringLiteralToCharPtr
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether the qualification conversion involves a change in the
comment|/// Objective-C lifetime (for automatic reference counting).
name|unsigned
name|QualificationIncludesObjCLifetime
range|:
literal|1
decl_stmt|;
comment|/// IncompatibleObjC - Whether this is an Objective-C conversion
comment|/// that we should warn about (if we actually use it).
name|unsigned
name|IncompatibleObjC
range|:
literal|1
decl_stmt|;
comment|/// ReferenceBinding - True when this is a reference binding
comment|/// (C++ [over.ics.ref]).
name|unsigned
name|ReferenceBinding
range|:
literal|1
decl_stmt|;
comment|/// DirectBinding - True when this is a reference binding that is a
comment|/// direct binding (C++ [dcl.init.ref]).
name|unsigned
name|DirectBinding
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this is an lvalue reference binding (otherwise, it's
comment|/// an rvalue reference binding).
name|unsigned
name|IsLvalueReference
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether we're binding to a function lvalue.
name|unsigned
name|BindsToFunctionLvalue
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether we're binding to an rvalue.
name|unsigned
name|BindsToRvalue
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this binds an implicit object argument to a
comment|/// non-static member function without a ref-qualifier.
name|unsigned
name|BindsImplicitObjectArgumentWithoutRefQualifier
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this binds a reference to an object with a different
comment|/// Objective-C lifetime qualifier.
name|unsigned
name|ObjCLifetimeConversionBinding
range|:
literal|1
decl_stmt|;
comment|/// FromType - The type that this conversion is converting
comment|/// from. This is an opaque pointer that can be translated into a
comment|/// QualType.
name|void
modifier|*
name|FromTypePtr
decl_stmt|;
comment|/// ToType - The types that this conversion is converting to in
comment|/// each step. This is an opaque pointer that can be translated
comment|/// into a QualType.
name|void
modifier|*
name|ToTypePtrs
index|[
literal|3
index|]
decl_stmt|;
comment|/// CopyConstructor - The copy constructor that is used to perform
comment|/// this conversion, when the conversion is actually just the
comment|/// initialization of an object via copy constructor. Such
comment|/// conversions are either identity conversions or derived-to-base
comment|/// conversions.
name|CXXConstructorDecl
modifier|*
name|CopyConstructor
decl_stmt|;
name|DeclAccessPair
name|FoundCopyConstructor
decl_stmt|;
name|void
name|setFromType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|FromTypePtr
operator|=
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
expr_stmt|;
block|}
name|void
name|setToType
parameter_list|(
name|unsigned
name|Idx
parameter_list|,
name|QualType
name|T
parameter_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
literal|3
operator|&&
literal|"To type index is out of range"
argument_list|)
expr_stmt|;
name|ToTypePtrs
index|[
name|Idx
index|]
operator|=
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
expr_stmt|;
block|}
name|void
name|setAllToTypes
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|ToTypePtrs
index|[
literal|0
index|]
operator|=
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
expr_stmt|;
name|ToTypePtrs
index|[
literal|1
index|]
operator|=
name|ToTypePtrs
index|[
literal|0
index|]
expr_stmt|;
name|ToTypePtrs
index|[
literal|2
index|]
operator|=
name|ToTypePtrs
index|[
literal|0
index|]
expr_stmt|;
block|}
name|QualType
name|getFromType
argument_list|()
specifier|const
block|{
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|FromTypePtr
argument_list|)
return|;
block|}
name|QualType
name|getToType
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
literal|3
operator|&&
literal|"To type index is out of range"
argument_list|)
expr_stmt|;
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|ToTypePtrs
index|[
name|Idx
index|]
argument_list|)
return|;
block|}
name|void
name|setAsIdentityConversion
parameter_list|()
function_decl|;
name|bool
name|isIdentityConversion
argument_list|()
specifier|const
block|{
return|return
name|Second
operator|==
name|ICK_Identity
operator|&&
name|Third
operator|==
name|ICK_Identity
return|;
block|}
name|ImplicitConversionRank
name|getRank
argument_list|()
specifier|const
expr_stmt|;
name|NarrowingKind
name|getNarrowingKind
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
specifier|const
name|Expr
operator|*
name|Converted
argument_list|,
name|APValue
operator|&
name|ConstantValue
argument_list|,
name|QualType
operator|&
name|ConstantType
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isPointerConversionToBool
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isPointerConversionToVoidPointer
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// UserDefinedConversionSequence - Represents a user-defined
comment|/// conversion sequence (C++ 13.3.3.1.2).
struct|struct
name|UserDefinedConversionSequence
block|{
comment|/// \brief Represents the standard conversion that occurs before
comment|/// the actual user-defined conversion.
comment|///
comment|/// C++11 13.3.3.1.2p1:
comment|///   If the user-defined conversion is specified by a constructor
comment|///   (12.3.1), the initial standard conversion sequence converts
comment|///   the source type to the type required by the argument of the
comment|///   constructor. If the user-defined conversion is specified by
comment|///   a conversion function (12.3.2), the initial standard
comment|///   conversion sequence converts the source type to the implicit
comment|///   object parameter of the conversion function.
name|StandardConversionSequence
name|Before
decl_stmt|;
comment|/// EllipsisConversion - When this is true, it means user-defined
comment|/// conversion sequence starts with a ... (ellipsis) conversion, instead of
comment|/// a standard conversion. In this case, 'Before' field must be ignored.
comment|// FIXME. I much rather put this as the first field. But there seems to be
comment|// a gcc code gen. bug which causes a crash in a test. Putting it here seems
comment|// to work around the crash.
name|bool
name|EllipsisConversion
range|:
literal|1
decl_stmt|;
comment|/// HadMultipleCandidates - When this is true, it means that the
comment|/// conversion function was resolved from an overloaded set having
comment|/// size greater than 1.
name|bool
name|HadMultipleCandidates
range|:
literal|1
decl_stmt|;
comment|/// After - Represents the standard conversion that occurs after
comment|/// the actual user-defined conversion.
name|StandardConversionSequence
name|After
decl_stmt|;
comment|/// ConversionFunction - The function that will perform the
comment|/// user-defined conversion. Null if the conversion is an
comment|/// aggregate initialization from an initializer list.
name|FunctionDecl
modifier|*
name|ConversionFunction
decl_stmt|;
comment|/// \brief The declaration that we found via name lookup, which might be
comment|/// the same as \c ConversionFunction or it might be a using declaration
comment|/// that refers to \c ConversionFunction.
name|DeclAccessPair
name|FoundConversionFunction
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
comment|/// Represents an ambiguous user-defined conversion sequence.
struct|struct
name|AmbiguousConversionSequence
block|{
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
operator|,
name|FunctionDecl
operator|*
operator|>
operator|,
literal|4
operator|>
name|ConversionSet
expr_stmt|;
name|void
modifier|*
name|FromTypePtr
decl_stmt|;
name|void
modifier|*
name|ToTypePtr
decl_stmt|;
name|char
name|Buffer
index|[
sizeof|sizeof
argument_list|(
name|ConversionSet
argument_list|)
index|]
decl_stmt|;
name|QualType
name|getFromType
argument_list|()
specifier|const
block|{
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|FromTypePtr
argument_list|)
return|;
block|}
name|QualType
name|getToType
argument_list|()
specifier|const
block|{
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|ToTypePtr
argument_list|)
return|;
block|}
name|void
name|setFromType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|FromTypePtr
operator|=
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
expr_stmt|;
block|}
name|void
name|setToType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|ToTypePtr
operator|=
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
expr_stmt|;
block|}
name|ConversionSet
modifier|&
name|conversions
parameter_list|()
block|{
return|return
operator|*
name|reinterpret_cast
operator|<
name|ConversionSet
operator|*
operator|>
operator|(
name|Buffer
operator|)
return|;
block|}
specifier|const
name|ConversionSet
operator|&
name|conversions
argument_list|()
specifier|const
block|{
return|return
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|ConversionSet
operator|*
operator|>
operator|(
name|Buffer
operator|)
return|;
block|}
name|void
name|addConversion
parameter_list|(
name|NamedDecl
modifier|*
name|Found
parameter_list|,
name|FunctionDecl
modifier|*
name|D
parameter_list|)
block|{
name|conversions
argument_list|()
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Found
argument_list|,
name|D
argument_list|)
argument_list|)
expr_stmt|;
block|}
typedef|typedef
name|ConversionSet
operator|::
name|iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|conversions
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|conversions
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
name|ConversionSet
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|conversions
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|conversions
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|void
name|construct
parameter_list|()
function_decl|;
name|void
name|destruct
parameter_list|()
function_decl|;
name|void
name|copyFrom
parameter_list|(
specifier|const
name|AmbiguousConversionSequence
modifier|&
parameter_list|)
function_decl|;
block|}
struct|;
comment|/// BadConversionSequence - Records information about an invalid
comment|/// conversion sequence.
struct|struct
name|BadConversionSequence
block|{
enum|enum
name|FailureKind
block|{
name|no_conversion
block|,
name|unrelated_class
block|,
name|bad_qualifiers
block|,
name|lvalue_ref_to_rvalue
block|,
name|rvalue_ref_to_lvalue
block|}
enum|;
comment|// This can be null, e.g. for implicit object arguments.
name|Expr
modifier|*
name|FromExpr
decl_stmt|;
name|FailureKind
name|Kind
decl_stmt|;
name|private
label|:
comment|// The type we're converting from (an opaque QualType).
name|void
modifier|*
name|FromTy
decl_stmt|;
comment|// The type we're converting to (an opaque QualType).
name|void
modifier|*
name|ToTy
decl_stmt|;
name|public
label|:
name|void
name|init
parameter_list|(
name|FailureKind
name|K
parameter_list|,
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|To
parameter_list|)
block|{
name|init
argument_list|(
name|K
argument_list|,
name|From
operator|->
name|getType
argument_list|()
argument_list|,
name|To
argument_list|)
expr_stmt|;
name|FromExpr
operator|=
name|From
expr_stmt|;
block|}
name|void
name|init
parameter_list|(
name|FailureKind
name|K
parameter_list|,
name|QualType
name|From
parameter_list|,
name|QualType
name|To
parameter_list|)
block|{
name|Kind
operator|=
name|K
expr_stmt|;
name|FromExpr
operator|=
name|nullptr
expr_stmt|;
name|setFromType
argument_list|(
name|From
argument_list|)
expr_stmt|;
name|setToType
argument_list|(
name|To
argument_list|)
expr_stmt|;
block|}
name|QualType
name|getFromType
argument_list|()
specifier|const
block|{
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|FromTy
argument_list|)
return|;
block|}
name|QualType
name|getToType
argument_list|()
specifier|const
block|{
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|ToTy
argument_list|)
return|;
block|}
name|void
name|setFromExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
name|FromExpr
operator|=
name|E
expr_stmt|;
name|setFromType
argument_list|(
name|E
operator|->
name|getType
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|setFromType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|FromTy
operator|=
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
expr_stmt|;
block|}
name|void
name|setToType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|ToTy
operator|=
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
expr_stmt|;
block|}
block|}
struct|;
comment|/// ImplicitConversionSequence - Represents an implicit conversion
comment|/// sequence, which may be a standard conversion sequence
comment|/// (C++ 13.3.3.1.1), user-defined conversion sequence (C++ 13.3.3.1.2),
comment|/// or an ellipsis conversion sequence (C++ 13.3.3.1.3).
name|class
name|ImplicitConversionSequence
block|{
name|public
label|:
comment|/// Kind - The kind of implicit conversion sequence. BadConversion
comment|/// specifies that there is no conversion from the source type to
comment|/// the target type.  AmbiguousConversion represents the unique
comment|/// ambiguous conversion (C++0x [over.best.ics]p10).
enum|enum
name|Kind
block|{
name|StandardConversion
init|=
literal|0
block|,
name|UserDefinedConversion
block|,
name|AmbiguousConversion
block|,
name|EllipsisConversion
block|,
name|BadConversion
block|}
enum|;
name|private
label|:
enum|enum
block|{
name|Uninitialized
init|=
name|BadConversion
operator|+
literal|1
block|}
enum|;
comment|/// ConversionKind - The kind of implicit conversion sequence.
name|unsigned
name|ConversionKind
range|:
literal|30
decl_stmt|;
comment|/// \brief Whether the target is really a std::initializer_list, and the
comment|/// sequence only represents the worst element conversion.
name|unsigned
name|StdInitializerListElement
range|:
literal|1
decl_stmt|;
name|void
name|setKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
name|destruct
argument_list|()
expr_stmt|;
name|ConversionKind
operator|=
name|K
expr_stmt|;
block|}
name|void
name|destruct
parameter_list|()
block|{
if|if
condition|(
name|ConversionKind
operator|==
name|AmbiguousConversion
condition|)
name|Ambiguous
operator|.
name|destruct
argument_list|()
expr_stmt|;
block|}
name|public
label|:
union|union
block|{
comment|/// When ConversionKind == StandardConversion, provides the
comment|/// details of the standard conversion sequence.
name|StandardConversionSequence
name|Standard
decl_stmt|;
comment|/// When ConversionKind == UserDefinedConversion, provides the
comment|/// details of the user-defined conversion sequence.
name|UserDefinedConversionSequence
name|UserDefined
decl_stmt|;
comment|/// When ConversionKind == AmbiguousConversion, provides the
comment|/// details of the ambiguous conversion.
name|AmbiguousConversionSequence
name|Ambiguous
decl_stmt|;
comment|/// When ConversionKind == BadConversion, provides the details
comment|/// of the bad conversion.
name|BadConversionSequence
name|Bad
decl_stmt|;
block|}
union|;
name|ImplicitConversionSequence
argument_list|()
operator|:
name|ConversionKind
argument_list|(
name|Uninitialized
argument_list|)
operator|,
name|StdInitializerListElement
argument_list|(
argument|false
argument_list|)
block|{
name|Standard
operator|.
name|setAsIdentityConversion
argument_list|()
block|;     }
operator|~
name|ImplicitConversionSequence
argument_list|()
block|{
name|destruct
argument_list|()
block|;     }
name|ImplicitConversionSequence
argument_list|(
specifier|const
name|ImplicitConversionSequence
operator|&
name|Other
argument_list|)
operator|:
name|ConversionKind
argument_list|(
name|Other
operator|.
name|ConversionKind
argument_list|)
operator|,
name|StdInitializerListElement
argument_list|(
argument|Other.StdInitializerListElement
argument_list|)
block|{
switch|switch
condition|(
name|ConversionKind
condition|)
block|{
case|case
name|Uninitialized
case|:
break|break;
case|case
name|StandardConversion
case|:
name|Standard
operator|=
name|Other
operator|.
name|Standard
expr_stmt|;
break|break;
case|case
name|UserDefinedConversion
case|:
name|UserDefined
operator|=
name|Other
operator|.
name|UserDefined
expr_stmt|;
break|break;
case|case
name|AmbiguousConversion
case|:
name|Ambiguous
operator|.
name|copyFrom
argument_list|(
name|Other
operator|.
name|Ambiguous
argument_list|)
expr_stmt|;
break|break;
case|case
name|EllipsisConversion
case|:
break|break;
case|case
name|BadConversion
case|:
name|Bad
operator|=
name|Other
operator|.
name|Bad
expr_stmt|;
break|break;
block|}
block|}
name|ImplicitConversionSequence
operator|&
name|operator
operator|=
operator|(
specifier|const
name|ImplicitConversionSequence
operator|&
name|Other
operator|)
block|{
name|destruct
argument_list|()
block|;
name|new
argument_list|(
argument|this
argument_list|)
name|ImplicitConversionSequence
argument_list|(
name|Other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isInitialized
argument_list|()
operator|&&
literal|"querying uninitialized conversion"
argument_list|)
block|;
return|return
name|Kind
argument_list|(
name|ConversionKind
argument_list|)
return|;
block|}
comment|/// \brief Return a ranking of the implicit conversion sequence
comment|/// kind, where smaller ranks represent better conversion
comment|/// sequences.
comment|///
comment|/// In particular, this routine gives user-defined conversion
comment|/// sequences and ambiguous conversion sequences the same rank,
comment|/// per C++ [over.best.ics]p10.
name|unsigned
name|getKindRank
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getKind
argument_list|()
condition|)
block|{
case|case
name|StandardConversion
case|:
return|return
literal|0
return|;
case|case
name|UserDefinedConversion
case|:
case|case
name|AmbiguousConversion
case|:
return|return
literal|1
return|;
case|case
name|EllipsisConversion
case|:
return|return
literal|2
return|;
case|case
name|BadConversion
case|:
return|return
literal|3
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Invalid ImplicitConversionSequence::Kind!"
argument_list|)
expr_stmt|;
block|}
name|bool
name|isBad
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|BadConversion
return|;
block|}
name|bool
name|isStandard
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|StandardConversion
return|;
block|}
name|bool
name|isEllipsis
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|EllipsisConversion
return|;
block|}
name|bool
name|isAmbiguous
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|AmbiguousConversion
return|;
block|}
name|bool
name|isUserDefined
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|UserDefinedConversion
return|;
block|}
name|bool
name|isFailure
argument_list|()
specifier|const
block|{
return|return
name|isBad
argument_list|()
operator|||
name|isAmbiguous
argument_list|()
return|;
block|}
comment|/// Determines whether this conversion sequence has been
comment|/// initialized.  Most operations should never need to query
comment|/// uninitialized conversions and should assert as above.
name|bool
name|isInitialized
argument_list|()
specifier|const
block|{
return|return
name|ConversionKind
operator|!=
name|Uninitialized
return|;
block|}
comment|/// Sets this sequence as a bad conversion for an explicit argument.
name|void
name|setBad
argument_list|(
name|BadConversionSequence
operator|::
name|FailureKind
name|Failure
argument_list|,
name|Expr
operator|*
name|FromExpr
argument_list|,
name|QualType
name|ToType
argument_list|)
block|{
name|setKind
argument_list|(
name|BadConversion
argument_list|)
expr_stmt|;
name|Bad
operator|.
name|init
argument_list|(
name|Failure
argument_list|,
name|FromExpr
argument_list|,
name|ToType
argument_list|)
expr_stmt|;
block|}
comment|/// Sets this sequence as a bad conversion for an implicit argument.
name|void
name|setBad
argument_list|(
name|BadConversionSequence
operator|::
name|FailureKind
name|Failure
argument_list|,
name|QualType
name|FromType
argument_list|,
name|QualType
name|ToType
argument_list|)
block|{
name|setKind
argument_list|(
name|BadConversion
argument_list|)
expr_stmt|;
name|Bad
operator|.
name|init
argument_list|(
name|Failure
argument_list|,
name|FromType
argument_list|,
name|ToType
argument_list|)
expr_stmt|;
block|}
name|void
name|setStandard
parameter_list|()
block|{
name|setKind
argument_list|(
name|StandardConversion
argument_list|)
expr_stmt|;
block|}
name|void
name|setEllipsis
parameter_list|()
block|{
name|setKind
argument_list|(
name|EllipsisConversion
argument_list|)
expr_stmt|;
block|}
name|void
name|setUserDefined
parameter_list|()
block|{
name|setKind
argument_list|(
name|UserDefinedConversion
argument_list|)
expr_stmt|;
block|}
name|void
name|setAmbiguous
parameter_list|()
block|{
if|if
condition|(
name|ConversionKind
operator|==
name|AmbiguousConversion
condition|)
return|return;
name|ConversionKind
operator|=
name|AmbiguousConversion
expr_stmt|;
name|Ambiguous
operator|.
name|construct
argument_list|()
expr_stmt|;
block|}
name|void
name|setAsIdentityConversion
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|setStandard
argument_list|()
expr_stmt|;
name|Standard
operator|.
name|setAsIdentityConversion
argument_list|()
expr_stmt|;
name|Standard
operator|.
name|setFromType
argument_list|(
name|T
argument_list|)
expr_stmt|;
name|Standard
operator|.
name|setAllToTypes
argument_list|(
name|T
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Whether the target is really a std::initializer_list, and the
comment|/// sequence only represents the worst element conversion.
name|bool
name|isStdInitializerListElement
argument_list|()
specifier|const
block|{
return|return
name|StdInitializerListElement
return|;
block|}
name|void
name|setStdInitializerListElement
parameter_list|(
name|bool
name|V
init|=
name|true
parameter_list|)
block|{
name|StdInitializerListElement
operator|=
name|V
expr_stmt|;
block|}
comment|// The result of a comparison between implicit conversion
comment|// sequences. Use Sema::CompareImplicitConversionSequences to
comment|// actually perform the comparison.
enum|enum
name|CompareKind
block|{
name|Better
init|=
operator|-
literal|1
block|,
name|Indistinguishable
init|=
literal|0
block|,
name|Worse
init|=
literal|1
block|}
enum|;
name|void
name|DiagnoseAmbiguousConversion
argument_list|(
name|Sema
operator|&
name|S
argument_list|,
name|SourceLocation
name|CaretLoc
argument_list|,
specifier|const
name|PartialDiagnostic
operator|&
name|PDiag
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
enum|enum
name|OverloadFailureKind
block|{
name|ovl_fail_too_many_arguments
block|,
name|ovl_fail_too_few_arguments
block|,
name|ovl_fail_bad_conversion
block|,
name|ovl_fail_bad_deduction
block|,
comment|/// This conversion candidate was not considered because it
comment|/// duplicates the work of a trivial or derived-to-base
comment|/// conversion.
name|ovl_fail_trivial_conversion
block|,
comment|/// This conversion candidate was not considered because it is
comment|/// an illegal instantiation of a constructor temploid: it is
comment|/// callable with one argument, we only have one argument, and
comment|/// its first parameter type is exactly the type of the class.
comment|///
comment|/// Defining such a constructor directly is illegal, and
comment|/// template-argument deduction is supposed to ignore such
comment|/// instantiations, but we can still get one with the right
comment|/// kind of implicit instantiation.
name|ovl_fail_illegal_constructor
block|,
comment|/// This conversion candidate is not viable because its result
comment|/// type is not implicitly convertible to the desired type.
name|ovl_fail_bad_final_conversion
block|,
comment|/// This conversion function template specialization candidate is not
comment|/// viable because the final conversion was not an exact match.
name|ovl_fail_final_conversion_not_exact
block|,
comment|/// (CUDA) This candidate was not viable because the callee
comment|/// was not accessible from the caller's target (i.e. host->device,
comment|/// global->host, device->host).
name|ovl_fail_bad_target
block|,
comment|/// This candidate function was not viable because an enable_if
comment|/// attribute disabled it.
name|ovl_fail_enable_if
block|,
comment|/// This candidate was not viable because its address could not be taken.
name|ovl_fail_addr_not_available
block|,
comment|/// This candidate was not viable because its OpenCL extension is disabled.
name|ovl_fail_ext_disabled
block|,
comment|/// This inherited constructor is not viable because it would slice the
comment|/// argument.
name|ovl_fail_inhctor_slice
block|,   }
enum|;
comment|/// A list of implicit conversion sequences for the arguments of an
comment|/// OverloadCandidate.
typedef|typedef
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|ImplicitConversionSequence
operator|>
name|ConversionSequenceList
expr_stmt|;
comment|/// OverloadCandidate - A single candidate in an overload set (C++ 13.3).
struct|struct
name|OverloadCandidate
block|{
comment|/// Function - The actual function that this candidate
comment|/// represents. When NULL, this is a built-in candidate
comment|/// (C++ [over.oper]) or a surrogate for a conversion to a
comment|/// function pointer or reference (C++ [over.call.object]).
name|FunctionDecl
modifier|*
name|Function
decl_stmt|;
comment|/// FoundDecl - The original declaration that was looked up /
comment|/// invented / otherwise found, together with its access.
comment|/// Might be a UsingShadowDecl or a FunctionTemplateDecl.
name|DeclAccessPair
name|FoundDecl
decl_stmt|;
comment|/// BuiltinParamTypes - Provides the parameter types of a built-in overload
comment|/// candidate. Only valid when Function is NULL.
name|QualType
name|BuiltinParamTypes
index|[
literal|3
index|]
decl_stmt|;
comment|/// Surrogate - The conversion function for which this candidate
comment|/// is a surrogate, but only if IsSurrogate is true.
name|CXXConversionDecl
modifier|*
name|Surrogate
decl_stmt|;
comment|/// The conversion sequences used to convert the function arguments
comment|/// to the function parameters.
name|ConversionSequenceList
name|Conversions
decl_stmt|;
comment|/// The FixIt hints which can be used to fix the Bad candidate.
name|ConversionFixItGenerator
name|Fix
decl_stmt|;
comment|/// Viable - True to indicate that this overload candidate is viable.
name|bool
name|Viable
decl_stmt|;
comment|/// IsSurrogate - True to indicate that this candidate is a
comment|/// surrogate for a conversion to a function pointer or reference
comment|/// (C++ [over.call.object]).
name|bool
name|IsSurrogate
decl_stmt|;
comment|/// IgnoreObjectArgument - True to indicate that the first
comment|/// argument's conversion, which for this function represents the
comment|/// implicit object argument, should be ignored. This will be true
comment|/// when the candidate is a static member function (where the
comment|/// implicit object argument is just a placeholder) or a
comment|/// non-static member function when the call doesn't have an
comment|/// object argument.
name|bool
name|IgnoreObjectArgument
decl_stmt|;
comment|/// FailureKind - The reason why this candidate is not viable.
comment|/// Actually an OverloadFailureKind.
name|unsigned
name|char
name|FailureKind
decl_stmt|;
comment|/// \brief The number of call arguments that were explicitly provided,
comment|/// to be used while performing partial ordering of function templates.
name|unsigned
name|ExplicitCallArguments
decl_stmt|;
union|union
block|{
name|DeductionFailureInfo
name|DeductionFailure
decl_stmt|;
comment|/// FinalConversion - For a conversion function (where Function is
comment|/// a CXXConversionDecl), the standard conversion that occurs
comment|/// after the call to the overload candidate to convert the result
comment|/// of calling the conversion function to the required type.
name|StandardConversionSequence
name|FinalConversion
decl_stmt|;
block|}
union|;
comment|/// hasAmbiguousConversion - Returns whether this overload
comment|/// candidate requires an ambiguous conversion or not.
name|bool
name|hasAmbiguousConversion
argument_list|()
specifier|const
block|{
for|for
control|(
name|auto
operator|&
name|C
operator|:
name|Conversions
control|)
block|{
if|if
condition|(
operator|!
name|C
operator|.
name|isInitialized
argument_list|()
condition|)
return|return
name|false
return|;
if|if
condition|(
name|C
operator|.
name|isAmbiguous
argument_list|()
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|bool
name|TryToFixBadConversion
parameter_list|(
name|unsigned
name|Idx
parameter_list|,
name|Sema
modifier|&
name|S
parameter_list|)
block|{
name|bool
name|CanFix
init|=
name|Fix
operator|.
name|tryToFixConversion
argument_list|(
name|Conversions
index|[
name|Idx
index|]
operator|.
name|Bad
operator|.
name|FromExpr
argument_list|,
name|Conversions
index|[
name|Idx
index|]
operator|.
name|Bad
operator|.
name|getFromType
argument_list|()
argument_list|,
name|Conversions
index|[
name|Idx
index|]
operator|.
name|Bad
operator|.
name|getToType
argument_list|()
argument_list|,
name|S
argument_list|)
decl_stmt|;
comment|// If at least one conversion fails, the candidate cannot be fixed.
if|if
condition|(
operator|!
name|CanFix
condition|)
name|Fix
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
name|CanFix
return|;
block|}
name|unsigned
name|getNumParams
argument_list|()
specifier|const
block|{
if|if
condition|(
name|IsSurrogate
condition|)
block|{
name|auto
name|STy
init|=
name|Surrogate
operator|->
name|getConversionType
argument_list|()
decl_stmt|;
while|while
condition|(
name|STy
operator|->
name|isPointerType
argument_list|()
operator|||
name|STy
operator|->
name|isReferenceType
argument_list|()
condition|)
name|STy
operator|=
name|STy
operator|->
name|getPointeeType
argument_list|()
expr_stmt|;
return|return
name|STy
operator|->
name|getAs
operator|<
name|FunctionProtoType
operator|>
operator|(
operator|)
operator|->
name|getNumParams
argument_list|()
return|;
block|}
if|if
condition|(
name|Function
condition|)
return|return
name|Function
operator|->
name|getNumParams
argument_list|()
return|;
return|return
name|ExplicitCallArguments
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// OverloadCandidateSet - A set of overload candidates, used in C++
end_comment

begin_comment
comment|/// overload resolution (C++ 13.3).
end_comment

begin_decl_stmt
name|class
name|OverloadCandidateSet
block|{
name|public
label|:
enum|enum
name|CandidateSetKind
block|{
comment|/// Normal lookup.
name|CSK_Normal
block|,
comment|/// Lookup for candidates for a call using operator syntax. Candidates
comment|/// that have no parameters of class type will be skipped unless there
comment|/// is a parameter of (reference to) enum type and the corresponding
comment|/// argument is of the same enum type.
name|CSK_Operator
block|}
enum|;
name|private
label|:
name|SmallVector
operator|<
name|OverloadCandidate
operator|,
literal|16
operator|>
name|Candidates
expr_stmt|;
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|Decl
operator|*
operator|,
literal|16
operator|>
name|Functions
expr_stmt|;
comment|// Allocator for ConversionSequenceLists. We store the first few of these
comment|// inline to avoid allocation for small sets.
name|llvm
operator|::
name|BumpPtrAllocator
name|SlabAllocator
expr_stmt|;
name|SourceLocation
name|Loc
decl_stmt|;
name|CandidateSetKind
name|Kind
decl_stmt|;
name|constexpr
specifier|static
name|unsigned
name|NumInlineBytes
init|=
literal|24
operator|*
sizeof|sizeof
argument_list|(
name|ImplicitConversionSequence
argument_list|)
decl_stmt|;
name|unsigned
name|NumInlineBytesUsed
decl_stmt|;
name|llvm
operator|::
name|AlignedCharArray
operator|<
name|alignof
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|NumInlineBytes
operator|>
name|InlineSpace
expr_stmt|;
comment|/// If we have space, allocates from inline storage. Otherwise, allocates
comment|/// from the slab allocator.
comment|/// FIXME: It would probably be nice to have a SmallBumpPtrAllocator
comment|/// instead.
comment|/// FIXME: Now that this only allocates ImplicitConversionSequences, do we
comment|/// want to un-generalize this?
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|slabAllocate
argument_list|(
argument|unsigned N
argument_list|)
block|{
comment|// It's simpler if this doesn't need to consider alignment.
name|static_assert
argument_list|(
name|alignof
argument_list|(
name|T
argument_list|)
operator|==
name|alignof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
literal|"Only works for pointer-aligned types."
argument_list|)
block|;
name|static_assert
argument_list|(
name|std
operator|::
name|is_trivial
operator|<
name|T
operator|>
operator|::
name|value
operator|||
name|std
operator|::
name|is_same
operator|<
name|ImplicitConversionSequence
argument_list|,
name|T
operator|>
operator|::
name|value
argument_list|,
literal|"Add destruction logic to OverloadCandidateSet::clear()."
argument_list|)
block|;
name|unsigned
name|NBytes
operator|=
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
name|N
block|;
if|if
condition|(
name|NBytes
operator|>
name|NumInlineBytes
operator|-
name|NumInlineBytesUsed
condition|)
return|return
name|SlabAllocator
operator|.
name|Allocate
operator|<
name|T
operator|>
operator|(
name|N
operator|)
return|;
name|char
operator|*
name|FreeSpaceStart
operator|=
name|InlineSpace
operator|.
name|buffer
operator|+
name|NumInlineBytesUsed
expr_stmt|;
name|assert
argument_list|(
name|uintptr_t
argument_list|(
name|FreeSpaceStart
argument_list|)
operator|%
name|alignof
argument_list|(
name|void
operator|*
argument_list|)
operator|==
literal|0
operator|&&
literal|"Misaligned storage!"
argument_list|)
expr_stmt|;
name|NumInlineBytesUsed
operator|+=
name|NBytes
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|FreeSpaceStart
operator|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|OverloadCandidateSet
argument_list|(
specifier|const
name|OverloadCandidateSet
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|OverloadCandidateSet
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|destroyCandidates
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_macro
name|OverloadCandidateSet
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|CandidateSetKind CSK
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|Loc
argument_list|(
name|Loc
argument_list|)
operator|,
name|Kind
argument_list|(
name|CSK
argument_list|)
operator|,
name|NumInlineBytesUsed
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|OverloadCandidateSet
argument_list|()
block|{
name|destroyCandidates
argument_list|()
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
end_expr_stmt

begin_expr_stmt
name|CandidateSetKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine when this overload candidate will be new to the
end_comment

begin_comment
comment|/// overload set.
end_comment

begin_function
name|bool
name|isNewCandidate
parameter_list|(
name|Decl
modifier|*
name|F
parameter_list|)
block|{
return|return
name|Functions
operator|.
name|insert
argument_list|(
name|F
operator|->
name|getCanonicalDecl
argument_list|()
argument_list|)
operator|.
name|second
return|;
block|}
end_function

begin_comment
comment|/// \brief Clear out all of the candidates.
end_comment

begin_function_decl
name|void
name|clear
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|SmallVectorImpl
operator|<
name|OverloadCandidate
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Candidates
operator|.
name|begin
argument_list|()
return|;
block|}
end_function

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
name|Candidates
operator|.
name|end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Candidates
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Candidates
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Allocate storage for conversion sequences for NumConversions
end_comment

begin_comment
comment|/// conversions.
end_comment

begin_function
name|ConversionSequenceList
name|allocateConversionSequences
parameter_list|(
name|unsigned
name|NumConversions
parameter_list|)
block|{
name|ImplicitConversionSequence
modifier|*
name|Conversions
init|=
name|slabAllocate
operator|<
name|ImplicitConversionSequence
operator|>
operator|(
name|NumConversions
operator|)
decl_stmt|;
comment|// Construct the new objects.
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|!=
name|NumConversions
condition|;
operator|++
name|I
control|)
name|new
argument_list|(
argument|&Conversions[I]
argument_list|)
name|ImplicitConversionSequence
argument_list|()
expr_stmt|;
return|return
name|ConversionSequenceList
argument_list|(
name|Conversions
argument_list|,
name|NumConversions
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Add a new candidate with NumConversions conversion sequence slots
end_comment

begin_comment
comment|/// to the overload set.
end_comment

begin_function
name|OverloadCandidate
modifier|&
name|addCandidate
parameter_list|(
name|unsigned
name|NumConversions
init|=
literal|0
parameter_list|,
name|ConversionSequenceList
name|Conversions
init|=
name|None
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|Conversions
operator|.
name|empty
argument_list|()
operator|||
name|Conversions
operator|.
name|size
argument_list|()
operator|==
name|NumConversions
operator|)
operator|&&
literal|"preallocated conversion sequence has wrong length"
argument_list|)
expr_stmt|;
name|Candidates
operator|.
name|push_back
argument_list|(
name|OverloadCandidate
argument_list|()
argument_list|)
expr_stmt|;
name|OverloadCandidate
modifier|&
name|C
init|=
name|Candidates
operator|.
name|back
argument_list|()
decl_stmt|;
name|C
operator|.
name|Conversions
operator|=
name|Conversions
operator|.
name|empty
argument_list|()
condition|?
name|allocateConversionSequences
argument_list|(
name|NumConversions
argument_list|)
else|:
name|Conversions
expr_stmt|;
return|return
name|C
return|;
block|}
end_function

begin_comment
comment|/// Find the best viable function on this overload set, if it exists.
end_comment

begin_decl_stmt
name|OverloadingResult
name|BestViableFunction
argument_list|(
name|Sema
operator|&
name|S
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|OverloadCandidateSet
operator|::
name|iterator
operator|&
name|Best
argument_list|,
name|bool
name|UserDefinedConversion
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|NoteCandidates
argument_list|(
name|Sema
operator|&
name|S
argument_list|,
name|OverloadCandidateDisplayKind
name|OCD
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|StringRef
name|Opc
operator|=
literal|""
argument_list|,
name|SourceLocation
name|Loc
operator|=
name|SourceLocation
argument_list|()
argument_list|,
name|llvm
operator|::
name|function_ref
operator|<
name|bool
argument_list|(
name|OverloadCandidate
operator|&
argument_list|)
operator|>
name|Filter
operator|=
index|[]
operator|(
name|OverloadCandidate
operator|&
operator|)
block|{
return|return
name|true
return|;
block|}
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
unit|};
name|bool
name|isBetterOverloadCandidate
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
specifier|const
name|OverloadCandidate
modifier|&
name|Cand1
parameter_list|,
specifier|const
name|OverloadCandidate
modifier|&
name|Cand2
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|UserDefinedConversion
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ConstructorInfo
block|{
name|DeclAccessPair
name|FoundDecl
decl_stmt|;
name|CXXConstructorDecl
modifier|*
name|Constructor
decl_stmt|;
name|FunctionTemplateDecl
modifier|*
name|ConstructorTmpl
decl_stmt|;
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Constructor
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|// FIXME: Add an AddOverloadCandidate / AddTemplateOverloadCandidate overload
end_comment

begin_comment
comment|// that takes one of these.
end_comment

begin_function
specifier|inline
name|ConstructorInfo
name|getConstructorInfo
parameter_list|(
name|NamedDecl
modifier|*
name|ND
parameter_list|)
block|{
if|if
condition|(
name|isa
operator|<
name|UsingDecl
operator|>
operator|(
name|ND
operator|)
condition|)
return|return
name|ConstructorInfo
block|{}
return|;
comment|// For constructors, the access check is performed against the underlying
comment|// declaration, not the found declaration.
name|auto
operator|*
name|D
operator|=
name|ND
operator|->
name|getUnderlyingDecl
argument_list|()
expr_stmt|;
name|ConstructorInfo
name|Info
init|=
block|{
name|DeclAccessPair
operator|::
name|make
argument_list|(
name|ND
argument_list|,
name|D
operator|->
name|getAccess
argument_list|()
argument_list|)
block|,
name|nullptr
block|,
name|nullptr
block|}
decl_stmt|;
name|Info
operator|.
name|ConstructorTmpl
operator|=
name|dyn_cast
operator|<
name|FunctionTemplateDecl
operator|>
operator|(
name|D
operator|)
expr_stmt|;
if|if
condition|(
name|Info
operator|.
name|ConstructorTmpl
condition|)
name|D
operator|=
name|Info
operator|.
name|ConstructorTmpl
operator|->
name|getTemplatedDecl
argument_list|()
expr_stmt|;
name|Info
operator|.
name|Constructor
operator|=
name|dyn_cast
operator|<
name|CXXConstructorDecl
operator|>
operator|(
name|D
operator|)
expr_stmt|;
return|return
name|Info
return|;
block|}
end_function

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_SEMA_OVERLOAD_H
end_comment

end_unit

