begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ronotabort.c - RONOT: bail-out routine which logs abort to rosap log */
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
literal|"$Header: /f/osi/ronot/RCS/ronotabort.c,v 7.2 91/02/22 09:50:29 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/ronot/RCS/ronotabort.c,v 7.2 91/02/22 09:50:29 mrose Interim $  *  *  * $Log:	ronotabort.c,v $  * Revision 7.2  91/02/22  09:50:29  mrose  * Interim 6.8  *   * Revision 7.1  90/07/26  14:33:53  mrose  * template  *   */
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
file|"tailor.h"
end_include

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_include
include|#
directive|include
file|"rosap.h"
end_include

begin_include
include|#
directive|include
file|"ronot.h"
end_include

begin_comment
comment|/*
comment|RO-ABORT.REQUEST */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|RoBindUAbort
parameter_list|(
name|sd
parameter_list|,
name|rni
parameter_list|)
name|int
name|sd
decl_stmt|;
name|struct
name|RoNOTindication
modifier|*
name|rni
decl_stmt|;
block|{
name|int
name|result
decl_stmt|;
name|struct
name|AcSAPindication
name|aci_s
decl_stmt|;
name|struct
name|AcSAPindication
modifier|*
name|aci
init|=
operator|&
operator|(
name|aci_s
operator|)
decl_stmt|;
name|struct
name|AcSAPabort
modifier|*
name|aca
init|=
operator|&
operator|(
name|aci
operator|->
name|aci_abort
operator|)
decl_stmt|;
name|LLOG
argument_list|(
name|rosap_log
argument_list|,
name|LLOG_EXCEPTIONS
argument_list|,
operator|(
literal|"RO-ABORT-BIND.REQUEST called on %d"
operator|,
name|sd
operator|)
argument_list|)
expr_stmt|;
name|result
operator|=
name|AcUAbortRequest
argument_list|(
name|sd
argument_list|,
name|NULLPEP
argument_list|,
literal|0
argument_list|,
name|aci
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|!=
name|OK
condition|)
block|{
name|LLOG
argument_list|(
name|rosap_log
argument_list|,
name|LLOG_EXCEPTIONS
argument_list|,
operator|(
literal|"RO-ABORT-BIND.REQUEST failed on %d"
operator|,
name|sd
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|acs2ronotlose
argument_list|(
name|rni
argument_list|,
literal|"RO-ABORT-BIND.REQUEST"
argument_list|,
name|aca
argument_list|)
operator|)
return|;
block|}
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

end_unit

