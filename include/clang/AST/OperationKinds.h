begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- OperationKinds.h - Operation enums -----------------------*- C++ -*-===//
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
comment|// This file enumerates the different kinds of operations that can be
end_comment

begin_comment
comment|// performed by various expressions.
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
name|LLVM_CLANG_AST_OPERATION_KINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_OPERATION_KINDS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// CastKind - the kind of cast this represents.
enum|enum
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
block|,
comment|/// \brief Converting between two Objective-C object types, which
comment|/// can occur when performing reference binding to an Objective-C
comment|/// object.
name|CK_ObjCObjectLValueCast
block|}
enum|;
enum|enum
name|BinaryOperatorKind
block|{
comment|// Operators listed in order of precedence.
comment|// Note that additions to this should also update the StmtVisitor class.
name|BO_PtrMemD
block|,
name|BO_PtrMemI
block|,
comment|// [C++ 5.5] Pointer-to-member operators.
name|BO_Mul
block|,
name|BO_Div
block|,
name|BO_Rem
block|,
comment|// [C99 6.5.5] Multiplicative operators.
name|BO_Add
block|,
name|BO_Sub
block|,
comment|// [C99 6.5.6] Additive operators.
name|BO_Shl
block|,
name|BO_Shr
block|,
comment|// [C99 6.5.7] Bitwise shift operators.
name|BO_LT
block|,
name|BO_GT
block|,
name|BO_LE
block|,
name|BO_GE
block|,
comment|// [C99 6.5.8] Relational operators.
name|BO_EQ
block|,
name|BO_NE
block|,
comment|// [C99 6.5.9] Equality operators.
name|BO_And
block|,
comment|// [C99 6.5.10] Bitwise AND operator.
name|BO_Xor
block|,
comment|// [C99 6.5.11] Bitwise XOR operator.
name|BO_Or
block|,
comment|// [C99 6.5.12] Bitwise OR operator.
name|BO_LAnd
block|,
comment|// [C99 6.5.13] Logical AND operator.
name|BO_LOr
block|,
comment|// [C99 6.5.14] Logical OR operator.
name|BO_Assign
block|,
name|BO_MulAssign
block|,
comment|// [C99 6.5.16] Assignment operators.
name|BO_DivAssign
block|,
name|BO_RemAssign
block|,
name|BO_AddAssign
block|,
name|BO_SubAssign
block|,
name|BO_ShlAssign
block|,
name|BO_ShrAssign
block|,
name|BO_AndAssign
block|,
name|BO_XorAssign
block|,
name|BO_OrAssign
block|,
name|BO_Comma
comment|// [C99 6.5.17] Comma operator.
block|}
enum|;
enum|enum
name|UnaryOperatorKind
block|{
comment|// Note that additions to this should also update the StmtVisitor class.
name|UO_PostInc
block|,
name|UO_PostDec
block|,
comment|// [C99 6.5.2.4] Postfix increment and decrement
name|UO_PreInc
block|,
name|UO_PreDec
block|,
comment|// [C99 6.5.3.1] Prefix increment and decrement
name|UO_AddrOf
block|,
name|UO_Deref
block|,
comment|// [C99 6.5.3.2] Address and indirection
name|UO_Plus
block|,
name|UO_Minus
block|,
comment|// [C99 6.5.3.3] Unary arithmetic
name|UO_Not
block|,
name|UO_LNot
block|,
comment|// [C99 6.5.3.3] Unary arithmetic
name|UO_Real
block|,
name|UO_Imag
block|,
comment|// "__real expr"/"__imag expr" Extension.
name|UO_Extension
comment|// __extension__ marker.
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

