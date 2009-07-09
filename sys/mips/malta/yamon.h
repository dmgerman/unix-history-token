begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2002 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Simon Burge for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed for the NetBSD Project by  *      Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MALTA_YAMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_MALTA_YAMON_H_
end_define

begin_define
define|#
directive|define
name|YAMON_FUNCTION_BASE
value|0x1fc00500ul
end_define

begin_define
define|#
directive|define
name|YAMON_PRINT_COUNT_OFS
value|(YAMON_FUNCTION_BASE + 0x04)
end_define

begin_define
define|#
directive|define
name|YAMON_EXIT_OFS
value|(YAMON_FUNCTION_BASE + 0x20)
end_define

begin_define
define|#
directive|define
name|YAMON_FLUSH_CACHE_OFS
value|(YAMON_FUNCTION_BASE + 0x2c)
end_define

begin_define
define|#
directive|define
name|YAMON_PRINT_OFS
value|(YAMON_FUNCTION_BASE + 0x34)
end_define

begin_define
define|#
directive|define
name|YAMON_REG_CPU_ISR_OFS
value|(YAMON_FUNCTION_BASE + 0x38)
end_define

begin_define
define|#
directive|define
name|YAMON_DEREG_CPU_ISR_OFS
value|(YAMON_FUNCTION_BASE + 0x3c)
end_define

begin_define
define|#
directive|define
name|YAMON_REG_IC_ISR_OFS
value|(YAMON_FUNCTION_BASE + 0x40)
end_define

begin_define
define|#
directive|define
name|YAMON_DEREG_IC_ISR_OFS
value|(YAMON_FUNCTION_BASE + 0x44)
end_define

begin_define
define|#
directive|define
name|YAMON_REG_ESR_OFS
value|(YAMON_FUNCTION_BASE + 0x48)
end_define

begin_define
define|#
directive|define
name|YAMON_DEREG_ESR_OFS
value|(YAMON_FUNCTION_BASE + 0x4c)
end_define

begin_define
define|#
directive|define
name|YAMON_GETCHAR_OFS
value|(YAMON_FUNCTION_BASE + 0x50)
end_define

begin_define
define|#
directive|define
name|YAMON_SYSCON_READ_OFS
value|(YAMON_FUNCTION_BASE + 0x54)
end_define

begin_define
define|#
directive|define
name|YAMON_FUNC
parameter_list|(
name|ofs
parameter_list|)
value|((long)(*(int32_t *)(MIPS_PHYS_TO_KSEG0(ofs))))
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|t_yamon_print_count
function_decl|)
parameter_list|(
name|uint32_t
name|port
parameter_list|,
name|char
modifier|*
name|s
parameter_list|,
name|uint32_t
name|count
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|YAMON_PRINT_COUNT
parameter_list|(
name|s
parameter_list|,
name|count
parameter_list|)
define|\
value|((t_yamon_print_count)(YAMON_FUNC(YAMON_PRINT_COUNT_OFS)))(0, s, count)
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|t_yamon_exit
function_decl|)
parameter_list|(
name|uint32_t
name|rc
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|YAMON_EXIT
parameter_list|(
name|rc
parameter_list|)
value|((t_yamon_exit)(YAMON_FUNC(YAMON_EXIT_OFS)))(rc)
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|t_yamon_print
function_decl|)
parameter_list|(
name|uint32_t
name|port
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|YAMON_PRINT
parameter_list|(
name|s
parameter_list|)
value|((t_yamon_print)(YAMON_FUNC(YAMON_PRINT_OFS)))(0, s)
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|t_yamon_getchar
function_decl|)
parameter_list|(
name|uint32_t
name|port
parameter_list|,
name|char
modifier|*
name|ch
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|YAMON_GETCHAR
parameter_list|(
name|ch
parameter_list|)
define|\
value|((t_yamon_getchar)(YAMON_FUNC(YAMON_GETCHAR_OFS)))(0, ch)
end_define

begin_typedef
typedef|typedef
name|int
name|t_yamon_syscon_id
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|t_yamon_syscon_read
function_decl|)
parameter_list|(
name|t_yamon_syscon_id
name|id
parameter_list|,
name|void
modifier|*
name|param
parameter_list|,
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|YAMON_SYSCON_READ
parameter_list|(
name|id
parameter_list|,
name|param
parameter_list|,
name|size
parameter_list|)
define|\
value|((t_yamon_syscon_read)(YAMON_FUNC(YAMON_SYSCON_READ_OFS)))	\ 	(id, param, size)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
name|yamon_env_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SYSCON_BOARD_CPU_CLOCK_FREQ_ID
value|34
end_define

begin_comment
comment|/* UINT32 */
end_comment

begin_define
define|#
directive|define
name|SYSCON_BOARD_BUS_CLOCK_FREQ_ID
value|35
end_define

begin_comment
comment|/* UINT32 */
end_comment

begin_define
define|#
directive|define
name|SYSCON_BOARD_PCI_FREQ_KHZ_ID
value|36
end_define

begin_comment
comment|/* UINT32 */
end_comment

begin_function_decl
name|char
modifier|*
name|yamon_getenv
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|yamon_getcpufreq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|yamon_env_t
modifier|*
name|fenvp
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MALTA_YAMON_H_ */
end_comment

end_unit

