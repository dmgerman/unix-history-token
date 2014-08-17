begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PLATFORM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PLATFORM_H_
end_define

begin_comment
comment|/*  * Initialization functions called by the common initarm() function in  * arm/machdep.c (but not necessarily from the custom initarm() functions of  * older code).  *  *  - platform_probe_and_attach() is called very early, after parsing the boot  *    params and after physical memory has been located and sized.  *  *  - platform_devmap_init() is called as one of the last steps of early virtual  *    memory initialization, shortly before the new page tables are installed.  *  *  - platform_lastaddr() is called after platform_devmap_init(), and must return  *    the address of the first byte of unusable KVA space.  This allows a  *    platform to carve out of the top of the KVA space whatever reserves it  *    needs for things like static device mapping, and this is called to get the  *    value before calling pmap_bootstrap() which uses the value to size the  *    available KVA.  *  *  - platform_gpio_init() is called after the static device mappings are  *    established and just before cninit().  The intention is that the routine  *    can do any hardware setup (such as gpio or pinmux) necessary to make the  *    console functional.  *  *  - platform_late_init() is called just after cninit().  This is the first of  *    the init routines that can use printf() and expect the output to appear on  *    a standard console.  *  */
end_comment

begin_function_decl
name|void
name|platform_probe_and_attach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|platform_devmap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|platform_lastaddr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_gpio_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_late_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PLATFORM_H_ */
end_comment

end_unit

