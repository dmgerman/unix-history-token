begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inet.h     Portable definitions for internet addresses */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1996-2003 by Internet Software Consortium  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *   Internet Systems Consortium, Inc.  *   950 Charter Street  *   Redwood City, CA 94063  *<info@isc.org>  *   http://www.isc.org/  *  * This software has been written for Internet Systems Consortium  * by Ted Lemon in cooperation with Vixie Enterprises and Nominum, Inc.  * To learn more about Internet Systems Consortium, see  * ``http://www.isc.org/''.  To learn more about Vixie Enterprises,  * see ``http://www.vix.com''.   To learn more about Nominum, Inc., see  * ``http://www.nominum.com''.  */
end_comment

begin_comment
comment|/* An internet address of up to 128 bits. */
end_comment

begin_struct
struct|struct
name|iaddr
block|{
name|unsigned
name|len
decl_stmt|;
name|unsigned
name|char
name|iabuf
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iaddrlist
block|{
name|struct
name|iaddrlist
modifier|*
name|next
decl_stmt|;
name|struct
name|iaddr
name|addr
decl_stmt|;
block|}
struct|;
end_struct

end_unit

