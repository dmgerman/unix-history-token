begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -triple i386-pc-win32 -fms-compatibility %s
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WCHAR_T_DEFINED
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"_WCHAR_T_DEFINED should not be defined in C99"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WCHAR_T_DEFINED
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"_WCHAR_T_DEFINED should have been set by stddef.h"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_NATIVE_WCHAR_T_DEFINED
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"_NATIVE_WCHAR_T_DEFINED should not be defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

