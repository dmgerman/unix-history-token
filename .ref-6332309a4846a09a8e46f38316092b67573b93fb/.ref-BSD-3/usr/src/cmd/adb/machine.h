begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/vm.h>
end_include

begin_define
define|#
directive|define
name|PAGSIZ
value|(NBPG*CLSIZE)
end_define

begin_comment
comment|/*  *	UNIX/vax debugger  */
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
value|"%R"
end_define

begin_define
define|#
directive|define
name|OFFMODE
value|"+%R"
end_define

begin_define
define|#
directive|define
name|TXTRNDSIZ
value|PAGSIZ
end_define

begin_decl_stmt
name|TYPE
name|long
name|TXTHDR
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|long
name|SYMV
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|vax
end_ifndef

begin_struct
struct|struct
block|{
name|short
name|hiword
decl_stmt|;
name|short
name|loword
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* stupid fp-11 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
ifndef|#
directive|ifndef
name|EDDT
name|char
name|symf
decl_stmt|;
name|char
name|sympad
index|[
literal|3
index|]
decl_stmt|;
endif|#
directive|endif
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
value|057
end_define

begin_define
define|#
directive|define
name|SYMTYPE
parameter_list|(
name|symflg
parameter_list|)
value|(symflg&41 ? DSYM : NSYM)
end_define

end_unit

