begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)un.h	7.7 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Definitions for UNIX IPC domain.  */
end_comment

begin_struct
struct|struct
name|sockaddr_un
block|{
name|u_char
name|sun_len
decl_stmt|;
comment|/* sockaddr len including null */
name|u_char
name|sun_family
decl_stmt|;
comment|/* AF_UNIX */
name|char
name|sun_path
index|[
literal|104
index|]
decl_stmt|;
comment|/* path name (gag) */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|int
name|unp_discard
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* actual length of an initialized sockaddr_un */
end_comment

begin_define
define|#
directive|define
name|SUN_LEN
parameter_list|(
name|su
parameter_list|)
define|\
value|(sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

