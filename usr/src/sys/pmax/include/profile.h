begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)profile.h	7.2 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|static void _mcount
end_define

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|asm(".globl mcount"); \ 	asm("mcount:"); \ 	asm(".set noreorder"); \ 	asm(".set noat"); \ 	asm("sw $31,4($29);"); \ 	asm("jal _mcount"); \ 	asm("sw $1,0($29);"); \ 	asm("lw $31,4($29)"); \ 	asm("lw $1,0($29)"); \ 	asm("addu $29,$29,8"); \ 	asm("j $31"); \ 	asm("move $31,$1"); \ 	asm(".set reorder"); \ 	asm(".set at");
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * The following two macros do splhigh and splx respectively.  * They have to be defined this way because these are real  * functions on the PMAX, and we do not want to invoke mcount  * recursively.  */
end_comment

begin_define
define|#
directive|define
name|MCOUNT_ENTER
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

