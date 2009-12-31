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
file|<dev/usb/usb_dynamic.h>
end_include

begin_comment
comment|/* function prototypes */
end_comment

begin_decl_stmt
specifier|static
name|usb_handle_req_t
name|usb_temp_get_desc_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|usb_temp_setup_by_index_t
name|usb_temp_setup_by_index_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|usb_temp_unsetup_t
name|usb_temp_unsetup_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|usb_test_quirk_t
name|usb_test_quirk_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|usb_quirk_ioctl_t
name|usb_quirk_ioctl_w
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global variables */
end_comment

begin_decl_stmt
name|usb_handle_req_t
modifier|*
name|usb_temp_get_desc_p
init|=
operator|&
name|usb_temp_get_desc_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usb_temp_setup_by_index_t
modifier|*
name|usb_temp_setup_by_index_p
init|=
operator|&
name|usb_temp_setup_by_index_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usb_temp_unsetup_t
modifier|*
name|usb_temp_unsetup_p
init|=
operator|&
name|usb_temp_unsetup_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usb_test_quirk_t
modifier|*
name|usb_test_quirk_p
init|=
operator|&
name|usb_test_quirk_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usb_quirk_ioctl_t
modifier|*
name|usb_quirk_ioctl_p
init|=
operator|&
name|usb_quirk_ioctl_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|devclass_t
name|usb_devclass_ptr
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|usb_error_t
name|usb_temp_setup_by_index_w
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint16_t
name|index
parameter_list|)
block|{
return|return
operator|(
name|USB_ERR_INVAL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|uint8_t
name|usb_test_quirk_w
parameter_list|(
specifier|const
name|struct
name|usbd_lookup_info
modifier|*
name|info
parameter_list|,
name|uint16_t
name|quirk
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
comment|/* no match */
block|}
end_function

begin_function
specifier|static
name|int
name|usb_quirk_ioctl_w
parameter_list|(
name|unsigned
name|long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
return|return
operator|(
name|ENOIOCTL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|usb_error_t
name|usb_temp_get_desc_w
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|struct
name|usb_device_request
modifier|*
name|req
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|pPtr
parameter_list|,
name|uint16_t
modifier|*
name|pLength
parameter_list|)
block|{
comment|/* stall */
return|return
operator|(
name|USB_ERR_STALLED
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|usb_temp_unsetup_w
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
block|{
if|if
condition|(
name|udev
operator|->
name|usb_template_ptr
condition|)
block|{
name|free
argument_list|(
name|udev
operator|->
name|usb_template_ptr
argument_list|,
name|M_USB
argument_list|)
expr_stmt|;
name|udev
operator|->
name|usb_template_ptr
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|usb_quirk_unload
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
comment|/* reset function pointers */
name|usb_test_quirk_p
operator|=
operator|&
name|usb_test_quirk_w
expr_stmt|;
name|usb_quirk_ioctl_p
operator|=
operator|&
name|usb_quirk_ioctl_w
expr_stmt|;
comment|/* wait for CPU to exit the loaded functions, if any */
comment|/* XXX this is a tradeoff */
name|pause
argument_list|(
literal|"WAIT"
argument_list|,
name|hz
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|usb_temp_unload
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
comment|/* reset function pointers */
name|usb_temp_get_desc_p
operator|=
operator|&
name|usb_temp_get_desc_w
expr_stmt|;
name|usb_temp_setup_by_index_p
operator|=
operator|&
name|usb_temp_setup_by_index_w
expr_stmt|;
name|usb_temp_unsetup_p
operator|=
operator|&
name|usb_temp_unsetup_w
expr_stmt|;
comment|/* wait for CPU to exit the loaded functions, if any */
comment|/* XXX this is a tradeoff */
name|pause
argument_list|(
literal|"WAIT"
argument_list|,
name|hz
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|usb_bus_unload
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
comment|/* reset function pointers */
name|usb_devclass_ptr
operator|=
name|NULL
expr_stmt|;
comment|/* wait for CPU to exit the loaded functions, if any */
comment|/* XXX this is a tradeoff */
name|pause
argument_list|(
literal|"WAIT"
argument_list|,
name|hz
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

