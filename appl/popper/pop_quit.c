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
comment|/*  *  quit:   Terminate a POP session  */
end_comment

begin_function
name|int
name|pop_quit
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
block|{
comment|/*  Release the message information list */
if|if
condition|(
name|p
operator|->
name|mlp
condition|)
name|free
argument_list|(
name|p
operator|->
name|mlp
argument_list|)
expr_stmt|;
return|return
operator|(
name|POP_SUCCESS
operator|)
return|;
block|}
end_function

end_unit

