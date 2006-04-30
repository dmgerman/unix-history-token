begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Linux dumps "struct task_struct" at the end of the core-file.  This    structure is currently 1080 bytes long, but we allow up to 4096    bytes to allow for some future growth.  */
end_comment

begin_define
define|#
directive|define
name|TRAD_CORE_EXTRA_SIZE_ALLOWED
value|4096
end_define

begin_define
define|#
directive|define
name|TRAD_UNIX_CORE_FILE_FAILING_SIGNAL
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((abfd)->tdata.trad_core_data->u.signal)
end_define

end_unit

