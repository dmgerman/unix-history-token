begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_include
include|#
directive|include
file|<popper.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  *  last:   Display the last message touched in a POP session  */
end_comment

begin_function
name|int
name|pop_last
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|pop_msg
argument_list|(
name|p
argument_list|,
name|POP_SUCCESS
argument_list|,
literal|"%u is the last message seen."
argument_list|,
name|p
operator|->
name|last_msg
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

