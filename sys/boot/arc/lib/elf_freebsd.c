begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: loadfile.c,v 1.10 1998/06/25 06:45:46 ross Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)boot.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_include
include|#
directive|include
file|<machine/elf.h>
end_include

begin_include
include|#
directive|include
file|<machine/prom.h>
end_include

begin_include
include|#
directive|include
file|<machine/rpb.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|"bootstrap.h"
end_include

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_function_decl
specifier|static
name|int
name|elf_exec
parameter_list|(
name|struct
name|loaded_module
modifier|*
name|amp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bi_load
parameter_list|(
name|struct
name|bootinfo_v1
modifier|*
parameter_list|,
name|vm_offset_t
modifier|*
parameter_list|,
name|struct
name|loaded_module
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|module_format
name|alpha_elf
init|=
block|{
name|elf_loadmodule
block|,
name|elf_exec
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|ffp_save
decl_stmt|,
name|ptbr_save
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|elf_exec
parameter_list|(
name|struct
name|loaded_module
modifier|*
name|mp
parameter_list|)
block|{
if|#
directive|if
literal|0
block|static struct bootinfo_v1	bootinfo_v1;     struct module_metadata	*md;     Elf_Ehdr			*hdr;     int				err;      if ((md = mod_findmetadata(mp, MODINFOMD_ELFHDR)) == NULL) 	return(EFTYPE);
comment|/* XXX actually EFUCKUP */
block|hdr = (Elf_Ehdr *)&(md->md_data);
comment|/* XXX ffp_save does not appear to be used in the kernel.. */
block|bzero(&bootinfo_v1, sizeof(bootinfo_v1));     err = bi_load(&bootinfo_v1,&ffp_save, mp);     if (err) 	return(err);
comment|/*      * Fill in the bootinfo for the kernel.      */
block|strncpy(bootinfo_v1.booted_kernel, mp->m_name, 	    sizeof(bootinfo_v1.booted_kernel));     prom_getenv(PROM_E_BOOTED_OSFLAGS, bootinfo_v1.boot_flags, 		sizeof(bootinfo_v1.boot_flags));     bootinfo_v1.hwrpb = (void *)HWRPB_ADDR;     bootinfo_v1.hwrpbsize = ((struct rpb *)HWRPB_ADDR)->rpb_size;     bootinfo_v1.cngetc = NULL;     bootinfo_v1.cnputc = NULL;     bootinfo_v1.cnpollc = NULL;      printf("Entering %s at 0x%lx...\n", mp->m_name, hdr->e_entry);     exit(0);     closeall();     alpha_pal_imb();     (*(void (*)())hdr->e_entry)(ffp_save, ptbr_save, 			       BOOTINFO_MAGIC,&bootinfo_v1, 1, 0);
endif|#
directive|endif
block|}
end_function

end_unit

