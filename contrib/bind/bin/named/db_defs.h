begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	from db.h	4.16 (Berkeley) 6/1/90  *	$Id: db_defs.h,v 8.41 2001/02/08 02:05:50 marka Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1985, 1990  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1996-2000 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Global definitions for data base routines.  */
end_comment

begin_comment
comment|/* max length of data in RR data field */
end_comment

begin_define
define|#
directive|define
name|MAXDATA
value|(2*MAXDNAME + 5*INT32SZ)
end_define

begin_comment
comment|/* max length of data in a TXT RR segment */
end_comment

begin_define
define|#
directive|define
name|MAXCHARSTRING
value|255
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

begin_define
define|#
directive|define
name|DICT_INDEXBITS
value|24
end_define

begin_define
define|#
directive|define
name|DICT_MAXLENGTH
value|127
end_define

begin_define
define|#
directive|define
name|DICT_INSERT_P
value|0x0001
end_define

begin_comment
comment|/* Average hash chain depths. */
end_comment

begin_define
define|#
directive|define
name|AVGCH_MARSHAL
value|5
end_define

begin_define
define|#
directive|define
name|AVGCH_NLOOKUP
value|3
end_define

begin_comment
comment|/* Nonstandard maximum class to force better packing. */
end_comment

begin_define
define|#
directive|define
name|ZONE_BITS
value|24
end_define

begin_define
define|#
directive|define
name|CLASS_BITS
value|8
end_define

begin_define
define|#
directive|define
name|ZONE_MAX
value|((1<<ZONE_BITS)-1)
end_define

begin_define
define|#
directive|define
name|CLASS_MAX
value|((1<<CLASS_BITS)-1)
end_define

begin_comment
comment|/*  * Hash table structures.  */
end_comment

begin_comment
comment|/*  * XXX  * For IPv6 transport support we need a seperate reference counted  * database of source addresses and d_addr should become a union with  * a pointer into that database.  A bit can be robbed from d_rode to  * indicate what the union is being used for.  This should require less  * memory than making d_addr a union of struct in6_addr and struct in_addr.  */
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
name|struct
name|in_addr
name|d_addr
decl_stmt|;
comment|/* NS from whence this came */
name|u_int32_t
name|d_ttl
decl_stmt|;
comment|/* time to live */
comment|/* if d_zone == DB_Z_CACHE, then 					 * d_ttl is actually the time when 					 * the record will expire. 					 * otherwise (for authoritative 					 * master and slave zones), 					 * d_ttl is the time to live. 					 */
name|unsigned
name|d_zone
range|:
name|ZONE_BITS
decl_stmt|;
comment|/* zone number or 0 for the cache */
name|unsigned
name|d_class
range|:
name|CLASS_BITS
decl_stmt|;
comment|/* class number (nonstandard limit) */
name|unsigned
name|d_flags
range|:
literal|4
decl_stmt|;
comment|/* DB_F_{??????} */
name|unsigned
name|d_secure
range|:
literal|2
decl_stmt|;
comment|/* DB_S_{??????} */
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
name|unsigned
name|d_rcode
range|:
literal|4
decl_stmt|;
comment|/* rcode for negative caching */
name|unsigned
name|d_mark
range|:
literal|3
decl_stmt|;
comment|/* place to mark data */
name|int16_t
name|d_type
decl_stmt|;
comment|/* type number */
name|int16_t
name|d_size
decl_stmt|;
comment|/* size of data area */
name|u_int32_t
name|d_rcnt
decl_stmt|;
ifdef|#
directive|ifdef
name|HITCOUNTS
name|u_int32_t
name|d_hitcnt
decl_stmt|;
comment|/* Number of requests for this data. */
endif|#
directive|endif
comment|/* HITCOUNTS */
name|u_int16_t
name|d_nstime
decl_stmt|;
comment|/* NS response time, milliseconds */
name|u_char
name|d_data
index|[
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
comment|/* dynamic (padded) */
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
value|(sizeof(struct databuf) - sizeof(void*) + n)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HITCOUNTS
end_ifdef

begin_decl_stmt
specifier|extern
name|u_int32_t
name|db_total_hits
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HITCOUNTS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_UPDATE
end_ifdef

begin_comment
comment|/*  * d_mark definitions  */
end_comment

begin_define
define|#
directive|define
name|D_MARK_DELETED
value|0x01
end_define

begin_define
define|#
directive|define
name|D_MARK_ADDED
value|0x02
end_define

begin_define
define|#
directive|define
name|D_MARK_FOUND
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|DB_F_ACTIVE
value|0x02
end_define

begin_comment
comment|/* databuf is linked into a cache */
end_comment

begin_define
define|#
directive|define
name|DB_F_FREE
value|0x04
end_define

begin_comment
comment|/* databuf has been freed */
end_comment

begin_define
define|#
directive|define
name|DB_F_LAME
value|0x08
end_define

begin_comment
comment|/* databuf may refer to lame server */
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

begin_comment
comment|/*  * d_secure definitions  */
end_comment

begin_define
define|#
directive|define
name|DB_S_SECURE
value|2
end_define

begin_comment
comment|/* secure (verified) data */
end_comment

begin_define
define|#
directive|define
name|DB_S_INSECURE
value|1
end_define

begin_comment
comment|/* insecure data */
end_comment

begin_define
define|#
directive|define
name|DB_S_FAILED
value|0
end_define

begin_comment
comment|/* data that failed a security check */
end_comment

begin_struct
struct|struct
name|namebuf
block|{
name|u_int
name|n_hashval
decl_stmt|;
comment|/* hash value of _n_name */
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
name|char
name|_n_name
index|[
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
comment|/* Counted str (dynamic). */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NAMESIZE
parameter_list|(
name|n
parameter_list|)
value|(sizeof(struct namebuf) - sizeof(void*) + 1 + n + 1)
end_define

begin_define
define|#
directive|define
name|NAMELEN
parameter_list|(
name|nb
parameter_list|)
value|(((u_char *)((nb)._n_name))[0])
end_define

begin_define
define|#
directive|define
name|NAME
parameter_list|(
name|nb
parameter_list|)
value|((nb)._n_name + 1)
end_define

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
comment|/* allocated as needed */
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
value|(sizeof(struct hashbuf) + (s-1) * sizeof(struct namebuf *))
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

begin_define
define|#
directive|define
name|HASHROTATE
parameter_list|(
name|v
parameter_list|)
define|\
value|(((v)<< HASHSHIFT) | ((v)>> ((sizeof(v) * 8) - HASHSHIFT)))
end_define

begin_define
define|#
directive|define
name|HASHLOWER
parameter_list|(
name|c
parameter_list|)
value|((isascii(c)&& isupper(c)) ? tolower(c) : (c))
end_define

begin_define
define|#
directive|define
name|HASHIMILATE
parameter_list|(
name|v
parameter_list|,
name|c
parameter_list|)
value|((v) = (HASHROTATE(v)) + (HASHLOWER(c)& HASHMASK))
end_define

begin_define
define|#
directive|define
name|TSIG_BUF_SIZE
value|640
end_define

begin_define
define|#
directive|define
name|TSIG_SIG_SIZE
value|20
end_define

begin_struct
struct|struct
name|tsig_record
block|{
name|u_int8_t
name|sig
index|[
name|TSIG_SIG_SIZE
index|]
decl_stmt|;
name|struct
name|dst_key
modifier|*
name|key
decl_stmt|;
name|int
name|siglen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sig_record
block|{
name|u_int16_t
name|sig_type_n
decl_stmt|;
name|u_int8_t
name|sig_alg_n
decl_stmt|,
name|sig_labels_n
decl_stmt|;
name|u_int32_t
name|sig_ottl_n
decl_stmt|,
name|sig_exp_n
decl_stmt|,
name|sig_time_n
decl_stmt|;
name|u_int16_t
name|sig_keyid_n
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This is the wire format size of "struct sig_record", i.e., no padding. */
end_comment

begin_define
define|#
directive|define
name|SIG_HDR_SIZE
value|18
end_define

begin_struct
struct|struct
name|dnode
block|{
name|struct
name|databuf
modifier|*
name|dp
decl_stmt|;
name|struct
name|dnode
modifier|*
name|dn_next
decl_stmt|;
name|int
name|line
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|dnode
modifier|*
name|dlist
typedef|;
end_typedef

begin_struct
struct|struct
name|db_rrset
block|{
name|dlist
name|rr_list
decl_stmt|;
name|dlist
name|rr_sigs
decl_stmt|;
name|char
modifier|*
name|rr_name
decl_stmt|;
name|int16_t
name|rr_class
decl_stmt|;
name|int16_t
name|rr_type
decl_stmt|;
name|struct
name|db_rrset
modifier|*
name|rr_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DBHASHSIZE
parameter_list|(
name|s
parameter_list|)
value|(sizeof(struct hashbuf) + \ 		       (s-1) * sizeof(struct db_rrset *))
end_define

begin_define
define|#
directive|define
name|SIG_COVERS
parameter_list|(
name|dp
parameter_list|)
value|(ns_get16(dp->d_data))
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
name|DB_MERGE
value|0x40
end_define

begin_comment
comment|/* make no control on rr in db_update (for ixfr) */
end_comment

begin_define
define|#
directive|define
name|DB_REPLACE
value|0x80
end_define

begin_comment
comment|/* replace data if it exists */
end_comment

begin_define
define|#
directive|define
name|DB_Z_CACHE
value|0
end_define

begin_comment
comment|/* cache-zone-only db_dump() */
end_comment

begin_define
define|#
directive|define
name|DB_Z_ALL
value|65535
end_define

begin_comment
comment|/* normal db_dump() */
end_comment

begin_define
define|#
directive|define
name|DB_Z_SPECIAL
parameter_list|(
name|z
parameter_list|)
value|((z) == DB_Z_CACHE || (z) == DB_Z_ALL)
end_define

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
value|(-1)
end_define

begin_define
define|#
directive|define
name|NOCLASS
value|(-2)
end_define

begin_define
define|#
directive|define
name|NOTYPE
value|(-3)
end_define

begin_define
define|#
directive|define
name|NODATA
value|(-4)
end_define

begin_define
define|#
directive|define
name|DATAEXISTS
value|(-5)
end_define

begin_define
define|#
directive|define
name|NODBFILE
value|(-6)
end_define

begin_define
define|#
directive|define
name|TOOMANYZONES
value|(-7)
end_define

begin_define
define|#
directive|define
name|GOODDB
value|(-8)
end_define

begin_define
define|#
directive|define
name|NEWDB
value|(-9)
end_define

begin_define
define|#
directive|define
name|AUTH
value|(-10)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_UPDATE
end_ifdef

begin_define
define|#
directive|define
name|SERIAL
value|(-11)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CNAMEANDOTHER
value|(-12)
end_define

begin_define
define|#
directive|define
name|DNSSECFAIL
value|(-13)
end_define

begin_comment
comment|/* db_set_update */
end_comment

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

begin_comment
comment|/*  * db_load() options  */
end_comment

begin_define
define|#
directive|define
name|ISNOTIXFR
value|0
end_define

begin_define
define|#
directive|define
name|ISIXFR
value|1
end_define

begin_define
define|#
directive|define
name|ISAXFRIXFR
value|2
end_define

begin_comment
comment|/*  * Database access abstractions.  */
end_comment

begin_define
define|#
directive|define
name|foreach_rr
parameter_list|(
name|dp
parameter_list|,
name|np
parameter_list|,
name|ty
parameter_list|,
name|cl
parameter_list|,
name|zn
parameter_list|)
define|\
value|for ((dp) = (np)->n_data; (dp) != NULL; (dp) = (dp)->d_next) \ 		if (!match(dp, (cl), (ty))) \ 			continue; \ 		else if (((zn) == DB_Z_CACHE) \ 			 ? stale(dp) \ 			 : (zn) != (dp)->d_zone) \ 			continue; \ 		else if ((dp)->d_rcode) \ 			continue; \ 		else
end_define

begin_comment
unit|\
comment|/* Caller code follows in sequence. */
end_comment

begin_define
define|#
directive|define
name|DRCNTINC
parameter_list|(
name|x
parameter_list|)
define|\
value|do { \ 		if (++((x)->d_rcnt) == 0) \ 			ns_panic(ns_log_db, 1, "++d_rcnt == 0"); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|DRCNTDEC
parameter_list|(
name|x
parameter_list|)
define|\
value|do { \ 		if (((x)->d_rcnt)-- == 0) \ 			ns_panic(ns_log_db, 1, "d_rcnt-- == 0"); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISVALIDGLUE
parameter_list|(
name|xdp
parameter_list|)
value|((xdp)->d_type == T_NS || (xdp)->d_type == T_A \                          || (xdp)->d_type == T_AAAA || (xdp)->d_type == ns_t_a6)
end_define

end_unit

