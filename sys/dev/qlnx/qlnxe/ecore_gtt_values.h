begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PREVENT_PXP_GLOBAL_WIN__
end_ifndef

begin_decl_stmt
specifier|static
name|u32
name|pxp_global_win
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0x1c02
block|,
comment|/* win 2: addr=0x1c02000, size=4096 bytes */
literal|0x1c80
block|,
comment|/* win 3: addr=0x1c80000, size=4096 bytes */
literal|0x1d00
block|,
comment|/* win 4: addr=0x1d00000, size=4096 bytes */
literal|0x1d01
block|,
comment|/* win 5: addr=0x1d01000, size=4096 bytes */
literal|0x1d80
block|,
comment|/* win 6: addr=0x1d80000, size=4096 bytes */
literal|0x1d81
block|,
comment|/* win 7: addr=0x1d81000, size=4096 bytes */
literal|0x1d82
block|,
comment|/* win 8: addr=0x1d82000, size=4096 bytes */
literal|0x1e00
block|,
comment|/* win 9: addr=0x1e00000, size=4096 bytes */
literal|0x1e80
block|,
comment|/* win 10: addr=0x1e80000, size=4096 bytes */
literal|0x1f00
block|,
comment|/* win 11: addr=0x1f00000, size=4096 bytes */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PREVENT_PXP_GLOBAL_WIN__ */
end_comment

end_unit

