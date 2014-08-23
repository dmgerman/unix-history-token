begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013, Joyent, Inc. All rights reserved.  * Copyright (c) 2012 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_IMPL_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/objfs.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/bitmap.h>
end_include

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<libctf.h>
end_include

begin_include
include|#
directive|include
file|<dtrace.h>
end_include

begin_include
include|#
directive|include
file|<gelf.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_include
include|#
directive|include
file|<synch.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
include|#
directive|include
file|<dt_parser.h>
include|#
directive|include
file|<dt_regset.h>
include|#
directive|include
file|<dt_inttab.h>
include|#
directive|include
file|<dt_strtab.h>
include|#
directive|include
file|<dt_ident.h>
include|#
directive|include
file|<dt_list.h>
include|#
directive|include
file|<dt_decl.h>
include|#
directive|include
file|<dt_as.h>
include|#
directive|include
file|<dt_proc.h>
include|#
directive|include
file|<dt_dof.h>
include|#
directive|include
file|<dt_pcb.h>
include|#
directive|include
file|<dt_pq.h>
struct_decl|struct
name|dt_module
struct_decl|;
comment|/* see below */
struct_decl|struct
name|dt_pfdict
struct_decl|;
comment|/* see<dt_printf.h> */
struct_decl|struct
name|dt_arg
struct_decl|;
comment|/* see below */
struct_decl|struct
name|dt_provider
struct_decl|;
comment|/* see<dt_provider.h> */
struct_decl|struct
name|dt_xlator
struct_decl|;
comment|/* see<dt_xlator.h> */
typedef|typedef
struct|struct
name|dt_intrinsic
block|{
specifier|const
name|char
modifier|*
name|din_name
decl_stmt|;
comment|/* string name of the intrinsic type */
name|ctf_encoding_t
name|din_data
decl_stmt|;
comment|/* integer or floating-point CTF encoding */
name|uint_t
name|din_kind
decl_stmt|;
comment|/* CTF type kind to instantiate */
block|}
name|dt_intrinsic_t
typedef|;
typedef|typedef
struct|struct
name|dt_typedef
block|{
specifier|const
name|char
modifier|*
name|dty_src
decl_stmt|;
comment|/* string name of typedef source type */
specifier|const
name|char
modifier|*
name|dty_dst
decl_stmt|;
comment|/* string name of typedef destination type */
block|}
name|dt_typedef_t
typedef|;
typedef|typedef
struct|struct
name|dt_intdesc
block|{
specifier|const
name|char
modifier|*
name|did_name
decl_stmt|;
comment|/* string name of the integer type */
name|ctf_file_t
modifier|*
name|did_ctfp
decl_stmt|;
comment|/* CTF container for this type reference */
name|ctf_id_t
name|did_type
decl_stmt|;
comment|/* CTF type reference for this type */
name|uintmax_t
name|did_limit
decl_stmt|;
comment|/* maximum positive value held by type */
block|}
name|dt_intdesc_t
typedef|;
typedef|typedef
struct|struct
name|dt_modops
block|{
name|uint_t
function_decl|(
modifier|*
name|do_syminit
function_decl|)
parameter_list|(
name|struct
name|dt_module
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|do_symsort
function_decl|)
parameter_list|(
name|struct
name|dt_module
modifier|*
parameter_list|)
function_decl|;
name|GElf_Sym
modifier|*
function_decl|(
modifier|*
name|do_symname
function_decl|)
parameter_list|(
name|struct
name|dt_module
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|GElf_Sym
modifier|*
parameter_list|,
name|uint_t
modifier|*
parameter_list|)
function_decl|;
name|GElf_Sym
modifier|*
function_decl|(
modifier|*
name|do_symaddr
function_decl|)
parameter_list|(
name|struct
name|dt_module
modifier|*
parameter_list|,
name|GElf_Addr
parameter_list|,
name|GElf_Sym
modifier|*
parameter_list|,
name|uint_t
modifier|*
parameter_list|)
function_decl|;
block|}
name|dt_modops_t
typedef|;
typedef|typedef
struct|struct
name|dt_arg
block|{
name|int
name|da_ndx
decl_stmt|;
comment|/* index of this argument */
name|int
name|da_mapping
decl_stmt|;
comment|/* mapping of argument indices to arguments */
name|ctf_id_t
name|da_type
decl_stmt|;
comment|/* type of argument */
name|ctf_file_t
modifier|*
name|da_ctfp
decl_stmt|;
comment|/* CTF container for type */
name|dt_ident_t
modifier|*
name|da_xlator
decl_stmt|;
comment|/* translator, if any */
name|struct
name|dt_arg
modifier|*
name|da_next
decl_stmt|;
comment|/* next argument */
block|}
name|dt_arg_t
typedef|;
typedef|typedef
struct|struct
name|dt_sym
block|{
name|uint_t
name|ds_symid
decl_stmt|;
comment|/* id of corresponding symbol */
name|uint_t
name|ds_next
decl_stmt|;
comment|/* index of next element in hash chain */
block|}
name|dt_sym_t
typedef|;
typedef|typedef
struct|struct
name|dt_module
block|{
name|dt_list_t
name|dm_list
decl_stmt|;
comment|/* list forward/back pointers */
name|char
name|dm_name
index|[
name|DTRACE_MODNAMELEN
index|]
decl_stmt|;
comment|/* string name of module */
name|char
name|dm_file
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* file path of module (if any) */
name|struct
name|dt_module
modifier|*
name|dm_next
decl_stmt|;
comment|/* pointer to next module in hash chain */
specifier|const
name|dt_modops_t
modifier|*
name|dm_ops
decl_stmt|;
comment|/* pointer to data model's ops vector */
name|Elf
modifier|*
name|dm_elf
decl_stmt|;
comment|/* libelf handle for module object */
name|objfs_info_t
name|dm_info
decl_stmt|;
comment|/* object filesystem private info */
name|ctf_sect_t
name|dm_symtab
decl_stmt|;
comment|/* symbol table for module */
name|ctf_sect_t
name|dm_strtab
decl_stmt|;
comment|/* string table for module */
name|ctf_sect_t
name|dm_ctdata
decl_stmt|;
comment|/* CTF data for module */
name|ctf_file_t
modifier|*
name|dm_ctfp
decl_stmt|;
comment|/* CTF container handle */
name|uint_t
modifier|*
name|dm_symbuckets
decl_stmt|;
comment|/* symbol table hash buckets (chain indices) */
name|dt_sym_t
modifier|*
name|dm_symchains
decl_stmt|;
comment|/* symbol table hash chains buffer */
name|void
modifier|*
name|dm_asmap
decl_stmt|;
comment|/* symbol pointers sorted by value */
name|uint_t
name|dm_symfree
decl_stmt|;
comment|/* index of next free hash element */
name|uint_t
name|dm_nsymbuckets
decl_stmt|;
comment|/* number of elements in bucket array */
name|uint_t
name|dm_nsymelems
decl_stmt|;
comment|/* number of elements in hash table */
name|uint_t
name|dm_asrsv
decl_stmt|;
comment|/* actual reserved size of dm_asmap */
name|uint_t
name|dm_aslen
decl_stmt|;
comment|/* number of entries in dm_asmap */
name|uint_t
name|dm_flags
decl_stmt|;
comment|/* module flags (see below) */
name|int
name|dm_modid
decl_stmt|;
comment|/* modinfo(1M) module identifier */
name|GElf_Addr
name|dm_text_va
decl_stmt|;
comment|/* virtual address of text section */
name|GElf_Xword
name|dm_text_size
decl_stmt|;
comment|/* size in bytes of text section */
name|GElf_Addr
name|dm_data_va
decl_stmt|;
comment|/* virtual address of data section */
name|GElf_Xword
name|dm_data_size
decl_stmt|;
comment|/* size in bytes of data section */
name|GElf_Addr
name|dm_bss_va
decl_stmt|;
comment|/* virtual address of BSS */
name|GElf_Xword
name|dm_bss_size
decl_stmt|;
comment|/* size in bytes of BSS */
name|dt_idhash_t
modifier|*
name|dm_extern
decl_stmt|;
comment|/* external symbol definitions */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
name|caddr_t
name|dm_reloc_offset
decl_stmt|;
comment|/* Symbol relocation offset. */
name|uintptr_t
modifier|*
name|dm_sec_offsets
decl_stmt|;
endif|#
directive|endif
name|pid_t
name|dm_pid
decl_stmt|;
comment|/* pid for this module */
name|uint_t
name|dm_nctflibs
decl_stmt|;
comment|/* number of ctf children libraries */
name|ctf_file_t
modifier|*
modifier|*
name|dm_libctfp
decl_stmt|;
comment|/* process library ctf pointers */
name|char
modifier|*
modifier|*
name|dm_libctfn
decl_stmt|;
comment|/* names of process ctf containers */
block|}
name|dt_module_t
typedef|;
define|#
directive|define
name|DT_DM_LOADED
value|0x1
comment|/* module symbol and type data is loaded */
define|#
directive|define
name|DT_DM_KERNEL
value|0x2
comment|/* module is associated with a kernel object */
define|#
directive|define
name|DT_DM_PRIMARY
value|0x4
comment|/* module is a krtld primary kernel object */
typedef|typedef
struct|struct
name|dt_provmod
block|{
name|char
modifier|*
name|dp_name
decl_stmt|;
comment|/* name of provider module */
name|struct
name|dt_provmod
modifier|*
name|dp_next
decl_stmt|;
comment|/* next module */
block|}
name|dt_provmod_t
typedef|;
typedef|typedef
struct|struct
name|dt_ahashent
block|{
name|struct
name|dt_ahashent
modifier|*
name|dtahe_prev
decl_stmt|;
comment|/* prev on hash chain */
name|struct
name|dt_ahashent
modifier|*
name|dtahe_next
decl_stmt|;
comment|/* next on hash chain */
name|struct
name|dt_ahashent
modifier|*
name|dtahe_prevall
decl_stmt|;
comment|/* prev on list of all */
name|struct
name|dt_ahashent
modifier|*
name|dtahe_nextall
decl_stmt|;
comment|/* next on list of all */
name|uint64_t
name|dtahe_hashval
decl_stmt|;
comment|/* hash value */
name|size_t
name|dtahe_size
decl_stmt|;
comment|/* size of data */
name|dtrace_aggdata_t
name|dtahe_data
decl_stmt|;
comment|/* data */
name|void
function_decl|(
modifier|*
name|dtahe_aggregate
function_decl|)
parameter_list|(
name|int64_t
modifier|*
parameter_list|,
name|int64_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/* function */
block|}
name|dt_ahashent_t
typedef|;
typedef|typedef
struct|struct
name|dt_ahash
block|{
name|dt_ahashent_t
modifier|*
modifier|*
name|dtah_hash
decl_stmt|;
comment|/* hash table */
name|dt_ahashent_t
modifier|*
name|dtah_all
decl_stmt|;
comment|/* list of all elements */
name|size_t
name|dtah_size
decl_stmt|;
comment|/* size of hash table */
block|}
name|dt_ahash_t
typedef|;
typedef|typedef
struct|struct
name|dt_aggregate
block|{
name|dtrace_bufdesc_t
name|dtat_buf
decl_stmt|;
comment|/* buf aggregation snapshot */
name|int
name|dtat_flags
decl_stmt|;
comment|/* aggregate flags */
name|processorid_t
name|dtat_ncpus
decl_stmt|;
comment|/* number of CPUs in aggregate */
name|processorid_t
modifier|*
name|dtat_cpus
decl_stmt|;
comment|/* CPUs in aggregate */
name|processorid_t
name|dtat_ncpu
decl_stmt|;
comment|/* size of dtat_cpus array */
name|processorid_t
name|dtat_maxcpu
decl_stmt|;
comment|/* maximum number of CPUs */
name|dt_ahash_t
name|dtat_hash
decl_stmt|;
comment|/* aggregate hash table */
block|}
name|dt_aggregate_t
typedef|;
typedef|typedef
struct|struct
name|dt_print_aggdata
block|{
name|dtrace_hdl_t
modifier|*
name|dtpa_dtp
decl_stmt|;
comment|/* pointer to libdtrace handle */
name|dtrace_aggvarid_t
name|dtpa_id
decl_stmt|;
comment|/* aggregation variable of interest */
name|FILE
modifier|*
name|dtpa_fp
decl_stmt|;
comment|/* file pointer */
name|int
name|dtpa_allunprint
decl_stmt|;
comment|/* print only unprinted aggregations */
name|int
name|dtpa_agghist
decl_stmt|;
comment|/* print aggregation as histogram */
name|int
name|dtpa_agghisthdr
decl_stmt|;
comment|/* aggregation histogram hdr printed */
name|int
name|dtpa_aggpack
decl_stmt|;
comment|/* pack quantized aggregations */
block|}
name|dt_print_aggdata_t
typedef|;
typedef|typedef
struct|struct
name|dt_dirpath
block|{
name|dt_list_t
name|dir_list
decl_stmt|;
comment|/* linked-list forward/back pointers */
name|char
modifier|*
name|dir_path
decl_stmt|;
comment|/* directory pathname */
block|}
name|dt_dirpath_t
typedef|;
typedef|typedef
struct|struct
name|dt_lib_depend
block|{
name|dt_list_t
name|dtld_deplist
decl_stmt|;
comment|/* linked-list forward/back pointers */
name|char
modifier|*
name|dtld_library
decl_stmt|;
comment|/* library name */
name|char
modifier|*
name|dtld_libpath
decl_stmt|;
comment|/* library pathname */
name|uint_t
name|dtld_finish
decl_stmt|;
comment|/* completion time in tsort for lib */
name|uint_t
name|dtld_start
decl_stmt|;
comment|/* starting time in tsort for lib */
name|uint_t
name|dtld_loaded
decl_stmt|;
comment|/* boolean: is this library loaded */
name|dt_list_t
name|dtld_dependencies
decl_stmt|;
comment|/* linked-list of lib dependencies */
name|dt_list_t
name|dtld_dependents
decl_stmt|;
comment|/* linked-list of lib dependents */
block|}
name|dt_lib_depend_t
typedef|;
typedef|typedef
name|uint32_t
name|dt_version_t
typedef|;
comment|/* encoded version (see below) */
struct|struct
name|dtrace_hdl
block|{
specifier|const
name|dtrace_vector_t
modifier|*
name|dt_vector
decl_stmt|;
comment|/* library vector, if vectored open */
name|void
modifier|*
name|dt_varg
decl_stmt|;
comment|/* vector argument, if vectored open */
name|dtrace_conf_t
name|dt_conf
decl_stmt|;
comment|/* DTrace driver configuration profile */
name|char
name|dt_errmsg
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* buffer for formatted syntax error msgs */
specifier|const
name|char
modifier|*
name|dt_errtag
decl_stmt|;
comment|/* tag used with last call to dt_set_errmsg() */
name|dt_pcb_t
modifier|*
name|dt_pcb
decl_stmt|;
comment|/* pointer to current parsing control block */
name|ulong_t
name|dt_gen
decl_stmt|;
comment|/* compiler generation number */
name|dt_list_t
name|dt_programs
decl_stmt|;
comment|/* linked list of dtrace_prog_t's */
name|dt_list_t
name|dt_xlators
decl_stmt|;
comment|/* linked list of dt_xlator_t's */
name|struct
name|dt_xlator
modifier|*
modifier|*
name|dt_xlatormap
decl_stmt|;
comment|/* dt_xlator_t's indexed by dx_id */
name|id_t
name|dt_xlatorid
decl_stmt|;
comment|/* next dt_xlator_t id to assign */
name|dt_ident_t
modifier|*
name|dt_externs
decl_stmt|;
comment|/* linked list of external symbol identifiers */
name|dt_idhash_t
modifier|*
name|dt_macros
decl_stmt|;
comment|/* hash table of macro variable identifiers */
name|dt_idhash_t
modifier|*
name|dt_aggs
decl_stmt|;
comment|/* hash table of aggregation identifiers */
name|dt_idhash_t
modifier|*
name|dt_globals
decl_stmt|;
comment|/* hash table of global identifiers */
name|dt_idhash_t
modifier|*
name|dt_tls
decl_stmt|;
comment|/* hash table of thread-local identifiers */
name|dt_list_t
name|dt_modlist
decl_stmt|;
comment|/* linked list of dt_module_t's */
name|dt_module_t
modifier|*
modifier|*
name|dt_mods
decl_stmt|;
comment|/* hash table of dt_module_t's */
name|uint_t
name|dt_modbuckets
decl_stmt|;
comment|/* number of module hash buckets */
name|uint_t
name|dt_nmods
decl_stmt|;
comment|/* number of modules in hash and list */
name|dt_provmod_t
modifier|*
name|dt_provmod
decl_stmt|;
comment|/* linked list of provider modules */
name|dt_module_t
modifier|*
name|dt_exec
decl_stmt|;
comment|/* pointer to executable module */
name|dt_module_t
modifier|*
name|dt_rtld
decl_stmt|;
comment|/* pointer to run-time linker module */
name|dt_module_t
modifier|*
name|dt_cdefs
decl_stmt|;
comment|/* pointer to C dynamic type module */
name|dt_module_t
modifier|*
name|dt_ddefs
decl_stmt|;
comment|/* pointer to D dynamic type module */
name|dt_list_t
name|dt_provlist
decl_stmt|;
comment|/* linked list of dt_provider_t's */
name|struct
name|dt_provider
modifier|*
modifier|*
name|dt_provs
decl_stmt|;
comment|/* hash table of dt_provider_t's */
name|uint_t
name|dt_provbuckets
decl_stmt|;
comment|/* number of provider hash buckets */
name|uint_t
name|dt_nprovs
decl_stmt|;
comment|/* number of providers in hash and list */
name|dt_proc_hash_t
modifier|*
name|dt_procs
decl_stmt|;
comment|/* hash table of grabbed process handles */
name|char
modifier|*
modifier|*
name|dt_proc_env
decl_stmt|;
comment|/* additional environment variables */
name|dt_intdesc_t
name|dt_ints
index|[
literal|6
index|]
decl_stmt|;
comment|/* cached integer type descriptions */
name|ctf_id_t
name|dt_type_func
decl_stmt|;
comment|/* cached CTF identifier for function type */
name|ctf_id_t
name|dt_type_fptr
decl_stmt|;
comment|/* cached CTF identifier for function pointer */
name|ctf_id_t
name|dt_type_str
decl_stmt|;
comment|/* cached CTF identifier for string type */
name|ctf_id_t
name|dt_type_dyn
decl_stmt|;
comment|/* cached CTF identifier for<DYN> type */
name|ctf_id_t
name|dt_type_stack
decl_stmt|;
comment|/* cached CTF identifier for stack type */
name|ctf_id_t
name|dt_type_symaddr
decl_stmt|;
comment|/* cached CTF identifier for _symaddr type */
name|ctf_id_t
name|dt_type_usymaddr
decl_stmt|;
comment|/* cached CTF ident. for _usymaddr type */
name|size_t
name|dt_maxprobe
decl_stmt|;
comment|/* max enabled probe ID */
name|dtrace_eprobedesc_t
modifier|*
modifier|*
name|dt_edesc
decl_stmt|;
comment|/* enabled probe descriptions */
name|dtrace_probedesc_t
modifier|*
modifier|*
name|dt_pdesc
decl_stmt|;
comment|/* probe descriptions for enabled prbs */
name|size_t
name|dt_maxagg
decl_stmt|;
comment|/* max aggregation ID */
name|dtrace_aggdesc_t
modifier|*
modifier|*
name|dt_aggdesc
decl_stmt|;
comment|/* aggregation descriptions */
name|int
name|dt_maxformat
decl_stmt|;
comment|/* max format ID */
name|void
modifier|*
modifier|*
name|dt_formats
decl_stmt|;
comment|/* pointer to format array */
name|int
name|dt_maxstrdata
decl_stmt|;
comment|/* max strdata ID */
name|char
modifier|*
modifier|*
name|dt_strdata
decl_stmt|;
comment|/* pointer to strdata array */
name|dt_aggregate_t
name|dt_aggregate
decl_stmt|;
comment|/* aggregate */
name|dt_pq_t
modifier|*
name|dt_bufq
decl_stmt|;
comment|/* CPU-specific data queue */
name|struct
name|dt_pfdict
modifier|*
name|dt_pfdict
decl_stmt|;
comment|/* dictionary of printf conversions */
name|dt_version_t
name|dt_vmax
decl_stmt|;
comment|/* optional ceiling on program API binding */
name|dtrace_attribute_t
name|dt_amin
decl_stmt|;
comment|/* optional floor on program attributes */
name|char
modifier|*
name|dt_cpp_path
decl_stmt|;
comment|/* pathname of cpp(1) to invoke if needed */
name|char
modifier|*
modifier|*
name|dt_cpp_argv
decl_stmt|;
comment|/* argument vector for exec'ing cpp(1) */
name|int
name|dt_cpp_argc
decl_stmt|;
comment|/* count of initialized cpp(1) arguments */
name|int
name|dt_cpp_args
decl_stmt|;
comment|/* size of dt_cpp_argv[] array */
name|char
modifier|*
name|dt_ld_path
decl_stmt|;
comment|/* pathname of ld(1) to invoke if needed */
name|dt_list_t
name|dt_lib_path
decl_stmt|;
comment|/* linked-list forming library search path */
name|uint_t
name|dt_lazyload
decl_stmt|;
comment|/* boolean:  set via -xlazyload */
name|uint_t
name|dt_droptags
decl_stmt|;
comment|/* boolean:  set via -xdroptags */
name|uint_t
name|dt_active
decl_stmt|;
comment|/* boolean:  set once tracing is active */
name|uint_t
name|dt_stopped
decl_stmt|;
comment|/* boolean:  set once tracing is stopped */
name|processorid_t
name|dt_beganon
decl_stmt|;
comment|/* CPU that executed BEGIN probe (if any) */
name|processorid_t
name|dt_endedon
decl_stmt|;
comment|/* CPU that executed END probe (if any) */
name|uint_t
name|dt_oflags
decl_stmt|;
comment|/* dtrace open-time options (see dtrace.h) */
name|uint_t
name|dt_cflags
decl_stmt|;
comment|/* dtrace compile-time options (see dtrace.h) */
name|uint_t
name|dt_dflags
decl_stmt|;
comment|/* dtrace link-time options (see dtrace.h) */
name|uint_t
name|dt_prcmode
decl_stmt|;
comment|/* dtrace process create mode (see dt_proc.h) */
name|uint_t
name|dt_linkmode
decl_stmt|;
comment|/* dtrace symbol linking mode (see below) */
name|uint_t
name|dt_linktype
decl_stmt|;
comment|/* dtrace link output file type (see below) */
name|uint_t
name|dt_xlatemode
decl_stmt|;
comment|/* dtrace translator linking mode (see below) */
name|uint_t
name|dt_stdcmode
decl_stmt|;
comment|/* dtrace stdc compatibility mode (see below) */
name|uint_t
name|dt_encoding
decl_stmt|;
comment|/* dtrace output encoding (see below) */
name|uint_t
name|dt_treedump
decl_stmt|;
comment|/* dtrace tree debug bitmap (see below) */
name|uint64_t
name|dt_options
index|[
name|DTRACEOPT_MAX
index|]
decl_stmt|;
comment|/* dtrace run-time options */
name|int
name|dt_version
decl_stmt|;
comment|/* library version requested by client */
name|int
name|dt_ctferr
decl_stmt|;
comment|/* error resulting from last CTF failure */
name|int
name|dt_errno
decl_stmt|;
comment|/* error resulting from last failed operation */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
specifier|const
name|char
modifier|*
name|dt_errfile
decl_stmt|;
name|int
name|dt_errline
decl_stmt|;
endif|#
directive|endif
name|int
name|dt_fd
decl_stmt|;
comment|/* file descriptor for dtrace pseudo-device */
name|int
name|dt_ftfd
decl_stmt|;
comment|/* file descriptor for fasttrap pseudo-device */
name|int
name|dt_fterr
decl_stmt|;
comment|/* saved errno from failed open of dt_ftfd */
name|int
name|dt_cdefs_fd
decl_stmt|;
comment|/* file descriptor for C CTF debugging cache */
name|int
name|dt_ddefs_fd
decl_stmt|;
comment|/* file descriptor for D CTF debugging cache */
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
name|int
name|dt_stdout_fd
decl_stmt|;
comment|/* file descriptor for saved stdout */
else|#
directive|else
name|FILE
modifier|*
name|dt_freopen_fp
decl_stmt|;
comment|/* file pointer for freopened stdout */
endif|#
directive|endif
name|dtrace_handle_err_f
modifier|*
name|dt_errhdlr
decl_stmt|;
comment|/* error handler, if any */
name|void
modifier|*
name|dt_errarg
decl_stmt|;
comment|/* error handler argument */
name|dtrace_prog_t
modifier|*
name|dt_errprog
decl_stmt|;
comment|/* error handler program, if any */
name|dtrace_handle_drop_f
modifier|*
name|dt_drophdlr
decl_stmt|;
comment|/* drop handler, if any */
name|void
modifier|*
name|dt_droparg
decl_stmt|;
comment|/* drop handler argument */
name|dtrace_handle_proc_f
modifier|*
name|dt_prochdlr
decl_stmt|;
comment|/* proc handler, if any */
name|void
modifier|*
name|dt_procarg
decl_stmt|;
comment|/* proc handler argument */
name|dtrace_handle_setopt_f
modifier|*
name|dt_setopthdlr
decl_stmt|;
comment|/* setopt handler, if any */
name|void
modifier|*
name|dt_setoptarg
decl_stmt|;
comment|/* setopt handler argument */
name|dtrace_status_t
name|dt_status
index|[
literal|2
index|]
decl_stmt|;
comment|/* status cache */
name|int
name|dt_statusgen
decl_stmt|;
comment|/* current status generation */
name|hrtime_t
name|dt_laststatus
decl_stmt|;
comment|/* last status */
name|hrtime_t
name|dt_lastswitch
decl_stmt|;
comment|/* last switch of buffer data */
name|hrtime_t
name|dt_lastagg
decl_stmt|;
comment|/* last snapshot of aggregation data */
name|char
modifier|*
name|dt_sprintf_buf
decl_stmt|;
comment|/* buffer for dtrace_sprintf() */
name|int
name|dt_sprintf_buflen
decl_stmt|;
comment|/* length of dtrace_sprintf() buffer */
specifier|const
name|char
modifier|*
name|dt_filetag
decl_stmt|;
comment|/* default filetag for dt_set_errmsg() */
name|char
modifier|*
name|dt_buffered_buf
decl_stmt|;
comment|/* buffer for buffered output */
name|size_t
name|dt_buffered_offs
decl_stmt|;
comment|/* current offset into buffered buffer */
name|size_t
name|dt_buffered_size
decl_stmt|;
comment|/* size of buffered buffer */
name|dtrace_handle_buffered_f
modifier|*
name|dt_bufhdlr
decl_stmt|;
comment|/* buffered handler, if any */
name|void
modifier|*
name|dt_bufarg
decl_stmt|;
comment|/* buffered handler argument */
name|dt_dof_t
name|dt_dof
decl_stmt|;
comment|/* DOF generation buffers (see dt_dof.c) */
name|struct
name|utsname
name|dt_uts
decl_stmt|;
comment|/* uname(2) information for system */
name|dt_list_t
name|dt_lib_dep
decl_stmt|;
comment|/* scratch linked-list of lib dependencies */
name|dt_list_t
name|dt_lib_dep_sorted
decl_stmt|;
comment|/* dependency sorted library list */
name|dtrace_flowkind_t
name|dt_flow
decl_stmt|;
comment|/* flow kind */
specifier|const
name|char
modifier|*
name|dt_prefix
decl_stmt|;
comment|/* recommended flow prefix */
name|int
name|dt_indent
decl_stmt|;
comment|/* recommended flow indent */
name|dtrace_epid_t
name|dt_last_epid
decl_stmt|;
comment|/* most recently consumed EPID */
name|uint64_t
name|dt_last_timestamp
decl_stmt|;
comment|/* most recently consumed timestamp */
block|}
struct|;
comment|/*  * Values for the user arg of the ECB.  */
define|#
directive|define
name|DT_ECB_DEFAULT
value|0
define|#
directive|define
name|DT_ECB_ERROR
value|1
comment|/*  * Values for the dt_linkmode property, which is used by the assembler when  * processing external symbol references.  User can set using -xlink=<mode>.  */
define|#
directive|define
name|DT_LINK_KERNEL
value|0
comment|/* kernel syms static, user syms dynamic */
define|#
directive|define
name|DT_LINK_PRIMARY
value|1
comment|/* primary kernel syms static, others dynamic */
define|#
directive|define
name|DT_LINK_DYNAMIC
value|2
comment|/* all symbols dynamic */
define|#
directive|define
name|DT_LINK_STATIC
value|3
comment|/* all symbols static */
comment|/*  * Values for the dt_linktype property, which is used by dtrace_program_link()  * to determine the type of output file that is desired by the client.  */
define|#
directive|define
name|DT_LTYP_ELF
value|0
comment|/* produce ELF containing DOF */
define|#
directive|define
name|DT_LTYP_DOF
value|1
comment|/* produce stand-alone DOF */
comment|/*  * Values for the dt_xlatemode property, which is used to determine whether  * references to dynamic translators are permitted.  Set using -xlate=<mode>.  */
define|#
directive|define
name|DT_XL_STATIC
value|0
comment|/* require xlators to be statically defined */
define|#
directive|define
name|DT_XL_DYNAMIC
value|1
comment|/* produce references to dynamic translators */
comment|/*  * Values for the dt_stdcmode property, which is used by the compiler when  * running cpp to determine the presence and setting of the __STDC__ macro.  */
define|#
directive|define
name|DT_STDC_XA
value|0
comment|/* ISO C + K&R C compat w/o ISO: __STDC__=0 */
define|#
directive|define
name|DT_STDC_XC
value|1
comment|/* Strict ISO C: __STDC__=1 */
define|#
directive|define
name|DT_STDC_XS
value|2
comment|/* K&R C: __STDC__ not defined */
define|#
directive|define
name|DT_STDC_XT
value|3
comment|/* ISO C + K&R C compat with ISO: __STDC__=0 */
comment|/*  * Values for the dt_encoding property, which is used to force a particular  * character encoding (overriding default behavior and/or automatic detection).  */
define|#
directive|define
name|DT_ENCODING_UNSET
value|0
define|#
directive|define
name|DT_ENCODING_ASCII
value|1
define|#
directive|define
name|DT_ENCODING_UTF8
value|2
comment|/*  * Macro to test whether a given pass bit is set in the dt_treedump bit-vector.  * If the bit for pass 'p' is set, the D compiler displays the parse tree for  * the program by printing it to stderr at the end of compiler pass 'p'.  */
define|#
directive|define
name|DT_TREEDUMP_PASS
parameter_list|(
name|dtp
parameter_list|,
name|p
parameter_list|)
value|((dtp)->dt_treedump& (1<< ((p) - 1)))
comment|/*  * Macros for accessing the cached CTF container and type ID for the common  * types "int", "string", and<DYN>, which we need to use frequently in the D  * compiler.  The DT_INT_* macro relies upon "int" being at index 0 in the  * _dtrace_ints_* tables in dt_open.c; the others are also set up there.  */
define|#
directive|define
name|DT_INT_CTFP
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_ints[0].did_ctfp)
define|#
directive|define
name|DT_INT_TYPE
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_ints[0].did_type)
define|#
directive|define
name|DT_FUNC_CTFP
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_ddefs->dm_ctfp)
define|#
directive|define
name|DT_FUNC_TYPE
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_type_func)
define|#
directive|define
name|DT_FPTR_CTFP
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_ddefs->dm_ctfp)
define|#
directive|define
name|DT_FPTR_TYPE
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_type_fptr)
define|#
directive|define
name|DT_STR_CTFP
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_ddefs->dm_ctfp)
define|#
directive|define
name|DT_STR_TYPE
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_type_str)
define|#
directive|define
name|DT_DYN_CTFP
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_ddefs->dm_ctfp)
define|#
directive|define
name|DT_DYN_TYPE
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_type_dyn)
define|#
directive|define
name|DT_STACK_CTFP
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_ddefs->dm_ctfp)
define|#
directive|define
name|DT_STACK_TYPE
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_type_stack)
define|#
directive|define
name|DT_SYMADDR_CTFP
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_ddefs->dm_ctfp)
define|#
directive|define
name|DT_SYMADDR_TYPE
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_type_symaddr)
define|#
directive|define
name|DT_USYMADDR_CTFP
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_ddefs->dm_ctfp)
define|#
directive|define
name|DT_USYMADDR_TYPE
parameter_list|(
name|dtp
parameter_list|)
value|((dtp)->dt_type_usymaddr)
comment|/*  * Actions and subroutines are both DT_NODE_FUNC nodes; to avoid confusing  * an action for a subroutine (or vice versa), we assure that the DT_ACT_*  * constants and the DIF_SUBR_* constants occupy non-overlapping ranges by  * starting the DT_ACT_* constants at DIF_SUBR_MAX + 1.  */
define|#
directive|define
name|DT_ACT_BASE
value|DIF_SUBR_MAX + 1
define|#
directive|define
name|DT_ACT
parameter_list|(
name|n
parameter_list|)
value|(DT_ACT_BASE + (n))
define|#
directive|define
name|DT_ACT_PRINTF
value|DT_ACT(0)
comment|/* printf() action */
define|#
directive|define
name|DT_ACT_TRACE
value|DT_ACT(1)
comment|/* trace() action */
define|#
directive|define
name|DT_ACT_TRACEMEM
value|DT_ACT(2)
comment|/* tracemem() action */
define|#
directive|define
name|DT_ACT_STACK
value|DT_ACT(3)
comment|/* stack() action */
define|#
directive|define
name|DT_ACT_STOP
value|DT_ACT(4)
comment|/* stop() action */
define|#
directive|define
name|DT_ACT_BREAKPOINT
value|DT_ACT(5)
comment|/* breakpoint() action */
define|#
directive|define
name|DT_ACT_PANIC
value|DT_ACT(6)
comment|/* panic() action */
define|#
directive|define
name|DT_ACT_SPECULATE
value|DT_ACT(7)
comment|/* speculate() action */
define|#
directive|define
name|DT_ACT_COMMIT
value|DT_ACT(8)
comment|/* commit() action */
define|#
directive|define
name|DT_ACT_DISCARD
value|DT_ACT(9)
comment|/* discard() action */
define|#
directive|define
name|DT_ACT_CHILL
value|DT_ACT(10)
comment|/* chill() action */
define|#
directive|define
name|DT_ACT_EXIT
value|DT_ACT(11)
comment|/* exit() action */
define|#
directive|define
name|DT_ACT_USTACK
value|DT_ACT(12)
comment|/* ustack() action */
define|#
directive|define
name|DT_ACT_PRINTA
value|DT_ACT(13)
comment|/* printa() action */
define|#
directive|define
name|DT_ACT_RAISE
value|DT_ACT(14)
comment|/* raise() action */
define|#
directive|define
name|DT_ACT_CLEAR
value|DT_ACT(15)
comment|/* clear() action */
define|#
directive|define
name|DT_ACT_NORMALIZE
value|DT_ACT(16)
comment|/* normalize() action */
define|#
directive|define
name|DT_ACT_DENORMALIZE
value|DT_ACT(17)
comment|/* denormalize() action */
define|#
directive|define
name|DT_ACT_TRUNC
value|DT_ACT(18)
comment|/* trunc() action */
define|#
directive|define
name|DT_ACT_SYSTEM
value|DT_ACT(19)
comment|/* system() action */
define|#
directive|define
name|DT_ACT_JSTACK
value|DT_ACT(20)
comment|/* jstack() action */
define|#
directive|define
name|DT_ACT_FTRUNCATE
value|DT_ACT(21)
comment|/* ftruncate() action */
define|#
directive|define
name|DT_ACT_FREOPEN
value|DT_ACT(22)
comment|/* freopen() action */
define|#
directive|define
name|DT_ACT_SYM
value|DT_ACT(23)
comment|/* sym()/func() actions */
define|#
directive|define
name|DT_ACT_MOD
value|DT_ACT(24)
comment|/* mod() action */
define|#
directive|define
name|DT_ACT_USYM
value|DT_ACT(25)
comment|/* usym()/ufunc() actions */
define|#
directive|define
name|DT_ACT_UMOD
value|DT_ACT(26)
comment|/* umod() action */
define|#
directive|define
name|DT_ACT_UADDR
value|DT_ACT(27)
comment|/* uaddr() action */
define|#
directive|define
name|DT_ACT_SETOPT
value|DT_ACT(28)
comment|/* setopt() action */
define|#
directive|define
name|DT_ACT_PRINT
value|DT_ACT(29)
comment|/* print() action */
define|#
directive|define
name|DT_ACT_PRINTM
value|DT_ACT(30)
comment|/* printm() action */
define|#
directive|define
name|DT_ACT_PRINTT
value|DT_ACT(31)
comment|/* printt() action */
comment|/*  * Sentinel to tell freopen() to restore the saved stdout.  This must not  * be ever valid for opening for write access via freopen(3C), which of  * course, "." never is.  */
define|#
directive|define
name|DT_FREOPEN_RESTORE
value|"."
define|#
directive|define
name|EDT_BASE
value|1000
comment|/* base value for libdtrace errnos */
enum|enum
block|{
name|EDT_VERSION
init|=
name|EDT_BASE
block|,
comment|/* client is requesting unsupported version */
name|EDT_VERSINVAL
block|,
comment|/* version string is invalid or overflows */
name|EDT_VERSUNDEF
block|,
comment|/* requested API version is not defined */
name|EDT_VERSREDUCED
block|,
comment|/* requested API version has been reduced */
name|EDT_CTF
block|,
comment|/* libctf called failed (dt_ctferr has more) */
name|EDT_COMPILER
block|,
comment|/* error in D program compilation */
name|EDT_NOTUPREG
block|,
comment|/* tuple register allocation failure */
name|EDT_NOMEM
block|,
comment|/* memory allocation failure */
name|EDT_INT2BIG
block|,
comment|/* integer limit exceeded */
name|EDT_STR2BIG
block|,
comment|/* string limit exceeded */
name|EDT_NOMOD
block|,
comment|/* unknown module name */
name|EDT_NOPROV
block|,
comment|/* unknown provider name */
name|EDT_NOPROBE
block|,
comment|/* unknown probe name */
name|EDT_NOSYM
block|,
comment|/* unknown symbol name */
name|EDT_NOSYMADDR
block|,
comment|/* no symbol corresponds to address */
name|EDT_NOTYPE
block|,
comment|/* unknown type name */
name|EDT_NOVAR
block|,
comment|/* unknown variable name */
name|EDT_NOAGG
block|,
comment|/* unknown aggregation name */
name|EDT_BADSCOPE
block|,
comment|/* improper use of type name scoping operator */
name|EDT_BADSPEC
block|,
comment|/* overspecified probe description */
name|EDT_BADSPCV
block|,
comment|/* bad macro variable in probe description */
name|EDT_BADID
block|,
comment|/* invalid probe identifier */
name|EDT_NOTLOADED
block|,
comment|/* module is not currently loaded */
name|EDT_NOCTF
block|,
comment|/* module does not contain any CTF data */
name|EDT_DATAMODEL
block|,
comment|/* module and program data models don't match */
name|EDT_DIFVERS
block|,
comment|/* library has newer DIF version than driver */
name|EDT_BADAGG
block|,
comment|/* unrecognized aggregating action */
name|EDT_FIO
block|,
comment|/* file i/o error */
name|EDT_DIFINVAL
block|,
comment|/* invalid DIF program */
name|EDT_DIFSIZE
block|,
comment|/* invalid DIF size */
name|EDT_DIFFAULT
block|,
comment|/* failed to copyin DIF program */
name|EDT_BADPROBE
block|,
comment|/* bad probe description */
name|EDT_BADPGLOB
block|,
comment|/* bad probe description globbing pattern */
name|EDT_NOSCOPE
block|,
comment|/* declaration scope stack underflow */
name|EDT_NODECL
block|,
comment|/* declaration stack underflow */
name|EDT_DMISMATCH
block|,
comment|/* record list does not match statement */
name|EDT_DOFFSET
block|,
comment|/* record data offset error */
name|EDT_DALIGN
block|,
comment|/* record data alignment error */
name|EDT_BADOPTNAME
block|,
comment|/* invalid dtrace_setopt option name */
name|EDT_BADOPTVAL
block|,
comment|/* invalid dtrace_setopt option value */
name|EDT_BADOPTCTX
block|,
comment|/* invalid dtrace_setopt option context */
name|EDT_CPPFORK
block|,
comment|/* failed to fork preprocessor */
name|EDT_CPPEXEC
block|,
comment|/* failed to exec preprocessor */
name|EDT_CPPENT
block|,
comment|/* preprocessor not found */
name|EDT_CPPERR
block|,
comment|/* unknown preprocessor error */
name|EDT_SYMOFLOW
block|,
comment|/* external symbol table overflow */
name|EDT_ACTIVE
block|,
comment|/* operation illegal when tracing is active */
name|EDT_DESTRUCTIVE
block|,
comment|/* destructive actions not allowed */
name|EDT_NOANON
block|,
comment|/* no anonymous tracing state */
name|EDT_ISANON
block|,
comment|/* can't claim anon state and enable probes */
name|EDT_ENDTOOBIG
block|,
comment|/* END enablings exceed size of prncpl buffer */
name|EDT_NOCONV
block|,
comment|/* failed to load type for printf conversion */
name|EDT_BADCONV
block|,
comment|/* incomplete printf conversion */
name|EDT_BADERROR
block|,
comment|/* invalid library ERROR action */
name|EDT_ERRABORT
block|,
comment|/* abort due to error */
name|EDT_DROPABORT
block|,
comment|/* abort due to drop */
name|EDT_DIRABORT
block|,
comment|/* abort explicitly directed */
name|EDT_BADRVAL
block|,
comment|/* invalid return value from callback */
name|EDT_BADNORMAL
block|,
comment|/* invalid normalization */
name|EDT_BUFTOOSMALL
block|,
comment|/* enabling exceeds size of buffer */
name|EDT_BADTRUNC
block|,
comment|/* invalid truncation */
name|EDT_BUSY
block|,
comment|/* device busy (active kernel debugger) */
name|EDT_ACCESS
block|,
comment|/* insufficient privileges to use DTrace */
name|EDT_NOENT
block|,
comment|/* dtrace device not available */
name|EDT_BRICKED
block|,
comment|/* abort due to systemic unresponsiveness */
name|EDT_HARDWIRE
block|,
comment|/* failed to load hard-wired definitions */
name|EDT_ELFVERSION
block|,
comment|/* libelf is out-of-date w.r.t libdtrace */
name|EDT_NOBUFFERED
block|,
comment|/* attempt to buffer output without handler */
name|EDT_UNSTABLE
block|,
comment|/* description matched unstable set of probes */
name|EDT_BADSETOPT
block|,
comment|/* invalid setopt library action */
name|EDT_BADSTACKPC
block|,
comment|/* invalid stack program counter size */
name|EDT_BADAGGVAR
block|,
comment|/* invalid aggregation variable identifier */
name|EDT_OVERSION
block|,
comment|/* client is requesting deprecated version */
name|EDT_ENABLING_ERR
block|,
comment|/* failed to enable probe */
name|EDT_NOPROBES
block|,
comment|/* no probes sites for declared provider */
name|EDT_CANTLOAD
comment|/* failed to load a module */
block|}
enum|;
comment|/*  * Interfaces for parsing and comparing DTrace attribute tuples, which describe  * stability and architectural binding information.  The dtrace_attribute_t  * structure and associated constant definitions are found in<sys/dtrace.h>.  */
specifier|extern
name|dtrace_attribute_t
name|dt_attr_min
parameter_list|(
name|dtrace_attribute_t
parameter_list|,
name|dtrace_attribute_t
parameter_list|)
function_decl|;
specifier|extern
name|dtrace_attribute_t
name|dt_attr_max
parameter_list|(
name|dtrace_attribute_t
parameter_list|,
name|dtrace_attribute_t
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|dt_attr_str
parameter_list|(
name|dtrace_attribute_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_attr_cmp
parameter_list|(
name|dtrace_attribute_t
parameter_list|,
name|dtrace_attribute_t
parameter_list|)
function_decl|;
comment|/*  * Interfaces for parsing and handling DTrace version strings.  Version binding  * is a feature of the D compiler that is handled completely independently of  * the DTrace kernel infrastructure, so the definitions are here in libdtrace.  * Version strings are compiled into an encoded uint32_t which can be compared  * using C comparison operators.  Version definitions are found in dt_open.c.  */
define|#
directive|define
name|DT_VERSION_STRMAX
value|16
comment|/* enough for "255.4095.4095\0" */
define|#
directive|define
name|DT_VERSION_MAJMAX
value|0xFF
comment|/* maximum major version number */
define|#
directive|define
name|DT_VERSION_MINMAX
value|0xFFF
comment|/* maximum minor version number */
define|#
directive|define
name|DT_VERSION_MICMAX
value|0xFFF
comment|/* maximum micro version number */
define|#
directive|define
name|DT_VERSION_NUMBER
parameter_list|(
name|M
parameter_list|,
name|m
parameter_list|,
name|u
parameter_list|)
define|\
value|((((M)& 0xFF)<< 24) | (((m)& 0xFFF)<< 12) | ((u)& 0xFFF))
define|#
directive|define
name|DT_VERSION_MAJOR
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0xFF000000)>> 24)
define|#
directive|define
name|DT_VERSION_MINOR
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x00FFF000)>> 12)
define|#
directive|define
name|DT_VERSION_MICRO
parameter_list|(
name|v
parameter_list|)
value|((v)& 0x00000FFF)
specifier|extern
name|char
modifier|*
name|dt_version_num2str
parameter_list|(
name|dt_version_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_version_str2num
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|dt_version_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_version_defined
parameter_list|(
name|dt_version_t
parameter_list|)
function_decl|;
comment|/*  * Miscellaneous internal libdtrace interfaces.  The definitions below are for  * libdtrace routines that do not yet merit their own separate header file.  */
specifier|extern
name|char
modifier|*
name|dt_cpp_add_arg
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|dt_cpp_pop_arg
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
specifier|extern
name|int
name|dt_set_errno
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
else|#
directive|else
name|int
name|_dt_set_errno
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
name|dt_get_errloc
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|dt_set_errno
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
value|_dt_set_errno(_a,_b,__FILE__,__LINE__)
endif|#
directive|endif
specifier|extern
name|void
name|dt_set_errmsg
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
specifier|extern
name|int
name|dt_ioctl
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
else|#
directive|else
specifier|extern
name|int
name|dt_ioctl
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|extern
name|int
name|dt_status
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|processorid_t
parameter_list|)
function_decl|;
specifier|extern
name|long
name|dt_sysconf
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|ssize_t
name|dt_write
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_printf
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|dt_zalloc
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|dt_alloc
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_free
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_difo_free
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dtrace_difo_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_gmatch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|dt_basename
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|ulong_t
name|dt_popc
parameter_list|(
name|ulong_t
parameter_list|)
function_decl|;
specifier|extern
name|ulong_t
name|dt_popcb
parameter_list|(
specifier|const
name|ulong_t
modifier|*
parameter_list|,
name|ulong_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_buffered_enable
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_buffered_flush
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dtrace_probedata_t
modifier|*
parameter_list|,
specifier|const
name|dtrace_recdesc_t
modifier|*
parameter_list|,
specifier|const
name|dtrace_aggdata_t
modifier|*
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_buffered_disable
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_buffered_destroy
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|uint64_t
name|dt_stddev
parameter_list|(
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_rw_read_held
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_rw_write_held
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_mutex_held
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_options_load
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|DT_RW_READ_HELD
parameter_list|(
name|x
parameter_list|)
value|dt_rw_read_held(x)
define|#
directive|define
name|DT_RW_WRITE_HELD
parameter_list|(
name|x
parameter_list|)
value|dt_rw_write_held(x)
define|#
directive|define
name|DT_RW_LOCK_HELD
parameter_list|(
name|x
parameter_list|)
value|(DT_RW_READ_HELD(x) || DT_RW_WRITE_HELD(x))
define|#
directive|define
name|DT_MUTEX_HELD
parameter_list|(
name|x
parameter_list|)
value|dt_mutex_held(x)
specifier|extern
name|void
name|dt_dprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_setcontext
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dtrace_probedesc_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_endcontext
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_pragma
parameter_list|(
name|dt_node_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_reduce
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dt_version_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_cg
parameter_list|(
name|dt_pcb_t
modifier|*
parameter_list|,
name|dt_node_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dtrace_difo_t
modifier|*
name|dt_as
parameter_list|(
name|dt_pcb_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_dis
parameter_list|(
specifier|const
name|dtrace_difo_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_aggregate_go
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_aggregate_init
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_aggregate_destroy
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_epid_lookup
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dtrace_epid_t
parameter_list|,
name|dtrace_eprobedesc_t
modifier|*
modifier|*
parameter_list|,
name|dtrace_probedesc_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_epid_destroy
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_aggid_lookup
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dtrace_aggid_t
parameter_list|,
name|dtrace_aggdesc_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_aggid_destroy
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|dt_format_lookup
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_format_destroy
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|char
modifier|*
name|dt_strdata_lookup
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_strdata_destroy
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_print_quantize
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_print_lquantize
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_print_llquantize
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_print_agg
parameter_list|(
specifier|const
name|dtrace_aggdata_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_handle
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dtrace_probedata_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_handle_liberr
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
specifier|const
name|dtrace_probedata_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_handle_cpudrop
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|processorid_t
parameter_list|,
name|dtrace_dropkind_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_handle_status
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dtrace_status_t
modifier|*
parameter_list|,
name|dtrace_status_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_handle_setopt
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dtrace_setoptdata_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_lib_depend_add
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dt_list_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_lib_depend_t
modifier|*
name|dt_lib_depend_lookup
parameter_list|(
name|dt_list_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_pcb_t
modifier|*
name|yypcb
decl_stmt|;
comment|/* pointer to current parser control block */
specifier|extern
name|char
name|yyintprefix
decl_stmt|;
comment|/* int token prefix for macros (+/-) */
specifier|extern
name|char
name|yyintsuffix
index|[
literal|4
index|]
decl_stmt|;
comment|/* int token suffix ([uUlL]*) */
specifier|extern
name|int
name|yyintdecimal
decl_stmt|;
comment|/* int token is decimal (1) or octal/hex (0) */
specifier|extern
name|char
name|yytext
index|[]
decl_stmt|;
comment|/* lex input buffer */
specifier|extern
name|int
name|yylineno
decl_stmt|;
comment|/* lex line number */
specifier|extern
name|int
name|yydebug
decl_stmt|;
comment|/* lex debugging */
specifier|extern
name|dt_node_t
modifier|*
name|yypragma
decl_stmt|;
comment|/* lex token list for control lines */
specifier|extern
specifier|const
name|dtrace_attribute_t
name|_dtrace_maxattr
decl_stmt|;
comment|/* maximum attributes */
specifier|extern
specifier|const
name|dtrace_attribute_t
name|_dtrace_defattr
decl_stmt|;
comment|/* default attributes */
specifier|extern
specifier|const
name|dtrace_attribute_t
name|_dtrace_symattr
decl_stmt|;
comment|/* symbol ref attributes */
specifier|extern
specifier|const
name|dtrace_attribute_t
name|_dtrace_typattr
decl_stmt|;
comment|/* type ref attributes */
specifier|extern
specifier|const
name|dtrace_attribute_t
name|_dtrace_prvattr
decl_stmt|;
comment|/* provider attributes */
specifier|extern
specifier|const
name|dtrace_pattr_t
name|_dtrace_prvdesc
decl_stmt|;
comment|/* provider attribute bundle */
specifier|extern
specifier|const
name|dt_version_t
name|_dtrace_versions
index|[]
decl_stmt|;
comment|/* array of valid versions */
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|_dtrace_version
decl_stmt|;
comment|/* current version string */
specifier|extern
name|int
name|_dtrace_strbuckets
decl_stmt|;
comment|/* number of hash buckets for strings */
specifier|extern
name|int
name|_dtrace_intbuckets
decl_stmt|;
comment|/* number of hash buckets for ints */
specifier|extern
name|uint_t
name|_dtrace_stkindent
decl_stmt|;
comment|/* default indent for stack/ustack */
specifier|extern
name|uint_t
name|_dtrace_pidbuckets
decl_stmt|;
comment|/* number of hash buckets for pids */
specifier|extern
name|uint_t
name|_dtrace_pidlrulim
decl_stmt|;
comment|/* number of proc handles to cache */
specifier|extern
name|int
name|_dtrace_debug
decl_stmt|;
comment|/* debugging messages enabled */
specifier|extern
name|size_t
name|_dtrace_bufsize
decl_stmt|;
comment|/* default dt_buf_create() size */
specifier|extern
name|int
name|_dtrace_argmax
decl_stmt|;
comment|/* default maximum probe arguments */
specifier|extern
specifier|const
name|char
modifier|*
name|_dtrace_libdir
decl_stmt|;
comment|/* default library directory */
specifier|extern
specifier|const
name|char
modifier|*
name|_dtrace_moddir
decl_stmt|;
comment|/* default kernel module directory */
ifdef|#
directive|ifdef
name|__FreeBSD__
specifier|extern
name|int
name|gmatch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
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
comment|/* _DT_IMPL_H */
end_comment

end_unit

