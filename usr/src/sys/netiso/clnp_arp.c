begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $Header: clnp_arp.c,v 4.2 88/06/29 14:58:32 hagens Exp $ */
end_comment

begin_comment
comment|/* $Source: /usr/argo/sys/netiso/RCS/clnp_arp.c,v $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: clnp_arp.c,v 4.2 88/06/29 14:58:32 hagens Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ISO
end_ifdef

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"domain.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"socketvar.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"../net/if.h"
end_include

begin_include
include|#
directive|include
file|"../net/route.h"
end_include

begin_include
include|#
directive|include
file|"iso.h"
end_include

begin_include
include|#
directive|include
file|"iso_var.h"
end_include

begin_include
include|#
directive|include
file|"iso_map.h"
end_include

begin_include
include|#
directive|include
file|"iso_snpac.h"
end_include

begin_include
include|#
directive|include
file|"clnp.h"
end_include

begin_include
include|#
directive|include
file|"clnp_stat.h"
end_include

begin_include
include|#
directive|include
file|"argo_debug.h"
end_include

begin_define
define|#
directive|define
name|MAPTAB_BSIZ
value|20
end_define

begin_comment
comment|/* bucket size */
end_comment

begin_define
define|#
directive|define
name|MAPTAB_NB
value|13
end_define

begin_comment
comment|/* number of buckets */
end_comment

begin_define
define|#
directive|define
name|MAPTAB_SIZE
value|(MAPTAB_BSIZ * MAPTAB_NB)
end_define

begin_decl_stmt
name|struct
name|maptab
name|iso_maptab
index|[
name|MAPTAB_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iso_maptab_size
init|=
name|MAPTAB_SIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for isomap command */
end_comment

begin_define
define|#
directive|define
name|MAPTAB_HASH
parameter_list|(
name|addr
parameter_list|)
define|\
value|(((u_long) iso_hashchar(addr, addr->isoa_len)) % MAPTAB_NB)
end_define

begin_define
define|#
directive|define
name|MAPTAB_LOOK
parameter_list|(
name|at
parameter_list|,
name|addr
parameter_list|)
value|{ \ 	register n; \ 	at =&iso_maptab[MAPTAB_HASH(addr) * MAPTAB_BSIZ]; \ 	for (n = 0 ; n< MAPTAB_BSIZ ; n++,at++) \ 		if ((at->map_valid)&& (iso_addrmatch1(&at->map_isoa, addr))) \ 			break; \ 	if (n>= MAPTAB_BSIZ) \ 		at = 0; \ }
end_define

begin_comment
comment|/*  * FUNCTION:		clnp_arpresolve  *  * PURPOSE:			Resolve a clnp address into hardware ethernet addr.  *  * RETURNS:			1 if addr is resolved  *					0 if addr is unknown  *  * SIDE EFFECTS:	  *  * NOTES:			This is a hack. If the address is local, then  *					the packet is put on the loopback driver. Otherwise,  *					if a translation is found, that ethernet address is  *					returned. Otherwise, the packet is dropped. Thus,  *					each translation must be placed (by hand) in the  *					tables (see isomap(8)).   *					TODO: should this map stuff be a critical section?  */
end_comment

begin_macro
name|clnp_arpresolve
argument_list|(
argument|ifp
argument_list|,
argument|m
argument_list|,
argument|dst
argument_list|,
argument|edst
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* outgoing interface */
end_comment

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pkt */
end_comment

begin_decl_stmt
name|struct
name|sockaddr_iso
modifier|*
name|dst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* destination */
end_comment

begin_decl_stmt
name|char
modifier|*
name|edst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RESULT: ethernet address */
end_comment

begin_block
block|{
specifier|extern
name|struct
name|ifnet
name|loif
decl_stmt|;
comment|/* loopback interface */
name|struct
name|maptab
modifier|*
name|at
decl_stmt|;
comment|/* ptr to map table entry */
name|struct
name|iso_addr
modifier|*
name|destiso
decl_stmt|;
comment|/* destination iso addr */
name|destiso
operator|=
operator|&
name|dst
operator|->
name|siso_addr
expr_stmt|;
if|if
condition|(
name|destiso
operator|->
name|isoa_genaddr
index|[
literal|0
index|]
operator|==
name|AFI_SNA
condition|)
block|{
comment|/* 		 *	This is a subnetwork address. Return it immediately 		 */
name|int
name|sna_len
decl_stmt|;
name|IFDEBUG
argument_list|(
argument|D_ESISOUTPUT
argument_list|)
name|printf
argument_list|(
literal|"clnp_arpresolve: return SN address\n"
argument_list|)
expr_stmt|;
name|ENDDEBUG
name|sna_len
init|=
name|destiso
operator|->
name|isoa_len
operator|-
literal|1
decl_stmt|;
comment|/* subtract size of AFI */
if|if
condition|(
name|sna_len
operator|!=
literal|6
condition|)
block|{
name|IFDEBUG
argument_list|(
argument|D_ESISOUTPUT
argument_list|)
name|printf
argument_list|(
literal|"clnp_arpresolve: SN len is bad (%d)\n"
argument_list|,
name|sna_len
argument_list|)
expr_stmt|;
name|ENDDEBUG
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|destiso
operator|->
name|isoa_genaddr
index|[
literal|1
index|]
argument_list|,
operator|(
name|caddr_t
operator|)
name|edst
argument_list|,
name|sna_len
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|IFDEBUG
argument_list|(
argument|D_ETHER
argument_list|)
name|printf
argument_list|(
literal|"clnp_arpresolve: resolving %s\n"
argument_list|,
name|clnp_iso_addrp
argument_list|(
name|destiso
argument_list|)
argument_list|)
expr_stmt|;
name|ENDDEBUG
comment|/* if for us, use software loopback driver if up */
if|if
condition|(
name|clnp_ours
argument_list|(
name|destiso
argument_list|)
condition|)
block|{
name|IFDEBUG
argument_list|(
argument|D_ETHER
argument_list|)
name|printf
argument_list|(
literal|"clnp_arpresolve: local destination\n"
argument_list|)
expr_stmt|;
name|ENDDEBUG
if|if
condition|(
name|loif
operator|.
name|if_flags
operator|&
name|IFF_UP
condition|)
block|{
name|IFDEBUG
argument_list|(
argument|D_ETHER
argument_list|)
name|printf
argument_list|(
literal|"clnp_arpresolve: calling looutput\n"
argument_list|)
expr_stmt|;
name|ENDDEBUG
argument_list|(
argument|void
argument_list|)
name|looutput
argument_list|(
operator|&
name|loif
argument_list|,
name|m
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
name|dst
argument_list|)
expr_stmt|;
comment|/* 			 * The packet has already been sent and freed. 			 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
name|IFDEBUG
argument_list|(
argument|D_ETHER
argument_list|)
name|printf
argument_list|(
literal|"clnp_arpresolve: NON-local destination\n"
argument_list|)
expr_stmt|;
name|ENDDEBUG
comment|/*  	 *	packet is not for us, check static map table for an entry  	 *	This does not need to be a critical section because the  	 *	table is not dynamically updated, except by a call to  	 *	isomap(8) 	 */
name|MAPTAB_LOOK
parameter_list|(
name|at
parameter_list|,
name|destiso
parameter_list|)
function_decl|;
if|if
condition|(
name|at
operator|==
literal|0
condition|)
block|{
comment|/* not found */
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
else|else
block|{
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
name|at
operator|->
name|map_enaddr
argument_list|,
operator|(
name|caddr_t
operator|)
name|edst
argument_list|,
sizeof|sizeof
argument_list|(
name|at
operator|->
name|map_enaddr
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
end_block

begin_comment
comment|/*  * FUNCTION:		isomap_new  *  * PURPOSE:			create a new entry in the iso address to ethernet  *					address table  *  * RETURNS:			pointer to newest entry, or NULL if none can be found  *  * SIDE EFFECTS:	  *  * NOTES:			TODO: timeout old entries  */
end_comment

begin_function
name|struct
name|maptab
modifier|*
name|isomap_new
parameter_list|(
name|isoa
parameter_list|)
name|struct
name|iso_addr
modifier|*
name|isoa
decl_stmt|;
comment|/* iso address to enter into table */
block|{
specifier|register
name|struct
name|maptab
modifier|*
name|at
decl_stmt|;
specifier|register
name|int
name|n
decl_stmt|;
name|at
operator|=
operator|&
name|iso_maptab
index|[
name|MAPTAB_HASH
argument_list|(
name|isoa
argument_list|)
operator|*
name|MAPTAB_BSIZ
index|]
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|MAPTAB_BSIZ
condition|;
name|n
operator|++
operator|,
name|at
operator|++
control|)
block|{
name|IFDEBUG
argument_list|(
argument|D_IOCTL
argument_list|)
name|printf
argument_list|(
literal|"isomap_new: at x%x "
argument_list|,
name|at
argument_list|)
expr_stmt|;
if|if
condition|(
name|at
operator|->
name|map_valid
condition|)
block|{
name|int
name|i
decl_stmt|;
name|printf
argument_list|(
literal|"(valid) %s "
argument_list|,
name|clnp_iso_addrp
argument_list|(
operator|&
name|at
operator|->
name|map_isoa
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|6
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"%x%c"
argument_list|,
name|at
operator|->
name|map_enaddr
index|[
name|i
index|]
argument_list|,
name|i
operator|<
literal|5
condition|?
literal|':'
else|:
literal|'\n'
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"invalid\n"
argument_list|)
expr_stmt|;
block|}
name|ENDDEBUG
if|if
condition|(
operator|!
name|at
operator|->
name|map_valid
condition|)
comment|/* found unused slot */
return|return
name|at
return|;
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/*  * FUNCTION:		isomap_free  *  * PURPOSE:			free an entry in the iso address map table  *  * RETURNS:			nothing  *  * SIDE EFFECTS:	  *  * NOTES:			  */
end_comment

begin_expr_stmt
name|isomap_free
argument_list|(
name|at
argument_list|)
specifier|register
expr|struct
name|maptab
operator|*
name|at
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* entry to free */
end_comment

begin_block
block|{
name|at
operator|->
name|map_valid
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * FUNCTION:		isomap_ioctl  *  * PURPOSE:			handle ioctls to change the iso address map  *  * RETURNS:			unix error code  *  * SIDE EFFECTS:	changes the maptab table declared above.  *  * NOTES:			  */
end_comment

begin_macro
name|isomap_ioctl
argument_list|(
argument|cmd
argument_list|,
argument|data
argument_list|)
end_macro

begin_decl_stmt
name|int
name|cmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ioctl to process */
end_comment

begin_decl_stmt
name|caddr_t
name|data
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data for the cmd */
end_comment

begin_block
block|{
specifier|register
name|struct
name|arpreq_iso
modifier|*
name|ar
init|=
operator|(
expr|struct
name|arpreq_iso
operator|*
operator|)
name|data
decl_stmt|;
specifier|register
name|struct
name|maptab
modifier|*
name|at
decl_stmt|;
specifier|register
name|struct
name|sockaddr_iso
modifier|*
name|siso
decl_stmt|;
specifier|register
name|struct
name|iso_addr
modifier|*
name|isoa
decl_stmt|;
comment|/* 	 *	only process commands for the ISO address family 	 */
if|if
condition|(
name|ar
operator|->
name|arp_pa
operator|.
name|siso_family
operator|!=
name|AF_ISO
condition|)
return|return
operator|(
name|EAFNOSUPPORT
operator|)
return|;
comment|/* look up this address in table */
name|siso
operator|=
operator|(
expr|struct
name|sockaddr_iso
operator|*
operator|)
operator|&
name|ar
operator|->
name|arp_pa
expr_stmt|;
name|isoa
operator|=
operator|&
name|siso
operator|->
name|siso_addr
expr_stmt|;
name|IFDEBUG
argument_list|(
argument|D_IOCTL
argument_list|)
name|int
name|i
decl_stmt|;
name|printf
argument_list|(
literal|"isomap_ioctl: "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|SIOCSISOMAP
case|:
name|printf
argument_list|(
literal|"set"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCDISOMAP
case|:
name|printf
argument_list|(
literal|"delete"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCGISOMAP
case|:
name|printf
argument_list|(
literal|"get"
argument_list|)
expr_stmt|;
break|break;
block|}
name|printf
argument_list|(
literal|" %s to "
argument_list|,
name|clnp_iso_addrp
argument_list|(
name|isoa
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|6
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"%x%c"
argument_list|,
name|ar
operator|->
name|arp_ha
operator|.
name|sa_data
index|[
name|i
index|]
argument_list|,
name|i
operator|<
literal|5
condition|?
literal|':'
else|:
literal|'\n'
argument_list|)
expr_stmt|;
name|ENDDEBUG
name|MAPTAB_LOOK
parameter_list|(
name|at
parameter_list|,
name|isoa
parameter_list|)
function_decl|;
if|if
condition|(
name|at
operator|==
name|NULL
condition|)
block|{
comment|/* not found */
if|if
condition|(
name|cmd
operator|!=
name|SIOCSISOMAP
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
comment|/* TODO: what if setting and net is not directly attached */
block|}
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|SIOCSISOMAP
case|:
comment|/* set entry */
if|if
condition|(
name|at
operator|==
name|NULL
condition|)
block|{
name|at
operator|=
name|isomap_new
argument_list|(
name|isoa
argument_list|)
expr_stmt|;
if|if
condition|(
name|at
operator|==
name|NULL
condition|)
return|return
operator|(
name|ENOBUFS
operator|)
return|;
block|}
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
name|isoa
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|at
operator|->
name|map_isoa
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|iso_addr
argument_list|)
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
name|ar
operator|->
name|arp_ha
operator|.
name|sa_data
argument_list|,
operator|(
name|caddr_t
operator|)
name|at
operator|->
name|map_enaddr
argument_list|,
sizeof|sizeof
argument_list|(
name|at
operator|->
name|map_enaddr
argument_list|)
argument_list|)
expr_stmt|;
name|at
operator|->
name|map_valid
operator|++
expr_stmt|;
break|break;
case|case
name|SIOCDISOMAP
case|:
comment|/* delete entry */
name|isomap_free
argument_list|(
name|at
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCGISOMAP
case|:
comment|/* get entry */
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
name|at
operator|->
name|map_enaddr
argument_list|,
operator|(
name|caddr_t
operator|)
name|ar
operator|->
name|arp_ha
operator|.
name|sa_data
argument_list|,
sizeof|sizeof
argument_list|(
name|at
operator|->
name|map_enaddr
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|ISO
end_endif

end_unit

