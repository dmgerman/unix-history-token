begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* report.c -- event reporting */
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
literal|"$Header: /f/osi/others/callback/RCS/report.c,v 7.1 91/02/22 09:26:41 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/others/callback/RCS/report.c,v 7.1 91/02/22 09:26:41 mrose Interim $  *  *  * $Log:	report.c,v $  * Revision 7.1  91/02/22  09:26:41  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:58:13  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<varargs.h>
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
file|"logger.h"
end_include

begin_decl_stmt
specifier|static
name|LLog
name|_pgm_log
init|=
block|{
literal|"callback.log"
block|,
name|NULLCP
block|,
name|NULLCP
block|,
name|LLOG_FATAL
operator||
name|LLOG_EXCEPTIONS
operator||
name|LLOG_NOTICE
block|,
name|LLOG_FATAL
block|,
operator|-
literal|1
block|,
name|LLOGCLS
operator||
name|LLOGCRT
operator||
name|LLOGZER
block|,
name|NOTOK
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|LLog
modifier|*
name|pgm_log
init|=
operator|&
name|_pgm_log
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_macro
name|reportailor
argument_list|(
argument|myname
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|myname
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|isodetailor
argument_list|(
name|myname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ll_hdinit
argument_list|(
name|pgm_log
argument_list|,
name|myname
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*
comment|*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_function
name|void
name|adios
parameter_list|(
name|va_alist
parameter_list|)
function|va_dcl
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|_ll_log
argument_list|(
name|pgm_log
argument_list|,
name|LLOG_FATAL
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VARARGS */
end_comment

begin_function
name|void
name|adios
parameter_list|(
name|what
parameter_list|,
name|fmt
parameter_list|)
name|char
modifier|*
name|what
decl_stmt|,
decl|*
name|fmt
decl_stmt|;
end_function

begin_block
block|{
name|adios
argument_list|(
name|what
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_function
name|void
name|advise
parameter_list|(
name|va_alist
parameter_list|)
function|va_dcl
block|{
name|int
name|code
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|code
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|int
argument_list|)
expr_stmt|;
name|_ll_log
argument_list|(
name|pgm_log
argument_list|,
name|code
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VARARGS */
end_comment

begin_function
name|void
name|advise
parameter_list|(
name|code
parameter_list|,
name|what
parameter_list|,
name|fmt
parameter_list|)
name|char
modifier|*
name|what
decl_stmt|,
decl|*
name|fmt
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|advise
argument_list|(
name|code
argument_list|,
name|what
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

