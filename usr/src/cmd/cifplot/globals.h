begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|programName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of program; appears on plot */
end_comment

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If zero no debugging information is output */
end_comment

begin_decl_stmt
name|int
name|outline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One if outlines around symbols */
end_comment

begin_decl_stmt
name|int
name|circle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Zero if circle, otherwise number of edges in 			 * polygon approximation */
end_comment

begin_decl_stmt
name|int
name|standard
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One if only standard CIF is accepted */
end_comment

begin_decl_stmt
name|int
name|list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One if a listing of the input is to be produced */
end_comment

begin_decl_stmt
name|int
name|output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indicates which output device is to be used */
end_comment

begin_decl_stmt
name|char
modifier|*
name|banner
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Points to string which is to be put at top of plot */
end_comment

begin_decl_stmt
name|int
name|fileopen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One if output file is open */
end_comment

begin_decl_stmt
name|int
name|plot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One if plot is to be made, zero to suppress */
end_comment

begin_decl_stmt
name|int
name|extractor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set if running extractor */
end_comment

begin_decl_stmt
name|char
modifier|*
name|baseName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base name for extractor to use */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fontfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of font file in '/usr/lib/vfont' to use for text */
end_comment

begin_decl_stmt
name|int
name|NoPixcels
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of pixcels on raster line */
end_comment

begin_decl_stmt
name|int
name|TextUp
decl_stmt|,
name|TextDown
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum extent of the text fonts above and below the base line */
end_comment

begin_decl_stmt
name|int
name|text
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one if text is to be plotted */
end_comment

begin_decl_stmt
name|int
name|printSymbolName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one if symbol names are to be plotted */
end_comment

begin_decl_stmt
name|int
name|background
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one if the program is running in the background */
end_comment

begin_decl_stmt
name|int
name|symbox
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one if bounding boxes are to be drawn around symbols */
end_comment

begin_decl_stmt
name|int
name|grid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spacing in CIF units between grid lines; 0 means no grid lines */
end_comment

begin_decl_stmt
name|int
name|ask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if should ask whether to plot;0 otherwise*/
end_comment

begin_decl_stmt
name|int
name|depth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* depth to instanciate symbols; 0 = infinity */
end_comment

begin_decl_stmt
name|int
name|SetScale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one if user has set the scale */
end_comment

begin_decl_stmt
name|double
name|scale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the scale of the plot */
end_comment

begin_decl_stmt
name|char
modifier|*
name|outfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|RetCmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|upToDate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one if LineNo and CharNo represent the beginning of token 			   just sent to the parser */
end_comment

begin_decl_stmt
name|int
name|TokenLine
decl_stmt|,
name|TokenChar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The line num& char num of token sent to parser */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|string
typedef|;
end_typedef

begin_decl_stmt
name|int
name|MoreToPlot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indicates whether there is another window to plot */
end_comment

begin_decl_stmt
name|int
name|SetStick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for STIF plot wires constant width */
end_comment

begin_decl_stmt
name|float
name|Stickw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for STIF the width of wires */
end_comment

end_unit

