begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	bk.h	4.2	81/02/19	*/
end_comment

begin_comment
comment|/*  * Macro definition of bk.c/netinput().  * This is used to replace a call to  *		(*linesw[tp->t_line].l_rint)(c,tp);  * with  *  *		if (tp->t_line == NETLDISC)  *			BKINPUT(c, tp);  *		else  *			(*linesw[tp->t_line].l_rint)(c,tp);  */
end_comment

begin_define
define|#
directive|define
name|BKINPUT
parameter_list|(
name|c
parameter_list|,
name|tp
parameter_list|)
value|{ \ 	if ((tp)->t_rec == 0) { \ 		*(tp)->t_cp++ = c; \ 		if (++(tp)->t_inbuf == BSIZE || (c) == '\n') { \ 			(tp)->t_rec = 1; \ 			wakeup((caddr_t)&(tp)->t_rawq); \ 		} \ 	} \ }
end_define

end_unit

