begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * Copyright 2006-2007 Advanced Micro Devices, Inc.   * * Permission is hereby granted, free of charge, to any person obtaining a * copy of this software and associated documentation files (the "Software"), * to deal in the Software without restriction, including without limitation * the rights to use, copy, modify, merge, publish, distribute, sublicense, * and/or sell copies of the Software, and to permit persons to whom the * Software is furnished to do so, subject to the following conditions: * * The above copyright notice and this permission notice shall be included in * all copies or substantial portions of the Software. * * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR * OTHER DEALINGS IN THE SOFTWARE. */
end_comment

begin_comment
comment|/* based on stg/asic_reg/drivers/inc/asic_reg/ObjectID.h ver 23 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OBJECTID_H
end_ifndef

begin_define
define|#
directive|define
name|_OBJECTID_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_X86_
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Graphics Object Type Definition                  */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|GRAPH_OBJECT_TYPE_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|GRAPH_OBJECT_TYPE_GPU
value|0x1
end_define

begin_define
define|#
directive|define
name|GRAPH_OBJECT_TYPE_ENCODER
value|0x2
end_define

begin_define
define|#
directive|define
name|GRAPH_OBJECT_TYPE_CONNECTOR
value|0x3
end_define

begin_define
define|#
directive|define
name|GRAPH_OBJECT_TYPE_ROUTER
value|0x4
end_define

begin_comment
comment|/* deleted */
end_comment

begin_define
define|#
directive|define
name|GRAPH_OBJECT_TYPE_DISPLAY_PATH
value|0x6
end_define

begin_define
define|#
directive|define
name|GRAPH_OBJECT_TYPE_GENERIC
value|0x7
end_define

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Encoder Object ID Definition                     */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_NONE
value|0x00
end_define

begin_comment
comment|/* Radeon Class Display Hardware */
end_comment

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_LVDS
value|0x01
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_TMDS1
value|0x02
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_TMDS2
value|0x03
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_DAC1
value|0x04
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_DAC2
value|0x05
end_define

begin_comment
comment|/* TV/CV DAC */
end_comment

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_SDVOA
value|0x06
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_SDVOB
value|0x07
end_define

begin_comment
comment|/* External Third Party Encoders */
end_comment

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_SI170B
value|0x08
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_CH7303
value|0x09
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_CH7301
value|0x0A
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_DVO1
value|0x0B
end_define

begin_comment
comment|/* This belongs to Radeon Class Display Hardware */
end_comment

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_EXTERNAL_SDVOA
value|0x0C
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_EXTERNAL_SDVOB
value|0x0D
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_TITFP513
value|0x0E
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_LVTM1
value|0x0F
end_define

begin_comment
comment|/* not used for Radeon */
end_comment

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_VT1623
value|0x10
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_HDMI_SI1930
value|0x11
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_HDMI_INTERNAL
value|0x12
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_ALMOND
value|0x22
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_TRAVIS
value|0x23
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_NUTMEG
value|0x22
end_define

begin_comment
comment|/* Kaleidoscope (KLDSCP) Class Display Hardware (internal) */
end_comment

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1
value|0x13
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DVO1
value|0x14
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC1
value|0x15
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC2
value|0x16
end_define

begin_comment
comment|/* Shared with CV/TV and CRT */
end_comment

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_SI178
value|0X17
end_define

begin_comment
comment|/* External TMDS (dual link, no HDCP.) */
end_comment

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_MVPU_FPGA
value|0x18
end_define

begin_comment
comment|/* MVPU FPGA chip */
end_comment

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_DDI
value|0x19
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_VT1625
value|0x1A
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_HDMI_SI1932
value|0x1B
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_DP_AN9801
value|0x1C
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_DP_DP501
value|0x1D
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_UNIPHY
value|0x1E
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_KLDSCP_LVTMA
value|0x1F
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_UNIPHY1
value|0x20
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_UNIPHY2
value|0x21
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_INTERNAL_VCE
value|0x24
end_define

begin_define
define|#
directive|define
name|ENCODER_OBJECT_ID_GENERAL_EXTERNAL_DVO
value|0xFF
end_define

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Connector Object ID Definition                   */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_I
value|0x01
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_I
value|0x02
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_D
value|0x03
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_D
value|0x04
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_VGA
value|0x05
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_COMPOSITE
value|0x06
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_SVIDEO
value|0x07
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_YPbPr
value|0x08
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_D_CONNECTOR
value|0x09
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_9PIN_DIN
value|0x0A
end_define

begin_comment
comment|/* Supports both CV& TV */
end_comment

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_SCART
value|0x0B
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_HDMI_TYPE_A
value|0x0C
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_HDMI_TYPE_B
value|0x0D
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_LVDS
value|0x0E
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_7PIN_DIN
value|0x0F
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_PCIE_CONNECTOR
value|0x10
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_CROSSFIRE
value|0x11
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_HARDCODE_DVI
value|0x12
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_DISPLAYPORT
value|0x13
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_eDP
value|0x14
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_MXM
value|0x15
end_define

begin_define
define|#
directive|define
name|CONNECTOR_OBJECT_ID_LVDS_eDP
value|0x16
end_define

begin_comment
comment|/* deleted */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Router Object ID Definition                      */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|ROUTER_OBJECT_ID_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|ROUTER_OBJECT_ID_I2C_EXTENDER_CNTL
value|0x01
end_define

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Generic Object ID Definition                     */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|GENERIC_OBJECT_ID_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|GENERIC_OBJECT_ID_GLSYNC
value|0x01
end_define

begin_define
define|#
directive|define
name|GENERIC_OBJECT_ID_PX2_NON_DRIVABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|GENERIC_OBJECT_ID_MXM_OPM
value|0x03
end_define

begin_define
define|#
directive|define
name|GENERIC_OBJECT_ID_STEREO_PIN
value|0x04
end_define

begin_comment
comment|//This object could show up from Misc Object table, it follows ATOM_OBJECT format, and contains one ATOM_OBJECT_GPIO_CNTL_RECORD for the stereo pin
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Graphics Object ENUM ID Definition               */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|GRAPH_OBJECT_ENUM_ID1
value|0x01
end_define

begin_define
define|#
directive|define
name|GRAPH_OBJECT_ENUM_ID2
value|0x02
end_define

begin_define
define|#
directive|define
name|GRAPH_OBJECT_ENUM_ID3
value|0x03
end_define

begin_define
define|#
directive|define
name|GRAPH_OBJECT_ENUM_ID4
value|0x04
end_define

begin_define
define|#
directive|define
name|GRAPH_OBJECT_ENUM_ID5
value|0x05
end_define

begin_define
define|#
directive|define
name|GRAPH_OBJECT_ENUM_ID6
value|0x06
end_define

begin_define
define|#
directive|define
name|GRAPH_OBJECT_ENUM_ID7
value|0x07
end_define

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Graphics Object ID Bit definition                */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|OBJECT_ID_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|ENUM_ID_MASK
value|0x0700
end_define

begin_define
define|#
directive|define
name|RESERVED1_ID_MASK
value|0x0800
end_define

begin_define
define|#
directive|define
name|OBJECT_TYPE_MASK
value|0x7000
end_define

begin_define
define|#
directive|define
name|RESERVED2_ID_MASK
value|0x8000
end_define

begin_define
define|#
directive|define
name|OBJECT_ID_SHIFT
value|0x00
end_define

begin_define
define|#
directive|define
name|ENUM_ID_SHIFT
value|0x08
end_define

begin_define
define|#
directive|define
name|OBJECT_TYPE_SHIFT
value|0x0C
end_define

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Graphics Object family definition                */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|CONSTRUCTOBJECTFAMILYID
parameter_list|(
name|GRAPHICS_OBJECT_TYPE
parameter_list|,
name|GRAPHICS_OBJECT_ID
parameter_list|)
value|(GRAPHICS_OBJECT_TYPE<< OBJECT_TYPE_SHIFT | \                                                                            GRAPHICS_OBJECT_ID<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* GPU Object ID definition - Shared with BIOS      */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|GPU_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_GPU<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT)
end_define

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Encoder Object ID definition - Shared with BIOS  */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* #define ENCODER_INTERNAL_LVDS_ENUM_ID1        0x2101       #define ENCODER_INTERNAL_TMDS1_ENUM_ID1       0x2102 #define ENCODER_INTERNAL_TMDS2_ENUM_ID1       0x2103 #define ENCODER_INTERNAL_DAC1_ENUM_ID1        0x2104 #define ENCODER_INTERNAL_DAC2_ENUM_ID1        0x2105 #define ENCODER_INTERNAL_SDVOA_ENUM_ID1       0x2106 #define ENCODER_INTERNAL_SDVOB_ENUM_ID1       0x2107 #define ENCODER_SIL170B_ENUM_ID1              0x2108   #define ENCODER_CH7303_ENUM_ID1               0x2109 #define ENCODER_CH7301_ENUM_ID1               0x210A #define ENCODER_INTERNAL_DVO1_ENUM_ID1        0x210B #define ENCODER_EXTERNAL_SDVOA_ENUM_ID1       0x210C #define ENCODER_EXTERNAL_SDVOB_ENUM_ID1       0x210D #define ENCODER_TITFP513_ENUM_ID1             0x210E #define ENCODER_INTERNAL_LVTM1_ENUM_ID1       0x210F #define ENCODER_VT1623_ENUM_ID1               0x2110 #define ENCODER_HDMI_SI1930_ENUM_ID1          0x2111 #define ENCODER_HDMI_INTERNAL_ENUM_ID1        0x2112 #define ENCODER_INTERNAL_KLDSCP_TMDS1_ENUM_ID1   0x2113 #define ENCODER_INTERNAL_KLDSCP_DVO1_ENUM_ID1    0x2114 #define ENCODER_INTERNAL_KLDSCP_DAC1_ENUM_ID1    0x2115 #define ENCODER_INTERNAL_KLDSCP_DAC2_ENUM_ID1    0x2116   #define ENCODER_SI178_ENUM_ID1                   0x2117  #define ENCODER_MVPU_FPGA_ENUM_ID1               0x2118 #define ENCODER_INTERNAL_DDI_ENUM_ID1            0x2119 #define ENCODER_VT1625_ENUM_ID1                  0x211A #define ENCODER_HDMI_SI1932_ENUM_ID1             0x211B #define ENCODER_ENCODER_DP_AN9801_ENUM_ID1       0x211C #define ENCODER_DP_DP501_ENUM_ID1                0x211D #define ENCODER_INTERNAL_UNIPHY_ENUM_ID1         0x211E */
end_comment

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_LVDS_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_INTERNAL_LVDS<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_TMDS1_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_INTERNAL_TMDS1<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_TMDS2_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_INTERNAL_TMDS2<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_DAC1_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_INTERNAL_DAC1<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_DAC2_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_INTERNAL_DAC2<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_SDVOA_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_INTERNAL_SDVOA<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_SDVOA_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_INTERNAL_SDVOA<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_SDVOB_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_INTERNAL_SDVOB<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_SIL170B_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_SI170B<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_CH7303_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_CH7303<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_CH7301_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_CH7301<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_DVO1_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_INTERNAL_DVO1<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_EXTERNAL_SDVOA_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_EXTERNAL_SDVOA<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_EXTERNAL_SDVOA_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_EXTERNAL_SDVOA<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_EXTERNAL_SDVOB_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_EXTERNAL_SDVOB<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_TITFP513_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_TITFP513<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_LVTM1_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_INTERNAL_LVTM1<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_VT1623_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_VT1623<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_HDMI_SI1930_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_HDMI_SI1930<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_HDMI_INTERNAL_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_HDMI_INTERNAL<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_KLDSCP_TMDS1_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                    GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                    ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_KLDSCP_TMDS1_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                    GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                    ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_KLDSCP_DVO1_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                    GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                    ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DVO1<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_KLDSCP_DAC1_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                    GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                    ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC1<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_KLDSCP_DAC2_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                    GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                    ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC2<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|// Shared with CV/TV and CRT
end_comment

begin_define
define|#
directive|define
name|ENCODER_SI178_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                    GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                    ENCODER_OBJECT_ID_SI178<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_MVPU_FPGA_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                    GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                    ENCODER_OBJECT_ID_MVPU_FPGA<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_DDI_ENUM_ID1
value|(  GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_INTERNAL_DDI<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_VT1625_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_VT1625<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_HDMI_SI1932_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_HDMI_SI1932<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_DP_DP501_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_DP_DP501<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_DP_AN9801_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                              GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                              ENCODER_OBJECT_ID_DP_AN9801<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_UNIPHY_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  ENCODER_OBJECT_ID_INTERNAL_UNIPHY<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_UNIPHY_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  ENCODER_OBJECT_ID_INTERNAL_UNIPHY<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_KLDSCP_LVTMA_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  ENCODER_OBJECT_ID_INTERNAL_KLDSCP_LVTMA<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_UNIPHY1_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  ENCODER_OBJECT_ID_INTERNAL_UNIPHY1<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_UNIPHY1_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  ENCODER_OBJECT_ID_INTERNAL_UNIPHY1<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_UNIPHY2_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  ENCODER_OBJECT_ID_INTERNAL_UNIPHY2<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_INTERNAL_UNIPHY2_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  ENCODER_OBJECT_ID_INTERNAL_UNIPHY2<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_GENERAL_EXTERNAL_DVO_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                   GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                   ENCODER_OBJECT_ID_GENERAL_EXTERNAL_DVO<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_ALMOND_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                   GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                   ENCODER_OBJECT_ID_ALMOND<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_ALMOND_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                   GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                   ENCODER_OBJECT_ID_ALMOND<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_TRAVIS_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                   GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                   ENCODER_OBJECT_ID_TRAVIS<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_TRAVIS_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                   GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                   ENCODER_OBJECT_ID_TRAVIS<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_NUTMEG_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                   GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                   ENCODER_OBJECT_ID_NUTMEG<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|ENCODER_VCE_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ENCODER<< OBJECT_TYPE_SHIFT |\                                                   GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                   ENCODER_OBJECT_ID_INTERNAL_VCE<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Connector Object ID definition - Shared with BIOS */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* #define CONNECTOR_SINGLE_LINK_DVI_I_ENUM_ID1        0x3101 #define CONNECTOR_DUAL_LINK_DVI_I_ENUM_ID1          0x3102 #define CONNECTOR_SINGLE_LINK_DVI_D_ENUM_ID1        0x3103 #define CONNECTOR_DUAL_LINK_DVI_D_ENUM_ID1          0x3104 #define CONNECTOR_VGA_ENUM_ID1                      0x3105 #define CONNECTOR_COMPOSITE_ENUM_ID1                0x3106 #define CONNECTOR_SVIDEO_ENUM_ID1                   0x3107 #define CONNECTOR_YPbPr_ENUM_ID1                    0x3108 #define CONNECTOR_D_CONNECTORE_ENUM_ID1             0x3109 #define CONNECTOR_9PIN_DIN_ENUM_ID1                 0x310A #define CONNECTOR_SCART_ENUM_ID1                    0x310B #define CONNECTOR_HDMI_TYPE_A_ENUM_ID1              0x310C #define CONNECTOR_HDMI_TYPE_B_ENUM_ID1              0x310D #define CONNECTOR_LVDS_ENUM_ID1                     0x310E #define CONNECTOR_7PIN_DIN_ENUM_ID1                 0x310F #define CONNECTOR_PCIE_CONNECTOR_ENUM_ID1           0x3110 */
end_comment

begin_define
define|#
directive|define
name|CONNECTOR_LVDS_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_LVDS<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_LVDS_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_LVDS<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_eDP_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_eDP<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_eDP_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_eDP<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_SINGLE_LINK_DVI_I_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_I<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_SINGLE_LINK_DVI_I_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_I<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_DUAL_LINK_DVI_I_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_I<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_DUAL_LINK_DVI_I_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_I<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_SINGLE_LINK_DVI_D_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_D<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_SINGLE_LINK_DVI_D_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_D<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_SINGLE_LINK_DVI_D_ENUM_ID3
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID3<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_D<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_SINGLE_LINK_DVI_D_ENUM_ID4
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID4<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_D<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_DUAL_LINK_DVI_D_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_D<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_DUAL_LINK_DVI_D_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_D<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_DUAL_LINK_DVI_D_ENUM_ID3
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID3<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_D<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_VGA_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_VGA<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_VGA_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_VGA<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_COMPOSITE_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_COMPOSITE<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_COMPOSITE_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_COMPOSITE<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_SVIDEO_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_SVIDEO<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_SVIDEO_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_SVIDEO<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_YPbPr_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_YPbPr<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_YPbPr_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_YPbPr<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_D_CONNECTOR_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_D_CONNECTOR<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_D_CONNECTOR_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_D_CONNECTOR<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_9PIN_DIN_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_9PIN_DIN<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_9PIN_DIN_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_9PIN_DIN<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_SCART_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_SCART<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_SCART_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_SCART<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_HDMI_TYPE_A_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_HDMI_TYPE_A<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_HDMI_TYPE_A_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_HDMI_TYPE_A<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_HDMI_TYPE_A_ENUM_ID3
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID3<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_HDMI_TYPE_A<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_HDMI_TYPE_B_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_HDMI_TYPE_B<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_HDMI_TYPE_B_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_HDMI_TYPE_B<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_7PIN_DIN_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_7PIN_DIN<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_7PIN_DIN_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_7PIN_DIN<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_PCIE_CONNECTOR_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_PCIE_CONNECTOR<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_PCIE_CONNECTOR_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_PCIE_CONNECTOR<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_CROSSFIRE_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_CROSSFIRE<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_CROSSFIRE_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_CROSSFIRE<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_HARDCODE_DVI_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_HARDCODE_DVI<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_HARDCODE_DVI_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_HARDCODE_DVI<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_DISPLAYPORT_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_DISPLAYPORT<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_DISPLAYPORT_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_DISPLAYPORT<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_DISPLAYPORT_ENUM_ID3
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID3<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_DISPLAYPORT<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_DISPLAYPORT_ENUM_ID4
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID4<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_DISPLAYPORT<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_DISPLAYPORT_ENUM_ID5
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID5<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_DISPLAYPORT<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_DISPLAYPORT_ENUM_ID6
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID6<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_DISPLAYPORT<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_MXM_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_MXM<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|//Mapping to MXM_DP_A
end_comment

begin_define
define|#
directive|define
name|CONNECTOR_MXM_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_MXM<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|//Mapping to MXM_DP_B
end_comment

begin_define
define|#
directive|define
name|CONNECTOR_MXM_ENUM_ID3
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID3<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_MXM<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|//Mapping to MXM_DP_C
end_comment

begin_define
define|#
directive|define
name|CONNECTOR_MXM_ENUM_ID4
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID4<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_MXM<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|//Mapping to MXM_DP_D
end_comment

begin_define
define|#
directive|define
name|CONNECTOR_MXM_ENUM_ID5
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID5<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_MXM<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|//Mapping to MXM_LVDS_TXxx
end_comment

begin_define
define|#
directive|define
name|CONNECTOR_MXM_ENUM_ID6
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID6<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_MXM<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|//Mapping to MXM_LVDS_UXxx
end_comment

begin_define
define|#
directive|define
name|CONNECTOR_MXM_ENUM_ID7
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID7<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_MXM<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|//Mapping to MXM_DAC
end_comment

begin_define
define|#
directive|define
name|CONNECTOR_LVDS_eDP_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_LVDS_eDP<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CONNECTOR_LVDS_eDP_ENUM_ID2
value|( GRAPH_OBJECT_TYPE_CONNECTOR<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  CONNECTOR_OBJECT_ID_LVDS_eDP<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Router Object ID definition - Shared with BIOS   */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|ROUTER_I2C_EXTENDER_CNTL_ENUM_ID1
value|( GRAPH_OBJECT_TYPE_ROUTER<< OBJECT_TYPE_SHIFT |\                                                 GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                 ROUTER_OBJECT_ID_I2C_EXTENDER_CNTL<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|/* deleted */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Generic Object ID definition - Shared with BIOS  */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|GENERICOBJECT_GLSYNC_ENUM_ID1
value|(GRAPH_OBJECT_TYPE_GENERIC<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  GENERIC_OBJECT_ID_GLSYNC<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|GENERICOBJECT_PX2_NON_DRIVABLE_ID1
value|(GRAPH_OBJECT_TYPE_GENERIC<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  GENERIC_OBJECT_ID_PX2_NON_DRIVABLE<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|GENERICOBJECT_PX2_NON_DRIVABLE_ID2
value|(GRAPH_OBJECT_TYPE_GENERIC<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID2<< ENUM_ID_SHIFT |\                                                  GENERIC_OBJECT_ID_PX2_NON_DRIVABLE<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|GENERICOBJECT_MXM_OPM_ENUM_ID1
value|(GRAPH_OBJECT_TYPE_GENERIC<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  GENERIC_OBJECT_ID_MXM_OPM<< OBJECT_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|GENERICOBJECT_STEREO_PIN_ENUM_ID1
value|(GRAPH_OBJECT_TYPE_GENERIC<< OBJECT_TYPE_SHIFT |\                                                  GRAPH_OBJECT_ENUM_ID1<< ENUM_ID_SHIFT |\                                                  GENERIC_OBJECT_ID_STEREO_PIN<< OBJECT_ID_SHIFT)
end_define

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/* Object Cap definition - Shared with BIOS         */
end_comment

begin_comment
comment|/****************************************************/
end_comment

begin_define
define|#
directive|define
name|GRAPHICS_OBJECT_CAP_I2C
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|GRAPHICS_OBJECT_CAP_TABLE_ID
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|GRAPHICS_OBJECT_I2CCOMMAND_TABLE_ID
value|0x01
end_define

begin_define
define|#
directive|define
name|GRAPHICS_OBJECT_HOTPLUGDETECTIONINTERUPT_TABLE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|GRAPHICS_OBJECT_ENCODER_OUTPUT_PROTECTION_TABLE_ID
value|0x03
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_X86_
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*GRAPHICTYPE */
end_comment

end_unit

