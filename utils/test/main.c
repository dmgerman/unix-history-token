begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
modifier|*
name|null_ptr
init|=
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|"Hello, fault!\n"
argument_list|)
expr_stmt|;
name|u_int32_t
name|val
init|=
operator|(
name|arc4random
argument_list|()
operator|&
literal|0x0f
operator|)
decl_stmt|;
name|printf
argument_list|(
literal|"val=%u\n"
argument_list|,
name|val
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|==
literal|0x07
condition|)
comment|// Lucky 7 :-)
name|printf
argument_list|(
literal|"Now segfault %d\n"
argument_list|,
operator|*
name|null_ptr
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"Better luck next time!\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

