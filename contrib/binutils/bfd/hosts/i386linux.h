begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Linux writes the task structure at the end of the core file.  Currently it    is 2912 bytes.  It is possible that this should be a pickier check, but    we should probably not be too picky (the size of the task structure might    vary, and if it's not the length we expect it to be, it doesn't affect    our ability to process the core file).  So allow 0-4096 extra bytes at    the end.  */
end_comment

begin_define
define|#
directive|define
name|TRAD_CORE_EXTRA_SIZE_ALLOWED
value|4096
end_define

end_unit

