begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -g -c -std=c11 -S -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: !DIGlobalVariable(name: "i"
end_comment

begin_comment
comment|// CHECK-SAME: type: ![[T:.*]], isLocal: false, isDefinition: true)
end_comment

begin_comment
comment|// CHECK: ![[T]] = !DIDerivedType(tag: DW_TAG_const_type, baseType: ![[BT:.*]])
end_comment

begin_comment
comment|// CHECK: ![[BT]] = !DIDerivedType(tag: DW_TAG_atomic_type, baseType: ![[BTT:.*]])
end_comment

begin_comment
comment|// CHECK: ![[BTT]] = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
end_comment

begin_decl_stmt
specifier|_Atomic
specifier|const
name|int
name|i
decl_stmt|;
end_decl_stmt

end_unit

