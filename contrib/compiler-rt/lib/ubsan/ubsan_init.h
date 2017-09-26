begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ubsan_init.h --------------------------------------------*- C++ -*-===//
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
comment|// Initialization function for UBSan runtime.
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
name|UBSAN_INIT_H
end_ifndef

begin_define
define|#
directive|define
name|UBSAN_INIT_H
end_define

begin_decl_stmt
name|namespace
name|__ubsan
block|{
comment|// Get the full tool name for UBSan.
specifier|const
name|char
modifier|*
name|GetSanititizerToolName
parameter_list|()
function_decl|;
comment|// Initialize UBSan as a standalone tool. Typically should be called early
comment|// during initialization.
name|void
name|InitAsStandalone
parameter_list|()
function_decl|;
comment|// Initialize UBSan as a standalone tool, if it hasn't been initialized before.
name|void
name|InitAsStandaloneIfNecessary
parameter_list|()
function_decl|;
comment|// Initializes UBSan as a plugin tool. This function should be called once
comment|// from "parent tool" (e.g. ASan) initialization.
name|void
name|InitAsPlugin
parameter_list|()
function_decl|;
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
comment|// UBSAN_INIT_H
end_comment

end_unit

