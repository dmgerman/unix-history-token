begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)lrscan.c	5.4 (Berkeley) %G%"
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
specifier|register
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
specifier|register
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

