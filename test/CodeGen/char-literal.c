begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x c++ -triple i386-unknown-unkown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Runs in c++ mode so that wchar_t is available.
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: store i8 97
name|char
name|a
init|=
literal|'a'
decl_stmt|;
comment|// Should pick second character.
comment|// CHECK: store i8 98
name|char
name|b
init|=
literal|'ab'
decl_stmt|;
comment|// CHECK: store i32 97
name|wchar_t
name|wa
init|=
literal|L'
expr|a'
decl_stmt|;
comment|// Should pick second character.
comment|// CHECK: store i32 98
name|wchar_t
name|wb
init|=
literal|L'
expr|ab'
decl_stmt|;
comment|// Should pick last character and store its lowest byte.
comment|// This does not match gcc, which takes the last character, converts it to
comment|// utf8, and then picks the second-lowest byte of that (they probably store
comment|// the utf8 in uint16_ts internally and take the lower byte of that).
comment|// CHECK: store i8 48
name|char
name|c
init|=
literal|'\u1120\u0220\U00102030'
decl_stmt|;
comment|// CHECK: store i32 61451
name|wchar_t
name|wc
init|=
literal|L'
expr|\uF00B'
decl_stmt|;
comment|// CHECK: store i32 1110027
name|wchar_t
name|wd
init|=
literal|L'
expr|\U0010F00B'
decl_stmt|;
comment|// Should pick second character.
comment|// CHECK: store i32 1110027
name|wchar_t
name|we
init|=
literal|L'
expr|\u1234\U0010F00B'
decl_stmt|;
block|}
end_function

end_unit

