begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x c -debug-info-kind=limited -triple mips-none-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_struct
struct|struct
name|fields
block|{
name|unsigned
name|a
range|:
literal|4
decl_stmt|;
name|unsigned
name|b
range|:
literal|4
decl_stmt|;
block|}
name|flags
struct|;
end_struct

begin_comment
comment|// CHECK: !DIDerivedType(tag: DW_TAG_member,
end_comment

begin_comment
comment|// CHECK-SAME: {{.*}}name: "a"
end_comment

begin_comment
comment|// CHECK-NOT: {{.*}}offset:
end_comment

begin_comment
comment|// CHECK-SAME: {{.*}}flags: DIFlagBitField
end_comment

begin_comment
comment|// CHECK: !DIDerivedType(tag: DW_TAG_member,
end_comment

begin_comment
comment|// CHECK-SAME: {{.*}}name: "b"
end_comment

begin_comment
comment|// CHECK-SAME: {{.*}}offset: 4
end_comment

begin_comment
comment|// CHECK-SAME: {{.*}}flags: DIFlagBitField
end_comment

end_unit

