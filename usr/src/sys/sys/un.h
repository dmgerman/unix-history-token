begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)un.h	8.2 (Berkeley) %G%  */
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

begin_struct_decl
struct_decl|struct
name|unpcb
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|uipc_usrreq
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|req
operator|,
expr|struct
name|mbuf
operator|*
name|m
operator|,
expr|struct
name|mbuf
operator|*
name|nam
operator|,
expr|struct
name|mbuf
operator|*
name|control
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unp_attach
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unp_bind
name|__P
argument_list|(
operator|(
expr|struct
name|unpcb
operator|*
name|unp
operator|,
expr|struct
name|mbuf
operator|*
name|nam
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unp_connect
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|mbuf
operator|*
name|nam
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unp_connect2
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|socket
operator|*
name|so2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unp_detach
name|__P
argument_list|(
operator|(
expr|struct
name|unpcb
operator|*
name|unp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unp_discard
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unp_disconnect
name|__P
argument_list|(
operator|(
expr|struct
name|unpcb
operator|*
name|unp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unp_drop
name|__P
argument_list|(
operator|(
expr|struct
name|unpcb
operator|*
name|unp
operator|,
name|int
name|errno
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unp_gc
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unp_mark
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unp_scan
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|m0
operator|,
name|void
argument_list|(
argument|*op
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unp_shutdown
name|__P
argument_list|(
operator|(
expr|struct
name|unpcb
operator|*
name|unp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KERNEL */
end_comment

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

begin_comment
comment|/* KERNEL */
end_comment

end_unit

