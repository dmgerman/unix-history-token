begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|NTREC
value|20
end_define

begin_define
define|#
directive|define
name|MLEN
value|16
end_define

begin_define
define|#
directive|define
name|MSIZ
value|4096
end_define

begin_define
define|#
directive|define
name|TS_TAPE
value|1
end_define

begin_define
define|#
directive|define
name|TS_INODE
value|2
end_define

begin_define
define|#
directive|define
name|TS_BITS
value|3
end_define

begin_define
define|#
directive|define
name|TS_ADDR
value|4
end_define

begin_define
define|#
directive|define
name|TS_END
value|5
end_define

begin_define
define|#
directive|define
name|TS_CLRI
value|6
end_define

begin_define
define|#
directive|define
name|MAGIC
value|(int)60011
end_define

begin_define
define|#
directive|define
name|CHECKSUM
value|(int)84446
end_define

begin_struct
struct|struct
name|spcl
block|{
name|int
name|c_type
decl_stmt|;
name|time_t
name|c_date
decl_stmt|;
name|time_t
name|c_ddate
decl_stmt|;
name|int
name|c_volume
decl_stmt|;
name|daddr_t
name|c_tapea
decl_stmt|;
name|ino_t
name|c_inumber
decl_stmt|;
name|int
name|c_magic
decl_stmt|;
name|int
name|c_checksum
decl_stmt|;
name|struct
name|dinode
name|c_dinode
decl_stmt|;
name|int
name|c_count
decl_stmt|;
name|char
name|c_addr
index|[
name|BSIZE
index|]
decl_stmt|;
block|}
name|spcl
struct|;
end_struct

begin_struct
struct|struct
name|idates
block|{
name|char
name|id_name
index|[
literal|16
index|]
decl_stmt|;
name|char
name|id_incno
decl_stmt|;
name|time_t
name|id_ddate
decl_stmt|;
block|}
struct|;
end_struct

end_unit

