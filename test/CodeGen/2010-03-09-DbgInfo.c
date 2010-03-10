begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -dA -S -O0 -g %s -o - | grep DW_TAG_variable
end_comment

begin_decl_stmt
name|unsigned
name|char
name|ctable1
index|[
literal|1
index|]
init|=
block|{
literal|0001
block|}
decl_stmt|;
end_decl_stmt

end_unit

