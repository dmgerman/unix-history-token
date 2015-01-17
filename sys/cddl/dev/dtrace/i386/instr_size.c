begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*	Copyright (c) 1988 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|illumos
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"@(#)instr_size.c	1.14	05/07/08 SMI"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|illumos
end_ifdef

begin_include
include|#
directive|include
file|<sys/cmn_err.h>
end_include

begin_include
include|#
directive|include
file|<sys/archsystm.h>
end_include

begin_include
include|#
directive|include
file|<sys/copyops.h>
end_include

begin_include
include|#
directive|include
file|<vm/seg_enum.h>
end_include

begin_include
include|#
directive|include
file|<sys/privregs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|u_int
name|model_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DATAMODEL_NATIVE
value|0
end_define

begin_function_decl
name|int
name|dtrace_instr_size
parameter_list|(
name|uchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtrace_instr_size_isa
parameter_list|(
name|uchar_t
modifier|*
parameter_list|,
name|model_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dis_tables.h>
end_include

begin_comment
comment|/*  * This subsystem (with the minor exception of the instr_size() function) is  * is called from DTrace probe context.  This imposes several requirements on  * the implementation:  *  * 1. External subsystems and functions may not be referenced.  The one current  *    exception is for cmn_err, but only to signal the detection of table  *    errors.  Assuming the tables are correct, no combination of input is to  *    trigger a cmn_err call.  *  * 2. These functions can't be allowed to be traced.  To prevent this,  *    all functions in the probe path (everything except instr_size()) must  *    have names that begin with "dtrace_".  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|dis_isize
block|{
name|DIS_ISIZE_INSTR
block|,
name|DIS_ISIZE_OPERAND
block|}
name|dis_isize_t
typedef|;
end_typedef

begin_comment
comment|/*  * get a byte from instruction stream  */
end_comment

begin_function
specifier|static
name|int
name|dtrace_dis_get_byte
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|uchar_t
modifier|*
modifier|*
name|instr
init|=
name|p
decl_stmt|;
name|ret
operator|=
operator|*
operator|*
name|instr
expr_stmt|;
operator|*
name|instr
operator|+=
literal|1
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Returns either the size of a given instruction, in bytes, or the size of that  * instruction's memory access (if any), depending on the value of `which'.  * If a programming error in the tables is detected, the system will panic to  * ease diagnosis.  Invalid instructions will not be flagged.  They will appear  * to have an instruction size between 1 and the actual size, and will be  * reported as having no memory impact.  */
end_comment

begin_comment
comment|/* ARGSUSED2 */
end_comment

begin_function
specifier|static
name|int
name|dtrace_dis_isize
parameter_list|(
name|uchar_t
modifier|*
name|instr
parameter_list|,
name|dis_isize_t
name|which
parameter_list|,
name|model_t
name|model
parameter_list|,
name|int
modifier|*
name|rmindex
parameter_list|)
block|{
name|int
name|sz
decl_stmt|;
name|dis86_t
name|x
decl_stmt|;
name|uint_t
name|mode
init|=
name|SIZE32
decl_stmt|;
ifdef|#
directive|ifdef
name|illumos
name|mode
operator|=
operator|(
name|model
operator|==
name|DATAMODEL_LP64
operator|)
condition|?
name|SIZE64
else|:
name|SIZE32
expr_stmt|;
endif|#
directive|endif
name|x
operator|.
name|d86_data
operator|=
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|instr
expr_stmt|;
name|x
operator|.
name|d86_get_byte
operator|=
name|dtrace_dis_get_byte
expr_stmt|;
name|x
operator|.
name|d86_check_func
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|dtrace_disx86
argument_list|(
operator|&
name|x
argument_list|,
name|mode
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|which
operator|==
name|DIS_ISIZE_INSTR
condition|)
name|sz
operator|=
name|x
operator|.
name|d86_len
expr_stmt|;
comment|/* length of the instruction */
else|else
name|sz
operator|=
name|x
operator|.
name|d86_memsize
expr_stmt|;
comment|/* length of memory operand */
if|if
condition|(
name|rmindex
operator|!=
name|NULL
condition|)
operator|*
name|rmindex
operator|=
name|x
operator|.
name|d86_rmindex
expr_stmt|;
return|return
operator|(
name|sz
operator|)
return|;
block|}
end_function

begin_function
name|int
name|dtrace_instr_size_isa
parameter_list|(
name|uchar_t
modifier|*
name|instr
parameter_list|,
name|model_t
name|model
parameter_list|,
name|int
modifier|*
name|rmindex
parameter_list|)
block|{
return|return
operator|(
name|dtrace_dis_isize
argument_list|(
name|instr
argument_list|,
name|DIS_ISIZE_INSTR
argument_list|,
name|model
argument_list|,
name|rmindex
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|dtrace_instr_size
parameter_list|(
name|uchar_t
modifier|*
name|instr
parameter_list|)
block|{
return|return
operator|(
name|dtrace_dis_isize
argument_list|(
name|instr
argument_list|,
name|DIS_ISIZE_INSTR
argument_list|,
name|DATAMODEL_NATIVE
argument_list|,
name|NULL
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

