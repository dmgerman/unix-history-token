begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  fpu_emu.h  *  *  * Copyright (C) 1992,1993,1994  *                       W. Metzenthen, 22 Parker St, Ormond, Vic 3163,  *                       Australia.  E-mail   billm@vaxc.cc.monash.edu.au  * All rights reserved.  *  * This copyright notice covers the redistribution and use of the  * FPU emulator developed by W. Metzenthen. It covers only its use  * in the 386BSD, FreeBSD and NetBSD operating systems. Any other  * use is not permitted under this copyright.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must include information specifying  *    that source code for the emulator is freely available and include  *    either:  *      a) an offer to provide the source code for a nominal distribution  *         fee, or  *      b) list at least two alternative methods whereby the source  *         can be obtained, e.g. a publically accessible bulletin board  *         and an anonymous ftp site from which the software can be  *         downloaded.  * 3. All advertising materials specifically mentioning features or use of  *    this emulator must acknowledge that it was developed by W. Metzenthen.  * 4. The name of W. Metzenthen may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * W. METZENTHEN BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  * The purpose of this copyright, based upon the Berkeley copyright, is to  * ensure that the covered software remains freely available to everyone.  *  * The software (with necessary differences) is also available, but under  * the terms of the GNU copyleft, for the Linux operating system and for  * the djgpp ms-dos extender.  *  * W. Metzenthen   June 1994.  *  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FPU_EMU_H_
end_ifndef

begin_define
define|#
directive|define
name|_FPU_EMU_H_
end_define

begin_comment
comment|/*  * Define DENORM_OPERAND to make the emulator detect denormals  * and use the denormal flag of the status word. Note: this only  * affects the flag and corresponding interrupt, the emulator  * will always generate denormals and operate upon them as required.  */
end_comment

begin_define
define|#
directive|define
name|DENORM_OPERAND
end_define

begin_comment
comment|/*  * Define PECULIAR_486 to get a closer approximation to 80486 behaviour,  * rather than behaviour which appears to be cleaner.  * This is a matter of opinion: for all I know, the 80486 may simply  * be complying with the IEEE spec. Maybe one day I'll get to see the  * spec...  */
end_comment

begin_define
define|#
directive|define
name|PECULIAR_486
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_include
include|#
directive|include
file|<gnu/i386/fpemul/fpu_asm.h>
end_include

begin_define
define|#
directive|define
name|Const
parameter_list|(
name|x
parameter_list|)
value|$
comment|/**/
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Const
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXP_BIAS
value|Const(0)
end_define

begin_define
define|#
directive|define
name|EXP_OVER
value|Const(0x4000)
end_define

begin_comment
comment|/* smallest invalid large exponent */
end_comment

begin_define
define|#
directive|define
name|EXP_UNDER
value|Const(-0x3fff)
end_define

begin_comment
comment|/* largest invalid small exponent */
end_comment

begin_define
define|#
directive|define
name|SIGN_POS
value|Const(0)
end_define

begin_define
define|#
directive|define
name|SIGN_NEG
value|Const(1)
end_define

begin_comment
comment|/* Keep the order TW_Valid, TW_Zero, TW_Denormal */
end_comment

begin_define
define|#
directive|define
name|TW_Valid
value|Const(0)
end_define

begin_comment
comment|/* valid */
end_comment

begin_define
define|#
directive|define
name|TW_Zero
value|Const(1)
end_define

begin_comment
comment|/* zero */
end_comment

begin_comment
comment|/* The following fold to 2 (Special) in the Tag Word */
end_comment

begin_define
define|#
directive|define
name|TW_Denormal
value|Const(4)
end_define

begin_comment
comment|/* De-normal */
end_comment

begin_define
define|#
directive|define
name|TW_Infinity
value|Const(5)
end_define

begin_comment
comment|/* + or - infinity */
end_comment

begin_define
define|#
directive|define
name|TW_NaN
value|Const(6)
end_define

begin_comment
comment|/* Not a Number */
end_comment

begin_define
define|#
directive|define
name|TW_Empty
value|Const(7)
end_define

begin_comment
comment|/* empty */
end_comment

begin_comment
comment|/* #define TW_FPU_Interrupt Const(0x80) */
end_comment

begin_comment
comment|/* Signals an interrupt */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<gnu/i386/fpemul/math_emu.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PARANOID
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|emulating
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REENTRANT_CHECK
parameter_list|(
name|state
parameter_list|)
value|emulating = (state)
end_define

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REENTRANT_CHECK
parameter_list|(
name|state
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PARANOID */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|FUNC
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fpu_reg
name|FPU_REG
typedef|;
end_typedef

begin_define
define|#
directive|define
name|st
parameter_list|(
name|x
parameter_list|)
value|( regs[((top+x)&7 )] )
end_define

begin_define
define|#
directive|define
name|STACK_OVERFLOW
value|(st_new_ptr =&st(-1), st_new_ptr->tag != TW_Empty)
end_define

begin_define
define|#
directive|define
name|NOT_EMPTY
parameter_list|(
name|i
parameter_list|)
value|(st(i).tag != TW_Empty)
end_define

begin_define
define|#
directive|define
name|NOT_EMPTY_0
value|(FPU_st0_tag ^ TW_Empty)
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|FPU_rm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|FPU_st0_tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
modifier|*
name|FPU_st0_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|FPU_data_address
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FPU_REG
name|FPU_loaded_data
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pop
parameter_list|()
value|{ FPU_st0_ptr->tag = TW_Empty; top++; }
end_define

begin_comment
comment|/* push() does not affect the tags */
end_comment

begin_define
define|#
directive|define
name|push
parameter_list|()
value|{ top--; FPU_st0_ptr = st_new_ptr; }
end_define

begin_define
define|#
directive|define
name|reg_move
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ \ 		 *(short *)&((y)->sign) = *(short *)&((x)->sign); \ 		 *(long *)&((y)->exp) = *(long *)&((x)->exp); \ 		 *(long long *)&((y)->sigl) = *(long long *)&((x)->sigl); }
end_define

begin_comment
comment|/*----- Prototypes for functions written in assembler -----*/
end_comment

begin_comment
comment|/* extern void reg_move(FPU_REG *a, FPU_REG *b); */
end_comment

begin_function_decl
specifier|extern
name|void
name|mul64
parameter_list|(
name|long
name|long
modifier|*
name|a
parameter_list|,
name|long
name|long
modifier|*
name|b
parameter_list|,
name|long
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|poly_div2
parameter_list|(
name|long
name|long
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|poly_div4
parameter_list|(
name|long
name|long
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|poly_div16
parameter_list|(
name|long
name|long
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|polynomial
parameter_list|(
name|unsigned
name|accum
index|[]
parameter_list|,
name|unsigned
name|x
index|[]
parameter_list|,
name|unsigned
name|short
name|terms
index|[]
index|[
literal|4
index|]
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|normalize
parameter_list|(
name|FPU_REG
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|normalize_nuo
parameter_list|(
name|FPU_REG
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_div
parameter_list|(
name|FPU_REG
modifier|*
name|arg1
parameter_list|,
name|FPU_REG
modifier|*
name|arg2
parameter_list|,
name|FPU_REG
modifier|*
name|answ
parameter_list|,
name|unsigned
name|int
name|control_w
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_u_sub
parameter_list|(
name|FPU_REG
modifier|*
name|arg1
parameter_list|,
name|FPU_REG
modifier|*
name|arg2
parameter_list|,
name|FPU_REG
modifier|*
name|answ
parameter_list|,
name|unsigned
name|int
name|control_w
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_u_mul
parameter_list|(
name|FPU_REG
modifier|*
name|arg1
parameter_list|,
name|FPU_REG
modifier|*
name|arg2
parameter_list|,
name|FPU_REG
modifier|*
name|answ
parameter_list|,
name|unsigned
name|int
name|control_w
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_u_div
parameter_list|(
name|FPU_REG
modifier|*
name|arg1
parameter_list|,
name|FPU_REG
modifier|*
name|arg2
parameter_list|,
name|FPU_REG
modifier|*
name|answ
parameter_list|,
name|unsigned
name|int
name|control_w
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_u_add
parameter_list|(
name|FPU_REG
modifier|*
name|arg1
parameter_list|,
name|FPU_REG
modifier|*
name|arg2
parameter_list|,
name|FPU_REG
modifier|*
name|answ
parameter_list|,
name|unsigned
name|int
name|control_w
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wm_sqrt
parameter_list|(
name|FPU_REG
modifier|*
name|n
parameter_list|,
name|unsigned
name|int
name|control_w
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|shrx
parameter_list|(
name|void
modifier|*
name|l
parameter_list|,
name|unsigned
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|shrxs
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|unsigned
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|div_small
parameter_list|(
name|unsigned
name|long
name|long
modifier|*
name|x
parameter_list|,
name|unsigned
name|long
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|round_reg
parameter_list|(
name|FPU_REG
modifier|*
name|arg
parameter_list|,
name|unsigned
name|int
name|extent
parameter_list|,
name|unsigned
name|int
name|control_w
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|MAKING_PROTO
end_ifndef

begin_include
include|#
directive|include
file|<gnu/i386/fpemul/fpu_proto.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FPU_EMU_H_ */
end_comment

end_unit

