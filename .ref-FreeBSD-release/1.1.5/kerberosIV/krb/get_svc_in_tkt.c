begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/get_svc_in_tkt.c,v $  * $Author: kfall $  *  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_get_svc_in_tkt_c
index|[]
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/get_svc_in_tkt.c,v 4.10 90/06/25 20:56:10 kfall Exp $"
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
file|<prot.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This file contains two routines: srvtab_to_key(), which gets  * a server's key from a srvtab file, and krb_get_svc_in_tkt() which  * gets an initial ticket for a server.  */
end_comment

begin_comment
comment|/*  * srvtab_to_key(): given a "srvtab" file (where the keys for the  * service on a host are stored), return the private key of the  * given service (user.instance@realm).  *  * srvtab_to_key() passes its arguments on to read_service_key(),  * plus one additional argument, the key version number.  * (Currently, the key version number is always 0; this value  * is treated as a wildcard by read_service_key().)  *  * If the "srvtab" argument is null, KEYFILE (defined in "krb.h")  * is passed in its place.  *  * It returns the return value of the read_service_key() call.  * The service key is placed in "key".  */
end_comment

begin_function
specifier|static
name|int
name|srvtab_to_key
parameter_list|(
name|user
parameter_list|,
name|instance
parameter_list|,
name|realm
parameter_list|,
name|srvtab
parameter_list|,
name|key
parameter_list|)
name|char
modifier|*
name|user
decl_stmt|,
decl|*
name|instance
decl_stmt|,
modifier|*
name|realm
decl_stmt|,
modifier|*
name|srvtab
decl_stmt|;
end_function

begin_decl_stmt
name|C_Block
name|key
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|srvtab
condition|)
name|srvtab
operator|=
name|KEYFILE
expr_stmt|;
return|return
operator|(
name|read_service_key
argument_list|(
name|user
argument_list|,
name|instance
argument_list|,
name|realm
argument_list|,
literal|0
argument_list|,
name|srvtab
argument_list|,
operator|(
name|char
operator|*
operator|)
name|key
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * krb_get_svc_in_tkt() passes its arguments on to krb_get_in_tkt(),  * plus two additional arguments: a pointer to the srvtab_to_key()  * function to be used to get the key from the key file and a NULL  * for the decryption procedure indicating that krb_get_in_tkt should   * use the default method of decrypting the response from the KDC.  *  * It returns the return value of the krb_get_in_tkt() call.  */
end_comment

begin_macro
name|krb_get_svc_in_tkt
argument_list|(
argument|user
argument_list|,
argument|instance
argument_list|,
argument|realm
argument_list|,
argument|service
argument_list|,
argument|sinstance
argument_list|,
argument|life
argument_list|,
argument|srvtab
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|user
decl_stmt|,
modifier|*
name|instance
decl_stmt|,
modifier|*
name|realm
decl_stmt|,
modifier|*
name|service
decl_stmt|,
modifier|*
name|sinstance
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|life
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|srvtab
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|krb_get_in_tkt
argument_list|(
name|user
argument_list|,
name|instance
argument_list|,
name|realm
argument_list|,
name|service
argument_list|,
name|sinstance
argument_list|,
name|life
argument_list|,
name|srvtab_to_key
argument_list|,
name|NULL
argument_list|,
name|srvtab
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

