begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dsapunbind2.c - DSAP: maps D-UNBIND mapping onto RO-UNBIND */
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
literal|"$Header: /f/osi/dsap/net/RCS/dsapunbind2.c,v 7.1 91/02/22 09:21:29 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/dsap/net/RCS/dsapunbind2.c,v 7.1 91/02/22 09:21:29 mrose Interim $  *  *  * $Log:	dsapunbind2.c,v $  * Revision 7.1  91/02/22  09:21:29  mrose  * Interim 6.8  *   * Revision 7.0  90/07/26  14:46:02  mrose  * *** empty log message ***  *   */
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
file|"quipu/dsap.h"
end_include

begin_comment
comment|/*
comment|D-UNBIND.ACCEPT */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|DUnBindAccept
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
name|watch_dog
argument_list|(
literal|"RoUnBindResult"
argument_list|)
expr_stmt|;
name|result
operator|=
name|RoUnBindResult
argument_list|(
name|sd
argument_list|,
name|NULLPE
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
operator|==
name|NOTOK
condition|)
block|{
operator|(
name|void
operator|)
name|ronot2dsaplose
argument_list|(
name|di
argument_list|,
literal|"D-UNBIND.ACCEPT"
argument_list|,
name|rni
argument_list|)
expr_stmt|;
return|return
operator|(
name|NOTOK
operator|)
return|;
block|}
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_comment
comment|/*
comment|D-UNBIND.REJECT */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|DUnBindReject
parameter_list|(
name|sd
parameter_list|,
name|status
parameter_list|,
name|reason
parameter_list|,
name|di
parameter_list|)
name|int
name|sd
decl_stmt|;
name|int
name|status
decl_stmt|;
name|int
name|reason
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
name|watch_dog
argument_list|(
literal|"DUnBindReject"
argument_list|)
expr_stmt|;
name|result
operator|=
name|RoUnBindReject
argument_list|(
name|sd
argument_list|,
name|status
argument_list|,
name|reason
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
operator|==
name|NOTOK
condition|)
block|{
operator|(
name|void
operator|)
name|ronot2dsaplose
argument_list|(
name|di
argument_list|,
literal|"D-UNBIND.REJECT"
argument_list|,
name|rni
argument_list|)
expr_stmt|;
return|return
operator|(
name|NOTOK
operator|)
return|;
block|}
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

end_unit

