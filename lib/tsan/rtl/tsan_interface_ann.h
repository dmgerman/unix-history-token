begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_interface_ann.h ------------------------------------*- C++ -*-===//
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
comment|// Interface for dynamic annotations.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_INTERFACE_ANN_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_INTERFACE_ANN_H
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
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_acquire
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__tsan_release
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
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
comment|// TSAN_INTERFACE_ANN_H
end_comment

end_unit

