begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sym.h */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/pepsy/RCS/sym.h,v 7.1 91/02/22 09:50:03 mrose Interim $  *  *  * $Log:	sym.h,v $  * Revision 7.1  91/02/22  09:50:03  mrose  * Interim 6.8  *   * Revision 7.0  90/07/01  19:54:45  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|symlist
block|{
name|char
modifier|*
name|sy_encpref
decl_stmt|;
name|char
modifier|*
name|sy_decpref
decl_stmt|;
name|char
modifier|*
name|sy_prfpref
decl_stmt|;
name|char
modifier|*
name|sy_module
decl_stmt|;
name|char
modifier|*
name|sy_name
decl_stmt|;
name|YP
name|sy_type
decl_stmt|;
name|struct
name|symlist
modifier|*
name|sy_next
decl_stmt|;
block|}
name|symlist
operator|,
typedef|*
name|SY
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLSY
value|((SY) 0)
end_define

end_unit

