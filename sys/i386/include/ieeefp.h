begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 Andrew Moore, Talke Studio  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * 	from: @(#) ieeefp.h 	1.0 (Berkeley) 9/23/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	IEEE floating point type and constant definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IEEEFP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IEEEFP_H_
end_define

begin_comment
comment|/*  * FP rounding modes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FP_RN
init|=
literal|0
block|,
comment|/* round to nearest */
name|FP_RM
block|,
comment|/* round down to minus infinity */
name|FP_RP
block|,
comment|/* round up to plus infinity */
name|FP_RZ
comment|/* truncate */
block|}
name|fp_rnd_t
typedef|;
end_typedef

begin_comment
comment|/*  * FP precision modes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FP_PS
init|=
literal|0
block|,
comment|/* 24 bit (single-precision) */
name|FP_PRS
block|,
comment|/* reserved */
name|FP_PD
block|,
comment|/* 53 bit (double-precision) */
name|FP_PE
comment|/* 64 bit (extended-precision) */
block|}
name|fp_prec_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fp_except_t
value|int
end_define

begin_comment
comment|/*  * FP exception masks  */
end_comment

begin_define
define|#
directive|define
name|FP_X_INV
value|0x01
end_define

begin_comment
comment|/* invalid operation */
end_comment

begin_define
define|#
directive|define
name|FP_X_DNML
value|0x02
end_define

begin_comment
comment|/* denormal */
end_comment

begin_define
define|#
directive|define
name|FP_X_DZ
value|0x04
end_define

begin_comment
comment|/* zero divide */
end_comment

begin_define
define|#
directive|define
name|FP_X_OFL
value|0x08
end_define

begin_comment
comment|/* overflow */
end_comment

begin_define
define|#
directive|define
name|FP_X_UFL
value|0x10
end_define

begin_comment
comment|/* underflow */
end_comment

begin_define
define|#
directive|define
name|FP_X_IMP
value|0x20
end_define

begin_comment
comment|/* (im)precision */
end_comment

begin_define
define|#
directive|define
name|FP_X_STK
value|0x40
end_define

begin_comment
comment|/* stack fault */
end_comment

begin_comment
comment|/*  * FP registers  */
end_comment

begin_define
define|#
directive|define
name|FP_MSKS_REG
value|0
end_define

begin_comment
comment|/* exception masks */
end_comment

begin_define
define|#
directive|define
name|FP_PRC_REG
value|0
end_define

begin_comment
comment|/* precision */
end_comment

begin_define
define|#
directive|define
name|FP_RND_REG
value|0
end_define

begin_comment
comment|/* direction */
end_comment

begin_define
define|#
directive|define
name|FP_STKY_REG
value|1
end_define

begin_comment
comment|/* sticky flags */
end_comment

begin_comment
comment|/*  * FP register bit field masks  */
end_comment

begin_define
define|#
directive|define
name|FP_MSKS_FLD
value|0x3f
end_define

begin_comment
comment|/* exception masks field */
end_comment

begin_define
define|#
directive|define
name|FP_PRC_FLD
value|0x300
end_define

begin_comment
comment|/* precision control field */
end_comment

begin_define
define|#
directive|define
name|FP_RND_FLD
value|0xc00
end_define

begin_comment
comment|/* round control field */
end_comment

begin_define
define|#
directive|define
name|FP_STKY_FLD
value|0x3f
end_define

begin_comment
comment|/* sticky flags field */
end_comment

begin_comment
comment|/*  * FP register bit field offsets  */
end_comment

begin_define
define|#
directive|define
name|FP_MSKS_OFF
value|0
end_define

begin_comment
comment|/* exception masks offset */
end_comment

begin_define
define|#
directive|define
name|FP_PRC_OFF
value|8
end_define

begin_comment
comment|/* precision control offset */
end_comment

begin_define
define|#
directive|define
name|FP_RND_OFF
value|10
end_define

begin_comment
comment|/* round control offset */
end_comment

begin_define
define|#
directive|define
name|FP_STKY_OFF
value|0
end_define

begin_comment
comment|/* sticky flags offset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_IEEEFP_H_ */
end_comment

end_unit

