begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995-1996 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: imgact_elf.h,v 1.2 1996/10/16 17:51:04 sos Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IMGACT_ELF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IMGACT_ELF_H_
end_define

begin_include
include|#
directive|include
file|<machine/elf.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|elf_trace
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AUXARGS_ENTRY
parameter_list|(
name|pos
parameter_list|,
name|id
parameter_list|,
name|val
parameter_list|)
value|{suword(pos++, id); suword(pos++, val);}
end_define

begin_comment
comment|/*  * Structure used to pass infomation from the loader to the  * stack fixup routine.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Sword
name|execfd
decl_stmt|;
name|Elf32_Word
name|phdr
decl_stmt|;
name|Elf32_Word
name|phent
decl_stmt|;
name|Elf32_Word
name|phnum
decl_stmt|;
name|Elf32_Word
name|pagesz
decl_stmt|;
name|Elf32_Word
name|base
decl_stmt|;
name|Elf32_Word
name|flags
decl_stmt|;
name|Elf32_Word
name|entry
decl_stmt|;
name|Elf32_Word
name|trace
decl_stmt|;
block|}
name|Elf32_Auxargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|brand
decl_stmt|;
name|char
modifier|*
name|emul_path
decl_stmt|;
name|char
modifier|*
name|interp_path
decl_stmt|;
name|struct
name|sysentvec
modifier|*
name|sysvec
decl_stmt|;
block|}
name|Elf32_Brandinfo
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_BRANDS
value|8
end_define

begin_decl_stmt
name|int
name|elf_insert_brand_entry
name|__P
argument_list|(
operator|(
name|Elf32_Brandinfo
operator|*
name|entry
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|elf_remove_brand_entry
name|__P
argument_list|(
operator|(
name|Elf32_Brandinfo
operator|*
name|entry
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_IMGACT_ELF_H_ */
end_comment

end_unit

