begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)nameser.h	5.11 (Berkeley) 2/14/86  */
end_comment

begin_comment
comment|/*  * Define constants based on rfc883  */
end_comment

begin_define
define|#
directive|define
name|PACKETSZ
value|512
end_define

begin_comment
comment|/* maximum packet size */
end_comment

begin_define
define|#
directive|define
name|MAXDNAME
value|256
end_define

begin_comment
comment|/* maximum domain name */
end_comment

begin_define
define|#
directive|define
name|MAXCDNAME
value|255
end_define

begin_comment
comment|/* maximum compressed domain name */
end_comment

begin_define
define|#
directive|define
name|MAXLABEL
value|63
end_define

begin_comment
comment|/* maximum length of domain label */
end_comment

begin_comment
comment|/* Number of bytes of fixed size data in query structure */
end_comment

begin_define
define|#
directive|define
name|QFIXEDSZ
value|4
end_define

begin_comment
comment|/* number of bytes of fixed size data in resource record */
end_comment

begin_define
define|#
directive|define
name|RRFIXEDSZ
value|10
end_define

begin_comment
comment|/*  * Internet nameserver port number  */
end_comment

begin_define
define|#
directive|define
name|NAMESERVER_PORT
value|53
end_define

begin_comment
comment|/*  * Currently defined opcodes  */
end_comment

begin_define
define|#
directive|define
name|QUERY
value|0
end_define

begin_comment
comment|/* standard query */
end_comment

begin_define
define|#
directive|define
name|IQUERY
value|1
end_define

begin_comment
comment|/* inverse query */
end_comment

begin_define
define|#
directive|define
name|CQUERYM
value|2
end_define

begin_comment
comment|/* completion query (multiple) */
end_comment

begin_define
define|#
directive|define
name|CQUERYU
value|3
end_define

begin_comment
comment|/* completion query (unique) */
end_comment

begin_comment
comment|/* non standard */
end_comment

begin_define
define|#
directive|define
name|UPDATEA
value|100
end_define

begin_comment
comment|/* add resource record */
end_comment

begin_define
define|#
directive|define
name|UPDATED
value|101
end_define

begin_comment
comment|/* delete resource record */
end_comment

begin_define
define|#
directive|define
name|UPDATEM
value|102
end_define

begin_comment
comment|/* modify resource record */
end_comment

begin_define
define|#
directive|define
name|ZONEINIT
value|103
end_define

begin_comment
comment|/* initial zone transfer */
end_comment

begin_define
define|#
directive|define
name|ZONEREF
value|104
end_define

begin_comment
comment|/* incremental zone referesh */
end_comment

begin_comment
comment|/*  * Currently defined response codes  */
end_comment

begin_define
define|#
directive|define
name|NOERROR
value|0
end_define

begin_comment
comment|/* no error */
end_comment

begin_define
define|#
directive|define
name|FORMERR
value|1
end_define

begin_comment
comment|/* format error */
end_comment

begin_define
define|#
directive|define
name|SERVFAIL
value|2
end_define

begin_comment
comment|/* server failure */
end_comment

begin_define
define|#
directive|define
name|NXDOMAIN
value|3
end_define

begin_comment
comment|/* non existent domain */
end_comment

begin_define
define|#
directive|define
name|NOTIMP
value|4
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|REFUSED
value|5
end_define

begin_comment
comment|/* query refused */
end_comment

begin_comment
comment|/* non standard */
end_comment

begin_define
define|#
directive|define
name|NOCHANGE
value|100
end_define

begin_comment
comment|/* update failed to change db */
end_comment

begin_comment
comment|/*  * Type values for resources and queries  */
end_comment

begin_define
define|#
directive|define
name|T_A
value|1
end_define

begin_comment
comment|/* host address */
end_comment

begin_define
define|#
directive|define
name|T_NS
value|2
end_define

begin_comment
comment|/* authoritative server */
end_comment

begin_define
define|#
directive|define
name|T_MD
value|3
end_define

begin_comment
comment|/* mail destination */
end_comment

begin_define
define|#
directive|define
name|T_MF
value|4
end_define

begin_comment
comment|/* mail forwarder */
end_comment

begin_define
define|#
directive|define
name|T_CNAME
value|5
end_define

begin_comment
comment|/* connonical name */
end_comment

begin_define
define|#
directive|define
name|T_SOA
value|6
end_define

begin_comment
comment|/* start of authority zone */
end_comment

begin_define
define|#
directive|define
name|T_MB
value|7
end_define

begin_comment
comment|/* mailbox domain name */
end_comment

begin_define
define|#
directive|define
name|T_MG
value|8
end_define

begin_comment
comment|/* mail group member */
end_comment

begin_define
define|#
directive|define
name|T_MR
value|9
end_define

begin_comment
comment|/* mail rename name */
end_comment

begin_define
define|#
directive|define
name|T_NULL
value|10
end_define

begin_comment
comment|/* null resource record */
end_comment

begin_define
define|#
directive|define
name|T_WKS
value|11
end_define

begin_comment
comment|/* well known service */
end_comment

begin_define
define|#
directive|define
name|T_PTR
value|12
end_define

begin_comment
comment|/* domain name pointer */
end_comment

begin_define
define|#
directive|define
name|T_HINFO
value|13
end_define

begin_comment
comment|/* host information */
end_comment

begin_define
define|#
directive|define
name|T_MINFO
value|14
end_define

begin_comment
comment|/* mailbox information */
end_comment

begin_define
define|#
directive|define
name|T_MX
value|15
end_define

begin_comment
comment|/* mail routing information */
end_comment

begin_comment
comment|/* non standard */
end_comment

begin_define
define|#
directive|define
name|T_UINFO
value|100
end_define

begin_comment
comment|/* user (finger) information */
end_comment

begin_define
define|#
directive|define
name|T_UID
value|101
end_define

begin_comment
comment|/* user ID */
end_comment

begin_define
define|#
directive|define
name|T_GID
value|102
end_define

begin_comment
comment|/* group ID */
end_comment

begin_comment
comment|/* Query type values which do not appear in resource records */
end_comment

begin_define
define|#
directive|define
name|T_AXFR
value|252
end_define

begin_comment
comment|/* transfer zone of authority */
end_comment

begin_define
define|#
directive|define
name|T_MAILB
value|253
end_define

begin_comment
comment|/* transfer mailbox records */
end_comment

begin_define
define|#
directive|define
name|T_MAILA
value|254
end_define

begin_comment
comment|/* transfer mail agent records */
end_comment

begin_define
define|#
directive|define
name|T_ANY
value|255
end_define

begin_comment
comment|/* wildcard match */
end_comment

begin_comment
comment|/*  * Values for class field  */
end_comment

begin_define
define|#
directive|define
name|C_IN
value|1
end_define

begin_comment
comment|/* the arpa internet */
end_comment

begin_define
define|#
directive|define
name|C_CHAOS
value|3
end_define

begin_comment
comment|/* for chaos net at MIT */
end_comment

begin_comment
comment|/* Query class values which do not appear in resource records */
end_comment

begin_define
define|#
directive|define
name|C_ANY
value|255
end_define

begin_comment
comment|/* wildcard match */
end_comment

begin_comment
comment|/*  * Structure for query header, the order of the fields is machine and  * compiler dependent, in our case, the bits within a byte are assignd   * least significant first, while the order of transmition is most   * significant first.  This requires a somewhat confusing rearrangement.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|id
decl_stmt|;
comment|/* query identification number */
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
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
name|is68k
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|||
name|defined
argument_list|(
name|BIT_ZERO_ON_LEFT
argument_list|)
comment|/* Bit zero on left:  Gould and similar architectures */
comment|/* fields in third byte */
name|u_char
name|qr
range|:
literal|1
decl_stmt|;
comment|/* response flag */
name|u_char
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* purpose of message */
name|u_char
name|aa
range|:
literal|1
decl_stmt|;
comment|/* authoritive answer */
name|u_char
name|tc
range|:
literal|1
decl_stmt|;
comment|/* truncated message */
name|u_char
name|rd
range|:
literal|1
decl_stmt|;
comment|/* recursion desired */
comment|/* fields in fourth byte */
name|u_char
name|ra
range|:
literal|1
decl_stmt|;
comment|/* recursion available */
name|u_char
name|pr
range|:
literal|1
decl_stmt|;
comment|/* primary server required (non standard) */
name|u_char
name|unused
range|:
literal|2
decl_stmt|;
comment|/* unused bits */
name|u_char
name|rcode
range|:
literal|4
decl_stmt|;
comment|/* response code */
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|BIT_ZERO_ON_RIGHT
argument_list|)
comment|/* Bit zero on right:  VAX */
comment|/* fields in third byte */
name|u_char
name|rd
range|:
literal|1
decl_stmt|;
comment|/* recursion desired */
name|u_char
name|tc
range|:
literal|1
decl_stmt|;
comment|/* truncated message */
name|u_char
name|aa
range|:
literal|1
decl_stmt|;
comment|/* authoritive answer */
name|u_char
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* purpose of message */
name|u_char
name|qr
range|:
literal|1
decl_stmt|;
comment|/* response flag */
comment|/* fields in fourth byte */
name|u_char
name|rcode
range|:
literal|4
decl_stmt|;
comment|/* response code */
name|u_char
name|unused
range|:
literal|2
decl_stmt|;
comment|/* unused bits */
name|u_char
name|pr
range|:
literal|1
decl_stmt|;
comment|/* primary server required (non standard) */
name|u_char
name|ra
range|:
literal|1
decl_stmt|;
comment|/* recursion available */
else|#
directive|else
comment|/* you must determine what the correct bit order is for your compiler */
name|UNDEFINED_BIT_ORDER
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* remaining bytes */
name|u_short
name|qdcount
decl_stmt|;
comment|/* number of question entries */
name|u_short
name|ancount
decl_stmt|;
comment|/* number of answer entries */
name|u_short
name|nscount
decl_stmt|;
comment|/* number of authority entries */
name|u_short
name|arcount
decl_stmt|;
comment|/* number of resource entries */
block|}
name|HEADER
typedef|;
end_typedef

begin_comment
comment|/*  * Defines for handling compressed domain names  */
end_comment

begin_define
define|#
directive|define
name|INDIR_MASK
value|0xc0
end_define

begin_comment
comment|/*  * Structure for passing resource records around.  */
end_comment

begin_struct
struct|struct
name|rrec
block|{
name|short
name|r_zone
decl_stmt|;
comment|/* zone number */
name|short
name|r_class
decl_stmt|;
comment|/* class number */
name|short
name|r_type
decl_stmt|;
comment|/* type number */
name|u_long
name|r_ttl
decl_stmt|;
comment|/* time to live */
name|int
name|r_size
decl_stmt|;
comment|/* size of data area */
name|char
modifier|*
name|r_data
decl_stmt|;
comment|/* pointer to data */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|u_short
name|getshort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|getlong
parameter_list|()
function_decl|;
end_function_decl

end_unit

