begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   *             Coda: an Experimental Distributed File System  *                              Release 3.1  *   *           Copyright (c) 1987-1998 Carnegie Mellon University  *                          All Rights Reserved  *   * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *   * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *   * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *   * 	@(#) src/sys/coda/coda_io.h,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $   * $FreeBSD$  *   */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1990 Carnegie-Mellon University  * Copyright (c) 1989 Carnegie-Mellon University  * All rights reserved.  The CMU software License Agreement specifies  * the terms and conditions for use and redistribution.  */
end_comment

begin_comment
comment|/*  * This code was written for the Coda file system at Carnegie Mellon University.  * Contributers include David Steere, James Kistler, and M. Satyanarayanan.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CODAIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_CODAIO_H_
end_define

begin_comment
comment|/* Define ioctl commands for vcioctl, /dev/cfs */
end_comment

begin_define
define|#
directive|define
name|CODARESIZE
value|_IOW('c', 1, struct coda_resize )
end_define

begin_comment
comment|/* Resize CODA NameCache */
end_comment

begin_define
define|#
directive|define
name|CODASTATS
value|_IO('c', 2)
end_define

begin_comment
comment|/* Collect stats */
end_comment

begin_define
define|#
directive|define
name|CODAPRINT
value|_IO('c', 3)
end_define

begin_comment
comment|/* Print Cache */
end_comment

begin_define
define|#
directive|define
name|CODATEST
value|_IO('c', 4)
end_define

begin_comment
comment|/* Print Cache */
end_comment

begin_struct
struct|struct
name|coda_resize
block|{
name|int
name|hashsize
decl_stmt|,
name|heapsize
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

