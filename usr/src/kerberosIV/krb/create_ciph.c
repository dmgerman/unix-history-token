begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/create_ciph.c,v $  * $Author: kfall $  *  * Copyright 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
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
name|rcsid_create_ciph_c
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/create_ciph.c,v 4.9 90/06/25 20:55:25 kfall Exp $"
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
file|<strings.h>
end_include

begin_comment
comment|/*  * This routine is used by the authentication server to create  * a packet for its client, containing a ticket for the requested  * service (given in "tkt"), and some information about the ticket, #ifndef NOENCRYPTION  * all encrypted in the given key ("key"). #endif  *  * Returns KSUCCESS no matter what.  *  * The length of the cipher is stored in c->length; the format of  * c->dat is as follows:  *  * 			variable  * type			or constant	   data  * ----			-----------	   ----  *   *   * 8 bytes		session		session key for client, service  *   * string		service		service name  *   * string		instance	service instance  *   * string		realm		KDC realm  *   * unsigned char	life		ticket lifetime  *   * unsigned char	kvno		service key version number  *   * unsigned char	tkt->length	length of following ticket  *   * data			tkt->dat	ticket for service  *   * 4 bytes		kdc_time	KDC's timestamp  *  *<=7 bytes		null		   null pad to 8 byte multiple  *  */
end_comment

begin_macro
name|create_ciph
argument_list|(
argument|c
argument_list|,
argument|session
argument_list|,
argument|service
argument_list|,
argument|instance
argument_list|,
argument|realm
argument_list|,
argument|life
argument_list|,
argument|kvno
argument_list|,
argument|tkt
argument_list|,
argument|kdc_time
argument_list|,
argument|key
argument_list|)
end_macro

begin_decl_stmt
name|KTEXT
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Text block to hold ciphertext */
end_comment

begin_decl_stmt
name|C_Block
name|session
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Session key to send to user */
end_comment

begin_decl_stmt
name|char
modifier|*
name|service
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Service name on ticket */
end_comment

begin_decl_stmt
name|char
modifier|*
name|instance
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Instance name on ticket */
end_comment

begin_decl_stmt
name|char
modifier|*
name|realm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Realm of this KDC */
end_comment

begin_decl_stmt
name|unsigned
name|long
name|life
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lifetime of the ticket */
end_comment

begin_decl_stmt
name|int
name|kvno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Key version number for service */
end_comment

begin_decl_stmt
name|KTEXT
name|tkt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The ticket for the service */
end_comment

begin_decl_stmt
name|unsigned
name|long
name|kdc_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* KDC time */
end_comment

begin_decl_stmt
name|C_Block
name|key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Key to encrypt ciphertext with */
end_comment

begin_block
block|{
name|char
modifier|*
name|ptr
decl_stmt|;
name|Key_schedule
name|key_s
decl_stmt|;
name|ptr
operator|=
operator|(
name|char
operator|*
operator|)
name|c
operator|->
name|dat
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|session
argument_list|,
name|ptr
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|ptr
operator|+=
literal|8
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|ptr
argument_list|,
name|service
argument_list|)
expr_stmt|;
name|ptr
operator|+=
name|strlen
argument_list|(
name|service
argument_list|)
operator|+
literal|1
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|ptr
argument_list|,
name|instance
argument_list|)
expr_stmt|;
name|ptr
operator|+=
name|strlen
argument_list|(
name|instance
argument_list|)
operator|+
literal|1
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|ptr
argument_list|,
name|realm
argument_list|)
expr_stmt|;
name|ptr
operator|+=
name|strlen
argument_list|(
name|realm
argument_list|)
operator|+
literal|1
expr_stmt|;
operator|*
operator|(
name|ptr
operator|++
operator|)
operator|=
operator|(
name|unsigned
name|char
operator|)
name|life
expr_stmt|;
operator|*
operator|(
name|ptr
operator|++
operator|)
operator|=
operator|(
name|unsigned
name|char
operator|)
name|kvno
expr_stmt|;
operator|*
operator|(
name|ptr
operator|++
operator|)
operator|=
operator|(
name|unsigned
name|char
operator|)
name|tkt
operator|->
name|length
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
name|tkt
operator|->
name|dat
operator|)
argument_list|,
name|ptr
argument_list|,
name|tkt
operator|->
name|length
argument_list|)
expr_stmt|;
name|ptr
operator|+=
name|tkt
operator|->
name|length
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|kdc_time
argument_list|,
name|ptr
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|ptr
operator|+=
literal|4
expr_stmt|;
comment|/* guarantee null padded encrypted data to multiple of 8 bytes */
name|bzero
argument_list|(
name|ptr
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|c
operator|->
name|length
operator|=
operator|(
operator|(
operator|(
name|ptr
operator|-
operator|(
name|char
operator|*
operator|)
name|c
operator|->
name|dat
operator|)
operator|+
literal|7
operator|)
operator|/
literal|8
operator|)
operator|*
literal|8
expr_stmt|;
ifndef|#
directive|ifndef
name|NOENCRYPTION
name|key_sched
argument_list|(
name|key
argument_list|,
name|key_s
argument_list|)
expr_stmt|;
name|pcbc_encrypt
argument_list|(
operator|(
name|C_Block
operator|*
operator|)
name|c
operator|->
name|dat
argument_list|,
operator|(
name|C_Block
operator|*
operator|)
name|c
operator|->
name|dat
argument_list|,
operator|(
name|long
operator|)
name|c
operator|->
name|length
argument_list|,
name|key_s
argument_list|,
name|key
argument_list|,
name|ENCRYPT
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOENCRYPTION */
return|return
operator|(
name|KSUCCESS
operator|)
return|;
block|}
end_block

end_unit

