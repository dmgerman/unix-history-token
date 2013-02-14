begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Peter Grehan  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PLATFORMVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PLATFORMVAR_H_
end_define

begin_comment
comment|/*  * A PowerPC platform implementation is declared with a kernel object and  * an associated method table, similar to a device driver.  *  * e.g.  *  * static platform_method_t chrp_methods[] = {  *	PLATFORMMETHOD(platform_probe,		chrp_probe),  *	PLATFORMMETHOD(platform_mem_regions,	ofw_mem_regions),  *  ...  *	PLATFORMMETHOD(platform_smp_first_cpu,	chrp_smp_first_cpu),  *	{ 0, 0 }  * };  *  * static platform_def_t chrp_platform = {  * 	"chrp",  *	chrp_methods,  *	sizeof(chrp_platform_softc),	// or 0 if no softc  * };  *  * PLATFORM_DEF(chrp_platform);  */
end_comment

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_struct
struct|struct
name|platform_kobj
block|{
comment|/* 	 * A platform instance is a kernel object 	 */
name|KOBJ_FIELDS
expr_stmt|;
comment|/* 	 * Utility elements that an instance may use 	 */
name|struct
name|mtx
name|platform_mtx
decl_stmt|;
comment|/* available for instance use */
name|void
modifier|*
name|platform_iptr
decl_stmt|;
comment|/* instance data pointer */
comment|/* 	 * Opaque data that can be overlaid with an instance-private 	 * structure. Platform code can test that this is large enough at 	 * compile time with a sizeof() test againt it's softc. There 	 * is also a run-time test when the platform kernel object is 	 * registered. 	 */
define|#
directive|define
name|PLATFORM_OPAQUESZ
value|64
name|u_int
name|platform_opaque
index|[
name|PLATFORM_OPAQUESZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|platform_kobj
modifier|*
name|platform_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|kobj_class
name|platform_def_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|platform_method_t
value|kobj_method_t
end_define

begin_define
define|#
directive|define
name|PLATFORMMETHOD
value|KOBJMETHOD
end_define

begin_define
define|#
directive|define
name|PLATFORMMETHOD_END
value|KOBJMETHOD_END
end_define

begin_define
define|#
directive|define
name|PLATFORM_DEF
parameter_list|(
name|name
parameter_list|)
value|DATA_SET(platform_set, name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PLATFORMVAR_H_ */
end_comment

end_unit

