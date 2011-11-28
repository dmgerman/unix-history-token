begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* libmain - flex run-time support library "main" function */
end_comment

begin_comment
comment|/*  This file is part of flex. */
end_comment

begin_comment
comment|/*  Redistribution and use in source and binary forms, with or without */
end_comment

begin_comment
comment|/*  modification, are permitted provided that the following conditions */
end_comment

begin_comment
comment|/*  are met: */
end_comment

begin_comment
comment|/*  1. Redistributions of source code must retain the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer. */
end_comment

begin_comment
comment|/*  2. Redistributions in binary form must reproduce the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer in the */
end_comment

begin_comment
comment|/*     documentation and/or other materials provided with the distribution. */
end_comment

begin_comment
comment|/*  Neither the name of the University nor the names of its contributors */
end_comment

begin_comment
comment|/*  may be used to endorse or promote products derived from this software */
end_comment

begin_comment
comment|/*  without specific prior written permission. */
end_comment

begin_comment
comment|/*  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR */
end_comment

begin_comment
comment|/*  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED */
end_comment

begin_comment
comment|/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR */
end_comment

begin_comment
comment|/*  PURPOSE. */
end_comment

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
while|while
condition|(
name|yylex
argument_list|()
operator|!=
literal|0
condition|)
empty_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

