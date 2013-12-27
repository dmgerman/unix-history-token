begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2006-2007 Advanced Micro Devices, Inc.    *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

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

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*Portion I: Definitions  shared between VBIOS and Driver                   */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATOMBIOS_H
end_ifndef

begin_define
define|#
directive|define
name|_ATOMBIOS_H
end_define

begin_define
define|#
directive|define
name|ATOM_VERSION_MAJOR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ATOM_VERSION_MINOR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATOM_HEADER_VERSION
value|(ATOM_VERSION_MAJOR | ATOM_VERSION_MINOR)
end_define

begin_comment
comment|/* Endianness should be specified before inclusion,  * default to little endian  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATOM_BIG_ENDIAN
end_ifndef

begin_error
error|#
directive|error
error|Endian not specified
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_H2INC
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ULONG
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ULONG
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UCHAR
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UCHAR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USHORT
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|USHORT
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ATOM_DAC_A
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_DAC_B
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_EXT_DAC
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_CRTC1
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_CRTC2
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_CRTC3
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_CRTC4
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_CRTC5
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_CRTC6
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_CRTC_INVALID
value|0xFF
end_define

begin_define
define|#
directive|define
name|ATOM_DIGA
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_DIGB
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL1
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL2
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_DCPLL
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL0
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_EXT_PLL1
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_EXT_PLL2
value|9
end_define

begin_define
define|#
directive|define
name|ATOM_EXT_CLOCK
value|10
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_INVALID
value|0xFF
end_define

begin_define
define|#
directive|define
name|ENCODER_REFCLK_SRC_P1PLL
value|0
end_define

begin_define
define|#
directive|define
name|ENCODER_REFCLK_SRC_P2PLL
value|1
end_define

begin_define
define|#
directive|define
name|ENCODER_REFCLK_SRC_DCPLL
value|2
end_define

begin_define
define|#
directive|define
name|ENCODER_REFCLK_SRC_EXTCLK
value|3
end_define

begin_define
define|#
directive|define
name|ENCODER_REFCLK_SRC_INVALID
value|0xFF
end_define

begin_define
define|#
directive|define
name|ATOM_SCALER1
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_SCALER2
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_SCALER_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_SCALER_CENTER
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_SCALER_EXPANSION
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_SCALER_MULTI_EX
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_LCD_BLOFF
value|(ATOM_DISABLE+2)
end_define

begin_define
define|#
directive|define
name|ATOM_LCD_BLON
value|(ATOM_ENABLE+2)
end_define

begin_define
define|#
directive|define
name|ATOM_LCD_BL_BRIGHTNESS_CONTROL
value|(ATOM_ENABLE+3)
end_define

begin_define
define|#
directive|define
name|ATOM_LCD_SELFTEST_START
value|(ATOM_DISABLE+5)
end_define

begin_define
define|#
directive|define
name|ATOM_LCD_SELFTEST_STOP
value|(ATOM_ENABLE+5)
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_INIT
value|(ATOM_DISABLE+7)
end_define

begin_define
define|#
directive|define
name|ATOM_INIT
value|(ATOM_DISABLE+7)
end_define

begin_define
define|#
directive|define
name|ATOM_GET_STATUS
value|(ATOM_DISABLE+8)
end_define

begin_define
define|#
directive|define
name|ATOM_BLANKING
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_BLANKING_OFF
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_CURSOR1
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_CURSOR2
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_ICON1
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_ICON2
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_CRT1
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_CRT2
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_TV_NTSC
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_TV_NTSCJ
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_TV_PAL
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_TV_PALM
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_TV_PALCN
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_TV_PALN
value|6
end_define

begin_define
define|#
directive|define
name|ATOM_TV_PAL60
value|7
end_define

begin_define
define|#
directive|define
name|ATOM_TV_SECAM
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_TV_CV
value|16
end_define

begin_define
define|#
directive|define
name|ATOM_DAC1_PS2
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_DAC1_CV
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_DAC1_NTSC
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_DAC1_PAL
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_DAC2_PS2
value|ATOM_DAC1_PS2
end_define

begin_define
define|#
directive|define
name|ATOM_DAC2_CV
value|ATOM_DAC1_CV
end_define

begin_define
define|#
directive|define
name|ATOM_DAC2_NTSC
value|ATOM_DAC1_NTSC
end_define

begin_define
define|#
directive|define
name|ATOM_DAC2_PAL
value|ATOM_DAC1_PAL
end_define

begin_define
define|#
directive|define
name|ATOM_PM_ON
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_PM_STANDBY
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_PM_SUSPEND
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_PM_OFF
value|3
end_define

begin_comment
comment|/* Bit0:{=0:single, =1:dual},    Bit1 {=0:666RGB, =1:888RGB},    Bit2:3:{Grey level}    Bit4:{=0:LDI format for RGB888, =1 FPDI format for RGB888}*/
end_comment

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_DUAL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_888RGB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_GREY_LEVEL
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_FPDI
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_GREY_LEVEL_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_SPATIAL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_TEMPORAL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_API_ENABLED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MEMTYPE_DDR1
value|"DDR1"
end_define

begin_define
define|#
directive|define
name|MEMTYPE_DDR2
value|"DDR2"
end_define

begin_define
define|#
directive|define
name|MEMTYPE_DDR3
value|"DDR3"
end_define

begin_define
define|#
directive|define
name|MEMTYPE_DDR4
value|"DDR4"
end_define

begin_define
define|#
directive|define
name|ASIC_BUS_TYPE_PCI
value|"PCI"
end_define

begin_define
define|#
directive|define
name|ASIC_BUS_TYPE_AGP
value|"AGP"
end_define

begin_define
define|#
directive|define
name|ASIC_BUS_TYPE_PCIE
value|"PCI_EXPRESS"
end_define

begin_comment
comment|/* Maximum size of that FireGL flag string */
end_comment

begin_define
define|#
directive|define
name|ATOM_FIREGL_FLAG_STRING
value|"FGL"
end_define

begin_comment
comment|//Flag used to enable FireGL Support
end_comment

begin_define
define|#
directive|define
name|ATOM_MAX_SIZE_OF_FIREGL_FLAG_STRING
value|3
end_define

begin_comment
comment|//sizeof( ATOM_FIREGL_FLAG_STRING )
end_comment

begin_define
define|#
directive|define
name|ATOM_FAKE_DESKTOP_STRING
value|"DSK"
end_define

begin_comment
comment|//Flag used to enable mobile ASIC on Desktop
end_comment

begin_define
define|#
directive|define
name|ATOM_MAX_SIZE_OF_FAKE_DESKTOP_STRING
value|ATOM_MAX_SIZE_OF_FIREGL_FLAG_STRING
end_define

begin_define
define|#
directive|define
name|ATOM_M54T_FLAG_STRING
value|"M54T"
end_define

begin_comment
comment|//Flag used to enable M54T Support
end_comment

begin_define
define|#
directive|define
name|ATOM_MAX_SIZE_OF_M54T_FLAG_STRING
value|4
end_define

begin_comment
comment|//sizeof( ATOM_M54T_FLAG_STRING )
end_comment

begin_define
define|#
directive|define
name|HW_ASSISTED_I2C_STATUS_FAILURE
value|2
end_define

begin_define
define|#
directive|define
name|HW_ASSISTED_I2C_STATUS_SUCCESS
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|/* BIOS data must use byte aligment */
end_comment

begin_comment
comment|/*  Define offset to location of ROM header. */
end_comment

begin_define
define|#
directive|define
name|OFFSET_TO_POINTER_TO_ATOM_ROM_HEADER
value|0x00000048L
end_define

begin_define
define|#
directive|define
name|OFFSET_TO_ATOM_ROM_IMAGE_SIZE
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|OFFSET_TO_ATOMBIOS_ASIC_BUS_MEM_TYPE
value|0x94
end_define

begin_define
define|#
directive|define
name|MAXSIZE_OF_ATOMBIOS_ASIC_BUS_MEM_TYPE
value|20
end_define

begin_comment
comment|/* including the terminator 0x0! */
end_comment

begin_define
define|#
directive|define
name|OFFSET_TO_GET_ATOMBIOS_STRINGS_NUMBER
value|0x002f
end_define

begin_define
define|#
directive|define
name|OFFSET_TO_GET_ATOMBIOS_STRINGS_START
value|0x006e
end_define

begin_comment
comment|/* Common header for all ROM Data tables.   Every table pointed  _ATOM_MASTER_DATA_TABLE has this common header.    And the pointer actually points to this header. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_COMMON_TABLE_HEADER
block|{
name|USHORT
name|usStructureSize
decl_stmt|;
name|UCHAR
name|ucTableFormatRevision
decl_stmt|;
comment|/*Change it when the Parser is not backward compatible */
name|UCHAR
name|ucTableContentRevision
decl_stmt|;
comment|/*Change it only when the table needs to change but the firmware */
comment|/*Image can't be updated, while Driver needs to carry the new table! */
block|}
name|ATOM_COMMON_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure stores the ROM header.
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ROM_HEADER
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|uaFirmWareSignature
index|[
literal|4
index|]
decl_stmt|;
comment|/*Signature to distinguish between Atombios and non-atombios,                                        atombios should init it as "ATOM", don't change the position */
name|USHORT
name|usBiosRuntimeSegmentAddress
decl_stmt|;
name|USHORT
name|usProtectedModeInfoOffset
decl_stmt|;
name|USHORT
name|usConfigFilenameOffset
decl_stmt|;
name|USHORT
name|usCRC_BlockOffset
decl_stmt|;
name|USHORT
name|usBIOS_BootupMessageOffset
decl_stmt|;
name|USHORT
name|usInt10Offset
decl_stmt|;
name|USHORT
name|usPciBusDevInitCode
decl_stmt|;
name|USHORT
name|usIoBaseAddress
decl_stmt|;
name|USHORT
name|usSubsystemVendorID
decl_stmt|;
name|USHORT
name|usSubsystemID
decl_stmt|;
name|USHORT
name|usPCI_InfoOffset
decl_stmt|;
name|USHORT
name|usMasterCommandTableOffset
decl_stmt|;
comment|/*Offset for SW to get all command table offsets, Don't change the position */
name|USHORT
name|usMasterDataTableOffset
decl_stmt|;
comment|/*Offset for SW to get all data table offsets, Don't change the position */
name|UCHAR
name|ucExtendedFunctionCode
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|ATOM_ROM_HEADER
typedef|;
end_typedef

begin_comment
comment|/*==============================Command Table Portion==================================== */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UEFI_BUILD
end_ifdef

begin_define
define|#
directive|define
name|UTEMP
value|USHORT
end_define

begin_define
define|#
directive|define
name|USHORT
value|void*
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used in Command.mtb
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MASTER_LIST_OF_COMMAND_TABLES
block|{
name|USHORT
name|ASIC_Init
decl_stmt|;
comment|//Function Table, used by various SW components,latest version 1.1
name|USHORT
name|GetDisplaySurfaceSize
decl_stmt|;
comment|//Atomic Table,  Used by Bios when enabling HW ICON
name|USHORT
name|ASIC_RegistersInit
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from ASIC_Init
name|USHORT
name|VRAM_BlockVenderDetection
decl_stmt|;
comment|//Atomic Table,  used only by Bios
name|USHORT
name|DIGxEncoderControl
decl_stmt|;
comment|//Only used by Bios
name|USHORT
name|MemoryControllerInit
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from ASIC_Init
name|USHORT
name|EnableCRTCMemReq
decl_stmt|;
comment|//Function Table,directly used by various SW components,latest version 2.1
name|USHORT
name|MemoryParamAdjust
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from SetMemoryClock if needed
name|USHORT
name|DVOEncoderControl
decl_stmt|;
comment|//Function Table,directly used by various SW components,latest version 1.2
name|USHORT
name|GPIOPinControl
decl_stmt|;
comment|//Atomic Table,  only used by Bios
name|USHORT
name|SetEngineClock
decl_stmt|;
comment|//Function Table,directly used by various SW components,latest version 1.1
name|USHORT
name|SetMemoryClock
decl_stmt|;
comment|//Function Table,directly used by various SW components,latest version 1.1
name|USHORT
name|SetPixelClock
decl_stmt|;
comment|//Function Table,directly used by various SW components,latest version 1.2
name|USHORT
name|EnableDispPowerGating
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from ASIC_Init
name|USHORT
name|ResetMemoryDLL
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
name|USHORT
name|ResetMemoryDevice
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
name|USHORT
name|MemoryPLLInit
decl_stmt|;
comment|//Atomic Table,  used only by Bios
name|USHORT
name|AdjustDisplayPll
decl_stmt|;
comment|//Atomic Table,  used by various SW componentes.
name|USHORT
name|AdjustMemoryController
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
name|USHORT
name|EnableASIC_StaticPwrMgt
decl_stmt|;
comment|//Atomic Table,  only used by Bios
name|USHORT
name|ASIC_StaticPwrMgtStatusChange
decl_stmt|;
comment|//Obsolete ,     only used by Bios
name|USHORT
name|DAC_LoadDetection
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.2
name|USHORT
name|LVTMAEncoderControl
decl_stmt|;
comment|//Atomic Table,directly used by various SW components,latest version 1.3
name|USHORT
name|HW_Misc_Operation
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|DAC1EncoderControl
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|DAC2EncoderControl
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|DVOOutputControl
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|CV1OutputControl
decl_stmt|;
comment|//Atomic Table,  Atomic Table,  Obsolete from Ry6xx, use DAC2 Output instead
name|USHORT
name|GetConditionalGoldenSetting
decl_stmt|;
comment|//Only used by Bios
name|USHORT
name|TVEncoderControl
decl_stmt|;
comment|//Function Table,directly used by various SW components,latest version 1.1
name|USHORT
name|PatchMCSetting
decl_stmt|;
comment|//only used by BIOS
name|USHORT
name|MC_SEQ_Control
decl_stmt|;
comment|//only used by BIOS
name|USHORT
name|TV1OutputControl
decl_stmt|;
comment|//Atomic Table,  Obsolete from Ry6xx, use DAC2 Output instead
name|USHORT
name|EnableScaler
decl_stmt|;
comment|//Atomic Table,  used only by Bios
name|USHORT
name|BlankCRTC
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|EnableCRTC
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|GetPixelClock
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|EnableVGA_Render
decl_stmt|;
comment|//Function Table,directly used by various SW components,latest version 1.1
name|USHORT
name|GetSCLKOverMCLKRatio
decl_stmt|;
comment|//Atomic Table,  only used by Bios
name|USHORT
name|SetCRTC_Timing
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|SetCRTC_OverScan
decl_stmt|;
comment|//Atomic Table,  used by various SW components,latest version 1.1
name|USHORT
name|SetCRTC_Replication
decl_stmt|;
comment|//Atomic Table,  used only by Bios
name|USHORT
name|SelectCRTC_Source
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|EnableGraphSurfaces
decl_stmt|;
comment|//Atomic Table,  used only by Bios
name|USHORT
name|UpdateCRTC_DoubleBufferRegisters
decl_stmt|;
comment|//Atomic Table,  used only by Bios
name|USHORT
name|LUT_AutoFill
decl_stmt|;
comment|//Atomic Table,  only used by Bios
name|USHORT
name|EnableHW_IconCursor
decl_stmt|;
comment|//Atomic Table,  only used by Bios
name|USHORT
name|GetMemoryClock
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|GetEngineClock
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|SetCRTC_UsingDTDTiming
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|ExternalEncoderControl
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 2.1
name|USHORT
name|LVTMAOutputControl
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|VRAM_BlockDetectionByStrap
decl_stmt|;
comment|//Atomic Table,  used only by Bios
name|USHORT
name|MemoryCleanUp
decl_stmt|;
comment|//Atomic Table,  only used by Bios
name|USHORT
name|ProcessI2cChannelTransaction
decl_stmt|;
comment|//Function Table,only used by Bios
name|USHORT
name|WriteOneByteToHWAssistedI2C
decl_stmt|;
comment|//Function Table,indirectly used by various SW components
name|USHORT
name|ReadHWAssistedI2CStatus
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components
name|USHORT
name|SpeedFanControl
decl_stmt|;
comment|//Function Table,indirectly used by various SW components,called from ASIC_Init
name|USHORT
name|PowerConnectorDetection
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|MC_Synchronization
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
name|USHORT
name|ComputeMemoryEnginePLL
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from SetMemory/EngineClock
name|USHORT
name|MemoryRefreshConversion
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from SetMemory or SetEngineClock
name|USHORT
name|VRAM_GetCurrentInfoBlock
decl_stmt|;
comment|//Atomic Table,  used only by Bios
name|USHORT
name|DynamicMemorySettings
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
name|USHORT
name|MemoryTraining
decl_stmt|;
comment|//Atomic Table,  used only by Bios
name|USHORT
name|EnableSpreadSpectrumOnPPLL
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.2
name|USHORT
name|TMDSAOutputControl
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|SetVoltage
decl_stmt|;
comment|//Function Table,directly and/or indirectly used by various SW components,latest version 1.1
name|USHORT
name|DAC1OutputControl
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|DAC2OutputControl
decl_stmt|;
comment|//Atomic Table,  directly used by various SW components,latest version 1.1
name|USHORT
name|ComputeMemoryClockParam
decl_stmt|;
comment|//Function Table,only used by Bios, obsolete soon.Switch to use "ReadEDIDFromHWAssistedI2C"
name|USHORT
name|ClockSource
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from ASIC_Init
name|USHORT
name|MemoryDeviceInit
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
name|USHORT
name|GetDispObjectInfo
decl_stmt|;
comment|//Atomic Table,  indirectly used by various SW components,called from EnableVGARender
name|USHORT
name|DIG1EncoderControl
decl_stmt|;
comment|//Atomic Table,directly used by various SW components,latest version 1.1
name|USHORT
name|DIG2EncoderControl
decl_stmt|;
comment|//Atomic Table,directly used by various SW components,latest version 1.1
name|USHORT
name|DIG1TransmitterControl
decl_stmt|;
comment|//Atomic Table,directly used by various SW components,latest version 1.1
name|USHORT
name|DIG2TransmitterControl
decl_stmt|;
comment|//Atomic Table,directly used by various SW components,latest version 1.1
name|USHORT
name|ProcessAuxChannelTransaction
decl_stmt|;
comment|//Function Table,only used by Bios
name|USHORT
name|DPEncoderService
decl_stmt|;
comment|//Function Table,only used by Bios
name|USHORT
name|GetVoltageInfo
decl_stmt|;
comment|//Function Table,only used by Bios since SI
block|}
name|ATOM_MASTER_LIST_OF_COMMAND_TABLES
typedef|;
end_typedef

begin_comment
comment|// For backward compatible
end_comment

begin_define
define|#
directive|define
name|ReadEDIDFromHWAssistedI2C
value|ProcessI2cChannelTransaction
end_define

begin_define
define|#
directive|define
name|DPTranslatorControl
value|DIG2EncoderControl
end_define

begin_define
define|#
directive|define
name|UNIPHYTransmitterControl
value|DIG1TransmitterControl
end_define

begin_define
define|#
directive|define
name|LVTMATransmitterControl
value|DIG2TransmitterControl
end_define

begin_define
define|#
directive|define
name|SetCRTC_DPM_State
value|GetConditionalGoldenSetting
end_define

begin_define
define|#
directive|define
name|SetUniphyInstance
value|ASIC_StaticPwrMgtStatusChange
end_define

begin_define
define|#
directive|define
name|HPDInterruptService
value|ReadHWAssistedI2CStatus
end_define

begin_define
define|#
directive|define
name|EnableVGA_Access
value|GetSCLKOverMCLKRatio
end_define

begin_define
define|#
directive|define
name|EnableYUV
value|GetDispObjectInfo
end_define

begin_define
define|#
directive|define
name|DynamicClockGating
value|EnableDispPowerGating
end_define

begin_define
define|#
directive|define
name|SetupHWAssistedI2CStatus
value|ComputeMemoryClockParam
end_define

begin_define
define|#
directive|define
name|TMDSAEncoderControl
value|PatchMCSetting
end_define

begin_define
define|#
directive|define
name|LVDSEncoderControl
value|MC_SEQ_Control
end_define

begin_define
define|#
directive|define
name|LCD1OutputControl
value|HW_Misc_Operation
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MASTER_COMMAND_TABLE
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_MASTER_LIST_OF_COMMAND_TABLES
name|ListOfCommandTables
decl_stmt|;
block|}
name|ATOM_MASTER_COMMAND_TABLE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used in every command table
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_TABLE_ATTRIBUTE
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|USHORT
name|UpdatedByUtility
range|:
literal|1
decl_stmt|;
comment|//[15]=Table updated by utility flag
name|USHORT
name|PS_SizeInBytes
range|:
literal|7
decl_stmt|;
comment|//[14:8]=Size of parameter space in Bytes (multiple of a dword),
name|USHORT
name|WS_SizeInBytes
range|:
literal|8
decl_stmt|;
comment|//[7:0]=Size of workspace in Bytes (in multiple of a dword),
else|#
directive|else
name|USHORT
name|WS_SizeInBytes
range|:
literal|8
decl_stmt|;
comment|//[7:0]=Size of workspace in Bytes (in multiple of a dword),
name|USHORT
name|PS_SizeInBytes
range|:
literal|7
decl_stmt|;
comment|//[14:8]=Size of parameter space in Bytes (multiple of a dword),
name|USHORT
name|UpdatedByUtility
range|:
literal|1
decl_stmt|;
comment|//[15]=Table updated by utility flag
endif|#
directive|endif
block|}
name|ATOM_TABLE_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_ATOM_TABLE_ATTRIBUTE_ACCESS
block|{
name|ATOM_TABLE_ATTRIBUTE
name|sbfAccess
decl_stmt|;
name|USHORT
name|susAccess
decl_stmt|;
block|}
name|ATOM_TABLE_ATTRIBUTE_ACCESS
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Common header for all command tables.
end_comment

begin_comment
comment|// Every table pointed by _ATOM_MASTER_COMMAND_TABLE has this common header.
end_comment

begin_comment
comment|// And the pointer actually points to this header.
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_COMMON_ROM_COMMAND_TABLE_HEADER
block|{
name|ATOM_COMMON_TABLE_HEADER
name|CommonHeader
decl_stmt|;
name|ATOM_TABLE_ATTRIBUTE
name|TableAttribute
decl_stmt|;
block|}
name|ATOM_COMMON_ROM_COMMAND_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by ComputeMemoryEnginePLLTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|COMPUTE_MEMORY_PLL_PARAM
value|1
end_define

begin_define
define|#
directive|define
name|COMPUTE_ENGINE_PLL_PARAM
value|2
end_define

begin_define
define|#
directive|define
name|ADJUST_MC_SETTING_PARAM
value|3
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by AdjustMemoryControllerTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ADJUST_MEMORY_CLOCK_FREQ
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|ULONG
name|ulPointerReturnFlag
range|:
literal|1
decl_stmt|;
comment|// BYTE_3[7]=1 - Return the pointer to the right Data Block; BYTE_3[7]=0 - Program the right Data Block
name|ULONG
name|ulMemoryModuleNumber
range|:
literal|7
decl_stmt|;
comment|// BYTE_3[6:0]
name|ULONG
name|ulClockFreq
range|:
literal|24
decl_stmt|;
else|#
directive|else
name|ULONG
name|ulClockFreq
range|:
literal|24
decl_stmt|;
name|ULONG
name|ulMemoryModuleNumber
range|:
literal|7
decl_stmt|;
comment|// BYTE_3[6:0]
name|ULONG
name|ulPointerReturnFlag
range|:
literal|1
decl_stmt|;
comment|// BYTE_3[7]=1 - Return the pointer to the right Data Block; BYTE_3[7]=0 - Program the right Data Block
endif|#
directive|endif
block|}
name|ATOM_ADJUST_MEMORY_CLOCK_FREQ
typedef|;
end_typedef

begin_define
define|#
directive|define
name|POINTER_RETURN_FLAG
value|0x80
end_define

begin_typedef
typedef|typedef
struct|struct
name|_COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS
block|{
name|ULONG
name|ulClock
decl_stmt|;
comment|//When returen, it's the re-calculated clock based on given Fb_div Post_Div and ref_div
name|UCHAR
name|ucAction
decl_stmt|;
comment|//0:reserved //1:Memory //2:Engine
name|UCHAR
name|ucReserved
decl_stmt|;
comment|//may expand to return larger Fbdiv later
name|UCHAR
name|ucFbDiv
decl_stmt|;
comment|//return value
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|//return value
block|}
name|COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS_V2
block|{
name|ULONG
name|ulClock
decl_stmt|;
comment|//When return, [23:0] return real clock
name|UCHAR
name|ucAction
decl_stmt|;
comment|//0:reserved;COMPUTE_MEMORY_PLL_PARAM:Memory;COMPUTE_ENGINE_PLL_PARAM:Engine. it return ref_div to be written to register
name|USHORT
name|usFbDiv
decl_stmt|;
comment|//return Feedback value to be written to register
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|//return post div to be written to register
block|}
name|COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS_V2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS_PS_ALLOCATION
value|COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|SET_CLOCK_FREQ_MASK
value|0x00FFFFFF
end_define

begin_comment
comment|//Clock change tables only take bit [23:0] as the requested clock value
end_comment

begin_define
define|#
directive|define
name|USE_NON_BUS_CLOCK_MASK
value|0x01000000
end_define

begin_comment
comment|//Applicable to both memory and engine clock change, when set, it uses another clock as the temporary clock (engine uses memory and vice versa)
end_comment

begin_define
define|#
directive|define
name|USE_MEMORY_SELF_REFRESH_MASK
value|0x02000000
end_define

begin_comment
comment|//Only applicable to memory clock change, when set, using memory self refresh during clock transition
end_comment

begin_define
define|#
directive|define
name|SKIP_INTERNAL_MEMORY_PARAMETER_CHANGE
value|0x04000000
end_define

begin_comment
comment|//Only applicable to memory clock change, when set, the table will skip predefined internal memory parameter change
end_comment

begin_define
define|#
directive|define
name|FIRST_TIME_CHANGE_CLOCK
value|0x08000000
end_define

begin_comment
comment|//Applicable to both memory and engine clock change,when set, it means this is 1st time to change clock after ASIC bootup
end_comment

begin_define
define|#
directive|define
name|SKIP_SW_PROGRAM_PLL
value|0x10000000
end_define

begin_comment
comment|//Applicable to both memory and engine clock change, when set, it means the table will not program SPLL/MPLL
end_comment

begin_define
define|#
directive|define
name|USE_SS_ENABLED_PIXEL_CLOCK
value|USE_NON_BUS_CLOCK_MASK
end_define

begin_define
define|#
directive|define
name|b3USE_NON_BUS_CLOCK_MASK
value|0x01
end_define

begin_comment
comment|//Applicable to both memory and engine clock change, when set, it uses another clock as the temporary clock (engine uses memory and vice versa)
end_comment

begin_define
define|#
directive|define
name|b3USE_MEMORY_SELF_REFRESH
value|0x02
end_define

begin_comment
comment|//Only applicable to memory clock change, when set, using memory self refresh during clock transition
end_comment

begin_define
define|#
directive|define
name|b3SKIP_INTERNAL_MEMORY_PARAMETER_CHANGE
value|0x04
end_define

begin_comment
comment|//Only applicable to memory clock change, when set, the table will skip predefined internal memory parameter change
end_comment

begin_define
define|#
directive|define
name|b3FIRST_TIME_CHANGE_CLOCK
value|0x08
end_define

begin_comment
comment|//Applicable to both memory and engine clock change,when set, it means this is 1st time to change clock after ASIC bootup
end_comment

begin_define
define|#
directive|define
name|b3SKIP_SW_PROGRAM_PLL
value|0x10
end_define

begin_comment
comment|//Applicable to both memory and engine clock change, when set, it means the table will not program SPLL/MPLL
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_COMPUTE_CLOCK_FREQ
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|ULONG
name|ulComputeClockFlag
range|:
literal|8
decl_stmt|;
comment|// =1: COMPUTE_MEMORY_PLL_PARAM, =2: COMPUTE_ENGINE_PLL_PARAM
name|ULONG
name|ulClockFreq
range|:
literal|24
decl_stmt|;
comment|// in unit of 10kHz
else|#
directive|else
name|ULONG
name|ulClockFreq
range|:
literal|24
decl_stmt|;
comment|// in unit of 10kHz
name|ULONG
name|ulComputeClockFlag
range|:
literal|8
decl_stmt|;
comment|// =1: COMPUTE_MEMORY_PLL_PARAM, =2: COMPUTE_ENGINE_PLL_PARAM
endif|#
directive|endif
block|}
name|ATOM_COMPUTE_CLOCK_FREQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_S_MPLL_FB_DIVIDER
block|{
name|USHORT
name|usFbDivFrac
decl_stmt|;
name|USHORT
name|usFbDiv
decl_stmt|;
block|}
name|ATOM_S_MPLL_FB_DIVIDER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS_V3
block|{
union|union
block|{
name|ATOM_COMPUTE_CLOCK_FREQ
name|ulClock
decl_stmt|;
comment|//Input Parameter
name|ATOM_S_MPLL_FB_DIVIDER
name|ulFbDiv
decl_stmt|;
comment|//Output Parameter
block|}
union|;
name|UCHAR
name|ucRefDiv
decl_stmt|;
comment|//Output Parameter
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|//Output Parameter
name|UCHAR
name|ucCntlFlag
decl_stmt|;
comment|//Output Parameter
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS_V3
typedef|;
end_typedef

begin_comment
comment|// ucCntlFlag
end_comment

begin_define
define|#
directive|define
name|ATOM_PLL_CNTL_FLAG_PLL_POST_DIV_EN
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_PLL_CNTL_FLAG_MPLL_VCO_MODE
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_PLL_CNTL_FLAG_FRACTION_DISABLE
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_PLL_CNTL_FLAG_SPLL_ISPARE_9
value|8
end_define

begin_comment
comment|// V4 are only used for APU which PLL outside GPU
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS_V4
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|ULONG
name|ucPostDiv
decl_stmt|;
comment|//return parameter: post divider which is used to program to register directly
name|ULONG
name|ulClock
range|:
literal|24
decl_stmt|;
comment|//Input= target clock, output = actual clock
else|#
directive|else
name|ULONG
name|ulClock
range|:
literal|24
decl_stmt|;
comment|//Input= target clock, output = actual clock
name|ULONG
name|ucPostDiv
decl_stmt|;
comment|//return parameter: post divider which is used to program to register directly
endif|#
directive|endif
block|}
name|COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS_V4
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS_V5
block|{
union|union
block|{
name|ATOM_COMPUTE_CLOCK_FREQ
name|ulClock
decl_stmt|;
comment|//Input Parameter
name|ATOM_S_MPLL_FB_DIVIDER
name|ulFbDiv
decl_stmt|;
comment|//Output Parameter
block|}
union|;
name|UCHAR
name|ucRefDiv
decl_stmt|;
comment|//Output Parameter
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|//Output Parameter
union|union
block|{
name|UCHAR
name|ucCntlFlag
decl_stmt|;
comment|//Output Flags
name|UCHAR
name|ucInputFlag
decl_stmt|;
comment|//Input Flags. ucInputFlag[0] - Strobe(1)/Performance(0) mode
block|}
union|;
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS_V5
typedef|;
end_typedef

begin_comment
comment|// ucInputFlag
end_comment

begin_define
define|#
directive|define
name|ATOM_PLL_INPUT_FLAG_PLL_STROBE_MODE_EN
value|1
end_define

begin_comment
comment|// 1-StrobeMode, 0-PerformanceMode
end_comment

begin_comment
comment|// use for ComputeMemoryClockParamTable
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_COMPUTE_MEMORY_CLOCK_PARAM_PARAMETERS_V2_1
block|{
union|union
block|{
name|ULONG
name|ulClock
decl_stmt|;
name|ATOM_S_MPLL_FB_DIVIDER
name|ulFbDiv
decl_stmt|;
comment|//Output:UPPER_WORD=FB_DIV_INTEGER,  LOWER_WORD=FB_DIV_FRAC shl (16-FB_FRACTION_BITS)
block|}
union|;
name|UCHAR
name|ucDllSpeed
decl_stmt|;
comment|//Output
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|//Output
union|union
block|{
name|UCHAR
name|ucInputFlag
decl_stmt|;
comment|//Input : ATOM_PLL_INPUT_FLAG_PLL_STROBE_MODE_EN: 1-StrobeMode, 0-PerformanceMode
name|UCHAR
name|ucPllCntlFlag
decl_stmt|;
comment|//Output:
block|}
union|;
name|UCHAR
name|ucBWCntl
decl_stmt|;
block|}
name|COMPUTE_MEMORY_CLOCK_PARAM_PARAMETERS_V2_1
typedef|;
end_typedef

begin_comment
comment|// definition of ucInputFlag
end_comment

begin_define
define|#
directive|define
name|MPLL_INPUT_FLAG_STROBE_MODE_EN
value|0x01
end_define

begin_comment
comment|// definition of ucPllCntlFlag
end_comment

begin_define
define|#
directive|define
name|MPLL_CNTL_FLAG_VCO_MODE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|MPLL_CNTL_FLAG_BYPASS_DQ_PLL
value|0x04
end_define

begin_define
define|#
directive|define
name|MPLL_CNTL_FLAG_QDR_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|MPLL_CNTL_FLAG_AD_HALF_RATE
value|0x10
end_define

begin_comment
comment|//MPLL_CNTL_FLAG_BYPASS_AD_PLL has a wrong name, should be BYPASS_DQ_PLL
end_comment

begin_define
define|#
directive|define
name|MPLL_CNTL_FLAG_BYPASS_AD_PLL
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
name|_DYNAMICE_MEMORY_SETTINGS_PARAMETER
block|{
name|ATOM_COMPUTE_CLOCK_FREQ
name|ulClock
decl_stmt|;
name|ULONG
name|ulReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|DYNAMICE_MEMORY_SETTINGS_PARAMETER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DYNAMICE_ENGINE_SETTINGS_PARAMETER
block|{
name|ATOM_COMPUTE_CLOCK_FREQ
name|ulClock
decl_stmt|;
name|ULONG
name|ulMemoryClock
decl_stmt|;
name|ULONG
name|ulReserved
decl_stmt|;
block|}
name|DYNAMICE_ENGINE_SETTINGS_PARAMETER
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by SetEngineClockTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SET_ENGINE_CLOCK_PARAMETERS
block|{
name|ULONG
name|ulTargetEngineClock
decl_stmt|;
comment|//In 10Khz unit
block|}
name|SET_ENGINE_CLOCK_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SET_ENGINE_CLOCK_PS_ALLOCATION
block|{
name|ULONG
name|ulTargetEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS_PS_ALLOCATION
name|sReserved
decl_stmt|;
block|}
name|SET_ENGINE_CLOCK_PS_ALLOCATION
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by SetMemoryClockTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SET_MEMORY_CLOCK_PARAMETERS
block|{
name|ULONG
name|ulTargetMemoryClock
decl_stmt|;
comment|//In 10Khz unit
block|}
name|SET_MEMORY_CLOCK_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SET_MEMORY_CLOCK_PS_ALLOCATION
block|{
name|ULONG
name|ulTargetMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|COMPUTE_MEMORY_ENGINE_PLL_PARAMETERS_PS_ALLOCATION
name|sReserved
decl_stmt|;
block|}
name|SET_MEMORY_CLOCK_PS_ALLOCATION
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by ASIC_Init.ctb
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ASIC_INIT_PARAMETERS
block|{
name|ULONG
name|ulDefaultEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDefaultMemoryClock
decl_stmt|;
comment|//In 10Khz unit
block|}
name|ASIC_INIT_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ASIC_INIT_PS_ALLOCATION
block|{
name|ASIC_INIT_PARAMETERS
name|sASICInitClocks
decl_stmt|;
name|SET_ENGINE_CLOCK_PS_ALLOCATION
name|sReserved
decl_stmt|;
comment|//Caller doesn't need to init this structure
block|}
name|ASIC_INIT_PS_ALLOCATION
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used by DynamicClockGatingTable.ctb
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DYNAMIC_CLOCK_GATING_PARAMETERS
block|{
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE or ATOM_DISABLE
name|UCHAR
name|ucPadding
index|[
literal|3
index|]
decl_stmt|;
block|}
name|DYNAMIC_CLOCK_GATING_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DYNAMIC_CLOCK_GATING_PS_ALLOCATION
value|DYNAMIC_CLOCK_GATING_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used by EnableDispPowerGatingTable.ctb
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_DISP_POWER_GATING_PARAMETERS_V2_1
block|{
name|UCHAR
name|ucDispPipeId
decl_stmt|;
comment|// ATOM_CRTC1, ATOM_CRTC2, ...
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE or ATOM_DISABLE
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ENABLE_DISP_POWER_GATING_PARAMETERS_V2_1
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used by EnableASIC_StaticPwrMgtTable.ctb
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_ASIC_STATIC_PWR_MGT_PARAMETERS
block|{
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE or ATOM_DISABLE
name|UCHAR
name|ucPadding
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ENABLE_ASIC_STATIC_PWR_MGT_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ENABLE_ASIC_STATIC_PWR_MGT_PS_ALLOCATION
value|ENABLE_ASIC_STATIC_PWR_MGT_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by DAC_LoadDetectionTable.ctb
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DAC_LOAD_DETECTION_PARAMETERS
block|{
name|USHORT
name|usDeviceID
decl_stmt|;
comment|//{ATOM_DEVICE_CRTx_SUPPORT,ATOM_DEVICE_TVx_SUPPORT,ATOM_DEVICE_CVx_SUPPORT}
name|UCHAR
name|ucDacType
decl_stmt|;
comment|//{ATOM_DAC_A,ATOM_DAC_B, ATOM_EXT_DAC}
name|UCHAR
name|ucMisc
decl_stmt|;
comment|//Valid only when table revision =1.3 and above
block|}
name|DAC_LOAD_DETECTION_PARAMETERS
typedef|;
end_typedef

begin_comment
comment|// DAC_LOAD_DETECTION_PARAMETERS.ucMisc
end_comment

begin_define
define|#
directive|define
name|DAC_LOAD_MISC_YPrPb
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_DAC_LOAD_DETECTION_PS_ALLOCATION
block|{
name|DAC_LOAD_DETECTION_PARAMETERS
name|sDacload
decl_stmt|;
name|ULONG
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|// Don't set this one, allocation for EXT DAC
block|}
name|DAC_LOAD_DETECTION_PS_ALLOCATION
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by DAC1EncoderControlTable.ctb and DAC2EncoderControlTable.ctb
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DAC_ENCODER_CONTROL_PARAMETERS
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
name|UCHAR
name|ucDacStandard
decl_stmt|;
comment|// See definition of ATOM_DACx_xxx, For DEC3.0, bit 7 used as internal flag to indicate DAC2 (==1) or DAC1 (==0)
name|UCHAR
name|ucAction
decl_stmt|;
comment|// 0: turn off encoder
comment|// 1: setup and turn on encoder
comment|// 7: ATOM_ENCODER_INIT Initialize DAC
block|}
name|DAC_ENCODER_CONTROL_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DAC_ENCODER_CONTROL_PS_ALLOCATION
value|DAC_ENCODER_CONTROL_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by DIG1EncoderControlTable
end_comment

begin_comment
comment|//                    DIG2EncoderControlTable
end_comment

begin_comment
comment|//                    ExternalEncoderControlTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DIG_ENCODER_CONTROL_PARAMETERS
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
name|UCHAR
name|ucConfig
decl_stmt|;
comment|// [2] Link Select:
comment|// =0: PHY linkA if bfLane<3
comment|// =1: PHY linkB if bfLanes<3
comment|// =0: PHY linkA+B if bfLanes=3
comment|// [3] Transmitter Sel
comment|// =0: UNIPHY or PCIEPHY
comment|// =1: LVTMA
name|UCHAR
name|ucAction
decl_stmt|;
comment|// =0: turn off encoder
comment|// =1: turn on encoder
name|UCHAR
name|ucEncoderMode
decl_stmt|;
comment|// =0: DP   encoder
comment|// =1: LVDS encoder
comment|// =2: DVI  encoder
comment|// =3: HDMI encoder
comment|// =4: SDVO encoder
name|UCHAR
name|ucLaneNum
decl_stmt|;
comment|// how many lanes to enable
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|DIG_ENCODER_CONTROL_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DIG_ENCODER_CONTROL_PS_ALLOCATION
value|DIG_ENCODER_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_CONTROL_PARAMETER
value|DIG_ENCODER_CONTROL_PARAMETERS
end_define

begin_comment
comment|//ucConfig
end_comment

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_DPLINKRATE_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_DPLINKRATE_1_62GHZ
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_DPLINKRATE_2_70GHZ
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_DPLINKRATE_5_40GHZ
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_LINK_SEL_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_LINKA
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_LINKB
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_LINKA_B
value|ATOM_TRANSMITTER_CONFIG_LINKA
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_LINKB_A
value|ATOM_ENCODER_CONFIG_LINKB
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_TRANSMITTER_SEL_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_UNIPHY
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_LVTMA
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_TRANSMITTER1
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_TRANSMITTER2
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_DIGB
value|0x80
end_define

begin_comment
comment|// VBIOS Internal use, outside SW should set this bit=0
end_comment

begin_comment
comment|// ucAction
end_comment

begin_comment
comment|// ATOM_ENABLE:  Enable Encoder
end_comment

begin_comment
comment|// ATOM_DISABLE: Disable Encoder
end_comment

begin_comment
comment|//ucEncoderMode
end_comment

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_DP
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_LVDS
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_DVI
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_HDMI
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_SDVO
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_DP_AUDIO
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_TV
value|13
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_CV
value|14
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_CRT
value|15
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_DVO
value|16
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_DP_SST
value|ATOM_ENCODER_MODE_DP
end_define

begin_comment
comment|// For DP1.2
end_comment

begin_define
define|#
directive|define
name|ATOM_ENCODER_MODE_DP_MST
value|5
end_define

begin_comment
comment|// For DP1.2
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DIG_ENCODER_CONFIG_V2
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|ucReserved1
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucTransmitterSel
range|:
literal|2
decl_stmt|;
comment|// =0: UniphyAB, =1: UniphyCD  =2: UniphyEF
name|UCHAR
name|ucLinkSel
range|:
literal|1
decl_stmt|;
comment|// =0: linkA/C/E =1: linkB/D/F
name|UCHAR
name|ucReserved
range|:
literal|1
decl_stmt|;
name|UCHAR
name|ucDPLinkRate
range|:
literal|1
decl_stmt|;
comment|// =0: 1.62Ghz, =1: 2.7Ghz
else|#
directive|else
name|UCHAR
name|ucDPLinkRate
range|:
literal|1
decl_stmt|;
comment|// =0: 1.62Ghz, =1: 2.7Ghz
name|UCHAR
name|ucReserved
range|:
literal|1
decl_stmt|;
name|UCHAR
name|ucLinkSel
range|:
literal|1
decl_stmt|;
comment|// =0: linkA/C/E =1: linkB/D/F
name|UCHAR
name|ucTransmitterSel
range|:
literal|2
decl_stmt|;
comment|// =0: UniphyAB, =1: UniphyCD  =2: UniphyEF
name|UCHAR
name|ucReserved1
range|:
literal|2
decl_stmt|;
endif|#
directive|endif
block|}
name|ATOM_DIG_ENCODER_CONFIG_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DIG_ENCODER_CONTROL_PARAMETERS_V2
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
name|ATOM_DIG_ENCODER_CONFIG_V2
name|acConfig
decl_stmt|;
name|UCHAR
name|ucAction
decl_stmt|;
name|UCHAR
name|ucEncoderMode
decl_stmt|;
comment|// =0: DP   encoder
comment|// =1: LVDS encoder
comment|// =2: DVI  encoder
comment|// =3: HDMI encoder
comment|// =4: SDVO encoder
name|UCHAR
name|ucLaneNum
decl_stmt|;
comment|// how many lanes to enable
name|UCHAR
name|ucStatus
decl_stmt|;
comment|// = DP_LINK_TRAINING_COMPLETE or DP_LINK_TRAINING_INCOMPLETE, only used by VBIOS with command ATOM_ENCODER_CMD_QUERY_DP_LINK_TRAINING_STATUS
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|DIG_ENCODER_CONTROL_PARAMETERS_V2
typedef|;
end_typedef

begin_comment
comment|//ucConfig
end_comment

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V2_DPLINKRATE_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V2_DPLINKRATE_1_62GHZ
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V2_DPLINKRATE_2_70GHZ
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V2_LINK_SEL_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V2_LINKA
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V2_LINKB
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V2_TRANSMITTER_SEL_MASK
value|0x18
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V2_TRANSMITTER1
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V2_TRANSMITTER2
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V2_TRANSMITTER3
value|0x10
end_define

begin_comment
comment|// ucAction:
end_comment

begin_comment
comment|// ATOM_DISABLE
end_comment

begin_comment
comment|// ATOM_ENABLE
end_comment

begin_define
define|#
directive|define
name|ATOM_ENCODER_CMD_DP_LINK_TRAINING_START
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CMD_DP_LINK_TRAINING_PATTERN1
value|0x09
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CMD_DP_LINK_TRAINING_PATTERN2
value|0x0a
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CMD_DP_LINK_TRAINING_PATTERN3
value|0x13
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CMD_DP_LINK_TRAINING_COMPLETE
value|0x0b
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CMD_DP_VIDEO_OFF
value|0x0c
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CMD_DP_VIDEO_ON
value|0x0d
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CMD_QUERY_DP_LINK_TRAINING_STATUS
value|0x0e
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CMD_SETUP
value|0x0f
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CMD_SETUP_PANEL_MODE
value|0x10
end_define

begin_comment
comment|// ucStatus
end_comment

begin_define
define|#
directive|define
name|ATOM_ENCODER_STATUS_LINK_TRAINING_COMPLETE
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_STATUS_LINK_TRAINING_INCOMPLETE
value|0x00
end_define

begin_comment
comment|//ucTableFormatRevision=1
end_comment

begin_comment
comment|//ucTableContentRevision=3
end_comment

begin_comment
comment|// Following function ENABLE sub-function will be used by driver when TMDS/HDMI/LVDS is used, disable function will be used by driver
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DIG_ENCODER_CONFIG_V3
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|ucReserved1
range|:
literal|1
decl_stmt|;
name|UCHAR
name|ucDigSel
range|:
literal|3
decl_stmt|;
comment|// =0/1/2/3/4/5: DIG0/1/2/3/4/5 (In register spec also referred as DIGA/B/C/D/E/F)
name|UCHAR
name|ucReserved
range|:
literal|3
decl_stmt|;
name|UCHAR
name|ucDPLinkRate
range|:
literal|1
decl_stmt|;
comment|// =0: 1.62Ghz, =1: 2.7Ghz
else|#
directive|else
name|UCHAR
name|ucDPLinkRate
range|:
literal|1
decl_stmt|;
comment|// =0: 1.62Ghz, =1: 2.7Ghz
name|UCHAR
name|ucReserved
range|:
literal|3
decl_stmt|;
name|UCHAR
name|ucDigSel
range|:
literal|3
decl_stmt|;
comment|// =0/1/2/3/4/5: DIG0/1/2/3/4/5 (In register spec also referred as DIGA/B/C/D/E/F)
name|UCHAR
name|ucReserved1
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
name|ATOM_DIG_ENCODER_CONFIG_V3
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V3_DPLINKRATE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V3_DPLINKRATE_1_62GHZ
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V3_DPLINKRATE_2_70GHZ
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V3_ENCODER_SEL
value|0x70
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V3_DIG0_ENCODER
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V3_DIG1_ENCODER
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V3_DIG2_ENCODER
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V3_DIG3_ENCODER
value|0x30
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V3_DIG4_ENCODER
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V3_DIG5_ENCODER
value|0x50
end_define

begin_typedef
typedef|typedef
struct|struct
name|_DIG_ENCODER_CONTROL_PARAMETERS_V3
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
name|ATOM_DIG_ENCODER_CONFIG_V3
name|acConfig
decl_stmt|;
name|UCHAR
name|ucAction
decl_stmt|;
union|union
block|{
name|UCHAR
name|ucEncoderMode
decl_stmt|;
comment|// =0: DP   encoder
comment|// =1: LVDS encoder
comment|// =2: DVI  encoder
comment|// =3: HDMI encoder
comment|// =4: SDVO encoder
comment|// =5: DP audio
name|UCHAR
name|ucPanelMode
decl_stmt|;
comment|// only valid when ucAction == ATOM_ENCODER_CMD_SETUP_PANEL_MODE
comment|// =0:     external DP
comment|// =1:     internal DP2
comment|// =0x11:  internal DP1 for NutMeg/Travis DP translator
block|}
union|;
name|UCHAR
name|ucLaneNum
decl_stmt|;
comment|// how many lanes to enable
name|UCHAR
name|ucBitPerColor
decl_stmt|;
comment|// only valid for DP mode when ucAction = ATOM_ENCODER_CMD_SETUP
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|DIG_ENCODER_CONTROL_PARAMETERS_V3
typedef|;
end_typedef

begin_comment
comment|//ucTableFormatRevision=1
end_comment

begin_comment
comment|//ucTableContentRevision=4
end_comment

begin_comment
comment|// start from NI
end_comment

begin_comment
comment|// Following function ENABLE sub-function will be used by driver when TMDS/HDMI/LVDS is used, disable function will be used by driver
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DIG_ENCODER_CONFIG_V4
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|ucReserved1
range|:
literal|1
decl_stmt|;
name|UCHAR
name|ucDigSel
range|:
literal|3
decl_stmt|;
comment|// =0/1/2/3/4/5: DIG0/1/2/3/4/5 (In register spec also referred as DIGA/B/C/D/E/F)
name|UCHAR
name|ucReserved
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDPLinkRate
range|:
literal|2
decl_stmt|;
comment|// =0: 1.62Ghz, =1: 2.7Ghz, 2=5.4Ghz<= Changed comparing to previous version
else|#
directive|else
name|UCHAR
name|ucDPLinkRate
range|:
literal|2
decl_stmt|;
comment|// =0: 1.62Ghz, =1: 2.7Ghz, 2=5.4Ghz<= Changed comparing to previous version
name|UCHAR
name|ucReserved
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDigSel
range|:
literal|3
decl_stmt|;
comment|// =0/1/2/3/4/5: DIG0/1/2/3/4/5 (In register spec also referred as DIGA/B/C/D/E/F)
name|UCHAR
name|ucReserved1
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
name|ATOM_DIG_ENCODER_CONFIG_V4
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DPLINKRATE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DPLINKRATE_1_62GHZ
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DPLINKRATE_2_70GHZ
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DPLINKRATE_5_40GHZ
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DPLINKRATE_3_24GHZ
value|0x03
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_ENCODER_SEL
value|0x70
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DIG0_ENCODER
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DIG1_ENCODER
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DIG2_ENCODER
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DIG3_ENCODER
value|0x30
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DIG4_ENCODER
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DIG5_ENCODER
value|0x50
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CONFIG_V4_DIG6_ENCODER
value|0x60
end_define

begin_typedef
typedef|typedef
struct|struct
name|_DIG_ENCODER_CONTROL_PARAMETERS_V4
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
union|union
block|{
name|ATOM_DIG_ENCODER_CONFIG_V4
name|acConfig
decl_stmt|;
name|UCHAR
name|ucConfig
decl_stmt|;
block|}
union|;
name|UCHAR
name|ucAction
decl_stmt|;
union|union
block|{
name|UCHAR
name|ucEncoderMode
decl_stmt|;
comment|// =0: DP   encoder
comment|// =1: LVDS encoder
comment|// =2: DVI  encoder
comment|// =3: HDMI encoder
comment|// =4: SDVO encoder
comment|// =5: DP audio
name|UCHAR
name|ucPanelMode
decl_stmt|;
comment|// only valid when ucAction == ATOM_ENCODER_CMD_SETUP_PANEL_MODE
comment|// =0:     external DP
comment|// =1:     internal DP2
comment|// =0x11:  internal DP1 for NutMeg/Travis DP translator
block|}
union|;
name|UCHAR
name|ucLaneNum
decl_stmt|;
comment|// how many lanes to enable
name|UCHAR
name|ucBitPerColor
decl_stmt|;
comment|// only valid for DP mode when ucAction = ATOM_ENCODER_CMD_SETUP
name|UCHAR
name|ucHPD_ID
decl_stmt|;
comment|// HPD ID (1-6). =0 means to skip HDP programming. New comparing to previous version
block|}
name|DIG_ENCODER_CONTROL_PARAMETERS_V4
typedef|;
end_typedef

begin_comment
comment|// define ucBitPerColor:
end_comment

begin_define
define|#
directive|define
name|PANEL_BPC_UNDEFINE
value|0x00
end_define

begin_define
define|#
directive|define
name|PANEL_6BIT_PER_COLOR
value|0x01
end_define

begin_define
define|#
directive|define
name|PANEL_8BIT_PER_COLOR
value|0x02
end_define

begin_define
define|#
directive|define
name|PANEL_10BIT_PER_COLOR
value|0x03
end_define

begin_define
define|#
directive|define
name|PANEL_12BIT_PER_COLOR
value|0x04
end_define

begin_define
define|#
directive|define
name|PANEL_16BIT_PER_COLOR
value|0x05
end_define

begin_comment
comment|//define ucPanelMode
end_comment

begin_define
define|#
directive|define
name|DP_PANEL_MODE_EXTERNAL_DP_MODE
value|0x00
end_define

begin_define
define|#
directive|define
name|DP_PANEL_MODE_INTERNAL_DP2_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|DP_PANEL_MODE_INTERNAL_DP1_MODE
value|0x11
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by UNIPHYTransmitterControlTable
end_comment

begin_comment
comment|//                    LVTMATransmitterControlTable
end_comment

begin_comment
comment|//                    DVOOutputControlTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DP_VS_MODE
block|{
name|UCHAR
name|ucLaneSel
decl_stmt|;
name|UCHAR
name|ucLaneSet
decl_stmt|;
block|}
name|ATOM_DP_VS_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DIG_TRANSMITTER_CONTROL_PARAMETERS
block|{
union|union
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
name|USHORT
name|usInitInfo
decl_stmt|;
comment|// when init uniphy,lower 8bit is used for connector type defined in objectid.h
name|ATOM_DP_VS_MODE
name|asMode
decl_stmt|;
comment|// DP Voltage swing mode
block|}
union|;
name|UCHAR
name|ucConfig
decl_stmt|;
comment|// [0]=0: 4 lane Link,
comment|//    =1: 8 lane Link ( Dual Links TMDS )
comment|// [1]=0: InCoherent mode
comment|//    =1: Coherent Mode
comment|// [2] Link Select:
comment|// =0: PHY linkA   if bfLane<3
comment|// =1: PHY linkB   if bfLanes<3
comment|// =0: PHY linkA+B if bfLanes=3
comment|// [5:4]PCIE lane Sel
comment|// =0: lane 0~3 or 0~7
comment|// =1: lane 4~7
comment|// =2: lane 8~11 or 8~15
comment|// =3: lane 12~15
name|UCHAR
name|ucAction
decl_stmt|;
comment|// =0: turn off encoder
comment|// =1: turn on encoder
name|UCHAR
name|ucReserved
index|[
literal|4
index|]
decl_stmt|;
block|}
name|DIG_TRANSMITTER_CONTROL_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DIG_TRANSMITTER_CONTROL_PS_ALLOCATION
value|DIG_TRANSMITTER_CONTROL_PARAMETERS
end_define

begin_comment
comment|//ucInitInfo
end_comment

begin_define
define|#
directive|define
name|ATOM_TRAMITTER_INITINFO_CONNECTOR_MASK
value|0x00ff
end_define

begin_comment
comment|//ucConfig
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_8LANE_LINK
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_COHERENT
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LINK_SEL_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LINKA
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LINKB
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LINKA_B
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LINKB_A
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_ENCODER_SEL_MASK
value|0x08
end_define

begin_comment
comment|// only used when ATOM_TRANSMITTER_ACTION_ENABLE
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_DIG1_ENCODER
value|0x00
end_define

begin_comment
comment|// only used when ATOM_TRANSMITTER_ACTION_ENABLE
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_DIG2_ENCODER
value|0x08
end_define

begin_comment
comment|// only used when ATOM_TRANSMITTER_ACTION_ENABLE
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_CLKSRC_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_CLKSRC_PPLL
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_CLKSRC_PCIE
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_CLKSRC_XTALIN
value|0x30
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LANE_SEL_MASK
value|0xc0
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LANE_0_3
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LANE_0_7
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LANE_4_7
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LANE_8_11
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LANE_8_15
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_LANE_12_15
value|0xc0
end_define

begin_comment
comment|//ucAction
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_LCD_BLOFF
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_LCD_BLON
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_BL_BRIGHTNESS_CONTROL
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_LCD_SELFTEST_START
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_LCD_SELFTEST_STOP
value|6
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_INIT
value|7
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_DISABLE_OUTPUT
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_ENABLE_OUTPUT
value|9
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_SETUP
value|10
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_SETUP_VSEMPH
value|11
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_POWER_ON
value|12
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_ACTION_POWER_OFF
value|13
end_define

begin_comment
comment|// Following are used for DigTransmitterControlTable ver1.2
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DIG_TRANSMITTER_CONFIG_V2
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|ucTransmitterSel
range|:
literal|2
decl_stmt|;
comment|//bit7:6: =0 Dig Transmitter 1 ( Uniphy AB )
comment|//        =1 Dig Transmitter 2 ( Uniphy CD )
comment|//        =2 Dig Transmitter 3 ( Uniphy EF )
name|UCHAR
name|ucReserved
range|:
literal|1
decl_stmt|;
name|UCHAR
name|fDPConnector
range|:
literal|1
decl_stmt|;
comment|//bit4=0: DP connector  =1: None DP connector
name|UCHAR
name|ucEncoderSel
range|:
literal|1
decl_stmt|;
comment|//bit3=0: Data/Clk path source from DIGA( DIG inst0 ). =1: Data/clk path source from DIGB ( DIG inst1 )
name|UCHAR
name|ucLinkSel
range|:
literal|1
decl_stmt|;
comment|//bit2=0: Uniphy LINKA or C or E when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is A or C or E
comment|//    =1: Uniphy LINKB or D or F when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is B or D or F
name|UCHAR
name|fCoherentMode
range|:
literal|1
decl_stmt|;
comment|//bit1=1: Coherent Mode ( for DVI/HDMI mode )
name|UCHAR
name|fDualLinkConnector
range|:
literal|1
decl_stmt|;
comment|//bit0=1: Dual Link DVI connector
else|#
directive|else
name|UCHAR
name|fDualLinkConnector
range|:
literal|1
decl_stmt|;
comment|//bit0=1: Dual Link DVI connector
name|UCHAR
name|fCoherentMode
range|:
literal|1
decl_stmt|;
comment|//bit1=1: Coherent Mode ( for DVI/HDMI mode )
name|UCHAR
name|ucLinkSel
range|:
literal|1
decl_stmt|;
comment|//bit2=0: Uniphy LINKA or C or E when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is A or C or E
comment|//    =1: Uniphy LINKB or D or F when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is B or D or F
name|UCHAR
name|ucEncoderSel
range|:
literal|1
decl_stmt|;
comment|//bit3=0: Data/Clk path source from DIGA( DIG inst0 ). =1: Data/clk path source from DIGB ( DIG inst1 )
name|UCHAR
name|fDPConnector
range|:
literal|1
decl_stmt|;
comment|//bit4=0: DP connector  =1: None DP connector
name|UCHAR
name|ucReserved
range|:
literal|1
decl_stmt|;
name|UCHAR
name|ucTransmitterSel
range|:
literal|2
decl_stmt|;
comment|//bit7:6: =0 Dig Transmitter 1 ( Uniphy AB )
comment|//        =1 Dig Transmitter 2 ( Uniphy CD )
comment|//        =2 Dig Transmitter 3 ( Uniphy EF )
endif|#
directive|endif
block|}
name|ATOM_DIG_TRANSMITTER_CONFIG_V2
typedef|;
end_typedef

begin_comment
comment|//ucConfig
end_comment

begin_comment
comment|//Bit0
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_DUAL_LINK_CONNECTOR
value|0x01
end_define

begin_comment
comment|//Bit1
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_COHERENT
value|0x02
end_define

begin_comment
comment|//Bit2
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_LINK_SEL_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_LINKA
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_LINKB
value|0x04
end_define

begin_comment
comment|// Bit3
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_ENCODER_SEL_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_DIG1_ENCODER
value|0x00
end_define

begin_comment
comment|// only used when ucAction == ATOM_TRANSMITTER_ACTION_ENABLE or ATOM_TRANSMITTER_ACTION_SETUP
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_DIG2_ENCODER
value|0x08
end_define

begin_comment
comment|// only used when ucAction == ATOM_TRANSMITTER_ACTION_ENABLE or ATOM_TRANSMITTER_ACTION_SETUP
end_comment

begin_comment
comment|// Bit4
end_comment

begin_define
define|#
directive|define
name|ATOM_TRASMITTER_CONFIG_V2_DP_CONNECTOR
value|0x10
end_define

begin_comment
comment|// Bit7:6
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_TRANSMITTER_SEL_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_TRANSMITTER1
value|0x00
end_define

begin_comment
comment|//AB
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_TRANSMITTER2
value|0x40
end_define

begin_comment
comment|//CD
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V2_TRANSMITTER3
value|0x80
end_define

begin_comment
comment|//EF
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DIG_TRANSMITTER_CONTROL_PARAMETERS_V2
block|{
union|union
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
name|USHORT
name|usInitInfo
decl_stmt|;
comment|// when init uniphy,lower 8bit is used for connector type defined in objectid.h
name|ATOM_DP_VS_MODE
name|asMode
decl_stmt|;
comment|// DP Voltage swing mode
block|}
union|;
name|ATOM_DIG_TRANSMITTER_CONFIG_V2
name|acConfig
decl_stmt|;
name|UCHAR
name|ucAction
decl_stmt|;
comment|// define as ATOM_TRANSMITER_ACTION_XXX
name|UCHAR
name|ucReserved
index|[
literal|4
index|]
decl_stmt|;
block|}
name|DIG_TRANSMITTER_CONTROL_PARAMETERS_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DIG_TRANSMITTER_CONFIG_V3
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|ucTransmitterSel
range|:
literal|2
decl_stmt|;
comment|//bit7:6: =0 Dig Transmitter 1 ( Uniphy AB )
comment|//        =1 Dig Transmitter 2 ( Uniphy CD )
comment|//        =2 Dig Transmitter 3 ( Uniphy EF )
name|UCHAR
name|ucRefClkSource
range|:
literal|2
decl_stmt|;
comment|//bit5:4: PPLL1 =0, PPLL2=1, EXT_CLK=2
name|UCHAR
name|ucEncoderSel
range|:
literal|1
decl_stmt|;
comment|//bit3=0: Data/Clk path source from DIGA/C/E. =1: Data/clk path source from DIGB/D/F
name|UCHAR
name|ucLinkSel
range|:
literal|1
decl_stmt|;
comment|//bit2=0: Uniphy LINKA or C or E when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is A or C or E
comment|//    =1: Uniphy LINKB or D or F when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is B or D or F
name|UCHAR
name|fCoherentMode
range|:
literal|1
decl_stmt|;
comment|//bit1=1: Coherent Mode ( for DVI/HDMI mode )
name|UCHAR
name|fDualLinkConnector
range|:
literal|1
decl_stmt|;
comment|//bit0=1: Dual Link DVI connector
else|#
directive|else
name|UCHAR
name|fDualLinkConnector
range|:
literal|1
decl_stmt|;
comment|//bit0=1: Dual Link DVI connector
name|UCHAR
name|fCoherentMode
range|:
literal|1
decl_stmt|;
comment|//bit1=1: Coherent Mode ( for DVI/HDMI mode )
name|UCHAR
name|ucLinkSel
range|:
literal|1
decl_stmt|;
comment|//bit2=0: Uniphy LINKA or C or E when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is A or C or E
comment|//    =1: Uniphy LINKB or D or F when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is B or D or F
name|UCHAR
name|ucEncoderSel
range|:
literal|1
decl_stmt|;
comment|//bit3=0: Data/Clk path source from DIGA/C/E. =1: Data/clk path source from DIGB/D/F
name|UCHAR
name|ucRefClkSource
range|:
literal|2
decl_stmt|;
comment|//bit5:4: PPLL1 =0, PPLL2=1, EXT_CLK=2
name|UCHAR
name|ucTransmitterSel
range|:
literal|2
decl_stmt|;
comment|//bit7:6: =0 Dig Transmitter 1 ( Uniphy AB )
comment|//        =1 Dig Transmitter 2 ( Uniphy CD )
comment|//        =2 Dig Transmitter 3 ( Uniphy EF )
endif|#
directive|endif
block|}
name|ATOM_DIG_TRANSMITTER_CONFIG_V3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DIG_TRANSMITTER_CONTROL_PARAMETERS_V3
block|{
union|union
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
name|USHORT
name|usInitInfo
decl_stmt|;
comment|// when init uniphy,lower 8bit is used for connector type defined in objectid.h
name|ATOM_DP_VS_MODE
name|asMode
decl_stmt|;
comment|// DP Voltage swing mode
block|}
union|;
name|ATOM_DIG_TRANSMITTER_CONFIG_V3
name|acConfig
decl_stmt|;
name|UCHAR
name|ucAction
decl_stmt|;
comment|// define as ATOM_TRANSMITER_ACTION_XXX
name|UCHAR
name|ucLaneNum
decl_stmt|;
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|DIG_TRANSMITTER_CONTROL_PARAMETERS_V3
typedef|;
end_typedef

begin_comment
comment|//ucConfig
end_comment

begin_comment
comment|//Bit0
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_DUAL_LINK_CONNECTOR
value|0x01
end_define

begin_comment
comment|//Bit1
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_COHERENT
value|0x02
end_define

begin_comment
comment|//Bit2
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_LINK_SEL_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_LINKA
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_LINKB
value|0x04
end_define

begin_comment
comment|// Bit3
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_ENCODER_SEL_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_DIG1_ENCODER
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_DIG2_ENCODER
value|0x08
end_define

begin_comment
comment|// Bit5:4
end_comment

begin_define
define|#
directive|define
name|ATOM_TRASMITTER_CONFIG_V3_REFCLK_SEL_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|ATOM_TRASMITTER_CONFIG_V3_P1PLL
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRASMITTER_CONFIG_V3_P2PLL
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_TRASMITTER_CONFIG_V3_REFCLK_SRC_EXT
value|0x20
end_define

begin_comment
comment|// Bit7:6
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_TRANSMITTER_SEL_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_TRANSMITTER1
value|0x00
end_define

begin_comment
comment|//AB
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_TRANSMITTER2
value|0x40
end_define

begin_comment
comment|//CD
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V3_TRANSMITTER3
value|0x80
end_define

begin_comment
comment|//EF
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by UNIPHYTransmitterControlTable V1.4
end_comment

begin_comment
comment|// ASIC Families: NI
end_comment

begin_comment
comment|// ucTableFormatRevision=1
end_comment

begin_comment
comment|// ucTableContentRevision=4
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DP_VS_MODE_V4
block|{
name|UCHAR
name|ucLaneSel
decl_stmt|;
union|union
block|{
name|UCHAR
name|ucLaneSet
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|ucPOST_CURSOR2
range|:
literal|2
decl_stmt|;
comment|//Bit[7:6] Post Cursor2 Level<= New in V4
name|UCHAR
name|ucPRE_EMPHASIS
range|:
literal|3
decl_stmt|;
comment|//Bit[5:3] Pre-emphasis Level
name|UCHAR
name|ucVOLTAGE_SWING
range|:
literal|3
decl_stmt|;
comment|//Bit[2:0] Voltage Swing Level
else|#
directive|else
name|UCHAR
name|ucVOLTAGE_SWING
range|:
literal|3
decl_stmt|;
comment|//Bit[2:0] Voltage Swing Level
name|UCHAR
name|ucPRE_EMPHASIS
range|:
literal|3
decl_stmt|;
comment|//Bit[5:3] Pre-emphasis Level
name|UCHAR
name|ucPOST_CURSOR2
range|:
literal|2
decl_stmt|;
comment|//Bit[7:6] Post Cursor2 Level<= New in V4
endif|#
directive|endif
block|}
struct|;
block|}
union|;
block|}
name|ATOM_DP_VS_MODE_V4
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DIG_TRANSMITTER_CONFIG_V4
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|ucTransmitterSel
range|:
literal|2
decl_stmt|;
comment|//bit7:6: =0 Dig Transmitter 1 ( Uniphy AB )
comment|//        =1 Dig Transmitter 2 ( Uniphy CD )
comment|//        =2 Dig Transmitter 3 ( Uniphy EF )
name|UCHAR
name|ucRefClkSource
range|:
literal|2
decl_stmt|;
comment|//bit5:4: PPLL1 =0, PPLL2=1, DCPLL=2, EXT_CLK=3<= New
name|UCHAR
name|ucEncoderSel
range|:
literal|1
decl_stmt|;
comment|//bit3=0: Data/Clk path source from DIGA/C/E. =1: Data/clk path source from DIGB/D/F
name|UCHAR
name|ucLinkSel
range|:
literal|1
decl_stmt|;
comment|//bit2=0: Uniphy LINKA or C or E when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is A or C or E
comment|//    =1: Uniphy LINKB or D or F when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is B or D or F
name|UCHAR
name|fCoherentMode
range|:
literal|1
decl_stmt|;
comment|//bit1=1: Coherent Mode ( for DVI/HDMI mode )
name|UCHAR
name|fDualLinkConnector
range|:
literal|1
decl_stmt|;
comment|//bit0=1: Dual Link DVI connector
else|#
directive|else
name|UCHAR
name|fDualLinkConnector
range|:
literal|1
decl_stmt|;
comment|//bit0=1: Dual Link DVI connector
name|UCHAR
name|fCoherentMode
range|:
literal|1
decl_stmt|;
comment|//bit1=1: Coherent Mode ( for DVI/HDMI mode )
name|UCHAR
name|ucLinkSel
range|:
literal|1
decl_stmt|;
comment|//bit2=0: Uniphy LINKA or C or E when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is A or C or E
comment|//    =1: Uniphy LINKB or D or F when fDualLinkConnector=0. when fDualLinkConnector=1, it means master link of dual link is B or D or F
name|UCHAR
name|ucEncoderSel
range|:
literal|1
decl_stmt|;
comment|//bit3=0: Data/Clk path source from DIGA/C/E. =1: Data/clk path source from DIGB/D/F
name|UCHAR
name|ucRefClkSource
range|:
literal|2
decl_stmt|;
comment|//bit5:4: PPLL1 =0, PPLL2=1, DCPLL=2, EXT_CLK=3<= New
name|UCHAR
name|ucTransmitterSel
range|:
literal|2
decl_stmt|;
comment|//bit7:6: =0 Dig Transmitter 1 ( Uniphy AB )
comment|//        =1 Dig Transmitter 2 ( Uniphy CD )
comment|//        =2 Dig Transmitter 3 ( Uniphy EF )
endif|#
directive|endif
block|}
name|ATOM_DIG_TRANSMITTER_CONFIG_V4
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DIG_TRANSMITTER_CONTROL_PARAMETERS_V4
block|{
union|union
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
name|USHORT
name|usInitInfo
decl_stmt|;
comment|// when init uniphy,lower 8bit is used for connector type defined in objectid.h
name|ATOM_DP_VS_MODE_V4
name|asMode
decl_stmt|;
comment|// DP Voltage swing mode     Redefined comparing to previous version
block|}
union|;
union|union
block|{
name|ATOM_DIG_TRANSMITTER_CONFIG_V4
name|acConfig
decl_stmt|;
name|UCHAR
name|ucConfig
decl_stmt|;
block|}
union|;
name|UCHAR
name|ucAction
decl_stmt|;
comment|// define as ATOM_TRANSMITER_ACTION_XXX
name|UCHAR
name|ucLaneNum
decl_stmt|;
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|DIG_TRANSMITTER_CONTROL_PARAMETERS_V4
typedef|;
end_typedef

begin_comment
comment|//ucConfig
end_comment

begin_comment
comment|//Bit0
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_DUAL_LINK_CONNECTOR
value|0x01
end_define

begin_comment
comment|//Bit1
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_COHERENT
value|0x02
end_define

begin_comment
comment|//Bit2
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_LINK_SEL_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_LINKA
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_LINKB
value|0x04
end_define

begin_comment
comment|// Bit3
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_ENCODER_SEL_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_DIG1_ENCODER
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_DIG2_ENCODER
value|0x08
end_define

begin_comment
comment|// Bit5:4
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_REFCLK_SEL_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_P1PLL
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_P2PLL
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_DCPLL
value|0x20
end_define

begin_comment
comment|// New in _V4
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_REFCLK_SRC_EXT
value|0x30
end_define

begin_comment
comment|// Changed comparing to V3
end_comment

begin_comment
comment|// Bit7:6
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_TRANSMITTER_SEL_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_TRANSMITTER1
value|0x00
end_define

begin_comment
comment|//AB
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_TRANSMITTER2
value|0x40
end_define

begin_comment
comment|//CD
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V4_TRANSMITTER3
value|0x80
end_define

begin_comment
comment|//EF
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DIG_TRANSMITTER_CONFIG_V5
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|ucReservd1
range|:
literal|1
decl_stmt|;
name|UCHAR
name|ucHPDSel
range|:
literal|3
decl_stmt|;
name|UCHAR
name|ucPhyClkSrcId
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucCoherentMode
range|:
literal|1
decl_stmt|;
name|UCHAR
name|ucReserved
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|UCHAR
name|ucReserved
range|:
literal|1
decl_stmt|;
name|UCHAR
name|ucCoherentMode
range|:
literal|1
decl_stmt|;
name|UCHAR
name|ucPhyClkSrcId
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucHPDSel
range|:
literal|3
decl_stmt|;
name|UCHAR
name|ucReservd1
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
name|ATOM_DIG_TRANSMITTER_CONFIG_V5
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DIG_TRANSMITTER_CONTROL_PARAMETERS_V1_5
block|{
name|USHORT
name|usSymClock
decl_stmt|;
comment|// Encoder Clock in 10kHz,(DP mode)= linkclock/10, (TMDS/LVDS/HDMI)= pixel clock,  (HDMI deep color), =pixel clock * deep_color_ratio
name|UCHAR
name|ucPhyId
decl_stmt|;
comment|// 0=UNIPHYA, 1=UNIPHYB, 2=UNIPHYC, 3=UNIPHYD, 4= UNIPHYE 5=UNIPHYF
name|UCHAR
name|ucAction
decl_stmt|;
comment|// define as ATOM_TRANSMITER_ACTION_xxx
name|UCHAR
name|ucLaneNum
decl_stmt|;
comment|// indicate lane number 1-8
name|UCHAR
name|ucConnObjId
decl_stmt|;
comment|// Connector Object Id defined in ObjectId.h
name|UCHAR
name|ucDigMode
decl_stmt|;
comment|// indicate DIG mode
union|union
block|{
name|ATOM_DIG_TRANSMITTER_CONFIG_V5
name|asConfig
decl_stmt|;
name|UCHAR
name|ucConfig
decl_stmt|;
block|}
union|;
name|UCHAR
name|ucDigEncoderSel
decl_stmt|;
comment|// indicate DIG front end encoder
name|UCHAR
name|ucDPLaneSet
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
name|UCHAR
name|ucReserved1
decl_stmt|;
block|}
name|DIG_TRANSMITTER_CONTROL_PARAMETERS_V1_5
typedef|;
end_typedef

begin_comment
comment|//ucPhyId
end_comment

begin_define
define|#
directive|define
name|ATOM_PHY_ID_UNIPHYA
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_PHY_ID_UNIPHYB
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_PHY_ID_UNIPHYC
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_PHY_ID_UNIPHYD
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_PHY_ID_UNIPHYE
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_PHY_ID_UNIPHYF
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_PHY_ID_UNIPHYG
value|6
end_define

begin_comment
comment|// ucDigEncoderSel
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANMSITTER_V5__DIGA_SEL
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_TRANMSITTER_V5__DIGB_SEL
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_TRANMSITTER_V5__DIGC_SEL
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_TRANMSITTER_V5__DIGD_SEL
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_TRANMSITTER_V5__DIGE_SEL
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_TRANMSITTER_V5__DIGF_SEL
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_TRANMSITTER_V5__DIGG_SEL
value|0x40
end_define

begin_comment
comment|// ucDigMode
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_DIGMODE_V5_DP
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_DIGMODE_V5_LVDS
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_DIGMODE_V5_DVI
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_DIGMODE_V5_HDMI
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_DIGMODE_V5_SDVO
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_DIGMODE_V5_DP_MST
value|5
end_define

begin_comment
comment|// ucDPLaneSet
end_comment

begin_define
define|#
directive|define
name|DP_LANE_SET__0DB_0_4V
value|0x00
end_define

begin_define
define|#
directive|define
name|DP_LANE_SET__0DB_0_6V
value|0x01
end_define

begin_define
define|#
directive|define
name|DP_LANE_SET__0DB_0_8V
value|0x02
end_define

begin_define
define|#
directive|define
name|DP_LANE_SET__0DB_1_2V
value|0x03
end_define

begin_define
define|#
directive|define
name|DP_LANE_SET__3_5DB_0_4V
value|0x08
end_define

begin_define
define|#
directive|define
name|DP_LANE_SET__3_5DB_0_6V
value|0x09
end_define

begin_define
define|#
directive|define
name|DP_LANE_SET__3_5DB_0_8V
value|0x0a
end_define

begin_define
define|#
directive|define
name|DP_LANE_SET__6DB_0_4V
value|0x10
end_define

begin_define
define|#
directive|define
name|DP_LANE_SET__6DB_0_6V
value|0x11
end_define

begin_define
define|#
directive|define
name|DP_LANE_SET__9_5DB_0_4V
value|0x18
end_define

begin_comment
comment|// ATOM_DIG_TRANSMITTER_CONFIG_V5 asConfig;
end_comment

begin_comment
comment|// Bit1
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_COHERENT
value|0x02
end_define

begin_comment
comment|// Bit3:2
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_REFCLK_SEL_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_REFCLK_SEL_SHIFT
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_P1PLL
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_P2PLL
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_P0PLL
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_REFCLK_SRC_EXT
value|0x0c
end_define

begin_comment
comment|// Bit6:4
end_comment

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_HPD_SEL_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_HPD_SEL_SHIFT
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_NO_HPD_SEL
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_HPD1_SEL
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_HPD2_SEL
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_HPD3_SEL
value|0x30
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_HPD4_SEL
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_HPD5_SEL
value|0x50
end_define

begin_define
define|#
directive|define
name|ATOM_TRANSMITTER_CONFIG_V5_HPD6_SEL
value|0x60
end_define

begin_define
define|#
directive|define
name|DIG_TRANSMITTER_CONTROL_PS_ALLOCATION_V1_5
value|DIG_TRANSMITTER_CONTROL_PARAMETERS_V1_5
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by ExternalEncoderControlTable V1.3
end_comment

begin_comment
comment|// ASIC Families: Evergreen, Llano, NI
end_comment

begin_comment
comment|// ucTableFormatRevision=1
end_comment

begin_comment
comment|// ucTableContentRevision=3
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EXTERNAL_ENCODER_CONTROL_PARAMETERS_V3
block|{
union|union
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// pixel clock in 10Khz, valid when ucAction=SETUP/ENABLE_OUTPUT
name|USHORT
name|usConnectorId
decl_stmt|;
comment|// connector id, valid when ucAction = INIT
block|}
union|;
name|UCHAR
name|ucConfig
decl_stmt|;
comment|// indicate which encoder, and DP link rate when ucAction = SETUP/ENABLE_OUTPUT
name|UCHAR
name|ucAction
decl_stmt|;
comment|//
name|UCHAR
name|ucEncoderMode
decl_stmt|;
comment|// encoder mode, only used when ucAction = SETUP/ENABLE_OUTPUT
name|UCHAR
name|ucLaneNum
decl_stmt|;
comment|// lane number, only used when ucAction = SETUP/ENABLE_OUTPUT
name|UCHAR
name|ucBitPerColor
decl_stmt|;
comment|// output bit per color, only valid when ucAction = SETUP/ENABLE_OUTPUT and ucEncodeMode= DP
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|EXTERNAL_ENCODER_CONTROL_PARAMETERS_V3
typedef|;
end_typedef

begin_comment
comment|// ucAction
end_comment

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_ACTION_V3_DISABLE_OUTPUT
value|0x00
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_ACTION_V3_ENABLE_OUTPUT
value|0x01
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_ACTION_V3_ENCODER_INIT
value|0x07
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_ACTION_V3_ENCODER_SETUP
value|0x0f
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_ACTION_V3_ENCODER_BLANKING_OFF
value|0x10
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_ACTION_V3_ENCODER_BLANKING
value|0x11
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_ACTION_V3_DACLOAD_DETECTION
value|0x12
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_ACTION_V3_DDC_SETUP
value|0x14
end_define

begin_comment
comment|// ucConfig
end_comment

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_CONFIG_V3_DPLINKRATE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_CONFIG_V3_DPLINKRATE_1_62GHZ
value|0x00
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_CONFIG_V3_DPLINKRATE_2_70GHZ
value|0x01
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_CONFIG_V3_DPLINKRATE_5_40GHZ
value|0x02
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_CONFIG_V3_ENCODER_SEL_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_CONFIG_V3_ENCODER1
value|0x00
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_CONFIG_V3_ENCODER2
value|0x10
end_define

begin_define
define|#
directive|define
name|EXTERNAL_ENCODER_CONFIG_V3_ENCODER3
value|0x20
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EXTERNAL_ENCODER_CONTROL_PS_ALLOCATION_V3
block|{
name|EXTERNAL_ENCODER_CONTROL_PARAMETERS_V3
name|sExtEncoder
decl_stmt|;
name|ULONG
name|ulReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|EXTERNAL_ENCODER_CONTROL_PS_ALLOCATION_V3
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by DAC1OuputControlTable
end_comment

begin_comment
comment|//                    DAC2OuputControlTable
end_comment

begin_comment
comment|//                    LVTMAOutputControlTable  (Before DEC30)
end_comment

begin_comment
comment|//                    TMDSAOutputControlTable  (Before DEC30)
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DISPLAY_DEVICE_OUTPUT_CONTROL_PARAMETERS
block|{
name|UCHAR
name|ucAction
decl_stmt|;
comment|// Possible input:ATOM_ENABLE||ATOMDISABLE
comment|// When the display is LCD, in addition to above:
comment|// ATOM_LCD_BLOFF|| ATOM_LCD_BLON ||ATOM_LCD_BL_BRIGHTNESS_CONTROL||ATOM_LCD_SELFTEST_START||
comment|// ATOM_LCD_SELFTEST_STOP
name|UCHAR
name|aucPadding
index|[
literal|3
index|]
decl_stmt|;
comment|// padding to DWORD aligned
block|}
name|DISPLAY_DEVICE_OUTPUT_CONTROL_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DISPLAY_DEVICE_OUTPUT_CONTROL_PS_ALLOCATION
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|CRT1_OUTPUT_CONTROL_PARAMETERS
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|CRT1_OUTPUT_CONTROL_PS_ALLOCATION
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PS_ALLOCATION
end_define

begin_define
define|#
directive|define
name|CRT2_OUTPUT_CONTROL_PARAMETERS
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|CRT2_OUTPUT_CONTROL_PS_ALLOCATION
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PS_ALLOCATION
end_define

begin_define
define|#
directive|define
name|CV1_OUTPUT_CONTROL_PARAMETERS
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|CV1_OUTPUT_CONTROL_PS_ALLOCATION
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PS_ALLOCATION
end_define

begin_define
define|#
directive|define
name|TV1_OUTPUT_CONTROL_PARAMETERS
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|TV1_OUTPUT_CONTROL_PS_ALLOCATION
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PS_ALLOCATION
end_define

begin_define
define|#
directive|define
name|DFP1_OUTPUT_CONTROL_PARAMETERS
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|DFP1_OUTPUT_CONTROL_PS_ALLOCATION
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PS_ALLOCATION
end_define

begin_define
define|#
directive|define
name|DFP2_OUTPUT_CONTROL_PARAMETERS
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|DFP2_OUTPUT_CONTROL_PS_ALLOCATION
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PS_ALLOCATION
end_define

begin_define
define|#
directive|define
name|LCD1_OUTPUT_CONTROL_PARAMETERS
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|LCD1_OUTPUT_CONTROL_PS_ALLOCATION
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PS_ALLOCATION
end_define

begin_define
define|#
directive|define
name|DVO_OUTPUT_CONTROL_PARAMETERS
value|DISPLAY_DEVICE_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|DVO_OUTPUT_CONTROL_PS_ALLOCATION
value|DIG_TRANSMITTER_CONTROL_PS_ALLOCATION
end_define

begin_define
define|#
directive|define
name|DVO_OUTPUT_CONTROL_PARAMETERS_V3
value|DIG_TRANSMITTER_CONTROL_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by BlankCRTCTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_BLANK_CRTC_PARAMETERS
block|{
name|UCHAR
name|ucCRTC
decl_stmt|;
comment|// ATOM_CRTC1 or ATOM_CRTC2
name|UCHAR
name|ucBlanking
decl_stmt|;
comment|// ATOM_BLANKING or ATOM_BLANKINGOFF
name|USHORT
name|usBlackColorRCr
decl_stmt|;
name|USHORT
name|usBlackColorGY
decl_stmt|;
name|USHORT
name|usBlackColorBCb
decl_stmt|;
block|}
name|BLANK_CRTC_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BLANK_CRTC_PS_ALLOCATION
value|BLANK_CRTC_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by EnableCRTCTable
end_comment

begin_comment
comment|//                    EnableCRTCMemReqTable
end_comment

begin_comment
comment|//                    UpdateCRTC_DoubleBufferRegistersTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_CRTC_PARAMETERS
block|{
name|UCHAR
name|ucCRTC
decl_stmt|;
comment|// ATOM_CRTC1 or ATOM_CRTC2
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE or ATOM_DISABLE
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ENABLE_CRTC_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ENABLE_CRTC_PS_ALLOCATION
value|ENABLE_CRTC_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by SetCRTC_OverScanTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SET_CRTC_OVERSCAN_PARAMETERS
block|{
name|USHORT
name|usOverscanRight
decl_stmt|;
comment|// right
name|USHORT
name|usOverscanLeft
decl_stmt|;
comment|// left
name|USHORT
name|usOverscanBottom
decl_stmt|;
comment|// bottom
name|USHORT
name|usOverscanTop
decl_stmt|;
comment|// top
name|UCHAR
name|ucCRTC
decl_stmt|;
comment|// ATOM_CRTC1 or ATOM_CRTC2
name|UCHAR
name|ucPadding
index|[
literal|3
index|]
decl_stmt|;
block|}
name|SET_CRTC_OVERSCAN_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SET_CRTC_OVERSCAN_PS_ALLOCATION
value|SET_CRTC_OVERSCAN_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by SetCRTC_ReplicationTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SET_CRTC_REPLICATION_PARAMETERS
block|{
name|UCHAR
name|ucH_Replication
decl_stmt|;
comment|// horizontal replication
name|UCHAR
name|ucV_Replication
decl_stmt|;
comment|// vertical replication
name|UCHAR
name|usCRTC
decl_stmt|;
comment|// ATOM_CRTC1 or ATOM_CRTC2
name|UCHAR
name|ucPadding
decl_stmt|;
block|}
name|SET_CRTC_REPLICATION_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SET_CRTC_REPLICATION_PS_ALLOCATION
value|SET_CRTC_REPLICATION_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by SelectCRTC_SourceTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SELECT_CRTC_SOURCE_PARAMETERS
block|{
name|UCHAR
name|ucCRTC
decl_stmt|;
comment|// ATOM_CRTC1 or ATOM_CRTC2
name|UCHAR
name|ucDevice
decl_stmt|;
comment|// ATOM_DEVICE_CRT1|ATOM_DEVICE_CRT2|....
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
block|}
name|SELECT_CRTC_SOURCE_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SELECT_CRTC_SOURCE_PS_ALLOCATION
value|SELECT_CRTC_SOURCE_PARAMETERS
end_define

begin_typedef
typedef|typedef
struct|struct
name|_SELECT_CRTC_SOURCE_PARAMETERS_V2
block|{
name|UCHAR
name|ucCRTC
decl_stmt|;
comment|// ATOM_CRTC1 or ATOM_CRTC2
name|UCHAR
name|ucEncoderID
decl_stmt|;
comment|// DAC1/DAC2/TVOUT/DIG1/DIG2/DVO
name|UCHAR
name|ucEncodeMode
decl_stmt|;
comment|// Encoding mode, only valid when using DIG1/DIG2/DVO
name|UCHAR
name|ucPadding
decl_stmt|;
block|}
name|SELECT_CRTC_SOURCE_PARAMETERS_V2
typedef|;
end_typedef

begin_comment
comment|//ucEncoderID
end_comment

begin_comment
comment|//#define ASIC_INT_DAC1_ENCODER_ID    						0x00
end_comment

begin_comment
comment|//#define ASIC_INT_TV_ENCODER_ID									0x02
end_comment

begin_comment
comment|//#define ASIC_INT_DIG1_ENCODER_ID								0x03
end_comment

begin_comment
comment|//#define ASIC_INT_DAC2_ENCODER_ID								0x04
end_comment

begin_comment
comment|//#define ASIC_EXT_TV_ENCODER_ID									0x06
end_comment

begin_comment
comment|//#define ASIC_INT_DVO_ENCODER_ID									0x07
end_comment

begin_comment
comment|//#define ASIC_INT_DIG2_ENCODER_ID								0x09
end_comment

begin_comment
comment|//#define ASIC_EXT_DIG_ENCODER_ID									0x05
end_comment

begin_comment
comment|//ucEncodeMode
end_comment

begin_comment
comment|//#define ATOM_ENCODER_MODE_DP										0
end_comment

begin_comment
comment|//#define ATOM_ENCODER_MODE_LVDS									1
end_comment

begin_comment
comment|//#define ATOM_ENCODER_MODE_DVI										2
end_comment

begin_comment
comment|//#define ATOM_ENCODER_MODE_HDMI									3
end_comment

begin_comment
comment|//#define ATOM_ENCODER_MODE_SDVO									4
end_comment

begin_comment
comment|//#define ATOM_ENCODER_MODE_TV										13
end_comment

begin_comment
comment|//#define ATOM_ENCODER_MODE_CV										14
end_comment

begin_comment
comment|//#define ATOM_ENCODER_MODE_CRT										15
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by SetPixelClockTable
end_comment

begin_comment
comment|//                    GetPixelClockTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|//Major revision=1., Minor revision=1
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PIXEL_CLOCK_PARAMETERS
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10kHz unit; for bios convenient = (RefClk*FB_Div)/(Ref_Div*Post_Div)
comment|// 0 means disable PPLL
name|USHORT
name|usRefDiv
decl_stmt|;
comment|// Reference divider
name|USHORT
name|usFbDiv
decl_stmt|;
comment|// feedback divider
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|// post divider
name|UCHAR
name|ucFracFbDiv
decl_stmt|;
comment|// fractional feedback divider
name|UCHAR
name|ucPpll
decl_stmt|;
comment|// ATOM_PPLL1 or ATOM_PPL2
name|UCHAR
name|ucRefDivSrc
decl_stmt|;
comment|// ATOM_PJITTER or ATO_NONPJITTER
name|UCHAR
name|ucCRTC
decl_stmt|;
comment|// Which CRTC uses this Ppll
name|UCHAR
name|ucPadding
decl_stmt|;
block|}
name|PIXEL_CLOCK_PARAMETERS
typedef|;
end_typedef

begin_comment
comment|//Major revision=1., Minor revision=2, add ucMiscIfno
end_comment

begin_comment
comment|//ucMiscInfo:
end_comment

begin_define
define|#
directive|define
name|MISC_FORCE_REPROG_PIXEL_CLOCK
value|0x1
end_define

begin_define
define|#
directive|define
name|MISC_DEVICE_INDEX_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|MISC_DEVICE_INDEX_SHIFT
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PIXEL_CLOCK_PARAMETERS_V2
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10kHz unit; for bios convenient = (RefClk*FB_Div)/(Ref_Div*Post_Div)
comment|// 0 means disable PPLL
name|USHORT
name|usRefDiv
decl_stmt|;
comment|// Reference divider
name|USHORT
name|usFbDiv
decl_stmt|;
comment|// feedback divider
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|// post divider
name|UCHAR
name|ucFracFbDiv
decl_stmt|;
comment|// fractional feedback divider
name|UCHAR
name|ucPpll
decl_stmt|;
comment|// ATOM_PPLL1 or ATOM_PPL2
name|UCHAR
name|ucRefDivSrc
decl_stmt|;
comment|// ATOM_PJITTER or ATO_NONPJITTER
name|UCHAR
name|ucCRTC
decl_stmt|;
comment|// Which CRTC uses this Ppll
name|UCHAR
name|ucMiscInfo
decl_stmt|;
comment|// Different bits for different purpose, bit [7:4] as device index, bit[0]=Force prog
block|}
name|PIXEL_CLOCK_PARAMETERS_V2
typedef|;
end_typedef

begin_comment
comment|//Major revision=1., Minor revision=3, structure/definition change
end_comment

begin_comment
comment|//ucEncoderMode:
end_comment

begin_comment
comment|//ATOM_ENCODER_MODE_DP
end_comment

begin_comment
comment|//ATOM_ENOCDER_MODE_LVDS
end_comment

begin_comment
comment|//ATOM_ENOCDER_MODE_DVI
end_comment

begin_comment
comment|//ATOM_ENOCDER_MODE_HDMI
end_comment

begin_comment
comment|//ATOM_ENOCDER_MODE_SDVO
end_comment

begin_comment
comment|//ATOM_ENCODER_MODE_TV										13
end_comment

begin_comment
comment|//ATOM_ENCODER_MODE_CV										14
end_comment

begin_comment
comment|//ATOM_ENCODER_MODE_CRT										15
end_comment

begin_comment
comment|//ucDVOConfig
end_comment

begin_comment
comment|//#define DVO_ENCODER_CONFIG_RATE_SEL							0x01
end_comment

begin_comment
comment|//#define DVO_ENCODER_CONFIG_DDR_SPEED						0x00
end_comment

begin_comment
comment|//#define DVO_ENCODER_CONFIG_SDR_SPEED						0x01
end_comment

begin_comment
comment|//#define DVO_ENCODER_CONFIG_OUTPUT_SEL						0x0c
end_comment

begin_comment
comment|//#define DVO_ENCODER_CONFIG_LOW12BIT							0x00
end_comment

begin_comment
comment|//#define DVO_ENCODER_CONFIG_UPPER12BIT						0x04
end_comment

begin_comment
comment|//#define DVO_ENCODER_CONFIG_24BIT								0x08
end_comment

begin_comment
comment|//ucMiscInfo: also changed, see below
end_comment

begin_define
define|#
directive|define
name|PIXEL_CLOCK_MISC_FORCE_PROG_PPLL
value|0x01
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_MISC_VGA_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_MISC_CRTC_SEL_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_MISC_CRTC_SEL_CRTC1
value|0x00
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_MISC_CRTC_SEL_CRTC2
value|0x04
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_MISC_USE_ENGINE_FOR_DISPCLK
value|0x08
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_MISC_REF_DIV_SRC
value|0x10
end_define

begin_comment
comment|// V1.4 for RoadRunner
end_comment

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V4_MISC_SS_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V4_MISC_COHERENT_MODE
value|0x20
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PIXEL_CLOCK_PARAMETERS_V3
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10kHz unit; for bios convenient = (RefClk*FB_Div)/(Ref_Div*Post_Div)
comment|// 0 means disable PPLL. For VGA PPLL,make sure this value is not 0.
name|USHORT
name|usRefDiv
decl_stmt|;
comment|// Reference divider
name|USHORT
name|usFbDiv
decl_stmt|;
comment|// feedback divider
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|// post divider
name|UCHAR
name|ucFracFbDiv
decl_stmt|;
comment|// fractional feedback divider
name|UCHAR
name|ucPpll
decl_stmt|;
comment|// ATOM_PPLL1 or ATOM_PPL2
name|UCHAR
name|ucTransmitterId
decl_stmt|;
comment|// graphic encoder id defined in objectId.h
union|union
block|{
name|UCHAR
name|ucEncoderMode
decl_stmt|;
comment|// encoder type defined as ATOM_ENCODER_MODE_DP/DVI/HDMI/
name|UCHAR
name|ucDVOConfig
decl_stmt|;
comment|// when use DVO, need to know SDR/DDR, 12bit or 24bit
block|}
union|;
name|UCHAR
name|ucMiscInfo
decl_stmt|;
comment|// bit[0]=Force program, bit[1]= set pclk for VGA, b[2]= CRTC sel
comment|// bit[3]=0:use PPLL for dispclk source, =1: use engine clock for dispclock source
comment|// bit[4]=0:use XTALIN as the source of reference divider,=1 use the pre-defined clock as the source of reference divider
block|}
name|PIXEL_CLOCK_PARAMETERS_V3
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PIXEL_CLOCK_PARAMETERS_LAST
value|PIXEL_CLOCK_PARAMETERS_V2
end_define

begin_define
define|#
directive|define
name|GET_PIXEL_CLOCK_PS_ALLOCATION
value|PIXEL_CLOCK_PARAMETERS_LAST
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PIXEL_CLOCK_PARAMETERS_V5
block|{
name|UCHAR
name|ucCRTC
decl_stmt|;
comment|// ATOM_CRTC1~6, indicate the CRTC controller to
comment|// drive the pixel clock. not used for DCPLL case.
union|union
block|{
name|UCHAR
name|ucReserved
decl_stmt|;
name|UCHAR
name|ucFracFbDiv
decl_stmt|;
comment|// [gphan] temporary to prevent build problem.  remove it after driver code is changed.
block|}
union|;
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// target the pixel clock to drive the CRTC timing
comment|// 0 means disable PPLL/DCPLL.
name|USHORT
name|usFbDiv
decl_stmt|;
comment|// feedback divider integer part.
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|// post divider.
name|UCHAR
name|ucRefDiv
decl_stmt|;
comment|// Reference divider
name|UCHAR
name|ucPpll
decl_stmt|;
comment|// ATOM_PPLL1/ATOM_PPLL2/ATOM_DCPLL
name|UCHAR
name|ucTransmitterID
decl_stmt|;
comment|// ASIC encoder id defined in objectId.h,
comment|// indicate which graphic encoder will be used.
name|UCHAR
name|ucEncoderMode
decl_stmt|;
comment|// Encoder mode:
name|UCHAR
name|ucMiscInfo
decl_stmt|;
comment|// bit[0]= Force program PPLL
comment|// bit[1]= when VGA timing is used.
comment|// bit[3:2]= HDMI panel bit depth: =0: 24bpp =1:30bpp, =2:32bpp
comment|// bit[4]= RefClock source for PPLL.
comment|// =0: XTLAIN( default mode )
comment|// =1: other external clock source, which is pre-defined
comment|//     by VBIOS depend on the feature required.
comment|// bit[7:5]: reserved.
name|ULONG
name|ulFbDivDecFrac
decl_stmt|;
comment|// 20 bit feedback divider decimal fraction part, range from 1~999999 ( 0.000001 to 0.999999 )
block|}
name|PIXEL_CLOCK_PARAMETERS_V5
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V5_MISC_FORCE_PROG_PPLL
value|0x01
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V5_MISC_VGA_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V5_MISC_HDMI_BPP_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V5_MISC_HDMI_24BPP
value|0x00
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V5_MISC_HDMI_30BPP
value|0x04
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V5_MISC_HDMI_32BPP
value|0x08
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V5_MISC_REF_DIV_SRC
value|0x10
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CRTC_PIXEL_CLOCK_FREQ
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|ULONG
name|ucCRTC
range|:
literal|8
decl_stmt|;
comment|// ATOM_CRTC1~6, indicate the CRTC controller to
comment|// drive the pixel clock. not used for DCPLL case.
name|ULONG
name|ulPixelClock
range|:
literal|24
decl_stmt|;
comment|// target the pixel clock to drive the CRTC timing.
comment|// 0 means disable PPLL/DCPLL. Expanded to 24 bits comparing to previous version.
else|#
directive|else
name|ULONG
name|ulPixelClock
range|:
literal|24
decl_stmt|;
comment|// target the pixel clock to drive the CRTC timing.
comment|// 0 means disable PPLL/DCPLL. Expanded to 24 bits comparing to previous version.
name|ULONG
name|ucCRTC
range|:
literal|8
decl_stmt|;
comment|// ATOM_CRTC1~6, indicate the CRTC controller to
comment|// drive the pixel clock. not used for DCPLL case.
endif|#
directive|endif
block|}
name|CRTC_PIXEL_CLOCK_FREQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PIXEL_CLOCK_PARAMETERS_V6
block|{
union|union
block|{
name|CRTC_PIXEL_CLOCK_FREQ
name|ulCrtcPclkFreq
decl_stmt|;
comment|// pixel clock and CRTC id frequency
name|ULONG
name|ulDispEngClkFreq
decl_stmt|;
comment|// dispclk frequency
block|}
union|;
name|USHORT
name|usFbDiv
decl_stmt|;
comment|// feedback divider integer part.
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|// post divider.
name|UCHAR
name|ucRefDiv
decl_stmt|;
comment|// Reference divider
name|UCHAR
name|ucPpll
decl_stmt|;
comment|// ATOM_PPLL1/ATOM_PPLL2/ATOM_DCPLL
name|UCHAR
name|ucTransmitterID
decl_stmt|;
comment|// ASIC encoder id defined in objectId.h,
comment|// indicate which graphic encoder will be used.
name|UCHAR
name|ucEncoderMode
decl_stmt|;
comment|// Encoder mode:
name|UCHAR
name|ucMiscInfo
decl_stmt|;
comment|// bit[0]= Force program PPLL
comment|// bit[1]= when VGA timing is used.
comment|// bit[3:2]= HDMI panel bit depth: =0: 24bpp =1:30bpp, =2:32bpp
comment|// bit[4]= RefClock source for PPLL.
comment|// =0: XTLAIN( default mode )
comment|// =1: other external clock source, which is pre-defined
comment|//     by VBIOS depend on the feature required.
comment|// bit[7:5]: reserved.
name|ULONG
name|ulFbDivDecFrac
decl_stmt|;
comment|// 20 bit feedback divider decimal fraction part, range from 1~999999 ( 0.000001 to 0.999999 )
block|}
name|PIXEL_CLOCK_PARAMETERS_V6
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V6_MISC_FORCE_PROG_PPLL
value|0x01
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V6_MISC_VGA_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V6_MISC_HDMI_BPP_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V6_MISC_HDMI_24BPP
value|0x00
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V6_MISC_HDMI_36BPP
value|0x04
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V6_MISC_HDMI_30BPP
value|0x08
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V6_MISC_HDMI_48BPP
value|0x0c
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_V6_MISC_REF_DIV_SRC
value|0x10
end_define

begin_typedef
typedef|typedef
struct|struct
name|_GET_DISP_PLL_STATUS_INPUT_PARAMETERS_V2
block|{
name|PIXEL_CLOCK_PARAMETERS_V3
name|sDispClkInput
decl_stmt|;
block|}
name|GET_DISP_PLL_STATUS_INPUT_PARAMETERS_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_GET_DISP_PLL_STATUS_OUTPUT_PARAMETERS_V2
block|{
name|UCHAR
name|ucStatus
decl_stmt|;
name|UCHAR
name|ucRefDivSrc
decl_stmt|;
comment|// =1: reference clock source from XTALIN, =0: source from PCIE ref clock
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|GET_DISP_PLL_STATUS_OUTPUT_PARAMETERS_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_GET_DISP_PLL_STATUS_INPUT_PARAMETERS_V3
block|{
name|PIXEL_CLOCK_PARAMETERS_V5
name|sDispClkInput
decl_stmt|;
block|}
name|GET_DISP_PLL_STATUS_INPUT_PARAMETERS_V3
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by AdjustDisplayPllTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ADJUST_DISPLAY_PLL_PARAMETERS
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
name|UCHAR
name|ucTransmitterID
decl_stmt|;
name|UCHAR
name|ucEncodeMode
decl_stmt|;
union|union
block|{
name|UCHAR
name|ucDVOConfig
decl_stmt|;
comment|//if DVO, need passing link rate and output 12bitlow or 24bit
name|UCHAR
name|ucConfig
decl_stmt|;
comment|//if none DVO, not defined yet
block|}
union|;
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ADJUST_DISPLAY_PLL_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ADJUST_DISPLAY_CONFIG_SS_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|ADJUST_DISPLAY_PLL_PS_ALLOCATION
value|ADJUST_DISPLAY_PLL_PARAMETERS
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ADJUST_DISPLAY_PLL_INPUT_PARAMETERS_V3
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// target pixel clock
name|UCHAR
name|ucTransmitterID
decl_stmt|;
comment|// GPU transmitter id defined in objectid.h
name|UCHAR
name|ucEncodeMode
decl_stmt|;
comment|// encoder mode: CRT, LVDS, DP, TMDS or HDMI
name|UCHAR
name|ucDispPllConfig
decl_stmt|;
comment|// display pll configure parameter defined as following DISPPLL_CONFIG_XXXX
name|UCHAR
name|ucExtTransmitterID
decl_stmt|;
comment|// external encoder id.
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ADJUST_DISPLAY_PLL_INPUT_PARAMETERS_V3
typedef|;
end_typedef

begin_comment
comment|// usDispPllConfig v1.2 for RoadRunner
end_comment

begin_define
define|#
directive|define
name|DISPPLL_CONFIG_DVO_RATE_SEL
value|0x0001
end_define

begin_comment
comment|// need only when ucTransmitterID = DVO
end_comment

begin_define
define|#
directive|define
name|DISPPLL_CONFIG_DVO_DDR_SPEED
value|0x0000
end_define

begin_comment
comment|// need only when ucTransmitterID = DVO
end_comment

begin_define
define|#
directive|define
name|DISPPLL_CONFIG_DVO_SDR_SPEED
value|0x0001
end_define

begin_comment
comment|// need only when ucTransmitterID = DVO
end_comment

begin_define
define|#
directive|define
name|DISPPLL_CONFIG_DVO_OUTPUT_SEL
value|0x000c
end_define

begin_comment
comment|// need only when ucTransmitterID = DVO
end_comment

begin_define
define|#
directive|define
name|DISPPLL_CONFIG_DVO_LOW12BIT
value|0x0000
end_define

begin_comment
comment|// need only when ucTransmitterID = DVO
end_comment

begin_define
define|#
directive|define
name|DISPPLL_CONFIG_DVO_UPPER12BIT
value|0x0004
end_define

begin_comment
comment|// need only when ucTransmitterID = DVO
end_comment

begin_define
define|#
directive|define
name|DISPPLL_CONFIG_DVO_24BIT
value|0x0008
end_define

begin_comment
comment|// need only when ucTransmitterID = DVO
end_comment

begin_define
define|#
directive|define
name|DISPPLL_CONFIG_SS_ENABLE
value|0x0010
end_define

begin_comment
comment|// Only used when ucEncoderMode = DP or LVDS
end_comment

begin_define
define|#
directive|define
name|DISPPLL_CONFIG_COHERENT_MODE
value|0x0020
end_define

begin_comment
comment|// Only used when ucEncoderMode = TMDS or HDMI
end_comment

begin_define
define|#
directive|define
name|DISPPLL_CONFIG_DUAL_LINK
value|0x0040
end_define

begin_comment
comment|// Only used when ucEncoderMode = TMDS or LVDS
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ADJUST_DISPLAY_PLL_OUTPUT_PARAMETERS_V3
block|{
name|ULONG
name|ulDispPllFreq
decl_stmt|;
comment|// return display PPLL freq which is used to generate the pixclock, and related idclk, symclk etc
name|UCHAR
name|ucRefDiv
decl_stmt|;
comment|// if it is none-zero, it is used to be calculated the other ppll parameter fb_divider and post_div ( if it is not given )
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|// if it is none-zero, it is used to be calculated the other ppll parameter fb_divider
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ADJUST_DISPLAY_PLL_OUTPUT_PARAMETERS_V3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ADJUST_DISPLAY_PLL_PS_ALLOCATION_V3
block|{
union|union
block|{
name|ADJUST_DISPLAY_PLL_INPUT_PARAMETERS_V3
name|sInput
decl_stmt|;
name|ADJUST_DISPLAY_PLL_OUTPUT_PARAMETERS_V3
name|sOutput
decl_stmt|;
block|}
union|;
block|}
name|ADJUST_DISPLAY_PLL_PS_ALLOCATION_V3
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by EnableYUVTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_YUV_PARAMETERS
block|{
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE:Enable YUV or ATOM_DISABLE:Disable YUV (RGB)
name|UCHAR
name|ucCRTC
decl_stmt|;
comment|// Which CRTC needs this YUV or RGB format
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ENABLE_YUV_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ENABLE_YUV_PS_ALLOCATION
value|ENABLE_YUV_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by GetMemoryClockTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_GET_MEMORY_CLOCK_PARAMETERS
block|{
name|ULONG
name|ulReturnMemoryClock
decl_stmt|;
comment|// current memory speed in 10KHz unit
block|}
name|GET_MEMORY_CLOCK_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GET_MEMORY_CLOCK_PS_ALLOCATION
value|GET_MEMORY_CLOCK_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by GetEngineClockTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_GET_ENGINE_CLOCK_PARAMETERS
block|{
name|ULONG
name|ulReturnEngineClock
decl_stmt|;
comment|// current engine speed in 10KHz unit
block|}
name|GET_ENGINE_CLOCK_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GET_ENGINE_CLOCK_PS_ALLOCATION
value|GET_ENGINE_CLOCK_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Following Structures and constant may be obsolete
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|//Maxium 8 bytes,the data read in will be placed in the parameter space.
end_comment

begin_comment
comment|//Read operaion successeful when the paramter space is non-zero, otherwise read operation failed
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_READ_EDID_FROM_HW_I2C_DATA_PARAMETERS
block|{
name|USHORT
name|usPrescale
decl_stmt|;
comment|//Ratio between Engine clock and I2C clock
name|USHORT
name|usVRAMAddress
decl_stmt|;
comment|//Address in Frame Buffer where to pace raw EDID
name|USHORT
name|usStatus
decl_stmt|;
comment|//When use output: lower byte EDID checksum, high byte hardware status
comment|//WHen use input:  lower byte as 'byte to read':currently limited to 128byte or 1byte
name|UCHAR
name|ucSlaveAddr
decl_stmt|;
comment|//Read from which slave
name|UCHAR
name|ucLineNumber
decl_stmt|;
comment|//Read from which HW assisted line
block|}
name|READ_EDID_FROM_HW_I2C_DATA_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|READ_EDID_FROM_HW_I2C_DATA_PS_ALLOCATION
value|READ_EDID_FROM_HW_I2C_DATA_PARAMETERS
end_define

begin_define
define|#
directive|define
name|ATOM_WRITE_I2C_FORMAT_PSOFFSET_PSDATABYTE
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_WRITE_I2C_FORMAT_PSOFFSET_PSTWODATABYTES
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_WRITE_I2C_FORMAT_PSCOUNTER_PSOFFSET_IDDATABLOCK
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_WRITE_I2C_FORMAT_PSCOUNTER_IDOFFSET_PLUS_IDDATABLOCK
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_WRITE_I2C_FORMAT_IDCOUNTER_IDOFFSET_IDDATABLOCK
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|_WRITE_ONE_BYTE_HW_I2C_DATA_PARAMETERS
block|{
name|USHORT
name|usPrescale
decl_stmt|;
comment|//Ratio between Engine clock and I2C clock
name|USHORT
name|usByteOffset
decl_stmt|;
comment|//Write to which byte
comment|//Upper portion of usByteOffset is Format of data
comment|//1bytePS+offsetPS
comment|//2bytesPS+offsetPS
comment|//blockID+offsetPS
comment|//blockID+offsetID
comment|//blockID+counterID+offsetID
name|UCHAR
name|ucData
decl_stmt|;
comment|//PS data1
name|UCHAR
name|ucStatus
decl_stmt|;
comment|//Status byte 1=success, 2=failure, Also is used as PS data2
name|UCHAR
name|ucSlaveAddr
decl_stmt|;
comment|//Write to which slave
name|UCHAR
name|ucLineNumber
decl_stmt|;
comment|//Write from which HW assisted line
block|}
name|WRITE_ONE_BYTE_HW_I2C_DATA_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WRITE_ONE_BYTE_HW_I2C_DATA_PS_ALLOCATION
value|WRITE_ONE_BYTE_HW_I2C_DATA_PARAMETERS
end_define

begin_typedef
typedef|typedef
struct|struct
name|_SET_UP_HW_I2C_DATA_PARAMETERS
block|{
name|USHORT
name|usPrescale
decl_stmt|;
comment|//Ratio between Engine clock and I2C clock
name|UCHAR
name|ucSlaveAddr
decl_stmt|;
comment|//Write to which slave
name|UCHAR
name|ucLineNumber
decl_stmt|;
comment|//Write from which HW assisted line
block|}
name|SET_UP_HW_I2C_DATA_PARAMETERS
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SPEED_FAN_CONTROL_PS_ALLOCATION
value|WRITE_ONE_BYTE_HW_I2C_DATA_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by PowerConnectorDetectionTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_POWER_CONNECTOR_DETECTION_PARAMETERS
block|{
name|UCHAR
name|ucPowerConnectorStatus
decl_stmt|;
comment|//Used for return value 0: detected, 1:not detected
name|UCHAR
name|ucPwrBehaviorId
decl_stmt|;
name|USHORT
name|usPwrBudget
decl_stmt|;
comment|//how much power currently boot to in unit of watt
block|}
name|POWER_CONNECTOR_DETECTION_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|POWER_CONNECTOR_DETECTION_PS_ALLOCATION
block|{
name|UCHAR
name|ucPowerConnectorStatus
decl_stmt|;
comment|//Used for return value 0: detected, 1:not detected
name|UCHAR
name|ucReserved
decl_stmt|;
name|USHORT
name|usPwrBudget
decl_stmt|;
comment|//how much power currently boot to in unit of watt
name|WRITE_ONE_BYTE_HW_I2C_DATA_PS_ALLOCATION
name|sReserved
decl_stmt|;
block|}
name|POWER_CONNECTOR_DETECTION_PS_ALLOCATION
typedef|;
end_typedef

begin_comment
comment|/****************************LVDS SS Command Table Definitions**********************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by EnableSpreadSpectrumOnPPLLTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_LVDS_SS_PARAMETERS
block|{
name|USHORT
name|usSpreadSpectrumPercentage
decl_stmt|;
name|UCHAR
name|ucSpreadSpectrumType
decl_stmt|;
comment|//Bit1=0 Down Spread,=1 Center Spread. Bit1=1 Ext. =0 Int. Others:TBD
name|UCHAR
name|ucSpreadSpectrumStepSize_Delay
decl_stmt|;
comment|//bits3:2 SS_STEP_SIZE; bit 6:4 SS_DELAY
name|UCHAR
name|ucEnable
decl_stmt|;
comment|//ATOM_ENABLE or ATOM_DISABLE
name|UCHAR
name|ucPadding
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ENABLE_LVDS_SS_PARAMETERS
typedef|;
end_typedef

begin_comment
comment|//ucTableFormatRevision=1,ucTableContentRevision=2
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_LVDS_SS_PARAMETERS_V2
block|{
name|USHORT
name|usSpreadSpectrumPercentage
decl_stmt|;
name|UCHAR
name|ucSpreadSpectrumType
decl_stmt|;
comment|//Bit1=0 Down Spread,=1 Center Spread. Bit1=1 Ext. =0 Int. Others:TBD
name|UCHAR
name|ucSpreadSpectrumStep
decl_stmt|;
comment|//
name|UCHAR
name|ucEnable
decl_stmt|;
comment|//ATOM_ENABLE or ATOM_DISABLE
name|UCHAR
name|ucSpreadSpectrumDelay
decl_stmt|;
name|UCHAR
name|ucSpreadSpectrumRange
decl_stmt|;
name|UCHAR
name|ucPadding
decl_stmt|;
block|}
name|ENABLE_LVDS_SS_PARAMETERS_V2
typedef|;
end_typedef

begin_comment
comment|//This new structure is based on ENABLE_LVDS_SS_PARAMETERS but expands to SS on PPLL, so other devices can use SS.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_SPREAD_SPECTRUM_ON_PPLL
block|{
name|USHORT
name|usSpreadSpectrumPercentage
decl_stmt|;
name|UCHAR
name|ucSpreadSpectrumType
decl_stmt|;
comment|// Bit1=0 Down Spread,=1 Center Spread. Bit1=1 Ext. =0 Int. Others:TBD
name|UCHAR
name|ucSpreadSpectrumStep
decl_stmt|;
comment|//
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE or ATOM_DISABLE
name|UCHAR
name|ucSpreadSpectrumDelay
decl_stmt|;
name|UCHAR
name|ucSpreadSpectrumRange
decl_stmt|;
name|UCHAR
name|ucPpll
decl_stmt|;
comment|// ATOM_PPLL1/ATOM_PPLL2
block|}
name|ENABLE_SPREAD_SPECTRUM_ON_PPLL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_SPREAD_SPECTRUM_ON_PPLL_V2
block|{
name|USHORT
name|usSpreadSpectrumPercentage
decl_stmt|;
name|UCHAR
name|ucSpreadSpectrumType
decl_stmt|;
comment|// Bit[0]: 0-Down Spread,1-Center Spread.
comment|// Bit[1]: 1-Ext. 0-Int.
comment|// Bit[3:2]: =0 P1PLL =1 P2PLL =2 DCPLL
comment|// Bits[7:4] reserved
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE or ATOM_DISABLE
name|USHORT
name|usSpreadSpectrumAmount
decl_stmt|;
comment|// Includes SS_AMOUNT_FBDIV[7:0] and SS_AMOUNT_NFRAC_SLIP[11:8]
name|USHORT
name|usSpreadSpectrumStep
decl_stmt|;
comment|// SS_STEP_SIZE_DSFRAC
block|}
name|ENABLE_SPREAD_SPECTRUM_ON_PPLL_V2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V2_DOWN_SPREAD
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V2_CENTRE_SPREAD
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V2_EXT_SPREAD
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V2_PPLL_SEL_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V2_P1PLL
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V2_P2PLL
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V2_DCPLL
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_AMOUNT_V2_FBDIV_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_AMOUNT_V2_FBDIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_AMOUNT_V2_NFRAC_MASK
value|0x0F00
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_AMOUNT_V2_NFRAC_SHIFT
value|8
end_define

begin_comment
comment|// Used by DCE5.0
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_SPREAD_SPECTRUM_ON_PPLL_V3
block|{
name|USHORT
name|usSpreadSpectrumAmountFrac
decl_stmt|;
comment|// SS_AMOUNT_DSFRAC New in DCE5.0
name|UCHAR
name|ucSpreadSpectrumType
decl_stmt|;
comment|// Bit[0]: 0-Down Spread,1-Center Spread.
comment|// Bit[1]: 1-Ext. 0-Int.
comment|// Bit[3:2]: =0 P1PLL =1 P2PLL =2 DCPLL
comment|// Bits[7:4] reserved
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE or ATOM_DISABLE
name|USHORT
name|usSpreadSpectrumAmount
decl_stmt|;
comment|// Includes SS_AMOUNT_FBDIV[7:0] and SS_AMOUNT_NFRAC_SLIP[11:8]
name|USHORT
name|usSpreadSpectrumStep
decl_stmt|;
comment|// SS_STEP_SIZE_DSFRAC
block|}
name|ENABLE_SPREAD_SPECTRUM_ON_PPLL_V3
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V3_DOWN_SPREAD
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V3_CENTRE_SPREAD
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V3_EXT_SPREAD
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V3_PPLL_SEL_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V3_P1PLL
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V3_P2PLL
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V3_DCPLL
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_TYPE_V3_P0PLL
value|ATOM_PPLL_SS_TYPE_V3_DCPLL
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_AMOUNT_V3_FBDIV_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_AMOUNT_V3_FBDIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_AMOUNT_V3_NFRAC_MASK
value|0x0F00
end_define

begin_define
define|#
directive|define
name|ATOM_PPLL_SS_AMOUNT_V3_NFRAC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ENABLE_SPREAD_SPECTRUM_ON_PPLL_PS_ALLOCATION
value|ENABLE_SPREAD_SPECTRUM_ON_PPLL
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SET_PIXEL_CLOCK_PS_ALLOCATION
block|{
name|PIXEL_CLOCK_PARAMETERS
name|sPCLKInput
decl_stmt|;
name|ENABLE_SPREAD_SPECTRUM_ON_PPLL
name|sReserved
decl_stmt|;
comment|//Caller doesn't need to init this portion
block|}
name|SET_PIXEL_CLOCK_PS_ALLOCATION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ENABLE_VGA_RENDER_PS_ALLOCATION
value|SET_PIXEL_CLOCK_PS_ALLOCATION
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by ###
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MEMORY_TRAINING_PARAMETERS
block|{
name|ULONG
name|ulTargetMemoryClock
decl_stmt|;
comment|//In 10Khz unit
block|}
name|MEMORY_TRAINING_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MEMORY_TRAINING_PS_ALLOCATION
value|MEMORY_TRAINING_PARAMETERS
end_define

begin_comment
comment|/****************************LVDS and other encoder command table definitions **********************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by LVDSEncoderControlTable   (Before DCE30)
end_comment

begin_comment
comment|//                    LVTMAEncoderControlTable  (Before DCE30)
end_comment

begin_comment
comment|//                    TMDSAEncoderControlTable  (Before DCE30)
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_LVDS_ENCODER_CONTROL_PARAMETERS
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
name|UCHAR
name|ucMisc
decl_stmt|;
comment|// bit0=0: Enable single link
comment|//     =1: Enable dual link
comment|// Bit1=0: 666RGB
comment|//     =1: 888RGB
name|UCHAR
name|ucAction
decl_stmt|;
comment|// 0: turn off encoder
comment|// 1: setup and turn on encoder
block|}
name|LVDS_ENCODER_CONTROL_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LVDS_ENCODER_CONTROL_PS_ALLOCATION
value|LVDS_ENCODER_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|TMDS1_ENCODER_CONTROL_PARAMETERS
value|LVDS_ENCODER_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|TMDS1_ENCODER_CONTROL_PS_ALLOCATION
value|TMDS1_ENCODER_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|TMDS2_ENCODER_CONTROL_PARAMETERS
value|TMDS1_ENCODER_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|TMDS2_ENCODER_CONTROL_PS_ALLOCATION
value|TMDS2_ENCODER_CONTROL_PARAMETERS
end_define

begin_comment
comment|//ucTableFormatRevision=1,ucTableContentRevision=2
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_LVDS_ENCODER_CONTROL_PARAMETERS_V2
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
name|UCHAR
name|ucMisc
decl_stmt|;
comment|// see PANEL_ENCODER_MISC_xx defintions below
name|UCHAR
name|ucAction
decl_stmt|;
comment|// 0: turn off encoder
comment|// 1: setup and turn on encoder
name|UCHAR
name|ucTruncate
decl_stmt|;
comment|// bit0=0: Disable truncate
comment|//     =1: Enable truncate
comment|// bit4=0: 666RGB
comment|//     =1: 888RGB
name|UCHAR
name|ucSpatial
decl_stmt|;
comment|// bit0=0: Disable spatial dithering
comment|//     =1: Enable spatial dithering
comment|// bit4=0: 666RGB
comment|//     =1: 888RGB
name|UCHAR
name|ucTemporal
decl_stmt|;
comment|// bit0=0: Disable temporal dithering
comment|//     =1: Enable temporal dithering
comment|// bit4=0: 666RGB
comment|//     =1: 888RGB
comment|// bit5=0: Gray level 2
comment|//     =1: Gray level 4
name|UCHAR
name|ucFRC
decl_stmt|;
comment|// bit4=0: 25FRC_SEL pattern E
comment|//     =1: 25FRC_SEL pattern F
comment|// bit6:5=0: 50FRC_SEL pattern A
comment|//       =1: 50FRC_SEL pattern B
comment|//       =2: 50FRC_SEL pattern C
comment|//       =3: 50FRC_SEL pattern D
comment|// bit7=0: 75FRC_SEL pattern E
comment|//     =1: 75FRC_SEL pattern F
block|}
name|LVDS_ENCODER_CONTROL_PARAMETERS_V2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LVDS_ENCODER_CONTROL_PS_ALLOCATION_V2
value|LVDS_ENCODER_CONTROL_PARAMETERS_V2
end_define

begin_define
define|#
directive|define
name|TMDS1_ENCODER_CONTROL_PARAMETERS_V2
value|LVDS_ENCODER_CONTROL_PARAMETERS_V2
end_define

begin_define
define|#
directive|define
name|TMDS1_ENCODER_CONTROL_PS_ALLOCATION_V2
value|TMDS1_ENCODER_CONTROL_PARAMETERS_V2
end_define

begin_define
define|#
directive|define
name|TMDS2_ENCODER_CONTROL_PARAMETERS_V2
value|TMDS1_ENCODER_CONTROL_PARAMETERS_V2
end_define

begin_define
define|#
directive|define
name|TMDS2_ENCODER_CONTROL_PS_ALLOCATION_V2
value|TMDS2_ENCODER_CONTROL_PARAMETERS_V2
end_define

begin_define
define|#
directive|define
name|LVDS_ENCODER_CONTROL_PARAMETERS_V3
value|LVDS_ENCODER_CONTROL_PARAMETERS_V2
end_define

begin_define
define|#
directive|define
name|LVDS_ENCODER_CONTROL_PS_ALLOCATION_V3
value|LVDS_ENCODER_CONTROL_PARAMETERS_V3
end_define

begin_define
define|#
directive|define
name|TMDS1_ENCODER_CONTROL_PARAMETERS_V3
value|LVDS_ENCODER_CONTROL_PARAMETERS_V3
end_define

begin_define
define|#
directive|define
name|TMDS1_ENCODER_CONTROL_PS_ALLOCATION_V3
value|TMDS1_ENCODER_CONTROL_PARAMETERS_V3
end_define

begin_define
define|#
directive|define
name|TMDS2_ENCODER_CONTROL_PARAMETERS_V3
value|LVDS_ENCODER_CONTROL_PARAMETERS_V3
end_define

begin_define
define|#
directive|define
name|TMDS2_ENCODER_CONTROL_PS_ALLOCATION_V3
value|TMDS2_ENCODER_CONTROL_PARAMETERS_V3
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by ###
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_EXTERNAL_TMDS_ENCODER_PARAMETERS
block|{
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// Enable or Disable External TMDS encoder
name|UCHAR
name|ucMisc
decl_stmt|;
comment|// Bit0=0:Enable Single link;=1:Enable Dual link;Bit1 {=0:666RGB, =1:888RGB}
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ENABLE_EXTERNAL_TMDS_ENCODER_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_EXTERNAL_TMDS_ENCODER_PS_ALLOCATION
block|{
name|ENABLE_EXTERNAL_TMDS_ENCODER_PARAMETERS
name|sXTmdsEncoder
decl_stmt|;
name|WRITE_ONE_BYTE_HW_I2C_DATA_PS_ALLOCATION
name|sReserved
decl_stmt|;
comment|//Caller doesn't need to init this portion
block|}
name|ENABLE_EXTERNAL_TMDS_ENCODER_PS_ALLOCATION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ENABLE_EXTERNAL_TMDS_ENCODER_PARAMETERS_V2
value|LVDS_ENCODER_CONTROL_PARAMETERS_V2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_EXTERNAL_TMDS_ENCODER_PS_ALLOCATION_V2
block|{
name|ENABLE_EXTERNAL_TMDS_ENCODER_PARAMETERS_V2
name|sXTmdsEncoder
decl_stmt|;
name|WRITE_ONE_BYTE_HW_I2C_DATA_PS_ALLOCATION
name|sReserved
decl_stmt|;
comment|//Caller doesn't need to init this portion
block|}
name|ENABLE_EXTERNAL_TMDS_ENCODER_PS_ALLOCATION_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EXTERNAL_ENCODER_CONTROL_PS_ALLOCATION
block|{
name|DIG_ENCODER_CONTROL_PARAMETERS
name|sDigEncoder
decl_stmt|;
name|WRITE_ONE_BYTE_HW_I2C_DATA_PS_ALLOCATION
name|sReserved
decl_stmt|;
block|}
name|EXTERNAL_ENCODER_CONTROL_PS_ALLOCATION
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by DVOEncoderControlTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|//ucTableFormatRevision=1,ucTableContentRevision=3
end_comment

begin_comment
comment|//ucDVOConfig:
end_comment

begin_define
define|#
directive|define
name|DVO_ENCODER_CONFIG_RATE_SEL
value|0x01
end_define

begin_define
define|#
directive|define
name|DVO_ENCODER_CONFIG_DDR_SPEED
value|0x00
end_define

begin_define
define|#
directive|define
name|DVO_ENCODER_CONFIG_SDR_SPEED
value|0x01
end_define

begin_define
define|#
directive|define
name|DVO_ENCODER_CONFIG_OUTPUT_SEL
value|0x0c
end_define

begin_define
define|#
directive|define
name|DVO_ENCODER_CONFIG_LOW12BIT
value|0x00
end_define

begin_define
define|#
directive|define
name|DVO_ENCODER_CONFIG_UPPER12BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|DVO_ENCODER_CONFIG_24BIT
value|0x08
end_define

begin_typedef
typedef|typedef
struct|struct
name|_DVO_ENCODER_CONTROL_PARAMETERS_V3
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
name|UCHAR
name|ucDVOConfig
decl_stmt|;
name|UCHAR
name|ucAction
decl_stmt|;
comment|//ATOM_ENABLE/ATOM_DISABLE/ATOM_HPD_INIT
name|UCHAR
name|ucReseved
index|[
literal|4
index|]
decl_stmt|;
block|}
name|DVO_ENCODER_CONTROL_PARAMETERS_V3
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DVO_ENCODER_CONTROL_PS_ALLOCATION_V3
value|DVO_ENCODER_CONTROL_PARAMETERS_V3
end_define

begin_comment
comment|//ucTableFormatRevision=1
end_comment

begin_comment
comment|//ucTableContentRevision=3 structure is not changed but usMisc add bit 1 as another input for
end_comment

begin_comment
comment|// bit1=0: non-coherent mode
end_comment

begin_comment
comment|//     =1: coherent mode
end_comment

begin_comment
comment|//==========================================================================================
end_comment

begin_comment
comment|//Only change is here next time when changing encoder parameter definitions again!
end_comment

begin_define
define|#
directive|define
name|LVDS_ENCODER_CONTROL_PARAMETERS_LAST
value|LVDS_ENCODER_CONTROL_PARAMETERS_V3
end_define

begin_define
define|#
directive|define
name|LVDS_ENCODER_CONTROL_PS_ALLOCATION_LAST
value|LVDS_ENCODER_CONTROL_PARAMETERS_LAST
end_define

begin_define
define|#
directive|define
name|TMDS1_ENCODER_CONTROL_PARAMETERS_LAST
value|LVDS_ENCODER_CONTROL_PARAMETERS_V3
end_define

begin_define
define|#
directive|define
name|TMDS1_ENCODER_CONTROL_PS_ALLOCATION_LAST
value|TMDS1_ENCODER_CONTROL_PARAMETERS_LAST
end_define

begin_define
define|#
directive|define
name|TMDS2_ENCODER_CONTROL_PARAMETERS_LAST
value|LVDS_ENCODER_CONTROL_PARAMETERS_V3
end_define

begin_define
define|#
directive|define
name|TMDS2_ENCODER_CONTROL_PS_ALLOCATION_LAST
value|TMDS2_ENCODER_CONTROL_PARAMETERS_LAST
end_define

begin_define
define|#
directive|define
name|DVO_ENCODER_CONTROL_PARAMETERS_LAST
value|DVO_ENCODER_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|DVO_ENCODER_CONTROL_PS_ALLOCATION_LAST
value|DVO_ENCODER_CONTROL_PS_ALLOCATION
end_define

begin_comment
comment|//==========================================================================================
end_comment

begin_define
define|#
directive|define
name|PANEL_ENCODER_MISC_DUAL
value|0x01
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_MISC_COHERENT
value|0x02
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_MISC_TMDS_LINKB
value|0x04
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_MISC_HDMI_TYPE
value|0x08
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_ACTION_DISABLE
value|ATOM_DISABLE
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_ACTION_ENABLE
value|ATOM_ENABLE
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_ACTION_COHERENTSEQ
value|(ATOM_ENABLE+1)
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_TRUNCATE_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_TRUNCATE_DEPTH
value|0x10
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_SPATIAL_DITHER_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_SPATIAL_DITHER_DEPTH
value|0x10
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_TEMPORAL_DITHER_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_TEMPORAL_DITHER_DEPTH
value|0x10
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_TEMPORAL_LEVEL_4
value|0x20
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_25FRC_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_25FRC_E
value|0x00
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_25FRC_F
value|0x10
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_50FRC_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_50FRC_A
value|0x00
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_50FRC_B
value|0x20
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_50FRC_C
value|0x40
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_50FRC_D
value|0x60
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_75FRC_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_75FRC_E
value|0x00
end_define

begin_define
define|#
directive|define
name|PANEL_ENCODER_75FRC_F
value|0x80
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by SetVoltageTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SET_VOLTAGE_TYPE_ASIC_VDDC
value|1
end_define

begin_define
define|#
directive|define
name|SET_VOLTAGE_TYPE_ASIC_MVDDC
value|2
end_define

begin_define
define|#
directive|define
name|SET_VOLTAGE_TYPE_ASIC_MVDDQ
value|3
end_define

begin_define
define|#
directive|define
name|SET_VOLTAGE_TYPE_ASIC_VDDCI
value|4
end_define

begin_define
define|#
directive|define
name|SET_VOLTAGE_INIT_MODE
value|5
end_define

begin_define
define|#
directive|define
name|SET_VOLTAGE_GET_MAX_VOLTAGE
value|6
end_define

begin_comment
comment|//Gets the Max. voltage for the soldered Asic
end_comment

begin_define
define|#
directive|define
name|SET_ASIC_VOLTAGE_MODE_ALL_SOURCE
value|0x1
end_define

begin_define
define|#
directive|define
name|SET_ASIC_VOLTAGE_MODE_SOURCE_A
value|0x2
end_define

begin_define
define|#
directive|define
name|SET_ASIC_VOLTAGE_MODE_SOURCE_B
value|0x4
end_define

begin_define
define|#
directive|define
name|SET_ASIC_VOLTAGE_MODE_SET_VOLTAGE
value|0x0
end_define

begin_define
define|#
directive|define
name|SET_ASIC_VOLTAGE_MODE_GET_GPIOVAL
value|0x1
end_define

begin_define
define|#
directive|define
name|SET_ASIC_VOLTAGE_MODE_GET_GPIOMASK
value|0x2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_SET_VOLTAGE_PARAMETERS
block|{
name|UCHAR
name|ucVoltageType
decl_stmt|;
comment|// To tell which voltage to set up, VDDC/MVDDC/MVDDQ
name|UCHAR
name|ucVoltageMode
decl_stmt|;
comment|// To set all, to set source A or source B or ...
name|UCHAR
name|ucVoltageIndex
decl_stmt|;
comment|// An index to tell which voltage level
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|SET_VOLTAGE_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SET_VOLTAGE_PARAMETERS_V2
block|{
name|UCHAR
name|ucVoltageType
decl_stmt|;
comment|// To tell which voltage to set up, VDDC/MVDDC/MVDDQ
name|UCHAR
name|ucVoltageMode
decl_stmt|;
comment|// Not used, maybe use for state machine for differen power mode
name|USHORT
name|usVoltageLevel
decl_stmt|;
comment|// real voltage level
block|}
name|SET_VOLTAGE_PARAMETERS_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SET_VOLTAGE_PARAMETERS_V1_3
block|{
name|UCHAR
name|ucVoltageType
decl_stmt|;
comment|// To tell which voltage to set up, VDDC/MVDDC/MVDDQ/VDDCI
name|UCHAR
name|ucVoltageMode
decl_stmt|;
comment|// Indicate action: Set voltage level
name|USHORT
name|usVoltageLevel
decl_stmt|;
comment|// real voltage level in unit of mv or Voltage Phase (0, 1, 2, .. )
block|}
name|SET_VOLTAGE_PARAMETERS_V1_3
typedef|;
end_typedef

begin_comment
comment|//ucVoltageType
end_comment

begin_define
define|#
directive|define
name|VOLTAGE_TYPE_VDDC
value|1
end_define

begin_define
define|#
directive|define
name|VOLTAGE_TYPE_MVDDC
value|2
end_define

begin_define
define|#
directive|define
name|VOLTAGE_TYPE_MVDDQ
value|3
end_define

begin_define
define|#
directive|define
name|VOLTAGE_TYPE_VDDCI
value|4
end_define

begin_comment
comment|//SET_VOLTAGE_PARAMETERS_V3.ucVoltageMode
end_comment

begin_define
define|#
directive|define
name|ATOM_SET_VOLTAGE
value|0
end_define

begin_comment
comment|//Set voltage Level
end_comment

begin_define
define|#
directive|define
name|ATOM_INIT_VOLTAGE_REGULATOR
value|3
end_define

begin_comment
comment|//Init Regulator
end_comment

begin_define
define|#
directive|define
name|ATOM_SET_VOLTAGE_PHASE
value|4
end_define

begin_comment
comment|//Set Vregulator Phase
end_comment

begin_define
define|#
directive|define
name|ATOM_GET_MAX_VOLTAGE
value|6
end_define

begin_comment
comment|//Get Max Voltage, not used in SetVoltageTable v1.3
end_comment

begin_define
define|#
directive|define
name|ATOM_GET_VOLTAGE_LEVEL
value|6
end_define

begin_comment
comment|//Get Voltage level from vitual voltage ID
end_comment

begin_comment
comment|// define vitual voltage id in usVoltageLevel
end_comment

begin_define
define|#
directive|define
name|ATOM_VIRTUAL_VOLTAGE_ID0
value|0xff01
end_define

begin_define
define|#
directive|define
name|ATOM_VIRTUAL_VOLTAGE_ID1
value|0xff02
end_define

begin_define
define|#
directive|define
name|ATOM_VIRTUAL_VOLTAGE_ID2
value|0xff03
end_define

begin_define
define|#
directive|define
name|ATOM_VIRTUAL_VOLTAGE_ID3
value|0xff04
end_define

begin_typedef
typedef|typedef
struct|struct
name|_SET_VOLTAGE_PS_ALLOCATION
block|{
name|SET_VOLTAGE_PARAMETERS
name|sASICSetVoltage
decl_stmt|;
name|WRITE_ONE_BYTE_HW_I2C_DATA_PS_ALLOCATION
name|sReserved
decl_stmt|;
block|}
name|SET_VOLTAGE_PS_ALLOCATION
typedef|;
end_typedef

begin_comment
comment|// New Added from SI for GetVoltageInfoTable, input parameter structure
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_GET_VOLTAGE_INFO_INPUT_PARAMETER_V1_1
block|{
name|UCHAR
name|ucVoltageType
decl_stmt|;
comment|// Input: To tell which voltage to set up, VDDC/MVDDC/MVDDQ/VDDCI
name|UCHAR
name|ucVoltageMode
decl_stmt|;
comment|// Input: Indicate action: Get voltage info
name|USHORT
name|usVoltageLevel
decl_stmt|;
comment|// Input: real voltage level in unit of mv or Voltage Phase (0, 1, 2, .. ) or Leakage Id
name|ULONG
name|ulReserved
decl_stmt|;
block|}
name|GET_VOLTAGE_INFO_INPUT_PARAMETER_V1_1
typedef|;
end_typedef

begin_comment
comment|// New Added from SI for GetVoltageInfoTable, output parameter structure when ucVotlageMode == ATOM_GET_VOLTAGE_VID
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_GET_VOLTAGE_INFO_OUTPUT_PARAMETER_V1_1
block|{
name|ULONG
name|ulVotlageGpioState
decl_stmt|;
name|ULONG
name|ulVoltageGPioMask
decl_stmt|;
block|}
name|GET_VOLTAGE_INFO_OUTPUT_PARAMETER_V1_1
typedef|;
end_typedef

begin_comment
comment|// New Added from SI for GetVoltageInfoTable, output parameter structure when ucVotlageMode == ATOM_GET_VOLTAGE_STATEx_LEAKAGE_VID
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_GET_LEAKAGE_VOLTAGE_INFO_OUTPUT_PARAMETER_V1_1
block|{
name|USHORT
name|usVoltageLevel
decl_stmt|;
name|USHORT
name|usVoltageId
decl_stmt|;
comment|// Voltage Id programmed in Voltage Regulator
name|ULONG
name|ulReseved
decl_stmt|;
block|}
name|GET_LEAKAGE_VOLTAGE_INFO_OUTPUT_PARAMETER_V1_1
typedef|;
end_typedef

begin_comment
comment|// GetVoltageInfo v1.1 ucVoltageMode
end_comment

begin_define
define|#
directive|define
name|ATOM_GET_VOLTAGE_VID
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_GET_VOTLAGE_INIT_SEQ
value|0x03
end_define

begin_define
define|#
directive|define
name|ATOM_GET_VOLTTAGE_PHASE_PHASE_VID
value|0x04
end_define

begin_comment
comment|// for SI, this state map to 0xff02 voltage state in Power Play table, which is power boost state
end_comment

begin_define
define|#
directive|define
name|ATOM_GET_VOLTAGE_STATE0_LEAKAGE_VID
value|0x10
end_define

begin_comment
comment|// for SI, this state map to 0xff01 voltage state in Power Play table, which is performance state
end_comment

begin_define
define|#
directive|define
name|ATOM_GET_VOLTAGE_STATE1_LEAKAGE_VID
value|0x11
end_define

begin_comment
comment|// undefined power state
end_comment

begin_define
define|#
directive|define
name|ATOM_GET_VOLTAGE_STATE2_LEAKAGE_VID
value|0x12
end_define

begin_define
define|#
directive|define
name|ATOM_GET_VOLTAGE_STATE3_LEAKAGE_VID
value|0x13
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by TVEncoderControlTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TV_ENCODER_CONTROL_PARAMETERS
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
comment|// in 10KHz; for bios convenient
name|UCHAR
name|ucTvStandard
decl_stmt|;
comment|// See definition "ATOM_TV_NTSC ..."
name|UCHAR
name|ucAction
decl_stmt|;
comment|// 0: turn off encoder
comment|// 1: setup and turn on encoder
block|}
name|TV_ENCODER_CONTROL_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TV_ENCODER_CONTROL_PS_ALLOCATION
block|{
name|TV_ENCODER_CONTROL_PARAMETERS
name|sTVEncoder
decl_stmt|;
name|WRITE_ONE_BYTE_HW_I2C_DATA_PS_ALLOCATION
name|sReserved
decl_stmt|;
comment|// Don't set this one
block|}
name|TV_ENCODER_CONTROL_PS_ALLOCATION
typedef|;
end_typedef

begin_comment
comment|//==============================Data Table Portion====================================
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in Data.mtb
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MASTER_LIST_OF_DATA_TABLES
block|{
name|USHORT
name|UtilityPipeLine
decl_stmt|;
comment|// Offest for the utility to get parser info,Don't change this position!
name|USHORT
name|MultimediaCapabilityInfo
decl_stmt|;
comment|// Only used by MM Lib,latest version 1.1, not configuable from Bios, need to include the table to build Bios
name|USHORT
name|MultimediaConfigInfo
decl_stmt|;
comment|// Only used by MM Lib,latest version 2.1, not configuable from Bios, need to include the table to build Bios
name|USHORT
name|StandardVESA_Timing
decl_stmt|;
comment|// Only used by Bios
name|USHORT
name|FirmwareInfo
decl_stmt|;
comment|// Shared by various SW components,latest version 1.4
name|USHORT
name|PaletteData
decl_stmt|;
comment|// Only used by BIOS
name|USHORT
name|LCD_Info
decl_stmt|;
comment|// Shared by various SW components,latest version 1.3, was called LVDS_Info
name|USHORT
name|DIGTransmitterInfo
decl_stmt|;
comment|// Internal used by VBIOS only version 3.1
name|USHORT
name|AnalogTV_Info
decl_stmt|;
comment|// Shared by various SW components,latest version 1.1
name|USHORT
name|SupportedDevicesInfo
decl_stmt|;
comment|// Will be obsolete from R600
name|USHORT
name|GPIO_I2C_Info
decl_stmt|;
comment|// Shared by various SW components,latest version 1.2 will be used from R600
name|USHORT
name|VRAM_UsageByFirmware
decl_stmt|;
comment|// Shared by various SW components,latest version 1.3 will be used from R600
name|USHORT
name|GPIO_Pin_LUT
decl_stmt|;
comment|// Shared by various SW components,latest version 1.1
name|USHORT
name|VESA_ToInternalModeLUT
decl_stmt|;
comment|// Only used by Bios
name|USHORT
name|ComponentVideoInfo
decl_stmt|;
comment|// Shared by various SW components,latest version 2.1 will be used from R600
name|USHORT
name|PowerPlayInfo
decl_stmt|;
comment|// Shared by various SW components,latest version 2.1,new design from R600
name|USHORT
name|CompassionateData
decl_stmt|;
comment|// Will be obsolete from R600
name|USHORT
name|SaveRestoreInfo
decl_stmt|;
comment|// Only used by Bios
name|USHORT
name|PPLL_SS_Info
decl_stmt|;
comment|// Shared by various SW components,latest version 1.2, used to call SS_Info, change to new name because of int ASIC SS info
name|USHORT
name|OemInfo
decl_stmt|;
comment|// Defined and used by external SW, should be obsolete soon
name|USHORT
name|XTMDS_Info
decl_stmt|;
comment|// Will be obsolete from R600
name|USHORT
name|MclkSS_Info
decl_stmt|;
comment|// Shared by various SW components,latest version 1.1, only enabled when ext SS chip is used
name|USHORT
name|Object_Header
decl_stmt|;
comment|// Shared by various SW components,latest version 1.1
name|USHORT
name|IndirectIOAccess
decl_stmt|;
comment|// Only used by Bios,this table position can't change at all!!
name|USHORT
name|MC_InitParameter
decl_stmt|;
comment|// Only used by command table
name|USHORT
name|ASIC_VDDC_Info
decl_stmt|;
comment|// Will be obsolete from R600
name|USHORT
name|ASIC_InternalSS_Info
decl_stmt|;
comment|// New tabel name from R600, used to be called "ASIC_MVDDC_Info"
name|USHORT
name|TV_VideoMode
decl_stmt|;
comment|// Only used by command table
name|USHORT
name|VRAM_Info
decl_stmt|;
comment|// Only used by command table, latest version 1.3
name|USHORT
name|MemoryTrainingInfo
decl_stmt|;
comment|// Used for VBIOS and Diag utility for memory training purpose since R600. the new table rev start from 2.1
name|USHORT
name|IntegratedSystemInfo
decl_stmt|;
comment|// Shared by various SW components
name|USHORT
name|ASIC_ProfilingInfo
decl_stmt|;
comment|// New table name from R600, used to be called "ASIC_VDDCI_Info" for pre-R600
name|USHORT
name|VoltageObjectInfo
decl_stmt|;
comment|// Shared by various SW components, latest version 1.1
name|USHORT
name|PowerSourceInfo
decl_stmt|;
comment|// Shared by various SW components, latest versoin 1.1
block|}
name|ATOM_MASTER_LIST_OF_DATA_TABLES
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MASTER_DATA_TABLE
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_MASTER_LIST_OF_DATA_TABLES
name|ListOfDataTables
decl_stmt|;
block|}
name|ATOM_MASTER_DATA_TABLE
typedef|;
end_typedef

begin_comment
comment|// For backward compatible
end_comment

begin_define
define|#
directive|define
name|LVDS_Info
value|LCD_Info
end_define

begin_define
define|#
directive|define
name|DAC_Info
value|PaletteData
end_define

begin_define
define|#
directive|define
name|TMDS_Info
value|DIGTransmitterInfo
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in MultimediaCapabilityInfoTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MULTIMEDIA_CAPABILITY_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulSignature
decl_stmt|;
comment|// HW info table signature string "$ATI"
name|UCHAR
name|ucI2C_Type
decl_stmt|;
comment|// I2C type (normal GP_IO, ImpactTV GP_IO, Dedicated I2C pin, etc)
name|UCHAR
name|ucTV_OutInfo
decl_stmt|;
comment|// Type of TV out supported (3:0) and video out crystal frequency (6:4) and TV data port (7)
name|UCHAR
name|ucVideoPortInfo
decl_stmt|;
comment|// Provides the video port capabilities
name|UCHAR
name|ucHostPortInfo
decl_stmt|;
comment|// Provides host port configuration information
block|}
name|ATOM_MULTIMEDIA_CAPABILITY_INFO
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in MultimediaConfigInfoTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MULTIMEDIA_CONFIG_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulSignature
decl_stmt|;
comment|// MM info table signature sting "$MMT"
name|UCHAR
name|ucTunerInfo
decl_stmt|;
comment|// Type of tuner installed on the adapter (4:0) and video input for tuner (7:5)
name|UCHAR
name|ucAudioChipInfo
decl_stmt|;
comment|// List the audio chip type (3:0) product type (4) and OEM revision (7:5)
name|UCHAR
name|ucProductID
decl_stmt|;
comment|// Defines as OEM ID or ATI board ID dependent on product type setting
name|UCHAR
name|ucMiscInfo1
decl_stmt|;
comment|// Tuner voltage (1:0) HW teletext support (3:2) FM audio decoder (5:4) reserved (6) audio scrambling (7)
name|UCHAR
name|ucMiscInfo2
decl_stmt|;
comment|// I2S input config (0) I2S output config (1) I2S Audio Chip (4:2) SPDIF Output Config (5) reserved (7:6)
name|UCHAR
name|ucMiscInfo3
decl_stmt|;
comment|// Video Decoder Type (3:0) Video In Standard/Crystal (7:4)
name|UCHAR
name|ucMiscInfo4
decl_stmt|;
comment|// Video Decoder Host Config (2:0) reserved (7:3)
name|UCHAR
name|ucVideoInput0Info
decl_stmt|;
comment|// Video Input 0 Type (1:0) F/B setting (2) physical connector ID (5:3) reserved (7:6)
name|UCHAR
name|ucVideoInput1Info
decl_stmt|;
comment|// Video Input 1 Type (1:0) F/B setting (2) physical connector ID (5:3) reserved (7:6)
name|UCHAR
name|ucVideoInput2Info
decl_stmt|;
comment|// Video Input 2 Type (1:0) F/B setting (2) physical connector ID (5:3) reserved (7:6)
name|UCHAR
name|ucVideoInput3Info
decl_stmt|;
comment|// Video Input 3 Type (1:0) F/B setting (2) physical connector ID (5:3) reserved (7:6)
name|UCHAR
name|ucVideoInput4Info
decl_stmt|;
comment|// Video Input 4 Type (1:0) F/B setting (2) physical connector ID (5:3) reserved (7:6)
block|}
name|ATOM_MULTIMEDIA_CONFIG_INFO
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used in FirmwareInfoTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// usBIOSCapability Definition:
end_comment

begin_comment
comment|// Bit 0 = 0: Bios image is not Posted, =1:Bios image is Posted;
end_comment

begin_comment
comment|// Bit 1 = 0: Dual CRTC is not supported, =1: Dual CRTC is supported;
end_comment

begin_comment
comment|// Bit 2 = 0: Extended Desktop is not supported, =1: Extended Desktop is supported;
end_comment

begin_comment
comment|// Others: Reserved
end_comment

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_ATOM_FIRMWARE_POSTED
value|0x0001
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_DUAL_CRTC_SUPPORT
value|0x0002
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_EXTENDED_DESKTOP_SUPPORT
value|0x0004
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_MEMORY_CLOCK_SS_SUPPORT
value|0x0008
end_define

begin_comment
comment|// (valid from v1.1 ~v1.4):=1: memclk SS enable, =0 memclk SS disable.
end_comment

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_ENGINE_CLOCK_SS_SUPPORT
value|0x0010
end_define

begin_comment
comment|// (valid from v1.1 ~v1.4):=1: engclk SS enable, =0 engclk SS disable.
end_comment

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_BL_CONTROLLED_BY_GPU
value|0x0020
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_WMI_SUPPORT
value|0x0040
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_PPMODE_ASSIGNGED_BY_SYSTEM
value|0x0080
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_HYPERMEMORY_SUPPORT
value|0x0100
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_HYPERMEMORY_SIZE_MASK
value|0x1E00
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_VPOST_WITHOUT_FIRST_MODE_SET
value|0x2000
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_BIOS_SCRATCH6_SCL2_REDEFINE
value|0x4000
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_MEMORY_CLOCK_EXT_SS_SUPPORT
value|0x0008
end_define

begin_comment
comment|// (valid from v2.1 ): =1: memclk ss enable with external ss chip
end_comment

begin_define
define|#
directive|define
name|ATOM_BIOS_INFO_ENGINE_CLOCK_EXT_SS_SUPPORT
value|0x0010
end_define

begin_comment
comment|// (valid from v2.1 ): =1: engclk ss enable with external ss chip
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H2INC
end_ifndef

begin_comment
comment|//Please don't add or expand this bitfield structure below, this one will retire soon.!
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_FIRMWARE_CAPABILITY
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|USHORT
name|Reserved
range|:
literal|1
decl_stmt|;
name|USHORT
name|SCL2Redefined
range|:
literal|1
decl_stmt|;
name|USHORT
name|PostWithoutModeSet
range|:
literal|1
decl_stmt|;
name|USHORT
name|HyperMemory_Size
range|:
literal|4
decl_stmt|;
name|USHORT
name|HyperMemory_Support
range|:
literal|1
decl_stmt|;
name|USHORT
name|PPMode_Assigned
range|:
literal|1
decl_stmt|;
name|USHORT
name|WMI_SUPPORT
range|:
literal|1
decl_stmt|;
name|USHORT
name|GPUControlsBL
range|:
literal|1
decl_stmt|;
name|USHORT
name|EngineClockSS_Support
range|:
literal|1
decl_stmt|;
name|USHORT
name|MemoryClockSS_Support
range|:
literal|1
decl_stmt|;
name|USHORT
name|ExtendedDesktopSupport
range|:
literal|1
decl_stmt|;
name|USHORT
name|DualCRTC_Support
range|:
literal|1
decl_stmt|;
name|USHORT
name|FirmwarePosted
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|USHORT
name|FirmwarePosted
range|:
literal|1
decl_stmt|;
name|USHORT
name|DualCRTC_Support
range|:
literal|1
decl_stmt|;
name|USHORT
name|ExtendedDesktopSupport
range|:
literal|1
decl_stmt|;
name|USHORT
name|MemoryClockSS_Support
range|:
literal|1
decl_stmt|;
name|USHORT
name|EngineClockSS_Support
range|:
literal|1
decl_stmt|;
name|USHORT
name|GPUControlsBL
range|:
literal|1
decl_stmt|;
name|USHORT
name|WMI_SUPPORT
range|:
literal|1
decl_stmt|;
name|USHORT
name|PPMode_Assigned
range|:
literal|1
decl_stmt|;
name|USHORT
name|HyperMemory_Support
range|:
literal|1
decl_stmt|;
name|USHORT
name|HyperMemory_Size
range|:
literal|4
decl_stmt|;
name|USHORT
name|PostWithoutModeSet
range|:
literal|1
decl_stmt|;
name|USHORT
name|SCL2Redefined
range|:
literal|1
decl_stmt|;
name|USHORT
name|Reserved
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
name|ATOM_FIRMWARE_CAPABILITY
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_ATOM_FIRMWARE_CAPABILITY_ACCESS
block|{
name|ATOM_FIRMWARE_CAPABILITY
name|sbfAccess
decl_stmt|;
name|USHORT
name|susAccess
decl_stmt|;
block|}
name|ATOM_FIRMWARE_CAPABILITY_ACCESS
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
union|union
name|_ATOM_FIRMWARE_CAPABILITY_ACCESS
block|{
name|USHORT
name|susAccess
decl_stmt|;
block|}
name|ATOM_FIRMWARE_CAPABILITY_ACCESS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_FIRMWARE_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulFirmwareRevision
decl_stmt|;
name|ULONG
name|ulDefaultEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDefaultMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDriverTargetEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDriverTargetMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxEngineClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxMemoryClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulASICMaxEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulASICMaxMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|UCHAR
name|ucASICMaxTemperature
decl_stmt|;
name|UCHAR
name|ucPadding
index|[
literal|3
index|]
decl_stmt|;
comment|//Don't use them
name|ULONG
name|aulReservedForBIOS
index|[
literal|3
index|]
decl_stmt|;
comment|//Don't use them
name|USHORT
name|usMinEngineClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxEngineClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinEngineClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinMemoryClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxMemoryClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinMemoryClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxPixelClock
decl_stmt|;
comment|//In 10Khz unit, Max.  Pclk
name|USHORT
name|usMinPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit, the definitions above can't change!!!
name|ATOM_FIRMWARE_CAPABILITY_ACCESS
name|usFirmwareCapability
decl_stmt|;
name|USHORT
name|usReferenceClock
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usPM_RTS_Location
decl_stmt|;
comment|//RTS PM4 starting location in ROM in 1Kb unit
name|UCHAR
name|ucPM_RTS_StreamSize
decl_stmt|;
comment|//RTS PM4 packets in Kb unit
name|UCHAR
name|ucDesign_ID
decl_stmt|;
comment|//Indicate what is the board design
name|UCHAR
name|ucMemoryModule_ID
decl_stmt|;
comment|//Indicate what is the board design
block|}
name|ATOM_FIRMWARE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_FIRMWARE_INFO_V1_2
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulFirmwareRevision
decl_stmt|;
name|ULONG
name|ulDefaultEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDefaultMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDriverTargetEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDriverTargetMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxEngineClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxMemoryClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulASICMaxEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulASICMaxMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|UCHAR
name|ucASICMaxTemperature
decl_stmt|;
name|UCHAR
name|ucMinAllowedBL_Level
decl_stmt|;
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
comment|//Don't use them
name|ULONG
name|aulReservedForBIOS
index|[
literal|2
index|]
decl_stmt|;
comment|//Don't use them
name|ULONG
name|ulMinPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinEngineClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxEngineClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinEngineClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinMemoryClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxMemoryClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinMemoryClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxPixelClock
decl_stmt|;
comment|//In 10Khz unit, Max.  Pclk
name|USHORT
name|usMinPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit - lower 16bit of ulMinPixelClockPLL_Output
name|ATOM_FIRMWARE_CAPABILITY_ACCESS
name|usFirmwareCapability
decl_stmt|;
name|USHORT
name|usReferenceClock
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usPM_RTS_Location
decl_stmt|;
comment|//RTS PM4 starting location in ROM in 1Kb unit
name|UCHAR
name|ucPM_RTS_StreamSize
decl_stmt|;
comment|//RTS PM4 packets in Kb unit
name|UCHAR
name|ucDesign_ID
decl_stmt|;
comment|//Indicate what is the board design
name|UCHAR
name|ucMemoryModule_ID
decl_stmt|;
comment|//Indicate what is the board design
block|}
name|ATOM_FIRMWARE_INFO_V1_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_FIRMWARE_INFO_V1_3
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulFirmwareRevision
decl_stmt|;
name|ULONG
name|ulDefaultEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDefaultMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDriverTargetEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDriverTargetMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxEngineClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxMemoryClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulASICMaxEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulASICMaxMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|UCHAR
name|ucASICMaxTemperature
decl_stmt|;
name|UCHAR
name|ucMinAllowedBL_Level
decl_stmt|;
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
comment|//Don't use them
name|ULONG
name|aulReservedForBIOS
decl_stmt|;
comment|//Don't use them
name|ULONG
name|ul3DAccelerationEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMinPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinEngineClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxEngineClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinEngineClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinMemoryClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxMemoryClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinMemoryClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxPixelClock
decl_stmt|;
comment|//In 10Khz unit, Max.  Pclk
name|USHORT
name|usMinPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit - lower 16bit of ulMinPixelClockPLL_Output
name|ATOM_FIRMWARE_CAPABILITY_ACCESS
name|usFirmwareCapability
decl_stmt|;
name|USHORT
name|usReferenceClock
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usPM_RTS_Location
decl_stmt|;
comment|//RTS PM4 starting location in ROM in 1Kb unit
name|UCHAR
name|ucPM_RTS_StreamSize
decl_stmt|;
comment|//RTS PM4 packets in Kb unit
name|UCHAR
name|ucDesign_ID
decl_stmt|;
comment|//Indicate what is the board design
name|UCHAR
name|ucMemoryModule_ID
decl_stmt|;
comment|//Indicate what is the board design
block|}
name|ATOM_FIRMWARE_INFO_V1_3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_FIRMWARE_INFO_V1_4
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulFirmwareRevision
decl_stmt|;
name|ULONG
name|ulDefaultEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDefaultMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDriverTargetEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDriverTargetMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxEngineClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxMemoryClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulASICMaxEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulASICMaxMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|UCHAR
name|ucASICMaxTemperature
decl_stmt|;
name|UCHAR
name|ucMinAllowedBL_Level
decl_stmt|;
name|USHORT
name|usBootUpVDDCVoltage
decl_stmt|;
comment|//In MV unit
name|USHORT
name|usLcdMinPixelClockPLL_Output
decl_stmt|;
comment|// In MHz unit
name|USHORT
name|usLcdMaxPixelClockPLL_Output
decl_stmt|;
comment|// In MHz unit
name|ULONG
name|ul3DAccelerationEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMinPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinEngineClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxEngineClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinEngineClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinMemoryClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxMemoryClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinMemoryClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxPixelClock
decl_stmt|;
comment|//In 10Khz unit, Max.  Pclk
name|USHORT
name|usMinPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit - lower 16bit of ulMinPixelClockPLL_Output
name|ATOM_FIRMWARE_CAPABILITY_ACCESS
name|usFirmwareCapability
decl_stmt|;
name|USHORT
name|usReferenceClock
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usPM_RTS_Location
decl_stmt|;
comment|//RTS PM4 starting location in ROM in 1Kb unit
name|UCHAR
name|ucPM_RTS_StreamSize
decl_stmt|;
comment|//RTS PM4 packets in Kb unit
name|UCHAR
name|ucDesign_ID
decl_stmt|;
comment|//Indicate what is the board design
name|UCHAR
name|ucMemoryModule_ID
decl_stmt|;
comment|//Indicate what is the board design
block|}
name|ATOM_FIRMWARE_INFO_V1_4
typedef|;
end_typedef

begin_comment
comment|//the structure below to be used from Cypress
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_FIRMWARE_INFO_V2_1
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulFirmwareRevision
decl_stmt|;
name|ULONG
name|ulDefaultEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDefaultMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulReserved1
decl_stmt|;
name|ULONG
name|ulReserved2
decl_stmt|;
name|ULONG
name|ulMaxEngineClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxMemoryClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulMaxPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulBinaryAlteredInfo
decl_stmt|;
comment|//Was ulASICMaxEngineClock
name|ULONG
name|ulDefaultDispEngineClkFreq
decl_stmt|;
comment|//In 10Khz unit
name|UCHAR
name|ucReserved1
decl_stmt|;
comment|//Was ucASICMaxTemperature;
name|UCHAR
name|ucMinAllowedBL_Level
decl_stmt|;
name|USHORT
name|usBootUpVDDCVoltage
decl_stmt|;
comment|//In MV unit
name|USHORT
name|usLcdMinPixelClockPLL_Output
decl_stmt|;
comment|// In MHz unit
name|USHORT
name|usLcdMaxPixelClockPLL_Output
decl_stmt|;
comment|// In MHz unit
name|ULONG
name|ulReserved4
decl_stmt|;
comment|//Was ulAsicMaximumVoltage
name|ULONG
name|ulMinPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinEngineClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxEngineClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinEngineClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinMemoryClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxMemoryClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinMemoryClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxPixelClock
decl_stmt|;
comment|//In 10Khz unit, Max.  Pclk
name|USHORT
name|usMinPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMinPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit - lower 16bit of ulMinPixelClockPLL_Output
name|ATOM_FIRMWARE_CAPABILITY_ACCESS
name|usFirmwareCapability
decl_stmt|;
name|USHORT
name|usCoreReferenceClock
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMemoryReferenceClock
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usUniphyDPModeExtClkFreq
decl_stmt|;
comment|//In 10Khz unit, if it is 0, In DP Mode Uniphy Input clock from internal PPLL, otherwise Input clock from external Spread clock
name|UCHAR
name|ucMemoryModule_ID
decl_stmt|;
comment|//Indicate what is the board design
name|UCHAR
name|ucReserved4
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ATOM_FIRMWARE_INFO_V2_1
typedef|;
end_typedef

begin_comment
comment|//the structure below to be used from NI
end_comment

begin_comment
comment|//ucTableFormatRevision=2
end_comment

begin_comment
comment|//ucTableContentRevision=2
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_FIRMWARE_INFO_V2_2
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulFirmwareRevision
decl_stmt|;
name|ULONG
name|ulDefaultEngineClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulDefaultMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulReserved
index|[
literal|2
index|]
decl_stmt|;
name|ULONG
name|ulReserved1
decl_stmt|;
comment|//Was ulMaxEngineClockPLL_Output; //In 10Khz unit*
name|ULONG
name|ulReserved2
decl_stmt|;
comment|//Was ulMaxMemoryClockPLL_Output; //In 10Khz unit*
name|ULONG
name|ulMaxPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|ULONG
name|ulBinaryAlteredInfo
decl_stmt|;
comment|//Was ulASICMaxEngineClock  ?
name|ULONG
name|ulDefaultDispEngineClkFreq
decl_stmt|;
comment|//In 10Khz unit. This is the frequency before DCDTO, corresponding to usBootUpVDDCVoltage.
name|UCHAR
name|ucReserved3
decl_stmt|;
comment|//Was ucASICMaxTemperature;
name|UCHAR
name|ucMinAllowedBL_Level
decl_stmt|;
name|USHORT
name|usBootUpVDDCVoltage
decl_stmt|;
comment|//In MV unit
name|USHORT
name|usLcdMinPixelClockPLL_Output
decl_stmt|;
comment|// In MHz unit
name|USHORT
name|usLcdMaxPixelClockPLL_Output
decl_stmt|;
comment|// In MHz unit
name|ULONG
name|ulReserved4
decl_stmt|;
comment|//Was ulAsicMaximumVoltage
name|ULONG
name|ulMinPixelClockPLL_Output
decl_stmt|;
comment|//In 10Khz unit
name|UCHAR
name|ucRemoteDisplayConfig
decl_stmt|;
name|UCHAR
name|ucReserved5
index|[
literal|3
index|]
decl_stmt|;
comment|//Was usMinEngineClockPLL_Input and usMaxEngineClockPLL_Input
name|ULONG
name|ulReserved6
decl_stmt|;
comment|//Was usMinEngineClockPLL_Output and usMinMemoryClockPLL_Input
name|ULONG
name|ulReserved7
decl_stmt|;
comment|//Was usMaxMemoryClockPLL_Input and usMinMemoryClockPLL_Output
name|USHORT
name|usReserved11
decl_stmt|;
comment|//Was usMaxPixelClock;  //In 10Khz unit, Max.  Pclk used only for DAC
name|USHORT
name|usMinPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMaxPixelClockPLL_Input
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usBootUpVDDCIVoltage
decl_stmt|;
comment|//In unit of mv; Was usMinPixelClockPLL_Output;
name|ATOM_FIRMWARE_CAPABILITY_ACCESS
name|usFirmwareCapability
decl_stmt|;
name|USHORT
name|usCoreReferenceClock
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usMemoryReferenceClock
decl_stmt|;
comment|//In 10Khz unit
name|USHORT
name|usUniphyDPModeExtClkFreq
decl_stmt|;
comment|//In 10Khz unit, if it is 0, In DP Mode Uniphy Input clock from internal PPLL, otherwise Input clock from external Spread clock
name|UCHAR
name|ucMemoryModule_ID
decl_stmt|;
comment|//Indicate what is the board design
name|UCHAR
name|ucReserved9
index|[
literal|3
index|]
decl_stmt|;
name|USHORT
name|usBootUpMVDDCVoltage
decl_stmt|;
comment|//In unit of mv; Was usMinPixelClockPLL_Output;
name|USHORT
name|usReserved12
decl_stmt|;
name|ULONG
name|ulReserved10
index|[
literal|3
index|]
decl_stmt|;
comment|// New added comparing to previous version
block|}
name|ATOM_FIRMWARE_INFO_V2_2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_FIRMWARE_INFO_LAST
value|ATOM_FIRMWARE_INFO_V2_2
end_define

begin_comment
comment|// definition of ucRemoteDisplayConfig
end_comment

begin_define
define|#
directive|define
name|REMOTE_DISPLAY_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|REMOTE_DISPLAY_ENABLE
value|0x01
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used in IntegratedSystemInfoTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|IGP_CAP_FLAG_DYNAMIC_CLOCK_EN
value|0x2
end_define

begin_define
define|#
directive|define
name|IGP_CAP_FLAG_AC_CARD
value|0x4
end_define

begin_define
define|#
directive|define
name|IGP_CAP_FLAG_SDVO_CARD
value|0x8
end_define

begin_define
define|#
directive|define
name|IGP_CAP_FLAG_POSTDIV_BY_2_MODE
value|0x10
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_INTEGRATED_SYSTEM_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulBootUpEngineClock
decl_stmt|;
comment|//in 10kHz unit
name|ULONG
name|ulBootUpMemoryClock
decl_stmt|;
comment|//in 10kHz unit
name|ULONG
name|ulMaxSystemMemoryClock
decl_stmt|;
comment|//in 10kHz unit
name|ULONG
name|ulMinSystemMemoryClock
decl_stmt|;
comment|//in 10kHz unit
name|UCHAR
name|ucNumberOfCyclesInPeriodHi
decl_stmt|;
name|UCHAR
name|ucLCDTimingSel
decl_stmt|;
comment|//=0:not valid.!=0 sel this timing descriptor from LCD EDID.
name|USHORT
name|usReserved1
decl_stmt|;
name|USHORT
name|usInterNBVoltageLow
decl_stmt|;
comment|//An intermidiate PMW value to set the voltage
name|USHORT
name|usInterNBVoltageHigh
decl_stmt|;
comment|//Another intermidiate PMW value to set the voltage
name|ULONG
name|ulReserved
index|[
literal|2
index|]
decl_stmt|;
name|USHORT
name|usFSBClock
decl_stmt|;
comment|//In MHz unit
name|USHORT
name|usCapabilityFlag
decl_stmt|;
comment|//Bit0=1 indicates the fake HDMI support,Bit1=0/1 for Dynamic clocking dis/enable
comment|//Bit[3:2]== 0:No PCIE card, 1:AC card, 2:SDVO card
comment|//Bit[4]==1: P/2 mode, ==0: P/1 mode
name|USHORT
name|usPCIENBCfgReg7
decl_stmt|;
comment|//bit[7:0]=MUX_Sel, bit[9:8]=MUX_SEL_LEVEL2, bit[10]=Lane_Reversal
name|USHORT
name|usK8MemoryClock
decl_stmt|;
comment|//in MHz unit
name|USHORT
name|usK8SyncStartDelay
decl_stmt|;
comment|//in 0.01 us unit
name|USHORT
name|usK8DataReturnTime
decl_stmt|;
comment|//in 0.01 us unit
name|UCHAR
name|ucMaxNBVoltage
decl_stmt|;
name|UCHAR
name|ucMinNBVoltage
decl_stmt|;
name|UCHAR
name|ucMemoryType
decl_stmt|;
comment|//[7:4]=1:DDR1;=2:DDR2;=3:DDR3.[3:0] is reserved
name|UCHAR
name|ucNumberOfCyclesInPeriod
decl_stmt|;
comment|//CG.FVTHROT_PWM_CTRL_REG0.NumberOfCyclesInPeriod
name|UCHAR
name|ucStartingPWM_HighTime
decl_stmt|;
comment|//CG.FVTHROT_PWM_CTRL_REG0.StartingPWM_HighTime
name|UCHAR
name|ucHTLinkWidth
decl_stmt|;
comment|//16 bit vs. 8 bit
name|UCHAR
name|ucMaxNBVoltageHigh
decl_stmt|;
name|UCHAR
name|ucMinNBVoltageHigh
decl_stmt|;
block|}
name|ATOM_INTEGRATED_SYSTEM_INFO
typedef|;
end_typedef

begin_comment
comment|/* Explanation on entries in ATOM_INTEGRATED_SYSTEM_INFO ulBootUpMemoryClock:    For Intel IGP,it's the UMA system memory clock                          For AMD IGP,it's 0 if no SidePort memory installed or it's the boot-up SidePort memory clock ulMaxSystemMemoryClock: For Intel IGP,it's the Max freq from memory SPD if memory runs in ASYNC mode or otherwise (SYNC mode) it's 0                         For AMD IGP,for now this can be 0 ulMinSystemMemoryClock: For Intel IGP,it's 133MHz if memory runs in ASYNC mode or otherwise (SYNC mode) it's 0                          For AMD IGP,for now this can be 0  usFSBClock:             For Intel IGP,it's FSB Freq                          For AMD IGP,it's HT Link Speed  usK8MemoryClock:        For AMD IGP only. For RevF CPU, set it to 200 usK8SyncStartDelay:     For AMD IGP only. Memory access latency in K8, required for watermark calculation usK8DataReturnTime:     For AMD IGP only. Memory access latency in K8, required for watermark calculation  VC:Voltage Control ucMaxNBVoltage:         Voltage regulator dependent PWM value. Low 8 bits of the value for the max voltage.Set this one to 0xFF if VC without PWM. Set this to 0x0 if no VC at all. ucMinNBVoltage:         Voltage regulator dependent PWM value. Low 8 bits of the value for the min voltage.Set this one to 0x00 if VC without PWM or no VC at all.  ucNumberOfCyclesInPeriod:   Indicate how many cycles when PWM duty is 100%. low 8 bits of the value.  ucNumberOfCyclesInPeriodHi: Indicate how many cycles when PWM duty is 100%. high 8 bits of the value.If the PWM has an inverter,set bit [7]==1,otherwise set it 0   ucMaxNBVoltageHigh:     Voltage regulator dependent PWM value. High 8 bits of  the value for the max voltage.Set this one to 0xFF if VC without PWM. Set this to 0x0 if no VC at all. ucMinNBVoltageHigh:     Voltage regulator dependent PWM value. High 8 bits of the value for the min voltage.Set this one to 0x00 if VC without PWM or no VC at all.   usInterNBVoltageLow:    Voltage regulator dependent PWM value. The value makes the the voltage>=Min NB voltage but<=InterNBVoltageHigh. Set this to 0x0000 if VC without PWM or no VC at all. usInterNBVoltageHigh:   Voltage regulator dependent PWM value. The value makes the the voltage>=InterNBVoltageLow but<=Max NB voltage.Set this to 0x0000 if VC without PWM or no VC at all. */
end_comment

begin_comment
comment|/* The following IGP table is introduced from RS780, which is supposed to be put by SBIOS in FB before IGP VBIOS starts VPOST; Then VBIOS will copy the whole structure to its image so all GPU SW components can access this data structure to get whatever they need.  The enough reservation should allow us to never change table revisions. Whenever needed, a GPU SW component can use reserved portion for new data entries.  SW components can access the IGP system infor structure in the same way as before */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_INTEGRATED_SYSTEM_INFO_V2
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulBootUpEngineClock
decl_stmt|;
comment|//in 10kHz unit
name|ULONG
name|ulReserved1
index|[
literal|2
index|]
decl_stmt|;
comment|//must be 0x0 for the reserved
name|ULONG
name|ulBootUpUMAClock
decl_stmt|;
comment|//in 10kHz unit
name|ULONG
name|ulBootUpSidePortClock
decl_stmt|;
comment|//in 10kHz unit
name|ULONG
name|ulMinSidePortClock
decl_stmt|;
comment|//in 10kHz unit
name|ULONG
name|ulReserved2
index|[
literal|6
index|]
decl_stmt|;
comment|//must be 0x0 for the reserved
name|ULONG
name|ulSystemConfig
decl_stmt|;
comment|//see explanation below
name|ULONG
name|ulBootUpReqDisplayVector
decl_stmt|;
name|ULONG
name|ulOtherDisplayMisc
decl_stmt|;
name|ULONG
name|ulDDISlot1Config
decl_stmt|;
name|ULONG
name|ulDDISlot2Config
decl_stmt|;
name|UCHAR
name|ucMemoryType
decl_stmt|;
comment|//[3:0]=1:DDR1;=2:DDR2;=3:DDR3.[7:4] is reserved
name|UCHAR
name|ucUMAChannelNumber
decl_stmt|;
name|UCHAR
name|ucDockingPinBit
decl_stmt|;
name|UCHAR
name|ucDockingPinPolarity
decl_stmt|;
name|ULONG
name|ulDockingPinCFGInfo
decl_stmt|;
name|ULONG
name|ulCPUCapInfo
decl_stmt|;
name|USHORT
name|usNumberOfCyclesInPeriod
decl_stmt|;
name|USHORT
name|usMaxNBVoltage
decl_stmt|;
name|USHORT
name|usMinNBVoltage
decl_stmt|;
name|USHORT
name|usBootUpNBVoltage
decl_stmt|;
name|ULONG
name|ulHTLinkFreq
decl_stmt|;
comment|//in 10Khz
name|USHORT
name|usMinHTLinkWidth
decl_stmt|;
name|USHORT
name|usMaxHTLinkWidth
decl_stmt|;
name|USHORT
name|usUMASyncStartDelay
decl_stmt|;
name|USHORT
name|usUMADataReturnTime
decl_stmt|;
name|USHORT
name|usLinkStatusZeroTime
decl_stmt|;
name|USHORT
name|usDACEfuse
decl_stmt|;
comment|//for storing badgap value (for RS880 only)
name|ULONG
name|ulHighVoltageHTLinkFreq
decl_stmt|;
comment|// in 10Khz
name|ULONG
name|ulLowVoltageHTLinkFreq
decl_stmt|;
comment|// in 10Khz
name|USHORT
name|usMaxUpStreamHTLinkWidth
decl_stmt|;
name|USHORT
name|usMaxDownStreamHTLinkWidth
decl_stmt|;
name|USHORT
name|usMinUpStreamHTLinkWidth
decl_stmt|;
name|USHORT
name|usMinDownStreamHTLinkWidth
decl_stmt|;
name|USHORT
name|usFirmwareVersion
decl_stmt|;
comment|//0 means FW is not supported. Otherwise it's the FW version loaded by SBIOS and driver should enable FW.
name|USHORT
name|usFullT0Time
decl_stmt|;
comment|// Input to calculate minimum HT link change time required by NB P-State. Unit is 0.01us.
name|ULONG
name|ulReserved3
index|[
literal|96
index|]
decl_stmt|;
comment|//must be 0x0
block|}
name|ATOM_INTEGRATED_SYSTEM_INFO_V2
typedef|;
end_typedef

begin_comment
comment|/* ulBootUpEngineClock:   Boot-up Engine Clock in 10Khz; ulBootUpUMAClock:      Boot-up UMA Clock in 10Khz; it must be 0x0 when UMA is not present ulBootUpSidePortClock: Boot-up SidePort Clock in 10Khz; it must be 0x0 when SidePort Memory is not present,this could be equal to or less than maximum supported Sideport memory clock  ulSystemConfig:   Bit[0]=1: PowerExpress mode =0 Non-PowerExpress mode;  Bit[1]=1: system boots up at AMD overdrived state or user customized  mode. In this case, driver will just stick to this boot-up mode. No other PowerPlay state       =0: system boots up at driver control state. Power state depends on PowerPlay table. Bit[2]=1: PWM method is used on NB voltage control. =0: GPIO method is used. Bit[3]=1: Only one power state(Performance) will be supported.       =0: Multiple power states supported from PowerPlay table. Bit[4]=1: CLMC is supported and enabled on current system.        =0: CLMC is not supported or enabled on current system. SBIOS need to support HT link/freq change through ATIF interface.   Bit[5]=1: Enable CDLW for all driver control power states. Max HT width is from SBIOS, while Min HT width is determined by display requirement.         =0: CDLW is disabled. If CLMC is enabled case, Min HT width will be set equal to Max HT width. If CLMC disabled case, Max HT width will be applied. Bit[6]=1: High Voltage requested for all power states. In this case, voltage will be forced at 1.1v and powerplay table voltage drop/throttling request will be ignored.       =0: Voltage settings is determined by powerplay table. Bit[7]=1: Enable CLMC as hybrid Mode. CDLD and CILR will be disabled in this case and we're using legacy C1E. This is workaround for CPU(Griffin) performance issue.       =0: Enable CLMC as regular mode, CDLD and CILR will be enabled. Bit[8]=1: CDLF is supported and enabled on current system.       =0: CDLF is not supported or enabled on current system. Bit[9]=1: DLL Shut Down feature is enabled on current system.       =0: DLL Shut Down feature is not enabled or supported on current system.  ulBootUpReqDisplayVector: This dword is a bit vector indicates what display devices are requested during boot-up. Refer to ATOM_DEVICE_xxx_SUPPORT for the bit vector definitions.  ulOtherDisplayMisc: [15:8]- Bootup LCD Expansion selection; 0-center, 1-full panel size expansion; 			              [7:0] - BootupTV standard selection; This is a bit vector to indicate what TV standards are supported by the system. Refer to ucTVSupportedStd definition;  ulDDISlot1Config: Describes the PCIE lane configuration on this DDI PCIE slot (ADD2 card) or connector (Mobile design).       [3:0]  - Bit vector to indicate PCIE lane config of the DDI slot/connector on chassis (bit 0=1 lane 3:0; bit 1=1 lane 7:4; bit 2=1 lane 11:8; bit 3=1 lane 15:12) 			[7:4]  - Bit vector to indicate PCIE lane config of the same DDI slot/connector on docking station (bit 4=1 lane 3:0; bit 5=1 lane 7:4; bit 6=1 lane 11:8; bit 7=1 lane 15:12)       When a DDI connector is not "paired" (meaming two connections mutualexclusive on chassis or docking, only one of them can be connected at one time.       in both chassis and docking, SBIOS has to duplicate the same PCIE lane info from chassis to docking or vice versa. For example:       one DDI connector is only populated in docking with PCIE lane 8-11, but there is no paired connection on chassis, SBIOS has to copy bit 6 to bit 2.  			[15:8] - Lane configuration attribute;        [23:16]- Connector type, possible value:                CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_D                CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_D                CONNECTOR_OBJECT_ID_HDMI_TYPE_A                CONNECTOR_OBJECT_ID_DISPLAYPORT                CONNECTOR_OBJECT_ID_eDP 			[31:24]- Reserved  ulDDISlot2Config: Same as Slot1. ucMemoryType: SidePort memory type, set it to 0x0 when Sideport memory is not installed. Driver needs this info to change sideport memory clock. Not for display in CCC. For IGP, Hypermemory is the only memory type showed in CCC.  ucUMAChannelNumber:  how many channels for the UMA;  ulDockingPinCFGInfo: [15:0]-Bus/Device/Function # to CFG to read this Docking Pin; [31:16]-reg offset in CFG to read this pin  ucDockingPinBit:     which bit in this register to read the pin status; ucDockingPinPolarity:Polarity of the pin when docked;  ulCPUCapInfo:        [7:0]=1:Griffin;[7:0]=2:Greyhound;[7:0]=3:K8, [7:0]=4:Pharaoh, other bits reserved for now and must be 0x0  usNumberOfCyclesInPeriod:Indicate how many cycles when PWM duty is 100%.  usMaxNBVoltage:Max. voltage control value in either PWM or GPIO mode.  usMinNBVoltage:Min. voltage control value in either PWM or GPIO mode.                     GPIO mode: both usMaxNBVoltage& usMinNBVoltage have a valid value ulSystemConfig.SYSTEM_CONFIG_USE_PWM_ON_VOLTAGE=0                     PWM mode: both usMaxNBVoltage& usMinNBVoltage have a valid value ulSystemConfig.SYSTEM_CONFIG_USE_PWM_ON_VOLTAGE=1                     GPU SW don't control mode: usMaxNBVoltage& usMinNBVoltage=0 and no care about ulSystemConfig.SYSTEM_CONFIG_USE_PWM_ON_VOLTAGE  usBootUpNBVoltage:Boot-up voltage regulator dependent PWM value.  ulHTLinkFreq:       Bootup HT link Frequency in 10Khz. usMinHTLinkWidth:   Bootup minimum HT link width. If CDLW disabled, this is equal to usMaxHTLinkWidth.                      If CDLW enabled, both upstream and downstream width should be the same during bootup. usMaxHTLinkWidth:   Bootup maximum HT link width. If CDLW disabled, this is equal to usMinHTLinkWidth.                      If CDLW enabled, both upstream and downstream width should be the same during bootup.    usUMASyncStartDelay: Memory access latency, required for watermark calculation  usUMADataReturnTime: Memory access latency, required for watermark calculation usLinkStatusZeroTime:Memory access latency required for watermark calculation, set this to 0x0 for K8 CPU, set a proper value in 0.01 the unit of us  for Griffin or Greyhound. SBIOS needs to convert to actual time by:                      if T0Ttime [5:4]=00b, then usLinkStatusZeroTime=T0Ttime [3:0]*0.1us (0.0 to 1.5us)                      if T0Ttime [5:4]=01b, then usLinkStatusZeroTime=T0Ttime [3:0]*0.5us (0.0 to 7.5us)                      if T0Ttime [5:4]=10b, then usLinkStatusZeroTime=T0Ttime [3:0]*2.0us (0.0 to 30us)                      if T0Ttime [5:4]=11b, and T0Ttime [3:0]=0x0 to 0xa, then usLinkStatusZeroTime=T0Ttime [3:0]*20us (0.0 to 200us)  ulHighVoltageHTLinkFreq:     HT link frequency for power state with low voltage. If boot up runs in HT1, this must be 0.                              This must be less than or equal to ulHTLinkFreq(bootup frequency).  ulLowVoltageHTLinkFreq:      HT link frequency for power state with low voltage or voltage scaling 1.0v~1.1v. If boot up runs in HT1, this must be 0.                              This must be less than or equal to ulHighVoltageHTLinkFreq.  usMaxUpStreamHTLinkWidth:    Asymmetric link width support in the future, to replace usMaxHTLinkWidth. Not used for now. usMaxDownStreamHTLinkWidth:  same as above. usMinUpStreamHTLinkWidth:    Asymmetric link width support in the future, to replace usMinHTLinkWidth. Not used for now. usMinDownStreamHTLinkWidth:  same as above. */
end_comment

begin_comment
comment|// ATOM_INTEGRATED_SYSTEM_INFO::ulCPUCapInfo  - CPU type definition
end_comment

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO__UNKNOWN_CPU
value|0
end_define

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO__AMD_CPU__GRIFFIN
value|1
end_define

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO__AMD_CPU__GREYHOUND
value|2
end_define

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO__AMD_CPU__K8
value|3
end_define

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO__AMD_CPU__PHARAOH
value|4
end_define

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO__AMD_CPU__OROCHI
value|5
end_define

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO__AMD_CPU__MAX_CODE
value|INTEGRATED_SYSTEM_INFO__AMD_CPU__OROCHI
end_define

begin_comment
comment|// this deff reflects max defined CPU code
end_comment

begin_define
define|#
directive|define
name|SYSTEM_CONFIG_POWEREXPRESS_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SYSTEM_CONFIG_RUN_AT_OVERDRIVE_ENGINE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SYSTEM_CONFIG_USE_PWM_ON_VOLTAGE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SYSTEM_CONFIG_PERFORMANCE_POWERSTATE_ONLY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SYSTEM_CONFIG_CLMC_ENABLED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SYSTEM_CONFIG_CDLW_ENABLED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SYSTEM_CONFIG_HIGH_VOLTAGE_REQUESTED
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SYSTEM_CONFIG_CLMC_HYBRID_MODE_ENABLED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SYSTEM_CONFIG_CDLF_ENABLED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SYSTEM_CONFIG_DLL_SHUTDOWN_ENABLED
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IGP_DDI_SLOT_LANE_CONFIG_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|b0IGP_DDI_SLOT_LANE_MAP_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|b0IGP_DDI_SLOT_DOCKING_LANE_MAP_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|b0IGP_DDI_SLOT_CONFIG_LANE_0_3
value|0x01
end_define

begin_define
define|#
directive|define
name|b0IGP_DDI_SLOT_CONFIG_LANE_4_7
value|0x02
end_define

begin_define
define|#
directive|define
name|b0IGP_DDI_SLOT_CONFIG_LANE_8_11
value|0x04
end_define

begin_define
define|#
directive|define
name|b0IGP_DDI_SLOT_CONFIG_LANE_12_15
value|0x08
end_define

begin_define
define|#
directive|define
name|IGP_DDI_SLOT_ATTRIBUTE_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|IGP_DDI_SLOT_CONFIG_REVERSED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|b1IGP_DDI_SLOT_CONFIG_REVERSED
value|0x01
end_define

begin_define
define|#
directive|define
name|IGP_DDI_SLOT_CONNECTOR_TYPE_MASK
value|0x00FF0000
end_define

begin_comment
comment|// IntegratedSystemInfoTable new Rev is V5 after V2, because of the real rev of V2 is v1.4. This rev is used for RR
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_INTEGRATED_SYSTEM_INFO_V5
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulBootUpEngineClock
decl_stmt|;
comment|//in 10kHz unit
name|ULONG
name|ulDentistVCOFreq
decl_stmt|;
comment|//Dentist VCO clock in 10kHz unit, the source of GPU SCLK, LCLK, UCLK and VCLK.
name|ULONG
name|ulLClockFreq
decl_stmt|;
comment|//GPU Lclk freq in 10kHz unit, have relationship with NCLK in NorthBridge
name|ULONG
name|ulBootUpUMAClock
decl_stmt|;
comment|//in 10kHz unit
name|ULONG
name|ulReserved1
index|[
literal|8
index|]
decl_stmt|;
comment|//must be 0x0 for the reserved
name|ULONG
name|ulBootUpReqDisplayVector
decl_stmt|;
name|ULONG
name|ulOtherDisplayMisc
decl_stmt|;
name|ULONG
name|ulReserved2
index|[
literal|4
index|]
decl_stmt|;
comment|//must be 0x0 for the reserved
name|ULONG
name|ulSystemConfig
decl_stmt|;
comment|//TBD
name|ULONG
name|ulCPUCapInfo
decl_stmt|;
comment|//TBD
name|USHORT
name|usMaxNBVoltage
decl_stmt|;
comment|//high NB voltage, calculated using current VDDNB (D24F2xDC) and VDDNB offset fuse;
name|USHORT
name|usMinNBVoltage
decl_stmt|;
comment|//low NB voltage, calculated using current VDDNB (D24F2xDC) and VDDNB offset fuse;
name|USHORT
name|usBootUpNBVoltage
decl_stmt|;
comment|//boot up NB voltage
name|UCHAR
name|ucHtcTmpLmt
decl_stmt|;
comment|//bit [22:16] of D24F3x64 Hardware Thermal Control (HTC) Register, may not be needed, TBD
name|UCHAR
name|ucTjOffset
decl_stmt|;
comment|//bit [28:22] of D24F3xE4 Thermtrip Status Register,may not be needed, TBD
name|ULONG
name|ulReserved3
index|[
literal|4
index|]
decl_stmt|;
comment|//must be 0x0 for the reserved
name|ULONG
name|ulDDISlot1Config
decl_stmt|;
comment|//see above ulDDISlot1Config definition
name|ULONG
name|ulDDISlot2Config
decl_stmt|;
name|ULONG
name|ulDDISlot3Config
decl_stmt|;
name|ULONG
name|ulDDISlot4Config
decl_stmt|;
name|ULONG
name|ulReserved4
index|[
literal|4
index|]
decl_stmt|;
comment|//must be 0x0 for the reserved
name|UCHAR
name|ucMemoryType
decl_stmt|;
comment|//[3:0]=1:DDR1;=2:DDR2;=3:DDR3.[7:4] is reserved
name|UCHAR
name|ucUMAChannelNumber
decl_stmt|;
name|USHORT
name|usReserved
decl_stmt|;
name|ULONG
name|ulReserved5
index|[
literal|4
index|]
decl_stmt|;
comment|//must be 0x0 for the reserved
name|ULONG
name|ulCSR_M3_ARB_CNTL_DEFAULT
index|[
literal|10
index|]
decl_stmt|;
comment|//arrays with values for CSR M3 arbiter for default
name|ULONG
name|ulCSR_M3_ARB_CNTL_UVD
index|[
literal|10
index|]
decl_stmt|;
comment|//arrays with values for CSR M3 arbiter for UVD playback
name|ULONG
name|ulCSR_M3_ARB_CNTL_FS3D
index|[
literal|10
index|]
decl_stmt|;
comment|//arrays with values for CSR M3 arbiter for Full Screen 3D applications
name|ULONG
name|ulReserved6
index|[
literal|61
index|]
decl_stmt|;
comment|//must be 0x0
block|}
name|ATOM_INTEGRATED_SYSTEM_INFO_V5
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_CRT_INT_ENCODER1_INDEX
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATOM_LCD_INT_ENCODER1_INDEX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATOM_TV_INT_ENCODER1_INDEX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATOM_DFP_INT_ENCODER1_INDEX
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ATOM_CRT_INT_ENCODER2_INDEX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATOM_LCD_EXT_ENCODER1_INDEX
value|0x00000005
end_define

begin_define
define|#
directive|define
name|ATOM_TV_EXT_ENCODER1_INDEX
value|0x00000006
end_define

begin_define
define|#
directive|define
name|ATOM_DFP_EXT_ENCODER1_INDEX
value|0x00000007
end_define

begin_define
define|#
directive|define
name|ATOM_CV_INT_ENCODER1_INDEX
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ATOM_DFP_INT_ENCODER2_INDEX
value|0x00000009
end_define

begin_define
define|#
directive|define
name|ATOM_CRT_EXT_ENCODER1_INDEX
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|ATOM_CV_EXT_ENCODER1_INDEX
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|ATOM_DFP_INT_ENCODER3_INDEX
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|ATOM_DFP_INT_ENCODER4_INDEX
value|0x0000000D
end_define

begin_comment
comment|// define ASIC internal encoder id ( bit vector ), used for CRTC_SourceSelTable
end_comment

begin_define
define|#
directive|define
name|ASIC_INT_DAC1_ENCODER_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|ASIC_INT_TV_ENCODER_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|ASIC_INT_DIG1_ENCODER_ID
value|0x03
end_define

begin_define
define|#
directive|define
name|ASIC_INT_DAC2_ENCODER_ID
value|0x04
end_define

begin_define
define|#
directive|define
name|ASIC_EXT_TV_ENCODER_ID
value|0x06
end_define

begin_define
define|#
directive|define
name|ASIC_INT_DVO_ENCODER_ID
value|0x07
end_define

begin_define
define|#
directive|define
name|ASIC_INT_DIG2_ENCODER_ID
value|0x09
end_define

begin_define
define|#
directive|define
name|ASIC_EXT_DIG_ENCODER_ID
value|0x05
end_define

begin_define
define|#
directive|define
name|ASIC_EXT_DIG2_ENCODER_ID
value|0x08
end_define

begin_define
define|#
directive|define
name|ASIC_INT_DIG3_ENCODER_ID
value|0x0a
end_define

begin_define
define|#
directive|define
name|ASIC_INT_DIG4_ENCODER_ID
value|0x0b
end_define

begin_define
define|#
directive|define
name|ASIC_INT_DIG5_ENCODER_ID
value|0x0c
end_define

begin_define
define|#
directive|define
name|ASIC_INT_DIG6_ENCODER_ID
value|0x0d
end_define

begin_define
define|#
directive|define
name|ASIC_INT_DIG7_ENCODER_ID
value|0x0e
end_define

begin_comment
comment|//define Encoder attribute
end_comment

begin_define
define|#
directive|define
name|ATOM_ANALOG_ENCODER
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_DIGITAL_ENCODER
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_DP_ENCODER
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_ENUM_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_ENUM_ID1
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_ENUM_ID2
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_ENUM_ID3
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_ENUM_ID4
value|0x30
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_ENUM_ID5
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_ENUM_ID6
value|0x50
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CRT1_INDEX
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_LCD1_INDEX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_TV1_INDEX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP1_INDEX
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CRT2_INDEX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_LCD2_INDEX
value|0x00000005
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP6_INDEX
value|0x00000006
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP2_INDEX
value|0x00000007
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CV_INDEX
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP3_INDEX
value|0x00000009
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP4_INDEX
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP5_INDEX
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_RESERVEDC_INDEX
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_RESERVEDD_INDEX
value|0x0000000D
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_RESERVEDE_INDEX
value|0x0000000E
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_RESERVEDF_INDEX
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|ATOM_MAX_SUPPORTED_DEVICE_INFO
value|(ATOM_DEVICE_DFP3_INDEX+1)
end_define

begin_define
define|#
directive|define
name|ATOM_MAX_SUPPORTED_DEVICE_INFO_2
value|ATOM_MAX_SUPPORTED_DEVICE_INFO
end_define

begin_define
define|#
directive|define
name|ATOM_MAX_SUPPORTED_DEVICE_INFO_3
value|(ATOM_DEVICE_DFP5_INDEX + 1 )
end_define

begin_define
define|#
directive|define
name|ATOM_MAX_SUPPORTED_DEVICE
value|(ATOM_DEVICE_RESERVEDF_INDEX+1)
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CRT1_SUPPORT
value|(0x1L<< ATOM_DEVICE_CRT1_INDEX )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_LCD1_SUPPORT
value|(0x1L<< ATOM_DEVICE_LCD1_INDEX )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_TV1_SUPPORT
value|(0x1L<< ATOM_DEVICE_TV1_INDEX  )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP1_SUPPORT
value|(0x1L<< ATOM_DEVICE_DFP1_INDEX )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CRT2_SUPPORT
value|(0x1L<< ATOM_DEVICE_CRT2_INDEX )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_LCD2_SUPPORT
value|(0x1L<< ATOM_DEVICE_LCD2_INDEX )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP6_SUPPORT
value|(0x1L<< ATOM_DEVICE_DFP6_INDEX )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP2_SUPPORT
value|(0x1L<< ATOM_DEVICE_DFP2_INDEX )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CV_SUPPORT
value|(0x1L<< ATOM_DEVICE_CV_INDEX   )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP3_SUPPORT
value|(0x1L<< ATOM_DEVICE_DFP3_INDEX )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP4_SUPPORT
value|(0x1L<< ATOM_DEVICE_DFP4_INDEX )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP5_SUPPORT
value|(0x1L<< ATOM_DEVICE_DFP5_INDEX )
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CRT_SUPPORT
value|(ATOM_DEVICE_CRT1_SUPPORT | ATOM_DEVICE_CRT2_SUPPORT)
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP_SUPPORT
value|(ATOM_DEVICE_DFP1_SUPPORT | ATOM_DEVICE_DFP2_SUPPORT |  ATOM_DEVICE_DFP3_SUPPORT | ATOM_DEVICE_DFP4_SUPPORT | ATOM_DEVICE_DFP5_SUPPORT | ATOM_DEVICE_DFP6_SUPPORT)
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_TV_SUPPORT
value|(ATOM_DEVICE_TV1_SUPPORT)
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_LCD_SUPPORT
value|(ATOM_DEVICE_LCD1_SUPPORT | ATOM_DEVICE_LCD2_SUPPORT)
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_TYPE_MASK
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_TYPE_SHIFT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_VGA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_DVI_I
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_DVI_D
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_DVI_A
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_SVIDEO
value|0x00000005
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_COMPOSITE
value|0x00000006
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_LVDS
value|0x00000007
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_DIGI_LINK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_SCART
value|0x00000009
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_HDMI_TYPE_A
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_HDMI_TYPE_B
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_CASE_1
value|0x0000000E
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECTOR_DISPLAYPORT
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DAC_INFO_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DAC_INFO_SHIFT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DAC_INFO_NODAC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DAC_INFO_DACA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DAC_INFO_DACB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DAC_INFO_EXDAC
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_I2C_ID_NOI2C
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_I2C_LINEMUX_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_I2C_LINEMUX_SHIFT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_I2C_ID_MASK
value|0x00000070
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_I2C_ID_SHIFT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_I2C_ID_IS_FOR_NON_MM_USE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_I2C_ID_IS_FOR_MM_USE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_I2C_ID_IS_FOR_SDVO_USE
value|0x00000003
end_define

begin_comment
comment|//For IGP RS600
end_comment

begin_define
define|#
directive|define
name|ATOM_DEVICE_I2C_ID_IS_FOR_DAC_SCL
value|0x00000004
end_define

begin_comment
comment|//For IGP RS690
end_comment

begin_define
define|#
directive|define
name|ATOM_DEVICE_I2C_HARDWARE_CAP_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_I2C_HARDWARE_CAP_SHIFT
value|0x00000007
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_USES_SOFTWARE_ASSISTED_I2C
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_USES_HARDWARE_ASSISTED_I2C
value|0x00000001
end_define

begin_comment
comment|//  usDeviceSupport:
end_comment

begin_comment
comment|//  Bits0	= 0 - no CRT1 support= 1- CRT1 is supported
end_comment

begin_comment
comment|//  Bit 1	= 0 - no LCD1 support= 1- LCD1 is supported
end_comment

begin_comment
comment|//  Bit 2	= 0 - no TV1  support= 1- TV1  is supported
end_comment

begin_comment
comment|//  Bit 3	= 0 - no DFP1 support= 1- DFP1 is supported
end_comment

begin_comment
comment|//  Bit 4	= 0 - no CRT2 support= 1- CRT2 is supported
end_comment

begin_comment
comment|//  Bit 5	= 0 - no LCD2 support= 1- LCD2 is supported
end_comment

begin_comment
comment|//  Bit 6	= 0 - no DFP6 support= 1- DFP6 is supported
end_comment

begin_comment
comment|//  Bit 7	= 0 - no DFP2 support= 1- DFP2 is supported
end_comment

begin_comment
comment|//  Bit 8	= 0 - no CV   support= 1- CV   is supported
end_comment

begin_comment
comment|//  Bit 9	= 0 - no DFP3 support= 1- DFP3 is supported
end_comment

begin_comment
comment|//  Bit 10      = 0 - no DFP4 support= 1- DFP4 is supported
end_comment

begin_comment
comment|//  Bit 11      = 0 - no DFP5 support= 1- DFP5 is supported
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Structure used in MclkSS_InfoTable                                       */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|//		ucI2C_ConfigID
end_comment

begin_comment
comment|//    [7:0] - I2C LINE Associate ID
end_comment

begin_comment
comment|//          = 0   - no I2C
end_comment

begin_comment
comment|//    [7]		-	HW_Cap        =	1,  [6:0]=HW assisted I2C ID(HW line selection)
end_comment

begin_comment
comment|//                          =	0,  [6:0]=SW assisted I2C ID
end_comment

begin_comment
comment|//    [6-4]	- HW_ENGINE_ID  =	1,  HW engine for NON multimedia use
end_comment

begin_comment
comment|//                          =	2,	HW engine for Multimedia use
end_comment

begin_comment
comment|//                          =	3-7	Reserved for future I2C engines
end_comment

begin_comment
comment|//		[3-0] - I2C_LINE_MUX  = A Mux number when it's HW assisted I2C or GPIO ID when it's SW I2C
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_I2C_ID_CONFIG
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|bfHW_Capable
range|:
literal|1
decl_stmt|;
name|UCHAR
name|bfHW_EngineID
range|:
literal|3
decl_stmt|;
name|UCHAR
name|bfI2C_LineMux
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|UCHAR
name|bfI2C_LineMux
range|:
literal|4
decl_stmt|;
name|UCHAR
name|bfHW_EngineID
range|:
literal|3
decl_stmt|;
name|UCHAR
name|bfHW_Capable
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
name|ATOM_I2C_ID_CONFIG
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_ATOM_I2C_ID_CONFIG_ACCESS
block|{
name|ATOM_I2C_ID_CONFIG
name|sbfAccess
decl_stmt|;
name|UCHAR
name|ucAccess
decl_stmt|;
block|}
name|ATOM_I2C_ID_CONFIG_ACCESS
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in GPIO_I2C_InfoTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_GPIO_I2C_ASSIGMENT
block|{
name|USHORT
name|usClkMaskRegisterIndex
decl_stmt|;
name|USHORT
name|usClkEnRegisterIndex
decl_stmt|;
name|USHORT
name|usClkY_RegisterIndex
decl_stmt|;
name|USHORT
name|usClkA_RegisterIndex
decl_stmt|;
name|USHORT
name|usDataMaskRegisterIndex
decl_stmt|;
name|USHORT
name|usDataEnRegisterIndex
decl_stmt|;
name|USHORT
name|usDataY_RegisterIndex
decl_stmt|;
name|USHORT
name|usDataA_RegisterIndex
decl_stmt|;
name|ATOM_I2C_ID_CONFIG_ACCESS
name|sucI2cId
decl_stmt|;
name|UCHAR
name|ucClkMaskShift
decl_stmt|;
name|UCHAR
name|ucClkEnShift
decl_stmt|;
name|UCHAR
name|ucClkY_Shift
decl_stmt|;
name|UCHAR
name|ucClkA_Shift
decl_stmt|;
name|UCHAR
name|ucDataMaskShift
decl_stmt|;
name|UCHAR
name|ucDataEnShift
decl_stmt|;
name|UCHAR
name|ucDataY_Shift
decl_stmt|;
name|UCHAR
name|ucDataA_Shift
decl_stmt|;
name|UCHAR
name|ucReserved1
decl_stmt|;
name|UCHAR
name|ucReserved2
decl_stmt|;
block|}
name|ATOM_GPIO_I2C_ASSIGMENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_GPIO_I2C_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_GPIO_I2C_ASSIGMENT
name|asGPIO_Info
index|[
name|ATOM_MAX_SUPPORTED_DEVICE
index|]
decl_stmt|;
block|}
name|ATOM_GPIO_I2C_INFO
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Common Structure used in other structures
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H2INC
end_ifndef

begin_comment
comment|//Please don't add or expand this bitfield structure below, this one will retire soon.!
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MODE_MISC_INFO
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|USHORT
name|Reserved
range|:
literal|6
decl_stmt|;
name|USHORT
name|RGB888
range|:
literal|1
decl_stmt|;
name|USHORT
name|DoubleClock
range|:
literal|1
decl_stmt|;
name|USHORT
name|Interlace
range|:
literal|1
decl_stmt|;
name|USHORT
name|CompositeSync
range|:
literal|1
decl_stmt|;
name|USHORT
name|V_ReplicationBy2
range|:
literal|1
decl_stmt|;
name|USHORT
name|H_ReplicationBy2
range|:
literal|1
decl_stmt|;
name|USHORT
name|VerticalCutOff
range|:
literal|1
decl_stmt|;
name|USHORT
name|VSyncPolarity
range|:
literal|1
decl_stmt|;
comment|//0=Active High, 1=Active Low
name|USHORT
name|HSyncPolarity
range|:
literal|1
decl_stmt|;
comment|//0=Active High, 1=Active Low
name|USHORT
name|HorizontalCutOff
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|USHORT
name|HorizontalCutOff
range|:
literal|1
decl_stmt|;
name|USHORT
name|HSyncPolarity
range|:
literal|1
decl_stmt|;
comment|//0=Active High, 1=Active Low
name|USHORT
name|VSyncPolarity
range|:
literal|1
decl_stmt|;
comment|//0=Active High, 1=Active Low
name|USHORT
name|VerticalCutOff
range|:
literal|1
decl_stmt|;
name|USHORT
name|H_ReplicationBy2
range|:
literal|1
decl_stmt|;
name|USHORT
name|V_ReplicationBy2
range|:
literal|1
decl_stmt|;
name|USHORT
name|CompositeSync
range|:
literal|1
decl_stmt|;
name|USHORT
name|Interlace
range|:
literal|1
decl_stmt|;
name|USHORT
name|DoubleClock
range|:
literal|1
decl_stmt|;
name|USHORT
name|RGB888
range|:
literal|1
decl_stmt|;
name|USHORT
name|Reserved
range|:
literal|6
decl_stmt|;
endif|#
directive|endif
block|}
name|ATOM_MODE_MISC_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_ATOM_MODE_MISC_INFO_ACCESS
block|{
name|ATOM_MODE_MISC_INFO
name|sbfAccess
decl_stmt|;
name|USHORT
name|usAccess
decl_stmt|;
block|}
name|ATOM_MODE_MISC_INFO_ACCESS
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
union|union
name|_ATOM_MODE_MISC_INFO_ACCESS
block|{
name|USHORT
name|usAccess
decl_stmt|;
block|}
name|ATOM_MODE_MISC_INFO_ACCESS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// usModeMiscInfo-
end_comment

begin_define
define|#
directive|define
name|ATOM_H_CUTOFF
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_HSYNC_POLARITY
value|0x02
end_define

begin_comment
comment|//0=Active High, 1=Active Low
end_comment

begin_define
define|#
directive|define
name|ATOM_VSYNC_POLARITY
value|0x04
end_define

begin_comment
comment|//0=Active High, 1=Active Low
end_comment

begin_define
define|#
directive|define
name|ATOM_V_CUTOFF
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_H_REPLICATIONBY2
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_V_REPLICATIONBY2
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_COMPOSITESYNC
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_INTERLACE
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_DOUBLE_CLOCK_MODE
value|0x100
end_define

begin_define
define|#
directive|define
name|ATOM_RGB888_MODE
value|0x200
end_define

begin_comment
comment|//usRefreshRate-
end_comment

begin_define
define|#
directive|define
name|ATOM_REFRESH_43
value|43
end_define

begin_define
define|#
directive|define
name|ATOM_REFRESH_47
value|47
end_define

begin_define
define|#
directive|define
name|ATOM_REFRESH_56
value|56
end_define

begin_define
define|#
directive|define
name|ATOM_REFRESH_60
value|60
end_define

begin_define
define|#
directive|define
name|ATOM_REFRESH_65
value|65
end_define

begin_define
define|#
directive|define
name|ATOM_REFRESH_70
value|70
end_define

begin_define
define|#
directive|define
name|ATOM_REFRESH_72
value|72
end_define

begin_define
define|#
directive|define
name|ATOM_REFRESH_75
value|75
end_define

begin_define
define|#
directive|define
name|ATOM_REFRESH_85
value|85
end_define

begin_comment
comment|// ATOM_MODE_TIMING data are exactly the same as VESA timing data.
end_comment

begin_comment
comment|// Translation from EDID to ATOM_MODE_TIMING, use the following formula.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//	VESA_HTOTAL			=	VESA_ACTIVE + 2* VESA_BORDER + VESA_BLANK
end_comment

begin_comment
comment|//						=	EDID_HA + EDID_HBL
end_comment

begin_comment
comment|//	VESA_HDISP			=	VESA_ACTIVE	=	EDID_HA
end_comment

begin_comment
comment|//	VESA_HSYNC_START	=	VESA_ACTIVE + VESA_BORDER + VESA_FRONT_PORCH
end_comment

begin_comment
comment|//						=	EDID_HA + EDID_HSO
end_comment

begin_comment
comment|//	VESA_HSYNC_WIDTH	=	VESA_HSYNC_TIME	=	EDID_HSPW
end_comment

begin_comment
comment|//	VESA_BORDER			=	EDID_BORDER
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in SetCRTC_UsingDTDTimingTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SET_CRTC_USING_DTD_TIMING_PARAMETERS
block|{
name|USHORT
name|usH_Size
decl_stmt|;
name|USHORT
name|usH_Blanking_Time
decl_stmt|;
name|USHORT
name|usV_Size
decl_stmt|;
name|USHORT
name|usV_Blanking_Time
decl_stmt|;
name|USHORT
name|usH_SyncOffset
decl_stmt|;
name|USHORT
name|usH_SyncWidth
decl_stmt|;
name|USHORT
name|usV_SyncOffset
decl_stmt|;
name|USHORT
name|usV_SyncWidth
decl_stmt|;
name|ATOM_MODE_MISC_INFO_ACCESS
name|susModeMiscInfo
decl_stmt|;
name|UCHAR
name|ucH_Border
decl_stmt|;
comment|// From DFP EDID
name|UCHAR
name|ucV_Border
decl_stmt|;
name|UCHAR
name|ucCRTC
decl_stmt|;
comment|// ATOM_CRTC1 or ATOM_CRTC2
name|UCHAR
name|ucPadding
index|[
literal|3
index|]
decl_stmt|;
block|}
name|SET_CRTC_USING_DTD_TIMING_PARAMETERS
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in SetCRTC_TimingTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SET_CRTC_TIMING_PARAMETERS
block|{
name|USHORT
name|usH_Total
decl_stmt|;
comment|// horizontal total
name|USHORT
name|usH_Disp
decl_stmt|;
comment|// horizontal display
name|USHORT
name|usH_SyncStart
decl_stmt|;
comment|// horozontal Sync start
name|USHORT
name|usH_SyncWidth
decl_stmt|;
comment|// horizontal Sync width
name|USHORT
name|usV_Total
decl_stmt|;
comment|// vertical total
name|USHORT
name|usV_Disp
decl_stmt|;
comment|// vertical display
name|USHORT
name|usV_SyncStart
decl_stmt|;
comment|// vertical Sync start
name|USHORT
name|usV_SyncWidth
decl_stmt|;
comment|// vertical Sync width
name|ATOM_MODE_MISC_INFO_ACCESS
name|susModeMiscInfo
decl_stmt|;
name|UCHAR
name|ucCRTC
decl_stmt|;
comment|// ATOM_CRTC1 or ATOM_CRTC2
name|UCHAR
name|ucOverscanRight
decl_stmt|;
comment|// right
name|UCHAR
name|ucOverscanLeft
decl_stmt|;
comment|// left
name|UCHAR
name|ucOverscanBottom
decl_stmt|;
comment|// bottom
name|UCHAR
name|ucOverscanTop
decl_stmt|;
comment|// top
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|SET_CRTC_TIMING_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SET_CRTC_TIMING_PARAMETERS_PS_ALLOCATION
value|SET_CRTC_TIMING_PARAMETERS
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in StandardVESA_TimingTable
end_comment

begin_comment
comment|//                   AnalogTV_InfoTable
end_comment

begin_comment
comment|//                   ComponentVideoInfoTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MODE_TIMING
block|{
name|USHORT
name|usCRTC_H_Total
decl_stmt|;
name|USHORT
name|usCRTC_H_Disp
decl_stmt|;
name|USHORT
name|usCRTC_H_SyncStart
decl_stmt|;
name|USHORT
name|usCRTC_H_SyncWidth
decl_stmt|;
name|USHORT
name|usCRTC_V_Total
decl_stmt|;
name|USHORT
name|usCRTC_V_Disp
decl_stmt|;
name|USHORT
name|usCRTC_V_SyncStart
decl_stmt|;
name|USHORT
name|usCRTC_V_SyncWidth
decl_stmt|;
name|USHORT
name|usPixelClock
decl_stmt|;
comment|//in 10Khz unit
name|ATOM_MODE_MISC_INFO_ACCESS
name|susModeMiscInfo
decl_stmt|;
name|USHORT
name|usCRTC_OverscanRight
decl_stmt|;
name|USHORT
name|usCRTC_OverscanLeft
decl_stmt|;
name|USHORT
name|usCRTC_OverscanBottom
decl_stmt|;
name|USHORT
name|usCRTC_OverscanTop
decl_stmt|;
name|USHORT
name|usReserve
decl_stmt|;
name|UCHAR
name|ucInternalModeNumber
decl_stmt|;
name|UCHAR
name|ucRefreshRate
decl_stmt|;
block|}
name|ATOM_MODE_TIMING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DTD_FORMAT
block|{
name|USHORT
name|usPixClk
decl_stmt|;
name|USHORT
name|usHActive
decl_stmt|;
name|USHORT
name|usHBlanking_Time
decl_stmt|;
name|USHORT
name|usVActive
decl_stmt|;
name|USHORT
name|usVBlanking_Time
decl_stmt|;
name|USHORT
name|usHSyncOffset
decl_stmt|;
name|USHORT
name|usHSyncWidth
decl_stmt|;
name|USHORT
name|usVSyncOffset
decl_stmt|;
name|USHORT
name|usVSyncWidth
decl_stmt|;
name|USHORT
name|usImageHSize
decl_stmt|;
name|USHORT
name|usImageVSize
decl_stmt|;
name|UCHAR
name|ucHBorder
decl_stmt|;
name|UCHAR
name|ucVBorder
decl_stmt|;
name|ATOM_MODE_MISC_INFO_ACCESS
name|susModeMiscInfo
decl_stmt|;
name|UCHAR
name|ucInternalModeNumber
decl_stmt|;
name|UCHAR
name|ucRefreshRate
decl_stmt|;
block|}
name|ATOM_DTD_FORMAT
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in LVDS_InfoTable
end_comment

begin_comment
comment|//  * Need a document to describe this table
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SUPPORTED_LCD_REFRESHRATE_30Hz
value|0x0004
end_define

begin_define
define|#
directive|define
name|SUPPORTED_LCD_REFRESHRATE_40Hz
value|0x0008
end_define

begin_define
define|#
directive|define
name|SUPPORTED_LCD_REFRESHRATE_50Hz
value|0x0010
end_define

begin_define
define|#
directive|define
name|SUPPORTED_LCD_REFRESHRATE_60Hz
value|0x0020
end_define

begin_comment
comment|//ucTableFormatRevision=1
end_comment

begin_comment
comment|//ucTableContentRevision=1
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_LVDS_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_DTD_FORMAT
name|sLCDTiming
decl_stmt|;
name|USHORT
name|usModePatchTableOffset
decl_stmt|;
name|USHORT
name|usSupportedRefreshRate
decl_stmt|;
comment|//Refer to panel info table in ATOMBIOS extension Spec.
name|USHORT
name|usOffDelayInMs
decl_stmt|;
name|UCHAR
name|ucPowerSequenceDigOntoDEin10Ms
decl_stmt|;
name|UCHAR
name|ucPowerSequenceDEtoBLOnin10Ms
decl_stmt|;
name|UCHAR
name|ucLVDS_Misc
decl_stmt|;
comment|// Bit0:{=0:single, =1:dual},Bit1 {=0:666RGB, =1:888RGB},Bit2:3:{Grey level}
comment|// Bit4:{=0:LDI format for RGB888, =1 FPDI format for RGB888}
comment|// Bit5:{=0:Spatial Dithering disabled;1 Spatial Dithering enabled}
comment|// Bit6:{=0:Temporal Dithering disabled;1 Temporal Dithering enabled}
name|UCHAR
name|ucPanelDefaultRefreshRate
decl_stmt|;
name|UCHAR
name|ucPanelIdentification
decl_stmt|;
name|UCHAR
name|ucSS_Id
decl_stmt|;
block|}
name|ATOM_LVDS_INFO
typedef|;
end_typedef

begin_comment
comment|//ucTableFormatRevision=1
end_comment

begin_comment
comment|//ucTableContentRevision=2
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_LVDS_INFO_V12
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_DTD_FORMAT
name|sLCDTiming
decl_stmt|;
name|USHORT
name|usExtInfoTableOffset
decl_stmt|;
name|USHORT
name|usSupportedRefreshRate
decl_stmt|;
comment|//Refer to panel info table in ATOMBIOS extension Spec.
name|USHORT
name|usOffDelayInMs
decl_stmt|;
name|UCHAR
name|ucPowerSequenceDigOntoDEin10Ms
decl_stmt|;
name|UCHAR
name|ucPowerSequenceDEtoBLOnin10Ms
decl_stmt|;
name|UCHAR
name|ucLVDS_Misc
decl_stmt|;
comment|// Bit0:{=0:single, =1:dual},Bit1 {=0:666RGB, =1:888RGB},Bit2:3:{Grey level}
comment|// Bit4:{=0:LDI format for RGB888, =1 FPDI format for RGB888}
comment|// Bit5:{=0:Spatial Dithering disabled;1 Spatial Dithering enabled}
comment|// Bit6:{=0:Temporal Dithering disabled;1 Temporal Dithering enabled}
name|UCHAR
name|ucPanelDefaultRefreshRate
decl_stmt|;
name|UCHAR
name|ucPanelIdentification
decl_stmt|;
name|UCHAR
name|ucSS_Id
decl_stmt|;
name|USHORT
name|usLCDVenderID
decl_stmt|;
name|USHORT
name|usLCDProductID
decl_stmt|;
name|UCHAR
name|ucLCDPanel_SpecialHandlingCap
decl_stmt|;
name|UCHAR
name|ucPanelInfoSize
decl_stmt|;
comment|//  start from ATOM_DTD_FORMAT to end of panel info, include ExtInfoTable
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ATOM_LVDS_INFO_V12
typedef|;
end_typedef

begin_comment
comment|//Definitions for ucLCDPanel_SpecialHandlingCap:
end_comment

begin_comment
comment|//Once DAL sees this CAP is set, it will read EDID from LCD on its own instead of using sLCDTiming in ATOM_LVDS_INFO_V12.
end_comment

begin_comment
comment|//Other entries in ATOM_LVDS_INFO_V12 are still valid/useful to DAL
end_comment

begin_define
define|#
directive|define
name|LCDPANEL_CAP_READ_EDID
value|0x1
end_define

begin_comment
comment|//If a design supports DRR (dynamic refresh rate) on internal panels (LVDS or EDP), this cap is set in ucLCDPanel_SpecialHandlingCap together
end_comment

begin_comment
comment|//with multiple supported refresh rates@usSupportedRefreshRate. This cap should not be set when only slow refresh rate is supported (static
end_comment

begin_comment
comment|//refresh rate switch by SW. This is only valid from ATOM_LVDS_INFO_V12
end_comment

begin_define
define|#
directive|define
name|LCDPANEL_CAP_DRR_SUPPORTED
value|0x2
end_define

begin_comment
comment|//Use this cap bit for a quick reference whether an embadded panel (LCD1 ) is LVDS or eDP.
end_comment

begin_define
define|#
directive|define
name|LCDPANEL_CAP_eDP
value|0x4
end_define

begin_comment
comment|//Color Bit Depth definition in EDID V1.4 @BYTE 14h
end_comment

begin_comment
comment|//Bit 6  5  4
end_comment

begin_comment
comment|//      0  0  0  -  Color bit depth is undefined
end_comment

begin_comment
comment|//      0  0  1  -  6 Bits per Primary Color
end_comment

begin_comment
comment|//      0  1  0  -  8 Bits per Primary Color
end_comment

begin_comment
comment|//      0  1  1  - 10 Bits per Primary Color
end_comment

begin_comment
comment|//      1  0  0  - 12 Bits per Primary Color
end_comment

begin_comment
comment|//      1  0  1  - 14 Bits per Primary Color
end_comment

begin_comment
comment|//      1  1  0  - 16 Bits per Primary Color
end_comment

begin_comment
comment|//      1  1  1  - Reserved
end_comment

begin_define
define|#
directive|define
name|PANEL_COLOR_BIT_DEPTH_MASK
value|0x70
end_define

begin_comment
comment|// Bit7:{=0:Random Dithering disabled;1 Random Dithering enabled}
end_comment

begin_define
define|#
directive|define
name|PANEL_RANDOM_DITHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PANEL_RANDOM_DITHER_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_LVDS_INFO_LAST
value|ATOM_LVDS_INFO_V12
end_define

begin_comment
comment|// no need to change this
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by LCD_InfoTable V1.3    Note: previous version was called ATOM_LVDS_INFO_V12
end_comment

begin_comment
comment|// ASIC Families:  NI
end_comment

begin_comment
comment|// ucTableFormatRevision=1
end_comment

begin_comment
comment|// ucTableContentRevision=3
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_LCD_INFO_V13
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_DTD_FORMAT
name|sLCDTiming
decl_stmt|;
name|USHORT
name|usExtInfoTableOffset
decl_stmt|;
name|USHORT
name|usSupportedRefreshRate
decl_stmt|;
comment|//Refer to panel info table in ATOMBIOS extension Spec.
name|ULONG
name|ulReserved0
decl_stmt|;
name|UCHAR
name|ucLCD_Misc
decl_stmt|;
comment|// Reorganized in V13
comment|// Bit0: {=0:single, =1:dual},
comment|// Bit1: {=0:LDI format for RGB888, =1 FPDI format for RGB888}  // was {=0:666RGB, =1:888RGB},
comment|// Bit3:2: {Grey level}
comment|// Bit6:4 Color Bit Depth definition (see below definition in EDID V1.4 @BYTE 14h)
comment|// Bit7   Reserved.  was for ATOM_PANEL_MISC_API_ENABLED, still need it?
name|UCHAR
name|ucPanelDefaultRefreshRate
decl_stmt|;
name|UCHAR
name|ucPanelIdentification
decl_stmt|;
name|UCHAR
name|ucSS_Id
decl_stmt|;
name|USHORT
name|usLCDVenderID
decl_stmt|;
name|USHORT
name|usLCDProductID
decl_stmt|;
name|UCHAR
name|ucLCDPanel_SpecialHandlingCap
decl_stmt|;
comment|// Reorganized in V13
comment|// Bit0: Once DAL sees this CAP is set, it will read EDID from LCD on its own
comment|// Bit1: See LCDPANEL_CAP_DRR_SUPPORTED
comment|// Bit2: a quick reference whether an embadded panel (LCD1 ) is LVDS (0) or eDP (1)
comment|// Bit7-3: Reserved
name|UCHAR
name|ucPanelInfoSize
decl_stmt|;
comment|//  start from ATOM_DTD_FORMAT to end of panel info, include ExtInfoTable
name|USHORT
name|usBacklightPWM
decl_stmt|;
comment|//  Backlight PWM in Hz. New in _V13
name|UCHAR
name|ucPowerSequenceDIGONtoDE_in4Ms
decl_stmt|;
name|UCHAR
name|ucPowerSequenceDEtoVARY_BL_in4Ms
decl_stmt|;
name|UCHAR
name|ucPowerSequenceVARY_BLtoDE_in4Ms
decl_stmt|;
name|UCHAR
name|ucPowerSequenceDEtoDIGON_in4Ms
decl_stmt|;
name|UCHAR
name|ucOffDelay_in4Ms
decl_stmt|;
name|UCHAR
name|ucPowerSequenceVARY_BLtoBLON_in4Ms
decl_stmt|;
name|UCHAR
name|ucPowerSequenceBLONtoVARY_BL_in4Ms
decl_stmt|;
name|UCHAR
name|ucReserved1
decl_stmt|;
name|UCHAR
name|ucDPCD_eDP_CONFIGURATION_CAP
decl_stmt|;
comment|// dpcd 0dh
name|UCHAR
name|ucDPCD_MAX_LINK_RATE
decl_stmt|;
comment|// dpcd 01h
name|UCHAR
name|ucDPCD_MAX_LANE_COUNT
decl_stmt|;
comment|// dpcd 02h
name|UCHAR
name|ucDPCD_MAX_DOWNSPREAD
decl_stmt|;
comment|// dpcd 03h
name|USHORT
name|usMaxPclkFreqInSingleLink
decl_stmt|;
comment|// Max PixelClock frequency in single link mode.
name|UCHAR
name|uceDPToLVDSRxId
decl_stmt|;
name|UCHAR
name|ucLcdReservd
decl_stmt|;
name|ULONG
name|ulReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ATOM_LCD_INFO_V13
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_LCD_INFO_LAST
value|ATOM_LCD_INFO_V13
end_define

begin_comment
comment|//Definitions for ucLCD_Misc
end_comment

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_V13_DUAL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_V13_FPDI
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_V13_GREY_LEVEL
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_V13_GREY_LEVEL_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_V13_COLOR_BIT_DEPTH_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_V13_6BIT_PER_COLOR
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_PANEL_MISC_V13_8BIT_PER_COLOR
value|0x20
end_define

begin_comment
comment|//Color Bit Depth definition in EDID V1.4 @BYTE 14h
end_comment

begin_comment
comment|//Bit 6  5  4
end_comment

begin_comment
comment|//      0  0  0  -  Color bit depth is undefined
end_comment

begin_comment
comment|//      0  0  1  -  6 Bits per Primary Color
end_comment

begin_comment
comment|//      0  1  0  -  8 Bits per Primary Color
end_comment

begin_comment
comment|//      0  1  1  - 10 Bits per Primary Color
end_comment

begin_comment
comment|//      1  0  0  - 12 Bits per Primary Color
end_comment

begin_comment
comment|//      1  0  1  - 14 Bits per Primary Color
end_comment

begin_comment
comment|//      1  1  0  - 16 Bits per Primary Color
end_comment

begin_comment
comment|//      1  1  1  - Reserved
end_comment

begin_comment
comment|//Definitions for ucLCDPanel_SpecialHandlingCap:
end_comment

begin_comment
comment|//Once DAL sees this CAP is set, it will read EDID from LCD on its own instead of using sLCDTiming in ATOM_LVDS_INFO_V12.
end_comment

begin_comment
comment|//Other entries in ATOM_LVDS_INFO_V12 are still valid/useful to DAL
end_comment

begin_define
define|#
directive|define
name|LCDPANEL_CAP_V13_READ_EDID
value|0x1
end_define

begin_comment
comment|// = LCDPANEL_CAP_READ_EDID no change comparing to previous version
end_comment

begin_comment
comment|//If a design supports DRR (dynamic refresh rate) on internal panels (LVDS or EDP), this cap is set in ucLCDPanel_SpecialHandlingCap together
end_comment

begin_comment
comment|//with multiple supported refresh rates@usSupportedRefreshRate. This cap should not be set when only slow refresh rate is supported (static
end_comment

begin_comment
comment|//refresh rate switch by SW. This is only valid from ATOM_LVDS_INFO_V12
end_comment

begin_define
define|#
directive|define
name|LCDPANEL_CAP_V13_DRR_SUPPORTED
value|0x2
end_define

begin_comment
comment|// = LCDPANEL_CAP_DRR_SUPPORTED no change comparing to previous version
end_comment

begin_comment
comment|//Use this cap bit for a quick reference whether an embadded panel (LCD1 ) is LVDS or eDP.
end_comment

begin_define
define|#
directive|define
name|LCDPANEL_CAP_V13_eDP
value|0x4
end_define

begin_comment
comment|// = LCDPANEL_CAP_eDP no change comparing to previous version
end_comment

begin_comment
comment|//uceDPToLVDSRxId
end_comment

begin_define
define|#
directive|define
name|eDP_TO_LVDS_RX_DISABLE
value|0x00
end_define

begin_comment
comment|// no eDP->LVDS translator chip
end_comment

begin_define
define|#
directive|define
name|eDP_TO_LVDS_COMMON_ID
value|0x01
end_define

begin_comment
comment|// common eDP->LVDS translator chip without AMD SW init
end_comment

begin_define
define|#
directive|define
name|eDP_TO_LVDS_RT_ID
value|0x02
end_define

begin_comment
comment|// RT tanslator which require AMD SW init
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PATCH_RECORD_MODE
block|{
name|UCHAR
name|ucRecordType
decl_stmt|;
name|USHORT
name|usHDisp
decl_stmt|;
name|USHORT
name|usVDisp
decl_stmt|;
block|}
name|ATOM_PATCH_RECORD_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_LCD_RTS_RECORD
block|{
name|UCHAR
name|ucRecordType
decl_stmt|;
name|UCHAR
name|ucRTSValue
decl_stmt|;
block|}
name|ATOM_LCD_RTS_RECORD
typedef|;
end_typedef

begin_comment
comment|//!! If the record below exits, it shoud always be the first record for easy use in command table!!!
end_comment

begin_comment
comment|// The record below is only used when LVDS_Info is present. From ATOM_LVDS_INFO_V12, use ucLCDPanel_SpecialHandlingCap instead.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_LCD_MODE_CONTROL_CAP
block|{
name|UCHAR
name|ucRecordType
decl_stmt|;
name|USHORT
name|usLCDCap
decl_stmt|;
block|}
name|ATOM_LCD_MODE_CONTROL_CAP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LCD_MODE_CAP_BL_OFF
value|1
end_define

begin_define
define|#
directive|define
name|LCD_MODE_CAP_CRTC_OFF
value|2
end_define

begin_define
define|#
directive|define
name|LCD_MODE_CAP_PANEL_OFF
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_FAKE_EDID_PATCH_RECORD
block|{
name|UCHAR
name|ucRecordType
decl_stmt|;
name|UCHAR
name|ucFakeEDIDLength
decl_stmt|;
name|UCHAR
name|ucFakeEDIDString
index|[
literal|1
index|]
decl_stmt|;
comment|// This actually has ucFakeEdidLength elements.
block|}
name|ATOM_FAKE_EDID_PATCH_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PANEL_RESOLUTION_PATCH_RECORD
block|{
name|UCHAR
name|ucRecordType
decl_stmt|;
name|USHORT
name|usHSize
decl_stmt|;
name|USHORT
name|usVSize
decl_stmt|;
block|}
name|ATOM_PANEL_RESOLUTION_PATCH_RECORD
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LCD_MODE_PATCH_RECORD_MODE_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|LCD_RTS_RECORD_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|LCD_CAP_RECORD_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|LCD_FAKE_EDID_PATCH_RECORD_TYPE
value|4
end_define

begin_define
define|#
directive|define
name|LCD_PANEL_RESOLUTION_RECORD_TYPE
value|5
end_define

begin_define
define|#
directive|define
name|LCD_EDID_OFFSET_PATCH_RECORD_TYPE
value|6
end_define

begin_define
define|#
directive|define
name|ATOM_RECORD_END_TYPE
value|0xFF
end_define

begin_comment
comment|/****************************Spread Spectrum Info Table Definitions **********************/
end_comment

begin_comment
comment|//ucTableFormatRevision=1
end_comment

begin_comment
comment|//ucTableContentRevision=2
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_SPREAD_SPECTRUM_ASSIGNMENT
block|{
name|USHORT
name|usSpreadSpectrumPercentage
decl_stmt|;
name|UCHAR
name|ucSpreadSpectrumType
decl_stmt|;
comment|//Bit1=0 Down Spread,=1 Center Spread. Bit1=1 Ext. =0 Int. Bit2=1: PCIE REFCLK SS =0 iternal PPLL SS  Others:TBD
name|UCHAR
name|ucSS_Step
decl_stmt|;
name|UCHAR
name|ucSS_Delay
decl_stmt|;
name|UCHAR
name|ucSS_Id
decl_stmt|;
name|UCHAR
name|ucRecommendedRef_Div
decl_stmt|;
name|UCHAR
name|ucSS_Range
decl_stmt|;
comment|//it was reserved for V11
block|}
name|ATOM_SPREAD_SPECTRUM_ASSIGNMENT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_MAX_SS_ENTRY
value|16
end_define

begin_define
define|#
directive|define
name|ATOM_DP_SS_ID1
value|0x0f1
end_define

begin_comment
comment|// SS ID for internal DP stream at 2.7Ghz. if ATOM_DP_SS_ID2 does not exist in SS_InfoTable, it is used for internal DP stream at 1.62Ghz as well.
end_comment

begin_define
define|#
directive|define
name|ATOM_DP_SS_ID2
value|0x0f2
end_define

begin_comment
comment|// SS ID for internal DP stream at 1.62Ghz, if it exists in SS_InfoTable.
end_comment

begin_define
define|#
directive|define
name|ATOM_LVLINK_2700MHz_SS_ID
value|0x0f3
end_define

begin_comment
comment|// SS ID for LV link translator chip at 2.7Ghz
end_comment

begin_define
define|#
directive|define
name|ATOM_LVLINK_1620MHz_SS_ID
value|0x0f4
end_define

begin_comment
comment|// SS ID for LV link translator chip at 1.62Ghz
end_comment

begin_define
define|#
directive|define
name|ATOM_SS_DOWN_SPREAD_MODE_MASK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATOM_SS_DOWN_SPREAD_MODE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATOM_SS_CENTRE_SPREAD_MODE_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATOM_SS_CENTRE_SPREAD_MODE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATOM_INTERNAL_SS_MASK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATOM_EXTERNAL_SS_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EXEC_SS_STEP_SIZE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|EXEC_SS_DELAY_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ACTIVEDATA_TO_BLON_DELAY_SHIFT
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_SPREAD_SPECTRUM_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_SPREAD_SPECTRUM_ASSIGNMENT
name|asSS_Info
index|[
name|ATOM_MAX_SS_ENTRY
index|]
decl_stmt|;
block|}
name|ATOM_SPREAD_SPECTRUM_INFO
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in AnalogTV_InfoTable (Top level)
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|//ucTVBootUpDefaultStd definition:
end_comment

begin_comment
comment|//ATOM_TV_NTSC                1
end_comment

begin_comment
comment|//ATOM_TV_NTSCJ               2
end_comment

begin_comment
comment|//ATOM_TV_PAL                 3
end_comment

begin_comment
comment|//ATOM_TV_PALM                4
end_comment

begin_comment
comment|//ATOM_TV_PALCN               5
end_comment

begin_comment
comment|//ATOM_TV_PALN                6
end_comment

begin_comment
comment|//ATOM_TV_PAL60               7
end_comment

begin_comment
comment|//ATOM_TV_SECAM               8
end_comment

begin_comment
comment|//ucTVSupportedStd definition:
end_comment

begin_define
define|#
directive|define
name|NTSC_SUPPORT
value|0x1
end_define

begin_define
define|#
directive|define
name|NTSCJ_SUPPORT
value|0x2
end_define

begin_define
define|#
directive|define
name|PAL_SUPPORT
value|0x4
end_define

begin_define
define|#
directive|define
name|PALM_SUPPORT
value|0x8
end_define

begin_define
define|#
directive|define
name|PALCN_SUPPORT
value|0x10
end_define

begin_define
define|#
directive|define
name|PALN_SUPPORT
value|0x20
end_define

begin_define
define|#
directive|define
name|PAL60_SUPPORT
value|0x40
end_define

begin_define
define|#
directive|define
name|SECAM_SUPPORT
value|0x80
end_define

begin_define
define|#
directive|define
name|MAX_SUPPORTED_TV_TIMING
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ANALOG_TV_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|ucTV_SupportedStandard
decl_stmt|;
name|UCHAR
name|ucTV_BootUpDefaultStandard
decl_stmt|;
name|UCHAR
name|ucExt_TV_ASIC_ID
decl_stmt|;
name|UCHAR
name|ucExt_TV_ASIC_SlaveAddr
decl_stmt|;
comment|/*ATOM_DTD_FORMAT          aModeTimings[MAX_SUPPORTED_TV_TIMING];*/
name|ATOM_MODE_TIMING
name|aModeTimings
index|[
name|MAX_SUPPORTED_TV_TIMING
index|]
decl_stmt|;
block|}
name|ATOM_ANALOG_TV_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_SUPPORTED_TV_TIMING_V1_2
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ANALOG_TV_INFO_V1_2
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|ucTV_SupportedStandard
decl_stmt|;
name|UCHAR
name|ucTV_BootUpDefaultStandard
decl_stmt|;
name|UCHAR
name|ucExt_TV_ASIC_ID
decl_stmt|;
name|UCHAR
name|ucExt_TV_ASIC_SlaveAddr
decl_stmt|;
name|ATOM_DTD_FORMAT
name|aModeTimings
index|[
name|MAX_SUPPORTED_TV_TIMING_V1_2
index|]
decl_stmt|;
block|}
name|ATOM_ANALOG_TV_INFO_V1_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DPCD_INFO
block|{
name|UCHAR
name|ucRevisionNumber
decl_stmt|;
comment|//10h : Revision 1.0; 11h : Revision 1.1
name|UCHAR
name|ucMaxLinkRate
decl_stmt|;
comment|//06h : 1.62Gbps per lane; 0Ah = 2.7Gbps per lane
name|UCHAR
name|ucMaxLane
decl_stmt|;
comment|//Bits 4:0 = MAX_LANE_COUNT (1/2/4). Bit 7 = ENHANCED_FRAME_CAP
name|UCHAR
name|ucMaxDownSpread
decl_stmt|;
comment|//Bit0 = 0: No Down spread; Bit0 = 1: 0.5% (Subject to change according to DP spec)
block|}
name|ATOM_DPCD_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_DPCD_MAX_LANE_MASK
value|0x1F
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|// VRAM usage and their defintions
end_comment

begin_comment
comment|// One chunk of VRAM used by Bios are for HWICON surfaces,EDID data.
end_comment

begin_comment
comment|// Current Mode timing and Dail Timing and/or STD timing data EACH device. They can be broken down as below.
end_comment

begin_comment
comment|// All the addresses below are the offsets from the frame buffer start.They all MUST be Dword aligned!
end_comment

begin_comment
comment|// To driver: The physical address of this memory portion=mmFB_START(4K aligned)+ATOMBIOS_VRAM_USAGE_START_ADDR+ATOM_x_ADDR
end_comment

begin_comment
comment|// To Bios:  ATOMBIOS_VRAM_USAGE_START_ADDR+ATOM_x_ADDR->MM_INDEX
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VESA_MEMORY_IN_64K_BLOCK
end_ifndef

begin_define
define|#
directive|define
name|VESA_MEMORY_IN_64K_BLOCK
value|0x100
end_define

begin_comment
comment|//256*64K=16Mb (Max. VESA memory is 16Mb!)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ATOM_EDID_RAW_DATASIZE
value|256
end_define

begin_comment
comment|//In Bytes
end_comment

begin_define
define|#
directive|define
name|ATOM_HWICON_SURFACE_SIZE
value|4096
end_define

begin_comment
comment|//In Bytes
end_comment

begin_define
define|#
directive|define
name|ATOM_HWICON_INFOTABLE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|MAX_DTD_MODE_IN_VRAM
value|6
end_define

begin_define
define|#
directive|define
name|ATOM_DTD_MODE_SUPPORT_TBL_SIZE
value|(MAX_DTD_MODE_IN_VRAM*28)
end_define

begin_comment
comment|//28= (SIZEOF ATOM_DTD_FORMAT)
end_comment

begin_define
define|#
directive|define
name|ATOM_STD_MODE_SUPPORT_TBL_SIZE
value|32*8
end_define

begin_comment
comment|//32 is a predefined number,8= (SIZEOF ATOM_STD_FORMAT)
end_comment

begin_comment
comment|//20 bytes for Encoder Type and DPCD in STD EDID area
end_comment

begin_define
define|#
directive|define
name|DFP_ENCODER_TYPE_OFFSET
value|(ATOM_EDID_RAW_DATASIZE + ATOM_DTD_MODE_SUPPORT_TBL_SIZE + ATOM_STD_MODE_SUPPORT_TBL_SIZE - 20)
end_define

begin_define
define|#
directive|define
name|ATOM_DP_DPCD_OFFSET
value|(DFP_ENCODER_TYPE_OFFSET + 4 )
end_define

begin_define
define|#
directive|define
name|ATOM_HWICON1_SURFACE_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_HWICON2_SURFACE_ADDR
value|(ATOM_HWICON1_SURFACE_ADDR + ATOM_HWICON_SURFACE_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_HWICON_INFOTABLE_ADDR
value|(ATOM_HWICON2_SURFACE_ADDR + ATOM_HWICON_SURFACE_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_CRT1_EDID_ADDR
value|(ATOM_HWICON_INFOTABLE_ADDR + ATOM_HWICON_INFOTABLE_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_CRT1_DTD_MODE_TBL_ADDR
value|(ATOM_CRT1_EDID_ADDR + ATOM_EDID_RAW_DATASIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_CRT1_STD_MODE_TBL_ADDR
value|(ATOM_CRT1_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_LCD1_EDID_ADDR
value|(ATOM_CRT1_STD_MODE_TBL_ADDR + ATOM_STD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_LCD1_DTD_MODE_TBL_ADDR
value|(ATOM_LCD1_EDID_ADDR + ATOM_EDID_RAW_DATASIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_LCD1_STD_MODE_TBL_ADDR
value|(ATOM_LCD1_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_TV1_DTD_MODE_TBL_ADDR
value|(ATOM_LCD1_STD_MODE_TBL_ADDR + ATOM_STD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP1_EDID_ADDR
value|(ATOM_TV1_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP1_DTD_MODE_TBL_ADDR
value|(ATOM_DFP1_EDID_ADDR + ATOM_EDID_RAW_DATASIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP1_STD_MODE_TBL_ADDR
value|(ATOM_DFP1_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_CRT2_EDID_ADDR
value|(ATOM_DFP1_STD_MODE_TBL_ADDR + ATOM_STD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_CRT2_DTD_MODE_TBL_ADDR
value|(ATOM_CRT2_EDID_ADDR + ATOM_EDID_RAW_DATASIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_CRT2_STD_MODE_TBL_ADDR
value|(ATOM_CRT2_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_LCD2_EDID_ADDR
value|(ATOM_CRT2_STD_MODE_TBL_ADDR + ATOM_STD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_LCD2_DTD_MODE_TBL_ADDR
value|(ATOM_LCD2_EDID_ADDR + ATOM_EDID_RAW_DATASIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_LCD2_STD_MODE_TBL_ADDR
value|(ATOM_LCD2_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP6_EDID_ADDR
value|(ATOM_LCD2_STD_MODE_TBL_ADDR + ATOM_STD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP6_DTD_MODE_TBL_ADDR
value|(ATOM_DFP6_EDID_ADDR + ATOM_EDID_RAW_DATASIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP6_STD_MODE_TBL_ADDR
value|(ATOM_DFP6_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP2_EDID_ADDR
value|(ATOM_DFP6_STD_MODE_TBL_ADDR + ATOM_STD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP2_DTD_MODE_TBL_ADDR
value|(ATOM_DFP2_EDID_ADDR + ATOM_EDID_RAW_DATASIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP2_STD_MODE_TBL_ADDR
value|(ATOM_DFP2_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_CV_EDID_ADDR
value|(ATOM_DFP2_STD_MODE_TBL_ADDR + ATOM_STD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_CV_DTD_MODE_TBL_ADDR
value|(ATOM_CV_EDID_ADDR + ATOM_EDID_RAW_DATASIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_CV_STD_MODE_TBL_ADDR
value|(ATOM_CV_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP3_EDID_ADDR
value|(ATOM_CV_STD_MODE_TBL_ADDR + ATOM_STD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP3_DTD_MODE_TBL_ADDR
value|(ATOM_DFP3_EDID_ADDR + ATOM_EDID_RAW_DATASIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP3_STD_MODE_TBL_ADDR
value|(ATOM_DFP3_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP4_EDID_ADDR
value|(ATOM_DFP3_STD_MODE_TBL_ADDR + ATOM_STD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP4_DTD_MODE_TBL_ADDR
value|(ATOM_DFP4_EDID_ADDR + ATOM_EDID_RAW_DATASIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP4_STD_MODE_TBL_ADDR
value|(ATOM_DFP4_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP5_EDID_ADDR
value|(ATOM_DFP4_STD_MODE_TBL_ADDR + ATOM_STD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP5_DTD_MODE_TBL_ADDR
value|(ATOM_DFP5_EDID_ADDR + ATOM_EDID_RAW_DATASIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DFP5_STD_MODE_TBL_ADDR
value|(ATOM_DFP5_DTD_MODE_TBL_ADDR + ATOM_DTD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_DP_TRAINING_TBL_ADDR
value|(ATOM_DFP5_STD_MODE_TBL_ADDR + ATOM_STD_MODE_SUPPORT_TBL_SIZE)
end_define

begin_define
define|#
directive|define
name|ATOM_STACK_STORAGE_START
value|(ATOM_DP_TRAINING_TBL_ADDR + 1024)
end_define

begin_define
define|#
directive|define
name|ATOM_STACK_STORAGE_END
value|ATOM_STACK_STORAGE_START + 512
end_define

begin_comment
comment|//The size below is in Kb!
end_comment

begin_define
define|#
directive|define
name|ATOM_VRAM_RESERVE_SIZE
value|((((ATOM_STACK_STORAGE_END - ATOM_HWICON1_SURFACE_ADDR)>>10)+4)&0xFFFC)
end_define

begin_define
define|#
directive|define
name|ATOM_VRAM_RESERVE_V2_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|ATOM_VRAM_OPERATION_FLAGS_MASK
value|0xC0000000L
end_define

begin_define
define|#
directive|define
name|ATOM_VRAM_OPERATION_FLAGS_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|ATOM_VRAM_BLOCK_NEEDS_NO_RESERVATION
value|0x1
end_define

begin_define
define|#
directive|define
name|ATOM_VRAM_BLOCK_NEEDS_RESERVATION
value|0x0
end_define

begin_comment
comment|/***********************************************************************************/
end_comment

begin_comment
comment|// Structure used in VRAM_UsageByFirmwareTable
end_comment

begin_comment
comment|// Note1: This table is filled by SetBiosReservationStartInFB in CoreCommSubs.asm
end_comment

begin_comment
comment|//        at running time.
end_comment

begin_comment
comment|// note2: From RV770, the memory is more than 32bit addressable, so we will change
end_comment

begin_comment
comment|//        ucTableFormatRevision=1,ucTableContentRevision=4, the strcuture remains
end_comment

begin_comment
comment|//        exactly same as 1.1 and 1.2 (1.3 is never in use), but ulStartAddrUsedByFirmware
end_comment

begin_comment
comment|//        (in offset to start of memory address) is KB aligned instead of byte aligend.
end_comment

begin_comment
comment|/***********************************************************************************/
end_comment

begin_comment
comment|// Note3:
end_comment

begin_comment
comment|/* If we change usReserved to "usFBUsedbyDrvInKB", then to VBIOS this usFBUsedbyDrvInKB is a predefined, unchanged constant across VGA or non VGA adapter, for CAIL, The size of FB access area is known, only thing missing is the Offset of FB Access area, so we can  have:  If (ulStartAddrUsedByFirmware!=0) FBAccessAreaOffset= ulStartAddrUsedByFirmware - usFBUsedbyDrvInKB; Reserved area has been claimed by VBIOS including this FB access area; CAIL doesn't need to reserve any extra area for this purpose else	//Non VGA case  if (FB_Size<=2Gb)     FBAccessAreaOffset= FB_Size - usFBUsedbyDrvInKB;  else 	  FBAccessAreaOffset= Aper_Size - usFBUsedbyDrvInKB  CAIL needs to claim an reserved area defined by FBAccessAreaOffset and usFBUsedbyDrvInKB in non VGA case.*/
end_comment

begin_comment
comment|/***********************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ATOM_MAX_FIRMWARE_VRAM_USAGE_INFO
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_FIRMWARE_VRAM_RESERVE_INFO
block|{
name|ULONG
name|ulStartAddrUsedByFirmware
decl_stmt|;
name|USHORT
name|usFirmwareUseInKb
decl_stmt|;
name|USHORT
name|usReserved
decl_stmt|;
block|}
name|ATOM_FIRMWARE_VRAM_RESERVE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_USAGE_BY_FIRMWARE
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_FIRMWARE_VRAM_RESERVE_INFO
name|asFirmwareVramReserveInfo
index|[
name|ATOM_MAX_FIRMWARE_VRAM_USAGE_INFO
index|]
decl_stmt|;
block|}
name|ATOM_VRAM_USAGE_BY_FIRMWARE
typedef|;
end_typedef

begin_comment
comment|// change verion to 1.5, when allow driver to allocate the vram area for command table access.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_FIRMWARE_VRAM_RESERVE_INFO_V1_5
block|{
name|ULONG
name|ulStartAddrUsedByFirmware
decl_stmt|;
name|USHORT
name|usFirmwareUseInKb
decl_stmt|;
name|USHORT
name|usFBUsedByDrvInKb
decl_stmt|;
block|}
name|ATOM_FIRMWARE_VRAM_RESERVE_INFO_V1_5
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_USAGE_BY_FIRMWARE_V1_5
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_FIRMWARE_VRAM_RESERVE_INFO_V1_5
name|asFirmwareVramReserveInfo
index|[
name|ATOM_MAX_FIRMWARE_VRAM_USAGE_INFO
index|]
decl_stmt|;
block|}
name|ATOM_VRAM_USAGE_BY_FIRMWARE_V1_5
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in GPIO_Pin_LUTTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_GPIO_PIN_ASSIGNMENT
block|{
name|USHORT
name|usGpioPin_AIndex
decl_stmt|;
name|UCHAR
name|ucGpioPinBitShift
decl_stmt|;
name|UCHAR
name|ucGPIO_ID
decl_stmt|;
block|}
name|ATOM_GPIO_PIN_ASSIGNMENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_GPIO_PIN_LUT
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_GPIO_PIN_ASSIGNMENT
name|asGPIO_Pin
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_GPIO_PIN_LUT
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in ComponentVideoInfoTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_ACTIVE_HIGH
value|0x1
end_define

begin_define
define|#
directive|define
name|MAX_SUPPORTED_CV_STANDARDS
value|5
end_define

begin_comment
comment|// definitions for ATOM_D_INFO.ucSettings
end_comment

begin_define
define|#
directive|define
name|ATOM_GPIO_SETTINGS_BITSHIFT_MASK
value|0x1F
end_define

begin_comment
comment|// [4:0]
end_comment

begin_define
define|#
directive|define
name|ATOM_GPIO_SETTINGS_RESERVED_MASK
value|0x60
end_define

begin_comment
comment|// [6:5] = must be zeroed out
end_comment

begin_define
define|#
directive|define
name|ATOM_GPIO_SETTINGS_ACTIVE_MASK
value|0x80
end_define

begin_comment
comment|// [7]
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_GPIO_INFO
block|{
name|USHORT
name|usAOffset
decl_stmt|;
name|UCHAR
name|ucSettings
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|ATOM_GPIO_INFO
typedef|;
end_typedef

begin_comment
comment|// definitions for ATOM_COMPONENT_VIDEO_INFO.ucMiscInfo (bit vector)
end_comment

begin_define
define|#
directive|define
name|ATOM_CV_RESTRICT_FORMAT_SELECTION
value|0x2
end_define

begin_comment
comment|// definitions for ATOM_COMPONENT_VIDEO_INFO.uc480i/uc480p/uc720p/uc1080i
end_comment

begin_define
define|#
directive|define
name|ATOM_GPIO_DEFAULT_MODE_EN
value|0x80
end_define

begin_comment
comment|//[7];
end_comment

begin_define
define|#
directive|define
name|ATOM_GPIO_SETTING_PERMODE_MASK
value|0x7F
end_define

begin_comment
comment|//[6:0]
end_comment

begin_comment
comment|// definitions for ATOM_COMPONENT_VIDEO_INFO.ucLetterBoxMode
end_comment

begin_comment
comment|//Line 3 out put 5V.
end_comment

begin_define
define|#
directive|define
name|ATOM_CV_LINE3_ASPECTRATIO_16_9_GPIO_A
value|0x01
end_define

begin_comment
comment|//represent gpio 3 state for 16:9
end_comment

begin_define
define|#
directive|define
name|ATOM_CV_LINE3_ASPECTRATIO_16_9_GPIO_B
value|0x02
end_define

begin_comment
comment|//represent gpio 4 state for 16:9
end_comment

begin_define
define|#
directive|define
name|ATOM_CV_LINE3_ASPECTRATIO_16_9_GPIO_SHIFT
value|0x0
end_define

begin_comment
comment|//Line 3 out put 2.2V
end_comment

begin_define
define|#
directive|define
name|ATOM_CV_LINE3_ASPECTRATIO_4_3_LETBOX_GPIO_A
value|0x04
end_define

begin_comment
comment|//represent gpio 3 state for 4:3 Letter box
end_comment

begin_define
define|#
directive|define
name|ATOM_CV_LINE3_ASPECTRATIO_4_3_LETBOX_GPIO_B
value|0x08
end_define

begin_comment
comment|//represent gpio 4 state for 4:3 Letter box
end_comment

begin_define
define|#
directive|define
name|ATOM_CV_LINE3_ASPECTRATIO_4_3_LETBOX_GPIO_SHIFT
value|0x2
end_define

begin_comment
comment|//Line 3 out put 0V
end_comment

begin_define
define|#
directive|define
name|ATOM_CV_LINE3_ASPECTRATIO_4_3_GPIO_A
value|0x10
end_define

begin_comment
comment|//represent gpio 3 state for 4:3
end_comment

begin_define
define|#
directive|define
name|ATOM_CV_LINE3_ASPECTRATIO_4_3_GPIO_B
value|0x20
end_define

begin_comment
comment|//represent gpio 4 state for 4:3
end_comment

begin_define
define|#
directive|define
name|ATOM_CV_LINE3_ASPECTRATIO_4_3_GPIO_SHIFT
value|0x4
end_define

begin_define
define|#
directive|define
name|ATOM_CV_LINE3_ASPECTRATIO_MASK
value|0x3F
end_define

begin_comment
comment|// bit [5:0]
end_comment

begin_define
define|#
directive|define
name|ATOM_CV_LINE3_ASPECTRATIO_EXIST
value|0x80
end_define

begin_comment
comment|//bit 7
end_comment

begin_comment
comment|//GPIO bit index in gpio setting per mode value, also represend the block no. in gpio blocks.
end_comment

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_LINE3_ASPECRATIO_GPIO_A
value|3
end_define

begin_comment
comment|//bit 3 in uc480i/uc480p/uc720p/uc1080i, which represend the default gpio bit setting for the mode.
end_comment

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_LINE3_ASPECRATIO_GPIO_B
value|4
end_define

begin_comment
comment|//bit 4 in uc480i/uc480p/uc720p/uc1080i, which represend the default gpio bit setting for the mode.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_COMPONENT_VIDEO_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usMask_PinRegisterIndex
decl_stmt|;
name|USHORT
name|usEN_PinRegisterIndex
decl_stmt|;
name|USHORT
name|usY_PinRegisterIndex
decl_stmt|;
name|USHORT
name|usA_PinRegisterIndex
decl_stmt|;
name|UCHAR
name|ucBitShift
decl_stmt|;
name|UCHAR
name|ucPinActiveState
decl_stmt|;
comment|//ucPinActiveState: Bit0=1 active high, =0 active low
name|ATOM_DTD_FORMAT
name|sReserved
decl_stmt|;
comment|// must be zeroed out
name|UCHAR
name|ucMiscInfo
decl_stmt|;
name|UCHAR
name|uc480i
decl_stmt|;
name|UCHAR
name|uc480p
decl_stmt|;
name|UCHAR
name|uc720p
decl_stmt|;
name|UCHAR
name|uc1080i
decl_stmt|;
name|UCHAR
name|ucLetterBoxMode
decl_stmt|;
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
name|UCHAR
name|ucNumOfWbGpioBlocks
decl_stmt|;
comment|//For Component video D-Connector support. If zere, NTSC type connector
name|ATOM_GPIO_INFO
name|aWbGpioStateBlock
index|[
name|MAX_SUPPORTED_CV_STANDARDS
index|]
decl_stmt|;
name|ATOM_DTD_FORMAT
name|aModeTimings
index|[
name|MAX_SUPPORTED_CV_STANDARDS
index|]
decl_stmt|;
block|}
name|ATOM_COMPONENT_VIDEO_INFO
typedef|;
end_typedef

begin_comment
comment|//ucTableFormatRevision=2
end_comment

begin_comment
comment|//ucTableContentRevision=1
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_COMPONENT_VIDEO_INFO_V21
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|ucMiscInfo
decl_stmt|;
name|UCHAR
name|uc480i
decl_stmt|;
name|UCHAR
name|uc480p
decl_stmt|;
name|UCHAR
name|uc720p
decl_stmt|;
name|UCHAR
name|uc1080i
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
name|UCHAR
name|ucLetterBoxMode
decl_stmt|;
name|UCHAR
name|ucNumOfWbGpioBlocks
decl_stmt|;
comment|//For Component video D-Connector support. If zere, NTSC type connector
name|ATOM_GPIO_INFO
name|aWbGpioStateBlock
index|[
name|MAX_SUPPORTED_CV_STANDARDS
index|]
decl_stmt|;
name|ATOM_DTD_FORMAT
name|aModeTimings
index|[
name|MAX_SUPPORTED_CV_STANDARDS
index|]
decl_stmt|;
block|}
name|ATOM_COMPONENT_VIDEO_INFO_V21
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_COMPONENT_VIDEO_INFO_LAST
value|ATOM_COMPONENT_VIDEO_INFO_V21
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structure used in object_InfoTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_OBJECT_HEADER
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usDeviceSupport
decl_stmt|;
name|USHORT
name|usConnectorObjectTableOffset
decl_stmt|;
name|USHORT
name|usRouterObjectTableOffset
decl_stmt|;
name|USHORT
name|usEncoderObjectTableOffset
decl_stmt|;
name|USHORT
name|usProtectionObjectTableOffset
decl_stmt|;
comment|//only available when Protection block is independent.
name|USHORT
name|usDisplayPathTableOffset
decl_stmt|;
block|}
name|ATOM_OBJECT_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_OBJECT_HEADER_V3
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usDeviceSupport
decl_stmt|;
name|USHORT
name|usConnectorObjectTableOffset
decl_stmt|;
name|USHORT
name|usRouterObjectTableOffset
decl_stmt|;
name|USHORT
name|usEncoderObjectTableOffset
decl_stmt|;
name|USHORT
name|usProtectionObjectTableOffset
decl_stmt|;
comment|//only available when Protection block is independent.
name|USHORT
name|usDisplayPathTableOffset
decl_stmt|;
name|USHORT
name|usMiscObjectTableOffset
decl_stmt|;
block|}
name|ATOM_OBJECT_HEADER_V3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DISPLAY_OBJECT_PATH
block|{
name|USHORT
name|usDeviceTag
decl_stmt|;
comment|//supported device
name|USHORT
name|usSize
decl_stmt|;
comment|//the size of ATOM_DISPLAY_OBJECT_PATH
name|USHORT
name|usConnObjectId
decl_stmt|;
comment|//Connector Object ID
name|USHORT
name|usGPUObjectId
decl_stmt|;
comment|//GPU ID
name|USHORT
name|usGraphicObjIds
index|[
literal|1
index|]
decl_stmt|;
comment|//1st Encoder Obj source from GPU to last Graphic Obj destinate to connector.
block|}
name|ATOM_DISPLAY_OBJECT_PATH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DISPLAY_EXTERNAL_OBJECT_PATH
block|{
name|USHORT
name|usDeviceTag
decl_stmt|;
comment|//supported device
name|USHORT
name|usSize
decl_stmt|;
comment|//the size of ATOM_DISPLAY_OBJECT_PATH
name|USHORT
name|usConnObjectId
decl_stmt|;
comment|//Connector Object ID
name|USHORT
name|usGPUObjectId
decl_stmt|;
comment|//GPU ID
name|USHORT
name|usGraphicObjIds
index|[
literal|2
index|]
decl_stmt|;
comment|//usGraphicObjIds[0]= GPU internal encoder, usGraphicObjIds[1]= external encoder
block|}
name|ATOM_DISPLAY_EXTERNAL_OBJECT_PATH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DISPLAY_OBJECT_PATH_TABLE
block|{
name|UCHAR
name|ucNumOfDispPath
decl_stmt|;
name|UCHAR
name|ucVersion
decl_stmt|;
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
name|ATOM_DISPLAY_OBJECT_PATH
name|asDispPath
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_DISPLAY_OBJECT_PATH_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_OBJECT
comment|//each object has this structure
block|{
name|USHORT
name|usObjectID
decl_stmt|;
name|USHORT
name|usSrcDstTableOffset
decl_stmt|;
name|USHORT
name|usRecordOffset
decl_stmt|;
comment|//this pointing to a bunch of records defined below
name|USHORT
name|usReserved
decl_stmt|;
block|}
name|ATOM_OBJECT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_OBJECT_TABLE
comment|//Above 4 object table offset pointing to a bunch of objects all have this structure
block|{
name|UCHAR
name|ucNumberOfObjects
decl_stmt|;
name|UCHAR
name|ucPadding
index|[
literal|3
index|]
decl_stmt|;
name|ATOM_OBJECT
name|asObjects
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_OBJECT_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_SRC_DST_TABLE_FOR_ONE_OBJECT
comment|//usSrcDstTableOffset pointing to this structure
block|{
name|UCHAR
name|ucNumberOfSrc
decl_stmt|;
name|USHORT
name|usSrcObjectID
index|[
literal|1
index|]
decl_stmt|;
name|UCHAR
name|ucNumberOfDst
decl_stmt|;
name|USHORT
name|usDstObjectID
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_SRC_DST_TABLE_FOR_ONE_OBJECT
typedef|;
end_typedef

begin_comment
comment|//Two definitions below are for OPM on MXM module designs
end_comment

begin_define
define|#
directive|define
name|EXT_HPDPIN_LUTINDEX_0
value|0
end_define

begin_define
define|#
directive|define
name|EXT_HPDPIN_LUTINDEX_1
value|1
end_define

begin_define
define|#
directive|define
name|EXT_HPDPIN_LUTINDEX_2
value|2
end_define

begin_define
define|#
directive|define
name|EXT_HPDPIN_LUTINDEX_3
value|3
end_define

begin_define
define|#
directive|define
name|EXT_HPDPIN_LUTINDEX_4
value|4
end_define

begin_define
define|#
directive|define
name|EXT_HPDPIN_LUTINDEX_5
value|5
end_define

begin_define
define|#
directive|define
name|EXT_HPDPIN_LUTINDEX_6
value|6
end_define

begin_define
define|#
directive|define
name|EXT_HPDPIN_LUTINDEX_7
value|7
end_define

begin_define
define|#
directive|define
name|MAX_NUMBER_OF_EXT_HPDPIN_LUT_ENTRIES
value|(EXT_HPDPIN_LUTINDEX_7+1)
end_define

begin_define
define|#
directive|define
name|EXT_AUXDDC_LUTINDEX_0
value|0
end_define

begin_define
define|#
directive|define
name|EXT_AUXDDC_LUTINDEX_1
value|1
end_define

begin_define
define|#
directive|define
name|EXT_AUXDDC_LUTINDEX_2
value|2
end_define

begin_define
define|#
directive|define
name|EXT_AUXDDC_LUTINDEX_3
value|3
end_define

begin_define
define|#
directive|define
name|EXT_AUXDDC_LUTINDEX_4
value|4
end_define

begin_define
define|#
directive|define
name|EXT_AUXDDC_LUTINDEX_5
value|5
end_define

begin_define
define|#
directive|define
name|EXT_AUXDDC_LUTINDEX_6
value|6
end_define

begin_define
define|#
directive|define
name|EXT_AUXDDC_LUTINDEX_7
value|7
end_define

begin_define
define|#
directive|define
name|MAX_NUMBER_OF_EXT_AUXDDC_LUT_ENTRIES
value|(EXT_AUXDDC_LUTINDEX_7+1)
end_define

begin_comment
comment|//ucChannelMapping are defined as following
end_comment

begin_comment
comment|//for DP connector, eDP, DP to VGA/LVDS
end_comment

begin_comment
comment|//Bit[1:0]: Define which pin connect to DP connector DP_Lane0, =0: source from GPU pin TX0, =1: from GPU pin TX1, =2: from GPU pin TX2, =3 from GPU pin TX3
end_comment

begin_comment
comment|//Bit[3:2]: Define which pin connect to DP connector DP_Lane1, =0: source from GPU pin TX0, =1: from GPU pin TX1, =2: from GPU pin TX2, =3 from GPU pin TX3
end_comment

begin_comment
comment|//Bit[5:4]: Define which pin connect to DP connector DP_Lane2, =0: source from GPU pin TX0, =1: from GPU pin TX1, =2: from GPU pin TX2, =3 from GPU pin TX3
end_comment

begin_comment
comment|//Bit[7:6]: Define which pin connect to DP connector DP_Lane3, =0: source from GPU pin TX0, =1: from GPU pin TX1, =2: from GPU pin TX2, =3 from GPU pin TX3
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DP_CONN_CHANNEL_MAPPING
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|ucDP_Lane3_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDP_Lane2_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDP_Lane1_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDP_Lane0_Source
range|:
literal|2
decl_stmt|;
else|#
directive|else
name|UCHAR
name|ucDP_Lane0_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDP_Lane1_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDP_Lane2_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDP_Lane3_Source
range|:
literal|2
decl_stmt|;
endif|#
directive|endif
block|}
name|ATOM_DP_CONN_CHANNEL_MAPPING
typedef|;
end_typedef

begin_comment
comment|//for DVI/HDMI, in dual link case, both links have to have same mapping.
end_comment

begin_comment
comment|//Bit[1:0]: Define which pin connect to DVI connector data Lane2, =0: source from GPU pin TX0, =1: from GPU pin TX1, =2: from GPU pin TX2, =3 from GPU pin TX3
end_comment

begin_comment
comment|//Bit[3:2]: Define which pin connect to DVI connector data Lane1, =0: source from GPU pin TX0, =1: from GPU pin TX1, =2: from GPU pin TX2, =3 from GPU pin TX3
end_comment

begin_comment
comment|//Bit[5:4]: Define which pin connect to DVI connector data Lane0, =0: source from GPU pin TX0, =1: from GPU pin TX1, =2: from GPU pin TX2, =3 from GPU pin TX3
end_comment

begin_comment
comment|//Bit[7:6]: Define which pin connect to DVI connector clock lane, =0: source from GPU pin TX0, =1: from GPU pin TX1, =2: from GPU pin TX2, =3 from GPU pin TX3
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DVI_CONN_CHANNEL_MAPPING
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|ucDVI_CLK_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDVI_DATA0_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDVI_DATA1_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDVI_DATA2_Source
range|:
literal|2
decl_stmt|;
else|#
directive|else
name|UCHAR
name|ucDVI_DATA2_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDVI_DATA1_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDVI_DATA0_Source
range|:
literal|2
decl_stmt|;
name|UCHAR
name|ucDVI_CLK_Source
range|:
literal|2
decl_stmt|;
endif|#
directive|endif
block|}
name|ATOM_DVI_CONN_CHANNEL_MAPPING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EXT_DISPLAY_PATH
block|{
name|USHORT
name|usDeviceTag
decl_stmt|;
comment|//A bit vector to show what devices are supported
name|USHORT
name|usDeviceACPIEnum
decl_stmt|;
comment|//16bit device ACPI id.
name|USHORT
name|usDeviceConnector
decl_stmt|;
comment|//A physical connector for displays to plug in, using object connector definitions
name|UCHAR
name|ucExtAUXDDCLutIndex
decl_stmt|;
comment|//An index into external AUX/DDC channel LUT
name|UCHAR
name|ucExtHPDPINLutIndex
decl_stmt|;
comment|//An index into external HPD pin LUT
name|USHORT
name|usExtEncoderObjId
decl_stmt|;
comment|//external encoder object id
union|union
block|{
name|UCHAR
name|ucChannelMapping
decl_stmt|;
comment|// if ucChannelMapping=0, using default one to one mapping
name|ATOM_DP_CONN_CHANNEL_MAPPING
name|asDPMapping
decl_stmt|;
name|ATOM_DVI_CONN_CHANNEL_MAPPING
name|asDVIMapping
decl_stmt|;
block|}
union|;
name|UCHAR
name|ucChPNInvert
decl_stmt|;
comment|// bit vector for up to 8 lanes, =0: P and N is not invert, =1 P and N is inverted
name|USHORT
name|usCaps
decl_stmt|;
name|USHORT
name|usReserved
decl_stmt|;
block|}
name|EXT_DISPLAY_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NUMBER_OF_UCHAR_FOR_GUID
value|16
end_define

begin_define
define|#
directive|define
name|MAX_NUMBER_OF_EXT_DISPLAY_PATH
value|7
end_define

begin_comment
comment|//usCaps
end_comment

begin_define
define|#
directive|define
name|EXT_DISPLAY_PATH_CAPS__HBR2_DISABLE
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_EXTERNAL_DISPLAY_CONNECTION_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|ucGuid
index|[
name|NUMBER_OF_UCHAR_FOR_GUID
index|]
decl_stmt|;
comment|// a GUID is a 16 byte long string
name|EXT_DISPLAY_PATH
name|sPath
index|[
name|MAX_NUMBER_OF_EXT_DISPLAY_PATH
index|]
decl_stmt|;
comment|// total of fixed 7 entries.
name|UCHAR
name|ucChecksum
decl_stmt|;
comment|// a  simple Checksum of the sum of whole structure equal to 0x0.
name|UCHAR
name|uc3DStereoPinId
decl_stmt|;
comment|// use for eDP panel
name|UCHAR
name|ucRemoteDisplayConfig
decl_stmt|;
name|UCHAR
name|uceDPToLVDSRxId
decl_stmt|;
name|UCHAR
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
comment|// for potential expansion
block|}
name|ATOM_EXTERNAL_DISPLAY_CONNECTION_INFO
typedef|;
end_typedef

begin_comment
comment|//Related definitions, all records are different but they have a commond header
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_COMMON_RECORD_HEADER
block|{
name|UCHAR
name|ucRecordType
decl_stmt|;
comment|//An emun to indicate the record type
name|UCHAR
name|ucRecordSize
decl_stmt|;
comment|//The size of the whole record in byte
block|}
name|ATOM_COMMON_RECORD_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_I2C_RECORD_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_HPD_INT_RECORD_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_OUTPUT_PROTECTION_RECORD_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_DEVICE_TAG_RECORD_TYPE
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_DVI_EXT_INPUT_RECORD_TYPE
value|5
end_define

begin_comment
comment|//Obsolete, switch to use GPIO_CNTL_RECORD_TYPE
end_comment

begin_define
define|#
directive|define
name|ATOM_ENCODER_FPGA_CONTROL_RECORD_TYPE
value|6
end_define

begin_comment
comment|//Obsolete, switch to use GPIO_CNTL_RECORD_TYPE
end_comment

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_CVTV_SHARE_DIN_RECORD_TYPE
value|7
end_define

begin_define
define|#
directive|define
name|ATOM_JTAG_RECORD_TYPE
value|8
end_define

begin_comment
comment|//Obsolete, switch to use GPIO_CNTL_RECORD_TYPE
end_comment

begin_define
define|#
directive|define
name|ATOM_OBJECT_GPIO_CNTL_RECORD_TYPE
value|9
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_DVO_CF_RECORD_TYPE
value|10
end_define

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_CF_RECORD_TYPE
value|11
end_define

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_HARDCODE_DTD_RECORD_TYPE
value|12
end_define

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_PCIE_SUBCONNECTOR_RECORD_TYPE
value|13
end_define

begin_define
define|#
directive|define
name|ATOM_ROUTER_DDC_PATH_SELECT_RECORD_TYPE
value|14
end_define

begin_define
define|#
directive|define
name|ATOM_ROUTER_DATA_CLOCK_PATH_SELECT_RECORD_TYPE
value|15
end_define

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_HPDPIN_LUT_RECORD_TYPE
value|16
end_define

begin_comment
comment|//This is for the case when connectors are not known to object table
end_comment

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_AUXDDC_LUT_RECORD_TYPE
value|17
end_define

begin_comment
comment|//This is for the case when connectors are not known to object table
end_comment

begin_define
define|#
directive|define
name|ATOM_OBJECT_LINK_RECORD_TYPE
value|18
end_define

begin_comment
comment|//Once this record is present under one object, it indicats the oobject is linked to another obj described by the record
end_comment

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_REMOTE_CAP_RECORD_TYPE
value|19
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_CAP_RECORD_TYPE
value|20
end_define

begin_comment
comment|//Must be updated when new record type is added,equal to that record definition!
end_comment

begin_define
define|#
directive|define
name|ATOM_MAX_OBJECT_RECORD_NUMBER
value|ATOM_ENCODER_CAP_RECORD_TYPE
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_I2C_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|ATOM_I2C_ID_CONFIG
name|sucI2cId
decl_stmt|;
name|UCHAR
name|ucI2CAddr
decl_stmt|;
comment|//The slave address, it's 0 when the record is attached to connector for DDC
block|}
name|ATOM_I2C_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_HPD_INT_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|UCHAR
name|ucHPDIntGPIOID
decl_stmt|;
comment|//Corresponding block in GPIO_PIN_INFO table gives the pin info
name|UCHAR
name|ucPlugged_PinState
decl_stmt|;
block|}
name|ATOM_HPD_INT_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_OUTPUT_PROTECTION_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|UCHAR
name|ucProtectionFlag
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|ATOM_OUTPUT_PROTECTION_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_DEVICE_TAG
block|{
name|ULONG
name|ulACPIDeviceEnum
decl_stmt|;
comment|//Reserved for now
name|USHORT
name|usDeviceID
decl_stmt|;
comment|//This Id is same as "ATOM_DEVICE_XXX_SUPPORT"
name|USHORT
name|usPadding
decl_stmt|;
block|}
name|ATOM_CONNECTOR_DEVICE_TAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_DEVICE_TAG_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|UCHAR
name|ucNumberOfDevice
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
name|ATOM_CONNECTOR_DEVICE_TAG
name|asDeviceTag
index|[
literal|1
index|]
decl_stmt|;
comment|//This Id is same as "ATOM_DEVICE_XXX_SUPPORT", 1 is only for allocation
block|}
name|ATOM_CONNECTOR_DEVICE_TAG_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_DVI_EXT_INPUT_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|UCHAR
name|ucConfigGPIOID
decl_stmt|;
name|UCHAR
name|ucConfigGPIOState
decl_stmt|;
comment|//Set to 1 when it's active high to enable external flow in
name|UCHAR
name|ucFlowinGPIPID
decl_stmt|;
name|UCHAR
name|ucExtInGPIPID
decl_stmt|;
block|}
name|ATOM_CONNECTOR_DVI_EXT_INPUT_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ENCODER_FPGA_CONTROL_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|UCHAR
name|ucCTL1GPIO_ID
decl_stmt|;
name|UCHAR
name|ucCTL1GPIOState
decl_stmt|;
comment|//Set to 1 when it's active high
name|UCHAR
name|ucCTL2GPIO_ID
decl_stmt|;
name|UCHAR
name|ucCTL2GPIOState
decl_stmt|;
comment|//Set to 1 when it's active high
name|UCHAR
name|ucCTL3GPIO_ID
decl_stmt|;
name|UCHAR
name|ucCTL3GPIOState
decl_stmt|;
comment|//Set to 1 when it's active high
name|UCHAR
name|ucCTLFPGA_IN_ID
decl_stmt|;
name|UCHAR
name|ucPadding
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ATOM_ENCODER_FPGA_CONTROL_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_CVTV_SHARE_DIN_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|UCHAR
name|ucGPIOID
decl_stmt|;
comment|//Corresponding block in GPIO_PIN_INFO table gives the pin info
name|UCHAR
name|ucTVActiveState
decl_stmt|;
comment|//Indicating when the pin==0 or 1 when TV is connected
block|}
name|ATOM_CONNECTOR_CVTV_SHARE_DIN_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_JTAG_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|UCHAR
name|ucTMSGPIO_ID
decl_stmt|;
name|UCHAR
name|ucTMSGPIOState
decl_stmt|;
comment|//Set to 1 when it's active high
name|UCHAR
name|ucTCKGPIO_ID
decl_stmt|;
name|UCHAR
name|ucTCKGPIOState
decl_stmt|;
comment|//Set to 1 when it's active high
name|UCHAR
name|ucTDOGPIO_ID
decl_stmt|;
name|UCHAR
name|ucTDOGPIOState
decl_stmt|;
comment|//Set to 1 when it's active high
name|UCHAR
name|ucTDIGPIO_ID
decl_stmt|;
name|UCHAR
name|ucTDIGPIOState
decl_stmt|;
comment|//Set to 1 when it's active high
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ATOM_JTAG_RECORD
typedef|;
end_typedef

begin_comment
comment|//The following generic object gpio pin control record type will replace JTAG_RECORD/FPGA_CONTROL_RECORD/DVI_EXT_INPUT_RECORD above gradually
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_GPIO_PIN_CONTROL_PAIR
block|{
name|UCHAR
name|ucGPIOID
decl_stmt|;
comment|// GPIO_ID, find the corresponding ID in GPIO_LUT table
name|UCHAR
name|ucGPIO_PinState
decl_stmt|;
comment|// Pin state showing how to set-up the pin
block|}
name|ATOM_GPIO_PIN_CONTROL_PAIR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_OBJECT_GPIO_CNTL_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|UCHAR
name|ucFlags
decl_stmt|;
comment|// Future expnadibility
name|UCHAR
name|ucNumberOfPins
decl_stmt|;
comment|// Number of GPIO pins used to control the object
name|ATOM_GPIO_PIN_CONTROL_PAIR
name|asGpio
index|[
literal|1
index|]
decl_stmt|;
comment|// the real gpio pin pair determined by number of pins ucNumberOfPins
block|}
name|ATOM_OBJECT_GPIO_CNTL_RECORD
typedef|;
end_typedef

begin_comment
comment|//Definitions for GPIO pin state
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_TYPE_INPUT
value|0x00
end_define

begin_define
define|#
directive|define
name|GPIO_PIN_TYPE_OUTPUT
value|0x10
end_define

begin_define
define|#
directive|define
name|GPIO_PIN_TYPE_HW_CONTROL
value|0x20
end_define

begin_comment
comment|//For GPIO_PIN_TYPE_OUTPUT the following is defined
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_OUTPUT_STATE_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|GPIO_PIN_OUTPUT_STATE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GPIO_PIN_STATE_ACTIVE_LOW
value|0x0
end_define

begin_define
define|#
directive|define
name|GPIO_PIN_STATE_ACTIVE_HIGH
value|0x1
end_define

begin_comment
comment|// Indexes to GPIO array in GLSync record
end_comment

begin_comment
comment|// GLSync record is for Frame Lock/Gen Lock feature.
end_comment

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_GLSYNC_REFCLK
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_GLSYNC_HSYNC
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_GLSYNC_VSYNC
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_GLSYNC_SWAP_REQ
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_GLSYNC_SWAP_GNT
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_GLSYNC_INTERRUPT
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_GLSYNC_V_RESET
value|6
end_define

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_GLSYNC_SWAP_CNTL
value|7
end_define

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_GLSYNC_SWAP_SEL
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_GPIO_INDEX_GLSYNC_MAX
value|9
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ENCODER_DVO_CF_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|ULONG
name|ulStrengthControl
decl_stmt|;
comment|// DVOA strength control for CF
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ATOM_ENCODER_DVO_CF_RECORD
typedef|;
end_typedef

begin_comment
comment|// Bit maps for ATOM_ENCODER_CAP_RECORD.ucEncoderCap
end_comment

begin_define
define|#
directive|define
name|ATOM_ENCODER_CAP_RECORD_HBR2
value|0x01
end_define

begin_comment
comment|// DP1.2 HBR2 is supported by HW encoder
end_comment

begin_define
define|#
directive|define
name|ATOM_ENCODER_CAP_RECORD_HBR2_EN
value|0x02
end_define

begin_comment
comment|// DP1.2 HBR2 setting is qualified and HBR2 can be enabled
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ENCODER_CAP_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
union|union
block|{
name|USHORT
name|usEncoderCap
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|USHORT
name|usReserved
range|:
literal|14
decl_stmt|;
comment|// Bit1-15 may be defined for other capability in future
name|USHORT
name|usHBR2En
range|:
literal|1
decl_stmt|;
comment|// Bit1 is for DP1.2 HBR2 enable
name|USHORT
name|usHBR2Cap
range|:
literal|1
decl_stmt|;
comment|// Bit0 is for DP1.2 HBR2 capability.
else|#
directive|else
name|USHORT
name|usHBR2Cap
range|:
literal|1
decl_stmt|;
comment|// Bit0 is for DP1.2 HBR2 capability.
name|USHORT
name|usHBR2En
range|:
literal|1
decl_stmt|;
comment|// Bit1 is for DP1.2 HBR2 enable
name|USHORT
name|usReserved
range|:
literal|14
decl_stmt|;
comment|// Bit1-15 may be defined for other capability in future
endif|#
directive|endif
block|}
struct|;
block|}
union|;
block|}
name|ATOM_ENCODER_CAP_RECORD
typedef|;
end_typedef

begin_comment
comment|// value for ATOM_CONNECTOR_CF_RECORD.ucConnectedDvoBundle
end_comment

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_CF_RECORD_CONNECTED_UPPER12BITBUNDLEA
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_CF_RECORD_CONNECTED_LOWER12BITBUNDLEB
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_CF_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|USHORT
name|usMaxPixClk
decl_stmt|;
name|UCHAR
name|ucFlowCntlGpioId
decl_stmt|;
name|UCHAR
name|ucSwapCntlGpioId
decl_stmt|;
name|UCHAR
name|ucConnectedDvoBundle
decl_stmt|;
name|UCHAR
name|ucPadding
decl_stmt|;
block|}
name|ATOM_CONNECTOR_CF_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_HARDCODE_DTD_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|ATOM_DTD_FORMAT
name|asTiming
decl_stmt|;
block|}
name|ATOM_CONNECTOR_HARDCODE_DTD_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_PCIE_SUBCONNECTOR_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
comment|//ATOM_CONNECTOR_PCIE_SUBCONNECTOR_RECORD_TYPE
name|UCHAR
name|ucSubConnectorType
decl_stmt|;
comment|//CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_D|X_ID_DUAL_LINK_DVI_D|HDMI_TYPE_A
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|ATOM_CONNECTOR_PCIE_SUBCONNECTOR_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ROUTER_DDC_PATH_SELECT_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|UCHAR
name|ucMuxType
decl_stmt|;
comment|//decide the number of ucMuxState, =0, no pin state, =1: single state with complement,>1: multiple state
name|UCHAR
name|ucMuxControlPin
decl_stmt|;
name|UCHAR
name|ucMuxState
index|[
literal|2
index|]
decl_stmt|;
comment|//for alligment purpose
block|}
name|ATOM_ROUTER_DDC_PATH_SELECT_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ROUTER_DATA_CLOCK_PATH_SELECT_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|UCHAR
name|ucMuxType
decl_stmt|;
name|UCHAR
name|ucMuxControlPin
decl_stmt|;
name|UCHAR
name|ucMuxState
index|[
literal|2
index|]
decl_stmt|;
comment|//for alligment purpose
block|}
name|ATOM_ROUTER_DATA_CLOCK_PATH_SELECT_RECORD
typedef|;
end_typedef

begin_comment
comment|// define ucMuxType
end_comment

begin_define
define|#
directive|define
name|ATOM_ROUTER_MUX_PIN_STATE_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|ATOM_ROUTER_MUX_PIN_SINGLE_STATE_COMPLEMENT
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_HPDPIN_LUT_RECORD
comment|//record for ATOM_CONNECTOR_HPDPIN_LUT_RECORD_TYPE
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|UCHAR
name|ucHPDPINMap
index|[
name|MAX_NUMBER_OF_EXT_HPDPIN_LUT_ENTRIES
index|]
decl_stmt|;
comment|//An fixed size array which maps external pins to internal GPIO_PIN_INFO table
block|}
name|ATOM_CONNECTOR_HPDPIN_LUT_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_AUXDDC_LUT_RECORD
comment|//record for ATOM_CONNECTOR_AUXDDC_LUT_RECORD_TYPE
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|ATOM_I2C_ID_CONFIG
name|ucAUXDDCMap
index|[
name|MAX_NUMBER_OF_EXT_AUXDDC_LUT_ENTRIES
index|]
decl_stmt|;
comment|//An fixed size array which maps external pins to internal DDC ID
block|}
name|ATOM_CONNECTOR_AUXDDC_LUT_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_OBJECT_LINK_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|USHORT
name|usObjectID
decl_stmt|;
comment|//could be connector, encorder or other object in object.h
block|}
name|ATOM_OBJECT_LINK_RECORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_REMOTE_CAP_RECORD
block|{
name|ATOM_COMMON_RECORD_HEADER
name|sheader
decl_stmt|;
name|USHORT
name|usReserved
decl_stmt|;
block|}
name|ATOM_CONNECTOR_REMOTE_CAP_RECORD
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// ASIC voltage data table
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VOLTAGE_INFO_HEADER
block|{
name|USHORT
name|usVDDCBaseLevel
decl_stmt|;
comment|//In number of 50mv unit
name|USHORT
name|usReserved
decl_stmt|;
comment|//For possible extension table offset
name|UCHAR
name|ucNumOfVoltageEntries
decl_stmt|;
name|UCHAR
name|ucBytesPerVoltageEntry
decl_stmt|;
name|UCHAR
name|ucVoltageStep
decl_stmt|;
comment|//Indicating in how many mv increament is one step, 0.5mv unit
name|UCHAR
name|ucDefaultVoltageEntry
decl_stmt|;
name|UCHAR
name|ucVoltageControlI2cLine
decl_stmt|;
name|UCHAR
name|ucVoltageControlAddress
decl_stmt|;
name|UCHAR
name|ucVoltageControlOffset
decl_stmt|;
block|}
name|ATOM_VOLTAGE_INFO_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VOLTAGE_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_VOLTAGE_INFO_HEADER
name|viHeader
decl_stmt|;
name|UCHAR
name|ucVoltageEntries
index|[
literal|64
index|]
decl_stmt|;
comment|//64 is for allocation, the actual number of entry is present at ucNumOfVoltageEntries*ucBytesPerVoltageEntry
block|}
name|ATOM_VOLTAGE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VOLTAGE_FORMULA
block|{
name|USHORT
name|usVoltageBaseLevel
decl_stmt|;
comment|// In number of 1mv unit
name|USHORT
name|usVoltageStep
decl_stmt|;
comment|// Indicating in how many mv increament is one step, 1mv unit
name|UCHAR
name|ucNumOfVoltageEntries
decl_stmt|;
comment|// Number of Voltage Entry, which indicate max Voltage
name|UCHAR
name|ucFlag
decl_stmt|;
comment|// bit0=0 :step is 1mv =1 0.5mv
name|UCHAR
name|ucBaseVID
decl_stmt|;
comment|// if there is no lookup table, VID= BaseVID + ( Vol - BaseLevle ) /VoltageStep
name|UCHAR
name|ucReserved
decl_stmt|;
name|UCHAR
name|ucVIDAdjustEntries
index|[
literal|32
index|]
decl_stmt|;
comment|// 32 is for allocation, the actual number of entry is present at ucNumOfVoltageEntries
block|}
name|ATOM_VOLTAGE_FORMULA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_VOLTAGE_LUT_ENTRY
block|{
name|USHORT
name|usVoltageCode
decl_stmt|;
comment|// The Voltage ID, either GPIO or I2C code
name|USHORT
name|usVoltageValue
decl_stmt|;
comment|// The corresponding Voltage Value, in mV
block|}
name|VOLTAGE_LUT_ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VOLTAGE_FORMULA_V2
block|{
name|UCHAR
name|ucNumOfVoltageEntries
decl_stmt|;
comment|// Number of Voltage Entry, which indicate max Voltage
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
name|VOLTAGE_LUT_ENTRY
name|asVIDAdjustEntries
index|[
literal|32
index|]
decl_stmt|;
comment|// 32 is for allocation, the actual number of entries is in ucNumOfVoltageEntries
block|}
name|ATOM_VOLTAGE_FORMULA_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VOLTAGE_CONTROL
block|{
name|UCHAR
name|ucVoltageControlId
decl_stmt|;
comment|//Indicate it is controlled by I2C or GPIO or HW state machine
name|UCHAR
name|ucVoltageControlI2cLine
decl_stmt|;
name|UCHAR
name|ucVoltageControlAddress
decl_stmt|;
name|UCHAR
name|ucVoltageControlOffset
decl_stmt|;
name|USHORT
name|usGpioPin_AIndex
decl_stmt|;
comment|//GPIO_PAD register index
name|UCHAR
name|ucGpioPinBitShift
index|[
literal|9
index|]
decl_stmt|;
comment|//at most 8 pin support 255 VIDs, termintate with 0xff
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|ATOM_VOLTAGE_CONTROL
typedef|;
end_typedef

begin_comment
comment|// Define ucVoltageControlId
end_comment

begin_define
define|#
directive|define
name|VOLTAGE_CONTROLLED_BY_HW
value|0x00
end_define

begin_define
define|#
directive|define
name|VOLTAGE_CONTROLLED_BY_I2C_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|VOLTAGE_CONTROLLED_BY_GPIO
value|0x80
end_define

begin_define
define|#
directive|define
name|VOLTAGE_CONTROL_ID_LM64
value|0x01
end_define

begin_comment
comment|//I2C control, used for R5xx Core Voltage
end_comment

begin_define
define|#
directive|define
name|VOLTAGE_CONTROL_ID_DAC
value|0x02
end_define

begin_comment
comment|//I2C control, used for R5xx/R6xx MVDDC,MVDDQ or VDDCI
end_comment

begin_define
define|#
directive|define
name|VOLTAGE_CONTROL_ID_VT116xM
value|0x03
end_define

begin_comment
comment|//I2C control, used for R6xx Core Voltage
end_comment

begin_define
define|#
directive|define
name|VOLTAGE_CONTROL_ID_DS4402
value|0x04
end_define

begin_define
define|#
directive|define
name|VOLTAGE_CONTROL_ID_UP6266
value|0x05
end_define

begin_define
define|#
directive|define
name|VOLTAGE_CONTROL_ID_SCORPIO
value|0x06
end_define

begin_define
define|#
directive|define
name|VOLTAGE_CONTROL_ID_VT1556M
value|0x07
end_define

begin_define
define|#
directive|define
name|VOLTAGE_CONTROL_ID_CHL822x
value|0x08
end_define

begin_define
define|#
directive|define
name|VOLTAGE_CONTROL_ID_VT1586M
value|0x09
end_define

begin_define
define|#
directive|define
name|VOLTAGE_CONTROL_ID_UP1637
value|0x0A
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VOLTAGE_OBJECT
block|{
name|UCHAR
name|ucVoltageType
decl_stmt|;
comment|//Indicate Voltage Source: VDDC, MVDDC, MVDDQ or MVDDCI
name|UCHAR
name|ucSize
decl_stmt|;
comment|//Size of Object
name|ATOM_VOLTAGE_CONTROL
name|asControl
decl_stmt|;
comment|//describ how to control
name|ATOM_VOLTAGE_FORMULA
name|asFormula
decl_stmt|;
comment|//Indicate How to convert real Voltage to VID
block|}
name|ATOM_VOLTAGE_OBJECT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VOLTAGE_OBJECT_V2
block|{
name|UCHAR
name|ucVoltageType
decl_stmt|;
comment|//Indicate Voltage Source: VDDC, MVDDC, MVDDQ or MVDDCI
name|UCHAR
name|ucSize
decl_stmt|;
comment|//Size of Object
name|ATOM_VOLTAGE_CONTROL
name|asControl
decl_stmt|;
comment|//describ how to control
name|ATOM_VOLTAGE_FORMULA_V2
name|asFormula
decl_stmt|;
comment|//Indicate How to convert real Voltage to VID
block|}
name|ATOM_VOLTAGE_OBJECT_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VOLTAGE_OBJECT_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_VOLTAGE_OBJECT
name|asVoltageObj
index|[
literal|3
index|]
decl_stmt|;
comment|//Info for Voltage control
block|}
name|ATOM_VOLTAGE_OBJECT_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VOLTAGE_OBJECT_INFO_V2
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_VOLTAGE_OBJECT_V2
name|asVoltageObj
index|[
literal|3
index|]
decl_stmt|;
comment|//Info for Voltage control
block|}
name|ATOM_VOLTAGE_OBJECT_INFO_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_LEAKID_VOLTAGE
block|{
name|UCHAR
name|ucLeakageId
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
name|USHORT
name|usVoltage
decl_stmt|;
block|}
name|ATOM_LEAKID_VOLTAGE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VOLTAGE_OBJECT_HEADER_V3
block|{
name|UCHAR
name|ucVoltageType
decl_stmt|;
comment|//Indicate Voltage Source: VDDC, MVDDC, MVDDQ or MVDDCI
name|UCHAR
name|ucVoltageMode
decl_stmt|;
comment|//Indicate voltage control mode: Init/Set/Leakage/Set phase
name|USHORT
name|usSize
decl_stmt|;
comment|//Size of Object
block|}
name|ATOM_VOLTAGE_OBJECT_HEADER_V3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_VOLTAGE_LUT_ENTRY_V2
block|{
name|ULONG
name|ulVoltageId
decl_stmt|;
comment|// The Voltage ID which is used to program GPIO register
name|USHORT
name|usVoltageValue
decl_stmt|;
comment|// The corresponding Voltage Value, in mV
block|}
name|VOLTAGE_LUT_ENTRY_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_LEAKAGE_VOLTAGE_LUT_ENTRY_V2
block|{
name|USHORT
name|usVoltageLevel
decl_stmt|;
comment|// The Voltage ID which is used to program GPIO register
name|USHORT
name|usVoltageId
decl_stmt|;
name|USHORT
name|usLeakageId
decl_stmt|;
comment|// The corresponding Voltage Value, in mV
block|}
name|LEAKAGE_VOLTAGE_LUT_ENTRY_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_I2C_VOLTAGE_OBJECT_V3
block|{
name|ATOM_VOLTAGE_OBJECT_HEADER_V3
name|sHeader
decl_stmt|;
name|UCHAR
name|ucVoltageRegulatorId
decl_stmt|;
comment|//Indicate Voltage Regulator Id
name|UCHAR
name|ucVoltageControlI2cLine
decl_stmt|;
name|UCHAR
name|ucVoltageControlAddress
decl_stmt|;
name|UCHAR
name|ucVoltageControlOffset
decl_stmt|;
name|ULONG
name|ulReserved
decl_stmt|;
name|VOLTAGE_LUT_ENTRY
name|asVolI2cLut
index|[
literal|1
index|]
decl_stmt|;
comment|// end with 0xff
block|}
name|ATOM_I2C_VOLTAGE_OBJECT_V3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_GPIO_VOLTAGE_OBJECT_V3
block|{
name|ATOM_VOLTAGE_OBJECT_HEADER_V3
name|sHeader
decl_stmt|;
name|UCHAR
name|ucVoltageGpioCntlId
decl_stmt|;
comment|// default is 0 which indicate control through CG VID mode
name|UCHAR
name|ucGpioEntryNum
decl_stmt|;
comment|// indiate the entry numbers of Votlage/Gpio value Look up table
name|UCHAR
name|ucPhaseDelay
decl_stmt|;
comment|// phase delay in unit of micro second
name|UCHAR
name|ucReserved
decl_stmt|;
name|ULONG
name|ulGpioMaskVal
decl_stmt|;
comment|// GPIO Mask value
name|VOLTAGE_LUT_ENTRY_V2
name|asVolGpioLut
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_GPIO_VOLTAGE_OBJECT_V3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_LEAKAGE_VOLTAGE_OBJECT_V3
block|{
name|ATOM_VOLTAGE_OBJECT_HEADER_V3
name|sHeader
decl_stmt|;
name|UCHAR
name|ucLeakageCntlId
decl_stmt|;
comment|// default is 0
name|UCHAR
name|ucLeakageEntryNum
decl_stmt|;
comment|// indicate the entry number of LeakageId/Voltage Lut table
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
name|ULONG
name|ulMaxVoltageLevel
decl_stmt|;
name|LEAKAGE_VOLTAGE_LUT_ENTRY_V2
name|asLeakageIdLut
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_LEAKAGE_VOLTAGE_OBJECT_V3
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_ATOM_VOLTAGE_OBJECT_V3
block|{
name|ATOM_GPIO_VOLTAGE_OBJECT_V3
name|asGpioVoltageObj
decl_stmt|;
name|ATOM_I2C_VOLTAGE_OBJECT_V3
name|asI2cVoltageObj
decl_stmt|;
name|ATOM_LEAKAGE_VOLTAGE_OBJECT_V3
name|asLeakageObj
decl_stmt|;
block|}
name|ATOM_VOLTAGE_OBJECT_V3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VOLTAGE_OBJECT_INFO_V3_1
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_VOLTAGE_OBJECT_V3
name|asVoltageObj
index|[
literal|3
index|]
decl_stmt|;
comment|//Info for Voltage control
block|}
name|ATOM_VOLTAGE_OBJECT_INFO_V3_1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ASIC_PROFILE_VOLTAGE
block|{
name|UCHAR
name|ucProfileId
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
name|USHORT
name|usSize
decl_stmt|;
name|USHORT
name|usEfuseSpareStartAddr
decl_stmt|;
name|USHORT
name|usFuseIndex
index|[
literal|8
index|]
decl_stmt|;
comment|//from LSB to MSB, Max 8bit,end of 0xffff if less than 8 efuse id,
name|ATOM_LEAKID_VOLTAGE
name|asLeakVol
index|[
literal|2
index|]
decl_stmt|;
comment|//Leakid and relatd voltage
block|}
name|ATOM_ASIC_PROFILE_VOLTAGE
typedef|;
end_typedef

begin_comment
comment|//ucProfileId
end_comment

begin_define
define|#
directive|define
name|ATOM_ASIC_PROFILE_ID_EFUSE_VOLTAGE
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_ASIC_PROFILE_ID_EFUSE_PERFORMANCE_VOLTAGE
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_ASIC_PROFILE_ID_EFUSE_THERMAL_VOLTAGE
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ASIC_PROFILING_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|asHeader
decl_stmt|;
name|ATOM_ASIC_PROFILE_VOLTAGE
name|asVoltage
decl_stmt|;
block|}
name|ATOM_ASIC_PROFILING_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_POWER_SOURCE_OBJECT
block|{
name|UCHAR
name|ucPwrSrcId
decl_stmt|;
comment|// Power source
name|UCHAR
name|ucPwrSensorType
decl_stmt|;
comment|// GPIO, I2C or none
name|UCHAR
name|ucPwrSensId
decl_stmt|;
comment|// if GPIO detect, it is GPIO id,  if I2C detect, it is I2C id
name|UCHAR
name|ucPwrSensSlaveAddr
decl_stmt|;
comment|// Slave address if I2C detect
name|UCHAR
name|ucPwrSensRegIndex
decl_stmt|;
comment|// I2C register Index if I2C detect
name|UCHAR
name|ucPwrSensRegBitMask
decl_stmt|;
comment|// detect which bit is used if I2C detect
name|UCHAR
name|ucPwrSensActiveState
decl_stmt|;
comment|// high active or low active
name|UCHAR
name|ucReserve
index|[
literal|3
index|]
decl_stmt|;
comment|// reserve
name|USHORT
name|usSensPwr
decl_stmt|;
comment|// in unit of watt
block|}
name|ATOM_POWER_SOURCE_OBJECT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_POWER_SOURCE_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|asHeader
decl_stmt|;
name|UCHAR
name|asPwrbehave
index|[
literal|16
index|]
decl_stmt|;
name|ATOM_POWER_SOURCE_OBJECT
name|asPwrObj
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_POWER_SOURCE_INFO
typedef|;
end_typedef

begin_comment
comment|//Define ucPwrSrcId
end_comment

begin_define
define|#
directive|define
name|POWERSOURCE_PCIE_ID1
value|0x00
end_define

begin_define
define|#
directive|define
name|POWERSOURCE_6PIN_CONNECTOR_ID1
value|0x01
end_define

begin_define
define|#
directive|define
name|POWERSOURCE_8PIN_CONNECTOR_ID1
value|0x02
end_define

begin_define
define|#
directive|define
name|POWERSOURCE_6PIN_CONNECTOR_ID2
value|0x04
end_define

begin_define
define|#
directive|define
name|POWERSOURCE_8PIN_CONNECTOR_ID2
value|0x08
end_define

begin_comment
comment|//define ucPwrSensorId
end_comment

begin_define
define|#
directive|define
name|POWER_SENSOR_ALWAYS
value|0x00
end_define

begin_define
define|#
directive|define
name|POWER_SENSOR_GPIO
value|0x01
end_define

begin_define
define|#
directive|define
name|POWER_SENSOR_I2C
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CLK_VOLT_CAPABILITY
block|{
name|ULONG
name|ulVoltageIndex
decl_stmt|;
comment|// The Voltage Index indicated by FUSE, same voltage index shared with SCLK DPM fuse table
name|ULONG
name|ulMaximumSupportedCLK
decl_stmt|;
comment|// Maximum clock supported with specified voltage index, unit in 10kHz
block|}
name|ATOM_CLK_VOLT_CAPABILITY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_AVAILABLE_SCLK_LIST
block|{
name|ULONG
name|ulSupportedSCLK
decl_stmt|;
comment|// Maximum clock supported with specified voltage index,  unit in 10kHz
name|USHORT
name|usVoltageIndex
decl_stmt|;
comment|// The Voltage Index indicated by FUSE for specified SCLK
name|USHORT
name|usVoltageID
decl_stmt|;
comment|// The Voltage ID indicated by FUSE for specified SCLK
block|}
name|ATOM_AVAILABLE_SCLK_LIST
typedef|;
end_typedef

begin_comment
comment|// ATOM_INTEGRATED_SYSTEM_INFO_V6 ulSystemConfig cap definition
end_comment

begin_define
define|#
directive|define
name|ATOM_IGP_INFO_V6_SYSTEM_CONFIG__PCIE_POWER_GATING_ENABLE
value|1
end_define

begin_comment
comment|// refer to ulSystemConfig bit[0]
end_comment

begin_comment
comment|// this IntegrateSystemInfoTable is used for Liano/Ontario APU
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_INTEGRATED_SYSTEM_INFO_V6
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulBootUpEngineClock
decl_stmt|;
name|ULONG
name|ulDentistVCOFreq
decl_stmt|;
name|ULONG
name|ulBootUpUMAClock
decl_stmt|;
name|ATOM_CLK_VOLT_CAPABILITY
name|sDISPCLK_Voltage
index|[
literal|4
index|]
decl_stmt|;
name|ULONG
name|ulBootUpReqDisplayVector
decl_stmt|;
name|ULONG
name|ulOtherDisplayMisc
decl_stmt|;
name|ULONG
name|ulGPUCapInfo
decl_stmt|;
name|ULONG
name|ulSB_MMIO_Base_Addr
decl_stmt|;
name|USHORT
name|usRequestedPWMFreqInHz
decl_stmt|;
name|UCHAR
name|ucHtcTmpLmt
decl_stmt|;
name|UCHAR
name|ucHtcHystLmt
decl_stmt|;
name|ULONG
name|ulMinEngineClock
decl_stmt|;
name|ULONG
name|ulSystemConfig
decl_stmt|;
name|ULONG
name|ulCPUCapInfo
decl_stmt|;
name|USHORT
name|usNBP0Voltage
decl_stmt|;
name|USHORT
name|usNBP1Voltage
decl_stmt|;
name|USHORT
name|usBootUpNBVoltage
decl_stmt|;
name|USHORT
name|usExtDispConnInfoOffset
decl_stmt|;
name|USHORT
name|usPanelRefreshRateRange
decl_stmt|;
name|UCHAR
name|ucMemoryType
decl_stmt|;
name|UCHAR
name|ucUMAChannelNumber
decl_stmt|;
name|ULONG
name|ulCSR_M3_ARB_CNTL_DEFAULT
index|[
literal|10
index|]
decl_stmt|;
name|ULONG
name|ulCSR_M3_ARB_CNTL_UVD
index|[
literal|10
index|]
decl_stmt|;
name|ULONG
name|ulCSR_M3_ARB_CNTL_FS3D
index|[
literal|10
index|]
decl_stmt|;
name|ATOM_AVAILABLE_SCLK_LIST
name|sAvail_SCLK
index|[
literal|5
index|]
decl_stmt|;
name|ULONG
name|ulGMCRestoreResetTime
decl_stmt|;
name|ULONG
name|ulMinimumNClk
decl_stmt|;
name|ULONG
name|ulIdleNClk
decl_stmt|;
name|ULONG
name|ulDDR_DLL_PowerUpTime
decl_stmt|;
name|ULONG
name|ulDDR_PLL_PowerUpTime
decl_stmt|;
name|USHORT
name|usPCIEClkSSPercentage
decl_stmt|;
name|USHORT
name|usPCIEClkSSType
decl_stmt|;
name|USHORT
name|usLvdsSSPercentage
decl_stmt|;
name|USHORT
name|usLvdsSSpreadRateIn10Hz
decl_stmt|;
name|USHORT
name|usHDMISSPercentage
decl_stmt|;
name|USHORT
name|usHDMISSpreadRateIn10Hz
decl_stmt|;
name|USHORT
name|usDVISSPercentage
decl_stmt|;
name|USHORT
name|usDVISSpreadRateIn10Hz
decl_stmt|;
name|ULONG
name|SclkDpmBoostMargin
decl_stmt|;
name|ULONG
name|SclkDpmThrottleMargin
decl_stmt|;
name|USHORT
name|SclkDpmTdpLimitPG
decl_stmt|;
name|USHORT
name|SclkDpmTdpLimitBoost
decl_stmt|;
name|ULONG
name|ulBoostEngineCLock
decl_stmt|;
name|UCHAR
name|ulBoostVid_2bit
decl_stmt|;
name|UCHAR
name|EnableBoost
decl_stmt|;
name|USHORT
name|GnbTdpLimit
decl_stmt|;
name|USHORT
name|usMaxLVDSPclkFreqInSingleLink
decl_stmt|;
name|UCHAR
name|ucLvdsMisc
decl_stmt|;
name|UCHAR
name|ucLVDSReserved
decl_stmt|;
name|ULONG
name|ulReserved3
index|[
literal|15
index|]
decl_stmt|;
name|ATOM_EXTERNAL_DISPLAY_CONNECTION_INFO
name|sExtDispConnInfo
decl_stmt|;
block|}
name|ATOM_INTEGRATED_SYSTEM_INFO_V6
typedef|;
end_typedef

begin_comment
comment|// ulGPUCapInfo
end_comment

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO_V6_GPUCAPINFO__TMDSHDMI_COHERENT_SINGLEPLL_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO_V6_GPUCAPINFO__DISABLE_AUX_HW_MODE_DETECTION
value|0x08
end_define

begin_comment
comment|//ucLVDSMisc:
end_comment

begin_define
define|#
directive|define
name|SYS_INFO_LVDSMISC__888_FPDI_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|SYS_INFO_LVDSMISC__DL_CH_SWAP
value|0x02
end_define

begin_define
define|#
directive|define
name|SYS_INFO_LVDSMISC__888_BPC
value|0x04
end_define

begin_define
define|#
directive|define
name|SYS_INFO_LVDSMISC__OVERRIDE_EN
value|0x08
end_define

begin_define
define|#
directive|define
name|SYS_INFO_LVDSMISC__BLON_ACTIVE_LOW
value|0x10
end_define

begin_comment
comment|// not used any more
end_comment

begin_define
define|#
directive|define
name|SYS_INFO_LVDSMISC__VSYNC_ACTIVE_LOW
value|0x04
end_define

begin_define
define|#
directive|define
name|SYS_INFO_LVDSMISC__HSYNC_ACTIVE_LOW
value|0x08
end_define

begin_comment
comment|/**********************************************************************************************************************   ATOM_INTEGRATED_SYSTEM_INFO_V6 Description ulBootUpEngineClock:              VBIOS bootup Engine clock frequency, in 10kHz unit. if it is equal 0, then VBIOS use pre-defined bootup engine clock ulDentistVCOFreq:                 Dentist VCO clock in 10kHz unit.  ulBootUpUMAClock:                 System memory boot up clock frequency in 10Khz unit.  sDISPCLK_Voltage:                 Report Display clock voltage requirement.   ulBootUpReqDisplayVector:         VBIOS boot up display IDs, following are supported devices in Liano/Ontaio projects:                                   ATOM_DEVICE_CRT1_SUPPORT                  0x0001                                   ATOM_DEVICE_CRT2_SUPPORT                  0x0010                                   ATOM_DEVICE_DFP1_SUPPORT                  0x0008                                    ATOM_DEVICE_DFP6_SUPPORT                  0x0040                                    ATOM_DEVICE_DFP2_SUPPORT                  0x0080                                          ATOM_DEVICE_DFP3_SUPPORT                  0x0200                                          ATOM_DEVICE_DFP4_SUPPORT                  0x0400                                           ATOM_DEVICE_DFP5_SUPPORT                  0x0800                                   ATOM_DEVICE_LCD1_SUPPORT                  0x0002 ulOtherDisplayMisc:      	        Other display related flags, not defined yet.  ulGPUCapInfo:                     bit[0]=0: TMDS/HDMI Coherent Mode use cascade PLL mode.                                         =1: TMDS/HDMI Coherent Mode use signel PLL mode.                                   bit[3]=0: Enable HW AUX mode detection logic                                         =1: Disable HW AUX mode dettion logic ulSB_MMIO_Base_Addr:              Physical Base address to SB MMIO space. Driver needs to initialize it for SMU usage.  usRequestedPWMFreqInHz:           When it's set to 0x0 by SBIOS: the LCD BackLight is not controlled by GPU(SW).                                    Any attempt to change BL using VBIOS function or enable VariBri from PP table is not effective since ATOM_BIOS_INFO_BL_CONTROLLED_BY_GPU==0;                                                                      When it's set to a non-zero frequency, the BackLight is controlled by GPU (SW) in one of two ways below:                                   1. SW uses the GPU BL PWM output to control the BL, in chis case, this non-zero frequency determines what freq GPU should use;                                   VBIOS will set up proper PWM frequency and ATOM_BIOS_INFO_BL_CONTROLLED_BY_GPU==1,as the result,                                   Changing BL using VBIOS function is functional in both driver and non-driver present environment;                                    and enabling VariBri under the driver environment from PP table is optional.                                    2. SW uses other means to control BL (like DPCD),this non-zero frequency serves as a flag only indicating                                   that BL control from GPU is expected.                                   VBIOS will NOT set up PWM frequency but make ATOM_BIOS_INFO_BL_CONTROLLED_BY_GPU==1                                   Changing BL using VBIOS function could be functional in both driver and non-driver present environment,but                                   it's per platform                                    and enabling VariBri under the driver environment from PP table is optional.  ucHtcTmpLmt:                      Refer to D18F3x64 bit[22:16], HtcTmpLmt.                                    Threshold on value to enter HTC_active state. ucHtcHystLmt:                     Refer to D18F3x64 bit[27:24], HtcHystLmt.                                    To calculate threshold off value to exit HTC_active state, which is Threshold on vlaue minus ucHtcHystLmt. ulMinEngineClock:                 Minimum SCLK allowed in 10kHz unit. This is calculated based on WRCK Fuse settings. ulSystemConfig:                   Bit[0]=0: PCIE Power Gating Disabled                                          =1: PCIE Power Gating Enabled                                   Bit[1]=0: DDR-DLL shut-down feature disabled.                                          1: DDR-DLL shut-down feature enabled.                                   Bit[2]=0: DDR-PLL Power down feature disabled.                                          1: DDR-PLL Power down feature enabled.                                  ulCPUCapInfo:                     TBD usNBP0Voltage:                    VID for voltage on NB P0 State usNBP1Voltage:                    VID for voltage on NB P1 State   usBootUpNBVoltage:                Voltage Index of GNB voltage configured by SBIOS, which is suffcient to support VBIOS DISPCLK requirement. usExtDispConnInfoOffset:          Offset to sExtDispConnInfo inside the structure usPanelRefreshRateRange:          Bit vector for LCD supported refresh rate range. If DRR is requestd by the platform, at least two bits need to be set                                   to indicate a range.                                   SUPPORTED_LCD_REFRESHRATE_30Hz          0x0004                                   SUPPORTED_LCD_REFRESHRATE_40Hz          0x0008                                   SUPPORTED_LCD_REFRESHRATE_50Hz          0x0010                                   SUPPORTED_LCD_REFRESHRATE_60Hz          0x0020 ucMemoryType:                     [3:0]=1:DDR1;=2:DDR2;=3:DDR3.[7:4] is reserved. ucUMAChannelNumber:      	        System memory channel numbers.  ulCSR_M3_ARB_CNTL_DEFAULT[10]:    Arrays with values for CSR M3 arbiter for default ulCSR_M3_ARB_CNTL_UVD[10]:        Arrays with values for CSR M3 arbiter for UVD playback. ulCSR_M3_ARB_CNTL_FS3D[10]:       Arrays with values for CSR M3 arbiter for Full Screen 3D applications. sAvail_SCLK[5]:                   Arrays to provide availabe list of SLCK and corresponding voltage, order from low to high   ulGMCRestoreResetTime:            GMC power restore and GMC reset time to calculate data reconnection latency. Unit in ns.  ulMinimumNClk:                    Minimum NCLK speed among all NB-Pstates to calcualte data reconnection latency. Unit in 10kHz.  ulIdleNClk:                       NCLK speed while memory runs in self-refresh state. Unit in 10kHz. ulDDR_DLL_PowerUpTime:            DDR PHY DLL power up time. Unit in ns. ulDDR_PLL_PowerUpTime:            DDR PHY PLL power up time. Unit in ns. usPCIEClkSSPercentage:            PCIE Clock Spred Spectrum Percentage in unit 0.01%; 100 mean 1%. usPCIEClkSSType:                  PCIE Clock Spred Spectrum Type. 0 for Down spread(default); 1 for Center spread. usLvdsSSPercentage:               LVDS panel ( not include eDP ) Spread Spectrum Percentage in unit of 0.01%, =0, use VBIOS default setting.  usLvdsSSpreadRateIn10Hz:          LVDS panel ( not include eDP ) Spread Spectrum frequency in unit of 10Hz, =0, use VBIOS default setting.  usHDMISSPercentage:               HDMI Spread Spectrum Percentage in unit 0.01%; 100 mean 1%,  =0, use VBIOS default setting.  usHDMISSpreadRateIn10Hz:          HDMI Spread Spectrum frequency in unit of 10Hz,  =0, use VBIOS default setting.  usDVISSPercentage:                DVI Spread Spectrum Percentage in unit 0.01%; 100 mean 1%,  =0, use VBIOS default setting.  usDVISSpreadRateIn10Hz:           DVI Spread Spectrum frequency in unit of 10Hz,  =0, use VBIOS default setting.  usMaxLVDSPclkFreqInSingleLink:    Max pixel clock LVDS panel single link, if=0 means VBIOS use default threhold, right now it is 85Mhz ucLVDSMisc:                       [bit0] LVDS 888bit panel mode =0: LVDS 888 panel in LDI mode, =1: LVDS 888 panel in FPDI mode                                   [bit1] LVDS panel lower and upper link mapping =0: lower link and upper link not swap, =1: lower link and upper link are swapped                                   [bit2] LVDS 888bit per color mode  =0: 666 bit per color =1:888 bit per color                                   [bit3] LVDS parameter override enable  =0: ucLvdsMisc parameter are not used =1: ucLvdsMisc parameter should be used                                   [bit4] Polarity of signal sent to digital BLON output pin. =0: not inverted(active high) =1: inverted ( active low ) **********************************************************************************************************************/
end_comment

begin_comment
comment|// this Table is used for Liano/Ontario APU
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_FUSION_SYSTEM_INFO_V1
block|{
name|ATOM_INTEGRATED_SYSTEM_INFO_V6
name|sIntegratedSysInfo
decl_stmt|;
name|ULONG
name|ulPowerplayTable
index|[
literal|128
index|]
decl_stmt|;
block|}
name|ATOM_FUSION_SYSTEM_INFO_V1
typedef|;
end_typedef

begin_comment
comment|/**********************************************************************************************************************   ATOM_FUSION_SYSTEM_INFO_V1 Description sIntegratedSysInfo:               refer to ATOM_INTEGRATED_SYSTEM_INFO_V6 definition. ulPowerplayTable[128]:            This 512 bytes memory is used to save ATOM_PPLIB_POWERPLAYTABLE3, starting form ulPowerplayTable[0]     **********************************************************************************************************************/
end_comment

begin_comment
comment|// this IntegrateSystemInfoTable is used for Trinity APU
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_INTEGRATED_SYSTEM_INFO_V1_7
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ULONG
name|ulBootUpEngineClock
decl_stmt|;
name|ULONG
name|ulDentistVCOFreq
decl_stmt|;
name|ULONG
name|ulBootUpUMAClock
decl_stmt|;
name|ATOM_CLK_VOLT_CAPABILITY
name|sDISPCLK_Voltage
index|[
literal|4
index|]
decl_stmt|;
name|ULONG
name|ulBootUpReqDisplayVector
decl_stmt|;
name|ULONG
name|ulOtherDisplayMisc
decl_stmt|;
name|ULONG
name|ulGPUCapInfo
decl_stmt|;
name|ULONG
name|ulSB_MMIO_Base_Addr
decl_stmt|;
name|USHORT
name|usRequestedPWMFreqInHz
decl_stmt|;
name|UCHAR
name|ucHtcTmpLmt
decl_stmt|;
name|UCHAR
name|ucHtcHystLmt
decl_stmt|;
name|ULONG
name|ulMinEngineClock
decl_stmt|;
name|ULONG
name|ulSystemConfig
decl_stmt|;
name|ULONG
name|ulCPUCapInfo
decl_stmt|;
name|USHORT
name|usNBP0Voltage
decl_stmt|;
name|USHORT
name|usNBP1Voltage
decl_stmt|;
name|USHORT
name|usBootUpNBVoltage
decl_stmt|;
name|USHORT
name|usExtDispConnInfoOffset
decl_stmt|;
name|USHORT
name|usPanelRefreshRateRange
decl_stmt|;
name|UCHAR
name|ucMemoryType
decl_stmt|;
name|UCHAR
name|ucUMAChannelNumber
decl_stmt|;
name|UCHAR
name|strVBIOSMsg
index|[
literal|40
index|]
decl_stmt|;
name|ULONG
name|ulReserved
index|[
literal|20
index|]
decl_stmt|;
name|ATOM_AVAILABLE_SCLK_LIST
name|sAvail_SCLK
index|[
literal|5
index|]
decl_stmt|;
name|ULONG
name|ulGMCRestoreResetTime
decl_stmt|;
name|ULONG
name|ulMinimumNClk
decl_stmt|;
name|ULONG
name|ulIdleNClk
decl_stmt|;
name|ULONG
name|ulDDR_DLL_PowerUpTime
decl_stmt|;
name|ULONG
name|ulDDR_PLL_PowerUpTime
decl_stmt|;
name|USHORT
name|usPCIEClkSSPercentage
decl_stmt|;
name|USHORT
name|usPCIEClkSSType
decl_stmt|;
name|USHORT
name|usLvdsSSPercentage
decl_stmt|;
name|USHORT
name|usLvdsSSpreadRateIn10Hz
decl_stmt|;
name|USHORT
name|usHDMISSPercentage
decl_stmt|;
name|USHORT
name|usHDMISSpreadRateIn10Hz
decl_stmt|;
name|USHORT
name|usDVISSPercentage
decl_stmt|;
name|USHORT
name|usDVISSpreadRateIn10Hz
decl_stmt|;
name|ULONG
name|SclkDpmBoostMargin
decl_stmt|;
name|ULONG
name|SclkDpmThrottleMargin
decl_stmt|;
name|USHORT
name|SclkDpmTdpLimitPG
decl_stmt|;
name|USHORT
name|SclkDpmTdpLimitBoost
decl_stmt|;
name|ULONG
name|ulBoostEngineCLock
decl_stmt|;
name|UCHAR
name|ulBoostVid_2bit
decl_stmt|;
name|UCHAR
name|EnableBoost
decl_stmt|;
name|USHORT
name|GnbTdpLimit
decl_stmt|;
name|USHORT
name|usMaxLVDSPclkFreqInSingleLink
decl_stmt|;
name|UCHAR
name|ucLvdsMisc
decl_stmt|;
name|UCHAR
name|ucLVDSReserved
decl_stmt|;
name|UCHAR
name|ucLVDSPwrOnSeqDIGONtoDE_in4Ms
decl_stmt|;
name|UCHAR
name|ucLVDSPwrOnSeqDEtoVARY_BL_in4Ms
decl_stmt|;
name|UCHAR
name|ucLVDSPwrOffSeqVARY_BLtoDE_in4Ms
decl_stmt|;
name|UCHAR
name|ucLVDSPwrOffSeqDEtoDIGON_in4Ms
decl_stmt|;
name|UCHAR
name|ucLVDSOffToOnDelay_in4Ms
decl_stmt|;
name|UCHAR
name|ucLVDSPwrOnSeqVARY_BLtoBLON_in4Ms
decl_stmt|;
name|UCHAR
name|ucLVDSPwrOffSeqBLONtoVARY_BL_in4Ms
decl_stmt|;
name|UCHAR
name|ucLVDSReserved1
decl_stmt|;
name|ULONG
name|ulLCDBitDepthControlVal
decl_stmt|;
name|ULONG
name|ulNbpStateMemclkFreq
index|[
literal|4
index|]
decl_stmt|;
name|USHORT
name|usNBP2Voltage
decl_stmt|;
name|USHORT
name|usNBP3Voltage
decl_stmt|;
name|ULONG
name|ulNbpStateNClkFreq
index|[
literal|4
index|]
decl_stmt|;
name|UCHAR
name|ucNBDPMEnable
decl_stmt|;
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
name|UCHAR
name|ucDPMState0VclkFid
decl_stmt|;
name|UCHAR
name|ucDPMState0DclkFid
decl_stmt|;
name|UCHAR
name|ucDPMState1VclkFid
decl_stmt|;
name|UCHAR
name|ucDPMState1DclkFid
decl_stmt|;
name|UCHAR
name|ucDPMState2VclkFid
decl_stmt|;
name|UCHAR
name|ucDPMState2DclkFid
decl_stmt|;
name|UCHAR
name|ucDPMState3VclkFid
decl_stmt|;
name|UCHAR
name|ucDPMState3DclkFid
decl_stmt|;
name|ATOM_EXTERNAL_DISPLAY_CONNECTION_INFO
name|sExtDispConnInfo
decl_stmt|;
block|}
name|ATOM_INTEGRATED_SYSTEM_INFO_V1_7
typedef|;
end_typedef

begin_comment
comment|// ulOtherDisplayMisc
end_comment

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO__GET_EDID_CALLBACK_FUNC_SUPPORT
value|0x01
end_define

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO__GET_BOOTUP_DISPLAY_CALLBACK_FUNC_SUPPORT
value|0x02
end_define

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO__GET_EXPANSION_CALLBACK_FUNC_SUPPORT
value|0x04
end_define

begin_define
define|#
directive|define
name|INTEGRATED_SYSTEM_INFO__FAST_BOOT_SUPPORT
value|0x08
end_define

begin_comment
comment|// ulGPUCapInfo
end_comment

begin_define
define|#
directive|define
name|SYS_INFO_GPUCAPS__TMDSHDMI_COHERENT_SINGLEPLL_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|SYS_INFO_GPUCAPS__DP_SINGLEPLL_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|SYS_INFO_GPUCAPS__DISABLE_AUX_MODE_DETECT
value|0x08
end_define

begin_comment
comment|/**********************************************************************************************************************   ATOM_INTEGRATED_SYSTEM_INFO_V1_7 Description ulBootUpEngineClock:              VBIOS bootup Engine clock frequency, in 10kHz unit. if it is equal 0, then VBIOS use pre-defined bootup engine clock ulDentistVCOFreq:                 Dentist VCO clock in 10kHz unit.  ulBootUpUMAClock:                 System memory boot up clock frequency in 10Khz unit.  sDISPCLK_Voltage:                 Report Display clock voltage requirement.   ulBootUpReqDisplayVector:         VBIOS boot up display IDs, following are supported devices in Trinity projects:                                   ATOM_DEVICE_CRT1_SUPPORT                  0x0001                                   ATOM_DEVICE_DFP1_SUPPORT                  0x0008                                    ATOM_DEVICE_DFP6_SUPPORT                  0x0040                                    ATOM_DEVICE_DFP2_SUPPORT                  0x0080                                          ATOM_DEVICE_DFP3_SUPPORT                  0x0200                                          ATOM_DEVICE_DFP4_SUPPORT                  0x0400                                           ATOM_DEVICE_DFP5_SUPPORT                  0x0800                                   ATOM_DEVICE_LCD1_SUPPORT                  0x0002 ulOtherDisplayMisc:      	        bit[0]=0: INT15 callback function Get LCD EDID ( ax=4e08, bl=1b ) is not supported by SBIOS.                                          =1: INT15 callback function Get LCD EDID ( ax=4e08, bl=1b ) is supported by SBIOS.                                    bit[1]=0: INT15 callback function Get boot display( ax=4e08, bl=01h) is not supported by SBIOS                                         =1: INT15 callback function Get boot display( ax=4e08, bl=01h) is supported by SBIOS                                   bit[2]=0: INT15 callback function Get panel Expansion ( ax=4e08, bl=02h) is not supported by SBIOS                                         =1: INT15 callback function Get panel Expansion ( ax=4e08, bl=02h) is supported by SBIOS                                   bit[3]=0: VBIOS fast boot is disable                                         =1: VBIOS fast boot is enable. ( VBIOS skip display device detection in every set mode if LCD panel is connect and LID is open) ulGPUCapInfo:                     bit[0]=0: TMDS/HDMI Coherent Mode use cascade PLL mode.                                         =1: TMDS/HDMI Coherent Mode use signel PLL mode.                                   bit[1]=0: DP mode use cascade PLL mode ( New for Trinity )                                         =1: DP mode use single PLL mode                                   bit[3]=0: Enable AUX HW mode detection logic                                         =1: Disable AUX HW mode detection logic                                        ulSB_MMIO_Base_Addr:              Physical Base address to SB MMIO space. Driver needs to initialize it for SMU usage.  usRequestedPWMFreqInHz:           When it's set to 0x0 by SBIOS: the LCD BackLight is not controlled by GPU(SW).                                    Any attempt to change BL using VBIOS function or enable VariBri from PP table is not effective since ATOM_BIOS_INFO_BL_CONTROLLED_BY_GPU==0;                                                                      When it's set to a non-zero frequency, the BackLight is controlled by GPU (SW) in one of two ways below:                                   1. SW uses the GPU BL PWM output to control the BL, in chis case, this non-zero frequency determines what freq GPU should use;                                   VBIOS will set up proper PWM frequency and ATOM_BIOS_INFO_BL_CONTROLLED_BY_GPU==1,as the result,                                   Changing BL using VBIOS function is functional in both driver and non-driver present environment;                                    and enabling VariBri under the driver environment from PP table is optional.                                    2. SW uses other means to control BL (like DPCD),this non-zero frequency serves as a flag only indicating                                   that BL control from GPU is expected.                                   VBIOS will NOT set up PWM frequency but make ATOM_BIOS_INFO_BL_CONTROLLED_BY_GPU==1                                   Changing BL using VBIOS function could be functional in both driver and non-driver present environment,but                                   it's per platform                                    and enabling VariBri under the driver environment from PP table is optional.  ucHtcTmpLmt:                      Refer to D18F3x64 bit[22:16], HtcTmpLmt.                                    Threshold on value to enter HTC_active state. ucHtcHystLmt:                     Refer to D18F3x64 bit[27:24], HtcHystLmt.                                    To calculate threshold off value to exit HTC_active state, which is Threshold on vlaue minus ucHtcHystLmt. ulMinEngineClock:                 Minimum SCLK allowed in 10kHz unit. This is calculated based on WRCK Fuse settings. ulSystemConfig:                   Bit[0]=0: PCIE Power Gating Disabled                                          =1: PCIE Power Gating Enabled                                   Bit[1]=0: DDR-DLL shut-down feature disabled.                                          1: DDR-DLL shut-down feature enabled.                                   Bit[2]=0: DDR-PLL Power down feature disabled.                                          1: DDR-PLL Power down feature enabled.                                  ulCPUCapInfo:                     TBD usNBP0Voltage:                    VID for voltage on NB P0 State usNBP1Voltage:                    VID for voltage on NB P1 State   usNBP2Voltage:                    VID for voltage on NB P2 State usNBP3Voltage:                    VID for voltage on NB P3 State   usBootUpNBVoltage:                Voltage Index of GNB voltage configured by SBIOS, which is suffcient to support VBIOS DISPCLK requirement. usExtDispConnInfoOffset:          Offset to sExtDispConnInfo inside the structure usPanelRefreshRateRange:          Bit vector for LCD supported refresh rate range. If DRR is requestd by the platform, at least two bits need to be set                                   to indicate a range.                                   SUPPORTED_LCD_REFRESHRATE_30Hz          0x0004                                   SUPPORTED_LCD_REFRESHRATE_40Hz          0x0008                                   SUPPORTED_LCD_REFRESHRATE_50Hz          0x0010                                   SUPPORTED_LCD_REFRESHRATE_60Hz          0x0020 ucMemoryType:                     [3:0]=1:DDR1;=2:DDR2;=3:DDR3.[7:4] is reserved. ucUMAChannelNumber:      	        System memory channel numbers.  ulCSR_M3_ARB_CNTL_DEFAULT[10]:    Arrays with values for CSR M3 arbiter for default ulCSR_M3_ARB_CNTL_UVD[10]:        Arrays with values for CSR M3 arbiter for UVD playback. ulCSR_M3_ARB_CNTL_FS3D[10]:       Arrays with values for CSR M3 arbiter for Full Screen 3D applications. sAvail_SCLK[5]:                   Arrays to provide availabe list of SLCK and corresponding voltage, order from low to high   ulGMCRestoreResetTime:            GMC power restore and GMC reset time to calculate data reconnection latency. Unit in ns.  ulMinimumNClk:                    Minimum NCLK speed among all NB-Pstates to calcualte data reconnection latency. Unit in 10kHz.  ulIdleNClk:                       NCLK speed while memory runs in self-refresh state. Unit in 10kHz. ulDDR_DLL_PowerUpTime:            DDR PHY DLL power up time. Unit in ns. ulDDR_PLL_PowerUpTime:            DDR PHY PLL power up time. Unit in ns. usPCIEClkSSPercentage:            PCIE Clock Spread Spectrum Percentage in unit 0.01%; 100 mean 1%. usPCIEClkSSType:                  PCIE Clock Spread Spectrum Type. 0 for Down spread(default); 1 for Center spread. usLvdsSSPercentage:               LVDS panel ( not include eDP ) Spread Spectrum Percentage in unit of 0.01%, =0, use VBIOS default setting.  usLvdsSSpreadRateIn10Hz:          LVDS panel ( not include eDP ) Spread Spectrum frequency in unit of 10Hz, =0, use VBIOS default setting.  usHDMISSPercentage:               HDMI Spread Spectrum Percentage in unit 0.01%; 100 mean 1%,  =0, use VBIOS default setting.  usHDMISSpreadRateIn10Hz:          HDMI Spread Spectrum frequency in unit of 10Hz,  =0, use VBIOS default setting.  usDVISSPercentage:                DVI Spread Spectrum Percentage in unit 0.01%; 100 mean 1%,  =0, use VBIOS default setting.  usDVISSpreadRateIn10Hz:           DVI Spread Spectrum frequency in unit of 10Hz,  =0, use VBIOS default setting.  usMaxLVDSPclkFreqInSingleLink:    Max pixel clock LVDS panel single link, if=0 means VBIOS use default threhold, right now it is 85Mhz ucLVDSMisc:                       [bit0] LVDS 888bit panel mode =0: LVDS 888 panel in LDI mode, =1: LVDS 888 panel in FPDI mode                                   [bit1] LVDS panel lower and upper link mapping =0: lower link and upper link not swap, =1: lower link and upper link are swapped                                   [bit2] LVDS 888bit per color mode  =0: 666 bit per color =1:888 bit per color                                   [bit3] LVDS parameter override enable  =0: ucLvdsMisc parameter are not used =1: ucLvdsMisc parameter should be used                                   [bit4] Polarity of signal sent to digital BLON output pin. =0: not inverted(active high) =1: inverted ( active low ) ucLVDSPwrOnSeqDIGONtoDE_in4Ms:    LVDS power up sequence time in unit of 4ms, time delay from DIGON signal active to data enable signal active( DE ).                                   =0 mean use VBIOS default which is 8 ( 32ms ). The LVDS power up sequence is as following: DIGON->DE->VARY_BL->BLON.                                    This parameter is used by VBIOS only. VBIOS will patch LVDS_InfoTable. ucLVDSPwrOnDEtoVARY_BL_in4Ms:     LVDS power up sequence time in unit of 4ms., time delay from DE( data enable ) active to Vary Brightness enable signal active( VARY_BL ).                                     =0 mean use VBIOS default which is 90 ( 360ms ). The LVDS power up sequence is as following: DIGON->DE->VARY_BL->BLON.                                    This parameter is used by VBIOS only. VBIOS will patch LVDS_InfoTable.  ucLVDSPwrOffVARY_BLtoDE_in4Ms:    LVDS power down sequence time in unit of 4ms, time delay from data enable ( DE ) signal off to LCDVCC (DIGON) off.                                    =0 mean use VBIOS default delay which is 8 ( 32ms ). The LVDS power down sequence is as following: BLON->VARY_BL->DE->DIGON                                   This parameter is used by VBIOS only. VBIOS will patch LVDS_InfoTable.  ucLVDSPwrOffDEtoDIGON_in4Ms:      LVDS power down sequence time in unit of 4ms, time delay from vary brightness enable signal( VARY_BL) off to data enable ( DE ) signal off.                                    =0 mean use VBIOS default which is 90 ( 360ms ). The LVDS power down sequence is as following: BLON->VARY_BL->DE->DIGON                                   This parameter is used by VBIOS only. VBIOS will patch LVDS_InfoTable.  ucLVDSOffToOnDelay_in4Ms:         LVDS power down sequence time in unit of 4ms. Time delay from DIGON signal off to DIGON signal active.                                    =0 means to use VBIOS default delay which is 125 ( 500ms ).                                   This parameter is used by VBIOS only. VBIOS will patch LVDS_InfoTable.  ucLVDSPwrOnVARY_BLtoBLON_in4Ms:   LVDS power up sequence time in unit of 4ms. Time delay from VARY_BL signal on to DLON signal active.                                    =0 means to use VBIOS default delay which is 0 ( 0ms ).                                   This parameter is used by VBIOS only. VBIOS will patch LVDS_InfoTable.  ucLVDSPwrOffBLONtoVARY_BL_in4Ms:  LVDS power down sequence time in unit of 4ms. Time delay from BLON signal off to VARY_BL signal off.                                    =0 means to use VBIOS default delay which is 0 ( 0ms ).                                   This parameter is used by VBIOS only. VBIOS will patch LVDS_InfoTable.  ulNbpStateMemclkFreq[4]:          system memory clock frequncey in unit of 10Khz in different NB pstate.   **********************************************************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|// This portion is only used when ext thermal chip or engine/memory clock SS chip is populated on a design
end_comment

begin_comment
comment|//Memory SS Info Table
end_comment

begin_comment
comment|//Define Memory Clock SS chip ID
end_comment

begin_define
define|#
directive|define
name|ICS91719
value|1
end_define

begin_define
define|#
directive|define
name|ICS91720
value|2
end_define

begin_comment
comment|//Define one structure to inform SW a "block of data" writing to external SS chip via I2C protocol
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_I2C_DATA_RECORD
block|{
name|UCHAR
name|ucNunberOfBytes
decl_stmt|;
comment|//Indicates how many bytes SW needs to write to the external ASIC for one block, besides to "Start" and "Stop"
name|UCHAR
name|ucI2CData
index|[
literal|1
index|]
decl_stmt|;
comment|//I2C data in bytes, should be less than 16 bytes usually
block|}
name|ATOM_I2C_DATA_RECORD
typedef|;
end_typedef

begin_comment
comment|//Define one structure to inform SW how many blocks of data writing to external SS chip via I2C protocol, in addition to other information
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_I2C_DEVICE_SETUP_INFO
block|{
name|ATOM_I2C_ID_CONFIG_ACCESS
name|sucI2cId
decl_stmt|;
comment|//I2C line and HW/SW assisted cap.
name|UCHAR
name|ucSSChipID
decl_stmt|;
comment|//SS chip being used
name|UCHAR
name|ucSSChipSlaveAddr
decl_stmt|;
comment|//Slave Address to set up this SS chip
name|UCHAR
name|ucNumOfI2CDataRecords
decl_stmt|;
comment|//number of data block
name|ATOM_I2C_DATA_RECORD
name|asI2CData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_I2C_DEVICE_SETUP_INFO
typedef|;
end_typedef

begin_comment
comment|//==========================================================================================
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ASIC_MVDD_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_I2C_DEVICE_SETUP_INFO
name|asI2CSetup
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_ASIC_MVDD_INFO
typedef|;
end_typedef

begin_comment
comment|//==========================================================================================
end_comment

begin_define
define|#
directive|define
name|ATOM_MCLK_SS_INFO
value|ATOM_ASIC_MVDD_INFO
end_define

begin_comment
comment|//==========================================================================================
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ASIC_SS_ASSIGNMENT
block|{
name|ULONG
name|ulTargetClockRange
decl_stmt|;
comment|//Clock Out frequence (VCO ), in unit of 10Khz
name|USHORT
name|usSpreadSpectrumPercentage
decl_stmt|;
comment|//in unit of 0.01%
name|USHORT
name|usSpreadRateInKhz
decl_stmt|;
comment|//in unit of kHz, modulation freq
name|UCHAR
name|ucClockIndication
decl_stmt|;
comment|//Indicate which clock source needs SS
name|UCHAR
name|ucSpreadSpectrumMode
decl_stmt|;
comment|//Bit1=0 Down Spread,=1 Center Spread.
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ATOM_ASIC_SS_ASSIGNMENT
typedef|;
end_typedef

begin_comment
comment|//Define ucClockIndication, SW uses the IDs below to search if the SS is required/enabled on a clock branch/signal type.
end_comment

begin_comment
comment|//SS is not required or enabled if a match is not found.
end_comment

begin_define
define|#
directive|define
name|ASIC_INTERNAL_MEMORY_SS
value|1
end_define

begin_define
define|#
directive|define
name|ASIC_INTERNAL_ENGINE_SS
value|2
end_define

begin_define
define|#
directive|define
name|ASIC_INTERNAL_UVD_SS
value|3
end_define

begin_define
define|#
directive|define
name|ASIC_INTERNAL_SS_ON_TMDS
value|4
end_define

begin_define
define|#
directive|define
name|ASIC_INTERNAL_SS_ON_HDMI
value|5
end_define

begin_define
define|#
directive|define
name|ASIC_INTERNAL_SS_ON_LVDS
value|6
end_define

begin_define
define|#
directive|define
name|ASIC_INTERNAL_SS_ON_DP
value|7
end_define

begin_define
define|#
directive|define
name|ASIC_INTERNAL_SS_ON_DCPLL
value|8
end_define

begin_define
define|#
directive|define
name|ASIC_EXTERNAL_SS_ON_DP_CLOCK
value|9
end_define

begin_define
define|#
directive|define
name|ASIC_INTERNAL_VCE_SS
value|10
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ASIC_SS_ASSIGNMENT_V2
block|{
name|ULONG
name|ulTargetClockRange
decl_stmt|;
comment|//For mem/engine/uvd, Clock Out frequence (VCO ), in unit of 10Khz
comment|//For TMDS/HDMI/LVDS, it is pixel clock , for DP, it is link clock ( 27000 or 16200 )
name|USHORT
name|usSpreadSpectrumPercentage
decl_stmt|;
comment|//in unit of 0.01%
name|USHORT
name|usSpreadRateIn10Hz
decl_stmt|;
comment|//in unit of 10Hz, modulation freq
name|UCHAR
name|ucClockIndication
decl_stmt|;
comment|//Indicate which clock source needs SS
name|UCHAR
name|ucSpreadSpectrumMode
decl_stmt|;
comment|//Bit0=0 Down Spread,=1 Center Spread, bit1=0: internal SS bit1=1: external SS
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ATOM_ASIC_SS_ASSIGNMENT_V2
typedef|;
end_typedef

begin_comment
comment|//ucSpreadSpectrumMode
end_comment

begin_comment
comment|//#define ATOM_SS_DOWN_SPREAD_MODE_MASK          0x00000000
end_comment

begin_comment
comment|//#define ATOM_SS_DOWN_SPREAD_MODE               0x00000000
end_comment

begin_comment
comment|//#define ATOM_SS_CENTRE_SPREAD_MODE_MASK        0x00000001
end_comment

begin_comment
comment|//#define ATOM_SS_CENTRE_SPREAD_MODE             0x00000001
end_comment

begin_comment
comment|//#define ATOM_INTERNAL_SS_MASK                  0x00000000
end_comment

begin_comment
comment|//#define ATOM_EXTERNAL_SS_MASK                  0x00000002
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ASIC_INTERNAL_SS_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_ASIC_SS_ASSIGNMENT
name|asSpreadSpectrum
index|[
literal|4
index|]
decl_stmt|;
block|}
name|ATOM_ASIC_INTERNAL_SS_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ASIC_INTERNAL_SS_INFO_V2
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_ASIC_SS_ASSIGNMENT_V2
name|asSpreadSpectrum
index|[
literal|1
index|]
decl_stmt|;
comment|//this is point only.
block|}
name|ATOM_ASIC_INTERNAL_SS_INFO_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ASIC_SS_ASSIGNMENT_V3
block|{
name|ULONG
name|ulTargetClockRange
decl_stmt|;
comment|//For mem/engine/uvd, Clock Out frequence (VCO ), in unit of 10Khz
comment|//For TMDS/HDMI/LVDS, it is pixel clock , for DP, it is link clock ( 27000 or 16200 )
name|USHORT
name|usSpreadSpectrumPercentage
decl_stmt|;
comment|//in unit of 0.01%
name|USHORT
name|usSpreadRateIn10Hz
decl_stmt|;
comment|//in unit of 10Hz, modulation freq
name|UCHAR
name|ucClockIndication
decl_stmt|;
comment|//Indicate which clock source needs SS
name|UCHAR
name|ucSpreadSpectrumMode
decl_stmt|;
comment|//Bit0=0 Down Spread,=1 Center Spread, bit1=0: internal SS bit1=1: external SS
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ATOM_ASIC_SS_ASSIGNMENT_V3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ASIC_INTERNAL_SS_INFO_V3
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_ASIC_SS_ASSIGNMENT_V3
name|asSpreadSpectrum
index|[
literal|1
index|]
decl_stmt|;
comment|//this is pointer only.
block|}
name|ATOM_ASIC_INTERNAL_SS_INFO_V3
typedef|;
end_typedef

begin_comment
comment|//==============================Scratch Pad Definition Portion===============================
end_comment

begin_define
define|#
directive|define
name|ATOM_DEVICE_CONNECT_INFO_DEF
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_ROM_LOCATION_DEF
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_TV_STANDARD_DEF
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_ACTIVE_INFO_DEF
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_LCD_INFO_DEF
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_DOS_REQ_INFO_DEF
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_ACC_CHANGE_INFO_DEF
value|6
end_define

begin_define
define|#
directive|define
name|ATOM_DOS_MODE_INFO_DEF
value|7
end_define

begin_define
define|#
directive|define
name|ATOM_I2C_CHANNEL_STATUS_DEF
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_I2C_CHANNEL_STATUS1_DEF
value|9
end_define

begin_define
define|#
directive|define
name|ATOM_INTERNAL_TIMER_DEF
value|10
end_define

begin_comment
comment|// BIOS_0_SCRATCH Definition
end_comment

begin_define
define|#
directive|define
name|ATOM_S0_CRT1_MONO
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CRT1_COLOR
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CRT1_MASK
value|(ATOM_S0_CRT1_MONO+ATOM_S0_CRT1_COLOR)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_COMPOSITE_A
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_SVIDEO_A
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_MASK_A
value|(ATOM_S0_TV1_COMPOSITE_A+ATOM_S0_TV1_SVIDEO_A)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CV_A
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CV_DIN_A
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CV_MASK_A
value|(ATOM_S0_CV_A+ATOM_S0_CV_DIN_A)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CRT2_MONO
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CRT2_COLOR
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CRT2_MASK
value|(ATOM_S0_CRT2_MONO+ATOM_S0_CRT2_COLOR)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_COMPOSITE
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_SVIDEO
value|0x00000800L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_SCART
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_MASK
value|(ATOM_S0_TV1_COMPOSITE+ATOM_S0_TV1_SVIDEO+ATOM_S0_TV1_SCART)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CV
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CV_DIN
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CV_MASK
value|(ATOM_S0_CV+ATOM_S0_CV_DIN)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP1
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP2
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_LCD1
value|0x00040000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_LCD2
value|0x00080000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP6
value|0x00100000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP3
value|0x00200000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP4
value|0x00400000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP5
value|0x00800000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP_MASK
value|ATOM_S0_DFP1 | ATOM_S0_DFP2 | ATOM_S0_DFP3 | ATOM_S0_DFP4 | ATOM_S0_DFP5 | ATOM_S0_DFP6
end_define

begin_define
define|#
directive|define
name|ATOM_S0_FAD_REGISTER_BUG
value|0x02000000L
end_define

begin_comment
comment|// If set, indicates we are running a PCIE asic with
end_comment

begin_comment
comment|// the FAD/HDP reg access bug.  Bit is read by DAL, this is obsolete from RV5xx
end_comment

begin_define
define|#
directive|define
name|ATOM_S0_THERMAL_STATE_MASK
value|0x1C000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_THERMAL_STATE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|ATOM_S0_SYSTEM_POWER_STATE_MASK
value|0xE0000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_SYSTEM_POWER_STATE_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|ATOM_S0_SYSTEM_POWER_STATE_VALUE_AC
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_S0_SYSTEM_POWER_STATE_VALUE_DC
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_S0_SYSTEM_POWER_STATE_VALUE_LITEAC
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_S0_SYSTEM_POWER_STATE_VALUE_LIT2AC
value|4
end_define

begin_comment
comment|//Byte aligned definition for BIOS usage
end_comment

begin_define
define|#
directive|define
name|ATOM_S0_CRT1_MONOb0
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CRT1_COLORb0
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CRT1_MASKb0
value|(ATOM_S0_CRT1_MONOb0+ATOM_S0_CRT1_COLORb0)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_COMPOSITEb0
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_SVIDEOb0
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_MASKb0
value|(ATOM_S0_TV1_COMPOSITEb0+ATOM_S0_TV1_SVIDEOb0)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CVb0
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CV_DINb0
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CV_MASKb0
value|(ATOM_S0_CVb0+ATOM_S0_CV_DINb0)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CRT2_MONOb1
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CRT2_COLORb1
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CRT2_MASKb1
value|(ATOM_S0_CRT2_MONOb1+ATOM_S0_CRT2_COLORb1)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_COMPOSITEb1
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_SVIDEOb1
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_SCARTb1
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV1_MASKb1
value|(ATOM_S0_TV1_COMPOSITEb1+ATOM_S0_TV1_SVIDEOb1+ATOM_S0_TV1_SCARTb1)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CVb1
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CV_DINb1
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S0_CV_MASKb1
value|(ATOM_S0_CVb1+ATOM_S0_CV_DINb1)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP1b2
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP2b2
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S0_LCD1b2
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S0_LCD2b2
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP6b2
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP3b2
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP4b2
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP5b2
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_S0_THERMAL_STATE_MASKb3
value|0x1C
end_define

begin_define
define|#
directive|define
name|ATOM_S0_THERMAL_STATE_SHIFTb3
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_S0_SYSTEM_POWER_STATE_MASKb3
value|0xE0
end_define

begin_define
define|#
directive|define
name|ATOM_S0_LCD1_SHIFT
value|18
end_define

begin_comment
comment|// BIOS_1_SCRATCH Definition
end_comment

begin_define
define|#
directive|define
name|ATOM_S1_ROM_LOCATION_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|ATOM_S1_PCI_BUS_DEV_MASK
value|0xFFFF0000L
end_define

begin_comment
comment|//	BIOS_2_SCRATCH Definition
end_comment

begin_define
define|#
directive|define
name|ATOM_S2_TV1_STANDARD_MASK
value|0x0000000FL
end_define

begin_define
define|#
directive|define
name|ATOM_S2_CURRENT_BL_LEVEL_MASK
value|0x0000FF00L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_CURRENT_BL_LEVEL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_S2_FORCEDLOWPWRMODE_STATE_MASK
value|0x0C000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_FORCEDLOWPWRMODE_STATE_MASK_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|ATOM_S2_FORCEDLOWPWRMODE_STATE_CHANGE
value|0x10000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DEVICE_DPMS_STATE
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_VRI_BRIGHT_ENABLE
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DISPLAY_ROTATION_0_DEGREE
value|0x0
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DISPLAY_ROTATION_90_DEGREE
value|0x1
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DISPLAY_ROTATION_180_DEGREE
value|0x2
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DISPLAY_ROTATION_270_DEGREE
value|0x3
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DISPLAY_ROTATION_DEGREE_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DISPLAY_ROTATION_ANGLE_MASK
value|0xC0000000L
end_define

begin_comment
comment|//Byte aligned definition for BIOS usage
end_comment

begin_define
define|#
directive|define
name|ATOM_S2_TV1_STANDARD_MASKb0
value|0x0F
end_define

begin_define
define|#
directive|define
name|ATOM_S2_CURRENT_BL_LEVEL_MASKb1
value|0xFF
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DEVICE_DPMS_STATEb2
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DEVICE_DPMS_MASKw1
value|0x3FF
end_define

begin_define
define|#
directive|define
name|ATOM_S2_FORCEDLOWPWRMODE_STATE_MASKb3
value|0x0C
end_define

begin_define
define|#
directive|define
name|ATOM_S2_FORCEDLOWPWRMODE_STATE_CHANGEb3
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S2_TMDS_COHERENT_MODEb3
value|0x10
end_define

begin_comment
comment|// used by VBIOS code only, use coherent mode for TMDS/HDMI mode
end_comment

begin_define
define|#
directive|define
name|ATOM_S2_VRI_BRIGHT_ENABLEb3
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S2_ROTATION_STATE_MASKb3
value|0xC0
end_define

begin_comment
comment|// BIOS_3_SCRATCH Definition
end_comment

begin_define
define|#
directive|define
name|ATOM_S3_CRT1_ACTIVE
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_LCD1_ACTIVE
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_TV1_ACTIVE
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP1_ACTIVE
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_CRT2_ACTIVE
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_LCD2_ACTIVE
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP6_ACTIVE
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP2_ACTIVE
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_CV_ACTIVE
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP3_ACTIVE
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP4_ACTIVE
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP5_ACTIVE
value|0x00000800L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DEVICE_ACTIVE_MASK
value|0x00000FFFL
end_define

begin_define
define|#
directive|define
name|ATOM_S3_LCD_FULLEXPANSION_ACTIVE
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_LCD_EXPANSION_ASPEC_RATIO_ACTIVE
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_CRT1_CRTC_ACTIVE
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_LCD1_CRTC_ACTIVE
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_TV1_CRTC_ACTIVE
value|0x00040000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP1_CRTC_ACTIVE
value|0x00080000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_CRT2_CRTC_ACTIVE
value|0x00100000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_LCD2_CRTC_ACTIVE
value|0x00200000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP6_CRTC_ACTIVE
value|0x00400000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP2_CRTC_ACTIVE
value|0x00800000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_CV_CRTC_ACTIVE
value|0x01000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP3_CRTC_ACTIVE
value|0x02000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP4_CRTC_ACTIVE
value|0x04000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP5_CRTC_ACTIVE
value|0x08000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DEVICE_CRTC_ACTIVE_MASK
value|0x0FFF0000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_ASIC_GUI_ENGINE_HUNG
value|0x20000000L
end_define

begin_comment
comment|//Below two definitions are not supported in pplib, but in the old powerplay in DAL
end_comment

begin_define
define|#
directive|define
name|ATOM_S3_ALLOW_FAST_PWR_SWITCH
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_RQST_GPU_USE_MIN_PWR
value|0x80000000L
end_define

begin_comment
comment|//Byte aligned definition for BIOS usage
end_comment

begin_define
define|#
directive|define
name|ATOM_S3_CRT1_ACTIVEb0
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S3_LCD1_ACTIVEb0
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S3_TV1_ACTIVEb0
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP1_ACTIVEb0
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S3_CRT2_ACTIVEb0
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S3_LCD2_ACTIVEb0
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP6_ACTIVEb0
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP2_ACTIVEb0
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_S3_CV_ACTIVEb1
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP3_ACTIVEb1
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP4_ACTIVEb1
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP5_ACTIVEb1
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S3_ACTIVE_CRTC1w0
value|0xFFF
end_define

begin_define
define|#
directive|define
name|ATOM_S3_CRT1_CRTC_ACTIVEb2
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S3_LCD1_CRTC_ACTIVEb2
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S3_TV1_CRTC_ACTIVEb2
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP1_CRTC_ACTIVEb2
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S3_CRT2_CRTC_ACTIVEb2
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S3_LCD2_CRTC_ACTIVEb2
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP6_CRTC_ACTIVEb2
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP2_CRTC_ACTIVEb2
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_S3_CV_CRTC_ACTIVEb3
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP3_CRTC_ACTIVEb3
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP4_CRTC_ACTIVEb3
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP5_CRTC_ACTIVEb3
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S3_ACTIVE_CRTC2w1
value|0xFFF
end_define

begin_comment
comment|// BIOS_4_SCRATCH Definition
end_comment

begin_define
define|#
directive|define
name|ATOM_S4_LCD1_PANEL_ID_MASK
value|0x000000FFL
end_define

begin_define
define|#
directive|define
name|ATOM_S4_LCD1_REFRESH_MASK
value|0x0000FF00L
end_define

begin_define
define|#
directive|define
name|ATOM_S4_LCD1_REFRESH_SHIFT
value|8
end_define

begin_comment
comment|//Byte aligned definition for BIOS usage
end_comment

begin_define
define|#
directive|define
name|ATOM_S4_LCD1_PANEL_ID_MASKb0
value|0x0FF
end_define

begin_define
define|#
directive|define
name|ATOM_S4_LCD1_REFRESH_MASKb1
value|ATOM_S4_LCD1_PANEL_ID_MASKb0
end_define

begin_define
define|#
directive|define
name|ATOM_S4_VRAM_INFO_MASKb2
value|ATOM_S4_LCD1_PANEL_ID_MASKb0
end_define

begin_comment
comment|// BIOS_5_SCRATCH Definition, BIOS_5_SCRATCH is used by Firmware only !!!!
end_comment

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_CRT1b0
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_LCD1b0
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_TV1b0
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP1b0
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_CRT2b0
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_LCD2b0
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP6b0
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP2b0
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_CVb1
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP3b1
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP4b1
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP5b1
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DEVICEw0
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_CRT1
value|0x0001
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_LCD1
value|0x0002
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_TV1
value|0x0004
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP1
value|0x0008
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_CRT2
value|0x0010
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_LCD2
value|0x0020
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP6
value|0x0040
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP2
value|0x0080
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_CV
value|0x0100
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP3
value|0x0200
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP4
value|0x0400
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP5
value|0x0800
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_FORCE_CRT1b2
value|ATOM_S5_DOS_REQ_CRT1b0
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_FORCE_TV1b2
value|ATOM_S5_DOS_REQ_TV1b0
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_FORCE_CRT2b2
value|ATOM_S5_DOS_REQ_CRT2b0
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_FORCE_CVb3
value|ATOM_S5_DOS_REQ_CVb1
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_FORCE_DEVICEw1
value|(ATOM_S5_DOS_FORCE_CRT1b2+ATOM_S5_DOS_FORCE_TV1b2+ATOM_S5_DOS_FORCE_CRT2b2+\                                         (ATOM_S5_DOS_FORCE_CVb3<<8))
end_define

begin_comment
comment|// BIOS_6_SCRATCH Definition
end_comment

begin_define
define|#
directive|define
name|ATOM_S6_DEVICE_CHANGE
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_SCALER_CHANGE
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_LID_CHANGE
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_DOCKING_CHANGE
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_MODE
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_EXT_DESKTOP_MODE
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_LID_STATE
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_DOCK_STATE
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_CRITICAL_STATE
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_HW_I2C_BUSY_STATE
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_THERMAL_STATE_CHANGE
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_INTERRUPT_SET_BY_BIOS
value|0x00000800L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_REQ_LCD_EXPANSION_FULL
value|0x00001000L
end_define

begin_comment
comment|//Normal expansion Request bit for LCD
end_comment

begin_define
define|#
directive|define
name|ATOM_S6_REQ_LCD_EXPANSION_ASPEC_RATIO
value|0x00002000L
end_define

begin_comment
comment|//Aspect ratio expansion Request bit for LCD
end_comment

begin_define
define|#
directive|define
name|ATOM_S6_DISPLAY_STATE_CHANGE
value|0x00004000L
end_define

begin_comment
comment|//This bit is recycled when ATOM_BIOS_INFO_BIOS_SCRATCH6_SCL2_REDEFINE is set,previously it's SCL2_H_expansion
end_comment

begin_define
define|#
directive|define
name|ATOM_S6_I2C_STATE_CHANGE
value|0x00008000L
end_define

begin_comment
comment|//This bit is recycled,when ATOM_BIOS_INFO_BIOS_SCRATCH6_SCL2_REDEFINE is set,previously it's SCL2_V_expansion
end_comment

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_CRT1
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_LCD1
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_TV1
value|0x00040000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP1
value|0x00080000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_CRT2
value|0x00100000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_LCD2
value|0x00200000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP6
value|0x00400000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP2
value|0x00800000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_CV
value|0x01000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP3
value|0x02000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP4
value|0x04000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP5
value|0x08000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_MASK
value|0x0FFF0000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_SYSTEM_POWER_MODE_CHANGE
value|0x10000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_BLOCK_DISPLAY_SWITCH
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_VRI_BRIGHTNESS_CHANGE
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S6_CONFIG_DISPLAY_CHANGE_MASK
value|0x80000000L
end_define

begin_comment
comment|//Byte aligned definition for BIOS usage
end_comment

begin_define
define|#
directive|define
name|ATOM_S6_DEVICE_CHANGEb0
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S6_SCALER_CHANGEb0
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S6_LID_CHANGEb0
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S6_DOCKING_CHANGEb0
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_MODEb0
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S6_EXT_DESKTOP_MODEb0
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S6_LID_STATEb0
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_S6_DOCK_STATEb0
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_S6_CRITICAL_STATEb1
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S6_HW_I2C_BUSY_STATEb1
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S6_THERMAL_STATE_CHANGEb1
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S6_INTERRUPT_SET_BY_BIOSb1
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S6_REQ_LCD_EXPANSION_FULLb1
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S6_REQ_LCD_EXPANSION_ASPEC_RATIOb1
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_CRT1b2
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_LCD1b2
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_TV1b2
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP1b2
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_CRT2b2
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_LCD2b2
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP6b2
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP2b2
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_CVb3
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP3b3
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP4b3
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP5b3
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DEVICEw1
value|ATOM_S5_DOS_REQ_DEVICEw0
end_define

begin_define
define|#
directive|define
name|ATOM_S6_SYSTEM_POWER_MODE_CHANGEb3
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_BLOCK_DISPLAY_SWITCHb3
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S6_VRI_BRIGHTNESS_CHANGEb3
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_S6_CONFIG_DISPLAY_CHANGEb3
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_S6_DEVICE_CHANGE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_S6_SCALER_CHANGE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_S6_LID_CHANGE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_S6_DOCKING_CHANGE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_MODE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_S6_EXT_DESKTOP_MODE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_S6_LID_STATE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|ATOM_S6_DOCK_STATE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|ATOM_S6_CRITICAL_STATE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_S6_HW_I2C_BUSY_STATE_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|ATOM_S6_THERMAL_STATE_CHANGE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|ATOM_S6_INTERRUPT_SET_BY_BIOS_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|ATOM_S6_REQ_SCALER_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ATOM_S6_REQ_SCALER_ARATIO_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|ATOM_S6_DISPLAY_STATE_CHANGE_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|ATOM_S6_I2C_STATE_CHANGE_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|ATOM_S6_SYSTEM_POWER_MODE_CHANGE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_BLOCK_DISPLAY_SWITCH_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|ATOM_S6_VRI_BRIGHTNESS_CHANGE_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|ATOM_S6_CONFIG_DISPLAY_CHANGE_SHIFT
value|31
end_define

begin_comment
comment|// BIOS_7_SCRATCH Definition, BIOS_7_SCRATCH is used by Firmware only !!!!
end_comment

begin_define
define|#
directive|define
name|ATOM_S7_DOS_MODE_TYPEb0
value|0x03
end_define

begin_define
define|#
directive|define
name|ATOM_S7_DOS_MODE_VGAb0
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_S7_DOS_MODE_VESAb0
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S7_DOS_MODE_EXTb0
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S7_DOS_MODE_PIXEL_DEPTHb0
value|0x0C
end_define

begin_define
define|#
directive|define
name|ATOM_S7_DOS_MODE_PIXEL_FORMATb0
value|0xF0
end_define

begin_define
define|#
directive|define
name|ATOM_S7_DOS_8BIT_DAC_ENb1
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S7_DOS_MODE_NUMBERw1
value|0x0FFFF
end_define

begin_define
define|#
directive|define
name|ATOM_S7_DOS_8BIT_DAC_EN_SHIFT
value|8
end_define

begin_comment
comment|// BIOS_8_SCRATCH Definition
end_comment

begin_define
define|#
directive|define
name|ATOM_S8_I2C_CHANNEL_BUSY_MASK
value|0x00000FFFF
end_define

begin_define
define|#
directive|define
name|ATOM_S8_I2C_HW_ENGINE_BUSY_MASK
value|0x0FFFF0000
end_define

begin_define
define|#
directive|define
name|ATOM_S8_I2C_CHANNEL_BUSY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_S8_I2C_ENGINE_BUSY_SHIFT
value|16
end_define

begin_comment
comment|// BIOS_9_SCRATCH Definition
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATOM_S9_I2C_CHANNEL_COMPLETED_MASK
end_ifndef

begin_define
define|#
directive|define
name|ATOM_S9_I2C_CHANNEL_COMPLETED_MASK
value|0x0000FFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATOM_S9_I2C_CHANNEL_ABORTED_MASK
end_ifndef

begin_define
define|#
directive|define
name|ATOM_S9_I2C_CHANNEL_ABORTED_MASK
value|0xFFFF0000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATOM_S9_I2C_CHANNEL_COMPLETED_SHIFT
end_ifndef

begin_define
define|#
directive|define
name|ATOM_S9_I2C_CHANNEL_COMPLETED_SHIFT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATOM_S9_I2C_CHANNEL_ABORTED_SHIFT
end_ifndef

begin_define
define|#
directive|define
name|ATOM_S9_I2C_CHANNEL_ABORTED_SHIFT
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ATOM_FLAG_SET
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_FLAG_CLEAR
value|0
end_define

begin_define
define|#
directive|define
name|CLEAR_ATOM_S6_ACC_MODE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_ACC_MODE_SHIFT | ATOM_FLAG_CLEAR)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_DEVICE_CHANGE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_DEVICE_CHANGE_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_VRI_BRIGHTNESS_CHANGE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_VRI_BRIGHTNESS_CHANGE_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_SCALER_CHANGE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_SCALER_CHANGE_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_LID_CHANGE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_LID_CHANGE_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_LID_STATE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_LID_STATE_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|CLEAR_ATOM_S6_LID_STATE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_LID_STATE_SHIFT | ATOM_FLAG_CLEAR)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_DOCK_CHANGE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_DOCKING_CHANGE_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_DOCK_STATE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_DOCK_STATE_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|CLEAR_ATOM_S6_DOCK_STATE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_DOCK_STATE_SHIFT | ATOM_FLAG_CLEAR)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_THERMAL_STATE_CHANGE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_THERMAL_STATE_CHANGE_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_SYSTEM_POWER_MODE_CHANGE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_SYSTEM_POWER_MODE_CHANGE_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_INTERRUPT_SET_BY_BIOS
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_INTERRUPT_SET_BY_BIOS_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_CRITICAL_STATE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_CRITICAL_STATE_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|CLEAR_ATOM_S6_CRITICAL_STATE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_CRITICAL_STATE_SHIFT | ATOM_FLAG_CLEAR)
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_REQ_SCALER
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_REQ_SCALER_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|CLEAR_ATOM_S6_REQ_SCALER
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_REQ_SCALER_SHIFT | ATOM_FLAG_CLEAR )
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_REQ_SCALER_ARATIO
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_REQ_SCALER_ARATIO_SHIFT | ATOM_FLAG_SET )
end_define

begin_define
define|#
directive|define
name|CLEAR_ATOM_S6_REQ_SCALER_ARATIO
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_REQ_SCALER_ARATIO_SHIFT | ATOM_FLAG_CLEAR )
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_I2C_STATE_CHANGE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_I2C_STATE_CHANGE_SHIFT | ATOM_FLAG_SET )
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_DISPLAY_STATE_CHANGE
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_DISPLAY_STATE_CHANGE_SHIFT | ATOM_FLAG_SET )
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S6_DEVICE_RECONFIG
value|((ATOM_ACC_CHANGE_INFO_DEF<< 8 )|ATOM_S6_CONFIG_DISPLAY_CHANGE_SHIFT | ATOM_FLAG_SET)
end_define

begin_define
define|#
directive|define
name|CLEAR_ATOM_S0_LCD1
value|((ATOM_DEVICE_CONNECT_INFO_DEF<< 8 )|  ATOM_S0_LCD1_SHIFT | ATOM_FLAG_CLEAR )
end_define

begin_define
define|#
directive|define
name|SET_ATOM_S7_DOS_8BIT_DAC_EN
value|((ATOM_DOS_MODE_INFO_DEF<< 8 )|ATOM_S7_DOS_8BIT_DAC_EN_SHIFT | ATOM_FLAG_SET )
end_define

begin_define
define|#
directive|define
name|CLEAR_ATOM_S7_DOS_8BIT_DAC_EN
value|((ATOM_DOS_MODE_INFO_DEF<< 8 )|ATOM_S7_DOS_8BIT_DAC_EN_SHIFT | ATOM_FLAG_CLEAR )
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|//Portion II: Definitinos only used in Driver
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Macros used by driver
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|GetIndexIntoMasterTable
parameter_list|(
name|MasterOrData
parameter_list|,
name|FieldName
parameter_list|)
value|((reinterpret_cast<char*>(&(static_cast<ATOM_MASTER_LIST_OF_##MasterOrData##_TABLES*>(0))->FieldName)-static_cast<char*>(0))/sizeof(USHORT))
end_define

begin_define
define|#
directive|define
name|GET_COMMAND_TABLE_COMMANDSET_REVISION
parameter_list|(
name|TABLE_HEADER_OFFSET
parameter_list|)
value|(((static_cast<ATOM_COMMON_TABLE_HEADER*>(TABLE_HEADER_OFFSET))->ucTableFormatRevision )&0x3F)
end_define

begin_define
define|#
directive|define
name|GET_COMMAND_TABLE_PARAMETER_REVISION
parameter_list|(
name|TABLE_HEADER_OFFSET
parameter_list|)
value|(((static_cast<ATOM_COMMON_TABLE_HEADER*>(TABLE_HEADER_OFFSET))->ucTableContentRevision)&0x3F)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// not __cplusplus
end_comment

begin_define
define|#
directive|define
name|GetIndexIntoMasterTable
parameter_list|(
name|MasterOrData
parameter_list|,
name|FieldName
parameter_list|)
value|(((char*)(&((ATOM_MASTER_LIST_OF_##MasterOrData##_TABLES*)0)->FieldName)-(char*)0)/sizeof(USHORT))
end_define

begin_define
define|#
directive|define
name|GET_COMMAND_TABLE_COMMANDSET_REVISION
parameter_list|(
name|TABLE_HEADER_OFFSET
parameter_list|)
value|((((ATOM_COMMON_TABLE_HEADER*)TABLE_HEADER_OFFSET)->ucTableFormatRevision)&0x3F)
end_define

begin_define
define|#
directive|define
name|GET_COMMAND_TABLE_PARAMETER_REVISION
parameter_list|(
name|TABLE_HEADER_OFFSET
parameter_list|)
value|((((ATOM_COMMON_TABLE_HEADER*)TABLE_HEADER_OFFSET)->ucTableContentRevision)&0x3F)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_define
define|#
directive|define
name|GET_DATA_TABLE_MAJOR_REVISION
value|GET_COMMAND_TABLE_COMMANDSET_REVISION
end_define

begin_define
define|#
directive|define
name|GET_DATA_TABLE_MINOR_REVISION
value|GET_COMMAND_TABLE_PARAMETER_REVISION
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|//Portion III: Definitinos only used in VBIOS
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ATOM_DAC_SRC
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_SRC_DAC1
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_SRC_DAC2
value|0x80
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MEMORY_PLLINIT_PARAMETERS
block|{
name|ULONG
name|ulTargetMemoryClock
decl_stmt|;
comment|//In 10Khz unit
name|UCHAR
name|ucAction
decl_stmt|;
comment|//not define yet
name|UCHAR
name|ucFbDiv_Hi
decl_stmt|;
comment|//Fbdiv Hi byte
name|UCHAR
name|ucFbDiv
decl_stmt|;
comment|//FB value
name|UCHAR
name|ucPostDiv
decl_stmt|;
comment|//Post div
block|}
name|MEMORY_PLLINIT_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MEMORY_PLLINIT_PS_ALLOCATION
value|MEMORY_PLLINIT_PARAMETERS
end_define

begin_define
define|#
directive|define
name|GPIO_PIN_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|GPIO_PIN_READ
value|0x00
end_define

begin_typedef
typedef|typedef
struct|struct
name|_GPIO_PIN_CONTROL_PARAMETERS
block|{
name|UCHAR
name|ucGPIO_ID
decl_stmt|;
comment|//return value, read from GPIO pins
name|UCHAR
name|ucGPIOBitShift
decl_stmt|;
comment|//define which bit in uGPIOBitVal need to be update
name|UCHAR
name|ucGPIOBitVal
decl_stmt|;
comment|//Set/Reset corresponding bit defined in ucGPIOBitMask
name|UCHAR
name|ucAction
decl_stmt|;
comment|//=GPIO_PIN_WRITE: Read; =GPIO_PIN_READ: Write
block|}
name|GPIO_PIN_CONTROL_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_SCALER_PARAMETERS
block|{
name|UCHAR
name|ucScaler
decl_stmt|;
comment|// ATOM_SCALER1, ATOM_SCALER2
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_SCALER_DISABLE or ATOM_SCALER_CENTER or ATOM_SCALER_EXPANSION
name|UCHAR
name|ucTVStandard
decl_stmt|;
comment|//
name|UCHAR
name|ucPadding
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ENABLE_SCALER_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ENABLE_SCALER_PS_ALLOCATION
value|ENABLE_SCALER_PARAMETERS
end_define

begin_comment
comment|//ucEnable:
end_comment

begin_define
define|#
directive|define
name|SCALER_BYPASS_AUTO_CENTER_NO_REPLICATION
value|0
end_define

begin_define
define|#
directive|define
name|SCALER_BYPASS_AUTO_CENTER_AUTO_REPLICATION
value|1
end_define

begin_define
define|#
directive|define
name|SCALER_ENABLE_2TAP_ALPHA_MODE
value|2
end_define

begin_define
define|#
directive|define
name|SCALER_ENABLE_MULTITAP_MODE
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_HARDWARE_ICON_CURSOR_PARAMETERS
block|{
name|ULONG
name|usHWIconHorzVertPosn
decl_stmt|;
comment|// Hardware Icon Vertical position
name|UCHAR
name|ucHWIconVertOffset
decl_stmt|;
comment|// Hardware Icon Vertical offset
name|UCHAR
name|ucHWIconHorzOffset
decl_stmt|;
comment|// Hardware Icon Horizontal offset
name|UCHAR
name|ucSelection
decl_stmt|;
comment|// ATOM_CURSOR1 or ATOM_ICON1 or ATOM_CURSOR2 or ATOM_ICON2
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE or ATOM_DISABLE
block|}
name|ENABLE_HARDWARE_ICON_CURSOR_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_HARDWARE_ICON_CURSOR_PS_ALLOCATION
block|{
name|ENABLE_HARDWARE_ICON_CURSOR_PARAMETERS
name|sEnableIcon
decl_stmt|;
name|ENABLE_CRTC_PARAMETERS
name|sReserved
decl_stmt|;
block|}
name|ENABLE_HARDWARE_ICON_CURSOR_PS_ALLOCATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_GRAPH_SURFACE_PARAMETERS
block|{
name|USHORT
name|usHight
decl_stmt|;
comment|// Image Hight
name|USHORT
name|usWidth
decl_stmt|;
comment|// Image Width
name|UCHAR
name|ucSurface
decl_stmt|;
comment|// Surface 1 or 2
name|UCHAR
name|ucPadding
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ENABLE_GRAPH_SURFACE_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_GRAPH_SURFACE_PARAMETERS_V1_2
block|{
name|USHORT
name|usHight
decl_stmt|;
comment|// Image Hight
name|USHORT
name|usWidth
decl_stmt|;
comment|// Image Width
name|UCHAR
name|ucSurface
decl_stmt|;
comment|// Surface 1 or 2
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE or ATOM_DISABLE
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ENABLE_GRAPH_SURFACE_PARAMETERS_V1_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_GRAPH_SURFACE_PARAMETERS_V1_3
block|{
name|USHORT
name|usHight
decl_stmt|;
comment|// Image Hight
name|USHORT
name|usWidth
decl_stmt|;
comment|// Image Width
name|UCHAR
name|ucSurface
decl_stmt|;
comment|// Surface 1 or 2
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE or ATOM_DISABLE
name|USHORT
name|usDeviceId
decl_stmt|;
comment|// Active Device Id for this surface. If no device, set to 0.
block|}
name|ENABLE_GRAPH_SURFACE_PARAMETERS_V1_3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_GRAPH_SURFACE_PARAMETERS_V1_4
block|{
name|USHORT
name|usHight
decl_stmt|;
comment|// Image Hight
name|USHORT
name|usWidth
decl_stmt|;
comment|// Image Width
name|USHORT
name|usGraphPitch
decl_stmt|;
name|UCHAR
name|ucColorDepth
decl_stmt|;
name|UCHAR
name|ucPixelFormat
decl_stmt|;
name|UCHAR
name|ucSurface
decl_stmt|;
comment|// Surface 1 or 2
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE or ATOM_DISABLE
name|UCHAR
name|ucModeType
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|ENABLE_GRAPH_SURFACE_PARAMETERS_V1_4
typedef|;
end_typedef

begin_comment
comment|// ucEnable
end_comment

begin_define
define|#
directive|define
name|ATOM_GRAPH_CONTROL_SET_PITCH
value|0x0f
end_define

begin_define
define|#
directive|define
name|ATOM_GRAPH_CONTROL_SET_DISP_START
value|0x10
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ENABLE_GRAPH_SURFACE_PS_ALLOCATION
block|{
name|ENABLE_GRAPH_SURFACE_PARAMETERS
name|sSetSurface
decl_stmt|;
name|ENABLE_YUV_PS_ALLOCATION
name|sReserved
decl_stmt|;
comment|// Don't set this one
block|}
name|ENABLE_GRAPH_SURFACE_PS_ALLOCATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MEMORY_CLEAN_UP_PARAMETERS
block|{
name|USHORT
name|usMemoryStart
decl_stmt|;
comment|//in 8Kb boundary, offset from memory base address
name|USHORT
name|usMemorySize
decl_stmt|;
comment|//8Kb blocks aligned
block|}
name|MEMORY_CLEAN_UP_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MEMORY_CLEAN_UP_PS_ALLOCATION
value|MEMORY_CLEAN_UP_PARAMETERS
end_define

begin_typedef
typedef|typedef
struct|struct
name|_GET_DISPLAY_SURFACE_SIZE_PARAMETERS
block|{
name|USHORT
name|usX_Size
decl_stmt|;
comment|//When use as input parameter, usX_Size indicates which CRTC
name|USHORT
name|usY_Size
decl_stmt|;
block|}
name|GET_DISPLAY_SURFACE_SIZE_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_GET_DISPLAY_SURFACE_SIZE_PARAMETERS_V2
block|{
union|union
block|{
name|USHORT
name|usX_Size
decl_stmt|;
comment|//When use as input parameter, usX_Size indicates which CRTC
name|USHORT
name|usSurface
decl_stmt|;
block|}
union|;
name|USHORT
name|usY_Size
decl_stmt|;
name|USHORT
name|usDispXStart
decl_stmt|;
name|USHORT
name|usDispYStart
decl_stmt|;
block|}
name|GET_DISPLAY_SURFACE_SIZE_PARAMETERS_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PALETTE_DATA_CONTROL_PARAMETERS_V3
block|{
name|UCHAR
name|ucLutId
decl_stmt|;
name|UCHAR
name|ucAction
decl_stmt|;
name|USHORT
name|usLutStartIndex
decl_stmt|;
name|USHORT
name|usLutLength
decl_stmt|;
name|USHORT
name|usLutOffsetInVram
decl_stmt|;
block|}
name|PALETTE_DATA_CONTROL_PARAMETERS_V3
typedef|;
end_typedef

begin_comment
comment|// ucAction:
end_comment

begin_define
define|#
directive|define
name|PALETTE_DATA_AUTO_FILL
value|1
end_define

begin_define
define|#
directive|define
name|PALETTE_DATA_READ
value|2
end_define

begin_define
define|#
directive|define
name|PALETTE_DATA_WRITE
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|_INTERRUPT_SERVICE_PARAMETERS_V2
block|{
name|UCHAR
name|ucInterruptId
decl_stmt|;
name|UCHAR
name|ucServiceId
decl_stmt|;
name|UCHAR
name|ucStatus
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|INTERRUPT_SERVICE_PARAMETER_V2
typedef|;
end_typedef

begin_comment
comment|// ucInterruptId
end_comment

begin_define
define|#
directive|define
name|HDP1_INTERRUPT_ID
value|1
end_define

begin_define
define|#
directive|define
name|HDP2_INTERRUPT_ID
value|2
end_define

begin_define
define|#
directive|define
name|HDP3_INTERRUPT_ID
value|3
end_define

begin_define
define|#
directive|define
name|HDP4_INTERRUPT_ID
value|4
end_define

begin_define
define|#
directive|define
name|HDP5_INTERRUPT_ID
value|5
end_define

begin_define
define|#
directive|define
name|HDP6_INTERRUPT_ID
value|6
end_define

begin_define
define|#
directive|define
name|SW_INTERRUPT_ID
value|11
end_define

begin_comment
comment|// ucAction
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_SERVICE_GEN_SW_INT
value|1
end_define

begin_define
define|#
directive|define
name|INTERRUPT_SERVICE_GET_STATUS
value|2
end_define

begin_comment
comment|// ucStatus
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_STATUS__INT_TRIGGER
value|1
end_define

begin_define
define|#
directive|define
name|INTERRUPT_STATUS__HPD_HIGH
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_INDIRECT_IO_ACCESS
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|IOAccessSequence
index|[
literal|256
index|]
decl_stmt|;
block|}
name|INDIRECT_IO_ACCESS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INDIRECT_READ
value|0x00
end_define

begin_define
define|#
directive|define
name|INDIRECT_WRITE
value|0x80
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_MM
value|0
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_PLL
value|1
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_MC
value|2
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_PCIE
value|3
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_PCIEP
value|4
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_NBMISC
value|5
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_PLL_READ
value|INDIRECT_IO_PLL   | INDIRECT_READ
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_PLL_WRITE
value|INDIRECT_IO_PLL   | INDIRECT_WRITE
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_MC_READ
value|INDIRECT_IO_MC    | INDIRECT_READ
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_MC_WRITE
value|INDIRECT_IO_MC    | INDIRECT_WRITE
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_PCIE_READ
value|INDIRECT_IO_PCIE  | INDIRECT_READ
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_PCIE_WRITE
value|INDIRECT_IO_PCIE  | INDIRECT_WRITE
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_PCIEP_READ
value|INDIRECT_IO_PCIEP | INDIRECT_READ
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_PCIEP_WRITE
value|INDIRECT_IO_PCIEP | INDIRECT_WRITE
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_NBMISC_READ
value|INDIRECT_IO_NBMISC | INDIRECT_READ
end_define

begin_define
define|#
directive|define
name|INDIRECT_IO_NBMISC_WRITE
value|INDIRECT_IO_NBMISC | INDIRECT_WRITE
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_OEM_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_I2C_ID_CONFIG_ACCESS
name|sucI2cId
decl_stmt|;
block|}
name|ATOM_OEM_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_TV_MODE
block|{
name|UCHAR
name|ucVMode_Num
decl_stmt|;
comment|//Video mode number
name|UCHAR
name|ucTV_Mode_Num
decl_stmt|;
comment|//Internal TV mode number
block|}
name|ATOM_TV_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_BIOS_INT_TVSTD_MODE
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usTV_Mode_LUT_Offset
decl_stmt|;
comment|// Pointer to standard to internal number conversion table
name|USHORT
name|usTV_FIFO_Offset
decl_stmt|;
comment|// Pointer to FIFO entry table
name|USHORT
name|usNTSC_Tbl_Offset
decl_stmt|;
comment|// Pointer to SDTV_Mode_NTSC table
name|USHORT
name|usPAL_Tbl_Offset
decl_stmt|;
comment|// Pointer to SDTV_Mode_PAL table
name|USHORT
name|usCV_Tbl_Offset
decl_stmt|;
comment|// Pointer to SDTV_Mode_PAL table
block|}
name|ATOM_BIOS_INT_TVSTD_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_TV_MODE_SCALER_PTR
block|{
name|USHORT
name|ucFilter0_Offset
decl_stmt|;
comment|//Pointer to filter format 0 coefficients
name|USHORT
name|usFilter1_Offset
decl_stmt|;
comment|//Pointer to filter format 0 coefficients
name|UCHAR
name|ucTV_Mode_Num
decl_stmt|;
block|}
name|ATOM_TV_MODE_SCALER_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_STANDARD_VESA_TIMING
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_DTD_FORMAT
name|aModeTimings
index|[
literal|16
index|]
decl_stmt|;
comment|// 16 is not the real array number, just for initial allocation
block|}
name|ATOM_STANDARD_VESA_TIMING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_STD_FORMAT
block|{
name|USHORT
name|usSTD_HDisp
decl_stmt|;
name|USHORT
name|usSTD_VDisp
decl_stmt|;
name|USHORT
name|usSTD_RefreshRate
decl_stmt|;
name|USHORT
name|usReserved
decl_stmt|;
block|}
name|ATOM_STD_FORMAT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VESA_TO_EXTENDED_MODE
block|{
name|USHORT
name|usVESA_ModeNumber
decl_stmt|;
name|USHORT
name|usExtendedModeNumber
decl_stmt|;
block|}
name|ATOM_VESA_TO_EXTENDED_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VESA_TO_INTENAL_MODE_LUT
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|ATOM_VESA_TO_EXTENDED_MODE
name|asVESA_ToExtendedModeInfo
index|[
literal|76
index|]
decl_stmt|;
block|}
name|ATOM_VESA_TO_INTENAL_MODE_LUT
typedef|;
end_typedef

begin_comment
comment|/*************** ATOM Memory Related Data Structure ***********************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MEMORY_VENDOR_BLOCK
block|{
name|UCHAR
name|ucMemoryType
decl_stmt|;
name|UCHAR
name|ucMemoryVendor
decl_stmt|;
name|UCHAR
name|ucAdjMCId
decl_stmt|;
name|UCHAR
name|ucDynClkId
decl_stmt|;
name|ULONG
name|ulDllResetClkRange
decl_stmt|;
block|}
name|ATOM_MEMORY_VENDOR_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MEMORY_SETTING_ID_CONFIG
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|ULONG
name|ucMemBlkId
range|:
literal|8
decl_stmt|;
name|ULONG
name|ulMemClockRange
range|:
literal|24
decl_stmt|;
else|#
directive|else
name|ULONG
name|ulMemClockRange
range|:
literal|24
decl_stmt|;
name|ULONG
name|ucMemBlkId
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
block|}
name|ATOM_MEMORY_SETTING_ID_CONFIG
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_ATOM_MEMORY_SETTING_ID_CONFIG_ACCESS
block|{
name|ATOM_MEMORY_SETTING_ID_CONFIG
name|slAccess
decl_stmt|;
name|ULONG
name|ulAccess
decl_stmt|;
block|}
name|ATOM_MEMORY_SETTING_ID_CONFIG_ACCESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MEMORY_SETTING_DATA_BLOCK
block|{
name|ATOM_MEMORY_SETTING_ID_CONFIG_ACCESS
name|ulMemoryID
decl_stmt|;
name|ULONG
name|aulMemData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_MEMORY_SETTING_DATA_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_INIT_REG_INDEX_FORMAT
block|{
name|USHORT
name|usRegIndex
decl_stmt|;
comment|// MC register index
name|UCHAR
name|ucPreRegDataLength
decl_stmt|;
comment|// offset in ATOM_INIT_REG_DATA_BLOCK.saRegDataBuf
block|}
name|ATOM_INIT_REG_INDEX_FORMAT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_INIT_REG_BLOCK
block|{
name|USHORT
name|usRegIndexTblSize
decl_stmt|;
comment|//size of asRegIndexBuf
name|USHORT
name|usRegDataBlkSize
decl_stmt|;
comment|//size of ATOM_MEMORY_SETTING_DATA_BLOCK
name|ATOM_INIT_REG_INDEX_FORMAT
name|asRegIndexBuf
index|[
literal|1
index|]
decl_stmt|;
name|ATOM_MEMORY_SETTING_DATA_BLOCK
name|asRegDataBuf
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_INIT_REG_BLOCK
typedef|;
end_typedef

begin_define
define|#
directive|define
name|END_OF_REG_INDEX_BLOCK
value|0x0ffff
end_define

begin_define
define|#
directive|define
name|END_OF_REG_DATA_BLOCK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATOM_INIT_REG_MASK_FLAG
value|0x80
end_define

begin_comment
comment|//Not used in BIOS
end_comment

begin_define
define|#
directive|define
name|CLOCK_RANGE_HIGHEST
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|VALUE_DWORD
value|SIZEOF ULONG
end_define

begin_define
define|#
directive|define
name|VALUE_SAME_AS_ABOVE
value|0
end_define

begin_define
define|#
directive|define
name|VALUE_MASK_DWORD
value|0x84
end_define

begin_define
define|#
directive|define
name|INDEX_ACCESS_RANGE_BEGIN
value|(VALUE_DWORD + 1)
end_define

begin_define
define|#
directive|define
name|INDEX_ACCESS_RANGE_END
value|(INDEX_ACCESS_RANGE_BEGIN + 1)
end_define

begin_define
define|#
directive|define
name|VALUE_INDEX_ACCESS_SINGLE
value|(INDEX_ACCESS_RANGE_END + 1)
end_define

begin_comment
comment|//#define ACCESS_MCIODEBUGIND            0x40       //defined in BIOS code
end_comment

begin_define
define|#
directive|define
name|ACCESS_PLACEHOLDER
value|0x80
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MC_INIT_PARAM_TABLE
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usAdjustARB_SEQDataOffset
decl_stmt|;
name|USHORT
name|usMCInitMemTypeTblOffset
decl_stmt|;
name|USHORT
name|usMCInitCommonTblOffset
decl_stmt|;
name|USHORT
name|usMCInitPowerDownTblOffset
decl_stmt|;
name|ULONG
name|ulARB_SEQDataBuf
index|[
literal|32
index|]
decl_stmt|;
name|ATOM_INIT_REG_BLOCK
name|asMCInitMemType
decl_stmt|;
name|ATOM_INIT_REG_BLOCK
name|asMCInitCommon
decl_stmt|;
block|}
name|ATOM_MC_INIT_PARAM_TABLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_4Mx16
value|0x2
end_define

begin_define
define|#
directive|define
name|_4Mx32
value|0x3
end_define

begin_define
define|#
directive|define
name|_8Mx16
value|0x12
end_define

begin_define
define|#
directive|define
name|_8Mx32
value|0x13
end_define

begin_define
define|#
directive|define
name|_16Mx16
value|0x22
end_define

begin_define
define|#
directive|define
name|_16Mx32
value|0x23
end_define

begin_define
define|#
directive|define
name|_32Mx16
value|0x32
end_define

begin_define
define|#
directive|define
name|_32Mx32
value|0x33
end_define

begin_define
define|#
directive|define
name|_64Mx8
value|0x41
end_define

begin_define
define|#
directive|define
name|_64Mx16
value|0x42
end_define

begin_define
define|#
directive|define
name|_64Mx32
value|0x43
end_define

begin_define
define|#
directive|define
name|_128Mx8
value|0x51
end_define

begin_define
define|#
directive|define
name|_128Mx16
value|0x52
end_define

begin_define
define|#
directive|define
name|_256Mx8
value|0x61
end_define

begin_define
define|#
directive|define
name|_256Mx16
value|0x62
end_define

begin_define
define|#
directive|define
name|SAMSUNG
value|0x1
end_define

begin_define
define|#
directive|define
name|INFINEON
value|0x2
end_define

begin_define
define|#
directive|define
name|ELPIDA
value|0x3
end_define

begin_define
define|#
directive|define
name|ETRON
value|0x4
end_define

begin_define
define|#
directive|define
name|NANYA
value|0x5
end_define

begin_define
define|#
directive|define
name|HYNIX
value|0x6
end_define

begin_define
define|#
directive|define
name|MOSEL
value|0x7
end_define

begin_define
define|#
directive|define
name|WINBOND
value|0x8
end_define

begin_define
define|#
directive|define
name|ESMT
value|0x9
end_define

begin_define
define|#
directive|define
name|MICRON
value|0xF
end_define

begin_define
define|#
directive|define
name|QIMONDA
value|INFINEON
end_define

begin_define
define|#
directive|define
name|PROMOS
value|MOSEL
end_define

begin_define
define|#
directive|define
name|KRETON
value|INFINEON
end_define

begin_define
define|#
directive|define
name|ELIXIR
value|NANYA
end_define

begin_comment
comment|/////////////Support for GDDR5 MC uCode to reside in upper 64K of ROM/////////////
end_comment

begin_define
define|#
directive|define
name|UCODE_ROM_START_ADDRESS
value|0x1b800
end_define

begin_define
define|#
directive|define
name|UCODE_SIGNATURE
value|0x4375434d
end_define

begin_comment
comment|// 'MCuC' - MC uCode
end_comment

begin_comment
comment|//uCode block header for reference
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MCuCodeHeader
block|{
name|ULONG
name|ulSignature
decl_stmt|;
name|UCHAR
name|ucRevision
decl_stmt|;
name|UCHAR
name|ucChecksum
decl_stmt|;
name|UCHAR
name|ucReserved1
decl_stmt|;
name|UCHAR
name|ucReserved2
decl_stmt|;
name|USHORT
name|usParametersLength
decl_stmt|;
name|USHORT
name|usUCodeLength
decl_stmt|;
name|USHORT
name|usReserved1
decl_stmt|;
name|USHORT
name|usReserved2
decl_stmt|;
block|}
name|MCuCodeHeader
typedef|;
end_typedef

begin_comment
comment|//////////////////////////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|ATOM_MAX_NUMBER_OF_VRAM_MODULE
value|16
end_define

begin_define
define|#
directive|define
name|ATOM_VRAM_MODULE_MEMORY_VENDOR_ID_MASK
value|0xF
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_MODULE_V1
block|{
name|ULONG
name|ulReserved
decl_stmt|;
name|USHORT
name|usEMRSValue
decl_stmt|;
name|USHORT
name|usMRSValue
decl_stmt|;
name|USHORT
name|usReserved
decl_stmt|;
name|UCHAR
name|ucExtMemoryID
decl_stmt|;
comment|// An external indicator (by hardcode, callback or pin) to tell what is the current memory module
name|UCHAR
name|ucMemoryType
decl_stmt|;
comment|// [7:4]=0x1:DDR1;=0x2:DDR2;=0x3:DDR3;=0x4:DDR4;[3:0] reserved;
name|UCHAR
name|ucMemoryVenderID
decl_stmt|;
comment|// Predefined,never change across designs or memory type/vender
name|UCHAR
name|ucMemoryDeviceCfg
decl_stmt|;
comment|// [7:4]=0x0:4M;=0x1:8M;=0x2:16M;0x3:32M....[3:0]=0x0:x4;=0x1:x8;=0x2:x16;=0x3:x32...
name|UCHAR
name|ucRow
decl_stmt|;
comment|// Number of Row,in power of 2;
name|UCHAR
name|ucColumn
decl_stmt|;
comment|// Number of Column,in power of 2;
name|UCHAR
name|ucBank
decl_stmt|;
comment|// Nunber of Bank;
name|UCHAR
name|ucRank
decl_stmt|;
comment|// Number of Rank, in power of 2
name|UCHAR
name|ucChannelNum
decl_stmt|;
comment|// Number of channel;
name|UCHAR
name|ucChannelConfig
decl_stmt|;
comment|// [3:0]=Indication of what channel combination;[4:7]=Channel bit width, in number of 2
name|UCHAR
name|ucDefaultMVDDQ_ID
decl_stmt|;
comment|// Default MVDDQ setting for this memory block, ID linking to MVDDQ info table to find real set-up data;
name|UCHAR
name|ucDefaultMVDDC_ID
decl_stmt|;
comment|// Default MVDDC setting for this memory block, ID linking to MVDDC info table to find real set-up data;
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ATOM_VRAM_MODULE_V1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_MODULE_V2
block|{
name|ULONG
name|ulReserved
decl_stmt|;
name|ULONG
name|ulFlags
decl_stmt|;
comment|// To enable/disable functionalities based on memory type
name|ULONG
name|ulEngineClock
decl_stmt|;
comment|// Override of default engine clock for particular memory type
name|ULONG
name|ulMemoryClock
decl_stmt|;
comment|// Override of default memory clock for particular memory type
name|USHORT
name|usEMRS2Value
decl_stmt|;
comment|// EMRS2 Value is used for GDDR2 and GDDR4 memory type
name|USHORT
name|usEMRS3Value
decl_stmt|;
comment|// EMRS3 Value is used for GDDR2 and GDDR4 memory type
name|USHORT
name|usEMRSValue
decl_stmt|;
name|USHORT
name|usMRSValue
decl_stmt|;
name|USHORT
name|usReserved
decl_stmt|;
name|UCHAR
name|ucExtMemoryID
decl_stmt|;
comment|// An external indicator (by hardcode, callback or pin) to tell what is the current memory module
name|UCHAR
name|ucMemoryType
decl_stmt|;
comment|// [7:4]=0x1:DDR1;=0x2:DDR2;=0x3:DDR3;=0x4:DDR4;[3:0] - must not be used for now;
name|UCHAR
name|ucMemoryVenderID
decl_stmt|;
comment|// Predefined,never change across designs or memory type/vender. If not predefined, vendor detection table gets executed
name|UCHAR
name|ucMemoryDeviceCfg
decl_stmt|;
comment|// [7:4]=0x0:4M;=0x1:8M;=0x2:16M;0x3:32M....[3:0]=0x0:x4;=0x1:x8;=0x2:x16;=0x3:x32...
name|UCHAR
name|ucRow
decl_stmt|;
comment|// Number of Row,in power of 2;
name|UCHAR
name|ucColumn
decl_stmt|;
comment|// Number of Column,in power of 2;
name|UCHAR
name|ucBank
decl_stmt|;
comment|// Nunber of Bank;
name|UCHAR
name|ucRank
decl_stmt|;
comment|// Number of Rank, in power of 2
name|UCHAR
name|ucChannelNum
decl_stmt|;
comment|// Number of channel;
name|UCHAR
name|ucChannelConfig
decl_stmt|;
comment|// [3:0]=Indication of what channel combination;[4:7]=Channel bit width, in number of 2
name|UCHAR
name|ucDefaultMVDDQ_ID
decl_stmt|;
comment|// Default MVDDQ setting for this memory block, ID linking to MVDDQ info table to find real set-up data;
name|UCHAR
name|ucDefaultMVDDC_ID
decl_stmt|;
comment|// Default MVDDC setting for this memory block, ID linking to MVDDC info table to find real set-up data;
name|UCHAR
name|ucRefreshRateFactor
decl_stmt|;
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ATOM_VRAM_MODULE_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MEMORY_TIMING_FORMAT
block|{
name|ULONG
name|ulClkRange
decl_stmt|;
comment|// memory clock in 10kHz unit, when target memory clock is below this clock, use this memory timing
union|union
block|{
name|USHORT
name|usMRS
decl_stmt|;
comment|// mode register
name|USHORT
name|usDDR3_MR0
decl_stmt|;
block|}
union|;
union|union
block|{
name|USHORT
name|usEMRS
decl_stmt|;
comment|// extended mode register
name|USHORT
name|usDDR3_MR1
decl_stmt|;
block|}
union|;
name|UCHAR
name|ucCL
decl_stmt|;
comment|// CAS latency
name|UCHAR
name|ucWL
decl_stmt|;
comment|// WRITE Latency
name|UCHAR
name|uctRAS
decl_stmt|;
comment|// tRAS
name|UCHAR
name|uctRC
decl_stmt|;
comment|// tRC
name|UCHAR
name|uctRFC
decl_stmt|;
comment|// tRFC
name|UCHAR
name|uctRCDR
decl_stmt|;
comment|// tRCDR
name|UCHAR
name|uctRCDW
decl_stmt|;
comment|// tRCDW
name|UCHAR
name|uctRP
decl_stmt|;
comment|// tRP
name|UCHAR
name|uctRRD
decl_stmt|;
comment|// tRRD
name|UCHAR
name|uctWR
decl_stmt|;
comment|// tWR
name|UCHAR
name|uctWTR
decl_stmt|;
comment|// tWTR
name|UCHAR
name|uctPDIX
decl_stmt|;
comment|// tPDIX
name|UCHAR
name|uctFAW
decl_stmt|;
comment|// tFAW
name|UCHAR
name|uctAOND
decl_stmt|;
comment|// tAOND
union|union
block|{
struct|struct
block|{
name|UCHAR
name|ucflag
decl_stmt|;
comment|// flag to control memory timing calculation. bit0= control EMRS2 Infineon
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
struct|;
name|USHORT
name|usDDR3_MR2
decl_stmt|;
block|}
union|;
block|}
name|ATOM_MEMORY_TIMING_FORMAT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MEMORY_TIMING_FORMAT_V1
block|{
name|ULONG
name|ulClkRange
decl_stmt|;
comment|// memory clock in 10kHz unit, when target memory clock is below this clock, use this memory timing
name|USHORT
name|usMRS
decl_stmt|;
comment|// mode register
name|USHORT
name|usEMRS
decl_stmt|;
comment|// extended mode register
name|UCHAR
name|ucCL
decl_stmt|;
comment|// CAS latency
name|UCHAR
name|ucWL
decl_stmt|;
comment|// WRITE Latency
name|UCHAR
name|uctRAS
decl_stmt|;
comment|// tRAS
name|UCHAR
name|uctRC
decl_stmt|;
comment|// tRC
name|UCHAR
name|uctRFC
decl_stmt|;
comment|// tRFC
name|UCHAR
name|uctRCDR
decl_stmt|;
comment|// tRCDR
name|UCHAR
name|uctRCDW
decl_stmt|;
comment|// tRCDW
name|UCHAR
name|uctRP
decl_stmt|;
comment|// tRP
name|UCHAR
name|uctRRD
decl_stmt|;
comment|// tRRD
name|UCHAR
name|uctWR
decl_stmt|;
comment|// tWR
name|UCHAR
name|uctWTR
decl_stmt|;
comment|// tWTR
name|UCHAR
name|uctPDIX
decl_stmt|;
comment|// tPDIX
name|UCHAR
name|uctFAW
decl_stmt|;
comment|// tFAW
name|UCHAR
name|uctAOND
decl_stmt|;
comment|// tAOND
name|UCHAR
name|ucflag
decl_stmt|;
comment|// flag to control memory timing calculation. bit0= control EMRS2 Infineon
comment|////////////////////////////////////GDDR parameters///////////////////////////////////
name|UCHAR
name|uctCCDL
decl_stmt|;
comment|//
name|UCHAR
name|uctCRCRL
decl_stmt|;
comment|//
name|UCHAR
name|uctCRCWL
decl_stmt|;
comment|//
name|UCHAR
name|uctCKE
decl_stmt|;
comment|//
name|UCHAR
name|uctCKRSE
decl_stmt|;
comment|//
name|UCHAR
name|uctCKRSX
decl_stmt|;
comment|//
name|UCHAR
name|uctFAW32
decl_stmt|;
comment|//
name|UCHAR
name|ucMR5lo
decl_stmt|;
comment|//
name|UCHAR
name|ucMR5hi
decl_stmt|;
comment|//
name|UCHAR
name|ucTerminator
decl_stmt|;
block|}
name|ATOM_MEMORY_TIMING_FORMAT_V1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MEMORY_TIMING_FORMAT_V2
block|{
name|ULONG
name|ulClkRange
decl_stmt|;
comment|// memory clock in 10kHz unit, when target memory clock is below this clock, use this memory timing
name|USHORT
name|usMRS
decl_stmt|;
comment|// mode register
name|USHORT
name|usEMRS
decl_stmt|;
comment|// extended mode register
name|UCHAR
name|ucCL
decl_stmt|;
comment|// CAS latency
name|UCHAR
name|ucWL
decl_stmt|;
comment|// WRITE Latency
name|UCHAR
name|uctRAS
decl_stmt|;
comment|// tRAS
name|UCHAR
name|uctRC
decl_stmt|;
comment|// tRC
name|UCHAR
name|uctRFC
decl_stmt|;
comment|// tRFC
name|UCHAR
name|uctRCDR
decl_stmt|;
comment|// tRCDR
name|UCHAR
name|uctRCDW
decl_stmt|;
comment|// tRCDW
name|UCHAR
name|uctRP
decl_stmt|;
comment|// tRP
name|UCHAR
name|uctRRD
decl_stmt|;
comment|// tRRD
name|UCHAR
name|uctWR
decl_stmt|;
comment|// tWR
name|UCHAR
name|uctWTR
decl_stmt|;
comment|// tWTR
name|UCHAR
name|uctPDIX
decl_stmt|;
comment|// tPDIX
name|UCHAR
name|uctFAW
decl_stmt|;
comment|// tFAW
name|UCHAR
name|uctAOND
decl_stmt|;
comment|// tAOND
name|UCHAR
name|ucflag
decl_stmt|;
comment|// flag to control memory timing calculation. bit0= control EMRS2 Infineon
comment|////////////////////////////////////GDDR parameters///////////////////////////////////
name|UCHAR
name|uctCCDL
decl_stmt|;
comment|//
name|UCHAR
name|uctCRCRL
decl_stmt|;
comment|//
name|UCHAR
name|uctCRCWL
decl_stmt|;
comment|//
name|UCHAR
name|uctCKE
decl_stmt|;
comment|//
name|UCHAR
name|uctCKRSE
decl_stmt|;
comment|//
name|UCHAR
name|uctCKRSX
decl_stmt|;
comment|//
name|UCHAR
name|uctFAW32
decl_stmt|;
comment|//
name|UCHAR
name|ucMR4lo
decl_stmt|;
comment|//
name|UCHAR
name|ucMR4hi
decl_stmt|;
comment|//
name|UCHAR
name|ucMR5lo
decl_stmt|;
comment|//
name|UCHAR
name|ucMR5hi
decl_stmt|;
comment|//
name|UCHAR
name|ucTerminator
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|ATOM_MEMORY_TIMING_FORMAT_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MEMORY_FORMAT
block|{
name|ULONG
name|ulDllDisClock
decl_stmt|;
comment|// memory DLL will be disable when target memory clock is below this clock
union|union
block|{
name|USHORT
name|usEMRS2Value
decl_stmt|;
comment|// EMRS2 Value is used for GDDR2 and GDDR4 memory type
name|USHORT
name|usDDR3_Reserved
decl_stmt|;
comment|// Not used for DDR3 memory
block|}
union|;
union|union
block|{
name|USHORT
name|usEMRS3Value
decl_stmt|;
comment|// EMRS3 Value is used for GDDR2 and GDDR4 memory type
name|USHORT
name|usDDR3_MR3
decl_stmt|;
comment|// Used for DDR3 memory
block|}
union|;
name|UCHAR
name|ucMemoryType
decl_stmt|;
comment|// [7:4]=0x1:DDR1;=0x2:DDR2;=0x3:DDR3;=0x4:DDR4;[3:0] - must not be used for now;
name|UCHAR
name|ucMemoryVenderID
decl_stmt|;
comment|// Predefined,never change across designs or memory type/vender. If not predefined, vendor detection table gets executed
name|UCHAR
name|ucRow
decl_stmt|;
comment|// Number of Row,in power of 2;
name|UCHAR
name|ucColumn
decl_stmt|;
comment|// Number of Column,in power of 2;
name|UCHAR
name|ucBank
decl_stmt|;
comment|// Nunber of Bank;
name|UCHAR
name|ucRank
decl_stmt|;
comment|// Number of Rank, in power of 2
name|UCHAR
name|ucBurstSize
decl_stmt|;
comment|// burst size, 0= burst size=4  1= burst size=8
name|UCHAR
name|ucDllDisBit
decl_stmt|;
comment|// position of DLL Enable/Disable bit in EMRS ( Extended Mode Register )
name|UCHAR
name|ucRefreshRateFactor
decl_stmt|;
comment|// memory refresh rate in unit of ms
name|UCHAR
name|ucDensity
decl_stmt|;
comment|// _8Mx32, _16Mx32, _16Mx16, _32Mx16
name|UCHAR
name|ucPreamble
decl_stmt|;
comment|//[7:4] Write Preamble, [3:0] Read Preamble
name|UCHAR
name|ucMemAttrib
decl_stmt|;
comment|// Memory Device Addribute, like RDBI/WDBI etc
name|ATOM_MEMORY_TIMING_FORMAT
name|asMemTiming
index|[
literal|5
index|]
decl_stmt|;
comment|//Memory Timing block sort from lower clock to higher clock
block|}
name|ATOM_MEMORY_FORMAT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_MODULE_V3
block|{
name|ULONG
name|ulChannelMapCfg
decl_stmt|;
comment|// board dependent paramenter:Channel combination
name|USHORT
name|usSize
decl_stmt|;
comment|// size of ATOM_VRAM_MODULE_V3
name|USHORT
name|usDefaultMVDDQ
decl_stmt|;
comment|// board dependent parameter:Default Memory Core Voltage
name|USHORT
name|usDefaultMVDDC
decl_stmt|;
comment|// board dependent parameter:Default Memory IO Voltage
name|UCHAR
name|ucExtMemoryID
decl_stmt|;
comment|// An external indicator (by hardcode, callback or pin) to tell what is the current memory module
name|UCHAR
name|ucChannelNum
decl_stmt|;
comment|// board dependent parameter:Number of channel;
name|UCHAR
name|ucChannelSize
decl_stmt|;
comment|// board dependent parameter:32bit or 64bit
name|UCHAR
name|ucVREFI
decl_stmt|;
comment|// board dependnt parameter: EXT or INT +160mv to -140mv
name|UCHAR
name|ucNPL_RT
decl_stmt|;
comment|// board dependent parameter:NPL round trip delay, used for calculate memory timing parameters
name|UCHAR
name|ucFlag
decl_stmt|;
comment|// To enable/disable functionalities based on memory type
name|ATOM_MEMORY_FORMAT
name|asMemory
decl_stmt|;
comment|// describ all of video memory parameters from memory spec
block|}
name|ATOM_VRAM_MODULE_V3
typedef|;
end_typedef

begin_comment
comment|//ATOM_VRAM_MODULE_V3.ucNPL_RT
end_comment

begin_define
define|#
directive|define
name|NPL_RT_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|BATTERY_ODT_MASK
value|0xc0
end_define

begin_define
define|#
directive|define
name|ATOM_VRAM_MODULE
value|ATOM_VRAM_MODULE_V3
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_MODULE_V4
block|{
name|ULONG
name|ulChannelMapCfg
decl_stmt|;
comment|// board dependent parameter: Channel combination
name|USHORT
name|usModuleSize
decl_stmt|;
comment|// size of ATOM_VRAM_MODULE_V4, make it easy for VBIOS to look for next entry of VRAM_MODULE
name|USHORT
name|usPrivateReserved
decl_stmt|;
comment|// BIOS internal reserved space to optimize code size, updated by the compiler, shouldn't be modified manually!!
comment|// MC_ARB_RAMCFG (includes NOOFBANK,NOOFRANKS,NOOFROWS,NOOFCOLS)
name|USHORT
name|usReserved
decl_stmt|;
name|UCHAR
name|ucExtMemoryID
decl_stmt|;
comment|// An external indicator (by hardcode, callback or pin) to tell what is the current memory module
name|UCHAR
name|ucMemoryType
decl_stmt|;
comment|// [7:4]=0x1:DDR1;=0x2:DDR2;=0x3:DDR3;=0x4:DDR4; 0x5:DDR5 [3:0] - Must be 0x0 for now;
name|UCHAR
name|ucChannelNum
decl_stmt|;
comment|// Number of channels present in this module config
name|UCHAR
name|ucChannelWidth
decl_stmt|;
comment|// 0 - 32 bits; 1 - 64 bits
name|UCHAR
name|ucDensity
decl_stmt|;
comment|// _8Mx32, _16Mx32, _16Mx16, _32Mx16
name|UCHAR
name|ucFlag
decl_stmt|;
comment|// To enable/disable functionalities based on memory type
name|UCHAR
name|ucMisc
decl_stmt|;
comment|// bit0: 0 - single rank; 1 - dual rank;   bit2: 0 - burstlength 4, 1 - burstlength 8
name|UCHAR
name|ucVREFI
decl_stmt|;
comment|// board dependent parameter
name|UCHAR
name|ucNPL_RT
decl_stmt|;
comment|// board dependent parameter:NPL round trip delay, used for calculate memory timing parameters
name|UCHAR
name|ucPreamble
decl_stmt|;
comment|// [7:4] Write Preamble, [3:0] Read Preamble
name|UCHAR
name|ucMemorySize
decl_stmt|;
comment|// BIOS internal reserved space to optimize code size, updated by the compiler, shouldn't be modified manually!!
comment|// Total memory size in unit of 16MB for CONFIG_MEMSIZE - bit[23:0] zeros
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
comment|//compare with V3, we flat the struct by merging ATOM_MEMORY_FORMAT (as is) into V4 as the same level
union|union
block|{
name|USHORT
name|usEMRS2Value
decl_stmt|;
comment|// EMRS2 Value is used for GDDR2 and GDDR4 memory type
name|USHORT
name|usDDR3_Reserved
decl_stmt|;
block|}
union|;
union|union
block|{
name|USHORT
name|usEMRS3Value
decl_stmt|;
comment|// EMRS3 Value is used for GDDR2 and GDDR4 memory type
name|USHORT
name|usDDR3_MR3
decl_stmt|;
comment|// Used for DDR3 memory
block|}
union|;
name|UCHAR
name|ucMemoryVenderID
decl_stmt|;
comment|// Predefined, If not predefined, vendor detection table gets executed
name|UCHAR
name|ucRefreshRateFactor
decl_stmt|;
comment|// [1:0]=RefreshFactor (00=8ms, 01=16ms, 10=32ms,11=64ms)
name|UCHAR
name|ucReserved2
index|[
literal|2
index|]
decl_stmt|;
name|ATOM_MEMORY_TIMING_FORMAT
name|asMemTiming
index|[
literal|5
index|]
decl_stmt|;
comment|//Memory Timing block sort from lower clock to higher clock
block|}
name|ATOM_VRAM_MODULE_V4
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VRAM_MODULE_V4_MISC_RANK_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|VRAM_MODULE_V4_MISC_DUAL_RANK
value|0x1
end_define

begin_define
define|#
directive|define
name|VRAM_MODULE_V4_MISC_BL_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|VRAM_MODULE_V4_MISC_BL8
value|0x4
end_define

begin_define
define|#
directive|define
name|VRAM_MODULE_V4_MISC_DUAL_CS
value|0x10
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_MODULE_V5
block|{
name|ULONG
name|ulChannelMapCfg
decl_stmt|;
comment|// board dependent parameter: Channel combination
name|USHORT
name|usModuleSize
decl_stmt|;
comment|// size of ATOM_VRAM_MODULE_V4, make it easy for VBIOS to look for next entry of VRAM_MODULE
name|USHORT
name|usPrivateReserved
decl_stmt|;
comment|// BIOS internal reserved space to optimize code size, updated by the compiler, shouldn't be modified manually!!
comment|// MC_ARB_RAMCFG (includes NOOFBANK,NOOFRANKS,NOOFROWS,NOOFCOLS)
name|USHORT
name|usReserved
decl_stmt|;
name|UCHAR
name|ucExtMemoryID
decl_stmt|;
comment|// An external indicator (by hardcode, callback or pin) to tell what is the current memory module
name|UCHAR
name|ucMemoryType
decl_stmt|;
comment|// [7:4]=0x1:DDR1;=0x2:DDR2;=0x3:DDR3;=0x4:DDR4; 0x5:DDR5 [3:0] - Must be 0x0 for now;
name|UCHAR
name|ucChannelNum
decl_stmt|;
comment|// Number of channels present in this module config
name|UCHAR
name|ucChannelWidth
decl_stmt|;
comment|// 0 - 32 bits; 1 - 64 bits
name|UCHAR
name|ucDensity
decl_stmt|;
comment|// _8Mx32, _16Mx32, _16Mx16, _32Mx16
name|UCHAR
name|ucFlag
decl_stmt|;
comment|// To enable/disable functionalities based on memory type
name|UCHAR
name|ucMisc
decl_stmt|;
comment|// bit0: 0 - single rank; 1 - dual rank;   bit2: 0 - burstlength 4, 1 - burstlength 8
name|UCHAR
name|ucVREFI
decl_stmt|;
comment|// board dependent parameter
name|UCHAR
name|ucNPL_RT
decl_stmt|;
comment|// board dependent parameter:NPL round trip delay, used for calculate memory timing parameters
name|UCHAR
name|ucPreamble
decl_stmt|;
comment|// [7:4] Write Preamble, [3:0] Read Preamble
name|UCHAR
name|ucMemorySize
decl_stmt|;
comment|// BIOS internal reserved space to optimize code size, updated by the compiler, shouldn't be modified manually!!
comment|// Total memory size in unit of 16MB for CONFIG_MEMSIZE - bit[23:0] zeros
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
comment|//compare with V3, we flat the struct by merging ATOM_MEMORY_FORMAT (as is) into V4 as the same level
name|USHORT
name|usEMRS2Value
decl_stmt|;
comment|// EMRS2 Value is used for GDDR2 and GDDR4 memory type
name|USHORT
name|usEMRS3Value
decl_stmt|;
comment|// EMRS3 Value is used for GDDR2 and GDDR4 memory type
name|UCHAR
name|ucMemoryVenderID
decl_stmt|;
comment|// Predefined, If not predefined, vendor detection table gets executed
name|UCHAR
name|ucRefreshRateFactor
decl_stmt|;
comment|// [1:0]=RefreshFactor (00=8ms, 01=16ms, 10=32ms,11=64ms)
name|UCHAR
name|ucFIFODepth
decl_stmt|;
comment|// FIFO depth supposes to be detected during vendor detection, but if we dont do vendor detection we have to hardcode FIFO Depth
name|UCHAR
name|ucCDR_Bandwidth
decl_stmt|;
comment|// [0:3]=Read CDR bandwidth, [4:7] - Write CDR Bandwidth
name|ATOM_MEMORY_TIMING_FORMAT_V1
name|asMemTiming
index|[
literal|5
index|]
decl_stmt|;
comment|//Memory Timing block sort from lower clock to higher clock
block|}
name|ATOM_VRAM_MODULE_V5
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_MODULE_V6
block|{
name|ULONG
name|ulChannelMapCfg
decl_stmt|;
comment|// board dependent parameter: Channel combination
name|USHORT
name|usModuleSize
decl_stmt|;
comment|// size of ATOM_VRAM_MODULE_V4, make it easy for VBIOS to look for next entry of VRAM_MODULE
name|USHORT
name|usPrivateReserved
decl_stmt|;
comment|// BIOS internal reserved space to optimize code size, updated by the compiler, shouldn't be modified manually!!
comment|// MC_ARB_RAMCFG (includes NOOFBANK,NOOFRANKS,NOOFROWS,NOOFCOLS)
name|USHORT
name|usReserved
decl_stmt|;
name|UCHAR
name|ucExtMemoryID
decl_stmt|;
comment|// An external indicator (by hardcode, callback or pin) to tell what is the current memory module
name|UCHAR
name|ucMemoryType
decl_stmt|;
comment|// [7:4]=0x1:DDR1;=0x2:DDR2;=0x3:DDR3;=0x4:DDR4; 0x5:DDR5 [3:0] - Must be 0x0 for now;
name|UCHAR
name|ucChannelNum
decl_stmt|;
comment|// Number of channels present in this module config
name|UCHAR
name|ucChannelWidth
decl_stmt|;
comment|// 0 - 32 bits; 1 - 64 bits
name|UCHAR
name|ucDensity
decl_stmt|;
comment|// _8Mx32, _16Mx32, _16Mx16, _32Mx16
name|UCHAR
name|ucFlag
decl_stmt|;
comment|// To enable/disable functionalities based on memory type
name|UCHAR
name|ucMisc
decl_stmt|;
comment|// bit0: 0 - single rank; 1 - dual rank;   bit2: 0 - burstlength 4, 1 - burstlength 8
name|UCHAR
name|ucVREFI
decl_stmt|;
comment|// board dependent parameter
name|UCHAR
name|ucNPL_RT
decl_stmt|;
comment|// board dependent parameter:NPL round trip delay, used for calculate memory timing parameters
name|UCHAR
name|ucPreamble
decl_stmt|;
comment|// [7:4] Write Preamble, [3:0] Read Preamble
name|UCHAR
name|ucMemorySize
decl_stmt|;
comment|// BIOS internal reserved space to optimize code size, updated by the compiler, shouldn't be modified manually!!
comment|// Total memory size in unit of 16MB for CONFIG_MEMSIZE - bit[23:0] zeros
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
comment|//compare with V3, we flat the struct by merging ATOM_MEMORY_FORMAT (as is) into V4 as the same level
name|USHORT
name|usEMRS2Value
decl_stmt|;
comment|// EMRS2 Value is used for GDDR2 and GDDR4 memory type
name|USHORT
name|usEMRS3Value
decl_stmt|;
comment|// EMRS3 Value is used for GDDR2 and GDDR4 memory type
name|UCHAR
name|ucMemoryVenderID
decl_stmt|;
comment|// Predefined, If not predefined, vendor detection table gets executed
name|UCHAR
name|ucRefreshRateFactor
decl_stmt|;
comment|// [1:0]=RefreshFactor (00=8ms, 01=16ms, 10=32ms,11=64ms)
name|UCHAR
name|ucFIFODepth
decl_stmt|;
comment|// FIFO depth supposes to be detected during vendor detection, but if we dont do vendor detection we have to hardcode FIFO Depth
name|UCHAR
name|ucCDR_Bandwidth
decl_stmt|;
comment|// [0:3]=Read CDR bandwidth, [4:7] - Write CDR Bandwidth
name|ATOM_MEMORY_TIMING_FORMAT_V2
name|asMemTiming
index|[
literal|5
index|]
decl_stmt|;
comment|//Memory Timing block sort from lower clock to higher clock
block|}
name|ATOM_VRAM_MODULE_V6
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_MODULE_V7
block|{
comment|// Design Specific Values
name|ULONG
name|ulChannelMapCfg
decl_stmt|;
comment|// mmMC_SHARED_CHREMAP
name|USHORT
name|usModuleSize
decl_stmt|;
comment|// Size of ATOM_VRAM_MODULE_V7
name|USHORT
name|usPrivateReserved
decl_stmt|;
comment|// MC_ARB_RAMCFG (includes NOOFBANK,NOOFRANKS,NOOFROWS,NOOFCOLS)
name|USHORT
name|usEnableChannels
decl_stmt|;
comment|// bit vector which indicate which channels are enabled
name|UCHAR
name|ucExtMemoryID
decl_stmt|;
comment|// Current memory module ID
name|UCHAR
name|ucMemoryType
decl_stmt|;
comment|// MEM_TYPE_DDR2/DDR3/GDDR3/GDDR5
name|UCHAR
name|ucChannelNum
decl_stmt|;
comment|// Number of mem. channels supported in this module
name|UCHAR
name|ucChannelWidth
decl_stmt|;
comment|// CHANNEL_16BIT/CHANNEL_32BIT/CHANNEL_64BIT
name|UCHAR
name|ucDensity
decl_stmt|;
comment|// _8Mx32, _16Mx32, _16Mx16, _32Mx16
name|UCHAR
name|ucReserve
decl_stmt|;
comment|// Former container for Mx_FLAGS like DBI_AC_MODE_ENABLE_ASIC for GDDR4. Not used now.
name|UCHAR
name|ucMisc
decl_stmt|;
comment|// RANK_OF_THISMEMORY etc.
name|UCHAR
name|ucVREFI
decl_stmt|;
comment|// Not used.
name|UCHAR
name|ucNPL_RT
decl_stmt|;
comment|// Round trip delay (MC_SEQ_CAS_TIMING [28:24]:TCL=CL+NPL_RT-2). Always 2.
name|UCHAR
name|ucPreamble
decl_stmt|;
comment|// [7:4] Write Preamble, [3:0] Read Preamble
name|UCHAR
name|ucMemorySize
decl_stmt|;
comment|// Total memory size in unit of 16MB for CONFIG_MEMSIZE - bit[23:0] zeros
name|USHORT
name|usSEQSettingOffset
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
comment|// Memory Module specific values
name|USHORT
name|usEMRS2Value
decl_stmt|;
comment|// EMRS2/MR2 Value.
name|USHORT
name|usEMRS3Value
decl_stmt|;
comment|// EMRS3/MR3 Value.
name|UCHAR
name|ucMemoryVenderID
decl_stmt|;
comment|// [7:4] Revision, [3:0] Vendor code
name|UCHAR
name|ucRefreshRateFactor
decl_stmt|;
comment|// [1:0]=RefreshFactor (00=8ms, 01=16ms, 10=32ms,11=64ms)
name|UCHAR
name|ucFIFODepth
decl_stmt|;
comment|// FIFO depth can be detected during vendor detection, here is hardcoded per memory
name|UCHAR
name|ucCDR_Bandwidth
decl_stmt|;
comment|// [0:3]=Read CDR bandwidth, [4:7] - Write CDR Bandwidth
name|char
name|strMemPNString
index|[
literal|20
index|]
decl_stmt|;
comment|// part number end with '0'.
block|}
name|ATOM_VRAM_MODULE_V7
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_INFO_V2
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|ucNumOfVRAMModule
decl_stmt|;
name|ATOM_VRAM_MODULE
name|aVramInfo
index|[
name|ATOM_MAX_NUMBER_OF_VRAM_MODULE
index|]
decl_stmt|;
comment|// just for allocation, real number of blocks is in ucNumOfVRAMModule;
block|}
name|ATOM_VRAM_INFO_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_INFO_V3
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usMemAdjustTblOffset
decl_stmt|;
comment|// offset of ATOM_INIT_REG_BLOCK structure for memory vendor specific MC adjust setting
name|USHORT
name|usMemClkPatchTblOffset
decl_stmt|;
comment|//	offset of ATOM_INIT_REG_BLOCK structure for memory clock specific MC setting
name|USHORT
name|usRerseved
decl_stmt|;
name|UCHAR
name|aVID_PinsShift
index|[
literal|9
index|]
decl_stmt|;
comment|// 8 bit strap maximum+terminator
name|UCHAR
name|ucNumOfVRAMModule
decl_stmt|;
name|ATOM_VRAM_MODULE
name|aVramInfo
index|[
name|ATOM_MAX_NUMBER_OF_VRAM_MODULE
index|]
decl_stmt|;
comment|// just for allocation, real number of blocks is in ucNumOfVRAMModule;
name|ATOM_INIT_REG_BLOCK
name|asMemPatch
decl_stmt|;
comment|// for allocation
comment|//	ATOM_INIT_REG_BLOCK				 aMemAdjust;
block|}
name|ATOM_VRAM_INFO_V3
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_VRAM_INFO_LAST
value|ATOM_VRAM_INFO_V3
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_INFO_V4
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usMemAdjustTblOffset
decl_stmt|;
comment|// offset of ATOM_INIT_REG_BLOCK structure for memory vendor specific MC adjust setting
name|USHORT
name|usMemClkPatchTblOffset
decl_stmt|;
comment|//	offset of ATOM_INIT_REG_BLOCK structure for memory clock specific MC setting
name|USHORT
name|usRerseved
decl_stmt|;
name|UCHAR
name|ucMemDQ7_0ByteRemap
decl_stmt|;
comment|// DQ line byte remap, =0: Memory Data line BYTE0, =1: BYTE1, =2: BYTE2, =3: BYTE3
name|ULONG
name|ulMemDQ7_0BitRemap
decl_stmt|;
comment|// each DQ line ( 7~0) use 3bits, like: DQ0=Bit[2:0], DQ1:[5:3], ... DQ7:[23:21]
name|UCHAR
name|ucReservde
index|[
literal|4
index|]
decl_stmt|;
name|UCHAR
name|ucNumOfVRAMModule
decl_stmt|;
name|ATOM_VRAM_MODULE_V4
name|aVramInfo
index|[
name|ATOM_MAX_NUMBER_OF_VRAM_MODULE
index|]
decl_stmt|;
comment|// just for allocation, real number of blocks is in ucNumOfVRAMModule;
name|ATOM_INIT_REG_BLOCK
name|asMemPatch
decl_stmt|;
comment|// for allocation
comment|//	ATOM_INIT_REG_BLOCK				 aMemAdjust;
block|}
name|ATOM_VRAM_INFO_V4
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_INFO_HEADER_V2_1
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usMemAdjustTblOffset
decl_stmt|;
comment|// offset of ATOM_INIT_REG_BLOCK structure for memory vendor specific MC adjust setting
name|USHORT
name|usMemClkPatchTblOffset
decl_stmt|;
comment|//	offset of ATOM_INIT_REG_BLOCK structure for memory clock specific MC setting
name|USHORT
name|usPerBytePresetOffset
decl_stmt|;
comment|// offset of ATOM_INIT_REG_BLOCK structure for Per Byte Offset Preset Settings
name|USHORT
name|usReserved
index|[
literal|3
index|]
decl_stmt|;
name|UCHAR
name|ucNumOfVRAMModule
decl_stmt|;
comment|// indicate number of VRAM module
name|UCHAR
name|ucMemoryClkPatchTblVer
decl_stmt|;
comment|// version of memory AC timing register list
name|UCHAR
name|ucVramModuleVer
decl_stmt|;
comment|// indicate ATOM_VRAM_MODUE version
name|UCHAR
name|ucReserved
decl_stmt|;
name|ATOM_VRAM_MODULE_V7
name|aVramInfo
index|[
name|ATOM_MAX_NUMBER_OF_VRAM_MODULE
index|]
decl_stmt|;
comment|// just for allocation, real number of blocks is in ucNumOfVRAMModule;
block|}
name|ATOM_VRAM_INFO_HEADER_V2_1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_VRAM_GPIO_DETECTION_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|aVID_PinsShift
index|[
literal|9
index|]
decl_stmt|;
comment|//8 bit strap maximum+terminator
block|}
name|ATOM_VRAM_GPIO_DETECTION_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MEMORY_TRAINING_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|ucTrainingLoop
decl_stmt|;
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
name|ATOM_INIT_REG_BLOCK
name|asMemTrainingSetting
decl_stmt|;
block|}
name|ATOM_MEMORY_TRAINING_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|SW_I2C_CNTL_DATA_PARAMETERS
block|{
name|UCHAR
name|ucControl
decl_stmt|;
name|UCHAR
name|ucData
decl_stmt|;
name|UCHAR
name|ucSatus
decl_stmt|;
name|UCHAR
name|ucTemp
decl_stmt|;
block|}
name|SW_I2C_CNTL_DATA_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SW_I2C_CNTL_DATA_PS_ALLOCATION
value|SW_I2C_CNTL_DATA_PARAMETERS
end_define

begin_typedef
typedef|typedef
struct|struct
name|_SW_I2C_IO_DATA_PARAMETERS
block|{
name|USHORT
name|GPIO_Info
decl_stmt|;
name|UCHAR
name|ucAct
decl_stmt|;
name|UCHAR
name|ucData
decl_stmt|;
block|}
name|SW_I2C_IO_DATA_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SW_I2C_IO_DATA_PS_ALLOCATION
value|SW_I2C_IO_DATA_PARAMETERS
end_define

begin_comment
comment|/****************************SW I2C CNTL DEFINITIONS**********************/
end_comment

begin_define
define|#
directive|define
name|SW_I2C_IO_RESET
value|0
end_define

begin_define
define|#
directive|define
name|SW_I2C_IO_GET
value|1
end_define

begin_define
define|#
directive|define
name|SW_I2C_IO_DRIVE
value|2
end_define

begin_define
define|#
directive|define
name|SW_I2C_IO_SET
value|3
end_define

begin_define
define|#
directive|define
name|SW_I2C_IO_START
value|4
end_define

begin_define
define|#
directive|define
name|SW_I2C_IO_CLOCK
value|0
end_define

begin_define
define|#
directive|define
name|SW_I2C_IO_DATA
value|0x80
end_define

begin_define
define|#
directive|define
name|SW_I2C_IO_ZERO
value|0
end_define

begin_define
define|#
directive|define
name|SW_I2C_IO_ONE
value|0x100
end_define

begin_define
define|#
directive|define
name|SW_I2C_CNTL_READ
value|0
end_define

begin_define
define|#
directive|define
name|SW_I2C_CNTL_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|SW_I2C_CNTL_START
value|2
end_define

begin_define
define|#
directive|define
name|SW_I2C_CNTL_STOP
value|3
end_define

begin_define
define|#
directive|define
name|SW_I2C_CNTL_OPEN
value|4
end_define

begin_define
define|#
directive|define
name|SW_I2C_CNTL_CLOSE
value|5
end_define

begin_define
define|#
directive|define
name|SW_I2C_CNTL_WRITE1BIT
value|6
end_define

begin_comment
comment|//==============================VESA definition Portion===============================
end_comment

begin_define
define|#
directive|define
name|VESA_OEM_PRODUCT_REV
value|"01.00"
end_define

begin_define
define|#
directive|define
name|VESA_MODE_ATTRIBUTE_MODE_SUPPORT
value|0xBB
end_define

begin_comment
comment|//refer to VBE spec p.32, no TTY support
end_comment

begin_define
define|#
directive|define
name|VESA_MODE_WIN_ATTRIBUTE
value|7
end_define

begin_define
define|#
directive|define
name|VESA_WIN_SIZE
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PTR_32_BIT_STRUCTURE
block|{
name|USHORT
name|Offset16
decl_stmt|;
name|USHORT
name|Segment16
decl_stmt|;
block|}
name|PTR_32_BIT_STRUCTURE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_PTR_32_BIT_UNION
block|{
name|PTR_32_BIT_STRUCTURE
name|SegmentOffset
decl_stmt|;
name|ULONG
name|Ptr32_Bit
decl_stmt|;
block|}
name|PTR_32_BIT_UNION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_VBE_1_2_INFO_BLOCK_UPDATABLE
block|{
name|UCHAR
name|VbeSignature
index|[
literal|4
index|]
decl_stmt|;
name|USHORT
name|VbeVersion
decl_stmt|;
name|PTR_32_BIT_UNION
name|OemStringPtr
decl_stmt|;
name|UCHAR
name|Capabilities
index|[
literal|4
index|]
decl_stmt|;
name|PTR_32_BIT_UNION
name|VideoModePtr
decl_stmt|;
name|USHORT
name|TotalMemory
decl_stmt|;
block|}
name|VBE_1_2_INFO_BLOCK_UPDATABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_VBE_2_0_INFO_BLOCK_UPDATABLE
block|{
name|VBE_1_2_INFO_BLOCK_UPDATABLE
name|CommonBlock
decl_stmt|;
name|USHORT
name|OemSoftRev
decl_stmt|;
name|PTR_32_BIT_UNION
name|OemVendorNamePtr
decl_stmt|;
name|PTR_32_BIT_UNION
name|OemProductNamePtr
decl_stmt|;
name|PTR_32_BIT_UNION
name|OemProductRevPtr
decl_stmt|;
block|}
name|VBE_2_0_INFO_BLOCK_UPDATABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_VBE_VERSION_UNION
block|{
name|VBE_2_0_INFO_BLOCK_UPDATABLE
name|VBE_2_0_InfoBlock
decl_stmt|;
name|VBE_1_2_INFO_BLOCK_UPDATABLE
name|VBE_1_2_InfoBlock
decl_stmt|;
block|}
name|VBE_VERSION_UNION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_VBE_INFO_BLOCK
block|{
name|VBE_VERSION_UNION
name|UpdatableVBE_Info
decl_stmt|;
name|UCHAR
name|Reserved
index|[
literal|222
index|]
decl_stmt|;
name|UCHAR
name|OemData
index|[
literal|256
index|]
decl_stmt|;
block|}
name|VBE_INFO_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_VBE_FP_INFO
block|{
name|USHORT
name|HSize
decl_stmt|;
name|USHORT
name|VSize
decl_stmt|;
name|USHORT
name|FPType
decl_stmt|;
name|UCHAR
name|RedBPP
decl_stmt|;
name|UCHAR
name|GreenBPP
decl_stmt|;
name|UCHAR
name|BlueBPP
decl_stmt|;
name|UCHAR
name|ReservedBPP
decl_stmt|;
name|ULONG
name|RsvdOffScrnMemSize
decl_stmt|;
name|ULONG
name|RsvdOffScrnMEmPtr
decl_stmt|;
name|UCHAR
name|Reserved
index|[
literal|14
index|]
decl_stmt|;
block|}
name|VBE_FP_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_VESA_MODE_INFO_BLOCK
block|{
comment|// Mandatory information for all VBE revisions
name|USHORT
name|ModeAttributes
decl_stmt|;
comment|//			dw	?	; mode attributes
name|UCHAR
name|WinAAttributes
decl_stmt|;
comment|//			db	?	; window A attributes
name|UCHAR
name|WinBAttributes
decl_stmt|;
comment|//			db	?	; window B attributes
name|USHORT
name|WinGranularity
decl_stmt|;
comment|//			dw	?	; window granularity
name|USHORT
name|WinSize
decl_stmt|;
comment|//			dw	?	; window size
name|USHORT
name|WinASegment
decl_stmt|;
comment|//			dw	?	; window A start segment
name|USHORT
name|WinBSegment
decl_stmt|;
comment|//			dw	?	; window B start segment
name|ULONG
name|WinFuncPtr
decl_stmt|;
comment|//			dd	?	; real mode pointer to window function
name|USHORT
name|BytesPerScanLine
decl_stmt|;
comment|//			dw	?	; bytes per scan line
comment|//; Mandatory information for VBE 1.2 and above
name|USHORT
name|XResolution
decl_stmt|;
comment|//			dw	?	; horizontal resolution in pixels or characters
name|USHORT
name|YResolution
decl_stmt|;
comment|//			dw	?	; vertical resolution in pixels or characters
name|UCHAR
name|XCharSize
decl_stmt|;
comment|//			db	?	; character cell width in pixels
name|UCHAR
name|YCharSize
decl_stmt|;
comment|//			db	?	; character cell height in pixels
name|UCHAR
name|NumberOfPlanes
decl_stmt|;
comment|//			db	?	; number of memory planes
name|UCHAR
name|BitsPerPixel
decl_stmt|;
comment|//			db	?	; bits per pixel
name|UCHAR
name|NumberOfBanks
decl_stmt|;
comment|//			db	?	; number of banks
name|UCHAR
name|MemoryModel
decl_stmt|;
comment|//			db	?	; memory model type
name|UCHAR
name|BankSize
decl_stmt|;
comment|//			db	?	; bank size in KB
name|UCHAR
name|NumberOfImagePages
decl_stmt|;
comment|//		  db	?	; number of images
name|UCHAR
name|ReservedForPageFunction
decl_stmt|;
comment|//db	1	; reserved for page function
comment|//; Direct Color fields(required for direct/6 and YUV/7 memory models)
name|UCHAR
name|RedMaskSize
decl_stmt|;
comment|//		db	?	; size of direct color red mask in bits
name|UCHAR
name|RedFieldPosition
decl_stmt|;
comment|//		db	?	; bit position of lsb of red mask
name|UCHAR
name|GreenMaskSize
decl_stmt|;
comment|//		db	?	; size of direct color green mask in bits
name|UCHAR
name|GreenFieldPosition
decl_stmt|;
comment|//		db	?	; bit position of lsb of green mask
name|UCHAR
name|BlueMaskSize
decl_stmt|;
comment|//		db	?	; size of direct color blue mask in bits
name|UCHAR
name|BlueFieldPosition
decl_stmt|;
comment|//		db	?	; bit position of lsb of blue mask
name|UCHAR
name|RsvdMaskSize
decl_stmt|;
comment|//		db	?	; size of direct color reserved mask in bits
name|UCHAR
name|RsvdFieldPosition
decl_stmt|;
comment|//		db	?	; bit position of lsb of reserved mask
name|UCHAR
name|DirectColorModeInfo
decl_stmt|;
comment|//		db	?	; direct color mode attributes
comment|//; Mandatory information for VBE 2.0 and above
name|ULONG
name|PhysBasePtr
decl_stmt|;
comment|//		dd	?	; physical address for flat memory frame buffer
name|ULONG
name|Reserved_1
decl_stmt|;
comment|//		dd	0	; reserved - always set to 0
name|USHORT
name|Reserved_2
decl_stmt|;
comment|//	  dw	0	; reserved - always set to 0
comment|//; Mandatory information for VBE 3.0 and above
name|USHORT
name|LinBytesPerScanLine
decl_stmt|;
comment|//	dw	?	; bytes per scan line for linear modes
name|UCHAR
name|BnkNumberOfImagePages
decl_stmt|;
comment|//	db	?	; number of images for banked modes
name|UCHAR
name|LinNumberOfImagPages
decl_stmt|;
comment|//	db	?	; number of images for linear modes
name|UCHAR
name|LinRedMaskSize
decl_stmt|;
comment|//	db	?	; size of direct color red mask(linear modes)
name|UCHAR
name|LinRedFieldPosition
decl_stmt|;
comment|//	db	?	; bit position of lsb of red mask(linear modes)
name|UCHAR
name|LinGreenMaskSize
decl_stmt|;
comment|//	db	?	; size of direct color green mask(linear modes)
name|UCHAR
name|LinGreenFieldPosition
decl_stmt|;
comment|//	db	?	; bit position of lsb of green mask(linear modes)
name|UCHAR
name|LinBlueMaskSize
decl_stmt|;
comment|//	db	?	; size of direct color blue mask(linear modes)
name|UCHAR
name|LinBlueFieldPosition
decl_stmt|;
comment|//	db	?	; bit position of lsb of blue mask(linear modes)
name|UCHAR
name|LinRsvdMaskSize
decl_stmt|;
comment|//	db	?	; size of direct color reserved mask(linear modes)
name|UCHAR
name|LinRsvdFieldPosition
decl_stmt|;
comment|//	db	?	; bit position of lsb of reserved mask(linear modes)
name|ULONG
name|MaxPixelClock
decl_stmt|;
comment|//	dd	?	; maximum pixel clock(in Hz) for graphics mode
name|UCHAR
name|Reserved
decl_stmt|;
comment|//	db	190 dup (0)
block|}
name|VESA_MODE_INFO_BLOCK
typedef|;
end_typedef

begin_comment
comment|// BIOS function CALLS
end_comment

begin_define
define|#
directive|define
name|ATOM_BIOS_EXTENDED_FUNCTION_CODE
value|0xA0
end_define

begin_comment
comment|// ATI Extended Function code
end_comment

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_COP_MODE
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_SHORT_QUERY1
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_SHORT_QUERY2
value|0x05
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_SHORT_QUERY3
value|0x06
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_GET_DDC
value|0x0B
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_ASIC_DSTATE
value|0x0E
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_DEBUG_PLAY
value|0x0F
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_STV_STD
value|0x16
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_DEVICE_DET
value|0x17
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_DEVICE_SWITCH
value|0x18
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_PANEL_CONTROL
value|0x82
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_OLD_DEVICE_DET
value|0x83
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_OLD_DEVICE_SWITCH
value|0x84
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_HW_ICON
value|0x8A
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_SET_CMOS
value|0x8B
end_define

begin_define
define|#
directive|define
name|SUB_FUNCTION_UPDATE_DISPLAY_INFO
value|0x8000
end_define

begin_comment
comment|// Sub function 80
end_comment

begin_define
define|#
directive|define
name|SUB_FUNCTION_UPDATE_EXPANSION_INFO
value|0x8100
end_define

begin_comment
comment|// Sub function 80
end_comment

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_DISPLAY_INFO
value|0x8D
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_DEVICE_ON_OFF
value|0x8E
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_VIDEO_STATE
value|0x8F
end_define

begin_define
define|#
directive|define
name|ATOM_SUB_FUNCTION_GET_CRITICAL_STATE
value|0x0300
end_define

begin_comment
comment|// Sub function 03
end_comment

begin_define
define|#
directive|define
name|ATOM_SUB_FUNCTION_GET_LIDSTATE
value|0x0700
end_define

begin_comment
comment|// Sub function 7
end_comment

begin_define
define|#
directive|define
name|ATOM_SUB_FUNCTION_THERMAL_STATE_NOTICE
value|0x1400
end_define

begin_comment
comment|// Notify caller the current thermal state
end_comment

begin_define
define|#
directive|define
name|ATOM_SUB_FUNCTION_CRITICAL_STATE_NOTICE
value|0x8300
end_define

begin_comment
comment|// Notify caller the current critical state
end_comment

begin_define
define|#
directive|define
name|ATOM_SUB_FUNCTION_SET_LIDSTATE
value|0x8500
end_define

begin_comment
comment|// Sub function 85
end_comment

begin_define
define|#
directive|define
name|ATOM_SUB_FUNCTION_GET_REQ_DISPLAY_FROM_SBIOS_MODE
value|0x8900
end_define

begin_comment
comment|// Sub function 89
end_comment

begin_define
define|#
directive|define
name|ATOM_SUB_FUNCTION_INFORM_ADC_SUPPORT
value|0x9400
end_define

begin_comment
comment|// Notify caller that ADC is supported
end_comment

begin_define
define|#
directive|define
name|ATOM_BIOS_FUNCTION_VESA_DPMS
value|0x4F10
end_define

begin_comment
comment|// Set DPMS
end_comment

begin_define
define|#
directive|define
name|ATOM_SUB_FUNCTION_SET_DPMS
value|0x0001
end_define

begin_comment
comment|// BL: Sub function 01
end_comment

begin_define
define|#
directive|define
name|ATOM_SUB_FUNCTION_GET_DPMS
value|0x0002
end_define

begin_comment
comment|// BL: Sub function 02
end_comment

begin_define
define|#
directive|define
name|ATOM_PARAMETER_VESA_DPMS_ON
value|0x0000
end_define

begin_comment
comment|// BH Parameter for DPMS ON.
end_comment

begin_define
define|#
directive|define
name|ATOM_PARAMETER_VESA_DPMS_STANDBY
value|0x0100
end_define

begin_comment
comment|// BH Parameter for DPMS STANDBY
end_comment

begin_define
define|#
directive|define
name|ATOM_PARAMETER_VESA_DPMS_SUSPEND
value|0x0200
end_define

begin_comment
comment|// BH Parameter for DPMS SUSPEND
end_comment

begin_define
define|#
directive|define
name|ATOM_PARAMETER_VESA_DPMS_OFF
value|0x0400
end_define

begin_comment
comment|// BH Parameter for DPMS OFF
end_comment

begin_define
define|#
directive|define
name|ATOM_PARAMETER_VESA_DPMS_REDUCE_ON
value|0x0800
end_define

begin_comment
comment|// BH Parameter for DPMS REDUCE ON (NOT SUPPORTED)
end_comment

begin_define
define|#
directive|define
name|ATOM_BIOS_RETURN_CODE_MASK
value|0x0000FF00L
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_REG_HIGH_MASK
value|0x0000FF00L
end_define

begin_define
define|#
directive|define
name|ATOM_BIOS_REG_LOW_MASK
value|0x000000FFL
end_define

begin_comment
comment|// structure used for VBIOS only
end_comment

begin_comment
comment|//DispOutInfoTable
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ASIC_TRANSMITTER_INFO
block|{
name|USHORT
name|usTransmitterObjId
decl_stmt|;
name|USHORT
name|usSupportDevice
decl_stmt|;
name|UCHAR
name|ucTransmitterCmdTblId
decl_stmt|;
name|UCHAR
name|ucConfig
decl_stmt|;
name|UCHAR
name|ucEncoderID
decl_stmt|;
comment|//available 1st encoder ( default )
name|UCHAR
name|ucOptionEncoderID
decl_stmt|;
comment|//available 2nd encoder ( optional )
name|UCHAR
name|uc2ndEncoderID
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|ASIC_TRANSMITTER_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ASIC_TRANSMITTER_INFO_CONFIG__DVO_SDR_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|ASIC_TRANSMITTER_INFO_CONFIG__COHERENT_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|ASIC_TRANSMITTER_INFO_CONFIG__ENCODEROBJ_ID_MASK
value|0xc4
end_define

begin_define
define|#
directive|define
name|ASIC_TRANSMITTER_INFO_CONFIG__ENCODER_A
value|0x00
end_define

begin_define
define|#
directive|define
name|ASIC_TRANSMITTER_INFO_CONFIG__ENCODER_B
value|0x04
end_define

begin_define
define|#
directive|define
name|ASIC_TRANSMITTER_INFO_CONFIG__ENCODER_C
value|0x40
end_define

begin_define
define|#
directive|define
name|ASIC_TRANSMITTER_INFO_CONFIG__ENCODER_D
value|0x44
end_define

begin_define
define|#
directive|define
name|ASIC_TRANSMITTER_INFO_CONFIG__ENCODER_E
value|0x80
end_define

begin_define
define|#
directive|define
name|ASIC_TRANSMITTER_INFO_CONFIG__ENCODER_F
value|0x84
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ASIC_ENCODER_INFO
block|{
name|UCHAR
name|ucEncoderID
decl_stmt|;
name|UCHAR
name|ucEncoderConfig
decl_stmt|;
name|USHORT
name|usEncoderCmdTblId
decl_stmt|;
block|}
name|ASIC_ENCODER_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DISP_OUT_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|ptrTransmitterInfo
decl_stmt|;
name|USHORT
name|ptrEncoderInfo
decl_stmt|;
name|ASIC_TRANSMITTER_INFO
name|asTransmitterInfo
index|[
literal|1
index|]
decl_stmt|;
name|ASIC_ENCODER_INFO
name|asEncoderInfo
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_DISP_OUT_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DISP_OUT_INFO_V2
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|ptrTransmitterInfo
decl_stmt|;
name|USHORT
name|ptrEncoderInfo
decl_stmt|;
name|USHORT
name|ptrMainCallParserFar
decl_stmt|;
comment|// direct address of main parser call in VBIOS binary.
name|ASIC_TRANSMITTER_INFO
name|asTransmitterInfo
index|[
literal|1
index|]
decl_stmt|;
name|ASIC_ENCODER_INFO
name|asEncoderInfo
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_DISP_OUT_INFO_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DISP_CLOCK_ID
block|{
name|UCHAR
name|ucPpllId
decl_stmt|;
name|UCHAR
name|ucPpllAttribute
decl_stmt|;
block|}
name|ATOM_DISP_CLOCK_ID
typedef|;
end_typedef

begin_comment
comment|// ucPpllAttribute
end_comment

begin_define
define|#
directive|define
name|CLOCK_SOURCE_SHAREABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|CLOCK_SOURCE_DP_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|CLOCK_SOURCE_NONE_DP_MODE
value|0x04
end_define

begin_comment
comment|//DispOutInfoTable
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ASIC_TRANSMITTER_INFO_V2
block|{
name|USHORT
name|usTransmitterObjId
decl_stmt|;
name|USHORT
name|usDispClkIdOffset
decl_stmt|;
comment|// point to clock source id list supported by Encoder Object
name|UCHAR
name|ucTransmitterCmdTblId
decl_stmt|;
name|UCHAR
name|ucConfig
decl_stmt|;
name|UCHAR
name|ucEncoderID
decl_stmt|;
comment|// available 1st encoder ( default )
name|UCHAR
name|ucOptionEncoderID
decl_stmt|;
comment|// available 2nd encoder ( optional )
name|UCHAR
name|uc2ndEncoderID
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|ASIC_TRANSMITTER_INFO_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DISP_OUT_INFO_V3
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|ptrTransmitterInfo
decl_stmt|;
name|USHORT
name|ptrEncoderInfo
decl_stmt|;
name|USHORT
name|ptrMainCallParserFar
decl_stmt|;
comment|// direct address of main parser call in VBIOS binary.
name|USHORT
name|usReserved
decl_stmt|;
name|UCHAR
name|ucDCERevision
decl_stmt|;
name|UCHAR
name|ucMaxDispEngineNum
decl_stmt|;
name|UCHAR
name|ucMaxActiveDispEngineNum
decl_stmt|;
name|UCHAR
name|ucMaxPPLLNum
decl_stmt|;
name|UCHAR
name|ucCoreRefClkSource
decl_stmt|;
comment|// value of CORE_REF_CLK_SOURCE
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
name|ASIC_TRANSMITTER_INFO_V2
name|asTransmitterInfo
index|[
literal|1
index|]
decl_stmt|;
comment|// for alligment only
block|}
name|ATOM_DISP_OUT_INFO_V3
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|CORE_REF_CLK_SOURCE
block|{
name|CLOCK_SRC_XTALIN
init|=
literal|0
block|,
name|CLOCK_SRC_XO_IN
init|=
literal|1
block|,
name|CLOCK_SRC_XO_IN2
init|=
literal|2
block|, }
name|CORE_REF_CLK_SOURCE
typedef|;
end_typedef

begin_comment
comment|// DispDevicePriorityInfo
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DISPLAY_DEVICE_PRIORITY_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|asDevicePriority
index|[
literal|16
index|]
decl_stmt|;
block|}
name|ATOM_DISPLAY_DEVICE_PRIORITY_INFO
typedef|;
end_typedef

begin_comment
comment|//ProcessAuxChannelTransactionTable
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PROCESS_AUX_CHANNEL_TRANSACTION_PARAMETERS
block|{
name|USHORT
name|lpAuxRequest
decl_stmt|;
name|USHORT
name|lpDataOut
decl_stmt|;
name|UCHAR
name|ucChannelID
decl_stmt|;
union|union
block|{
name|UCHAR
name|ucReplyStatus
decl_stmt|;
name|UCHAR
name|ucDelay
decl_stmt|;
block|}
union|;
name|UCHAR
name|ucDataOutLen
decl_stmt|;
name|UCHAR
name|ucReserved
decl_stmt|;
block|}
name|PROCESS_AUX_CHANNEL_TRANSACTION_PARAMETERS
typedef|;
end_typedef

begin_comment
comment|//ProcessAuxChannelTransactionTable
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PROCESS_AUX_CHANNEL_TRANSACTION_PARAMETERS_V2
block|{
name|USHORT
name|lpAuxRequest
decl_stmt|;
name|USHORT
name|lpDataOut
decl_stmt|;
name|UCHAR
name|ucChannelID
decl_stmt|;
union|union
block|{
name|UCHAR
name|ucReplyStatus
decl_stmt|;
name|UCHAR
name|ucDelay
decl_stmt|;
block|}
union|;
name|UCHAR
name|ucDataOutLen
decl_stmt|;
name|UCHAR
name|ucHPD_ID
decl_stmt|;
comment|//=0: HPD1, =1: HPD2, =2: HPD3, =3: HPD4, =4: HPD5, =5: HPD6
block|}
name|PROCESS_AUX_CHANNEL_TRANSACTION_PARAMETERS_V2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PROCESS_AUX_CHANNEL_TRANSACTION_PS_ALLOCATION
value|PROCESS_AUX_CHANNEL_TRANSACTION_PARAMETERS
end_define

begin_comment
comment|//GetSinkType
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DP_ENCODER_SERVICE_PARAMETERS
block|{
name|USHORT
name|ucLinkClock
decl_stmt|;
union|union
block|{
name|UCHAR
name|ucConfig
decl_stmt|;
comment|// for DP training command
name|UCHAR
name|ucI2cId
decl_stmt|;
comment|// use for GET_SINK_TYPE command
block|}
union|;
name|UCHAR
name|ucAction
decl_stmt|;
name|UCHAR
name|ucStatus
decl_stmt|;
name|UCHAR
name|ucLaneNum
decl_stmt|;
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|DP_ENCODER_SERVICE_PARAMETERS
typedef|;
end_typedef

begin_comment
comment|// ucAction
end_comment

begin_define
define|#
directive|define
name|ATOM_DP_ACTION_GET_SINK_TYPE
value|0x01
end_define

begin_comment
comment|/* obselete */
end_comment

begin_define
define|#
directive|define
name|ATOM_DP_ACTION_TRAINING_START
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_DP_ACTION_TRAINING_COMPLETE
value|0x03
end_define

begin_define
define|#
directive|define
name|ATOM_DP_ACTION_TRAINING_PATTERN_SEL
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_DP_ACTION_SET_VSWING_PREEMP
value|0x05
end_define

begin_define
define|#
directive|define
name|ATOM_DP_ACTION_GET_VSWING_PREEMP
value|0x06
end_define

begin_define
define|#
directive|define
name|ATOM_DP_ACTION_BLANKING
value|0x07
end_define

begin_comment
comment|// ucConfig
end_comment

begin_define
define|#
directive|define
name|ATOM_DP_CONFIG_ENCODER_SEL_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|ATOM_DP_CONFIG_DIG1_ENCODER
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_DP_CONFIG_DIG2_ENCODER
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_DP_CONFIG_EXTERNAL_ENCODER
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_DP_CONFIG_LINK_SEL_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_DP_CONFIG_LINK_A
value|0x00
end_define

begin_define
define|#
directive|define
name|ATOM_DP_CONFIG_LINK_B
value|0x04
end_define

begin_comment
comment|/* /obselete */
end_comment

begin_define
define|#
directive|define
name|DP_ENCODER_SERVICE_PS_ALLOCATION
value|WRITE_ONE_BYTE_HW_I2C_DATA_PARAMETERS
end_define

begin_typedef
typedef|typedef
struct|struct
name|_DP_ENCODER_SERVICE_PARAMETERS_V2
block|{
name|USHORT
name|usExtEncoderObjId
decl_stmt|;
comment|// External Encoder Object Id, output parameter only, use when ucAction = DP_SERVICE_V2_ACTION_DET_EXT_CONNECTION
name|UCHAR
name|ucAuxId
decl_stmt|;
name|UCHAR
name|ucAction
decl_stmt|;
name|UCHAR
name|ucSinkType
decl_stmt|;
comment|// Iput and Output parameters.
name|UCHAR
name|ucHPDId
decl_stmt|;
comment|// Input parameter, used when ucAction = DP_SERVICE_V2_ACTION_DET_EXT_CONNECTION
name|UCHAR
name|ucReserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|DP_ENCODER_SERVICE_PARAMETERS_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DP_ENCODER_SERVICE_PS_ALLOCATION_V2
block|{
name|DP_ENCODER_SERVICE_PARAMETERS_V2
name|asDPServiceParam
decl_stmt|;
name|PROCESS_AUX_CHANNEL_TRANSACTION_PARAMETERS_V2
name|asAuxParam
decl_stmt|;
block|}
name|DP_ENCODER_SERVICE_PS_ALLOCATION_V2
typedef|;
end_typedef

begin_comment
comment|// ucAction
end_comment

begin_define
define|#
directive|define
name|DP_SERVICE_V2_ACTION_GET_SINK_TYPE
value|0x01
end_define

begin_define
define|#
directive|define
name|DP_SERVICE_V2_ACTION_DET_LCD_CONNECTION
value|0x02
end_define

begin_comment
comment|// DP_TRAINING_TABLE
end_comment

begin_define
define|#
directive|define
name|DPCD_SET_LINKRATE_LANENUM_PATTERN1_TBL_ADDR
value|ATOM_DP_TRAINING_TBL_ADDR
end_define

begin_define
define|#
directive|define
name|DPCD_SET_SS_CNTL_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 8 )
end_define

begin_define
define|#
directive|define
name|DPCD_SET_LANE_VSWING_PREEMP_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 16 )
end_define

begin_define
define|#
directive|define
name|DPCD_SET_TRAINING_PATTERN0_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 24 )
end_define

begin_define
define|#
directive|define
name|DPCD_SET_TRAINING_PATTERN2_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 32)
end_define

begin_define
define|#
directive|define
name|DPCD_GET_LINKRATE_LANENUM_SS_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 40)
end_define

begin_define
define|#
directive|define
name|DPCD_GET_LANE_STATUS_ADJUST_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 48)
end_define

begin_define
define|#
directive|define
name|DP_I2C_AUX_DDC_WRITE_START_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 60)
end_define

begin_define
define|#
directive|define
name|DP_I2C_AUX_DDC_WRITE_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 64)
end_define

begin_define
define|#
directive|define
name|DP_I2C_AUX_DDC_READ_START_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 72)
end_define

begin_define
define|#
directive|define
name|DP_I2C_AUX_DDC_READ_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 76)
end_define

begin_define
define|#
directive|define
name|DP_I2C_AUX_DDC_WRITE_END_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 80)
end_define

begin_define
define|#
directive|define
name|DP_I2C_AUX_DDC_READ_END_TBL_ADDR
value|(ATOM_DP_TRAINING_TBL_ADDR + 84)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PROCESS_I2C_CHANNEL_TRANSACTION_PARAMETERS
block|{
name|UCHAR
name|ucI2CSpeed
decl_stmt|;
union|union
block|{
name|UCHAR
name|ucRegIndex
decl_stmt|;
name|UCHAR
name|ucStatus
decl_stmt|;
block|}
union|;
name|USHORT
name|lpI2CDataOut
decl_stmt|;
name|UCHAR
name|ucFlag
decl_stmt|;
name|UCHAR
name|ucTransBytes
decl_stmt|;
name|UCHAR
name|ucSlaveAddr
decl_stmt|;
name|UCHAR
name|ucLineNumber
decl_stmt|;
block|}
name|PROCESS_I2C_CHANNEL_TRANSACTION_PARAMETERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PROCESS_I2C_CHANNEL_TRANSACTION_PS_ALLOCATION
value|PROCESS_I2C_CHANNEL_TRANSACTION_PARAMETERS
end_define

begin_comment
comment|//ucFlag
end_comment

begin_define
define|#
directive|define
name|HW_I2C_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|HW_I2C_READ
value|0
end_define

begin_define
define|#
directive|define
name|I2C_2BYTE_ADDR
value|0x02
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|// Structures used by HW_Misc_OperationTable
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_HW_MISC_OPERATION_INPUT_PARAMETER_V1_1
block|{
name|UCHAR
name|ucCmd
decl_stmt|;
comment|//  Input: To tell which action to take
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
name|ULONG
name|ulReserved
decl_stmt|;
block|}
name|ATOM_HW_MISC_OPERATION_INPUT_PARAMETER_V1_1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_HW_MISC_OPERATION_OUTPUT_PARAMETER_V1_1
block|{
name|UCHAR
name|ucReturnCode
decl_stmt|;
comment|// Output: Return value base on action was taken
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
name|ULONG
name|ulReserved
decl_stmt|;
block|}
name|ATOM_HW_MISC_OPERATION_OUTPUT_PARAMETER_V1_1
typedef|;
end_typedef

begin_comment
comment|// Actions code
end_comment

begin_define
define|#
directive|define
name|ATOM_GET_SDI_SUPPORT
value|0xF0
end_define

begin_comment
comment|// Return code
end_comment

begin_define
define|#
directive|define
name|ATOM_UNKNOWN_CMD
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_FEATURE_NOT_SUPPORTED
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_FEATURE_SUPPORTED
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_HW_MISC_OPERATION_PS_ALLOCATION
block|{
name|ATOM_HW_MISC_OPERATION_INPUT_PARAMETER_V1_1
name|sInput_Output
decl_stmt|;
name|PROCESS_I2C_CHANNEL_TRANSACTION_PARAMETERS
name|sReserved
decl_stmt|;
block|}
name|ATOM_HW_MISC_OPERATION_PS_ALLOCATION
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SET_HWBLOCK_INSTANCE_PARAMETER_V2
block|{
name|UCHAR
name|ucHWBlkInst
decl_stmt|;
comment|// HW block instance, 0, 1, 2, ...
name|UCHAR
name|ucReserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|SET_HWBLOCK_INSTANCE_PARAMETER_V2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HWBLKINST_INSTANCE_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|HWBLKINST_HWBLK_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|HWBLKINST_HWBLK_SHIFT
value|0x04
end_define

begin_comment
comment|//ucHWBlock
end_comment

begin_define
define|#
directive|define
name|SELECT_DISP_ENGINE
value|0
end_define

begin_define
define|#
directive|define
name|SELECT_DISP_PLL
value|1
end_define

begin_define
define|#
directive|define
name|SELECT_DCIO_UNIPHY_LINK0
value|2
end_define

begin_define
define|#
directive|define
name|SELECT_DCIO_UNIPHY_LINK1
value|3
end_define

begin_define
define|#
directive|define
name|SELECT_DCIO_IMPCAL
value|4
end_define

begin_define
define|#
directive|define
name|SELECT_DCIO_DIG
value|6
end_define

begin_define
define|#
directive|define
name|SELECT_CRTC_PIXEL_RATE
value|7
end_define

begin_define
define|#
directive|define
name|SELECT_VGA_BLK
value|8
end_define

begin_comment
comment|// DIGTransmitterInfoTable structure used to program UNIPHY settings
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DIG_TRANSMITTER_INFO_HEADER_V3_1
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usDPVsPreEmphSettingOffset
decl_stmt|;
comment|// offset of PHY_ANALOG_SETTING_INFO * with DP Voltage Swing and Pre-Emphasis for each Link clock
name|USHORT
name|usPhyAnalogRegListOffset
decl_stmt|;
comment|// offset of CLOCK_CONDITION_REGESTER_INFO* with None-DP mode Analog Setting's register Info
name|USHORT
name|usPhyAnalogSettingOffset
decl_stmt|;
comment|// offset of CLOCK_CONDITION_SETTING_ENTRY* with None-DP mode Analog Setting for each link clock range
name|USHORT
name|usPhyPllRegListOffset
decl_stmt|;
comment|// offset of CLOCK_CONDITION_REGESTER_INFO* with Phy Pll register Info
name|USHORT
name|usPhyPllSettingOffset
decl_stmt|;
comment|// offset of CLOCK_CONDITION_SETTING_ENTRY* with Phy Pll Settings
block|}
name|DIG_TRANSMITTER_INFO_HEADER_V3_1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CLOCK_CONDITION_REGESTER_INFO
block|{
name|USHORT
name|usRegisterIndex
decl_stmt|;
name|UCHAR
name|ucStartBit
decl_stmt|;
name|UCHAR
name|ucEndBit
decl_stmt|;
block|}
name|CLOCK_CONDITION_REGESTER_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CLOCK_CONDITION_SETTING_ENTRY
block|{
name|USHORT
name|usMaxClockFreq
decl_stmt|;
name|UCHAR
name|ucEncodeMode
decl_stmt|;
name|UCHAR
name|ucPhySel
decl_stmt|;
name|ULONG
name|ulAnalogSetting
index|[
literal|1
index|]
decl_stmt|;
block|}
name|CLOCK_CONDITION_SETTING_ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CLOCK_CONDITION_SETTING_INFO
block|{
name|USHORT
name|usEntrySize
decl_stmt|;
name|CLOCK_CONDITION_SETTING_ENTRY
name|asClkCondSettingEntry
index|[
literal|1
index|]
decl_stmt|;
block|}
name|CLOCK_CONDITION_SETTING_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PHY_CONDITION_REG_VAL
block|{
name|ULONG
name|ulCondition
decl_stmt|;
name|ULONG
name|ulRegVal
decl_stmt|;
block|}
name|PHY_CONDITION_REG_VAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PHY_CONDITION_REG_INFO
block|{
name|USHORT
name|usRegIndex
decl_stmt|;
name|USHORT
name|usSize
decl_stmt|;
name|PHY_CONDITION_REG_VAL
name|asRegVal
index|[
literal|1
index|]
decl_stmt|;
block|}
name|PHY_CONDITION_REG_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PHY_ANALOG_SETTING_INFO
block|{
name|UCHAR
name|ucEncodeMode
decl_stmt|;
name|UCHAR
name|ucPhySel
decl_stmt|;
name|USHORT
name|usSize
decl_stmt|;
name|PHY_CONDITION_REG_INFO
name|asAnalogSetting
index|[
literal|1
index|]
decl_stmt|;
block|}
name|PHY_ANALOG_SETTING_INFO
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|//Portion VI: Definitinos for vbios MC scratch registers that driver used
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MC_MISC0__MEMORY_TYPE_MASK
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|MC_MISC0__MEMORY_TYPE__GDDR1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MC_MISC0__MEMORY_TYPE__DDR2
value|0x20000000
end_define

begin_define
define|#
directive|define
name|MC_MISC0__MEMORY_TYPE__GDDR3
value|0x30000000
end_define

begin_define
define|#
directive|define
name|MC_MISC0__MEMORY_TYPE__GDDR4
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MC_MISC0__MEMORY_TYPE__GDDR5
value|0x50000000
end_define

begin_define
define|#
directive|define
name|MC_MISC0__MEMORY_TYPE__DDR3
value|0xB0000000
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|//Portion VI: Definitinos being oboselete
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|//==========================================================================================
end_comment

begin_comment
comment|//Remove the definitions below when driver is ready!
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_DAC_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usMaxFrequency
decl_stmt|;
comment|// in 10kHz unit
name|USHORT
name|usReserved
decl_stmt|;
block|}
name|ATOM_DAC_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_COMPASSIONATE_DATA
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
comment|//==============================  DAC1 portion
name|UCHAR
name|ucDAC1_BG_Adjustment
decl_stmt|;
name|UCHAR
name|ucDAC1_DAC_Adjustment
decl_stmt|;
name|USHORT
name|usDAC1_FORCE_Data
decl_stmt|;
comment|//==============================  DAC2 portion
name|UCHAR
name|ucDAC2_CRT2_BG_Adjustment
decl_stmt|;
name|UCHAR
name|ucDAC2_CRT2_DAC_Adjustment
decl_stmt|;
name|USHORT
name|usDAC2_CRT2_FORCE_Data
decl_stmt|;
name|USHORT
name|usDAC2_CRT2_MUX_RegisterIndex
decl_stmt|;
name|UCHAR
name|ucDAC2_CRT2_MUX_RegisterInfo
decl_stmt|;
comment|//Bit[4:0]=Bit position,Bit[7]=1:Active High;=0 Active Low
name|UCHAR
name|ucDAC2_NTSC_BG_Adjustment
decl_stmt|;
name|UCHAR
name|ucDAC2_NTSC_DAC_Adjustment
decl_stmt|;
name|USHORT
name|usDAC2_TV1_FORCE_Data
decl_stmt|;
name|USHORT
name|usDAC2_TV1_MUX_RegisterIndex
decl_stmt|;
name|UCHAR
name|ucDAC2_TV1_MUX_RegisterInfo
decl_stmt|;
comment|//Bit[4:0]=Bit position,Bit[7]=1:Active High;=0 Active Low
name|UCHAR
name|ucDAC2_CV_BG_Adjustment
decl_stmt|;
name|UCHAR
name|ucDAC2_CV_DAC_Adjustment
decl_stmt|;
name|USHORT
name|usDAC2_CV_FORCE_Data
decl_stmt|;
name|USHORT
name|usDAC2_CV_MUX_RegisterIndex
decl_stmt|;
name|UCHAR
name|ucDAC2_CV_MUX_RegisterInfo
decl_stmt|;
comment|//Bit[4:0]=Bit position,Bit[7]=1:Active High;=0 Active Low
name|UCHAR
name|ucDAC2_PAL_BG_Adjustment
decl_stmt|;
name|UCHAR
name|ucDAC2_PAL_DAC_Adjustment
decl_stmt|;
name|USHORT
name|usDAC2_TV2_FORCE_Data
decl_stmt|;
block|}
name|COMPASSIONATE_DATA
typedef|;
end_typedef

begin_comment
comment|/****************************Supported Device Info Table Definitions**********************/
end_comment

begin_comment
comment|//  ucConnectInfo:
end_comment

begin_comment
comment|//    [7:4] - connector type
end_comment

begin_comment
comment|//      = 1   - VGA connector
end_comment

begin_comment
comment|//      = 2   - DVI-I
end_comment

begin_comment
comment|//      = 3   - DVI-D
end_comment

begin_comment
comment|//      = 4   - DVI-A
end_comment

begin_comment
comment|//      = 5   - SVIDEO
end_comment

begin_comment
comment|//      = 6   - COMPOSITE
end_comment

begin_comment
comment|//      = 7   - LVDS
end_comment

begin_comment
comment|//      = 8   - DIGITAL LINK
end_comment

begin_comment
comment|//      = 9   - SCART
end_comment

begin_comment
comment|//      = 0xA - HDMI_type A
end_comment

begin_comment
comment|//      = 0xB - HDMI_type B
end_comment

begin_comment
comment|//      = 0xE - Special case1 (DVI+DIN)
end_comment

begin_comment
comment|//      Others=TBD
end_comment

begin_comment
comment|//    [3:0] - DAC Associated
end_comment

begin_comment
comment|//      = 0   - no DAC
end_comment

begin_comment
comment|//      = 1   - DACA
end_comment

begin_comment
comment|//      = 2   - DACB
end_comment

begin_comment
comment|//      = 3   - External DAC
end_comment

begin_comment
comment|//      Others=TBD
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_INFO
block|{
if|#
directive|if
name|ATOM_BIG_ENDIAN
name|UCHAR
name|bfConnectorType
range|:
literal|4
decl_stmt|;
name|UCHAR
name|bfAssociatedDAC
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|UCHAR
name|bfAssociatedDAC
range|:
literal|4
decl_stmt|;
name|UCHAR
name|bfConnectorType
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
block|}
name|ATOM_CONNECTOR_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_ATOM_CONNECTOR_INFO_ACCESS
block|{
name|ATOM_CONNECTOR_INFO
name|sbfAccess
decl_stmt|;
name|UCHAR
name|ucAccess
decl_stmt|;
block|}
name|ATOM_CONNECTOR_INFO_ACCESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_INFO_I2C
block|{
name|ATOM_CONNECTOR_INFO_ACCESS
name|sucConnectorInfo
decl_stmt|;
name|ATOM_I2C_ID_CONFIG_ACCESS
name|sucI2cId
decl_stmt|;
block|}
name|ATOM_CONNECTOR_INFO_I2C
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_SUPPORTED_DEVICES_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usDeviceSupport
decl_stmt|;
name|ATOM_CONNECTOR_INFO_I2C
name|asConnInfo
index|[
name|ATOM_MAX_SUPPORTED_DEVICE_INFO
index|]
decl_stmt|;
block|}
name|ATOM_SUPPORTED_DEVICES_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NO_INT_SRC_MAPPED
value|0xFF
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_CONNECTOR_INC_SRC_BITMAP
block|{
name|UCHAR
name|ucIntSrcBitmap
decl_stmt|;
block|}
name|ATOM_CONNECTOR_INC_SRC_BITMAP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_SUPPORTED_DEVICES_INFO_2
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usDeviceSupport
decl_stmt|;
name|ATOM_CONNECTOR_INFO_I2C
name|asConnInfo
index|[
name|ATOM_MAX_SUPPORTED_DEVICE_INFO_2
index|]
decl_stmt|;
name|ATOM_CONNECTOR_INC_SRC_BITMAP
name|asIntSrcInfo
index|[
name|ATOM_MAX_SUPPORTED_DEVICE_INFO_2
index|]
decl_stmt|;
block|}
name|ATOM_SUPPORTED_DEVICES_INFO_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_SUPPORTED_DEVICES_INFO_2d1
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usDeviceSupport
decl_stmt|;
name|ATOM_CONNECTOR_INFO_I2C
name|asConnInfo
index|[
name|ATOM_MAX_SUPPORTED_DEVICE
index|]
decl_stmt|;
name|ATOM_CONNECTOR_INC_SRC_BITMAP
name|asIntSrcInfo
index|[
name|ATOM_MAX_SUPPORTED_DEVICE
index|]
decl_stmt|;
block|}
name|ATOM_SUPPORTED_DEVICES_INFO_2d1
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_SUPPORTED_DEVICES_INFO_LAST
value|ATOM_SUPPORTED_DEVICES_INFO_2d1
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_MISC_CONTROL_INFO
block|{
name|USHORT
name|usFrequency
decl_stmt|;
name|UCHAR
name|ucPLL_ChargePump
decl_stmt|;
comment|// PLL charge-pump gain control
name|UCHAR
name|ucPLL_DutyCycle
decl_stmt|;
comment|// PLL duty cycle control
name|UCHAR
name|ucPLL_VCO_Gain
decl_stmt|;
comment|// PLL VCO gain control
name|UCHAR
name|ucPLL_VoltageSwing
decl_stmt|;
comment|// PLL driver voltage swing control
block|}
name|ATOM_MISC_CONTROL_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_MAX_MISC_INFO
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_TMDS_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usMaxFrequency
decl_stmt|;
comment|// in 10Khz
name|ATOM_MISC_CONTROL_INFO
name|asMiscInfo
index|[
name|ATOM_MAX_MISC_INFO
index|]
decl_stmt|;
block|}
name|ATOM_TMDS_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ENCODER_ANALOG_ATTRIBUTE
block|{
name|UCHAR
name|ucTVStandard
decl_stmt|;
comment|//Same as TV standards defined above,
name|UCHAR
name|ucPadding
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_ENCODER_ANALOG_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_ENCODER_DIGITAL_ATTRIBUTE
block|{
name|UCHAR
name|ucAttribute
decl_stmt|;
comment|//Same as other digital encoder attributes defined above
name|UCHAR
name|ucPadding
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_ENCODER_DIGITAL_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_ATOM_ENCODER_ATTRIBUTE
block|{
name|ATOM_ENCODER_ANALOG_ATTRIBUTE
name|sAlgAttrib
decl_stmt|;
name|ATOM_ENCODER_DIGITAL_ATTRIBUTE
name|sDigAttrib
decl_stmt|;
block|}
name|ATOM_ENCODER_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DVO_ENCODER_CONTROL_PARAMETERS
block|{
name|USHORT
name|usPixelClock
decl_stmt|;
name|USHORT
name|usEncoderID
decl_stmt|;
name|UCHAR
name|ucDeviceType
decl_stmt|;
comment|//Use ATOM_DEVICE_xxx1_Index to indicate device type only.
name|UCHAR
name|ucAction
decl_stmt|;
comment|//ATOM_ENABLE/ATOM_DISABLE/ATOM_HPD_INIT
name|ATOM_ENCODER_ATTRIBUTE
name|usDevAttr
decl_stmt|;
block|}
name|DVO_ENCODER_CONTROL_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DVO_ENCODER_CONTROL_PS_ALLOCATION
block|{
name|DVO_ENCODER_CONTROL_PARAMETERS
name|sDVOEncoder
decl_stmt|;
name|WRITE_ONE_BYTE_HW_I2C_DATA_PS_ALLOCATION
name|sReserved
decl_stmt|;
comment|//Caller doesn't need to init this portion
block|}
name|DVO_ENCODER_CONTROL_PS_ALLOCATION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_XTMDS_ASIC_SI164_ID
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_XTMDS_ASIC_SI178_ID
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_XTMDS_ASIC_TFP513_ID
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_XTMDS_SUPPORTED_SINGLELINK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATOM_XTMDS_SUPPORTED_DUALLINK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATOM_XTMDS_MVPU_FPGA
value|0x00000004
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_XTMDS_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|USHORT
name|usSingleLinkMaxFrequency
decl_stmt|;
name|ATOM_I2C_ID_CONFIG_ACCESS
name|sucI2cId
decl_stmt|;
comment|//Point the ID on which I2C is used to control external chip
name|UCHAR
name|ucXtransimitterID
decl_stmt|;
name|UCHAR
name|ucSupportedLink
decl_stmt|;
comment|// Bit field, bit0=1, single link supported;bit1=1,dual link supported
name|UCHAR
name|ucSequnceAlterID
decl_stmt|;
comment|// Even with the same external TMDS asic, it's possible that the program seqence alters
comment|// due to design. This ID is used to alert driver that the sequence is not "standard"!
name|UCHAR
name|ucMasterAddress
decl_stmt|;
comment|// Address to control Master xTMDS Chip
name|UCHAR
name|ucSlaveAddress
decl_stmt|;
comment|// Address to control Slave xTMDS Chip
block|}
name|ATOM_XTMDS_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DFP_DPMS_STATUS_CHANGE_PARAMETERS
block|{
name|UCHAR
name|ucEnable
decl_stmt|;
comment|// ATOM_ENABLE=On or ATOM_DISABLE=Off
name|UCHAR
name|ucDevice
decl_stmt|;
comment|// ATOM_DEVICE_DFP1_INDEX....
name|UCHAR
name|ucPadding
index|[
literal|2
index|]
decl_stmt|;
block|}
name|DFP_DPMS_STATUS_CHANGE_PARAMETERS
typedef|;
end_typedef

begin_comment
comment|/****************************Legacy Power Play Table Definitions **********************/
end_comment

begin_comment
comment|//Definitions for ulPowerPlayMiscInfo
end_comment

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_SPLIT_CLOCK
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_USING_MCLK_SRC
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_USING_SCLK_SRC
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_VOLTAGE_DROP_SUPPORT
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_VOLTAGE_DROP_ACTIVE_HIGH
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_LOAD_PERFORMANCE_EN
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_ENGINE_CLOCK_CONTRL_EN
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_MEMORY_CLOCK_CONTRL_EN
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_PROGRAM_VOLTAGE
value|0x00000080L
end_define

begin_comment
comment|//When this bit set, ucVoltageDropIndex is not an index for GPIO pin, but a voltage ID that SW needs program
end_comment

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_ASIC_REDUCED_SPEED_SCLK_EN
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_ASIC_DYNAMIC_VOLTAGE_EN
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_ASIC_SLEEP_MODE_EN
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_LOAD_BALANCE_EN
value|0x00000800L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_DEFAULT_DC_STATE_ENTRY_TRUE
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_DEFAULT_LOW_DC_STATE_ENTRY_TRUE
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_LOW_LCD_REFRESH_RATE
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_DRIVER_DEFAULT_MODE
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_OVER_CLOCK_MODE
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_OVER_DRIVE_MODE
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_POWER_SAVING_MODE
value|0x00040000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_THERMAL_DIODE_MODE
value|0x00080000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_FRAME_MODULATION_MASK
value|0x00300000L
end_define

begin_comment
comment|//0-FM Disable, 1-2 level FM, 2-4 level FM, 3-Reserved
end_comment

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_FRAME_MODULATION_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_DYN_CLK_3D_IDLE
value|0x00400000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_DYNAMIC_CLOCK_DIVIDER_BY_2
value|0x00800000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_DYNAMIC_CLOCK_DIVIDER_BY_4
value|0x01000000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_DYNAMIC_HDP_BLOCK_EN
value|0x02000000L
end_define

begin_comment
comment|//When set, Dynamic
end_comment

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_DYNAMIC_MC_HOST_BLOCK_EN
value|0x04000000L
end_define

begin_comment
comment|//When set, Dynamic
end_comment

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_3D_ACCELERATION_EN
value|0x08000000L
end_define

begin_comment
comment|//When set, This mode is for acceleated 3D mode
end_comment

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_POWERPLAY_SETTINGS_GROUP_MASK
value|0x70000000L
end_define

begin_comment
comment|//1-Optimal Battery Life Group, 2-High Battery, 3-Balanced, 4-High Performance, 5- Optimal Performance (Default state with Default clocks)
end_comment

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_POWERPLAY_SETTINGS_GROUP_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO_ENABLE_BACK_BIAS
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO2_SYSTEM_AC_LITE_MODE
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO2_MULTI_DISPLAY_SUPPORT
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO2_DYNAMIC_BACK_BIAS_EN
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO2_FS3D_OVERDRIVE_INFO
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO2_FORCEDLOWPWR_MODE
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO2_VDDCI_DYNAMIC_VOLTAGE_EN
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO2_VIDEO_PLAYBACK_CAPABLE
value|0x00000040L
end_define

begin_comment
comment|//If this bit is set in multi-pp mode, then driver will pack up one with the minior power consumption.
end_comment

begin_comment
comment|//If it's not set in any pp mode, driver will use its default logic to pick a pp mode in video playback
end_comment

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO2_NOT_VALID_ON_DC
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO2_STUTTER_MODE_EN
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|ATOM_PM_MISCINFO2_UVD_SUPPORT_MODE
value|0x00000200L
end_define

begin_comment
comment|//ucTableFormatRevision=1
end_comment

begin_comment
comment|//ucTableContentRevision=1
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_POWERMODE_INFO
block|{
name|ULONG
name|ulMiscInfo
decl_stmt|;
comment|//The power level should be arranged in ascending order
name|ULONG
name|ulReserved1
decl_stmt|;
comment|// must set to 0
name|ULONG
name|ulReserved2
decl_stmt|;
comment|// must set to 0
name|USHORT
name|usEngineClock
decl_stmt|;
name|USHORT
name|usMemoryClock
decl_stmt|;
name|UCHAR
name|ucVoltageDropIndex
decl_stmt|;
comment|// index to GPIO table
name|UCHAR
name|ucSelectedPanel_RefreshRate
decl_stmt|;
comment|// panel refresh rate
name|UCHAR
name|ucMinTemperature
decl_stmt|;
name|UCHAR
name|ucMaxTemperature
decl_stmt|;
name|UCHAR
name|ucNumPciELanes
decl_stmt|;
comment|// number of PCIE lanes
block|}
name|ATOM_POWERMODE_INFO
typedef|;
end_typedef

begin_comment
comment|//ucTableFormatRevision=2
end_comment

begin_comment
comment|//ucTableContentRevision=1
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_POWERMODE_INFO_V2
block|{
name|ULONG
name|ulMiscInfo
decl_stmt|;
comment|//The power level should be arranged in ascending order
name|ULONG
name|ulMiscInfo2
decl_stmt|;
name|ULONG
name|ulEngineClock
decl_stmt|;
name|ULONG
name|ulMemoryClock
decl_stmt|;
name|UCHAR
name|ucVoltageDropIndex
decl_stmt|;
comment|// index to GPIO table
name|UCHAR
name|ucSelectedPanel_RefreshRate
decl_stmt|;
comment|// panel refresh rate
name|UCHAR
name|ucMinTemperature
decl_stmt|;
name|UCHAR
name|ucMaxTemperature
decl_stmt|;
name|UCHAR
name|ucNumPciELanes
decl_stmt|;
comment|// number of PCIE lanes
block|}
name|ATOM_POWERMODE_INFO_V2
typedef|;
end_typedef

begin_comment
comment|//ucTableFormatRevision=2
end_comment

begin_comment
comment|//ucTableContentRevision=2
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_POWERMODE_INFO_V3
block|{
name|ULONG
name|ulMiscInfo
decl_stmt|;
comment|//The power level should be arranged in ascending order
name|ULONG
name|ulMiscInfo2
decl_stmt|;
name|ULONG
name|ulEngineClock
decl_stmt|;
name|ULONG
name|ulMemoryClock
decl_stmt|;
name|UCHAR
name|ucVoltageDropIndex
decl_stmt|;
comment|// index to Core (VDDC) votage table
name|UCHAR
name|ucSelectedPanel_RefreshRate
decl_stmt|;
comment|// panel refresh rate
name|UCHAR
name|ucMinTemperature
decl_stmt|;
name|UCHAR
name|ucMaxTemperature
decl_stmt|;
name|UCHAR
name|ucNumPciELanes
decl_stmt|;
comment|// number of PCIE lanes
name|UCHAR
name|ucVDDCI_VoltageDropIndex
decl_stmt|;
comment|// index to VDDCI votage table
block|}
name|ATOM_POWERMODE_INFO_V3
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_MAX_NUMBEROF_POWER_BLOCK
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_PP_OVERDRIVE_INTBITMAP_AUXWIN
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_PP_OVERDRIVE_INTBITMAP_OVERDRIVE
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_PP_OVERDRIVE_THERMALCONTROLLER_LM63
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_PP_OVERDRIVE_THERMALCONTROLLER_ADM1032
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_PP_OVERDRIVE_THERMALCONTROLLER_ADM1030
value|0x03
end_define

begin_define
define|#
directive|define
name|ATOM_PP_OVERDRIVE_THERMALCONTROLLER_MUA6649
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_PP_OVERDRIVE_THERMALCONTROLLER_LM64
value|0x05
end_define

begin_define
define|#
directive|define
name|ATOM_PP_OVERDRIVE_THERMALCONTROLLER_F75375
value|0x06
end_define

begin_define
define|#
directive|define
name|ATOM_PP_OVERDRIVE_THERMALCONTROLLER_ASC7512
value|0x07
end_define

begin_comment
comment|// Andigilog
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_POWERPLAY_INFO
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|ucOverdriveThermalController
decl_stmt|;
name|UCHAR
name|ucOverdriveI2cLine
decl_stmt|;
name|UCHAR
name|ucOverdriveIntBitmap
decl_stmt|;
name|UCHAR
name|ucOverdriveControllerAddress
decl_stmt|;
name|UCHAR
name|ucSizeOfPowerModeEntry
decl_stmt|;
name|UCHAR
name|ucNumOfPowerModeEntries
decl_stmt|;
name|ATOM_POWERMODE_INFO
name|asPowerPlayInfo
index|[
name|ATOM_MAX_NUMBEROF_POWER_BLOCK
index|]
decl_stmt|;
block|}
name|ATOM_POWERPLAY_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_POWERPLAY_INFO_V2
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|ucOverdriveThermalController
decl_stmt|;
name|UCHAR
name|ucOverdriveI2cLine
decl_stmt|;
name|UCHAR
name|ucOverdriveIntBitmap
decl_stmt|;
name|UCHAR
name|ucOverdriveControllerAddress
decl_stmt|;
name|UCHAR
name|ucSizeOfPowerModeEntry
decl_stmt|;
name|UCHAR
name|ucNumOfPowerModeEntries
decl_stmt|;
name|ATOM_POWERMODE_INFO_V2
name|asPowerPlayInfo
index|[
name|ATOM_MAX_NUMBEROF_POWER_BLOCK
index|]
decl_stmt|;
block|}
name|ATOM_POWERPLAY_INFO_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_POWERPLAY_INFO_V3
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|ucOverdriveThermalController
decl_stmt|;
name|UCHAR
name|ucOverdriveI2cLine
decl_stmt|;
name|UCHAR
name|ucOverdriveIntBitmap
decl_stmt|;
name|UCHAR
name|ucOverdriveControllerAddress
decl_stmt|;
name|UCHAR
name|ucSizeOfPowerModeEntry
decl_stmt|;
name|UCHAR
name|ucNumOfPowerModeEntries
decl_stmt|;
name|ATOM_POWERMODE_INFO_V3
name|asPowerPlayInfo
index|[
name|ATOM_MAX_NUMBEROF_POWER_BLOCK
index|]
decl_stmt|;
block|}
name|ATOM_POWERPLAY_INFO_V3
typedef|;
end_typedef

begin_comment
comment|/* New PPlib */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_THERMALCONTROLLER
block|{
name|UCHAR
name|ucType
decl_stmt|;
comment|// one of ATOM_PP_THERMALCONTROLLER_*
name|UCHAR
name|ucI2cLine
decl_stmt|;
comment|// as interpreted by DAL I2C
name|UCHAR
name|ucI2cAddress
decl_stmt|;
name|UCHAR
name|ucFanParameters
decl_stmt|;
comment|// Fan Control Parameters.
name|UCHAR
name|ucFanMinRPM
decl_stmt|;
comment|// Fan Minimum RPM (hundreds) -- for display purposes only.
name|UCHAR
name|ucFanMaxRPM
decl_stmt|;
comment|// Fan Maximum RPM (hundreds) -- for display purposes only.
name|UCHAR
name|ucReserved
decl_stmt|;
comment|// ----
name|UCHAR
name|ucFlags
decl_stmt|;
comment|// to be defined
block|}
name|ATOM_PPLIB_THERMALCONTROLLER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_PP_FANPARAMETERS_TACHOMETER_PULSES_PER_REVOLUTION_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|ATOM_PP_FANPARAMETERS_NOFAN
value|0x80
end_define

begin_comment
comment|// No fan is connected to this controller.
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_LM63
value|1
end_define

begin_comment
comment|// Not used by PPLib
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_ADM1032
value|2
end_define

begin_comment
comment|// Not used by PPLib
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_ADM1030
value|3
end_define

begin_comment
comment|// Not used by PPLib
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_MUA6649
value|4
end_define

begin_comment
comment|// Not used by PPLib
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_LM64
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_F75375
value|6
end_define

begin_comment
comment|// Not used by PPLib
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_RV6xx
value|7
end_define

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_RV770
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_ADT7473
value|9
end_define

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_EXTERNAL_GPIO
value|11
end_define

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_EVERGREEN
value|12
end_define

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_EMC2103
value|13
end_define

begin_comment
comment|/* 0x0D */
end_comment

begin_comment
comment|// Only fan control will be implemented, do NOT show this in PPGen.
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_SUMO
value|14
end_define

begin_comment
comment|/* 0x0E */
end_comment

begin_comment
comment|// Sumo type, used internally
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_NISLANDS
value|15
end_define

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_SISLANDS
value|16
end_define

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_LM96163
value|17
end_define

begin_comment
comment|// Thermal controller 'combo type' to use an external controller for Fan control and an internal controller for thermal.
end_comment

begin_comment
comment|// We probably should reserve the bit 0x80 for this use.
end_comment

begin_comment
comment|// To keep the number of these types low we should also use the same code for all ASICs (i.e. do not distinguish RV6xx and RV7xx Internal here).
end_comment

begin_comment
comment|// The driver can pick the correct internal controller based on the ASIC.
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_ADT7473_WITH_INTERNAL
value|0x89
end_define

begin_comment
comment|// ADT7473 Fan Control + Internal Thermal Controller
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_THERMALCONTROLLER_EMC2103_WITH_INTERNAL
value|0x8D
end_define

begin_comment
comment|// EMC2103 Fan Control + Internal Thermal Controller
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_STATE
block|{
name|UCHAR
name|ucNonClockStateIndex
decl_stmt|;
name|UCHAR
name|ucClockStateIndices
index|[
literal|1
index|]
decl_stmt|;
comment|// variable-sized
block|}
name|ATOM_PPLIB_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_FANTABLE
block|{
name|UCHAR
name|ucFanTableFormat
decl_stmt|;
comment|// Change this if the table format changes or version changes so that the other fields are not the same.
name|UCHAR
name|ucTHyst
decl_stmt|;
comment|// Temperature hysteresis. Integer.
name|USHORT
name|usTMin
decl_stmt|;
comment|// The temperature, in 0.01 centigrades, below which we just run at a minimal PWM.
name|USHORT
name|usTMed
decl_stmt|;
comment|// The middle temperature where we change slopes.
name|USHORT
name|usTHigh
decl_stmt|;
comment|// The high point above TMed for adjusting the second slope.
name|USHORT
name|usPWMMin
decl_stmt|;
comment|// The minimum PWM value in percent (0.01% increments).
name|USHORT
name|usPWMMed
decl_stmt|;
comment|// The PWM value (in percent) at TMed.
name|USHORT
name|usPWMHigh
decl_stmt|;
comment|// The PWM value at THigh.
block|}
name|ATOM_PPLIB_FANTABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_FANTABLE2
block|{
name|ATOM_PPLIB_FANTABLE
name|basicTable
decl_stmt|;
name|USHORT
name|usTMax
decl_stmt|;
comment|// The max temperature
block|}
name|ATOM_PPLIB_FANTABLE2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_EXTENDEDHEADER
block|{
name|USHORT
name|usSize
decl_stmt|;
name|ULONG
name|ulMaxEngineClock
decl_stmt|;
comment|// For Overdrive.
name|ULONG
name|ulMaxMemoryClock
decl_stmt|;
comment|// For Overdrive.
comment|// Add extra system parameters here, always adjust size to include all fields.
name|USHORT
name|usVCETableOffset
decl_stmt|;
comment|//points to ATOM_PPLIB_VCE_Table
name|USHORT
name|usUVDTableOffset
decl_stmt|;
comment|//points to ATOM_PPLIB_UVD_Table
block|}
name|ATOM_PPLIB_EXTENDEDHEADER
typedef|;
end_typedef

begin_comment
comment|//// ATOM_PPLIB_POWERPLAYTABLE::ulPlatformCaps
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_BACKBIAS
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_POWERPLAY
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_SBIOSPOWERSOURCE
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_ASPM_L0s
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_ASPM_L1
value|16
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_HARDWAREDC
value|32
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_GEMINIPRIMARY
value|64
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_STEPVDDC
value|128
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_VOLTAGECONTROL
value|256
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_SIDEPORTCONTROL
value|512
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_TURNOFFPLL_ASPML1
value|1024
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_HTLINKCONTROL
value|2048
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_MVDDCONTROL
value|4096
end_define

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_GOTO_BOOT_ON_ALERT
value|0x2000
end_define

begin_comment
comment|// Go to boot state on alerts, e.g. on an AC->DC transition.
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_DONT_WAIT_FOR_VBLANK_ON_ALERT
value|0x4000
end_define

begin_comment
comment|// Do NOT wait for VBLANK during an alert (e.g. AC->DC transition).
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_VDDCI_CONTROL
value|0x8000
end_define

begin_comment
comment|// Does the driver control VDDCI independently from VDDC.
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_REGULATOR_HOT
value|0x00010000
end_define

begin_comment
comment|// Enable the 'regulator hot' feature.
end_comment

begin_define
define|#
directive|define
name|ATOM_PP_PLATFORM_CAP_BACO
value|0x00020000
end_define

begin_comment
comment|// Does the driver supports BACO state.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_POWERPLAYTABLE
block|{
name|ATOM_COMMON_TABLE_HEADER
name|sHeader
decl_stmt|;
name|UCHAR
name|ucDataRevision
decl_stmt|;
name|UCHAR
name|ucNumStates
decl_stmt|;
name|UCHAR
name|ucStateEntrySize
decl_stmt|;
name|UCHAR
name|ucClockInfoSize
decl_stmt|;
name|UCHAR
name|ucNonClockSize
decl_stmt|;
comment|// offset from start of this table to array of ucNumStates ATOM_PPLIB_STATE structures
name|USHORT
name|usStateArrayOffset
decl_stmt|;
comment|// offset from start of this table to array of ASIC-specific structures,
comment|// currently ATOM_PPLIB_CLOCK_INFO.
name|USHORT
name|usClockInfoArrayOffset
decl_stmt|;
comment|// offset from start of this table to array of ATOM_PPLIB_NONCLOCK_INFO
name|USHORT
name|usNonClockInfoArrayOffset
decl_stmt|;
name|USHORT
name|usBackbiasTime
decl_stmt|;
comment|// in microseconds
name|USHORT
name|usVoltageTime
decl_stmt|;
comment|// in microseconds
name|USHORT
name|usTableSize
decl_stmt|;
comment|//the size of this structure, or the extended structure
name|ULONG
name|ulPlatformCaps
decl_stmt|;
comment|// See ATOM_PPLIB_CAPS_*
name|ATOM_PPLIB_THERMALCONTROLLER
name|sThermalController
decl_stmt|;
name|USHORT
name|usBootClockInfoOffset
decl_stmt|;
name|USHORT
name|usBootNonClockInfoOffset
decl_stmt|;
block|}
name|ATOM_PPLIB_POWERPLAYTABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_POWERPLAYTABLE2
block|{
name|ATOM_PPLIB_POWERPLAYTABLE
name|basicTable
decl_stmt|;
name|UCHAR
name|ucNumCustomThermalPolicy
decl_stmt|;
name|USHORT
name|usCustomThermalPolicyArrayOffset
decl_stmt|;
block|}
name|ATOM_PPLIB_POWERPLAYTABLE2
operator|,
typedef|*
name|LPATOM_PPLIB_POWERPLAYTABLE2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_POWERPLAYTABLE3
block|{
name|ATOM_PPLIB_POWERPLAYTABLE2
name|basicTable2
decl_stmt|;
name|USHORT
name|usFormatID
decl_stmt|;
comment|// To be used ONLY by PPGen.
name|USHORT
name|usFanTableOffset
decl_stmt|;
name|USHORT
name|usExtendendedHeaderOffset
decl_stmt|;
block|}
name|ATOM_PPLIB_POWERPLAYTABLE3
operator|,
typedef|*
name|LPATOM_PPLIB_POWERPLAYTABLE3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_POWERPLAYTABLE4
block|{
name|ATOM_PPLIB_POWERPLAYTABLE3
name|basicTable3
decl_stmt|;
name|ULONG
name|ulGoldenPPID
decl_stmt|;
comment|// PPGen use only
name|ULONG
name|ulGoldenRevision
decl_stmt|;
comment|// PPGen use only
name|USHORT
name|usVddcDependencyOnSCLKOffset
decl_stmt|;
name|USHORT
name|usVddciDependencyOnMCLKOffset
decl_stmt|;
name|USHORT
name|usVddcDependencyOnMCLKOffset
decl_stmt|;
name|USHORT
name|usMaxClockVoltageOnDCOffset
decl_stmt|;
name|USHORT
name|usVddcPhaseShedLimitsTableOffset
decl_stmt|;
comment|// Points to ATOM_PPLIB_PhaseSheddingLimits_Table
name|USHORT
name|usReserved
decl_stmt|;
block|}
name|ATOM_PPLIB_POWERPLAYTABLE4
operator|,
typedef|*
name|LPATOM_PPLIB_POWERPLAYTABLE4
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_POWERPLAYTABLE5
block|{
name|ATOM_PPLIB_POWERPLAYTABLE4
name|basicTable4
decl_stmt|;
name|ULONG
name|ulTDPLimit
decl_stmt|;
name|ULONG
name|ulNearTDPLimit
decl_stmt|;
name|ULONG
name|ulSQRampingThreshold
decl_stmt|;
name|USHORT
name|usCACLeakageTableOffset
decl_stmt|;
comment|// Points to ATOM_PPLIB_CAC_Leakage_Table
name|ULONG
name|ulCACLeakage
decl_stmt|;
comment|// The iLeakage for driver calculated CAC leakage table
name|USHORT
name|usTDPODLimit
decl_stmt|;
name|USHORT
name|usLoadLineSlope
decl_stmt|;
comment|// in milliOhms * 100
block|}
name|ATOM_PPLIB_POWERPLAYTABLE5
operator|,
typedef|*
name|LPATOM_PPLIB_POWERPLAYTABLE5
typedef|;
end_typedef

begin_comment
comment|//// ATOM_PPLIB_NONCLOCK_INFO::usClassification
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_UI_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_UI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_UI_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_UI_BATTERY
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_UI_BALANCED
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_UI_PERFORMANCE
value|5
end_define

begin_comment
comment|// 2, 4, 6, 7 are reserved
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_BOOT
value|0x0008
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_THERMAL
value|0x0010
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_LIMITEDPOWERSOURCE
value|0x0020
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_REST
value|0x0040
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_FORCED
value|0x0080
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_3DPERFORMANCE
value|0x0100
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_OVERDRIVETEMPLATE
value|0x0200
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_UVDSTATE
value|0x0400
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_3DLOW
value|0x0800
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_ACPI
value|0x1000
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_HD2STATE
value|0x2000
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_HDSTATE
value|0x4000
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION_SDSTATE
value|0x8000
end_define

begin_comment
comment|//// ATOM_PPLIB_NONCLOCK_INFO::usClassification2
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION2_LIMITEDPOWERSOURCE_2
value|0x0001
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION2_ULV
value|0x0002
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_CLASSIFICATION2_MVC
value|0x0004
end_define

begin_comment
comment|//Multi-View Codec (BD-3D)
end_comment

begin_comment
comment|//// ATOM_PPLIB_NONCLOCK_INFO::ulCapsAndSettings
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_SINGLE_DISPLAY_ONLY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_SUPPORTS_VIDEO_PLAYBACK
value|0x00000002
end_define

begin_comment
comment|// 0 is 2.5Gb/s, 1 is 5Gb/s
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_PCIE_LINK_SPEED_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_PCIE_LINK_SPEED_SHIFT
value|2
end_define

begin_comment
comment|// lanes - 1: 1, 2, 4, 8, 12, 16 permitted by PCIE spec
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_PCIE_LINK_WIDTH_MASK
value|0x000000F8
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_PCIE_LINK_WIDTH_SHIFT
value|3
end_define

begin_comment
comment|// lookup into reduced refresh-rate table
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_LIMITED_REFRESHRATE_VALUE_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_LIMITED_REFRESHRATE_VALUE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_LIMITED_REFRESHRATE_UNLIMITED
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_LIMITED_REFRESHRATE_50HZ
value|1
end_define

begin_comment
comment|// 2-15 TBD as needed.
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_SOFTWARE_DISABLE_LOADBALANCING
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_SOFTWARE_ENABLE_SLEEP_FOR_TIMESTAMPS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_DISALLOW_ON_DC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_ENABLE_VARIBRIGHT
value|0x00008000
end_define

begin_comment
comment|//memory related flags
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_SWSTATE_MEMORY_DLL_OFF
value|0x000010000
end_define

begin_comment
comment|//M3 Arb    //2bits, current 3 sets of parameters in total
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_M3ARB_MASK
value|0x00060000
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_M3ARB_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_ENABLE_DRR
value|0x00080000
end_define

begin_comment
comment|// remaining 16 bits are reserved
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_THERMAL_STATE
block|{
name|UCHAR
name|ucMinTemperature
decl_stmt|;
name|UCHAR
name|ucMaxTemperature
decl_stmt|;
name|UCHAR
name|ucThermalAction
decl_stmt|;
block|}
name|ATOM_PPLIB_THERMAL_STATE
operator|,
typedef|*
name|LPATOM_PPLIB_THERMAL_STATE
typedef|;
end_typedef

begin_comment
comment|// Contained in an array starting at the offset
end_comment

begin_comment
comment|// in ATOM_PPLIB_POWERPLAYTABLE::usNonClockInfoArrayOffset.
end_comment

begin_comment
comment|// referenced from ATOM_PPLIB_STATE_INFO::ucNonClockStateIndex
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_NONCLOCKINFO_VER1
value|12
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_NONCLOCKINFO_VER2
value|24
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_NONCLOCK_INFO
block|{
name|USHORT
name|usClassification
decl_stmt|;
name|UCHAR
name|ucMinTemperature
decl_stmt|;
name|UCHAR
name|ucMaxTemperature
decl_stmt|;
name|ULONG
name|ulCapsAndSettings
decl_stmt|;
name|UCHAR
name|ucRequiredPower
decl_stmt|;
name|USHORT
name|usClassification2
decl_stmt|;
name|ULONG
name|ulVCLK
decl_stmt|;
name|ULONG
name|ulDCLK
decl_stmt|;
name|UCHAR
name|ucUnused
index|[
literal|5
index|]
decl_stmt|;
block|}
name|ATOM_PPLIB_NONCLOCK_INFO
typedef|;
end_typedef

begin_comment
comment|// Contained in an array starting at the offset
end_comment

begin_comment
comment|// in ATOM_PPLIB_POWERPLAYTABLE::usClockInfoArrayOffset.
end_comment

begin_comment
comment|// referenced from ATOM_PPLIB_STATE::ucClockStateIndices
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_R600_CLOCK_INFO
block|{
name|USHORT
name|usEngineClockLow
decl_stmt|;
name|UCHAR
name|ucEngineClockHigh
decl_stmt|;
name|USHORT
name|usMemoryClockLow
decl_stmt|;
name|UCHAR
name|ucMemoryClockHigh
decl_stmt|;
name|USHORT
name|usVDDC
decl_stmt|;
name|USHORT
name|usUnused1
decl_stmt|;
name|USHORT
name|usUnused2
decl_stmt|;
name|ULONG
name|ulFlags
decl_stmt|;
comment|// ATOM_PPLIB_R600_FLAGS_*
block|}
name|ATOM_PPLIB_R600_CLOCK_INFO
typedef|;
end_typedef

begin_comment
comment|// ulFlags in ATOM_PPLIB_R600_CLOCK_INFO
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_R600_FLAGS_PCIEGEN2
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_R600_FLAGS_UVDSAFE
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_R600_FLAGS_BACKBIASENABLE
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_R600_FLAGS_MEMORY_ODT_OFF
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_R600_FLAGS_MEMORY_DLL_OFF
value|16
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_R600_FLAGS_LOWPOWER
value|32
end_define

begin_comment
comment|// On the RV770 use 'low power' setting (sequencer S0).
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_EVERGREEN_CLOCK_INFO
block|{
name|USHORT
name|usEngineClockLow
decl_stmt|;
name|UCHAR
name|ucEngineClockHigh
decl_stmt|;
name|USHORT
name|usMemoryClockLow
decl_stmt|;
name|UCHAR
name|ucMemoryClockHigh
decl_stmt|;
name|USHORT
name|usVDDC
decl_stmt|;
name|USHORT
name|usVDDCI
decl_stmt|;
name|USHORT
name|usUnused
decl_stmt|;
name|ULONG
name|ulFlags
decl_stmt|;
comment|// ATOM_PPLIB_R600_FLAGS_*
block|}
name|ATOM_PPLIB_EVERGREEN_CLOCK_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_SI_CLOCK_INFO
block|{
name|USHORT
name|usEngineClockLow
decl_stmt|;
name|UCHAR
name|ucEngineClockHigh
decl_stmt|;
name|USHORT
name|usMemoryClockLow
decl_stmt|;
name|UCHAR
name|ucMemoryClockHigh
decl_stmt|;
name|USHORT
name|usVDDC
decl_stmt|;
name|USHORT
name|usVDDCI
decl_stmt|;
name|UCHAR
name|ucPCIEGen
decl_stmt|;
name|UCHAR
name|ucUnused1
decl_stmt|;
name|ULONG
name|ulFlags
decl_stmt|;
comment|// ATOM_PPLIB_SI_FLAGS_*, no flag is necessary for now
block|}
name|ATOM_PPLIB_SI_CLOCK_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_RS780_CLOCK_INFO
block|{
name|USHORT
name|usLowEngineClockLow
decl_stmt|;
comment|// Low Engine clock in MHz (the same way as on the R600).
name|UCHAR
name|ucLowEngineClockHigh
decl_stmt|;
name|USHORT
name|usHighEngineClockLow
decl_stmt|;
comment|// High Engine clock in MHz.
name|UCHAR
name|ucHighEngineClockHigh
decl_stmt|;
name|USHORT
name|usMemoryClockLow
decl_stmt|;
comment|// For now one of the ATOM_PPLIB_RS780_SPMCLK_XXXX constants.
name|UCHAR
name|ucMemoryClockHigh
decl_stmt|;
comment|// Currentyl unused.
name|UCHAR
name|ucPadding
decl_stmt|;
comment|// For proper alignment and size.
name|USHORT
name|usVDDC
decl_stmt|;
comment|// For the 780, use: None, Low, High, Variable
name|UCHAR
name|ucMaxHTLinkWidth
decl_stmt|;
comment|// From SBIOS - {2, 4, 8, 16}
name|UCHAR
name|ucMinHTLinkWidth
decl_stmt|;
comment|// From SBIOS - {2, 4, 8, 16}. Effective only if CDLW enabled. Minimum down stream width could be bigger as display BW requriement.
name|USHORT
name|usHTLinkFreq
decl_stmt|;
comment|// See definition ATOM_PPLIB_RS780_HTLINKFREQ_xxx or in MHz(>=200).
name|ULONG
name|ulFlags
decl_stmt|;
block|}
name|ATOM_PPLIB_RS780_CLOCK_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOM_PPLIB_RS780_VOLTAGE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_RS780_VOLTAGE_LOW
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_RS780_VOLTAGE_HIGH
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_RS780_VOLTAGE_VARIABLE
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_RS780_SPMCLK_NONE
value|0
end_define

begin_comment
comment|// We cannot change the side port memory clock, leave it as it is.
end_comment

begin_define
define|#
directive|define
name|ATOM_PPLIB_RS780_SPMCLK_LOW
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_RS780_SPMCLK_HIGH
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_RS780_HTLINKFREQ_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_RS780_HTLINKFREQ_LOW
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_PPLIB_RS780_HTLINKFREQ_HIGH
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_SUMO_CLOCK_INFO
block|{
name|USHORT
name|usEngineClockLow
decl_stmt|;
comment|//clockfrequency& 0xFFFF. The unit is in 10khz
name|UCHAR
name|ucEngineClockHigh
decl_stmt|;
comment|//clockfrequency>> 16.
name|UCHAR
name|vddcIndex
decl_stmt|;
comment|//2-bit vddc index;
name|USHORT
name|tdpLimit
decl_stmt|;
comment|//please initalize to 0
name|USHORT
name|rsv1
decl_stmt|;
comment|//please initialize to 0s
name|ULONG
name|rsv2
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ATOM_PPLIB_SUMO_CLOCK_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_STATE_V2
block|{
comment|//number of valid dpm levels in this state; Driver uses it to calculate the whole
comment|//size of the state: sizeof(ATOM_PPLIB_STATE_V2) + (ucNumDPMLevels - 1) * sizeof(UCHAR)
name|UCHAR
name|ucNumDPMLevels
decl_stmt|;
comment|//a index to the array of nonClockInfos
name|UCHAR
name|nonClockInfoIndex
decl_stmt|;
comment|/**       * Driver will read the first ucNumDPMLevels in this array       */
name|UCHAR
name|clockInfoIndex
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_PPLIB_STATE_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_StateArray
block|{
comment|//how many states we have
name|UCHAR
name|ucNumEntries
decl_stmt|;
name|ATOM_PPLIB_STATE_V2
name|states
index|[
literal|1
index|]
decl_stmt|;
block|}
name|StateArray
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ClockInfoArray
block|{
comment|//how many clock levels we have
name|UCHAR
name|ucNumEntries
decl_stmt|;
comment|//sizeof(ATOM_PPLIB_CLOCK_INFO)
name|UCHAR
name|ucEntrySize
decl_stmt|;
name|UCHAR
name|clockInfo
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ClockInfoArray
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NonClockInfoArray
block|{
comment|//how many non-clock levels we have. normally should be same as number of states
name|UCHAR
name|ucNumEntries
decl_stmt|;
comment|//sizeof(ATOM_PPLIB_NONCLOCK_INFO)
name|UCHAR
name|ucEntrySize
decl_stmt|;
name|ATOM_PPLIB_NONCLOCK_INFO
name|nonClockInfo
index|[
literal|1
index|]
decl_stmt|;
block|}
name|NonClockInfoArray
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_Clock_Voltage_Dependency_Record
block|{
name|USHORT
name|usClockLow
decl_stmt|;
name|UCHAR
name|ucClockHigh
decl_stmt|;
name|USHORT
name|usVoltage
decl_stmt|;
block|}
name|ATOM_PPLIB_Clock_Voltage_Dependency_Record
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_Clock_Voltage_Dependency_Table
block|{
name|UCHAR
name|ucNumEntries
decl_stmt|;
comment|// Number of entries.
name|ATOM_PPLIB_Clock_Voltage_Dependency_Record
name|entries
index|[
literal|1
index|]
decl_stmt|;
comment|// Dynamically allocate entries.
block|}
name|ATOM_PPLIB_Clock_Voltage_Dependency_Table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_Clock_Voltage_Limit_Record
block|{
name|USHORT
name|usSclkLow
decl_stmt|;
name|UCHAR
name|ucSclkHigh
decl_stmt|;
name|USHORT
name|usMclkLow
decl_stmt|;
name|UCHAR
name|ucMclkHigh
decl_stmt|;
name|USHORT
name|usVddc
decl_stmt|;
name|USHORT
name|usVddci
decl_stmt|;
block|}
name|ATOM_PPLIB_Clock_Voltage_Limit_Record
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_Clock_Voltage_Limit_Table
block|{
name|UCHAR
name|ucNumEntries
decl_stmt|;
comment|// Number of entries.
name|ATOM_PPLIB_Clock_Voltage_Limit_Record
name|entries
index|[
literal|1
index|]
decl_stmt|;
comment|// Dynamically allocate entries.
block|}
name|ATOM_PPLIB_Clock_Voltage_Limit_Table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_CAC_Leakage_Record
block|{
name|USHORT
name|usVddc
decl_stmt|;
comment|// We use this field for the "fake" standardized VDDC for power calculations
name|ULONG
name|ulLeakageValue
decl_stmt|;
block|}
name|ATOM_PPLIB_CAC_Leakage_Record
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_CAC_Leakage_Table
block|{
name|UCHAR
name|ucNumEntries
decl_stmt|;
comment|// Number of entries.
name|ATOM_PPLIB_CAC_Leakage_Record
name|entries
index|[
literal|1
index|]
decl_stmt|;
comment|// Dynamically allocate entries.
block|}
name|ATOM_PPLIB_CAC_Leakage_Table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_PhaseSheddingLimits_Record
block|{
name|USHORT
name|usVoltage
decl_stmt|;
name|USHORT
name|usSclkLow
decl_stmt|;
name|UCHAR
name|ucSclkHigh
decl_stmt|;
name|USHORT
name|usMclkLow
decl_stmt|;
name|UCHAR
name|ucMclkHigh
decl_stmt|;
block|}
name|ATOM_PPLIB_PhaseSheddingLimits_Record
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_PhaseSheddingLimits_Table
block|{
name|UCHAR
name|ucNumEntries
decl_stmt|;
comment|// Number of entries.
name|ATOM_PPLIB_PhaseSheddingLimits_Record
name|entries
index|[
literal|1
index|]
decl_stmt|;
comment|// Dynamically allocate entries.
block|}
name|ATOM_PPLIB_PhaseSheddingLimits_Table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_VCEClockInfo
block|{
name|USHORT
name|usEVClkLow
decl_stmt|;
name|UCHAR
name|ucEVClkHigh
decl_stmt|;
name|USHORT
name|usECClkLow
decl_stmt|;
name|UCHAR
name|ucECClkHigh
decl_stmt|;
block|}
name|VCEClockInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_VCEClockInfoArray
block|{
name|UCHAR
name|ucNumEntries
decl_stmt|;
name|VCEClockInfo
name|entries
index|[
literal|1
index|]
decl_stmt|;
block|}
name|VCEClockInfoArray
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_VCE_Clock_Voltage_Limit_Record
block|{
name|USHORT
name|usVoltage
decl_stmt|;
name|UCHAR
name|ucVCEClockInfoIndex
decl_stmt|;
block|}
name|ATOM_PPLIB_VCE_Clock_Voltage_Limit_Record
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_VCE_Clock_Voltage_Limit_Table
block|{
name|UCHAR
name|numEntries
decl_stmt|;
name|ATOM_PPLIB_VCE_Clock_Voltage_Limit_Record
name|entries
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_PPLIB_VCE_Clock_Voltage_Limit_Table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_VCE_State_Record
block|{
name|UCHAR
name|ucVCEClockInfoIndex
decl_stmt|;
name|UCHAR
name|ucClockInfoIndex
decl_stmt|;
comment|//highest 2 bits indicates memory p-states, lower 6bits indicates index to ClockInfoArrary
block|}
name|ATOM_PPLIB_VCE_State_Record
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_VCE_State_Table
block|{
name|UCHAR
name|numEntries
decl_stmt|;
name|ATOM_PPLIB_VCE_State_Record
name|entries
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_PPLIB_VCE_State_Table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_VCE_Table
block|{
name|UCHAR
name|revid
decl_stmt|;
comment|//    VCEClockInfoArray array;
comment|//    ATOM_PPLIB_VCE_Clock_Voltage_Limit_Table limits;
comment|//    ATOM_PPLIB_VCE_State_Table states;
block|}
name|ATOM_PPLIB_VCE_Table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_UVDClockInfo
block|{
name|USHORT
name|usVClkLow
decl_stmt|;
name|UCHAR
name|ucVClkHigh
decl_stmt|;
name|USHORT
name|usDClkLow
decl_stmt|;
name|UCHAR
name|ucDClkHigh
decl_stmt|;
block|}
name|UVDClockInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_UVDClockInfoArray
block|{
name|UCHAR
name|ucNumEntries
decl_stmt|;
name|UVDClockInfo
name|entries
index|[
literal|1
index|]
decl_stmt|;
block|}
name|UVDClockInfoArray
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_UVD_Clock_Voltage_Limit_Record
block|{
name|USHORT
name|usVoltage
decl_stmt|;
name|UCHAR
name|ucUVDClockInfoIndex
decl_stmt|;
block|}
name|ATOM_PPLIB_UVD_Clock_Voltage_Limit_Record
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_UVD_Clock_Voltage_Limit_Table
block|{
name|UCHAR
name|numEntries
decl_stmt|;
name|ATOM_PPLIB_UVD_Clock_Voltage_Limit_Record
name|entries
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_PPLIB_UVD_Clock_Voltage_Limit_Table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_UVD_State_Record
block|{
name|UCHAR
name|ucUVDClockInfoIndex
decl_stmt|;
name|UCHAR
name|ucClockInfoIndex
decl_stmt|;
comment|//highest 2 bits indicates memory p-states, lower 6bits indicates index to ClockInfoArrary
block|}
name|ATOM_PPLIB_UVD_State_Record
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_UVD_State_Table
block|{
name|UCHAR
name|numEntries
decl_stmt|;
name|ATOM_PPLIB_UVD_State_Record
name|entries
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ATOM_PPLIB_UVD_State_Table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ATOM_PPLIB_UVD_Table
block|{
name|UCHAR
name|revid
decl_stmt|;
comment|//    UVDClockInfoArray array;
comment|//    ATOM_PPLIB_UVD_Clock_Voltage_Limit_Table limits;
comment|//    ATOM_PPLIB_UVD_State_Table states;
block|}
name|ATOM_PPLIB_UVD_Table
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|// Following definitions are for compatibility issue in different SW components.
end_comment

begin_define
define|#
directive|define
name|ATOM_MASTER_DATA_TABLE_REVISION
value|0x01
end_define

begin_define
define|#
directive|define
name|Object_Info
value|Object_Header
end_define

begin_define
define|#
directive|define
name|AdjustARB_SEQ
value|MC_InitParameter
end_define

begin_define
define|#
directive|define
name|VRAM_GPIO_DetectionInfo
value|VoltageObjectInfo
end_define

begin_define
define|#
directive|define
name|ASIC_VDDCI_Info
value|ASIC_ProfilingInfo
end_define

begin_define
define|#
directive|define
name|ASIC_MVDDQ_Info
value|MemoryTrainingInfo
end_define

begin_define
define|#
directive|define
name|SS_Info
value|PPLL_SS_Info
end_define

begin_define
define|#
directive|define
name|ASIC_MVDDC_Info
value|ASIC_InternalSS_Info
end_define

begin_define
define|#
directive|define
name|DispDevicePriorityInfo
value|SaveRestoreInfo
end_define

begin_define
define|#
directive|define
name|DispOutInfo
value|TV_VideoMode
end_define

begin_define
define|#
directive|define
name|ATOM_ENCODER_OBJECT_TABLE
value|ATOM_OBJECT_TABLE
end_define

begin_define
define|#
directive|define
name|ATOM_CONNECTOR_OBJECT_TABLE
value|ATOM_OBJECT_TABLE
end_define

begin_comment
comment|//New device naming, remove them when both DAL/VBIOS is ready
end_comment

begin_define
define|#
directive|define
name|DFP2I_OUTPUT_CONTROL_PARAMETERS
value|CRT1_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|DFP2I_OUTPUT_CONTROL_PS_ALLOCATION
value|DFP2I_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|DFP1X_OUTPUT_CONTROL_PARAMETERS
value|CRT1_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|DFP1X_OUTPUT_CONTROL_PS_ALLOCATION
value|DFP1X_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|DFP1I_OUTPUT_CONTROL_PARAMETERS
value|DFP1_OUTPUT_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|DFP1I_OUTPUT_CONTROL_PS_ALLOCATION
value|DFP1_OUTPUT_CONTROL_PS_ALLOCATION
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP1I_SUPPORT
value|ATOM_DEVICE_DFP1_SUPPORT
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP1X_SUPPORT
value|ATOM_DEVICE_DFP2_SUPPORT
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP1I_INDEX
value|ATOM_DEVICE_DFP1_INDEX
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP1X_INDEX
value|ATOM_DEVICE_DFP2_INDEX
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP2I_INDEX
value|0x00000009
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_DFP2I_SUPPORT
value|(0x1L<< ATOM_DEVICE_DFP2I_INDEX)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP1I
value|ATOM_S0_DFP1
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP1X
value|ATOM_S0_DFP2
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP2I
value|0x00200000L
end_define

begin_define
define|#
directive|define
name|ATOM_S0_DFP2Ib2
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP1I_DPMS_STATE
value|ATOM_S2_DFP1_DPMS_STATE
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP1X_DPMS_STATE
value|ATOM_S2_DFP2_DPMS_STATE
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP2I_DPMS_STATE
value|0x02000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP2I_DPMS_STATEb3
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP2I_ACTIVEb1
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP1I_ACTIVE
value|ATOM_S3_DFP1_ACTIVE
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP1X_ACTIVE
value|ATOM_S3_DFP2_ACTIVE
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP2I_ACTIVE
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP1I_CRTC_ACTIVE
value|ATOM_S3_DFP1_CRTC_ACTIVE
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP1X_CRTC_ACTIVE
value|ATOM_S3_DFP2_CRTC_ACTIVE
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP2I_CRTC_ACTIVE
value|0x02000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_DFP2I_CRTC_ACTIVEb3
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP2Ib1
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S5_DOS_REQ_DFP2I
value|0x0200
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP1I
value|ATOM_S6_ACC_REQ_DFP1
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP1X
value|ATOM_S6_ACC_REQ_DFP2
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP2Ib3
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_DFP2I
value|0x02000000L
end_define

begin_define
define|#
directive|define
name|TMDS1XEncoderControl
value|DVOEncoderControl
end_define

begin_define
define|#
directive|define
name|DFP1XOutputControl
value|DVOOutputControl
end_define

begin_define
define|#
directive|define
name|ExternalDFPOutputControl
value|DFP1XOutputControl
end_define

begin_define
define|#
directive|define
name|EnableExternalTMDS_Encoder
value|TMDS1XEncoderControl
end_define

begin_define
define|#
directive|define
name|DFP1IOutputControl
value|TMDSAOutputControl
end_define

begin_define
define|#
directive|define
name|DFP2IOutputControl
value|LVTMAOutputControl
end_define

begin_define
define|#
directive|define
name|DAC1_ENCODER_CONTROL_PARAMETERS
value|DAC_ENCODER_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|DAC1_ENCODER_CONTROL_PS_ALLOCATION
value|DAC_ENCODER_CONTROL_PS_ALLOCATION
end_define

begin_define
define|#
directive|define
name|DAC2_ENCODER_CONTROL_PARAMETERS
value|DAC_ENCODER_CONTROL_PARAMETERS
end_define

begin_define
define|#
directive|define
name|DAC2_ENCODER_CONTROL_PS_ALLOCATION
value|DAC_ENCODER_CONTROL_PS_ALLOCATION
end_define

begin_define
define|#
directive|define
name|ucDac1Standard
value|ucDacStandard
end_define

begin_define
define|#
directive|define
name|ucDac2Standard
value|ucDacStandard
end_define

begin_define
define|#
directive|define
name|TMDS1EncoderControl
value|TMDSAEncoderControl
end_define

begin_define
define|#
directive|define
name|TMDS2EncoderControl
value|LVTMAEncoderControl
end_define

begin_define
define|#
directive|define
name|DFP1OutputControl
value|TMDSAOutputControl
end_define

begin_define
define|#
directive|define
name|DFP2OutputControl
value|LVTMAOutputControl
end_define

begin_define
define|#
directive|define
name|CRT1OutputControl
value|DAC1OutputControl
end_define

begin_define
define|#
directive|define
name|CRT2OutputControl
value|DAC2OutputControl
end_define

begin_comment
comment|//These two lines will be removed for sure in a few days, will follow up with Michael V.
end_comment

begin_define
define|#
directive|define
name|EnableLVDS_SS
value|EnableSpreadSpectrumOnPPLL
end_define

begin_define
define|#
directive|define
name|ENABLE_LVDS_SS_PARAMETERS_V3
value|ENABLE_SPREAD_SPECTRUM_ON_PPLL
end_define

begin_comment
comment|//#define ATOM_S2_CRT1_DPMS_STATE         0x00010000L
end_comment

begin_comment
comment|//#define ATOM_S2_LCD1_DPMS_STATE	        ATOM_S2_CRT1_DPMS_STATE
end_comment

begin_comment
comment|//#define ATOM_S2_TV1_DPMS_STATE          ATOM_S2_CRT1_DPMS_STATE
end_comment

begin_comment
comment|//#define ATOM_S2_DFP1_DPMS_STATE         ATOM_S2_CRT1_DPMS_STATE
end_comment

begin_comment
comment|//#define ATOM_S2_CRT2_DPMS_STATE         ATOM_S2_CRT1_DPMS_STATE
end_comment

begin_define
define|#
directive|define
name|ATOM_S6_ACC_REQ_TV2
value|0x00400000L
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_TV2_INDEX
value|0x00000006
end_define

begin_define
define|#
directive|define
name|ATOM_DEVICE_TV2_SUPPORT
value|(0x1L<< ATOM_DEVICE_TV2_INDEX)
end_define

begin_define
define|#
directive|define
name|ATOM_S0_TV2
value|0x00100000L
end_define

begin_define
define|#
directive|define
name|ATOM_S3_TV2_ACTIVE
value|ATOM_S3_DFP6_ACTIVE
end_define

begin_define
define|#
directive|define
name|ATOM_S3_TV2_CRTC_ACTIVE
value|ATOM_S3_DFP6_CRTC_ACTIVE
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATOM_S2_CRT1_DPMS_STATE
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_LCD1_DPMS_STATE
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_TV1_DPMS_STATE
value|0x00040000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP1_DPMS_STATE
value|0x00080000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_CRT2_DPMS_STATE
value|0x00100000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_LCD2_DPMS_STATE
value|0x00200000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_TV2_DPMS_STATE
value|0x00400000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP2_DPMS_STATE
value|0x00800000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_CV_DPMS_STATE
value|0x01000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP3_DPMS_STATE
value|0x02000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP4_DPMS_STATE
value|0x04000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP5_DPMS_STATE
value|0x08000000L
end_define

begin_define
define|#
directive|define
name|ATOM_S2_CRT1_DPMS_STATEb2
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S2_LCD1_DPMS_STATEb2
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S2_TV1_DPMS_STATEb2
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP1_DPMS_STATEb2
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S2_CRT2_DPMS_STATEb2
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_S2_LCD2_DPMS_STATEb2
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S2_TV2_DPMS_STATEb2
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP2_DPMS_STATEb2
value|0x80
end_define

begin_define
define|#
directive|define
name|ATOM_S2_CV_DPMS_STATEb3
value|0x01
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP3_DPMS_STATEb3
value|0x02
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP4_DPMS_STATEb3
value|0x04
end_define

begin_define
define|#
directive|define
name|ATOM_S2_DFP5_DPMS_STATEb3
value|0x08
end_define

begin_define
define|#
directive|define
name|ATOM_S3_ASIC_GUI_ENGINE_HUNGb3
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_S3_ALLOW_FAST_PWR_SWITCHb3
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_S3_RQST_GPU_USE_MIN_PWRb3
value|0x80
end_define

begin_comment
comment|/*********************************************************************************/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|// BIOS data must use byte aligment
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// AMD ACPI Table
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|ULONG
name|Signature
decl_stmt|;
name|ULONG
name|TableLength
decl_stmt|;
comment|//Length
name|UCHAR
name|Revision
decl_stmt|;
name|UCHAR
name|Checksum
decl_stmt|;
name|UCHAR
name|OemId
index|[
literal|6
index|]
decl_stmt|;
name|UCHAR
name|OemTableId
index|[
literal|8
index|]
decl_stmt|;
comment|//UINT64  OemTableId;
name|ULONG
name|OemRevision
decl_stmt|;
name|ULONG
name|CreatorId
decl_stmt|;
name|ULONG
name|CreatorRevision
decl_stmt|;
block|}
name|AMD_ACPI_DESCRIPTION_HEADER
typedef|;
end_typedef

begin_comment
comment|/* //EFI_ACPI_DESCRIPTION_HEADER from AcpiCommon.h typedef struct {   UINT32  Signature;       //0x0   UINT32  Length;          //0x4   UINT8   Revision;        //0x8   UINT8   Checksum;        //0x9   UINT8   OemId[6];        //0xA   UINT64  OemTableId;      //0x10   UINT32  OemRevision;     //0x18   UINT32  CreatorId;       //0x1C   UINT32  CreatorRevision; //0x20 }EFI_ACPI_DESCRIPTION_HEADER; */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|AMD_ACPI_DESCRIPTION_HEADER
name|SHeader
decl_stmt|;
name|UCHAR
name|TableUUID
index|[
literal|16
index|]
decl_stmt|;
comment|//0x24
name|ULONG
name|VBIOSImageOffset
decl_stmt|;
comment|//0x34. Offset to the first GOP_VBIOS_CONTENT block from the beginning of the stucture.
name|ULONG
name|Lib1ImageOffset
decl_stmt|;
comment|//0x38. Offset to the first GOP_LIB1_CONTENT block from the beginning of the stucture.
name|ULONG
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
comment|//0x3C
block|}
name|UEFI_ACPI_VFCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ULONG
name|PCIBus
decl_stmt|;
comment|//0x4C
name|ULONG
name|PCIDevice
decl_stmt|;
comment|//0x50
name|ULONG
name|PCIFunction
decl_stmt|;
comment|//0x54
name|USHORT
name|VendorID
decl_stmt|;
comment|//0x58
name|USHORT
name|DeviceID
decl_stmt|;
comment|//0x5A
name|USHORT
name|SSVID
decl_stmt|;
comment|//0x5C
name|USHORT
name|SSID
decl_stmt|;
comment|//0x5E
name|ULONG
name|Revision
decl_stmt|;
comment|//0x60
name|ULONG
name|ImageLength
decl_stmt|;
comment|//0x64
block|}
name|VFCT_IMAGE_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|VFCT_IMAGE_HEADER
name|VbiosHeader
decl_stmt|;
name|UCHAR
name|VbiosContent
index|[
literal|1
index|]
decl_stmt|;
block|}
name|GOP_VBIOS_CONTENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|VFCT_IMAGE_HEADER
name|Lib1Header
decl_stmt|;
name|UCHAR
name|Lib1Content
index|[
literal|1
index|]
decl_stmt|;
block|}
name|GOP_LIB1_CONTENT
typedef|;
end_typedef

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

begin_comment
comment|/* _ATOMBIOS_H */
end_comment

end_unit

