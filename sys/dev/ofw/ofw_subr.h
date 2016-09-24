begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_OFW_OFW_SUBR_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_OFW_OFW_SUBR_H_
end_define

begin_comment
comment|/*  * Translate an address from the Nth tuple of a device node's reg properties to  * a physical memory address, by applying the range mappings from all ancestors.  * This assumes that all ancestor ranges are simple numerical offsets for which  * addition and subtraction operations will perform the required mapping (the  * bit-options in the high word of standard PCI properties are also handled).  * After the call, *pci_hi (if non-NULL) contains the phys.hi cell of the  * device's parent PCI bus, or OFW_PADDR_NOT_PCI if no PCI bus is involved.  *  * This is intended to be a helper function called by the platform-specific  * implementation of OF_decode_addr(), and not for direct use by device drivers.  */
end_comment

begin_define
define|#
directive|define
name|OFW_PADDR_NOT_PCI
value|(~0)
end_define

begin_function_decl
name|int
name|ofw_reg_to_paddr
parameter_list|(
name|phandle_t
name|_dev
parameter_list|,
name|int
name|_regno
parameter_list|,
name|bus_addr_t
modifier|*
name|_paddr
parameter_list|,
name|bus_size_t
modifier|*
name|_size
parameter_list|,
name|pcell_t
modifier|*
name|_pci_hi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_parse_bootargs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

