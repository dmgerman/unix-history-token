begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2011 Broadcom Corporation. All rights reserved.  *  *    Gary Zambrano<zambrano@broadcom.com>  *    David Christensen<davidch@broadcom.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of Broadcom Corporation nor the name of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written consent.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HW_DUMP_REG_ST_H
end_ifndef

begin_define
define|#
directive|define
name|_HW_DUMP_REG_ST_H
end_define

begin_define
define|#
directive|define
name|BXE_GRCDUMP_BUF_SIZE
value|0xE0000
end_define

begin_define
define|#
directive|define
name|XSTORM_WAITP_ADDRESS
value|0x2b8a80
end_define

begin_define
define|#
directive|define
name|TSTORM_WAITP_ADDRESS
value|0x2b8a80
end_define

begin_define
define|#
directive|define
name|USTORM_WAITP_ADDRESS
value|0x2b8a80
end_define

begin_define
define|#
directive|define
name|CSTORM_WAITP_ADDRESS
value|0x2b8a80
end_define

begin_define
define|#
directive|define
name|TSTORM_CAM_MODE
value|0x1B1440
end_define

begin_comment
comment|/* Register address structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|reg_addr
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
block|}
typedef|*
name|preg_addr
typedef|;
end_typedef

begin_comment
comment|/* Wide register address structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|wreg_addr
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|uint32_t
name|const_regs_count
decl_stmt|;
name|uint32_t
modifier|*
name|const_regs
decl_stmt|;
block|}
typedef|*
name|pwreg_addr
typedef|;
end_typedef

begin_comment
comment|/* Dump header parameters. */
end_comment

begin_struct
struct|struct
name|hd_param
block|{
name|uint32_t
name|time_stamp
decl_stmt|;
name|uint32_t
name|diag_ver
decl_stmt|;
name|uint32_t
name|grc_dump_ver
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global parameters. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|wreg_addr
name|wreg_addrs_e1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|reg_addr
name|reg_addrs_e1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|regs_count_e1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|wregs_count_e1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|hd_param
name|hd_param_e1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|wreg_addr
name|wreg_addrs_e1h
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|reg_addr
name|reg_addrs_e1h
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|regs_count_e1h
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|wregs_count_e1h
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|hd_param
name|hd_param_e1h
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//_HW_DUMP_REG_ST_H
end_comment

end_unit

