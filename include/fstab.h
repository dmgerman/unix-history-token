begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fstab.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FSTAB_H_
end_ifndef

begin_define
define|#
directive|define
name|_FSTAB_H_
end_define

begin_comment
comment|/*  * File system table, see fstab(5).  *  * Used by dump, mount, umount, swapon, fsck, df, ...  *  * For ufs fs_spec field is the block special name.  Programs that want to  * use the character special name must create that name by prepending a 'r'  * after the right most slash.  Quota files are always named "quotas", so  * if type is "rq", then use concatenation of fs_file and "quotas" to locate  * quota file.  */
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
name|fs_vfstype
decl_stmt|;
comment|/* File system type, ufs, nfs */
name|char
modifier|*
name|fs_mntops
decl_stmt|;
comment|/* Mount options ala -o */
name|char
modifier|*
name|fs_type
decl_stmt|;
comment|/* FSTAB_* from fs_mntops */
name|int
name|fs_freq
decl_stmt|;
comment|/* dump frequency, in days */
name|int
name|fs_passno
decl_stmt|;
comment|/* pass number on parallel fsck */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|struct
name|fstab
modifier|*
name|getfsent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fstab
modifier|*
name|getfsspec
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fstab
modifier|*
name|getfsfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setfsent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endfsent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FSTAB_H_ */
end_comment

end_unit

