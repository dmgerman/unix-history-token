begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * $FreeBSD$  * $Source: /usr/src/eBones/rkinitd/RCS/util.c,v $  * $Author: dglo $  *  * This file contains general rkinit server utilities.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SABER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
name|defined
argument_list|(
name|RCS_HDRS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint || SABER || LOCORE || RCS_HDRS */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<rkinit.h>
end_include

begin_include
include|#
directive|include
file|<rkinit_err.h>
end_include

begin_include
include|#
directive|include
file|<rkinit_private.h>
end_include

begin_include
include|#
directive|include
file|"rkinitd.h"
end_include

begin_decl_stmt
specifier|static
name|char
name|errbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|rpc_exchange_version_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|int
name|choose_version
parameter_list|(
name|int
modifier|*
name|version
parameter_list|)
else|#
directive|else
function|int choose_version
parameter_list|(
name|version
parameter_list|)
name|int
modifier|*
name|version
decl_stmt|;
endif|#
directive|endif
comment|/* __STDC__ */
block|{
name|int
name|c_lversion
decl_stmt|;
comment|/* lowest version number client supports */
name|int
name|c_hversion
decl_stmt|;
comment|/* highest version number client supports */
name|int
name|status
init|=
name|RKINIT_SUCCESS
decl_stmt|;
name|rpc_exchange_version_info
argument_list|(
operator|&
name|c_lversion
argument_list|,
operator|&
name|c_hversion
argument_list|,
name|RKINIT_LVERSION
argument_list|,
name|RKINIT_HVERSION
argument_list|)
expr_stmt|;
operator|*
name|version
operator|=
name|min
argument_list|(
name|RKINIT_HVERSION
argument_list|,
name|c_hversion
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|version
operator|<
name|max
argument_list|(
name|RKINIT_LVERSION
argument_list|,
name|c_lversion
argument_list|)
condition|)
block|{
name|sprintf
argument_list|(
name|errbuf
argument_list|,
literal|"Can't run version %d client against version %d server."
argument_list|,
name|c_hversion
argument_list|,
name|RKINIT_HVERSION
argument_list|)
expr_stmt|;
name|rkinit_errmsg
argument_list|(
name|errbuf
argument_list|)
expr_stmt|;
return|return
operator|(
name|RKINIT_VERSION
operator|)
return|;
block|}
return|return
operator|(
name|status
operator|)
return|;
block|}
end_function

end_unit

