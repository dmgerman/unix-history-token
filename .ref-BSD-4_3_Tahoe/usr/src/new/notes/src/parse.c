begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"dump.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|RCSid
init|=
literal|"$Header: parse.c,v 1.7 85/01/18 15:42:07 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	given a header line in the basic RFC-822 format,  *	this routine scans the name and determines a variable  *	name for it.  *  *	Ray Essick, March 1984  *		Stolen from the code I did for the BA 456 class....  */
end_comment

begin_macro
name|rfcparse
argument_list|(
argument|line
argument_list|,
argument|varlist
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dump_f
modifier|*
name|varlist
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|name
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* hold name */
if|if
condition|(
name|sscanf
argument_list|(
name|line
argument_list|,
literal|"%[^:]:"
argument_list|,
name|name
argument_list|)
operator|!=
literal|1
condition|)
comment|/* get field name */
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bogus line */
block|}
for|for
control|(
init|;
name|varlist
operator|->
name|du_name
index|[
literal|0
index|]
condition|;
name|varlist
operator|++
control|)
comment|/* empty string at end */
block|{
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
name|varlist
operator|->
name|du_name
argument_list|)
condition|)
comment|/* matched */
return|return
operator|(
name|varlist
operator|->
name|du_number
operator|)
return|;
comment|/* which is it */
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* never reached */
block|}
end_block

end_unit

