begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	form: one.c,v 4.1 88/11/15 16:51:41 jtkohl Exp $  * $FreeBSD$  */
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
unit|static char rcsid[] = "$FreeBSD$";
endif|#
directive|endif
endif|lint
end_endif

begin_endif
endif|#
directive|endif
end_endif

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

