begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ps_error.c - presentation stream error to string */
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
literal|"$Header: /f/osi/psap/RCS/ps_error.c,v 7.3 91/02/22 09:36:32 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/ps_error.c,v 7.3 91/02/22 09:36:32 mrose Interim $  *  *  * $Log:	ps_error.c,v $  * Revision 7.3  91/02/22  09:36:32  mrose  * Interim 6.8  *   * Revision 7.2  91/01/11  07:09:10  mrose  * jpo  *   * Revision 7.1  91/01/07  12:40:35  mrose  * update  *   * Revision 7.0  89/11/23  22:13:20  mrose  * Release 6.0  *   */
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
file|"psap.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ps_errorlist
index|[]
init|=
block|{
literal|"Error 0"
block|,
literal|"Overflow in ID"
block|,
literal|"Overflow in length"
block|,
literal|"Out of memory"
block|,
literal|"End of file"
block|,
literal|"End of file reading extended ID"
block|,
literal|"End of file reading extended length"
block|,
literal|"Length Mismatch"
block|,
literal|"Truncated"
block|,
literal|"Indefinite length in primitive form"
block|,
literal|"I/O error"
block|,
literal|"Extraneous octets"
block|,
literal|"XXX"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ps_maxerror
init|=
sizeof|sizeof
name|ps_errorlist
operator|/
sizeof|sizeof
name|ps_errorlist
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|char
modifier|*
name|ps_error
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
specifier|static
name|char
name|buffer
index|[
literal|30
index|]
decl_stmt|;
if|if
condition|(
name|c
operator|<
name|ps_maxerror
operator|&&
operator|(
name|bp
operator|=
name|ps_errorlist
index|[
name|c
index|]
operator|)
condition|)
return|return
name|bp
return|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"Error %d"
argument_list|,
name|c
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_function

end_unit

