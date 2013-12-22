begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// RUN: not %clang_cc1 -verify %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Please note that all comments are inside "#if 0" blocks so that
end_comment

begin_comment
comment|// VerifyDiagnosticConsumer sees no comments while processing this
end_comment

begin_comment
comment|// test-case (and hence no expected-* directives).
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"verify2.h"
end_include

begin_error
error|#
directive|error
error|source
end_error

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// expected-error {{should be ignored}}
end_comment

begin_comment
comment|//      CHECK: error: no expected directives found: consider use of 'expected-no-diagnostics'
end_comment

begin_comment
comment|// CHECK-NEXT: error: 'error' diagnostics seen but not expected:
end_comment

begin_comment
comment|// CHECK-NEXT:   Line 1: header
end_comment

begin_comment
comment|// CHECK-NEXT:   Line 10: source
end_comment

begin_comment
comment|// CHECK-NEXT: 3 errors generated.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

