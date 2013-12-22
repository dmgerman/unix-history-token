begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang -fsyntax-only -fmacro-backtrace-limit=0 %s 2>&1 | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|FOO
value|1+"hi"
end_define

begin_define
define|#
directive|define
name|BAR
value|FOO
end_define

begin_define
define|#
directive|define
name|BAZ
value|BAR
end_define

begin_define
define|#
directive|define
name|QUZ
value|BAZ
end_define

begin_define
define|#
directive|define
name|TAZ
value|QUZ
end_define

begin_define
define|#
directive|define
name|ABA
value|TAZ
end_define

begin_define
define|#
directive|define
name|BAB
value|ABA
end_define

begin_define
define|#
directive|define
name|ZAZ
value|BAB
end_define

begin_define
define|#
directive|define
name|WAZ
value|ZAZ
end_define

begin_define
define|#
directive|define
name|DROOL
value|WAZ
end_define

begin_define
define|#
directive|define
name|FOOL
value|DROOL
end_define

begin_expr_stmt
name|FOOL
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK: :15:1: error: expected identifier or '('
end_comment

begin_comment
comment|// CHECK: FOOL
end_comment

begin_comment
comment|// CHECK: ^
end_comment

begin_comment
comment|// CHECK: :13:14: note: expanded from macro 'FOOL'
end_comment

begin_comment
comment|// CHECK: #define FOOL DROOL
end_comment

begin_comment
comment|// CHECK:              ^
end_comment

begin_comment
comment|// CHECK: :12:15: note: expanded from macro 'DROOL'
end_comment

begin_comment
comment|// CHECK: #define DROOL WAZ
end_comment

begin_comment
comment|// CHECK:               ^
end_comment

begin_comment
comment|// CHECK: :11:13: note: expanded from macro 'WAZ'
end_comment

begin_comment
comment|// CHECK: #define WAZ ZAZ
end_comment

begin_comment
comment|// CHECK:             ^
end_comment

begin_comment
comment|// CHECK: :10:13: note: expanded from macro 'ZAZ'
end_comment

begin_comment
comment|// CHECK: #define ZAZ BAB
end_comment

begin_comment
comment|// CHECK:             ^
end_comment

begin_comment
comment|// CHECK: :9:13: note: expanded from macro 'BAB'
end_comment

begin_comment
comment|// CHECK: #define BAB ABA
end_comment

begin_comment
comment|// CHECK:             ^
end_comment

begin_comment
comment|// CHECK: :8:13: note: expanded from macro 'ABA'
end_comment

begin_comment
comment|// CHECK: #define ABA TAZ
end_comment

begin_comment
comment|// CHECK:             ^
end_comment

begin_comment
comment|// CHECK: :7:13: note: expanded from macro 'TAZ'
end_comment

begin_comment
comment|// CHECK: #define TAZ QUZ
end_comment

begin_comment
comment|// CHECK:             ^
end_comment

begin_comment
comment|// CHECK: :6:13: note: expanded from macro 'QUZ'
end_comment

begin_comment
comment|// CHECK: #define QUZ BAZ
end_comment

begin_comment
comment|// CHECK:             ^
end_comment

begin_comment
comment|// CHECK: :5:13: note: expanded from macro 'BAZ'
end_comment

begin_comment
comment|// CHECK: #define BAZ BAR
end_comment

begin_comment
comment|// CHECK:             ^
end_comment

begin_comment
comment|// CHECK: :4:13: note: expanded from macro 'BAR'
end_comment

begin_comment
comment|// CHECK: #define BAR FOO
end_comment

begin_comment
comment|// CHECK:             ^
end_comment

begin_comment
comment|// CHECK: :3:13: note: expanded from macro 'FOO'
end_comment

begin_comment
comment|// CHECK: #define FOO 1+"hi"
end_comment

begin_comment
comment|// CHECK:             ^
end_comment

begin_define
define|#
directive|define
name|ADD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a ## #b
end_define

begin_macro
name|ADD
argument_list|(
argument|L
argument_list|,
argument|foo
argument_list|)
end_macro

begin_comment
comment|// CHECK:    error: expected identifier or '('
end_comment

begin_comment
comment|// CHECK:    ADD(L, foo)
end_comment

begin_comment
comment|// CHECK: {{^\^}}
end_comment

begin_comment
comment|// CHECK:    note: expanded from macro 'ADD'
end_comment

begin_comment
comment|// CHECK:    #define ADD(a, b) a ## #b
end_comment

begin_comment
comment|// CHECK: {{^                  \^}}
end_comment

begin_comment
comment|// CHECK:    note: expanded from here
end_comment

begin_comment
comment|// CHECK:    L"foo"
end_comment

begin_comment
comment|// CHECK: {{^\^}}
end_comment

begin_comment
comment|// CHECK: 2 errors generated.
end_comment

end_unit

