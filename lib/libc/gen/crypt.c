begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Tom Truscott.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
comment|/* from static char sccsid[] = "@(#)crypt.c	5.11 (Berkeley) 6/25/91"; */
end_comment

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * UNIX password, and DES, encryption.  *  * since this is non-exportable, this is just a dummy.  if you want real  * encryption, make sure you've got libcrypt.a around.  */
end_comment

begin_expr_stmt
name|des_setkey
argument_list|(
name|key
argument_list|)
specifier|register
specifier|const
name|char
operator|*
name|key
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"WARNING!  des_setkey(3) not present in the system!\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|des_cipher
argument_list|(
argument|in
argument_list|,
argument|out
argument_list|,
argument|salt
argument_list|,
argument|num_iter
argument_list|)
end_macro

begin_decl_stmt
specifier|const
name|char
modifier|*
name|in
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|salt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|num_iter
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"WARNING!  des_cipher(3) not present in the system!\n"
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|in
argument_list|,
name|out
argument_list|,
literal|8
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|setkey
argument_list|(
name|key
argument_list|)
specifier|register
specifier|const
name|char
operator|*
name|key
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"WARNING!  setkey(3) not present in the system!\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|encrypt
argument_list|(
name|block
argument_list|,
name|flag
argument_list|)
specifier|register
name|char
operator|*
name|block
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|flag
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"WARNING!  encrypt(3) not present in the system!\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

