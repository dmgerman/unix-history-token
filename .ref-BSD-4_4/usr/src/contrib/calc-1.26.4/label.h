begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  */
end_comment

begin_comment
comment|/*  * Label structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|l_offset
decl_stmt|;
comment|/* offset into code of label */
name|long
name|l_chain
decl_stmt|;
comment|/* offset into code of undefined chain */
name|char
modifier|*
name|l_name
decl_stmt|;
comment|/* name of label if any */
block|}
name|LABEL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|initlabels
argument_list|()
decl_stmt|,
name|definelabel
argument_list|()
decl_stmt|,
name|addlabel
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|checklabels
argument_list|()
decl_stmt|,
name|clearlabel
argument_list|()
decl_stmt|,
name|setlabel
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|uselabel
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* END CODE */
end_comment

end_unit

