begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -S -emit-llvm -o - -O2 %s | FileCheck %s -check-prefix=O2
end_comment

begin_comment
comment|// RUN: %clang -S -emit-llvm -o - -O0 %s | FileCheck %s -check-prefix=O0
end_comment

begin_function_decl
specifier|extern
name|int
name|bar
parameter_list|(
name|char
modifier|*
name|A
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// O0-NOT: @llvm.lifetime.start
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
condition|)
block|{
comment|// O2: @llvm.lifetime.start
name|char
name|A
index|[
literal|100
index|]
decl_stmt|;
return|return
name|bar
argument_list|(
name|A
argument_list|,
literal|1
argument_list|)
return|;
block|}
else|else
block|{
comment|// O2: @llvm.lifetime.start
name|char
name|A
index|[
literal|100
index|]
decl_stmt|;
return|return
name|bar
argument_list|(
name|A
argument_list|,
literal|2
argument_list|)
return|;
block|}
block|}
end_function

end_unit

