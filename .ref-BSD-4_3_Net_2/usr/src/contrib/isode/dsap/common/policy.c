begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* policy.c - SecurityPolicy abstract syntax  */
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
literal|"$Header: /f/osi/dsap/common/RCS/policy.c,v 7.1 91/02/22 09:19:58 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/dsap/common/RCS/policy.c,v 7.1 91/02/22 09:19:58 mrose Interim $  *  *  * $Log:	policy.c,v $  * Revision 7.1  91/02/22  09:19:58  mrose  * Interim 6.8  *   * Revision 7.0  90/08/24  12:10:43  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"cmd_srch.h"
end_include

begin_include
include|#
directive|include
file|"quipu/policy.h"
end_include

begin_comment
comment|/*  * This syntax is not yet implemented. However, the following routines for  * handling security policies are used by some applications.  */
end_comment

begin_decl_stmt
specifier|static
name|CMD_TABLE
name|permtab
index|[]
init|=
block|{
literal|"detect"
block|,
name|POLICY_ACCESS_DETECT
block|,
literal|"read"
block|,
name|POLICY_ACCESS_READ
block|,
literal|"add"
block|,
name|POLICY_ACCESS_ADD
block|,
literal|"write"
block|,
name|POLICY_ACCESS_WRITE
block|,
literal|"all"
block|,
name|POLICY_ACCESS_ALL
block|,
literal|"none"
block|,
literal|0
block|,
name|NULLCP
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|unsigned
name|str2permission
parameter_list|(
name|str
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
block|{
name|char
modifier|*
name|cp
decl_stmt|;
name|unsigned
name|result
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|str
operator|&&
operator|(
operator|*
name|str
operator|!=
literal|'\0'
operator|)
condition|)
block|{
name|cp
operator|=
name|index
argument_list|(
name|str
argument_list|,
literal|'$'
argument_list|)
expr_stmt|;
if|if
condition|(
name|cp
operator|!=
name|NULLCP
condition|)
operator|*
name|cp
operator|++
operator|=
literal|'\0'
expr_stmt|;
name|result
operator||=
name|cmd_srch
argument_list|(
name|str
argument_list|,
name|permtab
argument_list|)
expr_stmt|;
name|str
operator|=
name|cp
expr_stmt|;
block|}
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

end_unit

