begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Project database definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Buffer sizes  */
end_comment

begin_define
define|#
directive|define
name|PBUFSIZE
value|1024
end_define

begin_comment
comment|/* project database buffer size */
end_comment

begin_define
define|#
directive|define
name|PDBERRSIZE
value|256
end_define

begin_comment
comment|/* database error message buffer size */
end_comment

begin_comment
comment|/*  * Database access mode definitions  */
end_comment

begin_define
define|#
directive|define
name|_PACCESS
value|007
end_define

begin_comment
comment|/* access mask */
end_comment

begin_define
define|#
directive|define
name|_PREAD
value|001
end_define

begin_comment
comment|/* database open for reading */
end_comment

begin_define
define|#
directive|define
name|_PWRITE
value|002
end_define

begin_comment
comment|/* database open for writing */
end_comment

begin_define
define|#
directive|define
name|_PAPPEND
value|004
end_define

begin_comment
comment|/* database open for appending */
end_comment

begin_comment
comment|/*  * Database status definitions  */
end_comment

begin_define
define|#
directive|define
name|_PSTAT
value|070
end_define

begin_comment
comment|/* status mask */
end_comment

begin_define
define|#
directive|define
name|_PUPDATE
value|010
end_define

begin_comment
comment|/* database updated */
end_comment

begin_define
define|#
directive|define
name|_PEOF
value|020
end_define

begin_comment
comment|/* EOF */
end_comment

begin_define
define|#
directive|define
name|_PERR
value|040
end_define

begin_comment
comment|/* error */
end_comment

begin_comment
comment|/*  * Project database structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pdbdesc
comment|/* database description struct */
block|{
name|char
name|root
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* database directory pathname */
name|char
name|path
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* database pathname */
name|FILE
modifier|*
name|fp
decl_stmt|;
comment|/* database file pointer */
name|char
name|tpath
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* temporary database pathname */
name|FILE
modifier|*
name|tfp
decl_stmt|;
comment|/* temporary database file ptr */
name|unsigned
name|short
name|flag
decl_stmt|;
comment|/* mode of database access */
name|char
name|pbuf
index|[
name|PBUFSIZE
index|]
decl_stmt|;
comment|/* database line buffer */
name|char
name|perr
index|[
name|PDBERRSIZE
index|]
decl_stmt|;
comment|/* database error message buffer */
block|}
name|PDB
typedef|;
end_typedef

begin_comment
comment|/*  * Functions defined for project databases  */
end_comment

begin_function_decl
specifier|extern
name|int
name|_closepdb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* close database without updating */
end_comment

begin_function_decl
specifier|extern
name|int
name|closepdb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* close database */
end_comment

begin_function_decl
specifier|extern
name|int
name|errpdb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print database error message */
end_comment

begin_function_decl
specifier|extern
name|PDB
modifier|*
name|mustopenpdb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* must open database or die */
end_comment

begin_function_decl
specifier|extern
name|PDB
modifier|*
name|openpdb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* open database */
end_comment

begin_function_decl
specifier|extern
name|void
name|renamepdb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* rename database */
end_comment

begin_function_decl
specifier|extern
name|void
name|resetpdb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* reset current database ptr */
end_comment

begin_function_decl
specifier|extern
name|void
name|rewindpdb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* rewind database */
end_comment

begin_function_decl
specifier|extern
name|int
name|pfndent
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find and load database entry */
end_comment

begin_function_decl
specifier|extern
name|int
name|pgetent
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* load next entry into buffer */
end_comment

begin_function_decl
specifier|extern
name|int
name|pputent
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* write buffer to database */
end_comment

begin_function_decl
specifier|extern
name|void
name|prment
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove database entry */
end_comment

begin_function_decl
specifier|extern
name|void
name|paddkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add key to specified entries */
end_comment

begin_function_decl
specifier|extern
name|void
name|pchgkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* change specified key */
end_comment

begin_function_decl
specifier|extern
name|void
name|prmkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove specified key */
end_comment

begin_function_decl
specifier|extern
name|void
name|paddflag
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add flags */
end_comment

begin_function_decl
specifier|extern
name|void
name|pchgflag
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* change flags */
end_comment

begin_function_decl
specifier|extern
name|void
name|pputflag
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add or change flags */
end_comment

begin_function_decl
specifier|extern
name|void
name|prmflag
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove flags */
end_comment

begin_function_decl
specifier|extern
name|void
name|paddstring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add or change strings */
end_comment

begin_function_decl
specifier|extern
name|void
name|pchgstring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* change strings */
end_comment

begin_function_decl
specifier|extern
name|void
name|pputstring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add or change strings */
end_comment

begin_function_decl
specifier|extern
name|void
name|prmstring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove strings */
end_comment

end_unit

