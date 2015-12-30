begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm-only -triple armv7-apple-darwin -fdump-record-layouts %s 2>/dev/null \
end_comment

begin_comment
comment|// RUN:            | FileCheck %s
end_comment

begin_comment
comment|// rdar://22275433
end_comment

begin_pragma
pragma|#
directive|pragma
name|ms_struct
name|on
end_pragma

begin_union
union|union
name|A
block|{
name|unsigned
name|long
name|long
name|x
range|:
literal|32
decl_stmt|;
name|unsigned
name|long
name|long
name|y
range|:
literal|32
decl_stmt|;
block|}
name|a
union|;
end_union

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:        0 | union A
end_comment

begin_comment
comment|// CHECK-NEXT:   0:0-31 |   unsigned long long x
end_comment

begin_comment
comment|// CHECK-NEXT:   0:0-31 |   unsigned long long y
end_comment

begin_comment
comment|// CHECK-NEXT:          | [sizeof=8, align=1]
end_comment

begin_union
union|union
name|B
block|{
name|__attribute__
argument_list|(
argument|(aligned(
literal|4
argument|))
argument_list|)
name|unsigned
name|long
name|long
name|x
range|:
literal|32
decl_stmt|;
name|unsigned
name|long
name|long
name|y
range|:
literal|32
decl_stmt|;
block|}
name|b
union|;
end_union

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:       0 | union B
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-31 |   unsigned long long x
end_comment

begin_comment
comment|// CHECK-NEXT:  0:0-31 |   unsigned long long y
end_comment

begin_comment
comment|// CHECK-NEXT:         | [sizeof=8, align=1]
end_comment

begin_union
union|union
name|C
block|{
name|unsigned
name|long
name|long
range|:
literal|0
decl_stmt|;
name|unsigned
name|short
name|y
range|:
literal|8
decl_stmt|;
block|}
name|c
union|;
end_union

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:       0 | union C
end_comment

begin_comment
comment|// CHECK-NEXT:     0:- |   unsigned long long
end_comment

begin_comment
comment|// CHECK-NEXT:   0:0-7 |   unsigned short y
end_comment

begin_comment
comment|// CHECK-NEXT:         | [sizeof=2, align=1]
end_comment

begin_union
union|union
name|D
block|{
name|unsigned
name|long
name|long
range|:
literal|0
decl_stmt|;
name|unsigned
name|short
range|:
literal|0
decl_stmt|;
block|}
name|d
union|;
end_union

begin_comment
comment|// CHECK:*** Dumping AST Record Layout
end_comment

begin_comment
comment|// CHECK-NEXT:       0 | union D
end_comment

begin_comment
comment|// CHECK-NEXT:     0:- |   unsigned long long
end_comment

begin_comment
comment|// CHECK-NEXT:     0:- |   unsigned short
end_comment

begin_comment
comment|// CHECK-NEXT:         | [sizeof=1, align=1]
end_comment

end_unit

