begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* smalloc.c - error checking malloc */
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
literal|"$Header: /f/osi/compat/RCS/smalloc.c,v 7.1 91/02/22 09:15:52 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/compat/RCS/smalloc.c,v 7.1 91/02/22 09:15:52 mrose Interim $  *  *  * $Log:	smalloc.c,v $  * Revision 7.1  91/02/22  09:15:52  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:23:33  mrose  * Release 6.0  *   */
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|char
modifier|*
name|smalloc
parameter_list|(
name|size
parameter_list|)
name|int
name|size
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
operator|(
name|ptr
operator|=
name|malloc
argument_list|(
operator|(
name|unsigned
operator|)
name|size
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|LLOG
argument_list|(
name|compat_log
argument_list|,
name|LLOG_FATAL
argument_list|,
operator|(
literal|"malloc() failure"
operator|)
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
block|}
return|return
operator|(
name|ptr
operator|)
return|;
block|}
end_function

end_unit

