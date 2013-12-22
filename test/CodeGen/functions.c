begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-unknown-unknown -emit-llvm -o - -verify | FileCheck %s
end_comment

begin_function_decl
name|int
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|g
argument_list|(
name|i
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|g
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|g
argument_list|(
name|i
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// rdar://6110827
end_comment

begin_typedef
typedef|typedef
name|void
name|T
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function
name|void
name|test3
parameter_list|(
name|T
name|f
parameter_list|)
block|{
name|f
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|int
name|a
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|a
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|void
name|f0
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f0()
end_comment

begin_function_decl
name|void
name|f1
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: call void @f1()
name|f1
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f1()
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define {{.*}} @f3{{\(\)|\(.*sret.*\)}}
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|X
decl_stmt|,
name|Y
decl_stmt|,
name|Z
decl_stmt|;
block|}
name|f3
argument_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// PR4423 - This shouldn't crash in codegen
name|void
name|f4
argument_list|()
block|{}
name|void
name|f5
argument_list|()
block|{
name|f4
argument_list|(
literal|42
argument_list|)
expr_stmt|;
block|}
comment|//expected-warning {{too many arguments}}
comment|// Qualifiers on parameter types shouldn't make a difference.
decl|static
name|void
name|f6
argument_list|(
specifier|const
name|float
name|f
argument_list|,
specifier|const
name|float
name|g
argument_list|)
block|{ }
name|void
name|f7
argument_list|(
name|float
name|f
argument_list|,
name|float
name|g
argument_list|)
block|{
name|f6
argument_list|(
name|f
argument_list|,
name|g
argument_list|)
expr_stmt|;
comment|// CHECK: define void @f7(float{{.*}}, float{{.*}})
comment|// CHECK: call void @f6(float{{.*}}, float{{.*}})
block|}
comment|// PR6911 - incomplete function types
decl|struct
name|Incomplete
struct|;
end_struct

begin_function_decl
name|void
name|f8_callback
parameter_list|(
name|struct
name|Incomplete
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f8_user
parameter_list|(
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|Incomplete
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f8_test
parameter_list|()
block|{
name|f8_user
argument_list|(
operator|&
name|f8_callback
argument_list|)
expr_stmt|;
comment|// CHECK-LABEL: define void @f8_test()
comment|// CHECK: call void @f8_user({{.*}}* bitcast (void ()* @f8_callback to {{.*}}*))
comment|// CHECK: declare void @f8_user({{.*}}*)
comment|// CHECK: declare void @f8_callback()
block|}
end_function

begin_comment
comment|// PR10204: don't crash
end_comment

begin_function
specifier|static
name|void
name|test9_helper
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
name|void
name|test9
parameter_list|()
block|{
operator|(
name|void
operator|)
name|test9_helper
expr_stmt|;
block|}
end_function

end_unit

