begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   *             Coda: an Experimental Distributed File System  *                              Release 3.1  *   *           Copyright (c) 1987-1998 Carnegie Mellon University  *                          All Rights Reserved  *   * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *   * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *   * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *   * 	@(#) src/sys/coda/coda_kernel.h,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $   * $FreeBSD$  *   */
end_comment

begin_comment
comment|/* Macros to manipulate the queue */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INIT_QUEUE
end_ifndef

begin_struct
struct|struct
name|queue
block|{
name|struct
name|queue
modifier|*
name|forw
decl_stmt|,
modifier|*
name|back
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INIT_QUEUE
parameter_list|(
name|head
parameter_list|)
define|\
value|do {                                         \     (head).forw = (struct queue *)&(head);   \     (head).back = (struct queue *)&(head);   \ } while (0)
end_define

begin_define
define|#
directive|define
name|GETNEXT
parameter_list|(
name|head
parameter_list|)
value|(head).forw
end_define

begin_define
define|#
directive|define
name|EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head).forw ==&(head))
end_define

begin_define
define|#
directive|define
name|EOQ
parameter_list|(
name|el
parameter_list|,
name|head
parameter_list|)
value|((struct queue *)(el) == (struct queue *)&(head))
end_define

begin_define
define|#
directive|define
name|INSQUE
parameter_list|(
name|el
parameter_list|,
name|head
parameter_list|)
define|\
value|do {                                                 \ 	(el).forw = ((head).back)->forw;             \ 	(el).back = (head).back;                     \ 	((head).back)->forw = (struct queue *)&(el); \ 	(head).back = (struct queue *)&(el);         \ } while (0)
end_define

begin_define
define|#
directive|define
name|REMQUE
parameter_list|(
name|el
parameter_list|)
define|\
value|do {                                       \ 	((el).forw)->back = (el).back;     \ 	(el).back->forw = (el).forw;       \ }  while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

