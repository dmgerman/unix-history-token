begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bfdlink.h -- header file for BFD link routines    Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2002, 2003,    2004 Free Software Foundation, Inc.    Written by Steve Chamberlain and Ian Lance Taylor, Cygnus Support.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BFDLINK_H
end_ifndef

begin_define
define|#
directive|define
name|BFDLINK_H
end_define

begin_comment
comment|/* Which symbols to strip during a link.  */
end_comment

begin_enum
enum|enum
name|bfd_link_strip
block|{
name|strip_none
block|,
comment|/* Don't strip any symbols.  */
name|strip_debugger
block|,
comment|/* Strip debugging symbols.  */
name|strip_some
block|,
comment|/* keep_hash is the list of symbols to keep.  */
name|strip_all
comment|/* Strip all symbols.  */
block|}
enum|;
end_enum

begin_comment
comment|/* Which local symbols to discard during a link.  This is irrelevant    if strip_all is used.  */
end_comment

begin_enum
enum|enum
name|bfd_link_discard
block|{
name|discard_sec_merge
block|,
comment|/* Discard local temporary symbols in SEC_MERGE 			   sections.  */
name|discard_none
block|,
comment|/* Don't discard any locals.  */
name|discard_l
block|,
comment|/* Discard local temporary symbols.  */
name|discard_all
comment|/* Discard all locals.  */
block|}
enum|;
end_enum

begin_comment
comment|/* Describes the type of hash table entry structure being used.    Different hash table structure have different fields and so    support different linking features.  */
end_comment

begin_enum
enum|enum
name|bfd_link_hash_table_type
block|{
name|bfd_link_generic_hash_table
block|,
name|bfd_link_elf_hash_table
block|}
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/* These are the possible types of an entry in the BFD link hash    table.  */
end_comment

begin_enum
enum|enum
name|bfd_link_hash_type
block|{
name|bfd_link_hash_new
block|,
comment|/* Symbol is new.  */
name|bfd_link_hash_undefined
block|,
comment|/* Symbol seen before, but undefined.  */
name|bfd_link_hash_undefweak
block|,
comment|/* Symbol is weak and undefined.  */
name|bfd_link_hash_defined
block|,
comment|/* Symbol is defined.  */
name|bfd_link_hash_defweak
block|,
comment|/* Symbol is weak and defined.  */
name|bfd_link_hash_common
block|,
comment|/* Symbol is common.  */
name|bfd_link_hash_indirect
block|,
comment|/* Symbol is an indirect link.  */
name|bfd_link_hash_warning
comment|/* Like indirect, but warn if referenced.  */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|bfd_link_common_skip_ar_aymbols
block|{
name|bfd_link_common_skip_none
block|,
name|bfd_link_common_skip_text
block|,
name|bfd_link_common_skip_data
block|,
name|bfd_link_common_skip_all
block|}
enum|;
end_enum

begin_comment
comment|/* The linking routines use a hash table which uses this structure for    its elements.  */
end_comment

begin_struct
struct|struct
name|bfd_link_hash_entry
block|{
comment|/* Base hash table entry structure.  */
name|struct
name|bfd_hash_entry
name|root
decl_stmt|;
comment|/* Type of this entry.  */
name|enum
name|bfd_link_hash_type
name|type
decl_stmt|;
comment|/* Undefined and common symbols are kept in a linked list through      this field.  This field is not in the union because that would      force us to remove entries from the list when we changed their      type, which would force the list to be doubly linked, which would      waste more memory.  When an undefined or common symbol is      created, it should be added to this list, the head of which is in      the link hash table itself.  As symbols are defined, they need      not be removed from the list; anything which reads the list must      doublecheck the symbol type.       Weak symbols are not kept on this list.       Defined and defweak symbols use this field as a reference marker.      If the field is not NULL, or this structure is the tail of the      undefined symbol list, the symbol has been referenced.  If the      symbol is undefined and becomes defined, this field will      automatically be non-NULL since the symbol will have been on the      undefined symbol list.  */
name|struct
name|bfd_link_hash_entry
modifier|*
name|und_next
decl_stmt|;
comment|/* A union of information depending upon the type.  */
union|union
block|{
comment|/* Nothing is kept for bfd_hash_new.  */
comment|/* bfd_link_hash_undefined, bfd_link_hash_undefweak.  */
struct|struct
block|{
name|bfd
modifier|*
name|abfd
decl_stmt|;
comment|/* BFD symbol was found in.  */
block|}
name|undef
struct|;
comment|/* bfd_link_hash_defined, bfd_link_hash_defweak.  */
struct|struct
block|{
name|bfd_vma
name|value
decl_stmt|;
comment|/* Symbol value.  */
name|asection
modifier|*
name|section
decl_stmt|;
comment|/* Symbol section.  */
block|}
name|def
struct|;
comment|/* bfd_link_hash_indirect, bfd_link_hash_warning.  */
struct|struct
block|{
name|struct
name|bfd_link_hash_entry
modifier|*
name|link
decl_stmt|;
comment|/* Real symbol.  */
specifier|const
name|char
modifier|*
name|warning
decl_stmt|;
comment|/* Warning (bfd_link_hash_warning only).  */
block|}
name|i
struct|;
comment|/* bfd_link_hash_common.  */
struct|struct
block|{
comment|/* The linker needs to know three things about common 	     symbols: the size, the alignment, and the section in 	     which the symbol should be placed.  We store the size 	     here, and we allocate a small structure to hold the 	     section and the alignment.  The alignment is stored as a 	     power of two.  We don't store all the information 	     directly because we don't want to increase the size of 	     the union; this structure is a major space user in the 	     linker.  */
name|bfd_size_type
name|size
decl_stmt|;
comment|/* Common symbol size.  */
struct|struct
name|bfd_link_hash_common_entry
block|{
name|unsigned
name|int
name|alignment_power
decl_stmt|;
comment|/* Alignment.  */
name|asection
modifier|*
name|section
decl_stmt|;
comment|/* Symbol section.  */
block|}
modifier|*
name|p
struct|;
block|}
name|c
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* This is the link hash table.  It is a derived class of    bfd_hash_table.  */
end_comment

begin_struct
struct|struct
name|bfd_link_hash_table
block|{
comment|/* The hash table itself.  */
name|struct
name|bfd_hash_table
name|table
decl_stmt|;
comment|/* The back end which created this hash table.  This indicates the      type of the entries in the hash table, which is sometimes      important information when linking object files of different      types together.  */
specifier|const
name|bfd_target
modifier|*
name|creator
decl_stmt|;
comment|/* A linked list of undefined and common symbols, linked through the      next field in the bfd_link_hash_entry structure.  */
name|struct
name|bfd_link_hash_entry
modifier|*
name|undefs
decl_stmt|;
comment|/* Entries are added to the tail of the undefs list.  */
name|struct
name|bfd_link_hash_entry
modifier|*
name|undefs_tail
decl_stmt|;
comment|/* The type of the link hash table.  */
name|enum
name|bfd_link_hash_table_type
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Look up an entry in a link hash table.  If FOLLOW is TRUE, this    follows bfd_link_hash_indirect and bfd_link_hash_warning links to    the real symbol.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|bfd_link_hash_entry
modifier|*
name|bfd_link_hash_lookup
parameter_list|(
name|struct
name|bfd_link_hash_table
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|bfd_boolean
name|create
parameter_list|,
name|bfd_boolean
name|copy
parameter_list|,
name|bfd_boolean
name|follow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Look up an entry in the main linker hash table if the symbol might    be wrapped.  This should only be used for references to an    undefined symbol, not for definitions of a symbol.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|bfd_link_hash_entry
modifier|*
name|bfd_wrapped_link_hash_lookup
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
name|bfd_boolean
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Traverse a link hash table.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|bfd_link_hash_traverse
parameter_list|(
name|struct
name|bfd_link_hash_table
modifier|*
parameter_list|,
name|bfd_boolean
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|bfd_link_hash_entry
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add an entry to the undefs list.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|bfd_link_add_undef
parameter_list|(
name|struct
name|bfd_link_hash_table
modifier|*
parameter_list|,
name|struct
name|bfd_link_hash_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|bfd_sym_chain
block|{
name|struct
name|bfd_sym_chain
modifier|*
name|next
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* How to handle unresolved symbols.    There are four possibilities which are enumerated below:  */
end_comment

begin_enum
enum|enum
name|report_method
block|{
comment|/* This is the initial value when then link_info structure is created.      It allows the various stages of the linker to determine whether they      allowed to set the value.  */
name|RM_NOT_YET_SET
init|=
literal|0
block|,
name|RM_IGNORE
block|,
name|RM_GENERATE_WARNING
block|,
name|RM_GENERATE_ERROR
block|}
enum|;
end_enum

begin_comment
comment|/* This structure holds all the information needed to communicate    between BFD and the linker when doing a link.  */
end_comment

begin_struct
struct|struct
name|bfd_link_info
block|{
comment|/* TRUE if BFD should generate a relocatable object file.  */
name|unsigned
name|int
name|relocatable
range|:
literal|1
decl_stmt|;
comment|/* TRUE if BFD should generate relocation information in the final      executable.  */
name|unsigned
name|int
name|emitrelocations
range|:
literal|1
decl_stmt|;
comment|/* TRUE if BFD should generate a "task linked" object file,      similar to relocatable but also with globals converted to      statics.  */
name|unsigned
name|int
name|task_link
range|:
literal|1
decl_stmt|;
comment|/* TRUE if BFD should generate a shared object.  */
name|unsigned
name|int
name|shared
range|:
literal|1
decl_stmt|;
comment|/* TRUE if BFD should pre-bind symbols in a shared object.  */
name|unsigned
name|int
name|symbolic
range|:
literal|1
decl_stmt|;
comment|/* TRUE if BFD should export all symbols in the dynamic symbol table      of an executable, rather than only those used.  */
name|unsigned
name|int
name|export_dynamic
range|:
literal|1
decl_stmt|;
comment|/* TRUE if shared objects should be linked directly, not shared.  */
name|unsigned
name|int
name|static_link
range|:
literal|1
decl_stmt|;
comment|/* TRUE if the output file should be in a traditional format.  This      is equivalent to the setting of the BFD_TRADITIONAL_FORMAT flag      on the output file, but may be checked when reading the input      files.  */
name|unsigned
name|int
name|traditional_format
range|:
literal|1
decl_stmt|;
comment|/* TRUE if we want to produced optimized output files.  This might      need much more time and therefore must be explicitly selected.  */
name|unsigned
name|int
name|optimize
range|:
literal|1
decl_stmt|;
comment|/* TRUE if ok to have multiple definition.  */
name|unsigned
name|int
name|allow_multiple_definition
range|:
literal|1
decl_stmt|;
comment|/* TRUE if ok to have version with no definition.  */
name|unsigned
name|int
name|allow_undefined_version
range|:
literal|1
decl_stmt|;
comment|/* TRUE if symbols should be retained in memory, FALSE if they      should be freed and reread.  */
name|unsigned
name|int
name|keep_memory
range|:
literal|1
decl_stmt|;
comment|/* TRUE if every symbol should be reported back via the notice      callback.  */
name|unsigned
name|int
name|notice_all
range|:
literal|1
decl_stmt|;
comment|/* TRUE if executable should not contain copy relocs.      Setting this true may result in a non-sharable text segment.  */
name|unsigned
name|int
name|nocopyreloc
range|:
literal|1
decl_stmt|;
comment|/* TRUE if the new ELF dynamic tags are enabled. */
name|unsigned
name|int
name|new_dtags
range|:
literal|1
decl_stmt|;
comment|/* TRUE if non-PLT relocs should be merged into one reloc section      and sorted so that relocs against the same symbol come together.  */
name|unsigned
name|int
name|combreloc
range|:
literal|1
decl_stmt|;
comment|/* TRUE if .eh_frame_hdr section and PT_GNU_EH_FRAME ELF segment      should be created.  */
name|unsigned
name|int
name|eh_frame_hdr
range|:
literal|1
decl_stmt|;
comment|/* TRUE if global symbols in discarded sections should be stripped.  */
name|unsigned
name|int
name|strip_discarded
range|:
literal|1
decl_stmt|;
comment|/* TRUE if the final relax pass is needed.  */
name|unsigned
name|int
name|need_relax_finalize
range|:
literal|1
decl_stmt|;
comment|/* TRUE if generating a position independent executable.  */
name|unsigned
name|int
name|pie
range|:
literal|1
decl_stmt|;
comment|/* TRUE if generating an executable, position independent or not.  */
name|unsigned
name|int
name|executable
range|:
literal|1
decl_stmt|;
comment|/* TRUE if PT_GNU_STACK segment should be created with PF_R|PF_W|PF_X      flags.  */
name|unsigned
name|int
name|execstack
range|:
literal|1
decl_stmt|;
comment|/* TRUE if PT_GNU_STACK segment should be created with PF_R|PF_W      flags.  */
name|unsigned
name|int
name|noexecstack
range|:
literal|1
decl_stmt|;
comment|/* What to do with unresolved symbols in an object file.      When producing executables the default is GENERATE_ERROR.      When producing shared libraries the default is IGNORE.  The      assumption with shared libraries is that the reference will be      resolved at load/execution time.  */
name|enum
name|report_method
name|unresolved_syms_in_objects
decl_stmt|;
comment|/* What to do with unresolved symbols in a shared library.      The same defaults apply.  */
name|enum
name|report_method
name|unresolved_syms_in_shared_libs
decl_stmt|;
comment|/* Which symbols to strip.  */
name|enum
name|bfd_link_strip
name|strip
decl_stmt|;
comment|/* Which local symbols to discard.  */
name|enum
name|bfd_link_discard
name|discard
decl_stmt|;
comment|/* Criteria for skipping symbols when detemining      whether to include an object from an archive. */
name|enum
name|bfd_link_common_skip_ar_aymbols
name|common_skip_ar_aymbols
decl_stmt|;
comment|/* Char that may appear as the first char of a symbol, but should be      skipped (like symbol_leading_char) when looking up symbols in      wrap_hash.  Used by PowerPC Linux for 'dot' symbols.  */
name|char
name|wrap_char
decl_stmt|;
comment|/* Function callbacks.  */
specifier|const
name|struct
name|bfd_link_callbacks
modifier|*
name|callbacks
decl_stmt|;
comment|/* Hash table handled by BFD.  */
name|struct
name|bfd_link_hash_table
modifier|*
name|hash
decl_stmt|;
comment|/* Hash table of symbols to keep.  This is NULL unless strip is      strip_some.  */
name|struct
name|bfd_hash_table
modifier|*
name|keep_hash
decl_stmt|;
comment|/* Hash table of symbols to report back via the notice callback.  If      this is NULL, and notice_all is FALSE, then no symbols are      reported back.  */
name|struct
name|bfd_hash_table
modifier|*
name|notice_hash
decl_stmt|;
comment|/* Hash table of symbols which are being wrapped (the --wrap linker      option).  If this is NULL, no symbols are being wrapped.  */
name|struct
name|bfd_hash_table
modifier|*
name|wrap_hash
decl_stmt|;
comment|/* The list of input BFD's involved in the link.  These are chained      together via the link_next field.  */
name|bfd
modifier|*
name|input_bfds
decl_stmt|;
comment|/* If a symbol should be created for each input BFD, this is section      where those symbols should be placed.  It must be a section in      the output BFD.  It may be NULL, in which case no such symbols      will be created.  This is to support CREATE_OBJECT_SYMBOLS in the      linker command language.  */
name|asection
modifier|*
name|create_object_symbols_section
decl_stmt|;
comment|/* List of global symbol names that are starting points for marking      sections against garbage collection.  */
name|struct
name|bfd_sym_chain
modifier|*
name|gc_sym_list
decl_stmt|;
comment|/* If a base output file is wanted, then this points to it */
name|void
modifier|*
name|base_file
decl_stmt|;
comment|/* The function to call when the executable or shared object is      loaded.  */
specifier|const
name|char
modifier|*
name|init_function
decl_stmt|;
comment|/* The function to call when the executable or shared object is      unloaded.  */
specifier|const
name|char
modifier|*
name|fini_function
decl_stmt|;
comment|/* Non-zero if auto-import thunks for DATA items in pei386 DLLs      should be generated/linked against.  Set to 1 if this feature      is explicitly requested by the user, -1 if enabled by default.  */
name|int
name|pei386_auto_import
decl_stmt|;
comment|/* Non-zero if runtime relocs for DATA items with non-zero addends      in pei386 DLLs should be generated.  Set to 1 if this feature      is explicitly requested by the user, -1 if enabled by default.  */
name|int
name|pei386_runtime_pseudo_reloc
decl_stmt|;
comment|/* How many spare .dynamic DT_NULL entries should be added?  */
name|unsigned
name|int
name|spare_dynamic_tags
decl_stmt|;
comment|/* May be used to set DT_FLAGS for ELF. */
name|bfd_vma
name|flags
decl_stmt|;
comment|/* May be used to set DT_FLAGS_1 for ELF. */
name|bfd_vma
name|flags_1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structures holds a set of callback functions.  These are    called by the BFD linker routines.  The first argument to each    callback function is the bfd_link_info structure being used.  Each    function returns a boolean value.  If the function returns FALSE,    then the BFD function which called it will return with a failure    indication.  */
end_comment

begin_struct
struct|struct
name|bfd_link_callbacks
block|{
comment|/* A function which is called when an object is added from an      archive.  ABFD is the archive element being added.  NAME is the      name of the symbol which caused the archive element to be pulled      in.  */
name|bfd_boolean
function_decl|(
modifier|*
name|add_archive_element
function_decl|)
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/* A function which is called when a symbol is found with multiple      definitions.  NAME is the symbol which is defined multiple times.      OBFD is the old BFD, OSEC is the old section, OVAL is the old      value, NBFD is the new BFD, NSEC is the new section, and NVAL is      the new value.  OBFD may be NULL.  OSEC and NSEC may be      bfd_com_section or bfd_ind_section.  */
name|bfd_boolean
function_decl|(
modifier|*
name|multiple_definition
function_decl|)
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bfd
modifier|*
name|obfd
parameter_list|,
name|asection
modifier|*
name|osec
parameter_list|,
name|bfd_vma
name|oval
parameter_list|,
name|bfd
modifier|*
name|nbfd
parameter_list|,
name|asection
modifier|*
name|nsec
parameter_list|,
name|bfd_vma
name|nval
parameter_list|)
function_decl|;
comment|/* A function which is called when a common symbol is defined      multiple times.  NAME is the symbol appearing multiple times.      OBFD is the BFD of the existing symbol; it may be NULL if this is      not known.  OTYPE is the type of the existing symbol, which may      be bfd_link_hash_defined, bfd_link_hash_defweak,      bfd_link_hash_common, or bfd_link_hash_indirect.  If OTYPE is      bfd_link_hash_common, OSIZE is the size of the existing symbol.      NBFD is the BFD of the new symbol.  NTYPE is the type of the new      symbol, one of bfd_link_hash_defined, bfd_link_hash_common, or      bfd_link_hash_indirect.  If NTYPE is bfd_link_hash_common, NSIZE      is the size of the new symbol.  */
name|bfd_boolean
function_decl|(
modifier|*
name|multiple_common
function_decl|)
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bfd
modifier|*
name|obfd
parameter_list|,
name|enum
name|bfd_link_hash_type
name|otype
parameter_list|,
name|bfd_vma
name|osize
parameter_list|,
name|bfd
modifier|*
name|nbfd
parameter_list|,
name|enum
name|bfd_link_hash_type
name|ntype
parameter_list|,
name|bfd_vma
name|nsize
parameter_list|)
function_decl|;
comment|/* A function which is called to add a symbol to a set.  ENTRY is      the link hash table entry for the set itself (e.g.,      __CTOR_LIST__).  RELOC is the relocation to use for an entry in      the set when generating a relocatable file, and is also used to      get the size of the entry when generating an executable file.      ABFD, SEC and VALUE identify the value to add to the set.  */
name|bfd_boolean
function_decl|(
modifier|*
name|add_to_set
function_decl|)
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|struct
name|bfd_link_hash_entry
modifier|*
name|entry
parameter_list|,
name|bfd_reloc_code_real_type
name|reloc
parameter_list|,
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|sec
parameter_list|,
name|bfd_vma
name|value
parameter_list|)
function_decl|;
comment|/* A function which is called when the name of a g++ constructor or      destructor is found.  This is only called by some object file      formats.  CONSTRUCTOR is TRUE for a constructor, FALSE for a      destructor.  This will use BFD_RELOC_CTOR when generating a      relocatable file.  NAME is the name of the symbol found.  ABFD,      SECTION and VALUE are the value of the symbol.  */
name|bfd_boolean
function_decl|(
modifier|*
name|constructor
function_decl|)
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|bfd_boolean
name|constructor
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|sec
parameter_list|,
name|bfd_vma
name|value
parameter_list|)
function_decl|;
comment|/* A function which is called to issue a linker warning.  For      example, this is called when there is a reference to a warning      symbol.  WARNING is the warning to be issued.  SYMBOL is the name      of the symbol which triggered the warning; it may be NULL if      there is none.  ABFD, SECTION and ADDRESS identify the location      which trigerred the warning; either ABFD or SECTION or both may      be NULL if the location is not known.  */
name|bfd_boolean
function_decl|(
modifier|*
name|warning
function_decl|)
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|warning
parameter_list|,
specifier|const
name|char
modifier|*
name|symbol
parameter_list|,
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|section
parameter_list|,
name|bfd_vma
name|address
parameter_list|)
function_decl|;
comment|/* A function which is called when a relocation is attempted against      an undefined symbol.  NAME is the symbol which is undefined.      ABFD, SECTION and ADDRESS identify the location from which the      reference is made. FATAL indicates whether an undefined symbol is      a fatal error or not. In some cases SECTION may be NULL.  */
name|bfd_boolean
function_decl|(
modifier|*
name|undefined_symbol
function_decl|)
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|section
parameter_list|,
name|bfd_vma
name|address
parameter_list|,
name|bfd_boolean
name|fatal
parameter_list|)
function_decl|;
comment|/* A function which is called when a reloc overflow occurs.  NAME is      the name of the symbol or section the reloc is against,      RELOC_NAME is the name of the relocation, and ADDEND is any      addend that is used.  ABFD, SECTION and ADDRESS identify the      location at which the overflow occurs; if this is the result of a      bfd_section_reloc_link_order or bfd_symbol_reloc_link_order, then      ABFD will be NULL.  */
name|bfd_boolean
function_decl|(
modifier|*
name|reloc_overflow
function_decl|)
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|reloc_name
parameter_list|,
name|bfd_vma
name|addend
parameter_list|,
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|section
parameter_list|,
name|bfd_vma
name|address
parameter_list|)
function_decl|;
comment|/* A function which is called when a dangerous reloc is performed.      The canonical example is an a29k IHCONST reloc which does not      follow an IHIHALF reloc.  MESSAGE is an appropriate message.      ABFD, SECTION and ADDRESS identify the location at which the      problem occurred; if this is the result of a      bfd_section_reloc_link_order or bfd_symbol_reloc_link_order, then      ABFD will be NULL.  */
name|bfd_boolean
function_decl|(
modifier|*
name|reloc_dangerous
function_decl|)
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|section
parameter_list|,
name|bfd_vma
name|address
parameter_list|)
function_decl|;
comment|/* A function which is called when a reloc is found to be attached      to a symbol which is not being written out.  NAME is the name of      the symbol.  ABFD, SECTION and ADDRESS identify the location of      the reloc; if this is the result of a      bfd_section_reloc_link_order or bfd_symbol_reloc_link_order, then      ABFD will be NULL.  */
name|bfd_boolean
function_decl|(
modifier|*
name|unattached_reloc
function_decl|)
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|section
parameter_list|,
name|bfd_vma
name|address
parameter_list|)
function_decl|;
comment|/* A function which is called when a symbol in notice_hash is      defined or referenced.  NAME is the symbol.  ABFD, SECTION and      ADDRESS are the value of the symbol.  If SECTION is      bfd_und_section, this is a reference.  */
name|bfd_boolean
function_decl|(
modifier|*
name|notice
function_decl|)
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|section
parameter_list|,
name|bfd_vma
name|address
parameter_list|)
function_decl|;
comment|/* A function which is called for reporting a linker error. ID is the      error identifier. The remaining input is the same as einfo () in      ld.  */
name|bfd_boolean
function_decl|(
modifier|*
name|error_handler
function_decl|)
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|/* Identifiers of linker error messages used by error_handler.  */
define|#
directive|define
name|LD_DEFINITION_IN_DISCARDED_SECTION
value|1
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* The linker builds link_order structures which tell the code how to    include input data in the output file.  */
end_comment

begin_comment
comment|/* These are the types of link_order structures.  */
end_comment

begin_enum
enum|enum
name|bfd_link_order_type
block|{
name|bfd_undefined_link_order
block|,
comment|/* Undefined.  */
name|bfd_indirect_link_order
block|,
comment|/* Built from a section.  */
name|bfd_data_link_order
block|,
comment|/* Set to explicit data.  */
name|bfd_section_reloc_link_order
block|,
comment|/* Relocate against a section.  */
name|bfd_symbol_reloc_link_order
comment|/* Relocate against a symbol.  */
block|}
enum|;
end_enum

begin_comment
comment|/* This is the link_order structure itself.  These form a chain    attached to the section whose contents they are describing.  */
end_comment

begin_struct
struct|struct
name|bfd_link_order
block|{
comment|/* Next link_order in chain.  */
name|struct
name|bfd_link_order
modifier|*
name|next
decl_stmt|;
comment|/* Type of link_order.  */
name|enum
name|bfd_link_order_type
name|type
decl_stmt|;
comment|/* Offset within output section.  */
name|bfd_vma
name|offset
decl_stmt|;
comment|/* Size within output section.  */
name|bfd_size_type
name|size
decl_stmt|;
comment|/* Type specific information.  */
union|union
block|{
struct|struct
block|{
comment|/* Section to include.  If this is used, then 	     section->output_section must be the section the 	     link_order is attached to, section->output_offset must 	     equal the link_order offset field, and section->_raw_size 	     must equal the link_order size field.  Maybe these 	     restrictions should be relaxed someday.  */
name|asection
modifier|*
name|section
decl_stmt|;
block|}
name|indirect
struct|;
struct|struct
block|{
comment|/* Size of contents, or zero when contents size == size 	     within output section. 	     A non-zero value allows filling of the output section 	     with an arbitrary repeated pattern.  */
name|unsigned
name|int
name|size
decl_stmt|;
comment|/* Data to put into file.  */
name|bfd_byte
modifier|*
name|contents
decl_stmt|;
block|}
name|data
struct|;
struct|struct
block|{
comment|/* Description of reloc to generate.  Used for 	     bfd_section_reloc_link_order and 	     bfd_symbol_reloc_link_order.  */
name|struct
name|bfd_link_order_reloc
modifier|*
name|p
decl_stmt|;
block|}
name|reloc
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* A linker order of type bfd_section_reloc_link_order or    bfd_symbol_reloc_link_order means to create a reloc against a    section or symbol, respectively.  This is used to implement -Ur to    generate relocs for the constructor tables.  The    bfd_link_order_reloc structure describes the reloc that BFD should    create.  It is similar to a arelent, but I didn't use arelent    because the linker does not know anything about most symbols, and    any asymbol structure it creates will be partially meaningless.    This information could logically be in the bfd_link_order struct,    but I didn't want to waste the space since these types of relocs    are relatively rare.  */
end_comment

begin_struct
struct|struct
name|bfd_link_order_reloc
block|{
comment|/* Reloc type.  */
name|bfd_reloc_code_real_type
name|reloc
decl_stmt|;
union|union
block|{
comment|/* For type bfd_section_reloc_link_order, this is the section 	 the reloc should be against.  This must be a section in the 	 output BFD, not any of the input BFDs.  */
name|asection
modifier|*
name|section
decl_stmt|;
comment|/* For type bfd_symbol_reloc_link_order, this is the name of the 	 symbol the reloc should be against.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|u
union|;
comment|/* Addend to use.  The object file should contain zero.  The BFD      backend is responsible for filling in the contents of the object      file correctly.  For some object file formats (e.g., COFF) the      addend must be stored into in the object file, and for some      (e.g., SPARC a.out) it is kept in the reloc.  */
name|bfd_vma
name|addend
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Allocate a new link_order for a section.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|bfd_link_order
modifier|*
name|bfd_new_link_order
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These structures are used to describe version information for the    ELF linker.  These structures could be manipulated entirely inside    BFD, but it would be a pain.  Instead, the regular linker sets up    these structures, and then passes them into BFD.  */
end_comment

begin_comment
comment|/* Glob pattern for a version.  */
end_comment

begin_struct
struct|struct
name|bfd_elf_version_expr
block|{
comment|/* Next glob pattern for this version.  */
name|struct
name|bfd_elf_version_expr
modifier|*
name|next
decl_stmt|;
comment|/* Glob pattern.  */
specifier|const
name|char
modifier|*
name|pattern
decl_stmt|;
comment|/* NULL for a glob pattern, otherwise a straight symbol.  */
specifier|const
name|char
modifier|*
name|symbol
decl_stmt|;
comment|/* Defined by ".symver".  */
name|unsigned
name|int
name|symver
range|:
literal|1
decl_stmt|;
comment|/* Defined by version script.  */
name|unsigned
name|int
name|script
range|:
literal|1
decl_stmt|;
comment|/* Pattern type.  */
define|#
directive|define
name|BFD_ELF_VERSION_C_TYPE
value|1
define|#
directive|define
name|BFD_ELF_VERSION_CXX_TYPE
value|2
define|#
directive|define
name|BFD_ELF_VERSION_JAVA_TYPE
value|4
name|unsigned
name|int
name|mask
range|:
literal|3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bfd_elf_version_expr_head
block|{
comment|/* List of all patterns, both wildcards and non-wildcards.  */
name|struct
name|bfd_elf_version_expr
modifier|*
name|list
decl_stmt|;
comment|/* Hash table for non-wildcards.  */
name|void
modifier|*
name|htab
decl_stmt|;
comment|/* Remaining patterns.  */
name|struct
name|bfd_elf_version_expr
modifier|*
name|remaining
decl_stmt|;
comment|/* What kind of pattern types are present in list (bitmask).  */
name|unsigned
name|int
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Version dependencies.  */
end_comment

begin_struct
struct|struct
name|bfd_elf_version_deps
block|{
comment|/* Next dependency for this version.  */
name|struct
name|bfd_elf_version_deps
modifier|*
name|next
decl_stmt|;
comment|/* The version which this version depends upon.  */
name|struct
name|bfd_elf_version_tree
modifier|*
name|version_needed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A node in the version tree.  */
end_comment

begin_struct
struct|struct
name|bfd_elf_version_tree
block|{
comment|/* Next version.  */
name|struct
name|bfd_elf_version_tree
modifier|*
name|next
decl_stmt|;
comment|/* Name of this version.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Version number.  */
name|unsigned
name|int
name|vernum
decl_stmt|;
comment|/* Regular expressions for global symbols in this version.  */
name|struct
name|bfd_elf_version_expr_head
name|globals
decl_stmt|;
comment|/* Regular expressions for local symbols in this version.  */
name|struct
name|bfd_elf_version_expr_head
name|locals
decl_stmt|;
comment|/* List of versions which this version depends upon.  */
name|struct
name|bfd_elf_version_deps
modifier|*
name|deps
decl_stmt|;
comment|/* Index of the version name.  This is used within BFD.  */
name|unsigned
name|int
name|name_indx
decl_stmt|;
comment|/* Whether this version tree was used.  This is used within BFD.  */
name|int
name|used
decl_stmt|;
comment|/* Matching hook.  */
name|struct
name|bfd_elf_version_expr
modifier|*
function_decl|(
modifier|*
name|match
function_decl|)
parameter_list|(
name|struct
name|bfd_elf_version_expr_head
modifier|*
name|head
parameter_list|,
name|struct
name|bfd_elf_version_expr
modifier|*
name|prev
parameter_list|,
specifier|const
name|char
modifier|*
name|sym
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

