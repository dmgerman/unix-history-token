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
literal|"$Id: debug_decl.c,v 1.10 1999/06/16 15:10:38 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Declare global debugging variables. */
end_comment

begin_decl_stmt
name|int
name|krb_ap_req_debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_dns_debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|krb_enable_debug
parameter_list|(
name|void
parameter_list|)
block|{
name|krb_ap_req_debug
operator|=
name|krb_debug
operator|=
name|krb_dns_debug
operator|=
literal|1
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|krb_disable_debug
parameter_list|(
name|void
parameter_list|)
block|{
name|krb_ap_req_debug
operator|=
name|krb_debug
operator|=
name|krb_dns_debug
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

