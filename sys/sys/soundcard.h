begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|SOUNDCARD_H
end_ifndef

begin_define
define|#
directive|define
name|SOUNDCARD_H
end_define

begin_comment
comment|/*  * Copyright by Hannu Savolainen 1993  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *   */
end_comment

begin_comment
comment|/*    * If you make modifications to this file, please contact me before   * distributing the modified version. There is already enough    * diversity in the world.   *   * Regards,   * Hannu Savolainen   * hannu@voxware.pp.fi   *   **********************************************************************   * PS.	The Hacker's Guide to VoxWare available from    *     nic.funet.fi:pub/OS/Linux/ALPHA/sound. The file is   *	snd-sdk-doc-0.1.ps.gz (gzipped postscript). It contains   *	some useful information about programming with VoxWare.   *	(NOTE! The pub/OS/Linux/ALPHA/ directories are hidden. You have   *	to cd inside them before the files are accessible.)   **********************************************************************   */
end_comment

begin_define
define|#
directive|define
name|SOUND_VERSION
value|301
end_define

begin_comment
comment|/*  *	Supported card ID numbers (Should be somewhere else?)  */
end_comment

begin_define
define|#
directive|define
name|SNDCARD_ADLIB
value|1
end_define

begin_define
define|#
directive|define
name|SNDCARD_SB
value|2
end_define

begin_define
define|#
directive|define
name|SNDCARD_PAS
value|3
end_define

begin_define
define|#
directive|define
name|SNDCARD_GUS
value|4
end_define

begin_define
define|#
directive|define
name|SNDCARD_MPU401
value|5
end_define

begin_define
define|#
directive|define
name|SNDCARD_SB16
value|6
end_define

begin_define
define|#
directive|define
name|SNDCARD_SB16MIDI
value|7
end_define

begin_define
define|#
directive|define
name|SNDCARD_UART6850
value|8
end_define

begin_define
define|#
directive|define
name|SNDCARD_GUS16
value|9
end_define

begin_define
define|#
directive|define
name|SNDCARD_MSS
value|10
end_define

begin_define
define|#
directive|define
name|SNDCARD_PSS
value|11
end_define

begin_define
define|#
directive|define
name|SNDCARD_SSCAPE
value|12
end_define

begin_define
define|#
directive|define
name|SNDCARD_PSS_MPU
value|13
end_define

begin_define
define|#
directive|define
name|SNDCARD_PSS_MSS
value|14
end_define

begin_define
define|#
directive|define
name|SNDCARD_SSCAPE_MSS
value|15
end_define

begin_define
define|#
directive|define
name|SNDCARD_TRXPRO
value|16
end_define

begin_define
define|#
directive|define
name|SNDCARD_TRXPRO_SB
value|17
end_define

begin_define
define|#
directive|define
name|SNDCARD_TRXPRO_MPU
value|18
end_define

begin_define
define|#
directive|define
name|SNDCARD_MAD16
value|19
end_define

begin_define
define|#
directive|define
name|SNDCARD_MAD16_MPU
value|20
end_define

begin_define
define|#
directive|define
name|SNDCARD_CS4232
value|21
end_define

begin_define
define|#
directive|define
name|SNDCARD_CS4232_MPU
value|22
end_define

begin_define
define|#
directive|define
name|SNDCARD_MAUI
value|23
end_define

begin_define
define|#
directive|define
name|SNDCARD_PSEUDO_MSS
value|24
end_define

begin_define
define|#
directive|define
name|SNDCARD_AWE32
value|25
end_define

begin_comment
comment|/*  * IOCTL Commands for /dev/sequencer  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOWR
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IOWR */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|SNDCTL_SEQ_RESET
value|_IO  ('Q', 0)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SEQ_SYNC
value|_IO  ('Q', 1)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SYNTH_INFO
value|_IOWR('Q', 2, struct synth_info)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SEQ_CTRLRATE
value|_IOWR('Q', 3, int)
end_define

begin_comment
comment|/* Set/get timer resolution (hz) */
end_comment

begin_define
define|#
directive|define
name|SNDCTL_SEQ_GETOUTCOUNT
value|_IOR ('Q', 4, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SEQ_GETINCOUNT
value|_IOR ('Q', 5, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SEQ_PERCMODE
value|_IOW ('Q', 6, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_FM_LOAD_INSTR
value|_IOW ('Q', 7, struct sbi_instrument)
end_define

begin_comment
comment|/* Valid for FM only */
end_comment

begin_define
define|#
directive|define
name|SNDCTL_SEQ_TESTMIDI
value|_IOW ('Q', 8, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SEQ_RESETSAMPLES
value|_IOW ('Q', 9, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SEQ_NRSYNTHS
value|_IOR ('Q',10, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SEQ_NRMIDIS
value|_IOR ('Q',11, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_MIDI_INFO
value|_IOWR('Q',12, struct midi_info)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SEQ_THRESHOLD
value|_IOW ('Q',13, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SEQ_TRESHOLD
value|SNDCTL_SEQ_THRESHOLD
end_define

begin_comment
comment|/* there was once a typo */
end_comment

begin_define
define|#
directive|define
name|SNDCTL_SYNTH_MEMAVL
value|_IOWR('Q',14, int)
end_define

begin_comment
comment|/* in=dev#, out=memsize */
end_comment

begin_define
define|#
directive|define
name|SNDCTL_FM_4OP_ENABLE
value|_IOW ('Q',15, int)
end_define

begin_comment
comment|/* in=dev# */
end_comment

begin_define
define|#
directive|define
name|SNDCTL_PMGR_ACCESS
value|_IOWR('Q',16, struct patmgr_info)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SEQ_PANIC
value|_IO  ('Q',17)
end_define

begin_define
define|#
directive|define
name|SNDCTL_SEQ_OUTOFBAND
value|_IOW ('Q',18, struct seq_event_rec)
end_define

begin_struct
struct|struct
name|seq_event_rec
block|{
name|u_char
name|arr
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SNDCTL_TMR_TIMEBASE
value|_IOWR('T', 1, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_TMR_START
value|_IO  ('T', 2)
end_define

begin_define
define|#
directive|define
name|SNDCTL_TMR_STOP
value|_IO  ('T', 3)
end_define

begin_define
define|#
directive|define
name|SNDCTL_TMR_CONTINUE
value|_IO  ('T', 4)
end_define

begin_define
define|#
directive|define
name|SNDCTL_TMR_TEMPO
value|_IOWR('T', 5, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_TMR_SOURCE
value|_IOWR('T', 6, int)
end_define

begin_define
define|#
directive|define
name|TMR_INTERNAL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TMR_EXTERNAL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TMR_MODE_MIDI
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TMR_MODE_FSK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TMR_MODE_CLS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TMR_MODE_SMPTE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SNDCTL_TMR_METRONOME
value|_IOW ('T', 7, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_TMR_SELECT
value|_IOW ('T', 8, int)
end_define

begin_comment
comment|/*  *	Endian aware patch key generation algorithm.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|||
name|defined
argument_list|(
name|AIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATCHKEY
parameter_list|(
name|id
parameter_list|)
value|(0xfd00|id)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATCHKEY
parameter_list|(
name|id
parameter_list|)
value|((id<<8)|0xfd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	Sample loading mechanism for internal synthesizers (/dev/sequencer)  *	The following patch_info structure has been designed to support  *	Gravis UltraSound. It tries to be universal format for uploading  *	sample based patches but is propably too limited.  */
end_comment

begin_struct
struct|struct
name|patch_info
block|{
comment|/*		u_short key;		 Use GUS_PATCH here */
name|short
name|key
decl_stmt|;
comment|/* Use GUS_PATCH here */
define|#
directive|define
name|GUS_PATCH
value|_PATCHKEY(0x04)
define|#
directive|define
name|OBSOLETE_GUS_PATCH
value|_PATCHKEY(0x02)
name|short
name|device_no
decl_stmt|;
comment|/* Synthesizer number */
name|short
name|instr_no
decl_stmt|;
comment|/* Midi pgm# */
name|u_long
name|mode
decl_stmt|;
comment|/*  * The least significant byte has the same format than the GUS .PAT  * files  */
define|#
directive|define
name|WAVE_16_BITS
value|0x01
comment|/* bit 0 = 8 or 16 bit wave data. */
define|#
directive|define
name|WAVE_UNSIGNED
value|0x02
comment|/* bit 1 = Signed - Unsigned data. */
define|#
directive|define
name|WAVE_LOOPING
value|0x04
comment|/* bit 2 = looping enabled-1. */
define|#
directive|define
name|WAVE_BIDIR_LOOP
value|0x08
comment|/* bit 3 = Set is bidirectional looping. */
define|#
directive|define
name|WAVE_LOOP_BACK
value|0x10
comment|/* bit 4 = Set is looping backward. */
define|#
directive|define
name|WAVE_SUSTAIN_ON
value|0x20
comment|/* bit 5 = Turn sustaining on. (Env. pts. 3)*/
define|#
directive|define
name|WAVE_ENVELOPES
value|0x40
comment|/* bit 6 = Enable envelopes - 1 */
comment|/* 	(use the env_rate/env_offs fields). */
comment|/* Linux specific bits */
define|#
directive|define
name|WAVE_VIBRATO
value|0x00010000
comment|/* The vibrato info is valid */
define|#
directive|define
name|WAVE_TREMOLO
value|0x00020000
comment|/* The tremolo info is valid */
define|#
directive|define
name|WAVE_SCALE
value|0x00040000
comment|/* The scaling info is valid */
comment|/* Other bits must be zeroed */
name|long
name|len
decl_stmt|;
comment|/* Size of the wave data in bytes */
name|long
name|loop_start
decl_stmt|,
name|loop_end
decl_stmt|;
comment|/* Byte offsets from the beginning */
comment|/*   * The base_freq and base_note fields are used when computing the  * playback speed for a note. The base_note defines the tone frequency  * which is heard if the sample is played using the base_freq as the  * playback speed.  *  * The low_note and high_note fields define the minimum and maximum note  * frequencies for which this sample is valid. It is possible to define  * more than one samples for a instrument number at the same time. The  * low_note and high_note fields are used to select the most suitable one.  *  * The fields base_note, high_note and low_note should contain  * the note frequency multiplied by 1000. For example value for the  * middle A is 440*1000.  */
name|u_int
name|base_freq
decl_stmt|;
name|u_long
name|base_note
decl_stmt|;
name|u_long
name|high_note
decl_stmt|;
name|u_long
name|low_note
decl_stmt|;
name|int
name|panning
decl_stmt|;
comment|/* -128=left, 127=right */
name|int
name|detuning
decl_stmt|;
comment|/*	New fields introduced in version 1.99.5	*/
comment|/* Envelope. Enabled by mode bit WAVE_ENVELOPES	*/
name|u_char
name|env_rate
index|[
literal|6
index|]
decl_stmt|;
comment|/* GUS HW ramping rate */
name|u_char
name|env_offset
index|[
literal|6
index|]
decl_stmt|;
comment|/* 255 == 100% */
comment|/*  	 * The tremolo, vibrato and scale info are not supported yet. 	 * Enable by setting the mode bits WAVE_TREMOLO, WAVE_VIBRATO or 	 * WAVE_SCALE 	 */
name|u_char
name|tremolo_sweep
decl_stmt|;
name|u_char
name|tremolo_rate
decl_stmt|;
name|u_char
name|tremolo_depth
decl_stmt|;
name|u_char
name|vibrato_sweep
decl_stmt|;
name|u_char
name|vibrato_rate
decl_stmt|;
name|u_char
name|vibrato_depth
decl_stmt|;
name|int
name|scale_frequency
decl_stmt|;
name|u_int
name|scale_factor
decl_stmt|;
comment|/* from 0 to 2048 or 0 to 2 */
name|int
name|volume
decl_stmt|;
name|int
name|spare
index|[
literal|4
index|]
decl_stmt|;
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
comment|/* The waveform data starts here */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sysex_info
block|{
name|short
name|key
decl_stmt|;
comment|/* Use GUS_PATCH here */
define|#
directive|define
name|SYSEX_PATCH
value|_PATCHKEY(0x05)
define|#
directive|define
name|MAUI_PATCH
value|_PATCHKEY(0x06)
name|short
name|device_no
decl_stmt|;
comment|/* Synthesizer number */
name|long
name|len
decl_stmt|;
comment|/* Size of the sysex data in bytes */
name|u_char
name|data
index|[
literal|1
index|]
decl_stmt|;
comment|/* Sysex data starts here */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Patch management interface (/dev/sequencer, /dev/patmgr#)  * Don't use these calls if you want to maintain compatibility with  * the future versions of the driver.  */
end_comment

begin_define
define|#
directive|define
name|PS_NO_PATCHES
value|0
end_define

begin_comment
comment|/* No patch support on device */
end_comment

begin_define
define|#
directive|define
name|PS_MGR_NOT_OK
value|1
end_define

begin_comment
comment|/* Plain patch support (no mgr) */
end_comment

begin_define
define|#
directive|define
name|PS_MGR_OK
value|2
end_define

begin_comment
comment|/* Patch manager supported */
end_comment

begin_define
define|#
directive|define
name|PS_MANAGED
value|3
end_define

begin_comment
comment|/* Patch manager running */
end_comment

begin_define
define|#
directive|define
name|SNDCTL_PMGR_IFACE
value|_IOWR('P', 1, struct patmgr_info)
end_define

begin_comment
comment|/*  * The patmgr_info is a fixed size structure which is used for two  * different purposes. The intended use is for communication between  * the application using /dev/sequencer and the patch manager daemon  * associated with a synthesizer device (ioctl(SNDCTL_PMGR_ACCESS)).  *  * This structure is also used with ioctl(SNDCTL_PGMR_IFACE) which allows  * a patch manager daemon to read and write device parameters. This  * ioctl available through /dev/sequencer also. Avoid using it since it's  * extremely hardware dependent. In addition access trough /dev/sequencer   * may confuse the patch manager daemon.  */
end_comment

begin_struct
struct|struct
name|patmgr_info
block|{
comment|/* Note! size must be< 4k since kmalloc() is used */
name|u_long
name|key
decl_stmt|;
comment|/* Don't worry. Reserved for communication 	  			   between the patch manager and the driver. */
define|#
directive|define
name|PM_K_EVENT
value|1
comment|/* Event from the /dev/sequencer driver */
define|#
directive|define
name|PM_K_COMMAND
value|2
comment|/* Request from a application */
define|#
directive|define
name|PM_K_RESPONSE
value|3
comment|/* From patmgr to application */
define|#
directive|define
name|PM_ERROR
value|4
comment|/* Error returned by the patmgr */
name|int
name|device
decl_stmt|;
name|int
name|command
decl_stmt|;
comment|/*   * Commands 0x000 to 0xfff reserved for patch manager programs   */
define|#
directive|define
name|PM_GET_DEVTYPE
value|1
comment|/* Returns type of the patch mgr interface of dev */
define|#
directive|define
name|PMTYPE_FM2
value|1
comment|/* 2 OP fm */
define|#
directive|define
name|PMTYPE_FM4
value|2
comment|/* Mixed 4 or 2 op FM (OPL-3) */
define|#
directive|define
name|PMTYPE_WAVE
value|3
comment|/* Wave table synthesizer (GUS) */
define|#
directive|define
name|PM_GET_NRPGM
value|2
comment|/* Returns max # of midi programs in parm1 */
define|#
directive|define
name|PM_GET_PGMMAP
value|3
comment|/* Returns map of loaded midi programs in data8 */
define|#
directive|define
name|PM_GET_PGM_PATCHES
value|4
comment|/* Return list of patches of a program (parm1) */
define|#
directive|define
name|PM_GET_PATCH
value|5
comment|/* Return patch header of patch parm1 */
define|#
directive|define
name|PM_SET_PATCH
value|6
comment|/* Set patch header of patch parm1 */
define|#
directive|define
name|PM_READ_PATCH
value|7
comment|/* Read patch (wave) data */
define|#
directive|define
name|PM_WRITE_PATCH
value|8
comment|/* Write patch (wave) data */
comment|/*  * Commands 0x1000 to 0xffff are for communication between the patch manager  * and the client  */
define|#
directive|define
name|_PM_LOAD_PATCH
value|0x100
comment|/*   * Commands above 0xffff reserved for device specific use  */
name|long
name|parm1
decl_stmt|;
name|long
name|parm2
decl_stmt|;
name|long
name|parm3
decl_stmt|;
union|union
block|{
name|u_char
name|data8
index|[
literal|4000
index|]
decl_stmt|;
name|u_short
name|data16
index|[
literal|2000
index|]
decl_stmt|;
name|u_long
name|data32
index|[
literal|1000
index|]
decl_stmt|;
name|struct
name|patch_info
name|patch
decl_stmt|;
block|}
name|data
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * When a patch manager daemon is present, it will be informed by the  * driver when something important happens. For example when the  * /dev/sequencer is opened or closed. A record with key == PM_K_EVENT is  * returned. The command field contains the event type:  */
end_comment

begin_define
define|#
directive|define
name|PM_E_OPENED
value|1
end_define

begin_comment
comment|/* /dev/sequencer opened */
end_comment

begin_define
define|#
directive|define
name|PM_E_CLOSED
value|2
end_define

begin_comment
comment|/* /dev/sequencer closed */
end_comment

begin_define
define|#
directive|define
name|PM_E_PATCH_RESET
value|3
end_define

begin_comment
comment|/* SNDCTL_RESETSAMPLES called */
end_comment

begin_define
define|#
directive|define
name|PM_E_PATCH_LOADED
value|4
end_define

begin_comment
comment|/* A patch has been loaded by appl */
end_comment

begin_comment
comment|/*  * /dev/sequencer input events.  *  * The data written to the /dev/sequencer is a stream of events. Events  * are records of 4 or 8 bytes. The first byte defines the size.   * Any number of events can be written with a write call. There  * is a set of macros for sending these events. Use these macros if you  * want to maximize portability of your program.  *  * Events SEQ_WAIT, SEQ_MIDIPUTC and SEQ_ECHO. Are also input events.  * (All input events are currently 4 bytes long. Be prepared to support  * 8 byte events also. If you receive any event having first byte>= 128,  * it's a 8 byte event.  *  * The events are documented at the end of this file.  *  * Normal events (4 bytes)  * There is also a 8 byte version of most of the 4 byte events. The  * 8 byte one is recommended.  */
end_comment

begin_define
define|#
directive|define
name|SEQ_NOTEOFF
value|0
end_define

begin_define
define|#
directive|define
name|SEQ_FMNOTEOFF
value|SEQ_NOTEOFF
end_define

begin_comment
comment|/* Just old name */
end_comment

begin_define
define|#
directive|define
name|SEQ_NOTEON
value|1
end_define

begin_define
define|#
directive|define
name|SEQ_FMNOTEON
value|SEQ_NOTEON
end_define

begin_define
define|#
directive|define
name|SEQ_WAIT
value|TMR_WAIT_ABS
end_define

begin_define
define|#
directive|define
name|SEQ_PGMCHANGE
value|3
end_define

begin_define
define|#
directive|define
name|SEQ_FMPGMCHANGE
value|SEQ_PGMCHANGE
end_define

begin_define
define|#
directive|define
name|SEQ_SYNCTIMER
value|TMR_START
end_define

begin_define
define|#
directive|define
name|SEQ_MIDIPUTC
value|5
end_define

begin_define
define|#
directive|define
name|SEQ_DRUMON
value|6
end_define

begin_comment
comment|/*** OBSOLETE ***/
end_comment

begin_define
define|#
directive|define
name|SEQ_DRUMOFF
value|7
end_define

begin_comment
comment|/*** OBSOLETE ***/
end_comment

begin_define
define|#
directive|define
name|SEQ_ECHO
value|TMR_ECHO
end_define

begin_comment
comment|/* For synching programs with output */
end_comment

begin_define
define|#
directive|define
name|SEQ_AFTERTOUCH
value|9
end_define

begin_define
define|#
directive|define
name|SEQ_CONTROLLER
value|10
end_define

begin_comment
comment|/*******************************************  *	Midi controller numbers  *******************************************  * Controllers 0 to 31 (0x00 to 0x1f) and  * 32 to 63 (0x20 to 0x3f) are continuous  * controllers.  * In the MIDI 1.0 these controllers are sent using  * two messages. Controller numbers 0 to 31 are used  * to send the MSB and the controller numbers 32 to 63  * are for the LSB. Note that just 7 bits are used in MIDI bytes.  */
end_comment

begin_define
define|#
directive|define
name|CTL_BANK_SELECT
value|0x00
end_define

begin_define
define|#
directive|define
name|CTL_MODWHEEL
value|0x01
end_define

begin_define
define|#
directive|define
name|CTL_BREATH
value|0x02
end_define

begin_comment
comment|/*		undefined		0x03 */
end_comment

begin_define
define|#
directive|define
name|CTL_FOOT
value|0x04
end_define

begin_define
define|#
directive|define
name|CTL_PORTAMENTO_TIME
value|0x05
end_define

begin_define
define|#
directive|define
name|CTL_DATA_ENTRY
value|0x06
end_define

begin_define
define|#
directive|define
name|CTL_MAIN_VOLUME
value|0x07
end_define

begin_define
define|#
directive|define
name|CTL_BALANCE
value|0x08
end_define

begin_comment
comment|/*		undefined		0x09 */
end_comment

begin_define
define|#
directive|define
name|CTL_PAN
value|0x0a
end_define

begin_define
define|#
directive|define
name|CTL_EXPRESSION
value|0x0b
end_define

begin_comment
comment|/*		undefined		0x0c */
end_comment

begin_comment
comment|/*		undefined		0x0d */
end_comment

begin_comment
comment|/*		undefined		0x0e */
end_comment

begin_comment
comment|/*		undefined		0x0f */
end_comment

begin_define
define|#
directive|define
name|CTL_GENERAL_PURPOSE1
value|0x10
end_define

begin_define
define|#
directive|define
name|CTL_GENERAL_PURPOSE2
value|0x11
end_define

begin_define
define|#
directive|define
name|CTL_GENERAL_PURPOSE3
value|0x12
end_define

begin_define
define|#
directive|define
name|CTL_GENERAL_PURPOSE4
value|0x13
end_define

begin_comment
comment|/*		undefined		0x14 - 0x1f */
end_comment

begin_comment
comment|/*		undefined		0x20 */
end_comment

begin_comment
comment|/* The controller numbers 0x21 to 0x3f are reserved for the */
end_comment

begin_comment
comment|/* least significant bytes of the controllers 0x00 to 0x1f. */
end_comment

begin_comment
comment|/* These controllers are not recognised by the driver. */
end_comment

begin_comment
comment|/* Controllers 64 to 69 (0x40 to 0x45) are on/off switches. */
end_comment

begin_comment
comment|/* 0=OFF and 127=ON (intermediate values are possible) */
end_comment

begin_define
define|#
directive|define
name|CTL_DAMPER_PEDAL
value|0x40
end_define

begin_define
define|#
directive|define
name|CTL_SUSTAIN
value|0x40
end_define

begin_comment
comment|/* Alias */
end_comment

begin_define
define|#
directive|define
name|CTL_HOLD
value|0x40
end_define

begin_comment
comment|/* Alias */
end_comment

begin_define
define|#
directive|define
name|CTL_PORTAMENTO
value|0x41
end_define

begin_define
define|#
directive|define
name|CTL_SOSTENUTO
value|0x42
end_define

begin_define
define|#
directive|define
name|CTL_SOFT_PEDAL
value|0x43
end_define

begin_comment
comment|/*		undefined		0x44 */
end_comment

begin_define
define|#
directive|define
name|CTL_HOLD2
value|0x45
end_define

begin_comment
comment|/*		undefined		0x46 - 0x4f */
end_comment

begin_define
define|#
directive|define
name|CTL_GENERAL_PURPOSE5
value|0x50
end_define

begin_define
define|#
directive|define
name|CTL_GENERAL_PURPOSE6
value|0x51
end_define

begin_define
define|#
directive|define
name|CTL_GENERAL_PURPOSE7
value|0x52
end_define

begin_define
define|#
directive|define
name|CTL_GENERAL_PURPOSE8
value|0x53
end_define

begin_comment
comment|/*		undefined		0x54 - 0x5a */
end_comment

begin_define
define|#
directive|define
name|CTL_EXT_EFF_DEPTH
value|0x5b
end_define

begin_define
define|#
directive|define
name|CTL_TREMOLO_DEPTH
value|0x5c
end_define

begin_define
define|#
directive|define
name|CTL_CHORUS_DEPTH
value|0x5d
end_define

begin_define
define|#
directive|define
name|CTL_DETUNE_DEPTH
value|0x5e
end_define

begin_define
define|#
directive|define
name|CTL_CELESTE_DEPTH
value|0x5e
end_define

begin_comment
comment|/* Alias for the above one */
end_comment

begin_define
define|#
directive|define
name|CTL_PHASER_DEPTH
value|0x5f
end_define

begin_define
define|#
directive|define
name|CTL_DATA_INCREMENT
value|0x60
end_define

begin_define
define|#
directive|define
name|CTL_DATA_DECREMENT
value|0x61
end_define

begin_define
define|#
directive|define
name|CTL_NONREG_PARM_NUM_LSB
value|0x62
end_define

begin_define
define|#
directive|define
name|CTL_NONREG_PARM_NUM_MSB
value|0x63
end_define

begin_define
define|#
directive|define
name|CTL_REGIST_PARM_NUM_LSB
value|0x64
end_define

begin_define
define|#
directive|define
name|CTL_REGIST_PARM_NUM_MSB
value|0x65
end_define

begin_comment
comment|/*		undefined		0x66 - 0x78 */
end_comment

begin_comment
comment|/*		reserved		0x79 - 0x7f */
end_comment

begin_comment
comment|/* Pseudo controllers (not midi compatible) */
end_comment

begin_define
define|#
directive|define
name|CTRL_PITCH_BENDER
value|255
end_define

begin_define
define|#
directive|define
name|CTRL_PITCH_BENDER_RANGE
value|254
end_define

begin_define
define|#
directive|define
name|CTRL_EXPRESSION
value|253
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_define
define|#
directive|define
name|CTRL_MAIN_VOLUME
value|252
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_define
define|#
directive|define
name|SEQ_BALANCE
value|11
end_define

begin_define
define|#
directive|define
name|SEQ_VOLMODE
value|12
end_define

begin_comment
comment|/*  * Volume mode decides how volumes are used  */
end_comment

begin_define
define|#
directive|define
name|VOL_METHOD_ADAGIO
value|1
end_define

begin_define
define|#
directive|define
name|VOL_METHOD_LINEAR
value|2
end_define

begin_comment
comment|/*  * Note! SEQ_WAIT, SEQ_MIDIPUTC and SEQ_ECHO are used also as  *	 input events.  */
end_comment

begin_comment
comment|/*  * Event codes 0xf0 to 0xfc are reserved for future extensions.  */
end_comment

begin_define
define|#
directive|define
name|SEQ_FULLSIZE
value|0xfd
end_define

begin_comment
comment|/* Long events */
end_comment

begin_comment
comment|/*  *	SEQ_FULLSIZE events are used for loading patches/samples to the  *	synthesizer devices. These events are passed directly to the driver  *	of the associated synthesizer device. There is no limit to the size  *	of the extended events. These events are not queued but executed  *	immediately when the write() is called (execution can take several  *	seconds of time).   *  *	When a SEQ_FULLSIZE message is written to the device, it must  *	be written using exactly one write() call. Other events cannot  *	be mixed to the same write.  *	  *	For FM synths (YM3812/OPL3) use struct sbi_instrument and write it to the   *	/dev/sequencer. Don't write other data together with the instrument structure  *	Set the key field of the structure to FM_PATCH. The device field is used to  *	route the patch to the corresponding device.  *  *	For Gravis UltraSound use struct patch_info. Initialize the key field  *      to GUS_PATCH.  */
end_comment

begin_define
define|#
directive|define
name|SEQ_PRIVATE
value|0xfe
end_define

begin_comment
comment|/* Low level HW dependent events (8 bytes) */
end_comment

begin_define
define|#
directive|define
name|SEQ_EXTENDED
value|0xff
end_define

begin_comment
comment|/* Extended events (8 bytes) OBSOLETE */
end_comment

begin_comment
comment|/*  * Record for FM patches  */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|sbi_instr_data
index|[
literal|32
index|]
typedef|;
end_typedef

begin_struct
struct|struct
name|sbi_instrument
block|{
name|u_short
name|key
decl_stmt|;
comment|/* FM_PATCH or OPL3_PATCH */
define|#
directive|define
name|FM_PATCH
value|_PATCHKEY(0x01)
define|#
directive|define
name|OPL3_PATCH
value|_PATCHKEY(0x03)
name|short
name|device
decl_stmt|;
comment|/* Synth# (0-4)	*/
name|int
name|channel
decl_stmt|;
comment|/* Program# to be initialized  */
name|sbi_instr_data
name|operators
decl_stmt|;
comment|/* Reg. settings for operator cells 					 * (.SBI format)	*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|synth_info
block|{
comment|/* Read only */
name|char
name|name
index|[
literal|30
index|]
decl_stmt|;
name|int
name|device
decl_stmt|;
comment|/* 0-N. INITIALIZE BEFORE CALLING */
name|int
name|synth_type
decl_stmt|;
define|#
directive|define
name|SYNTH_TYPE_FM
value|0
define|#
directive|define
name|SYNTH_TYPE_SAMPLE
value|1
define|#
directive|define
name|SYNTH_TYPE_MIDI
value|2
comment|/* Midi interface */
name|int
name|synth_subtype
decl_stmt|;
define|#
directive|define
name|FM_TYPE_ADLIB
value|0x00
define|#
directive|define
name|FM_TYPE_OPL3
value|0x01
define|#
directive|define
name|SAMPLE_TYPE_GUS
value|0x10
name|int
name|perc_mode
decl_stmt|;
comment|/* No longer supported */
name|int
name|nr_voices
decl_stmt|;
name|int
name|nr_drums
decl_stmt|;
comment|/* Obsolete field */
name|int
name|instr_bank_size
decl_stmt|;
name|u_long
name|capabilities
decl_stmt|;
define|#
directive|define
name|SYNTH_CAP_PERCMODE
value|0x00000001
comment|/* No longer used */
define|#
directive|define
name|SYNTH_CAP_OPL3
value|0x00000002
comment|/* Set if OPL3 supported */
define|#
directive|define
name|SYNTH_CAP_INPUT
value|0x00000004
comment|/* Input (MIDI) device */
name|int
name|dummies
index|[
literal|19
index|]
decl_stmt|;
comment|/* Reserve space */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sound_timer_info
block|{
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
name|int
name|caps
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MIDI_CAP_MPU401
value|1
end_define

begin_comment
comment|/* MPU-401 intelligent mode */
end_comment

begin_struct
struct|struct
name|midi_info
block|{
name|char
name|name
index|[
literal|30
index|]
decl_stmt|;
name|int
name|device
decl_stmt|;
comment|/* 0-N. INITIALIZE BEFORE CALLING */
name|u_long
name|capabilities
decl_stmt|;
comment|/* To be defined later */
name|int
name|dev_type
decl_stmt|;
name|int
name|dummies
index|[
literal|18
index|]
decl_stmt|;
comment|/* Reserve space */
block|}
struct|;
end_struct

begin_comment
comment|/********************************************  * ioctl commands for the /dev/midi##  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|cmd
decl_stmt|;
name|char
name|nr_args
decl_stmt|,
name|nr_returns
decl_stmt|;
name|u_char
name|data
index|[
literal|30
index|]
decl_stmt|;
block|}
name|mpu_command_rec
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNDCTL_MIDI_PRETIME
value|_IOWR('m', 0, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_MIDI_MPUMODE
value|_IOWR('m', 1, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_MIDI_MPUCMD
value|_IOWR('m', 2, mpu_command_rec)
end_define

begin_comment
comment|/********************************************  * IOCTL commands for /dev/dsp and /dev/audio  */
end_comment

begin_define
define|#
directive|define
name|SNDCTL_DSP_RESET
value|_IO  ('P', 0)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_SYNC
value|_IO  ('P', 1)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_SPEED
value|_IOWR('P', 2, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_STEREO
value|_IOWR('P', 3, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_GETBLKSIZE
value|_IOR('P', 4, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_SETBLKSIZE
value|_IOW('P', 4, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_SAMPLESIZE
value|SNDCTL_DSP_SETFMT
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_WRITE_CHANNELS
value|_IOWR('P', 6, int)
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_WRITE_FILTER
value|_IOWR('P', 7, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_POST
value|_IO  ('P', 8)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_SUBDIVIDE
value|_IOWR('P', 9, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_SETFRAGMENT
value|_IOWR('P',10, int)
end_define

begin_comment
comment|/*	Audio data formats (Note! U8=8 and S16_LE=16 for compatibility) */
end_comment

begin_define
define|#
directive|define
name|SNDCTL_DSP_GETFMTS
value|_IOR ('P',11, int)
end_define

begin_comment
comment|/* Returns a mask */
end_comment

begin_define
define|#
directive|define
name|SNDCTL_DSP_SETFMT
value|_IOWR('P',5, int)
end_define

begin_comment
comment|/* Selects ONE fmt*/
end_comment

begin_define
define|#
directive|define
name|AFMT_QUERY
value|0x00000000
end_define

begin_comment
comment|/* Return current fmt */
end_comment

begin_define
define|#
directive|define
name|AFMT_MU_LAW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AFMT_A_LAW
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AFMT_IMA_ADPCM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AFMT_U8
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AFMT_S16_LE
value|0x00000010
end_define

begin_comment
comment|/* Little endian signed 16*/
end_comment

begin_define
define|#
directive|define
name|AFMT_S16_BE
value|0x00000020
end_define

begin_comment
comment|/* Big endian signed 16 */
end_comment

begin_define
define|#
directive|define
name|AFMT_S8
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AFMT_U16_LE
value|0x00000080
end_define

begin_comment
comment|/* Little endian U16 */
end_comment

begin_define
define|#
directive|define
name|AFMT_U16_BE
value|0x00000100
end_define

begin_comment
comment|/* Big endian U16 */
end_comment

begin_define
define|#
directive|define
name|AFMT_MPEG
value|0x00000200
end_define

begin_comment
comment|/* MPEG (2) audio */
end_comment

begin_comment
comment|/*  * Buffer status queries.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|audio_buf_info
block|{
name|int
name|fragments
decl_stmt|;
comment|/* # of available fragments (partially used 			 * ones not counted) */
name|int
name|fragstotal
decl_stmt|;
comment|/* Total # of fragments allocated */
name|int
name|fragsize
decl_stmt|;
comment|/* Size of a fragment in bytes */
name|int
name|bytes
decl_stmt|;
comment|/* Available space in bytes (includes 			 * partially used fragments) */
comment|/* Note! 'bytes' could be more than fragments*fragsize */
block|}
name|audio_buf_info
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNDCTL_DSP_GETOSPACE
value|_IOR ('P',12, audio_buf_info)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_GETISPACE
value|_IOR ('P',13, audio_buf_info)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_NONBLOCK
value|_IO  ('P',14)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_GETCAPS
value|_IOR ('P',15, int)
end_define

begin_define
define|#
directive|define
name|DSP_CAP_REVISION
value|0x000000ff
end_define

begin_comment
comment|/* Bits for revision level (0 to 255) */
end_comment

begin_define
define|#
directive|define
name|DSP_CAP_DUPLEX
value|0x00000100
end_define

begin_comment
comment|/* Full duplex record/playback */
end_comment

begin_define
define|#
directive|define
name|DSP_CAP_REALTIME
value|0x00000200
end_define

begin_comment
comment|/* Real time capability */
end_comment

begin_define
define|#
directive|define
name|DSP_CAP_BATCH
value|0x00000400
end_define

begin_comment
comment|/* Device has some kind of */
end_comment

begin_comment
comment|/* internal buffers which may */
end_comment

begin_comment
comment|/* cause some delays and */
end_comment

begin_comment
comment|/* decrease precision of timing */
end_comment

begin_define
define|#
directive|define
name|DSP_CAP_COPROC
value|0x00000800
end_define

begin_comment
comment|/* Has a coprocessor */
end_comment

begin_comment
comment|/* Sometimes it's a DSP */
end_comment

begin_comment
comment|/* but usually not */
end_comment

begin_define
define|#
directive|define
name|DSP_CAP_TRIGGER
value|0x00001000
end_define

begin_comment
comment|/* Supports SETTRIGGER */
end_comment

begin_define
define|#
directive|define
name|DSP_CAP_MMAP
value|0x00002000
end_define

begin_comment
comment|/* Supports mmap() */
end_comment

begin_define
define|#
directive|define
name|SNDCTL_DSP_GETCAPS
value|_IOR ('P',15, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_GETTRIGGER
value|_IOR ('P',16, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_SETTRIGGER
value|_IOW ('P',16, int)
end_define

begin_define
define|#
directive|define
name|PCM_ENABLE_INPUT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCM_ENABLE_OUTPUT
value|0x00000002
end_define

begin_typedef
typedef|typedef
struct|struct
name|count_info
block|{
name|int
name|bytes
decl_stmt|;
comment|/* Total # of bytes processed */
name|int
name|blocks
decl_stmt|;
comment|/* # of fragment transitions since last time */
name|int
name|ptr
decl_stmt|;
comment|/* Current DMA pointer value */
block|}
name|count_info
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNDCTL_DSP_GETIPTR
value|_IOR ('P',17, count_info)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_GETOPTR
value|_IOR ('P',18, count_info)
end_define

begin_typedef
typedef|typedef
struct|struct
name|buffmem_desc
block|{
name|caddr_t
name|buffer
decl_stmt|;
name|int
name|size
decl_stmt|;
block|}
name|buffmem_desc
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNDCTL_DSP_MAPINBUF
value|_IOR ('P', 19, buffmem_desc)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_MAPOUTBUF
value|_IOR ('P', 20, buffmem_desc)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_SETSYNCRO
value|_IO  ('P', 21)
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_READ_RATE
value|_IOR ('P', 2, int)
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_READ_CHANNELS
value|_IOR ('P', 6, int)
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_READ_BITS
value|_IOR ('P', 5, int)
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_READ_FILTER
value|_IOR ('P', 7, int)
end_define

begin_comment
comment|/* Some alias names */
end_comment

begin_define
define|#
directive|define
name|SOUND_PCM_WRITE_BITS
value|SNDCTL_DSP_SETFMT
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_WRITE_RATE
value|SNDCTL_DSP_SPEED
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_POST
value|SNDCTL_DSP_POST
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_RESET
value|SNDCTL_DSP_RESET
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_SYNC
value|SNDCTL_DSP_SYNC
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_SUBDIVIDE
value|SNDCTL_DSP_SUBDIVIDE
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_SETFRAGMENT
value|SNDCTL_DSP_SETFRAGMENT
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_GETFMTS
value|SNDCTL_DSP_GETFMTS
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_SETFMT
value|SNDCTL_DSP_SETFMT
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_GETOSPACE
value|SNDCTL_DSP_GETOSPACE
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_GETISPACE
value|SNDCTL_DSP_GETISPACE
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_NONBLOCK
value|SNDCTL_DSP_NONBLOCK
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_GETCAPS
value|SNDCTL_DSP_GETCAPS
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_GETTRIGGER
value|SNDCTL_DSP_GETTRIGGER
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_SETTRIGGER
value|SNDCTL_DSP_SETTRIGGER
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_SETSYNCRO
value|SNDCTL_DSP_SETSYNCRO
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_GETIPTR
value|SNDCTL_DSP_GETIPTR
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_GETOPTR
value|SNDCTL_DSP_GETOPTR
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_MAPINBUF
value|SNDCTL_DSP_MAPINBUF
end_define

begin_define
define|#
directive|define
name|SOUND_PCM_MAPOUTBUF
value|SNDCTL_DSP_MAPOUTBUF
end_define

begin_comment
comment|/*  * ioctl calls to be used in communication with coprocessors and  * DSP chips.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|copr_buffer
block|{
name|int
name|command
decl_stmt|;
comment|/* Set to 0 if not used */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|CPF_NONE
value|0x0000
define|#
directive|define
name|CPF_FIRST
value|0x0001
comment|/* First block */
define|#
directive|define
name|CPF_LAST
value|0x0002
comment|/* Last block */
name|int
name|len
decl_stmt|;
name|int
name|offs
decl_stmt|;
comment|/* If required by the device (0 if not used) */
name|u_char
name|data
index|[
literal|4000
index|]
decl_stmt|;
comment|/* NOTE! 4000 is not 4k */
block|}
name|copr_buffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|copr_debug_buf
block|{
name|int
name|command
decl_stmt|;
comment|/* Used internally. Set to 0 */
name|int
name|parm1
decl_stmt|;
name|int
name|parm2
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|len
decl_stmt|;
comment|/* Length of data in bytes */
block|}
name|copr_debug_buf
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|copr_msg
block|{
name|int
name|len
decl_stmt|;
name|u_char
name|data
index|[
literal|4000
index|]
decl_stmt|;
block|}
name|copr_msg
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNDCTL_COPR_RESET
value|_IO  ('C',  0)
end_define

begin_define
define|#
directive|define
name|SNDCTL_COPR_LOAD
value|_IOWR('C',  1, copr_buffer)
end_define

begin_define
define|#
directive|define
name|SNDCTL_COPR_RDATA
value|_IOWR('C',  2, copr_debug_buf)
end_define

begin_define
define|#
directive|define
name|SNDCTL_COPR_RCODE
value|_IOWR('C',  3, copr_debug_buf)
end_define

begin_define
define|#
directive|define
name|SNDCTL_COPR_WDATA
value|_IOW ('C',  4, copr_debug_buf)
end_define

begin_define
define|#
directive|define
name|SNDCTL_COPR_WCODE
value|_IOW ('C',  5, copr_debug_buf)
end_define

begin_define
define|#
directive|define
name|SNDCTL_COPR_RUN
value|_IOWR('C',  6, copr_debug_buf)
end_define

begin_define
define|#
directive|define
name|SNDCTL_COPR_HALT
value|_IOWR('C',  7, copr_debug_buf)
end_define

begin_define
define|#
directive|define
name|SNDCTL_COPR_SENDMSG
value|_IOW ('C',  8, copr_msg)
end_define

begin_define
define|#
directive|define
name|SNDCTL_COPR_RCVMSG
value|_IOR ('C',  9, copr_msg)
end_define

begin_comment
comment|/*********************************************  * IOCTL commands for /dev/mixer  */
end_comment

begin_comment
comment|/*   * Mixer devices  *  * There can be up to 20 different analog mixer channels. The  * SOUND_MIXER_NRDEVICES gives the currently supported maximum.   * The SOUND_MIXER_READ_DEVMASK returns a bitmask which tells  * the devices supported by the particular mixer.  */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_NRDEVICES
value|17
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_VOLUME
value|0
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_BASS
value|1
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_TREBLE
value|2
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_SYNTH
value|3
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_PCM
value|4
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_SPEAKER
value|5
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_LINE
value|6
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_MIC
value|7
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_CD
value|8
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_IMIX
value|9
end_define

begin_comment
comment|/*  Recording monitor  */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_ALTPCM
value|10
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_RECLEV
value|11
end_define

begin_comment
comment|/* Recording level */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_IGAIN
value|12
end_define

begin_comment
comment|/* Input gain */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_OGAIN
value|13
end_define

begin_comment
comment|/* Output gain */
end_comment

begin_comment
comment|/*   * The AD1848 codec and compatibles have three line level inputs  * (line, aux1 and aux2). Since each card manufacturer have assigned  * different meanings to these inputs, it's inpractical to assign  * specific meanings (line, cd, synth etc.) to them.  */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_LINE1
value|14
end_define

begin_comment
comment|/* Input source 1  (aux1) */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_LINE2
value|15
end_define

begin_comment
comment|/* Input source 2  (aux2) */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_LINE3
value|16
end_define

begin_comment
comment|/* Input source 3  (line) */
end_comment

begin_comment
comment|/* Some on/off settings (SOUND_SPECIAL_MIN - SOUND_SPECIAL_MAX) */
end_comment

begin_comment
comment|/* Not counted to SOUND_MIXER_NRDEVICES, but use the same number space */
end_comment

begin_define
define|#
directive|define
name|SOUND_ONOFF_MIN
value|28
end_define

begin_define
define|#
directive|define
name|SOUND_ONOFF_MAX
value|30
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_MUTE
value|28
end_define

begin_comment
comment|/* 0 or 1 */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_ENHANCE
value|29
end_define

begin_comment
comment|/* Enhanced stereo (0, 40, 60 or 80) */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_LOUD
value|30
end_define

begin_comment
comment|/* 0 or 1 */
end_comment

begin_comment
comment|/* Note!	Number 31 cannot be used since the sign bit is reserved */
end_comment

begin_define
define|#
directive|define
name|SOUND_DEVICE_LABELS
value|{ \ 	"Vol  ", "Bass ", "Trebl", "Synth", "Pcm  ", "Spkr ", "Line ", \ 	 "Mic  ", "CD   ", "Mix  ", "Pcm2 ", "Rec  ", "IGain", "OGain", \ 	 "Line1", "Line2", "Line3"}
end_define

begin_define
define|#
directive|define
name|SOUND_DEVICE_NAMES
value|{ \ 	"vol", "bass", "treble", "synth", "pcm", "speaker", "line", \ 	"mic", "cd", "mix", "pcm2", "rec", "igain", "ogain", \ 	"line1", "line2", "line3"}
end_define

begin_comment
comment|/*	Device bitmask identifiers	*/
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_RECSRC
value|0xff
end_define

begin_comment
comment|/* 1 bit per recording source */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_DEVMASK
value|0xfe
end_define

begin_comment
comment|/* 1 bit per supported device */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_RECMASK
value|0xfd
end_define

begin_comment
comment|/* 1 bit per supp. recording source */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_CAPS
value|0xfc
end_define

begin_define
define|#
directive|define
name|SOUND_CAP_EXCL_INPUT
value|0x00000001
end_define

begin_comment
comment|/* Only 1 rec. src at a time */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_STEREODEVS
value|0xfb
end_define

begin_comment
comment|/* Mixer channels supporting stereo */
end_comment

begin_comment
comment|/*	Device mask bits	*/
end_comment

begin_define
define|#
directive|define
name|SOUND_MASK_VOLUME
value|(1<< SOUND_MIXER_VOLUME)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_BASS
value|(1<< SOUND_MIXER_BASS)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_TREBLE
value|(1<< SOUND_MIXER_TREBLE)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_SYNTH
value|(1<< SOUND_MIXER_SYNTH)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_PCM
value|(1<< SOUND_MIXER_PCM)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_SPEAKER
value|(1<< SOUND_MIXER_SPEAKER)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_LINE
value|(1<< SOUND_MIXER_LINE)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_MIC
value|(1<< SOUND_MIXER_MIC)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_CD
value|(1<< SOUND_MIXER_CD)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_IMIX
value|(1<< SOUND_MIXER_IMIX)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_ALTPCM
value|(1<< SOUND_MIXER_ALTPCM)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_RECLEV
value|(1<< SOUND_MIXER_RECLEV)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_IGAIN
value|(1<< SOUND_MIXER_IGAIN)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_OGAIN
value|(1<< SOUND_MIXER_OGAIN)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_LINE1
value|(1<< SOUND_MIXER_LINE1)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_LINE2
value|(1<< SOUND_MIXER_LINE2)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_LINE3
value|(1<< SOUND_MIXER_LINE3)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_MUTE
value|(1<< SOUND_MIXER_MUTE)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_ENHANCE
value|(1<< SOUND_MIXER_ENHANCE)
end_define

begin_define
define|#
directive|define
name|SOUND_MASK_LOUD
value|(1<< SOUND_MIXER_LOUD)
end_define

begin_define
define|#
directive|define
name|MIXER_READ
parameter_list|(
name|dev
parameter_list|)
value|_IOR('M', dev, int)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_VOLUME
value|MIXER_READ(SOUND_MIXER_VOLUME)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_BASS
value|MIXER_READ(SOUND_MIXER_BASS)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_TREBLE
value|MIXER_READ(SOUND_MIXER_TREBLE)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_SYNTH
value|MIXER_READ(SOUND_MIXER_SYNTH)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_PCM
value|MIXER_READ(SOUND_MIXER_PCM)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_SPEAKER
value|MIXER_READ(SOUND_MIXER_SPEAKER)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_LINE
value|MIXER_READ(SOUND_MIXER_LINE)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_MIC
value|MIXER_READ(SOUND_MIXER_MIC)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_CD
value|MIXER_READ(SOUND_MIXER_CD)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_IMIX
value|MIXER_READ(SOUND_MIXER_IMIX)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_ALTPCM
value|MIXER_READ(SOUND_MIXER_ALTPCM)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_RECLEV
value|MIXER_READ(SOUND_MIXER_RECLEV)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_IGAIN
value|MIXER_READ(SOUND_MIXER_IGAIN)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_OGAIN
value|MIXER_READ(SOUND_MIXER_OGAIN)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_LINE1
value|MIXER_READ(SOUND_MIXER_LINE1)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_LINE2
value|MIXER_READ(SOUND_MIXER_LINE2)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_LINE3
value|MIXER_READ(SOUND_MIXER_LINE3)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_MUTE
value|MIXER_READ(SOUND_MIXER_MUTE)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_ENHANCE
value|MIXER_READ(SOUND_MIXER_ENHANCE)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_LOUD
value|MIXER_READ(SOUND_MIXER_LOUD)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_RECSRC
value|MIXER_READ(SOUND_MIXER_RECSRC)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_DEVMASK
value|MIXER_READ(SOUND_MIXER_DEVMASK)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_RECMASK
value|MIXER_READ(SOUND_MIXER_RECMASK)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_STEREODEVS
value|MIXER_READ(SOUND_MIXER_STEREODEVS)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_READ_CAPS
value|MIXER_READ(SOUND_MIXER_CAPS)
end_define

begin_define
define|#
directive|define
name|MIXER_WRITE
parameter_list|(
name|dev
parameter_list|)
value|_IOWR('M', dev, int)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_VOLUME
value|MIXER_WRITE(SOUND_MIXER_VOLUME)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_BASS
value|MIXER_WRITE(SOUND_MIXER_BASS)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_TREBLE
value|MIXER_WRITE(SOUND_MIXER_TREBLE)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_SYNTH
value|MIXER_WRITE(SOUND_MIXER_SYNTH)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_PCM
value|MIXER_WRITE(SOUND_MIXER_PCM)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_SPEAKER
value|MIXER_WRITE(SOUND_MIXER_SPEAKER)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_LINE
value|MIXER_WRITE(SOUND_MIXER_LINE)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_MIC
value|MIXER_WRITE(SOUND_MIXER_MIC)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_CD
value|MIXER_WRITE(SOUND_MIXER_CD)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_IMIX
value|MIXER_WRITE(SOUND_MIXER_IMIX)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_ALTPCM
value|MIXER_WRITE(SOUND_MIXER_ALTPCM)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_RECLEV
value|MIXER_WRITE(SOUND_MIXER_RECLEV)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_IGAIN
value|MIXER_WRITE(SOUND_MIXER_IGAIN)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_OGAIN
value|MIXER_WRITE(SOUND_MIXER_OGAIN)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_LINE1
value|MIXER_WRITE(SOUND_MIXER_LINE1)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_LINE2
value|MIXER_WRITE(SOUND_MIXER_LINE2)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_LINE3
value|MIXER_WRITE(SOUND_MIXER_LINE3)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_MUTE
value|MIXER_WRITE(SOUND_MIXER_MUTE)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_ENHANCE
value|MIXER_WRITE(SOUND_MIXER_ENHANCE)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_LOUD
value|MIXER_WRITE(SOUND_MIXER_LOUD)
end_define

begin_define
define|#
directive|define
name|SOUND_MIXER_WRITE_RECSRC
value|MIXER_WRITE(SOUND_MIXER_RECSRC)
end_define

begin_comment
comment|/*  * Level 2 event types for /dev/sequencer  */
end_comment

begin_comment
comment|/*  * The 4 most significant bits of byte 0 specify the class of  * the event:   *  *	0x8X = system level events,  *	0x9X = device/port specific events, event[1] = device/port,  *		The last 4 bits give the subtype:  *			0x02	= Channel event (event[3] = chn).  *			0x01	= note event (event[4] = note).  *			(0x01 is not used alone but always with bit 0x02).  *	       event[2] = MIDI message code (0x80=note off etc.)  *  */
end_comment

begin_define
define|#
directive|define
name|EV_SEQ_LOCAL
value|0x80
end_define

begin_define
define|#
directive|define
name|EV_TIMING
value|0x81
end_define

begin_define
define|#
directive|define
name|EV_CHN_COMMON
value|0x92
end_define

begin_define
define|#
directive|define
name|EV_CHN_VOICE
value|0x93
end_define

begin_define
define|#
directive|define
name|EV_SYSEX
value|0x94
end_define

begin_comment
comment|/*  * Event types 200 to 220 are reserved for application use.  * These numbers will not be used by the driver.  */
end_comment

begin_comment
comment|/*  * Events for event type EV_CHN_VOICE  */
end_comment

begin_define
define|#
directive|define
name|MIDI_NOTEOFF
value|0x80
end_define

begin_define
define|#
directive|define
name|MIDI_NOTEON
value|0x90
end_define

begin_define
define|#
directive|define
name|MIDI_KEY_PRESSURE
value|0xA0
end_define

begin_comment
comment|/*  * Events for event type EV_CHN_COMMON  */
end_comment

begin_define
define|#
directive|define
name|MIDI_CTL_CHANGE
value|0xB0
end_define

begin_define
define|#
directive|define
name|MIDI_PGM_CHANGE
value|0xC0
end_define

begin_define
define|#
directive|define
name|MIDI_CHN_PRESSURE
value|0xD0
end_define

begin_define
define|#
directive|define
name|MIDI_PITCH_BEND
value|0xE0
end_define

begin_define
define|#
directive|define
name|MIDI_SYSTEM_PREFIX
value|0xF0
end_define

begin_comment
comment|/*  * Timer event types  */
end_comment

begin_define
define|#
directive|define
name|TMR_WAIT_REL
value|1
end_define

begin_comment
comment|/* Time relative to the prev time */
end_comment

begin_define
define|#
directive|define
name|TMR_WAIT_ABS
value|2
end_define

begin_comment
comment|/* Absolute time since TMR_START */
end_comment

begin_define
define|#
directive|define
name|TMR_STOP
value|3
end_define

begin_define
define|#
directive|define
name|TMR_START
value|4
end_define

begin_define
define|#
directive|define
name|TMR_CONTINUE
value|5
end_define

begin_define
define|#
directive|define
name|TMR_TEMPO
value|6
end_define

begin_define
define|#
directive|define
name|TMR_ECHO
value|8
end_define

begin_define
define|#
directive|define
name|TMR_CLOCK
value|9
end_define

begin_comment
comment|/* MIDI clock */
end_comment

begin_define
define|#
directive|define
name|TMR_SPP
value|10
end_define

begin_comment
comment|/* Song position pointer */
end_comment

begin_define
define|#
directive|define
name|TMR_TIMESIG
value|11
end_define

begin_comment
comment|/* Time signature */
end_comment

begin_comment
comment|/*  *	Local event types  */
end_comment

begin_define
define|#
directive|define
name|LOCL_STARTAUDIO
value|1
end_define

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|INKERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|USE_SEQ_MACROS
argument_list|)
end_if

begin_comment
comment|/*  *	Some convenience macros to simplify programming of the  *	/dev/sequencer interface  *  *	These macros define the API which should be used when possible.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_SIMPLE_MACROS
end_ifndef

begin_function_decl
name|void
name|seqbuf_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function must be provided by programs */
end_comment

begin_comment
comment|/* Sample seqbuf_dump() implementation:  *  *	SEQ_DEFINEBUF (2048);	-- Defines a buffer for 2048 bytes  *  *	int seqfd;		-- The file descriptor for /dev/sequencer.  *  *	void  *	seqbuf_dump ()  *	{  *	  if (_seqbufptr)  *	    if (write (seqfd, _seqbuf, _seqbufptr) == -1)  *	      {  *		perror ("write /dev/sequencer");  *		exit (-1);  *	      }  *	  _seqbufptr = 0;  *	}  */
end_comment

begin_define
define|#
directive|define
name|SEQ_DEFINEBUF
parameter_list|(
name|len
parameter_list|)
define|\
value|u_char _seqbuf[len]; int _seqbuflen = len;int _seqbufptr = 0
end_define

begin_define
define|#
directive|define
name|SEQ_USE_EXTBUF
parameter_list|()
define|\
value|extern u_char _seqbuf[]; \ 	extern int _seqbuflen;extern int _seqbufptr
end_define

begin_define
define|#
directive|define
name|SEQ_DECLAREBUF
parameter_list|()
value|SEQ_USE_EXTBUF()
end_define

begin_define
define|#
directive|define
name|SEQ_PM_DEFINES
value|struct patmgr_info _pm_info
end_define

begin_define
define|#
directive|define
name|_SEQ_NEEDBUF
parameter_list|(
name|len
parameter_list|)
define|\
value|if ((_seqbufptr+(len))> _seqbuflen) \ 		seqbuf_dump()
end_define

begin_define
define|#
directive|define
name|_SEQ_ADVBUF
parameter_list|(
name|len
parameter_list|)
value|_seqbufptr += len
end_define

begin_define
define|#
directive|define
name|SEQ_DUMPBUF
value|seqbuf_dump
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * This variation of the sequencer macros is used just to format one event  * using fixed buffer.  *   * The program using the macro library must define the following macros before  * using this library.  *  * #define _seqbuf 		 name of the buffer (u_char[])   * #define _SEQ_ADVBUF(len)	 If the applic needs to know the exact  *				 size of the event, this macro can be used.  *				 Otherwise this must be defined as empty.  * #define _seqbufptr		 Define the name of index variable or 0 if  *				 not required.   */
end_comment

begin_define
define|#
directive|define
name|_SEQ_NEEDBUF
parameter_list|(
name|len
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PM_LOAD_PATCH
parameter_list|(
name|dev
parameter_list|,
name|bank
parameter_list|,
name|pgm
parameter_list|)
define|\
value|(SEQ_DUMPBUF(), _pm_info.command = _PM_LOAD_PATCH, \ 	_pm_info.device=dev, _pm_info.data.data8[0]=pgm, \ 	_pm_info.parm1 = bank, _pm_info.parm2 = 1, \ 	ioctl(seqfd, SNDCTL_PMGR_ACCESS,&_pm_info))
end_define

begin_define
define|#
directive|define
name|PM_LOAD_PATCHES
parameter_list|(
name|dev
parameter_list|,
name|bank
parameter_list|,
name|pgm
parameter_list|)
define|\
value|(SEQ_DUMPBUF(), _pm_info.command = _PM_LOAD_PATCH, \ 	_pm_info.device=dev, bcopy( pgm, _pm_info.data.data8,  128), \ 	_pm_info.parm1 = bank, _pm_info.parm2 = 128, \ 	ioctl(seqfd, SNDCTL_PMGR_ACCESS,&_pm_info))
end_define

begin_define
define|#
directive|define
name|SEQ_VOLUME_MODE
parameter_list|(
name|dev
parameter_list|,
name|mode
parameter_list|)
value|{ \ 	_SEQ_NEEDBUF(8);\ 	_seqbuf[_seqbufptr] = SEQ_EXTENDED;\ 	_seqbuf[_seqbufptr+1] = SEQ_VOLMODE;\ 	_seqbuf[_seqbufptr+2] = (dev);\ 	_seqbuf[_seqbufptr+3] = (mode);\ 	_seqbuf[_seqbufptr+4] = 0;\ 	_seqbuf[_seqbufptr+5] = 0;\ 	_seqbuf[_seqbufptr+6] = 0;\ 	_seqbuf[_seqbufptr+7] = 0;\ 	_SEQ_ADVBUF(8);}
end_define

begin_comment
comment|/*  * Midi voice messages  */
end_comment

begin_define
define|#
directive|define
name|_CHN_VOICE
parameter_list|(
name|dev
parameter_list|,
name|event
parameter_list|,
name|chn
parameter_list|,
name|note
parameter_list|,
name|parm
parameter_list|)
value|{ \ 	_SEQ_NEEDBUF(8);\ 	_seqbuf[_seqbufptr] = EV_CHN_VOICE;\ 	_seqbuf[_seqbufptr+1] = (dev);\ 	_seqbuf[_seqbufptr+2] = (event);\ 	_seqbuf[_seqbufptr+3] = (chn);\ 	_seqbuf[_seqbufptr+4] = (note);\ 	_seqbuf[_seqbufptr+5] = (parm);\ 	_seqbuf[_seqbufptr+6] = (0);\ 	_seqbuf[_seqbufptr+7] = 0;\ 	_SEQ_ADVBUF(8);}
end_define

begin_define
define|#
directive|define
name|SEQ_START_NOTE
parameter_list|(
name|dev
parameter_list|,
name|chn
parameter_list|,
name|note
parameter_list|,
name|vol
parameter_list|)
define|\
value|_CHN_VOICE(dev, MIDI_NOTEON, chn, note, vol)
end_define

begin_define
define|#
directive|define
name|SEQ_STOP_NOTE
parameter_list|(
name|dev
parameter_list|,
name|chn
parameter_list|,
name|note
parameter_list|,
name|vol
parameter_list|)
define|\
value|_CHN_VOICE(dev, MIDI_NOTEOFF, chn, note, vol)
end_define

begin_define
define|#
directive|define
name|SEQ_KEY_PRESSURE
parameter_list|(
name|dev
parameter_list|,
name|chn
parameter_list|,
name|note
parameter_list|,
name|pressure
parameter_list|)
define|\
value|_CHN_VOICE(dev, MIDI_KEY_PRESSURE, chn, note, pressure)
end_define

begin_comment
comment|/*  * Midi channel messages  */
end_comment

begin_define
define|#
directive|define
name|_CHN_COMMON
parameter_list|(
name|dev
parameter_list|,
name|event
parameter_list|,
name|chn
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|w14
parameter_list|)
value|{ \ 	_SEQ_NEEDBUF(8);\ 	_seqbuf[_seqbufptr] = EV_CHN_COMMON;\ 	_seqbuf[_seqbufptr+1] = (dev);\ 	_seqbuf[_seqbufptr+2] = (event);\ 	_seqbuf[_seqbufptr+3] = (chn);\ 	_seqbuf[_seqbufptr+4] = (p1);\ 	_seqbuf[_seqbufptr+5] = (p2);\ 	*(short *)&_seqbuf[_seqbufptr+6] = (w14);\ 	_SEQ_ADVBUF(8);}
end_define

begin_comment
comment|/*  * SEQ_SYSEX permits sending of sysex messages. (It may look that it permits  * sending any MIDI bytes but it's absolutely not possible. Trying to do  * so _will_ cause problems with MPU401 intelligent mode).  *  * Sysex messages are sent in blocks of 1 to 6 bytes. Longer messages must be   * sent by calling SEQ_SYSEX() several times (there must be no other events  * between them). First sysex fragment must have 0xf0 in the first byte  * and the last byte (buf[len-1] of the last fragment must be 0xf7. No byte  * between these sysex start and end markers cannot be larger than 0x7f. Also  * lengths of each fragments (except the last one) must be 6.  *  * Breaking the above rules may work with some MIDI ports but is likely to  * cause fatal problems with some other devices (such as MPU401).  */
end_comment

begin_define
define|#
directive|define
name|SEQ_SYSEX
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
value|{ \ 	int i, l=(len); if (l>6)l=6;\ 	_SEQ_NEEDBUF(8);\ 	_seqbuf[_seqbufptr] = EV_SYSEX;\ 	for(i=0;i<l;i++)_seqbuf[_seqbufptr+i+1] = (buf)[i];\ 	for(i=l;i<6;i++)_seqbuf[_seqbufptr+i+1] = 0xff;\ 	_SEQ_ADVBUF(8);}
end_define

begin_define
define|#
directive|define
name|SEQ_CHN_PRESSURE
parameter_list|(
name|dev
parameter_list|,
name|chn
parameter_list|,
name|pressure
parameter_list|)
define|\
value|_CHN_COMMON(dev, MIDI_CHN_PRESSURE, chn, pressure, 0, 0)
end_define

begin_define
define|#
directive|define
name|SEQ_SET_PATCH
parameter_list|(
name|dev
parameter_list|,
name|chn
parameter_list|,
name|patch
parameter_list|)
define|\
value|_CHN_COMMON(dev, MIDI_PGM_CHANGE, chn, patch, 0, 0)
end_define

begin_define
define|#
directive|define
name|SEQ_CONTROL
parameter_list|(
name|dev
parameter_list|,
name|chn
parameter_list|,
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|_CHN_COMMON(dev, MIDI_CTL_CHANGE, chn, controller, 0, value)
end_define

begin_define
define|#
directive|define
name|SEQ_BENDER
parameter_list|(
name|dev
parameter_list|,
name|chn
parameter_list|,
name|value
parameter_list|)
define|\
value|_CHN_COMMON(dev, MIDI_PITCH_BEND, chn, 0, 0, value)
end_define

begin_define
define|#
directive|define
name|SEQ_V2_X_CONTROL
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|controller
parameter_list|,
name|value
parameter_list|)
value|{ \ 	_SEQ_NEEDBUF(8);\ 	_seqbuf[_seqbufptr] = SEQ_EXTENDED;\ 	_seqbuf[_seqbufptr+1] = SEQ_CONTROLLER;\ 	_seqbuf[_seqbufptr+2] = (dev);\ 	_seqbuf[_seqbufptr+3] = (voice);\ 	_seqbuf[_seqbufptr+4] = (controller);\ 	*(short *)&_seqbuf[_seqbufptr+5] = (value);\ 	_seqbuf[_seqbufptr+7] = 0;\ 	_SEQ_ADVBUF(8);}
end_define

begin_comment
comment|/*  * The following 5 macros are incorrectly implemented and obsolete.  * Use SEQ_BENDER and SEQ_CONTROL (with proper controller) instead.  */
end_comment

begin_define
define|#
directive|define
name|SEQ_PITCHBEND
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|value
parameter_list|)
define|\
value|SEQ_V2_X_CONTROL(dev, voice, CTRL_PITCH_BENDER, value)
end_define

begin_define
define|#
directive|define
name|SEQ_BENDER_RANGE
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|value
parameter_list|)
define|\
value|SEQ_V2_X_CONTROL(dev, voice, CTRL_PITCH_BENDER_RANGE, value)
end_define

begin_define
define|#
directive|define
name|SEQ_EXPRESSION
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|value
parameter_list|)
define|\
value|SEQ_CONTROL(dev, voice, CTL_EXPRESSION, value*128)
end_define

begin_define
define|#
directive|define
name|SEQ_MAIN_VOLUME
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|value
parameter_list|)
define|\
value|SEQ_CONTROL(dev, voice, CTL_MAIN_VOLUME, (value*16383)/100)
end_define

begin_define
define|#
directive|define
name|SEQ_PANNING
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|pos
parameter_list|)
define|\
value|SEQ_CONTROL(dev, voice, CTL_PAN, (pos+128) / 2)
end_define

begin_comment
comment|/*  * Timing and syncronization macros  */
end_comment

begin_define
define|#
directive|define
name|_TIMER_EVENT
parameter_list|(
name|ev
parameter_list|,
name|parm
parameter_list|)
value|{ \ 	_SEQ_NEEDBUF(8);\ 	_seqbuf[_seqbufptr+0] = EV_TIMING; \ 	_seqbuf[_seqbufptr+1] = (ev); \ 	_seqbuf[_seqbufptr+2] = 0;\ 	_seqbuf[_seqbufptr+3] = 0;\ 	*(u_int *)&_seqbuf[_seqbufptr+4] = (parm); \ 	_SEQ_ADVBUF(8); \ 	}
end_define

begin_define
define|#
directive|define
name|SEQ_START_TIMER
parameter_list|()
value|_TIMER_EVENT(TMR_START, 0)
end_define

begin_define
define|#
directive|define
name|SEQ_STOP_TIMER
parameter_list|()
value|_TIMER_EVENT(TMR_STOP, 0)
end_define

begin_define
define|#
directive|define
name|SEQ_CONTINUE_TIMER
parameter_list|()
value|_TIMER_EVENT(TMR_CONTINUE, 0)
end_define

begin_define
define|#
directive|define
name|SEQ_WAIT_TIME
parameter_list|(
name|ticks
parameter_list|)
value|_TIMER_EVENT(TMR_WAIT_ABS, ticks)
end_define

begin_define
define|#
directive|define
name|SEQ_DELTA_TIME
parameter_list|(
name|ticks
parameter_list|)
value|_TIMER_EVENT(TMR_WAIT_REL, ticks)
end_define

begin_define
define|#
directive|define
name|SEQ_ECHO_BACK
parameter_list|(
name|key
parameter_list|)
value|_TIMER_EVENT(TMR_ECHO, key)
end_define

begin_define
define|#
directive|define
name|SEQ_SET_TEMPO
parameter_list|(
name|value
parameter_list|)
value|_TIMER_EVENT(TMR_TEMPO, value)
end_define

begin_define
define|#
directive|define
name|SEQ_SONGPOS
parameter_list|(
name|pos
parameter_list|)
value|_TIMER_EVENT(TMR_SPP, pos)
end_define

begin_define
define|#
directive|define
name|SEQ_TIME_SIGNATURE
parameter_list|(
name|sig
parameter_list|)
value|_TIMER_EVENT(TMR_TIMESIG, sig)
end_define

begin_comment
comment|/*  * Local control events  */
end_comment

begin_define
define|#
directive|define
name|_LOCAL_EVENT
parameter_list|(
name|ev
parameter_list|,
name|parm
parameter_list|)
value|{ \ 	_SEQ_NEEDBUF(8);\ 	_seqbuf[_seqbufptr+0] = EV_SEQ_LOCAL; \ 	_seqbuf[_seqbufptr+1] = (ev); \ 	_seqbuf[_seqbufptr+2] = 0;\ 	_seqbuf[_seqbufptr+3] = 0;\ 	*(u_int *)&_seqbuf[_seqbufptr+4] = (parm); \ 	_SEQ_ADVBUF(8); \ 	}
end_define

begin_define
define|#
directive|define
name|SEQ_PLAYAUDIO
parameter_list|(
name|devmask
parameter_list|)
value|_LOCAL_EVENT(LOCL_STARTAUDIO, devmask)
end_define

begin_comment
comment|/*  * Events for the level 1 interface only   */
end_comment

begin_define
define|#
directive|define
name|SEQ_MIDIOUT
parameter_list|(
name|device
parameter_list|,
name|byte
parameter_list|)
value|{ \ 	_SEQ_NEEDBUF(4);\ 	_seqbuf[_seqbufptr] = SEQ_MIDIPUTC;\ 	_seqbuf[_seqbufptr+1] = (byte);\ 	_seqbuf[_seqbufptr+2] = (device);\ 	_seqbuf[_seqbufptr+3] = 0;\ 	_SEQ_ADVBUF(4);}
end_define

begin_comment
comment|/*  * Patch loading.  */
end_comment

begin_define
define|#
directive|define
name|SEQ_WRPATCH
parameter_list|(
name|patchx
parameter_list|,
name|len
parameter_list|)
value|{ \ 	if (_seqbufptr) seqbuf_dump(); \ 	if (write(seqfd, (char*)(patchx), len)==-1) \ 	   perror("Write patch: /dev/sequencer"); \ 	}
end_define

begin_define
define|#
directive|define
name|SEQ_WRPATCH2
parameter_list|(
name|patchx
parameter_list|,
name|len
parameter_list|)
define|\
value|( seqbuf_dump(), write(seqfd, (char*)(patchx), len) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

