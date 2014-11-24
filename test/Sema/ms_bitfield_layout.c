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
comment|// CHECK: Type: struct A
end_comment

begin_comment
comment|// CHECK:   Size:128
end_comment

begin_comment
comment|// CHECK:   Alignment:32
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 32, 64, 64, 96, 99, 112]>
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
comment|// CHECK: Type: struct B
end_comment

begin_comment
comment|// CHECK:   Size:48
end_comment

begin_comment
comment|// CHECK:   Alignment:16
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 8, 16, 32]>
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
comment|// CHECK: Type: struct C
end_comment

begin_comment
comment|// CHECK:   Size:64
end_comment

begin_comment
comment|// CHECK:   Alignment:32
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 16, 32, 32]>
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
comment|// CHECK: Type: struct D
end_comment

begin_comment
comment|// CHECK:   Size:16
end_comment

begin_comment
comment|// CHECK:   Alignment:8
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 8, 8, 8]>
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
comment|// CHECK: Type: union E
end_comment

begin_comment
comment|// CHECK:   Size:64
end_comment

begin_comment
comment|// CHECK:   Alignment:16
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 0, 0, 0, 0]>
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
comment|// CHECK: Type: struct F
end_comment

begin_comment
comment|// CHECK:   Size:128
end_comment

begin_comment
comment|// CHECK:   Alignment:16
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 8, 11, 16, 32, 38, 48, 64, 80, 96, 112]>
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
comment|// CHECK: Type: union G
end_comment

begin_comment
comment|// CHECK:   Size:32
end_comment

begin_comment
comment|// CHECK:   Alignment:16
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 0, 0, 0, 0]>
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
comment|// CHECK: Type: struct H
end_comment

begin_comment
comment|// CHECK:   Size:32
end_comment

begin_comment
comment|// CHECK:   Alignment:16
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 16, 16, 16]>
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
comment|// CHECK: Type: struct I
end_comment

begin_comment
comment|// CHECK:   Size:16
end_comment

begin_comment
comment|// CHECK:   Alignment:16
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 8]
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
comment|// CHECK: Type: struct A1
end_comment

begin_comment
comment|// CHECK:   Size:96
end_comment

begin_comment
comment|// CHECK:   Alignment:8
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 8, 40, 40, 72, 75, 80]>
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
comment|// CHECK: Type: struct B1
end_comment

begin_comment
comment|// CHECK:   Size:32
end_comment

begin_comment
comment|// CHECK:   Alignment:8
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 8, 8, 24]>
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
comment|// CHECK: Type: struct C1
end_comment

begin_comment
comment|// CHECK:   Size:32
end_comment

begin_comment
comment|// CHECK:   Alignment:8
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 8, 24, 24]>
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
comment|// CHECK: Type: struct D1
end_comment

begin_comment
comment|// CHECK:   Size:16
end_comment

begin_comment
comment|// CHECK:   Alignment:8
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 8, 8, 8]>
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
comment|// CHECK: Type: union E1
end_comment

begin_comment
comment|// CHECK:   Size:64
end_comment

begin_comment
comment|// CHECK:   Alignment:8
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 0, 0, 0, 0]>
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
comment|// CHECK: Type: struct F1
end_comment

begin_comment
comment|// CHECK:   Size:120
end_comment

begin_comment
comment|// CHECK:   Alignment:8
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 8, 11, 16, 24, 30, 40, 56, 72, 88, 104]>
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
comment|// CHECK: Type: union G1
end_comment

begin_comment
comment|// CHECK:   Size:32
end_comment

begin_comment
comment|// CHECK:   Alignment:8
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 0, 0, 0, 0]>
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
comment|// CHECK: Type: struct H1
end_comment

begin_comment
comment|// CHECK:   Size:64
end_comment

begin_comment
comment|// CHECK:   Alignment:8
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 32, 32, 32]>
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
comment|// CHECK: Type: struct I1
end_comment

begin_comment
comment|// CHECK:   Size:16
end_comment

begin_comment
comment|// CHECK:   Alignment:8
end_comment

begin_comment
comment|// CHECK:   FieldOffsets: [0, 8]
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

