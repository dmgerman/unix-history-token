begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/decomp_ticket.c,v $  * $Author: bostic $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
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
name|rcsid_decomp_ticket_c
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/decomp_ticket.c,v 4.14 91/02/25 15:21:17 bostic Exp $"
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
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
comment|/*  * This routine takes a ticket and pointers to the variables that  * should be filled in based on the information in the ticket.  It #ifndef NOENCRYPTION  * decrypts the ticket using the given key, and  #endif  * fills in values for its arguments.  *  * Note: if the client realm field in the ticket is the null string,  * then the "prealm" variable is filled in with the local realm (as  * defined by KRB_REALM).  *  * If the ticket byte order is different than the host's byte order  * (as indicated by the byte order bit of the "flags" field), then  * the KDC timestamp "time_sec" is byte-swapped.  The other fields  * potentially affected by byte order, "paddress" and "session" are  * not byte-swapped.  *  * The routine returns KFAILURE if any of the "pname", "pinstance",  * or "prealm" fields is too big, otherwise it returns KSUCCESS.  *  * The corresponding routine to generate tickets is create_ticket.  * When changes are made to this routine, the corresponding changes  * should also be made to that file.  *  * See create_ticket.c for the format of the ticket packet.  */
end_comment

begin_macro
name|decomp_ticket
argument_list|(
argument|tkt
argument_list|,
argument|flags
argument_list|,
argument|pname
argument_list|,
argument|pinstance
argument_list|,
argument|prealm
argument_list|,
argument|paddress
argument_list|,
argument|session
argument_list|,
argument|life
argument_list|,
argument|time_sec
argument_list|,
argument|sname
argument_list|,
argument|sinstance
argument_list|,
argument|key
argument_list|,
argument|key_s
argument_list|)
end_macro

begin_decl_stmt
name|KTEXT
name|tkt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The ticket to be decoded */
end_comment

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Kerberos ticket flags */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Authentication name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pinstance
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Principal's instance */
end_comment

begin_decl_stmt
name|char
modifier|*
name|prealm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Principal's authentication domain */
end_comment

begin_decl_stmt
name|unsigned
name|long
modifier|*
name|paddress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Net address of entity                                  * requesting ticket */
end_comment

begin_decl_stmt
name|C_Block
name|session
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Session key inserted in ticket */
end_comment

begin_decl_stmt
name|int
modifier|*
name|life
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lifetime of the ticket */
end_comment

begin_decl_stmt
name|unsigned
name|long
modifier|*
name|time_sec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Issue time and date */
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
name|sinstance
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Service instance */
end_comment

begin_decl_stmt
name|C_Block
name|key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Service's secret key                                  * (to decrypt the ticket) */
end_comment

begin_decl_stmt
name|Key_schedule
name|key_s
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The precomputed key schedule */
end_comment

begin_block
block|{
specifier|static
name|int
name|tkt_swap_bytes
decl_stmt|;
name|unsigned
name|char
modifier|*
name|uptr
decl_stmt|;
name|char
modifier|*
name|ptr
init|=
operator|(
name|char
operator|*
operator|)
name|tkt
operator|->
name|dat
decl_stmt|;
ifndef|#
directive|ifndef
name|NOENCRYPTION
comment|/* Do the decryption */
name|pcbc_encrypt
argument_list|(
operator|(
name|C_Block
operator|*
operator|)
name|tkt
operator|->
name|dat
argument_list|,
operator|(
name|C_Block
operator|*
operator|)
name|tkt
operator|->
name|dat
argument_list|,
operator|(
name|long
operator|)
name|tkt
operator|->
name|length
argument_list|,
name|key_s
argument_list|,
name|key
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ! NOENCRYPTION */
operator|*
name|flags
operator|=
operator|*
name|ptr
expr_stmt|;
comment|/* get flags byte */
name|ptr
operator|+=
sizeof|sizeof
argument_list|(
operator|*
name|flags
argument_list|)
expr_stmt|;
name|tkt_swap_bytes
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|HOST_BYTE_ORDER
operator|!=
operator|(
operator|(
operator|*
name|flags
operator|>>
name|K_FLAG_ORDER
operator|)
operator|&
literal|1
operator|)
condition|)
name|tkt_swap_bytes
operator|++
expr_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|ptr
argument_list|)
operator|>
name|ANAME_SZ
condition|)
return|return
operator|(
name|KFAILURE
operator|)
return|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|pname
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
comment|/* pname */
name|ptr
operator|+=
name|strlen
argument_list|(
name|pname
argument_list|)
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|ptr
argument_list|)
operator|>
name|INST_SZ
condition|)
return|return
operator|(
name|KFAILURE
operator|)
return|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|pinstance
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
comment|/* instance */
name|ptr
operator|+=
name|strlen
argument_list|(
name|pinstance
argument_list|)
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|ptr
argument_list|)
operator|>
name|REALM_SZ
condition|)
return|return
operator|(
name|KFAILURE
operator|)
return|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|prealm
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
comment|/* realm */
name|ptr
operator|+=
name|strlen
argument_list|(
name|prealm
argument_list|)
operator|+
literal|1
expr_stmt|;
comment|/* temporary hack until realms are dealt with properly */
if|if
condition|(
operator|*
name|prealm
operator|==
literal|0
condition|)
return|return
operator|(
name|KFAILURE
operator|)
return|;
ifdef|#
directive|ifdef
name|notdef
name|Do
name|not
name|want
name|to
name|use
name|this
name|definition
operator|-
name|kfall
argument_list|(
argument|void
argument_list|)
name|strcpy
argument_list|(
name|prealm
argument_list|,
name|KRB_REALM
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|bcopy
argument_list|(
name|ptr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|paddress
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|/* net address */
name|ptr
operator|+=
literal|4
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
comment|/* session key */
name|ptr
operator|+=
literal|8
expr_stmt|;
ifdef|#
directive|ifdef
name|notdef
comment|/* DONT SWAP SESSION KEY spm 10/22/86 */
if|if
condition|(
name|tkt_swap_bytes
condition|)
name|swap_C_Block
argument_list|(
name|session
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* get lifetime, being certain we don't get negative lifetimes */
name|uptr
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|ptr
operator|++
expr_stmt|;
operator|*
name|life
operator|=
operator|(
name|int
operator|)
operator|*
name|uptr
expr_stmt|;
name|bcopy
argument_list|(
name|ptr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|time_sec
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|/* issue time */
name|ptr
operator|+=
literal|4
expr_stmt|;
if|if
condition|(
name|tkt_swap_bytes
condition|)
name|swap_u_long
argument_list|(
operator|*
name|time_sec
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|sname
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
comment|/* service name */
name|ptr
operator|+=
literal|1
operator|+
name|strlen
argument_list|(
name|sname
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|sinstance
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
comment|/* instance */
name|ptr
operator|+=
literal|1
operator|+
name|strlen
argument_list|(
name|sinstance
argument_list|)
expr_stmt|;
return|return
operator|(
name|KSUCCESS
operator|)
return|;
block|}
end_block

end_unit

