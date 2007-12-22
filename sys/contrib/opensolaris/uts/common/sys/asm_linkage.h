begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IA32_SYS_ASM_LINKAGE_H
end_ifndef

begin_define
define|#
directive|define
name|_IA32_SYS_ASM_LINKAGE_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_ASM
comment|/* The remainder of this file is only for assembly files */
comment|/*  * make annoying differences in assembler syntax go away  */
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
define|#
directive|define
name|ASM_ENTRY_ALIGN
value|16
comment|/*  * ENTRY provides the standard procedure entry code and an easy way to  * insert the calls to mcount for profiling. ENTRY_NP is identical, but  * never calls mcount.  */
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.text; \ 	.align	ASM_ENTRY_ALIGN; \ 	.globl	x; \ 	.type	x, @function; \ x:
comment|/*  * ALTENTRY provides for additional entry points.  */
define|#
directive|define
name|ALTENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl x; \ 	.type	x, @function; \ x:
comment|/*  * SET_SIZE trails a function and set the size for the ELF symbol table.  */
define|#
directive|define
name|SET_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|.size	x, [.-x]
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc64__
argument_list|)
comment|/*  * ENTRY provides the standard procedure entry code and an easy way to  * insert the calls to mcount for profiling. ENTRY_NP is identical, but  * never calls mcount.  */
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.section	".text"; \ 	.align	4; \ 	.global	x; \ 	.type	x, @function; \ x:
comment|/*  * ALTENTRY provides for additional entry points.  */
define|#
directive|define
name|ALTENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.global	x; \ 	.type	x, @function; \ x:
comment|/*  * SET_SIZE trails a function and set the size for the ELF symbol table.  */
define|#
directive|define
name|SET_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|.size	x, (.-x)
else|#
directive|else
error|#
directive|error
error|Unsupported architecture.
endif|#
directive|endif
endif|#
directive|endif
comment|/* _ASM */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IA32_SYS_ASM_LINKAGE_H */
end_comment

end_unit

