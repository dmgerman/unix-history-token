begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* py_advise.c - standard "advise" routine for pepsy/pepy */
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
literal|"$Header: /f/osi/pepsy/RCS/py_advise.c,v 7.2 91/02/22 09:50:02 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/pepsy/RCS/py_advise.c,v 7.2 91/02/22 09:50:02 mrose Interim $  *  *  * $Log:	py_advise.c,v $  * Revision 7.2  91/02/22  09:50:02  mrose  * Interim 6.8  *   * Revision 7.1  90/07/09  14:53:19  mrose  * sync  *   * Revision 7.0  89/11/23  22:12:05  mrose  * Release 6.0  *   */
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
file|<varargs.h>
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|PY_pepy
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|PY_advise
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
name|asprintf
argument_list|(
name|PY_pepy
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
name|PY_advise
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
name|PY_advise
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

end_unit

