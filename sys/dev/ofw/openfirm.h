begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: openfirm.h,v 1.1 1998/05/15 10:16:00 tsubai Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
comment|/*  * Prototypes for Open Firmware Interface Routines  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|cell_t
typedef|;
end_typedef

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_define
define|#
directive|define
name|p1275_ptr2cell
parameter_list|(
name|p
parameter_list|)
value|((cell_t)((uintptr_t)((void *)(p))))
end_define

begin_define
define|#
directive|define
name|p1275_int2cell
parameter_list|(
name|i
parameter_list|)
value|((cell_t)((int)(i)))
end_define

begin_define
define|#
directive|define
name|p1275_uint2cell
parameter_list|(
name|u
parameter_list|)
value|((cell_t)((unsigned int)(u)))
end_define

begin_define
define|#
directive|define
name|p1275_size2cell
parameter_list|(
name|u
parameter_list|)
value|((cell_t)((size_t)(u)))
end_define

begin_define
define|#
directive|define
name|p1275_phandle2cell
parameter_list|(
name|ph
parameter_list|)
value|((cell_t)((unsigned int)((phandle_t)(ph))))
end_define

begin_define
define|#
directive|define
name|p1275_dnode2cell
parameter_list|(
name|d
parameter_list|)
value|((cell_t)((unsigned int)((pnode_t)(d))))
end_define

begin_define
define|#
directive|define
name|p1275_ihandle2cell
parameter_list|(
name|ih
parameter_list|)
value|((cell_t)((unsigned int)((ihandle_t)(ih))))
end_define

begin_define
define|#
directive|define
name|p1275_ull2cell_high
parameter_list|(
name|ll
parameter_list|)
value|(0LL)
end_define

begin_define
define|#
directive|define
name|p1275_ull2cell_low
parameter_list|(
name|ll
parameter_list|)
value|((cell_t)(ll))
end_define

begin_define
define|#
directive|define
name|p1275_uintptr2cell
parameter_list|(
name|i
parameter_list|)
value|((cell_t)((uintptr_t)(i)))
end_define

begin_define
define|#
directive|define
name|p1275_cell2ptr
parameter_list|(
name|p
parameter_list|)
value|((void *)((cell_t)(p)))
end_define

begin_define
define|#
directive|define
name|p1275_cell2int
parameter_list|(
name|i
parameter_list|)
value|((int)((cell_t)(i)))
end_define

begin_define
define|#
directive|define
name|p1275_cell2uint
parameter_list|(
name|u
parameter_list|)
value|((unsigned int)((cell_t)(u)))
end_define

begin_define
define|#
directive|define
name|p1275_cell2size
parameter_list|(
name|u
parameter_list|)
value|((size_t)((cell_t)(u)))
end_define

begin_define
define|#
directive|define
name|p1275_cell2phandle
parameter_list|(
name|ph
parameter_list|)
value|((phandle_t)((cell_t)(ph)))
end_define

begin_define
define|#
directive|define
name|p1275_cell2dnode
parameter_list|(
name|d
parameter_list|)
value|((pnode_t)((cell_t)(d)))
end_define

begin_define
define|#
directive|define
name|p1275_cell2ihandle
parameter_list|(
name|ih
parameter_list|)
value|((ihandle_t)((cell_t)(ih)))
end_define

begin_define
define|#
directive|define
name|p1275_cells2ull
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|((unsigned long long)(cell_t)(l))
end_define

begin_define
define|#
directive|define
name|p1275_cell2uintptr
parameter_list|(
name|i
parameter_list|)
value|((uintptr_t)((cell_t)(i)))
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_OFWPROP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Stuff that is used by the Open Firmware code.  */
end_comment

begin_function_decl
name|void
name|set_openfirm_callback
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openfirmware
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This isn't actually an Open Firmware function, but it seemed like the right  * place for it to go.  */
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

begin_function_decl
name|void
name|OF_helloworld
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OF_printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
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
name|OF_getprop_alloc
parameter_list|(
name|phandle_t
name|package
parameter_list|,
name|char
modifier|*
name|propname
parameter_list|,
name|int
name|elsz
parameter_list|,
name|void
modifier|*
modifier|*
name|buf
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
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* User interface functions */
end_comment

begin_function_decl
name|int
name|OF_interpret
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

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

begin_comment
comment|/* sun4v additions */
end_comment

begin_function_decl
name|void
name|OF_set_mmfsa_traptable
parameter_list|(
name|void
modifier|*
name|tba_addr
parameter_list|,
name|uint64_t
name|mmfsa_ra
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_translate_virt
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|int
modifier|*
name|valid
parameter_list|,
name|vm_paddr_t
modifier|*
name|physaddr
parameter_list|,
name|int
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|OF_vtophys
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENFIRM_H_ */
end_comment

end_unit

