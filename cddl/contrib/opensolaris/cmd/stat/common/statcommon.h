begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004, 2010, Oracle and/or its affiliates. All rights reserved.  *  * Common routines for acquiring snapshots of kstats for  * iostat, mpstat, and vmstat.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STATCOMMON_H
end_ifndef

begin_define
define|#
directive|define
name|_STATCOMMON_H
end_define

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
file|<stdio.h>
include|#
directive|include
file|<sys/types.h>
include|#
directive|include
file|<time.h>
define|#
directive|define
name|NODATE
value|0
comment|/* Default:  No time stamp */
define|#
directive|define
name|DDATE
value|1
comment|/* Standard date format */
define|#
directive|define
name|UDATE
value|2
comment|/* Internal representation of Unix time */
comment|/* Print a timestamp in either Unix or standard format. */
name|void
name|print_timestamp
parameter_list|(
name|uint_t
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
comment|/* _STATCOMMON_H */
end_comment

end_unit

