begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* this is a hacked version of if.h from unix to contain the stuff we need only to build named (bind) with    the minimal amount of changes... by l. kahn */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_H
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_H
end_define

begin_comment
comment|/* #pragma ident	"@(#)if.h	1.3	93/06/30 SMI" /* if.h 1.26 90/05/29 SMI; from UCB 7.1 6/4/86		*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * Structures defining a network interface, providing a packet  * transport mechanism (ala level 0 of the PUP protocols).  *  * Each interface accepts output datagrams of a specified maximum  * length, and provides higher level routines with input datagrams  * received from its medium.  *  * Output occurs when the routine if_output is called, with three parameters:  *	(*ifp->if_output)(ifp, m, dst)  * Here m is the mbuf chain to be sent and dst is the destination address.  * The output routine encapsulates the supplied datagram if necessary,  * and then transmits it on its medium.  *  * On input, each interface unwraps the data received by it, and either  * places it on the input queue of a internetwork datagram routine  * and posts the associated software interrupt, or passes the datagram to a raw  * packet input routine.  *  * Routines exist for locating interfaces by their addresses  * or for locating a interface on a certain network, as well as more general  * routing and gateway routines maintaining information used to locate  * interfaces.  These routines live in the files if.c and route.c  */
comment|/*  * Structure defining a queue for a network interface.  *  * (Would like to call this struct ``if'', but C isn't PL/1.)  */
comment|/*  * Interface request structure used for socket  * ioctl's.  All interface ioctl's must have parameter  * definitions which begin with ifr_name.  The  * remainder may be interface specific.  */
ifdef|#
directive|ifdef
name|FD_SETSIZE
undef|#
directive|undef
name|FD_SETSIZE
endif|#
directive|endif
define|#
directive|define
name|FD_SETSIZE
value|512
include|#
directive|include
file|<winsock.h>
typedef|typedef
name|char
modifier|*
name|caddr_t
typedef|;
name|int
name|get_winnt_interfaces
parameter_list|()
function_decl|;
struct|struct
name|ifreq
block|{
define|#
directive|define
name|IFNAMSIZ
value|16
name|char
name|ifr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|sockaddr
name|ifru_addr
decl_stmt|;
name|char
name|nt_mask
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* new field to store mask returned from nt lookup l. kahn */
define|#
directive|define
name|ifr_addr
value|ifru_addr
comment|/* address */
define|#
directive|define
name|ifr_mask
value|nt_mask
comment|/* nt mask in character form */
block|}
struct|;
comment|/*  * Structure used in SIOCGIFCONF request.  * Used to retrieve interface configuration  * for machine (useful for programs which  * must know all networks accessible).  */
struct|struct
name|ifconf
block|{
name|int
name|ifc_len
decl_stmt|;
comment|/* size of associated buffer */
union|union
block|{
name|caddr_t
name|ifcu_buf
decl_stmt|;
name|struct
name|ifreq
modifier|*
name|ifcu_req
decl_stmt|;
block|}
name|ifc_ifcu
union|;
define|#
directive|define
name|ifc_buf
value|ifc_ifcu.ifcu_buf
comment|/* buffer address */
define|#
directive|define
name|ifc_req
value|ifc_ifcu.ifcu_req
comment|/* array of structures returned */
block|}
struct|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_H */
end_comment

end_unit

