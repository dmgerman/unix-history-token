begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-llvm -o %t %s&&
end_comment

begin_comment
comment|// RUN: grep '@g0 = internal global %.truct.s0 { i32 3 }' %t | count 1
end_comment

begin_struct
struct|struct
name|s0
block|{
name|int
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|s0
name|g0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|g0
operator|.
name|a
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|struct
name|s0
name|g0
init|=
block|{
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|g1
init|=
name|f0
decl_stmt|;
end_decl_stmt

end_unit

