begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* strdup.c - create a duplicate copy of the given string */
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
literal|"$Header: /f/osi/compat/RCS/strdup.c,v 7.3 91/02/22 09:16:05 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/compat/RCS/strdup.c,v 7.3 91/02/22 09:16:05 mrose Interim $  *  *  * $Log:	strdup.c,v $  * Revision 7.3  91/02/22  09:16:05  mrose  * Interim 6.8  *   * Revision 7.2  90/11/04  19:14:52  mrose  * update  *   * Revision 7.1  90/10/15  18:19:58  mrose  * sync  *   * Revision 7.0  89/11/23  21:23:40  mrose  * Release 6.0  *   */
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
name|strdup
parameter_list|(
name|str
parameter_list|)
specifier|register
name|char
modifier|*
name|str
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
call|(
name|unsigned
call|)
argument_list|(
name|strlen
argument_list|(
name|str
argument_list|)
operator|+
literal|1
argument_list|)
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
literal|"strdup malloc() failure"
operator|)
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
block|}
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|ptr
argument_list|,
name|str
argument_list|)
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_function

end_unit

