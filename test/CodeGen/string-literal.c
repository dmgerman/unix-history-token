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
comment|// CHECK-C: private unnamed_addr constant [10 x i8] c"abc\00\00\00\00\00\00\00", align 1
comment|// CHECK-CPP0X: private unnamed_addr constant [10 x i8] c"abc\00\00\00\00\00\00\00", align 1
name|char
name|a
index|[
literal|10
index|]
init|=
literal|"abc"
decl_stmt|;
comment|// This should convert to utf8.
comment|// CHECK-C: private unnamed_addr constant [10 x i8] c"\E1\84\A0\C8\A0\F4\82\80\B0\00", align 1
comment|// CHECK-CPP0X: private unnamed_addr constant [10 x i8] c"\E1\84\A0\C8\A0\F4\82\80\B0\00", align 1
name|char
name|b
index|[
literal|10
index|]
init|=
literal|"\u1120\u0220\U00102030"
decl_stmt|;
comment|// CHECK-C: private unnamed_addr constant [12 x i8] c"A\00\00\00B\00\00\00\00\00\00\00", align 4
comment|// CHECK-CPP0X: private unnamed_addr constant [12 x i8] c"A\00\00\00B\00\00\00\00\00\00\00", align 4
specifier|const
name|wchar_t
modifier|*
name|foo
init|=
literal|L"AB"
decl_stmt|;
comment|// CHECK-C: private unnamed_addr constant [12 x i8] c"4\12\00\00\0B\F0\10\00\00\00\00\00", align 4
comment|// CHECK-CPP0X: private unnamed_addr constant [12 x i8] c"4\12\00\00\0B\F0\10\00\00\00\00\00", align 4
specifier|const
name|wchar_t
modifier|*
name|bar
init|=
literal|L"\u1234\U0010F00B"
decl_stmt|;
comment|// CHECK-C: private unnamed_addr constant [12 x i8] c"4\12\00\00\0C\F0\10\00\00\00\00\00", align 4
comment|// CHECK-CPP0X: private unnamed_addr constant [12 x i8] c"4\12\00\00\0C\F0\10\00\00\00\00\00", align 4
specifier|const
name|wchar_t
modifier|*
name|baz
init|=
literal|L"\u1234"
literal|"\U0010F00C"
decl_stmt|;
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
comment|// CHECK-CPP0X: private unnamed_addr constant [12 x i8] c"C\00\00\00D\00\00\00\00\00\00\00", align 4
specifier|const
name|char32_t
modifier|*
name|c
init|=
literal|U"CD"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [12 x i8] c"5\12\00\00\0C\F0\10\00\00\00\00\00", align 4
specifier|const
name|char32_t
modifier|*
name|d
init|=
literal|U"\u1235\U0010F00C"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [12 x i8] c"5\12\00\00\0B\F0\10\00\00\00\00\00", align 4
specifier|const
name|char32_t
modifier|*
name|o
init|=
literal|"\u1235"
literal|U"\U0010F00B"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [6 x i8] c"E\00F\00\00\00", align 2
specifier|const
name|char16_t
modifier|*
name|e
init|=
literal|u"EF"
decl_stmt|;
comment|// This should convert to utf16.
comment|// CHECK-CPP0X: private unnamed_addr constant [10 x i8] c" \11 \02\C8\DB0\DC\00\00", align 2
specifier|const
name|char16_t
modifier|*
name|f
init|=
literal|u"\u1120\u0220\U00102030"
decl_stmt|;
comment|// This should convert to utf16.
comment|// CHECK-CPP0X: private unnamed_addr constant [10 x i8] c" \11 \03\C8\DB0\DC\00\00", align 2
specifier|const
name|char16_t
modifier|*
name|p
init|=
literal|u"\u1120\u0320"
literal|"\U00102030"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [4 x i8] c"def\00", align 1
specifier|const
name|char
modifier|*
name|g
init|=
literal|u8"def"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [4 x i8] c"ghi\00", align 1
specifier|const
name|char
modifier|*
name|h
init|=
name|R
literal|"foo(ghi)foo"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [4 x i8] c"jkl\00", align 1
specifier|const
name|char
modifier|*
name|i
init|=
name|u8R
literal|"bar(jkl)bar"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [6 x i8] c"G\00H\00\00\00", align 2
specifier|const
name|char16_t
modifier|*
name|j
init|=
name|uR
literal|"foo(GH)foo"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [12 x i8] c"I\00\00\00J\00\00\00\00\00\00\00", align 4
specifier|const
name|char32_t
modifier|*
name|k
init|=
name|UR
literal|"bar(IJ)bar"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [12 x i8] c"K\00\00\00L\00\00\00\00\00\00\00", align 4
specifier|const
name|wchar_t
modifier|*
name|l
init|=
name|LR
literal|"bar(KL)bar"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [9 x i8] c"abc\5Cndef\00", align 1
specifier|const
name|char
modifier|*
name|m
init|=
name|R
literal|"(abc\ndef)"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [8 x i8] c"abc\0Adef\00", align 1
specifier|const
name|char
modifier|*
name|n
init|=
name|R
literal|"(abc def)"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [11 x i8] c"abc\0Adefghi\00", align 1
specifier|const
name|char
modifier|*
name|q
init|=
name|R
literal|"(abc def)"
literal|"ghi"
decl_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

