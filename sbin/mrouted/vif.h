begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $Id: vif.h,v 1.3 1993/05/30 01:36:38 deering Exp $  */
end_comment

begin_comment
comment|/*  * User level Virtual Interface structure  *  * A "virtual interface" is either a physical, multicast-capable interface  * (called a "phyint") or a virtual point-to-point link (called a "tunnel").  * (Note: all addresses, subnet numbers and masks are kept in NETWORK order.)  */
end_comment

begin_struct
struct|struct
name|uvif
block|{
name|u_short
name|uv_flags
decl_stmt|;
comment|/* VIFF_ flags defined below            */
name|u_char
name|uv_metric
decl_stmt|;
comment|/* cost of this vif                     */
name|u_char
name|uv_threshold
decl_stmt|;
comment|/* min ttl required to forward on vif   */
name|u_long
name|uv_lcl_addr
decl_stmt|;
comment|/* local address of this vif            */
name|u_long
name|uv_rmt_addr
decl_stmt|;
comment|/* remote end-point addr (tunnels only) */
name|u_long
name|uv_subnet
decl_stmt|;
comment|/* subnet number         (phyints only) */
name|u_long
name|uv_subnetmask
decl_stmt|;
comment|/* subnet mask           (phyints only) */
name|u_long
name|uv_subnetbcast
decl_stmt|;
comment|/* subnet broadcast addr (phyints only) */
name|char
name|uv_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* interface name                   */
name|struct
name|listaddr
modifier|*
name|uv_groups
decl_stmt|;
comment|/* list of local groups  (phyints only) */
name|struct
name|listaddr
modifier|*
name|uv_neighbors
decl_stmt|;
comment|/* list of neighboring routers          */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIFF_KERNEL_FLAGS
value|(VIFF_TUNNEL|VIFF_SRCRT)
end_define

begin_define
define|#
directive|define
name|VIFF_DOWN
value|0x0100
end_define

begin_comment
comment|/* kernel state of interface */
end_comment

begin_define
define|#
directive|define
name|VIFF_DISABLED
value|0x0200
end_define

begin_comment
comment|/* administratively disabled */
end_comment

begin_define
define|#
directive|define
name|VIFF_QUERIER
value|0x0400
end_define

begin_comment
comment|/* I am the subnet's querier */
end_comment

begin_struct
struct|struct
name|listaddr
block|{
name|struct
name|listaddr
modifier|*
name|al_next
decl_stmt|;
comment|/* link to next addr, MUST BE FIRST */
name|u_long
name|al_addr
decl_stmt|;
comment|/* local group or neighbor address  */
name|u_long
name|al_timer
decl_stmt|;
comment|/* for timing out group or neighbor */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NO_VIF
value|((vifi_t)MAXVIFS)
end_define

begin_comment
comment|/* An invalid vif index */
end_comment

end_unit

