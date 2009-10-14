begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_decl_stmt
name|char
name|auto_kibitz_list
index|[
literal|100
index|]
index|[
literal|20
index|]
init|=
block|{
block|{
literal|"diepx"
block|}
block|,
block|{
literal|"ferret"
block|}
block|,
block|{
literal|"knightc"
block|}
block|,
block|{
literal|"knightcap"
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

