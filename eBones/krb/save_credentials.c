begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: save_credentials.c,v 4.9 89/05/31 17:45:43 jtkohl Exp $  *	$Id: save_credentials.c,v 1.3 1995/07/18 16:39:40 mark Exp $  */
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
unit|static char *rcsid = "$Id: save_credentials.c,v 1.3 1995/07/18 16:39:40 mark Exp $";
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
file|<krb.h>
end_include

begin_comment
comment|/*  * This routine takes a ticket and associated info and calls  * tf_save_cred() to store them in the ticket cache.  The peer  * routine for extracting a ticket and associated info from the  * ticket cache is krb_get_cred().  When changes are made to  * this routine, the corresponding changes should be made  * in krb_get_cred() as well.  *  * Returns KSUCCESS if all goes well, otherwise an error returned  * by the tf_init() or tf_save_cred() routines.  */
end_comment

begin_function
name|int
name|save_credentials
parameter_list|(
name|char
modifier|*
name|service
parameter_list|,
name|char
modifier|*
name|instance
parameter_list|,
name|char
modifier|*
name|realm
parameter_list|,
name|des_cblock
name|session
parameter_list|,
name|int
name|lifetime
parameter_list|,
name|int
name|kvno
parameter_list|,
name|KTEXT
name|ticket
parameter_list|,
name|long
name|issue_date
parameter_list|)
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
end_function

end_unit

