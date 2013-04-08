begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_union
union|union
name|S
block|{
name|unsigned
name|ac
range|:
literal|4
decl_stmt|;
name|unsigned
label|:
literal|4
expr_stmt|;
name|unsigned
name|clock
range|:
literal|1
decl_stmt|;
name|unsigned
label|:
literal|0
expr_stmt|;
name|unsigned
name|flag
range|:
literal|1
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|X
block|{
name|unsigned
name|light
range|:
literal|1
decl_stmt|;
name|unsigned
name|toaster
range|:
literal|1
decl_stmt|;
name|int
name|count
decl_stmt|;
name|union
name|S
name|stat
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// RUN: c-index-test -test-print-bitwidth %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: FieldDecl=ac:2:12 (Definition) bitwidth=4
end_comment

begin_comment
comment|// CHECK: FieldDecl=:3:3 (Definition) bitwidth=4
end_comment

begin_comment
comment|// CHECK: FieldDecl=clock:4:12 (Definition) bitwidth=1
end_comment

begin_comment
comment|// CHECK: FieldDecl=:5:3 (Definition) bitwidth=0
end_comment

begin_comment
comment|// CHECK: FieldDecl=flag:6:12 (Definition) bitwidth=1
end_comment

begin_comment
comment|// CHECK: FieldDecl=light:10:12 (Definition) bitwidth=1
end_comment

begin_comment
comment|// CHECK: FieldDecl=toaster:11:12 (Definition) bitwidth=1
end_comment

begin_comment
comment|// CHECK-NOT: count
end_comment

begin_comment
comment|// CHECK-NOT: stat
end_comment

end_unit

