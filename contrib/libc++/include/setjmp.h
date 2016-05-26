begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===--------------------------- setjmp.h ---------------------------------===//
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
name|_LIBCPP_SETJMP_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_SETJMP_H
end_define

begin_comment
comment|/*     setjmp.h synopsis  Macros:      setjmp  Types:      jmp_buf  void longjmp(jmp_buf env, int val);  */
end_comment

begin_include
include|#
directive|include
file|<__config>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#include_next<setjmp.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|setjmp
end_ifndef

begin_define
define|#
directive|define
name|setjmp
parameter_list|(
name|env
parameter_list|)
value|setjmp(env)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_SETJMP_H
end_comment

end_unit

