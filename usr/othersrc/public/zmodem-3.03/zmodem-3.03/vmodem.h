begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  VMODEM.H  *  VMS support for UMODEM program  *  *	#INCLUDE files defining structures associated with terminal  *	information structure TT_INFO.  *	Information about the terminal is passed around in UMODEM in a  *	STRUCT TT_INFO.  *  *  Walter Reiher  *  Harvard University  *  Department of Chemistry  *  12 Oxford Street  *  Cambridge, MA 02138  *  March 10, 1983  */
end_comment

begin_struct
struct|struct
name|tt_mode
comment|/*  Info for a IO$_SETMODE call  */
block|{
name|char
name|class
decl_stmt|;
name|char
name|type
decl_stmt|;
name|short
name|page_width
decl_stmt|;
name|char
name|bcharacteristics
index|[
literal|3
index|]
decl_stmt|;
name|char
name|page_length
decl_stmt|;
name|int
name|echaracteristics
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tt_mode_iosb
comment|/*  Terminal IO$_SENSEMODE IOSB  */
block|{
name|short
name|status
decl_stmt|;
name|char
name|t_speed
decl_stmt|;
name|char
name|r_speed
decl_stmt|;
name|char
name|CR_fill
decl_stmt|;
name|char
name|LF_fill
decl_stmt|;
name|char
name|parity_flags
decl_stmt|;
name|char
name|unused2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tt_info
comment|/*  Summary of terminal infomation  */
block|{
name|struct
name|tt_mode
name|dev_characteristics
decl_stmt|;
name|struct
name|tt_mode_iosb
name|dev_modes
decl_stmt|;
block|}
struct|;
end_struct

end_unit

