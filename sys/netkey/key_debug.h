begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * modified by Jun-ichiro itojun Itoh<itojun@itojun.org>, 1997  */
end_comment

begin_comment
comment|/*  * in6_debug.h  --  Insipired by Craig Metz's Net/2 in6_debug.h, but  *                  not quite as heavyweight (initially, anyway).  *  *                  In particular, if function exit-entries are to be  *                  documented, do them in a lightweight fashion.  *  * Copyright 1995 by Dan McDonald, Bao Phan, and Randall Atkinson,  *	All Rights Reserved.    *      All Rights under this copyright have been assigned to NRL.  */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------- #       @(#)COPYRIGHT   1.1a (NRL) 17 August 1995  COPYRIGHT NOTICE  All of the documentation and software included in this software distribution from the US Naval Research Laboratory (NRL) are copyrighted by their respective developers.  This software and documentation were developed at NRL by various people.  Those developers have each copyrighted the portions that they developed at NRL and have assigned All Rights for those portions to NRL.  Outside the USA, NRL also has copyright on the software developed at NRL. The affected files all contain specific copyright notices and those notices must be retained in any derived work.  NRL LICENSE  NRL grants permission for redistribution and use in source and binary forms, with or without modification, of the software and documentation created at NRL provided that the following conditions are met:  1. Redistributions of source code must retain the above copyright    notice, this list of conditions and the following disclaimer. 2. Redistributions in binary form must reproduce the above copyright    notice, this list of conditions and the following disclaimer in the    documentation and/or other materials provided with the distribution. 3. All advertising materials mentioning features or use of this software    must display the following acknowledgement:          This product includes software developed at the Information         Technology Division, US Naval Research Laboratory.  4. Neither the name of the NRL nor the names of its contributors    may be used to endorse or promote products derived from this software    without specific prior written permission.  THE SOFTWARE PROVIDED BY NRL IS PROVIDED BY NRL AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL NRL OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  The views and conclusions contained in the software and documentation are those of the authors and should not be interpreted as representing official policies, either expressed or implied, of the US Naval Research Laboratory (NRL).  ----------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* IDL_* is IPv6 Debug Level */
end_comment

begin_define
define|#
directive|define
name|IDL_ALL
value|0xFFFFFFFE
end_define

begin_comment
comment|/* Report all messages. */
end_comment

begin_define
define|#
directive|define
name|IDL_NONE
value|0
end_define

begin_comment
comment|/* Report no messages.  */
end_comment

begin_define
define|#
directive|define
name|IDL_CRITICAL
value|3
end_define

begin_define
define|#
directive|define
name|IDL_ERROR
value|7
end_define

begin_define
define|#
directive|define
name|IDL_MAJOR_EVENT
value|10
end_define

begin_define
define|#
directive|define
name|IDL_EVENT
value|15
end_define

begin_define
define|#
directive|define
name|IDL_GROSS_EVENT
value|20
end_define

begin_define
define|#
directive|define
name|IDL_FINISHED
value|0xFFFFFFF0
end_define

begin_comment
comment|/*  * Make sure argument for DPRINTF is in parentheses.  *  * For both DPRINTF and DDO, and attempt was made to make both macros  * be usable as normal C statments.  There is a small amount of compiler  * trickery (if-else clauses with effectively null statements), which may  * cause a few compilers to complain.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KEY_DEBUG
end_ifdef

begin_comment
comment|/*  * DPRINTF() is a general printf statement.  The "arg" is literally what  * would follow the function name printf, which means it has to be in  * parenthesis.  Unlimited arguments can be used this way.  *  * EXAMPLE:  *        DPRINTF(IDL_MAJOR_EVENT,("Hello, world.  IP version %d.\n",vers));  */
end_comment

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|lev
parameter_list|,
name|arg
parameter_list|)
value|if ((lev)< in6_debug_level) { \ 						      printf arg; \ 						      } \                          else in6_debug_level = in6_debug_level
end_define

begin_comment
comment|/*  * DDO() executes a series of statements at a certain debug level.  The  * "stmt" argument is a statement in the sense of a "statement list" in a  * C grammar.  "stmt" does not have to end with a semicolon.  *  * EXAMPLE:  *        DDO(IDL_CRITICAL,dump_ipv6(header), dump_inpcb(inp));  */
end_comment

begin_define
define|#
directive|define
name|DDO
parameter_list|(
name|lev
parameter_list|,
name|stmt
parameter_list|)
value|if ((lev)< in6_debug_level) { stmt ; } \                        else in6_debug_level = in6_debug_level
end_define

begin_comment
comment|/*  * DP() is a shortcut for DPRINTF().  Basically:  *  *        DP(lev, var, fmt)   ==   DPRINTF(IDL_lev, ("var = %fmt\n", var))  *  * It is handy for printing single variables without a lot of typing.  *  * EXAMPLE:  *  *        DP(CRITICAL,length,d);  * same as DPRINTF(IDL_CRITICAL, ("length = %d\n", length))  */
end_comment

begin_define
define|#
directive|define
name|DP
parameter_list|(
name|lev
parameter_list|,
name|var
parameter_list|,
name|fmt
parameter_list|)
value|DPRINTF(IDL_ ## lev, (#var " = %" #fmt "\n", var))
end_define

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|void
name|in6_debug_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dump_in6_addr
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|dump_in_addr
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dump_sockaddr_in6
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|dump_sockaddr_in
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

begin_decl_stmt
specifier|extern
name|void
name|dump_sockaddr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_sockaddr_dl
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_dl
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_smart_sockaddr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dump_ipv6
name|__P
argument_list|(
operator|(
expr|struct
name|ip6
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_ipv6_icmp
name|__P
argument_list|(
operator|(
expr|struct
name|icmp6
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*INET6*/
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dump_mbuf_hdr
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_mbuf
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_mchain
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_tcpdump
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_ifa
name|__P
argument_list|(
operator|(
expr|struct
name|ifaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_ifp
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_route
name|__P
argument_list|(
operator|(
expr|struct
name|route
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_rtentry
name|__P
argument_list|(
operator|(
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_inpcb
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dump_in6pcb
name|__P
argument_list|(
operator|(
expr|struct
name|in6pcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|dump_buf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_keytblnode
name|__P
argument_list|(
operator|(
expr|struct
name|key_tblnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_secassoc
name|__P
argument_list|(
operator|(
expr|struct
name|key_secassoc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_keymsghdr
name|__P
argument_list|(
operator|(
expr|struct
name|key_msghdr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_keymsginfo
name|__P
argument_list|(
operator|(
expr|struct
name|key_msgdata
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! KEY_DEBUG */
end_comment

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|lev
parameter_list|,
name|arg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DDO
parameter_list|(
name|lev
parameter_list|,
name|stmt
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KEY_DEBUG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INET6_DEBUG_C
end_ifndef

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|in6_debug_level
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*KERNEL*/
end_comment

end_unit

