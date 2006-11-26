begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003, Trent Nelson,<trent@arpa.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"convtbl.h"
end_include

begin_decl_stmt
name|struct
name|convtbl
name|convtbl
index|[]
init|=
block|{
comment|/* mul, scale, str */
block|{
name|BYTE
block|,
name|BYTES
block|,
literal|"bytes"
block|}
block|,
comment|/* SC_BYTE	(0) */
block|{
name|BYTE
block|,
name|KILO
block|,
literal|"KB"
block|}
block|,
comment|/* SC_KILOBYTE	(1) */
block|{
name|BYTE
block|,
name|MEGA
block|,
literal|"MB"
block|}
block|,
comment|/* SC_MEGABYTE	(2) */
block|{
name|BYTE
block|,
name|GIGA
block|,
literal|"GB"
block|}
block|,
comment|/* SC_GIGABYTE	(3) */
block|{
name|BIT
block|,
name|BITS
block|,
literal|"b"
block|}
block|,
comment|/* SC_BITS	(4) */
block|{
name|BIT
block|,
name|KILO
block|,
literal|"Kb"
block|}
block|,
comment|/* SC_KILOBITS	(5) */
block|{
name|BIT
block|,
name|MEGA
block|,
literal|"Mb"
block|}
block|,
comment|/* SC_MEGABITS	(6) */
block|{
name|BIT
block|,
name|GIGA
block|,
literal|"Gb"
block|}
block|,
comment|/* SC_GIGABITS	(7) */
block|{
literal|0
block|,
literal|0
block|,
literal|""
block|}
comment|/* SC_AUTO	(8) */
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|convtbl
operator|*
name|get_tbl_ptr
argument_list|(
argument|const u_long size
argument_list|,
argument|const u_int scale
argument_list|)
block|{ 	struct
name|convtbl
operator|*
name|tbl_ptr
operator|=
name|NULL
block|;
name|u_long
name|tmp
operator|=
literal|0
block|;
name|u_int
name|idx
operator|=
name|scale
block|;
comment|/* If our index is out of range, default to auto-scaling. */
if|if
condition|(
name|idx
operator|>
name|SC_AUTO
condition|)
name|idx
operator|=
name|SC_AUTO
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|idx
operator|==
name|SC_AUTO
condition|)
comment|/* 		 * Simple but elegant algorithm.  Count how many times 		 * we can shift our size value right by a factor of ten, 		 * incrementing an index each time.  We then use the 		 * index as the array index into the conversion table. 		 */
for|for
control|(
name|tmp
operator|=
name|size
operator|,
name|idx
operator|=
name|SC_KILOBYTE
init|;
name|tmp
operator|>=
name|MEGA
operator|&&
name|idx
operator|<
name|SC_GIGABYTE
condition|;
name|tmp
operator|>>=
literal|10
operator|,
name|idx
operator|++
control|)
empty_stmt|;
end_if

begin_expr_stmt
name|tbl_ptr
operator|=
operator|&
name|convtbl
index|[
name|idx
index|]
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|tbl_ptr
return|;
end_return

begin_macro
unit|}  double
name|convert
argument_list|(
argument|const u_long size
argument_list|,
argument|const u_int scale
argument_list|)
end_macro

begin_block
block|{
name|struct
name|convtbl
modifier|*
name|tp
init|=
name|NULL
decl_stmt|;
name|tp
operator|=
name|get_tbl_ptr
argument_list|(
name|size
argument_list|,
name|scale
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|double
operator|)
name|size
operator|*
name|tp
operator|->
name|mul
operator|/
name|tp
operator|->
name|scale
operator|)
return|;
block|}
end_block

begin_function
specifier|const
name|char
modifier|*
name|get_string
parameter_list|(
specifier|const
name|u_long
name|size
parameter_list|,
specifier|const
name|u_int
name|scale
parameter_list|)
block|{
name|struct
name|convtbl
modifier|*
name|tp
init|=
name|NULL
decl_stmt|;
name|tp
operator|=
name|get_tbl_ptr
argument_list|(
name|size
argument_list|,
name|scale
argument_list|)
expr_stmt|;
return|return
name|tp
operator|->
name|str
return|;
block|}
end_function

end_unit

