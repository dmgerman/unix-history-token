begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1996, 1997, 1998, 1999, 2000 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<machine/elf.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<elf-hints.h>
end_include

begin_include
include|#
directive|include
file|<link.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"rtld_machdep.h"
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
name|stat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|Struct_Obj_Entry
struct_decl|;
end_struct_decl

begin_comment
comment|/* Lists of shared objects */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Struct_Objlist_Entry
block|{
name|STAILQ_ENTRY
argument_list|(
argument|Struct_Objlist_Entry
argument_list|)
name|link
expr_stmt|;
name|struct
name|Struct_Obj_Entry
modifier|*
name|obj
decl_stmt|;
block|}
name|Objlist_Entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument|Struct_Objlist
argument_list|,
argument|Struct_Objlist_Entry
argument_list|)
name|Objlist
expr_stmt|;
end_typedef

begin_comment
comment|/* Types of init and fini functions */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|InitFunc
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Lists of shared object dependencies */
end_comment

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
comment|/* Lock object */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Struct_LockInfo
block|{
name|void
modifier|*
name|context
decl_stmt|;
comment|/* Client context for creating locks */
name|void
modifier|*
name|thelock
decl_stmt|;
comment|/* The one big lock */
comment|/* Debugging aids. */
specifier|volatile
name|int
name|rcount
decl_stmt|;
comment|/* Number of readers holding lock */
specifier|volatile
name|int
name|wcount
decl_stmt|;
comment|/* Number of writers holding lock */
comment|/* Methods */
name|void
modifier|*
function_decl|(
modifier|*
name|lock_create
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rlock_acquire
function_decl|)
parameter_list|(
name|void
modifier|*
name|lock
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|wlock_acquire
function_decl|)
parameter_list|(
name|void
modifier|*
name|lock
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rlock_release
function_decl|)
parameter_list|(
name|void
modifier|*
name|lock
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|wlock_release
function_decl|)
parameter_list|(
name|void
modifier|*
name|lock
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|lock_destroy
function_decl|)
parameter_list|(
name|void
modifier|*
name|lock
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|context_destroy
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
block|}
name|LockInfo
typedef|;
end_typedef

begin_comment
comment|/*  * Shared object descriptor.  *  * Items marked with "(%)" are dynamically allocated, and must be freed  * when the structure is destroyed.  *  * CAUTION: It appears that the JDK port peeks into these structures.  * It looks at "next" and "mapbase" at least.  Don't add new members  * near the front, until this can be straightened out.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Struct_Obj_Entry
block|{
comment|/*      * These two items have to be set right for compatibility with the      * original ElfKit crt1.o.      */
name|Elf_Word
name|magic
decl_stmt|;
comment|/* Magic number (sanity check) */
name|Elf_Word
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
name|Elf_Addr
name|vaddrbase
decl_stmt|;
comment|/* Base address in shared object file */
name|caddr_t
name|relocbase
decl_stmt|;
comment|/* Relocation constant = mapbase - vaddrbase */
specifier|const
name|Elf_Dyn
modifier|*
name|dynamic
decl_stmt|;
comment|/* Dynamic section */
name|caddr_t
name|entry
decl_stmt|;
comment|/* Entry point */
specifier|const
name|Elf_Phdr
modifier|*
name|phdr
decl_stmt|;
comment|/* Program header if it is mapped, else NULL */
name|size_t
name|phsize
decl_stmt|;
comment|/* Size of program header in bytes */
specifier|const
name|char
modifier|*
name|interp
decl_stmt|;
comment|/* Pathname of the interpreter, if any */
comment|/* Items from the dynamic section. */
name|Elf_Addr
modifier|*
name|pltgot
decl_stmt|;
comment|/* PLT or GOT, depending on architecture */
specifier|const
name|Elf_Rel
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
name|Elf_Rela
modifier|*
name|rela
decl_stmt|;
comment|/* Relocation entries with addend */
name|unsigned
name|long
name|relasize
decl_stmt|;
comment|/* Size in bytes of addend relocation info */
specifier|const
name|Elf_Rel
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
name|Elf_Rela
modifier|*
name|pltrela
decl_stmt|;
comment|/* PLT relocation entries with addend */
name|unsigned
name|long
name|pltrelasize
decl_stmt|;
comment|/* Size in bytes of PLT addend reloc info */
specifier|const
name|Elf_Sym
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
name|Elf_Addr
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
name|Elf_Addr
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
name|InitFunc
name|init
decl_stmt|;
comment|/* Initialization function to call */
name|InitFunc
name|fini
decl_stmt|;
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
name|bool
name|traced
decl_stmt|;
comment|/* Already printed in ldd trace output */
name|bool
name|jmpslots_done
decl_stmt|;
comment|/* Already have relocated the jump slots */
name|bool
name|init_done
decl_stmt|;
comment|/* Already have added object to init list */
name|struct
name|link_map
name|linkmap
decl_stmt|;
comment|/* for GDB */
name|Objlist
name|dldags
decl_stmt|;
comment|/* Object belongs to these dlopened DAGs (%) */
name|Objlist
name|dagmembers
decl_stmt|;
comment|/* DAG has these members (%) */
name|dev_t
name|dev
decl_stmt|;
comment|/* Object's filesystem's device */
name|ino_t
name|ino
decl_stmt|;
comment|/* Object's inode number */
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

begin_comment
comment|/*  * Symbol cache entry used during relocation to avoid multiple lookups  * of the same symbol.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Struct_SymCache
block|{
specifier|const
name|Elf_Sym
modifier|*
name|sym
decl_stmt|;
comment|/* Symbol table entry */
specifier|const
name|Obj_Entry
modifier|*
name|obj
decl_stmt|;
comment|/* Shared object which defines it */
block|}
name|SymCache
typedef|;
end_typedef

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
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|Obj_Entry
modifier|*
name|map_object
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|stat
modifier|*
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

begin_decl_stmt
specifier|extern
name|Elf_Addr
name|_GLOBAL_OFFSET_TABLE_
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Function declarations.  */
end_comment

begin_function_decl
name|int
name|do_copy_relocations
parameter_list|(
name|Obj_Entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|elf_hash
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|Elf_Sym
modifier|*
name|find_symdef
parameter_list|(
name|unsigned
name|long
parameter_list|,
specifier|const
name|Obj_Entry
modifier|*
parameter_list|,
specifier|const
name|Obj_Entry
modifier|*
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|SymCache
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_pltgot
parameter_list|(
name|Obj_Entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lockdflt_init
parameter_list|(
name|LockInfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_free
parameter_list|(
name|Obj_Entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Obj_Entry
modifier|*
name|obj_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reloc_non_plt
parameter_list|(
name|Obj_Entry
modifier|*
parameter_list|,
name|Obj_Entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reloc_plt
parameter_list|(
name|Obj_Entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reloc_jmpslots
parameter_list|(
name|Obj_Entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_rtld_bind_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|Elf_Sym
modifier|*
name|symlook_obj
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|Obj_Entry
modifier|*
parameter_list|,
name|bool
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

