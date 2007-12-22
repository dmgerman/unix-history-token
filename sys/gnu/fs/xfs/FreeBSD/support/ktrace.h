begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_KTRACE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPPORT_KTRACE_H__
end_define

begin_include
include|#
directive|include
file|<support/spin.h>
end_include

begin_comment
comment|/*  * Trace buffer entry structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ktrace_entry
block|{
name|void
modifier|*
name|val
index|[
literal|16
index|]
decl_stmt|;
block|}
name|ktrace_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Trace buffer header structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ktrace
block|{
name|lock_t
name|kt_lock
decl_stmt|;
comment|/* mutex to guard counters */
name|int
name|kt_nentries
decl_stmt|;
comment|/* number of entries in trace buf */
name|int
name|kt_index
decl_stmt|;
comment|/* current index in entries */
name|int
name|kt_rollover
decl_stmt|;
name|ktrace_entry_t
modifier|*
name|kt_entries
decl_stmt|;
comment|/* buffer of entries */
block|}
name|ktrace_t
typedef|;
end_typedef

begin_comment
comment|/*  * Trace buffer snapshot structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ktrace_snap
block|{
name|int
name|ks_start
decl_stmt|;
comment|/* kt_index at time of snap */
name|int
name|ks_index
decl_stmt|;
comment|/* current index */
block|}
name|ktrace_snap_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XFS_TRACE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|ktrace_init
parameter_list|(
name|int
name|zentries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ktrace_uninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ktrace_t
modifier|*
name|ktrace_alloc
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ktrace_free
parameter_list|(
name|ktrace_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ktrace_enter
parameter_list|(
name|ktrace_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ktrace_entry_t
modifier|*
name|ktrace_first
parameter_list|(
name|ktrace_t
modifier|*
parameter_list|,
name|ktrace_snap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ktrace_nentries
parameter_list|(
name|ktrace_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ktrace_entry_t
modifier|*
name|ktrace_next
parameter_list|(
name|ktrace_t
modifier|*
parameter_list|,
name|ktrace_snap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ktrace_entry_t
modifier|*
name|ktrace_skip
parameter_list|(
name|ktrace_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|ktrace_snap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ktrace_init
parameter_list|(
name|x
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|ktrace_uninit
parameter_list|()
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_XFS_TRACE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_KTRACE_H__ */
end_comment

end_unit

