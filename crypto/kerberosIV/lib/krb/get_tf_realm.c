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
literal|"$Id: get_tf_realm.c,v 1.5 1997/03/23 03:53:10 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This file contains a routine to extract the realm of a kerberos  * ticket file.  */
end_comment

begin_comment
comment|/*  * krb_get_tf_realm() takes two arguments: the name of a ticket   * and a variable to store the name of the realm in.  *   */
end_comment

begin_function
name|int
name|krb_get_tf_realm
parameter_list|(
name|char
modifier|*
name|ticket_file
parameter_list|,
name|char
modifier|*
name|realm
parameter_list|)
block|{
return|return
operator|(
name|krb_get_tf_fullname
argument_list|(
name|ticket_file
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|realm
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

