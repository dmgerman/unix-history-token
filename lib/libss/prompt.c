begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * prompt.c: Routines for retrieving and setting a prompt.  *  * Header: prompt.c,v 1.2 89/01/18 18:27:02 raeburn Exp  *  * Copyright 1987, 1988 by MIT Student Information Processing Board  *  * For copyright information, see copyright.h.  */
end_comment

begin_include
include|#
directive|include
file|"copyright.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ss_internal.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"Header: prompt.c,v 1.2 89/01/18 18:27:02 raeburn Exp "
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|ss_set_prompt
parameter_list|(
name|sci_idx
parameter_list|,
name|new_prompt
parameter_list|)
name|int
name|sci_idx
decl_stmt|;
name|char
modifier|*
name|new_prompt
decl_stmt|;
block|{
name|ss_info
argument_list|(
name|sci_idx
argument_list|)
operator|->
name|prompt
operator|=
name|new_prompt
expr_stmt|;
block|}
end_function

begin_function
name|char
modifier|*
name|ss_get_prompt
parameter_list|(
name|sci_idx
parameter_list|)
name|int
name|sci_idx
decl_stmt|;
block|{
return|return
operator|(
name|ss_info
argument_list|(
name|sci_idx
argument_list|)
operator|->
name|prompt
operator|)
return|;
block|}
end_function

end_unit

