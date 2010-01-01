begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -emit-llvm -S -o %t %s
end_comment

begin_struct
struct|struct
name|s0
block|{
name|void
modifier|*
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s0
modifier|*
name|__attribute__
argument_list|(
operator|(
name|objc_gc
argument_list|(
name|strong
argument_list|)
operator|)
argument_list|)
name|g0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
name|g0
operator|->
name|a
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

