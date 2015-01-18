begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -I%S/Inputs/include_next/x -I%S/Inputs/include_next/y -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -I%S/Inputs/include_next/x -I%S/Inputs/include_next/y -verify %s -fmodules -fmodules-cache-path=%t
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_include
include|#
directive|include
file|"a.h"
end_include

begin_include
include|#
directive|include
file|"subdir/b.h"
end_include

begin_assert
assert|_Static_assert
argument_list|(
name|ax
operator|==
literal|1
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|ay
operator|==
literal|2
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|bx
operator|==
literal|3
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|by
operator|==
literal|4
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

end_unit

