begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  *             Coda: an Experimental Distributed File System  *                              Release 3.1  *  *           Copyright (c) 1998 Carnegie Mellon University  *                          All Rights Reserved  *  * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *  * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *  * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *  * 	@(#) src/sys/coda/coda_psdev.c,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CODA_PSDEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_CODA_PSDEV_H_
end_define

begin_comment
comment|/*  * Prototypes for cfs device operations.  */
end_comment

begin_decl_stmt
name|d_open_t
name|vc_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|vc_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|vc_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|vc_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|vc_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_poll_t
name|vc_poll
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CODA_PSDEV_H_ */
end_comment

end_unit

