begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XDisName.c,v 11.6 91/05/11 17:03:04 gildea Exp $ */
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
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
specifier|extern
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

