begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)tp.h	4.2	6/28/84	*/
end_comment

begin_comment
comment|/*	c-version of tp?.s  *  *	M. Ferentz  *	August 1976  *  *	revised July 1977 BTL  */
end_comment

begin_define
define|#
directive|define
name|MDIRENT
value|496
end_define

begin_comment
comment|/* must be zero mod 8 */
end_comment

begin_define
define|#
directive|define
name|DIRSZ
value|sizeof(struct dent)
end_define

begin_define
define|#
directive|define
name|MAPSIZE
value|4096
end_define

begin_define
define|#
directive|define
name|MAPMASK
value|07777
end_define

begin_define
define|#
directive|define
name|NAMELEN
value|32
end_define

begin_define
define|#
directive|define
name|BSIZE
value|512
end_define

begin_define
define|#
directive|define
name|TCSIZ
value|578
end_define

begin_define
define|#
directive|define
name|TCDIRS
value|192
end_define

begin_define
define|#
directive|define
name|MTSIZ
value|32767
end_define

begin_define
define|#
directive|define
name|TPB
value|(BSIZE/sizeof(struct tent))
end_define

begin_define
define|#
directive|define
name|OK
value|0100000
end_define

begin_define
define|#
directive|define
name|BRKINCR
value|512
end_define

begin_define
define|#
directive|define
name|tapeblk
value|&tpentry[0]
end_define

begin_define
define|#
directive|define
name|tapeb
value|&tpentry[0]
end_define

begin_struct
struct|struct
name|tent
block|{
comment|/* Structure of a tape directory block */
name|char
name|pathnam
index|[
name|NAMELEN
index|]
decl_stmt|;
name|short
name|mode
decl_stmt|;
name|char
name|uid
decl_stmt|;
name|char
name|gid
decl_stmt|;
name|char
name|spare
decl_stmt|;
name|char
name|size0
decl_stmt|;
name|unsigned
name|short
name|size1
decl_stmt|;
name|long
name|time
decl_stmt|;
name|unsigned
name|short
name|tapea
decl_stmt|;
comment|/* tape address */
name|short
name|unused
index|[
literal|8
index|]
decl_stmt|;
name|short
name|cksum
decl_stmt|;
block|}
name|tpentry
index|[
name|TPB
index|]
struct|;
end_struct

begin_struct
struct|struct
name|dent
block|{
comment|/* in core version of tent with "unused" removed 		 * and pathname replaced by pointer to same in a 		 * packed area (nameblock). 		 */
name|char
modifier|*
name|d_namep
decl_stmt|;
name|int
name|d_mode
decl_stmt|;
name|int
name|d_uid
decl_stmt|;
name|int
name|d_gid
decl_stmt|;
name|long
name|d_size
decl_stmt|;
name|long
name|d_time
decl_stmt|;
name|int
name|d_tapea
decl_stmt|;
block|}
name|dir
index|[
name|MDIRENT
index|]
struct|;
end_struct

begin_decl_stmt
name|char
name|map
index|[
name|MAPSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|name
index|[
name|NAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|name1
index|[
name|NAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|mt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|mheader
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|theader
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|narg
decl_stmt|,
name|rnarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|parg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wseeka
decl_stmt|,
name|rseeka
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tapsiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fio
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|ndirent
decl_stmt|,
name|ndentb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dent
modifier|*
name|edir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dent
modifier|*
name|lastd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for improvement */
end_comment

begin_function_decl
name|char
modifier|*
name|sbrk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|command
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|flags
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|flc
value|0001
end_define

begin_define
define|#
directive|define
name|fli
value|0004
end_define

begin_define
define|#
directive|define
name|flm
value|0010
end_define

begin_define
define|#
directive|define
name|flu
value|0020
end_define

begin_define
define|#
directive|define
name|flv
value|0040
end_define

begin_define
define|#
directive|define
name|flw
value|0100
end_define

begin_define
define|#
directive|define
name|fls
value|0200
end_define

end_unit

