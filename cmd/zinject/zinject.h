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
name|_ZINJECT_H
end_ifndef

begin_define
define|#
directive|define
name|_ZINJECT_H
end_define

begin_include
include|#
directive|include
file|<sys/zfs_ioctl.h>
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
typedef|typedef
enum|enum
block|{
name|TYPE_DATA
block|,
comment|/* plain file contents		*/
name|TYPE_DNODE
block|,
comment|/* metadnode contents		*/
name|TYPE_MOS
block|,
comment|/* all MOS data			*/
name|TYPE_MOSDIR
block|,
comment|/* MOS object directory		*/
name|TYPE_METASLAB
block|,
comment|/* metaslab objects		*/
name|TYPE_CONFIG
block|,
comment|/* MOS config			*/
name|TYPE_BPOBJ
block|,
comment|/* block pointer list		*/
name|TYPE_SPACEMAP
block|,
comment|/* space map objects		*/
name|TYPE_ERRLOG
block|,
comment|/* persistent error log		*/
name|TYPE_LABEL_UBERBLOCK
block|,
comment|/* label specific uberblock	*/
name|TYPE_LABEL_NVLIST
block|,
comment|/* label specific nvlist	*/
name|TYPE_LABEL_PAD1
block|,
comment|/* label specific 8K pad1 area	*/
name|TYPE_LABEL_PAD2
block|,
comment|/* label specific 8K pad2 area	*/
name|TYPE_INVAL
block|}
name|err_type_t
typedef|;
define|#
directive|define
name|MOS_TYPE
parameter_list|(
name|t
parameter_list|)
define|\
value|((t)>= TYPE_MOS&& (t)< TYPE_LABEL_UBERBLOCK)
define|#
directive|define
name|LABEL_TYPE
parameter_list|(
name|t
parameter_list|)
define|\
value|((t)>= TYPE_LABEL_UBERBLOCK&& (t)< TYPE_INVAL)
name|int
name|translate_record
parameter_list|(
name|err_type_t
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|object
parameter_list|,
specifier|const
name|char
modifier|*
name|range
parameter_list|,
name|int
name|level
parameter_list|,
name|zinject_record_t
modifier|*
name|record
parameter_list|,
name|char
modifier|*
name|poolname
parameter_list|,
name|char
modifier|*
name|dataset
parameter_list|)
function_decl|;
name|int
name|translate_raw
parameter_list|(
specifier|const
name|char
modifier|*
name|raw
parameter_list|,
name|zinject_record_t
modifier|*
name|record
parameter_list|)
function_decl|;
name|int
name|translate_device
parameter_list|(
specifier|const
name|char
modifier|*
name|pool
parameter_list|,
specifier|const
name|char
modifier|*
name|device
parameter_list|,
name|err_type_t
name|label_type
parameter_list|,
name|zinject_record_t
modifier|*
name|record
parameter_list|)
function_decl|;
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|libzfs_handle_t
modifier|*
name|g_zfs
decl_stmt|;
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
comment|/* _ZINJECT_H */
end_comment

end_unit

