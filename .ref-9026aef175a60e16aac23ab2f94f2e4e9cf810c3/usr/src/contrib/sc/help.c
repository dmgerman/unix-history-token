begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Help functions for sc   * R. Bond, 1988  * $Revision: 6.8 $  */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|"sc.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|intro
index|[]
init|=
block|{
literal|" "
block|,
literal|" Overview:"
block|,
literal|" "
block|,
literal|" A:   This overview"
block|,
literal|" B:   Options"
block|,
literal|" C:   Cursor movement commands"
block|,
literal|" D:   Cell entry and editing commands"
block|,
literal|" E:   Line Editing"
block|,
literal|" F:   File commands"
block|,
literal|" G:   Row and column commands"
block|,
literal|" H:   Range commands"
block|,
literal|" I:   Miscellaneous commands"
block|,
literal|" J:   Variable names/Expressions"
block|,
literal|" K:   Range functions"
block|,
literal|" L:   Numeric functions"
block|,
literal|" M:   String functions"
block|,
literal|" N:   Financial functions"
block|,
literal|" O:   Time and date functions"
block|,
literal|" "
block|,
literal|" Q:   Return to main spreadsheet"
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|options
index|[]
init|=
block|{
literal|" "
block|,
literal|" B: Options"
block|,
literal|" "
block|,
literal|"     ^To  Toggle options. Toggle one option selected by o:"
block|,
literal|" "
block|,
literal|"          a    Recalculate automatically or on ``@'' commands."
block|,
literal|"          c    Current cell highlighting enable/disable."
block|,
literal|"          e    External function execution enable/disable."
block|,
literal|"          n    If enabled, a digit starts a numeric value."
block|,
literal|"          t    Top line display enable/disable."
block|,
literal|"          x    Encrypt/decrypt database and listing files."
block|,
literal|"          $    Dollar prescale.  If enabled, all numeric constants."
block|,
literal|"               (not expressions) entered are multipled by 0.01."
block|,
literal|" "
block|,
literal|"     S    Set options.  Options include:"
block|,
literal|" "
block|,
literal|"          byrows        Recalculate in row order. (default)"
block|,
literal|"          bycols        Recalculate in column order."
block|,
literal|"          iterations=n  Set the number of iterations allowed. (10)"
block|,
literal|"          tblstyle=xx   Set ``T'' output style to:"
block|,
literal|"                        0 (none), tex, latex, or tbl."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cursor
index|[]
init|=
block|{
literal|" "
block|,
literal|" C: Cell cursor movement (always OK):"
block|,
literal|" "
block|,
literal|"     ^N ^P ^B ^F Down, up, back, forward"
block|,
literal|"     ^Ed         Go to end of range.  Follow ^E by a direction indicator"
block|,
literal|"                 such as ^P or j."
block|,
literal|"     Arrow keys (if the terminal and termcap support them.)"
block|,
literal|" "
block|,
literal|" Cell cursor movement if no prompt active:"
block|,
literal|"     j,k,l,h    Down, up, right, left"
block|,
literal|"     SPACE      Forward"
block|,
literal|"     ^H         Back"
block|,
literal|"     TAB        Forward, otherwise starts/ends a range"
block|,
literal|"     ^          Up to row 0 of the current column."
block|,
literal|"     #          Down to the last valid row of the current column."
block|,
literal|"     0          Back to column A.  Preface with ^U if numeric mode."
block|,
literal|"     $          Forward to the last valid column of the current row."
block|,
literal|"     b          Back then up to the previous valid cell."
block|,
literal|"     w          Forward then down to the next valid cell."
block|,
literal|"     g          Go to a cell.  Cell name, range name, quoted string,"
block|,
literal|"                or a number specify which cell."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cell
index|[]
init|=
block|{
literal|" "
block|,
literal|" D: Cell entry and editing commands:"
block|,
literal|" "
block|,
literal|"     =    Enter a numeric constant or expression."
block|,
literal|"<    Enter a left justified string or string expression."
block|,
literal|"     \",>  Enter a right justified string or string expression."
block|,
literal|"     e    Edit the current cell's numeric value."
block|,
literal|"     E    Edit the current cell's string part."
block|,
literal|"     x    Clear the current cell."
block|,
literal|"     c    Copy the last marked cell to the current cell."
block|,
literal|"     m    Mark a cell to be used as the source for ``c''"
block|,
literal|"     +    Increment numeric part"
block|,
literal|"     -    Decrement numeric part"
block|,
literal|" "
block|,
literal|"     In numeric mode, a decimal digit, ``+'', ``-'', and ``.'' all start"
block|,
literal|"     a new numeric constant or expression."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|vi
index|[]
init|=
block|{
literal|" "
block|,
literal|" E: Line Editor"
block|,
literal|" "
block|,
literal|"     Hitting the ESC key while entering any command on the top line"
block|,
literal|"     will start a one-line vi-style editor.  Supported commands:"
block|,
literal|" "
block|,
literal|"     ESC q        Abort command entry."
block|,
literal|"     h l          Move cursor forward, backward."
block|,
literal|"     0 $          Move cursor to the beginning, end of the line."
block|,
literal|"     b w          Move cursor forward/back one word."
block|,
literal|"     fc           Move cursor to character c."
block|,
literal|"     tc           Move the cursor the the character before c."
block|,
literal|"     i a          Enter insert mode before/after the cursor."
block|,
literal|"     I            Move to cursor column 0 and enter insert mode."
block|,
literal|"     x X          Delete the character under/before the cursor."
block|,
literal|"     rc           Replace the character under the cursor with c."
block|,
literal|"     cm           Change - m = b,f,h,l,t or w."
block|,
literal|"     dm           Delete - m = b,f,h,l,t or w."
block|,
literal|"     R            Enter replace (overstrike) mode."
block|,
literal|"     + j - k /    Forward/backward/search the command history."
block|,
literal|"     n            Repeat last history search."
block|,
literal|"     . u          Repeat/undo the last command."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|file
index|[]
init|=
block|{
literal|" "
block|,
literal|" F: File commands:"
block|,
literal|" "
block|,
literal|"     G    Get a new database from a file. "
block|,
literal|"     M    Merge a new file into the current database."
block|,
literal|"     P    Put the current database into a file."
block|,
literal|"     W    Write a listing of the current database into a file in"
block|,
literal|"          a form that matches its appearance on the screen."
block|,
literal|"     T    Write a listing of the current database to a file, but"
block|,
literal|"          put delimiters between each pair of fields."
block|,
literal|"          Optionally brackets output with control lines for ``tbl'',"
block|,
literal|"          ``LaTeX'', or ``TeX''."
block|,
literal|" "
block|,
literal|"     If encryption mode is set, file I/O will be encrypted/decrypted."
block|,
literal|"     ``\"| program\"'' for a file name will pipe (unencrypted) output to"
block|,
literal|"     a program for Put, Write and Table.  If a cell name is used"
block|,
literal|"     as the file name, the cell's string part will be used as the"
block|,
literal|"     file name."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|row
index|[]
init|=
block|{
literal|" "
block|,
literal|" G: Row and column commands:"
block|,
literal|" "
block|,
literal|"     ir, ic      Insert a new, empty row (column)"
block|,
literal|"     ar, ac      Append a new copy of the current row (column)"
block|,
literal|"     dr, dc      Delete the current row (column)"
block|,
literal|"     pr, pc, pm  Pull deleted cells back into the spreadsheet"
block|,
literal|"                 Insert rows, columns or merge the cells."
block|,
literal|"     vr, vc      Remove expressions from the affected rows (columns),"
block|,
literal|"                 leaving only the values."
block|,
literal|"     zr, zc      Hide (``zap'') the current row (column)"
block|,
literal|"     sr, sc      Show hidden rows (columns)"
block|,
literal|"     f           Set the output format to be used with the values of"
block|,
literal|"                 each cell in this column.  Enter field width and"
block|,
literal|"                 number of fractional digits.  A preceding count can be"
block|,
literal|"                 used to change more than one column."
block|,
literal|" "
block|,
literal|"     Commands which move or copy cells also modify the row and column "
block|,
literal|"     references in the new cell expressions.  Use ``fixed'' or the"
block|,
literal|"     ``$'' style cell reference to supress the change."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|range
index|[]
init|=
block|{
literal|" "
block|,
literal|" H: Range commands:"
block|,
literal|" "
block|,
literal|"     /x   Clear a range. "
block|,
literal|"     /v   Remove the expressions from a range of cells, leaving "
block|,
literal|"          just the values."
block|,
literal|"     /c   Copy a source range to a destination range."
block|,
literal|"     /f   Fill a range with constant values starting with a given"
block|,
literal|"          value and increasing by a given increment."
block|,
literal|"     /d   Assign a name to a cell or a range of cells.  Give the"
block|,
literal|"          the name, surrounded by quotes, and either a cell name such"
block|,
literal|"          as ``A10'' or a range such as ``a1:b20''."
block|,
literal|"     /s   Shows the currently defined range names.  Pipe output to"
block|,
literal|"          sort, then to less."
block|,
literal|"     /u   Use this command to undefine a previously defined range"
block|,
literal|"          name."
block|,
literal|" "
block|,
literal|"     Range operations affect a rectangular region on the screen"
block|,
literal|"     defined by the upper left and lower right cells in the region."
block|,
literal|"     A range is specified by giving the cell names separated by ``:'',"
block|,
literal|"     such as ``a20:k52''.  Another way to refer to a range is to use"
block|,
literal|"     a name previously defined using ``/d''."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|misc
index|[]
init|=
block|{
literal|" "
block|,
literal|" I: Miscellaneous commands:"
block|,
literal|" "
block|,
literal|"     Q q ^C   Exit from the program."
block|,
literal|"     ^G ESC   Abort entry of the current command."
block|,
literal|"     ?        Help"
block|,
literal|"     !        Shell escape.  Enter a command to run.  ``!!'' repeats"
block|,
literal|"              the last command.  Just ``!'' starts an interactive shell."
block|,
literal|"     ^L       Redraw the screen."
block|,
literal|"     ^R       Redraw the screen.  Highlight cells with values but no"
block|,
literal|"              expressions."
block|,
literal|"     ^X       Redraw the screen.  Show formulas, not values."
block|,
literal|"     @        Recalculate the spreadsheet."
block|,
literal|"     ^V       Type, in the command line, the name of the current cell."
block|,
literal|"     ^W       Type, in the command line, the current cell's expression."
block|,
literal|"     ^A       Type, in the command line, the current cell's numeric value."
block|,
literal|"     TAB      When the character cursor is on the top line TAB can be used"
block|,
literal|"              to start or stop the display of the default range."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|var
index|[]
init|=
block|{
literal|" "
block|,
literal|" J: Variable names:"
block|,
literal|" "
block|,
literal|"     K20    Row and column can vary on copies."
block|,
literal|"     $K$20  Row and column stay fixed on copies."
block|,
literal|"     $K20   Row can vary; column stays fixed on copies."
block|,
literal|"     K$20   Row stays fixed; column can vary on copies."
block|,
literal|"     fixed  holds following expession fixed on copies."
block|,
literal|"     Cells and ranges can be given a symbolic name via ``/d''."
block|,
literal|" "
block|,
literal|" Expressions:"
block|,
literal|"     -e      Negation                e<=e  Less than or equal"
block|,
literal|"     e+e     Addition                e=e   Equal"
block|,
literal|"     e-e     Subtraction             e!=e  Not Equal"
block|,
literal|"     e*e     Multiplication          e>=e  Greater than or equal"
block|,
literal|"     e/e     Division                e>e  Greater than"
block|,
literal|"     e%e     Modulo                  e<e  Less than"
block|,
literal|"     e^e     Exponentiation          e&e  Boolean operator AND."
block|,
literal|"     ~e      Boolean operator NOT    e|e  Boolean operator OR"
block|,
literal|"     e?e1:e2  or @if(e,e1,e2)"
block|,
literal|"             Conditional: If e is non zero then then e1, else e2."
block|,
literal|"     Terms may be constants, variables, and parenthesized expressions."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|rangef
index|[]
init|=
block|{
literal|" "
block|,
literal|" K: Range functions:"
block|,
literal|" "
block|,
literal|"     @sum(r)           Sum all valid cells in the range."
block|,
literal|"     @prod(r)          Multiply together all valid cells in the range."
block|,
literal|"     @avg(r)           Average all valid cells in the range."
block|,
literal|"     @count(r)         Count all valid cells in the range."
block|,
literal|"     @max(r)           Return the maximum value in the range."
block|,
literal|"     @min(r)           Return the minimum value in the range."
block|,
literal|"     @stddev(r)        Return the sample standard deviation of "
block|,
literal|"                       the cells in the range."
block|,
literal|"     @index(e,r) @stindex(e,r)"
block|,
literal|"                       Return the numeric (string) value of the cell at"
block|,
literal|"                       index e into range r."
block|,
literal|"     @lookup(e,r) @hlookup(e,r,n) @vlookup(e,r,n)"
block|,
literal|"                       Search through the range r for a value that"
block|,
literal|"                       matches e.  If e is numeric, the last value<= e"
block|,
literal|"                       matches; if string, an exact match is required."
block|,
literal|"                       @lookup searches a single row (column) and returns"
block|,
literal|"                       the value from the next column (row); @hlookup"
block|,
literal|"                       (@vlookup) searches the first row (column) in r and"
block|,
literal|"                       returns the value n columns (rows) from the match."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|numericf
index|[]
init|=
block|{
literal|" "
block|,
literal|" L: Numeric functions:"
block|,
literal|" "
block|,
literal|"     @atan2(e1,e2)     Arc tangent of e1/e2."
block|,
literal|"     @ceil(e)          Smallest integer not less than e."
block|,
literal|"     @eqs(se1,se2)     1 if string expr se1 has the same value as se2."
block|,
literal|"     @exp(e)           Exponential function of e."
block|,
literal|"     @abs(e) @fabs(e)  Absolute value of e."
block|,
literal|"     @floor(e)         The largest integer not greater than e."
block|,
literal|"     @hypot(x,y)       Sqrt(x*x+y*y)."
block|,
literal|"     @max(e1,e2,...)   The maximum of the values of the e's."
block|,
literal|"     @min(e1,e2,...)   The minimum of the values of the e's"
block|,
literal|"     @nval(se,e)       The numeric value of a named cell."
block|,
literal|"     pi                A constant quite close to pi."
block|,
literal|"     @pow(e1,e2)       e1 raised to the power of e2."
block|,
literal|"     @rnd(e)           Round e to the nearest integer."
block|,
literal|"     @round(e,n)       Round e to n decimal places."
block|,
literal|"     @sqrt(e)          Square root of e."
block|,
literal|"     @ston(se)         Convert string expr se to a numeric"
block|,
literal|"     @ln(e)   @log(e)           Natural/base 10 logarithm of e."
block|,
literal|"     @dtr(e)  @rtd(e)           Convert degrees to/from radians."
block|,
literal|"     @cos(e)  @sin(e)  @tan(e)  Trig functions of radian arguments."
block|,
literal|"     @asin(e) @acos(e) @atan(e) Inverse trig function."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|stringf
index|[]
init|=
block|{
literal|" "
block|,
literal|" M: String functions:"
block|,
literal|" "
block|,
literal|"     #                 Concatenate strings.  For example, the"
block|,
literal|"                       string expression ``A0 # \"zy dog\"'' yields"
block|,
literal|"                       ``the lazy dog'' if A0 is ``the la''."
block|,
literal|"     @substr(se,e1,e2) Extract characters e1 through e2 from the"
block|,
literal|"                       string expression se.  For example,"
block|,
literal|"                       ``@substr(\"Nice jacket\" 4, 7)'' yields "
block|,
literal|"                       ``e jac''."
block|,
literal|"     @fmt(se,e)        Convert a number to a string using sprintf(3)."
block|,
literal|"                       For example,  ``@fmt(\"*%6.3f*\",10.5)'' yields"
block|,
literal|"                       ``*10.500*''.  Use formats are e, E, f, g, and G."
block|,
literal|"     @sval(se,e)       Return the string value of a cell selected by name."
block|,
literal|"     @ext(se,e)        Call an external function (program or"
block|,
literal|"                       script).  Convert e to a string and append it"
block|,
literal|"                       to the command line as an argument.  @ext yields"
block|,
literal|"                       a string: the first line printed to standard"
block|,
literal|"                       output by the command."
block|,
literal|"     String expressions are made up of constant strings (characters"
block|,
literal|"     surrounded by quotes), variables, and string functions."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|finf
index|[]
init|=
block|{
literal|" "
block|,
literal|" N: Financial functions:"
block|,
literal|" "
block|,
literal|"     @pmt(e1,e2,e3)    @pmt(60000,.01,360) computes the monthly"
block|,
literal|"                       payments for a $60000 mortgage at 12%"
block|,
literal|"                       annual interest (.01 per month) for 30"
block|,
literal|"                       years (360 months)."
block|,
literal|" "
block|,
literal|"     @fv(e1,e2,e3)     @fv(100,.005,36) computes the future value"
block|,
literal|"                       of 36 monthly payments of $100 at 6%"
block|,
literal|"                       interest (.005 per month).  It answers the"
block|,
literal|"                       question:  ``How much will I have in 36"
block|,
literal|"                       months if I deposit $100 per month in a"
block|,
literal|"                       savings account paying 6% interest com-"
block|,
literal|"                       pounded monthly?''"
block|,
literal|" "
block|,
literal|"     @pv(e1,e2,e3)     @pv(1000,.015,36) computes the present"
block|,
literal|"                       value of an ordinary annuity of 36"
block|,
literal|"                       monthly payments of $1000 at 18% annual"
block|,
literal|"                       interest.  It answers the question: ``How"
block|,
literal|"                       much can I borrow at 18% for 30 years if I"
block|,
literal|"                       pay $1000 per month?''"
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|timef
index|[]
init|=
block|{
literal|" "
block|,
literal|" O: Time and date functions:"
block|,
literal|" "
block|,
literal|"     @now              Return the time encoded in seconds since 1970."
block|,
literal|"     @dts(m,d,y)       Return m/d/y encoded in seconds since 1970."
block|,
literal|"     @tts(h,m,s)       Return h:m:s encoded in seconds since midnight."
block|,
literal|" "
block|,
literal|"     All of the following take an argument expressed in seconds:"
block|,
literal|" "
block|,
literal|"     @date(e)          Convert the time in seconds to a date"
block|,
literal|"                       string 24 characters long in the following"
block|,
literal|"                       form: ``Sun Sep 16 01:03:52 1973''.  Note"
block|,
literal|"                       that you can extract pieces of this fixed format"
block|,
literal|"                       string with @substr."
block|,
literal|"     @year(e)          Return the year.  Valid years begin with 1970."
block|,
literal|"     @month(e)         Return the month: 1 (Jan) to 12 (Dec)."
block|,
literal|"     @day(e)           Return the day of the month: 1 to 31."
block|,
literal|"     @hour(e)          Return the number of hours since midnight: 0 to 23."
block|,
literal|"     @minute(e)        Return the number of minutes since the"
block|,
literal|"                       last full hour: 0 to 59."
block|,
literal|"     @second(e)        Return the number of seconds since the"
block|,
literal|"                       last full minute: 0 to 59."
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|help
parameter_list|()
block|{
name|int
name|option
decl_stmt|;
name|char
modifier|*
modifier|*
name|ns
init|=
name|intro
decl_stmt|;
while|while
condition|(
operator|(
name|option
operator|=
name|pscreen
argument_list|(
name|ns
argument_list|)
operator|)
operator|!=
literal|'q'
operator|&&
name|option
operator|!=
literal|'Q'
condition|)
block|{
switch|switch
condition|(
name|option
condition|)
block|{
case|case
literal|'a'
case|:
case|case
literal|'A'
case|:
name|ns
operator|=
name|intro
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
case|case
literal|'B'
case|:
name|ns
operator|=
name|options
expr_stmt|;
break|break;
case|case
literal|'c'
case|:
case|case
literal|'C'
case|:
name|ns
operator|=
name|cursor
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
case|case
literal|'D'
case|:
name|ns
operator|=
name|cell
expr_stmt|;
break|break;
case|case
literal|'e'
case|:
case|case
literal|'E'
case|:
name|ns
operator|=
name|vi
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
case|case
literal|'F'
case|:
name|ns
operator|=
name|file
expr_stmt|;
break|break;
case|case
literal|'g'
case|:
case|case
literal|'G'
case|:
name|ns
operator|=
name|row
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
case|case
literal|'H'
case|:
name|ns
operator|=
name|range
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
case|case
literal|'I'
case|:
name|ns
operator|=
name|misc
expr_stmt|;
break|break;
case|case
literal|'j'
case|:
case|case
literal|'J'
case|:
name|ns
operator|=
name|var
expr_stmt|;
break|break;
case|case
literal|'k'
case|:
case|case
literal|'K'
case|:
name|ns
operator|=
name|rangef
expr_stmt|;
break|break;
case|case
literal|'l'
case|:
case|case
literal|'L'
case|:
name|ns
operator|=
name|numericf
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
case|case
literal|'M'
case|:
name|ns
operator|=
name|stringf
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
case|case
literal|'N'
case|:
name|ns
operator|=
name|finf
expr_stmt|;
break|break;
case|case
literal|'o'
case|:
case|case
literal|'O'
case|:
name|ns
operator|=
name|timef
expr_stmt|;
break|break;
default|default:
name|ns
operator|=
name|intro
expr_stmt|;
break|break;
block|}
block|}
name|FullUpdate
operator|++
expr_stmt|;
operator|(
name|void
operator|)
name|move
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|clrtobot
argument_list|()
expr_stmt|;
block|}
end_function

begin_macro
name|pscreen
argument_list|(
argument|screen
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|screen
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|line
decl_stmt|;
name|int
name|dbline
decl_stmt|;
operator|(
name|void
operator|)
name|move
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|clrtobot
argument_list|()
expr_stmt|;
name|dbline
operator|=
literal|1
expr_stmt|;
for|for
control|(
name|line
operator|=
literal|0
init|;
name|screen
index|[
name|line
index|]
condition|;
name|line
operator|++
control|)
block|{
operator|(
name|void
operator|)
name|move
argument_list|(
name|dbline
operator|++
argument_list|,
literal|4
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|addstr
argument_list|(
name|screen
index|[
name|line
index|]
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|clrtoeol
argument_list|()
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|move
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printw
argument_list|(
literal|"Which Screen? [a-n, q]"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|clrtoeol
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|refresh
argument_list|()
expr_stmt|;
return|return
operator|(
name|nmgetch
argument_list|()
operator|)
return|;
block|}
end_block

end_unit

