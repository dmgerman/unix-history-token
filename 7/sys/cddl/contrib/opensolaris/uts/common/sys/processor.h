begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  *	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T  *	  All Rights Reserved  *  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PROCESSOR_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PROCESSOR_H
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/procset.h>
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
comment|/*  * Definitions for p_online, processor_info& lgrp system calls.  */
comment|/*  * Type for an lgrpid  */
typedef|typedef
name|uint16_t
name|lgrpid_t
typedef|;
comment|/*  * Type for processor name (CPU number).  */
typedef|typedef
name|int
name|processorid_t
typedef|;
typedef|typedef
name|int
name|chipid_t
typedef|;
comment|/*  * Flags and return values for p_online(2), and pi_state for processor_info(2).  * These flags are *not* for in-kernel examination of CPU states.  * See<sys/cpuvar.h> for appropriate informational functions.  */
define|#
directive|define
name|P_OFFLINE
value|0x0001
comment|/* processor is offline, as quiet as possible */
define|#
directive|define
name|P_ONLINE
value|0x0002
comment|/* processor is online */
define|#
directive|define
name|P_STATUS
value|0x0003
comment|/* value passed to p_online to request status */
define|#
directive|define
name|P_FAULTED
value|0x0004
comment|/* processor is offline, in faulted state */
define|#
directive|define
name|P_POWEROFF
value|0x0005
comment|/* processor is powered off */
define|#
directive|define
name|P_NOINTR
value|0x0006
comment|/* processor is online, but no I/O interrupts */
define|#
directive|define
name|P_SPARE
value|0x0007
comment|/* processor is offline, can be reactivated */
define|#
directive|define
name|P_BAD
value|P_FAULTED
comment|/* unused but defined by USL */
define|#
directive|define
name|P_FORCED
value|0x10000000
comment|/* force processor offline */
comment|/*  * String names for processor states defined above.  */
define|#
directive|define
name|PS_OFFLINE
value|"off-line"
define|#
directive|define
name|PS_ONLINE
value|"on-line"
define|#
directive|define
name|PS_FAULTED
value|"faulted"
define|#
directive|define
name|PS_POWEROFF
value|"powered-off"
define|#
directive|define
name|PS_NOINTR
value|"no-intr"
define|#
directive|define
name|PS_SPARE
value|"spare"
comment|/*  * Structure filled in by processor_info(2).  *  * The string fields are guaranteed to contain a NULL.  *  * The pi_fputypes field contains a (possibly empty) comma-separated  * list of floating point identifier strings.  */
define|#
directive|define
name|PI_TYPELEN
value|16
comment|/* max size of CPU type string */
define|#
directive|define
name|PI_FPUTYPE
value|32
comment|/* max size of FPU types string */
typedef|typedef
struct|struct
block|{
name|int
name|pi_state
decl_stmt|;
comment|/* processor state, see above */
name|char
name|pi_processor_type
index|[
name|PI_TYPELEN
index|]
decl_stmt|;
comment|/* ASCII CPU type */
name|char
name|pi_fputypes
index|[
name|PI_FPUTYPE
index|]
decl_stmt|;
comment|/* ASCII FPU types */
name|int
name|pi_clock
decl_stmt|;
comment|/* CPU clock freq in MHz */
block|}
name|processor_info_t
typedef|;
comment|/*  * Binding values for processor_bind(2)  */
define|#
directive|define
name|PBIND_NONE
value|-1
comment|/* LWP/thread is not bound */
define|#
directive|define
name|PBIND_QUERY
value|-2
comment|/* don't set, just return the binding */
comment|/*  * User-level system call interface prototypes  */
ifndef|#
directive|ifndef
name|_KERNEL
ifdef|#
directive|ifdef
name|__STDC__
specifier|extern
name|int
name|p_online
parameter_list|(
name|processorid_t
name|processorid
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
specifier|extern
name|int
name|processor_info
parameter_list|(
name|processorid_t
name|processorid
parameter_list|,
name|processor_info_t
modifier|*
name|infop
parameter_list|)
function_decl|;
specifier|extern
name|int
name|processor_bind
parameter_list|(
name|idtype_t
name|idtype
parameter_list|,
name|id_t
name|id
parameter_list|,
name|processorid_t
name|processorid
parameter_list|,
name|processorid_t
modifier|*
name|obind
parameter_list|)
function_decl|;
specifier|extern
name|processorid_t
name|getcpuid
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|lgrpid_t
name|gethomelgroup
parameter_list|(
name|void
parameter_list|)
function_decl|;
else|#
directive|else
specifier|extern
name|int
name|p_online
parameter_list|()
function_decl|;
specifier|extern
name|int
name|processor_info
parameter_list|()
function_decl|;
specifier|extern
name|int
name|processor_bind
parameter_list|()
function_decl|;
specifier|extern
name|processorid_t
name|getcpuid
parameter_list|()
function_decl|;
specifier|extern
name|lgrpid_t
name|gethomelgroup
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* __STDC__ */
else|#
directive|else
comment|/* _KERNEL */
comment|/*  * Internal interface prototypes  */
specifier|extern
name|int
name|p_online_internal
parameter_list|(
name|processorid_t
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* !_KERNEL */
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
comment|/* _SYS_PROCESSOR_H */
end_comment

end_unit

