begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)fstab.h	5.6 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * File system table, see fstab(5).  *  * Used by dump, mount, umount, swapon, fsck, df, ...  *  * The fs_spec field is the block special name.  Programs that want to use  * the character special name must create that name by prepending a 'r'  * after the right most slash.  Quota files are always named "quotas", so  * if type is "rq", then use concatenation of fs_file and "quotas" to locate  * quota file.  */
end_comment

begin_define
define|#
directive|define
name|_PATH_FSTAB
value|"/etc/fstab"
end_define

begin_define
define|#
directive|define
name|FSTAB
value|"/etc/fstab"
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|FSTAB_RW
value|"rw"
end_define

begin_comment
comment|/* read/write device */
end_comment

begin_define
define|#
directive|define
name|FSTAB_RQ
value|"rq"
end_define

begin_comment
comment|/* read/write with quotas */
end_comment

begin_define
define|#
directive|define
name|FSTAB_RO
value|"ro"
end_define

begin_comment
comment|/* read-only device */
end_comment

begin_define
define|#
directive|define
name|FSTAB_SW
value|"sw"
end_define

begin_comment
comment|/* swap device */
end_comment

begin_define
define|#
directive|define
name|FSTAB_XX
value|"xx"
end_define

begin_comment
comment|/* ignore totally */
end_comment

begin_struct
struct|struct
name|fstab
block|{
name|char
modifier|*
name|fs_spec
decl_stmt|;
comment|/* block special device name */
name|char
modifier|*
name|fs_file
decl_stmt|;
comment|/* file system path prefix */
name|char
modifier|*
name|fs_type
decl_stmt|;
comment|/* FSTAB_* */
name|int
name|fs_freq
decl_stmt|;
comment|/* dump frequency, in days */
name|int
name|fs_passno
decl_stmt|;
comment|/* pass number on parallel dump */
name|char
modifier|*
name|fs_vfstype
decl_stmt|;
comment|/* File system type, ufs, nfs */
name|char
modifier|*
name|fs_mntops
decl_stmt|;
comment|/* Mount options ala -o */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|fstab
modifier|*
name|getfsent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fstab
modifier|*
name|getfsspec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fstab
modifier|*
name|getfsfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setfsent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endfsent
parameter_list|()
function_decl|;
end_function_decl

end_unit

