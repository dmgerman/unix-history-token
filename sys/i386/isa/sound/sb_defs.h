begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|/* DSP Commands */
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

begin_define
define|#
directive|define
name|DSP_CMD_DMAOFF
value|0xD4
end_define

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
value|1
end_define

begin_define
define|#
directive|define
name|IMODE_INPUT
value|2
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

