begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005, 2010, Oracle and/or its affiliates. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ZIO_CHECKSUM_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ZIO_CHECKSUM_H
end_define

begin_include
include|#
directive|include
file|<sys/zio.h>
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
comment|/*  * Signature for checksum functions.  */
typedef|typedef
name|void
name|zio_checksum_t
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|zio_cksum_t
modifier|*
name|zcp
parameter_list|)
function_decl|;
comment|/*  * Information about each checksum function.  */
typedef|typedef
struct|struct
name|zio_checksum_info
block|{
name|zio_checksum_t
modifier|*
name|ci_func
index|[
literal|2
index|]
decl_stmt|;
comment|/* checksum function for each byteorder */
name|int
name|ci_correctable
decl_stmt|;
comment|/* number of correctable bits	*/
name|int
name|ci_eck
decl_stmt|;
comment|/* uses zio embedded checksum? */
name|int
name|ci_dedup
decl_stmt|;
comment|/* strong enough for dedup? */
name|char
modifier|*
name|ci_name
decl_stmt|;
comment|/* descriptive name */
block|}
name|zio_checksum_info_t
typedef|;
typedef|typedef
struct|struct
name|zio_bad_cksum
block|{
name|zio_cksum_t
name|zbc_expected
decl_stmt|;
name|zio_cksum_t
name|zbc_actual
decl_stmt|;
specifier|const
name|char
modifier|*
name|zbc_checksum_name
decl_stmt|;
name|uint8_t
name|zbc_byteswapped
decl_stmt|;
name|uint8_t
name|zbc_injected
decl_stmt|;
name|uint8_t
name|zbc_has_cksum
decl_stmt|;
comment|/* expected/actual valid */
block|}
name|zio_bad_cksum_t
typedef|;
specifier|extern
name|zio_checksum_info_t
name|zio_checksum_table
index|[
name|ZIO_CHECKSUM_FUNCTIONS
index|]
decl_stmt|;
comment|/*  * Checksum routines.  */
specifier|extern
name|zio_checksum_t
name|zio_checksum_SHA256
decl_stmt|;
specifier|extern
name|void
name|zio_checksum_compute
parameter_list|(
name|zio_t
modifier|*
name|zio
parameter_list|,
name|enum
name|zio_checksum
name|checksum
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|uint64_t
name|size
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zio_checksum_error
parameter_list|(
name|zio_t
modifier|*
name|zio
parameter_list|,
name|zio_bad_cksum_t
modifier|*
name|out
parameter_list|)
function_decl|;
specifier|extern
name|enum
name|zio_checksum
name|spa_dedup_checksum
parameter_list|(
name|spa_t
modifier|*
name|spa
parameter_list|)
function_decl|;
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
comment|/* _SYS_ZIO_CHECKSUM_H */
end_comment

end_unit

