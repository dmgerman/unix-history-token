begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gsutil.h */
end_comment

begin_comment
comment|/* Prototypes for procedures in gsutil.c */
end_comment

begin_comment
comment|/* ------ String utilities ------ */
end_comment

begin_comment
comment|/* Compare two strings, returning -1 if the first is less, */
end_comment

begin_comment
comment|/* 0 if they are equal, and 1 if first is greater. */
end_comment

begin_comment
comment|/* We can't use memcmp, because we always use unsigned characters. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bytes_compare
argument_list|(
name|P4
argument_list|(
specifier|const
name|byte
operator|*
argument_list|,
name|uint
argument_list|,
specifier|const
name|byte
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Test whether a string matches a pattern with wildcards. */
end_comment

begin_comment
comment|/* '*' = any substring, '?' = any character, '\' quotes next character. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|string_match
argument_list|(
name|P5
argument_list|(
argument|const byte *str
argument_list|,
argument|uint len
argument_list|,
argument|const byte *pstr
argument_list|,
argument|uint plen
argument_list|,
argument|int ignore_case
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compute a hash for a string */
end_comment

begin_decl_stmt
specifier|extern
name|uint
name|string_hash
argument_list|(
name|P2
argument_list|(
specifier|const
name|byte
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ Property list utilities ------ */
end_comment

begin_comment
comment|/*  * The recipient of a property list typically wants to extract a set of  * known properties and disregard the rest.  The following procedure  * accomplishes this.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gs_prop_item_s_DEFINED
end_ifndef

begin_struct_decl
struct_decl|struct
name|gs_prop_item_s
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|props_extract
argument_list|(
name|P6
argument_list|(
argument|struct gs_prop_item_s *plist
argument_list|,
comment|/* plist[count] */
argument|int count
argument_list|,
argument|const struct gs_prop_item_s *template
argument_list|,
comment|/* template[tcount] */
comment|/* (the known properties) */
argument|int tcount
argument_list|,
argument|struct gs_prop_item_s **pknown
argument_list|,
comment|/* *pknown[tcount] */
comment|/* (these are set to point to the */
comment|/* corresponding items in plist, */
comment|/* or NULL if the item is absent) */
argument|int finished
comment|/* if true, mark remaining items */
comment|/* in plist as pv_unknown */
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

