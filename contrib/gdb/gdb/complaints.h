begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for complaint handling during symbol reading in GDB.    Copyright (C) 1990, 1991, 1992  Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|COMPLAINTS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|COMPLAINTS_H
end_define

begin_comment
comment|/* Support for complaining about things in the symbol file that aren't    catastrophic.     Each such thing gets a counter.  The first time we have the problem,    during a symbol read, we report it.  At the end of symbol reading,    if verbose, we report how many of each problem we had.  */
end_comment

begin_struct
struct|struct
name|complaint
block|{
name|char
modifier|*
name|message
decl_stmt|;
name|unsigned
name|counter
decl_stmt|;
name|struct
name|complaint
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Root of the chain of complaints that have at some point been issued.     This is used to reset the counters, and/or report the total counts.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|complaint
name|complaint_root
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions that handle complaints.  (in complaints.c)  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|complain
name|PARAMS
argument_list|(
operator|(
expr|struct
name|complaint
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_complaints
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (COMPLAINTS_H) */
end_comment

end_unit

