begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Include file for midi sequencer driver.  *   * Copyright by Seigo Tanimura 1999.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * first, include kernel header files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SEQUENCER_H_
end_ifndef

begin_define
define|#
directive|define
name|_SEQUENCER_H_
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
file|<sys/kernel.h>
end_include

begin_comment
comment|/* for DATA_SET */
end_comment

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
file|<sys/condvar.h>
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
file|<sys/soundcard.h>
end_include

begin_define
define|#
directive|define
name|SEQ_CDEV_MAJOR
value|MIDI_CDEV_MAJOR
end_define

begin_comment
comment|/*  * the following assumes that FreeBSD 3.X uses poll(2) instead of select(2).  * This change dates to late 1997.  */
end_comment

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_define
define|#
directive|define
name|d_select_t
value|d_poll_t
end_define

begin_typedef
typedef|typedef
name|struct
name|_seqdev_info
name|seqdev_info
typedef|;
end_typedef

begin_comment
comment|/*  * The order of mutex lock (from the first to the last)  *  * 1. sequencer flags, queues, timer and device list  * 2. midi synth voice and channel  * 3. midi synth status  * 4. generic midi flags and queues  * 5. midi device  */
end_comment

begin_comment
comment|/*  * descriptor of sequencer operations ...  *  */
end_comment

begin_struct
struct|struct
name|_seqdev_info
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
name|d_read_t
modifier|*
name|read
decl_stmt|;
name|d_write_t
modifier|*
name|write
decl_stmt|;
name|d_ioctl_t
modifier|*
name|ioctl
decl_stmt|;
name|d_poll_t
modifier|*
name|poll
decl_stmt|;
name|midi_callback_t
modifier|*
name|callback
decl_stmt|;
comment|/* 	 * combinations of the following flags are used as second argument in 	 * the callback from the dma module to the device-specific routines. 	 */
define|#
directive|define
name|SEQ_CB_RD
value|0x100
comment|/* read callback */
define|#
directive|define
name|SEQ_CB_WR
value|0x200
comment|/* write callback */
define|#
directive|define
name|SEQ_CB_REASON_MASK
value|0xff
define|#
directive|define
name|SEQ_CB_START
value|0x01
comment|/* start dma op */
define|#
directive|define
name|SEQ_CB_STOP
value|0x03
comment|/* stop dma op */
define|#
directive|define
name|SEQ_CB_ABORT
value|0x04
comment|/* abort dma op */
define|#
directive|define
name|SEQ_CB_INIT
value|0x05
comment|/* init board parameters */
comment|/* 	 * callback extensions 	 */
define|#
directive|define
name|SEQ_CB_DMADONE
value|0x10
define|#
directive|define
name|SEQ_CB_DMAUPDATE
value|0x11
define|#
directive|define
name|SEQ_CB_DMASTOP
value|0x12
comment|/* init can only be called with int enabled and 	 * no pending DMA activity. 	 */
comment|/* 	 * whereas from here, parameters are set at runtime. 	 * io_base == 0 means that the board is not configured. 	 */
name|int
name|unit
decl_stmt|;
comment|/* unit number of the device */
name|void
modifier|*
name|softc
decl_stmt|;
comment|/* softc for a device */
name|int
name|bd_id
decl_stmt|;
comment|/* used to hold board-id info, eg. sb version, 			 * mss codec type, etc. etc. 			 */
name|struct
name|mtx
name|flagqueue_mtx
decl_stmt|;
comment|/* Mutex to protect flags and queues */
name|struct
name|cv
name|insync_cv
decl_stmt|;
comment|/* Conditional variable for sync */
comment|/* Queues */
name|midi_dbuf
name|midi_dbuf_in
decl_stmt|;
comment|/* midi input event/message queue */
name|midi_dbuf
name|midi_dbuf_out
decl_stmt|;
comment|/* midi output event/message queue */
comment|/*          * these parameters describe the operation of the board.          * Generic things like busy flag, speed, etc are here.          */
comment|/* Flags */
specifier|volatile
name|u_long
name|flags
decl_stmt|;
comment|/* 32 bits, used for various purposes. */
comment|/* 	 * we have separate flags for read and write, although in some 	 * cases this is probably not necessary (e.g. because we cannot 	 * know how many processes are using the device, we cannot 	 * distinguish if open, close, abort are for a write or for a 	 * read). 	 */
comment|/* 	 * the following flag is used by open-close routines 	 * to mark the status of the device. 	 */
define|#
directive|define
name|SEQ_F_BUSY
value|0x0001
comment|/* has been opened 	*/
comment|/* 	 * the next two are used to allow only one pending operation of 	 * each type. 	 */
define|#
directive|define
name|SEQ_F_READING
value|0x0004
comment|/* have a pending read */
define|#
directive|define
name|SEQ_F_WRITING
value|0x0008
comment|/* have a pending write */
comment|/* 	 * flag used to mark a pending close. 	 */
define|#
directive|define
name|SEQ_F_CLOSING
value|0x0040
comment|/* a pending close */
comment|/* 	 * if user has not set block size, then make it adaptive 	 * (0.25s, or the perhaps last read/write ?) 	 */
define|#
directive|define
name|SEQ_F_HAS_SIZE
value|0x0080
comment|/* user set block size */
comment|/* 	 * assorted flags related to operating mode. 	 */
define|#
directive|define
name|SEQ_F_STEREO
value|0x0100
comment|/* doing stereo */
define|#
directive|define
name|SEQ_F_NBIO
value|0x0200
comment|/* do non-blocking i/o */
comment|/* 	 * these flags mark a pending abort on a r/w operation. 	 */
define|#
directive|define
name|SEQ_F_ABORTING
value|0x1000
comment|/* a pending abort */
comment|/* 	 * this is used to mark that board initialization is needed, e.g. 	 * because of a change in sampling rate, format, etc. -- It will 	 * be done at the next convenient time. 	 */
define|#
directive|define
name|SEQ_F_INIT
value|0x4000
comment|/* changed parameters. need init */
define|#
directive|define
name|SEQ_F_INSYNC
value|0x8000
comment|/* a pending sync */
name|int
name|play_blocksize
decl_stmt|,
name|rec_blocksize
decl_stmt|;
comment|/* blocksize for io and dma ops */
define|#
directive|define
name|swsel
value|midi_dbuf_out.sel
define|#
directive|define
name|srsel
value|midi_dbuf_in.sel
name|u_long
name|interrupts
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
comment|/* The tailq entry of the next sequencer device. */
name|TAILQ_ENTRY
argument_list|(
argument|_seqdev_info
argument_list|)
name|sd_link
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
name|NSEQ_MAX
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
comment|/*  * finally, all default parameters  */
end_comment

begin_define
define|#
directive|define
name|SEQ_BUFFSIZE
value|(1024)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * some macros for debugging purposes  * DDB/DEB to enable/disable debugging stuff  * BVDDB   to enable debugging when bootverbose  */
end_comment

begin_define
define|#
directive|define
name|DDB
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|BVDDB
parameter_list|(
name|x
parameter_list|)
value|if (bootverbose) x
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEB
end_ifndef

begin_define
define|#
directive|define
name|DEB
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MIDI_DEV_SEQ
value|1
end_define

begin_comment
comment|/* Sequencer output /dev/sequencer (FM 				   synthesizer and MIDI output) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SEQUENCER_H_ */
end_comment

end_unit

