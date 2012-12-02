begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -std=c99 -pedantic -W -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -x c++ -std=c++03 -pedantic-errors -W %s
end_comment

begin_include
include|#
directive|include
file|"completely-empty-header-file.h"
end_include

begin_comment
comment|// no-warning -- an empty file is OK
end_comment

begin_define
define|#
directive|define
name|A_MACRO_IS_NOT_GOOD_ENOUGH
value|1
end_define

begin_comment
comment|// In C we should get this warning, but in C++ we shouldn't.
end_comment

begin_comment
comment|// expected-warning{{ISO C requires a translation unit to contain at least one declaration}}
end_comment

end_unit

