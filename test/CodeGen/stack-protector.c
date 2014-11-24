begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s -stack-protector 0 | FileCheck -check-prefix=NOSSP %s
end_comment

begin_comment
comment|// NOSSP: define void @test1(i8* %msg) #0 {
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s -stack-protector 1 | FileCheck -check-prefix=WITHSSP %s
end_comment

begin_comment
comment|// WITHSSP: define void @test1(i8* %msg) #0 {
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s -stack-protector 2 | FileCheck -check-prefix=SSPSTRONG %s
end_comment

begin_comment
comment|// SSPSTRONG: define void @test1(i8* %msg) #0 {
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s -stack-protector 3 | FileCheck -check-prefix=SSPREQ %s
end_comment

begin_comment
comment|// SSPREQ: define void @test1(i8* %msg) #0 {
end_comment

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

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

begin_function_decl
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
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

begin_comment
comment|// NOSSP: attributes #{{.*}} = { nounwind{{.*}} }
end_comment

begin_comment
comment|// WITHSSP: attributes #{{.*}} = { nounwind ssp{{.*}} }
end_comment

begin_comment
comment|// SSPSTRONG: attributes #{{.*}} = { nounwind sspstrong{{.*}} }
end_comment

begin_comment
comment|// SSPREQ: attributes #{{.*}} = { nounwind sspreq{{.*}} }
end_comment

end_unit

