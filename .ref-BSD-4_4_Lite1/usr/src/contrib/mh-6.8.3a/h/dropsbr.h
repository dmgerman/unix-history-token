begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dropsbr.h - definitions for maildrop-style files */
end_comment

begin_comment
comment|/* A file which is formatted like a maildrop may have a corresponding map    file which is an index to the bounds of each message.  The first record    of such an map is special, it contains:  	d_id    = number of messages in file 	d_size	= version number of map 	d_start = last message read 	d_stop  = size of file      Each record after that contains:  	d_id	= BBoard-ID: of message, or similar info 	d_size	= size of message in ARPA Internet octets (\n == 2 octets) 	d_start	= starting position of message in file 	d_stop	= stopping position of message in file     Note that d_st{art,op} do NOT include the message delimiters, so    programs using the map can simply fseek to d_start and keep reading    until the position is at d_stop.  */
end_comment

begin_define
define|#
directive|define
name|DRVRSN
value|3
end_define

begin_struct
struct|struct
name|drop
block|{
name|int
name|d_id
decl_stmt|;
name|int
name|d_size
decl_stmt|;
name|long
name|d_start
decl_stmt|;
name|long
name|d_stop
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|map_chk
argument_list|()
decl_stmt|,
name|map_read
argument_list|()
decl_stmt|,
name|map_write
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|map_name
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|mbx_mmdf
argument_list|()
decl_stmt|,
name|mbx_uucp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mbx_open
argument_list|()
decl_stmt|,
name|mbx_Xopen
argument_list|()
decl_stmt|,
name|mbx_copy
argument_list|()
decl_stmt|,
name|mbx_size
argument_list|()
decl_stmt|,
name|mbx_close
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mbx_read
argument_list|()
decl_stmt|,
name|mbx_write
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

