begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* "@(#)mode.h 4.2 8/17/82" */
end_comment

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_comment
comment|/*  *	UNIX debugger  */
end_comment

begin_define
define|#
directive|define
name|MAXCOM
value|64
end_define

begin_define
define|#
directive|define
name|MAXARG
value|32
end_define

begin_define
define|#
directive|define
name|LINSIZ
value|256
end_define

begin_decl_stmt
name|TYPE
name|long
name|ADDR
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|vax
end_ifndef

begin_decl_stmt
name|TYPE
name|int
name|INT
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|TYPE
name|short
name|INT
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|TYPE
name|int
name|VOID
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
name|float
name|REAL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|double
name|L_REAL
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
name|BOOL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|char
name|CHAR
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
name|struct
name|map
name|MAP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|MAP
modifier|*
name|MAPPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|struct
name|symtab
name|SYMTAB
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|SYMTAB
modifier|*
name|SYMPTR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|struct
name|symslave
name|SYMSLAVE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|struct
name|bkpt
name|BKPT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|BKPT
modifier|*
name|BKPTR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file address maps */
end_comment

begin_struct
struct|struct
name|map
block|{
name|L_INT
name|b1
decl_stmt|;
name|L_INT
name|e1
decl_stmt|;
name|L_INT
name|f1
decl_stmt|;
name|L_INT
name|b2
decl_stmt|;
name|L_INT
name|e2
decl_stmt|;
name|L_INT
name|f2
decl_stmt|;
name|INT
name|ufd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* slave table for symbols */
end_comment

begin_struct
struct|struct
name|symslave
block|{
name|SYMV
name|valslave
decl_stmt|;
name|INT
name|typslave
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bkpt
block|{
name|ADDR
name|loc
decl_stmt|;
name|ADDR
name|ins
decl_stmt|;
name|INT
name|count
decl_stmt|;
name|INT
name|initcnt
decl_stmt|;
name|INT
name|flag
decl_stmt|;
name|CHAR
name|comm
index|[
name|MAXCOM
index|]
decl_stmt|;
name|BKPT
modifier|*
name|nxtbkpt
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|TYPE
name|struct
name|reglist
name|REGLIST
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TYPE
name|REGLIST
modifier|*
name|REGPTR
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|reglist
block|{
name|STRING
name|rname
decl_stmt|;
name|INT
name|roffs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|INT
name|junk
index|[
literal|2
index|]
decl_stmt|;
name|INT
name|fpsr
decl_stmt|;
name|REAL
name|Sfr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|INT
name|junk
index|[
literal|2
index|]
decl_stmt|;
name|INT
name|fpsr
decl_stmt|;
name|L_REAL
name|Lfr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

