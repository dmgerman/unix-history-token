begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/get_cred.c,v $  * $Author: kfall $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
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
name|rcsid_get_cred_c
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/get_cred.c,v 4.11 90/06/25 20:55:51 kfall Exp $"
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

begin_comment
comment|/*  * krb_get_cred takes a service name, instance, and realm, and a  * structure of type CREDENTIALS to be filled in with ticket  * information.  It then searches the ticket file for the appropriate  * ticket and fills in the structure with the corresponding  * information from the file.  If successful, it returns KSUCCESS.  * On failure it returns a Kerberos error code.  */
end_comment

begin_macro
name|krb_get_cred
argument_list|(
argument|service
argument_list|,
argument|instance
argument_list|,
argument|realm
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|service
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
name|char
modifier|*
name|realm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Auth domain */
end_comment

begin_decl_stmt
name|CREDENTIALS
modifier|*
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Credentials struct */
end_comment

begin_block
block|{
name|int
name|tf_status
decl_stmt|;
comment|/* return value of tf function calls */
comment|/* Open ticket file and lock it for shared reading */
if|if
condition|(
operator|(
name|tf_status
operator|=
name|tf_init
argument_list|(
name|TKT_FILE
argument_list|,
name|R_TKT_FIL
argument_list|)
operator|)
operator|!=
name|KSUCCESS
condition|)
return|return
operator|(
name|tf_status
operator|)
return|;
comment|/* Copy principal's name and instance into the CREDENTIALS struc c */
if|if
condition|(
operator|(
name|tf_status
operator|=
name|tf_get_pname
argument_list|(
name|c
operator|->
name|pname
argument_list|)
operator|)
operator|!=
name|KSUCCESS
operator|||
operator|(
name|tf_status
operator|=
name|tf_get_pinst
argument_list|(
name|c
operator|->
name|pinst
argument_list|)
operator|)
operator|!=
name|KSUCCESS
condition|)
return|return
operator|(
name|tf_status
operator|)
return|;
comment|/* Search for requested service credentials and copy into c */
while|while
condition|(
operator|(
name|tf_status
operator|=
name|tf_get_cred
argument_list|(
name|c
argument_list|)
operator|)
operator|==
name|KSUCCESS
condition|)
block|{
comment|/* Is this the right ticket? */
if|if
condition|(
operator|(
name|strcmp
argument_list|(
name|c
operator|->
name|service
argument_list|,
name|service
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|strcmp
argument_list|(
name|c
operator|->
name|instance
argument_list|,
name|instance
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|strcmp
argument_list|(
name|c
operator|->
name|realm
argument_list|,
name|realm
argument_list|)
operator|==
literal|0
operator|)
condition|)
break|break;
block|}
operator|(
name|void
operator|)
name|tf_close
argument_list|()
expr_stmt|;
if|if
condition|(
name|tf_status
operator|==
name|EOF
condition|)
return|return
operator|(
name|GC_NOTKT
operator|)
return|;
return|return
operator|(
name|tf_status
operator|)
return|;
block|}
end_block

end_unit

