begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007-2009 Google Inc. and Amit Singh  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *   * * Redistributions of source code must retain the above copyright  *   notice, this list of conditions and the following disclaimer.  * * Redistributions in binary form must reproduce the above  *   copyright notice, this list of conditions and the following disclaimer  *   in the documentation and/or other materials provided with the  *   distribution.  * * Neither the name of Google Inc. nor the names of its  *   contributors may be used to endorse or promote products derived from  *   this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FUSE_PARAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_FUSE_PARAM_H_
end_define

begin_comment
comment|/*  * This is the prefix ("fuse" by default) of the name of a FUSE device node  * in devfs. The suffix is the device number. "/dev/fuse0" is the first FUSE  * device by default. If you change the prefix from the default to something  * else, the user-space FUSE library will need to know about it too.  */
end_comment

begin_define
define|#
directive|define
name|FUSE_DEVICE_BASENAME
value|"fuse"
end_define

begin_comment
comment|/*  * This is the number of /dev/fuse<n> nodes we will create.<n> goes from  * 0 to (FUSE_NDEVICES - 1).  */
end_comment

begin_define
define|#
directive|define
name|FUSE_NDEVICES
value|16
end_define

begin_comment
comment|/*  * This is the default block size of the virtual storage devices that are  * implicitly implemented by the FUSE kernel extension. This can be changed  * on a per-mount basis (there's one such virtual device for each mount).  */
end_comment

begin_define
define|#
directive|define
name|FUSE_DEFAULT_BLOCKSIZE
value|4096
end_define

begin_comment
comment|/*  * This is default I/O size used while accessing the virtual storage devices.  * This can be changed on a per-mount basis.  */
end_comment

begin_define
define|#
directive|define
name|FUSE_DEFAULT_IOSIZE
value|4096
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * This is the soft upper limit on the number of "request tickets" FUSE's  * user-kernel IPC layer can have for a given mount. This can be modified  * through the fuse.* sysctl interface.  */
end_comment

begin_define
define|#
directive|define
name|FUSE_DEFAULT_MAX_FREE_TICKETS
value|1024
end_define

begin_define
define|#
directive|define
name|FUSE_DEFAULT_IOV_PERMANENT_BUFSIZE
value|(1L<< 19)
end_define

begin_define
define|#
directive|define
name|FUSE_DEFAULT_IOV_CREDIT
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FUSE_LINK_MAX
value|LINK_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FUSE_PARAM_H_ */
end_comment

end_unit

