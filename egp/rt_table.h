begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	rt_table.h  */
end_comment

begin_comment
comment|/* EGP User Process, ISI 23-Jun-84 */
end_comment

begin_comment
comment|/*  * Modified from Routing table management daemon. table.h  */
end_comment

begin_comment
comment|/*  * Routing table structure; differs a bit from kernel tables.  *  * Note: the union below must agree in the first 4 members  * so the ioctl's will work.  */
end_comment

begin_struct
struct|struct
name|rthash
block|{
name|struct
name|rt_entry
modifier|*
name|rt_forw
decl_stmt|;
name|struct
name|rt_entry
modifier|*
name|rt_back
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rt_entry
block|{
name|struct
name|rt_entry
modifier|*
name|rt_forw
decl_stmt|;
name|struct
name|rt_entry
modifier|*
name|rt_back
decl_stmt|;
union|union
block|{
name|struct
name|rtentry
name|rtu_rt
decl_stmt|;
struct|struct
block|{
name|u_long
name|rtu_hash
decl_stmt|;
name|struct
name|sockaddr
name|rtu_dst
decl_stmt|;
name|struct
name|sockaddr
name|rtu_router
decl_stmt|;
name|short
name|rtu_flags
decl_stmt|;
name|short
name|rtu_state
decl_stmt|;
name|int
name|rtu_timer
decl_stmt|;
name|int
name|rtu_metric
decl_stmt|;
name|struct
name|interface
modifier|*
name|rtu_ifp
decl_stmt|;
block|}
name|rtu_entry
struct|;
block|}
name|rt_rtu
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rt_rt
value|rt_rtu.rtu_rt
end_define

begin_comment
comment|/* pass to ioctl */
end_comment

begin_define
define|#
directive|define
name|rt_hash
value|rt_rtu.rtu_entry.rtu_hash
end_define

begin_comment
comment|/* for net or host */
end_comment

begin_define
define|#
directive|define
name|rt_dst
value|rt_rtu.rtu_entry.rtu_dst
end_define

begin_comment
comment|/* match value */
end_comment

begin_define
define|#
directive|define
name|rt_router
value|rt_rtu.rtu_entry.rtu_router
end_define

begin_comment
comment|/* who to forward to*/
end_comment

begin_define
define|#
directive|define
name|rt_flags
value|rt_rtu.rtu_entry.rtu_flags
end_define

begin_comment
comment|/* kernel flags */
end_comment

begin_define
define|#
directive|define
name|rt_timer
value|rt_rtu.rtu_entry.rtu_timer
end_define

begin_comment
comment|/* for invalidation */
end_comment

begin_define
define|#
directive|define
name|rt_state
value|rt_rtu.rtu_entry.rtu_state
end_define

begin_comment
comment|/* see below */
end_comment

begin_define
define|#
directive|define
name|rt_metric
value|rt_rtu.rtu_entry.rtu_metric
end_define

begin_comment
comment|/* cost of route */
end_comment

begin_define
define|#
directive|define
name|rt_ifp
value|rt_rtu.rtu_entry.rtu_ifp
end_define

begin_comment
comment|/* interface to take*/
end_comment

begin_define
define|#
directive|define
name|ROUTEHASHSIZ
value|19
end_define

begin_comment
comment|/*  * "State" of routing table entry.  */
end_comment

begin_define
define|#
directive|define
name|RTS_CHANGED
value|0x1
end_define

begin_comment
comment|/* route has been altered recently */
end_comment

begin_define
define|#
directive|define
name|RTS_PASSIVE
value|0x20
end_define

begin_comment
comment|/* don't time out route */
end_comment

begin_define
define|#
directive|define
name|RTS_INTERFACE
value|0x40
end_define

begin_comment
comment|/* route is for network interface */
end_comment

begin_define
define|#
directive|define
name|RTS_REMOTE
value|0x80
end_define

begin_comment
comment|/*not used	/* route is for ``remote'' entity */
end_comment

begin_define
define|#
directive|define
name|RTS_NOTINSTALL
value|0x100
end_define

begin_comment
comment|/* don't install this route in the 					 * kernel as an interior route is 					 * available and preferred 					 */
end_comment

begin_define
define|#
directive|define
name|RTS_NOTADVISENR
value|0x200
end_define

begin_comment
comment|/* This route notr to be advised in  					 * EGP Net Reachable messages 					 */
end_comment

begin_define
define|#
directive|define
name|HOPCNT_INFINITY
value|255
end_define

begin_comment
comment|/* unreachable net distance */
end_comment

begin_define
define|#
directive|define
name|INTERIOR
value|0
end_define

begin_comment
comment|/* interior routing table */
end_comment

begin_define
define|#
directive|define
name|EXTERIOR
value|1
end_define

begin_comment
comment|/* exterior routing table */
end_comment

begin_define
define|#
directive|define
name|DEFAULTNET
value|0
end_define

begin_comment
comment|/* net # for default route */
end_comment

begin_define
define|#
directive|define
name|RT_MINAGE
value|240
end_define

begin_comment
comment|/*4 /*240	/* minimum time in seconds before 					   route is deleted when not updated*/
end_comment

begin_define
define|#
directive|define
name|RT_NPOLLAGE
value|3
end_define

begin_comment
comment|/* minimum number of poll intervals 					   before a route is deleted when 					   not updated */
end_comment

begin_define
define|#
directive|define
name|RT_TIMERRATE
value|60
end_define

begin_comment
comment|/*2 /*60	/* minimum time in seconds between 					route age increments. Actually use 					multiple of EGP hello interval as this 					is timer interrupt period */
end_comment

begin_define
define|#
directive|define
name|INSTALLED
value|1
end_define

begin_comment
comment|/* status of default route */
end_comment

begin_define
define|#
directive|define
name|NOTINSTALLED
value|2
end_define

end_unit

