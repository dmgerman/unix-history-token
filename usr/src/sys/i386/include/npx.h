begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.redist.c%  *  *	@(#)npx.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * 287/387 NPX Coprocessor Data Structures and Constants  * W. Jolitz 1/90  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|___NPX87___
end_ifndef

begin_define
define|#
directive|define
name|___NPX87___
end_define

begin_comment
comment|/* Environment information of floating point unit */
end_comment

begin_struct
struct|struct
name|env87
block|{
name|long
name|en_cw
decl_stmt|;
comment|/* control word (16bits) */
name|long
name|en_sw
decl_stmt|;
comment|/* status word (16bits) */
name|long
name|en_tw
decl_stmt|;
comment|/* tag word (16bits) */
name|long
name|en_fip
decl_stmt|;
comment|/* floating point instruction pointer */
name|u_short
name|en_fcs
decl_stmt|;
comment|/* floating code segment selector */
name|u_short
name|en_opcode
decl_stmt|;
comment|/* opcode last executed (11 bits ) */
name|long
name|en_foo
decl_stmt|;
comment|/* floating operand offset */
name|long
name|en_fos
decl_stmt|;
comment|/* floating operand segment selector */
block|}
struct|;
end_struct

begin_comment
comment|/* Contents of each floating point accumulator */
end_comment

begin_struct
struct|struct
name|fpacc87
block|{
name|u_long
name|fp_mantlo
decl_stmt|;
comment|/* mantissa low (31:0) */
name|u_long
name|fp_manthi
decl_stmt|;
comment|/* mantissa high (63:32) */
name|int
name|fp_exp
range|:
literal|15
decl_stmt|;
comment|/* exponent */
name|int
name|fp_sgn
range|:
literal|1
decl_stmt|;
comment|/* mantissa sign */
block|}
struct|;
end_struct

begin_comment
comment|/* Floating point context */
end_comment

begin_struct
struct|struct
name|save87
block|{
name|struct
name|env87
name|sv_env
decl_stmt|;
comment|/* floating point control/status */
name|struct
name|fpacc87
name|sv_ac
index|[
literal|8
index|]
decl_stmt|;
comment|/* accumulator contents, 0-7 */
block|}
struct|;
end_struct

begin_comment
comment|/* Cyrix EMC memory - mapped coprocessor context switch information */
end_comment

begin_struct
struct|struct
name|emcsts
block|{
name|long
name|em_msw
decl_stmt|;
comment|/* memory mapped status register when swtched */
name|long
name|em_tar
decl_stmt|;
comment|/* memory mapped temp A register when swtched */
name|long
name|em_dl
decl_stmt|;
comment|/* memory mapped D low register when swtched */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|___NPX87___
end_endif

end_unit

