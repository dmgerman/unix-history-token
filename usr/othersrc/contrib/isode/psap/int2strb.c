begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* int2strb.c - integer to string of bits */
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
literal|"$Header: /f/osi/psap/RCS/int2strb.c,v 7.1 91/02/22 09:35:41 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/int2strb.c,v 7.1 91/02/22 09:35:41 mrose Interim $  *  *  * $Log:	int2strb.c,v $  * Revision 7.1  91/02/22  09:35:41  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:12:39  mrose  * Release 6.0  *   */
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

begin_function
name|char
modifier|*
name|int2strb
parameter_list|(
name|n
parameter_list|,
name|len
parameter_list|)
specifier|register
name|int
name|n
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|static
name|char
name|buffer
index|[
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|+
literal|1
index|]
decl_stmt|;
name|bzero
argument_list|(
name|buffer
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|n
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
name|buffer
index|[
name|i
operator|/
literal|8
index|]
operator||=
operator|(
literal|1
operator|<<
operator|(
literal|7
operator|-
operator|(
name|i
operator|%
literal|8
operator|)
operator|)
operator|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_function

end_unit

