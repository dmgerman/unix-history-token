begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * tclUnixSock.c --  *  *	This file contains Unix-specific socket related code.  *  * Copyright (c) 1995 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) tclUnixSock.c 1.5 96/04/04 15:28:39  */
end_comment

begin_include
include|#
directive|include
file|"tcl.h"
end_include

begin_include
include|#
directive|include
file|"tclPort.h"
end_include

begin_comment
comment|/*  * The following variable holds the network name of this host.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_NMLN
end_ifndef

begin_define
define|#
directive|define
name|SYS_NMLN
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|char
name|hostname
index|[
name|SYS_NMLN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|hostnameInited
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * Tcl_GetHostName --  *  *	Get the network name for this machine, in a system dependent way.  *  * Results:  *	A string containing the network name for this machine.  *  * Side effects:  *	None.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|char
modifier|*
name|Tcl_GetHostName
parameter_list|()
block|{
name|struct
name|utsname
name|u
decl_stmt|;
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
if|if
condition|(
name|hostnameInited
condition|)
block|{
return|return
name|hostname
return|;
block|}
if|if
condition|(
name|uname
argument_list|(
operator|&
name|u
argument_list|)
operator|>
operator|-
literal|1
condition|)
block|{
name|hp
operator|=
name|gethostbyname
argument_list|(
name|u
operator|.
name|nodename
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
operator|!=
name|NULL
condition|)
block|{
name|strcpy
argument_list|(
name|hostname
argument_list|,
name|hp
operator|->
name|h_name
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|strcpy
argument_list|(
name|hostname
argument_list|,
name|u
operator|.
name|nodename
argument_list|)
expr_stmt|;
block|}
name|hostnameInited
operator|=
literal|1
expr_stmt|;
return|return
name|hostname
return|;
block|}
return|return
operator|(
name|char
operator|*
operator|)
name|NULL
return|;
block|}
end_function

end_unit

