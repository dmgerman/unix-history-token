begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	from db.h	4.16 (Berkeley) 6/1/90  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * ++Copyright++ 1985, 1990  * -  * Copyright (c) 1985, 1990  *    The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_comment
comment|/*  * Global definitions for data base routines.  */
end_comment

begin_define
define|#
directive|define
name|INVBLKSZ
value|7
end_define

begin_comment
comment|/* # of namebuf pointers per block */
end_comment

begin_define
define|#
directive|define
name|INVHASHSZ
value|919
end_define

begin_comment
comment|/* size of inverse hash table */
end_comment

begin_comment
comment|/* max length of data in RR data field */
end_comment

begin_define
define|#
directive|define
name|MAXDATA
value|2048
end_define

begin_define
define|#
directive|define
name|DB_ROOT_TIMBUF
value|3600
end_define

begin_define
define|#
directive|define
name|TIMBUF
value|300
end_define

begin_comment
comment|/*  * Hash table structures.  */
end_comment

begin_struct
struct|struct
name|databuf
block|{
name|struct
name|databuf
modifier|*
name|d_next
decl_stmt|;
comment|/* linked list */
name|u_int32_t
name|d_ttl
decl_stmt|;
comment|/* time to live */
comment|/* if d_zone == DB_Z_CACHE, then 					 * d_ttl is actually the time when 					 * the record will expire. 					 * otherwise (for authoritative 					 * primary and secondary zones), 					 * d_ttl is the time to live. 					 */
name|unsigned
name|d_flags
range|:
literal|7
decl_stmt|;
comment|/* see below */
name|unsigned
name|d_cred
range|:
literal|3
decl_stmt|;
comment|/* DB_C_{??????} */
name|unsigned
name|d_clev
range|:
literal|6
decl_stmt|;
name|int16_t
name|d_zone
decl_stmt|;
comment|/* zone number or 0 for the cache */
name|int16_t
name|d_class
decl_stmt|;
comment|/* class number */
name|int16_t
name|d_type
decl_stmt|;
comment|/* type number */
name|int16_t
name|d_mark
decl_stmt|;
comment|/* place to mark data */
name|int16_t
name|d_size
decl_stmt|;
comment|/* size of data area */
ifdef|#
directive|ifdef
name|NCACHE
name|int16_t
name|d_rcode
decl_stmt|;
comment|/* rcode added for negative caching */
endif|#
directive|endif
name|int16_t
name|d_rcnt
decl_stmt|;
ifdef|#
directive|ifdef
name|STATS
name|struct
name|nameser
modifier|*
name|d_ns
decl_stmt|;
comment|/* NS from whence this came */
endif|#
directive|endif
comment|/*XXX*/
name|u_int32_t
name|d_nstime
decl_stmt|;
comment|/* NS response time, milliseconds */
name|u_char
name|d_data
index|[
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
index|]
decl_stmt|;
comment|/* malloc'd (padded) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DATASIZE
parameter_list|(
name|n
parameter_list|)
value|(sizeof(struct databuf) - sizeof(char*) + n)
end_define

begin_comment
comment|/*  * d_flags definitions  */
end_comment

begin_define
define|#
directive|define
name|DB_F_HINT
value|0x01
end_define

begin_comment
comment|/* databuf belongs to fcachetab */
end_comment

begin_comment
comment|/*  * d_cred definitions  */
end_comment

begin_define
define|#
directive|define
name|DB_C_ZONE
value|4
end_define

begin_comment
comment|/* authoritative zone - best */
end_comment

begin_define
define|#
directive|define
name|DB_C_AUTH
value|3
end_define

begin_comment
comment|/* authoritative answer */
end_comment

begin_define
define|#
directive|define
name|DB_C_ANSWER
value|2
end_define

begin_comment
comment|/* non-authoritative answer */
end_comment

begin_define
define|#
directive|define
name|DB_C_ADDITIONAL
value|1
end_define

begin_comment
comment|/* additional data */
end_comment

begin_define
define|#
directive|define
name|DB_C_CACHE
value|0
end_define

begin_comment
comment|/* cache - worst */
end_comment

begin_struct
struct|struct
name|namebuf
block|{
name|char
modifier|*
name|n_dname
decl_stmt|;
comment|/* domain name */
name|u_int
name|n_hashval
decl_stmt|;
comment|/* hash value of n_dname */
name|struct
name|namebuf
modifier|*
name|n_next
decl_stmt|;
comment|/* linked list */
name|struct
name|databuf
modifier|*
name|n_data
decl_stmt|;
comment|/* data records */
name|struct
name|namebuf
modifier|*
name|n_parent
decl_stmt|;
comment|/* parent domain */
name|struct
name|hashbuf
modifier|*
name|n_hash
decl_stmt|;
comment|/* hash table for children */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|INVQ
end_ifdef

begin_struct
struct|struct
name|invbuf
block|{
name|struct
name|invbuf
modifier|*
name|i_next
decl_stmt|;
comment|/* linked list */
name|struct
name|namebuf
modifier|*
name|i_dname
index|[
name|INVBLKSZ
index|]
decl_stmt|;
comment|/* domain name */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|hashbuf
block|{
name|int
name|h_size
decl_stmt|;
comment|/* size of hash table */
name|int
name|h_cnt
decl_stmt|;
comment|/* number of entries */
name|struct
name|namebuf
modifier|*
name|h_tab
index|[
literal|1
index|]
decl_stmt|;
comment|/* malloc'ed as needed */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HASHSIZE
parameter_list|(
name|s
parameter_list|)
value|(s*sizeof(struct namebuf *) + 2*sizeof(int))
end_define

begin_define
define|#
directive|define
name|HASHSHIFT
value|3
end_define

begin_define
define|#
directive|define
name|HASHMASK
value|0x1f
end_define

begin_comment
comment|/*  * Flags to updatedb  */
end_comment

begin_define
define|#
directive|define
name|DB_NODATA
value|0x01
end_define

begin_comment
comment|/* data should not exist */
end_comment

begin_define
define|#
directive|define
name|DB_MEXIST
value|0x02
end_define

begin_comment
comment|/* data must exist */
end_comment

begin_define
define|#
directive|define
name|DB_DELETE
value|0x04
end_define

begin_comment
comment|/* delete data if it exists */
end_comment

begin_define
define|#
directive|define
name|DB_NOTAUTH
value|0x08
end_define

begin_comment
comment|/* must not update authoritative data */
end_comment

begin_define
define|#
directive|define
name|DB_NOHINTS
value|0x10
end_define

begin_comment
comment|/* don't reflect update in fcachetab */
end_comment

begin_define
define|#
directive|define
name|DB_PRIMING
value|0x20
end_define

begin_comment
comment|/* is this update the result of priming? */
end_comment

begin_define
define|#
directive|define
name|DB_Z_CACHE
value|(0)
end_define

begin_comment
comment|/* cache-zone-only db_dump() */
end_comment

begin_define
define|#
directive|define
name|DB_Z_ALL
value|(-1)
end_define

begin_comment
comment|/* normal db_dump() */
end_comment

begin_comment
comment|/*  * Error return codes  */
end_comment

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_define
define|#
directive|define
name|NONAME
value|-1
end_define

begin_define
define|#
directive|define
name|NOCLASS
value|-2
end_define

begin_define
define|#
directive|define
name|NOTYPE
value|-3
end_define

begin_define
define|#
directive|define
name|NODATA
value|-4
end_define

begin_define
define|#
directive|define
name|DATAEXISTS
value|-5
end_define

begin_define
define|#
directive|define
name|NODBFILE
value|-6
end_define

begin_define
define|#
directive|define
name|TOOMANYZONES
value|-7
end_define

begin_define
define|#
directive|define
name|GOODDB
value|-8
end_define

begin_define
define|#
directive|define
name|NEWDB
value|-9
end_define

begin_define
define|#
directive|define
name|AUTH
value|-10
end_define

begin_comment
comment|/*  * getnum() options  */
end_comment

begin_define
define|#
directive|define
name|GETNUM_NONE
value|0x00
end_define

begin_comment
comment|/* placeholder */
end_comment

begin_define
define|#
directive|define
name|GETNUM_SERIAL
value|0x01
end_define

begin_comment
comment|/* treat as serial number */
end_comment

begin_define
define|#
directive|define
name|GETNUM_SCALED
value|0x02
end_define

begin_comment
comment|/* permit "k", "m" suffixes, scale result */
end_comment

end_unit

