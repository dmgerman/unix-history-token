begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* quipu_sntx.c - invoke quipu syntax handlers */
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
literal|"$Header: /f/osi/dsap/common/RCS/quipu_sntx.c,v 7.2 91/02/22 09:20:03 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/dsap/common/RCS/quipu_sntx.c,v 7.2 91/02/22 09:20:03 mrose Interim $  *  *  * $Log:	quipu_sntx.c,v $  * Revision 7.2  91/02/22  09:20:03  mrose  * Interim 6.8  *   * Revision 7.1  90/10/17  11:42:37  mrose  * sync  *   * Revision 7.0  89/11/23  21:44:25  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *                                NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_macro
name|quipu_syntaxes
argument_list|()
end_macro

begin_block
block|{
name|standard_syntaxes
argument_list|()
expr_stmt|;
name|acl_syntax
argument_list|()
expr_stmt|;
name|edbinfo_syntax
argument_list|()
expr_stmt|;
name|schema_syntax
argument_list|()
expr_stmt|;
name|photo_syntax
argument_list|()
expr_stmt|;
name|protected_password_syntax
argument_list|()
expr_stmt|;
name|inherit_syntax
argument_list|()
expr_stmt|;
name|audio_syntax
argument_list|()
expr_stmt|;
name|ap_syntax
argument_list|()
expr_stmt|;
comment|/* Thorn syntaxes */
name|mailbox_syntax
argument_list|()
expr_stmt|;
name|documentStore_syntax
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

