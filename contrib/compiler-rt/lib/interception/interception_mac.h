begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- interception_mac.h --------------------------------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Mac-specific interception methods.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INCLUDED_FROM_INTERCEPTION_LIB
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"interception_mac.h should be included from interception.h only"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTERCEPTION_MAC_H
end_ifndef

begin_define
define|#
directive|define
name|INTERCEPTION_MAC_H
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_MAC
parameter_list|(
name|func
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_VER_MAC
parameter_list|(
name|func
parameter_list|,
name|symver
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// INTERCEPTION_MAC_H
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __APPLE__
end_comment

end_unit

