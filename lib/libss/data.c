begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1987, 1988, 1989 Massachusetts Institute of Technology  * (Student Information Processing Board)  *  * For copyright info, see copyright.h.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ss_internal.h"
end_include

begin_include
include|#
directive|include
file|"copyright.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
name|copyright
index|[]
init|=
literal|"Copyright 1987, 1988, 1989 by the Massachusetts Institute of Technology"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ss_data
modifier|*
modifier|*
name|_ss_table
init|=
operator|(
name|ss_data
operator|*
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|_ss_pager_name
init|=
operator|(
name|char
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

end_unit

