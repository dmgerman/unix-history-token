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
name|_DEV_OPENFIRM_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_OPENFIRM_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * Prototypes for Open Firmware Interface Routines  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ihandle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|phandle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|pcell_t
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<machine/ofw_machdep.h>
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_OFWPROP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Open Firmware interface initialization.  OF_install installs the named  * interface as the Open Firmware access mechanism, OF_init initializes it.  */
end_comment

begin_function_decl
name|boolean_t
name|OF_install
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|prio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_init
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Known Open Firmware interface names  */
end_comment

begin_define
define|#
directive|define
name|OFW_STD_DIRECT
value|"ofw_std"
end_define

begin_comment
comment|/* Standard OF interface */
end_comment

begin_define
define|#
directive|define
name|OFW_STD_REAL
value|"ofw_real"
end_define

begin_comment
comment|/* Real-mode OF interface */
end_comment

begin_define
define|#
directive|define
name|OFW_STD_32BIT
value|"ofw_32bit"
end_define

begin_comment
comment|/* 32-bit OF interface */
end_comment

begin_define
define|#
directive|define
name|OFW_FDT
value|"ofw_fdt"
end_define

begin_comment
comment|/* Flattened Device Tree */
end_comment

begin_comment
comment|/* Generic functions */
end_comment

begin_function_decl
name|int
name|OF_test
parameter_list|(
specifier|const
name|char
modifier|*
name|name
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
name|fmt
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
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|phandle_t
name|OF_child
parameter_list|(
name|phandle_t
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|phandle_t
name|OF_parent
parameter_list|(
name|phandle_t
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|OF_getproplen
parameter_list|(
name|phandle_t
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|propname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|OF_getprop
parameter_list|(
name|phandle_t
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|propname
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|OF_getencprop
parameter_list|(
name|phandle_t
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|prop
parameter_list|,
name|pcell_t
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Same as getprop, but maintains endianness */
end_comment

begin_function_decl
name|int
name|OF_hasprop
parameter_list|(
name|phandle_t
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|propname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|OF_searchprop
parameter_list|(
name|phandle_t
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|propname
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|OF_searchencprop
parameter_list|(
name|phandle_t
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|propname
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|OF_getprop_alloc
parameter_list|(
name|phandle_t
name|node
parameter_list|,
specifier|const
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
name|ssize_t
name|OF_getencprop_alloc
parameter_list|(
name|phandle_t
name|node
parameter_list|,
specifier|const
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
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|propname
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_setprop
parameter_list|(
name|phandle_t
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|OF_canon
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
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
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|OF_package_to_path
parameter_list|(
name|phandle_t
name|node
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Some OF implementations (IBM, FDT) have a concept of effective phandles  * used for device-tree cross-references. Given one of these, returns the  * real phandle. If one can't be found (or running on OF implementations  * without this property), returns its input.  */
end_comment

begin_function_decl
name|phandle_t
name|OF_node_from_xref
parameter_list|(
name|phandle_t
name|xref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|phandle_t
name|OF_xref_from_node
parameter_list|(
name|phandle_t
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * When properties contain references to other nodes using xref handles it is  * often necessary to use interfaces provided by the driver for the referenced  * instance.  These routines allow a driver that provides such an interface to  * register its association with an xref handle, and for other drivers to obtain  * the device_t associated with an xref handle.  */
end_comment

begin_function_decl
name|device_t
name|OF_device_from_xref
parameter_list|(
name|phandle_t
name|xref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_device_register_xref
parameter_list|(
name|phandle_t
name|xref
parameter_list|,
name|device_t
name|dev
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
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OF_close
parameter_list|(
name|ihandle_t
name|instance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|OF_read
parameter_list|(
name|ihandle_t
name|instance
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|OF_write
parameter_list|(
name|ihandle_t
name|instance
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_seek
parameter_list|(
name|ihandle_t
name|instance
parameter_list|,
name|uint64_t
name|where
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|phandle_t
name|OF_instance_to_package
parameter_list|(
name|ihandle_t
name|instance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|OF_instance_to_path
parameter_list|(
name|ihandle_t
name|instance
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OF_call_method
parameter_list|(
specifier|const
name|char
modifier|*
name|method
parameter_list|,
name|ihandle_t
name|instance
parameter_list|,
name|int
name|nargs
parameter_list|,
name|int
name|nreturns
parameter_list|,
modifier|...
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
name|virtrequest
parameter_list|,
name|size_t
name|size
parameter_list|,
name|u_int
name|align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OF_release
parameter_list|(
name|void
modifier|*
name|virt
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Control transfer functions */
end_comment

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

begin_comment
comment|/* User interface functions */
end_comment

begin_function_decl
name|int
name|OF_interpret
parameter_list|(
specifier|const
name|char
modifier|*
name|cmd
parameter_list|,
name|int
name|nreturns
parameter_list|,
modifier|...
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
comment|/* _DEV_OPENFIRM_H_ */
end_comment

end_unit

