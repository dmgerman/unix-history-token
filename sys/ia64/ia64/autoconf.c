begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_include
include|#
directive|include
file|<sys/diskslice.h>
end_include

begin_comment
comment|/* for BASE_SLICE, MAX_SLICES */
end_comment

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
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/devicestat.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_ccb.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_periph.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_decl_stmt
specifier|static
name|void
name|configure
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|SYSINIT
argument_list|(
argument|configure
argument_list|,
argument|SI_SUB_CONFIGURE
argument_list|,
argument|SI_ORDER_THIRD
argument_list|,
argument|configure
argument_list|,
argument|NULL
argument_list|)
end_macro

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

begin_decl_stmt
specifier|extern
name|int
name|nfs_diskless_valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX use include file */
end_comment

begin_decl_stmt
name|dev_t
name|rootdev
init|=
name|NODEV
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|dumpdev
init|=
name|NODEV
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Determine i/o configuration for a machine.  */
end_comment

begin_function
specifier|static
name|void
name|configure
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|device_add_child
argument_list|(
name|root_bus
argument_list|,
literal|"nexus"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|root_bus_configure
argument_list|()
expr_stmt|;
comment|/* 	 * Probe ISA devices after everything. 	 */
ifdef|#
directive|ifdef
name|DEV_ISA
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
name|enable_intr
argument_list|()
expr_stmt|;
name|cold
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Do legacy root filesystem discovery.  This isn't really  * needed on the Alpha, which has always used the loader.  */
end_comment

begin_function
name|void
name|cpu_rootconf
parameter_list|()
block|{
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
name|int
name|order
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BOOTP
if|if
condition|(
operator|!
name|ia64_running_in_simulator
argument_list|()
condition|)
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
if|if
condition|(
name|nfs_diskless_valid
condition|)
endif|#
directive|endif
name|rootdevnames
index|[
name|order
operator|++
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

