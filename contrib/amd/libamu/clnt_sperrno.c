begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1998 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: clnt_sperrno.c,v 5.2.2.1 1992/02/09 15:08:40 jsp beta $  *  */
end_comment

begin_comment
comment|/*  * Early RPC seems to be missing these..  * Extracted from the RPC 3.9 sources as indicated  */
end_comment

begin_comment
comment|/* @(#)clnt_perror.c    1.1 87/11/04 3.9 RPCSRC */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_include
include|#
directive|include
file|<am_defs.h>
end_include

begin_include
include|#
directive|include
file|<amu.h>
end_include

begin_struct
struct|struct
name|rpc_errtab
block|{
name|enum
name|clnt_stat
name|status
decl_stmt|;
name|char
modifier|*
name|message
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|rpc_errtab
name|rpc_errlist
index|[]
init|=
block|{
block|{
name|RPC_SUCCESS
block|,
literal|"RPC: Success"
block|}
block|,
block|{
name|RPC_CANTENCODEARGS
block|,
literal|"RPC: Can't encode arguments"
block|}
block|,
block|{
name|RPC_CANTDECODERES
block|,
literal|"RPC: Can't decode result"
block|}
block|,
block|{
name|RPC_CANTSEND
block|,
literal|"RPC: Unable to send"
block|}
block|,
block|{
name|RPC_CANTRECV
block|,
literal|"RPC: Unable to receive"
block|}
block|,
block|{
name|RPC_TIMEDOUT
block|,
literal|"RPC: Timed out"
block|}
block|,
block|{
name|RPC_VERSMISMATCH
block|,
literal|"RPC: Incompatible versions of RPC"
block|}
block|,
block|{
name|RPC_AUTHERROR
block|,
literal|"RPC: Authentication error"
block|}
block|,
block|{
name|RPC_PROGUNAVAIL
block|,
literal|"RPC: Program unavailable"
block|}
block|,
block|{
name|RPC_PROGVERSMISMATCH
block|,
literal|"RPC: Program/version mismatch"
block|}
block|,
block|{
name|RPC_PROCUNAVAIL
block|,
literal|"RPC: Procedure unavailable"
block|}
block|,
block|{
name|RPC_CANTDECODEARGS
block|,
literal|"RPC: Server can't decode arguments"
block|}
block|,
block|{
name|RPC_SYSTEMERROR
block|,
literal|"RPC: Remote system error"
block|}
block|,
block|{
name|RPC_UNKNOWNHOST
block|,
literal|"RPC: Unknown host"
block|}
block|,
comment|/*      { RPC_UNKNOWNPROTO,  * "RPC: Unknown protocol" }, */
block|{
name|RPC_PMAPFAILURE
block|,
literal|"RPC: Port mapper failure"
block|}
block|,
block|{
name|RPC_PROGNOTREGISTERED
block|,
literal|"RPC: Program not registered"
block|}
block|,
block|{
name|RPC_FAILED
block|,
literal|"RPC: Failed (unspecified error)"
block|}
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
name|enum
name|clnt_stat
name|stat
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|rpc_errlist
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|rpc_errtab
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|rpc_errlist
index|[
name|i
index|]
operator|.
name|status
operator|==
name|stat
condition|)
block|{
return|return
operator|(
name|rpc_errlist
index|[
name|i
index|]
operator|.
name|message
operator|)
return|;
block|}
block|}
return|return
operator|(
literal|"RPC: (unknown error code)"
operator|)
return|;
block|}
end_function

end_unit

