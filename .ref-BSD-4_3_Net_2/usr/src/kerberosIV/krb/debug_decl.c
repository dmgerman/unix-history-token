begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /mit/kerberos/src/lib/krb/RCS/debug_decl.c,v $  * $Author: shanzer $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_debug_decl_c
index|[]
init|=
literal|"$Header: debug_decl.c,v 4.5 88/10/07 06:07:49 shanzer Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

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

end_unit

