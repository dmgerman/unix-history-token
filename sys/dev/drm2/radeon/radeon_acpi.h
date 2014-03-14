begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2012 Advanced Micro Devices, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|RADEON_ACPI_H
end_ifndef

begin_define
define|#
directive|define
name|RADEON_ACPI_H
end_define

begin_struct_decl
struct_decl|struct
name|radeon_device
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|radeon_atif_handler
parameter_list|(
name|struct
name|radeon_device
modifier|*
name|rdev
parameter_list|,
name|UINT32
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* AMD hw uses four ACPI control methods:  * 1. ATIF  * ARG0: (ACPI_INTEGER) function code  * ARG1: (ACPI_BUFFER) parameter buffer, 256 bytes  * OUTPUT: (ACPI_BUFFER) output buffer, 256 bytes  * ATIF provides an entry point for the gfx driver to interact with the sbios.  * The AMD ACPI notification mechanism uses Notify (VGA, 0x81) or a custom  * notification. Which notification is used as indicated by the ATIF Control  * Method GET_SYSTEM_PARAMETERS. When the driver receives Notify (VGA, 0x81) or  * a custom notification it invokes ATIF Control Method GET_SYSTEM_BIOS_REQUESTS  * to identify pending System BIOS requests and associated parameters. For  * example, if one of the pending requests is DISPLAY_SWITCH_REQUEST, the driver  * will perform display device detection and invoke ATIF Control Method  * SELECT_ACTIVE_DISPLAYS.  *  * 2. ATPX  * ARG0: (ACPI_INTEGER) function code  * ARG1: (ACPI_BUFFER) parameter buffer, 256 bytes  * OUTPUT: (ACPI_BUFFER) output buffer, 256 bytes  * ATPX methods are used on PowerXpress systems to handle mux switching and  * discrete GPU power control.  *  * 3. ATRM  * ARG0: (ACPI_INTEGER) offset of vbios rom data  * ARG1: (ACPI_BUFFER) size of the buffer to fill (up to 4K).  * OUTPUT: (ACPI_BUFFER) output buffer  * ATRM provides an interfacess to access the discrete GPU vbios image on  * PowerXpress systems with multiple GPUs.  *  * 4. ATCS  * ARG0: (ACPI_INTEGER) function code  * ARG1: (ACPI_BUFFER) parameter buffer, 256 bytes  * OUTPUT: (ACPI_BUFFER) output buffer, 256 bytes  * ATCS provides an interface to AMD chipset specific functionality.  *  */
end_comment

begin_comment
comment|/* ATIF */
end_comment

begin_define
define|#
directive|define
name|ATIF_FUNCTION_VERIFY_INTERFACE
value|0x0
end_define

begin_comment
comment|/* ARG0: ATIF_FUNCTION_VERIFY_INTERFACE  * ARG1: none  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * WORD  - version  * DWORD - supported notifications mask  * DWORD - supported functions bit vector  */
end_comment

begin_comment
comment|/* Notifications mask */
end_comment

begin_define
define|#
directive|define
name|ATIF_DISPLAY_SWITCH_REQUEST_SUPPORTED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATIF_EXPANSION_MODE_CHANGE_REQUEST_SUPPORTED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATIF_THERMAL_STATE_CHANGE_REQUEST_SUPPORTED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATIF_FORCED_POWER_STATE_CHANGE_REQUEST_SUPPORTED
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATIF_SYSTEM_POWER_SOURCE_CHANGE_REQUEST_SUPPORTED
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATIF_DISPLAY_CONF_CHANGE_REQUEST_SUPPORTED
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ATIF_PX_GFX_SWITCH_REQUEST_SUPPORTED
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ATIF_PANEL_BRIGHTNESS_CHANGE_REQUEST_SUPPORTED
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATIF_DGPU_DISPLAY_EVENT_SUPPORTED
value|(1<< 8)
end_define

begin_comment
comment|/* supported functions vector */
end_comment

begin_define
define|#
directive|define
name|ATIF_GET_SYSTEM_PARAMETERS_SUPPORTED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATIF_GET_SYSTEM_BIOS_REQUESTS_SUPPORTED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATIF_SELECT_ACTIVE_DISPLAYS_SUPPORTED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATIF_GET_LID_STATE_SUPPORTED
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATIF_GET_TV_STANDARD_FROM_CMOS_SUPPORTED
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATIF_SET_TV_STANDARD_IN_CMOS_SUPPORTED
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ATIF_GET_PANEL_EXPANSION_MODE_FROM_CMOS_SUPPORTED
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ATIF_SET_PANEL_EXPANSION_MODE_IN_CMOS_SUPPORTED
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATIF_TEMPERATURE_CHANGE_NOTIFICATION_SUPPORTED
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|ATIF_GET_GRAPHICS_DEVICE_TYPES_SUPPORTED
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|ATIF_FUNCTION_GET_SYSTEM_PARAMETERS
value|0x1
end_define

begin_comment
comment|/* ARG0: ATIF_FUNCTION_GET_SYSTEM_PARAMETERS  * ARG1: none  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * DWORD - valid flags mask  * DWORD - flags  *  * OR  *  * WORD  - structure size in bytes (includes size field)  * DWORD - valid flags mask  * DWORD - flags  * BYTE  - notify command code  *  * flags  * bits 1:0:  * 0 - Notify(VGA, 0x81) is not used for notification  * 1 - Notify(VGA, 0x81) is used for notification  * 2 - Notify(VGA, n) is used for notification where  * n (0xd0-0xd9) is specified in notify command code.  * bit 2:  * 1 - lid changes not reported though int10  */
end_comment

begin_define
define|#
directive|define
name|ATIF_FUNCTION_GET_SYSTEM_BIOS_REQUESTS
value|0x2
end_define

begin_comment
comment|/* ARG0: ATIF_FUNCTION_GET_SYSTEM_BIOS_REQUESTS  * ARG1: none  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * DWORD - pending sbios requests  * BYTE  - panel expansion mode  * BYTE  - thermal state: target gfx controller  * BYTE  - thermal state: state id (0: exit state, non-0: state)  * BYTE  - forced power state: target gfx controller  * BYTE  - forced power state: state id  * BYTE  - system power source  * BYTE  - panel backlight level (0-255)  */
end_comment

begin_comment
comment|/* pending sbios requests */
end_comment

begin_define
define|#
directive|define
name|ATIF_DISPLAY_SWITCH_REQUEST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATIF_EXPANSION_MODE_CHANGE_REQUEST
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATIF_THERMAL_STATE_CHANGE_REQUEST
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATIF_FORCED_POWER_STATE_CHANGE_REQUEST
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATIF_SYSTEM_POWER_SOURCE_CHANGE_REQUEST
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATIF_DISPLAY_CONF_CHANGE_REQUEST
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ATIF_PX_GFX_SWITCH_REQUEST
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ATIF_PANEL_BRIGHTNESS_CHANGE_REQUEST
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATIF_DGPU_DISPLAY_EVENT
value|(1<< 8)
end_define

begin_comment
comment|/* panel expansion mode */
end_comment

begin_define
define|#
directive|define
name|ATIF_PANEL_EXPANSION_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|ATIF_PANEL_EXPANSION_FULL
value|1
end_define

begin_define
define|#
directive|define
name|ATIF_PANEL_EXPANSION_ASPECT
value|2
end_define

begin_comment
comment|/* target gfx controller */
end_comment

begin_define
define|#
directive|define
name|ATIF_TARGET_GFX_SINGLE
value|0
end_define

begin_define
define|#
directive|define
name|ATIF_TARGET_GFX_PX_IGPU
value|1
end_define

begin_define
define|#
directive|define
name|ATIF_TARGET_GFX_PX_DGPU
value|2
end_define

begin_comment
comment|/* system power source */
end_comment

begin_define
define|#
directive|define
name|ATIF_POWER_SOURCE_AC
value|1
end_define

begin_define
define|#
directive|define
name|ATIF_POWER_SOURCE_DC
value|2
end_define

begin_define
define|#
directive|define
name|ATIF_POWER_SOURCE_RESTRICTED_AC_1
value|3
end_define

begin_define
define|#
directive|define
name|ATIF_POWER_SOURCE_RESTRICTED_AC_2
value|4
end_define

begin_define
define|#
directive|define
name|ATIF_FUNCTION_SELECT_ACTIVE_DISPLAYS
value|0x3
end_define

begin_comment
comment|/* ARG0: ATIF_FUNCTION_SELECT_ACTIVE_DISPLAYS  * ARG1:  * WORD  - structure size in bytes (includes size field)  * WORD  - selected displays  * WORD  - connected displays  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * WORD  - selected displays  */
end_comment

begin_define
define|#
directive|define
name|ATIF_LCD1
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATIF_CRT1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATIF_TV
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATIF_DFP1
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATIF_CRT2
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATIF_LCD2
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ATIF_DFP2
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATIF_CV
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|ATIF_DFP3
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|ATIF_DFP4
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|ATIF_DFP5
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|ATIF_DFP6
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|ATIF_FUNCTION_GET_LID_STATE
value|0x4
end_define

begin_comment
comment|/* ARG0: ATIF_FUNCTION_GET_LID_STATE  * ARG1: none  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * BYTE  - lid state (0: open, 1: closed)  *  * GET_LID_STATE only works at boot and resume, for general lid  * status, use the kernel provided status  */
end_comment

begin_define
define|#
directive|define
name|ATIF_FUNCTION_GET_TV_STANDARD_FROM_CMOS
value|0x5
end_define

begin_comment
comment|/* ARG0: ATIF_FUNCTION_GET_TV_STANDARD_FROM_CMOS  * ARG1: none  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * BYTE  - 0  * BYTE  - TV standard  */
end_comment

begin_define
define|#
directive|define
name|ATIF_TV_STD_NTSC
value|0
end_define

begin_define
define|#
directive|define
name|ATIF_TV_STD_PAL
value|1
end_define

begin_define
define|#
directive|define
name|ATIF_TV_STD_PALM
value|2
end_define

begin_define
define|#
directive|define
name|ATIF_TV_STD_PAL60
value|3
end_define

begin_define
define|#
directive|define
name|ATIF_TV_STD_NTSCJ
value|4
end_define

begin_define
define|#
directive|define
name|ATIF_TV_STD_PALCN
value|5
end_define

begin_define
define|#
directive|define
name|ATIF_TV_STD_PALN
value|6
end_define

begin_define
define|#
directive|define
name|ATIF_TV_STD_SCART_RGB
value|9
end_define

begin_define
define|#
directive|define
name|ATIF_FUNCTION_SET_TV_STANDARD_IN_CMOS
value|0x6
end_define

begin_comment
comment|/* ARG0: ATIF_FUNCTION_SET_TV_STANDARD_IN_CMOS  * ARG1:  * WORD  - structure size in bytes (includes size field)  * BYTE  - 0  * BYTE  - TV standard  * OUTPUT: none  */
end_comment

begin_define
define|#
directive|define
name|ATIF_FUNCTION_GET_PANEL_EXPANSION_MODE_FROM_CMOS
value|0x7
end_define

begin_comment
comment|/* ARG0: ATIF_FUNCTION_GET_PANEL_EXPANSION_MODE_FROM_CMOS  * ARG1: none  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * BYTE  - panel expansion mode  */
end_comment

begin_define
define|#
directive|define
name|ATIF_FUNCTION_SET_PANEL_EXPANSION_MODE_IN_CMOS
value|0x8
end_define

begin_comment
comment|/* ARG0: ATIF_FUNCTION_SET_PANEL_EXPANSION_MODE_IN_CMOS  * ARG1:  * WORD  - structure size in bytes (includes size field)  * BYTE  - panel expansion mode  * OUTPUT: none  */
end_comment

begin_define
define|#
directive|define
name|ATIF_FUNCTION_TEMPERATURE_CHANGE_NOTIFICATION
value|0xD
end_define

begin_comment
comment|/* ARG0: ATIF_FUNCTION_TEMPERATURE_CHANGE_NOTIFICATION  * ARG1:  * WORD  - structure size in bytes (includes size field)  * WORD  - gfx controller id  * BYTE  - current temperature (degress Celsius)  * OUTPUT: none  */
end_comment

begin_define
define|#
directive|define
name|ATIF_FUNCTION_GET_GRAPHICS_DEVICE_TYPES
value|0xF
end_define

begin_comment
comment|/* ARG0: ATIF_FUNCTION_GET_GRAPHICS_DEVICE_TYPES  * ARG1: none  * OUTPUT:  * WORD  - number of gfx devices  * WORD  - device structure size in bytes (excludes device size field)  * DWORD - flags         \  * WORD  - bus number     } repeated structure  * WORD  - device number /  */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|ATIF_PX_REMOVABLE_GRAPHICS_DEVICE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATIF_XGP_PORT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATIF_VGA_ENABLED_GRAPHICS_DEVICE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATIF_XGP_PORT_IN_DOCK
value|(1<< 3)
end_define

begin_comment
comment|/* ATPX */
end_comment

begin_define
define|#
directive|define
name|ATPX_FUNCTION_VERIFY_INTERFACE
value|0x0
end_define

begin_comment
comment|/* ARG0: ATPX_FUNCTION_VERIFY_INTERFACE  * ARG1: none  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * WORD  - version  * DWORD - supported functions bit vector  */
end_comment

begin_comment
comment|/* supported functions vector */
end_comment

begin_define
define|#
directive|define
name|ATPX_GET_PX_PARAMETERS_SUPPORTED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATPX_POWER_CONTROL_SUPPORTED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATPX_DISPLAY_MUX_CONTROL_SUPPORTED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATPX_I2C_MUX_CONTROL_SUPPORTED
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATPX_GRAPHICS_DEVICE_SWITCH_START_NOTIFICATION_SUPPORTED
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATPX_GRAPHICS_DEVICE_SWITCH_END_NOTIFICATION_SUPPORTED
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ATPX_GET_DISPLAY_CONNECTORS_MAPPING_SUPPORTED
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATPX_GET_DISPLAY_DETECTION_PORTS_SUPPORTED
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|ATPX_FUNCTION_GET_PX_PARAMETERS
value|0x1
end_define

begin_comment
comment|/* ARG0: ATPX_FUNCTION_GET_PX_PARAMETERS  * ARG1: none  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * DWORD - valid flags mask  * DWORD - flags  */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|ATPX_LVDS_I2C_AVAILABLE_TO_BOTH_GPUS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATPX_CRT1_I2C_AVAILABLE_TO_BOTH_GPUS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATPX_DVI1_I2C_AVAILABLE_TO_BOTH_GPUS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATPX_CRT1_RGB_SIGNAL_MUXED
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATPX_TV_SIGNAL_MUXED
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATPX_DFP_SIGNAL_MUXED
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ATPX_SEPARATE_MUX_FOR_I2C
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ATPX_DYNAMIC_PX_SUPPORTED
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATPX_ACF_NOT_SUPPORTED
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|ATPX_FIXED_NOT_SUPPORTED
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|ATPX_DYNAMIC_DGPU_POWER_OFF_SUPPORTED
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|ATPX_DGPU_REQ_POWER_FOR_DISPLAYS
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|ATPX_FUNCTION_POWER_CONTROL
value|0x2
end_define

begin_comment
comment|/* ARG0: ATPX_FUNCTION_POWER_CONTROL  * ARG1:  * WORD  - structure size in bytes (includes size field)  * BYTE  - dGPU power state (0: power off, 1: power on)  * OUTPUT: none  */
end_comment

begin_define
define|#
directive|define
name|ATPX_FUNCTION_DISPLAY_MUX_CONTROL
value|0x3
end_define

begin_comment
comment|/* ARG0: ATPX_FUNCTION_DISPLAY_MUX_CONTROL  * ARG1:  * WORD  - structure size in bytes (includes size field)  * WORD  - display mux control (0: iGPU, 1: dGPU)  * OUTPUT: none  */
end_comment

begin_define
define|#
directive|define
name|ATPX_INTEGRATED_GPU
value|0
end_define

begin_define
define|#
directive|define
name|ATPX_DISCRETE_GPU
value|1
end_define

begin_define
define|#
directive|define
name|ATPX_FUNCTION_I2C_MUX_CONTROL
value|0x4
end_define

begin_comment
comment|/* ARG0: ATPX_FUNCTION_I2C_MUX_CONTROL  * ARG1:  * WORD  - structure size in bytes (includes size field)  * WORD  - i2c/aux/hpd mux control (0: iGPU, 1: dGPU)  * OUTPUT: none  */
end_comment

begin_define
define|#
directive|define
name|ATPX_FUNCTION_GRAPHICS_DEVICE_SWITCH_START_NOTIFICATION
value|0x5
end_define

begin_comment
comment|/* ARG0: ATPX_FUNCTION_GRAPHICS_DEVICE_SWITCH_START_NOTIFICATION  * ARG1:  * WORD  - structure size in bytes (includes size field)  * WORD  - target gpu (0: iGPU, 1: dGPU)  * OUTPUT: none  */
end_comment

begin_define
define|#
directive|define
name|ATPX_FUNCTION_GRAPHICS_DEVICE_SWITCH_END_NOTIFICATION
value|0x6
end_define

begin_comment
comment|/* ARG0: ATPX_FUNCTION_GRAPHICS_DEVICE_SWITCH_END_NOTIFICATION  * ARG1:  * WORD  - structure size in bytes (includes size field)  * WORD  - target gpu (0: iGPU, 1: dGPU)  * OUTPUT: none  */
end_comment

begin_define
define|#
directive|define
name|ATPX_FUNCTION_GET_DISPLAY_CONNECTORS_MAPPING
value|0x8
end_define

begin_comment
comment|/* ARG0: ATPX_FUNCTION_GET_DISPLAY_CONNECTORS_MAPPING  * ARG1: none  * OUTPUT:  * WORD  - number of display connectors  * WORD  - connector structure size in bytes (excludes connector size field)  * BYTE  - flags                                                     \  * BYTE  - ATIF display vector bit position                           } repeated  * BYTE  - adapter id (0: iGPU, 1-n: dGPU ordered by pcie bus number) } structure  * WORD  - connector ACPI id                                         /  */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|ATPX_DISPLAY_OUTPUT_SUPPORTED_BY_ADAPTER_ID_DEVICE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATPX_DISPLAY_HPD_SUPPORTED_BY_ADAPTER_ID_DEVICE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATPX_DISPLAY_I2C_SUPPORTED_BY_ADAPTER_ID_DEVICE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATPX_FUNCTION_GET_DISPLAY_DETECTION_PORTS
value|0x9
end_define

begin_comment
comment|/* ARG0: ATPX_FUNCTION_GET_DISPLAY_DETECTION_PORTS  * ARG1: none  * OUTPUT:  * WORD  - number of HPD/DDC ports  * WORD  - port structure size in bytes (excludes port size field)  * BYTE  - ATIF display vector bit position \  * BYTE  - hpd id                            } reapeated structure  * BYTE  - ddc id                           /  *  * available on A+A systems only  */
end_comment

begin_comment
comment|/* hpd id */
end_comment

begin_define
define|#
directive|define
name|ATPX_HPD_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ATPX_HPD1
value|1
end_define

begin_define
define|#
directive|define
name|ATPX_HPD2
value|2
end_define

begin_define
define|#
directive|define
name|ATPX_HPD3
value|3
end_define

begin_define
define|#
directive|define
name|ATPX_HPD4
value|4
end_define

begin_define
define|#
directive|define
name|ATPX_HPD5
value|5
end_define

begin_define
define|#
directive|define
name|ATPX_HPD6
value|6
end_define

begin_comment
comment|/* ddc id */
end_comment

begin_define
define|#
directive|define
name|ATPX_DDC_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ATPX_DDC1
value|1
end_define

begin_define
define|#
directive|define
name|ATPX_DDC2
value|2
end_define

begin_define
define|#
directive|define
name|ATPX_DDC3
value|3
end_define

begin_define
define|#
directive|define
name|ATPX_DDC4
value|4
end_define

begin_define
define|#
directive|define
name|ATPX_DDC5
value|5
end_define

begin_define
define|#
directive|define
name|ATPX_DDC6
value|6
end_define

begin_define
define|#
directive|define
name|ATPX_DDC7
value|7
end_define

begin_define
define|#
directive|define
name|ATPX_DDC8
value|8
end_define

begin_comment
comment|/* ATCS */
end_comment

begin_define
define|#
directive|define
name|ATCS_FUNCTION_VERIFY_INTERFACE
value|0x0
end_define

begin_comment
comment|/* ARG0: ATCS_FUNCTION_VERIFY_INTERFACE  * ARG1: none  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * WORD  - version  * DWORD - supported functions bit vector  */
end_comment

begin_comment
comment|/* supported functions vector */
end_comment

begin_define
define|#
directive|define
name|ATCS_GET_EXTERNAL_STATE_SUPPORTED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATCS_PCIE_PERFORMANCE_REQUEST_SUPPORTED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATCS_PCIE_DEVICE_READY_NOTIFICATION_SUPPORTED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATCS_SET_PCIE_BUS_WIDTH_SUPPORTED
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATCS_FUNCTION_GET_EXTERNAL_STATE
value|0x1
end_define

begin_comment
comment|/* ARG0: ATCS_FUNCTION_GET_EXTERNAL_STATE  * ARG1: none  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * DWORD - valid flags mask  * DWORD - flags (0: undocked, 1: docked)  */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|ATCS_DOCKED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATCS_FUNCTION_PCIE_PERFORMANCE_REQUEST
value|0x2
end_define

begin_comment
comment|/* ARG0: ATCS_FUNCTION_PCIE_PERFORMANCE_REQUEST  * ARG1:  * WORD  - structure size in bytes (includes size field)  * WORD  - client id (bit 2-0: func num, 7-3: dev num, 15-8: bus num)  * WORD  - valid flags mask  * WORD  - flags  * BYTE  - request type  * BYTE  - performance request  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * BYTE  - return value  */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|ATCS_ADVERTISE_CAPS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATCS_WAIT_FOR_COMPLETION
value|(1<< 1)
end_define

begin_comment
comment|/* request type */
end_comment

begin_define
define|#
directive|define
name|ATCS_PCIE_LINK_SPEED
value|1
end_define

begin_comment
comment|/* performance request */
end_comment

begin_define
define|#
directive|define
name|ATCS_REMOVE
value|0
end_define

begin_define
define|#
directive|define
name|ATCS_FORCE_LOW_POWER
value|1
end_define

begin_define
define|#
directive|define
name|ATCS_PERF_LEVEL_1
value|2
end_define

begin_comment
comment|/* PCIE Gen 1 */
end_comment

begin_define
define|#
directive|define
name|ATCS_PERF_LEVEL_2
value|3
end_define

begin_comment
comment|/* PCIE Gen 2 */
end_comment

begin_define
define|#
directive|define
name|ATCS_PERF_LEVEL_3
value|4
end_define

begin_comment
comment|/* PCIE Gen 3 */
end_comment

begin_comment
comment|/* return value */
end_comment

begin_define
define|#
directive|define
name|ATCS_REQUEST_REFUSED
value|1
end_define

begin_define
define|#
directive|define
name|ATCS_REQUEST_COMPLETE
value|2
end_define

begin_define
define|#
directive|define
name|ATCS_REQUEST_IN_PROGRESS
value|3
end_define

begin_define
define|#
directive|define
name|ATCS_FUNCTION_PCIE_DEVICE_READY_NOTIFICATION
value|0x3
end_define

begin_comment
comment|/* ARG0: ATCS_FUNCTION_PCIE_DEVICE_READY_NOTIFICATION  * ARG1: none  * OUTPUT: none  */
end_comment

begin_define
define|#
directive|define
name|ATCS_FUNCTION_SET_PCIE_BUS_WIDTH
value|0x4
end_define

begin_comment
comment|/* ARG0: ATCS_FUNCTION_SET_PCIE_BUS_WIDTH  * ARG1:  * WORD  - structure size in bytes (includes size field)  * WORD  - client id (bit 2-0: func num, 7-3: dev num, 15-8: bus num)  * BYTE  - number of active lanes  * OUTPUT:  * WORD  - structure size in bytes (includes size field)  * BYTE  - number of active lanes  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

