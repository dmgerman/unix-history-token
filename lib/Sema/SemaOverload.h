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
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
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
comment|///< Overload resoltuion refers to a deleted function.
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
name|ICK_NoReturn_Adjustment
block|,
comment|///< Removal of noreturn from a type (Clang)
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
comment|/// EllipsisConversion - When this is true, it means user-defined
comment|/// conversion sequence starts with a ... (elipsis) conversion, instead of
comment|/// a standard conversion. In this case, 'Before' field must be ignored.
comment|// FIXME. I much rather put this as the first field. But there seems to be
comment|// a gcc code gen. bug which causes a crash in a test. Putting it here seems
comment|// to work around the crash.
name|bool
name|EllipsisConversion
range|:
literal|1
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
comment|/// Represents an ambiguous user-defined conversion sequence.
struct|struct
name|AmbiguousConversionSequence
block|{
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|FunctionDecl
operator|*
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
name|D
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
name|suppressed_user
block|,
name|bad_qualifiers
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
literal|0
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
struct|struct
name|ImplicitConversionSequence
block|{
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
comment|/// ConversionKind - The kind of implicit conversion sequence.
name|Kind
name|ConversionKind
decl_stmt|;
name|void
name|setKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
if|if
condition|(
name|isAmbiguous
argument_list|()
condition|)
name|Ambiguous
operator|.
name|destruct
argument_list|()
expr_stmt|;
name|ConversionKind
operator|=
name|K
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
argument|BadConversion
argument_list|)
block|{}
operator|~
name|ImplicitConversionSequence
argument_list|()
block|{
if|if
condition|(
name|isAmbiguous
argument_list|()
condition|)
name|Ambiguous
operator|.
name|destruct
argument_list|()
expr_stmt|;
block|}
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
argument|Other.ConversionKind
argument_list|)
block|{
switch|switch
condition|(
name|ConversionKind
condition|)
block|{
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
if|if
condition|(
name|isAmbiguous
argument_list|()
condition|)
name|Ambiguous
operator|.
name|destruct
argument_list|()
expr_stmt|;
name|new
argument_list|(
argument|this
argument_list|)
name|ImplicitConversionSequence
argument_list|(
name|Other
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|Kind
name|getKind
argument_list|()
decl|const
block|{
return|return
name|ConversionKind
return|;
block|}
name|bool
name|isBad
argument_list|()
decl|const
block|{
return|return
name|ConversionKind
operator|==
name|BadConversion
return|;
block|}
name|bool
name|isStandard
argument_list|()
decl|const
block|{
return|return
name|ConversionKind
operator|==
name|StandardConversion
return|;
block|}
name|bool
name|isEllipsis
argument_list|()
decl|const
block|{
return|return
name|ConversionKind
operator|==
name|EllipsisConversion
return|;
block|}
name|bool
name|isAmbiguous
argument_list|()
decl|const
block|{
return|return
name|ConversionKind
operator|==
name|AmbiguousConversion
return|;
block|}
name|bool
name|isUserDefined
argument_list|()
decl|const
block|{
return|return
name|ConversionKind
operator|==
name|UserDefinedConversion
return|;
block|}
name|void
name|setBad
argument_list|()
block|{
name|setKind
argument_list|(
name|BadConversion
argument_list|)
expr_stmt|;
block|}
name|void
name|setStandard
argument_list|()
block|{
name|setKind
argument_list|(
name|StandardConversion
argument_list|)
expr_stmt|;
block|}
name|void
name|setEllipsis
argument_list|()
block|{
name|setKind
argument_list|(
name|EllipsisConversion
argument_list|)
expr_stmt|;
block|}
name|void
name|setUserDefined
argument_list|()
block|{
name|setKind
argument_list|(
name|UserDefinedConversion
argument_list|)
expr_stmt|;
block|}
name|void
name|setAmbiguous
argument_list|()
block|{
if|if
condition|(
name|isAmbiguous
argument_list|()
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
comment|// The result of a comparison between implicit conversion
comment|// sequences. Use Sema::CompareImplicitConversionSequences to
comment|// actually perform the comparison.
decl|enum
name|CompareKind
block|{
name|Better
operator|=
operator|-
literal|1
operator|,
name|Indistinguishable
operator|=
literal|0
operator|,
name|Worse
operator|=
literal|1
block|}
struct|;
name|void
name|DebugPrint
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_enum
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
comment|/// This conversion candidate is not viable because its result
comment|/// type is not implicitly convertible to the desired type.
name|ovl_fail_bad_final_conversion
block|}
enum|;
end_enum

begin_comment
comment|/// OverloadCandidate - A single candidate in an overload set (C++ 13.3).
end_comment

begin_struct
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
comment|/// FailureKind - The reason why this candidate is not viable.
comment|/// Actually an OverloadFailureKind.
name|unsigned
name|char
name|FailureKind
decl_stmt|;
comment|/// FinalConversion - For a conversion function (where Function is
comment|/// a CXXConversionDecl), the standard conversion that occurs
comment|/// after the call to the overload candidate to convert the result
comment|/// of calling the conversion function to the required type.
name|StandardConversionSequence
name|FinalConversion
decl_stmt|;
comment|/// hasAmbiguousConversion - Returns whether this overload
comment|/// candidate requires an ambiguous conversion or not.
name|bool
name|hasAmbiguousConversion
argument_list|()
specifier|const
block|{
for|for
control|(
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|ImplicitConversionSequence
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|Conversions
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|Conversions
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
if|if
condition|(
name|I
operator|->
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
end_struct

begin_comment
unit|};
comment|/// OverloadCandidateSet - A set of overload candidates, used in C++
end_comment

begin_comment
comment|/// overload resolution (C++ 13.3).
end_comment

begin_decl_stmt
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
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|OverloadCandidate
operator|,
literal|16
operator|>
name|inherited
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
comment|/// \brief Clear out all of the candidates.
name|void
name|clear
parameter_list|()
block|{
name|inherited
operator|::
name|clear
argument_list|()
expr_stmt|;
name|Functions
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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

