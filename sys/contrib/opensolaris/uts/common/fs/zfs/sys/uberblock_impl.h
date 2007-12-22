begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UBERBLOCK_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UBERBLOCK_IMPL_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/uberblock.h>
end_include

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
comment|/*  * The uberblock version is incremented whenever an incompatible on-disk  * format change is made to the SPA, DMU, or ZAP.  *  * Note: the first two fields should never be moved.  When a storage pool  * is opened, the uberblock must be read off the disk before the version  * can be checked.  If the ub_version field is moved, we may not detect  * version mismatch.  If the ub_magic field is moved, applications that  * expect the magic number in the first word won't work.  */
define|#
directive|define
name|UBERBLOCK_MAGIC
value|0x00bab10c
comment|/* oo-ba-bloc!	*/
define|#
directive|define
name|UBERBLOCK_SHIFT
value|10
comment|/* up to 1K	*/
struct|struct
name|uberblock
block|{
name|uint64_t
name|ub_magic
decl_stmt|;
comment|/* UBERBLOCK_MAGIC		*/
name|uint64_t
name|ub_version
decl_stmt|;
comment|/* ZFS_VERSION			*/
name|uint64_t
name|ub_txg
decl_stmt|;
comment|/* txg of last sync		*/
name|uint64_t
name|ub_guid_sum
decl_stmt|;
comment|/* sum of all vdev guids	*/
name|uint64_t
name|ub_timestamp
decl_stmt|;
comment|/* UTC time of last sync	*/
name|blkptr_t
name|ub_rootbp
decl_stmt|;
comment|/* MOS objset_phys_t		*/
block|}
struct|;
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
comment|/* _SYS_UBERBLOCK_IMPL_H */
end_comment

end_unit

