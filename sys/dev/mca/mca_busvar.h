begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Matthew N. Dodd<winter@jurai.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|mca_id_t
typedef|;
end_typedef

begin_struct
struct|struct
name|mca_ident
block|{
name|mca_id_t
name|id
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|char
modifier|*
name|mca_match_id
parameter_list|(
name|u_int16_t
parameter_list|,
name|struct
name|mca_ident
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Simplified accessors for isa devices  */
end_comment

begin_enum
enum|enum
name|mca_device_ivars
block|{
name|MCA_IVAR_SLOT
block|,
name|MCA_IVAR_ID
block|,
name|MCA_IVAR_ENABLED
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|MCA_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\ 									\
value|static __inline T mca_get_ ## A(device_t dev)				\ {									\ 	uintptr_t v;							\ 	BUS_READ_IVAR(device_get_parent(dev), dev, MCA_IVAR_ ## B,&v);	\ 	return (T) v;							\ }
end_define

begin_macro
name|MCA_ACCESSOR
argument_list|(
argument|slot
argument_list|,
argument|SLOT
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|MCA_ACCESSOR
argument_list|(
argument|id
argument_list|,
argument|ID
argument_list|,
argument|mca_id_t
argument_list|)
end_macro

begin_macro
name|MCA_ACCESSOR
argument_list|(
argument|enabled
argument_list|,
argument|ENABLED
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* don't use these! */
end_comment

begin_function_decl
name|void
name|mca_pos_set
parameter_list|(
name|device_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int8_t
name|mca_pos_get
parameter_list|(
name|device_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int8_t
name|mca_pos_read
parameter_list|(
name|device_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mca_add_irq
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mca_add_drq
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mca_add_iospace
parameter_list|(
name|device_t
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mca_add_mspace
parameter_list|(
name|device_t
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

end_unit

