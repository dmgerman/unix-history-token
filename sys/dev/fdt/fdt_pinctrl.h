begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_FDT_PINCTRL_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_FDT_PINCTRL_H
end_define

begin_include
include|#
directive|include
file|"fdt_pinctrl_if.h"
end_include

begin_comment
comment|/*  * Configure pins by name or index.  This looks up the pinctrl-N property in  * client's fdt data by index or name, and passes each handle in it to the  * pinctrl driver for configuration.  */
end_comment

begin_function_decl
name|int
name|fdt_pinctrl_configure
parameter_list|(
name|device_t
name|client
parameter_list|,
name|u_int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_pinctrl_configure_by_name
parameter_list|(
name|device_t
name|client
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Register a pinctrl driver so that it can be used by other devices which call  * fdt_pinctrl_configure().  The pinprop argument is the name of a property that  * identifies each descendent of the pinctrl node which is a pin configuration  * node whose xref phandle can be passed to FDT_PINCTRL_CONFIGURE().  If this is  * NULL, every descendant node is registered.  */
end_comment

begin_function_decl
name|int
name|fdt_pinctrl_register
parameter_list|(
name|device_t
name|pinctrl
parameter_list|,
specifier|const
name|char
modifier|*
name|pinprop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Walk the device tree and configure pins for each enabled device whose  * pinctrl-0 property contains references to nodes which are children of the  * given pinctrl device.  This helper routine is for use by pinctrl drivers.  */
end_comment

begin_function_decl
name|int
name|fdt_pinctrl_configure_tree
parameter_list|(
name|device_t
name|pinctrl
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_FDT_PINCTRL_H */
end_comment

end_unit

