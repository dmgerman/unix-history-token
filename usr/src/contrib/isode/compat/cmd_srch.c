begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cmd_srch.c - search a lookup table: return numeric value */
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
literal|"$Header: /f/osi/compat/RCS/cmd_srch.c,v 7.1 91/02/22 09:15:06 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/compat/RCS/cmd_srch.c,v 7.1 91/02/22 09:15:06 mrose Interim $  *  *  * $Log:	cmd_srch.c,v $  * Revision 7.1  91/02/22  09:15:06  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:22:58  mrose  * Release 6.0  *   */
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
file|"manifest.h"
end_include

begin_include
include|#
directive|include
file|"cmd_srch.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* map a string onto a value */
end_comment

begin_expr_stmt
name|cmd_srch
argument_list|(
name|str
argument_list|,
name|cmd
argument_list|)
specifier|register
name|char
operator|*
name|str
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|CMD_TABLE
modifier|*
name|cmd
decl_stmt|;
end_decl_stmt

begin_block
block|{
for|for
control|(
init|;
name|cmd
operator|->
name|cmd_key
operator|!=
name|NULLCP
condition|;
name|cmd
operator|++
control|)
if|if
condition|(
name|lexequ
argument_list|(
name|str
argument_list|,
name|cmd
operator|->
name|cmd_key
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|cmd
operator|->
name|cmd_value
operator|)
return|;
return|return
operator|(
name|cmd
operator|->
name|cmd_value
operator|)
return|;
block|}
end_block

end_unit

