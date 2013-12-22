begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck -check-prefix=CHECK-C %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck -check-prefix=CHECK-C %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++11 -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck -check-prefix=CHECK-CPP0X %s
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK-C: store i8 97
comment|// CHECK-CPP0X: store i8 97
name|char
name|a
init|=
literal|'a'
decl_stmt|;
comment|// Should truncate value (equal to last character).
comment|// CHECK-C: store i8 98
comment|// CHECK-CPP0X: store i8 98
name|char
name|b
init|=
literal|'ab'
decl_stmt|;
comment|// Should get concatenated characters
comment|// CHECK-C: store i32 24930
comment|// CHECK-CPP0X: store i32 24930
name|int
name|b1
init|=
literal|'ab'
decl_stmt|;
comment|// Should get concatenated characters
comment|// CHECK-C: store i32 808464432
comment|// CHECK-CPP0X: store i32 808464432
name|int
name|b2
init|=
literal|'0000'
decl_stmt|;
comment|// Should get truncated value (last four characters concatenated)
comment|// CHECK-C: store i32 1919512167
comment|// CHECK-CPP0X: store i32 1919512167
name|int
name|b3
init|=
literal|'somesillylongstring'
decl_stmt|;
comment|// CHECK-C: store i32 97
comment|// CHECK-CPP0X: store i32 97
name|wchar_t
name|wa
init|=
literal|L'
expr|a'
decl_stmt|;
comment|// Should pick second character.
comment|// CHECK-C: store i32 98
comment|// CHECK-CPP0X: store i32 98
name|wchar_t
name|wb
init|=
literal|L'
expr|ab'
decl_stmt|;
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
comment|// CHECK-CPP0X: store i16 97
name|char16_t
name|ua
init|=
literal|u'
expr|a'
decl_stmt|;
comment|// CHECK-CPP0X: store i32 97
name|char32_t
name|Ua
init|=
literal|U'
expr|a'
decl_stmt|;
comment|// CHECK-CPP0X: store i16 1047
name|char16_t
name|ua1
init|=
literal|u'
expr|Ð'
decl_stmt|;
comment|// CHECK-CPP0X: store i16 12538
name|char16_t
name|ua2
init|=
literal|u'
expr|ãº'
decl_stmt|;
comment|// CHECK-CPP0X: store i16 -27177
name|char16_t
name|ua3
init|=
literal|u'
expr|é'
decl_stmt|;
comment|// CHECK-CPP0X: store i32 181
name|char32_t
name|Ua1
init|=
literal|U'
expr|Âµ'
decl_stmt|;
comment|// CHECK-CPP0X: store i32 38359
name|char32_t
name|Ua2
init|=
literal|U'
expr|é'
decl_stmt|;
comment|// CHECK-CPP0X: store i32 128128
name|char32_t
name|Ua3
init|=
literal|U'
expr|ð'
decl_stmt|;
endif|#
directive|endif
comment|// CHECK-C: store i32 61451
comment|// CHECK-CPP0X: store i32 61451
name|wchar_t
name|wc
init|=
literal|L'
expr|\uF00B'
decl_stmt|;
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
comment|// -4085 == 0xf00b
comment|// CHECK-CPP0X: store i16 -4085
name|char16_t
name|uc
init|=
literal|u'
expr|\uF00B'
decl_stmt|;
comment|// CHECK-CPP0X: store i32 61451
name|char32_t
name|Uc
init|=
literal|U'
expr|\uF00B'
decl_stmt|;
endif|#
directive|endif
comment|// CHECK-C: store i32 1110027
comment|// CHECK-CPP0X: store i32 1110027
name|wchar_t
name|wd
init|=
literal|L'
expr|\U0010F00B'
decl_stmt|;
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
comment|// CHECK-CPP0X: store i32 1110027
name|char32_t
name|Ud
init|=
literal|U'
expr|\U0010F00B'
decl_stmt|;
endif|#
directive|endif
comment|// Should pick second character.
comment|// CHECK-C: store i32 1110027
comment|// CHECK-CPP0X: store i32 1110027
name|wchar_t
name|we
init|=
literal|L'
expr|\u1234\U0010F00B'
decl_stmt|;
block|}
end_function

end_unit

