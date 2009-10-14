begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* This testcase causes a symbol table collision.  Type names and variable  * names should be in distinct namespaces  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|foo
block|{
name|int
name|X
decl_stmt|,
name|Y
decl_stmt|;
block|}
name|FOO
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|FOO
name|foo
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test
parameter_list|()
block|{
return|return
name|foo
index|[
literal|4
index|]
operator|.
name|Y
return|;
block|}
end_function

end_unit

