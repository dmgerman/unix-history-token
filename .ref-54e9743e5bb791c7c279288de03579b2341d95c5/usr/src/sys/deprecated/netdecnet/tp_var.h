begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tp_var.h	1.3	82/10/09	*/
end_comment

begin_comment
comment|/*  * Kernel data structures for DECnet Transport layer.  */
end_comment

begin_comment
comment|/*  * DECnet node number of this host.  */
end_comment

begin_decl_stmt
name|int
name|tp_host
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Transport Statistics  */
end_comment

begin_struct
struct|struct
name|tpstat
block|{
name|int
name|tps_badinit
decl_stmt|;
comment|/* bad initialization message */
name|int
name|tps_init
decl_stmt|;
comment|/* good initialization message */
name|int
name|tps_p2hdr
decl_stmt|;
comment|/* saw Phase II route header */
name|int
name|tps_returned
decl_stmt|;
comment|/* got a returned packet */
name|int
name|tps_shortpacket
decl_stmt|;
comment|/* packet was too short */
name|int
name|tps_notforme
decl_stmt|;
comment|/* dstnode not this system */
name|int
name|tps_verif
decl_stmt|;
comment|/* saw a verification message */
name|int
name|tps_badtest
decl_stmt|;
comment|/* bad hello and test message */
name|int
name|tps_unknown
decl_stmt|;
comment|/* unknown message type */
name|int
name|tps_badsrc
decl_stmt|;
comment|/* source number out of range */
name|int
name|tps_route
decl_stmt|;
comment|/* got routing message */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transport State  * (should be per interface when routing)  */
end_comment

begin_decl_stmt
name|int
name|tpstate
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TPS_HALT
value|0
end_define

begin_comment
comment|/* line not initialized */
end_comment

begin_define
define|#
directive|define
name|TPS_TIS
value|1
end_define

begin_comment
comment|/* transport initialize sent */
end_comment

begin_define
define|#
directive|define
name|TPS_RUN
value|2
end_define

begin_comment
comment|/* line ready for use */
end_comment

begin_comment
comment|/*  * Routing Parameters  * (Transport spec, page 23)  */
end_comment

begin_struct
struct|struct
name|tprp
block|{
name|short
name|tprp_nn
decl_stmt|;
comment|/* number of nodes in network (max addr) */
comment|/* NEED MORE FOR FULL ROUTING */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|tpstat
name|tpstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tprp
name|tprp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|tpintrq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifnet
modifier|*
name|tpifp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The DECnet hardware interface */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

