begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TWE_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {										\ 	    if (level<= TWE_DEBUG) printf("%s: " fmt "\n", __FUNCTION__ , ##args);	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|debug_called
parameter_list|(
name|level
parameter_list|)
define|\
value|do {								\ 	    if (level<= TWE_DEBUG) printf(__FUNCTION__ ": called\n");	\ 	} while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|debug_called
parameter_list|(
name|level
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure describing a logical unit as attached to the controller  */
end_comment

begin_struct
struct|struct
name|twe_drive
block|{
comment|/* unit properties */
name|u_int32_t
name|td_size
decl_stmt|;
name|int
name|td_cylinders
decl_stmt|;
name|int
name|td_heads
decl_stmt|;
name|int
name|td_sectors
decl_stmt|;
name|int
name|td_unit
decl_stmt|;
comment|/* unit state and type */
name|u_int8_t
name|td_state
decl_stmt|;
name|u_int8_t
name|td_type
decl_stmt|;
comment|/* handle for attached driver */
name|device_t
name|td_disk
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-command control structure.  *  * Note that due to alignment constraints on the tc_command field, this *must* be 64-byte aligned.  * We achieve this by placing the command at the beginning of the structure, and using malloc()  * to allocate each structure.  */
end_comment

begin_struct
struct|struct
name|twe_request
block|{
comment|/* controller command */
name|TWE_Command
name|tr_command
decl_stmt|;
comment|/* command as submitted to controller */
comment|/* command payload */
name|void
modifier|*
name|tr_data
decl_stmt|;
comment|/* data buffer */
name|void
modifier|*
name|tr_realdata
decl_stmt|;
comment|/* copy of real data buffer pointer for alignment fixup */
name|size_t
name|tr_length
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|twe_request
argument_list|)
name|tr_link
expr_stmt|;
comment|/* list linkage */
name|struct
name|twe_softc
modifier|*
name|tr_sc
decl_stmt|;
comment|/* controller that owns us */
name|int
name|tr_status
decl_stmt|;
comment|/* command status */
define|#
directive|define
name|TWE_CMD_SETUP
value|0
comment|/* being assembled */
define|#
directive|define
name|TWE_CMD_BUSY
value|1
comment|/* submitted to controller */
define|#
directive|define
name|TWE_CMD_COMPLETE
value|2
comment|/* completed by controller (maybe with error) */
name|int
name|tr_flags
decl_stmt|;
define|#
directive|define
name|TWE_CMD_DATAIN
value|(1<<0)
define|#
directive|define
name|TWE_CMD_DATAOUT
value|(1<<1)
define|#
directive|define
name|TWE_CMD_ALIGNBUF
value|(1<<2)
comment|/* data in bio is misaligned, have to copy to/from private buffer */
define|#
directive|define
name|TWE_CMD_SLEEPER
value|(1<<3)
comment|/* owner is sleeping on this command */
name|void
function_decl|(
modifier|*
name|tr_complete
function_decl|)
parameter_list|(
name|struct
name|twe_request
modifier|*
name|tr
parameter_list|)
function_decl|;
comment|/* completion handler */
name|void
modifier|*
name|tr_private
decl_stmt|;
comment|/* submitter-private data or wait channel */
name|TWE_PLATFORM_REQUEST
comment|/* platform-specific request elements */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-controller state.  */
end_comment

begin_struct
struct|struct
name|twe_softc
block|{
comment|/* controller queues and arrays */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|twe_request
argument_list|)
name|twe_free
expr_stmt|;
comment|/* command structures available for reuse */
name|twe_bioq
name|twe_bioq
decl_stmt|;
comment|/* outstanding I/O operations */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|twe_request
argument_list|)
name|twe_ready
expr_stmt|;
comment|/* requests ready for the controller */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|twe_request
argument_list|)
name|twe_busy
expr_stmt|;
comment|/* requests busy in the controller */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|twe_request
argument_list|)
name|twe_complete
expr_stmt|;
comment|/* active commands (busy or waiting for completion) */
name|struct
name|twe_request
modifier|*
name|twe_lookup
index|[
name|TWE_Q_LENGTH
index|]
decl_stmt|;
comment|/* commands indexed by request ID */
name|struct
name|twe_drive
name|twe_drive
index|[
name|TWE_MAX_UNITS
index|]
decl_stmt|;
comment|/* attached drives */
comment|/* asynchronous event handling */
name|u_int16_t
name|twe_aen_queue
index|[
name|TWE_Q_LENGTH
index|]
decl_stmt|;
comment|/* AENs queued for userland tool(s) */
name|int
name|twe_aen_head
decl_stmt|,
name|twe_aen_tail
decl_stmt|;
comment|/* ringbuffer pointers for AEN queue */
name|int
name|twe_wait_aen
decl_stmt|;
comment|/* wait-for-aen notification */
comment|/* controller status */
name|int
name|twe_state
decl_stmt|;
define|#
directive|define
name|TWE_STATE_INTEN
value|(1<<0)
comment|/* interrupts have been enabled */
define|#
directive|define
name|TWE_STATE_SHUTDOWN
value|(1<<1)
comment|/* controller is shut down */
define|#
directive|define
name|TWE_STATE_OPEN
value|(1<<2)
comment|/* control device is open */
define|#
directive|define
name|TWE_STATE_SUSPEND
value|(1<<3)
comment|/* controller is suspended */
name|int
name|twe_host_id
decl_stmt|;
name|struct
name|twe_qstat
name|twe_qstat
index|[
name|TWEQ_COUNT
index|]
decl_stmt|;
comment|/* queue statistics */
name|TWE_PLATFORM_SOFTC
comment|/* platform-specific softc elements */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interface betwen driver core and platform-dependant code.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|twe_setup
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* do early driver/controller setup */
end_comment

begin_function_decl
specifier|extern
name|void
name|twe_init
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* init controller */
end_comment

begin_function_decl
specifier|extern
name|void
name|twe_deinit
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stop controller */
end_comment

begin_function_decl
specifier|extern
name|void
name|twe_intr
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* hardware interrupt signalled */
end_comment

begin_function_decl
specifier|extern
name|void
name|twe_startio
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|twe_dump_blocks
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|,
name|int
name|unit
parameter_list|,
comment|/* crashdump block write */
name|u_int32_t
name|lba
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|nblks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|twe_ioctl
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* handle user request */
end_comment

begin_function_decl
specifier|extern
name|void
name|twe_describe_controller
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* print controller info */
end_comment

begin_function_decl
specifier|extern
name|void
name|twe_print_controller
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|twe_enable_interrupts
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* enable controller interrupts */
end_comment

begin_function_decl
specifier|extern
name|void
name|twe_disable_interrupts
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* disable controller interrupts */
end_comment

begin_function_decl
specifier|extern
name|void
name|twe_attach_drive
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|twe_drive
modifier|*
name|dr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* attach drive when found in twe_init */
end_comment

begin_function_decl
specifier|extern
name|void
name|twed_intr
parameter_list|(
name|twe_bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return bio from core */
end_comment

begin_function_decl
specifier|extern
name|struct
name|twe_request
modifier|*
name|twe_allocate_request
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* allocate request structure */
end_comment

begin_function_decl
specifier|extern
name|void
name|twe_free_request
parameter_list|(
name|struct
name|twe_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* free request structure */
end_comment

begin_function_decl
specifier|extern
name|void
name|twe_map_request
parameter_list|(
name|struct
name|twe_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* make request visible to controller, do s/g */
end_comment

begin_function_decl
specifier|extern
name|void
name|twe_unmap_request
parameter_list|(
name|struct
name|twe_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cleanup after transfer, unmap */
end_comment

begin_comment
comment|/********************************************************************************  * Queue primitives  */
end_comment

begin_define
define|#
directive|define
name|TWEQ_ADD
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
define|\
value|do {							\ 	    struct twe_qstat *qs =&(sc)->twe_qstat[qname];	\ 								\ 	    qs->q_length++;					\ 	    if (qs->q_length> qs->q_max)			\ 		qs->q_max = qs->q_length;			\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|TWEQ_REMOVE
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
value|(sc)->twe_qstat[qname].q_length--
end_define

begin_define
define|#
directive|define
name|TWEQ_INIT
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
define|\
value|do {					\ 	    sc->twe_qstat[qname].q_length = 0;	\ 	    sc->twe_qstat[qname].q_max = 0;	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|TWEQ_REQUEST_QUEUE
parameter_list|(
name|name
parameter_list|,
name|index
parameter_list|)
define|\
value|static __inline void							\ twe_initq_ ## name (struct twe_softc *sc)				\ {									\     TAILQ_INIT(&sc->twe_ ## name);					\     TWEQ_INIT(sc, index);						\ }									\ static __inline void							\ twe_enqueue_ ## name (struct twe_request *tr)				\ {									\     int		s;							\ 									\     s = splbio();							\     TAILQ_INSERT_TAIL(&tr->tr_sc->twe_ ## name, tr, tr_link);		\     TWEQ_ADD(tr->tr_sc, index);						\     splx(s);								\ }									\ static __inline void							\ twe_requeue_ ## name (struct twe_request *tr)				\ {									\     int		s;							\ 									\     s = splbio();							\     TAILQ_INSERT_HEAD(&tr->tr_sc->twe_ ## name, tr, tr_link);		\     TWEQ_ADD(tr->tr_sc, index);						\     splx(s);								\ }									\ static __inline struct twe_request *					\ twe_dequeue_ ## name (struct twe_softc *sc)				\ {									\     struct twe_request	*tr;						\     int			s;						\ 									\     s = splbio();							\     if ((tr = TAILQ_FIRST(&sc->twe_ ## name)) != NULL) {		\ 	TAILQ_REMOVE(&sc->twe_ ## name, tr, tr_link);			\ 	TWEQ_REMOVE(sc, index);						\     }									\     splx(s);								\     return(tr);								\ }									\ static __inline void							\ twe_remove_ ## name (struct twe_request *tr)				\ {									\     int			s;						\ 									\     s = splbio();							\     TAILQ_REMOVE(&tr->tr_sc->twe_ ## name, tr, tr_link);		\     TWEQ_REMOVE(tr->tr_sc, index);					\     splx(s);								\ }
end_define

begin_macro
name|TWEQ_REQUEST_QUEUE
argument_list|(
argument|free
argument_list|,
argument|TWEQ_FREE
argument_list|)
end_macro

begin_macro
name|TWEQ_REQUEST_QUEUE
argument_list|(
argument|ready
argument_list|,
argument|TWEQ_READY
argument_list|)
end_macro

begin_macro
name|TWEQ_REQUEST_QUEUE
argument_list|(
argument|busy
argument_list|,
argument|TWEQ_BUSY
argument_list|)
end_macro

begin_macro
name|TWEQ_REQUEST_QUEUE
argument_list|(
argument|complete
argument_list|,
argument|TWEQ_COMPLETE
argument_list|)
end_macro

begin_comment
comment|/*  * outstanding bio queue  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|twe_initq_bio
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|)
block|{
name|TWE_BIO_QINIT
argument_list|(
name|sc
operator|->
name|twe_bioq
argument_list|)
expr_stmt|;
name|TWEQ_INIT
argument_list|(
name|sc
argument_list|,
name|TWEQ_BIO
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|twe_enqueue_bio
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|TWE_BIO_QINSERT
argument_list|(
name|sc
operator|->
name|twe_bioq
argument_list|,
name|bp
argument_list|)
expr_stmt|;
name|TWEQ_ADD
argument_list|(
name|sc
argument_list|,
name|TWEQ_BIO
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|bio
operator|*
name|twe_dequeue_bio
argument_list|(
argument|struct twe_softc *sc
argument_list|)
block|{
name|int
name|s
block|;     struct
name|bio
operator|*
name|bp
block|;
name|s
operator|=
name|splbio
argument_list|()
block|;
if|if
condition|(
operator|(
name|bp
operator|=
name|TWE_BIO_QFIRST
argument_list|(
name|sc
operator|->
name|twe_bioq
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|TWE_BIO_QREMOVE
argument_list|(
name|sc
operator|->
name|twe_bioq
argument_list|,
name|bp
argument_list|)
expr_stmt|;
name|TWEQ_REMOVE
argument_list|(
name|sc
argument_list|,
name|TWEQ_BIO
argument_list|)
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|bp
operator|)
return|;
end_return

unit|}
end_unit

