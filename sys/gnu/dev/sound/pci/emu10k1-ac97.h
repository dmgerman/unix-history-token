begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AC97_CODEC_H_
end_ifndef

begin_define
define|#
directive|define
name|_AC97_CODEC_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/soundcard.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AC97 1.0 */
end_comment

begin_define
define|#
directive|define
name|AC97_RESET
value|0x0000
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AC97_MASTER_VOL_STEREO
value|0x0002
end_define

begin_comment
comment|// Line Out
end_comment

begin_define
define|#
directive|define
name|AC97_HEADPHONE_VOL
value|0x0004
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AC97_MASTER_VOL_MONO
value|0x0006
end_define

begin_comment
comment|// TAD Output
end_comment

begin_define
define|#
directive|define
name|AC97_MASTER_TONE
value|0x0008
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AC97_PCBEEP_VOL
value|0x000a
end_define

begin_comment
comment|// none
end_comment

begin_define
define|#
directive|define
name|AC97_PHONE_VOL
value|0x000c
end_define

begin_comment
comment|// TAD Input (mono)
end_comment

begin_define
define|#
directive|define
name|AC97_MIC_VOL
value|0x000e
end_define

begin_comment
comment|// MIC Input (mono)
end_comment

begin_define
define|#
directive|define
name|AC97_LINEIN_VOL
value|0x0010
end_define

begin_comment
comment|// Line Input (stereo)
end_comment

begin_define
define|#
directive|define
name|AC97_CD_VOL
value|0x0012
end_define

begin_comment
comment|// CD Input (stereo)
end_comment

begin_define
define|#
directive|define
name|AC97_VIDEO_VOL
value|0x0014
end_define

begin_comment
comment|// none
end_comment

begin_define
define|#
directive|define
name|AC97_AUX_VOL
value|0x0016
end_define

begin_comment
comment|// Aux Input (stereo)
end_comment

begin_define
define|#
directive|define
name|AC97_PCMOUT_VOL
value|0x0018
end_define

begin_comment
comment|// Wave Output (stereo)
end_comment

begin_define
define|#
directive|define
name|AC97_RECORD_SELECT
value|0x001a
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AC97_RECORD_GAIN
value|0x001c
end_define

begin_define
define|#
directive|define
name|AC97_RECORD_GAIN_MIC
value|0x001e
end_define

begin_define
define|#
directive|define
name|AC97_GENERAL_PURPOSE
value|0x0020
end_define

begin_define
define|#
directive|define
name|AC97_3D_CONTROL
value|0x0022
end_define

begin_define
define|#
directive|define
name|AC97_MODEM_RATE
value|0x0024
end_define

begin_define
define|#
directive|define
name|AC97_POWER_CONTROL
value|0x0026
end_define

begin_comment
comment|/* AC'97 2.0 */
end_comment

begin_define
define|#
directive|define
name|AC97_EXTENDED_ID
value|0x0028
end_define

begin_comment
comment|/* Extended Audio ID */
end_comment

begin_define
define|#
directive|define
name|AC97_EXTENDED_STATUS
value|0x002A
end_define

begin_comment
comment|/* Extended Audio Status */
end_comment

begin_define
define|#
directive|define
name|AC97_PCM_FRONT_DAC_RATE
value|0x002C
end_define

begin_comment
comment|/* PCM Front DAC Rate */
end_comment

begin_define
define|#
directive|define
name|AC97_PCM_SURR_DAC_RATE
value|0x002E
end_define

begin_comment
comment|/* PCM Surround DAC Rate */
end_comment

begin_define
define|#
directive|define
name|AC97_PCM_LFE_DAC_RATE
value|0x0030
end_define

begin_comment
comment|/* PCM LFE DAC Rate */
end_comment

begin_define
define|#
directive|define
name|AC97_PCM_LR_ADC_RATE
value|0x0032
end_define

begin_comment
comment|/* PCM LR ADC Rate */
end_comment

begin_define
define|#
directive|define
name|AC97_PCM_MIC_ADC_RATE
value|0x0034
end_define

begin_comment
comment|/* PCM MIC ADC Rate */
end_comment

begin_define
define|#
directive|define
name|AC97_CENTER_LFE_MASTER
value|0x0036
end_define

begin_comment
comment|/* Center + LFE Master Volume */
end_comment

begin_define
define|#
directive|define
name|AC97_SURROUND_MASTER
value|0x0038
end_define

begin_comment
comment|/* Surround (Rear) Master Volume */
end_comment

begin_define
define|#
directive|define
name|AC97_RESERVED_3A
value|0x003A
end_define

begin_comment
comment|/* Reserved in AC '97< 2.2 */
end_comment

begin_comment
comment|/* AC'97 2.2 */
end_comment

begin_define
define|#
directive|define
name|AC97_SPDIF_CONTROL
value|0x003A
end_define

begin_comment
comment|/* S/PDIF Control */
end_comment

begin_comment
comment|/* range 0x3c-0x58 - MODEM */
end_comment

begin_define
define|#
directive|define
name|AC97_EXTENDED_MODEM_ID
value|0x003C
end_define

begin_define
define|#
directive|define
name|AC97_EXTEND_MODEM_STAT
value|0x003E
end_define

begin_define
define|#
directive|define
name|AC97_LINE1_RATE
value|0x0040
end_define

begin_define
define|#
directive|define
name|AC97_LINE2_RATE
value|0x0042
end_define

begin_define
define|#
directive|define
name|AC97_HANDSET_RATE
value|0x0044
end_define

begin_define
define|#
directive|define
name|AC97_LINE1_LEVEL
value|0x0046
end_define

begin_define
define|#
directive|define
name|AC97_LINE2_LEVEL
value|0x0048
end_define

begin_define
define|#
directive|define
name|AC97_HANDSET_LEVEL
value|0x004A
end_define

begin_define
define|#
directive|define
name|AC97_GPIO_CONFIG
value|0x004C
end_define

begin_define
define|#
directive|define
name|AC97_GPIO_POLARITY
value|0x004E
end_define

begin_define
define|#
directive|define
name|AC97_GPIO_STICKY
value|0x0050
end_define

begin_define
define|#
directive|define
name|AC97_GPIO_WAKE_UP
value|0x0052
end_define

begin_define
define|#
directive|define
name|AC97_GPIO_STATUS
value|0x0054
end_define

begin_define
define|#
directive|define
name|AC97_MISC_MODEM_STAT
value|0x0056
end_define

begin_define
define|#
directive|define
name|AC97_RESERVED_58
value|0x0058
end_define

begin_comment
comment|/* registers 0x005a - 0x007a are vendor reserved */
end_comment

begin_define
define|#
directive|define
name|AC97_VENDOR_ID1
value|0x007c
end_define

begin_define
define|#
directive|define
name|AC97_VENDOR_ID2
value|0x007e
end_define

begin_comment
comment|/* volume control bit defines */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AC97_MUTE
end_ifndef

begin_define
define|#
directive|define
name|AC97_MUTE
value|0x8000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AC97_MICBOOST
value|0x0040
end_define

begin_define
define|#
directive|define
name|AC97_LEFTVOL
value|0x3f00
end_define

begin_define
define|#
directive|define
name|AC97_RIGHTVOL
value|0x003f
end_define

begin_comment
comment|/* record mux defines */
end_comment

begin_define
define|#
directive|define
name|AC97_RECMUX_MIC
value|0x0000
end_define

begin_define
define|#
directive|define
name|AC97_RECMUX_CD
value|0x0101
end_define

begin_define
define|#
directive|define
name|AC97_RECMUX_VIDEO
value|0x0202
end_define

begin_define
define|#
directive|define
name|AC97_RECMUX_AUX
value|0x0303
end_define

begin_define
define|#
directive|define
name|AC97_RECMUX_LINE
value|0x0404
end_define

begin_define
define|#
directive|define
name|AC97_RECMUX_STEREO_MIX
value|0x0505
end_define

begin_define
define|#
directive|define
name|AC97_RECMUX_MONO_MIX
value|0x0606
end_define

begin_define
define|#
directive|define
name|AC97_RECMUX_PHONE
value|0x0707
end_define

begin_comment
comment|/* general purpose register bit defines */
end_comment

begin_define
define|#
directive|define
name|AC97_GP_LPBK
value|0x0080
end_define

begin_comment
comment|/* Loopback mode */
end_comment

begin_define
define|#
directive|define
name|AC97_GP_MS
value|0x0100
end_define

begin_comment
comment|/* Mic Select 0=Mic1, 1=Mic2 */
end_comment

begin_define
define|#
directive|define
name|AC97_GP_MIX
value|0x0200
end_define

begin_comment
comment|/* Mono output select 0=Mix, 1=Mic */
end_comment

begin_define
define|#
directive|define
name|AC97_GP_RLBK
value|0x0400
end_define

begin_comment
comment|/* Remote Loopback - Modem line codec */
end_comment

begin_define
define|#
directive|define
name|AC97_GP_LLBK
value|0x0800
end_define

begin_comment
comment|/* Local Loopback - Modem Line codec */
end_comment

begin_define
define|#
directive|define
name|AC97_GP_LD
value|0x1000
end_define

begin_comment
comment|/* Loudness 1=on */
end_comment

begin_define
define|#
directive|define
name|AC97_GP_3D
value|0x2000
end_define

begin_comment
comment|/* 3D Enhancement 1=on */
end_comment

begin_define
define|#
directive|define
name|AC97_GP_ST
value|0x4000
end_define

begin_comment
comment|/* Stereo Enhancement 1=on */
end_comment

begin_define
define|#
directive|define
name|AC97_GP_POP
value|0x8000
end_define

begin_comment
comment|/* Pcm Out Path, 0=pre 3D, 1=post 3D */
end_comment

begin_comment
comment|/* extended audio status and control bit defines */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_VRA
value|0x0001
end_define

begin_comment
comment|/* Variable bit rate enable bit */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_DRA
value|0x0002
end_define

begin_comment
comment|/* Double-rate audio enable bit */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_SPDIF
value|0x0004
end_define

begin_comment
comment|/* S/PDIF Enable bit */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_VRM
value|0x0008
end_define

begin_comment
comment|/* Variable bit rate for MIC enable bit */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_CDAC
value|0x0040
end_define

begin_comment
comment|/* PCM Center DAC is ready (Read only) */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_SDAC
value|0x0040
end_define

begin_comment
comment|/* PCM Surround DACs are ready (Read only) */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_LDAC
value|0x0080
end_define

begin_comment
comment|/* PCM LFE DAC is ready (Read only) */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_MDAC
value|0x0100
end_define

begin_comment
comment|/* MIC ADC is ready (Read only) */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_SPCV
value|0x0400
end_define

begin_comment
comment|/* S/PDIF configuration valid (Read only) */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_PRI
value|0x0800
end_define

begin_comment
comment|/* Turns the PCM Center DAC off */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_PRJ
value|0x1000
end_define

begin_comment
comment|/* Turns the PCM Surround DACs off */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_PRK
value|0x2000
end_define

begin_comment
comment|/* Turns the PCM LFE DAC off */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_PRL
value|0x4000
end_define

begin_comment
comment|/* Turns the MIC ADC off */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_SLOT_MASK
value|0xffcf
end_define

begin_comment
comment|/* Mask for slot assignment bits */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_SPSA_3_4
value|0x0000
end_define

begin_comment
comment|/* Slot assigned to 3& 4 */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_SPSA_7_8
value|0x0010
end_define

begin_comment
comment|/* Slot assigned to 7& 8 */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_SPSA_6_9
value|0x0020
end_define

begin_comment
comment|/* Slot assigned to 6& 9 */
end_comment

begin_define
define|#
directive|define
name|AC97_EA_SPSA_10_11
value|0x0030
end_define

begin_comment
comment|/* Slot assigned to 10& 11 */
end_comment

begin_comment
comment|/* S/PDIF control bit defines */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_PRO
value|0x0001
end_define

begin_comment
comment|/* Professional status */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_NAUDIO
value|0x0002
end_define

begin_comment
comment|/* Non audio stream */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_COPY
value|0x0004
end_define

begin_comment
comment|/* Copyright status */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_PRE
value|0x0008
end_define

begin_comment
comment|/* Preemphasis status */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_CC_MASK
value|0x07f0
end_define

begin_comment
comment|/* Category Code mask */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_L
value|0x0800
end_define

begin_comment
comment|/* Generation Level status */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_SPSR_MASK
value|0xcfff
end_define

begin_comment
comment|/* S/PDIF Sample Rate bits */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_SPSR_44K
value|0x0000
end_define

begin_comment
comment|/* Use 44.1kHz Sample rate */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_SPSR_48K
value|0x2000
end_define

begin_comment
comment|/* Use 48kHz Sample rate */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_SPSR_32K
value|0x3000
end_define

begin_comment
comment|/* Use 32kHz Sample rate */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_DRS
value|0x4000
end_define

begin_comment
comment|/* Double Rate S/PDIF */
end_comment

begin_define
define|#
directive|define
name|AC97_SC_V
value|0x8000
end_define

begin_comment
comment|/* Validity status */
end_comment

begin_comment
comment|/* powerdown control and status bit defines */
end_comment

begin_comment
comment|/* status */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_MDM
value|0x0010
end_define

begin_comment
comment|/* Modem section ready */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_REF
value|0x0008
end_define

begin_comment
comment|/* Vref nominal */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_ANL
value|0x0004
end_define

begin_comment
comment|/* Analog section ready */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_DAC
value|0x0002
end_define

begin_comment
comment|/* DAC section ready */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_ADC
value|0x0001
end_define

begin_comment
comment|/* ADC section ready */
end_comment

begin_comment
comment|/* control */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_PR0
value|0x0100
end_define

begin_comment
comment|/* ADC and Mux powerdown */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_PR1
value|0x0200
end_define

begin_comment
comment|/* DAC powerdown */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_PR2
value|0x0400
end_define

begin_comment
comment|/* Output mixer powerdown (Vref on) */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_PR3
value|0x0800
end_define

begin_comment
comment|/* Output mixer powerdown (Vref off) */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_PR4
value|0x1000
end_define

begin_comment
comment|/* AC-link powerdown */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_PR5
value|0x2000
end_define

begin_comment
comment|/* Internal Clk disable */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_PR6
value|0x4000
end_define

begin_comment
comment|/* HP amp powerdown */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_PR7
value|0x8000
end_define

begin_comment
comment|/* Modem off - if supported */
end_comment

begin_comment
comment|/* extended audio ID register bit defines */
end_comment

begin_define
define|#
directive|define
name|AC97_EXTID_VRA
value|0x0001
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_DRA
value|0x0002
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_SPDIF
value|0x0004
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_VRM
value|0x0008
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_DSA0
value|0x0010
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_DSA1
value|0x0020
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_CDAC
value|0x0040
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_SDAC
value|0x0080
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_LDAC
value|0x0100
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_AMAP
value|0x0200
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_REV0
value|0x0400
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_REV1
value|0x0800
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_ID0
value|0x4000
end_define

begin_define
define|#
directive|define
name|AC97_EXTID_ID1
value|0x8000
end_define

begin_comment
comment|/* extended status register bit defines */
end_comment

begin_define
define|#
directive|define
name|AC97_EXTSTAT_VRA
value|0x0001
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_DRA
value|0x0002
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_SPDIF
value|0x0004
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_VRM
value|0x0008
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_SPSA0
value|0x0010
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_SPSA1
value|0x0020
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_CDAC
value|0x0040
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_SDAC
value|0x0080
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_LDAC
value|0x0100
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_MADC
value|0x0200
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_SPCV
value|0x0400
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_PRI
value|0x0800
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_PRJ
value|0x1000
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_PRK
value|0x2000
end_define

begin_define
define|#
directive|define
name|AC97_EXTSTAT_PRL
value|0x4000
end_define

begin_comment
comment|/* useful power states */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_D0
value|0x0000
end_define

begin_comment
comment|/* everything on */
end_comment

begin_define
define|#
directive|define
name|AC97_PWR_D1
value|AC97_PWR_PR0|AC97_PWR_PR1|AC97_PWR_PR4
end_define

begin_define
define|#
directive|define
name|AC97_PWR_D2
value|AC97_PWR_PR0|AC97_PWR_PR1|AC97_PWR_PR2|AC97_PWR_PR3|AC97_PWR_PR4
end_define

begin_define
define|#
directive|define
name|AC97_PWR_D3
value|AC97_PWR_PR0|AC97_PWR_PR1|AC97_PWR_PR2|AC97_PWR_PR3|AC97_PWR_PR4
end_define

begin_define
define|#
directive|define
name|AC97_PWR_ANLOFF
value|AC97_PWR_PR2|AC97_PWR_PR3
end_define

begin_comment
comment|/* analog section off */
end_comment

begin_comment
comment|/* Total number of defined registers.  */
end_comment

begin_define
define|#
directive|define
name|AC97_REG_CNT
value|64
end_define

begin_comment
comment|/* OSS interface to the ac97s.. */
end_comment

begin_define
define|#
directive|define
name|AC97_STEREO_MASK
value|(SOUND_MASK_VOLUME|SOUND_MASK_PCM|\ 	SOUND_MASK_LINE|SOUND_MASK_CD|\ 	SOUND_MASK_ALTPCM|SOUND_MASK_IGAIN|\ 	SOUND_MASK_LINE1|SOUND_MASK_VIDEO)
end_define

begin_define
define|#
directive|define
name|AC97_SUPPORTED_MASK
value|(AC97_STEREO_MASK | \ 	SOUND_MASK_BASS|SOUND_MASK_TREBLE|\ 	SOUND_MASK_SPEAKER|SOUND_MASK_MIC|\ 	SOUND_MASK_PHONEIN|SOUND_MASK_PHONEOUT)
end_define

begin_define
define|#
directive|define
name|AC97_RECORD_MASK
value|(SOUND_MASK_MIC|\ 	SOUND_MASK_CD|SOUND_MASK_IGAIN|SOUND_MASK_VIDEO|\ 	SOUND_MASK_LINE1| SOUND_MASK_LINE|\ 	SOUND_MASK_PHONEIN)
end_define

begin_comment
comment|/* original check is not good enough in case FOO is greater than  * SOUND_MIXER_NRDEVICES because the supported_mixers has exactly  * SOUND_MIXER_NRDEVICES elements.  * before matching the given mixer against the bitmask in supported_mixers we  * check if mixer number exceeds maximum allowed size which is as mentioned  * above SOUND_MIXER_NRDEVICES */
end_comment

begin_define
define|#
directive|define
name|supported_mixer
parameter_list|(
name|CODEC
parameter_list|,
name|FOO
parameter_list|)
value|((FOO>= 0)&& \                                     (FOO< SOUND_MIXER_NRDEVICES)&& \                                     (CODEC)->supported_mixers& (1<<FOO) )
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_struct
struct|struct
name|ac97_codec
block|{
comment|/* AC97 controller connected with */
name|void
modifier|*
name|private_data
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|id
decl_stmt|;
name|int
name|dev_mixer
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|modem
range|:
literal|1
decl_stmt|;
name|struct
name|ac97_ops
modifier|*
name|codec_ops
decl_stmt|;
comment|/* controller specific lower leverl ac97 accessing routines */
name|u16
function_decl|(
modifier|*
name|codec_read
function_decl|)
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|,
name|u8
name|reg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|codec_write
function_decl|)
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|,
name|u8
name|reg
parameter_list|,
name|u16
name|val
parameter_list|)
function_decl|;
comment|/* Wait for codec-ready.  Ok to sleep here.  */
name|void
function_decl|(
modifier|*
name|codec_wait
function_decl|)
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|)
function_decl|;
comment|/* OSS mixer masks */
name|int
name|modcnt
decl_stmt|;
name|int
name|supported_mixers
decl_stmt|;
name|int
name|stereo_mixers
decl_stmt|;
name|int
name|record_sources
decl_stmt|;
comment|/* Property flags */
name|int
name|flags
decl_stmt|;
name|int
name|bit_resolution
decl_stmt|;
comment|/* OSS mixer interface */
name|int
function_decl|(
modifier|*
name|read_mixer
function_decl|)
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|,
name|int
name|oss_channel
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|write_mixer
function_decl|)
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|,
name|int
name|oss_channel
parameter_list|,
name|unsigned
name|int
name|left
parameter_list|,
name|unsigned
name|int
name|right
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|recmask_io
function_decl|)
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|,
name|int
name|rw
parameter_list|,
name|int
name|mask
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|mixer_ioctl
function_decl|)
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|,
name|unsigned
name|int
name|cmd
parameter_list|,
name|unsigned
name|long
name|arg
parameter_list|)
function_decl|;
comment|/* saved OSS mixer states */
name|unsigned
name|int
name|mixer_state
index|[
name|SOUND_MIXER_NRDEVICES
index|]
decl_stmt|;
comment|/* Software Modem interface */
name|int
function_decl|(
modifier|*
name|modem_ioctl
function_decl|)
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|,
name|unsigned
name|int
name|cmd
parameter_list|,
name|unsigned
name|long
name|arg
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Operation structures for each known AC97 chip  */
end_comment

begin_struct
struct|struct
name|ac97_ops
block|{
comment|/* Initialise */
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|c
parameter_list|)
function_decl|;
comment|/* Amplifier control */
name|int
function_decl|(
modifier|*
name|amplifier
function_decl|)
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
comment|/* Digital mode control */
name|int
function_decl|(
modifier|*
name|digital
function_decl|)
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|,
name|int
name|format
parameter_list|)
function_decl|;
define|#
directive|define
name|AC97_DELUDED_MODEM
value|1
comment|/* Audio codec reports its a modem */
define|#
directive|define
name|AC97_NO_PCM_VOLUME
value|2
comment|/* Volume control is missing 	   */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|ac97_read_proc
parameter_list|(
name|char
modifier|*
name|page_out
parameter_list|,
name|char
modifier|*
modifier|*
name|start
parameter_list|,
name|off_t
name|off
parameter_list|,
name|int
name|count
parameter_list|,
name|int
modifier|*
name|eof
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ac97_probe_codec
parameter_list|(
name|struct
name|ac97_codec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|ac97_set_adc_rate
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|,
name|unsigned
name|int
name|rate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|ac97_set_dac_rate
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|,
name|unsigned
name|int
name|rate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ac97_save_state
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ac97_restore_state
parameter_list|(
name|struct
name|ac97_codec
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__linux__*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AC97_CODEC_H_ */
end_comment

end_unit

