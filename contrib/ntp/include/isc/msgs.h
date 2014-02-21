begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: msgs.h,v 1.5.2.2.8.3 2004/03/06 08:14:44 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MSGS_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_MSGS_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lib.h>
end_include

begin_comment
comment|/* Provide isc_msgcat global variable. */
end_comment

begin_include
include|#
directive|include
file|<isc/msgcat.h>
end_include

begin_comment
comment|/* Provide isc_msgcat_*() functions. */
end_comment

begin_comment
comment|/*  * Message sets, named per source file, excepting "GENERAL".  * IMPORTANT: The original list is alphabetical, but any new sets must  * be added to the end.  */
end_comment

begin_define
define|#
directive|define
name|ISC_MSGSET_GENERAL
value|1
end_define

begin_comment
comment|/*	ISC_RESULT_RESULTSET    2 */
end_comment

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*	ISC_RESULT_UNAVAILABLESET 3 */
end_comment

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|ISC_MSGSET_APP
value|4
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_COMMANDLINE
value|5
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_ENTROPY
value|6
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_IFITERIOCTL
value|7
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_IFITERSYSCTL
value|8
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_LEX
value|9
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_LOG
value|10
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_MEM
value|11
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_NETADDR
value|12
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_PRINT
value|13
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_RESULT
value|14
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_RWLOCK
value|15
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_SOCKADDR
value|16
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_SOCKET
value|17
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_TASK
value|18
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_TIMER
value|19
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_UTIL
value|20
end_define

begin_define
define|#
directive|define
name|ISC_MSGSET_IFITERGETIFADDRS
value|21
end_define

begin_comment
comment|/*  * Message numbers.  They are only required to be unique per message set,  * but are unique throughout the entire catalog to not be as confusing when  * debugging.  *  * The initial numbering was done by multiply by 100 the set number the  * message appears in then adding the incremental message number.  */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_FAILED
value|101
end_define

begin_comment
comment|/* "failed" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SUCCEEDED
value|102
end_define

begin_comment
comment|/* Compatible with "failed" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SUCCESS
value|103
end_define

begin_comment
comment|/* More usual way to say "success" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_STARTING
value|104
end_define

begin_comment
comment|/* As in "daemon: starting" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_STOPING
value|105
end_define

begin_comment
comment|/* As in "daemon: stopping" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_ENTERING
value|106
end_define

begin_comment
comment|/* As in "some_subr: entering" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_EXITING
value|107
end_define

begin_comment
comment|/* As in "some_subr: exiting" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_CALLING
value|108
end_define

begin_comment
comment|/* As in "calling some_subr()" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_RETURNED
value|109
end_define

begin_comment
comment|/* As in "some_subr: returned<foo>" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_FATALERROR
value|110
end_define

begin_comment
comment|/* "fatal error" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SHUTTINGDOWN
value|111
end_define

begin_comment
comment|/* "shutting down" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_RUNNING
value|112
end_define

begin_comment
comment|/* "running" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_WAIT
value|113
end_define

begin_comment
comment|/* "wait" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_WAITUNTIL
value|114
end_define

begin_comment
comment|/* "waituntil" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SIGNALSETUP
value|201
end_define

begin_comment
comment|/* "handle_signal() %d setup: %s" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_ILLEGALOPT
value|301
end_define

begin_comment
comment|/* "illegal option" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_OPTNEEDARG
value|302
end_define

begin_comment
comment|/* "option requires an argument" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_ENTROPYSTATS
value|401
end_define

begin_comment
comment|/* "Entropy pool %p:  refcnt %u ..." */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_MAKESCANSOCKET
value|501
end_define

begin_comment
comment|/* "making interface scan socket: %s" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_GETIFCONFIG
value|502
end_define

begin_comment
comment|/* "get interface configuration: %s" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_BUFFERMAX
value|503
end_define

begin_comment
comment|/* "... maximum buffer size exceeded" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_GETDESTADDR
value|504
end_define

begin_comment
comment|/* "%s: getting destination address: %s" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_GETNETMASK
value|505
end_define

begin_comment
comment|/* "%s: getting netmask: %s" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_GETIFLISTSIZE
value|601
end_define

begin_comment
comment|/* "getting interface list size: ..." */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_GETIFLIST
value|602
end_define

begin_comment
comment|/* "getting interface list: ..." */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_UNEXPECTEDTYPE
value|603
end_define

begin_comment
comment|/* "... unexpected ... message type" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_UNEXPECTEDSTATE
value|701
end_define

begin_comment
comment|/* "Unexpected state %d" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_BADTIME
value|801
end_define

begin_comment
comment|/* "Bad 00 99:99:99.999 " */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_LEVEL
value|802
end_define

begin_comment
comment|/* "level %d: " */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_ADDTRACE
value|901
end_define

begin_comment
comment|/* "add %p size %u " */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_DELTRACE
value|902
end_define

begin_comment
comment|/* "del %p size %u " */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POOLSTATS
value|903
end_define

begin_comment
comment|/* "[Pool statistics]\n" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POOLNAME
value|904
end_define

begin_comment
comment|/* "name" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POOLSIZE
value|905
end_define

begin_comment
comment|/* "size" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POOLMAXALLOC
value|906
end_define

begin_comment
comment|/* "maxalloc" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POOLALLOCATED
value|907
end_define

begin_comment
comment|/* "allocated" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POOLFREECOUNT
value|908
end_define

begin_comment
comment|/* "freecount" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POOLFREEMAX
value|909
end_define

begin_comment
comment|/* "freemax" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POOLFILLCOUNT
value|910
end_define

begin_comment
comment|/* "fillcount" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POOLGETS
value|911
end_define

begin_comment
comment|/* "gets" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_DUMPALLOC
value|912
end_define

begin_comment
comment|/* "DUMP OF ALL OUTSTANDING MEMORY ..." */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_NONE
value|913
end_define

begin_comment
comment|/* "\tNone.\n" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_PTRFILELINE
value|914
end_define

begin_comment
comment|/* "\tptr %p file %s line %u\n" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_UNKNOWNADDR
value|1001
end_define

begin_comment
comment|/* "<unknown address, family %u>" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_NOLONGDBL
value|1104
end_define

begin_comment
comment|/* "long doubles are not supported" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_PRINTLOCK
value|1201
end_define

begin_comment
comment|/* "rwlock %p thread %lu ..." */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_READ
value|1202
end_define

begin_comment
comment|/* "read" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_WRITE
value|1203
end_define

begin_comment
comment|/* "write" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_READING
value|1204
end_define

begin_comment
comment|/* "reading" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_WRITING
value|1205
end_define

begin_comment
comment|/* "writing" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_PRELOCK
value|1206
end_define

begin_comment
comment|/* "prelock" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POSTLOCK
value|1207
end_define

begin_comment
comment|/* "postlock" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_PREUNLOCK
value|1208
end_define

begin_comment
comment|/* "preunlock" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POSTUNLOCK
value|1209
end_define

begin_comment
comment|/* "postunlock" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_UNKNOWNFAMILY
value|1301
end_define

begin_comment
comment|/* "unknown address family: %d" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_WRITEFAILED
value|1401
end_define

begin_comment
comment|/* "write() failed during watcher ..." */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_READFAILED
value|1402
end_define

begin_comment
comment|/* "read() failed during watcher ... " */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_PROCESSCMSG
value|1403
end_define

begin_comment
comment|/* "processing cmsg %p" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_IFRECEIVED
value|1404
end_define

begin_comment
comment|/* "interface received on ifindex %u" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SENDTODATA
value|1405
end_define

begin_comment
comment|/* "sendto pktinfo data, ifindex %u" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_DOIORECV
value|1406
end_define

begin_comment
comment|/* "doio_recv: recvmsg(%d) %d bytes ..." */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_PKTRECV
value|1407
end_define

begin_comment
comment|/* "packet received correctly" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_DESTROYING
value|1408
end_define

begin_comment
comment|/* "destroying" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_CREATED
value|1409
end_define

begin_comment
comment|/* "created" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_ACCEPTLOCK
value|1410
end_define

begin_comment
comment|/* "internal_accept called, locked ..." */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_ACCEPTEDCXN
value|1411
end_define

begin_comment
comment|/* "accepted connection, new socket %p" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_INTERNALRECV
value|1412
end_define

begin_comment
comment|/* "internal_recv: task %p got event %p" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_INTERNALSEND
value|1413
end_define

begin_comment
comment|/* "internal_send: task %p got event %p" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_WATCHERMSG
value|1414
end_define

begin_comment
comment|/* "watcher got message %d" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SOCKETSREMAIN
value|1415
end_define

begin_comment
comment|/* "sockets exist" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_PKTINFOPROVIDED
value|1416
end_define

begin_comment
comment|/* "pktinfo structure provided, ..." */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_BOUND
value|1417
end_define

begin_comment
comment|/* "bound" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_ACCEPTRETURNED
value|1418
end_define

begin_comment
comment|/* accept() returned %d/%s */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_TOOMANYFDS
value|1419
end_define

begin_comment
comment|/* %s: too many open file descriptors */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_ZEROPORT
value|1420
end_define

begin_comment
comment|/* dropping source port zero packet */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_FILTER
value|1420
end_define

begin_comment
comment|/* setsockopt(SO_ACCEPTFILTER): %s */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_AWAKE
value|1502
end_define

begin_comment
comment|/* "awake" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_WORKING
value|1503
end_define

begin_comment
comment|/* "working" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_EXECUTE
value|1504
end_define

begin_comment
comment|/* "execute action" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_EMPTY
value|1505
end_define

begin_comment
comment|/* "empty" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_DONE
value|1506
end_define

begin_comment
comment|/* "done" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_QUANTUM
value|1507
end_define

begin_comment
comment|/* "quantum" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SCHEDULE
value|1601
end_define

begin_comment
comment|/* "schedule" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SIGNALSCHED
value|1602
end_define

begin_comment
comment|/* "signal (schedule)" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SIGNALDESCHED
value|1603
end_define

begin_comment
comment|/* "signal (deschedule)" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SIGNALDESTROY
value|1604
end_define

begin_comment
comment|/* "signal (destroy)" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_IDLERESCHED
value|1605
end_define

begin_comment
comment|/* "idle reschedule" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_EVENTNOTALLOC
value|1606
end_define

begin_comment
comment|/* "couldn't allocate event" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SCHEDFAIL
value|1607
end_define

begin_comment
comment|/* "couldn't schedule timer: %u" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_POSTING
value|1608
end_define

begin_comment
comment|/* "posting" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_WAKEUP
value|1609
end_define

begin_comment
comment|/* "wakeup" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_LOCK
value|1701
end_define

begin_comment
comment|/* "LOCK" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_LOCKING
value|1702
end_define

begin_comment
comment|/* "LOCKING" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_LOCKED
value|1703
end_define

begin_comment
comment|/* "LOCKED" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_UNLOCKED
value|1704
end_define

begin_comment
comment|/* "UNLOCKED" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_RWLOCK
value|1705
end_define

begin_comment
comment|/* "RWLOCK" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_RWLOCKED
value|1706
end_define

begin_comment
comment|/* "RWLOCKED" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_RWUNLOCK
value|1707
end_define

begin_comment
comment|/* "RWUNLOCK" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_BROADCAST
value|1708
end_define

begin_comment
comment|/* "BROADCAST" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_SIGNAL
value|1709
end_define

begin_comment
comment|/* "SIGNAL" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_UTILWAIT
value|1710
end_define

begin_comment
comment|/* "WAIT" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_WAITED
value|1711
end_define

begin_comment
comment|/* "WAITED" */
end_comment

begin_define
define|#
directive|define
name|ISC_MSG_GETIFADDRS
value|1801
end_define

begin_comment
comment|/* "getting interface addresses: ..." */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_MSGS_H */
end_comment

end_unit

