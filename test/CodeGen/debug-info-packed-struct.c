begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x c -debug-info-kind=limited -emit-llvm -triple x86_64-apple-darwin -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: %struct.layout3 = type<{ i8, [3 x i8], %struct.size8_pack4, i8, [3 x i8] }>
end_comment

begin_comment
comment|// CHECK: %struct.layout0 = type { i8, %struct.size8, i8 }
end_comment

begin_comment
comment|// CHECK: %struct.layout1 = type<{ i8, %struct.size8_anon, i8, [2 x i8] }>
end_comment

begin_comment
comment|// CHECK: %struct.layout2 = type<{ i8, %struct.size8_pack1, i8 }>
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_comment
comment|// Not packed.
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_struct
struct|struct
name|size8
block|{
name|int
name|i
range|:
literal|4
decl_stmt|;
name|long
name|long
name|l
range|:
literal|60
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|layout0
block|{
name|char
name|l0_ofs0
decl_stmt|;
name|struct
name|size8
name|l0_ofs8
decl_stmt|;
name|int
name|l0_ofs16
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: l0_ofs0
end_comment

begin_comment
comment|// CHECK: !DIDerivedType(tag: DW_TAG_member, name: "l0_ofs8",
end_comment

begin_comment
comment|// CHECK-SAME:     {{.*}}size: 64, offset: 64)
end_comment

begin_comment
comment|// CHECK: !DIDerivedType(tag: DW_TAG_member, name: "l0_ofs16",
end_comment

begin_comment
comment|// CHECK-SAME:     {{.*}}size: 1, offset: 128, flags: DIFlagBitField, extraData: i64 128)
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_comment
comment|// Implicitly packed.
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_struct
struct|struct
name|size8_anon
block|{
name|int
label|:
literal|4
expr_stmt|;
name|long
name|long
range|:
literal|60
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|layout1
block|{
name|char
name|l1_ofs0
decl_stmt|;
name|struct
name|size8_anon
name|l1_ofs1
decl_stmt|;
name|int
name|l1_ofs9
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: l1_ofs0
end_comment

begin_comment
comment|// CHECK: !DIDerivedType(tag: DW_TAG_member, name: "l1_ofs1",
end_comment

begin_comment
comment|// CHECK-SAME:     {{.*}}size: 64, offset: 8)
end_comment

begin_comment
comment|// CHECK: !DIDerivedType(tag: DW_TAG_member, name: "l1_ofs9",
end_comment

begin_comment
comment|// CHECK-SAME:     {{.*}}size: 1, offset: 72, flags: DIFlagBitField, extraData: i64 72)
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_comment
comment|// Explicitly packed.
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_struct
struct|struct
name|size8_pack1
block|{
name|int
name|i
range|:
literal|4
decl_stmt|;
name|long
name|long
name|l
range|:
literal|60
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|layout2
block|{
name|char
name|l2_ofs0
decl_stmt|;
name|struct
name|size8_pack1
name|l2_ofs1
decl_stmt|;
name|int
name|l2_ofs9
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|// CHECK: l2_ofs0
end_comment

begin_comment
comment|// CHECK: !DIDerivedType(tag: DW_TAG_member, name: "l2_ofs1",
end_comment

begin_comment
comment|// CHECK-SAME:     {{.*}}size: 64, offset: 8)
end_comment

begin_comment
comment|// CHECK: !DIDerivedType(tag: DW_TAG_member, name: "l2_ofs9",
end_comment

begin_comment
comment|// CHECK-SAME:     {{.*}}size: 1, offset: 72, flags: DIFlagBitField, extraData: i64 72)
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_comment
comment|// Explicitly packed with different alignment.
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|4
name|)
end_pragma

begin_struct
struct|struct
name|size8_pack4
block|{
name|int
name|i
range|:
literal|4
decl_stmt|;
name|long
name|long
name|l
range|:
literal|60
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|layout3
block|{
name|char
name|l3_ofs0
decl_stmt|;
name|struct
name|size8_pack4
name|l3_ofs4
decl_stmt|;
name|int
name|l3_ofs12
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|// CHECK: l3_ofs0
end_comment

begin_comment
comment|// CHECK: !DIDerivedType(tag: DW_TAG_member, name: "l3_ofs4",
end_comment

begin_comment
comment|// CHECK-SAME:     {{.*}}size: 64, offset: 32)
end_comment

begin_comment
comment|// CHECK: !DIDerivedType(tag: DW_TAG_member, name: "l3_ofs12",
end_comment

begin_comment
comment|// CHECK-SAME:     {{.*}}size: 1, offset: 96, flags: DIFlagBitField, extraData: i64 96)
end_comment

begin_decl_stmt
name|struct
name|layout3
name|l3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|layout0
name|l0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|layout1
name|l1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|layout2
name|l2
decl_stmt|;
end_decl_stmt

end_unit

