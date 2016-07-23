begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-elfiamcu -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Structure that is more than 8 byte.
end_comment

begin_struct
struct|struct
name|Big
block|{
name|double
name|a
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Empty union with zero size must be returned as void.
end_comment

begin_union
union|union
name|U1
block|{ }
name|u1
union|;
end_union

begin_comment
comment|// Too large union (80 bytes) must be returned via memory.
end_comment

begin_union
union|union
name|U2
block|{
name|struct
name|Big
name|b
decl_stmt|;
block|}
name|u2
union|;
end_union

begin_comment
comment|// Must be returned in register.
end_comment

begin_union
union|union
name|U3
block|{
name|int
name|x
decl_stmt|;
block|}
name|u3
union|;
end_union

begin_comment
comment|// Empty struct with zero size, must be returned as void.
end_comment

begin_struct
struct|struct
name|S1
block|{ }
name|s1
struct|;
end_struct

begin_comment
comment|// Must be returend in register.
end_comment

begin_struct
struct|struct
name|S2
block|{
name|int
name|x
decl_stmt|;
block|}
name|s2
struct|;
end_struct

begin_comment
comment|// CHECK: [[UNION1_TYPE:%.+]] = type {}
end_comment

begin_comment
comment|// CHECK: [[UNION2_TYPE:%.+]] = type { [[STRUCT_TYPE:%.+]] }
end_comment

begin_comment
comment|// CHECK: [[STRUCT_TYPE]] = type { [10 x double] }
end_comment

begin_comment
comment|// CHECK: [[UNION3_TYPE:%.+]] = type { i32 }
end_comment

begin_comment
comment|// CHECK: [[STRUCT1_TYPE:%.+]] = type {}
end_comment

begin_comment
comment|// CHECK: [[STRUCT2_TYPE:%.+]] = type { i32 }
end_comment

begin_function
name|union
name|U1
name|foo1
parameter_list|()
block|{
return|return
name|u1
return|;
block|}
end_function

begin_function
name|union
name|U2
name|foo2
parameter_list|()
block|{
return|return
name|u2
return|;
block|}
end_function

begin_function
name|union
name|U3
name|foo3
parameter_list|()
block|{
return|return
name|u3
return|;
block|}
end_function

begin_function
name|struct
name|S1
name|bar1
parameter_list|()
block|{
return|return
name|s1
return|;
block|}
end_function

begin_function
name|struct
name|S2
name|bar2
parameter_list|()
block|{
return|return
name|s2
return|;
block|}
end_function

begin_function
name|struct
name|S1
name|bar3
parameter_list|(
name|union
name|U1
name|u
parameter_list|)
block|{
return|return
name|s1
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @foo1()
end_comment

begin_comment
comment|// CHECK: define void @foo2([[UNION2_TYPE]]* noalias sret %{{.+}})
end_comment

begin_comment
comment|// CHECK: define i32 @foo3()
end_comment

begin_comment
comment|// CHECK: define void @bar1()
end_comment

begin_comment
comment|// CHECK: define i32 @bar2()
end_comment

begin_comment
comment|// CHECK: define void @bar3()
end_comment

begin_function
name|void
name|run
parameter_list|()
block|{
name|union
name|U1
name|x1
init|=
name|foo1
argument_list|()
decl_stmt|;
name|union
name|U2
name|x2
init|=
name|foo2
argument_list|()
decl_stmt|;
name|union
name|U3
name|x3
init|=
name|foo3
argument_list|()
decl_stmt|;
name|struct
name|S1
name|y1
init|=
name|bar1
argument_list|()
decl_stmt|;
name|struct
name|S2
name|y2
init|=
name|bar2
argument_list|()
decl_stmt|;
name|struct
name|S1
name|y3
init|=
name|bar3
argument_list|(
name|x1
argument_list|)
decl_stmt|;
comment|// CHECK: [[X1:%.+]] = alloca [[UNION1_TYPE]]
comment|// CHECK: [[X2:%.+]] = alloca [[UNION2_TYPE]]
comment|// CHECK: [[X3:%.+]] = alloca [[UNION3_TYPE]]
comment|// CHECK: [[Y1:%.+]] = alloca [[STRUCT1_TYPE]]
comment|// CHECK: [[Y2:%.+]] = alloca [[STRUCT2_TYPE]]
comment|// CHECK: call void @foo1()
comment|// CHECK: call void @foo2([[UNION2_TYPE]]* sret [[X2]])
comment|// CHECK: {{.+}} = call i32 @foo3()
comment|// CHECK: call void @bar1()
comment|// CHECK: {{.+}} = call i32 @bar2()
comment|// CHECK: call void @bar3()
block|}
end_function

end_unit

