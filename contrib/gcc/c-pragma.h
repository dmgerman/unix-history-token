begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Pragma related interfaces.    Copyright (C) 1995, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HANDLE_SYSV_PRAGMA
end_ifdef

begin_comment
comment|/* Support #pragma weak iff ASM_WEAKEN_LABEL and ASM_OUTPUT_WEAK_ALIAS are    defined.  */
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
name|ASM_OUTPUT_WEAK_ALIAS
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HANDLE_PRAGMA_PACK_PUSH_POP */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_pragma
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Duplicate prototypes for the register_pragma stuff and the typedef for    cpp_reader, to avoid dragging cpplib.h in almost everywhere...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CPPLIB_H
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|cpp_reader
name|cpp_reader
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|cpp_register_pragma
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|void
argument_list|(
argument|*
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|cpp_reader
operator|*
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_C_PRAGMA_H */
end_comment

end_unit

