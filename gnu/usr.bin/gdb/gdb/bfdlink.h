begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bfdlink.h -- header file for BFD link routines    Copyright 1993 Free Software Foundation, Inc.    Written by Steve Chamberlain and Ian Lance Taylor, Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/* Discard locals with a certain prefix.  */
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
name|bfd_link_hash_weak
block|,
comment|/* Symbol is weak and undefined.  */
name|bfd_link_hash_defined
block|,
comment|/* Symbol is defined.  */
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
comment|/* Undefined and common symbols are kept in a linked list through      this field.  This field is not in the union because that would      force us to remove entries from the list when we changed their      type, which would force the list to be doubly linked, which would      waste more memory.  When an undefined or common symbol is      created, it should be added to this list, the head of which is in      the link hash table itself.  As symbols are defined, they need      not be removed from the list; anything which reads the list must      doublecheck the symbol type.       Weak symbols are not kept on this list.       Defined symbols use this field as a reference marker.  If the      field is not NULL, or this structure is the tail of the undefined      symbol list, the symbol has been referenced.  If the symbol is      undefined and becomes defined, this field will automatically be      non-NULL since the symbol will have been on the undefined symbol      list.  */
name|struct
name|bfd_link_hash_entry
modifier|*
name|next
decl_stmt|;
comment|/* A union of information depending upon the type.  */
union|union
block|{
comment|/* Nothing is kept for bfd_hash_new.  */
comment|/* bfd_link_hash_undefined, bfd_link_hash_weak.  */
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
comment|/* bfd_link_hash_defined.  */
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
name|bfd_vma
name|size
decl_stmt|;
comment|/* Common symbol size.  */
name|asection
modifier|*
name|section
decl_stmt|;
comment|/* Symbol section.  */
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
comment|/* true if BFD should generate a shared object.  */
name|boolean
name|shared
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
comment|/* The local symbol prefix to discard if using discard_l.  */
name|unsigned
name|int
name|lprefix_len
decl_stmt|;
specifier|const
name|char
modifier|*
name|lprefix
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
comment|/* Hash table of symbols to report back via notice_callback.  If      this is NULL no symbols are reported back.  */
name|struct
name|bfd_hash_table
modifier|*
name|notice_hash
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
comment|/* A function which is called when a common symbol is defined      multiple times.  NAME is the symbol appearing multiple times.      OBFD is the BFD of the existing symbol.  OTYPE is the type of the      existing symbol, either bfd_link_hash_defined or      bfd_link_hash_common.  If OTYPE is bfd_link_hash_common, OSIZE is      the size of the existing symbol.  NBFD is the BFD of the new      symbol.  NTYPE is the type of the new symbol, either      bfd_link_hash_defined or bfd_link_hash_common.  If NTYPE is      bfd_link_hash_common, NSIZE is the size of the new symbol.  */
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
comment|/* A function which is called when there is a reference to a warning      symbol.  WARNING is the warning to be issued.  */
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
operator|)
argument_list|)
expr_stmt|;
comment|/* A function which is called when a relocation is attempted against      an undefined symbol.  NAME is the symbol which is undefined.      ABFD, SECTION and ADDRESS identify the location from which the      reference is made.  */
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

