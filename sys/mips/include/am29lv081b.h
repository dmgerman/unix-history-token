begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003, 2005, Juniper Networks, Inc.  * All rights reserved.  * JNPR: am29lv081b.h,v 1.1 2006/08/07 05:38:57 katta  *  * am29lv081b.h -- am29lv081b definitions   *  * Chan Lee, May 2000  */
end_comment

begin_comment
comment|// $FreeBSD$
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AM29LV081B_H__
end_ifndef

begin_define
define|#
directive|define
name|__AM29LV081B_H__
end_define

begin_comment
comment|/*  * Identifiers for the am29lv081b chip  */
end_comment

begin_define
define|#
directive|define
name|AM29L_MAN_ID
value|0x01
end_define

begin_define
define|#
directive|define
name|AM29L_DEV_ID
value|0x38
end_define

begin_define
define|#
directive|define
name|AM29L_DEV_ID_OFFSET
value|0x01
end_define

begin_define
define|#
directive|define
name|AM29L_TIMEOUT
value|3000
end_define

begin_comment
comment|/* 3 seconds in ms */
end_comment

begin_define
define|#
directive|define
name|AM29L_ERASE_TIME
value|30000
end_define

begin_comment
comment|/* 30 seconds in ms */
end_comment

begin_comment
comment|/*  * This is defined for human consumption.  */
end_comment

begin_define
define|#
directive|define
name|AM29L_BANNER
value|"AMD29L081B 8Mb flash"
end_define

begin_comment
comment|/*  * Sector definitions.  */
end_comment

begin_define
define|#
directive|define
name|AM29L_SA0
value|0x00000
end_define

begin_define
define|#
directive|define
name|AM29L_SA1
value|0x10000
end_define

begin_define
define|#
directive|define
name|AM29L_SA2
value|0x20000
end_define

begin_define
define|#
directive|define
name|AM29L_SA3
value|0x30000
end_define

begin_define
define|#
directive|define
name|AM29L_SA4
value|0x40000
end_define

begin_define
define|#
directive|define
name|AM29L_SA5
value|0x50000
end_define

begin_define
define|#
directive|define
name|AM29L_SA6
value|0x60000
end_define

begin_define
define|#
directive|define
name|AM29L_SA7
value|0x70000
end_define

begin_define
define|#
directive|define
name|AM29L_SA8
value|0x80000
end_define

begin_define
define|#
directive|define
name|AM29L_SA9
value|0x90000
end_define

begin_define
define|#
directive|define
name|AM29L_SA10
value|0xA0000
end_define

begin_define
define|#
directive|define
name|AM29L_SA11
value|0xB0000
end_define

begin_define
define|#
directive|define
name|AM29L_SA12
value|0xC0000
end_define

begin_define
define|#
directive|define
name|AM29L_SA13
value|0xD0000
end_define

begin_define
define|#
directive|define
name|AM29L_SA14
value|0xE0000
end_define

begin_define
define|#
directive|define
name|AM29L_SA15
value|0xF0000
end_define

begin_define
define|#
directive|define
name|AM29L_BANK_MASK
value|0xFFF00000
end_define

begin_define
define|#
directive|define
name|AM29L_SECTOR_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|AM29L_SECTOR_SIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|AM29L_SECTOR_PER_BLK
value|4
end_define

begin_define
define|#
directive|define
name|AM29L_TOTAL_SECTORS
value|16
end_define

begin_define
define|#
directive|define
name|AM29L_PROTECT_OFFSET
value|0x2
end_define

begin_comment
comment|/*  * Definitions for the unlock sequence, both  * the address offset and the data definition.  */
end_comment

begin_define
define|#
directive|define
name|AM29L_ULCK_ADDR1
value|0x555
end_define

begin_define
define|#
directive|define
name|AM29L_ULCK_ADDR2
value|0x2AA
end_define

begin_define
define|#
directive|define
name|AM29L_ULCK_DATA1
value|0xAA
end_define

begin_define
define|#
directive|define
name|AM29L_ULCK_DATA2
value|0x55
end_define

begin_comment
comment|/*  * Command definitions for the am29lv081b. Most  * of the following command can only be issue  * after the unlock command sequence.  */
end_comment

begin_define
define|#
directive|define
name|AM29L_CMD_AUTO
value|0x90
end_define

begin_define
define|#
directive|define
name|AM29L_CMD_BYTE_PROGRAM
value|0xA0
end_define

begin_define
define|#
directive|define
name|AM29L_CMD_ERASE
value|0x80
end_define

begin_define
define|#
directive|define
name|AM29L_CMD_ERASE_CHIP
value|0x10
end_define

begin_define
define|#
directive|define
name|AM29L_CMD_ERASE_SECT
value|0x30
end_define

begin_define
define|#
directive|define
name|AM29L_CMD_RESET
value|0xF0
end_define

begin_comment
comment|/*  * Masks for get the DQ3, DQ5, DQ6, DQ7 bits.  * All these bits signals the status of the  * command operations.  */
end_comment

begin_define
define|#
directive|define
name|AM29L_DQ2_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|AM29L_DQ3_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|AM29L_DQ5_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|AM29L_DQ6_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|AM29L_DQ7_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|AM29L_GET_DQ2
parameter_list|(
name|data
parameter_list|)
value|((data& AM29L_DQ2_MASK)>> 2)
end_define

begin_define
define|#
directive|define
name|AM29L_GET_DQ3
parameter_list|(
name|data
parameter_list|)
value|((data& AM29L_DQ3_MASK)>> 3)
end_define

begin_define
define|#
directive|define
name|AM29L_GET_DQ5
parameter_list|(
name|data
parameter_list|)
value|((data& AM29L_DQ5_MASK)>> 5)
end_define

begin_define
define|#
directive|define
name|AM29L_GET_DQ6
parameter_list|(
name|data
parameter_list|)
value|((data& AM29L_DQ6_MASK)>> 6)
end_define

begin_define
define|#
directive|define
name|AM29L_GET_DQ7
parameter_list|(
name|data
parameter_list|)
value|((data& AM29L_DQ7_MASK)>> 7)
end_define

begin_function_decl
specifier|extern
name|void
name|flash_add_amd29l081b
parameter_list|(
name|flash_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|u_int32_t
name|am29f_start_addr_flash
parameter_list|(
name|u_int8_t
modifier|*
name|ptr
parameter_list|)
block|{
return|return
operator|(
operator|(
name|u_int32_t
operator|)
name|ptr
operator|&
name|AM29L_SECTOR_MASK
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AM29LV081B_H_ */
end_comment

begin_comment
comment|/* End of file */
end_comment

end_unit

