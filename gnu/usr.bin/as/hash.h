begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hash.h - for hash.c    Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|hashH
end_ifndef

begin_define
define|#
directive|define
name|hashH
end_define

begin_struct
struct|struct
name|hash_entry
block|{
name|char
modifier|*
name|hash_string
decl_stmt|;
comment|/* points to where the symbol string is */
comment|/* NULL means slot is not used */
comment|/* DELETED means slot was deleted */
name|char
modifier|*
name|hash_value
decl_stmt|;
comment|/* user's datum, associated with symbol */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HASH_STATLENGTH
value|(6)
end_define

begin_struct
struct|struct
name|hash_control
block|{
name|struct
name|hash_entry
modifier|*
name|hash_where
decl_stmt|;
comment|/* address of hash table */
name|int
name|hash_sizelog
decl_stmt|;
comment|/* Log of ( hash_mask + 1 ) */
name|int
name|hash_mask
decl_stmt|;
comment|/* masks a hash into index into table */
name|int
name|hash_full
decl_stmt|;
comment|/* when hash_stat[STAT_USED] exceeds this, */
comment|/* grow table */
name|struct
name|hash_entry
modifier|*
name|hash_wall
decl_stmt|;
comment|/* point just after last (usable) entry */
comment|/* here we have some statistics */
name|int
name|hash_stat
index|[
name|HASH_STATLENGTH
index|]
decl_stmt|;
comment|/* lies& statistics */
comment|/* we need STAT_USED& STAT_SIZE */
block|}
struct|;
end_struct

begin_comment
comment|/* fixme: prototype. */
end_comment

begin_comment
comment|/* returns */
end_comment

begin_function_decl
name|struct
name|hash_control
modifier|*
name|hash_new
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* [control block] */
end_comment

begin_function_decl
name|void
name|hash_die
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hash_say
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|hash_delete
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* previous value */
end_comment

begin_function_decl
name|char
modifier|*
name|hash_relpace
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* previous value */
end_comment

begin_function_decl
name|char
modifier|*
name|hash_insert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* error string */
end_comment

begin_function_decl
name|char
modifier|*
name|hash_apply
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 0 means OK */
end_comment

begin_function_decl
name|char
modifier|*
name|hash_find
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* value */
end_comment

begin_function_decl
name|char
modifier|*
name|hash_jam
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* error text (internal) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifdef hashH */
end_comment

begin_comment
comment|/* end of hash.h */
end_comment

end_unit

