begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: openfirm.h,v 1.1 1998/05/15 10:16:00 tsubai Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 Benno Rice.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Benno Rice ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENFIRM_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENFIRM_H_
end_define

begin_comment
comment|/*  * Prototypes for Openfirmware Interface Routines  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ihandle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|phandle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|cell_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|openfirmware
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|phandle_t
name|chosen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This isn't actually an OpenFirmware function, but it seemed like the right  * place for it to go.  */
end_comment

begin_function_decl
name|void
name|OF_init
parameter_list|(
name|int
function_decl|(
modifier|*
name|openfirm
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generic functions */
end_comment

begin_function_decl
name|int
name|OF_test
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Device tree functions */
end_comment

begin_function_decl
name|phandle_t
name|OF_peer
parameter_list|(
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|phandle_t
name|OF_child
parameter_list|(
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|phandle_t
name|OF_parent
parameter_list|(
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|phandle_t
name|OF_instance_to_package
parameter_list|(
name|ihandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_getproplen
parameter_list|(
name|phandle_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_getprop
parameter_list|(
name|phandle_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_nextprop
parameter_list|(
name|phandle_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_setprop
parameter_list|(
name|phandle_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_canon
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|phandle_t
name|OF_finddevice
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_instance_to_path
parameter_list|(
name|ihandle_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_package_to_path
parameter_list|(
name|phandle_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_call_method
parameter_list|(
name|char
modifier|*
parameter_list|,
name|ihandle_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Device I/O functions */
end_comment

begin_function_decl
name|ihandle_t
name|OF_open
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OF_close
parameter_list|(
name|ihandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_read
parameter_list|(
name|ihandle_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_write
parameter_list|(
name|ihandle_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_seek
parameter_list|(
name|ihandle_t
parameter_list|,
name|u_quad_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Memory functions */
end_comment

begin_function_decl
name|void
modifier|*
name|OF_claim
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|OF_claim_virt
parameter_list|(
name|vm_offset_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|OF_alloc_phys
parameter_list|(
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OF_release
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OF_release_phys
parameter_list|(
name|vm_offset_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Control transfer functions */
end_comment

begin_function_decl
name|void
name|OF_boot
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OF_enter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OF_exit
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|OF_chain
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* User interface functions */
end_comment

begin_comment
comment|/* OF_interpret */
end_comment

begin_endif
unit|void 		*OF_set_callback(void *); void		OF_set_symbol_lookup(void *, void *);
endif|#
directive|endif
end_endif

begin_comment
comment|/* Time function */
end_comment

begin_function_decl
name|int
name|OF_milliseconds
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
comment|/* _OPENFIRM_H_ */
end_comment

end_unit

