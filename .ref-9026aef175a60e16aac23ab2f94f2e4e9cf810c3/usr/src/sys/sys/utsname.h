begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chuck Karish of Mindcraft, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)utsname.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UTSNAME_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UTSNAME_H
end_define

begin_struct
struct|struct
name|utsname
block|{
name|char
name|sysname
index|[
literal|256
index|]
decl_stmt|;
comment|/* Name of this OS. */
name|char
name|nodename
index|[
literal|256
index|]
decl_stmt|;
comment|/* Name of this network node. */
name|char
name|release
index|[
literal|256
index|]
decl_stmt|;
comment|/* Release level. */
name|char
name|version
index|[
literal|256
index|]
decl_stmt|;
comment|/* Version level. */
name|char
name|machine
index|[
literal|256
index|]
decl_stmt|;
comment|/* Hardware type. */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|uname
name|__P
argument_list|(
operator|(
expr|struct
name|utsname
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_UTSNAME_H */
end_comment

end_unit

