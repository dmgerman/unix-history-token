begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XErrDescrip.c,v 10.4 86/02/01 15:32:52 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|"XlibInternal.h"
end_include

begin_define
define|#
directive|define
name|num_error_codes
value|13
end_define

begin_decl_stmt
name|char
modifier|*
name|XErrorList
index|[
name|num_error_codes
operator|+
literal|1
index|]
init|=
block|{
comment|/* No error		*/
literal|""
block|,
comment|/* BadRequest		*/
literal|"bad request code"
block|,
comment|/* BadValue		*/
literal|"integer parameter out of range"
block|,
comment|/* BadWindow		*/
literal|"parameter not a Window"
block|,
comment|/* BadPixmap		*/
literal|"parameter not a Pixmap"
block|,
comment|/* BadBitmap		*/
literal|"parameter not a Bitmap"
block|,
comment|/* BadCursor		*/
literal|"parameter not a Cursor"
block|,
comment|/* BadFont		*/
literal|"parameter not a Font"
block|,
comment|/* BadMatch		*/
literal|"parameter mismatch"
block|,
comment|/* BadTile		*/
literal|"Pixmap shape invalid for tiling"
block|,
comment|/* BadGrab		*/
literal|"button/mouse already grabbed"
block|,
comment|/* BadAccess		*/
literal|"access control violation"
block|,
comment|/* BadAlloc		*/
literal|"insufficient resources"
block|,
comment|/* BadColor 	    	*/
literal|"no such color"
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|XErrDescrip
parameter_list|(
name|code
parameter_list|)
specifier|register
name|int
name|code
decl_stmt|;
block|{
if|if
condition|(
name|code
operator|<=
name|num_error_codes
operator|&&
name|code
operator|>
literal|0
condition|)
return|return
operator|(
name|XErrorList
index|[
name|code
index|]
operator|)
return|;
return|return
operator|(
literal|"Unknown error"
operator|)
return|;
block|}
end_function

end_unit

