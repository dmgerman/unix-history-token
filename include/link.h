begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * RRS section definitions.  * Nomenclature and, more importantly, the layout of the various  * data structures defined in this header file are borrowed from  * Sun Microsystems' original<link.h>, so we can provide compatibility  * with the SunOS 4.x shared library scheme.  *  *	$Id: link.h,v 1.2 1993/10/22 21:04:19 pk Exp $  *		(derived from: @(#)link.h 1.6 88/08/19 SMI  *		Copyright (c) 1987 by Sun Microsystems, Inc.)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINK_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINK_H_
end_define

begin_comment
comment|/*  * A `link_object' structure descibes a shared object that is needed  * to complete the link edit process of the object containing it.  * A list of such objects (chained through `lo_next') is pointed at  * by `ld_need' in the link_dynamic_2 structure.  */
end_comment

begin_struct
struct|struct
name|link_object
block|{
name|long
name|lo_name
decl_stmt|;
comment|/* name (relative to load address) */
name|u_int
name|lo_library
range|:
literal|1
decl_stmt|,
comment|/* searched for by library rules */
name|lo_unused
range|:
literal|31
decl_stmt|;
name|short
name|lo_major
decl_stmt|;
comment|/* major version number */
name|short
name|lo_minor
decl_stmt|;
comment|/* minor version number */
name|long
name|lo_next
decl_stmt|;
comment|/* next one (often relative) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * `link_maps' are used by the run-time link editor (ld.so) to keep  * track of all shared objects loaded into a process' address space.  * These structures are only used at run-time and do not occur within  * the text or data segment of an executable or shared library.  */
end_comment

begin_struct
struct|struct
name|link_map
block|{
name|caddr_t
name|lm_addr
decl_stmt|;
comment|/* address at which object mapped */
name|char
modifier|*
name|lm_name
decl_stmt|;
comment|/* full name of loaded object */
name|struct
name|link_map
modifier|*
name|lm_next
decl_stmt|;
comment|/* next object in map */
name|struct
name|link_object
modifier|*
name|lm_lop
decl_stmt|;
comment|/* link object that got us here */
name|caddr_t
name|lm_lob
decl_stmt|;
comment|/* base address for said link object */
name|u_int
name|lm_rwt
range|:
literal|1
decl_stmt|;
comment|/* text is read/write */
name|struct
name|link_dynamic
modifier|*
name|lm_ld
decl_stmt|;
comment|/* dynamic structure */
name|caddr_t
name|lm_lpd
decl_stmt|;
comment|/* loader private data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Symbol description with size. This is simply an `nlist' with  * one field (nz_size) added.  * Used to convey size information on items in the data segment  * of shared objects. An array of these live in the shared object's  * text segment and is address by the `ld_symbols' field.  */
end_comment

begin_struct
struct|struct
name|nzlist
block|{
name|struct
name|nlist
name|nlist
decl_stmt|;
name|u_long
name|nz_size
decl_stmt|;
define|#
directive|define
name|nz_un
value|nlist.n_un
define|#
directive|define
name|nz_strx
value|nlist.n_un.n_strx
define|#
directive|define
name|nz_name
value|nlist.n_un.n_name
define|#
directive|define
name|nz_type
value|nlist.n_type
define|#
directive|define
name|nz_value
value|nlist.n_value
define|#
directive|define
name|nz_desc
value|nlist.n_desc
define|#
directive|define
name|nz_other
value|nlist.n_other
block|}
struct|;
end_struct

begin_comment
comment|/*  * The `link_dynamic_2' structure contains offsets to various data  * structures needed to do run-time relocation.  */
end_comment

begin_struct
struct|struct
name|link_dynamic_2
block|{
name|struct
name|link_map
modifier|*
name|ld_loaded
decl_stmt|;
comment|/* list of loaded objects */
name|long
name|ld_need
decl_stmt|;
comment|/* list of needed objects */
name|long
name|ld_rules
decl_stmt|;
comment|/* search rules for library objects */
name|long
name|ld_got
decl_stmt|;
comment|/* global offset table */
name|long
name|ld_plt
decl_stmt|;
comment|/* procedure linkage table */
name|long
name|ld_rel
decl_stmt|;
comment|/* relocation table */
name|long
name|ld_hash
decl_stmt|;
comment|/* symbol hash table */
name|long
name|ld_symbols
decl_stmt|;
comment|/* symbol table itself */
name|long
function_decl|(
modifier|*
name|ld_stab_hash
function_decl|)
parameter_list|()
function_decl|;
comment|/* "pointer" to symbol hash function */
name|long
name|ld_buckets
decl_stmt|;
comment|/* number of hash buckets */
name|long
name|ld_strings
decl_stmt|;
comment|/* symbol strings */
name|long
name|ld_str_sz
decl_stmt|;
comment|/* size of symbol strings */
name|long
name|ld_text_sz
decl_stmt|;
comment|/* size of text area */
name|long
name|ld_plt_sz
decl_stmt|;
comment|/* size of procedure linkage table */
block|}
struct|;
end_struct

begin_comment
comment|/*  * RRS symbol hash table, addressed by `ld_hash' in link_dynamic_2  * Used to quickly lookup symbols of the shared object by hashing  * on the symbol's name. `rh_symbolnum' is the index of the symbol  * in the shared object's symbol list (`ld_symbols'), `rh_next' is  * the next symbol in the hash bucket (in case of collisions).  */
end_comment

begin_struct
struct|struct
name|rrs_hash
block|{
name|int
name|rh_symbolnum
decl_stmt|;
comment|/* symbol number */
name|int
name|rh_next
decl_stmt|;
comment|/* next hash entry */
block|}
struct|;
end_struct

begin_comment
comment|/*  * `rt_symbols' is used to keep track of run-time allocated commons  * and data items copied from shared objects.  */
end_comment

begin_struct
struct|struct
name|rt_symbol
block|{
name|struct
name|nzlist
modifier|*
name|rt_sp
decl_stmt|;
comment|/* the symbol */
name|struct
name|rt_symbol
modifier|*
name|rt_next
decl_stmt|;
comment|/* next in linear list */
name|struct
name|rt_symbol
modifier|*
name|rt_link
decl_stmt|;
comment|/* next in bucket */
name|caddr_t
name|rt_srcaddr
decl_stmt|;
comment|/* address of "master" copy */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debugger interface structure.  */
end_comment

begin_struct
struct|struct
name|ld_debug
block|{
name|int
name|ldd_version
decl_stmt|;
comment|/* version # of interface */
name|int
name|ldd_in_debugger
decl_stmt|;
comment|/* a debugger is running us */
name|int
name|ldd_sym_loaded
decl_stmt|;
comment|/* we loaded some symbols */
name|char
modifier|*
name|ldd_bp_addr
decl_stmt|;
comment|/* place for ld-generated bpt */
name|int
name|ldd_bp_inst
decl_stmt|;
comment|/* instruction which was there */
name|struct
name|rt_symbol
modifier|*
name|ldd_cp
decl_stmt|;
comment|/* commons we built */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Entry points into ld.so - user interface to the run-time linker.  * (see also libdl.a)  */
end_comment

begin_struct
struct|struct
name|ld_entry
block|{
name|int
function_decl|(
modifier|*
name|dlopen
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|dlclose
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|dlsym
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the structure pointed at by the __DYNAMIC symbol if an  * executable requires the attention of the run-time link editor.  * __DYNAMIC is given the value zero if no run-time linking needs to  * be done (it is always present in shared objects).  * The union `ld_un' provides for different versions of the dynamic  * linking mechanism (switched on by `ld_version'). The last version  * used by Sun is 3. We leave some room here and go to version number  * 8 for NetBSD, the main difference lying in the support for the  * `nz_list' type of symbols.  */
end_comment

begin_struct
struct|struct
name|link_dynamic
block|{
name|int
name|ld_version
decl_stmt|;
comment|/* version # of this structure */
name|struct
name|ld_debug
modifier|*
name|ldd
decl_stmt|;
union|union
block|{
name|struct
name|link_dynamic_2
modifier|*
name|ld_2
decl_stmt|;
block|}
name|ld_un
union|;
name|struct
name|ld_entry
modifier|*
name|ld_entry
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LD_VERSION_SUN
value|(3)
end_define

begin_define
define|#
directive|define
name|LD_VERSION_BSD
value|(8)
end_define

begin_define
define|#
directive|define
name|LD_VERSION_NZLIST_P
parameter_list|(
name|v
parameter_list|)
value|((v)>= 8)
end_define

begin_define
define|#
directive|define
name|LD_GOT
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_got)
end_define

begin_define
define|#
directive|define
name|LD_PLT
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_plt)
end_define

begin_define
define|#
directive|define
name|LD_REL
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_rel)
end_define

begin_define
define|#
directive|define
name|LD_SYMBOL
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_symbols)
end_define

begin_define
define|#
directive|define
name|LD_HASH
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_hash)
end_define

begin_define
define|#
directive|define
name|LD_STRINGS
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_strings)
end_define

begin_define
define|#
directive|define
name|LD_NEED
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_need)
end_define

begin_define
define|#
directive|define
name|LD_BUCKETS
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_buckets)
end_define

begin_define
define|#
directive|define
name|LD_GOTSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_plt - (x)->ld_un.ld_2->ld_got)
end_define

begin_define
define|#
directive|define
name|LD_RELSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_hash - (x)->ld_un.ld_2->ld_rel)
end_define

begin_define
define|#
directive|define
name|LD_HASHSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_symbols - (x)->ld_un.ld_2->ld_hash)
end_define

begin_define
define|#
directive|define
name|LD_STABSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_strings - (x)->ld_un.ld_2->ld_symbols)
end_define

begin_define
define|#
directive|define
name|LD_PLTSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_plt_sz)
end_define

begin_define
define|#
directive|define
name|LD_STRSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_str_sz)
end_define

begin_define
define|#
directive|define
name|LD_TEXTSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->ld_un.ld_2->ld_text_sz)
end_define

begin_comment
comment|/*  * Interface to ld.so (see link(5))  */
end_comment

begin_struct
struct|struct
name|crt_ldso
block|{
name|int
name|crt_ba
decl_stmt|;
comment|/* Base address of ld.so */
name|int
name|crt_dzfd
decl_stmt|;
comment|/* "/dev/zero" file decriptor (SunOS) */
name|int
name|crt_ldfd
decl_stmt|;
comment|/* ld.so file descriptor */
name|struct
name|link_dynamic
modifier|*
name|crt_dp
decl_stmt|;
comment|/* Main's __DYNAMIC */
name|char
modifier|*
modifier|*
name|crt_ep
decl_stmt|;
comment|/* environment strings */
name|caddr_t
name|crt_bp
decl_stmt|;
comment|/* Breakpoint if run from debugger */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Version passed from crt0 to ld.so (1st argument to _rtld()).  */
end_comment

begin_define
define|#
directive|define
name|CRT_VERSION_SUN
value|1
end_define

begin_define
define|#
directive|define
name|CRT_VERSION_BSD
value|2
end_define

begin_comment
comment|/*  * Maximum number of recognized shared object version numbers.  */
end_comment

begin_define
define|#
directive|define
name|MAXDEWEY
value|8
end_define

begin_comment
comment|/*  * Header of the hints file.  */
end_comment

begin_struct
struct|struct
name|hints_header
block|{
name|long
name|hh_magic
decl_stmt|;
define|#
directive|define
name|HH_MAGIC
value|011421044151
name|long
name|hh_version
decl_stmt|;
comment|/* Interface version number */
define|#
directive|define
name|LD_HINTS_VERSION_1
value|1
name|long
name|hh_hashtab
decl_stmt|;
comment|/* Location of hash table */
name|long
name|hh_nbucket
decl_stmt|;
comment|/* Number of buckets in hashtab */
name|long
name|hh_strtab
decl_stmt|;
comment|/* Location of strings */
name|long
name|hh_strtab_sz
decl_stmt|;
comment|/* Size of strings */
name|long
name|hh_ehints
decl_stmt|;
comment|/* End of hints (max offset in file) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HH_BADMAG
parameter_list|(
name|hdr
parameter_list|)
value|((hdr).hh_magic != HH_MAGIC)
end_define

begin_comment
comment|/*  * Hash table element in hints file.  */
end_comment

begin_struct
struct|struct
name|hints_bucket
block|{
comment|/* namex and pathx are indices into the string table */
name|int
name|hi_namex
decl_stmt|;
comment|/* Library name */
name|int
name|hi_pathx
decl_stmt|;
comment|/* Full path */
name|int
name|hi_dewey
index|[
name|MAXDEWEY
index|]
decl_stmt|;
comment|/* The versions */
name|int
name|hi_ndewey
decl_stmt|;
comment|/* Number of version numbers */
define|#
directive|define
name|hi_major
value|hi_dewey[0]
define|#
directive|define
name|hi_minor
value|hi_dewey[1]
name|int
name|hi_next
decl_stmt|;
comment|/* Next in this bucket */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_PATH_LD_HINTS
value|"/var/run/ld.so.hints"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINK_H_ */
end_comment

end_unit

