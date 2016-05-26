begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------- config_elast.h -------------------------------===//
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
name|_LIBCPP_CONFIG_ELAST
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_CONFIG_ELAST
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ELAST
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LIBCPP_ELAST
value|ELAST
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_NEWLIB_VERSION
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBCPP_ELAST
value|__ELASTERROR
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__linux__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBCPP_ELAST
value|4095
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_elif

begin_comment
comment|// No _LIBCPP_ELAST needed on Apple
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sun__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBCPP_ELAST
value|ESTALE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBCPP_ELAST
value|_sys_nerr
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Warn here so that the person doing the libcxx port has an easier time:
end_comment

begin_warning
warning|#
directive|warning
warning|ELAST for this platform not yet implemented
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_CONFIG_ELAST
end_comment

end_unit

