begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Generic driver for the aic7xxx based adaptec SCSI controllers  * Product specific probe and attach routines can be found in:  * i386/eisa/aic7770.c	27/284X and aic7770 motherboard controllers  * pci/aic7870.c	3940, 2940, aic7880, aic7870, aic7860,  *			and aic7850 controllers  *  * Copyright (c) 1994, 1995, 1996 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $Id: aic7xxx.c,v 1.81 1996/10/28 06:10:00 gibbs Exp $  */
end_comment

begin_comment
comment|/*  * TODO:  *	Implement Target Mode  *  * A few notes on features of the driver.  *  * SCB paging takes advantage of the fact that devices stay disconnected  * from the bus a relatively long time and that while they're disconnected,  * having the SCBs for these transactions down on the host adapter is of  * little use.  Instead of leaving this idle SCB down on the card we copy  * it back up into kernel memory and reuse the SCB slot on the card to  * schedule another transaction.  This can be a real payoff when doing random  * I/O to tagged queueing devices since there are more transactions active at  * once for the device to sort for optimal seek reduction. The algorithm goes  * like this...  *  * The sequencer maintains two lists of its hardware SCBs.  The first is the  * singly linked free list which tracks all SCBs that are not currently in  * use.  The second is the doubly linked disconnected list which holds the  * SCBs of transactions that are in the disconnected state sorted most  * recently disconnected first.  When the kernel queues a transaction to  * the card, a hardware SCB to "house" this transaction is retrieved from  * either of these two lists.  If the SCB came from the disconnected list,  * a check is made to see if any data transfer or SCB linking (more on linking  * in a bit) information has been changed since it was copied from the host  * and if so, DMAs the SCB back up before it can be used.  Once a hardware  * SCB has been obtained, the SCB is DMAed from the host.  Before any work  * can begin on this SCB, the sequencer must ensure that either the SCB is  * for a tagged transaction or the target is not already working on another  * non-tagged transaction.  If a conflict arises in the non-tagged case, the  * sequencer finds the SCB for the active transactions and sets the SCB_LINKED  * field in that SCB to this next SCB to execute.  To facilitate finding  * active non-tagged SCBs, the last four bytes of up to the first four hardware  * SCBs serve as a storage area for the currently active SCB ID for each  * target.  *  * When a device reconnects, a search is made of the hardware SCBs to find  * the SCB for this transaction.  If the search fails, a hardware SCB is  * pulled from either the free or disconnected SCB list and the proper  * SCB is DMAed from the host.  If the SCB_ABORTED control bit is set  * in the control byte of the SCB while it was disconnected, the sequencer  * will send an abort or abort tag message to the target during the  * reconnection and signal the kernel that the abort was successfull.  *  * When a command completes, a check for non-zero status and residuals is  * made.  If either of these conditions exists, the SCB is DMAed back up to  * the host so that it can interpret this information.  Additionally, in the  * case of bad status, the sequencer generates a special interrupt and pauses  * itself.  This allows the host to setup a request sense command if it   * chooses for this target synchronously with the error so that sense  * information isn't lost.  *  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/device.h>
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__NetBSD__) */
end_comment

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsi_message.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<scsi/scsi_debug.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<scsi/scsiconf.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<i386/scsi/aic7xxx.h>
end_include

begin_include
include|#
directive|include
file|<dev/aic7xxx/aic7xxx_reg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__FreeBSD__) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dev/ic/aic7xxxreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/ic/aic7xxxvar.h>
end_include

begin_define
define|#
directive|define
name|bootverbose
value|1
end_define

begin_if
if|#
directive|if
name|DEBUGTARGET
operator|<
literal|0
end_if

begin_comment
comment|/* Negative numbrs for disabling cause warnings */
end_comment

begin_define
define|#
directive|define
name|DEBUGTARGET
value|17
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
comment|/* defined(__NetBSD__) */
end_comment

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|ALL_TARGETS
value|-1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_decl_stmt
name|u_long
name|ahc_unit
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AHC_DEBUG
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|ahc_debug
init|=
name|AHC_DEBUG
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AHC_BROKEN_CACHE
end_ifdef

begin_decl_stmt
name|int
name|ahc_broken_cache
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * "wbinvd" cause writing back whole cache (both CPU internal& external)  * to memory, so that the instruction takes a lot of time.  * This makes machine slow.  */
end_comment

begin_define
define|#
directive|define
name|INVALIDATE_CACHE
parameter_list|()
value|__asm __volatile("wbinvd")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**** bit definitions for SCSIDEF ****/
end_comment

begin_define
define|#
directive|define
name|HSCSIID
value|0x07
end_define

begin_comment
comment|/* our SCSI ID */
end_comment

begin_define
define|#
directive|define
name|HWSCSIID
value|0x0f
end_define

begin_comment
comment|/* our SCSI ID if Wide Bus */
end_comment

begin_decl_stmt
specifier|static
name|void
name|ahcminphys
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
name|bp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int32_t
name|ahc_scsi_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_xfer
operator|*
name|xs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_run_waiting_queue
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|scb
modifier|*
name|ahc_get_scb
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|u_int32_t
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_free_scb
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
expr|struct
name|scb
operator|*
name|scb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|scb
modifier|*
name|ahc_alloc_scb
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|void
name|pause_sequencer
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|void
name|unpause_sequencer
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|int
name|unpause_always
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|void
name|restart_sequencer
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|scsi_adapter
name|ahc_switch
init|=
block|{
name|ahc_scsi_cmd
block|,
name|ahcminphys
block|,
name|NULL
block|,
name|NULL
block|,
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|NULL
block|,
literal|"ahc"
block|,
block|{
literal|0
block|,
literal|0
block|}
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|scsi_device
name|ahc_dev
init|=
block|{
name|NULL
block|,
comment|/* Use default error handler */
name|NULL
block|,
comment|/* have a queue, served by this */
name|NULL
block|,
comment|/* have no async handler */
name|NULL
block|,
comment|/* Use default 'done' routine */
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
literal|"ahc"
block|,
literal|0
block|,
block|{
literal|0
block|,
literal|0
block|}
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|void
name|pause_sequencer
parameter_list|(
name|ahc
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
block|{
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|HCNTRL
argument_list|,
name|ahc
operator|->
name|pause
argument_list|)
expr_stmt|;
comment|/* 	 * Since the sequencer can disable pausing in a critical section, we 	 * must loop until it actually stops. 	 */
while|while
condition|(
operator|(
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|HCNTRL
argument_list|)
operator|&
name|PAUSE
operator|)
operator|==
literal|0
condition|)
empty_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|unpause_sequencer
parameter_list|(
name|ahc
parameter_list|,
name|unpause_always
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
name|int
name|unpause_always
decl_stmt|;
block|{
if|if
condition|(
name|unpause_always
operator|||
operator|(
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|INTSTAT
argument_list|)
operator|&
operator|(
name|SCSIINT
operator||
name|SEQINT
operator||
name|BRKADRINT
operator|)
operator|)
operator|==
literal|0
condition|)
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|HCNTRL
argument_list|,
name|ahc
operator|->
name|unpause
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Restart the sequencer program from address zero  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|restart_sequencer
parameter_list|(
name|ahc
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
block|{
do|do
block|{
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|SEQCTL
argument_list|,
name|SEQRESET
operator||
name|FASTMODE
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|SEQADDR0
argument_list|)
operator|!=
literal|0
operator|)
operator|||
operator|(
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|SEQADDR1
argument_list|)
operator|!=
literal|0
operator|)
condition|)
do|;
name|unpause_sequencer
argument_list|(
name|ahc
argument_list|,
comment|/*unpause_always*/
name|TRUE
argument_list|)
expr_stmt|;
block|}
end_function

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
name|IS_SCSIBUS_B
parameter_list|(
name|ahc
parameter_list|,
name|sc_link
parameter_list|)
define|\
value|(((u_int32_t)(sc_link)->fordriver)& SELBUSB)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NetBSD/OpenBSD */
end_comment

begin_define
define|#
directive|define
name|IS_SCSIBUS_B
parameter_list|(
name|ahc
parameter_list|,
name|sc_link
parameter_list|)
define|\
value|((sc_link)->scsibus == (ahc)->sc_link_b.scsibus)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|u_int8_t
name|ahc_abort_wscb
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
expr|struct
name|scb
operator|*
name|scbp
operator|,
name|u_int8_t
name|scbpos
operator|,
name|u_int8_t
name|prev
operator|,
expr|struct
name|scb
operator|*
name|timedout_scb
operator|,
name|u_int32_t
name|xs_error
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_done
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
expr|struct
name|scb
operator|*
name|scbp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_handle_seqint
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|u_int8_t
name|intstat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_handle_scsiint
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|u_int8_t
name|intstat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_loadseq
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ahc_match_scb
name|__P
argument_list|(
operator|(
expr|struct
name|scb
operator|*
name|scb
operator|,
name|int
name|target
operator|,
name|char
name|channel
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ahc_poll
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|int
name|wait
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|AHC_DEBUG
end_ifdef

begin_decl_stmt
specifier|static
name|void
name|ahc_print_scb
name|__P
argument_list|(
operator|(
expr|struct
name|scb
operator|*
name|scb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|u_int8_t
name|find_scb
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
expr|struct
name|scb
operator|*
name|scb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ahc_reset_channel
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|char
name|channel
operator|,
expr|struct
name|scb
operator|*
name|timedout_scb
operator|,
name|u_int32_t
name|xs_error
operator|,
name|int
name|initiate_reset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ahc_reset_device
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|int
name|target
operator|,
name|char
name|channel
operator|,
expr|struct
name|scb
operator|*
name|timedout_scb
operator|,
name|u_int32_t
name|xs_error
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_reset_current_bus
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_run_done_queue
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_scsirate
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|u_int8_t
operator|*
name|scsirate
operator|,
name|u_int8_t
operator|*
name|period
operator|,
name|u_int8_t
operator|*
name|offset
operator|,
name|char
name|channel
operator|,
name|int
name|target
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|timeout_t
name|ahc_timeout
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_decl_stmt
specifier|static
name|void
name|ahc_timeout
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|u_int8_t
name|ahc_unbusy_target
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|int
name|target
operator|,
name|char
name|channel
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_construct_sdtr
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|int
name|start_byte
operator|,
name|u_int8_t
name|period
operator|,
name|u_int8_t
name|offset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_construct_wdtr
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|int
name|start_byte
operator|,
name|u_int8_t
name|bus_width
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ahc_calc_residual
name|__P
argument_list|(
operator|(
expr|struct
name|scb
operator|*
name|scb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_function
name|char
modifier|*
name|ahc_name
parameter_list|(
name|ahc
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
block|{
specifier|static
name|char
name|name
index|[
literal|10
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"ahc%d"
argument_list|,
name|ahc
operator|->
name|unit
argument_list|)
expr_stmt|;
return|return
operator|(
name|name
operator|)
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_decl_stmt
name|struct
name|cfdriver
name|ahc_cd
init|=
block|{
name|NULL
block|,
literal|"ahc"
block|,
name|DV_DULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AHC_DEBUG
end_ifdef

begin_function
specifier|static
name|void
name|ahc_print_scb
parameter_list|(
name|scb
parameter_list|)
name|struct
name|scb
modifier|*
name|scb
decl_stmt|;
block|{
name|printf
argument_list|(
literal|"scb:%p control:0x%x tcl:0x%x cmdlen:%d cmdpointer:0x%lx\n"
argument_list|,
name|scb
argument_list|,
name|scb
operator|->
name|control
argument_list|,
name|scb
operator|->
name|tcl
argument_list|,
name|scb
operator|->
name|cmdlen
argument_list|,
name|scb
operator|->
name|cmdpointer
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"        datlen:%d data:0x%lx segs:0x%x segp:0x%lx\n"
argument_list|,
name|scb
operator|->
name|datalen
argument_list|,
name|scb
operator|->
name|data
argument_list|,
name|scb
operator|->
name|SG_segment_count
argument_list|,
name|scb
operator|->
name|SG_list_pointer
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"	sg_addr:%lx sg_len:%ld\n"
argument_list|,
name|scb
operator|->
name|ahc_dma
index|[
literal|0
index|]
operator|.
name|addr
argument_list|,
name|scb
operator|->
name|ahc_dma
index|[
literal|0
index|]
operator|.
name|len
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_struct
specifier|static
struct|struct
block|{
name|u_int8_t
name|errno
decl_stmt|;
name|char
modifier|*
name|errmesg
decl_stmt|;
block|}
name|hard_error
index|[]
init|=
block|{
block|{
name|ILLHADDR
block|,
literal|"Illegal Host Access"
block|}
block|,
block|{
name|ILLSADDR
block|,
literal|"Illegal Sequencer Address referrenced"
block|}
block|,
block|{
name|ILLOPCODE
block|,
literal|"Illegal Opcode in sequencer program"
block|}
block|,
block|{
name|PARERR
block|,
literal|"Sequencer Ram Parity Error"
block|}
block|}
struct|;
end_struct

begin_comment
comment|/*  * Valid SCSIRATE values.  (p. 3-17)  * Provides a mapping of tranfer periods in ns to the proper value to  * stick in the scsiscfr reg to use that transfer rate.  */
end_comment

begin_struct
specifier|static
struct|struct
block|{
name|int
name|sxfr
decl_stmt|;
comment|/* Rates in Ultra mode have bit 8 of sxfr set */
define|#
directive|define
name|ULTRA_SXFR
value|0x100
name|u_int8_t
name|period
decl_stmt|;
comment|/* Period to send to SCSI target */
name|char
modifier|*
name|rate
decl_stmt|;
block|}
name|ahc_syncrates
index|[]
init|=
block|{
block|{
literal|0x100
block|,
literal|12
block|,
literal|"20.0"
block|}
block|,
block|{
literal|0x110
block|,
literal|15
block|,
literal|"16.0"
block|}
block|,
block|{
literal|0x120
block|,
literal|18
block|,
literal|"13.4"
block|}
block|,
block|{
literal|0x000
block|,
literal|25
block|,
literal|"10.0"
block|}
block|,
block|{
literal|0x010
block|,
literal|31
block|,
literal|"8.0"
block|}
block|,
block|{
literal|0x020
block|,
literal|37
block|,
literal|"6.67"
block|}
block|,
block|{
literal|0x030
block|,
literal|43
block|,
literal|"5.7"
block|}
block|,
block|{
literal|0x040
block|,
literal|50
block|,
literal|"5.0"
block|}
block|,
block|{
literal|0x050
block|,
literal|56
block|,
literal|"4.4"
block|}
block|,
block|{
literal|0x060
block|,
literal|62
block|,
literal|"4.0"
block|}
block|,
block|{
literal|0x070
block|,
literal|68
block|,
literal|"3.6"
block|}
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|int
name|ahc_num_syncrates
init|=
sizeof|sizeof
argument_list|(
name|ahc_syncrates
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ahc_syncrates
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Allocate a controller structures for a new device and initialize it.  * ahc_reset should be called before now since we assume that the card  * is paused.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_decl_stmt
name|struct
name|ahc_softc
modifier|*
name|ahc_alloc
argument_list|(
name|unit
argument_list|,
name|iobase
argument_list|,
name|maddr
argument_list|,
name|type
argument_list|,
name|flags
argument_list|,
name|scb_data
argument_list|)
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|iobase
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_function
name|void
name|ahc_construct
parameter_list|(
name|ahc
parameter_list|,
name|bc
parameter_list|,
name|ioh
parameter_list|,
name|maddr
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
name|bus_chipset_tag_t
name|bc
decl_stmt|;
name|bus_io_handle_t
name|ioh
decl_stmt|;
endif|#
directive|endif
name|vm_offset_t
name|maddr
decl_stmt|;
name|ahc_type
name|type
decl_stmt|;
name|ahc_flag
name|flags
decl_stmt|;
name|struct
name|scb_data
modifier|*
name|scb_data
decl_stmt|;
block|{
comment|/* 	 * find unit and check we have that many defined 	 */
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
name|size_t
name|alloc_size
decl_stmt|;
comment|/* 	 * Allocate a storage area for us 	 */
if|if
condition|(
name|scb_data
operator|==
name|NULL
condition|)
comment|/* 		 * We are not sharing SCB space with another controller 		 * so allocate our own SCB data space. 		 */
name|alloc_size
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|full_ahc_softc
argument_list|)
expr_stmt|;
else|else
name|alloc_size
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|ahc_softc
argument_list|)
expr_stmt|;
name|ahc
operator|=
name|malloc
argument_list|(
name|alloc_size
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ahc
condition|)
block|{
name|printf
argument_list|(
literal|"ahc%d: cannot malloc!\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|bzero
argument_list|(
name|ahc
argument_list|,
name|alloc_size
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|scb_data
operator|==
name|NULL
condition|)
block|{
name|struct
name|full_ahc_softc
modifier|*
name|full_softc
init|=
operator|(
expr|struct
name|full_ahc_softc
operator|*
operator|)
name|ahc
decl_stmt|;
name|ahc
operator|->
name|scb_data
operator|=
operator|&
name|full_softc
operator|->
name|scb_data_storage
expr_stmt|;
name|STAILQ_INIT
argument_list|(
operator|&
name|ahc
operator|->
name|scb_data
operator|->
name|free_scbs
argument_list|)
expr_stmt|;
block|}
else|else
name|ahc
operator|->
name|scb_data
operator|=
name|scb_data
expr_stmt|;
name|STAILQ_INIT
argument_list|(
operator|&
name|ahc
operator|->
name|waiting_scbs
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|ahc
operator|->
name|unit
operator|=
name|unit
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|ahc
operator|->
name|baseport
operator|=
name|iobase
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|ahc
operator|->
name|sc_bc
operator|=
name|bc
expr_stmt|;
name|ahc
operator|->
name|sc_ioh
operator|=
name|ioh
expr_stmt|;
endif|#
directive|endif
name|ahc
operator|->
name|maddr
operator|=
operator|(
specifier|volatile
name|u_int8_t
operator|*
operator|)
name|maddr
expr_stmt|;
name|ahc
operator|->
name|type
operator|=
name|type
expr_stmt|;
name|ahc
operator|->
name|flags
operator|=
name|flags
expr_stmt|;
name|ahc
operator|->
name|unpause
operator|=
operator|(
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|HCNTRL
argument_list|)
operator|&
name|IRQMS
operator|)
operator||
name|INTEN
expr_stmt|;
name|ahc
operator|->
name|pause
operator|=
name|ahc
operator|->
name|unpause
operator||
name|PAUSE
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
return|return
operator|(
name|ahc
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|ahc_free
parameter_list|(
name|ahc
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
block|{
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|free
argument_list|(
name|ahc
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
return|return;
endif|#
directive|endif
block|}
end_function

begin_function
name|void
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|ahc_reset
parameter_list|(
name|iobase
parameter_list|)
name|u_int32_t
name|iobase
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
function|ahc_reset
parameter_list|(
name|devname
parameter_list|,
name|bc
parameter_list|,
name|ioh
parameter_list|)
name|char
modifier|*
name|devname
decl_stmt|;
name|bus_chipset_tag_t
name|bc
decl_stmt|;
name|bus_io_handle_t
name|ioh
decl_stmt|;
endif|#
directive|endif
block|{
name|u_int8_t
name|hcntrl
decl_stmt|;
name|int
name|wait
decl_stmt|;
comment|/* Retain the IRQ type accross the chip reset */
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|hcntrl
operator|=
operator|(
name|inb
argument_list|(
name|HCNTRL
operator|+
name|iobase
argument_list|)
operator|&
name|IRQMS
operator|)
operator||
name|INTEN
expr_stmt|;
name|outb
argument_list|(
name|HCNTRL
operator|+
name|iobase
argument_list|,
name|CHIPRST
operator||
name|PAUSE
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|hcntrl
operator|=
operator|(
name|bus_io_read_1
argument_list|(
name|bc
argument_list|,
name|ioh
argument_list|,
name|HCNTRL
argument_list|)
operator|&
name|IRQMS
operator|)
operator||
name|INTEN
expr_stmt|;
name|bus_io_write_1
argument_list|(
name|bc
argument_list|,
name|ioh
argument_list|,
name|HCNTRL
argument_list|,
name|CHIPRST
operator||
name|PAUSE
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Ensure that the reset has finished 	 */
name|wait
operator|=
literal|1000
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
while|while
condition|(
operator|--
name|wait
operator|&&
operator|!
operator|(
name|inb
argument_list|(
name|HCNTRL
operator|+
name|iobase
argument_list|)
operator|&
name|CHIPRSTACK
operator|)
condition|)
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
while|while
condition|(
operator|--
name|wait
operator|&&
operator|!
operator|(
name|bus_io_read_1
argument_list|(
name|bc
argument_list|,
name|ioh
argument_list|,
name|HCNTRL
argument_list|)
operator|&
name|CHIPRSTACK
operator|)
condition|)
endif|#
directive|endif
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
if|if
condition|(
name|wait
operator|==
literal|0
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|printf
argument_list|(
literal|"ahc at 0x%lx: WARNING - Failed chip reset!  "
literal|"Trying to initialize anyway.\n"
argument_list|,
name|iobase
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|printf
argument_list|(
literal|"%s: WARNING - Failed chip reset!  "
literal|"Trying to initialize anyway.\n"
argument_list|,
name|devname
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|outb
argument_list|(
name|HCNTRL
operator|+
name|iobase
argument_list|,
name|hcntrl
operator||
name|PAUSE
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|bus_io_write_1
argument_list|(
name|bc
argument_list|,
name|ioh
argument_list|,
name|HCNTRL
argument_list|,
name|hcntrl
operator||
name|PAUSE
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Look up the valid period to SCSIRATE conversion in our table.  */
end_comment

begin_function
specifier|static
name|void
name|ahc_scsirate
parameter_list|(
name|ahc
parameter_list|,
name|scsirate
parameter_list|,
name|period
parameter_list|,
name|offset
parameter_list|,
name|channel
parameter_list|,
name|target
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
name|u_int8_t
modifier|*
name|scsirate
decl_stmt|;
name|u_int8_t
modifier|*
name|period
decl_stmt|;
name|u_int8_t
modifier|*
name|offset
decl_stmt|;
name|char
name|channel
decl_stmt|;
name|int
name|target
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|u_int32_t
name|ultra_enb_addr
decl_stmt|;
name|u_int8_t
name|sxfrctl0
decl_stmt|;
name|u_int8_t
name|ultra_enb
decl_stmt|;
name|i
operator|=
name|ahc_num_syncrates
expr_stmt|;
comment|/* Default to async */
if|if
condition|(
operator|*
name|period
operator|>=
name|ahc_syncrates
index|[
literal|0
index|]
operator|.
name|period
operator|&&
operator|*
name|offset
operator|!=
literal|0
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ahc_num_syncrates
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|period
operator|<=
name|ahc_syncrates
index|[
name|i
index|]
operator|.
name|period
condition|)
block|{
comment|/* 				 * Watch out for Ultra speeds when ultra is not 				 * enabled and vice-versa. 				 */
if|if
condition|(
operator|!
operator|(
name|ahc
operator|->
name|type
operator|&
name|AHC_ULTRA
operator|)
operator|&&
operator|(
name|ahc_syncrates
index|[
name|i
index|]
operator|.
name|sxfr
operator|&
name|ULTRA_SXFR
operator|)
condition|)
block|{
comment|/* 					 * This should only happen if the 					 * drive is the first to negotiate 					 * and chooses a high rate.  We'll 					 * just move down the table util 					 * we hit a non ultra speed. 					 */
continue|continue;
block|}
operator|*
name|scsirate
operator|=
operator|(
name|ahc_syncrates
index|[
name|i
index|]
operator|.
name|sxfr
operator|&
literal|0xF0
operator|)
operator||
operator|(
operator|*
name|offset
operator|&
literal|0x0f
operator|)
expr_stmt|;
operator|*
name|period
operator|=
name|ahc_syncrates
index|[
name|i
index|]
operator|.
name|period
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
block|{
name|printf
argument_list|(
literal|"%s: target %d synchronous at "
literal|"%sMHz, offset = 0x%x\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|,
name|target
argument_list|,
name|ahc_syncrates
index|[
name|i
index|]
operator|.
name|rate
argument_list|,
operator|*
name|offset
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
block|}
if|if
condition|(
name|i
operator|>=
name|ahc_num_syncrates
condition|)
block|{
comment|/* Use asyncronous transfers. */
operator|*
name|scsirate
operator|=
literal|0
expr_stmt|;
operator|*
name|period
operator|=
literal|0
expr_stmt|;
operator|*
name|offset
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"%s: target %d using asyncronous transfers\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|,
name|target
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Ensure Ultra mode is set properly for 	 * this target. 	 */
name|ultra_enb_addr
operator|=
name|ULTRA_ENB
expr_stmt|;
if|if
condition|(
name|channel
operator|==
literal|'B'
operator|||
name|target
operator|>
literal|7
condition|)
name|ultra_enb_addr
operator|++
expr_stmt|;
name|ultra_enb
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|ultra_enb_addr
argument_list|)
expr_stmt|;
name|sxfrctl0
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|SXFRCTL0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|scsirate
operator|!=
literal|0
operator|&&
name|ahc_syncrates
index|[
name|i
index|]
operator|.
name|sxfr
operator|&
name|ULTRA_SXFR
condition|)
block|{
name|ultra_enb
operator||=
literal|0x01
operator|<<
operator|(
name|target
operator|&
literal|0x07
operator|)
expr_stmt|;
name|sxfrctl0
operator||=
name|ULTRAEN
expr_stmt|;
block|}
else|else
block|{
name|ultra_enb
operator|&=
operator|~
operator|(
literal|0x01
operator|<<
operator|(
name|target
operator|&
literal|0x07
operator|)
operator|)
expr_stmt|;
name|sxfrctl0
operator|&=
operator|~
name|ULTRAEN
expr_stmt|;
block|}
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|ultra_enb_addr
argument_list|,
name|ultra_enb
argument_list|)
expr_stmt|;
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|SXFRCTL0
argument_list|,
name|sxfrctl0
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_function
name|int
name|ahcprint
parameter_list|(
name|aux
parameter_list|,
name|name
parameter_list|)
name|void
modifier|*
name|aux
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|{
if|if
condition|(
name|name
operator|!=
name|NULL
condition|)
name|printf
argument_list|(
literal|"%s: scsibus "
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
name|UNCONF
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Attach all the sub-devices we can find  */
end_comment

begin_function
name|int
name|ahc_attach
parameter_list|(
name|ahc
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
block|{
name|struct
name|scsibus_data
modifier|*
name|scbus
decl_stmt|;
ifdef|#
directive|ifdef
name|AHC_BROKEN_CACHE
if|if
condition|(
name|cpu_class
operator|==
name|CPUCLASS_386
condition|)
comment|/* doesn't have "wbinvd" instruction */
name|ahc_broken_cache
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * fill in the prototype scsi_links. 	 */
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|ahc
operator|->
name|sc_link
operator|.
name|adapter_unit
operator|=
name|ahc
operator|->
name|unit
expr_stmt|;
name|ahc
operator|->
name|sc_link
operator|.
name|adapter_targ
operator|=
name|ahc
operator|->
name|our_id
expr_stmt|;
name|ahc
operator|->
name|sc_link
operator|.
name|fordriver
operator|=
literal|0
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|ahc
operator|->
name|sc_link
operator|.
name|adapter_target
operator|=
name|ahc
operator|->
name|our_id
expr_stmt|;
endif|#
directive|endif
name|ahc
operator|->
name|sc_link
operator|.
name|adapter_softc
operator|=
name|ahc
expr_stmt|;
name|ahc
operator|->
name|sc_link
operator|.
name|adapter
operator|=
operator|&
name|ahc_switch
expr_stmt|;
name|ahc
operator|->
name|sc_link
operator|.
name|opennings
operator|=
literal|2
expr_stmt|;
name|ahc
operator|->
name|sc_link
operator|.
name|device
operator|=
operator|&
name|ahc_dev
expr_stmt|;
name|ahc
operator|->
name|sc_link
operator|.
name|flags
operator|=
name|DEBUGLEVEL
expr_stmt|;
if|if
condition|(
name|ahc
operator|->
name|type
operator|&
name|AHC_TWIN
condition|)
block|{
comment|/* Configure the second scsi bus */
name|ahc
operator|->
name|sc_link_b
operator|=
name|ahc
operator|->
name|sc_link
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|ahc
operator|->
name|sc_link_b
operator|.
name|adapter_targ
operator|=
name|ahc
operator|->
name|our_id_b
expr_stmt|;
name|ahc
operator|->
name|sc_link_b
operator|.
name|adapter_bus
operator|=
literal|1
expr_stmt|;
name|ahc
operator|->
name|sc_link_b
operator|.
name|fordriver
operator|=
operator|(
name|void
operator|*
operator|)
name|SELBUSB
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|ahc
operator|->
name|sc_link_b
operator|.
name|adapter_target
operator|=
name|ahc
operator|->
name|our_id_b
expr_stmt|;
endif|#
directive|endif
block|}
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
comment|/* 	 * Prepare the scsibus_data area for the upperlevel 	 * scsi code. 	 */
name|scbus
operator|=
name|scsi_alloc_bus
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|scbus
condition|)
return|return
literal|0
return|;
name|scbus
operator|->
name|adapter_link
operator|=
operator|(
name|ahc
operator|->
name|flags
operator|&
name|AHC_CHANNEL_B_PRIMARY
operator|)
condition|?
operator|&
name|ahc
operator|->
name|sc_link_b
else|:
operator|&
name|ahc
operator|->
name|sc_link
expr_stmt|;
if|if
condition|(
name|ahc
operator|->
name|type
operator|&
name|AHC_WIDE
condition|)
name|scbus
operator|->
name|maxtarg
operator|=
literal|15
expr_stmt|;
comment|/* 	 * ask the adapter what subunits are present 	 */
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"ahc%d: Probing channel %c\n"
argument_list|,
name|ahc
operator|->
name|unit
argument_list|,
operator|(
name|ahc
operator|->
name|flags
operator|&
name|AHC_CHANNEL_B_PRIMARY
operator|)
condition|?
literal|'B'
else|:
literal|'A'
argument_list|)
expr_stmt|;
name|scsi_attachdevs
argument_list|(
name|scbus
argument_list|)
expr_stmt|;
name|scbus
operator|=
name|NULL
expr_stmt|;
comment|/* Upper-level SCSI code owns this now */
if|if
condition|(
name|ahc
operator|->
name|type
operator|&
name|AHC_TWIN
condition|)
block|{
name|scbus
operator|=
name|scsi_alloc_bus
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|scbus
condition|)
return|return
literal|0
return|;
name|scbus
operator|->
name|adapter_link
operator|=
operator|(
name|ahc
operator|->
name|flags
operator|&
name|AHC_CHANNEL_B_PRIMARY
operator|)
condition|?
operator|&
name|ahc
operator|->
name|sc_link
else|:
operator|&
name|ahc
operator|->
name|sc_link_b
expr_stmt|;
if|if
condition|(
name|ahc
operator|->
name|type
operator|&
name|AHC_WIDE
condition|)
name|scbus
operator|->
name|maxtarg
operator|=
literal|15
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"ahc%d: Probing Channel %c\n"
argument_list|,
name|ahc
operator|->
name|unit
argument_list|,
operator|(
name|ahc
operator|->
name|flags
operator|&
name|AHC_CHANNEL_B_PRIMARY
operator|)
condition|?
literal|'A'
else|:
literal|'B'
argument_list|)
expr_stmt|;
name|scsi_attachdevs
argument_list|(
name|scbus
argument_list|)
expr_stmt|;
name|scbus
operator|=
name|NULL
expr_stmt|;
comment|/* Upper-level SCSI code owns this now */
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
comment|/* 	 * XXX - Update MI SCSI code 	 * 	 * if(ahc->type& AHC_WIDE) 	 *	max target of both channel A and B = 15; 	 */
comment|/* 	 * ask the adapter what subunits are present 	 */
if|if
condition|(
operator|(
name|ahc
operator|->
name|flags
operator|&
name|AHC_CHANNEL_B_PRIMARY
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* make IS_SCSIBUS_B() == false, while probing channel A */
name|ahc
operator|->
name|sc_link_b
operator|.
name|scsibus
operator|=
literal|0xff
expr_stmt|;
if|if
condition|(
name|ahc
operator|->
name|type
operator|&
name|AHC_TWIN
condition|)
name|printf
argument_list|(
literal|"%s: Probing channel A\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|)
expr_stmt|;
name|config_found
argument_list|(
operator|(
name|void
operator|*
operator|)
name|ahc
argument_list|,
operator|&
name|ahc
operator|->
name|sc_link
argument_list|,
name|ahcprint
argument_list|)
expr_stmt|;
if|if
condition|(
name|ahc
operator|->
name|type
operator|&
name|AHC_TWIN
condition|)
block|{
name|printf
argument_list|(
literal|"%s: Probing channel B\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|)
expr_stmt|;
name|config_found
argument_list|(
operator|(
name|void
operator|*
operator|)
name|ahc
argument_list|,
operator|&
name|ahc
operator|->
name|sc_link_b
argument_list|,
name|ahcprint
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* 		 * if implementation of IS_SCSIBUS_B() is changed to use 		 * ahc->sc_link.scsibus, then "ahc->sc_link.scsibus = 0xff;" 		 * is needed, here. 		 */
comment|/* assert(ahc->type& AHC_TWIN); */
name|printf
argument_list|(
literal|"%s: Probing channel B\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|)
expr_stmt|;
name|config_found
argument_list|(
operator|(
name|void
operator|*
operator|)
name|ahc
argument_list|,
operator|&
name|ahc
operator|->
name|sc_link_b
argument_list|,
name|ahcprint
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s: Probing channel A\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|)
expr_stmt|;
name|config_found
argument_list|(
operator|(
name|void
operator|*
operator|)
name|ahc
argument_list|,
operator|&
name|ahc
operator|->
name|sc_link
argument_list|,
name|ahcprint
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Catch an interrupt from the adapter  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_function
name|void
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|int
endif|#
directive|endif
name|ahc_intr
parameter_list|(
name|arg
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
block|{
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
name|u_int8_t
name|intstat
decl_stmt|;
name|ahc
operator|=
operator|(
expr|struct
name|ahc_softc
operator|*
operator|)
name|arg
expr_stmt|;
name|intstat
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|INTSTAT
argument_list|)
expr_stmt|;
comment|/* 	 * Is this interrupt for me? or for 	 * someone who is sharing my interrupt 	 */
if|if
condition|(
operator|!
operator|(
name|intstat
operator|&
name|INT_PEND
operator|)
condition|)
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
return|return;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
return|return
literal|0
return|;
endif|#
directive|endif
if|if
condition|(
name|intstat
operator|&
name|BRKADRINT
condition|)
block|{
comment|/* 		 * We upset the sequencer :-( 		 * Lookup the error message 		 */
name|int
name|i
decl_stmt|,
name|error
decl_stmt|,
name|num_errors
decl_stmt|;
name|error
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|ERROR
argument_list|)
expr_stmt|;
name|num_errors
operator|=
sizeof|sizeof
argument_list|(
name|hard_error
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|hard_error
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|error
operator|!=
literal|1
operator|&&
name|i
operator|<
name|num_errors
condition|;
name|i
operator|++
control|)
name|error
operator|>>=
literal|1
expr_stmt|;
name|panic
argument_list|(
literal|"%s: brkadrint, %s at seqaddr = 0x%x\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|,
name|hard_error
index|[
name|i
index|]
operator|.
name|errmesg
argument_list|,
operator|(
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|SEQADDR1
argument_list|)
operator|<<
literal|8
operator|)
operator||
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|SEQADDR0
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|intstat
operator|&
name|SEQINT
condition|)
name|ahc_handle_seqint
argument_list|(
name|ahc
argument_list|,
name|intstat
argument_list|)
expr_stmt|;
if|if
condition|(
name|intstat
operator|&
name|SCSIINT
condition|)
name|ahc_handle_scsiint
argument_list|(
name|ahc
argument_list|,
name|intstat
argument_list|)
expr_stmt|;
if|if
condition|(
name|intstat
operator|&
name|CMDCMPLT
condition|)
block|{
name|struct
name|scb
modifier|*
name|scb
decl_stmt|;
name|u_int8_t
name|scb_index
decl_stmt|;
name|u_int8_t
name|qoutcnt
decl_stmt|;
name|int
name|int_cleared
decl_stmt|;
name|int_cleared
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|qoutcnt
operator|=
operator|(
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|QOUTCNT
argument_list|)
operator|&
name|ahc
operator|->
name|qcntmask
operator|)
condition|)
block|{
for|for
control|(
init|;
name|qoutcnt
operator|>
literal|0
condition|;
name|qoutcnt
operator|--
control|)
block|{
name|scb_index
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|QOUTFIFO
argument_list|)
expr_stmt|;
name|scb
operator|=
name|ahc
operator|->
name|scb_data
operator|->
name|scbarray
index|[
name|scb_index
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|scb
operator|||
operator|!
operator|(
name|scb
operator|->
name|flags
operator|&
name|SCB_ACTIVE
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"%s: WARNING "
literal|"no command for scb %d "
literal|"(cmdcmplt)\nQOUTCNT == %d\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|,
name|scb_index
argument_list|,
name|qoutcnt
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|untimeout
argument_list|(
name|ahc_timeout
argument_list|,
operator|(
name|caddr_t
operator|)
name|scb
argument_list|)
expr_stmt|;
comment|/* 				 * Save off the residual if there is one. 				 */
if|if
condition|(
name|scb
operator|->
name|hscb
operator|->
name|residual_SG_segment_count
operator|!=
literal|0
condition|)
name|ahc_calc_residual
argument_list|(
name|scb
argument_list|)
expr_stmt|;
name|ahc_done
argument_list|(
name|ahc
argument_list|,
name|scb
argument_list|)
expr_stmt|;
block|}
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|CLRINT
argument_list|,
name|CLRCMDINT
argument_list|)
expr_stmt|;
name|int_cleared
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|int_cleared
operator|==
literal|0
condition|)
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|CLRINT
argument_list|,
name|CLRCMDINT
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ahc
operator|->
name|waiting_scbs
operator|.
name|stqh_first
operator|!=
name|NULL
condition|)
name|ahc_run_waiting_queue
argument_list|(
name|ahc
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
return|return
literal|1
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|void
name|ahc_handle_seqint
parameter_list|(
name|ahc
parameter_list|,
name|intstat
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
name|u_int8_t
name|intstat
decl_stmt|;
block|{
name|struct
name|scb
modifier|*
name|scb
decl_stmt|;
name|u_int16_t
name|targ_mask
decl_stmt|;
name|u_int8_t
name|target
init|=
operator|(
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|SCSIID
argument_list|)
operator|>>
literal|4
operator|)
operator|&
literal|0x0f
decl_stmt|;
name|int
name|scratch_offset
init|=
name|target
decl_stmt|;
name|char
name|channel
init|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|SBLKCTL
argument_list|)
operator|&
name|SELBUSB
condition|?
literal|'B'
else|:
literal|'A'
decl_stmt|;
if|if
condition|(
name|channel
operator|==
literal|'B'
condition|)
name|scratch_offset
operator|+=
literal|8
expr_stmt|;
name|targ_mask
operator|=
operator|(
literal|0x01
operator|<<
name|scratch_offset
operator|)
expr_stmt|;
switch|switch
condition|(
name|intstat
operator|&
name|SEQINT_MASK
condition|)
block|{
case|case
name|NO_MATCH
case|:
block|{
comment|/* 		 * This could be for a normal abort request. 		 * Figure out the SCB that we were trying to find 		 * and only give an error if we didn't ask for this 		 * to happen. 		 */
name|u_int8_t
name|scb_index
decl_stmt|;
name|u_int8_t
name|busy_scbid
decl_stmt|;
name|busy_scbid
operator|=
name|ahc_unbusy_target
argument_list|(
name|ahc
argument_list|,
name|target
argument_list|,
name|channel
argument_list|)
expr_stmt|;
name|scb_index
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|ARG_1
argument_list|)
expr_stmt|;
if|if
condition|(
name|scb_index
operator|==
name|SCB_LIST_NULL
condition|)
comment|/* Untagged Request */
name|scb_index
operator|=
name|busy_scbid
expr_stmt|;
if|if
condition|(
name|scb_index
operator|<
name|ahc
operator|->
name|scb_data
operator|->
name|numscbs
condition|)
block|{
name|scb
operator|=
name|ahc
operator|->
name|scb_data
operator|->
name|scbarray
index|[
name|busy_scbid
index|]
expr_stmt|;
if|if
condition|(
name|scb
operator|->
name|hscb
operator|->
name|control
operator|&
name|ABORT_SCB
condition|)
block|{
name|sc_print_addr
argument_list|(
name|scb
operator|->
name|xs
operator|->
name|sc_link
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" - SCB abort successfull\n"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|printf
argument_list|(
literal|"%s:%c:%d: no active SCB for reconnecting "
literal|"target - issuing ABORT\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|,
name|channel
argument_list|,
name|target
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"SAVED_TCL == 0x%x\n"
argument_list|,
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|SAVED_TCL
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|NO_MATCH_BUSY
case|:
block|{
comment|/* The SCB that wanted to link in is in CUR_SCBID */
name|u_int8_t
name|scb_index
decl_stmt|;
name|u_int8_t
name|busy_scbindex
decl_stmt|;
name|struct
name|scb
modifier|*
name|busy_scb
init|=
name|NULL
decl_stmt|;
name|scb_index
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|CUR_SCBID
argument_list|)
expr_stmt|;
name|scb
operator|=
name|ahc
operator|->
name|scb_data
operator|->
name|scbarray
index|[
name|scb_index
index|]
expr_stmt|;
comment|/* Find the busy SCB and unbusy this target */
name|busy_scbindex
operator|=
name|ahc_unbusy_target
argument_list|(
name|ahc
argument_list|,
name|scb
operator|->
name|xs
operator|->
name|sc_link
operator|->
name|target
argument_list|,
name|channel
argument_list|)
expr_stmt|;
if|if
condition|(
name|busy_scbindex
operator|==
name|SCB_LIST_NULL
condition|)
name|panic
argument_list|(
literal|"%s:%c:%d: Target busy link failure, but "
literal|"the target is not busy!\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|,
name|channel
argument_list|,
name|target
argument_list|)
expr_stmt|;
name|busy_scb
operator|=
name|ahc
operator|->
name|scb_data
operator|->
name|scbarray
index|[
name|busy_scbindex
index|]
expr_stmt|;
comment|/* Busy SCB should be aborted */
if|if
condition|(
operator|(
name|busy_scb
operator|!=
name|NULL
operator|)
operator|&&
operator|(
name|busy_scb
operator|->
name|hscb
operator|->
name|control
operator|&
name|ABORT_SCB
operator|)
operator|==
literal|0
operator|&&
operator|(
name|busy_scb
operator|->
name|hscb
operator|->
name|control
operator|&
name|SCB_ACTIVE
operator|)
operator|!=
literal|0
condition|)
block|{
name|panic
argument_list|(
literal|"%s:%c:%d: Target busy link failure, but "
literal|"busy SCB exists!\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|,
name|channel
argument_list|,
name|target
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|scb
operator|->
name|hscb
operator|->
name|control
operator|&
name|ABORT_SCB
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* We didn't want to abort this one too */
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|QINFIFO
argument_list|,
name|scb_index
argument_list|)
expr_stmt|;
block|}
else|else
comment|/* It's been aborted */
name|ahc_done
argument_list|(
name|ahc
argument_list|,
name|scb
argument_list|)
expr_stmt|;
name|restart_sequencer
argument_list|(
name|ahc
argument_list|)
expr_stmt|;
block|}
case|case
name|SEND_REJECT
case|:
block|{
name|u_int8_t
name|rejbyte
init|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|REJBYTE
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|"%s:%c:%d: Warning - unknown message recieved from "
literal|"target (0x%x).  Rejecting\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|,
name|channel
argument_list|,
name|target
argument_list|,
name|rejbyte
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|NO_IDENT
case|:
name|panic
argument_list|(
literal|"%s:%c:%d: Target did not send an IDENTIFY message. "
literal|"SAVED_TCL == 0x%x\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|,
name|channel
argument_list|,
name|target
argument_list|,
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|SAVED_TCL
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|BAD_PHASE
case|:
name|printf
argument_list|(
literal|"%s:%c:%d: unknown scsi bus phase.  Attempting to "
literal|"continue\n"
argument_list|,
name|ahc_name
argument_list|(
name|ahc
argument_list|)
argument_list|,
name|channel
argument_list|,
name|target
argument_list|)
expr_stmt|;
break|break;
case|case
name|EXTENDED_MSG
case|:
block|{
name|u_int8_t
name|message_length
decl_stmt|;
name|u_int8_t
name|message_code
decl_stmt|;
name|message_length
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|MSGIN_EXT_LEN
argument_list|)
expr_stmt|;
name|message_code
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|MSGIN_EXT_OPCODE
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|message_code
condition|)
block|{
case|case
name|MSG_EXT_SDTR
case|:
block|{
name|u_int8_t
name|period
decl_stmt|;
name|u_int8_t
name|offset
decl_stmt|;
name|u_int8_t
name|saved_offset
decl_stmt|;
name|u_int8_t
name|targ_scratch
decl_stmt|;
name|u_int8_t
name|maxoffset
decl_stmt|;
name|u_int8_t
name|rate
decl_stmt|;
if|if
condition|(
name|message_length
operator|!=
name|MSG_EXT_SDTR_LEN
condition|)
block|{
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|RETURN_1
argument_list|,
name|SEND_REJ
argument_list|)
expr_stmt|;
name|ahc
operator|->
name|sdtrpending
operator|&=
operator|~
name|targ_mask
expr_stmt|;
break|break;
block|}
name|period
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|MSGIN_EXT_BYTE0
argument_list|)
expr_stmt|;
name|saved_offset
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|MSGIN_EXT_BYTE1
argument_list|)
expr_stmt|;
name|targ_scratch
operator|=
name|AHC_INB
argument_list|(
name|ahc
argument_list|,
name|TARG_SCRATCH
operator|+
name|scratch_offset
argument_list|)
expr_stmt|;
if|if
condition|(
name|targ_scratch
operator|&
name|WIDEXFER
condition|)
name|maxoffset
operator|=
name|MAX_OFFSET_16BIT
expr_stmt|;
else|else
name|maxoffset
operator|=
name|MAX_OFFSET_8BIT
expr_stmt|;
name|offset
operator|=
name|MIN
argument_list|(
name|saved_offset
argument_list|,
name|maxoffset
argument_list|)
expr_stmt|;
name|ahc_scsirate
argument_list|(
name|ahc
argument_list|,
operator|&
name|rate
argument_list|,
operator|&
name|period
argument_list|,
operator|&
name|offset
argument_list|,
name|channel
argument_list|,
name|target
argument_list|)
expr_stmt|;
comment|/* Preserve the WideXfer flag */
name|targ_scratch
operator|=
name|rate
operator||
operator|(
name|targ_scratch
operator|&
name|WIDEXFER
operator|)
expr_stmt|;
comment|/* 			 * Update both the target scratch area and the 			 * current SCSIRATE. 			 */
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|TARG_SCRATCH
operator|+
name|scratch_offset
argument_list|,
name|targ_scratch
argument_list|)
expr_stmt|;
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|SCSIRATE
argument_list|,
name|targ_scratch
argument_list|)
expr_stmt|;
comment|/* 			 * See if we initiated Sync Negotiation 			 * and didn't have to fall down to async 			 * transfers. 			 */
if|if
condition|(
operator|(
name|ahc
operator|->
name|sdtrpending
operator|&
name|targ_mask
operator|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|saved_offset
operator|==
name|offset
condition|)
block|{
comment|/* 					 * Don't send an SDTR back to 					 * the target 					 */
name|AHC_OUTB
argument_list|(
name|ahc
argument_list|,
name|RETURN_1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
name|AHC_OUTB
argument_list|(
argument|ahc
argument_list|,
argument|RETURN_1
argument_list|,
argument|SEND_REJ; 			} else {
comment|/* 				 * Send our own SDTR in reply 				 */
argument|printf(
literal|"Sending SDTR!!\n"
argument|); 				ahc_construct_sdtr(ahc,
comment|/*start_byte*/
literal|0
argument|, 						   period, offset); 				AHC_OUTB(ahc, RETURN_1, SEND_MSG); 			} 			ahc->needsdtr&= ~targ_mask; 			ahc->sdtrpending&= ~targ_mask; 			break; 		} 		case MSG_EXT_WDTR: 		{ 			u_int8_t scratch
argument_list|,
argument|bus_width;  			if (message_length != MSG_EXT_WDTR_LEN) { 				AHC_OUTB(ahc, RETURN_1, SEND_REJ); 				ahc->wdtrpending&= ~targ_mask; 				break; 			}  			bus_width = AHC_INB(ahc, MSGIN_EXT_BYTE0); 			scratch = AHC_INB(ahc, TARG_SCRATCH 					  + scratch_offset);  			if (ahc->wdtrpending& targ_mask) {
comment|/* 				 * Don't send a WDTR back to the 				 * target, since we asked first. 				 */
argument|AHC_OUTB(ahc, RETURN_1,
literal|0
argument|); 				switch (bus_width){ 				case BUS_8_BIT: 					scratch&=
literal|0x7f
argument|; 					break; 				case BUS_16_BIT: 					if (bootverbose) 						printf(
literal|"%s: target %d using "
literal|"16Bit transfers\n"
argument|, 						       ahc_name(ahc), target); 					scratch |= WIDEXFER;	 					break; 				case BUS_32_BIT:
comment|/* 					 * How can we do 32bit transfers 					 * on a 16bit bus? 					 */
argument|AHC_OUTB(ahc, RETURN_1, SEND_REJ); 					printf(
literal|"%s: target %d requested 32Bit "
literal|"transfers.  Rejecting...\n"
argument|, 					       ahc_name(ahc), target); 					break; 				default: 					break; 				} 			} else {
comment|/* 				 * Send our own WDTR in reply 				 */
argument|switch (bus_width) { 				case BUS_8_BIT: 					scratch&=
literal|0x7f
argument|; 					break; 				case BUS_32_BIT: 				case BUS_16_BIT: 					if (ahc->type& AHC_WIDE) {
comment|/* Negotiate 16_BITS */
argument|bus_width = BUS_16_BIT; 						if (bootverbose) 							printf(
literal|"%s: target %d "
literal|"using 16Bit "
literal|"transfers\n"
argument|, 							       ahc_name(ahc), 							       target); 						scratch |= WIDEXFER;	 					} else 						bus_width = BUS_8_BIT; 					break; 				default: 					break; 				} 				ahc_construct_wdtr(ahc,
comment|/*start_byte*/
literal|0
argument|, 						   bus_width); 				AHC_OUTB(ahc, RETURN_1, SEND_MSG); 			} 			 			ahc->needwdtr&= ~targ_mask; 			ahc->wdtrpending&= ~targ_mask; 			AHC_OUTB(ahc, TARG_SCRATCH + scratch_offset, scratch); 			AHC_OUTB(ahc, SCSIRATE, scratch);  			break; 		} 		default:
comment|/* Unknown extended message.  Reject it. */
argument|AHC_OUTB(ahc, RETURN_1, SEND_REJ); 		} 		break; 	} 	case REJECT_MSG: 	{
comment|/* 		 * What we care about here is if we had an 		 * outstanding SDTR or WDTR message for this 		 * target.  If we did, this is a signal that 		 * the target is refusing negotiation. 		 */
argument|u_int8_t targ_scratch;  		targ_scratch = AHC_INB(ahc, TARG_SCRATCH 				       + scratch_offset);  		if (ahc->wdtrpending& targ_mask) {
comment|/* note 8bit xfers and clear flag */
argument|targ_scratch&=
literal|0x7f
argument|; 			ahc->needwdtr&= ~targ_mask; 			ahc->wdtrpending&= ~targ_mask; 			printf(
literal|"%s:%c:%d: refuses WIDE negotiation.  Using "
literal|"8bit transfers\n"
argument|, ahc_name(ahc), 			       channel, target); 		} else if (ahc->sdtrpending& targ_mask) {
comment|/* note asynch xfers and clear flag */
argument|targ_scratch&=
literal|0xf0
argument|; 			ahc->needsdtr&= ~targ_mask; 			ahc->sdtrpending&= ~targ_mask; 			printf(
literal|"%s:%c:%d: refuses syncronous negotiation. "
literal|"Using asyncronous transfers\n"
argument|, 			       ahc_name(ahc), 			       channel, target); 		} else {
comment|/* 			 * Otherwise, we ignore it. 			 */
ifdef|#
directive|ifdef
name|AHC_DEBUG
argument|if (ahc_debug& AHC_SHOWMISC) 				printf(
literal|"%s:%c:%d: Message reject -- ignored\n"
argument|, 				       ahc_name(ahc), channel, target);
endif|#
directive|endif
argument|break; 		} 		AHC_OUTB(ahc, TARG_SCRATCH + scratch_offset, targ_scratch); 		AHC_OUTB(ahc, SCSIRATE, targ_scratch); 		break; 	} 	case BAD_STATUS: 	{ 		u_int8_t scb_index; 		struct	 scsi_xfer *xs; 		struct	 hardware_scb *hscb;
comment|/* 		 * The sequencer will notify us when a command 		 * has an error that would be of interest to 		 * the kernel.  This allows us to leave the sequencer 		 * running in the common case of command completes 		 * without error.  The sequencer will already have 		 * dma'd the SCB back up to us, so we can reference 		 * the in kernel copy directly. 		 */
argument|scb_index = AHC_INB(ahc, SCB_TAG); 		scb = ahc->scb_data->scbarray[scb_index]; 		hscb = scb->hscb;
comment|/* 		 * Set the default return value to 0 (don't 		 * send sense).  The sense code will change 		 * this if needed and this reduces code 		 * duplication. 		 */
argument|AHC_OUTB(ahc, RETURN_1,
literal|0
argument|); 		if (!(scb&& (scb->flags& SCB_ACTIVE))) { 			printf(
literal|"%s:%c:%d: ahc_intr - referenced scb "
literal|"not valid during seqint 0x%x scb(%d)\n"
argument|, 			       ahc_name(ahc), 			       channel, target, intstat, 			       scb_index); 			goto clear; 		}  		xs = scb->xs;  		xs->status = hscb->status; 		switch (hscb->status){ 		case SCSI_OK: 			printf(
literal|"%s: Interrupted for staus of"
literal|" 0???\n"
argument|, ahc_name(ahc)); 			break; 		case SCSI_CHECK:
ifdef|#
directive|ifdef
name|AHC_DEBUG
argument|if (ahc_debug& AHC_SHOWSENSE) { 				sc_print_addr(xs->sc_link); 				printf(
literal|"requests Check Status\n"
argument|); 			}
endif|#
directive|endif
argument|if ((xs->error == XS_NOERROR)&& !(scb->flags& SCB_SENSE)) { 				struct ahc_dma_seg *sg = scb->ahc_dma; 				struct scsi_sense *sc =&(scb->sense_cmd);
comment|/* 				 * Save off the residual if there is one. 				 */
argument|if (hscb->residual_SG_segment_count !=
literal|0
argument|) 					ahc_calc_residual(scb);
ifdef|#
directive|ifdef
name|AHC_DEBUG
argument|if (ahc_debug& AHC_SHOWSENSE) { 					sc_print_addr(xs->sc_link); 					printf(
literal|"Sending Sense\n"
argument|); 				}
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
argument|sc->op_code = REQUEST_SENSE;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
argument|sc->opcode = REQUEST_SENSE;
endif|#
directive|endif
argument|sc->byte2 =  xs->sc_link->lun<<
literal|5
argument|; 				sc->length = sizeof(struct scsi_sense_data); 				sc->control =
literal|0
argument|;  				sg->addr = vtophys(&xs->sense); 				sg->len = sizeof(struct scsi_sense_data);  				hscb->control&= DISCENB; 				hscb->status =
literal|0
argument|; 				hscb->SG_segment_count =
literal|1
argument|; 				hscb->SG_list_pointer = vtophys(sg); 				hscb->data = sg->addr;
comment|/* Maintain SCB_LINKED_NEXT */
argument|hscb->datalen&=
literal|0xFF000000
argument|; 				hscb->datalen |= sg->len; 				hscb->cmdpointer = vtophys(sc); 				hscb->cmdlen = sizeof(*sc);  				scb->flags |= SCB_SENSE; 				AHC_OUTB(ahc, RETURN_1, SEND_SENSE); 				break; 			}
comment|/* 			 * Clear the SCB_SENSE Flag and have 			 * the sequencer do a normal command 			 * complete with either a "DRIVER_STUFFUP" 			 * error or whatever other error condition 			 * we already had. 			 */
argument|scb->flags&= ~SCB_SENSE; 			if (xs->error == XS_NOERROR) 				xs->error = XS_DRIVER_STUFFUP; 			break; 		case SCSI_BUSY: 			xs->error = XS_BUSY; 			sc_print_addr(xs->sc_link); 			printf(
literal|"Target Busy\n"
argument|); 			break; 		case SCSI_QUEUE_FULL:
comment|/* 			 * The upper level SCSI code will someday 			 * handle this properly. 			 */
argument|printf(
literal|"Queue Full\n"
argument|); 			xs->error = XS_BUSY; 			break; 		default: 			sc_print_addr(xs->sc_link); 			printf(
literal|"unexpected targ_status: %x\n"
argument|, hscb->status); 			xs->error = XS_DRIVER_STUFFUP; 			break; 		} 		break; 	} 	case ABORT_TAG: 	{ 		u_int8_t scb_index; 		struct scsi_xfer *xs;  		scb_index = AHC_INB(ahc, SCB_TAG); 		scb = ahc->scb_data->scbarray[scb_index]; 		xs = scb->xs;
comment|/* 		 * We didn't recieve a valid tag back from 		 * the target on a reconnect. 		 */
argument|sc_print_addr(xs->sc_link); 		printf(
literal|"invalid tag recieved -- sending ABORT_TAG\n"
argument|); 		xs->error = XS_DRIVER_STUFFUP; 		untimeout(ahc_timeout, (caddr_t)scb); 		ahc_done(ahc, scb); 		break; 	} 	case AWAITING_MSG: 	{ 		int   scb_index;  		scb_index = AHC_INB(ahc, SCB_TAG); 		scb = ahc->scb_data->scbarray[scb_index];
comment|/* 		 * This SCB had MK_MESSAGE set in its control byte, 		 * informing the sequencer that we wanted to send a 		 * special message to this target. 		 */
argument|if (scb->flags& SCB_DEVICE_RESET) { 			AHC_OUTB(ahc, MSG0, 				 MSG_BUS_DEV_RESET); 			AHC_OUTB(ahc, MSG_LEN,
literal|1
argument|); 			printf(
literal|"Bus Device Reset Message Sent\n"
argument|); 		} else if (scb->flags& SCB_MSGOUT_WDTR) { 			ahc_construct_wdtr(ahc, AHC_INB(ahc, MSG_LEN), 					   BUS_16_BIT); 		} else if (scb->flags& SCB_MSGOUT_SDTR) { 			u_int8_t target_scratch; 			u_int8_t ultraenable;			 			int sxfr; 			int i;
comment|/* Pull the user defined setting */
argument|target_scratch = AHC_INB(ahc, TARG_SCRATCH 						 + scratch_offset); 			 			sxfr = target_scratch& SXFR; 			if (scratch_offset<
literal|8
argument|) 				ultraenable = AHC_INB(ahc, ULTRA_ENB); 			else 				ultraenable = AHC_INB(ahc, ULTRA_ENB +
literal|1
argument|); 			 			if (ultraenable& targ_mask)
comment|/* Want an ultra speed in the table */
argument|sxfr |=
literal|0x100
argument|; 			 			for (i =
literal|0
argument|; i< ahc_num_syncrates; i++) 				if (sxfr == ahc_syncrates[i].sxfr) 					break; 							 			ahc_construct_sdtr(ahc, AHC_INB(ahc, MSG_LEN), 					   ahc_syncrates[i].period, 					   (target_scratch& WIDEXFER) ? 					   MAX_OFFSET_16BIT : MAX_OFFSET_8BIT); 		} else	 			panic(
literal|"ahc_intr: AWAITING_MSG for an SCB that "
literal|"does not have a waiting message"
argument|); 		break; 	} 	case IMMEDDONE: 	{
comment|/* 		 * Take care of device reset messages 		 */
argument|u_int8_t scbindex = AHC_INB(ahc, SCB_TAG);  		scb = ahc->scb_data->scbarray[scbindex]; 		if (scb->flags& SCB_DEVICE_RESET) { 			u_int8_t targ_scratch; 			int found;
comment|/* 			 * Go back to async/narrow transfers and 			 * renegotiate. 			 */
argument|ahc_unbusy_target(ahc, target, channel); 			ahc->needsdtr |= ahc->needsdtr_orig& targ_mask; 			ahc->needwdtr |= ahc->needwdtr_orig& targ_mask; 			ahc->sdtrpending&= ~targ_mask; 			ahc->wdtrpending&= ~targ_mask; 			targ_scratch = AHC_INB(ahc, TARG_SCRATCH  					       + scratch_offset); 			targ_scratch&= SXFR; 			AHC_OUTB(ahc, TARG_SCRATCH + scratch_offset, 				 targ_scratch); 			found = ahc_reset_device(ahc, target, 						 channel, NULL,  						 XS_NOERROR); 			sc_print_addr(scb->xs->sc_link); 			printf(
literal|"Bus Device Reset delivered. "
literal|"%d SCBs aborted\n"
argument|, found); 			ahc->in_timeout = FALSE; 			ahc_run_done_queue(ahc); 		} else 			panic(
literal|"ahc_intr: Immediate complete for "
literal|"unknown operation."
argument|); 		break; 	} 	case DATA_OVERRUN: 	{
comment|/* 		 * When the sequencer detects an overrun, it 		 * sets STCNT to 0x00ffffff and allows the 		 * target to complete its transfer in 		 * BITBUCKET mode. 		 */
argument|u_int8_t scbindex = AHC_INB(ahc, SCB_TAG); 		u_int32_t overrun; 		scb = ahc->scb_data->scbarray[scbindex]; 		overrun = AHC_INB(ahc, STCNT0) 			| (AHC_INB(ahc, STCNT1)<<
literal|8
argument|) 			| (AHC_INB(ahc, STCNT2)<<
literal|16
argument|); 		overrun =
literal|0x00ffffff
argument|- overrun; 		sc_print_addr(scb->xs->sc_link); 		printf(
literal|"data overrun of %d bytes detected."
literal|"  Forcing a retry.\n"
argument|, overrun);
comment|/* 		 * Set this and it will take affect when the 		 * target does a command complete. 		 */
argument|scb->xs->error = XS_DRIVER_STUFFUP; 		break; 	}
if|#
directive|if
name|NOT_YET
comment|/* XXX Fill these in later */
argument|case MESG_BUFFER_BUSY: 		break; 	case MSGIN_PHASEMIS: 		break;
endif|#
directive|endif
argument|default: 		printf(
literal|"ahc_intr: seqint, "
literal|"intstat == 0x%x, scsisigi = 0x%x\n"
argument|, 		       intstat, AHC_INB(ahc, SCSISIGI)); 		break; 	} 	 clear:
comment|/* 	 * Clear the upper byte that holds SEQINT status 	 * codes and clear the SEQINT bit. 	 */
argument|AHC_OUTB(ahc, CLRINT, CLRSEQINT);
comment|/* 	 *  The sequencer is paused immediately on 	 *  a SEQINT, so we should restart it when 	 *  we're done. 	 */
argument|unpause_sequencer(ahc,
comment|/*unpause_always*/
argument|TRUE); }  static void ahc_handle_scsiint(ahc, intstat) 	struct ahc_softc *ahc; 	u_int8_t intstat; { 	u_int8_t scb_index; 	u_int8_t status; 	struct scb *scb;  	scb_index = AHC_INB(ahc, SCB_TAG); 	status = AHC_INB(ahc, SSTAT1); 	scb = ahc->scb_data->scbarray[scb_index];  	if (status& SCSIRSTI) { 		char channel; 		channel = (AHC_INB(ahc, SBLKCTL)& SELBUSB) ?
literal|'B'
argument|:
literal|'A'
argument|; 		printf(
literal|"%s: Someone reset channel %c\n"
argument|, 			ahc_name(ahc), channel); 		ahc_reset_channel(ahc,  				  channel, 				  NULL, 				  XS_BUSY,
comment|/* Initiate Reset */
argument|FALSE); 		scb = NULL; 	} else if (!(scb&& (scb->flags& SCB_ACTIVE))){ 		printf(
literal|"%s: ahc_intr - referenced scb not "
literal|"valid during scsiint 0x%x scb(%d)\n"
argument|, 			ahc_name(ahc), status, scb_index); 		AHC_OUTB(ahc, CLRSINT1, status); 		unpause_sequencer(ahc,
comment|/*unpause_always*/
argument|TRUE); 		AHC_OUTB(ahc, CLRINT, CLRSCSIINT); 		scb = NULL; 	} else if (status& SCSIPERR) {
comment|/* 		 * Determine the bus phase and 		 * queue an appropriate message 		 */
argument|char	 *phase; 		u_int8_t mesg_out = MSG_NOOP; 		u_int8_t lastphase = AHC_INB(ahc, LASTPHASE); 		struct	 scsi_xfer *xs;  		xs = scb->xs; 		sc_print_addr(xs->sc_link);  		switch (lastphase) { 		case P_DATAOUT: 			phase =
literal|"Data-Out"
argument|; 			break; 		case P_DATAIN: 			phase =
literal|"Data-In"
argument|; 			mesg_out = MSG_INITIATOR_DET_ERR; 			break; 		case P_COMMAND: 			phase =
literal|"Command"
argument|; 			break; 		case P_MESGOUT: 			phase =
literal|"Message-Out"
argument|; 			break; 		case P_STATUS: 			phase =
literal|"Status"
argument|; 			mesg_out = MSG_INITIATOR_DET_ERR; 			break; 		case P_MESGIN: 			phase =
literal|"Message-In"
argument|; 			mesg_out = MSG_PARITY_ERROR; 			break; 		default: 			phase =
literal|"unknown"
argument|; 			break; 		} 		printf(
literal|"parity error during %s phase.\n"
argument|, phase);
comment|/* 		 * We've set the hardware to assert ATN if we    		 * get a parity error on "in" phases, so all we   		 * need to do is stuff the message buffer with 		 * the appropriate message.  "In" phases have set 		 * mesg_out to something other than MSG_NOP. 		 */
argument|if (mesg_out != MSG_NOOP) { 			AHC_OUTB(ahc, MSG0, mesg_out); 			AHC_OUTB(ahc, MSG_LEN,
literal|1
argument|); 		} else
comment|/* 			 * Should we allow the target to make 			 * this decision for us? 			 */
argument|xs->error = XS_DRIVER_STUFFUP; 	} else if (status& SELTO) { 		struct scsi_xfer *xs; 		u_int8_t scbptr; 		u_int8_t nextscb; 		u_int8_t flags;  		xs = scb->xs; 		xs->error = XS_SELTIMEOUT;
comment|/* 		 * Clear any pending messages for the timed out 		 * target, and mark the target as free 		 */
argument|flags = AHC_INB(ahc, FLAGS); 		AHC_OUTB(ahc, MSG_LEN,
literal|0
argument|); 		ahc_unbusy_target(ahc, xs->sc_link->target, 				  IS_SCSIBUS_B(ahc, xs->sc_link) ?
literal|'B'
argument|:
literal|'A'
argument|);
comment|/* Stop the selection */
argument|AHC_OUTB(ahc, SCSISEQ,
literal|0
argument|);  		AHC_OUTB(ahc, SCB_CONTROL,
literal|0
argument|);  		AHC_OUTB(ahc, CLRSINT1, CLRSELTIMEO);  		AHC_OUTB(ahc, CLRINT, CLRSCSIINT);
comment|/* Shift the waiting Q forward. */
argument|scbptr = AHC_INB(ahc, WAITING_SCBH); 		AHC_OUTB(ahc, SCBPTR, scbptr); 		nextscb = AHC_INB(ahc, SCB_NEXT); 		AHC_OUTB(ahc, WAITING_SCBH, nextscb);
comment|/* Put this SCB back on the free list */
argument|nextscb = AHC_INB(ahc, FREE_SCBH); 		AHC_OUTB(ahc, SCB_NEXT, nextscb); 		AHC_OUTB(ahc, FREE_SCBH, scbptr); 		restart_sequencer(ahc); 	} else if (!(status& BUSFREE)) { 		sc_print_addr(scb->xs->sc_link); 		printf(
literal|"Unknown SCSIINT. Status = 0x%x\n"
argument|, status); 		AHC_OUTB(ahc, CLRSINT1, status); 		unpause_sequencer(ahc,
comment|/*unpause_always*/
argument|TRUE); 		AHC_OUTB(ahc, CLRINT, CLRSCSIINT); 		scb = NULL; 	} 	if (scb != NULL) {
comment|/* We want to process the command */
argument|untimeout(ahc_timeout, (caddr_t)scb); 		ahc_done(ahc, scb); 	} }
comment|/*  * We have a scb which has been processed by the  * adaptor, now we look to see how the operation  * went.  */
argument|static void ahc_done(ahc, scb) 	struct ahc_softc *ahc; 	struct scb *scb; { 	struct scsi_xfer *xs = scb->xs;  	SC_DEBUG(xs->sc_link, SDEV_DB2, (
literal|"ahc_done\n"
argument|));
comment|/* 	 * Put the results of the operation 	 * into the xfer and call whoever started it 	 */
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
argument|if (xs->error != XS_NOERROR) {
comment|/* Don't override the error value. */
argument|} else if (scb->flags& SCB_ABORTED) { 		xs->error = XS_DRIVER_STUFFUP; 	} else
endif|#
directive|endif
argument|if (scb->flags& SCB_SENSE) 		xs->error = XS_SENSE; 	if (scb->flags& SCB_SENTORDEREDTAG) 		ahc->in_timeout = FALSE;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
argument|if ((xs->flags& SCSI_ERR_OK)&& !(xs->error == XS_SENSE)) {
comment|/* All went correctly  OR errors expected */
argument|xs->error = XS_NOERROR; 	}
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
comment|/* 	 * Since NetBSD doesn't have error ignoring operation mode 	 * (SCSI_ERR_OK in FreeBSD), we don't have to care this case. 	 */
endif|#
directive|endif
argument|xs->flags |= ITSDONE;
ifdef|#
directive|ifdef
name|AHC_TAGENABLE
comment|/* 	 * This functionality is provided by the generic SCSI layer  	 * in FreeBSD 2.2. 	 */
argument|if (xs->cmd->opcode == INQUIRY&& xs->error == XS_NOERROR) { 		struct scsi_inquiry_data *inq_data; 		u_int16_t mask =
literal|0x01
argument|<< (xs->sc_link->target | 				          (scb->hscb->tcl&
literal|0x08
argument|));
comment|/* 		 * Sneak a look at the results of the SCSI Inquiry 		 * command and see if we can do Tagged queing.  This 		 * should really be done by the higher level drivers. 		 */
argument|inq_data = (struct scsi_inquiry_data *)xs->data; 		if ((inq_data->flags& SID_CmdQue)&& !(ahc->tagenable& mask)) { 		        printf(
literal|"%s: target %d Tagged Queuing Device\n"
argument|, 				ahc_name(ahc), xs->sc_link->target); 			ahc->tagenable |= mask; 			if (ahc->scb_data->maxhscbs>=
literal|16
argument||| (ahc->flags& AHC_PAGESCBS)) {
comment|/* Default to 8 tags */
argument|xs->sc_link->opennings +=
literal|6
argument|; 			} else {
comment|/* 				 * Default to 4 tags on whimpy 				 * cards that don't have much SCB 				 * space and can't page.  This prevents 				 * a single device from hogging all 				 * slots.  We should really have a better 				 * way of providing fairness. 				 */
argument|xs->sc_link->opennings +=
literal|2
argument|; 			} 		} 	}
endif|#
directive|endif
comment|/* AHC_TAGENABLE */
argument|ahc_free_scb(ahc, scb); 	scsi_done(xs); }
comment|/*  * Start the board, ready for normal operation  */
argument|int ahc_init(ahc) 	struct  ahc_softc *ahc; { 	u_int8_t  scsi_conf
argument_list|,
argument|sblkctl
argument_list|,
argument|i; 	u_int16_t ultraenable =
literal|0
argument|; 	int       max_targ =
literal|15
argument|;
comment|/* 	 * Assume we have a board at this stage and it has been reset. 	 */
comment|/* Handle the SCBPAGING option */
ifndef|#
directive|ifndef
name|AHC_SCBPAGING_ENABLE
argument|ahc->flags&= ~AHC_PAGESCBS;
endif|#
directive|endif
comment|/* Determine channel configuration and who we are on the scsi bus. */
argument|switch ((sblkctl = AHC_INB(ahc, SBLKCTL)&
literal|0x0a
argument|)) { 	case
literal|0
argument|: 		ahc->our_id = (AHC_INB(ahc, SCSICONF)& HSCSIID); 		ahc->flags&= ~AHC_CHANNEL_B_PRIMARY; 		if ((ahc->type& AHC_39X) !=
literal|0
argument|) { 			char channel =
literal|'A'
argument|;  			if ((ahc->flags& (AHC_CHNLB|AHC_CHNLC)) !=
literal|0
argument|) 				channel = ahc->flags& AHC_CHNLB ?
literal|'B'
argument|:
literal|'C'
argument|; 			printf(
literal|"Channel %c, SCSI Id=%d, "
argument|, channel, 				ahc->our_id); 		} else 			printf(
literal|"Single Channel, SCSI Id=%d, "
argument|, ahc->our_id); 		AHC_OUTB(ahc, FLAGS, SINGLE_BUS | (ahc->flags& AHC_PAGESCBS)); 		break; 	case
literal|2
argument|: 		ahc->our_id = (AHC_INB(ahc, SCSICONF +
literal|1
argument|)& HWSCSIID); 		ahc->flags&= ~AHC_CHANNEL_B_PRIMARY; 		if ((ahc->type& AHC_39X) !=
literal|0
argument|)  { 			char channel =
literal|'A'
argument|;  			if ((ahc->flags& (AHC_CHNLB|AHC_CHNLC)) !=
literal|0
argument|) 				channel = ahc->flags& AHC_CHNLB ?
literal|'B'
argument|:
literal|'C'
argument|; 			printf(
literal|"Wide Channel %c, SCSI Id=%d, "
argument|, channel, 				ahc->our_id); 		} else 			printf(
literal|"Wide Channel, SCSI Id=%d, "
argument|, ahc->our_id); 		ahc->type |= AHC_WIDE; 		AHC_OUTB(ahc, FLAGS, WIDE_BUS | (ahc->flags& AHC_PAGESCBS)); 		break; 	case
literal|8
argument|: 		ahc->our_id = (AHC_INB(ahc, SCSICONF)& HSCSIID); 		ahc->our_id_b = (AHC_INB(ahc, SCSICONF +
literal|1
argument|)& HSCSIID); 		printf(
literal|"Twin Channel, A SCSI Id=%d, B SCSI Id=%d, "
argument|, 			ahc->our_id, ahc->our_id_b); 		ahc->type |= AHC_TWIN; 		AHC_OUTB(ahc, FLAGS, TWIN_BUS | (ahc->flags& AHC_PAGESCBS)); 		break; 	default: 		printf(
literal|" Unsupported adapter type.  Ignoring\n"
argument|); 		return(-
literal|1
argument|); 	}
comment|/* Determine the number of SCBs and initialize them */
argument|if (ahc->scb_data->maxhscbs ==
literal|0
argument|) {
comment|/* SCB 0 heads the free list */
argument|AHC_OUTB(ahc, FREE_SCBH,
literal|0
argument|); 		for (i =
literal|0
argument|; i< AHC_SCB_MAX; i++) { 			AHC_OUTB(ahc, SCBPTR, i); 			AHC_OUTB(ahc, SCB_CONTROL, i); 			if(AHC_INB(ahc, SCB_CONTROL) != i) 				break; 			AHC_OUTB(ahc, SCBPTR,
literal|0
argument|); 			if(AHC_INB(ahc, SCB_CONTROL) !=
literal|0
argument|) 				break; 			AHC_OUTB(ahc, SCBPTR, i);
comment|/* Clear the control byte. */
argument|AHC_OUTB(ahc, SCB_CONTROL,
literal|0
argument|);
comment|/* Set the next pointer */
argument|AHC_OUTB(ahc, SCB_NEXT, i+
literal|1
argument|);
comment|/* No Busy non-tagged targets yet */
argument|AHC_OUTB(ahc, SCB_ACTIVE0, SCB_LIST_NULL); 			AHC_OUTB(ahc, SCB_ACTIVE1, SCB_LIST_NULL); 			AHC_OUTB(ahc, SCB_ACTIVE2, SCB_LIST_NULL); 			AHC_OUTB(ahc, SCB_ACTIVE3, SCB_LIST_NULL); 		}
comment|/* Make that the last SCB terminates the free list */
argument|AHC_OUTB(ahc, SCBPTR, i-
literal|1
argument|); 		AHC_OUTB(ahc, SCB_NEXT, SCB_LIST_NULL);
comment|/* Ensure we clear the 0 SCB's control byte. */
argument|AHC_OUTB(ahc, SCBPTR,
literal|0
argument|); 		AHC_OUTB(ahc, SCB_CONTROL,
literal|0
argument|);  		ahc->scb_data->maxhscbs = i; 	}  	if ((ahc->scb_data->maxhscbs< AHC_SCB_MAX)&& (ahc->flags& AHC_PAGESCBS)) { 		ahc->scb_data->maxscbs = AHC_SCB_MAX; 		printf(
literal|"%d/%d SCBs\n"
argument|, ahc->scb_data->maxhscbs, 			ahc->scb_data->maxscbs); 	} else { 		ahc->scb_data->maxscbs = ahc->scb_data->maxhscbs; 		ahc->flags&= ~AHC_PAGESCBS; 		printf(
literal|"%d SCBs\n"
argument|, ahc->scb_data->maxhscbs); 	}
ifdef|#
directive|ifdef
name|AHC_DEBUG
argument|if (ahc_debug& AHC_SHOWMISC) { 		printf(
literal|"%s: hardware scb %d bytes; kernel scb %d bytes; "
literal|"ahc_dma %d bytes\n"
argument|, 			ahc_name(ahc), 		        sizeof(struct hardware_scb), 			sizeof(struct scb), 			sizeof(struct ahc_dma_seg)); 	}
endif|#
directive|endif
comment|/* AHC_DEBUG */
comment|/* Set the SCSI Id, SXFRCTL0, SXFRCTL1, and SIMODE1, for both channels*/
argument|if (ahc->type& AHC_TWIN) {
comment|/* 		 * The device is gated to channel B after a chip reset, 		 * so set those values first 		 */
argument|AHC_OUTB(ahc, SCSIID, ahc->our_id_b); 		scsi_conf = AHC_INB(ahc, SCSICONF +
literal|1
argument|); 		AHC_OUTB(ahc, SXFRCTL1, (scsi_conf& (ENSPCHK|STIMESEL)) 					| ENSTIMER|ACTNEGEN|STPWEN); 		AHC_OUTB(ahc, SIMODE1, ENSELTIMO|ENSCSIRST|ENSCSIPERR); 		if (ahc->type& AHC_ULTRA) 			AHC_OUTB(ahc, SXFRCTL0, DFON|SPIOEN|ULTRAEN); 		else 			AHC_OUTB(ahc, SXFRCTL0, DFON|SPIOEN);  		if (scsi_conf& RESET_SCSI) {
comment|/* Reset the bus */
argument|if (bootverbose) 				printf(
literal|"%s: Reseting Channel B\n"
argument|, 				       ahc_name(ahc)); 			AHC_OUTB(ahc, SCSISEQ, SCSIRSTO); 			DELAY(
literal|1000
argument|); 			AHC_OUTB(ahc, SCSISEQ,
literal|0
argument|);
comment|/* Ensure we don't get a RSTI interrupt from this */
argument|AHC_OUTB(ahc, CLRSINT1, CLRSCSIRSTI); 			AHC_OUTB(ahc, CLRINT, CLRSCSIINT); 		}
comment|/* Select Channel A */
argument|AHC_OUTB(ahc, SBLKCTL,
literal|0
argument|); 	} 	AHC_OUTB(ahc, SCSIID, ahc->our_id); 	scsi_conf = AHC_INB(ahc, SCSICONF); 	AHC_OUTB(ahc, SXFRCTL1, (scsi_conf& (ENSPCHK|STIMESEL)) 				| ENSTIMER|ACTNEGEN|STPWEN); 	AHC_OUTB(ahc, SIMODE1, ENSELTIMO|ENSCSIRST|ENSCSIPERR); 	if (ahc->type& AHC_ULTRA) 		AHC_OUTB(ahc, SXFRCTL0, DFON|SPIOEN|ULTRAEN); 	else 		AHC_OUTB(ahc, SXFRCTL0, DFON|SPIOEN);  	if (scsi_conf& RESET_SCSI) {
comment|/* Reset the bus */
argument|if (bootverbose) 			printf(
literal|"%s: Reseting Channel A\n"
argument|, ahc_name(ahc));  		AHC_OUTB(ahc, SCSISEQ, SCSIRSTO); 		DELAY(
literal|1000
argument|); 		AHC_OUTB(ahc, SCSISEQ,
literal|0
argument|);
comment|/* Ensure we don't get a RSTI interrupt from this */
argument|AHC_OUTB(ahc, CLRSINT1, CLRSCSIRSTI); 		AHC_OUTB(ahc, CLRINT, CLRSCSIINT); 	}
comment|/* 	 * Look at the information that board initialization or 	 * the board bios has left us.  In the lower four bits of each 	 * target's scratch space any value other than 0 indicates 	 * that we should initiate syncronous transfers.  If it's zero, 	 * the user or the BIOS has decided to disable syncronous 	 * negotiation to that target so we don't activate the needsdtr 	 * flag. 	 */
argument|ahc->needsdtr_orig =
literal|0
argument|; 	ahc->needwdtr_orig =
literal|0
argument|;
comment|/* Grab the disconnection disable table and invert it for our needs */
argument|if (ahc->flags& AHC_USEDEFAULTS) { 		printf(
literal|"%s: Host Adapter Bios disabled.  Using default SCSI "
literal|"device parameters\n"
argument|, ahc_name(ahc)); 		ahc->discenable =
literal|0xff
argument|; 	} else 		ahc->discenable = ~((AHC_INB(ahc, DISC_DSB +
literal|1
argument|)<<
literal|8
argument|) 				   | AHC_INB(ahc, DISC_DSB));  	if (!(ahc->type& (AHC_WIDE|AHC_TWIN))) 		max_targ =
literal|7
argument|;  	for (i =
literal|0
argument|; i<= max_targ; i++) { 		u_int8_t target_settings; 		if (ahc->flags& AHC_USEDEFAULTS) { 			target_settings =
literal|0
argument|;
comment|/* 10MHz */
argument|ahc->needsdtr_orig |= (
literal|0x01
argument|<< i); 			ahc->needwdtr_orig |= (
literal|0x01
argument|<< i); 		} else {
comment|/* Take the settings leftover in scratch RAM. */
argument|target_settings = AHC_INB(ahc, TARG_SCRATCH + i);  			if (target_settings&
literal|0x0f
argument|) { 				ahc->needsdtr_orig |= (
literal|0x01
argument|<< i);
comment|/*Default to a asyncronous transfers(0 offset)*/
argument|target_settings&=
literal|0xf0
argument|; 			} 			if (target_settings&
literal|0x80
argument|) { 				ahc->needwdtr_orig |= (
literal|0x01
argument|<< i);
comment|/* 				 * We'll set the Wide flag when we 				 * are successful with Wide negotiation. 				 * Turn it off for now so we aren't 				 * confused. 				 */
argument|target_settings&=
literal|0x7f
argument|; 			} 			if (ahc->type& AHC_ULTRA) {
comment|/* 				 * Enable Ultra for any target that 				 * has a valid ultra syncrate setting. 				 */
argument|u_int8_t rate = target_settings&
literal|0x70
argument|; 				if (rate ==
literal|0x00
argument||| rate ==
literal|0x10
argument||| 				    rate ==
literal|0x20
argument||| rate ==
literal|0x40
argument|) { 					if (rate ==
literal|0x40
argument|) {
comment|/* Treat 10MHz specially */
argument|target_settings&= ~
literal|0x70
argument|; 					} else 						ultraenable |= (
literal|0x01
argument|<< i); 				} 			} 		} 		AHC_OUTB(ahc, TARG_SCRATCH+i,target_settings); 	}
comment|/* 	 * If we are not a WIDE device, forget WDTR.  This 	 * makes the driver work on some cards that don't 	 * leave these fields cleared when the BIOS is not 	 * installed. 	 */
argument|if ((ahc->type& AHC_WIDE) ==
literal|0
argument|) 		ahc->needwdtr_orig =
literal|0
argument|; 	ahc->needsdtr = ahc->needsdtr_orig; 	ahc->needwdtr = ahc->needwdtr_orig; 	ahc->sdtrpending =
literal|0
argument|; 	ahc->wdtrpending =
literal|0
argument|; 	ahc->tagenable =
literal|0
argument|; 	ahc->orderedtag =
literal|0
argument|;  	AHC_OUTB(ahc, ULTRA_ENB, ultraenable&
literal|0xff
argument|); 	AHC_OUTB(ahc, ULTRA_ENB +
literal|1
argument|, (ultraenable>>
literal|8
argument|)&
literal|0xff
argument|);
ifdef|#
directive|ifdef
name|AHC_DEBUG
comment|/* How did we do? */
argument|if (ahc_debug& AHC_SHOWMISC) 		printf(
literal|"NEEDSDTR == 0x%x\nNEEDWDTR == 0x%x\n"
literal|"DISCENABLE == 0x%x\n"
argument|, ahc->needsdtr,  			ahc->needwdtr, ahc->discenable);
endif|#
directive|endif
comment|/* 	 * Set the number of availible hardware SCBs 	 */
argument|AHC_OUTB(ahc, SCBCOUNT, ahc->scb_data->maxhscbs);
comment|/* 	 * 2's compliment of maximum tag value 	 */
argument|i = ahc->scb_data->maxscbs; 	AHC_OUTB(ahc, COMP_SCBCOUNT, -i&
literal|0xff
argument|);
comment|/* 	 * Allocate enough "hardware scbs" to handle 	 * the maximum number of concurrent transactions 	 * we can have active.  We have to use contigmalloc 	 * if this array crosses a page boundary since the 	 * sequencer depends on this array being physically 	 * contiguous. 	 */
argument|if (ahc->scb_data->hscbs == NULL) { 		size_t array_size; 		u_int32_t hscb_physaddr;  		array_size = ahc->scb_data->maxscbs*sizeof(struct hardware_scb); 		if (array_size> PAGE_SIZE) { 			ahc->scb_data->hscbs = (struct hardware_scb *) 				     contigmalloc(array_size, M_DEVBUF, 				     M_NOWAIT,
literal|0ul
argument|,
literal|0xffffffff
argument|, PAGE_SIZE,
literal|0x10000
argument|); 		} else { 			ahc->scb_data->hscbs = (struct hardware_scb *) 				     malloc(array_size, M_DEVBUF, M_NOWAIT); 		} 	 		if (ahc->scb_data->hscbs == NULL) { 			printf(
literal|"%s: unable to allocate hardware SCB array.  "
literal|"Failing attach\n"
argument|); 			return (-
literal|1
argument|); 		}
comment|/* Tell the sequencer where it can find the hscb array. */
argument|hscb_physaddr = vtophys(ahc->scb_data->hscbs); 		AHC_OUTB(ahc, HSCB_ADDR0, hscb_physaddr&
literal|0xFF
argument|); 		AHC_OUTB(ahc, HSCB_ADDR1, (hscb_physaddr>>
literal|8
argument|)&
literal|0xFF
argument|); 		AHC_OUTB(ahc, HSCB_ADDR2, (hscb_physaddr>>
literal|16
argument|)&
literal|0xFF
argument|); 		AHC_OUTB(ahc, HSCB_ADDR3, (hscb_physaddr>>
literal|24
argument|)&
literal|0xFF
argument|); 	}
comment|/* 	 * Q-Full-Count.  Some cards have more Q space 	 * then SCBs. 	 */
argument|if (ahc->type& AHC_AIC7770) { 		ahc->qfullcount =
literal|4
argument|; 		ahc->qcntmask =
literal|0x07
argument|; 	} else if (ahc->type& AHC_AIC7850) { 		ahc->qfullcount =
literal|8
argument|; 		ahc->qcntmask =
literal|0x0f
argument|; 	} else if (ahc->scb_data->maxhscbs ==
literal|255
argument|) {
comment|/* 7870/7880 with external SRAM */
argument|ahc->qfullcount =
literal|255
argument|; 		ahc->qcntmask =
literal|0xff
argument|; 	} else {
comment|/* 7870/7880 */
argument|ahc->qfullcount =
literal|16
argument|; 		ahc->qcntmask =
literal|0x1f
argument|; 	}
comment|/* 	 * QCount mask to deal with broken aic7850s that 	 * sporatically get garbage in the upper bits of 	 * their QCount registers. 	 * 	 * QFullCount to guard against overflowing the 	 * QINFIFO or QOUTFIFO when we are paging SCBs. 	 */
argument|AHC_OUTB(ahc, QCNTMASK, ahc->qcntmask);  	AHC_OUTB(ahc, QFULLCNT, ahc->qfullcount);
comment|/* We don't have any waiting selections */
argument|AHC_OUTB(ahc, WAITING_SCBH, SCB_LIST_NULL);
comment|/* Our disconnection list is empty too */
argument|AHC_OUTB(ahc, DISCONNECTED_SCBH, SCB_LIST_NULL);
comment|/* Message out buffer starts empty */
argument|AHC_OUTB(ahc, MSG_LEN,
literal|0x00
argument|);
comment|/* 	 * Load the Sequencer program and Enable the adapter 	 * in "fast" mode.          */
argument|if (bootverbose) 		printf(
literal|"%s: Downloading Sequencer Program..."
argument|, 		       ahc_name(ahc));  	ahc_loadseq(ahc);  	if (bootverbose) 		printf(
literal|"Done\n"
argument|);  	AHC_OUTB(ahc, SEQCTL, FASTMODE);  	unpause_sequencer(ahc,
comment|/*unpause_always*/
argument|TRUE);
comment|/* 	 * Note that we are going and return (to probe) 	 */
argument|ahc->flags |= AHC_INIT; 	return (
literal|0
argument|); }  static void ahcminphys(bp)         struct buf *bp; {
comment|/*  * Even though the card can transfer up to 16megs per command  * we are limited by the number of segments in the dma segment  * list that we can hold.  The worst case is that all pages are  * discontinuous physically, hense the "page per segment" limit  * enforced here.  */
argument|if (bp->b_bcount> ((AHC_NSEG -
literal|1
argument|) * PAGE_SIZE)) {                 bp->b_bcount = ((AHC_NSEG -
literal|1
argument|) * PAGE_SIZE);         }
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
argument|minphys(bp);
endif|#
directive|endif
argument|}
comment|/*  * start a scsi operation given the command and  * the data address, target, and lun all of which  * are stored in the scsi_xfer struct  */
argument|static int32_t ahc_scsi_cmd(xs)         struct scsi_xfer *xs; { 	struct	  scb *scb; 	struct	  hardware_scb *hscb; 	struct	  ahc_softc *ahc; 	u_int16_t mask; 	int	  flags; 	int	  s;  	ahc = (struct ahc_softc *)xs->sc_link->adapter_softc; 	mask = (
literal|0x01
argument|<< (xs->sc_link->target 		| (IS_SCSIBUS_B(ahc, xs->sc_link) ? SELBUSB :
literal|0
argument|))); 	SC_DEBUG(xs->sc_link, SDEV_DB2, (
literal|"ahc_scsi_cmd\n"
argument|)); 	flags = xs->flags;
comment|/* 	 * get an scb to use. If the transfer 	 * is from a buf (possibly from interrupt time) 	 * then we can't allow it to sleep 	 */
argument|if ((scb = ahc_get_scb(ahc, flags)) == NULL) { 		xs->error = XS_DRIVER_STUFFUP; 		return (TRY_AGAIN_LATER); 	} 	hscb = scb->hscb; 	SC_DEBUG(xs->sc_link, SDEV_DB3, (
literal|"start scb(%p)\n"
argument|, scb)); 	scb->xs = xs;
comment|/* 	 * Put all the arguments for the xfer in the scb 	 */
argument|if (ahc->discenable& mask) 		hscb->control |= DISCENB; 	 	if (flags& SCSI_RESET) { 		scb->flags |= SCB_DEVICE_RESET|SCB_IMMED; 		hscb->control |= MK_MESSAGE;		 	} else if ((ahc->needwdtr& mask)&& !(ahc->wdtrpending& mask)) { 		ahc->wdtrpending |= mask; 		hscb->control |= MK_MESSAGE; 		scb->flags |= SCB_MSGOUT_WDTR; 	} else if((ahc->needsdtr& mask)&& !(ahc->sdtrpending& mask)) { 		ahc->sdtrpending |= mask; 		hscb->control |= MK_MESSAGE;		 		scb->flags |= SCB_MSGOUT_SDTR; 	} else if (ahc->orderedtag& mask) {
comment|/* XXX this should be handled by the upper SCSI layer */
argument|printf(
literal|"Ordered Tag sent\n"
argument|); 		hscb->control |= MSG_ORDERED_Q_TAG; 		ahc->orderedtag&= ~mask; 	} else if (hscb->control& DISCENB) {                 if (ahc->tagenable& mask)                         hscb->control |= TAG_ENB; 	} 	hscb->tcl = ((xs->sc_link->target<<
literal|4
argument|)&
literal|0xF0
argument|) 		  | (IS_SCSIBUS_B(ahc,xs->sc_link)? SELBUSB :
literal|0
argument|) 		  | (xs->sc_link->lun&
literal|0x07
argument|); 	hscb->cmdlen = xs->cmdlen; 	hscb->cmdpointer = vtophys(xs->cmd); 	xs->resid =
literal|0
argument|; 	xs->status =
literal|0
argument|;
comment|/* Only use S/G if non-zero length */
argument|if (xs->datalen) { 		int		seg; 		u_int32_t	datalen; 		vm_offset_t	vaddr; 		u_int32_t	paddr; 		u_int32_t	nextpaddr; 		struct		ahc_dma_seg *sg; 	 		seg =
literal|0
argument|; 		datalen = xs->datalen; 		vaddr = (vm_offset_t)xs->data; 		paddr = vtophys(vaddr); 		sg = scb->ahc_dma; 		hscb->SG_list_pointer = vtophys(sg);  		while ((datalen>
literal|0
argument|)&& (seg< AHC_NSEG)) {
comment|/* put in the base address and length */
argument|sg->addr = paddr; 			sg->len =
literal|0
argument|;
comment|/* do it at least once */
argument|nextpaddr = paddr;  			while ((datalen>
literal|0
argument|)&& (paddr == nextpaddr)) { 				u_int32_t	size;
comment|/* 				 * This page is contiguous (physically) 				 * with the the last, just extend the 				 * length 				 */
comment|/* how far to the end of the page */
argument|nextpaddr = (paddr& (~PAGE_MASK)) + PAGE_SIZE;
comment|/* 				 * Compute the maximum size 				 */
argument|size = nextpaddr - paddr; 				if (size> datalen) 				        size = datalen;  				sg->len += size; 				vaddr   += size; 				datalen -= size; 				if (datalen>
literal|0
argument|) 					paddr = vtophys(vaddr); 			}
comment|/* 			 * next page isn't contiguous, finish the seg 			 */
argument|seg++; 			sg++; 		} 		hscb->SG_segment_count = seg;
comment|/* Copy the first SG into the data pointer area */
argument|hscb->data = scb->ahc_dma->addr; 		hscb->datalen = scb->ahc_dma->len | (SCB_LIST_NULL<<
literal|24
argument|); 		if (datalen) {
comment|/* there's still data, must have run out of segs! */
argument|printf(
literal|"%s: ahc_scsi_cmd: more than %d DMA segs\n"
argument|, 				ahc_name(ahc), AHC_NSEG); 			xs->error = XS_DRIVER_STUFFUP; 			ahc_free_scb(ahc, scb); 			return (COMPLETE); 		}
ifdef|#
directive|ifdef
name|AHC_BROKEN_CACHE
argument|if (ahc_broken_cache) 			INVALIDATE_CACHE();
endif|#
directive|endif
argument|} else {
comment|/* 		 * No data xfer, use non S/G values 	 	 */
argument|hscb->SG_segment_count =
literal|0
argument|; 		hscb->SG_list_pointer =
literal|0
argument|; 		hscb->data =
literal|0
argument|; 		hscb->datalen = (SCB_LIST_NULL<<
literal|24
argument|); 	}
ifdef|#
directive|ifdef
name|AHC_DEBUG
argument|if((ahc_debug& AHC_SHOWSCBS)&& (xs->sc_link->target == DEBUGTARGET)) 		ahc_print_scb(scb);
endif|#
directive|endif
argument|s = splbio();  	STAILQ_INSERT_TAIL(&ahc->waiting_scbs, scb, links);  	scb->flags |= SCB_ACTIVE;  	ahc_run_waiting_queue(ahc);  	if ((flags& SCSI_NOMASK) ==
literal|0
argument|) { 		timeout(ahc_timeout, (caddr_t)scb, (xs->timeout * hz) /
literal|1000
argument|); 		splx(s); 		return (SUCCESSFULLY_QUEUED); 	}
comment|/* 	 * If we can't use interrupts, poll for completion 	 */
argument|SC_DEBUG(xs->sc_link, SDEV_DB3, (
literal|"cmd_poll\n"
argument|)); 	do { 		if (ahc_poll(ahc, xs->timeout)) { 			if (!(xs->flags& SCSI_SILENT)) 				printf(
literal|"cmd fail\n"
argument|); 			ahc_timeout(scb); 			break; 		} 	} while ((xs->flags& ITSDONE) ==
literal|0
argument|);
comment|/* a non command complete intr */
argument|splx(s);  	return (COMPLETE); }
comment|/*  * Look for space in the QINFIFO and queue as many SCBs in the waiting  * queue as possible.  Assumes that it is called at splbio().  */
argument|static void ahc_run_waiting_queue(ahc) 	struct	ahc_softc *ahc; { 	struct scb *scb;
comment|/* 	 * On aic78X0 chips, we rely on Auto Access Pause (AAP) 	 * instead of doing an explicit pause/unpause. 	 */
argument|if ((ahc->type& AHC_AIC78X0) ==
literal|0
argument|) 		pause_sequencer(ahc);  	while ((scb = ahc->waiting_scbs.stqh_first) != NULL) {  		if (ahc->curqincnt>= ahc->qfullcount) { 			ahc->curqincnt = AHC_INB(ahc, QINCNT)& ahc->qcntmask; 			if (ahc->curqincnt>= ahc->qfullcount)
comment|/* Still no space */
argument|break; 		} 		STAILQ_REMOVE_HEAD(&ahc->waiting_scbs, links); 		AHC_OUTB(ahc, QINFIFO, scb->hscb->tag);  		if ((ahc->flags& AHC_PAGESCBS) !=
literal|0
argument|)
comment|/* 			 * We only care about this statistic when paging 			 * since it is impossible to overflow the qinfifo 			 * in the non-paging case. 			 */
argument|ahc->curqincnt++; 	} 	if ((ahc->type& AHC_AIC78X0) ==
literal|0
argument|) 		unpause_sequencer(ahc,
comment|/*Unpause always*/
argument|FALSE); }
comment|/*  * A scb (and hence an scb entry on the board is put onto the  * free list.  */
argument|static void ahc_free_scb(ahc, scb) 	struct	ahc_softc *ahc; 	struct	scb *scb; {        	struct hardware_scb *hscb; 	int opri;  	hscb = scb->hscb;  	opri = splbio();
comment|/* Clean up for the next user */
argument|scb->flags = SCB_FREE; 	hscb->control =
literal|0
argument|; 	hscb->status =
literal|0
argument|;  	STAILQ_INSERT_HEAD(&ahc->scb_data->free_scbs, scb, links); 	if (scb->links.stqe_next == NULL) {
comment|/* 		 * If there were no SCBs availible, wake anybody waiting 		 * for one to come free. 		 */
argument|wakeup((caddr_t)&ahc->scb_data->free_scbs); 	}
ifdef|#
directive|ifdef
name|AHC_DEBUG
argument|ahc->activescbs--;
endif|#
directive|endif
argument|splx(opri); }
comment|/*  * Get a free scb, either one already assigned to a hardware slot  * on the adapter or one that will require an SCB to be paged out before  * use. If there are none, see if we can allocate a new SCB.  Otherwise  * either return an error or sleep.  */
argument|static struct scb * ahc_get_scb(ahc, flags) 	struct  ahc_softc *ahc; 	u_int32_t flags; { 	struct scb *scbp; 	int opri;  	opri = splbio();
comment|/* 	 * If we can and have to, sleep waiting for one to come free 	 * but only if we can't allocate a new one. 	 */
argument|while (
literal|1
argument|) { 		if ((scbp = ahc->scb_data->free_scbs.stqh_first)) { 			STAILQ_REMOVE_HEAD(&ahc->scb_data->free_scbs, links); 		} else if(ahc->scb_data->numscbs< ahc->scb_data->maxscbs) { 			scbp = ahc_alloc_scb(ahc); 			if (scbp == NULL) 				printf(
literal|"%s: Can't malloc SCB\n"
argument|, ahc_name(ahc)); 		} else if ((flags& SCSI_NOSLEEP) ==
literal|0
argument|) { 			tsleep((caddr_t)&ahc->scb_data->free_scbs, PRIBIO,
literal|"ahcscb"
argument|,
literal|0
argument|); 			continue; 		} 		break; 	}
ifdef|#
directive|ifdef
name|AHC_DEBUG
argument|if (scbp) { 		ahc->activescbs++; 		if((ahc_debug& AHC_SHOWSCBCNT)&& (ahc->activescbs == ahc->scb_data->maxhscbs)) 			printf(
literal|"%s: Max SCBs active\n"
argument|, ahc_name(ahc)); 	}
endif|#
directive|endif
argument|splx(opri);  	return (scbp); }   static struct scb * ahc_alloc_scb(ahc) 	struct	ahc_softc *ahc; { 	static	struct ahc_dma_seg *next_sg_array = NULL; 	static	int sg_arrays_free =
literal|0
argument|; 	struct	scb *newscb;  	newscb = (struct scb *) malloc(sizeof(struct scb), M_DEVBUF, M_NOWAIT); 	if (newscb != NULL) { 		bzero(newscb, sizeof(struct scb)); 		if (next_sg_array == NULL) { 			size_t	alloc_size = sizeof(struct ahc_dma_seg) 					     * AHC_NSEG;  			sg_arrays_free = PAGE_SIZE / alloc_size; 			alloc_size *= sg_arrays_free; 			if (alloc_size ==
literal|0
argument|) 				panic(
literal|"%s: SG list doesn't fit in a page"
argument|, 				      ahc_name(ahc)); 			next_sg_array = (struct ahc_dma_seg *) 					malloc(alloc_size, M_DEVBUF, M_NOWAIT); 		} 		if (next_sg_array != NULL) { 			struct hardware_scb *hscb;  			newscb->ahc_dma = next_sg_array; 			sg_arrays_free--; 			if (sg_arrays_free ==
literal|0
argument|) 				next_sg_array = NULL; 			else 				next_sg_array =&next_sg_array[AHC_NSEG]; 			hscb =&ahc->scb_data->hscbs[ahc->scb_data->numscbs]; 			newscb->hscb = hscb; 			hscb->control =
literal|0
argument|; 			hscb->status =
literal|0
argument|; 			hscb->tag = ahc->scb_data->numscbs; 			hscb->residual_data_count[
literal|2
argument|] =
literal|0
argument|; 			hscb->residual_data_count[
literal|1
argument|] =
literal|0
argument|; 			hscb->residual_data_count[
literal|0
argument|] =
literal|0
argument|; 			hscb->residual_SG_segment_count =
literal|0
argument|; 			ahc->scb_data->numscbs++;
comment|/* 			 * Place in the scbarray 			 * Never is removed. 			 */
argument|ahc->scb_data->scbarray[hscb->tag] = newscb; 		} else { 			free(newscb, M_DEVBUF); 			newscb = NULL; 		} 	} 	return newscb; }  static void ahc_loadseq(ahc) 	struct ahc_softc *ahc; {         static u_char seqprog[] = {
include|#
directive|include
file|"aic7xxx_seq.h"
argument|};  	AHC_OUTB(ahc, SEQCTL, PERRORDIS|SEQRESET|LOADRAM);  	AHC_OUTSB(ahc, SEQRAM, seqprog, sizeof(seqprog));  	do { 		AHC_OUTB(ahc, SEQCTL, SEQRESET|FASTMODE); 	} while ((AHC_INB(ahc, SEQADDR0) !=
literal|0
argument|) 	      || (AHC_INB(ahc, SEQADDR1) !=
literal|0
argument|)); }
comment|/*  * Function to poll for command completion when  * interrupts are disabled (crash dumps)  */
argument|static int ahc_poll(ahc, wait) 	struct	ahc_softc *ahc; 	int	wait;
comment|/* in msec */
argument|{ 	while (--wait) { 		DELAY(
literal|1000
argument|); 		if (AHC_INB(ahc, INTSTAT)& INT_PEND) 			break; 	} if (wait ==
literal|0
argument|) { 		printf(
literal|"%s: board is not responding\n"
argument|, ahc_name(ahc)); 		return (EIO); 	} 	ahc_intr((void *)ahc); 	return (
literal|0
argument|); }  static void ahc_timeout(arg) 	void	*arg; { 	struct	scb *scb = (struct scb *)arg; 	struct	ahc_softc *ahc; 	int	s
argument_list|,
argument|found; 	u_char	bus_state;  	s = splbio();  	if (!(scb->flags& SCB_ACTIVE)) {
comment|/* Previous timeout took care of me already */
argument|splx(s); 		return; 	}  	ahc = (struct ahc_softc *)scb->xs->sc_link->adapter_softc;  	if (ahc->in_timeout) {
comment|/* 		 * Some other SCB has started a recovery operation 		 * and is still working on cleaning things up. 		 */
argument|if (scb->flags& SCB_TIMEDOUT) {
comment|/* 			 * This SCB has been here before and is not the 			 * recovery SCB. Cut our losses and panic.  Its 			 * better to do this than trash a filesystem. 			 */
argument|panic(
literal|"%s: Timed-out command times out "
literal|"again\n"
argument|, ahc_name(ahc)); 		} else if ((scb->flags& (SCB_ABORTED | SCB_DEVICE_RESET 					  | SCB_SENTORDEREDTAG)) ==
literal|0
argument|) {
comment|/* 			 * This is not the SCB that started this timeout 			 * processing.  Give this scb another lifetime so 			 * that it can continue once we deal with the 			 * timeout. 			 */
argument|scb->flags |= SCB_TIMEDOUT; 			timeout(ahc_timeout, (caddr_t)scb,  				(scb->xs->timeout * hz) /
literal|1000
argument|); 			splx(s); 			return; 		} 	} 	ahc->in_timeout = TRUE;
comment|/*       	 * Ensure that the card doesn't do anything 	 * behind our back. 	 */
argument|pause_sequencer(ahc);  	sc_print_addr(scb->xs->sc_link); 	printf(
literal|"timed out "
argument|);
comment|/* 	 * Take a snapshot of the bus state and print out 	 * some information so we can track down driver bugs. 	 */
argument|bus_state = AHC_INB(ahc, LASTPHASE);  	switch(bus_state& PHASE_MASK) 	{ 	case P_DATAOUT: 		printf(
literal|"in dataout phase"
argument|); 		break; 	case P_DATAIN: 		printf(
literal|"in datain phase"
argument|); 		break; 	case P_COMMAND: 		printf(
literal|"in command phase"
argument|); 		break; 	case P_MESGOUT: 		printf(
literal|"in message out phase"
argument|); 		break; 	case P_STATUS: 		printf(
literal|"in status phase"
argument|); 		break; 	case P_MESGIN: 		printf(
literal|"in message in phase"
argument|); 		break; 	default: 		printf(
literal|"while idle, LASTPHASE == 0x%x"
argument|, 			bus_state);
comment|/*  		 * We aren't in a valid phase, so assume we're 		 * idle. 		 */
argument|bus_state =
literal|0
argument|; 		break; 	}  	printf(
literal|", SCSISIGI == 0x%x\n"
argument|, AHC_INB(ahc, SCSISIGI));
comment|/* Decide our course of action */
argument|if (scb->flags& SCB_ABORTED) {
comment|/* 		 * Been down this road before. 		 * Do a full bus reset. 		 */
argument|char channel = (scb->hscb->tcl& SELBUSB) 			   ?
literal|'B'
argument|:
literal|'A'
argument|;	 		found = ahc_reset_channel(ahc, channel, scb, 					  XS_TIMEOUT,
comment|/*Initiate Reset*/
argument|TRUE); 		printf(
literal|"%s: Issued Channel %c Bus Reset. "
literal|"%d SCBs aborted\n"
argument|, ahc_name(ahc), channel, found); 		ahc->in_timeout = FALSE; 	} else if ((scb->hscb->control& TAG_ENB) !=
literal|0
argument|&& (scb->flags& SCB_SENTORDEREDTAG) ==
literal|0
argument|) {
comment|/* 		 * We could be starving this command 		 * try sending an ordered tag command 		 * to the target we come from. 		 */
argument|scb->flags |= SCB_SENTORDEREDTAG; 		ahc->orderedtag |=
literal|0xFF
argument|; 		timeout(ahc_timeout, (caddr_t)scb, (
literal|5
argument|* hz)); 		unpause_sequencer(ahc,
comment|/*unpause_always*/
argument|FALSE); 		printf(
literal|"Ordered Tag queued\n"
argument|); 	} else {
comment|/* 		 * Send an Abort Message: 		 * The target that is holding up the bus may not 		 * be the same as the one that triggered this timeout 		 * (different commands have different timeout lengths). 		 * Our strategy here is to queue an abort message 		 * to the timed out target if it is disconnected. 		 * Otherwise, if we have an active target we stuff the 		 * message buffer with an abort message and assert ATN 		 * in the hopes that the target will let go of the bus 		 * and go to the mesgout phase.  If this fails, we'll 		 * get another timeout 2 seconds later which will attempt 		 * a bus reset. 		 */
argument|u_int8_t saved_scbptr; 		u_int8_t active_scb_index; 		struct scb *active_scb;  		saved_scbptr = AHC_INB(ahc, SCBPTR); 		active_scb_index = AHC_INB(ahc, SCB_TAG); 		active_scb = ahc->scb_data->scbarray[active_scb_index];  		if (bus_state !=
literal|0
argument|) {
comment|/* Send the abort to the active SCB */
argument|AHC_OUTB(ahc, MSG_LEN,
literal|1
argument|); 			AHC_OUTB(ahc, MSG0, 				 (active_scb->hscb->control& TAG_ENB) ==
literal|0
argument|? 				 MSG_ABORT : MSG_ABORT_TAG); 			AHC_OUTB(ahc, SCSISIGO, bus_state|ATNO); 			sc_print_addr(active_scb->xs->sc_link); 			printf(
literal|"abort message in message buffer\n"
argument|); 			active_scb->flags |= SCB_ABORTED; 			if (active_scb != scb) { 				untimeout(ahc_timeout,  					  (caddr_t)active_scb);
comment|/* Give scb a new lease on life */
argument|timeout(ahc_timeout, (caddr_t)scb,  					(scb->xs->timeout * hz) /
literal|1000
argument|); 			} 			timeout(ahc_timeout, (caddr_t)active_scb, (
literal|2
argument|* hz)); 			unpause_sequencer(ahc,
comment|/*unpause_always*/
argument|FALSE); 		} else { 			u_int8_t hscb_index; 			int	 disconnected;  			disconnected = FALSE; 			hscb_index = find_scb(ahc, scb); 			if (hscb_index == SCB_LIST_NULL) 				disconnected = TRUE; 			else { 				AHC_OUTB(ahc, SCBPTR, hscb_index); 				if (AHC_INB(ahc, SCB_CONTROL)& DISCONNECTED) 					disconnected = TRUE; 			}  			scb->flags |= SCB_ABORTED; 			if (disconnected) {
comment|/* Simply set the ABORT_SCB control bit */
argument|scb->hscb->control |= ABORT_SCB; 				if (hscb_index != SCB_LIST_NULL) 					AHC_OUTB(ahc, SCB_CONTROL, ABORT_SCB); 				timeout(ahc_timeout, (caddr_t)scb, (
literal|2
argument|* hz)); 			} 			AHC_OUTB(ahc, SCBPTR, saved_scbptr); 			unpause_sequencer(ahc,
comment|/*unpause_always*/
argument|FALSE); 			if (!disconnected)
comment|/* Go "immediatly" to the bus reset */
argument|timeout(ahc_timeout, (caddr_t)scb, hz /
literal|2
argument|);	 		} 	} 	splx(s); }
comment|/*  * Look through the SCB array of the card and attempt to find the  * hardware SCB that corresponds to the passed in SCB.  Return  * SCB_LIST_NULL if unsuccessful.  This routine assumes that the  * card is already paused.  */
argument|static u_int8_t find_scb(ahc, scb) 	struct ahc_softc *ahc; 	struct scb *scb; { 	u_int8_t saved_scbptr; 	u_int8_t curindex;  	saved_scbptr = AHC_INB(ahc, SCBPTR); 	curindex =
literal|0
argument|; 	for (curindex =
literal|0
argument|; curindex< ahc->scb_data->maxhscbs; curindex++) { 		AHC_OUTB(ahc, SCBPTR, curindex); 		if (AHC_INB(ahc, SCB_TAG) == scb->hscb->tag) 			break; 	} 	AHC_OUTB(ahc, SCBPTR, saved_scbptr); 	if (curindex> ahc->scb_data->maxhscbs) 		curindex = SCB_LIST_NULL;  	return curindex; }
comment|/*  * The device at the given target/channel has been reset.  Abort   * all active and queued scbs for that target/channel.   */
argument|static int ahc_reset_device(ahc, target, channel, timedout_scb, xs_error) 	struct ahc_softc *ahc; 	int target; 	char channel; 	struct scb *timedout_scb; 	u_int32_t xs_error; {         struct scb *scbp; 	u_char active_scb; 	int i =
literal|0
argument|; 	int found =
literal|0
argument|;
comment|/* restore this when we're done */
argument|active_scb = AHC_INB(ahc, SCBPTR);
comment|/* 	 * Search the QINFIFO. 	 */
argument|{ 		u_int8_t saved_queue[AHC_SCB_MAX]; 		u_int8_t queued = AHC_INB(ahc, QINCNT)& ahc->qcntmask;  		for (i =
literal|0
argument|; i< (queued - found); i++) { 			saved_queue[i] = AHC_INB(ahc, QINFIFO); 			scbp = ahc->scb_data->scbarray[saved_queue[i]]; 			if (ahc_match_scb (scbp, target, channel)) {
comment|/* 				 * We found an scb that needs to be aborted. 				 */
argument|scbp->flags = SCB_ABORTED|SCB_QUEUED_FOR_DONE; 				scbp->xs->error |= xs_error; 				if(scbp != timedout_scb) 					untimeout(ahc_timeout, (caddr_t)scbp); 				i--; 				found++; 			} 		}
comment|/* Now put the saved scbs back. */
argument|for (queued =
literal|0
argument|; queued< i; queued++) { 			AHC_OUTB(ahc, QINFIFO, saved_queue[queued]); 		} 	}
comment|/* 	 * Search waiting for selection list. 	 */
argument|{ 		u_int8_t next
argument_list|,
argument|prev;  		next = AHC_INB(ahc, WAITING_SCBH);
comment|/* Start at head of list. */
argument|prev = SCB_LIST_NULL;  		while (next != SCB_LIST_NULL) { 			AHC_OUTB(ahc, SCBPTR, next); 			scbp = ahc->scb_data->scbarray[AHC_INB(ahc, SCB_TAG)]; 			if (ahc_match_scb(scbp, target, channel)) { 				next = ahc_abort_wscb(ahc, scbp, next, prev, 						      timedout_scb, xs_error); 				found++; 			} else { 				prev = next; 				next = AHC_INB(ahc, SCB_NEXT); 			} 		} 	}
comment|/* 	 * Go through the entire SCB array now and look for  	 * commands for this target that are active.  These 	 * are other (most likely tagged) commands that  	 * were disconnected when the reset occured. 	 */
argument|for (i =
literal|0
argument|; i< ahc->scb_data->numscbs; i++) { 		scbp = ahc->scb_data->scbarray[i]; 		if ((scbp->flags& SCB_ACTIVE)&& ahc_match_scb(scbp, target, channel)) {
comment|/* Ensure the target is "free" */
argument|ahc_unbusy_target(ahc, target, channel); 			scbp->flags = SCB_ABORTED|SCB_QUEUED_FOR_DONE; 			scbp->xs->error |= xs_error; 			if (scbp != timedout_scb) 				untimeout(ahc_timeout, (caddr_t)scbp); 			found++; 		} 	}			 	AHC_OUTB(ahc, SCBPTR, active_scb); 	return found; }
comment|/*  * Manipulate the waiting for selection list and return the  * scb that follows the one that we remove.  */
argument|static u_char ahc_abort_wscb (ahc, scbp, scbpos, prev, timedout_scb, xs_error) 	struct	  ahc_softc *ahc; 	struct	  scb *scbp; 	u_int8_t  scbpos; 	u_int8_t  prev; 	struct	  scb *timedout_scb; 	u_int32_t xs_error; {        	u_int8_t curscb
argument_list|,
argument|next; 	int target = ((scbp->hscb->tcl>>
literal|4
argument|)&
literal|0x0f
argument|); 	char channel = (scbp->hscb->tcl& SELBUSB) ?
literal|'B'
argument|:
literal|'A'
argument|;
comment|/* 	 * Select the SCB we want to abort and 	 * pull the next pointer out of it. 	 */
argument|curscb = AHC_INB(ahc, SCBPTR); 	AHC_OUTB(ahc, SCBPTR, scbpos); 	next = AHC_INB(ahc, SCB_NEXT);
comment|/* Clear the necessary fields */
argument|AHC_OUTB(ahc, SCB_CONTROL,
literal|0
argument|); 	AHC_OUTB(ahc, SCB_NEXT, SCB_LIST_NULL); 	ahc_unbusy_target(ahc, target, channel);
comment|/* update the waiting list */
argument|if (prev == SCB_LIST_NULL)
comment|/* First in the list */
argument|AHC_OUTB(ahc, WAITING_SCBH, next);  	else {
comment|/* 		 * Select the scb that pointed to us  		 * and update its next pointer. 		 */
argument|AHC_OUTB(ahc, SCBPTR, prev); 		AHC_OUTB(ahc, SCB_NEXT, next); 	}
comment|/* 	 * Point us back at the original scb position 	 * and inform the SCSI system that the command 	 * has been aborted. 	 */
argument|AHC_OUTB(ahc, SCBPTR, curscb); 	scbp->flags = SCB_ABORTED|SCB_QUEUED_FOR_DONE; 	scbp->xs->error |= xs_error; 	if (scbp != timedout_scb) 		untimeout(ahc_timeout, (caddr_t)scbp); 	return next; }  static u_int8_t ahc_unbusy_target(ahc, target, channel) 	struct	ahc_softc *ahc; 	int	target; 	char	channel; { 	u_int8_t  active_scb; 	u_int8_t  info_scb; 	u_int8_t  busy_scbid; 	u_int32_t scb_offset;  	info_scb = target /
literal|4
argument|; 	if (channel ==
literal|'B'
argument|) 		info_scb +=
literal|2
argument|; 	active_scb = AHC_INB(ahc, SCBPTR); 	AHC_OUTB(ahc, SCBPTR, info_scb); 	scb_offset = SCB_ACTIVE0 + (target&
literal|0x03
argument|); 	busy_scbid = AHC_INB(ahc, scb_offset); 	AHC_OUTB(ahc, scb_offset, SCB_LIST_NULL); 	AHC_OUTB(ahc, SCBPTR, active_scb); 	return busy_scbid; }  static void ahc_reset_current_bus(ahc) 	struct ahc_softc *ahc; { 	AHC_OUTB(ahc, SCSISEQ, SCSIRSTO); 	DELAY(
literal|1000
argument|); 	AHC_OUTB(ahc, SCSISEQ,
literal|0
argument|); }  static int ahc_reset_channel(ahc, channel, timedout_scb, xs_error, initiate_reset) 	struct	  ahc_softc *ahc; 	char	  channel; 	struct	  scb *timedout_scb; 	u_int32_t xs_error; 	int	  initiate_reset; { 	u_int8_t sblkctl; 	char cur_channel; 	u_int32_t offset
argument_list|,
argument|offset_max; 	int found; 	int target; 	int maxtarget;  	maxtarget =
literal|8
argument|;
comment|/* 	 * Clean up all the state information for the 	 * pending transactions on this bus. 	 */
argument|found = ahc_reset_device(ahc, ALL_TARGETS, channel,  				 timedout_scb, xs_error); 	if (channel ==
literal|'B'
argument|) { 		ahc->needsdtr |= (ahc->needsdtr_orig&
literal|0xff00
argument|); 		ahc->sdtrpending&=
literal|0x00ff
argument|; 		offset = TARG_SCRATCH +
literal|8
argument|; 		offset_max = TARG_SCRATCH +
literal|16
argument|; 	} else if (ahc->type& AHC_WIDE){ 		ahc->needsdtr = ahc->needsdtr_orig; 		ahc->needwdtr = ahc->needwdtr_orig; 		ahc->sdtrpending =
literal|0
argument|; 		ahc->wdtrpending =
literal|0
argument|; 		maxtarget =
literal|16
argument|; 		offset = TARG_SCRATCH; 		offset_max = TARG_SCRATCH +
literal|16
argument|; 	} else { 		ahc->needsdtr |= (ahc->needsdtr_orig&
literal|0x00ff
argument|); 		ahc->sdtrpending&=
literal|0xff00
argument|; 		offset = TARG_SCRATCH; 		offset_max = TARG_SCRATCH +
literal|8
argument|; 	}  	for (target =
literal|0
argument|; target< maxtarget; target++) 		ahc_unbusy_target(ahc, target, channel);  	for (; offset< offset_max; offset++) {
comment|/* 		 * Revert to async/narrow transfers 		 * until we renegotiate. 		 */
argument|u_int8_t targ_scratch;  		targ_scratch = AHC_INB(ahc, offset); 		targ_scratch&= SXFR; 		AHC_OUTB(ahc, offset, targ_scratch); 	}
comment|/* 	 * Reset the bus if we are initiating this reset and 	 * restart/unpause the sequencer 	 */
argument|sblkctl = AHC_INB(ahc, SBLKCTL); 	cur_channel = (sblkctl& SELBUSB) ?
literal|'B'
argument|:
literal|'A'
argument|; 	if (cur_channel != channel) {
comment|/* Case 1: Command for another bus is active 		 * Stealthily reset the other bus without 		 * upsetting the current bus. 		 */
argument|AHC_OUTB(ahc, SBLKCTL, sblkctl ^ SELBUSB); 		if (initiate_reset) 			ahc_reset_current_bus(ahc); 		AHC_OUTB(ahc, CLRSINT1, CLRSCSIRSTI|CLRSELTIMEO); 		AHC_OUTB(ahc, CLRINT, CLRSCSIINT); 		AHC_OUTB(ahc, SBLKCTL, sblkctl); 		unpause_sequencer(ahc,
comment|/*unpause_always*/
argument|TRUE); 	} else {
comment|/* Case 2: A command from this bus is active or we're idle */
argument|if (initiate_reset) 			ahc_reset_current_bus(ahc); 		AHC_OUTB(ahc, CLRSINT1, CLRSCSIRSTI|CLRSELTIMEO); 		AHC_OUTB(ahc, CLRINT, CLRSCSIINT); 		restart_sequencer(ahc); 	} 	ahc_run_done_queue(ahc); 	return found; }  void ahc_run_done_queue(ahc) 	struct ahc_softc *ahc; { 	int i; 	struct scb *scbp; 	 	for (i =
literal|0
argument|; i< ahc->scb_data->numscbs; i++) { 		scbp = ahc->scb_data->scbarray[i]; 		if (scbp->flags& SCB_QUEUED_FOR_DONE)  			ahc_done(ahc, scbp); 	} } 	 static int ahc_match_scb (scb, target, channel)         struct scb *scb;         int target; 	char channel; { 	int targ = (scb->hscb->tcl>>
literal|4
argument|)&
literal|0x0f
argument|; 	char chan = (scb->hscb->tcl& SELBUSB) ?
literal|'B'
argument|:
literal|'A'
argument|;  	if (target == ALL_TARGETS)  		return (chan == channel); 	else 		return ((chan == channel)&& (targ == target)); }  static void ahc_construct_sdtr(ahc, start_byte, period, offset) 	struct ahc_softc *ahc; 	int start_byte; 	u_int8_t period; 	u_int8_t offset; { 	AHC_OUTB(ahc, MSG0 + start_byte, MSG_EXTENDED); 	AHC_OUTB(ahc, MSG1 + start_byte, MSG_EXT_SDTR_LEN); 	AHC_OUTB(ahc, MSG2 + start_byte, MSG_EXT_SDTR); 	AHC_OUTB(ahc, MSG3 + start_byte, period); 	AHC_OUTB(ahc, MSG4 + start_byte, offset); 	AHC_OUTB(ahc, MSG_LEN, start_byte +
literal|5
argument|); }  static void ahc_construct_wdtr(ahc, start_byte, bus_width) 	struct ahc_softc *ahc; 	int start_byte; 	u_int8_t bus_width; { 	AHC_OUTB(ahc, MSG0 + start_byte, MSG_EXTENDED); 	AHC_OUTB(ahc, MSG1 + start_byte, MSG_EXT_WDTR_LEN); 	AHC_OUTB(ahc, MSG2 + start_byte, MSG_EXT_WDTR); 	AHC_OUTB(ahc, MSG3 + start_byte, bus_width); 	AHC_OUTB(ahc, MSG_LEN, start_byte +
literal|4
argument|); }  static void ahc_calc_residual(scb) 	struct scb *scb; { 	struct	scsi_xfer *xs; 	struct	hardware_scb *hscb; 	int	resid_sgs;  	xs = scb->xs; 	hscb = scb->hscb;  	if ((scb->flags& SCB_SENSE) ==
literal|0
argument|) {
comment|/* 		 * Remainder of the SG where the transfer 		 * stopped. 		 */
argument|xs->resid = (hscb->residual_data_count[
literal|2
argument|]<<
literal|16
argument|) | 			    (hscb->residual_data_count[
literal|1
argument|]<<
literal|8
argument|)  | 			    (hscb->residual_data_count[
literal|0
argument|]);
comment|/* 		 * Add up the contents of all residual 		 * SG segments that are after the SG where 		 * the transfer stopped. 		 */
argument|resid_sgs = hscb->residual_SG_segment_count -
literal|1
argument|; 		while (resid_sgs>
literal|0
argument|) { 			int sg;  			sg = hscb->SG_segment_count - resid_sgs; 			xs->resid += scb->ahc_dma[sg].len; 			resid_sgs--; 		}
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
argument|xs->flags |= SCSI_RESID_VALID;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
comment|/* XXX - Update to do this right */
endif|#
directive|endif
argument|}
comment|/* 	 * Clean out the residual information in this SCB for the 	 * next consumer of this SCB. 	 */
argument|hscb->residual_data_count[
literal|2
argument|] =
literal|0
argument|; 	hscb->residual_data_count[
literal|1
argument|] =
literal|0
argument|; 	hscb->residual_data_count[
literal|0
argument|] =
literal|0
argument|; 	hscb->residual_SG_segment_count =
literal|0
argument|;
ifdef|#
directive|ifdef
name|AHC_DEBUG
argument|if (ahc_debug& AHC_SHOWMISC) { 		sc_print_addr(xs->sc_link); 		printf(
literal|"Handled Residual of %ld bytes\n"
argument|,xs->resid); 	}
endif|#
directive|endif
argument|}
end_function

end_unit

