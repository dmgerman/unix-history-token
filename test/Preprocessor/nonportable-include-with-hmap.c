begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Eonly                        \
end_comment

begin_comment
comment|// RUN:   -I%S/Inputs/nonportable-hmaps/foo.hmap \
end_comment

begin_comment
comment|// RUN:   -I%S/Inputs/nonportable-hmaps          \
end_comment

begin_comment
comment|// RUN:   %s -verify
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// foo.hmap contains: Foo/Foo.h -> headers/foo/Foo.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Header search of "Foo/Foo.h" follows this path:
end_comment

begin_comment
comment|//  1. Look for "Foo/Foo.h".
end_comment

begin_comment
comment|//  2. Find "Foo/Foo.h" in "nonportable-hmaps/foo.hmap".
end_comment

begin_comment
comment|//  3. Look for "headers/foo/Foo.h".
end_comment

begin_comment
comment|//  4. Find "headers/foo/Foo.h" in "nonportable-hmaps".
end_comment

begin_comment
comment|//  5. Return.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// There is nothing nonportable; -Wnonportable-include-path should not fire.
end_comment

begin_include
include|#
directive|include
file|"Foo/Foo.h"
end_include

begin_comment
comment|// expected-no-diagnostics
end_comment

end_unit

