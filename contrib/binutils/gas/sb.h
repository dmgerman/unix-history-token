begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sb.h - header file for string buffer manipulation routines    Copyright 1994, 1995, 2000 Free Software Foundation, Inc.     Written by Steve and Judy Chamberlain of Cygnus Support,       sac@cygnus.com     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SB_H
end_ifndef

begin_define
define|#
directive|define
name|SB_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* string blocks     I had a couple of choices when deciding upon this data structure.    gas uses null terminated strings for all its internal work.  This    often means that parts of the program that want to examine    substrings have to manipulate the data in the string to do the    right thing (a common operation is to single out a bit of text by    saving away the character after it, nulling it out, operating on    the substring and then replacing the character which was under the    null).  This is a pain and I remember a load of problems that I had with    code in gas which almost got this right.  Also, it's harder to grow and    allocate null terminated strings efficiently.     Obstacks provide all the functionality needed, but are too    complicated, hence the sb.     An sb is allocated by the caller, and is initialized to point to an    sb_element.  sb_elements are kept on a free lists, and used when    needed, replaced onto the free list when unused.  */
end_comment

begin_define
define|#
directive|define
name|sb_max_power_two
value|30
end_define

begin_comment
comment|/* don't allow strings more than 			           2^sb_max_power_two long */
end_comment

begin_comment
comment|/* structure of an sb */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sb
block|{
name|char
modifier|*
name|ptr
decl_stmt|;
comment|/* points to the current block.  */
name|int
name|len
decl_stmt|;
comment|/* how much is used.  */
name|int
name|pot
decl_stmt|;
comment|/* the maximum length is 1<<pot */
name|struct
name|le
modifier|*
name|item
decl_stmt|;
block|}
name|sb
typedef|;
end_typedef

begin_comment
comment|/* Structure of the free list object of an sb */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|le
block|{
name|struct
name|le
modifier|*
name|next
decl_stmt|;
name|int
name|size
decl_stmt|;
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|sb_element
typedef|;
end_typedef

begin_comment
comment|/* The free list */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|sb_element
modifier|*
name|size
index|[
name|sb_max_power_two
index|]
decl_stmt|;
block|}
name|sb_list_vector
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|string_count
index|[
name|sb_max_power_two
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|sb_build
parameter_list|(
name|sb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sb_new
parameter_list|(
name|sb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sb_kill
parameter_list|(
name|sb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sb_add_sb
parameter_list|(
name|sb
modifier|*
parameter_list|,
name|sb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sb_reset
parameter_list|(
name|sb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sb_add_char
parameter_list|(
name|sb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sb_add_string
parameter_list|(
name|sb
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sb_add_buffer
parameter_list|(
name|sb
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sb_print
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|sb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sb_print_at
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|,
name|sb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|sb_name
parameter_list|(
name|sb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|sb_terminate
parameter_list|(
name|sb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sb_skip_white
parameter_list|(
name|int
parameter_list|,
name|sb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sb_skip_comma
parameter_list|(
name|int
parameter_list|,
name|sb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Actually in input-scrub.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|input_scrub_include_sb
parameter_list|(
name|sb
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SB_H */
end_comment

end_unit

