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
name|_SYS_FM_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FM_UTIL_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

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
file|<sys/nvpair.h>
include|#
directive|include
file|<sys/errorq.h>
comment|/*  * Shared user/kernel definitions for class length, error channel name,  * and kernel event publisher string.  */
define|#
directive|define
name|FM_MAX_CLASS
value|100
define|#
directive|define
name|FM_ERROR_CHAN
value|"com.sun:fm:error"
define|#
directive|define
name|FM_PUB
value|"fm"
comment|/*  * ereport dump device transport support  *  * Ereports are written out to the dump device at a proscribed offset from the  * end, similar to in-transit log messages.  The ereports are represented as a  * erpt_dump_t header followed by ed_size bytes of packed native nvlist data.  *  * NOTE: All of these constants and the header must be defined so they have the  * same representation for *both* 32-bit and 64-bit producers and consumers.  */
define|#
directive|define
name|ERPT_MAGIC
value|0xf00d4eddU
define|#
directive|define
name|ERPT_MAX_ERRS
value|16
define|#
directive|define
name|ERPT_DATA_SZ
value|(6 * 1024)
define|#
directive|define
name|ERPT_EVCH_MAX
value|256
define|#
directive|define
name|ERPT_HIWAT
value|64
typedef|typedef
struct|struct
name|erpt_dump
block|{
name|uint32_t
name|ed_magic
decl_stmt|;
comment|/* ERPT_MAGIC or zero to indicate end */
name|uint32_t
name|ed_chksum
decl_stmt|;
comment|/* checksum32() of packed nvlist data */
name|uint32_t
name|ed_size
decl_stmt|;
comment|/* ereport (nvl) fixed buf size */
name|uint32_t
name|ed_pad
decl_stmt|;
comment|/* reserved for future use */
name|hrtime_t
name|ed_hrt_nsec
decl_stmt|;
comment|/* hrtime of this ereport */
name|hrtime_t
name|ed_hrt_base
decl_stmt|;
comment|/* hrtime sample corresponding to ed_tod_base */
struct|struct
block|{
name|uint64_t
name|sec
decl_stmt|;
comment|/* seconds since gettimeofday() Epoch */
name|uint64_t
name|nsec
decl_stmt|;
comment|/* nanoseconds past ed_tod_base.sec */
block|}
name|ed_tod_base
struct|;
block|}
name|erpt_dump_t
typedef|;
ifdef|#
directive|ifdef
name|_KERNEL
include|#
directive|include
file|<sys/systm.h>
define|#
directive|define
name|FM_STK_DEPTH
value|20
comment|/* maximum stack depth */
define|#
directive|define
name|FM_SYM_SZ
value|64
comment|/* maximum symbol size */
define|#
directive|define
name|FM_ERR_PIL
value|2
comment|/* PIL for ereport_errorq drain processing */
define|#
directive|define
name|FM_EREPORT_PAYLOAD_NAME_STACK
value|"stack"
specifier|extern
name|errorq_t
modifier|*
name|ereport_errorq
decl_stmt|;
specifier|extern
name|void
modifier|*
name|ereport_dumpbuf
decl_stmt|;
specifier|extern
name|size_t
name|ereport_dumplen
decl_stmt|;
specifier|extern
name|void
name|fm_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|fm_nvprint
parameter_list|(
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|fm_panic
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|void
name|fm_banner
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|fm_ereport_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|fm_ereport_post
parameter_list|(
name|nvlist_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* _KERNEL */
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
comment|/* _SYS_FM_UTIL_H */
end_comment

end_unit

