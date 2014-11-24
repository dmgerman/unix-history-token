begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -DTEST1 -verify %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST2 -verify %s 2>&1 | FileCheck -check-prefix=CHECK2 %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST3 -verify %s 2>&1 | FileCheck -check-prefix=CHECK3 %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST4 -verify %s 2>&1 | FileCheck -check-prefix=CHECK4 %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DTEST5 -verify %s 2>&1 | FileCheck -check-prefix=CHECK5 %s
end_comment

begin_comment
comment|// expected-warning@ malformed
end_comment

begin_comment
comment|// expected-error@7 1 {{missing or invalid line number}}
end_comment

begin_comment
comment|// expected-warning@0 malformed
end_comment

begin_comment
comment|// expected-error@10 {{missing or invalid line number}}
end_comment

begin_comment
comment|// expected-warning@-50 malformed
end_comment

begin_comment
comment|// expected-error@13 {{missing or invalid line number}}
end_comment

begin_comment
comment|// expected-warning malformed
end_comment

begin_comment
comment|// expected-error@16 {{cannot find start}}
end_comment

begin_comment
comment|// expected-error 0+ {{should also be ignored}}
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST1
end_ifdef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// expected-error {{should be ignored}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// eexpected-error {{should also be ignored: unrecognised directive}}
end_comment

begin_error
error|#
directive|error
error|should not be ignored
end_error

begin_comment
comment|// expected-error@-1 1+ {{should not be ignored}}
end_comment

begin_line
line|#
directive|line
number|90
end_line

begin_decl_stmt
name|unexpected
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error@+0 + {{unknown type}}
end_comment

begin_line
line|#
directive|line
number|60
end_line

begin_decl_stmt
name|unexpected
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error@33 1-1 {{unknown type}}
end_comment

begin_comment
comment|// expected-error@+2 {{file not found}} check that multi-line handled correctly: \
end_comment

begin_include
include|#
directive|include
file|"missing_header_file.include"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TEST2
end_ifdef

begin_define
define|#
directive|define
name|MACRO
value|some_value
end_define

begin_comment
comment|// expected-error {{define_error}}
end_comment

begin_undef
undef|#
directive|undef
name|MACRO
name|extra_token
end_undef

begin_comment
comment|// expected-warning {{undef_error}}
end_comment

begin_line
line|#
directive|line
line|-2
end_line

begin_comment
comment|// expected-error {{line_error}}
end_comment

begin_error
error|#
directive|error
error|AAA
end_error

begin_comment
comment|// expected-error {{BBB}}<- this shall be part of diagnostic
end_comment

begin_warning
warning|#
directive|warning
warning|CCC
end_warning

begin_comment
comment|// expected-warning {{DDD}}<- this shall be part of diagnostic
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// This is encapsulated in "#if 0" so that the expected-* checks below
end_comment

begin_comment
comment|// are not inadvertently included in the diagnostic checking!
end_comment

begin_comment
comment|//      CHECK2: error: 'error' diagnostics expected but not seen:
end_comment

begin_comment
comment|// CHECK2-NEXT:   Line 41: define_error
end_comment

begin_comment
comment|// CHECK2-NEXT:   Line 43: line_error
end_comment

begin_comment
comment|// CHECK2-NEXT: error: 'error' diagnostics seen but not expected:
end_comment

begin_comment
comment|// CHECK2-NEXT:   Line 43: #line directive requires a positive integer argument
end_comment

begin_comment
comment|// CHECK2-NEXT:   Line 44: AAA // expected-error {{[{][{]BBB[}][}]}}<- this shall be part of diagnostic
end_comment

begin_comment
comment|// CHECK2-NEXT: error: 'warning' diagnostics expected but not seen:
end_comment

begin_comment
comment|// CHECK2-NEXT:   Line 42: undef_error
end_comment

begin_comment
comment|// CHECK2-NEXT: error: 'warning' diagnostics seen but not expected:
end_comment

begin_comment
comment|// CHECK2-NEXT:   Line 42: extra tokens at end of #undef directive
end_comment

begin_comment
comment|// CHECK2-NEXT:   Line 45: CCC // expected-warning {{[{][{]DDD[}][}]}}<- this shall be part of diagnostic
end_comment

begin_comment
comment|// CHECK2-NEXT: 7 errors generated.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TEST3
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|TEST3
end_ifndef

begin_comment
comment|// expected-note {{line_67}}
end_comment

begin_comment
comment|// expected-note {{line_68_ignored}}
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNDEFINED
end_ifdef

begin_comment
comment|// expected-note {{line_69_ignored}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-note {{line_70_ignored}}
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|TEST3
argument_list|)
end_elif

begin_comment
comment|// expected-note {{line_71}}
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|// expected-note {{line_72}}
end_comment

begin_comment
comment|// expected-note {{line_73}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// expected-note {{line_74}}
end_comment

begin_comment
comment|// expected-note {{line_75_ignored}}
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TEST3
end_ifndef

begin_comment
comment|// expected-note {{line_76_ignored}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-note {{line_77_ignored}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-note {{line_78}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//      CHECK3: error: 'note' diagnostics expected but not seen:
end_comment

begin_comment
comment|// CHECK3-NEXT:   Line 67: line_67
end_comment

begin_comment
comment|// CHECK3-NEXT:   Line 71: line_71
end_comment

begin_comment
comment|// CHECK3-NEXT:   Line 72: line_72
end_comment

begin_comment
comment|// CHECK3-NEXT:   Line 73: line_73
end_comment

begin_comment
comment|// CHECK3-NEXT:   Line 74: line_74
end_comment

begin_comment
comment|// CHECK3-NEXT:   Line 78: line_78
end_comment

begin_comment
comment|// CHECK3-NEXT: 6 errors generated.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TEST4
end_ifdef

begin_include
include|#
directive|include
file|"missing_header_file.include"
end_include

begin_comment
comment|// expected-error {{include_error}}
end_comment

begin_comment
comment|//      CHECK4: error: 'error' diagnostics expected but not seen:
end_comment

begin_comment
comment|// CHECK4-NEXT:   Line 92: include_error
end_comment

begin_comment
comment|// CHECK4-NEXT: error: 'error' diagnostics seen but not expected:
end_comment

begin_comment
comment|// CHECK4-NEXT:   Line 92: 'missing_header_file.include' file not found
end_comment

begin_comment
comment|// CHECK4-NEXT: 2 errors generated.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TEST5
end_ifdef

begin_include
include|#
directive|include
file|"verify-directive.h"
end_include

begin_comment
comment|// expected-error@50 {{source file test}}
end_comment

begin_comment
comment|//      CHECK5: error: 'error' diagnostics expected but not seen:
end_comment

begin_comment
comment|// CHECK5-NEXT:   Line 1 (directive at {{.*}}verify-directive.h:2): include file test
end_comment

begin_comment
comment|// CHECK5-NEXT:   Line 50 (directive at {{.*}}verify.c:103): source file test
end_comment

begin_comment
comment|// CHECK5-NEXT: 2 errors generated.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// RUN: not %clang_cc1 -verify %t.invalid 2>&1 | FileCheck -check-prefix=CHECK6 %s
end_comment

begin_comment
comment|//      CHECK6: error: no expected directives found: consider use of 'expected-no-diagnostics'
end_comment

begin_comment
comment|// CHECK6-NEXT: error: 'error' diagnostics seen but not expected:
end_comment

begin_comment
comment|// CHECK6-NEXT:   (frontend): error reading '{{.*}}verify.c.tmp.invalid'
end_comment

begin_comment
comment|// CHECK6-NEXT: 2 errors generated.
end_comment

begin_comment
comment|// RUN: printf '//expected-error@2{{1}}\n#error 2\n' | not %clang_cc1 -verify 2>&1 | FileCheck -check-prefix=CHECK7 %s
end_comment

begin_comment
comment|//      CHECK7: error: 'error' diagnostics expected but not seen:
end_comment

begin_comment
comment|// CHECK7-NEXT:   Line 2 (directive at<stdin>:1): 1
end_comment

begin_comment
comment|// CHECK7-NEXT: error: 'error' diagnostics seen but not expected:
end_comment

begin_comment
comment|// CHECK7-NEXT:   Line 2: 2
end_comment

begin_comment
comment|// CHECK7-NEXT: 2 errors generated.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TEST8
end_ifdef

begin_comment
comment|// RUN: not %clang_cc1 -DTEST8 -verify %s 2>&1 | FileCheck -check-prefix=CHECK8 %s
end_comment

begin_comment
comment|// expected-warning@nonexistent-file:1 {{ }}
end_comment

begin_comment
comment|// expected-error@-1 {{file 'nonexistent-file' could not be located}}
end_comment

begin_comment
comment|// expected-warning@verify-directive.h: {{ }}
end_comment

begin_comment
comment|// expected-error@-1 {{missing or invalid line number}}
end_comment

begin_comment
comment|// expected-warning@verify-directive.h:0 {{ }}
end_comment

begin_comment
comment|// expected-error@-1 {{missing or invalid line number}}
end_comment

begin_comment
comment|// expected-warning@verify-directive.h:0*{{ }}
end_comment

begin_comment
comment|// expected-error@-1 {{missing or invalid line number}}
end_comment

begin_comment
comment|// expected-warning@verify-directive.h:*0{{ }}
end_comment

begin_comment
comment|// syntactically ok -- means match in any line for 0 occurrences.
end_comment

begin_comment
comment|// expected-warning@verify-directive.h:1 {{diagnostic}}
end_comment

begin_comment
comment|//      CHECK8: error: 'warning' diagnostics expected but not seen:
end_comment

begin_comment
comment|// CHECK8-NEXT:   File {{.*}}verify-directive.h Line 1 (directive at {{.*}}verify.c:146): diagnostic
end_comment

begin_comment
comment|// CHECK8-NEXT: 1 error generated.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

