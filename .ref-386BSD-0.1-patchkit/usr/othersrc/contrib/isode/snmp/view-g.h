begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* view-g.h - VIEW group */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/snmp/RCS/view-g.h,v 7.3 91/02/22 09:45:02 mrose Interim $  *  *  * $Log:	view-g.h,v $  * Revision 7.3  91/02/22  09:45:02  mrose  * Interim 6.8  *   * Revision 7.2  90/12/18  10:14:35  mrose  * update  *   * Revision 7.1  90/12/17  22:19:34  mrose  * touch-up  *   * Revision 7.0  90/12/17  22:08:01  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"isoaddrs.h"
end_include

begin_include
include|#
directive|include
file|"internet.h"
end_include

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_comment
comment|/*
comment|VIEWS */
end_comment

begin_define
define|#
directive|define
name|inSubtree
parameter_list|(
name|tree
parameter_list|,
name|object
parameter_list|)
define|\
value|((tree) -> oid_nelem<= (object) -> oid_nelem \&& bcmp ((char *) (tree) -> oid_elements, \ 		      (char *) (object) -> oid_elements, \ 		      (tree) -> oid_nelem \ 		          * sizeof ((tree) -> oid_elements[0])) == 0)
end_define

begin_struct
struct|struct
name|subtree
block|{
name|struct
name|subtree
modifier|*
name|s_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|subtree
modifier|*
name|s_back
decl_stmt|;
comment|/* doubly-linked list */
name|OID
name|s_subtree
decl_stmt|;
comment|/* subtree */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|view
block|{
name|struct
name|view
modifier|*
name|v_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|view
modifier|*
name|v_back
decl_stmt|;
comment|/*   .. */
name|OID
name|v_name
decl_stmt|;
comment|/* view name */
name|u_long
name|v_mask
decl_stmt|;
comment|/* view mask */
name|struct
name|subtree
name|v_subtree
decl_stmt|;
comment|/* list of subtrees */
name|struct
name|qbuf
modifier|*
name|v_community
decl_stmt|;
comment|/* for proxy, traps... */
name|struct
name|sockaddr
name|v_sa
decl_stmt|;
name|unsigned
name|int
modifier|*
name|v_instance
decl_stmt|;
comment|/* object instance */
name|int
name|v_insize
decl_stmt|;
comment|/*   .. */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|view
modifier|*
name|VHead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|COMMUNITIES */
end_comment

begin_struct
struct|struct
name|community
block|{
name|struct
name|community
modifier|*
name|c_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|community
modifier|*
name|c_back
decl_stmt|;
comment|/*   .. */
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/* community name */
name|struct
name|NSAPaddr
name|c_addr
decl_stmt|;
comment|/* network address */
name|int
name|c_permission
decl_stmt|;
comment|/* same as ot_access */
define|#
directive|define
name|OT_YYY
value|0x08
name|OID
name|c_vu
decl_stmt|;
comment|/* associated view */
name|struct
name|view
modifier|*
name|c_view
decl_stmt|;
comment|/*   .. */
name|unsigned
name|int
modifier|*
name|c_instance
decl_stmt|;
comment|/* object instance */
name|int
name|c_insize
decl_stmt|;
comment|/*   .. */
name|struct
name|community
modifier|*
name|c_next
decl_stmt|;
comment|/* next in lexi-order */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|community
modifier|*
name|CHead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|TRAPS */
end_comment

begin_struct
struct|struct
name|trap
block|{
name|struct
name|trap
modifier|*
name|t_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|trap
modifier|*
name|t_back
decl_stmt|;
comment|/*   .. */
name|char
modifier|*
name|t_name
decl_stmt|;
comment|/* trap name */
name|struct
name|view
name|t_vu
decl_stmt|;
comment|/* associated view */
name|struct
name|view
modifier|*
name|t_view
decl_stmt|;
comment|/*   .. */
name|u_long
name|t_generics
decl_stmt|;
comment|/* generic traps enabled */
name|unsigned
name|int
modifier|*
name|t_instance
decl_stmt|;
comment|/* object instance */
name|int
name|t_insize
decl_stmt|;
comment|/*   .. */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|trap
modifier|*
name|UHead
decl_stmt|;
end_decl_stmt

end_unit

