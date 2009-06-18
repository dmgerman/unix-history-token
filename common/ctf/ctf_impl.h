begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTF_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_CTF_IMPL_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_include
include|#
directive|include
file|<sys/ctf_api.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/cmn_err.h>
end_include

begin_include
include|#
directive|include
file|<sys/varargs.h>
end_include

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
define|\
value|((c) == ' ' || (c) == '\t' || (c) == '\n' || \ 	(c) == '\r' || (c) == '\f' || (c) == '\v')
end_define

begin_define
define|#
directive|define
name|MAP_FAILED
value|((void *)-1)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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
typedef|typedef
struct|struct
name|ctf_helem
block|{
name|uint_t
name|h_name
decl_stmt|;
comment|/* reference to name in string table */
name|ushort_t
name|h_type
decl_stmt|;
comment|/* corresponding type ID number */
name|ushort_t
name|h_next
decl_stmt|;
comment|/* index of next element in hash chain */
block|}
name|ctf_helem_t
typedef|;
typedef|typedef
struct|struct
name|ctf_hash
block|{
name|ushort_t
modifier|*
name|h_buckets
decl_stmt|;
comment|/* hash bucket array (chain indices) */
name|ctf_helem_t
modifier|*
name|h_chains
decl_stmt|;
comment|/* hash chains buffer */
name|ushort_t
name|h_nbuckets
decl_stmt|;
comment|/* number of elements in bucket array */
name|ushort_t
name|h_nelems
decl_stmt|;
comment|/* number of elements in hash table */
name|uint_t
name|h_free
decl_stmt|;
comment|/* index of next free hash element */
block|}
name|ctf_hash_t
typedef|;
typedef|typedef
struct|struct
name|ctf_strs
block|{
specifier|const
name|char
modifier|*
name|cts_strs
decl_stmt|;
comment|/* base address of string table */
name|size_t
name|cts_len
decl_stmt|;
comment|/* size of string table in bytes */
block|}
name|ctf_strs_t
typedef|;
typedef|typedef
struct|struct
name|ctf_dmodel
block|{
specifier|const
name|char
modifier|*
name|ctd_name
decl_stmt|;
comment|/* data model name */
name|int
name|ctd_code
decl_stmt|;
comment|/* data model code */
name|size_t
name|ctd_pointer
decl_stmt|;
comment|/* size of void * in bytes */
name|size_t
name|ctd_char
decl_stmt|;
comment|/* size of char in bytes */
name|size_t
name|ctd_short
decl_stmt|;
comment|/* size of short in bytes */
name|size_t
name|ctd_int
decl_stmt|;
comment|/* size of int in bytes */
name|size_t
name|ctd_long
decl_stmt|;
comment|/* size of long in bytes */
block|}
name|ctf_dmodel_t
typedef|;
typedef|typedef
struct|struct
name|ctf_lookup
block|{
specifier|const
name|char
modifier|*
name|ctl_prefix
decl_stmt|;
comment|/* string prefix for this lookup */
name|size_t
name|ctl_len
decl_stmt|;
comment|/* length of prefix string in bytes */
name|ctf_hash_t
modifier|*
name|ctl_hash
decl_stmt|;
comment|/* pointer to hash table for lookup */
block|}
name|ctf_lookup_t
typedef|;
typedef|typedef
struct|struct
name|ctf_fileops
block|{
name|ushort_t
function_decl|(
modifier|*
name|ctfo_get_kind
function_decl|)
parameter_list|(
name|ushort_t
parameter_list|)
function_decl|;
name|ushort_t
function_decl|(
modifier|*
name|ctfo_get_root
function_decl|)
parameter_list|(
name|ushort_t
parameter_list|)
function_decl|;
name|ushort_t
function_decl|(
modifier|*
name|ctfo_get_vlen
function_decl|)
parameter_list|(
name|ushort_t
parameter_list|)
function_decl|;
block|}
name|ctf_fileops_t
typedef|;
typedef|typedef
struct|struct
name|ctf_list
block|{
name|struct
name|ctf_list
modifier|*
name|l_prev
decl_stmt|;
comment|/* previous pointer or tail pointer */
name|struct
name|ctf_list
modifier|*
name|l_next
decl_stmt|;
comment|/* next pointer or head pointer */
block|}
name|ctf_list_t
typedef|;
typedef|typedef
enum|enum
block|{
name|CTF_PREC_BASE
block|,
name|CTF_PREC_POINTER
block|,
name|CTF_PREC_ARRAY
block|,
name|CTF_PREC_FUNCTION
block|,
name|CTF_PREC_MAX
block|}
name|ctf_decl_prec_t
typedef|;
typedef|typedef
struct|struct
name|ctf_decl_node
block|{
name|ctf_list_t
name|cd_list
decl_stmt|;
comment|/* linked list pointers */
name|ctf_id_t
name|cd_type
decl_stmt|;
comment|/* type identifier */
name|uint_t
name|cd_kind
decl_stmt|;
comment|/* type kind */
name|uint_t
name|cd_n
decl_stmt|;
comment|/* type dimension if array */
block|}
name|ctf_decl_node_t
typedef|;
typedef|typedef
struct|struct
name|ctf_decl
block|{
name|ctf_list_t
name|cd_nodes
index|[
name|CTF_PREC_MAX
index|]
decl_stmt|;
comment|/* declaration node stacks */
name|int
name|cd_order
index|[
name|CTF_PREC_MAX
index|]
decl_stmt|;
comment|/* storage order of decls */
name|ctf_decl_prec_t
name|cd_qualp
decl_stmt|;
comment|/* qualifier precision */
name|ctf_decl_prec_t
name|cd_ordp
decl_stmt|;
comment|/* ordered precision */
name|char
modifier|*
name|cd_buf
decl_stmt|;
comment|/* buffer for output */
name|char
modifier|*
name|cd_ptr
decl_stmt|;
comment|/* buffer location */
name|char
modifier|*
name|cd_end
decl_stmt|;
comment|/* buffer limit */
name|size_t
name|cd_len
decl_stmt|;
comment|/* buffer space required */
name|int
name|cd_err
decl_stmt|;
comment|/* saved error value */
block|}
name|ctf_decl_t
typedef|;
typedef|typedef
struct|struct
name|ctf_dmdef
block|{
name|ctf_list_t
name|dmd_list
decl_stmt|;
comment|/* list forward/back pointers */
name|char
modifier|*
name|dmd_name
decl_stmt|;
comment|/* name of this member */
name|ctf_id_t
name|dmd_type
decl_stmt|;
comment|/* type of this member (for sou) */
name|ulong_t
name|dmd_offset
decl_stmt|;
comment|/* offset of this member in bits (for sou) */
name|int
name|dmd_value
decl_stmt|;
comment|/* value of this member (for enum) */
block|}
name|ctf_dmdef_t
typedef|;
typedef|typedef
struct|struct
name|ctf_dtdef
block|{
name|ctf_list_t
name|dtd_list
decl_stmt|;
comment|/* list forward/back pointers */
name|struct
name|ctf_dtdef
modifier|*
name|dtd_hash
decl_stmt|;
comment|/* hash chain pointer for ctf_dthash */
name|char
modifier|*
name|dtd_name
decl_stmt|;
comment|/* name associated with definition (if any) */
name|ctf_id_t
name|dtd_type
decl_stmt|;
comment|/* type identifier for this definition */
name|ctf_type_t
name|dtd_data
decl_stmt|;
comment|/* type node (see<sys/ctf.h>) */
union|union
block|{
name|ctf_list_t
name|dtu_members
decl_stmt|;
comment|/* struct, union, or enum */
name|ctf_arinfo_t
name|dtu_arr
decl_stmt|;
comment|/* array */
name|ctf_encoding_t
name|dtu_enc
decl_stmt|;
comment|/* integer or float */
name|ctf_id_t
modifier|*
name|dtu_argv
decl_stmt|;
comment|/* function */
block|}
name|dtd_u
union|;
block|}
name|ctf_dtdef_t
typedef|;
typedef|typedef
struct|struct
name|ctf_bundle
block|{
name|ctf_file_t
modifier|*
name|ctb_file
decl_stmt|;
comment|/* CTF container handle */
name|ctf_id_t
name|ctb_type
decl_stmt|;
comment|/* CTF type identifier */
name|ctf_dtdef_t
modifier|*
name|ctb_dtd
decl_stmt|;
comment|/* CTF dynamic type definition (if any) */
block|}
name|ctf_bundle_t
typedef|;
comment|/*  * The ctf_file is the structure used to represent a CTF container to library  * clients, who see it only as an opaque pointer.  Modifications can therefore  * be made freely to this structure without regard to client versioning.  The  * ctf_file_t typedef appears in<sys/ctf_api.h> and declares a forward tag.  *  * NOTE: ctf_update() requires that everything inside of ctf_file either be an  * immediate value, a pointer to dynamically allocated data *outside* of the  * ctf_file itself, or a pointer to statically allocated data.  If you add a  * pointer to ctf_file that points to something within the ctf_file itself,  * you must make corresponding changes to ctf_update().  */
struct|struct
name|ctf_file
block|{
specifier|const
name|ctf_fileops_t
modifier|*
name|ctf_fileops
decl_stmt|;
comment|/* version-specific file operations */
name|ctf_sect_t
name|ctf_data
decl_stmt|;
comment|/* CTF data from object file */
name|ctf_sect_t
name|ctf_symtab
decl_stmt|;
comment|/* symbol table from object file */
name|ctf_sect_t
name|ctf_strtab
decl_stmt|;
comment|/* string table from object file */
name|ctf_hash_t
name|ctf_structs
decl_stmt|;
comment|/* hash table of struct types */
name|ctf_hash_t
name|ctf_unions
decl_stmt|;
comment|/* hash table of union types */
name|ctf_hash_t
name|ctf_enums
decl_stmt|;
comment|/* hash table of enum types */
name|ctf_hash_t
name|ctf_names
decl_stmt|;
comment|/* hash table of remaining type names */
name|ctf_lookup_t
name|ctf_lookups
index|[
literal|5
index|]
decl_stmt|;
comment|/* pointers to hashes for name lookup */
name|ctf_strs_t
name|ctf_str
index|[
literal|2
index|]
decl_stmt|;
comment|/* array of string table base and bounds */
specifier|const
name|uchar_t
modifier|*
name|ctf_base
decl_stmt|;
comment|/* base of CTF header + uncompressed buffer */
specifier|const
name|uchar_t
modifier|*
name|ctf_buf
decl_stmt|;
comment|/* uncompressed CTF data buffer */
name|size_t
name|ctf_size
decl_stmt|;
comment|/* size of CTF header + uncompressed data */
name|uint_t
modifier|*
name|ctf_sxlate
decl_stmt|;
comment|/* translation table for symtab entries */
name|ulong_t
name|ctf_nsyms
decl_stmt|;
comment|/* number of entries in symtab xlate table */
name|uint_t
modifier|*
name|ctf_txlate
decl_stmt|;
comment|/* translation table for type IDs */
name|ushort_t
modifier|*
name|ctf_ptrtab
decl_stmt|;
comment|/* translation table for pointer-to lookups */
name|ulong_t
name|ctf_typemax
decl_stmt|;
comment|/* maximum valid type ID number */
specifier|const
name|ctf_dmodel_t
modifier|*
name|ctf_dmodel
decl_stmt|;
comment|/* data model pointer (see above) */
name|struct
name|ctf_file
modifier|*
name|ctf_parent
decl_stmt|;
comment|/* parent CTF container (if any) */
specifier|const
name|char
modifier|*
name|ctf_parlabel
decl_stmt|;
comment|/* label in parent container (if any) */
specifier|const
name|char
modifier|*
name|ctf_parname
decl_stmt|;
comment|/* basename of parent (if any) */
name|uint_t
name|ctf_refcnt
decl_stmt|;
comment|/* reference count (for parent links) */
name|uint_t
name|ctf_flags
decl_stmt|;
comment|/* libctf flags (see below) */
name|int
name|ctf_errno
decl_stmt|;
comment|/* error code for most recent error */
name|int
name|ctf_version
decl_stmt|;
comment|/* CTF data version */
name|ctf_dtdef_t
modifier|*
modifier|*
name|ctf_dthash
decl_stmt|;
comment|/* hash of dynamic type definitions */
name|ulong_t
name|ctf_dthashlen
decl_stmt|;
comment|/* size of dynamic type hash bucket array */
name|ctf_list_t
name|ctf_dtdefs
decl_stmt|;
comment|/* list of dynamic type definitions */
name|size_t
name|ctf_dtstrlen
decl_stmt|;
comment|/* total length of dynamic type strings */
name|ulong_t
name|ctf_dtnextid
decl_stmt|;
comment|/* next dynamic type id to assign */
name|ulong_t
name|ctf_dtoldid
decl_stmt|;
comment|/* oldest id that has been committed */
name|void
modifier|*
name|ctf_specific
decl_stmt|;
comment|/* data for ctf_get/setspecific */
block|}
struct|;
define|#
directive|define
name|LCTF_INDEX_TO_TYPEPTR
parameter_list|(
name|fp
parameter_list|,
name|i
parameter_list|)
define|\
value|((ctf_type_t *)((uintptr_t)(fp)->ctf_buf + (fp)->ctf_txlate[(i)]))
define|#
directive|define
name|LCTF_INFO_KIND
parameter_list|(
name|fp
parameter_list|,
name|info
parameter_list|)
value|((fp)->ctf_fileops->ctfo_get_kind(info))
define|#
directive|define
name|LCTF_INFO_ROOT
parameter_list|(
name|fp
parameter_list|,
name|info
parameter_list|)
value|((fp)->ctf_fileops->ctfo_get_root(info))
define|#
directive|define
name|LCTF_INFO_VLEN
parameter_list|(
name|fp
parameter_list|,
name|info
parameter_list|)
value|((fp)->ctf_fileops->ctfo_get_vlen(info))
define|#
directive|define
name|LCTF_MMAP
value|0x0001
comment|/* libctf should munmap buffers on close */
define|#
directive|define
name|LCTF_CHILD
value|0x0002
comment|/* CTF container is a child */
define|#
directive|define
name|LCTF_RDWR
value|0x0004
comment|/* CTF container is writable */
define|#
directive|define
name|LCTF_DIRTY
value|0x0008
comment|/* CTF container has been modified */
define|#
directive|define
name|ECTF_BASE
value|1000
comment|/* base value for libctf errnos */
enum|enum
block|{
name|ECTF_FMT
init|=
name|ECTF_BASE
block|,
comment|/* file is not in CTF or ELF format */
name|ECTF_ELFVERS
block|,
comment|/* ELF version is more recent than libctf */
name|ECTF_CTFVERS
block|,
comment|/* CTF version is more recent than libctf */
name|ECTF_ENDIAN
block|,
comment|/* data is different endian-ness than lib */
name|ECTF_SYMTAB
block|,
comment|/* symbol table uses invalid entry size */
name|ECTF_SYMBAD
block|,
comment|/* symbol table data buffer invalid */
name|ECTF_STRBAD
block|,
comment|/* string table data buffer invalid */
name|ECTF_CORRUPT
block|,
comment|/* file data corruption detected */
name|ECTF_NOCTFDATA
block|,
comment|/* ELF file does not contain CTF data */
name|ECTF_NOCTFBUF
block|,
comment|/* buffer does not contain CTF data */
name|ECTF_NOSYMTAB
block|,
comment|/* symbol table data is not available */
name|ECTF_NOPARENT
block|,
comment|/* parent CTF container is not available */
name|ECTF_DMODEL
block|,
comment|/* data model mismatch */
name|ECTF_MMAP
block|,
comment|/* failed to mmap a data section */
name|ECTF_ZMISSING
block|,
comment|/* decompression library not installed */
name|ECTF_ZINIT
block|,
comment|/* failed to initialize decompression library */
name|ECTF_ZALLOC
block|,
comment|/* failed to allocate decompression buffer */
name|ECTF_DECOMPRESS
block|,
comment|/* failed to decompress CTF data */
name|ECTF_STRTAB
block|,
comment|/* string table for this string is missing */
name|ECTF_BADNAME
block|,
comment|/* string offset is corrupt w.r.t. strtab */
name|ECTF_BADID
block|,
comment|/* invalid type ID number */
name|ECTF_NOTSOU
block|,
comment|/* type is not a struct or union */
name|ECTF_NOTENUM
block|,
comment|/* type is not an enum */
name|ECTF_NOTSUE
block|,
comment|/* type is not a struct, union, or enum */
name|ECTF_NOTINTFP
block|,
comment|/* type is not an integer or float */
name|ECTF_NOTARRAY
block|,
comment|/* type is not an array */
name|ECTF_NOTREF
block|,
comment|/* type does not reference another type */
name|ECTF_NAMELEN
block|,
comment|/* buffer is too small to hold type name */
name|ECTF_NOTYPE
block|,
comment|/* no type found corresponding to name */
name|ECTF_SYNTAX
block|,
comment|/* syntax error in type name */
name|ECTF_NOTFUNC
block|,
comment|/* symtab entry does not refer to a function */
name|ECTF_NOFUNCDAT
block|,
comment|/* no func info available for function */
name|ECTF_NOTDATA
block|,
comment|/* symtab entry does not refer to a data obj */
name|ECTF_NOTYPEDAT
block|,
comment|/* no type info available for object */
name|ECTF_NOLABEL
block|,
comment|/* no label found corresponding to name */
name|ECTF_NOLABELDATA
block|,
comment|/* file does not contain any labels */
name|ECTF_NOTSUP
block|,
comment|/* feature not supported */
name|ECTF_NOENUMNAM
block|,
comment|/* enum element name not found */
name|ECTF_NOMEMBNAM
block|,
comment|/* member name not found */
name|ECTF_RDONLY
block|,
comment|/* CTF container is read-only */
name|ECTF_DTFULL
block|,
comment|/* CTF type is full (no more members allowed) */
name|ECTF_FULL
block|,
comment|/* CTF container is full */
name|ECTF_DUPMEMBER
block|,
comment|/* duplicate member name definition */
name|ECTF_CONFLICT
comment|/* conflicting type definition present */
block|}
enum|;
specifier|extern
name|ssize_t
name|ctf_get_ctt_size
parameter_list|(
specifier|const
name|ctf_file_t
modifier|*
parameter_list|,
specifier|const
name|ctf_type_t
modifier|*
parameter_list|,
name|ssize_t
modifier|*
parameter_list|,
name|ssize_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|ctf_type_t
modifier|*
name|ctf_lookup_by_id
parameter_list|(
name|ctf_file_t
modifier|*
modifier|*
parameter_list|,
name|ctf_id_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|ctf_hash_create
parameter_list|(
name|ctf_hash_t
modifier|*
parameter_list|,
name|ulong_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|ctf_hash_insert
parameter_list|(
name|ctf_hash_t
modifier|*
parameter_list|,
name|ctf_file_t
modifier|*
parameter_list|,
name|ushort_t
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|ctf_hash_define
parameter_list|(
name|ctf_hash_t
modifier|*
parameter_list|,
name|ctf_file_t
modifier|*
parameter_list|,
name|ushort_t
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|ctf_helem_t
modifier|*
name|ctf_hash_lookup
parameter_list|(
name|ctf_hash_t
modifier|*
parameter_list|,
name|ctf_file_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|uint_t
name|ctf_hash_size
parameter_list|(
specifier|const
name|ctf_hash_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_hash_destroy
parameter_list|(
name|ctf_hash_t
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|ctf_list_prev
parameter_list|(
name|elem
parameter_list|)
value|((void *)(((ctf_list_t *)(elem))->l_prev))
define|#
directive|define
name|ctf_list_next
parameter_list|(
name|elem
parameter_list|)
value|((void *)(((ctf_list_t *)(elem))->l_next))
specifier|extern
name|void
name|ctf_list_append
parameter_list|(
name|ctf_list_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_list_prepend
parameter_list|(
name|ctf_list_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_list_delete
parameter_list|(
name|ctf_list_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_dtd_insert
parameter_list|(
name|ctf_file_t
modifier|*
parameter_list|,
name|ctf_dtdef_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_dtd_delete
parameter_list|(
name|ctf_file_t
modifier|*
parameter_list|,
name|ctf_dtdef_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|ctf_dtdef_t
modifier|*
name|ctf_dtd_lookup
parameter_list|(
name|ctf_file_t
modifier|*
parameter_list|,
name|ctf_id_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_decl_init
parameter_list|(
name|ctf_decl_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_decl_fini
parameter_list|(
name|ctf_decl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_decl_push
parameter_list|(
name|ctf_decl_t
modifier|*
parameter_list|,
name|ctf_file_t
modifier|*
parameter_list|,
name|ctf_id_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_decl_sprintf
parameter_list|(
name|ctf_decl_t
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
specifier|const
name|char
modifier|*
name|ctf_strraw
parameter_list|(
name|ctf_file_t
modifier|*
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|char
modifier|*
name|ctf_strptr
parameter_list|(
name|ctf_file_t
modifier|*
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|ctf_file_t
modifier|*
name|ctf_set_open_errno
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|long
name|ctf_set_errno
parameter_list|(
name|ctf_file_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|void
modifier|*
name|ctf_sect_mmap
parameter_list|(
name|ctf_sect_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_sect_munmap
parameter_list|(
specifier|const
name|ctf_sect_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|ctf_data_alloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_data_free
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_data_protect
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|ctf_alloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_free
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|ctf_strdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|char
modifier|*
name|ctf_strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|ctf_dprintf
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
modifier|*
name|ctf_zopen
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|char
name|_CTF_SECTION
index|[]
decl_stmt|;
comment|/* name of CTF ELF section */
specifier|extern
specifier|const
name|char
name|_CTF_NULLSTR
index|[]
decl_stmt|;
comment|/* empty string */
specifier|extern
name|int
name|_libctf_version
decl_stmt|;
comment|/* library client version */
specifier|extern
name|int
name|_libctf_debug
decl_stmt|;
comment|/* debugging messages enabled */
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
comment|/* _CTF_IMPL_H */
end_comment

end_unit

