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
comment|/*  * ioctl  *  * XXX comments in Linux'<asm-generic/ioctl.h> indicate these  * could be arch-dependant...  */
end_comment

begin_define
define|#
directive|define
name|LINUX_IOC_VOID
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_IOC_IN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|LINUX_IOC_OUT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|LINUX_IOC_INOUT
value|(LINUX_IOC_IN|LINUX_IOC_OUT)
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
name|LINUX_SIOCGIFINDEX
value|0x8933
end_define

begin_define
define|#
directive|define
name|LINUX_SIOGIFINDEX
value|LINUX_SIOCGIFINDEX
end_define

begin_define
define|#
directive|define
name|LINUX_SIOCGIFCOUNT
value|0x8938
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
value|LINUX_SIOCGIFCOUNT
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
name|LINUX_SOUND_MIXER_READ_CAPS
value|0x4dfc
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
name|LINUX_TIOCSPTLCK
value|0x5431
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
comment|/*  * video  */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOCGCAP
value|0x7601
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGCHAN
value|0x7602
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSCHAN
value|0x7603
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGTUNER
value|0x7604
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSTUNER
value|0x7605
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGPICT
value|0x7606
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSPICT
value|0x7607
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCCAPTURE
value|0x7608
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGWIN
value|0x7609
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSWIN
value|0x760a
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGFBUF
value|0x760b
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSFBUF
value|0x760c
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCKEY
value|0x760d
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGFREQ
value|0x760e
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSFREQ
value|0x760f
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGAUDIO
value|0x7610
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSAUDIO
value|0x7611
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSYNC
value|0x7623
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCMCAPTURE
value|0x7613
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGMBUF
value|0x7614
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGUNIT
value|0x7615
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGCAPTURE
value|0x7616
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSCAPTURE
value|0x7617
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSPLAYMODE
value|0x7618
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSWRITEMODE
value|0x7619
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGPLAYINFO
value|0x761a
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSMICROCODE
value|0x761b
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCGVBIFMT
value|0x761c
end_define

begin_define
define|#
directive|define
name|LINUX_VIDIOCSVBIFMT
value|0x761d
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_VIDEO_MIN
value|LINUX_VIDIOCGCAP
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_VIDEO_MAX
value|LINUX_VIDIOCSVBIFMT
end_define

begin_comment
comment|/* videodev2 aka V4L2 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_QUERYCAP
value|0x5600
end_define

begin_comment
comment|/* 0x80685600 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_RESERVED
value|0x5601
end_define

begin_comment
comment|/* 0x00005601 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_ENUM_FMT
value|0x5602
end_define

begin_comment
comment|/* 0xc0405602 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_FMT
value|0x5604
end_define

begin_comment
comment|/* 0xc0cc5604 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_FMT
value|0x5605
end_define

begin_comment
comment|/* 0xc0cc5605 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_REQBUFS
value|0x5608
end_define

begin_comment
comment|/* 0xc0145608 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_QUERYBUF
value|0x5609
end_define

begin_comment
comment|/* 0xc0445609 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_FBUF
value|0x560a
end_define

begin_comment
comment|/* 0x802c560a */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_FBUF
value|0x560b
end_define

begin_comment
comment|/* 0x402c560b */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_OVERLAY
value|0x560e
end_define

begin_comment
comment|/* 0x4004560e */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_QBUF
value|0x560f
end_define

begin_comment
comment|/* 0xc044560f */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_DQBUF
value|0x5611
end_define

begin_comment
comment|/* 0xc0445611 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_STREAMON
value|0x5612
end_define

begin_comment
comment|/* 0x40045612 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_STREAMOFF
value|0x5613
end_define

begin_comment
comment|/* 0x40045613 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_PARM
value|0x5615
end_define

begin_comment
comment|/* 0xc0cc5615 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_PARM
value|0x5616
end_define

begin_comment
comment|/* 0xc0cc5616 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_STD
value|0x5617
end_define

begin_comment
comment|/* 0x80085617 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_STD
value|0x5618
end_define

begin_comment
comment|/* 0x40085618 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_ENUMSTD
value|0x5619
end_define

begin_comment
comment|/* 0xc0405619 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_ENUMINPUT
value|0x561a
end_define

begin_comment
comment|/* 0xc04c561a */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_CTRL
value|0x561b
end_define

begin_comment
comment|/* 0xc008561b */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_CTRL
value|0x561c
end_define

begin_comment
comment|/* 0xc008561c */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_TUNER
value|0x561d
end_define

begin_comment
comment|/* 0xc054561d */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_TUNER
value|0x561e
end_define

begin_comment
comment|/* 0x4054561e */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_AUDIO
value|0x5621
end_define

begin_comment
comment|/* 0x80345621 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_AUDIO
value|0x5622
end_define

begin_comment
comment|/* 0x40345622 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_QUERYCTRL
value|0x5624
end_define

begin_comment
comment|/* 0xc0445624 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_QUERYMENU
value|0x5625
end_define

begin_comment
comment|/* 0xc02c5625 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_INPUT
value|0x5626
end_define

begin_comment
comment|/* 0x80045626 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_INPUT
value|0x5627
end_define

begin_comment
comment|/* 0xc0045627 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_OUTPUT
value|0x562e
end_define

begin_comment
comment|/* 0x8004562e */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_OUTPUT
value|0x562f
end_define

begin_comment
comment|/* 0xc004562f */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_ENUMOUTPUT
value|0x5630
end_define

begin_comment
comment|/* 0xc0485630 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_AUDOUT
value|0x5631
end_define

begin_comment
comment|/* 0x80345631 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_AUDOUT
value|0x5632
end_define

begin_comment
comment|/* 0x40345632 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_MODULATOR
value|0x5636
end_define

begin_comment
comment|/* 0xc0445636 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_MODULATOR
value|0x5637
end_define

begin_comment
comment|/* 0x40445637 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_FREQUENCY
value|0x5638
end_define

begin_comment
comment|/* 0xc02c5638 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_FREQUENCY
value|0x5639
end_define

begin_comment
comment|/* 0x402c5639 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_CROPCAP
value|0x563a
end_define

begin_comment
comment|/* 0xc02c563a */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_CROP
value|0x563b
end_define

begin_comment
comment|/* 0xc014563b */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_CROP
value|0x563c
end_define

begin_comment
comment|/* 0x4014563c */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_JPEGCOMP
value|0x563d
end_define

begin_comment
comment|/* 0x808c563d */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_JPEGCOMP
value|0x563e
end_define

begin_comment
comment|/* 0x408c563e */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_QUERYSTD
value|0x563f
end_define

begin_comment
comment|/* 0x8008563f */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_TRY_FMT
value|0x5640
end_define

begin_comment
comment|/* 0xc0cc5640 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_ENUMAUDIO
value|0x5641
end_define

begin_comment
comment|/* 0xc0345641 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_ENUMAUDOUT
value|0x5642
end_define

begin_comment
comment|/* 0xc0345642 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_PRIORITY
value|0x5643
end_define

begin_comment
comment|/* 0x80045643 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_PRIORITY
value|0x5644
end_define

begin_comment
comment|/* 0x40045644 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_SLICED_VBI_CAP
value|0x5645
end_define

begin_comment
comment|/* 0xc0745645 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_LOG_STATUS
value|0x5646
end_define

begin_comment
comment|/* 0x00005646 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_EXT_CTRLS
value|0x5647
end_define

begin_comment
comment|/* 0xc0185647 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_EXT_CTRLS
value|0x5648
end_define

begin_comment
comment|/* 0xc0185648 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_TRY_EXT_CTRLS
value|0x5649
end_define

begin_comment
comment|/* 0xc0185649 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_ENUM_FRAMESIZES
value|0x564a
end_define

begin_comment
comment|/* 0xc02c564a */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_ENUM_FRAMEINTERVALS
value|0x564b
end_define

begin_comment
comment|/* 0xc034564b */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_ENC_INDEX
value|0x564c
end_define

begin_comment
comment|/* 0x8818564c */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_ENCODER_CMD
value|0x564d
end_define

begin_comment
comment|/* 0xc028564d */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_TRY_ENCODER_CMD
value|0x564e
end_define

begin_comment
comment|/* 0xc028564e */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_DBG_S_REGISTER
value|0x564f
end_define

begin_comment
comment|/* 0x4038564f */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_DBG_G_REGISTER
value|0x5650
end_define

begin_comment
comment|/* 0xc0385650 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_DBG_G_CHIP_IDENT
value|0x5651
end_define

begin_comment
comment|/* 0xc02c5651 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_HW_FREQ_SEEK
value|0x5652
end_define

begin_comment
comment|/* 0x40305652 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_ENUM_DV_PRESETS
value|0x5653
end_define

begin_comment
comment|/* 0xc0405653 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_DV_PRESET
value|0x5654
end_define

begin_comment
comment|/* 0xc0145654 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_DV_PRESET
value|0x5655
end_define

begin_comment
comment|/* 0xc0145655 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_QUERY_DV_PRESET
value|0x5656
end_define

begin_comment
comment|/* 0x80145656 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_DV_TIMINGS
value|0x5657
end_define

begin_comment
comment|/* 0xc0845657 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_DV_TIMINGS
value|0x5658
end_define

begin_comment
comment|/* 0xc0845658 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_DQEVENT
value|0x5659
end_define

begin_comment
comment|/* 0x80785659 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_SUBSCRIBE_EVENT
value|0x565a
end_define

begin_comment
comment|/* 0x4020565a */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_UNSUBSCRIBE_EVENT
value|0x565b
end_define

begin_comment
comment|/* 0x4020565b */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_OVERLAY_OLD
value|0x560e
end_define

begin_comment
comment|/* 0xc004560e */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_PARM_OLD
value|0x5616
end_define

begin_comment
comment|/* 0x40cc5616 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_S_CTRL_OLD
value|0x561c
end_define

begin_comment
comment|/* 0x4008561c */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_AUDIO_OLD
value|0x5621
end_define

begin_comment
comment|/* 0xc0345621 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_G_AUDOUT_OLD
value|0x5631
end_define

begin_comment
comment|/* 0xc0345631 */
end_comment

begin_define
define|#
directive|define
name|LINUX_VIDIOC_CROPCAP_OLD
value|0x563a
end_define

begin_comment
comment|/* 0x802c563a */
end_comment

begin_define
define|#
directive|define
name|LINUX_IOCTL_VIDEO2_MIN
value|LINUX_VIDIOC_QUERYCAP
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_VIDEO2_MAX
value|LINUX_VIDIOC_UNSUBSCRIBE_EVENT
end_define

begin_comment
comment|/*  * Our libusb(8) calls emulated within linux(4).  */
end_comment

begin_define
define|#
directive|define
name|FBSD_LUSB_DEVICEENUMERATE
value|0xffff
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_DEV_QUIRK_ADD
value|0xfffe
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_DEV_QUIRK_GET
value|0xfffd
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_DEV_QUIRK_REMOVE
value|0xfffc
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_DO_REQUEST
value|0xfffb
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_FS_CLEAR_STALL_SYNC
value|0xfffa
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_FS_CLOSE
value|0xfff9
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_FS_COMPLETE
value|0xfff8
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_FS_INIT
value|0xfff7
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_FS_OPEN
value|0xfff6
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_FS_START
value|0xfff5
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_FS_STOP
value|0xfff4
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_FS_UNINIT
value|0xfff3
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_CONFIG
value|0xfff2
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_DEVICEINFO
value|0xfff1
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_DEVICE_DESC
value|0xfff0
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_FULL_DESC
value|0xffef
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_IFACE_DRIVER
value|0xffee
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_PLUGTIME
value|0xffed
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_POWER_MODE
value|0xffec
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_REPORT_DESC
value|0xffeb
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_REPORT_ID
value|0xffea
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_TEMPLATE
value|0xffe9
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_IFACE_DRIVER_ACTIVE
value|0xffe8
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_IFACE_DRIVER_DETACH
value|0xffe7
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_QUIRK_NAME_GET
value|0xffe6
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_READ_DIR
value|0xffe5
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_SET_ALTINTERFACE
value|0xffe4
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_SET_CONFIG
value|0xffe3
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_SET_IMMED
value|0xffe2
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_SET_POWER_MODE
value|0xffe1
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_SET_TEMPLATE
value|0xffe0
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_FS_OPEN_STREAM
value|0xffdf
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_DEV_PORT_PATH
value|0xffde
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_GET_POWER_USAGE
value|0xffdd
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_MAX
value|0xffff
end_define

begin_define
define|#
directive|define
name|FBSD_LUSB_MIN
value|0xffdd
end_define

begin_comment
comment|/*  * Linux btrfs clone operation  */
end_comment

begin_define
define|#
directive|define
name|LINUX_BTRFS_IOC_CLONE
value|0x9409
end_define

begin_comment
comment|/* 0x40049409 */
end_comment

begin_comment
comment|/*  * Linux evdev ioctl min and max  */
end_comment

begin_define
define|#
directive|define
name|LINUX_IOCTL_EVDEV_MIN
value|0x4500
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_EVDEV_MAX
value|0x45ff
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_EVDEV_CLK
value|LINUX_CLOCK_REALTIME |	\ 	    LINUX_CLOCK_MONOTONIC |LINUX_CLOCK_BOOTTIME
end_define

begin_comment
comment|/*  * Pluggable ioctl handlers  */
end_comment

begin_struct_decl
struct_decl|struct
name|linux_ioctl_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|linux_ioctl_function_t
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|linux_ioctl_args
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|linux_ioctl_handler
block|{
name|linux_ioctl_function_t
modifier|*
name|func
decl_stmt|;
name|int
name|low
decl_stmt|,
name|high
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|linux_ioctl_register_handler
parameter_list|(
name|struct
name|linux_ioctl_handler
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_ioctl_unregister_handler
parameter_list|(
name|struct
name|linux_ioctl_handler
modifier|*
name|h
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

