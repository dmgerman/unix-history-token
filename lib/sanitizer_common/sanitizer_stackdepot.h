begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_stackdepot.h ----------------------------------*- C++ -*-===//
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
comment|// This file is shared between AddressSanitizer and ThreadSanitizer
end_comment

begin_comment
comment|// run-time libraries.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_STACKDEPOT_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_STACKDEPOT_H
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
comment|// StackDepot efficiently stores huge amounts of stack traces.
comment|// Maps stack trace to an unique id.
name|u32
name|StackDepotPut
parameter_list|(
specifier|const
name|uptr
modifier|*
name|stack
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
comment|// Retrieves a stored stack trace by the id.
specifier|const
name|uptr
modifier|*
name|StackDepotGet
parameter_list|(
name|u32
name|id
parameter_list|,
name|uptr
modifier|*
name|size
parameter_list|)
function_decl|;
struct|struct
name|StackDepotStats
block|{
name|uptr
name|n_uniq_ids
decl_stmt|;
name|uptr
name|mapped
decl_stmt|;
block|}
struct|;
name|StackDepotStats
modifier|*
name|StackDepotGetStats
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_STACKDEPOT_H
end_comment

end_unit

