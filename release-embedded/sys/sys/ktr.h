begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from BSDI $Id: ktr.h,v 1.10.2.7 2000/03/16 21:44:42 cp Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	Wraparound kernel trace buffer support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KTR_H_
end_define

begin_include
include|#
directive|include
file|<sys/ktr_class.h>
end_include

begin_comment
comment|/*  * Version number for ktr_entry struct.  Increment this when you break binary  * compatibility.  */
end_comment

begin_define
define|#
directive|define
name|KTR_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|KTR_PARMS
value|6
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/_cpuset.h>
end_include

begin_struct
struct|struct
name|ktr_entry
block|{
name|u_int64_t
name|ktr_timestamp
decl_stmt|;
name|int
name|ktr_cpu
decl_stmt|;
name|int
name|ktr_line
decl_stmt|;
specifier|const
name|char
modifier|*
name|ktr_file
decl_stmt|;
specifier|const
name|char
modifier|*
name|ktr_desc
decl_stmt|;
name|struct
name|thread
modifier|*
name|ktr_thread
decl_stmt|;
name|u_long
name|ktr_parms
index|[
name|KTR_PARMS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|cpuset_t
name|ktr_cpumask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ktr_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ktr_entries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ktr_verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|ktr_idx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ktr_entry
modifier|*
name|ktr_buf
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KTR
end_ifdef

begin_function_decl
name|void
name|ktr_tracepoint
parameter_list|(
name|u_int
name|mask
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|u_long
name|arg1
parameter_list|,
name|u_long
name|arg2
parameter_list|,
name|u_long
name|arg3
parameter_list|,
name|u_long
name|arg4
parameter_list|,
name|u_long
name|arg5
parameter_list|,
name|u_long
name|arg6
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CTR6
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
value|do {			\ 	if (KTR_COMPILE& (m))						\ 		ktr_tracepoint((m), __FILE__, __LINE__, format,		\ 		    (u_long)(p1), (u_long)(p2), (u_long)(p3),		\ 		    (u_long)(p4), (u_long)(p5), (u_long)(p6));		\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|CTR0
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|)
value|CTR6(m, format, 0, 0, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|CTR1
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|)
value|CTR6(m, format, p1, 0, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|CTR2
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
value|CTR6(m, format, p1, p2, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|CTR3
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
value|CTR6(m, format, p1, p2, p3, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|CTR4
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
value|CTR6(m, format, p1, p2, p3, p4, 0, 0)
end_define

begin_define
define|#
directive|define
name|CTR5
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
value|CTR6(m, format, p1, p2, p3, p4, p5, 0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* KTR */
end_comment

begin_define
define|#
directive|define
name|CTR0
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|CTR1
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|CTR2
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|CTR3
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|CTR4
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|CTR5
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|CTR6
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
value|(void)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KTR */
end_comment

begin_define
define|#
directive|define
name|TR0
parameter_list|(
name|d
parameter_list|)
value|CTR0(KTR_GEN, d)
end_define

begin_define
define|#
directive|define
name|TR1
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|)
value|CTR1(KTR_GEN, d, p1)
end_define

begin_define
define|#
directive|define
name|TR2
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
value|CTR2(KTR_GEN, d, p1, p2)
end_define

begin_define
define|#
directive|define
name|TR3
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
value|CTR3(KTR_GEN, d, p1, p2, p3)
end_define

begin_define
define|#
directive|define
name|TR4
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
value|CTR4(KTR_GEN, d, p1, p2, p3, p4)
end_define

begin_define
define|#
directive|define
name|TR5
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
value|CTR5(KTR_GEN, d, p1, p2, p3, p4, p5)
end_define

begin_define
define|#
directive|define
name|TR6
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
value|CTR6(KTR_GEN, d, p1, p2, p3, p4, p5, p6)
end_define

begin_comment
comment|/*  * The event macros implement KTR graphic plotting facilities provided  * by src/tools/sched/schedgraph.py.  Three generic types of events are  * supported: states, counters, and points.  *  * m is the ktr class for ktr_mask.  * ident is the string identifier that owns the event (ie: "thread 10001")  * etype is the type of event to plot (state, counter, point)  * edat is the event specific data (state name, counter value, point name)  * up to four attributes may be supplied as a name, value pair of arguments.  *  * etype and attribute names must be string constants.  This minimizes the  * number of ktr slots required by construction the final format strings  * at compile time.  Both must also include a colon and format specifier  * (ie. "prio:%d", prio).  It is recommended that string arguments be  * contained within escaped quotes if they may contain ',' or ':' characters.  *  * The special attribute (KTR_ATTR_LINKED, ident) creates a reference to another  * id on the graph for easy traversal of related graph elements.  */
end_comment

begin_define
define|#
directive|define
name|KTR_ATTR_LINKED
value|"linkedto:\"%s\""
end_define

begin_define
define|#
directive|define
name|KTR_EFMT
parameter_list|(
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|etype
parameter_list|)
define|\
value|"KTRGRAPH group:\"" egroup "\", id:\"%s\", " etype ", attributes: "
end_define

begin_define
define|#
directive|define
name|KTR_EVENT0
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|etype
parameter_list|,
name|edat
parameter_list|)
define|\
value|CTR2(m,	KTR_EFMT(egroup, ident, etype) "none", ident, edat)
end_define

begin_define
define|#
directive|define
name|KTR_EVENT1
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|etype
parameter_list|,
name|edat
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|)
define|\
value|CTR3(m, KTR_EFMT(egroup, ident, etype) a0, ident, edat, (v0))
end_define

begin_define
define|#
directive|define
name|KTR_EVENT2
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|etype
parameter_list|,
name|edat
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|)
define|\
value|CTR4(m, KTR_EFMT(egroup, ident, etype) a0 ", " a1,		\ 	    ident, edat, (v0), (v1))
end_define

begin_define
define|#
directive|define
name|KTR_EVENT3
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|etype
parameter_list|,
name|edat
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|)
define|\
value|CTR5(m,KTR_EFMT(egroup, ident, etype) a0 ", " a1 ", " a2,	\ 	    ident, edat, (v0), (v1), (v2))
end_define

begin_define
define|#
directive|define
name|KTR_EVENT4
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|etype
parameter_list|,
name|edat
parameter_list|,			\
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|,
name|a3
parameter_list|,
name|v3
parameter_list|)
define|\
value|CTR6(m,KTR_EFMT(egroup, ident, etype) a0 ", " a1 ", " a2 ", " a3,\ 	     ident, edat, (v0), (v1), (v2), (v3))
end_define

begin_comment
comment|/*  * State functions graph state changes on an ident.  */
end_comment

begin_define
define|#
directive|define
name|KTR_STATE0
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|state
parameter_list|)
define|\
value|KTR_EVENT0(m, egroup, ident, "state:\"%s\"", state)
end_define

begin_define
define|#
directive|define
name|KTR_STATE1
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|state
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|)
define|\
value|KTR_EVENT1(m, egroup, ident, "state:\"%s\"", state, a0, (v0))
end_define

begin_define
define|#
directive|define
name|KTR_STATE2
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|state
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|)
define|\
value|KTR_EVENT2(m, egroup, ident, "state:\"%s\"", state, a0, (v0), a1, (v1))
end_define

begin_define
define|#
directive|define
name|KTR_STATE3
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|state
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|)
define|\
value|KTR_EVENT3(m, egroup, ident, "state:\"%s\"",			\ 	    state, a0, (v0), a1, (v1), a2, (v2))
end_define

begin_define
define|#
directive|define
name|KTR_STATE4
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|state
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|,
name|a3
parameter_list|,
name|v3
parameter_list|)
define|\
value|KTR_EVENT4(m, egroup, ident, "state:\"%s\"",			\ 	    state, a0, (v0), a1, (v1), a2, (v2), a3, (v3))
end_define

begin_comment
comment|/*  * Counter functions graph counter values.  The counter id  * must not be intermixed with a state id.   */
end_comment

begin_define
define|#
directive|define
name|KTR_COUNTER0
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|counter
parameter_list|)
define|\
value|KTR_EVENT0(m, egroup, ident, "counter:%d", counter)
end_define

begin_define
define|#
directive|define
name|KTR_COUNTER1
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|edat
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|)
define|\
value|KTR_EVENT1(m, egroup, ident, "counter:%d", counter, a0, (v0))
end_define

begin_define
define|#
directive|define
name|KTR_COUNTER2
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|counter
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|)
define|\
value|KTR_EVENT2(m, egroup, ident, "counter:%d", counter, a0, (v0), a1, (v1))
end_define

begin_define
define|#
directive|define
name|KTR_COUNTER3
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|counter
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|)
define|\
value|KTR_EVENT3(m, egroup, ident, "counter:%d",			\ 	    counter, a0, (v0), a1, (v1), a2, (v2))
end_define

begin_define
define|#
directive|define
name|KTR_COUNTER4
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|counter
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|,
name|a3
parameter_list|,
name|v3
parameter_list|)
define|\
value|KTR_EVENT4(m, egroup, ident, "counter:%d",			\ 	    counter, a0, (v0), a1, (v1), a2, (v2), a3, (v3))
end_define

begin_comment
comment|/*  * Point functions plot points of interest on counter or state graphs.  */
end_comment

begin_define
define|#
directive|define
name|KTR_POINT0
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|point
parameter_list|)
define|\
value|KTR_EVENT0(m, egroup, ident, "point:\"%s\"", point)
end_define

begin_define
define|#
directive|define
name|KTR_POINT1
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|point
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|)
define|\
value|KTR_EVENT1(m, egroup, ident, "point:\"%s\"", point, a0, (v0))
end_define

begin_define
define|#
directive|define
name|KTR_POINT2
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|point
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|)
define|\
value|KTR_EVENT2(m, egroup, ident, "point:\"%s\"", point, a0, (v0), a1, (v1))
end_define

begin_define
define|#
directive|define
name|KTR_POINT3
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|point
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|)
define|\
value|KTR_EVENT3(m, egroup, ident, "point:\"%s\"", point,		\ 	    a0, (v0), a1, (v1), a2, (v2))
end_define

begin_define
define|#
directive|define
name|KTR_POINT4
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|point
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|,
name|a3
parameter_list|,
name|v3
parameter_list|)
define|\
value|KTR_EVENT4(m, egroup, ident, "point:\"%s\"",			\ 	    point, a0, (v0), a1, (v1), a2, (v2), a3, (v3))
end_define

begin_comment
comment|/*  * Start functions denote the start of a region of code or operation  * and should be paired with stop functions for timing of nested  * sequences.  *  * Specifying extra attributes with the name "key" will result in  * multi-part keys.  For example a block device and offset pair  * might be used to describe a buf undergoing I/O.  */
end_comment

begin_define
define|#
directive|define
name|KTR_START0
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|key
parameter_list|)
define|\
value|KTR_EVENT0(m, egroup, ident, "start:0x%jX", (uintmax_t)key)
end_define

begin_define
define|#
directive|define
name|KTR_START1
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|key
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|)
define|\
value|KTR_EVENT1(m, egroup, ident, "start:0x%jX", (uintmax_t)key, a0, (v0))
end_define

begin_define
define|#
directive|define
name|KTR_START2
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|key
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|)
define|\
value|KTR_EVENT2(m, egroup, ident, "start:0x%jX", (uintmax_t)key,	\ 	    a0, (v0), a1, (v1))
end_define

begin_define
define|#
directive|define
name|KTR_START3
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|key
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|)
define|\
value|KTR_EVENT3(m, egroup, ident, "start:0x%jX", (uintmax_t)key,	\ 	    a0, (v0), a1, (v1), a2, (v2))
end_define

begin_define
define|#
directive|define
name|KTR_START4
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|key
parameter_list|,				\
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|,
name|a3
parameter_list|,
name|v3
parameter_list|)
define|\
value|KTR_EVENT4(m, egroup, ident, "start:0x%jX", (uintmax_t)key,	\ 	    a0, (v0), a1, (v1), a2, (v2), a3, (v3))
end_define

begin_comment
comment|/*  * Stop functions denote the end of a region of code or operation  * and should be paired with start functions for timing of nested  * sequences.  */
end_comment

begin_define
define|#
directive|define
name|KTR_STOP0
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|key
parameter_list|)
define|\
value|KTR_EVENT0(m, egroup, ident, "stop:0x%jX", (uintmax_t)key)
end_define

begin_define
define|#
directive|define
name|KTR_STOP1
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|key
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|)
define|\
value|KTR_EVENT1(m, egroup, ident, "stop:0x%jX", (uintmax_t)key, a0, (v0))
end_define

begin_define
define|#
directive|define
name|KTR_STOP2
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|key
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|)
define|\
value|KTR_EVENT2(m, egroup, ident, "stop:0x%jX", (uintmax_t)key,	\ 	    a0, (v0), a1, (v1))
end_define

begin_define
define|#
directive|define
name|KTR_STOP3
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|,
name|key
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|)
define|\
value|KTR_EVENT3(m, egroup, ident, "stop:0x%jX", (uintmax_t)key,	\ 	    a0, (v0), a1, (v1), a2, (v2))
end_define

begin_define
define|#
directive|define
name|KTR_STOP4
parameter_list|(
name|m
parameter_list|,
name|egroup
parameter_list|,
name|ident
parameter_list|, 					\
name|key
parameter_list|,
name|a0
parameter_list|,
name|v0
parameter_list|,
name|a1
parameter_list|,
name|v1
parameter_list|,
name|a2
parameter_list|,
name|v2
parameter_list|,
name|a3
parameter_list|,
name|v3
parameter_list|)
define|\
value|KTR_EVENT4(m, egroup, ident, "stop:0x%jX", (uintmax_t)key,	\ 	    a0, (v0), a1, (v1), a2, (v2), a3, (v3))
end_define

begin_comment
comment|/*  * Trace initialization events, similar to CTR with KTR_INIT, but  * completely ifdef'ed out if KTR_INIT isn't in KTR_COMPILE (to  * save string space, the compiler doesn't optimize out strings  * for the conditional ones above).  */
end_comment

begin_if
if|#
directive|if
operator|(
name|KTR_COMPILE
operator|&
name|KTR_INIT
operator|)
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|ITR0
parameter_list|(
name|d
parameter_list|)
value|CTR0(KTR_INIT, d)
end_define

begin_define
define|#
directive|define
name|ITR1
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|)
value|CTR1(KTR_INIT, d, p1)
end_define

begin_define
define|#
directive|define
name|ITR2
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
value|CTR2(KTR_INIT, d, p1, p2)
end_define

begin_define
define|#
directive|define
name|ITR3
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
value|CTR3(KTR_INIT, d, p1, p2, p3)
end_define

begin_define
define|#
directive|define
name|ITR4
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
value|CTR4(KTR_INIT, d, p1, p2, p3, p4)
end_define

begin_define
define|#
directive|define
name|ITR5
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
value|CTR5(KTR_INIT, d, p1, p2, p3, p4, p5)
end_define

begin_define
define|#
directive|define
name|ITR6
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
value|CTR6(KTR_INIT, d, p1, p2, p3, p4, p5, p6)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ITR0
parameter_list|(
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR1
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR2
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR3
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR4
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR5
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR6
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_KTR_H_ */
end_comment

end_unit

