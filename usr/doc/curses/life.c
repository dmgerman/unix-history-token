begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/*  *	Run a life game.  This is a demonstration program for  * the Screen Updating section of the -lcurses cursor package.  */
end_comment

begin_struct
struct|struct
name|lst_st
block|{
comment|/* linked list element */
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
comment|/* (y, x) position of piece */
name|struct
name|lst_st
modifier|*
name|next
decl_stmt|,
modifier|*
name|last
decl_stmt|;
comment|/* doubly linked */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|lst_st
name|LIST
typedef|;
end_typedef

begin_decl_stmt
name|LIST
modifier|*
name|Head
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of linked list */
end_comment

begin_function
name|main
parameter_list|(
name|ac
parameter_list|,
name|av
parameter_list|)
name|int
name|ac
decl_stmt|;
name|char
modifier|*
name|av
index|[]
decl_stmt|;
block|{
name|int
name|die
parameter_list|()
function_decl|;
name|evalargs
argument_list|(
name|ac
argument_list|,
name|av
argument_list|)
expr_stmt|;
comment|/* evaluate arguments */
name|initscr
argument_list|()
expr_stmt|;
comment|/* initialize screen package */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|die
argument_list|)
expr_stmt|;
comment|/* set to restore tty stats */
name|crmode
argument_list|()
expr_stmt|;
comment|/* set for char-by-char */
name|noecho
argument_list|()
expr_stmt|;
comment|/*	input */
name|nonl
argument_list|()
expr_stmt|;
comment|/* for optimization */
name|getstart
argument_list|()
expr_stmt|;
comment|/* get starting position */
for|for
control|(
init|;
condition|;
control|)
block|{
name|prboard
argument_list|()
expr_stmt|;
comment|/* print out current board */
name|update
argument_list|()
expr_stmt|;
comment|/* update board position */
block|}
block|}
end_function

begin_comment
comment|/*  * This is the routine which is called when rubout is hit.  * It resets the tty stats to their original values.  This  * is the normal way of leaving the program.  */
end_comment

begin_macro
name|die
argument_list|()
end_macro

begin_block
block|{
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* ignore rubouts */
name|mvcur
argument_list|(
literal|0
argument_list|,
name|COLS
operator|-
literal|1
argument_list|,
name|LINES
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* go to bottom of screen */
name|endwin
argument_list|()
expr_stmt|;
comment|/* set terminal to initial state */
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Get the starting position from the user.  They keys u, i, o, j, l,  * m, ,, and . are used for moving their relative directions from the  * k key.  Thus, u move diagonally up to the left, , moves directly down,  * etc.  x places a piece at the current position, " " takes it away.  * The input can also be from a file.  The list is built after the  * board setup is ready.  */
end_comment

begin_macro
name|getstart
argument_list|()
end_macro

begin_block
block|{
name|reg
name|char
name|c
decl_stmt|;
name|reg
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|box
argument_list|(
name|stdscr
argument_list|,
literal|'|'
argument_list|,
literal|'_'
argument_list|)
expr_stmt|;
comment|/* box in the screen */
name|move
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* move to upper left corner */
do|do
block|{
name|refresh
argument_list|()
expr_stmt|;
comment|/* print current position */
if|if
condition|(
operator|(
name|c
operator|=
name|getch
argument_list|()
operator|)
operator|==
literal|'q'
condition|)
break|break;
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'u'
case|:
case|case
literal|'i'
case|:
case|case
literal|'o'
case|:
case|case
literal|'j'
case|:
case|case
literal|'l'
case|:
case|case
literal|'m'
case|:
case|case
literal|','
case|:
case|case
literal|'.'
case|:
name|adjustyx
argument_list|(
name|c
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
name|mvaddstr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|"File name: "
argument_list|)
expr_stmt|;
name|getstr
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|readfile
argument_list|(
name|buf
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
name|addch
argument_list|(
literal|'X'
argument_list|)
expr_stmt|;
break|break;
case|case
literal|' '
case|:
name|addch
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
do|if (Head != NULL
block|)
end_block

begin_comment
comment|/* start new list */
end_comment

begin_expr_stmt
name|dellist
argument_list|(
name|Head
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Head
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|LIST
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * loop through the screen looking for 'x's, and add a list 	 * element for each one 	 */
end_comment

begin_for
for|for
control|(
name|y
operator|=
literal|1
init|;
name|y
operator|<
name|LINES
operator|-
literal|1
condition|;
name|y
operator|++
control|)
for|for
control|(
name|x
operator|=
literal|1
init|;
name|x
operator|<
name|COLS
operator|-
literal|1
condition|;
name|x
operator|++
control|)
block|{
name|move
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|inch
argument_list|()
operator|==
literal|'x'
condition|)
name|addlist
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_for

begin_comment
unit|}
comment|/*  * Print out the current board position from the linked list  */
end_comment

begin_expr_stmt
unit|prboard
operator|(
operator|)
block|{
name|reg
name|LIST
operator|*
name|hp
block|;
name|erase
argument_list|()
block|;
comment|/* clear out last position */
name|box
argument_list|(
name|stdscr
argument_list|,
literal|'|'
argument_list|,
literal|'_'
argument_list|)
block|;
comment|/* box in the screen */
comment|/* 	 * go through the list adding each piece to the newly 	 * blank board 	 */
for|for
control|(
name|hp
operator|=
name|Head
init|;
name|hp
condition|;
name|hp
operator|=
name|hp
operator|->
name|next
control|)
name|mvaddch
argument_list|(
name|hp
operator|->
name|y
argument_list|,
name|hp
operator|->
name|x
argument_list|,
literal|'X'
argument_list|)
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
end_expr_stmt

unit|}
end_unit

