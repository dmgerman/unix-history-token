begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)in_var.h	8.2 (Berkeley) 1/9/95  *	$Id: in_var.h,v 1.12 1995/11/14 20:34:07 phk Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IN_VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

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
name|LIST_HEAD
argument_list|(
argument|in_multihead
argument_list|,
argument|in_multi
argument_list|)
name|ia_multiaddrs
expr_stmt|;
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
name|IA_DSTSIN
parameter_list|(
name|ia
parameter_list|)
value|(&(((struct in_ifaddr *)(ia))->ia_dstaddr))
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
specifier|extern
name|struct
name|in_addr
name|zeroin_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|inetctlerrmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rtq_reallyold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rtq_minreallyold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rtq_toomany
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

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
value|{ \ 	register struct in_ifaddr *ia; \ \ 	for (ia = in_ifaddr; \ 	    ia != NULL&& ((ia->ia_ifp->if_flags& IFF_POINTOPOINT)? \ 		IA_DSTSIN(ia):IA_SIN(ia))->sin_addr.s_addr != (addr).s_addr; \ 	    ia = ia->ia_next) \ 		 continue; \ 	(ifp) = (ia == NULL) ? NULL : ia->ia_ifp; \ }
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
comment|/*  * This information should be part of the ifnet structure but we don't wish  * to change that - as it might break a number of things  */
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
name|LIST_ENTRY
argument_list|(
argument|in_multi
argument_list|)
name|inm_entry
expr_stmt|;
comment|/* list glue */
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
comment|/* struct in_addr addr; */
define|\
comment|/* struct ifnet *ifp; */
define|\
comment|/* struct in_multi *inm; */
define|\
value|{ \ 	register struct in_ifaddr *ia; \ \ 	IFP_TO_IA((ifp), ia); \ 	if (ia == NULL) \ 		(inm) = NULL; \ 	else \ 		for ((inm) = ia->ia_multiaddrs.lh_first; \ 		    (inm) != NULL&& (inm)->inm_addr.s_addr != (addr).s_addr; \ 		     (inm) = inm->inm_entry.le_next) \ 			 continue; \ }
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
value|{ \ 	if (((inm) = (step).i_inm) != NULL) \ 		(step).i_inm = (inm)->inm_entry.le_next; \ 	else \ 		while ((step).i_ia != NULL) { \ 			(inm) = (step).i_ia->ia_multiaddrs.lh_first; \ 			(step).i_ia = (step).i_ia->ia_next; \ 			if ((inm) != NULL) { \ 				(step).i_inm = (inm)->inm_entry.le_next; \ 				break; \ 			} \ 		} \ }
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
name|void
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

begin_decl_stmt
name|void
name|in_rtqdrain
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IN_VAR_H_ */
end_comment

end_unit

