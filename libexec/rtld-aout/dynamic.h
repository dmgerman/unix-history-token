begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Paul Kranenburg  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Paul Kranenburg.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DYNAMIC_H__
end_ifndef

begin_define
define|#
directive|define
name|__DYNAMIC_H__
end_define

begin_define
define|#
directive|define
name|SUN_COMPAT
end_define

begin_include
include|#
directive|include
file|"md.h"
end_include

begin_include
include|#
directive|include
file|"link.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|RELOC_JMPTAB_P
end_ifndef

begin_define
define|#
directive|define
name|RELOC_JMPTAB_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_jmptable)
end_define

begin_define
define|#
directive|define
name|RELOC_BASEREL_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_baserel)
end_define

begin_define
define|#
directive|define
name|RELOC_RELATIVE_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_relative)
end_define

begin_define
define|#
directive|define
name|RELOC_COPY_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_copy)
end_define

begin_define
define|#
directive|define
name|RELOC_LAZY_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_jmptable)
end_define

begin_define
define|#
directive|define
name|CHECK_GOT_RELOC
parameter_list|(
name|r
parameter_list|)
value|((r)->r_pcrel)
end_define

begin_define
define|#
directive|define
name|RELOC_PIC_TYPE
parameter_list|(
name|r
parameter_list|)
value|((r)->r_baserel? \ 						PIC_TYPE_LARGE:PIC_TYPE_NONE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RELOC_INIT_SEGMENT_RELOC
end_ifndef

begin_define
define|#
directive|define
name|RELOC_INIT_SEGMENT_RELOC
parameter_list|(
name|r
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_GOTOFF
end_ifndef

begin_define
define|#
directive|define
name|MAX_GOTOFF
parameter_list|(
name|x
parameter_list|)
value|(LONG_MAX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN_GOTOFF
end_ifndef

begin_define
define|#
directive|define
name|MIN_GOTOFF
parameter_list|(
name|x
parameter_list|)
value|(LONG_MIN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Internal representation of relocation types  */
end_comment

begin_define
define|#
directive|define
name|RELTYPE_EXTERN
value|1
end_define

begin_define
define|#
directive|define
name|RELTYPE_JMPSLOT
value|2
end_define

begin_define
define|#
directive|define
name|RELTYPE_BASEREL
value|4
end_define

begin_define
define|#
directive|define
name|RELTYPE_RELATIVE
value|8
end_define

begin_define
define|#
directive|define
name|RELTYPE_COPY
value|16
end_define

begin_define
define|#
directive|define
name|N_ISWEAK
parameter_list|(
name|p
parameter_list|)
value|(N_BIND(p)& BIND_WEAK)
end_define

begin_typedef
typedef|typedef
struct|struct
name|localsymbol
block|{
name|struct
name|nzlist
name|nzlist
decl_stmt|;
comment|/* n[z]list from file */
name|struct
name|glosym
modifier|*
name|symbol
decl_stmt|;
comment|/* Corresponding global symbol, 						   if any */
name|struct
name|localsymbol
modifier|*
name|next
decl_stmt|;
comment|/* List of definitions */
name|struct
name|file_entry
modifier|*
name|entry
decl_stmt|;
comment|/* Backpointer to file */
name|long
name|gotslot_offset
decl_stmt|;
comment|/* Position in GOT, if any */
name|int
name|symbolnum
decl_stmt|;
comment|/* Position in output nlist */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|LS_L_SYMBOL
value|1
comment|/* Local symbol starts with an `L' */
define|#
directive|define
name|LS_WRITE
value|2
comment|/* Symbol goes in output symtable */
define|#
directive|define
name|LS_RENAME
value|4
comment|/* xlat name to `<file>.<name>' */
define|#
directive|define
name|LS_HASGOTSLOT
value|8
comment|/* This symbol has a GOT entry */
define|#
directive|define
name|LS_WARNING
value|16
comment|/* Second part of a N_WARNING duo */
block|}
name|localsymbol_t
typedef|;
end_typedef

begin_comment
comment|/*  * Global symbol data is recorded in these structures, one for each global  * symbol. They are found via hashing in 'symtab', which points to a vector  * of buckets. Each bucket is a chain of these structures through the link  * field.  *  * Rewritten version to support extra info for dynamic linking.  */
end_comment

begin_struct
struct|struct
name|glosym
block|{
name|struct
name|glosym
modifier|*
name|link
decl_stmt|;
comment|/* Next symbol hash bucket. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of this symbol.  */
name|long
name|value
decl_stmt|;
comment|/* Value of this symbol */
name|localsymbol_t
modifier|*
name|refs
decl_stmt|;
comment|/* Chain of local symbols from object 				   files pertaining to this global 				   symbol */
name|localsymbol_t
modifier|*
name|sorefs
decl_stmt|;
comment|/* Same for local symbols from shared 				   object files. */
name|char
modifier|*
name|warning
decl_stmt|;
comment|/* message, from N_WARNING nlists */
name|int
name|common_size
decl_stmt|;
comment|/* Common size */
name|int
name|symbolnum
decl_stmt|;
comment|/* Symbol index in output symbol table */
name|int
name|rrs_symbolnum
decl_stmt|;
comment|/* Symbol index in RRS symbol table */
name|localsymbol_t
modifier|*
name|def_lsp
decl_stmt|;
comment|/* The local symbol that gave this 					   global symbol its definition */
name|char
name|defined
decl_stmt|;
comment|/* Definition of this symbol */
name|char
name|so_defined
decl_stmt|;
comment|/* Definition of this symbol in a shared 				   object. These go into the RRS symbol table */
name|u_char
name|undef_refs
decl_stmt|;
comment|/* Count of number of "undefined" 				   messages printed for this symbol */
name|u_char
name|mult_defs
decl_stmt|;
comment|/* Same for "multiply defined" symbols */
name|struct
name|glosym
modifier|*
name|alias
decl_stmt|;
comment|/* For symbols of type N_INDR, this 				   points at the real symbol. */
name|int
name|setv_count
decl_stmt|;
comment|/* Number of elements in N_SETV symbols */
name|int
name|size
decl_stmt|;
comment|/* Size of this symbol (either from N_SIZE 				   symbols or a from shared object's RRS */
name|int
name|aux
decl_stmt|;
comment|/* Auxiliary type information conveyed in 				   the `n_other' field of nlists */
comment|/* The offset into one of the RRS tables, -1 if not used */
name|long
name|jmpslot_offset
decl_stmt|;
name|long
name|gotslot_offset
decl_stmt|;
name|long
name|flags
decl_stmt|;
define|#
directive|define
name|GS_DEFINED
value|0x1
comment|/* Symbol has definition (notyetused)*/
define|#
directive|define
name|GS_REFERENCED
value|0x2
comment|/* Symbol is referred to by something 					   interesting */
define|#
directive|define
name|GS_TRACE
value|0x4
comment|/* Symbol will be traced */
define|#
directive|define
name|GS_HASJMPSLOT
value|0x8
comment|/*				 */
define|#
directive|define
name|GS_HASGOTSLOT
value|0x10
comment|/* Some state bits concerning    */
define|#
directive|define
name|GS_CPYRELOCRESERVED
value|0x20
comment|/* entries in GOT and PLT tables */
define|#
directive|define
name|GS_CPYRELOCCLAIMED
value|0x40
comment|/*				 */
define|#
directive|define
name|GS_WEAK
value|0x80
comment|/* Symbol is weakly defined */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|__symbol_defined__
end_ifndef

begin_define
define|#
directive|define
name|__symbol_defined__
end_define

begin_typedef
typedef|typedef
name|struct
name|glosym
name|symbol
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The symbol hash table: a vector of SYMTABSIZE pointers to struct glosym. */
end_comment

begin_decl_stmt
specifier|extern
name|symbol
modifier|*
name|symtab
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FOR_EACH_SYMBOL
parameter_list|(
name|i
parameter_list|,
name|sp
parameter_list|)
value|{					\ 	int i;							\ 	for (i = 0; i< SYMTABSIZE; i++) {				\ 		register symbol *sp;				\ 		for (sp = symtab[i]; sp; sp = sp->link)
end_define

begin_define
define|#
directive|define
name|END_EACH_SYMBOL
value|}}
end_define

begin_decl_stmt
specifier|extern
name|symbol
modifier|*
name|got_symbol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the symbol __GLOBAL_OFFSET_TABLE_ */
end_comment

begin_decl_stmt
specifier|extern
name|symbol
modifier|*
name|dynamic_symbol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the symbol __DYNAMIC */
end_comment

begin_comment
comment|/*  * Each input file, and each library member ("subfile") being loaded, has a  * `file_entry' structure for it.  *  * For files specified by command args, these are contained in the vector which  * `file_table' points to.  *  * For library members, they are dynamically allocated, and chained through the  * `chain' field. The chain is found in the `subfiles' field of the  * `file_entry'. The `file_entry' objects for the members have `superfile'  * fields pointing to the one for the library.  *  * Rewritten version to support extra info for dynamic linking.  */
end_comment

begin_struct
struct|struct
name|file_entry
block|{
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* Name of this file.  */
comment|/* 	 * Name to use for the symbol giving address of text start Usually 	 * the same as filename, but for a file spec'd with -l this is the -l 	 * switch itself rather than the filename. 	 */
name|char
modifier|*
name|local_sym_name
decl_stmt|;
name|struct
name|exec
name|header
decl_stmt|;
comment|/* The file's a.out header.  */
name|localsymbol_t
modifier|*
name|symbols
decl_stmt|;
comment|/* Symbol table of the file. */
name|int
name|nsymbols
decl_stmt|;
comment|/* Number of symbols in above array. */
name|int
name|string_size
decl_stmt|;
comment|/* Size in bytes of string table. */
name|char
modifier|*
name|strings
decl_stmt|;
comment|/* Pointer to the string table when 					   in core, NULL otherwise */
name|int
name|strings_offset
decl_stmt|;
comment|/* Offset of string table, 					   (normally N_STROFF() + 4) */
comment|/* 	 * Next two used only if `relocatable_output' or if needed for 	 * output of undefined reference line numbers. 	 */
name|struct
name|relocation_info
modifier|*
name|textrel
decl_stmt|;
comment|/* Text relocations */
name|int
name|ntextrel
decl_stmt|;
comment|/* # of text relocations */
name|struct
name|relocation_info
modifier|*
name|datarel
decl_stmt|;
comment|/* Data relocations */
name|int
name|ndatarel
decl_stmt|;
comment|/* # of data relocations */
comment|/* 	 * Relation of this file's segments to the output file. 	 */
name|int
name|text_start_address
decl_stmt|;
comment|/* Start of this file's text segment 					   in the output file core image. */
name|int
name|data_start_address
decl_stmt|;
comment|/* Start of this file's data segment 					   in the output file core image. */
name|int
name|bss_start_address
decl_stmt|;
comment|/* Start of this file's bss segment 					   in the output file core image. */
name|struct
name|file_entry
modifier|*
name|subfiles
decl_stmt|;
comment|/* For a library, points to chain of 					   entries for the library members. */
name|struct
name|file_entry
modifier|*
name|superfile
decl_stmt|;
comment|/* For library member, points to the 					   library's own entry.  */
name|struct
name|file_entry
modifier|*
name|chain
decl_stmt|;
comment|/* For library member, points to next 					   entry for next member.  */
name|int
name|starting_offset
decl_stmt|;
comment|/* For a library member, offset of the 					   member within the archive. Zero for 					   files that are not library members.*/
name|int
name|total_size
decl_stmt|;
comment|/* Size of contents of this file, 					   if library member. */
ifdef|#
directive|ifdef
name|SUN_COMPAT
name|struct
name|file_entry
modifier|*
name|silly_archive
decl_stmt|;
comment|/* For shared libraries which have 					    a .sa companion */
endif|#
directive|endif
name|int
name|lib_major
decl_stmt|,
name|lib_minor
decl_stmt|;
comment|/* Version numbers of a shared object */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|E_IS_LIBRARY
value|1
comment|/* File is a an archive */
define|#
directive|define
name|E_HEADER_VALID
value|2
comment|/* File's header has been read */
define|#
directive|define
name|E_SEARCH_DIRS
value|4
comment|/* Search directories for file */
define|#
directive|define
name|E_SEARCH_DYNAMIC
value|8
comment|/* Search for shared libs allowed */
define|#
directive|define
name|E_JUST_SYMS
value|0x10
comment|/* File is used for incremental load */
define|#
directive|define
name|E_DYNAMIC
value|0x20
comment|/* File is a shared object */
define|#
directive|define
name|E_SCRAPPED
value|0x40
comment|/* Ignore this file */
define|#
directive|define
name|E_SYMBOLS_USED
value|0x80
comment|/* Symbols from this entry were used */
define|#
directive|define
name|E_SECONDCLASS
value|0x100
comment|/* Shared object is a subsidiary */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Runtime Relocation Section (RRS).  * This describes the data structures that go into the output text and data  * segments to support the run-time linker. The RRS can be empty (plain old  * static linking), or can just exist of GOT and PLT entries (in case of  * statically linked PIC code).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rrs_section_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* What's in the RRS section */
end_comment

begin_define
define|#
directive|define
name|RRS_NONE
value|0
end_define

begin_define
define|#
directive|define
name|RRS_PARTIAL
value|1
end_define

begin_define
define|#
directive|define
name|RRS_FULL
value|2
end_define

begin_decl_stmt
specifier|extern
name|int
name|rrs_text_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of RRS text additions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rrs_text_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Location of above */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rrs_data_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of RRS data additions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rrs_data_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Location of above */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rrs_search_paths
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* `-L' RT paths */
end_comment

begin_comment
comment|/* Version number to put in __DYNAMIC (set by -V) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|soversion
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_SOVERSION
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_SOVERSION
value|LD_VERSION_BSD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|pc_relocation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current PC reloc value */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|number_of_shobjs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of shared objects linked in */
end_comment

begin_comment
comment|/* Current link mode */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|link_mode
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DYNAMIC
value|1
end_define

begin_comment
comment|/* Consider shared libraries */
end_comment

begin_define
define|#
directive|define
name|SYMBOLIC
value|2
end_define

begin_comment
comment|/* Force symbolic resolution */
end_comment

begin_define
define|#
directive|define
name|FORCEARCHIVE
value|4
end_define

begin_comment
comment|/* Force inclusion of all members 					   of archives */
end_comment

begin_define
define|#
directive|define
name|SHAREABLE
value|8
end_define

begin_comment
comment|/* Build a shared object */
end_comment

begin_define
define|#
directive|define
name|SILLYARCHIVE
value|16
end_define

begin_comment
comment|/* Process .sa companions, if any */
end_comment

begin_define
define|#
directive|define
name|FORCEDYNAMIC
value|32
end_define

begin_comment
comment|/* Force dynamic output even if no 					   shared libraries included */
end_comment

begin_define
define|#
directive|define
name|WARNRRSTEXT
value|64
end_define

begin_comment
comment|/* Warn about rrs in text */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|outstream
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output file. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|exec
name|outheader
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output file header. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|magic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output file magic. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|oldmagic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|relocatable_output
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pic_type
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PIC_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PIC_TYPE_SMALL
value|1
end_define

begin_define
define|#
directive|define
name|PIC_TYPE_LARGE
value|2
end_define

begin_decl_stmt
name|void
name|read_header
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_entry_symbols
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_entry_strings
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_entry_relocation
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|enter_file_symbols
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_file_symbols
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|set_element_prefixed_p
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|text_offset
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file_open
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|each_file
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|each_full_file
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|check_each_file
name|__P
argument_list|(
operator|(
name|unsigned
name|long
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mywrite
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|padfile
name|__P
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In warnings.c: */
end_comment

begin_decl_stmt
name|void
name|perror_name
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|perror_file
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_symbols
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|get_file_name
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_file_name
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prline_file_name
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_warnings
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In etc.c: */
end_comment

begin_include
include|#
directive|include
file|"support.h"
end_include

begin_comment
comment|/* In symbol.c: */
end_comment

begin_decl_stmt
name|void
name|symtab_init
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|symbol
modifier|*
name|getsym
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|getsym_soft
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In lib.c: */
end_comment

begin_decl_stmt
name|void
name|search_library
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_shared_object
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|findlib
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In shlib.c: */
end_comment

begin_include
include|#
directive|include
file|"shlib.h"
end_include

begin_comment
comment|/* In rrs.c: */
end_comment

begin_decl_stmt
name|void
name|init_rrs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rrs_add_shobj
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_rrs_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_rrs_segment_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_rrs_jmpslot
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_rrs_gotslot
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|localsymbol_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_rrs_cpy_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|claim_rrs_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|symbol
operator|*
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|claim_rrs_jmpslot
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|symbol
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|claim_rrs_gotslot
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|localsymbol
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|claim_rrs_internal_gotslot
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|localsymbol
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|claim_rrs_cpy_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|claim_rrs_segment_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|consider_rrs_section_lengths
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|relocate_rrs_addresses
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|write_rrs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In<md>.c */
end_comment

begin_decl_stmt
name|void
name|md_init_header
name|__P
argument_list|(
operator|(
expr|struct
name|exec
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|md_get_addend
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_relocate
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
name|long
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_jmpslot
name|__P
argument_list|(
operator|(
name|jmpslot_t
operator|*
operator|,
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_fix_jmpslot
name|__P
argument_list|(
operator|(
name|jmpslot_t
operator|*
operator|,
name|long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|md_make_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_jmpreloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_gotreloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_copyreloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_set_breakpoint
name|__P
argument_list|(
operator|(
name|long
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SWAP
end_ifdef

begin_comment
comment|/* In xbits.c: */
end_comment

begin_decl_stmt
name|void
name|swap_longs
name|__P
argument_list|(
operator|(
name|long
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_symbols
name|__P
argument_list|(
operator|(
expr|struct
name|nlist
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_zsymbols
name|__P
argument_list|(
operator|(
expr|struct
name|nzlist
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_ranlib_hdr
name|__P
argument_list|(
operator|(
expr|struct
name|ranlib
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap__dynamic
name|__P
argument_list|(
operator|(
expr|struct
name|link_dynamic
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_section_dispatch_table
name|__P
argument_list|(
operator|(
expr|struct
name|section_dispatch_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_so_debug
name|__P
argument_list|(
operator|(
expr|struct
name|so_debug
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swapin_sod
name|__P
argument_list|(
operator|(
expr|struct
name|sod
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swapout_sod
name|__P
argument_list|(
operator|(
expr|struct
name|sod
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swapout_fshash
name|__P
argument_list|(
operator|(
expr|struct
name|fshash
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DYNAMIC_H__ */
end_comment

end_unit

