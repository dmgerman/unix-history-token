begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	defs.h	4.3	82/05/26	*/
end_comment

begin_comment
comment|/*  * Internal data structure definitions for  * user routing process.  Based on Xerox NS  * protocol specs with mods relevant to more  * general addressing scheme.  */
end_comment

begin_include
include|#
directive|include
file|<net/route.h>
end_include

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
name|rtu_gateway
decl_stmt|;
name|short
name|rtu_flags
decl_stmt|;
name|short
name|rtu_retry
decl_stmt|;
name|short
name|rtu_timer
decl_stmt|;
name|short
name|rtu_state
decl_stmt|;
name|int
name|rtu_metric
decl_stmt|;
name|struct
name|ifnet
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
name|rt_gateway
value|rt_rtu.rtu_entry.rtu_gateway
end_define

begin_comment
comment|/* who to forward to */
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
name|rt_retry
value|rt_rtu.rtu_entry.rtu_retry
end_define

begin_comment
comment|/* retries of ioctl */
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
comment|/* interface to take */
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
name|RTS_DELRT
value|0x1
end_define

begin_comment
comment|/* delete pending */
end_comment

begin_define
define|#
directive|define
name|RTS_CHGRT
value|0x2
end_define

begin_comment
comment|/* change command pending */
end_comment

begin_define
define|#
directive|define
name|RTS_ADDRT
value|0x4
end_define

begin_comment
comment|/* add command pending */
end_comment

begin_define
define|#
directive|define
name|RTS_SILENT
value|0x8
end_define

begin_comment
comment|/* don't send to router */
end_comment

begin_decl_stmt
name|struct
name|rthash
name|nethash
index|[
name|ROUTEHASHSIZ
index|]
decl_stmt|,
name|hosthash
index|[
name|ROUTEHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|rt_entry
modifier|*
name|rtlookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Per address family routines.  */
end_comment

begin_struct
struct|struct
name|afswitch
block|{
name|int
function_decl|(
modifier|*
name|af_hash
function_decl|)
parameter_list|()
function_decl|;
comment|/* returns keys based on address */
name|int
function_decl|(
modifier|*
name|af_netmatch
function_decl|)
parameter_list|()
function_decl|;
comment|/* verifies net # matching */
name|int
function_decl|(
modifier|*
name|af_output
function_decl|)
parameter_list|()
function_decl|;
comment|/* interprets address for sending */
name|int
function_decl|(
modifier|*
name|af_portmatch
function_decl|)
parameter_list|()
function_decl|;
comment|/* interprets address on receipt */
name|int
function_decl|(
modifier|*
name|af_checkhost
function_decl|)
parameter_list|()
function_decl|;
comment|/* tells if address for host or net */
name|int
function_decl|(
modifier|*
name|af_canon
function_decl|)
parameter_list|()
function_decl|;
comment|/* purges extraneous part of address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure returned by af_hash routines.  */
end_comment

begin_struct
struct|struct
name|afhash
block|{
name|u_int
name|afh_hosthash
decl_stmt|;
comment|/* host based hash */
name|u_int
name|afh_nethash
decl_stmt|;
comment|/* network based hash */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|afswitch
name|afswitch
index|[
name|AF_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table proper */
end_comment

end_unit

