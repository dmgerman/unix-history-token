begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * solUtils.c --  *  *	remade by A.Fujita, DEC-16-1992  */
end_comment

begin_include
include|#
directive|include
file|"sol.h"
end_include

begin_function
name|int
name|ddxProcessArgument
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|,
name|i
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
name|int
name|i
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"solUtils.c: ddxProcessArgument()\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|ddxUseMsg
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"solUtils.c: ddxUseMsg()\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

