begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: tlsbvar.h,v 1.5 1998/05/13 23:23:23 thorpej Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997, 2000 by Matthew Jacob  * NASA AMES Research Center.  * All rights reserved.  *  * Based in part upon a prototype version by Jason Thorpe  * Copyright (c) 1996 by Jason Thorpe.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Definitions for the TurboLaser System Bus found on  * AlphaServer 8200/8400 systems.  */
end_comment

begin_enum
enum|enum
name|tlsb_device_instvars
block|{
name|TLSB_IVAR_NODE
block|,
name|TLSB_IVAR_DTYPE
block|,
name|TLSB_IVAR_SWREV
block|,
name|TLSB_IVAR_HWREV
block|}
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for turbolaser devices  */
end_comment

begin_define
define|#
directive|define
name|TLSB_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\ 									 \
value|static __inline T tlsb_get_ ## A(device_t dev)				 \ {									 \ 	u_long v;							 \ 	BUS_READ_IVAR(device_get_parent(dev), dev, TLSB_IVAR_ ## B,&v); \ 	return v;							 \ }
end_define

begin_macro
name|TLSB_ACCESSOR
argument_list|(
argument|node
argument_list|,
argument|NODE
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|TLSB_ACCESSOR
argument_list|(
argument|dtype
argument_list|,
argument|DTYPE
argument_list|,
argument|u_int16_t
argument_list|)
end_macro

begin_macro
name|TLSB_ACCESSOR
argument_list|(
argument|hwrev
argument_list|,
argument|HWREV
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|TLSB_ACCESSOR
argument_list|(
argument|swrev
argument_list|,
argument|SWREV
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_comment
comment|/*  * Bus-dependent structure for CPUs. This is dynamically allocated  * for each CPU on the TurboLaser, and glued into the cpu_softc  * as sc_busdep (when there is a cpu_softc to do this to).  */
end_comment

begin_struct
struct|struct
name|tlsb_cpu_busdep
block|{
name|u_int8_t
name|tcpu_vid
decl_stmt|;
comment|/* virtual ID of CPU */
name|int
name|tcpu_node
decl_stmt|;
comment|/* TurboLaser node */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The structure used to attach devices to the TurboLaser.  */
end_comment

begin_struct
struct|struct
name|tlsb_device
block|{
name|int
name|td_node
decl_stmt|;
comment|/* node number (TLSB slot) */
name|u_int32_t
name|td_tldev
decl_stmt|;
comment|/* tl device id */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEVTOTLSB
parameter_list|(
name|dev
parameter_list|)
value|((struct tlsb_device *) device_get_ivars(dev))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|tlsb_device
modifier|*
name|tlsb_primary_cpu
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

