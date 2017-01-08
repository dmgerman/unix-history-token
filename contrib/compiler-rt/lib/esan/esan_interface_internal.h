begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- esan_interface_internal.h -------------------------------*- C++ -*-===//
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
comment|// This file is a part of EfficiencySanitizer, a family of performance tuners.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Calls to the functions declared in this header will be inserted by
end_comment

begin_comment
comment|// the instrumentation module.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ESAN_INTERFACE_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|ESAN_INTERFACE_INTERNAL_H
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
comment|// All functions in this header are extern "C" and start with __esan_.
end_comment

begin_expr_stmt
name|using
name|__sanitizer
operator|::
name|uptr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__sanitizer
operator|::
name|u32
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern
literal|"C"
block|{
comment|// This should be kept consistent with LLVM's EfficiencySanitizerOptions.
comment|// The value is passed as a 32-bit integer by the compiler.
typedef|typedef
enum|enum
name|Type
enum|:
name|u32
block|{
name|ESAN_None
init|=
literal|0
block|,
name|ESAN_CacheFrag
block|,
name|ESAN_WorkingSet
block|,
name|ESAN_Max
block|, }
name|ToolType
typedef|;
comment|// To handle interceptors that invoke instrumented code prior to
comment|// __esan_init() being called, the instrumentation module creates this
comment|// global variable specifying the tool.
specifier|extern
name|ToolType
name|__esan_which_tool
decl_stmt|;
comment|// This function should be called at the very beginning of the process,
comment|// before any instrumented code is executed and before any call to malloc.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_init
parameter_list|(
name|ToolType
name|Tool
parameter_list|,
name|void
modifier|*
name|Ptr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_exit
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
function_decl|;
comment|// The instrumentation module will insert a call to one of these routines prior
comment|// to each load and store instruction for which we do not have "fastpath"
comment|// inlined instrumentation.  These calls constitute the "slowpath" for our
comment|// tools.  We have separate routines for each type of memory access to enable
comment|// targeted optimization.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_aligned_load1
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_aligned_load2
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_aligned_load4
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_aligned_load8
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_aligned_load16
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_aligned_store1
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_aligned_store2
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_aligned_store4
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_aligned_store8
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_aligned_store16
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_unaligned_load2
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_unaligned_load4
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_unaligned_load8
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_unaligned_load16
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_unaligned_store2
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_unaligned_store4
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_unaligned_store8
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_unaligned_store16
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
comment|// These cover unusually-sized accesses.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_unaligned_loadN
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|,
name|uptr
name|Size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__esan_unaligned_storeN
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|,
name|uptr
name|Size
parameter_list|)
function_decl|;
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ESAN_INTERFACE_INTERNAL_H
end_comment

end_unit

