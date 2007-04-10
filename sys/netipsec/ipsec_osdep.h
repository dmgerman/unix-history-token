begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NetBSD: ipsec_osdep.h,v 1.1 2003/08/13 20:06:51 jonathan Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003 Jonathan Stone (jonathan@cs.stanford.edu)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETIPSEC_OSDEP_H
end_ifndef

begin_define
define|#
directive|define
name|NETIPSEC_OSDEP_H
end_define

begin_comment
comment|/*   *  Hide porting differences across different 4.4BSD-derived platforms.  *   * 1.  KASSERT() differences:   * 2.  Kernel  Random-number API differences.  * 3.  Is packet data in an mbuf object writeable?  * 4.  Packet-header semantics.  * 5.  Fast mbuf-cluster allocation.  * 6.  Network packet-output macros.  * 7.  Elased time, in seconds.  * 8.  Test if a  socket object opened by  a privileged (super) user.  * 9.  Global SLIST of all open raw sockets.  * 10. Global SLIST of known interface addresses.  */
end_comment

begin_comment
comment|/*  *  1. KASSERT and spl differences   *  * FreeBSD takes an expression and  parenthesized printf() argument-list.  * NetBSD takes one arg: the expression being asserted.  * FreeBSD's SPLASSERT() takes an SPL level as 1st arg and a  * parenthesized printf-format argument list as the second argument.  *  * This difference is hidden by two 2-argument macros and one 1-arg macro:  *    IPSEC_ASSERT(expr, msg)  *    IPSEC_SPLASSERT(spl, msg)  * One further difference is the spl names:  *    NetBSD splsoftnet equates to FreeBSD splnet;  *    NetBSD splnet equates to FreeBSD splimp.  * which is hidden by the macro IPSEC_SPLASSERT_SOFTNET(msg).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_define
define|#
directive|define
name|IPSEC_SPLASSERT
parameter_list|(
name|_x
parameter_list|,
name|_y
parameter_list|)
value|SPLASSERT(_x, _y)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPSEC_SPLASSERT
parameter_list|(
name|_x
parameter_list|,
name|_y
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPSEC_SPLASSERT_SOFTNET
parameter_list|(
name|_m
parameter_list|)
value|IPSEC_SPLASSERT(net,_m)
end_define

begin_define
define|#
directive|define
name|IPSEC_ASSERT
parameter_list|(
name|_c
parameter_list|,
name|_m
parameter_list|)
value|KASSERT(_c, _m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|IPSEC_SPLASSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|IPSEC_ASSERT
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
value|KASSERT(c)
end_define

begin_define
define|#
directive|define
name|IPSEC_SPLASSERT_SOFTNET
parameter_list|(
name|m
parameter_list|)
value|IPSEC_SPLASSERT(softnet, m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/*  * 2. Kernel Randomness API.  * FreeBSD uses:  *    u_int read_random(void *outbuf, int nbytes).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_comment
comment|/* do nothing, use native random code. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/rnd.h>
end_include

begin_function_decl
specifier|static
name|__inline
name|u_int
name|read_random
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|u_int
name|read_random
parameter_list|(
name|void
modifier|*
name|bufp
parameter_list|,
name|u_int
name|len
parameter_list|)
block|{
return|return
name|rnd_extract_data
argument_list|(
name|bufp
argument_list|,
name|len
argument_list|,
name|RND_EXTRACT_ANY
comment|/*XXX FIXME */
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/*  * 3. Test for mbuf mutability  * FreeBSD 4.x uses: M_EXT_WRITABLE  * NetBSD has M_READONLY(). Use !M_READONLY().  * Not an exact match to FreeBSD semantics, but adequate for IPsec purposes.  *   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_comment
comment|/* XXX wrong, but close enough for restricted ipsec usage. */
end_comment

begin_define
define|#
directive|define
name|M_EXT_WRITABLE
parameter_list|(
name|m
parameter_list|)
value|(!M_READONLY(m))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/*  * 4. mbuf packet-header/packet-tag semantics.  * Sam Leffler explains, in private email, some problems with  * M_COPY_PKTHDR(), and why FreeBSD deprecated it and replaced it  * with new, explicit macros M_MOVE_PKTHDR()/M_DUP_PKTHDR().  * he original fast-ipsec source uses M_MOVE_PKTHDR.  * NetBSD currently still uses M_COPY_PKTHDR(), so we define  * M_MOVE_PKTHDR in terms of M_COPY_PKTHDR().  Fast-IPsec  * will delete the source mbuf shortly after copying packet tags,  * so we are safe for fast-ipsec but not in general..  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|M_MOVE_PKTHDR
parameter_list|(
name|_f
parameter_list|,
name|_t
parameter_list|)
value|M_COPY_PKTHDR(_f, _t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/*  * 5. Fast mbuf-cluster allocation.  * FreeBSD 4.6 introduce m_getcl(), which performs `fast' allocation  * mbuf clusters from a cache of recently-freed clusters. (If the  cache  * is empty, new clusters are allocated en-masse).  *   On NetBSD, for now, implement the `cache' as an inline  function  *using normal NetBSD mbuf/cluster allocation macros. Replace this  * with fast-cache code, if and when netBSD  implements one.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_getcl
argument_list|(
argument|int how
argument_list|,
argument|short type
argument_list|,
argument|int flags
argument_list|)
block|{ 	struct
name|mbuf
operator|*
name|mp
block|;
if|if
condition|(
name|flags
operator|&
name|M_PKTHDR
condition|)
name|MGETHDR
argument_list|(
name|mp
argument_list|,
name|how
argument_list|,
name|type
argument_list|)
expr_stmt|;
else|else
name|MGET
argument_list|(
name|mp
argument_list|,
name|how
argument_list|,
name|type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|mp
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
end_if

begin_expr_stmt
name|MCLGET
argument_list|(
name|mp
argument_list|,
name|how
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|mp
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/*  * 6. Network output macros  * FreeBSD uses the  IF_HANDOFF(), which raises SPL, enqueues  * a packet, and updates interface counters. NetBSD has IFQ_ENQUE(),  * which leaves SPL changes up to the caller.   * For now, we provide an emulation of IF_HANOOFF() which works  * for protocol input queues.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/* nothing to do */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|IF_HANDOFF
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|,
name|f
parameter_list|)
value|if_handoff(ifq, m, f, 0)
end_define

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_function
unit|static
name|__inline
name|int
name|if_handoff
parameter_list|(
name|struct
name|ifqueue
modifier|*
name|ifq
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
name|adjust
parameter_list|)
block|{
name|int
name|need_if_start
init|=
literal|0
decl_stmt|;
name|int
name|s
init|=
name|splnet
argument_list|()
decl_stmt|;
if|if
condition|(
name|IF_QFULL
argument_list|(
name|ifq
argument_list|)
condition|)
block|{
name|IF_DROP
argument_list|(
name|ifq
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|ifp
operator|!=
name|NULL
condition|)
block|{
name|ifp
operator|->
name|if_obytes
operator|+=
name|m
operator|->
name|m_pkthdr
operator|.
name|len
operator|+
name|adjust
expr_stmt|;
if|if
condition|(
name|m
operator|->
name|m_flags
operator|&
name|M_MCAST
condition|)
name|ifp
operator|->
name|if_omcasts
operator|++
expr_stmt|;
name|need_if_start
operator|=
operator|!
operator|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_OACTIVE
operator|)
expr_stmt|;
block|}
name|IF_ENQUEUE
argument_list|(
name|ifq
argument_list|,
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|need_if_start
condition|)
call|(
modifier|*
name|ifp
operator|->
name|if_start
call|)
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/*  * 7. Elapsed Time: time_second as time in seconds.  * Original FreeBSD fast-ipsec code references a FreeBSD kernel global,  * time_second().  NetBSD: kludge #define to use time_mono_time.tv_sec.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_define
define|#
directive|define
name|time_second
value|mono_time.tv_sec
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/* protosw glue */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_define
define|#
directive|define
name|ipprotosw
value|protosw
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/*  * 8. Test for "privileged" socket opened by superuser.  * FreeBSD tests  ((so)->so_cred != NULL&& priv_check_cred((so)->so_cred,  * PRIV_NETINET_IPSEC, SUSER_ALLOWJAIL) == 0).  * NetBSD (1.6N) tests (so)->so_uid == 0).  * This difference is wrapped inside  the IPSEC_PRIVILEGED_SO() macro.  *  * XXXRW: Why was this suser_allowjail?  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|IPSEC_IS_PRIVILEGED_SO
parameter_list|(
name|_so
parameter_list|)
define|\
value|((_so)->so_cred != NULL&& \ 	 priv_check_cred((_so)->so_cred, PRIV_NETINET_IPSEC, 0) \ 	 == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_comment
comment|/* superuser opened socket? */
end_comment

begin_define
define|#
directive|define
name|IPSEC_IS_PRIVILEGED_SO
parameter_list|(
name|so
parameter_list|)
value|((so)->so_uid == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/*  * 9. Raw socket list  * FreeBSD uses: listhead = rawcb_list, SLIST()-next field "list".  * NetBSD  uses: listhead = rawcb, SLIST()-next field "list"  *  * This version of fast-ipsec source code  uses rawcb_list as the head,  *  and (to avoid namespace collisions) uses rcb_list as the "next" field.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|rcb_list
value|list
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|rawcb_list
value|rawcb
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/*  * 10. List of all known network interfaces.  * FreeBSD has listhead in_ifaddread, with ia_link as link.  * NetBSD has listhead in_ifaddr, with ia_list as link.  * No name-clahses, so just #define the appropriate names on NetBSD.  * NB: Is it worth introducing iterator (find-first-list/find-next-list)  * functions or macros to encapsulate these?  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/* nothing to do for raw interface list */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FreeBSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_comment
comment|/* For now, use FreeBSD-compatible names for raw interface list. */
end_comment

begin_define
define|#
directive|define
name|in_ifaddrhead
value|in_ifaddr
end_define

begin_define
define|#
directive|define
name|ia_link
value|ia_list
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/*  * Differences that we don't attempt to hide:  *  * A. Initialization code.  This  is the largest difference of all.  *  *   FreeBSD uses compile/link-time perl hackery to generate special   * .o files  with linker sections  that give the moral equivalent of  * C++ file-level-object constructors. NetBSD has no such facility.  *  * Either we implement it (ideally, in a way that can emulate  * FreeBSD's SYSINIT() macros), or we must take other means  * to have the per-file init functions called at some appropriate time.  *  * In the absence of SYSINIT(), all the file-level init functions  * now have "extern" linkage. There is a new fast-ipsec init()  * function which calls each of the per-file in an appropriate order.   * init_main will arrange to call the fast-ipsec init function  * after the crypto framework has registered its transforms (including  * any autoconfigured hardware crypto  accelerators) but before  * initializing the network stack to send or receive  packet.  *  * B. Protosw() differences.   * CSRG-style BSD TCP/IP uses a generic protocol-dispatch-function  * where the specific request is identified by an enum argument.  * FreeBSD replaced that with an array of request-specific  * function pointers.  *  * These differences affect the handlers for key-protocol user requests  * so pervasively that I gave up on the fast-ipsec code, and re-worked the  * NetBSD KAME code to match the (relative few) API differences  * between NetBSD and FreeBSD's KAME netkey, and Fast-IPsec netkey.  *  * C. Timeout() versus callout(9):  * The FreeBSD 4.x netipsec/ code still uses timeout().  * FreeBSD 4.7 has callout(9), so I just replaced   * timeout_*() with the nearest callout_*() equivalents,  * and added a callout handle to the ipsec context.  *  * D. SPL name differences.  * FreeBSD splnet() equates directly to NetBSD's splsoftnet();  * FreeBSD uses splimp() where (for networking) NetBSD would use splnet().  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETIPSEC_OSDEP_H */
end_comment

end_unit

