begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	route.h	4.7	82/03/31	*/
end_comment

begin_comment
comment|/*  * Kernel resident routing tables.  *   * Each interface makes an entry at boot time so that  * correspondents directly addressible can be found.  * User programs can update this data base from information  * stored in the file system or information gleaned from  * routing protocol interactions with gateways.  *  * TODO:  *	keep statistics  *	smooth usage figures  */
end_comment

begin_struct
struct|struct
name|rtentry
block|{
name|u_long
name|rt_hash
decl_stmt|;
comment|/* for net or for host */
name|struct
name|sockaddr
name|rt_dst
decl_stmt|;
comment|/* match value */
name|struct
name|sockaddr
name|rt_gateway
decl_stmt|;
comment|/* who to forward to */
name|short
name|rt_flags
decl_stmt|;
comment|/* see below */
name|short
name|rt_refcnt
decl_stmt|;
comment|/* # held references */
name|u_long
name|rt_use
decl_stmt|;
comment|/* raw # packets forwarded */
name|struct
name|ifnet
modifier|*
name|rt_ifp
decl_stmt|;
comment|/* interface to use */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|route
block|{
name|struct
name|rtentry
modifier|*
name|ro_rt
decl_stmt|;
name|struct
name|sockaddr
name|ro_dst
decl_stmt|;
name|caddr_t
name|ro_pcb
decl_stmt|;
comment|/* back pointer? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags and host/network status.  */
end_comment

begin_define
define|#
directive|define
name|RTF_UP
value|0x1
end_define

begin_comment
comment|/* route useable */
end_comment

begin_define
define|#
directive|define
name|RTF_DIRECT
value|0x2
end_define

begin_comment
comment|/* destination is a neighbor */
end_comment

begin_define
define|#
directive|define
name|RTF_HOST
value|0x4
end_define

begin_comment
comment|/* host entry (net otherwise) */
end_comment

begin_define
define|#
directive|define
name|RTFREE
parameter_list|(
name|rt
parameter_list|)
define|\
value|if ((rt)->rt_refcnt == 1) \ 		rtfree(rt); \ 	else \ 		(rt)->rt_refcnt--;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Lookup are hashed by a key.  Each hash bucket  * consists of a linked list of mbuf's  * containing routing entries.  Dead entries are  * reclaimed along with mbufs.  */
end_comment

begin_define
define|#
directive|define
name|RTHASHSIZ
value|7
end_define

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|rthost
index|[
name|RTHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|rtnet
index|[
name|RTHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

