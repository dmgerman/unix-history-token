begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998,1999 Luigi Rizzo  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|do_bridge
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * the hash table for bridge  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hash_table
block|{
name|struct
name|ifnet
modifier|*
name|name
decl_stmt|;
name|unsigned
name|char
name|etheraddr
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|short
name|used
decl_stmt|;
block|}
name|bdg_hash_table
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|bdg_hash_table
modifier|*
name|bdg_table
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BDG_MAX_PORTS
value|128
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|bdg_addresses
index|[
literal|6
operator|*
name|BDG_MAX_PORTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bdg_ports
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * out of the 6 bytes, the last ones are more "variable". Since  * we are on a little endian machine, we have to do some gimmick...  */
end_comment

begin_define
define|#
directive|define
name|HASH_SIZE
value|8192
end_define

begin_comment
comment|/* must be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|HASH_FN
parameter_list|(
name|addr
parameter_list|)
value|(	\ 	ntohs( ((short *)addr)[1] ^ ((short *)addr)[2] )& (HASH_SIZE -1))
end_define

begin_function_decl
name|struct
name|ifnet
modifier|*
name|bridge_in
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* bdg_forward frees the mbuf if necessary, returning null */
end_comment

begin_function_decl
name|int
name|bdg_forward
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
name|m
parameter_list|,
name|struct
name|ifnet
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|BDG_MATCH
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|( \     ((unsigned short *)(a))[2] == ((unsigned short *)(b))[2]&& \     *((unsigned int *)(a)) == *((unsigned int *)(b)) )
end_define

begin_define
define|#
directive|define
name|IS_ETHER_BROADCAST
parameter_list|(
name|a
parameter_list|)
value|( \ 	*((unsigned int *)(a)) == 0xffffffff&& \ 	((unsigned short *)(a))[2] == 0xffff )
end_define

begin_else
else|#
directive|else
end_else

begin_warning
warning|#
directive|warning
warning|... must complete these for the alpha etc.
end_warning

begin_define
define|#
directive|define
name|BDG_MATCH
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(!bcmp(a, b, ETHER_ADDR_LEN) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following constants are not legal ifnet pointers, and are used  * as return values from the classifier, bridge_dst_lookup()  * The same values are used as index in the statistics arrays,  * with BDG_FORWARD replacing specifically forwarded packets.  */
end_comment

begin_define
define|#
directive|define
name|BDG_BCAST
value|( (struct ifnet *)1 )
end_define

begin_define
define|#
directive|define
name|BDG_MCAST
value|( (struct ifnet *)2 )
end_define

begin_define
define|#
directive|define
name|BDG_LOCAL
value|( (struct ifnet *)3 )
end_define

begin_define
define|#
directive|define
name|BDG_DROP
value|( (struct ifnet *)4 )
end_define

begin_define
define|#
directive|define
name|BDG_UNKNOWN
value|( (struct ifnet *)5 )
end_define

begin_define
define|#
directive|define
name|BDG_IN
value|( (struct ifnet *)7 )
end_define

begin_define
define|#
directive|define
name|BDG_OUT
value|( (struct ifnet *)8 )
end_define

begin_define
define|#
directive|define
name|BDG_FORWARD
value|( (struct ifnet *)9 )
end_define

begin_define
define|#
directive|define
name|PF_BDG
value|3
end_define

begin_comment
comment|/* XXX superhack */
end_comment

begin_comment
comment|/*  * statistics, passed up with sysctl interface and ns -p bdg  */
end_comment

begin_define
define|#
directive|define
name|STAT_MAX
value|(int)BDG_FORWARD
end_define

begin_struct
struct|struct
name|bdg_port_stat
block|{
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
name|u_long
name|collisions
decl_stmt|;
name|u_long
name|p_in
index|[
name|STAT_MAX
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bdg_stats
block|{
name|struct
name|bdg_port_stat
name|s
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BDG_STAT
parameter_list|(
name|ifp
parameter_list|,
name|type
parameter_list|)
value|bdg_stats.s[ifp->if_index].p_in[(int)type]++
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Find the right pkt destination:  *	BDG_BCAST	is a broadcast  *	BDG_MCAST	is a multicast  *	BDG_LOCAL	is for a local address  *	BDG_DROP	must be dropped  *	other		ifp of the dest. interface (incl.self)  */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|ifnet
operator|*
name|bridge_dst_lookup
argument_list|(
argument|struct mbuf *m
argument_list|)
block|{     struct
name|ether_header
operator|*
name|eh
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
expr|struct
name|ether_header
operator|*
argument_list|)
block|;     struct
name|ifnet
operator|*
name|dst
block|;
name|int
name|index
block|;
name|u_char
operator|*
name|eth_addr
operator|=
name|bdg_addresses
block|;
if|if
condition|(
name|IS_ETHER_BROADCAST
argument_list|(
name|eh
operator|->
name|ether_dhost
argument_list|)
condition|)
return|return
name|BDG_BCAST
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|eh
operator|->
name|ether_dhost
index|[
literal|0
index|]
operator|&
literal|1
condition|)
return|return
name|BDG_MCAST
return|;
end_if

begin_comment
comment|/*      * Lookup local addresses in case one matches.      */
end_comment

begin_for
for|for
control|(
name|index
operator|=
name|bdg_ports
operator|,
name|eth_addr
operator|=
name|bdg_addresses
init|;
name|index
condition|;
name|index
operator|--
operator|,
name|eth_addr
operator|+=
literal|6
control|)
if|if
condition|(
name|BDG_MATCH
argument_list|(
name|eth_addr
argument_list|,
name|eh
operator|->
name|ether_dhost
argument_list|)
condition|)
return|return
name|BDG_LOCAL
return|;
end_for

begin_comment
comment|/*      * Look for a possible destination in table      */
end_comment

begin_expr_stmt
name|index
operator|=
name|HASH_FN
argument_list|(
name|eh
operator|->
name|ether_dhost
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dst
operator|=
name|bdg_table
index|[
name|index
index|]
operator|.
name|name
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|dst
operator|&&
name|BDG_MATCH
argument_list|(
name|bdg_table
index|[
name|index
index|]
operator|.
name|etheraddr
argument_list|,
name|eh
operator|->
name|ether_dhost
argument_list|)
condition|)
return|return
name|dst
return|;
else|else
return|return
name|BDG_UNKNOWN
return|;
end_if

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

