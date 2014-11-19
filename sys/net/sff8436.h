begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Yandex LLC.  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The following set of constants are from Document SFF-8436  * "QSFP+ 10 Gbs 4X PLUGGABLE TRANSCEIVER" revision 4.8 dated October 31, 2013  *  * This SFF standard defines the following QSFP+ memory address module:  *  * 1) 256-byte addressable block and 128-byte pages  * 2) Lower 128-bytes addresses always refer to the same page  * 3) Upper address space may refer to different pages depending on  *   "page select" byte value.  *  * Map description:  *  * Serial address 0xA02:  *  * Lower bits  * 0-127   Monitoring data& page select byte  * 128-255:  *  * Page 00:  * 128-191 Base ID Fields  * 191-223 Extended ID  * 223-255 Vendor Specific ID  *  * Page 01 (optional):  * 128-255 App-specific data  *  * Page 02 (optional):  * 128-255 User EEPROM Data  *  * Page 03 (optional for Cable Assmeblies)  * 128-223 Thresholds  * 225-237 Vendor Specific  * 238-253 Channel Controls/Monitor  * 254-255 Reserverd  *  * All these values are read across an I2C (i squared C) bus.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8436_BASE
value|0xA0
end_define

begin_comment
comment|/* Base address for all requests */
end_comment

begin_comment
comment|/* Table 17 - Lower Memory Map */
end_comment

begin_enum
enum|enum
block|{
name|SFF_8436_MID
init|=
literal|0
block|,
comment|/* Copy of SFF_8436_ID field */
name|SFF_8436_STATUS
init|=
literal|1
block|,
comment|/* 2-bytes status (Table 18) */
name|SFF_8436_INTR_START
init|=
literal|3
block|,
comment|/* Interrupt flags (Tables 19-21) */
name|SFF_8436_INTR_END
init|=
literal|21
block|,
name|SFF_8436_MODMON_START
init|=
literal|22
block|,
comment|/* Module monitors (Table 22 */
name|SFF_8436_TEMP
init|=
literal|22
block|,
comment|/* Internally measured module temp */
name|SFF_8436_VCC
init|=
literal|26
block|,
comment|/* Internally mesasure module 					* supplied voltage */
name|SFF_8436_MODMON_END
init|=
literal|33
block|,
name|SFF_8436_CHMON_START
init|=
literal|34
block|,
comment|/* Channel monitors (Table 23) */
name|SFF_8436_RX_CH1_MSB
init|=
literal|34
block|,
comment|/* Internally measured RX input power */
name|SFF_8436_RX_CH1_LSB
init|=
literal|35
block|,
comment|/* for channel 1 */
name|SFF_8436_RX_CH2_MSB
init|=
literal|36
block|,
comment|/* Internally measured RX input power */
name|SFF_8436_RX_CH2_LSB
init|=
literal|37
block|,
comment|/* for channel 2 */
name|SFF_8436_RX_CH3_MSB
init|=
literal|38
block|,
comment|/* Internally measured RX input power */
name|SFF_8436_RX_CH3_LSB
init|=
literal|39
block|,
comment|/* for channel 3 */
name|SFF_8436_RX_CH4_MSB
init|=
literal|40
block|,
comment|/* Internally measured RX input power */
name|SFF_8436_RX_CH4_LSB
init|=
literal|41
block|,
comment|/* for channel 4 */
name|SFF_8436_TX_CH1_MSB
init|=
literal|42
block|,
comment|/* Internally measured TX bias */
name|SFF_8436_TX_CH1_LSB
init|=
literal|43
block|,
comment|/* for channel 1 */
name|SFF_8436_TX_CH2_MSB
init|=
literal|44
block|,
comment|/* Internally measured TX bias */
name|SFF_8436_TX_CH2_LSB
init|=
literal|45
block|,
comment|/* for channel 2 */
name|SFF_8436_TX_CH3_MSB
init|=
literal|46
block|,
comment|/* Internally measured TX bias */
name|SFF_8436_TX_CH3_LSB
init|=
literal|47
block|,
comment|/* for channel 3 */
name|SFF_8436_TX_CH4_MSB
init|=
literal|48
block|,
comment|/* Internally measured TX bias */
name|SFF_8436_TX_CH4_LSB
init|=
literal|49
block|,
comment|/* for channel 4 */
name|SFF_8436_CHANMON_END
init|=
literal|81
block|,
name|SFF_8436_CONTROL_START
init|=
literal|86
block|,
comment|/* Control (Table 24) */
name|SFF_8436_CONTROL_END
init|=
literal|97
block|,
name|SFF_8436_MASKS_START
init|=
literal|100
block|,
comment|/* Module/channel masks (Table 25) */
name|SFF_8436_MASKS_END
init|=
literal|106
block|,
name|SFF_8436_CHPASSWORD
init|=
literal|119
block|,
comment|/* Password change entry (4 bytes) */
name|SFF_8436_PASSWORD
init|=
literal|123
block|,
comment|/* Password entry area (4 bytes) */
name|SFF_8436_PAGESEL
init|=
literal|127
block|,
comment|/* Page select byte */
block|}
enum|;
end_enum

begin_comment
comment|/* Table 18 - Status Indicators bits */
end_comment

begin_comment
comment|/* Byte 1: all bits reserved */
end_comment

begin_comment
comment|/* Byte 2 bits */
end_comment

begin_define
define|#
directive|define
name|SFF_8436_STATUS_FLATMEM
value|(1<< 2)
end_define

begin_comment
comment|/* Upper memory flat or paged 						* 0 = paging, 1=Page 0 only */
end_comment

begin_define
define|#
directive|define
name|SFF_8436_STATUS_INTL
value|(1<< 1)
end_define

begin_comment
comment|/* Digital state of the intL 						* Interrupt output pin */
end_comment

begin_define
define|#
directive|define
name|SFF_8436_STATUS_NOTREADY
value|1
end_define

begin_comment
comment|/* Module has not yet achieved 						* power up and memory data is not 						* ready. 0=data is ready */
end_comment

begin_comment
comment|/*  * Upper page 0 definitions:  * Table 29 - Serial ID: Data fields.  *  * Note that this table is mostly the same as used in SFF-8472.  * The only differenee is address shift: +128 bytes.  */
end_comment

begin_enum
enum|enum
block|{
name|SFF_8436_ID
init|=
literal|128
block|,
comment|/* Module Type (defined in sff8472.h) */
name|SFF_8436_EXT_ID
init|=
literal|129
block|,
comment|/* Extended transceiver type 					 * (Table 31) */
name|SFF_8436_CONNECTOR
init|=
literal|130
block|,
comment|/* Connector type (Table 32) */
name|SFF_8436_TRANS_START
init|=
literal|131
block|,
comment|/* Electric or Optical Compatibility 					 * (Table 33) */
name|SFF_8436_CODE_E1040G
init|=
literal|131
block|,
comment|/* 10/40G Ethernet Compliance Code */
name|SFF_8436_CODE_SONET
init|=
literal|132
block|,
comment|/* SONET Compliance codes */
name|SFF_8436_CODE_SATA
init|=
literal|133
block|,
comment|/* SAS/SATA compliance codes */
name|SFF_8436_CODE_E1G
init|=
literal|134
block|,
comment|/* Gigabit Ethernet Compliant codes */
name|SFF_8436_CODE_FC_START
init|=
literal|135
block|,
comment|/* FC link/media/speed */
name|SFF_8436_CODE_FC_END
init|=
literal|138
block|,
name|SFF_8436_TRANS_END
init|=
literal|138
block|,
name|SFF_8436_ENCODING
init|=
literal|139
block|,
comment|/* Encoding Code for high speed 					* serial encoding algorithm (see 					* Table 34) */
name|SFF_8436_BITRATE
init|=
literal|140
block|,
comment|/* Nominal signaling rate, units 					* of 100MBd. */
name|SFF_8436_RATEID
init|=
literal|141
block|,
comment|/* Extended RateSelect Compliance 					* (see Table 35) */
name|SFF_8436_LEN_SMF_KM
init|=
literal|142
block|,
comment|/* Link length supported for single 					* mode fiber, units of km */
name|SFF_8436_LEN_OM3
init|=
literal|143
block|,
comment|/* Link length supported for 850nm 					* 50um multimode fiber, units of 2 m */
name|SFF_8436_LEN_OM2
init|=
literal|144
block|,
comment|/* Link length supported for 50 um 					* OM2 fiber, units of 1 m */
name|SFF_8436_LEN_OM1
init|=
literal|145
block|,
comment|/* Link length supported for 1310 nm 					 * 50um multi-mode fiber, units of 1m*/
name|SFF_8436_LEN_ASM
init|=
literal|144
block|,
comment|/* Link length of passive cable assembly 					* Length is specified as in the INF 					* 8074, units of 1m. 0 means this is 					* not value assembly. Value of 255 					* means thet the Module supports length 					* greater than 254 m. */
name|SFF_8436_DEV_TECH
init|=
literal|147
block|,
comment|/* Device/transmitter technology, 					* see Table 36/37 */
name|SFF_8436_VENDOR_START
init|=
literal|148
block|,
comment|/* Vendor name, 16 bytes, padded 					* right with 0x20 */
name|SFF_8436_VENDOR_END
init|=
literal|163
block|,
name|SFF_8436_EXTMODCODE
init|=
literal|164
block|,
comment|/* Extended module code, Table 164 */
name|SFF_8436_VENDOR_OUI_START
init|=
literal|165
block|,
comment|/* Vendor OUI SFP vendor IEEE 					* company ID */
name|SFF_8436_VENDOR_OUI_END
init|=
literal|167
block|,
name|SFF_8436_PN_START
init|=
literal|168
block|,
comment|/* Vendor PN, padded right with 0x20 */
name|SFF_8436_PN_END
init|=
literal|183
block|,
name|SFF_8436_REV_START
init|=
literal|184
block|,
comment|/* Vendor Revision, padded right 0x20 */
name|SFF_8436_REV_END
init|=
literal|185
block|,
name|SFF_8436_WAVELEN_START
init|=
literal|186
block|,
comment|/* Wavelength Laser wavelength 					* (Passive/Active Cable 					* Specification Compliance) */
name|SFF_8436_WAVELEN_END
init|=
literal|189
block|,
name|SFF_8436_MAX_CASE_TEMP
init|=
literal|190
block|,
comment|/* Allows to specify maximum temp 					* above 70C. Maximum case temperature is 					* an 8-bit value in Degrees C. A value 					*of 0 implies the standard 70C rating.*/
name|SFF_8436_CC_BASE
init|=
literal|191
block|,
comment|/* CC_BASE Check code for Base ID 					* Fields (first 63 bytes) */
comment|/* Extended ID fields */
name|SFF_8436_OPTIONS_START
init|=
literal|192
block|,
comment|/* Options Indicates which optional 					* transceiver signals are 					* implemented (see Table 39) */
name|SFF_8436_OPTIONS_END
init|=
literal|195
block|,
name|SFF_8436_SN_START
init|=
literal|196
block|,
comment|/* Vendor SN, riwght padded with 0x20 */
name|SFF_8436_SN_END
init|=
literal|211
block|,
name|SFF_8436_DATE_START
init|=
literal|212
block|,
comment|/* Vendorâs manufacturing date code 					* (see Table 40) */
name|SFF_8436_DATE_END
init|=
literal|219
block|,
name|SFF_8436_DIAG_TYPE
init|=
literal|220
block|,
comment|/* Diagnostic Monitoring Type 					* Indicates which type of 					* diagnostic monitoring is 					* implemented (if any) in the 					* transceiver (see Table 41) */
name|SFF_8436_ENHANCED
init|=
literal|221
block|,
comment|/* Enhanced Options Indicates which 					* optional features are implemented 					* (if any) in the transceiver 					* (see Table 42) */
name|SFF_8436_CC_EXT
init|=
literal|222
block|,
comment|/* Check code for the Extended ID 					* Fields (bytes 192-222 incl) */
name|SFF_8436_VENDOR_RSRVD_START
init|=
literal|224
block|,
name|SFF_8436_VENDOR_RSRVD_END
init|=
literal|255
block|, }
enum|;
end_enum

end_unit

