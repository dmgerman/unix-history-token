begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ldctor.h - linker constructor support    Copyright 1991, 1992, 1993, 1994, 1995, 1998, 2000    Free Software Foundation, Inc.  This file is part of GLD, the Gnu Linker.  GLD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GLD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GLD; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDCTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LDCTOR_H
end_define

begin_comment
comment|/* List of statements needed to handle constructors */
end_comment

begin_decl_stmt
specifier|extern
name|lang_statement_list_type
name|constructor_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether the constructors should be sorted.  Note that this is    global for the entire link; we assume that there is only a single    CONSTRUCTORS command in the linker script.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|constructors_sorted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We keep a list of these structures for each set we build.  */
end_comment

begin_struct
struct|struct
name|set_info
block|{
name|struct
name|set_info
modifier|*
name|next
decl_stmt|;
comment|/* Next set.  */
name|struct
name|bfd_link_hash_entry
modifier|*
name|h
decl_stmt|;
comment|/* Hash table entry.  */
name|bfd_reloc_code_real_type
name|reloc
decl_stmt|;
comment|/* Reloc to use for an entry.  */
name|size_t
name|count
decl_stmt|;
comment|/* Number of elements.  */
name|struct
name|set_element
modifier|*
name|elements
decl_stmt|;
comment|/* Elements in set.  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|set_element
block|{
name|struct
name|set_element
modifier|*
name|next
decl_stmt|;
comment|/* Next element.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name in set (may be NULL).  */
name|asection
modifier|*
name|section
decl_stmt|;
comment|/* Section of value in set.  */
name|bfd_vma
name|value
decl_stmt|;
comment|/* Value in set.  */
block|}
struct|;
end_struct

begin_comment
comment|/* The sets we have seen.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|set_info
modifier|*
name|sets
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ldctor_add_set_entry
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_hash_entry
operator|*
operator|,
name|bfd_reloc_code_real_type
operator|,
specifier|const
name|char
operator|*
operator|,
name|asection
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ldctor_build_sets
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

