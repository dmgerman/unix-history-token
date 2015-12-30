begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang -cc1 -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|a
value|b
end_define

begin_define
define|#
directive|define
name|b
value|c
end_define

begin_define
define|#
directive|define
name|c
parameter_list|(
name|x
parameter_list|)
value|d(x)
end_define

begin_define
define|#
directive|define
name|d
parameter_list|(
name|x
parameter_list|)
value|x*1
end_define

begin_define
define|#
directive|define
name|e
value|f
end_define

begin_define
define|#
directive|define
name|f
value|g
end_define

begin_define
define|#
directive|define
name|g
parameter_list|(
name|x
parameter_list|)
value|h(x)
end_define

begin_define
define|#
directive|define
name|h
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_function
name|void
name|PR16799
parameter_list|()
block|{
specifier|const
name|char
name|str
index|[]
init|=
literal|"string"
decl_stmt|;
name|a
argument_list|(
name|str
argument_list|)
expr_stmt|;
comment|// CHECK: :15:3: error: invalid operands to binary expression
comment|// CHECK:       ('const char *' and 'int')
comment|// CHECK:   a(str);
comment|// CHECK:   ^~~~~~
comment|// CHECK: :3:11: note: expanded from macro 'a'
comment|// CHECK: #define a b
comment|// CHECK:           ^
comment|// CHECK: :4:11: note: expanded from macro 'b'
comment|// CHECK: #define b c
comment|// CHECK:           ^
comment|// CHECK: :5:14: note: expanded from macro 'c'
comment|// CHECK: #define c(x) d(x)
comment|// CHECK:              ^~~~
comment|// CHECK: :6:15: note: expanded from macro 'd'
comment|// CHECK: #define d(x) x*1
comment|// CHECK:              ~^~
name|e
argument_list|(
name|str
argument_list|)
expr_stmt|;
comment|// CHECK: :33:5: warning: expression result unused
comment|// CHECK:   e(str);
comment|// CHECK:     ^~~
comment|// CHECK: :8:11: note: expanded from macro 'e'
comment|// CHECK: #define e f
comment|// CHECK:           ^
comment|// CHECK: :9:11: note: expanded from macro 'f'
comment|// CHECK: #define f g
comment|// CHECK:           ^
comment|// CHECK: :10:16: note: expanded from macro 'g'
comment|// CHECK: #define g(x) h(x)
comment|// CHECK:                ^
comment|// CHECK: :11:14: note: expanded from macro 'h'
comment|// CHECK: #define h(x) x
comment|// CHECK:              ^
block|}
end_function

begin_comment
comment|// CHECK: 1 warning and 1 error generated.
end_comment

end_unit

