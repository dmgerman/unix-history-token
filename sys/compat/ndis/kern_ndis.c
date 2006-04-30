begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/pe_var.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/cfg_var.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/resource_var.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/ntoskrnl_var.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/ndis_var.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/hal_var.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/usbd_var.h>
end_include

begin_include
include|#
directive|include
file|<dev/if_ndis/if_ndisvar.h>
end_include

begin_define
define|#
directive|define
name|NDIS_DUMMY_PATH
value|"\\\\some\\bogus\\path"
end_define

begin_function_decl
specifier|static
name|void
name|ndis_status_func
parameter_list|(
name|ndis_handle
parameter_list|,
name|ndis_status
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ndis_statusdone_func
parameter_list|(
name|ndis_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ndis_setdone_func
parameter_list|(
name|ndis_handle
parameter_list|,
name|ndis_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ndis_getdone_func
parameter_list|(
name|ndis_handle
parameter_list|,
name|ndis_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ndis_resetdone_func
parameter_list|(
name|ndis_handle
parameter_list|,
name|ndis_status
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ndis_sendrsrcavail_func
parameter_list|(
name|ndis_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ndis_intrsetup
parameter_list|(
name|kdpc
modifier|*
parameter_list|,
name|device_object
modifier|*
parameter_list|,
name|irp
modifier|*
parameter_list|,
name|struct
name|ndis_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ndis_return
parameter_list|(
name|device_object
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|image_patch_table
name|kernndis_functbl
index|[]
init|=
block|{
name|IMPORT_SFUNC
argument_list|(
name|ndis_status_func
argument_list|,
literal|4
argument_list|)
block|,
name|IMPORT_SFUNC
argument_list|(
name|ndis_statusdone_func
argument_list|,
literal|1
argument_list|)
block|,
name|IMPORT_SFUNC
argument_list|(
name|ndis_setdone_func
argument_list|,
literal|2
argument_list|)
block|,
name|IMPORT_SFUNC
argument_list|(
name|ndis_getdone_func
argument_list|,
literal|2
argument_list|)
block|,
name|IMPORT_SFUNC
argument_list|(
name|ndis_resetdone_func
argument_list|,
literal|3
argument_list|)
block|,
name|IMPORT_SFUNC
argument_list|(
name|ndis_sendrsrcavail_func
argument_list|,
literal|1
argument_list|)
block|,
name|IMPORT_SFUNC
argument_list|(
name|ndis_intrsetup
argument_list|,
literal|4
argument_list|)
block|,
name|IMPORT_SFUNC
argument_list|(
name|ndis_return
argument_list|,
literal|1
argument_list|)
block|,
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|nd_head
name|ndis_devhead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This allows us to export our symbols to other modules.  * Note that we call ourselves 'ndisapi' to avoid a namespace  * collision with if_ndis.ko, which internally calls itself  * 'ndis.'  *  * Note: some of the subsystems depend on each other, so the  * order in which they're started is important. The order of  * importance is:  *  * HAL - spinlocks and IRQL manipulation  * ntoskrnl - DPC and workitem threads, object waiting  * windrv - driver/device registration  *  * The HAL should also be the last thing shut down, since  * the ntoskrnl subsystem will use spinlocks right up until  * the DPC and workitem threads are terminated.  */
end_comment

begin_function
specifier|static
name|int
name|ndis_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|image_patch_table
modifier|*
name|patch
decl_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|MOD_LOAD
case|:
comment|/* Initialize subsystems */
name|hal_libinit
argument_list|()
expr_stmt|;
name|ntoskrnl_libinit
argument_list|()
expr_stmt|;
name|windrv_libinit
argument_list|()
expr_stmt|;
name|ndis_libinit
argument_list|()
expr_stmt|;
name|usbd_libinit
argument_list|()
expr_stmt|;
name|patch
operator|=
name|kernndis_functbl
expr_stmt|;
while|while
condition|(
name|patch
operator|->
name|ipt_func
operator|!=
name|NULL
condition|)
block|{
name|windrv_wrap
argument_list|(
operator|(
name|funcptr
operator|)
name|patch
operator|->
name|ipt_func
argument_list|,
operator|(
name|funcptr
operator|*
operator|)
operator|&
name|patch
operator|->
name|ipt_wrap
argument_list|,
name|patch
operator|->
name|ipt_argcnt
argument_list|,
name|patch
operator|->
name|ipt_ftype
argument_list|)
expr_stmt|;
name|patch
operator|++
expr_stmt|;
block|}
name|TAILQ_INIT
argument_list|(
operator|&
name|ndis_devhead
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_SHUTDOWN
case|:
if|if
condition|(
name|TAILQ_FIRST
argument_list|(
operator|&
name|ndis_devhead
argument_list|)
operator|==
name|NULL
condition|)
block|{
comment|/* Shut down subsystems */
name|ndis_libfini
argument_list|()
expr_stmt|;
name|usbd_libfini
argument_list|()
expr_stmt|;
name|windrv_libfini
argument_list|()
expr_stmt|;
name|ntoskrnl_libfini
argument_list|()
expr_stmt|;
name|hal_libfini
argument_list|()
expr_stmt|;
name|patch
operator|=
name|kernndis_functbl
expr_stmt|;
while|while
condition|(
name|patch
operator|->
name|ipt_func
operator|!=
name|NULL
condition|)
block|{
name|windrv_unwrap
argument_list|(
name|patch
operator|->
name|ipt_wrap
argument_list|)
expr_stmt|;
name|patch
operator|++
expr_stmt|;
block|}
block|}
break|break;
case|case
name|MOD_UNLOAD
case|:
comment|/* Shut down subsystems */
name|ndis_libfini
argument_list|()
expr_stmt|;
name|usbd_libfini
argument_list|()
expr_stmt|;
name|windrv_libfini
argument_list|()
expr_stmt|;
name|ntoskrnl_libfini
argument_list|()
expr_stmt|;
name|hal_libfini
argument_list|()
expr_stmt|;
name|patch
operator|=
name|kernndis_functbl
expr_stmt|;
while|while
condition|(
name|patch
operator|->
name|ipt_func
operator|!=
name|NULL
condition|)
block|{
name|windrv_unwrap
argument_list|(
name|patch
operator|->
name|ipt_wrap
argument_list|)
expr_stmt|;
name|patch
operator|++
expr_stmt|;
block|}
break|break;
default|default:
name|error
operator|=
name|EINVAL
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DEV_MODULE
argument_list|(
name|ndisapi
argument_list|,
name|ndis_modevent
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|ndisapi
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|ndis_sendrsrcavail_func
parameter_list|(
name|adapter
parameter_list|)
name|ndis_handle
name|adapter
decl_stmt|;
block|{
return|return;
block|}
end_function

begin_function
specifier|static
name|void
name|ndis_status_func
parameter_list|(
name|adapter
parameter_list|,
name|status
parameter_list|,
name|sbuf
parameter_list|,
name|slen
parameter_list|)
name|ndis_handle
name|adapter
decl_stmt|;
name|ndis_status
name|status
decl_stmt|;
name|void
modifier|*
name|sbuf
decl_stmt|;
name|uint32_t
name|slen
decl_stmt|;
block|{
name|ndis_miniport_block
modifier|*
name|block
decl_stmt|;
name|struct
name|ndis_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|block
operator|=
name|adapter
expr_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|block
operator|->
name|nmb_physdeviceobj
operator|->
name|do_devext
argument_list|)
expr_stmt|;
name|ifp
operator|=
name|sc
operator|->
name|ifp
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_DEBUG
condition|)
name|device_printf
argument_list|(
name|sc
operator|->
name|ndis_dev
argument_list|,
literal|"status: %x\n"
argument_list|,
name|status
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
name|void
name|ndis_statusdone_func
parameter_list|(
name|adapter
parameter_list|)
name|ndis_handle
name|adapter
decl_stmt|;
block|{
name|ndis_miniport_block
modifier|*
name|block
decl_stmt|;
name|struct
name|ndis_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|block
operator|=
name|adapter
expr_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|block
operator|->
name|nmb_physdeviceobj
operator|->
name|do_devext
argument_list|)
expr_stmt|;
name|ifp
operator|=
name|sc
operator|->
name|ifp
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_DEBUG
condition|)
name|device_printf
argument_list|(
name|sc
operator|->
name|ndis_dev
argument_list|,
literal|"status complete\n"
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
name|void
name|ndis_setdone_func
parameter_list|(
name|adapter
parameter_list|,
name|status
parameter_list|)
name|ndis_handle
name|adapter
decl_stmt|;
name|ndis_status
name|status
decl_stmt|;
block|{
name|ndis_miniport_block
modifier|*
name|block
decl_stmt|;
name|block
operator|=
name|adapter
expr_stmt|;
name|block
operator|->
name|nmb_setstat
operator|=
name|status
expr_stmt|;
name|KeSetEvent
argument_list|(
operator|&
name|block
operator|->
name|nmb_setevent
argument_list|,
name|IO_NO_INCREMENT
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
name|void
name|ndis_getdone_func
parameter_list|(
name|adapter
parameter_list|,
name|status
parameter_list|)
name|ndis_handle
name|adapter
decl_stmt|;
name|ndis_status
name|status
decl_stmt|;
block|{
name|ndis_miniport_block
modifier|*
name|block
decl_stmt|;
name|block
operator|=
name|adapter
expr_stmt|;
name|block
operator|->
name|nmb_getstat
operator|=
name|status
expr_stmt|;
name|KeSetEvent
argument_list|(
operator|&
name|block
operator|->
name|nmb_getevent
argument_list|,
name|IO_NO_INCREMENT
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
name|void
name|ndis_resetdone_func
parameter_list|(
name|adapter
parameter_list|,
name|status
parameter_list|,
name|addressingreset
parameter_list|)
name|ndis_handle
name|adapter
decl_stmt|;
name|ndis_status
name|status
decl_stmt|;
name|uint8_t
name|addressingreset
decl_stmt|;
block|{
name|ndis_miniport_block
modifier|*
name|block
decl_stmt|;
name|struct
name|ndis_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|block
operator|=
name|adapter
expr_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|block
operator|->
name|nmb_physdeviceobj
operator|->
name|do_devext
argument_list|)
expr_stmt|;
name|ifp
operator|=
name|sc
operator|->
name|ifp
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_DEBUG
condition|)
name|device_printf
argument_list|(
name|sc
operator|->
name|ndis_dev
argument_list|,
literal|"reset done...\n"
argument_list|)
expr_stmt|;
name|KeSetEvent
argument_list|(
operator|&
name|block
operator|->
name|nmb_resetevent
argument_list|,
name|IO_NO_INCREMENT
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|int
name|ndis_create_sysctls
parameter_list|(
name|arg
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
block|{
name|struct
name|ndis_softc
modifier|*
name|sc
decl_stmt|;
name|ndis_cfg
modifier|*
name|vals
decl_stmt|;
name|char
name|buf
index|[
literal|256
index|]
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|oidp
decl_stmt|;
name|struct
name|sysctl_ctx_entry
modifier|*
name|e
decl_stmt|;
if|if
condition|(
name|arg
operator|==
name|NULL
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
name|sc
operator|=
name|arg
expr_stmt|;
name|vals
operator|=
name|sc
operator|->
name|ndis_regvals
expr_stmt|;
name|TAILQ_INIT
argument_list|(
operator|&
name|sc
operator|->
name|ndis_cfglist_head
argument_list|)
expr_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|502113
comment|/* Create the sysctl tree. */
name|sc
operator|->
name|ndis_tree
operator|=
name|SYSCTL_ADD_NODE
argument_list|(
operator|&
name|sc
operator|->
name|ndis_ctx
argument_list|,
name|SYSCTL_STATIC_CHILDREN
argument_list|(
name|_hw
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
name|device_get_nameunit
argument_list|(
name|sc
operator|->
name|ndis_dev
argument_list|)
argument_list|,
name|CTLFLAG_RD
argument_list|,
literal|0
argument_list|,
name|device_get_desc
argument_list|(
name|sc
operator|->
name|ndis_dev
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Add the driver-specific registry keys. */
while|while
condition|(
literal|1
condition|)
block|{
if|if
condition|(
name|vals
operator|->
name|nc_cfgkey
operator|==
name|NULL
condition|)
break|break;
if|if
condition|(
name|vals
operator|->
name|nc_idx
operator|!=
name|sc
operator|->
name|ndis_devidx
condition|)
block|{
name|vals
operator|++
expr_stmt|;
continue|continue;
block|}
comment|/* See if we already have a sysctl with this name */
name|oidp
operator|=
name|NULL
expr_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|502113
name|TAILQ_FOREACH
argument_list|(
argument|e
argument_list|,
argument|&sc->ndis_ctx
argument_list|,
argument|link
argument_list|)
block|{
else|#
directive|else
name|TAILQ_FOREACH
argument_list|(
argument|e
argument_list|,
argument|device_get_sysctl_ctx(sc->ndis_dev)
argument_list|,
argument|link
argument_list|)
block|{
endif|#
directive|endif
name|oidp
operator|=
name|e
operator|->
name|entry
expr_stmt|;
if|if
condition|(
name|ndis_strcasecmp
argument_list|(
name|oidp
operator|->
name|oid_name
argument_list|,
name|vals
operator|->
name|nc_cfgkey
argument_list|)
operator|==
literal|0
condition|)
break|break;
name|oidp
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|oidp
operator|!=
name|NULL
condition|)
block|{
name|vals
operator|++
expr_stmt|;
continue|continue;
block|}
name|ndis_add_sysctl
argument_list|(
name|sc
argument_list|,
name|vals
operator|->
name|nc_cfgkey
argument_list|,
name|vals
operator|->
name|nc_cfgdesc
argument_list|,
name|vals
operator|->
name|nc_val
argument_list|,
name|CTLFLAG_RW
argument_list|)
expr_stmt|;
name|vals
operator|++
expr_stmt|;
block|}
comment|/* Now add a couple of builtin keys. */
comment|/* 	 * Environment can be either Windows (0) or WindowsNT (1). 	 * We qualify as the latter. 	 */
name|ndis_add_sysctl
argument_list|(
name|sc
argument_list|,
literal|"Environment"
argument_list|,
literal|"Windows environment"
argument_list|,
literal|"1"
argument_list|,
name|CTLFLAG_RD
argument_list|)
expr_stmt|;
comment|/* NDIS version should be 5.1. */
name|ndis_add_sysctl
argument_list|(
name|sc
argument_list|,
literal|"NdisVersion"
argument_list|,
literal|"NDIS API Version"
argument_list|,
literal|"0x00050001"
argument_list|,
name|CTLFLAG_RD
argument_list|)
expr_stmt|;
comment|/* Bus type (PCI, PCMCIA, etc...) */
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%d"
argument_list|,
operator|(
name|int
operator|)
name|sc
operator|->
name|ndis_iftype
argument_list|)
expr_stmt|;
name|ndis_add_sysctl
argument_list|(
name|sc
argument_list|,
literal|"BusType"
argument_list|,
literal|"Bus Type"
argument_list|,
name|buf
argument_list|,
name|CTLFLAG_RD
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|ndis_res_io
operator|!=
name|NULL
condition|)
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"0x%lx"
argument_list|,
name|rman_get_start
argument_list|(
name|sc
operator|->
name|ndis_res_io
argument_list|)
argument_list|)
expr_stmt|;
name|ndis_add_sysctl
argument_list|(
name|sc
argument_list|,
literal|"IOBaseAddress"
argument_list|,
literal|"Base I/O Address"
argument_list|,
name|buf
argument_list|,
name|CTLFLAG_RD
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sc
operator|->
name|ndis_irq
operator|!=
name|NULL
condition|)
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%lu"
argument_list|,
name|rman_get_start
argument_list|(
name|sc
operator|->
name|ndis_irq
argument_list|)
argument_list|)
expr_stmt|;
name|ndis_add_sysctl
argument_list|(
name|sc
argument_list|,
literal|"InterruptNumber"
argument_list|,
literal|"Interrupt Number"
argument_list|,
name|buf
argument_list|,
name|CTLFLAG_RD
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|int
name|ndis_add_sysctl
parameter_list|(
name|arg
parameter_list|,
name|key
parameter_list|,
name|desc
parameter_list|,
name|val
parameter_list|,
name|flag
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
name|char
modifier|*
name|key
decl_stmt|;
name|char
modifier|*
name|desc
decl_stmt|;
name|char
modifier|*
name|val
decl_stmt|;
name|int
name|flag
decl_stmt|;
block|{
name|struct
name|ndis_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|ndis_cfglist
modifier|*
name|cfg
decl_stmt|;
name|char
name|descstr
index|[
literal|256
index|]
decl_stmt|;
name|sc
operator|=
name|arg
expr_stmt|;
name|cfg
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|ndis_cfglist
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_NOWAIT
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
if|if
condition|(
name|cfg
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"failed for %s\n"
argument_list|,
name|key
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOMEM
operator|)
return|;
block|}
name|cfg
operator|->
name|ndis_cfg
operator|.
name|nc_cfgkey
operator|=
name|strdup
argument_list|(
name|key
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
if|if
condition|(
name|desc
operator|==
name|NULL
condition|)
block|{
name|snprintf
argument_list|(
name|descstr
argument_list|,
sizeof|sizeof
argument_list|(
name|descstr
argument_list|)
argument_list|,
literal|"%s (dynamic)"
argument_list|,
name|key
argument_list|)
expr_stmt|;
name|cfg
operator|->
name|ndis_cfg
operator|.
name|nc_cfgdesc
operator|=
name|strdup
argument_list|(
name|descstr
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
block|}
else|else
name|cfg
operator|->
name|ndis_cfg
operator|.
name|nc_cfgdesc
operator|=
name|strdup
argument_list|(
name|desc
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|cfg
operator|->
name|ndis_cfg
operator|.
name|nc_val
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|sc
operator|->
name|ndis_cfglist_head
argument_list|,
name|cfg
argument_list|,
name|link
argument_list|)
expr_stmt|;
name|cfg
operator|->
name|ndis_oid
operator|=
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|502113
name|SYSCTL_ADD_STRING
argument_list|(
argument|&sc->ndis_ctx
argument_list|,
argument|SYSCTL_CHILDREN(sc->ndis_tree)
argument_list|,
else|#
directive|else
argument|SYSCTL_ADD_STRING(device_get_sysctl_ctx(sc->ndis_dev), 	    SYSCTL_CHILDREN(device_get_sysctl_tree(sc->ndis_dev)),
endif|#
directive|endif
argument|OID_AUTO, cfg->ndis_cfg.nc_cfgkey, flag, 	    cfg->ndis_cfg.nc_val, sizeof(cfg->ndis_cfg.nc_val), 	    cfg->ndis_cfg.nc_cfgdesc);  	return(
literal|0
argument|); }
comment|/*  * Somewhere, somebody decided "hey, let's automatically create  * a sysctl tree for each device instance as it's created -- it'll  * make life so much easier!" Lies. Why must they turn the kernel  * into a house of lies?  */
argument|int ndis_flush_sysctls(arg) 	void			*arg; { 	struct ndis_softc	*sc; 	struct ndis_cfglist	*cfg; 	struct sysctl_ctx_list	*clist;  	sc = arg;
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|502113
argument|clist =&sc->ndis_ctx;
else|#
directive|else
argument|clist = device_get_sysctl_ctx(sc->ndis_dev);
endif|#
directive|endif
argument|while (!TAILQ_EMPTY(&sc->ndis_cfglist_head)) { 		cfg = TAILQ_FIRST(&sc->ndis_cfglist_head); 		TAILQ_REMOVE(&sc->ndis_cfglist_head, cfg, link); 		sysctl_ctx_entry_del(clist, cfg->ndis_oid); 		sysctl_remove_oid(cfg->ndis_oid,
literal|1
argument|,
literal|0
argument|); 		free(cfg->ndis_cfg.nc_cfgkey, M_DEVBUF); 		free(cfg->ndis_cfg.nc_cfgdesc, M_DEVBUF); 		free(cfg, M_DEVBUF); 	}  	return(
literal|0
argument|); }  static void ndis_return(dobj, arg) 	device_object		*dobj; 	void			*arg; { 	ndis_miniport_block	*block; 	ndis_miniport_characteristics	*ch; 	ndis_return_handler	returnfunc; 	ndis_handle		adapter; 	ndis_packet		*p; 	uint8_t			irql; 	list_entry		*l;  	block = arg; 	ch = IoGetDriverObjectExtension(dobj->do_drvobj, (void *)
literal|1
argument|);  	p = arg; 	adapter = block->nmb_miniportadapterctx;  	if (adapter == NULL) 		return;  	returnfunc = ch->nmc_return_packet_func;  	KeAcquireSpinLock(&block->nmb_returnlock,&irql); 	while (!IsListEmpty(&block->nmb_returnlist)) { 		l = RemoveHeadList((&block->nmb_returnlist)); 		p = CONTAINING_RECORD(l, ndis_packet, np_list); 		InitializeListHead((&p->np_list)); 		KeReleaseSpinLock(&block->nmb_returnlock, irql); 		MSCALL2(returnfunc, adapter, p); 		KeAcquireSpinLock(&block->nmb_returnlock,&irql); 	} 	KeReleaseSpinLock(&block->nmb_returnlock, irql);  	return; }  void ndis_return_packet(buf, arg) 	void			*buf;
comment|/* not used */
argument|void			*arg; { 	ndis_packet		*p; 	ndis_miniport_block	*block;  	if (arg == NULL) 		return;  	p = arg;
comment|/* Decrement refcount. */
argument|p->np_refcnt--;
comment|/* Release packet when refcount hits zero, otherwise return. */
argument|if (p->np_refcnt) 		return;  	block = ((struct ndis_softc *)p->np_softc)->ndis_block;  	KeAcquireSpinLockAtDpcLevel(&block->nmb_returnlock); 	InitializeListHead((&p->np_list)); 	InsertHeadList((&block->nmb_returnlist), (&p->np_list)); 	KeReleaseSpinLockFromDpcLevel(&block->nmb_returnlock);  	IoQueueWorkItem(block->nmb_returnitem, 	    (io_workitem_func)kernndis_functbl[
literal|7
argument|].ipt_wrap, 	    WORKQUEUE_CRITICAL, block);  	return; }  void ndis_free_bufs(b0) 	ndis_buffer		*b0; { 	ndis_buffer		*next;  	if (b0 == NULL) 		return;  	while(b0 != NULL) { 		next = b0->mdl_next; 		IoFreeMdl(b0); 		b0 = next; 	}  	return; } int in_reset =
literal|0
argument|; void ndis_free_packet(p) 	ndis_packet		*p; { 	if (p == NULL) 		return;  	ndis_free_bufs(p->np_private.npp_head); 	NdisFreePacket(p); 	return; }  int ndis_convert_res(arg) 	void			*arg; { 	struct ndis_softc	*sc; 	ndis_resource_list	*rl = NULL; 	cm_partial_resource_desc	*prd = NULL; 	ndis_miniport_block	*block; 	device_t		dev; 	struct resource_list	*brl; 	struct resource_list_entry	*brle;
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|600022
argument|struct resource_list	brl_rev; 	struct resource_list_entry	*n;
endif|#
directive|endif
argument|int 			error =
literal|0
argument|;  	sc = arg; 	block = sc->ndis_block; 	dev = sc->ndis_dev;
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|600022
argument|SLIST_INIT(&brl_rev);
endif|#
directive|endif
argument|rl = malloc(sizeof(ndis_resource_list) + 	    (sizeof(cm_partial_resource_desc) * (sc->ndis_rescnt -
literal|1
argument|)), 	    M_DEVBUF, M_NOWAIT|M_ZERO);  	if (rl == NULL) 		return(ENOMEM);  	rl->cprl_version =
literal|5
argument|; 	rl->cprl_version =
literal|1
argument|; 	rl->cprl_count = sc->ndis_rescnt; 	prd = rl->cprl_partial_descs;  	brl = BUS_GET_RESOURCE_LIST(dev, dev);  	if (brl != NULL) {
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|600022
comment|/* 		 * We have a small problem. Some PCI devices have 		 * multiple I/O ranges. Windows orders them starting 		 * from lowest numbered BAR to highest. We discover 		 * them in that order too, but insert them into a singly 		 * linked list head first, which means when time comes 		 * to traverse the list, we enumerate them in reverse 		 * order. This screws up some drivers which expect the 		 * BARs to be in ascending order so that they can choose 		 * the "first" one as their register space. Unfortunately, 		 * in order to fix this, we have to create our own 		 * temporary list with the entries in reverse order. 		 */
argument|SLIST_FOREACH(brle, brl, link) { 			n = malloc(sizeof(struct resource_list_entry), 			    M_TEMP, M_NOWAIT); 			if (n == NULL) { 				error = ENOMEM; 				goto bad; 			} 			bcopy((char *)brle, (char *)n, 			    sizeof(struct resource_list_entry)); 			SLIST_INSERT_HEAD(&brl_rev, n, link); 		}  		SLIST_FOREACH(brle,&brl_rev, link) {
else|#
directive|else
argument|STAILQ_FOREACH(brle, brl, link) {
endif|#
directive|endif
argument|switch (brle->type) { 			case SYS_RES_IOPORT: 				prd->cprd_type = CmResourceTypePort; 				prd->cprd_flags = CM_RESOURCE_PORT_IO; 				prd->cprd_sharedisp = 				    CmResourceShareDeviceExclusive; 				prd->u.cprd_port.cprd_start.np_quad = 				    brle->start; 				prd->u.cprd_port.cprd_len = brle->count; 				break; 			case SYS_RES_MEMORY: 				prd->cprd_type = CmResourceTypeMemory; 				prd->cprd_flags = 				    CM_RESOURCE_MEMORY_READ_WRITE; 				prd->cprd_sharedisp = 				    CmResourceShareDeviceExclusive; 				prd->u.cprd_port.cprd_start.np_quad = 				    brle->start; 				prd->u.cprd_port.cprd_len = brle->count; 				break; 			case SYS_RES_IRQ: 				prd->cprd_type = CmResourceTypeInterrupt; 				prd->cprd_flags =
literal|0
argument|;
comment|/* 				 * Always mark interrupt resources as 				 * shared, since in our implementation, 				 * they will be. 				 */
argument|prd->cprd_sharedisp = 				    CmResourceShareShared; 				prd->u.cprd_intr.cprd_level = brle->start; 				prd->u.cprd_intr.cprd_vector = brle->start; 				prd->u.cprd_intr.cprd_affinity =
literal|0
argument|; 				break; 			default: 				break; 			} 			prd++; 		} 	}  	block->nmb_rlist = rl;
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|600022
argument|bad:  	while (!SLIST_EMPTY(&brl_rev)) { 		n = SLIST_FIRST(&brl_rev); 		SLIST_REMOVE_HEAD(&brl_rev, link); 		free (n, M_TEMP); 	}
endif|#
directive|endif
argument|return(error); }
comment|/*  * Map an NDIS packet to an mbuf list. When an NDIS driver receives a  * packet, it will hand it to us in the form of an ndis_packet,  * which we need to convert to an mbuf that is then handed off  * to the stack. Note: we configure the mbuf list so that it uses  * the memory regions specified by the ndis_buffer structures in  * the ndis_packet as external storage. In most cases, this will  * point to a memory region allocated by the driver (either by  * ndis_malloc_withtag() or ndis_alloc_sharedmem()). We expect  * the driver to handle free()ing this region for is, so we set up  * a dummy no-op free handler for it.  */
argument|int ndis_ptom(m0, p) 	struct mbuf		**m0; 	ndis_packet		*p; { 	struct mbuf		*m = NULL
argument_list|,
argument|*prev = NULL; 	ndis_buffer		*buf; 	ndis_packet_private	*priv; 	uint32_t		totlen =
literal|0
argument|; 	struct ifnet		*ifp; 	struct ether_header	*eh; 	int			diff;  	if (p == NULL || m0 == NULL) 		return(EINVAL);  	priv =&p->np_private; 	buf = priv->npp_head; 	p->np_refcnt =
literal|0
argument|;  	for (buf = priv->npp_head; buf != NULL; buf = buf->mdl_next) { 		if (buf == priv->npp_head)
ifdef|#
directive|ifdef
name|MT_HEADER
argument|MGETHDR(m, M_DONTWAIT, MT_HEADER);
else|#
directive|else
argument|MGETHDR(m, M_DONTWAIT, MT_DATA);
endif|#
directive|endif
argument|else 			MGET(m, M_DONTWAIT, MT_DATA); 		if (m == NULL) { 			m_freem(*m0); 			*m0 = NULL; 			return(ENOBUFS); 		} 		m->m_len = MmGetMdlByteCount(buf); 		m->m_data = MmGetMdlVirtualAddress(buf); 		MEXTADD(m, m->m_data, m->m_len, ndis_return_packet, 		    p,
literal|0
argument|, EXT_NDIS); 		p->np_refcnt++;  		totlen += m->m_len; 		if (m->m_flags& M_PKTHDR) 			*m0 = m; 		else 			prev->m_next = m; 		prev = m; 	}
comment|/* 	 * This is a hack to deal with the Marvell 8335 driver 	 * which, when associated with an AP in WPA-PSK mode, 	 * seems to overpad its frames by 8 bytes. I don't know 	 * that the extra 8 bytes are for, and they're not there 	 * in open mode, so for now clamp the frame size at 1514 	 * until I can figure out how to deal with this properly, 	 * otherwise if_ethersubr() will spank us by discarding 	 * the 'oversize' frames. 	 */
argument|eh = mtod((*m0), struct ether_header *); 	ifp = ((struct ndis_softc *)p->np_softc)->ifp; 	if (totlen> ETHER_MAX_FRAME(ifp, eh->ether_type, FALSE)) { 		diff = totlen - ETHER_MAX_FRAME(ifp, eh->ether_type, FALSE); 		totlen -= diff; 		m->m_len -= diff; 	} 	(*m0)->m_pkthdr.len = totlen;  	return(
literal|0
argument|); }
comment|/*  * Create an NDIS packet from an mbuf chain.  * This is used mainly when transmitting packets, where we need  * to turn an mbuf off an interface's send queue and transform it  * into an NDIS packet which will be fed into the NDIS driver's  * send routine.  *  * NDIS packets consist of two parts: an ndis_packet structure,  * which is vaguely analagous to the pkthdr portion of an mbuf,  * and one or more ndis_buffer structures, which define the  * actual memory segments in which the packet data resides.  * We need to allocate one ndis_buffer for each mbuf in a chain,  * plus one ndis_packet as the header.  */
argument|int ndis_mtop(m0, p) 	struct mbuf		*m0; 	ndis_packet		**p; { 	struct mbuf		*m; 	ndis_buffer		*buf = NULL
argument_list|,
argument|*prev = NULL; 	ndis_packet_private	*priv;  	if (p == NULL || *p == NULL || m0 == NULL) 		return(EINVAL);  	priv =&(*p)->np_private; 	priv->npp_totlen = m0->m_pkthdr.len;  	for (m = m0; m != NULL; m = m->m_next) { 		if (m->m_len ==
literal|0
argument|) 			continue; 		buf = IoAllocateMdl(m->m_data, m->m_len, FALSE, FALSE, NULL); 		if (buf == NULL) { 			ndis_free_packet(*p); 			*p = NULL; 			return(ENOMEM); 		} 		MmBuildMdlForNonPagedPool(buf);  		if (priv->npp_head == NULL) 			priv->npp_head = buf; 		else 			prev->mdl_next = buf; 		prev = buf; 	}  	priv->npp_tail = buf;  	return(
literal|0
argument|); }  int ndis_get_supported_oids(arg, oids, oidcnt) 	void			*arg; 	ndis_oid		**oids; 	int			*oidcnt; { 	int			len
argument_list|,
argument|rval; 	ndis_oid		*o;  	if (arg == NULL || oids == NULL || oidcnt == NULL) 		return(EINVAL); 	len =
literal|0
argument|; 	ndis_get_info(arg, OID_GEN_SUPPORTED_LIST, NULL,&len);  	o = malloc(len, M_DEVBUF, M_NOWAIT); 	if (o == NULL) 		return(ENOMEM);  	rval = ndis_get_info(arg, OID_GEN_SUPPORTED_LIST, o,&len);  	if (rval) { 		free(o, M_DEVBUF); 		return(rval); 	}  	*oids = o; 	*oidcnt = len /
literal|4
argument|;  	return(
literal|0
argument|); }  int ndis_set_info(arg, oid, buf, buflen) 	void			*arg; 	ndis_oid		oid; 	void			*buf; 	int			*buflen; { 	struct ndis_softc	*sc; 	ndis_status		rval; 	ndis_handle		adapter; 	ndis_setinfo_handler	setfunc; 	uint32_t		byteswritten =
literal|0
argument_list|,
argument|bytesneeded =
literal|0
argument|; 	uint8_t			irql; 	uint64_t		duetime;
comment|/* 	 * According to the NDIS spec, MiniportQueryInformation() 	 * and MiniportSetInformation() requests are handled serially: 	 * once one request has been issued, we must wait for it to  	 * finish before allowing another request to proceed. 	 */
argument|sc = arg;  	KeAcquireSpinLock(&sc->ndis_block->nmb_lock,&irql);  	if (sc->ndis_block->nmb_pendingreq != NULL) { 		KeReleaseSpinLock(&sc->ndis_block->nmb_lock, irql); 		panic(
literal|"ndis_set_info() called while other request pending"
argument|); 	} else 		sc->ndis_block->nmb_pendingreq = (ndis_request *)sc;  	setfunc = sc->ndis_chars->nmc_setinfo_func; 	adapter = sc->ndis_block->nmb_miniportadapterctx;  	if (adapter == NULL || setfunc == NULL || 	    sc->ndis_block->nmb_devicectx == NULL) { 		sc->ndis_block->nmb_pendingreq = NULL; 		KeReleaseSpinLock(&sc->ndis_block->nmb_lock, irql); 		return(ENXIO); 	}  	rval = MSCALL6(setfunc, adapter, oid, buf, *buflen,&byteswritten,&bytesneeded);  	sc->ndis_block->nmb_pendingreq = NULL;  	KeReleaseSpinLock(&sc->ndis_block->nmb_lock, irql);  	if (rval == NDIS_STATUS_PENDING) {
comment|/* Wait up to 5 seconds. */
argument|duetime = (
literal|5
argument|*
literal|1000000
argument|) * -
literal|10
argument|; 		KeResetEvent(&sc->ndis_block->nmb_setevent); 		KeWaitForSingleObject(&sc->ndis_block->nmb_setevent,
literal|0
argument|,
literal|0
argument|, FALSE,&duetime); 		rval = sc->ndis_block->nmb_setstat; 	}  	if (byteswritten) 		*buflen = byteswritten; 	if (bytesneeded) 		*buflen = bytesneeded;  	if (rval == NDIS_STATUS_INVALID_LENGTH) 		return(ENOSPC);  	if (rval == NDIS_STATUS_INVALID_OID) 		return(EINVAL);  	if (rval == NDIS_STATUS_NOT_SUPPORTED || 	    rval == NDIS_STATUS_NOT_ACCEPTED) 		return(ENOTSUP);  	if (rval != NDIS_STATUS_SUCCESS) 		return(ENODEV);  	return(
literal|0
argument|); }  typedef void (*ndis_senddone_func)(ndis_handle, ndis_packet *, ndis_status);  int ndis_send_packets(arg, packets, cnt) 	void			*arg; 	ndis_packet		**packets; 	int			cnt; { 	struct ndis_softc	*sc; 	ndis_handle		adapter; 	ndis_sendmulti_handler	sendfunc; 	ndis_senddone_func		senddonefunc; 	int			i; 	ndis_packet		*p; 	uint8_t			irql;  	sc = arg; 	adapter = sc->ndis_block->nmb_miniportadapterctx; 	if (adapter == NULL) 		return(ENXIO); 	sendfunc = sc->ndis_chars->nmc_sendmulti_func; 	senddonefunc = sc->ndis_block->nmb_senddone_func;  	if (NDIS_SERIALIZED(sc->ndis_block)) 		KeAcquireSpinLock(&sc->ndis_block->nmb_lock,&irql);  	MSCALL3(sendfunc, adapter, packets, cnt);  	for (i =
literal|0
argument|; i< cnt; i++) { 		p = packets[i];
comment|/* 		 * Either the driver already handed the packet to 		 * ndis_txeof() due to a failure, or it wants to keep 		 * it and release it asynchronously later. Skip to the 		 * next one. 		 */
argument|if (p == NULL || p->np_oob.npo_status == NDIS_STATUS_PENDING) 			continue; 		MSCALL3(senddonefunc, sc->ndis_block, p, p->np_oob.npo_status); 	}  	if (NDIS_SERIALIZED(sc->ndis_block)) 		KeReleaseSpinLock(&sc->ndis_block->nmb_lock, irql);  	return(
literal|0
argument|); }  int ndis_send_packet(arg, packet) 	void			*arg; 	ndis_packet		*packet; { 	struct ndis_softc	*sc; 	ndis_handle		adapter; 	ndis_status		status; 	ndis_sendsingle_handler	sendfunc; 	ndis_senddone_func		senddonefunc; 	uint8_t			irql;  	sc = arg; 	adapter = sc->ndis_block->nmb_miniportadapterctx; 	if (adapter == NULL) 		return(ENXIO); 	sendfunc = sc->ndis_chars->nmc_sendsingle_func; 	senddonefunc = sc->ndis_block->nmb_senddone_func;  	if (NDIS_SERIALIZED(sc->ndis_block)) 		KeAcquireSpinLock(&sc->ndis_block->nmb_lock,&irql); 	status = MSCALL3(sendfunc, adapter, packet, 	    packet->np_private.npp_flags);  	if (status == NDIS_STATUS_PENDING) { 		if (NDIS_SERIALIZED(sc->ndis_block)) 			KeReleaseSpinLock(&sc->ndis_block->nmb_lock, irql); 		return(
literal|0
argument|); 	}  	MSCALL3(senddonefunc, sc->ndis_block, packet, status);  	if (NDIS_SERIALIZED(sc->ndis_block)) 		KeReleaseSpinLock(&sc->ndis_block->nmb_lock, irql);  	return(
literal|0
argument|); }  int ndis_init_dma(arg) 	void			*arg; { 	struct ndis_softc	*sc; 	int			i
argument_list|,
argument|error;  	sc = arg;  	sc->ndis_tmaps = malloc(sizeof(bus_dmamap_t) * sc->ndis_maxpkts, 	    M_DEVBUF, M_NOWAIT|M_ZERO);  	if (sc->ndis_tmaps == NULL) 		return(ENOMEM);  	for (i =
literal|0
argument|; i< sc->ndis_maxpkts; i++) { 		error = bus_dmamap_create(sc->ndis_ttag,
literal|0
argument|,&sc->ndis_tmaps[i]); 		if (error) { 			free(sc->ndis_tmaps, M_DEVBUF); 			return(ENODEV); 		} 	}  	return(
literal|0
argument|); }  int ndis_destroy_dma(arg) 	void			*arg; { 	struct ndis_softc	*sc; 	struct mbuf		*m; 	ndis_packet		*p = NULL; 	int			i;  	sc = arg;  	for (i =
literal|0
argument|; i< sc->ndis_maxpkts; i++) { 		if (sc->ndis_txarray[i] != NULL) { 			p = sc->ndis_txarray[i]; 			m = (struct mbuf *)p->np_rsvd[
literal|1
argument|]; 			if (m != NULL) 				m_freem(m); 			ndis_free_packet(sc->ndis_txarray[i]); 		} 		bus_dmamap_destroy(sc->ndis_ttag, sc->ndis_tmaps[i]); 	}  	free(sc->ndis_tmaps, M_DEVBUF);  	bus_dma_tag_destroy(sc->ndis_ttag);  	return(
literal|0
argument|); }  int ndis_reset_nic(arg) 	void			*arg; { 	struct ndis_softc	*sc; 	ndis_handle		adapter; 	ndis_reset_handler	resetfunc; 	uint8_t			addressing_reset; 	int			rval; 	uint8_t			irql;  	sc = arg;  	NDIS_LOCK(sc); 	adapter = sc->ndis_block->nmb_miniportadapterctx; 	resetfunc = sc->ndis_chars->nmc_reset_func;  	if (adapter == NULL || resetfunc == NULL || 	    sc->ndis_block->nmb_devicectx == NULL) { 		NDIS_UNLOCK(sc); 		return(EIO); 	}  	NDIS_UNLOCK(sc);  	if (NDIS_SERIALIZED(sc->ndis_block)) 		KeAcquireSpinLock(&sc->ndis_block->nmb_lock,&irql);  	rval = MSCALL2(resetfunc,&addressing_reset, adapter);  	if (NDIS_SERIALIZED(sc->ndis_block)) 		KeReleaseSpinLock(&sc->ndis_block->nmb_lock, irql);  	if (rval == NDIS_STATUS_PENDING) { 		KeResetEvent(&sc->ndis_block->nmb_resetevent); 		KeWaitForSingleObject(&sc->ndis_block->nmb_resetevent,
literal|0
argument|,
literal|0
argument|, FALSE, NULL); 	}  	return(
literal|0
argument|); }  int ndis_halt_nic(arg) 	void			*arg; { 	struct ndis_softc	*sc; 	ndis_handle		adapter; 	ndis_halt_handler	haltfunc; 	ndis_miniport_block	*block; 	int			empty =
literal|0
argument|; 	uint8_t			irql;  	sc = arg; 	block = sc->ndis_block;  	if (!cold) 		KeFlushQueuedDpcs();
comment|/* 	 * Wait for all packets to be returned. 	 */
argument|while (
literal|1
argument|) { 		KeAcquireSpinLock(&block->nmb_returnlock,&irql); 		empty = IsListEmpty(&block->nmb_returnlist); 		KeReleaseSpinLock(&block->nmb_returnlock, irql); 		if (empty) 			break; 		NdisMSleep(
literal|1000
argument|); 	}  	NDIS_LOCK(sc); 	adapter = sc->ndis_block->nmb_miniportadapterctx; 	if (adapter == NULL) { 		NDIS_UNLOCK(sc); 		return(EIO); 	}  	sc->ndis_block->nmb_devicectx = NULL;
comment|/* 	 * The adapter context is only valid after the init 	 * handler has been called, and is invalid once the 	 * halt handler has been called. 	 */
argument|haltfunc = sc->ndis_chars->nmc_halt_func; 	NDIS_UNLOCK(sc);  	MSCALL1(haltfunc, adapter);  	NDIS_LOCK(sc); 	sc->ndis_block->nmb_miniportadapterctx = NULL; 	NDIS_UNLOCK(sc);  	return(
literal|0
argument|); }  int ndis_shutdown_nic(arg) 	void			*arg; { 	struct ndis_softc	*sc; 	ndis_handle		adapter; 	ndis_shutdown_handler	shutdownfunc;  	sc = arg; 	NDIS_LOCK(sc); 	adapter = sc->ndis_block->nmb_miniportadapterctx; 	shutdownfunc = sc->ndis_chars->nmc_shutdown_handler; 	NDIS_UNLOCK(sc); 	if (adapter == NULL || shutdownfunc == NULL) 		return(EIO);  	if (sc->ndis_chars->nmc_rsvd0 == NULL) 		MSCALL1(shutdownfunc, adapter); 	else 		MSCALL1(shutdownfunc, sc->ndis_chars->nmc_rsvd0);  	TAILQ_REMOVE(&ndis_devhead, sc->ndis_block, link);  	return(
literal|0
argument|); }  int ndis_init_nic(arg) 	void			*arg; { 	struct ndis_softc	*sc; 	ndis_miniport_block	*block;         ndis_init_handler	initfunc; 	ndis_status		status
argument_list|,
argument|openstatus =
literal|0
argument|; 	ndis_medium		mediumarray[NdisMediumMax]; 	uint32_t		chosenmedium
argument_list|,
argument|i;  	if (arg == NULL) 		return(EINVAL);  	sc = arg; 	NDIS_LOCK(sc); 	block = sc->ndis_block; 	initfunc = sc->ndis_chars->nmc_init_func; 	NDIS_UNLOCK(sc);  	sc->ndis_block->nmb_timerlist = NULL;  	for (i =
literal|0
argument|; i< NdisMediumMax; i++) 		mediumarray[i] = i;          status = MSCALL6(initfunc,&openstatus,&chosenmedium,             mediumarray, NdisMediumMax, block, block);
comment|/* 	 * If the init fails, blow away the other exported routines 	 * we obtained from the driver so we can't call them later. 	 * If the init failed, none of these will work. 	 */
argument|if (status != NDIS_STATUS_SUCCESS) { 		NDIS_LOCK(sc); 		sc->ndis_block->nmb_miniportadapterctx = NULL; 		NDIS_UNLOCK(sc); 		return(ENXIO); 	}
comment|/* 	 * This may look really goofy, but apparently it is possible 	 * to halt a miniport too soon after it's been initialized. 	 * After MiniportInitialize() finishes, pause for 1 second 	 * to give the chip a chance to handle any short-lived timers 	 * that were set in motion. If we call MiniportHalt() too soon, 	 * some of the timers may not be cancelled, because the driver 	 * expects them to fire before the halt is called. 	 */
argument|tsleep(curthread->td_proc, PWAIT,
literal|"ndwait"
argument|, hz);  	NDIS_LOCK(sc); 	sc->ndis_block->nmb_devicectx = sc; 	NDIS_UNLOCK(sc);  	return(
literal|0
argument|); }  static void ndis_intrsetup(dpc, dobj, ip, sc) 	kdpc			*dpc; 	device_object		*dobj; 	irp			*ip; 	struct ndis_softc	*sc; { 	ndis_miniport_interrupt	*intr;  	intr = sc->ndis_block->nmb_interrupt;
comment|/* Sanity check. */
argument|if (intr == NULL) 		return;  	KeAcquireSpinLockAtDpcLevel(&intr->ni_dpccountlock); 	KeResetEvent(&intr->ni_dpcevt); 	if (KeInsertQueueDpc(&intr->ni_dpc, NULL, NULL) == TRUE) 		intr->ni_dpccnt++; 	KeReleaseSpinLockFromDpcLevel(&intr->ni_dpccountlock);  	return; }  int ndis_get_info(arg, oid, buf, buflen) 	void			*arg; 	ndis_oid		oid; 	void			*buf; 	int			*buflen; { 	struct ndis_softc	*sc; 	ndis_status		rval; 	ndis_handle		adapter; 	ndis_queryinfo_handler	queryfunc; 	uint32_t		byteswritten =
literal|0
argument_list|,
argument|bytesneeded =
literal|0
argument|; 	uint8_t			irql; 	uint64_t		duetime;  	sc = arg;  	KeAcquireSpinLock(&sc->ndis_block->nmb_lock,&irql);  	if (sc->ndis_block->nmb_pendingreq != NULL) { 		KeReleaseSpinLock(&sc->ndis_block->nmb_lock, irql); 		panic(
literal|"ndis_get_info() called while other request pending"
argument|); 	} else 		sc->ndis_block->nmb_pendingreq = (ndis_request *)sc;  	queryfunc = sc->ndis_chars->nmc_queryinfo_func; 	adapter = sc->ndis_block->nmb_miniportadapterctx;  	if (adapter == NULL || queryfunc == NULL || 	    sc->ndis_block->nmb_devicectx == NULL) { 		sc->ndis_block->nmb_pendingreq = NULL; 		KeReleaseSpinLock(&sc->ndis_block->nmb_lock, irql); 		return(ENXIO); 	}  	rval = MSCALL6(queryfunc, adapter, oid, buf, *buflen,&byteswritten,&bytesneeded);  	sc->ndis_block->nmb_pendingreq = NULL;  	KeReleaseSpinLock(&sc->ndis_block->nmb_lock, irql);
comment|/* Wait for requests that block. */
argument|if (rval == NDIS_STATUS_PENDING) {
comment|/* Wait up to 5 seconds. */
argument|duetime = (
literal|5
argument|*
literal|1000000
argument|) * -
literal|10
argument|; 		KeResetEvent(&sc->ndis_block->nmb_getevent); 		KeWaitForSingleObject(&sc->ndis_block->nmb_getevent,
literal|0
argument|,
literal|0
argument|, FALSE,&duetime); 		rval = sc->ndis_block->nmb_getstat; 	}  	if (byteswritten) 		*buflen = byteswritten; 	if (bytesneeded) 		*buflen = bytesneeded;  	if (rval == NDIS_STATUS_INVALID_LENGTH || 	    rval == NDIS_STATUS_BUFFER_TOO_SHORT) 		return(ENOSPC);  	if (rval == NDIS_STATUS_INVALID_OID) 		return(EINVAL);  	if (rval == NDIS_STATUS_NOT_SUPPORTED || 	    rval == NDIS_STATUS_NOT_ACCEPTED) 		return(ENOTSUP);  	if (rval != NDIS_STATUS_SUCCESS) 		return(ENODEV);  	return(
literal|0
argument|); }  uint32_t NdisAddDevice(drv, pdo) 	driver_object		*drv; 	device_object		*pdo; { 	device_object		*fdo; 	ndis_miniport_block	*block; 	struct ndis_softc	*sc; 	uint32_t		status; 	int			error;  	sc = device_get_softc(pdo->do_devext);          if (sc->ndis_iftype == PCMCIABus || sc->ndis_iftype == PCIBus) { 		error = bus_setup_intr(sc->ndis_dev, sc->ndis_irq, 		    INTR_TYPE_NET | INTR_MPSAFE, 		    ntoskrnl_intr, NULL,&sc->ndis_intrhand); 		if (error) 			return(NDIS_STATUS_FAILURE); 	}  	status = IoCreateDevice(drv, sizeof(ndis_miniport_block), NULL, 	    FILE_DEVICE_UNKNOWN,
literal|0
argument|, FALSE,&fdo);  	if (status != STATUS_SUCCESS) 		return(status);  	block = fdo->do_devext;  	block->nmb_filterdbs.nf_ethdb = block; 	block->nmb_deviceobj = fdo; 	block->nmb_physdeviceobj = pdo; 	block->nmb_nextdeviceobj = IoAttachDeviceToDeviceStack(fdo, pdo); 	KeInitializeSpinLock(&block->nmb_lock); 	KeInitializeSpinLock(&block->nmb_returnlock); 	KeInitializeEvent(&block->nmb_getevent, EVENT_TYPE_NOTIFY, TRUE); 	KeInitializeEvent(&block->nmb_setevent, EVENT_TYPE_NOTIFY, TRUE); 	KeInitializeEvent(&block->nmb_resetevent, EVENT_TYPE_NOTIFY, TRUE); 	InitializeListHead(&block->nmb_parmlist); 	InitializeListHead(&block->nmb_returnlist); 	block->nmb_returnitem = IoAllocateWorkItem(fdo);
comment|/* 	 * Stash pointers to the miniport block and miniport 	 * characteristics info in the if_ndis softc so the 	 * UNIX wrapper driver can get to them later.          */
argument|sc->ndis_block = block; 	sc->ndis_chars = IoGetDriverObjectExtension(drv, (void *)
literal|1
argument|);
comment|/* 	 * If the driver has a MiniportTransferData() function, 	 * we should allocate a private RX packet pool. 	 */
argument|if (sc->ndis_chars->nmc_transferdata_func != NULL) { 		NdisAllocatePacketPool(&status,&block->nmb_rxpool,
literal|32
argument|, PROTOCOL_RESERVED_SIZE_IN_PACKET); 		if (status != NDIS_STATUS_SUCCESS) { 			IoDetachDevice(block->nmb_nextdeviceobj); 			IoDeleteDevice(fdo); 			return(status); 		} 		InitializeListHead((&block->nmb_packetlist)); 	}
comment|/* Give interrupt handling priority over timers. */
argument|IoInitializeDpcRequest(fdo, kernndis_functbl[
literal|6
argument|].ipt_wrap); 	KeSetImportanceDpc(&fdo->do_dpc, KDPC_IMPORTANCE_HIGH);
comment|/* Finish up BSD-specific setup. */
argument|block->nmb_signature = (void *)
literal|0xcafebabe
argument|; 	block->nmb_status_func = kernndis_functbl[
literal|0
argument|].ipt_wrap; 	block->nmb_statusdone_func = kernndis_functbl[
literal|1
argument|].ipt_wrap; 	block->nmb_setdone_func = kernndis_functbl[
literal|2
argument|].ipt_wrap; 	block->nmb_querydone_func = kernndis_functbl[
literal|3
argument|].ipt_wrap; 	block->nmb_resetdone_func = kernndis_functbl[
literal|4
argument|].ipt_wrap; 	block->nmb_sendrsrc_func = kernndis_functbl[
literal|5
argument|].ipt_wrap; 	block->nmb_pendingreq = NULL;  	TAILQ_INSERT_TAIL(&ndis_devhead, block, link);  	return (STATUS_SUCCESS); }  int ndis_unload_driver(arg) 	void			*arg; { 	struct ndis_softc	*sc; 	device_object		*fdo;  	sc = arg;  	if (sc->ndis_intrhand) 		bus_teardown_intr(sc->ndis_dev, 		    sc->ndis_irq, sc->ndis_intrhand);  	if (sc->ndis_block->nmb_rlist != NULL) 		free(sc->ndis_block->nmb_rlist, M_DEVBUF);  	ndis_flush_sysctls(sc);  	TAILQ_REMOVE(&ndis_devhead, sc->ndis_block, link);  	if (sc->ndis_chars->nmc_transferdata_func != NULL) 		NdisFreePacketPool(sc->ndis_block->nmb_rxpool); 	fdo = sc->ndis_block->nmb_deviceobj; 	IoFreeWorkItem(sc->ndis_block->nmb_returnitem); 	IoDetachDevice(sc->ndis_block->nmb_nextdeviceobj); 	IoDeleteDevice(fdo);  	return(
literal|0
argument|); }
end_function

end_unit

