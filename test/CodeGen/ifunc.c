begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-linux-gnu -O2 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function_decl
name|int
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ifunc
parameter_list|(
function_decl|"foo_ifunc"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
name|int
name|f1
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
operator|+
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|f2
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
operator|+
literal|2
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|foo_t
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|int
name|global
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|foo_t
name|foo_ifunc
parameter_list|()
block|{
return|return
name|global
condition|?
name|f1
else|:
name|f2
return|;
block|}
end_function

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
name|foo
argument_list|(
literal|1
argument_list|)
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|goo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bar2
parameter_list|(
name|void
parameter_list|)
block|{
name|goo
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|goo
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ifunc
parameter_list|(
function_decl|"goo_ifunc"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
modifier|*
name|goo_ifunc
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: @foo = ifunc i32 (i32), bitcast (i32 (i32)* ()* @foo_ifunc to i32 (i32)*)
end_comment

begin_comment
comment|// CHECK: @goo = ifunc void (), bitcast (i8* ()* @goo_ifunc to void ()*)
end_comment

begin_comment
comment|// CHECK: call i32 @foo(i32
end_comment

begin_comment
comment|// CHECK: call void @goo()
end_comment

end_unit

