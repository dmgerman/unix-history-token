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
comment|/*  * An ARM platform implementation is declared with a kernel object and  * an associated method table, similar to a device driver.  *  * e.g.  *  * static platform_method_t bcm2835_methods[] = {  *	PLATFORMMETHOD(platform_probe,		bcm2835_probe),  *  ...  *	PLATFORMMETHOD_END  * };  *  * static platform_def_t bcm3835_platform = {  * 	"bcm2835",  *	bcm2835_methods,  *	sizeof(bcm2835_platform_softc),	// or 0 if no softc  * };  *  * PLATFORM_DEF(bcm2835_platform);  */
end_comment

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_struct
struct|struct
name|platform_class
block|{
name|KOBJ_CLASS_FIELDS
expr_stmt|;
comment|/* How many times to loop to delay approximately 1us */
name|int
name|delay_count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|platform_kobj
block|{
comment|/* 	 * A platform instance is a kernel object 	 */
name|KOBJ_FIELDS
expr_stmt|;
comment|/* Platform class, for access to class specific data */
name|struct
name|platform_class
modifier|*
name|cls
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
name|platform_class
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

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_struct
struct|struct
name|fdt_platform_class
block|{
name|KOBJ_CLASS_FIELDS
expr_stmt|;
specifier|const
name|char
modifier|*
name|fdt_compatible
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fdt_platform_class
name|fdt_platform_def_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|platform_method_t
name|fdt_platform_methods
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FDT_PLATFORM_DEF2
parameter_list|(
name|NAME
parameter_list|,
name|VAR_NAME
parameter_list|,
name|NAME_STR
parameter_list|,
name|size
parameter_list|,
name|compatible
parameter_list|,	\
name|delay
parameter_list|)
define|\
value|CTASSERT(delay> 0);							\ static fdt_platform_def_t VAR_NAME ## _fdt_platform = {			\ 	.name = NAME_STR,						\ 	.methods = fdt_platform_methods,				\ 	.fdt_compatible = compatible,					\ };									\ static kobj_class_t VAR_NAME ## _baseclasses[] =			\ 	{ (kobj_class_t)&VAR_NAME ## _fdt_platform, NULL };		\ static platform_def_t VAR_NAME ## _platform = {				\ 	NAME_STR,							\ 	NAME ## _methods,						\ 	size,								\ 	VAR_NAME ## _baseclasses,					\ 	delay,								\ };									\ DATA_SET(platform_set, VAR_NAME ## _platform)
end_define

begin_define
define|#
directive|define
name|FDT_PLATFORM_DEF
parameter_list|(
name|NAME
parameter_list|,
name|NAME_STR
parameter_list|,
name|size
parameter_list|,
name|compatible
parameter_list|,
name|delay
parameter_list|)
define|\
value|FDT_PLATFORM_DEF2(NAME, NAME, NAME_STR, size, compatible, delay)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Helper to get the platform object  */
end_comment

begin_function_decl
name|platform_t
name|platform_obj
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|arm_tmr_timed_wait
parameter_list|(
name|platform_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PLATFORMVAR_H_ */
end_comment

end_unit

