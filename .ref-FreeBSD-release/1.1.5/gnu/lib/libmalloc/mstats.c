begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Access the statistics maintained by `malloc'.    Copyright 1990, 1991, 1992 Free Software Foundation 		  Written May 1989 by Mike Haertel.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with this library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author may be reached (Email) at the address mike@ai.mit.edu,    or (US mail) as Mike Haertel c/o Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MALLOC_INTERNAL
end_ifndef

begin_define
define|#
directive|define
name|_MALLOC_INTERNAL
end_define

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|struct
name|mstats
name|mstats
parameter_list|()
block|{
name|struct
name|mstats
name|result
decl_stmt|;
name|result
operator|.
name|bytes_total
operator|=
operator|(
name|char
operator|*
operator|)
call|(
modifier|*
name|__morecore
call|)
argument_list|(
literal|0
argument_list|)
operator|-
name|_heapbase
expr_stmt|;
name|result
operator|.
name|chunks_used
operator|=
name|_chunks_used
expr_stmt|;
name|result
operator|.
name|bytes_used
operator|=
name|_bytes_used
expr_stmt|;
name|result
operator|.
name|chunks_free
operator|=
name|_chunks_free
expr_stmt|;
name|result
operator|.
name|bytes_free
operator|=
name|_bytes_free
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

end_unit

