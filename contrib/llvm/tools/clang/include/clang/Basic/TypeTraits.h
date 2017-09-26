begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TypeTraits.h - C++ Type Traits Support Enumerations ----*- C++ -*-===//
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
comment|/// \brief Defines enumerations for the type traits support.
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
name|LLVM_CLANG_BASIC_TYPETRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_TYPETRAITS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Names for traits that operate specifically on types.
enum|enum
name|TypeTrait
block|{
name|UTT_HasNothrowAssign
block|,
name|UTT_HasNothrowMoveAssign
block|,
name|UTT_HasNothrowCopy
block|,
name|UTT_HasNothrowConstructor
block|,
name|UTT_HasTrivialAssign
block|,
name|UTT_HasTrivialMoveAssign
block|,
name|UTT_HasTrivialCopy
block|,
name|UTT_HasTrivialDefaultConstructor
block|,
name|UTT_HasTrivialMoveConstructor
block|,
name|UTT_HasTrivialDestructor
block|,
name|UTT_HasVirtualDestructor
block|,
name|UTT_IsAbstract
block|,
name|UTT_IsAggregate
block|,
name|UTT_IsArithmetic
block|,
name|UTT_IsArray
block|,
name|UTT_IsClass
block|,
name|UTT_IsCompleteType
block|,
name|UTT_IsCompound
block|,
name|UTT_IsConst
block|,
name|UTT_IsDestructible
block|,
name|UTT_IsEmpty
block|,
name|UTT_IsEnum
block|,
name|UTT_IsFinal
block|,
name|UTT_IsFloatingPoint
block|,
name|UTT_IsFunction
block|,
name|UTT_IsFundamental
block|,
name|UTT_IsIntegral
block|,
name|UTT_IsInterfaceClass
block|,
name|UTT_IsLiteral
block|,
name|UTT_IsLvalueReference
block|,
name|UTT_IsMemberFunctionPointer
block|,
name|UTT_IsMemberObjectPointer
block|,
name|UTT_IsMemberPointer
block|,
name|UTT_IsNothrowDestructible
block|,
name|UTT_IsObject
block|,
name|UTT_IsPOD
block|,
name|UTT_IsPointer
block|,
name|UTT_IsPolymorphic
block|,
name|UTT_IsReference
block|,
name|UTT_IsRvalueReference
block|,
name|UTT_IsScalar
block|,
name|UTT_IsSealed
block|,
name|UTT_IsSigned
block|,
name|UTT_IsStandardLayout
block|,
name|UTT_IsTrivial
block|,
name|UTT_IsTriviallyCopyable
block|,
name|UTT_IsTriviallyDestructible
block|,
name|UTT_IsUnion
block|,
name|UTT_IsUnsigned
block|,
name|UTT_IsVoid
block|,
name|UTT_IsVolatile
block|,
name|UTT_Last
init|=
name|UTT_IsVolatile
block|,
name|BTT_IsBaseOf
block|,
name|BTT_IsConvertible
block|,
name|BTT_IsConvertibleTo
block|,
name|BTT_IsSame
block|,
name|BTT_TypeCompatible
block|,
name|BTT_IsAssignable
block|,
name|BTT_IsNothrowAssignable
block|,
name|BTT_IsTriviallyAssignable
block|,
name|BTT_Last
init|=
name|BTT_IsTriviallyAssignable
block|,
name|TT_IsConstructible
block|,
name|TT_IsNothrowConstructible
block|,
name|TT_IsTriviallyConstructible
block|}
enum|;
comment|/// \brief Names for the array type traits.
enum|enum
name|ArrayTypeTrait
block|{
name|ATT_ArrayRank
block|,
name|ATT_ArrayExtent
block|}
enum|;
comment|/// \brief Names for the "expression or type" traits.
enum|enum
name|UnaryExprOrTypeTrait
block|{
name|UETT_SizeOf
block|,
name|UETT_AlignOf
block|,
name|UETT_VecStep
block|,
name|UETT_OpenMPRequiredSimdAlign
block|,   }
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

