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
file|<symbol.h>
end_include

begin_include
include|#
directive|include
file|<tree.h>
end_include

begin_include
include|#
directive|include
file|<batch.h>
end_include

begin_include
include|#
directive|include
file|"../ctlmod/pipes.h"
end_include

begin_include
include|#
directive|include
file|"../decomp/globs.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)equelpr.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **	This file contains all the routines needed **	for communicating with the equel process. **	They are called only if the flag Equel = TRUE. */
end_comment

begin_decl_stmt
name|pb_t
name|EquelPb
decl_stmt|;
end_decl_stmt

begin_macro
name|startequel
argument_list|()
end_macro

begin_block
block|{
name|pb_prime
argument_list|(
operator|&
name|EquelPb
argument_list|,
name|PB_REG
argument_list|)
expr_stmt|;
name|EquelPb
operator|.
name|pb_proc
operator|=
name|PB_FRONT
expr_stmt|;
name|EquelPb
operator|.
name|pb_st
operator|=
name|PB_FRONT
expr_stmt|;
name|EquelPb
operator|.
name|pb_stat
operator||=
name|PB_INFO
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **	equelatt writes one symbol pointed to **	by ss up the data pipe to the equel **	process. ** **	if a symbol is a character then *ss->value **	contains a pointer to the character string. **	otherwise the value is stored in successive **	words starting in ss->value. */
end_comment

begin_macro
name|equelatt
argument_list|(
argument|ss
argument_list|)
end_macro

begin_decl_stmt
name|SYMBOL
modifier|*
name|ss
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|xOTR1
if|if
condition|(
name|tTf
argument_list|(
literal|80
argument_list|,
literal|0
argument_list|)
condition|)
name|prstack
argument_list|(
name|ss
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|pwritesym
argument_list|(
name|ss
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **	equeleol is called at the end of the interpretation of **	a tuple. Its purpose is to write an end-of-tuple **	symbol to the equel process and flush the pipe. ** **	It is also called at the end of a query to write **	an exit symbol to equel. */
end_comment

begin_macro
name|equeleol
argument_list|(
argument|code
argument_list|)
end_macro

begin_decl_stmt
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|stacksym
name|symb
decl_stmt|;
name|symb
operator|.
name|s_type
operator|=
name|code
expr_stmt|;
name|symb
operator|.
name|s_len
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|xOTR1
if|if
condition|(
name|tTf
argument_list|(
literal|80
argument_list|,
literal|3
argument_list|)
condition|)
name|printf
argument_list|(
literal|"equeleol:writing %d to equel\n"
argument_list|,
name|code
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|pb_put
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|symb
argument_list|,
name|TYP_LEN_SIZ
argument_list|,
operator|&
name|EquelPb
argument_list|)
expr_stmt|;
comment|/* flush after every tuple for Equel versions before 6.2  	 * and at end of results always 	 */
if|if
condition|(
name|code
operator|==
name|EXIT
condition|)
name|pb_flush
argument_list|(
operator|&
name|EquelPb
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **	pwritesym write the stacksymbol **	pointed to by "ss" to the pipe **	indicated by filedesc. ** **	The destination will either be equel **	or decomp ** **	Since a CHAR isn't stored immediately following **	the type and len of the symbol, A small bit **	of manipulation must be done. */
end_comment

begin_expr_stmt
name|pwritesym
argument_list|(
name|s
argument_list|)
specifier|register
name|SYMBOL
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|length
decl_stmt|;
name|length
operator|=
name|s
operator|->
name|len
operator|&
literal|0377
expr_stmt|;
name|pb_put
argument_list|(
operator|(
name|char
operator|*
operator|)
name|s
argument_list|,
name|TYP_LEN_SIZ
argument_list|,
operator|&
name|EquelPb
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|->
name|type
operator|==
name|CHAR
condition|)
name|p
operator|=
name|s
operator|->
name|value
operator|.
name|sym_data
operator|.
name|cptype
expr_stmt|;
comment|/* p points to the string */
else|else
name|p
operator|=
name|s
operator|->
name|value
operator|.
name|sym_data
operator|.
name|c0type
expr_stmt|;
name|pb_put
argument_list|(
name|p
argument_list|,
name|length
argument_list|,
operator|&
name|EquelPb
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

