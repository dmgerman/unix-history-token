begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hash.h - for hash.c    Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_struct_decl
struct_decl|struct
name|hash_control
struct_decl|;
end_struct_decl

begin_comment
comment|/* returns control block */
end_comment

begin_decl_stmt
name|struct
name|hash_control
modifier|*
name|hash_new
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hash_die
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* returns previous value */
end_comment

begin_decl_stmt
name|PTR
name|hash_delete
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|,
specifier|const
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* returns previous value */
end_comment

begin_decl_stmt
name|PTR
name|hash_replace
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|,
specifier|const
name|char
operator|*
name|str
operator|,
name|PTR
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* returns error string or null */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|hash_insert
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|,
specifier|const
name|char
operator|*
name|str
operator|,
name|PTR
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* returns value */
end_comment

begin_decl_stmt
name|PTR
name|hash_find
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|,
specifier|const
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* returns error text or null (internal) */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|hash_jam
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_control
operator|*
operator|,
specifier|const
name|char
operator|*
name|str
operator|,
name|PTR
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hash_print_statistics
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
expr|struct
name|hash_control
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifdef hashH */
end_comment

begin_comment
comment|/* end of hash.c */
end_comment

end_unit

