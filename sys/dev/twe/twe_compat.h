begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Portability and compatibility interfaces.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/******************************************************************************  * FreeBSD  */
end_comment

begin_define
define|#
directive|define
name|TWE_SUPPORTED_PLATFORM
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/disk.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
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
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_comment
comment|/*  * These macros allows us to build a version of the driver which can   * safely be loaded into a kernel which already contains a 'twe' driver,  * and which will override it in all things.  *  * All public symbols must be listed here.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TWE_OVERRIDE
end_ifdef

begin_define
define|#
directive|define
name|twe_setup
value|Xtwe_setup
end_define

begin_define
define|#
directive|define
name|twe_init
value|Xtwe_init
end_define

begin_define
define|#
directive|define
name|twe_deinit
value|Xtwe_deinit
end_define

begin_define
define|#
directive|define
name|twe_intr
value|Xtwe_intr
end_define

begin_define
define|#
directive|define
name|twe_submit_bio
value|Xtwe_submit_bio
end_define

begin_define
define|#
directive|define
name|twe_ioctl
value|Xtwe_ioctl
end_define

begin_define
define|#
directive|define
name|twe_describe_controller
value|Xtwe_describe_controller
end_define

begin_define
define|#
directive|define
name|twe_print_controller
value|Xtwe_print_controller
end_define

begin_define
define|#
directive|define
name|twe_enable_interrupts
value|Xtwe_enable_interrupts
end_define

begin_define
define|#
directive|define
name|twe_disable_interrupts
value|Xtwe_disable_interrupts
end_define

begin_define
define|#
directive|define
name|twe_attach_drive
value|Xtwe_attach_drive
end_define

begin_define
define|#
directive|define
name|twed_intr
value|Xtwed_intr
end_define

begin_define
define|#
directive|define
name|twe_allocate_request
value|Xtwe_allocate_request
end_define

begin_define
define|#
directive|define
name|twe_free_request
value|Xtwe_free_request
end_define

begin_define
define|#
directive|define
name|twe_map_request
value|Xtwe_map_request
end_define

begin_define
define|#
directive|define
name|twe_unmap_request
value|Xtwe_unmap_request
end_define

begin_define
define|#
directive|define
name|twe_describe_code
value|Xtwe_describe_code
end_define

begin_define
define|#
directive|define
name|twe_table_status
value|Xtwe_table_status
end_define

begin_define
define|#
directive|define
name|twe_table_unitstate
value|Xtwe_table_unitstate
end_define

begin_define
define|#
directive|define
name|twe_table_unittype
value|Xtwe_table_unittype
end_define

begin_define
define|#
directive|define
name|twe_table_aen
value|Xtwe_table_aen
end_define

begin_define
define|#
directive|define
name|TWE_DRIVER_NAME
value|Xtwe
end_define

begin_define
define|#
directive|define
name|TWED_DRIVER_NAME
value|Xtwed
end_define

begin_define
define|#
directive|define
name|TWE_MALLOC_CLASS
value|M_XTWE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TWE_DRIVER_NAME
value|twe
end_define

begin_define
define|#
directive|define
name|TWED_DRIVER_NAME
value|twed
end_define

begin_define
define|#
directive|define
name|TWE_MALLOC_CLASS
value|M_TWE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * Wrappers for bus-space actions  */
end_comment

begin_define
define|#
directive|define
name|TWE_CONTROL
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->twe_btag, sc->twe_bhandle, 0x0, (u_int32_t)val)
end_define

begin_define
define|#
directive|define
name|TWE_STATUS
parameter_list|(
name|sc
parameter_list|)
value|(u_int32_t)bus_space_read_4(sc->twe_btag, sc->twe_bhandle, 0x4)
end_define

begin_define
define|#
directive|define
name|TWE_COMMAND_QUEUE
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->twe_btag, sc->twe_bhandle, 0x8, (u_int32_t)val)
end_define

begin_define
define|#
directive|define
name|TWE_RESPONSE_QUEUE
parameter_list|(
name|sc
parameter_list|)
value|(TWE_Response_Queue)bus_space_read_4(sc->twe_btag, sc->twe_bhandle, 0xc)
end_define

begin_comment
comment|/*  * FreeBSD-specific softc elements  */
end_comment

begin_define
define|#
directive|define
name|TWE_PLATFORM_SOFTC
define|\
value|device_t			twe_dev;
comment|/* bus device */
value|\     dev_t			twe_dev_t;
comment|/* control device */
value|\     struct resource		*twe_io;
comment|/* register interface window */
value|\     bus_space_handle_t		twe_bhandle;
comment|/* bus space handle */
value|\     bus_space_tag_t		twe_btag;
comment|/* bus space tag */
value|\     bus_dma_tag_t		twe_parent_dmat;
comment|/* parent DMA tag */
value|\     bus_dma_tag_t		twe_buffer_dmat;
comment|/* data buffer DMA tag */
value|\     struct resource		*twe_irq;
comment|/* interrupt */
value|\     void			*twe_intr;
comment|/* interrupt handle */
value|\     struct intr_config_hook	twe_ich;
end_define

begin_comment
comment|/* delayed-startup hook */
end_comment

begin_comment
comment|/*  * FreeBSD-specific request elements  */
end_comment

begin_define
define|#
directive|define
name|TWE_PLATFORM_REQUEST
define|\
value|bus_dmamap_t		tr_cmdmap;
comment|/* DMA map for command */
value|\     u_int32_t			tr_cmdphys;
comment|/* address of command in controller space */
value|\     bus_dmamap_t		tr_dmamap;
comment|/* DMA map for data */
value|\     u_int32_t			tr_dataphys;
end_define

begin_comment
comment|/* data buffer base address in controller space */
end_comment

begin_comment
comment|/*  * Output identifying the controller/disk  */
end_comment

begin_define
define|#
directive|define
name|twe_printf
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|device_printf(sc->twe_dev, fmt , ##args)
end_define

begin_define
define|#
directive|define
name|twed_printf
parameter_list|(
name|twed
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|device_printf(twed->twed_dev, fmt , ##args)
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500003
end_if

begin_comment
comment|/* old buf style */
end_comment

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|buf
name|twe_bio
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|buf_queue_head
name|twe_bioq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TWE_BIO_QINIT
parameter_list|(
name|bq
parameter_list|)
value|bufq_init(&bq);
end_define

begin_define
define|#
directive|define
name|TWE_BIO_QINSERT
parameter_list|(
name|bq
parameter_list|,
name|bp
parameter_list|)
value|bufq_insert_tail(&bq, bp)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_QFIRST
parameter_list|(
name|bq
parameter_list|)
value|bufq_first(&bq)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_QREMOVE
parameter_list|(
name|bq
parameter_list|,
name|bp
parameter_list|)
value|bufq_remove(&bq, bp)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_IS_READ
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_flags& B_READ)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_DATA
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_data
end_define

begin_define
define|#
directive|define
name|TWE_BIO_LENGTH
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_bcount
end_define

begin_define
define|#
directive|define
name|TWE_BIO_LBA
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_pblkno
end_define

begin_define
define|#
directive|define
name|TWE_BIO_SOFTC
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_dev->si_drv1
end_define

begin_define
define|#
directive|define
name|TWE_BIO_UNIT
parameter_list|(
name|bp
parameter_list|)
value|*(int *)((bp)->b_dev->si_drv2)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_SET_ERROR
parameter_list|(
name|bp
parameter_list|,
name|err
parameter_list|)
value|do { (bp)->b_error = err; (bp)->b_flags |= B_ERROR;} while(0)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_HAS_ERROR
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_flags& B_ERROR)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_RESID
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_resid
end_define

begin_define
define|#
directive|define
name|TWE_BIO_DONE
parameter_list|(
name|bp
parameter_list|)
value|biodone(bp)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_STATS_START
parameter_list|(
name|bp
parameter_list|)
value|devstat_start_transaction(&((struct twed_softc *)TWE_BIO_SOFTC(bp))->twed_stats)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_STATS_END
parameter_list|(
name|bp
parameter_list|)
value|devstat_end_transaction_buf(&((struct twed_softc *)TWE_BIO_SOFTC(bp))->twed_stats, bp)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|bio
name|twe_bio
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bio_queue_head
name|twe_bioq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TWE_BIO_QINIT
parameter_list|(
name|bq
parameter_list|)
value|bioq_init(&bq);
end_define

begin_define
define|#
directive|define
name|TWE_BIO_QINSERT
parameter_list|(
name|bq
parameter_list|,
name|bp
parameter_list|)
value|bioq_insert_tail(&bq, bp)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_QFIRST
parameter_list|(
name|bq
parameter_list|)
value|bioq_first(&bq)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_QREMOVE
parameter_list|(
name|bq
parameter_list|,
name|bp
parameter_list|)
value|bioq_remove(&bq, bp)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_IS_READ
parameter_list|(
name|bp
parameter_list|)
value|((bp)->bio_cmd == BIO_READ)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_DATA
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_data
end_define

begin_define
define|#
directive|define
name|TWE_BIO_LENGTH
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_bcount
end_define

begin_define
define|#
directive|define
name|TWE_BIO_LBA
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_pblkno
end_define

begin_define
define|#
directive|define
name|TWE_BIO_SOFTC
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_dev->si_drv1
end_define

begin_define
define|#
directive|define
name|TWE_BIO_UNIT
parameter_list|(
name|bp
parameter_list|)
value|*(int *)((bp)->bio_dev->si_drv2)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_SET_ERROR
parameter_list|(
name|bp
parameter_list|,
name|err
parameter_list|)
value|do { (bp)->bio_error = err; (bp)->bio_flags |= BIO_ERROR;} while(0)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_HAS_ERROR
parameter_list|(
name|bp
parameter_list|)
value|((bp)->bio_flags& BIO_ERROR)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_RESID
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_resid
end_define

begin_define
define|#
directive|define
name|TWE_BIO_DONE
parameter_list|(
name|bp
parameter_list|)
value|biodone(bp)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_STATS_START
parameter_list|(
name|bp
parameter_list|)
value|devstat_start_transaction(&((struct twed_softc *)TWE_BIO_SOFTC(bp))->twed_stats)
end_define

begin_define
define|#
directive|define
name|TWE_BIO_STATS_END
parameter_list|(
name|bp
parameter_list|)
value|devstat_end_transaction_bio(&((struct twed_softc *)TWE_BIO_SOFTC(bp))->twed_stats, bp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FreeBSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TWE_SUPPORTED_PLATFORM
end_ifndef

begin_error
error|#
directive|error
error|platform not supported
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

