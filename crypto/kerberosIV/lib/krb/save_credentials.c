begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    Copyright (C) 1989 by the Massachusetts Institute of Technology     Export of this software from the United States of America is assumed    to require a specific license from the United States Government.    It is the responsibility of any person or organization contemplating    export to obtain such a license before exporting.  WITHIN THAT CONSTRAINT, permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty.    */
end_comment

begin_include
include|#
directive|include
file|"krb_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: save_credentials.c,v 1.5 1997/03/23 03:53:17 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/* Service name */
name|char
modifier|*
name|instance
parameter_list|,
comment|/* Instance */
name|char
modifier|*
name|realm
parameter_list|,
comment|/* Auth domain */
name|unsigned
name|char
modifier|*
name|session
parameter_list|,
comment|/* Session key */
name|int
name|lifetime
parameter_list|,
comment|/* Lifetime */
name|int
name|kvno
parameter_list|,
comment|/* Key version number */
name|KTEXT
name|ticket
parameter_list|,
comment|/* The ticket itself */
name|int32_t
name|issue_date
parameter_list|)
comment|/* The issue time */
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

