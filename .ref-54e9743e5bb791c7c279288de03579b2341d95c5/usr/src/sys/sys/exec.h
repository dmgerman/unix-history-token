begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)exec.h	8.3 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<machine/exec.h>
end_include

begin_comment
comment|/*  * The following structure is found at the top of the user stack of each  * user process. The ps program uses it to locate argv and environment  * strings. Programs that wish ps to display other information may modify  * it; normally ps_argvstr points to the text for argv[0], and ps_nargvstr  * is the same as the program's argc. The fields ps_envstr and ps_nenvstr  * are the equivalent for the environment.  */
end_comment

begin_struct
struct|struct
name|ps_strings
block|{
name|char
modifier|*
name|ps_argvstr
decl_stmt|;
comment|/* first of 0 or more argument strings */
name|int
name|ps_nargvstr
decl_stmt|;
comment|/* the number of argument strings */
name|char
modifier|*
name|ps_envstr
decl_stmt|;
comment|/* first of 0 or more environment strings */
name|int
name|ps_nenvstr
decl_stmt|;
comment|/* the number of environment strings */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Address of ps_strings structure (in user space).  */
end_comment

begin_define
define|#
directive|define
name|PS_STRINGS
define|\
value|((struct ps_strings *)(USRSTACK - sizeof(struct ps_strings)))
end_define

begin_comment
comment|/*  * Arguments to the exec system call.  */
end_comment

begin_struct
struct|struct
name|execve_args
block|{
name|char
modifier|*
name|fname
decl_stmt|;
name|char
modifier|*
modifier|*
name|argp
decl_stmt|;
name|char
modifier|*
modifier|*
name|envp
decl_stmt|;
block|}
struct|;
end_struct

end_unit

