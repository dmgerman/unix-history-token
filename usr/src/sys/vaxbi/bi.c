begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)bi.c	7.2 (Berkeley) 7/9/88  */
end_comment

begin_comment
comment|/*  * VAXBI specific routines.  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"../vax/cpu.h"
end_include

begin_include
include|#
directive|include
file|"../vax/mtpr.h"
end_include

begin_include
include|#
directive|include
file|"../vax/nexus.h"
end_include

begin_include
include|#
directive|include
file|"bireg.h"
end_include

begin_expr_stmt
name|bi_reset
argument_list|(
name|bi
argument_list|)
specifier|register
expr|struct
name|biiregs
operator|*
name|bi
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|bi
operator|->
name|bi_csr
operator||=
name|BICSR_NRST
expr_stmt|;
name|DELAY
argument_list|(
literal|10000
argument_list|)
expr_stmt|;
comment|/* ??? */
block|}
end_block

begin_comment
comment|/*  * Reset with self test.  Return true iff reset fails.  * BEWARE, THIS RESETS THE BI ARBITRATION LEVEL TO ARB_NONE  * does self test ever cause a bi bus error?  */
end_comment

begin_expr_stmt
name|bi_selftest
argument_list|(
name|bi
argument_list|)
specifier|register
expr|struct
name|biiregs
operator|*
name|bi
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|timo
decl_stmt|;
name|bi
operator|->
name|bi_csr
operator||=
name|BICSR_ARB_NONE
expr_stmt|;
comment|/* why? */
name|bi
operator|->
name|bi_csr
operator||=
name|BICSR_STS
operator||
name|BICSR_INIT
expr_stmt|;
comment|/* must this be separate? */
name|DELAY
argument_list|(
literal|50
argument_list|)
expr_stmt|;
comment|/* why? */
name|timo
operator|=
name|todr
argument_list|()
operator|+
literal|1000
expr_stmt|;
while|while
condition|(
name|bi
operator|->
name|bi_csr
operator|&
name|BICSR_BROKE
condition|)
block|{
if|if
condition|(
name|todr
argument_list|()
operator|>
name|timo
condition|)
comment|/* reset failed */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
comment|/* reset OK */
block|}
end_block

begin_comment
comment|/*  * THIS SHOULD PROBABLY WORK MORE LIKE ubaerror()  * (but then we would need to be able to reset BI nodes)  * (we need a per-BI-device driver structure!)  */
end_comment

begin_macro
name|bi_buserr
argument_list|(
argument|binum
argument_list|)
end_macro

begin_decl_stmt
name|int
name|binum
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|bi_node
modifier|*
name|bi
decl_stmt|;
specifier|register
name|int
name|node
decl_stmt|;
specifier|extern
name|int
name|bi_nodes
decl_stmt|;
specifier|extern
name|int
name|cold
decl_stmt|;
name|printf
argument_list|(
literal|"vaxbi%d: bus error\n"
argument_list|,
name|binum
argument_list|)
expr_stmt|;
name|bi
operator|=
operator|(
expr|struct
name|bi_node
operator|*
operator|)
operator|&
name|nexus
index|[
name|binum
operator|*
name|NNODEBI
index|]
expr_stmt|;
comment|/* XXX */
for|for
control|(
name|node
operator|=
literal|0
init|;
name|node
operator|<
literal|16
condition|;
name|node
operator|++
operator|,
name|bi
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|bi_nodes
operator|&
operator|(
literal|1
operator|<<
name|node
operator|)
operator|)
operator|==
literal|0
condition|)
comment|/* XXX crude */
continue|continue;
name|printf
argument_list|(
literal|"node %x: ber=%b\n"
argument_list|,
name|node
argument_list|,
name|bi
operator|->
name|biic
operator|.
name|bi_ber
argument_list|,
name|BIBER_BITS
argument_list|)
expr_stmt|;
block|}
name|panic
argument_list|(
literal|"bi_buserr"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

