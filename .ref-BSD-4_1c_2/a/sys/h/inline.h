begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	inline.h	4.5	82/06/08	*/
end_comment

begin_comment
comment|/*  * Definitions of inlines, and macro replacements  * for them if UNFAST (latter only scantily tested).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNFAST
end_ifndef

begin_define
define|#
directive|define
name|ilock
parameter_list|(
name|ip
parameter_list|)
define|\
value|{ \ 	while ((ip)->i_flag& ILOCK) { \ 		(ip)->i_flag |= IWANT; \ 		sleep((caddr_t)(ip), PINOD); \ 	} \ 	(ip)->i_flag |= ILOCK; \ }
end_define

begin_define
define|#
directive|define
name|iunlock
parameter_list|(
name|ip
parameter_list|)
define|\
value|{ \ 	(ip)->i_flag&= ~ILOCK; \ 	if ((ip)->i_flag&IWANT) { \ 		(ip)->i_flag&= ~IWANT; \ 		wakeup((caddr_t)(ip)); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|GETF
parameter_list|(
name|fp
parameter_list|,
name|fd
parameter_list|)
value|{ \ 	if ((unsigned)(fd)>= NOFILE || ((fp) = u.u_ofile[fd]) == NULL) { \ 		u.u_error = EBADF; \ 		return; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|IUPDAT
parameter_list|(
name|ip
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|,
name|waitfor
parameter_list|)
value|{ \ 	if (ip->i_flag&(IUPD|IACC|ICHG)) \ 		iupdat(ip, t1, t2, waitfor); \ }
end_define

begin_define
define|#
directive|define
name|ISSIG
parameter_list|(
name|p
parameter_list|)
value|((p)->p_sig&& \ 	((p)->p_flag&STRC || ((p)->p_sig&~ (p)->p_ignsig))&& issig())
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GETF
parameter_list|(
name|fp
parameter_list|,
name|fd
parameter_list|)
value|{ \ 	(fp) = getf(fd); \ 	if ((fp) == NULL) \ 		return; \ }
end_define

begin_define
define|#
directive|define
name|IUPDAT
parameter_list|(
name|ip
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|,
name|waitfor
parameter_list|)
value|iupdat(ip, t1, t2, waitfor)
end_define

begin_define
define|#
directive|define
name|ISSIG
parameter_list|(
name|p
parameter_list|)
value|issig(p)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

