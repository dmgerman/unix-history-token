begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *       Copyright (c) 1997 by Simon Shapiro  *       All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: softisr.h,v 1.1.2.1 1998/03/06 23:44:18 julian Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SOFTISR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SOFTISR_H_
end_define

begin_comment
comment|/*  *	The following manifest constants are named w/o  *	regard to imagination  */
end_comment

begin_define
define|#
directive|define
name|DPTISR_DPT
value|0
end_define

begin_define
define|#
directive|define
name|DPTISR_1
value|1
end_define

begin_define
define|#
directive|define
name|DPTISR_2
value|2
end_define

begin_define
define|#
directive|define
name|DPTISR_3
value|3
end_define

begin_define
define|#
directive|define
name|DPTISR_4
value|4
end_define

begin_define
define|#
directive|define
name|DPTISR_5
value|5
end_define

begin_define
define|#
directive|define
name|DPTISR_6
value|6
end_define

begin_define
define|#
directive|define
name|DPTISR_7
value|7
end_define

begin_define
define|#
directive|define
name|DPTISR_8
value|8
end_define

begin_define
define|#
directive|define
name|DPTISR_9
value|9
end_define

begin_define
define|#
directive|define
name|DPTISR_10
value|10
end_define

begin_define
define|#
directive|define
name|DPTISR_11
value|11
end_define

begin_define
define|#
directive|define
name|DPTISR_12
value|12
end_define

begin_define
define|#
directive|define
name|DPTISR_13
value|13
end_define

begin_define
define|#
directive|define
name|DPTISR_14
value|14
end_define

begin_define
define|#
directive|define
name|DPTISR_15
value|15
end_define

begin_define
define|#
directive|define
name|DPTISR_16
value|16
end_define

begin_define
define|#
directive|define
name|DPTISR_17
value|17
end_define

begin_define
define|#
directive|define
name|DPTISR_18
value|18
end_define

begin_define
define|#
directive|define
name|DPTISR_19
value|19
end_define

begin_define
define|#
directive|define
name|DPTISR_20
value|20
end_define

begin_define
define|#
directive|define
name|DPTISR_21
value|21
end_define

begin_define
define|#
directive|define
name|DPTISR_22
value|22
end_define

begin_define
define|#
directive|define
name|DPTISR_23
value|23
end_define

begin_define
define|#
directive|define
name|DPTISR_24
value|24
end_define

begin_define
define|#
directive|define
name|DPTISR_25
value|25
end_define

begin_define
define|#
directive|define
name|DPTISR_26
value|26
end_define

begin_define
define|#
directive|define
name|DPTISR_27
value|27
end_define

begin_define
define|#
directive|define
name|DPTISR_28
value|28
end_define

begin_define
define|#
directive|define
name|DPTISR_29
value|29
end_define

begin_define
define|#
directive|define
name|DPTISR_30
value|30
end_define

begin_define
define|#
directive|define
name|DPTISR_31
value|31
end_define

begin_comment
comment|/*  *	equivalent to schednetisr() for the DPT driver  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|setsoftdpt
end_ifndef

begin_function_decl
specifier|extern
name|void
name|setsoftdpt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|scheddptisr
parameter_list|(
name|anisr
parameter_list|)
value|{ dptisr |= 1<<(anisr); setsoftdpt(); }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
specifier|volatile
name|unsigned
name|int
name|dptisr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scheduling bits for DPT driver */
end_comment

begin_typedef
typedef|typedef
name|void
name|dptisr_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|dptisrtab
block|{
name|int
name|sint_num
decl_stmt|;
name|dptisr_t
modifier|*
name|sint_isr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DPTISR_SET
parameter_list|(
name|num
parameter_list|,
name|isr
parameter_list|)
define|\
value|static struct dptisrtab mod_sint = { num, isr}; \ 	DATA_SET(dptisr_set, mod_sint);
end_define

begin_decl_stmt
name|int
name|register_dptisr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|dptisr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifdef  KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _SOFTISR_H_ */
end_comment

end_unit

