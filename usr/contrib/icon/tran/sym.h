begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Structures for symbol table entries.  */
end_comment

begin_struct
struct|struct
name|lentry
block|{
comment|/* local table entry */
name|struct
name|lentry
modifier|*
name|l_blink
decl_stmt|;
comment|/*   link for bucket chain */
name|char
modifier|*
name|l_name
decl_stmt|;
comment|/*   name of variable */
name|int
name|l_flag
decl_stmt|;
comment|/*   variable flags */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gentry
block|{
comment|/* global table entry */
name|struct
name|gentry
modifier|*
name|g_blink
decl_stmt|;
comment|/*   link for bucket chain */
name|char
modifier|*
name|g_name
decl_stmt|;
comment|/*   name of variable */
name|int
name|g_flag
decl_stmt|;
comment|/*   variable flags */
name|int
name|g_nargs
decl_stmt|;
comment|/*   number of args (procedure) or */
block|}
struct|;
end_struct

begin_comment
comment|/*     number of fields (record) */
end_comment

begin_struct
struct|struct
name|centry
block|{
comment|/* constant table entry */
name|struct
name|centry
modifier|*
name|c_blink
decl_stmt|;
comment|/*   link for bucket chain */
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/*   pointer to string */
name|int
name|c_length
decl_stmt|;
comment|/*   length of string */
name|int
name|c_flag
decl_stmt|;
comment|/*   type of literal flag */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ientry
block|{
comment|/* identifier table entry */
name|struct
name|ientry
modifier|*
name|i_blink
decl_stmt|;
comment|/*   link for bucket chain */
name|char
modifier|*
name|i_name
decl_stmt|;
comment|/*   pointer to string */
name|int
name|i_length
decl_stmt|;
comment|/*   length of string */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flag values.  */
end_comment

begin_define
define|#
directive|define
name|F_GLOBAL
value|01
end_define

begin_comment
comment|/* variable declared global externally */
end_comment

begin_define
define|#
directive|define
name|F_PROC
value|04
end_define

begin_comment
comment|/* procedure */
end_comment

begin_define
define|#
directive|define
name|F_RECORD
value|010
end_define

begin_comment
comment|/* record */
end_comment

begin_define
define|#
directive|define
name|F_DYNAMIC
value|020
end_define

begin_comment
comment|/* variable declared local dynamic */
end_comment

begin_define
define|#
directive|define
name|F_STATIC
value|040
end_define

begin_comment
comment|/* variable declared local static */
end_comment

begin_define
define|#
directive|define
name|F_BUILTIN
value|0100
end_define

begin_comment
comment|/* identifier refers to built-in procedure */
end_comment

begin_define
define|#
directive|define
name|F_IMPERROR
value|0400
end_define

begin_comment
comment|/* procedure has default error */
end_comment

begin_define
define|#
directive|define
name|F_ARGUMENT
value|01000
end_define

begin_comment
comment|/* variable is a formal parameter */
end_comment

begin_define
define|#
directive|define
name|F_INTLIT
value|02000
end_define

begin_comment
comment|/* literal is an integer */
end_comment

begin_define
define|#
directive|define
name|F_REALLIT
value|04000
end_define

begin_comment
comment|/* literal is a real */
end_comment

begin_define
define|#
directive|define
name|F_STRLIT
value|010000
end_define

begin_comment
comment|/* literal is a string */
end_comment

begin_define
define|#
directive|define
name|F_CSETLIT
value|020000
end_define

begin_comment
comment|/* literal is a cset */
end_comment

begin_comment
comment|/*  * Symbol table region pointers.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|lentry
modifier|*
modifier|*
name|lhash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash area for local table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gentry
modifier|*
modifier|*
name|ghash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash area for global table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|centry
modifier|*
modifier|*
name|chash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash area for constant table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ientry
modifier|*
modifier|*
name|ihash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash area for identifier table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|lentry
modifier|*
name|ltable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gentry
modifier|*
name|gtable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|centry
modifier|*
name|ctable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* constant table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ientry
modifier|*
name|itable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* identifier table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|lentry
modifier|*
name|lfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for local table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gentry
modifier|*
name|gfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for global table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|centry
modifier|*
name|ctfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for constant table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ientry
modifier|*
name|ifree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for identifier table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of local table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of global table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|csize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of constant table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|isize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of identifier table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ihsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of identifier hash table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lhsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of local hash tables */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ghsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of global hash tables */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|chsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of constant hash tables */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for local table hash */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for global table hash */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for constant table hash */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for identifier table hash */
end_comment

begin_comment
comment|/*  * Symbol table parameters.  */
end_comment

begin_define
define|#
directive|define
name|LSIZE
value|100
end_define

begin_comment
comment|/* default size of local table */
end_comment

begin_define
define|#
directive|define
name|GSIZE
value|100
end_define

begin_comment
comment|/* default size of global table */
end_comment

begin_define
define|#
directive|define
name|CSIZE
value|100
end_define

begin_comment
comment|/* default size of constant table */
end_comment

begin_define
define|#
directive|define
name|ISIZE
value|500
end_define

begin_comment
comment|/* default size of identifier table */
end_comment

begin_define
define|#
directive|define
name|LHSIZE
value|128
end_define

begin_comment
comment|/* default size of local hash table */
end_comment

begin_define
define|#
directive|define
name|GHSIZE
value|128
end_define

begin_comment
comment|/* default size of global hash table */
end_comment

begin_define
define|#
directive|define
name|CHSIZE
value|128
end_define

begin_comment
comment|/* default size of constant hash table */
end_comment

begin_define
define|#
directive|define
name|IHSIZE
value|128
end_define

begin_comment
comment|/* default size of identifier hash table */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PORT
end_ifdef

begin_define
define|#
directive|define
name|TSIZE
value|x
end_define

begin_comment
comment|/* default size of parse tree space */
end_comment

begin_define
define|#
directive|define
name|SSIZE
value|x
end_define

begin_comment
comment|/* default size of string space */
end_comment

begin_endif
endif|#
directive|endif
endif|PORT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_define
define|#
directive|define
name|TSIZE
value|15000
end_define

begin_comment
comment|/* default size of parse tree space */
end_comment

begin_define
define|#
directive|define
name|SSIZE
value|15000
end_define

begin_comment
comment|/* default size of string space */
end_comment

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_define
define|#
directive|define
name|TSIZE
value|7500
end_define

begin_comment
comment|/* default size of parse tree space */
end_comment

begin_define
define|#
directive|define
name|SSIZE
value|5000
end_define

begin_comment
comment|/* default size of string space */
end_comment

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

begin_comment
comment|/*  * Structure for keyword table.  */
end_comment

begin_struct
struct|struct
name|keyent
block|{
name|char
modifier|*
name|keyname
decl_stmt|;
name|int
name|keyid
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|keyent
name|keytab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keyword table */
end_comment

begin_comment
comment|/*  * Hash functions for symbol tables.  */
end_comment

begin_define
define|#
directive|define
name|ghasher
parameter_list|(
name|x
parameter_list|)
value|(((int)x)&gmask)
end_define

begin_comment
comment|/* global symbol table */
end_comment

begin_define
define|#
directive|define
name|lhasher
parameter_list|(
name|x
parameter_list|)
value|(((int)x)&lmask)
end_define

begin_comment
comment|/* local symbol table */
end_comment

begin_define
define|#
directive|define
name|chasher
parameter_list|(
name|x
parameter_list|)
value|(((int)x)&cmask)
end_define

begin_comment
comment|/* constant symbol table */
end_comment

end_unit

