begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	%M%	%I%	%E%	*/
end_comment

begin_comment
comment|/*  * sed -- stream  editor  */
end_comment

begin_define
define|#
directive|define
name|CBRA
value|1
end_define

begin_define
define|#
directive|define
name|CCHR
value|2
end_define

begin_define
define|#
directive|define
name|CDOT
value|4
end_define

begin_define
define|#
directive|define
name|CCL
value|6
end_define

begin_define
define|#
directive|define
name|CNL
value|8
end_define

begin_define
define|#
directive|define
name|CDOL
value|10
end_define

begin_define
define|#
directive|define
name|CEOF
value|11
end_define

begin_define
define|#
directive|define
name|CKET
value|12
end_define

begin_define
define|#
directive|define
name|CNULL
value|13
end_define

begin_define
define|#
directive|define
name|CLNUM
value|14
end_define

begin_define
define|#
directive|define
name|CEND
value|16
end_define

begin_define
define|#
directive|define
name|CDONT
value|17
end_define

begin_define
define|#
directive|define
name|CBACK
value|18
end_define

begin_define
define|#
directive|define
name|STAR
value|01
end_define

begin_define
define|#
directive|define
name|NLINES
value|256
end_define

begin_define
define|#
directive|define
name|DEPTH
value|20
end_define

begin_define
define|#
directive|define
name|PTRSIZE
value|200
end_define

begin_define
define|#
directive|define
name|RESIZE
value|10000
end_define

begin_define
define|#
directive|define
name|ABUFSIZE
value|20
end_define

begin_define
define|#
directive|define
name|LBSIZE
value|4000
end_define

begin_define
define|#
directive|define
name|ESIZE
value|256
end_define

begin_define
define|#
directive|define
name|LABSIZE
value|50
end_define

begin_define
define|#
directive|define
name|NBRA
value|9
end_define

begin_decl_stmt
name|FILE
modifier|*
name|fin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|reptr
modifier|*
name|abuf
index|[
name|ABUFSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|reptr
modifier|*
modifier|*
name|aptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|lastre
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ibuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cbp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ebp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|genbuf
index|[
name|LBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|loc1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|loc2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|locs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|seof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|reend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|lbend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|hend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|lcomend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|reptr
modifier|*
name|ptrend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dolflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|jflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|numbra
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|delflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|lnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|linebuf
index|[
name|LBSIZE
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|holdsp
index|[
name|LBSIZE
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|spend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|hspend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|braelist
index|[
name|NBRA
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|braslist
index|[
name|NBRA
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|tlno
index|[
name|NLINES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nlno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|fname
index|[
literal|12
index|]
index|[
literal|40
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|fcode
index|[
literal|12
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfiles
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ACOM
value|01
end_define

begin_define
define|#
directive|define
name|BCOM
value|020
end_define

begin_define
define|#
directive|define
name|CCOM
value|02
end_define

begin_define
define|#
directive|define
name|CDCOM
value|025
end_define

begin_define
define|#
directive|define
name|CNCOM
value|022
end_define

begin_define
define|#
directive|define
name|COCOM
value|017
end_define

begin_define
define|#
directive|define
name|CPCOM
value|023
end_define

begin_define
define|#
directive|define
name|DCOM
value|03
end_define

begin_define
define|#
directive|define
name|ECOM
value|015
end_define

begin_define
define|#
directive|define
name|EQCOM
value|013
end_define

begin_define
define|#
directive|define
name|FCOM
value|016
end_define

begin_define
define|#
directive|define
name|GCOM
value|027
end_define

begin_define
define|#
directive|define
name|CGCOM
value|030
end_define

begin_define
define|#
directive|define
name|HCOM
value|031
end_define

begin_define
define|#
directive|define
name|CHCOM
value|032
end_define

begin_define
define|#
directive|define
name|ICOM
value|04
end_define

begin_define
define|#
directive|define
name|LCOM
value|05
end_define

begin_define
define|#
directive|define
name|NCOM
value|012
end_define

begin_define
define|#
directive|define
name|PCOM
value|010
end_define

begin_define
define|#
directive|define
name|QCOM
value|011
end_define

begin_define
define|#
directive|define
name|RCOM
value|06
end_define

begin_define
define|#
directive|define
name|SCOM
value|07
end_define

begin_define
define|#
directive|define
name|TCOM
value|021
end_define

begin_define
define|#
directive|define
name|WCOM
value|014
end_define

begin_define
define|#
directive|define
name|CWCOM
value|024
end_define

begin_define
define|#
directive|define
name|YCOM
value|026
end_define

begin_define
define|#
directive|define
name|XCOM
value|033
end_define

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|reend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|lbend
decl_stmt|;
end_decl_stmt

begin_union
union|union
name|reptr
block|{
struct|struct
name|reptr1
block|{
name|char
modifier|*
name|ad1
decl_stmt|;
name|char
modifier|*
name|ad2
decl_stmt|;
name|char
modifier|*
name|re1
decl_stmt|;
name|char
modifier|*
name|rhs
decl_stmt|;
name|FILE
modifier|*
name|fcode
decl_stmt|;
name|char
name|command
decl_stmt|;
name|char
name|gfl
decl_stmt|;
name|char
name|pfl
decl_stmt|;
name|char
name|inar
decl_stmt|;
name|char
name|negfl
decl_stmt|;
block|}
name|A
struct|;
struct|struct
name|reptr2
block|{
name|char
modifier|*
name|ad1
decl_stmt|;
name|char
modifier|*
name|ad2
decl_stmt|;
name|union
name|reptr
modifier|*
name|lb1
decl_stmt|;
name|char
modifier|*
name|rhs
decl_stmt|;
name|FILE
modifier|*
name|fcode
decl_stmt|;
name|char
name|command
decl_stmt|;
name|char
name|gfl
decl_stmt|;
name|char
name|pfl
decl_stmt|;
name|char
name|inar
decl_stmt|;
name|char
name|negfl
decl_stmt|;
block|}
name|B
struct|;
block|}
name|ptrspace
index|[
name|PTRSIZE
index|]
union|,
modifier|*
name|rep
union|;
end_union

begin_decl_stmt
name|char
name|respace
index|[
name|RESIZE
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|label
block|{
name|char
name|asc
index|[
literal|9
index|]
decl_stmt|;
name|union
name|reptr
modifier|*
name|chain
decl_stmt|;
name|union
name|reptr
modifier|*
name|address
decl_stmt|;
block|}
name|ltab
index|[
name|LABSIZE
index|]
struct|;
end_struct

begin_decl_stmt
name|struct
name|label
modifier|*
name|lab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|label
modifier|*
name|labend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|depth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|eargv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|bittab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|reptr
modifier|*
modifier|*
name|cmpend
index|[
name|DEPTH
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|depth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|reptr
modifier|*
name|pending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|badp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|bad
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|compile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ycomp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|address
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|text
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|compsub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|label
modifier|*
name|search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|gline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|place
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|compfl
decl_stmt|;
end_decl_stmt

end_unit

