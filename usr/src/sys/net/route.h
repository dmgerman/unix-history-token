begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	route.h	4.2	82/03/28	*/
end_comment

begin_comment
comment|/*  * Structure of kernel resident routing  * data base.  Assumption is user routing  * daemon maintains this data base based  * on routing information it gleans from  * gateway protocols it listens to (e.g. GGP).  *  * TO ADD:  *	more statistics -- smooth usage figures  */
end_comment

begin_struct
struct|struct
name|rtentry
block|{
name|u_long
name|rt_key
decl_stmt|;
comment|/* lookup key */
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
name|RTF_MUNGE
value|0x2
end_define

begin_comment
comment|/* munge packet src address */
end_comment

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
value|16
end_define

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|routehash
index|[
name|RTHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|rtentry
modifier|*
name|reroute
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

