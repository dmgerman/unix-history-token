begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pucvar.h,v 1.2 1999/02/06 06:29:54 cgd Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002 JF Hay.  All rights reserved.  * Copyright (c) 2000 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Christopher G. Demetriou.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Exported (or conveniently located) PCI "universal" communications card  * software structures.  *  * Author: Christopher G. Demetriou, May 14, 1998.  */
end_comment

begin_define
define|#
directive|define
name|PUC_MAX_PORTS
value|16
end_define

begin_struct_decl
struct_decl|struct
name|puc_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|puc_init_t
parameter_list|(
name|struct
name|puc_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|puc_device_description
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|uint32_t
name|rval
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|rmask
index|[
literal|4
index|]
decl_stmt|;
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|int
name|bar
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|u_int
name|serialfreq
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
name|int
name|regshft
decl_stmt|;
block|}
name|ports
index|[
name|PUC_MAX_PORTS
index|]
struct|;
name|uint32_t
name|ilr_type
decl_stmt|;
name|uint32_t
name|ilr_offset
index|[
literal|2
index|]
decl_stmt|;
name|puc_init_t
modifier|*
name|init
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PUC_REG_VEND
value|0
end_define

begin_define
define|#
directive|define
name|PUC_REG_PROD
value|1
end_define

begin_define
define|#
directive|define
name|PUC_REG_SVEND
value|2
end_define

begin_define
define|#
directive|define
name|PUC_REG_SPROD
value|3
end_define

begin_define
define|#
directive|define
name|PUC_PORT_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PUC_PORT_TYPE_COM
value|1
end_define

begin_define
define|#
directive|define
name|PUC_PORT_TYPE_LPT
value|2
end_define

begin_define
define|#
directive|define
name|PUC_PORT_TYPE_UART
value|3
end_define

begin_comment
comment|/* UART subtypes. */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_SUBTYPE_MASK
value|(~0xff)
end_define

begin_define
define|#
directive|define
name|PUC_PORT_UART_NS8250
value|(0<<8)
end_define

begin_define
define|#
directive|define
name|PUC_PORT_UART_SAB82532
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|PUC_PORT_UART_Z8530
value|(2<<8)
end_define

begin_comment
comment|/* Interrupt Latch Register (ILR) types */
end_comment

begin_define
define|#
directive|define
name|PUC_ILR_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PUC_ILR_TYPE_DIGI
value|1
end_define

begin_define
define|#
directive|define
name|PUC_FLAGS_MEMORY
value|0x0001
end_define

begin_comment
comment|/* Use memory mapped I/O. */
end_comment

begin_define
define|#
directive|define
name|PUC_FLAGS_ALTRES
value|0x0002
end_define

begin_comment
comment|/* Use alternate I/O type. */
end_comment

begin_define
define|#
directive|define
name|PUC_PORT_VALID
parameter_list|(
name|desc
parameter_list|,
name|port
parameter_list|)
define|\
value|((port)< PUC_MAX_PORTS&& (desc).ports[(port)].type != PUC_PORT_TYPE_NONE)
end_define

begin_define
define|#
directive|define
name|PUC_MAX_BAR
value|6
end_define

begin_enum
enum|enum
name|puc_device_ivars
block|{
name|PUC_IVAR_FREQ
block|,
name|PUC_IVAR_SUBTYPE
block|,
name|PUC_IVAR_REGSHFT
block|,
name|PUC_IVAR_PORT
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|PUC_ENTRAILS
end_ifdef

begin_function_decl
name|int
name|puc_attach
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|puc_device_description
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|puc_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|resource
modifier|*
name|puc_alloc_resource
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|puc_release_resource
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|puc_get_resource
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|puc_read_ivar
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|uintptr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|puc_setup_intr
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|puc_teardown_intr
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|puc_softc
block|{
name|struct
name|puc_device_description
name|sc_desc
decl_stmt|;
comment|/* card-global dynamic data */
name|int
name|fastintr
decl_stmt|;
name|int
name|barmuxed
decl_stmt|;
name|int
name|irqrid
decl_stmt|;
name|struct
name|resource
modifier|*
name|irqres
decl_stmt|;
name|void
modifier|*
name|intr_cookie
decl_stmt|;
name|int
name|ilr_enabled
decl_stmt|;
name|bus_space_tag_t
name|ilr_st
decl_stmt|;
name|bus_space_handle_t
name|ilr_sh
decl_stmt|;
struct|struct
block|{
name|int
name|used
decl_stmt|;
name|int
name|bar
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* SYS_RES_IOPORT or SYS_RES_MEMORY. */
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
block|}
name|sc_bar_mappings
index|[
name|PUC_MAX_BAR
index|]
struct|;
comment|/* per-port dynamic data */
struct|struct
block|{
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
comment|/* filled in by bus_setup_intr() */
name|void
function_decl|(
modifier|*
name|ihand
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|ihandarg
decl_stmt|;
block|}
name|sc_ports
index|[
name|PUC_MAX_PORTS
index|]
struct|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PUC_ENTRAILS */
end_comment

end_unit

