begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RS/6000 AIX botched alloca and requires a pragma, which ordinary compilers    throw up about, so we have to put it in a specially-configured file.    Like this one.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

end_unit

