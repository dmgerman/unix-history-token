begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	pccard.c - Interface code for PC-CARD controllers.  *  *	June 1995, Andrew McRae (andrew@mega.com.au)  *-------------------------------------------------------------------------  *  * Copyright (c) 2001 M. Warner Losh.  All rights reserved.  * Copyright (c) 1995 Andrew McRae.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_pcic.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<pccard/cardinfo.h>
end_include

begin_include
include|#
directive|include
file|<pccard/driver.h>
end_include

begin_include
include|#
directive|include
file|<pccard/slot.h>
end_include

begin_include
include|#
directive|include
file|<pccard/pccard_nbk.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_define
define|#
directive|define
name|suser_td
parameter_list|(
name|a
parameter_list|)
value|suser(a)
end_define

begin_define
define|#
directive|define
name|thread
value|proc
end_define

begin_comment
comment|/* Compat with new thread stuff */
end_comment

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_machdep
argument_list|,
name|OID_AUTO
argument_list|,
name|pccard
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"pccard"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The following might now be obsolete */
end_comment

begin_decl_stmt
specifier|static
name|int
name|pcic_resume_reset
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_machdep_pccard
argument_list|,
name|OID_AUTO
argument_list|,
name|pcic_resume_reset
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|pcic_resume_reset
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<(b)?(a):(b))
end_define

begin_function_decl
specifier|static
name|int
name|allocate_driver
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|,
name|struct
name|dev_desc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|inserted
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|disable_slot
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|disable_slot_to
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|power_off_slot
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	The driver interface for read/write uses a block  *	of memory in the ISA I/O memory space allocated via  *	an ioctl setting.  *  *	Now that we have different bus attachments, we should really  *	use a better algorythm to allocate memory.  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|pccard_mem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Physical memory */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
modifier|*
name|pccard_kmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Kernel virtual address */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|resource
modifier|*
name|pccard_mem_res
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|pccard_mem_rid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_open_t
name|crdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_close_t
name|crdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_read_t
name|crdread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_write_t
name|crdwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|crdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_poll_t
name|crdpoll
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CDEV_MAJOR
value|50
end_define

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|crd_cdevsw
init|=
block|{
comment|/* open */
name|crdopen
block|,
comment|/* close */
name|crdclose
block|,
comment|/* read */
name|crdread
block|,
comment|/* write */
name|crdwrite
block|,
comment|/* ioctl */
name|crdioctl
block|,
comment|/* poll */
name|crdpoll
block|,
comment|/* mmap */
name|nommap
block|,
comment|/* strategy */
name|nostrategy
block|,
comment|/* name */
literal|"crd"
block|,
comment|/* maj */
name|CDEV_MAJOR
block|,
comment|/* dump */
name|nodump
block|,
comment|/* psize */
name|nopsize
block|,
comment|/* flags */
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Power off the slot.  *	(doing it immediately makes the removal of some cards unstable)  */
end_comment

begin_function
specifier|static
name|void
name|power_off_slot
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|slot
modifier|*
name|slt
init|=
operator|(
expr|struct
name|slot
operator|*
operator|)
name|arg
decl_stmt|;
name|int
name|s
decl_stmt|;
comment|/* 	 * The following will generate an interrupt.  So, to hold off 	 * the interrupt unitl after disable runs so that we can get rid 	 * rid of the interrupt before it becomes unsafe to touch the 	 * device. 	 * 	 * XXX In current, the spl stuff is a nop. 	 */
name|s
operator|=
name|splhigh
argument_list|()
expr_stmt|;
comment|/* Power off the slot. */
name|slt
operator|->
name|pwr_off_pending
operator|=
literal|0
expr_stmt|;
name|slt
operator|->
name|ctrl
operator|->
name|disable
argument_list|(
name|slt
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	disable_slot - Disables the slot by removing  *	the power and unmapping the I/O  */
end_comment

begin_function
specifier|static
name|void
name|disable_slot
parameter_list|(
name|struct
name|slot
modifier|*
name|slt
parameter_list|)
block|{
name|device_t
name|pccarddev
decl_stmt|;
name|device_t
modifier|*
name|kids
decl_stmt|;
name|int
name|nkids
decl_stmt|;
name|int
name|i
decl_stmt|;
name|int
name|ret
decl_stmt|;
comment|/* 	 * Note that a race condition is possible here; if a 	 * driver is accessing the device and it is removed, then 	 * all bets are off... 	 */
name|pccarddev
operator|=
name|slt
operator|->
name|dev
expr_stmt|;
name|device_get_children
argument_list|(
name|pccarddev
argument_list|,
operator|&
name|kids
argument_list|,
operator|&
name|nkids
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nkids
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|ret
operator|=
name|device_delete_child
argument_list|(
name|pccarddev
argument_list|,
name|kids
index|[
name|i
index|]
argument_list|)
operator|)
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"pccard: delete of %s failed: %d\n"
argument_list|,
name|device_get_nameunit
argument_list|(
name|kids
index|[
name|i
index|]
argument_list|)
argument_list|,
name|ret
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|kids
argument_list|,
name|M_TEMP
argument_list|)
expr_stmt|;
comment|/* Power off the slot 1/2 second after removal of the card */
name|slt
operator|->
name|poff_ch
operator|=
name|timeout
argument_list|(
name|power_off_slot
argument_list|,
operator|(
name|caddr_t
operator|)
name|slt
argument_list|,
name|hz
operator|/
literal|2
argument_list|)
expr_stmt|;
name|slt
operator|->
name|pwr_off_pending
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|disable_slot_to
parameter_list|(
name|struct
name|slot
modifier|*
name|slt
parameter_list|)
block|{
name|disable_slot
argument_list|(
name|slt
argument_list|)
expr_stmt|;
if|if
condition|(
name|slt
operator|->
name|state
operator|==
name|empty
condition|)
name|printf
argument_list|(
literal|"pccard: card removed, slot %d\n"
argument_list|,
name|slt
operator|->
name|slotnum
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"pccard: card deactivated, slot %d\n"
argument_list|,
name|slt
operator|->
name|slotnum
argument_list|)
expr_stmt|;
name|pccard_remove_beep
argument_list|()
expr_stmt|;
name|selwakeup
argument_list|(
operator|&
name|slt
operator|->
name|selp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	pccard_init_slot - Initialize the slot controller and attach various  * things to it.  We also make the device for it.  We create the device that  * will be exported to devfs.  */
end_comment

begin_function
name|struct
name|slot
modifier|*
name|pccard_init_slot
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|slot_ctrl
modifier|*
name|ctrl
parameter_list|)
block|{
name|int
name|slotno
decl_stmt|;
name|struct
name|slot
modifier|*
name|slt
decl_stmt|;
name|slt
operator|=
name|PCCARD_DEVICE2SOFTC
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|slotno
operator|=
name|device_get_unit
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|slt
operator|->
name|dev
operator|=
name|dev
expr_stmt|;
name|slt
operator|->
name|d
operator|=
name|make_dev
argument_list|(
operator|&
name|crd_cdevsw
argument_list|,
name|slotno
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0600
argument_list|,
literal|"card%d"
argument_list|,
name|slotno
argument_list|)
expr_stmt|;
name|slt
operator|->
name|d
operator|->
name|si_drv1
operator|=
name|slt
expr_stmt|;
name|slt
operator|->
name|ctrl
operator|=
name|ctrl
expr_stmt|;
name|slt
operator|->
name|slotnum
operator|=
name|slotno
expr_stmt|;
name|callout_handle_init
argument_list|(
operator|&
name|slt
operator|->
name|insert_ch
argument_list|)
expr_stmt|;
name|callout_handle_init
argument_list|(
operator|&
name|slt
operator|->
name|poff_ch
argument_list|)
expr_stmt|;
return|return
operator|(
name|slt
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	allocate_driver - Create a new device entry for this  *	slot, and attach a driver to it.  */
end_comment

begin_function
specifier|static
name|int
name|allocate_driver
parameter_list|(
name|struct
name|slot
modifier|*
name|slt
parameter_list|,
name|struct
name|dev_desc
modifier|*
name|desc
parameter_list|)
block|{
name|struct
name|pccard_devinfo
modifier|*
name|devi
decl_stmt|;
name|device_t
name|pccarddev
decl_stmt|;
name|int
name|err
decl_stmt|,
name|irq
init|=
literal|0
decl_stmt|;
name|device_t
name|child
decl_stmt|;
name|device_t
modifier|*
name|devs
decl_stmt|;
name|int
name|count
decl_stmt|;
name|pccarddev
operator|=
name|slt
operator|->
name|dev
expr_stmt|;
name|err
operator|=
name|device_get_children
argument_list|(
name|pccarddev
argument_list|,
operator|&
name|devs
argument_list|,
operator|&
name|count
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
return|return
operator|(
name|err
operator|)
return|;
name|free
argument_list|(
name|devs
argument_list|,
name|M_TEMP
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
condition|)
block|{
name|device_printf
argument_list|(
name|pccarddev
argument_list|,
literal|"Can not attach more than one child.\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
name|irq
operator|=
name|ffs
argument_list|(
name|desc
operator|->
name|irqmask
argument_list|)
operator|-
literal|1
expr_stmt|;
name|MALLOC
argument_list|(
name|devi
argument_list|,
expr|struct
name|pccard_devinfo
operator|*
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|devi
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|devi
operator|->
name|name
argument_list|,
name|desc
operator|->
name|name
argument_list|)
expr_stmt|;
comment|/* 	 *	Create an entry for the device under this slot. 	 */
name|devi
operator|->
name|running
operator|=
literal|1
expr_stmt|;
name|devi
operator|->
name|slt
operator|=
name|slt
expr_stmt|;
name|bcopy
argument_list|(
name|desc
operator|->
name|misc
argument_list|,
name|devi
operator|->
name|misc
argument_list|,
sizeof|sizeof
argument_list|(
name|desc
operator|->
name|misc
argument_list|)
argument_list|)
expr_stmt|;
name|resource_list_init
argument_list|(
operator|&
name|devi
operator|->
name|resources
argument_list|)
expr_stmt|;
name|child
operator|=
name|device_add_child
argument_list|(
name|pccarddev
argument_list|,
name|devi
operator|->
name|name
argument_list|,
name|desc
operator|->
name|unit
argument_list|)
expr_stmt|;
if|if
condition|(
name|child
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
argument|pccardd
argument_list|,
literal|"device_add_child shouldn't have failed, but did\n"
literal|"); 		return (EIO); 	} 	device_set_flags(child, desc->flags); 	device_set_ivars(child, devi); 	if (bootverbose) { 		device_printf(pccarddev, 		    "
argument|Assigning %s: io
literal|0x
argument|%x-
literal|0x
argument|%x irq %d mem
literal|0x
argument|%lx-
literal|0x
argument|%lx\n
literal|", 		    device_get_nameunit(child), 		    desc->iobase, desc->iobase + desc->iosize - 1, 		    irq, desc->mem, desc->mem + desc->memsize - 1);  	} 	err = bus_set_resource(child, SYS_RES_IOPORT, 0, desc->iobase, 	    desc->iosize); 	if (err) 		goto err; 	if (irq) 		err = bus_set_resource(child, SYS_RES_IRQ, 0, irq, 1); 	if (err) 		goto err; 	if (desc->memsize) { 		err = bus_set_resource(child, SYS_RES_MEMORY, 0, desc->mem, 		    desc->memsize); 		if (err) 			goto err; 	} 	err = device_probe_and_attach(child); 	/* 	 * XXX We unwisely assume that the detach code won't run while the 	 * XXX the attach code is attaching.  Someone should put some 	 * XXX interlock code.  This can happen if probe/attach takes a while 	 * XXX and the user ejects the card, which causes the detach 	 * XXX function to be called. 	 */ 	strncpy(desc->name, device_get_nameunit(child), sizeof(desc->name)); 	desc->name[sizeof(desc->name) - 1] = '\0'; err: 	if (err) 		device_delete_child(pccarddev, child); 	return (err); }  /*  *	card insert routine - Called from a timeout to debounce  *	insertion events.  */ static void inserted(void *arg) { 	struct slot *slt = arg;  	slt->state = filled; 	/* 	 *	Enable 5V to the card so that the CIS can be read. 	 */ 	slt->pwr.vcc = 50; 	slt->pwr.vpp = 50;  	/* 	 * Disable any pending timeouts for this slot, and explicitly 	 * power it off right now.  Then, re-enable the power using 	 * the (possibly new) power settings. 	 */ 	untimeout(power_off_slot, (caddr_t)slt, slt->poff_ch); 	power_off_slot(slt); 	slt->ctrl->power(slt);  	printf("
argument|pccard: card inserted
argument_list|,
argument|slot %d\n
literal|", slt->slotnum); 	pccard_insert_beep(); 	/* 	 *	Now start resetting the card. 	 */ 	slt->ctrl->reset(slt); }  /*  *	Card event callback. Called at splhigh to prevent  *	device interrupts from interceding.  */ void pccard_event(struct slot *slt, enum card_event event) { 	if (slt->insert_seq) { 		slt->insert_seq = 0; 		untimeout(inserted, (void *)slt, slt->insert_ch); 	}  	switch(event) { 	case card_removed: 	case card_deactivated: 		if (slt->state == filled || slt->state == inactive) { 			if (event == card_removed) 				slt->state = empty; 			else 				slt->state = inactive; 			disable_slot_to(slt); 		} 		break; 	case card_inserted: 		slt->insert_seq = 1; 		slt->insert_ch = timeout(inserted, (void *)slt, hz/4); 		break; 	} }  /*  *	Device driver interface.  */ static	int crdopen(dev_t dev, int oflags, int devtype, struct thread *td) { 	struct slot *slt = PCCARD_DEV2SOFTC(dev);  	if (slt == NULL) 		return (ENXIO); 	if (slt->rwmem == 0) 		slt->rwmem = MDF_ATTR; 	return (0); }  /*  *	Close doesn't de-allocate any resources, since  *	slots may be assigned to drivers already.  */ static	int crdclose(dev_t dev, int fflag, int devtype, struct thread *td) { 	return (0); }  /*  *	read interface. Map memory at lseek offset,  *	then transfer to user space.  */ static	int crdread(dev_t dev, struct uio *uio, int ioflag) { 	struct slot *slt = PCCARD_DEV2SOFTC(dev); 	struct mem_desc *mp, oldmap; 	unsigned char *p; 	unsigned int offs; 	int error = 0, win, count;  	if (slt == 0 || slt->state != filled) 		return (ENXIO); 	if (pccard_mem == 0) 		return (ENOMEM); 	for (win = 0; win< slt->ctrl->maxmem; win++) 		if ((slt->mem[win].flags& MDF_ACTIVE) == 0) 			break; 	if (win>= slt->ctrl->maxmem) 		return (EBUSY); 	mp =&slt->mem[win]; 	oldmap = *mp; 	mp->flags = slt->rwmem | MDF_ACTIVE; 	while (uio->uio_resid&& error == 0) { 		mp->card = uio->uio_offset; 		mp->size = PCCARD_MEMSIZE; 		mp->start = (caddr_t)(void *)(uintptr_t)pccard_mem; 		if ((error = slt->ctrl->mapmem(slt, win)) != 0) 			break; 		offs = (unsigned int)uio->uio_offset& (PCCARD_MEMSIZE - 1); 		p = pccard_kmem + offs; 		count = MIN(PCCARD_MEMSIZE - offs, uio->uio_resid); 		error = uiomove(p, count, uio); 	} 	/* 	 *	Restore original map. 	 */ 	*mp = oldmap; 	slt->ctrl->mapmem(slt, win);  	return (error); }  /*  *	crdwrite - Write data to card memory.  *	Handles wrap around so that only one memory  *	window is used.  */ static	int crdwrite(dev_t dev, struct uio *uio, int ioflag) { 	struct slot *slt = PCCARD_DEV2SOFTC(dev); 	struct mem_desc *mp, oldmap; 	unsigned char *p; 	unsigned int offs; 	int error = 0, win, count;  	if (slt == 0 || slt->state != filled) 		return (ENXIO); 	if (pccard_mem == 0) 		return (ENOMEM); 	for (win = 0; win< slt->ctrl->maxmem; win++) 		if ((slt->mem[win].flags& MDF_ACTIVE) == 0) 			break; 	if (win>= slt->ctrl->maxmem) 		return (EBUSY); 	mp =&slt->mem[win]; 	oldmap = *mp; 	mp->flags = slt->rwmem | MDF_ACTIVE; 	while (uio->uio_resid&& error == 0) { 		mp->card = uio->uio_offset; 		mp->size = PCCARD_MEMSIZE; 		mp->start = (caddr_t)(void *)(uintptr_t)pccard_mem; 		if ((error = slt->ctrl->mapmem(slt, win)) != 0) 			break; 		offs = (unsigned int)uio->uio_offset& (PCCARD_MEMSIZE - 1); 		p = pccard_kmem + offs; 		count = MIN(PCCARD_MEMSIZE - offs, uio->uio_resid); 		error = uiomove(p, count, uio); 	} 	/* 	 *	Restore original map. 	 */ 	*mp = oldmap; 	slt->ctrl->mapmem(slt, win);  	return (error); }  /*  *	ioctl calls - allows setting/getting of memory and I/O  *	descriptors, and assignment of drivers.  */ static	int crdioctl(dev_t dev, u_long cmd, caddr_t data, int fflag, struct thread *td) { 	u_int32_t	addr; 	int		err; 	struct io_desc	*ip; 	struct mem_desc *mp; 	device_t	pccarddev; 	int		pwval; 	int		s; 	struct slot	*slt = PCCARD_DEV2SOFTC(dev);  	if (slt == 0&& cmd != PIOCRWMEM) 		return (ENXIO); 	switch(cmd) { 	default: 		if (slt->ctrl->ioctl) 			return (slt->ctrl->ioctl(slt, cmd, data)); 		return (ENOTTY); 	/* 	 * Get slot state. 	 */ 	case PIOCGSTATE: 		s = splhigh(); 		((struct slotstate *)data)->state = slt->state; 		((struct slotstate *)data)->laststate = slt->laststate; 		slt->laststate = slt->state; 		splx(s); 		((struct slotstate *)data)->maxmem = slt->ctrl->maxmem; 		((struct slotstate *)data)->maxio = slt->ctrl->maxio; 		((struct slotstate *)data)->irqs = 0; 		break; 	/* 	 * Get memory context. 	 */ 	case PIOCGMEM: 		s = ((struct mem_desc *)data)->window; 		if (s< 0 || s>= slt->ctrl->maxmem) 			return (EINVAL); 		mp =&slt->mem[s]; 		((struct mem_desc *)data)->flags = mp->flags; 		((struct mem_desc *)data)->start = mp->start; 		((struct mem_desc *)data)->size = mp->size; 		((struct mem_desc *)data)->card = mp->card; 		break; 	/* 	 * Set memory context. If context already active, then unmap it. 	 * It is hard to see how the parameters can be checked. 	 * At the very least, we only allow root to set the context. 	 */ 	case PIOCSMEM: 		if (suser_td(td)) 			return (EPERM); 		if (slt->state != filled) 			return (ENXIO); 		s = ((struct mem_desc *)data)->window; 		if (s< 0 || s>= slt->ctrl->maxmem) 			return (EINVAL); 		slt->mem[s] = *((struct mem_desc *)data); 		return (slt->ctrl->mapmem(slt, s)); 	/* 	 * Get I/O port context. 	 */ 	case PIOCGIO: 		s = ((struct io_desc *)data)->window; 		if (s< 0 || s>= slt->ctrl->maxio) 			return (EINVAL); 		ip =&slt->io[s]; 		((struct io_desc *)data)->flags = ip->flags; 		((struct io_desc *)data)->start = ip->start; 		((struct io_desc *)data)->size = ip->size; 		break; 	/* 	 * Set I/O port context. 	 */ 	case PIOCSIO: 		if (suser_td(td)) 			return (EPERM); 		if (slt->state != filled) 			return (ENXIO); 		s = ((struct io_desc *)data)->window; 		if (s< 0 || s>= slt->ctrl->maxio) 			return (EINVAL); 		slt->io[s] = *((struct io_desc *)data); 		/* XXX Don't actually map */ 		return (0); 		break; 	/* 	 * Set memory window flags for read/write interface. 	 */ 	case PIOCRWFLAG: 		slt->rwmem = *(int *)data; 		break; 	/* 	 * Set the memory window to be used for the read/write interface. 	 * Not available on the alpha. 	 */ 	case PIOCRWMEM: 		if (*(unsigned long *)data == 0) { 			*(unsigned long *)data = pccard_mem; 			break; 		} 		if (suser_td(td)) 			return (EPERM); 		/* 		 * Validate the memory by checking it against the I/O 		 * memory range. It must also start on an aligned block size. 		 */ 		if (*(unsigned long *)data& (PCCARD_MEMSIZE-1)) 			return (EINVAL); 		pccarddev = PCCARD_DEV2SOFTC(dev)->dev; 		pccard_mem_rid = 0; 		addr = *(unsigned long *)data; 		if (pccard_mem_res) 			bus_release_resource(pccarddev, SYS_RES_MEMORY, 			    pccard_mem_rid, pccard_mem_res); 		pccard_mem_res = bus_alloc_resource(pccarddev, SYS_RES_MEMORY,&pccard_mem_rid, addr, addr, PCCARD_MEMSIZE, 		    RF_ACTIVE | rman_make_alignment_flags(PCCARD_MEMSIZE)); 		if (pccard_mem_res == NULL) 			return (EINVAL); 		pccard_mem = rman_get_start(pccard_mem_res); 		pccard_kmem = rman_get_virtual(pccard_mem_res); 		break; 	/* 	 * Set power values. 	 */ 	case PIOCSPOW: 		slt->pwr = *(struct power *)data; 		return (slt->ctrl->power(slt)); 	/* 	 * Allocate a driver to this slot. 	 */ 	case PIOCSDRV: 		if (suser_td(td)) 			return (EPERM); 		err = allocate_driver(slt, (struct dev_desc *)data); 		if (!err) 			pccard_success_beep(); 		else 			pccard_failure_beep(); 		return (err); 	/* 	 * Virtual removal/insertion 	 */ 	case PIOCSVIR: 		pwval = *(int *)data; 		if (!pwval) { 			if (slt->state != filled) 				return (EINVAL); 			pccard_event(slt, card_deactivated); 		} else { 			if (slt->state != empty&& slt->state != inactive) 				return (EINVAL); 			pccard_event(slt, card_inserted); 		} 		break; 	case PIOCSBEEP: 		if (pccard_beep_select(*(int *)data)) { 			return (EINVAL); 		} 		break; 	} 	return (0); }  /*  *	poll - Poll on exceptions will return true  *	when a change in card status occurs.  */ static	int crdpoll(dev_t dev, int events, struct thread *td) { 	int	revents = 0; 	int	s; 	struct slot *slt = PCCARD_DEV2SOFTC(dev);  	if (events& (POLLIN | POLLRDNORM)) 		revents |= events& (POLLIN | POLLRDNORM);  	if (events& (POLLOUT | POLLWRNORM)) 		revents |= events& (POLLIN | POLLRDNORM);  	s = splhigh(); 	/* 	 *	select for exception - card event. 	 */ 	if (events& POLLRDBAND) 		if (slt == 0 || slt->laststate != slt->state) 			revents |= POLLRDBAND;  	if (revents == 0) 		selrecord(td,&slt->selp);  	splx(s); 	return (revents); }  /*  *	APM hooks for suspending and resuming.  */ int pccard_suspend(device_t dev) { 	struct slot *slt = PCCARD_DEVICE2SOFTC(dev);  	/* This code stolen from pccard_event:card_removed */ 	if (slt->state == filled) { 		int s = splhigh();		/* nop on current */ 		disable_slot(slt); 		slt->laststate = suspend;	/* for pccardd */ 		slt->state = empty; 		splx(s); 		printf("
argument|pccard: card disabled
argument_list|,
argument|slot %d\n
literal|"
end_function

unit|, slt->slotnum); 	} 	/* 	 * Disable any pending timeouts for this slot since we're 	 * powering it down/disabling now. 	 */ 	untimeout(power_off_slot, (caddr_t)slt, slt->poff_ch); 	slt->ctrl->disable(slt); 	return (0); }  int pccard_resume(device_t dev) { 	struct slot *slt = PCCARD_DEVICE2SOFTC(dev);  	slt->ctrl->resume(slt); 	return (0); }
end_unit

