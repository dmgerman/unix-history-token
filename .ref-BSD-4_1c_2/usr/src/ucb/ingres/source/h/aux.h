begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* **  AUX.H -- misc. include information. ** **	Version: **		@(#)aux.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXFIELD
end_ifndef

begin_comment
comment|/* **	Accessparam structure -- this structure is filled by **	the paramd() and parami() routines. It gives a list of **	key domains in their key sequence order. */
end_comment

begin_struct
struct|struct
name|accessparam
block|{
name|short
name|mode
decl_stmt|;
comment|/* mode of relation, NOKEY, RANGEKEY, EXACTKEY */
name|short
name|sec_index
decl_stmt|;
comment|/* TRUE if relation is a secondary index. else FALSE */
name|char
name|keydno
index|[
name|MAXDOM
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* **	Desxx structure -- This structure is used by opencatalog and **	closecatalog. It is used to maintain a list of system relations **	for caching. */
end_comment

begin_struct
struct|struct
name|desxx
block|{
name|char
modifier|*
name|cach_relname
decl_stmt|;
comment|/* name of the relation */
name|DESC
modifier|*
name|cach_desc
decl_stmt|;
comment|/* desc to use */
name|DESC
modifier|*
name|cach_alias
decl_stmt|;
comment|/* alias for above descriptor */
block|}
struct|;
end_struct

begin_comment
comment|/* **  Relation status bits ** **	These bits are in the relation relation, in the "relstat" **	field.  They define status information about the relation. */
end_comment

begin_define
define|#
directive|define
name|S_CATALOG
value|0000001
end_define

begin_comment
comment|/* system catalog */
end_comment

begin_define
define|#
directive|define
name|S_NOUPDT
value|0000002
end_define

begin_comment
comment|/* no update allowed */
end_comment

begin_define
define|#
directive|define
name|S_PROTUPS
value|0000004
end_define

begin_comment
comment|/* tuples exist in 'protect' */
end_comment

begin_define
define|#
directive|define
name|S_INTEG
value|0000010
end_define

begin_comment
comment|/* integrity constrained */
end_comment

begin_define
define|#
directive|define
name|S_CONCUR
value|0000020
end_define

begin_comment
comment|/* concurrency enforced */
end_comment

begin_define
define|#
directive|define
name|S_VIEW
value|0000040
end_define

begin_comment
comment|/* relation is a view */
end_comment

begin_define
define|#
directive|define
name|S_VBASE
value|0000100
end_define

begin_comment
comment|/* base rel for a view */
end_comment

begin_define
define|#
directive|define
name|S_INDEX
value|0000200
end_define

begin_comment
comment|/* is a sec indx */
end_comment

begin_define
define|#
directive|define
name|S_BINARY
value|0000400
end_define

begin_comment
comment|/* print char domains in binary */
end_comment

begin_define
define|#
directive|define
name|S_DISTRIBUTED
value|0001000
end_define

begin_comment
comment|/* reserved for distributed rels */
end_comment

begin_define
define|#
directive|define
name|S_DISCRIT
value|0002000
end_define

begin_comment
comment|/* resrved for distr temp rel */
end_comment

begin_define
define|#
directive|define
name|S_DISCOPY
value|0004000
end_define

begin_comment
comment|/* reserved for distributed rels */
end_comment

begin_define
define|#
directive|define
name|S_PROTALL
value|0010000
end_define

begin_comment
comment|/* if clear, all permission */
end_comment

begin_define
define|#
directive|define
name|S_PROTRET
value|0020000
end_define

begin_comment
comment|/* if clear, read permission */
end_comment

begin_comment
comment|/* **  Protection bits are defined as follows: ** **	S_PROTUPS -- if set, there are tuples for this relation in the **		protect catalog. **	S_PROTALL, S_PROTRET -- AS shown from the following table: **	PROTALL	PROTRET	    meaning **	    1	    1	Need to look in the protect catalog to tell. **	    1	    0	Permit RETRIEVE to ALL case. **	    0	    1	Permit ALL to ALL case. **	    0	    0	Permit ALL to ALL and RETRIEVE to ALL. */
end_comment

begin_comment
comment|/* **  User status bits ** **	These bits are in the status field of the users file.  They end **	up in a variable "Status" after a call to initucode. */
end_comment

begin_define
define|#
directive|define
name|U_CREATDB
value|0000001
end_define

begin_comment
comment|/* can create data bases */
end_comment

begin_define
define|#
directive|define
name|U_DRCTUPDT
value|0000002
end_define

begin_comment
comment|/* can specify direct update */
end_comment

begin_define
define|#
directive|define
name|U_UPSYSCAT
value|0000004
end_define

begin_comment
comment|/* can update system catalogs directly */
end_comment

begin_define
define|#
directive|define
name|U_TRACE
value|0000020
end_define

begin_comment
comment|/* can use trace flags */
end_comment

begin_define
define|#
directive|define
name|U_QRYMODOFF
value|0000040
end_define

begin_comment
comment|/* can turn off qrymod */
end_comment

begin_define
define|#
directive|define
name|U_APROCTAB
value|0000100
end_define

begin_comment
comment|/* can use arbitrary proctab */
end_comment

begin_define
define|#
directive|define
name|U_EPROCTAB
value|0000200
end_define

begin_comment
comment|/* can use =proctab form */
end_comment

begin_define
define|#
directive|define
name|U_SUPER
value|0100000
end_define

begin_comment
comment|/* ingres superuser */
end_comment

begin_comment
comment|/* **	The following defines declare the field number in the users **	file for each field. */
end_comment

begin_define
define|#
directive|define
name|UF_NAME
value|0
end_define

begin_comment
comment|/* login name */
end_comment

begin_define
define|#
directive|define
name|UF_UCODE
value|1
end_define

begin_comment
comment|/* user code */
end_comment

begin_define
define|#
directive|define
name|UF_UID
value|2
end_define

begin_comment
comment|/* UNIX user id */
end_comment

begin_define
define|#
directive|define
name|UF_GID
value|3
end_define

begin_comment
comment|/* UNIX group id */
end_comment

begin_define
define|#
directive|define
name|UF_STAT
value|4
end_define

begin_comment
comment|/* status bits */
end_comment

begin_define
define|#
directive|define
name|UF_FLAGS
value|5
end_define

begin_comment
comment|/* default flags */
end_comment

begin_define
define|#
directive|define
name|UF_PTAB
value|6
end_define

begin_comment
comment|/* default proctab */
end_comment

begin_define
define|#
directive|define
name|UF_IFILE
value|7
end_define

begin_comment
comment|/* monitor init file */
end_comment

begin_define
define|#
directive|define
name|UF_DBLIST
value|9
end_define

begin_comment
comment|/* list of valid databases */
end_comment

begin_define
define|#
directive|define
name|UF_NFIELDS
value|10
end_define

begin_comment
comment|/* TOTAL number of fields */
end_comment

begin_comment
comment|/* **	Usercode contains the current user's INGRES user-id code. **	Pathname contains the name of the INGRES subtree. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Usercode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Pathname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **	The following union are for use in type conversion. **		modified for VAX june '79 */
end_comment

begin_comment
comment|/* **  PRINTED OUTPUT ARGUMENTS ** **	The following struct describes the printed output available **	to the user. */
end_comment

begin_struct
struct|struct
name|out_arg
block|{
name|int
name|c0width
decl_stmt|;
comment|/* minimum width of "c" field */
name|int
name|i1width
decl_stmt|;
comment|/* width of "i1" field */
name|int
name|i2width
decl_stmt|;
comment|/* width of "i2" field */
name|int
name|i4width
decl_stmt|;
comment|/* width of "i4" field */
name|int
name|f4width
decl_stmt|;
comment|/* width of "f4" field */
name|int
name|f8width
decl_stmt|;
comment|/* width of "f8" field */
name|int
name|f4prec
decl_stmt|;
comment|/* number of decimal places on "f4" */
name|int
name|f8prec
decl_stmt|;
comment|/* number of decimal places on "f8" */
name|char
name|f4style
decl_stmt|;
comment|/* "f4" output style */
name|char
name|f8style
decl_stmt|;
comment|/* "f8" output style */
name|int
name|linesperpage
decl_stmt|;
comment|/* number of lines per output page */
name|char
name|coldelim
decl_stmt|;
comment|/* column delimiter */
block|}
struct|;
end_struct

begin_comment
comment|/* maximum width of any of the above fields */
end_comment

begin_define
define|#
directive|define
name|MAXFIELD
value|255
end_define

begin_comment
comment|/* **  any text line read from a file (for example, .../files/users) can **	be at most MAXLINE bytes long.  buffers designed for holding **	such info should be decleared as char buf[MAXLINE + 1] to allow **	for the null terminator. */
end_comment

begin_define
define|#
directive|define
name|MAXLINE
value|256
end_define

begin_comment
comment|/* file mode for INGRES files */
end_comment

begin_define
define|#
directive|define
name|FILEMODE
value|0600
end_define

begin_comment
comment|/* db file mode */
end_comment

begin_comment
comment|/* stuff giving information about the machine */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_define
define|#
directive|define
name|WORDSIZE
value|16
end_define

begin_comment
comment|/* number of bits in word */
end_comment

begin_define
define|#
directive|define
name|LOG2WORDSIZE
value|4
end_define

begin_comment
comment|/* log base 2 of WORDSIZE */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WORDSIZE
value|32
end_define

begin_comment
comment|/* number of bits in word */
end_comment

begin_define
define|#
directive|define
name|LOG2WORDSIZE
value|5
end_define

begin_comment
comment|/* log base 2 of WORDSIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
endif|MAXFIELD
end_endif

end_unit

