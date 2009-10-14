begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_typedef
typedef|typedef
struct|struct
name|min_info
block|{
name|long
name|offset
decl_stmt|;
name|unsigned
name|file_attr
decl_stmt|;
block|}
name|min_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Globals
block|{
name|char
name|answerbuf
decl_stmt|;
name|min_info
name|info
index|[
literal|1
index|]
decl_stmt|;
name|min_info
modifier|*
name|pInfo
decl_stmt|;
block|}
name|Uz_Globs
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Uz_Globs
name|G
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|extract_or_test_files
parameter_list|()
block|{
name|G
operator|.
name|pInfo
operator|=
name|G
operator|.
name|info
expr_stmt|;
block|}
end_function

end_unit

