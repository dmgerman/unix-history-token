begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	deviceinfo.h: 		 data describing the Interpress device and fonts */
end_comment

begin_struct
struct|struct
name|device_entry
block|{
name|short
name|font_size
decl_stmt|;
comment|/* total size of font_entries in file (bytes), */
name|short
name|resolution
decl_stmt|;
comment|/* resolution of device */
name|short
name|hor_units
decl_stmt|;
comment|/* horizontal units */
name|short
name|ver_units
decl_stmt|;
comment|/* vertical units */
name|short
name|width_units
decl_stmt|;
comment|/* units used to descibe character widths */
name|short
name|num_fonts
decl_stmt|;
comment|/* number of valid fonts for device */
name|short
name|num_sizes
decl_stmt|;
comment|/* number of valid sizes for device  */
name|short
name|scaling
decl_stmt|;
comment|/* scale factor used to represent non-integer point sizes */
name|short
name|output_wid
decl_stmt|;
comment|/* maximum width of output (in units) */
name|short
name|output_len
decl_stmt|;
comment|/* maximum length of output (in units) */
name|short
name|spec_char_num
decl_stmt|;
comment|/* number of 'special' characters recognized by device */
comment|/* must exist in specCharTab */
name|short
name|spec_name_len
decl_stmt|;
comment|/* length of string containing all 'special' */
comment|/* character names */
name|short
name|num_stiptypes
decl_stmt|;
comment|/* number of different stipple families */
name|short
name|unused
index|[
literal|1
index|]
decl_stmt|;
comment|/* for expansion */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|font_entry
block|{
name|char
name|num_char_wid
decl_stmt|;
comment|/* number of width entries for this font */
name|char
name|special_flag
decl_stmt|;
comment|/* indicates if this font is a special font (=1)  */
name|char
name|ligature_flag
decl_stmt|;
comment|/* indicates if ligatures exist on this font (=1) */
name|char
name|unused
decl_stmt|;
name|char
name|font_name
index|[
literal|10
index|]
decl_stmt|;
comment|/* troff internal font name  */
name|char
name|font_number
index|[
literal|10
index|]
decl_stmt|;
comment|/* troff internal font number (ascii equivalent) */
block|}
struct|;
end_struct

end_unit

