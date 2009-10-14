begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i686-unknown-unknown -emit-llvm -o %t %s&&
end_comment

begin_comment
comment|// RUN: not grep 'ssp' %t&&
end_comment

begin_comment
comment|// RUN: clang-cc -triple i686-apple-darwin9 -emit-llvm -o %t %s&&
end_comment

begin_comment
comment|// RUN: not grep 'ssp' %t&&
end_comment

begin_comment
comment|// RUN: clang-cc -triple i686-apple-darwin10 -emit-llvm -o %t %s&&
end_comment

begin_comment
comment|// RUN: grep 'ssp' %t&&
end_comment

begin_comment
comment|// RUN: clang -fstack-protector-all -emit-llvm -S -o %t %s&&
end_comment

begin_comment
comment|// RUN: grep 'sspreq' %t&&
end_comment

begin_comment
comment|// RUN: clang -fstack-protector -emit-llvm -S -o %t %s&&
end_comment

begin_comment
comment|// RUN: grep 'ssp' %t&&
end_comment

begin_comment
comment|// RUN: clang -fno-stack-protector -emit-llvm -S -o %t %s&&
end_comment

begin_comment
comment|// RUN: not grep 'ssp' %t&&
end_comment

begin_comment
comment|// RUN: true
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

