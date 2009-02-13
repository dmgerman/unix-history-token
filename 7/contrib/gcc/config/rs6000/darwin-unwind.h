begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* DWARF2 EH unwinding support for Darwin.    Copyright (C) 2004 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     In addition to the permissions in the GNU General Public License, the    Free Software Foundation gives you unlimited permission to link the    compiled version of this file into combinations with other programs,    and to distribute those combinations without any restriction coming    from the use of this file.  (The General Public License restrictions    do apply in other respects; for example, they cover modification of    the file, and distribution when not linked into a combined    executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|_Unwind_fallback_frame_state_for
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|_Unwind_FrameState
modifier|*
name|fs
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MD_FALLBACK_FRAME_STATE_FOR
parameter_list|(
name|CONTEXT
parameter_list|,
name|FS
parameter_list|)
define|\
value|(_Unwind_fallback_frame_state_for (CONTEXT, FS)	\    ? _URC_NO_REASON : _URC_END_OF_STACK)
end_define

end_unit

