begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)mount.h	5.1 (Berkeley) 7/19/90  */
end_comment

begin_define
define|#
directive|define
name|MNTPATHLEN
value|1024
end_define

begin_define
define|#
directive|define
name|MNTNAMLEN
value|255
end_define

begin_define
define|#
directive|define
name|FHSIZE
value|32
end_define

begin_typedef
typedef|typedef
name|char
name|fhandle
index|[
name|FHSIZE
index|]
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_fhandle
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|fhstatus
block|{
name|u_int
name|fhs_status
decl_stmt|;
union|union
block|{
name|fhandle
name|fhs_fhandle
decl_stmt|;
block|}
name|fhstatus_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fhstatus
name|fhstatus
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_fhstatus
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|char
modifier|*
name|dirpath
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_dirpath
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|char
modifier|*
name|name
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_name
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|struct
name|mountbody
modifier|*
name|mountlist
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_mountlist
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|mountbody
block|{
name|name
name|ml_hostname
decl_stmt|;
name|dirpath
name|ml_directory
decl_stmt|;
name|mountlist
name|ml_next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mountbody
name|mountbody
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_mountbody
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|struct
name|groupnode
modifier|*
name|groups
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_groups
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|groupnode
block|{
name|name
name|gr_name
decl_stmt|;
name|groups
name|gr_next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|groupnode
name|groupnode
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_groupnode
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|struct
name|exportnode
modifier|*
name|exports
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_exports
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|exportnode
block|{
name|dirpath
name|ex_dir
decl_stmt|;
name|groups
name|ex_groups
decl_stmt|;
name|exports
name|ex_next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|exportnode
name|exportnode
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_exportnode
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MOUNTPROG
value|((u_long)100005)
end_define

begin_define
define|#
directive|define
name|MOUNTVERS
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|MOUNTPROC_NULL
value|((u_long)0)
end_define

begin_function_decl
specifier|extern
name|voidp
name|mountproc_null_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MOUNTPROC_MNT
value|((u_long)1)
end_define

begin_function_decl
specifier|extern
name|fhstatus
modifier|*
name|mountproc_mnt_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MOUNTPROC_DUMP
value|((u_long)2)
end_define

begin_function_decl
specifier|extern
name|mountlist
modifier|*
name|mountproc_dump_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MOUNTPROC_UMNT
value|((u_long)3)
end_define

begin_function_decl
specifier|extern
name|voidp
name|mountproc_umnt_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MOUNTPROC_UMNTALL
value|((u_long)4)
end_define

begin_function_decl
specifier|extern
name|voidp
name|mountproc_umntall_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MOUNTPROC_EXPORT
value|((u_long)5)
end_define

begin_function_decl
specifier|extern
name|exports
modifier|*
name|mountproc_export_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MOUNTPROC_EXPORTALL
value|((u_long)6)
end_define

begin_function_decl
specifier|extern
name|exports
modifier|*
name|mountproc_exportall_1
parameter_list|()
function_decl|;
end_function_decl

end_unit

