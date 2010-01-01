begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o %t
end_comment

begin_typedef
typedef|typedef
name|struct
name|a
name|b
typedef|;
end_typedef

begin_decl_stmt
name|b
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|a
block|{
name|b
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f
parameter_list|()
block|{
name|b
modifier|*
name|z
init|=
name|x
operator|->
name|p
decl_stmt|;
block|}
end_function

end_unit

