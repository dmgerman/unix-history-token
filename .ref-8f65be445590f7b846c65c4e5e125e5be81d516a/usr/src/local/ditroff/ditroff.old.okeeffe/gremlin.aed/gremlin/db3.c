begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)db3.c	1.2	%G%  *  *  * Copyright -C- 1982 Barry S. Roitblat  *  *       This file contains additional routines to implement the database  * manipulations necessary for the gremlin picture editor.  */
end_comment

begin_include
include|#
directive|include
file|"gremlin.h"
end_include

begin_include
include|#
directive|include
file|"grem2.h"
end_include

begin_comment
comment|/* the following variable is a pointer for the current set and is  * available to the outside world.  */
end_comment

begin_decl_stmt
name|ELT
modifier|*
name|cset
decl_stmt|;
end_decl_stmt

begin_macro
name|DBAddSet
argument_list|(
argument|element
argument_list|)
end_macro

begin_decl_stmt
name|ELT
modifier|*
name|element
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *      This routine adds the element to the current set database.  */
end_comment

begin_block
block|{
name|ELT
modifier|*
name|elist
decl_stmt|;
name|elist
operator|=
name|cset
expr_stmt|;
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|elist
argument_list|)
condition|)
comment|/* makes sure element not */
block|{
comment|/* already in list        */
if|if
condition|(
name|elist
operator|==
name|element
condition|)
return|return;
name|elist
operator|=
name|DBNextofSet
argument_list|(
name|elist
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|element
operator|->
name|setnext
operator|=
name|cset
expr_stmt|;
name|cset
operator|=
name|element
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end AddSet */
end_comment

begin_macro
name|DBClearSet
argument_list|()
end_macro

begin_comment
comment|/*  *      This routine clears the current set by setting the pointer  * to a null element.  */
end_comment

begin_block
block|{
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|cset
argument_list|)
condition|)
name|cset
operator|=
name|DBNextofSet
argument_list|(
name|cset
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end ClearSet */
end_comment

end_unit

