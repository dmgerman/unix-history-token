begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * file: sbcard.h  *  * $FreeBSD$  *  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sbc_major
decl_stmt|,
name|sbc_minor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * sound blaster registers  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|DSP_RESET
value|(sbc_base + 0x600)
end_define

begin_define
define|#
directive|define
name|DSP_READ
value|(sbc_base + 0xA00)
end_define

begin_define
define|#
directive|define
name|DSP_WRITE
value|(sbc_base + 0xC00)
end_define

begin_define
define|#
directive|define
name|DSP_COMMAND
value|(sbc_base + 0xC00)
end_define

begin_define
define|#
directive|define
name|DSP_STATUS
value|(sbc_base + 0xC00)
end_define

begin_define
define|#
directive|define
name|DSP_DATA_AVAIL
value|(sbc_base + 0xE00)
end_define

begin_define
define|#
directive|define
name|DSP_DATA_AVL16
value|(sbc_base + 0xF00)
end_define

begin_define
define|#
directive|define
name|MIXER_ADDR
value|(sbc_base + 0x400)
end_define

begin_define
define|#
directive|define
name|MIXER_DATA
value|(sbc_base + 0x500)
end_define

begin_define
define|#
directive|define
name|OPL3_LEFT
value|(sbc_base + 0x000)
end_define

begin_define
define|#
directive|define
name|OPL3_RIGHT
value|(sbc_base + 0x200)
end_define

begin_define
define|#
directive|define
name|OPL3_BOTH
value|(sbc_base + 0x800)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DSP_RESET
value|(sbc_base + 0x6)
end_define

begin_define
define|#
directive|define
name|DSP_READ
value|(sbc_base + 0xA)
end_define

begin_define
define|#
directive|define
name|DSP_WRITE
value|(sbc_base + 0xC)
end_define

begin_define
define|#
directive|define
name|DSP_COMMAND
value|(sbc_base + 0xC)
end_define

begin_define
define|#
directive|define
name|DSP_STATUS
value|(sbc_base + 0xC)
end_define

begin_define
define|#
directive|define
name|DSP_DATA_AVAIL
value|(sbc_base + 0xE)
end_define

begin_define
define|#
directive|define
name|DSP_DATA_AVL16
value|(sbc_base + 0xF)
end_define

begin_define
define|#
directive|define
name|MIXER_ADDR
value|(sbc_base + 0x4)
end_define

begin_define
define|#
directive|define
name|MIXER_DATA
value|(sbc_base + 0x5)
end_define

begin_define
define|#
directive|define
name|OPL3_LEFT
value|(sbc_base + 0x0)
end_define

begin_define
define|#
directive|define
name|OPL3_RIGHT
value|(sbc_base + 0x2)
end_define

begin_define
define|#
directive|define
name|OPL3_BOTH
value|(sbc_base + 0x8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * DSP Commands. There are many, and in many cases they are used explicitly  */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_SPKON
value|0xD1
end_define

begin_define
define|#
directive|define
name|DSP_CMD_SPKOFF
value|0xD3
end_define

begin_define
define|#
directive|define
name|DSP_CMD_DMAON
value|0xD0
end_define

begin_comment
comment|/* ??? the comment says Halt DMA */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_DMAOFF
value|0xD4
end_define

begin_comment
comment|/* ??? comment says continue dma */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_DMAHALT
value|0xD0
end_define

begin_define
define|#
directive|define
name|DSP_CMD_TCONST
value|0x40
end_define

begin_comment
comment|/* set time constant */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_HSSIZE
value|0x48
end_define

begin_comment
comment|/* high speed dma count */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_HSDAC
value|0x91
end_define

begin_comment
comment|/* high speed dac */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_HSADC
value|0x99
end_define

begin_comment
comment|/* high speed adc */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_DAC8
value|0x14
end_define

begin_comment
comment|/* 8-bit dac (dma count) */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_ADC8
value|0x24
end_define

begin_comment
comment|/* 8-bit adc (dma count) */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_GETVER
value|0xE1
end_define

begin_define
define|#
directive|define
name|DSP_CMD_GETID
value|0xE7
end_define

begin_comment
comment|/* return id bytes */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*** unknown ***/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IMODE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|IMODE_OUTPUT
value|PCM_ENABLE_OUTPUT
end_define

begin_define
define|#
directive|define
name|IMODE_INPUT
value|PCM_ENABLE_INPUT
end_define

begin_define
define|#
directive|define
name|IMODE_INIT
value|3
end_define

begin_define
define|#
directive|define
name|IMODE_MIDI
value|4
end_define

begin_define
define|#
directive|define
name|NORMAL_MIDI
value|0
end_define

begin_define
define|#
directive|define
name|UART_MIDI
value|1
end_define

end_unit

