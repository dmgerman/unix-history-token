begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_struct
struct|struct
name|dkinfo
block|{
name|struct
name|dkinfo
modifier|*
name|dk_next
decl_stmt|;
name|char
modifier|*
name|dk_name
decl_stmt|;
comment|/* full-length name */
name|char
name|dk_2c
index|[
literal|3
index|]
decl_stmt|;
comment|/* two-character version of dk_name */
name|int
name|dk_sel
decl_stmt|;
comment|/* 1 if we should print this one */
name|u_long
name|dk_addr
decl_stmt|;
comment|/* kernel addr of struct dkdevice */
name|long
name|dk_oxfer
decl_stmt|;
comment|/* previous xfer stat */
name|long
name|dk_dxfer
decl_stmt|;
comment|/* delta between oxfer and cur xfer */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|dkinfo
modifier|*
name|dkinfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ndrives
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|kvm_t
modifier|*
name|kd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dointr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|domem
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dosum
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dovmstat
name|__P
argument_list|(
operator|(
name|u_int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|errexit
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|getuptime
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|knlist
name|__P
argument_list|(
operator|(
expr|struct
name|nlist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kread
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|void
operator|*
operator|,
name|size_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

