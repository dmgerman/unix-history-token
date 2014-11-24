begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s -Wall -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Eonly %s -Wall -verify
end_comment

begin_comment
comment|// RUN: %clang -M -Wall %s -Xclang -verify
end_comment

begin_comment
comment|// RUN: %clang -E -frewrite-includes %s -Wall -Xclang -verify
end_comment

begin_comment
comment|// RUN: %clang -E -dD -dM %s -Wall -Xclang -verify
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

begin_pragma
pragma|#
directive|pragma
name|weak
end_pragma

begin_pragma
pragma|#
directive|pragma
name|this_pragma_does_not_exist
end_pragma

end_unit

