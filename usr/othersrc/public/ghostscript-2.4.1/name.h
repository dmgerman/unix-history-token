begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* name.h */
end_comment

begin_comment
comment|/* Name table entry structure for Ghostscript */
end_comment

begin_comment
comment|/* Name structure.  The name table is a simple chained hash table. */
end_comment

begin_comment
comment|/* There is an optimization to avoid lookup for operator and other */
end_comment

begin_comment
comment|/* global names. */
end_comment

begin_struct
struct|struct
name|name_s
block|{
name|ushort
name|next_index
decl_stmt|;
comment|/* next name in chain or 0 */
name|ushort
name|index
decl_stmt|;
comment|/* In order to pack names into 16 bytes, we use a non-standard */
comment|/* representation for the string, omitting the type_attrs field. */
name|ushort
name|string_size
decl_stmt|;
specifier|const
name|byte
modifier|*
name|string_bytes
decl_stmt|;
comment|/* pvalue specifies the definition status of the name: */
comment|/*	pvalue == pv_no_defn: no definitions */
define|#
directive|define
name|pv_no_defn
value|((ref *)0)
comment|/*	pvalue == pv_other: other status */
define|#
directive|define
name|pv_other
value|((ref *)1)
define|#
directive|define
name|pv_valid
parameter_list|(
name|pvalue
parameter_list|)
value|((unsigned long)(pvalue)> 1)
comment|/*	pvalue != pv_no_defn, pvalue != pv_other: pvalue is valid */
name|ref
modifier|*
name|pvalue
decl_stmt|;
comment|/* if only defined in systemdict */
comment|/* or userdict, this points to */
comment|/* the value */
block|}
struct|;
end_struct

begin_comment
comment|/*typedef struct name_s name;*/
end_comment

begin_comment
comment|/* in ghost.h */
end_comment

begin_comment
comment|/* Procedures for the name table. */
end_comment

begin_comment
comment|/* The size argument for name_ref should be a ushort, */
end_comment

begin_comment
comment|/* but this gets the Apollo compiler confused. */
end_comment

begin_comment
comment|/* enterflag=-1 means don't enter (return an error if missing); */
end_comment

begin_comment
comment|/* enterflag=0 means enter if missing, don't copy the string; */
end_comment

begin_comment
comment|/* enterflag=1 means enter if missing, copy the string. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|name_ref
argument_list|(
name|P4
argument_list|(
argument|const byte *ptr
argument_list|,
argument|uint size
argument_list|,
argument|ref *pnref
argument_list|,
argument|int enterflag
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|name_string_ref
argument_list|(
name|P2
argument_list|(
specifier|const
name|ref
operator|*
name|pnref
argument_list|,
name|ref
operator|*
name|psref
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|name_enter
argument_list|(
name|P2
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|,
name|ref
operator|*
name|pnref
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name_from_string essentially implements cvn. */
end_comment

begin_comment
comment|/* It always enters the name, and copies the executable attribute. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|name_from_string
argument_list|(
name|P2
argument_list|(
specifier|const
name|ref
operator|*
name|psref
argument_list|,
name|ref
operator|*
name|pnref
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Conversion between names and indices. */
end_comment

begin_define
define|#
directive|define
name|name_index
parameter_list|(
name|pnref
parameter_list|)
value|((pnref)->value.pname->index)
end_define

begin_decl_stmt
specifier|extern
name|void
name|name_index_ref
argument_list|(
name|P2
argument_list|(
argument|uint index
comment|/* should be ushort */
argument_list|,
argument|ref *pnref
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint
name|name_count
argument_list|(
name|P0
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|name_is_since_count
argument_list|(
name|P2
argument_list|(
name|ref
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clean up the name table before a restore. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|name_restore
argument_list|(
name|P1
argument_list|(
argument|uint old_count
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

