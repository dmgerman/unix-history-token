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
comment|/// CastKind - The kind of operation required for a conversion.
enum|enum
name|CastKind
block|{
comment|/// CK_Dependent - A conversion which cannot yet be analyzed because
comment|/// either the expression or target type is dependent.  These are
comment|/// created only for explicit casts; dependent ASTs aren't required
comment|/// to even approximately type-check.
comment|///   (T*) malloc(sizeof(T))
comment|///   reinterpret_cast<intptr_t>(A<T>::alloc());
name|CK_Dependent
block|,
comment|/// CK_BitCast - A conversion which causes a bit pattern of one type
comment|/// to be reinterpreted as a bit pattern of another type.  Generally
comment|/// the operands must have equivalent size and unrelated types.
comment|///
comment|/// The pointer conversion char* -> int* is a bitcast.  A conversion
comment|/// from any pointer type to a C pointer type is a bitcast unless
comment|/// it's actually BaseToDerived or DerivedToBase.  A conversion to a
comment|/// block pointer or ObjC pointer type is a bitcast only if the
comment|/// operand has the same type kind; otherwise, it's one of the
comment|/// specialized casts below.
comment|///
comment|/// Vector coercions are bitcasts.
name|CK_BitCast
block|,
comment|/// CK_LValueBitCast - A conversion which reinterprets the address of
comment|/// an l-value as an l-value of a different kind.  Used for
comment|/// reinterpret_casts of l-value expressions to reference types.
comment|///    bool b; reinterpret_cast<char&>(b) = 'a';
name|CK_LValueBitCast
block|,
comment|/// CK_LValueToRValue - A conversion which causes the extraction of
comment|/// an r-value from the operand gl-value.  The result of an r-value
comment|/// conversion is always unqualified.
name|CK_LValueToRValue
block|,
comment|/// CK_NoOp - A conversion which does not affect the type other than
comment|/// (possibly) adding qualifiers.
comment|///   int    -> int
comment|///   char** -> const char * const *
name|CK_NoOp
block|,
comment|/// CK_BaseToDerived - A conversion from a C++ class pointer/reference
comment|/// to a derived class pointer/reference.
comment|///   B *b = static_cast<B*>(a);
name|CK_BaseToDerived
block|,
comment|/// CK_DerivedToBase - A conversion from a C++ class pointer
comment|/// to a base class pointer.
comment|///   A *a = new B();
name|CK_DerivedToBase
block|,
comment|/// CK_UncheckedDerivedToBase - A conversion from a C++ class
comment|/// pointer/reference to a base class that can assume that the
comment|/// derived pointer is not null.
comment|///   const A&a = B();
comment|///   b->method_from_a();
name|CK_UncheckedDerivedToBase
block|,
comment|/// CK_Dynamic - A C++ dynamic_cast.
name|CK_Dynamic
block|,
comment|/// CK_ToUnion - The GCC cast-to-union extension.
comment|///   int   -> union { int x; float y; }
comment|///   float -> union { int x; float y; }
name|CK_ToUnion
block|,
comment|/// CK_ArrayToPointerDecay - Array to pointer decay.
comment|///   int[10] -> int*
comment|///   char[5][6] -> char(*)[6]
name|CK_ArrayToPointerDecay
block|,
comment|/// CK_FunctionToPointerDecay - Function to pointer decay.
comment|///   void(int) -> void(*)(int)
name|CK_FunctionToPointerDecay
block|,
comment|/// CK_NullToPointer - Null pointer constant to pointer, ObjC
comment|/// pointer, or block pointer.
comment|///   (void*) 0
comment|///   void (^block)() = 0;
name|CK_NullToPointer
block|,
comment|/// CK_NullToMemberPointer - Null pointer constant to member pointer.
comment|///   int A::*mptr = 0;
comment|///   int (A::*fptr)(int) = nullptr;
name|CK_NullToMemberPointer
block|,
comment|/// CK_BaseToDerivedMemberPointer - Member pointer in base class to
comment|/// member pointer in derived class.
comment|///   int B::*mptr =&A::member;
name|CK_BaseToDerivedMemberPointer
block|,
comment|/// CK_DerivedToBaseMemberPointer - Member pointer in derived class to
comment|/// member pointer in base class.
comment|///   int A::*mptr = static_cast<int A::*>(&B::member);
name|CK_DerivedToBaseMemberPointer
block|,
comment|/// CK_MemberPointerToBoolean - Member pointer to boolean.  A check
comment|/// against the null member pointer.
name|CK_MemberPointerToBoolean
block|,
comment|/// CK_ReinterpretMemberPointer - Reinterpret a member pointer as a
comment|/// different kind of member pointer.  C++ forbids this from
comment|/// crossing between function and object types, but otherwise does
comment|/// not restrict it.  However, the only operation that is permitted
comment|/// on a "punned" member pointer is casting it back to the original
comment|/// type, which is required to be a lossless operation (although
comment|/// many ABIs do not guarantee this on all possible intermediate types).
name|CK_ReinterpretMemberPointer
block|,
comment|/// CK_UserDefinedConversion - Conversion using a user defined type
comment|/// conversion function.
comment|///    struct A { operator int(); }; int i = int(A());
name|CK_UserDefinedConversion
block|,
comment|/// CK_ConstructorConversion - Conversion by constructor.
comment|///    struct A { A(int); }; A a = A(10);
name|CK_ConstructorConversion
block|,
comment|/// CK_IntegralToPointer - Integral to pointer.  A special kind of
comment|/// reinterpreting conversion.  Applies to normal, ObjC, and block
comment|/// pointers.
comment|///    (char*) 0x1001aab0
comment|///    reinterpret_cast<int*>(0)
name|CK_IntegralToPointer
block|,
comment|/// CK_PointerToIntegral - Pointer to integral.  A special kind of
comment|/// reinterpreting conversion.  Applies to normal, ObjC, and block
comment|/// pointers.
comment|///    (intptr_t) "help!"
name|CK_PointerToIntegral
block|,
comment|/// CK_PointerToBoolean - Pointer to boolean conversion.  A check
comment|/// against null.  Applies to normal, ObjC, and block pointers.
name|CK_PointerToBoolean
block|,
comment|/// CK_ToVoid - Cast to void, discarding the computed value.
comment|///    (void) malloc(2048)
name|CK_ToVoid
block|,
comment|/// CK_VectorSplat - A conversion from an arithmetic type to a
comment|/// vector of that element type.  Fills all elements ("splats") with
comment|/// the source value.
comment|///    __attribute__((ext_vector_type(4))) int v = 5;
name|CK_VectorSplat
block|,
comment|/// CK_IntegralCast - A cast between integral types (other than to
comment|/// boolean).  Variously a bitcast, a truncation, a sign-extension,
comment|/// or a zero-extension.
comment|///    long l = 5;
comment|///    (unsigned) i
name|CK_IntegralCast
block|,
comment|/// CK_IntegralToBoolean - Integral to boolean.  A check against zero.
comment|///    (bool) i
name|CK_IntegralToBoolean
block|,
comment|/// CK_IntegralToFloating - Integral to floating point.
comment|///    float f = i;
name|CK_IntegralToFloating
block|,
comment|/// CK_FloatingToIntegral - Floating point to integral.  Rounds
comment|/// towards zero, discarding any fractional component.
comment|///    (int) f
name|CK_FloatingToIntegral
block|,
comment|/// CK_FloatingToBoolean - Floating point to boolean.
comment|///    (bool) f
name|CK_FloatingToBoolean
block|,
comment|/// CK_FloatingCast - Casting between floating types of different size.
comment|///    (double) f
comment|///    (float) ld
name|CK_FloatingCast
block|,
comment|/// CK_CPointerToObjCPointerCast - Casting a C pointer kind to an
comment|/// Objective-C pointer.
name|CK_CPointerToObjCPointerCast
block|,
comment|/// CK_BlockPointerToObjCPointerCast - Casting a block pointer to an
comment|/// ObjC pointer.
name|CK_BlockPointerToObjCPointerCast
block|,
comment|/// CK_AnyPointerToBlockPointerCast - Casting any non-block pointer
comment|/// to a block pointer.  Block-to-block casts are bitcasts.
name|CK_AnyPointerToBlockPointerCast
block|,
comment|/// \brief Converting between two Objective-C object types, which
comment|/// can occur when performing reference binding to an Objective-C
comment|/// object.
name|CK_ObjCObjectLValueCast
block|,
comment|/// \brief A conversion of a floating point real to a floating point
comment|/// complex of the original type.  Injects the value as the real
comment|/// component with a zero imaginary component.
comment|///   float -> _Complex float
name|CK_FloatingRealToComplex
block|,
comment|/// \brief Converts a floating point complex to floating point real
comment|/// of the source's element type.  Just discards the imaginary
comment|/// component.
comment|///   _Complex long double -> long double
name|CK_FloatingComplexToReal
block|,
comment|/// \brief Converts a floating point complex to bool by comparing
comment|/// against 0+0i.
name|CK_FloatingComplexToBoolean
block|,
comment|/// \brief Converts between different floating point complex types.
comment|///   _Complex float -> _Complex double
name|CK_FloatingComplexCast
block|,
comment|/// \brief Converts from a floating complex to an integral complex.
comment|///   _Complex float -> _Complex int
name|CK_FloatingComplexToIntegralComplex
block|,
comment|/// \brief Converts from an integral real to an integral complex
comment|/// whose element type matches the source.  Injects the value as
comment|/// the real component with a zero imaginary component.
comment|///   long -> _Complex long
name|CK_IntegralRealToComplex
block|,
comment|/// \brief Converts an integral complex to an integral real of the
comment|/// source's element type by discarding the imaginary component.
comment|///   _Complex short -> short
name|CK_IntegralComplexToReal
block|,
comment|/// \brief Converts an integral complex to bool by comparing against
comment|/// 0+0i.
name|CK_IntegralComplexToBoolean
block|,
comment|/// \brief Converts between different integral complex types.
comment|///   _Complex char -> _Complex long long
comment|///   _Complex unsigned int -> _Complex signed int
name|CK_IntegralComplexCast
block|,
comment|/// \brief Converts from an integral complex to a floating complex.
comment|///   _Complex unsigned -> _Complex float
name|CK_IntegralComplexToFloatingComplex
block|,
comment|/// \brief [ARC] Produces a retainable object pointer so that it may
comment|/// be consumed, e.g. by being passed to a consuming parameter.
comment|/// Calls objc_retain.
name|CK_ARCProduceObject
block|,
comment|/// \brief [ARC] Consumes a retainable object pointer that has just
comment|/// been produced, e.g. as the return value of a retaining call.
comment|/// Enters a cleanup to call objc_release at some indefinite time.
name|CK_ARCConsumeObject
block|,
comment|/// \brief [ARC] Reclaim a retainable object pointer object that may
comment|/// have been produced and autoreleased as part of a function return
comment|/// sequence.
name|CK_ARCReclaimReturnedObject
block|,
comment|/// \brief [ARC] Causes a value of block type to be copied to the
comment|/// heap, if it is not already there.  A number of other operations
comment|/// in ARC cause blocks to be copied; this is for cases where that
comment|/// would not otherwise be guaranteed, such as when casting to a
comment|/// non-block pointer type.
name|CK_ARCExtendBlockObject
block|,
comment|/// \brief Converts from _Atomic(T) to T.
name|CK_AtomicToNonAtomic
block|,
comment|/// \brief Converts from T to _Atomic(T).
name|CK_NonAtomicToAtomic
block|,
comment|/// \brief Causes a block literal to by copied to the heap and then
comment|/// autoreleased.
comment|///
comment|/// This particular cast kind is used for the conversion from a C++11
comment|/// lambda expression to a block pointer.
name|CK_CopyAndAutoreleaseBlockObject
block|,
comment|// Convert a builtin function to a function pointer; only allowed in the
comment|// callee of a call expression.
name|CK_BuiltinFnToFnPtr
block|,
comment|// Convert a zero value for OpenCL event_t initialization.
name|CK_ZeroToOCLEvent
block|,
comment|// Convert a pointer to a different address space.
name|CK_AddressSpaceConversion
block|}
enum|;
specifier|static
specifier|const
name|CastKind
name|CK_Invalid
init|=
name|static_cast
operator|<
name|CastKind
operator|>
operator|(
operator|-
literal|1
operator|)
decl_stmt|;
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
comment|/// \brief The kind of bridging performed by the Objective-C bridge cast.
enum|enum
name|ObjCBridgeCastKind
block|{
comment|/// \brief Bridging via __bridge, which does nothing but reinterpret
comment|/// the bits.
name|OBC_Bridge
block|,
comment|/// \brief Bridging via __bridge_transfer, which transfers ownership of an
comment|/// Objective-C pointer into ARC.
name|OBC_BridgeTransfer
block|,
comment|/// \brief Bridging via __bridge_retain, which makes an ARC object available
comment|/// as a +1 C pointer.
name|OBC_BridgeRetained
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

