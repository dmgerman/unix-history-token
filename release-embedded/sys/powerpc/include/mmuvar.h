begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Peter Grehan  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MMUVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MMUVAR_H_
end_define

begin_comment
comment|/*  * A PowerPC MMU implementation is declared with a kernel object and  * an associated method table. The MMU_DEF macro is used to declare  * the class, and also links it to the global MMU class list.  *  * e.g.  *  * static mmu_method_t ppc8xx_methods[] = {  *	MMUMETHOD(mmu_change_wiring,		ppc8xx_mmu_change_wiring),  *	MMUMETHOD(mmu_clear_modify,		ppc8xx_mmu_clear_modify),  *	MMUMETHOD(mmu_clear_reference,		ppc8xx_mmu_clear_reference),  *  ...  *	MMUMETHOD(mmu_dev_direct_mapped,	ppc8xx_mmu_dev_direct_mapped),  *	{ 0, 0 }  * };  *  * MMU_DEF(ppc8xx, MMU_TYPE_8xx, ppc8xx_methods, sizeof(ppc8xx_mmu_softc));  *  * A single level of inheritance is supported in a similar fashion to  * kobj inheritance e.g.  *  * MMU_DEF_1(ppc860c, MMU_TYPE_860c, ppc860c_methods, 0, ppc8xx);  */
end_comment

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_struct
struct|struct
name|mmu_kobj
block|{
comment|/* 	 * An MMU instance is a kernel object 	 */
name|KOBJ_FIELDS
expr_stmt|;
comment|/* 	 * Utility elements that an instance may use 	 */
name|struct
name|mtx
name|mmu_mtx
decl_stmt|;
comment|/* available for instance use */
name|void
modifier|*
name|mmu_iptr
decl_stmt|;
comment|/* instance data pointer */
comment|/* 	 * Opaque data that can be overlaid with an instance-private 	 * structure. MMU code can test that this is large enough at 	 * compile time with a sizeof() test againt it's softc. There 	 * is also a run-time test when the MMU kernel object is 	 * registered. 	 */
define|#
directive|define
name|MMU_OPAQUESZ
value|64
name|u_int
name|mmu_opaque
index|[
name|MMU_OPAQUESZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mmu_kobj
modifier|*
name|mmu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|kobj_class
name|mmu_def_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|mmu_method_t
value|kobj_method_t
end_define

begin_define
define|#
directive|define
name|MMUMETHOD
value|KOBJMETHOD
end_define

begin_define
define|#
directive|define
name|MMU_DEF
parameter_list|(
name|name
parameter_list|,
name|ident
parameter_list|,
name|methods
parameter_list|,
name|size
parameter_list|)
define|\ 						\
value|mmu_def_t name = {				\ 	ident, methods, size, NULL		\ };						\ DATA_SET(mmu_set, name)
end_define

begin_define
define|#
directive|define
name|MMU_DEF_INHERIT
parameter_list|(
name|name
parameter_list|,
name|ident
parameter_list|,
name|methods
parameter_list|,
name|size
parameter_list|,
name|base1
parameter_list|)
define|\ 						\
value|static kobj_class_t name ## _baseclasses[] =	\        	{&base1, NULL };			\ mmu_def_t name = {                              \ 	ident, methods, size, name ## _baseclasses	\ };                                              \ DATA_SET(mmu_set, name)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|mmu_def_t name = {				\ 	ident, methods, size, name ## _baseclasses	\ };						 DATA_SET(mmu_set, name)
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Known MMU names  */
end_comment

begin_define
define|#
directive|define
name|MMU_TYPE_BOOKE
value|"mmu_booke"
end_define

begin_comment
comment|/* Book-E MMU specification */
end_comment

begin_define
define|#
directive|define
name|MMU_TYPE_OEA
value|"mmu_oea"
end_define

begin_comment
comment|/* 32-bit OEA */
end_comment

begin_define
define|#
directive|define
name|MMU_TYPE_G5
value|"mmu_g5"
end_define

begin_comment
comment|/* 64-bit bridge (ibm 970) */
end_comment

begin_define
define|#
directive|define
name|MMU_TYPE_8xx
value|"mmu_8xx"
end_define

begin_comment
comment|/* 8xx quicc TLB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_MMUVAR_H_ */
end_comment

end_unit

