begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- lsan.h --------------------------------------------------------------===//
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
comment|// This file is a part of LeakSanitizer.
end_comment

begin_comment
comment|// Private header for standalone LSan RTL.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_flags.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_stacktrace.h"
end_include

begin_decl_stmt
name|namespace
name|__lsan
block|{
name|void
name|InitializeInterceptors
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __lsan
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|lsan_inited
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|lsan_init_is_running
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern
literal|"C"
name|void
name|__lsan_init
parameter_list|()
function_decl|;
end_extern

end_unit

