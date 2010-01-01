begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep "internal addrspace(1) global i32 1"
end_comment

begin_typedef
typedef|typedef
name|int
name|a
name|__attribute__
typedef|((
name|address_space
typedef|(1)));
end_typedef

begin_decl_stmt
name|a
modifier|*
name|x
init|=
operator|&
operator|(
name|a
operator|)
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

end_unit

