begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wnewline-eof -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -pedantic -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -x c++ -std=c++03 -pedantic -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wnewline-eof %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// rdar://9133072
end_comment

begin_comment
comment|// In C++11 mode, this is allowed, so don't warn in pedantic mode.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -x c++ -std=c++11 -Wnewline-eof -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -x c++ -std=c++11 -Werror -pedantic %s
end_comment

begin_comment
comment|// Make sure the diagnostic shows up properly at the end of the last line.
end_comment

begin_comment
comment|// CHECK: newline-eof.c:[[@LINE+3]]:63
end_comment

begin_comment
comment|// The following line isn't terminated, don't fix it.
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning{{no newline at end of file}}
end_comment

end_unit

