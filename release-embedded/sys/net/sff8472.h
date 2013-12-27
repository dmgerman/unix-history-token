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

begin_define
define|#
directive|define
name|SFF_8472_BASE
value|0xa0
end_define

begin_comment
comment|/* Base address for all our queries. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID
value|0
end_define

begin_comment
comment|/* Transceiver Type (Table 3.2) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_EXT_ID
value|1
end_define

begin_comment
comment|/* Extended transceiver type (Table 3.3) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_CONNECTOR
value|2
end_define

begin_comment
comment|/* Connector type (Table 3.4) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TRANS_START
value|3
end_define

begin_comment
comment|/* Elec or Optical Compatibility 				    * (Table 3.5) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TRANS_END
value|10
end_define

begin_define
define|#
directive|define
name|SFF_8472_ENCODING
value|11
end_define

begin_comment
comment|/* Encoding Code for high speed 				    * serial encoding algorithm (see 				    * Table 3.6) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_BITRATE
value|12
end_define

begin_comment
comment|/* Nominal signaling rate, units 				    *  of 100MBd.  (see details for 				    *  rates> 25.0Gb/s) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RATEID
value|13
end_define

begin_comment
comment|/* Type of rate select 				    * functionality (see Table 				    * 3.6a) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_LEN_SMF_KM
value|14
end_define

begin_comment
comment|/* Link length supported for single 				    * mode fiber, units of km */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_LEN_SMF
value|15
end_define

begin_comment
comment|/* Link length supported for single 				    * mode fiber, units of 100 m */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_LEN_50UM
value|16
end_define

begin_comment
comment|/* Link length supported for 50 um 				    * OM2 fiber, units of 10 m */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_LEN_625UM
value|17
end_define

begin_comment
comment|/* Link length supported for 62.5 				    * um OM1 fiber, units of 10 m */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_LEN_OM4
value|18
end_define

begin_comment
comment|/* Link length supported for 50um 				    * OM4 fiber, units of 10m. 				    * Alternatively copper or direct 				    * attach cable, units of m */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_LEN_OM3
value|19
end_define

begin_comment
comment|/* Link length supported for 50 um OM3 fiber, units of 10 m */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_VENDOR_START
value|20
end_define

begin_comment
comment|/* Vendor name [Address A0h, Bytes 				    * 20-35] */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_VENDOR_END
value|35
end_define

begin_define
define|#
directive|define
name|SFF_8472_TRANS
value|36
end_define

begin_comment
comment|/* Transceiver Code for electronic 				    * or optical compatibility (see 				    * Table 3.5) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_VENDOR_OUI_START
value|37
end_define

begin_comment
comment|/* Vendor OUI SFP vendor IEEE 				    * company ID */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_VENDOR_OUI_END
value|39
end_define

begin_define
define|#
directive|define
name|SFF_8472_PN_START
value|40
end_define

begin_comment
comment|/* Vendor PN */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_PN_END
value|55
end_define

begin_define
define|#
directive|define
name|SFF_8472_REV_START
value|56
end_define

begin_comment
comment|/* Vendor Revision */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_REV_END
value|59
end_define

begin_define
define|#
directive|define
name|SFF_8472_WAVELEN_START
value|60
end_define

begin_comment
comment|/* Wavelength Laser wavelength 				    * (Passive/Active Cable 				    * Specification Compliance) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_WAVELEN_END
value|61
end_define

begin_define
define|#
directive|define
name|SFF_8472_CC_BASE
value|63
end_define

begin_comment
comment|/* CC_BASE Check code for Base ID 				    * Fields (addresses 0 to 62) */
end_comment

begin_comment
comment|/*  * Extension Fields (optional) check the options before reading other  * addresses.  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_OPTIONS_MSB
value|64
end_define

begin_comment
comment|/* Options Indicates which optional 				    * transceiver signals are 				    * implemented */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_OPTIONS_LSB
value|65
end_define

begin_comment
comment|/* (see Table 3.7) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_BR_MAX
value|66
end_define

begin_comment
comment|/* BR max Upper bit rate margin, 				    * units of % (see details for 				    * rates> 25.0Gb/s) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_BR_MIN
value|67
end_define

begin_comment
comment|/* Lower bit rate margin, units of 				    * % (see details for rates> 				    * 25.0Gb/s) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_SN_START
value|68
end_define

begin_comment
comment|/* Vendor SN [Address A0h, Bytes 68-83] */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_SN_END
value|83
end_define

begin_define
define|#
directive|define
name|SFF_8472_DATE_START
value|84
end_define

begin_comment
comment|/* Date code Vendorâs manufacturing 				    * date code (see Table 3.8) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_DATE_END
value|91
end_define

begin_define
define|#
directive|define
name|SFF_8472_DIAG_TYPE
value|92
end_define

begin_comment
comment|/* Diagnostic Monitoring Type 				    * Indicates which type of 				    * diagnostic monitoring is 				    * implemented (if any) in the 				    * transceiver (see Table 3.9) 				    */
end_comment

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

begin_define
define|#
directive|define
name|SFF_8472_ENHANCED
value|93
end_define

begin_comment
comment|/* Enhanced Options Indicates which 				    * optional enhanced features are 				    * implemented (if any) in the 				    * transceiver (see Table 3.10) */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_COMPLIANCE
value|94
end_define

begin_comment
comment|/* SFF-8472 Compliance Indicates 				    * which revision of SFF-8472 the 				    * transceiver complies with.  (see 				    * Table 3.12)*/
end_comment

begin_define
define|#
directive|define
name|SFF_8472_CC_EXT
value|95
end_define

begin_comment
comment|/* Check code for the Extended ID 				    * Fields (addresses 64 to 94) 				    */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_VENDOR_RSRVD_START
value|96
end_define

begin_define
define|#
directive|define
name|SFF_8472_VENDOR_RSRVD_END
value|127
end_define

begin_define
define|#
directive|define
name|SFF_8472_RESERVED_START
value|128
end_define

begin_define
define|#
directive|define
name|SFF_8472_RESERVED_END
value|255
end_define

begin_comment
comment|/*   * Diagnostics are available at the two wire address 0xa2.  All   * diagnostics are OPTIONAL so you should check 0xa0 registers 92 to   * see which, if any are supported.   */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_DIAG
value|0xa2
end_define

begin_comment
comment|/* Base address for diagnostics. */
end_comment

begin_comment
comment|/*   *  Table 3.15 Alarm and Warning Thresholds All values are 2 bytes   * and MUST be read in a single read operation starting at the MSB   */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TEMP_HIGH_ALM
value|0
end_define

begin_comment
comment|/* Temp High Alarm  */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TEMP_LOW_ALM
value|2
end_define

begin_comment
comment|/* Temp Low Alarm */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TEMP_HIGH_WARN
value|4
end_define

begin_comment
comment|/* Temp High Warning */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TEMP_LOW_WARN
value|6
end_define

begin_comment
comment|/* Temp Low Warning */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_VOLTAGE_HIGH_ALM
value|8
end_define

begin_comment
comment|/* Voltage High Alarm */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_VOLTAGE_LOW_ALM
value|10
end_define

begin_comment
comment|/* Voltage Low Alarm */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_VOLTAGE_HIGH_WARN
value|12
end_define

begin_comment
comment|/* Voltage High Warning */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_VOLTAGE_LOW_WARN
value|14
end_define

begin_comment
comment|/* Voltage Low Warning */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_BIAS_HIGH_ALM
value|16
end_define

begin_comment
comment|/* Bias High Alarm */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_BIAS_LOW_ALM
value|18
end_define

begin_comment
comment|/* Bias Low Alarm */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_BIAS_HIGH_WARN
value|20
end_define

begin_comment
comment|/* Bias High Warning */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_BIAS_LOW_WARN
value|22
end_define

begin_comment
comment|/* Bias Low Warning */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TX_POWER_HIGH_ALM
value|24
end_define

begin_comment
comment|/* TX Power High Alarm */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TX_POWER_LOW_ALM
value|26
end_define

begin_comment
comment|/* TX Power Low Alarm */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TX_POWER_HIGH_WARN
value|28
end_define

begin_comment
comment|/* TX Power High Warning */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TX_POWER_LOW_WARN
value|30
end_define

begin_comment
comment|/* TX Power Low Warning */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RX_POWER_HIGH_ALM
value|32
end_define

begin_comment
comment|/* RX Power High Alarm */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RX_POWER_LOW_ALM
value|34
end_define

begin_comment
comment|/* RX Power Low Alarm */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RX_POWER_HIGH_WARN
value|36
end_define

begin_comment
comment|/* RX Power High Warning */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RX_POWER_LOW_WARN
value|38
end_define

begin_comment
comment|/* RX Power Low Warning */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RX_POWER4
value|56
end_define

begin_comment
comment|/* Rx_PWR(4) Single precision 				    *  floating point calibration data 				    *  - Rx optical power. Bit 7 of 				    *  byte 56 is MSB. Bit 0 of byte 				    *  59 is LSB. Rx_PWR(4) should be 				    *  set to zero for âinternally 				    *  calibratedâ devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RX_POWER3
value|60
end_define

begin_comment
comment|/* Rx_PWR(3) Single precision 				    * floating point calibration data 				    * - Rx optical power.  Bit 7 of 				    * byte 60 is MSB. Bit 0 of byte 63 				    * is LSB. Rx_PWR(3) should be set 				    * to zero for âinternally 				    * calibratedâ devices.*/
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RX_POWER2
value|64
end_define

begin_comment
comment|/* Rx_PWR(2) Single precision 				    * floating point calibration data, 				    * Rx optical power.  Bit 7 of byte 				    * 64 is MSB, bit 0 of byte 67 is 				    * LSB. Rx_PWR(2) should be set to 				    * zero for âinternally calibratedâ 				    * devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RX_POWER1
value|68
end_define

begin_comment
comment|/* Rx_PWR(1) Single precision 				    * floating point calibration data, 				    * Rx optical power. Bit 7 of byte 				    * 68 is MSB, bit 0 of byte 71 is 				    * LSB. Rx_PWR(1) should be set to 				    * 1 for âinternally calibratedâ 				    * devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RX_POWER0
value|72
end_define

begin_comment
comment|/* Rx_PWR(0) Single precision 				    * floating point calibration data, 				    * Rx optical power. Bit 7 of byte 				    * 72 is MSB, bit 0 of byte 75 is 				    * LSB. Rx_PWR(0) should be set to 				    * zero for âinternally calibratedâ 				    * devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TX_I_SLOPE
value|76
end_define

begin_comment
comment|/* Tx_I(Slope) Fixed decimal 				    * (unsigned) calibration data, 				    * laser bias current. Bit 7 of 				    * byte 76 is MSB, bit 0 of byte 77 				    * is LSB. Tx_I(Slope) should be 				    * set to 1 for âinternally 				    * calibratedâ devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TX_I_OFFSET
value|78
end_define

begin_comment
comment|/* Tx_I(Offset) Fixed decimal 				    * (signed twoâs complement) 				    * calibration data, laser bias 				    * current. Bit 7 of byte 78 is 				    * MSB, bit 0 of byte 79 is 				    * LSB. Tx_I(Offset) should be set 				    * to zero for âinternally 				    * calibratedâ devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TX_POWER_SLOPE
value|80
end_define

begin_comment
comment|/* Tx_PWR(Slope) Fixed decimal 				    * (unsigned) calibration data, 				    * transmitter coupled output 				    * power. Bit 7 of byte 80 is MSB, 				    * bit 0 of byte 81 is LSB. 				    * Tx_PWR(Slope) should be set to 1 				    * for âinternally calibratedâ 				    * devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TX_POWER_OFFSET
value|82
end_define

begin_comment
comment|/* Tx_PWR(Offset) Fixed decimal 				    * (signed twoâs complement) 				    * calibration data, transmitter 				    * coupled output power. Bit 7 of 				    * byte 82 is MSB, bit 0 of byte 83 				    * is LSB. Tx_PWR(Offset) should be 				    * set to zero for âinternally 				    * calibratedâ devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_T_SLOPE
value|84
end_define

begin_comment
comment|/* T (Slope) Fixed decimal 				    * (unsigned) calibration data, 				    * internal module temperature. Bit 				    * 7 of byte 84 is MSB, bit 0 of 				    * byte 85 is LSB.  T(Slope) should 				    * be set to 1 for âinternally 				    * calibratedâ devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_T_OFFSET
value|86
end_define

begin_comment
comment|/* T (Offset) Fixed decimal (signed 				    * twoâs complement) calibration 				    * data, internal module 				    * temperature. Bit 7 of byte 86 is 				    * MSB, bit 0 of byte 87 is LSB. 				    * T(Offset) should be set to zero 				    * for âinternally calibratedâ 				    * devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_V_SLOPE
value|88
end_define

begin_comment
comment|/* V (Slope) Fixed decimal 				    * (unsigned) calibration data, 				    * internal module supply 				    * voltage. Bit 7 of byte 88 is 				    * MSB, bit 0 of byte 89 is 				    * LSB. V(Slope) should be set to 1 				    * for âinternally calibratedâ 				    * devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_V_OFFSET
value|90
end_define

begin_comment
comment|/* V (Offset) Fixed decimal (signed 				    * twoâs complement) calibration 				    * data, internal module supply 				    * voltage. Bit 7 of byte 90 is 				    * MSB. Bit 0 of byte 91 is 				    * LSB. V(Offset) should be set to 				    * zero for âinternally calibratedâ 				    * devices. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_CHECKSUM
value|95
end_define

begin_comment
comment|/* Checksum Byte 95 contains the 				    * low order 8 bits of the sum of 				    * bytes 0 â 94. */
end_comment

begin_comment
comment|/* Internal measurements. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TEMP
value|96
end_define

begin_comment
comment|/* Internally measured module temperature. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_VCC
value|98
end_define

begin_comment
comment|/* Internally measured supply 				    * voltage in transceiver. 				    */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TX_BIAS
value|100
end_define

begin_comment
comment|/* Internally measured TX Bias Current. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_TX_POWER
value|102
end_define

begin_comment
comment|/* Measured TX output power. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_RX_POWER
value|104
end_define

begin_comment
comment|/* Measured RX input power. */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_STATUS
value|110
end_define

begin_comment
comment|/* See below */
end_comment

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

begin_define
define|#
directive|define
name|SFF_8472_ID_UNKNOWN
value|0x0
end_define

begin_comment
comment|/* Unknown or unspecified */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_GBIC
value|0x1
end_define

begin_comment
comment|/* GBIC */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_SFF
value|0x2
end_define

begin_comment
comment|/* Module soldered to motherboard (ex: SFF)*/
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_SFP
value|0x3
end_define

begin_comment
comment|/* SFP or SFP âPlusâ */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_XBI
value|0x4
end_define

begin_comment
comment|/* Reserved for â300 pin XBIâ devices */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_XENPAK
value|0x5
end_define

begin_comment
comment|/* Reserved for âXenpakâ devices */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_XFP
value|0x6
end_define

begin_comment
comment|/* Reserved for âXFPâ devices */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_XFF
value|0x7
end_define

begin_comment
comment|/* Reserved for âXFFâ devices */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_XFPE
value|0x8
end_define

begin_comment
comment|/* Reserved for âXFP-Eâ devices */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_XPAK
value|0x9
end_define

begin_comment
comment|/* Reserved for âXPakâ devices */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_X2
value|0xA
end_define

begin_comment
comment|/* Reserved for âX2â devices */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_DWDM_SFP
value|0xB
end_define

begin_comment
comment|/* Reserved for âDWDM-SFPâ devices */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_QSFP
value|0xC
end_define

begin_comment
comment|/* Reserved for âQSFPâ devices */
end_comment

begin_define
define|#
directive|define
name|SFF_8472_ID_LAST
value|SFF_8472_ID_QSFP
end_define

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

