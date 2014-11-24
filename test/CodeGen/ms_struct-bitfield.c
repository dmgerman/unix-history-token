begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple x86_64-apple-darwin9 %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple thumbv7-apple-ios -target-abi apcs-gnu %s | FileCheck %s -check-prefix=CHECK-ARM
end_comment

begin_comment
comment|// rdar://8823265
end_comment

begin_comment
comment|// Note that we're declaring global variables with these types,
end_comment

begin_comment
comment|// triggering both Sema and IRGen struct layout.
end_comment

begin_define
define|#
directive|define
name|ATTR
value|__attribute__((__ms_struct__))
end_define

begin_struct
struct|struct
block|{
name|char
name|foo
decl_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
name|bar
decl_stmt|;
block|}
name|ATTR
name|t1
struct|;
end_struct

begin_decl_stmt
name|int
name|s1
init|=
sizeof|sizeof
argument_list|(
name|t1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s1 = global i32 2
end_comment

begin_comment
comment|// CHECK-ARM: @s1 = global i32 2
end_comment

begin_struct
struct|struct
block|{
name|char
name|foo
decl_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|char
name|bar
decl_stmt|;
block|}
name|ATTR
name|t2
struct|;
end_struct

begin_decl_stmt
name|int
name|s2
init|=
sizeof|sizeof
argument_list|(
name|t2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s2 = global i32 2
end_comment

begin_comment
comment|// CHECK-ARM: @s2 = global i32 2
end_comment

begin_struct
struct|struct
block|{
name|char
name|foo
decl_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|char
name|bar
decl_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
label|:
literal|0
expr_stmt|;
block|}
name|ATTR
name|t3
struct|;
end_struct

begin_decl_stmt
name|int
name|s3
init|=
sizeof|sizeof
argument_list|(
name|t3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s3 = global i32 2
end_comment

begin_comment
comment|// CHECK-ARM: @s3 = global i32 2
end_comment

begin_struct
struct|struct
block|{
name|long
label|:
literal|0
expr_stmt|;
name|char
name|bar
decl_stmt|;
block|}
name|ATTR
name|t4
struct|;
end_struct

begin_decl_stmt
name|int
name|s4
init|=
sizeof|sizeof
argument_list|(
name|t4
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s4 = global i32 1
end_comment

begin_comment
comment|// CHECK-ARM: @s4 = global i32 1
end_comment

begin_struct
struct|struct
block|{
name|long
label|:
literal|0
expr_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|char
name|bar
decl_stmt|;
block|}
name|ATTR
name|t5
struct|;
end_struct

begin_decl_stmt
name|int
name|s5
init|=
sizeof|sizeof
argument_list|(
name|t5
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s5 = global i32 1
end_comment

begin_comment
comment|// CHECK-ARM: @s5 = global i32 1
end_comment

begin_struct
struct|struct
block|{
name|long
label|:
literal|0
expr_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|char
name|bar
decl_stmt|;
block|}
name|ATTR
name|t6
struct|;
end_struct

begin_decl_stmt
name|int
name|s6
init|=
sizeof|sizeof
argument_list|(
name|t6
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s6 = global i32 1
end_comment

begin_comment
comment|// CHECK-ARM: @s6 = global i32 1
end_comment

begin_struct
struct|struct
block|{
name|char
name|foo
decl_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|char
name|bar
decl_stmt|;
name|char
name|bar1
decl_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
name|bar2
decl_stmt|;
name|char
name|bar3
decl_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|char
name|bar4
decl_stmt|;
name|char
name|bar5
decl_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|char
name|bar6
decl_stmt|;
name|char
name|bar7
decl_stmt|;
block|}
name|ATTR
name|t7
struct|;
end_struct

begin_decl_stmt
name|int
name|s7
init|=
sizeof|sizeof
argument_list|(
name|t7
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s7 = global i32 9
end_comment

begin_comment
comment|// CHECK-ARM: @s7 = global i32 9
end_comment

begin_struct
struct|struct
block|{
name|long
label|:
literal|0
expr_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
label|:
literal|0
expr_stmt|;
block|}
name|ATTR
name|t8
struct|;
end_struct

begin_decl_stmt
name|int
name|s8
init|=
sizeof|sizeof
argument_list|(
name|t8
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s8 = global i32 0
end_comment

begin_comment
comment|// CHECK-ARM: @s8 = global i32 0
end_comment

begin_struct
struct|struct
block|{
name|char
name|foo
decl_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|char
name|bar
decl_stmt|;
name|char
name|bar1
decl_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
name|bar2
decl_stmt|;
name|char
name|bar3
decl_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|char
name|bar4
decl_stmt|;
name|char
name|bar5
decl_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|char
name|bar6
decl_stmt|;
name|char
name|bar7
decl_stmt|;
name|int
name|i1
decl_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
label|:
literal|4
expr_stmt|;
name|char
name|bar8
decl_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|char
name|bar9
decl_stmt|;
name|char
name|bar10
decl_stmt|;
name|int
name|i2
decl_stmt|;
name|char
label|:
literal|0
expr_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
label|:
literal|4
expr_stmt|;
block|}
name|ATTR
name|t9
struct|;
end_struct

begin_decl_stmt
name|int
name|s9
init|=
sizeof|sizeof
argument_list|(
name|t9
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s9 = global i32 28
end_comment

begin_comment
comment|// CHECK-ARM: @s9 = global i32 28
end_comment

begin_struct
struct|struct
block|{
name|char
name|foo
range|:
literal|8
decl_stmt|;
name|long
label|:
literal|0
expr_stmt|;
name|char
name|bar
decl_stmt|;
block|}
name|ATTR
name|t10
struct|;
end_struct

begin_decl_stmt
name|int
name|s10
init|=
sizeof|sizeof
argument_list|(
name|t10
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s10 = global i32 16
end_comment

begin_comment
comment|// CHECK-ARM: @s10 = global i32 8
end_comment

begin_comment
comment|// rdar://16041826 - ensure that ms_structs work correctly on a
end_comment

begin_comment
comment|// !useBitFieldTypeAlignment() target
end_comment

begin_struct
struct|struct
block|{
name|unsigned
name|int
name|a
range|:
literal|31
decl_stmt|;
name|unsigned
name|int
name|b
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|c
decl_stmt|;
block|}
name|ATTR
name|t11
struct|;
end_struct

begin_decl_stmt
name|int
name|s11
init|=
sizeof|sizeof
argument_list|(
name|t11
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s11 = global i32 12
end_comment

begin_comment
comment|// CHECK-ARM: @s11 = global i32 12
end_comment

begin_struct
struct|struct
block|{
name|unsigned
name|char
name|a
range|:
literal|3
decl_stmt|;
name|unsigned
name|char
name|b
range|:
literal|4
decl_stmt|;
name|unsigned
name|short
name|c
range|:
literal|6
decl_stmt|;
block|}
name|ATTR
name|t12
struct|;
end_struct

begin_decl_stmt
name|int
name|s12
init|=
sizeof|sizeof
argument_list|(
name|t12
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s12 = global i32 4
end_comment

begin_comment
comment|// CHECK-ARM: @s12 = global i32 4
end_comment

begin_struct
struct|struct
block|{
name|unsigned
name|char
name|a
range|:
literal|3
decl_stmt|;
name|unsigned
name|char
name|b
range|:
literal|4
decl_stmt|;
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|unsigned
name|short
name|c
range|:
literal|6
decl_stmt|;
block|}
name|ATTR
name|t13
struct|;
end_struct

begin_decl_stmt
name|int
name|s13
init|=
sizeof|sizeof
argument_list|(
name|t13
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @s13 = global i32 4
end_comment

begin_comment
comment|// CHECK-ARM: @s13 = global i32 4
end_comment

end_unit

