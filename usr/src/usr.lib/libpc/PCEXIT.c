begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)PCEXIT.c 1.1 10/30/80"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_macro
name|PCEXIT
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
struct|struct
block|{
name|long
name|usr_time
decl_stmt|;
name|long
name|sys_time
decl_stmt|;
name|long
name|child_usr_time
decl_stmt|;
name|long
name|child_sys_time
decl_stmt|;
block|}
name|tbuf
struct|;
name|double
name|l
decl_stmt|;
name|PCLOSE
argument_list|(
name|GLVL
argument_list|)
expr_stmt|;
name|PFLUSH
argument_list|()
expr_stmt|;
if|if
condition|(
name|_stcnt
operator|>
literal|0
condition|)
block|{
name|times
argument_list|(
operator|&
name|tbuf
argument_list|)
expr_stmt|;
name|l
operator|=
name|tbuf
operator|.
name|usr_time
expr_stmt|;
name|l
operator|=
name|l
operator|/
name|HZ
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n%1ld %s %04.2f seconds cpu time.\n"
argument_list|,
name|_stcnt
argument_list|,
literal|"statements executed in"
argument_list|,
name|l
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

