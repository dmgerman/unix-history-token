begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file contains definitions for the SPD fields on an SDRAM.    Copyright (c) 2007 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SDRAM_SPD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SDRAM_SPD_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/SdramSpdDdr3.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/SdramSpdDdr4.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/SdramSpdLpDdr.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// SDRAM SPD field definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SPD_MEMORY_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_ROW_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_COL_ADDR
value|4
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_MODULE_ROWS
value|5
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_MODULE_DATA_WIDTH_LSB
value|6
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_MODULE_DATA_WIDTH_MSB
value|7
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_ECC_SUPPORT
value|11
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_REFRESH
value|12
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_WIDTH
value|13
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_ERROR_WIDTH
value|14
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_BURST_LENGTH
value|16
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_NO_OF_BANKS
value|17
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_CAS_LATENCY
value|18
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_MODULE_ATTR
value|21
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_TCLK1_PULSE
value|9
end_define

begin_comment
comment|///< cycle time for highest cas latency
end_comment

begin_define
define|#
directive|define
name|SPD_SDRAM_TAC1_PULSE
value|10
end_define

begin_comment
comment|///< access time for highest cas latency
end_comment

begin_define
define|#
directive|define
name|SPD_SDRAM_TCLK2_PULSE
value|23
end_define

begin_comment
comment|///< cycle time for 2nd highest cas latency
end_comment

begin_define
define|#
directive|define
name|SPD_SDRAM_TAC2_PULSE
value|24
end_define

begin_comment
comment|///< access time for 2nd highest cas latency
end_comment

begin_define
define|#
directive|define
name|SPD_SDRAM_TCLK3_PULSE
value|25
end_define

begin_comment
comment|///< cycle time for 3rd highest cas latency
end_comment

begin_define
define|#
directive|define
name|SPD_SDRAM_TAC3_PULSE
value|26
end_define

begin_comment
comment|///< access time for 3rd highest cas latency
end_comment

begin_define
define|#
directive|define
name|SPD_SDRAM_MIN_PRECHARGE
value|27
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_ACTIVE_MIN
value|28
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_RAS_CAS
value|29
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_RAS_PULSE
value|30
end_define

begin_define
define|#
directive|define
name|SPD_SDRAM_DENSITY
value|31
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Memory Type Definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SPD_VAL_SDR_TYPE
value|4
end_define

begin_comment
comment|///< SDR SDRAM memory
end_comment

begin_define
define|#
directive|define
name|SPD_VAL_DDR_TYPE
value|7
end_define

begin_comment
comment|///< DDR SDRAM memory
end_comment

begin_define
define|#
directive|define
name|SPD_VAL_DDR2_TYPE
value|8
end_define

begin_comment
comment|///< DDR2 SDRAM memory
end_comment

begin_define
define|#
directive|define
name|SPD_VAL_DDR3_TYPE
value|11
end_define

begin_comment
comment|///< DDR3 SDRAM memory
end_comment

begin_define
define|#
directive|define
name|SPD_VAL_DDR4_TYPE
value|12
end_define

begin_comment
comment|///< DDR4 SDRAM memory
end_comment

begin_define
define|#
directive|define
name|SPD_VAL_LPDDR3_TYPE
value|15
end_define

begin_comment
comment|///< LPDDR3 SDRAM memory
end_comment

begin_define
define|#
directive|define
name|SPD_VAL_LPDDR4_TYPE
value|16
end_define

begin_comment
comment|///< LPDDR4 SDRAM memory
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ECC Type Definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SPD_ECC_TYPE_NONE
value|0x00
end_define

begin_comment
comment|///< No error checking
end_comment

begin_define
define|#
directive|define
name|SPD_ECC_TYPE_PARITY
value|0x01
end_define

begin_comment
comment|///< No error checking
end_comment

begin_define
define|#
directive|define
name|SPD_ECC_TYPE_ECC
value|0x02
end_define

begin_comment
comment|///< Error checking only
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Module Attributes (Bit positions)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SPD_BUFFERED
value|0x01
end_define

begin_define
define|#
directive|define
name|SPD_REGISTERED
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

