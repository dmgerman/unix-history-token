begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Code dealing with register stack frames, for GDB, the GNU debugger.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SENTINEL_FRAME_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|SENTINEL_FRAME_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|frame_unwind
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regcache
struct_decl|;
end_struct_decl

begin_comment
comment|/* Implement the sentinel frame.  The sentinel frame terminates the    inner most end of the frame chain.  If unwound, it returns the    information need to construct an inner-most frame.  */
end_comment

begin_comment
comment|/* Pump prime the sentinel frame's cache.  Since this needs the    REGCACHE provide that here.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|sentinel_frame_cache
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* At present there is only one type of sentinel frame.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|frame_unwind
modifier|*
specifier|const
name|sentinel_frame_unwind
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (SENTINEL_FRAME_H)  */
end_comment

end_unit

