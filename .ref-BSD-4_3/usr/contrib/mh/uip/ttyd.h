begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ttyd.h - definitions for ttyd */
end_comment

begin_comment
comment|/* The Regents of the University of California wish to make it known that:  *  *  *				  DISCLAIMER  *  *	"Although each program has been tested by its contributor, no  *	warranty, express or implied, is made by the contributor or the  *	University of California, as to the accuracy and functioning of  *	the program and related program material, nor shall the fact of  *	distribution constitute any such warranty, and no responsibility  *	is assumed by the contributor or the University of California in  *	connection herewith."  *  */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|MAIL
value|"/bin/mail"
end_define

begin_define
define|#
directive|define
name|SMLWAIT
value|60
end_define

begin_comment
comment|/* seconds for select() */
end_comment

begin_define
define|#
directive|define
name|NOTOK
value|(-1)
end_define

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_define
define|#
directive|define
name|DONE
value|1
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|serror
define|\
value|(errno> 0&& errno< sys_nerr ? sys_errlist[errno] : "Unknown error")
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_siglist
index|[]
decl_stmt|;
end_decl_stmt

end_unit

