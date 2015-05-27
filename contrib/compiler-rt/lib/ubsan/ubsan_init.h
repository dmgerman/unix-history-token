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
comment|// NOTE: This function might take a lock (if .preinit_array initialization is
comment|// not used). It's generally a bad idea to call it on a fast path.
name|void
name|InitIfNecessary
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

