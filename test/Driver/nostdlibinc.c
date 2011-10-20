begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-unknown-unknown \
end_comment

begin_comment
comment|// RUN:   -nostdlibinc -ffreestanding -fsyntax-only %s
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_include
argument_list|(
literal|"stddef.h"
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"expected to be able to find compiler builtin headers!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_include
argument_list|(
literal|"stdlib.h"
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"expected to *not* be able to find standard C headers"
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

