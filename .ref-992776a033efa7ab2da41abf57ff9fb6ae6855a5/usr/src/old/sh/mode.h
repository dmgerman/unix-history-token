begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mode.h	4.1	82/05/07	*/
end_comment

begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	UNIX shell  */
end_comment

begin_define
define|#
directive|define
name|BYTESPERWORD
value|(sizeof(char *))
end_define

begin_decl_stmt
name|TYPE
name|char
name|CHAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|char
name|BOOL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|int
name|UFD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|int
name|INT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|float
name|REAL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|char
modifier|*
name|ADDRESS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|long
name|int
name|L_INT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|int
name|VOID
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|unsigned
name|POS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|char
modifier|*
name|STRING
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|char
name|MSG
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|int
name|PIPE
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|char
modifier|*
name|STKPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|char
modifier|*
name|BYTPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|stat
name|STATBUF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in /usr/sys/stat.h */
end_comment

begin_decl_stmt
name|STRUCT
name|blk
modifier|*
name|BLKPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|fileblk
name|FILEBLK
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|filehdr
name|FILEHDR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|fileblk
modifier|*
name|FILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|trenod
modifier|*
name|TREPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|forknod
modifier|*
name|FORKPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|comnod
modifier|*
name|COMPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|swnod
modifier|*
name|SWPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|regnod
modifier|*
name|REGPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|parnod
modifier|*
name|PARPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|ifnod
modifier|*
name|IFPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|whnod
modifier|*
name|WHPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|fornod
modifier|*
name|FORPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|lstnod
modifier|*
name|LSTPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|argnod
modifier|*
name|ARGPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|dolnod
modifier|*
name|DOLPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|ionod
modifier|*
name|IOPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|namnod
name|NAMNOD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|namnod
modifier|*
name|NAMPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|sysnod
name|SYSNOD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|sysnod
modifier|*
name|SYSPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRUCT
name|sysnod
name|SYSTAB
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NIL
value|((char*)0)
end_define

begin_comment
comment|/* the following nonsense is required  * because casts turn an Lvalue  * into an Rvalue so two cheats  * are necessary, one for each context.  */
end_comment

begin_union
union|union
block|{
name|int
name|_cheat
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|Lcheat
parameter_list|(
name|a
parameter_list|)
value|((a)._cheat)
end_define

begin_define
define|#
directive|define
name|Rcheat
parameter_list|(
name|a
parameter_list|)
value|((int)(a))
end_define

begin_comment
comment|/* address puns for storage allocation */
end_comment

begin_macro
name|UNION
end_macro

begin_block
block|{
name|FORKPTR
name|_forkptr
decl_stmt|;
name|COMPTR
name|_comptr
decl_stmt|;
name|PARPTR
name|_parptr
decl_stmt|;
name|IFPTR
name|_ifptr
decl_stmt|;
name|WHPTR
name|_whptr
decl_stmt|;
name|FORPTR
name|_forptr
decl_stmt|;
name|LSTPTR
name|_lstptr
decl_stmt|;
name|BLKPTR
name|_blkptr
decl_stmt|;
name|NAMPTR
name|_namptr
decl_stmt|;
name|BYTPTR
name|_bytptr
decl_stmt|;
block|}
end_block

begin_expr_stmt
name|address
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* for functions that do not return values */
end_comment

begin_comment
comment|/* struct void {INT vvvvvvvv;}; */
end_comment

begin_comment
comment|/* heap storage */
end_comment

begin_struct
struct|struct
name|blk
block|{
name|BLKPTR
name|word
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BUFSIZ
value|64
end_define

begin_struct
struct|struct
name|fileblk
block|{
name|UFD
name|fdes
decl_stmt|;
name|POS
name|flin
decl_stmt|;
name|BOOL
name|feof
decl_stmt|;
name|CHAR
name|fsiz
decl_stmt|;
name|STRING
name|fnxt
decl_stmt|;
name|STRING
name|fend
decl_stmt|;
name|STRING
modifier|*
name|feval
decl_stmt|;
name|FILE
name|fstak
decl_stmt|;
name|CHAR
name|fbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* for files not used with file descriptors */
end_comment

begin_struct
struct|struct
name|filehdr
block|{
name|UFD
name|fdes
decl_stmt|;
name|POS
name|flin
decl_stmt|;
name|BOOL
name|feof
decl_stmt|;
name|CHAR
name|fsiz
decl_stmt|;
name|STRING
name|fnxt
decl_stmt|;
name|STRING
name|fend
decl_stmt|;
name|STRING
modifier|*
name|feval
decl_stmt|;
name|FILE
name|fstak
decl_stmt|;
name|CHAR
name|_fbuf
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sysnod
block|{
name|STRING
name|sysnam
decl_stmt|;
name|INT
name|sysval
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* this node is a proforma for those that follow */
end_comment

begin_struct
struct|struct
name|trenod
block|{
name|INT
name|tretyp
decl_stmt|;
name|IOPTR
name|treio
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* dummy for access only */
end_comment

begin_struct
struct|struct
name|argnod
block|{
name|ARGPTR
name|argnxt
decl_stmt|;
name|CHAR
name|argval
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dolnod
block|{
name|DOLPTR
name|dolnxt
decl_stmt|;
name|INT
name|doluse
decl_stmt|;
name|CHAR
name|dolarg
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|forknod
block|{
name|INT
name|forktyp
decl_stmt|;
name|IOPTR
name|forkio
decl_stmt|;
name|TREPTR
name|forktre
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|comnod
block|{
name|INT
name|comtyp
decl_stmt|;
name|IOPTR
name|comio
decl_stmt|;
name|ARGPTR
name|comarg
decl_stmt|;
name|ARGPTR
name|comset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifnod
block|{
name|INT
name|iftyp
decl_stmt|;
name|TREPTR
name|iftre
decl_stmt|;
name|TREPTR
name|thtre
decl_stmt|;
name|TREPTR
name|eltre
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|whnod
block|{
name|INT
name|whtyp
decl_stmt|;
name|TREPTR
name|whtre
decl_stmt|;
name|TREPTR
name|dotre
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fornod
block|{
name|INT
name|fortyp
decl_stmt|;
name|TREPTR
name|fortre
decl_stmt|;
name|STRING
name|fornam
decl_stmt|;
name|COMPTR
name|forlst
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|swnod
block|{
name|INT
name|swtyp
decl_stmt|;
name|STRING
name|swarg
decl_stmt|;
name|REGPTR
name|swlst
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|regnod
block|{
name|ARGPTR
name|regptr
decl_stmt|;
name|TREPTR
name|regcom
decl_stmt|;
name|REGPTR
name|regnxt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|parnod
block|{
name|INT
name|partyp
decl_stmt|;
name|TREPTR
name|partre
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lstnod
block|{
name|INT
name|lsttyp
decl_stmt|;
name|TREPTR
name|lstlef
decl_stmt|;
name|TREPTR
name|lstrit
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ionod
block|{
name|INT
name|iofile
decl_stmt|;
name|STRING
name|ioname
decl_stmt|;
name|IOPTR
name|ionxt
decl_stmt|;
name|IOPTR
name|iolst
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FORKTYPE
value|(sizeof(struct forknod))
end_define

begin_define
define|#
directive|define
name|COMTYPE
value|(sizeof(struct comnod))
end_define

begin_define
define|#
directive|define
name|IFTYPE
value|(sizeof(struct ifnod))
end_define

begin_define
define|#
directive|define
name|WHTYPE
value|(sizeof(struct whnod))
end_define

begin_define
define|#
directive|define
name|FORTYPE
value|(sizeof(struct fornod))
end_define

begin_define
define|#
directive|define
name|SWTYPE
value|(sizeof(struct swnod))
end_define

begin_define
define|#
directive|define
name|REGTYPE
value|(sizeof(struct regnod))
end_define

begin_define
define|#
directive|define
name|PARTYPE
value|(sizeof(struct parnod))
end_define

begin_define
define|#
directive|define
name|LSTTYPE
value|(sizeof(struct lstnod))
end_define

begin_define
define|#
directive|define
name|IOTYPE
value|(sizeof(struct ionod))
end_define

end_unit

