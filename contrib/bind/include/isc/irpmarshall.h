begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: irpmarshall.h,v 8.1 1999/01/18 07:46:47 vixie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IRPMARSHALL_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_IRPMARSHALL_H_INCLUDED
end_define

begin_comment
comment|/* Hide function names */
end_comment

begin_define
define|#
directive|define
name|irp_marshall_gr
value|__irp_marshall_gr
end_define

begin_define
define|#
directive|define
name|irp_marshall_ho
value|__irp_marshall_ho
end_define

begin_define
define|#
directive|define
name|irp_marshall_ne
value|__irp_marshall_ne
end_define

begin_define
define|#
directive|define
name|irp_marshall_ng
value|__irp_marshall_ng
end_define

begin_define
define|#
directive|define
name|irp_marshall_nw
value|__irp_marshall_nw
end_define

begin_define
define|#
directive|define
name|irp_marshall_pr
value|__irp_marshall_pr
end_define

begin_define
define|#
directive|define
name|irp_marshall_pw
value|__irp_marshall_pw
end_define

begin_define
define|#
directive|define
name|irp_marshall_sv
value|__irp_marshall_sv
end_define

begin_define
define|#
directive|define
name|irp_unmarshall_gr
value|__irp_unmarshall_gr
end_define

begin_define
define|#
directive|define
name|irp_unmarshall_ho
value|__irp_unmarshall_ho
end_define

begin_define
define|#
directive|define
name|irp_unmarshall_ne
value|__irp_unmarshall_ne
end_define

begin_define
define|#
directive|define
name|irp_unmarshall_ng
value|__irp_unmarshall_ng
end_define

begin_define
define|#
directive|define
name|irp_unmarshall_nw
value|__irp_unmarshall_nw
end_define

begin_define
define|#
directive|define
name|irp_unmarshall_pr
value|__irp_unmarshall_pr
end_define

begin_define
define|#
directive|define
name|irp_unmarshall_pw
value|__irp_unmarshall_pw
end_define

begin_define
define|#
directive|define
name|irp_unmarshall_sv
value|__irp_unmarshall_sv
end_define

begin_define
define|#
directive|define
name|MAXPADDRSIZE
value|(sizeof "255.255.255.255" + 1)
end_define

begin_define
define|#
directive|define
name|ADDR_T_STR
parameter_list|(
name|x
parameter_list|)
value|(x == AF_INET ? "AF_INET" :\ 		       (x == AF_INET6 ? "AF_INET6" : "UNKNOWN"))
end_define

begin_comment
comment|/* See comment below on usage */
end_comment

begin_function_decl
name|int
name|irp_marshall_pw
parameter_list|(
specifier|const
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
name|char
modifier|*
modifier|*
name|buffer
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_unmarshall_pw
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_marshall_gr
parameter_list|(
specifier|const
name|struct
name|group
modifier|*
name|gr
parameter_list|,
name|char
modifier|*
modifier|*
name|buffer
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_unmarshall_gr
parameter_list|(
name|struct
name|group
modifier|*
name|gr
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_marshall_sv
parameter_list|(
specifier|const
name|struct
name|servent
modifier|*
name|sv
parameter_list|,
name|char
modifier|*
modifier|*
name|buffer
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_unmarshall_sv
parameter_list|(
name|struct
name|servent
modifier|*
name|sv
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_marshall_pr
parameter_list|(
name|struct
name|protoent
modifier|*
name|pr
parameter_list|,
name|char
modifier|*
modifier|*
name|buffer
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_unmarshall_pr
parameter_list|(
name|struct
name|protoent
modifier|*
name|pr
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_marshall_ho
parameter_list|(
name|struct
name|hostent
modifier|*
name|ho
parameter_list|,
name|char
modifier|*
modifier|*
name|buffer
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_unmarshall_ho
parameter_list|(
name|struct
name|hostent
modifier|*
name|ho
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_marshall_ng
parameter_list|(
specifier|const
name|char
modifier|*
name|host
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|,
specifier|const
name|char
modifier|*
name|domain
parameter_list|,
name|char
modifier|*
modifier|*
name|buffer
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_unmarshall_ng
parameter_list|(
name|char
modifier|*
modifier|*
name|host
parameter_list|,
name|char
modifier|*
modifier|*
name|user
parameter_list|,
name|char
modifier|*
modifier|*
name|domain
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_marshall_nw
parameter_list|(
name|struct
name|nwent
modifier|*
name|ne
parameter_list|,
name|char
modifier|*
modifier|*
name|buffer
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_unmarshall_nw
parameter_list|(
name|struct
name|nwent
modifier|*
name|ne
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_marshall_ne
parameter_list|(
name|struct
name|netent
modifier|*
name|ne
parameter_list|,
name|char
modifier|*
modifier|*
name|buffer
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irp_unmarshall_ne
parameter_list|(
name|struct
name|netent
modifier|*
name|ne
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions to marshall and unmarshall various system data structures. We  * use a printable ascii format that is as close to various system config  * files as reasonable (e.g. /etc/passwd format).  *  * We are not forgiving with unmarhsalling misformatted buffers. In  * particular whitespace in fields is not ignored. So a formatted password  * entry "brister  :1364:100:...." will yield a username of "brister   "  *  * We potentially do a lot of mallocs to fill fields that are of type  * (char **) like a hostent h_addr field. Building (for example) the  * h_addr field and its associated addresses all in one buffer is  * certainly possible, but not done here.  *  * The following description is true for all the marshalling functions:  *  */
end_comment

begin_comment
comment|/* int irp_marshall_XX(struct yyyy *XX, char **buffer, size_t *len);  *  * The argument XX (of type struct passwd for example) is marshalled in the  * buffer pointed at by *BUFFER, which is of length *LEN. Returns 0  * on success and -1 on failure. Failure will occur if *LEN is  * smaller than needed.  *  * If BUFFER is NULL, then *LEN is set to the size of the buffer  * needed to marshall the data and no marshalling is actually done.  *  * If *BUFFER is NULL, then a buffer large enough will be allocated  * with memget() and the size allocated will be stored in *LEN. An extra 2  * bytes will be allocated for the client to append CRLF if wanted. The  * value of *LEN will include these two bytes.  *  * All the marshalling functions produce a buffer with the fields  * separated by colons (except for the hostent marshalling, which uses '@'  * to separate fields). Fields that have multiple subfields (like the  * gr_mem field in struct group) have their subparts separated by  * commas.  */
end_comment

begin_comment
comment|/*  * int irp_unmarshall_XX(struct YYYYY *XX, char *buffer);  *  * The unmashalling functions break apart the buffer and store the  * values in the struct pointed to by XX. All pointer values inside  * XX are allocated with malloc. All arrays of pointers have a NULL  * as the last element.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

