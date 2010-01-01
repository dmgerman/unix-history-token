begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|aa
parameter_list|(
name|int
name|b
parameter_list|,
name|int
name|x
index|[
sizeof|sizeof
name|b
index|]
parameter_list|)
block|{}
end_function

begin_function
name|void
name|foo
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|A
index|[
name|i
index|]
parameter_list|)
block|{}
end_function

end_unit

