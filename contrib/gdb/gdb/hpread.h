begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hpread.h  * Common include file for:  *   hp_symtab_read.c  *   hp_psymtab_read.c  */
end_comment

begin_comment
comment|/* Copyright 1993, 1996 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by the Center for Software Science at the University of Utah    and by Cygnus Support.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"gdb_string.h"
end_include

begin_include
include|#
directive|include
file|"hp-symtab.h"
end_include

begin_include
include|#
directive|include
file|"syms.h"
end_include

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"symfile.h"
end_include

begin_include
include|#
directive|include
file|"objfiles.h"
end_include

begin_include
include|#
directive|include
file|"buildsym.h"
end_include

begin_include
include|#
directive|include
file|"complaints.h"
end_include

begin_include
include|#
directive|include
file|"gdb-stabs.h"
end_include

begin_include
include|#
directive|include
file|"gdbtypes.h"
end_include

begin_include
include|#
directive|include
file|"demangle.h"
end_include

begin_comment
comment|/* Private information attached to an objfile which we use to find    and internalize the HP C debug symbols within that objfile.  */
end_comment

begin_struct
struct|struct
name|hpread_symfile_info
block|{
comment|/* The contents of each of the debug sections (there are 4 of them).  */
name|char
modifier|*
name|gntt
decl_stmt|;
name|char
modifier|*
name|lntt
decl_stmt|;
name|char
modifier|*
name|slt
decl_stmt|;
name|char
modifier|*
name|vt
decl_stmt|;
comment|/* We keep the size of the $VT$ section for range checking.  */
name|unsigned
name|int
name|vt_size
decl_stmt|;
comment|/* Some routines still need to know the number of symbols in the      main debug sections ($LNTT$ and $GNTT$). */
name|unsigned
name|int
name|lntt_symcount
decl_stmt|;
name|unsigned
name|int
name|gntt_symcount
decl_stmt|;
comment|/* To keep track of all the types we've processed.  */
name|struct
name|type
modifier|*
modifier|*
name|type_vector
decl_stmt|;
name|int
name|type_vector_length
decl_stmt|;
comment|/* Keeps track of the beginning of a range of source lines.  */
name|sltpointer
name|sl_index
decl_stmt|;
comment|/* Some state variables we'll need.  */
name|int
name|within_function
decl_stmt|;
comment|/* Keep track of the current function's address.  We may need to look      up something based on this address.  */
name|unsigned
name|int
name|current_function_value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Accessor macros to get at the fields.  */
end_comment

begin_define
define|#
directive|define
name|HPUX_SYMFILE_INFO
parameter_list|(
name|o
parameter_list|)
define|\
value|((struct hpread_symfile_info *)((o)->sym_private))
end_define

begin_define
define|#
directive|define
name|GNTT
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->gntt)
end_define

begin_define
define|#
directive|define
name|LNTT
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->lntt)
end_define

begin_define
define|#
directive|define
name|SLT
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->slt)
end_define

begin_define
define|#
directive|define
name|VT
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->vt)
end_define

begin_define
define|#
directive|define
name|VT_SIZE
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->vt_size)
end_define

begin_define
define|#
directive|define
name|LNTT_SYMCOUNT
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->lntt_symcount)
end_define

begin_define
define|#
directive|define
name|GNTT_SYMCOUNT
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->gntt_symcount)
end_define

begin_define
define|#
directive|define
name|TYPE_VECTOR
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->type_vector)
end_define

begin_define
define|#
directive|define
name|TYPE_VECTOR_LENGTH
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->type_vector_length)
end_define

begin_define
define|#
directive|define
name|SL_INDEX
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->sl_index)
end_define

begin_define
define|#
directive|define
name|WITHIN_FUNCTION
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->within_function)
end_define

begin_define
define|#
directive|define
name|CURRENT_FUNCTION_VALUE
parameter_list|(
name|o
parameter_list|)
value|(HPUX_SYMFILE_INFO(o)->current_function_value)
end_define

begin_comment
comment|/* Given the native debug symbol SYM, set NAMEP to the name associated    with the debug symbol.  Note we may be called with a debug symbol which    has no associated name, in that case we return an empty string.     Also note we "know" that the name for any symbol is always in the    same place.  Hence we don't have to conditionalize on the symbol type.  */
end_comment

begin_define
define|#
directive|define
name|SET_NAMESTRING
parameter_list|(
name|SYM
parameter_list|,
name|NAMEP
parameter_list|,
name|OBJFILE
parameter_list|)
define|\
value|if (! hpread_has_name ((SYM)->dblock.kind)) \     *NAMEP = ""; \   else if (((unsigned)(SYM)->dsfile.name)>= VT_SIZE (OBJFILE)) \     { \       complain (&string_table_offset_complaint, (char *) symnum); \       *NAMEP = ""; \     } \   else \     *NAMEP = (SYM)->dsfile.name + VT (OBJFILE)
end_define

begin_escape
end_escape

begin_comment
comment|/* We put a pointer to this structure in the read_symtab_private field    of the psymtab.  */
end_comment

begin_struct
struct|struct
name|symloc
block|{
comment|/* The offset within the file symbol table of first local symbol for      this file.  */
name|int
name|ldsymoff
decl_stmt|;
comment|/* Length (in bytes) of the section of the symbol table devoted to      this file's symbols (actually, the section bracketed may contain      more than just this file's symbols).  If ldsymlen is 0, the only      reason for this thing's existence is the dependency list.      Nothing else will happen when it is read in.  */
name|int
name|ldsymlen
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LDSYMOFF
parameter_list|(
name|p
parameter_list|)
value|(((struct symloc *)((p)->read_symtab_private))->ldsymoff)
end_define

begin_define
define|#
directive|define
name|LDSYMLEN
parameter_list|(
name|p
parameter_list|)
value|(((struct symloc *)((p)->read_symtab_private))->ldsymlen)
end_define

begin_define
define|#
directive|define
name|SYMLOC
parameter_list|(
name|p
parameter_list|)
value|((struct symloc *)((p)->read_symtab_private))
end_define

begin_escape
end_escape

begin_comment
comment|/* FIXME: Shouldn't this stuff be in a .h file somewhere?  */
end_comment

begin_comment
comment|/* Nonzero means give verbose info on gdb action.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|info_verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Complaints about the symbols we have encountered.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|complaint
name|string_table_offset_complaint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|complaint
name|lbrac_unmatched_complaint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|complaint
name|lbrac_mismatch_complaint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|sltentry
modifier|*
name|hpread_get_slt
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|dnttentry
modifier|*
name|hpread_get_lntt
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hpread_has_name
name|PARAMS
argument_list|(
operator|(
expr|enum
name|dntt_entry_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of hpread.h */
end_comment

end_unit

