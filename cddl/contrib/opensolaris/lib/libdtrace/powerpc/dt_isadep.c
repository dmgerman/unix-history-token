begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<libgen.h>
end_include

begin_include
include|#
directive|include
file|<dt_impl.h>
end_include

begin_include
include|#
directive|include
file|<dt_pid.h>
end_include

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|dt_pid_create_entry_probe
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
name|P
parameter_list|,
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|fasttrap_probe_spec_t
modifier|*
name|ftp
parameter_list|,
specifier|const
name|GElf_Sym
modifier|*
name|symp
parameter_list|)
block|{
name|dt_dprintf
argument_list|(
literal|"%s: unimplemented\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return
operator|(
name|DT_PROC_ERR
operator|)
return|;
block|}
end_function

begin_function
name|int
name|dt_pid_create_return_probe
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
name|P
parameter_list|,
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|fasttrap_probe_spec_t
modifier|*
name|ftp
parameter_list|,
specifier|const
name|GElf_Sym
modifier|*
name|symp
parameter_list|,
name|uint64_t
modifier|*
name|stret
parameter_list|)
block|{
name|dt_dprintf
argument_list|(
literal|"%s: unimplemented\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return
operator|(
name|DT_PROC_ERR
operator|)
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|dt_pid_create_offset_probe
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
name|P
parameter_list|,
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|fasttrap_probe_spec_t
modifier|*
name|ftp
parameter_list|,
specifier|const
name|GElf_Sym
modifier|*
name|symp
parameter_list|,
name|ulong_t
name|off
parameter_list|)
block|{
name|dt_dprintf
argument_list|(
literal|"%s: unimplemented\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return
operator|(
name|DT_PROC_ERR
operator|)
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|dt_pid_create_glob_offset_probes
parameter_list|(
name|struct
name|ps_prochandle
modifier|*
name|P
parameter_list|,
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|fasttrap_probe_spec_t
modifier|*
name|ftp
parameter_list|,
specifier|const
name|GElf_Sym
modifier|*
name|symp
parameter_list|,
specifier|const
name|char
modifier|*
name|pattern
parameter_list|)
block|{
name|dt_dprintf
argument_list|(
literal|"%s: unimplemented\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return
operator|(
name|DT_PROC_ERR
operator|)
return|;
block|}
end_function

end_unit

