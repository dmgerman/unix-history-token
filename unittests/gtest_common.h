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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|_HAS_EXCEPTIONS
operator|==
literal|0
operator|)
end_if

begin_comment
comment|// Due to a bug in<thread>, when _HAS_EXCEPTIONS == 0 the header will try to
end_comment

begin_comment
comment|// call
end_comment

begin_comment
comment|// uncaught_exception() without having a declaration for it.  The fix for this
end_comment

begin_comment
comment|// is
end_comment

begin_comment
comment|// to manually #include<eh.h>, which contains this declaration.
end_comment

begin_include
include|#
directive|include
file|<eh.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

