begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * lib_strbuf - library string storage  */
end_comment

begin_include
include|#
directive|include
file|"lib_strbuf.h"
end_include

begin_comment
comment|/*  * Storage declarations  */
end_comment

begin_decl_stmt
name|char
name|lib_stringbuf
index|[
name|LIB_NUMBUFS
index|]
index|[
name|LIB_BUFLENGTH
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lib_nextbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lib_inited
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * initialization routine.  Might be needed if the code is ROMized.  */
end_comment

begin_function
name|void
name|init_lib
parameter_list|(
name|void
parameter_list|)
block|{
name|lib_nextbuf
operator|=
literal|0
expr_stmt|;
name|lib_inited
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

