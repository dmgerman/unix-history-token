begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* converts a bit string - output of bitstr2strb() - to an integer */
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
literal|"$Header: /f/osi/psap/RCS/strb2int.c,v 7.1 91/02/22 09:37:12 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/strb2int.c,v 7.1 91/02/22 09:37:12 mrose Interim $  *  *  * $Log:	strb2int.c,v $  * Revision 7.1  91/02/22  09:37:12  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:51  mrose  * Release 6.0  *   */
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

begin_function
name|int
name|strb2int
parameter_list|(
name|cp
parameter_list|,
name|len
parameter_list|)
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
specifier|register
name|int
name|len
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|bit
decl_stmt|,
name|mask
decl_stmt|,
name|n
decl_stmt|;
name|n
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|bit
operator|=
operator|(
operator|*
name|cp
operator|&
literal|0xff
operator|)
operator|,
name|i
operator|=
literal|0
operator|,
name|mask
operator|=
literal|1
operator|<<
operator|(
name|j
operator|=
literal|7
operator|)
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|bit
operator|&
name|mask
condition|)
name|n
operator||=
literal|1
operator|<<
name|i
expr_stmt|;
if|if
condition|(
name|j
operator|--
operator|==
literal|0
condition|)
name|bit
operator|=
operator|*
operator|++
name|cp
operator|&
literal|0xff
operator|,
name|mask
operator|=
literal|1
operator|<<
operator|(
name|j
operator|=
literal|7
operator|)
expr_stmt|;
else|else
name|mask
operator|>>=
literal|1
expr_stmt|;
block|}
return|return
name|n
return|;
block|}
end_function

end_unit

