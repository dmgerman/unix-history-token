begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * File: 	notify.c  * Author: 	Marc van Kempen  * Desc:	display a notify box with a message  *  * Copyright (c) 1995, Marc van Kempen  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dialog.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|void
name|dialog_notify
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|)
comment|/*  * Desc: display an error message  */
block|{
name|char
modifier|*
name|tmphlp
decl_stmt|;
name|WINDOW
modifier|*
name|w
decl_stmt|;
name|w
operator|=
name|dupwin
argument_list|(
name|newscr
argument_list|)
expr_stmt|;
if|if
condition|(
name|w
operator|==
name|NULL
condition|)
block|{
name|endwin
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\ndupwin(newscr) failed, malloc memory corrupted\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|tmphlp
operator|=
name|get_helpline
argument_list|()
expr_stmt|;
name|use_helpline
argument_list|(
literal|"Press enter or space"
argument_list|)
expr_stmt|;
name|dialog_mesgbox
argument_list|(
literal|"Message"
argument_list|,
name|msg
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|restore_helpline
argument_list|(
name|tmphlp
argument_list|)
expr_stmt|;
name|touchwin
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|wrefresh
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|delwin
argument_list|(
name|w
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/* dialog_notify() */
end_comment

end_unit

