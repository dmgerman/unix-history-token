begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bfdlink.h -- header file for BFD link routines    Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000    Free Software Foundation, Inc.    Written by Steve Chamberlain and Ian Lance Taylor, Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|next
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
comment|/* The linker needs to know three things about common              symbols: the size, the alignment, and the section in              which the symbol should be placed.  We store the size              here, and we allocate a small structure to hold the              section and the alignment.  The alignment is stored as a              power of two.  We don't store all the information              directly because we don't want to increase the size of              the union; this structure is a major space user in the              linker.  */
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
block|}
struct|;
end_struct

begin_comment
comment|/* Look up an entry in a link hash table.  If FOLLOW is true, this    follows bfd_link_hash_indirect and bfd_link_hash_warning links to    the real symbol.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bfd_link_hash_entry
modifier|*
name|bfd_link_hash_lookup
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_hash_table
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|boolean
name|create
operator|,
name|boolean
name|copy
operator|,
name|boolean
name|follow
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Look up an entry in the main linker hash table if the symbol might    be wrapped.  This should only be used for references to an    undefined symbol, not for definitions of a symbol.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bfd_link_hash_entry
modifier|*
name|bfd_wrapped_link_hash_lookup
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|boolean
operator|,
name|boolean
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Traverse a link hash table.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bfd_link_hash_traverse
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_hash_table
operator|*
operator|,
name|boolean
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|bfd_link_hash_entry
operator|*
argument_list|,
name|PTR
argument_list|)
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add an entry to the undefs list.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bfd_link_add_undef
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_hash_table
operator|*
operator|,
expr|struct
name|bfd_link_hash_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* This structure holds all the information needed to communicate    between BFD and the linker when doing a link.  */
end_comment

begin_struct
struct|struct
name|bfd_link_info
block|{
comment|/* Function callbacks.  */
specifier|const
name|struct
name|bfd_link_callbacks
modifier|*
name|callbacks
decl_stmt|;
comment|/* true if BFD should generate a relocateable object file.  */
name|boolean
name|relocateable
decl_stmt|;
comment|/* true if BFD should generate relocation information in the final executable.  */
name|boolean
name|emitrelocations
decl_stmt|;
comment|/* true if BFD should generate a "task linked" object file,      similar to relocatable but also with globals converted to statics. */
name|boolean
name|task_link
decl_stmt|;
comment|/* true if BFD should generate a shared object.  */
name|boolean
name|shared
decl_stmt|;
comment|/* true if BFD should pre-bind symbols in a shared object.  */
name|boolean
name|symbolic
decl_stmt|;
comment|/* true if shared objects should be linked directly, not shared.  */
name|boolean
name|static_link
decl_stmt|;
comment|/* true if the output file should be in a traditional format.  This      is equivalent to the setting of the BFD_TRADITIONAL_FORMAT flag      on the output file, but may be checked when reading the input      files.  */
name|boolean
name|traditional_format
decl_stmt|;
comment|/* true if we want to produced optimized output files.  This might      need much more time and therefore must be explicitly selected.  */
name|boolean
name|optimize
decl_stmt|;
comment|/* true if BFD should generate errors for undefined symbols      even if generating a shared object.  */
name|boolean
name|no_undefined
decl_stmt|;
comment|/* true if BFD should allow undefined symbols in shared objects even      when no_undefined is set to disallow undefined symbols.  The net      result will be that undefined symbols in regular objects will      still trigger an error, but undefined symbols in shared objects      will be ignored.  The implementation of no_undefined makes the      assumption that the runtime linker will choke on undefined      symbols.  However there is at least one system (BeOS) where      undefined symbols in shared libraries is normal since the kernel      patches them at load time to select which function is most      appropriate for the current architecture.  I.E. dynamically      select an appropriate memset function.  Apparently it is also      normal for HPPA shared libraries to have undefined symbols.  */
name|boolean
name|allow_shlib_undefined
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
comment|/* true if symbols should be retained in memory, false if they      should be freed and reread.  */
name|boolean
name|keep_memory
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
comment|/* true if every symbol should be reported back via the notice      callback.  */
name|boolean
name|notice_all
decl_stmt|;
comment|/* Hash table of symbols to report back via the notice callback.  If      this is NULL, and notice_all is false, then no symbols are      reported back.  */
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
comment|/* If a base output file is wanted, then this points to it */
name|PTR
name|base_file
decl_stmt|;
comment|/* If non-zero, specifies that branches which are problematic for the   MPC860 C0 (or earlier) should be checked for and modified.  It gives the   number of bytes that should be checked at the end of each text page. */
name|int
name|mpc860c0
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
comment|/* true if the new ELF dynamic tags are enabled. */
name|boolean
name|new_dtags
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
comment|/* This structures holds a set of callback functions.  These are    called by the BFD linker routines.  The first argument to each    callback function is the bfd_link_info structure being used.  Each    function returns a boolean value.  If the function returns false,    then the BFD function which called it will return with a failure    indication.  */
end_comment

begin_struct
struct|struct
name|bfd_link_callbacks
block|{
comment|/* A function which is called when an object is added from an      archive.  ABFD is the archive element being added.  NAME is the      name of the symbol which caused the archive element to be pulled      in.  */
name|boolean
argument_list|(
argument|*add_archive_element
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
name|bfd
operator|*
name|abfd
operator|,
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
expr_stmt|;
comment|/* A function which is called when a symbol is found with multiple      definitions.  NAME is the symbol which is defined multiple times.      OBFD is the old BFD, OSEC is the old section, OVAL is the old      value, NBFD is the new BFD, NSEC is the new section, and NVAL is      the new value.  OBFD may be NULL.  OSEC and NSEC may be      bfd_com_section or bfd_ind_section.  */
name|boolean
argument_list|(
argument|*multiple_definition
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
name|bfd
operator|*
name|obfd
operator|,
name|asection
operator|*
name|osec
operator|,
name|bfd_vma
name|oval
operator|,
name|bfd
operator|*
name|nbfd
operator|,
name|asection
operator|*
name|nsec
operator|,
name|bfd_vma
name|nval
operator|)
argument_list|)
expr_stmt|;
comment|/* A function which is called when a common symbol is defined      multiple times.  NAME is the symbol appearing multiple times.      OBFD is the BFD of the existing symbol; it may be NULL if this is      not known.  OTYPE is the type of the existing symbol, which may      be bfd_link_hash_defined, bfd_link_hash_defweak,      bfd_link_hash_common, or bfd_link_hash_indirect.  If OTYPE is      bfd_link_hash_common, OSIZE is the size of the existing symbol.      NBFD is the BFD of the new symbol.  NTYPE is the type of the new      symbol, one of bfd_link_hash_defined, bfd_link_hash_common, or      bfd_link_hash_indirect.  If NTYPE is bfd_link_hash_common, NSIZE      is the size of the new symbol.  */
name|boolean
argument_list|(
argument|*multiple_common
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
name|bfd
operator|*
name|obfd
operator|,
expr|enum
name|bfd_link_hash_type
name|otype
operator|,
name|bfd_vma
name|osize
operator|,
name|bfd
operator|*
name|nbfd
operator|,
expr|enum
name|bfd_link_hash_type
name|ntype
operator|,
name|bfd_vma
name|nsize
operator|)
argument_list|)
expr_stmt|;
comment|/* A function which is called to add a symbol to a set.  ENTRY is      the link hash table entry for the set itself (e.g.,      __CTOR_LIST__).  RELOC is the relocation to use for an entry in      the set when generating a relocateable file, and is also used to      get the size of the entry when generating an executable file.      ABFD, SEC and VALUE identify the value to add to the set.  */
name|boolean
argument_list|(
argument|*add_to_set
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
expr|struct
name|bfd_link_hash_entry
operator|*
name|entry
operator|,
name|bfd_reloc_code_real_type
name|reloc
operator|,
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|sec
operator|,
name|bfd_vma
name|value
operator|)
argument_list|)
expr_stmt|;
comment|/* A function which is called when the name of a g++ constructor or      destructor is found.  This is only called by some object file      formats.  CONSTRUCTOR is true for a constructor, false for a      destructor.  This will use BFD_RELOC_CTOR when generating a      relocateable file.  NAME is the name of the symbol found.  ABFD,      SECTION and VALUE are the value of the symbol.  */
name|boolean
argument_list|(
argument|*constructor
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
name|boolean
name|constructor
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|sec
operator|,
name|bfd_vma
name|value
operator|)
argument_list|)
expr_stmt|;
comment|/* A function which is called to issue a linker warning.  For      example, this is called when there is a reference to a warning      symbol.  WARNING is the warning to be issued.  SYMBOL is the name      of the symbol which triggered the warning; it may be NULL if      there is none.  ABFD, SECTION and ADDRESS identify the location      which trigerred the warning; either ABFD or SECTION or both may      be NULL if the location is not known.  */
name|boolean
argument_list|(
argument|*warning
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
specifier|const
name|char
operator|*
name|warning
operator|,
specifier|const
name|char
operator|*
name|symbol
operator|,
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|section
operator|,
name|bfd_vma
name|address
operator|)
argument_list|)
expr_stmt|;
comment|/* A function which is called when a relocation is attempted against      an undefined symbol.  NAME is the symbol which is undefined.      ABFD, SECTION and ADDRESS identify the location from which the      reference is made. FATAL indicates whether an undefined symbol is      a fatal error or not. In some cases SECTION may be NULL.  */
name|boolean
argument_list|(
argument|*undefined_symbol
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|section
operator|,
name|bfd_vma
name|address
operator|,
name|boolean
name|fatal
operator|)
argument_list|)
expr_stmt|;
comment|/* A function which is called when a reloc overflow occurs.  NAME is      the name of the symbol or section the reloc is against,      RELOC_NAME is the name of the relocation, and ADDEND is any      addend that is used.  ABFD, SECTION and ADDRESS identify the      location at which the overflow occurs; if this is the result of a      bfd_section_reloc_link_order or bfd_symbol_reloc_link_order, then      ABFD will be NULL.  */
name|boolean
argument_list|(
argument|*reloc_overflow
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
specifier|const
name|char
operator|*
name|reloc_name
operator|,
name|bfd_vma
name|addend
operator|,
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|section
operator|,
name|bfd_vma
name|address
operator|)
argument_list|)
expr_stmt|;
comment|/* A function which is called when a dangerous reloc is performed.      The canonical example is an a29k IHCONST reloc which does not      follow an IHIHALF reloc.  MESSAGE is an appropriate message.      ABFD, SECTION and ADDRESS identify the location at which the      problem occurred; if this is the result of a      bfd_section_reloc_link_order or bfd_symbol_reloc_link_order, then      ABFD will be NULL.  */
name|boolean
argument_list|(
argument|*reloc_dangerous
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
specifier|const
name|char
operator|*
name|message
operator|,
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|section
operator|,
name|bfd_vma
name|address
operator|)
argument_list|)
expr_stmt|;
comment|/* A function which is called when a reloc is found to be attached      to a symbol which is not being written out.  NAME is the name of      the symbol.  ABFD, SECTION and ADDRESS identify the location of      the reloc; if this is the result of a      bfd_section_reloc_link_order or bfd_symbol_reloc_link_order, then      ABFD will be NULL.  */
name|boolean
argument_list|(
argument|*unattached_reloc
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|section
operator|,
name|bfd_vma
name|address
operator|)
argument_list|)
expr_stmt|;
comment|/* A function which is called when a symbol in notice_hash is      defined or referenced.  NAME is the symbol.  ABFD, SECTION and      ADDRESS are the value of the symbol.  If SECTION is      bfd_und_section, this is a reference.  */
name|boolean
argument_list|(
argument|*notice
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|section
operator|,
name|bfd_vma
name|address
operator|)
argument_list|)
expr_stmt|;
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
name|bfd_fill_link_order
block|,
comment|/* Fill with a 16 bit constant.  */
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
comment|/* Value to fill with.  */
name|unsigned
name|int
name|value
decl_stmt|;
block|}
name|fill
struct|;
struct|struct
block|{
comment|/* Data to put into file.  The size field gives the number 	     of bytes which this field points to.  */
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

begin_decl_stmt
specifier|extern
name|struct
name|bfd_link_order
modifier|*
name|bfd_new_link_order
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These structures are used to describe version information for the    ELF linker.  These structures could be manipulated entirely inside    BFD, but it would be a pain.  Instead, the regular linker sets up    these structures, and then passes them into BFD.  */
end_comment

begin_comment
comment|/* Regular expressions for a version.  */
end_comment

begin_struct
struct|struct
name|bfd_elf_version_expr
block|{
comment|/* Next regular expression for this version.  */
name|struct
name|bfd_elf_version_expr
modifier|*
name|next
decl_stmt|;
comment|/* Regular expression.  */
specifier|const
name|char
modifier|*
name|pattern
decl_stmt|;
comment|/* Matching function.  */
name|int
argument_list|(
argument|*match
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_elf_version_expr
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
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
name|bfd_elf_version_expr
modifier|*
name|globals
decl_stmt|;
comment|/* Regular expressions for local symbols in this version.  */
name|struct
name|bfd_elf_version_expr
modifier|*
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
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

