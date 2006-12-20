begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AT91RM9200_LOWLEVEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_AT91RM9200_LOWLEVEL_H_
end_define

begin_comment
comment|/* default system config parameters */
end_comment

begin_define
define|#
directive|define
name|SDRAM_BASE
value|0x20000000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BOOT_KB920X
end_ifdef

begin_comment
comment|/* The following divisor sets PLLA frequency: e.g. 10/5 * 90 = 180MHz */
end_comment

begin_define
define|#
directive|define
name|OSC_MAIN_FREQ_DIV
value|5
end_define

begin_comment
comment|/* for 10MHz osc */
end_comment

begin_define
define|#
directive|define
name|SDRAM_WIDTH
value|AT91C_SDRC_DBW_16_BITS
end_define

begin_typedef
typedef|typedef
name|unsigned
name|short
name|sdram_size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OSC_MAIN_MULT
value|90
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BOOT_BWCT
end_ifdef

begin_comment
comment|/* The following divisor sets PLLA frequency: e.g. 16/4 * 45 = 180MHz */
end_comment

begin_define
define|#
directive|define
name|OSC_MAIN_FREQ_DIV
value|4
end_define

begin_comment
comment|/* for 16MHz osc */
end_comment

begin_define
define|#
directive|define
name|SDRAM_WIDTH
value|AT91C_SDRC_DBW_32_BITS
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|sdram_size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OSC_MAIN_MULT
value|45
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BOOT_TSC
end_ifdef

begin_comment
comment|/* The following divisor sets PLLA frequency: e.g. 16/4 * 45 = 180MHz */
end_comment

begin_define
define|#
directive|define
name|OSC_MAIN_FREQ_DIV
value|4
end_define

begin_comment
comment|/* for 16MHz osc */
end_comment

begin_define
define|#
directive|define
name|SDRAM_WIDTH
value|AT91C_SDRC_DBW_32_BITS
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|sdram_size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OSC_MAIN_MULT
value|45
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Master clock frequency at power-up */
end_comment

begin_define
define|#
directive|define
name|AT91C_MASTER_CLOCK
value|60000000
end_define

begin_define
define|#
directive|define
name|GetSeconds
parameter_list|()
value|(AT91C_BASE_RTC->RTC_TIMR& AT91C_RTC_SEC)
end_define

begin_function_decl
specifier|extern
name|void
name|_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AT91RM9200_LOWLEVEL_H_ */
end_comment

end_unit

