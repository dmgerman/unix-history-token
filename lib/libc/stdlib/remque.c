begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Initial implementation:  * Copyright (c) 2002 Robert Drehmel  * All rights reserved.  *  * As long as the above copyright statement and this notice remain  * unchanged, you can do what ever you want with this file.   */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|_SEARCH_PRIVATE
end_define

begin_include
include|#
directive|include
file|<search.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* for NULL */
end_comment

begin_function
name|void
name|remque
parameter_list|(
name|void
modifier|*
name|element
parameter_list|)
block|{
name|struct
name|que_elem
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|,
modifier|*
name|elem
decl_stmt|;
name|elem
operator|=
operator|(
expr|struct
name|que_elem
operator|*
operator|)
name|element
expr_stmt|;
name|prev
operator|=
name|elem
operator|->
name|prev
expr_stmt|;
name|next
operator|=
name|elem
operator|->
name|next
expr_stmt|;
if|if
condition|(
name|prev
operator|!=
name|NULL
condition|)
name|prev
operator|->
name|next
operator|=
name|next
expr_stmt|;
if|if
condition|(
name|next
operator|!=
name|NULL
condition|)
name|next
operator|->
name|prev
operator|=
name|prev
expr_stmt|;
block|}
end_function

end_unit

