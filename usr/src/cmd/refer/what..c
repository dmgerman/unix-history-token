begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"ctype.h"
end_include

begin_include
include|#
directive|include
file|"sys/types.h"
end_include

begin_include
include|#
directive|include
file|"sys/stat.h"
end_include

begin_include
include|#
directive|include
file|"assert.h"
end_include

begin_define
define|#
directive|define
name|NFILES
value|100
end_define

begin_define
define|#
directive|define
name|NAMES
value|2000
end_define

begin_extern
extern|extern exch(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|comp
argument_list|()
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|filans
block|{
name|char
modifier|*
name|nm
decl_stmt|;
name|long
name|fdate
decl_stmt|;
name|long
name|size
decl_stmt|;
name|int
name|uid
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|filans
name|files
index|[
name|NFILES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|fnames
index|[
name|NAMES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NFEED
value|5
end_define

end_unit

