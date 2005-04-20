begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|id
index|[]
init|=
literal|"@(#)$Id: t_snprintf.c,v 8.4 2001/09/23 03:35:41 ca Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! lint */
end_comment

begin_define
define|#
directive|define
name|TEST_STRING
value|"1234567890"
end_define

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|r
decl_stmt|;
name|char
name|buf
index|[
literal|5
index|]
decl_stmt|;
name|r
operator|=
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
literal|"%s"
argument_list|,
name|TEST_STRING
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf
index|[
sizeof|sizeof
name|buf
operator|-
literal|1
index|]
operator|!=
literal|'\0'
operator|||
name|r
operator|!=
name|strlen
argument_list|(
name|TEST_STRING
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Add the following to devtools/Site/site.config.m4:\n\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"APPENDDEF(`confENVDEF', `-DSNPRINTF_IS_BROKEN=1')\n\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EX_OSERR
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"snprintf() appears to work properly\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EX_OK
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

