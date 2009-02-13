begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_DEVID_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_DEVID_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/disk.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|ddi_devid
block|{
name|char
name|devid
index|[
name|DISK_IDENT_SIZE
index|]
decl_stmt|;
block|}
name|ddi_devid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|devid_nmlist
block|{
name|char
name|devname
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
block|}
name|devid_nmlist_t
typedef|;
end_typedef

begin_function_decl
name|int
name|devid_str_decode
parameter_list|(
name|char
modifier|*
name|devidstr
parameter_list|,
name|ddi_devid_t
modifier|*
name|retdevid
parameter_list|,
name|char
modifier|*
modifier|*
name|retminor_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devid_deviceid_to_nmlist
parameter_list|(
name|char
modifier|*
name|search_path
parameter_list|,
name|ddi_devid_t
name|devid
parameter_list|,
name|char
modifier|*
name|minor_name
parameter_list|,
name|devid_nmlist_t
modifier|*
modifier|*
name|retlist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devid_str_free
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devid_free
parameter_list|(
name|ddi_devid_t
name|devid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devid_free_nmlist
parameter_list|(
name|devid_nmlist_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devid_get
parameter_list|(
name|int
name|fd
parameter_list|,
name|ddi_devid_t
modifier|*
name|retdevid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devid_get_minor_name
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
modifier|*
name|retminor_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|devid_str_encode
parameter_list|(
name|ddi_devid_t
name|devid
parameter_list|,
name|char
modifier|*
name|minor_name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OPENSOLARIS_DEVID_H_ */
end_comment

end_unit

