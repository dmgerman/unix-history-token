begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This test-case runs several sub-tests on -verify to ensure that correct
end_comment

begin_comment
comment|// diagnostics are generated in relation to the mis-use and non-use of the
end_comment

begin_comment
comment|// 'expected-no-diagnostics' directive.
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST1 -verify %s 2>&1 | FileCheck -check-prefix=CHECK1 %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST1
end_ifdef

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// expected-note {{}}
end_comment

begin_comment
comment|//      CHECK1: error: 'error' diagnostics seen but not expected:
end_comment

begin_comment
comment|// CHECK1-NEXT:   Line 8: expected directive cannot follow 'expected-no-diagnostics' directive
end_comment

begin_comment
comment|// CHECK1-NEXT: 1 error generated.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: not %clang_cc1 -DTEST2 -verify %s 2>&1 | FileCheck -check-prefix=CHECK2 %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST2
end_ifdef

begin_warning
warning|#
directive|warning
warning|X
end_warning

begin_comment
comment|// expected-warning@-1 {{X}}
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|//      CHECK2: error: 'error' diagnostics seen but not expected:
end_comment

begin_comment
comment|// CHECK2-NEXT:   Line 19: 'expected-no-diagnostics' directive cannot follow other expected directives
end_comment

begin_comment
comment|// CHECK2-NEXT: 1 error generated.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: not %clang_cc1 -DTEST3 -verify %s 2>&1 | FileCheck -check-prefix=CHECK3 %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -verify %s 2>&1 | FileCheck -check-prefix=CHECK3 %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST3
end_ifdef

begin_comment
comment|// no directives
end_comment

begin_comment
comment|//      CHECK3: error: no expected directives found: consider use of 'expected-no-diagnostics'
end_comment

begin_comment
comment|// CHECK3-NEXT: 1 error generated.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: %clang_cc1 -E -DTEST4 -verify %s 2>&1 | FileCheck -check-prefix=CHECK4 %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST4
end_ifdef

begin_warning
warning|#
directive|warning
warning|X
end_warning

begin_comment
comment|// expected-warning@-1 {{X}}
end_comment

begin_comment
comment|// CHECK4-NOT: error: no expected directives found: consider use of 'expected-no-diagnostics'
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

