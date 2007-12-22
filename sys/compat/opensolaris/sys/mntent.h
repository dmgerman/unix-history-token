begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  *  *	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T  *		All Rights Reserved  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_MNTENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_MNTENT_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_empty
empty|#include_next<sys/mount.h>
end_empty

begin_define
define|#
directive|define
name|MNTMAXSTR
value|128
end_define

begin_define
define|#
directive|define
name|MNTTYPE_ZFS
value|"zfs"
end_define

begin_comment
comment|/* ZFS file system */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_RO
value|"ro"
end_define

begin_comment
comment|/* Read only */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_RW
value|"rw"
end_define

begin_comment
comment|/* Read/write */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOSUID
value|"nosuid"
end_define

begin_comment
comment|/* Neither setuid nor devices allowed */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_DEVICES
value|"devices"
end_define

begin_comment
comment|/* Device-special allowed */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NODEVICES
value|"nodevices"
end_define

begin_comment
comment|/* Device-special disallowed */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_SETUID
value|"setuid"
end_define

begin_comment
comment|/* Set uid allowed */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOSETUID
value|"nosetuid"
end_define

begin_comment
comment|/* Set uid not allowed */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_REMOUNT
value|"remount"
end_define

begin_comment
comment|/* Change mount options */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_ATIME
value|"atime"
end_define

begin_comment
comment|/* update atime for files */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOATIME
value|"noatime"
end_define

begin_comment
comment|/* do not update atime for files */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_XATTR
value|"xattr"
end_define

begin_comment
comment|/* enable extended attributes */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOXATTR
value|"noxattr"
end_define

begin_comment
comment|/* disable extended attributes */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_EXEC
value|"exec"
end_define

begin_comment
comment|/* enable executables */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOEXEC
value|"noexec"
end_define

begin_comment
comment|/* disable executables */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_RESTRICT
value|"restrict"
end_define

begin_comment
comment|/* restricted autofs mount */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OPENSOLARIS_MNTENT_H_ */
end_comment

end_unit

