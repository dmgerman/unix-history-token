begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * CAM ioctl compatibility shims  *  * Copyright (c) 2013 Scott Long  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_COMPAT_H
end_define

begin_function_decl
name|int
name|cam_compat_ioctl
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|u_long
modifier|*
name|cmd
parameter_list|,
name|caddr_t
modifier|*
name|addr
parameter_list|,
name|int
modifier|*
name|flag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Version 0x16 compatibility */
end_comment

begin_define
define|#
directive|define
name|CAM_VERSION_0x16
value|0x16
end_define

begin_comment
comment|/* The size of the union ccb didn't change when going to 0x17 */
end_comment

begin_define
define|#
directive|define
name|CAMIOCOMMAND_0x16
value|_IOWR(CAM_VERSION_0x16, 2, union ccb)
end_define

begin_define
define|#
directive|define
name|CAMGETPASSTHRU_0x16
value|_IOWR(CAM_VERSION_0x16, 3, union ccb)
end_define

begin_define
define|#
directive|define
name|CAM_SCATTER_VALID_0x16
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CAM_SG_LIST_PHYS_0x16
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CAM_DATA_PHYS_0x16
value|0x00200000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

