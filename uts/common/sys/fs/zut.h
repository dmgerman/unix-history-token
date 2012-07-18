begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZUT_H
end_ifndef

begin_define
define|#
directive|define
name|_ZUT_H
end_define

begin_comment
comment|/*  * IOCTLs for the zfs unit test driver  */
end_comment

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
include|#
directive|include
file|<sys/param.h>
include|#
directive|include
file|<sys/types.h>
include|#
directive|include
file|<sys/stat.h>
define|#
directive|define
name|ZUT_DRIVER
value|"zut"
define|#
directive|define
name|ZUT_DEV
value|"/dev/zut"
define|#
directive|define
name|ZUT_VERSION_STRING
value|"1"
comment|/*  * /dev/zut ioctl numbers.  */
define|#
directive|define
name|ZUT_IOC
value|('U'<< 8)
comment|/* Request flags */
define|#
directive|define
name|ZUT_IGNORECASE
value|0x01
define|#
directive|define
name|ZUT_ACCFILTER
value|0x02
define|#
directive|define
name|ZUT_XATTR
value|0x04
define|#
directive|define
name|ZUT_EXTRDDIR
value|0x08
define|#
directive|define
name|ZUT_GETSTAT
value|0x10
typedef|typedef
struct|struct
name|zut_lookup
block|{
name|int
name|zl_reqflags
decl_stmt|;
name|int
name|zl_deflags
decl_stmt|;
comment|/* output */
name|int
name|zl_retcode
decl_stmt|;
comment|/* output */
name|char
name|zl_dir
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|zl_file
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|char
name|zl_xfile
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|char
name|zl_real
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* output */
name|uint64_t
name|zl_xvattrs
decl_stmt|;
comment|/* output */
name|struct
name|stat64
name|zl_statbuf
decl_stmt|;
comment|/* output */
block|}
name|zut_lookup_t
typedef|;
typedef|typedef
struct|struct
name|zut_readdir
block|{
name|uint64_t
name|zr_buf
decl_stmt|;
comment|/* pointer to output buffer */
name|uint64_t
name|zr_loffset
decl_stmt|;
comment|/* output */
name|char
name|zr_dir
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|zr_file
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|int
name|zr_reqflags
decl_stmt|;
name|int
name|zr_retcode
decl_stmt|;
comment|/* output */
name|int
name|zr_eof
decl_stmt|;
comment|/* output */
name|uint_t
name|zr_bytes
decl_stmt|;
comment|/* output */
name|uint_t
name|zr_buflen
decl_stmt|;
block|}
name|zut_readdir_t
typedef|;
typedef|typedef
enum|enum
name|zut_ioc
block|{
name|ZUT_IOC_MIN_CMD
init|=
name|ZUT_IOC
operator|-
literal|1
block|,
name|ZUT_IOC_LOOKUP
init|=
name|ZUT_IOC
block|,
name|ZUT_IOC_READDIR
block|,
name|ZUT_IOC_MAX_CMD
block|}
name|zut_ioc_t
typedef|;
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
comment|/* _ZUT_H */
end_comment

end_unit

