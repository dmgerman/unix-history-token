begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Sean C. Farley<scf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_comment
comment|/*  * Static values for building and testing an artificial group.  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|grpName
index|[]
init|=
literal|"groupName"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|grpPasswd
index|[]
init|=
literal|"groupPwd"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|gid_t
name|grpGID
init|=
literal|1234
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|grpMems
index|[]
init|=
block|{
literal|"mem1"
block|,
literal|"mem2"
block|,
literal|"mem3"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|origStrGrp
init|=
literal|"groupName:groupPwd:1234:mem1,mem2,mem3"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Build a group to test against without depending on a real group to be found  * within /etc/group.  */
end_comment

begin_function
specifier|static
name|void
name|build_grp
parameter_list|(
name|struct
name|group
modifier|*
name|grp
parameter_list|)
block|{
name|grp
operator|->
name|gr_name
operator|=
name|grpName
expr_stmt|;
name|grp
operator|->
name|gr_passwd
operator|=
name|grpPasswd
expr_stmt|;
name|grp
operator|->
name|gr_gid
operator|=
name|grpGID
expr_stmt|;
name|grp
operator|->
name|gr_mem
operator|=
name|grpMems
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|char
modifier|*
name|strGrp
decl_stmt|;
name|int
name|testNdx
decl_stmt|;
name|struct
name|group
modifier|*
name|dupGrp
decl_stmt|;
name|struct
name|group
modifier|*
name|scanGrp
decl_stmt|;
name|struct
name|group
name|origGrp
decl_stmt|;
comment|/* Setup. */
name|printf
argument_list|(
literal|"1..4\n"
argument_list|)
expr_stmt|;
name|testNdx
operator|=
literal|0
expr_stmt|;
comment|/* Manually build a group using static values. */
name|build_grp
argument_list|(
operator|&
name|origGrp
argument_list|)
expr_stmt|;
comment|/* Copy the group. */
name|testNdx
operator|++
expr_stmt|;
if|if
condition|(
operator|(
name|dupGrp
operator|=
name|gr_dup
argument_list|(
operator|&
name|origGrp
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|printf
argument_list|(
literal|"not "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ok %d - %s\n"
argument_list|,
name|testNdx
argument_list|,
literal|"gr_dup"
argument_list|)
expr_stmt|;
comment|/* Compare the original and duplicate groups. */
name|testNdx
operator|++
expr_stmt|;
if|if
condition|(
operator|!
name|gr_equal
argument_list|(
operator|&
name|origGrp
argument_list|,
name|dupGrp
argument_list|)
condition|)
name|printf
argument_list|(
literal|"not "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ok %d - %s\n"
argument_list|,
name|testNdx
argument_list|,
literal|"gr_equal"
argument_list|)
expr_stmt|;
comment|/* Create group string from the duplicate group structure. */
name|testNdx
operator|++
expr_stmt|;
name|strGrp
operator|=
name|gr_make
argument_list|(
name|dupGrp
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|strGrp
argument_list|,
name|origStrGrp
argument_list|)
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"not "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ok %d - %s\n"
argument_list|,
name|testNdx
argument_list|,
literal|"gr_make"
argument_list|)
expr_stmt|;
comment|/* 	 * Create group structure from string and compare it to the original 	 * group structure. 	 */
name|testNdx
operator|++
expr_stmt|;
if|if
condition|(
operator|(
name|scanGrp
operator|=
name|gr_scan
argument_list|(
name|strGrp
argument_list|)
operator|)
operator|==
name|NULL
operator|||
operator|!
name|gr_equal
argument_list|(
operator|&
name|origGrp
argument_list|,
name|scanGrp
argument_list|)
condition|)
name|printf
argument_list|(
literal|"not "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ok %d - %s\n"
argument_list|,
name|testNdx
argument_list|,
literal|"gr_scan"
argument_list|)
expr_stmt|;
comment|/* Clean up. */
name|free
argument_list|(
name|scanGrp
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|strGrp
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|dupGrp
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

