begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Check that the 'include' options work.  * RUN: echo "int x;\n"> %t1.inc  * RUN: llvmc -include %t1.inc -fsyntax-only %s  */
end_comment

begin_function
name|int
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

end_unit

