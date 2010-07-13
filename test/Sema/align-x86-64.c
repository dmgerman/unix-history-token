begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -fsyntax-only -verify %s
end_comment

begin_comment
comment|// PR5599
end_comment

begin_function_decl
name|void
name|frob
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|float
name|x
index|[
literal|4
index|]
decl_stmt|;
name|char
name|y
index|[
name|__alignof__
argument_list|(
name|x
argument_list|)
operator|==
literal|16
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
name|frob
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

