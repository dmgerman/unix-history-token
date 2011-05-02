begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -isystem %S %s -fsyntax-only -verify
end_comment

begin_include
include|#
directive|include
file|<warn-in-system-header.h>
end_include

begin_comment
comment|// expected-warning {{#warning}}
end_comment

end_unit

