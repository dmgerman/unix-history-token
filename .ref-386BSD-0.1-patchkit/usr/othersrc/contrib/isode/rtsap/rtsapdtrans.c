begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rtsapdtrans.c - RTPM: set downtrans upcall */
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
literal|"$Header: /f/osi/rtsap/RCS/rtsapdtrans.c,v 7.1 91/02/22 09:42:37 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/rtsap/RCS/rtsapdtrans.c,v 7.1 91/02/22 09:42:37 mrose Interim $  *  *  * $Log:	rtsapdtrans.c,v $  * Revision 7.1  91/02/22  09:42:37  mrose  * Interim 6.8  *   * Revision 6.0  89/03/18  23:43:26  mrose  * Release 5.0  *   */
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
comment|set downtrans upcall */
end_comment

begin_function
name|int
name|RtSetDownTrans
parameter_list|(
name|sd
parameter_list|,
name|fnx
parameter_list|,
name|rti
parameter_list|)
name|int
name|sd
decl_stmt|;
name|IFP
name|fnx
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
name|acb
operator|->
name|acb_downtrans
operator|=
name|fnx
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
name|OK
return|;
block|}
end_function

end_unit

