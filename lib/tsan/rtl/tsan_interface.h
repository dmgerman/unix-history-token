begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_interface.h ----------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer (TSan), a race detector.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The functions declared in this header will be inserted by the instrumentation
end_comment

begin_comment
comment|// module.
end_comment

begin_comment
comment|// This header can be included by the instrumented program or by TSan tests.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|<sanitizer_common/sanitizer_internal_defs.h>
end_include

begin_comment
comment|// This header should NOT include any other headers.
end_comment

begin_comment
comment|// All functions in this header are extern "C" and start with __tsan_.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// This function should be called at the very beginning of the process,
comment|// before any instrumented code is executed and before any call to malloc.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_init
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_read1
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_read2
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_read4
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_read8
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_read16
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_write1
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_write2
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_write4
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_write8
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_write16
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_unaligned_read2
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_unaligned_read4
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_unaligned_read8
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_unaligned_read16
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_unaligned_write2
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_unaligned_write4
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_unaligned_write8
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_unaligned_write16
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_vptr_read
parameter_list|(
name|void
modifier|*
modifier|*
name|vptr_p
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_vptr_update
parameter_list|(
name|void
modifier|*
modifier|*
name|vptr_p
parameter_list|,
name|void
modifier|*
name|new_val
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_func_entry
parameter_list|(
name|void
modifier|*
name|call_pc
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_func_exit
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_read_range
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|)
function_decl|;
comment|// NOLINT
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_write_range
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|)
function_decl|;
comment|// NOLINT
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_INTERFACE_H
end_comment

end_unit

