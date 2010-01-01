begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s -stack-protector 0 | FileCheck -check-prefix=NOSSP %s
end_comment

begin_comment
comment|// NOSSP: define void @test1(i8* %msg) nounwind {
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s -stack-protector 1 | FileCheck -check-prefix=WITHSSP %s
end_comment

begin_comment
comment|// WITHSSP: define void @test1(i8* %msg) nounwind ssp {
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s -stack-protector 2 | FileCheck -check-prefix=SSPREQ %s
end_comment

begin_comment
comment|// SSPREQ: define void @test1(i8* %msg) nounwind sspreq {
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
name|_Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test1
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
name|char
name|a
index|[
name|strlen
argument_list|(
name|msg
argument_list|)
operator|+
literal|1
index|]
decl_stmt|;
name|strcpy
argument_list|(
name|a
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

