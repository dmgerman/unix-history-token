begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-darwin-apple -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// PR6695
end_comment

begin_comment
comment|// CHECK: define void @test0(i32* %{{.*}}, i32 %{{.*}})
end_comment

begin_function
name|void
name|test0
parameter_list|(
name|int
modifier|*
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @test1(i32* noalias %{{.*}}, i32 %{{.*}})
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|int
modifier|*
specifier|restrict
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @test2(i32* %{{.*}}, i32* noalias %{{.*}})
end_comment

begin_function
name|void
name|test2
parameter_list|(
name|int
modifier|*
name|x
parameter_list|,
name|int
modifier|*
specifier|restrict
name|y
parameter_list|)
block|{ }
end_function

begin_typedef
typedef|typedef
name|int
modifier|*
specifier|restrict
name|rp
typedef|;
end_typedef

begin_comment
comment|// CHECK: define void @test3(i32* noalias %{{.*}}, i32 %{{.*}})
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|rp
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @test4(i32* %{{.*}}, i32* noalias %{{.*}})
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|int
modifier|*
name|x
parameter_list|,
name|rp
name|y
parameter_list|)
block|{ }
end_function

end_unit

