begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* routes.h - support for MIB support of the routing tables */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/snmp/RCS/routes.h,v 7.2 91/02/22 09:43:53 mrose Interim $  *  * Contributed by NYSERNet Inc.  This work was partially supported by the  * U.S. Defense Advanced Research Projects Agency and the Rome Air Development  * Center of the U.S. Air Force Systems Command under contract number  * F30602-88-C-0016.  *  *  * $Log:	routes.h,v $  * Revision 7.2  91/02/22  09:43:53  mrose  * Interim 6.8  *   * Revision 7.1  91/01/08  12:48:42  mrose  * update  *   * Revision 7.0  89/11/23  22:23:22  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|METRIC_NONE
value|(-1)
end_define

begin_comment
comment|/* ipRouteMetric[1234] */
end_comment

begin_define
define|#
directive|define
name|TYPE_OTHER
value|1
end_define

begin_comment
comment|/* ipRouteType */
end_comment

begin_define
define|#
directive|define
name|TYPE_DIRECT
value|3
end_define

begin_define
define|#
directive|define
name|TYPE_REMOTE
value|4
end_define

begin_define
define|#
directive|define
name|PROTO_OTHER
value|1
end_define

begin_comment
comment|/* ipRouteProto */
end_comment

begin_define
define|#
directive|define
name|PROTO_ICMP
value|4
end_define

begin_define
define|#
directive|define
name|PROTO_ESIS
value|10
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|rtetab
block|{
define|#
directive|define
name|RT_SIZE
value|20
comment|/* object instance */
name|unsigned
name|int
name|rt_instance
index|[
name|RT_SIZE
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|rt_insize
decl_stmt|;
name|int
name|rt_magic
decl_stmt|;
comment|/* for multiple routes to the 						   same destination */
name|struct
name|rtentry
name|rt_rt
decl_stmt|;
comment|/* from kernel */
name|union
name|sockaddr_un
name|rt_dst
decl_stmt|;
comment|/* key */
name|union
name|sockaddr_un
name|rt_gateway
decl_stmt|;
comment|/* value */
name|struct
name|rtetab
modifier|*
name|rt_next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|rtetab
modifier|*
name|rts_inet
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|rtetab
modifier|*
name|rts_iso
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|get_routes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rtetab
modifier|*
name|get_rtent
parameter_list|()
function_decl|;
end_function_decl

end_unit

