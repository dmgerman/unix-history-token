begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pepy_strings.c - constant strings used in pepy */
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
literal|"$Header: /f/osi/pepsy/RCS/pepsy_strings.c,v 7.1 91/02/22 09:49:50 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/pepsy/RCS/pepsy_strings.c,v 7.1 91/02/22 09:49:50 mrose Interim $  *  *  * $Log:	pepsy_strings.c,v $  * Revision 7.1  91/02/22  09:49:50  mrose  * Interim 6.8  *   * Revision 7.0  90/07/01  19:54:28  mrose  * *** empty log message ***  *   * Revision 7.0  89/11/23  22:11:54  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pepy_strings
index|[]
init|=
block|{
literal|"bad "
block|,
comment|/* PEPY_ERR_BAD */
literal|"bad bitstring: "
block|,
comment|/* PEPY_ERR_BAD_BITS */
literal|"bad boolean: "
block|,
comment|/* PEPY_ERR_BAD_BOOLEAN */
literal|"bad class/id: "
block|,
comment|/* PEPY_ERR_BAD_CLASS */
literal|"bad class/form/id: "
block|,
comment|/* PEPY_ERR_BAD_CLASS_FORM_ID */
literal|"bad form "
block|,
comment|/* PEPY_ERR_BAD_FORM */
literal|"bad integer: "
block|,
comment|/* PEPY_ERR_BAD_INTEGER */
literal|"bad object identifier: "
block|,
comment|/* PEPY_ERR_BAD_OID */
literal|"bad octetstring: "
block|,
comment|/* PEPY_ERR_BAD_OCTET */
literal|"bad real: "
block|,
comment|/* PEPY_ERR_BAD_REAL */
literal|"bad sequence: "
block|,
comment|/* PEPY_ERR_BAD_SEQ */
literal|"bad set: "
block|,
comment|/* PEPY_ERR_BAD_SET */
literal|"has too many bits"
block|,
comment|/* PEPY_ERR_TOO_MANY_BITS */
literal|"has too many elements"
block|,
comment|/* PEPY_ERR_TOO_MANY_ELEMENTS */
literal|"has unknown choice: "
block|,
comment|/* PEPY_ERR_UNKNOWN_CHOICE */
literal|"has unknown component: "
block|,
comment|/* PEPY_ERR_UNK_COMP */
literal|"initialization fails"
block|,
comment|/* PEPY_ERR_INIT_FAILED */
literal|"invalid choice selected: "
block|,
comment|/* PEPY_ERR_INVALID_CHOICE */
literal|"missing "
block|,
comment|/* PEPY_ERR_MISSING */
literal|"out of memory"
block|,
comment|/* PEPY_ERR_NOMEM  */
literal|"too many elements for tagged "
block|,
comment|/* PEPY_ERR_TOO_MANY_TAGGED */
literal|"warning: extra or duplicate members present in SET"
block|,
comment|/* PEPY_ERR_EXTRA_MEMBERS */
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

