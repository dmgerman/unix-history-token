begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x c++ -emit-llvm -fshort-wchar %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Runs in c++ mode so that wchar_t is available.
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// This should convert to utf8.
comment|// CHECK: internal constant [10 x i8] c"\E1\84\A0\C8\A0\F4\82\80\B0\00", align 1
name|char
name|b
index|[
literal|10
index|]
init|=
literal|"\u1120\u0220\U00102030"
decl_stmt|;
comment|// CHECK: private unnamed_addr constant [6 x i8] c"A\00B\00\00\00"
specifier|const
name|wchar_t
modifier|*
name|foo
init|=
literal|L"AB"
decl_stmt|;
comment|// This should convert to utf16.
comment|// CHECK: private unnamed_addr constant [10 x i8] c" \11 \02\C8\DB0\DC\00\00"
specifier|const
name|wchar_t
modifier|*
name|bar
init|=
literal|L"\u1120\u0220\U00102030"
decl_stmt|;
comment|// Should pick second character.
comment|// CHECK: store i8 98
name|char
name|c
init|=
literal|'ab'
decl_stmt|;
comment|// CHECK: store i16 97
name|wchar_t
name|wa
init|=
literal|L'
expr|a'
decl_stmt|;
comment|// Should pick second character.
comment|// CHECK: store i16 98
name|wchar_t
name|wb
init|=
literal|L'
expr|ab'
decl_stmt|;
comment|// -4085 == 0xf00b
comment|// CHECK: store i16 -4085
name|wchar_t
name|wc
init|=
literal|L'
expr|\uF00B'
decl_stmt|;
comment|// Should take lower word of the 4byte UNC sequence. This does not match
comment|// gcc. I don't understand what gcc does (it looks like it converts to utf16,
comment|// then takes the second (!) utf16 word, swaps the lower two nibbles, and
comment|// stores that?).
comment|// CHECK: store i16 -4085
name|wchar_t
name|wd
init|=
literal|L'
expr|\U0010F00B'
decl_stmt|;
comment|// has utf16 encoding dbc8 dcb0
comment|// Should pick second character. (gcc: -9205)
comment|// CHECK: store i16 -4085
name|wchar_t
name|we
init|=
literal|L'
expr|\u1234\U0010F00B'
decl_stmt|;
block|}
end_function

end_unit

