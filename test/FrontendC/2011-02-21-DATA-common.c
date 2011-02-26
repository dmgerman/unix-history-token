begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o /dev/null
end_comment

begin_struct
struct|struct
name|rtxc_snapshot
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|__attribute__
argument_list|(
argument|(section(
literal|"__DATA, __common"
argument|))
argument_list|)
end_macro

begin_decl_stmt
specifier|static
name|struct
name|rtxc_snapshot
name|rtxc_log_A
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

end_unit

