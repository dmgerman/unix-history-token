begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_bootblock.c,v 1.1 2010/07/17 19:26:27 jmmv Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004, 2008, 2010 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__COPYRIGHT
argument_list|(
literal|"@(#) Copyright (c) 2008, 2010\  The NetBSD Foundation, inc. All rights reserved."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_bootblock.c,v 1.1 2010/07/17 19:26:27 jmmv Exp $"
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
file|<sys/bootblock.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|mbr_sector
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|mbr_sector
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|ATF_CHECK_EQ
argument_list|(
literal|512
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|mbr_sector
argument_list|)
argument_list|)
expr_stmt|;
name|ATF_CHECK_EQ
argument_list|(
name|MBR_BPB_OFFSET
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|mbr_sector
argument_list|,
name|mbr_bpb
argument_list|)
argument_list|)
expr_stmt|;
name|ATF_CHECK_EQ
argument_list|(
name|MBR_BS_OFFSET
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|mbr_sector
argument_list|,
name|mbr_bootsel
argument_list|)
argument_list|)
expr_stmt|;
name|ATF_CHECK_EQ
argument_list|(
literal|440
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|mbr_sector
argument_list|,
name|mbr_dsn
argument_list|)
argument_list|)
expr_stmt|;
name|ATF_CHECK_EQ
argument_list|(
literal|446
argument_list|,
name|MBR_PART_OFFSET
argument_list|)
expr_stmt|;
name|ATF_CHECK_EQ
argument_list|(
name|MBR_PART_OFFSET
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|mbr_sector
argument_list|,
name|mbr_parts
argument_list|)
argument_list|)
expr_stmt|;
name|ATF_CHECK_EQ
argument_list|(
literal|510
argument_list|,
name|MBR_MAGIC_OFFSET
argument_list|)
expr_stmt|;
name|ATF_CHECK_EQ
argument_list|(
name|MBR_MAGIC_OFFSET
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|mbr_sector
argument_list|,
name|mbr_magic
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|mbr_partition
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|mbr_partition
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|ATF_CHECK_EQ
argument_list|(
literal|16
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|mbr_partition
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|mbr_sector
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|mbr_partition
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

