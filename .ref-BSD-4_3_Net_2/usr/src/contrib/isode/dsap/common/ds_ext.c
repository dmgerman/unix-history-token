begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ds_ext.c - */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/dsap/common/RCS/ds_ext.c,v 7.1 91/02/22 09:19:06 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/dsap/common/RCS/ds_ext.c,v 7.1 91/02/22 09:19:06 mrose Interim $  *  *  * $Log:	ds_ext.c,v $  * Revision 7.1  91/02/22  09:19:06  mrose  * Interim 6.8  *   * Revision 7.0  90/12/01  18:07:30  mrose  * *** empty log message ***  *   * Revision 7.0  89/11/23  21:50:30  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *                                NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|"quipu/util.h"
end_include

begin_include
include|#
directive|include
file|"quipu/common.h"
end_include

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|log_dsap
decl_stmt|;
end_decl_stmt

begin_macro
name|subords_free
argument_list|(
argument|subp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|subordinate
modifier|*
name|subp
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|subp
operator|==
name|NULLSUBORD
condition|)
return|return;
name|subords_free
argument_list|(
name|subp
operator|->
name|sub_next
argument_list|)
expr_stmt|;
name|rdn_free
argument_list|(
name|subp
operator|->
name|sub_rdn
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|subp
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ems_free
argument_list|(
argument|emp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|entrymod
modifier|*
name|emp
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|emp
operator|==
name|NULLMOD
condition|)
return|return;
name|ems_free
argument_list|(
name|emp
operator|->
name|em_next
argument_list|)
expr_stmt|;
name|as_free
argument_list|(
name|emp
operator|->
name|em_what
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|emp
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|aps_free
argument_list|(
argument|app
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|access_point
modifier|*
name|app
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|app
operator|==
name|NULLACCESSPOINT
condition|)
return|return;
name|aps_free
argument_list|(
name|app
operator|->
name|ap_next
argument_list|)
expr_stmt|;
name|dn_free
argument_list|(
name|app
operator|->
name|ap_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|app
operator|->
name|ap_address
condition|)
name|psap_free
argument_list|(
name|app
operator|->
name|ap_address
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|app
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|crefs_free
argument_list|(
argument|crefp
argument_list|)
end_macro

begin_decl_stmt
name|ContinuationRef
name|crefp
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|crefp
operator|==
name|NULLCONTINUATIONREF
condition|)
return|return;
name|crefs_free
argument_list|(
name|crefp
operator|->
name|cr_next
argument_list|)
expr_stmt|;
name|dn_free
argument_list|(
name|crefp
operator|->
name|cr_name
argument_list|)
expr_stmt|;
name|aps_free
argument_list|(
name|crefp
operator|->
name|cr_accesspoints
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|crefp
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

