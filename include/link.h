begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Paul Kranenburg  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Paul Kranenburg.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: link.h,v 1.9.2.1 1997/08/08 02:17:55 jdp Exp $  */
end_comment

begin_comment
comment|/*  * RRS section definitions.  *  * The layout of some data structures defined in this header file is  * such that we can provide compatibility with the SunOS 4.x shared  * library scheme.  */
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
comment|/*  * A `Shared Object Descriptor' describes a shared object that is needed  * to complete the link edit process of the object containing it.  * A list of such objects (chained through `sod_next') is pointed at  * by `sdt_sods' in the section_dispatch_table structure.  */
end_comment

begin_struct
struct|struct
name|sod
block|{
comment|/* Shared Object Descriptor */
name|long
name|sod_name
decl_stmt|;
comment|/* name (relative to load address) */
name|u_int
name|sod_library
range|:
literal|1
decl_stmt|,
comment|/* Searched for by library rules */
name|sod_reserved
range|:
literal|31
decl_stmt|;
name|short
name|sod_major
decl_stmt|;
comment|/* major version number */
name|short
name|sod_minor
decl_stmt|;
comment|/* minor version number */
name|long
name|sod_next
decl_stmt|;
comment|/* next sod */
block|}
struct|;
end_struct

begin_comment
comment|/*  * `Shared Object Map's are used by the run-time link editor (ld.so) to  * keep track of all shared objects loaded into a process' address space.  * These structures are only used at run-time and do not occur within  * the text or data segment of an executable or shared library.  */
end_comment

begin_struct
struct|struct
name|so_map
block|{
comment|/* Shared Object Map */
name|caddr_t
name|som_addr
decl_stmt|;
comment|/* Address at which object mapped */
name|char
modifier|*
name|som_path
decl_stmt|;
comment|/* Path to mmap'ed file */
name|struct
name|so_map
modifier|*
name|som_next
decl_stmt|;
comment|/* Next map in chain */
name|struct
name|sod
modifier|*
name|som_sod
decl_stmt|;
comment|/* Sod responsible for this map */
name|caddr_t
name|som_sodbase
decl_stmt|;
comment|/* Base address of this sod */
name|u_int
name|som_write
range|:
literal|1
decl_stmt|;
comment|/* Text is currently writable */
name|struct
name|_dynamic
modifier|*
name|som_dynamic
decl_stmt|;
comment|/* _dynamic structure */
name|caddr_t
name|som_spd
decl_stmt|;
comment|/* Private data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Symbol description with size. This is simply an `nlist' with  * one field (nz_size) added.  * Used to convey size information on items in the data segment  * of shared objects. An array of these live in the shared object's  * text segment and is addressed by the `sdt_nzlist' field.  */
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

begin_define
define|#
directive|define
name|N_AUX
parameter_list|(
name|p
parameter_list|)
value|((p)->n_other& 0xf)
end_define

begin_define
define|#
directive|define
name|N_BIND
parameter_list|(
name|p
parameter_list|)
value|(((unsigned int)(p)->n_other>> 4)& 0xf)
end_define

begin_define
define|#
directive|define
name|N_OTHER
parameter_list|(
name|r
parameter_list|,
name|v
parameter_list|)
value|(((unsigned int)(r)<< 4) | ((v)& 0xf))
end_define

begin_define
define|#
directive|define
name|AUX_OBJECT
value|1
end_define

begin_define
define|#
directive|define
name|AUX_FUNC
value|2
end_define

begin_comment
comment|/*#define BIND_LOCAL	0	not used */
end_comment

begin_comment
comment|/*#define BIND_GLOBAL	1	not used */
end_comment

begin_define
define|#
directive|define
name|BIND_WEAK
value|2
end_define

begin_comment
comment|/*  * The `section_dispatch_table' structure contains offsets to various data  * structures needed to do run-time relocation.  */
end_comment

begin_struct
struct|struct
name|section_dispatch_table
block|{
name|struct
name|so_map
modifier|*
name|sdt_loaded
decl_stmt|;
comment|/* List of loaded objects */
name|long
name|sdt_sods
decl_stmt|;
comment|/* List of shared objects descriptors */
name|long
name|sdt_paths
decl_stmt|;
comment|/* Library search paths */
name|long
name|sdt_got
decl_stmt|;
comment|/* Global offset table */
name|long
name|sdt_plt
decl_stmt|;
comment|/* Procedure linkage table */
name|long
name|sdt_rel
decl_stmt|;
comment|/* Relocation table */
name|long
name|sdt_hash
decl_stmt|;
comment|/* Symbol hash table */
name|long
name|sdt_nzlist
decl_stmt|;
comment|/* Symbol table itself */
name|long
name|sdt_filler2
decl_stmt|;
comment|/* Unused (was: stab_hash) */
name|long
name|sdt_buckets
decl_stmt|;
comment|/* Number of hash buckets */
name|long
name|sdt_strings
decl_stmt|;
comment|/* Symbol strings */
name|long
name|sdt_str_sz
decl_stmt|;
comment|/* Size of symbol strings */
name|long
name|sdt_text_sz
decl_stmt|;
comment|/* Size of text area */
name|long
name|sdt_plt_sz
decl_stmt|;
comment|/* Size of procedure linkage table */
block|}
struct|;
end_struct

begin_comment
comment|/*  * RRS symbol hash table, addressed by `sdt_hash' in section_dispatch_table.  * Used to quickly lookup symbols of the shared object by hashing  * on the symbol's name. `rh_symbolnum' is the index of the symbol  * in the shared object's symbol list (`sdt_nzlist'), `rh_next' is  * the next symbol in the hash bucket (in case of collisions).  */
end_comment

begin_struct
struct|struct
name|rrs_hash
block|{
name|int
name|rh_symbolnum
decl_stmt|;
comment|/* Symbol number */
name|int
name|rh_next
decl_stmt|;
comment|/* Next hash entry */
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
comment|/* The symbol */
name|struct
name|rt_symbol
modifier|*
name|rt_next
decl_stmt|;
comment|/* Next in linear list */
name|struct
name|rt_symbol
modifier|*
name|rt_link
decl_stmt|;
comment|/* Next in bucket */
name|caddr_t
name|rt_srcaddr
decl_stmt|;
comment|/* Address of "master" copy */
name|struct
name|so_map
modifier|*
name|rt_smp
decl_stmt|;
comment|/* Originating map */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debugger interface structure.  */
end_comment

begin_struct
struct|struct
name|so_debug
block|{
name|int
name|dd_version
decl_stmt|;
comment|/* Version # of interface */
name|int
name|dd_in_debugger
decl_stmt|;
comment|/* Set when run by debugger */
name|int
name|dd_sym_loaded
decl_stmt|;
comment|/* Run-time linking brought more 					   symbols into scope */
name|char
modifier|*
name|dd_bpt_addr
decl_stmt|;
comment|/* Address of rtld-generated bpt */
name|int
name|dd_bpt_shadow
decl_stmt|;
comment|/* Original contents of bpt */
name|struct
name|rt_symbol
modifier|*
name|dd_cc
decl_stmt|;
comment|/* Allocated commons/copied data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Version returned to crt0 from ld.so  */
end_comment

begin_define
define|#
directive|define
name|LDSO_VERSION_NONE
value|0
end_define

begin_comment
comment|/* FreeBSD2.0, 2.0.5 */
end_comment

begin_define
define|#
directive|define
name|LDSO_VERSION_HAS_DLEXIT
value|1
end_define

begin_comment
comment|/* includes dlexit in ld_entry */
end_comment

begin_define
define|#
directive|define
name|LDSO_VERSION_HAS_DLSYM3
value|2
end_define

begin_comment
comment|/* includes 3-argument dlsym */
end_comment

begin_comment
comment|/*  * Entry points into ld.so - user interface to the run-time linker.  * Entries are valid for the given version numbers returned by ld.so  * to crt0.  */
end_comment

begin_struct
struct|struct
name|ld_entry
block|{
name|void
operator|*
operator|(
operator|*
name|dlopen
operator|)
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* NONE */
name|int
argument_list|(
argument|*dlclose
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* NONE */
name|void
operator|*
operator|(
operator|*
name|dlsym
operator|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* NONE */
specifier|const
name|char
operator|*
operator|(
operator|*
name|dlerror
operator|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* NONE */
name|void
argument_list|(
argument|*dlexit
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* HAS_DLEXIT */
name|void
operator|*
operator|(
operator|*
name|dlsym3
operator|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* HAS_DLSYM3 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * dl*() prototypes.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|dlopen
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dlclose
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|dlsym
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|dlerror
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This is the structure pointed at by the __DYNAMIC symbol if an  * executable requires the attention of the run-time link editor.  * __DYNAMIC is given the value zero if no run-time linking needs to  * be done (it is always present in shared objects).  * The union `d_un' provides for different versions of the dynamic  * linking mechanism (switched on by `d_version'). The last version  * used by Sun is 3. We leave some room here and go to version number  * 8 for NetBSD, the main difference lying in the support for the  * `nz_list' type of symbols.  */
end_comment

begin_struct
struct|struct
name|_dynamic
block|{
name|int
name|d_version
decl_stmt|;
comment|/* version # of this interface */
name|struct
name|so_debug
modifier|*
name|d_debug
decl_stmt|;
union|union
block|{
name|struct
name|section_dispatch_table
modifier|*
name|d_sdt
decl_stmt|;
block|}
name|d_un
union|;
name|struct
name|ld_entry
modifier|*
name|d_entry
decl_stmt|;
comment|/* XXX */
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
value|((x)->d_un.d_sdt->sdt_got)
end_define

begin_define
define|#
directive|define
name|LD_PLT
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_plt)
end_define

begin_define
define|#
directive|define
name|LD_REL
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_rel)
end_define

begin_define
define|#
directive|define
name|LD_SYMBOL
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_nzlist)
end_define

begin_define
define|#
directive|define
name|LD_HASH
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_hash)
end_define

begin_define
define|#
directive|define
name|LD_STRINGS
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_strings)
end_define

begin_define
define|#
directive|define
name|LD_NEED
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_sods)
end_define

begin_define
define|#
directive|define
name|LD_BUCKETS
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_buckets)
end_define

begin_define
define|#
directive|define
name|LD_PATHS
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_paths)
end_define

begin_define
define|#
directive|define
name|LD_GOTSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_plt - (x)->d_un.d_sdt->sdt_got)
end_define

begin_define
define|#
directive|define
name|LD_RELSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_hash - (x)->d_un.d_sdt->sdt_rel)
end_define

begin_define
define|#
directive|define
name|LD_HASHSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_nzlist - (x)->d_un.d_sdt->sdt_hash)
end_define

begin_define
define|#
directive|define
name|LD_STABSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_strings - (x)->d_un.d_sdt->sdt_nzlist)
end_define

begin_define
define|#
directive|define
name|LD_PLTSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_plt_sz)
end_define

begin_define
define|#
directive|define
name|LD_STRSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_str_sz)
end_define

begin_define
define|#
directive|define
name|LD_TEXTSZ
parameter_list|(
name|x
parameter_list|)
value|((x)->d_un.d_sdt->sdt_text_sz)
end_define

begin_comment
comment|/*  * Interface to ld.so  */
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
comment|/* "/dev/zero" file descriptor (SunOS) */
name|int
name|crt_ldfd
decl_stmt|;
comment|/* ld.so file descriptor */
name|struct
name|_dynamic
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
name|char
modifier|*
name|crt_prog
decl_stmt|;
comment|/* Program name (v3) */
name|char
modifier|*
name|crt_ldso
decl_stmt|;
comment|/* Link editor name (v4) */
name|struct
name|ld_entry
modifier|*
name|crt_ldentry
decl_stmt|;
comment|/* dl*() access (v4) */
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
name|CRT_VERSION_BSD_2
value|2
end_define

begin_define
define|#
directive|define
name|CRT_VERSION_BSD_3
value|3
end_define

begin_define
define|#
directive|define
name|CRT_VERSION_BSD_4
value|4
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
define|#
directive|define
name|LD_HINTS_VERSION_2
value|2
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
name|long
name|hh_dirlist
decl_stmt|;
comment|/* Colon-separated list of srch dirs */
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

