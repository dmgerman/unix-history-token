begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 by Coleman Kane<cokane@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Gardner Buchanan.  * 4. The name of Gardner Buchanan may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* FIXME: There are IOCTLS to merge in here, see drm.h*/
end_comment

begin_comment
comment|/* Query IOCTLs */
end_comment

begin_comment
comment|/* XFree86 4.1.x DRI support */
end_comment

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_VERSION
value|0x6400
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_GET_UNIQUE
value|0x6401
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_GET_MAGIC
value|0x6402
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_IRQ_BUSID
value|0x6403
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_GET_MAP
value|0x6404
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_GET_CLIENT
value|0x6405
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_GET_STATS
value|0x6406
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_SET_UNIQUE
value|0x6410
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_AUTH_MAGIC
value|0x6411
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_BLOCK
value|0x6412
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_UNBLOCK
value|0x6413
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_CONTROL
value|0x6414
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_ADD_MAP
value|0x6415
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_ADD_BUFS
value|0x6416
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MARK_BUFS
value|0x6417
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_INFO_BUFS
value|0x6418
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MAP_BUFS
value|0x6419
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_FREE_BUFS
value|0x641a
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RM_MAP
value|0x641b
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_SET_SAREA_CTX
value|0x641c
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_GET_SAREA_CTX
value|0x641d
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_ADD_CTX
value|0x6420
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RM_CTX
value|0x6421
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MOD_CTX
value|0x6422
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_GET_CTX
value|0x6423
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_SWITCH_CTX
value|0x6424
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_NEW_CTX
value|0x6425
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RES_CTX
value|0x6426
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_ADD_DRAW
value|0x6427
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RM_DRAW
value|0x6428
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_DMA
value|0x6429
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_LOCK
value|0x642a
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_UNLOCK
value|0x642b
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_FINISH
value|0x642c
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_AGP_ACQUIRE
value|0x6430
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_AGP_RELEASE
value|0x6431
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_AGP_ENABLE
value|0x6432
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_AGP_INFO
value|0x6433
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_AGP_ALLOC
value|0x6434
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_AGP_FREE
value|0x6435
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_AGP_BIND
value|0x6436
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_AGP_UNBIND
value|0x6437
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_SG_ALLOC
value|0x6438
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_SG_FREE
value|0x6439
end_define

begin_comment
comment|/* MGA specific ioctls */
end_comment

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MGA_INIT
value|0x6440
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MGA_FLUSH
value|0x6441
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MGA_RESET
value|0x6442
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MGA_SWAP
value|0x6443
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MGA_CLEAR
value|0x6444
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MGA_VERTEX
value|0x6445
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MGA_INDICES
value|0x6446
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MGA_ILOAD
value|0x6447
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_MGA_BLIT
value|0x6448
end_define

begin_comment
comment|/* i810 specific ioctls */
end_comment

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_I810_INIT
value|0x6440
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_I810_VERTEX
value|0x6441
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_I810_CLEAR
value|0x6442
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_I810_FLUSH
value|0x6443
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_I810_GETAGE
value|0x6444
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_I810_GETBUF
value|0x6445
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_I810_SWAP
value|0x6446
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_I810_COPY
value|0x6447
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_I810_DOCOPY
value|0x6448
end_define

begin_comment
comment|/* Rage 128 specific ioctls */
end_comment

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_INIT
value|0x6440
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_CCE_START
value|0x6441
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_CCE_STOP
value|0x6442
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_CCE_RESET
value|0x6443
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_CCE_IDLE
value|0x6444
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_RESET
value|0x6446
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_SWAP
value|0x6447
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_CLEAR
value|0x6448
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_VERTEX
value|0x6449
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_INDICES
value|0x644a
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_BLIT
value|0x644b
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_DEPTH
value|0x644c
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_STIPPLE
value|0x644d
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_INDIRECT
value|0x644f
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_R128_FULLSCREEN
value|0x6450
end_define

begin_comment
comment|/* Radeon specific ioctls */
end_comment

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_CP_INIT
value|0x6440
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_CP_START
value|0x6441
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_CP_STOP
value|0x6442
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_CP_RESET
value|0x6443
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_CP_IDLE
value|0x6444
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_RESET
value|0x6445
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_FULLSCREEN
value|0x6446
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_SWAP
value|0x6447
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_CLEAR
value|0x6448
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_VERTEX
value|0x6449
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_INDICES
value|0x644a
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_STIPPLE
value|0x644c
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_INDIRECT
value|0x644d
end_define

begin_define
define|#
directive|define
name|LINUX_DRM_IOCTL_RADEON_TEXTURE
value|0x644e
end_define

begin_comment
comment|/* card specific ioctls may increase the DRM_MAX */
end_comment

begin_define
define|#
directive|define
name|LINUX_IOCTL_DRM_MIN
value|LINUX_DRM_IOCTL_VERSION
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_DRM_MAX
value|LINUX_DRM_IOCTL_R128_FULLSCREEN
end_define

end_unit

