begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, 2003 David E. O'Brien  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"elf-bfd.h"
end_include

begin_comment
comment|/* The kernel recognizes executables as valid only if they carry a    "FreeBSD" label in the ELF header.  So we put this label on all    executables and (for simplicity) also all other object files.  */
end_comment

begin_decl_stmt
specifier|static
name|void
name|elf_fbsd_post_process_headers
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|elf_fbsd_post_process_headers
parameter_list|(
name|abfd
parameter_list|,
name|link_info
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|link_info
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
name|Elf_Internal_Ehdr
modifier|*
name|i_ehdrp
decl_stmt|;
comment|/* ELF file header, internal form.  */
name|i_ehdrp
operator|=
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
comment|/* Put an ABI label supported by FreeBSD>= 4.1.  */
name|i_ehdrp
operator|->
name|e_ident
index|[
name|EI_OSABI
index|]
operator|=
name|ELFOSABI_FREEBSD
expr_stmt|;
block|}
end_function

end_unit

