begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)volhdr.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * vohldr.h: volume header for "LIF" format volumes  */
end_comment

begin_struct
struct|struct
name|lifvol
block|{
name|short
name|vol_id
decl_stmt|;
name|char
name|vol_label
index|[
literal|6
index|]
decl_stmt|;
name|int
name|vol_addr
decl_stmt|;
name|short
name|vol_oct
decl_stmt|;
name|short
name|vol_dummy
decl_stmt|;
name|int
name|vol_dirsize
decl_stmt|;
name|short
name|vol_version
decl_stmt|;
name|short
name|vol_zero
decl_stmt|;
name|int
name|vol_huh1
decl_stmt|;
name|int
name|vol_huh2
decl_stmt|;
name|int
name|vol_length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lifdir
block|{
name|char
name|dir_name
index|[
literal|10
index|]
decl_stmt|;
name|short
name|dir_type
decl_stmt|;
name|int
name|dir_addr
decl_stmt|;
name|int
name|dir_length
decl_stmt|;
name|char
name|dir_toc
index|[
literal|6
index|]
decl_stmt|;
name|short
name|dir_flag
decl_stmt|;
name|int
name|dir_exec
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* load header for boot rom */
end_comment

begin_struct
struct|struct
name|load
block|{
name|int
name|address
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VOL_ID
value|-32768
end_define

begin_define
define|#
directive|define
name|VOL_OCT
value|4096
end_define

begin_define
define|#
directive|define
name|DIR_TYPE
value|-5822
end_define

begin_define
define|#
directive|define
name|DIR_FLAG
value|0x8001
end_define

begin_comment
comment|/* dont ask me! */
end_comment

begin_define
define|#
directive|define
name|SECTSIZE
value|256
end_define

end_unit

