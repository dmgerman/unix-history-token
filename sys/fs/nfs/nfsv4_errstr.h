begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Rick Macklem, University of Guelph  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSV4ERRSTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSV4ERRSTR_H_
end_define

begin_comment
comment|/*  * Defines static storage in the C file, but I can't be bothered creating  * a library of one function for this, since it is only currently used by  * mount_newnfs.c.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|nfsv4_errstr
index|[
literal|48
index|]
init|=
block|{
literal|"Illegal filehandle"
block|,
literal|"Undefined NFSv4 err"
block|,
literal|"READDIR cookie is stale"
block|,
literal|"operation not supported"
block|,
literal|"response limit exceeded"
block|,
literal|"undefined server error"
block|,
literal|"type invalid for CREATE"
block|,
literal|"file busy - retry"
block|,
literal|"nverify says attrs same"
block|,
literal|"lock unavailable"
block|,
literal|"lock lease expired"
block|,
literal|"I/O failed due to lock"
block|,
literal|"in grace period"
block|,
literal|"filehandle expired"
block|,
literal|"share reserve denied"
block|,
literal|"wrong security flavor"
block|,
literal|"clientid in use"
block|,
literal|"resource exhaustion"
block|,
literal|"filesystem relocated"
block|,
literal|"current FH is not set"
block|,
literal|"minor vers not supp"
block|,
literal|"server has rebooted"
block|,
literal|"server has rebooted"
block|,
literal|"state is out of sync"
block|,
literal|"incorrect stateid"
block|,
literal|"request is out of seq"
block|,
literal|"verify - attrs not same"
block|,
literal|"lock range not supported"
block|,
literal|"should be file/directory"
block|,
literal|"no saved filehandle"
block|,
literal|"some filesystem moved"
block|,
literal|"recommended attr not sup"
block|,
literal|"reclaim outside of grace"
block|,
literal|"reclaim error at server"
block|,
literal|"conflict on reclaim"
block|,
literal|"XDR decode failed"
block|,
literal|"file locks held at CLOSE"
block|,
literal|"conflict in OPEN and I/O"
block|,
literal|"owner translation bad"
block|,
literal|"utf-8 char not supported"
block|,
literal|"name not supported"
block|,
literal|"lock range not supported"
block|,
literal|"no atomic up/downgrade"
block|,
literal|"undefined operation"
block|,
literal|"file locking deadlock"
block|,
literal|"open file blocks op"
block|,
literal|"lockowner state revoked"
block|,
literal|"callback path down"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Return the error string for the NFS4ERR_xxx. The pointers returned are  * static and must not be free'd.  */
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|nfsv4_geterrstr
parameter_list|(
name|int
name|errval
parameter_list|)
block|{
if|if
condition|(
name|errval
operator|<
name|NFSERR_BADHANDLE
operator|||
name|errval
operator|>
name|NFSERR_CBPATHDOWN
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
return|return
operator|(
name|nfsv4_errstr
index|[
name|errval
operator|-
name|NFSERR_BADHANDLE
index|]
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_NFSV4ERRSTR_H_ */
end_comment

end_unit

