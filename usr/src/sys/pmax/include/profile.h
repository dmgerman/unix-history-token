begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)profile.h	7.5 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|static void __mcount
end_define

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|asm(".globl _mcount;" \ 	"_mcount:;" \ 	".set noreorder;" \ 	".set noat;" \ 	"sw $4,8($29);" \ 	"sw $5,12($29);" \ 	"sw $6,16($29);" \ 	"sw $7,20($29);" \ 	"sw $1,0($29);" \ 	"sw $31,4($29);" \ 	"move $5,$31;" \ 	"jal __mcount;" \ 	"move $4,$1;" \ 	"lw $4,8($29);" \ 	"lw $5,12($29);" \ 	"lw $6,16($29);" \ 	"lw $7,20($29);" \ 	"lw $31,4($29);" \ 	"lw $1,0($29);" \ 	"addu $29,$29,8;" \ 	"j $31;" \ 	"move $31,$1;" \ 	".set reorder;" \ 	".set at");
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
value|s = _splhigh()
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
value|_splx(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

