begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is part of the Chelsio T4/T5/T6 Ethernet driver.  *  * Copyright (C) 2003-2016 Chelsio Communications.  All rights reserved.  *  * This program is distributed in the hope that it will be useful, but WITHOUT  * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  * FITNESS FOR A PARTICULAR PURPOSE.  See the LICENSE file included in this  * release for licensing terms and conditions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_CHIP_TYPE_H__
end_ifndef

begin_define
define|#
directive|define
name|__T4_CHIP_TYPE_H__
end_define

begin_comment
comment|/*  * All T4 and later chips have their PCI-E Device IDs encoded as 0xVFPP where:  *  *   V  = "4" for T4; "5" for T5, etc. or  *      = "a" for T4 FPGA; "b" for T4 FPGA, etc.  *   F  = "0" for PF 0..3; "4".."7" for PF4..7; and "8" for VFs  *   PP = adapter product designation  *  * We use the "version" (V) of the adpater to code the Chip Version above  * but separate out the FPGA as a separate boolean as per above.  */
end_comment

begin_define
define|#
directive|define
name|CHELSIO_PCI_ID_VER
parameter_list|(
name|__DeviceID
parameter_list|)
value|((__DeviceID)>> 12)
end_define

begin_define
define|#
directive|define
name|CHELSIO_PCI_ID_FUNC
parameter_list|(
name|__DeviceID
parameter_list|)
value|(((__DeviceID)>> 8)& 0xf)
end_define

begin_define
define|#
directive|define
name|CHELSIO_PCI_ID_PROD
parameter_list|(
name|__DeviceID
parameter_list|)
value|((__DeviceID)& 0xff)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4
value|0x4
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_FPGA
value|0xa
end_define

begin_define
define|#
directive|define
name|CHELSIO_T5
value|0x5
end_define

begin_define
define|#
directive|define
name|CHELSIO_T5_FPGA
value|0xb
end_define

begin_define
define|#
directive|define
name|CHELSIO_T6
value|0x6
end_define

begin_define
define|#
directive|define
name|CHELSIO_T6_FPGA
value|0xc
end_define

begin_comment
comment|/*  * Translate a PCI Device ID to a base Chelsio Chip Version -- CHELSIO_T4,  * CHELSIO_T5, etc.  If it weren't for the screwed up numbering of the FPGAs  * we could do this simply as DeviceID>> 12 (because we know the real  * encoding oc CHELSIO_Tx identifiers).  However, the FPGAs _do_ have weird  * Device IDs so we need to do this translation here.  Note that only constant  * arithmetic and comparisons can be done here since this is being used to  * initialize static tables, etc.  *  * Finally: This will of course need to be expanded as future chips are  * developed.  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|CHELSIO_PCI_ID_CHIP_VERSION
parameter_list|(
name|unsigned
name|int
name|DeviceID
parameter_list|)
block|{
switch|switch
condition|(
name|CHELSIO_PCI_ID_VER
argument_list|(
name|DeviceID
argument_list|)
condition|)
block|{
case|case
name|CHELSIO_T4
case|:
case|case
name|CHELSIO_T4_FPGA
case|:
return|return
name|CHELSIO_T4
return|;
case|case
name|CHELSIO_T5
case|:
case|case
name|CHELSIO_T5_FPGA
case|:
return|return
name|CHELSIO_T5
return|;
case|case
name|CHELSIO_T6
case|:
case|case
name|CHELSIO_T6_FPGA
case|:
return|return
name|CHELSIO_T6
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Internally we code the Chelsio T4 Family "Chip Code" as a tuple:  *  *     (Is FPGA, Chip Version, Chip Revision)  *  * where:  *  *     Is FPGA: is 0/1 indicating whether we're working with an FPGA  *     Chip Version: is T4, T5, etc.  *     Chip Revision: is the FAB "spin" of the Chip Version.  */
end_comment

begin_define
define|#
directive|define
name|CHELSIO_CHIP_CODE
parameter_list|(
name|version
parameter_list|,
name|revision
parameter_list|)
value|(((version)<< 4) | (revision))
end_define

begin_define
define|#
directive|define
name|CHELSIO_CHIP_FPGA
value|0x100
end_define

begin_define
define|#
directive|define
name|CHELSIO_CHIP_VERSION
parameter_list|(
name|code
parameter_list|)
value|(((code)>> 4)& 0xf)
end_define

begin_define
define|#
directive|define
name|CHELSIO_CHIP_RELEASE
parameter_list|(
name|code
parameter_list|)
value|((code)& 0xf)
end_define

begin_enum
enum|enum
name|chip_type
block|{
name|T4_A1
init|=
name|CHELSIO_CHIP_CODE
argument_list|(
name|CHELSIO_T4
argument_list|,
literal|1
argument_list|)
block|,
name|T4_A2
init|=
name|CHELSIO_CHIP_CODE
argument_list|(
name|CHELSIO_T4
argument_list|,
literal|2
argument_list|)
block|,
name|T4_FIRST_REV
init|=
name|T4_A1
block|,
name|T4_LAST_REV
init|=
name|T4_A2
block|,
name|T5_A0
init|=
name|CHELSIO_CHIP_CODE
argument_list|(
name|CHELSIO_T5
argument_list|,
literal|0
argument_list|)
block|,
name|T5_A1
init|=
name|CHELSIO_CHIP_CODE
argument_list|(
name|CHELSIO_T5
argument_list|,
literal|1
argument_list|)
block|,
name|T5_FIRST_REV
init|=
name|T5_A0
block|,
name|T5_LAST_REV
init|=
name|T5_A1
block|,
name|T6_A0
init|=
name|CHELSIO_CHIP_CODE
argument_list|(
name|CHELSIO_T6
argument_list|,
literal|0
argument_list|)
block|,
name|T6_FIRST_REV
init|=
name|T6_A0
block|,
name|T6_LAST_REV
init|=
name|T6_A0
block|, }
enum|;
end_enum

begin_function
specifier|static
specifier|inline
name|int
name|is_t4
parameter_list|(
name|enum
name|chip_type
name|chip
parameter_list|)
block|{
return|return
operator|(
name|CHELSIO_CHIP_VERSION
argument_list|(
name|chip
argument_list|)
operator|==
name|CHELSIO_T4
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|is_t5
parameter_list|(
name|enum
name|chip_type
name|chip
parameter_list|)
block|{
return|return
operator|(
name|CHELSIO_CHIP_VERSION
argument_list|(
name|chip
argument_list|)
operator|==
name|CHELSIO_T5
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|is_t6
parameter_list|(
name|enum
name|chip_type
name|chip
parameter_list|)
block|{
return|return
operator|(
name|CHELSIO_CHIP_VERSION
argument_list|(
name|chip
argument_list|)
operator|==
name|CHELSIO_T6
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|is_fpga
parameter_list|(
name|enum
name|chip_type
name|chip
parameter_list|)
block|{
return|return
name|chip
operator|&
name|CHELSIO_CHIP_FPGA
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __T4_CHIP_TYPE_H__ */
end_comment

end_unit

