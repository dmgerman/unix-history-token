begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998  *      Nick Hibma<n_hibma@freebsd.org>. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY NICK HIBMA AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  *      $Id$  */
end_comment

begin_comment
comment|/* Macro's to cope with the differences between NetBSD and FreeBSD  */
end_comment

begin_comment
comment|/*  * NetBSD  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_usbverbose.h"
end_include

begin_define
define|#
directive|define
name|DEVICE_NAME
parameter_list|(
name|bdev
parameter_list|)
define|\
value|printf("%s: ", (bdev).dv_xname)
end_define

begin_typedef
typedef|typedef
name|struct
name|device
name|bdevice
typedef|;
end_typedef

begin_comment
comment|/* base device */
end_comment

begin_comment
comment|/*  * FreeBSD  *  */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"opt_usb.h"
end_include

begin_define
define|#
directive|define
name|DEVICE_NAME
parameter_list|(
name|bdev
parameter_list|)
define|\
value|printf("%s%d: ",	\ 			device_get_name(bdev), device_get_unit(bdev))
end_define

begin_comment
comment|/* XXX Change this when FreeBSD has memset  */
end_comment

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|do{			\ 		if ((v) == 0)		\ 			bzero((d), (s));	\ 		else			\ 			panic("Non zero filler for memset, cannot handle!"); \ 		} while (0)
end_define

begin_comment
comment|/* XXX can't we put this somehow into a typedef? */
end_comment

begin_define
define|#
directive|define
name|bdevice
value|device_t
end_define

begin_comment
comment|/* base device */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * General  *  */
end_comment

begin_define
define|#
directive|define
name|DEVICE_MSG
parameter_list|(
name|bdev
parameter_list|,
name|s
parameter_list|)
value|(DEVICE_NAME(bdev), printf s)
end_define

begin_define
define|#
directive|define
name|DEVICE_ERROR
parameter_list|(
name|bdev
parameter_list|,
name|s
parameter_list|)
value|DEVICE_MSG(bdev, s)
end_define

begin_comment
comment|/* Returns from attach for NetBSD vs. FreeBSD  */
end_comment

begin_comment
comment|/* Error returns */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATTACH_ERROR_RETURN
value|return
end_define

begin_define
define|#
directive|define
name|ATTACH_SUCCESS_RETURN
value|return
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ATTACH_ERROR_RETURN
value|return ENXIO
end_define

begin_define
define|#
directive|define
name|ATTACH_SUCCESS_RETURN
value|return 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The debugging subsystem  */
end_comment

begin_comment
comment|/* XXX to be filled in  */
end_comment

end_unit

