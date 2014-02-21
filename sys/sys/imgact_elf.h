begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995-1996 SÃ¸ren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|_KERNEL
end_ifdef

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

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Structure used to pass infomation from the loader to the  * stack fixup routine.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf_Ssize
name|execfd
decl_stmt|;
name|Elf_Size
name|phdr
decl_stmt|;
name|Elf_Size
name|phent
decl_stmt|;
name|Elf_Size
name|phnum
decl_stmt|;
name|Elf_Size
name|pagesz
decl_stmt|;
name|Elf_Size
name|base
decl_stmt|;
name|Elf_Size
name|flags
decl_stmt|;
name|Elf_Size
name|entry
decl_stmt|;
block|}
name|__ElfN
typedef|(
name|Auxargs
typedef|);
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf_Note
name|hdr
decl_stmt|;
specifier|const
name|char
modifier|*
name|vendor
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|boolean_t
function_decl|(
modifier|*
name|trans_osrel
function_decl|)
parameter_list|(
specifier|const
name|Elf_Note
modifier|*
parameter_list|,
name|int32_t
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|BN_CAN_FETCH_OSREL
value|0x0001
comment|/* Deprecated. */
define|#
directive|define
name|BN_TRANSLATE_OSREL
value|0x0002
comment|/* Use trans_osrel to fetch osrel */
comment|/* after checking the image ABI specification, if needed. */
block|}
name|Elf_Brandnote
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|brand
decl_stmt|;
name|int
name|machine
decl_stmt|;
specifier|const
name|char
modifier|*
name|compat_3_brand
decl_stmt|;
comment|/* pre Binutils 2.10 method (FBSD 3) */
specifier|const
name|char
modifier|*
name|emul_path
decl_stmt|;
specifier|const
name|char
modifier|*
name|interp_path
decl_stmt|;
name|struct
name|sysentvec
modifier|*
name|sysvec
decl_stmt|;
specifier|const
name|char
modifier|*
name|interp_newpath
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|Elf_Brandnote
modifier|*
name|brand_note
decl_stmt|;
define|#
directive|define
name|BI_CAN_EXEC_DYN
value|0x0001
define|#
directive|define
name|BI_BRAND_NOTE
value|0x0002
comment|/* May have note.ABI-tag section. */
define|#
directive|define
name|BI_BRAND_NOTE_MANDATORY
value|0x0004
comment|/* Must have note.ABI-tag section. */
block|}
name|__ElfN
typedef|(
name|Brandinfo
typedef|);
end_typedef

begin_expr_stmt
name|__ElfType
argument_list|(
name|Auxargs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ElfType
argument_list|(
name|Brandinfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|MAX_BRANDS
value|8
end_define

begin_function_decl
name|int
name|__elfN
function_decl|(
name|brand_inuse
function_decl|)
parameter_list|(
name|Elf_Brandinfo
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__elfN
function_decl|(
name|insert_brand_entry
function_decl|)
parameter_list|(
name|Elf_Brandinfo
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__elfN
function_decl|(
name|remove_brand_entry
function_decl|)
parameter_list|(
name|Elf_Brandinfo
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__elfN
function_decl|(
name|freebsd_fixup
function_decl|)
parameter_list|(
name|register_t
modifier|*
modifier|*
parameter_list|,
name|struct
name|image_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__elfN
function_decl|(
name|coredump
function_decl|)
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Machine specific function to dump per-thread information. */
end_comment

begin_function_decl
name|void
name|__elfN
function_decl|(
name|dump_thread
function_decl|)
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__elfN
parameter_list|(
name|fallback_brand
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Elf_Brandnote
name|__elfN
parameter_list|(
name|freebsd_brandnote
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Elf_Brandnote
name|__elfN
parameter_list|(
name|kfreebsd_brandnote
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
comment|/* !_SYS_IMGACT_ELF_H_ */
end_comment

end_unit

