begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ext.c */
end_comment

begin_comment
comment|/* EGP User Process, ISI 23-Jun-84 */
end_comment

begin_comment
comment|/* external variable definitions */
end_comment

begin_include
include|#
directive|include
file|"include.h"
end_include

begin_comment
comment|/* int impsock;			/* IMP socket handle */
end_comment

begin_decl_stmt
name|int
name|tracing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log errors, route changes&/or packets */
end_comment

begin_decl_stmt
name|int
name|n_interfaces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # internet interfaces */
end_comment

begin_decl_stmt
name|int
name|n_remote_nets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # remote nets via internal non-routing 				   gateways */
end_comment

begin_decl_stmt
name|struct
name|rthash
name|rt_interior
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* routes interior to my autonomous system */
end_comment

begin_decl_stmt
name|struct
name|rthash
name|nethash
index|[
name|ROUTEHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exterior routes advised by EGP  						neighbor - see rt_table.h */
end_comment

begin_decl_stmt
name|struct
name|interface
modifier|*
name|ifnet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* direct internet interface list */
end_comment

begin_decl_stmt
name|int
name|terminate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terminate EGP process - set by 				   egpallcease(); tested by egpstunacq() and  				   egpacq() */
end_comment

begin_decl_stmt
name|int
name|s
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket for ioctl calls installing routes, 				   set in main() */
end_comment

begin_decl_stmt
name|int
name|install
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if TRUE install route in kernel, 				   it is set by main() after kernel routes 				   initially read and tested in rt_table.c */
end_comment

begin_decl_stmt
name|int
name|rt_default_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NULL (no default) | INSTALLED (install  				   needs to be true also) | NOTINSTALLED */
end_comment

begin_decl_stmt
name|u_short
name|mysystem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* autonomous system number */
end_comment

begin_decl_stmt
name|int
name|nneigh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of trusted egp neighbors */
end_comment

begin_decl_stmt
name|int
name|maxacq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number neighbors to be acquired */
end_comment

begin_decl_stmt
name|int
name|n_acquired
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number neighbors acquired */
end_comment

begin_decl_stmt
name|int
name|egpsleep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* No. seconds between egpjob() wakeups, 				   recomputed when neighbor acquired or ceased 				 */
end_comment

begin_decl_stmt
name|struct
name|egpngh
modifier|*
name|egpngh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start egp neighbor state table linked list 				 */
end_comment

begin_decl_stmt
name|u_short
name|egprid_h
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sequence number of received egp packet 				   in host byte order - all ids in internal 				   tables are in host byte order */
end_comment

begin_decl_stmt
name|int
name|rt_maxage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum allowed age of any route since last 				   updated by an NR message */
end_comment

begin_decl_stmt
name|int
name|maxpollint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum poll interval of acquired neighbors 				   set in egpstime(), used in rt_NRupdate() */
end_comment

end_unit

