begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Include file cached obstack implementation.    Written by Fred Fish (fnf@cygnus.com)    Copyright 1995 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|BCACHE_H
value|1
end_define

begin_define
define|#
directive|define
name|BCACHE_HASHLENGTH
value|12
end_define

begin_comment
comment|/* Number of bits in hash value */
end_comment

begin_define
define|#
directive|define
name|BCACHE_HASHSIZE
value|(1<< BCACHE_HASHLENGTH)
end_define

begin_define
define|#
directive|define
name|BCACHE_MAXLENGTH
value|128
end_define

begin_comment
comment|/* Note that the user data is stored in data[].  Since it can be any type,    it needs to have the same alignment  as the most strict alignment of     any type on the host machine.  So do it the same way obstack does. */
end_comment

begin_struct
struct|struct
name|hashlink
block|{
name|struct
name|hashlink
modifier|*
name|next
decl_stmt|;
union|union
block|{
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
name|double
name|dummy
decl_stmt|;
block|}
name|d
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* BCACHE_DATA is used to get the address of the cached data. */
end_comment

begin_define
define|#
directive|define
name|BCACHE_DATA
parameter_list|(
name|p
parameter_list|)
value|((p)->d.data)
end_define

begin_comment
comment|/* BCACHE_DATA_ALIGNMENT is used to get the offset of the start of    cached data within the hashlink struct.  This value, plus the    size of the cached data, is the amount of space to allocate for    a hashlink struct to hold the next pointer and the data. */
end_comment

begin_define
define|#
directive|define
name|BCACHE_DATA_ALIGNMENT
define|\
value|(((char *) BCACHE_DATA((struct hashlink*) 0) - (char *) 0))
end_define

begin_struct
struct|struct
name|bcache
block|{
name|struct
name|obstack
name|cache
decl_stmt|;
name|struct
name|hashlink
modifier|*
modifier|*
name|indextable
index|[
name|BCACHE_MAXLENGTH
index|]
decl_stmt|;
name|int
name|cache_hits
decl_stmt|;
name|int
name|cache_misses
decl_stmt|;
name|int
name|cache_bytes
decl_stmt|;
name|int
name|cache_savings
decl_stmt|;
name|int
name|bcache_overflows
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|bcache
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
name|bytes
operator|,
name|int
name|count
operator|,
expr|struct
name|bcache
operator|*
name|bcachep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|MAINTENANCE_CMDS
end_if

begin_decl_stmt
specifier|extern
name|void
name|print_bcache_statistics
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bcache
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
comment|/* MAINTENANCE_CMDS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BCACHE_H */
end_comment

end_unit

