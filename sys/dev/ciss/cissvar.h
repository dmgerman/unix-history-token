begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * CISS adapter driver datastructures  */
end_comment

begin_comment
comment|/************************************************************************  * Tunable parameters  */
end_comment

begin_comment
comment|/*  * There is no guaranteed upper bound on the number of concurrent  * commands an adapter may claim to support.  Cap it at a reasonable  * value.  */
end_comment

begin_define
define|#
directive|define
name|CISS_MAX_REQUESTS
value|256
end_define

begin_comment
comment|/*  * Maximum number of logical drives we support.  */
end_comment

begin_define
define|#
directive|define
name|CISS_MAX_LOGICAL
value|15
end_define

begin_comment
comment|/*  * Maximum number of physical devices we support.  */
end_comment

begin_define
define|#
directive|define
name|CISS_MAX_PHYSICAL
value|1024
end_define

begin_comment
comment|/*  * Interrupt reduction can be controlled by tuning the interrupt  * coalesce delay and count paramters.  The delay (in microseconds)  * defers delivery of interrupts to increase the chance of there being  * more than one completed command ready when the interrupt is  * delivered.  The count expedites the delivery of the interrupt when  * the given number of commands are ready.  *  * If the delay is set to 0, interrupts are delivered immediately.  */
end_comment

begin_define
define|#
directive|define
name|CISS_INTERRUPT_COALESCE_DELAY
value|1000
end_define

begin_define
define|#
directive|define
name|CISS_INTERRUPT_COALESCE_COUNT
value|16
end_define

begin_comment
comment|/*  * Heartbeat routine timeout in seconds.  Note that since event  * handling is performed on a callback basis, we don't need this to  * run very often.  */
end_comment

begin_define
define|#
directive|define
name|CISS_HEARTBEAT_RATE
value|10
end_define

begin_comment
comment|/************************************************************************  * Compatibility with older versions of FreeBSD  */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|440001
end_if

begin_warning
warning|#
directive|warning
warning|testing old-FreeBSD compat
end_warning

begin_typedef
typedef|typedef
name|struct
name|proc
name|d_thread_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************************************************  * Command queue statistics  */
end_comment

begin_define
define|#
directive|define
name|CISSQ_FREE
value|0
end_define

begin_define
define|#
directive|define
name|CISSQ_BUSY
value|1
end_define

begin_define
define|#
directive|define
name|CISSQ_COMPLETE
value|2
end_define

begin_define
define|#
directive|define
name|CISSQ_NOTIFY
value|3
end_define

begin_define
define|#
directive|define
name|CISSQ_COUNT
value|4
end_define

begin_struct
struct|struct
name|ciss_qstat
block|{
name|u_int32_t
name|q_length
decl_stmt|;
name|u_int32_t
name|q_max
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/************************************************************************  * Driver version.  Only really significant to the ACU interface.  */
end_comment

begin_define
define|#
directive|define
name|CISS_DRIVER_VERSION
value|20011201
end_define

begin_comment
comment|/************************************************************************  * Driver data structures  */
end_comment

begin_comment
comment|/*  * Each command issued to the adapter is managed by a request  * structure.  */
end_comment

begin_struct
struct|struct
name|ciss_request
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ciss_request
argument_list|)
name|cr_link
expr_stmt|;
name|int
name|cr_onq
decl_stmt|;
comment|/* which queue we are on */
name|struct
name|ciss_softc
modifier|*
name|cr_sc
decl_stmt|;
comment|/* controller softc */
name|void
modifier|*
name|cr_data
decl_stmt|;
comment|/* data buffer */
name|u_int32_t
name|cr_length
decl_stmt|;
comment|/* data length */
name|bus_dmamap_t
name|cr_datamap
decl_stmt|;
comment|/* DMA map for data */
name|int
name|cr_tag
decl_stmt|;
name|int
name|cr_flags
decl_stmt|;
define|#
directive|define
name|CISS_REQ_MAPPED
value|(1<<0)
comment|/* data mapped */
define|#
directive|define
name|CISS_REQ_SLEEP
value|(1<<1)
comment|/* submitter sleeping */
define|#
directive|define
name|CISS_REQ_POLL
value|(1<<2)
comment|/* submitter polling */
define|#
directive|define
name|CISS_REQ_DATAOUT
value|(1<<3)
comment|/* data host->adapter */
define|#
directive|define
name|CISS_REQ_DATAIN
value|(1<<4)
comment|/* data adapter->host */
name|void
function_decl|(
modifier|*
name|cr_complete
function_decl|)
parameter_list|(
name|struct
name|ciss_request
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|cr_private
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The adapter command structure is defined with a zero-length  * scatter/gather list size.  In practise, we want space for a  * scatter-gather list, and we also want to avoid having commands  * cross page boundaries.  *  * Note that 512 bytes yields 28 scatter/gather entries, or the  * ability to map (26 * PAGE_SIZE) + 2 bytes of data.  On x86, this is  * 104kB.  256 bytes would only yield 12 entries, giving a mere 40kB,  * too small.  */
end_comment

begin_define
define|#
directive|define
name|CISS_COMMAND_ALLOC_SIZE
value|512
end_define

begin_comment
comment|/* XXX tune to get sensible s/g list length */
end_comment

begin_define
define|#
directive|define
name|CISS_COMMAND_SG_LENGTH
value|((CISS_COMMAND_ALLOC_SIZE - sizeof(struct ciss_command)) \ 				 / sizeof(struct ciss_sg_entry))
end_define

begin_comment
comment|/*  * Per-logical-drive data.  */
end_comment

begin_struct
struct|struct
name|ciss_ldrive
block|{
name|union
name|ciss_device_address
name|cl_address
decl_stmt|;
name|union
name|ciss_device_address
modifier|*
name|cl_controller
decl_stmt|;
name|int
name|cl_status
decl_stmt|;
define|#
directive|define
name|CISS_LD_NONEXISTENT
value|0
define|#
directive|define
name|CISS_LD_ONLINE
value|1
define|#
directive|define
name|CISS_LD_OFFLINE
value|2
name|int
name|cl_update
decl_stmt|;
name|struct
name|ciss_bmic_id_ldrive
modifier|*
name|cl_ldrive
decl_stmt|;
name|struct
name|ciss_bmic_id_lstatus
modifier|*
name|cl_lstatus
decl_stmt|;
name|struct
name|ciss_ldrive_geometry
name|cl_geometry
decl_stmt|;
name|char
name|cl_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* device name */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-physical-drive data  */
end_comment

begin_struct
struct|struct
name|ciss_pdrive
block|{
name|union
name|ciss_device_address
name|cp_address
decl_stmt|;
name|int
name|cp_online
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CISS_PHYSICAL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|CISS_PHYSICAL_BASE
value|(1<< CISS_PHYSICAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|CISS_MAX_PHYSTGT
value|15
end_define

begin_define
define|#
directive|define
name|CISS_IS_PHYSICAL
parameter_list|(
name|bus
parameter_list|)
value|(bus>= CISS_PHYSICAL_BASE)
end_define

begin_define
define|#
directive|define
name|CISS_CAM_TO_PBUS
parameter_list|(
name|bus
parameter_list|)
value|(bus - CISS_PHYSICAL_BASE)
end_define

begin_comment
comment|/*  * Per-adapter data  */
end_comment

begin_struct
struct|struct
name|ciss_softc
block|{
comment|/* bus connections */
name|device_t
name|ciss_dev
decl_stmt|;
comment|/* bus attachment */
name|struct
name|cdev
modifier|*
name|ciss_dev_t
decl_stmt|;
comment|/* control device */
name|struct
name|resource
modifier|*
name|ciss_regs_resource
decl_stmt|;
comment|/* register interface window */
name|int
name|ciss_regs_rid
decl_stmt|;
comment|/* resource ID */
name|bus_space_handle_t
name|ciss_regs_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|ciss_regs_btag
decl_stmt|;
comment|/* bus space tag */
name|struct
name|resource
modifier|*
name|ciss_cfg_resource
decl_stmt|;
comment|/* config struct interface window */
name|int
name|ciss_cfg_rid
decl_stmt|;
comment|/* resource ID */
name|struct
name|ciss_config_table
modifier|*
name|ciss_cfg
decl_stmt|;
comment|/* config table in adapter memory */
name|struct
name|ciss_bmic_id_table
modifier|*
name|ciss_id
decl_stmt|;
comment|/* ID table in host memory */
name|u_int32_t
name|ciss_heartbeat
decl_stmt|;
comment|/* last heartbeat value */
name|int
name|ciss_heart_attack
decl_stmt|;
comment|/* number of times we have seen this value */
name|struct
name|resource
modifier|*
name|ciss_irq_resource
decl_stmt|;
comment|/* interrupt */
name|int
name|ciss_irq_rid
decl_stmt|;
comment|/* resource ID */
name|void
modifier|*
name|ciss_intr
decl_stmt|;
comment|/* interrupt handle */
name|bus_dma_tag_t
name|ciss_parent_dmat
decl_stmt|;
comment|/* parent DMA tag */
name|bus_dma_tag_t
name|ciss_buffer_dmat
decl_stmt|;
comment|/* data buffer/command DMA tag */
name|u_int32_t
name|ciss_interrupt_mask
decl_stmt|;
comment|/* controller interrupt mask bits */
name|int
name|ciss_max_requests
decl_stmt|;
name|struct
name|ciss_request
name|ciss_request
index|[
name|CISS_MAX_REQUESTS
index|]
decl_stmt|;
comment|/* requests */
name|void
modifier|*
name|ciss_command
decl_stmt|;
comment|/* command structures */
name|bus_dma_tag_t
name|ciss_command_dmat
decl_stmt|;
comment|/* command DMA tag */
name|bus_dmamap_t
name|ciss_command_map
decl_stmt|;
comment|/* command DMA map */
name|u_int32_t
name|ciss_command_phys
decl_stmt|;
comment|/* command array base address */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ciss_request
argument_list|)
name|ciss_free
expr_stmt|;
comment|/* requests available for reuse */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ciss_request
argument_list|)
name|ciss_busy
expr_stmt|;
comment|/* requests in the adapter */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ciss_request
argument_list|)
name|ciss_complete
expr_stmt|;
comment|/* requests which have been returned by the adapter */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ciss_request
argument_list|)
name|ciss_notify
expr_stmt|;
comment|/* requests which are defered for processing */
name|struct
name|proc
modifier|*
name|ciss_notify_thread
decl_stmt|;
name|struct
name|callout
name|ciss_periodic
decl_stmt|;
comment|/* periodic event handling */
name|struct
name|ciss_request
modifier|*
name|ciss_periodic_notify
decl_stmt|;
comment|/* notify callback request */
name|struct
name|mtx
name|ciss_mtx
decl_stmt|;
name|struct
name|ciss_ldrive
modifier|*
modifier|*
name|ciss_logical
decl_stmt|;
name|struct
name|ciss_pdrive
modifier|*
modifier|*
name|ciss_physical
decl_stmt|;
name|union
name|ciss_device_address
modifier|*
name|ciss_controllers
decl_stmt|;
comment|/* controller address */
name|int
name|ciss_max_bus_number
decl_stmt|;
comment|/* maximum bus number */
name|int
name|ciss_max_logical_bus
decl_stmt|;
name|int
name|ciss_max_physical_bus
decl_stmt|;
name|struct
name|cam_devq
modifier|*
name|ciss_cam_devq
decl_stmt|;
name|struct
name|cam_sim
modifier|*
modifier|*
name|ciss_cam_sim
decl_stmt|;
name|int
name|ciss_soft_reset
decl_stmt|;
name|int
name|ciss_flags
decl_stmt|;
define|#
directive|define
name|CISS_FLAG_NOTIFY_OK
value|(1<<0)
comment|/* notify command running OK */
define|#
directive|define
name|CISS_FLAG_CONTROL_OPEN
value|(1<<1)
comment|/* control device is open */
define|#
directive|define
name|CISS_FLAG_ABORTING
value|(1<<2)
comment|/* driver is going away */
define|#
directive|define
name|CISS_FLAG_RUNNING
value|(1<<3)
comment|/* driver is running (interrupts usable) */
define|#
directive|define
name|CISS_FLAG_FAKE_SYNCH
value|(1<<16)
comment|/* needs SYNCHRONISE_CACHE faked */
define|#
directive|define
name|CISS_FLAG_BMIC_ABORT
value|(1<<17)
comment|/* use BMIC command to abort Notify on Event */
define|#
directive|define
name|CISS_FLAG_THREAD_SHUT
value|(1<<20)
comment|/* shutdown the kthread */
name|struct
name|ciss_qstat
name|ciss_qstat
index|[
name|CISSQ_COUNT
index|]
decl_stmt|;
comment|/* queue statistics */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Given a request tag, find the corresponding command in virtual or  * physical space.  *  * The arithmetic here is due to the allocation of ciss_command structures  * inside CISS_COMMAND_ALLOC_SIZE blocks.  See the comment at the definition  * of CISS_COMMAND_ALLOC_SIZE above.  */
end_comment

begin_define
define|#
directive|define
name|CISS_FIND_COMMAND
parameter_list|(
name|cr
parameter_list|)
define|\
value|(struct ciss_command *)((u_int8_t *)(cr)->cr_sc->ciss_command +		\ 				((cr)->cr_tag * CISS_COMMAND_ALLOC_SIZE))
end_define

begin_define
define|#
directive|define
name|CISS_FIND_COMMANDPHYS
parameter_list|(
name|cr
parameter_list|)
value|((cr)->cr_sc->ciss_command_phys + \ 					 ((cr)->cr_tag * CISS_COMMAND_ALLOC_SIZE))
end_define

begin_comment
comment|/************************************************************************  * Debugging/diagnostic output.  */
end_comment

begin_comment
comment|/*  * Debugging levels:  *  0 - quiet, only emit warnings  *  1 - talkative, log major events, but nothing on the I/O path  *  2 - noisy, log events on the I/O path  *  3 - extremely noisy, log items in loops  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CISS_DEBUG
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
value|do {										\ 	    if (level<= CISS_DEBUG) printf("%s: " fmt "\n", __func__ , ##args);	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|debug_called
parameter_list|(
name|level
parameter_list|)
define|\
value|do {								\ 	    if (level<= CISS_DEBUG) printf("%s: called\n", __func__);	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|debug_struct
parameter_list|(
name|s
parameter_list|)
value|printf("  SIZE %s: %zu\n", #s, sizeof(struct s))
end_define

begin_define
define|#
directive|define
name|debug_union
parameter_list|(
name|s
parameter_list|)
value|printf("  SIZE %s: %zu\n", #s, sizeof(union s))
end_define

begin_define
define|#
directive|define
name|debug_type
parameter_list|(
name|s
parameter_list|)
value|printf("  SIZE %s: %zu\n", #s, sizeof(s))
end_define

begin_define
define|#
directive|define
name|debug_field
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|printf("  OFFSET %s.%s: %d\n", #s, #f, ((int)&(((struct s *)0)->f)))
end_define

begin_define
define|#
directive|define
name|debug_const
parameter_list|(
name|c
parameter_list|)
value|printf("  CONST %s %jd/0x%jx\n", #c, (intmax_t)c, (intmax_t)c);
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

begin_define
define|#
directive|define
name|debug_struct
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|debug_union
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|debug_type
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|debug_field
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|debug_const
parameter_list|(
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ciss_printf
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|device_printf(sc->ciss_dev, fmt , ##args)
end_define

begin_comment
comment|/************************************************************************  * Queue primitives  */
end_comment

begin_define
define|#
directive|define
name|CISSQ_ADD
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
define|\
value|do {							\ 	    struct ciss_qstat *qs =&(sc)->ciss_qstat[qname];	\ 								\ 	    qs->q_length++;					\ 	    if (qs->q_length> qs->q_max)			\ 		qs->q_max = qs->q_length;			\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|CISSQ_REMOVE
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
value|(sc)->ciss_qstat[qname].q_length--
end_define

begin_define
define|#
directive|define
name|CISSQ_INIT
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
define|\
value|do {					\ 	    sc->ciss_qstat[qname].q_length = 0;	\ 	    sc->ciss_qstat[qname].q_max = 0;	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|CISSQ_REQUEST_QUEUE
parameter_list|(
name|name
parameter_list|,
name|index
parameter_list|)
define|\
value|static __inline void							\ ciss_initq_ ## name (struct ciss_softc *sc)				\ {									\     TAILQ_INIT(&sc->ciss_ ## name);					\     CISSQ_INIT(sc, index);						\ }									\ static __inline void							\ ciss_enqueue_ ## name (struct ciss_request *cr)				\ {									\     int		s;							\ 									\     s = splcam();							\     TAILQ_INSERT_TAIL(&cr->cr_sc->ciss_ ## name, cr, cr_link);		\     CISSQ_ADD(cr->cr_sc, index);					\     cr->cr_onq = index;							\     splx(s);								\ }									\ static __inline void							\ ciss_requeue_ ## name (struct ciss_request *cr)				\ {									\     int		s;							\ 									\     s = splcam();							\     TAILQ_INSERT_HEAD(&cr->cr_sc->ciss_ ## name, cr, cr_link);		\     CISSQ_ADD(cr->cr_sc, index);					\     cr->cr_onq = index;							\     splx(s);								\ }									\ static __inline struct ciss_request *					\ ciss_dequeue_ ## name (struct ciss_softc *sc)				\ {									\     struct ciss_request	*cr;						\     int			s;						\ 									\     s = splcam();							\     if ((cr = TAILQ_FIRST(&sc->ciss_ ## name)) != NULL) {		\ 	TAILQ_REMOVE(&sc->ciss_ ## name, cr, cr_link);			\ 	CISSQ_REMOVE(sc, index);					\ 	cr->cr_onq = -1;						\     }									\     splx(s);								\     return(cr);								\ }									\ static __inline int							\ ciss_remove_ ## name (struct ciss_request *cr)				\ {									\     int			s, error;					\ 									\     s = splcam();							\     if (cr->cr_onq != index) {						\ 	printf("request on queue %d (expected %d)\n", cr->cr_onq, index);\ 	error = 1;							\     } else {								\ 	TAILQ_REMOVE(&cr->cr_sc->ciss_ ## name, cr, cr_link);		\ 	CISSQ_REMOVE(cr->cr_sc, index);					\ 	cr->cr_onq = -1;						\ 	error = 0;							\     }									\     splx(s);								\     return(error);							\ }									\ struct hack
end_define

begin_expr_stmt
name|CISSQ_REQUEST_QUEUE
argument_list|(
name|free
argument_list|,
name|CISSQ_FREE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CISSQ_REQUEST_QUEUE
argument_list|(
name|busy
argument_list|,
name|CISSQ_BUSY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CISSQ_REQUEST_QUEUE
argument_list|(
name|complete
argument_list|,
name|CISSQ_COMPLETE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CISSQ_REQUEST_QUEUE
argument_list|(
name|notify
argument_list|,
name|CISSQ_NOTIFY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/********************************************************************************  * space-fill a character string  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|padstr
parameter_list|(
name|char
modifier|*
name|targ
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|int
name|len
parameter_list|)
block|{
while|while
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|src
operator|!=
literal|0
condition|)
block|{
operator|*
name|targ
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
block|}
else|else
block|{
operator|*
name|targ
operator|++
operator|=
literal|' '
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

