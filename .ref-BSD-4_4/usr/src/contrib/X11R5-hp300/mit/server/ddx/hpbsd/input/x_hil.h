begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|X_HIL_H
end_ifndef

begin_define
define|#
directive|define
name|X_HIL_H
end_define

begin_comment
comment|/* $Header: /host/kaukau/disk2/X11R5/R5-hp300/mit/server/ddx/hpbsd/input/RCS/x_hil.h,v 1.1 1992/09/30 03:14:10 root Exp $ */
end_comment

begin_comment
comment|/*  Copyright (c) 1986, 1987 by Hewlett-Packard Company Copyright (c) 1986, 1987 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  HEWLETT-PACKARD MAKES NO WARRANTY OF ANY KIND WITH REGARD TO THIS SOFWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE.  Hewlett-Packard shall not be liable for errors  contained herein or direct, indirect, special, incidental or  consequential damages in connection with the furnishing,  performance, or use of this material.  This software is not subject to any license of the American Telephone and Telegraph Company or of the Regents of the University of California.  */
end_comment

begin_include
include|#
directive|include
file|"hpext.h"
end_include

begin_comment
comment|/* MAXHILEVENTS is the maximum number of X events that can    be put on the events queue as the result of reading a     single HIL data packet.  The HIL definition is that     a packet may contain one motion event and up to 8 bytes    of key data.  If the key device is a barcode reader in     ASCII mode, we translate each ASCII code into up to 6    keycodes.  The maximum number of X events that can be     generated from a single HIL packet is therefore 49.     MAX_EVENTS is the size of the server's internal queue of    input events.  X input is a two-step process, with the     first step consisting of reading input events from the     device and putting them on this internal queue.  Later    in the dispatch loop, that queue is emptied and all the    events are routed by DIX to the appropriate clients.     The size of the event queue is not as large as the     theoretical maximum, but motion events are compressed    into a single event until a key or button is seen.     The worst at all reasonable case is alternating key and    motion data, which would result in less than 50 events.    A more reasonable guess is 20 events per device.    Our queue size therefore allows for the worst case on     5 - 10 devices simultaneously. */
end_comment

begin_define
define|#
directive|define
name|MAXHILEVENTS
value|49
end_define

begin_define
define|#
directive|define
name|MOTION_BUFFER_SIZE
value|100
end_define

begin_define
define|#
directive|define
name|MAX_EVENTS
value|256
end_define

begin_define
define|#
directive|define
name|WR_EVENTS
value|MAX_EVENTS-1
end_define

begin_struct
struct|struct
name|x11EventQueue
block|{
name|xHPEvent
modifier|*
name|events
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|head
decl_stmt|;
name|int
name|tail
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

