begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Poul-Henning Kamp  * Copyright (c) 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by Poul-Henning Kamp  * and NAI Labs, the Security Research Division of Network Associates, Inc.  * under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the  * DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/sbuf.h>
end_include

begin_include
include|#
directive|include
file|<geom/geom.h>
end_include

begin_function
name|int
name|thread_sim
parameter_list|(
name|void
modifier|*
name|ptr
name|__unused
parameter_list|)
block|{
name|rattle
argument_list|()
expr_stmt|;
name|g_simdisk_init
argument_list|()
expr_stmt|;
name|g_bsd_init
argument_list|()
expr_stmt|;
name|g_mbr_init
argument_list|()
expr_stmt|;
name|g_mbrext_init
argument_list|()
expr_stmt|;
name|g_dev_init
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|rattle
argument_list|()
expr_stmt|;
name|g_simdisk_xml_load
argument_list|(
literal|"da0"
argument_list|,
literal|"../../Data/disk.beast.da0.xml"
argument_list|)
expr_stmt|;
name|g_simdisk_xml_load
argument_list|(
literal|"da1"
argument_list|,
literal|"../../Data/disk.alpha.da0.xml"
argument_list|)
expr_stmt|;
name|g_simdisk_xml_load
argument_list|(
literal|"da2"
argument_list|,
literal|"../../Data/disk.alpha2.da0.xml"
argument_list|)
expr_stmt|;
name|rattle
argument_list|()
expr_stmt|;
name|conff
argument_list|(
literal|"1"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Done\n"
argument_list|)
expr_stmt|;
name|done
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

