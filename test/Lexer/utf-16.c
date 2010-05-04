begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang %s -fsyntax-only -verify
end_comment

begin_comment
comment|// rdar://7876588
end_comment

begin_comment
comment|// This test verifies that clang gives a decent error for UTF-16 source files.
end_comment

begin_include
include|#
directive|include
file|"utf-16.c.txt"
end_include

begin_comment
comment|// expected-error {{UTF-16 (LE) byte order mark detected}}
end_comment

end_unit

