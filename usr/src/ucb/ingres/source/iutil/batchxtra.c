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
file|<access.h>
end_include

begin_include
include|#
directive|include
file|<batch.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)batchxtra.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_macro
name|rmbatch
argument_list|()
end_macro

begin_block
block|{
name|char
modifier|*
name|batchname
parameter_list|()
function_decl|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|p
operator|=
name|batchname
argument_list|()
expr_stmt|;
if|if
condition|(
name|i
operator|=
name|close
argument_list|(
name|Batch_fp
argument_list|)
condition|)
name|syserr
argument_list|(
literal|"rmbatch:can't close %s %d"
argument_list|,
name|p
argument_list|,
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|=
name|unlink
argument_list|(
name|p
argument_list|)
condition|)
name|syserr
argument_list|(
literal|"rmbatch:can't unlink %s %d"
argument_list|,
name|p
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|Batchhd
operator|.
name|mode_up
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  BATCHNAME -- create batch file name */
end_comment

begin_function
name|char
modifier|*
name|batchname
parameter_list|()
block|{
specifier|extern
name|char
modifier|*
name|Fileset
decl_stmt|;
specifier|extern
name|char
modifier|*
name|ztack
parameter_list|()
function_decl|;
return|return
operator|(
name|ztack
argument_list|(
literal|"_SYSbatch"
argument_list|,
name|Fileset
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

