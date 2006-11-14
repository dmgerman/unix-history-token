begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* defer.h    Copyright (C) 1993, 2001, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation, Inc.,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_struct
struct|struct
name|deferment
block|{
name|struct
name|deferment
modifier|*
name|next
decl_stmt|;
name|struct
name|new_cpio_header
name|header
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|deferment
modifier|*
name|create_deferment
name|P_
argument_list|(
operator|(
expr|struct
name|new_cpio_header
operator|*
name|file_hdr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_deferment
name|P_
argument_list|(
operator|(
expr|struct
name|deferment
operator|*
name|d
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

