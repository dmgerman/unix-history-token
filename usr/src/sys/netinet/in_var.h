begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)in_var.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Interface address, Internet version.  One of these structures  * is allocated for each interface with an Internet address.  * The ifaddr structure contains the protocol-independent part  * of the structure and is assumed to be first.  */
end_comment

begin_struct
struct|struct
name|in_ifaddr
block|{
name|struct
name|ifaddr
name|ia_ifa
decl_stmt|;
comment|/* protocol-independent info */
define|#
directive|define
name|ia_ifp
value|ia_ifa.ifa_ifp
define|#
directive|define
name|ia_flags
value|ia_ifa.ifa_flags
comment|/* ia_{,sub}net{,mask} in host order */
name|u_long
name|ia_net
decl_stmt|;
comment|/* network number of interface */
name|u_long
name|ia_netmask
decl_stmt|;
comment|/* mask of net part */
name|u_long
name|ia_subnet
decl_stmt|;
comment|/* subnet number, including net */
name|u_long
name|ia_subnetmask
decl_stmt|;
comment|/* mask of subnet part */
name|struct
name|in_addr
name|ia_netbroadcast
decl_stmt|;
comment|/* to recognize net broadcasts */
name|struct
name|in_ifaddr
modifier|*
name|ia_next
decl_stmt|;
comment|/* next in list of internet addresses */
name|struct
name|sockaddr_in
name|ia_addr
decl_stmt|;
comment|/* reserve space for interface name */
name|struct
name|sockaddr_in
name|ia_dstaddr
decl_stmt|;
comment|/* reserve space for broadcast addr */
define|#
directive|define
name|ia_broadaddr
value|ia_dstaddr
name|struct
name|sockaddr_in
name|ia_sockmask
decl_stmt|;
comment|/* reserve space for general netmask */
name|struct
name|in_multi
modifier|*
name|ia_multiaddrs
decl_stmt|;
comment|/* list of multicast addresses */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|in_aliasreq
block|{
name|char
name|ifra_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|sockaddr_in
name|ifra_addr
decl_stmt|;
name|struct
name|sockaddr_in
name|ifra_broadaddr
decl_stmt|;
define|#
directive|define
name|ifra_dstaddr
value|ifra_broadaddr
name|struct
name|sockaddr_in
name|ifra_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Given a pointer to an in_ifaddr (ifaddr),  * return a pointer to the addr as a sockaddr_in.  */
end_comment

begin_define
define|#
directive|define
name|IA_SIN
parameter_list|(
name|ia
parameter_list|)
value|(&(((struct in_ifaddr *)(ia))->ia_addr))
end_define

begin_define
define|#
directive|define
name|IN_LNAOF
parameter_list|(
name|in
parameter_list|,
name|ifa
parameter_list|)
define|\
value|((ntohl((in).s_addr)& ~((struct in_ifaddr *)(ifa)->ia_subnetmask))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|in_ifaddr
modifier|*
name|in_ifaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ifqueue
name|ipintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip packet input queue */
end_comment

begin_decl_stmt
name|void
name|in_socktrim
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Macro for finding the interface (ifnet structure) corresponding to one  * of our IP addresses.  */
end_comment

begin_define
define|#
directive|define
name|INADDR_TO_IFP
parameter_list|(
name|addr
parameter_list|,
name|ifp
parameter_list|)
define|\
comment|/* struct in_addr addr; */
define|\
comment|/* struct ifnet *ifp; */
define|\
value|{ \ 	register struct in_ifaddr *ia; \ \ 	for (ia = in_ifaddr; \ 	    ia != NULL&& IA_SIN(ia)->sin_addr.s_addr != (addr).s_addr; \ 	    ia = ia->ia_next) \ 		 continue; \ 	(ifp) = (ia == NULL) ? NULL : ia->ia_ifp; \ }
end_define

begin_comment
comment|/*  * Macro for finding the internet address structure (in_ifaddr) corresponding  * to a given interface (ifnet structure).  */
end_comment

begin_define
define|#
directive|define
name|IFP_TO_IA
parameter_list|(
name|ifp
parameter_list|,
name|ia
parameter_list|)
define|\
comment|/* struct ifnet *ifp; */
define|\
comment|/* struct in_ifaddr *ia; */
define|\
value|{ \ 	for ((ia) = in_ifaddr; \ 	    (ia) != NULL&& (ia)->ia_ifp != (ifp); \ 	    (ia) = (ia)->ia_next) \ 		continue; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Internet multicast address structure.  There is one of these for each IP  * multicast group to which this host belongs on a given network interface.  * They are kept in a linked list, rooted in the interface's in_ifaddr  * structure.  */
end_comment

begin_struct
struct|struct
name|in_multi
block|{
name|struct
name|in_addr
name|inm_addr
decl_stmt|;
comment|/* IP multicast address */
name|struct
name|ifnet
modifier|*
name|inm_ifp
decl_stmt|;
comment|/* back pointer to ifnet */
name|struct
name|in_ifaddr
modifier|*
name|inm_ia
decl_stmt|;
comment|/* back pointer to in_ifaddr */
name|u_int
name|inm_refcount
decl_stmt|;
comment|/* no. membership claims by sockets */
name|u_int
name|inm_timer
decl_stmt|;
comment|/* IGMP membership report timer */
name|struct
name|in_multi
modifier|*
name|inm_next
decl_stmt|;
comment|/* ptr to next multicast address */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Structure used by macros below to remember position when stepping through  * all of the in_multi records.  */
end_comment

begin_struct
struct|struct
name|in_multistep
block|{
name|struct
name|in_ifaddr
modifier|*
name|i_ia
decl_stmt|;
name|struct
name|in_multi
modifier|*
name|i_inm
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macro for looking up the in_multi record for a given IP multicast address  * on a given interface.  If no matching record is found, "inm" returns NULL.  */
end_comment

begin_define
define|#
directive|define
name|IN_LOOKUP_MULTI
parameter_list|(
name|addr
parameter_list|,
name|ifp
parameter_list|,
name|inm
parameter_list|)
define|\
comment|/* struct in_addr addr; */
define|\
comment|/* struct ifnet *ifp; */
define|\
comment|/* struct in_multi *inm; */
define|\
value|{ \ 	register struct in_ifaddr *ia; \ \ 	IFP_TO_IA((ifp), ia); \ 	if (ia == NULL) \ 		(inm) = NULL; \ 	else \ 		for ((inm) = ia->ia_multiaddrs; \ 		    (inm) != NULL&& (inm)->inm_addr.s_addr != (addr).s_addr; \ 		     (inm) = inm->inm_next) \ 			 continue; \ }
end_define

begin_comment
comment|/*  * Macro to step through all of the in_multi records, one at a time.  * The current position is remembered in "step", which the caller must  * provide.  IN_FIRST_MULTI(), below, must be called to initialize "step"  * and get the first record.  Both macros return a NULL "inm" when there  * are no remaining records.  */
end_comment

begin_define
define|#
directive|define
name|IN_NEXT_MULTI
parameter_list|(
name|step
parameter_list|,
name|inm
parameter_list|)
define|\
comment|/* struct in_multistep  step; */
define|\
comment|/* struct in_multi *inm; */
define|\
value|{ \ 	if (((inm) = (step).i_inm) != NULL) \ 		(step).i_inm = (inm)->inm_next; \ 	else \ 		while ((step).i_ia != NULL) { \ 			(inm) = (step).i_ia->ia_multiaddrs; \ 			(step).i_ia = (step).i_ia->ia_next; \ 			if ((inm) != NULL) { \ 				(step).i_inm = (inm)->inm_next; \ 				break; \ 			} \ 		} \ }
end_define

begin_define
define|#
directive|define
name|IN_FIRST_MULTI
parameter_list|(
name|step
parameter_list|,
name|inm
parameter_list|)
define|\
comment|/* struct in_multistep step; */
define|\
comment|/* struct in_multi *inm; */
define|\
value|{ \ 	(step).i_ia = in_ifaddr; \ 	(step).i_inm = NULL; \ 	IN_NEXT_MULTI((step), (inm)); \ }
end_define

begin_decl_stmt
name|int
name|in_ifinit
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|in_ifaddr
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|in_multi
modifier|*
name|in_addmulti
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|*
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_delmulti
name|__P
argument_list|(
operator|(
expr|struct
name|in_multi
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in_ifscrub
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|in_ifaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_control
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

