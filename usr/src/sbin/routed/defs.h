begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	defs.h	4.1	82/05/22	*/
end_comment

begin_comment
comment|/*  * Internal data structure definitions for  * user routing process.  Based on Xerox NS  * protocol specs with mods relevant to more  * general addressing scheme.  */
end_comment

begin_comment
comment|/*  * Internal routing table structure.  * Differs a bit from kernel tables.  */
end_comment

begin_struct
struct|struct
name|rt_hash
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
name|rt_retry
decl_stmt|;
comment|/* # ioctl retries */
name|int
name|rt_timer
decl_stmt|;
comment|/* for invalidation */
name|int
name|rt_metric
decl_stmt|;
comment|/* hop count of route */
name|struct
name|ifnet
modifier|*
name|rt_ifp
decl_stmt|;
comment|/* corresponding interface */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ROUTEHASHSIZ
value|19
end_define

begin_comment
comment|/*  * Flags used by routing process are not  * interpreted by kernel.  */
end_comment

begin_define
define|#
directive|define
name|RTF_DELRT
value|0x8
end_define

begin_comment
comment|/* delete pending */
end_comment

begin_define
define|#
directive|define
name|RTF_CHGRT
value|0x10
end_define

begin_comment
comment|/* change command pending */
end_comment

begin_define
define|#
directive|define
name|RTF_ADDRT
value|0x20
end_define

begin_comment
comment|/* add command pending */
end_comment

begin_define
define|#
directive|define
name|RTF_SILENT
value|0x40
end_define

begin_comment
comment|/* don't send to router */
end_comment

begin_decl_stmt
name|struct
name|rt_hash
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
comment|/*  * Per address family routines.  Hash returns hash key based  * on address; netmatch verifies net # matching, output interprets  * an address in preparation for sending; portmatch interprets  * an address in verifying incoming packets were sent from the  * appropriate port; checkhost is used to decide whether an  * address is for a host, or for a network (e.g. broadcast);  * canon purges any extraneous stuff from a sender's address  * before pattern matching is performed (e.g. Internet ports).  */
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
name|int
function_decl|(
modifier|*
name|af_netmatch
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|af_output
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|af_portmatch
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|af_checkhost
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|af_canon
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|afhash
block|{
name|u_int
name|afh_hosthash
decl_stmt|;
name|u_int
name|afh_nethash
decl_stmt|;
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

end_unit

