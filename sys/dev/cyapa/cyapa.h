begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 The DragonFly Project.  All rights reserved.  *  * This code is derived from software contributed to The DragonFly Project  * by Matthew Dillon<dillon@backplane.com> and was subsequently ported  * to FreeBSD by Michael Gmelin<freebsd@grem.de>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DEV_SMBUS_CYAPA_CYAPA_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DEV_SMBUS_CYAPA_CYAPA_H_
end_define

begin_define
define|#
directive|define
name|CYAPA_MAX_MT
value|5
end_define

begin_comment
comment|/*  * Boot-time registers.  This is the device map  * if (stat& CYAPA_STAT_RUNNING) is 0.  */
end_comment

begin_struct
struct|struct
name|cyapa_boot_regs
block|{
name|uint8_t
name|stat
decl_stmt|;
comment|/* CYAPA_STAT_xxx */
name|uint8_t
name|boot
decl_stmt|;
comment|/* CYAPA_BOOT_xxx */
name|uint8_t
name|error
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|CYAPA_BOOT_BUSY
value|0x80
end_define

begin_define
define|#
directive|define
name|CYAPA_BOOT_RUNNING
value|0x10
end_define

begin_define
define|#
directive|define
name|CYAPA_BOOT_DATA_VALID
value|0x08
end_define

begin_define
define|#
directive|define
name|CYAPA_BOOT_CSUM_VALID
value|0x01
end_define

begin_define
define|#
directive|define
name|CYAPA_ERROR_INVALID
value|0x80
end_define

begin_define
define|#
directive|define
name|CYAPA_ERROR_INVALID_KEY
value|0x40
end_define

begin_define
define|#
directive|define
name|CYAPA_ERROR_BOOTLOADER
value|0x20
end_define

begin_define
define|#
directive|define
name|CYAPA_ERROR_CMD_CSUM
value|0x10
end_define

begin_define
define|#
directive|define
name|CYAPA_ERROR_FLASH_PROT
value|0x08
end_define

begin_define
define|#
directive|define
name|CYAPA_ERROR_FLASH_CSUM
value|0x04
end_define

begin_struct
struct|struct
name|cyapa_regs
block|{
name|uint8_t
name|stat
decl_stmt|;
name|uint8_t
name|fngr
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|xy_high
decl_stmt|;
comment|/* 7:4 high 4 bits of x */
name|uint8_t
name|x_low
decl_stmt|;
comment|/* 3:0 high 4 bits of y */
name|uint8_t
name|y_low
decl_stmt|;
name|uint8_t
name|pressure
decl_stmt|;
name|uint8_t
name|id
decl_stmt|;
comment|/* 1-15 incremented each touch */
block|}
name|touch
index|[
name|CYAPA_MAX_MT
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|cyapa_cap
block|{
name|uint8_t
name|prod_ida
index|[
literal|5
index|]
decl_stmt|;
comment|/* 0x00 - 0x04 */
name|uint8_t
name|prod_idb
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x05 - 0x0A */
name|uint8_t
name|prod_idc
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x0B - 0x0C */
name|uint8_t
name|reserved
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x0D - 0x12 */
name|uint8_t
name|buttons
decl_stmt|;
comment|/* 0x13 */
name|uint8_t
name|gen
decl_stmt|;
comment|/* 0x14, low 4 bits */
name|uint8_t
name|max_abs_xy_high
decl_stmt|;
comment|/* 0x15 7:4 high x bits, 3:0 high y bits */
name|uint8_t
name|max_abs_x_low
decl_stmt|;
comment|/* 0x16 */
name|uint8_t
name|max_abs_y_low
decl_stmt|;
comment|/* 0x17 */
name|uint8_t
name|phy_siz_xy_high
decl_stmt|;
comment|/* 0x18 7:4 high x bits, 3:0 high y bits */
name|uint8_t
name|phy_siz_x_low
decl_stmt|;
comment|/* 0x19 */
name|uint8_t
name|phy_siz_y_low
decl_stmt|;
comment|/* 0x1A */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|CYAPA_STAT_RUNNING
value|0x80
end_define

begin_define
define|#
directive|define
name|CYAPA_STAT_PWR_MASK
value|0x0C
end_define

begin_define
define|#
directive|define
name|CYAPA_PWR_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|CYAPA_PWR_IDLE
value|0x08
end_define

begin_define
define|#
directive|define
name|CYAPA_PWR_ACTIVE
value|0x0C
end_define

begin_define
define|#
directive|define
name|CYAPA_STAT_DEV_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|CYAPA_DEV_NORMAL
value|0x03
end_define

begin_define
define|#
directive|define
name|CYAPA_DEV_BUSY
value|0x01
end_define

begin_define
define|#
directive|define
name|CYAPA_FNGR_DATA_VALID
value|0x08
end_define

begin_define
define|#
directive|define
name|CYAPA_FNGR_MIDDLE
value|0x04
end_define

begin_define
define|#
directive|define
name|CYAPA_FNGR_RIGHT
value|0x02
end_define

begin_define
define|#
directive|define
name|CYAPA_FNGR_LEFT
value|0x01
end_define

begin_define
define|#
directive|define
name|CYAPA_FNGR_NUMFINGERS
parameter_list|(
name|c
parameter_list|)
value|(((c)>> 4)& 0x0F)
end_define

begin_define
define|#
directive|define
name|CYAPA_TOUCH_X
parameter_list|(
name|regs
parameter_list|,
name|i
parameter_list|)
value|((((regs)->touch[i].xy_high<< 4)& 0x0F00) | \ 				  (regs)->touch[i].x_low)
end_define

begin_define
define|#
directive|define
name|CYAPA_TOUCH_Y
parameter_list|(
name|regs
parameter_list|,
name|i
parameter_list|)
value|((((regs)->touch[i].xy_high<< 8)& 0x0F00) | \ 				  (regs)->touch[i].y_low)
end_define

begin_define
define|#
directive|define
name|CYAPA_TOUCH_P
parameter_list|(
name|regs
parameter_list|,
name|i
parameter_list|)
value|((regs)->touch[i].pressure)
end_define

begin_define
define|#
directive|define
name|CMD_BOOT_STATUS
value|0x00
end_define

begin_comment
comment|/* only if in boot state */
end_comment

begin_define
define|#
directive|define
name|CMD_DEV_STATUS
value|0x00
end_define

begin_comment
comment|/* only if in operational state */
end_comment

begin_define
define|#
directive|define
name|CMD_SOFT_RESET
value|0x28
end_define

begin_define
define|#
directive|define
name|CMD_POWER_MODE
value|0x29
end_define

begin_define
define|#
directive|define
name|CMD_POWER_MODE_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|CMD_POWER_MODE_IDLE
value|0x14
end_define

begin_define
define|#
directive|define
name|CMD_POWER_MODE_FULL
value|0xFC
end_define

begin_define
define|#
directive|define
name|CMD_QUERY_CAPABILITIES
value|0x2A
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

