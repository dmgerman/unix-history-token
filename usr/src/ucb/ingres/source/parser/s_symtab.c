begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|"scanner.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)s_symtab.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* ** SYMENT **	enter a symbol into the symbol table */
end_comment

begin_function
name|char
modifier|*
name|syment
parameter_list|(
name|ptr
parameter_list|,
name|len1
parameter_list|)
name|char
modifier|*
name|ptr
decl_stmt|;
name|int
name|len1
decl_stmt|;
block|{
specifier|register
name|int
name|len
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|extern
name|char
modifier|*
name|need
parameter_list|()
function_decl|;
name|len
operator|=
name|len1
expr_stmt|;
name|p
operator|=
name|need
argument_list|(
name|Sbuf
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|bmove
argument_list|(
name|ptr
argument_list|,
name|p
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ** FREESYM **	free all entries in the symbol table */
end_comment

begin_macro
name|freesym
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|int
name|neederr
parameter_list|()
function_decl|;
name|initbuf
argument_list|(
name|Sbuf
argument_list|,
name|SBUFSIZ
argument_list|,
name|SBUFOFLO
argument_list|,
name|neederr
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

