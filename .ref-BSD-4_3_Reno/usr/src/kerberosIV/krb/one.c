begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /mit/kerberos/src/lib/krb/RCS/one.c,v $  * $Author: jtkohl $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_one_c
index|[]
init|=
literal|"$Header: one.c,v 4.1 88/11/15 16:51:41 jtkohl Exp $"
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
comment|/*  * definition of variable set to 1.  * used in krb_conf.h to determine host byte order.  */
end_comment

begin_decl_stmt
name|int
name|krbONE
init|=
literal|1
decl_stmt|;
end_decl_stmt

end_unit

