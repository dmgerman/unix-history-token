begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)autoconf.c	7.1 (Berkeley) 5/9/91  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Setup the system to run on the current machine.  *  * Configure() is called at boot time and initializes the vba  * device tables and the memory controller monitoring.  Available  * devices are determined (from possibilities mentioned in ioconf.c),  * and the drivers are initialized.  */
end_comment

begin_include
include|#
directive|include
file|"opt_bootp.h"
end_include

begin_include
include|#
directive|include
file|"opt_isa.h"
end_include

begin_include
include|#
directive|include
file|"opt_nfs.h"
end_include

begin_include
include|#
directive|include
file|"opt_nfsroot.h"
end_include

begin_include
include|#
directive|include
file|"opt_bus.h"
end_include

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
file|<sys/reboot.h>
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
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<nfs/rpcv2.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfsproto.h>
end_include

begin_include
include|#
directive|include
file|<nfsclient/nfs.h>
end_include

begin_include
include|#
directive|include
file|<nfsclient/nfsdiskless.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_IO
end_ifdef

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_else
else|#
directive|else
end_else

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
comment|/* APIC_IO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_ISA
end_ifdef

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_decl_stmt
name|device_t
name|isa_bus_device
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|void
name|configure_first
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|configure
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|configure_final
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|SYSINIT
argument_list|(
name|configure1
argument_list|,
name|SI_SUB_CONFIGURE
argument_list|,
name|SI_ORDER_FIRST
argument_list|,
name|configure_first
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* SI_ORDER_SECOND is hookable */
end_comment

begin_expr_stmt
name|SYSINIT
argument_list|(
name|configure2
argument_list|,
name|SI_SUB_CONFIGURE
argument_list|,
name|SI_ORDER_THIRD
argument_list|,
name|configure
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* SI_ORDER_MIDDLE is hookable */
end_comment

begin_expr_stmt
name|SYSINIT
argument_list|(
name|configure3
argument_list|,
name|SI_SUB_CONFIGURE
argument_list|,
name|SI_ORDER_ANY
argument_list|,
name|configure_final
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Determine i/o configuration for a machine.  */
end_comment

begin_function
specifier|static
name|void
name|configure_first
parameter_list|(
name|dummy
parameter_list|)
name|void
modifier|*
name|dummy
decl_stmt|;
block|{ }
end_function

begin_function
specifier|static
name|void
name|configure
parameter_list|(
name|dummy
parameter_list|)
name|void
modifier|*
name|dummy
decl_stmt|;
block|{
comment|/* 	 * Activate the ICU's.  Note that we are explicitly at splhigh() 	 * at present as we have no way to disable stray PCI level triggered 	 * interrupts until the devices have had a driver attached.  This 	 * is particularly a problem when the interrupts are shared.  For 	 * example, if IRQ 10 is shared between a disk and network device 	 * and the disk device generates an interrupt, if we "activate" 	 * IRQ 10 when the network driver is set up, then we will get 	 * recursive interrupt 10's as nothing will know how to turn off 	 * the disk device's interrupt. 	 * 	 * Having the ICU's active means we can probe interrupt routing to 	 * see if a device causes the corresponding pending bit to be set. 	 * 	 * This is all rather inconvenient. 	 */
ifdef|#
directive|ifdef
name|APIC_IO
name|bsp_apic_configure
argument_list|()
expr_stmt|;
name|enable_intr
argument_list|()
expr_stmt|;
else|#
directive|else
name|enable_intr
argument_list|()
expr_stmt|;
name|INTREN
argument_list|(
name|IRQ_SLAVE
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* APIC_IO */
comment|/* nexus0 is the top of the i386 device tree */
name|device_add_child
argument_list|(
name|root_bus
argument_list|,
literal|"nexus"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* initialize new bus architecture */
name|root_bus_configure
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DEV_ISA
comment|/* 	 * Explicitly probe and attach ISA last.  The isa bus saves 	 * it's device node at attach time for us here. 	 */
if|if
condition|(
name|isa_bus_device
condition|)
name|isa_probe_children
argument_list|(
name|isa_bus_device
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Now we're ready to handle (pending) interrupts. 	 * XXX this is slightly misplaced. 	 */
name|spl0
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|configure_final
parameter_list|(
name|dummy
parameter_list|)
name|void
modifier|*
name|dummy
decl_stmt|;
block|{
name|cninit_finish
argument_list|()
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
block|{
ifdef|#
directive|ifdef
name|APIC_IO
name|imen_dump
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* APIC_IO */
ifdef|#
directive|ifdef
name|PC98
block|{
name|int
name|i
decl_stmt|;
comment|/* 		 * Print out the BIOS's idea of the disk geometries. 		 */
name|printf
argument_list|(
literal|"BIOS Geometries:\n"
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
name|N_BIOS_GEOM
condition|;
name|i
operator|++
control|)
block|{
name|unsigned
name|long
name|bios_geom
decl_stmt|;
name|int
name|max_cylinder
decl_stmt|,
name|max_head
decl_stmt|,
name|max_sector
decl_stmt|;
name|bios_geom
operator|=
name|bootinfo
operator|.
name|bi_bios_geom
index|[
name|i
index|]
expr_stmt|;
comment|/* 			 * XXX the bootstrap punts a 1200K floppy geometry 			 * when the get-disk-geometry interrupt fails.  Skip 			 * drives that have this geometry. 			 */
if|if
condition|(
name|bios_geom
operator|==
literal|0x4f010f
condition|)
continue|continue;
name|printf
argument_list|(
literal|" %x:%08lx "
argument_list|,
name|i
argument_list|,
name|bios_geom
argument_list|)
expr_stmt|;
name|max_cylinder
operator|=
name|bios_geom
operator|>>
literal|16
expr_stmt|;
name|max_head
operator|=
operator|(
name|bios_geom
operator|>>
literal|8
operator|)
operator|&
literal|0xff
expr_stmt|;
name|max_sector
operator|=
name|bios_geom
operator|&
literal|0xff
expr_stmt|;
name|printf
argument_list|(
literal|"0..%d=%d cylinders, 0..%d=%d heads, 1..%d=%d sectors\n"
argument_list|,
name|max_cylinder
argument_list|,
name|max_cylinder
operator|+
literal|1
argument_list|,
name|max_head
argument_list|,
name|max_head
operator|+
literal|1
argument_list|,
name|max_sector
argument_list|,
name|max_sector
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|" %d accounted for\n"
argument_list|,
name|bootinfo
operator|.
name|bi_n_bios_used
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|printf
argument_list|(
literal|"Device configuration finished.\n"
argument_list|)
expr_stmt|;
block|}
name|cold
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Do legacy root filesystem discovery.  */
end_comment

begin_function
name|void
name|cpu_rootconf
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|BOOTP
name|bootpc_init
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|NFSCLIENT
argument_list|)
operator|&&
name|defined
argument_list|(
name|NFS_ROOT
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BOOTP_NFSROOT
argument_list|)
name|nfs_setup_diskless
argument_list|()
expr_stmt|;
if|if
condition|(
name|nfs_diskless_valid
condition|)
endif|#
directive|endif
name|rootdevnames
index|[
literal|0
index|]
operator|=
literal|"nfs:"
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_macro
name|SYSINIT
argument_list|(
argument|cpu_rootconf
argument_list|,
argument|SI_SUB_ROOT_CONF
argument_list|,
argument|SI_ORDER_FIRST
argument_list|,
argument|cpu_rootconf
argument_list|,
argument|NULL
argument_list|)
end_macro

end_unit

