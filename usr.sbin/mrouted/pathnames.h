begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $FreeBSD$  * pathnames.h,v 3.8 1995/11/29 22:36:57 fenner Rel  */
end_comment

begin_define
define|#
directive|define
name|_PATH_MROUTED_CONF
value|"/etc/mrouted.conf"
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
name|_PATH_MROUTED_PID
value|"/var/run/mrouted.pid"
end_define

begin_define
define|#
directive|define
name|_PATH_MROUTED_GENID
value|"/var/run/mrouted.genid"
end_define

begin_define
define|#
directive|define
name|_PATH_MROUTED_DUMP
value|"/var/tmp/mrouted.dump"
end_define

begin_define
define|#
directive|define
name|_PATH_MROUTED_CACHE
value|"/var/tmp/mrouted.cache"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_MROUTED_PID
value|"/etc/mrouted.pid"
end_define

begin_define
define|#
directive|define
name|_PATH_MROUTED_GENID
value|"/etc/mrouted.genid"
end_define

begin_define
define|#
directive|define
name|_PATH_MROUTED_DUMP
value|"/usr/tmp/mrouted.dump"
end_define

begin_define
define|#
directive|define
name|_PATH_MROUTED_CACHE
value|"/usr/tmp/mrouted.cache"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

