begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Mitsuru IWASAKI<iwasaki@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: aml_common.h,v 1.4 2000/08/08 14:12:05 iwasaki Exp $  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AML_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_AML_COMMON_H_
end_define

begin_comment
comment|/*  * General Stuff  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|AML_SYSABORT
parameter_list|()
value|do {						\ 	printf("aml: fatal errer at %s:%d\n", __FILE__, __LINE__);	\ 	panic("panic in AML interpreter!");				\ } while(0)
end_define

begin_define
define|#
directive|define
name|AML_SYSASSERT
parameter_list|(
name|x
parameter_list|)
value|do {						\ 	if (!(x)) {							\ 		AML_SYSABORT();						\ 	}								\ } while(0)
end_define

begin_define
define|#
directive|define
name|AML_SYSERRX
parameter_list|(
name|eval
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {				\ 	printf(fmt, args);						\ } while(0)
end_define

begin_define
define|#
directive|define
name|AML_DEBUGGER
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_comment
comment|/* no debugger in kernel */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_define
define|#
directive|define
name|AML_SYSASSERT
parameter_list|(
name|x
parameter_list|)
value|assert(x)
end_define

begin_define
define|#
directive|define
name|AML_SYSABORT
parameter_list|()
value|abort()
end_define

begin_define
define|#
directive|define
name|AML_SYSERRX
parameter_list|(
name|eval
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|errx(eval, fmt, args)
end_define

begin_define
define|#
directive|define
name|AML_DEBUGGER
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|aml_dbgr(x, y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_union_decl
union_decl|union
name|aml_object
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|aml_name
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|aml_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AML_DEBUGPRINT
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do {					\ 	if (aml_debug) {						\ 		printf(args);						\ 	}								\ } while(0)
end_define

begin_function_decl
name|void
name|aml_showobject
parameter_list|(
name|union
name|aml_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aml_showtree
parameter_list|(
name|struct
name|aml_name
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aml_print_curname
parameter_list|(
name|struct
name|aml_name
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aml_print_namestring
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aml_print_indent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reigion I/O Stuff for both kernel/userland.  */
end_comment

begin_comment
comment|/*  * Field Flags  */
end_comment

begin_comment
comment|/* bit 0 -3:	AccessType */
end_comment

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_ACCESS_ANYACC
value|0x00
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_ACCESS_BYTEACC
value|0x01
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_ACCESS_WORDACC
value|0x02
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_ACCESS_DWORDACC
value|0x03
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_ACCESS_BLOCKACC
value|0x04
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_ACCESS_SMBSENDRECVACC
value|0x05
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_ACCESS_SMBQUICKACC
value|0x06
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_ACCESSTYPE
parameter_list|(
name|flags
parameter_list|)
value|(flags& 0x0f)
end_define

begin_comment
comment|/* bit 4:	LockRule */
end_comment

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_LOCK_NOLOCK
value|0x00
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_LOCK_LOCK
value|0x10
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_LOCKRULE
parameter_list|(
name|flags
parameter_list|)
value|(flags& 0x10)
end_define

begin_comment
comment|/* bit 5 - 6:	UpdateRule */
end_comment

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_UPDATE_PRESERVE
value|0x00
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_UPDATE_WRITEASONES
value|0x20
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_UPDATE_WRITEASZEROS
value|0x40
end_define

begin_define
define|#
directive|define
name|AML_FIELDFLAGS_UPDATERULE
parameter_list|(
name|flags
parameter_list|)
value|(flags& 0x60)
end_define

begin_comment
comment|/* bit 7:	reserved (must be 0) */
end_comment

begin_define
define|#
directive|define
name|AML_REGION_INPUT
value|0
end_define

begin_define
define|#
directive|define
name|AML_REGION_OUTPUT
value|1
end_define

begin_define
define|#
directive|define
name|AML_REGION_SYSMEM
value|0
end_define

begin_define
define|#
directive|define
name|AML_REGION_SYSIO
value|1
end_define

begin_define
define|#
directive|define
name|AML_REGION_PCICFG
value|2
end_define

begin_define
define|#
directive|define
name|AML_REGION_EMBCTL
value|3
end_define

begin_define
define|#
directive|define
name|AML_REGION_SMBUS
value|4
end_define

begin_struct
struct|struct
name|aml_region_handle
block|{
comment|/* These are copies of values used on initialization */
name|struct
name|aml_environ
modifier|*
name|env
decl_stmt|;
name|int
name|regtype
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
name|u_int32_t
name|baseaddr
decl_stmt|;
name|u_int32_t
name|bitoffset
decl_stmt|;
name|u_int32_t
name|bitlen
decl_stmt|;
comment|/* following is determined on initialization */
name|vm_offset_t
name|addr
decl_stmt|,
name|bytelen
decl_stmt|;
name|u_int32_t
name|unit
decl_stmt|;
comment|/* access unit in bytes */
comment|/* region type dependant */
name|vm_offset_t
name|vaddr
decl_stmt|;
comment|/* SystemMemory */
name|u_int32_t
name|pci_bus
decl_stmt|,
name|pci_devfunc
decl_stmt|;
comment|/* PCI_Config */
block|}
struct|;
end_struct

begin_function_decl
name|u_int32_t
name|aml_adjust_readvalue
parameter_list|(
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|aml_adjust_updatevalue
parameter_list|(
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|aml_bufferfield_read
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aml_bufferfield_write
parameter_list|(
name|u_int32_t
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aml_region_handle_alloc
parameter_list|(
name|struct
name|aml_environ
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|struct
name|aml_region_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aml_region_handle_free
parameter_list|(
name|struct
name|aml_region_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aml_region_io
parameter_list|(
name|struct
name|aml_environ
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aml_region_read_simple
parameter_list|(
name|struct
name|aml_region_handle
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aml_region_write_simple
parameter_list|(
name|struct
name|aml_region_handle
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|aml_region_prompt_read
parameter_list|(
name|struct
name|aml_region_handle
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|aml_region_prompt_write
parameter_list|(
name|struct
name|aml_region_handle
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aml_region_prompt_update_value
parameter_list|(
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|struct
name|aml_region_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AML_COMMON_H_ */
end_comment

end_unit

