begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* **  QRYMOD.H -- Query Modification header file. ** **	Contains the manifest constants and global variables **	used by the query modification process. ** **	Version: **		@(#)qrymod.h	7.1	2/5/81 */
end_comment

begin_decl_stmt
specifier|extern
name|DESC
name|Treedes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* descriptor for tree catalog */
end_comment

begin_struct
struct|struct
block|{
name|short
name|qm_newresvar
decl_stmt|;
comment|/* new result variable number */
block|}
name|Qm
struct|;
end_struct

begin_comment
comment|/********************************************************************* **								    ** **  The following stuff is used by the protection algorithm only.   ** **								    ** *********************************************************************/
end_comment

begin_comment
comment|/* maximum query mode for proopset (<--> sizeof Proopmap - 1) */
end_comment

begin_define
define|#
directive|define
name|MAXPROQM
value|4
end_define

end_unit

