begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Pragma related interfaces.    Copyright (C) 1995, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_include
include|#
directive|include
file|<cpplib.h>
end_include

begin_comment
comment|/* For enum cpp_ttype.  */
end_comment

begin_comment
comment|/* Pragma identifiers built in to the front end parsers.  Identifiers    for ancillary handlers will follow these.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|pragma_kind
block|{
name|PRAGMA_NONE
init|=
literal|0
block|,
name|PRAGMA_OMP_ATOMIC
block|,
name|PRAGMA_OMP_BARRIER
block|,
name|PRAGMA_OMP_CRITICAL
block|,
name|PRAGMA_OMP_FLUSH
block|,
name|PRAGMA_OMP_FOR
block|,
name|PRAGMA_OMP_MASTER
block|,
name|PRAGMA_OMP_ORDERED
block|,
name|PRAGMA_OMP_PARALLEL
block|,
name|PRAGMA_OMP_PARALLEL_FOR
block|,
name|PRAGMA_OMP_PARALLEL_SECTIONS
block|,
name|PRAGMA_OMP_SECTION
block|,
name|PRAGMA_OMP_SECTIONS
block|,
name|PRAGMA_OMP_SINGLE
block|,
name|PRAGMA_OMP_THREADPRIVATE
block|,
name|PRAGMA_GCC_PCH_PREPROCESS
block|,
name|PRAGMA_FIRST_EXTERNAL
block|}
name|pragma_kind
typedef|;
end_typedef

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

begin_comment
comment|/* It's safe to always leave visibility pragma enabled as if    visibility is not supported on the host OS platform the    statements are ignored.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_VISIBILITY
value|1
end_define

begin_function_decl
specifier|extern
name|void
name|push_visibility
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_visibility
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* Front-end wrappers for pragma registration.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|pragma_handler
function_decl|)
parameter_list|(
name|struct
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_typedef

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
name|pragma_handler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_register_pragma_with_expansion
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|pragma_handler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_invoke_pragma_handler
parameter_list|(
name|unsigned
name|int
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
name|void
name|maybe_apply_pending_pragma_weaks
parameter_list|(
name|void
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
name|enum
name|cpp_ttype
name|pragma_lex
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is not actually available to pragma parsers.  It's merely a    convenient location to declare this function for c-lex, after    having enum cpp_ttype declared.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|cpp_ttype
name|c_lex_with_flags
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|location_t
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If 1, then lex strings into the execution character set.    If 0, lex strings into the host character set.    If -1, lex both, and chain them together, such that the former    is the TREE_CHAIN of the latter.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|c_lex_string_translate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If true, strings should be passed to the caller of c_lex completely    unmolested (no concatenation, no translation).  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|c_lex_return_raw_strings
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_C_PRAGMA_H */
end_comment

end_unit

