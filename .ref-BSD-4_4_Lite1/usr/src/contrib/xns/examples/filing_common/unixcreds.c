begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"$Header: unixcreds.c,v 1.2 87/04/01 10:12:52 ed Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/*  * Copyright (c) 1986, 1987 Xerox Corporation.  */
end_comment

begin_comment
comment|/* $Log:	unixcreds.c,v $  * Revision 1.2  87/04/01  10:12:52  ed  * added Filing version 5.  *   * Revision 1.1  87/01/14  11:28:25  ed  * Initial revision  *   */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netns/ns.h>
end_include

begin_include
include|#
directive|include
file|<netns/sp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FILING4
end_ifdef

begin_include
include|#
directive|include
file|"filingV4.h"
end_include

begin_include
include|#
directive|include
file|"clearinghouseV2.h"
end_include

begin_include
include|#
directive|include
file|"authenticationV2.h"
end_include

begin_endif
endif|#
directive|endif
endif|FILING4
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FILING5
end_ifdef

begin_include
include|#
directive|include
file|"filingV5.h"
end_include

begin_include
include|#
directive|include
file|"clearinghouseV2.h"
end_include

begin_include
include|#
directive|include
file|"authenticationV2.h"
end_include

begin_endif
endif|#
directive|endif
endif|FILING5
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FILING6
end_ifdef

begin_include
include|#
directive|include
file|"filingV6.h"
end_include

begin_include
include|#
directive|include
file|"clearinghouseV3.h"
end_include

begin_include
include|#
directive|include
file|"authenticationV3.h"
end_include

begin_endif
endif|#
directive|endif
endif|FILING6
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FILINGSUBSET1
end_ifdef

begin_include
include|#
directive|include
file|"filingsubsetV1.h"
end_include

begin_include
include|#
directive|include
file|"clearinghouseV3.h"
end_include

begin_include
include|#
directive|include
file|"authenticationV3.h"
end_include

begin_endif
endif|#
directive|endif
endif|FILINGSUBSET1
end_endif

begin_include
include|#
directive|include
file|<xnscourier/filing_server.h>
end_include

begin_include
include|#
directive|include
file|<xnscourier/CH.h>
end_include

begin_function_decl
specifier|extern
name|char
modifier|*
name|AttrToString
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|FILE
modifier|*
name|msgs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|DEBUG
end_endif

begin_macro
name|get_name_and_pwd
argument_list|(
argument|creds
argument_list|,
argument|name
argument_list|,
argument|pwd
argument_list|)
end_macro

begin_decl_stmt
name|FILING_SecondaryCredentials
modifier|*
name|creds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|pwd
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
name|FILING_SecondaryItem
modifier|*
name|item
decl_stmt|;
name|Boolean
name|gotname
init|=
name|FALSE
decl_stmt|,
name|gotpwd
init|=
name|FALSE
decl_stmt|;
name|char
modifier|*
name|user
decl_stmt|,
modifier|*
name|pass
decl_stmt|;
if|if
condition|(
name|creds
operator|->
name|designator
operator|!=
name|FILING_simple
condition|)
block|{
name|ReturnAuthenticationError
argument_list|(
name|FILING_secondaryCredentialsRequired
argument_list|)
expr_stmt|;
comment|/* NOT REACHED */
block|}
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|msgs
argument_list|,
literal|"%n secondary types\n"
argument_list|,
name|creds
operator|->
name|FILING_simple_case
operator|.
name|length
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
if|if
condition|(
name|creds
operator|->
name|FILING_simple_case
operator|.
name|length
operator|<=
literal|0
condition|)
block|{
name|ReturnAuthenticationError
argument_list|(
name|FILING_secondaryCredentialsRequired
argument_list|)
expr_stmt|;
comment|/* NOT REACHED */
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|creds
operator|->
name|FILING_simple_case
operator|.
name|length
condition|;
name|i
operator|++
control|)
block|{
name|item
operator|=
operator|&
name|creds
operator|->
name|FILING_simple_case
operator|.
name|sequence
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|item
operator|->
name|type
operator|==
name|FILING_userName
condition|)
block|{
name|gotname
operator|=
name|TRUE
expr_stmt|;
name|user
operator|=
name|AttrToString
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|name
argument_list|,
name|user
argument_list|)
expr_stmt|;
name|clear_String
argument_list|(
operator|&
name|user
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|item
operator|->
name|type
operator|==
name|FILING_userPassword
condition|)
block|{
name|gotpwd
operator|=
name|TRUE
expr_stmt|;
name|pass
operator|=
name|AttrToString
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|pwd
argument_list|,
name|pass
argument_list|)
expr_stmt|;
name|clear_String
argument_list|(
operator|&
name|pass
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ReturnAuthenticationError
argument_list|(
name|FILING_secondaryCredentialsTypeInvalid
argument_list|)
expr_stmt|;
comment|/* NOT REACHED */
block|}
block|}
if|if
condition|(
operator|!
name|gotname
operator|&&
operator|!
name|gotpwd
condition|)
block|{
name|ReturnAuthenticationError
argument_list|(
name|FILING_secondaryCredentialsRequired
argument_list|)
expr_stmt|;
comment|/* NOT REACHED */
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

end_unit

