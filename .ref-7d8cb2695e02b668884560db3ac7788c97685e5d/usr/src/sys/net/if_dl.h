begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)if_dl.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * A Link-Level Sockaddr may specify the interface in one of two  * ways: either by means of a system-provided index number (computed  * anew and possibly differently on every reboot), or by a human-readable  * string such as "il0" (for managerial convenience).  *   * Census taking actions, such as something akin to SIOCGCONF would return  * both the index and the human name.  *   * High volume transactions (such as giving a link-level ``from'' address  * in a recvfrom or recvmsg call) may be likely only to provide the indexed  * form, (which requires fewer copy operations and less space).  *   * The form and interpretation  of the link-level address is purely a matter  * of convention between the device driver and its consumers; however, it is  * expected that all drivers for an interface of a given if_type will agree.  */
end_comment

begin_comment
comment|/*  * Structure of a Link-Level sockaddr:  */
end_comment

begin_struct
struct|struct
name|sockaddr_dl
block|{
name|u_char
name|sdl_len
decl_stmt|;
comment|/* Total length of sockaddr */
name|u_char
name|sdl_family
decl_stmt|;
comment|/* AF_DLI */
name|u_short
name|sdl_index
decl_stmt|;
comment|/* if != 0, system given index for interface */
name|u_char
name|sdl_type
decl_stmt|;
comment|/* interface type */
name|u_char
name|sdl_nlen
decl_stmt|;
comment|/* interface name length, no trailing 0 reqd. */
name|u_char
name|sdl_alen
decl_stmt|;
comment|/* link level address length */
name|u_char
name|sdl_slen
decl_stmt|;
comment|/* link layer selector length */
name|char
name|sdl_data
index|[
literal|12
index|]
decl_stmt|;
comment|/* minimum work area, can be larger; 				   contains both if name and ll address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LLADDR
parameter_list|(
name|s
parameter_list|)
value|((caddr_t)((s)->sdl_data + (s)->sdl_nlen))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|link_addr
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|sockaddr_dl
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|link_ntoa
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|sockaddr_dl
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
comment|/* !KERNEL */
end_comment

end_unit

