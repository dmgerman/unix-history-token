begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------- LLDBAssert.h ------------------------------*- C++-*-===//
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
name|utility_LLDBAssert_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_LLDBAssert_h_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LLDB_CONFIGURATION_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|lldbassert
parameter_list|(
name|x
parameter_list|)
value|assert(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|lldbassert
parameter_list|(
name|x
parameter_list|)
define|\
value|lldb_private::lldb_assert(x, #x, __FUNCTION__, __FILE__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|void
name|lldb_assert
parameter_list|(
name|bool
name|expression
parameter_list|,
specifier|const
name|char
modifier|*
name|expr_text
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|unsigned
name|int
name|line
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// utility_LLDBAssert_h_
end_comment

end_unit

