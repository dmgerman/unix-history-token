begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: debug_decl.c,v 4.5 88/10/07 06:07:49 shanzer Exp $  *	$Id: debug_decl.c,v 1.2 1994/07/19 19:25:03 g89r4222 Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: debug_decl.c,v 1.2 1994/07/19 19:25:03 g89r4222 Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

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

