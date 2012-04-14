begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -fms-compatibility %s 2>&1 | grep 'doh.c:100:2: error: #import of type library is an unsupported Microsoft feature'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -fms-compatibility %s 2>&1 | grep 'doh.c:200:2: error: #import of type library is an unsupported Microsoft feature'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -fms-compatibility %s 2>&1 | grep 'doh.c:300:2: error: #import of type library is an unsupported Microsoft feature'
end_comment

begin_line
line|#
directive|line
number|100
file|"doh.c"
end_line

begin_empty
empty|#import "pp-record.h"
end_empty

begin_comment
comment|// expected-error {{#import of type library is an unsupported Microsoft feature}}
end_comment

begin_comment
comment|// Test attributes
end_comment

begin_line
line|#
directive|line
number|200
file|"doh.c"
end_line

begin_empty
empty|#import "pp-record.h" no_namespace, auto_rename
end_empty

begin_comment
comment|// expected-error {{#import of type library is an unsupported Microsoft feature}}
end_comment

begin_comment
comment|// This will also fire the "#import of type library is an unsupported Microsoft feature"
end_comment

begin_comment
comment|// error, but we can't use -verify because there's no way to put the comment on the proper line
end_comment

begin_line
line|#
directive|line
number|300
file|"doh.c"
end_line

begin_empty
empty|#import "pp-record.h" no_namespace \                       auto_rename \                       auto_search
end_empty

end_unit

