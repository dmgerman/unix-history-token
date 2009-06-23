begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/System/Atomic.h - Atomic Operations -----------------*- C++ -*-===//
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
comment|// This file declares the llvm::sys atomic operations.
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
name|LLVM_SYSTEM_ATOMIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_ATOMIC_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
name|void
name|MemoryFence
parameter_list|()
function_decl|;
name|uint32_t
name|CompareAndSwap32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|new_value
parameter_list|,
name|uint32_t
name|old_value
parameter_list|)
function_decl|;
name|int32_t
name|AtomicIncrement32
parameter_list|(
specifier|volatile
name|int32_t
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|int32_t
name|AtomicDecrement32
parameter_list|(
specifier|volatile
name|int32_t
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|int32_t
name|AtomicAdd32
parameter_list|(
specifier|volatile
name|int32_t
modifier|*
name|ptr
parameter_list|,
name|int32_t
name|val
parameter_list|)
function_decl|;
name|int64_t
name|AtomicAdd64
parameter_list|(
specifier|volatile
name|int64_t
modifier|*
name|ptr
parameter_list|,
name|int64_t
name|val
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

