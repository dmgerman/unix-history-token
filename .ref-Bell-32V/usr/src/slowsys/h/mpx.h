begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|M
value|3
end_define

begin_define
define|#
directive|define
name|C
value|100
end_define

begin_comment
comment|/*  * character Q structure  */
end_comment

begin_struct
struct|struct
name|clist
block|{
name|int
name|c_cc
decl_stmt|;
name|int
name|c_cf
decl_stmt|;
name|int
name|c_cl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|chan
block|{
name|char
name|cflag
decl_stmt|;
name|char
name|m
decl_stmt|,
name|c
decl_stmt|;
name|struct
name|chan
modifier|*
name|dest
decl_stmt|;
name|struct
name|clist
name|ioq
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* c flags */
end_comment

begin_define
define|#
directive|define
name|BLOCK
value|01
end_define

begin_struct
struct|struct
name|line
block|{
name|char
name|xbuf
index|[
literal|24
operator|+
literal|2
index|]
decl_stmt|;
name|char
name|rbuf
index|[
literal|100
operator|+
literal|2
index|]
decl_stmt|;
name|char
name|rseq
decl_stmt|;
name|char
name|xseq
decl_stmt|;
name|char
name|ackf
decl_stmt|;
name|char
name|xflag
decl_stmt|;
name|char
name|state
decl_stmt|;
name|char
name|time
decl_stmt|;
name|int
name|sum
decl_stmt|;
name|char
modifier|*
name|ip
decl_stmt|;
name|char
modifier|*
name|ep
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WWAIT
value|02
end_define

begin_define
define|#
directive|define
name|CRUN
value|04
end_define

begin_define
define|#
directive|define
name|RWAIT
value|010
end_define

begin_define
define|#
directive|define
name|ALLOC
value|020
end_define

begin_define
define|#
directive|define
name|DIS
value|040
end_define

begin_define
define|#
directive|define
name|DLY
value|0100
end_define

begin_comment
comment|/*  * machine structure  */
end_comment

begin_struct
struct|struct
name|mach
block|{
name|char
name|mflag
decl_stmt|;
name|char
name|rchan
decl_stmt|;
name|char
name|rcount
decl_stmt|;
name|char
name|xchan
decl_stmt|;
name|char
name|xcount
decl_stmt|;
name|struct
name|clist
name|ackq
decl_stmt|;
name|struct
name|clist
name|datq
decl_stmt|;
name|struct
name|clist
name|disq
decl_stmt|;
name|struct
name|chan
modifier|*
name|chanp
index|[
literal|128
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* m flags */
end_comment

begin_define
define|#
directive|define
name|RNEXT
value|01
end_define

begin_define
define|#
directive|define
name|MRUN
value|04
end_define

begin_define
define|#
directive|define
name|XNEXT
value|010
end_define

begin_comment
comment|/*  * trace buffer  */
end_comment

begin_define
define|#
directive|define
name|TBSIZ
value|100
end_define

end_unit

