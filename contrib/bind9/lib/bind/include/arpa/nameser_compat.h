begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1983, 1989  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  *      from nameser.h	8.1 (Berkeley) 6/2/93  *	$Id: nameser_compat.h,v 1.1.2.3.4.3 2006/05/19 02:38:15 marka Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARPA_NAMESER_COMPAT_
end_ifndef

begin_define
define|#
directive|define
name|_ARPA_NAMESER_COMPAT_
end_define

begin_define
define|#
directive|define
name|__BIND
value|19950621
end_define

begin_comment
comment|/* (DEAD) interface version stamp. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_if
if|#
directive|if
operator|(
name|BSD
operator|>=
literal|199103
operator|)
end_if

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__linux
end_ifdef

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_comment
comment|/* least-significant byte first (vax, pc) */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* most-significant byte first (IBM, net) */
end_comment

begin_define
define|#
directive|define
name|PDP_ENDIAN
value|3412
end_define

begin_comment
comment|/* LSB first in word, MSW first in long (pdp)*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|ns32000
argument_list|)
operator|||
name|defined
argument_list|(
name|sun386
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPSEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_MIPSEL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|BIT_ZERO_ON_RIGHT
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__Lynx__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__x86__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sel
argument_list|)
operator|||
name|defined
argument_list|(
name|pyr
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68000
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|is68k
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|||
name|defined
argument_list|(
name|ibm032
argument_list|)
operator|||
name|defined
argument_list|(
name|ibm370
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MIPSEB
argument_list|)
operator|||
name|defined
argument_list|(
name|_MIPSEB
argument_list|)
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
operator|||
name|defined
argument_list|(
name|DGUX
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|apollo
argument_list|)
operator|||
name|defined
argument_list|(
name|__convex__
argument_list|)
operator|||
name|defined
argument_list|(
name|_CRAY
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__hppa
argument_list|)
operator|||
name|defined
argument_list|(
name|__hp9000
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__hp9000s300
argument_list|)
operator|||
name|defined
argument_list|(
name|__hp9000s700
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__hp3000s900
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|MPE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|BIT_ZERO_ON_LEFT
argument_list|)
operator|||
name|defined
argument_list|(
name|m68k
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__Lynx__
argument_list|)
operator|&&
expr|\
operator|(
name|defined
argument_list|(
name|__68k__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
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
comment|/* __linux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|||
expr|\
operator|(
name|BYTE_ORDER
operator|!=
name|BIG_ENDIAN
operator|&&
name|BYTE_ORDER
operator|!=
name|LITTLE_ENDIAN
operator|&&
expr|\
name|BYTE_ORDER
operator|!=
name|PDP_ENDIAN
operator|)
end_if

begin_comment
comment|/* you must determine what the correct bit order is for 	 * your compiler - the next line is an intentional error 	 * which will force your compiles to bomb until you fix 	 * the above macros. 	 */
end_comment

begin_expr_stmt
name|error
literal|"Undefined or invalid BYTE_ORDER"
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure for query header.  The order of the fields is machine- and  * compiler-dependent, depending on the byte/bit order and the layout  * of bit fields.  We use bit fields only in int variables, as this  * is all ANSI requires.  This requires a somewhat confusing rearrangement.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|id
range|:
literal|16
decl_stmt|;
comment|/* query identification number */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
comment|/* fields in third byte */
name|unsigned
name|qr
range|:
literal|1
decl_stmt|;
comment|/* response flag */
name|unsigned
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* purpose of message */
name|unsigned
name|aa
range|:
literal|1
decl_stmt|;
comment|/* authoritive answer */
name|unsigned
name|tc
range|:
literal|1
decl_stmt|;
comment|/* truncated message */
name|unsigned
name|rd
range|:
literal|1
decl_stmt|;
comment|/* recursion desired */
comment|/* fields in fourth byte */
name|unsigned
name|ra
range|:
literal|1
decl_stmt|;
comment|/* recursion available */
name|unsigned
name|unused
range|:
literal|1
decl_stmt|;
comment|/* unused bits (MBZ as of 4.9.3a3) */
name|unsigned
name|ad
range|:
literal|1
decl_stmt|;
comment|/* authentic data from named */
name|unsigned
name|cd
range|:
literal|1
decl_stmt|;
comment|/* checking disabled by resolver */
name|unsigned
name|rcode
range|:
literal|4
decl_stmt|;
comment|/* response code */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|||
name|BYTE_ORDER
operator|==
name|PDP_ENDIAN
comment|/* fields in third byte */
name|unsigned
name|rd
range|:
literal|1
decl_stmt|;
comment|/* recursion desired */
name|unsigned
name|tc
range|:
literal|1
decl_stmt|;
comment|/* truncated message */
name|unsigned
name|aa
range|:
literal|1
decl_stmt|;
comment|/* authoritive answer */
name|unsigned
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* purpose of message */
name|unsigned
name|qr
range|:
literal|1
decl_stmt|;
comment|/* response flag */
comment|/* fields in fourth byte */
name|unsigned
name|rcode
range|:
literal|4
decl_stmt|;
comment|/* response code */
name|unsigned
name|cd
range|:
literal|1
decl_stmt|;
comment|/* checking disabled by resolver */
name|unsigned
name|ad
range|:
literal|1
decl_stmt|;
comment|/* authentic data from named */
name|unsigned
name|unused
range|:
literal|1
decl_stmt|;
comment|/* unused bits (MBZ as of 4.9.3a3) */
name|unsigned
name|ra
range|:
literal|1
decl_stmt|;
comment|/* recursion available */
endif|#
directive|endif
comment|/* remaining bytes */
name|unsigned
name|qdcount
range|:
literal|16
decl_stmt|;
comment|/* number of question entries */
name|unsigned
name|ancount
range|:
literal|16
decl_stmt|;
comment|/* number of answer entries */
name|unsigned
name|nscount
range|:
literal|16
decl_stmt|;
comment|/* number of authority entries */
name|unsigned
name|arcount
range|:
literal|16
decl_stmt|;
comment|/* number of resource entries */
block|}
name|HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PACKETSZ
value|NS_PACKETSZ
end_define

begin_define
define|#
directive|define
name|MAXDNAME
value|NS_MAXDNAME
end_define

begin_define
define|#
directive|define
name|MAXCDNAME
value|NS_MAXCDNAME
end_define

begin_define
define|#
directive|define
name|MAXLABEL
value|NS_MAXLABEL
end_define

begin_define
define|#
directive|define
name|HFIXEDSZ
value|NS_HFIXEDSZ
end_define

begin_define
define|#
directive|define
name|QFIXEDSZ
value|NS_QFIXEDSZ
end_define

begin_define
define|#
directive|define
name|RRFIXEDSZ
value|NS_RRFIXEDSZ
end_define

begin_define
define|#
directive|define
name|INT32SZ
value|NS_INT32SZ
end_define

begin_define
define|#
directive|define
name|INT16SZ
value|NS_INT16SZ
end_define

begin_define
define|#
directive|define
name|INT8SZ
value|NS_INT8SZ
end_define

begin_define
define|#
directive|define
name|INADDRSZ
value|NS_INADDRSZ
end_define

begin_define
define|#
directive|define
name|IN6ADDRSZ
value|NS_IN6ADDRSZ
end_define

begin_define
define|#
directive|define
name|INDIR_MASK
value|NS_CMPRSFLGS
end_define

begin_define
define|#
directive|define
name|NAMESERVER_PORT
value|NS_DEFAULTPORT
end_define

begin_define
define|#
directive|define
name|S_ZONE
value|ns_s_zn
end_define

begin_define
define|#
directive|define
name|S_PREREQ
value|ns_s_pr
end_define

begin_define
define|#
directive|define
name|S_UPDATE
value|ns_s_ud
end_define

begin_define
define|#
directive|define
name|S_ADDT
value|ns_s_ar
end_define

begin_define
define|#
directive|define
name|QUERY
value|ns_o_query
end_define

begin_define
define|#
directive|define
name|IQUERY
value|ns_o_iquery
end_define

begin_define
define|#
directive|define
name|STATUS
value|ns_o_status
end_define

begin_define
define|#
directive|define
name|NS_NOTIFY_OP
value|ns_o_notify
end_define

begin_define
define|#
directive|define
name|NS_UPDATE_OP
value|ns_o_update
end_define

begin_define
define|#
directive|define
name|NOERROR
value|ns_r_noerror
end_define

begin_define
define|#
directive|define
name|FORMERR
value|ns_r_formerr
end_define

begin_define
define|#
directive|define
name|SERVFAIL
value|ns_r_servfail
end_define

begin_define
define|#
directive|define
name|NXDOMAIN
value|ns_r_nxdomain
end_define

begin_define
define|#
directive|define
name|NOTIMP
value|ns_r_notimpl
end_define

begin_define
define|#
directive|define
name|REFUSED
value|ns_r_refused
end_define

begin_define
define|#
directive|define
name|YXDOMAIN
value|ns_r_yxdomain
end_define

begin_define
define|#
directive|define
name|YXRRSET
value|ns_r_yxrrset
end_define

begin_define
define|#
directive|define
name|NXRRSET
value|ns_r_nxrrset
end_define

begin_define
define|#
directive|define
name|NOTAUTH
value|ns_r_notauth
end_define

begin_define
define|#
directive|define
name|NOTZONE
value|ns_r_notzone
end_define

begin_comment
comment|/*#define BADSIG		ns_r_badsig*/
end_comment

begin_comment
comment|/*#define BADKEY		ns_r_badkey*/
end_comment

begin_comment
comment|/*#define BADTIME		ns_r_badtime*/
end_comment

begin_define
define|#
directive|define
name|DELETE
value|ns_uop_delete
end_define

begin_define
define|#
directive|define
name|ADD
value|ns_uop_add
end_define

begin_define
define|#
directive|define
name|T_A
value|ns_t_a
end_define

begin_define
define|#
directive|define
name|T_NS
value|ns_t_ns
end_define

begin_define
define|#
directive|define
name|T_MD
value|ns_t_md
end_define

begin_define
define|#
directive|define
name|T_MF
value|ns_t_mf
end_define

begin_define
define|#
directive|define
name|T_CNAME
value|ns_t_cname
end_define

begin_define
define|#
directive|define
name|T_SOA
value|ns_t_soa
end_define

begin_define
define|#
directive|define
name|T_MB
value|ns_t_mb
end_define

begin_define
define|#
directive|define
name|T_MG
value|ns_t_mg
end_define

begin_define
define|#
directive|define
name|T_MR
value|ns_t_mr
end_define

begin_define
define|#
directive|define
name|T_NULL
value|ns_t_null
end_define

begin_define
define|#
directive|define
name|T_WKS
value|ns_t_wks
end_define

begin_define
define|#
directive|define
name|T_PTR
value|ns_t_ptr
end_define

begin_define
define|#
directive|define
name|T_HINFO
value|ns_t_hinfo
end_define

begin_define
define|#
directive|define
name|T_MINFO
value|ns_t_minfo
end_define

begin_define
define|#
directive|define
name|T_MX
value|ns_t_mx
end_define

begin_define
define|#
directive|define
name|T_TXT
value|ns_t_txt
end_define

begin_define
define|#
directive|define
name|T_RP
value|ns_t_rp
end_define

begin_define
define|#
directive|define
name|T_AFSDB
value|ns_t_afsdb
end_define

begin_define
define|#
directive|define
name|T_X25
value|ns_t_x25
end_define

begin_define
define|#
directive|define
name|T_ISDN
value|ns_t_isdn
end_define

begin_define
define|#
directive|define
name|T_RT
value|ns_t_rt
end_define

begin_define
define|#
directive|define
name|T_NSAP
value|ns_t_nsap
end_define

begin_define
define|#
directive|define
name|T_NSAP_PTR
value|ns_t_nsap_ptr
end_define

begin_define
define|#
directive|define
name|T_SIG
value|ns_t_sig
end_define

begin_define
define|#
directive|define
name|T_KEY
value|ns_t_key
end_define

begin_define
define|#
directive|define
name|T_PX
value|ns_t_px
end_define

begin_define
define|#
directive|define
name|T_GPOS
value|ns_t_gpos
end_define

begin_define
define|#
directive|define
name|T_AAAA
value|ns_t_aaaa
end_define

begin_define
define|#
directive|define
name|T_LOC
value|ns_t_loc
end_define

begin_define
define|#
directive|define
name|T_NXT
value|ns_t_nxt
end_define

begin_define
define|#
directive|define
name|T_EID
value|ns_t_eid
end_define

begin_define
define|#
directive|define
name|T_NIMLOC
value|ns_t_nimloc
end_define

begin_define
define|#
directive|define
name|T_SRV
value|ns_t_srv
end_define

begin_define
define|#
directive|define
name|T_ATMA
value|ns_t_atma
end_define

begin_define
define|#
directive|define
name|T_NAPTR
value|ns_t_naptr
end_define

begin_define
define|#
directive|define
name|T_A6
value|ns_t_a6
end_define

begin_define
define|#
directive|define
name|T_TSIG
value|ns_t_tsig
end_define

begin_define
define|#
directive|define
name|T_IXFR
value|ns_t_ixfr
end_define

begin_define
define|#
directive|define
name|T_AXFR
value|ns_t_axfr
end_define

begin_define
define|#
directive|define
name|T_MAILB
value|ns_t_mailb
end_define

begin_define
define|#
directive|define
name|T_MAILA
value|ns_t_maila
end_define

begin_define
define|#
directive|define
name|T_ANY
value|ns_t_any
end_define

begin_define
define|#
directive|define
name|C_IN
value|ns_c_in
end_define

begin_define
define|#
directive|define
name|C_CHAOS
value|ns_c_chaos
end_define

begin_define
define|#
directive|define
name|C_HS
value|ns_c_hs
end_define

begin_comment
comment|/* BIND_UPDATE */
end_comment

begin_define
define|#
directive|define
name|C_NONE
value|ns_c_none
end_define

begin_define
define|#
directive|define
name|C_ANY
value|ns_c_any
end_define

begin_define
define|#
directive|define
name|GETSHORT
value|NS_GET16
end_define

begin_define
define|#
directive|define
name|GETLONG
value|NS_GET32
end_define

begin_define
define|#
directive|define
name|PUTSHORT
value|NS_PUT16
end_define

begin_define
define|#
directive|define
name|PUTLONG
value|NS_PUT32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARPA_NAMESER_COMPAT_ */
end_comment

end_unit

