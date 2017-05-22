begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm-cvtres.h ------------------------------------------ *- C++ --*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TOOLS_LLVMCVTRES_LLVMCVTRES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMCVTRES_LLVMCVTRES_H
end_define

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|void
name|error
argument_list|(
name|std
operator|::
name|error_code
name|EC
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|class
name|machine
block|{
name|UNKNOWN
operator|=
literal|0
operator|,
name|ARM
operator|,
name|X64
operator|,
name|X86
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

