begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -Wall -Wextra -E -frewrite-includes %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|default
name|)
end_pragma

end_unit

