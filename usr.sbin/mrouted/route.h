begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $FreeBSD$  * route.h,v 3.8.4.6 1997/07/01 23:02:35 fenner Exp  */
end_comment

begin_comment
comment|/*  * Routing Table Entry, one per subnet from which a multicast could originate.  * (Note: all addresses, subnet numbers and masks are kept in NETWORK order.)  *  * The Routing Table is stored as a doubly-linked list of these structures,  * ordered by decreasing value of rt_originmask and, secondarily, by  * decreasing value of rt_origin within each rt_originmask value.  * This data structure is efficient for generating route reports, whether  * full or partial, for processing received full reports, for clearing the  * CHANGED flags, and for periodically advancing the timers in all routes.  * It is not so efficient for updating a small number of routes in response  * to a partial report.  In a stable topology, the latter are rare; if they  * turn out to be costing a lot, we can add an auxiliary hash table for  * faster access to arbitrary route entries.  */
end_comment

begin_struct
struct|struct
name|rtentry
block|{
name|struct
name|rtentry
modifier|*
name|rt_next
decl_stmt|;
comment|/* link to next entry MUST BE FIRST */
name|u_int32
name|rt_origin
decl_stmt|;
comment|/* subnet origin of multicasts      */
name|u_int32
name|rt_originmask
decl_stmt|;
comment|/* subnet mask for origin           */
name|short
name|rt_originwidth
decl_stmt|;
comment|/* # bytes of origin subnet number  */
name|u_char
name|rt_metric
decl_stmt|;
comment|/* cost of route back to origin     */
name|u_char
name|rt_flags
decl_stmt|;
comment|/* RTF_ flags defined below         */
name|u_int32
name|rt_gateway
decl_stmt|;
comment|/* first-hop gateway back to origin */
name|vifi_t
name|rt_parent
decl_stmt|;
comment|/* incoming vif (ie towards origin) */
name|vifbitmap_t
name|rt_children
decl_stmt|;
comment|/* outgoing children vifs           */
name|u_int32
modifier|*
name|rt_dominants
decl_stmt|;
comment|/* per vif dominant gateways        */
name|nbrbitmap_t
name|rt_subordinates
decl_stmt|;
comment|/* bitmap of subordinate gateways   */
name|nbrbitmap_t
name|rt_subordadv
decl_stmt|;
comment|/* recently advertised subordinates */
name|u_int
name|rt_timer
decl_stmt|;
comment|/* for timing out the route entry   */
name|struct
name|rtentry
modifier|*
name|rt_prev
decl_stmt|;
comment|/* link to previous entry           */
name|struct
name|gtable
modifier|*
name|rt_groups
decl_stmt|;
comment|/* link to active groups 	    */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTF_CHANGED
value|0x01
end_define

begin_comment
comment|/* route changed but not reported   */
end_comment

begin_define
define|#
directive|define
name|RTF_HOLDDOWN
value|0x04
end_define

begin_comment
comment|/* this route is in holddown	    */
end_comment

begin_define
define|#
directive|define
name|ALL_ROUTES
value|0
end_define

begin_comment
comment|/* possible arguments to report()   */
end_comment

begin_define
define|#
directive|define
name|CHANGED_ROUTES
value|1
end_define

begin_comment
comment|/*  and report_to_all_neighbors()   */
end_comment

begin_define
define|#
directive|define
name|RT_FMT
parameter_list|(
name|r
parameter_list|,
name|s
parameter_list|)
value|inet_fmts((r)->rt_origin, (r)->rt_originmask, s)
end_define

end_unit

