begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/add_ticket.c,v $  * $Author: kfall $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_add_ticket_c
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/add_ticket.c,v 1.1 90/06/25 20:54:59 kfall Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

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
comment|/*  * This routine is now obsolete.  It used to be possible to request  * more than one ticket at a time from the authentication server, and  * it looks like this routine was used by the server to package the  * tickets to be returned to the client.  */
end_comment

begin_comment
comment|/*  * This routine adds a new ticket to the ciphertext to be returned to  * the client.  The routine takes the ciphertext (which doesn't get  * encrypted till later), the number of the ticket (i.e. 1st, 2nd,  * etc) the session key which goes in the ticket and is sent back to  * the user, the lifetime for the ticket, the service name, the  * instance, the realm, the key version number, and the ticket itself.  *  * This routine returns 0 (KSUCCESS) on success, and 1 (KFAILURE) on  * failure.  On failure, which occurs when there isn't enough room  * for the ticket, a 0 length ticket is added.  *  * Notes: This routine must be called with successive values of n.  * i.e. the ticket must be added in order.  The corresponding routine  * on the client side is extract ticket.  */
end_comment

begin_comment
comment|/* XXX they aren't all used; to avoid incompatible changes we will  * fool lint for the moment */
end_comment

begin_comment
comment|/*ARGSUSED */
end_comment

begin_macro
name|add_ticket
argument_list|(
argument|cipher
argument_list|,
argument|n
argument_list|,
argument|session
argument_list|,
argument|lifetime
argument_list|,
argument|sname
argument_list|,
argument|instance
argument_list|,
argument|realm
argument_list|,
argument|kvno
argument_list|,
argument|ticket
argument_list|)
end_macro

begin_decl_stmt
name|KTEXT
name|cipher
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ciphertext info for ticket */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Service name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|instance
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Instance */
end_comment

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Relative position of this ticket */
end_comment

begin_decl_stmt
name|char
modifier|*
name|session
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Session key for this tkt */
end_comment

begin_decl_stmt
name|int
name|lifetime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lifetime of this ticket */
end_comment

begin_decl_stmt
name|char
modifier|*
name|realm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Realm in which ticket is valid */
end_comment

begin_decl_stmt
name|int
name|kvno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Key version number of service key */
end_comment

begin_decl_stmt
name|KTEXT
name|ticket
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The ticket itself */
end_comment

begin_block
block|{
comment|/* Note, the 42 is a temporary hack; it will have to be changed. */
comment|/* Begin check of ticket length */
if|if
condition|(
operator|(
name|cipher
operator|->
name|length
operator|+
name|ticket
operator|->
name|length
operator|+
literal|4
operator|+
literal|42
operator|+
operator|(
operator|*
operator|(
name|cipher
operator|->
name|dat
operator|)
operator|+
literal|1
operator|-
name|n
operator|)
operator|*
operator|(
literal|11
operator|+
name|strlen
argument_list|(
name|realm
argument_list|)
operator|)
operator|)
operator|>
name|MAX_KTXT_LEN
condition|)
block|{
name|bcopy
argument_list|(
name|session
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|(
name|cipher
operator|->
name|dat
operator|+
name|cipher
operator|->
name|length
operator|)
argument_list|,
literal|8
argument_list|)
expr_stmt|;
operator|*
operator|(
name|cipher
operator|->
name|dat
operator|+
name|cipher
operator|->
name|length
operator|+
literal|8
operator|)
operator|=
operator|(
name|char
operator|)
name|lifetime
expr_stmt|;
operator|*
operator|(
name|cipher
operator|->
name|dat
operator|+
name|cipher
operator|->
name|length
operator|+
literal|9
operator|)
operator|=
operator|(
name|char
operator|)
name|kvno
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
name|cipher
operator|->
name|dat
operator|+
name|cipher
operator|->
name|length
operator|+
literal|10
operator|)
argument_list|,
name|realm
argument_list|)
expr_stmt|;
name|cipher
operator|->
name|length
operator|+=
literal|11
operator|+
name|strlen
argument_list|(
name|realm
argument_list|)
expr_stmt|;
operator|*
operator|(
name|cipher
operator|->
name|dat
operator|+
name|n
operator|)
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|KFAILURE
operator|)
return|;
block|}
comment|/* End check of ticket length */
comment|/* Add the session key, lifetime, kvno, ticket to the ciphertext */
name|bcopy
argument_list|(
name|session
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|(
name|cipher
operator|->
name|dat
operator|+
name|cipher
operator|->
name|length
operator|)
argument_list|,
literal|8
argument_list|)
expr_stmt|;
operator|*
operator|(
name|cipher
operator|->
name|dat
operator|+
name|cipher
operator|->
name|length
operator|+
literal|8
operator|)
operator|=
operator|(
name|char
operator|)
name|lifetime
expr_stmt|;
operator|*
operator|(
name|cipher
operator|->
name|dat
operator|+
name|cipher
operator|->
name|length
operator|+
literal|9
operator|)
operator|=
operator|(
name|char
operator|)
name|kvno
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
name|cipher
operator|->
name|dat
operator|+
name|cipher
operator|->
name|length
operator|+
literal|10
operator|)
argument_list|,
name|realm
argument_list|)
expr_stmt|;
name|cipher
operator|->
name|length
operator|+=
literal|11
operator|+
name|strlen
argument_list|(
name|realm
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
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
operator|(
name|char
operator|*
operator|)
operator|(
name|cipher
operator|->
name|dat
operator|+
name|cipher
operator|->
name|length
operator|)
argument_list|,
name|ticket
operator|->
name|length
argument_list|)
expr_stmt|;
name|cipher
operator|->
name|length
operator|+=
name|ticket
operator|->
name|length
expr_stmt|;
comment|/* Set the ticket length at beginning of ciphertext */
operator|*
operator|(
name|cipher
operator|->
name|dat
operator|+
name|n
operator|)
operator|=
name|ticket
operator|->
name|length
expr_stmt|;
return|return
operator|(
name|KSUCCESS
operator|)
return|;
block|}
end_block

end_unit

