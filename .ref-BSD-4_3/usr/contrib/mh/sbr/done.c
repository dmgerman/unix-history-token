begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* done.c - terminate the program */
end_comment

begin_include
include|#
directive|include
file|"../h/mh.h"
end_include

begin_function
name|void
name|done
parameter_list|(
name|status
parameter_list|)
specifier|register
name|int
name|status
decl_stmt|;
block|{
name|exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

