begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<geom/geom_disk.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_function
name|void
name|sparc64_ad_firmware_geom_adjust
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|disk
modifier|*
name|disk
parameter_list|)
block|{
comment|/* 	 * The Sun disk label only uses 16-bit fields for cylinders, 	 * heads and sectors so the geometry of large IDE disks has 	 * to be adjusted.  If the disk is> 32GB at 16 heads and 63 	 * sectors, the sectors have to be adjusted to 255.  If the 	 * the disk is even> 128GB, additionally adjust the heads 	 * to 255. 	 * XXX the OpenSolaris dad(7D) driver limits the mediasize 	 * to 128GB. 	 */
if|if
condition|(
name|disk
operator|->
name|d_mediasize
operator|>
operator|(
name|off_t
operator|)
literal|65535
operator|*
literal|16
operator|*
literal|63
operator|*
name|disk
operator|->
name|d_sectorsize
condition|)
name|disk
operator|->
name|d_fwsectors
operator|=
literal|255
expr_stmt|;
if|if
condition|(
name|disk
operator|->
name|d_mediasize
operator|>
operator|(
name|off_t
operator|)
literal|65535
operator|*
literal|16
operator|*
literal|255
operator|*
name|disk
operator|->
name|d_sectorsize
condition|)
name|disk
operator|->
name|d_fwheads
operator|=
literal|255
expr_stmt|;
block|}
end_function

end_unit

