begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)machdep.c	7.2 (Berkeley) 1/28/88  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"../vax/mtpr.h"
end_include

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_comment
comment|/*VARARGS1*/
end_comment

begin_macro
name|mtpr
argument_list|(
argument|regno
argument_list|,
argument|value
argument_list|)
end_macro

begin_block
block|{
asm|asm("	mtpr	8(ap),4(ap)");
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|mfpr
argument_list|(
argument|regno
argument_list|)
end_macro

begin_block
block|{
asm|asm("	mfpr	4(ap),r0");
ifdef|#
directive|ifdef
name|lint
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
block|}
end_block

begin_comment
comment|/*  * Copy bytes within kernel  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|bcopy
argument_list|(
argument|from
argument_list|,
argument|to
argument_list|,
argument|count
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|from
decl_stmt|,
name|to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
asm|asm("	movc3	12(ap),*4(ap),*8(ap)");
block|}
end_block

end_unit

