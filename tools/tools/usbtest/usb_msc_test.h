begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_MSC_TEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_MSC_TEST_H_
end_define

begin_enum
enum|enum
block|{
name|USB_MSC_IO_MODE_READ_ONLY
block|,
name|USB_MSC_IO_MODE_WRITE_ONCE_READ_ONLY
block|,
name|USB_MSC_IO_MODE_WRITE_ONLY
block|,
name|USB_MSC_IO_MODE_READ_WRITE
block|,
name|USB_MSC_IO_MODE_MAX
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|USB_MSC_IO_PATTERN_FIXED
block|,
name|USB_MSC_IO_PATTERN_RANDOM
block|,
name|USB_MSC_IO_PATTERN_PRESERVE
block|,
name|USB_MSC_IO_PATTERN_MAX
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|USB_MSC_IO_SIZE_RANDOM
block|,
name|USB_MSC_IO_SIZE_INCREASING
block|,
name|USB_MSC_IO_SIZE_FIXED_1BLK
block|,
name|USB_MSC_IO_SIZE_FIXED_2BLK
block|,
name|USB_MSC_IO_SIZE_FIXED_4BLK
block|,
name|USB_MSC_IO_SIZE_FIXED_8BLK
block|,
name|USB_MSC_IO_SIZE_FIXED_16BLK
block|,
name|USB_MSC_IO_SIZE_FIXED_32BLK
block|,
name|USB_MSC_IO_SIZE_FIXED_64BLK
block|,
name|USB_MSC_IO_SIZE_FIXED_128BLK
block|,
name|USB_MSC_IO_SIZE_FIXED_256BLK
block|,
name|USB_MSC_IO_SIZE_FIXED_512BLK
block|,
name|USB_MSC_IO_SIZE_FIXED_1024BLK
block|,
name|USB_MSC_IO_SIZE_MAX
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|USB_MSC_IO_DELAY_NONE
block|,
name|USB_MSC_IO_DELAY_RANDOM_10MS
block|,
name|USB_MSC_IO_DELAY_RANDOM_100MS
block|,
name|USB_MSC_IO_DELAY_FIXED_10MS
block|,
name|USB_MSC_IO_DELAY_FIXED_100MS
block|,
name|USB_MSC_IO_DELAY_MAX
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|USB_MSC_IO_OFF_START_OF_DISK
block|,
name|USB_MSC_IO_OFF_RANDOM
block|,
name|USB_MSC_IO_OFF_MAX
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|USB_MSC_IO_AREA_COMPLETE
block|,
name|USB_MSC_IO_AREA_1MB
block|,
name|USB_MSC_IO_AREA_16MB
block|,
name|USB_MSC_IO_AREA_256MB
block|,
name|USB_MSC_IO_AREA_MAX
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|USB_MSC_IO_LUN_0
block|,
name|USB_MSC_IO_LUN_1
block|,
name|USB_MSC_IO_LUN_2
block|,
name|USB_MSC_IO_LUN_3
block|,
name|USB_MSC_IO_LUN_MAX
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|usb_msc_params
block|{
name|uint32_t
name|duration
decl_stmt|;
name|uint32_t
name|max_errors
decl_stmt|;
comment|/* See "USB_MSC_XXX" enums */
name|uint8_t
name|io_mode
decl_stmt|;
name|uint8_t
name|io_size
decl_stmt|;
name|uint8_t
name|io_delay
decl_stmt|;
name|uint8_t
name|io_offset
decl_stmt|;
name|uint8_t
name|io_area
decl_stmt|;
name|uint8_t
name|io_pattern
decl_stmt|;
name|uint8_t
name|io_lun
decl_stmt|;
comment|/* booleans */
name|uint8_t
name|try_invalid_scsi_command
decl_stmt|;
name|uint8_t
name|try_invalid_wrapper_block
decl_stmt|;
name|uint8_t
name|try_invalid_max_packet_size
decl_stmt|;
name|uint8_t
name|try_shorter_wrapper_block
decl_stmt|;
name|uint8_t
name|try_last_lba
decl_stmt|;
name|uint8_t
name|try_abort_data_write
decl_stmt|;
name|uint8_t
name|try_sense_on_error
decl_stmt|;
name|uint8_t
name|try_all_lun
decl_stmt|;
name|uint8_t
name|done
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_MSC_TEST_H_ */
end_comment

end_unit

