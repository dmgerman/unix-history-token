begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------------------------------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
name|SUPPORT_DISABLE_MISSING_BRACES_WARNING_H
end_ifndef

begin_define
define|#
directive|define
name|SUPPORT_DISABLE_MISSING_BRACES_WARNING_H
end_define

begin_comment
comment|// std::array is explicitly allowed to be initialized with A a = { init-list };.
end_comment

begin_comment
comment|// Disable the missing braces warning for this reason.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wmissing-braces"
end_pragma

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__clang__
argument_list|)
end_elif

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wmissing-braces"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SUPPORT_DISABLE_MISSING_BRACES_WARNING_H
end_comment

end_unit

