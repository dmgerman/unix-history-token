begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sgmldecl.h: SGML declaration parsing. */
end_comment

begin_define
define|#
directive|define
name|QATTCNT
value|0
end_define

begin_define
define|#
directive|define
name|QATTSPLEN
value|1
end_define

begin_define
define|#
directive|define
name|QBSEQLEN
value|2
end_define

begin_define
define|#
directive|define
name|QDTAGLEN
value|3
end_define

begin_define
define|#
directive|define
name|QDTEMPLEN
value|4
end_define

begin_define
define|#
directive|define
name|QENTLVL
value|5
end_define

begin_define
define|#
directive|define
name|QGRPCNT
value|6
end_define

begin_define
define|#
directive|define
name|QGRPGTCNT
value|7
end_define

begin_define
define|#
directive|define
name|QGRPLVL
value|8
end_define

begin_define
define|#
directive|define
name|QLITLEN
value|9
end_define

begin_define
define|#
directive|define
name|QNAMELEN
value|10
end_define

begin_define
define|#
directive|define
name|QNORMSEP
value|11
end_define

begin_define
define|#
directive|define
name|QPILEN
value|12
end_define

begin_define
define|#
directive|define
name|QTAGLEN
value|13
end_define

begin_define
define|#
directive|define
name|QTAGLVL
value|14
end_define

begin_define
define|#
directive|define
name|NQUANTITY
value|(QTAGLVL+1)
end_define

begin_define
define|#
directive|define
name|TOTALCAP
value|0
end_define

begin_define
define|#
directive|define
name|ENTCAP
value|1
end_define

begin_define
define|#
directive|define
name|ENTCHCAP
value|2
end_define

begin_define
define|#
directive|define
name|ELEMCAP
value|3
end_define

begin_define
define|#
directive|define
name|GRPCAP
value|4
end_define

begin_define
define|#
directive|define
name|EXGRPCAP
value|5
end_define

begin_define
define|#
directive|define
name|EXNMCAP
value|6
end_define

begin_define
define|#
directive|define
name|ATTCAP
value|7
end_define

begin_define
define|#
directive|define
name|ATTCHCAP
value|8
end_define

begin_define
define|#
directive|define
name|AVGRPCAP
value|9
end_define

begin_define
define|#
directive|define
name|NOTCAP
value|10
end_define

begin_define
define|#
directive|define
name|NOTCHCAP
value|11
end_define

begin_define
define|#
directive|define
name|IDCAP
value|12
end_define

begin_define
define|#
directive|define
name|IDREFCAP
value|13
end_define

begin_define
define|#
directive|define
name|MAPCAP
value|14
end_define

begin_define
define|#
directive|define
name|LKSETCAP
value|15
end_define

begin_define
define|#
directive|define
name|LKNMCAP
value|16
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|captab
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|sgmldecl
block|{
name|long
name|capacity
index|[
name|NCAPACITY
index|]
decl_stmt|;
name|long
name|subdoc
decl_stmt|;
name|UNCH
name|formal
decl_stmt|;
name|UNCH
name|omittag
decl_stmt|;
name|UNCH
name|shorttag
decl_stmt|;
name|UNCH
name|shortref
decl_stmt|;
name|UNCH
name|namecase
index|[
literal|2
index|]
decl_stmt|;
comment|/* case translation of general/entity names */
name|int
name|quantity
index|[
name|NQUANTITY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|sgmldecl
name|sd
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OMITTAG
value|(sd.omittag)
end_define

begin_define
define|#
directive|define
name|SUBDOC
value|(sd.subdoc)
end_define

begin_define
define|#
directive|define
name|SHORTTAG
value|(sd.shorttag)
end_define

begin_define
define|#
directive|define
name|FORMAL
value|(sd.formal)
end_define

begin_define
define|#
directive|define
name|ATTCNT
value|(sd.quantity[QATTCNT])
end_define

begin_define
define|#
directive|define
name|ATTSPLEN
value|(sd.quantity[QATTSPLEN])
end_define

begin_define
define|#
directive|define
name|BSEQLEN
value|(sd.quantity[QBSEQLEN])
end_define

begin_define
define|#
directive|define
name|ENTLVL
value|(sd.quantity[QENTLVL])
end_define

begin_define
define|#
directive|define
name|GRPGTCNT
value|(sd.quantity[QGRPGTCNT])
end_define

begin_define
define|#
directive|define
name|GRPCNT
value|(sd.quantity[QGRPCNT])
end_define

begin_define
define|#
directive|define
name|GRPLVL
value|(sd.quantity[QGRPLVL])
end_define

begin_define
define|#
directive|define
name|LITLEN
value|(sd.quantity[QLITLEN])
end_define

begin_define
define|#
directive|define
name|NAMELEN
value|(sd.quantity[QNAMELEN])
end_define

begin_define
define|#
directive|define
name|NORMSEP
value|(sd.quantity[QNORMSEP])
end_define

begin_define
define|#
directive|define
name|PILEN
value|(sd.quantity[QPILEN])
end_define

begin_define
define|#
directive|define
name|TAGLEN
value|(sd.quantity[QTAGLEN])
end_define

begin_define
define|#
directive|define
name|TAGLVL
value|(sd.quantity[QTAGLVL])
end_define

begin_define
define|#
directive|define
name|NAMECASE
value|(sd.namecase[0])
end_define

begin_define
define|#
directive|define
name|ENTCASE
value|(sd.namecase[1])
end_define

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_define
define|#
directive|define
name|UNUSED
value|-1
end_define

begin_define
define|#
directive|define
name|UNKNOWN
value|-2
end_define

begin_define
define|#
directive|define
name|UNDESC
value|-3
end_define

begin_define
define|#
directive|define
name|UNKNOWN_SET
value|-4
end_define

begin_decl_stmt
specifier|extern
name|int
name|iso646charset
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iso646G0charset
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iso646C0charset
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iso8859_1charset
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iso6429C1charset
index|[]
decl_stmt|;
end_decl_stmt

end_unit

