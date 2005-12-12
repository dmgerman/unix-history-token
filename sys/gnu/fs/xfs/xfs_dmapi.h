begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DMAPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DMAPI_H__
end_define

begin_comment
comment|/*	Values used to define the on-disk version of dm_attrname_t. All  *	on-disk attribute names start with the 8-byte string "SGI_DMI_".  *  *      In the on-disk inode, DMAPI attribute names consist of the user-provided  *      name with the DMATTR_PREFIXSTRING pre-pended.  This string must NEVER be  *      changed.  */
end_comment

begin_define
define|#
directive|define
name|DMATTR_PREFIXLEN
value|8
end_define

begin_define
define|#
directive|define
name|DMATTR_PREFIXSTRING
value|"SGI_DMI_"
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|DM_EVENT_INVALID
init|=
operator|-
literal|1
block|,
name|DM_EVENT_CANCEL
init|=
literal|0
block|,
comment|/* not supported */
name|DM_EVENT_MOUNT
init|=
literal|1
block|,
name|DM_EVENT_PREUNMOUNT
init|=
literal|2
block|,
name|DM_EVENT_UNMOUNT
init|=
literal|3
block|,
name|DM_EVENT_DEBUT
init|=
literal|4
block|,
comment|/* not supported */
name|DM_EVENT_CREATE
init|=
literal|5
block|,
name|DM_EVENT_CLOSE
init|=
literal|6
block|,
comment|/* not supported */
name|DM_EVENT_POSTCREATE
init|=
literal|7
block|,
name|DM_EVENT_REMOVE
init|=
literal|8
block|,
name|DM_EVENT_POSTREMOVE
init|=
literal|9
block|,
name|DM_EVENT_RENAME
init|=
literal|10
block|,
name|DM_EVENT_POSTRENAME
init|=
literal|11
block|,
name|DM_EVENT_LINK
init|=
literal|12
block|,
name|DM_EVENT_POSTLINK
init|=
literal|13
block|,
name|DM_EVENT_SYMLINK
init|=
literal|14
block|,
name|DM_EVENT_POSTSYMLINK
init|=
literal|15
block|,
name|DM_EVENT_READ
init|=
literal|16
block|,
name|DM_EVENT_WRITE
init|=
literal|17
block|,
name|DM_EVENT_TRUNCATE
init|=
literal|18
block|,
name|DM_EVENT_ATTRIBUTE
init|=
literal|19
block|,
name|DM_EVENT_DESTROY
init|=
literal|20
block|,
name|DM_EVENT_NOSPACE
init|=
literal|21
block|,
name|DM_EVENT_USER
init|=
literal|22
block|,
name|DM_EVENT_MAX
init|=
literal|23
block|}
name|dm_eventtype_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_DM_EVENTTYPE_T
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|DM_RIGHT_NULL
block|,
name|DM_RIGHT_SHARED
block|,
name|DM_RIGHT_EXCL
block|}
name|dm_right_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_DM_RIGHT_T
end_define

begin_comment
comment|/* Defines for determining if an event message should be sent. */
end_comment

begin_define
define|#
directive|define
name|DM_EVENT_ENABLED
parameter_list|(
name|vfsp
parameter_list|,
name|ip
parameter_list|,
name|event
parameter_list|)
value|( \ 	unlikely ((vfsp)->vfs_flag& VFS_DMI)&& \ 		( ((ip)->i_d.di_dmevmask& (1<< event)) || \ 		  ((ip)->i_mount->m_dmevmask& (1<< event)) ) \ 	)
end_define

begin_define
define|#
directive|define
name|DM_EVENT_ENABLED_IO
parameter_list|(
name|vfsp
parameter_list|,
name|io
parameter_list|,
name|event
parameter_list|)
value|( \ 	unlikely ((vfsp)->vfs_flag& VFS_DMI)&& \ 		( ((io)->io_dmevmask& (1<< event)) || \ 		  ((io)->io_mount->m_dmevmask& (1<< event)) ) \ 	)
end_define

begin_define
define|#
directive|define
name|DM_XFS_VALID_FS_EVENTS
value|( \ 	(1<< DM_EVENT_PREUNMOUNT)	| \ 	(1<< DM_EVENT_UNMOUNT)		| \ 	(1<< DM_EVENT_NOSPACE)		| \ 	(1<< DM_EVENT_DEBUT)		| \ 	(1<< DM_EVENT_CREATE)		| \ 	(1<< DM_EVENT_POSTCREATE)	| \ 	(1<< DM_EVENT_REMOVE)		| \ 	(1<< DM_EVENT_POSTREMOVE)	| \ 	(1<< DM_EVENT_RENAME)		| \ 	(1<< DM_EVENT_POSTRENAME)	| \ 	(1<< DM_EVENT_LINK)		| \ 	(1<< DM_EVENT_POSTLINK)	| \ 	(1<< DM_EVENT_SYMLINK)		| \ 	(1<< DM_EVENT_POSTSYMLINK)	| \ 	(1<< DM_EVENT_ATTRIBUTE)	| \ 	(1<< DM_EVENT_DESTROY)		)
end_define

begin_comment
comment|/* Events valid in dm_set_eventlist() when called with a file handle for    a regular file or a symlink.  These events are persistent. */
end_comment

begin_define
define|#
directive|define
name|DM_XFS_VALID_FILE_EVENTS
value|( \ 	(1<< DM_EVENT_ATTRIBUTE)	| \ 	(1<< DM_EVENT_DESTROY)		)
end_define

begin_comment
comment|/* Events valid in dm_set_eventlist() when called with a file handle for    a directory.  These events are persistent. */
end_comment

begin_define
define|#
directive|define
name|DM_XFS_VALID_DIRECTORY_EVENTS
value|( \ 	(1<< DM_EVENT_CREATE)		| \ 	(1<< DM_EVENT_POSTCREATE)	| \ 	(1<< DM_EVENT_REMOVE)		| \ 	(1<< DM_EVENT_POSTREMOVE)	| \ 	(1<< DM_EVENT_RENAME)		| \ 	(1<< DM_EVENT_POSTRENAME)	| \ 	(1<< DM_EVENT_LINK)		| \ 	(1<< DM_EVENT_POSTLINK)	| \ 	(1<< DM_EVENT_SYMLINK)		| \ 	(1<< DM_EVENT_POSTSYMLINK)	| \ 	(1<< DM_EVENT_ATTRIBUTE)	| \ 	(1<< DM_EVENT_DESTROY)		)
end_define

begin_comment
comment|/* Events supported by the XFS filesystem. */
end_comment

begin_define
define|#
directive|define
name|DM_XFS_SUPPORTED_EVENTS
value|( \ 	(1<< DM_EVENT_MOUNT)		| \ 	(1<< DM_EVENT_PREUNMOUNT)	| \ 	(1<< DM_EVENT_UNMOUNT)		| \ 	(1<< DM_EVENT_NOSPACE)		| \ 	(1<< DM_EVENT_CREATE)		| \ 	(1<< DM_EVENT_POSTCREATE)	| \ 	(1<< DM_EVENT_REMOVE)		| \ 	(1<< DM_EVENT_POSTREMOVE)	| \ 	(1<< DM_EVENT_RENAME)		| \ 	(1<< DM_EVENT_POSTRENAME)	| \ 	(1<< DM_EVENT_LINK)		| \ 	(1<< DM_EVENT_POSTLINK)	| \ 	(1<< DM_EVENT_SYMLINK)		| \ 	(1<< DM_EVENT_POSTSYMLINK)	| \ 	(1<< DM_EVENT_READ)		| \ 	(1<< DM_EVENT_WRITE)		| \ 	(1<< DM_EVENT_TRUNCATE)	| \ 	(1<< DM_EVENT_ATTRIBUTE)	| \ 	(1<< DM_EVENT_DESTROY)		)
end_define

begin_comment
comment|/*  *	Definitions used for the flags field on dm_send_*_event().  */
end_comment

begin_define
define|#
directive|define
name|DM_FLAGS_NDELAY
value|0x001
end_define

begin_comment
comment|/* return EAGAIN after dm_pending() */
end_comment

begin_define
define|#
directive|define
name|DM_FLAGS_UNWANTED
value|0x002
end_define

begin_comment
comment|/* event not in fsys dm_eventset_t */
end_comment

begin_define
define|#
directive|define
name|DM_FLAGS_ISEM
value|0x004
end_define

begin_comment
comment|/* thread holds i_sem */
end_comment

begin_define
define|#
directive|define
name|DM_FLAGS_IALLOCSEM_RD
value|0x010
end_define

begin_comment
comment|/* thread holds i_alloc_sem rd */
end_comment

begin_define
define|#
directive|define
name|DM_FLAGS_IALLOCSEM_WR
value|0x020
end_define

begin_comment
comment|/* thread holds i_alloc_sem wr */
end_comment

begin_comment
comment|/*  *	Based on IO_ISDIRECT, decide which i_ flag is set.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DM_FLAGS_IALLOCSEM_RD
end_ifdef

begin_define
define|#
directive|define
name|DM_SEM_FLAG_RD
parameter_list|(
name|ioflags
parameter_list|)
value|(((ioflags)& IO_ISDIRECT) ? \ 			      DM_FLAGS_IALLOCSEM_RD : DM_FLAGS_ISEM)
end_define

begin_define
define|#
directive|define
name|DM_SEM_FLAG_WR
value|(DM_FLAGS_IALLOCSEM_WR | DM_FLAGS_ISEM)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DM_SEM_FLAG_RD
parameter_list|(
name|ioflags
parameter_list|)
value|(((ioflags)& IO_ISDIRECT) ? \ 			      0 : DM_FLAGS_ISEM)
end_define

begin_define
define|#
directive|define
name|DM_SEM_FLAG_WR
value|(DM_FLAGS_ISEM)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	Macros to turn caller specified delay/block flags into  *	dm_send_xxxx_event flag DM_FLAGS_NDELAY.  */
end_comment

begin_define
define|#
directive|define
name|FILP_DELAY_FLAG
parameter_list|(
name|filp
parameter_list|)
value|((filp->f_flags&(O_NDELAY|O_NONBLOCK)) ? \ 			DM_FLAGS_NDELAY : 0)
end_define

begin_define
define|#
directive|define
name|AT_DELAY_FLAG
parameter_list|(
name|f
parameter_list|)
value|((f&ATTR_NONBLOCK) ? DM_FLAGS_NDELAY : 0)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|bhv_vfsops
name|xfs_dmops
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|dmapi_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dmapi_uninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DMAPI_H__ */
end_comment

end_unit

