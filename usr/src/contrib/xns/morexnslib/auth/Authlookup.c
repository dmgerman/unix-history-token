begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986, 1987 Xerox Corporation.  */
end_comment

begin_comment
comment|/* contains:  * Auth_GetFirstAuth  */
end_comment

begin_comment
comment|/* $Log:	Authlookup.c,v $  * Revision 1.2  87/03/23  10:25:34  ed  * Minor change.  *   * Revision 1.1  87/01/05  11:50:16  ed  * Initial revision  *   */
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
file|<xnscourier/courier.h>
end_include

begin_include
include|#
directive|include
file|<xnscourier/courierconnection.h>
end_include

begin_include
include|#
directive|include
file|<xnscourier/except.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BFS
end_ifndef

begin_define
define|#
directive|define
name|BFS
value|"/usr/new/xnsbfs -a"
end_define

begin_endif
endif|#
directive|endif
endif|BFS
end_endif

begin_decl_stmt
name|struct
name|ns_addr
modifier|*
name|chaddr
decl_stmt|;
end_decl_stmt

begin_function
name|CourierConnection
modifier|*
name|Auth_GetFirstAuth
parameter_list|()
block|{
specifier|extern
name|struct
name|ns_addr
modifier|*
name|getXNSaddr
parameter_list|()
function_decl|;
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|CourierConnection
modifier|*
name|result
decl_stmt|;
name|FILE
modifier|*
name|chfile
decl_stmt|;
name|int
name|i
decl_stmt|;
name|result
operator|=
operator|(
name|CourierConnection
operator|*
operator|)
name|NULL
expr_stmt|;
comment|/* broadcast for Authentication server */
comment|/*  -- this could be more efficient! */
if|if
condition|(
operator|(
name|chfile
operator|=
name|popen
argument_list|(
name|BFS
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
while|while
condition|(
name|fgets
argument_list|(
name|buf
argument_list|,
name|BUFSIZ
argument_list|,
name|chfile
argument_list|)
operator|!=
name|NULL
condition|)
if|if
condition|(
operator|(
name|buf
index|[
literal|0
index|]
operator|!=
literal|'#'
operator|)
operator|&&
operator|(
name|chaddr
operator|=
name|getXNSaddr
argument_list|(
name|buf
argument_list|)
operator|)
operator|&&
operator|(
name|result
operator|=
name|CourierOpen
argument_list|(
name|chaddr
argument_list|)
operator|)
condition|)
block|{
name|pclose
argument_list|(
name|chfile
argument_list|)
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
name|pclose
argument_list|(
name|chfile
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

end_unit

