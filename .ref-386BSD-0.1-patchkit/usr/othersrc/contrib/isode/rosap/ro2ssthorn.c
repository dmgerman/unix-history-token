begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ro2ssthorn.c - ROPM: interface for THORN */
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
literal|"$Header: /f/osi/rosap/RCS/ro2ssthorn.c,v 7.1 91/02/22 09:41:24 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/rosap/RCS/ro2ssthorn.c,v 7.1 91/02/22 09:41:24 mrose Interim $  *  *  * $Log:	ro2ssthorn.c,v $  * Revision 7.1  91/02/22  09:41:24  mrose  * Interim 6.8  *   * Revision 6.0  89/03/18  23:42:20  mrose  * Release 5.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"ropkt.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_function
specifier|static
name|PE
name|qb2Rpe
parameter_list|(
name|qb
parameter_list|,
name|len
parameter_list|,
name|result
parameter_list|)
specifier|register
name|struct
name|qbuf
modifier|*
name|qb
decl_stmt|;
name|int
name|len
decl_stmt|;
name|int
modifier|*
name|result
decl_stmt|;
block|{
return|return
name|qb2pe
argument_list|(
name|qb
argument_list|,
name|len
argument_list|,
literal|2
argument_list|,
name|result
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*
comment|modify underling service */
end_comment

begin_function
name|int
name|RoSetThorn
parameter_list|(
name|sd
parameter_list|,
name|roi
parameter_list|)
name|int
name|sd
decl_stmt|;
name|struct
name|RoSAPindication
modifier|*
name|roi
decl_stmt|;
block|{
name|SBV
name|smask
decl_stmt|;
name|int
name|result
decl_stmt|;
specifier|register
name|struct
name|assocblk
modifier|*
name|acb
decl_stmt|;
name|missingP
argument_list|(
name|roi
argument_list|)
expr_stmt|;
name|smask
operator|=
name|sigioblock
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|acb
operator|=
name|findacblk
argument_list|(
name|sd
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|sigiomask
argument_list|(
name|smask
argument_list|)
expr_stmt|;
return|return
name|rosaplose
argument_list|(
name|roi
argument_list|,
name|ROS_PARAMETER
argument_list|,
name|NULLCP
argument_list|,
literal|"invalid association descriptor"
argument_list|)
return|;
block|}
if|if
condition|(
name|acb
operator|->
name|acb_flags
operator|&
name|ACB_ROS
condition|)
block|{
name|acb
operator|->
name|acb_getosdu
operator|=
name|qb2Rpe
expr_stmt|;
name|result
operator|=
name|OK
expr_stmt|;
block|}
else|else
name|result
operator|=
name|rosaplose
argument_list|(
name|roi
argument_list|,
name|ROS_OPERATION
argument_list|,
name|NULLCP
argument_list|,
literal|"not an association descriptor for ROS"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sigiomask
argument_list|(
name|smask
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

end_unit

