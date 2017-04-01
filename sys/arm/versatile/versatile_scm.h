begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017 Oleksandr Tymoshenko<gonzo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Ben Gray.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BEN GRAY ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BEN GRAY BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VERSATILE_SCM_H_
end_ifndef

begin_define
define|#
directive|define
name|_VERSATILE_SCM_H_
end_define

begin_define
define|#
directive|define
name|SCM_PCICTL
value|0x44
end_define

begin_define
define|#
directive|define
name|SCM_CLCD
value|0x50
end_define

begin_define
define|#
directive|define
name|SCM_CLCD_CLCDID_SHIFT
value|0x08
end_define

begin_define
define|#
directive|define
name|SCM_CLCD_CLCDID_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|SCM_CLCD_PWR3V5VSWITCH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SCM_CLCD_VDDPOSSWITCH
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SCM_CLCD_NLCDIOON
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SCM_CLCD_LCD_MODE_MASK
value|0x03
end_define

begin_function_decl
name|int
name|versatile_scm_reg_read_4
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|versatile_scm_reg_write_4
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VERSATILE_SCM_H_ */
end_comment

end_unit

