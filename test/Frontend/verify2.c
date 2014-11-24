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
comment|// CHECK-NEXT:   Line 5: header
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

begin_ifdef
ifdef|#
directive|ifdef
name|CHECK2
end_ifdef

begin_comment
comment|// RUN: not %clang_cc1 -DCHECK2 -verify %s 2>&1 | FileCheck -check-prefix=CHECK2 %s
end_comment

begin_comment
comment|// The following checks that -verify can match "any line" in an included file.
end_comment

begin_comment
comment|// The location of the diagnostic need therefore only match in the file, not to
end_comment

begin_comment
comment|// a specific line number.  This is useful where -verify is used as a testing
end_comment

begin_comment
comment|// tool for 3rd-party libraries where headers may change and the specific line
end_comment

begin_comment
comment|// number of a diagnostic in a header is not important.
end_comment

begin_comment
comment|// expected-error@verify2.h:* {{header}}
end_comment

begin_comment
comment|// expected-error@verify2.h:* {{unknown}}
end_comment

begin_comment
comment|//      CHECK2: error: 'error' diagnostics expected but not seen:
end_comment

begin_comment
comment|// CHECK2-NEXT:   File {{.*}}verify2.h Line * (directive at {{.*}}verify2.c:32): unknown
end_comment

begin_comment
comment|// CHECK2-NEXT: error: 'error' diagnostics seen but not expected:
end_comment

begin_comment
comment|// CHECK2-NEXT:   File {{.*}}verify2.c Line 10: source
end_comment

begin_comment
comment|// CHECK2-NEXT: 2 errors generated.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

