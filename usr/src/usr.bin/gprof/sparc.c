begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)sparc.c	8.1 (Berkeley) 6/6/93"
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
file|"gprof.h"
end_include

begin_comment
comment|/*      *	a namelist entry to be the child of indirect calls      */
end_comment

begin_decl_stmt
name|nltype
name|indirectchild
init|=
block|{
literal|"(*)"
block|,
comment|/* the name */
operator|(
name|unsigned
name|long
operator|)
literal|0
block|,
comment|/* the pc entry point */
operator|(
name|unsigned
name|long
operator|)
literal|0
block|,
comment|/* entry point aligned to histogram */
operator|(
name|double
operator|)
literal|0.0
block|,
comment|/* ticks in this routine */
operator|(
name|double
operator|)
literal|0.0
block|,
comment|/* cumulative ticks in children */
operator|(
name|long
operator|)
literal|0
block|,
comment|/* how many times called */
operator|(
name|long
operator|)
literal|0
block|,
comment|/* times called by live arcs */
operator|(
name|long
operator|)
literal|0
block|,
comment|/* how many calls to self */
operator|(
name|double
operator|)
literal|1.0
block|,
comment|/* propagation fraction */
operator|(
name|double
operator|)
literal|0.0
block|,
comment|/* self propagation time */
operator|(
name|double
operator|)
literal|0.0
block|,
comment|/* child propagation time */
operator|(
name|short
operator|)
literal|0
block|,
comment|/* print flag */
operator|(
name|short
operator|)
literal|0
block|,
comment|/* flags */
operator|(
name|int
operator|)
literal|0
block|,
comment|/* index in the graph list */
operator|(
name|int
operator|)
literal|0
block|,
comment|/* graph call chain top-sort order */
operator|(
name|int
operator|)
literal|0
block|,
comment|/* internal number of cycle on */
operator|(
name|int
operator|)
literal|0
block|,
comment|/* number of live parent arcs */
operator|(
expr|struct
name|nl
operator|*
operator|)
operator|&
name|indirectchild
block|,
comment|/* pointer to head of cycle */
operator|(
expr|struct
name|nl
operator|*
operator|)
literal|0
block|,
comment|/* pointer to next member of cycle */
operator|(
name|arctype
operator|*
operator|)
literal|0
block|,
comment|/* list of caller arcs */
operator|(
name|arctype
operator|*
operator|)
literal|0
comment|/* list of callee arcs */
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|findcall
argument_list|(
argument|parentp
argument_list|,
argument|p_lowpc
argument_list|,
argument|p_highpc
argument_list|)
end_macro

begin_decl_stmt
name|nltype
modifier|*
name|parentp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|p_lowpc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|p_highpc
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|u_long
name|pc
decl_stmt|;
name|nltype
modifier|*
name|childp
decl_stmt|;
name|unsigned
name|long
name|destpc
decl_stmt|;
specifier|register
name|long
name|op
decl_stmt|;
specifier|register
name|int
name|off
decl_stmt|;
if|if
condition|(
name|textspace
operator|==
literal|0
condition|)
return|return;
if|if
condition|(
name|p_lowpc
operator|<
name|s_lowpc
condition|)
name|p_lowpc
operator|=
name|s_lowpc
expr_stmt|;
if|if
condition|(
name|p_highpc
operator|>
name|s_highpc
condition|)
name|p_highpc
operator|=
name|s_highpc
expr_stmt|;
for|for
control|(
name|pc
operator|=
name|p_lowpc
init|;
name|pc
operator|<
name|p_highpc
condition|;
name|pc
operator|+=
literal|4
control|)
block|{
name|off
operator|=
name|pc
operator|-
name|s_lowpc
expr_stmt|;
name|op
operator|=
operator|*
operator|(
name|u_long
operator|*
operator|)
operator|&
name|textspace
index|[
name|off
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|op
operator|&
literal|0xc0000000
operator|)
operator|==
literal|0x40000000
condition|)
block|{
comment|/* 			 * a pc relative call insn -- check that this 			 * is the address of a function. 			 */
name|off
operator|=
operator|(
name|op
operator|&
literal|0x3fffffff
operator|)
operator|<<
literal|2
expr_stmt|;
name|destpc
operator|=
name|pc
operator|+
name|off
expr_stmt|;
if|if
condition|(
name|destpc
operator|>=
name|s_lowpc
operator|&&
name|destpc
operator|<=
name|s_highpc
condition|)
block|{
name|childp
operator|=
name|nllookup
argument_list|(
name|destpc
argument_list|)
expr_stmt|;
if|if
condition|(
name|childp
operator|!=
literal|0
operator|&&
name|childp
operator|->
name|value
operator|==
name|destpc
condition|)
name|addarc
argument_list|(
name|parentp
argument_list|,
name|childp
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
operator|(
name|op
operator|&
literal|0xfff80000
operator|)
operator|==
literal|0x9fc00000
condition|)
comment|/* 			 * A jmpl with rd = 15 (%o7) -- an indirect call. 			 */
name|addarc
argument_list|(
name|parentp
argument_list|,
operator|&
name|indirectchild
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

