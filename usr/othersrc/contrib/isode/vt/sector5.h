begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sector5.h - VTPM: FSM sector 5 definitions */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/vt/RCS/sector5.h,v 7.1 91/02/22 09:48:10 mrose Interim $  *  *  * $Log:	sector5.h,v $  * Revision 7.1  91/02/22  09:48:10  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:31:41  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|expl_ptr
block|{
define|#
directive|define
name|NULLCOORD
value|-1
name|int
name|xval
decl_stmt|;
comment|/* if they don't exist = NULLCOORD */
name|int
name|yval
decl_stmt|;
name|int
name|zval
decl_stmt|;
block|}
name|EXPL_PTR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NOBKTOK
value|-1
end_define

begin_comment
comment|/* for token in S mode */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bkq_content
block|{
name|int
name|token_val
decl_stmt|;
comment|/* 0 initiator, 1 acceptor, 2 accChoice or nobktok */
name|EXPL_PTR
name|ExplPtr
decl_stmt|;
block|}
name|BKQ_content
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bkr_content
block|{
name|int
name|token_val
decl_stmt|;
comment|/* 0 initiator, 1 acceptor or nobktok */
name|EXPL_PTR
name|ExplPtr
decl_stmt|;
block|}
name|BKR_content
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|br_cnt
block|{
name|BKQ_content
name|BKQcont
decl_stmt|;
name|BKR_content
name|BKRcont
decl_stmt|;
name|EXPL_PTR
name|ExPtr
decl_stmt|;
block|}
name|BRcnt
typedef|;
end_typedef

end_unit

