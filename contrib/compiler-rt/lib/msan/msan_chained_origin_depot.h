begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- msan_chained_origin_depot.h --------------------------*- C++ -*-===//
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
comment|// A storage for chained origins.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSAN_CHAINED_ORIGIN_DEPOT_H
end_ifndef

begin_define
define|#
directive|define
name|MSAN_CHAINED_ORIGIN_DEPOT_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_decl_stmt
name|namespace
name|__msan
block|{
name|StackDepotStats
modifier|*
name|ChainedOriginDepotGetStats
parameter_list|()
function_decl|;
name|bool
name|ChainedOriginDepotPut
parameter_list|(
name|u32
name|here_id
parameter_list|,
name|u32
name|prev_id
parameter_list|,
name|u32
modifier|*
name|new_id
parameter_list|)
function_decl|;
comment|// Retrieves a stored stack trace by the id.
name|u32
name|ChainedOriginDepotGet
parameter_list|(
name|u32
name|id
parameter_list|,
name|u32
modifier|*
name|other
parameter_list|)
function_decl|;
name|void
name|ChainedOriginDepotLockAll
parameter_list|()
function_decl|;
name|void
name|ChainedOriginDepotUnlockAll
parameter_list|()
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
comment|// MSAN_CHAINED_ORIGIN_DEPOT_H
end_comment

end_unit

