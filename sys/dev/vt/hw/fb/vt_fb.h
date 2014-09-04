begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Aleksandr Rybalko under sponsorship from the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_VT_HW_FB_VT_FB_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_VT_HW_FB_VT_FB_H_
end_define

begin_comment
comment|/* Generic framebuffer interface call vt_fb_attach to init VT(9) */
end_comment

begin_function_decl
name|int
name|vt_fb_attach
parameter_list|(
name|struct
name|fb_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_fb_resume
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_fb_suspend
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|vd_init_t
name|vt_fb_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vd_blank_t
name|vt_fb_blank
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vd_bitbltchr_t
name|vt_fb_bitbltchr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vd_maskbitbltchr_t
name|vt_fb_maskbitbltchr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vd_postswitch_t
name|vt_fb_postswitch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vd_fb_ioctl_t
name|vt_fb_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vd_fb_mmap_t
name|vt_fb_mmap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_VT_HW_FB_VT_FB_H_ */
end_comment

end_unit

