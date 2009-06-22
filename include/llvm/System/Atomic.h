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
typedef|typedef
name|uint32_t
name|cas_flag
typedef|;
name|cas_flag
name|CompareAndSwap
parameter_list|(
specifier|volatile
name|cas_flag
modifier|*
name|ptr
parameter_list|,
name|cas_flag
name|new_value
parameter_list|,
name|cas_flag
name|old_value
parameter_list|)
function_decl|;
name|cas_flag
name|AtomicIncrement
parameter_list|(
specifier|volatile
name|cas_flag
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|cas_flag
name|AtomicDecrement
parameter_list|(
specifier|volatile
name|cas_flag
modifier|*
name|ptr
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

