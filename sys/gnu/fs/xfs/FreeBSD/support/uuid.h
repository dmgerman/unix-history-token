begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_UUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPPORT_UUID_H__
end_define

begin_function_decl
name|void
name|uuid_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uuid_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uuid_create_nil
parameter_list|(
name|uuid_t
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uuid_is_nil
parameter_list|(
name|uuid_t
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uuid_equal
parameter_list|(
name|uuid_t
modifier|*
name|uuid1
parameter_list|,
name|uuid_t
modifier|*
name|uuid2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uuid_getnodeuniq
parameter_list|(
name|uuid_t
modifier|*
name|uuid
parameter_list|,
name|int
name|fsid
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__uint64_t
name|uuid_hash64
parameter_list|(
name|uuid_t
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uuid_table_insert
parameter_list|(
name|uuid_t
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uuid_table_remove
parameter_list|(
name|uuid_t
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_UUID_H__ */
end_comment

end_unit

