begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dkio.h	1.1	86/01/05	*/
end_comment

begin_comment
comment|/*  * Structures and definitions for disk io control commands  *  * THIS WHOLE AREA NEEDS MORE THOUGHT.  FOR NOW JUST IMPLEMENT  * ENOUGH TO READ AND WRITE HEADERS ON MASSBUS DISKS.  EVENTUALLY  * SHOULD BE ABLE TO DETERMINE DRIVE TYPE AND DO OTHER GOOD STUFF.  */
end_comment

begin_comment
comment|/* disk io control commands */
end_comment

begin_define
define|#
directive|define
name|DKIOCHDR
value|_IO(d, 1)
end_define

begin_comment
comment|/* next I/O will read/write header */
end_comment

end_unit

