begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NecBSD: bsif.h,v 1.5 1997/10/23 20:52:34 honda Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) HONDA Naofumi, KATO Takenori, 1996.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *   notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * The name of the author may not be used to endorse or promote products  * derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/***************************************************  * misc device header in bs_softc  ***************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|OS_DEPEND_DEVICE_HEADER
define|\
value|struct device sc_dev;			\ 	void *sc_ih;
end_define

begin_define
define|#
directive|define
name|OS_DEPEND_SCSI_HEADER
define|\
value|struct scsi_link sc_link;
end_define

begin_define
define|#
directive|define
name|OS_DEPEND_MISC_HEADER
define|\
value|pisa_device_handle_t sc_dh;		\ 	bus_space_tag_t sc_iot;			\ 	bus_space_tag_t sc_memt;		\ 	bus_space_handle_t sc_ioh;		\ 	bus_space_handle_t sc_delaybah;		\ 	bus_space_handle_t sc_memh;		\ 	bus_dma_tag_t sc_dmat;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|OS_DEPEND_DEVICE_HEADER
define|\
value|int unit;
end_define

begin_define
define|#
directive|define
name|OS_DEPEND_SCSI_HEADER
define|\
value|struct scsi_link sc_link;
end_define

begin_define
define|#
directive|define
name|OS_DEPEND_MISC_HEADER
define|\
value|struct callout_handle timeout_ch;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSHW_NBPG
value|NBPG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSHW_NBPG
value|PAGE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************  * include  ***************************************************/
end_comment

begin_comment
comment|/* (I) common include */
end_comment

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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_comment
comment|/* (II) os depend include */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_include
include|#
directive|include
file|<dev/isa/isareg.h>
end_include

begin_include
include|#
directive|include
file|<dev/isa/isavar.h>
end_include

begin_include
include|#
directive|include
file|<dev/isa/pisaif.h>
end_include

begin_include
include|#
directive|include
file|<dev/isa/isadmavar.h>
end_include

begin_include
include|#
directive|include
file|<dev/isa/isadmareg.h>
end_include

begin_include
include|#
directive|include
file|<dev/cons.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<machine/dvcfg.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsiconf.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsi_disk.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<machine/ipl.h>
end_include

begin_include
include|#
directive|include
file|<machine/dvcfg.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsiconf.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsi_disk.h>
end_include

begin_include
include|#
directive|include
file|<pc98/pc98/pc98.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/icu.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/***************************************************  * BUS IO MAPPINGS& BS specific inclusion  ***************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|BUS_IO_DELAY
value|((void) bus_space_read_1(bsc->sc_iot, bsc->sc_delaybah, 0))
end_define

begin_define
define|#
directive|define
name|BUS_IO_WEIGHT
value|(bus_space_write_1(bsc->sc_iot, bsc->sc_delaybah, 0, 0))
end_define

begin_define
define|#
directive|define
name|BUS_IOR
parameter_list|(
name|offs
parameter_list|)
value|(bus_space_read_1(bsc->sc_iot, bsc->sc_ioh, (offs)))
end_define

begin_define
define|#
directive|define
name|BUS_IOW
parameter_list|(
name|offs
parameter_list|,
name|val
parameter_list|)
value|(bus_space_write_1(bsc->sc_iot, bsc->sc_ioh, (offs), (val)))
end_define

begin_include
include|#
directive|include
file|<dev/ic/wd33c93reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/isa/ccbque.h>
end_include

begin_include
include|#
directive|include
file|<i386/Cbus/dev/scsi_dvcfg.h>
end_include

begin_include
include|#
directive|include
file|<i386/Cbus/dev/bs/bsvar.h>
end_include

begin_include
include|#
directive|include
file|<i386/Cbus/dev/bs/bshw.h>
end_include

begin_include
include|#
directive|include
file|<i386/Cbus/dev/bs/bsfunc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|BUS_IO_DELAY
value|((void) inb(0x5f))
end_define

begin_define
define|#
directive|define
name|BUS_IO_WEIGHT
value|(outb(0x5f, 0))
end_define

begin_define
define|#
directive|define
name|BUS_IOR
parameter_list|(
name|offs
parameter_list|)
value|(BUS_IO_DELAY, inb(bsc->sc_iobase + (offs)))
end_define

begin_define
define|#
directive|define
name|BUS_IOW
parameter_list|(
name|offs
parameter_list|,
name|val
parameter_list|)
value|(BUS_IO_DELAY, outb(bsc->sc_iobase + (offs), (val)))
end_define

begin_include
include|#
directive|include
file|<i386/isa/ic/wd33c93.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/ccbque.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/scsi_dvcfg.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/bs/bsvar.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/bs/bshw.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/bs/bsfunc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/***************************************************  * XS return type  ***************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|XSBS_INT32T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|XSBS_INT32T
value|int32_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/***************************************************  * xs flags's abstraction (all currently used)  ***************************************************/
end_comment

begin_define
define|#
directive|define
name|XSBS_ITSDONE
value|ITSDONE
end_define

begin_define
define|#
directive|define
name|XSBS_SCSI_NOSLEEP
value|SCSI_NOSLEEP
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|XSBS_SCSI_POLL
value|SCSI_POLL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|XSBS_SCSI_POLL
value|SCSI_NOMASK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/***************************************************  * Special operations  ***************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|BS_ADDRESS_CHECK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/***************************************************  * declare  ***************************************************/
end_comment

begin_comment
comment|/* (I) common declare */
end_comment

begin_decl_stmt
name|void
name|bs_alloc_buf
name|__P
argument_list|(
operator|(
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XSBS_INT32T
name|bs_target_open
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_link
operator|*
operator|,
expr|struct
name|cfdata
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XSBS_INT32T
name|bs_scsi_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_xfer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|delaycount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (II) os depend declare */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_decl_stmt
name|int
name|bsintr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bsprint
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_decl_stmt
specifier|static
name|BS_INLINE
name|void
name|memcopy
name|__P
argument_list|(
operator|(
name|void
operator|*
name|from
operator|,
name|void
operator|*
name|to
operator|,
specifier|register
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|bs_adapter_info
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|delay
parameter_list|(
name|y
parameter_list|)
value|DELAY(y)
end_define

begin_decl_stmt
specifier|extern
name|int
name|dma_init_flag
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_error
error|#
directive|error
error|XXX see comments in i386/isa/bs/bsif.h for details
end_error

begin_comment
comment|/*  * ipending is 'opaque' in SMP, and can't be accessed this way.  * Since its my belief that this is PC98 code, and that PC98 and SMP  * are mutually exclusive, the above compile-time error is the "fix".  * Please inform smp@freebsd.org if this is NOT the case.  */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|softintr
parameter_list|(
name|y
parameter_list|)
value|ipending |= (1<< y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_function
specifier|static
name|BS_INLINE
name|void
name|memcopy
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|len
parameter_list|)
name|void
modifier|*
name|from
decl_stmt|,
decl|*
name|to
decl_stmt|;
end_function

begin_decl_stmt
specifier|register
name|size_t
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|len
operator|>>=
literal|2
expr_stmt|;
asm|__asm __volatile("cld\n\trep\n\tmovsl" : :
literal|"S"
operator|(
name|from
operator|)
operator|,
literal|"D"
operator|(
name|to
operator|)
operator|,
literal|"c"
operator|(
name|len
operator|)
operator|:
literal|"%esi"
operator|,
literal|"%edi"
operator|,
literal|"%ecx"
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

end_unit

