begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is loaded before crt0.o on machines where we do not    remap part of the data space into text space in unexec.    On these machines, there is no problem with standard crt0.o's    that make environ an initialized variable.  However, we do    need to make sure the label data_start exists anyway.  */
end_comment

begin_comment
comment|/* Create a label to appear at the beginning of data space.  */
end_comment

begin_decl_stmt
name|int
name|data_start
init|=
literal|0
decl_stmt|;
end_decl_stmt

end_unit

