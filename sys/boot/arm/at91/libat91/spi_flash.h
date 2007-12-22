begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Filename: spi_flash.h  *  * Definition of flash control routines supporting AT45DB161B  *  * Revision information:  *  * 17JAN2005	kb_admin	initial creation  *  * BEGIN_KBDD_BLOCK  * No warranty, expressed or implied, is included with this software.  It is  * provided "AS IS" and no warranty of any kind including statutory or aspects  * relating to merchantability or fitness for any purpose is provided.  All  * intellectual property rights of others is maintained with the respective  * owners.  This software is not copyrighted and is intended for reference  * only.  * END_BLOCK  *  * $FreeBSD$  ******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPI_FLASH_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPI_FLASH_H_
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|tx_cmd
decl_stmt|;
name|unsigned
name|tx_cmd_size
decl_stmt|;
name|char
modifier|*
name|rx_cmd
decl_stmt|;
name|unsigned
name|rx_cmd_size
decl_stmt|;
name|char
modifier|*
name|tx_data
decl_stmt|;
name|unsigned
name|tx_data_size
decl_stmt|;
name|char
modifier|*
name|rx_data
decl_stmt|;
name|unsigned
name|rx_data_size
decl_stmt|;
block|}
name|spiCommand_t
typedef|;
end_typedef

begin_function_decl
name|void
name|SPI_ReadFlash
parameter_list|(
name|unsigned
name|flash_addr
parameter_list|,
name|char
modifier|*
name|dest_addr
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SPI_WriteFlash
parameter_list|(
name|unsigned
name|flash_addr
parameter_list|,
name|char
modifier|*
name|dest_addr
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SPI_InitFlash
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SPI_GetId
parameter_list|(
name|unsigned
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BOOT_BWCT
end_ifdef

begin_define
define|#
directive|define
name|FLASH_PAGE_SIZE
value|528
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FLASH_PAGE_SIZE
value|1056
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Flash commands
end_comment

begin_define
define|#
directive|define
name|CONTINUOUS_ARRAY_READ
value|0xE8
end_define

begin_define
define|#
directive|define
name|CONTINUOUS_ARRAY_READ_HF
value|0x0B
end_define

begin_define
define|#
directive|define
name|CONTINUOUS_ARRAY_READ_LF
value|0x03
end_define

begin_define
define|#
directive|define
name|STATUS_REGISTER_READ
value|0xD7
end_define

begin_define
define|#
directive|define
name|PROGRAM_THROUGH_BUFFER
value|0x82
end_define

begin_define
define|#
directive|define
name|MANUFACTURER_ID
value|0x9F
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

