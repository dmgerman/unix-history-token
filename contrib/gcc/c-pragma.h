begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Pragma related interfaces.    Copyright (C) 1995, 1998, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_C_PRAGMA_H
end_ifndef

begin_define
define|#
directive|define
name|_C_PRAGMA_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HANDLE_SYSV_PRAGMA
end_ifdef

begin_comment
comment|/* Support #pragma weak iff ASM_WEAKEN_LABEL and ASM_OUTPUT_DEF are    defined.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ASM_WEAKEN_LABEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|ASM_OUTPUT_DEF
argument_list|)
end_if

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_WEAK
value|SUPPORTS_WEAK
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|PRAGMA_INSERT_ATTRIBUTES
parameter_list|(
name|node
parameter_list|,
name|pattr
parameter_list|,
name|prefix_attr
parameter_list|)
define|\
value|insert_pack_attributes (node, pattr, prefix_attr)
end_define

begin_decl_stmt
specifier|extern
name|void
name|insert_pack_attributes
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|*
operator|,
name|tree
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
comment|/* HANDLE_PRAGMA_PACK_PUSH_POP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HANDLE_PRAGMA_WEAK
end_ifdef

begin_comment
comment|/* This structure contains any weak symbol declarations waiting to be emitted.  */
end_comment

begin_struct
struct|struct
name|weak_syms
block|{
name|struct
name|weak_syms
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Declared in varasm.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|weak_syms
modifier|*
name|weak_decls
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|add_weak
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
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
comment|/* HANDLE_PRAGMA_WEAK */
end_comment

begin_if
if|#
directive|if
name|defined
name|HANDLE_PRAGMA_PACK
operator|||
name|defined
name|HANDLE_PRAGMA_WEAK
end_if

begin_comment
comment|/* Define HANDLE_GENERIC_PRAGMAS if any kind of front-end pragma    parsing is to be done.  The code in GCC's generic C source files    will only look for the definition of this constant.  They will    ignore definitions of HANDLE_PRAGMA_PACK and so on.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_GENERIC_PRAGMAS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HANDLE_GENERIC_PRAGMAS
end_ifdef

begin_enum
enum|enum
name|pragma_state
block|{
name|ps_start
block|,
name|ps_done
block|,
ifdef|#
directive|ifdef
name|HANDLE_PRAGMA_WEAK
name|ps_weak
block|,
name|ps_name
block|,
name|ps_equals
block|,
name|ps_value
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HANDLE_PRAGMA_PACK
name|ps_pack
block|,
name|ps_left
block|,
name|ps_align
block|,
name|ps_right
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HANDLE_PRAGMA_PACK_PUSH_POP
name|ps_push
block|,
name|ps_pushcomma
block|,
name|ps_pushid
block|,
name|ps_pushcomma2
block|,
name|ps_pop
block|,
name|ps_popcomma
block|,
endif|#
directive|endif
name|ps_bad
block|}
enum|;
end_enum

begin_comment
comment|/* Handle a C style pragma */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|handle_pragma_token
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HANDLE_GENERIC_PRAGMAS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _C_PRAGMA_H */
end_comment

end_unit

