begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -verify -fms-compatibility %s
end_comment

begin_empty
empty|#import "pp-record.h"
end_empty

begin_comment
comment|// expected-error {{#import of type library is an unsupported Microsoft feature}}
end_comment

begin_comment
comment|// Test attributes
end_comment

begin_empty
empty|#import "pp-record.h" no_namespace, auto_rename
end_empty

begin_comment
comment|// expected-error {{#import of type library is an unsupported Microsoft feature}}
end_comment

begin_empty
empty|#import "pp-record.h" no_namespace \                       auto_rename \                       auto_search
end_empty

begin_comment
comment|// expected-error@-3 {{#import of type library is an unsupported Microsoft feature}}
end_comment

end_unit

