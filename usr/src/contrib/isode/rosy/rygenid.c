begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rygenid.c - ROSY: generate unique invoke ID */
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
literal|"$Header: /f/osi/rosy/RCS/rygenid.c,v 7.1 91/02/22 09:42:01 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/rosy/RCS/rygenid.c,v 7.1 91/02/22 09:42:01 mrose Interim $  *  *  * $Log:	rygenid.c,v $  * Revision 7.1  91/02/22  09:42:01  mrose  * Interim 6.8  *   * Revision 6.0  89/03/18  23:42:53  mrose  * Release 5.0  *   */
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
file|"rosy.h"
end_include

begin_comment
comment|/*
comment|generate unique invoke ID */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|RyGenID
parameter_list|(
name|sd
parameter_list|)
name|int
name|sd
decl_stmt|;
block|{
specifier|static
name|int
name|id
init|=
literal|0
decl_stmt|;
return|return
operator|(
operator|++
name|id
operator|)
return|;
block|}
end_function

end_unit

