begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_comment
comment|/*static char *sccsid = "from: @(#)clnt_perror.c 1.15 87/10/07 Copyr 1984 Sun Micro";*/
end_comment

begin_comment
comment|/*static char *sccsid = "from: @(#)clnt_perror.c	2.1 88/07/29 4.0 RPCSRC";*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Id: clnt_perror.c,v 1.9 1997/05/28 05:05:04 wpaul Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * clnt_perror.c  *  * Copyright (C) 1984, Sun Microsystems, Inc.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_include
include|#
directive|include
file|<rpc/auth.h>
end_include

begin_include
include|#
directive|include
file|<rpc/clnt.h>
end_include

begin_function_decl
specifier|static
name|char
modifier|*
name|auth_errmsg
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CLNT_PERROR_BUFLEN
value|256
end_define

begin_decl_stmt
specifier|static
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|char
modifier|*
name|_buf
parameter_list|()
block|{
if|if
condition|(
name|buf
operator|==
literal|0
condition|)
name|buf
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|CLNT_PERROR_BUFLEN
argument_list|)
expr_stmt|;
return|return
operator|(
name|buf
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Print reply error info  */
end_comment

begin_function
name|char
modifier|*
name|clnt_sperror
parameter_list|(
name|rpch
parameter_list|,
name|s
parameter_list|)
name|CLIENT
modifier|*
name|rpch
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|struct
name|rpc_err
name|e
decl_stmt|;
name|char
modifier|*
name|err
decl_stmt|;
name|char
modifier|*
name|str
init|=
name|_buf
argument_list|()
decl_stmt|;
name|char
modifier|*
name|strstart
init|=
name|str
decl_stmt|;
if|if
condition|(
name|str
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|CLNT_GETERR
argument_list|(
name|rpch
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|str
argument_list|,
literal|"%s: %s"
argument_list|,
name|s
argument_list|,
name|clnt_sperrno
argument_list|(
name|e
operator|.
name|re_status
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|+=
name|strlen
argument_list|(
name|str
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|e
operator|.
name|re_status
condition|)
block|{
case|case
name|RPC_SUCCESS
case|:
case|case
name|RPC_CANTENCODEARGS
case|:
case|case
name|RPC_CANTDECODERES
case|:
case|case
name|RPC_TIMEDOUT
case|:
case|case
name|RPC_PROGUNAVAIL
case|:
case|case
name|RPC_PROCUNAVAIL
case|:
case|case
name|RPC_CANTDECODEARGS
case|:
case|case
name|RPC_SYSTEMERROR
case|:
case|case
name|RPC_UNKNOWNHOST
case|:
case|case
name|RPC_UNKNOWNPROTO
case|:
case|case
name|RPC_PMAPFAILURE
case|:
case|case
name|RPC_PROGNOTREGISTERED
case|:
case|case
name|RPC_FAILED
case|:
break|break;
case|case
name|RPC_CANTSEND
case|:
case|case
name|RPC_CANTRECV
case|:
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|str
argument_list|,
name|CLNT_PERROR_BUFLEN
operator|-
operator|(
name|str
operator|-
name|strstart
operator|)
argument_list|,
literal|"; errno = %s\n"
argument_list|,
name|strerror
argument_list|(
name|e
operator|.
name|re_errno
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|RPC_VERSMISMATCH
case|:
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|str
argument_list|,
literal|"; low version = %lu, high version = %lu\n"
argument_list|,
operator|(
name|u_long
operator|)
name|e
operator|.
name|re_vers
operator|.
name|low
argument_list|,
operator|(
name|u_long
operator|)
name|e
operator|.
name|re_vers
operator|.
name|high
argument_list|)
expr_stmt|;
break|break;
case|case
name|RPC_AUTHERROR
case|:
name|err
operator|=
name|auth_errmsg
argument_list|(
name|e
operator|.
name|re_why
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|str
argument_list|,
literal|"; why = "
argument_list|)
expr_stmt|;
name|str
operator|+=
name|strlen
argument_list|(
name|str
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|str
argument_list|,
literal|"%s\n"
argument_list|,
name|err
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|str
argument_list|,
literal|"(unknown authentication error - %d)\n"
argument_list|,
operator|(
name|int
operator|)
name|e
operator|.
name|re_why
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|RPC_PROGVERSMISMATCH
case|:
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|str
argument_list|,
literal|"; low version = %lu, high version = %lu\n"
argument_list|,
operator|(
name|u_long
operator|)
name|e
operator|.
name|re_vers
operator|.
name|low
argument_list|,
operator|(
name|u_long
operator|)
name|e
operator|.
name|re_vers
operator|.
name|high
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* unknown */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|str
argument_list|,
literal|"; s1 = %lu, s2 = %lu\n"
argument_list|,
operator|(
name|long
operator|)
name|e
operator|.
name|re_lb
operator|.
name|s1
argument_list|,
operator|(
name|long
operator|)
name|e
operator|.
name|re_lb
operator|.
name|s2
argument_list|)
expr_stmt|;
break|break;
block|}
name|strstart
index|[
name|CLNT_PERROR_BUFLEN
operator|-
literal|2
index|]
operator|=
literal|'\n'
expr_stmt|;
name|strstart
index|[
name|CLNT_PERROR_BUFLEN
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|strstart
operator|)
return|;
block|}
end_function

begin_function
name|void
name|clnt_perror
parameter_list|(
name|rpch
parameter_list|,
name|s
parameter_list|)
name|CLIENT
modifier|*
name|rpch
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|clnt_sperror
argument_list|(
name|rpch
argument_list|,
name|s
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|rpc_errlist
index|[]
init|=
block|{
literal|"RPC: Success"
block|,
comment|/*  0 - RPC_SUCCESS */
literal|"RPC: Can't encode arguments"
block|,
comment|/*  1 - RPC_CANTENCODEARGS */
literal|"RPC: Can't decode result"
block|,
comment|/*  2 - RPC_CANTDECODERES */
literal|"RPC: Unable to send"
block|,
comment|/*  3 - RPC_CANTSEND */
literal|"RPC: Unable to receive"
block|,
comment|/*  4 - RPC_CANTRECV */
literal|"RPC: Timed out"
block|,
comment|/*  5 - RPC_TIMEDOUT */
literal|"RPC: Incompatible versions of RPC"
block|,
comment|/*  6 - RPC_VERSMISMATCH */
literal|"RPC: Authentication error"
block|,
comment|/*  7 - RPC_AUTHERROR */
literal|"RPC: Program unavailable"
block|,
comment|/*  8 - RPC_PROGUNAVAIL */
literal|"RPC: Program/version mismatch"
block|,
comment|/*  9 - RPC_PROGVERSMISMATCH */
literal|"RPC: Procedure unavailable"
block|,
comment|/* 10 - RPC_PROCUNAVAIL */
literal|"RPC: Server can't decode arguments"
block|,
comment|/* 11 - RPC_CANTDECODEARGS */
literal|"RPC: Remote system error"
block|,
comment|/* 12 - RPC_SYSTEMERROR */
literal|"RPC: Unknown host"
block|,
comment|/* 13 - RPC_UNKNOWNHOST */
literal|"RPC: Port mapper failure"
block|,
comment|/* 14 - RPC_PMAPFAILURE */
literal|"RPC: Program not registered"
block|,
comment|/* 15 - RPC_PROGNOTREGISTERED */
literal|"RPC: Failed (unspecified error)"
block|,
comment|/* 16 - RPC_FAILED */
literal|"RPC: Unknown protocol"
comment|/* 17 - RPC_UNKNOWNPROTO */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This interface for use by clntrpc  */
end_comment

begin_function
name|char
modifier|*
name|clnt_sperrno
parameter_list|(
name|stat
parameter_list|)
name|enum
name|clnt_stat
name|stat
decl_stmt|;
block|{
name|unsigned
name|int
name|errnum
init|=
name|stat
decl_stmt|;
if|if
condition|(
name|errnum
operator|<
operator|(
sizeof|sizeof
argument_list|(
name|rpc_errlist
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|rpc_errlist
index|[
literal|0
index|]
argument_list|)
operator|)
condition|)
return|return
operator|(
name|char
operator|*
operator|)
name|rpc_errlist
index|[
name|errnum
index|]
return|;
return|return
operator|(
literal|"RPC: (unknown error code)"
operator|)
return|;
block|}
end_function

begin_function
name|void
name|clnt_perrno
parameter_list|(
name|num
parameter_list|)
name|enum
name|clnt_stat
name|num
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|clnt_sperrno
argument_list|(
name|num
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|char
modifier|*
name|clnt_spcreateerror
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|char
modifier|*
name|str
init|=
name|_buf
argument_list|()
decl_stmt|;
if|if
condition|(
name|str
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
switch|switch
condition|(
name|rpc_createerr
operator|.
name|cf_stat
condition|)
block|{
case|case
name|RPC_PMAPFAILURE
case|:
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|str
argument_list|,
name|CLNT_PERROR_BUFLEN
argument_list|,
literal|"%s: %s - %s\n"
argument_list|,
name|s
argument_list|,
name|clnt_sperrno
argument_list|(
name|rpc_createerr
operator|.
name|cf_stat
argument_list|)
argument_list|,
name|clnt_sperrno
argument_list|(
name|rpc_createerr
operator|.
name|cf_error
operator|.
name|re_status
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|RPC_SYSTEMERROR
case|:
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|str
argument_list|,
name|CLNT_PERROR_BUFLEN
argument_list|,
literal|"%s: %s - %s\n"
argument_list|,
name|s
argument_list|,
name|clnt_sperrno
argument_list|(
name|rpc_createerr
operator|.
name|cf_stat
argument_list|)
argument_list|,
name|strerror
argument_list|(
name|rpc_createerr
operator|.
name|cf_error
operator|.
name|re_errno
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|str
argument_list|,
name|CLNT_PERROR_BUFLEN
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|s
argument_list|,
name|clnt_sperrno
argument_list|(
name|rpc_createerr
operator|.
name|cf_stat
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
name|str
index|[
name|CLNT_PERROR_BUFLEN
operator|-
literal|2
index|]
operator|=
literal|'\n'
expr_stmt|;
name|str
index|[
name|CLNT_PERROR_BUFLEN
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|str
operator|)
return|;
block|}
end_function

begin_function
name|void
name|clnt_pcreateerror
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|clnt_spcreateerror
argument_list|(
name|s
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|auth_errlist
index|[]
init|=
block|{
literal|"Authentication OK"
block|,
comment|/* 0 - AUTH_OK */
literal|"Invalid client credential"
block|,
comment|/* 1 - AUTH_BADCRED */
literal|"Server rejected credential"
block|,
comment|/* 2 - AUTH_REJECTEDCRED */
literal|"Invalid client verifier"
block|,
comment|/* 3 - AUTH_BADVERF */
literal|"Server rejected verifier"
block|,
comment|/* 4 - AUTH_REJECTEDVERF */
literal|"Client credential too weak"
block|,
comment|/* 5 - AUTH_TOOWEAK */
literal|"Invalid server verifier"
block|,
comment|/* 6 - AUTH_INVALIDRESP */
literal|"Failed (unspecified error)"
comment|/* 7 - AUTH_FAILED */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|char
modifier|*
name|auth_errmsg
parameter_list|(
name|stat
parameter_list|)
name|enum
name|auth_stat
name|stat
decl_stmt|;
block|{
name|unsigned
name|int
name|errnum
init|=
name|stat
decl_stmt|;
if|if
condition|(
name|errnum
operator|<
operator|(
sizeof|sizeof
argument_list|(
name|auth_errlist
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|auth_errlist
index|[
literal|0
index|]
argument_list|)
operator|)
condition|)
return|return
operator|(
name|char
operator|*
operator|)
name|auth_errlist
index|[
name|errnum
index|]
return|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

