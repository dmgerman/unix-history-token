begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2001 by Thomas Moestl<tmm@FreeBSD.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_LSU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_LSU_H_
end_define

begin_comment
comment|/*  * Definitions for the Load-Store-Unit Control Register. This is called  * Data Cache Unit Control Register (DCUCR) for UltraSPARC-III.  */
end_comment

begin_define
define|#
directive|define
name|LSU_IC
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|LSU_DC
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|LSU_IM
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|LSU_DM
value|(1UL<< 3)
end_define

begin_comment
comment|/* Parity control mask, UltraSPARC-I and II series only. */
end_comment

begin_define
define|#
directive|define
name|LSU_FM_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|LSU_FM_BITS
value|16
end_define

begin_define
define|#
directive|define
name|LSU_FM_MASK
value|(((1UL<< LSU_FM_BITS) - 1)<< LSU_FM_SHIFT)
end_define

begin_define
define|#
directive|define
name|LSU_VM_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|LSU_VM_BITS
value|8
end_define

begin_define
define|#
directive|define
name|LSU_VM_MASK
value|(((1UL<< LSU_VM_BITS) - 1)<< LSU_VM_SHIFT)
end_define

begin_define
define|#
directive|define
name|LSU_PM_SHIFT
value|33
end_define

begin_define
define|#
directive|define
name|LSU_PM_BITS
value|8
end_define

begin_define
define|#
directive|define
name|LSU_PM_MASK
value|(((1UL<< LSU_PM_BITS) - 1)<< LSU_PM_SHIFT)
end_define

begin_define
define|#
directive|define
name|LSU_VW
value|(1UL<< 21)
end_define

begin_define
define|#
directive|define
name|LSU_VR
value|(1UL<< 22)
end_define

begin_define
define|#
directive|define
name|LSU_PW
value|(1UL<< 23)
end_define

begin_define
define|#
directive|define
name|LSU_PR
value|(1UL<< 24)
end_define

begin_comment
comment|/* The following bits are valid for the UltraSPARC-III series only. */
end_comment

begin_define
define|#
directive|define
name|LSU_WE
value|(1UL<< 41)
end_define

begin_define
define|#
directive|define
name|LSU_SL
value|(1UL<< 42)
end_define

begin_define
define|#
directive|define
name|LSU_SPE
value|(1UL<< 43)
end_define

begin_define
define|#
directive|define
name|LSU_HPE
value|(1UL<< 44)
end_define

begin_define
define|#
directive|define
name|LSU_PE
value|(1UL<< 45)
end_define

begin_define
define|#
directive|define
name|LSU_RE
value|(1UL<< 46)
end_define

begin_define
define|#
directive|define
name|LSU_ME
value|(1UL<< 47)
end_define

begin_define
define|#
directive|define
name|LSU_CV
value|(1UL<< 48)
end_define

begin_define
define|#
directive|define
name|LSU_CP
value|(1UL<< 49)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_LSU_H_ */
end_comment

end_unit

