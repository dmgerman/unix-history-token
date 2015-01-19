begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_atomic.h --------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer/AddressSanitizer runtime.
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
name|SANITIZER_ATOMIC_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_ATOMIC_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
enum|enum
name|memory_order
block|{
name|memory_order_relaxed
init|=
literal|1
operator|<<
literal|0
block|,
name|memory_order_consume
init|=
literal|1
operator|<<
literal|1
block|,
name|memory_order_acquire
init|=
literal|1
operator|<<
literal|2
block|,
name|memory_order_release
init|=
literal|1
operator|<<
literal|3
block|,
name|memory_order_acq_rel
init|=
literal|1
operator|<<
literal|4
block|,
name|memory_order_seq_cst
init|=
literal|1
operator|<<
literal|5
block|}
enum|;
struct|struct
name|atomic_uint8_t
block|{
typedef|typedef
name|u8
name|Type
typedef|;
specifier|volatile
name|Type
name|val_dont_use
decl_stmt|;
block|}
struct|;
struct|struct
name|atomic_uint16_t
block|{
typedef|typedef
name|u16
name|Type
typedef|;
specifier|volatile
name|Type
name|val_dont_use
decl_stmt|;
block|}
struct|;
struct|struct
name|atomic_uint32_t
block|{
typedef|typedef
name|u32
name|Type
typedef|;
specifier|volatile
name|Type
name|val_dont_use
decl_stmt|;
block|}
struct|;
struct|struct
name|atomic_uint64_t
block|{
typedef|typedef
name|u64
name|Type
typedef|;
comment|// On 32-bit platforms u64 is not necessary aligned on 8 bytes.
specifier|volatile
name|ALIGNED
argument_list|(
literal|8
argument_list|)
name|Type
name|val_dont_use
expr_stmt|;
block|}
struct|;
struct|struct
name|atomic_uintptr_t
block|{
typedef|typedef
name|uptr
name|Type
typedef|;
specifier|volatile
name|Type
name|val_dont_use
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"sanitizer_atomic_clang.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"sanitizer_atomic_msvc.h"
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Unsupported compiler"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_ATOMIC_H
end_comment

end_unit

