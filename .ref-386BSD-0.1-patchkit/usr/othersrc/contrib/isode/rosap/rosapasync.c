begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rosapasync.c - ROPM: set asynchronous events */
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
literal|"$Header: /f/osi/rosap/RCS/rosapasync.c,v 7.2 91/02/22 09:41:28 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/rosap/RCS/rosapasync.c,v 7.2 91/02/22 09:41:28 mrose Interim $  *  * Based on an TCP-based implementation by George Michaelson of University  * College London.  *  *  * $Log:	rosapasync.c,v $  * Revision 7.2  91/02/22  09:41:28  mrose  * Interim 6.8  *   * Revision 7.1  90/08/08  14:13:55  mrose  * update  *   * Revision 6.0  89/03/18  23:42:23  mrose  * Release 5.0  *   */
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
comment|define vectors for INDICATION events */
end_comment

begin_function
name|int
name|RoSetIndications
parameter_list|(
name|sd
parameter_list|,
name|indication
parameter_list|,
name|roi
parameter_list|)
name|int
name|sd
decl_stmt|;
name|IFP
name|indication
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
name|_iosignals_set
operator|=
literal|1
expr_stmt|;
name|smask
operator|=
name|sigioblock
argument_list|()
expr_stmt|;
name|rosapPsig
argument_list|(
name|acb
argument_list|,
name|sd
argument_list|)
expr_stmt|;
if|if
condition|(
name|acb
operator|->
name|acb_apdu
operator|||
operator|(
name|acb
operator|->
name|acb_flags
operator|&
name|ACB_CLOSING
operator|)
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
name|ROS_WAITING
argument_list|,
name|NULLCP
argument_list|,
name|NULLCP
argument_list|)
return|;
block|}
name|result
operator|=
call|(
modifier|*
name|acb
operator|->
name|acb_rosetindications
call|)
argument_list|(
name|acb
argument_list|,
name|indication
argument_list|,
name|roi
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

