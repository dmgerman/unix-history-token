begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)in_var.h 1.3 88/08/19 SMI; from UCB 7.1 6/5/86	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1985, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/*  * Interface address, Internet version.  One of these structures  * is allocated for each interface with an Internet address.  * The ifaddr structure contains the protocol-independent part  * of the structure and is assumed to be first.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_netinet_in_var_h
end_ifndef

begin_define
define|#
directive|define
name|_netinet_in_var_h
end_define

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
name|ia_addr
value|ia_ifa.ifa_addr
define|#
directive|define
name|ia_broadaddr
value|ia_ifa.ifa_broadaddr
define|#
directive|define
name|ia_dstaddr
value|ia_ifa.ifa_dstaddr
define|#
directive|define
name|ia_ifp
value|ia_ifa.ifa_ifp
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
comment|/* mask of net + subnet */
name|struct
name|in_addr
name|ia_netbroadcast
decl_stmt|;
comment|/* broadcast addr for (logical) net */
name|int
name|ia_flags
decl_stmt|;
name|struct
name|in_ifaddr
modifier|*
name|ia_next
decl_stmt|;
comment|/* next in list of internet addresses */
name|struct
name|in_multi
modifier|*
name|ia_multiaddrs
decl_stmt|;
comment|/* list of multicast addresses */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Given a pointer to an in_ifaddr (ifaddr),  * return a pointer to the addr as a sockadd_in.  */
end_comment

begin_define
define|#
directive|define
name|IA_SIN
parameter_list|(
name|ia
parameter_list|)
value|((struct sockaddr_in *)(&((struct in_ifaddr *)ia)->ia_addr))
end_define

begin_comment
comment|/*  * ia_flags  */
end_comment

begin_define
define|#
directive|define
name|IFA_ROUTE
value|0x01
end_define

begin_comment
comment|/* routing entry installed */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|in_ifaddr
modifier|*
name|in_ifaddr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|in_ifaddr
modifier|*
name|in_iaonnetof
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|ifqueue
name|ipintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip packet input queue */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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
comment|/* struct ifnet  *ifp;  */
define|\
value|{									  \ 	register struct in_ifaddr *ia;					  \ 									  \ 	for (ia = in_ifaddr;						  \ 	     ia != NULL&& IA_SIN(ia)->sin_addr.s_addr != (addr).s_addr;  \ 	     ia = ia->ia_next);						  \ 	(ifp) = (ia == NULL) ? NULL : ia->ia_ifp;			  \ }
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
comment|/* struct ifnet     *ifp; */
define|\
comment|/* struct in_ifaddr *ia;  */
define|\
value|{									  \ 	for ((ia) = in_ifaddr;						  \ 	     (ia) != NULL&& (ia)->ia_ifp != (ifp);			  \ 	     (ia) = (ia)->ia_next);					  \ }
end_define

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

begin_comment
comment|/*  * Per-interface router version information is kept in this list.  * This information should be part of the ifnet structure but we don't wish  * to change that - as it might break a number of things  */
end_comment

begin_struct
struct|struct
name|router_info
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* type of router which is querier on this interface */
name|int
name|time
decl_stmt|;
comment|/* # of slow timeouts since last old query */
name|struct
name|router_info
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* IP multicast address             */
name|struct
name|ifnet
modifier|*
name|inm_ifp
decl_stmt|;
comment|/* back pointer to ifnet            */
name|struct
name|in_ifaddr
modifier|*
name|inm_ia
decl_stmt|;
comment|/* back pointer to in_ifaddr        */
name|u_int
name|inm_refcount
decl_stmt|;
comment|/* no. membership claims by sockets */
name|u_int
name|inm_timer
decl_stmt|;
comment|/* IGMP membership report timer     */
name|struct
name|in_multi
modifier|*
name|inm_next
decl_stmt|;
comment|/* ptr to next multicast address    */
name|u_int
name|inm_state
decl_stmt|;
comment|/*  state of the membership */
name|struct
name|router_info
modifier|*
name|inm_rti
decl_stmt|;
comment|/* router info*/
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
comment|/* struct in_addr  addr; */
define|\
comment|/* struct ifnet    *ifp; */
define|\
comment|/* struct in_multi *inm; */
define|\
value|{									    \ 	register struct in_ifaddr *ia;					    \ 									    \ 	IFP_TO_IA((ifp), ia);						    \ 	if (ia == NULL)							    \ 		(inm) = NULL;						    \ 	else								    \ 	    for ((inm) = ia->ia_multiaddrs;				    \ 		 (inm) != NULL&& (inm)->inm_addr.s_addr != (addr).s_addr;  \ 		 (inm) = inm->inm_next);				    \ }
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
comment|/* struct in_multi     *inm;  */
define|\
value|{									\ 	if (((inm) = (step).i_inm) != NULL) {				\ 		(step).i_inm = (inm)->inm_next;				\ 	}								\ 	else while ((step).i_ia != NULL) {				\ 		(inm) = (step).i_ia->ia_multiaddrs;			\ 		(step).i_ia = (step).i_ia->ia_next;			\ 		if ((inm) != NULL) {					\ 			(step).i_inm = (inm)->inm_next;			\ 			break;						\ 		}							\ 	}								\ }
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
comment|/* struct in_multistep  step; */
define|\
comment|/* struct in_multi     *inm;  */
define|\
value|{									\ 	(step).i_ia  = in_ifaddr;					\ 	(step).i_inm = NULL;						\ 	IN_NEXT_MULTI((step), (inm));					\ }
end_define

begin_function_decl
name|struct
name|in_multi
modifier|*
name|in_addmulti
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!_netinet_in_var_h*/
end_comment

end_unit

