begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) UNIX System Laboratories, Inc.  All or some portions  * of this file are derived from material licensed to the  * University of California by American Telephone and Telegraph Co.  * or UNIX System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1982, 1986, The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)map.h	7.5 (Berkeley) 5/7/91  *	$Id: map.h,v 1.2 1993/11/07 17:52:44 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MAP_H_
value|1
end_define

begin_comment
comment|/*  * Resource allocation maps.  *  * Associated routines manage sub-allocation of an address space using  * an array of segment descriptors.  The first element of this array  * is a map structure, describing the arrays extent and the name  * of the controlled object.  Each additional structure represents  * a free segment of the address space.  *  * A call to rminit initializes a resource map and may also be used  * to free some address space for the map.  Subsequent calls to rmalloc  * and rmfree allocate and free space in the resource map.  If the resource  * map becomes too fragmented to be described in the available space,  * then some of the resource is discarded.  This may lead to critical  * shortages, but is better than not checking (as the previous versions  * of these routines did) or giving up and calling panic().  The routines  * could use linked lists and call a memory allocator when they run  * out of space, but that would not solve the out of space problem when  * called at interrupt time.  *  * N.B.: The address 0 in the resource address space is not available  * as it is used internally by the resource map routines.  */
end_comment

begin_struct
struct|struct
name|map
block|{
name|struct
name|mapent
modifier|*
name|m_limit
decl_stmt|;
comment|/* address of last slot in map */
name|char
modifier|*
name|m_name
decl_stmt|;
comment|/* name of resource, for messages */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mapent
block|{
name|int
name|m_size
decl_stmt|;
comment|/* size of this segment of the map */
name|int
name|m_addr
decl_stmt|;
comment|/* start of segment */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|ARGMAPSIZE
value|16
end_define

begin_decl_stmt
name|struct
name|map
modifier|*
name|kmemmap
decl_stmt|,
modifier|*
name|mbmap
decl_stmt|,
modifier|*
name|swapmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nswapmap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_MAP_H_ */
end_comment

end_unit

