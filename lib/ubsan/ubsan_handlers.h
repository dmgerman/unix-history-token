begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ubsan_handlers.h ----------------------------------------*- C++ -*-===//
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
comment|// Entry points to the runtime library for Clang's undefined behavior sanitizer.
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
name|UBSAN_HANDLERS_H
end_ifndef

begin_define
define|#
directive|define
name|UBSAN_HANDLERS_H
end_define

begin_include
include|#
directive|include
file|"ubsan_value.h"
end_include

begin_decl_stmt
name|namespace
name|__ubsan
block|{
struct|struct
name|TypeMismatchData
block|{
name|SourceLocation
name|Loc
decl_stmt|;
specifier|const
name|TypeDescriptor
modifier|&
name|Type
decl_stmt|;
name|uptr
name|Alignment
decl_stmt|;
name|unsigned
name|char
name|TypeCheckKind
decl_stmt|;
block|}
struct|;
define|#
directive|define
name|RECOVERABLE
parameter_list|(
name|checkname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|extern "C" SANITIZER_INTERFACE_ATTRIBUTE \     void __ubsan_handle_ ## checkname( __VA_ARGS__ ); \   extern "C" SANITIZER_INTERFACE_ATTRIBUTE \     void __ubsan_handle_ ## checkname ## _abort( __VA_ARGS__ );
comment|/// \brief Handle a runtime type check failure, caused by either a misaligned
comment|/// pointer, a null pointer, or a pointer to insufficient storage for the
comment|/// type.
name|RECOVERABLE
argument_list|(
argument|type_mismatch
argument_list|,
argument|TypeMismatchData *Data
argument_list|,
argument|ValueHandle Pointer
argument_list|)
struct|struct
name|OverflowData
block|{
name|SourceLocation
name|Loc
decl_stmt|;
specifier|const
name|TypeDescriptor
modifier|&
name|Type
decl_stmt|;
block|}
struct|;
comment|/// \brief Handle an integer addition overflow.
name|RECOVERABLE
argument_list|(
argument|add_overflow
argument_list|,
argument|OverflowData *Data
argument_list|,
argument|ValueHandle LHS
argument_list|,
argument|ValueHandle RHS
argument_list|)
comment|/// \brief Handle an integer subtraction overflow.
name|RECOVERABLE
argument_list|(
argument|sub_overflow
argument_list|,
argument|OverflowData *Data
argument_list|,
argument|ValueHandle LHS
argument_list|,
argument|ValueHandle RHS
argument_list|)
comment|/// \brief Handle an integer multiplication overflow.
name|RECOVERABLE
argument_list|(
argument|mul_overflow
argument_list|,
argument|OverflowData *Data
argument_list|,
argument|ValueHandle LHS
argument_list|,
argument|ValueHandle RHS
argument_list|)
comment|/// \brief Handle a signed integer overflow for a unary negate operator.
name|RECOVERABLE
argument_list|(
argument|negate_overflow
argument_list|,
argument|OverflowData *Data
argument_list|,
argument|ValueHandle OldVal
argument_list|)
comment|/// \brief Handle an INT_MIN/-1 overflow or division by zero.
name|RECOVERABLE
argument_list|(
argument|divrem_overflow
argument_list|,
argument|OverflowData *Data
argument_list|,
argument|ValueHandle LHS
argument_list|,
argument|ValueHandle RHS
argument_list|)
struct|struct
name|ShiftOutOfBoundsData
block|{
name|SourceLocation
name|Loc
decl_stmt|;
specifier|const
name|TypeDescriptor
modifier|&
name|LHSType
decl_stmt|;
specifier|const
name|TypeDescriptor
modifier|&
name|RHSType
decl_stmt|;
block|}
struct|;
comment|/// \brief Handle a shift where the RHS is out of bounds or a left shift where
comment|/// the LHS is negative or overflows.
name|RECOVERABLE
argument_list|(
argument|shift_out_of_bounds
argument_list|,
argument|ShiftOutOfBoundsData *Data
argument_list|,
argument|ValueHandle LHS
argument_list|,
argument|ValueHandle RHS
argument_list|)
struct|struct
name|OutOfBoundsData
block|{
name|SourceLocation
name|Loc
decl_stmt|;
specifier|const
name|TypeDescriptor
modifier|&
name|ArrayType
decl_stmt|;
specifier|const
name|TypeDescriptor
modifier|&
name|IndexType
decl_stmt|;
block|}
struct|;
comment|/// \brief Handle an array index out of bounds error.
name|RECOVERABLE
argument_list|(
argument|out_of_bounds
argument_list|,
argument|OutOfBoundsData *Data
argument_list|,
argument|ValueHandle Index
argument_list|)
struct|struct
name|UnreachableData
block|{
name|SourceLocation
name|Loc
decl_stmt|;
block|}
struct|;
comment|/// \brief Handle a __builtin_unreachable which is reached.
extern|extern
literal|"C"
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__ubsan_handle_builtin_unreachable
parameter_list|(
name|UnreachableData
modifier|*
name|Data
parameter_list|)
function_decl|;
comment|/// \brief Handle reaching the end of a value-returning function.
extern|extern
literal|"C"
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__ubsan_handle_missing_return
parameter_list|(
name|UnreachableData
modifier|*
name|Data
parameter_list|)
function_decl|;
struct|struct
name|VLABoundData
block|{
name|SourceLocation
name|Loc
decl_stmt|;
specifier|const
name|TypeDescriptor
modifier|&
name|Type
decl_stmt|;
block|}
struct|;
comment|/// \brief Handle a VLA with a non-positive bound.
name|RECOVERABLE
argument_list|(
argument|vla_bound_not_positive
argument_list|,
argument|VLABoundData *Data
argument_list|,
argument|ValueHandle Bound
argument_list|)
struct|struct
name|FloatCastOverflowData
block|{
comment|// FIXME: SourceLocation Loc;
specifier|const
name|TypeDescriptor
modifier|&
name|FromType
decl_stmt|;
specifier|const
name|TypeDescriptor
modifier|&
name|ToType
decl_stmt|;
block|}
struct|;
comment|/// \brief Handle overflow in a conversion to or from a floating-point type.
name|RECOVERABLE
argument_list|(
argument|float_cast_overflow
argument_list|,
argument|FloatCastOverflowData *Data
argument_list|,
argument|ValueHandle From
argument_list|)
struct|struct
name|InvalidValueData
block|{
name|SourceLocation
name|Loc
decl_stmt|;
specifier|const
name|TypeDescriptor
modifier|&
name|Type
decl_stmt|;
block|}
struct|;
comment|/// \brief Handle a load of an invalid value for the type.
name|RECOVERABLE
argument_list|(
argument|load_invalid_value
argument_list|,
argument|InvalidValueData *Data
argument_list|,
argument|ValueHandle Val
argument_list|)
struct|struct
name|FunctionTypeMismatchData
block|{
name|SourceLocation
name|Loc
decl_stmt|;
specifier|const
name|TypeDescriptor
modifier|&
name|Type
decl_stmt|;
block|}
struct|;
name|RECOVERABLE
argument_list|(
argument|function_type_mismatch
argument_list|,
argument|FunctionTypeMismatchData *Data
argument_list|,
argument|ValueHandle Val
argument_list|)
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// UBSAN_HANDLERS_H
end_comment

end_unit

