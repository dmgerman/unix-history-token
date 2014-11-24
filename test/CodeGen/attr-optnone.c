begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s> %t
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=PRESENT< %t
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=ABSENT< %t
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(always_inline)
argument_list|)
end_macro

begin_function
name|int
name|test2
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// PRESENT-DAG: @test2{{.*}}[[ATTR2:#[0-9]+]]
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(optnone)
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(minsize)
argument_list|)
end_macro

begin_function
name|int
name|test3
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// PRESENT-DAG: @test3{{.*}}[[ATTR3:#[0-9]+]]
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(optnone)
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(cold)
argument_list|)
end_macro

begin_function
name|int
name|test4
parameter_list|()
block|{
return|return
name|test2
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// PRESENT-DAG: @test4{{.*}}[[ATTR4:#[0-9]+]]
end_comment

begin_comment
comment|// Also check that test2 is inlined into test4 (always_inline still works).
end_comment

begin_comment
comment|// PRESENT-NOT: call i32 @test2
end_comment

begin_comment
comment|// Check for both noinline and optnone on each optnone function.
end_comment

begin_comment
comment|// PRESENT-DAG: attributes [[ATTR3]] = { {{.*}}noinline{{.*}}optnone{{.*}} }
end_comment

begin_comment
comment|// PRESENT-DAG: attributes [[ATTR4]] = { {{.*}}noinline{{.*}}optnone{{.*}} }
end_comment

begin_comment
comment|// Check that no 'optsize' or 'minsize' attributes appear.
end_comment

begin_comment
comment|// ABSENT-NOT: optsize
end_comment

begin_comment
comment|// ABSENT-NOT: minsize
end_comment

end_unit

