begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_SPROMREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_SPROMREG_H_
end_define

begin_define
define|#
directive|define
name|SPROM_SZ_R1_3
value|128
end_define

begin_comment
comment|/**< SPROM image size (rev 1-3) */
end_comment

begin_define
define|#
directive|define
name|SPROM_SZ_R4_8_9
value|440
end_define

begin_comment
comment|/**< SPROM image size (rev 4, 8-9) */
end_comment

begin_define
define|#
directive|define
name|SPROM_SZ_R10
value|460
end_define

begin_comment
comment|/**< SPROM image size (rev 10) */
end_comment

begin_define
define|#
directive|define
name|SPROM_SZ_R11
value|468
end_define

begin_comment
comment|/**< SPROM image size (rev 11) */
end_comment

begin_comment
comment|/** Maximum supported SPROM image size */
end_comment

begin_define
define|#
directive|define
name|SPROM_SZ_MAX
value|SPROM_SZ_R11
end_define

begin_define
define|#
directive|define
name|SPROM_SIG_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|SPROM_SIG_NONE_OFF
value|0x0
end_define

begin_comment
comment|/** SPROM signature (rev 4) */
end_comment

begin_define
define|#
directive|define
name|SPROM_SIG_R4
value|0x5372
end_define

begin_define
define|#
directive|define
name|SPROM_SIG_R4_OFF
value|64
end_define

begin_comment
comment|/**< SPROM signature offset (rev 4) */
end_comment

begin_comment
comment|/** SPROM signature (rev 8, 9) */
end_comment

begin_define
define|#
directive|define
name|SPROM_SIG_R8_9
value|SPROM_SIG_R4
end_define

begin_define
define|#
directive|define
name|SPROM_SIG_R8_9_OFF
value|128
end_define

begin_comment
comment|/**< SPROM signature offset (rev 8-9) */
end_comment

begin_comment
comment|/** SPROM signature (rev 10) */
end_comment

begin_define
define|#
directive|define
name|SPROM_SIG_R10
value|SPROM_SIG_R4
end_define

begin_define
define|#
directive|define
name|SPROM_SIG_R10_OFF
value|438
end_define

begin_comment
comment|/**< SPROM signature offset (rev 10) */
end_comment

begin_comment
comment|/** SPROM signature (rev 11) */
end_comment

begin_define
define|#
directive|define
name|SPROM_SIG_R11
value|0x0634
end_define

begin_define
define|#
directive|define
name|SPROM_SIG_R11_OFF
value|128
end_define

begin_comment
comment|/**< SPROM signature offset (rev 11) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_SPROMREG_H_ */
end_comment

end_unit

