begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck -check-prefix=CHECK-C %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++0x -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck -check-prefix=CHECK-CPP0X %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++0x -fshort-wchar -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck -check-prefix=CHECK-SHORTWCHAR %s
end_comment

begin_comment
comment|// This file contains a mix of ISO-8859-1 and UTF-8 encoded data.
end_comment

begin_comment
comment|// the literal assigned to 'aa' should be the ISO-8859-1 encoding for the code
end_comment

begin_comment
comment|// points U+00C0 U+00E9 U+00EE U+00F5 U+00FC
end_comment

begin_comment
comment|// The rest of the literals should contain the UTF-8 encoding for U+041A U+043E
end_comment

begin_comment
comment|// U+0448 U+043A U+0430
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
endif|#
directive|endif
name|void
name|f
parameter_list|()
block|{
comment|// CHECK-C: private unnamed_addr constant [6 x i8] c"\C0\E9\EE\F5\FC\00", align 1
comment|// CHECK-CPP0X: private unnamed_addr constant [6 x i8] c"\C0\E9\EE\F5\FC\00", align 1
name|char
specifier|const
modifier|*
name|aa
init|=
literal|"Àéîõü"
decl_stmt|;
comment|// CHECK-C: private unnamed_addr constant [11 x i8] c"\D0\9A\D0\BE\D1\88\D0\BA\D0\B0\00", align 1
comment|// CHECK-CPP0X: private unnamed_addr constant [11 x i8] c"\D0\9A\D0\BE\D1\88\D0\BA\D0\B0\00", align 1
name|char
specifier|const
modifier|*
name|a
init|=
literal|"ÐÐ¾ÑÐºÐ°"
decl_stmt|;
comment|// CHECK-C: private unnamed_addr constant [6 x i32] [i32 1050, i32 1086, i32 1096, i32 1082, i32 1072, i32 0], align 4
comment|// CHECK-SHORTWCHAR: private unnamed_addr constant [6 x i16] [i16 1050, i16 1086, i16 1096, i16 1082, i16 1072, i16 0], align 2
comment|// CHECK-CPP0X: private unnamed_addr constant [6 x i32] [i32 1050, i32 1086, i32 1096, i32 1082, i32 1072, i32 0], align 4
name|wchar_t
specifier|const
modifier|*
name|b
init|=
literal|L"ÐÐ¾ÑÐºÐ°"
decl_stmt|;
comment|// CHECK-C: private unnamed_addr constant [4 x i32] [i32 20320, i32 22909, i32 66304, i32 0], align 4
comment|// CHECK-CPP0X: private unnamed_addr constant [4 x i32] [i32 20320, i32 22909, i32 66304, i32 0], align 4
if|#
directive|if
name|__WCHAR_MAX__
operator|==
literal|2147483647
name|wchar_t
specifier|const
modifier|*
name|b2
init|=
literal|L"\x4f60\x597d\x10300"
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
comment|// CHECK-CPP0X: private unnamed_addr constant [12 x i8] c"1\D0\9A\D0\BE\D1\88\D0\BA\D0\B0\00", align 1
name|char
specifier|const
modifier|*
name|c
init|=
literal|u8"1ÐÐ¾ÑÐºÐ°"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [7 x i16] [i16 50, i16 1050, i16 1086, i16 1096, i16 1082, i16 1072, i16 0], align 2
name|char16_t
specifier|const
modifier|*
name|e
init|=
literal|u"2ÐÐ¾ÑÐºÐ°"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [7 x i32] [i32 51, i32 1050, i32 1086, i32 1096, i32 1082, i32 1072, i32 0], align 4
name|char32_t
specifier|const
modifier|*
name|f
init|=
literal|U"3ÐÐ¾ÑÐºÐ°"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [12 x i8] c"4\D0\9A\D0\BE\D1\88\D0\BA\D0\B0\00", align 1
name|char
specifier|const
modifier|*
name|d
init|=
name|u8R
literal|"(4ÐÐ¾ÑÐºÐ°)"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [7 x i16] [i16 53, i16 1050, i16 1086, i16 1096, i16 1082, i16 1072, i16 0], align 2
name|char16_t
specifier|const
modifier|*
name|g
init|=
name|uR
literal|"(5ÐÐ¾ÑÐºÐ°)"
decl_stmt|;
comment|// CHECK-CPP0X: private unnamed_addr constant [7 x i32] [i32 54, i32 1050, i32 1086, i32 1096, i32 1082, i32 1072, i32 0], align 4
name|char32_t
specifier|const
modifier|*
name|h
init|=
name|UR
literal|"(6ÐÐ¾ÑÐºÐ°)"
decl_stmt|;
comment|// CHECK-SHORTWCHAR: private unnamed_addr constant [7 x i16] [i16 55, i16 1050, i16 1086, i16 1096, i16 1082, i16 1072, i16 0], align 2
comment|// CHECK-CPP0X: private unnamed_addr constant [7 x i32] [i32 55, i32 1050, i32 1086, i32 1096, i32 1082, i32 1072, i32 0], align 4
name|wchar_t
specifier|const
modifier|*
name|i
init|=
name|LR
literal|"(7ÐÐ¾ÑÐºÐ°)"
decl_stmt|;
endif|#
directive|endif
block|}
end_extern

end_unit

