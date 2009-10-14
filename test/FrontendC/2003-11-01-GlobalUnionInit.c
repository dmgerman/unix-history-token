begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_union
union|union
name|bdflush_param
block|{
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|b_un
struct|;
name|int
name|y
index|[
literal|1
index|]
decl_stmt|;
block|}
name|bdf_prm
init|=
block|{
block|{
literal|30
block|}
block|}
union|;
end_union

end_unit

