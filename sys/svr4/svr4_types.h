begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_TYPES_H_
end_define

begin_typedef
typedef|typedef
name|u_quad_t
name|svr4_ino64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|quad_t
name|svr4_off64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|quad_t
name|svr4_blkcnt64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_quad_t
name|svr4_fsblkcnt64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|svr4_off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|svr4_dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|svr4_ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|svr4_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|svr4_nlink_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|svr4_uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|svr4_gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|svr4_daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|svr4_pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|svr4_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|svr4_blkcnt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|svr4_fsblkcnt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|svr4_caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|svr4_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|svr4_o_dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|svr4_o_pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|svr4_o_ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|svr4_o_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|svr4_o_nlink_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|svr4_o_uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|svr4_o_gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|svr4_clock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|svr4_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|timespec
name|svr4_timestruc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|svr4_omajor
parameter_list|(
name|x
parameter_list|)
value|((int32_t)((((x)& 0x7f00)>> 8)))
end_define

begin_define
define|#
directive|define
name|svr4_ominor
parameter_list|(
name|x
parameter_list|)
value|((int32_t)((((x)& 0x00ff)>> 0)))
end_define

begin_define
define|#
directive|define
name|svr4_omakedev
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((svr4_o_dev_t)((((x)<< 8)& 0x7f00) | \ 					      (((y)<< 0)& 0x00ff)))
end_define

begin_define
define|#
directive|define
name|svr4_to_bsd_odev_t
parameter_list|(
name|d
parameter_list|)
value|makedev(svr4_omajor(d), svr4_ominor(d))
end_define

begin_define
define|#
directive|define
name|bsd_to_svr4_odev_t
parameter_list|(
name|d
parameter_list|)
value|svr4_omakedev(umajor(d), uminor(d))
end_define

begin_define
define|#
directive|define
name|svr4_major
parameter_list|(
name|x
parameter_list|)
value|((int32_t)((((x)& 0xfffc0000)>> 18)))
end_define

begin_define
define|#
directive|define
name|svr4_minor
parameter_list|(
name|x
parameter_list|)
value|((int32_t)((((x)& 0x0003ffff)>> 0)))
end_define

begin_define
define|#
directive|define
name|svr4_makedev
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((svr4_dev_t)((((x)<< 18)& 0xfffc0000) | \ 					    (((y)<< 0)& 0x0003ffff)))
end_define

begin_define
define|#
directive|define
name|svr4_to_bsd_dev_t
parameter_list|(
name|d
parameter_list|)
value|makedev(svr4_major(d), svr4_minor(d))
end_define

begin_define
define|#
directive|define
name|bsd_to_svr4_dev_t
parameter_list|(
name|d
parameter_list|)
value|svr4_makedev(umajor(d), uminor(d))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_TYPES_H_ */
end_comment

end_unit

