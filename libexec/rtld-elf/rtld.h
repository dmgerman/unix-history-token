begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1996-1998 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *      $Id: rtld.h,v 1.3 1998/03/06 14:00:09 jdp Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTLD_H
end_ifndef

begin_comment
comment|/* { */
end_comment

begin_define
define|#
directive|define
name|RTLD_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<elf.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_LIBRARY_PATH
end_ifndef

begin_define
define|#
directive|define
name|STANDARD_LIBRARY_PATH
value|"/usr/lib/elf:/usr/lib"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NEW
parameter_list|(
name|type
parameter_list|)
value|((type *) xmalloc(sizeof(type)))
end_define

begin_define
define|#
directive|define
name|CNEW
parameter_list|(
name|type
parameter_list|)
value|((type *) xcalloc(sizeof(type)))
end_define

begin_comment
comment|/* We might as well do booleans like C++. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_struct_decl
struct_decl|struct
name|Struct_Obj_Entry
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|Struct_Needed_Entry
block|{
name|struct
name|Struct_Needed_Entry
modifier|*
name|next
decl_stmt|;
name|struct
name|Struct_Obj_Entry
modifier|*
name|obj
decl_stmt|;
name|unsigned
name|long
name|name
decl_stmt|;
comment|/* Offset of name in string table */
block|}
name|Needed_Entry
typedef|;
end_typedef

begin_comment
comment|/*  * Shared object descriptor.  *  * Items marked with "(%)" are dynamically allocated, and must be freed  * when the structure is destroyed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Struct_Obj_Entry
block|{
comment|/*      * These two items have to be set right for compatibility with the      * original ElfKit crt1.o.      */
name|Elf32_Word
name|magic
decl_stmt|;
comment|/* Magic number (sanity check) */
name|Elf32_Word
name|version
decl_stmt|;
comment|/* Version number of struct format */
name|struct
name|Struct_Obj_Entry
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|path
decl_stmt|;
comment|/* Pathname of underlying file (%) */
name|int
name|refcount
decl_stmt|;
name|int
name|dl_refcount
decl_stmt|;
comment|/* Number of times loaded by dlopen */
comment|/* These items are computed by map_object() or by digest_phdr(). */
name|caddr_t
name|mapbase
decl_stmt|;
comment|/* Base address of mapped region */
name|size_t
name|mapsize
decl_stmt|;
comment|/* Size of mapped region in bytes */
name|size_t
name|textsize
decl_stmt|;
comment|/* Size of text segment in bytes */
name|Elf32_Addr
name|vaddrbase
decl_stmt|;
comment|/* Base address in shared object file */
name|caddr_t
name|relocbase
decl_stmt|;
comment|/* Relocation constant = mapbase - vaddrbase */
specifier|const
name|Elf32_Dyn
modifier|*
name|dynamic
decl_stmt|;
comment|/* Dynamic section */
name|caddr_t
name|entry
decl_stmt|;
comment|/* Entry point */
specifier|const
name|Elf32_Phdr
modifier|*
name|phdr
decl_stmt|;
comment|/* Program header if it is mapped, else NULL */
name|size_t
name|phsize
decl_stmt|;
comment|/* Size of program header in bytes */
comment|/* Items from the dynamic section. */
name|Elf32_Addr
modifier|*
name|got
decl_stmt|;
comment|/* GOT table */
specifier|const
name|Elf32_Rel
modifier|*
name|rel
decl_stmt|;
comment|/* Relocation entries */
name|unsigned
name|long
name|relsize
decl_stmt|;
comment|/* Size in bytes of relocation info */
specifier|const
name|Elf32_Rel
modifier|*
name|pltrel
decl_stmt|;
comment|/* PLT relocation entries */
name|unsigned
name|long
name|pltrelsize
decl_stmt|;
comment|/* Size in bytes of PLT relocation info */
specifier|const
name|Elf32_Sym
modifier|*
name|symtab
decl_stmt|;
comment|/* Symbol table */
specifier|const
name|char
modifier|*
name|strtab
decl_stmt|;
comment|/* String table */
name|unsigned
name|long
name|strsize
decl_stmt|;
comment|/* Size in bytes of string table */
specifier|const
name|Elf32_Word
modifier|*
name|buckets
decl_stmt|;
comment|/* Hash table buckets array */
name|unsigned
name|long
name|nbuckets
decl_stmt|;
comment|/* Number of buckets */
specifier|const
name|Elf32_Word
modifier|*
name|chains
decl_stmt|;
comment|/* Hash table chain array */
name|unsigned
name|long
name|nchains
decl_stmt|;
comment|/* Number of chains */
specifier|const
name|char
modifier|*
name|rpath
decl_stmt|;
comment|/* Search path specified in object */
name|Needed_Entry
modifier|*
name|needed
decl_stmt|;
comment|/* Shared objects needed by this one (%) */
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Initialization function to call */
name|void
function_decl|(
modifier|*
name|fini
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Termination function to call */
name|bool
name|mainprog
decl_stmt|;
comment|/* True if this is the main program */
name|bool
name|rtld
decl_stmt|;
comment|/* True if this is the dynamic linker */
name|bool
name|textrel
decl_stmt|;
comment|/* True if there are relocations to text seg */
name|bool
name|symbolic
decl_stmt|;
comment|/* True if generated with "-Bsymbolic" */
block|}
name|Obj_Entry
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RTLD_MAGIC
value|0xd550b87a
end_define

begin_define
define|#
directive|define
name|RTLD_VERSION
value|1
end_define

begin_function_decl
specifier|extern
name|void
name|_rtld_error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Obj_Entry
modifier|*
name|map_object
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|xcalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|xstrdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

end_unit

