begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  */
end_comment

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
name|char
modifier|*
name|addstr
argument_list|()
decl_stmt|,
modifier|*
name|namestr
argument_list|()
decl_stmt|,
modifier|*
name|charstr
argument_list|()
decl_stmt|,
modifier|*
name|addliteral
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|findstr
argument_list|()
decl_stmt|,
name|stringindex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|initstr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* END CODE */
end_comment

end_unit

