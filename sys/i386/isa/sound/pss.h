begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  	def.h  	Version 1.3	11/2/93  	Copyright (c) 1993 Analog Devices Inc. All rights reserved  ******************************************************************************/
end_comment

begin_comment
comment|/* Port offsets from base port for Sound Blaster DSP */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_CMSD0
value|0x00
end_define

begin_comment
comment|/* C/MS music voice 1-6 data port, write only */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_CMSR0
value|0x01
end_define

begin_comment
comment|/* C/MS music voice 1-6 register port, write only */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_CMSD1
value|0x02
end_define

begin_comment
comment|/* C/MS music voice 7-12 data port, write only */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_CMSR1
value|0x03
end_define

begin_comment
comment|/* C/MS music voice 7-12 register port, write only */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_STATUS
value|0x04
end_define

begin_comment
comment|/* DSP Status bits, read only */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_CONTROL
value|0x04
end_define

begin_comment
comment|/* DSP Control bits, write only */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_DATA_LSB
value|0x05
end_define

begin_comment
comment|/* Read or write LSB of 16 bit data */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_RESET
value|0x06
end_define

begin_comment
comment|/* DSP Reset, write only */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_07h
value|0x07
end_define

begin_comment
comment|/* reserved port */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_FMD0
value|0x08
end_define

begin_comment
comment|/* FM music data/status port, read/write  */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_FMR0
value|0x09
end_define

begin_comment
comment|/* FM music data/status port, write only */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_RDDATA
value|0x0A
end_define

begin_comment
comment|/* DSP Read data, read only reading signals DSP */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_0Bh
value|0x0B
end_define

begin_comment
comment|/* reserved port */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_WRDATA
value|0x0C
end_define

begin_comment
comment|/* DSP Write data or command, write */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_WRBUSY
value|0x0C
end_define

begin_comment
comment|/* DSP Write buffer status (bit 7), read */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_0Dh
value|0x0D
end_define

begin_comment
comment|/* reserved port */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_DATAAVAIL
value|0x0E
end_define

begin_comment
comment|/* DSP Data available status (bit 7), read only */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_INTERFACE
value|0x0E
end_define

begin_comment
comment|/* Sets DMA Channel and Interrupt, write only */
end_comment

begin_define
define|#
directive|define
name|DSP_PORT_0Fh
value|0x0F
end_define

begin_comment
comment|/* reserved port (used on Pro cards) */
end_comment

begin_define
define|#
directive|define
name|ADDR_MASK
value|0x003f
end_define

begin_define
define|#
directive|define
name|INT_MASK
value|0xffc7
end_define

begin_define
define|#
directive|define
name|INT_3_BITS
value|0x0008
end_define

begin_define
define|#
directive|define
name|INT_5_BITS
value|0x0010
end_define

begin_define
define|#
directive|define
name|INT_7_BITS
value|0x0018
end_define

begin_define
define|#
directive|define
name|INT_9_BITS
value|0x0020
end_define

begin_define
define|#
directive|define
name|INT_10_BITS
value|0x0028
end_define

begin_define
define|#
directive|define
name|INT_11_BITS
value|0x0030
end_define

begin_define
define|#
directive|define
name|INT_12_BITS
value|0x0038
end_define

begin_define
define|#
directive|define
name|GAME_BIT
value|0x0400
end_define

begin_define
define|#
directive|define
name|GAME_BIT_MASK
value|0xfbff
end_define

begin_define
define|#
directive|define
name|INT_TEST_BIT
value|0x0200
end_define

begin_define
define|#
directive|define
name|INT_TEST_PASS
value|0x0100
end_define

begin_define
define|#
directive|define
name|INT_TEST_BIT_MASK
value|0xFDFF
end_define

begin_define
define|#
directive|define
name|DMA_MASK
value|0xfff8
end_define

begin_define
define|#
directive|define
name|DMA_0_BITS
value|0x0001
end_define

begin_define
define|#
directive|define
name|DMA_1_BITS
value|0x0002
end_define

begin_define
define|#
directive|define
name|DMA_3_BITS
value|0x0003
end_define

begin_define
define|#
directive|define
name|DMA_5_BITS
value|0x0004
end_define

begin_define
define|#
directive|define
name|DMA_6_BITS
value|0x0005
end_define

begin_define
define|#
directive|define
name|DMA_7_BITS
value|0x0006
end_define

begin_define
define|#
directive|define
name|DMA_TEST_BIT
value|0x0080
end_define

begin_define
define|#
directive|define
name|DMA_TEST_PASS
value|0x0040
end_define

begin_define
define|#
directive|define
name|DMA_TEST_BIT_MASK
value|0xFF7F
end_define

begin_comment
comment|/* Echo DSP Flags */
end_comment

begin_define
define|#
directive|define
name|DSP_FLAG3
value|0x10
end_define

begin_define
define|#
directive|define
name|DSP_FLAG2
value|0x08
end_define

begin_define
define|#
directive|define
name|DSP_FLAG1
value|0x80
end_define

begin_define
define|#
directive|define
name|DSP_FLAG0
value|0x40
end_define

begin_define
define|#
directive|define
name|PSS_CONFIG
value|0x10
end_define

begin_define
define|#
directive|define
name|PSS_WSS_CONFIG
value|0x12
end_define

begin_define
define|#
directive|define
name|SB_CONFIG
value|0x14
end_define

begin_define
define|#
directive|define
name|MIDI_CONFIG
value|0x18
end_define

begin_define
define|#
directive|define
name|CD_CONFIG
value|0x16
end_define

begin_define
define|#
directive|define
name|UART_CONFIG
value|0x1a
end_define

begin_define
define|#
directive|define
name|PSS_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|PSS_STATUS
value|0x02
end_define

begin_define
define|#
directive|define
name|PSS_CONTROL
value|0x02
end_define

begin_define
define|#
directive|define
name|PSS_ID_VERS
value|0x04
end_define

begin_define
define|#
directive|define
name|PSS_FLAG3
value|0x0800
end_define

begin_define
define|#
directive|define
name|PSS_FLAG2
value|0x0400
end_define

begin_define
define|#
directive|define
name|PSS_FLAG1
value|0x1000
end_define

begin_define
define|#
directive|define
name|PSS_FLAG0
value|0x0800
end_define

begin_comment
comment|/*_____ WSS defines */
end_comment

begin_define
define|#
directive|define
name|WSS_BASE_ADDRESS
value|0x530
end_define

begin_define
define|#
directive|define
name|WSS_CONFIG
value|0x0
end_define

begin_define
define|#
directive|define
name|WSS_VERSION
value|0x03
end_define

begin_define
define|#
directive|define
name|WSS_SP0
value|0x04
end_define

begin_define
define|#
directive|define
name|WSS_SP1
value|0x05
end_define

begin_define
define|#
directive|define
name|WSS_SP2
value|0x06
end_define

begin_define
define|#
directive|define
name|WSS_SP3
value|0x07
end_define

begin_comment
comment|/*_____ SoundPort register addresses */
end_comment

begin_define
define|#
directive|define
name|SP_LIN_SOURCE_CTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|SP_RIN_SOURCE_CTRL
value|0x01
end_define

begin_define
define|#
directive|define
name|SP_LIN_GAIN_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|SP_RIN_GAIN_CTRL
value|0x11
end_define

begin_define
define|#
directive|define
name|SP_LAUX1_CTRL
value|0x02
end_define

begin_define
define|#
directive|define
name|SP_RAUX1_CTRL
value|0x03
end_define

begin_define
define|#
directive|define
name|SP_LAUX2_CTRL
value|0x04
end_define

begin_define
define|#
directive|define
name|SP_RAUX2_CTRL
value|0x05
end_define

begin_define
define|#
directive|define
name|SP_LOUT_CTRL
value|0x06
end_define

begin_define
define|#
directive|define
name|SP_ROUT_CTRL
value|0x07
end_define

begin_define
define|#
directive|define
name|SP_CLK_FORMAT
value|0x48
end_define

begin_define
define|#
directive|define
name|SP_INT_CONF
value|0x09
end_define

begin_define
define|#
directive|define
name|SP_INT_CONF_MCE
value|0x49
end_define

begin_define
define|#
directive|define
name|SP_PIN_CTRL
value|0x0a
end_define

begin_define
define|#
directive|define
name|SP_TEST_INIT
value|0x0b
end_define

begin_define
define|#
directive|define
name|SP_MISC_CTRL
value|0x0c
end_define

begin_define
define|#
directive|define
name|SP_MIX_CTRL
value|0x0d
end_define

begin_define
define|#
directive|define
name|SP_DMA_UCNT
value|0x0e
end_define

begin_define
define|#
directive|define
name|SP_DMA_LCNT
value|0x0f
end_define

begin_comment
comment|/*_____ Gain constants  */
end_comment

begin_define
define|#
directive|define
name|GAIN_0
value|0x00
end_define

begin_define
define|#
directive|define
name|GAIN_1_5
value|0x01
end_define

begin_define
define|#
directive|define
name|GAIN_3
value|0x02
end_define

begin_define
define|#
directive|define
name|GAIN_4_5
value|0x03
end_define

begin_define
define|#
directive|define
name|GAIN_6
value|0x04
end_define

begin_define
define|#
directive|define
name|GAIN_7_5
value|0x05
end_define

begin_define
define|#
directive|define
name|GAIN_9
value|0x06
end_define

begin_define
define|#
directive|define
name|GAIN_10_5
value|0x07
end_define

begin_define
define|#
directive|define
name|GAIN_12
value|0x08
end_define

begin_define
define|#
directive|define
name|GAIN_13_5
value|0x09
end_define

begin_define
define|#
directive|define
name|GAIN_15
value|0x0a
end_define

begin_define
define|#
directive|define
name|GAIN_16_5
value|0x0b
end_define

begin_define
define|#
directive|define
name|GAIN_18
value|0x0c
end_define

begin_define
define|#
directive|define
name|GAIN_19_5
value|0x0d
end_define

begin_define
define|#
directive|define
name|GAIN_21
value|0x0e
end_define

begin_define
define|#
directive|define
name|GAIN_22_5
value|0x0f
end_define

begin_define
define|#
directive|define
name|MUTE
value|0XFFFF
end_define

begin_comment
comment|/*_____ Attenuation constants  */
end_comment

begin_define
define|#
directive|define
name|ATTEN_0
value|0x00
end_define

begin_define
define|#
directive|define
name|ATTEN_1_5
value|0x01
end_define

begin_define
define|#
directive|define
name|ATTEN_3
value|0x02
end_define

begin_define
define|#
directive|define
name|ATTEN_4_5
value|0x03
end_define

begin_define
define|#
directive|define
name|ATTEN_6
value|0x04
end_define

begin_define
define|#
directive|define
name|ATTEN_7_5
value|0x05
end_define

begin_define
define|#
directive|define
name|ATTEN_9
value|0x06
end_define

begin_define
define|#
directive|define
name|ATTEN_10_5
value|0x07
end_define

begin_define
define|#
directive|define
name|ATTEN_12
value|0x08
end_define

begin_define
define|#
directive|define
name|ATTEN_13_5
value|0x09
end_define

begin_define
define|#
directive|define
name|ATTEN_15
value|0x0a
end_define

begin_define
define|#
directive|define
name|ATTEN_16_5
value|0x0b
end_define

begin_define
define|#
directive|define
name|ATTEN_18
value|0x0c
end_define

begin_define
define|#
directive|define
name|ATTEN_19_5
value|0x0d
end_define

begin_define
define|#
directive|define
name|ATTEN_21
value|0x0e
end_define

begin_define
define|#
directive|define
name|ATTEN_22_5
value|0x0f
end_define

begin_define
define|#
directive|define
name|PSS_WRITE_EMPTY
value|0x8000
end_define

begin_define
define|#
directive|define
name|CD_POL_MASK
value|0xFFBF
end_define

begin_define
define|#
directive|define
name|CD_POL_BIT
value|0x0040
end_define

begin_comment
comment|/******************************************************************************  	host.h  	Version 1.2	9/27/93  	Copyright (c) 1993 Analog Devices Inc. All rights reserved  ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SB_WRITE_FULL
value|0x80
end_define

begin_define
define|#
directive|define
name|SB_READ_FULL
value|0x80
end_define

begin_define
define|#
directive|define
name|SB_WRITE_STATUS
value|0x0C
end_define

begin_define
define|#
directive|define
name|SB_READ_STATUS
value|0x0E
end_define

begin_define
define|#
directive|define
name|SB_READ_DATA
value|0x0A
end_define

begin_define
define|#
directive|define
name|SB_WRITE_DATA
value|0x0C
end_define

begin_define
define|#
directive|define
name|PSS_DATA_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|PSS_STATUS_REG
value|0x02
end_define

begin_define
define|#
directive|define
name|PSS_WRITE_EMPTY
value|0x8000
end_define

begin_define
define|#
directive|define
name|PSS_READ_FULL
value|0x4000
end_define

begin_comment
comment|/*_____ 1848 Sound Port bit defines */
end_comment

begin_define
define|#
directive|define
name|SP_IN_INIT
value|0x80
end_define

begin_define
define|#
directive|define
name|MODE_CHANGE_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|MODE_CHANGE_MASK
value|0xbf
end_define

begin_define
define|#
directive|define
name|TRANSFER_DISABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|TRANSFER_DISABLE_MASK
value|0xdf
end_define

begin_define
define|#
directive|define
name|ADDRESS_MASK
value|0xf0
end_define

begin_comment
comment|/*_____ Status bits */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_STATUS
value|0x01
end_define

begin_define
define|#
directive|define
name|PLAYBACK_READY
value|0x02
end_define

begin_define
define|#
directive|define
name|PLAYBACK_LEFT
value|0x04
end_define

begin_comment
comment|/*_____ pbright is not left */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_UPPER
value|0x08
end_define

begin_comment
comment|/*_____ bplower is not upper */
end_comment

begin_define
define|#
directive|define
name|SAMPLE_OVERRUN
value|0x10
end_define

begin_define
define|#
directive|define
name|SAMPLE_UNDERRUN
value|0x10
end_define

begin_define
define|#
directive|define
name|CAPTURE_READY
value|0x20
end_define

begin_define
define|#
directive|define
name|CAPTURE_LEFT
value|0x40
end_define

begin_comment
comment|/*_____ cpright is not left */
end_comment

begin_define
define|#
directive|define
name|CAPTURE_UPPER
value|0x08
end_define

begin_comment
comment|/*_____ cplower is not upper */
end_comment

begin_comment
comment|/*_____ Input& Output regs bits */
end_comment

begin_define
define|#
directive|define
name|LINE_INPUT
value|0x80
end_define

begin_define
define|#
directive|define
name|AUX_INPUT
value|0x40
end_define

begin_define
define|#
directive|define
name|MIC_INPUT
value|0x80
end_define

begin_define
define|#
directive|define
name|MIXED_DAC_INPUT
value|0xC0
end_define

begin_define
define|#
directive|define
name|INPUT_GAIN_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|INPUT_MIC_GAIN_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|INPUT_MIC_GAIN_MASK
value|0xdf
end_define

begin_define
define|#
directive|define
name|INPUT_SOURCE_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|AUX_INPUT_ATTEN_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|AUX_INPUT_MUTE
value|0x80
end_define

begin_define
define|#
directive|define
name|AUX_INPUT_MUTE_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|OUTPUT_MUTE
value|0x80
end_define

begin_define
define|#
directive|define
name|OUTPUT_MUTE_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|OUTPUT_ATTEN_MASK
value|0xc0
end_define

begin_comment
comment|/*_____ Clock and Data format reg bits */
end_comment

begin_define
define|#
directive|define
name|CLOCK_SELECT_MASK
value|0xfe
end_define

begin_define
define|#
directive|define
name|CLOCK_XTAL2
value|0x01
end_define

begin_define
define|#
directive|define
name|CLOCK_XTAL1
value|0x00
end_define

begin_define
define|#
directive|define
name|CLOCK_FREQ_MASK
value|0xf1
end_define

begin_define
define|#
directive|define
name|STEREO_MONO_MASK
value|0xef
end_define

begin_define
define|#
directive|define
name|STEREO
value|0x10
end_define

begin_define
define|#
directive|define
name|AUDIO_MONO
value|0x00
end_define

begin_define
define|#
directive|define
name|LINEAR_COMP_MASK
value|0xdf
end_define

begin_define
define|#
directive|define
name|LINEAR
value|0x00
end_define

begin_define
define|#
directive|define
name|COMPANDED
value|0x20
end_define

begin_define
define|#
directive|define
name|FORMAT_MASK
value|0xbf
end_define

begin_define
define|#
directive|define
name|PCM
value|0x00
end_define

begin_define
define|#
directive|define
name|ULAW
value|0x00
end_define

begin_define
define|#
directive|define
name|TWOS_COMP
value|0x40
end_define

begin_define
define|#
directive|define
name|ALAW
value|0x40
end_define

begin_comment
comment|/*_____ Interface Configuration reg bits */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|PLAYBACK_ENABLE_MASK
value|0xfe
end_define

begin_define
define|#
directive|define
name|CAPTURE_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|CAPTURE_ENABLE_MASK
value|0xfd
end_define

begin_define
define|#
directive|define
name|SINGLE_DMA
value|0x04
end_define

begin_define
define|#
directive|define
name|SINGLE_DMA_MASK
value|0xfb
end_define

begin_define
define|#
directive|define
name|DUAL_DMA
value|0x00
end_define

begin_define
define|#
directive|define
name|AUTO_CAL_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|AUTO_CAL_DISABLE_MASK
value|0xf7
end_define

begin_define
define|#
directive|define
name|PLAYBACK_PIO_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|PLAYBACK_DMA_MASK
value|0xbf
end_define

begin_define
define|#
directive|define
name|CAPTURE_PIO_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|CAPTURE_DMA_MASK
value|0x7f
end_define

begin_comment
comment|/*_____ Pin control bits */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|INTERRUPT_MASK
value|0xfd
end_define

begin_comment
comment|/*_____ Test and init reg bits */
end_comment

begin_define
define|#
directive|define
name|OVERRANGE_LEFT_MASK
value|0xfc
end_define

begin_define
define|#
directive|define
name|OVERRANGE_RIGHT_MASK
value|0xf3
end_define

begin_define
define|#
directive|define
name|DATA_REQUEST_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|AUTO_CAL_IN_PROG
value|0x20
end_define

begin_define
define|#
directive|define
name|PLAYBACK_UNDERRUN
value|0x40
end_define

begin_define
define|#
directive|define
name|CAPTURE_UNDERRUN
value|0x80
end_define

begin_comment
comment|/*_____ Miscellaneous Control reg bits */
end_comment

begin_define
define|#
directive|define
name|ID_MASK
value|0xf0
end_define

begin_comment
comment|/*_____ Digital Mix Control reg bits */
end_comment

begin_define
define|#
directive|define
name|DIGITAL_MIX1_MUTE_MASK
value|0xfe
end_define

begin_define
define|#
directive|define
name|MIX_ATTEN_MASK
value|0x03
end_define

begin_comment
comment|/*_____ 1848 Sound Port reg defines */
end_comment

begin_define
define|#
directive|define
name|SP_LEFT_INPUT_CONTROL
value|0x0
end_define

begin_define
define|#
directive|define
name|SP_RIGHT_INPUT_CONTROL
value|0x1
end_define

begin_define
define|#
directive|define
name|SP_LEFT_AUX1_CONTROL
value|0x2
end_define

begin_define
define|#
directive|define
name|SP_RIGHT_AUX1_CONTROL
value|0x3
end_define

begin_define
define|#
directive|define
name|SP_LEFT_AUX2_CONTROL
value|0x4
end_define

begin_define
define|#
directive|define
name|SP_RIGHT_AUX2_CONTROL
value|0x5
end_define

begin_define
define|#
directive|define
name|SP_LEFT_OUTPUT_CONTROL
value|0x6
end_define

begin_define
define|#
directive|define
name|SP_RIGHT_OUTPUT_CONTROL
value|0x7
end_define

begin_define
define|#
directive|define
name|SP_CLOCK_DATA_FORMAT
value|0x8
end_define

begin_define
define|#
directive|define
name|SP_INTERFACE_CONFIG
value|0x9
end_define

begin_define
define|#
directive|define
name|SP_PIN_CONTROL
value|0xA
end_define

begin_define
define|#
directive|define
name|SP_TEST_AND_INIT
value|0xB
end_define

begin_define
define|#
directive|define
name|SP_MISC_INFO
value|0xC
end_define

begin_define
define|#
directive|define
name|SP_DIGITAL_MIX
value|0xD
end_define

begin_define
define|#
directive|define
name|SP_UPPER_BASE_COUNT
value|0xE
end_define

begin_define
define|#
directive|define
name|SP_LOWER_BASE_COUNT
value|0xF
end_define

begin_define
define|#
directive|define
name|HOST_SP_ADDR
value|(0x534)
end_define

begin_define
define|#
directive|define
name|HOST_SP_DATA
value|(0x535)
end_define

begin_comment
comment|/******************************************************************************  	phillips.h  	Version 1.2	9/27/93  	Copyright (c) 1993 Analog Devices Inc. All rights reserved  ******************************************************************************/
end_comment

begin_comment
comment|/*_____ Phillips control SW defines */
end_comment

begin_comment
comment|/*_____ Settings and ranges */
end_comment

begin_define
define|#
directive|define
name|VOLUME_MAX
value|6
end_define

begin_define
define|#
directive|define
name|VOLUME_MIN
value|(-64)
end_define

begin_define
define|#
directive|define
name|VOLUME_RANGE
value|70
end_define

begin_define
define|#
directive|define
name|VOLUME_STEP
value|2
end_define

begin_define
define|#
directive|define
name|BASS_MAX
value|15
end_define

begin_define
define|#
directive|define
name|BASS_MIN
value|(-12)
end_define

begin_define
define|#
directive|define
name|BASS_STEP
value|2
end_define

begin_define
define|#
directive|define
name|BASS_RANGE
value|27
end_define

begin_define
define|#
directive|define
name|TREBLE_MAX
value|12
end_define

begin_define
define|#
directive|define
name|TREBLE_MIN
value|(-12)
end_define

begin_define
define|#
directive|define
name|TREBLE_STEP
value|2
end_define

begin_define
define|#
directive|define
name|TREBLE_RANGE
value|24
end_define

begin_define
define|#
directive|define
name|VOLUME_CONSTANT
value|252
end_define

begin_define
define|#
directive|define
name|BASS_CONSTANT
value|246
end_define

begin_define
define|#
directive|define
name|TREBLE_CONSTANT
value|246
end_define

begin_comment
comment|/*_____ Software commands */
end_comment

begin_define
define|#
directive|define
name|SET_MASTER_COMMAND
value|0x0010
end_define

begin_define
define|#
directive|define
name|MASTER_VOLUME_LEFT
value|0x0000
end_define

begin_define
define|#
directive|define
name|MASTER_VOLUME_RIGHT
value|0x0100
end_define

begin_define
define|#
directive|define
name|MASTER_BASS
value|0x0200
end_define

begin_define
define|#
directive|define
name|MASTER_TREBLE
value|0x0300
end_define

begin_define
define|#
directive|define
name|MASTER_SWITCH
value|0x0800
end_define

begin_define
define|#
directive|define
name|STEREO_MODE
value|0x00ce
end_define

begin_define
define|#
directive|define
name|PSEUDO_MODE
value|0x00d6
end_define

begin_define
define|#
directive|define
name|SPATIAL_MODE
value|0x00de
end_define

begin_define
define|#
directive|define
name|MONO_MODE
value|0x00c6
end_define

begin_define
define|#
directive|define
name|PSS_STEREO
value|0x00ce
end_define

begin_define
define|#
directive|define
name|PSS_PSEUDO
value|0x00d6
end_define

begin_define
define|#
directive|define
name|PSS_SPATIAL
value|0x00de
end_define

begin_define
define|#
directive|define
name|PSS_MONO
value|0x00c6
end_define

begin_define
define|#
directive|define
name|PHILLIPS_VOL_MIN
value|-64
end_define

begin_define
define|#
directive|define
name|PHILLIPS_VOL_MAX
value|6
end_define

begin_define
define|#
directive|define
name|PHILLIPS_VOL_DELTA
value|70
end_define

begin_define
define|#
directive|define
name|PHILLIPS_VOL_INITIAL
value|-20
end_define

begin_define
define|#
directive|define
name|PHILLIPS_VOL_CONSTANT
value|252
end_define

begin_define
define|#
directive|define
name|PHILLIPS_VOL_STEP
value|2
end_define

begin_define
define|#
directive|define
name|PHILLIPS_BASS_MIN
value|-12
end_define

begin_define
define|#
directive|define
name|PHILLIPS_BASS_MAX
value|15
end_define

begin_define
define|#
directive|define
name|PHILLIPS_BASS_DELTA
value|27
end_define

begin_define
define|#
directive|define
name|PHILLIPS_BASS_INITIAL
value|0
end_define

begin_define
define|#
directive|define
name|PHILLIPS_BASS_CONSTANT
value|246
end_define

begin_define
define|#
directive|define
name|PHILLIPS_BASS_STEP
value|2
end_define

begin_define
define|#
directive|define
name|PHILLIPS_TREBLE_MIN
value|-12
end_define

begin_define
define|#
directive|define
name|PHILLIPS_TREBLE_MAX
value|12
end_define

begin_define
define|#
directive|define
name|PHILLIPS_TREBLE_DELTA
value|24
end_define

begin_define
define|#
directive|define
name|PHILLIPS_TREBLE_INITIAL
value|0
end_define

begin_define
define|#
directive|define
name|PHILLIPS_TREBLE_CONSTANT
value|246
end_define

begin_define
define|#
directive|define
name|PHILLIPS_TREBLE_STEP
value|2
end_define

end_unit

