begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 David E. O'Brien  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_FREEBSD32_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_FREEBSD32_IOCTL_H_
end_define

begin_typedef
typedef|typedef
name|__uint32_t
name|caddr_t32
typedef|;
end_typedef

begin_struct
struct|struct
name|ioc_toc_header32
block|{
name|u_short
name|len
decl_stmt|;
name|u_char
name|starting_track
decl_stmt|;
name|u_char
name|ending_track
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ioc_read_toc_entry32
block|{
name|u_char
name|address_format
decl_stmt|;
name|u_char
name|starting_track
decl_stmt|;
name|u_short
name|data_len
decl_stmt|;
name|uint32_t
name|data
decl_stmt|;
comment|/* struct cd_toc_entry* */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MDNPAD32
value|MDNPAD - 1
end_define

begin_struct
struct|struct
name|md_ioctl32
block|{
name|unsigned
name|md_version
decl_stmt|;
comment|/* Structure layout version */
name|unsigned
name|md_unit
decl_stmt|;
comment|/* unit number */
name|enum
name|md_types
name|md_type
decl_stmt|;
comment|/* type of disk */
name|caddr_t32
name|md_file
decl_stmt|;
comment|/* pathname of file to mount */
name|off_t
name|md_mediasize
decl_stmt|;
comment|/* size of disk in bytes */
name|unsigned
name|md_sectorsize
decl_stmt|;
comment|/* sectorsize */
name|unsigned
name|md_options
decl_stmt|;
comment|/* options */
name|u_int64_t
name|md_base
decl_stmt|;
comment|/* base address */
name|int
name|md_fwheads
decl_stmt|;
comment|/* firmware heads */
name|int
name|md_fwsectors
decl_stmt|;
comment|/* firmware sectors */
name|int
name|md_pad
index|[
name|MDNPAD32
index|]
decl_stmt|;
comment|/* padding for future ideas */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fiodgname_arg32
block|{
name|int
name|len
decl_stmt|;
name|caddr_t32
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDIOREADTOCENTRYS_32
value|_IOWR('c', 5, struct ioc_read_toc_entry32)
end_define

begin_define
define|#
directive|define
name|CDIOREADTOCHEADER_32
value|_IOR('c', 4, struct ioc_toc_header32)
end_define

begin_define
define|#
directive|define
name|MDIOCATTACH_32
value|_IOC(IOC_INOUT, 'm', 0, sizeof(struct md_ioctl32) + 4)
end_define

begin_define
define|#
directive|define
name|MDIOCDETACH_32
value|_IOC(IOC_INOUT, 'm', 1, sizeof(struct md_ioctl32) + 4)
end_define

begin_define
define|#
directive|define
name|MDIOCQUERY_32
value|_IOC(IOC_INOUT, 'm', 2, sizeof(struct md_ioctl32) + 4)
end_define

begin_define
define|#
directive|define
name|MDIOCLIST_32
value|_IOC(IOC_INOUT, 'm', 3, sizeof(struct md_ioctl32) + 4)
end_define

begin_define
define|#
directive|define
name|FIODGNAME_32
value|_IOW('f', 120, struct fiodgname_arg32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMPAT_FREEBSD32_IOCTL_H_ */
end_comment

end_unit

