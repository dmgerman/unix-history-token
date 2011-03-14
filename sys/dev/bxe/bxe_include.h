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
name|_BXE_INCLUDE_H
end_ifndef

begin_define
define|#
directive|define
name|_BXE_INCLUDE_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/*  * Convert FreeBSD byte order to match generated code usage.  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|__BIG_ENDIAN
value|1
end_define

begin_undef
undef|#
directive|undef
name|__LITTLE_ENDIAN
end_undef

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|__BIG_ENDIAN
end_undef

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"bxe_debug.h"
end_include

begin_include
include|#
directive|include
file|"bxe_reg.h"
end_include

begin_include
include|#
directive|include
file|"bxe_fw_defs.h"
end_include

begin_include
include|#
directive|include
file|"bxe_hsi.h"
end_include

begin_include
include|#
directive|include
file|"bxe_link.h"
end_include

begin_comment
comment|/*  * Convenience definitions used in multiple files.  */
end_comment

begin_define
define|#
directive|define
name|BXE_PRINTF
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {										\ 		device_printf(sc->bxe_dev, fmt, ##args);\ 	}while(0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BXE_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|REG_WR
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bxe_reg_write32(sc, offset, val)
end_define

begin_define
define|#
directive|define
name|REG_WR8
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bxe_reg_write8(sc, offset, val)
end_define

begin_define
define|#
directive|define
name|REG_WR16
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bxe_reg_write16(sc, offset, val)
end_define

begin_define
define|#
directive|define
name|REG_WR32
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bxe_reg_write32(sc, offset, val)
end_define

begin_define
define|#
directive|define
name|REG_RD
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bxe_reg_read32(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_RD8
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bxe_reg_read8(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_RD16
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bxe_reg_read16(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_RD32
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bxe_reg_read32(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_RD_IND
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bxe_reg_rd_ind(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_WR_IND
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bxe_reg_wr_ind(sc, offset, val)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_WR
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->bxe_btag, sc->bxe_bhandle, offset, val)
end_define

begin_define
define|#
directive|define
name|REG_WR8
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1(sc->bxe_btag, sc->bxe_bhandle, offset, val)
end_define

begin_define
define|#
directive|define
name|REG_WR16
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2(sc->bxe_btag, sc->bxe_bhandle, offset, val)
end_define

begin_define
define|#
directive|define
name|REG_WR32
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->bxe_btag, sc->bxe_bhandle, offset, val)
end_define

begin_define
define|#
directive|define
name|REG_RD
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_4(sc->bxe_btag, sc->bxe_bhandle, offset)
end_define

begin_define
define|#
directive|define
name|REG_RD8
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_1(sc->bxe_btag, sc->bxe_bhandle, offset)
end_define

begin_define
define|#
directive|define
name|REG_RD16
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_2(sc->bxe_btag, sc->bxe_bhandle, offset)
end_define

begin_define
define|#
directive|define
name|REG_RD32
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_4(sc->bxe_btag, sc->bxe_bhandle, offset)
end_define

begin_define
define|#
directive|define
name|REG_RD_IND
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bxe_reg_rd_ind(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_WR_IND
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bxe_reg_wr_ind(sc, offset, val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BXE_DEBUG */
end_comment

begin_define
define|#
directive|define
name|REG_RD_DMAE
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|,
name|len32
parameter_list|)
define|\
value|do {												\ 		bxe_read_dmae(sc, offset, len32);				\ 		memcpy(val, BXE_SP(sc, wb_data[0]), len32 * 4); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|REG_WR_DMAE
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|,
name|len32
parameter_list|)
define|\
value|do { 												\ 		memcpy(BXE_SP(sc, wb_data[0]), val, len32 * 4); \ 		bxe_write_dmae(sc, BXE_SP_MAPPING(sc, wb_data), \ 			offset, len32);								\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SHMEM_ADDR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
value|(sc->common.shmem_base + \ 	offsetof(struct shmem_region, field))
end_define

begin_define
define|#
directive|define
name|SHMEM_RD
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
define|\
value|REG_RD(sc, SHMEM_ADDR(sc, field))
end_define

begin_define
define|#
directive|define
name|SHMEM_RD16
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
define|\
value|REG_RD16(sc, SHMEM_ADDR(sc, field))
end_define

begin_define
define|#
directive|define
name|SHMEM_WR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
define|\
value|REG_WR(sc, SHMEM_ADDR(sc, field), val)
end_define

begin_define
define|#
directive|define
name|SHMEM2_ADDR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
value|(sc->common.shmem2_base + \ 									 offsetof(struct shmem2_region, field))
end_define

begin_define
define|#
directive|define
name|SHMEM2_RD
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
value|REG_RD(sc, SHMEM2_ADDR(sc, field))
end_define

begin_define
define|#
directive|define
name|SHMEM2_WR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
value|REG_WR(sc, SHMEM2_ADDR(sc, field), val)
end_define

begin_define
define|#
directive|define
name|EMAC_RD
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|REG_RD(sc, emac_base + (uint32_t) reg)
end_define

begin_define
define|#
directive|define
name|EMAC_WR
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|REG_WR(sc, emac_base + (uint32_t) reg, val)
end_define

begin_define
define|#
directive|define
name|BMAC_WR
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|REG_WR(sc, GRCBASE_NIG + bmac_addr + reg, val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BXE_INCLUDE_H */
end_comment

end_unit

