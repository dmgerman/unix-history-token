begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/*  FILE   : iwdefs.h*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*  REMARKS: This file contains all defines used by DDK functions. It*/
end_comment

begin_comment
comment|/*           should be included by all applications and should be*/
end_comment

begin_comment
comment|/*           referenced by programmers to make their code easy to read*/
end_comment

begin_comment
comment|/*           and understand.*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*  UPDATE: 3/21/95*/
end_comment

begin_comment
comment|/*          7/10/95 --- added #def DRAM_HOLES*/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IWDEFS
end_ifndef

begin_define
define|#
directive|define
name|IWDEFS
end_define

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* Macros for use in loading Synth Addr Regs*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|ADDR_HIGH
parameter_list|(
name|x
parameter_list|)
value|(short)(x>>7)
end_define

begin_define
define|#
directive|define
name|ADDR_LOW
parameter_list|(
name|x
parameter_list|)
value|(short)(x<<9)
end_define

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*     Defines for DMA Controllers*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/* DMA Controler #1 (8-bit controller) */
end_comment

begin_define
define|#
directive|define
name|DMA1_STAT
value|0x08
end_define

begin_comment
comment|/* read status register */
end_comment

begin_define
define|#
directive|define
name|DMA1_WCMD
value|0x08
end_define

begin_comment
comment|/* write command register */
end_comment

begin_define
define|#
directive|define
name|DMA1_WREQ
value|0x09
end_define

begin_comment
comment|/* write request register */
end_comment

begin_define
define|#
directive|define
name|DMA1_SNGL
value|0x0A
end_define

begin_comment
comment|/* write single bit register */
end_comment

begin_define
define|#
directive|define
name|DMA1_MODE
value|0x0B
end_define

begin_comment
comment|/* write mode register */
end_comment

begin_define
define|#
directive|define
name|DMA1_CLRFF
value|0x0C
end_define

begin_comment
comment|/* clear byte ptr flip/flop */
end_comment

begin_define
define|#
directive|define
name|DMA1_MCLR
value|0x0D
end_define

begin_comment
comment|/* master clear register */
end_comment

begin_define
define|#
directive|define
name|DMA1_CLRM
value|0x0E
end_define

begin_comment
comment|/* clear mask register */
end_comment

begin_define
define|#
directive|define
name|DMA1_WRTALL
value|0x0F
end_define

begin_comment
comment|/* write all mask register */
end_comment

begin_comment
comment|/* DMA Controler #2 (16-bit controller) */
end_comment

begin_define
define|#
directive|define
name|DMA2_STAT
value|0xD0
end_define

begin_comment
comment|/* read status register */
end_comment

begin_define
define|#
directive|define
name|DMA2_WCMD
value|0xD0
end_define

begin_comment
comment|/* write command register */
end_comment

begin_define
define|#
directive|define
name|DMA2_WREQ
value|0xD2
end_define

begin_comment
comment|/* write request register */
end_comment

begin_define
define|#
directive|define
name|DMA2_SNGL
value|0xD4
end_define

begin_comment
comment|/* write single bit register */
end_comment

begin_define
define|#
directive|define
name|DMA2_MODE
value|0xD6
end_define

begin_comment
comment|/* write mode register */
end_comment

begin_define
define|#
directive|define
name|DMA2_CLRFF
value|0xD8
end_define

begin_comment
comment|/* clear byte ptr flip/flop */
end_comment

begin_define
define|#
directive|define
name|DMA2_MCLR
value|0xDA
end_define

begin_comment
comment|/* master clear register */
end_comment

begin_define
define|#
directive|define
name|DMA2_CLRM
value|0xDC
end_define

begin_comment
comment|/* clear mask register */
end_comment

begin_define
define|#
directive|define
name|DMA2_WRTALL
value|0xDE
end_define

begin_comment
comment|/* write all mask register */
end_comment

begin_define
define|#
directive|define
name|DMA0_ADDR
value|0x00
end_define

begin_comment
comment|/* chan 0 base adddress */
end_comment

begin_define
define|#
directive|define
name|DMA0_CNT
value|0x01
end_define

begin_comment
comment|/* chan 0 base count */
end_comment

begin_define
define|#
directive|define
name|DMA1_ADDR
value|0x02
end_define

begin_comment
comment|/* chan 1 base adddress */
end_comment

begin_define
define|#
directive|define
name|DMA1_CNT
value|0x03
end_define

begin_comment
comment|/* chan 1 base count */
end_comment

begin_define
define|#
directive|define
name|DMA2_ADDR
value|0x04
end_define

begin_comment
comment|/* chan 2 base adddress */
end_comment

begin_define
define|#
directive|define
name|DMA2_CNT
value|0x05
end_define

begin_comment
comment|/* chan 2 base count */
end_comment

begin_define
define|#
directive|define
name|DMA3_ADDR
value|0x06
end_define

begin_comment
comment|/* chan 3 base adddress */
end_comment

begin_define
define|#
directive|define
name|DMA3_CNT
value|0x07
end_define

begin_comment
comment|/* chan 3 base count */
end_comment

begin_define
define|#
directive|define
name|DMA4_ADDR
value|0xC0
end_define

begin_comment
comment|/* chan 4 base adddress */
end_comment

begin_define
define|#
directive|define
name|DMA4_CNT
value|0xC2
end_define

begin_comment
comment|/* chan 4 base count */
end_comment

begin_define
define|#
directive|define
name|DMA5_ADDR
value|0xC4
end_define

begin_comment
comment|/* chan 5 base adddress */
end_comment

begin_define
define|#
directive|define
name|DMA5_CNT
value|0xC6
end_define

begin_comment
comment|/* chan 5 base count */
end_comment

begin_define
define|#
directive|define
name|DMA6_ADDR
value|0xC8
end_define

begin_comment
comment|/* chan 6 base adddress */
end_comment

begin_define
define|#
directive|define
name|DMA6_CNT
value|0xCA
end_define

begin_comment
comment|/* chan 6 base count */
end_comment

begin_define
define|#
directive|define
name|DMA7_ADDR
value|0xCC
end_define

begin_comment
comment|/* chan 7 base adddress */
end_comment

begin_define
define|#
directive|define
name|DMA7_CNT
value|0xCE
end_define

begin_comment
comment|/* chan 7 base count */
end_comment

begin_define
define|#
directive|define
name|DMA0_PAGE
value|0x87
end_define

begin_comment
comment|/* chan 0 page register (refresh)*/
end_comment

begin_define
define|#
directive|define
name|DMA1_PAGE
value|0x83
end_define

begin_comment
comment|/* chan 1 page register */
end_comment

begin_define
define|#
directive|define
name|DMA2_PAGE
value|0x81
end_define

begin_comment
comment|/* chan 2 page register */
end_comment

begin_define
define|#
directive|define
name|DMA3_PAGE
value|0x82
end_define

begin_comment
comment|/* chan 3 page register */
end_comment

begin_define
define|#
directive|define
name|DMA4_PAGE
value|0x8F
end_define

begin_comment
comment|/* chan 4 page register (unusable)*/
end_comment

begin_define
define|#
directive|define
name|DMA5_PAGE
value|0x8B
end_define

begin_comment
comment|/* chan 5 page register */
end_comment

begin_define
define|#
directive|define
name|DMA6_PAGE
value|0x89
end_define

begin_comment
comment|/* chan 6 page register */
end_comment

begin_define
define|#
directive|define
name|DMA7_PAGE
value|0x8A
end_define

begin_comment
comment|/* chan 7 page register */
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* Defines for register UISR (Interrupt Status)*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|MIDI_TX_IRQ
value|0x01
end_define

begin_define
define|#
directive|define
name|MIDI_RX_IRQ
value|0x02
end_define

begin_define
define|#
directive|define
name|ALIB_TIMER1_IRQ
value|0x04
end_define

begin_define
define|#
directive|define
name|ALIB_TIMER2_IRQ
value|0x08
end_define

begin_define
define|#
directive|define
name|_UASBCI
value|0x45
end_define

begin_comment
comment|/* UASBCI index */
end_comment

begin_define
define|#
directive|define
name|SAMPLE_CONTROL
value|0x49
end_define

begin_comment
comment|/* Not used by IW */
end_comment

begin_define
define|#
directive|define
name|SET_VOICES
value|0x0E
end_define

begin_define
define|#
directive|define
name|WAVETABLE_IRQ
value|0x20
end_define

begin_define
define|#
directive|define
name|ENVELOPE_IRQ
value|0x40
end_define

begin_define
define|#
directive|define
name|DMA_TC_IRQ
value|0x80
end_define

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*            Synthesizer-related defines*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|GEN_INDEX
value|0x03
end_define

begin_comment
comment|/* IGIDX offset into p3xr */
end_comment

begin_define
define|#
directive|define
name|VOICE_SELECT
value|0x02
end_define

begin_comment
comment|/* SVSR offset into p3xr */
end_comment

begin_define
define|#
directive|define
name|VOICE_IRQS
value|0x8F
end_define

begin_comment
comment|/* SVII index (read) */
end_comment

begin_define
define|#
directive|define
name|_URSTI
value|0x4C
end_define

begin_comment
comment|/* URSTI index */
end_comment

begin_define
define|#
directive|define
name|GF1_SET
value|0x01
end_define

begin_comment
comment|/* URSTI[0] */
end_comment

begin_define
define|#
directive|define
name|GF1_OUT_ENABLE
value|0x02
end_define

begin_comment
comment|/* URSTI[1] */
end_comment

begin_define
define|#
directive|define
name|GF1_IRQ_ENABLE
value|0x04
end_define

begin_comment
comment|/* URSTI[2] */
end_comment

begin_define
define|#
directive|define
name|GF1_RESET
value|0xFE
end_define

begin_comment
comment|/* URSTI[0]=0 */
end_comment

begin_define
define|#
directive|define
name|VOICE_VOLUME_IRQ
value|0x04
end_define

begin_comment
comment|/* SVII[2] */
end_comment

begin_define
define|#
directive|define
name|VOICE_WAVE_IRQ
value|0x08
end_define

begin_comment
comment|/* SVII[3] */
end_comment

begin_define
define|#
directive|define
name|VC_IRQ_ENABLE
value|0x20
end_define

begin_comment
comment|/* SACI[5] or SVCI[5]*/
end_comment

begin_define
define|#
directive|define
name|VOICE_NUMBER
value|0x1F
end_define

begin_comment
comment|/* Mask for SVII[4:0] */
end_comment

begin_define
define|#
directive|define
name|VC_IRQ_PENDING
value|0x80
end_define

begin_comment
comment|/* SACI[7] or SVCI[7] */
end_comment

begin_define
define|#
directive|define
name|VC_DIRECT
value|0x40
end_define

begin_comment
comment|/* SACI[6] or SVCI[6]*/
end_comment

begin_define
define|#
directive|define
name|VC_DATA_WIDTH
value|0x04
end_define

begin_comment
comment|/* SACI[2] */
end_comment

begin_define
define|#
directive|define
name|VOICE_STOP
value|0x02
end_define

begin_comment
comment|/* SACI[1] */
end_comment

begin_define
define|#
directive|define
name|VOICE_STOPPED
value|0x01
end_define

begin_comment
comment|/* SACI[0] */
end_comment

begin_define
define|#
directive|define
name|VOLUME_STOP
value|0x02
end_define

begin_comment
comment|/* SVCI[1] */
end_comment

begin_define
define|#
directive|define
name|VOLUME_STOPPED
value|0x01
end_define

begin_comment
comment|/* SVCI[0] */
end_comment

begin_define
define|#
directive|define
name|VC_ROLLOVER
value|0x04
end_define

begin_comment
comment|/* SVCI[2] */
end_comment

begin_define
define|#
directive|define
name|VC_LOOP_ENABLE
value|0x08
end_define

begin_comment
comment|/* SVCI[3] or SACI[3]*/
end_comment

begin_define
define|#
directive|define
name|VC_BI_LOOP
value|0x10
end_define

begin_comment
comment|/* SVCI[4] or SACI[4]*/
end_comment

begin_define
define|#
directive|define
name|VOICE_OFFSET
value|0x20
end_define

begin_comment
comment|/* SMSI[5] */
end_comment

begin_define
define|#
directive|define
name|VOLUME_RATE0
value|0x00
end_define

begin_comment
comment|/* SVRI[7:6]=(0,0) */
end_comment

begin_define
define|#
directive|define
name|VOLUME_RATE1
value|0x40
end_define

begin_comment
comment|/* SVRI[7:6]=(0,1) */
end_comment

begin_define
define|#
directive|define
name|VOLUME_RATE2
value|0x80
end_define

begin_comment
comment|/* SVRI[7:6]=(1,0) */
end_comment

begin_define
define|#
directive|define
name|VOLUME_RATE3
value|0xC0
end_define

begin_comment
comment|/* SVRI[7:6]=(1,1) */
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*         Power-Mode Control Defines*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|SHUT_DOWN
value|0x7E
end_define

begin_comment
comment|/* shuts InterWave down */
end_comment

begin_define
define|#
directive|define
name|POWER_UP
value|0xFE
end_define

begin_comment
comment|/* enables all modules */
end_comment

begin_define
define|#
directive|define
name|CODEC_PWR_UP
value|0x81
end_define

begin_comment
comment|/* enables Codec Analog Ckts */
end_comment

begin_define
define|#
directive|define
name|CODEC_PWR_DOWN
value|0x01
end_define

begin_comment
comment|/* disables Codec Analog Ckts */
end_comment

begin_define
define|#
directive|define
name|CODEC_REC_UP
value|0x82
end_define

begin_comment
comment|/* Enables Record Path */
end_comment

begin_define
define|#
directive|define
name|CODEC_REC_DOWN
value|0x02
end_define

begin_comment
comment|/* Disables Record Path */
end_comment

begin_define
define|#
directive|define
name|CODEC_PLAY_UP
value|0x84
end_define

begin_comment
comment|/* Enables Playback Path */
end_comment

begin_define
define|#
directive|define
name|CODEC_PLAY_DOWN
value|0x04
end_define

begin_comment
comment|/* Disables Playback Path */
end_comment

begin_define
define|#
directive|define
name|CODEC_IRQ_ENABLE
value|0x02
end_define

begin_comment
comment|/* CEXTI[2] */
end_comment

begin_define
define|#
directive|define
name|CODEC_TIMER_IRQ
value|0x40
end_define

begin_comment
comment|/* CSR3I[6] */
end_comment

begin_define
define|#
directive|define
name|CODEC_REC_IRQ
value|0x20
end_define

begin_comment
comment|/* CSR3I[5] */
end_comment

begin_define
define|#
directive|define
name|CODEC_PLAY_IRQ
value|0x10
end_define

begin_comment
comment|/* CSR3I[4] */
end_comment

begin_define
define|#
directive|define
name|CODEC_INT
value|0x01
end_define

begin_comment
comment|/* CSR1R[0] */
end_comment

begin_define
define|#
directive|define
name|MONO_INPUT
value|0x80
end_define

begin_comment
comment|/* CMONOI[7] */
end_comment

begin_define
define|#
directive|define
name|MONO_OUTPUT
value|0x40
end_define

begin_comment
comment|/* CMONOI[6] */
end_comment

begin_define
define|#
directive|define
name|MIDI_UP
value|0x88
end_define

begin_comment
comment|/* Enables MIDI ports */
end_comment

begin_define
define|#
directive|define
name|MIDI_DOWN
value|0x08
end_define

begin_comment
comment|/* Disables MIDI ports */
end_comment

begin_define
define|#
directive|define
name|SYNTH_UP
value|0x90
end_define

begin_comment
comment|/* Enables Synthesizer */
end_comment

begin_define
define|#
directive|define
name|SYNTH_DOWN
value|0x10
end_define

begin_comment
comment|/* Disables Synthesizer */
end_comment

begin_define
define|#
directive|define
name|LMC_UP
value|0xA0
end_define

begin_comment
comment|/* Enables LM Module */
end_comment

begin_define
define|#
directive|define
name|LMC_DOWN
value|0x20
end_define

begin_comment
comment|/* Disbales LM Module */
end_comment

begin_define
define|#
directive|define
name|XTAL24_UP
value|0xC0
end_define

begin_comment
comment|/* Enables 24MHz Osc */
end_comment

begin_define
define|#
directive|define
name|XTAL24_DOWN
value|0x40
end_define

begin_comment
comment|/* Disables 24MHz Osc */
end_comment

begin_define
define|#
directive|define
name|_PPWRI
value|0xF2
end_define

begin_comment
comment|/* PPWRI index */
end_comment

begin_define
define|#
directive|define
name|PLAY
value|0x0F
end_define

begin_define
define|#
directive|define
name|REC
value|0x1F
end_define

begin_define
define|#
directive|define
name|LEFT_AUX1_INPUT
value|0x02
end_define

begin_define
define|#
directive|define
name|RIGHT_AUX1_INPUT
value|0x03
end_define

begin_define
define|#
directive|define
name|LEFT_AUX2_INPUT
value|0x04
end_define

begin_define
define|#
directive|define
name|RIGHT_AUX2_INPUT
value|0x05
end_define

begin_define
define|#
directive|define
name|LEFT_LINE_IN
value|0x12
end_define

begin_define
define|#
directive|define
name|RIGHT_LINE_IN
value|0x13
end_define

begin_define
define|#
directive|define
name|LEFT_LINE_OUT
value|0x19
end_define

begin_define
define|#
directive|define
name|RIGHT_LINE_OUT
value|0x1B
end_define

begin_define
define|#
directive|define
name|LEFT_SOURCE
value|0x00
end_define

begin_define
define|#
directive|define
name|RIGHT_SOURCE
value|0x01
end_define

begin_define
define|#
directive|define
name|LINE_IN
value|0x00
end_define

begin_define
define|#
directive|define
name|AUX1_IN
value|0x40
end_define

begin_define
define|#
directive|define
name|MIC_IN
value|0x80
end_define

begin_define
define|#
directive|define
name|MIX_IN
value|0xC0
end_define

begin_define
define|#
directive|define
name|LEFT_DAC
value|0x06
end_define

begin_define
define|#
directive|define
name|RIGHT_DAC
value|0x07
end_define

begin_define
define|#
directive|define
name|LEFT_MIC_IN
value|0x16
end_define

begin_define
define|#
directive|define
name|RIGHT_MIC_IN
value|0x17
end_define

begin_define
define|#
directive|define
name|_CUPCTI
value|0x0E
end_define

begin_define
define|#
directive|define
name|_CLPCTI
value|0x0F
end_define

begin_define
define|#
directive|define
name|_CURCTI
value|0x1E
end_define

begin_define
define|#
directive|define
name|_CLRCTI
value|0x1F
end_define

begin_define
define|#
directive|define
name|_CLAX1I
value|0x02
end_define

begin_define
define|#
directive|define
name|_CRAX1I
value|0x03
end_define

begin_define
define|#
directive|define
name|_CLAX2I
value|0x04
end_define

begin_define
define|#
directive|define
name|_CRAX2I
value|0x05
end_define

begin_define
define|#
directive|define
name|_CLLICI
value|0x12
end_define

begin_define
define|#
directive|define
name|_CRLICI
value|0x13
end_define

begin_define
define|#
directive|define
name|_CLOAI
value|0x19
end_define

begin_define
define|#
directive|define
name|_CROAI
value|0x1B
end_define

begin_define
define|#
directive|define
name|_CLICI
value|0x00
end_define

begin_define
define|#
directive|define
name|_CRICI
value|0x01
end_define

begin_define
define|#
directive|define
name|_CLDACI
value|0x06
end_define

begin_define
define|#
directive|define
name|_CRDACI
value|0x07
end_define

begin_define
define|#
directive|define
name|_CPVFI
value|0x1D
end_define

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* Defines for DMA transfer related operations*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|MAX_DMA
value|0x07
end_define

begin_define
define|#
directive|define
name|DMA_DECREMENT
value|0x20
end_define

begin_define
define|#
directive|define
name|AUTO_INIT
value|0x10
end_define

begin_define
define|#
directive|define
name|DMA_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|DMA_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|AUTO_READ
value|0x03
end_define

begin_define
define|#
directive|define
name|AUTO_WRITE
value|0x04
end_define

begin_define
define|#
directive|define
name|IDMA_INV
value|0x0400
end_define

begin_define
define|#
directive|define
name|IDMA_WIDTH_16
value|0x0100
end_define

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* Bits for dma flags within a DMA structure.*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|DMA_USED
value|0x0001
end_define

begin_define
define|#
directive|define
name|DMA_SPLIT
value|0x0004
end_define

begin_comment
comment|/* DMA Controller Page Crossover*/
end_comment

begin_define
define|#
directive|define
name|CODEC_DMA
value|0x0008
end_define

begin_comment
comment|/* Indicates a Codec DMA*/
end_comment

begin_define
define|#
directive|define
name|DMA_WAIT
value|0x0020
end_define

begin_comment
comment|/* Wait for DMA xfer to complete*/
end_comment

begin_define
define|#
directive|define
name|DMA_DOWN
value|0x0040
end_define

begin_comment
comment|/* DMA xfer from PC to InterWave*/
end_comment

begin_define
define|#
directive|define
name|DRAM_HOLES
value|0x8000
end_define

begin_comment
comment|/* Indicates Non-contiguous RAM configuration*/
end_comment

begin_define
define|#
directive|define
name|DMA_UP
value|0xFFBF
end_define

begin_comment
comment|/* DMA xfer from InterWave to PC */
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* Bits for DMA Control Register (LDMACI)*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|_LDMACI
value|0x41
end_define

begin_comment
comment|/* Index */
end_comment

begin_define
define|#
directive|define
name|DMA_INV
value|0x80
end_define

begin_define
define|#
directive|define
name|DMA_IRQ_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|DMA_IRQ_PENDING
value|0x40
end_define

begin_comment
comment|/* on reads of LDMACI[6] */
end_comment

begin_define
define|#
directive|define
name|DMA_DATA_16
value|0x40
end_define

begin_comment
comment|/* on writes to LDMACI[6] */
end_comment

begin_define
define|#
directive|define
name|DMA_WIDTH_16
value|0x04
end_define

begin_comment
comment|/* 1=16-bit, 0=8-bit (DMA channel) */
end_comment

begin_define
define|#
directive|define
name|DMA_RATE
value|0x18
end_define

begin_comment
comment|/* 00=fastest,...,11=slowest */
end_comment

begin_define
define|#
directive|define
name|DMA_UPLOAD
value|0x02
end_define

begin_comment
comment|/* From LM to PC */
end_comment

begin_define
define|#
directive|define
name|DMA_ENABLE
value|0x01
end_define

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*    DMA Transfer Rates*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|DMA_R0
value|0xE7
end_define

begin_comment
comment|/* Fastest (use ANDing to set) */
end_comment

begin_define
define|#
directive|define
name|DMA_R1
value|0x08
end_define

begin_define
define|#
directive|define
name|DMA_R2
value|0x10
end_define

begin_define
define|#
directive|define
name|DMA_R3
value|0x18
end_define

begin_comment
comment|/* Slowest */
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*    Interrupt Controller Defines*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|IW_HANDLERS_ON
value|0x80
end_define

begin_comment
comment|/* Flag for when IVT is modified */
end_comment

begin_define
define|#
directive|define
name|EOI
value|0x20
end_define

begin_define
define|#
directive|define
name|OCR1
value|0x20
end_define

begin_comment
comment|/* 8259-1 Operation Control Reg. */
end_comment

begin_define
define|#
directive|define
name|IMR1
value|0x21
end_define

begin_comment
comment|/* 8259-1 Interrupt Mask Reg. */
end_comment

begin_define
define|#
directive|define
name|OCR2
value|0xA0
end_define

begin_comment
comment|/* 8259-2 Operation Control Reg. */
end_comment

begin_define
define|#
directive|define
name|IMR2
value|0xA1
end_define

begin_comment
comment|/* 8259-2 Interrupt Mask Reg. */
end_comment

begin_define
define|#
directive|define
name|IRQ0_UNMASK
value|0xFE
end_define

begin_comment
comment|/* Mask to clear bit 0 in IMR */
end_comment

begin_define
define|#
directive|define
name|IRQ1_UNMASK
value|0xFD
end_define

begin_define
define|#
directive|define
name|IRQ2_UNMASK
value|0xFB
end_define

begin_define
define|#
directive|define
name|IRQ3_UNMASK
value|0xF7
end_define

begin_define
define|#
directive|define
name|IRQ4_UNMASK
value|0xEF
end_define

begin_define
define|#
directive|define
name|IRQ5_UNMASK
value|0xDF
end_define

begin_define
define|#
directive|define
name|IRQ6_UNMASK
value|0xBF
end_define

begin_define
define|#
directive|define
name|IRQ7_UNMASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|IRQ8_UNMASK
value|0xFE
end_define

begin_comment
comment|/* Mask to clear bit 0 in IMR */
end_comment

begin_define
define|#
directive|define
name|IRQ9_UNMASK
value|0xFD
end_define

begin_define
define|#
directive|define
name|IRQ10_UNMASK
value|0xFB
end_define

begin_define
define|#
directive|define
name|IRQ11_UNMASK
value|0xF7
end_define

begin_define
define|#
directive|define
name|IRQ12_UNMASK
value|0xEF
end_define

begin_define
define|#
directive|define
name|IRQ13_UNMASK
value|0xDF
end_define

begin_define
define|#
directive|define
name|IRQ14_UNMASK
value|0xBF
end_define

begin_define
define|#
directive|define
name|IRQ15_UNMASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|IRQ0_EOI
value|0x60
end_define

begin_comment
comment|/* Spec EOI for IRQ0 */
end_comment

begin_define
define|#
directive|define
name|IRQ1_EOI
value|0x61
end_define

begin_define
define|#
directive|define
name|IRQ2_EOI
value|0x62
end_define

begin_define
define|#
directive|define
name|IRQ3_EOI
value|0x63
end_define

begin_define
define|#
directive|define
name|IRQ4_EOI
value|0x64
end_define

begin_define
define|#
directive|define
name|IRQ5_EOI
value|0x65
end_define

begin_define
define|#
directive|define
name|IRQ6_EOI
value|0x66
end_define

begin_define
define|#
directive|define
name|IRQ7_EOI
value|0x67
end_define

begin_define
define|#
directive|define
name|IRQ8_EOI
value|0x60
end_define

begin_comment
comment|/* Spec EOI for IRQ8 */
end_comment

begin_define
define|#
directive|define
name|IRQ9_EOI
value|0x61
end_define

begin_define
define|#
directive|define
name|IRQ10_EOI
value|0x62
end_define

begin_define
define|#
directive|define
name|IRQ11_EOI
value|0x63
end_define

begin_define
define|#
directive|define
name|IRQ12_EOI
value|0x64
end_define

begin_define
define|#
directive|define
name|IRQ13_EOI
value|0x65
end_define

begin_define
define|#
directive|define
name|IRQ14_EOI
value|0x66
end_define

begin_define
define|#
directive|define
name|IRQ15_EOI
value|0x67
end_define

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*     Generic defines*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|MEMBANK0
value|0L
end_define

begin_comment
comment|/* Addr of Memory Bank 0*/
end_comment

begin_define
define|#
directive|define
name|MEMBANK1
value|4194304L
end_define

begin_comment
comment|/* Addr of Memory Bank 1*/
end_comment

begin_define
define|#
directive|define
name|MEMBANK2
value|8388608L
end_define

begin_comment
comment|/* Addr of Memory Bank 2*/
end_comment

begin_define
define|#
directive|define
name|MEMBANK3
value|12582912L
end_define

begin_comment
comment|/* Addr of Memory Bank 3*/
end_comment

begin_define
define|#
directive|define
name|IRQ_UNAVAIL
value|0x0000
end_define

begin_define
define|#
directive|define
name|IRQ_AVAIL
value|0x0001
end_define

begin_define
define|#
directive|define
name|IRQ_USED
value|0x0002
end_define

begin_define
define|#
directive|define
name|MAX_IRQ
value|16
end_define

begin_define
define|#
directive|define
name|NEXT_OFFSET
value|0L
end_define

begin_define
define|#
directive|define
name|PREV_OFFSET
value|4L
end_define

begin_define
define|#
directive|define
name|SIZE_OFFSET
value|8L
end_define

begin_define
define|#
directive|define
name|MEM_HEADER_SIZE
value|12L
end_define

begin_define
define|#
directive|define
name|GF1_POOL
value|(usigned long)(256L*1024L)
end_define

begin_define
define|#
directive|define
name|GUS_MODE
value|0x00
end_define

begin_comment
comment|/* SGMI[0]=0*/
end_comment

begin_define
define|#
directive|define
name|ENH_MODE
value|0x01
end_define

begin_comment
comment|/* SGMI[0]=1*/
end_comment

begin_define
define|#
directive|define
name|ENABLE_LFOS
value|0x02
end_define

begin_comment
comment|/* SGMI[1]*/
end_comment

begin_define
define|#
directive|define
name|NO_WAVETABLE
value|0x04
end_define

begin_comment
comment|/* SGMI[2]*/
end_comment

begin_define
define|#
directive|define
name|RAM_TEST
value|0x08
end_define

begin_comment
comment|/* SGMI[3]*/
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_define
define|#
directive|define
name|AUDIO
value|0
end_define

begin_define
define|#
directive|define
name|EXT
value|1
end_define

begin_define
define|#
directive|define
name|GAME
value|2
end_define

begin_define
define|#
directive|define
name|EMULATION
value|3
end_define

begin_define
define|#
directive|define
name|MPU401
value|4
end_define

begin_define
define|#
directive|define
name|AUDIO_EXT
value|2
end_define

begin_define
define|#
directive|define
name|ALLOC_FAILURE
value|0xFFFFFFFFL
end_define

begin_define
define|#
directive|define
name|MEM_EXHAUSTED
value|0xFFFFFFFFL
end_define

begin_define
define|#
directive|define
name|RAM_MAX
value|16777216L
end_define

begin_define
define|#
directive|define
name|RAM_STEP
value|65536L
end_define

begin_define
define|#
directive|define
name|BANK_MAX
value|4194304L
end_define

begin_define
define|#
directive|define
name|ILLEGAL_SIZE
value|-1
end_define

begin_define
define|#
directive|define
name|MEM_INIT
value|1
end_define

begin_define
define|#
directive|define
name|NO_NEXT
value|0xFFFFFFFFL
end_define

begin_define
define|#
directive|define
name|NO_PREV
value|NO_NEXT
end_define

begin_define
define|#
directive|define
name|DMA_BAD_ADDR
value|-1
end_define

begin_define
define|#
directive|define
name|DMA_ON
value|-1
end_define

begin_define
define|#
directive|define
name|DMA_OK
value|1
end_define

begin_define
define|#
directive|define
name|MIDI_TX_IRQ
value|0x01
end_define

begin_define
define|#
directive|define
name|MIDI_RX_IRQ
value|0x02
end_define

begin_define
define|#
directive|define
name|ALIB_TIMER1_IRQ
value|0x04
end_define

begin_define
define|#
directive|define
name|ALIB_TIMER2_IRQ
value|0x08
end_define

begin_define
define|#
directive|define
name|WAVETABLE_IRQ
value|0x20
end_define

begin_define
define|#
directive|define
name|ENVELOPE_IRQ
value|0x40
end_define

begin_define
define|#
directive|define
name|DMA_TC_IRQ
value|0x80
end_define

begin_define
define|#
directive|define
name|DMA_SET_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|PNP_DATA_RDY
value|1
end_define

begin_comment
comment|/* PRESSI[0] */
end_comment

begin_define
define|#
directive|define
name|IWAVE_ABSENT
value|2
end_define

begin_define
define|#
directive|define
name|IWAVE_OPEN
value|4
end_define

begin_define
define|#
directive|define
name|IWAVE_OK
value|5
end_define

begin_define
define|#
directive|define
name|BAD_VOICES
value|-1
end_define

begin_define
define|#
directive|define
name|PNP_ABSENT
value|0xFF
end_define

begin_comment
comment|/* No PNP cards in system */
end_comment

begin_define
define|#
directive|define
name|DPMI_INT
value|0x31
end_define

begin_define
define|#
directive|define
name|_PCCCI
value|0x02
end_define

begin_define
define|#
directive|define
name|_PCSNI
value|0x06
end_define

begin_define
define|#
directive|define
name|_PIDXR
value|0x279
end_define

begin_define
define|#
directive|define
name|_PNPWRP
value|0xA79
end_define

begin_define
define|#
directive|define
name|_LDSALI
value|0x42
end_define

begin_define
define|#
directive|define
name|_LDSAHI
value|0x50
end_define

begin_define
define|#
directive|define
name|_LMALI
value|0x43
end_define

begin_define
define|#
directive|define
name|_LMAHI
value|0x44
end_define

begin_define
define|#
directive|define
name|_LMCFI
value|0x52
end_define

begin_define
define|#
directive|define
name|_LMCI
value|0x53
end_define

begin_define
define|#
directive|define
name|_LDIBI
value|0x58
end_define

begin_define
define|#
directive|define
name|_LDICI
value|0x57
end_define

begin_define
define|#
directive|define
name|_LMSBAI
value|0x51
end_define

begin_define
define|#
directive|define
name|_SVCI_RD
value|0x8D
end_define

begin_define
define|#
directive|define
name|_SVCI_WR
value|0x0D
end_define

begin_define
define|#
directive|define
name|_SACI_RD
value|0x80
end_define

begin_define
define|#
directive|define
name|_SACI_WR
value|0x00
end_define

begin_define
define|#
directive|define
name|_SALI_RD
value|0x8B
end_define

begin_define
define|#
directive|define
name|_SALI_WR
value|0x0B
end_define

begin_define
define|#
directive|define
name|_SAHI_RD
value|0x8A
end_define

begin_define
define|#
directive|define
name|_SAHI_WR
value|0x0A
end_define

begin_define
define|#
directive|define
name|_SASHI_RD
value|0x82
end_define

begin_define
define|#
directive|define
name|_SASHI_WR
value|0x02
end_define

begin_define
define|#
directive|define
name|_SASLI_RD
value|0x83
end_define

begin_define
define|#
directive|define
name|_SASLI_WR
value|0x03
end_define

begin_define
define|#
directive|define
name|_SAEHI_RD
value|0x84
end_define

begin_define
define|#
directive|define
name|_SAEHI_WR
value|0x04
end_define

begin_define
define|#
directive|define
name|_SAELI_RD
value|0x85
end_define

begin_define
define|#
directive|define
name|_SAELI_WR
value|0x05
end_define

begin_define
define|#
directive|define
name|_SVRI_RD
value|0x86
end_define

begin_define
define|#
directive|define
name|_SVRI_WR
value|0x06
end_define

begin_define
define|#
directive|define
name|_SVSI_RD
value|0x87
end_define

begin_define
define|#
directive|define
name|_SVSI_WR
value|0x07
end_define

begin_define
define|#
directive|define
name|_SVEI_RD
value|0x88
end_define

begin_define
define|#
directive|define
name|_SVEI_WR
value|0x08
end_define

begin_define
define|#
directive|define
name|_SVLI_RD
value|0x89
end_define

begin_define
define|#
directive|define
name|_SVLI_WR
value|0x09
end_define

begin_define
define|#
directive|define
name|_SROI_RD
value|0x8C
end_define

begin_define
define|#
directive|define
name|_SROI_WR
value|0x0C
end_define

begin_define
define|#
directive|define
name|_SLOI_RD
value|0x93
end_define

begin_define
define|#
directive|define
name|_SLOI_WR
value|0x13
end_define

begin_define
define|#
directive|define
name|_SMSI_RD
value|0x95
end_define

begin_define
define|#
directive|define
name|_SMSI_WR
value|0x15
end_define

begin_define
define|#
directive|define
name|_SGMI_RD
value|0x99
end_define

begin_define
define|#
directive|define
name|_SGMI_WR
value|0x19
end_define

begin_define
define|#
directive|define
name|_SFCI_RD
value|0x81
end_define

begin_define
define|#
directive|define
name|_SFCI_WR
value|0x01
end_define

begin_define
define|#
directive|define
name|_SUAI_RD
value|0x90
end_define

begin_define
define|#
directive|define
name|_SUAI_WR
value|0x10
end_define

begin_define
define|#
directive|define
name|_SVII
value|0x8F
end_define

begin_define
define|#
directive|define
name|_CMODEI
value|0x0C
end_define

begin_comment
comment|/* index for CMODEI */
end_comment

begin_define
define|#
directive|define
name|_CFIG3I
value|0x11
end_define

begin_define
define|#
directive|define
name|_CFIG2I
value|0x10
end_define

begin_define
define|#
directive|define
name|_CLTIMI
value|0x14
end_define

begin_define
define|#
directive|define
name|_CUTIMI
value|0x15
end_define

begin_define
define|#
directive|define
name|_CSR3I
value|0x18
end_define

begin_comment
comment|/* Index to CSR3I (Interrupt Status) */
end_comment

begin_define
define|#
directive|define
name|_CEXTI
value|0x0A
end_define

begin_comment
comment|/* Index to External Control Register */
end_comment

begin_define
define|#
directive|define
name|_CFIG1I
value|0x09
end_define

begin_comment
comment|/* Index to Codec Conf Reg 1 */
end_comment

begin_define
define|#
directive|define
name|_CSR2I
value|0x0B
end_define

begin_comment
comment|/* Index to Codec Stat Reg 2 */
end_comment

begin_define
define|#
directive|define
name|_CPDFI
value|0x08
end_define

begin_comment
comment|/* Index to Play Data Format Reg */
end_comment

begin_define
define|#
directive|define
name|_CRDFI
value|0x1C
end_define

begin_comment
comment|/* Index to Rec Data Format Reg */
end_comment

begin_define
define|#
directive|define
name|_CLMICI
value|0x16
end_define

begin_comment
comment|/* Index to Left Mic Input Ctrl Register */
end_comment

begin_define
define|#
directive|define
name|_CRMICI
value|0x17
end_define

begin_comment
comment|/* Index to Right Mic Input Ctrl Register */
end_comment

begin_define
define|#
directive|define
name|_CLCI
value|0x0D
end_define

begin_comment
comment|/* Index to Loopback Ctrl Register */
end_comment

begin_define
define|#
directive|define
name|_IVERI
value|0x5B
end_define

begin_comment
comment|/* Index to register IVERI */
end_comment

begin_define
define|#
directive|define
name|CODEC_MODE1
value|0x00
end_define

begin_define
define|#
directive|define
name|CODEC_MODE2
value|0x40
end_define

begin_define
define|#
directive|define
name|CODEC_MODE3
value|0x6C
end_define

begin_comment
comment|/* Enhanced Mode */
end_comment

begin_define
define|#
directive|define
name|CODEC_STATUS1
value|0x01
end_define

begin_define
define|#
directive|define
name|CODEC_STATUS2
value|0x0B
end_define

begin_comment
comment|/* Index to CSR2I */
end_comment

begin_define
define|#
directive|define
name|CODEC_STATUS3
value|0x18
end_define

begin_comment
comment|/* Index to CSR3I */
end_comment

begin_define
define|#
directive|define
name|PLAYBACK
value|0x01
end_define

begin_comment
comment|/* Enable playback path CFIG1I[0]=1*/
end_comment

begin_define
define|#
directive|define
name|RECORD
value|0x02
end_define

begin_comment
comment|/* Enable Record path CFIG1I[1]=1*/
end_comment

begin_define
define|#
directive|define
name|TIMER_ENABLE
value|0x40
end_define

begin_comment
comment|/* CFIG2I[6] */
end_comment

begin_define
define|#
directive|define
name|CODEC_MCE
value|0x40
end_define

begin_comment
comment|/* CIDXR[6] */
end_comment

begin_define
define|#
directive|define
name|CALIB_IN_PROGRESS
value|0x20
end_define

begin_comment
comment|/* CSR2I[5] */
end_comment

begin_define
define|#
directive|define
name|CODEC_INIT
value|0x80
end_define

begin_comment
comment|/* CIDXR[7] */
end_comment

begin_define
define|#
directive|define
name|BIT16_BIG
value|0xC0
end_define

begin_comment
comment|/* 16-bit signed, big endian */
end_comment

begin_define
define|#
directive|define
name|IMA_ADPCM
value|0xA0
end_define

begin_comment
comment|/* IMA-compliant ADPCM */
end_comment

begin_define
define|#
directive|define
name|BIT8_ALAW
value|0x60
end_define

begin_comment
comment|/* 8-bit A-law */
end_comment

begin_define
define|#
directive|define
name|BIT16_LITTLE
value|0x40
end_define

begin_comment
comment|/* 16-bit signed, lillte endian */
end_comment

begin_define
define|#
directive|define
name|BIT8_ULAW
value|0x20
end_define

begin_comment
comment|/* 8-bit u-law */
end_comment

begin_define
define|#
directive|define
name|BIT8_LINEAR
value|0x00
end_define

begin_comment
comment|/* 8-bit unsigned */
end_comment

begin_define
define|#
directive|define
name|REC_DFORMAT
value|0x1C
end_define

begin_define
define|#
directive|define
name|PLAY_DFORMAT
value|0x08
end_define

begin_define
define|#
directive|define
name|DMA_ACCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|PIO_ACCESS
value|0xC0
end_define

begin_define
define|#
directive|define
name|DMA_SIMPLEX
value|0x04
end_define

begin_define
define|#
directive|define
name|STEREO
value|0x10
end_define

begin_comment
comment|/* CxDFI[4] */
end_comment

begin_define
define|#
directive|define
name|XTAL1
value|0x00
end_define

begin_comment
comment|/* CxDFI[4]=0 selects 24.5Mhz XTAL */
end_comment

begin_define
define|#
directive|define
name|XTAL2
value|0x01
end_define

begin_comment
comment|/* CxDFI[4]=1 selects 16.9Mhz XTAL */
end_comment

begin_define
define|#
directive|define
name|AUTOCALIB
value|0x08
end_define

begin_comment
comment|/* CFIG1I[3] */
end_comment

begin_define
define|#
directive|define
name|ROM_IO
value|0x02
end_define

begin_comment
comment|/* ROM I/O cycles - LMCI[1]=1 */
end_comment

begin_define
define|#
directive|define
name|DRAM_IO
value|0x4D
end_define

begin_comment
comment|/* DRAM I/O cycles - LMCI[1]=0 */
end_comment

begin_define
define|#
directive|define
name|AUTOI
value|0x01
end_define

begin_comment
comment|/* LMCI[0]=1 */
end_comment

begin_define
define|#
directive|define
name|_PLDNI
value|0x07
end_define

begin_define
define|#
directive|define
name|ACTIVATE_DEV
value|0x30
end_define

begin_define
define|#
directive|define
name|_PWAKEI
value|0x03
end_define

begin_comment
comment|/* Index for PWAKEI */
end_comment

begin_define
define|#
directive|define
name|_PISOCI
value|0x01
end_define

begin_comment
comment|/* Index for PISOCI */
end_comment

begin_define
define|#
directive|define
name|_PSECI
value|0xF1
end_define

begin_comment
comment|/* Index for PSECI */
end_comment

begin_define
define|#
directive|define
name|RANGE_IOCHK
value|0x31
end_define

begin_comment
comment|/* PURCI or PRRCI Index */
end_comment

begin_define
define|#
directive|define
name|MIDI_RESET
value|0x03
end_define

begin_define
define|#
directive|define
name|IO_OK
value|5
end_define

begin_comment
comment|/* No IO conflict flag */
end_comment

begin_define
define|#
directive|define
name|IO_CONFLICT
value|6
end_define

begin_comment
comment|/* IO Conflict detected */
end_comment

begin_define
define|#
directive|define
name|IO_0x55
value|0x01
end_define

begin_define
define|#
directive|define
name|IO_0xAA
value|0xFE
end_define

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* Defines for Sound Handlers in "iw".*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|PLAY_DMA_HANDLER
value|0x01
end_define

begin_define
define|#
directive|define
name|REC_DMA_HANDLER
value|0x02
end_define

begin_define
define|#
directive|define
name|MIDI_TX_HANDLER
value|0x03
end_define

begin_define
define|#
directive|define
name|MIDI_RX_HANDLER
value|0x04
end_define

begin_define
define|#
directive|define
name|TIMER1_HANDLER
value|0x05
end_define

begin_define
define|#
directive|define
name|TIMER2_HANDLER
value|0x06
end_define

begin_define
define|#
directive|define
name|WAVE_HANDLER
value|0x07
end_define

begin_define
define|#
directive|define
name|VOLUME_HANDLER
value|0x08
end_define

begin_define
define|#
directive|define
name|CODEC_TIMER_HANDLER
value|0x09
end_define

begin_define
define|#
directive|define
name|CODEC_PLAY_HANDLER
value|0x0A
end_define

begin_define
define|#
directive|define
name|CODEC_REC_HANDLER
value|0x0B
end_define

begin_define
define|#
directive|define
name|AUX_HANDLER
value|0x0C
end_define

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*     Mapping for System Control Regs.*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|UMCR
value|0x00010000
end_define

begin_comment
comment|/* Mix Control Reg.*/
end_comment

begin_define
define|#
directive|define
name|UISR
value|0x00020006
end_define

begin_comment
comment|/* IRQ Stat Reg. (read) */
end_comment

begin_define
define|#
directive|define
name|U2X6R
value|0x00030006
end_define

begin_comment
comment|/* SB 2X6 reg */
end_comment

begin_define
define|#
directive|define
name|UACWR
value|0x00040008
end_define

begin_comment
comment|/* AdLib Command Write Reg */
end_comment

begin_define
define|#
directive|define
name|UASRR
value|0x00050008
end_define

begin_comment
comment|/* AdLib Stat Read Reg */
end_comment

begin_define
define|#
directive|define
name|UADR
value|0x00060009
end_define

begin_comment
comment|/* AdLib Data Register */
end_comment

begin_define
define|#
directive|define
name|UACRR
value|0x0007000A
end_define

begin_comment
comment|/* AdLib Cmd Read Reg */
end_comment

begin_define
define|#
directive|define
name|UASWR
value|0x0008000A
end_define

begin_comment
comment|/* AdLib Stat Write Reg */
end_comment

begin_define
define|#
directive|define
name|UHRDP
value|0x0009000B
end_define

begin_comment
comment|/* Hidden Reg Data Port */
end_comment

begin_define
define|#
directive|define
name|UI2XCR
value|0x000A000C
end_define

begin_comment
comment|/* SB IRQ 2xC Reg */
end_comment

begin_define
define|#
directive|define
name|U2XCR
value|0x000B000D
end_define

begin_comment
comment|/* SB 2xC Reg. (No IRQ) */
end_comment

begin_define
define|#
directive|define
name|U2XER
value|0x000C000E
end_define

begin_comment
comment|/* SB 2xE Reg. */
end_comment

begin_define
define|#
directive|define
name|URCR
value|0x000D000F
end_define

begin_comment
comment|/* Reg Control Register */
end_comment

begin_define
define|#
directive|define
name|USRR
value|0x000E000F
end_define

begin_comment
comment|/* Status Read Register */
end_comment

begin_define
define|#
directive|define
name|UDCI
value|0x000F000B
end_define

begin_comment
comment|/* DMA Channel Control Reg */
end_comment

begin_define
define|#
directive|define
name|UICI
value|0x0010000B
end_define

begin_comment
comment|/* Interrupt Ctrl Reg */
end_comment

begin_define
define|#
directive|define
name|UGP1I
value|0x0011010B
end_define

begin_comment
comment|/* GP Reg 1 (Back Door) */
end_comment

begin_define
define|#
directive|define
name|UGP2I
value|0x0012020B
end_define

begin_comment
comment|/* GP Reg 2 (Back Door) */
end_comment

begin_define
define|#
directive|define
name|UGPA1I
value|0x0013030B
end_define

begin_comment
comment|/* GP reg 1 Address */
end_comment

begin_define
define|#
directive|define
name|UGPA2I
value|0x0014040B
end_define

begin_comment
comment|/* GP reg 2 Address */
end_comment

begin_define
define|#
directive|define
name|UCLRII
value|0x0015050B
end_define

begin_comment
comment|/* Clear Interrupt Reg */
end_comment

begin_define
define|#
directive|define
name|UJMPI
value|0x0016060B
end_define

begin_comment
comment|/* Jumper Register */
end_comment

begin_define
define|#
directive|define
name|UGP1II
value|0x0017000B
end_define

begin_comment
comment|/* Gen. Purp Reg 1(Emulation) */
end_comment

begin_define
define|#
directive|define
name|UGP2II
value|0x0018000B
end_define

begin_comment
comment|/* Gen. Purp Reg 2(Emulation) */
end_comment

begin_define
define|#
directive|define
name|GGCR
value|0x00190201
end_define

begin_comment
comment|/* Game Control Register */
end_comment

begin_define
define|#
directive|define
name|GMCR
value|0x001A0000
end_define

begin_comment
comment|/* MIDI Control Register */
end_comment

begin_define
define|#
directive|define
name|GMSR
value|0x001B0000
end_define

begin_comment
comment|/* MIDI Status Reg. */
end_comment

begin_define
define|#
directive|define
name|GMTDR
value|0x001C0001
end_define

begin_comment
comment|/* MIDI xmit data reg */
end_comment

begin_define
define|#
directive|define
name|GMRDR
value|0x001D0001
end_define

begin_comment
comment|/* MIDI rcv data reg */
end_comment

begin_define
define|#
directive|define
name|SVSR
value|0x001E0002
end_define

begin_comment
comment|/* Synth Voice Select Reg */
end_comment

begin_define
define|#
directive|define
name|IGIDXR
value|0x001F0003
end_define

begin_comment
comment|/* General Index Register */
end_comment

begin_define
define|#
directive|define
name|I16DP
value|0x00200004
end_define

begin_comment
comment|/* General 16-bit Data Port */
end_comment

begin_define
define|#
directive|define
name|I8DP
value|0x00210005
end_define

begin_comment
comment|/* General 8-bit Data Port */
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*             Synth defines*/
end_comment

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#######################################################################*/
end_comment

begin_define
define|#
directive|define
name|SACI
value|0x00220005
end_define

begin_comment
comment|/* Synth Addr Control */
end_comment

begin_define
define|#
directive|define
name|SFCI
value|0x00230104
end_define

begin_comment
comment|/* Synth Freq Control */
end_comment

begin_define
define|#
directive|define
name|SASHI
value|0x00240204
end_define

begin_comment
comment|/* Synth Addr Start High */
end_comment

begin_define
define|#
directive|define
name|SASLI
value|0x00250304
end_define

begin_comment
comment|/* Synth Addr Start Low */
end_comment

begin_define
define|#
directive|define
name|SAEHI
value|0x00260404
end_define

begin_comment
comment|/* Synth Addr End High */
end_comment

begin_define
define|#
directive|define
name|SAELI
value|0x00270504
end_define

begin_comment
comment|/* Synth Addr End Low */
end_comment

begin_define
define|#
directive|define
name|SVRI
value|0x00280605
end_define

begin_comment
comment|/* Synth Volume Rate */
end_comment

begin_define
define|#
directive|define
name|SVSI
value|0x00290705
end_define

begin_comment
comment|/* Synth Volume Start */
end_comment

begin_define
define|#
directive|define
name|SVEI
value|0x002A0805
end_define

begin_comment
comment|/* Synth Volume End */
end_comment

begin_define
define|#
directive|define
name|SVLI
value|0x002B0904
end_define

begin_comment
comment|/* Synth Volume Level */
end_comment

begin_define
define|#
directive|define
name|SAHI
value|0x002C0A04
end_define

begin_comment
comment|/* Synth Address High */
end_comment

begin_define
define|#
directive|define
name|SALI
value|0x002D0B04
end_define

begin_comment
comment|/* Synth Address Low */
end_comment

begin_define
define|#
directive|define
name|SROI
value|0x002E0C04
end_define

begin_comment
comment|/* Synth Right Offset */
end_comment

begin_define
define|#
directive|define
name|SVCI
value|0x002F0D05
end_define

begin_comment
comment|/* Synth Volume Control */
end_comment

begin_define
define|#
directive|define
name|SAVI
value|0x00300E05
end_define

begin_comment
comment|/* Synth Active Voices */
end_comment

begin_define
define|#
directive|define
name|SVII
value|0x00318F05
end_define

begin_comment
comment|/* Synth Voice IRQ */
end_comment

begin_define
define|#
directive|define
name|SUAI
value|0x00321005
end_define

begin_comment
comment|/* Synth Upper Addr */
end_comment

begin_define
define|#
directive|define
name|SEAHI
value|0x00331104
end_define

begin_comment
comment|/* Synth Effect Addr High */
end_comment

begin_define
define|#
directive|define
name|SEALI
value|0x00341204
end_define

begin_comment
comment|/* Synth Effect Addr Low */
end_comment

begin_define
define|#
directive|define
name|SLOI
value|0x00351304
end_define

begin_comment
comment|/* Synth Left Offset */
end_comment

begin_define
define|#
directive|define
name|SEASI
value|0x00361405
end_define

begin_comment
comment|/* Synth Effects Accum Sel */
end_comment

begin_define
define|#
directive|define
name|SMSI
value|0x00371505
end_define

begin_comment
comment|/* Synth Mode Select */
end_comment

begin_define
define|#
directive|define
name|SEVI
value|0x00381604
end_define

begin_comment
comment|/* Synth Effect Volume */
end_comment

begin_define
define|#
directive|define
name|SFLFOI
value|0x00391705
end_define

begin_comment
comment|/* Synth Freq LFO */
end_comment

begin_define
define|#
directive|define
name|SVLFOI
value|0x003A1805
end_define

begin_comment
comment|/* Synth Vol LFO */
end_comment

begin_define
define|#
directive|define
name|SGMI
value|0x003B1905
end_define

begin_comment
comment|/* Synth Global Mode */
end_comment

begin_define
define|#
directive|define
name|SLFOBI
value|0x003C1A04
end_define

begin_comment
comment|/* Synth LFO Base Address */
end_comment

begin_define
define|#
directive|define
name|SROFI
value|0x003D1B04
end_define

begin_define
define|#
directive|define
name|SLOFI
value|0x003E1C04
end_define

begin_define
define|#
directive|define
name|SEVFI
value|0x003F1D04
end_define

begin_define
define|#
directive|define
name|SVIRI
value|0x00409F05
end_define

begin_comment
comment|/* Synth Voice Read IRQ */
end_comment

begin_define
define|#
directive|define
name|LDMACI
value|0x00414105
end_define

begin_comment
comment|/* DMA Control Reg. */
end_comment

begin_define
define|#
directive|define
name|LDSALI
value|0x00424204
end_define

begin_comment
comment|/* LMC DMA Start Addr. Low Reg. */
end_comment

begin_define
define|#
directive|define
name|LMALI
value|0x00434304
end_define

begin_comment
comment|/* LMC Addr Low (I/O) */
end_comment

begin_define
define|#
directive|define
name|LMAHI
value|0x00444405
end_define

begin_comment
comment|/* LMC Addr High (I/O) */
end_comment

begin_define
define|#
directive|define
name|UASBCI
value|0x00454505
end_define

begin_comment
comment|/* Adlib-SB Control */
end_comment

begin_define
define|#
directive|define
name|UAT1I
value|0x00464605
end_define

begin_comment
comment|/* AdLib Timer 1 Count */
end_comment

begin_define
define|#
directive|define
name|UAT2I
value|0x00474705
end_define

begin_comment
comment|/* AdLib Timer 2 Count */
end_comment

begin_define
define|#
directive|define
name|USCI
value|0x00484905
end_define

begin_comment
comment|/* Sample Control Reg */
end_comment

begin_define
define|#
directive|define
name|GJTDI
value|0x00494B05
end_define

begin_define
define|#
directive|define
name|URSTI
value|0x004A4C05
end_define

begin_define
define|#
directive|define
name|LDSAHI
value|0x004B5005
end_define

begin_define
define|#
directive|define
name|LMSBAI
value|0x004C5104
end_define

begin_define
define|#
directive|define
name|LMCFI
value|0x004D5204
end_define

begin_define
define|#
directive|define
name|LMCI
value|0x004E5305
end_define

begin_define
define|#
directive|define
name|LMRFAI
value|0x004F5404
end_define

begin_define
define|#
directive|define
name|LMPFAI
value|0x00505504
end_define

begin_define
define|#
directive|define
name|LMSFI
value|0x00515604
end_define

begin_define
define|#
directive|define
name|LDICI
value|0x00525704
end_define

begin_define
define|#
directive|define
name|LDIBI
value|0x00535804
end_define

begin_define
define|#
directive|define
name|ICMPTI
value|0x00545905
end_define

begin_define
define|#
directive|define
name|IDECI
value|0x00555A05
end_define

begin_define
define|#
directive|define
name|IVERI
value|0x00565B05
end_define

begin_define
define|#
directive|define
name|IEMUAI
value|0x00575C05
end_define

begin_define
define|#
directive|define
name|IEMUBI
value|0x00585D05
end_define

begin_define
define|#
directive|define
name|GMRFAI
value|0x00595E05
end_define

begin_define
define|#
directive|define
name|ITCI
value|0x005A5F05
end_define

begin_define
define|#
directive|define
name|IEIRQI
value|0x005B6005
end_define

begin_define
define|#
directive|define
name|LMBDR
value|0x005C0007
end_define

begin_comment
comment|/*##########################################################*/
end_comment

begin_comment
comment|/* Mnemonics for Codec Registers*/
end_comment

begin_comment
comment|/*##########################################################*/
end_comment

begin_define
define|#
directive|define
name|CIDXR
value|0x005D0000
end_define

begin_define
define|#
directive|define
name|CDATAP
value|0x005E0001
end_define

begin_define
define|#
directive|define
name|CSR1R
value|0x005F0002
end_define

begin_define
define|#
directive|define
name|CPDR
value|0x00600003
end_define

begin_define
define|#
directive|define
name|CRDR
value|0x00610003
end_define

begin_define
define|#
directive|define
name|CLICI
value|0x00620001
end_define

begin_define
define|#
directive|define
name|CRICI
value|0x00630101
end_define

begin_define
define|#
directive|define
name|CLAX1I
value|0x00640201
end_define

begin_define
define|#
directive|define
name|CRAX1I
value|0x00650301
end_define

begin_define
define|#
directive|define
name|CLAX2I
value|0x00660401
end_define

begin_define
define|#
directive|define
name|CRAX2I
value|0x00670501
end_define

begin_define
define|#
directive|define
name|CLDACI
value|0x00680601
end_define

begin_define
define|#
directive|define
name|CRDACI
value|0x00690701
end_define

begin_define
define|#
directive|define
name|CPDFI
value|0x006A0801
end_define

begin_define
define|#
directive|define
name|CFIG1I
value|0x006B0901
end_define

begin_define
define|#
directive|define
name|CEXTI
value|0x006C0A01
end_define

begin_define
define|#
directive|define
name|CSR2I
value|0x006D0B01
end_define

begin_define
define|#
directive|define
name|CMODEI
value|0x006E0C01
end_define

begin_define
define|#
directive|define
name|CLCI
value|0x006F0D01
end_define

begin_define
define|#
directive|define
name|CUPCTI
value|0x00700E01
end_define

begin_define
define|#
directive|define
name|CLPCTI
value|0x00710F01
end_define

begin_define
define|#
directive|define
name|CFIG2I
value|0x00721001
end_define

begin_define
define|#
directive|define
name|CFIG3I
value|0x00731101
end_define

begin_define
define|#
directive|define
name|CLLICI
value|0x00741201
end_define

begin_define
define|#
directive|define
name|CRLICI
value|0x00751301
end_define

begin_define
define|#
directive|define
name|CLTIMI
value|0x00761401
end_define

begin_define
define|#
directive|define
name|CUTIMI
value|0x00771501
end_define

begin_define
define|#
directive|define
name|CLMICI
value|0x00781601
end_define

begin_define
define|#
directive|define
name|CRMICI
value|0x00791701
end_define

begin_define
define|#
directive|define
name|CSR3I
value|0x007A1801
end_define

begin_define
define|#
directive|define
name|CLOAI
value|0x007B1901
end_define

begin_define
define|#
directive|define
name|CMONOI
value|0x007C1A01
end_define

begin_define
define|#
directive|define
name|CROAI
value|0x007D1B01
end_define

begin_define
define|#
directive|define
name|CRDFI
value|0x007E1C01
end_define

begin_define
define|#
directive|define
name|CPVFI
value|0x007F1D01
end_define

begin_define
define|#
directive|define
name|CURCTI
value|0x00801E01
end_define

begin_define
define|#
directive|define
name|CLRCTI
value|0x00811F01
end_define

begin_comment
comment|/*##########################################################*/
end_comment

begin_comment
comment|/* Mnemonics for PnP Registers*/
end_comment

begin_comment
comment|/*##########################################################*/
end_comment

begin_define
define|#
directive|define
name|PCSNBR
value|0x00820201
end_define

begin_define
define|#
directive|define
name|PIDXR
value|0x00830279
end_define

begin_define
define|#
directive|define
name|PNPWRP
value|0x00840A79
end_define

begin_define
define|#
directive|define
name|PNPRDP
value|0x00850000
end_define

begin_define
define|#
directive|define
name|PSRPAI
value|0x00860000
end_define

begin_define
define|#
directive|define
name|PISOCI
value|0x00870100
end_define

begin_define
define|#
directive|define
name|PCCCI
value|0x00880200
end_define

begin_define
define|#
directive|define
name|PWAKEI
value|0x00890300
end_define

begin_define
define|#
directive|define
name|PRESDI
value|0x008A0400
end_define

begin_define
define|#
directive|define
name|PRESSI
value|0x008B0500
end_define

begin_define
define|#
directive|define
name|PCSNI
value|0x008C0600
end_define

begin_define
define|#
directive|define
name|PLDNI
value|0x008D0700
end_define

begin_define
define|#
directive|define
name|PUACTI
value|0x008E3000
end_define

begin_define
define|#
directive|define
name|PURCI
value|0x008F3100
end_define

begin_define
define|#
directive|define
name|P2X0HI
value|0x00906000
end_define

begin_define
define|#
directive|define
name|P2X0LI
value|0x00916100
end_define

begin_define
define|#
directive|define
name|P3X0HI
value|0x00926200
end_define

begin_define
define|#
directive|define
name|P3X0LI
value|0x00936300
end_define

begin_define
define|#
directive|define
name|PHCAI
value|0x00946400
end_define

begin_define
define|#
directive|define
name|PLCAI
value|0x00956500
end_define

begin_define
define|#
directive|define
name|PUI1SI
value|0x00967000
end_define

begin_define
define|#
directive|define
name|PUI1TI
value|0x00977100
end_define

begin_define
define|#
directive|define
name|PUI2SI
value|0x00987200
end_define

begin_define
define|#
directive|define
name|PUI2TI
value|0x00997300
end_define

begin_define
define|#
directive|define
name|PUD1SI
value|0x009A7400
end_define

begin_define
define|#
directive|define
name|PUD2SI
value|0x009B7500
end_define

begin_define
define|#
directive|define
name|PSEENI
value|0x009CF000
end_define

begin_define
define|#
directive|define
name|PSECI
value|0x009DF100
end_define

begin_define
define|#
directive|define
name|PPWRI
value|0x009EF200
end_define

begin_define
define|#
directive|define
name|PRACTI
value|0x009F3001
end_define

begin_define
define|#
directive|define
name|PRRCI
value|0x00A03101
end_define

begin_define
define|#
directive|define
name|PRAHI
value|0x00A16001
end_define

begin_define
define|#
directive|define
name|PRALI
value|0x00A26101
end_define

begin_define
define|#
directive|define
name|PATAHI
value|0x00A36201
end_define

begin_define
define|#
directive|define
name|PATALI
value|0x00A46301
end_define

begin_define
define|#
directive|define
name|PRISI
value|0x00A57001
end_define

begin_define
define|#
directive|define
name|PRITI
value|0x00A67101
end_define

begin_define
define|#
directive|define
name|PRDSI
value|0x00A77401
end_define

begin_define
define|#
directive|define
name|PGACTI
value|0x00A83002
end_define

begin_define
define|#
directive|define
name|PGRCI
value|0x00A93102
end_define

begin_define
define|#
directive|define
name|P201HI
value|0x00AA6002
end_define

begin_define
define|#
directive|define
name|P201LI
value|0x00AB6102
end_define

begin_define
define|#
directive|define
name|PSACTI
value|0x00AC3003
end_define

begin_define
define|#
directive|define
name|PSRCI
value|0x00AD3103
end_define

begin_define
define|#
directive|define
name|P388HI
value|0x00AE6003
end_define

begin_define
define|#
directive|define
name|P388LI
value|0x00AF6103
end_define

begin_define
define|#
directive|define
name|PSBISI
value|0x00B07003
end_define

begin_define
define|#
directive|define
name|PSBITI
value|0x00B17103
end_define

begin_define
define|#
directive|define
name|PMACTI
value|0x00B23004
end_define

begin_define
define|#
directive|define
name|PMRCI
value|0x00B33104
end_define

begin_define
define|#
directive|define
name|P401HI
value|0x00B46004
end_define

begin_define
define|#
directive|define
name|P401LI
value|0x00B56104
end_define

begin_define
define|#
directive|define
name|PMISI
value|0x00B67004
end_define

begin_define
define|#
directive|define
name|PMITI
value|0x00B77104
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BYTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|WORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|PORT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|DWORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|BOOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|FLAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|flags
decl_stmt|;
comment|/* InterWave stat flags */
name|PORT
name|pcodar
decl_stmt|;
comment|/* Base Port for Codec */
name|PORT
name|pcdrar
decl_stmt|;
comment|/* Base Port for Ext Device */
name|PORT
name|p2xr
decl_stmt|;
comment|/* Compatibility Base Port */
name|PORT
name|p3xr
decl_stmt|;
comment|/* MIDI and Synth Base Port */
name|PORT
name|p401ar
decl_stmt|;
comment|/* Gen Purpose Reg. 1 address */
name|PORT
name|p201ar
decl_stmt|;
comment|/* Game Ctrl normally at 0x201 */
name|PORT
name|pataar
decl_stmt|;
comment|/* Base Address for ATAPI I/O Space */
name|PORT
name|p388ar
decl_stmt|;
comment|/* Base Port for AdLib. It should be 388h */
name|PORT
name|pnprdp
decl_stmt|;
comment|/* PNP read data port */
name|PORT
name|igidxr
decl_stmt|;
comment|/* Gen Index Reg at P3XR+0x03 */
name|PORT
name|i16dp
decl_stmt|;
comment|/* 16-bit data port at P3XR+0x04  */
name|PORT
name|i8dp
decl_stmt|;
comment|/* 8-bit data port at P3XR+0x05 */
name|PORT
name|svsr
decl_stmt|;
comment|/* Synth Voice Select at P3XR+0x02 */
name|PORT
name|cdatap
decl_stmt|;
comment|/* Codec Indexed Data Port at PCODAR+0x01 */
name|PORT
name|csr1r
decl_stmt|;
comment|/* Codec Stat Reg 1 at PCODAR+0x02 */
name|PORT
name|cxdr
decl_stmt|;
comment|/* Play or Record Data Reg at PCODAR+0x03 */
name|PORT
name|gmxr
decl_stmt|;
comment|/* GMCR or GMSR at P3XR+0x00 */
name|PORT
name|gmxdr
decl_stmt|;
comment|/* GMTDR or GMRDR at P3XR+0x01 */
name|PORT
name|lmbdr
decl_stmt|;
comment|/* LMBDR at P3XR+0x07 */
name|BYTE
name|csn
decl_stmt|;
comment|/* Card Select Number */
name|BYTE
name|cmode
decl_stmt|;
comment|/* Codec Operation Mode */
name|int
name|dma1_chan
decl_stmt|;
comment|/* DMA channel 1 (local DMA& codec rec) */
name|int
name|dma2_chan
decl_stmt|;
comment|/* DMA channel 2 (codec play) */
name|int
name|ext_chan
decl_stmt|;
comment|/* Ext Dev DMA channel */
name|BYTE
name|voices
decl_stmt|;
comment|/* Number of active voices */
name|DWORD
name|vendor
decl_stmt|;
comment|/* Vendor ID and Product Identifier */
name|int
name|synth_irq
decl_stmt|;
comment|/* Synth IRQ number */
name|int
name|midi_irq
decl_stmt|;
comment|/* MIDI IRQ number */
name|int
name|ext_irq
decl_stmt|;
comment|/* Ext Dev IRQ  */
name|int
name|mpu_irq
decl_stmt|;
comment|/* MPU401 Dev IRQ */
name|int
name|emul_irq
decl_stmt|;
comment|/* Sound Blaster/AdLib Dev IRQ */
name|ADDRESS
name|free_mem
decl_stmt|;
comment|/* Address of First Free LM Block */
name|DWORD
name|reserved_mem
decl_stmt|;
comment|/* Amount of LM reserved by app. */
name|BYTE
name|smode
decl_stmt|;
comment|/* Synth Mode */
name|WORD
name|size_mem
decl_stmt|;
comment|/* Total LM in Kbytes */
block|}
name|IWAVE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

