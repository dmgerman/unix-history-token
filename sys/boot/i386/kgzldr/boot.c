begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Global Technology Associates, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/inflate.h>
end_include

begin_include
include|#
directive|include
file|"kgzldr.h"
end_include

begin_define
define|#
directive|define
name|KGZ_HEAD
value|0xa
end_define

begin_comment
comment|/* leading bytes to ignore */
end_comment

begin_define
define|#
directive|define
name|KGZ_TAIL
value|0x8
end_define

begin_comment
comment|/* trailing bytes to ignore */
end_comment

begin_define
define|#
directive|define
name|E_FMT
value|1
end_define

begin_comment
comment|/* Error: Invalid format */
end_comment

begin_define
define|#
directive|define
name|E_MEM
value|2
end_define

begin_comment
comment|/* Error: Out of memory */
end_comment

begin_struct
struct|struct
name|kgz_hdr
block|{
name|char
name|ident
index|[
literal|4
index|]
decl_stmt|;
comment|/* identification */
name|uint32_t
name|dload
decl_stmt|;
comment|/* decoded image load address */
name|uint32_t
name|dsize
decl_stmt|;
comment|/* decoded image size */
name|uint32_t
name|isize
decl_stmt|;
comment|/* image size in memory */
name|uint32_t
name|entry
decl_stmt|;
comment|/* program entry point */
name|uint32_t
name|nsize
decl_stmt|;
comment|/* encoded image size */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|kgz_hdr
name|kgz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* header */
end_comment

begin_decl_stmt
specifier|extern
name|uint8_t
name|kgz_ndata
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* encoded image */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|msg
index|[]
init|=
block|{
literal|"done"
block|,
literal|"invalid format"
block|,
literal|"out of memory"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|u_char
modifier|*
name|ip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input pointer */
end_comment

begin_decl_stmt
specifier|static
name|u_char
modifier|*
name|op
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output pointer */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|inflate
name|infl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inflate() parameters */
end_comment

begin_function_decl
specifier|static
name|int
name|decode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|input
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|output
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Uncompress and boot a kernel.  */
end_comment

begin_function
name|int
name|boot
parameter_list|(
name|int
name|howto
parameter_list|)
block|{
name|int
name|err
decl_stmt|;
name|kgz_con
operator|=
name|howto
operator|&
name|RB_SERIAL
condition|?
name|KGZ_SIO
else|:
name|KGZ_CRT
expr_stmt|;
name|putstr
argument_list|(
literal|"Uncompressing ... "
argument_list|)
expr_stmt|;
name|err
operator|=
name|decode
argument_list|()
expr_stmt|;
name|putstr
argument_list|(
name|msg
index|[
name|err
index|]
argument_list|)
expr_stmt|;
name|putstr
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|putstr
argument_list|(
literal|"System halted"
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
empty_stmt|;
block|}
return|return
name|err
return|;
block|}
end_function

begin_comment
comment|/*  * Interface with inflate() to uncompress the data.  */
end_comment

begin_function
specifier|static
name|int
name|decode
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|u_char
name|slide
index|[
name|GZ_WSIZE
index|]
decl_stmt|;
name|int
name|err
decl_stmt|;
name|ip
operator|=
name|kgz_ndata
operator|+
name|KGZ_HEAD
expr_stmt|;
name|op
operator|=
operator|(
name|u_char
operator|*
operator|)
name|kgz
operator|.
name|dload
expr_stmt|;
name|infl
operator|.
name|gz_input
operator|=
name|input
expr_stmt|;
name|infl
operator|.
name|gz_output
operator|=
name|output
expr_stmt|;
name|infl
operator|.
name|gz_slide
operator|=
name|slide
expr_stmt|;
name|err
operator|=
name|inflate
argument_list|(
operator|&
name|infl
argument_list|)
expr_stmt|;
return|return
name|err
condition|?
name|err
operator|==
literal|3
condition|?
name|E_MEM
else|:
name|E_FMT
else|:
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Read a byte.  */
end_comment

begin_function
specifier|static
name|int
name|input
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
if|if
condition|(
call|(
name|size_t
call|)
argument_list|(
name|ip
operator|-
name|kgz_ndata
argument_list|)
operator|+
name|KGZ_TAIL
operator|>
name|kgz
operator|.
name|nsize
condition|)
return|return
name|GZ_EOF
return|;
return|return
operator|*
name|ip
operator|++
return|;
block|}
end_function

begin_comment
comment|/*  * Write some bytes.  */
end_comment

begin_function
specifier|static
name|int
name|output
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|,
name|u_char
modifier|*
name|ptr
parameter_list|,
name|u_long
name|len
parameter_list|)
block|{
if|if
condition|(
name|op
operator|-
operator|(
name|u_char
operator|*
operator|)
name|kgz
operator|.
name|dload
operator|+
name|len
operator|>
name|kgz
operator|.
name|dsize
condition|)
return|return
operator|-
literal|1
return|;
while|while
condition|(
name|len
operator|--
condition|)
operator|*
name|op
operator|++
operator|=
operator|*
name|ptr
operator|++
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

