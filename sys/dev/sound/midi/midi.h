begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Include file for midi driver.  *   * Copyright by Seigo Tanimura 1999.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * first, include kernel header files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIDI_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIDI_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/* for DATA_SET */
end_comment

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus_memio.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus_pio.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_comment
comment|/* for DELAY */
end_comment

begin_include
include|#
directive|include
file|<machine/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/soundcard.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/sound/midi/miditypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/sound/midi/midibuf.h>
end_include

begin_include
include|#
directive|include
file|<dev/sound/midi/midisynth.h>
end_include

begin_define
define|#
directive|define
name|MIDI_CDEV_MAJOR
value|30
end_define

begin_comment
comment|/*#define MIDI_OUTOFGIANT*/
end_comment

begin_comment
comment|/*  * The order of mutex lock (from the first to the last)  *  * 1. sequencer flags, queues, timer and device list  * 2. midi synth voice and channel  * 3. midi synth status  * 4. generic midi flags and queues  * 5. midi device  */
end_comment

begin_comment
comment|/*  * descriptor of midi operations ...  *  */
end_comment

begin_struct
struct|struct
name|_mididev_info
block|{
comment|/* 	 * the first part of the descriptor is filled up from a 	 * template. 	 */
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
name|int
name|type
decl_stmt|;
name|d_open_t
modifier|*
name|open
decl_stmt|;
name|d_close_t
modifier|*
name|close
decl_stmt|;
name|d_ioctl_t
modifier|*
name|ioctl
decl_stmt|;
name|midi_callback_t
modifier|*
name|callback
decl_stmt|;
comment|/* 	 * combinations of the following flags are used as second argument in 	 * the callback from the dma module to the device-specific routines. 	 */
define|#
directive|define
name|MIDI_CB_RD
value|0x100
comment|/* read callback */
define|#
directive|define
name|MIDI_CB_WR
value|0x200
comment|/* write callback */
define|#
directive|define
name|MIDI_CB_REASON_MASK
value|0xff
define|#
directive|define
name|MIDI_CB_START
value|0x01
comment|/* start dma op */
define|#
directive|define
name|MIDI_CB_STOP
value|0x03
comment|/* stop dma op */
define|#
directive|define
name|MIDI_CB_ABORT
value|0x04
comment|/* abort dma op */
define|#
directive|define
name|MIDI_CB_INIT
value|0x05
comment|/* init board parameters */
comment|/* 	 * callback extensions 	 */
define|#
directive|define
name|MIDI_CB_DMADONE
value|0x10
define|#
directive|define
name|MIDI_CB_DMAUPDATE
value|0x11
define|#
directive|define
name|MIDI_CB_DMASTOP
value|0x12
comment|/* init can only be called with int enabled and 	 * no pending DMA activity. 	 */
comment|/* 	 * whereas from here, parameters are set at runtime. 	 * resources are stored in the softc of the device, 	 * not in the common structure. 	 */
name|int
name|unit
decl_stmt|;
comment|/* unit number of the device */
name|int
name|midiunit
decl_stmt|;
comment|/* unit number for midi devices */
name|int
name|synthunit
decl_stmt|;
comment|/* unit number for synth devices */
name|int
name|mdtype
decl_stmt|;
comment|/* MDT_MIDI or MDT_SYNTH */
name|void
modifier|*
name|softc
decl_stmt|;
comment|/* softc for the device */
name|device_t
name|dev
decl_stmt|;
comment|/* device_t for the device */
name|int
name|bd_id
decl_stmt|;
comment|/* used to hold board-id info, eg. sb version, 				 * mss codec type, etc. etc. 				 */
name|struct
name|mtx
name|flagqueue_mtx
decl_stmt|;
comment|/* Mutex to protect flags and queues */
comment|/* Queues */
name|midi_dbuf
name|midi_dbuf_in
decl_stmt|;
comment|/* midi input event/message queue */
name|midi_dbuf
name|midi_dbuf_out
decl_stmt|;
comment|/* midi output event/message queue */
name|midi_dbuf
name|midi_dbuf_passthru
decl_stmt|;
comment|/* midi passthru event/message queue */
comment|/*          * these parameters describe the operation of the board.          * Generic things like busy flag, speed, etc are here.          */
comment|/* Flags */
specifier|volatile
name|u_long
name|flags
decl_stmt|;
comment|/* 32 bits, used for various purposes. */
name|int
name|fflags
decl_stmt|;
comment|/* file flag */
comment|/* 	 * we have separate flags for read and write, although in some 	 * cases this is probably not necessary (e.g. because we cannot 	 * know how many processes are using the device, we cannot 	 * distinguish if open, close, abort are for a write or for a 	 * read). 	 */
comment|/* 	 * the following flag is used by open-close routines 	 * to mark the status of the device. 	 */
define|#
directive|define
name|MIDI_F_BUSY
value|0x0001
comment|/* has been opened 	*/
comment|/* 	 * the next two are used to allow only one pending operation of 	 * each type. 	 */
define|#
directive|define
name|MIDI_F_READING
value|0x0004
comment|/* have a pending read */
define|#
directive|define
name|MIDI_F_WRITING
value|0x0008
comment|/* have a pending write */
comment|/* 	 * flag used to mark a pending close. 	 */
define|#
directive|define
name|MIDI_F_CLOSING
value|0x0040
comment|/* a pending close */
comment|/* 	 * if user has not set block size, then make it adaptive 	 * (0.25s, or the perhaps last read/write ?) 	 */
define|#
directive|define
name|MIDI_F_HAS_SIZE
value|0x0080
comment|/* user set block size */
comment|/* 	 * assorted flags related to operating mode. 	 */
define|#
directive|define
name|MIDI_F_STEREO
value|0x0100
comment|/* doing stereo */
define|#
directive|define
name|MIDI_F_NBIO
value|0x0200
comment|/* do non-blocking i/o */
define|#
directive|define
name|MIDI_F_PASSTHRU
value|0x0400
comment|/* pass received data to output port */
comment|/* 	 * these flags mark a pending abort on a r/w operation. 	 */
define|#
directive|define
name|MIDI_F_ABORTING
value|0x1000
comment|/* a pending abort */
comment|/* 	 * this is used to mark that board initialization is needed, e.g. 	 * because of a change in sampling rate, format, etc. -- It will 	 * be done at the next convenient time. 	 */
define|#
directive|define
name|MIDI_F_INIT
value|0x4000
comment|/* changed parameters. need init */
name|int
name|play_blocksize
decl_stmt|,
name|rec_blocksize
decl_stmt|;
comment|/* blocksize for io and dma ops */
define|#
directive|define
name|mwsel
value|midi_dbuf_out.sel
define|#
directive|define
name|mrsel
value|midi_dbuf_in.sel
name|u_long
name|nterrupts
decl_stmt|;
comment|/* counter of interrupts */
name|u_long
name|magic
decl_stmt|;
define|#
directive|define
name|MAGIC
parameter_list|(
name|unit
parameter_list|)
value|( 0xa4d10de0 + unit )
name|void
modifier|*
name|device_data
decl_stmt|;
comment|/* just in case it is needed...*/
name|midi_intr_t
modifier|*
name|intr
decl_stmt|;
comment|/* interrupt handler of the upper layer (ie sequencer) */
name|void
modifier|*
name|intrarg
decl_stmt|;
comment|/* argument to interrupt handler */
comment|/* The following is the interface from a midi sequencer to a midi device. */
name|synthdev_info
name|synth
decl_stmt|;
comment|/* This is the status message to display via /dev/midistat */
name|char
name|midistat
index|[
literal|128
index|]
decl_stmt|;
comment|/* The tailq entry of the next midi device. */
name|TAILQ_ENTRY
argument_list|(
argument|_mididev_info
argument_list|)
name|md_link
expr_stmt|;
comment|/* The tailq entry of the next midi device opened by a sequencer. */
name|TAILQ_ENTRY
argument_list|(
argument|_mididev_info
argument_list|)
name|md_linkseq
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * then ioctls and other stuff  */
end_comment

begin_define
define|#
directive|define
name|NMIDI_MAX
value|16
end_define

begin_comment
comment|/* Number of supported devices */
end_comment

begin_comment
comment|/*  * many variables should be reduced to a range. Here define a macro  */
end_comment

begin_define
define|#
directive|define
name|RANGE
parameter_list|(
name|var
parameter_list|,
name|low
parameter_list|,
name|high
parameter_list|)
value|(var) = \ ((var)<(low)?(low) : (var)>(high)?(high) : (var))
end_define

begin_comment
comment|/*  * convert dev_t to unit and dev  */
end_comment

begin_define
define|#
directive|define
name|MIDIMINOR
parameter_list|(
name|x
parameter_list|)
value|(minor(x))
end_define

begin_define
define|#
directive|define
name|MIDIUNIT
parameter_list|(
name|x
parameter_list|)
value|((MIDIMINOR(x)& 0x000000f0)>> 4)
end_define

begin_define
define|#
directive|define
name|MIDIDEV
parameter_list|(
name|x
parameter_list|)
value|(MIDIMINOR(x)& 0x0000000f)
end_define

begin_define
define|#
directive|define
name|MIDIMKMINOR
parameter_list|(
name|u
parameter_list|,
name|d
parameter_list|)
value|(((u)& 0x0f)<< 4 | ((d)& 0x0f))
end_define

begin_define
define|#
directive|define
name|MIDIMKDEV
parameter_list|(
name|m
parameter_list|,
name|u
parameter_list|,
name|d
parameter_list|)
value|(makedev((m), MIDIMKMINOR((u), (d))))
end_define

begin_comment
comment|/*  * see if the device is configured  */
end_comment

begin_define
define|#
directive|define
name|MIDICONFED
parameter_list|(
name|x
parameter_list|)
value|((x)->ioctl != NULL)
end_define

begin_comment
comment|/*  * finally, all default parameters  */
end_comment

begin_define
define|#
directive|define
name|MIDI_BUFFSIZE
value|(1024)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* This is the generic midi drvier initializer. */
end_comment

begin_function_decl
name|int
name|midiinit
parameter_list|(
name|mididev_info
modifier|*
name|d
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This provides an access to the mididev_info. */
end_comment

begin_function_decl
name|mididev_info
modifier|*
name|get_mididev_info
parameter_list|(
name|dev_t
name|i_dev
parameter_list|,
name|int
modifier|*
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mididev_info
modifier|*
name|get_mididev_info_unit
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mididev_info
modifier|*
name|get_mididev_midi_unit
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mididev_info
modifier|*
name|get_mididev_synth_unit
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mididev_info
modifier|*
name|create_mididev_info_unit
parameter_list|(
name|int
name|type
parameter_list|,
name|mididev_info
modifier|*
name|mdinf
parameter_list|,
name|synthdev_info
modifier|*
name|syninf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mididev_info_number
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mididev_midi_number
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mididev_synth_number
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MDT_MIDI
value|(0)
end_define

begin_define
define|#
directive|define
name|MDT_SYNTH
value|(1)
end_define

begin_comment
comment|/* These are the generic methods for a midi driver. */
end_comment

begin_decl_stmt
name|d_open_t
name|midi_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|midi_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|midi_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|midi_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|midi_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_poll_t
name|midi_poll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Common interrupt handler */
end_comment

begin_function_decl
name|void
name|midi_intr
parameter_list|(
name|mididev_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sync output */
end_comment

begin_function_decl
name|int
name|midi_sync
parameter_list|(
name|mididev_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|_midi_cmdtab
block|{
name|int
name|cmd
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_midi_cmdtab
name|midi_cmdtab
typedef|;
end_typedef

begin_function_decl
name|char
modifier|*
name|midi_cmdname
parameter_list|(
name|int
name|cmd
parameter_list|,
name|midi_cmdtab
modifier|*
name|tab
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_midi
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|midi_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MIDI_DEBUG
parameter_list|(
name|x
parameter_list|)
define|\
value|do {				\ 		if (midi_debug) {	\ 			(x);		\ 		}			\ 	} while(0)
end_define

begin_decl_stmt
specifier|extern
name|midi_cmdtab
name|cmdtab_midiioctl
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Minor numbers for the midi driver.  */
end_comment

begin_define
define|#
directive|define
name|MIDI_DEV_MIDIN
value|2
end_define

begin_comment
comment|/* Raw midi access */
end_comment

begin_define
define|#
directive|define
name|MIDI_DEV_STATUS
value|15
end_define

begin_comment
comment|/* /dev/midistat */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIDI_H_ */
end_comment

end_unit

