begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id$  * From: $NetBSD: bootsectmain.c,v 1.1.1.1 1997/03/14 02:40:34 perry Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996  *	Matthias Drochner.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project  *	by Matthias Drochner.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/* load remainder of boot program  (blocks from fraglist),  start main()  needs lowlevel parts from biosdisk_ll.c  */
end_comment

begin_include
include|#
directive|include
file|"biosdisk_ll.h"
end_include

begin_include
include|#
directive|include
file|"bbinfo.h"
end_include

begin_decl_stmt
name|int
name|boot_biosdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exported */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fraglist
name|fraglist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|edata
index|[]
decl_stmt|,
name|end
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|main
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bootsectmain
parameter_list|(
name|biosdev
parameter_list|)
name|int
name|biosdev
decl_stmt|;
block|{
name|struct
name|biosdisk_ll
name|d
decl_stmt|;
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
comment|/*    * load sectors from bootdev    */
name|d
operator|.
name|dev
operator|=
name|biosdev
expr_stmt|;
name|set_geometry
argument_list|(
operator|&
name|d
argument_list|)
expr_stmt|;
name|buf
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
name|PRIM_LOADSZ
operator|*
name|BIOSDISK_SECSIZE
operator|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|fraglist
operator|.
name|numentries
condition|;
name|i
operator|++
control|)
block|{
name|int
name|dblk
decl_stmt|,
name|num
decl_stmt|;
name|dblk
operator|=
name|fraglist
operator|.
name|entries
index|[
name|i
index|]
operator|.
name|offset
expr_stmt|;
name|num
operator|=
name|fraglist
operator|.
name|entries
index|[
name|i
index|]
operator|.
name|num
expr_stmt|;
if|if
condition|(
name|readsects
argument_list|(
operator|&
name|d
argument_list|,
name|dblk
argument_list|,
name|num
argument_list|,
name|buf
argument_list|,
literal|1
argument_list|)
condition|)
return|return;
comment|/* halts in start_bootsect.S */
name|buf
operator|+=
name|num
operator|*
name|BIOSDISK_SECSIZE
expr_stmt|;
block|}
comment|/* clear BSS */
name|buf
operator|=
name|edata
expr_stmt|;
while|while
condition|(
name|buf
operator|<
name|end
condition|)
operator|*
name|buf
operator|++
operator|=
literal|0
expr_stmt|;
comment|/* call main() */
name|boot_biosdev
operator|=
name|biosdev
expr_stmt|;
comment|/*  main(); */
block|}
end_function

end_unit

