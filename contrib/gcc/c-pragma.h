begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Pragma related interfaces.    Copyright (C) 1995 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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

begin_enum
enum|enum
name|pragma_state
block|{
name|ps_start
block|,
name|ps_done
block|,
name|ps_bad
block|,
name|ps_weak
block|,
name|ps_name
block|,
name|ps_equals
block|,
name|ps_value
block|,
name|ps_pack
block|,
name|ps_left
block|,
name|ps_align
block|,
name|ps_right
block|}
enum|;
end_enum

begin_comment
comment|/* Output asm to handle ``#pragma weak'' */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|handle_pragma_weak
name|PROTO
argument_list|(
operator|(
expr|enum
name|pragma_state
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Handle a C style pragma */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|handle_pragma_token
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

