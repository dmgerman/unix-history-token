begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   *             Coda: an Experimental Distributed File System  *                              Release 3.1  *   *           Copyright (c) 1987-1998 Carnegie Mellon University  *                          All Rights Reserved  *   * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *   * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *   * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *   * 	@(#) src/sys/coda/coda_pioctl.h,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $   * $FreeBSD$  *   */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1989 Carnegie-Mellon University  * Copyright (c) 1988 Carnegie-Mellon University  * Copyright (c) 1987 Carnegie-Mellon University  * All rights reserved.  The CMU software License Agreement specifies  * the terms and conditions for use and redistribution.  */
end_comment

begin_comment
comment|/*  * ITC Remote file system - vice ioctl interface module  */
end_comment

begin_comment
comment|/*  *  TODO:  Find /usr/local/include/viceioctl.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PIOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PIOCTL_H_
end_define

begin_comment
comment|/* The 2K limits above are a consequence of the size of the kernel buffer    used to buffer requests from the user to venus--2*MAXPATHLEN.    The buffer pointers may be null, or the counts may be 0 if there    are no input or output parameters  */
end_comment

begin_define
define|#
directive|define
name|_VICEIOCTL
parameter_list|(
name|id
parameter_list|)
value|((unsigned int ) _IOW('V', id, struct ViceIoctl))
end_define

begin_comment
comment|/* Use this macro to define up to 256 vice ioctl's.  These ioctl's    all potentially have in/out parameters--this depends upon the    values in the ViceIoctl structure.  This structure is itself passed    into the kernel by the normal ioctl parameter passing mechanism.  */
end_comment

begin_define
define|#
directive|define
name|_VALIDVICEIOCTL
parameter_list|(
name|com
parameter_list|)
value|(com>= _VICEIOCTL(0)&& com<= _VICEIOCTL(255))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

