begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dsapabort.c - DSAP: Lose the binding identified by the descriptor */
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
literal|"$Header: /f/osi/dsap/net/RCS/dsapabort.c,v 7.1 91/02/22 09:21:13 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/dsap/net/RCS/dsapabort.c,v 7.1 91/02/22 09:21:13 mrose Interim $  *  *  * $Log:	dsapabort.c,v $  * Revision 7.1  91/02/22  09:21:13  mrose  * Interim 6.8  *   * Revision 7.0  90/07/26  14:45:36  mrose  * *** empty log message ***  *   */
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
file|"logger.h"
end_include

begin_include
include|#
directive|include
file|"quipu/dsap.h"
end_include

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|log_dsap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|RO-ABORT.REQUEST */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|DUAbortRequest
parameter_list|(
name|sd
parameter_list|,
name|di
parameter_list|)
name|int
name|sd
decl_stmt|;
name|struct
name|DSAPindication
modifier|*
name|di
decl_stmt|;
block|{
name|int
name|result
decl_stmt|;
name|struct
name|RoNOTindication
name|rni_s
decl_stmt|;
name|struct
name|RoNOTindication
modifier|*
name|rni
init|=
operator|&
operator|(
name|rni_s
operator|)
decl_stmt|;
name|LLOG
argument_list|(
name|log_dsap
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
name|watch_dog
argument_list|(
literal|"RoBindUAbort"
argument_list|)
expr_stmt|;
name|result
operator|=
name|RoBindUAbort
argument_list|(
name|sd
argument_list|,
name|rni
argument_list|)
expr_stmt|;
name|watch_dog_reset
argument_list|()
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
name|log_dsap
argument_list|,
name|LLOG_EXCEPTIONS
argument_list|,
operator|(
literal|"D-ABORT-BIND.REQUEST failed on %d"
operator|,
name|sd
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|ronot2dsaplose
argument_list|(
name|di
argument_list|,
literal|"D-ABORT-BIND.REQUEST"
argument_list|,
name|rni
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

