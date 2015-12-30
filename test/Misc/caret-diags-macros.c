begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s 2>&1 | FileCheck %s -strict-whitespace
end_comment

begin_define
define|#
directive|define
name|M1
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|M2
value|1;
end_define

begin_function
name|void
name|foo
parameter_list|()
block|{
name|M1
argument_list|(
name|M2
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:7:{{[0-9]+}}: warning: expression result unused
comment|// CHECK: {{.*}}:4:{{[0-9]+}}: note: expanded from macro 'M2'
comment|// CHECK: {{.*}}:3:{{[0-9]+}}: note: expanded from macro 'M1'
block|}
end_function

begin_define
define|#
directive|define
name|A
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|B
parameter_list|(
name|x
parameter_list|)
value|A(x)
end_define

begin_define
define|#
directive|define
name|C
parameter_list|(
name|x
parameter_list|)
value|B(x)
end_define

begin_function
name|void
name|bar
parameter_list|()
block|{
name|C
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:17:5: warning: expression result unused
block|}
end_function

begin_comment
comment|// rdar://7597492
end_comment

begin_define
define|#
directive|define
name|sprintf
parameter_list|(
name|str
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|__builtin___sprintf_chk (str, 0, 42, A, B)
end_define

begin_function
name|void
name|baz
parameter_list|(
name|char
modifier|*
name|Msg
parameter_list|)
block|{
name|sprintf
argument_list|(
name|Msg
argument_list|,
literal|"  sizeof FoooLib            : =%3u\n"
argument_list|,
literal|12LL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR9279: comprehensive tests for multi-level macro back traces
end_comment

begin_define
define|#
directive|define
name|macro_args1
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|macro_args2
parameter_list|(
name|x
parameter_list|)
value|macro_args1(x)
end_define

begin_define
define|#
directive|define
name|macro_args3
parameter_list|(
name|x
parameter_list|)
value|macro_args2(x)
end_define

begin_define
define|#
directive|define
name|macro_many_args1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|y
end_define

begin_define
define|#
directive|define
name|macro_many_args2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|macro_many_args1(x, y, z)
end_define

begin_define
define|#
directive|define
name|macro_many_args3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|macro_many_args2(x, y, z)
end_define

begin_function
name|void
name|test
parameter_list|()
block|{
name|macro_args3
argument_list|(
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:40:15: warning: expression result unused
comment|// Also check that the 'caret' printing agrees with the location here where
comment|// its easy to FileCheck.
comment|// CHECK-NEXT:      macro_args3(11);
comment|// CHECK-NEXT: {{^              \^~}}
name|macro_many_args3
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:49:5: warning: expression result unused
comment|// CHECK: {{.*}}:37:55: note: expanded from macro 'macro_many_args3'
comment|// CHECK: {{.*}}:36:55: note: expanded from macro 'macro_many_args2'
comment|// CHECK: {{.*}}:35:35: note: expanded from macro 'macro_many_args1'
name|macro_many_args3
argument_list|(
literal|1
argument_list|,
name|M2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:58:5: warning: expression result unused
comment|// CHECK: {{.*}}:4:12: note: expanded from macro 'M2'
comment|// CHECK: {{.*}}:37:55: note: expanded from macro 'macro_many_args3'
comment|// CHECK: {{.*}}:36:55: note: expanded from macro 'macro_many_args2'
comment|// CHECK: {{.*}}:35:35: note: expanded from macro 'macro_many_args1'
name|macro_many_args3
argument_list|(
literal|1
argument_list|,
name|macro_args2
argument_list|(
literal|22
argument_list|)
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:68:17: warning: expression result unused
comment|// This caret location needs to be printed *inside* a different macro's
comment|// arguments.
comment|// CHECK-NEXT:        macro_args2(22),
comment|// CHECK-NEXT: {{^                \^~}}
comment|// CHECK: {{.*}}:32:36: note: expanded from macro 'macro_args2'
comment|// CHECK: {{.*}}:31:24: note: expanded from macro 'macro_args1'
comment|// CHECK: {{.*}}:37:55: note: expanded from macro 'macro_many_args3'
comment|// CHECK: {{.*}}:36:55: note: expanded from macro 'macro_many_args2'
comment|// CHECK: {{.*}}:35:35: note: expanded from macro 'macro_many_args1'
block|}
end_function

begin_define
define|#
directive|define
name|variadic_args1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
modifier|...
parameter_list|)
value|y
end_define

begin_define
define|#
directive|define
name|variadic_args2
parameter_list|(
name|x
parameter_list|,
modifier|...
parameter_list|)
value|variadic_args1(x, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|variadic_args3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
modifier|...
parameter_list|)
value|variadic_args2(x, y, __VA_ARGS__)
end_define

begin_function
name|void
name|test2
parameter_list|()
block|{
name|variadic_args3
argument_list|(
literal|1
argument_list|,
literal|22
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:87:21: warning: expression result unused
comment|// CHECK-NEXT:      variadic_args3(1, 22, 3, 4);
comment|// CHECK-NEXT: {{^                    \^~}}
comment|// CHECK: {{.*}}:84:53: note: expanded from macro 'variadic_args3'
comment|// CHECK: {{.*}}:83:50: note: expanded from macro 'variadic_args2'
comment|// CHECK: {{.*}}:82:35: note: expanded from macro 'variadic_args1'
block|}
end_function

begin_define
define|#
directive|define
name|variadic_pasting_args1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|y
end_define

begin_define
define|#
directive|define
name|variadic_pasting_args2
parameter_list|(
name|x
parameter_list|,
modifier|...
parameter_list|)
value|variadic_pasting_args1(x ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|variadic_pasting_args2a
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
modifier|...
parameter_list|)
value|variadic_pasting_args1(x, y ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|variadic_pasting_args3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
modifier|...
parameter_list|)
value|variadic_pasting_args2(x, y, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|variadic_pasting_args3a
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
modifier|...
parameter_list|)
value|variadic_pasting_args2a(x, y, __VA_ARGS__)
end_define

begin_function
name|void
name|test3
parameter_list|()
block|{
name|variadic_pasting_args3
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:103:32: warning: expression result unused
comment|// CHECK: {{.*}}:99:72: note: expanded from macro 'variadic_pasting_args3'
comment|// CHECK: {{.*}}:97:68: note: expanded from macro 'variadic_pasting_args2'
comment|// CHECK: {{.*}}:96:41: note: expanded from macro 'variadic_pasting_args1'
name|variadic_pasting_args3a
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK:        {{.*}}:109:3: warning: expression result unused
comment|// CHECK-NEXT:     variadic_pasting_args3a(1, 2, 3, 4);
comment|// CHECK-NEXT: {{  \^~~~~~~~~~~~~~~~~~~~~~~}}
comment|// CHECK:        {{.*}}:100:44: note: expanded from macro 'variadic_pasting_args3a'
comment|// CHECK-NEXT:   #define variadic_pasting_args3a(x, y, ...) variadic_pasting_args2a(x, y, __VA_ARGS__)
comment|// CHECK-NEXT: {{                                           \^~~~~~~~~~~~~~~~~~~~~~~}}
comment|// CHECK:        {{.*}}:98:70: note: expanded from macro 'variadic_pasting_args2a'
comment|// CHECK-NEXT:   #define variadic_pasting_args2a(x, y, ...) variadic_pasting_args1(x, y ## __VA_ARGS__)
comment|// CHECK-NEXT: {{                                                                     \^~~~~~~~~~~~~~~~}}
comment|// CHECK:        {{.*}}:96:41: note: expanded from macro 'variadic_pasting_args1'
comment|// CHECK-NEXT:   #define variadic_pasting_args1(x, y, z) y
comment|// CHECK-NEXT: {{                                        \^}}
block|}
end_function

begin_define
define|#
directive|define
name|BAD_CONDITIONAL_OPERATOR
value|(2<3)?2:3
end_define

begin_decl_stmt
name|int
name|test4
init|=
name|BAD_CONDITIONAL_OPERATOR
operator|+
name|BAD_CONDITIONAL_OPERATOR
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:         {{.*}}:124:39: note: expanded from macro 'BAD_CONDITIONAL_OPERATOR'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define BAD_CONDITIONAL_OPERATOR (2<3)?2:3
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                      \^}}
end_comment

begin_comment
comment|// CHECK:         {{.*}}:124:39: note: expanded from macro 'BAD_CONDITIONAL_OPERATOR'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define BAD_CONDITIONAL_OPERATOR (2<3)?2:3
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                      \^}}
end_comment

begin_comment
comment|// CHECK:         {{.*}}:124:39: note: expanded from macro 'BAD_CONDITIONAL_OPERATOR'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define BAD_CONDITIONAL_OPERATOR (2<3)?2:3
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                 ~~~~~\^~~~}}
end_comment

begin_define
define|#
directive|define
name|QMARK
value|?
end_define

begin_define
define|#
directive|define
name|TWOL
value|(2<
end_define

begin_define
define|#
directive|define
name|X
value|1+TWOL 3) QMARK 4:5
end_define

begin_decl_stmt
name|int
name|x
init|=
name|X
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:         {{.*}}:139:9: note: place parentheses around the '+' expression to silence this warning
end_comment

begin_comment
comment|// CHECK-NEXT:    int x = X;
end_comment

begin_comment
comment|// CHECK-NEXT: {{^        \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:138:21: note: expanded from macro 'X'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define X 1+TWOL 3) QMARK 4:5
end_comment

begin_comment
comment|// CHECK-NEXT: {{^          ~~~~~~~~~ \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:136:15: note: expanded from macro 'QMARK'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define QMARK ?
end_comment

begin_comment
comment|// CHECK-NEXT: {{^              \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:139:9: note: place parentheses around the '?:' expression to evaluate it first
end_comment

begin_comment
comment|// CHECK-NEXT:    int x = X;
end_comment

begin_comment
comment|// CHECK-NEXT: {{^        \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:138:21: note: expanded from macro 'X'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define X 1+TWOL 3) QMARK 4:5
end_comment

begin_comment
comment|// CHECK-NEXT: {{^            ~~~~~~~~\^~~~~~~~~}}
end_comment

begin_define
define|#
directive|define
name|ONEPLUS
value|1+
end_define

begin_define
define|#
directive|define
name|Y
value|ONEPLUS (2<3) QMARK 4:5
end_define

begin_decl_stmt
name|int
name|y
init|=
name|Y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:         {{.*}}:158:9: warning: operator '?:' has lower precedence than '+'; '+' will be evaluated first
end_comment

begin_comment
comment|// CHECK-NEXT:    int y = Y;
end_comment

begin_comment
comment|// CHECK-NEXT: {{^        \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:157:25: note: expanded from macro 'Y'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define Y ONEPLUS (2<3) QMARK 4:5
end_comment

begin_comment
comment|// CHECK-NEXT: {{^          ~~~~~~~~~~~~~ \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:136:15: note: expanded from macro 'QMARK'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define QMARK ?
end_comment

begin_comment
comment|// CHECK-NEXT: {{^              \^}}
end_comment

begin_comment
comment|// PR14399
end_comment

begin_function_decl
name|void
name|iequals
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo_aa
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
block|{
define|#
directive|define
comment|/* */
name|BARC
parameter_list|(
name|c
parameter_list|,
comment|/* */
name|b
parameter_list|,
name|a
parameter_list|)
value|(a + b ? c : c)
name|iequals
argument_list|(
name|__LINE__
argument_list|,
name|BARC
argument_list|(
literal|123
argument_list|,
operator|(
literal|456
operator|<
literal|345
operator|)
argument_list|,
literal|789
argument_list|)
argument_list|,
literal|8
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK:         {{.*}}:174:21: warning: operator '?:' has lower precedence than '+'
end_comment

begin_comment
comment|// CHECK-NEXT:      iequals(__LINE__, BARC(123, (456< 345), 789), 8);
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                    \^~~~~~~~~~~~~~~~~~~~~~~~~~~}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:173:41: note: expanded from macro 'BARC'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define /* */ BARC(c, /* */b, a) (a + b ? c : c)
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                  ~~~~~ \^}}
end_comment

begin_define
define|#
directive|define
name|APPEND2
parameter_list|(
name|NUM
parameter_list|,
name|SUFF
parameter_list|)
value|-1 != NUM ## SUFF
end_define

begin_define
define|#
directive|define
name|APPEND
parameter_list|(
name|NUM
parameter_list|,
name|SUFF
parameter_list|)
value|APPEND2(NUM, SUFF)
end_define

begin_define
define|#
directive|define
name|UTARG_MAX_U
value|APPEND (MAX_UINT, UL)
end_define

begin_define
define|#
directive|define
name|MAX_UINT
value|18446744073709551615
end_define

begin_if
if|#
directive|if
name|UTARG_MAX_U
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK:         {{.*}}:187:5: warning: left side of operator converted from negative value to unsigned: -1 to 18446744073709551615
end_comment

begin_comment
comment|// CHECK-NEXT:    #if UTARG_MAX_U
end_comment

begin_comment
comment|// CHECK-NEXT: {{^    \^~~~~~~~~~~}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:185:21: note: expanded from macro 'UTARG_MAX_U'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define UTARG_MAX_U APPEND (MAX_UINT, UL)
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                    \^~~~~~~~~~~~~~~~~~~~~}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:184:27: note: expanded from macro 'APPEND'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define APPEND(NUM, SUFF) APPEND2(NUM, SUFF)
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                          \^~~~~~~~~~~~~~~~~~}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:183:31: note: expanded from macro 'APPEND2'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define APPEND2(NUM, SUFF) -1 != NUM ## SUFF
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                           ~~ \^  ~~~~~~~~~~~}}
end_comment

begin_function_decl
name|unsigned
name|long
name|strlen_test
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|__darwin_obsz
parameter_list|(
name|object
parameter_list|)
value|__builtin_object_size (object, 1)
end_define

begin_define
define|#
directive|define
name|sprintf2
parameter_list|(
name|str
parameter_list|,
modifier|...
parameter_list|)
define|\
value|__builtin___sprintf_chk (str, 0, __darwin_obsz(str), __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|Cstrlen
parameter_list|(
name|a
parameter_list|)
value|strlen_test(a)
end_define

begin_define
define|#
directive|define
name|Csprintf
value|sprintf2
end_define

begin_function
name|void
name|f
parameter_list|(
name|char
modifier|*
name|pMsgBuf
parameter_list|,
name|char
modifier|*
name|pKeepBuf
parameter_list|)
block|{
name|Csprintf
argument_list|(
name|pMsgBuf
argument_list|,
literal|"\nEnter minimum anagram length (2-%1d): "
argument_list|,
name|strlen_test
argument_list|(
name|pKeepBuf
argument_list|)
argument_list|)
expr_stmt|;
comment|// FIXME: Change test to use 'Cstrlen' instead of 'strlen_test' when macro printing is fixed.
block|}
end_function

begin_comment
comment|// CHECK:         {{.*}}:210:62: warning: format specifies type 'int' but the argument has type 'unsigned long'
end_comment

begin_comment
comment|// CHECK-NEXT:    Csprintf(pMsgBuf,"\nEnter minimum anagram length (2-%1d): ", strlen_test(pKeepBuf));
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                                    ~~~      \^~~~~~~~~~~~~~~~~~~~~}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                                    %1lu}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:208:21: note: expanded from macro 'Csprintf'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define Csprintf    sprintf2
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                    \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:206:56: note: expanded from macro 'sprintf2'
end_comment

begin_comment
comment|// CHECK-NEXT:      __builtin___sprintf_chk (str, 0, __darwin_obsz(str), __VA_ARGS__)
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                                       \^~~~~~~~~~~}}
end_comment

begin_define
define|#
directive|define
name|SWAP_AND_APPLY
parameter_list|(
name|arg
parameter_list|,
name|macro
parameter_list|)
value|macro arg
end_define

begin_define
define|#
directive|define
name|APPLY
parameter_list|(
name|macro
parameter_list|,
name|arg
parameter_list|)
value|macro arg
end_define

begin_define
define|#
directive|define
name|DECLARE_HELPER
parameter_list|()
value|__builtin_printf("%d\n", mylong);
end_define

begin_function
name|void
name|use_evil_macros
parameter_list|(
name|long
name|mylong
parameter_list|)
block|{
name|SWAP_AND_APPLY
argument_list|(
argument|()
argument_list|,
argument|DECLARE_HELPER
argument_list|)
name|APPLY
argument_list|(
argument|DECLARE_HELPER
argument_list|,
argument|()
argument_list|)
block|}
end_function

begin_comment
comment|// CHECK:      {{.*}}:228:22: warning: format specifies type 'int' but the argument has type 'long'
end_comment

begin_comment
comment|// CHECK-NEXT:   SWAP_AND_APPLY((), DECLARE_HELPER)
end_comment

begin_comment
comment|// CHECK-NEXT:   ~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~
end_comment

begin_comment
comment|// CHECK-NEXT: {{.*}}:224:36: note: expanded from macro 'SWAP_AND_APPLY'
end_comment

begin_comment
comment|// CHECK-NEXT: #define SWAP_AND_APPLY(arg, macro) macro arg
end_comment

begin_comment
comment|// CHECK-NEXT:                                    ^~~~~~~~~
end_comment

begin_comment
comment|// CHECK-NEXT: {{.*}}:226:51: note: expanded from macro 'DECLARE_HELPER'
end_comment

begin_comment
comment|// CHECK-NEXT: #define DECLARE_HELPER() __builtin_printf("%d\n", mylong);
end_comment

begin_comment
comment|// CHECK-NEXT:                                            ~~     ^~~~~~
end_comment

begin_comment
comment|// CHECK-NEXT: {{.*}}:229:9: warning: format specifies type 'int' but the argument has type 'long'
end_comment

begin_comment
comment|// CHECK-NEXT:   APPLY(DECLARE_HELPER, ())
end_comment

begin_comment
comment|// CHECK-NEXT:   ~~~~~~^~~~~~~~~~~~~~~~~~~
end_comment

begin_comment
comment|// CHECK-NEXT: {{.*}}:225:27: note: expanded from macro 'APPLY'
end_comment

begin_comment
comment|// CHECK-NEXT: #define APPLY(macro, arg) macro arg
end_comment

begin_comment
comment|// CHECK-NEXT:                           ^~~~~~~~~
end_comment

begin_comment
comment|// CHECK-NEXT: {{.*}}:226:51: note: expanded from macro 'DECLARE_HELPER'
end_comment

begin_comment
comment|// CHECK-NEXT: #define DECLARE_HELPER() __builtin_printf("%d\n", mylong);
end_comment

begin_comment
comment|// CHECK-NEXT:                                            ~~     ^~~~~~
end_comment

end_unit

