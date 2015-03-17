begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- msan_poisoning.h ----------------------------------------*- C++ -*-===//
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
comment|// This file is a part of MemorySanitizer.
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
name|MSAN_POISONING_H
end_ifndef

begin_define
define|#
directive|define
name|MSAN_POISONING_H
end_define

begin_include
include|#
directive|include
file|"msan.h"
end_include

begin_decl_stmt
name|namespace
name|__msan
block|{
comment|// Return origin for the first poisoned byte in the memory range, or 0.
name|u32
name|GetOriginIfPoisoned
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
comment|// Walk [addr, addr+size) app memory region, copying origin tags from the
comment|// corresponding positions in [src_origin, src_origin+size) where the
comment|// corresponding shadow in [src_shadow, src_shadow+size) is non-zero.
name|void
name|SetOriginIfPoisoned
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
name|src_shadow
parameter_list|,
name|uptr
name|size
parameter_list|,
name|u32
name|src_origin
parameter_list|)
function_decl|;
comment|// Copy origin from src (app address) to dst (app address), creating chained
comment|// origin ids as necessary, without overriding origin for fully initialized
comment|// quads.
name|void
name|CopyOrigin
parameter_list|(
specifier|const
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|,
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
comment|// memmove() shadow and origin. Dst and src are application addresses.
comment|// See CopyOrigin() for the origin copying logic.
name|void
name|MoveShadowAndOrigin
parameter_list|(
specifier|const
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|,
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
comment|// memcpy() shadow and origin. Dst and src are application addresses.
comment|// See CopyOrigin() for the origin copying logic.
name|void
name|CopyShadowAndOrigin
parameter_list|(
specifier|const
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|,
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
comment|// memcpy() app memory, and do "the right thing" to the corresponding shadow and
comment|// origin regions.
name|void
name|CopyMemory
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|,
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
comment|// Fill shadow will value. Ptr is an application address.
name|void
name|SetShadow
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|uptr
name|size
parameter_list|,
name|u8
name|value
parameter_list|)
function_decl|;
comment|// Set origin for the memory region.
name|void
name|SetOrigin
parameter_list|(
specifier|const
name|void
modifier|*
name|dst
parameter_list|,
name|uptr
name|size
parameter_list|,
name|u32
name|origin
parameter_list|)
function_decl|;
comment|// Mark memory region uninitialized, with origins.
name|void
name|PoisonMemory
parameter_list|(
specifier|const
name|void
modifier|*
name|dst
parameter_list|,
name|uptr
name|size
parameter_list|,
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __msan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MSAN_POISONING_H
end_comment

end_unit

