begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rcmd_srch.c: search a lookup table: return string value */
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
literal|"$Header: /f/osi/compat/RCS/rcmd_srch.c,v 7.1 91/02/22 09:15:42 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/compat/RCS/rcmd_srch.c,v 7.1 91/02/22 09:15:42 mrose Interim $  *  *  * $Log:	rcmd_srch.c,v $  * Revision 7.1  91/02/22  09:15:42  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:23:22  mrose  * Release 6.0  *   */
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

begin_function
name|char
modifier|*
name|rcmd_srch
parameter_list|(
name|val
parameter_list|,
name|cmd
parameter_list|)
specifier|register
name|int
name|val
decl_stmt|;
specifier|register
name|CMD_TABLE
modifier|*
name|cmd
decl_stmt|;
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
name|val
operator|==
name|cmd
operator|->
name|cmd_value
condition|)
return|return
operator|(
name|cmd
operator|->
name|cmd_key
operator|)
return|;
return|return
operator|(
name|NULLCP
operator|)
return|;
block|}
end_function

end_unit

