begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<dev/rr232x/rr232x_config.h>
end_include

begin_comment
comment|/* $Id: himfuncs.h,v 1.14 2005/12/22 00:13:11 gmm Exp $  * Copyright (C) 2004-2005 HighPoint Technologies, Inc. All rights reserved.  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * define _HIM_INTERFACE before include this file, and  * undef it after include this file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HIM_INTERFACE
end_ifndef

begin_error
error|#
directive|error
literal|"you must define _HIM_INTERFACE before this file"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_BOOL
argument_list|,
argument|get_supported_device_id
argument_list|,
argument|(int index, PCI_ID *id)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_U8
argument_list|,
argument|get_controller_count
argument_list|,
argument|(PCI_ID *id, HPT_U8 *reached)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_UINT
argument_list|,
argument|get_adapter_size
argument_list|,
argument|(const PCI_ID *id)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_BOOL
argument_list|,
argument|create_adapter
argument_list|,
argument|(const PCI_ID *id, PCI_ADDRESS pciAddress, void *adapter, void *osext)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|get_adapter_config
argument_list|,
argument|(void *adapter, HIM_ADAPTER_CONFIG *config)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_BOOL
argument_list|,
argument|get_meminfo
argument_list|,
argument|(void *adapter)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_BOOL
argument_list|,
argument|adapter_on_same_vbus
argument_list|,
argument|(void *adapter1, void *adapter2)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|route_irq
argument_list|,
argument|(void *adapter, HPT_BOOL enable)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_BOOL
argument_list|,
argument|initialize
argument_list|,
argument|(void *adapter)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_UINT
argument_list|,
argument|get_device_size
argument_list|,
argument|(void *adapter)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_BOOL
argument_list|,
argument|probe_device
argument_list|,
argument|(void *adapter, int index, void *devhandle, PROBE_CALLBACK done, void *arg)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void *
argument_list|,
argument|get_device
argument_list|,
argument|(void *adapter, int index)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|get_device_config
argument_list|,
argument|(void *dev, HIM_DEVICE_CONFIG *config)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|remove_device
argument_list|,
argument|(void *dev)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|reset_device
argument_list|,
argument|(void * dev, void (*done)(void *arg), void *arg)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_U32
argument_list|,
argument|get_cmdext_size
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|queue_cmd
argument_list|,
argument|(void *dev, struct _COMMAND *cmd)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|int
argument_list|,
argument|read_write
argument_list|,
argument|(void *dev,HPT_LBA lba, HPT_U16 nsector, HPT_U8 *buffer, HPT_BOOL read)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_BOOL
argument_list|,
argument|intr_handler
argument_list|,
argument|(void *adapter)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_BOOL
argument_list|,
argument|intr_control
argument_list|,
argument|(void * adapter, HPT_BOOL enable)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|int
argument_list|,
argument|get_channel_config
argument_list|,
argument|(void * adapter, int index, PHIM_CHANNEL_CONFIG pInfo)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|int
argument_list|,
argument|set_device_info
argument_list|,
argument|(void * dev, PHIM_ALTERABLE_DEV_INFO pInfo)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|unplug_device
argument_list|,
argument|(void * dev)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|shutdown
argument_list|,
argument|(void *adapter)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|suspend
argument_list|,
argument|(void *adapter)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|resume
argument_list|,
argument|(void *adapter)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|release_adapter
argument_list|,
argument|(void *adapter)
argument_list|)
end_macro

begin_comment
comment|/*called after ldm_register_adapter*/
end_comment

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_BOOL
argument_list|,
argument|verify_adapter
argument_list|,
argument|(void *adapter)
argument_list|)
end_macro

begin_comment
comment|/* (optional) */
end_comment

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|void
argument_list|,
argument|ioctl
argument_list|,
argument|(void * adapter, struct _IOCTL_ARG *arg)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|int
argument_list|,
argument|compare_slot_seq
argument_list|,
argument|(void *adapter1, void *adapter2)
argument_list|)
end_macro

begin_macro
name|_HIM_INTERFACE
argument_list|(
argument|HPT_BOOL
argument_list|,
argument|flash_access
argument_list|,
argument|(void *adapter, HPT_U32 offset, void *value, int size, HPT_BOOL reading)
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|_HIM_INTERFACE
end_undef

end_unit

