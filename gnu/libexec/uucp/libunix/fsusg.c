begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fsusage.c -- return space usage of mounted filesystems    Copyright (C) 1991, 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     This file was modified slightly by Ian Lance Taylor, December 1992,    for use with Taylor UUCP.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"fsusg.h"
end_include

begin_function_decl
name|int
name|statfs
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|STAT_STATFS2_BSIZE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_IBMR2
end_ifndef

begin_comment
comment|/* 4.3BSD, SunOS 4, HP-UX, AIX PS/2.  */
end_comment

begin_include
include|#
directive|include
file|<sys/vfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STAT_STATFS2_FSIZE
end_if

begin_comment
comment|/* 4.4BSD.  */
end_comment

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STAT_STATFS2_FS_DATA
end_if

begin_comment
comment|/* Ultrix.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STAT_USTAT
end_if

begin_comment
comment|/* SVR2 and others.  */
end_comment

begin_include
include|#
directive|include
file|<ustat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STAT_STATFS4
end_if

begin_comment
comment|/* SVR3, Dynix, Irix.  */
end_comment

begin_include
include|#
directive|include
file|<sys/statfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_IBMR2
end_ifdef

begin_comment
comment|/* AIX RS6000.  */
end_comment

begin_include
include|#
directive|include
file|<sys/statfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_I386
end_ifdef

begin_comment
comment|/* AIX PS/2.  */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/dustat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STAT_STATVFS
end_if

begin_comment
comment|/* SVR4.  */
end_comment

begin_include
include|#
directive|include
file|<sys/statvfs.h>
end_include

begin_function_decl
name|int
name|statvfs
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STAT_NONE
value|0
end_define

begin_if
if|#
directive|if
operator|!
name|STAT_STATVFS
end_if

begin_if
if|#
directive|if
operator|!
name|STAT_STATFS2_BSIZE
end_if

begin_if
if|#
directive|if
operator|!
name|STAT_STATFS2_FSIZE
end_if

begin_if
if|#
directive|if
operator|!
name|STAT_STATFS2_FS_DATA
end_if

begin_if
if|#
directive|if
operator|!
name|STAT_STATFS4
end_if

begin_if
if|#
directive|if
operator|!
name|STAT_USTAT
end_if

begin_undef
undef|#
directive|undef
name|STAT_NONE
end_undef

begin_define
define|#
directive|define
name|STAT_NONE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|STAT_NONE
end_if

begin_comment
comment|/* Return the number of TOSIZE-byte blocks used by    BLOCKS FROMSIZE-byte blocks, rounding up.  */
end_comment

begin_function
specifier|static
name|long
name|adjust_blocks
parameter_list|(
name|blocks
parameter_list|,
name|fromsize
parameter_list|,
name|tosize
parameter_list|)
name|long
name|blocks
decl_stmt|;
name|int
name|fromsize
decl_stmt|,
name|tosize
decl_stmt|;
block|{
if|if
condition|(
name|fromsize
operator|==
name|tosize
condition|)
comment|/* E.g., from 512 to 512.  */
return|return
name|blocks
return|;
elseif|else
if|if
condition|(
name|fromsize
operator|>
name|tosize
condition|)
comment|/* E.g., from 2048 to 512.  */
return|return
name|blocks
operator|*
operator|(
name|fromsize
operator|/
name|tosize
operator|)
return|;
else|else
comment|/* E.g., from 256 to 512.  */
return|return
operator|(
name|blocks
operator|+
literal|1
operator|)
operator|/
operator|(
name|tosize
operator|/
name|fromsize
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Fill in the fields of FSP with information about space usage for    the filesystem on which PATH resides.    DISK is the device on which PATH is mounted, for space-getting    methods that need to know it.    Return 0 if successful, -1 if not. */
end_comment

begin_function
name|int
name|get_fs_usage
parameter_list|(
name|path
parameter_list|,
name|disk
parameter_list|,
name|fsp
parameter_list|)
name|char
modifier|*
name|path
decl_stmt|,
decl|*
name|disk
decl_stmt|;
end_function

begin_decl_stmt
name|struct
name|fs_usage
modifier|*
name|fsp
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|#
directive|if
name|STAT_NONE
return|return
operator|-
literal|1
return|;
endif|#
directive|endif
if|#
directive|if
name|STAT_STATFS2_FS_DATA
comment|/* Ultrix.  */
name|struct
name|fs_data
name|fsd
decl_stmt|;
if|if
condition|(
name|statfs
argument_list|(
name|path
argument_list|,
operator|&
name|fsd
argument_list|)
operator|!=
literal|1
condition|)
return|return
operator|-
literal|1
return|;
define|#
directive|define
name|convert_blocks
parameter_list|(
name|b
parameter_list|)
value|adjust_blocks ((b), 1024, 512)
name|fsp
operator|->
name|fsu_blocks
operator|=
name|convert_blocks
argument_list|(
name|fsd
operator|.
name|fd_req
operator|.
name|btot
argument_list|)
expr_stmt|;
name|fsp
operator|->
name|fsu_bfree
operator|=
name|convert_blocks
argument_list|(
name|fsd
operator|.
name|fd_req
operator|.
name|bfree
argument_list|)
expr_stmt|;
name|fsp
operator|->
name|fsu_bavail
operator|=
name|convert_blocks
argument_list|(
name|fsd
operator|.
name|fd_req
operator|.
name|bfreen
argument_list|)
expr_stmt|;
name|fsp
operator|->
name|fsu_files
operator|=
name|fsd
operator|.
name|fd_req
operator|.
name|gtot
expr_stmt|;
name|fsp
operator|->
name|fsu_ffree
operator|=
name|fsd
operator|.
name|fd_req
operator|.
name|gfree
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|STAT_STATFS2_BSIZE
comment|/* 4.3BSD, SunOS 4, HP-UX, AIX.  */
name|struct
name|statfs
name|fsd
decl_stmt|;
if|if
condition|(
name|statfs
argument_list|(
name|path
argument_list|,
operator|&
name|fsd
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
define|#
directive|define
name|convert_blocks
parameter_list|(
name|b
parameter_list|)
value|adjust_blocks ((b), fsd.f_bsize, 512)
endif|#
directive|endif
if|#
directive|if
name|STAT_STATFS2_FSIZE
comment|/* 4.4BSD.  */
name|struct
name|statfs
name|fsd
decl_stmt|;
if|if
condition|(
name|statfs
argument_list|(
name|path
argument_list|,
operator|&
name|fsd
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
define|#
directive|define
name|convert_blocks
parameter_list|(
name|b
parameter_list|)
value|adjust_blocks ((b), fsd.f_fsize, 512)
endif|#
directive|endif
if|#
directive|if
name|STAT_STATFS4
comment|/* SVR3, Dynix, Irix.  */
name|struct
name|statfs
name|fsd
decl_stmt|;
if|if
condition|(
name|statfs
argument_list|(
name|path
argument_list|,
operator|&
name|fsd
argument_list|,
sizeof|sizeof
name|fsd
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/* Empirically, the block counts on most SVR3 and SVR3-derived      systems seem to always be in terms of 512-byte blocks,      no matter what value f_bsize has.  */
define|#
directive|define
name|convert_blocks
parameter_list|(
name|b
parameter_list|)
value|(b)
ifndef|#
directive|ifndef
name|_SEQUENT_
comment|/* _SEQUENT_ is DYNIX/ptx.  */
define|#
directive|define
name|f_bavail
value|f_bfree
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|STAT_STATVFS
comment|/* SVR4.  */
name|struct
name|statvfs
name|fsd
decl_stmt|;
if|if
condition|(
name|statvfs
argument_list|(
name|path
argument_list|,
operator|&
name|fsd
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/* f_frsize isn't guaranteed to be supported.  */
define|#
directive|define
name|convert_blocks
parameter_list|(
name|b
parameter_list|)
define|\
value|adjust_blocks ((b), fsd.f_frsize ? fsd.f_frsize : fsd.f_bsize, 512)
endif|#
directive|endif
if|#
directive|if
name|STAT_USTAT
block|{
name|struct
name|stat
name|sstat
decl_stmt|;
name|struct
name|ustat
name|s
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|path
argument_list|,
operator|&
name|sstat
argument_list|)
operator|<
literal|0
operator|||
name|ustat
argument_list|(
name|sstat
operator|.
name|st_dev
argument_list|,
operator|&
name|s
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|fsp
operator|->
name|fsu_blocks
operator|=
operator|-
literal|1
expr_stmt|;
name|fsp
operator|->
name|fsu_bfree
operator|=
name|f_tfree
expr_stmt|;
name|fsp
operator|->
name|fsu_bavail
operator|=
name|f_tfree
expr_stmt|;
name|fsp
operator|->
name|fsu_files
operator|=
operator|-
literal|1
expr_stmt|;
name|fsp
operator|->
name|fsu_ffree
operator|=
operator|-
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
if|#
directive|if
operator|!
name|STAT_STATFS2_FS_DATA
comment|/* ! Ultrix */
if|#
directive|if
operator|!
name|STAT_USTAT
if|#
directive|if
operator|!
name|STAT_NONE
name|fsp
operator|->
name|fsu_blocks
operator|=
name|convert_blocks
argument_list|(
name|fsd
operator|.
name|f_blocks
argument_list|)
expr_stmt|;
name|fsp
operator|->
name|fsu_bfree
operator|=
name|convert_blocks
argument_list|(
name|fsd
operator|.
name|f_bfree
argument_list|)
expr_stmt|;
name|fsp
operator|->
name|fsu_bavail
operator|=
name|convert_blocks
argument_list|(
name|fsd
operator|.
name|f_bavail
argument_list|)
expr_stmt|;
name|fsp
operator|->
name|fsu_files
operator|=
name|fsd
operator|.
name|f_files
expr_stmt|;
name|fsp
operator|->
name|fsu_ffree
operator|=
name|fsd
operator|.
name|f_ffree
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_I386
end_ifdef

begin_comment
comment|/* AIX PS/2 does not supply statfs.  */
end_comment

begin_function
name|int
name|statfs
parameter_list|(
name|path
parameter_list|,
name|fsb
parameter_list|)
name|char
modifier|*
name|path
decl_stmt|;
name|struct
name|statfs
modifier|*
name|fsb
decl_stmt|;
block|{
name|struct
name|stat
name|stats
decl_stmt|;
name|struct
name|dustat
name|fsd
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|path
argument_list|,
operator|&
name|stats
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|dustat
argument_list|(
name|stats
operator|.
name|st_dev
argument_list|,
literal|0
argument_list|,
operator|&
name|fsd
argument_list|,
sizeof|sizeof
argument_list|(
name|fsd
argument_list|)
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
name|fsb
operator|->
name|f_type
operator|=
literal|0
expr_stmt|;
name|fsb
operator|->
name|f_bsize
operator|=
name|fsd
operator|.
name|du_bsize
expr_stmt|;
name|fsb
operator|->
name|f_blocks
operator|=
name|fsd
operator|.
name|du_fsize
operator|-
name|fsd
operator|.
name|du_isize
expr_stmt|;
name|fsb
operator|->
name|f_bfree
operator|=
name|fsd
operator|.
name|du_tfree
expr_stmt|;
name|fsb
operator|->
name|f_bavail
operator|=
name|fsd
operator|.
name|du_tfree
expr_stmt|;
name|fsb
operator|->
name|f_files
operator|=
operator|(
name|fsd
operator|.
name|du_isize
operator|-
literal|2
operator|)
operator|*
name|fsd
operator|.
name|du_inopb
expr_stmt|;
name|fsb
operator|->
name|f_ffree
operator|=
name|fsd
operator|.
name|du_tinode
expr_stmt|;
name|fsb
operator|->
name|f_fsid
operator|.
name|val
index|[
literal|0
index|]
operator|=
name|fsd
operator|.
name|du_site
expr_stmt|;
name|fsb
operator|->
name|f_fsid
operator|.
name|val
index|[
literal|1
index|]
operator|=
name|fsd
operator|.
name|du_pckno
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX&& _I386 */
end_comment

end_unit

