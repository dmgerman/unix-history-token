begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../src/parms.h"
end_include

begin_include
include|#
directive|include
file|"../src/structs.h"
end_include

begin_comment
comment|/*  *	structsize  *  *	Tells you the size of some of the structures in the  *	data base.  *  *	This is useful when installing new versions of the  *	notesfile code.  I have recently (Sept 6, '83) played  *	with one of the structures and it resulted in a   *	non-obvious (but quickly figured out) change in the  *	size of the data structures.  This broke extant notesfiles.  *  *	If things don't fly when you first use new code, I would  *	suggest compiling and running this file with both the  *	old and new structure files (it will work with both)  *	and see what changed.  Then play with the filler space  *	that I left in the structure definitions to make things  *	work out.  *  *	Sorry that things like this have to happen. *sigh*  *  *	-- Ray Essick	September 6, 1983  *  * $Header: /mntb/3/srg/notes/work/utility/RCS/structsize.c,v 1.6 84/03/07 19:04:42 notes Exp $  *  */
end_comment

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"size of descr_f %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|descr_f
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of note_f %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|note_f
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"size of resp_f %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|resp_f
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

