begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: extract_ticket.c,v 4.6 88/10/07 06:08:15 shanzer Exp $  * $FreeBSD$  */
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
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<prot.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_comment
comment|/*  * This routine is obsolete.  *  * This routine accepts the ciphertext returned by kerberos and  * extracts the nth ticket.  It also fills in the variables passed as  * session, liftime and kvno.  */
end_comment

begin_function
name|void
name|extract_ticket
parameter_list|(
name|cipher
parameter_list|,
name|n
parameter_list|,
name|session
parameter_list|,
name|lifetime
parameter_list|,
name|kvno
parameter_list|,
name|realm
parameter_list|,
name|ticket
parameter_list|)
name|KTEXT
name|cipher
decl_stmt|;
comment|/* The ciphertext */
name|int
name|n
decl_stmt|;
comment|/* Which ticket */
name|char
modifier|*
name|session
decl_stmt|;
comment|/* The session key for this tkt */
name|int
modifier|*
name|lifetime
decl_stmt|;
comment|/* The life of this ticket */
name|int
modifier|*
name|kvno
decl_stmt|;
comment|/* The kvno for the service */
name|char
modifier|*
name|realm
decl_stmt|;
comment|/* Realm in which tkt issued */
name|KTEXT
name|ticket
decl_stmt|;
comment|/* The ticket itself */
block|{
name|char
modifier|*
name|ptr
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/* Start after the ticket lengths */
name|ptr
operator|=
operator|(
name|char
operator|*
operator|)
name|cipher
operator|->
name|dat
expr_stmt|;
name|ptr
operator|=
name|ptr
operator|+
literal|1
operator|+
operator|(
name|int
operator|)
operator|*
operator|(
name|cipher
operator|->
name|dat
operator|)
expr_stmt|;
comment|/* Step through earlier tickets */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|n
condition|;
name|i
operator|++
control|)
name|ptr
operator|=
name|ptr
operator|+
literal|11
operator|+
name|strlen
argument_list|(
name|ptr
operator|+
literal|10
argument_list|)
operator|+
operator|(
name|int
operator|)
operator|*
operator|(
name|cipher
operator|->
name|dat
operator|+
name|i
operator|)
expr_stmt|;
name|bcopy
argument_list|(
name|ptr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|session
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|/* Save the session key */
name|ptr
operator|+=
literal|8
expr_stmt|;
operator|*
name|lifetime
operator|=
operator|*
operator|(
name|ptr
operator|++
operator|)
expr_stmt|;
comment|/* Save the life of the ticket */
operator|*
name|kvno
operator|=
operator|*
operator|(
name|ptr
operator|++
operator|)
expr_stmt|;
comment|/* Save the kvno */
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|realm
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
comment|/* instance */
name|ptr
operator|+=
name|strlen
argument_list|(
name|realm
argument_list|)
operator|+
literal|1
expr_stmt|;
comment|/* Save the ticket if its length is non zero */
name|ticket
operator|->
name|length
operator|=
operator|*
operator|(
name|cipher
operator|->
name|dat
operator|+
name|n
operator|)
expr_stmt|;
if|if
condition|(
name|ticket
operator|->
name|length
condition|)
name|bcopy
argument_list|(
name|ptr
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|(
name|ticket
operator|->
name|dat
operator|)
argument_list|,
name|ticket
operator|->
name|length
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

