begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * I/O addresses  */
end_comment

begin_define
define|#
directive|define
name|u_Base
value|(gus_base + 0x000)
end_define

begin_define
define|#
directive|define
name|u_Mixer
value|u_Base
end_define

begin_define
define|#
directive|define
name|u_Status
value|(gus_base + 0x006)
end_define

begin_define
define|#
directive|define
name|u_TimerControl
value|(gus_base + 0x008)
end_define

begin_define
define|#
directive|define
name|u_TimerData
value|(gus_base + 0x009)
end_define

begin_define
define|#
directive|define
name|u_IRQDMAControl
value|(gus_base + 0x00b)
end_define

begin_define
define|#
directive|define
name|u_MidiControl
value|(gus_base + 0x100)
end_define

begin_define
define|#
directive|define
name|MIDI_RESET
value|0x03
end_define

begin_define
define|#
directive|define
name|MIDI_ENABLE_XMIT
value|0x20
end_define

begin_define
define|#
directive|define
name|MIDI_ENABLE_RCV
value|0x80
end_define

begin_define
define|#
directive|define
name|u_MidiStatus
value|u_MidiControl
end_define

begin_define
define|#
directive|define
name|MIDI_RCV_FULL
value|0x01
end_define

begin_define
define|#
directive|define
name|MIDI_XMIT_EMPTY
value|0x02
end_define

begin_define
define|#
directive|define
name|MIDI_FRAME_ERR
value|0x10
end_define

begin_define
define|#
directive|define
name|MIDI_OVERRUN
value|0x20
end_define

begin_define
define|#
directive|define
name|MIDI_IRQ_PEND
value|0x80
end_define

begin_define
define|#
directive|define
name|u_MidiData
value|(gus_base + 0x101)
end_define

begin_define
define|#
directive|define
name|u_Voice
value|(gus_base + 0x102)
end_define

begin_define
define|#
directive|define
name|u_Command
value|(gus_base + 0x103)
end_define

begin_define
define|#
directive|define
name|u_DataLo
value|(gus_base + 0x104)
end_define

begin_define
define|#
directive|define
name|u_DataHi
value|(gus_base + 0x105)
end_define

begin_define
define|#
directive|define
name|u_MixData
value|(gus_base + 0x106)
end_define

begin_comment
comment|/* Rev. 3.7+ mixing */
end_comment

begin_define
define|#
directive|define
name|u_MixSelect
value|(gus_base + 0x506)
end_define

begin_comment
comment|/* registers.       */
end_comment

begin_define
define|#
directive|define
name|u_IrqStatus
value|u_Status
end_define

begin_define
define|#
directive|define
name|MIDI_TX_IRQ
value|0x01
end_define

begin_comment
comment|/* pending MIDI xmit IRQ */
end_comment

begin_define
define|#
directive|define
name|MIDI_RX_IRQ
value|0x02
end_define

begin_comment
comment|/* pending MIDI recv IRQ */
end_comment

begin_define
define|#
directive|define
name|GF1_TIMER1_IRQ
value|0x04
end_define

begin_comment
comment|/* general purpose timer */
end_comment

begin_define
define|#
directive|define
name|GF1_TIMER2_IRQ
value|0x08
end_define

begin_comment
comment|/* general purpose timer */
end_comment

begin_define
define|#
directive|define
name|WAVETABLE_IRQ
value|0x20
end_define

begin_comment
comment|/* pending wavetable IRQ */
end_comment

begin_define
define|#
directive|define
name|ENVELOPE_IRQ
value|0x40
end_define

begin_comment
comment|/* pending volume envelope IRQ */
end_comment

begin_define
define|#
directive|define
name|DMA_TC_IRQ
value|0x80
end_define

begin_comment
comment|/* pending dma tc IRQ */
end_comment

begin_define
define|#
directive|define
name|ICS2101
value|1
end_define

begin_define
define|#
directive|define
name|ICS_MIXDEVS
value|6
end_define

begin_define
define|#
directive|define
name|DEV_MIC
value|0
end_define

begin_define
define|#
directive|define
name|DEV_LINE
value|1
end_define

begin_define
define|#
directive|define
name|DEV_CD
value|2
end_define

begin_define
define|#
directive|define
name|DEV_GF1
value|3
end_define

begin_define
define|#
directive|define
name|DEV_UNUSED
value|4
end_define

begin_define
define|#
directive|define
name|DEV_VOL
value|5
end_define

begin_define
define|#
directive|define
name|CHN_LEFT
value|0
end_define

begin_define
define|#
directive|define
name|CHN_RIGHT
value|1
end_define

begin_define
define|#
directive|define
name|CS4231
value|2
end_define

begin_define
define|#
directive|define
name|u_DRAMIO
value|(gus_base + 0x107)
end_define

end_unit

