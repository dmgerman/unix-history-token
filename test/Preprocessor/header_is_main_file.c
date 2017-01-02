begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x c-header -ffreestanding -Eonly -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_empty
empty|#include_next "stdint.h"
end_empty

begin_if
if|#
directive|if
operator|!
name|__has_include_next
argument_list|(
literal|"stdint.h"
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"__has_include_next failed"
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

