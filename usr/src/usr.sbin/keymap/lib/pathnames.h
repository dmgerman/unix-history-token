begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Contributed to 386bsd 0.1 and later versions  *  *	Copyright 1992 by Holger Veit  *	May be freely used with Bill Jolitz's port of   *	386bsd and may be included in a 386bsd collection  *	as long as binary and source are available and reproduce the above  *	copyright.  *  *	You may freely modify this code and contribute improvements based  *	on this code as long as you don't claim to be the original author.  *	Commercial use of this source requires permittance of the copyright   *	holder. A general license for 386bsd will override this restriction.  *  *	Use at your own risk. The copyright holder or any person who makes  *	this code available for the public (administrators of public archives  *	for instance) are not responsible for any harm to hardware or software  *	that might happen due to wrong application or program faults.  *  * You must have the codriver driver in the same package generated  * into the 386bsd kernel, otherwise this program does not work.  *  *	@(#)pathnames.h	1.0 (386bsd contribution) 1.8.92  */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|_PATH_KEYCAP
value|"/usr/share/misc/keycap"
end_define

begin_define
define|#
directive|define
name|_PATH_CONSFONT
value|"/usr/share/font"
end_define

begin_define
define|#
directive|define
name|_PATH_KEYBOARD
value|"/dev/kbd"
end_define

begin_define
define|#
directive|define
name|_PATH_VIDEO
value|"/dev/vga"
end_define

end_unit

