begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* smux-g.h - SMUX group */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/snmp/RCS/smux-g.h,v 7.3 91/02/22 09:43:56 mrose Interim $  *  *  * $Log:	smux-g.h,v $  * Revision 7.3  91/02/22  09:43:56  mrose  * Interim 6.8  *   * Revision 7.2  91/02/20  17:25:53  mrose  * stuff  *   * Revision 7.1  91/01/12  11:43:20  mrose  * stuff  *   * Revision 7.0  90/12/17  22:07:54  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

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

begin_struct
struct|struct
name|smuxPeer
block|{
name|struct
name|smuxPeer
modifier|*
name|pb_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|smuxPeer
modifier|*
name|pb_back
decl_stmt|;
comment|/*   .. */
name|int
name|pb_index
decl_stmt|;
comment|/* smuxPindex */
name|int
name|pb_fd
decl_stmt|;
name|struct
name|sockaddr_in
name|pb_address
decl_stmt|;
name|char
name|pb_source
index|[
literal|30
index|]
decl_stmt|;
name|OID
name|pb_identity
decl_stmt|;
comment|/* smuxPidentity */
name|char
modifier|*
name|pb_description
decl_stmt|;
comment|/* smuxPdescription */
name|PS
name|pb_ps
decl_stmt|;
name|int
name|pb_priority
decl_stmt|;
comment|/* minimum allowed priority */
name|int
name|pb_newstatus
decl_stmt|;
comment|/* for setting smuxPstatus */
name|int
name|pb_invalid
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|smuxPeer
modifier|*
name|PHead
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|smuxTree
block|{
name|struct
name|smuxTree
modifier|*
name|tb_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|smuxTree
modifier|*
name|tb_back
decl_stmt|;
comment|/*   .. */
define|#
directive|define
name|TB_SIZE
value|30
comment|/* object instance */
name|unsigned
name|int
name|tb_instance
index|[
name|TB_SIZE
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|tb_insize
decl_stmt|;
name|OT
name|tb_subtree
decl_stmt|;
comment|/* smuxTsubtree */
name|int
name|tb_priority
decl_stmt|;
comment|/* smuxTpriority */
name|struct
name|smuxPeer
modifier|*
name|tb_peer
decl_stmt|;
comment|/* smuxTindex */
name|struct
name|smuxTree
modifier|*
name|tb_next
decl_stmt|;
comment|/* linked list for ot_smux */
name|int
name|tb_newstatus
decl_stmt|;
comment|/* for setting smuxPstatus */
name|int
name|tb_invalid
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|smuxTree
modifier|*
name|THead
decl_stmt|;
end_decl_stmt

end_unit

