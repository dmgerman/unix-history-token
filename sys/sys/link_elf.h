begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 Paul Kranenburg  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Paul Kranenburg.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * RRS section definitions.  *  * The layout of some data structures defined in this header file is  * such that we can provide compatibility with the SunOS 4.x shared  * library scheme.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LINK_ELF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LINK_ELF_H_
end_define

begin_include
include|#
directive|include
file|<sys/elf.h>
end_include

begin_comment
comment|/*  * Flags that describe the origin of the entries in Dl_serinfo.  * SunOS has these in<sys/link.h>, we follow the suit.  */
end_comment

begin_define
define|#
directive|define
name|LA_SER_ORIG
value|0x01
end_define

begin_comment
comment|/* original (needed) name */
end_comment

begin_define
define|#
directive|define
name|LA_SER_LIBPATH
value|0x02
end_define

begin_comment
comment|/* LD_LIBRARY_PATH entry prepended */
end_comment

begin_define
define|#
directive|define
name|LA_SER_RUNPATH
value|0x04
end_define

begin_comment
comment|/* runpath entry prepended */
end_comment

begin_define
define|#
directive|define
name|LA_SER_CONFIG
value|0x08
end_define

begin_comment
comment|/* configuration entry prepended */
end_comment

begin_define
define|#
directive|define
name|LA_SER_DEFAULT
value|0x40
end_define

begin_comment
comment|/* default path prepended */
end_comment

begin_define
define|#
directive|define
name|LA_SER_SECURE
value|0x80
end_define

begin_comment
comment|/* default (secure) path prepended */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|link_map
block|{
name|caddr_t
name|l_addr
decl_stmt|;
comment|/* Base Address of library */
ifdef|#
directive|ifdef
name|__mips__
name|caddr_t
name|l_offs
decl_stmt|;
comment|/* Load Offset of library */
endif|#
directive|endif
specifier|const
name|char
modifier|*
name|l_name
decl_stmt|;
comment|/* Absolute Path to Library */
specifier|const
name|void
modifier|*
name|l_ld
decl_stmt|;
comment|/* Pointer to .dynamic in memory */
name|struct
name|link_map
modifier|*
name|l_next
decl_stmt|,
modifier|*
name|l_prev
decl_stmt|;
comment|/* linked list of of mapped libs */
block|}
name|Link_map
typedef|;
end_typedef

begin_struct
struct|struct
name|r_debug
block|{
name|int
name|r_version
decl_stmt|;
comment|/* not used */
name|struct
name|link_map
modifier|*
name|r_map
decl_stmt|;
comment|/* list of loaded images */
name|void
function_decl|(
modifier|*
name|r_brk
function_decl|)
parameter_list|(
name|struct
name|r_debug
modifier|*
parameter_list|,
name|struct
name|link_map
modifier|*
parameter_list|)
function_decl|;
comment|/* pointer to break point */
enum|enum
block|{
name|RT_CONSISTENT
block|,
comment|/* things are stable */
name|RT_ADD
block|,
comment|/* adding a shared library */
name|RT_DELETE
comment|/* removing a shared library */
block|}
name|r_state
enum|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dl_phdr_info
block|{
name|Elf_Addr
name|dlpi_addr
decl_stmt|;
comment|/* module relocation base */
specifier|const
name|char
modifier|*
name|dlpi_name
decl_stmt|;
comment|/* module name */
specifier|const
name|Elf_Phdr
modifier|*
name|dlpi_phdr
decl_stmt|;
comment|/* pointer to module's phdr */
name|Elf_Half
name|dlpi_phnum
decl_stmt|;
comment|/* number of entries in phdr */
name|unsigned
name|long
name|long
name|int
name|dlpi_adds
decl_stmt|;
comment|/* total # of loads */
name|unsigned
name|long
name|long
name|int
name|dlpi_subs
decl_stmt|;
comment|/* total # of unloads */
name|size_t
name|dlpi_tls_modid
decl_stmt|;
name|void
modifier|*
name|dlpi_tls_data
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|__BEGIN_DECLS
end_macro

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|__dl_iterate_hdr_callback
function_decl|)
parameter_list|(
name|struct
name|dl_phdr_info
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|dl_iterate_phdr
parameter_list|(
name|__dl_iterate_hdr_callback
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_LINK_ELF_H_ */
end_comment

end_unit

