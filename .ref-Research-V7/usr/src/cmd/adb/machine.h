begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	UNIX/INTERDATA debugger  */
end_comment

begin_comment
comment|/* unix parameters */
end_comment

begin_define
define|#
directive|define
name|DBNAME
value|"adb\n"
end_define

begin_define
define|#
directive|define
name|LPRMODE
value|"%Q"
end_define

begin_define
define|#
directive|define
name|OFFMODE
value|"+%o"
end_define

begin_define
define|#
directive|define
name|TXTRNDSIZ
value|8192L
end_define

begin_decl_stmt
name|TYPE
name|unsigned
name|TXTHDR
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|unsigned
name|SYMV
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* symbol table in a.out file */
end_comment

begin_struct
struct|struct
name|symtab
block|{
name|char
name|symc
index|[
literal|8
index|]
decl_stmt|;
name|int
name|symf
decl_stmt|;
name|SYMV
name|symv
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SYMTABSIZ
value|(sizeof (struct symtab))
end_define

begin_define
define|#
directive|define
name|SYMCHK
value|047
end_define

begin_define
define|#
directive|define
name|SYMTYPE
parameter_list|(
name|symflg
parameter_list|)
value|(( symflg>=041 || (symflg>=02&& symflg<=04))\ 				?  ((symflg&07)>=3 ? DSYM : (symflg&07))\ 				: NSYM\ 			)
end_define

end_unit

