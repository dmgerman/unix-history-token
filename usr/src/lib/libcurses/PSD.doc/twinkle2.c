begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|.
operator|\
literal|" Copyright (c) 1980 The Regents of the University of California. .\" All rights reserved. .\" .\" %sccs.include.redist.roff% .\" .\"	@(#)twinkle2.c	8.1 (Berkeley) %G% .\" extern int	_putchar();  main() { 	reg char	*sp;  	srand(getpid());		/* initialize random sequence */  	if (isatty(0)) { 	       gettmode(); 	       if ((sp = getenv("
name|TERM
literal|")) != NULL) 		       setterm(sp); 		signal(SIGINT, die); 	} 	else { 		printf("
name|Need
name|a
name|terminal
name|on
operator|%
name|d
operator|\
name|n
literal|"
end_expr_stmt

unit|, _tty_ch); 		exit(1); 	} 	_puts(TI); 	_puts(VS);  	noecho(); 	nonl(); 	tputs(CL, NLINES, _putchar); 	for (;;) { 		makeboard();		/* make the board setup */ 		puton('*');		/* put on '*'s */ 		puton(' ');		/* cover up with ' 's */ 	} }  puton(ch) char	ch; { 	reg LOCS	*lp; 	reg int		r; 	reg LOCS	*end; 	LOCS		temp; 	static int	lasty, lastx;  	end =&Layout[Numstars]; 	for (lp = Layout; lp< end; lp++) { 		r = rand() % Numstars; 		temp = *lp; 		*lp = Layout[r]; 		Layout[r] = temp; 	}  	for (lp = Layout; lp< end; lp++) 			/* prevent scrolling */ 		if (!AM || (lp->y< NLINES - 1 || lp->x< NCOLS - 1)) { 			mvcur(lasty, lastx, lp->y, lp->x); 			putchar(ch); 			lasty = lp->y; 			if ((lastx = lp->x + 1)>= NCOLS) 				if (AM) { 					lastx = 0; 					lasty++; 				} 				else 					lastx = NCOLS - 1; 		} }
end_unit

