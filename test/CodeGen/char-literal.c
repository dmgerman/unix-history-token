begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck -check-prefix=C %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck -check-prefix=C %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++11 -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck -check-prefix=CPP0X %s
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
comment|// Should pick second character.
comment|// CHECK-C: store i8 98
comment|// CHECK-CPP0X: store i8 98
name|char
name|b
init|=
literal|'ab'
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
comment|// Should pick second character.
comment|// CHECK-CPP0X: store i16 98
name|char16_t
name|ub
init|=
literal|u'
expr|ab'
decl_stmt|;
comment|// CHECK-CPP0X: store i32 97
name|char32_t
name|Ua
init|=
literal|U'
expr|a'
decl_stmt|;
comment|// Should pick second character.
comment|// CHECK-CPP0X: store i32 98
name|char32_t
name|Ub
init|=
literal|U'
expr|ab'
decl_stmt|;
endif|#
directive|endif
comment|// Should pick last character and store its lowest byte.
comment|// This does not match gcc, which takes the last character, converts it to
comment|// utf8, and then picks the second-lowest byte of that (they probably store
comment|// the utf8 in uint16_ts internally and take the lower byte of that).
comment|// CHECK-C: store i8 48
comment|// CHECK-CPP0X: store i8 48
name|char
name|c
init|=
literal|'\u1120\u0220\U00102030'
decl_stmt|;
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
comment|// Should take lower word of the 4byte UNC sequence. This does not match
comment|// gcc. I don't understand what gcc does (it looks like it converts to utf16,
comment|// then takes the second (!) utf16 word, swaps the lower two nibbles, and
comment|// stores that?).
comment|// CHECK-CPP0X: store i16 -4085
name|char16_t
name|ud
init|=
literal|u'
expr|\U0010F00B'
decl_stmt|;
comment|// has utf16 encoding dbc8 dcb0
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
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
comment|// Should pick second character.
comment|// CHECK-CPP0X: store i16 -4085
name|char16_t
name|ue
init|=
literal|u'
expr|\u1234\U0010F00B'
decl_stmt|;
comment|// Should pick second character.
comment|// CHECK-CPP0X: store i32 1110027
name|char32_t
name|Ue
init|=
literal|U'
expr|\u1234\U0010F00B'
decl_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

