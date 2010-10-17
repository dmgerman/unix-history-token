begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Test supplied by Ulrich.  Verify that we can correctly force 'a'  * to local scope.  */
end_comment

begin_function
name|int
name|__a_internal
parameter_list|(
name|int
name|e
parameter_list|)
block|{
return|return
name|e
operator|+
literal|10
return|;
block|}
end_function

begin_function
name|int
name|__b_internal
parameter_list|(
name|int
name|e
parameter_list|)
block|{
return|return
name|e
operator|+
literal|42
return|;
block|}
end_function

begin_asm
asm|asm (".symver __a_internal,hide_a@@VERS_1");
end_asm

begin_asm
asm|asm (".symver __b_internal,show_b@@VERS_1");
end_asm

end_unit

