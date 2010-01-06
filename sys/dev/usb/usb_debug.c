begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
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
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbdi.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_core.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_debug.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_process.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_device.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_busdma.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_transfer.h>
end_include

begin_include
include|#
directive|include
file|<ddb/ddb.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_sym.h>
end_include

begin_comment
comment|/*  * Define this unconditionally in case a kernel module is loaded that  * has been compiled with debugging options.  */
end_comment

begin_decl_stmt
name|int
name|usb_debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|usb
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"USB debugging"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_usb
argument_list|,
name|OID_AUTO
argument_list|,
name|debug
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|usb_debug
argument_list|,
literal|0
argument_list|,
literal|"Debug level"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.usb.debug"
argument_list|,
operator|&
name|usb_debug
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*------------------------------------------------------------------------*  *	usb_dump_iface  *  * This function dumps information about an USB interface.  *------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|usb_dump_iface
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|iface
parameter_list|)
block|{
name|printf
argument_list|(
literal|"usb_dump_iface: iface=%p\n"
argument_list|,
name|iface
argument_list|)
expr_stmt|;
if|if
condition|(
name|iface
operator|==
name|NULL
condition|)
block|{
return|return;
block|}
name|printf
argument_list|(
literal|" iface=%p idesc=%p altindex=%d\n"
argument_list|,
name|iface
argument_list|,
name|iface
operator|->
name|idesc
argument_list|,
name|iface
operator|->
name|alt_index
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*------------------------------------------------------------------------*  *	usb_dump_device  *  * This function dumps information about an USB device.  *------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|usb_dump_device
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
block|{
name|printf
argument_list|(
literal|"usb_dump_device: dev=%p\n"
argument_list|,
name|udev
argument_list|)
expr_stmt|;
if|if
condition|(
name|udev
operator|==
name|NULL
condition|)
block|{
return|return;
block|}
name|printf
argument_list|(
literal|" bus=%p \n"
literal|" address=%d config=%d depth=%d speed=%d self_powered=%d\n"
literal|" power=%d langid=%d\n"
argument_list|,
name|udev
operator|->
name|bus
argument_list|,
name|udev
operator|->
name|address
argument_list|,
name|udev
operator|->
name|curr_config_no
argument_list|,
name|udev
operator|->
name|depth
argument_list|,
name|udev
operator|->
name|speed
argument_list|,
name|udev
operator|->
name|flags
operator|.
name|self_powered
argument_list|,
name|udev
operator|->
name|power
argument_list|,
name|udev
operator|->
name|langid
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*------------------------------------------------------------------------*  *	usb_dump_queue  *  * This function dumps the USB transfer that are queued up on an USB endpoint.  *------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|usb_dump_queue
parameter_list|(
name|struct
name|usb_endpoint
modifier|*
name|ep
parameter_list|)
block|{
name|struct
name|usb_xfer
modifier|*
name|xfer
decl_stmt|;
name|printf
argument_list|(
literal|"usb_dump_queue: endpoint=%p xfer: "
argument_list|,
name|ep
argument_list|)
expr_stmt|;
name|TAILQ_FOREACH
argument_list|(
argument|xfer
argument_list|,
argument|&ep->endpoint_q.head
argument_list|,
argument|wait_entry
argument_list|)
block|{
name|printf
argument_list|(
literal|" %p"
argument_list|,
name|xfer
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*------------------------------------------------------------------------*  *	usb_dump_endpoint  *  * This function dumps information about an USB endpoint.  *------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|usb_dump_endpoint
parameter_list|(
name|struct
name|usb_endpoint
modifier|*
name|ep
parameter_list|)
block|{
if|if
condition|(
name|ep
condition|)
block|{
name|printf
argument_list|(
literal|"usb_dump_endpoint: endpoint=%p"
argument_list|,
name|ep
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" edesc=%p isoc_next=%d toggle_next=%d"
argument_list|,
name|ep
operator|->
name|edesc
argument_list|,
name|ep
operator|->
name|isoc_next
argument_list|,
name|ep
operator|->
name|toggle_next
argument_list|)
expr_stmt|;
if|if
condition|(
name|ep
operator|->
name|edesc
condition|)
block|{
name|printf
argument_list|(
literal|" bEndpointAddress=0x%02x"
argument_list|,
name|ep
operator|->
name|edesc
operator|->
name|bEndpointAddress
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|usb_dump_queue
argument_list|(
name|ep
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"usb_dump_endpoint: endpoint=NULL\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*------------------------------------------------------------------------*  *	usb_dump_xfer  *  * This function dumps information about an USB transfer.  *------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|usb_dump_xfer
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
block|{
name|struct
name|usb_device
modifier|*
name|udev
decl_stmt|;
name|printf
argument_list|(
literal|"usb_dump_xfer: xfer=%p\n"
argument_list|,
name|xfer
argument_list|)
expr_stmt|;
if|if
condition|(
name|xfer
operator|==
name|NULL
condition|)
block|{
return|return;
block|}
if|if
condition|(
name|xfer
operator|->
name|endpoint
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"xfer %p: endpoint=NULL\n"
argument_list|,
name|xfer
argument_list|)
expr_stmt|;
return|return;
block|}
name|udev
operator|=
name|xfer
operator|->
name|xroot
operator|->
name|udev
expr_stmt|;
name|printf
argument_list|(
literal|"xfer %p: udev=%p vid=0x%04x pid=0x%04x addr=%d "
literal|"endpoint=%p ep=0x%02x attr=0x%02x\n"
argument_list|,
name|xfer
argument_list|,
name|udev
argument_list|,
name|UGETW
argument_list|(
name|udev
operator|->
name|ddesc
operator|.
name|idVendor
argument_list|)
argument_list|,
name|UGETW
argument_list|(
name|udev
operator|->
name|ddesc
operator|.
name|idProduct
argument_list|)
argument_list|,
name|udev
operator|->
name|address
argument_list|,
name|xfer
operator|->
name|endpoint
argument_list|,
name|xfer
operator|->
name|endpoint
operator|->
name|edesc
operator|->
name|bEndpointAddress
argument_list|,
name|xfer
operator|->
name|endpoint
operator|->
name|edesc
operator|->
name|bmAttributes
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

