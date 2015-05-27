begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ubsan_value.h -------------------------------------------*- C++ -*-===//
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
comment|// Representation of data which is passed from the compiler-generated calls into
end_comment

begin_comment
comment|// the ubsan runtime.
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
name|UBSAN_VALUE_H
end_ifndef

begin_define
define|#
directive|define
name|UBSAN_VALUE_H
end_define

begin_comment
comment|// For now, only support Linux, FreeBSD and Darwin. Other platforms should
end_comment

begin_comment
comment|// be easy to add, and probably work as-is.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"UBSan not supported for this platform!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_atomic.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_comment
comment|// FIXME: Move this out to a config header.
end_comment

begin_if
if|#
directive|if
name|__SIZEOF_INT128__
end_if

begin_macro
name|__extension__
end_macro

begin_typedef
typedef|typedef
name|__int128
name|s128
typedef|;
end_typedef

begin_macro
name|__extension__
end_macro

begin_typedef
typedef|typedef
name|unsigned
name|__int128
name|u128
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_INT128_T
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_INT128_T
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|__ubsan
block|{
comment|/// \brief Largest integer types we support.
if|#
directive|if
name|HAVE_INT128_T
typedef|typedef
name|s128
name|SIntMax
typedef|;
typedef|typedef
name|u128
name|UIntMax
typedef|;
else|#
directive|else
typedef|typedef
name|s64
name|SIntMax
typedef|;
typedef|typedef
name|u64
name|UIntMax
typedef|;
endif|#
directive|endif
comment|/// \brief Largest floating-point type we support.
typedef|typedef
name|long
name|double
name|FloatMax
typedef|;
comment|/// \brief A description of a source location. This corresponds to Clang's
comment|/// \c PresumedLoc type.
name|class
name|SourceLocation
block|{
specifier|const
name|char
modifier|*
name|Filename
decl_stmt|;
name|u32
name|Line
decl_stmt|;
name|u32
name|Column
decl_stmt|;
name|public
label|:
name|SourceLocation
argument_list|()
operator|:
name|Filename
argument_list|()
operator|,
name|Line
argument_list|()
operator|,
name|Column
argument_list|()
block|{}
name|SourceLocation
argument_list|(
argument|const char *Filename
argument_list|,
argument|unsigned Line
argument_list|,
argument|unsigned Column
argument_list|)
operator|:
name|Filename
argument_list|(
name|Filename
argument_list|)
operator|,
name|Line
argument_list|(
name|Line
argument_list|)
operator|,
name|Column
argument_list|(
argument|Column
argument_list|)
block|{}
comment|/// \brief Determine whether the source location is known.
name|bool
name|isInvalid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Filename
return|;
block|}
comment|/// \brief Atomically acquire a copy, disabling original in-place.
comment|/// Exactly one call to acquire() returns a copy that isn't disabled.
name|SourceLocation
name|acquire
parameter_list|()
block|{
name|u32
name|OldColumn
init|=
name|__sanitizer
operator|::
name|atomic_exchange
argument_list|(
operator|(
name|__sanitizer
operator|::
name|atomic_uint32_t
operator|*
operator|)
operator|&
name|Column
argument_list|,
operator|~
name|u32
argument_list|(
literal|0
argument_list|)
argument_list|,
name|__sanitizer
operator|::
name|memory_order_relaxed
argument_list|)
decl_stmt|;
return|return
name|SourceLocation
argument_list|(
name|Filename
argument_list|,
name|Line
argument_list|,
name|OldColumn
argument_list|)
return|;
block|}
comment|/// \brief Determine if this Location has been disabled.
comment|/// Disabled SourceLocations are invalid to use.
name|bool
name|isDisabled
parameter_list|()
block|{
return|return
name|Column
operator|==
operator|~
name|u32
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// \brief Get the presumed filename for the source location.
specifier|const
name|char
operator|*
name|getFilename
argument_list|()
specifier|const
block|{
return|return
name|Filename
return|;
block|}
comment|/// \brief Get the presumed line number.
name|unsigned
name|getLine
argument_list|()
specifier|const
block|{
return|return
name|Line
return|;
block|}
comment|/// \brief Get the column within the presumed line.
name|unsigned
name|getColumn
argument_list|()
specifier|const
block|{
return|return
name|Column
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief A description of a type.
name|class
name|TypeDescriptor
block|{
comment|/// A value from the \c Kind enumeration, specifying what flavor of type we
comment|/// have.
name|u16
name|TypeKind
decl_stmt|;
comment|/// A \c Type-specific value providing information which allows us to
comment|/// interpret the meaning of a ValueHandle of this type.
name|u16
name|TypeInfo
decl_stmt|;
comment|/// The name of the type follows, in a format suitable for including in
comment|/// diagnostics.
name|char
name|TypeName
index|[
literal|1
index|]
decl_stmt|;
name|public
label|:
enum|enum
name|Kind
block|{
comment|/// An integer type. Lowest bit is 1 for a signed value, 0 for an unsigned
comment|/// value. Remaining bits are log_2(bit width). The value representation is
comment|/// the integer itself if it fits into a ValueHandle, and a pointer to the
comment|/// integer otherwise.
name|TK_Integer
init|=
literal|0x0000
block|,
comment|/// A floating-point type. Low 16 bits are bit width. The value
comment|/// representation is that of bitcasting the floating-point value to an
comment|/// integer type.
name|TK_Float
init|=
literal|0x0001
block|,
comment|/// Any other type. The value representation is unspecified.
name|TK_Unknown
init|=
literal|0xffff
block|}
enum|;
specifier|const
name|char
operator|*
name|getTypeName
argument_list|()
specifier|const
block|{
return|return
name|TypeName
return|;
block|}
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
name|TypeKind
operator|)
return|;
block|}
name|bool
name|isIntegerTy
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|TK_Integer
return|;
block|}
name|bool
name|isSignedIntegerTy
argument_list|()
specifier|const
block|{
return|return
name|isIntegerTy
argument_list|()
operator|&&
operator|(
name|TypeInfo
operator|&
literal|1
operator|)
return|;
block|}
name|bool
name|isUnsignedIntegerTy
argument_list|()
specifier|const
block|{
return|return
name|isIntegerTy
argument_list|()
operator|&&
operator|!
operator|(
name|TypeInfo
operator|&
literal|1
operator|)
return|;
block|}
name|unsigned
name|getIntegerBitWidth
argument_list|()
specifier|const
block|{
name|CHECK
argument_list|(
name|isIntegerTy
argument_list|()
argument_list|)
block|;
return|return
literal|1
operator|<<
operator|(
name|TypeInfo
operator|>>
literal|1
operator|)
return|;
block|}
name|bool
name|isFloatTy
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|TK_Float
return|;
block|}
name|unsigned
name|getFloatBitWidth
argument_list|()
specifier|const
block|{
name|CHECK
argument_list|(
name|isFloatTy
argument_list|()
argument_list|)
block|;
return|return
name|TypeInfo
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief An opaque handle to a value.
typedef|typedef
name|uptr
name|ValueHandle
typedef|;
comment|/// \brief Representation of an operand value provided by the instrumented code.
comment|///
comment|/// This is a combination of a TypeDescriptor (which is emitted as constant data
comment|/// as an operand to a handler function) and a ValueHandle (which is passed at
comment|/// runtime when a check failure occurs).
name|class
name|Value
block|{
comment|/// The type of the value.
specifier|const
name|TypeDescriptor
modifier|&
name|Type
decl_stmt|;
comment|/// The encoded value itself.
name|ValueHandle
name|Val
decl_stmt|;
comment|/// Is \c Val a (zero-extended) integer?
name|bool
name|isInlineInt
argument_list|()
specifier|const
block|{
name|CHECK
argument_list|(
name|getType
argument_list|()
operator|.
name|isIntegerTy
argument_list|()
argument_list|)
block|;
specifier|const
name|unsigned
name|InlineBits
operator|=
sizeof|sizeof
argument_list|(
name|ValueHandle
argument_list|)
operator|*
literal|8
block|;
specifier|const
name|unsigned
name|Bits
operator|=
name|getType
argument_list|()
operator|.
name|getIntegerBitWidth
argument_list|()
block|;
return|return
name|Bits
operator|<=
name|InlineBits
return|;
block|}
comment|/// Is \c Val a (zero-extended) integer representation of a float?
name|bool
name|isInlineFloat
argument_list|()
specifier|const
block|{
name|CHECK
argument_list|(
name|getType
argument_list|()
operator|.
name|isFloatTy
argument_list|()
argument_list|)
block|;
specifier|const
name|unsigned
name|InlineBits
operator|=
sizeof|sizeof
argument_list|(
name|ValueHandle
argument_list|)
operator|*
literal|8
block|;
specifier|const
name|unsigned
name|Bits
operator|=
name|getType
argument_list|()
operator|.
name|getFloatBitWidth
argument_list|()
block|;
return|return
name|Bits
operator|<=
name|InlineBits
return|;
block|}
name|public
label|:
name|Value
argument_list|(
argument|const TypeDescriptor&Type
argument_list|,
argument|ValueHandle Val
argument_list|)
block|:
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|Val
argument_list|(
argument|Val
argument_list|)
block|{}
specifier|const
name|TypeDescriptor
operator|&
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
comment|/// \brief Get this value as a signed integer.
name|SIntMax
name|getSIntValue
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Get this value as an unsigned integer.
name|UIntMax
name|getUIntValue
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Decode this value, which must be a positive or unsigned integer.
name|UIntMax
name|getPositiveIntValue
argument_list|()
specifier|const
expr_stmt|;
comment|/// Is this an integer with value -1?
name|bool
name|isMinusOne
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|.
name|isSignedIntegerTy
argument_list|()
operator|&&
name|getSIntValue
argument_list|()
operator|==
operator|-
literal|1
return|;
block|}
comment|/// Is this a negative integer?
name|bool
name|isNegative
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|.
name|isSignedIntegerTy
argument_list|()
operator|&&
name|getSIntValue
argument_list|()
operator|<
literal|0
return|;
block|}
comment|/// \brief Get this value as a floating-point quantity.
name|FloatMax
name|getFloatValue
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __ubsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// UBSAN_VALUE_H
end_comment

end_unit

