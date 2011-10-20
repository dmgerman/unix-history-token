begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o /dev/null
end_comment

begin_struct
struct|struct
name|item
block|{
name|short
name|delta
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|TEST
parameter_list|(
name|int
name|nt
parameter_list|)
block|{
specifier|register
name|struct
name|item
modifier|*
name|aa
decl_stmt|;
name|aa
index|[
name|nt
index|]
operator|.
name|delta
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

