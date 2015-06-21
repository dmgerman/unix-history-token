begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -DTEST_SWITCH -verify-ignore-unexpected=remark,aoeu,note -verify %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck -check-prefix=CHECK-BAD-SWITCH %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST_SWITCH
end_ifdef

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-BAD-SWITCH: error: 'error' diagnostics seen but not expected:
end_comment

begin_comment
comment|// CHECK-BAD-SWITCH-NEXT: (frontend): invalid value 'aoeu' in '-verify-ignore-unexpected='
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DTEST1 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DTEST1 -verify -verify-ignore-unexpected %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST1
end_ifdef

begin_warning
warning|#
directive|warning
warning|MyWarning1
end_warning

begin_comment
comment|// expected-warning@-1 {{MyWarning1}}
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
name|float
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'x'}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: not %clang_cc1 -DTEST2 -verify %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck -check-prefix=CHECK-UNEXP %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST2 -verify -verify-ignore-unexpected= %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck -check-prefix=CHECK-UNEXP %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST2 -verify -verify-ignore-unexpected=note %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck -check-prefix=CHECK-NOTE %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST2 -verify -verify-ignore-unexpected=warning %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck -check-prefix=CHECK-WARN %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST2 -verify -verify-ignore-unexpected=error %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck -check-prefix=CHECK-ERR %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST2
end_ifdef

begin_warning
warning|#
directive|warning
warning|MyWarning2
end_warning

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|x
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-UNEXP: no expected directives found
end_comment

begin_comment
comment|// CHECK-UNEXP-NEXT: 'error' diagnostics seen but not expected
end_comment

begin_comment
comment|// CHECK-UNEXP-NEXT: Line {{[0-9]+}}: redefinition of 'x'
end_comment

begin_comment
comment|// CHECK-UNEXP-NEXT: 'warning' diagnostics seen but not expected
end_comment

begin_comment
comment|// CHECK-UNEXP-NEXT: Line {{[0-9]+}}: MyWarning2
end_comment

begin_comment
comment|// CHECK-UNEXP-NEXT: 'note' diagnostics seen but not expected
end_comment

begin_comment
comment|// CHECK-UNEXP-NEXT: Line {{[0-9]+}}: previous definition is here
end_comment

begin_comment
comment|// CHECK-UNEXP-NEXT: 4 errors generated.
end_comment

begin_comment
comment|// CHECK-NOTE: no expected directives found
end_comment

begin_comment
comment|// CHECK-NOTE-NEXT: 'error' diagnostics seen but not expected
end_comment

begin_comment
comment|// CHECK-NOTE-NEXT: Line {{[0-9]+}}: redefinition of 'x'
end_comment

begin_comment
comment|// CHECK-NOTE-NEXT: 'warning' diagnostics seen but not expected
end_comment

begin_comment
comment|// CHECK-NOTE-NEXT: Line {{[0-9]+}}: MyWarning2
end_comment

begin_comment
comment|// CHECK-NOTE-NEXT: 3 errors generated.
end_comment

begin_comment
comment|// CHECK-WARN: no expected directives found
end_comment

begin_comment
comment|// CHECK-WARN-NEXT: 'error' diagnostics seen but not expected
end_comment

begin_comment
comment|// CHECK-WARN-NEXT: Line {{[0-9]+}}: redefinition of 'x'
end_comment

begin_comment
comment|// CHECK-WARN-NEXT: 'note' diagnostics seen but not expected
end_comment

begin_comment
comment|// CHECK-WARN-NEXT: Line {{[0-9]+}}: previous definition is here
end_comment

begin_comment
comment|// CHECK-WARN-NEXT: 3 errors generated.
end_comment

begin_comment
comment|// CHECK-ERR: no expected directives found
end_comment

begin_comment
comment|// CHECK-ERR-NEXT: 'warning' diagnostics seen but not expected
end_comment

begin_comment
comment|// CHECK-ERR-NEXT: Line {{[0-9]+}}: MyWarning2
end_comment

begin_comment
comment|// CHECK-ERR-NEXT: 'note' diagnostics seen but not expected
end_comment

begin_comment
comment|// CHECK-ERR-NEXT: Line {{[0-9]+}}: previous definition is here
end_comment

begin_comment
comment|// CHECK-ERR-NEXT: 3 errors generated.
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST3 -verify -verify-ignore-unexpected %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck -check-prefix=CHECK-EXP %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST3
end_ifdef

begin_comment
comment|// expected-error {{test3}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-EXP: 'error' diagnostics expected but not seen
end_comment

begin_comment
comment|// CHECK-EXP-NEXT: Line {{[0-9]+}}: test3
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST4 -verify -verify-ignore-unexpected %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck -check-prefix=CHECK-NOEXP %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST4 -verify -verify-ignore-unexpected=warning,error,note %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck -check-prefix=CHECK-NOEXP %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST4
end_ifdef

begin_warning
warning|#
directive|warning
warning|MyWarning4
end_warning

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|x
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-NOEXP: error: no expected directives found
end_comment

begin_comment
comment|// CHECK-NOEXP-NEXT: 1 error generated
end_comment

end_unit

