begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Pragma related interfaces.    Copyright (C) 1995, 1998, 1999, 2000, 2001, 2002, 2003, 2004    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_C_PRAGMA_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_C_PRAGMA_H
end_define

begin_comment
comment|/* Cause the `yydebug' variable to be defined.  */
end_comment

begin_define
define|#
directive|define
name|YYDEBUG
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|yydebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cpp_reader
modifier|*
name|parse_in
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_WEAK
value|SUPPORTS_WEAK
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HANDLE_SYSV_PRAGMA
end_ifdef

begin_comment
comment|/* We always support #pragma pack for SYSV pragmas.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HANDLE_PRAGMA_PACK
end_ifndef

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HANDLE_SYSV_PRAGMA */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HANDLE_PRAGMA_PACK_PUSH_POP
end_ifdef

begin_comment
comment|/* If we are supporting #pragma pack(push... then we automatically    support #pragma pack(<n>)  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HANDLE_PRAGMA_PACK_PUSH_POP */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_pragma
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Front-end wrapper for pragma registration to avoid dragging    cpplib.h in almost everywhere.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_register_pragma
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|cpp_reader
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|maybe_apply_pragma_weak
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|maybe_apply_renaming_pragma
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_to_renaming_pragma_list
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_lex
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_lex_with_flags
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_C_PRAGMA_H */
end_comment

end_unit

