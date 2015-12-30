begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fno-rtti -emit-llvm-only -triple i686-pc-win32 -fms-extensions -fdump-record-layouts %s 2>/dev/null \
end_comment

begin_comment
comment|// RUN:            | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fno-rtti -emit-llvm-only -triple x86_64-pc-win32 -fms-extensions -fdump-record-layouts %s 2>/dev/null \
end_comment

begin_comment
comment|// RUN:            | FileCheck %s
end_comment

begin_typedef
typedef|typedef
struct|struct
name|A
block|{
name|char
name|x
decl_stmt|;
name|int
name|a
range|:
literal|22
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|int
name|c
range|:
literal|10
decl_stmt|;
name|char
name|b
range|:
literal|3
decl_stmt|;
name|char
name|d
range|:
literal|4
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|A
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct A
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT: 4:0-21 |   int a
end_comment

begin_comment
comment|// CHECK-NEXT:    8:- |   int
end_comment

begin_comment
comment|// CHECK-NEXT:  8:0-9 |   int c
end_comment

begin_comment
comment|// CHECK-NEXT: 12:0-2 |   char b
end_comment

begin_comment
comment|// CHECK-NEXT: 12:3-6 |   char d
end_comment

begin_comment
comment|// CHECK-NEXT:     14 |   short y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=16, align=4]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|B
block|{
name|char
name|x
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|short
name|a
range|:
literal|4
decl_stmt|;
name|char
name|y
decl_stmt|;
block|}
name|B
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct B
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:    1:- |   int
end_comment

begin_comment
comment|// CHECK-NEXT:  2:0-3 |   short a
end_comment

begin_comment
comment|// CHECK-NEXT:      4 |   char y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=6, align=2]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|C
block|{
name|char
name|x
decl_stmt|;
name|short
name|a
range|:
literal|4
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|char
name|y
decl_stmt|;
block|}
name|C
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct C
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:  2:0-3 |   short a
end_comment

begin_comment
comment|// CHECK-NEXT:    4:- |   int
end_comment

begin_comment
comment|// CHECK-NEXT:      4 |   char y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=8, align=4]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|D
block|{
name|char
name|x
decl_stmt|;
name|short
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|char
name|y
decl_stmt|;
block|}
name|D
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct D
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:    1:- |   short
end_comment

begin_comment
comment|// CHECK-NEXT:    1:- |   int
end_comment

begin_comment
comment|// CHECK-NEXT:      1 |   char y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=2, align=1]
end_comment

begin_typedef
typedef|typedef
union|union
name|E
block|{
name|char
name|x
decl_stmt|;
name|long
name|long
name|a
range|:
literal|3
decl_stmt|;
name|int
name|b
range|:
literal|3
decl_stmt|;
name|long
name|long
range|:
literal|0
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|E
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | union E
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-2 |   long long a
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-2 |   int b
end_comment

begin_comment
comment|// CHECK-NEXT:    0:- |   long long
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   short
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=8, align=2]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|F
block|{
name|char
name|x
decl_stmt|;
name|char
name|a
range|:
literal|3
decl_stmt|;
name|char
name|b
range|:
literal|3
decl_stmt|;
name|char
name|c
range|:
literal|3
decl_stmt|;
name|short
name|d
range|:
literal|6
decl_stmt|;
name|short
name|e
range|:
literal|6
decl_stmt|;
name|short
name|f
range|:
literal|6
decl_stmt|;
name|short
name|g
range|:
literal|11
decl_stmt|;
name|short
name|h
range|:
literal|11
decl_stmt|;
name|short
name|i
range|:
literal|11
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|F
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct F
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:  1:0-2 |   char a
end_comment

begin_comment
comment|// CHECK-NEXT:  1:3-5 |   char b
end_comment

begin_comment
comment|// CHECK-NEXT:  2:0-2 |   char c
end_comment

begin_comment
comment|// CHECK-NEXT:  4:0-5 |   short d
end_comment

begin_comment
comment|// CHECK-NEXT: 4:6-11 |   short e
end_comment

begin_comment
comment|// CHECK-NEXT:  6:0-5 |   short f
end_comment

begin_comment
comment|// CHECK-NEXT: 8:0-10 |   short g
end_comment

begin_comment
comment|// CHECK-NEXT:10:0-10 |   short h
end_comment

begin_comment
comment|// CHECK-NEXT:12:0-10 |   short i
end_comment

begin_comment
comment|// CHECK-NEXT:     14 |   short y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=16, align=2]
end_comment

begin_typedef
typedef|typedef
union|union
name|G
block|{
name|char
name|x
decl_stmt|;
name|int
name|a
range|:
literal|3
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|long
name|long
range|:
literal|0
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|G
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | union G
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-2 |   int a
end_comment

begin_comment
comment|// CHECK-NEXT:    0:- |   int
end_comment

begin_comment
comment|// CHECK-NEXT:    0:- |   long long
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   short y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=4, align=2]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|H
block|{
name|unsigned
name|short
name|a
range|:
literal|1
decl_stmt|;
name|unsigned
name|char
range|:
literal|0
decl_stmt|;
name|unsigned
name|long
range|:
literal|0
decl_stmt|;
name|unsigned
name|short
name|c
range|:
literal|1
decl_stmt|;
block|}
name|H
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct H
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-0 |   unsigned short a
end_comment

begin_comment
comment|// CHECK-NEXT:    2:- |   unsigned char
end_comment

begin_comment
comment|// CHECK-NEXT:    2:- |   unsigned long
end_comment

begin_comment
comment|// CHECK-NEXT:  2:0-0 |   unsigned short c
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=4, align=2]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|I
block|{
name|short
label|:
literal|8
expr_stmt|;
name|__declspec
argument_list|(
argument|align(
literal|16
argument|)
argument_list|)
name|short
label|:
literal|8
expr_stmt|;
block|}
name|I
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct I
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-7 |   short
end_comment

begin_comment
comment|// CHECK-NEXT:  1:0-7 |   short
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=2, align=2]
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|A1
block|{
name|char
name|x
decl_stmt|;
name|int
name|a
range|:
literal|22
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|int
name|c
range|:
literal|10
decl_stmt|;
name|char
name|b
range|:
literal|3
decl_stmt|;
name|char
name|d
range|:
literal|4
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|A1
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct A1
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT: 1:0-21 |   int a
end_comment

begin_comment
comment|// CHECK-NEXT:    5:- |   int
end_comment

begin_comment
comment|// CHECK-NEXT:  5:0-9 |   int c
end_comment

begin_comment
comment|// CHECK-NEXT:  9:0-2 |   char b
end_comment

begin_comment
comment|// CHECK-NEXT:  9:3-6 |   char d
end_comment

begin_comment
comment|// CHECK-NEXT:     10 |   short y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=12, align=1]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|B1
block|{
name|char
name|x
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|short
name|a
range|:
literal|4
decl_stmt|;
name|char
name|y
decl_stmt|;
block|}
name|B1
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct B1
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:    1:- |   int
end_comment

begin_comment
comment|// CHECK-NEXT:  1:0-3 |   short
end_comment

begin_comment
comment|// CHECK-NEXT:      3 |   char y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=4, align=1]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|C1
block|{
name|char
name|x
decl_stmt|;
name|short
name|a
range|:
literal|4
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|char
name|y
decl_stmt|;
block|}
name|C1
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct C1
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:  1:0-3 |   short
end_comment

begin_comment
comment|// CHECK-NEXT:    3:- |   int
end_comment

begin_comment
comment|// CHECK-NEXT:      3 |   char y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=4, align=1]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|D1
block|{
name|char
name|x
decl_stmt|;
name|short
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|char
name|y
decl_stmt|;
block|}
name|D1
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct D1
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:    1:- |   short
end_comment

begin_comment
comment|// CHECK-NEXT:    1:- |   int
end_comment

begin_comment
comment|// CHECK-NEXT:      1 |   char y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=2, align=1]
end_comment

begin_typedef
typedef|typedef
union|union
name|E1
block|{
name|char
name|x
decl_stmt|;
name|long
name|long
name|a
range|:
literal|3
decl_stmt|;
name|int
name|b
range|:
literal|3
decl_stmt|;
name|long
name|long
range|:
literal|0
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|E1
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | union E1
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-2 |   long long a
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-2 |   int b
end_comment

begin_comment
comment|// CHECK-NEXT:    0:- |   long long
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   short y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=8, align=1]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|F1
block|{
name|char
name|x
decl_stmt|;
name|char
name|a
range|:
literal|3
decl_stmt|;
name|char
name|b
range|:
literal|3
decl_stmt|;
name|char
name|c
range|:
literal|3
decl_stmt|;
name|short
name|d
range|:
literal|6
decl_stmt|;
name|short
name|e
range|:
literal|6
decl_stmt|;
name|short
name|f
range|:
literal|6
decl_stmt|;
name|short
name|g
range|:
literal|11
decl_stmt|;
name|short
name|h
range|:
literal|11
decl_stmt|;
name|short
name|i
range|:
literal|11
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|F1
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct F1
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:  1:0-2 |   char a
end_comment

begin_comment
comment|// CHECK-NEXT:  1:3-5 |   char b
end_comment

begin_comment
comment|// CHECK-NEXT:  2:0-2 |   char c
end_comment

begin_comment
comment|// CHECK-NEXT:  3:0-5 |   short d
end_comment

begin_comment
comment|// CHECK-NEXT: 3:6-11 |   short e
end_comment

begin_comment
comment|// CHECK-NEXT:  5:0-5 |   short f
end_comment

begin_comment
comment|// CHECK-NEXT: 7:0-10 |   short g
end_comment

begin_comment
comment|// CHECK-NEXT: 9:0-10 |   short h
end_comment

begin_comment
comment|// CHECK-NEXT:11:0-10 |   short i
end_comment

begin_comment
comment|// CHECK-NEXT:     13 |   short y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=15, align=1]
end_comment

begin_typedef
typedef|typedef
union|union
name|G1
block|{
name|char
name|x
decl_stmt|;
name|int
name|a
range|:
literal|3
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|long
name|long
range|:
literal|0
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|G1
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | union G1
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   char x
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-2 |   int a
end_comment

begin_comment
comment|// CHECK-NEXT:    0:- |   int
end_comment

begin_comment
comment|// CHECK-NEXT:    0:- |   long long
end_comment

begin_comment
comment|// CHECK-NEXT:      0 |   short y
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=4, align=1]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|H1
block|{
name|unsigned
name|long
name|a
range|:
literal|1
decl_stmt|;
name|unsigned
name|char
range|:
literal|0
decl_stmt|;
name|unsigned
name|long
range|:
literal|0
decl_stmt|;
name|unsigned
name|long
name|c
range|:
literal|1
decl_stmt|;
block|}
name|H1
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct H1
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-0 |   unsigned long a
end_comment

begin_comment
comment|// CHECK-NEXT:    4:- |   unsigned char
end_comment

begin_comment
comment|// CHECK-NEXT:    4:- |   unsigned long
end_comment

begin_comment
comment|// CHECK-NEXT:  4:0-0 |   unsigned long c
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=8, align=1]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|I1
block|{
name|short
label|:
literal|8
expr_stmt|;
name|__declspec
argument_list|(
argument|align(
literal|16
argument|)
argument_list|)
name|short
label|:
literal|8
expr_stmt|;
block|}
name|I1
typedef|;
end_typedef

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:      0 | struct I1
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-7 |   short
end_comment

begin_comment
comment|// CHECK-NEXT:  1:0-7 |   short
end_comment

begin_comment
comment|// CHECK-NEXT:        | [sizeof=2, align=1]
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_decl_stmt
name|int
name|x
index|[
sizeof|sizeof
argument_list|(
name|A
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|B
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|C
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|D
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|E
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|F
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|G
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|H
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|I
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|A1
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|B1
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|C1
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|D1
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|E1
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|F1
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|G1
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|H1
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|I1
argument_list|)
operator|+
literal|0
index|]
decl_stmt|;
end_decl_stmt

end_unit

