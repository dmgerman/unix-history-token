begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-7  * Copyright (c) 2006 Stephane E. Potvin<sepotvin@videotron.ca>  * Copyright (c) 2006 Ariff Abdullah<ariff@FreeBSD.org>  * Copyright (c) 2008-2012 Alexander Motin<mav@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Intel High Definition Audio (Audio function quirks) driver for FreeBSD.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HDAA_QUIRKS_H_
end_ifndef

begin_define
define|#
directive|define
name|_HDAA_QUIRKS_H_
end_define

begin_define
define|#
directive|define
name|HDAA_GPIO_SHIFT
parameter_list|(
name|n
parameter_list|)
value|(n * 3)
end_define

begin_define
define|#
directive|define
name|HDAA_GPIO_MASK
parameter_list|(
name|n
parameter_list|)
value|(0x7<< (n * 3))
end_define

begin_define
define|#
directive|define
name|HDAA_GPIO_KEEP
parameter_list|(
name|n
parameter_list|)
value|(0x0<< (n * 3))
end_define

begin_define
define|#
directive|define
name|HDAA_GPIO_SET
parameter_list|(
name|n
parameter_list|)
value|(0x1<< (n * 3))
end_define

begin_define
define|#
directive|define
name|HDAA_GPIO_CLEAR
parameter_list|(
name|n
parameter_list|)
value|(0x2<< (n * 3))
end_define

begin_define
define|#
directive|define
name|HDAA_GPIO_DISABLE
parameter_list|(
name|n
parameter_list|)
value|(0x3<< (n * 3))
end_define

begin_define
define|#
directive|define
name|HDAA_GPIO_INPUT
parameter_list|(
name|n
parameter_list|)
value|(0x4<< (n * 3))
end_define

begin_comment
comment|/* 9 - 25 = anything else */
end_comment

begin_define
define|#
directive|define
name|HDAA_QUIRK_SOFTPCMVOL
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_FIXEDRATE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_FORCESTEREO
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_EAPDINV
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_SENSEINV
value|(1<< 14)
end_define

begin_comment
comment|/* 26 - 31 = vrefs */
end_comment

begin_define
define|#
directive|define
name|HDAA_QUIRK_IVREF50
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_IVREF80
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_IVREF100
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_OVREF50
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_OVREF80
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_OVREF100
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_IVREF
value|(HDAA_QUIRK_IVREF50 | HDAA_QUIRK_IVREF80 | \ 						HDAA_QUIRK_IVREF100)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_OVREF
value|(HDAA_QUIRK_OVREF50 | HDAA_QUIRK_OVREF80 | \ 						HDAA_QUIRK_OVREF100)
end_define

begin_define
define|#
directive|define
name|HDAA_QUIRK_VREF
value|(HDAA_QUIRK_IVREF | HDAA_QUIRK_OVREF)
end_define

begin_define
define|#
directive|define
name|HDAA_AMP_VOL_DEFAULT
value|(-1)
end_define

begin_define
define|#
directive|define
name|HDAA_AMP_MUTE_DEFAULT
value|(0xffffffff)
end_define

begin_define
define|#
directive|define
name|HDAA_AMP_MUTE_NONE
value|(0)
end_define

begin_define
define|#
directive|define
name|HDAA_AMP_MUTE_LEFT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDAA_AMP_MUTE_RIGHT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDAA_AMP_MUTE_ALL
value|(HDAA_AMP_MUTE_LEFT | HDAA_AMP_MUTE_RIGHT)
end_define

begin_define
define|#
directive|define
name|HDAA_AMP_LEFT_MUTED
parameter_list|(
name|v
parameter_list|)
value|((v)& (HDAA_AMP_MUTE_LEFT))
end_define

begin_define
define|#
directive|define
name|HDAA_AMP_RIGHT_MUTED
parameter_list|(
name|v
parameter_list|)
value|(((v)& HDAA_AMP_MUTE_RIGHT)>> 1)
end_define

begin_comment
comment|/* Widget in playback receiving signal from recording. */
end_comment

begin_define
define|#
directive|define
name|HDAA_ADC_MONITOR
value|(1<< 0)
end_define

begin_comment
comment|/* Input mixer widget needs volume control as destination. */
end_comment

begin_define
define|#
directive|define
name|HDAA_IMIX_AS_DST
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|HDAA_CTL_OUT
value|1
end_define

begin_define
define|#
directive|define
name|HDAA_CTL_IN
value|2
end_define

begin_define
define|#
directive|define
name|HDA_MAX_CONNS
value|32
end_define

begin_define
define|#
directive|define
name|HDA_MAX_NAMELEN
value|32
end_define

begin_struct_decl
struct_decl|struct
name|hdaa_audio_as
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hdaa_audio_ctl
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hdaa_chan
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hdaa_devinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hdaa_pcm_devinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hdaa_widget
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|hdaa_widget
block|{
name|nid_t
name|nid
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|enable
decl_stmt|;
name|int
name|nconns
decl_stmt|,
name|selconn
decl_stmt|;
name|int
name|waspin
decl_stmt|;
name|uint32_t
name|pflags
decl_stmt|;
name|int
name|bindas
decl_stmt|;
name|int
name|bindseqmask
decl_stmt|;
name|int
name|ossdev
decl_stmt|;
name|uint32_t
name|ossmask
decl_stmt|;
name|int
name|unsol
decl_stmt|;
name|nid_t
name|conns
index|[
name|HDA_MAX_CONNS
index|]
decl_stmt|;
name|u_char
name|connsenable
index|[
name|HDA_MAX_CONNS
index|]
decl_stmt|;
name|char
name|name
index|[
name|HDA_MAX_NAMELEN
index|]
decl_stmt|;
name|uint8_t
modifier|*
name|eld
decl_stmt|;
name|int
name|eld_len
decl_stmt|;
name|struct
name|hdaa_devinfo
modifier|*
name|devinfo
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|widget_cap
decl_stmt|;
name|uint32_t
name|outamp_cap
decl_stmt|;
name|uint32_t
name|inamp_cap
decl_stmt|;
name|uint32_t
name|supp_stream_formats
decl_stmt|;
name|uint32_t
name|supp_pcm_size_rate
decl_stmt|;
name|uint32_t
name|eapdbtl
decl_stmt|;
block|}
name|param
struct|;
union|union
block|{
struct|struct
block|{
name|uint32_t
name|config
decl_stmt|;
name|uint32_t
name|original
decl_stmt|;
name|uint32_t
name|newconf
decl_stmt|;
name|uint32_t
name|cap
decl_stmt|;
name|uint32_t
name|ctrl
decl_stmt|;
name|int
name|connected
decl_stmt|;
block|}
name|pin
struct|;
struct|struct
block|{
name|uint8_t
name|stripecap
decl_stmt|;
block|}
name|conv
struct|;
block|}
name|wclass
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hdaa_audio_ctl
block|{
name|struct
name|hdaa_widget
modifier|*
name|widget
decl_stmt|,
modifier|*
name|childwidget
decl_stmt|;
name|int
name|enable
decl_stmt|;
name|int
name|index
decl_stmt|,
name|dir
decl_stmt|,
name|ndir
decl_stmt|;
name|int
name|mute
decl_stmt|,
name|step
decl_stmt|,
name|size
decl_stmt|,
name|offset
decl_stmt|;
name|int
name|left
decl_stmt|,
name|right
decl_stmt|,
name|forcemute
decl_stmt|;
name|uint32_t
name|muted
decl_stmt|;
name|uint32_t
name|ossmask
decl_stmt|;
comment|/* OSS devices that may affect control. */
name|int
name|devleft
index|[
name|SOUND_MIXER_NRDEVICES
index|]
decl_stmt|;
comment|/* Left ampl in 1/4dB. */
name|int
name|devright
index|[
name|SOUND_MIXER_NRDEVICES
index|]
decl_stmt|;
comment|/* Right ampl in 1/4dB. */
name|int
name|devmute
index|[
name|SOUND_MIXER_NRDEVICES
index|]
decl_stmt|;
comment|/* Mutes per OSS device. */
block|}
struct|;
end_struct

begin_comment
comment|/* Association is a group of pins bound for some special function. */
end_comment

begin_struct
struct|struct
name|hdaa_audio_as
block|{
name|u_char
name|enable
decl_stmt|;
name|u_char
name|index
decl_stmt|;
name|u_char
name|dir
decl_stmt|;
name|u_char
name|pincnt
decl_stmt|;
name|u_char
name|fakeredir
decl_stmt|;
name|u_char
name|digital
decl_stmt|;
name|uint16_t
name|pinset
decl_stmt|;
name|nid_t
name|hpredir
decl_stmt|;
name|nid_t
name|pins
index|[
literal|16
index|]
decl_stmt|;
name|nid_t
name|dacs
index|[
literal|2
index|]
index|[
literal|16
index|]
decl_stmt|;
name|int
name|num_chans
decl_stmt|;
name|int
name|chans
index|[
literal|2
index|]
decl_stmt|;
name|int
name|location
decl_stmt|;
comment|/* Pins location, if all have the same */
name|int
name|mixed
decl_stmt|;
comment|/* Mixed/multiplexed recording, not multichannel. */
name|struct
name|hdaa_pcm_devinfo
modifier|*
name|pdevinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hdaa_pcm_devinfo
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|hdaa_devinfo
modifier|*
name|devinfo
decl_stmt|;
name|struct
name|snd_mixer
modifier|*
name|mixer
decl_stmt|;
name|int
name|index
decl_stmt|;
name|int
name|registered
decl_stmt|;
name|int
name|playas
decl_stmt|,
name|recas
decl_stmt|;
name|u_char
name|left
index|[
name|SOUND_MIXER_NRDEVICES
index|]
decl_stmt|;
name|u_char
name|right
index|[
name|SOUND_MIXER_NRDEVICES
index|]
decl_stmt|;
name|int
name|minamp
index|[
name|SOUND_MIXER_NRDEVICES
index|]
decl_stmt|;
comment|/* Minimal amps in 1/4dB. */
name|int
name|maxamp
index|[
name|SOUND_MIXER_NRDEVICES
index|]
decl_stmt|;
comment|/* Maximal amps in 1/4dB. */
name|int
name|chan_size
decl_stmt|;
name|int
name|chan_blkcnt
decl_stmt|;
name|u_char
name|digital
decl_stmt|;
name|uint32_t
name|ossmask
decl_stmt|;
comment|/* Mask of supported OSS devices. */
name|uint32_t
name|recsrc
decl_stmt|;
comment|/* Mask of supported OSS sources. */
name|int
name|autorecsrc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hdaa_devinfo
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|mtx
modifier|*
name|lock
decl_stmt|;
name|nid_t
name|nid
decl_stmt|;
name|nid_t
name|startnode
decl_stmt|,
name|endnode
decl_stmt|;
name|uint32_t
name|outamp_cap
decl_stmt|;
name|uint32_t
name|inamp_cap
decl_stmt|;
name|uint32_t
name|supp_stream_formats
decl_stmt|;
name|uint32_t
name|supp_pcm_size_rate
decl_stmt|;
name|uint32_t
name|gpio_cap
decl_stmt|;
name|uint32_t
name|quirks
decl_stmt|;
name|uint32_t
name|newquirks
decl_stmt|;
name|uint32_t
name|gpio
decl_stmt|;
name|uint32_t
name|newgpio
decl_stmt|;
name|uint32_t
name|gpo
decl_stmt|;
name|uint32_t
name|newgpo
decl_stmt|;
name|int
name|nodecnt
decl_stmt|;
name|int
name|ctlcnt
decl_stmt|;
name|int
name|ascnt
decl_stmt|;
name|int
name|num_devs
decl_stmt|;
name|int
name|num_chans
decl_stmt|;
name|struct
name|hdaa_widget
modifier|*
name|widget
decl_stmt|;
name|struct
name|hdaa_audio_ctl
modifier|*
name|ctl
decl_stmt|;
name|struct
name|hdaa_audio_as
modifier|*
name|as
decl_stmt|;
name|struct
name|hdaa_pcm_devinfo
modifier|*
name|devs
decl_stmt|;
name|struct
name|hdaa_chan
modifier|*
name|chans
decl_stmt|;
name|struct
name|callout
name|poll_jack
decl_stmt|;
name|int
name|poll_ival
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HDAA_CHN_RUNNING
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HDAA_CHN_SUSPEND
value|0x00000002
end_define

begin_struct
struct|struct
name|hdaa_chan
block|{
name|struct
name|snd_dbuf
modifier|*
name|b
decl_stmt|;
name|struct
name|pcm_channel
modifier|*
name|c
decl_stmt|;
name|struct
name|pcmchan_caps
name|caps
decl_stmt|;
name|struct
name|hdaa_devinfo
modifier|*
name|devinfo
decl_stmt|;
name|struct
name|hdaa_pcm_devinfo
modifier|*
name|pdevinfo
decl_stmt|;
name|uint32_t
name|spd
decl_stmt|,
name|fmt
decl_stmt|,
name|fmtlist
index|[
literal|32
index|]
decl_stmt|,
name|pcmrates
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|supp_stream_formats
decl_stmt|,
name|supp_pcm_size_rate
decl_stmt|;
name|uint32_t
name|blkcnt
decl_stmt|,
name|blksz
decl_stmt|;
name|uint32_t
modifier|*
name|dmapos
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|int
name|dir
decl_stmt|;
name|int
name|off
decl_stmt|;
name|int
name|sid
decl_stmt|;
name|int
name|bit16
decl_stmt|,
name|bit32
decl_stmt|;
name|int
name|channels
decl_stmt|;
comment|/* Number of audio channels. */
name|int
name|as
decl_stmt|;
comment|/* Number of association. */
name|int
name|asindex
decl_stmt|;
comment|/* Index within association. */
name|nid_t
name|io
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|stripecap
decl_stmt|;
comment|/* AND of stripecap of all ios. */
name|uint8_t
name|stripectl
decl_stmt|;
comment|/* stripe to use to all ios. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MINQDB
parameter_list|(
name|ctl
parameter_list|)
define|\
value|((0 - (ctl)->offset) * ((ctl)->size + 1))
end_define

begin_define
define|#
directive|define
name|MAXQDB
parameter_list|(
name|ctl
parameter_list|)
define|\
value|(((ctl)->step - (ctl)->offset) * ((ctl)->size + 1))
end_define

begin_define
define|#
directive|define
name|RANGEQDB
parameter_list|(
name|ctl
parameter_list|)
define|\
value|((ctl)->step * ((ctl)->size + 1))
end_define

begin_define
define|#
directive|define
name|VAL2QDB
parameter_list|(
name|ctl
parameter_list|,
name|val
parameter_list|)
define|\
value|(((ctl)->size + 1) * ((int)(val) - (ctl)->offset))
end_define

begin_define
define|#
directive|define
name|QDB2VAL
parameter_list|(
name|ctl
parameter_list|,
name|qdb
parameter_list|)
define|\
value|imax(imin((((qdb) + (ctl)->size / 2 * ((qdb)> 0 ? 1 : -1)) /	\ 	 ((ctl)->size + 1) + (ctl)->offset), (ctl)->step), 0)
end_define

begin_define
define|#
directive|define
name|hdaa_codec_id
parameter_list|(
name|devinfo
parameter_list|)
define|\
value|(((uint32_t)hda_get_vendor_id(devinfo->dev)<< 16) +	\ 		hda_get_device_id(devinfo->dev))
end_define

begin_define
define|#
directive|define
name|hdaa_card_id
parameter_list|(
name|devinfo
parameter_list|)
define|\
value|(((uint32_t)hda_get_subdevice_id(devinfo->dev)<< 16) +	\ 		hda_get_subvendor_id(devinfo->dev))
end_define

begin_function_decl
name|struct
name|hdaa_widget
modifier|*
name|hdaa_widget_get
parameter_list|(
name|struct
name|hdaa_devinfo
modifier|*
parameter_list|,
name|nid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|hdaa_widget_pin_patch
parameter_list|(
name|uint32_t
name|config
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|hdaa_gpio_patch
parameter_list|(
name|uint32_t
name|gpio
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hdaa_patch
parameter_list|(
name|struct
name|hdaa_devinfo
modifier|*
name|devinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hdaa_patch_direct
parameter_list|(
name|struct
name|hdaa_devinfo
modifier|*
name|devinfo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

