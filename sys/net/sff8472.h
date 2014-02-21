begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 George V. Neville-Neil  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The following set of constants are from Document SFF-8472  * "Diagnostic Monitoring Interface for Optical Transceivers" revision  * 11.3 published by the SFF Committee on June 11, 2013  *  * The SFF standard defines two ranges of addresses, each 255 bytes  * long for the storage of data and diagnostics on cables, such as  * SFP+ optics and TwinAx cables.  The ranges are defined in the  * following way:  *  * Base Address 0xa0 (Identification Data)  * 0-95    Serial ID Defined by SFP MSA  * 96-127  Vendor Specific Data  * 128-255 Reserved  *  * Base Address 0xa2 (Diagnostic Data)  * 0-55    Alarm and Warning Thresholds  * 56-95   Cal Constants  * 96-119  Real Time Diagnostic Interface  * 120-127 Vendor Specific  * 128-247 User Writable EEPROM  * 248-255 Vendor Specific  *  * Note that not all addresses are supported.  Where support is  * optional this is noted and instructions for checking for the  * support are supplied.  *  * All these values are read across an I2C (i squared C) bus.  Any  * device wishing to read these addresses must first have support for  * i2c calls.  The Chelsio T4/T5 driver (dev/cxgbe) is one such  * driver.  */
end_comment

begin_comment
comment|/* Table 3.1 Two-wire interface ID: Data Fields */
end_comment

begin_enum
enum|enum
block|{
name|SFF_8472_BASE
init|=
literal|0xa0
block|,
comment|/* Base address for all our queries. */
name|SFF_8472_ID
init|=
literal|0
block|,
comment|/* Transceiver Type (Table 3.2) */
name|SFF_8472_EXT_ID
init|=
literal|1
block|,
comment|/* Extended transceiver type (Table 3.3) */
name|SFF_8472_CONNECTOR
init|=
literal|2
block|,
comment|/* Connector type (Table 3.4) */
name|SFF_8472_TRANS_START
init|=
literal|3
block|,
comment|/* Elec or Optical Compatibility 				    * (Table 3.5) */
name|SFF_8472_TRANS_END
init|=
literal|10
block|,
name|SFF_8472_ENCODING
init|=
literal|11
block|,
comment|/* Encoding Code for high speed 				     * serial encoding algorithm (see 				     * Table 3.6) */
name|SFF_8472_BITRATE
init|=
literal|12
block|,
comment|/* Nominal signaling rate, units 				     * of 100MBd.  (see details for 				     * rates> 25.0Gb/s) */
name|SFF_8472_RATEID
init|=
literal|13
block|,
comment|/* Type of rate select 				     * functionality (see Table 				     * 3.6a) */
name|SFF_8472_LEN_SMF_KM
init|=
literal|14
block|,
comment|/* Link length supported for single 				    * mode fiber, units of km */
name|SFF_8472_LEN_SMF
init|=
literal|15
block|,
comment|/* Link length supported for single 				    * mode fiber, units of 100 m */
name|SFF_8472_LEN_50UM
init|=
literal|16
block|,
comment|/* Link length supported for 50 um 				    * OM2 fiber, units of 10 m */
name|SFF_8472_LEN_625UM
init|=
literal|17
block|,
comment|/* Link length supported for 62.5 				    * um OM1 fiber, units of 10 m */
name|SFF_8472_LEN_OM4
init|=
literal|18
block|,
comment|/* Link length supported for 50um 				    * OM4 fiber, units of 10m. 				    * Alternatively copper or direct 				    * attach cable, units of m */
name|SFF_8472_LEN_OM3
init|=
literal|19
block|,
comment|/* Link length supported for 50 um OM3 fiber, units of 10 m */
name|SFF_8472_VENDOR_START
init|=
literal|20
block|,
comment|/* Vendor name [Address A0h, Bytes 				    * 20-35] */
name|SFF_8472_VENDOR_END
init|=
literal|35
block|,
name|SFF_8472_TRANS
init|=
literal|36
block|,
comment|/* Transceiver Code for electronic 				    * or optical compatibility (see 				    * Table 3.5) */
name|SFF_8472_VENDOR_OUI_START
init|=
literal|37
block|,
comment|/* Vendor OUI SFP vendor IEEE 				    * company ID */
name|SFF_8472_VENDOR_OUI_END
init|=
literal|39
block|,
name|SFF_8472_PN_START
init|=
literal|40
block|,
comment|/* Vendor PN */
name|SFF_8472_PN_END
init|=
literal|55
block|,
name|SFF_8472_REV_START
init|=
literal|56
block|,
comment|/* Vendor Revision */
name|SFF_8472_REV_END
init|=
literal|59
block|,
name|SFF_8472_WAVELEN_START
init|=
literal|60
block|,
comment|/* Wavelength Laser wavelength 				    * (Passive/Active Cable 				    * Specification Compliance) */
name|SFF_8472_WAVELEN_END
init|=
literal|61
block|,
name|SFF_8472_CC_BASE
init|=
literal|63
block|,
comment|/* CC_BASE Check code for Base ID 				    * Fields (addresses 0 to 62) */
comment|/*  * Extension Fields (optional) check the options before reading other  * addresses.  */
name|SFF_8472_OPTIONS_MSB
init|=
literal|64
block|,
comment|/* Options Indicates which optional 				    * transceiver signals are 				    * implemented */
name|SFF_8472_OPTIONS_LSB
init|=
literal|65
block|,
comment|/* (see Table 3.7) */
name|SFF_8472_BR_MAX
init|=
literal|66
block|,
comment|/* BR max Upper bit rate margin, 				    * units of % (see details for 				    * rates> 25.0Gb/s) */
name|SFF_8472_BR_MIN
init|=
literal|67
block|,
comment|/* Lower bit rate margin, units of 				    * % (see details for rates> 				    * 25.0Gb/s) */
name|SFF_8472_SN_START
init|=
literal|68
block|,
comment|/* Vendor SN [Address A0h, Bytes 68-83] */
name|SFF_8472_SN_END
init|=
literal|83
block|,
name|SFF_8472_DATE_START
init|=
literal|84
block|,
comment|/* Date code Vendorâs manufacturing 				    * date code (see Table 3.8) */
name|SFF_8472_DATE_END
init|=
literal|91
block|,
name|SFF_8472_DIAG_TYPE
init|=
literal|92
block|,
comment|/* Diagnostic Monitoring Type 				    * Indicates which type of 				    * diagnostic monitoring is 				    * implemented (if any) in the 				    * transceiver (see Table 3.9) 				    */
name|SFF_8472_ENHANCED
init|=
literal|93
block|,
comment|/* Enhanced Options Indicates which 				    * optional enhanced features are 				    * implemented (if any) in the 				    * transceiver (see Table 3.10) */
name|SFF_8472_COMPLIANCE
init|=
literal|94
block|,
comment|/* SFF-8472 Compliance Indicates 				    * which revision of SFF-8472 the 				    * transceiver complies with.  (see 				    * Table 3.12)*/
name|SFF_8472_CC_EXT
init|=
literal|95
block|,
comment|/* Check code for the Extended ID 				    * Fields (addresses 64 to 94) 				    */
name|SFF_8472_VENDOR_RSRVD_START
init|=
literal|96
block|,
name|SFF_8472_VENDOR_RSRVD_END
init|=
literal|127
block|,
name|SFF_8472_RESERVED_START
init|=
literal|128
block|,
name|SFF_8472_RESERVED_END
init|=
literal|255
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SFF_8472_DIAG_IMPL
value|(1<< 6)
end_define

begin_comment
comment|/* Required to be 1 */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_DIAG_INTERNAL
value|(1<< 5)
end_define

begin_comment
comment|/* Internal measurements. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_DIAG_EXTERNAL
value|(1<< 4)
end_define

begin_comment
comment|/* External measurements. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_DIAG_POWER
value|(1<< 3)
end_define

begin_comment
comment|/* Power measurement type */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_DIAG_ADDR_CHG
value|(1<< 2)
end_define

begin_comment
comment|/* Address change required. 					  * See SFF-8472 doc. */
end_comment

begin_comment
comment|/*   * Diagnostics are available at the two wire address 0xa2.  All   * diagnostics are OPTIONAL so you should check 0xa0 registers 92 to   * see which, if any are supported.   */
end_comment

begin_enum
enum|enum
block|{
name|SFF_8472_DIAG
init|=
literal|0xa2
block|}
enum|;
end_enum

begin_comment
comment|/* Base address for diagnostics. */
end_comment

begin_comment
comment|/*   *  Table 3.15 Alarm and Warning Thresholds All values are 2 bytes   * and MUST be read in a single read operation starting at the MSB   */
end_comment

begin_enum
enum|enum
block|{
name|SFF_8472_TEMP_HIGH_ALM
init|=
literal|0
block|,
comment|/* Temp High Alarm  */
name|SFF_8472_TEMP_LOW_ALM
init|=
literal|2
block|,
comment|/* Temp Low Alarm */
name|SFF_8472_TEMP_HIGH_WARN
init|=
literal|4
block|,
comment|/* Temp High Warning */
name|SFF_8472_TEMP_LOW_WARN
init|=
literal|6
block|,
comment|/* Temp Low Warning */
name|SFF_8472_VOLTAGE_HIGH_ALM
init|=
literal|8
block|,
comment|/* Voltage High Alarm */
name|SFF_8472_VOLTAGE_LOW_ALM
init|=
literal|10
block|,
comment|/* Voltage Low Alarm */
name|SFF_8472_VOLTAGE_HIGH_WARN
init|=
literal|12
block|,
comment|/* Voltage High Warning */
name|SFF_8472_VOLTAGE_LOW_WARN
init|=
literal|14
block|,
comment|/* Voltage Low Warning */
name|SFF_8472_BIAS_HIGH_ALM
init|=
literal|16
block|,
comment|/* Bias High Alarm */
name|SFF_8472_BIAS_LOW_ALM
init|=
literal|18
block|,
comment|/* Bias Low Alarm */
name|SFF_8472_BIAS_HIGH_WARN
init|=
literal|20
block|,
comment|/* Bias High Warning */
name|SFF_8472_BIAS_LOW_WARN
init|=
literal|22
block|,
comment|/* Bias Low Warning */
name|SFF_8472_TX_POWER_HIGH_ALM
init|=
literal|24
block|,
comment|/* TX Power High Alarm */
name|SFF_8472_TX_POWER_LOW_ALM
init|=
literal|26
block|,
comment|/* TX Power Low Alarm */
name|SFF_8472_TX_POWER_HIGH_WARN
init|=
literal|28
block|,
comment|/* TX Power High Warning */
name|SFF_8472_TX_POWER_LOW_WARN
init|=
literal|30
block|,
comment|/* TX Power Low Warning */
name|SFF_8472_RX_POWER_HIGH_ALM
init|=
literal|32
block|,
comment|/* RX Power High Alarm */
name|SFF_8472_RX_POWER_LOW_ALM
init|=
literal|34
block|,
comment|/* RX Power Low Alarm */
name|SFF_8472_RX_POWER_HIGH_WARN
init|=
literal|36
block|,
comment|/* RX Power High Warning */
name|SFF_8472_RX_POWER_LOW_WARN
init|=
literal|38
block|,
comment|/* RX Power Low Warning */
name|SFF_8472_RX_POWER4
init|=
literal|56
block|,
comment|/* Rx_PWR(4) Single precision 				    *  floating point calibration data 				    *  - Rx optical power. Bit 7 of 				    *  byte 56 is MSB. Bit 0 of byte 				    *  59 is LSB. Rx_PWR(4) should be 				    *  set to zero for âinternally 				    *  calibratedâ devices. */
name|SFF_8472_RX_POWER3
init|=
literal|60
block|,
comment|/* Rx_PWR(3) Single precision 				    * floating point calibration data 				    * - Rx optical power.  Bit 7 of 				    * byte 60 is MSB. Bit 0 of byte 63 				    * is LSB. Rx_PWR(3) should be set 				    * to zero for âinternally 				    * calibratedâ devices.*/
name|SFF_8472_RX_POWER2
init|=
literal|64
block|,
comment|/* Rx_PWR(2) Single precision 				    * floating point calibration data, 				    * Rx optical power.  Bit 7 of byte 				    * 64 is MSB, bit 0 of byte 67 is 				    * LSB. Rx_PWR(2) should be set to 				    * zero for âinternally calibratedâ 				    * devices. */
name|SFF_8472_RX_POWER1
init|=
literal|68
block|,
comment|/* Rx_PWR(1) Single precision 				    * floating point calibration data, 				    * Rx optical power. Bit 7 of byte 				    * 68 is MSB, bit 0 of byte 71 is 				    * LSB. Rx_PWR(1) should be set to 				    * 1 for âinternally calibratedâ 				    * devices. */
name|SFF_8472_RX_POWER0
init|=
literal|72
block|,
comment|/* Rx_PWR(0) Single precision 				    * floating point calibration data, 				    * Rx optical power. Bit 7 of byte 				    * 72 is MSB, bit 0 of byte 75 is 				    * LSB. Rx_PWR(0) should be set to 				    * zero for âinternally calibratedâ 				    * devices. */
name|SFF_8472_TX_I_SLOPE
init|=
literal|76
block|,
comment|/* Tx_I(Slope) Fixed decimal 				    * (unsigned) calibration data, 				    * laser bias current. Bit 7 of 				    * byte 76 is MSB, bit 0 of byte 77 				    * is LSB. Tx_I(Slope) should be 				    * set to 1 for âinternally 				    * calibratedâ devices. */
name|SFF_8472_TX_I_OFFSET
init|=
literal|78
block|,
comment|/* Tx_I(Offset) Fixed decimal 				    * (signed twoâs complement) 				    * calibration data, laser bias 				    * current. Bit 7 of byte 78 is 				    * MSB, bit 0 of byte 79 is 				    * LSB. Tx_I(Offset) should be set 				    * to zero for âinternally 				    * calibratedâ devices. */
name|SFF_8472_TX_POWER_SLOPE
init|=
literal|80
block|,
comment|/* Tx_PWR(Slope) Fixed decimal 				    * (unsigned) calibration data, 				    * transmitter coupled output 				    * power. Bit 7 of byte 80 is MSB, 				    * bit 0 of byte 81 is LSB. 				    * Tx_PWR(Slope) should be set to 1 				    * for âinternally calibratedâ 				    * devices. */
name|SFF_8472_TX_POWER_OFFSET
init|=
literal|82
block|,
comment|/* Tx_PWR(Offset) Fixed decimal 					    * (signed twoâs complement) 					    * calibration data, transmitter 					    * coupled output power. Bit 7 of 					    * byte 82 is MSB, bit 0 of byte 83 					    * is LSB. Tx_PWR(Offset) should be 					    * set to zero for âinternally 					    * calibratedâ devices. */
name|SFF_8472_T_SLOPE
init|=
literal|84
block|,
comment|/* T (Slope) Fixed decimal 				    * (unsigned) calibration data, 				    * internal module temperature. Bit 				    * 7 of byte 84 is MSB, bit 0 of 				    * byte 85 is LSB.  T(Slope) should 				    * be set to 1 for âinternally 				    * calibratedâ devices. */
name|SFF_8472_T_OFFSET
init|=
literal|86
block|,
comment|/* T (Offset) Fixed decimal (signed 				    * twoâs complement) calibration 				    * data, internal module 				    * temperature. Bit 7 of byte 86 is 				    * MSB, bit 0 of byte 87 is LSB. 				    * T(Offset) should be set to zero 				    * for âinternally calibratedâ 				    * devices. */
name|SFF_8472_V_SLOPE
init|=
literal|88
block|,
comment|/* V (Slope) Fixed decimal 				    * (unsigned) calibration data, 				    * internal module supply 				    * voltage. Bit 7 of byte 88 is 				    * MSB, bit 0 of byte 89 is 				    * LSB. V(Slope) should be set to 1 				    * for âinternally calibratedâ 				    * devices. */
name|SFF_8472_V_OFFSET
init|=
literal|90
block|,
comment|/* V (Offset) Fixed decimal (signed 				    * twoâs complement) calibration 				    * data, internal module supply 				    * voltage. Bit 7 of byte 90 is 				    * MSB. Bit 0 of byte 91 is 				    * LSB. V(Offset) should be set to 				    * zero for âinternally calibratedâ 				    * devices. */
name|SFF_8472_CHECKSUM
init|=
literal|95
block|,
comment|/* Checksum Byte 95 contains the 				    * low order 8 bits of the sum of 				    * bytes 0 â 94. */
comment|/* Internal measurements. */
name|SFF_8472_TEMP
init|=
literal|96
block|,
comment|/* Internally measured module temperature. */
name|SFF_8472_VCC
init|=
literal|98
block|,
comment|/* Internally measured supply 				    * voltage in transceiver. 				    */
name|SFF_8472_TX_BIAS
init|=
literal|100
block|,
comment|/* Internally measured TX Bias Current. */
name|SFF_8472_TX_POWER
init|=
literal|102
block|,
comment|/* Measured TX output power. */
name|SFF_8472_RX_POWER
init|=
literal|104
block|,
comment|/* Measured RX input power. */
name|SFF_8472_STATUS
init|=
literal|110
comment|/* See below */
block|}
enum|;
end_enum

begin_comment
comment|/* Status Bits Described */
end_comment

begin_comment
comment|/*  * TX Disable State Digital state of the TX Disable Input Pin. Updated  * within 100ms of change on pin.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_STATUS_TX_DISABLE
value|(1<< 7)
end_define

begin_comment
comment|/*  * Select Read/write bit that allows software disable of  * laser. Writing â1â disables laser. See Table 3.11 for  * enable/disable timing requirements. This bit is âORâd with the hard  * TX_DISABLE pin value. Note, per SFP MSA TX_DISABLE pin is default  * enabled unless pulled low by hardware. If Soft TX Disable is not  * implemented, the transceiver ignores the value of this bit. Default  * power up value is zero/low.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_STATUS_SOFT_TX_DISABLE
value|(1<< 6)
end_define

begin_comment
comment|/*  * RS(1) State Digital state of SFP input pin AS(1) per SFF-8079 or  * RS(1) per SFF-8431. Updated within 100ms of change on pin. See A2h  * Byte 118, Bit 3 for Soft RS(1) Select control information.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RS_STATE
value|(1<< 5)
end_define

begin_comment
comment|/*  * Rate_Select State [aka. âRS(0)â] Digital state of the SFP  * Rate_Select Input Pin. Updated within 100ms of change on pin. Note:  * This pin is also known as AS(0) in SFF-8079 and RS(0) in SFF-8431.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_STATUS_SELECT_STATE
value|(1<< 4)
end_define

begin_comment
comment|/*  * Read/write bit that allows software rate select control. Writing  * â1â selects full bandwidth operation. This bit is âORâd with the  * hard Rate_Select, AS(0) or RS(0) pin value. See Table 3.11 for  * timing requirements. Default at power up is logic zero/low. If Soft  * Rate Select is not implemented, the transceiver ignores the value  * of this bit. Note: Specific transceiver behaviors of this bit are  * identified in Table 3.6a and referenced documents. See Table 3.18a,  * byte 118, bit 3 for Soft RS(1) Select.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_STATUS_SOFT_RATE_SELECT
value|(1<< 3)
end_define

begin_comment
comment|/*  * TX Fault State Digital state of the TX Fault Output Pin. Updated  * within 100ms of change on pin.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_STATUS_TX_FAULT_STATE
value|(1<< 2)
end_define

begin_comment
comment|/*  * Digital state of the RX_LOS Output Pin. Updated within 100ms of  * change on pin.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_STATUS_RX_LOS
value|(1<< 1)
end_define

begin_comment
comment|/*  * Indicates transceiver has achieved power up and data is ready. Bit  * remains high until data is ready to be read at which time the  * device sets the bit low.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_STATUS_DATA_READY
value|(1<< 0)
end_define

begin_comment
comment|/* Table 3.2 Identifier values */
end_comment

begin_enum
enum|enum
block|{
name|SFF_8472_ID_UNKNOWN
init|=
literal|0x0
block|,
comment|/* Unknown or unspecified */
name|SFF_8472_ID_GBIC
init|=
literal|0x1
block|,
comment|/* GBIC */
name|SFF_8472_ID_SFF
init|=
literal|0x2
block|,
comment|/* Module soldered to motherboard (ex: SFF)*/
name|SFF_8472_ID_SFP
init|=
literal|0x3
block|,
comment|/* SFP or SFP âPlusâ */
name|SFF_8472_ID_XBI
init|=
literal|0x4
block|,
comment|/* Reserved for â300 pin XBIâ devices */
name|SFF_8472_ID_XENPAK
init|=
literal|0x5
block|,
comment|/* Reserved for âXenpakâ devices */
name|SFF_8472_ID_XFP
init|=
literal|0x6
block|,
comment|/* Reserved for âXFPâ devices */
name|SFF_8472_ID_XFF
init|=
literal|0x7
block|,
comment|/* Reserved for âXFFâ devices */
name|SFF_8472_ID_XFPE
init|=
literal|0x8
block|,
comment|/* Reserved for âXFP-Eâ devices */
name|SFF_8472_ID_XPAK
init|=
literal|0x9
block|,
comment|/* Reserved for âXPakâ devices */
name|SFF_8472_ID_X2
init|=
literal|0xA
block|,
comment|/* Reserved for âX2â devices */
name|SFF_8472_ID_DWDM_SFP
init|=
literal|0xB
block|,
comment|/* Reserved for âDWDM-SFPâ devices */
name|SFF_8472_ID_QSFP
init|=
literal|0xC
block|,
comment|/* Reserved for âQSFPâ devices */
name|SFF_8472_ID_LAST
init|=
name|SFF_8472_ID_QSFP
block|}
enum|;
end_enum

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sff_8472_id
index|[
name|SFF_8472_ID_LAST
operator|+
literal|1
index|]
init|=
block|{
literal|"Unknown"
block|,
literal|"GBIC"
block|,
literal|"SFF"
block|,
literal|"SFP"
block|,
literal|"XBI"
block|,
literal|"Xenpak"
block|,
literal|"XFP"
block|,
literal|"XFF"
block|,
literal|"XFP-E"
block|,
literal|"XPak"
block|,
literal|"X2"
block|,
literal|"DWDM-SFP"
block|,
literal|"QSFP"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Table 3.13 and 3.14 Temperature Conversion Values */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TEMP_SIGN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|SFF_8472_TEMP_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SFF_8472_TEMP_MSK
value|0xEF00
end_define

begin_define
define|#
directive|define
name|SFF_8472_TEMP_FRAC
value|0x00FF
end_define

begin_comment
comment|/* Internal Callibration Conversion factors */
end_comment

begin_comment
comment|/*  * Represented as a 16 bit unsigned integer with the voltage defined  * as the full 16 bit value (0 â 65535) with LSB equal to 100 uVolt,  * yielding a total range of 0 to +6.55 Volts.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_VCC_FACTOR
value|10000.0
end_define

begin_comment
comment|/*  * Represented as a 16 bit unsigned integer with the current defined  * as the full 16 bit value (0 â 65535) with LSB equal to 2 uA,  * yielding a total range of 0 to 131 mA.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_BIAS_FACTOR
value|2000.0
end_define

begin_comment
comment|/*  * Represented as a 16 bit unsigned integer with the power defined as  * the full 16 bit value (0 â 65535) with LSB equal to 0.1 uW,  * yielding a total range of 0 to 6.5535 mW (~ -40 to +8.2 dBm).  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_POWER_FACTOR
value|10000.0
end_define

end_unit

