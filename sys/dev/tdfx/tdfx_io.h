begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2001 by Coleman Kane<cokane@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Gardner Buchanan.  * 4. The name of Gardner Buchanan may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *   $FreeBSD$  */
end_comment

begin_comment
comment|/* This code originally came from<shocking@prth.pgs.com>  * it is basically a derivative of some sys/dhio.h file to work with the 3dfx  * cards   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TDFX_IO_H
end_ifndef

begin_define
define|#
directive|define
name|TDFX_IO_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * define an ioctl here  */
end_comment

begin_define
define|#
directive|define
name|DHIOCRESET
value|_IO('D', 0)
end_define

begin_comment
comment|/* reset the voodoo device */
end_comment

begin_define
define|#
directive|define
name|GETVOODOO
value|0x3302
end_define

begin_define
define|#
directive|define
name|SETVOODOO
value|0x3303
end_define

begin_define
define|#
directive|define
name|MOREVOODOO
value|0x3300
end_define

begin_define
define|#
directive|define
name|_IOC_NRBITS
value|8
end_define

begin_define
define|#
directive|define
name|_IOC_TYPEBITS
value|8
end_define

begin_define
define|#
directive|define
name|_IOC_SIZEBITS
value|14
end_define

begin_define
define|#
directive|define
name|_IOC_DIRBITS
value|2
end_define

begin_define
define|#
directive|define
name|_IOC_NRMASK
value|((1<< _IOC_NRBITS)-1)
end_define

begin_define
define|#
directive|define
name|_IOC_TYPEMASK
value|((1<< _IOC_TYPEBITS)-1)
end_define

begin_define
define|#
directive|define
name|_IOC_SIZEMASK
value|((1<< _IOC_SIZEBITS)-1)
end_define

begin_define
define|#
directive|define
name|_IOC_DIRMASK
value|((1<< _IOC_DIRBITS)-1)
end_define

begin_define
define|#
directive|define
name|_IOC_NRSHIFT
value|0
end_define

begin_define
define|#
directive|define
name|_IOC_TYPESHIFT
value|(_IOC_NRSHIFT+_IOC_NRBITS)
end_define

begin_define
define|#
directive|define
name|_IOC_SIZESHIFT
value|(_IOC_TYPESHIFT+_IOC_TYPEBITS)
end_define

begin_define
define|#
directive|define
name|_IOC_DIRSHIFT
value|(_IOC_SIZESHIFT+_IOC_SIZEBITS)
end_define

begin_comment
comment|/*  * Direction bits.  */
end_comment

begin_define
define|#
directive|define
name|_IOC_NONE
value|0U
end_define

begin_define
define|#
directive|define
name|_IOC_WRITE
value|1U
end_define

begin_define
define|#
directive|define
name|_IOC_READ
value|2U
end_define

begin_define
define|#
directive|define
name|_IOCV
parameter_list|(
name|dir
parameter_list|,
name|type
parameter_list|,
name|nr
parameter_list|,
name|size
parameter_list|)
define|\
value|(((dir)<< _IOC_DIRSHIFT) | \ 	 ((type)<< _IOC_TYPESHIFT) | \ 	 ((nr)<< _IOC_NRSHIFT) | \ 	 ((size)<< _IOC_SIZESHIFT))
end_define

begin_comment
comment|/* used to create numbers */
end_comment

begin_define
define|#
directive|define
name|_IOV
parameter_list|(
name|type
parameter_list|,
name|nr
parameter_list|)
value|_IOCV(_IOC_NONE,(type),(nr),0)
end_define

begin_define
define|#
directive|define
name|_IORV
parameter_list|(
name|type
parameter_list|,
name|nr
parameter_list|,
name|size
parameter_list|)
value|_IOCV(_IOC_READ,(type),(nr),sizeof(size))
end_define

begin_define
define|#
directive|define
name|_IOWV
parameter_list|(
name|type
parameter_list|,
name|nr
parameter_list|,
name|size
parameter_list|)
value|_IOCV(_IOC_WRITE,(type),(nr),sizeof(size))
end_define

begin_define
define|#
directive|define
name|_IOWRV
parameter_list|(
name|type
parameter_list|,
name|nr
parameter_list|,
name|size
parameter_list|)
value|_IOCV(_IOC_READ|_IOC_WRITE,(type),(nr),sizeof(size))
end_define

begin_comment
comment|/* used to decode ioctl numbers.. */
end_comment

begin_define
define|#
directive|define
name|_IOC_DIR
parameter_list|(
name|nr
parameter_list|)
value|(((nr)>> _IOC_DIRSHIFT)& _IOC_DIRMASK)
end_define

begin_define
define|#
directive|define
name|_IOC_TYPE
parameter_list|(
name|nr
parameter_list|)
value|(((nr)>> _IOC_TYPESHIFT)& _IOC_TYPEMASK)
end_define

begin_define
define|#
directive|define
name|_IOC_NR
parameter_list|(
name|nr
parameter_list|)
value|(((nr)>> _IOC_NRSHIFT)& _IOC_NRMASK)
end_define

begin_define
define|#
directive|define
name|_IOC_SIZE
parameter_list|(
name|nr
parameter_list|)
value|(((nr)>> _IOC_SIZESHIFT)& _IOC_SIZEMASK)
end_define

begin_comment
comment|/* ...and for the drivers/sound files... */
end_comment

begin_define
define|#
directive|define
name|IOCV_IN
value|(_IOC_WRITE<< _IOC_DIRSHIFT)
end_define

begin_define
define|#
directive|define
name|IOCV_OUT
value|(_IOC_READ<< _IOC_DIRSHIFT)
end_define

begin_define
define|#
directive|define
name|IOCV_INOUT
value|((_IOC_WRITE|_IOC_READ)<< _IOC_DIRSHIFT)
end_define

begin_define
define|#
directive|define
name|IOCSIZE_MASK
value|(_IOC_SIZEMASK<< _IOC_SIZESHIFT)
end_define

begin_define
define|#
directive|define
name|IOCSIZE_SHIFT
value|(_IOC_SIZESHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

