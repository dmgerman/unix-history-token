begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check the data structures emitted by coverage mapping
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name ir.c %s -o - -emit-llvm -fprofile-instrument=clang -fcoverage-mapping | FileCheck %s
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|foo
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: @__llvm_coverage_mapping = internal constant { { i32, i32, i32, i32 }, [2 x<{ i64, i32, i64 }>], [{{[0-9]+}} x i8] } { { i32, i32, i32, i32 } { i32 2, i32 {{[0-9]+}}, i32 {{[0-9]+}}, i32 {{[0-9]+}} }, [2 x<{ i64, i32, i64 }>] [<{{.*}}><{{.*}}>,<{{.*}}><{{.*}}>]
end_comment

end_unit

