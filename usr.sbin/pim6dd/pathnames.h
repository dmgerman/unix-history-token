begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1998 by the University of Southern California.  *  All rights reserved.  *  *  Permission to use, copy, modify, and distribute this software and  *  its documentation in source and binary forms for lawful  *  purposes and without fee is hereby granted, provided  *  that the above copyright notice appear in all copies and that both  *  the copyright notice and this permission notice appear in supporting  *  documentation, and that any documentation, advertising materials,  *  and other materials related to such distribution and use acknowledge  *  that the software was developed by the University of Southern  *  California and/or Information Sciences Institute.  *  The name of the University of Southern California may not  *  be used to endorse or promote products derived from this software  *  without specific prior written permission.  *  *  THE UNIVERSITY OF SOUTHERN CALIFORNIA DOES NOT MAKE ANY REPRESENTATIONS  *  ABOUT THE SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE.  THIS SOFTWARE IS  *  PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  *  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND  *  NON-INFRINGEMENT.  *  *  IN NO EVENT SHALL USC, OR ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY  *  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, WHETHER IN CONTRACT,  *  TORT, OR OTHER FORM OF ACTION, ARISING OUT OF OR IN CONNECTION WITH,  *  THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *  Other copyrights might apply to parts of this software and are so  *  noted when applicable.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to  *  Pavlin Ivanov Radoslavov (pavlin@catarina.usc.edu)  *  *  $Id: pathnames.h,v 1.2 1999/12/16 05:36:37 jinmei Exp $  */
end_comment

begin_comment
comment|/*  * Part of this program has been derived from mrouted.  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE.mrouted".  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|_PATH_PIM6D_CONF
value|"/usr/local/v6/etc/pim6dd.conf"
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|_PATH_PIM6D_PID
value|"/var/run/pim6dd.pid"
end_define

begin_define
define|#
directive|define
name|_PATH_PIM6D_GENID
value|"/var/run/pim6dd.genid"
end_define

begin_define
define|#
directive|define
name|_PATH_PIM6D_DUMP
value|"/var/run/pim6dd.dump"
end_define

begin_define
define|#
directive|define
name|_PATH_PIM6D_CACHE
value|"/var/run/pim6dd.cache"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_PIM6D_PID
value|"/etc/pim6dd.pid"
end_define

begin_define
define|#
directive|define
name|_PATH_PIM6D_GENID
value|"/etc/pim6dd.genid"
end_define

begin_define
define|#
directive|define
name|_PATH_PIM6D_DUMP
value|"/etc/pim6dd.dump"
end_define

begin_define
define|#
directive|define
name|_PATH_PIM6D_CACHE
value|"/etc/pim6dd.cache"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

