begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/save_credentials.c,v $  * $Author: kfall $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
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
name|rcsid_save_credentials_c
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/save_credentials.c,v 4.10 90/06/25 20:57:18 kfall Exp $"
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
comment|/*  * This routine takes a ticket and associated info and calls  * tf_save_cred() to store them in the ticket cache.  The peer  * routine for extracting a ticket and associated info from the  * ticket cache is krb_get_cred().  When changes are made to  * this routine, the corresponding changes should be made  * in krb_get_cred() as well.  *  * Returns KSUCCESS if all goes well, otherwise an error returned  * by the tf_init() or tf_save_cred() routines.  */
end_comment

begin_macro
name|save_credentials
argument_list|(
argument|service
argument_list|,
argument|instance
argument_list|,
argument|realm
argument_list|,
argument|session
argument_list|,
argument|lifetime
argument_list|,
argument|kvno
argument_list|,
argument|ticket
argument_list|,
argument|issue_date
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
name|C_Block
name|session
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Session key */
end_comment

begin_decl_stmt
name|int
name|lifetime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lifetime */
end_comment

begin_decl_stmt
name|int
name|kvno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Key version number */
end_comment

begin_decl_stmt
name|KTEXT
name|ticket
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The ticket itself */
end_comment

begin_decl_stmt
name|long
name|issue_date
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The issue time */
end_comment

begin_block
block|{
name|int
name|tf_status
decl_stmt|;
comment|/* return values of the tf_util calls */
comment|/* Open and lock the ticket file for writing */
if|if
condition|(
operator|(
name|tf_status
operator|=
name|tf_init
argument_list|(
name|TKT_FILE
argument_list|,
name|W_TKT_FIL
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
comment|/* Save credentials by appending to the ticket file */
name|tf_status
operator|=
name|tf_save_cred
argument_list|(
name|service
argument_list|,
name|instance
argument_list|,
name|realm
argument_list|,
name|session
argument_list|,
name|lifetime
argument_list|,
name|kvno
argument_list|,
name|ticket
argument_list|,
name|issue_date
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|tf_close
argument_list|()
expr_stmt|;
return|return
operator|(
name|tf_status
operator|)
return|;
block|}
end_block

end_unit

