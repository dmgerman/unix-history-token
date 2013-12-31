begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  * Copyright (c) 2013 Joyent, Inc. All rights reserved.  * Copyright 2012 Nexenta Systems, Inc.  All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VDEV_DISK_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VDEV_DISK_H
end_define

begin_include
include|#
directive|include
file|<sys/vdev.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/ddi.h>
end_include

begin_include
include|#
directive|include
file|<sys/sunldi.h>
end_include

begin_include
include|#
directive|include
file|<sys/sunddi.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_KERNEL
typedef|typedef
struct|struct
name|vdev_disk
block|{
name|ddi_devid_t
name|vd_devid
decl_stmt|;
name|char
modifier|*
name|vd_minor
decl_stmt|;
name|ldi_handle_t
name|vd_lh
decl_stmt|;
name|list_t
name|vd_ldi_cbs
decl_stmt|;
name|boolean_t
name|vd_ldi_offline
decl_stmt|;
block|}
name|vdev_disk_t
typedef|;
endif|#
directive|endif
specifier|extern
name|int
name|vdev_disk_physio
parameter_list|(
name|vdev_t
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|size_t
parameter_list|,
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
comment|/*  * Since vdev_disk.c is not compiled into libzpool, this function should only be  * defined in the zfs kernel module.  */
ifdef|#
directive|ifdef
name|_KERNEL
specifier|extern
name|int
name|vdev_disk_ldi_physio
parameter_list|(
name|ldi_handle_t
parameter_list|,
name|caddr_t
parameter_list|,
name|size_t
parameter_list|,
name|uint64_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_VDEV_DISK_H */
end_comment

end_unit

