begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* date.c */
end_comment

begin_include
include|#
directive|include
file|"tws.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|dtimenow
argument_list|()
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

