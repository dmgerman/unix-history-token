begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)ioccom.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IOCCOM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IOCCOM_H_
end_define

begin_comment
comment|/*  * Ioctl's have the command encoded in the lower word, and the size of  * any in or out parameters in the upper word.  The high 3 bits of the  * upper word are used to encode the in/out status of the parameter.  */
end_comment

begin_define
define|#
directive|define
name|IOCPARM_MASK
value|0x1fff
end_define

begin_comment
comment|/* parameter length, at most 13 bits */
end_comment

begin_define
define|#
directive|define
name|IOCPARM_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& IOCPARM_MASK)
end_define

begin_define
define|#
directive|define
name|IOCBASECMD
parameter_list|(
name|x
parameter_list|)
value|((x)& ~(IOCPARM_MASK<< 16))
end_define

begin_define
define|#
directive|define
name|IOCGROUP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|IOCPARM_MAX
value|NBPG
end_define

begin_comment
comment|/* max size of ioctl, mult. of NBPG */
end_comment

begin_define
define|#
directive|define
name|IOC_VOID
value|0x20000000
end_define

begin_comment
comment|/* no parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_OUT
value|0x40000000
end_define

begin_comment
comment|/* copy out parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_IN
value|0x80000000
end_define

begin_comment
comment|/* copy in parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_INOUT
value|(IOC_IN|IOC_OUT)
end_define

begin_define
define|#
directive|define
name|IOC_DIRMASK
value|0xe0000000
end_define

begin_comment
comment|/* mask for IN/OUT/VOID */
end_comment

begin_define
define|#
directive|define
name|_IOC
parameter_list|(
name|inout
parameter_list|,
name|group
parameter_list|,
name|num
parameter_list|,
name|len
parameter_list|)
define|\
value|(inout | ((len& IOCPARM_MASK)<< 16) | ((group)<< 8) | (num))
end_define

begin_define
define|#
directive|define
name|_IO
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|)
value|_IOC(IOC_VOID,	(g), (n), 0)
end_define

begin_define
define|#
directive|define
name|_IOR
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|_IOC(IOC_OUT,	(g), (n), sizeof(t))
end_define

begin_define
define|#
directive|define
name|_IOW
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|_IOC(IOC_IN,	(g), (n), sizeof(t))
end_define

begin_comment
comment|/* this should be _IORW, but stdio got there first */
end_comment

begin_define
define|#
directive|define
name|_IOWR
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|_IOC(IOC_INOUT,	(g), (n), sizeof(t))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_IOCCOM_H_ */
end_comment

end_unit

