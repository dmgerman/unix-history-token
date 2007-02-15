begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997-2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LINKER_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LINKER_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/elf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_LINKER
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|mod_depend
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Object representing a file which has been loaded by the linker.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|linker_file
modifier|*
name|linker_file_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|linker_file
argument_list|)
name|linker_file_list_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|caddr_t
name|linker_sym_t
typedef|;
end_typedef

begin_comment
comment|/* opaque symbol */
end_comment

begin_typedef
typedef|typedef
name|c_caddr_t
name|c_linker_sym_t
typedef|;
end_typedef

begin_comment
comment|/* const opaque symbol */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|linker_function_name_callback_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * expanded out linker_sym_t  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|linker_symval
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|caddr_t
name|value
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
name|linker_symval_t
typedef|;
end_typedef

begin_struct
struct|struct
name|common_symbol
block|{
name|STAILQ_ENTRY
argument_list|(
argument|common_symbol
argument_list|)
name|link
expr_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|caddr_t
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linker_file
block|{
name|KOBJ_FIELDS
expr_stmt|;
name|int
name|refs
decl_stmt|;
comment|/* reference count */
name|int
name|userrefs
decl_stmt|;
comment|/* kldload(2) count */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|LINKER_FILE_LINKED
value|0x1
comment|/* file has been fully linked */
name|TAILQ_ENTRY
argument_list|(
argument|linker_file
argument_list|)
name|link
expr_stmt|;
comment|/* list of all loaded files */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* file which was loaded */
name|int
name|id
decl_stmt|;
comment|/* unique id */
name|caddr_t
name|address
decl_stmt|;
comment|/* load address */
name|size_t
name|size
decl_stmt|;
comment|/* size of file */
name|int
name|ndeps
decl_stmt|;
comment|/* number of dependencies */
name|linker_file_t
modifier|*
name|deps
decl_stmt|;
comment|/* list of dependencies */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|common_symbol
argument_list|)
name|common
expr_stmt|;
comment|/* list of common symbols */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|module
argument_list|)
name|modules
expr_stmt|;
comment|/* modules in this file */
name|TAILQ_ENTRY
argument_list|(
argument|linker_file
argument_list|)
name|loaded
expr_stmt|;
comment|/* preload dependency support */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Object implementing a class of file (a.out, elf, etc.)  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|linker_class
modifier|*
name|linker_class_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|linker_class
argument_list|)
name|linker_class_list_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|linker_class
block|{
name|KOBJ_CLASS_FIELDS
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|linker_class
argument_list|)
name|link
expr_stmt|;
comment|/* list of all file classes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The "file" for the kernel.  */
end_comment

begin_decl_stmt
specifier|extern
name|linker_file_t
name|linker_kernel_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Add a new file class to the linker.  */
end_comment

begin_function_decl
name|int
name|linker_add_class
parameter_list|(
name|linker_class_t
name|_cls
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Load a kernel module.  */
end_comment

begin_function_decl
name|int
name|linker_load_module
parameter_list|(
specifier|const
name|char
modifier|*
name|_kldname
parameter_list|,
specifier|const
name|char
modifier|*
name|_modname
parameter_list|,
name|struct
name|linker_file
modifier|*
name|_parent
parameter_list|,
name|struct
name|mod_depend
modifier|*
name|_verinfo
parameter_list|,
name|struct
name|linker_file
modifier|*
modifier|*
name|_lfpp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Obtain a reference to a module, loading it if required.  */
end_comment

begin_function_decl
name|int
name|linker_reference_module
parameter_list|(
specifier|const
name|char
modifier|*
name|_modname
parameter_list|,
name|struct
name|mod_depend
modifier|*
name|_verinfo
parameter_list|,
name|linker_file_t
modifier|*
name|_result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Release a reference to a module, unloading it if there are no more  * references.  Note that one should either provide a module name and  * optional version info or a linker file, but not both.  */
end_comment

begin_function_decl
name|int
name|linker_release_module
parameter_list|(
specifier|const
name|char
modifier|*
name|_modname
parameter_list|,
name|struct
name|mod_depend
modifier|*
name|_verinfo
parameter_list|,
name|linker_file_t
name|_file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find a currently loaded file given its filename.  */
end_comment

begin_function_decl
name|linker_file_t
name|linker_find_file_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|_filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find a currently loaded file given its file id.  */
end_comment

begin_function_decl
name|linker_file_t
name|linker_find_file_by_id
parameter_list|(
name|int
name|_fileid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Called from a class handler when a file is laoded.  */
end_comment

begin_function_decl
name|linker_file_t
name|linker_make_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_filename
parameter_list|,
name|linker_class_t
name|_cls
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Unload a file, freeing up memory.  */
end_comment

begin_function_decl
name|int
name|linker_file_unload
parameter_list|(
name|linker_file_t
name|_file
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add a dependency to a file.  */
end_comment

begin_function_decl
name|int
name|linker_file_add_dependency
parameter_list|(
name|linker_file_t
name|_file
parameter_list|,
name|linker_file_t
name|_dep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Lookup a symbol in a file.  If deps is TRUE, look in dependencies  * if not found in file.  */
end_comment

begin_function_decl
name|caddr_t
name|linker_file_lookup_symbol
parameter_list|(
name|linker_file_t
name|_file
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|,
name|int
name|_deps
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Lookup a linker set in a file.  Return pointers to the first entry,  * last + 1, and count of entries.  Use: for (p = start; p< stop; p++) {}  * void *start is really: "struct yoursetmember ***start;"  */
end_comment

begin_function_decl
name|int
name|linker_file_lookup_set
parameter_list|(
name|linker_file_t
name|_file
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|,
name|void
modifier|*
name|_start
parameter_list|,
name|void
modifier|*
name|_stop
parameter_list|,
name|int
modifier|*
name|_count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This routine is responsible for finding dependencies of userland  * initiated kldload(2)'s of files.  */
end_comment

begin_function_decl
name|int
name|linker_load_dependencies
parameter_list|(
name|linker_file_t
name|_lf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * DDB Helpers, tuned specifically for ddb/db_kld.c  */
end_comment

begin_function_decl
name|int
name|linker_ddb_lookup
parameter_list|(
specifier|const
name|char
modifier|*
name|_symstr
parameter_list|,
name|c_linker_sym_t
modifier|*
name|_sym
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linker_ddb_search_symbol
parameter_list|(
name|caddr_t
name|_value
parameter_list|,
name|c_linker_sym_t
modifier|*
name|_sym
parameter_list|,
name|long
modifier|*
name|_diffp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linker_ddb_symbol_values
parameter_list|(
name|c_linker_sym_t
name|_sym
parameter_list|,
name|linker_symval_t
modifier|*
name|_symval
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

begin_comment
comment|/*  * Module information subtypes  */
end_comment

begin_define
define|#
directive|define
name|MODINFO_END
value|0x0000
end_define

begin_comment
comment|/* End of list */
end_comment

begin_define
define|#
directive|define
name|MODINFO_NAME
value|0x0001
end_define

begin_comment
comment|/* Name of module (string) */
end_comment

begin_define
define|#
directive|define
name|MODINFO_TYPE
value|0x0002
end_define

begin_comment
comment|/* Type of module (string) */
end_comment

begin_define
define|#
directive|define
name|MODINFO_ADDR
value|0x0003
end_define

begin_comment
comment|/* Loaded address */
end_comment

begin_define
define|#
directive|define
name|MODINFO_SIZE
value|0x0004
end_define

begin_comment
comment|/* Size of module */
end_comment

begin_define
define|#
directive|define
name|MODINFO_EMPTY
value|0x0005
end_define

begin_comment
comment|/* Has been deleted */
end_comment

begin_define
define|#
directive|define
name|MODINFO_ARGS
value|0x0006
end_define

begin_comment
comment|/* Parameters string */
end_comment

begin_define
define|#
directive|define
name|MODINFO_METADATA
value|0x8000
end_define

begin_comment
comment|/* Module-specfic */
end_comment

begin_define
define|#
directive|define
name|MODINFOMD_AOUTEXEC
value|0x0001
end_define

begin_comment
comment|/* a.out exec header */
end_comment

begin_define
define|#
directive|define
name|MODINFOMD_ELFHDR
value|0x0002
end_define

begin_comment
comment|/* ELF header */
end_comment

begin_define
define|#
directive|define
name|MODINFOMD_SSYM
value|0x0003
end_define

begin_comment
comment|/* start of symbols */
end_comment

begin_define
define|#
directive|define
name|MODINFOMD_ESYM
value|0x0004
end_define

begin_comment
comment|/* end of symbols */
end_comment

begin_define
define|#
directive|define
name|MODINFOMD_DYNAMIC
value|0x0005
end_define

begin_comment
comment|/* _DYNAMIC pointer */
end_comment

begin_comment
comment|/* These values are MD on these two platforms */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__sparc64__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MODINFOMD_ENVP
value|0x0006
end_define

begin_comment
comment|/* envp[] */
end_comment

begin_define
define|#
directive|define
name|MODINFOMD_HOWTO
value|0x0007
end_define

begin_comment
comment|/* boothowto */
end_comment

begin_define
define|#
directive|define
name|MODINFOMD_KERNEND
value|0x0008
end_define

begin_comment
comment|/* kernend */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MODINFOMD_SHDR
value|0x0009
end_define

begin_comment
comment|/* section header table */
end_comment

begin_define
define|#
directive|define
name|MODINFOMD_NOCOPY
value|0x8000
end_define

begin_comment
comment|/* don't copy this metadata to the kernel */
end_comment

begin_define
define|#
directive|define
name|MODINFOMD_DEPLIST
value|(0x4001 | MODINFOMD_NOCOPY)
end_define

begin_comment
comment|/* depends on */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MD_FETCH
parameter_list|(
name|mdp
parameter_list|,
name|info
parameter_list|,
name|type
parameter_list|)
value|({ \ 	type *__p; \ 	__p = (type *)preload_search_info((mdp), MODINFO_METADATA | (info)); \ 	__p ? *__p : 0; \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINKER_HINTS_VERSION
value|1
end_define

begin_comment
comment|/* linker.hints file version */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Module lookup  */
end_comment

begin_decl_stmt
specifier|extern
name|caddr_t
name|preload_metadata
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|caddr_t
name|preload_search_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|caddr_t
name|preload_search_by_type
parameter_list|(
specifier|const
name|char
modifier|*
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|caddr_t
name|preload_search_next_name
parameter_list|(
name|caddr_t
name|_base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|caddr_t
name|preload_search_info
parameter_list|(
name|caddr_t
name|_mod
parameter_list|,
name|int
name|_inf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|preload_delete_name
parameter_list|(
specifier|const
name|char
modifier|*
name|_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|preload_bootstrap_relocate
parameter_list|(
name|vm_offset_t
name|_offset
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KLD_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|kld_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KLD_DEBUG_FILE
value|1
end_define

begin_comment
comment|/* file load/unload */
end_comment

begin_define
define|#
directive|define
name|KLD_DEBUG_SYM
value|2
end_define

begin_comment
comment|/* symbol lookup */
end_comment

begin_define
define|#
directive|define
name|KLD_DPF
parameter_list|(
name|cat
parameter_list|,
name|args
parameter_list|)
define|\
value|do {							\ 		if (kld_debug& KLD_DEBUG_##cat) printf args;	\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KLD_DPF
parameter_list|(
name|cat
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|Elf_Addr
name|elf_lookup_fn
parameter_list|(
name|linker_file_t
parameter_list|,
name|Elf_Size
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Support functions */
end_comment

begin_function_decl
name|int
name|elf_reloc
parameter_list|(
name|linker_file_t
name|_lf
parameter_list|,
name|Elf_Addr
name|base
parameter_list|,
specifier|const
name|void
modifier|*
name|_rel
parameter_list|,
name|int
name|_type
parameter_list|,
name|elf_lookup_fn
name|_lu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_reloc_local
parameter_list|(
name|linker_file_t
name|_lf
parameter_list|,
name|Elf_Addr
name|base
parameter_list|,
specifier|const
name|void
modifier|*
name|_rel
parameter_list|,
name|int
name|_type
parameter_list|,
name|elf_lookup_fn
name|_lu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|Elf_Sym
modifier|*
name|elf_get_sym
parameter_list|(
name|linker_file_t
name|_lf
parameter_list|,
name|Elf_Size
name|_symidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|elf_get_symname
parameter_list|(
name|linker_file_t
name|_lf
parameter_list|,
name|Elf_Size
name|_symidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_cpu_load_file
parameter_list|(
name|linker_file_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_cpu_unload_file
parameter_list|(
name|linker_file_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* values for type */
end_comment

begin_define
define|#
directive|define
name|ELF_RELOC_REL
value|1
end_define

begin_define
define|#
directive|define
name|ELF_RELOC_RELA
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_struct
struct|struct
name|kld_file_stat
block|{
name|int
name|version
decl_stmt|;
comment|/* set to sizeof(linker_file_stat) */
name|char
name|name
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|int
name|refs
decl_stmt|;
name|int
name|id
decl_stmt|;
name|caddr_t
name|address
decl_stmt|;
comment|/* load address */
name|size_t
name|size
decl_stmt|;
comment|/* size in bytes */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kld_sym_lookup
block|{
name|int
name|version
decl_stmt|;
comment|/* set to sizeof(struct kld_sym_lookup) */
name|char
modifier|*
name|symname
decl_stmt|;
comment|/* Symbol name we are looking up */
name|u_long
name|symvalue
decl_stmt|;
name|size_t
name|symsize
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KLDSYM_LOOKUP
value|1
end_define

begin_comment
comment|/*  * Flags for kldunloadf() and linker_file_unload()  */
end_comment

begin_define
define|#
directive|define
name|LINKER_UNLOAD_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|LINKER_UNLOAD_FORCE
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|kldload
parameter_list|(
specifier|const
name|char
modifier|*
name|_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldunload
parameter_list|(
name|int
name|_fileid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldunloadf
parameter_list|(
name|int
name|_fileid
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldfind
parameter_list|(
specifier|const
name|char
modifier|*
name|_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldnext
parameter_list|(
name|int
name|_fileid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldstat
parameter_list|(
name|int
name|_fileid
parameter_list|,
name|struct
name|kld_file_stat
modifier|*
name|_stat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldfirstmod
parameter_list|(
name|int
name|_fileid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldsym
parameter_list|(
name|int
name|_fileid
parameter_list|,
name|int
name|_cmd
parameter_list|,
name|void
modifier|*
name|_data
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_LINKER_H_ */
end_comment

end_unit

