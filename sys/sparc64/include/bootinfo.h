begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1994 by Rodney W. Grimes, Milwaukie, Oregon  97222  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Rodney W. Grimes.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY RODNEY W. GRIMES ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL RODNEY W. GRIMES BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/i386/include/bootinfo.h,v 1.14 1999/12/29  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BOOTINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BOOTINFO_H_
end_define

begin_comment
comment|/*  * Increment the version number when you break binary compatibiity.  */
end_comment

begin_define
define|#
directive|define
name|BOOTINFO_VERSION
value|1
end_define

begin_struct
struct|struct
name|bootinfo
block|{
name|u_int
name|bi_version
decl_stmt|;
comment|/* Version number of this structure. */
name|u_int
name|bi_howto
decl_stmt|;
comment|/* How to boot. */
name|u_long
name|bi_end
decl_stmt|;
comment|/* End of kernel space. */
name|u_long
name|bi_kpa
decl_stmt|;
comment|/* Physical address of start of kernel. */
name|u_long
name|bi_metadata
decl_stmt|;
comment|/* Preload modules. */
name|u_long
name|bi_envp
decl_stmt|;
comment|/* Kernel environment. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_BOOTINFO_H_ */
end_comment

end_unit

