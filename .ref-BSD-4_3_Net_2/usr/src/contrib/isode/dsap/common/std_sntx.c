begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* std_sntx.c - invoke standard syntax handlers */
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
literal|"$Header: /f/osi/dsap/common/RCS/std_sntx.c,v 7.2 91/02/22 09:20:18 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/dsap/common/RCS/std_sntx.c,v 7.2 91/02/22 09:20:18 mrose Interim $  *  *  * $Log:	std_sntx.c,v $  * Revision 7.2  91/02/22  09:20:18  mrose  * Interim 6.8  *   * Revision 7.1  90/10/17  11:42:53  mrose  * sync  *   * Revision 7.0  89/11/23  21:44:32  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *                                NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_macro
name|standard_syntaxes
argument_list|()
end_macro

begin_block
block|{
name|string_syntaxes
argument_list|()
expr_stmt|;
name|cilist_syntax
argument_list|()
expr_stmt|;
name|dn_syntax
argument_list|()
expr_stmt|;
name|psap_syntax
argument_list|()
expr_stmt|;
name|objectclass_syntax
argument_list|()
expr_stmt|;
name|oid_syntax
argument_list|()
expr_stmt|;
name|time_syntax
argument_list|()
expr_stmt|;
name|boolean_syntax
argument_list|()
expr_stmt|;
name|integer_syntax
argument_list|()
expr_stmt|;
name|fax_syntax
argument_list|()
expr_stmt|;
name|post_syntax
argument_list|()
expr_stmt|;
name|telex_syntax
argument_list|()
expr_stmt|;
name|teletex_syntax
argument_list|()
expr_stmt|;
name|pref_deliv_syntax
argument_list|()
expr_stmt|;
name|guide_syntax
argument_list|()
expr_stmt|;
name|certificate_syntax
argument_list|()
expr_stmt|;
name|certificate_pair_syntax
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

