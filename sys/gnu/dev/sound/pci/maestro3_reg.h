begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  *      ESS Technology allegro audio driver.  *  *      Copyright (C) 1992-2000  Don Kim (don.kim@esstech.com)  *  *      This program is free software; you can redistribute it and/or modify  *      it under the terms of the GNU General Public License as published by  *      the Free Software Foundation; either version 2 of the License, or  *      (at your option) any later version.  *  *      This program is distributed in the hope that it will be useful,  *      but WITHOUT ANY WARRANTY; without even the implied warranty of  *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *      GNU General Public License for more details.  *  *      You should have received a copy of the GNU General Public License  *      along with this program; if not, write to the Free Software  *      Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  *  *      Hacked for the maestro3 driver by zab  */
end_comment

begin_comment
comment|/* Allegro PCI configuration registers */
end_comment

begin_define
define|#
directive|define
name|PCI_LEGACY_AUDIO_CTRL
value|0x40
end_define

begin_define
define|#
directive|define
name|SOUND_BLASTER_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FM_SYNTHESIS_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GAME_PORT_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MPU401_IO_ENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MPU401_IRQ_ENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ALIAS_10BIT_IO
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SB_DMA_MASK
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|SB_DMA_0
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SB_DMA_1
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SB_DMA_R
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SB_DMA_3
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|SB_IRQ_MASK
value|0x00000700
end_define

begin_define
define|#
directive|define
name|SB_IRQ_5
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SB_IRQ_7
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SB_IRQ_9
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SB_IRQ_10
value|0x00000300
end_define

begin_define
define|#
directive|define
name|MIDI_IRQ_MASK
value|0x00003800
end_define

begin_define
define|#
directive|define
name|SERIAL_IRQ_ENABLE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DISABLE_LEGACY
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PCI_ALLEGRO_CONFIG
value|0x50
end_define

begin_define
define|#
directive|define
name|SB_ADDR_240
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MPU_ADDR_MASK
value|0x00000018
end_define

begin_define
define|#
directive|define
name|MPU_ADDR_330
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MPU_ADDR_300
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MPU_ADDR_320
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MPU_ADDR_340
value|0x00000018
end_define

begin_define
define|#
directive|define
name|USE_PCI_TIMING
value|0x00000040
end_define

begin_define
define|#
directive|define
name|POSTED_WRITE_ENABLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DMA_POLICY_MASK
value|0x00000700
end_define

begin_define
define|#
directive|define
name|DMA_DDMA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DMA_TDMA
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DMA_PCPCI
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DMA_WBDMA16
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DMA_WBDMA4
value|0x00000500
end_define

begin_define
define|#
directive|define
name|DMA_WBDMA2
value|0x00000600
end_define

begin_define
define|#
directive|define
name|DMA_WBDMA1
value|0x00000700
end_define

begin_define
define|#
directive|define
name|DMA_SAFE_GUARD
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HI_PERF_GP_ENABLE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PIC_SNOOP_MODE_0
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PIC_SNOOP_MODE_1
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SOUNDBLASTER_IRQ_MASK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|RING_IN_ENABLE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SPDIF_TEST_MODE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CLK_MULT_MODE_SELECT_2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|EEPROM_WRITE_ENABLE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|CODEC_DIR_IN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HV_BUTTON_FROM_GD
value|0x00200000
end_define

begin_define
define|#
directive|define
name|REDUCED_DEBOUNCE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|HV_CTRL_ENABLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SPDIF_ENABLE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SELECT
value|0x06000000
end_define

begin_define
define|#
directive|define
name|CLK_DIV_BY_48
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CLK_DIV_BY_49
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CLK_DIV_BY_50
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CLK_DIV_RESERVED
value|0x06000000
end_define

begin_define
define|#
directive|define
name|PM_CTRL_ENABLE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CLK_MULT_MODE_SELECT
value|0x30000000
end_define

begin_define
define|#
directive|define
name|CLK_MULT_MODE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|CLK_MULT_MODE_0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CLK_MULT_MODE_1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CLK_MULT_MODE_2
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CLK_MULT_MODE_3
value|0x30000000
end_define

begin_define
define|#
directive|define
name|INT_CLK_SELECT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|INT_CLK_MULT_RESET
value|0x80000000
end_define

begin_comment
comment|/* M3 */
end_comment

begin_define
define|#
directive|define
name|INT_CLK_SRC_NOT_PCI
value|0x00100000
end_define

begin_define
define|#
directive|define
name|INT_CLK_MULT_ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PCI_ACPI_CONTROL
value|0x54
end_define

begin_define
define|#
directive|define
name|PCI_ACPI_D0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_ACPI_D1
value|0xB4F70000
end_define

begin_define
define|#
directive|define
name|PCI_ACPI_D2
value|0xB4F7B4F7
end_define

begin_define
define|#
directive|define
name|PCI_USER_CONFIG
value|0x58
end_define

begin_define
define|#
directive|define
name|EXT_PCI_MASTER_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SPDIF_OUT_SELECT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TEST_PIN_DIR_CTRL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AC97_CODEC_TEST
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TRI_STATE_BUFFER
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IN_CLK_12MHZ_SELECT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MULTI_FUNC_DISABLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|EXT_MASTER_PAIR_SEL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PCI_MASTER_SUPPORT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|STOP_CLOCK_ENABLE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|EAPD_DRIVE_ENABLE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|REQ_TRI_STATE_ENABLE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|REQ_LOW_ENABLE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MIDI_1_ENABLE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MIDI_2_ENABLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SB_AUDIO_SYNC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HV_CTRL_TEST
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SOUNDBLASTER_TEST
value|0x00400000
end_define

begin_define
define|#
directive|define
name|PCI_USER_CONFIG_C
value|0x5C
end_define

begin_define
define|#
directive|define
name|PCI_DDMA_CTRL
value|0x60
end_define

begin_define
define|#
directive|define
name|DDMA_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Allegro registers */
end_comment

begin_define
define|#
directive|define
name|HOST_INT_CTRL
value|0x18
end_define

begin_define
define|#
directive|define
name|SB_INT_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MPU401_INT_ENABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ASSP_INT_ENABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|RING_INT_ENABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|HV_INT_ENABLE
value|0x0040
end_define

begin_define
define|#
directive|define
name|CLKRUN_GEN_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|HV_CTRL_TO_PME
value|0x0400
end_define

begin_define
define|#
directive|define
name|SOFTWARE_RESET_ENABLE
value|0x8000
end_define

begin_comment
comment|/*  * should be using the above defines, probably.  */
end_comment

begin_define
define|#
directive|define
name|REGB_ENABLE_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|REGB_STOP_CLOCK
value|0x10
end_define

begin_define
define|#
directive|define
name|HOST_INT_STATUS
value|0x1A
end_define

begin_define
define|#
directive|define
name|SB_INT_PENDING
value|0x01
end_define

begin_define
define|#
directive|define
name|MPU401_INT_PENDING
value|0x02
end_define

begin_define
define|#
directive|define
name|ASSP_INT_PENDING
value|0x10
end_define

begin_define
define|#
directive|define
name|RING_INT_PENDING
value|0x20
end_define

begin_define
define|#
directive|define
name|HV_INT_PENDING
value|0x40
end_define

begin_define
define|#
directive|define
name|HARDWARE_VOL_CTRL
value|0x1B
end_define

begin_define
define|#
directive|define
name|SHADOW_MIX_REG_VOICE
value|0x1C
end_define

begin_define
define|#
directive|define
name|HW_VOL_COUNTER_VOICE
value|0x1D
end_define

begin_define
define|#
directive|define
name|SHADOW_MIX_REG_MASTER
value|0x1E
end_define

begin_define
define|#
directive|define
name|HW_VOL_COUNTER_MASTER
value|0x1F
end_define

begin_define
define|#
directive|define
name|CODEC_COMMAND
value|0x30
end_define

begin_define
define|#
directive|define
name|CODEC_READ_B
value|0x80
end_define

begin_define
define|#
directive|define
name|CODEC_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|CODEC_BUSY_B
value|0x01
end_define

begin_define
define|#
directive|define
name|CODEC_DATA
value|0x32
end_define

begin_define
define|#
directive|define
name|RING_BUS_CTRL_A
value|0x36
end_define

begin_define
define|#
directive|define
name|RAC_PME_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|RAC_SDFS_ENABLE
value|0x0200
end_define

begin_define
define|#
directive|define
name|LAC_PME_ENABLE
value|0x0400
end_define

begin_define
define|#
directive|define
name|LAC_SDFS_ENABLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|SERIAL_AC_LINK_ENABLE
value|0x1000
end_define

begin_define
define|#
directive|define
name|IO_SRAM_ENABLE
value|0x2000
end_define

begin_define
define|#
directive|define
name|IIS_INPUT_ENABLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|RING_BUS_CTRL_B
value|0x38
end_define

begin_define
define|#
directive|define
name|SECOND_CODEC_ID_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|SPDIF_FUNC_ENABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|SECOND_AC_ENABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|SB_MODULE_INTF_ENABLE
value|0x0040
end_define

begin_define
define|#
directive|define
name|SSPE_ENABLE
value|0x0040
end_define

begin_define
define|#
directive|define
name|M3I_DOCK_ENABLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|SDO_OUT_DEST_CTRL
value|0x3A
end_define

begin_define
define|#
directive|define
name|COMMAND_ADDR_OUT
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCM_LR_OUT_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCM_LR_OUT_REMOTE
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCM_LR_OUT_MUTE
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCM_LR_OUT_BOTH
value|0x000C
end_define

begin_define
define|#
directive|define
name|LINE1_DAC_OUT_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|LINE1_DAC_OUT_REMOTE
value|0x0010
end_define

begin_define
define|#
directive|define
name|LINE1_DAC_OUT_MUTE
value|0x0020
end_define

begin_define
define|#
directive|define
name|LINE1_DAC_OUT_BOTH
value|0x0030
end_define

begin_define
define|#
directive|define
name|PCM_CLS_OUT_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCM_CLS_OUT_REMOTE
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCM_CLS_OUT_MUTE
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCM_CLS_OUT_BOTH
value|0x00C0
end_define

begin_define
define|#
directive|define
name|PCM_RLF_OUT_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCM_RLF_OUT_REMOTE
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCM_RLF_OUT_MUTE
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCM_RLF_OUT_BOTH
value|0x0300
end_define

begin_define
define|#
directive|define
name|LINE2_DAC_OUT_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|LINE2_DAC_OUT_REMOTE
value|0x0400
end_define

begin_define
define|#
directive|define
name|LINE2_DAC_OUT_MUTE
value|0x0800
end_define

begin_define
define|#
directive|define
name|LINE2_DAC_OUT_BOTH
value|0x0C00
end_define

begin_define
define|#
directive|define
name|HANDSET_OUT_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|HANDSET_OUT_REMOTE
value|0x1000
end_define

begin_define
define|#
directive|define
name|HANDSET_OUT_MUTE
value|0x2000
end_define

begin_define
define|#
directive|define
name|HANDSET_OUT_BOTH
value|0x3000
end_define

begin_define
define|#
directive|define
name|IO_CTRL_OUT_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|IO_CTRL_OUT_REMOTE
value|0x4000
end_define

begin_define
define|#
directive|define
name|IO_CTRL_OUT_MUTE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IO_CTRL_OUT_BOTH
value|0xC000
end_define

begin_define
define|#
directive|define
name|SDO_IN_DEST_CTRL
value|0x3C
end_define

begin_define
define|#
directive|define
name|STATUS_ADDR_IN
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCM_LR_IN_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCM_LR_IN_REMOTE
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCM_LR_RESERVED
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCM_LR_IN_BOTH
value|0x000C
end_define

begin_define
define|#
directive|define
name|LINE1_ADC_IN_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|LINE1_ADC_IN_REMOTE
value|0x0010
end_define

begin_define
define|#
directive|define
name|LINE1_ADC_IN_MUTE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MIC_ADC_IN_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|MIC_ADC_IN_REMOTE
value|0x0040
end_define

begin_define
define|#
directive|define
name|MIC_ADC_IN_MUTE
value|0x0080
end_define

begin_define
define|#
directive|define
name|LINE2_DAC_IN_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|LINE2_DAC_IN_REMOTE
value|0x0400
end_define

begin_define
define|#
directive|define
name|LINE2_DAC_IN_MUTE
value|0x0800
end_define

begin_define
define|#
directive|define
name|HANDSET_IN_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|HANDSET_IN_REMOTE
value|0x1000
end_define

begin_define
define|#
directive|define
name|HANDSET_IN_MUTE
value|0x2000
end_define

begin_define
define|#
directive|define
name|IO_STATUS_IN_LOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|IO_STATUS_IN_REMOTE
value|0x4000
end_define

begin_define
define|#
directive|define
name|SPDIF_IN_CTRL
value|0x3E
end_define

begin_define
define|#
directive|define
name|SPDIF_IN_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|GPIO_DATA
value|0x60
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_MASK
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|GPIO_HV_STATUS
value|0x3000
end_define

begin_define
define|#
directive|define
name|GPIO_PME_STATUS
value|0x4000
end_define

begin_define
define|#
directive|define
name|GPIO_MASK
value|0x64
end_define

begin_define
define|#
directive|define
name|GPIO_DIRECTION
value|0x68
end_define

begin_define
define|#
directive|define
name|GPO_PRIMARY_AC97
value|0x0001
end_define

begin_define
define|#
directive|define
name|GPI_LINEOUT_SENSE
value|0x0004
end_define

begin_define
define|#
directive|define
name|GPO_SECONDARY_AC97
value|0x0008
end_define

begin_define
define|#
directive|define
name|GPI_VOL_DOWN
value|0x0010
end_define

begin_define
define|#
directive|define
name|GPI_VOL_UP
value|0x0020
end_define

begin_define
define|#
directive|define
name|GPI_IIS_CLK
value|0x0040
end_define

begin_define
define|#
directive|define
name|GPI_IIS_LRCLK
value|0x0080
end_define

begin_define
define|#
directive|define
name|GPI_IIS_DATA
value|0x0100
end_define

begin_define
define|#
directive|define
name|GPI_DOCKING_STATUS
value|0x0100
end_define

begin_define
define|#
directive|define
name|GPI_HEADPHONE_SENSE
value|0x0200
end_define

begin_define
define|#
directive|define
name|GPO_EXT_AMP_SHUTDOWN
value|0x1000
end_define

begin_comment
comment|/* M3 */
end_comment

begin_define
define|#
directive|define
name|GPO_M3_EXT_AMP_SHUTDN
value|0x0002
end_define

begin_define
define|#
directive|define
name|ASSP_INDEX_PORT
value|0x80
end_define

begin_define
define|#
directive|define
name|ASSP_MEMORY_PORT
value|0x82
end_define

begin_define
define|#
directive|define
name|ASSP_DATA_PORT
value|0x84
end_define

begin_define
define|#
directive|define
name|MPU401_DATA_PORT
value|0x98
end_define

begin_define
define|#
directive|define
name|MPU401_STATUS_PORT
value|0x99
end_define

begin_define
define|#
directive|define
name|CLK_MULT_DATA_PORT
value|0x9C
end_define

begin_define
define|#
directive|define
name|ASSP_CONTROL_A
value|0xA2
end_define

begin_define
define|#
directive|define
name|ASSP_0_WS_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|ASSP_CTRL_A_RESERVED1
value|0x02
end_define

begin_define
define|#
directive|define
name|ASSP_CTRL_A_RESERVED2
value|0x04
end_define

begin_define
define|#
directive|define
name|ASSP_CLK_49MHZ_SELECT
value|0x08
end_define

begin_define
define|#
directive|define
name|FAST_PLU_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|ASSP_CTRL_A_RESERVED3
value|0x20
end_define

begin_define
define|#
directive|define
name|DSP_CLK_36MHZ_SELECT
value|0x40
end_define

begin_define
define|#
directive|define
name|ASSP_CONTROL_B
value|0xA4
end_define

begin_define
define|#
directive|define
name|RESET_ASSP
value|0x00
end_define

begin_define
define|#
directive|define
name|RUN_ASSP
value|0x01
end_define

begin_define
define|#
directive|define
name|ENABLE_ASSP_CLOCK
value|0x00
end_define

begin_define
define|#
directive|define
name|STOP_ASSP_CLOCK
value|0x10
end_define

begin_define
define|#
directive|define
name|RESET_TOGGLE
value|0x40
end_define

begin_define
define|#
directive|define
name|ASSP_CONTROL_C
value|0xA6
end_define

begin_define
define|#
directive|define
name|ASSP_HOST_INT_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|FM_ADDR_REMAP_DISABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|HOST_WRITE_PORT_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|ASSP_HOST_INT_STATUS
value|0xAC
end_define

begin_define
define|#
directive|define
name|DSP2HOST_REQ_PIORECORD
value|0x01
end_define

begin_define
define|#
directive|define
name|DSP2HOST_REQ_I2SRATE
value|0x02
end_define

begin_define
define|#
directive|define
name|DSP2HOST_REQ_TIMER
value|0x04
end_define

begin_comment
comment|/* AC97 registers */
end_comment

begin_comment
comment|/* XXX fix this crap up */
end_comment

begin_comment
comment|/*#define AC97_RESET              0x00*/
end_comment

begin_define
define|#
directive|define
name|AC97_VOL_MUTE_B
value|0x8000
end_define

begin_define
define|#
directive|define
name|AC97_VOL_M
value|0x1F
end_define

begin_define
define|#
directive|define
name|AC97_LEFT_VOL_S
value|8
end_define

begin_define
define|#
directive|define
name|AC97_MASTER_VOL
value|0x02
end_define

begin_define
define|#
directive|define
name|AC97_LINE_LEVEL_VOL
value|0x04
end_define

begin_define
define|#
directive|define
name|AC97_MASTER_MONO_VOL
value|0x06
end_define

begin_define
define|#
directive|define
name|AC97_PC_BEEP_VOL
value|0x0A
end_define

begin_define
define|#
directive|define
name|AC97_PC_BEEP_VOL_M
value|0x0F
end_define

begin_define
define|#
directive|define
name|AC97_SROUND_MASTER_VOL
value|0x38
end_define

begin_define
define|#
directive|define
name|AC97_PC_BEEP_VOL_S
value|1
end_define

begin_comment
comment|/*#define AC97_PHONE_VOL          0x0C #define AC97_MIC_VOL            0x0E*/
end_comment

begin_define
define|#
directive|define
name|AC97_MIC_20DB_ENABLE
value|0x40
end_define

begin_comment
comment|/*#define AC97_LINEIN_VOL         0x10 #define AC97_CD_VOL             0x12 #define AC97_VIDEO_VOL          0x14 #define AC97_AUX_VOL            0x16*/
end_comment

begin_define
define|#
directive|define
name|AC97_PCM_OUT_VOL
value|0x18
end_define

begin_comment
comment|/*#define AC97_RECORD_SELECT      0x1A*/
end_comment

begin_define
define|#
directive|define
name|AC97_RECORD_MIC
value|0x00
end_define

begin_define
define|#
directive|define
name|AC97_RECORD_CD
value|0x01
end_define

begin_define
define|#
directive|define
name|AC97_RECORD_VIDEO
value|0x02
end_define

begin_define
define|#
directive|define
name|AC97_RECORD_AUX
value|0x03
end_define

begin_define
define|#
directive|define
name|AC97_RECORD_MONO_MUX
value|0x02
end_define

begin_define
define|#
directive|define
name|AC97_RECORD_DIGITAL
value|0x03
end_define

begin_define
define|#
directive|define
name|AC97_RECORD_LINE
value|0x04
end_define

begin_define
define|#
directive|define
name|AC97_RECORD_STEREO
value|0x05
end_define

begin_define
define|#
directive|define
name|AC97_RECORD_MONO
value|0x06
end_define

begin_define
define|#
directive|define
name|AC97_RECORD_PHONE
value|0x07
end_define

begin_comment
comment|/*#define AC97_RECORD_GAIN        0x1C*/
end_comment

begin_define
define|#
directive|define
name|AC97_RECORD_VOL_M
value|0x0F
end_define

begin_comment
comment|/*#define AC97_GENERAL_PURPOSE    0x20*/
end_comment

begin_define
define|#
directive|define
name|AC97_POWER_DOWN_CTRL
value|0x26
end_define

begin_define
define|#
directive|define
name|AC97_ADC_READY
value|0x0001
end_define

begin_define
define|#
directive|define
name|AC97_DAC_READY
value|0x0002
end_define

begin_define
define|#
directive|define
name|AC97_ANALOG_READY
value|0x0004
end_define

begin_define
define|#
directive|define
name|AC97_VREF_ON
value|0x0008
end_define

begin_define
define|#
directive|define
name|AC97_PR0
value|0x0100
end_define

begin_define
define|#
directive|define
name|AC97_PR1
value|0x0200
end_define

begin_define
define|#
directive|define
name|AC97_PR2
value|0x0400
end_define

begin_define
define|#
directive|define
name|AC97_PR3
value|0x0800
end_define

begin_define
define|#
directive|define
name|AC97_PR4
value|0x1000
end_define

begin_define
define|#
directive|define
name|AC97_RESERVED1
value|0x28
end_define

begin_define
define|#
directive|define
name|AC97_VENDOR_TEST
value|0x5A
end_define

begin_define
define|#
directive|define
name|AC97_CLOCK_DELAY
value|0x5C
end_define

begin_define
define|#
directive|define
name|AC97_LINEOUT_MUX_SEL
value|0x0001
end_define

begin_define
define|#
directive|define
name|AC97_MONO_MUX_SEL
value|0x0002
end_define

begin_define
define|#
directive|define
name|AC97_CLOCK_DELAY_SEL
value|0x1F
end_define

begin_define
define|#
directive|define
name|AC97_DAC_CDS_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|AC97_ADC_CDS_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|AC97_MULTI_CHANNEL_SEL
value|0x74
end_define

begin_comment
comment|/*#define AC97_VENDOR_ID1         0x7C #define AC97_VENDOR_ID2         0x7E*/
end_comment

begin_comment
comment|/*  * ASSP control regs  */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_TIMER_COUNT
value|0x06
end_define

begin_define
define|#
directive|define
name|DSP_PORT_MEMORY_INDEX
value|0x80
end_define

begin_define
define|#
directive|define
name|DSP_PORT_MEMORY_TYPE
value|0x82
end_define

begin_define
define|#
directive|define
name|MEMTYPE_INTERNAL_CODE
value|0x0002
end_define

begin_define
define|#
directive|define
name|MEMTYPE_INTERNAL_DATA
value|0x0003
end_define

begin_define
define|#
directive|define
name|MEMTYPE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|DSP_PORT_MEMORY_DATA
value|0x84
end_define

begin_define
define|#
directive|define
name|DSP_PORT_CONTROL_REG_A
value|0xA2
end_define

begin_define
define|#
directive|define
name|DSP_PORT_CONTROL_REG_B
value|0xA4
end_define

begin_define
define|#
directive|define
name|DSP_PORT_CONTROL_REG_C
value|0xA6
end_define

begin_define
define|#
directive|define
name|REV_A_CODE_MEMORY_BEGIN
value|0x0000
end_define

begin_define
define|#
directive|define
name|REV_A_CODE_MEMORY_END
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|REV_A_CODE_MEMORY_UNIT_LENGTH
value|0x0040
end_define

begin_define
define|#
directive|define
name|REV_A_CODE_MEMORY_LENGTH
value|(REV_A_CODE_MEMORY_END - REV_A_CODE_MEMORY_BEGIN + 1)
end_define

begin_define
define|#
directive|define
name|REV_B_CODE_MEMORY_BEGIN
value|0x0000
end_define

begin_define
define|#
directive|define
name|REV_B_CODE_MEMORY_END
value|0x0BFF
end_define

begin_define
define|#
directive|define
name|REV_B_CODE_MEMORY_UNIT_LENGTH
value|0x0040
end_define

begin_define
define|#
directive|define
name|REV_B_CODE_MEMORY_LENGTH
value|(REV_B_CODE_MEMORY_END - REV_B_CODE_MEMORY_BEGIN + 1)
end_define

begin_define
define|#
directive|define
name|REV_A_DATA_MEMORY_BEGIN
value|0x1000
end_define

begin_define
define|#
directive|define
name|REV_A_DATA_MEMORY_END
value|0x2FFF
end_define

begin_define
define|#
directive|define
name|REV_A_DATA_MEMORY_UNIT_LENGTH
value|0x0080
end_define

begin_define
define|#
directive|define
name|REV_A_DATA_MEMORY_LENGTH
value|(REV_A_DATA_MEMORY_END - REV_A_DATA_MEMORY_BEGIN + 1)
end_define

begin_define
define|#
directive|define
name|REV_B_DATA_MEMORY_BEGIN
value|0x1000
end_define

begin_define
define|#
directive|define
name|REV_B_DATA_MEMORY_END
value|0x2BFF
end_define

begin_define
define|#
directive|define
name|REV_B_DATA_MEMORY_UNIT_LENGTH
value|0x0080
end_define

begin_define
define|#
directive|define
name|REV_B_DATA_MEMORY_LENGTH
value|(REV_B_DATA_MEMORY_END - REV_B_DATA_MEMORY_BEGIN + 1)
end_define

begin_define
define|#
directive|define
name|NUM_UNITS_KERNEL_CODE
value|16
end_define

begin_define
define|#
directive|define
name|NUM_UNITS_KERNEL_DATA
value|2
end_define

begin_define
define|#
directive|define
name|NUM_UNITS_KERNEL_CODE_WITH_HSP
value|16
end_define

begin_define
define|#
directive|define
name|NUM_UNITS_KERNEL_DATA_WITH_HSP
value|5
end_define

begin_comment
comment|/*  * Kernel data layout  */
end_comment

begin_define
define|#
directive|define
name|DP_SHIFT_COUNT
value|7
end_define

begin_define
define|#
directive|define
name|KDATA_BASE_ADDR
value|0x1000
end_define

begin_define
define|#
directive|define
name|KDATA_BASE_ADDR2
value|0x1080
end_define

begin_define
define|#
directive|define
name|KDATA_TASK0
value|(KDATA_BASE_ADDR + 0x0000)
end_define

begin_define
define|#
directive|define
name|KDATA_TASK1
value|(KDATA_BASE_ADDR + 0x0001)
end_define

begin_define
define|#
directive|define
name|KDATA_TASK2
value|(KDATA_BASE_ADDR + 0x0002)
end_define

begin_define
define|#
directive|define
name|KDATA_TASK3
value|(KDATA_BASE_ADDR + 0x0003)
end_define

begin_define
define|#
directive|define
name|KDATA_TASK4
value|(KDATA_BASE_ADDR + 0x0004)
end_define

begin_define
define|#
directive|define
name|KDATA_TASK5
value|(KDATA_BASE_ADDR + 0x0005)
end_define

begin_define
define|#
directive|define
name|KDATA_TASK6
value|(KDATA_BASE_ADDR + 0x0006)
end_define

begin_define
define|#
directive|define
name|KDATA_TASK7
value|(KDATA_BASE_ADDR + 0x0007)
end_define

begin_define
define|#
directive|define
name|KDATA_TASK_ENDMARK
value|(KDATA_BASE_ADDR + 0x0008)
end_define

begin_define
define|#
directive|define
name|KDATA_CURRENT_TASK
value|(KDATA_BASE_ADDR + 0x0009)
end_define

begin_define
define|#
directive|define
name|KDATA_TASK_SWITCH
value|(KDATA_BASE_ADDR + 0x000A)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE0_POS3D
value|(KDATA_BASE_ADDR + 0x000B)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE1_POS3D
value|(KDATA_BASE_ADDR + 0x000C)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE2_POS3D
value|(KDATA_BASE_ADDR + 0x000D)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE3_POS3D
value|(KDATA_BASE_ADDR + 0x000E)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE4_POS3D
value|(KDATA_BASE_ADDR + 0x000F)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE5_POS3D
value|(KDATA_BASE_ADDR + 0x0010)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE6_POS3D
value|(KDATA_BASE_ADDR + 0x0011)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE7_POS3D
value|(KDATA_BASE_ADDR + 0x0012)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE8_POS3D
value|(KDATA_BASE_ADDR + 0x0013)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE_POS3D_ENDMARK
value|(KDATA_BASE_ADDR + 0x0014)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE0_SPKVIRT
value|(KDATA_BASE_ADDR + 0x0015)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE_SPKVIRT_ENDMARK
value|(KDATA_BASE_ADDR + 0x0016)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE0_SPDIF
value|(KDATA_BASE_ADDR + 0x0017)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE_SPDIF_ENDMARK
value|(KDATA_BASE_ADDR + 0x0018)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE0_MODEM
value|(KDATA_BASE_ADDR + 0x0019)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE_MODEM_ENDMARK
value|(KDATA_BASE_ADDR + 0x001A)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE0_SRC
value|(KDATA_BASE_ADDR + 0x001B)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE1_SRC
value|(KDATA_BASE_ADDR + 0x001C)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE_SRC_ENDMARK
value|(KDATA_BASE_ADDR + 0x001D)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE0_MINISRC
value|(KDATA_BASE_ADDR + 0x001E)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE1_MINISRC
value|(KDATA_BASE_ADDR + 0x001F)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE2_MINISRC
value|(KDATA_BASE_ADDR + 0x0020)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE3_MINISRC
value|(KDATA_BASE_ADDR + 0x0021)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE_MINISRC_ENDMARK
value|(KDATA_BASE_ADDR + 0x0022)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE0_CPYTHRU
value|(KDATA_BASE_ADDR + 0x0023)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE1_CPYTHRU
value|(KDATA_BASE_ADDR + 0x0024)
end_define

begin_define
define|#
directive|define
name|KDATA_INSTANCE_CPYTHRU_ENDMARK
value|(KDATA_BASE_ADDR + 0x0025)
end_define

begin_define
define|#
directive|define
name|KDATA_CURRENT_DMA
value|(KDATA_BASE_ADDR + 0x0026)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_SWITCH
value|(KDATA_BASE_ADDR + 0x0027)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_ACTIVE
value|(KDATA_BASE_ADDR + 0x0028)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_XFER0
value|(KDATA_BASE_ADDR + 0x0029)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_XFER1
value|(KDATA_BASE_ADDR + 0x002A)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_XFER2
value|(KDATA_BASE_ADDR + 0x002B)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_XFER3
value|(KDATA_BASE_ADDR + 0x002C)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_XFER4
value|(KDATA_BASE_ADDR + 0x002D)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_XFER5
value|(KDATA_BASE_ADDR + 0x002E)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_XFER6
value|(KDATA_BASE_ADDR + 0x002F)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_XFER7
value|(KDATA_BASE_ADDR + 0x0030)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_XFER8
value|(KDATA_BASE_ADDR + 0x0031)
end_define

begin_define
define|#
directive|define
name|KDATA_DMA_XFER_ENDMARK
value|(KDATA_BASE_ADDR + 0x0032)
end_define

begin_define
define|#
directive|define
name|KDATA_I2S_SAMPLE_COUNT
value|(KDATA_BASE_ADDR + 0x0033)
end_define

begin_define
define|#
directive|define
name|KDATA_I2S_INT_METER
value|(KDATA_BASE_ADDR + 0x0034)
end_define

begin_define
define|#
directive|define
name|KDATA_I2S_ACTIVE
value|(KDATA_BASE_ADDR + 0x0035)
end_define

begin_define
define|#
directive|define
name|KDATA_TIMER_COUNT_RELOAD
value|(KDATA_BASE_ADDR + 0x0036)
end_define

begin_define
define|#
directive|define
name|KDATA_TIMER_COUNT_CURRENT
value|(KDATA_BASE_ADDR + 0x0037)
end_define

begin_define
define|#
directive|define
name|KDATA_HALT_SYNCH_CLIENT
value|(KDATA_BASE_ADDR + 0x0038)
end_define

begin_define
define|#
directive|define
name|KDATA_HALT_SYNCH_DMA
value|(KDATA_BASE_ADDR + 0x0039)
end_define

begin_define
define|#
directive|define
name|KDATA_HALT_ACKNOWLEDGE
value|(KDATA_BASE_ADDR + 0x003A)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC1_XFER0
value|(KDATA_BASE_ADDR + 0x003B)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC1_XFER_ENDMARK
value|(KDATA_BASE_ADDR + 0x003C)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC1_LEFT_VOLUME
value|(KDATA_BASE_ADDR + 0x003D)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC1_RIGHT_VOLUME
value|(KDATA_BASE_ADDR + 0x003E)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC1_LEFT_SUR_VOL
value|(KDATA_BASE_ADDR + 0x003F)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC1_RIGHT_SUR_VOL
value|(KDATA_BASE_ADDR + 0x0040)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC2_XFER0
value|(KDATA_BASE_ADDR + 0x0041)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC2_XFER_ENDMARK
value|(KDATA_BASE_ADDR + 0x0042)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC2_LEFT_VOLUME
value|(KDATA_BASE_ADDR + 0x0043)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC2_RIGHT_VOLUME
value|(KDATA_BASE_ADDR + 0x0044)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC2_LEFT_SUR_VOL
value|(KDATA_BASE_ADDR + 0x0045)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC2_RIGHT_SUR_VOL
value|(KDATA_BASE_ADDR + 0x0046)
end_define

begin_define
define|#
directive|define
name|KDATA_CD_XFER0
value|(KDATA_BASE_ADDR + 0x0047)
end_define

begin_define
define|#
directive|define
name|KDATA_CD_XFER_ENDMARK
value|(KDATA_BASE_ADDR + 0x0048)
end_define

begin_define
define|#
directive|define
name|KDATA_CD_LEFT_VOLUME
value|(KDATA_BASE_ADDR + 0x0049)
end_define

begin_define
define|#
directive|define
name|KDATA_CD_RIGHT_VOLUME
value|(KDATA_BASE_ADDR + 0x004A)
end_define

begin_define
define|#
directive|define
name|KDATA_CD_LEFT_SUR_VOL
value|(KDATA_BASE_ADDR + 0x004B)
end_define

begin_define
define|#
directive|define
name|KDATA_CD_RIGHT_SUR_VOL
value|(KDATA_BASE_ADDR + 0x004C)
end_define

begin_define
define|#
directive|define
name|KDATA_MIC_XFER0
value|(KDATA_BASE_ADDR + 0x004D)
end_define

begin_define
define|#
directive|define
name|KDATA_MIC_XFER_ENDMARK
value|(KDATA_BASE_ADDR + 0x004E)
end_define

begin_define
define|#
directive|define
name|KDATA_MIC_VOLUME
value|(KDATA_BASE_ADDR + 0x004F)
end_define

begin_define
define|#
directive|define
name|KDATA_MIC_SUR_VOL
value|(KDATA_BASE_ADDR + 0x0050)
end_define

begin_define
define|#
directive|define
name|KDATA_I2S_XFER0
value|(KDATA_BASE_ADDR + 0x0051)
end_define

begin_define
define|#
directive|define
name|KDATA_I2S_XFER_ENDMARK
value|(KDATA_BASE_ADDR + 0x0052)
end_define

begin_define
define|#
directive|define
name|KDATA_CHI_XFER0
value|(KDATA_BASE_ADDR + 0x0053)
end_define

begin_define
define|#
directive|define
name|KDATA_CHI_XFER_ENDMARK
value|(KDATA_BASE_ADDR + 0x0054)
end_define

begin_define
define|#
directive|define
name|KDATA_SPDIF_XFER
value|(KDATA_BASE_ADDR + 0x0055)
end_define

begin_define
define|#
directive|define
name|KDATA_SPDIF_CURRENT_FRAME
value|(KDATA_BASE_ADDR + 0x0056)
end_define

begin_define
define|#
directive|define
name|KDATA_SPDIF_FRAME0
value|(KDATA_BASE_ADDR + 0x0057)
end_define

begin_define
define|#
directive|define
name|KDATA_SPDIF_FRAME1
value|(KDATA_BASE_ADDR + 0x0058)
end_define

begin_define
define|#
directive|define
name|KDATA_SPDIF_FRAME2
value|(KDATA_BASE_ADDR + 0x0059)
end_define

begin_define
define|#
directive|define
name|KDATA_SPDIF_REQUEST
value|(KDATA_BASE_ADDR + 0x005A)
end_define

begin_define
define|#
directive|define
name|KDATA_SPDIF_TEMP
value|(KDATA_BASE_ADDR + 0x005B)
end_define

begin_define
define|#
directive|define
name|KDATA_SPDIFIN_XFER0
value|(KDATA_BASE_ADDR + 0x005C)
end_define

begin_define
define|#
directive|define
name|KDATA_SPDIFIN_XFER_ENDMARK
value|(KDATA_BASE_ADDR + 0x005D)
end_define

begin_define
define|#
directive|define
name|KDATA_SPDIFIN_INT_METER
value|(KDATA_BASE_ADDR + 0x005E)
end_define

begin_define
define|#
directive|define
name|KDATA_DSP_RESET_COUNT
value|(KDATA_BASE_ADDR + 0x005F)
end_define

begin_define
define|#
directive|define
name|KDATA_DEBUG_OUTPUT
value|(KDATA_BASE_ADDR + 0x0060)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_LIST
value|(KDATA_BASE_ADDR + 0x0061)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_CBSR1
value|(KDATA_BASE_ADDR + 0x0062)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_CBER1
value|(KDATA_BASE_ADDR + 0x0063)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_CBCR
value|(KDATA_BASE_ADDR + 0x0064)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_AR0
value|(KDATA_BASE_ADDR + 0x0065)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_AR1
value|(KDATA_BASE_ADDR + 0x0066)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_AR2
value|(KDATA_BASE_ADDR + 0x0067)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_AR3
value|(KDATA_BASE_ADDR + 0x0068)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_AR4
value|(KDATA_BASE_ADDR + 0x0069)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_AR5
value|(KDATA_BASE_ADDR + 0x006A)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_BRCR
value|(KDATA_BASE_ADDR + 0x006B)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_PASR
value|(KDATA_BASE_ADDR + 0x006C)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_PAER
value|(KDATA_BASE_ADDR + 0x006D)
end_define

begin_define
define|#
directive|define
name|KDATA_CLIENT_SCRATCH0
value|(KDATA_BASE_ADDR + 0x006E)
end_define

begin_define
define|#
directive|define
name|KDATA_CLIENT_SCRATCH1
value|(KDATA_BASE_ADDR + 0x006F)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_SCRATCH
value|(KDATA_BASE_ADDR + 0x0070)
end_define

begin_define
define|#
directive|define
name|KDATA_KERNEL_ISR_SCRATCH
value|(KDATA_BASE_ADDR + 0x0071)
end_define

begin_define
define|#
directive|define
name|KDATA_OUEUE_LEFT
value|(KDATA_BASE_ADDR + 0x0072)
end_define

begin_define
define|#
directive|define
name|KDATA_QUEUE_RIGHT
value|(KDATA_BASE_ADDR + 0x0073)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC1_REQUEST
value|(KDATA_BASE_ADDR + 0x0074)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC2_REQUEST
value|(KDATA_BASE_ADDR + 0x0075)
end_define

begin_define
define|#
directive|define
name|KDATA_CD_REQUEST
value|(KDATA_BASE_ADDR + 0x0076)
end_define

begin_define
define|#
directive|define
name|KDATA_MIC_REQUEST
value|(KDATA_BASE_ADDR + 0x0077)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC1_MIXER_REQUEST
value|(KDATA_BASE_ADDR + 0x0078)
end_define

begin_define
define|#
directive|define
name|KDATA_ADC2_MIXER_REQUEST
value|(KDATA_BASE_ADDR + 0x0079)
end_define

begin_define
define|#
directive|define
name|KDATA_CD_MIXER_REQUEST
value|(KDATA_BASE_ADDR + 0x007A)
end_define

begin_define
define|#
directive|define
name|KDATA_MIC_MIXER_REQUEST
value|(KDATA_BASE_ADDR + 0x007B)
end_define

begin_define
define|#
directive|define
name|KDATA_MIC_SYNC_COUNTER
value|(KDATA_BASE_ADDR + 0x007C)
end_define

begin_comment
comment|/*  * second 'segment' (?) reserved for mixer  * buffers..  */
end_comment

begin_define
define|#
directive|define
name|KDATA_MIXER_WORD0
value|(KDATA_BASE_ADDR2 + 0x0000)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORD1
value|(KDATA_BASE_ADDR2 + 0x0001)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORD2
value|(KDATA_BASE_ADDR2 + 0x0002)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORD3
value|(KDATA_BASE_ADDR2 + 0x0003)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORD4
value|(KDATA_BASE_ADDR2 + 0x0004)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORD5
value|(KDATA_BASE_ADDR2 + 0x0005)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORD6
value|(KDATA_BASE_ADDR2 + 0x0006)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORD7
value|(KDATA_BASE_ADDR2 + 0x0007)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORD8
value|(KDATA_BASE_ADDR2 + 0x0008)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORD9
value|(KDATA_BASE_ADDR2 + 0x0009)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORDA
value|(KDATA_BASE_ADDR2 + 0x000A)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORDB
value|(KDATA_BASE_ADDR2 + 0x000B)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORDC
value|(KDATA_BASE_ADDR2 + 0x000C)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORDD
value|(KDATA_BASE_ADDR2 + 0x000D)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORDE
value|(KDATA_BASE_ADDR2 + 0x000E)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_WORDF
value|(KDATA_BASE_ADDR2 + 0x000F)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_XFER0
value|(KDATA_BASE_ADDR2 + 0x0010)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_XFER1
value|(KDATA_BASE_ADDR2 + 0x0011)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_XFER2
value|(KDATA_BASE_ADDR2 + 0x0012)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_XFER3
value|(KDATA_BASE_ADDR2 + 0x0013)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_XFER4
value|(KDATA_BASE_ADDR2 + 0x0014)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_XFER5
value|(KDATA_BASE_ADDR2 + 0x0015)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_XFER6
value|(KDATA_BASE_ADDR2 + 0x0016)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_XFER7
value|(KDATA_BASE_ADDR2 + 0x0017)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_XFER8
value|(KDATA_BASE_ADDR2 + 0x0018)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_XFER9
value|(KDATA_BASE_ADDR2 + 0x0019)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_XFER_ENDMARK
value|(KDATA_BASE_ADDR2 + 0x001A)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_TASK_NUMBER
value|(KDATA_BASE_ADDR2 + 0x001B)
end_define

begin_define
define|#
directive|define
name|KDATA_CURRENT_MIXER
value|(KDATA_BASE_ADDR2 + 0x001C)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_ACTIVE
value|(KDATA_BASE_ADDR2 + 0x001D)
end_define

begin_define
define|#
directive|define
name|KDATA_MIXER_BANK_STATUS
value|(KDATA_BASE_ADDR2 + 0x001E)
end_define

begin_define
define|#
directive|define
name|KDATA_DAC_LEFT_VOLUME
value|(KDATA_BASE_ADDR2 + 0x001F)
end_define

begin_define
define|#
directive|define
name|KDATA_DAC_RIGHT_VOLUME
value|(KDATA_BASE_ADDR2 + 0x0020)
end_define

begin_define
define|#
directive|define
name|MAX_INSTANCE_MINISRC
value|(KDATA_INSTANCE_MINISRC_ENDMARK - KDATA_INSTANCE0_MINISRC)
end_define

begin_define
define|#
directive|define
name|MAX_VIRTUAL_DMA_CHANNELS
value|(KDATA_DMA_XFER_ENDMARK - KDATA_DMA_XFER0)
end_define

begin_define
define|#
directive|define
name|MAX_VIRTUAL_MIXER_CHANNELS
value|(KDATA_MIXER_XFER_ENDMARK - KDATA_MIXER_XFER0)
end_define

begin_define
define|#
directive|define
name|MAX_VIRTUAL_ADC1_CHANNELS
value|(KDATA_ADC1_XFER_ENDMARK - KDATA_ADC1_XFER0)
end_define

begin_comment
comment|/*  * client data area offsets  */
end_comment

begin_define
define|#
directive|define
name|CDATA_INSTANCE_READY
value|0x00
end_define

begin_define
define|#
directive|define
name|CDATA_HOST_SRC_ADDRL
value|0x01
end_define

begin_define
define|#
directive|define
name|CDATA_HOST_SRC_ADDRH
value|0x02
end_define

begin_define
define|#
directive|define
name|CDATA_HOST_SRC_END_PLUS_1L
value|0x03
end_define

begin_define
define|#
directive|define
name|CDATA_HOST_SRC_END_PLUS_1H
value|0x04
end_define

begin_define
define|#
directive|define
name|CDATA_HOST_SRC_CURRENTL
value|0x05
end_define

begin_define
define|#
directive|define
name|CDATA_HOST_SRC_CURRENTH
value|0x06
end_define

begin_define
define|#
directive|define
name|CDATA_IN_BUF_CONNECT
value|0x07
end_define

begin_define
define|#
directive|define
name|CDATA_OUT_BUF_CONNECT
value|0x08
end_define

begin_define
define|#
directive|define
name|CDATA_IN_BUF_BEGIN
value|0x09
end_define

begin_define
define|#
directive|define
name|CDATA_IN_BUF_END_PLUS_1
value|0x0A
end_define

begin_define
define|#
directive|define
name|CDATA_IN_BUF_HEAD
value|0x0B
end_define

begin_define
define|#
directive|define
name|CDATA_IN_BUF_TAIL
value|0x0C
end_define

begin_define
define|#
directive|define
name|CDATA_OUT_BUF_BEGIN
value|0x0D
end_define

begin_define
define|#
directive|define
name|CDATA_OUT_BUF_END_PLUS_1
value|0x0E
end_define

begin_define
define|#
directive|define
name|CDATA_OUT_BUF_HEAD
value|0x0F
end_define

begin_define
define|#
directive|define
name|CDATA_OUT_BUF_TAIL
value|0x10
end_define

begin_define
define|#
directive|define
name|CDATA_DMA_CONTROL
value|0x11
end_define

begin_define
define|#
directive|define
name|CDATA_RESERVED
value|0x12
end_define

begin_define
define|#
directive|define
name|CDATA_FREQUENCY
value|0x13
end_define

begin_define
define|#
directive|define
name|CDATA_LEFT_VOLUME
value|0x14
end_define

begin_define
define|#
directive|define
name|CDATA_RIGHT_VOLUME
value|0x15
end_define

begin_define
define|#
directive|define
name|CDATA_LEFT_SUR_VOL
value|0x16
end_define

begin_define
define|#
directive|define
name|CDATA_RIGHT_SUR_VOL
value|0x17
end_define

begin_define
define|#
directive|define
name|CDATA_HEADER_LEN
value|0x18
end_define

begin_define
define|#
directive|define
name|SRC3_DIRECTION_OFFSET
value|CDATA_HEADER_LEN
end_define

begin_define
define|#
directive|define
name|SRC3_MODE_OFFSET
value|(CDATA_HEADER_LEN + 1)
end_define

begin_define
define|#
directive|define
name|SRC3_WORD_LENGTH_OFFSET
value|(CDATA_HEADER_LEN + 2)
end_define

begin_define
define|#
directive|define
name|SRC3_PARAMETER_OFFSET
value|(CDATA_HEADER_LEN + 3)
end_define

begin_define
define|#
directive|define
name|SRC3_COEFF_ADDR_OFFSET
value|(CDATA_HEADER_LEN + 8)
end_define

begin_define
define|#
directive|define
name|SRC3_FILTAP_ADDR_OFFSET
value|(CDATA_HEADER_LEN + 10)
end_define

begin_define
define|#
directive|define
name|SRC3_TEMP_INBUF_ADDR_OFFSET
value|(CDATA_HEADER_LEN + 16)
end_define

begin_define
define|#
directive|define
name|SRC3_TEMP_OUTBUF_ADDR_OFFSET
value|(CDATA_HEADER_LEN + 17)
end_define

begin_define
define|#
directive|define
name|MINISRC_IN_BUFFER_SIZE
value|( 0x50 * 2 )
end_define

begin_define
define|#
directive|define
name|MINISRC_OUT_BUFFER_SIZE
value|( 0x50 * 2 * 2)
end_define

begin_define
define|#
directive|define
name|MINISRC_OUT_BUFFER_SIZE
value|( 0x50 * 2 * 2)
end_define

begin_define
define|#
directive|define
name|MINISRC_TMP_BUFFER_SIZE
value|( 112 + ( MINISRC_BIQUAD_STAGE * 3 + 4 ) * 2 * 2 )
end_define

begin_define
define|#
directive|define
name|MINISRC_BIQUAD_STAGE
value|2
end_define

begin_define
define|#
directive|define
name|MINISRC_COEF_LOC
value|0X175
end_define

begin_define
define|#
directive|define
name|DMACONTROL_BLOCK_MASK
value|0x000F
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCK0_SELECTOR
value|0x0000
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCK1_SELECTOR
value|0x0001
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCK2_SELECTOR
value|0x0002
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCK3_SELECTOR
value|0x0003
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCK4_SELECTOR
value|0x0004
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCK5_SELECTOR
value|0x0005
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCK6_SELECTOR
value|0x0006
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCK7_SELECTOR
value|0x0007
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCK8_SELECTOR
value|0x0008
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCK9_SELECTOR
value|0x0009
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCKA_SELECTOR
value|0x000A
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCKB_SELECTOR
value|0x000B
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCKC_SELECTOR
value|0x000C
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCKD_SELECTOR
value|0x000D
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCKE_SELECTOR
value|0x000E
end_define

begin_define
define|#
directive|define
name|DMAC_BLOCKF_SELECTOR
value|0x000F
end_define

begin_define
define|#
directive|define
name|DMACONTROL_PAGE_MASK
value|0x00F0
end_define

begin_define
define|#
directive|define
name|DMAC_PAGE0_SELECTOR
value|0x0030
end_define

begin_define
define|#
directive|define
name|DMAC_PAGE1_SELECTOR
value|0x0020
end_define

begin_define
define|#
directive|define
name|DMAC_PAGE2_SELECTOR
value|0x0010
end_define

begin_define
define|#
directive|define
name|DMAC_PAGE3_SELECTOR
value|0x0000
end_define

begin_define
define|#
directive|define
name|DMACONTROL_AUTOREPEAT
value|0x1000
end_define

begin_define
define|#
directive|define
name|DMACONTROL_STOPPED
value|0x2000
end_define

begin_define
define|#
directive|define
name|DMACONTROL_DIRECTION
value|0x0100
end_define

end_unit

