begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)fsr.h	7.3 (Berkeley) %G%  *  * from: $Header: fsr.h,v 1.6 92/11/26 02:04:36 torek Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FSR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FSR_H_
end_define

begin_comment
comment|/*  * Bits in FSR.  */
end_comment

begin_define
define|#
directive|define
name|FSR_RD
value|0xc0000000
end_define

begin_comment
comment|/* rounding direction */
end_comment

begin_define
define|#
directive|define
name|FSR_RD_RN
value|0
end_define

begin_comment
comment|/* round to nearest */
end_comment

begin_define
define|#
directive|define
name|FSR_RD_RZ
value|1
end_define

begin_comment
comment|/* round towards 0 */
end_comment

begin_define
define|#
directive|define
name|FSR_RD_RP
value|2
end_define

begin_comment
comment|/* round towards +inf */
end_comment

begin_define
define|#
directive|define
name|FSR_RD_RM
value|3
end_define

begin_comment
comment|/* round towards -inf */
end_comment

begin_define
define|#
directive|define
name|FSR_RD_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|FSR_RD_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|FSR_RP
value|0x30000000
end_define

begin_comment
comment|/* extended rounding precision */
end_comment

begin_define
define|#
directive|define
name|FSR_RP_X
value|0
end_define

begin_comment
comment|/* extended stays extended */
end_comment

begin_define
define|#
directive|define
name|FSR_RP_S
value|1
end_define

begin_comment
comment|/* extended => single */
end_comment

begin_define
define|#
directive|define
name|FSR_RP_D
value|2
end_define

begin_comment
comment|/* extended => double */
end_comment

begin_define
define|#
directive|define
name|FSR_RP_80
value|3
end_define

begin_comment
comment|/* extended => 80-bit */
end_comment

begin_define
define|#
directive|define
name|FSR_RP_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|FSR_RP_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|FSR_TEM
value|0x0f800000
end_define

begin_comment
comment|/* trap enable mask */
end_comment

begin_define
define|#
directive|define
name|FSR_TEM_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|FSR_TEM_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|FSR_NS
value|0x00400000
end_define

begin_comment
comment|/* ``nonstandard mode'' */
end_comment

begin_define
define|#
directive|define
name|FSR_AU
value|0x00400000
end_define

begin_comment
comment|/* aka abrupt underflow mode */
end_comment

begin_define
define|#
directive|define
name|FSR_MBZ
value|0x00300000
end_define

begin_comment
comment|/* reserved; must be zero */
end_comment

begin_define
define|#
directive|define
name|FSR_VER
value|0x000e0000
end_define

begin_comment
comment|/* version bits */
end_comment

begin_define
define|#
directive|define
name|FSR_VER_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|FSR_VER_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|FSR_FTT
value|0x0001c000
end_define

begin_comment
comment|/* FP trap type */
end_comment

begin_define
define|#
directive|define
name|FSR_TT_NONE
value|0
end_define

begin_comment
comment|/* no trap */
end_comment

begin_define
define|#
directive|define
name|FSR_TT_IEEE
value|1
end_define

begin_comment
comment|/* IEEE exception */
end_comment

begin_define
define|#
directive|define
name|FSR_TT_UNFIN
value|2
end_define

begin_comment
comment|/* unfinished operation */
end_comment

begin_define
define|#
directive|define
name|FSR_TT_UNIMP
value|3
end_define

begin_comment
comment|/* unimplemented operation */
end_comment

begin_define
define|#
directive|define
name|FSR_TT_SEQ
value|4
end_define

begin_comment
comment|/* sequence error */
end_comment

begin_define
define|#
directive|define
name|FSR_TT_HWERR
value|5
end_define

begin_comment
comment|/* hardware error (unrecoverable) */
end_comment

begin_define
define|#
directive|define
name|FSR_FTT_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|FSR_FTT_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|FSR_QNE
value|0x00002000
end_define

begin_comment
comment|/* queue not empty */
end_comment

begin_define
define|#
directive|define
name|FSR_PR
value|0x00001000
end_define

begin_comment
comment|/* partial result */
end_comment

begin_define
define|#
directive|define
name|FSR_FCC
value|0x00000c00
end_define

begin_comment
comment|/* FP condition codes */
end_comment

begin_define
define|#
directive|define
name|FSR_CC_EQ
value|0
end_define

begin_comment
comment|/* f1 = f2 */
end_comment

begin_define
define|#
directive|define
name|FSR_CC_LT
value|1
end_define

begin_comment
comment|/* f1< f2 */
end_comment

begin_define
define|#
directive|define
name|FSR_CC_GT
value|2
end_define

begin_comment
comment|/* f1> f2 */
end_comment

begin_define
define|#
directive|define
name|FSR_CC_UO
value|3
end_define

begin_comment
comment|/* (f1,f2) unordered */
end_comment

begin_define
define|#
directive|define
name|FSR_FCC_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|FSR_FCC_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|FSR_AX
value|0x000003e0
end_define

begin_comment
comment|/* accrued exceptions */
end_comment

begin_define
define|#
directive|define
name|FSR_AX_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|FSR_AX_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|FSR_CX
value|0x0000001f
end_define

begin_comment
comment|/* current exceptions */
end_comment

begin_define
define|#
directive|define
name|FSR_CX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FSR_CX_MASK
value|0x1f
end_define

begin_comment
comment|/* The following exceptions apply to TEM, AX, and CX. */
end_comment

begin_define
define|#
directive|define
name|FSR_NV
value|0x10
end_define

begin_comment
comment|/* invalid operand */
end_comment

begin_define
define|#
directive|define
name|FSR_OF
value|0x08
end_define

begin_comment
comment|/* overflow */
end_comment

begin_define
define|#
directive|define
name|FSR_UF
value|0x04
end_define

begin_comment
comment|/* underflow */
end_comment

begin_define
define|#
directive|define
name|FSR_DZ
value|0x02
end_define

begin_comment
comment|/* division by zero */
end_comment

begin_define
define|#
directive|define
name|FSR_NX
value|0x01
end_define

begin_comment
comment|/* inexact result */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_FSR_H_ */
end_comment

end_unit

