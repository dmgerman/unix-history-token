begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|uleft
value|04040
end_define

begin_define
define|#
directive|define
name|uright
value|04004
end_define

begin_define
define|#
directive|define
name|dleft
value|00440
end_define

begin_define
define|#
directive|define
name|dright
value|00404
end_define

begin_define
define|#
directive|define
name|left
value|00040
end_define

begin_define
define|#
directive|define
name|right
value|00004
end_define

begin_define
define|#
directive|define
name|up
value|04000
end_define

begin_define
define|#
directive|define
name|down
value|00400
end_define

begin_define
define|#
directive|define
name|u2r1
value|06004
end_define

begin_define
define|#
directive|define
name|u1r2
value|04006
end_define

begin_define
define|#
directive|define
name|d1r2
value|00406
end_define

begin_define
define|#
directive|define
name|d2r1
value|00604
end_define

begin_define
define|#
directive|define
name|d2l1
value|00640
end_define

begin_define
define|#
directive|define
name|d1l2
value|00460
end_define

begin_define
define|#
directive|define
name|u1l2
value|04060
end_define

begin_define
define|#
directive|define
name|u2l1
value|06040
end_define

begin_define
define|#
directive|define
name|rank2
value|00200
end_define

begin_define
define|#
directive|define
name|rank7
value|02000
end_define

begin_decl_stmt
name|int
name|attacv
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|center
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wheur
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bheur
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|control
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|clktim
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|testf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|qdepth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mdepth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bookf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bookp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|manflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|matflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|intrp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|moveno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|game
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|abmove
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|lmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|amp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sbufp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lastmov
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mantom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ply
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ivalue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mfmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|depth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eppos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bkpos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wkpos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|column
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|edge
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pval
index|[
literal|13
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipval
index|[
literal|13
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dir
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|board
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lmbuf
index|[
literal|1000
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ambuf
index|[
literal|1200
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|sbuf
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

end_unit

