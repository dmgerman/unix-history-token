begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -O -o - | FileCheck %s
end_comment

begin_comment
comment|// The load here was getting lost because this code was close
end_comment

begin_comment
comment|// enough to the traditional (wrong) implementation of offsetof
end_comment

begin_comment
comment|// to confuse the gcc FE.  8629268.
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|x
decl_stmt|;
name|int
modifier|*
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|foo
name|Foo
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|bar
parameter_list|(
name|unsigned
name|int
name|ix
parameter_list|)
block|{
comment|// CHECK: load
return|return
operator|&
name|Foo
operator|->
name|y
index|[
name|ix
index|]
return|;
block|}
end_function

end_unit

