begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rtsaptrans.c - RTPM: transfer */
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
literal|"$Header: /f/osi/rtsap/RCS/rtsaptrans.c,v 7.1 91/02/22 09:42:43 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/rtsap/RCS/rtsaptrans.c,v 7.1 91/02/22 09:42:43 mrose Interim $  *  *  * $Log:	rtsaptrans.c,v $  * Revision 7.1  91/02/22  09:42:43  mrose  * Interim 6.8  *   * Revision 6.0  89/03/18  23:43:32  mrose  * Release 5.0  *   */
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
file|"rtpkt.h"
end_include

begin_comment
comment|/*
comment|RT-TRANSFER.REQUEST */
end_comment

begin_function
name|int
name|RtTransferRequest
parameter_list|(
name|sd
parameter_list|,
name|data
parameter_list|,
name|secs
parameter_list|,
name|rti
parameter_list|)
name|int
name|sd
decl_stmt|;
name|PE
name|data
decl_stmt|;
name|int
name|secs
decl_stmt|;
name|struct
name|RtSAPindication
modifier|*
name|rti
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
name|rti
argument_list|)
expr_stmt|;
name|smask
operator|=
name|sigioblock
argument_list|()
expr_stmt|;
name|rtsapPsig
argument_list|(
name|acb
argument_list|,
name|sd
argument_list|)
expr_stmt|;
if|if
condition|(
name|data
operator|==
name|NULLPE
operator|&&
name|acb
operator|->
name|acb_downtrans
operator|==
name|NULLIFP
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
name|rtsaplose
argument_list|(
name|rti
argument_list|,
name|RTS_PARAMETER
argument_list|,
name|NULLCP
argument_list|,
literal|"mandatory parameter \"data\" missing"
argument_list|)
return|;
block|}
name|result
operator|=
call|(
modifier|*
name|acb
operator|->
name|acb_transferequest
call|)
argument_list|(
name|acb
argument_list|,
name|data
argument_list|,
name|secs
argument_list|,
name|rti
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

