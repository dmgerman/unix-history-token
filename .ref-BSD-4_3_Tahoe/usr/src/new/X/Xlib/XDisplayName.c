begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: XDisplayName.c,v 10.1 86/11/19 18:17:19 jg Rel $ */
end_comment

begin_comment
comment|/* XDisplayName.c */
end_comment

begin_comment
comment|/*   * Returns the name of the display XOpenDisplay would use.  This is better  * than just printing the "display" variable in a program because that  * could be NULL and/or there could be an environment variable set.  * This makes it easier for programmers to provide meaningful error  * messages.   *  *   * For example, this is used in XOpenDisplay() as  *	strncpy( displaybuf, XDisplayName( display ), sizeof(displaybuf) );  *      if ( *displaybuf == '\0' ) return( NULL );  *  This check is actually unnecessary because the next thing is an index()  *  call looking for a ':' which will fail and we'll return(NULL).  */
end_comment

begin_comment
comment|/* Written at Waterloo - JMSellens */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|char
modifier|*
name|XDisplayName
parameter_list|(
name|display
parameter_list|)
name|char
modifier|*
name|display
decl_stmt|;
block|{
name|char
modifier|*
name|d
decl_stmt|;
if|if
condition|(
name|display
operator|!=
operator|(
name|char
operator|*
operator|)
name|NULL
operator|&&
operator|*
name|display
operator|!=
literal|'\0'
condition|)
return|return
operator|(
name|display
operator|)
return|;
if|if
condition|(
operator|(
name|d
operator|=
name|getenv
argument_list|(
literal|"DISPLAY"
argument_list|)
operator|)
operator|!=
operator|(
name|char
operator|*
operator|)
name|NULL
condition|)
return|return
operator|(
name|d
operator|)
return|;
return|return
operator|(
literal|""
operator|)
return|;
block|}
end_function

end_unit

