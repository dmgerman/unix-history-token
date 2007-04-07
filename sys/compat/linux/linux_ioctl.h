begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_IOCTL_H_
end_define

begin_comment
comment|/*  * disk  */
end_comment

begin_define
define|#
directive|define
name|LINUX_BLKROSET
value|0x125d
end_define

begin_define
define|#
directive|define
name|LINUX_BLKROGET
value|0x125e
end_define

begin_define
define|#
directive|define
name|LINUX_BLKRRPART
value|0x125f
end_define

begin_define
define|#
directive|define
name|LINUX_BLKGETSIZE
value|0x1260
end_define

begin_define
define|#
directive|define
name|LINUX_BLKFLSBUF
value|0x1261
end_define

begin_define
define|#
directive|define
name|LINUX_BLKRASET
value|0x1262
end_define

begin_define
define|#
directive|define
name|LINUX_BLKRAGET
value|0x1263
end_define

begin_define
define|#
directive|define
name|LINUX_BLKFRASET
value|0x1264
end_define

begin_define
define|#
directive|define
name|LINUX_BLKFRAGET
value|0x1265
end_define

begin_define
define|#
directive|define
name|LINUX_BLKSECTSET
value|0x1266
end_define

begin_define
define|#
directive|define
name|LINUX_BLKSECTGET
value|0x1267
end_define

begin_define
define|#
directive|define
name|LINUX_BLKSSZGET
value|0x1268
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_DISK_MIN
value|LINUX_BLKROSET
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_DISK_MAX
value|LINUX_BLKSSZGET
end_define

begin_comment
comment|/*  * hdio  */
end_comment

begin_define
define|#
directive|define
name|LINUX_HDIO_GET_GEO
value|0x0301
end_define

begin_define
define|#
directive|define
name|LINUX_HDIO_GET_IDENTITY
value|0x030D
end_define

begin_comment
comment|/* not yet implemented */
end_comment

begin_define
define|#
directive|define
name|LINUX_HDIO_GET_GEO_BIG
value|0x0330
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_HDIO_MIN
value|LINUX_HDIO_GET_GEO
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_HDIO_MAX
value|LINUX_HDIO_GET_GEO_BIG
end_define

begin_comment
comment|/*  * cdrom  */
end_comment

begin_define
define|#
directive|define
name|LINUX_CDROMPAUSE
value|0x5301
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMRESUME
value|0x5302
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMPLAYMSF
value|0x5303
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMPLAYTRKIND
value|0x5304
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMREADTOCHDR
value|0x5305
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMREADTOCENTRY
value|0x5306
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMSTOP
value|0x5307
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMSTART
value|0x5308
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMEJECT
value|0x5309
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMVOLCTRL
value|0x530a
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMSUBCHNL
value|0x530b
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMREADMODE2
value|0x530c
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMREADMODE1
value|0x530d
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMREADAUDIO
value|0x530e
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMEJECT_SW
value|0x530f
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMMULTISESSION
value|0x5310
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_GET_UPC
value|0x5311
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMRESET
value|0x5312
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMVOLREAD
value|0x5313
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMREADRAW
value|0x5314
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMREADCOOKED
value|0x5315
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMSEEK
value|0x5316
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMPLAYBLK
value|0x5317
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMREADALL
value|0x5318
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMCLOSETRAY
value|0x5319
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMLOADFROMSLOT
value|0x531a
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMGETSPINDOWN
value|0x531d
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMSETSPINDOWN
value|0x531e
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_SET_OPTIONS
value|0x5320
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_CLEAR_OPTIONS
value|0x5321
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_SELECT_SPEED
value|0x5322
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_SELECT_DISC
value|0x5323
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_MEDIA_CHANGED
value|0x5325
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_DRIVE_STATUS
value|0x5326
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_DISC_STATUS
value|0x5327
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_CHANGER_NSLOTS
value|0x5328
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_LOCKDOOR
value|0x5329
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_DEBUG
value|0x5330
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_GET_CAPABILITY
value|0x5331
end_define

begin_define
define|#
directive|define
name|LINUX_CDROMAUDIOBUFSIZ
value|0x5382
end_define

begin_define
define|#
directive|define
name|LINUX_SCSI_GET_IDLUN
value|0x5382
end_define

begin_define
define|#
directive|define
name|LINUX_SCSI_GET_BUS_NUMBER
value|0x5386
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_READ_STRUCT
value|0x5390
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_WRITE_STRUCT
value|0x5391
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_AUTH
value|0x5392
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_SEND_PACKET
value|0x5393
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_NEXT_WRITABLE
value|0x5394
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_LAST_WRITTEN
value|0x5395
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_CDROM_MIN
value|LINUX_CDROMPAUSE
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_CDROM_MAX
value|LINUX_CDROM_LAST_WRITTEN
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_LBA
value|0x01
end_define

begin_define
define|#
directive|define
name|LINUX_CDROM_MSF
value|0x02
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_LU_SEND_AGID
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_HOST_SEND_CHALLENGE
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_LU_SEND_KEY1
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_LU_SEND_CHALLENGE
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_HOST_SEND_KEY2
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_AUTH_ESTABLISHED
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_AUTH_FAILURE
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_LU_SEND_TITLE_KEY
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_LU_SEND_ASF
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_INVALIDATE_AGID
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_LU_SEND_RPC_STATE
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_DVD_HOST_SEND_RPC_STATE
value|11
end_define

begin_comment
comment|/*  * SG  */
end_comment

begin_define
define|#
directive|define
name|LINUX_SG_SET_TIMEOUT
value|0x2201
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_TIMEOUT
value|0x2202
end_define

begin_define
define|#
directive|define
name|LINUX_SG_EMULATED_HOST
value|0x2203
end_define

begin_define
define|#
directive|define
name|LINUX_SG_SET_TRANSFORM
value|0x2204
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_TRANSFORM
value|0x2205
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_COMMAND_Q
value|0x2270
end_define

begin_define
define|#
directive|define
name|LINUX_SG_SET_COMMAND_Q
value|0x2271
end_define

begin_define
define|#
directive|define
name|LINUX_SG_SET_RESERVED_SIZE
value|0x2275
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_RESERVED_SIZE
value|0x2272
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_SCSI_ID
value|0x2276
end_define

begin_define
define|#
directive|define
name|LINUX_SG_SET_FORCE_LOW_DMA
value|0x2279
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_LOW_DMA
value|0x227a
end_define

begin_define
define|#
directive|define
name|LINUX_SG_SET_FORCE_PACK_ID
value|0x227b
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_PACK_ID
value|0x227c
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_NUM_WAITING
value|0x227d
end_define

begin_define
define|#
directive|define
name|LINUX_SG_SET_DEBUG
value|0x227e
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_SG_TABLESIZE
value|0x227f
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_VERSION_NUM
value|0x2282
end_define

begin_define
define|#
directive|define
name|LINUX_SG_NEXT_CMD_LEN
value|0x2283
end_define

begin_define
define|#
directive|define
name|LINUX_SG_SCSI_RESET
value|0x2284
end_define

begin_define
define|#
directive|define
name|LINUX_SG_IO
value|0x2285
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_REQUEST_TABLE
value|0x2286
end_define

begin_define
define|#
directive|define
name|LINUX_SG_SET_KEEP_ORPHAN
value|0x2287
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_KEEP_ORPHAN
value|0x2288
end_define

begin_define
define|#
directive|define
name|LINUX_SG_GET_ACCESS_COUNT
value|0x2289
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_SG_MIN
value|0x2200
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_SG_MAX
value|0x22ff
end_define

begin_comment
comment|/*  * VFAT  */
end_comment

begin_define
define|#
directive|define
name|LINUX_VFAT_READDIR_BOTH
value|0x7201
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_VFAT_MIN
value|LINUX_VFAT_READDIR_BOTH
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_VFAT_MAX
value|LINUX_VFAT_READDIR_BOTH
end_define

begin_comment
comment|/*  * console  */
end_comment

begin_define
define|#
directive|define
name|LINUX_KIOCSOUND
value|0x4B2F
end_define

begin_define
define|#
directive|define
name|LINUX_KDMKTONE
value|0x4B30
end_define

begin_define
define|#
directive|define
name|LINUX_KDGETLED
value|0x4B31
end_define

begin_define
define|#
directive|define
name|LINUX_KDSETLED
value|0x4B32
end_define

begin_define
define|#
directive|define
name|LINUX_KDSETMODE
value|0x4B3A
end_define

begin_define
define|#
directive|define
name|LINUX_KDGETMODE
value|0x4B3B
end_define

begin_define
define|#
directive|define
name|LINUX_KDGKBMODE
value|0x4B44
end_define

begin_define
define|#
directive|define
name|LINUX_KDSKBMODE
value|0x4B45
end_define

begin_define
define|#
directive|define
name|LINUX_VT_OPENQRY
value|0x5600
end_define

begin_define
define|#
directive|define
name|LINUX_VT_GETMODE
value|0x5601
end_define

begin_define
define|#
directive|define
name|LINUX_VT_SETMODE
value|0x5602
end_define

begin_define
define|#
directive|define
name|LINUX_VT_GETSTATE
value|0x5603
end_define

begin_define
define|#
directive|define
name|LINUX_VT_RELDISP
value|0x5605
end_define

begin_define
define|#
directive|define
name|LINUX_VT_ACTIVATE
value|0x5606
end_define

begin_define
define|#
directive|define
name|LINUX_VT_WAITACTIVE
value|0x5607
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_CONSOLE_MIN
value|LINUX_KIOCSOUND
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_CONSOLE_MAX
value|LINUX_VT_WAITACTIVE
end_define

begin_define
define|#
directive|define
name|LINUX_LED_SCR
value|0x01
end_define

begin_define
define|#
directive|define
name|LINUX_LED_NUM
value|0x02
end_define

begin_define
define|#
directive|define
name|LINUX_LED_CAP
value|0x04
end_define

begin_define
define|#
directive|define
name|LINUX_KD_TEXT
value|0x0
end_define

begin_define
define|#
directive|define
name|LINUX_KD_GRAPHICS
value|0x1
end_define

begin_define
define|#
directive|define
name|LINUX_KD_TEXT0
value|0x2
end_define

begin_define
define|#
directive|define
name|LINUX_KD_TEXT1
value|0x3
end_define

begin_define
define|#
directive|define
name|LINUX_KBD_RAW
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_KBD_XLATE
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_KBD_MEDIUMRAW
value|2
end_define

begin_comment
comment|/*  * socket  */
end_comment

begin_define
define|#
directive|define
name|LINUX_FIOSETOWN
value|0x8901
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCSPGRP
value|0x8902
end_define

begin_define
define|#
directive|define
name|LINUX_FIOGETOWN
value|0x8903
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCGPGRP
value|0x8904
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCATMARK
value|0x8905
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCGSTAMP
value|0x8906
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCGIFCONF
value|0x8912
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCGIFFLAGS
value|0x8913
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCGIFADDR
value|0x8915
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCSIFADDR
value|0x8916
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCGIFDSTADDR
value|0x8917
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCGIFBRDADDR
value|0x8919
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCGIFNETMASK
value|0x891b
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCSIFNETMASK
value|0x891c
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCGIFMTU
value|0x8921
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCSIFMTU
value|0x8922
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCSIFNAME
value|0x8923
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCSIFHWADDR
value|0x8924
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCGIFHWADDR
value|0x8927
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCADDMULTI
value|0x8931
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCDELMULTI
value|0x8932
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_SOCKET_MIN
value|LINUX_FIOSETOWN
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_SOCKET_MAX
value|LINUX_SIOCDELMULTI
end_define

begin_comment
comment|/*  * Device private ioctl calls   */
end_comment

begin_define
define|#
directive|define
name|LINUX_SIOCDEVPRIVATE
value|0x89F0
end_define

begin_comment
comment|/* to 89FF */
end_comment

begin_define
define|#
directive|define
name|LINUX_IOCTL_PRIVATE_MIN
value|LINUX_SIOCDEVPRIVATE
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_PRIVATE_MAX
value|LINUX_SIOCDEVPRIVATE+0xf
end_define

begin_comment
comment|/*  * sound  */
end_comment

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_VOLUME
value|0x4d00
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_BASS
value|0x4d01
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_TREBLE
value|0x4d02
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_SYNTH
value|0x4d03
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_PCM
value|0x4d04
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_SPEAKER
value|0x4d05
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_LINE
value|0x4d06
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_MIC
value|0x4d07
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_CD
value|0x4d08
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_IMIX
value|0x4d09
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_ALTPCM
value|0x4d0A
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_RECLEV
value|0x4d0B
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_IGAIN
value|0x4d0C
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_OGAIN
value|0x4d0D
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_LINE1
value|0x4d0E
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_LINE2
value|0x4d0F
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_LINE3
value|0x4d10
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_INFO
value|0x4d65
end_define

begin_define
define|#
directive|define
name|LINUX_OSS_GETVERSION
value|0x4d76
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_READ_STEREODEVS
value|0x4dfb
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_READ_RECMASK
value|0x4dfd
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_READ_DEVMASK
value|0x4dfe
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_MIXER_WRITE_RECSRC
value|0x4dff
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_RESET
value|0x5000
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_SYNC
value|0x5001
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_SPEED
value|0x5002
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_STEREO
value|0x5003
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_GETBLKSIZE
value|0x5004
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_SETBLKSIZE
value|LINUX_SNDCTL_DSP_GETBLKSIZE
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_SETFMT
value|0x5005
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_PCM_WRITE_CHANNELS
value|0x5006
end_define

begin_define
define|#
directive|define
name|LINUX_SOUND_PCM_WRITE_FILTER
value|0x5007
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_POST
value|0x5008
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_SUBDIVIDE
value|0x5009
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_SETFRAGMENT
value|0x500A
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_GETFMTS
value|0x500B
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_GETOSPACE
value|0x500C
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_GETISPACE
value|0x500D
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_NONBLOCK
value|0x500E
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_GETCAPS
value|0x500F
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_GETTRIGGER
value|0x5010
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_SETTRIGGER
value|LINUX_SNDCTL_DSP_GETTRIGGER
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_GETIPTR
value|0x5011
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_GETOPTR
value|0x5012
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_SETDUPLEX
value|0x5016
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_DSP_GETODELAY
value|0x5017
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SEQ_RESET
value|0x5100
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SEQ_SYNC
value|0x5101
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SYNTH_INFO
value|0x5102
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SEQ_CTRLRATE
value|0x5103
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SEQ_GETOUTCOUNT
value|0x5104
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SEQ_GETINCOUNT
value|0x5105
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SEQ_PERCMODE
value|0x5106
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_FM_LOAD_INSTR
value|0x5107
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SEQ_TESTMIDI
value|0x5108
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SEQ_RESETSAMPLES
value|0x5109
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SEQ_NRSYNTHS
value|0x510A
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SEQ_NRMIDIS
value|0x510B
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_MIDI_INFO
value|0x510C
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SEQ_TRESHOLD
value|0x510D
end_define

begin_define
define|#
directive|define
name|LINUX_SNDCTL_SYNTH_MEMAVL
value|0x510E
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_SOUND_MIN
value|LINUX_SOUND_MIXER_WRITE_VOLUME
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_SOUND_MAX
value|LINUX_SNDCTL_SYNTH_MEMAVL
end_define

begin_comment
comment|/*  * termio  */
end_comment

begin_define
define|#
directive|define
name|LINUX_TCGETS
value|0x5401
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETS
value|0x5402
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETSW
value|0x5403
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETSF
value|0x5404
end_define

begin_define
define|#
directive|define
name|LINUX_TCGETA
value|0x5405
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETA
value|0x5406
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETAW
value|0x5407
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETAF
value|0x5408
end_define

begin_define
define|#
directive|define
name|LINUX_TCSBRK
value|0x5409
end_define

begin_define
define|#
directive|define
name|LINUX_TCXONC
value|0x540A
end_define

begin_define
define|#
directive|define
name|LINUX_TCFLSH
value|0x540B
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCEXCL
value|0x540C
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCNXCL
value|0x540D
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSCTTY
value|0x540E
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGPGRP
value|0x540F
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSPGRP
value|0x5410
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCOUTQ
value|0x5411
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSTI
value|0x5412
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGWINSZ
value|0x5413
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSWINSZ
value|0x5414
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCMGET
value|0x5415
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCMBIS
value|0x5416
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCMBIC
value|0x5417
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCMSET
value|0x5418
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGSOFTCAR
value|0x5419
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSSOFTCAR
value|0x541A
end_define

begin_define
define|#
directive|define
name|LINUX_FIONREAD
value|0x541B
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCINQ
value|FIONREAD
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCLINUX
value|0x541C
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCCONS
value|0x541D
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGSERIAL
value|0x541E
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSSERIAL
value|0x541F
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCPKT
value|0x5420
end_define

begin_define
define|#
directive|define
name|LINUX_FIONBIO
value|0x5421
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCNOTTY
value|0x5422
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSETD
value|0x5423
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGETD
value|0x5424
end_define

begin_define
define|#
directive|define
name|LINUX_TCSBRKP
value|0x5425
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCTTYGSTRUCT
value|0x5426
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSBRK
value|0x5427
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCCBRK
value|0x5428
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGPTN
value|0x5430
end_define

begin_define
define|#
directive|define
name|LINUX_FIONCLEX
value|0x5450
end_define

begin_define
define|#
directive|define
name|LINUX_FIOCLEX
value|0x5451
end_define

begin_define
define|#
directive|define
name|LINUX_FIOASYNC
value|0x5452
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSERCONFIG
value|0x5453
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSERGWILD
value|0x5454
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSERSWILD
value|0x5455
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGLCKTRMIOS
value|0x5456
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSLCKTRMIOS
value|0x5457
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_TERMIO_MIN
value|LINUX_TCGETS
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_TERMIO_MAX
value|LINUX_TIOCSLCKTRMIOS
end_define

begin_comment
comment|/* arguments for tcflow() and LINUX_TCXONC */
end_comment

begin_define
define|#
directive|define
name|LINUX_TCOOFF
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_TCOON
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_TCIOFF
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_TCION
value|3
end_define

begin_comment
comment|/* arguments for tcflush() and LINUX_TCFLSH */
end_comment

begin_define
define|#
directive|define
name|LINUX_TCIFLUSH
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_TCOFLUSH
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_TCIOFLUSH
value|2
end_define

begin_comment
comment|/* line disciplines */
end_comment

begin_define
define|#
directive|define
name|LINUX_N_TTY
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_N_SLIP
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_N_MOUSE
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_N_PPP
value|3
end_define

begin_comment
comment|/* Linux termio c_cc values */
end_comment

begin_define
define|#
directive|define
name|LINUX_VINTR
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_VQUIT
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_VERASE
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_VKILL
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_VEOF
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_VTIME
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_VMIN
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_VSWTC
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_NCC
value|8
end_define

begin_comment
comment|/* Linux termios c_cc values */
end_comment

begin_comment
comment|/* In addition to the termio values */
end_comment

begin_define
define|#
directive|define
name|LINUX_VSTART
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_VSTOP
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_VSUSP
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_VEOL
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_VREPRINT
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_VDISCARD
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_VWERASE
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_VLNEXT
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_VEOL2
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_NCCS
value|19
end_define

begin_define
define|#
directive|define
name|LINUX_POSIX_VDISABLE
value|'\0'
end_define

begin_comment
comment|/* Linux c_iflag masks */
end_comment

begin_define
define|#
directive|define
name|LINUX_IGNBRK
value|0x0000001
end_define

begin_define
define|#
directive|define
name|LINUX_BRKINT
value|0x0000002
end_define

begin_define
define|#
directive|define
name|LINUX_IGNPAR
value|0x0000004
end_define

begin_define
define|#
directive|define
name|LINUX_PARMRK
value|0x0000008
end_define

begin_define
define|#
directive|define
name|LINUX_INPCK
value|0x0000010
end_define

begin_define
define|#
directive|define
name|LINUX_ISTRIP
value|0x0000020
end_define

begin_define
define|#
directive|define
name|LINUX_INLCR
value|0x0000040
end_define

begin_define
define|#
directive|define
name|LINUX_IGNCR
value|0x0000080
end_define

begin_define
define|#
directive|define
name|LINUX_ICRNL
value|0x0000100
end_define

begin_define
define|#
directive|define
name|LINUX_IUCLC
value|0x0000200
end_define

begin_define
define|#
directive|define
name|LINUX_IXON
value|0x0000400
end_define

begin_define
define|#
directive|define
name|LINUX_IXANY
value|0x0000800
end_define

begin_define
define|#
directive|define
name|LINUX_IXOFF
value|0x0001000
end_define

begin_define
define|#
directive|define
name|LINUX_IMAXBEL
value|0x0002000
end_define

begin_comment
comment|/* Linux c_oflag masks */
end_comment

begin_define
define|#
directive|define
name|LINUX_OPOST
value|0x0000001
end_define

begin_define
define|#
directive|define
name|LINUX_OLCUC
value|0x0000002
end_define

begin_define
define|#
directive|define
name|LINUX_ONLCR
value|0x0000004
end_define

begin_define
define|#
directive|define
name|LINUX_OCRNL
value|0x0000008
end_define

begin_define
define|#
directive|define
name|LINUX_ONOCR
value|0x0000010
end_define

begin_define
define|#
directive|define
name|LINUX_ONLRET
value|0x0000020
end_define

begin_define
define|#
directive|define
name|LINUX_OFILL
value|0x0000040
end_define

begin_define
define|#
directive|define
name|LINUX_OFDEL
value|0x0000080
end_define

begin_define
define|#
directive|define
name|LINUX_NLDLY
value|0x0000100
end_define

begin_define
define|#
directive|define
name|LINUX_NL0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_NL1
value|0x0000100
end_define

begin_define
define|#
directive|define
name|LINUX_CRDLY
value|0x0000600
end_define

begin_define
define|#
directive|define
name|LINUX_CR0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_CR1
value|0x0000200
end_define

begin_define
define|#
directive|define
name|LINUX_CR2
value|0x0000400
end_define

begin_define
define|#
directive|define
name|LINUX_CR3
value|0x0000600
end_define

begin_define
define|#
directive|define
name|LINUX_TABDLY
value|0x0001800
end_define

begin_define
define|#
directive|define
name|LINUX_TAB0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_TAB1
value|0x0000800
end_define

begin_define
define|#
directive|define
name|LINUX_TAB2
value|0x0001000
end_define

begin_define
define|#
directive|define
name|LINUX_TAB3
value|0x0001800
end_define

begin_define
define|#
directive|define
name|LINUX_XTABS
value|0x0001800
end_define

begin_define
define|#
directive|define
name|LINUX_BSDLY
value|0x0002000
end_define

begin_define
define|#
directive|define
name|LINUX_BS0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_BS1
value|0x0002000
end_define

begin_define
define|#
directive|define
name|LINUX_VTDLY
value|0x0004000
end_define

begin_define
define|#
directive|define
name|LINUX_VT0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_VT1
value|0x0004000
end_define

begin_define
define|#
directive|define
name|LINUX_FFDLY
value|0x0008000
end_define

begin_define
define|#
directive|define
name|LINUX_FF0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_FF1
value|0x0008000
end_define

begin_define
define|#
directive|define
name|LINUX_CBAUD
value|0x0000100f
end_define

begin_define
define|#
directive|define
name|LINUX_B0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|LINUX_B50
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LINUX_B75
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LINUX_B110
value|0x00000003
end_define

begin_define
define|#
directive|define
name|LINUX_B134
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LINUX_B150
value|0x00000005
end_define

begin_define
define|#
directive|define
name|LINUX_B200
value|0x00000006
end_define

begin_define
define|#
directive|define
name|LINUX_B300
value|0x00000007
end_define

begin_define
define|#
directive|define
name|LINUX_B600
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LINUX_B1200
value|0x00000009
end_define

begin_define
define|#
directive|define
name|LINUX_B1800
value|0x0000000a
end_define

begin_define
define|#
directive|define
name|LINUX_B2400
value|0x0000000b
end_define

begin_define
define|#
directive|define
name|LINUX_B4800
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|LINUX_B9600
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|LINUX_B19200
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|LINUX_B38400
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|LINUX_EXTA
value|LINUX_B19200
end_define

begin_define
define|#
directive|define
name|LINUX_EXTB
value|LINUX_B38400
end_define

begin_define
define|#
directive|define
name|LINUX_CBAUDEX
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LINUX_B57600
value|0x00001001
end_define

begin_define
define|#
directive|define
name|LINUX_B115200
value|0x00001002
end_define

begin_define
define|#
directive|define
name|LINUX_CSIZE
value|0x00000030
end_define

begin_define
define|#
directive|define
name|LINUX_CS5
value|0x00000000
end_define

begin_define
define|#
directive|define
name|LINUX_CS6
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LINUX_CS7
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LINUX_CS8
value|0x00000030
end_define

begin_define
define|#
directive|define
name|LINUX_CSTOPB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LINUX_CREAD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|LINUX_PARENB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LINUX_PARODD
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LINUX_HUPCL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCAL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LINUX_CRTSCTS
value|0x80000000
end_define

begin_comment
comment|/* Linux c_lflag masks */
end_comment

begin_define
define|#
directive|define
name|LINUX_ISIG
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LINUX_ICANON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LINUX_XCASE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LINUX_ECHO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LINUX_ECHOE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LINUX_ECHOK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LINUX_ECHONL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LINUX_NOFLSH
value|0x00000080
end_define

begin_define
define|#
directive|define
name|LINUX_TOSTOP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LINUX_ECHOCTL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LINUX_ECHOPRT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LINUX_ECHOKE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LINUX_FLUSHO
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LINUX_PENDIN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LINUX_IEXTEN
value|0x00008000
end_define

begin_comment
comment|/* serial_struct values for TIOC[GS]SERIAL ioctls */
end_comment

begin_define
define|#
directive|define
name|LINUX_ASYNC_CLOSING_WAIT_INF
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_CLOSING_WAIT_NONE
value|65535
end_define

begin_define
define|#
directive|define
name|LINUX_PORT_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_PORT_8250
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_PORT_16450
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_PORT_16550
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_PORT_16550A
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_PORT_CIRRUS
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_PORT_16650
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_PORT_MAX
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_HUP_NOTIFY
value|0x0001
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_FOURPORT
value|0x0002
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_SAK
value|0x0004
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_SPLIT_TERMIOS
value|0x0008
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_SPD_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_SPD_HI
value|0x0010
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_SPD_VHI
value|0x0020
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_SPD_CUST
value|0x0030
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_SKIP_TEST
value|0x0040
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_AUTO_IRQ
value|0x0080
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_SESSION_LOCKOUT
value|0x0100
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_PGRP_LOCKOUT
value|0x0200
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_CALLOUT_NOHUP
value|0x0400
end_define

begin_define
define|#
directive|define
name|LINUX_ASYNC_FLAGS
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_DRM_MIN
value|0x6400
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_DRM_MAX
value|0x64ff
end_define

begin_comment
comment|/*  * This doesn't really belong here, but I can't think of a better  * place to put it.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|linux_ifname
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LINUX_IOCTL_H_ */
end_comment

end_unit

