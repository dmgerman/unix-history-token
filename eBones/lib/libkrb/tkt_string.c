begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: tkt_string.c,v 4.6 89/01/05 12:31:51 raeburn Exp $  * $FreeBSD$  */
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
unit|static char *rcsid = "$FreeBSD$";
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/*  * This routine is used to generate the name of the file that holds  * the user's cache of server tickets and associated session keys.  *  * If it is set, krb_ticket_string contains the ticket file name.  * Otherwise, the filename is constructed as follows:  *  * If it is set, the environment variable "KRBTKFILE" will be used as  * the ticket file name.  Otherwise TKT_ROOT (defined in "krb.h") and  * the user's uid are concatenated to produce the ticket file name  * (e.g., "/tmp/tkt123").  A pointer to the string containing the ticket  * file name is returned.  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|krb_ticket_string
index|[
name|MAXPATHLEN
index|]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|tkt_string
parameter_list|()
block|{
name|char
modifier|*
name|env
decl_stmt|;
name|uid_t
name|getuid
parameter_list|()
function_decl|;
if|if
condition|(
operator|!
operator|*
name|krb_ticket_string
condition|)
block|{
if|if
condition|(
operator|(
name|env
operator|=
name|getenv
argument_list|(
literal|"KRBTKFILE"
argument_list|)
operator|)
condition|)
block|{
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|krb_ticket_string
argument_list|,
name|env
argument_list|,
sizeof|sizeof
argument_list|(
name|krb_ticket_string
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
name|krb_ticket_string
index|[
sizeof|sizeof
argument_list|(
name|krb_ticket_string
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
else|else
block|{
comment|/* 32 bits of signed integer will always fit in 11 characters 	     (including the sign), so no need to worry about overflow */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|krb_ticket_string
argument_list|,
literal|"%s%ld"
argument_list|,
name|TKT_ROOT
argument_list|,
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|krb_ticket_string
return|;
block|}
end_function

begin_comment
comment|/*  * This routine is used to set the name of the file that holds the user's  * cache of server tickets and associated session keys.  *  * The value passed in is copied into local storage.  *  * NOTE:  This routine should be called during initialization, before other  * Kerberos routines are called; otherwise tkt_string() above may be called  * and return an undesired ticket file name until this routine is called.  */
end_comment

begin_function
name|void
name|krb_set_tkt_string
parameter_list|(
name|val
parameter_list|)
name|char
modifier|*
name|val
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|krb_ticket_string
argument_list|,
name|val
argument_list|,
sizeof|sizeof
argument_list|(
name|krb_ticket_string
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
name|krb_ticket_string
index|[
sizeof|sizeof
argument_list|(
name|krb_ticket_string
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return;
block|}
end_function

end_unit

