begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mine.h */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/pepsy/RCS/mine.h,v 7.2 91/02/22 09:49:16 mrose Interim $  *  *  * $Log:	mine.h,v $  * Revision 7.2  91/02/22  09:49:16  mrose  * Interim 6.8  *   * Revision 7.1  90/11/04  19:18:55  mrose  * update  *   * Revision 7.0  90/07/01  19:54:42  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_define
define|#
directive|define
name|TABLESIZE
value|29
end_define

begin_typedef
typedef|typedef
struct|struct
name|ID_TABLE
block|{
name|char
modifier|*
name|h_value
decl_stmt|;
name|char
modifier|*
name|r_value
decl_stmt|;
name|int
name|def_bit
decl_stmt|;
name|int
name|def_value
decl_stmt|;
name|int
name|count
decl_stmt|;
name|struct
name|ID_TABLE
modifier|*
name|next
decl_stmt|;
block|}
name|id_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|S_TABLE
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|type
decl_stmt|;
name|struct
name|S_TABLE
modifier|*
name|parent
decl_stmt|;
name|char
modifier|*
name|field
decl_stmt|;
name|int
name|defined
decl_stmt|;
name|struct
name|S_TABLE
modifier|*
name|next
decl_stmt|;
block|}
name|s_table
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|id_entry
modifier|*
name|id_table
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|c_flags
parameter_list|()
function_decl|;
end_function_decl

end_unit

