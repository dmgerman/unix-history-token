begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)lrscan.c	8.1 (Berkeley) 5/31/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
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
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"trek.h"
end_include

begin_comment
comment|/* **  LONG RANGE OF SCANNERS ** **	A summary of the quadrants that surround you is printed.  The **	hundreds digit is the number of Klingons in the quadrant, **	the tens digit is the number of starbases, and the units digit **	is the number of stars.  If the printout is "///" it means **	that that quadrant is rendered uninhabitable by a supernova. **	It also updates the "scanned" field of the quadrants it scans, **	for future use by the "chart" option of the computer. */
end_comment

begin_macro
name|lrscan
argument_list|()
end_macro

begin_block
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|struct
name|quad
modifier|*
name|q
decl_stmt|;
if|if
condition|(
name|check_out
argument_list|(
name|LRSCAN
argument_list|)
condition|)
block|{
return|return;
block|}
name|printf
argument_list|(
literal|"Long range scan for quadrant %d,%d\n\n"
argument_list|,
name|Ship
operator|.
name|quadx
argument_list|,
name|Ship
operator|.
name|quady
argument_list|)
expr_stmt|;
comment|/* print the header on top */
for|for
control|(
name|j
operator|=
name|Ship
operator|.
name|quady
operator|-
literal|1
init|;
name|j
operator|<=
name|Ship
operator|.
name|quady
operator|+
literal|1
condition|;
name|j
operator|++
control|)
block|{
if|if
condition|(
name|j
operator|<
literal|0
operator|||
name|j
operator|>=
name|NQUADS
condition|)
name|printf
argument_list|(
literal|"      "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"     %1d"
argument_list|,
name|j
argument_list|)
expr_stmt|;
block|}
comment|/* scan the quadrants */
for|for
control|(
name|i
operator|=
name|Ship
operator|.
name|quadx
operator|-
literal|1
init|;
name|i
operator|<=
name|Ship
operator|.
name|quadx
operator|+
literal|1
condition|;
name|i
operator|++
control|)
block|{
name|printf
argument_list|(
literal|"\n  -------------------\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
operator|||
name|i
operator|>=
name|NQUADS
condition|)
block|{
comment|/* negative energy barrier */
name|printf
argument_list|(
literal|"  !  *  !  *  !  *  !"
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|/* print the left hand margin */
name|printf
argument_list|(
literal|"%1d !"
argument_list|,
name|i
argument_list|)
expr_stmt|;
for|for
control|(
name|j
operator|=
name|Ship
operator|.
name|quady
operator|-
literal|1
init|;
name|j
operator|<=
name|Ship
operator|.
name|quady
operator|+
literal|1
condition|;
name|j
operator|++
control|)
block|{
if|if
condition|(
name|j
operator|<
literal|0
operator|||
name|j
operator|>=
name|NQUADS
condition|)
block|{
comment|/* negative energy barrier again */
name|printf
argument_list|(
literal|"  *  !"
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|q
operator|=
operator|&
name|Quad
index|[
name|i
index|]
index|[
name|j
index|]
expr_stmt|;
if|if
condition|(
name|q
operator|->
name|stars
operator|<
literal|0
condition|)
block|{
comment|/* supernova */
name|printf
argument_list|(
literal|" /// !"
argument_list|)
expr_stmt|;
name|q
operator|->
name|scanned
operator|=
literal|1000
expr_stmt|;
continue|continue;
block|}
name|q
operator|->
name|scanned
operator|=
name|q
operator|->
name|klings
operator|*
literal|100
operator|+
name|q
operator|->
name|bases
operator|*
literal|10
operator|+
name|q
operator|->
name|stars
expr_stmt|;
name|printf
argument_list|(
literal|" %3d !"
argument_list|,
name|q
operator|->
name|scanned
argument_list|)
expr_stmt|;
block|}
block|}
name|printf
argument_list|(
literal|"\n  -------------------\n"
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

end_unit

