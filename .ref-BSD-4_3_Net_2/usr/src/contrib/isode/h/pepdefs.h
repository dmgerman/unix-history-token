begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pepdefs.h */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/pepdefs.h,v 7.1 91/02/22 09:24:51 mrose Interim $  *  *  * $Log:	pepdefs.h,v $  * Revision 7.1  91/02/22  09:24:51  mrose  * Interim 6.8  *   * Revision 7.0  90/07/01  19:52:37  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEPDEF_DEFINITIONS
end_ifndef

begin_define
define|#
directive|define
name|PEPDEF_DEFINITIONS
end_define

begin_comment
comment|/*  * Globally known pep definitions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|md_name
decl_stmt|;
comment|/* Name of this module */
name|int
name|md_nentries
decl_stmt|;
comment|/* Number of entries */
name|tpe
modifier|*
modifier|*
name|md_etab
decl_stmt|;
comment|/* Pointer to encoding tables */
name|tpe
modifier|*
modifier|*
name|md_dtab
decl_stmt|;
comment|/* Pointer to decoding tables */
name|ptpe
modifier|*
modifier|*
name|md_ptab
decl_stmt|;
comment|/* Pointer to Printing tables */
name|PE
function_decl|(
modifier|*
name|md_eucode
function_decl|)
parameter_list|()
function_decl|;
comment|/* User code for encoding */
name|PE
function_decl|(
modifier|*
name|md_ducode
function_decl|)
parameter_list|()
function_decl|;
comment|/* User code for decoding */
name|PE
function_decl|(
modifier|*
name|md_pucode
function_decl|)
parameter_list|()
function_decl|;
comment|/* User code for printing */
block|}
name|modtyp
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|(char *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

