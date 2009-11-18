begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc< %s -emit-llvm> %t1 -triple=i686-apple-darwin9
end_comment

begin_comment
comment|// RUN: grep "STest1 = type { i32, \[4 x i16\], double }" %t1
end_comment

begin_comment
comment|// RUN: grep "STest2 = type { i16, i16, i32, i32 }" %t1
end_comment

begin_comment
comment|// RUN: grep "STest3 = type { i8, i16, i32 }" %t1
end_comment

begin_comment
comment|// RUN: grep "STestB1 = type { i8, i8 }" %t1
end_comment

begin_comment
comment|// RUN: grep "STestB2 = type { i8, i8, i8 }" %t1
end_comment

begin_comment
comment|// RUN: grep "STestB3 = type { i8, i8 }" %t1
end_comment

begin_comment
comment|// RUN: grep "STestB4 = type { i8, i8, i8, i8 }" %t1
end_comment

begin_comment
comment|// RUN: grep "STestB5 = type { i8, i8, \[2 x i8\], i8, i8 }" %t1
end_comment

begin_comment
comment|// RUN: grep "STestB6 = type { i8, i8, \[2 x i8\] }" %t1
end_comment

begin_comment
comment|// Test struct layout for x86-darwin target
end_comment

begin_struct
struct|struct
name|STest1
block|{
name|int
name|x
decl_stmt|;
name|short
name|y
index|[
literal|4
index|]
decl_stmt|;
name|double
name|z
decl_stmt|;
block|}
name|st1
struct|;
end_struct

begin_struct
struct|struct
name|STest2
block|{
name|short
name|a
decl_stmt|,
name|b
decl_stmt|;
name|int
name|c
decl_stmt|,
name|d
decl_stmt|;
block|}
name|st2
struct|;
end_struct

begin_struct
struct|struct
name|STest3
block|{
name|char
name|a
decl_stmt|;
name|short
name|b
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
name|st3
struct|;
end_struct

begin_comment
comment|// Bitfields
end_comment

begin_struct
struct|struct
name|STestB1
block|{
name|char
name|a
decl_stmt|;
name|char
name|b
range|:
literal|2
decl_stmt|;
block|}
name|stb1
struct|;
end_struct

begin_struct
struct|struct
name|STestB2
block|{
name|char
name|a
decl_stmt|;
name|char
name|b
range|:
literal|5
decl_stmt|;
name|char
name|c
range|:
literal|4
decl_stmt|;
block|}
name|stb2
struct|;
end_struct

begin_struct
struct|struct
name|STestB3
block|{
name|char
name|a
decl_stmt|;
name|char
name|b
range|:
literal|2
decl_stmt|;
block|}
name|stb3
struct|;
end_struct

begin_struct
struct|struct
name|STestB4
block|{
name|char
name|a
decl_stmt|;
name|short
name|b
range|:
literal|2
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
name|stb4
struct|;
end_struct

begin_struct
struct|struct
name|STestB5
block|{
name|char
name|a
decl_stmt|;
name|short
name|b
range|:
literal|10
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
name|stb5
struct|;
end_struct

begin_struct
struct|struct
name|STestB6
block|{
name|int
name|a
range|:
literal|1
decl_stmt|;
name|char
name|b
decl_stmt|;
name|int
name|c
range|:
literal|13
block|}
name|stb6
struct|;
end_struct

begin_comment
comment|// Packed struct STestP1 {char a; short b; int c; } __attribute__((__packed__)) stp1;
end_comment

end_unit

