begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sequence.h - */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/quipu/RCS/sequence.h,v 7.1 91/02/22 09:26:07 mrose Interim $  *  *  * $Log:	sequence.h,v $  * Revision 7.1  91/02/22  09:26:07  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:56:44  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_struct
struct|struct
name|dua_sequence
block|{
name|char
modifier|*
name|ds_name
decl_stmt|;
name|struct
name|dua_seq_entry
modifier|*
name|ds_data
decl_stmt|;
name|struct
name|dua_seq_entry
modifier|*
name|ds_last
decl_stmt|;
name|struct
name|dua_sequence
modifier|*
name|ds_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ds_alloc
parameter_list|()
value|(struct dua_sequence *) smalloc(sizeof (struct dua_sequence))
end_define

begin_define
define|#
directive|define
name|NULL_DS
value|((struct dua_sequence *)0)
end_define

begin_function_decl
name|DN
name|sequence_dn
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|dua_seq_entry
block|{
name|DN
name|de_name
decl_stmt|;
name|struct
name|dua_seq_entry
modifier|*
name|de_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|de_alloc
parameter_list|()
value|(struct dua_seq_entry *) smalloc(sizeof (struct dua_seq_entry))
end_define

begin_define
define|#
directive|define
name|NULL_DE
value|((struct dua_seq_entry *)0)
end_define

end_unit

