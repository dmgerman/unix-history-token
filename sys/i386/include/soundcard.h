begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_SOUNDCARD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SOUNDCARD_H_
end_define

begin_comment
comment|/*  * Copyright by Hannu Savolainen 1993  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *   */
end_comment

begin_comment
comment|/*    * If you make modifications to this file, please contact me before   * distributing the modified version. There is already enough    * divercity in the world.   *   * Regards,   * Hannu Savolainen   * hannu@voxware.pp.fi, Hannu.Savolainen@helsinki.fi   */
end_comment

begin_define
define|#
directive|define
name|SOUND_VERSION
value|205
end_define

begin_define
define|#
directive|define
name|VOXWARE
end_define

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

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

begin_comment
comment|/***********************************  * IOCTL Commands for /dev/sequencer  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOWR
end_ifndef

begin_comment
comment|/*	@(#)ioctlp.h */
end_comment

begin_comment
comment|/* Ioctl's have the command encoded in the lower word,  * and the size of any in or out parameters in the upper  * word.  The high 2 bits of the upper word are used  * to encode the in/out status of the parameter; for now  * we restrict parameters to at most 128 bytes.  */
end_comment

begin_comment
comment|/* #define	IOCTYPE		(0xff<<8) */
end_comment

begin_define
define|#
directive|define
name|IOCPARM_MASK
value|0x7f
end_define

begin_comment
comment|/* parameters must be< 128 bytes */
end_comment

begin_define
define|#
directive|define
name|IOC_VOID
value|0x00000000
end_define

begin_comment
comment|/* no parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_OUT
value|0x20000000
end_define

begin_comment
comment|/* copy out parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_IN
value|0x40000000
end_define

begin_comment
comment|/* copy in parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_INOUT
value|(IOC_IN|IOC_OUT)
end_define

begin_comment
comment|/* the 0x20000000 is so we can distinguish new ioctl's from old */
end_comment

begin_define
define|#
directive|define
name|_IO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((int)(IOC_VOID|(x<<8)|y))
end_define

begin_define
define|#
directive|define
name|_IOR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|t
parameter_list|)
value|((int)(IOC_OUT|((sizeof(t)&IOCPARM_MASK)<<16)|(x<<8)|y))
end_define

begin_define
define|#
directive|define
name|_IOW
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|t
parameter_list|)
value|((int)(IOC_IN|((sizeof(t)&IOCPARM_MASK)<<16)|(x<<8)|y))
end_define

begin_comment
comment|/* this should be _IORW, but stdio got there first */
end_comment

begin_define
define|#
directive|define
name|_IOWR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|t
parameter_list|)
value|((int)(IOC_INOUT|((sizeof(t)&IOCPARM_MASK)<<16)|(x<<8)|y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IOWR */
end_comment

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
comment|/* Set/get timer resolution (HZ) */
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
name|SNDCTL_SEQ_TRESHOLD
value|_IOW ('Q',13, int)
end_define

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

begin_comment
comment|/*  *	Sample loading mechanism for internal synthesizers (/dev/sequencer)  *	The following patch_info structure has been designed to support  *	Gravis UltraSound. It tries to be universal format for uploading  *	sample based patches but is propably too limited.  */
end_comment

begin_struct
struct|struct
name|patch_info
block|{
name|short
name|key
decl_stmt|;
comment|/* Use GUS_PATCH here */
define|#
directive|define
name|GUS_PATCH
value|0x04fd
define|#
directive|define
name|OBSOLETE_GUS_PATCH
value|0x02fd
name|short
name|device_no
decl_stmt|;
comment|/* Synthesizer number */
name|short
name|instr_no
decl_stmt|;
comment|/* Midi pgm# */
name|unsigned
name|long
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
name|unsigned
name|int
name|base_freq
decl_stmt|;
name|unsigned
name|long
name|base_note
decl_stmt|;
name|unsigned
name|long
name|high_note
decl_stmt|;
name|unsigned
name|long
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
name|unsigned
name|char
name|env_rate
index|[
literal|6
index|]
decl_stmt|;
comment|/* GUS HW ramping rate */
name|unsigned
name|char
name|env_offset
index|[
literal|6
index|]
decl_stmt|;
comment|/* 255 == 100% */
comment|/*  	 * The tremolo, vibrato and scale info are not supported yet. 	 * Enable by setting the mode bits WAVE_TREMOLO, WAVE_VIBRATO or 	 * WAVE_SCALE 	 */
name|unsigned
name|char
name|tremolo_sweep
decl_stmt|;
name|unsigned
name|char
name|tremolo_rate
decl_stmt|;
name|unsigned
name|char
name|tremolo_depth
decl_stmt|;
name|unsigned
name|char
name|vibrato_sweep
decl_stmt|;
name|unsigned
name|char
name|vibrato_rate
decl_stmt|;
name|unsigned
name|char
name|vibrato_depth
decl_stmt|;
name|int
name|scale_frequency
decl_stmt|;
name|unsigned
name|int
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
name|unsigned
name|long
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
name|unsigned
name|char
name|data8
index|[
literal|4000
index|]
decl_stmt|;
name|unsigned
name|short
name|data16
index|[
literal|2000
index|]
decl_stmt|;
name|unsigned
name|long
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
comment|/*  * /dev/sequencer input events.  *  * The data written to the /dev/sequencer is a stream of events. Events  * are records of 4 or 8 bytes. The first byte defines the size.   * Any number of events can be written with a write call. There  * is a set of macros for sending these events. Use these macros if you  * want to maximize portability of your program.  *  * Events SEQ_WAIT, SEQ_MIDIPUTC and SEQ_ECHO. Are also input events.  * (All input events are currently 4 bytes long. Be prepared to support  * 8 byte events also. If you receive any event having first byte>= 0xf0,  * it's a 8 byte event.  *  * The events are documented at the end of this file.  *  * Normal events (4 bytes)  * There is also a 8 byte version of most of the 4 byte events. The  * 8 byte one is recommended.  */
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
value|2
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
value|4
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
value|8
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

begin_define
define|#
directive|define
name|CTRL_MAIN_VOLUME
value|252
end_define

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
comment|/* Extended events (8 bytes) */
end_comment

begin_comment
comment|/*  *	Extended events for synthesizers (8 bytes)  *  *	Format:  *  *		b0	= SEQ_EXTENDED  *		b1	= command  *		b2	= device  *		b3-b7	= parameters  *  *	Command				b3	b4	b5	b6	b7  *	----------------------------------------------------------------------------  *	SEQ_NOTEON			voice	note	volume	0	0  *	SEQ_NOTEOFF			voice	note	volume	0	0  *	SEQ_PGMCHANGE			voice	pgm	0	0	0  *	SEQ_DRUMON			(voice)	drum#	volume	0	0  *	SEQ_DRUMOFF			(voice)	drum#	volume	0	0  */
end_comment

begin_comment
comment|/*  * Record for FM patches  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
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
name|unsigned
name|short
name|key
decl_stmt|;
comment|/* 	Initialize to FM_PATCH or OPL3_PATCH */
define|#
directive|define
name|FM_PATCH
value|0x01fd
define|#
directive|define
name|OPL3_PATCH
value|0x03fd
name|short
name|device
decl_stmt|;
comment|/*	Synth# (0-4)	*/
name|int
name|channel
decl_stmt|;
comment|/*	Program# to be initialized 	*/
name|sbi_instr_data
name|operators
decl_stmt|;
comment|/*	Register settings for operator cells (.SBI format)	*/
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
name|unsigned
name|long
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
name|unsigned
name|long
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
value|_IOWR('P', 4, int)
end_define

begin_define
define|#
directive|define
name|SNDCTL_DSP_SAMPLESIZE
value|_IOWR('P', 5, int)
end_define

begin_comment
comment|/* 8, 12 or 16 */
end_comment

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
value|SNDCTL_DSP_SAMPLESIZE
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
value|12
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
value|{"Vol  ", "Bass ", "Trebl", "Synth", "Pcm  ", "Spkr ", "Line ", \ 				 "Mic  ", "CD   ", "Mix  ", "Pcm2 ", "rec"}
end_define

begin_define
define|#
directive|define
name|SOUND_DEVICE_NAMES
value|{"vol", "bass", "treble", "synth", "pcm", "speaker", "line", \ 				 "mic", "cd", "mix", "pcm2", "rec"}
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
comment|/* Arg contains a bit for each recording source */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_DEVMASK
value|0xfe
end_define

begin_comment
comment|/* Arg contains a bit for each supported device */
end_comment

begin_define
define|#
directive|define
name|SOUND_MIXER_RECMASK
value|0xfd
end_define

begin_comment
comment|/* Arg contains a bit for each supported recording source */
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
comment|/* Only one recording source at a time */
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
comment|/*  *	The following mixer ioctl calls are compatible with the BSD driver by  *	  Steve Haehnichen<shaehnic@ucsd.edu>  *  * Since this interface is entirely SB specific, it will be dropped in the  * near future.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|S_BYTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|S_FLAG
typedef|;
end_typedef

begin_struct
struct|struct
name|stereo_vol
block|{
name|S_BYTE
name|l
decl_stmt|;
comment|/* Left volume */
name|S_BYTE
name|r
decl_stmt|;
comment|/* Right volume */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MIXER_IOCTL_SET_LEVELS
value|_IOW ('s', 20, struct sb_mixer_levels)
end_define

begin_define
define|#
directive|define
name|MIXER_IOCTL_SET_PARAMS
value|_IOW ('s', 21, struct sb_mixer_params)
end_define

begin_define
define|#
directive|define
name|MIXER_IOCTL_READ_LEVELS
value|_IOR ('s', 22, struct sb_mixer_levels)
end_define

begin_define
define|#
directive|define
name|MIXER_IOCTL_READ_PARAMS
value|_IOR ('s', 23, struct sb_mixer_params)
end_define

begin_define
define|#
directive|define
name|MIXER_IOCTL_RESET
value|_IO  ('s', 24)
end_define

begin_comment
comment|/*  * Mixer volume levels for MIXER_IOCTL_SET_VOL& MIXER_IOCTL_READ_VOL  */
end_comment

begin_struct
struct|struct
name|sb_mixer_levels
block|{
name|struct
name|stereo_vol
name|master
decl_stmt|;
comment|/* Master volume */
name|struct
name|stereo_vol
name|voc
decl_stmt|;
comment|/* DSP Voice volume */
name|struct
name|stereo_vol
name|fm
decl_stmt|;
comment|/* FM volume */
name|struct
name|stereo_vol
name|line
decl_stmt|;
comment|/* Line-in volume */
name|struct
name|stereo_vol
name|cd
decl_stmt|;
comment|/* CD audio */
name|S_BYTE
name|mic
decl_stmt|;
comment|/* Microphone level */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mixer parameters for MIXER_IOCTL_SET_PARAMS& MIXER_IOCTL_READ_PARAMS  */
end_comment

begin_struct
struct|struct
name|sb_mixer_params
block|{
name|S_BYTE
name|record_source
decl_stmt|;
comment|/* Recording source (See SRC_xxx below) */
name|S_FLAG
name|hifreq_filter
decl_stmt|;
comment|/* Filter frequency (hi/low) */
name|S_FLAG
name|filter_input
decl_stmt|;
comment|/* ANFI input filter */
name|S_FLAG
name|filter_output
decl_stmt|;
comment|/* DNFI output filter */
name|S_FLAG
name|dsp_stereo
decl_stmt|;
comment|/* 1 if DSP is in Stereo mode */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SRC_MIC
value|1
end_define

begin_comment
comment|/* Select Microphone recording source */
end_comment

begin_define
define|#
directive|define
name|SRC_CD
value|3
end_define

begin_comment
comment|/* Select CD recording source */
end_comment

begin_define
define|#
directive|define
name|SRC_LINE
value|7
end_define

begin_comment
comment|/* Use Line-in for recording source */
end_comment

begin_if
if|#
directive|if
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
end_if

begin_comment
comment|/*  *	Some convenience macros to simplify programming of the  *	/dev/sequencer interface  *  *	These macros define the API which should be used when possible.  */
end_comment

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
value|unsigned char _seqbuf[len]; int _seqbuflen = len; int _seqbufptr = 0
end_define

begin_define
define|#
directive|define
name|SEQ_DECLAREBUF
parameter_list|()
value|extern unsigned char _seqbuf[]; extern int _seqbuflen;extern int _seqbufptr
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
value|if ((_seqbufptr+(len))> _seqbuflen) seqbuf_dump()
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
value|(SEQ_DUMPBUF(), _pm_info.command = _PM_LOAD_PATCH, \ 					_pm_info.device=dev, _pm_info.data.data8[0]=pgm, \ 					_pm_info.parm1 = bank, _pm_info.parm2 = 1, \ 					ioctl(seqfd, SNDCTL_PMGR_ACCESS,&_pm_info))
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
value|(SEQ_DUMPBUF(), _pm_info.command = _PM_LOAD_PATCH, \ 					_pm_info.device=dev, memcpy(_pm_info.data.data8, pgm, 128), \ 					_pm_info.parm1 = bank, _pm_info.parm2 = 128, \ 					ioctl(seqfd, SNDCTL_PMGR_ACCESS,&_pm_info))
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
value|{_SEQ_NEEDBUF(8);\ 					_seqbuf[_seqbufptr] = SEQ_EXTENDED;\ 					_seqbuf[_seqbufptr+1] = SEQ_VOLMODE;\ 					_seqbuf[_seqbufptr+2] = (dev);\ 					_seqbuf[_seqbufptr+3] = (mode);\ 					_seqbuf[_seqbufptr+4] = 0;\ 					_seqbuf[_seqbufptr+5] = 0;\ 					_seqbuf[_seqbufptr+6] = 0;\ 					_seqbuf[_seqbufptr+7] = 0;\ 					_SEQ_ADVBUF(8);}
end_define

begin_define
define|#
directive|define
name|SEQ_START_NOTE
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|note
parameter_list|,
name|vol
parameter_list|)
value|{_SEQ_NEEDBUF(8);\ 					_seqbuf[_seqbufptr] = SEQ_EXTENDED;\ 					_seqbuf[_seqbufptr+1] = SEQ_NOTEON;\ 					_seqbuf[_seqbufptr+2] = (dev);\ 					_seqbuf[_seqbufptr+3] = (voice);\ 					_seqbuf[_seqbufptr+4] = (note);\ 					_seqbuf[_seqbufptr+5] = (vol);\ 					_seqbuf[_seqbufptr+6] = 0;\ 					_seqbuf[_seqbufptr+7] = 0;\ 					_SEQ_ADVBUF(8);}
end_define

begin_define
define|#
directive|define
name|SEQ_STOP_NOTE
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|note
parameter_list|,
name|vol
parameter_list|)
value|{_SEQ_NEEDBUF(8);\ 					_seqbuf[_seqbufptr] = SEQ_EXTENDED;\ 					_seqbuf[_seqbufptr+1] = SEQ_NOTEOFF;\ 					_seqbuf[_seqbufptr+2] = (dev);\ 					_seqbuf[_seqbufptr+3] = (voice);\ 					_seqbuf[_seqbufptr+4] = (note);\ 					_seqbuf[_seqbufptr+5] = (vol);\ 					_seqbuf[_seqbufptr+6] = 0;\ 					_seqbuf[_seqbufptr+7] = 0;\ 					_SEQ_ADVBUF(8);}
end_define

begin_define
define|#
directive|define
name|SEQ_CHN_PRESSURE
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|pressure
parameter_list|)
value|{_SEQ_NEEDBUF(8);\ 					_seqbuf[_seqbufptr] = SEQ_EXTENDED;\ 					_seqbuf[_seqbufptr+1] = SEQ_AFTERTOUCH;\ 					_seqbuf[_seqbufptr+2] = (dev);\ 					_seqbuf[_seqbufptr+3] = (voice);\ 					_seqbuf[_seqbufptr+4] = (pressure);\ 					_seqbuf[_seqbufptr+5] = 0;\ 					_seqbuf[_seqbufptr+6] = 0;\ 					_seqbuf[_seqbufptr+7] = 0;\ 					_SEQ_ADVBUF(8);}
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
value|{_SEQ_NEEDBUF(8);\ 					_seqbuf[_seqbufptr] = SEQ_EXTENDED;\ 					_seqbuf[_seqbufptr+1] = SEQ_BALANCE;\ 					_seqbuf[_seqbufptr+2] = (dev);\ 					_seqbuf[_seqbufptr+3] = (voice);\ 					(char)_seqbuf[_seqbufptr+4] = (pos);\ 					_seqbuf[_seqbufptr+5] = 0;\ 					_seqbuf[_seqbufptr+6] = 0;\ 					_seqbuf[_seqbufptr+7] = 0;\ 					_SEQ_ADVBUF(8);}
end_define

begin_define
define|#
directive|define
name|SEQ_CONTROL
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|controller
parameter_list|,
name|value
parameter_list|)
value|{_SEQ_NEEDBUF(8);\ 					_seqbuf[_seqbufptr] = SEQ_EXTENDED;\ 					_seqbuf[_seqbufptr+1] = SEQ_CONTROLLER;\ 					_seqbuf[_seqbufptr+2] = (dev);\ 					_seqbuf[_seqbufptr+3] = (voice);\ 					_seqbuf[_seqbufptr+4] = (controller);\ 					*(short *)&_seqbuf[_seqbufptr+5] = (value);\ 					_seqbuf[_seqbufptr+7] = 0;\ 					_SEQ_ADVBUF(8);}
end_define

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
value|SEQ_CONTROL(dev, voice, CTRL_PITCH_BENDER, value)
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
value|SEQ_CONTROL(dev, voice, CTRL_PITCH_BENDER_RANGE, value)
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
value|SEQ_CONTROL(dev, voice, CTRL_EXPRESSION, value)
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
value|SEQ_CONTROL(dev, voice, CTRL_MAIN_VOLUME, value)
end_define

begin_define
define|#
directive|define
name|SEQ_START_TIMER
parameter_list|()
value|{_SEQ_NEEDBUF(4);\ 					_seqbuf[_seqbufptr] = SEQ_SYNCTIMER;\ 					_seqbuf[_seqbufptr+1] = 0;\ 					_seqbuf[_seqbufptr+2] = 0;\ 					_seqbuf[_seqbufptr+3] = 0;\ 					_SEQ_ADVBUF(4);}
end_define

begin_define
define|#
directive|define
name|SEQ_SET_PATCH
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|patch
parameter_list|)
value|{_SEQ_NEEDBUF(8);\ 					_seqbuf[_seqbufptr] = SEQ_EXTENDED;\ 					_seqbuf[_seqbufptr+1] = SEQ_PGMCHANGE;\ 					_seqbuf[_seqbufptr+2] = (dev);\ 					_seqbuf[_seqbufptr+3] = (voice);\ 					_seqbuf[_seqbufptr+4] = (patch);\ 					_seqbuf[_seqbufptr+5] = 0;\ 					_seqbuf[_seqbufptr+6] = 0;\ 					_seqbuf[_seqbufptr+7] = 0;\ 					_SEQ_ADVBUF(8);}
end_define

begin_define
define|#
directive|define
name|SEQ_WAIT_TIME
parameter_list|(
name|ticks
parameter_list|)
value|{_SEQ_NEEDBUF(4);\ 				 	*(unsigned long *)&_seqbuf[_seqbufptr] = SEQ_WAIT | ((ticks)<< 8);\ 				 	_SEQ_ADVBUF(4);}
end_define

begin_define
define|#
directive|define
name|SEQ_ECHO_BACK
parameter_list|(
name|key
parameter_list|)
value|{_SEQ_NEEDBUF(4);\ 				 	*(unsigned long *)&_seqbuf[_seqbufptr] = SEQ_ECHO | ((key)<< 8);\ 				 	_SEQ_ADVBUF(4);}
end_define

begin_define
define|#
directive|define
name|SEQ_MIDIOUT
parameter_list|(
name|device
parameter_list|,
name|byte
parameter_list|)
value|{_SEQ_NEEDBUF(4);\ 					_seqbuf[_seqbufptr] = SEQ_MIDIPUTC;\ 					_seqbuf[_seqbufptr+1] = (byte);\ 					_seqbuf[_seqbufptr+2] = (device);\ 					_seqbuf[_seqbufptr+3] = 0;\ 					_SEQ_ADVBUF(4);}
end_define

begin_define
define|#
directive|define
name|SEQ_WRPATCH
parameter_list|(
name|patchx
parameter_list|,
name|len
parameter_list|)
value|{if (_seqbufptr) seqbuf_dump();\ 					if (write(seqfd, (char*)(patchx), len)==-1) \ 					   perror("Write patch: /dev/sequencer");}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|soundcard_init
parameter_list|(
name|long
name|mem_start
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SOUNDCARD_H_ */
end_comment

end_unit

