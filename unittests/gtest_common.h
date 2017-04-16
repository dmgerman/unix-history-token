begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- gtest_common.h ------------------------------------------*- C++ -*-===//
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LLDB_GTEST_COMMON_H
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"gtest_common.h should not be included manually."
end_error

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_GTEST_COMMON_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// This header file is force included by all of LLDB's unittest compilation
end_comment

begin_comment
comment|// units.  Be very leary about putting anything in this file.
end_comment

end_unit

