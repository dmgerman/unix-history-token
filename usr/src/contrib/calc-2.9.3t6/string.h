begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CALCSTRING_H
end_ifndef

begin_define
define|#
directive|define
name|CALCSTRING_H
end_define

begin_include
include|#
directive|include
file|"zmath.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|h_list
decl_stmt|;
comment|/* list of strings separated by nulls */
name|long
name|h_used
decl_stmt|;
comment|/* characters used so far */
name|long
name|h_avail
decl_stmt|;
comment|/* characters available for use */
name|long
name|h_count
decl_stmt|;
comment|/* number of strings */
block|}
name|STRINGHEAD
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|initstr
name|MATH_PROTO
argument_list|(
operator|(
name|STRINGHEAD
operator|*
name|hp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|addstr
name|MATH_PROTO
argument_list|(
operator|(
name|STRINGHEAD
operator|*
name|hp
operator|,
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|namestr
name|MATH_PROTO
argument_list|(
operator|(
name|STRINGHEAD
operator|*
name|hp
operator|,
name|long
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|findstr
name|MATH_PROTO
argument_list|(
operator|(
name|STRINGHEAD
operator|*
name|hp
operator|,
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|charstr
name|MATH_PROTO
argument_list|(
operator|(
name|int
name|ch
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|addliteral
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|stringindex
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|str1
operator|,
name|char
operator|*
name|str2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HASH
name|hashstr
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|cp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

