begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: get_phost.c,v 4.6 89/01/23 09:25:40 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char rcsid[] = "$FreeBSD$";
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_function_decl
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * This routine takes an alias for a host name and returns the first  * field, lower case, of its domain name.  For example, if "menel" is  * an alias for host officially named "menelaus" (in /etc/hosts), for  * the host whose official name is "MENELAUS.MIT.EDU", the name "menelaus"  * is returned.  *  * This is done for historical Athena reasons: the Kerberos name of  * rcmd servers (rlogin, rsh, rcp) is of the form "rcmd.host@realm"  * where "host"is the lowercase for of the host name ("menelaus").  * This should go away: the instance should be the domain name  * (MENELAUS.MIT.EDU).  But for now we need this routine...  *  * A pointer to the name is returned, if found, otherwise a pointer  * to the original "alias" argument is returned.  */
end_comment

begin_function
name|char
modifier|*
name|krb_get_phost
parameter_list|(
name|alias
parameter_list|)
name|char
modifier|*
name|alias
decl_stmt|;
block|{
name|struct
name|hostent
modifier|*
name|h
decl_stmt|;
name|char
modifier|*
name|phost
init|=
name|alias
decl_stmt|;
if|if
condition|(
operator|(
name|h
operator|=
name|gethostbyname
argument_list|(
name|alias
argument_list|)
operator|)
operator|!=
operator|(
expr|struct
name|hostent
operator|*
operator|)
name|NULL
condition|)
block|{
name|char
modifier|*
name|p
init|=
name|index
argument_list|(
name|h
operator|->
name|h_name
argument_list|,
literal|'.'
argument_list|)
decl_stmt|;
if|if
condition|(
name|p
condition|)
operator|*
name|p
operator|=
name|NULL
expr_stmt|;
name|p
operator|=
name|phost
operator|=
name|h
operator|->
name|h_name
expr_stmt|;
do|do
block|{
if|if
condition|(
name|isupper
argument_list|(
operator|*
name|p
argument_list|)
condition|)
operator|*
name|p
operator|=
name|tolower
argument_list|(
operator|*
name|p
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|*
name|p
operator|++
condition|)
do|;
block|}
return|return
operator|(
name|phost
operator|)
return|;
block|}
end_function

end_unit

