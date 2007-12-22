begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Silicon Graphics, Inc.  All Rights Reserved.  *   * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *   * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *   * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *   * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *   * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *   * http://www.sgi.com   *   * For further information regarding this notice, see:   *   * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_DEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPPORT_DEBUG_H__
end_define

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_define
define|#
directive|define
name|CE_DEBUG
value|7
end_define

begin_comment
comment|/* debug        */
end_comment

begin_define
define|#
directive|define
name|CE_CONT
value|6
end_define

begin_comment
comment|/* continuation */
end_comment

begin_define
define|#
directive|define
name|CE_NOTE
value|5
end_define

begin_comment
comment|/* notice       */
end_comment

begin_define
define|#
directive|define
name|CE_WARN
value|4
end_define

begin_comment
comment|/* warning      */
end_comment

begin_define
define|#
directive|define
name|CE_ALERT
value|1
end_define

begin_comment
comment|/* alert        */
end_comment

begin_define
define|#
directive|define
name|CE_PANIC
value|0
end_define

begin_comment
comment|/* panic        */
end_comment

begin_function_decl
specifier|extern
name|void
name|icmn_err
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cmn_err
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|prdev
parameter_list|(
name|fmt
parameter_list|,
name|targ
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|printf("Device %s - " fmt "\n", XFS_BUFTARG_NAME(targ), ## args)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|STATIC
end_ifndef

begin_define
define|#
directive|define
name|STATIC
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|EX
parameter_list|)
value|((void)0)
end_define

begin_comment
comment|/* avoid "constant in conditional" babble */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|EX
parameter_list|)
value|((EX)?((void)0):assfail(#EX, __FILE__, __LINE__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DEBUG */
end_comment

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|x
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|assfail
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_thread_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|assfail
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASSERT_ALWAYS
parameter_list|(
name|EX
parameter_list|)
value|((EX)?((void)0):assfail(#EX, __FILE__, __LINE__))
end_define

begin_define
define|#
directive|define
name|debug_stop_all_cpus
parameter_list|(
name|param
parameter_list|)
end_define

begin_comment
comment|/* param is "cpumask_t *" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_DEBUG_H__ */
end_comment

end_unit

