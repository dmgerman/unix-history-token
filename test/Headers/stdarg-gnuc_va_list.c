begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wsystem-headers -std=c99 %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// Check that no warnings are emitted from stdarg.h if __gnuc_va_list has
end_comment

begin_comment
comment|// previously been defined in another header file.
end_comment

begin_typedef
typedef|typedef
name|__builtin_va_list
name|__va_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__va_list
name|__gnuc_va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__GNUC_VA_LIST
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

end_unit

