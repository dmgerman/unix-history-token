begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /mit/kerberos/src/lib/des/RCS/debug_decl.c,v $  * $Author: steiner $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Declaration of debugging flag.  */
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
literal|"$Header: debug_decl.c,v 4.2 88/02/24 14:20:36 steiner Exp $"
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

begin_decl_stmt
name|int
name|des_debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

end_unit

