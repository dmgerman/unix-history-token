begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s
end_comment

begin_union
union|union
block|{
name|int
label|:
literal|3
expr_stmt|;
name|double
name|f
decl_stmt|;
block|}
name|u17_017
init|=
block|{
literal|17.17
block|}
union|;
end_union

end_unit

