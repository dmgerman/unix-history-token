begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This supports the ENSONIQ AudioPCI board based on the ES1370.  *  * Copyright (c) 1998 Joachim Kuebart<joki@kuebart.stuttgart.netsurf.de>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Joachim Kuebart.  * 4. Modifications may be freely made to this file if the above conditions  *    are met.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ES1370_REG_H
end_ifndef

begin_define
define|#
directive|define
name|_ES1370_REG_H
end_define

begin_define
define|#
directive|define
name|ES1370_REG_CONTROL
value|0x00
end_define

begin_define
define|#
directive|define
name|ES1370_REG_STATUS
value|0x04
end_define

begin_define
define|#
directive|define
name|ES1370_REG_UART_DATA
value|0x08
end_define

begin_define
define|#
directive|define
name|ES1370_REG_UART_STATUS
value|0x09
end_define

begin_define
define|#
directive|define
name|ES1370_REG_UART_CONTROL
value|0x09
end_define

begin_define
define|#
directive|define
name|ES1370_REG_UART_TEST
value|0x0a
end_define

begin_define
define|#
directive|define
name|ES1370_REG_MEMPAGE
value|0x0c
end_define

begin_define
define|#
directive|define
name|ES1370_REG_CODEC
value|0x10
end_define

begin_define
define|#
directive|define
name|CODEC_INDEX_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ES1370_REG_SERIAL_CONTROL
value|0x20
end_define

begin_define
define|#
directive|define
name|ES1370_REG_DAC1_SCOUNT
value|0x24
end_define

begin_define
define|#
directive|define
name|ES1370_REG_DAC2_SCOUNT
value|0x28
end_define

begin_define
define|#
directive|define
name|ES1370_REG_ADC_SCOUNT
value|0x2c
end_define

begin_define
define|#
directive|define
name|ES1370_REG_DAC1_FRAMEADR
value|0xc30
end_define

begin_define
define|#
directive|define
name|ES1370_REG_DAC1_FRAMECNT
value|0xc34
end_define

begin_define
define|#
directive|define
name|ES1370_REG_DAC2_FRAMEADR
value|0xc38
end_define

begin_define
define|#
directive|define
name|ES1370_REG_DAC2_FRAMECNT
value|0xc3c
end_define

begin_define
define|#
directive|define
name|ES1370_REG_ADC_FRAMEADR
value|0xd30
end_define

begin_define
define|#
directive|define
name|ES1370_REG_ADC_FRAMECNT
value|0xd34
end_define

begin_define
define|#
directive|define
name|DAC2_SRTODIV
parameter_list|(
name|x
parameter_list|)
value|(((1411200 + (x) / 2) / (x) - 2)& 0x1fff)
end_define

begin_define
define|#
directive|define
name|DAC2_DIVTOSR
parameter_list|(
name|x
parameter_list|)
value|(1411200 / ((x) + 2))
end_define

begin_define
define|#
directive|define
name|CTRL_ADC_STOP
value|0x80000000
end_define

begin_comment
comment|/* 1 = ADC stopped */
end_comment

begin_define
define|#
directive|define
name|CTRL_XCTL1
value|0x40000000
end_define

begin_comment
comment|/* SERR pin if enabled */
end_comment

begin_define
define|#
directive|define
name|CTRL_OPEN
value|0x20000000
end_define

begin_comment
comment|/* no function, can be read and 					 * written */
end_comment

begin_define
define|#
directive|define
name|CTRL_PCLKDIV
value|0x1fff0000
end_define

begin_comment
comment|/* ADC/DAC2 clock divider */
end_comment

begin_define
define|#
directive|define
name|CTRL_SH_PCLKDIV
value|16
end_define

begin_define
define|#
directive|define
name|CTRL_MSFMTSEL
value|0x00008000
end_define

begin_comment
comment|/* MPEG serial data fmt: 0 = Sony, 1 					 * = I2S */
end_comment

begin_define
define|#
directive|define
name|CTRL_M_SBB
value|0x00004000
end_define

begin_comment
comment|/* DAC2 clock: 0 = PCLKDIV, 1 = MPEG */
end_comment

begin_define
define|#
directive|define
name|CTRL_WTSRSEL
value|0x00003000
end_define

begin_comment
comment|/* DAC1 clock freq: 0=5512, 1=11025, 					 * 2=22050, 3=44100 */
end_comment

begin_define
define|#
directive|define
name|CTRL_SH_WTSRSEL
value|12
end_define

begin_define
define|#
directive|define
name|CTRL_DAC_SYNC
value|0x00000800
end_define

begin_comment
comment|/* 1 = DAC2 runs off DAC1 clock */
end_comment

begin_define
define|#
directive|define
name|CTRL_CCB_INTRM
value|0x00000400
end_define

begin_comment
comment|/* 1 = CCB "voice" ints enabled */
end_comment

begin_define
define|#
directive|define
name|CTRL_M_CB
value|0x00000200
end_define

begin_comment
comment|/* recording source: 0 = ADC, 1 = 					 * MPEG */
end_comment

begin_define
define|#
directive|define
name|CTRL_XCTL0
value|0x00000100
end_define

begin_comment
comment|/* 0 = Line in, 1 = Line out */
end_comment

begin_define
define|#
directive|define
name|CTRL_BREQ
value|0x00000080
end_define

begin_comment
comment|/* 1 = test mode (internal mem test) */
end_comment

begin_define
define|#
directive|define
name|CTRL_DAC1_EN
value|0x00000040
end_define

begin_comment
comment|/* enable DAC1 */
end_comment

begin_define
define|#
directive|define
name|CTRL_DAC2_EN
value|0x00000020
end_define

begin_comment
comment|/* enable DAC2 */
end_comment

begin_define
define|#
directive|define
name|CTRL_ADC_EN
value|0x00000010
end_define

begin_comment
comment|/* enable ADC */
end_comment

begin_define
define|#
directive|define
name|CTRL_UART_EN
value|0x00000008
end_define

begin_comment
comment|/* enable MIDI uart */
end_comment

begin_define
define|#
directive|define
name|CTRL_JYSTK_EN
value|0x00000004
end_define

begin_comment
comment|/* enable Joystick port (presumably 					 * at address 0x200) */
end_comment

begin_define
define|#
directive|define
name|CTRL_CDC_EN
value|0x00000002
end_define

begin_comment
comment|/* enable serial (CODEC) interface */
end_comment

begin_define
define|#
directive|define
name|CTRL_SERR_DIS
value|0x00000001
end_define

begin_comment
comment|/* 1 = disable PCI SERR signal */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P2ENDINC
value|0x00380000
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SCTRL_SH_P2ENDINC
value|19
end_define

begin_define
define|#
directive|define
name|SCTRL_P2STINC
value|0x00070000
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SCTRL_SH_P2STINC
value|16
end_define

begin_define
define|#
directive|define
name|SCTRL_R1LOOPSEL
value|0x00008000
end_define

begin_comment
comment|/* 0 = loop mode */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P2LOOPSEL
value|0x00004000
end_define

begin_comment
comment|/* 0 = loop mode */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P1LOOPSEL
value|0x00002000
end_define

begin_comment
comment|/* 0 = loop mode */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P2PAUSE
value|0x00001000
end_define

begin_comment
comment|/* 1 = pause mode */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P1PAUSE
value|0x00000800
end_define

begin_comment
comment|/* 1 = pause mode */
end_comment

begin_define
define|#
directive|define
name|SCTRL_R1INTEN
value|0x00000400
end_define

begin_comment
comment|/* enable interrupt */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P2INTEN
value|0x00000200
end_define

begin_comment
comment|/* enable interrupt */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P1INTEN
value|0x00000100
end_define

begin_comment
comment|/* enable interrupt */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P1SCTRLD
value|0x00000080
end_define

begin_comment
comment|/* reload sample count register for 					 * DAC1 */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P2DACSEN
value|0x00000040
end_define

begin_comment
comment|/* 1 = DAC2 play back last sample 					 * when disabled */
end_comment

begin_define
define|#
directive|define
name|SCTRL_R1SEB
value|0x00000020
end_define

begin_comment
comment|/* 1 = 16bit */
end_comment

begin_define
define|#
directive|define
name|SCTRL_R1SMB
value|0x00000010
end_define

begin_comment
comment|/* 1 = stereo */
end_comment

begin_define
define|#
directive|define
name|SCTRL_R1FMT
value|0x00000030
end_define

begin_comment
comment|/* format mask */
end_comment

begin_define
define|#
directive|define
name|SCTRL_SH_R1FMT
value|4
end_define

begin_define
define|#
directive|define
name|SCTRL_P2SEB
value|0x00000008
end_define

begin_comment
comment|/* 1 = 16bit */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P2SMB
value|0x00000004
end_define

begin_comment
comment|/* 1 = stereo */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P2FMT
value|0x0000000c
end_define

begin_comment
comment|/* format mask */
end_comment

begin_define
define|#
directive|define
name|SCTRL_SH_P2FMT
value|2
end_define

begin_define
define|#
directive|define
name|SCTRL_P1SEB
value|0x00000002
end_define

begin_comment
comment|/* 1 = 16bit */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P1SMB
value|0x00000001
end_define

begin_comment
comment|/* 1 = stereo */
end_comment

begin_define
define|#
directive|define
name|SCTRL_P1FMT
value|0x00000003
end_define

begin_comment
comment|/* format mask */
end_comment

begin_define
define|#
directive|define
name|SCTRL_SH_P1FMT
value|0
end_define

begin_define
define|#
directive|define
name|STAT_INTR
value|0x80000000
end_define

begin_comment
comment|/* wired or of all interrupt bits */
end_comment

begin_define
define|#
directive|define
name|STAT_CSTAT
value|0x00000400
end_define

begin_comment
comment|/* 1 = codec busy or codec write in 					 * progress */
end_comment

begin_define
define|#
directive|define
name|STAT_CBUSY
value|0x00000200
end_define

begin_comment
comment|/* 1 = codec busy */
end_comment

begin_define
define|#
directive|define
name|STAT_CWRIP
value|0x00000100
end_define

begin_comment
comment|/* 1 = codec write in progress */
end_comment

begin_define
define|#
directive|define
name|STAT_VC
value|0x00000060
end_define

begin_comment
comment|/* CCB int source, 0=DAC1, 1=DAC2, 					 * 2=ADC, 3=undef */
end_comment

begin_define
define|#
directive|define
name|STAT_SH_VC
value|5
end_define

begin_define
define|#
directive|define
name|STAT_MCCB
value|0x00000010
end_define

begin_comment
comment|/* CCB int pending */
end_comment

begin_define
define|#
directive|define
name|STAT_UART
value|0x00000008
end_define

begin_comment
comment|/* UART int pending */
end_comment

begin_define
define|#
directive|define
name|STAT_DAC1
value|0x00000004
end_define

begin_comment
comment|/* DAC1 int pending */
end_comment

begin_define
define|#
directive|define
name|STAT_DAC2
value|0x00000002
end_define

begin_comment
comment|/* DAC2 int pending */
end_comment

begin_define
define|#
directive|define
name|STAT_ADC
value|0x00000001
end_define

begin_comment
comment|/* ADC int pending */
end_comment

begin_define
define|#
directive|define
name|CODEC_OMIX1
value|0x10
end_define

begin_define
define|#
directive|define
name|CODEC_OMIX2
value|0x11
end_define

begin_define
define|#
directive|define
name|CODEC_LIMIX1
value|0x12
end_define

begin_define
define|#
directive|define
name|CODEC_RIMIX1
value|0x13
end_define

begin_define
define|#
directive|define
name|CODEC_LIMIX2
value|0x14
end_define

begin_define
define|#
directive|define
name|CODEC_RIMIX2
value|0x15
end_define

begin_define
define|#
directive|define
name|CODEC_RES_PD
value|0x16
end_define

begin_define
define|#
directive|define
name|CODEC_CSEL
value|0x17
end_define

begin_define
define|#
directive|define
name|CODEC_ADSEL
value|0x18
end_define

begin_define
define|#
directive|define
name|CODEC_MGAIN
value|0x19
end_define

begin_comment
comment|/* ES1371 specific */
end_comment

begin_define
define|#
directive|define
name|CODEC_ID_SESHIFT
value|10
end_define

begin_define
define|#
directive|define
name|CODEC_ID_SEMASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|CODEC_PIRD
value|0x00800000
end_define

begin_comment
comment|/* 0 = write AC97 register */
end_comment

begin_define
define|#
directive|define
name|CODEC_PIADD_MASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|CODEC_PIADD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CODEC_PIDAT_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|CODEC_PIDAT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CODEC_PORD
value|0x00800000
end_define

begin_comment
comment|/* 0 = write AC97 register */
end_comment

begin_define
define|#
directive|define
name|CODEC_POADD_MASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|CODEC_POADD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CODEC_PODAT_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|CODEC_PODAT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CODEC_RDY
value|0x80000000
end_define

begin_comment
comment|/* AC97 read data valid */
end_comment

begin_define
define|#
directive|define
name|CODEC_WIP
value|0x40000000
end_define

begin_comment
comment|/* AC97 write in progress */
end_comment

begin_define
define|#
directive|define
name|ES1370_REG_CONTROL
value|0x00
end_define

begin_define
define|#
directive|define
name|ES1370_REG_SERIAL_CONTROL
value|0x20
end_define

begin_define
define|#
directive|define
name|ES1371_REG_CODEC
value|0x14
end_define

begin_define
define|#
directive|define
name|ES1371_REG_LEGACY
value|0x18
end_define

begin_comment
comment|/* W/R: Legacy control/status register */
end_comment

begin_define
define|#
directive|define
name|ES1371_REG_SMPRATE
value|0x10
end_define

begin_comment
comment|/* W/R: Codec rate converter interface register */
end_comment

begin_define
define|#
directive|define
name|ES1371_SYNC_RES
value|(1<<14)
end_define

begin_comment
comment|/* Warm AC97 reset */
end_comment

begin_define
define|#
directive|define
name|ES1371_DIS_R1
value|(1<<19)
end_define

begin_comment
comment|/* record channel accumulator update disable */
end_comment

begin_define
define|#
directive|define
name|ES1371_DIS_P2
value|(1<<20)
end_define

begin_comment
comment|/* playback channel 2 accumulator update disable */
end_comment

begin_define
define|#
directive|define
name|ES1371_DIS_P1
value|(1<<21)
end_define

begin_comment
comment|/* playback channel 1 accumulator update disable */
end_comment

begin_define
define|#
directive|define
name|ES1371_DIS_SRC
value|(1<<22)
end_define

begin_comment
comment|/* sample rate converter disable */
end_comment

begin_define
define|#
directive|define
name|ES1371_SRC_RAM_BUSY
value|(1<<23)
end_define

begin_comment
comment|/* R/O: sample rate memory is busy */
end_comment

begin_define
define|#
directive|define
name|ES1371_SRC_RAM_WE
value|(1<<24)
end_define

begin_comment
comment|/* R/W: read/write control for sample rate converter */
end_comment

begin_define
define|#
directive|define
name|ES1371_SRC_RAM_ADDRO
parameter_list|(
name|o
parameter_list|)
value|(((o)&0x7f)<<25)
end_define

begin_comment
comment|/* address of the sample rate converter */
end_comment

begin_define
define|#
directive|define
name|ES1371_SRC_RAM_DATAO
parameter_list|(
name|o
parameter_list|)
value|(((o)&0xffff)<<0)
end_define

begin_comment
comment|/* current value of the sample rate converter */
end_comment

begin_define
define|#
directive|define
name|ES1371_SRC_RAM_DATAI
parameter_list|(
name|i
parameter_list|)
value|(((i)>>0)&0xffff)
end_define

begin_comment
comment|/* current value of the sample rate converter */
end_comment

begin_comment
comment|/*  *  Sample rate converter addresses  */
end_comment

begin_define
define|#
directive|define
name|ES_SMPREG_DAC1
value|0x70
end_define

begin_define
define|#
directive|define
name|ES_SMPREG_DAC2
value|0x74
end_define

begin_define
define|#
directive|define
name|ES_SMPREG_ADC
value|0x78
end_define

begin_define
define|#
directive|define
name|ES_SMPREG_TRUNC_N
value|0x00
end_define

begin_define
define|#
directive|define
name|ES_SMPREG_INT_REGS
value|0x01
end_define

begin_define
define|#
directive|define
name|ES_SMPREG_VFREQ_FRAC
value|0x03
end_define

begin_define
define|#
directive|define
name|ES_SMPREG_VOL_ADC
value|0x6c
end_define

begin_define
define|#
directive|define
name|ES_SMPREG_VOL_DAC1
value|0x7c
end_define

begin_define
define|#
directive|define
name|ES_SMPREG_VOL_DAC2
value|0x7e
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

