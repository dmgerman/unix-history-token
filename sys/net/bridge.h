begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2002 Luigi Rizzo  *  * Work partly supported by: Cisco Systems, Inc. - NSITE lab, RTP, NC  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|do_bridge
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * We need additional per-interface info for the bridge, which is  * stored in a struct bdg_softc. The ifp2sc[] array provides a pointer  * to this struct using the if_index as a mapping key.  * bdg_softc has a backpointer to the struct ifnet, the bridge  * flags, and a cluster (bridging occurs only between port of the  * same cluster).  */
end_comment

begin_struct_decl
struct_decl|struct
name|cluster_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/* opaque here, defined in bridge.c */
end_comment

begin_struct
struct|struct
name|bdg_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* also ((struct arpcom *)ifp)->ac_enaddr is the eth. addr */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|IFF_BDG_PROMISC
value|0x0001
comment|/* set promisc mode on this if.	*/
define|#
directive|define
name|IFF_MUTE
value|0x0002
comment|/* mute this if for bridging.   */
define|#
directive|define
name|IFF_USED
value|0x0004
comment|/* use this if for bridging.    */
name|struct
name|cluster_softc
modifier|*
name|cluster
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|bdg_softc
modifier|*
name|ifp2sc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BDG_USED
parameter_list|(
name|ifp
parameter_list|)
value|(ifp2sc[ifp->if_index].flags& IFF_USED)
end_define

begin_comment
comment|/*  * BDG_ACTIVE(ifp) does all checks to see if bridging is enabled, loaded,  * and used on a given interface.  */
end_comment

begin_define
define|#
directive|define
name|BDG_ACTIVE
parameter_list|(
name|ifp
parameter_list|)
value|(do_bridge&& BDG_LOADED&& BDG_USED(ifp))
end_define

begin_comment
comment|/*  * The following constants are not legal ifnet pointers, and are used  * as return values from the classifier, bridge_dst_lookup().  * The same values are used as index in the statistics arrays,  * with BDG_FORWARD replacing specifically forwarded packets.  *  * These constants are here because they are used in 'netstat'  * to show bridge statistics.  */
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

begin_comment
comment|/*  * Statistics are passed up with the sysctl interface, "netstat -p bdg"  * reads them. PF_BDG defines the 'bridge' protocol family.  */
end_comment

begin_define
define|#
directive|define
name|PF_BDG
value|3
end_define

begin_comment
comment|/* XXX superhack */
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

begin_comment
comment|/* XXX this should be made dynamic */
end_comment

begin_define
define|#
directive|define
name|BDG_MAX_PORTS
value|128
end_define

begin_struct
struct|struct
name|bdg_stats
block|{
name|struct
name|bdg_port_stat
name|s
index|[
name|BDG_MAX_PORTS
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
value|bdg_stats.s[ifp->if_index].p_in[(uintptr_t)type]++
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|ifnet
modifier|*
name|bridge_in_t
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ether_header
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* bdg_forward frees the mbuf if necessary, returning null */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mbuf
modifier|*
name|bdg_forward_t
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ether_header
modifier|*
specifier|const
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|bdgtakeifaces_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|bridge_in_t
modifier|*
name|bridge_in_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bdg_forward_t
modifier|*
name|bdg_forward_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bdgtakeifaces_t
modifier|*
name|bdgtakeifaces_ptr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BDG_LOADED
value|(bdgtakeifaces_ptr != NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

