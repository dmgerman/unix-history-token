begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: uaudioreg.h,v 1.12 2004/11/05 19:08:29 kent Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|UAUDIO_VERSION
value|0x100
end_define

begin_define
define|#
directive|define
name|UDESC_CS_CONFIG
value|0x22
end_define

begin_define
define|#
directive|define
name|UDESC_CS_STRING
value|0x23
end_define

begin_define
define|#
directive|define
name|UDESC_CS_INTERFACE
value|0x24
end_define

begin_define
define|#
directive|define
name|UDESC_CS_ENDPOINT
value|0x25
end_define

begin_define
define|#
directive|define
name|UDESCSUB_AC_HEADER
value|1
end_define

begin_define
define|#
directive|define
name|UDESCSUB_AC_INPUT
value|2
end_define

begin_define
define|#
directive|define
name|UDESCSUB_AC_OUTPUT
value|3
end_define

begin_define
define|#
directive|define
name|UDESCSUB_AC_MIXER
value|4
end_define

begin_define
define|#
directive|define
name|UDESCSUB_AC_SELECTOR
value|5
end_define

begin_define
define|#
directive|define
name|UDESCSUB_AC_FEATURE
value|6
end_define

begin_define
define|#
directive|define
name|UDESCSUB_AC_PROCESSING
value|7
end_define

begin_define
define|#
directive|define
name|UDESCSUB_AC_EXTENSION
value|8
end_define

begin_comment
comment|/* The first fields are identical to usb_endpoint_descriptor_t */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bEndpointAddress
decl_stmt|;
name|uByte
name|bmAttributes
decl_stmt|;
name|uWord
name|wMaxPacketSize
decl_stmt|;
name|uByte
name|bInterval
decl_stmt|;
comment|/* 	 * The following two entries are only used by the Audio Class. 	 * And according to the specs the Audio Class is the only one 	 * allowed to extend the endpoint descriptor. 	 * Who knows what goes on in the minds of the people in the USB 	 * standardization?  :-( 	 */
name|uByte
name|bRefresh
decl_stmt|;
name|uByte
name|bSynchAddress
decl_stmt|;
block|}
name|UPACKED
name|usb_endpoint_descriptor_audio_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_audio_control_descriptor
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uWord
name|bcdADC
decl_stmt|;
name|uWord
name|wTotalLength
decl_stmt|;
name|uByte
name|bInCollection
decl_stmt|;
name|uByte
name|baInterfaceNr
index|[
literal|1
index|]
decl_stmt|;
block|}
name|UPACKED
struct|;
end_struct

begin_struct
struct|struct
name|usb_audio_streaming_interface_descriptor
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bTerminalLink
decl_stmt|;
name|uByte
name|bDelay
decl_stmt|;
name|uWord
name|wFormatTag
decl_stmt|;
block|}
name|UPACKED
struct|;
end_struct

begin_struct
struct|struct
name|usb_audio_streaming_endpoint_descriptor
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bmAttributes
decl_stmt|;
define|#
directive|define
name|UA_SED_FREQ_CONTROL
value|0x01
define|#
directive|define
name|UA_SED_PITCH_CONTROL
value|0x02
define|#
directive|define
name|UA_SED_MAXPACKETSONLY
value|0x80
name|uByte
name|bLockDelayUnits
decl_stmt|;
name|uWord
name|wLockDelay
decl_stmt|;
block|}
name|UPACKED
struct|;
end_struct

begin_struct
struct|struct
name|usb_audio_streaming_type1_descriptor
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bFormatType
decl_stmt|;
name|uByte
name|bNrChannels
decl_stmt|;
name|uByte
name|bSubFrameSize
decl_stmt|;
name|uByte
name|bBitResolution
decl_stmt|;
name|uByte
name|bSamFreqType
decl_stmt|;
define|#
directive|define
name|UA_SAMP_CONTNUOUS
value|0
name|uByte
name|tSamFreq
index|[
literal|3
operator|*
literal|2
index|]
decl_stmt|;
comment|/* room for low and high */
define|#
directive|define
name|UA_GETSAMP
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|((p)->tSamFreq[(n)*3+0] | ((p)->tSamFreq[(n)*3+1]<< 8) | ((p)->tSamFreq[(n)*3+2]<< 16))
define|#
directive|define
name|UA_SAMP_LO
parameter_list|(
name|p
parameter_list|)
value|UA_GETSAMP(p, 0)
define|#
directive|define
name|UA_SAMP_HI
parameter_list|(
name|p
parameter_list|)
value|UA_GETSAMP(p, 1)
block|}
name|UPACKED
struct|;
end_struct

begin_struct
struct|struct
name|usb_audio_cluster
block|{
name|uByte
name|bNrChannels
decl_stmt|;
name|uWord
name|wChannelConfig
decl_stmt|;
define|#
directive|define
name|UA_CHANNEL_LEFT
value|0x0001
define|#
directive|define
name|UA_CHANNEL_RIGHT
value|0x0002
define|#
directive|define
name|UA_CHANNEL_CENTER
value|0x0004
define|#
directive|define
name|UA_CHANNEL_LFE
value|0x0008
define|#
directive|define
name|UA_CHANNEL_L_SURROUND
value|0x0010
define|#
directive|define
name|UA_CHANNEL_R_SURROUND
value|0x0020
define|#
directive|define
name|UA_CHANNEL_L_CENTER
value|0x0040
define|#
directive|define
name|UA_CHANNEL_R_CENTER
value|0x0080
define|#
directive|define
name|UA_CHANNEL_SURROUND
value|0x0100
define|#
directive|define
name|UA_CHANNEL_L_SIDE
value|0x0200
define|#
directive|define
name|UA_CHANNEL_R_SIDE
value|0x0400
define|#
directive|define
name|UA_CHANNEL_TOP
value|0x0800
name|uByte
name|iChannelNames
decl_stmt|;
block|}
name|UPACKED
struct|;
end_struct

begin_comment
comment|/* Shared by all units and terminals */
end_comment

begin_struct
struct|struct
name|usb_audio_unit
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bUnitId
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* UDESCSUB_AC_INPUT */
end_comment

begin_struct
struct|struct
name|usb_audio_input_terminal
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bTerminalId
decl_stmt|;
name|uWord
name|wTerminalType
decl_stmt|;
name|uByte
name|bAssocTerminal
decl_stmt|;
name|uByte
name|bNrChannels
decl_stmt|;
name|uWord
name|wChannelConfig
decl_stmt|;
name|uByte
name|iChannelNames
decl_stmt|;
name|uByte
name|iTerminal
decl_stmt|;
block|}
name|UPACKED
struct|;
end_struct

begin_comment
comment|/* UDESCSUB_AC_OUTPUT */
end_comment

begin_struct
struct|struct
name|usb_audio_output_terminal
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bTerminalId
decl_stmt|;
name|uWord
name|wTerminalType
decl_stmt|;
name|uByte
name|bAssocTerminal
decl_stmt|;
name|uByte
name|bSourceId
decl_stmt|;
name|uByte
name|iTerminal
decl_stmt|;
block|}
name|UPACKED
struct|;
end_struct

begin_comment
comment|/* UDESCSUB_AC_MIXER */
end_comment

begin_struct
struct|struct
name|usb_audio_mixer_unit
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bUnitId
decl_stmt|;
name|uByte
name|bNrInPins
decl_stmt|;
name|uByte
name|baSourceId
index|[
literal|255
index|]
decl_stmt|;
comment|/* [bNrInPins] */
comment|/* struct usb_audio_mixer_unit_1 */
block|}
name|UPACKED
struct|;
end_struct

begin_struct
struct|struct
name|usb_audio_mixer_unit_1
block|{
name|uByte
name|bNrChannels
decl_stmt|;
name|uWord
name|wChannelConfig
decl_stmt|;
name|uByte
name|iChannelNames
decl_stmt|;
name|uByte
name|bmControls
index|[
literal|255
index|]
decl_stmt|;
comment|/* [bNrChannels] */
comment|/*uByte		iMixer;*/
block|}
name|UPACKED
struct|;
end_struct

begin_comment
comment|/* UDESCSUB_AC_SELECTOR */
end_comment

begin_struct
struct|struct
name|usb_audio_selector_unit
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bUnitId
decl_stmt|;
name|uByte
name|bNrInPins
decl_stmt|;
name|uByte
name|baSourceId
index|[
literal|255
index|]
decl_stmt|;
comment|/* [bNrInPins] */
comment|/* uByte	iSelector; */
block|}
name|UPACKED
struct|;
end_struct

begin_comment
comment|/* UDESCSUB_AC_FEATURE */
end_comment

begin_struct
struct|struct
name|usb_audio_feature_unit
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bUnitId
decl_stmt|;
name|uByte
name|bSourceId
decl_stmt|;
name|uByte
name|bControlSize
decl_stmt|;
name|uByte
name|bmaControls
index|[
literal|255
index|]
decl_stmt|;
comment|/* size for more than enough */
comment|/* uByte	iFeature; */
block|}
name|UPACKED
struct|;
end_struct

begin_comment
comment|/* UDESCSUB_AC_PROCESSING */
end_comment

begin_struct
struct|struct
name|usb_audio_processing_unit
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bUnitId
decl_stmt|;
name|uWord
name|wProcessType
decl_stmt|;
name|uByte
name|bNrInPins
decl_stmt|;
name|uByte
name|baSourceId
index|[
literal|255
index|]
decl_stmt|;
comment|/* [bNrInPins] */
comment|/* struct usb_audio_processing_unit_1 */
block|}
name|UPACKED
struct|;
end_struct

begin_struct
struct|struct
name|usb_audio_processing_unit_1
block|{
name|uByte
name|bNrChannels
decl_stmt|;
name|uWord
name|wChannelConfig
decl_stmt|;
name|uByte
name|iChannelNames
decl_stmt|;
name|uByte
name|bControlSize
decl_stmt|;
name|uByte
name|bmControls
index|[
literal|255
index|]
decl_stmt|;
comment|/* [bControlSize] */
define|#
directive|define
name|UA_PROC_ENABLE_MASK
value|1
block|}
name|UPACKED
struct|;
end_struct

begin_struct
struct|struct
name|usb_audio_processing_unit_updown
block|{
name|uByte
name|iProcessing
decl_stmt|;
name|uByte
name|bNrModes
decl_stmt|;
name|uWord
name|waModes
index|[
literal|255
index|]
decl_stmt|;
comment|/* [bNrModes] */
block|}
name|UPACKED
struct|;
end_struct

begin_comment
comment|/* UDESCSUB_AC_EXTENSION */
end_comment

begin_struct
struct|struct
name|usb_audio_extension_unit
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bUnitId
decl_stmt|;
name|uWord
name|wExtensionCode
decl_stmt|;
name|uByte
name|bNrInPins
decl_stmt|;
name|uByte
name|baSourceId
index|[
literal|255
index|]
decl_stmt|;
comment|/* [bNrInPins] */
comment|/* struct usb_audio_extension_unit_1 */
block|}
name|UPACKED
struct|;
end_struct

begin_struct
struct|struct
name|usb_audio_extension_unit_1
block|{
name|uByte
name|bNrChannels
decl_stmt|;
name|uWord
name|wChannelConfig
decl_stmt|;
name|uByte
name|iChannelNames
decl_stmt|;
name|uByte
name|bControlSize
decl_stmt|;
name|uByte
name|bmControls
index|[
literal|255
index|]
decl_stmt|;
comment|/* [bControlSize] */
define|#
directive|define
name|UA_EXT_ENABLE_MASK
value|1
define|#
directive|define
name|UA_EXT_ENABLE
value|1
comment|/*uByte		iExtension;*/
block|}
name|UPACKED
struct|;
end_struct

begin_comment
comment|/* USB terminal types */
end_comment

begin_define
define|#
directive|define
name|UAT_UNDEFINED
value|0x0100
end_define

begin_define
define|#
directive|define
name|UAT_STREAM
value|0x0101
end_define

begin_define
define|#
directive|define
name|UAT_VENDOR
value|0x01ff
end_define

begin_comment
comment|/* input terminal types */
end_comment

begin_define
define|#
directive|define
name|UATI_UNDEFINED
value|0x0200
end_define

begin_define
define|#
directive|define
name|UATI_MICROPHONE
value|0x0201
end_define

begin_define
define|#
directive|define
name|UATI_DESKMICROPHONE
value|0x0202
end_define

begin_define
define|#
directive|define
name|UATI_PERSONALMICROPHONE
value|0x0203
end_define

begin_define
define|#
directive|define
name|UATI_OMNIMICROPHONE
value|0x0204
end_define

begin_define
define|#
directive|define
name|UATI_MICROPHONEARRAY
value|0x0205
end_define

begin_define
define|#
directive|define
name|UATI_PROCMICROPHONEARR
value|0x0206
end_define

begin_comment
comment|/* output terminal types */
end_comment

begin_define
define|#
directive|define
name|UATO_UNDEFINED
value|0x0300
end_define

begin_define
define|#
directive|define
name|UATO_SPEAKER
value|0x0301
end_define

begin_define
define|#
directive|define
name|UATO_HEADPHONES
value|0x0302
end_define

begin_define
define|#
directive|define
name|UATO_DISPLAYAUDIO
value|0x0303
end_define

begin_define
define|#
directive|define
name|UATO_DESKTOPSPEAKER
value|0x0304
end_define

begin_define
define|#
directive|define
name|UATO_ROOMSPEAKER
value|0x0305
end_define

begin_define
define|#
directive|define
name|UATO_COMMSPEAKER
value|0x0306
end_define

begin_define
define|#
directive|define
name|UATO_SUBWOOFER
value|0x0307
end_define

begin_comment
comment|/* bidir terminal types */
end_comment

begin_define
define|#
directive|define
name|UATB_UNDEFINED
value|0x0400
end_define

begin_define
define|#
directive|define
name|UATB_HANDSET
value|0x0401
end_define

begin_define
define|#
directive|define
name|UATB_HEADSET
value|0x0402
end_define

begin_define
define|#
directive|define
name|UATB_SPEAKERPHONE
value|0x0403
end_define

begin_define
define|#
directive|define
name|UATB_SPEAKERPHONEESUP
value|0x0404
end_define

begin_define
define|#
directive|define
name|UATB_SPEAKERPHONEECANC
value|0x0405
end_define

begin_comment
comment|/* telephony terminal types */
end_comment

begin_define
define|#
directive|define
name|UATT_UNDEFINED
value|0x0500
end_define

begin_define
define|#
directive|define
name|UATT_PHONELINE
value|0x0501
end_define

begin_define
define|#
directive|define
name|UATT_TELEPHONE
value|0x0502
end_define

begin_define
define|#
directive|define
name|UATT_DOWNLINEPHONE
value|0x0503
end_define

begin_comment
comment|/* external terminal types */
end_comment

begin_define
define|#
directive|define
name|UATE_UNDEFINED
value|0x0600
end_define

begin_define
define|#
directive|define
name|UATE_ANALOGCONN
value|0x0601
end_define

begin_define
define|#
directive|define
name|UATE_DIGITALAUIFC
value|0x0602
end_define

begin_define
define|#
directive|define
name|UATE_LINECONN
value|0x0603
end_define

begin_define
define|#
directive|define
name|UATE_LEGACYCONN
value|0x0604
end_define

begin_define
define|#
directive|define
name|UATE_SPDIF
value|0x0605
end_define

begin_define
define|#
directive|define
name|UATE_1394DA
value|0x0606
end_define

begin_define
define|#
directive|define
name|UATE_1394DV
value|0x0607
end_define

begin_comment
comment|/* embedded function terminal types */
end_comment

begin_define
define|#
directive|define
name|UATF_UNDEFINED
value|0x0700
end_define

begin_define
define|#
directive|define
name|UATF_CALIBNOISE
value|0x0701
end_define

begin_define
define|#
directive|define
name|UATF_EQUNOISE
value|0x0702
end_define

begin_define
define|#
directive|define
name|UATF_CDPLAYER
value|0x0703
end_define

begin_define
define|#
directive|define
name|UATF_DAT
value|0x0704
end_define

begin_define
define|#
directive|define
name|UATF_DCC
value|0x0705
end_define

begin_define
define|#
directive|define
name|UATF_MINIDISK
value|0x0706
end_define

begin_define
define|#
directive|define
name|UATF_ANALOGTAPE
value|0x0707
end_define

begin_define
define|#
directive|define
name|UATF_PHONOGRAPH
value|0x0708
end_define

begin_define
define|#
directive|define
name|UATF_VCRAUDIO
value|0x0709
end_define

begin_define
define|#
directive|define
name|UATF_VIDEODISCAUDIO
value|0x070a
end_define

begin_define
define|#
directive|define
name|UATF_DVDAUDIO
value|0x070b
end_define

begin_define
define|#
directive|define
name|UATF_TVTUNERAUDIO
value|0x070c
end_define

begin_define
define|#
directive|define
name|UATF_SATELLITE
value|0x070d
end_define

begin_define
define|#
directive|define
name|UATF_CABLETUNER
value|0x070e
end_define

begin_define
define|#
directive|define
name|UATF_DSS
value|0x070f
end_define

begin_define
define|#
directive|define
name|UATF_RADIORECV
value|0x0710
end_define

begin_define
define|#
directive|define
name|UATF_RADIOXMIT
value|0x0711
end_define

begin_define
define|#
directive|define
name|UATF_MULTITRACK
value|0x0712
end_define

begin_define
define|#
directive|define
name|UATF_SYNTHESIZER
value|0x0713
end_define

begin_define
define|#
directive|define
name|SET_CUR
value|0x01
end_define

begin_define
define|#
directive|define
name|GET_CUR
value|0x81
end_define

begin_define
define|#
directive|define
name|SET_MIN
value|0x02
end_define

begin_define
define|#
directive|define
name|GET_MIN
value|0x82
end_define

begin_define
define|#
directive|define
name|SET_MAX
value|0x03
end_define

begin_define
define|#
directive|define
name|GET_MAX
value|0x83
end_define

begin_define
define|#
directive|define
name|SET_RES
value|0x04
end_define

begin_define
define|#
directive|define
name|GET_RES
value|0x84
end_define

begin_define
define|#
directive|define
name|SET_MEM
value|0x05
end_define

begin_define
define|#
directive|define
name|GET_MEM
value|0x85
end_define

begin_define
define|#
directive|define
name|GET_STAT
value|0xff
end_define

begin_define
define|#
directive|define
name|MUTE_CONTROL
value|0x01
end_define

begin_define
define|#
directive|define
name|VOLUME_CONTROL
value|0x02
end_define

begin_define
define|#
directive|define
name|BASS_CONTROL
value|0x03
end_define

begin_define
define|#
directive|define
name|MID_CONTROL
value|0x04
end_define

begin_define
define|#
directive|define
name|TREBLE_CONTROL
value|0x05
end_define

begin_define
define|#
directive|define
name|GRAPHIC_EQUALIZER_CONTROL
value|0x06
end_define

begin_define
define|#
directive|define
name|AGC_CONTROL
value|0x07
end_define

begin_define
define|#
directive|define
name|DELAY_CONTROL
value|0x08
end_define

begin_define
define|#
directive|define
name|BASS_BOOST_CONTROL
value|0x09
end_define

begin_define
define|#
directive|define
name|LOUDNESS_CONTROL
value|0x0a
end_define

begin_define
define|#
directive|define
name|FU_MASK
parameter_list|(
name|u
parameter_list|)
value|(1<< ((u)-1))
end_define

begin_define
define|#
directive|define
name|MASTER_CHAN
value|0
end_define

begin_define
define|#
directive|define
name|AS_GENERAL
value|1
end_define

begin_define
define|#
directive|define
name|FORMAT_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|FORMAT_SPECIFIC
value|3
end_define

begin_define
define|#
directive|define
name|UA_FMT_PCM
value|1
end_define

begin_define
define|#
directive|define
name|UA_FMT_PCM8
value|2
end_define

begin_define
define|#
directive|define
name|UA_FMT_IEEE_FLOAT
value|3
end_define

begin_define
define|#
directive|define
name|UA_FMT_ALAW
value|4
end_define

begin_define
define|#
directive|define
name|UA_FMT_MULAW
value|5
end_define

begin_define
define|#
directive|define
name|UA_FMT_MPEG
value|0x1001
end_define

begin_define
define|#
directive|define
name|UA_FMT_AC3
value|0x1002
end_define

begin_define
define|#
directive|define
name|SAMPLING_FREQ_CONTROL
value|0x01
end_define

begin_define
define|#
directive|define
name|PITCH_CONTROL
value|0x02
end_define

begin_define
define|#
directive|define
name|FORMAT_TYPE_UNDEFINED
value|0
end_define

begin_define
define|#
directive|define
name|FORMAT_TYPE_I
value|1
end_define

begin_define
define|#
directive|define
name|FORMAT_TYPE_II
value|2
end_define

begin_define
define|#
directive|define
name|FORMAT_TYPE_III
value|3
end_define

begin_define
define|#
directive|define
name|UA_PROC_MASK
parameter_list|(
name|n
parameter_list|)
value|(1<< ((n)-1))
end_define

begin_define
define|#
directive|define
name|PROCESS_UNDEFINED
value|0
end_define

begin_define
define|#
directive|define
name|XX_ENABLE_CONTROL
value|1
end_define

begin_define
define|#
directive|define
name|UPDOWNMIX_PROCESS
value|1
end_define

begin_define
define|#
directive|define
name|UD_ENABLE_CONTROL
value|1
end_define

begin_define
define|#
directive|define
name|UD_MODE_SELECT_CONTROL
value|2
end_define

begin_define
define|#
directive|define
name|DOLBY_PROLOGIC_PROCESS
value|2
end_define

begin_define
define|#
directive|define
name|DP_ENABLE_CONTROL
value|1
end_define

begin_define
define|#
directive|define
name|DP_MODE_SELECT_CONTROL
value|2
end_define

begin_define
define|#
directive|define
name|P3D_STEREO_EXTENDER_PROCESS
value|3
end_define

begin_define
define|#
directive|define
name|P3D_ENABLE_CONTROL
value|1
end_define

begin_define
define|#
directive|define
name|P3D_SPACIOUSNESS_CONTROL
value|2
end_define

begin_define
define|#
directive|define
name|REVERBATION_PROCESS
value|4
end_define

begin_define
define|#
directive|define
name|RV_ENABLE_CONTROL
value|1
end_define

begin_define
define|#
directive|define
name|RV_LEVEL_CONTROL
value|2
end_define

begin_define
define|#
directive|define
name|RV_TIME_CONTROL
value|3
end_define

begin_define
define|#
directive|define
name|RV_FEEDBACK_CONTROL
value|4
end_define

begin_define
define|#
directive|define
name|CHORUS_PROCESS
value|5
end_define

begin_define
define|#
directive|define
name|CH_ENABLE_CONTROL
value|1
end_define

begin_define
define|#
directive|define
name|CH_LEVEL_CONTROL
value|2
end_define

begin_define
define|#
directive|define
name|CH_RATE_CONTROL
value|3
end_define

begin_define
define|#
directive|define
name|CH_DEPTH_CONTROL
value|4
end_define

begin_define
define|#
directive|define
name|DYN_RANGE_COMP_PROCESS
value|6
end_define

begin_define
define|#
directive|define
name|DR_ENABLE_CONTROL
value|1
end_define

begin_define
define|#
directive|define
name|DR_COMPRESSION_RATE_CONTROL
value|2
end_define

begin_define
define|#
directive|define
name|DR_MAXAMPL_CONTROL
value|3
end_define

begin_define
define|#
directive|define
name|DR_THRESHOLD_CONTROL
value|4
end_define

begin_define
define|#
directive|define
name|DR_ATTACK_TIME_CONTROL
value|5
end_define

begin_define
define|#
directive|define
name|DR_RELEASE_TIME_CONTROL
value|6
end_define

end_unit

