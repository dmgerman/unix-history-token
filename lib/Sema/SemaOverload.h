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
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXConstructorDecl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
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
name|ICK_Complex_Real
block|,
comment|///< Complex-real conversions (C99 6.3.1.7)
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
name|ICK_Num_Conversion_Kinds
comment|///< The number of conversion kinds
block|}
enum|;
comment|/// ImplicitConversionCategory - The category of an implicit
comment|/// conversion kind. The enumerator values match with Table 9 of
comment|/// (C++ 13.3.3.1.1) and are listed such that better conversion
comment|/// categories have smaller values.
enum|enum
name|ImplicitConversionCategory
block|{
name|ICC_Identity
init|=
literal|0
block|,
comment|///< Identity
name|ICC_Lvalue_Transformation
block|,
comment|///< Lvalue transformation
name|ICC_Qualification_Adjustment
block|,
comment|///< Qualification adjustment
name|ICC_Promotion
block|,
comment|///< Promotion
name|ICC_Conversion
comment|///< Conversion
block|}
enum|;
name|ImplicitConversionCategory
name|GetConversionCategory
parameter_list|(
name|ImplicitConversionKind
name|Kind
parameter_list|)
function_decl|;
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
comment|///< Conversion
block|}
enum|;
name|ImplicitConversionRank
name|GetConversionRank
parameter_list|(
name|ImplicitConversionKind
name|Kind
parameter_list|)
function_decl|;
comment|/// StandardConversionSequence - represents a standard conversion
comment|/// sequence (C++ 13.3.3.1.1). A standard conversion sequence
comment|/// contains between zero and three conversions. If a particular
comment|/// conversion is not needed, it will be set to the identity conversion
comment|/// (ICK_Identity). Note that the three conversions are
comment|/// specified as separate members (rather than in an array) so that
comment|/// we can keep the size of a standard conversion sequence to a
comment|/// single word.
struct|struct
name|StandardConversionSequence
block|{
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
comment|/// Third - The third conversion can be a qualification conversion.
name|ImplicitConversionKind
name|Third
range|:
literal|8
decl_stmt|;
comment|/// Deprecated - Whether this the deprecated conversion of a
comment|/// string literal to a pointer to non-const character data
comment|/// (C++ 4.2p2).
name|bool
name|Deprecated
range|:
literal|1
decl_stmt|;
comment|/// IncompatibleObjC - Whether this is an Objective-C conversion
comment|/// that we should warn about (if we actually use it).
name|bool
name|IncompatibleObjC
range|:
literal|1
decl_stmt|;
comment|/// ReferenceBinding - True when this is a reference binding
comment|/// (C++ [over.ics.ref]).
name|bool
name|ReferenceBinding
range|:
literal|1
decl_stmt|;
comment|/// DirectBinding - True when this is a reference binding that is a
comment|/// direct binding (C++ [dcl.init.ref]).
name|bool
name|DirectBinding
range|:
literal|1
decl_stmt|;
comment|/// RRefBinding - True when this is a reference binding of an rvalue
comment|/// reference to an rvalue (C++0x [over.ics.rank]p3b4).
name|bool
name|RRefBinding
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
comment|/// ToType - The type that this conversion is converting to. This
comment|/// is an opaque pointer that can be translated into a QualType.
name|void
modifier|*
name|ToTypePtr
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
name|void
name|setAsIdentityConversion
parameter_list|()
function_decl|;
name|ImplicitConversionRank
name|getRank
argument_list|()
specifier|const
expr_stmt|;
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
name|DebugPrint
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
comment|/// UserDefinedConversionSequence - Represents a user-defined
comment|/// conversion sequence (C++ 13.3.3.1.2).
struct|struct
name|UserDefinedConversionSequence
block|{
comment|/// Before - Represents the standard conversion that occurs before
comment|/// the actual user-defined conversion. (C++ 13.3.3.1.2p1):
comment|///
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
comment|/// After - Represents the standard conversion that occurs after
comment|/// the actual user-defined conversion.
name|StandardConversionSequence
name|After
decl_stmt|;
comment|/// ConversionFunction - The function that will perform the
comment|/// user-defined conversion.
name|FunctionDecl
modifier|*
name|ConversionFunction
decl_stmt|;
name|void
name|DebugPrint
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
comment|/// ImplicitConversionSequence - Represents an implicit conversion
comment|/// sequence, which may be a standard conversion sequence
comment|/// (C++ 13.3.3.1.1), user-defined conversion sequence (C++ 13.3.3.1.2),
comment|/// or an ellipsis conversion sequence (C++ 13.3.3.1.3).
struct|struct
name|ImplicitConversionSequence
block|{
comment|/// Kind - The kind of implicit conversion sequence. BadConversion
comment|/// specifies that there is no conversion from the source type to
comment|/// the target type. The enumerator values are ordered such that
comment|/// better implicit conversions have smaller values.
enum|enum
name|Kind
block|{
name|StandardConversion
init|=
literal|0
block|,
name|UserDefinedConversion
block|,
name|EllipsisConversion
block|,
name|BadConversion
block|}
enum|;
comment|/// ConversionKind - The kind of implicit conversion sequence.
name|Kind
name|ConversionKind
decl_stmt|;
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
block|}
union|;
comment|/// When ConversionKind == BadConversion due to multiple conversion
comment|/// functions, this will list those functions.
name|llvm
operator|::
name|SmallVector
operator|<
name|FunctionDecl
operator|*
operator|,
literal|4
operator|>
name|ConversionFunctionSet
expr_stmt|;
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
name|DebugPrint
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
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
comment|// BuiltinTypes - Provides the return and parameter types of a
comment|// built-in overload candidate. Only valid when Function is NULL.
struct|struct
block|{
name|QualType
name|ResultTy
decl_stmt|;
name|QualType
name|ParamTypes
index|[
literal|3
index|]
decl_stmt|;
block|}
name|BuiltinTypes
struct|;
comment|/// Surrogate - The conversion function for which this candidate
comment|/// is a surrogate, but only if IsSurrogate is true.
name|CXXConversionDecl
modifier|*
name|Surrogate
decl_stmt|;
comment|/// Conversions - The conversion sequences used to convert the
comment|/// function arguments to the function parameters.
name|llvm
operator|::
name|SmallVector
operator|<
name|ImplicitConversionSequence
operator|,
literal|4
operator|>
name|Conversions
expr_stmt|;
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
comment|/// FinalConversion - For a conversion function (where Function is
comment|/// a CXXConversionDecl), the standard conversion that occurs
comment|/// after the call to the overload candidate to convert the result
comment|/// of calling the conversion function to the required type.
name|StandardConversionSequence
name|FinalConversion
decl_stmt|;
block|}
struct|;
comment|/// OverloadCandidateSet - A set of overload candidates, used in C++
comment|/// overload resolution (C++ 13.3).
name|class
name|OverloadCandidateSet
range|:
name|public
name|llvm
operator|::
name|SmallVector
operator|<
name|OverloadCandidate
decl_stmt|, 16>
block|{
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
name|public
label|:
comment|/// \brief Determine when this overload candidate will be new to the
comment|/// overload set.
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
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
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

