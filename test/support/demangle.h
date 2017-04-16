begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

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
name|SUPPORT_DEMANGLE_H
end_ifndef

begin_define
define|#
directive|define
name|SUPPORT_DEMANGLE_H
end_define

begin_include
include|#
directive|include
file|"test_macros.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TEST_HAS_NO_DEMANGLE
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_if
if|#
directive|if
name|__has_include
argument_list|(
literal|"cxxabi.h"
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LIBCPP_ABI_MICROSOFT
argument_list|)
end_if

begin_include
include|#
directive|include
file|"cxxabi.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_HAS_NO_DEMANGLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_HAS_NO_DEMANGLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TEST_HAS_NO_DEMANGLE
argument_list|)
end_if

begin_expr_stmt
specifier|inline
name|std
operator|::
name|string
name|demangle
argument_list|(
argument|const char* mangled_name
argument_list|)
block|{
return|return
name|mangled_name
return|;
block|}
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|template
operator|<
name|size_t
name|N
operator|>
expr|struct
name|Printer
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|inline
name|std
operator|::
name|string
name|demangle
argument_list|(
argument|const char* mangled_name
argument_list|)
block|{
name|int
name|status
operator|=
literal|0
block|;
name|char
operator|*
name|out
operator|=
name|__cxxabiv1
operator|::
name|__cxa_demangle
argument_list|(
name|mangled_name
argument_list|,
name|nullptr
argument_list|,
name|nullptr
argument_list|,
operator|&
name|status
argument_list|)
block|;
if|if
condition|(
name|out
operator|!=
name|nullptr
condition|)
block|{
name|std
operator|::
name|string
name|res
argument_list|(
name|out
argument_list|)
expr_stmt|;
name|std
operator|::
name|free
argument_list|(
name|out
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_expr_stmt

begin_return
return|return
name|mangled_name
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SUPPORT_DEMANGLE_H
end_comment

end_unit

