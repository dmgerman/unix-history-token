begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* explode.c - explode octets into ascii */
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
literal|"$Header: /f/osi/compat/RCS/explode.c,v 7.1 91/02/22 09:15:09 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/compat/RCS/explode.c,v 7.1 91/02/22 09:15:09 mrose Interim $  *  *  * $Log:	explode.c,v $  * Revision 7.1  91/02/22  09:15:09  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:22:59  mrose  * Release 6.0  *   */
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
file|"general.h"
end_include

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_comment
comment|/*
comment|DATA */
end_comment

begin_decl_stmt
specifier|static
name|char
name|nib2hex
index|[
literal|0x10
index|]
init|=
block|{
literal|'0'
block|,
literal|'1'
block|,
literal|'2'
block|,
literal|'3'
block|,
literal|'4'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'7'
block|,
literal|'8'
block|,
literal|'9'
block|,
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
literal|'f'
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|int
name|explode
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
specifier|register
name|char
modifier|*
name|a
decl_stmt|;
specifier|register
name|u_char
modifier|*
name|b
decl_stmt|;
specifier|register
name|int
name|n
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|u_char
name|c
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
name|i
operator|++
control|)
block|{
name|c
operator|=
operator|*
name|b
operator|++
expr_stmt|;
operator|*
name|a
operator|++
operator|=
name|nib2hex
index|[
operator|(
name|c
operator|&
literal|0xf0
operator|)
operator|>>
literal|4
index|]
expr_stmt|;
operator|*
name|a
operator|++
operator|=
name|nib2hex
index|[
operator|(
name|c
operator|&
literal|0x0f
operator|)
index|]
expr_stmt|;
block|}
operator|*
name|a
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|n
operator|*
literal|2
operator|)
return|;
block|}
end_function

end_unit

