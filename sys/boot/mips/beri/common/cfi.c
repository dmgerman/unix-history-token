begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_include
include|#
directive|include
file|"mips.h"
end_include

begin_include
include|#
directive|include
file|"cfi.h"
end_include

begin_comment
comment|/*  * Memory-mapped Intel StrataFlash mini-driver.  Very mini.  Nothing fancy --  * and few seatbelts.  *  * XXXRW: Should we be making some effort to reset isf to a known-good state  * before starting, in case there was a soft reset mid-transaction.  *  * XXXRW: Would be nice to support multiple devices and also handle SD cards  * here ... and probably not too hard.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|__cheri_flash_bootfs_vaddr__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|__cheri_flash_bootfs_len__
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CHERI_BOOTFS_BASE
value|((uintptr_t)&__cheri_flash_bootfs_vaddr__)
end_define

begin_define
define|#
directive|define
name|CHERI_BOOTFS_LENGTH
value|((uintptr_t)&__cheri_flash_bootfs_len__)
end_define

begin_function
name|int
name|cfi_read
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|lba
parameter_list|,
name|unsigned
name|nblk
parameter_list|)
block|{
if|if
condition|(
operator|(
name|lba
operator|<<
literal|9
operator|)
operator|+
operator|(
name|nblk
operator|<<
literal|9
operator|)
operator|>
name|CHERI_BOOTFS_LENGTH
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|memcpy
argument_list|(
name|buf
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
name|CHERI_BOOTFS_BASE
operator|+
operator|(
name|lba
operator|<<
literal|9
operator|)
operator|)
argument_list|,
name|nblk
operator|<<
literal|9
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|cfi_get_mediasize
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|CHERI_BOOTFS_LENGTH
operator|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|cfi_get_sectorsize
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
literal|512
operator|)
return|;
comment|/* Always a good sector size. */
block|}
end_function

end_unit

